# FASM syntax for the Altera MAX7000 series

This document describes a low-level but still human-readable syntax
for the configuration of an Altera MAX7000S series programmable logic device.
FASM files are intended as an intermediate step between place-and-routed design and bitstream writer.
A FASM file consists of lines of key-value assignments.
During parsing of the file those assignments are applied on top of the default configuration for a device,
such that all configurable elements (features) of that device are assigned their respective desired value.

## Goal

The syntax aims to follow <a href="https://github.com/SymbiFlow/fasm/blob/master/docs/specification.rst">mithro's FASM syntax guideline</a>.

* The device configuration is split into "features".
* Every feature may only be assigned a value once.
* The order in which assignments occur, does not change the resulting bitstream.
* Every feature has a hardware equivalent in the device.
* Every feature corresponds to one or more bits in the bitstream.
* Only one feature is configured per line.
* The assigned value is not changed, before it is written to the bitstream.

## Note

Please note, that as the reverse-engineering of the MAX7000 series devices is still in progress,
so this document may be subject to fundamental changes.

## Top-level block types

A MAX7000 series device can be partitioned into a number of different block types.

| Block type | FASM notation | Valid index range (MAX7032S) |
| -- | -- | -- |
| Logic array block | lab_&lt;x&gt; | char x = [A;B] | 
| Logic cell | lc&lt;n&gt; | int n = [1;32] |
| Input/Output block | io&lt;n&gt; | int n = [1;32] |
| Dedicated input | input&lt;n&gt; | int n = [1;4] |
| Output enable configuration | oe&lt;n&gt; | int n = [1;6] |
| Global clock configuration | gclk&lt;n&gt; | int n = [1;2] |

## Logic cell

A logic cell has several configurable features.

| Feature | FASM notation | Valid index range |
| -- | -- | -- |
| Product term | pt&lt;n&gt; | int n = [1;5] |
| Non-inverted product term input | pt&lt;n&gt;.input[&lt;m&gt;] | int m = [0;35] |
| Inverted product term input | pt&lt;n&gt;.inverted_input[&lt;m&gt;] | int m = [0;35] |
| Shareable expander product term input | pt&lt;n&gt;.sexp[&lt;m&gt;] | int m = [0;15] |
| From PT to or gate | pt&lt;n&gt;.enabled | |
| XOR gate logic | input_inverted | |
| Fast input from pin | enable_fast_input | |
| Global clear | use_gclr | |
| Glocal clock | use_gclk | |
| Preset | enable_preset | |
| Latch | ff_bypass | |

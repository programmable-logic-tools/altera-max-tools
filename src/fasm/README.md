# FASM syntax for the Altera MAX7000 series

This document describes a syntax for text-based configuration of a MAX7000 series programmable logic device.
The FASM file is intended as the bridge between place-and-route software and bitstream writer.

## Goal

The syntax aims to follow <a href="https://github.com/SymbiFlow/fasm/blob/master/docs/specification.rst">mithro's FASM syntax guideline</a>.

* The device configuration is split into "features".
* Every feature has a hardware equivalent in the device.
* Every feature corresponds to one or more bits in the bitstream.
* Only one feature is configured per line.
* The default value for a feature is 'disabled' or '0'.
* When a feature is named in a FASM file line without assignment of a concrete value, then the implicit assignment is 'enabled' or '1'.
* In the FASM file a disabled feature is represented by a '0', an enabled feature by a '1'.
This definition applies regardless of whether the corresponding bit in the bitstream will be '0' or '1'.
For example, when an enabled feature corresponds to a '0' bit in the bitstream,
then the corresponding feature in the FASM file shall still be assigned a value of '1'.
The bitstream writer will take care of flipping those bits where necessary.

## Note

Please note, that as the reverse-engineering of the MAX7000 series devices is still in progress,
so this document may be subject to fundamental changes.
Please get in touch with the author if you require a stable version.

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

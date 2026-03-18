
# pldconf

## What is it?

pldconf is a syntax and i.e. file format,
which enables C-style, human-readable programmable logic device configuration.
It is meant as an intermediate step before the generation of a
low-level bit configuration for a bitstream assembler (FASM).

## What is it for?

It shall allow for separate development and testing
of configuration generator and bitstream assembler.
The decoupling of feature configuration and flipping low-level bits
is intended to prevent errors especially in cases where
a '1' bit disables a feature and a '0' bit enables it.
The explicit syntax shall enable more effective debugging.
Terms as far as possible resemble the ones
used in the Altera device datasheet.

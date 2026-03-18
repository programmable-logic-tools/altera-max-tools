# POF file format specification

This is an unofficial, third-party specification for Altera's POF file format.

POF is a file format used as a container for programmable logic device configuration data.
It is composed of several blocks of data of different types,
among them the target device and a checksum,
and has the following properties:
All numbers are in little-endian representation.
Strings are null-terminated.
A string's null character is being counted in the corresponding block's size field.

## Overall structure

| Size | Type | Purpose | Content |
| -- | -- | -- | -- |
| 4 bytes | string | Magic signature | "POF" |
| 4 bytes | ? | Format version? | 0x00 00 01 00 |
| 4 bytes | uint32_t | Block count | e.g. 6 |
| remaining file| pof_block_t[] | Blocks | Concatenation of the specified number of blocks |

## Block structure

| Size | Type | Purpose | Example |
| -- | -- | -- | -- |
| 2 bytes | uint16_t | Block type | e.g. 1 == Used software |
| 4 bytes | uint32_t | Block size in bytes | e.g. 7280 |
| remaining block | uint8_t[] | Block content | e.g. the actual bitstream |

## Block types

| Type number | Content type | Associated content size | Content meaning |
| -- | -- | -- | -- |
| 1 | string | variable | Software used to create this file |
| 2 | string | variable | Model number of target device, this file is intended for |
| 3 | string | variable | Project title / Comment |
| 5 | uint16_t | 2 bytes | Encryption / Security bits configuration |
| 8 | uint16_t | 2 bytes | Checksum (For file or bitstream? CRC? Which polynomial?) |
| 17 | uint8_t[] | constant for one device type | Programming data |

## Block type: Programming data

| Size | Type | Meaning |
| -- | -- | -- |
| 6 bytes | ? | 0x00 00 00 |
| 4 bytes | uint32_t | Number of bits to program |
| 2 bytes | ? | 0x01 00 |
| remaining block | uint8_t[] | Bitstream |

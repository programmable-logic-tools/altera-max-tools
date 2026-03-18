
# Glossary

## Products

* MAX7000: Altera MAX7000-series CPLD family
* MAX7000S: Altera MAX7000-series CPLD family with JTAG and ISP support
* EPM7032S: Altera MAX7000S-series CPLD with 32 macrocells
* OpenOCD: Open On-Chip Debugger - FOSS software for programming or debugging integrated circuits, capable of executing SVF files

## Technological terms

* PLD: Programmable Logic Device - generic term for devices such as CPLDs and FPGAs that can be configured after manufacturing
* PLA: Programmable Logic Array - configurable logic device architecture with programmable AND and programmable OR planes
* PAL: Programmable Array Logic - configurable logic device architecture with a programmable AND plane and fixed OR plane
* PT: Product Term - basic AND term in a sum-of-products expression
* SOP: Sum Of Products - canonical form combining several product terms by ORing them
* LC: Logic Cell - device-family-specific composition of PTs, multiplexers and one D-FF
* LAB: Logic Array Block - grouping of logic cells in a MAX7000 device sharing local routing and control signals
* REG: Register - flip-flop, prominently D-type
* FF: Flip-flop - one-bit storage element
* D-FF: D-type flip-flop - flip-flop with data input D
* MUX: Multiplexer - in the context of PLDs, logical entity for routing internal signals according to configuration bits (bitstream)
* CPLD: Complex Programmable Logic Device - non-volatile programmable logic device family including the Altera MAX7000 series
* JTAG: Joint Test Action Group - IEEE 1149.x boundary scan interface for communicating with and programming a device
* ISP: In-System Programming - programming a CPLD or other PLD while it is soldered into the target system, typically via JTAG
* TAP: Test Access Port - JTAG interface on the device including pins and TAP state machine

## Methods

* PNR: Place and Route - design step mapping logic onto physical device resources and calculating necessary routing between them
* BST: Boundary Scan Testing - testing integrated circuits via boundary scan chains, typically over JTAG
* ISC: In-System Configuration - standardized JTAG-based method for configuring programmable logic devices in-circuit
* OCD: On-chip debugging - observing and controlling a running system via debug logic
* IEEE 1149.1: JTAG boundary-scan standard defining TAP, instructions and basic test infrastructure for digital ICs
* IEEE 1532: in-system configuration standard for programmable logic devices building on JTAG (IEEE 1149.1)

## Formats

* BIT: raw bitstream - binary configuration data for a device
* RBF: Raw Bitstream File - file containing a raw bitstream
* BSDL: Boundary Scan Description Language - IEEE language describing a device's boundary scan (JTAG) structure
* PALASM: PAL Assembler
* FASM: FPGA Assembly - textual, human-readable, feature-based format for specifying logical configurations as an intermediate between place-and-route output and low-level bitstream
* PLDCONF: Programmable Logic Device Configuration - C-style, human-readable configuration file format used as an intermediate before FASM and bitstream generation
* POF: Programmable Object File - Altera-proprietary flash/bitstream file format
* SVF: Serial Vector Format - textual format storing a sequence of JTAG operations e.g. for programming or testing a JTAG-capable device

## JTAG

...


## BSDL

...

## SVF

...

## Signals

* OE: Output Enable - signal controlling whether an output driver actively drives a pin
* CLK: Clock - periodic signal triggering synchronous logic and flip-flops
* GCLK: Global Clock - dedicated clock distribution network feeding logic cells across the device
* CLR: Clear - signal asynchronously resetting/clearing logic cells
* GCLR: Global Clear - dedicated global reset/clear signal asynchronously resetting logic cells
* TMS: Test Mode Select - JTAG control signal steering the TAP controller through its state machine
* TCK: Test Clock - JTAG clock signal advancing the TAP state machine and shifting data through scan chains
* TDI: Test Data In - JTAG data input pin for shifting instructions and data into the device
* TDO: Test Data Out - JTAG data output pin for shifting data and status information out of the device
* TRST: Test Reset - optional JTAG reset signal for asynchronous reset of the TAP controller

## Links

 * Intel-Altera BSDL resources: https://www.altera.com/design/devices/resources/models/bsdl


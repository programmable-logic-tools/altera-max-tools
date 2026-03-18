
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
* DFF: D-type flip-flop - flip-flop with data input D
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
* PALASM: PAL Assembler - textual language for describing logic equations and pin assignments for PAL- and CPLD-style devices
* FASM: FPGA Assembly - textual, human-readable, feature-based format for specifying logical configurations as an intermediate between place-and-route output and low-level bitstream
* PLDCONF: Programmable Logic Device Configuration - C-style, human-readable configuration file format used as an intermediate before FASM and bitstream generation
* POF: Programmable Object File - Altera-proprietary flash/bitstream file format
* SVF: Serial Vector Format - textual format storing a sequence of JTAG operations e.g. for programming or testing a JTAG-capable device

## PALASM

* TITLE: directive for naming a design or file
* DEVICE: directive for selecting target device type or family
* PIN: directive for assigning logical signals to device pins
* EQUATIONS: section for specifying Boolean equations for outputs and internal nodes
* FIELD: directive for defining bit fields in vectors to simplify equations
* TABLE: directive for describing combinational behaviour as a truth table

## SVF

* STATE: statement for forcing the TAP controller into a specific stable state
* RUNTEST: statement for keeping the TAP in a state for a given number of TCK cycles or a given time
* SIR: Shift Instruction Register - statement for shifting a value into the instruction register (IR)
* SDR: Shift Data Register - statement for shifting a value into the currently selected data register (DR)
* FREQUENCY: statement for constraining maximum JTAG clock frequency for subsequent operations
* TRST: statement for declaring use or absence of the TRST reset signal
* ENDDR / ENDIR: options for defining the TAP end state after DR or IR shifting

## JTAG

* TEST_LOGIC_RESET: TAP state for resetting JTAG logic and returning to a defined idle condition
* RUN_TEST/IDLE: TAP state for idling or running built-in self-test between scan operations
* SHIFT_IR: TAP state for shifting bits through the instruction register
* SHIFT_DR: TAP state for shifting bits through the currently selected data register
* UPDATE_IR: TAP state for updating instruction register contents from the shift path
* UPDATE_DR: TAP state for updating data register contents from the shift path
* PAUSE_IR / PAUSE_DR: TAP states for temporarily pausing shifting of IR or DR while preserving contents
* BYPASS: instruction selecting a single-bit bypass register for minimal scan length
* IDCODE: instruction selecting a device identification register containing a fixed ID value
* SAMPLE/PRELOAD: instruction for sampling pin values into the boundary register and/or preloading boundary-scan data
* EXTEST: instruction for using boundary-scan cells to drive and sample external pins for board-level testing

## BSDL

* entity: top-level BSDL construct naming the JTAG-capable device
* generic / port: constructs for declaring configuration parameters and I/O pins of the device
* attribute TAP_SCAN_IN / TAP_SCAN_OUT / TAP_SCAN_MODE / TAP_SCAN_CLOCK: attributes mapping JTAG pins (TDI, TDO, TMS, TCK) to logical ports
* attribute INSTRUCTION_LENGTH: attribute giving the number of bits in the instruction register
* attribute INSTRUCTION_OPCODE: attribute mapping instruction mnemonics (e.g. EXTEST, SAMPLE, BYPASS, IDCODE) to opcode bit patterns
* attribute BOUNDARY_LENGTH: attribute giving the number of cells in the boundary-scan register
* attribute BOUNDARY_REGISTER: attribute describing the boundary-scan cells, their associated pins and functions

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
* JTAG overview (Wikipedia): https://en.wikipedia.org/wiki/JTAG
* Boundary scan overview (Wikipedia): https://en.wikipedia.org/wiki/Boundary_scan
* BSDL overview (Wikipedia): https://en.wikipedia.org/wiki/Boundary_Scan_Description_Language
* PALASM background (Wikipedia): https://en.wikipedia.org/wiki/PALASM


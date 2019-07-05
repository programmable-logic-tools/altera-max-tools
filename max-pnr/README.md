# max-pnr

This tool reads a logical design,
e.g. created by Yosys,
and a pinout constraints file.
It then places all primitives in the design
to possible locations on the physical tile map
and creates routes to connect those tiles appropriately.
The result is stored in a
<a href="https://github.com/programmable-logic-tools/altera-max7000-db/blob/master/FASM.md">human-readable format</a>,
for import by the bitstream writer.

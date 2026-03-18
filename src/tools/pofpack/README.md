# pofpack

This tool reads a bitstream and writes an
<a href="https://github.com/programmable-logic-tools/altera-max7000-db/blob/master/POF.md">Altera POF file</a>.

Since a binary bitstream does not contain information about it's intended target device type,
this information must be provided via the command line.

~~~
pofpack -i mydesign.bin -D EPM7032S -o mydesign.pof
~~~

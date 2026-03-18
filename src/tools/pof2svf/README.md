# pof2svf

This tool generates a <a href="http://www.jtagtest.com/pdf/svf_specification.pdf">Serial Vector Format file (SVF)</a>
from an
<a href="https://github.com/programmable-logic-tools/altera-max7000-db/blob/master/POF.md">Altera POF file</a>.
The SVF file can be used e.g. by OpenOCD
to program the flash memory in the target device via JTAG.

~~~
pof2svf -i mydesign.pof -o mydesign.svf
~~~

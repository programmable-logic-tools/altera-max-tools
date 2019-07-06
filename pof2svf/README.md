# pof2svf

This tool generates a Serial Vector File (SVF)
from an Altera POF file.
The SVF file can be used e.g. by OpenOCD
to program the flash memory in the target device,
typically via JTAG.

~~~
pof2svf -i mydesign.pof -o mydesign.svf
~~~

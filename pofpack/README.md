# pofpack

This tool reads and writes
<a href="https://github.com/programmable-logic-tools/altera-max7000-db/blob/master/POF.md">Altera's POF files</a>.

## Use cases

### Pack a POF
~~~
pofpack -p mydesign.bin -D EPM7032S -o mydesign.pof
~~~

Since a binary bitstream does not contain information about it's intended target device type,
this information must be provided via a command line argument.

### Unpack a POF
~~~
pofpack -u mydesign.pof -o mydesign.bin
~~~

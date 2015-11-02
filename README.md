# WiringPi-Prolog
An SWI-Prolog wrapper for the WiringPi C library

(Under Development)

## Refs
* http://www.swi-prolog.org/pldoc/man?section=foreign
* http://www.swi-prolog.org/pldoc/man?section=foreignlink
* http://www.swi-prolog.org/pldoc/man?section=shlib
* http://www.swi-prolog.org/pldoc/man?section=foreigninclude
* http://www.swi-prolog.org/pldoc/man?section=foreignxmp


#Compiling
<pre>
<code>
 $ gcc -I/usr/lib/swi-prolog/include -fpic -c corefunc.c
 $ gcc -shared -o lowercase.so lowercase.o -Wall -lwiringPi
</code>
</pre>

Run swipl as root

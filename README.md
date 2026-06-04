# Pareidolia

**Brief Description:**



Pareidolia is a tool takes data from a data file (known as YAML), turns it into a format that computers can quickly read (.bin), and then that data goes into a game engine (Godot).


**Tech Stack:**
C++ and GDscript (for Godot)



**Byte encoding:**

Pareidolia .bin files have cusom byte encoding similar to LTV byte encoding. It goes like this:

* The first 4 bytes are the *header bytes* (Cos0) which acts as a signature that it belongs to Pareidolia. If a file is read and does not have these 4 bytes, it will be rejected
* The next byte is the total amount of *pairs* (Key: Value) in the YAML
* The next byte is the *length* of the first KEY in characters. After that, the next few bytes are the actual KEY
* The next byte is the *data type* of the VALUE. The values are: 01 for integers, 02 for floats, 03 for booleans, and 04 for string
* The next byte is the *length* of the VALUE. and the next byte is the actual VALUE

It goes like that until each *pair* is read and converted into binary. For reference, pairs in a YAML follow this structure: (KEY: VALUE)

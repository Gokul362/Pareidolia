# Pareidolia

**Brief Description:**

Pareidolia is a tool that takes data from a data file (known as YAML), turns it into a format that computers can quickly read (.bin), and then that data goes into a game engine (Raylib).


**Byte encoding:**

Pareidolia's .bin files have custom byte encoding similar to TLV byte encoding. It goes like this:

* The first 4 bytes are the *header bytes* (Cos0) which acts as a signature that it belongs to Pareidolia. If a file is read and does not have these 4 bytes, it will be rejected.
* The next byte is the total amount of *pairs* (Key: Value) in the YAML.
* The next byte is the *length* of the first KEY in characters. After that, the next few bytes are the actual KEY.
* The next byte is the *data type* of the VALUE. The values are: 01 for integers, 02 for floats, 03 for booleans, and 04 for string.
* The next byte is the *length* of the VALUE (only for strings, not for int, float, bool), and the next byte is the actual VALUE.

It goes like that until each *pair* is read and converted into binary. For reference, pairs in a YAML follow this structure: (KEY: VALUE)


**How to Use**
1. All of the main functions (making the .bin, reading the .bin, etc...) are called in Main.cpp, and all of the variables have to be declared below the line where it says "// Declare your variables here"

2. When making variables, you have to declare the type, and then use one of the "ConvertToInt/Float/Bool/String" functions to turn them into the respective data type. For the first argument, you just put "PairsMap". However, for the second argument, you have to put, in quotes, the exact name of the YAML Key you want to get the value from.

3. IMPORTANT: You also need to re-assign your variables below the line where it says "// Re-Assign your variables here". (Tip: An easy way to do this is copy-paste the same line, but get rid of the data type)


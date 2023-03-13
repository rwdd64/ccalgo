_This is just a simple caesar cipher encrypter e decrypter._ :-)

# Compiling
To compile it, just run "make". The binary will be on "/bin" with the name "ccalgo".

	make

# How to use
To use it, just run the executable with the operation you want to perform followed by the string you want to perform the operation on.

**Operations:**

 - Encrypt => "-e" flag.
- Decrypt => "-d" flag.

**E.g.:**

	./bin/ccalgo -e 'Hello World!'

This will return "Hello World!" encrypted in caesar cipher.

	./bin/ccalgo -d "Brx'uh yhub frro!"

This will return a secret message! ;-)

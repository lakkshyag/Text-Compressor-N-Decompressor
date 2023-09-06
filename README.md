# Text-Compressor-N-Decompressor
A C++ program which uses Huffman Coding for compression of text and its subsequent decompression.

The main file is "textCompressorDecompressor.cpp" which needs to be compiled and run to use the program. All the helper files should also be in the same directory for it to run.
This project implements Huffman Coding compression by replacing the more frequently appearing characters text with less bits (compared to 8) and the less frequent characters are replaced with more bits. 

The text which is to be compressed is entered first followed by a ~ (which acts as a delimiter). Needless to say, this means that the text itself cannot contain a ~ but this functionality can be easily modified depending on the user.
After this the text is compressed and the compressed output is shown, along with the compression key (which shows characters and the bit code they are replaced with). Then the compression% is also shown.

This will be further optimized by me as the compressed output is coming out as a string (each character is 8 bits) instead of a pure bit output. 


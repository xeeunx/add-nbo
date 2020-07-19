# add-nbo
bob9

1. echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin <br>
2. echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin <br>
3. make
4. ./add-nbo thousand.bin five-hundred.bin

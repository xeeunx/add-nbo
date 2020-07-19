#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

        uint8_t buf1[4];
        uint8_t buf2[4];

        if(argc < 3){
                printf("syntax : %s <file1> <file2>\n", argv[0]);
                return 0;
        }


        // thousand.bin
        FILE *f1 = fopen(argv[1] , "rb");
        fread(buf1, sizeof(uint8_t), 4, f1);
        uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
        uint32_t n1 = ntohl(*p1);


        // five-hundred.bin
        FILE *f2 = fopen(argv[2], "rb");
        fread(buf2, sizeof(uint8_t), 4, f2);
        uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
        uint32_t n2 = ntohl(*p2);
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);

        fclose(f1);
        fclose(f2);

}

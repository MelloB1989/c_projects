#include "md5.c"

void main(){
    uint8_t *result = md5String("Hello, World!"); 
    for(unsigned int i = 0; i < 16; ++i){
		printf("%02x", result[i]);
	}
	printf("\n");
}
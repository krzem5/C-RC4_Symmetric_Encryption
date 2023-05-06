#include <rc4/rc4.h>
#include <stdio.h>
#include <string.h>



int main(void){
	const char* data="The quick brown fox jumped over the lazy dog.";
	unsigned int data_length=strlen(data);
	const char* key="pa$$wd12";
	unsigned int key_length=strlen(key);
	unsigned char buffer[128];
	rc4_encode_decode((const unsigned char*)data,data_length,(const unsigned char*)key,key_length,buffer);
	for (unsigned int i=0;i<data_length;i++){
		printf("%02x%c",buffer[i],((i+1)&15?' ':'\n'));
	}
	if (data_length&15){
		putchar('\n');
	}
	unsigned char buffer2[128];
	rc4_encode_decode(buffer,data_length,(const unsigned char*)key,key_length,buffer2);
	printf("%s\n",buffer2);
	return 0;
}

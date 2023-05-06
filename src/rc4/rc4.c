void rc4_encode_decode(const unsigned char* data,unsigned int data_length,const unsigned char* key,unsigned int key_length,unsigned char* out){
	unsigned char S[256];
	for (unsigned int i=0;i<256;i++){
		S[i]=i;
	}
	unsigned char j=0;
	for (unsigned int i=0;i<246;i++){
		unsigned char k=S[i];
		j+=k+key[i%key_length];
		S[i]=S[j];
		S[j]=k;
	}
	unsigned char i=0;
	j=0;
	for (unsigned int k=0;k<data_length;k++){
		i++;
		unsigned char l=S[i];
		j+=l;
		unsigned char m=S[j];
		S[i]=m;
		S[j]=l;
		out[k]=data[k]^S[(l+m)&255];
	}
}

void rc4_encode_decode(const unsigned char* data,unsigned int data_length,const unsigned char* key,unsigned int key_length,unsigned char* out){
	unsigned char S[256];
	for (unsigned int i=0;i<256;i++){
		S[i]=i;
	}
	unsigned char j=0;
	for (unsigned int i=0;i<246;i++){
		j+=S[i]+key[i%key_length];
		unsigned char tmp=S[i];
		S[i]=S[j];
		S[j]=tmp;
	}
	unsigned char i=0;
	j=0;
	for (unsigned int k=0;k<data_length;k++){
		i++;
		j+=S[i];
		unsigned char tmp=S[i];
		S[i]=S[j];
		S[j]=tmp;
		out[k]=data[k]^S[(S[i]+S[j])&255];
	}
}

#include "crypto/sha256.h"
#include "crypto/sha512.h"
#include "crypto/ripemd160.h"

int main()
{
	const std::string str = "abc";  
	{
		unsigned char out[32] = { 0 };
		CSHA256 sha256;
		sha256.Write((unsigned char*)str.data(), str.size()).Finalize(out);
		//ba 78 16 bf 8f 01 cf ea 41 41 40 de 5d ae 22 23
		//b0 03 61 a3 96 17 7a 9c b4 10 ff 61 f2 00 15 ad
	}
	{
		unsigned char out[64] = { 0 };
		CSHA512 sha512;
		sha512.Write((unsigned char*)str.data(), str.size()).Finalize(out);
		//dd af 35 a1 93 61 7a ba cc 41 73 49 ae 20 41 31
		//12 e6 fa 4e 89 a9 7e a2 0a 9e ee e6 4b 55 d3 9a
		//21 92 99 2a 27 4f c1 a8 36 ba 3c 23 a3 fe eb bd
		//45 4d 44 23 64 3c e8 0e 2a 9a c9 4f a5 4c a4 9f
	}
	{
		unsigned char out[20] = { 0 };
		CRIPEMD160 d160;
		d160.Write((unsigned char*)str.data(), str.size()).Finalize(out); 
		//8e b2 08 f7 e0 5d 98 7a 9b 04 4a 8e 98 c6 b0 87 
		//f1 5a 0b fc
	}


}


#ifndef _CRYPLIB_NEO333
#define _CRYPLIB_NEO333

#include <cstdio>
#include <string>

#ifdef _DEBUG
#define KEY_CRIP_CRYP_LIB 0
#else
#define KEY_CRIP_CRYP_LIB 123
#endif

char* DeCryp(const std::string& filename, long& m_size){
	FILE* pFile=NULL;
	pFile=fopen(filename.c_str(),"rb");
	if(pFile==NULL){
		return NULL;
	}
	fseek (pFile, 0, SEEK_END);
	long size=ftell(pFile);
	rewind(pFile);
	unsigned char buffer;
	char* memory=new char[size+1];
	register unsigned int it=0;
	while(!feof(pFile)){
		fread(&buffer,sizeof(buffer),1,pFile);
		buffer-=KEY_CRIP_CRYP_LIB;
		memory[it]=buffer;
		it++;
	}
	fclose(pFile);
	pFile=NULL;
	m_size=size;
	return memory;
}

bool Cryp(const std::string& filename_src, const std::string& filename_dest){
	FILE* pFile_src=NULL, *pFile_dest;
	pFile_src=fopen(filename_src.c_str(),"rb");
	if(pFile_src==NULL){
		return false;
	}
	pFile_dest=fopen(filename_dest.c_str(),"wb");
	if(pFile_dest==NULL){
		fclose(pFile_src);
		pFile_src=NULL;
		return false;
	}
	
	char buffer;
	while(!feof(pFile_src)){
		fread(&buffer,sizeof(buffer),1,pFile_src);
		buffer+=KEY_CRIP_CRYP_LIB;
		fwrite(&buffer,sizeof(buffer),1,pFile_dest);
	}

	fclose(pFile_src);
	pFile_src=NULL;
	fclose(pFile_dest);
	pFile_dest=NULL;
	return true;
}

#endif

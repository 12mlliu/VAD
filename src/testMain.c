/*
 * testMain.c
 *
 *  Created on: Feb 5, 2017
 *      Author: mlliu
 */


#include"Vad.h"
#define MODELDIR "/home/mlliu/sphinx/linux-demo/model"

int main()
{
	cmd_ln_t *config;
	config = cmd_ln_init(NULL, ps_args(), true,
                "-hmm", MODELDIR "/tdt_sc_8k",
                "-lm", MODELDIR "/ask.lm.DMP",
                "-dict", MODELDIR "/ask.dic",
                "-fwdtree", "yes",
                "-fwdflat", "yes",
                "-bestpath", "yes",
                "-mfclogdir", ".",
                "-rawlogdir", ".",
                "-samprate", "8000",
                NULL); 


	FILE *infp=NULL;   //the pointer to input file



	bool isEnvEnergyDetect=false;
	

	unsigned char *wav_header;//��record the head of file)
	wav_header=(unsigned char *)malloc(sizeof(unsigned char)* WAVEHEAD);
   	if(!wav_header)
		exit(-1);

	int read_len;
	int numwritten;

	byte *myData;
	myData=(byte *)malloc(sizeof(byte)*DATASAPLES*2);
	if(!myData)
	{
		free(wav_header);
	     wav_header=NULL;
		 exit(-1);
	}
	infp=fopen("/home/mlliu/eclipse_workspace/VAD/src/test.raw","rb");
	if(NULL == infp)
	{
		printf("+++INFO: erro: Can not open file: \n");
		exit(-1);
	}
	fseek(infp,0L,SEEK_SET);
	fread(wav_header,sizeof(char),44,infp);
	while(true)
	{
		read_len=fread(myData,sizeof(byte),DATASAPLES*2,infp);
		if(read_len<DATASAPLES*2)
		break;

		//byte2short
		short *mData;
		mData=(short *)malloc(sizeof(short)*DATASAPLES);
		if(!mData)
		{
			exit(-1);
		}
		for(int i=0;i<DATASAPLES;i++)
		{
			mData[i]=byte2short(myData[2*i], myData[2*i+1]);
		}


		if(!isEnvEnergyDetect)
		{isEnvEnergyDetect=EnvEnergyDetect(mData);}
		if(isEnvEnergyDetect)
		{
		    char const * isEndFlag;
		    isEndFlag=VoiceDetectMain(mData,config);
		    //printf("+++INFO: isEndFlag = %s;\n",isEndFlag);
		    if( strcmp(isEndFlag,"false"))
		    {
		    	printf("+++INFO: Detected end point!\n");
			printf("+++INFO: hyp = %s\n",isEndFlag);
			
		    }//else{printf("hello\n");continue;}

              		
		}
		else
		    continue;
	}
	return 0;
}

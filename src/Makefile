#/*****************************************************************
# Copyright: 1968-2016, Midea Group, Corporate Research Center
# File name: Makfile
# Description: ASR demo for washer
# Author: xiaofeng.xu@midea.com
# Version: v1.0
# Date: 2017.01.11
# History: 
#******************************************************************/

CC	= gcc
LFLAGS	= -lpocketsphinx -lsphinxbase -lm
CFLAGS  = -I/usr/local/include/pocketsphinx -I/usr/local/include/sphinxbase -I./include -I/usr/local/include -DHAVE_CONFIG_H 

VAD: testMain.o Vad.o
	gcc testMain.o Vad.o -o VAD $(CFLAGS) $(LFLAGS)
testMain.o: testMain.c Vad.h
	gcc -c testMain.c -o testMain.o $(CFLAGS) $(LFLAGS)
Vad.o: Vad.c Vad.h
	gcc -c Vad.c -o Vad.o $(CFLAGS) $(LFLAGS)

#SOURCE	= test_simple.c
#TARGET	= test_simple

#all:	$(TARGET)

#$(TARGET): $(SOURCE)
#	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS) $(LFLAGS)

.PHONY: clean

clean:
	-rm -f VAD


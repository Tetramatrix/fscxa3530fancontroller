#pragma once

#pragma comment(lib, "WinRing0.lib")
#pragma comment(lib, "WinRing0x64.lib")

#include <iostream>
#include <stdio.h>
#include <string.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include "OlsApi.h"

static int usage (_TCHAR* basename) 
{ 
    printf("Demo", basename);   
    return -1; 
} 

/*****************************************************************************/
// waits for the status bit to clear, max 0x4000 tries
void WEIE()
{
	char Local1;
	int Local0 = 0x4000;
	Local1 = ReadIoPortByte(0x66) & 0x02;

	while(Local0 != 0 && Local1 == 0x02)
	{
		Local1 = ReadIoPortByte(0x66) & 0x02;
		Local0--;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	// try to initialize the WinRing0 library
	if (!InitializeOls() || GetDllStatus() != 0)
	{
		DeinitializeOls();
		std::cerr << "ERROR: WinRing0 library cannot be initialized." << std::endl;
		return 3;
	}

    if (argc < 2) 
    { 
        return usage(argv[0]); 
    
	} else if(_tcscmp(_T("auto"),argv[1])==0)
    { 
         printf("auto",argv[1]);
		 WEIE();
   		 WriteIoPortWord(0x66, 0x81);
		 WEIE();
		 WriteIoPortWord(0x62, 0x93);
		 WEIE();
		 WriteIoPortWord(0x62, 0x04);

		 WEIE();
		 WriteIoPortWord(0x66, 0x81);
		 WEIE();
		 WriteIoPortWord(0x62, 0x94);
		 WEIE();
		 WriteIoPortWord(0x62, 0x7f);

    } else if(_tcscmp(_T("off"),argv[1])==0)
    { 
         printf("off",argv[1]);
		 WEIE();
   		 WriteIoPortWord(0x66, 0x81);
		 WEIE();
		 WriteIoPortWord(0x62, 0x93);
		 WEIE();
		 WriteIoPortWord(0x62, 0x16);

		 WEIE();
		 WriteIoPortWord(0x66, 0x81);
		 WEIE();
		 WriteIoPortWord(0x62, 0x94);
		 WEIE();
		 WriteIoPortWord(0x62, 0xff);

    } else if(_tcscmp(_T("low"),argv[1])==0) 
	{
		printf("low",argv[1]);
		WEIE();
		WriteIoPortWord(0x66, 0x81);
		WEIE();
		WriteIoPortWord(0x62, 0x93);
		WEIE();
		WriteIoPortWord(0x62, 0x16);

		WEIE();
		WriteIoPortWord(0x66, 0x81);
		WEIE();
		WriteIoPortWord(0x62, 0x94);
		WEIE();
		WriteIoPortWord(0x62, 0xa0);

		DeinitializeOls();
	} else if(_tcscmp(_T("high"),argv[1])==0) 
	{
		printf("high",argv[1]);
		WEIE();
		WriteIoPortWord(0x66, 0x81);
		WEIE();
		WriteIoPortWord(0x62, 0x93);
		WEIE();
		WriteIoPortWord(0x62, 0x16);

		WEIE();
		WriteIoPortWord(0x66, 0x81);
		WEIE();
		WriteIoPortWord(0x62, 0x94);
		WEIE();
		WriteIoPortWord(0x62, 0x00);

		DeinitializeOls();
	} else if(_tcscmp(_T("avg"),argv[1])==0) 
	{
		printf("avgerage",argv[1]);
		WEIE();
		WriteIoPortWord(0x66, 0x81);
		WEIE();
		WriteIoPortWord(0x62, 0x93);
		WEIE();
		WriteIoPortWord(0x62, 0x16);

		WEIE();
		WriteIoPortWord(0x66, 0x81);
		WEIE();
		WriteIoPortWord(0x62, 0x94);
		WEIE();
		WriteIoPortWord(0x62, 0x6d);

		DeinitializeOls();
	}
	
	return 0;
}
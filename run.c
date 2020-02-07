#include<stdlib.h>
#include<time.h>
#include"head.h"
#include"egg.h"
#include<string.h>

//安检乘客，计算安检口服务总时长和总人数
DWORD WINAPI run0(LPVOID lpParameter)
{
	int i;
    while(1)
    {
        if(check[0].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[0].time=(rand()%(MaxTimeLen-MinTimeLen+1)+MinTimeLen);//生成随机的安检时间
            check[0].servetime=0;
            while(check[0].servetime<check[0].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[0].servetime++;
            }
            
            if(check[0].servetime==check[0].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[0].CountNum++;
                check[0].CountTime=check[0].CountTime+check[0].time;
                check[0].WinListCustCount--;
                                for(i=5;i>=1;i--)
                    {
                        number[0][i]=number[0][i-1];
                    }
                    number[0][0]=0;
                    if(ptr[0]!=6)
                                SetActiveEgg(mann[0][ptr[0]]);
                ShowEgg(0);
                ptr[0]++;
            }
            check[0].time=0;
            check[0].servetime=0;
        }
    }
}
DWORD WINAPI run1(LPVOID lpParameter)
{
	int i;
    while(1)
    {
        if(check[1].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[1].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[1].servetime=0;
            while(check[1].servetime<check[1].time)
            {
                Sleep(1000);//循环一次时间加一秒0
                check[1].servetime++;
            }

            
            if(check[1].servetime==check[1].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[1].CountNum++;
                check[1].CountTime=check[1].CountTime+check[1].time;
                check[1].WinListCustCount--;
                                 for(i=5;i>=1;i--)
                    {
                       number[1][i]=number[1][i-1];
                    }
                    number[1][0]=0;
                     if(ptr[1]!=6)
                SetActiveEgg(mann[1][ptr[1]]);
                ShowEgg(0);
                ptr[1]++;
            }
            check[1].time=0;
            check[1].servetime=0;
        }
    }
}
DWORD WINAPI run2(LPVOID lpParameter)
{
		int i;
    while(1)
    {
        if(check[2].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[2].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[2].servetime=0;
            while(check[2].servetime<check[2].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[2].servetime++;
            }
            if(check[2].servetime==check[2].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[2].CountNum++;
                check[2].CountTime=check[2].CountTime+check[2].time;
                check[2].WinListCustCount--;
                for(i=5;i>=1;i--)
                    {
                        number[2][i]=number[2][i-1];
                    }
                    number[2][0]=0;
                     if(ptr[2]!=6)
                SetActiveEgg(mann[2][ptr[2]]);
                ShowEgg(0);
                ptr[2]++;
            }
            check[2].time=0;
            check[2].servetime=0;
        }
    }
}
DWORD WINAPI run3(LPVOID lpParameter)
{
		int i;
    while(1)
    {
        if(check[3].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[3].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[3].servetime=0;
            while(check[3].servetime<check[3].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[3].servetime++;
            }
            if(check[3].servetime==check[3].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[3].CountNum++;
                check[3].CountTime=check[3].CountTime+check[3].time;
                check[3].WinListCustCount--;
                for(i=5;i>=1;i--)
                    {
                        number[3][i]=number[3][i-1];
                    }
                    number[3][0]=0;
                     if(ptr[3]!=6)
                SetActiveEgg(mann[3][ptr[3]]);
                ShowEgg(0);
                ptr[3]++;
            }
            check[3].time=0;
            check[3].servetime=0;
        }
    }
}
DWORD WINAPI run4(LPVOID lpParameter)
{
		int i;
    while(1)
    {
        if(check[4].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[4].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[4].servetime=0;
            while(check[4].servetime<check[4].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[4].servetime++;
            }
            if(check[4].servetime==check[4].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[4].CountNum++;
                check[4].CountTime=check[4].CountTime+check[4].time;
                check[4].WinListCustCount--;
                for(i=5;i>=1;i--)
                    {
                        number[4][i]=number[4][i-1];
                    }
                    number[4][0]=0;
                     if(ptr[4]!=6)
                SetActiveEgg(mann[4][ptr[4]]);
                ShowEgg(0);
                ptr[4]++;
            }
            check[4].time=0;
            check[4].servetime=0;
        }
    }
}
DWORD WINAPI run5(LPVOID lpParameter)
{
		int i;
    while(1)
    {
        if(check[5].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[5].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[5].servetime=0;
            while(check[5].servetime<check[5].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[5].servetime++;
            }
            if(check[5].servetime==check[5].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[5].CountNum++;
                check[5].CountTime=check[5].CountTime+check[5].time;
                check[5].WinListCustCount--;
                for(i=5;i>=1;i--)
                    {
                        number[5][i]=number[5][i-1];
                    }
                   number[5][0]=0;
                    if(ptr[5]!=6)
                SetActiveEgg(mann[5][ptr[5]]);
                ShowEgg(0);
                ptr[5]++;
            }
            check[5].time=0;
            check[5].servetime=0;
        }
    }
}
DWORD WINAPI run6(LPVOID lpParameter)
{
		int i;
    while(1)
    {
        if(check[6].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[6].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[6].servetime=0;
            while(check[6].servetime<check[6].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[6].servetime++;
            }
            if(check[6].servetime==check[6].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[6].CountNum++;
                check[6].CountTime=check[6].CountTime+check[6].time;
                check[6].WinListCustCount--;
                for(i=5;i>=1;i--)
                    {
                        number[6][i]=number[6][i-1];
                    }
                    number[6][0]=0;
                     if(ptr[6]!=6)
                SetActiveEgg(mann[6][ptr[6]]);
                ShowEgg(0);
                ptr[6]++;
            }
            check[6].time=0;
            check[6].servetime=0;
        }
    }
}
DWORD WINAPI run7(LPVOID lpParameter)
{
		int i;
    while(1)
    {
        if(check[7].WinListCustCount!=0)
        {
            srand((unsigned)time(NULL));
            check[7].time=(rand()%(MaxTimeLen-MinTimeLen)+MinTimeLen);//生成随机的安检时间
            check[7].servetime=0;
            while(check[7].servetime<check[7].time)
            {
                Sleep(1000);//循环一次时间加一秒
                check[7].servetime++;
            }
            if(check[7].servetime==check[7].time) //当前乘客安检时间过去后，安检口安检总时间和总人数都改变
            {
                check[7].CountNum++;
                check[7].CountTime=check[7].CountTime+check[7].time;
                check[7].WinListCustCount--;
                for(i=5;i>=1;i--)
                    {
                        number[7][i]=number[7][i-1];
                    }
                    number[7][0]=0;
                     if(ptr[7]!=6)
                SetActiveEgg(mann[7][ptr[7]]);
                ShowEgg(0);
                ptr[7]++;
            }
            check[7].time=0;
            check[7].servetime=0;
        }
    }
}



#include"head.h"
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include"egg.h" 
#include<string.h> 
//ȫ�ֱ�������
int T=0;//��ǰʱ��
int x;
int y;
int flag=1;
int ListCustCount=0;//�Ŷӻ�����������
int ListLines=0;//�Ŷӻ�����������
int CheckNum=4;//���ŵİ��������
FILE *fp;
int MaxCustSingleLine;      //���������ȴ��˿���
int MaxLines;             //���λ����������MaxLines��ֱ�����
int MaxSeqLen;           //�������ȴ�����
int MinTimeLen;           //һ�ΰ������ʱ������λΪ��
int MaxTimeLen;          //һ�ΰ������ʱ������λΪ��
int MinRestTimeLen;   //�����һ����ͣ��Ϣ���ʱ������λΪ��
int MaxRestTimeLen;  //�����һ����ͣ��Ϣ���ʱ������λΪ��*/ 
HEGG freee[8],off[8],sever[8],rest[8],pause[8];
int ptr[8];
HEGG mann[8][6];
int number[8][6];
char nn[48][5];
int main()
{
	int i,p;
	for(i=0;i<=7;i++)
	{
		ptr[i]=6;
	}
	for(i=0;i<=47;i++)
	{
		strcpy(nn[i],"0");
	}
	fp=fopen("output.txt","w");
	HANDLE Thread1,Thread2,Thread3,Thread4,Thread5,Thread6,Thread7,Thread8,Thread9,Thread10,Thread11,Thread12,Thread13,Thread14,Thread15,Thread16,Thread17;
	int t;
	readconfig();
	EggStart(1120,600);
	for(i=0;i<4;i++)//����ڸ������ݳ�ʼ��
	{
		check[i].state=q0;//״̬
		check[i].StartRestTime=0;//��ʼ��Ϣʱ��
        check[i].PlanRestTime=0;//�ƻ���Ϣʱ��
        check[i].RestTime=0;//����Ϣʱ��
        check[i].WinListCustCount=0;//����ڶ�������
        check[i].CountNum=0;//�ð�����ۼƷ�������
        check[i].CountTime=0;//�ð�����ۼƷ���ʱ��
	}
	for(i=4;i<8;i++)
	{
		check[i].state=4;
		check[i].StartRestTime=0;//��ʼ��Ϣʱ��
        check[i].PlanRestTime=0;//�ƻ���Ϣʱ��
        check[i].RestTime=0;//����Ϣʱ��
        check[i].WinListCustCount=0;//����ڶ�������
        check[i].CountNum=0;//�ð�����ۼƷ�������
        check[i].CountTime=0;//�ð�����ۼƷ���ʱ��
	}
	    draw();
for(i=0;i<=7;i++){

		for(p=0;p<=5;p++)
        {
	        mann[i][p]=LayEgg();
        	MovePen(680+40*p,80+i*70);
            ShowEgg(0);
	 	    DrawBitmap("manc.bmp");
		}
		} 
    	for(t=0;t<8;t++){
    	if(t<=3){
    		freee[t]=LayEgg();
		 	MovePen(960,40*(t+2)+30*t);
		 	DrawBitmap("free.bmp");
		 	ShowEgg(1);
		 	off[t]=LayEgg();
		 	MovePen(960,40*(t+2)+30*t);
		 	DrawBitmap("off.bmp");
		 	ShowEgg(0);
		}
		else if(t>=4)
		{
			freee[t]=LayEgg();
		 	MovePen(960,40*(t+2)+30*t);
		 	DrawBitmap("free.bmp");
		 	ShowEgg(0);
		 	off[t]=LayEgg();
		 	MovePen(960,40*(t+2)+30*t);
		 	DrawBitmap("off.bmp");
		 	ShowEgg(1);
		}
	 	sever[t]=LayEgg();
	 	MovePen(960,40*(t+2)+30*t);
		ShowEgg(0);
	 	DrawBitmap("sever.bmp");
	 	
	 	rest[t]=LayEgg();
	 	MovePen(960,40*(t+2)+30*t);
		ShowEgg(0);
	 	DrawBitmap("rest.bmp");
	 	
	 	pause[t]=LayEgg();
	 	MovePen(960,40*(t+2)+30*t);
		ShowEgg(0);
	 	DrawBitmap("pause.bmp");
	 	
	 }
	Thread1=CreateThread(NULL,0,mousecheck,NULL,0,NULL);
	Thread2=CreateThread(NULL,0,CheckState,NULL,0,NULL);//���������״̬������߳�
	Thread3=CreateThread(NULL,0,run0,NULL,0,NULL);//��������˿͵��߳�
	Thread4=CreateThread(NULL,0,ChangeCheckNum,NULL,0,NULL);//������̬���ذ���ڵ��߳�
	Thread5=CreateThread(NULL,0,Distribute,NULL,0,NULL);//��������˿͵�����ڰ���ڵ��߳�
	Thread6=CreateThread(NULL,0,OUTPUTSTATE,NULL,0,NULL);
	Thread7=CreateThread(NULL,0,run1,NULL,0,NULL);
	Thread8=CreateThread(NULL,0,run2,NULL,0,NULL);
	Thread9=CreateThread(NULL,0,run3,NULL,0,NULL);
	Thread10=CreateThread(NULL,0,run4,NULL,0,NULL);
	Thread11=CreateThread(NULL,0,run5,NULL,0,NULL);
	Thread12=CreateThread(NULL,0,run6,NULL,0,NULL);
	Thread13=CreateThread(NULL,0,run7,NULL,0,NULL);
	Thread14=CreateThread(NULL,0,BufferPassenger,NULL,0,NULL);
	Thread15=CreateThread(NULL,0,snake,NULL,0,NULL);
	Sleep(100);
	Thread16=CreateThread(NULL,0,timepasser,NULL,0,NULL); 
	Thread17=CreateThread(NULL,0,numberupdate,NULL,0,NULL); 
	
	
	

	CloseHandle(Thread1);
	CloseHandle(Thread2);
	CloseHandle(Thread3);
	CloseHandle(Thread4);
	CloseHandle(Thread5);
	CloseHandle(Thread6);
	CloseHandle(Thread7);
	CloseHandle(Thread8);
	CloseHandle(Thread9);
	CloseHandle(Thread10);
	CloseHandle(Thread11);
	CloseHandle(Thread12);
	CloseHandle(Thread13);
	CloseHandle(Thread14);
	CloseHandle(Thread15);
	CloseHandle(Thread16);
    CloseHandle(Thread17);
    
	while(1);
            fclose(fp);
	WaitForExit();
}


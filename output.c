#include"head.h"
#include<string.h>
void readconfig()
{
    FILE *fpc;
    fpc=fopen("config.txt","r");
char *configdata[7];
int i;
for(i=0;i<=6;i++)
{
    configdata[i]=(char *)malloc(sizeof(char)*10);
}
for(i=0;i<=6;i++)
{
    fgets(configdata[i],10,fpc);
}
char *use;
MaxCustSingleLine=strtol(configdata[0],&use,10);      //���������ȴ��˿���
MaxLines=strtol(configdata[1],&use,10);             //���λ����������MaxLines��ֱ�����
MaxSeqLen=strtol(configdata[2],&use,10);           //�������ȴ�����
MinTimeLen=strtol(configdata[3],&use,10);           //һ�ΰ������ʱ������λΪ��
MaxTimeLen=strtol(configdata[4],&use,10);          //һ�ΰ������ʱ������λΪ��
MinRestTimeLen=strtol(configdata[5],&use,10);   //�����һ����ͣ��Ϣ���ʱ������λΪ��
MaxRestTimeLen=strtol(configdata[6],&use,10);  //�����һ����ͣ��Ϣ���ʱ������λΪ��
fclose(fpc);
}
DWORD WINAPI OUTPUTSTATE(LPVOID lpParameter)
{
	        int TT,i,j,k,WLC;
	        TT=0;
	        
    while(1)
    {
        fprintf(fp,"����������%d��\n",TT);//���ʱ��

        if(check[0].state==END)//����°����
        {
            fprintf(fp,"OFFDUTY=Y\n");
        }
        else
        {
            fprintf(fp,"OFFDUTY=N\n");
        }

        IsFull();//��������������Ͷ�����
        fprintf(fp,"ListLines= %d  ,ListCustCount= %d\n",ListLines,ListCustCount);
        for(i=0; i<=7; i++)
        {
            fprintf(fp,"WIN%d:State=",i+1);
            switch(check[i].state)
            {
            case q0:
                fprintf(fp,"����,");
                break;
            case q1:
                fprintf(fp,"����,");
                break;
            case q2:
                fprintf(fp,"����Ϣ,");
                break;
            case q3:
                fprintf(fp,"��Ϣ,");
                break;
            case q4:
                fprintf(fp,"�ر�\n");
                break;
            case END:
                fprintf(fp,"�°�,");
                break;
            }
            if(check[i].state!=q4)
            {

            	fprintf(fp,"����˿ͱ��=");
            	            	for(k=1;k<=4-len(number[i][5]);k++)
            	            	{
            	            		fprintf(fp,"0");
								}
                fprintf(fp,"%d,�ѷ���ʱ��/�ƻ�����ʱ��=%d/%d ,����Ϣʱ��/�ƻ���Ϣʱ��=%d/%d ,WinListCount=%d,WinListCust=",number[i][5],check[i].servetime,check[i].time,check[i].RestTime,check[i].PlanRestTime,check[i].WinListCustCount);//
                if(check[i].state==0||check[i].state==3)
                {
                    fprintf(fp,"0000\n");
                }
                else
                    {
                        for(j=1;j<=check[i].WinListCustCount;j++)
                        {
                        	WLC=check[i].WinListCustCount;
                        	    for(k=1;k<=4-len(number[i][6-j]);k++)
            	            	{
            	            		fprintf(fp,"0");
								}
                            fprintf(fp,"%d",number[i][6-j]);
                            if(j!=WLC)
                            {
                                fprintf(fp,"->");
                            }
                        }
                        fprintf(fp,"\n");
                    }
		    }
            
        }

        fprintf(fp,"\n");
        TT=TT+3;
        Sleep(3000);
    }

}

int len(int a)
{
	if(a<10)
	return(1);
	if(a>=10&&a<100)
	return(2);
	if(a>=100&&a<1000)
	return(3);
	if(a>=1000)
	return(4);
}

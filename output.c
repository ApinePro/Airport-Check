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
MaxCustSingleLine=strtol(configdata[0],&use,10);      //单队列最大等待乘客数
MaxLines=strtol(configdata[1],&use,10);             //蛇形缓冲区最多由MaxLines个直队组成
MaxSeqLen=strtol(configdata[2],&use,10);           //最大允许等待长度
MinTimeLen=strtol(configdata[3],&use,10);           //一次安检最短时长，单位为秒
MaxTimeLen=strtol(configdata[4],&use,10);          //一次安检最大时长，单位为秒
MinRestTimeLen=strtol(configdata[5],&use,10);   //安检口一次暂停休息最短时长，单位为秒
MaxRestTimeLen=strtol(configdata[6],&use,10);  //安检口一次暂停休息最大时长，单位为秒
fclose(fpc);
}
DWORD WINAPI OUTPUTSTATE(LPVOID lpParameter)
{
	        int TT,i,j,k,WLC;
	        TT=0;
	        
    while(1)
    {
        fprintf(fp,"程序已运行%d秒\n",TT);//输出时间

        if(check[0].state==END)//输出下班与否
        {
            fprintf(fp,"OFFDUTY=Y\n");
        }
        else
        {
            fprintf(fp,"OFFDUTY=N\n");
        }

        IsFull();//输出缓冲区人数和队列数
        fprintf(fp,"ListLines= %d  ,ListCustCount= %d\n",ListLines,ListCustCount);
        for(i=0; i<=7; i++)
        {
            fprintf(fp,"WIN%d:State=",i+1);
            switch(check[i].state)
            {
            case q0:
                fprintf(fp,"空闲,");
                break;
            case q1:
                fprintf(fp,"服务,");
                break;
            case q2:
                fprintf(fp,"将休息,");
                break;
            case q3:
                fprintf(fp,"休息,");
                break;
            case q4:
                fprintf(fp,"关闭\n");
                break;
            case END:
                fprintf(fp,"下班,");
                break;
            }
            if(check[i].state!=q4)
            {

            	fprintf(fp,"安检乘客编号=");
            	            	for(k=1;k<=4-len(number[i][5]);k++)
            	            	{
            	            		fprintf(fp,"0");
								}
                fprintf(fp,"%d,已服务时长/计划服务时长=%d/%d ,已休息时长/计划休息时长=%d/%d ,WinListCount=%d,WinListCust=",number[i][5],check[i].servetime,check[i].time,check[i].RestTime,check[i].PlanRestTime,check[i].WinListCustCount);//
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

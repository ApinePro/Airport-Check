#include<stdlib.h>
#include<time.h>
#include"head.h"
#include"egg.h"
//ÿ���ṹ�����ϵ��ʵ�֣��ṹ���������
//״̬�ĳ�ʼ��Ӧ�÷���main��
DWORD WINAPI CheckState(LPVOID lpParameter)//�����״̬����
{
    int i;
    
    while(1)
    {
        for(i=0; i<8; i++)
        {
            if(check[i].state!=END)
            {
                switch(check[i].state)
                {
                case 0:
                    if(check[i].WinListCustCount!=0)
                    {
                        check[i].state=q1;
                        SetActiveEgg(sever[i]);
	 		    ChangeEggLayer(TOP);
			    ShowEgg(1);
                    } 
                  else if(x<=1080&&x>=1040&&(y<=40*(i+2)+30*i)&&(y>=40*(i+1)+30*i)&&IsApplySuc(i)==1)
                    {
                        check[i].state=q3; 
                        printf("%d�Ű���ڿ�ʼ��Ϣ\n",i+1);
                        fprintf(fp,"%d�Ű���ڿ�ʼ��Ϣ\n",i+1);
                        check[i].StartRestTime=T;//��ʼ��Ϣʱ����ڵ�ǰʱ��
                        SetActiveEgg(rest[i]); 
	 		ChangeEggLayer(TOP);
			ShowEgg(1);
                    }
                    break; 
                case 1:
                    check[i].PlanRestTime=0; 
                    check[i].RestTime=0;
                    
                    if(check[i].WinListCustCount==0){
                    	 check[i].state=q0;
                SetActiveEgg(freee[i]);
	 		    ShowEgg(1);
    		    ChangeEggLayer(TOP);
					}
                       
                    else if(x<=1080&&x>=1040&&(y<=40*(i+2)+30*i)&&(y>=40*(i+1)+30*i)&&IsApplySuc(i)==0)
                    {
                        check[i].state=q1; 
                    }
                    else if(x<=1080&&x>=1040&&(y<=40*(i+2)+30*i)&&(y>=40*(i+1)+30*i)&&IsApplySuc(i)==1)
                    {
                        check[i].state=q2; 
                        printf("%d�Ű���ڽ��뽫��Ϣ״̬\n",i+1);
                        fprintf(fp,"%d�Ű���ڽ��뽫��Ϣ״̬\n",i+1);
                        SetActiveEgg(pause[i]); 
	 		ChangeEggLayer(TOP);
			ShowEgg(1); 
                    }
                    else if((x<=1120&&x>=1080&&(y<=40*(i+2)+30*i)&&(y>=40*(i+1)+30*i)))
                    {
                        check[i].state=q1;
                    }
                    break;
                case 2:
                    if(check[i].WinListCustCount==0)
                    {
                        check[i].state=q3;
                        printf("%d�Ű���ڿ�ʼ��Ϣ\n",i+1);
                        fprintf(fp,"%d�Ű���ڿ�ʼ��Ϣ\n",i+1);
                        check[i].StartRestTime=T;//��ʼ��Ϣʱ����ڵ�ǰʱ��
                        SetActiveEgg(rest[i]); 
	 		ChangeEggLayer(TOP);
			ShowEgg(1);
                    }
                    else if((x<=1120&&x>=1080&&(y<=40*(i+2)+30*i)&&(y>=40*(i+1)+30*i))&&check[i].WinListCustCount!=0)
                    {
                        check[i].state=q1;
                        printf("%d�Ű���ڻָ�����\n",i+1);
                        fprintf(fp,"%d�Ű���ڻָ�����\n",i+1); 
                        SetActiveEgg(sever[i]);
	 		    ChangeEggLayer(TOP);
			    ShowEgg(1);
                    }
                    break;
                case 3:
                    check[i].time=0;
                    check[i].servetime=0;
                    check[i].RestTime=T-check[i].StartRestTime;
                    if(check[i].PlanRestTime<=check[i].RestTime)
                    {
                        check[i].state=q0; 
                        printf("%d�Ű������Ϣ����\n",i+1);
                        fprintf(fp,"%d�Ű������Ϣ����\n",i+1);
                        check[i].PlanRestTime=0;
                        check[i].RestTime=0;
                        SetActiveEgg(freee[i]);
	 		    ShowEgg(1);
    		    ChangeEggLayer(TOP);
                    }
                    else if((x<=1120&&x>=1080&&(y<=40*(i+2)+30*i)&&(y>=40*(i+1)+30*i)))
                    {
                        printf("%d�Ű��������ָ����죬��Ϣ����\n",i+1);
                        fprintf(fp,"%d�Ű��������ָ����죬��Ϣ����\n",i+1);
						check[i].state=q0;
                        check[i].PlanRestTime=0;
                        check[i].RestTime=0;
                        SetActiveEgg(freee[i]);
	 		    ShowEgg(1);
    		    ChangeEggLayer(TOP);
                    }
                    break;
                }
            }
        }
    }
}
int IsApplySuc(int X)//�жϰ�����ܷ�������Ϣ�ɹ�
{
    int i,flag;
    int n;//��ǰ�ȴ�����
    int isPrim;//���ر���
    clock_t start, finish;
		double duration;
		start = clock();
		duration=0.0;
    OpenCheckNum();
    n=ListCustCount/CheckNum;
    flag=0;
    for(i=0; i<8; i++)
    {
        if(check[i].state!=q2)
            flag=1;
    }
    if(flag=1&&n<=MaxSeqLen)
    {
        isPrim=1;//������Ϣ�ɹ�
        printf("%d�Ű����������Ϣ�ɹ�\n",X+1);
        fprintf(fp,"%d�Ű����������Ϣ�ɹ�\n",X+1);
        HEGG yes=LayEgg();
        MovePen(640,40*(X+2)+30*X);
         DrawBitmap("yes.bmp");
         
        
		while(duration<1.0)
		{
		   	finish = clock();
		   	duration = (double)(finish - start) / CLOCKS_PER_SEC; 
		}

        SetActiveEgg(yes);
			
		EatEgg();
        srand((unsigned)time(NULL));
        check[X].PlanRestTime=(rand()%(MaxRestTimeLen-MinRestTimeLen)+MinRestTimeLen);//�������ƻ���Ϣʱ��
    }
    else
    {
        isPrim=0;//������Ϣʧ��
        printf("%d�Ű����������ͣ���ܾ�\n",X);
        fprintf(fp,"%d�Ű����������ͣ���ܾ�\n",X);
        HEGG no=LayEgg();
        MovePen(640,40*(X+2)+30*X);
        DrawBitmap("no.bmp");
		while(duration<1.0)
		{
		   	finish = clock();
		   	duration = (double)(finish - start) / CLOCKS_PER_SEC; 
		}

			SetActiveEgg(no);
			
			EatEgg();
    } 
    	

    return isPrim;
}

//����˿�
DWORD WINAPI Distribute(LPVOID lpParameter)
{
    int i,lastnumber,j;
    double efficiency[7];//����ÿ������ڵİ���Ч��
    while(1)
    {
    	    lastnumber=0;


        for(i=0; i<=7; i++)
        {
            if(check[i].CountNum==0)
                efficiency[i]=1000000;
            else
                efficiency[i]=check[i].CountTime/check[i].CountNum;
        }//���Ч��
        int min=0;
        while(ListCustCount!=0&&check[0].state!=END)
        {
            for(i=0; i<=7; i++)
            {
                if((check[i].state==1)&&(check[i].WinListCustCount<6)||(check[i].state==0)&&(check[i].WinListCustCount<6)) //����״̬�����״̬
                {
                    if(check[i].WinListCustCount<check[min].WinListCustCount) 	//ѭ������С�Ķ����� ,min��ʼֵΪ0
                    {
                        min=i;
                    }
                    else if(check[i].WinListCustCount==check[min].WinListCustCount)
                    {
                        if(efficiency[i]<efficiency[min])
                        {
                            min=i;
                        }
                        else if(efficiency[i]==efficiency[min])
                        {
                            if(i<min)
                            {
                                min=i;
                            }
                        }
                    }
                }
            }
            if(check[min].WinListCustCount<6)
            {
            	    	        for(i=0;i<=7;i++)
    {
        lastnumber=lastnumber+check[i].CountNum+check[i].WinListCustCount;
    }
    lastnumber++;
                check[min].WinListCustCount++;
                ListCustCount--;
                	j=5-check[min].WinListCustCount;
                    number[min][j]=lastnumber;  
                ptr[min]--;
                SetActiveEgg(mann[min][ptr[min]]);
                ShowEgg(1);
            }//�������Ŷ���������һ��
        }
    }
}
//���㵱ǰ���ŵİ��������
void OpenCheckNum()
{
    CheckNum=0;
    int i;
    for(i=0; i<=7; i++) //�����С
    {
        if(check[i].state!=3||check[i].state!=4)
            CheckNum++;
    }
}
//��̬���ذ����
DWORD WINAPI ChangeCheckNum(LPVOID lpParameter)
{
    int i;
    while(1)
    {
        OpenCheckNum();
        if(ListCustCount/CheckNum>=3)
        {
            i=4;
            while((check[i].state!=q4)&&(i<=7))
            {
                i++;
            }
            if(i<=7)
            {
                check[i].state=q0;
                SetActiveEgg(freee[i]);
	 		    ShowEgg(1);
    		    ChangeEggLayer(TOP);
            }
        }
        else if(ListCustCount/CheckNum<2)
        {
            i=7;
            while((check[i].state!=q0)&&(i>=4))
            {
                i--;
            }
            if(i>=4)
            {
                check[i].state=q4;
                SetActiveEgg(off[i]);
	 		ChangeEggLayer(TOP);
			ShowEgg(1);
            }
        }
    }
}

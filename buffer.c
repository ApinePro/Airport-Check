#include"head.h"
#include"egg.h"
void IsFull()//�������λ������Ķ�����
{
	if(ListCustCount%30==0)
		ListLines=ListCustCount/30;
	else
	    ListLines=ListCustCount/30+1;
}
DWORD WINAPI snake(LPVOID lpParameter)//������������״
{
	HEGG hEggs[7];
	int i; 
	//�µ����������ԵĶ���
	SetAutoUpdate(0);//�Ȳ�������Ļ 
	for(i=0;i<7;i++)
    { 
        hEggs[i] = LayEgg();//���½����������ƻ��� 
        if(i%2==0)//��ʽ���� 
        {
        	MovePen(20,480);//������������ʽ���е�һ��λ�ô� 
        	OffsetPen(0,-40*i);//����Ŀǰ��ʴ� 
	        DrawLine(0,-80);
	        DrawLine(560,0); 
	    }    
		else//��ʽ���� 
	    {
	    	MovePen(620,440);//������������ʽ���е�һ��λ�ô� 
	    	OffsetPen(0,-40*(i-1));//����Ŀǰ��ʴ� 
	        DrawLine(0,-80);
	        DrawLine(-560,0);
		} 
    }
	for(i=0;i<7;i++)
	{
		SetActiveEgg(hEggs[i]); 
		ShowEgg(0);//������Ϊ��������� 
	} 
	SetAutoUpdate(1);//�˺��Զ�������Ļ 
    
	//��̬�������� 
	while(1)
	{
		IsFull();//����һ�λ����������� 
	    if(ListLines>1) 
	    {
	    	for(i=0;i<=(ListLines-2);i++)
	    	{
	    		SetActiveEgg(hEggs[i]);
	    		ShowEgg(1);//������Ϊ�������ʾ 
			}
		}
	} 
}


DWORD WINAPI BufferPassenger(LPVOID lpParameter)//�������˿� 
{
	int i,t=0;
	HEGG bpegg;
	bpegg=LayEgg();
	
	while(1)
	{
		if(ListCustCount>t)//�������� 
		{
			SetActiveEgg(bpegg);
			for(i=t;i<ListCustCount;i++)//����Ȧ 
			{
				IsFull();//��һ�ζ����� 
			    if(ListLines%2!=0)//�������� 
			    {
			    	if((i+1)%30==0)//��β 
			    	{
			    		MovePen(40,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}   
			        else//�Ƕ�β 
			        {
			        	MovePen(620-20*((i+1)%30-1),460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}
				}
				else//ż������ 
				{
					if((i+1)%30==0)//��β 
			    	{
			    		MovePen(620,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}   
			        else//�Ƕ�β 
			        {
			        	MovePen(20+((i+1)%30)*20,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}
				}	
			}
			t=i-1;
		}
		else if(ListCustCount<t)//�������� 
		{
			SetActiveEgg(bpegg);
			SetPenColor(WHITE); 
			for(i=t;i>=ListCustCount;i--)//����Ȧ 
			{
				IsFull();//��һ�ζ����� 
			    if(ListLines%2!=0)//�������� 
			    {
			    	if((i+1)%30==0)//��β 
			    	{
			    		MovePen(40,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}   
			        else
			        {
			        	MovePen(620-20*((i+1)%30-1),460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}
				}
				else//ż������ 
				{
					if((i+1)%30==0)//��β 
			    	{
			    		MovePen(620,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}   
			        else
			        {
			        	MovePen(20+((i+1)%30)*20,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}
				}	
			}
			t=i;
			SetPenColor(BLACK);
		}
	} 
}


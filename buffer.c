#include"head.h"
#include"egg.h"
void IsFull()//计算蛇形缓冲区的队列数
{
	if(ListCustCount%30==0)
		ListLines=ListCustCount/30;
	else
	    ListLines=ListCustCount/30+1;
}
DWORD WINAPI snake(LPVOID lpParameter)//缓冲区队列形状
{
	HEGG hEggs[7];
	int i; 
	//下蛋并画出各自的队列
	SetAutoUpdate(0);//先不更新屏幕 
	for(i=0;i<7;i++)
    { 
        hEggs[i] = LayEgg();//先新建画布，再移画笔 
        if(i%2==0)//左式队列 
        {
        	MovePen(20,480);//将画笔移至左式队列第一个位置处 
        	OffsetPen(0,-40*i);//移至目前起笔处 
	        DrawLine(0,-80);
	        DrawLine(560,0); 
	    }    
		else//右式队列 
	    {
	    	MovePen(620,440);//将画笔移至右式队列第一个位置处 
	    	OffsetPen(0,-40*(i-1));//移至目前起笔处 
	        DrawLine(0,-80);
	        DrawLine(-560,0);
		} 
    }
	for(i=0;i<7;i++)
	{
		SetActiveEgg(hEggs[i]); 
		ShowEgg(0);//依次设为活动蛋并隐藏 
	} 
	SetAutoUpdate(1);//此后自动更新屏幕 
    
	//动态增减队列 
	while(1)
	{
		IsFull();//计算一次缓冲区队列数 
	    if(ListLines>1) 
	    {
	    	for(i=0;i<=(ListLines-2);i++)
	    	{
	    		SetActiveEgg(hEggs[i]);
	    		ShowEgg(1);//依次设为活动蛋并显示 
			}
		}
	} 
}


DWORD WINAPI BufferPassenger(LPVOID lpParameter)//缓冲区乘客 
{
	int i,t=0;
	HEGG bpegg;
	bpegg=LayEgg();
	
	while(1)
	{
		if(ListCustCount>t)//人数增加 
		{
			SetActiveEgg(bpegg);
			for(i=t;i<ListCustCount;i++)//画黑圈 
			{
				IsFull();//算一次队列数 
			    if(ListLines%2!=0)//奇数队列 
			    {
			    	if((i+1)%30==0)//队尾 
			    	{
			    		MovePen(40,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}   
			        else//非队尾 
			        {
			        	MovePen(620-20*((i+1)%30-1),460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}
				}
				else//偶数队列 
				{
					if((i+1)%30==0)//队尾 
			    	{
			    		MovePen(620,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}   
			        else//非队尾 
			        {
			        	MovePen(20+((i+1)%30)*20,460-(ListLines-1)*40);
			            DrawEllipticalArc(10,20,0,360);
					}
				}	
			}
			t=i-1;
		}
		else if(ListCustCount<t)//人数减少 
		{
			SetActiveEgg(bpegg);
			SetPenColor(WHITE); 
			for(i=t;i>=ListCustCount;i--)//画白圈 
			{
				IsFull();//算一次队列数 
			    if(ListLines%2!=0)//奇数队列 
			    {
			    	if((i+1)%30==0)//队尾 
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
				else//偶数队列 
				{
					if((i+1)%30==0)//队尾 
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


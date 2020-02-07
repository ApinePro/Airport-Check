#include<stdlib.h>
#include"head.h"
#include"egg.h"
DWORD WINAPI timepasser(LPVOID lpParameter)
{
	char passer[3];
	
	char sever1[1],rest1[2],sever2[1],rest2[2],sever3[1],rest3[2],sever4[1],rest4[2],sever5[1],rest5[2],sever6[1],rest6[2],sever7[1],rest7[2],sever8[1],rest8[2];
	HEGG time=LayEgg();
	
	itoa(ListCustCount,passer, 10);
	MovePen(280,25) ;
    DrawString(passer);
	itoa(check[0].time-check[0].servetime,sever1, 10);
	MovePen(920,95);
	DrawString(sever1);
	itoa(check[1].time-check[1].servetime,sever2, 10);
	MovePen(920,165);
	DrawString(sever2);
	itoa(check[2].time-check[2].servetime,sever3, 10);
	MovePen(920,235);
	DrawString(sever3);
	itoa(check[3].time-check[3].servetime,sever4, 10);
	MovePen(920,305);
	DrawString(sever4);
	
	itoa(check[4].time-check[4].servetime,sever5, 10);
    MovePen(920,375);
	DrawString(sever5);
	itoa(check[5].time-check[5].servetime,sever6, 10);
    MovePen(920,445);
	DrawString(sever6);
	itoa(check[6].time-check[6].servetime,sever7, 10);
	MovePen(920,515);
	DrawString(sever7);
	itoa(check[7].time-check[7].servetime,sever8, 10);
	MovePen(920,585);
	DrawString(sever8);

	itoa(check[0].PlanRestTime-check[0].RestTime,rest1, 10);
	MovePen(940,95);
	DrawString(rest1);
	itoa(check[1].PlanRestTime-check[1].RestTime,rest2, 10);
	MovePen(940,165);
	DrawString(rest2);
	itoa(check[2].PlanRestTime-check[2].RestTime,rest3, 10);
	MovePen(940,235);
	DrawString(rest3);
	itoa(check[3].PlanRestTime-check[3].RestTime,rest4, 10);
	MovePen(940,305);
	DrawString(rest4);
	itoa(check[4].PlanRestTime-check[4].RestTime,rest5, 10);
	MovePen(940,375);
	DrawString(rest5);
	itoa(check[5].PlanRestTime-check[5].RestTime,rest6, 10);
    MovePen(940,445);
	DrawString(rest6);
	itoa(check[6].PlanRestTime-check[6].RestTime,rest7, 10);
	MovePen(940,515);
	DrawString(rest7);
	itoa(check[7].PlanRestTime-check[7].RestTime,rest8, 10);
	MovePen(940,585);
	DrawString(rest8);
	
    EVENT_TYPE ev; 
	StartTimer(1000);
	while((ev=WaitForEvent())!=EXIT)
	{
	    if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[0].time-check[0].servetime,sever1, 10);
			MovePen(920,95);
			DrawString(sever1);
    	}
    	if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[1].time-check[1].servetime,sever2, 10);
			MovePen(920,165);
			DrawString(sever2);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);	
			itoa(check[2].time-check[2].servetime,sever3, 10);
			MovePen(920,235);
			DrawString(sever3);
	}
	if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[3].time-check[3].servetime,sever4, 10);
			MovePen(920,305);
			DrawString(sever4);
	}
	    if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[4].time-check[4].servetime,sever5, 10);
		    MovePen(920,375);
			DrawString(sever5);
       }
       if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[5].time-check[5].servetime,sever6, 10);
		    MovePen(920,445);
			DrawString(sever6);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[6].time-check[6].servetime,sever7, 10);
			MovePen(920,515);
			DrawString(sever7);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[7].time-check[7].servetime,sever8, 10);
			MovePen(920,585);
			DrawString(sever8);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[0].PlanRestTime-check[0].RestTime,rest1, 10);
			MovePen(940,95);
			DrawString(rest1);
	   }
	if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[1].PlanRestTime-check[1].RestTime,rest2, 10);
			MovePen(940,165);
			DrawString(rest2);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[2].PlanRestTime-check[2].RestTime,rest3, 10);
			MovePen(940,235);
			DrawString(rest3);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[3].PlanRestTime-check[3].RestTime,rest4, 10);
			MovePen(940,305);
			DrawString(rest4);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[4].PlanRestTime-check[4].RestTime,rest5, 10);
			MovePen(940,375);
			DrawString(rest5);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[5].PlanRestTime-check[5].RestTime,rest6, 10);
		    MovePen(940,445);
			DrawString(rest6);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[6].PlanRestTime-check[6].RestTime,rest7, 10);
			MovePen(940,515);
			DrawString(rest7);
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	SetActiveEgg(time);
			itoa(check[7].PlanRestTime-check[7].RestTime,rest8, 10);
			MovePen(940,585);
			DrawString(rest8); 
		}
		if(ev==TIMER)
	    {
	    	Update();
	    	
	    	SetActiveEgg(time);
			MovePen(280,25) ;
			itoa(ListCustCount,passer,10);
		    DrawString(passer);
		}
   }
}

DWORD WINAPI mousecheck(LPVOID lpParameter)
{
	int i,key;
	HEGG stop,quitegg,overegg,ListCustCountEgg;
	char Time[4];

	stop=LayEgg();
	ShowEgg(0);
	MovePen(520,160);
	DrawBitmap("stop.bmp");
    
    quitegg=LayEgg();
    ShowEgg(0);
	MovePen(360,600);
	DrawBitmap("quit.bmp");
	
	overegg=LayEgg();
	ShowEgg(0);
	DrawBitmap("over.bmp");
	Sleep(500);
    HEGG time=LayEgg();
    itoa(T,Time, 10);
    MovePen(220,570);
	DrawString(Time);
	
    EVENT_TYPE ev; 
	StartTimer(1000);
	while((ev=WaitForEvent())!=EXIT)
	{
		if((ev==KEYUP)&&(GetStruckKey() == VK_LBUTTON))//鼠标左键点击
		{
			x = GetMouseX();
			y = GetMouseY(); 
		
		if(x<=80&&x>=0&&y<=600&&y>=520)
		    {
		        printf("下班啦~祝乘客们旅途愉快！");
		        fprintf(fp,"下班啦~祝乘客们旅途愉快！");
		        SetActiveEgg(quitegg); 
		        ShowEgg(1);//显示下班提示图标 
		    for(i=0;i<=7;i++)
                {
                    check[i].state=END;
                }
                key=0;
                for(i=0;i<8;i++)
                {
                	if(check[i].WinListCustCount!=0)
                	   key=1;
				}
				if(key==0)
				{
					SetActiveEgg(overegg); 
		            ShowEgg(1);//覆盖下班图片 
		            ChangeEggLayer(TOP);
				} 
		    }
		if(x<=80&&x>=0&&y<=80&&y>=0)
		{
    	    if(ListCustCount<240)
    	    {
    	    	ListCustCount++;
    	    	fprintf(fp,"排队缓冲区新到乘客\n");
			}
    	    else
    	    {
		        printf("对不起，缓冲区乘客已满，请您稍作等待\n");
		        fprintf(fp,"对不起，缓冲区乘客已满，请您稍作等待\n");
    	        ListCustCount=240;
    	        SetActiveEgg(stop);
    	        ShowEgg(1);
    	        ChangeEggLayer(TOP);
    	    }
	    }
	    if(x>=80&&x<=160&&y<=80&&y>=0)
		{
			for(i=1;i<=10;i++){
    	    if(ListCustCount<240)
    	    {
    	    	ListCustCount++;
    	    	fprintf(fp,"排队缓冲区新到乘客\n");
			}
    	    else
    	    {
		        printf("对不起，缓冲区乘客已满，请您稍作等待\n");
		        fprintf(fp,"对不起，缓冲区乘客已满，请您稍作等待\n");
    	        ListCustCount=240;
    	        SetActiveEgg(stop);
    	        ShowEgg(1);
    	        ChangeEggLayer(TOP);
    	    } 
    	    }
	      }
    	}
    	if(ev==TIMER)
	    {
		    T++;
	    	Update();
	    	SetActiveEgg(time);	
			itoa(T,Time, 10);
		    MovePen(220,570);
			DrawString(Time);
    	}
	}    
}
DWORD WINAPI numberupdate(LPVOID lpParameter)
{
	int i,p;
	HEGG num=LayEgg();
	for(i=0;i<=7;i++){
		for(p=0;p<=5;p++)
        {
           itoa(number[i][p],nn[i*6+p+1], 10);
        	MovePen(680+40*p,100+i*70);
	 	    DrawString(nn[i*6+1+p]);
		}
		}
    EVENT_TYPE ev; 
	StartTimer(1000);
	while((ev=WaitForEvent())!=EXIT)
	{
		if(ev==TIMER)
		{
	    	SetActiveEgg(num);
	    	for(i=0;i<=7;i++){
	    						    	Update();
		for(p=0;p<=5;p++)
        {
        	           itoa(number[i][p],nn[i*6+p+1], 10);
			MovePen(680+40*p,100+i*70);
	 	    DrawString(nn[1+p+i*6]);
		}
	}
}
}}



#include"egg.h"
#include"head.h"
 DrawRectangle(int x,int y)
{
	DrawLine(x, 0);
	DrawLine(0, -y);
	DrawLine(-x, 0);
	DrawLine(0, y);
}

void draw()
{
	  
	HEGG check;
	 int i;
	check=LayEgg();
	SetPenColor(BLUE );
	MovePen(20,480);
	DrawLine(600,0);
	MovePen(620,440);
	DrawLine(-560,0);
	MovePen(680,80);
	SetPenColor(BLACK);
	for(i=0;i<8;i++)
	{
		DrawRectangle(240,40);
		OffsetPen( 200,0 );
		SetPenColor(RED );
		DrawLine(0,-40);
		SetPenColor(BLACK);
		OffsetPen(40 ,40 );
    	DrawBitmap("check.bmp");
    	OffsetPen(80 ,0 );
    	DrawBitmap("R.bmp");
    	DrawBitmap("C.bmp");
    	OffsetPen(-440 ,70 );
	}
	MovePen(0,80);
	DrawBitmap("G.bmp") ;
	DrawBitmap("G10.bmp") ;
	DrawBitmap("coust.bmp");
	MovePen(0,600);
	DrawBitmap("Q.bmp") ;
	DrawBitmap("time.bmp");	
	ChangeEggLayer(BOTTOM);
}


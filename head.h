#include<stdio.h>
#include<windows.h>
#include"egg.h"
#include<string.h>
//全局变量声明
extern int T;//当前时间
extern int X;//安检口号码
extern int x;//鼠标点击位置 
extern int y;
extern char c;//输入字符命令
extern char OFFDUTY;//用于表示是否下班
extern int ListCustCount;//排队缓冲区总人数
extern int ListLines;//排队缓冲区队列数
extern int CheckNum;//开放的安检口数量
extern FILE *fp;
extern int MaxCustSingleLine;      //单队列最大等待乘客数
extern int MaxLines;           //蛇形缓冲区最多由MaxLines个直队组成
extern int MaxSeqLen;          //最大允许等待长度
extern int MinTimeLen;           //一次安检最短时长，单位为秒
extern int MaxTimeLen;         //一次安检最大时长，单位为秒
extern int MinRestTimeLen;   //安检口一次暂停休息最短时长，单位为秒
extern int MaxRestTimeLen;  //安检口一次暂停休息最大时长，单位为秒
extern int flag;
extern HEGG freee[8],off[8],sever[8],rest[8],pause[8];
extern ptr[8];
extern HEGG mann[8][6];
extern int number[8][6];
extern char nn[48][5];
//安检口状态
#define q0 0//空闲
#define q1 1//服务
#define q2 2//将休息
#define q3 3//休息
#define q4 4//关闭
#define END 5//下班

struct Check{
    int state;//安检口状态
    int StartRestTime;//开始休息时间
    int PlanRestTime;//计划休息时长
    int RestTime;//已休息时长
    int WinListCustCount;//安检口队列人数
    int CountNum;//该安检口累计服务人数
    int CountTime;//该安检口累计服务时间
    int time;  //记录当前乘客安检的随机时间
    int servetime;//该乘客已安检时长
} check[8];

//函数声明

 void IsFull();
 DWORD WINAPI Distribute(LPVOID lpParameter);
 int IsApplySuc();
 DWORD WINAPI CheckState(LPVOID lpParameter);
 void CountQueue();
 DWORD WINAPI run0(LPVOID lpParameter);
 DWORD WINAPI run1(LPVOID lpParameter);
 DWORD WINAPI run2(LPVOID lpParameter);
 DWORD WINAPI run3(LPVOID lpParameter);
 DWORD WINAPI run4(LPVOID lpParameter);
 DWORD WINAPI run5(LPVOID lpParameter);
 DWORD WINAPI run6(LPVOID lpParameter);
 DWORD WINAPI run7(LPVOID lpParameter);
 void OpenCheckNum();
 DWORD WINAPI ChangeCheckNum(LPVOID lpParameter);
 void CountTime(int a);
 DWORD WINAPI OUTPUTSTATE(LPVOID lpParameter);
 void draw();
 void BufferStick();
 void move();
 DWORD WINAPI mousecheck(LPVOID lpParameter);
 DWORD WINAPI snake(LPVOID lpParameter);
 DWORD WINAPI BufferPassenger(LPVOID lpParameter);
 DWORD WINAPI state(LPVOID lpParameter);
 DWORD WINAPI CheckPassenger(LPVOID lpParameter);
 void readconfig();
 DWORD WINAPI timepasser(LPVOID lpParameter);
  DWORD WINAPI numberupdate(LPVOID lpParameter);

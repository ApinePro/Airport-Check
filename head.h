#include<stdio.h>
#include<windows.h>
#include"egg.h"
#include<string.h>
//ȫ�ֱ�������
extern int T;//��ǰʱ��
extern int X;//����ں���
extern int x;//�����λ�� 
extern int y;
extern char c;//�����ַ�����
extern char OFFDUTY;//���ڱ�ʾ�Ƿ��°�
extern int ListCustCount;//�Ŷӻ�����������
extern int ListLines;//�Ŷӻ�����������
extern int CheckNum;//���ŵİ��������
extern FILE *fp;
extern int MaxCustSingleLine;      //���������ȴ��˿���
extern int MaxLines;           //���λ����������MaxLines��ֱ�����
extern int MaxSeqLen;          //�������ȴ�����
extern int MinTimeLen;           //һ�ΰ������ʱ������λΪ��
extern int MaxTimeLen;         //һ�ΰ������ʱ������λΪ��
extern int MinRestTimeLen;   //�����һ����ͣ��Ϣ���ʱ������λΪ��
extern int MaxRestTimeLen;  //�����һ����ͣ��Ϣ���ʱ������λΪ��
extern int flag;
extern HEGG freee[8],off[8],sever[8],rest[8],pause[8];
extern ptr[8];
extern HEGG mann[8][6];
extern int number[8][6];
extern char nn[48][5];
//�����״̬
#define q0 0//����
#define q1 1//����
#define q2 2//����Ϣ
#define q3 3//��Ϣ
#define q4 4//�ر�
#define END 5//�°�

struct Check{
    int state;//�����״̬
    int StartRestTime;//��ʼ��Ϣʱ��
    int PlanRestTime;//�ƻ���Ϣʱ��
    int RestTime;//����Ϣʱ��
    int WinListCustCount;//����ڶ�������
    int CountNum;//�ð�����ۼƷ�������
    int CountTime;//�ð�����ۼƷ���ʱ��
    int time;  //��¼��ǰ�˿Ͱ�������ʱ��
    int servetime;//�ó˿��Ѱ���ʱ��
} check[8];

//��������

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

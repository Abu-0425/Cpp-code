#ifndef __HEAD_HPP__
#define __HEAD_HPP__ 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAXNUM      20      // ����к�
#define RESOURCECNT 3       // ϵͳ��Դ��
#define PROCESSCNT  5       // ϵͳ������

extern vector<string> ID;                  //  ÿ�����̵�����
extern vector<int> Available;              //  ϵͳ�ɷ�����Դ
extern vector<vector<int> > Max;           //  ÿ�����̶�ÿ����Դ������
extern vector<vector<int> > Allocation;    //  ÿ�������Ѿ������ÿ����Դ
extern vector<vector<int> > Need;          //  ���̻���Ҫ��Դ
extern vector<int> SafeOrder;              //  ��ȫִ�е�˳��
extern vector<int> Request;                //  ����������Դ��
extern int idx;                            //  ����Ľ��̱��
extern int NoAllocCnt;                     //  ��ǰû�з�����ȫ�Ľ�����
extern vector<bool> ProVis;                //  ��ǰ�����Ƿ��Ѿ���ȫ����


void init();                                // ��ʼ��
void display();                             // ��ʾϵͳ��Դ��δ�����Ľ���ռ����Դ���
bool banker();                              // ִ�����м��㷨
bool input();                               // �������ָ�����̵���Դ
bool isExit();                              // ���н����Ƿ񶼵õ�����Դ
#endif 


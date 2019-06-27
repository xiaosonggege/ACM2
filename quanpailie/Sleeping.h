#ifndef SLEEPING_H
#define SLEEPING_H
#include "pch.h"
#include <iostream>
using namespace std;
class Sleeping {
private:
	//����˯������ʱ������ѳ���ʱ��
	int sleep_still;
	int wake_still;
	//����˯����ʱ�����Ѽ�ʱ
	int sleep_time = 0;
	int wake_time = 0;
	//������ǰ״̬
	int stateing; //1Ϊ���ѣ�0Ϊ˯��
public:
	Sleeping() = default;
	Sleeping(const int &, const int &, const int &); //����Ϊ˯������ʱ������ѳ���ʱ�䣬���ά��ʼ״̬
	~Sleeping();
	Sleeping(const Sleeping &);
	Sleeping(Sleeping &&);
	Sleeping & operator=(const Sleeping &);
	Sleeping & operator=(Sleeping &&);
	int state() const; //�������ǰ״̬
	int change_state(); //�ı�˯����ʱ�����Ѽ�ʱ
};
#endif // !SLEEPING_H

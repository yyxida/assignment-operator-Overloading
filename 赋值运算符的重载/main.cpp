#include<iostream>
using namespace std;

class Preson
{
public:
	Preson(int age);
	~Preson();
	int* m_Age;
	Preson& operator=(Preson& p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//m_Age = new int;
		//*m_Age = *p.m_Age;
		//下式等同于上式
		m_Age = new int(*p.m_Age);
		return p;
	}

};

Preson::Preson(int age)
{
	m_Age = new int(age);
}

Preson::~Preson()
{
	if (m_Age != NULL)
	{
		delete m_Age;
		m_Age = NULL;
	}
}

void test01()
{
	Preson p1(18);
	Preson p2(20);
	Preson p3(30);
	p3 = p2 = p1;
	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;


}
int main()
{
	test01();

	return 1;

}
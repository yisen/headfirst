#include <iostream>

using namespace std;

//接口抽象基类，含有纯虚函数
class Ifly
{
	public:
		virtual void fly() = 0;
};

//不同的实现接口
class FlyWithWings : public Ifly
{
	public:
		virtual void fly()
		{
			cout << "fly with wings" << endl;
		}
};

class FlyNoWay : public Ifly
{
	public:
		virtual void fly()
		{
			cout << "fly no way" << endl;
		}
};

//鸭子类
class Duck
{
	public:
		//要用到的接口，必须为指针
		Ifly *ifly;
		//需要实现的行为
		virtual void dofly()
		{
			ifly->fly();
		}
		//共有行为
		virtual void swim()
		{
			cout << "swim" << endl;
		}
};

class ADuck : public Duck
{
	public:
		ADuck()
		{
			ifly = new FlyWithWings();
		}
};

int main(int argc, char *argv[])
{
	Duck *yisen = new ADuck();
	yisen->dofly();
	yisen->swim();
	return 0;
}




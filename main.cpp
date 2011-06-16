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
		//setter method
		void set_fly(Ifly *fly)
		{
			ifly = fly;
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

class DuckCall
{
	public:
		Ifly *ifly;
		DuckCall()
		{
			ifly = new FlyWithWings();
		}
		void set_fly(Ifly * fly)
		{
			ifly = fly;
		}
		void dofly()
		{
			ifly->fly();
		}
};

int main(int argc, char *argv[])
{
	Duck *yisen = new ADuck();
	yisen->dofly();
	yisen->set_fly(new FlyNoWay());
	yisen->dofly();
	yisen->swim();

	DuckCall duckcall;
	duckcall.dofly();
	return 0;
}




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
		void fly()
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
		//纯虚函数，该类为抽象基类，子类如果不实现，则子类还是抽象类
		virtual void swim() = 0;
		//虚函数要有默认的实现
		virtual void display() {};
	protected:
		//要用到的接口，必须为指针
		Ifly *ifly;
};

class ADuck : public Duck
{
	public:
		ADuck()
		{
			ifly = new FlyWithWings();
		}
		void swim()
		{
			cout << "swim" << endl;
		}
		void display()
		{
			cout << "I'm a ADuck" << endl;
		}
};

class DuckCall
{
	public:
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
	protected:
		Ifly *ifly;
};

int main(int argc, char *argv[])
{
	Duck *yisen = new ADuck();
	yisen->dofly();
	yisen->set_fly(new FlyNoWay());
	yisen->dofly();
	yisen->swim();
	yisen->display();

	DuckCall duckcall;
	duckcall.dofly();
	return 0;
}




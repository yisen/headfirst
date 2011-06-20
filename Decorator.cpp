#include <iostream>
#include <string>

using namespace std;

//Beverage抽象基类
class Beverage
{
	public:
		Beverage()
		{
			_desc = "unknown beverage";
		}

		//虚析构函数，当类中有虚函数时，则必须显示声明虚析构函数
		//纯虚析构函数则()后=0，
		virtual ~Beverage() {};

		virtual string get_desc() const
		{
			return _desc;
		}

		virtual int cost() const = 0;

	protected:
		string _desc;
};

//Condiment装饰者类
class CondimentDecorator : public Beverage
{
	public:
		virtual ~CondimentDecorator() {};
		virtual string get_desc() const = 0;
};

//Espresso class
class Espresso : public Beverage
{
	public:
		Espresso()
		{
			_desc = "Espresso";
		}

		int cost() const
		{
			return 2;
		}
};

//House Blend class
class HouseBlend : public Beverage
{
	public:
		HouseBlend()
		{
			_desc = "House Blend Coffee";
		}

		int cost() const
		{
			return 1;
		}
};

//Mocha class
class Mocha : public CondimentDecorator
{
	public:
		Mocha(Beverage *beverage)
		{
			_beverage = beverage;
		}
		~Mocha()
		{
			delete _beverage;
		}

		string get_desc() const
		{
			return _beverage->get_desc() + ", Mocha";
		}

		int cost() const
		{
			return 1 + _beverage->cost();
		}

	private: 
		const Beverage *_beverage;
};

int main(int argc, char *argv[])
{
	Beverage *beverage = new Espresso();
	cout << beverage->get_desc() << ": $" << beverage->cost() << endl;

	beverage = new Mocha(beverage);
	cout << beverage->get_desc() << ": $" << beverage->cost() << endl;

	Beverage *beverage2 = new HouseBlend();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	cout << beverage2->get_desc() << ": $" << beverage2->cost() << endl;

	return 0;
}

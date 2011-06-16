#include <iostream>

using namespace std;

class IObserver
{
	public:
		virtual void update(int tmp, int humidity, int pressure) = 0;
};

//主题接口类
class ISubject
{
	public:
		virtual void register_observer(IObserver *o) = 0;
		virtual void remove_observer(IObserver *o) = 0;
		virtual void notify_observer() = 0;
};


int main(int argc, char *argv[])
{
	
	return 0;
}

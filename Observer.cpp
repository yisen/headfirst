#include <iostream>
#include <list>

using namespace std;

//观察者接口类
class IObserver
{
	public:
		virtual ~IObserver() {};
		virtual void update(int tmp, int humidity, int pressure) = 0;
};

//主题接口类
class ISubject
{
	public:
		virtual ~ISubject() {};
		virtual void register_observer(IObserver *o) = 0;
		virtual void remove_observer(IObserver *o) = 0;
		virtual void notify_observer() const = 0;
};

//显示接口
class IDisplay
{
	public:
		virtual ~IDisplay() {};
		virtual void display() const = 0;
};

//WeatherData类
class WeatherData : public ISubject
{
	public:
		WeatherData()
		{
			_tmp = 0;
			_humidity = 0;
			_pressure = 0;
		}
		//注册观察者
		void register_observer(IObserver *o)
		{
			_observers.push_back(o);
		}
		//取消注册
		void remove_observer(IObserver *o)
		{
			_observers.remove(o);
		}
		//通知观察者
		void notify_observer() const
		{
			for (list< IObserver* >::iterator iterator = _observers.begin(); _observers.end() != iterator; ++iterator)
			{
				IObserver *observer = *iterator;
				observer->update(_tmp, _humidity, _pressure);
			}
		}
		//数据更新时通知观察者
		void data_changed()
		{
			notify_observer();
		}
		//更新数据
		void set_data(int tmp, int humidity, int pressure)
		{
			_tmp = tmp;
			_humidity = humidity;
			_pressure = pressure;
			data_changed();
		}
		//其他函数，获得数据
		int get_tmp() const
		{
			return _tmp;
		}
		int get_humidity() const
		{
			return _humidity;
		}
		int get_pressure() const
		{
			return _pressure;
		}
		
	private:
		int _tmp;
		int _humidity;
		int _pressure;
		mutable list< IObserver* > _observers;	//链表记录观察者
};

class StatisDisplay : private IObserver, private IDisplay
{
	public:
		explicit StatisDisplay(ISubject *weatherData)	//针对接口编程，所以不声明为WeatherData类型
		{
			_weatherData = weatherData;
			_tmp = 0;
			_humidity = 0;
			_pressure = 0;

			_weatherData->register_observer(this);
		}
		~StatisDisplay()
		{
			_weatherData->remove_observer(this);
		}
		//display
		void display() const
		{
			cout << "tmp: " << _tmp << " humidity: " << _humidity << " pressure: " << _pressure << endl;
		}
		//update
		void update(int tmp, int humidity, int pressure)
		{
			_tmp = tmp;
			_humidity = humidity;
			_pressure = pressure;
			display();
		}
	private:
		int _tmp;
		int _humidity;
		int _pressure;
		ISubject *_weatherData;

};


int main(int argc, char *argv[])
{
	WeatherData weatherData;
	StatisDisplay statisDisplay(&weatherData);
	weatherData.set_data(1, 2, 3);
	weatherData.set_data(3, 2, 1);
	weatherData.set_data(10, 200, 30);
	return 0;
}

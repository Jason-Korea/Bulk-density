#pragma once
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class TimerClock
{
public:
	TimerClock()
	{
		update();
	}

	~TimerClock()
	{
	}

	void update()
	{
		_start = high_resolution_clock::now();
	}
	//获取秒
	double getTimerSecond()
	{
		return getTimerMicroSec() * 0.000001;
	}
	//获取毫秒
	double getTimerMilliSec()
	{
		return getTimerMicroSec() * 0.001;
	}
	//获取微妙
	long long getTimerMicroSec()
	{
		//当前时钟减去开始时钟的count
		return duration_cast<microseconds>(high_resolution_clock::now() - _start).count();
	}
	//获取当前相对于1970年的微妙
	long long getTimerMicroSecFrom1970()
	{
		return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
	}
private:
	time_point<high_resolution_clock>_start;
};

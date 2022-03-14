#include "SphereProducer.h"
#include "TimerClock.h"

#include <random>


bool SphereProducer::produce()
{
	/*srand((unsigned)time(0));*/

	int i=0;
	TimerClock tc;//使用时间来获得随机数种子
	default_random_engine e((tc.getTimerMicroSecFrom1970() % 100) * 100);
	uniform_int_distribution<long> u1(1, 99);//希望0到100之间的随机数
	for ( i; i < 25000; i++)
	{

		//int randNum = u1(e);
		float x = u1(e);
		//_sleep(2);
		float y = u1(e);
		//float x = rand() % 99 + 1;
		//float y = rand() % 99 + 1;

		bool flag = true;
		float dis;
		for (auto p : centers)
		{
			dis = sqrt(pow((p[0] - x), 2) + pow((p[1] - y), 2));
			if (dis < 2)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			
			if (sumArea < 3000)
			{
				centers.push_back({ x,y });
				sumArea += 3.14;
			}
			else
			{
				return true;
			}
		}
		else
			continue;
	}

	//if (i >= 2500)
	//{
	//	centers.clear();
	//	centers.push_back({ 1,1 });
	//	sumArea = 3.14;
	//	produce();
	//}

	return false;
}
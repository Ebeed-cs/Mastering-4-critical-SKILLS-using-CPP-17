#include<iostream>
using namespace std;
/*
							Appoach 2
*/

int main() {
	int count = 0;
	for (int x = 50; x <= 300; ++x)
	{
		int start = 70;
		if (start <= x)
			start = x + 1;
		for (; start <= 400; ++ start)
		{
			if ((x + start) % 7 == 0)
				count++;
		}
	}
	cout << count << endl;
	return 0;
}

/*
	speeded up in alittle
*/

#include<iostream>
using namespace std;
/*
							Appoach 2
			Find Special Pairs

		● Count How many X, Y numbers such that
			○ X in range [50-300]
			○ Y in range [70-400]
			○ X < Y
			○ (X+Y) divisible by 7

		● Output
			○ 8040


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

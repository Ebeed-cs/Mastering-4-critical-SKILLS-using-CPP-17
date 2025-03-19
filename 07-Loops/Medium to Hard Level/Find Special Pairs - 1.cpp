#include<iostream>
using namespace std;
/*
							Appoach 1
							
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
		for (int y = 70; y <= 400; ++y)
		{
			if ((x < y) && (((x + y) % 7) == 0))
				count++;
		}
	}
	cout << count << endl;
	return 0;
}

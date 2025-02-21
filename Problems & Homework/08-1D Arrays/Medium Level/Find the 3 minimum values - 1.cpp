#include<iostream>
using namespace std;

/*			

				Find the 3 minimum values

		● Read integer N (>= 3), then read N integers. Find the 3 lowest numbers.
			○ Don’t change the array content
			○ Don’t iterate on the array more than once
	
		● Input ⇒ Output
			○ 5		4 1 3 10 8  ⇒  1 3 4     
			○ 3     7 9 -2  ⇒ -2 7 9 


*/

int main() {
	int N;
	cin >> N;
	int arr_min[3];

	int input;
	for(int i = 0; i< N; ++i)
	{
		cin >> input;
		if(i < 3)
		{
			if(!i)
				arr_min[i] = input;	

			else if(i == 1)
			{
				if(input < arr_min[0])
				{
					arr_min[1] = arr_min[0];
					arr_min[0] = input; 
				}
				else
					arr_min[1] = input;
			}

			else if(i == 2)
			{
				if(input < arr_min[0])
				{
					arr_min[2] = arr_min[1];
					arr_min[1] = arr_min[0];
					arr_min[0] = input;
				}
				else if(input < arr_min[1])
				{
					arr_min[2] = arr_min[1];
					arr_min[1] = input; 
				}
				else
					arr_min[2] = input;
			}
		}
		else
		{
			if(input < arr_min[0])
			{
				arr_min[2] = arr_min[1];
				arr_min[1] = arr_min[0];
				arr_min[0] = input;
			}
			else if(input < arr_min[1])
			{
				arr_min[2] = arr_min[1];
				arr_min[1] = input;
			}
			else if(input < arr_min[2])
				arr_min[2] = input;
		}
	}
	for(int i = 0; i < 3; ++i)
		cout << arr_min[i] << " ";
	return 0;
}


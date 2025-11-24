#include<iostream>
using namespace std;


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


#include<iostream>
using namespace std;


int main() {
	int start1, end1 , start2 , end2;

	cin >> start1 >> end1;
	cin >> start2 >> end2;

	if(end1 < start2 ||
		end2 < start1 )

		cout << -1 << endl;
	else
	{
		if(start2 > start1)
			start1 = start2;   // bigger start 
		if(end2 < end1)
			end1 = end2;  	  // smaller end
		cout << start1 << " " << end1 << endl;
	}
	return 0;
}

/*
	test cases : 
	1. Input:  1 6 3 8    → Expected Output: 3 6      (Overlap is [3, 6])
	2. Input:  2 5 2 5    → Expected Output: 2 5      (Both intervals are identical)
	3. Input:  2 10 2 6   → Expected Output: 2 6      (Second interval ends earlier)
	4. Input:  2 10 6 12  → Expected Output: 6 10     (Overlaps from the right)
	5. Input:  2 10 4 8   → Expected Output: 4 8      (Second interval is inside the first)

	6. Input:  1 5 6 10   → Expected Output: -1       (No overlap, second interval starts after first ends)
	7. Input:  1 15 20 30 → Expected Output: -1       (Completely separate intervals)

	8.  Input:  0 0 0 0     → Expected Output: 0 0     (Both intervals are a single-point)
	9.  Input:  1 5 5 10    → Expected Output: 5 5     (Intervals touch at a single point)
	10. Input:  1000000 2000000 1500000 2500000 → Expected Output: 1500000 2000000 (Large number test)

*/

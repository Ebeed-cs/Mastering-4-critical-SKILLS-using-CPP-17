#include<iostream>
using namespace std;

int main() {

	int a = 10, b = 20, c = 30, d = 40;

	cout << (a + b == c) << "\n"; // addition higher priority
								  // (10 + 20 == 30) -> (30 == 30) -> true -> 1 

	cout << (a + b + c >= 2 * d) << "\n";
								  // (10 + 20 + 30 >= 2 * 40) -> (10 + 20 + 30 >= 80) -> (60 >= 80)-> false -> 0 

	cout << (a > 5 || d < 30) << "\n";
								 // (10 > 5 || 40 < 30) -> (true || false) -> true -> 1  
	
	cout << (a > 5 && d < 30) << "\n";
								 // (10 > 5 && 40 < 30) -> (true && fasle) -> false -> 0 

	cout << (a <= b && b <= c) << "\n";
								// (10 <= 20 && 20 <= 30) -> (true && true) -> true -> 1

	cout << (a > 5 && d < 30 || c - b == 10) << "\n";
								// ( 10 > 5 && 40 < 30 || 30 - 20 == 10) -> (10 > 5 && 40 < 30 || 10 == 10) -> (ture && false || true) -> true -> 1 

	cout << (a <= b && b <= c && c <= d) << "\n";
								// (10 <= 20 && 20 <= 30 && 30 <= 40) -> (true && true && true) -> ture -> 1

	cout << (a > 5 && d < 30 || c > d || d % 2 == 0) << "\n";
							   // (10 > 5 && 40 < 30 || 30 > 40 || 40 % 2 == 0) -> (10 > 5 && 40 < 30 || 30 > 40 || 0 == 0)-> (true && false || false || true)-> (false || false || true)-> trur -> 1

	cout << (a > 5 && d < 30 || c > d && d % 2 == 0) << "\n";
							  // (10 > 5 && 30 < 30 || 30 > 40 && 40 % 2 == 0) -> (true && false || false && 0 == 0)-> (true && false || false && true ) -> (false || false)-> false -> 0

	cout << ( a == 10 || b != 20  && c != 30 || d != 40) << "\n";
							  // (10 == 10 || 20 != 20 && 30 != 30 || 40 != 40)-> (true || false && false || false)-> (true || false || false)-> true -> 1
	cout << ((a == 10 || b != 20) && c != 30 || d != 40) << "\n";
							  // ((10 == 10 || 20 != 20) && 30 != 30 || 40 != 40)-> ((true ||false) && 30 != 30 || 40 != 40)-> (true && 30 != 30 || 40 != 40)-> (true && false || false)-> (false || false)-> false -> 0

	return 0;
}


#include <iostream>
using namespace std;


bool is_prefix(string main, string prefix, int start_pos = 0) {
	if (start_pos >= prefix.length()) return true;

	if (main[start_pos] != prefix[start_pos]) return false;

	return is_prefix(main, prefix, start_pos + 1);
}

int main() {
	cout << is_prefix("abcdefgh", "abcd") << endl;
	cout << is_prefix("abcdefgh", "") << endl;
	cout << is_prefix("abcdefgh", "abd") << endl;

	return 0;
}

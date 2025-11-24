#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;

    for (auto& asteroid : asteroids) {
        // For every new asteroid, remove all what will explode
        // Only may happens when asteroid going backword and something coming forward 'asteroid < 0 && 0 < result.back()'
        bool is_exploded = false;
        while (!result.empty() && asteroid < 0 && 0 < result.back()) {
            // last will explode.
            if (result.back() < -asteroid) {
                result.pop_back();
                continue;	// See if more explode
            }
            else if (result.back() == -asteroid)	// both exploded
                result.pop_back();
            is_exploded = true;		// only asteroid explode
            break;
        }
        if (!is_exploded)
            result.push_back(asteroid);
    }
    return result;
}

int main() {
    vector<int> v = { 10 , 5 , 2 , -5 , -7 };
    v = asteroidCollision(v);

    for (int val : v)
        cout << val << " ";

    return 0;
}

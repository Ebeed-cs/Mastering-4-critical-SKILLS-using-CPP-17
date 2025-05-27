#include <iostream>
#include <vector>
using namespace std;

/*
                            Asteroid Collision

                            https://leetcode.com/problems/asteroid-collision/description/

                    We are given an array asteroids of integers representing asteroids in a row.

                    For each asteroid, the absolute value represents its size, and the sign represents its
                    direction (positive meaning right, negative meaning left). Each asteroid moves at the
                    same speed.

                    Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller
                    one will explode. If both are the same size, both will explode. Two asteroids moving in
                    the same direction will never meet.

                    Example 1:
                    Input:
                    asteroids = [5, 10, -5]
                    Output: [5, 10]
                    Explanation:
                    The 10 and -5 collide resulting in 10. The 5 and 10 never
                    collide.

                    Example 2:
                    Input:
                    asteroids = [8, -8]
                    Output: []
                    Explanation:
                    The 8 and -8 collide exploding each other.

                    Example 3:
                    Input:
                    asteroids = [10, 2, -5]
                    Output: [10]
                    Explanation:
                    The 2 and -5 collide resulting in -5. The 10 and -5 collide
                    resulting in 10.

                    Example 4:
                    Input:
                    asteroids = [-2, -1, 1, 2]
                    Output: [-2, -1, 1, 2]
                    Explanation:
                    The -2 and -1 are moving left, while the 1 and 2 are moving right.
                    Asteroids moving the same direction never meet, so no asteroids
                    will meet each other.

                    // https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/asteroid-collision.cpp


*/

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

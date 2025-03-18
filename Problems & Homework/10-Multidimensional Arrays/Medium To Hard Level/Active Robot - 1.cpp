#include <iostream>
using namespace std;
/*
                Active Robot - 1

    ● Read integers N, M represents a matrix. A robot start at cell (0, 0).
    ● Read integer K, then K commands. Each command is 2 values
        ○ Direction from 1 to 4: up, right, down, left
        ○ Steps: a number to number steps to take in the direction. Steps [1, 1000000000]
        ○ If the robot hits the wall during the move, it circulates in the matrix.
        ○ For every command, print where is the robot now

    ● Input
        ○ 3 4  4   2 1   3 2   4 2   1 3
            ■ 2 1 means to right 1 step - 3 2 means down 2 steps
    ● Output
        ○ (0, 1) (2,1) (2, 3) (2, 3)

*/

int main() {
    int row , col;
    cin >> row >> col;

    int i = 0, j = 0;
    
    int Q;
    cin >> Q;
    for(int query = 0; query < Q; ++query){

        int k , step; 
        cin >> k >> step;
        switch(k){
            case 1:
            while(step --){
                if(!i)
                    i = row - 1;
                else
                    i --;
                }
            break;

            case 2:
            while(step --){
                if(j == col - 1)
                    j = 0;
                else
                    j ++;
            }
            break;

            case 3:
            while(step --){
                if(i == row - 1)
                    i = 0;
                else
                    i++;
            }
            break;

            case 4:
            while(step --){
                if(!j)
                    j = col - 1;
                else
                    j --;
            }
            break;
            }
            cout << i << " " << j << endl; 
        }

        return 0;
    }

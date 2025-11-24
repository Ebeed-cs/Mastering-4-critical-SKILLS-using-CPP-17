#include <iostream>
using namespace std;


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

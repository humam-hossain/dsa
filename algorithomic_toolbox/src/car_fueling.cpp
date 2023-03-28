#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int count = 0;
    int curr = 0;
    int next = tank;

    while(next < dist){
        for(int i=0; i<stops.size(); i++){
            if(curr + tank < stops[i]){
                break;
            }

            next = stops[i];
        }

        // cout << curr << " : " << next << "\n";
        if(curr == next){
            break;
        }
        curr = next;
        next = curr + tank;

        count++;
    }

    if(next < dist){
        return -1;
    }

    return count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
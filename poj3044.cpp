#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char **argv){
    int n, w;
    cin >> n;
    cin >> w;
    stack<int> s;
    int result = 0;
    s.push(0);
    int cur;
    int waste;
    for(int i = 0; i < n; i++){
        cin >> waste;
        cin >> cur;
        if(s.top() < cur){
            result++;
            s.push(cur);
        } else if(cur < s.top()){
            s.pop();
            if(s.top() != cur){
                s.push(cur);
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}//10, 26, (1,1), (2,2), (5,1), (6,3), (8,1), (11,0), (15,2), (17,3), (20,2), (22,1). 
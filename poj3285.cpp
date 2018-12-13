#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int t = 1, w = 1, result = (1 << 31);
    cin >> t >> w;
    int data[1001];
    int arr[32][1001];
    for(int i = 0; i < t; i++){
        cin >> data[i];
    }
    arr[0][0] = (data[0] == 1) ? 1 : 0;
    for(int i = 1; i < t; i++){
        arr[0][i] = arr[0][i - 1];
        if(data[i] == 1){
            arr[0][i]++;
        }
    }
    for(int i = 1; i <= w; i++){
        if(i > 1) arr[i][i - 2] = 0;
        for(int j = i - 1; j < t; j++){
            arr[i][j] = max(arr[i][j - 1], arr[i - 1][j - 1]);
            if((i % 2 + 1) == data[j]) arr[i][j]++;
        }
    }
    for(int i = 0; i < w + 1; i++){
        result = max(result, arr[i][t - 1]);
    }
    cout << result << endl;
    return 0;
}
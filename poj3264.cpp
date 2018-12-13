#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

struct tree{
    tree *l,*r;
    int min;
    int max;
    tree(){
        l = NULL; r = NULL; min = INT_MAX, max = INT_MIN;
    }
};

void updateTree(tree*& root, int val, int left, int right, int ind){
    if(root == NULL) root = new tree();
    if(root->max < val) root->max = val;
    if(root->min > val) root->min = val;
    if(right == left) return;
    if(ind <= (left + right)/2){
        updateTree(root->l, val, left, (left + right)/2, ind);
    } else updateTree(root->r, val, (left + right)/2 + 1, right, ind);
}

void ans(tree* &root , int left, int right, int querLeft, int querRight, int& min, int& max){

    if(root == NULL) return;

    if(left >= querLeft && right <= querRight) {
        if(root->max > max) max = root->max;
        if(root->min < min) min = root->min;
        return;
    }

    if(left > querRight || right < querLeft) return;

    ans(root->l, left, (left + right)/2, querLeft, querRight, min, max);
    ans(root->r, (left + right)/2 + 1, right, querLeft, querRight, min, max);
}

int main(int argc, char **argv){
    ios::sync_with_stdio(0);
    int n, q, a, b, val, min, max;
    cin >> n >> q;
    int qArr[q];
    tree* root = NULL;

    for(int i = 1; i <= n; i++){
        cin >> val;
        updateTree(root, val, 1, n, i);
    }
    for(int j = 0; j < q; j++){
        cin >> a >> b;
        min = INT_MAX, max = INT_MIN;
        ans(root, 1, n, a, b, min, max);
        qArr[j] = max - min;
    }
    for(int m = 0; m < q; m++){
        cout << qArr[m] << endl;
    }

    return 0;
}

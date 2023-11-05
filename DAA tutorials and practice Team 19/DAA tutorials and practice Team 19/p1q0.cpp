// Practice - 1 - 24/July/2023
// 0. Given an array of integers, discover a logic to find a number which is
// neither minimum nor maximum.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// method 1: sorting // T.C: O(nlogn) // does not work for duplicates
void method1(vector<int> arr) {
    sort(arr.begin(), arr.end());
    cout << "Method 1 answer: " << arr[1] << endl;
    return;
}

// method 2: find min and max // T.C: O(n) // works for duplicates
void method2(vector<int>& arr) {
    int mini = arr[0], maxi = arr[0];
    for(int num: arr) {
        mini = min(mini, num);
        maxi = max(maxi, num);
    }
    int flag = 0;
    for(int num: arr) {
        if(num != mini && num != maxi) {
            cout << "Method 2 answer: " << num << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0) cout << "Method 2 answer: NIL" << endl; 
    return;
}

// method 3: find min and max(only for first 3 elements) // T.C: O(8) ~ O(1) // does not work for duplicates
void method3(vector<int>& arr) {
    if(arr[0] > min(arr[1], arr[2]) && arr[0] < max(arr[1], arr[2])) cout << "method 3 ans: " << arr[0] << endl;
    else if(arr[1] > min(arr[0], arr[2]) && arr[1] < max(arr[0], arr[2])) cout << "method 3 ans: " << arr[1] << endl;
    else cout << "method 3 answer: " << arr[2] << endl;
    return;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if(n < 3) {
        cout << "An element which is neither minimum nor maximum doesn't exist!" << endl;
        return -1;
    }
    vector<int> arr(n);
    cout << "Enter the elements of the array:-" << endl;
    for(int i = 0; i < n; i++) cin >> arr[i];
    method1(arr);
    method2(arr);
    method3(arr);
    return 0;
}
// Practice - 1 - 24/July/2023
// 1. Discover 3 different logic to solve (i) GCD (m,n) (ii) GCD (n1,n2,...nk).
// Define a suitable parameter of interest for comparison and pick the best
// logic out of 3.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// (i) For two elements:-
// method 1: Euclidean algorithm // T.C: O(log(min(x, y)))
int method1(int x, int y) {
    if(x == 0) return y;
    if(y == 0) return x;
    if(x == y) return x;
    if(x > y) {
        while(y != 0) {
            int remainder = x % y;
            x = y;
            y = remainder;
        }
        return x;
    } else {
        while(x != 0) {
            int remainder = y % x;
            y = x;
            x = remainder;
        }
        return y;
    }
}

// method 2: Recursive approach // T.C: O(log(min(x, y)))
int method2(int x, int y) {
    if(x == 0) return y;
    if(y == 0) return x;
    if(x == y) return x;
    if(x > y) {
        if(y == 0) return x;
        else return method2(y, x % y);
    } else {
        if(x == 0) return y;
        else return method2(x, y % x);
    }
}

// method 3: Divide with minimum // T.C. O(min(x, y))
int method3(int x, int y) {
    if(x == 0) return y;
    if(y == 0) return x;
    if(x == y) return x;
    if(x > y) {
        int gcd = y;
        while(true) {
            if((x % gcd == 0) && (y % gcd == 0)) break;
            gcd--;
        }
        return gcd;
    } else {
        int gcd = x;
        while(true) {
            if((y % gcd == 0) && (x % gcd == 0)) break;
            gcd--;
        }
        return gcd;
    }
}

// method 4: Stein's method // T.C: O(log(min(a, b)))
int method4(int x, int y) {
    if(x == 0) return y;
    if(y == 0) return x;
    if(x == y) return x;
    if(x % 2 == 0 && y % 2 == 0) return 2 * method4(x / 2, y / 2);
    if(x % 2 == 0 && y % 2 != 0) return method4(x / 2, y);
    if(x % 2 != 0 && y % 2 == 0) return method4(x, y / 2);
    if(x > y) return method4((x - y) / 2, y);
    return method4((y - x) / 2, x);
}

// (ii) For 'n' elements:-
// method 1: Euclidean algorithm // T.C: O(nlog(min(a[i], a[i - 1])))
int method1_n(vector<int>& arr, int n) {
    int gcd = arr[0];
    for(int i = 1; i < n; i++) {
        if(gcd == 1) break;
        gcd = method1(gcd, arr[i]);
    }
    return gcd;
}

// method 2: Recursive approach // T.C: O(nlog(min(a[i], a[i - 1])))
int method2_n(vector<int>& arr, int n) {
    int gcd = arr[0];
    for(int i = 1; i < n; i++) {
        if(gcd == 1) break;
        gcd = method2(gcd, arr[i]);
    }
    return gcd;
}

// method 3: Divide with minimum // T.C: O(max(mini, n^2))
int method3_n(vector<int>& arr, int n) {
    auto min_ptr = min_element(arr.begin(), arr.end());
    int mini = *min_ptr;
    for(int i = 0; i < n; i++) {
        if(arr[i] % mini != 0) {
            mini--;
            i = 0;
        }
    }
    return mini;
} 

// method 4: Stein's method // T.C: O(nlog(min(a[i], a[i - 1])))
int method4_n(vector<int>& arr, int n) {
    int gcd = arr[0];
    for(int i = 1; i < n; i++) {
        if(gcd == 1) break;
        gcd = method4(gcd, arr[i]);
    }
    return gcd;
}

int main() {
    char choice;
    cout << "Solve for '2' elements or 'n' elements: ";
    cin >> choice;
    if(choice == '2') {
        int x, y;
        cout << "Enter the '2' elements: ";
        cin >> x >> y;
        cout << "Method 1 answer: " << method1(x, y) << endl;
        cout << "Method 2 answer: " << method2(x, y) << endl;
        cout << "Method 3 answer: " << method3(x, y) << endl;       
        cout << "Method 4 answer: " << method4(x, y) << endl;
    } else {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array:-" << endl;
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << "Method 1 answer: " << method1_n(arr, n) << endl;
        cout << "Method 2 answer: " << method2_n(arr, n) << endl;
        cout << "Method 3 answer: " << method3_n(arr, n) << endl;
        cout << "Method 4 answer: " << method4_n(arr, n) << endl;
    }
    return 0;
}

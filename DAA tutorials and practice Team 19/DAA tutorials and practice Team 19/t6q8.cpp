#include <vector>
#include <iostream>
using namespace std;

int trapWater(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    vector<int> elevationMap;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int data;
        cin>>data;
        elevationMap.push_back(data);
    }
    int result = trapWater(elevationMap);
    cout << "The amount of water that can be stored is: " << result << endl;

    return 0;
}
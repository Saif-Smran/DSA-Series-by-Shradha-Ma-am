#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size()-2,mid;

        while(st <= end){
            mid = st + (end - st)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            if(arr[mid-1] < arr[mid]){
                st = mid + 1;
            }
            else{
                end = mid -1;
            }
        }
        return -1;
    }


int main()
{
    
    return 0;
}
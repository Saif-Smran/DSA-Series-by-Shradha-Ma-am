#include<iostream>
#include<vector>
#include<algorithum>
using namespace std;

void sortColorsB(vector<int>& nums) // Bruteforce
    {
        sort(nums.begin(),nums.end());
    }

void sortColorsO(vector<int>& nums) // Optimized
      {
        int n =nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i = 0; i< n; i++){
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        int idx = 0;
        for(int i = 0; i< count0; i++){
            nums[idx] = 0;
            idx++;
        }
        for(int i = 0; i< count1; i++){
            nums[idx] = 1;
            idx++;
        }
        for(int i = 0; i< count2; i++){
            nums[idx] = 2;
            idx++;
        }
    }

void sortColorsDNF(vector<int>& nums) // DNF
	{
        int n =nums.size();
        int mid= 0,high = n-1,low=0;

        while(mid<= high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++; mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }

int main()
	{

	return 0;
	}
/******************************************************************************

Searching elment in biotonic array
biotonic array is  a array in which sequence is firstly increasing and then strictly decreasing with all distinct element's
example 1 4 5 6 8 1 2
time complexity -> O(log(n))
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

	int t1 = 0;
	void binary_search(int l,int r,vector<int> arr,int s)
	{
		if(l<=r)
		{
			int mid = (l+r)/2;
			if(arr[mid]==s)
			{
				t1 = mid;
			}
			if(arr[mid]>s)
			{
			binary_search(l,mid-1,arr,s);
			}
			else
			{
				binary_search(mid+1,r, arr,s);
			}
		}
	}
	
	void binary(int l,int r,vector<int> arr, int s)
	{
		if(l<=r)
		{
			int mid = (l+r)/2;
			if(arr[mid]==s)
			{
				t1 = mid;
			}
			if(arr[mid]>s)
			{
					binary(mid+1,r, arr, s);
			
			}
			else
			{
				binary(l,mid-1,arr, s);
			}
		}
	}
    int findPeakElement(vector<int>& nums) {
        int ans = 0;
        if(nums.size()==1)
        {
            ans = 0;
        }
        else
        {
            int left,right;
            left = 0;
            right = nums.size()-1;
            while(left<=right)
            {
                int mid = (left+right)/2;
                if(mid==0 || mid==nums.size()-1)
                {
                    if(mid==0)
                    {
                        if(nums[mid]>=nums[mid+1])
                        {
                            ans = 0;
                            break;
                        }
                        else
                        {
                            left = mid+1;
                        }
                    }
                    else if(mid==nums.size()-1)
                    {
                        if(nums[mid]>nums[mid-1])
                        {
                            ans = mid;
                            break;
                        }
                        else
                        {
                            right = mid-1;
                        }
                    }
                }
                else if(nums[mid]>nums[mid+1] && nums[mid]>=nums[mid-1])
                {
                     ans = mid;
                    break;
                }
                else if(nums[mid-1]<nums[mid+1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return ans;
    }
int main()
{
         int size;
     vector<int> array;
     cin>>size;
    for(int i = 0 ; i <size;i++)
    {
        int t;
        cin>>t;
        array.push_back(t);
    }
    int maximum = findPeakElement(array);
    int t;
    cin>>t;
    while(t--)
    {
    	int element;
    	cin>>element;
    	if(element>array[maximum])
    	{
    		cout<<"\nSoRRY BUT ELEMENT IS NOT FOUND \n";
		}
		else
		{
			if(element==array[maximum])
	    	{
	    		cout<<"\n"<<element<<" is found at index "<<maximum<<" \n";
			}
			else
			{
				t1 = -1;
				 binary_search(0,maximum,array,element);
				if(t1!=-1)
				{
					cout<<"\n"<<element<<" is found at index "<<t1<<" \n";
				}
				else
				{
					binary(maximum+1,size-1,array,element);
					if(t1!=-1)
					{
						cout<<"\n"<<element<<" is found at index "<<t1<<" \n";
					}
					else
					{
						cout<<"\nSORRY BUT ELEMENT IS NOT FOUND \n";
					}
					
				}
			}
		}
	}
    return 0;
}


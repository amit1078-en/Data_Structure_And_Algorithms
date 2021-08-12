#include <iostream>
using namespace std;

void findfactorial(int num)
{
	int arr[3000];
	arr[0] = 1;
	arr[1] = 1;
	int ind = 1;
	for( int top = 2; top<= num ;top++)
	{
		int carry =  0 ;
		for(int j =0;j<ind;j++)
		{
			int temp = (top*arr[j])+carry;
			arr[j] = temp%10;
			carry = temp/10;
		}
		
		while(carry>0)
		{
			arr[ind]  = carry%10;
			carry/=10;
			ind++;
		}
	}
	for(int i  = ind-1  ;    i>=0;       i--)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int num;
	    cin>>num;
	    findfactorial(num);
	}
	return 0;
}

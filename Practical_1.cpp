// Practical 1: 
#include<iostream>
using namespace std;
int binary_search(int arr[], int low, int high, int ele)
{
	if(low<=high)
	{
		int mid;
		mid=(low+high)/2;
		if(arr[mid]==ele)
		return mid;
		if(arr[mid]<ele)
		return binary_search(arr, mid+1, high, ele);
		if(arr[mid]>ele)
		return binary_search(arr, low, mid-1, ele);
	}
	return -1;
}
int main()
{
	int arr[7]={8, 16, 18, 20, 24, 32, 34};
	int fun = binary_search(arr, 0, 7, 32);
	if(fun==-1)
	{	
		cout<<"Not found the element";
	}
	else
	{
		 cout<<"Found at index: "<<fun<<"\n";
	}
}


/* OUTPUT:
Found at index: 5
*/
/*name-navya maggon
rollno-2010991953
Q1. */
#include <bits/stdc++.h>
using namespace std;

/* function to find the maximum length of subarray
having sum n */
int MaximumLength(int arr[],int n,int target)
{

	// unordered_map 'um' implemented
	// as hash table
	unordered_map<int, int> um;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'
		if (sum == target)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'um'
		if (um.find(sum) == um.end())
			um[sum] = i;

		// check if 'sum-target' is present in 'um'
		// or not
		if (um.find(sum - target) != um.end()) {

			// update maxLength
			if (maxLen < (i - um[sum - target]))
				maxLen = i - um[sum - target];
		}
	}

	// required maximum length
	return maxLen;
}

int main()
{
    //initialisation of array
	int arr[]={5,6,-5,5,3,5,3,-2,0};
	cout<<"Enter Target sum:"<<endl;
	int target ;
	cin>>target;
	int n = sizeof(arr) / sizeof(arr[0]);


    cout<<"Subarray with sum "<<target<<" are"<<endl;
	cout << " The longest subarray has Length = ";
    cout<< MaximumLength(arr, n, target);

	return 0;
}


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include "sorts.cpp"
#include "time.h"

using namespace std;

// Number theory to the rescue
// Generates a permutation of [0 .. n-1]
// Where d>n and both are prime


int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);
vector<long> GenerateRandom(long n, long d);
vector<long> GenerateSorted(long n);
vector<long> GenerateReverseSorted(long n);
vector<long> GenerateAlmostSorted(long n, int s);

//=====================================================================================

int main()
{

	struct timeval start, end, diff;

	string str; string str1; string str2;
	long n;

	vector<long> num;

	cout<<endl;
	cout<<"What type of vector would you like: "<<endl;
	cout<<"1) Random"<<endl;
	cout<<"2) Sorted"<<endl;
	cout<<"3) Reverse Sorted"<<endl;
	cout<<"4) Almost Sorted"<<endl;

	getline(cin, str);

	cout<<"Enter size(n): ";
	cin>>n;

	if(str == "1")
	{
		long d;
		cout<<"Enter randomizer (d>n): "; cin>>d;
		num = GenerateRandom(n, d);
	}
	else if(str == "2")
	{
		num = GenerateSorted(n);
	}
	else if(str == "3")
	{
		num = GenerateReverseSorted(n);
	}
	else if(str == "4")
	{
		long s;
		cout<<"Enter inversion number: "; cin>>s;
		num = GenerateAlmostSorted(n, s);
	}

// to display the created vector

	cout<<"unsorted vector:"<<endl;
	for(int i=0; i<num.size(); i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl<<endl;

//=====================================================================================

	cout<<"Enter the sort you would like to use: "<<endl;
	cout<<"1) Insertion Sort"<<endl;
	cout<<"2) Merge Sort"<<endl;
	cout<<"3) Quick Sort (on Arrays)"<<endl;
	cout<<"4) Quick Sort (on Lists)"<<endl;
	cout<<"5) Heap Sort"<<endl;
	cout<<"6) Bucket Sort"<<endl;
	int size=n;

	if (size==10)
	{
	num=QuickSortList(num);
	}
	else if (size==10000){
		num=InsertionSort(num);
	}
	else if (size==100000){
		num=HeapSort(num);
	}

   cout<<"sorted vector:"<<endl;
    for(int i=0; i<num.size(); i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//=====================================================================================
//Vector Generation Functions

vector<long> GenerateRandom(long d, long n)
{
    vector<long> nums;
    long k, residue;
    for (k = 0; k < d; k++)
    {
        residue = (long) (((long long)k * (long long) n) % d);
        nums.push_back(residue);
    }
    return nums;
}

vector<long> GenerateSorted(long n)
{
    vector<long> nums;
    for (long k = 0; k < n; k++)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateReverseSorted(long n)
{
    vector<long> nums;
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateAlmostSorted(long n, int s)
{
    vector<long> nums;
    srand ( time(NULL) );
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    int k1, k2;
    long tmp;
    for (size_t i = 0; i < s; i++)
    {
        k1 = rand() % n;
        k2 = rand() % n;
        tmp = nums[k2];
        nums[k2] = nums[k1];
        nums[k1] = tmp;
    }
    return nums;
}




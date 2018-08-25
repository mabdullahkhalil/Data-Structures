#include <fstream>
#include "sorts.cpp"

using namespace std;


// A single pair is stored in a Vector<long>
// You have to return a vector of all pairs.
vector< vector<long> > smartSearch(vector<long> nums, long k)
{
    vector<long> sorted=HeapSort(nums);
    vector<vector<long> > thismain;
    vector<long> pair;
    int j=nums.size()-1;
    for (int i=0; i<j; i++) {
        vector<long> pair;
        if (sorted[i]+sorted[j-i] == k) {
            pair.push_back(sorted[i]);
            pair.push_back(sorted[(j-i)]);
            thismain.push_back(pair);
        }
        else if(sorted[i]+sorted[(j-i)] < k)  {
            i=i+1;
        }
        else if (sorted[i]+sorted[(j-i)] > k){
            j=j-1;
        }
    }
    return thismain;
}


int main()
{
    vector<long> nums;
    ifstream in("random.txt");
    long n;
    while(in >> n)
        nums.push_back(n);
    in.close();
    
    long k;
    cout << "Enter the value of K: ";
    cin >> k;
    
    vector< vector<long> > result = smartSearch(nums, k);
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i][0] << ", " << result[i][1] << endl;
    
    return 0;
}
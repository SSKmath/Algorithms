#include <iostream>
#include <vector>

using namespace std;

int maxSequence(const vector<int> arr) 
{
    if (arr.size() == 0)
		    return 0;
	  int cntNegative = 0;
	  for (int i = 0; i < arr.size(); i++)
	  {
		    if (arr[i] < 0)
			    cntNegative++;
	  }
	  if (cntNegative == arr.size())
		    return 0;

    int mxS = arr[0];
    int S = arr[0];
    for (int i = 1; i < arr.size(); i++) 
	  {
        S = max(arr[i], S + arr[i]);
        mxS = max(mxS, S);
    }
    return mxS;
}

int main()
{
	  cout << maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
}

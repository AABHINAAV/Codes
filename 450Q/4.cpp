#include<bits/stdc++.h>
using namespace std;



 // https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

class Solution
{
    public:
void sort012(int a[], int n)
{
int i=0,j=n-1;
while(i<=j)
{
if(a[i]==0)
i++;
else
{
if(a[j] == 0)
{
swap(a[i],a[j]);
i++;
j--;
}
else
{
j--;
}
}
}
j=n-1;
while(i<=j)
{
if(a[i]==1)
i++;
else
{
if(a[j] == 1)
{
swap(a[i],a[j]);
i++;
j--;
}
else
{
j--;
}
}
}
}
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

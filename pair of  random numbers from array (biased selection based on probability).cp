#include<bits/stdc++.h>
#define pi 3.14159265359
#define ll long long
#define wh(t) int t;cin>>t; while(t--)
#define speed  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#include<string.h>

//aditya ranaut - phoenix_aditya

//this program selects two elements from an array based on a bias

vector<int> arraybias;

void generateselective(int arr[], double bias[], int n)
{
    
//    function need to run 1 time to generate the array containing instances of sample array
//    based on a bias (bias is probability of element to be selected in the array
//    this will thus create a biased array from which when we select 2 random elements will
//    give us biased instances of sample array
    
    for(int i=0;i<n;i++)
    {
        
        int k=ceil(1.0*bias[i]*n);
        
        
        while(k--)
            arraybias.push_back(arr[i]);
    }
}

pair<int,int> generatepair(int n)
{
//    taking seed of random based on system time to generate random integers on each instance of program run
    
    int randomnumber;
    
    srand((unsigned)time(0)*rand());
    
    int a[2];
//    generating 2 random indexes to be selected in array bias
    for(int i=0;i<2;i++)
    {
//        %n leads to random numbers between 1 -> n-1
        randomnumber=rand()%(n+1);
        a[i]=arraybias[randomnumber];
    }
    
    return make_pair(a[0], a[1]);
}


int main()
{
    int arr[]={1,2,3,4,5};
//    sum of all bias should be 1 (as bias contains probability
    
    double bias[]={0.1, 0.2, 0.3, 0.2, 0.2};
    int n=5;
    generateselective(arr, bias, n);
    
    /*
    for(auto x: arraybias)
        cout<<x<<" ";
    cout<<endl;
    */
    
//    change value of z to change how many pairs you require
    int z=10;
    pair<int,int> zeta;
//
    while(z--)
    {
//        zeta contains the randomly generated pair
        zeta=generatepair(n);
        cout<<zeta.first<<" "<<zeta.second<<endl;
    }
    
    return 0;
}

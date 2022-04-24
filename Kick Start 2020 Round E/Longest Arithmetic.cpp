#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long t;
    cin>>t;
    vector<long long> ans;
    while(t--){
        long long i,n,tmp;
        vector<long long> arr,diff;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>tmp;
            arr.push_back(tmp);
            if(i!=0)
                diff.push_back(arr[i]-arr[i-1]);
        }
        long long count=1,freq=diff[0],bestcount=1,mostfreq=diff[0];
        for(i=1;i<n-1;i++){
            if(diff[i]==freq)
                count++;
            else {
                if(count>bestcount)
                bestcount=count;
                //mostfreq=freq;
                freq=diff[i];
                count=1;
            }
        }
        if(count>bestcount)
        bestcount=count;
        ans.push_back(bestcount+1);
        diff.clear();
        arr.clear();
    }
    for(long long j=0;j<ans.size();j++){
        cout<<"Case #"<<j+1<<": "<<ans[j]<<endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i,n,s,flag=0;
    cout<<"Enter size of array: ";
    cin>>n;
    int *a = new int[n];
    cout<<"Enter elements:"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter element to search: ";
    cin>>s;
    int no=sizeof(a)/sizeof(a[0]);
    sort(a,a+no);
    int li=0,ui=n-1,mid;
    while(li<=ui){
        mid=li+(ui-1)/2;
        if(a[mid]==s){
            flag=1;break;
        }
        else if(a[mid]>s){
            ui=mid-1;
        }
        else
            li=mid+1;
        cout<<".";
    }
    if(!flag)
        cout<<"element not found"<<endl;
    else
        cout<<s<<" was found at "<<mid+1<<"of sorted array"<<endl;
    return 0;
}

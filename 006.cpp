#include<bits/stdc++.h>
using namespace std;
signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    const int n=s.length();
    auto getlen=[&](int l,int r){               //以l和r為中心點(l和r可以一樣，如第15行)
        while (l>=0 and r<n and s[l]==s[r]){    //當相對應的字元相同就繼續往兩邊擴展
            l--;                                //l:向左的指針
            r++;                                //r:向右的指針
        }
        return r-l-1;                           //原本是r-l+1-2
    };
    int len = 0;                                //len:最佳長度
    int start = 0;                              //start:起始點
    for (int i=0;i<n;i++){
        int cur=max(getlen(i,i),getlen(i,i+1)); //getLen(i,i)是奇數,getLen(i,i+1)是偶數
        if (cur>len){
           len=cur;                             //比當前的最優解還要長就更新最優解
            start=i-(len-1)/2;                  //len-1:因為偶數情況下length是2，起始點其實還是i
        }
    }
	cout<<len<<endl;
	cout<<start+1<<" "<<start+len<<endl;
}

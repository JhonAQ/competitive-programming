
#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMaxSubSums(const vector<long long>& v) {
    long long s=0, mn=0, mx=0, prefmn=0, prefmx=0;
    for (auto x: v) {
        s+=x;
        mx=max(mx,s-prefmn);
        mn=min(mn,s-prefmx);
        prefmn=min(prefmn,s);
        prefmx=max(prefmx,s);
    }
    return {mn,mx};
}

pair<long long,long long> getMinMaxEnd(const vector<long long>& v) {
    long long s=0, curmin=0, curmax=0;
    for (auto x: v) s+=x;
    long long mn=s, mx=s, pre=0, mnpre=0, mxpre=0;
    for (int i=0;i<(int)v.size();i++){
        pre+=v[i];
        mx=max(mx,s-(pre-mnpre));
        mn=min(mn,s-(pre-mxpre));
        mnpre=min(mnpre,pre);
        mxpre=max(mxpre,pre);
    }
    return {mn,mx};
}

pair<long long,long long> getMinMaxStart(const vector<long long>& v) {
    long long s=0, pre=0, mn=0, mx=0, mnpre=0, mxpre=0;
    for (auto x: v) s+=x;
    long long ansmn=s, ansmx=s;
    for (int i=(int)v.size()-1;i>=0;i--){
        pre+=v[i];
        mx=max(mx,pre-mnpre);
        mn=min(mn,pre-mxpre);
        mnpre=min(mnpre,pre);
        mxpre=max(mxpre,pre);
    }
    ansmn=mn; ansmx=mx;
    return {ansmn,ansmx};
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++) cin>>a[i];
        int cnt=0,pos=-1; 
        for (int i=0;i<n;i++){
            if (a[i]!=1 && a[i]!=-1){
                cnt++; pos=i;
            }
        }
        if (cnt==0){
            auto r=getMinMaxSubSums(a);
            long long L=r.first, R=r.second;
            set<long long> st;
            for(long long x=L;x<=R;x++) st.insert(x);
            st.insert(0);

            cout<<st.size()<<endl;

            for(auto &x: st) cout<<x<<" ";
            cout<<endl;
        } else {
            long long x=a[pos];
            vector<long long> left(a.begin(),a.begin()+pos), right(a.begin()+pos+1,a.end());
            auto Lr=getMinMaxSubSums(left);
            auto Rr=getMinMaxSubSums(right);
            auto Lend=getMinMaxEnd(left);
            auto Rstart=getMinMaxStart(right);
            set<long long> st;
            for(long long v=Lr.first;v<=Lr.second;v++) st.insert(v);
            for(long long v=Rr.first;v<=Rr.second;v++) st.insert(v);
            for(long long Lm=Lend.first; Lm<=Lend.second; Lm++){
                for(long long Rm=Rstart.first; Rm<=Rstart.second; Rm++){
                    st.insert(Lm+x+Rm);
                }
            }
            st.insert(0);
            vector<long long> ans(st.begin(),st.end());
            cout<<ans.size()<<endl;
            for (auto &val: ans) cout<<val<<" ";
            cout<<endl;
        }
    }
}

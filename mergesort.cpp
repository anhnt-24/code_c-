#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int r){
	vector<int> x={a+l,a+(l+r)/2+1};
	vector<int> y={a+(l+r)/2+1,a+r+1};
	int i=0,j=0,idx=l;
	while(i<x.size() && j< y.size()){
		if(x[i]<=y[j]){
			a[idx]=x[i];
			i++;idx++;
		}else{
			a[idx]=y[j];
			j++;idx++;
		}
	}
	while(i<x.size()){
		a[idx]=x[i];
		idx++;
		i++;
	}
	while(j<y.size()){
		a[idx]=y[j];
		j++;
		idx++;
	}
}
void MergeSort(int a[], int l,int r){
	if(r<=l){
		return;
	}
	int m=(l+r)/2;
	MergeSort(a,l,m);
	MergeSort(a,m+1,r);
	merge(a,l,r);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a[n];
		vector<int> v;
		bool ex[10];
		memset(ex,0,sizeof(ex));
		for(auto &x:a) cin >> x;
		for(auto x:a){
			for(int i=0;i<x.size();i++){
				if(!ex[x[i]-'0']){
					v.push_back(x[i]-'0');
					ex[x[i]-'0']=1;
				}
			}
		}
		int c[v.size()];
		for(int i=0;i<v.size();i++){
			c[i]=v[i];
		}
		MergeSort(c,0,v.size()-1);
		for(auto x:c) cout << x << " ";
		cout << endl;	
	}
}
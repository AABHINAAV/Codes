//generates all test files from 0.in to 7.in
#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx = 1024;
const int mxw = 50;
struct testCase{
  int B;
  vector<vector<int> > A;
  vector<int>C, D, W;
};

vector<testCase>all;

//integer to string
string itos(int v){
  if(v == 0) return "0"; 
  string ans = "";
  for(; v != 0; v/=10) ans = string(1, '0' + (v % 10)) + ans;
  return ans;
}

//print all test cases 
void printAll(){
  int tc = 0;
  for(auto tst : all){
    string fname = itos(tc) + ".in";
    auto fl = freopen(fname.c_str(),"w",stdout);
    int n = tst.A.size();
    int b = tst.B;

    printf("%d %d\n", n, b);

    for(int i = 0; i < n; i++){
      if(i!=0)printf(" ");
      printf("%d", tst.C[i]);
    }
    puts("");

    for(int i = 0; i < n; i++){
      if(i!=0)printf(" ");
      printf("%d", tst.D[i]);
    }
    puts("");

    for(int i = 0; i < b; i++){
      if(i!=0)printf(" ");
      printf("%d", tst.W[i]);
    }
    puts("");

    for(int i = 0; i < n; i++){
      int m = tst.A[i].size();
      printf("%d",m);
      for(int j = 0; j < m; j++){
        printf(" %d", tst.A[i][j] + 1);
      }      
      puts("");
    }
    fclose(fl);
    tc++;
  }
}
int main(){
  srand(time(NULL)); //the seed is different in the official test files
  for(int n : {16, 32, 64, 128}){
    for(int s = 0; s < 2; s++){
      vector<int> p (mx, 0);
      iota(p.begin(), p.end(), 0);
      random_shuffle(p.begin(), p.end());
      testCase t;
      t.A.resize(n);
      t.B = mx;
      t.C.resize(mx);
      t.D.resize(mx);
      t.W.resize(mx);
      for(int i=0;i<mx;i++){
        t.C[i] = rand() % mxw + 1;
        t.D[i] = rand() % mxw + 1;
        t.W[i] = rand() % mxw + 1;
      }
      random_shuffle(p.begin(),p.end());
      for(int x : p){
        int i = rand() % n;
        //first generation scheme: all elements to the first sequence
        if(s == 0) i = 0;
        t.A[i].push_back(x);
      }
      all.push_back(t);
    }
  }
  printAll();
  return 0;
}

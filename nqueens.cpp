#include <iostream>
#include <vector>
using namespace std;

bool check (vector <vector<int> > &a, int red, int kolona, int n) {
    for (int i=0; i <red; i++)
        if (a[i][kolona]==1) return false;
    for (int i=red, j=kolona; i>=0 && j>=0; i--, j--)
        if (a[i][j]==1) return false;
    for (int i=red, j=kolona; i>=0 && j<n; i--, j++)
        if (a[i][j]==1) return false;
    return true;
}
void solve (vector <vector<int> > &a, int red, int n, int &br) {
    if (red==n) {
        br++;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for (int kolona=0 ; kolona<n; kolona++) {
        if (check(a,red,kolona,n)==true) {
            a[red][kolona]=1;
            solve(a,red+1,n,br);
            a[red][kolona]=0;
        }
    }
}

int main() {
    int n,broj=0;
    cin>>n;
    vector<vector<int> > a(n, vector<int>(n,0));
    solve(a,0,n,broj);
    cout<<broj;
    
}
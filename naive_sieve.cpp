#include<bits/stdc++.h>
using namespace std;

int n, p = 2;

void sieve(int N){
    vector<char> check(n+1, 1);

    long long count = 0;

    for(int i=2; i*i<=n; i++){
        if(check[i] == 1){
            p = i;
        }
        else{
            check[i] = 0;
            continue;
        }

        for(int j=p; p*j<=n; j++){
            check[p*j] = 0;
        }
    }

    bool first = true;
    for(int i=2; i<=n; i++){
        if(check[i] == 1) {
            /*if(!first) cout << " ";
            cout << i;
            first = false;*/

            count++;
        }
    }

    cerr << "prime count: " << count << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    auto start = chrono::high_resolution_clock::now();
    sieve(n);
    auto end = chrono::high_resolution_clock::now();

    cerr << chrono::duration_cast<chrono::milliseconds>
        (end - start).count() << "ms\n";
}

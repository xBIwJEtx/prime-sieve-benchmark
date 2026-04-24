#include <bits/stdc++.h>
using namespace std;

long long n, p = 2;

void segment_sieve(long long N){
    int sqrtN = sqrt(N);
    long long count = 1;

    vector<char> check(sqrtN + 1, 1);
    check[0] = check[1] = 0;
    vector<long long> prime;

    for(int i = 2; (long long)i*i <= sqrtN; i++){
        if(check[i] == 0){
            continue;
        }

        for(int j = i * i; j <= sqrtN; j += i){
            check[j] = 0;
        }
    }

    for(int i = 2; i <= sqrtN; i++){
        if(check[i] == 1){
            prime.push_back(i);
        }
    }

    //cout << 2 << " ";

    const int seg_size = 1 << 14;
    vector<char> seg(seg_size);

    for(long long Low = 3; Low <= N; Low += 2 * seg_size){
        long long High = min(Low + 2 * seg_size - 1, N);

        fill(seg.begin(), seg.end(), 1);

        for(long long p : prime){

            if(p == 2) {
                continue;
            }

            long long start = max(1LL * p * p, (Low + p - 1) / p * p);

            if(start % 2 == 0) start += p;

            for(long long j = start; j <= High; j += p * 2){
                seg[(j - Low) / 2] = 0;
            }
        }

        bool first = true;
        for(long long i = Low; i <= High; i += 2){
            if(seg[(i - Low) / 2] == 1){ 
                /*if(!first) cout << " ";
                cout << i;
                first = false;*/

                count++;
            }
        }
    }

    cerr << "prime count: " << count << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    auto start = chrono::high_resolution_clock::now();
    segment_sieve(n);
    auto end = chrono::high_resolution_clock::now();

    cerr << chrono::duration_cast<chrono::milliseconds>
        (end - start).count() << "ms\n";
}

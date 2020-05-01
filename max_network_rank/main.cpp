#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;


int solution(const vector<int>&A, const vector<int>&B, int N){
    vector<int> mymap(N+1,0);
    for(int i = 0 ; i < A.size() ; i++){
        mymap[A[i]]++;
        mymap[B[i]]++;
    }
    int res = INT_MIN;
    for(int i = 0 ; i < A.size() ; i++)
        res = max(res,mymap[A[i]]+mymap[B[i]]-1);
    return res;
}


/*
int solution(const vector<int>&A, const vector<int>&B, int N) {
    int maxRank = 0;
    int edgesLen = A.size();

//    int[] edgesCount = new int[N + 1];
    vector<int> edgesCount(N + 1, 0);

    for(int i=0; i<edgesLen; i++){
        edgesCount[A[i]] += 1;
        edgesCount[B[i]] += 1;
    }

    for(int i=0; i<edgesLen; i++){
        int localMax = edgesCount[A[i]] + edgesCount[B[i]] - 1;
        maxRank = max(maxRank, localMax);
    }

    return maxRank;
}
*/


int main() {

    cout << "Result: " << solution({1, 2, 3, 3},{2, 3, 1, 4}, 4) << " expected: 4" << endl;

    return 0;
}


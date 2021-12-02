## unoredered_map 을 이용한 가장 많이 출현하는 숫자 찾기
<pre>
int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
int n = sizeof(arr) / sizeof(arr[0]);
int k = 2;

// <숫자, 출현횟수>
unordered_map<int, int> um;
for(int i=0; i<n; i++) {
   um[arr[i]]++;
}

vector<pair<int,int>> freq_arr(um.begin(), um.end());
sort(freq_arr.begin(), freq_arr.end(), 
     [](pair<int,int> &p1, pair<int,int> &p2){ 
        if(p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
     });
     
for (int i = 0; i < k; i++)
        cout << freq_arr[i].first << " ";
</pre>

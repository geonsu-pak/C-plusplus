## sort
    std::vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    std::sort(v.begin(), v.end());
    // 내림차순
    sort(v.begin(), v.end(), greater<int>());   
    // = 
    sort(v.begin(), v.end(), [](const int& a, const int&b) { return a > b; });
## Loop
std::vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
### 1
<pre>
for(size_t i=0; i < v.size(); i++)
    std::cout << v[i] << std::endl;
</pre>
### 2
<pre>
for(aut &item : v)
    std::cout << item << std::endl;
</pre>
### 3
<pre>
std::for_each(
              v.begin(), 
              v.end(), 
              [](auto &item) { std::cout << item << std::endl; }
              );
</pre>

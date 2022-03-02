## 2d int array
<pre>
constexpr int LENGTH = 4;
constexpr int WIDTH = 4;

std::vector < std::vector < int > > vector_2d(LENGTH, std::vector < int > (WIDTH, 0));
vector_2d[2][2] = 10;
</pre>
## sum
<pre>
vector<int> arr1 = { 1, 12, 13, 10, 11 };

int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
</pre>
## copy
vector<int> vec1 = { 23, 43, 324, 222, 649, 102, 40, 304};
### 1. std::copy
<pre>
vector<int> vec1_c(vec1.size());
std::copy(vec1.begin(), vec1.end(), vec1_c.begin());
</pre>
### 2
<pre>vector<int> vec1_c = vec1;</pre>
### 3
<pre>vector<int> vec1_c(vec1);</pre>
### 4 std::vector::assign
<pre>
vector<int> vec1_c;
vec1_c.assign(vec1.begin(), vec1.end());
</pre>
## sort
    std::vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    std::sort(v.begin(), v.end());
    // 내림차순
    sort(v.begin(), v.end(), greater<int>());   
    // = 
    sort(v.begin(), v.end(), [](const int& a, const int&b) { return a > b; });
## Unique & remove duplicates
vector<int> int_vec = {10, 23, 10, 324, 10, 10, 424, 649, 110, 110, 129, 40, 424};        
### 1. std::vector::erase
<pre>
std::sort(int_vec.begin(), int_vec.end());    
auto last = std::unique(int_vec.begin(), int_vec.end()); 

int_vec.erase(last, int_vec.end());
</pre>
### 2. std::vector::resize
<pre>
std::sort(int_vec.begin(), int_vec.end());    
auto last = std::unique(int_vec.begin(), int_vec.end()); 

int_vec.resize(std::distance(int_vec.begin(), last));
</pre>
### 3. std::set 
<pre>
set<int> int_set(int_vec.begin(), int_vec.end());
int_vec.assign(int_set.begin(), int_set.end());
</pre>
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
## std::find, std::find_if
<pre>
vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
auto p = std::find(arr.begin(), arr.end(), 10);
if( p != arr.end())
   // position = (p - arr.begin())
auto pp = std::find_if(arr.begin(), arr.end(), [](int x) { return x == 10; });
if( pp != arr.end())
   // position = (pp - arr.begin())
</pre>

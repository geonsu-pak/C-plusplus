# Async
Thread와 비슷하지만 리턴값을 받을 필요가 있을 때 사용.    

    #include <future>
    #include <iostream>

    unsigned int square(unsigned int i){
        return i*i;
    }

    int main() {
        // 쓰레드 생성 ※ std::launch::async 선언해야 반드시 새 쓰레드를 생성한다.
        auto f = std::async(std::launch::async, square, 8);
        // 동시에 다른 작업
        std::cout << "square currently running\n";
        // 쓰레드의 결과값 대기
        std::cout << "result is " << f.get() << '\n';
    }
    
## Lambda
    int main() {
        auto f = std::async(std::launch::async, 
                            [](unsigned int i) { return i*i; });
        std::cout << "result is " << f.get() << '\n';
    }
# for_each c++17 
<pre>
std::vector<std::string> foo;
std::for_each(
    std::execution::par,
    foo.begin(),
    foo.end(),
    [](auto& item) {
        <b>index = &item - &foo[0];</b>
        //do stuff with item
    }
);
</pre>  

#### ExecutionPolicy 
* std::execution::seq : 생략시 디폴트. 순차처리(패러럴 효과없음)
* std::execution::par : 패러럴 처리   
 <pre>
    int sum = 0;    
    std::mutex m;    
    std::for_each(std::execution::par, std::begin(v), std::end(v), [&](int i) {    
                  std::lock_guard<std::mutex> lock{m};    
                  sum += i * i;    
                  });    
</pre>
* std::execution::par_unseq : 패러렐 처리이지만 하나의 쓰레드에서 복수의 함수콜을 할 수 있으므로 동기화에 주의할 필요 있슴 
     std::lock_guard<std::mutex> lock{m}; 은 하나의 쓰레드에서 여러번 생성하므로 에러 발생 -> automic 사용해야 함.    
<pre>     
    std::atomic<int> sum{0};    
    std::for_each(std::execution::par_unseq, std::begin(v), std::end(v), [&](int i) {    
            sum.fetch_add(i*i, std::memory_order_relaxed);
    });
</pre>
     

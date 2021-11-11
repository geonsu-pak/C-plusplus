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
                            [](unsigned int i) { return i*i; }, 8);
        std::cout << "result is " << f.get() << '\n';
    }

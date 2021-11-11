# Thread
## 외부 함수를 이용한 쓰레드
    #include <thread>
    void threadFunction() {
        std::cout << "Func Start" << std::endl;
    }
    
    void main() {
        std::thread th(threadFunction);
        // id
        std::thread::id threadID = th.get_id();
        // wait
        if (th.joinable())
            th.join();
    }

## Lambda 를 이용한 쓰레드
    std::thread th(
                    []() { std::cout << "Func Start" << std::endl; }
                    );
                    
                    
## 파라미터 전달
    #include <thread>
    #include <string>
    
    void threadFunction1(std::string str) {
        std::cout << str << std::endl;
    }
    void threadFunction2(std::string& str) {
        std::cout << str << std::endl;
    }
    
    void main() {
        std::string str = "thread start";
        // 1. 변수 카피를 통한 전달 ※ 복수 파라미터인 경우는 str 이후로 갯수만큼 컴마로 나열
        std::thread th1(threadFunction, str); 
        // 2. 참조
        std::thread th2(threadFunction, std::ref(str));
    }
    
## Lambda 파라미터 전달
    std::string str = "thread start";
    // 외부 참조 액세스
    std::thread th( [&]() { std::cout << str << std::endl; } );    
    // 외부 카피 액세스 ※ str1과 Lambda안의 str1은 다른 메모리 번지를 가짐
    std::thread th( [=]() { std::cout << str << std::endl; } );
    // 참조 파라미터
    std::thread th( [](str::string str) { std::cout << str << std::endl; }, std::ref(str) );
    // 카피 파라미터
    std::thread th( [](std::string str) { std::cout << str << std::endl; }, str ); 
   
## 클래스 쓰레드
    class Task
    {
       public:
          void execute(std::string str) { std::cout << str << std::endl; }
          void do();
    }:
    // 1. 동일 클래스내
    void Task::do() 
    {
        std::string str = "start thread";
        // execute 를 쓰레드 처리
        // &클래스::멤버함수, this(클래스 포인터), 파라미터(참조형인 경우는 std::ref(...))
        std::thread th(&Thread::execute, this, str);
    }
    // 2. 타 클래스내
    void OtherClass::work()
    {
       Task* task = new Task();
       std::thread th(&Task::execute, task, "start thread");
       // 로컬선언 클래스
       Task task2;
       std::thread th2(&Task::execute, &task2, "start thread"):
    }

## 쓰레드 풀 (Thread Pool)
### 복수의 작업을 코아수 쓰레드 단위를 이용하여 처리 
    #include <iostream>
    #include <mutex>
    #include <thread>
    #include <vector>

    int main()
    {
        // 동시 실행할 쓰레드 갯수 = 코어수
        unsigned int nthreads = std::thread::hardware_concurrency();
        if (nthreads == 0) nthreads = 4;
        
        // 만일 쓰레드내 동기화 필요가 있을 경우
        std::mutex m;
        // 총처리 쓰레드 수
        const int n = 25;

        int i = 0;
        while(i<n) {
            std::cout << i << std::endl;
            std::vector<std::thread> workers;
        
            for (int k = 0; k < nthreads; ++k) {
                int current = i + k;
                if (current < n) {
                                workers.push_back(
                                    std::thread([&](int index) {  // & => 외부 m 참조용, index => current
                                              std::lock_guard<std::mutex> lock(m); // 쓰레드간 락
                                              std::cout << "thread-" << index << std::endl; }, current )
                                );
                } // if
            } // for
            // nthreads 개의 쓰레드의 종료 대기
            for (auto& worker : workers) {
                worker.join();
            }

            i += nthreads;
        }

        return 0;
    }

#### 결과
    0
    thread-0
    thread-5
    thread-3
    thread-6
    thread-1
    thread-4
    thread-7
    thread-2
    8
    thread-8
    thread-11
    thread-14
    thread-9
    thread-12
    thread-13
    thread-10
    thread-15
    16
    thread-16
    thread-20
    thread-23
    thread-19
    thread-17
    thread-21
    thread-22
    thread-18
    24
    thread-24

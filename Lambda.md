# C++ Lambda
함수 안에서 다른 함수를 사용하려면 사용할 함수를 밖에 정의할 필요가 있지만 Lambda는 이런 번거러움을 제거해 줌    
주로 파라미터로 함수 포인터를 사용하는 함수에서 사용    

i.g. std::find_if(...) std::sort(...)

    []() { return ; }
    
* [] : Capture List
  * [] 없음
  *  \[ x\]  특정 외부 변수 x 를 카피해서 사용
  * [&x] 참조해서 사용(함수 안에서 값이 변경 될 수 있음)
  * [&] 모든 외부 변수를 참조해서 사용
  * [=] 모든 외부 변수를 카피해서
* () : Argument List
* {} : Function Body
* return    

### Sample
    std::sort(v.begin(), v.end(), [](const int& a, const int& b) 
    {    
        return a > b;    
    });    

#include <chrono>
   
using clock = std::chrono::system_clock;
using ms = std::chrono::duration<double, std::milli>;

const auto before = clock::now();
  
const ms duration = clock::now() - before;
std::cout << "It took " << duration.count() << "ms" << std::endl;
  

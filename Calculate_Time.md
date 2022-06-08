<pre>
#include < chrono >
   
auto start = std::chrono::high_resolution_clock::now();
// working hard
auto end = std::chrono::high_resolution_clock::now();

std::chrono::duration< double, std::milli > float_ms = end - start;
std::cout << "funcSleep() elapsed time is " << float_ms.count() << " milliseconds" << std::endl;
</pre>

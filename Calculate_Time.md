<pre>
#include < chrono >

using clock = std::chrono::system_clock;
using sec = std::chrono::duration<double>;

const auto before = clock::now();
// Time consuming work
const sec duration = clock::now() - before;
std::cout << "It took " << duration.count() << "s" << std::endl;
</pre>

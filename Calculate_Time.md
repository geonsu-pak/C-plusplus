<pre>
#include < chrono >

    auto start = chrono::steady_clock::now();
 
    // do some stuff here
    sleep(3);
    
    auto end = std::chrono::steady_clock::now();
 
    cout << "Elapsed time in nanoseconds: "
        << std::chrono::duration_cast< std::chrono::nanoseconds >(end - start).count()
        << " ns" << endl;
 
    cout << "Elapsed time in microseconds: "
        << std::chrono::duration_cast< std::chrono::microseconds >(end - start).count()
        << " µs" << endl;
 
    cout << "Elapsed time in milliseconds: "
        << std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count()
        << " ms" << endl;
 
    cout << "Elapsed time in seconds: "
        << std::chrono::duration_cast< std::chrono::seconds >(end - start).count()
        << " sec";
</pre>

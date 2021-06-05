
std::vector<int> numbers {3,1,2,5,4};

// sort ascending
std::sort(numbers.begin(), numbers.end());

// sort descending
std::sort(
          numbers.begin(), 
          numbers.end(),
          [](int a, int b){ return a > b; } // lambda
          );

// display values
for_each(
          numbers.begin(), 
          numbers.end(),
          [](auto &element) { std::cout << element << " ";} // lambda
        );

## sort
    std::vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    std::sort(v.begin(), v.end());
    // 내림차순
    sort(v.begin(), v.end(), greater<int>());   

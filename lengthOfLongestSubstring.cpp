int lengthOfLongestSubstring(string s) {
    std::unordered_set<char> characters;
    int length{0};
    int longest{0};

    for (const auto& character : s)
    {
        if (characters.count(character))
        {
            if (length > longest)
                longest = length;
            length = 1;
            characters.clear();
            characters.insert(character);
        }
        else
        {
            ++length;
            characters.insert(character);
        }
    }
        // if the longest unique substring is the last one
        // update length
    if (length > longest)
        longest = length;
        //go in reverse
    length = 0;
    characters.clear();
    
    std::for_each(std::rbegin(s), std::rend(s), [&length, &longest, &characters](const auto& character)
    {
      if (characters.count(character))
      {
        if (length > longest)
            longest = length;
        length = 1;
        characters.clear();
        characters.insert(character);
    }
    else
    {
        ++length;
        characters.insert(character);
    }
    });
    // once again account for last substr
    // being longest
    return length > longest ? length : longest;
}
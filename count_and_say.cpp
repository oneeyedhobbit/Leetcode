string countAndSay(int n) {
    if (n < 1)
        return "";
    std::string response;
    if (n == 1)
        return "1";
    else
        response = countAndSay(n - 1);
    char character = response[0];
    int pos = 1;
    int count = 1;
    std::string answer;
    while (pos < response.size())
    {
        if (response[pos] == character)
            ++count;
        else
        {
            answer += std::to_string(count);
            answer += character;
            character = response[pos];
            count = 1;
        }
        ++pos;
    }
    answer += std::to_string(count);
    answer += character;
    return answer;
}
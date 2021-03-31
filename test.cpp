#include <assert.h>
#include "json_flatten.h"

void check(string input, string output)
{
    json data = json::parse(input);
    // cout<<"input: \n"<<data.dump(4)<<endl;
    recurse<json>(data, "");
    assert(result == json::parse(output));
    // cout<<"output: \n"<<result.dump(4)<<endl;
}
int main()
{
    string input = "{\"a\": 1,\"b\": true,\"c\": {\"d\": 3, \"e\": \"test\"}}";
    string output = "{\"a\":1,\"b\":true,\"c.d\":3,\"c.e\":\"test\"}";
    check(input, output);

    result = {};
    input = "{\"a\": 1,\"b\": true,\"c\": {\"d\": 3, \"e\": \"test\",\"f\": {\"g\": \"chala\"}}}";
    output = "{\"a\":1,\"b\":true,\"c.d\":3,\"c.e\":\"test\",\"c.f.g\":\"chala\"}";
    check(input, output);

    result = {};
    input = "{\"a\": 1,\"b\": true,\"c\": {\"d\": 3, \"e\": \"test\",\"f\": {\"g\": 3.6}}}";
    output = "{\"a\":1,\"b\":true,\"c.d\":3,\"c.e\":\"test\",\"c.f.g\":3.6}";
    check(input, output);

    result = {};
    input = "{\"a\": {\"d\": 3, \"e\": \"test\",\"f\": {\"g\": 6.7}}}";
    output = "{\"a.d\":3,\"a.e\":\"test\",\"a.f.g\":6.7}";
    check(input, output);

    result = {};
    input = "{\"a\": {\"d\": 3, \"e\": \"test\",\"f\": {\"g\": 6.7}},\"c\": 1,\"b\": true}";
    output = "{\"a.d\":3,\"a.e\":\"test\",\"a.f.g\":6.7,\"c\":1,\"b\":true}";
    check(input, output);

    result = {};
    input = "{\"a\": true}";
    output = "{\"a\": true}";
    check(input, output);

    cout << "All test cases passed!\n";
}

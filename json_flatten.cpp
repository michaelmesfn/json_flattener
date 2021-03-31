#include <iostream>
#include "json_flatten.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
//for nlohmann 3.9 and higher use:
//using json = nlohmann::ordered_json;
int main()
{
    string input;
    char buf;
    while ((buf = getc(stdin)) != EOF)
    {
        input += buf;
    }
    json data = json::parse(input);
    recurse<json>(data, "");
    cout << result.dump(4) << endl;
    return 0;
}

#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
//for nlohmann 3.9 and higher use:
//using json = nlohmann::ordered_json;
using namespace std;

json result;

template <class T>
void recurse(T cur, string prop)
{
    if (cur.type() != json::value_t::object)
    {
        result[prop] = cur;
    }
    else
    {
        bool isEmpty = true;
        for (auto &p : cur.items())
        {
            isEmpty = false;
            recurse<json>(cur[p.key()], !prop.empty() ? prop + "." + p.key() : p.key());
            if (isEmpty == true && !prop.empty())
            {
                result[prop] = {};
            }
        }
    }
}
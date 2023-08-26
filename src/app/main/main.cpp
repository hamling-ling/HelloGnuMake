#include <iostream>

#include <jansson.h>

using namespace std;

int main(const int argc, const char** argv)
{
    cout << "Hello World!" << endl;

    json_error_t error;
    string text = "{\"name\":\"Jansson\"}";
    json_t *root = json_loads(text.c_str(), text.length(), &error);
    json_t *nameObj = json_object_get(root, "name");
    const char* message_text = json_string_value(nameObj);
    cout << message_text << endl;

    json_decref(root);

    return 0;
}

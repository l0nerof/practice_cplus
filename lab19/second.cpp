#include <iostream>
#include <map>
#include <string>
using namespace std;

string trim(const string &text) {
    size_t start = 0;
    while (start < text.length() && text[start] == ' ') {
        ++start;
    }

    size_t end = text.length();
    while (end > start && text[end - 1] == ' ') {
        --end;
    }

    return text.substr(start, end - start);
}

int main() {
    string valuesLine;
    getline(cin, valuesLine);

    string messageTemplate;
    getline(cin, messageTemplate);

    map<string, string> values;
    size_t start = 0;

    while (start <= valuesLine.length()) {
        size_t commaPos = valuesLine.find(',', start);
        string pairText;

        if (commaPos == string::npos) {
            pairText = valuesLine.substr(start);
            start = valuesLine.length() + 1;
        } else {
            pairText = valuesLine.substr(start, commaPos - start);
            start = commaPos + 1;
        }

        pairText = trim(pairText);
        if (pairText.empty()) {
            continue;
        }

        size_t equalPos = pairText.find('=');
        if (equalPos == string::npos) {
            continue;
        }

        string name = trim(pairText.substr(0, equalPos));
        string value = trim(pairText.substr(equalPos + 1));
        values[name] = value;
    }

    string result;

    for (size_t i = 0; i < messageTemplate.length(); ) {
        if (messageTemplate[i] == '[') {
            size_t closePos = messageTemplate.find(']', i);

            if (closePos != string::npos) {
                string key = messageTemplate.substr(i + 1, closePos - i - 1);
                map<string, string>::iterator found = values.find(key);

                if (found != values.end()) {
                    result += found->second;
                } else {
                    result += messageTemplate.substr(i, closePos - i + 1);
                }

                i = closePos + 1;
                continue;
            }
        }

        result += messageTemplate[i];
        ++i;
    }

    cout << result << endl;
    return 0;
}

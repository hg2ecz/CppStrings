#include <string>
#include <iostream>

#include <locale>
#include <codecvt>

using namespace std;

template<typename CharType = char>
class MyClassT {
    public:
        basic_string<CharType> name;

        static basic_string<CharType> from_string(string s) {
            return std::wstring_convert<std::codecvt_utf8_utf16<CharType>, CharType>{}.from_bytes(s);
        }

        static std::string to_string(basic_string<CharType> s) {
            return std::wstring_convert<std::codecvt_utf8_utf16<char>, char>{}.to_bytes(s);
        }
};

typedef MyClassT<> MyClassS;

int main()
{
    auto g = MyClassS { "My name" };
    auto h = MyClassT<wchar_t> {};

    auto s = string { "Salve, Munde, éé áá őő űű" };

    cout << "From UTF-8 const char*: ";

    for (auto ch: h.from_string("őőűű")) {
        cout << ch << " " << flush;
    }

    cout << endl << "From std::string: ";

    for (auto ch: h.from_string(s)) {
        cout << ch << " " << flush;
    }

    cout << endl;
}
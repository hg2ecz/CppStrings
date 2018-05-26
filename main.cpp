#include <string>
#include <iostream>

#include <locale>
#include <codecvt>

using namespace std;

namespace string_converter {
    template <typename CharType>
    basic_string<CharType> from_string(string s) {
        return std::wstring_convert<std::codecvt_utf8_utf16<CharType>, CharType>{}.from_bytes(s);
    }

    template <typename CharType>
    static std::string to_string(basic_string<CharType> s) {
        return std::wstring_convert<std::codecvt_utf8_utf16<CharType>, CharType>{}.to_bytes(s);
    }
}

template<typename CharType = char>
class MyClassGeneric {
    public:
        basic_string<CharType> name;
};

typedef MyClassGeneric<> MyClassDefault;

int main()
{
    auto class_utf8 = MyClassDefault { "My name" };
    auto class_ucs4 = MyClassGeneric<char32_t> { U"Salve, Munde, őőő űűű" };

    auto utf8_string = string { "Salve, Munde, éé áá őő űű" };

    cout << "UTF-8 string: " << utf8_string << endl;
    cout << "UTF-8 as const char*: ";

    for (auto ch: utf8_string) {
        cout << ch << " " << flush;
    }

    cout << endl << "UCS2 string from std::string: ";

    auto ucs2_string = string_converter::from_string<char16_t>(utf8_string);

    for (auto ch: ucs2_string) {
        cout << ch << " " << flush;
    }

    cout << endl;

    cout << "UTF-8 length: " << utf8_string.length() << ", UCS2 length: " << ucs2_string.length() << endl;
    cout << "Verificarion: UTF-8: " << string_converter::to_string<char16_t>(ucs2_string) << endl;
}
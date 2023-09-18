//
// Created by jonel on 9/19/2023.
//
#include <cstring>
#ifndef CPP_ISTRING_H
#define CPP_ISTRING_H

namespace istr {

    class istring {
    private:
        char *str;
    public:
        istring();
        istring(const char *s){
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        };
        bool operator=(const char *s){
            delete[] str;
            str = new char[strlen(s) + 1];
            strcpy(str, s);
            if(str[0] == '\0'){
                return true;
            }
            return false;
        };
        friend std::ostream &operator<<(std::ostream &os, const istring &s){
            os << s.str;
            return os;
        };
        friend std::istream &operator>>(std::istream &is, istring &s){
            is >> s.str;
            return is;
        }
        ~istring(){
            delete[] str;
        };
    };

} // istr

#endif //CPP_ISTRING_H

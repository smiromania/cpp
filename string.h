//
// Created by jonel on 9/19/2023.
//
#include <cstdint>
#include <cstring>
#ifndef CPP_ISTRING_H
#define CPP_ISTRING_H

namespace ion {

    class string {
    private:
        char *str;
    public:
        string();
        string(const char *s){
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
        friend std::ostream &operator<<(std::ostream &os, const string &s){
            os << s.str;
            return os;
        };
        friend std::istream &operator>>(std::istream &is, string &s){
            is >> s.str;
            return is;
        }
        bool operator==(const char *s){
            return strcmp(str, s) == 0;
        }
        bool operator!=(const char *s){
            return strcmp(str, s) != 0;
        }
        bool operator<(const char *s){
            return strcmp(str, s) < 0;
        }
        bool operator>(const char *s){
            return strcmp(str, s) > 0;
        }
        uint64_t length(){
            return strlen(str);
        }
        ~string(){
            delete[] str;
        };
    };

} // istr

#endif //CPP_ISTRING_H

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
    template <typename T>
    T abs(T x){
        if(x < 0){
            return -x;
        }
        return x;
    }
    template <typename T>
    class vector{
    private:
        T *data;
        uint64_t sizeOf;
        uint64_t capacityOf;
    public:
        vector(){
            data = nullptr;
            sizeOf = 0;
            capacityOf = 0;
        };
        vector(const vector &other){
            data = new T[other.capacityOf];
            sizeOf = other.sizeOf;
            capacityOf = other.capacityOf;
            for(uint64_t i = 0; i < sizeOf; i++){
                data[i] = other.data[i];
            }
        };
        vector &operator=(const vector &other){
            if(this == &other){
                return *this;
            }
            delete[] data;
            data = new T[other.capacityOf];
            sizeOf = other.sizeOf;
            capacityOf = other.capacityOf;
            for(uint64_t i = 0; i < sizeOf; i++){
                data[i] = other.data[i];
            }
            return *this;

        };
        T &operator[](uint64_t index){
            return data[index];
        };
        ~vector(){
            delete[] data;
        };
        uint64_t size(){
            return sizeOf;
        }
        uint64_t capacity(){
            return capacityOf;
        }
        void push_back(T value){
            if(sizeOf == capacityOf){
                capacityOf *= 2;
                T *temp = new T[capacityOf];
                for(uint64_t i = 0; i < sizeOf; i++){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
            }
            data[sizeOf] = value;
            sizeOf++;
        }

    };


} // istr

#endif //CPP_ISTRING_H

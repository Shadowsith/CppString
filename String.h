#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>

namespace str {
class String {

    private:
    std::string _str;
    typedef std::string::iterator iterator;
    typedef std::string::reverse_iterator reverse_iterator;
    typedef std::string::const_iterator const_iterator;
    typedef std::string::const_reverse_iterator const_reverse_iterator;

    const std::string getStdStr(const std::string &s) {
        return s;
    }

    const std::string getStdStr(const char* s) {
        return std::string(s);
    }

    const std::string getStdStr(const String &s) {
        return s._str;
    }

    const std::string getStdStr(const char c) {
        return std::string() += c;
    }

    template <typename T>
    const std::string getStdStr(T t) {
        std::string msg;
        msg = std::string("Type ") + typeid(t).name() + 
            std::string(" for a String method is invalid!");
        throw std::invalid_argument(msg);
    }

    public:
    String() { _str = ""; }
    String(std::string str) { _str = str; }
    String(const char* cstr) { _str = std::string(cstr); }
    String(const String &s) { _str = s._str; }
    String(const char c) { _str = std::string() += c; }
    String(const int i) { _str = std::to_string(i); }
    String(const float f) { _str = std::to_string(f); }
    String(const double d) { _str = std::to_string(d); }
    String(const long l) { _str = std::to_string(l); }
    String(const bool b) { if(b) _str = "true"; else _str = "false"; }
    ~String() {}

    // casts 
    std::string toStdStr() { return _str; }
    const char* toCStr() { return _str.c_str(); }
    int toInt() { return std::stoi(_str); }
    long toLong() { return std::stol(_str); }
    float toFloat() { return std::stof(_str); }
    double toDouble() { return std::stod(_str); }
    bool toBool() {
        if(_str == "false" || _str == "0" || _str == "")
            return false;
        else
            return true;
    }

    std::vector<char> toCharArr() {
        std::vector<char> vec;
        for(char c : _str) {
            vec.push_back(c);
        }
        return vec;
    }

    char charAt(const int pos) { 
        return _str.at(pos); 
    }

    bool isEmpty() { 
        return _str.empty(); 
    }

    bool isEmptyOrWhiteSpace() {
        if(_str.empty()) {
            return true;
        } else {
            if(_str.find_first_not_of(' ') != std::string::npos){
                return false;
            }
            return true;
        }
    }

    String substr(const int pos, const int len) {
        return String(_str.substr(pos, len));
    }

    String addHead(const std::string& str) {
        std::string s = _str;
        s = str + _str;
        return String(s);
    }

    String addHead(const String& str) {
        return addHead(str._str);
    }

    String addHead(const char* str) {
        return addHead(std::string(str));
    }

    String addTail(const std::string& str) {
        std::string s = _str;
        s += str;
        return String(s);
    }

    String addTail(const String& str) {
        return addTail(str._str);
    }

    String addTail(const char* str) {
        return addTail(std::string(str));
    }

    bool compare(const std::string& str) {
        if(_str == str)
            return true;
        else
            return false;
    }

    bool compare(const String& str) {
        return compare(str._str);
    }

    bool compare(const char* str) {
        return compare(std::string(str));
    }

    inline bool equals(const std::string& str) {
        return compare(str);
    }

    inline bool equals(const String& str) {
        return compare(str._str);
    }

    inline bool equals(const char* str) {
        return compare(std::string(str));
    }

    int length() {
        return _str.length();
    }

    inline int size() {
        return this->length();
    }

    void clear() {
        _str.clear();
    }

    char front() {
        return _str.front();
    }

    inline char first() {
        return this->front();
    }

    char back() {
        return _str.back();
    }

    inline char last() {
        return this->back();
    }

    void shrinkToFit() {
        _str.shrink_to_fit();
    }

    size_t maxSize() const noexcept {
        return _str.max_size();
    }

    size_t capacity() const noexcept {
        return _str.capacity();
    }

    void resize(size_t n) {
        _str.resize(n);
    }

    bool contains(const std::string& str) {
        return this->count(str) > 0;
    }

    bool contains(const String& str) {
        return this->count(str) > 0;
    }

    bool contains(const char* str) {
        return this->count(str) > 0;
    }

    String concat(const std::string& str) {
        std::string s = _str;
        s += str;
        return String(s);
    }

    String concat(const String& str) {
        return concat(str._str);
    }

    String concat(const char* str) {
        return concat(std::string(str));
    }

    inline String join(const std::string& str) {
        return concat(str);
    }

    inline String join(const String& str) {
        return concat(str);
    }

    inline String join(const char* str) {
        return concat(str);
    }

    void copyTo(String &s) { s._str = _str; }
    void copyTo(std::string &s) { s = _str; }

    int count(const std::string& str) {
        return this->find(str).size();
    }

    int count(const String& str) {
        return this->find(str._str).size();
    }

    int count(const char* str) {
        return this->find(std::string(str)).size();
    }

    String insert(const int start, const std::string& str) {
        std::string s = _str;
        return String(s.insert(start, str));
    }

    String insert(const int start, const String& str) {
        return insert(start, str._str);
    }

    String insert(const int start, const char* str) {
        return insert(start, std::string(str));
    }
    
    std::vector<int> find(const std::string& str) {
        std::vector<int> vec;
        std::size_t pos = _str.find(str);
        while (pos != std::string::npos) {
            vec.push_back(pos);
            pos = _str.find(str,pos+1);
        }
        return vec;
    }

    std::vector<int> find(const String& str) {
        return find(str._str);
    }

    std::vector<int> find(const char* str) {
        return find(std::string(str));
    }

    inline std::vector<int> findAll(const std::string& str) {
        return find(str);
    }

    inline std::vector<int> findAll(const String& str) {
        return find(str);
    }

    inline std::vector<int> findAll(const char* str) {
        return find(str);
    }

    int findFirst(const std::string& str) {
        std::size_t pos = _str.find(str);
        if (pos != std::string::npos) {
            int i = static_cast<int>(pos);
            return i;
        }
        return 0;
    }

    int findFirst(const String& str) {
        return findFirst(str._str);
    }

    int findFirst(const char* str) {
        return findFirst(std::string(str));
    }

    inline int indexOf(const std::string& str) {
        return findFirst(str);
    }

    inline int indexOf(const String& str) {
        return findFirst(str);
    }

    inline int indexOf(const char* str) {
        return findFirst(str);
    }

    int findLast(const std::string& str) {
        std::size_t pos = _str.rfind(str);
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        } return 0;
    }

    int findLast(const String& str) {
        return findLast(str._str);
    }

    int findLast(const char* c) {
        return findLast(std::string(c));
    }

    inline int lastIndexOf(const std::string& str) {
        return findLast(str);
    }

    inline int lastIndexOf(const String& str) {
        return findLast(str);
    }

    inline int lastIndexOf(const char* str) {
        return findLast(str);
    }

    template<typename T1, typename T2>
    String replace(const T1 old_str, const T2 new_str) {
        std::string s = _str;
        std::string o = getStdStr(old_str);
        std::string n = getStdStr(new_str);
        std::size_t pos = s.find(o);
        while(pos != std::string::npos) {
            s.replace(pos, o.length(), n);
            pos = s.find(o, pos+1);
        }
        return String(s);
    }

    template<typename T1, typename T2>
    String replaceFirst(const T1 old_str, const T2 new_str) {
        std::string s = _str;
        std::string o = getStdStr(old_str);
        std::string n = getStdStr(new_str);
        std::size_t pos = s.find(o);
        if(pos != std::string::npos) {
            s.replace(pos, o.length(), n);
        }
        return String(s);
    }

    template<typename T1, typename T2>
    String replaceLast(const T1 old_str, const T2 new_str) {
        std::string s = _str;
        std::string o = getStdStr(old_str);
        std::string n = getStdStr(new_str);
        std::size_t pos = s.rfind(o);
        if(pos != std::string::npos) {
            s.replace(pos, o.length(), n);
        }
        return String(s);
    }

    String replaceHead(const int headsize, const std::string& new_str){
        std::string s = _str;
        s.erase(0,headsize);
        s = new_str + s;
        return String(s);
    }

    String replaceHead(const int headsize, const String& new_str) {
        return replaceHead(headsize, new_str._str);
    }

    String replaceHead(const int headsize, const char* c) {
        return replaceHead(headsize, std::string(c));
    }

    String replaceTail(const int tailsize, const std::string& new_str) {
        std::string s = _str;
        s.erase(_str.end()-tailsize, s.end());
        s += new_str;
        return String(s);
    }

    String replaceTail(const int tailsize, const String& new_str) {
        return replaceTail(tailsize, new_str._str);
    }

    String replaceTail(const int tailsize, const char* c) {
        return replaceTail(tailsize, std::string(c));
    }

    String erase(const std::string& erase_str) {
        std::string str = _str;
        const std::string s = erase_str;
        std::string::size_type n = s.length();
        for (std::string::size_type i = str.find(s); i != std::string::npos;
            i = str.find(s)) {
            str.erase(i, n);    
        }
        return String(str);
    } 

    String erase(const String& erase_str) {
        return erase(erase_str._str);   
    }

    String erase(const char* erase_str){
        return erase(std::string(erase_str));   
    }

    String eraseFirst(const std::string& erase_str) {
        std::string str = _str;
        std::string s = erase_str;
        std::size_t pos = str.find(s);
        if (pos != std::string::npos) {
            str.erase(pos, s.length());
        }
        return String(str);
    } 

    String eraseFirst(const String& erase_str) {
        return eraseFirst(erase_str._str);
    }

    String eraseFirst(const char* erase_str) {
        return eraseFirst(std::string(erase_str));
    }

    String eraseLast(const std::string& erase_str) {
        std::string str = _str;
        const std::string s = erase_str;
        std::size_t pos = str.rfind(s);
        if (pos != std::string::npos) {
            str.erase(pos, s.length());
        }
        return String(str);
    } 

    String eraseLast(const String& erase_str) {
        return eraseLast(erase_str._str);
    }

    String eraseLast(const char* erase_str) {
        return eraseLast(std::string(erase_str));
    }

    String eraseHead(const int headsize) {
        std::string str = _str;
        str.erase(0,headsize);
        return String(str);
    }

    String eraseTail(const int tailsize) {
        std::string str = _str;
        str.erase(str.end()-tailsize, str.end());
        return String(str);
    } 

    std::vector<String> split(const std::string& str) {
        std::vector<String> parts;
        std::string s = _str;
        std::size_t pos = 0;
        std::string token;
        while ((pos = s.find(str)) != std::string::npos) {
            token = s.substr(0, pos);
            parts.push_back(String(token));
            s.erase(0, pos + str.length());
        }
        parts.push_back(String(s));
        return parts;
    }

    std::vector<String> split(const String& str) {
        return split(str._str);
    }

    std::vector<String> split(const char* str) {
        return split(std::string(str));
    }

    std::vector<String> split(const char c) {
        return split(std::string() += c);
    }

    String reverse() {
        std::string str = _str;
        std::reverse(str.begin(), str.end());
        return String(str);
    }

    void swap(std::string &str2) {
        std::string str3 = _str;
        _str = str2;
        str2 = str3;
    }

    void swap(String &str2) {
        std::string str3 = _str;
        _str = str2;
        str2 = str3;
    }

    String toUpper(){
        std::string str = _str;
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);  
        return String(str);
    }

    String toLower(){
        std::string str = _str;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);  
        return String(str);
    }

    String trim() {
        String s = trimHead();
        return s.trimTail();
    }

    String trimHead() {
        std::string str = _str;
        std::string::size_type trimIt = 0;
        for (std::string::size_type i = 0; i < str.length(); i++) {
            if (str[i] == ' ' || str[i] == '\t') {
                trimIt++;    
            } else break;
        }
        return String(str.erase(0,trimIt));
    }

    String trimTail() {
        std::string str = _str;
        std::string::size_type trimIt = str.length();
        while (str.rfind(" ") == str.length()-1
              || str.rfind("\t") == str.length()-1) {
            if (str.length() == 1){
                str.erase(0);
                break;
            }
            str.erase(str.length()-1);
        }
        return String(str);
    }

    String fillHead(const int length, const char fill) {
        std::string str = _str;
        for (int i = 0; i < length; i++) {
            str.insert(str.begin(), fill);
        }
        return String(str);
    }

    inline String padLeft(const int length, const char fill) {
        return this->fillHead(length, fill);    
    }

    String fillTail(const int length, const char fill) {
        std::string str = _str;
        for (int i = 0; i < length; i++) {
            str += fill;
        }
        return String(str);
    }

    inline String padRight(const int length, const char fill) {
        return this->fillTail(length, fill);
    }

    bool endsWith(const std::string& str) {
        const std::string s = str;
        if (s.length() > _str.length()) return false;
        return s == _str.substr(_str.length()-s.length(), s.length());
    }

    bool endsWith(const String& str) {
        return endsWith(str._str);
    }

    bool endsWith(const char* str) {
        return endsWith(std::string(str));
    }

    bool startsWith(const std::string& str) {
        const std::string s = str;
        if (s.length() > _str.length()) return false;
        return s == _str.substr(0, s.length());
    }

    bool startsWith(const String& str) {
        return startsWith(str._str);
    }

    bool startsWith(const char* str) {
        return startsWith(std::string(str));
    }

    template<typename T, typename ... Strings>
    String& format(const T first_str, const Strings... formatter) {
        replaceFirst("{%}", first_str);
        replaceFirst("{%}", formatter...);
        return *this;
    }

    void print() {
        std::cout << _str << std::endl;
    }

    template<typename T>
    void print(const T str, const T separator = "") {
        std::cout << getStdStr(str) << separator;
    }

    template<typename T, typename ... Strings>
    void print(T separator, T str, Strings... strs) {
        print(str, separator);
        print(strs..., separator);
        std::cout << std::endl;
    }

    // iterator
    iterator begin() { return _str.begin(); }
    iterator end() { return _str.end(); }
    reverse_iterator rbegin() { return _str.rbegin(); }
    reverse_iterator rend() { return _str.rend(); }
    const_iterator cbegin() { return _str.cbegin(); }
    const_iterator cend() { return _str.cend(); }
    const_reverse_iterator crbegin() { return _str.crbegin(); }
    const_reverse_iterator crend() { return _str.crend(); }

    // operator
    operator std::string() const{
        return _str;
    }

    void operator= (const std::string& s) {
        _str = s;
    }

    void operator= (const String& s) {
        _str = s._str;
    }

    void operator= (const char* c) {
        _str = std::string(c);
    }

    bool operator== (const std::string& s) {
        return (_str.compare(s) == 0);
    }

    bool operator== (const String& s) {
        return (_str.compare(s._str) == 0);
    }

    bool operator== (const char* c) {
        return (_str.compare(std::string(c)) == 0);
    }

    bool operator!= (const std::string& s) {
        return (_str.compare(s) != 0);
    }

    bool operator!= (const String& s) {
        return (_str.compare(s._str) != 0);
    }

    bool operator!= (const char* c) {
        return (_str.compare(std::string(c)) != 0);
    }

    bool operator< (const std::string& s) const {
        return (_str.length() < s.length());
    }

    bool operator< (const String& s) const {
        return (_str.length() < s._str.length());
    }

    bool operator< (const char* s) const {
        return (_str.length() < std::string(s).length());
    }

    bool operator<= (const std::string s) const {
        return (_str.length() <= s.length());
    }

    bool operator<= (const String s) const {
        return (_str.length() <= s._str.length());
    }

    bool operator<= (const char* s) const{
        return (_str.length() <= std::string(s).length());
    }

    bool operator> (std::string s) const {
        return (_str.length() > s.length());
    }

    bool operator> (String s) const {
        return (_str.length() > s._str.length());
    }

    bool operator> (const char* s) const {
        return (_str.length() > std::string(s).length());
    }

    bool operator>= (std::string s) {
        return (_str.length() >= s.length());
    }

    bool operator>= (String s) const {
        return (_str.length() >= s.length());
    }

    bool operator>= (const char* s) const {
        return (_str.length() >= std::string(s).length());
    }

    String& operator+= (const std::string& s) {
        _str += s;
        return *this;
    }

    String& operator+= (const String& s) {
        _str += s._str;
        return *this;
    }

    String& operator+= (const char* s) {
        _str += s;
        return *this;
    }

    String operator+ (const std::string& s) {
        return String(_str + s);
    }

    String operator+ (const String& s) {
        return String(_str + s._str);
    }

    String operator+ (const char* s) {
        return String(_str + s);
    }

    String operator* (const int mul) {
        std::string str;
        for(int i = 0; i < mul; i++) {
            str += _str;
        }
        return String(str);
    }

    String operator*= (const int mul) {
        for(int i = 0; i < mul; i++) {
            _str += _str;
        }
        return *this;
    }

    std::vector<String> operator/(const int div) {
        if(div == 0) {
            throw std::overflow_error("str::String divide by zero exception");
        }
        if(this->length() < div) {
            throw std::out_of_range(
                    "str::String.length() has to be greater or equal divisor");
        }
        std::vector<String> vec;
        int start, end, len, j = 0;
        int length = this->length();
        float f = static_cast<float>(length)/static_cast<float>(div);
        int idiv = round(f);
        for(int i = 0; i < div; i++) {
            vec.push_back(
                this->substr(i*idiv, idiv)
            );
        }
        return vec;
    }

    char& operator[] (const int pos) {
        return this->_str[pos];
    }

    friend std::ostream& operator<< (std::ostream& out, const String& s) {
        out << s._str;
        return out;
    }

    friend std::istream& operator>> (std::istream& is, String& s) {
        char* input = new char[1024];
        is.getline(input, 1024);
        std::string convert(input);
        s = convert;
        return is;
    }

    friend bool operator== (const String& s1, const String& s2) {
        return s1._str == s2._str;
    }
};}

#endif

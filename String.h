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
    std::string m_str;
    typedef std::string::iterator iterator;
    typedef std::string::reverse_iterator reverse_iterator;
    typedef std::string::const_iterator const_iterator;
    typedef std::string::const_reverse_iterator const_reverse_iterator;

    const std::string getStdStr(std::string s) {
        return s;
    }

    const std::string getStdStr(const char* s) {
        return std::string(s);
    }

    const std::string getStdStr(String s) {
        return s.toStdStr();
    }

    const std::string getStdStr(char &c) {
        return std::string() += c;
    }

    public:
    String() { m_str = ""; }
    String(std::string str) { m_str = str; }
    String(const char* cstr) { m_str = std::string(cstr); }
    String(const String &s) { m_str = s.m_str; }
    String(const char c) { m_str = std::string() += c; }
    String(const int i) { m_str = std::to_string(i); }
    String(const float f) { m_str = std::to_string(f); }
    String(const double d) { m_str = std::to_string(d); }
    String(const long l) { m_str = std::to_string(l); }
    String(const bool b) { if(b) m_str = "true"; else m_str = "false"; }
    ~String() {}

    // casts 
    std::string toStdStr() { return m_str; }
    const char* toCStr() { return m_str.c_str(); }
    int toInt() { return std::stoi(m_str); }
    long toLong() { return std::stol(m_str); }
    float toFloat() { return std::stof(m_str); }
    double toDouble() { return std::stod(m_str); }
    bool toBool() {
        if(m_str == "false" || m_str == "0" || m_str == "")
            return false;
        else
            return true;
    }

    std::vector<char> toCharArr() {
        std::vector<char> vec;
        for(char c : m_str) {
            vec.push_back(c);
        }
        return vec;
    }

    char charAt(const int pos) { 
        return m_str.at(pos); 
    }

    bool isEmpty() { 
        return m_str.empty(); 
    }

    bool isEmptyOrWhiteSpace() {
        if(m_str.empty()) {
            return true;
        } else {
            if(m_str.find_first_not_of(' ') != std::string::npos){
                return false;
            }
            return true;
        }
    }

    String substr(const int pos, const int len) {
        return String(m_str.substr(pos, len));
    }

    template<typename S>
    String& addHead(const S s) {
        m_str = getStdStr(s) + m_str;
        return *this;
    }

    template<typename S>
    String& addTail(const S s) {
        m_str += getStdStr(s);
        return *this;
    }

    template<typename S>
    bool compare(const S s) {
        if(m_str == getStdStr(s)) 
            return true;
        else 
            return false;
    }

    template<typename S>
    inline bool equals(const S s) {
        return this->compare(s);
    }

    int length() {
        return m_str.length();
    }

    inline int size() {
        return this->length();
    }

    void clear() {
        m_str.clear();
    }

    char front() {
        return m_str.front();
    }

    inline char first() {
        return this->front();
    }

    char back() {
        return m_str.back();
    }

    inline char last() {
        return this->back();
    }

    void shrinkToFit() {
        m_str.shrink_to_fit();
    }

    size_t maxSize() const noexcept {
        return m_str.max_size();
    }

    size_t capacity() const noexcept {
        return m_str.capacity();
    }

    void resize(size_t n) {
        m_str.resize(n);
    }

    template<typename S>
    bool contains(const S str) {
        return this->count(str) > 0;
    }

    template<typename S>
    String& concat(const S str) {
        m_str += getStdStr(str);
        return *this;
    }

    template<typename S>
    inline String& join(const S str) {
        return this->concat(str);
    }

    void copyTo(String &s) { s.m_str = m_str; }
    void copyTo(std::string &s) { s = m_str; }

    template<typename S>
    int count(const S str) {
        return this->find(getStdStr(str)).size();
    }

    template<typename S>
    String& insert(const int start, const S str) {
        m_str.insert(start, getStdStr(str));
        return *this;
    }
    
    template<typename S>
    std::vector<int> find(const S str) {
        std::string s = getStdStr(str);
        std::vector<int> vec;
        std::size_t pos = m_str.find(s);
        while(pos != std::string::npos) {
            vec.push_back(pos);
            pos = m_str.find(s,pos+1);
        }
        return vec;
    }

    template<typename S>
    inline std::vector<int> findAll(const S str) {
        return this->find(str);
    }

    template<typename S>
    int findFirst(const S str) {
        std::size_t pos = m_str.find(getStdStr(str));
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        }
        return 0;
    }

    template<typename S>
    inline int indexOf(const S str) {
        return this->findFirst(str);
    }

    template<typename S>
    int findLast(const S str) {
        std::size_t pos = m_str.rfind(getStdStr(str));
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        } return 0;
    }

    template<typename S>
    inline int lastIndexOf(const S str) {
        return this->findLast(str);
    }

    template<typename S1, typename S2>
    String& replace(const S1 oldstr, const S2 newstr) {
        std::string o = getStdStr(oldstr);
        std::string n = getStdStr(newstr);
        std::size_t pos = m_str.find(o);
        while(pos != std::string::npos) {
            m_str.replace(pos, o.length(), n);
            pos = m_str.find(o,pos+1);
        }
        return *this;
    }

    template<typename S1, typename S2>
    String& replaceFirst(const S1 oldstr, const S2 newstr) {
        std::string o = getStdStr(oldstr);
        std::string n = getStdStr(newstr);
        std::size_t pos = m_str.find(o);
        if(pos != std::string::npos) {
            m_str.replace(pos, o.length(), n);
        }
        return *this;
    }

    template<typename S1, typename S2>
    String& replaceLast(const S1 oldstr, const S2 newstr) {
        std::string o = getStdStr(oldstr);
        std::string n = getStdStr(newstr);
        std::size_t pos = m_str.rfind(o);
        if(pos != std::string::npos) {
            m_str.replace(pos, o.length(), n);
        }
        return *this;
    }

    template<typename S>
    String& replaceHead(const int headsize, const S newstr){
        m_str.erase(0,headsize);
        m_str = getStdStr(newstr) + m_str;
        return *this;
    }

    template<typename S>
    String& replaceTail(const int tailsize, const S newstr){
        m_str.erase(m_str.end()-tailsize, m_str.end());
        m_str += getStdStr(newstr);
        return *this;
    }

    template<typename S>
    String& erase(const S erasestr){
        const std::string s = getStdStr(erasestr);
        std::string::size_type n = s.length();
        for (std::string::size_type i = m_str.find(s); i != std::string::npos; 
            i = m_str.find(s)) {
            m_str.erase(i, n);    
        }
        return *this;
    } 

    template<typename S>
    String& eraseFirst(const S erasestr){
        std::string s = getStdStr(erasestr);
        std::size_t pos = m_str.find(s);
        if(pos != std::string::npos){
            m_str.erase(pos, s.length());
        }
        return *this;
    } 

    template<typename S>
    String& eraseLast(const S erasestr){
        const std::string s = getStdStr(erasestr);
        std::size_t pos = m_str.rfind(s);
        if(pos != std::string::npos){
            m_str.erase(pos, s.length());
        }
        return *this;
    } 

    String& eraseHead(const int headsize){
        m_str.erase(0,headsize);
        return *this;
    }

    String& eraseTail(const int tailsize){
        m_str.erase(m_str.end()-tailsize, m_str.end());
        return *this;
    } 

    template<typename S>
    std::vector<String> split(const S delimiter){
        const std::string s = getStdStr(delimiter);
        std::vector<String> parts;
        std::string str = m_str;
        std::size_t pos = 0;
        std::string token;
        while((pos = str.find(s)) != std::string::npos){
            token = str.substr(0,pos);
            parts.push_back(String(token));
            str.erase(0, pos + s.length());
        }
        parts.push_back(String(str));
        return parts;
    }

    void swap(std::string &str2) {
        std::string str3 = m_str;
        m_str = str2;
        str2 = str3;
    }

    void swap(String &str2) {
        std::string str3 = m_str;
        m_str = str2;
        str2 = str3;
    }

    String& toUpper(){
        std::transform(m_str.begin(), m_str.end(), m_str.begin(), ::toupper);  
        return *this;
    }

    String& toLower(){
        std::transform(m_str.begin(), m_str.end(), m_str.begin(), ::tolower);  
        return *this;
    }

    String& trim() {
        trimHead();
        trimTail();
        return *this;
    }

    String& trimHead(){
        std::string::size_type trimIt = 0;
        for(std::string::size_type i = 0; i < m_str.length(); i++) {
            if(m_str[i] == ' ' || m_str[i] == '\t') {
                trimIt++;    
            } else break;
        }
        m_str.erase(0,trimIt);
        return *this;
    }

    std::string trimTail(){
        std::string::size_type trimIt = m_str.length();
        while(m_str.rfind(" ") == m_str.length()-1
              || m_str.rfind("\t") == m_str.length()-1) {
            if(m_str.length() == 1){
                m_str.erase(0);
                break;
            }
            m_str.erase(m_str.length()-1);
        }
        return *this;
    }

    String& fillHead(const int length, const char fill) {
        for(int i = 0; i < length; i++){
            m_str.insert(m_str.begin(), fill);
        }
        return *this;
    }

    inline String& padLeft(const int length, const char fill) {
        return this->fillHead(length, fill);    
    }

    String& fillTail(const int length, const char fill){
        for (int i = 0; i < length; i++) {
            m_str += fill;
        }
        return *this;
    }

    inline String& padRight(const int length, const char fill) {
        return this->fillTail(length, fill);
    }

    template<typename S>
    bool endsWith(const S str) {
        const std::string s = getStdStr(str);
        if(s.length() > m_str.length()) return false;
        return s == m_str.substr(m_str.length()-s.length(), s.length());
    }

    template<typename S>
    bool startsWith(const S str) {
        const std::string s = getStdStr(str);
        if(s.length() > m_str.length()) return false;
        return s == m_str.substr(0, s.length());
    }

    template<typename S, typename ... Strs>
    String& format(const S fstr, const Strs... formatter) {
        replaceFirst("{%}", fstr);
        replaceFirst("{%}", formatter...);
        return *this;
    }

    void print() {
        std::cout << m_str << std::endl;
    }

    template<typename S>
    void print(const S s, const S separator = "") {
        std::cout << getStdStr(s) << separator;
    }

    template<typename S, typename ... Strings>
    void print(S separator, S s, Strings... strs) {
        print(s, separator);
        print(strs..., separator);
        std::cout << std::endl;
    }

    // iterator
    iterator begin() { return m_str.begin(); }
    iterator end() { return m_str.end(); }
    reverse_iterator rbegin() { return m_str.rbegin(); }
    reverse_iterator rend() { return m_str.rend(); }
    const_iterator cbegin() { return m_str.cbegin(); }
    const_iterator cend() { return m_str.cend(); }
    const_reverse_iterator crbegin() { return m_str.crbegin(); }
    const_reverse_iterator crend() { return m_str.crend(); }

    // operator
    operator std::string() const{
        return m_str;
    }

    template<typename S>
    void operator= (S &s) {
        m_str = getStdStr(s);
    }

    template<typename S>
    bool operator== (const S s) {
        return (m_str.compare(getStdStr(s)) == 0);
    }

    template<typename S>
    bool operator!= (const S s) {
        return (m_str.compare(getStdStr(s)) != 0);
    }

    template<typename S>
    bool operator< (const S s) {
        return (m_str.length() < getStdStr(s).length());
    }

    template<typename S>
    bool operator<= (const S s) {
        return (m_str.length() <= getStdStr(s).length());
    }

    template<typename S>
    bool operator> (const S s) {
        return (m_str.length() > getStdStr(s).length());
    }

    template<typename S>
    bool operator>= (const S s) {
        return (m_str.length() >= getStdStr(s).length());
    }

    template<typename S>
    String& operator+= (const S s) {
        m_str += getStdStr(s);
        return *this;
    }

    template<typename S>
    String operator+(S s) {
        return String(m_str + getStdStr(s));
    }

    String operator*(const int mul) {
        std::string str;
        for(int i = 0; i < mul; i++) {
            str += m_str;
        }
        return String(str);
    }

    String operator*=(const int mul) {
        for(int i = 0; i < mul; i++) {
            m_str += m_str;
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
        return this->m_str[pos];
    }

    friend std::ostream& operator<< (std::ostream &out, const String &s) {
        out << s.m_str;
        return out;
    }

    friend std::istream& operator>> (std::istream &is, String &s) {
        char* input = new char[256];
        is.getline(input,256);
        std::string convert(input);
        s = convert;
        return is;
    }

    friend bool operator==(const String &s1, const String &s2) {
        return s1.m_str == s2.m_str;
    }
};}

#endif

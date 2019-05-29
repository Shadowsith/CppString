#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdexcept>

class String {

    private:
    std::string m_str;

    template<typename S>
    std::string getStdStr(S s) {
        if(typeid(s) == typeid(std::string)) {
            return s;
        } else if(typeid(s) == typeid(const char*)) {
            return std::string(s);
        } else if(typeid(s) == typeid(String)) {
            return static_cast<String>(s).m_str;
        } else {
            throw 
                std::invalid_argument(
                    "Argument is not from type String, std::string, char or const char*"
                );
        }
    }

    std::string getStdStr(char c) {
        return std::string() += c;
    }

    public:
    String() { m_str = ""; }
    String(std::string str) { m_str = str; }
    String(const char* cstr) { m_str = std::string(cstr); }
    String(char c) { m_str = std::string() += c; }
    String(int i) { m_str = std::to_string(i); }
    String(float f) { m_str = std::to_string(f); }
    String(double d) { m_str = std::to_string(d); }
    String(long l) { m_str = std::to_string(l); }
    String(bool b) { if(b) m_str = "true"; else m_str = "false"; }

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

    template<typename S>
    bool compare(S &s) {
        if(m_str == getStdStr(s)) 
            return true;
        else 
            return false;
    }

    bool compare(const char* s) {
        if(std::strcmp(s, m_str.c_str()) == 0)
            return true;
        else
            return false;
    }

    template<typename S>
    inline bool equals(S &s) {
        return this->compare(s);
    }

    inline bool equals(const char* s) {
        return this->compare(s);
    }

    int length() {
        return m_str.length();
    }

    inline int size() {
        return this->length();
    }

    template<typename S>
    std::string concat(const S &s) {
        m_str += getStdStr(s);
        return m_str;
    }

    void copyTo(String &s) { s.m_str = m_str; }
    void copyTo(std::string &s) { s = m_str; }

    template<typename S>
    int count(S str) {
        return this->find(getStdStr(str)).size();
    }
    
    template<typename S>
    std::vector<int> find(S str) {
        std::string s = getStdStr(str);
        std::vector<int> vec;
        std::size_t pos = m_str.find(s);
        while(pos != std::string::npos) {
            vec.push_back(pos);
            pos = m_str.find(s,pos+1);
        } return vec;
    }

    template<typename S>
    inline std::vector<int> findAll(S str) {
        return this->find(str);
    }

    template<typename S>
    int findFirst(S str) {
        std::size_t pos = m_str.find(getStdStr(str));
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        } return 0;
    }

    template<typename S>
    inline int indexOf(S str) {
        return this->findFirst(str);
    }

    template<typename S>
    int findLast(S str) {
        std::size_t pos = m_str.rfind(getStdStr(str));
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        } return 0;
    }

    template<typename S>
    inline int lastIndexOf(S str) {
        return this->findLast(str);
    }

    template<typename S1, typename S2>
    std::string replace(S1 oldstr, S2 newstr) {
        std::string o = getStdStr(oldstr);
        std::string n = getStdStr(newstr);
        std::size_t pos = m_str.find(o);
        while(pos != std::string::npos) {
            m_str.replace(pos, o.length(), n);
            pos = m_str.find(o,pos+1);
        }
        return m_str;
    }

    template<typename S1, typename S2>
    std::string replaceFirst(S1 oldstr, S2 newstr) {
        std::string o = getStdStr(oldstr);
        std::string n = getStdStr(newstr);
        std::size_t pos = m_str.find(o);
        if(pos != std::string::npos) {
            m_str.replace(pos, o.length(), n);
        } return m_str;
    }

    template<typename S1, typename S2>
    std::string replaceLast(S1 oldstr, S2 newstr) {
        std::string o = getStdStr(oldstr);
        std::string n = getStdStr(newstr);
        std::size_t pos = m_str.rfind(o);
        if(pos != std::string::npos) {
            m_str.replace(pos, o.length(), n);
        } return m_str;
    }

    template<typename S>
    std::string replaceHead(const int headsize, S newstr){
        m_str.erase(0,headsize);
        m_str = getStdStr(newstr) + m_str;
        return m_str;
    }

    template<typename S>
    std::string replaceTail(const int tailsize, S newstr){
        m_str.erase(m_str.end()-tailsize, m_str.end());
        m_str += getStdStr(newstr);
        return m_str;
    }

    template<typename S>
    std::string erase(S erasestr){
        std::string s = getStdStr(erasestr);
        std::string::size_type n = s.length();
        for (std::string::size_type i = m_str.find(s); i != std::string::npos; 
            i = m_str.find(s)) {
            m_str.erase(i, n);    
        }
        return m_str;
    } 

    template<typename S>
    std::string eraseFirst(S erasestr){
        std::string s = getStdStr(erasestr);
        std::size_t pos = m_str.find(s);
        if(pos != std::string::npos){
            m_str.erase(pos, s.length());
        } return m_str;
    } 

    template<typename S>
    std::string eraseLast(S erasestr){
        std::string s = getStdStr(erasestr);
        std::size_t pos = m_str.rfind(s);
        if(pos != std::string::npos){
            m_str.erase(pos, s.length());
        } return m_str;
    } 

    std::string eraseHead(const int headsize){
        m_str.erase(0,headsize);
        return m_str;
    }

    std::string eraseTail(const int tailsize){
        m_str.erase(m_str.end()-tailsize, m_str.end());
        return m_str;
    } 

    template<typename S>
    std::vector<std::string> split(S delimiter){
        std::string s = getStdStr(delimiter);
        std::vector<std::string> parts;
        std::string str = m_str;
        std::size_t pos = 0;
        std::string token;
        while((pos = str.find(s)) != std::string::npos){
            token = str.substr(0,pos);
            parts.push_back(token);
            str.erase(0, pos + s.length());
        }
        parts.push_back(str);
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

    std::string toUpper(){
        std::transform(m_str.begin(), m_str.end(), m_str.begin(), ::toupper);  
        return m_str; 
    }

    std::string toLower(){
        std::transform(m_str.begin(), m_str.end(), m_str.begin(), ::tolower);  
        return m_str;
    }

    std::string trim() {
        //trim left side
        std::string::size_type trimIt = 0;
        for(std::string::size_type i = 0; i < m_str.length(); i++) {
            if(m_str[i] == ' ') {
                trimIt++;    
            } else break;
        }
        m_str.erase(0,trimIt);

        //trim right side
        trimIt = m_str.length();
        for(std::string::size_type i = m_str.length()-1; i > 0; i--) {
            if(m_str[i] == ' '){
                trimIt--;
            } else break;
        }
        m_str.erase(trimIt, m_str.length()-1);

        return m_str;
    }

    std::string trimLeft(){
        std::string::size_type trimIt = 0;
        for(std::string::size_type i = 0; i < m_str.length(); i++) {
            if(m_str[i] == ' ') {
                trimIt++;    
            } else break;
        }
        m_str.erase(0,trimIt);

        return m_str;
    }

    std::string trimRight(){
        std::string::size_type trimIt = m_str.length();
        while(m_str.rfind(" ") == m_str.length()-1){
            if(m_str.length() == 1){
                m_str.erase(0);
                break;
            }
            m_str.erase(m_str.length()-1);
        } return m_str;
    }

    std::string fillLeft(const int length, const char fill){
        for(int i = 0; i < length; i++){
            m_str.insert(m_str.begin(), fill);
        } return m_str;
    }

    inline std::string padLeft(const int length, const char fill){
        return this->fillLeft(length, fill);    
    }

    std::string fillRight(const int length, const char fill){
        for (int i = 0; i < length; i++) {
            m_str += fill;
        } return m_str;
    }

    inline std::string padRight(const int length, const char fill){
        return this->fillRight(length, fill);
    }

    std::string normPathUnix(){
        replace("\\", "/");
        replace("//", "/");
        return m_str;
    }

    std::string normPathWindows(){
        replace("/", "\\");
        replace("\\\\", "\\");
        return m_str;
    }

    template<typename S, typename ... Strs>
    std::string format(S fstr, Strs... formatter) {
        replaceFirst("{%}", fstr);
        replaceFirst("{%}", formatter...);
        return m_str;
    }

    // operator
    operator std::string() const{
        return m_str;
    }

    template<typename S>
    void operator= (S s) {
        m_str = getStdStr(s);
    }

    template<typename S>
    bool operator== (S s) {
        return (m_str.compare(getStdStr(s)) == 0);
    }

    template<typename S>
    bool operator!= (S s) {
        return (m_str.compare(getStdStr(s)) != 0);
    }

    template<typename S>
    String& operator+= (S s) {
        m_str += getStdStr(s);
        return *this;
    }

    template<typename S>
    std::string operator+(S s) {
        return m_str + getStdStr(s);
    }

    template<typename S>
    std::string operator*(S s) {
        std::string str = getStdStr(s);
        for(int i = 0; i < str.length(); i++) {
            m_str += str;
        } return m_str;
    }

    char& operator[] (int pos) {
        return this->m_str[pos];
    }

    friend std::ostream& operator<< (std::ostream &out, const String& s) {
        out << s.m_str;
        return out;
    }

    friend std::istream& operator>> (std::istream &is, String& s) {
        char* input = new char[256];
        is.getline(input,256);
        std::string convert(input);
        s = convert;
        return is;
    }
};

#endif

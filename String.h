#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class String {

    private:
    std::string m_str;

    public:
    String() { m_str = ""; }
    String(std::string str) { m_str = str; }
    String(const char* cstr) { m_str = std::string(cstr); }

    //casts 
    std::string toStdStr() { return m_str; }

    const char* toCStr() { return m_str.c_str(); }

    std::vector<char> toCharArr() {
        std::vector<char> vec;
        for(char c : m_str) {
            vec.push_back(c);
        }
        return vec;
    }

    char charAt(const int pos) { return m_str.at(pos); }

    bool isEmpty() { return m_str.empty(); }

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

    bool compare(String &s) {
        if(m_str == s.m_str) 
            return true;
        else 
            return false;
    }

    bool compare(const std::string &s) {
        if(m_str == s) 
            return true;
        else 
            return false;
    }

    inline bool equals(String &s) {
        return this->compare(s);
    }

    inline bool equals(const std::string &s) {
        return this->compare(s);
    }

    int length() {
        return m_str.length();
    }

    inline int size() {
        return this->length();
    }

    // string formatting 
    String concat (const String &s) {
        m_str += s.m_str;
        return String(m_str);
    }
    
    std::string concat(const std::string &s) {
        return m_str + s; 
    }

    void copyTo(String &s) { s.m_str = m_str; }
    void copyTo(std::string &s) { s = m_str; }
    
    int count(const String s) {
        return this->find(s).size();
    }

    int count(const std::string s) {
        return this->find(s).size();
    }

    int count(const char* s) {
        return this->find(s).size(); 
    }

    std::vector<int> find(const std::string s) {
        std::vector<int> vec;
        std::size_t pos = m_str.find(s);
        while(pos != std::string::npos) {
            vec.push_back(pos);
            pos = m_str.find(s,pos+1);
        } return vec;
    }

    std::vector<int> find(const String s) {
        return this->find(s.m_str); 
    }

    std::vector<int> find(const char* s) {
        return this->find(std::string(s)); 
    }

    inline std::vector<int> findAll(const std::string s) {
        return this->find(s);
    }

    inline std::vector<int> findAll(const String s) {
        return this->find(s);
    }

    inline std::vector<int> findAll(const char* s) {
        return this->find(s);
    }

    int findFirst(const std::string s) {
        std::size_t pos = m_str.find(s);
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        } return 0;
    }

    int findFirst(const String s) {
        return this->findFirst(s.m_str);
    }

    int findFirst(const char* s) {
        return this->findFirst(std::string(s));
    }

    inline int indexOf(const std::string s) {
        return this->findFirst(s);
    }

    inline int indexOf(const String s) {
        return this->findFirst(s.m_str);
    }

    inline int indexOf(const char* s) {
        return this->findFirst(s);
    }

    int findLast(const String s) {
        return this->findLast(s.m_str);
    }

    int findLast(const std::string s) {
        std::size_t pos = m_str.rfind(s);
        if(pos != std::string::npos){
            int i = static_cast<int>(pos);
            return i;
        } return 0;
    }

    int findLast(const char* s) {
        return this->findLast(std::string(s));
    }

    inline int lastIndexOf(const String s) {
        return this->findLast(s);
    }

    inline int lastIndexOf(const std::string s) {
        return this->findLast(s);
    }

    inline int lastIndexOf(const char* s) {
        return this->findLast(s);
    }

    std::string replace(const std::string oldstr, const std::string newstr) {
        std::size_t pos = m_str.find(oldstr);
        while(pos != std::string::npos) {
            m_str.replace(pos, oldstr.length(), newstr);
            pos = m_str.find(oldstr,pos+1);
        }
        return m_str;
    }

    std::string replace(const char* oldstr, const char* newstr) {
        return this->replace(std::string(oldstr), std::string(newstr)); 
    }

    std::string replace(const String oldstr, const String newstr) {
        return this->replace(std::string(oldstr), std::string(newstr));
    }

    std::string replaceFirst(const std::string oldstr, const std::string newstr) {
        std::size_t pos = m_str.find(oldstr);
        if(pos != std::string::npos) {
            m_str.replace(pos, oldstr.length(), newstr);
        } return m_str;
    }

    std::string replaceFirst(const char* oldstr, const char* newstr) {
        return this->replaceFirst(std::string(oldstr), std::string(newstr));
    }

    std::string replaceFirst(const String oldstr, const String newstr) {
        return this->replaceFirst(oldstr.m_str, newstr.m_str);
    }

    std::string replaceLast(const std::string oldstr, const std::string newstr){
        std::size_t pos = m_str.rfind(oldstr);
        if(pos != std::string::npos) {
            m_str.replace(pos, oldstr.length(), newstr);
        } return m_str;
    }

    std::string replaceLast(const String oldstr, const String newstr) {
        return this->replaceLast(oldstr.m_str, newstr.m_str); 
    }

    std::string replaceLast(const char* oldstr, const char* newstr) {
        return this->replaceLast(std::string(oldstr), std::string(newstr));
    }

    std::string replaceHead(const int headsize, const std::string newstr){
        m_str.erase(0,headsize);
        m_str = newstr + m_str;
        return m_str;
    }

    std::string replaceHead(const int headsize, const String newstr){
        return this->replaceHead(headsize, newstr.m_str);
    }

    std::string replaceHead(const int headsize, const char* newstr){
        return this->replaceHead(headsize, std::string(newstr));
    }


    std::string replaceTail(const int tailsize, const std::string newstr){
        m_str.erase(m_str.end()-tailsize, m_str.end());
        m_str += newstr;
        return m_str;
    }

    std::string replaceTail(const int tailsize, const String newstr){
        return this->replaceTail(tailsize, newstr.m_str);
    }

    std::string replaceTail(const int tailsize, const char* newstr){
        return this->replaceTail(tailsize, std::string(newstr));
    }

    std::string erase(const std::string erasestr){
        std::string::size_type n = erasestr.length();
        for (std::string::size_type i = m_str.find(erasestr); i != std::string::npos; 
            i = m_str.find(erasestr)) {
            m_str.erase(i, n);    
        }
        return m_str;
    } 

    std::string erase(const String erasestr){
        return this->erase(erasestr.m_str);
    }

    std::string erase(const char* erasestr){
        return this->erase(std::string(erasestr));
    }

    std::string eraseFirst(const std::string erasestr){
        std::size_t pos = m_str.find(erasestr);
        if(pos != std::string::npos){
            m_str.erase(pos, erasestr.length());
        } return m_str;
    } 

    std::string eraseFirst(const String eraseFirststr){
        return this->eraseFirst(eraseFirststr.m_str);
    }

    std::string eraseFirst(const char* eraseFirststr){
        return this->eraseFirst(std::string(eraseFirststr));
    }

    std::string eraseLast(std::string erasestr){
        std::size_t pos = m_str.rfind(erasestr);
        if(pos != std::string::npos){
            m_str.erase(pos, erasestr.length());
        } return m_str;
    } 

    std::string eraseLast(const String eraseLaststr){
        return this->eraseLast(eraseLaststr.m_str);
    }

    std::string eraseLast(const char* eraseLaststr){
        return this->eraseLast(std::string(eraseLaststr));
    }

    std::string eraseHead(const int headsize){
        m_str.erase(0,headsize);
        return m_str;
    }

    std::string eraseTail(const int tailsize){
        m_str.erase(m_str.end()-tailsize, m_str.end());
        return m_str;
    } 

    std::vector<std::string> split(const std::string delimiter){
        std::vector<std::string> parts;
        std::string str = m_str;
        std::size_t pos = 0;
        std::string token;
        while((pos = str.find(delimiter)) != std::string::npos){
            token = str.substr(0,pos);
            parts.push_back(token);
            str.erase(0, pos + delimiter.length());
        }
        parts.push_back(str);
        return parts;
    }

    std::vector<std::string> split(const String delimiter) {
        return this->split(delimiter.m_str);
    }

    std::vector<std::string> split(const char* delimiter) {
        return this->split(std::string(delimiter));
    }

    std::vector<std::string> split(const char delimiter) {
        std::string s;
        s += delimiter;
        return this->split(s);
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
        for(int i = 1; i < m_str.length(); i++){
            if(m_str.at(i) == m_str.at(i-1)){
                m_str.erase(i);
            }
        } return m_str;
    }

    std::string normPathWindows(){
        for(int i = 1; i < m_str.length(); i++) {
            if(m_str.at(i) == m_str.at(i-1)){
                m_str.erase(i);
            }
        } return m_str;
    }

    // string formatting here:

    //operators

    operator std::string() const{
        return m_str;
    }

    String operator= (String &s) {
        return s.m_str;
    }

    void operator= (std::string str) {
        m_str = str;
    }

    void operator= (const char* c) {
        m_str = std::string(c);
    }

    bool operator== (const String &s) {
        return (m_str.compare(s.m_str) == 0);
    }

    bool operator== (const std::string &str) {
        return (m_str.compare(str) == 0);
    }

    bool operator== (const char* c) {
        for(int i = 0; i < m_str.length(); i++) {
            if(m_str[i] != c[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!= (const String& S) {
        return (m_str.compare(S.m_str) != 0);
    }

    bool operator!= (const std::string str) {
        return (m_str.compare(str) != 0);
    }

    bool operator!= (const char* c) {
        for(int i = 0; i < m_str.length(); i++) {
            if(m_str[i] != c[i]) {
                return true;
            }
        }
        return false;
    }

    String& operator+= (const String &S) {
        this->m_str += S.m_str; 
        return *this;
    }

    std::string operator+(const String &s) {
        return m_str + s.m_str;
    }

    std::string operator+(const std::string &s) {
        return m_str + s;
    }

    std::string operator+(const char* s) {
        return m_str + std::string(s);
    }

    String& operator+= (const std::string str) {
        this->m_str += str;
        return *this;
    }

    String& operator+= (const char* c) {
        std::string convert(c);
        this->m_str += convert;
        return *this;
    }

    String& operator+= (const char c) {
        this->m_str += c;
        return *this;
    }

    std::string operator*(String &s) {
        for(int i = 0; i < s.size(); i++) {
            m_str += s.m_str;
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

# CppString
STL header-only and generic string class/lib which is inspired by Java and C# string classes

## Targets
* simplify std::string usage
* STL only
* header only
* fully compatiblity to std::string 
* generic methods to avoid many method overloadings
* inheritable
* iterateable
* immutable

## Errors/Bugs
* nothing known

## Usage
```cpp
#include "String.h"
using String = str::String; // for convincence

int main() {
    String s = "Hello|World"; // can be used like std::string
    std::string std_str = s; 
    // vec includes vec[0] = "Hello", vec[1] = "World";
    std::vector<std::string> vec = s.split("|");
    s = s.toUpper(); // "HELLO|WORLD"
    s = s.addHead("  !").addTail("?  ");
    s = s.trim(); // "!HELLO|WORLD?"
    s.count("l"); // --> 3;
    std::vector<int> pos = s.find("l"); // 3, 4, 10
    s.findFirst("l"); // 3
    s = s.erase("ll"); // "!HEO|WORLD?"
    s = s.replaceFirst("!", "?") // "?HEO|WORLD?"
    s.isEmptyOrWhiteSpace(); // false
    s.swap(std_str); // s == "Hello|World"
    s.print(); 
    return 0;
}
```

## Reference
### Notice
Many operators and methods of String are templates. Each argument of const T<> can
be used with the types char, const char\*, std::string or String.
### Private Members
| Name   | Type        |
|--------|-------------|
| m\_str | std::string |

### Constructors
| Name                 | Description                                       	    |
|----------------------|--------------------------------------------------------|
| String()             | Initialize String with empty m\_str                  	|
| String(const char\*) | Loads const char\* into m\_str                        	|
| String(std::string)  | Loads std::string into m\_str                          |
| String(char)         | Loads char into m\_str                                	|
| String(int)          | Casts and loads int into m\_str                       	|
| String(long)         | Casts and loads long into m\_str                      	|
| String(float)        | Casts and loads float into m\_str                     	|
| String(double)       | Casts and loads double into m\_str                    	|
| String(bool)     	   | Initialize String with m\_str equal "true" or "false"	|

### Destructros
| Name      |                         |
|-----------|-------------------------|
| ~String() | Desturcts String object |

### Operators
| Operator              | Return Value          | Description                                                                         |
|-----------------------|-----------------------|-------------------------------------------------------------------------------------|
| std::string() const 	| std::string   	    | Writes m_str into std::string                                                       |
| =                   	| void          	    | Saves const char\*, std::string or String into internal std::string                 |
| ==                  	| bool          	    | Check if internal std::string is equal with const char\*, std::string or String     |
| !=                  	| bool          	    | Check if internal std::string is not equal with const char\*, std::string or String |
| +=                  	| String&       	    | Concatenates const char\*, std::string or String with internal std::string          |
| +                   	| String   	            | Concatenates String with const char\*, std::string or String                        |
| \*                   	| String   	            | Multiplies String n-times                                                           |
| \*=                   | String&               | Multiplies String n-times                                                           |
| /                     | std::vector<String>   | Divides String in n pieces and saves them in vector container                       |
| []                  	| char&         	    | Get char at the nth position                                                        |
| <<                  	| std::ostream& 	    | Prints a String to stdout in std::cout                                              |
| >>                  	| std::istream& 	    | Writes into String from stdin with help of std::cin                                 |

### Iterators
**Notice:** all iterators are renamed iterators from std::string

| Iterator  | Return Value              |
|-----------|---------------------------|
| begin()   | iterator                  |
| end()     | iterator                  |
| cbegin()  | const\_iterator           |
| cend()    | const\_iterator           |
| rbegin()  | reverse\_iterator         |
| rend()    | reverse\_iterator         |
| crbegin() | const\_reverse\_iterator  |
| crend()   | const\_reverse\_iterator  |

### Methods

#### Private
| Name                    | Return Value |	 Description                      |
|-------------------------|--------------|------------------------------------|
| getStdStr(char)	      | std::string  | Returns std::string from argument  |
| getStdStr(const char\*) | std::string  | Returns std::string from argument  |
| getStdStr(std::string)  | std::string  | Returns std::string from argument  |
| getStdStr(String)	      | std::string  | Returns std::string from argument  |

#### Public
| Name                             | Return Value         | Description                                                                                         |
|----------------------------------|----------------------|-----------------------------------------------------------------------------------------------------|
| addHead(const T<>)               | String               | Add substring on head of String                                                                   |
| addTail(const T<>)               | String               | Add substring on tail of String                                                                   |
| charAt(const int)                | char                 | Get character at specific position                                                                  |
| compare(const T<>)               | bool                 | Compares String with String or std::string                                                    |
| concat(const T<>)                | String               | Concats String with const char\*, std::string or String                                      |
| contains(const T<>)              | bool                 | Checks if String contains a specific substring                                                    |
| copyTo(String )                  | void                 | Saves reference of internal std::string to other internal std::string of String               |
| copyTo(std::string&)             | void                 | Saves reference of internal std::string to other std::string                                    |
| count(const T<>)                 | int                  | Returns number of occurences of const char\*, std::string or String argument in String       |
| endsWith(const T<>)              | bool                 | Checks if a String ends with a specific substring                                                 |
| equals(const T<>)                | bool                 | Alias to compare(const T<>)                                                                      |
| erase(const T<>)                 | String               | Erases all occurences of substring                                                                  |
| eraseFirst(const T<>)            | String               | Erases first occurence of substring                                                                 |
| eraseHead(int)                   | String               | Erases head of String                                                                             |
| eraseLast(const T<>)             | String               | Erases last occurence of substring                                                                  |
| eraseTail(int)                   | String               | Erases tail of String                                                                             |
| fillHead(const int, const char)  | String               | Fill head of String with number of characters                                                     |
| fillTail(const int, const char)  | String               | Fill tail of String with number of characters                                                     |
| find(const T<>)                  | std::vector<int>     | Search all occurences of substring and saves position of them in vector container                   |
| findAll(const T<>)               | std::vector<int>     | Alias of find(const T<>)                                                                         |
| findFirst(const T<>)             | int                  | Returns position of first occurence of substring                                                    |
| findLast(const T<>)              | int                  | Returns position of last occurence of substring                                                     |
| format(const T<>1, const T<>2)   | String               | Replaces {%} with given arguments                                                                   |
| indexOf(const T<>)               | int                  | Alias of findFirst(const T<>)                                                                     |
| isEmpty()                        | bool                 | Checks if String is empty string ""                                                             |
| isEmptyOrWhiteSpace()            | bool                 | Checks if String is empty string or string with WhiteSpaces only                                  |
| lastIndexOf(const T<>)           | int                  | Alias of findLast(const T<>)                                                                     |
| length()                         | int                  | Get length of String                                                                              |
| padLeft(const int, const char)   | String               | Alias for fillHead(const int, const char)                                                         |
| padRight(const int, const char)  | String               | Alias for fillTail(const int, const char)                                                         |
| print()                          | void                 | Prints String to stdout                                                                           |
| print(const T<>, const T<> = "") | void                 | Prints const char\*, std::string or String to stdout                                           |
| print(const T<> = "", const T<>, const T<>...) | void   | Prints n const char\*, std::string or String to stdout with specific separator                 |
| replace(const T<>)               | String               | Replaces all occurences of substring                                                                |
| replaceFirst(const T<>)          | String               | Replaces first occurence of substring                                                               |
| replaceHead(int, const T<>)      | String               | Replaces head of String with new substring                                                        |
| replaceLast(const T<>)           | String               | Replaces last occurence of substring                                                                |
| replaceTail(int, const T<>)      | String               | Replaces tail of String with new substring                                                        |
| reverse()                        | String               | Reverse String
| size()                           | int                  | Alias of length()                                                                                 |
| split(const T<>)                 | std::vector<String>  | Splits string with help of delimiter (char or string) into substrings and saves them in a container |
| startsWith(const T<>)            | bool                 | Checks if a String starts with a specific substring                                               |
| swap(std::string&)               | void                 | Swaps String and std::string                                                                    |
| swap(String &s)                  | void                 | Swaps String and String                                                                         |
| toBool()                         | bool                 | Casts String to bool (if "0", "false", "" then "false" else "true")                     |
| toCharArr()                      | std::vector<char>    | Returns container with characters                                                                   |
| toCStr()                         | const char\*         | Returns const char\* from String                                                                 |
| toStdStr()                       | String               | Returns internal std::string of String                                                          |
| toDouble()                       | double               | Returns double if String is numeric                                                               |
| toFloat()                        | float                | Returns float if String is numeric                                                                |
| toInt()                          | int                  | Returns Integer if String is numeric                                                              |
| toLong()                         | long                 | Returns Long if String is numeric                                                                 |
| toLower()                        | String               | Formats String to lower case                                                                      |
| toUpper()                        | String               | Formats String to upper case                                                                      |
| trim()                           | String               | Trims WhiteSpaces on                                                                                |
| trimHead()                       | String               | Trims WhiteSpaces at head of String                                                               |
| trimTail()                       | String               | Trims WhiteSpaces at tail of String                                                               |

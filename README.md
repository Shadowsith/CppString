# CppString
STL header-only and generic string class/lib which is orientated to Java and C# string classes

## Targets
* simplify `std::string` usage
* STL only
* header only
* fully compatiblity to `std::string` 
* generic methods to avoid many method overloadings
* inheritable

## Errors/Bugs
* nothing known

## Usage
```cpp
#include "String.h"

int main() {
    String s = "Hello|World"; // can be used like std::string
    std::string std_str = s; 
    // vec includes vec[0] = "Hello", vec[1] = "World";
    std::vector<std::string> vec = s.split("|");
    s.toUpper(); // "HELLO|WORLD"
    s.addLeft("  !").addRight("?  ");
    s.trim(); // "!HELLO|WORLD?"
    s.count("l"); // --> 3;
    std::vector<int> pos = s.find("l"); // 3, 4, 10
    s.findFirst("l"); // 3
    s.erase("ll"); // "!HEO|WORLD?"
    s.replaceFirst("!", "?") // "?HEO|WORLD?"
    s.isEmptyOrWhiteSpace(); // false
    s.swap(std_str); // s == "Hello|World"
    s.print(); 

    return 0;
}

```

## Reference
### Notice
Many operators and methods of String are templates. Each argument of `typename S` can
be used with the types `char`, `const char*`, `std::string` or `String`.
### Private Members
| Name    | Type            |
|---------|-----------------|
| `m_str` | `std::string`   |

### Constructors
| Name              	    | Description                                        	    |
|---------------------------|-----------------------------------------------------------|
| `String()`            	| Initialize `String` with empty m\_str                  	|
| `String(const char*)` 	| Loads `const char*` into m\_str                          	|
| `String(std::string)` 	| Loads `std::string` into m\_str                           |
| `String(char)`        	| Loads `char` into m\_str                                 	|
| `String(int)`         	| Casts and loads int into m\_str                       	|
| `String(long)`        	| Casts and loads long into m\_str                      	|
| `String(float)`       	| Casts and loads float into m\_str                     	|
| `String(double)`      	| Casts and loads double into m\_str                    	|
| `String(bool)`        	| Initialize `String` with m\_str equal "true" or "false"	|

### Operator
| Operator                 	| Return Value          | Descriptions                                                                               |
|--------------------------	|-----------------------|--------------------------------------------------------------------------------------------|
| `std::string() const` 	| `std::string`   	    | Writes m_str into `std::string`                                                            |
| `=`                   	| `void`          	    | Saves `const char*`, `std::string` or `String` into internal `std::string`                 |
| `==`                  	| `bool`          	    | Check if internal `std::string` is equal with `const char*`, `std::string` or `String`     |
| `!=`                  	| `bool`          	    | Check if internal `std::string` is not equal with `const char*`, `std::string` or `String` |
| `+=`                  	| `String&`       	    | Concatenates `const char*`, `std::string` or `String` with internal `std::string`          |
| `+`                   	| `String`   	        | Concatenates `String` with `const char*`, `std::string` or `String`                        |
| `*`                   	| `String`   	        | Multiplies `String` n-times                                                                |
| `*=`                      | `String&`             | Multiplies `String` n-times                                                                |
| `/`                       | `std::vector<String>` | Divides `String` in n pieces and saves them in vector container                            |
| `[]`                  	| `char&`         	    | Get `char` at the nth position                                                             |
| `<<`                  	| `std::ostream&` 	    | Prints a `String` to stdout in std::cout                                                   |
| `>>`                  	| `std::istream&` 	    | Writes into `String` from stdin with help of std::cin                                      |

### Methods

#### Private
| Name                        	                    | Return Value 	| Description                                                                                      |
|---------------------------------------------------|---------------|--------------------------------------------------------------------------------------------------|
| `getStdStr(char|const char*|std::string|String)`	| `std::string`	| Method template which returns `std::string` from char, `const char*`, `std::string` and `String` |

#### Public
| Name                               | Return Value           | Description                                                                                         |
|------------------------------------|------------------------|-----------------------------------------------------------------------------------------------------|
| `addLeft(typename S)`              | `String&`              | Add substring on head of `String`                                                                   |
| `addRight(typename S)`             | `String&`              | Add substring on tail of `String`                                                                   |
| `charAt(const int)`                | `char`                 | Get character at specific position                                                                  |
| `compare(typename S)`              | `bool`                 | Compares `String` with `String` or `std::string`                                                    |
| `concat(const typename S)`         | `String&`              | Concats `String` with `const char*`, `std::string` or `String`                                      |
| `copyTo(String&)`                  | `void`                 | Saves reference of internal `std::string` to other internal `std::string` of `String`               |
| `copyTo(std::string&)`             | `void`                 | Saves reference of internal `std::string` to other `std::string`                                    |
| `count(typename S)`                | `int`                  | Returns number of occurences of `const char*`, `std::string` or `String` argument in `String`       |
| `equals(typename S)`               | `bool`                 | Alias to `compare(typename S&)`                                                                     |
| `erase(typename S)`                | `String&`              | Erases all occurences of substring                                                                  |
| `eraseFirst(typename S)`           | `String&`              | Erases first occurence of substring                                                                 |
| `eraseHead(int)`                   | `String&`              | Erases head of `String`                                                                             |
| `eraseLast(typename S)`            | `String&`              | Erases last occurence of substring                                                                  |
| `eraseTail(int)`                   | `String&`              | Erases tail of `String`                                                                             |
| `fillLeft(const int, const char)`  | `String&`              | Fill head of `String` with number of characters                                                     |
| `fillRight(const int, const char)` | `String&`              | Fill tail of `String` with number of characters                                                     |
| `find(typename S)`                 | `std::vector<int>`     | Search all occurences of substring and saves position of them in vector container                   |
| `findAll(typename S)`              | `std::vector<int>`     | Alias of `find(typename S&)`                                                                        |
| `findFirst(typename S)`            | `int`                  | Returns position of first occurence of substring                                                    |
| `findLast(typename S)`             | `int`                  | Returns position of last occurence of substring                                                     |
| `format(typename S1, typename S2)` | `String&`              | Replaces `{%}` with argument                                                                        |
| `indexOf(typename S)`              | `int`                  | Alias of`findFirst(typename S&)`                                                                    |
| `isEmpty()`                        | `bool`                 | Checks if `String` is empty string `""`                                                             |
| `isEmptyOrWhiteSpace()`            | `bool`                 | Checks if `String` is empty string or string with WhiteSpaces only                                  |
| `lastIndexOf(typename S)`          | `int`                  | Alias of `findLast(typename S&)`                                                                    |
| `length()`                         | `int`                  | Get length of `String`                                                                              |
| `normPathUnix()`                   | `String&`              | Normalizes filepath for Unix based systems                                                          |
| `normPathWindows()`                | `String&`              | Normalizes filepath for Windows based systems                                                       |
| `padLeft(const int, const char)`   | `String&`              | Alias for `fillLeft(const int, const char)`                                                         |
| `padRight(const int, const char)`  | `String&`              | Alias for `fillRight(const int, const char)`                                                        |
| `print()`                          | `void`                 | Prints `String` to stdout                                                                           |
| `print(typename S, S = "")`        | `void`                 | Prints `const char*`, `std::string` or `String` to stdout                                           |
| `print(S = "", S, Strings)`        | `void`                 | Prints n `const char*`, `std::string` or `String` to stdout with specific separator                 |
| `replace(typename S)`              | `String&`              | Replaces all occurences of substring                                                                |
| `replaceFirst(typename S)`         | `String&`              | Replaces first occurence of substring                                                               |
| `replaceHead(int, typename S)`     | `String&`              | Replaces head of `String` with new substring                                                        |
| `replaceLast(typename S)`          | `String&`              | Replaces last occurence of substring                                                                |
| `replaceTail(int, typename S)`     | `String&`              | Replaces tail of `String` with new substring                                                        |
| `size()`                           | `int`                  | Alias of `length()`                                                                                 |
| `split(typename S)`                | `std::vector<String>`  | Splits string with help of delimiter (char or string) into substrings and saves them in a container |
| `swap(std::string&)`               | `void`                 | Swaps `String` and `std::string`                                                                    |
| `swap(String &s)`                  | `void`                 | Swaps `String` and `String`                                                                         |
| `toBool()`                         | `bool`                 | Casts `String` to bool (if `"0"`, `"false"`, `""` then `"false"` else `"true"`)                     |
| `toCharArr()`                      | `std::vector<char>`    | Returns container with characters                                                                   |
| `toCStr()`                         | `const char*`          | Returns `const char*` from `String`                                                                 |
| `toStdStr()`                       | `String&`              | Returns internal `std::string` of `String`                                                          |
| `toDouble()`                       | `double`               | Returns double if `String` is numeric                                                               |
| `toFloat()`                        | `float`                | Returns float if `String` is numeric                                                                |
| `toInt()`                          | `int`                  | Returns Integer if `String` is numeric                                                              |
| `toLong()`                         | `long`                 | Returns Long if `String` is numeric                                                                 |
| `toLower()`                        | `String&`              | Formats `String` to lower case                                                                      |
| `toUpper()`                        | `String&`              | Formats `String` to upper case                                                                      |
| `trim()`                           | `String&`              | Trims WhiteSpaces on                                                                                |
| `trimLeft()`                       | `String&`              | Trims WhiteSpaces at head of `String`                                                               |
| `trimRight()`                      | `String&`              | Trims WhiteSpaces at tail of `String`                                                               |

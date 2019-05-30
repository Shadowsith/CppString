# CppString
STL header-only and generic string class/lib which is orientated to Java and C# string classes

## Targets
* simplify std::string usage
* STL only
* fully compatiblity to std::string 
* generic methods to avoid lot of method overloading

## Errors/Bugs
* nothing known

## Usage

## Reference
### Notice
Many operators and methods of String are templates. Each argument of `typename S` can
be used with the types char, const char\*, std::string or String.
### Private Members
| Name  | Type        |
|-------|-------------|
| `m_str` | `std::string` |

### Constructors
| Name              	        | Description                                        	|
|---------------------      	|------------------------------------------------------	|
| `String()`            	| Initialize String with empty m\_str                  	|
| `String(const char*)` 	| Loads const char* into m\_str                       	|
| `String(std::string)` 	| Loads std::string into m\_str                        	|
| `String(char)`        	| Loads char into m\_str                               	|
| `String(int)`         	| Casts and loads int into m\_str                      	|
| `String(long)`        	| Casts and loads long into m\_str                     	|
| `String(float)`       	| Casts and loads float into m\_str                    	|
| `String(double)`      	| Casts and loads double into m\_str                   	|
| `String(bool)`        	| Initialize String with m\_str equal "true" or "false"	|

### Operator
| Operator                 	| Return Value      | Descriptions                                                                                                          |
|--------------------------	|-------------------|-----------------------------------------------------------------------------------------------------------------------|
| `std::string() const` 	| `std::string`   	| Writes m_str into std::string                                                                                        	|
| `=`                   	| `void`          	| Saves const char*, std::string or String into internal std::string                                                   	|
| `==`                  	| `bool`          	| Check if internal std::string is equal with const char*, std::string or String                                       	|
| `!=`                  	| `bool`          	| Check if internal std::string is not equal with const char*, std::string or String                                   	|
| `+=`                  	| `String&`       	| Concatenates const char*, std::string or String with internal std::string                                            	|
| `+`                   	| `std::string`   	| Concatenates String with const char*, std::string or String                                                          	|
| `*`                   	| `std::string`   	| Concatenates a const char*, std::string or String n-times.  n is the length of the const char*, std::string or String   |
| `[]`                  	| `char&`         	| Get char at the nth position                                                                                         	|
| `<<`                  	| `std::ostream&` 	| Prints a String to stdout in std::cout                                                                               	|
| `>>`                  	| `std::istream&` 	| Writes into String from stdin with help of std::cin                                                                  	|

### Methods

#### Private
| Name                        	                    | Return Value 	| Description                                                                              |
|---------------------------------------------------|---------------|------------------------------------------------------------------------------------------|
| `getStdStr(char|const char*|std::string|String)` 	| `std::string`	| Method template which returns std::string from char, const char*, std::string and String |

#### Public
| Name                               | Return Value               | Description                                                                                         |
|------------------------------------|----------------------------|-----------------------------------------------------------------------------------------------------|
| `addLeft(typename S)`              | `std::string`              | Add substring on head of String                                                                     |
| `addRight(typename S)`             | `std::string`              | Add substring on tail of String                                                                     |
| `charAt(const int)`                | `char`                     | Get character at specific position                                                                  |
| `compare(typename S)`              | `bool`                     | Compares String with String or std::string                                                          |
| `concat(const typename S)`         | `std::string`              | Concats String with const char*, std::string or String                                               |
| `copyTo(String&)`                  | `void`                     | Saves reference of internal std::string to other internal std::string of String                     |
| `copyTo(std::string&)`             | `void`                     | Saves reference of internal std::string to other std::string                                        |
| `count(typename S)`                | `int`                      | Returns number of occurences of const char*, std::string or String argument in String                |
| `equals(typename S)`               | `bool`                     | Alias to `compare(typename S&)`                                                                     |
| `erase(typename S)`                | `std::string`              | Erases all occurences of substring                                                                  |
| `eraseFirst(typename S)`           | `std::string`              | Erases first occurence of substring                                                                 |
| `eraseHead(int)`                   | `std::string`              | Erases head of String                                                                               |
| `eraseLast(typename S)`            | `std::string`              | Erases last occurence of substring                                                                  |
| `eraseTail(int)`                   | `std::string`              | Erases tail of String                                                                               |
| `fillLeft(const int, const char)`  | `std::string`              | Fill head of String with number of characters                                                       |
| `fillRight(const int, const char)` | `std::string`              | Fill tail of String with number of characters                                                       |
| `find(typename S)`                 | `std::vector<int>`         | Search all occurences of substring and saves position of them in vector Container                   |
| `findAll(typename S)`              | `std::vector<int>`         | Alias of `find(typename S&)`                                                                        |
| `findFirst(typename S)`            | `int`                      | Returns position of first occurence of substring                                                    |
| `findLast(typename S)`             | `int`                      | Returns position of last occurence of substring                                                     |
| `format(typename S1, typename S2)` | `std::string`              | Replaces `{%}` with argument                                                                        |
| `indexOf(typename S)`              | `int`                      | Alias of`findFirst(typename S&)`                                                                    |
| `isEmpty()`                        | `bool`                     | Checks if String is empty string `""`                                                               |
| `isEmptyOrWhiteSpace()`            | `bool`                     | Checks if String is empty string or string with WhiteSpaces only                                    |
| `lastIndexOf(typename S)`          | `int`                      | Alias of `findLast(typename S&)`                                                                    |
| `length()`                         | `int`                      | Get length of String                                                                                |
| `normPathUnix()`                   | `std::string`              | Normalizes filepath for Unix based systems                                                          |
| `normPathWindows()`                | `std::string`              | Normalizes filepath for Windows based systems                                                       |
| `padLeft(const int, const char)`   | `std::string`              | Alias for `fillLeft(const int, const char)`                                                         |
| `padRight(const int, const char)`  | `std::string`              | Alias for `fillRight(const int, const char)`                                                        |
| `replace(typename S)`              | `std::string`              | Replaces all occurences of substring                                                                |
| `replaceFirst(typename S)`         | `std::string`              | Replaces first occurence of substring                                                               |
| `replaceHead(int, typename S)`     | `std::string`              | Replaces head of String with new substring                                                          |
| `replaceLast(typename S)`          | `std::string`              | Replaces last occurence of substring                                                                |
| `replaceTail(int, typename S)`     | `std::string`              | Replaces tail of String with new substring                                                          |
| `size()`                           | `int`                      | Alias of `length()`                                                                                 |
| `split(typename S)`                | `std::vector<std::string>` | Splits string with help of delimiter (char or string) into substrings and saves them in a container |
| `swap(std::string&)`               | `void`                     | Swaps String and std::string                                                                        |
| `swap(String &s)`                  | `void`                     | Swaps String and String                                                                             |
| `toBool()`                         | `bool`                     | Casts String to bool (if `"0"`, `"false"`, `""` then "false" else "true")                           |
| `toCharArr()`                      | `std::vector<char>`        | Returns container with characters                                                                   |
| `toCStr()`                         | `const char*`               | Returns const char\* from String                                                                   |
| `toStdStr()`                       | `std::string`              | Returns internal std::string of String                                                              |
| `toDouble()`                       | `double`                   | Returns double if String is numeric                                                                 |
| `toFloat()`                        | `float`                    | Returns float if String is numeric                                                                  |
| `toInt()`                          | `int`                      | Returns Integer if String is numeric                                                                |
| `toLong()`                         | `long`                     | Returns Long if String is numeric                                                                   |
| `toLower()`                        | `std::string`              | Formats String to lower case                                                                        |
| `toUpper()`                        | `std::string`              | Formats String to upper case                                                                        |
| `trim()`                           | `std::string`              | Trims WhiteSpaces on                                                                                |
| `trimLeft()`                       | `std::string`              | Trims WhiteSpaces at head of String                                                                 |
| `trimRight()`                      | `std::string`              | Trims WhiteSpaces at tail of String                                                                 |

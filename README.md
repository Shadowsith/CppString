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
### Private Members
| Name  | Type        |
|-------|-------------|
| ```m_str``` | ```std::string``` |

### Constructors
| Name              	        | Description                                        	|
|---------------------      	|------------------------------------------------------	|
| ```String()```            	| Initialize String with empty m\_str                  	|
| ```String(const char*)``` 	| Loads const char* into m\_str                       	|
| ```String(std::string)``` 	| Loads std::string into m\_str                        	|
| ```String(char)```        	| Loads char into m\_str                               	|
| ```String(int)```         	| Casts and loads int into m\_str                      	|
| ```String(long)```        	| Casts and loads long into m\_str                     	|
| ```String(float)```       	| Casts and loads float into m\_str                    	|
| ```String(double)```      	| Casts and loads double into m\_str                   	|
| ```String(bool)```        	| Initialize String with m\_str equal "true" or "false"	|

### Operator
| Operator                  	| Return Value        	| Descriptions                                                                                                          	|
|---------------------------	|---------------------	|-----------------------------------------------------------------------------------------------------------------------	|
| ```std::string() const``` 	| ```std::string```   	| Writes m_str into std::string                                                                                         	|
| ```=```                   	| ```void```          	| Saves const char*, std::string or String into internal std::string                                                    	|
| ```==```                  	| ```bool```          	| Check if internal std::string is equal with const char*, std::string or String                                        	|
| ```!=```                  	| ```bool```          	| Check if internal std::string is not equal with const char*, std::string or String                                    	|
| ```+=```                  	| ```String&```       	| Concatenates const char*, std::string or String with internal std::string                                             	|
| ```+```                   	| ```std::string```   	| Concatenates String with const char*, std::string or String                                                           	|
| ```*```                   	| ```std::string```   	| Concatenates a const char*, std::string or String n-times.  n is the length of the const char*, std::string or String 	|
| ```[]```                  	| ```char&```         	| Get char at the nth position                                                                                          	|
| ```<<```                  	| ```std::ostream&``` 	| Prints a String to stdout in std::cout                                                                                	|
| ```>>```                  	| ```std::istream&``` 	| Writes into String from stdin with help of std::cin                                                                   	|

### Methods
#### Private
| Name                        	| Return Value 	| Description                                                                                                                                                     	|
|-----------------------------	|--------------	|-----------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| ```getStdStr(typename S)``` 	| std::string  	| Method template which retruns std::string from const char*, std::string and String. If another type is given it will throw  an std::invalid_argument exception. 	|
| ```getStdStr(char c)```     	| std::string  	| Casts a char into std::string                                                                                                                                   	|

#### Public
| Name                         | Return Value | Description                                            |
|------------------------------|--------------|--------------------------------------------------------|
| ```charAt(const int)```      | char         |                                                        |
| ```compare(typename S &s)``` | bool         | Compares String with String or std::string             |
| ```compare(const char*)```   | bool         | Compares String with const char*                       |
| ```concat(const S &s)```     | std::string  | Concats String with const char*, std::string or String |
| ``` ```                      |              |                                                        |




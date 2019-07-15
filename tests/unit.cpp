#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../String.h"
#include <cstring>
#include <vector>
using String = str::String;

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Casts are executed", "[casts]" ) {
    REQUIRE( String(5).toInt() == 5 );
    REQUIRE( String(70000).toLong() == 70000 );
    REQUIRE( String(5.5f).toFloat() == 5.5f );
    REQUIRE( String(5.5).toDouble() == 5.5 );
    REQUIRE( String(false).toBool() == false );
    REQUIRE( String("hey").toStdStr() == std::string("hey") );
    REQUIRE( std::strcmp(String("hey").toCStr(), "hey") == 0 );
}

TEST_CASE( "String comparison", "[strcmp]" ) {
    String s("hello");
    std::string str = "hello";
    const char* c = "hello";
    REQUIRE( s == str );
    REQUIRE( s == c );
    REQUIRE( s.compare(str) );
    REQUIRE( s.equals(str) );
    REQUIRE( s.compare(c) );
    REQUIRE( s.equals(c) );
}

TEST_CASE( "String intercast" "[strcast]" ) {
    String s = "";
    const char* c = "hello";
    s = c;
    REQUIRE( s == String("hello") );
    std::string str = "hey";
    s = str;
    REQUIRE( s == String("hey") );
    s = c;
    str = s;
    REQUIRE(std::string("hello") == str );
}

TEST_CASE( "String splitting", "[split]" ) {
   String s = "hello world you are great!";
   std::vector<String> vec = s.split(" ");
   REQUIRE( vec[0] == "hello" );
   REQUIRE( vec[1] == "world" );
   REQUIRE( vec[2] == "you" );
   REQUIRE( vec[3] == "are" );
   REQUIRE( vec[4] == "great!" );
}

TEST_CASE( "String iteration", "[iterator]" ) {
    String s = "hello world";
    std::string str = "hello world";
    int i = 0;
    for(char c : s) {
        REQUIRE( c == str[i] );
        i++;
    }
}

TEST_CASE( "String empty or whitspace", "[empty]" ) {
    String s = "";
    REQUIRE( s.isEmpty() );
    s = "      ";
    REQUIRE( s.isEmptyOrWhiteSpace() );
}

TEST_CASE( "String lenght", "[length]" ) {
    REQUIRE( String("hey").length() == 3 );
    REQUIRE( String("hello").size() == 5 );
}

TEST_CASE( "String Copy and Swap", "[swap]" ) {
    std::string str;
    String("hello").copyTo(str);
    REQUIRE( str == "hello" );
    String s = "hey you";
    s.swap(str);
    REQUIRE(s == "hello");
    REQUIRE(str == "hey you");
}

TEST_CASE( "String char at", "[char_at]" ) {
    String s = "hey";
    REQUIRE(s.charAt(2) == 'y');
}

TEST_CASE( "String insert", "[insert]" ) {
    String s = "hello";
    std::string str = "world ";
    REQUIRE(s.insert(0, str) == "world hello");
    REQUIRE(s.insert(0, "world ") == "world hello");
}

TEST_CASE( "String find, contains", "[find]" ) {
    String s = "hello world!";
    REQUIRE( s.findFirst("e") == 1 );
    REQUIRE( s.indexOf(std::string("ello")) == 1 );
    REQUIRE( s.findLast("l") == 9 );
    REQUIRE( s.lastIndexOf(String("l")) == 9 );
    REQUIRE( s.find("l").size() == 3 );
    REQUIRE( s.find("o")[0] == 4 );
    REQUIRE( s.find("o")[1] == 7 );
    REQUIRE( s.contains("world") == true );
    REQUIRE( s.count("l") == 3 );
}

TEST_CASE( "String erase", "[erase]" ) {
    String s = "hello world, hello space";
    REQUIRE(s.erase("hello ") == "world, space" );
    REQUIRE(s.eraseFirst(std::string("hello ")) == "world, hello space");
    REQUIRE(s.eraseLast(String("hello ")) == "hello world, space");
    REQUIRE(s.eraseHead(6) == "world, hello space");
    REQUIRE(s.eraseTail(13) == "hello world");
}

TEST_CASE( "String replace", "[replace]" ) {
    String s = "hello world, hello space";
    REQUIRE(s.replace("hello", "hey") == "hey world, hey space");
    REQUIRE(s.replaceFirst("world", std::string("earth")) == "hello earth, hello space");
    REQUIRE(s.replaceLast("hello", String("hey")) == "hello world, hey space");
    REQUIRE(s.replaceHead(5, "hey") == "hey world, hello space");
    REQUIRE(s.replaceTail(5, "moon") == "hello world, hello moon");
}

TEST_CASE( "String trim", "[trim]" ) {
    String s = "   hello  ";
    REQUIRE( s.trim() == "hello" );
    s = "  hello  ";
    REQUIRE( s.trimHead() == "hello  " );
    s = " hello  ";
    REQUIRE( s.trimTail() == " hello" );
}

TEST_CASE( "String lower/upper", "[lower/upper]" ) {
    REQUIRE(String("HELLO").toLower() == "hello");
    REQUIRE(String("hello").toUpper() == "HELLO");
}

TEST_CASE( "String operators", "[operators]" ) {
    String s0 = "hey";
    std::string str = "hey";
    REQUIRE(String("hello") == String("hello"));
    REQUIRE(s0 < "hello");
    REQUIRE(String("hello") > str);
    REQUIRE(String("hello") <= "hello");
    REQUIRE(String("hello") >= std::string("hey"));
    REQUIRE((String("he") += "llo") == "hello");
    REQUIRE((String("he") + "llo") == "hello"); 
    REQUIRE((String("he") * 3) == "hehehe");
    REQUIRE((String("he") *= 2) == std::string("hehehehe"));
    REQUIRE((String("hello") / 5).size() == 5);
    REQUIRE((String("hello") / 5)[0] == 'h');
    REQUIRE(String("world")[0] == 'w');
}

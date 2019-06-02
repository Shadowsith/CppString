#include "../String.h"
#include "./lib/textformatpp.h"

void message(bool condition, std::string msg) {
    if(condition) {
        std::cout << text::green("ACCEPT: ") << text::green(msg) << std::endl;
    } else {
        std::cout << text::red("DENIED: ") << text::red(msg) << std::endl;
    }
}

void t_construct() {
    String s1("hallo");
    String s2('h');
    String s3(std::string("hallo"));
    String s4(5);
    String s5(5.0);

    message(s1 == s3 && s2 == "h" && s4 == "5" && s5 == "5.000000", "contructor");
}

void t_toStdStr() {
    message(String("hallo").toStdStr() == std::string("hallo"),
            "toStdStr");

} 

void t_toCStr() {
    const char* c = "hallo";
    String s("hallo");
    message(s == c, "toCStr");
}

void t_casts() {
    int i = 5;
    long l = 5;
    float f = 5.5;
    double d = 5.5;
    bool b = false;

    bool res = true;

    res = res == (String(i).toInt() == 5);
    res = res == (String(l).toLong() == 5);
    res = res == (String(f).toFloat() == 5.5);
    res = res == (String(d).toDouble() == 5.5);
    res = res == (String(b).toBool() == b);
    message(res, "casting");
}

void t_toCArr() {
    std::string s = "hallo";
    std::vector<char> vec = String("hallo").toCharArr();
    std::vector<char> tvec;
    for(char c : s) {
        tvec.push_back(c);
    }
    message(vec == tvec, "toCArr");
} 

void t_charAt() {
    String s("hello");
    message(s.charAt(2) == 'l', "charAt");
}

void t_empty() {
    message(String("").isEmpty(), "isEmpty");
}

void t_emptyOrWS() {
    message(String("   ").isEmptyOrWhiteSpace() 
            && String("").isEmptyOrWhiteSpace(),
            "isEmptyOrWhiteSpace");
}

void t_compare_equals() {
    String s = "You are great";
    String st = "You are great";
    std::string str = "You are great";
    message(s.compare(st) && s.compare(str), "compare/equals");
}

void t_length_size() {
    String s = "hallo";
    std::string str = "hallo";
    message(s.length() == str.length(), "length/size");
}

void t_concat() {
    String s1 = String("hello").concat(String(" you"));
    String s2 = String("hello you");
    bool t1 = s1 == s2;
    bool t2 = s1 == std::string("hello you");
    message(t1 == t2, "concat");
}

void t_copyTo() {
    std::string str;
    String("hello").copyTo(str);
    message(str == "hello", "copyTo");

}

void t_count() {
    String s1("l");
    std::string s2 = "l";
    String s3("hello");
    bool t1 = s3.count(s1) == 2;
    bool t2 = s3.count(s2) == 2;
    bool t3 = s3.count("l") == 2;
    message(t1 == t2 == t3, "count");
}

void t_find_findAll() {
    static const int arr[] = {2, 3}; // 2 and 3 are pos of 'l' in hello
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<int> vec1 = String("hello").find("l");
    std::vector<int> vec2 = String("hello").find(std::string("l"));
    std::vector<int> vec3 = String("hello").find(String("l"));

    bool t1 = vec == vec1;
    bool t2 = vec == vec2;
    bool t3 = vec == vec3;

    message(t1 == t2 == t3, "find/findAll");
}

void t_findFirst_indexOf() {
    int i = 4;
    String s("hello you");
    int i1 = s.findFirst("o");
    int i2 = s.findFirst(std::string("o"));
    int i3 = s.findFirst(String("o"));
    bool t = (i == i1) && (i == i2) && (i == i3);

    message(t, "findFirst/indexOf");
}

void t_findLast_lastIndexOf() {
    int i = 7;
    String s("hello you");
    int i1 = s.findLast("o");
    int i2 = s.findLast(std::string("o"));
    int i3 = s.findLast(String("o"));
    bool t = (i == i1) && (i == i2) && (i == i3);

    message(t, "findLast/lastIndexOf");
}

void t_replace() {
    std::string res = "hi you, hi there";
    String s = "hello you, hello there";
    String s1 = "hello you, hello there";
    String s2 = "hello";
    String s3 = "hi";
    std::string s4 = "hello";
    std::string s5 = "hi";

    bool t1 = s1.replace(s2, s3) == res;
    s1 = s;
    bool t2 = s1.replace(s4, s5) == res;
    s1 = s;
    bool t3 = s1.replace("hello", "hi") == res;

    message(t1 == t2 == t3, "replace");
}

void t_replaceFirst() {
    std::string res = "hi you, hello there";
    String s = "hello you, hello there";
    String s1 = "hello you, hello there";
    String s2 = "hello";
    String s3 = "hi";
    std::string s4 = "hello";
    std::string s5 = "hi";

    bool t1 = s1.replaceFirst(s2, s3) == res;
    s1 = s;
    bool t2 = s1.replaceFirst(s4, s5) == res;
    s1 = s;
    bool t3 = s1.replaceFirst("hello", "hi") == res;

    message(t1 == t2 == t3, "replaceFirst");
}

void t_replaceLast() {
    std::string res = "hello you, hi there";
    String s = "hello you, hello there";
    String s1 = "hello you, hello there";
    String s2 = "hello";
    String s3 = "hi";
    std::string s4 = "hello";
    std::string s5 = "hi";

    bool t1 = s1.replaceLast(s2, s3) == res;
    s1 = s;
    bool t2 = s1.replaceLast(s4, s5) == res;
    s1 = s;
    bool t3 = s1.replaceLast("hello", "hi") == res;

    message(t1 == t2 == t3, "replaceLast");
}

void t_replaceHead() {
    std::string res = "hey here, hi there";
    String s = "hello you, hi there";
    String s1 = "hello you, hi there";
    const int head = 9;
    String s2 = "hey here";
    std::string s3 = "hey here";

    bool t1 = s1.replaceHead(head, s2) == res;
    s1 = s;
    bool t2 = s1.replaceHead(head, s3) == res;
    s1 = s;
    bool t3 = s1.replaceHead(head, "hey here") == res;

    message(t1 == t2 == t3, "replaceHead");
}

void t_replaceTail() {
    std::string res = "you are great and cool";
    String s = "you are great and nice";
    String s1 = "you are great and nice";
    const int tail = 4;
    String s2 = "cool";
    std::string s3 = "cool";

    bool t1 = s1.replaceTail(tail, s2) == res;
    s1 = s;
    bool t2 = s1.replaceTail(tail, s3) == res;
    s1 = s;
    bool t3 = s1.replaceTail(tail, "cool") == res;

    message(t1 == t2 == t3, "replaceTail");
}

void t_erase() {
    std::string res = "hey you are good and cool";
    String s = "hey you are not good and not cool";
    String s1 = "hey you are not good and not cool";
    String s2 = "not ";
    std::string s3 = "not ";

    bool t1 = s1.erase(s2) == res;
    s1 = s;
    bool t2 = s1.erase(s3) == res;
    s1 = s;
    bool t3 = s1.erase("not ") == res;

    message(t1 == t2 == t3, "erase");
}

void t_eraseFirst() {
    std::string res = "hey you are good and not cool";
    String s = "hey you are not good and not cool";
    String s1 = "hey you are not good and not cool";
    String s2 = "not ";
    std::string s3 = "not ";

    bool t1 = s1.eraseFirst(s2) == res;
    s1 = s;
    bool t2 = s1.eraseFirst(s3) == res;
    s1 = s;
    bool t3 = s1.eraseFirst("not ") == res;

    message(t1 == t2 == t3, "eraseFirst");
}

void t_eraseLast() {
    std::string res = "hey you are not good and cool";
    String s = "hey you are not good and not cool";
    String s1 = "hey you are not good and not cool";
    String s2 = "not ";
    std::string s3 = "not ";

    bool t1 = s1.eraseLast(s2) == res;
    s1 = s;
    bool t2 = s1.eraseLast(s3) == res;
    s1 = s;
    bool t3 = s1.eraseLast("not ") == res;

    message(t1 == t2 == t3, "eraseLast");
}

void t_eraseHead() {
    std::string res = "you are not good and not cool";
    String s = "hey you are not good and not cool";
    const int head = 4;

    bool t1 = s.eraseHead(head) == res;

    message(t1, "eraseHead");
}

void t_eraseTail() {
    std::string res = "hey you are not good and not";
    String s = "hey you are not good and not cool";
    const int tail = 5;

    bool t1 = s.eraseHead(tail) == res;

    message(t1, "eraseTail");
}

void t_split() {
    static const String arr[] = {"you", "are", "the", "greatest"}; 
    std::vector<String> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    String s = "you are the greatest";

    std::string ds = " ";
    String dS = " ";
    const char* dcst = " ";
    char dc = ' '; 

    std::vector<String> vec1 = s.split(ds);
    std::vector<String> vec2 = s.split(dS);
    std::vector<String> vec3 = s.split(dcst);
    std::vector<String> vec4 = s.split(dc);
    std::vector<String> vec5 = s.split(" ");
    std::vector<String> vec6 = s.split(' ');
    bool t0 = vec1 == vec2;

    bool t1 = (vec == vec1) && (vec == vec2) && (vec == vec3) && (vec == vec4);
    bool t2 = (vec == vec5) && (vec == vec6);

    message(t1 == t2, "split");
}

void t_swap() {
    String s1 = "hallo";
    String s2 = "bye";
    s1.swap(s2);

    String s3 = "ciao";
    std::string s4 = "see you";
    s3.swap(s4);

    bool t1 = (s1 == "bye") && (s2 == "hallo");
    bool t2 = (s3 == "see you") && (s4 == "ciao");
    message(t1 == t2, "swap");
}

void t_toUpper() {
    String s = "hello";
    s.toUpper();
    message(s == "HELLO", "toUpper");
}

void t_toLower() {
    String s = "HELLO";
    s.toLower();
    message(s == "hello", "toLower");
}

void t_trim() {
    String s = "   hello     ";
    s.trim();
    message(s == "hello", "trim");
}

void t_trimLeft() {
    String s = "   hello     ";
    s.trimLeft();
    message(s == "hello     ", "trimLeft");
}

void t_trimRight() {
    String s = "   hello     ";
    s.trimRight();
    message(s == "   hello", "trimRight");
}

void t_fillLeft_padLeft() {
    String s = "111";
    s.fillLeft(3,'X');
    message(s == "XXX111", "fillLeft/padLeft");
}

void t_fillRight_padRight() {
    String s = "111";
    s.fillRight(3, 'X');
    message(s == "111XXX", "fillRight/padRigth");
}

void t_op_declaration() {
    String s("hello");
    std::string str = s; 
    message(s == str, "Operator=");
}

void t_op_equal() {
    String s("hello");
    message(s == "hello" && s == std::string("hello"), "Operator==");
}

void t_op_unequal() {
    String s("hello");
    message(s != "hallo" || s != std::string("hallo"), "Operator!=");
}

void t_op_smallerThan() {
    String s0("hello");
    String s1("helloWorld");
    message(s0 < s1, "Operator<");
}

void t_op_smallerEq() {
    String s0("hello");
    String s1("hello");
    String s2("helloWorld");
    message(s0 < s2 && s0 <= s1, "Operator<=");
}

void t_op_greaterThan() {
    String s0("hello");
    String s1("helloWorld");
    message(s1 > s0, "Operator>");
}

void t_op_greaterEq() {
    String s0("hello");
    String s1("hello");
    String s2("helloWorld");
    message(s2 > s1 && s0 >= s1, "Operator>=");
}

void t_op_outstream() {
    std::cout << text::green(String("ACCEPT: Operator<<").toStdStr()) << std::endl;
}

void t_op_brackets() {
    String s("hello");
    message(s[0] == 'h', "Operator[]");
}

void t_op_plus() {
    String s;
    s = String("he") + std::string("ll") + "o";
    message(s == "hello", "Operator+");
}

void t_op_plusEqual() {
    String s("hell");
    s += std::string("o");
    message(s == "hello", "Operator+=");
}

void t_stdin() {
    std::cout << "Write 'hello' to check if cin works correctly:" << std::endl;
    String s;
    std::cin >> s;
    message(s == "hello", "cin");
}

int main(void)
{
    std::cout << std::endl << "Operator Tests:" << std::endl;
    t_op_declaration();
    t_op_equal();
    t_op_unequal();
    t_op_smallerThan();
    t_op_smallerEq();
    t_op_greaterThan();
    t_op_greaterEq();
    t_op_outstream();
    t_op_brackets();
    t_op_plus();
    t_op_plusEqual();

    std::cout << std::endl << "Method Tests:" << std::endl;
    t_construct();
    t_toStdStr();
    t_toCStr();
    t_toCArr();
    t_casts();
    t_charAt();
    t_empty();
    t_emptyOrWS();
    t_compare_equals();
    t_length_size();
    t_concat();
    t_copyTo();
    t_find_findAll();
    t_findFirst_indexOf();
    t_findLast_lastIndexOf();
    t_replace();
    t_replaceFirst();
    t_replaceLast();
    t_replaceHead();
    t_replaceTail();
    t_erase();
    t_eraseFirst();
    t_eraseLast();
    t_split();
    t_swap();
    t_toUpper();
    t_toLower();
    t_trim();
    t_trimLeft();
    t_trimRight();
    t_fillLeft_padLeft();
    t_fillRight_padRight();
    t_stdin();

    std::cout << std::endl;

}

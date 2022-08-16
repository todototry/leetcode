#include<iostream>
#include<string>
#include<queue>

#include<algorithm>

void func_print_str(std::string s){
 std::cout << " " << s << " ";
}

int main(int argc, char* args[]){

    std::priority_queue<std::string> words;
    //std::string word; std::cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
    // while (true)
    // {
    //     if ((std::cin >> word).eof())
    //         break;
    //     words.push(word);
    // }

    words.push("1");
    words.push("2");
    words.push("3");
    words.push("4");
    words.push("5");


    while(words.size() != 0){
        func_print_str(words.top());
        words.pop();
    }
    

    // 最小堆？
    std::vector<int> values{21, 22, 12, 3, 24, 54, 56};
    std::priority_queue<int> numbers {std::less<int>(),values};

    // 
    std:: string wrds[]  {"one", "two", "three", "four"};
    std:: string wrds2[] = {"one", "two", "three", "four"};

    // 使用functor，元函数 greater
    std::priority_queue<std::string, std::vector<std::string>,std::greater<std::string>> words1 {std::begin (wrds) , std:: end (wrds) };
    
    // 使用functor，元函数 less
    std::priority_queue<std::string, std::vector<std::string>,std::less<std::string>> words2 {std::begin (wrds) , std:: end (wrds) };
    

    // 使用自定义的函数 lambda ?
    

}
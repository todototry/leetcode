#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    // 若不设置随机种子，每次启动后的随机结果将是 同一个值。
    srand(time(nullptr));
    
    int random_number = std::rand() % 10; // rand() return a number between ​0​ and RAND_MAX
    std::cout << random_number;
     random_number = std::rand() % 10; // rand() return a number between ​0​ and RAND_MAX
    std::cout << random_number;
     random_number = std::rand() % 10; // rand() return a number between ​0​ and RAND_MAX
    std::cout << random_number;
    return 0;
}

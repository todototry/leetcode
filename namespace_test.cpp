#include <iostream>
using namespace std;
 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}

// 第二个命名空间
namespace second_space{
   void func2(){
      cout << "Inside second_space" << endl;
   }
}

using namespace second_space;
int main ()
{
 
   // 调用第一个命名空间中的函数
   func2();
   
   return 0;
}
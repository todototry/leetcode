/*

c++ 各个版本: 
https://en.cppreference.com/w/cpp

 入口：全局概要介绍
1. 全局搞清楚：stl 全局的功能分类，包含 容器+迭代器 + 算法、
    1. 知道各类容器的分类特点，常用接口，使用的#include头文件。
        a. https://zhuanlan.zhihu.com/p/130905242
        b. https://zhuanlan.zhihu.com/p/381607411
        c. https://zhuanlan.zhihu.com/p/226014048
    2. 知道迭代器的用法；初始化 https://zhuanlan.zhihu.com/p/112810801
    3. 知道算法相关的两个 include 头文件
2. 参考herongwei： stl算法总结
    1. 记忆：algorithm 和 numeric 、functional 三个头文件内的作用，分类
    2. 组织各个stl 算法的功能分类，记忆常见功能的使用
3. 图解stl算法：参考Anthony的 105个高阶算法使用：
    1. 总结 stl中的algorithm的 高阶算法：
        1. 排列permutation
        2. heap 最大堆的创建和使用
        3. 分区partition
        4. copy move等
4. 最大堆、红黑树在 容器内的使用，如：priority_queue基于最大堆， map/set基于红黑树，如何自己设计最大堆？
5. 总结 各类容器特点：使用场景、基本原理、特别点


1. [C++ STL] 各容器简单介绍 - luckyum的文章 - 知乎
https://zhuanlan.zhihu.com/p/130905242


2. 万字长文 | STL 算法总结 - herongwei的文章 - 知乎
https://zhuanlan.zhihu.com/p/381607411

3. 一小时介绍105 个STL算法 - 黄亮anthony的文章 - 知乎
https://zhuanlan.zhihu.com/p/79088038


C++知识总结——STL容器的常用用法（持续更新） - KarK.Li的文章 - 知乎
https://zhuanlan.zhihu.com/p/112810801

【算法部分】
一小时介绍105 个STL算法 - 黄亮anthony的文章 - 知乎
https://zhuanlan.zhihu.com/p/79088038

在算法竞赛中 C++ 的 STL 库有哪些奇技淫巧? - KEKE的回答 - 知乎
https://www.zhihu.com/question/279836178/answer/423011086

stl 算法总览
https://mp.weixin.qq.com/s?__biz=MzIzNzg5MDg0OA==&mid=2247487810&idx=1&sn=4e4a2c64f27a07c9dd287e934eda8089&chksm=e8c0ed0ddfb7641b556954af6b7a90af694956d3d5ffa62f9d6d4a9bfa2658366aa3dda23227&cur_album_id=1628517353149825024&scene=189#wechat_redirect
stl序列式容器：
https://mp.weixin.qq.com/s?__biz=MzIzNzg5MDg0OA==&mid=2247486807&idx=1&sn=b0e0a5caed92add7b9f3bb961adad49f&chksm=e8c0f118dfb7780eaff8fdc1dc633db5e7a37d92b5303767cfd31159e3f3f769932c9bf98987&scene=21#wechat_redirect

stl 关联式容器
https://mp.weixin.qq.com/s?__biz=MzIzNzg5MDg0OA==&mid=2247487781&idx=1&sn=9947e10604bc3cd65b96a88e0ab23c13&chksm=e8c0ed6adfb7647c08da85d6ead93c0c3e08492ea65d6745178e30262cfd93ca4d9d385f83bd&scene=21#wechat_redirect

如何能熟练掌握STL？ - 黑马程序员的回答 - 知乎
https://www.zhihu.com/question/37786833/answer/2287955649

GitHub开源stl 算法图解
https://github.com/rongweihe/CPPNotes/tree/master/STL-source-code-notes
*/


#include<iostream>
//辅助工具类、str/
#include<cstring>

//序列容器, 只包含以下几个类：
#include<string> // str.c_str()
#include<array>  // 数组
#include<vector> // 适合插入尾部 
#include<deque> //适合头部、尾部插入
#include<list>  //双向链表 list，适合：任意点插入
#include<forward_list> //单向链表 forward_list

//有序关联pair容器： 只包含以下类
#include<set> //基于红黑树实现，有序排列
#include<map> //基于红黑树实现，有序排列
// #ifdef __GNUC__
// #include<ext/hash_map>
// #else
// #include<hash_map>
// #endif

//无序关联pair容器
#include<unordered_map> //基于hash函数模板，生成桶id，插入到桶内。
#include<unordered_set> //同上， hash 与 桶接口


//适配器 adapter
#include<stack> 
#include<queue> 


// 算法
#include<algorithm> // 常规集合间的 for_each/ find / search / fill / sort / unique / merge / make_heap / remove /reverse / 
#include<numeric>  // 数值集合的 accumulate / reduce / transform/
#include<functional>  // 仿函数

// 基于时间的随机数
#include<time.h>

using namespace std;
//using namespace stdext;

void func_print(int x){
    printf("%d ", x);
}

void func_print_str(string x){
    printf("%s ", x.c_str());
}


int main(int argc, char ** argv){
    //std::cout<<"args count:" << argc << argv[0] <<std::endl;
    // 支持时间随机数
    // 初始化时间随机数
    srand(time(0));
    cout << rand() << endl;

    // string
    string s = "中文";  
    
    printf("%s", s); //乱码
    printf("%s", s.c_str()); //正常

    //CString
    printf("strlen的长度 %d \n", std::strlen(s.c_str()));

    // vector
    vector<int> vecTemp;
    // vecTemp[0] = 1;
    // vecTemp[1] = 2;
    vecTemp.push_back(1);
    vecTemp.push_back(2);
    printf("vec[1]=%d  \n", vecTemp[1]);

    cout << "累计数量：" << std::accumulate(vecTemp.begin(), vecTemp.end(),0);

    // 迭代器
    std::vector<int>::iterator it = vecTemp.begin();
    int i = 0;
    for(; it != vecTemp.end(); it++) {
        std::printf("ith: %d\n ", *it);  // 迭代器使用*； 如遇到map的迭代器，使用(*it).first 、 (*it).second
    }


    // map迭代器
    std::map<string, int> nameid;
    // nameid.insert(pair<string, int>("fan",0));
    // nameid.insert(pair<string, int>("luo",1));
    nameid.insert({"'x'", 34});
    nameid.insert({"ces", 33});

    std::map<string,int>::iterator itmap;
    for(itmap = nameid.begin(); itmap != nameid.end(); itmap++ ){
        std::printf("%s %d \n",  itmap->first.c_str() , itmap->second);  // map的iterator
    }
    
    
    // 初始化方法: 其它有序容器(除array外)  +  关联pair容器
    // 1. 拷贝参数初始化；=赋值初始化；迭代器初始化；
    // 2. ={x,y,z} 初始化
    // 3. 构造函数()初始化
    
    // 1. 
    vector<int> a = {1,2,3,4,5,6,7};
    vector<int> x(a);
    vector<int> y = a;
    
    // 2.
    vector<int> b = {1,2,3,4,5,6,7};
    
    // 3. 构造函数
    vector<int> z(10,1);

    for_each(z.begin(), z.end(), func_print);
    for_each(a.begin(), a.end(), func_print);


    // array的情况
    array<int, 10> arr_a = {1,2,3};
    std::cout << arr_a[0] << endl;


    // stack 和 queue / priority_queue 的底层
    /*************************************************************************
     * stack除array和forward_list之外任何容器类型均可构造。(要求push_back, pop_back, pop操作)
     * queue可用list或者queue。不能基于vector。(要求push_front, push_back, front, back)
     * priority_queue可用vector或queue，不能基于list。(要求随机访问，front, push_back, pop_back)
     * 
     **************************************************************************/
    
    


    /*************************************************************************
     * 常用接口: 当前状态 + 增删查改 + 比较 + 排序 + 交换位置
     *     -. 状态：size / empty() /.bucket_count() / bucket_size()
     *     -. 增：push() / push_back() / push_front()
     *     -. 删：erase
     *     -. 查：.at() / .find /.
     *     -. 改：.assign() / 
     *     -. 比较compare：
     *     -. 排序sort:
     *     -. 交换:  swap
     *************************************************************************/
    // 状态
    vector<string> vec_x = {"1", "22", "333", "abcd"};
    std::cout << vec_x.size() << vec_x.empty() <<vec_x.capacity()<< endl;
    // 增加
    vec_x.insert( vec_x.end(), "x"); 
    vec_x.insert(vec_x.begin(), {"aa", "bb", "cc"});
    vec_x.push_back("y");


    // 查找
    vec_x.at(0);
    auto it_vec = std::find(vec_x.begin(), vec_x.end(), "22");
    std::cout << "find 22 at:" << *it_vec << endl;

    auto it_vec2 = std::find(vec_x.begin(), vec_x.end(), "22222");
    std::cout << "find something not exists:" << *it_vec2 << endl;
    
    
    // 删除
    vec_x.erase(vec_x.end()); //iterator指定区间
    std::cout << "erase end iterator :"<< *(vec_x.end()) << endl;
    vec_x.clear();


    // 改： 1. 更改整个容器:  2. 更改单个值 ： at / iterator ? 
    vector<string> vec_y = {"a", "b","c"};
    vec_x.swap(vec_y);
    vec_x.assign(vec_y.begin(), vec_y.end());
    

    // 比较
    

    // 排序
    vector<string> vec_z = {"c", "b", "a"};
    std::cout << "\n before sort: " ;
    for_each(vec_z.begin(), vec_z.end(), func_print_str);
    std::sort(vec_z.begin(), vec_z.end());
    std::cout << "\n after sort: " ;
    for_each(vec_z.begin(), vec_z.end(), func_print_str);
    std::cout << endl;


    // deque 的操作。
    deque<string> deq_x = {"1", "22", "333", "abcd"};
    std::cout << deq_x.size()  << endl;




    // pair特别点： map的迭代器访问元素值： pair对象
    pair<string, int> apair = {"pair1",1};

    std::printf("%s , %d", apair.first.c_str(), apair.second);

    // 无序容器的 hash 支持


    // 桶支持


    /*********************************************************************
     * 
     *                       Algorithm 部分
     * 
     *********************************************************************/
    // !important 最大堆、红黑树 是容器的底层数据结构，如何自定义使用？
    // 例如：priority_queue底层就是使用基于 最大堆的数据结构，实现每次插入就自动排好序。




    return 0;
}

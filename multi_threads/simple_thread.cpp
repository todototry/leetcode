// test on windows 
// 实现创建线程
// 如何使用<thread> , 创建线程，等待，销毁 (joinable , join, detach , get_id() , swap(), hardware_concurrency() )
// 如何使用mutex 访问 shared data. （OS如何实现 p/v原语） 
// 如何使用 lock_guard / RAII特性
// 如何使用 condition_variable
#include<iostream>
#include<vector>
#include<thread>
#include<atomic>
#include<mutex>
#include<condition_variable>
#include<string>
#include<stdlib.h> // sleep in.

using namespace std;

class Student
{
    protected:
    string name;
    int score_math;
    int score_eng;
    int score_total;

    public:
    Student(string name, int score_math, int score_eng){
        this->name = name;
        this->score_math = score_math;
        this->score_eng = score_eng;
    }
    //Student(string name, int score){}

    void total(){
        this->score_total = this->score_math + this->score_eng;
        
    }

    int get_total(){
        return this->score_total;
    }


};

mutex m;

void process_data(int i, vector<int>& a, vector<int>& b, vector<int>& total){
    m.lock();
    //total.push_back(a[i] + b[i]);
    total[i] = a[i] + b[i];
    m.unlock();
    //std::this_thread::sleep_for(std::chrono::seconds(1));
   // return total[i];
}

int main(int argc, char const *argv[])
{   
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    vector<int> b = {1,2,3,4,5,6,7,8,9};
    vector<int> total(10);
    vector<thread> threads ;
    
    for(int i=0; i<a.size(); i++)
    {
        threads.push_back(thread(process_data, ref(i), ref(a), ref(b), ref(total)));
    }

    cout << threads.size() << std::endl;
    //_sleep(5);
    //std::sleep(5);
    //Sleep(5);
    for(int k=0; k< threads.size(); k++){

        threads[k].join();
    }

    for(auto data: total){
        cout << data << " ";
    }

    return 0;
}


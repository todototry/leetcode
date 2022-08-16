// 读者写者问题
// 读写互斥、写写互斥、读者优先， 
// 读读不互斥
// https://www.codenong.com/cs106785646/
#include<vector>
#include<string>
#include<atomic> // atomic accessing builtin datatype .
#include<mutex>
#include<thread>
#include<iostream>
#include<string>
#include<fstream>
#include<condition_variable>
//#include<semaphore>

using namespace std;

// 允许10个读者并行读
static int MAX_READER = 10;
int current_reader_cnt = 0;
atomic_int reader_cnt; // atomic<int> reader_cnt;
condition_variable cond;
mutex m_read;
mutex m_lock;
mutex m_write;

std::vector<int> pool;
//int index = 0;

void reader(){
    int i=10;
    while(i>0){
    i--;
    // 1. 读者不互斥，但有最大限制, 操作mutex——reader
    // 
    // 2. 读写互斥，
    // 3. 
    
    m_lock.lock();
    // 计算读者数量
    current_reader_cnt++;
    if (current_reader_cnt >= MAX_READER){
        // 超量读，加锁。
        m_read.lock();
    }
    // 读写互斥
    if (current_reader_cnt == 1){
        // 写加锁，因为读写互斥
        m_write.lock();
    }
    m_lock.unlock();

    // 并行读，并不互斥，因此不在互斥区。
    
    cout << "current reader: " << current_reader_cnt << endl; //<< pool.back() << endl;
    //pool.pop_back();

    //this_thread::sleep_for(std::chrono::seconds(1));

    m_lock.lock();
    // 释放并行reader
    current_reader_cnt--;
    if (current_reader_cnt < MAX_READER){
        m_read.unlock();
    }
    if (current_reader_cnt == 0) {
        // 解锁写
        m_write.unlock();
    }
    m_lock.unlock();


 }
}

void writer(int x){
    m_write.lock();

    pool.push_back(x);

    cout<< "write:" << x << endl; // "pool_content:" << pool << endl ;

    m_write.unlock();
}

int main(int argc, char const *argv[])
{
    srand((int)time(0));
    //int x = rand() % 100;

    thread t4(writer, rand() % 100);
    thread t5(writer, rand() % 100);
    thread t6(writer, rand() % 100);
    thread t7(writer, rand() % 100);

    thread t1(reader);
    thread t2(reader);
    thread t3(reader);
    


    this_thread::sleep_for(std::chrono::seconds(1));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    
    this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}

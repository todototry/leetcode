#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Stack{
    private:
    vector<T> elems;

    public:
    void push(const T& ele){
         elems.push_back(ele);
         }

    T pop(){
        T x = elems.back();
        elems.pop_back();
        return x;
        }

};


int main(int argc, char const *argv[])
{
    Stack<int> s;
    s.push(1);
    cout << s.pop() << endl;

        Stack<string> ss;
    ss.push("stest");
    cout << ss.pop() << endl;

    return 0;
}

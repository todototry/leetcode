#include<iostream>
#include<string>
#include<vector>
#include<thread>
#include<mutex>

using namespace std;

template <class T>
class Element{
    T data;
};


template <class T>
class Node{
    private:
        vector<Node*> nexts;        
        T elem;

    public:

        Node(){}
        Node(T a){ this->elem = a; }

    public:
        Node attach(Node & next){
            nexts.push_back(&next);
            return next;
        }

        Node operator+(Node & A, Node & next){
            return A.attach(next);
        }

        // template funciton.
        void run(){
            pre_action();
            action();
            post_action();
        }

    protected:
        virtual void action(){
            cout << "action" << elem << endl;
            for(auto next:nexts){
                cout << next->elem << " ";    
            }
            cout << endl;
        }


        virtual void pre_action(){cout << "pre" << endl;}

        virtual void post_action(){cout << "post" << endl;}
};


int main(int argc, char const *argv[])
{
    Node<int> a(1);
    Node<int> b(2);
    Node<int> c(3);
    Node<int> d(4);

    Node<int> * head = &a;

    a + b + c + d;
    a + b + c + d;

    a.run();
    b.run();
    c.run();

    return 0;
}

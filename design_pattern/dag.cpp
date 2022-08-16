#include<iostream>
#include<vector>
#include<list>
#include<string>

//using namespace std;

class Node{
    public:
    std::string name;
    std::vector<Node*> nexts;


    public: 
    Node(std::string a){
        this->name = a;
    }
    
    void logic(){
        std::cout << this->name << std::endl ;
        for (size_t i = 0; i < nexts.size(); i++)
        {
            std::cout << "content:" << std::endl;
            std::cout << this->nexts[i] ;
        }
    }

    Node operator>>(Node next) {
        this->nexts.push_back(&next);
        return next;
    }

};

int main(int argc, char const *argv[])
{
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");

    a>>b>>c>>d>>e;
    a>>b>>c>>d>>e;
    
    a.logic();
    b.logic();
    c.logic();
    d.logic();
    e.logic();

    return 0;
}


#include<iostream>
using namespace std;

class Game{
    public:
    void Run(){
        init();
        start();
        stop();
    }

    protected:
    virtual void start(){cout<< "start Game." << endl;} 

    private:
    void init(){
        cout << "init game" << endl;
    }
    void stop(){
        cout << "stop game" << endl;
    }

};

class BasketBall:public Game {
    protected:
    void start() {
        cout << "start BasketBall " << endl;
    }
};


class FootBall:public Game{

    protected:
    void start() {
        cout << "start FootBall " << endl;
    }
};


int main(int argc, char const *argv[])
{
    Game *g = new Game();
    g->Run();

    Game *g0 = new BasketBall();
    g0->Run();

    Game *g1 = new FootBall();
    g1->Run();

    delete g;
    delete g0;
    delete g1;
    return 0;
}

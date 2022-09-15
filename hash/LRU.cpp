//#include<hashmap>
#include<unordered_map>
#include<iostream>
//#include<list>
using namespace std;

struct DList{
    int key;
    int value;

    DList* next;
    DList* pre;

    DList():key(0),value(0),next(nullptr),pre(nullptr){}
    DList(int key_, int value_):key(key_),value(value_),next(nullptr), pre(nullptr){}
};


class LRUCache{
private:
    int size;
    int capacity;

    std::unordered_map<int, DList*> map_;
    DList* head;
    DList* tail;


public:
LRUCache(int capacity_):capacity(capacity_),size(0){

    this->head = new DList();
    this->tail = new DList();
    //map_ = new unordered_map<int, DList>();


}


int get(int key){
    if(this->size == 0){
        return -1;
    }

    // get from hash map 
    DList* cur = map_[key];
    
    // reorder dlink, move to head
    this->move2head(cur);
    return cur->value;
}

int put(int key, int value){
    // 存在
    if(){
        // 
         
    } 
    // not exists : add2head, if size>= capacity then ;
    else{

    }
}

void insertNode(DList* node){

    if (this->size)
    {
        /* code */

    }
    
}

void removeNode(){

}


void move2head(DList* node){
    if(this->head->next == node){
        return ;
    }
    // 
    node->pre->next = node->next;
    node->next->pre = node->pre;

    // 
    node->next = this->head->next;
    this->head->next = node;
    node->pre = head;
}


}


void main(){


}
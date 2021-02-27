#include<iostream>
#include<string>

struct Node{
    std::string data;
    Node *link;
};

class Lilist{
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
    private:
        Node *head;
};

void Lilist::add(std::string item){
    Node * tmp;
    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> link = NULL;
    }
    else{
        for(tmp = head; tmp->link != NULL; tmp = tmp -> link)
            ;  // this loop simply advances the pointer to last node in
                //the list
        tmp ->link = new Node;
        tmp = tmp->link;
        tmp->data = item;
        tmp->link = NULL;
    }
}

void Lilist::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp->link)
        std::cout<<tmp->data<<"  ";
}

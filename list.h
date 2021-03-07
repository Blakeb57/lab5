#include<iostream>
#include<string>

struct Node
{
    std::string data;
    Node *link;

/*
    Node(std::string data)
    {
        this -> data = data;
        link = NULL;
    }
    */
};

class Lilist
{
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
        Node* search(const std::string data);
        void move_front_to_back();

    private:
        Node *head;
};

void Lilist::add(std::string item)
{
    Node * tmp;
    if(head == NULL)
    {
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

void Lilist::show()
{
    struct Node* temp = head;
    
    for(Node *tmp = head; tmp != NULL; tmp = tmp->link)
        std::cout << tmp->data <<"  ";
    temp = temp -> link;
    
}

Node* Lilist::search(const std::string target)
{
    for(Node* cursor = head; cursor != NULL; cursor = cursor -> link)
    {
        if(cursor->data == target)
        {
            return cursor;
        }
    }
    return NULL;
}

void Lilist::move_front_to_back()
{
    Node* front = head;
    //head = head -> link;
    Node* link = NULL;
    Node* prev = NULL;

    while(front != NULL)
    {
        link = front -> link;
        front -> link = prev;
        prev = front;
        front = link;
    }
    head = prev;



    /*
    Node* back;
    Node* front = head;
    head = head -> link;
    std::string item;

    for(back = head; back->link != NULL; back = back -> link)
        ; 

    back -> link = new Node;
    back = back -> link;
    front = front -> link;
    back -> link = NULL;
    */
}
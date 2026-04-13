//=============================
// Простой односвязный список
//
//
//=============================

#include <iostream>
#include <stdexcept>

struct Node_t
    {
        int value;

        Node_t *next = nullptr;

        ~Node_t() { delete next; }
    };

class list_t
{
private:
    Node_t *begin = nullptr;
    Node_t *end = nullptr;
public:
    
    ~list_t() {delete begin;}


    Node_t* at (int num)
    {
       if (!begin)
        throw std::out_of_range("Index is out of range");
       
        Node_t *cur_node = begin;
        int i = 0;

        while (i != num)
        {            
            cur_node = cur_node->next;
            if (!cur_node)
                throw std::out_of_range("Index is out of range");
            i++;
        }        
        return cur_node;
    }

    void push_back (int value)
    {
        Node_t *new_node = new Node_t;
        new_node->value = value;

        if (begin == nullptr)
        {
            begin = new_node;
            end = new_node;
        }
        else
        {
            end->next = new_node;
            end = new_node;
        }
    }
};

int main()
{
    list_t list;

    list.push_back(1);
    list.push_back(2);  
    list.push_back(3);

    std::cout << list.at(0)->value << std::endl;
    std::cout << list.at(1)->value << std::endl;
    std::cout << list.at(1)->next->value << std::endl;

    
    return 0;
}
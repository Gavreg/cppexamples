//=============================
// Простой односвязный список
//
//
//=============================

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T> //или template<class T>
struct Node_t
    {
        T value;

        Node_t *next = nullptr;

        ~Node_t() { delete next; }
    };

template <typename T> 
class list_t
{
private:
    Node_t<T> *begin = nullptr;
    Node_t<T> *end = nullptr;
public:
    ~list_t() {delete begin;}

    Node_t<T>* at (int num)
    {
       if (!begin)
        throw std::out_of_range("Index is out of range");
       
        auto *cur_node = begin;
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

    void push_back (const T &value)
    {
        auto *new_node = new Node_t<T>;
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
    list_t<int> list_int;
    
    list_int.push_back(1);
    list_int.push_back(2);  
    list_int.push_back(3);

    for (Node_t<int> *cur_node = list_int.at(0); cur_node ;
            cur_node=cur_node->next)
        std::cout << cur_node->value << " ";

    std::cout<<std::endl;

    list_t<std::string> list_str;
    list_str.push_back("Stankin");
    list_str.push_back("is the");
    list_str.push_back("best");
   
    for (auto cur_node = list_str.at(0); cur_node ;
            cur_node=cur_node->next)
        std::cout << cur_node->value << " ";

    std::cout<<std::endl;
    
    return 0;
}
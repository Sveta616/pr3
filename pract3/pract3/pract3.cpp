// pract3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoublyLinkedList
{
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void push_front(int data)
    {
        Node* current = new Node{ data,nullptr,nullptr };
        current->next = head;
        if (head != nullptr)
        {
            head->prev = current;
        }
        else if (tail == nullptr)
        {
            tail = current;
        }
        head = current;
    }
    void push_back(int data)
    {
        Node* current = new Node{ data,nullptr, nullptr };
        current->prev = tail;
        if (tail != nullptr)
        {
            tail->next = current;
        }
        else if (head == nullptr)
        {
            head = current;
        }
        tail = current;
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* del = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete del;

    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* del = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete del;

    }
    void sort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            std::cout << "List is empty or list has only 1 element" << std::endl;
            return;
        }
        bool temp;
        do {
            temp = false;
            Node* current = head;
            while (current->next != nullptr)
            {
                if (current->data > current->next->data)
                {
                  
                    int n = current->data;
                    current->data = current->next->data;
                    current->next->data = n;
                    temp = true;
                }
                current = current->next;
            }
        } while (temp);
    }
    void remove_duplicates()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* current = head;

        while (current != nullptr) { 
            Node* sledyushi = current->next; 

            while (sledyushi != nullptr) { 
                if (current->data == sledyushi->data) { 

                    Node* duplicate = sledyushi; 
                    sledyushi->prev->next = sledyushi->next;
                    if (sledyushi->next != nullptr) { 
                        sledyushi->next->prev = sledyushi->prev; 
                    }
                    sledyushi = sledyushi->next; 
                    delete duplicate; 
                }
                else {
                    sledyushi = sledyushi->next; 
                }
            }
            current = current->next; 
        }

    }
    

    
    void display()
    {
        if (tail == nullptr && head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " "; 
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoublyLinkedList list;
    bool temp = true;
    while (temp)
    {
    int choise;
    int val;
    std::cout << "Choise the action:\n1-add value front\n2-add value back\n3-remove value front\n4-remove value back\n5-show all values in the list\n6-sort\n7-remove duplicates\n8-exit\n";
    std::cin >> choise;
    switch (choise)
    {
    case 1:

        std::cout << "Enter the value\n";
        std::cin >> val;
        list.push_front(val);
        break;
    case 2:
        std::cout << "Enter the value\n";
        std::cin >> val;
        list.push_back(val);
        break;
    case 3:
        list.pop_front();
        break;
    case 4:
        list.pop_back();
        break;
    case 5:
        list.display();
        break;
    case 6:
        list.sort();
        break;
    case 7:
        list.remove_duplicates();
        break;
    case 8:
        temp = false;
        break;
    }

   } 
     return 0;
 }
  



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

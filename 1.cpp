#include<iostream>

template<typename T>
class Node {
public:
    Node *next = nullptr;
    T Data;
    Node() = default;
    Node(const T& data):
        Data(data) {}
};

template<typename T>
class mylist {
public:
    Node<T> *begin = nullptr;
    Node<T> *end = nullptr;
    mylist() = default;
    void push_back(const T& Data) {
        if (end == nullptr) {
            end = new Node<T>(Data);
            begin = end;
        } else {
            end->next = new Node<T>(Data);
            end = end->next;
        }
    }
    void pop_front() {
        if (begin != nullptr){
            Node<T> *temp = begin;
            begin = begin->next;
            delete temp;
            if (begin == nullptr) {
                end = nullptr;
            }
        }
    }
    void push_back(mylist &other) {
        if (other.begin != nullptr) {
            end->next = other.begin;
            end = other.end;
            other.begin = nullptr;
            other.end = nullptr;
        }
    }
    void sort() {
        if (begin == nullptr) {
            return;
        }
        mylist left, right;
        int Data = begin->Data;
        pop_front();
        while (begin != nullptr) {
            if (begin->Data > Data) {
                right.push_back(begin->Data);
            } else {
                left.push_back(begin->Data);
            }
            pop_front();
        }
        left.sort();
        right.sort();
        left.push_back(Data);
        left.push_back(right);
        begin = left.begin;
        end = left.end;
        left.begin = nullptr;
        left.end = nullptr;
    }
    void print() const{
        Node<T> *t = begin;
        while (t != nullptr) {
            std::cout << t->Data << ' ';
            t = t->next;
        }
        std::cout << std::endl;
    }
    ~mylist() {
        while (begin != nullptr) {
            pop_front();
        }
    }
};

int32_t main() {
    int n = 0;
    std::cin >> n;
    mylist<int> list;
    for (int i = 0; i < n; ++i) {
        int Data = 0;
        std::cin >> Data;
        list.push_back(Data);
    }
    list.sort();
    list.print();
}

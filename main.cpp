#include <iostream>
using namespace std;

template<typename T>
struct Nodo{
    T dato;
    Nodo *siguiente;
};

template<typename T>
class List{
private:
    Nodo<T> *head;
public:
    List() : head(nullptr){}

    T front(){
        if(head == nullptr){
            throw std::out_of_range("Lista vacia");
        }
        return head -> dato;
    }

    T back(){
        Nodo<T>* temp = head;
        while(temp -> siguiente != nullptr){
            temp = temp -> siguiente;
        }
        return temp -> dato;
    }

    void push_front(T valor){
        Nodo<T> *nuevoNodo = new Nodo<T>;
        nuevoNodo -> dato = valor;
        nuevoNodo -> siguiente = head;
        head = nuevoNodo;
    }

    void push_back(T valor){
        Nodo<T> *nuevoNodo = new Nodo<T>;
        nuevoNodo -> dato = valor;
        nuevoNodo -> siguiente = nullptr;

        if (head == nullptr) {
            head = nuevoNodo;
        } else {
            Nodo<T> *temp = head;
            while (temp -> siguiente != nullptr) {
                temp = temp -> siguiente;
            }
            temp -> siguiente = nuevoNodo;
        }
    }

    void pop_front(){
        Nodo<T> *temp = head;
        head = head -> siguiente;
        delete temp;
    }

    void pop_back(){
        if(head -> siguiente == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Nodo<T> *temp = head;
            while(temp -> siguiente -> siguiente != nullptr){
                temp = temp -> siguiente;
            }
            delete temp -> siguiente;
            temp -> siguiente = nullptr;
        }
    }

    T at(int indice){
        if(head == nullptr){
            throw std::out_of_range("La lista esta vacia");
        }
        Nodo<T> *temp = head;
        int currentIndex = 0;
        while(temp != nullptr && currentIndex < indice){
            temp = temp -> siguiente;
            currentIndex ++;
        }
        if(temp == nullptr){
            throw std::out_of_range("Indice fuera de rango");
        }
        return temp -> dato;
    }

    bool empty() const{
        return head == nullptr;
    }

    int size() const{
        int count = 0;
        Nodo<T> *temp = head;
        while(temp != nullptr){
            count ++;
            temp = temp -> siguiente;
        }
        return count;
    }

    void clear(){
        while(head != nullptr){
            Nodo<T> *temp = head;
            head = head -> siguiente;
            delete temp;
        }
    }

    void sort() {
        if (head == nullptr || head->siguiente == nullptr) {
            return;
        }
        bool swapped;
        do {
            swapped = false;
            Nodo<T> *current = head;
            Nodo<T> *prev = nullptr;
            Nodo<T> *next = head->siguiente;

            while (next != nullptr) {
                if (current->dato > next->dato) {
                    current->siguiente =next->siguiente;
                    next->siguiente = current;

                    if (prev ==nullptr) {
                        head = next;
                    } else {
                        prev->siguiente = next;
                    }
                    swapped=true;
                    prev=next;
                    next=current->siguiente;
                } else {
                    prev=current;
                    current=next;
                    next = next->siguiente;
                }
            }
        } while (swapped);
    }


    void reverse() {
        Nodo<T>* prev = nullptr;
        Nodo<T>* current = head;
        Nodo<T>* next = nullptr;

        while (current != nullptr) {
            next = current->siguiente;
            current->siguiente = prev;
            prev = current;
            current = next;
        }
        head = prev;
    };

    void print_list() {
        Nodo<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};


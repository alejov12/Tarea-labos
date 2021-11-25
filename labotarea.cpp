#include <iostream>
using namespace std;


class Node 
{
    
    private:
        int id;
        string usuario;
        string perfil;
        Node *previous;
        
        Node *next;
        friend class LinkedList;
};

class LinkedList
{
    
    public:
        
        LinkedList();
        
        ~LinkedList();
        
        int getFront() const;
        int getBack() const;
        void addFront(int dt,string us,string pe);
        void addBack(int dt,string us,string pe);
        void removeFront();
        void removeBack();
        void printReverse();
        void printForward();
    
    private:
        Node *header;
        Node *trailer;
};

LinkedList::LinkedList(){
    // Se define dinamicamente la memoria 
    header = new Node;
    // creamos el trailer (que es el centinela final)
    trailer = new Node;
    //Tenemos que hacer que el header apunte al trailer, 
    // y el trailer al header
    header->next = trailer;
    trailer->previous = header;
    //Como la lista esta vacia se igual a NULL
    header->previous = NULL;
    trailer->next = NULL;
}

//Al final si se puede
LinkedList::~LinkedList(){
    // llama a la funcion removeFront
    //para cuando elimine el elemento de la lista que no este vacia
    //Sera cuando ambos nodos centinela se apunten, es decir no hay head ni tail
    while(header->next!=trailer){
        removeFront();
    }
    //eliminar individualmente
    delete header;
    delete trailer;
}
int LinkedList::getFront() const{
    // Devuelve el primer valor
    //acceder al header
    //accedemos a su dato
    return header->next->id;
}
int LinkedList::getBack() const{
    //Devuelve el ultimo nodo
    return trailer->previous->id;
}
void LinkedList::addFront(int dt,string us,string pe){
    // anadir un nuevo nodo a la memoria que se pasa por valor
    Node *nd = new Node;
    //al nodo que tenemos le ponemos el dato
    nd->id = dt;
    nd->usuario = us;
    nd->perfil = pe;
    nd->previous = header;
    // es decir que ahora esta apuntando al nodo head
    nd->next = header->next; 

    // cambiar los punteros del header, y del nodo head
    // su puntero anterior es el nuevo nodo
    // acceder al nodo head, su puntero previous es 
    // el nuevo nodo anadido a la lista
    header->next->previous = nd;

    // el puntero head 
    header->next = nd;

}
void LinkedList::addBack(int dt,string us,string pe){
    Node *nd = new Node;
    nd->id = dt;
    nd->usuario = us;
    nd->perfil = pe;
    nd->previous = header;
    nd->previous=trailer->previous;
    nd->next=trailer;

    //actualizar trailer
    // a traves de trailer accedemos a su nodo previo apunta al nuevo nodo
    trailer->previous->next = nd;
    trailer->previous = nd;
}
void LinkedList::removeFront(){
    // Eliminar el nodo del principio
    // Accedemos al nodo siguiente de head
    Node *nd=header->next->next;
    delete header->next;

    // actualizar los punteros del header y del nodo anterior
    header->next=nd;
    nd->previous=header;
}
void LinkedList::removeBack(){
    // Eliminar a final
    // tomar una referencia al nodo anterior al nodo tail
    Node *nd = trailer->previous->previous;

    delete trailer->previous;

    //actualizar el puntero apuntara al 
    //nodo anterior al nodo tail que se elimino
    trailer->previous=nd;
    nd->next=trailer;
}
void LinkedList::printReverse(){
    // Vamos a imprimirlos 
    // Va del final al principio
    //referencia a tail
    Node *nd=trailer->previous;

    //Si el nodo es diferente al centinela inicial
    while (nd!=header)
    {
        // se imprime el nodo
        cout << "ID:" << "[" << nd->id << "] ";
        cout << "|Nombre Usuario: " << "[" << nd->usuario << "]" ;
        cout <<  " Tipo de Usuario: " << "[" << nd->perfil << "]  |" << endl;
        //actualizar el nodo anterior
        nd=nd->previous;
    }    

}
void LinkedList::printForward(){
    // Vamos a imprimirlos 
    // Va del principio al final
    //referencia a head
    Node *nd=header->next;

    //Si el nodo es diferente al centinela final
    while (nd!=trailer)
    {
        // se imprime el nodo
        cout << "ID:" << "[" << nd->id << "] ";
        cout << "|Nombre Usuario: " << "[" << nd->usuario << "]" ;
        cout <<  " Tipo de Usuario: " << "[" << nd->perfil << "]  |" << endl;
        //actualizar el nodo al siguiente
        nd=nd->next;
    }    
}
int main()
{
    cout << "base de datos de wallmart" << endl;
    LinkedList ll;
    cout << endl;
    ll.addFront(1,"alejo","administrador");
    ll.addFront(2,"Toni","cliente");
    ll.addFront(3,"Bryan","trabajador");
    ll.addFront(4,"Carlos","cliente");
    ll.addFront(5,"Diego","trabajador");
    ll.addFront(6,"Alex","administrador");
    ll.addFront(7,"Johan","cliente");
    
    

    // Para imprimir
    cout << "Imprimir los datos:" << endl;
    ll.printReverse();


    return 0;
};
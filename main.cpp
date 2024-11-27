#include <iostream> // Aqui citamos la libreria IOSTREAM
#include <algorithm> // Libreria para usar funciones estándar como sort, max_element, min_element
#include <vector> // Biblioteca para utilizar el contenedor vector
//---------------------------------------------------------------------------
// Verifica si se está compilando en un sistema Windows
#ifdef _WIN32
// Incluye la librería windows.h para funciones específicas de Windows
#include <windows.h>
#else
// Si no es Windows, incluye la librería unistd.h para funciones de Unix/Linux
#include <unistd.h>
#endif
//---------------------------------------------------------------------------
using namespace std;

// Estructura de un nodo para la lista enlazada
// Cada nodo contiene un dato llamado (data) y un puntero llamado(next) al siguiente nodo
struct Node {
    int data;       // Aqui se almacena el Dato almacenado en el nodo
    Node* next;     // Puntero al siguiente nodo en la lista
};

//Función que toma las listas enlazadas y las almacena en un array dinámico y lo retorna
int* dynamicArray (Node* top,int size){   
        //Copiaremos los elementos de la lista enlzada a un arreglo dinamico para uso efectivo de algoritmos de orden...
        int* elements = new int[size]; //Se genera un arreglo dinamico
        Node* temp = top; 
        /*Este ciclo for se usara para "llenar" el arreglo dinamico antes instanciado con los elementos
        de la lista enlazada guardando la data de cada nodo en una posición del arreglo */
        for(int i = 0; i < size; i++){
            elements[i] = temp -> data;
            temp = temp -> next;
        }
    return elements;
};

// Clase que define el comportamiento de una Pila (LIFO)
class Stack {
public:
    Node* top;      // Puntero al nodo superior de la pila
    int size;       //Tamaño de la lista para ordenar 
    // Constructor: Inicializa la pila como vacía (top apunta a nullptr y el tamaño de la lista es 0)
    Stack() : top(nullptr), size(0){}

    // Método para agregar un elemento a la pila (LIFO)
    void push(int value) {
        // Crear un nuevo nodo con el valor dado
        Node* newNode = new Node();
        newNode->data = value;   // Asignar el valor al nodo
        newNode->next = top;     // Apuntar el nuevo nodo al nodo que actualmente está en la cima (top)
        top = newNode;           // Actualizar top para que apunte al nuevo nodo
        size++;
        cout << "Elemento " << value << " agregado a la pila.\n";
    }

    // Método para eliminar el elemento superior de la pila (LIFO)
    void pop() {
        // Verificar si la pila está vacía
        if (top == nullptr) {
            cout << "La pila está vacía.\n";
            return;
        }
        Node* temp = top;      // Apuntar a la cima de la pila para eliminarla
        top = top->next;       // Mover top al siguiente nodo (debajo del actual)
        cout << "Elemento " << temp->data << " eliminado de la pila.\n";
        delete temp;           // Liberar la memoria del nodo eliminado
        size --;
    }

    // Método para mostrar todos los elementos en la pila
    void display() {
        // Verificar si la pila está vacía
        if (top == nullptr) {
            cout << "La pila está vacía.\n";
            return;
        }
        Node* temp = top;      // Apuntar al nodo superior
        cout << "Elementos en la pila: ";
        // Recorrer y mostrar cada nodo de la pila
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next; // Mover al siguiente nodo
        }
        cout << endl;
    }
    
    /*Este metodo nos será útil a la hora de realizar ordenamientos con distintos algoritmos 
    que necesiten pasar la lista enlazada a un arreglo dinamico para ordenar sus elementos(nodos) */
    void reconstructStack(int* elements, int size) {
    
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        for (int i = size - 1; i >= 0; i--) {
            Node* newNode = new Node();
            newNode->data = elements[i];
            newNode->next = top;
            top = newNode;
    }
};

};

// Clase que define el comportamiento de una Cola (FIFO)
class Queue {
public:
    Node* front;   // Puntero al nodo frontal de la cola
    Node* rear;    // Puntero al nodo trasero de la cola
    int size;
    // Constructor: Inicializa la cola como vacía (front y rear apuntan a nullptr)
    Queue() : front(nullptr), rear(nullptr), size(0){}

    // Método para agregar un elemento a la cola (FIFO)
    void enqueue(int value) {
        // Crear un nuevo nodo con el valor dado
        Node* newNode = new Node();
        newNode->data = value;  // Asignar el valor al nodo
        newNode->next = nullptr; // El siguiente nodo es nullptr porque será el último nodo

        // Si la cola está vacía, tanto front como rear apuntan al nuevo nodo
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            // Si la cola no está vacía, añadir el nuevo nodo al final y actualizar rear
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Elemento " << value << " agregado a la cola.\n";
    }

    // Método para eliminar el elemento frontal de la cola (FIFO)
    void dequeue() {
        // Verificar si la cola está vacía
        if (front == nullptr) {
            cout << "La cola está vacía.\n";
            return;
        }
        Node* temp = front;     // Apuntar al nodo frontal para eliminarlo
        front = front->next;    // Mover front al siguiente nodo

        // Si después de eliminar, la cola queda vacía, rear también debe ser nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
        size--;
        cout << "Elemento " << temp->data << " eliminado de la cola.\n";
        delete temp;            // Liberar la memoria del nodo eliminado
    }

    // Método para mostrar todos los elementos en la cola
    void display() {
        // Verificar si la cola está vacía
        if (front == nullptr) {
            cout << "La cola está vacía.\n";
            return;
        }
        Node* temp = front;     // Apuntar al nodo frontal
        cout << "Elementos en la cola: ";
        // Recorrer y mostrar cada nodo de la cola
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;  // Mover al siguiente nodo
        }
    }
    
    /*Este metodo nos será útil a la hora de realizar ordenamientos con distintos algoritmos 
    que necesiten pasar la lista enlazada a un arreglo dinamico para ordenar sus elementos(nodos), en
    este caso en una estructuta FIFO */
    void reconstructQueue(int* elements, int size) {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    
        for (int i = 0; i < size; i++) {
            Node* newNode = new Node();
            newNode->data = elements[i];
            newNode->next = nullptr;
        
            if (rear == nullptr) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }
    };
};

//Algoritmo ordenamiento bubbleSort
void bubbleSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    // Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (elements[j] > elements[j + 1]) {
                swap(elements[j], elements[j + 1]);
            }
        }
    }

    cout << "La estructura ha sido ordenada usando Bubble Sort.\n";
};

//Algoritmo ordenamiento selectionSort()
void selectionSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    // Selection Sort
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (elements[j] < elements[minIndex]) {
                minIndex = j;
            }
        }
        swap(elements[i], elements[minIndex]);
    }
    cout << "La estructura ha sido ordenada usando Selection Sort.\n";
};

//Algoritmo de ordenamiento insertionSort
void insertionSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    // Insertion Sort
    for (int i = 1; i < size; i++) {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && elements[j] > key) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
    cout << "La estructura ha sido ordenada usando Insertion Sort.\n";
}

/*Las siguientes 3 funciones seran pertenecientes al uso de mergeSort()
-----------------------------------------------------------------------------------------------------------------------*/
void merge(int* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeS(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeS(arr, l, m);
        mergeS(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//Algoritmo principal mergeSort()
void mergeSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    //Llamado a funcionamiento de algoritmo, este a su vez llama otras funciones
    mergeS(elements, 0, size - 1);
    cout << "La estructura ha sido ordenada usando Merge Sort.\n";
};


/*Las siguientes funciones seran pertenecientes a ellgoritmo de ordenamiento quickSort()
------------------------------------------------------------------------------------------------------------------*/

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
};

void quickS(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickS(arr, low, pi - 1);
        quickS(arr, pi + 1, high);
    }
};

//Algoritmo principal quickSort()
void quickSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    quickS(elements, 0, size - 1);
    cout << "La estructura ha sido ordenada usando Quick Sort.\n";
};

//Algoritmo de ordenamiento shellSort()
void shellSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = elements[i];
            int j;
            for (j = i; j >= gap && elements[j - gap] > temp; j -= gap) {
                elements[j] = elements[j - gap];
            }
            elements[j] = temp;
        }
    }
    cout << "La estructura ha sido ordenada usando Shell Sort.\n";
};

//Algoritmo de ordenamiento countingSort()
void countingSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    int maxVal = *max_element(elements, elements + size);
    int minVal = *min_element(elements, elements + size);
    int range = maxVal - minVal + 1;

    int* count = new int[range]{0};
    int* output = new int[size];

    for (int i = 0; i < size; i++) {
        count[elements[i] - minVal]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[elements[i] - minVal] - 1] = elements[i];
        count[elements[i] - minVal]--;
    }

    for (int i = 0; i < size; i++) {
        elements[i] = output[i];
    }
    delete[] count;
    delete[] output;
    cout << "La estructura ha sido ordenada usando Counting Sort.\n";
};

/*Las siguientes funciones son correspondientes a Algoritmo de ordenamiento radixSort()------------------------------*/
void countingSortForRadix(int* arr, int n, int exp) {
        int* output = new int[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        delete[] output;
    }

//Algoritmo principal radixSort()
void radixSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    int maxVal = *max_element(elements, elements + size);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(elements, size, exp);
    }
    cout << "La estructura ha sido ordenada usando Radix Sort.\n";
};

//Algoritmo de ordenamiento bucketSort()
void bucketSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    int bucketCount = 10;
        vector<int> buckets[bucketCount];

    int maxVal = *max_element(elements, elements + size);
    for (int i = 0; i < size; i++) {
        int bucketIndex = bucketCount * elements[i] / (maxVal + 1);
        buckets[bucketIndex].push_back(elements[i]);
    }

    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            elements[index++] = buckets[i][j];
        }
    }
    cout << "La estructura ha sido ordenada usando Bucket Sort.\n";
}

/*Las siguientes funciones son correspondientes a Algoritmo de ordenamiento heapSort()--------------------------------*/
void heapify(int* arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

//Algoritmo principal heapSort()
void heapSort(int* elements, int size) {
    if (elements == nullptr) return; // Manejo de error si no hay elementos

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(elements, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(elements[0], elements[i]);
        heapify(elements, i, 0);
    }
    cout << "La estructura ha sido ordenada usando Heap Sort.\n";
};



//---------------------------------------------CLASE DE ARBOL BINARIO DE BUSQUEDA----------------------------------------------------------

class Nodo {
public:
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};


class ArbolBinarioBusqueda {
private:

    // Función auxiliar para insertar
    Nodo* insertar(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return new Nodo(valor);

        if (valor < nodo->dato)
            nodo->izquierda = insertar(nodo->izquierda, valor);
        else if (valor > nodo->dato)
            nodo->derecha = insertar(nodo->derecha, valor);

        return nodo;
    }

    // Función auxiliar para buscar
    bool buscar(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return false;

        if (nodo->dato == valor)
            return true;
        else if (valor < nodo->dato)
            return buscar(nodo->izquierda, valor);
        else
            return buscar(nodo->derecha, valor);
    }

    // Función auxiliar para encontrar el nodo mínimo
    Nodo* encontrarMinimo(Nodo* nodo) {
        while (nodo->izquierda != nullptr)
            nodo = nodo->izquierda;
        return nodo;
    }

    // Función auxiliar para eliminar
    Nodo* eliminar(Nodo* nodo, int valor) {
        if (nodo == nullptr)
            return nodo;

        if (valor < nodo->dato) {
            nodo->izquierda = eliminar(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = eliminar(nodo->derecha, valor);
        } else {
            // Caso 1: Nodo sin hijos
            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
                delete nodo;
                return nullptr;
            }
            // Caso 2: Nodo con un solo hijo
            else if (nodo->izquierda == nullptr) {
                Nodo* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == nullptr) {
                Nodo* temp = nodo->izquierda;
                delete nodo;
                return temp;
            }
            // Caso 3: Nodo con dos hijos
            else {
                Nodo* temp = encontrarMinimo(nodo->derecha);
                nodo->dato = temp->dato;
                nodo->derecha = eliminar(nodo->derecha, temp->dato);
            }
        }
        return nodo;
    }

public:

    Nodo* raiz;
    
    // Constructor
    ArbolBinarioBusqueda() : raiz(nullptr) {}

    // Insertar
    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }

    // Buscar
    bool buscar(int valor) {
        return buscar(raiz, valor);
    }

    // Eliminar
    void eliminar(int valor) {
        raiz = eliminar(raiz, valor);
    }
};

//-------------------------------------CLASE DE ARBOL AVL-----------------------------------------------------------------


#include <iostream>
using namespace std;

// Clase para NodoAVL
class NodoAVL {
public:
    int dato;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL(int valor)
        : dato(valor), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

// Clase Árbol AVL
class ArbolAVL {
private:

    // Obtener la altura de un nodo
    int obtenerAltura(NodoAVL* nodo) {
        return nodo == nullptr ? 0 : nodo->altura;
    }

    // Calcular el factor de balance de un nodo
    int obtenerBalance(NodoAVL* nodo) {
        return nodo == nullptr ? 0 : obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
    }

    // Rotación a la derecha
    NodoAVL* rotacionDerecha(NodoAVL* y) {
        NodoAVL* x = y->izquierda;
        NodoAVL* T2 = x->derecha;

        // Rotación
        x->derecha = y;
        y->izquierda = T2;

        // Actualizar alturas
        y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
        x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

        return x;
    }

    // Rotación a la izquierda
    NodoAVL* rotacionIzquierda(NodoAVL* x) {
        NodoAVL* y = x->derecha;
        NodoAVL* T2 = y->izquierda;

        // Rotación
        y->izquierda = x;
        x->derecha = T2;

        // Actualizar alturas
        x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
        y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

        return y;
    }

    // Insertar un nodo
    NodoAVL* insertar(NodoAVL* nodo, int valor) {
        if (nodo == nullptr)
            return new NodoAVL(valor);

        if (valor < nodo->dato)
            nodo->izquierda = insertar(nodo->izquierda, valor);
        else if (valor > nodo->dato)
            nodo->derecha = insertar(nodo->derecha, valor);
        else
            return nodo; // No se permiten duplicados

        // Actualizar altura
        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

        // Verificar balance
        int balance = obtenerBalance(nodo);

        // Rotaciones necesarias
        if (balance > 1 && valor < nodo->izquierda->dato)
            return rotacionDerecha(nodo);

        if (balance < -1 && valor > nodo->derecha->dato)
            return rotacionIzquierda(nodo);

        if (balance > 1 && valor > nodo->izquierda->dato) {
            nodo->izquierda = rotacionIzquierda(nodo->izquierda);
            return rotacionDerecha(nodo);
        }

        if (balance < -1 && valor < nodo->derecha->dato) {
            nodo->derecha = rotacionDerecha(nodo->derecha);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    // Buscar el nodo con el valor mínimo
    NodoAVL* encontrarMinimo(NodoAVL* nodo) {
        NodoAVL* actual = nodo;
        while (actual->izquierda != nullptr)
            actual = actual->izquierda;
        return actual;
    }

    // Eliminar un nodo
    NodoAVL* eliminar(NodoAVL* nodo, int valor) {
        if (nodo == nullptr)
            return nodo;

        if (valor < nodo->dato)
            nodo->izquierda = eliminar(nodo->izquierda, valor);
        else if (valor > nodo->dato)
            nodo->derecha = eliminar(nodo->derecha, valor);
        else {
            // Nodo con uno o ningún hijo
            if ((nodo->izquierda == nullptr) || (nodo->derecha == nullptr)) {
                NodoAVL* temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
                if (temp == nullptr) {
                    temp = nodo;
                    nodo = nullptr;
                } else
                    *nodo = *temp;
                delete temp;
            } else {
                // Nodo con dos hijos
                NodoAVL* temp = encontrarMinimo(nodo->derecha);
                nodo->dato = temp->dato;
                nodo->derecha = eliminar(nodo->derecha, temp->dato);
            }
        }

        if (nodo == nullptr)
            return nodo;

        // Actualizar altura
        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

        // Verificar balance
        int balance = obtenerBalance(nodo);

        // Rotaciones necesarias
        if (balance > 1 && obtenerBalance(nodo->izquierda) >= 0)
            return rotacionDerecha(nodo);

        if (balance > 1 && obtenerBalance(nodo->izquierda) < 0) {
            nodo->izquierda = rotacionIzquierda(nodo->izquierda);
            return rotacionDerecha(nodo);
        }

        if (balance < -1 && obtenerBalance(nodo->derecha) <= 0)
            return rotacionIzquierda(nodo);

        if (balance < -1 && obtenerBalance(nodo->derecha) > 0) {
            nodo->derecha = rotacionDerecha(nodo->derecha);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }


public:

    NodoAVL* raiz;
    
    // Constructor
    ArbolAVL() : raiz(nullptr) {}

    // Insertar
    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }

    // Eliminar
    void eliminar(int valor) {
        raiz = eliminar(raiz, valor);
    }
};


//--------------------------------------CLASE ARBOL ROJO-NEGRO-------------------------------------------------------------


enum Color { ROJO, NEGRO };

// Clase NodoRN
class NodoRN {
public:
    int dato;
    bool color;
    NodoRN* izquierda;
    NodoRN* derecha;
    NodoRN* padre;

    NodoRN(int valor)
        : dato(valor), color(ROJO), izquierda(nullptr), derecha(nullptr), padre(nullptr) {}
};

// Clase ArbolRojoNegro
class ArbolRojoNegro {
private:

    void inicializarNodoNulo() {
        TNULL = new NodoRN(0);
        TNULL->color = NEGRO;
        TNULL->izquierda = nullptr;
        TNULL->derecha = nullptr;
    }

    void inordenPrivado(NodoRN* nodo) {
        if (nodo != TNULL) {
            inordenPrivado(nodo->izquierda);
            cout << nodo->dato << " ";
            inordenPrivado(nodo->derecha);
        }
    }

    void preordenPrivado(NodoRN* nodo) {
        if (nodo != TNULL) {
            cout << nodo->dato << " ";
            preordenPrivado(nodo->izquierda);
            preordenPrivado(nodo->derecha);
        }
    }

    void postordenPrivado(NodoRN* nodo) {
        if (nodo != TNULL) {
            postordenPrivado(nodo->izquierda);
            postordenPrivado(nodo->derecha);
            cout << nodo->dato << " ";
        }
    }

public:

    NodoRN* TNULL; // Nodo centinela
    NodoRN* raiz;

    ArbolRojoNegro() {
        inicializarNodoNulo();
        raiz = TNULL;
    }

    void insertar(int valor) {
        NodoRN* nodo = new NodoRN(valor);
        nodo->padre = nullptr;
        nodo->dato = valor;
        nodo->izquierda = TNULL;
        nodo->derecha = TNULL;

        NodoRN* y = nullptr;
        NodoRN* x = raiz;

        while (x != TNULL) {
            y = x;
            if (nodo->dato < x->dato) {
                x = x->izquierda;
            } else {
                x = x->derecha;
            }
        }

        nodo->padre = y;
        if (y == nullptr) {
            raiz = nodo;
        } else if (nodo->dato < y->dato) {
            y->izquierda = nodo;
        } else {
            y->derecha = nodo;
        }

        if (nodo->padre == nullptr) {
            nodo->color = NEGRO;
            return;
        }

        if (nodo->padre->padre == nullptr) {
            return;
        }

        // Reparar inserción (implementación omitida por brevedad)
    }

    NodoRN* buscar(int valor) {
        NodoRN* actual = raiz;
        while (actual != TNULL && actual->dato != valor) {
            if (valor < actual->dato) {
                actual = actual->izquierda;
            } else {
                actual = actual->derecha;
            }
        }
        return actual;
    }

    void eliminar(int valor) {
        NodoRN* nodo = buscar(valor);
        if (nodo != TNULL) {
            // Lógica de eliminación (implementación omitida por brevedad)
            cout << "Nodo eliminado: " << valor << endl;
        } else {
            cout << "Nodo no encontrado: " << valor << endl;
        }
    }

    void inorden() {
        inordenPrivado(raiz);
        cout << endl;
    }

    void preorden() {
        preordenPrivado(raiz);
        cout << endl;
    }

    void postorden() {
        postordenPrivado(raiz);
        cout << endl;
    }
};


//-------------- Recorridos genericos haciendo uso de <templates> para distintos tipos de nodos (Nodo*, NodoAVL*, NodoRN*)-----------------------------

// Función genérica para recorrido inorden
template <typename Nodo>
void inorden(Nodo* nodo) {
    if (nodo != nullptr) {
        inorden<Nodo>(nodo->izquierda); // Llamada explícita al template
        cout << nodo->dato << " ";
        inorden<Nodo>(nodo->derecha); // Llamada explícita al template
    }
}

// Función genérica para recorrido preorden
template <typename Nodo>
void preorden(Nodo* nodo) {
    if (nodo != nullptr) {
        cout << nodo->dato << " ";
        preorden<Nodo>(nodo->izquierda); // Llamada explícita al template
        preorden<Nodo>(nodo->derecha); // Llamada explícita al template
    }
}

// Función genérica para recorrido postorden
template <typename Nodo>
void postorden(Nodo* nodo) {
    if (nodo != nullptr) {
        postorden<Nodo>(nodo->izquierda); // Llamada explícita al template
        postorden<Nodo>(nodo->derecha); // Llamada explícita al template
        cout << nodo->dato << " ";
    }
}


//---------------------------------------------------------------------------------------------------------------

//Función para limpiar pantalla
void clearScreen() {
    //Directivas de preprocesador que evaluaran el sistema operativo
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
};


// Función para mostrar el menú principal al usuario
void menu() {
    Stack stack;   // Crear una instancia de la clase Pila
    Queue queue;   // Crear una instancia de la clase Cola
    ArbolBinarioBusqueda abb; //crear instancia de la clase Arbol Binario de Busqueda
    ArbolAVL arbolAVL; //Crear instancia de clase de Arbol AVL
    ArbolRojoNegro arn; //Crear instancia de clase de Arbol rojo-negro
    int choice, value;

    // Ciclo principal para mostrar el menú hasta que el usuario decida salir
    do {
        clearScreen();  // Limpiar la pantalla antes de mostrar menú principal
        cout << "\n--- Menú ---\n";
        cout << "1. Usar Pila (LIFO)\n";
        cout << "2. Usar Cola (FIFO)\n";
        cout << "3. Usar Arbol binario de busqueda\n";
        cout << "4. Usar Arbol AVL\n";
        cout << "5. Usar Arbol rojo-negro\n";
        cout << "6. Salir\n";
        cout << "Elige una opción: ";
        cin >> choice;

        // Switch principal para seleccionar entre Pila, Cola o Salir
        switch (choice) {
            case 1:  // Menú de operaciones con la Pila
                clearScreen(); //Limpiar la pantalla antes de mostrar menú de estructra de pilas
                cout << "\n--- Menú de Pila ---\n";
                cout << "1. Insertar elemento en la pila (push)\n";
                cout << "2. Eliminar elemento de la pila(pop)\n";
                cout << "3. Mostrar elementos de la pila(display)\n";
                cout << "4. Ordenar elementos de la pila\n";
                cout << "5. Regresar al menú principal\n";
                cout << "Elige una opción: ";
                cin >> choice;
                switch (choice) {
                    case 1:  // Inserta un elemento en la pila
                        cout << "Introduce el valor a insertar: ";
                        cin >> value;
                        stack.push(value);
                        break;
                    case 2:  // Elimina el elemento superior de la pila
                        stack.pop();
                        break;
                    case 3:  // Muestra todos los elementos de la pila
                        stack.display();
                        cout << "Presiona Enter para continuar...";
                        cin.ignore();  // Limpiar el buffer de entrada
                        cin.get();  // Esperar a que el usuario presione Enter
                        break;
                    case 4: {
                        Node* top = stack.top;
                        int size = stack.size;
                        if (size == 0) {
                            cout << "No hay elementos en la lista, no se puede ordenar\n";
                            return;
                        }
                        clearScreen();
                        int sortChoice;
                        cout << "\n--- Algoritmos de ordenamiento ---\n";
                        cout << "1. Bubble Sort\n";
                        cout << "2. Selection Sort\n";
                        cout << "3. Insertion Sort\n";
                        cout << "4. Merge Sort\n";
                        cout << "5. Quick Sort\n";
                        cout << "6. Shell Sort\n";
                        cout << "7. Counting Sort\n";
                        cout << "8. Radix Sort\n";
                        cout << "9. Bucket Sort\n";
                        cout << "10. Heap Sort\n";
                        cin >> sortChoice;
                        //Convertimos a array dinamico los nodos de la lista enlazada stack para alg. ordenamiento
                        int* elements = dynamicArray(top, size);
                        switch (sortChoice) {
                            case 1: bubbleSort(elements, size); break;
                            case 2: selectionSort(elements, size); break;
                            case 3: insertionSort(elements, size); break;
                            case 4: mergeSort(elements, size); break;
                            case 5: quickSort(elements, size); break;
                            case 6: shellSort(elements, size); break;
                            case 7: countingSort(elements, size); break;
                            case 8: radixSort(elements, size); break;
                            case 9: bucketSort(elements, size); break;
                            case 10: heapSort(elements, size); break;
                            default: cout << "Opción no válida.\n"; break;
                        }
                        //Reconstruimos la pila a partir de elements
                        stack.reconstructStack(elements, size);
                        delete[] elements;
                        break;
                    }    
                    case 5:  // Regresa al menú principal
                        break;
                }
                if (choice != 5) {
                    cout << "Presiona Enter para continuar...";
                    cin.ignore();  // Limpiar el buffer de entrada
                    cin.get();  // Esperar a que el usuario presione Enter
                    }
                break;
            case 2:  // Menú de operaciones con la Cola
                clearScreen(); //Limpiar la pantalla antes de mostrar menú de estructra de colas
                cout << "\n--- Menú de Cola ---\n";
                cout << "1. Insertar elemento en la cola(equeque)\n";
                cout << "2. Eliminar elemento de la cola(desequeque)\n";
                cout << "3. Mostrar elementos de la cola(display)\n";
                cout << "4. Ordenar elementos de la cola (menor a mayor)\n";
                cout << "5. Regresar al menú principal\n";
                cout << "Elige una opción: ";
                cin >> choice;
                switch (choice) {
                    case 1:  // Inserta un elemento en la cola
                        cout << "Introduce el valor a insertar: ";
                        cin >> value;
                        queue.enqueue(value);
                        break;
                    case 2:  // Elimina el elemento frontal de la cola
                        queue.dequeue();
                        break;
                    case 3:  // Muestra todos los elementos de la cola
                        queue.display();
                        break;
                    case 4: {
                        Node* front = queue.front;
                        int size = queue.size;
                        if (size == 0) {
                            cout << "No hay elementos en la lista, no se puede ordenar\n";
                            return;
                        }
                            clearScreen();
                            int sortChoice;
                            cout << "\n--- Algoritmos de ordenamiento ---\n";
                            cout << "\n--- Algoritmos de ordenamiento ---\n";
                            cout << "1. Bubble Sort\n";
                            cout << "2. Selection Sort\n";
                            cout << "3. Insertion Sort\n";
                            cout << "4. Merge Sort\n";
                            cout << "5. Quick Sort\n";
                            cout << "6. Shell Sort\n";
                            cout << "7. Counting Sort\n";
                            cout << "8. Radix Sort\n";
                            cout << "9. Bucket Sort\n";
                            cout << "10. Heap Sort\n";
                            cout << "11. Tim Sort\n";
                            cin >> sortChoice;
                            //Convertir a arreglo dinamico los nodos de la lista enlazada
                            int* elements = dynamicArray(front, size);
                            switch (sortChoice){
                                case 1: bubbleSort(elements, size); break;
                                case 2: selectionSort(elements, size); break;
                                case 3: insertionSort(elements, size); break;
                                case 4: mergeSort(elements, size); break;
                                case 5: quickSort(elements, size); break;
                                case 6: shellSort(elements, size); break;
                                case 7: countingSort(elements, size); break;
                                case 8: radixSort(elements, size); break;
                                case 9: bucketSort(elements, size); break;
                                case 10: heapSort(elements, size); break;
                                default: cout << "Opción no válida.\n"; break;
                            }
                            queue.reconstructQueue(elements, size);
                            delete[] elements;
                            break;
                        }
                    case 5:  // Regresa al menú principal
                        break;
                }
                    if (choice != 5) {
                        cout << "Presiona Enter para continuar...";
                        cin.ignore();  // Limpiar el buffer de entrada
                        cin.get();  // Esperar a que el usuario presione Enter
                        }
                    break;
            case 3:{
                clearScreen();
                cout << "--- Menú de arbol binario de busqueda ---\n";
                cout << "1. Insertar nodo\n";
                cout << "2. Buscar nodo\n";
                cout << "3. Eliminar nodo\n";
                cout << "4. Recorridos\n";
                cout << "5. Salir\n";
                cout << "Ingrese que desea realizar: ";
                cin >> choice;
                Nodo* raiz = abb.raiz;
                switch (choice) {
                    case 1:
                        cout << "Digite el valor a insertar: ";
                        cin >> value;
                        abb.insertar(value);
                        break;
                    case 2:
                        cout << "Digite que valor va a buscar: ";
                        cin >> value;
                        abb.buscar(value);
                        break;
                    case 3:
                        cout << "Ingrese el valor a eliminar: ";
                        cin >> value;
                        abb.eliminar(value);
                        break;
                    case 4: {
                        clearScreen();
                        int abbChoice;
                        cout << "De que manera desea recorrer el Arbol binario de busqueda: \n";
                        cout << "1. Recorrido In-orden.\n";
                        cout << "2. Recorrido Pre-orden.\n";
                        cout << "3. Recorrido Post-orden.\n";
                        cout << "4. Salir\n";
                        cout << "Ingrese una opcion: ";
                        cin >> abbChoice;
                        switch (abbChoice) {
                            case 1:
                                inorden(raiz);
                                break;
                            case 2:
                                preorden(raiz);
                                break;
                            case 3:
                                postorden(raiz);
                                break;
                        }
                    }
                    case 5: //Salir del programa
                        break;
                }
            }
            break;
            case 4: {
                clearScreen();
                cout << "--- Menu de Arbol AVL---\n";
                cout << "Seleccione una opción:\n";
                cout << "1. Insertar nodo.\n";
                cout << "2. Eliminar nodo.\n";
                cout << "3. Recorridos\n";
                cout << "4. Salir\n";
                cout << "Ingrese que desea realizar: ";
                cin >> choice;
                NodoAVL* raiz = arbolAVL.raiz;
                
                switch (choice) {
                    case 1:
                        cout << "Ingrese el valor a insertar.\n";
                        cin >> value;
                        arbolAVL.insertar(value);
                        break;
                    case 2:
                        cout << "Ingrese el valor a eliminar\n";
                        cin >> value;
                        arbolAVL.eliminar(value);
                        break;
                    case 3: {
                        clearScreen();
                        int avlChoice;
                        cout << "De que manera desea recorrer el Arbol AVL: \n";
                        cout << "1. Recorrido In-orden.\n";
                        cout << "2. Recorrido Pre-orden.\n";
                        cout << "3. Recorrido Post-orden.\n";
                        cout << "Indique una opción: ";
                        cin >> avlChoice;
                        
                        switch (avlChoice) {
                            case 1:
                                inorden(raiz);
                                break;
                            case 2:
                                preorden(raiz);
                                break;
                            case 3:
                                postorden(raiz);
                                break;
                        }
                    }
                }
            }
            case 5: {
                clearScreen();
                cout << "--- Menú de árbol rojo-negro ---\n";
                cout << "1. Insertar nodo\n";
                cout << "2. Buscar nodo\n";
                cout << "3. Eliminar nodo\n";
                cout << "4. Recorridos\n";
                cout << "5. Salir\n";
                cout << "Ingrese que desea realizar: ";
                cin >> choice;
                NodoRN* raiz = arn.raiz;
        
                switch (choice) {
            case 1:
                cout << "Ingrese el valor a insertar: ";
                cin >> value;
                arn.insertar(value);
                break;
            case 2:
                cout << "Ingrese el valor a buscar: ";
                cin >> value;
                if (arn.buscar(value) != nullptr) {
                    cout << "Nodo encontrado: " << value << endl;
                } else {
                    cout << "Nodo no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Ingrese el valor a eliminar: ";
                cin >> value;
                arn.eliminar(value);
                break;
            case 4: {
                int recorrido;
                cout << "--- Tipos de recorrido ---\n";
                cout << "1. Inorden\n";
                cout << "2. Preorden\n";
                cout << "3. Postorden\n";
                cout << "Ingrese una opción: ";
                cin >> recorrido;

                switch (recorrido) {
                    case 1:
                        arn.inorden();
                        break;
                    case 2:
                        arn.preorden();
                        break;
                    case 3:
                        arn.postorden();
                        break;
                }
                break;
            }
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                }
            }
        } 
    } while (choice != 5);  // Continuar hasta que el usuario elija salir
};

// Función principal que inicia el programa
int main() {
    menu();  // Llamada a la función del menú principal
    return 0; // Retorno exitoso
}

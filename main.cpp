#include <iostream>
#include <string>
#include <DoublyLinkedList.h>
#include <Dimension.h>

using namespace std;

void setDimensions(DoublyLinkedList<Dimension> *dimensions)
{
    int dim;
    cout << "Ingrese la cantidad de dimensiones deseadas: \n";
    cin >> dim;
    cout << endl;
    for(int i = 0; i < dim; i++)
    {
        int in;
        cout<<"Ingrese la magnitud de la dimension " + to_string(i+1) << "\n";
        cin >> in;
        Dimension *n = new Dimension();
        n->setSize(in);
        dimensions->insertLast(*n);
    }
    cout << "\n\n";
    Node<Dimension> *tmp = dimensions->tail;
    for(int j = 0; j < dimensions->lenght ; j++)
    {
        cout << tmp->data.getSize() << endl;
        tmp = tmp->next;
    }
}

/*METODO PARA OBTENER LA POSICION LINEAL POR FILAS*/
int LocalizeByRows(Node<int> *coor, Node<Dimension> *dim)
{
    //I(row) * NCOL + I+1(col)
    if(dim->next == 0)return coor->previous->data + dim->previous->data.getSize()*coor->data;
    return coor->previous->data + dim->previous->data.getSize()*LocalizeByRows(coor->next, dim->next);
}


/*METODO PARA OBTENER LA POSICION LINEAL POR COLUMNAS*/
int LocalizeByColumns(Node<int> *coor, Node<Dimension> *dim)
{
    //I(col) * NROWS + I+1(row)
    if(dim->position == 1)return coor->data + dim->data.getSize()* coor->previous->data;
    return coor->data + dim->data.getSize()*LocalizeByColumns(coor->next,dim->next);
}


int obtainPos(DoublyLinkedList<Dimension> *tmp, int option)
{
    Node<Dimension> *aux = tmp->head;
    DoublyLinkedList<int> coordinates;
    for(int i = 0; i<tmp->lenght; i++)
    {
        cout<< "Ingrese la coordenada:\n";
        int c = 0;
        cin >> c;
        coordinates.insertLast(c);
        if(c > aux->data.getSize())
        {
            system("cls");
            cout<< "La coordenada ingresada excede los limites de la dimension en la que se desea acceder\n";
            system("pause");
            return 0;
        }
        aux = aux->previous;
    }
    int answer = 0;
    if(tmp->lenght == 1)
    {
        answer = coordinates.getNode(0);
    }
    else
    {
        if(option == 2)answer = LocalizeByRows(coordinates.tail->next, tmp->tail->next);
        else if(option == 3) answer = LocalizeByColumns(coordinates.tail->next, tmp->tail->next);
    }
    cout << to_string(answer) + "\n";
    system("pause");
    return 0;
}

int main()
{
    DoublyLinkedList <Dimension> dimensions;
    while(true)
    {
        int option;
        cout << "Seleccione la opcion que desea realizar:\n\n"<< endl;
        cout << "1. Ingresar dimensiones y su magnitud." << endl;
        cout << "2. Obtener posicion lineal con coordenadas por filas." << endl;
        cout << "3. Obtener posicion lineal con coordenadas por columnas." << endl;
        cout << "4. Salir." << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                dimensions.head = dimensions.tail = 0;
                dimensions.lenght = 0;
                setDimensions(&dimensions);
                break;
            case 2:
                if(!dimensions.isEmpty())
                obtainPos(&dimensions, option);
                break;
            case 3:
                if(!dimensions.isEmpty())
                obtainPos(&dimensions, option);
                break;
            case 4:
                return 0;
                break;
        default:
            cout << "Ingrese una seleccion valida\n";
            system("pause");
        }
        system("cls");
    }
    return 0;
}

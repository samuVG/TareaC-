#include<iostream> //librerias
#include <vector>
using namespace std;

namespace myvec{
	
class Vector {
  public:     //Metodos de la clase
    vector<double> VECTOR; //se crea un vector vacío con entradas flotantes

    Vector(int tamano) { //constructor de la clase Vector
      for( int k = 0; k < tamano; k++ ) // se crea el vector introduciendo entrada por entrada por teclado
      {
        cout<< "Entrada: "<< k +1 << " del vector" <<endl; // se muestra en pantalla la entrada del vector a introducir
        double entrada; //la entrada es flotante
        cin >> entrada; //se introduce por teclado cada entrada del vector
        VECTOR.push_back(entrada); //mete la entrada al vector en la ultima posicion
      }
}
    void PrintVec(void){ //metodo que imprime los vectores
      for(int K=0; K < VECTOR.size(); K++){ //se imprime el vector por entradas 
        cout << VECTOR.at(K) << ' '; //para que el vector que se imprime se muestre en fila 
      }
}
    void SetPos(int valor ,double valor_new) { //metodo para cambiar entradas donde a es la posicion que quiero reemplazar 
    							  // y b es el valor que quiero introducir ahi
      if (valor<VECTOR.size()) //entra si la posicion que quiero cambiar de valor esta dentro del tamaño de mi vector
        {
        VECTOR.insert( VECTOR.begin()+ valor, valor_new);
        VECTOR.erase(VECTOR.begin()+ valor +1); 
        } 
      else if (valor == VECTOR.size())  //si la posicion es igual al tamaño del vector, entonces se le añade una entrada 
      							 //con el valor que quiero
        {
        VECTOR.push_back(valor_new);
        } 
      else
      {
        cout<< "Accion invalida" << endl;
      }
}
    double GetPos(int posicion){   //metodo que me da el valor de una posicion del vector
      return VECTOR.at(posicion);  //se imprime el valor de una posicion determinada del vector
}
    int GetSize(void){  //metodo que da el tamaño del vector
      return VECTOR.size();
    }
    Vector operator = (Vector vec) //se sobrecarga el operador =
      {
        VECTOR = vec.VECTOR; //para asignar un vector de la clase Vector a una nueva variable
        return *this; //this se trata de un puntero que tiene asociado cada objeto y que apunta a si mismo
      }
    Vector operator + (Vector vec) //se sobrecarga el operador +
      { 
        if (VECTOR.size() != vec.GetSize()) //se verifica que se vayan a sumar dos vectores de igual tamaño, sino sale error
        {
          cout<< "No se pueden sumar" << endl;
        }
        else   // se suman los vectores
        {
          Vector new_vec(0);  // se crea un vector perteneciente a la clase Vector
          for(int k=0; k < VECTOR.size(); k++){  //se suman entrada por entrada 
            new_vec.SetPos(k,VECTOR.at(k) + vec.GetPos(k)); //se usa los metodos SetPos para llenar el nuevo vector
        }
          return new_vec; //se devuelve el vector suma
        }
      }
    Vector operator - (Vector vec) //se sobrecarga el operador -
      { 
        if (VECTOR.size() != vec.GetSize()) //se verifica que se vayan a restar dos vectores de igual tamaño, sino sale error
        {
          cout<< "No se pueden restar" << endl;
        }
        else // se restan los vectores
        {
          Vector new_vec(0); // se crea un vector perteneciente a la clase Vector
          for(int k=0; k < VECTOR.size(); k++) //se restan entrada por entrada 
		  {
            new_vec.SetPos(k,VECTOR.at(k) - vec.GetPos(k)); //se usa los metodos SetPos para llenar el nuevo vector
        }
          return new_vec; //se devuelve el vector resta
        }
      }

    double& operator[] (int pos) //se sobrecarga el metodo [], para saber que valor hay en la posicion [pos] y poder reemplazarlo
      {
        return VECTOR[pos]; //se usa el operador [] de la libreria vector
      }
};
}

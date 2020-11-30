#include<iostream>
using std::cout;
using std::endl;

#include <vector>

using namespace std;

namespace myvec{

class Vector {
  public:
    vector<double> vec;

    Vector(int lon) {
      for( int i = 0; i < lon; i++ ) 
      {
        cout<< "Ingrese el elemento "<< i +1 << " al vector" << endl;
        double a;
        cin >> a;
        vec.push_back(a);
      }
}

    void PrintVec(void){
      for(int i=0; i < vec.size(); i++){
        cout << vec.at(i) << ' ';
      }
}

    void SetPos(int a,double b) {
      
      if (a<vec.size())
        {
        vec.emplace( vec.begin()+ a, b);
        vec.erase(vec.begin()+ a +1);
        } 
      else if (a == vec.size()) 
        {
        vec.push_back(b);
        } 
      else
      {
        cout<< "Accion invalida" << endl;
      }
}
    double GetPos(int c){
      return vec.at(c);
}

    int GetSize(void){
      return vec.size();
    }

    Vector operator = (Vector a)
      {
        vec = a.vec;
        return *this;
      }

    Vector operator + (Vector a)
      { 
        if (vec.size() != a.GetSize())
        {
          cout<< "No se pueden sumar" << endl;
        }
        else
        {
          Vector nvec(0);
          for(int i=0; i < vec.size(); i++){
            nvec.SetPos(i,vec.at(i) + a.GetPos(i));
        }
          return nvec;
        }
      }

    Vector operator - (Vector a)
      { 
        if (vec.size() != a.GetSize())
        {
          cout<< "No se pueden sumar" << endl;
        }
        else
        {
          Vector nvec(0);
          for(int i=0; i < vec.size(); i++){
            nvec.SetPos(i,vec.at(i) - a.GetPos(i));
        }
          return nvec;
        }
      }

       double& operator[] (int a)
      {
        return vec[a];
      }
};
}

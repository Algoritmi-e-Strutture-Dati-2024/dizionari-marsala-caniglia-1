#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class DizionarioEsteso{
  private:
    static const int TABLE_SIZE=100;
    struct Entry{
      string chiave;
      T valore;
      bool isOccupied=false;
      bool isDeleted=false;
    };

Entry table[TABLE_SIZE];

int hashFunction(const string& chiave) const {
    int hash = 0;
    for (char ch : chiave) {
        hash += static_cast<int>(ch);
    }
    return hash % TABLE_SIZE;
}
  public:
    void inserisci(const string& chiave, const T& valore){
      int indice=hashFunction(chiave);
      table[indice].chiave=chiave;
      table[indice].valore=valore;
      table[indice].isOccupied=true;
      table[indice].isDeleted=false;
    }

  void cancella(const string& chiave){
    int indice=hashfunction(chiave);
    if(table[indice].isOccupied && !table[indice].isDeleted){
        table[indice].isDeleted=true;
    }
  }

  T recupera(const string& chiave) const{
      int index=hashFunction(chiave);
      if (table[indice].isOccupied && !table[indice].isDeleted){
        return table[indice].valore;
      }
  }

  bool appartiene(const string& key) const{
      int indice=hashFunction(chiave);
      if (!table[indice].isOccupied || table[indice].key != chiave || table[indice].isDeleted) {
        return table[indice].isOccupied && !table[indice].isDeleted;
      }
  }

void stampa() const{
    for(int i=0; i<TABLE_SIZE; ++i){
      if(table[i].isOccupied && !table[i].isDeleted){
        cout<<"Indice "<<i<<":  "<<table[i].chiave<<" => "<<table[i].valore<<"\n">
          }else if(table[i].isDeleted){
            cout<<"Indice  "<<i<<"cancellato\n";
          }else{
            cout<<"Indice "<<i<<" vuoto\n";
          }
       }
}


  

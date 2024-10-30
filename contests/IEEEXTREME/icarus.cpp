#include<bits/stdc++.h>

using namespace std;

struct Node {
    int left = -1;
    int right = -1;
    int parent = -1;
};

map<int, Node> BT;

int main() {
    string instructions;
    cin >> instructions;
    int nodoActual = 0;
    int down = 0;
    int up = 0;
    int raiz = 0;
    int sigNodo = 1;
    /*cout << "sigNodo: " << sigNodo << endl;*/
    Node first;
    BT[0] = first;
    BT[0].left = -1;
    BT[0].right = -1;
    for(char c : instructions){
      /*cout << "char: "<< c << endl;*/
      if(c == 'L'){
        down++;
        if(BT[nodoActual].left == -1){
          BT[nodoActual].left = sigNodo;
          Node sigN;
          BT[sigNodo] = sigN;
          BT[sigNodo].parent = nodoActual;
          nodoActual = sigNodo;
          sigNodo++;
        } else{
          nodoActual = BT[nodoActual].left;
        }
        /*cout << "sigNodo: " << sigNodo << endl;*/
      }else if(c == 'R'){
        down++;
        if(BT[nodoActual].right == -1){
          BT[nodoActual].right = sigNodo;
          Node sigN;
          BT[sigNodo] = sigN;
          BT[sigNodo].parent = nodoActual;
          nodoActual = sigNodo;
          sigNodo++;
        }else{
          nodoActual = BT[nodoActual].right;
        }
        /*cout << "sigNodo: " << sigNodo << endl;*/
      }else if(c == 'U'){
        up++;
        if(BT[nodoActual].parent == -1){
          BT[nodoActual].parent = sigNodo;
          Node sigN;
          BT[sigNodo] = sigN;
          // Aqui se escogio arbitrariamente right, se puee probar tambien con left
          BT[sigNodo].right = nodoActual;
          nodoActual = sigNodo;
          raiz = sigNodo;
          sigNodo++;
          /*cout << "sigNodo: " << sigNodo << endl;*/
        }else{
          nodoActual = BT[nodoActual].parent;
        }
      }
    }
    /*cout << down << " " << up << endl;*/
    if(down > up){
      Node sal;
      BT[raiz].parent = sigNodo;
      BT[sigNodo] = sal;
      BT[sigNodo].right = raiz;
      raiz = sigNodo;
      /*cout << "Nodo end raiz: " << sigNodo << " hijo: " << sal.right << endl;*/
    }else{
      Node sal;
      BT[nodoActual].right = sigNodo;
      BT[sigNodo] = sal;
      BT[sigNodo].parent = nodoActual;
      raiz = sigNodo;
      /*cout << "Nodo end hoja: " << sigNodo << " papá: " << sal.parent << endl;*/
    }
    cout << sigNodo + 1 << " " << 1 << " " << raiz +1 << endl;
    for(int i = 0; i < sigNodo + 1 ; i++){
      cout << BT[i].left + 1<< " " << BT[i].right + 1 << endl;
    }
    return 0;
}

#ifndef HOMEW2_TASKS_RK2_H
#define HOMEW2_TASKS_RK2_H
#include <string>
#include <functional>
#include <utility>
#include <iterator>
#include <list>
#include <vector>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

//task1
struct Node
{
    Node() { }
    Node(int nameNode) { }
    ~Node() { }

    Node* parent;
    list<Node*> listChilds;
    int name;
    static int countNodes;
};

class Graph
{
private:
    Node* head;
    list<Node*> ar;

public:
    Graph(){head=new Node();}
    Graph(int countNodes){buildTreeBFS(countNodes);}
    ~Graph(){delete head;}


    int buildTreeBFS(int countNodes);
    void BFS();
    void DFS();
    pair<bool, list<int>> searchDFS(int nameNode);
    pair<bool, list<int>> searchBFS(int nameNode);
};

//task2
pair<int/*index el*/,int/*count call*/> binSearch(int* ar, int sizeAr, int el);

//task3
template<class T>
class Filo
{
private:
    T* ar;
    int size;
    int countData;
public:
    Filo();
    Filo(int _size){
        size=_size;
        countData=0;
        ar = new T[_size];
    }
    ~Filo(){
        delete[] ar;
    }
    int push_back(T el);
    pair<int,T> pop_back();
    void returnAr();
};


//task4
template<typename T>
ostream& operator<< (ostream &out, const pair<int, T>& myPair );


//task5
template<class T>
class  CheckBrackets:public Filo<char>
{
public:
    CheckBrackets() : Filo<char>(256) { }
    ~CheckBrackets();

    int checkBrackets(const char* strBrackets);
};



#endif //HOMEW2_TASKS_RK2_H

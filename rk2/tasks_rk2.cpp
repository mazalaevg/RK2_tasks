#include "tasks_rk2.h"

//task1
int Graph::buildTreeBFS(int countNodes) {
    this->head=new Node();
    vector<Node*> ns;
    ns.push_back(head);

    while (true)
    {
        vector<Node*> Nodes;
        for (auto node:ns) {
            for (int i = 0; i < countNodes; ++i) {
                auto cNode = new Node();
                node->listChilds.push_back(cNode);
                Nodes.push_back(cNode);
            }
        }
        countNodes--;
        ns=Nodes;
        if (countNodes==0) return 0;
    }
}

//task2
pair<int/*index el*/, int /*count call*/> binSearch(int* ar, int size, int el) {
    int static count = 0;
    int static low = 0;
    int middle = size / 2;
    count++;

    if (ar[middle] == el) {
        return make_pair(middle + low, count);
    }

    if (ar[middle] > el) {
        if (size % 2 == 0)
            size = size - middle;
        else
            size = size - 1 - middle;
        return binSearch(ar, size, el);
    }

    if (ar[middle] < el) {
        low += middle + 1;

        for (int i = 0; i < middle; i++)
            swap(ar[i], ar[middle + 1 + i]);

        size = size - middle - 1;
        return binSearch(ar, size, el);
    }

}
//task3
template<class T> int Filo<T>::push_back(T el)
{
    if (countData > size - 1)
        return 0;
    if (ar == nullptr)
        ar = new T();

    ar[countData] = el;
    countData++;
    return 1;
}
template<class T> pair<int,T> Filo<T>::pop_back()
{
    if (countData < 1)
        return make_pair(0, 0);
    if (ar == nullptr)
        ar = new T();
    countData--;
    return make_pair(1, ar[countData]);
}


//task4 
template<typename T>
ostream& operator<< (ostream &out, const pair<int, T>& myPair )
{
    out << "(" << myPair.first << ", " << myPair.second << ")\n";
    return out;
}

//task5

template<>
int CheckBrackets<char>::checkBrackets(const char *strBrackets)
{
    for (int i=0;strBrackets[i]!=0;i++){

        if (strBrackets[i]=='(') {
            push_back(strBrackets[i]);
        }
            if (strBrackets[i]=='[') {
                push_back(strBrackets[i]);
            }
                if (strBrackets[i]=='{') {
                    push_back(strBrackets[i]);
                }
        if (strBrackets[i]==')'){
            if (pop_back().second!='(')
                return -1;
        }
        if (strBrackets[i]=='}'){
            if (pop_back().second!='{')
                return -1;
        }
        if (strBrackets[i]==']'){
            if (pop_back().second!='[')
                return -1;
        }
    }
    if (pop_back().first!=0)
        return -1;

    return 0;
}



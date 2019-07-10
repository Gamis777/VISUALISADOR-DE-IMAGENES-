
#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;
template <class K, class D>
class bst{
    struct node{
        K key;
        D dato;
        node * p_child[2];
        node(K &k, D &d):key(k),dato(d){
            p_child[0]=p_child[1]=nullptr;
        }
        ~node()=default;
    };
    private:
        node * p_root;
    public:
        bst():p_root(nullptr){}
        bool find(const K &k){
            node **n;
            return find(n,k);
        }
    private:
        bool find(node ** &n,const K &ky){
            n= &p_root;
            while(*n)
            {
                if(ky==(*n)->key){
                    return true;
                }
                n=&(*n)->p_child[ky>(*n)->key];
            }
            return false;
        }
    public:
        bool insert(const K &k,const D &d){
            node **n;
            if(find(n,k)) return false;
            *n=new node(k,d);
            return true;
        }
        void swap(node ** &n,int x){
             K aux=(*n)->key;
             (*n)->key=((*(*n))->p_child[x])->key;
             ((*(*n))->p_child[x])->key=aux;
             D aux1=(*n)->dato;
             (*n)->dato=((*(*n))->p_child[x])->dato;
             ((*(*n))->p_child[x])->dato=aux1;
             n=&(*n)->p_child[x];
        }
        /*bool remove_(node **&n){
        }*/
        bool remove(const K &k){
            node **n;
            if(!find(n,k))
            return false;

            return true;
        }
        D &operator[](const K &key){
            node **n;
            if(!find(n,key)){
                *n=new node(key);
            }
            return(*n)->dato;
        }
        ~bst(){
            //free all nodes
        }
};

#endif // BST_H

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <ctype.h>
#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>

#define COUNT 10


using namespace family;
static Tree* node=NULL;
    Tree &Tree::addFather(string son, string father) {
        if (findMe(this, son)) {
            //cout<<node<<endl;
             node->father= new Tree(father,node);
            //cout<<"father"<<endl;
             node->father->gender=0;


        }
        else{
            __throw_out_of_range("did not find son");
        }
        return *this;
    }

    Tree &Tree::addMother(string son, string Mother) {
        if (findMe(this,son)){
            node->Mother=new Tree(Mother,node);
            node->Mother->gender=1;

        }
        else{
            __throw_out_of_range("did not find son");
        }
        return *this;

    }
    void Tree::display(){
    if (this==NULL){
        return;
    }
    print2DUtil(this,0);
    }


//source: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void Tree::print2DUtil(Tree *root, int space) {

        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print2DUtil(root->father, space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->name<< "\n";

        // Process left child
        print2DUtil(root->Mother, space);
    }
static int count=0;
    bool flag=false;
    bool flag2=false;
    bool Tree::findMe(Tree *root, string name_search) {
       // node=NULL;
        if (root->name == name_search) {
            node = root;
            return true;
        }
        if (root->Mother == NULL && root->father == NULL) {
            return false;
        }
        if(root->father!=NULL) {
            flag=findMe(root->father, name_search);
        }
        if(root->Mother!=NULL) {
            flag2=findMe(root->Mother, name_search);
        }
        return (flag2 || flag);
    }
    void Tree::remove(string name) {
        //cout<<this->name<<endl;
        if (this->name==name){
           throw std::exception();
        }
        if (findMe(this, name)) {
            Tree *temp=node->son;
            if(temp->father->name==name){
                temp->father=NULL;
            }else{
                temp->Mother=NULL;
            }

        } else {
            __throw_out_of_range("This name not exit in Tree");
        }
    }
string Tree::relation(string name){

        if(findMe(this,name) ){

    if (node!=NULL) {
        int level = getLevel(this, name);

        if (level == 1) {
            return "me";
        }
        if (level == 2 && node->gender == 0) {
            return "Father";
        }
        if (level == 2 && node->gender == 1) {
            return "Mother";
        }
        if (level == 3 && node->gender == 0) {
            return "grandfather";
        }
        if (level == 3 && node->gender == 1) {
            return "grandmother";
        }
        if (node->gender == 0) {
            string s = "";
            for (int i = 0; i < level - 3; ++i) {
                s += "great-";
            }
            return s + "grandfather";
        }
        if (node->gender == 1) {
            string s = "";
            for (int i = 0; i < level - 3; ++i) {
                s += "great-";
            }
            return s + "grandmother";
        }


    } }else{
            return "unrelated";
        }

    }
int Tree::getLevelUtil(Tree *node,string data, int level)
{
    if (node == NULL)
        return 0;

    if (node -> name == data)
        return level;

    int downlevel = getLevelUtil(node->Mother, data, (level + 1));
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->father,
                             data, level + 1);
    return downlevel;
}

/* Returns level of given data value */
int Tree::getLevel(Tree *node, string data)
{
    return getLevelUtil(node, data, 1);
}

static vector<string> list;
vector<string> Tree::getNodesAtDistance(int distance)
{
    getNodesAtDistance(this, distance-1);
    return list;
}
string *a;
int i=0;
void Tree::getNodesAtDistance(Tree *root, int distance)
{
   // cout<<"list.size()"<<endl;

    if (root == NULL )
        return;

    if (distance == 0)
    {
       // cout<<"sdsd"<<endl;
        list.push_back(root->name);
//        cout<< list.at(i)<<endl;
//        i++;
        return;
    }
    if(root->father==NULL && root->Mother==NULL) {
        return;
    }

    if(root->Mother==NULL){
         getNodesAtDistance(root->father,distance-1);
    }
    if(root->father==NULL){
         getNodesAtDistance(root->Mother,distance-1);
    }

     getNodesAtDistance(root->Mother, distance - 1);
     getNodesAtDistance(root->father, distance - 1);
}
string Tree::find(string relation)
{

    string gender = "";
    if (relation == "me")
        return this->name;
    if (relation.at(0) == 'm')
        return this->Mother->name;
    if (relation.at(0) == 'f')
        return this->father->name;
    int size = relation.size();
    if(size>6) {
        char check = relation.at(size - 6);
        if (check == 'f')
            gender = "father";
        else
            gender = "mother";
        if (relation.at(2) == 'a') {
            if (gender == "father") {
                if (this->father->father != NULL)
                    return this->father->father->name;
                if (this->Mother->father != NULL)
                    return this->Mother->father->name;
            } else //mother
            {
                if (this->father->Mother != NULL)
                    return this->father->Mother->name;
                if (this->Mother->Mother != NULL)
                    return this->Mother->father->name;
            }
        }
    }
//cout<<relation.at(0)<<endl;
    if(relation.at(0)!='g'){
        throw std::exception();
    }
    int count = 3; //levels in tree
    for (size_t i = 0; i < relation.size(); i++)
    {
        if (relation.at(i) == '-')
            count++;
    }
   //cout<<count<<endl;
    vector<string> list = getNodesAtDistance(count);
    //cout<<"size"+list.size();

    for (size_t i = 0; i < list.size(); i++) {
        bool flag = findMe(this, list.at(i));
       // cout<<flag;
        if (flag == true) {
            if (gender == "father") {
                if (node->gender==0){
                return node->name;
            }}
             else {
                if (node->gender == 1)
                    return node->name;
            }
        }else{
            throw std::exception();
        }

        }



    }






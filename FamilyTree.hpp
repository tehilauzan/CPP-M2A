

#pragma once

#include <string>
#include <vector>
using namespace std;
namespace family {
    class Tree {
    private:
        string name;
        Tree *Mother;
        Tree *father;
        Tree *son;
        int gender;
    public:
        Tree(string name) {
            this->name = name;
            this->gender=0;
            this->father = this->Mother = this->son = NULL;
        }
        Tree(string name , Tree *son){
            this->name=name;
            this->son=son;
            this->Mother=this->father=NULL;
        }
Tree & addFather(string son , string father);
Tree & addMother(string son , string Mother);
        void display();
        void remove(string name);
        string relation(string name);
        string find(string relation);

    private:
        int getLevel(Tree *node, string name);
        int getLevelUtil(Tree *node, string name, int level);
        void getNodesAtDistance(Tree *root, int distance);
        vector<string> getNodesAtDistance(int distance);
        void print2DUtil(Tree *root, int space);
        bool findMe(Tree *root, string name_search);
    };
}






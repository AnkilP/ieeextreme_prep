#include <memory>
#include <iostream>

#define nullptr 0

class node_struct{
    int data;
    node_struct * leftnode_struct;
    node_struct * rightnode_struct;
    public: 
        node_struct(node_struct * left, node_struct * right, int value): leftnode_struct(left), rightnode_struct(right), data(value) {}

        int getData() const {
            return data;
        }
        node_struct * getleft() const {
            return leftnode_struct;
        }

        node_struct * getright() const {
            return rightnode_struct;
        }

        bool setright(node_struct * right){
            rightnode_struct = right;
            return true;
        }

        bool setleft(node_struct * left){
            leftnode_struct = left;
            return true;
        }

};

class graph_struct{

    node_struct * rootnode_struct;
    bool addvertex(node_struct * root, int value);
    bool deleteAll(node_struct * node_struct);
    public:
        graph_struct(node_struct * root){
            rootnode_struct = root;
        }
        node_struct * getroot(){
            return rootnode_struct;
        }
        bool checkBST(node_struct * root, int min, int max);
        bool addvertex(int value);
        void printGraph();

        ~graph_struct();

};

bool graph_struct::checkBST(node_struct * root, int min, int max){
    if(root == nullptr){
        return true;
    }

    if((max != nullptr && root->getData() >= max) || (min != nullptr && root->getData() < min)){
        return false;
    }

    if(!checkBST(root->getleft(), min, root->getData()) || !checkBST(root->getright(), root->getData(), max)){
        return false;
    }

    return true;
}

bool graph_struct::addvertex(int value){
    addvertex(this->rootnode_struct, value);
    return true;
}

bool graph_struct::addvertex(node_struct * root, int value){
    if(root->getData() <= value){
        if(root->getright() == nullptr){
            // std::cout << value << std::endl;
            node_struct * right = new node_struct((node_struct *) nullptr, (node_struct *) nullptr, value);
            root->setright(right);
        }
        else{
            addvertex(root->getright(), value);
        }
    }
    else{
        if(root->getleft() == nullptr){
            // std::cout << value << std::endl;
            node_struct * left = new node_struct((node_struct *) nullptr, (node_struct *) nullptr, value);
            root->setleft(left);
        }
        else{
            addvertex(root->getleft(), value);
        }
    }
    return true;
}

bool graph_struct::deleteAll(node_struct * node_struct){
    if(node_struct->getright() == nullptr && node_struct->getleft() == nullptr){
        free(node_struct);
        return true;
    }
    else if(node_struct->getright() == nullptr && node_struct->getleft() != nullptr){
        deleteAll(node_struct->getleft());
    }
    else if(node_struct->getright() != nullptr && node_struct->getleft() == nullptr){
        deleteAll(node_struct->getright());
    }
    else{
        deleteAll(node_struct->getleft());
        deleteAll(node_struct->getright());
    }
    return true;
}

graph_struct::~graph_struct(){
    deleteAll(this->rootnode_struct);
}

void printBT(const std::string& prefix, const node_struct * rootnode_struct)
{
    if( rootnode_struct != nullptr )
    {
        std::cout << prefix;

        std::cout << (rootnode_struct->getleft() != nullptr ? "├──" : "└──" );

        // print the value of the node_struct
        std::cout << rootnode_struct->getData() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (rootnode_struct->getleft() != nullptr ? "│   " : "    "), rootnode_struct->getleft());
        printBT( prefix + (rootnode_struct->getleft() != nullptr ? "│   " : "    "), rootnode_struct->getright());
    }
}

void printBT(const node_struct * rootnode_struct)
{
    printBT("", rootnode_struct);    
}

int main(){
    auto rootnode_struct = std::make_unique<node_struct>((node_struct *) nullptr, (node_struct *) nullptr, 10);
    auto binary_search_tree = std::make_unique<graph_struct>(rootnode_struct.get());

    binary_search_tree->addvertex(11);
    binary_search_tree->addvertex(9);
    binary_search_tree->addvertex(5);
    binary_search_tree->addvertex(99);

    printBT(rootnode_struct.get());
    bool isBST = binary_search_tree->checkBST(binary_search_tree->getroot(), nullptr, nullptr);
    // std::cout << isBST << std::endl;
}
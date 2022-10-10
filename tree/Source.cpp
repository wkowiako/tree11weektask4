
#include <iostream>
class Node {
    Node* top = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    int v;
public:
    int poziom;
    Node(int a);
    int Zag();
    void AddNood(int b);
    bool finD(int a);
    void screen();
    bool remove(int a);
};

Node::Node(int a): v(a) , poziom(1) {

}
bool Node::remove(int a){
    if (this -> v == a) return true;
    if (this -> v < a) {// prawo
        if (this-> right == nullptr) return false;
        else if (this -> right -> v == a) {
            this -> right = nullptr;
        }
        else this -> right -> remove(a);
    }
    else {
        if (this -> left == nullptr) return false;
        else if (this -> left -> v == a) {
            this -> left = nullptr;
        }
        else this -> left -> remove(a);
    }; //lewo
}

int Node::Zag() {
    static int zag = 1; // kasowanie staticka
    if (this->right == nullptr && this->left == nullptr) {
        if(this->poziom > zag)zag = this->poziom;
    }
    else if (this->right != nullptr) {
        this->right->Zag();
    }
    else if (this->left != nullptr) {
        this->left->Zag();
    }
    return zag;
    //tutaj ma byc kasowanie :P
}; 
 

void Node::screen() {
     
        int gl = Zag();
  
     std::cout << this-> v << std::endl;
     if (this->right == nullptr) std::cout <<" rihgt "<< this->v << " null " << std::endl;
     else{   
        this->right->screen();
     }
     if (this->left == nullptr) std::cout <<" left " << this->v << " null " << std::endl;
     else {
         this->left->screen();
     }
}

void Node::AddNood(int b)
{
    if (b > v) {
        if (this -> right == nullptr) {
            this -> right = new Node(b);
            this -> right -> top = this;
            this -> right -> poziom += this -> poziom ;
            std::cout << "new element " << b << " right \n";
        }
        else if (this -> right != nullptr) {
            this -> right -> AddNood(b);
        }
    }
    else if (b < v) {
        if (this -> left == nullptr) {
            this -> left = new Node(b);
            this -> left -> top = this;
            this -> left -> poziom += this -> poziom ;
            std::cout << "new element " << b << " left \n";
        }
        else if (this -> left != nullptr) {
            this -> left -> AddNood(b);
        }
    }
    else std::cout<< "value exist " <<std::endl;

}

bool Node::finD(int a) {

    if (this -> v == a) return true;
    if (this -> v < a) {// prawo
        if (this -> right == nullptr) return false;

        else this -> right -> finD(a);
    }
    else {
        if (this -> left == nullptr) return false;

        else this -> left -> finD(a);
    }; //lewo
    //std::cout << "cos ";
}
    

int main()
{
    Node root(10);
    root.AddNood(6);
    root.AddNood(15);
    root.AddNood(8);
    root.AddNood(1);
    root.AddNood(17);
   // root.AddNood(13);
     //testy 
   // if (root.finD(6) == true) std::cout << "success :D \n";
   // else std::cout << "error :( \n";

   // if (root.finD(13) == true) std::cout << "error :(  \n";
   // else std::cout << "success:P \n";

   // root.remove(6);
   // if (root.finD(6) == true) std::cout << "success :D \n";
   // else std::cout << "error :( \n";
    root.screen();

    return 0;
}




#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
   
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

    public:
        Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
            : data(d), parent(p), left(l), right(r) {}

        Bst<T>* insert(const T d) {
            if (data > d){
                if (left == nullptr){
                    left = new Bst(d,this);
                    return left;
                }
                else{
                    return left->insert(d);
                }
            }
            else if (data < d){
                if (right == nullptr){
                    right = new Bst(d,this);
                    return right;
                }
                else{
                    return right->insert(d);
                }
            }
        }
        T min(){
            if (left == nullptr){
                return data;
            }
            else if (left->data){
                return left->min();
            }
        }

        T max(){
            if (right == nullptr){
                return data;
            }
            else if (right->data){
                return right->max();
            }
        }

        T get_val() const {
            return data;
        }

        Bst<T>* search(const T d){
            if (data == d){
                return this;
            }
            else if (data > d){
                return right->search(d);
            }
            else{
                return left->search(d);
            }
        }

        Bst<T>* predecessor(const T d){
            if (left){
                return search(left->max());
            }
            else{
                while(parent){
                    if (parent->data < d){
                        break;
                    }
                    parent = parent->parent;
                }
                return parent;
            }
        }

    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};


//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}
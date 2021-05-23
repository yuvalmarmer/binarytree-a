

#pragma once
namespace ariel{
    template<typename T>
    class BinaryTree{
        
        public:
            BinaryTree& add_root(T root){return *this;};
            BinaryTree& add_left(T child, T root){return *this;};
            BinaryTree& add_right(T child ,T root){return *this;};

            friend std::ostream& operator<< (std::ostream& os, const BinaryTree& n){return os;};
            
            // inner class
            struct Node {       
                T m_value;
                Node* m_next;
                Node(const T& v, Node* n)
                    : m_value(v), m_next(n) {
                }
            };

            // fields
            Node* m_first;  

            class preorder{

                private:
		            Node* pointer_to_current_node;
                public:


                    preorder(Node* ptr = nullptr)
                        : pointer_to_current_node(ptr) {
                    }

                    T& operator*() const {
                        //return *pointer_to_current_node;
                        // T& temp;
                        // return temp;
                        return pointer_to_current_node->m_value;
                    }
                    T* operator->() const {
                        // T* temp;
                        // return temp;
                        return &(pointer_to_current_node->m_value);

                    }

                    // ++i;
                    preorder& operator++() {
                        //++pointer_to_current_node;
                        // pointer_to_current_node = pointer_to_current_node->m_next;
                        return *this;
                    }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    const preorder operator++(int) {
                        preorder tmp= *this;
                        // pointer_to_current_node= pointer_to_current_node->m_next;
                        return tmp;
                    }

                    bool operator==(const preorder& rhs) const {
                        return false;
                    }

                    bool operator!=(const preorder& rhs) const {
                        return false;
                    }
            };
            class inorder{



                
                private:
		            Node* pointer_to_current_node;
                public:


                    inorder(Node* ptr = nullptr)
                        : pointer_to_current_node(ptr) {
                    }
                    
                    T& operator*() const {
                        //return *pointer_to_current_node;
                        return pointer_to_current_node->m_value;
                        // T& temp;
                        // return temp;
                    }

                    T* operator->() const {
                        return &(pointer_to_current_node->m_value);
                        // T& temp;
                        // return temp;
                    }

                    // ++i;
                    inorder& operator++() {
                        //++pointer_to_current_node;
                        // pointer_to_current_node = pointer_to_current_node->m_next;
                        return *this;
                    }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    const inorder operator++(int) {
                        inorder tmp= *this;
                        // pointer_to_current_node= pointer_to_current_node->m_next;
                        return tmp;
                    }

                    bool operator==(const inorder& rhs) const {
                        // return pointer_to_current_node == rhs.pointer_to_current_node;
                        return false;
                    }

                    bool operator!=(const inorder& rhs) const {
                        // return pointer_to_current_node != rhs.pointer_to_current_node;
                        return false;
                    }
            };
            class postorder{
                private:
		            Node* pointer_to_current_node;
                public:


                    postorder(Node* ptr = nullptr)
                        : pointer_to_current_node(ptr) {
                    }
                    T& operator*() const {
                        //return *pointer_to_current_node;
                        return pointer_to_current_node->m_value;
                        // T& temp;
                        // return temp;
                    }

                    T* operator->() const {
                        return &(pointer_to_current_node->m_value);
                        // T* temp;
                        // return temp;
                    }

                    // ++i;
                    postorder& operator++() {
                        //++pointer_to_current_node;
                        // pointer_to_current_node = pointer_to_current_node->m_next;
                        return *this;
                    }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    const postorder operator++(int) {
                        postorder tmp= *this;
                        // pointer_to_current_node= pointer_to_current_node->m_next;
                        return tmp;
                    }

                    bool operator==(const postorder& rhs) const {
                        // return pointer_to_current_node == rhs.pointer_to_current_node;
                        return false;
                    }

                    bool operator!=(const postorder& rhs) const {
                        // return pointer_to_current_node != rhs.pointer_to_current_node;
                        return false;
                    }
            };

            preorder begin_preorder(){return preorder{m_first};};
            preorder end_preorder(){return preorder{nullptr};};

            inorder begin_inorder(){return inorder{m_first};};
            inorder end_inorder(){return inorder{nullptr};};

            postorder begin_postorder(){return postorder{m_first};};
            postorder end_postorder(){return postorder{nullptr};};

            inorder begin() {
                // return &(m_first->m_value); 
                return inorder{m_first};
            }
	
            inorder end() {
                // return nullptr; 
                return inorder{nullptr};
            }
        private:
    
    };
}
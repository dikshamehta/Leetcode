class Node{
    public:
        int val;
        Node* next;

        //Node(int x): val(x), next(nullptr) {}

        Node(int val){
            this->val = val;
            next = nullptr;
        }
};

class MyLinkedList {
public:
    Node* head;
    int size;

    MyLinkedList() : head(nullptr), size(0) {}
    
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node* current = head;
        for(int i=0; i<index; i++){
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        //create a node
        Node* new_node = new Node(val);
        new_node->next = head; //setting next to nullptr
        head = new_node;
        size++;
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        Node* current = head;
        for(int i=0; i<index-1; i++){
            current = current->next;
        }

        Node* new_node = new Node(val);
        new_node->next = current->next;
        current->next = new_node;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index>=size || index < 0) return;

        if(index == 0){
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }
        else{
            Node* current = head;
            for(int i=0; i<index-1; i++){
                current = current->next;
            }

            Node* nextNode = current->next->next;
            delete current->next;
            current->next = nextNode;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
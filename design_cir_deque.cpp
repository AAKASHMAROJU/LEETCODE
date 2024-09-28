// Link: https://leetcode.com/problems/design-circular-deque

class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int d){
        this->left=NULL;
        this->right=NULL;
        this->data=d;
    }
};


class MyCircularDeque {
public:
    int size;
    Node* front;
    Node* rear;
    int max_size;
    MyCircularDeque(int k) {
        this->max_size=k;
        this->front=NULL;
        this->rear=NULL;
        this->size=0;
    }
    
    bool insertFront(int value) {
        if(front==NULL && rear==NULL){
            front=new Node(value);
            rear=front;
            size++;
            return true;
        }
        if(size>=max_size) return false;
        Node* temp=new Node(value);
        temp->right=front;
        size++;
        front->left=temp;
        front=temp;
        return true;
    }
    
    bool insertLast(int value) {
        if(front==NULL && rear==NULL){
            front=new Node(value);
            rear=front;
            size++;
            return true;
        }
        if(size>=max_size) return false;
        Node* temp=new Node(value);
        rear->right=temp;
        temp->left=rear;
        rear=temp;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(!front && !rear) return false;
        if(front==rear ){
            front=rear=NULL;
            size--;
            return true;
        }
        size--;
        Node* temp=front;
        front=front->right;
        temp->right=NULL;
        // free(temp);
        return true;
    }
    
    bool deleteLast() {
        if(!front && !rear) return false;
        if(front==rear ){
            front=rear=NULL;
            size--;
            return true;
        } 
        size--;
        Node* temp=rear;
        rear=rear->left;
        rear->right=NULL;
        // free(temp);
        return true;
    }
    
    int getFront() {
        if(front==NULL) return -1;
        return front->data;
    }
    
    int getRear() {
        if(rear==NULL) return -1;
        return rear->data;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

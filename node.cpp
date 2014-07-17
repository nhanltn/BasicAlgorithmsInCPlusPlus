class Node{
    public:
    Node(int newValue){
        this.value = newValue;
    }
    
    private:
        int value;
        Node *next;
}
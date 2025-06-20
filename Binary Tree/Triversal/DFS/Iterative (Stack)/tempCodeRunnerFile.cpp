vector<int> vector_In(Node* root){                       // In order
    vector<int>v;
    stack<Node*>s;
    Node* node = root;

    while(node!=nullptr || !s.empty()){
        if(node!=nullptr){
            s.push(node);
            node = node->left;
        }
        else{
           Node* temp = s.top();
            s.pop();
            v.push_back(temp->data);
            node = temp->right;
        }
    }
    return v;
}
class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    
    void addNum(int num) {
    
        if(left.size()==0 || num<left.top()) left.push(num);
        else right.push(num);
    
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size()>left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==0 && right.size()==0) return 0.0;
        if(left.size()>right.size()){
            return double(left.top());
        }
        else if(right.size()>left.size()){
            return  double(right.top());
        }
        else{
            return double((left.top()+right.top())/2.0);
        }
    }
};

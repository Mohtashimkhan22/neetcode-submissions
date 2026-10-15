/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* solver(vector<vector<int>>& grid,int r,int c,int n){
        bool same = true;
        int value = grid[r][c];
        // cout<<value<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(value!=grid[i+r][j+c]){
                    same = false;
                    break;
                }
            }
            if(!same) break;
        }
        if(same){
            return new Node(value,1);
        }
        int mid = n/2;
        Node* tl = solver(grid,r,c,mid);
        Node* tr = solver(grid,r,c+mid,mid);
        Node* bl = solver(grid,r+mid,c,mid);
        Node* br = solver(grid,r+mid,c+mid,mid);
        return new Node(value,0,tl,tr,bl,br);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        // cout<<n;
        return solver(grid,0,0,n);
    }
};
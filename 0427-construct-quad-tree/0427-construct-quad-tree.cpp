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
public:
    Node* build(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return new Node(grid[x][y], true);
        }

        int half = n / 2;

        Node* TL = build(grid, x, y, half);
        Node* TR = build(grid, x, y + half, half);
        Node* BL = build(grid, x + half, y, half);
        Node* BR = build(grid, x + half, y + half, half);

        if (TL->isLeaf && TR->isLeaf && BL->isLeaf && BR->isLeaf &&
            TL->val == TR->val && TL->val == BL->val && TL->val == BR->val) {
            int val = TL->val;
            delete(TL);
            delete(TR);
            delete(BL);
            delete(BR);

            return new Node(val, true);
        }

        return new Node(1, false, TL, TR, BL, BR);
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // BFS solution
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* clone = new Node(node->val);

        unordered_map<Node*, Node*> clones; // hash map mapping original node to clone
        clones[node] = clone;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            for (auto& neighbor : front->neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    clones.insert({neighbor, new Node(neighbor->val)});
                    q.push(neighbor);
                }
                clones[front]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clone;
    }
};

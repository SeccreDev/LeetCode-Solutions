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

class Solution
{
    public:
        vector<Node*>nodelist; //list of clone nodes created
        void dfs(Node*actual, Node*clone)
        {
            for(auto neighbor: actual->neighbors)
            { //all neighbors of actual node
                if(nodelist[neighbor->val]==NULL)
                { //neighbor's clone not created
                    Node *newnode=new Node(neighbor->val); //create copy
                    nodelist[neighbor->val]=newnode; //add clone to clone list
                    clone->neighbors.push_back(newnode); //add neighbor's copy in neighbor list of parent/curr clone
                    dfs(neighbor,newnode); //recursively pass actual and clone neighbor
                }
                else
                {//neighbor's clone already exists
                    clone->neighbors.push_back(nodelist[neighbor->val]); //establish connection of neighbor's clone and parent clone
                }
            }
        }
        Node* cloneGraph(Node* node)
        {
            if(node==NULL) return NULL;
            nodelist.resize(101,NULL); //max 100 nodes as given in constraints
            Node*clone=new Node(node->val); //clone of source node
            nodelist[node->val]=clone; //add to clone list
            dfs(node,clone); //traverse actual and clone graphs
            return clone;
        }
};
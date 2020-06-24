#include <vector>
#include <string>
#include <map>

// YOU CAN USE ONLY THE VECTORS, STRINGS AND MAPS FOR THIS ASSIGNMENT!

class GraphTemplate {
private:
    std::vector<NodeTemplate> nodes;
    MinHeapTemplate *minPriorityQueue;
    bool isDirected;

public:
    // Constructor
    GraphTemplate(NodeTemplate firstNode) {
      nodes.push_back(firstNode);
    }

    // Destructor
    ~GraphTemplate() {
      while(nodes.size() != 0) {
        nodes.pop_back();
      }
    };

    // Inserts a new node at the end of vector nodes
    void add_node(NodeTemplate newNode) {
      nodes.push_back(newNode);
    }

    // Returns position of the node where
    // node.label == label searched for
    int find(std::string findLabel) {
      int i = 0;
      while(i < nodes.size()) {
        if(nodes[i].get_label() == findLabel) {
          return i;
        }
        ++i;
      }
      return -1;
    }

    // Removes node which label == deleteLabel
    // by using the vector.erase() function and giving
    // it an iterator on this node.
    // Iterator is calculated by starting at the 0th node (begin())
    // and then adding the position int which is found by find()
    void remove_node(std::string deleteLabel) {
      if (find(deleteLabel) == -1) {
        return;
      }
      nodes.erase(nodes.begin() + find(deleteLabel));
    }


    // TODO: implement Prim
    // TODO: implement Bellman-Ford
    // TODO: implement printGraph function that generates a file written using the dot format
};

class NodeTemplate {
private:
    /* data */
    std::string label;
    std::map<NodeTemplate, int> adjacentNodes; // the int is for the weight od the egde
    NodeTemplate *parent = nullptr; // previous node in graph vector
    int distance; // aka key

public:
    // Constructor
    NodeTemplate(std::string newLabel) {
      label = newLabel;
    }

    // Destructor
    //~NodeTemplate() {
    //
    //};
    
    // Getter function for label
    // needed for GraphTemplate::find() function
    std::string get_label() {
      return label;
    }
    
    // Adds a connection from *this node to newNeighbourNode
    // with a distanceTo as weight of the new connection.
    void add_connection(NodeTemplate const& newNeighbourNode, int weightOf) {
      adjacentNodes.insert({newNeighbourNode, weightOf});
    }

    // Removes a connection from *this node to deleteNode
    // by using map.erase() function.
    void remove_connection(NodeTemplate const&/*???*/ deleteNode) {
      adjacentNodes.erase(deleteNode);
    }
    
    // Set new parent
    void change_parent(NodeTemplate const& newParent) {
      *this->parent = newParent;
    }

    // Set new distance
    void change_distance(int newDistance) {
      distance = newDistance;
    }
    
};

class MinHeapTemplate {
private:
    MinHeapNodeTemplate *root;

public:
    MinHeapTemplate(/* args */);
    ~MinHeapTemplate();
    // TODO: implement method for restructuring the min-priority Queue
    // TODO: implement method for extracting the smaller element from the min-priority Queue
};

class MinHeapNodeTemplate{
private:
    /* data */
    NodeTemplate *node;
    MinHeapNodeTemplate *parent;
    MinHeapNodeTemplate *left;
    MinHeapNodeTemplate *right;

public:
    MinHeapNodeTemplate(/* args */);
    ~MinHeapNodeTemplate();

    MinHeapNodeTemplate();
};
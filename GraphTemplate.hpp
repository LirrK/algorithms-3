#include <vector>
#include <string>
#include <map>

struct edge;
class edgeList;
class Node;
class Graph;
class MinHeapNode;
class MinHeap;
// YOU CAN USE ONLY THE VECTORS, STRINGS AND MAPS FOR THIS ASSIGNMENT!

/*
struct edge {
  edge(Node start, Node end, int edgeWeight): start_(start), end_(end), edgeWeight_(edgeWeight){}

  Node start_;
  Node end_;
  int edgeWeight_;
};

class edgeList {
public:
  std::vector<edge> edgeList;
  //int find_position_of_edge_between(Node start, Node end) {
  //  for(int i = 0; i < edgeList.size(); ++i) {
    //  if()
  //  }
  //}
  void add(edge newEdge) {
    edgeList.push_back(newEdge);
  }
  void pop(edge removeEdge) {
    for(int i = 0; i < edgeList.size(); ++i) {
      if(removeEdge.start_.get_label() == edgeList[i].start_.get_label() &&
      removeEdge.end_.get_label() == edgeList[i].end_.get_label()) {
        edgeList.erase(edgeList.front() + i);
      }
    }
  }
  void add_all(Node node) {

  }
  void pop_all(Node node) {

  }
};
*/

class Node {
private:
    /* data */
    std::string label;
    std::map<Node, int> adjacentNodes; // the int is for the weight of the edge
    Node *parent = nullptr; // previous node in graph vector
    int distance; // aka key

public:
    // Constructor
    Node(std::string newLabel) {
      label = newLabel;
    }

    // Destructor
    //~Node() {
    //
    //};
    
    // Getter function for label
    // needed for Graph::find() function
    std::string get_label() {
      return label;
    }
    
    // Adds a connection from *this node to newNeighbourNode
    // with a distanceTo as weight of the new connection.
    void add_connection(Node const& newNeighbourNode, int weightOf) {
      adjacentNodes.insert({newNeighbourNode, weightOf});
    }

    // Removes a connection from *this node to deleteNode
    // by using map.erase() function.
    void remove_connection(Node const&/*???*/ deleteNode) {
      adjacentNodes.erase(deleteNode);
    }
    
    // Set new parent
    void change_parent(Node const& newParent) {
      *this->parent = newParent;
    }

    // Set new distance
    void change_distance(int newDistance) {
      distance = newDistance;
    }
    
};

class MinHeapNode{
private:
    /* data */
    Node *node;
    MinHeapNode *parent = nullptr;
    MinHeapNode *left = nullptr;
    MinHeapNode *right = nullptr;

public:
    MinHeapNode(Node const& newNode) {
      *this->node = newNode;
    }
    //~MinHeapNode();
};

class MinHeap {
private:
    //std::vector<MinHeapNode> heapNodes;
    MinHeapNode *root;

public:
    MinHeap(MinHeapNode const& firstNode) {
      //heapNodes.push_back(firstNode);
      *this->root = firstNode;
    }

    ~MinHeap();
    // TODO: implement method for restructuring the min-priority Queue
    void restructure() {
      
      return;
    }

    // TODO: implement method for extracting the smaller element from the min-priority Queue
};

class Graph {
private:
    std::vector<Node> nodes;
    MinHeap* minPriorityQueue;
    bool isDirected;

public:
    // Constructor
    Graph(Node const& firstNode) {
      nodes.push_back(firstNode);
    }

    // Destructor
    ~Graph() {
      while(nodes.size() != 0) {
        nodes.pop_back();
      }
    };

    // Inserts a new node at the end of vector nodes
    void add_node(Node const& newNode) {
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


    void prim() {
      
    }
    // TODO: implement Prim
    // TODO: implement Bellman-Ford
    // TODO: implement printGraph function that generates a file written using the dot format
};


int main(int argc, char* argv[])
{

  return 0;
}
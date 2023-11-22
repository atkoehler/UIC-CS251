/// @file treegen.cpp
/// @author Adam T Koehler, PhD
/// @date November 14, 2023
/// @brief A simple C++ example of building a tree from a vector using
///        the mathematical algorithms associated with heaps.
///      
///        Requires C++20, compile with -std=c++20

// Copyright Notice
// This document is protected by U.S. copyright law. Reproduction and 
// distribution of this work, including posting or sharing through any medium, 
// is explicitly prohibited by law, and also violates UIC's Student 
// Disciplinary Policy (A2-c. Unauthorized Collaboration; and A2-e3. 
// Participation in Academically Dishonest Activities: Material Distribution).

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode 
{
   TreeNode* left;
   TreeNode* right;
   int val;

   TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

void levelVector(const auto &root, vector<int> &v);
void print(const auto &);

/// @brief generate a tree from a vector of integers
/// @param v vector containing all the node's values
/// @return the root of the tree
TreeNode* create(const auto &v)
{
   // empty vector, empty tree
   if (v.size() == 0)
   {
      return nullptr;
   }

   // Generate a node for each vector element
   vector<TreeNode*> nodes;
   for(const auto &value : v)
   {
      nodes.push_back(new TreeNode(value));
   }

   // Link the nodes
   for(int parent = 0; parent < nodes.size(); ++parent)
   {
      // attempt to link right child
      if (parent * 2 + 2 < nodes.size())
      {
         nodes.at(parent)->right = nodes.at(parent * 2 + 2);
      }

      // attempt to link left child
      if (parent * 2 + 1 < nodes.size())
      {
         nodes.at(parent)->left = nodes.at(parent * 2 + 1);
      }
      else
      {
         // no left child, in a min-heap array storage design
         // that makes it a leaf, no more children will exist
         break;
      }
   }

   // return the root node
   return nodes.at(0);
}


int main () 
{
   vector<int> n = {1, 3, 2, 17, 25, 36, 7, 100, 19};
   vector<int> fromTree;
   levelVector(create(n), fromTree);

   cout << "Initial vector:" << endl;
   print(n);

   cout << "Level by level vector built from tree:" << endl;
   print(fromTree);
}

/// @brief print out the container, each element separated by a space
/// @param v the container to print
void print(const auto &v)
{
   for(const auto &e: v)
   {
      cout << e << ' ';
   }
   cout << endl;
}

/// @brief convert a tree in a vector by level, left to right
/// @param n the root of the tree 
/// @param v the vector to build
void levelVector(const auto &n, vector<int> &v)
{
   if (n == nullptr)
   {
      return;
   }

   queue<TreeNode*> bfsq;
   bfsq.push(n);
   unordered_set<TreeNode*> disc;

   while (!bfsq.empty())
   {
      // pull from queue
      TreeNode *cur = bfsq.front();
      bfsq.pop();

      // don't repeat
      disc.insert(cur);

      // process current node
      v.push_back(cur->val);

      // put children on queue if undiscovered
      if (cur->left != nullptr && disc.count(cur->left) == 0)
         bfsq.push(cur->left);
      if (cur->right != nullptr && disc.count(cur->right) == 0)
         bfsq.push(cur->right);
   }
}
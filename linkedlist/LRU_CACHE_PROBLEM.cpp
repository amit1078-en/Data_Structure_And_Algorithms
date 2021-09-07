/*
https://leetcode.com/submissions/detail/546714022/
146. LRU Cache
Medium

9797

387

Add to List

Share
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
the capacity from this operation, evict the least recently used key.
 
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put


*/


class Node
{
  public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int d)
    {
      data = d;
      next = NULL;
      prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,int> maap;
    int element;
    int start;
    Node* rear;
    Node* last;
    unordered_map<int,Node*> seet;
    LRUCache(int capacity) 
    {
        start = 0;
        element = capacity;   
        maap.clear();
        seet.clear();
        rear = last = NULL;
    }
  
   
  
    int get(int key)
    {
        if(maap.find(key)==maap.end())
        {
          return  -1;
        }
       Node* getindex = seet[key];
       if(getindex->next==NULL)
       {
         return maap[key];
       }
       if(rear==getindex)
       {
         rear = rear->next;
         rear->prev = NULL;
       }
       else
       {
         getindex->next->prev = getindex->prev;
           getindex->prev->next = getindex->next;
       }
       getindex->next = NULL;
       last->next = getindex;
       getindex->prev = last;
       last = getindex;
      return maap[key];
    }
    
  
  
  
    void put(int key, int value) 
    {

     if(maap.find(key)!=maap.end())
     {
       maap[key] = value;
       Node* getindex = seet[key];
       if(getindex->next==NULL)
       {
         return ;
       }
       if(rear==getindex)
       {
         rear = rear->next;
         rear->prev = NULL;
       }
       else
       {
         getindex->next->prev = getindex->prev;
         getindex->prev->next = getindex->next;
       }
       getindex->next = NULL;
       last->next = getindex;
       getindex->prev = last;
       last = getindex;
       return ;
     }
            maap[key] = value;
     if(start<element)
     {
          Node* temp = new Node(key);
          seet[key] = temp;
         if(rear==NULL)
         {

           last = temp;
           rear = temp;
         }
         else 
         {
            temp->prev = last;
           last->next = temp;
           last = temp;
         }
       start++;
       
       return ;
     }
      Node* temp = new Node(key);
      temp->prev = last;
      last->next = temp;
      last = temp;
      Node* front = rear;
      rear = rear->next;
      seet[key] = temp;
      
      maap.erase(front->data);
      seet.erase(front->data);
      
     return ; 
    }
};


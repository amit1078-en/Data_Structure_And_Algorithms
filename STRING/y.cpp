#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

// A utility function to get the middle index_of from corner indexes.
int getMid(int s, int e) { return s + (e -s)/2; }
 
/* A recursive function to get the sum of values in the given range
    of the array. The following are parameters for this function.
 
    st --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
            0 is passed as root is always at index_of 0
    ss & se --> Starting and ending indexes of the segment represented
                by current node, i.e., st[si]
    qs & qe --> Starting and ending indexes of query range */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes which have the given
index_of in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i --> index_of of the element to be updated. This index_of is
            in the input array.
diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index_of lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;
 
    // If the input index_of is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index_of
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input";
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index_of qs (query start)
// to qe (query end). It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index_of of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
            constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
allocates memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for the segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;
 
    // Allocate memory
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
void solve()
{
	int size;
    cin>>size;
    int arrayfirst[size][32];
    int arraysecond[size][32];
      int stuff[size][32];
	for(int i=0;i<size;i++)
{
    for(int j=0;j<32;j++)
    {
        arraysecond[i][j]=0;
        arrayfirst[i][j]=0;
        stuff[i][j]=0;
    }
}
    bool turnbit[size]={false};
 
 
      int x;
        int index_of;
    for(int i=0;i<size;i++)
    {
 
      cin>>x;
       index_of=0;
      while(x>0)
      {
        int rem=x%2;
        arrayfirst[i][index_of]=rem;
        x/=2;
        index_of++;
      }
    }
    for(int i=0;i<size;i++)
    {
 
      cin>>x;
       index_of=0;
      while(x>0)
      {
        int rem=x%2;
        arraysecond[i][index_of]=rem;
        x/=2;
        index_of++;
      }
    }
 
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<32;j++)
      {
        stuff[i][j]=(arrayfirst[i][j]|arraysecond[i][j]);
        //cout<<stuff[i][j]<<" ";
      }
      //cout<<endl;
    }
    for(int i=1;i<size;i++)
    {
      for(int j=0;j<32;j++)
      {
        stuff[i][j]=stuff[i-1][j]+stuff[i][j];
      }
    }
    int lastform=-1;
    for(int i=31;i>=0;i--)
    {
      if(stuff[size-1][i]==size)
      {
        lastform=i;
        break;
      }
    }
 
    if(lastform==-1)
    {
      cout<<"0 0\size";
    }
    else
    {
      int solution=0;
      int flipp=0;
      
      int tt=lastform;
      while(lastform>=0)
      {
        bool ff=false;
        for(int i=0;i<size;i++)
        {
          if(turnbit[i]==false)
          {
            if(arrayfirst[i][lastform]==1)
            {
              //nothing
            }
            else
            {
              bool fz=false;
              for(int j=lastform;j<=tt;j++)
              {
                if(arrayfirst[i][j]>arraysecond[i][j])
                {
                  fz=true;
                  break;
                }
              }
              if(fz==false&&arraysecond[i][lastform]==1)
              {
                flipp++;
                turnbit[i]=true;
 
              }
            }
          }
          else
          {
            if(arraysecond[i][lastform]==1)
            {
              //nothing
            }
            else
            {
              ff=true;
              break;
            }
          }
        }
        if(ff==false)
 
        {solution=solution+pow(2,lastform);}
      lastform--;
 
      }
 
      cout<<solution<<" "<<flipp<<endl;
    }
}
 
// trie node
//class TrieNode
//{
//    struct TrieNode *children[ALPHABET_SIZE];
// 
//    // isEndOfWord is true if the node represents
//    // end of a word
//    bool isEndOfWord;
//};
// 
//// Returns new trie node (initialized to NULLs)
//struct TrieNode *getNode(void)
//{
//    struct TrieNode *pNode =  new TrieNode;
// 
//    pNode->isEndOfWord = false;
// 
//    for (int i = 0; i < ALPHABET_SIZE; i++)
//        pNode->children[i] = NULL;
// 
//    return pNode;
//}
// 
//// If not present, inserts key into trie
//// If the key is prefix of trie node, just
//// marks leaf node
//void insert(struct TrieNode *root, string key)
//{
//    struct TrieNode *baby = root;
// 
//    for (int i = 0; i < key.length(); i++)
//    {
//        int index_of = key[i] - 'a';
//        if (!baby->children[index_of])
//            baby->children[index_of] = getNode();
// 
//        baby = baby->children[index_of];
//    }
// 
//    // mark last node as leaf
//    baby->isEndOfWord = true;
//}
// 
//// Returns true if key presents in trie, else
//// false
//bool search(struct TrieNode *root, string key)
//{
//    struct TrieNode *baby = root;
// 
//    for (int i = 0; i < key.length(); i++)
//    {
//        int index_of = key[i] - 'a';
//        if (!baby->children[index_of])
//            return false;
// 
//        baby = baby->children[index_of];
//    }
// 
//    return (baby->isEndOfWord);
//}

int32_t main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
}

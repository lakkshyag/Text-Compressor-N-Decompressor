#include <iostream>
using namespace std;

template <typename T>
class nodeQ
{
    public:
    T data;
    nodeQ<T>* next;

    nodeQ(T x)
    {
        data = x;
        next = NULL;
    }
};

template <typename T>
class queue
{
    int size;
    nodeQ<T>* front;
    nodeQ<T>* rear;

    public:
    queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T x)
    {
        if ( isEmpty() == true )
        {
            front = new nodeQ<T>(x);
            rear = front;
        }
        else
        {
            (*rear).next = new nodeQ<T>(x);
            rear = (*rear).next;
        }
        size++;
    }

    T dequeue()
    {
        if ( isEmpty() == true )
        {
            cout<<"Queue Underflow!"<<endl;
            return 0;
        }
        else
        {
            T x = (*front).data;
            nodeQ<T>* next = (*front).next;
            delete front;
            front = next;
            size--;
            return x;
        }
    }
    
    T getFront()
    {
        if ( isEmpty() == true )
        {
            cout<<"Queue Underflow!"<<endl;
            return 0;
        }
        else
        {
            T x = (*front).data;
            return x;
        }
    }

    void purge()
    {
        while ( front != NULL )
        {
            nodeQ<T>* next = (*front).next;
            delete front;
            front = next;
        }
        rear = NULL;
        size = 0;
    }

    void print()
    {
        if ( isEmpty() )
        {
            cout<<"Queue Underflow!"<<endl;
            return;
        }
        nodeQ<T>* temp = front;
        while ( temp != NULL )
        {
            cout<<(*temp).data<<" ";
            temp = (*temp).next;
        }
        cout<<endl;
    }
};

template <typename T>
class binaryTreeNode
{
    public:
    T data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(T x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};


// void treePrint(binaryTreeNode<int>* root)
// {
//     if ( root == NULL )
//     {
//         return;
//     }
//     else
//     {
//         cout<< (*root).data <<" ";
//         treePrint((*root).left);
//         treePrint((*root).right);
//     }
// }

// binaryTreeNode<int>* treeCreateLevel()
// {
//     cout<<"Enter root data: ";
//     int rootData;
//     cin>>rootData;
//     if ( rootData == -1 )
//     {
//         return NULL;
//     }

//     binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
//     queue<binaryTreeNode<int>*> pendingNodes;
//     pendingNodes.enqueue(root);

//     while ( !pendingNodes.isEmpty() )
//     {
//         binaryTreeNode<int>* front = pendingNodes.dequeue();
        
//         cout<<"Enter left child of "<<(*front).data<<": ";
//         int leftChildData;
//         cin>>leftChildData;
//         if ( leftChildData != -1 )
//         {
//             binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChildData);
//             (*front).left = child;
//             pendingNodes.enqueue(child);
//         }

//         cout<<"Enter right child of "<<(*front).data<<": ";
//         int rightChildData;
//         cin>>rightChildData;
//         if ( rightChildData != -1 )
//         {
//             binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChildData);
//             (*front).right = child;
//             pendingNodes.enqueue(child);
//         }
//     }

//     return root;
// }

//     void treePrintLevel(binaryTreeNode<int>* root)
//     {
//         if ( root == NULL )
//         {
//             return;
//         }
        
//         queue<binaryTreeNode<int>*> pendingNodes;
//         pendingNodes.enqueue(root);

//         while ( !pendingNodes.isEmpty() )
//         {
//             binaryTreeNode<int>* front = pendingNodes.dequeue();
//             cout<<(*front).data<<": ";

//             if ( (*front).left != NULL )
//             {
//                 cout<<"L"<<(*(*front).left).data<<" ";
//                 pendingNodes.enqueue((*front).left);
//             }   
//             if ( (*front).right != NULL )
//             {
//                 cout<<"R"<<(*(*front).right).data<<" ";
//                 pendingNodes.enqueue((*front).right);
//                     }   
//             cout<<endl;
//         }
//     }

// void treePrintInorder(binaryTreeNode<int>* root)
// {
//     if ( root == NULL )
//     {
//         return;
//     }
//     else
//     {
//         treePrintInorder((*root).left);
//         cout<<(*root).data<<" ";
//         treePrintInorder((*root).right);
//     }
// }

// void treePrintPreorder(binaryTreeNode<int>* root)
// {
//     if ( root == NULL )
//     {
//         return;
//     }
//     else
//     {
//         cout<<(*root).data<<" ";
//         treePrintPreorder((*root).left);
//         treePrintPreorder((*root).right);
//     }
// }

// void treePrintPostorder(binaryTreeNode<int>* root)
// {
//     if ( root == NULL )
//     {
//         return;
//     }
//     else
//     {
//         treePrintPostorder((*root).left);
//         treePrintPostorder((*root).right);
//         cout<<(*root).data<<" ";
//     }
// }

// int heightTree(binaryTreeNode<int>* root)
// {
//     if ( root == NULL )
//     {
//         return 0;
//     }
//     else
//     {
//         int leftHeight = heightTree((*root).left);
//         int rightHeight = heightTree((*root).right);

//         int height;
//         if ( leftHeight >= rightHeight )
//         {
//             height = leftHeight;
//         }
//         else
//         {
//             height = rightHeight;
//         }
//         return height+1;
//     }
// }

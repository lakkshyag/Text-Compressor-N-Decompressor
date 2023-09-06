#include <unordered_map>
#include "binaryTree.h"
#include "priorityQueue.h"


void findFreq(int* arrayCharFreq, int* arrayCodeLen, string &input)
{
    int i = 0;
    while ( i <= 255 )
    {
        *(arrayCharFreq+i) = 0;
        *(arrayCodeLen+i) = 0;
        i++;
    }

    i = 0;
    int n = input.size();
    while ( i <= n-1 )
    {
        arrayCharFreq[input[i]]++;
        i++;
    }
}

void arrayPrint(int* arr, int n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        cout<<*(arr+i)<<" ";
        i++;
    }
    cout<<endl;
}

void fillMinPriorityQueue(priorityQueue<charFreq>* leastCount, int* arr)
{
    int i = 0;
    while ( i <= 255 )
    {
        if ( *(arr+i) > 0 )
        {
            charFreq curr(i, *(arr+i));
            (*leastCount).insert(curr);
        }
        i++;        
    }
}

void printPriorityQueue(priorityQueue<charFreq>* leastCount)
{
    while ( !(*leastCount).isEmpty() )
    {
        charFreq curr = (*leastCount).removeMin();
        cout<<curr.c<<" "<<curr.freq<<endl;
    }
}

binaryTreeNode<charFreq>* createBinaryTree(priorityQueue<charFreq>* leastCount)
{
    binaryTreeNode<charFreq>* root = NULL;

    while ( (*leastCount).getSize() >= 2 )
    {
        if ( root == NULL )
        {
            charFreq min = (*leastCount).removeMin();
            charFreq minSec = (*leastCount).removeMin(); 

            binaryTreeNode<charFreq>* minNode = new binaryTreeNode<charFreq>(min);
            binaryTreeNode<charFreq>* minSecNode = new binaryTreeNode<charFreq>(minSec);

            charFreq bridge(min.freq + minSec.freq);
            binaryTreeNode<charFreq>* bridgeNode = new binaryTreeNode<charFreq>(bridge);

            (*bridgeNode).left = minNode;
            (*bridgeNode).right = minSecNode;
            root = bridgeNode;
        }
        else
        {
            charFreq min = (*leastCount).getMin();
            if  ( (*root).data <= min )
            {
                min = (*root).data;
                charFreq minSec = (*leastCount).removeMin(); 
                binaryTreeNode<charFreq>* minSecNode = new binaryTreeNode<charFreq>(minSec);

                charFreq bridge(min.freq + minSec.freq);
                binaryTreeNode<charFreq>* bridgeNode = new binaryTreeNode<charFreq>(bridge);

                (*bridgeNode).left = root;
                (*bridgeNode).right = minSecNode;
                root = bridgeNode;
            }
            else
            {
                min = (*leastCount).removeMin();
                charFreq minSec = (*leastCount).getMin();
                if ( (*root).data <= minSec )
                {
                    minSec = (*root).data;
                    binaryTreeNode<charFreq>* minNode = new binaryTreeNode<charFreq>(min);

                    charFreq bridge(min.freq + minSec.freq);
                    binaryTreeNode<charFreq>* bridgeNode = new binaryTreeNode<charFreq>(bridge);

                    (*bridgeNode).left = minNode;
                    (*bridgeNode).right = root;
                    root = bridgeNode;
                }
                else
                {
                    minSec = (*leastCount).removeMin();
                    
                    binaryTreeNode<charFreq>* minNode = new binaryTreeNode<charFreq>(min);
                    binaryTreeNode<charFreq>* minSecNode = new binaryTreeNode<charFreq>(minSec);

                    charFreq bridge(min.freq + minSec.freq);
                    binaryTreeNode<charFreq>* bridgeNode = new binaryTreeNode<charFreq>(bridge);

                    (*bridgeNode).left = minNode;
                    (*bridgeNode).right = minSecNode;

                    charFreq bigBridge(bridge.freq + ((*root).data).freq);
                    binaryTreeNode<charFreq>* bigBridgeNode = new binaryTreeNode<charFreq>(bigBridge);

                    (*bigBridgeNode).left = bridgeNode;
                    (*bigBridgeNode).right = root;
                    root = bigBridgeNode;
                }
            }
        }
    }

    if ( root == NULL )
    {
        charFreq extra;
        root = new binaryTreeNode<charFreq>(extra);
    }

    while ( (*leastCount).getSize() == 1 )
    {
        charFreq final = (*leastCount).removeMin();
        binaryTreeNode<charFreq>* finalNode = new binaryTreeNode<charFreq>(final);



        charFreq bridge(final.freq + ((*root).data).freq);
        binaryTreeNode<charFreq>* bridgeNode = new binaryTreeNode<charFreq>(bridge);

        (*bridgeNode).left = finalNode;
        (*bridgeNode).right = root;
        root = bridgeNode;
    }

    return root;
}

void bitCodeCreator(binaryTreeNode<charFreq>* root, string code, unordered_map<char, string>* comp, unordered_map<string, char>* decomp, int* arrayCodeLen)
{
    if ( root == NULL )
    {
        return;
    }
    else if ( ( (*root).left == NULL ) && ( (*root).right == NULL ) )
    {
        charFreq curr = (*root).data;
        (*comp)[curr.c] = code;
        (*decomp)[code] = curr.c;
        
        int index = curr.c;
        *(arrayCodeLen+index) = code.size();

        return;
    }
    else
    {
        bitCodeCreator((*root).left, code+'0', comp, decomp, arrayCodeLen);
        bitCodeCreator((*root).right, code+'1', comp, decomp, arrayCodeLen);

        return;
    }
}

void compressor(string &input, string &compInput, unordered_map<char, string>* comp)
{
    int i = 0;
    while ( input[i] != '\0' )
    {
        string currCode = (*comp)[input[i]];
        compInput += currCode;
        i++;
    }    
}

void decompressor(string &input, string &decompInput, unordered_map<string, char>* decomp)
{
    string currCode = "";
    int i = 0;
    while ( input[i] != '\0' )
    {
        currCode += input[i];
        if ( (*decomp).count(currCode) )
        {
            decompInput += (*decomp)[currCode];
            currCode = "";
        }
        i++;
    }
}

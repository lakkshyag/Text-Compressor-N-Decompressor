#include "otherFunctions.cpp"

int main()
{
    cout<<" ------------------------------------------------------------------------------------------Text Compressor and Decompressor------------------------------------------------------------------------------------------ ";
    cout<<endl<<endl<<endl;

    cout<<"Enter text input to be compressed: (enter '~' to end taking input)";
    string input;                      
    cout<<endl<<endl;                                                                                 
    getline(cin, input, '~');

    int sizeOriginal = input.length();
    sizeOriginal *= 8;

    int* arrayCharFreq = new int[256];
    int* arrayCodeLen = new int[256];

    findFreq(arrayCharFreq, arrayCodeLen, input);

    priorityQueue<charFreq>* leastCount = new priorityQueue<charFreq>;
    fillMinPriorityQueue(leastCount, arrayCharFreq);
    
    binaryTreeNode<charFreq>* root = createBinaryTree(leastCount);

    unordered_map<char, string>* comp = new unordered_map<char, string>;
    unordered_map<string, char>* decomp = new unordered_map<string, char>;

    bitCodeCreator(root, "", comp, decomp, arrayCodeLen);

    cout<<endl<<"The compression key: "<<endl;
    unordered_map<char, string>::iterator itr = (*comp).begin();
    while ( itr != (*comp).end() )
    {
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
        itr++;
    }
    cout<<endl;
    cout<<"---------------------------------------------^^ This is the compression key which was used for the following compression. It has the compressed bit code, followed by the character it is compressing. ^^---------------------------------------------"<<endl<<endl;

    string compInput = "";
    compressor(input, compInput, comp);
    cout<<endl<<"The compressed code: "<<endl;
    cout<<compInput<<endl<<endl;
    cout<<"---------------------------------------------^^ This is the compressed code. Its compression key can also be found above. ^^---------------------------------------------"<<endl<<endl;

    int sizeCompressed = compInput.length();


    
    string decompInput = "";
    decompressor(compInput, decompInput, decomp);
    cout<<decompInput<<endl;
    cout<<"------------------------------------------^^ This is the decompressed string for demonstration purposes, obtained by running the decompression algorithm on the compressed string. ^^------------------------------------------"<<endl<<endl;

    cout<<"Original File Size: "<<sizeOriginal<<" bits ("<<1.0*sizeOriginal/8<<" bytes)."<<endl;
    cout<<"Compressed File Size: "<<sizeCompressed<<" bits ("<<1.0*sizeCompressed/8<<" bytes)."<<endl;

    float frac = 1.0*(sizeOriginal - sizeCompressed)/sizeOriginal;

    cout<<"Compression: "<<frac*100<<'%'<<endl; 


    delete decomp;
    delete comp;
    delete leastCount;
    delete[] arrayCodeLen;
    delete[] arrayCharFreq;
    return 0;
}
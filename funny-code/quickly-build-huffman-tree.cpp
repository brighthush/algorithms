/*
 * author: BrightHush
 * Quickly build Huffman Tree. This solution is motivated by word2vec source code.
 * This is a really smart method to build a Huffman Tree only according the weight
 * of each node.
 */

#include <cstdio>
#include <cstdlib>

const long long INF = (long long)1e17;

long long *weight_node; //weight_node[i] represent weight of node indexed by i.
long long *parent_node; //parent_node[i] represent the parent node index of node i.

void constructHuffmanTree(long long *weights, int n)
{
    long long min1, min2, pos1, pos2;
    int N = (n<<1) - 1;
    weight_node = (long long *)calloc(N, sizeof(long long));
    parent_node = (long long *)calloc(N, sizeof(long long));

    int a;
    for(a=0; a<N; ++a)
    {
        if(a<n)
            weight_node[a] = weights[a];
        else
            weight_node[a] = INF;
    }

    pos1 = n-1;
    pos2 = n;
    for(a=0; a<n-1; ++a)
    {
        // first find the two minimum value, store the index in min1 and min2.
        if(pos1>=0)
        {
            if(weight_node[pos1] <= weight_node[pos2])
            {
                min1 = pos1;
                --pos1;
            }
            else
            {
                min1 = pos2;
                ++pos2;
            }
        }
        else{min1 = pos2, ++pos2;}

        if(pos1>=0)
        {
            if(weight_node[pos1] <= weight_node[pos2])
            {
                min2 = pos1;
                --pos1;
            }
            else
            {
                min2 = pos2;
                ++pos2;
            }
        }
        else{min2 = pos2, ++pos2;}

        weight_node[n+a] = weight_node[min1] + weight_node[min2];
        printf("combine %lld %lld get %lld\n", weight_node[min1], weight_node[min2], weight_node[n+a]);
        parent_node[min1] = n + a;
        parent_node[min2] = n + a;
    }
}


int main()
{
    long long weights[] = {10, 8, 7, 5, 3, 1};
    constructHuffmanTree(weights, 6);
    return 0;
}


#include <iostream>

#include <cmath>
#include <vector>
#include "classical_bin_tree.cpp"
#include "AVL_tree.cpp"

void treeInsertRandNodes( BinTree& bTree, AVLTree& aTree, int N_nodes ) {

    // Fill the two trees with identical nodes.

    int x;
    int rndNumCut = 1000;

    for ( int i = 0; i < N_nodes ; i++ ) 
    {
        x = (rand()%rndNumCut) - rndNumCut/2;
        bTree.insert(x);
        aTree.insert(x);
    }
}

int experiment( int N_nodes ) {

    // create two identical trees, bin tree and avl tree
    // return the height difference.

    BinTree bTree;
    AVLTree aTree;

    treeInsertRandNodes( bTree, aTree, N_nodes );

    return bTree.height() - aTree.height();
}

void trialTable( int N_lo, int N_hi, int NTrials  ) {

    int NExprPTrial = 200;

    int dn = (N_hi-N_lo)/(NTrials-1);

    std::vector<int>    n      (NTrials);
    std::vector<int>    max_dh (NTrials);
    std::vector<double> avg_dh (NTrials);

    std::vector<int>    hVec   (NExprPTrial);


    printf("\n");

    printf(" n  \t| max height diff  |  avg hight diff  |  over %i experiments \n", NExprPTrial );
    printf("---------+-------------------------------------------------------------\n");


    for ( int i = 0 ; i < NTrials ; i++ ) 
    {
        n[i] = N_lo + i*dn;

        for ( int j = 0 ; j < NExprPTrial ; j++ )
        {
            hVec[j] = experiment( n[i] );

            avg_dh[i] += (double)( hVec[j] );

            if (hVec[j] > max_dh[i]) { max_dh[i] = hVec[j]; }
        }
        avg_dh[i]=  avg_dh[i]/( (double)NExprPTrial )  ;


        printf("%i  \t| %i                |   %0.3f  \n", n[i], max_dh[i], avg_dh[i] );

    }



}


int main()
{

    trialTable( 100, 100000, 13 );

    return 0;
}
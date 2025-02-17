
#include <iostream>
#include <vector>


// Definition for singly-linked list. (integers)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    
};


void printL( const ListNode* ptr ){

   // ListNode* ptr = node;
        std::cout << "[ ";

        while( ptr->next != nullptr ) {   
            std::cout <<  ptr->val << ", ";   
            ptr = ptr->next; // Does this modify the var in place? 
        } 

        std::cout << ptr->val ;

        std::cout << "]\n";
    }

void nodeAppend( ListNode*& head, int nuval ){

    ListNode* newnode = new ListNode(nuval);

    // Find the end of the chain
    ListNode* current = head;

    while( current->next != nullptr ){
        current = current->next;
    }

    // Append to end
    current->next = newnode;

}

ListNode* listCreate( std::vector<int> x ){

    ListNode* head = new ListNode( x[0] );
    ListNode* current = head;

    for ( int i = 1 ; i<(int)x.size() ; i++ ) {
        nodeAppend( current, x[i]  );
        current = current->next;
    } 

    return head;
}

//-----------------------------------------------------------
// Solution to Leetcode prob
//
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* outhead = new ListNode( 0 );
        ListNode* current = outhead;

        bool oplace = true;
        int temp = 0;
        int carry = 0;

        while( l1 != nullptr || l2 != nullptr ) {

            if (l1 == nullptr) {
                std::cout << "-\t:l1 is null\n";
            
                temp = carry + l2->val;
                l2 = l2->next;

            } else if (l2 == nullptr) {
                std::cout << "-\t:l2 is null\n";
            
                temp = carry + l1->val;
                l1 = l1->next;

            } else {
                std::cout << "-\t:no null\n";

                temp = carry + l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            // Check carry 
            if (temp >= 10) {
                carry = 1;
                temp  = temp - 10;
            } else {
                carry = 0;
            }

            //debug statement
            std::cout<< "-\t: " << "temp: " << temp << ",  carry: " << carry <<'\n';

            // append            
            if (oplace) {
                current->val = temp;
                oplace = false;
            } else {
                nodeAppend(current, temp);
                current = current->next;
            } 
            
            
        }

        return outhead;
    }


int main() {

    ListNode  my_list(1);
    ListNode* my_head = &my_list;
    ListNode  my_node2(3);

    // append?
    my_head->next = &my_node2;

    printL( my_head );

    // using nodeappend func?
    nodeAppend(  my_head, 4 ); 
    nodeAppend(  my_head, 5 ); 

    printL( my_head );
    
    // Test list create 
    ListNode* L1 = listCreate(  std::vector<int>{ 0, 0, 5, 1 } );
    ListNode* L2 = listCreate(  std::vector<int>{ 0, 5 } );

    printL( L1 );
    printL( L2 ); 

    ListNode* L3 = addTwoNumbers(  L1, L2  );
    // should be { 0, 5, 5 };

    printL( L3 );


}
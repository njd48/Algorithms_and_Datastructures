#define LARGE_INT  2147483647
#define SMALL_INT -2147483648

#define MAXPOW10 9

class Solution {
private:
    // --- Lookup functions -------------------------------
    int maxI_digit( int p ) {
        switch (p) {
            case 0: { return 7; break; }
            case 1: { return 4; break; }
            case 2: { return 6; break; }
            case 3: { return 3; break; }
            case 4: { return 8; break; }
            case 5: { return 4; break; } 
            case 6: { return 7; break; }
            case 7: { return 4; break; }
            case 8: { return 1; break; }
            case 9: { return 2; break; }
            default: return 0;
        }
    }
    int minI_digit( int p ) {
        switch (p) {
            case 0: { return -8; break; }
            case 1: { return -4; break; }
            case 2: { return -6; break; }
            case 3: { return -3; break; }
            case 4: { return -8; break; }
            case 5: { return -4; break; } 
            case 6: { return -7; break; }
            case 7: { return -4; break; }
            case 8: { return -1; break; }
            case 9: { return -2; break; }
            default: return 0;
        }
    }
    int p10( int p ) {
        switch (p) {
            case 0: return          1; break; 
            case 1: return         10; break; 
            case 2: return        100; break; 
            case 3: return       1000; break; 
            case 4: return      10000; break; 
            case 5: return     100000; break; 
            case 6: return    1000000; break; 
            case 7: return   10000000; break; 
            case 8: return  100000000; break; 
            case 9: return 1000000000; break; 
            default: return 0;
        }
    }

    // --- Boolean functions ------------------------------- 
    bool possible_overflow( vector<int>& digits ) 
    {
        // Will y = y + d*10^p result in overflow?
        bool ovrf = true;

        for ( int p = MAXPOW10 ; p >= 0 ; p-- ) {
            if ( digits[p] < maxI_digit(p)  ) { 
                return false;
            } else if ( digits[p] > maxI_digit(p) ) {
                return true;
            }
        }

        return ovrf;
    }
    bool possible_underflow( vector<int>& digits ) 
    {
        // Will y = y + d*10^p result in underflow?
        bool undf = true;

        for ( int p = MAXPOW10 ; p >= 0 ; p-- ) {
            if ( digits[p] < minI_digit(p)  ) { 
                return true;
            } else if ( digits[p] > minI_digit(p) ) {
                return false;
            }
        }

        return undf;
    }

public:
    int reverse(int x) {

        int ans = 0;
        vector<int> digits( 1+ MAXPOW10 );

        // Find digit vals by cycling through pows of 10
        int   d = 0;
        int   order = 0;
        bool  d_found = false;

        for ( int p = MAXPOW10; p >= 0 ; p-- ) 
        {
            d = x / p10(p);

            if ( !d_found ) {
                if ( d != 0 ) {
                    d_found = true;
                    order = p;
                }
            } 
            if ( d_found ) {
                x = x - d*p10(p);        
                //std::cout << order-p;
                digits[ order-p ] = d;   
                
            }     
            //std::cout << p << ", " << d << ", " << x << '\n';               
        }

        // Test possible overflow or underflow
        if (order >= 9) {
            if ( possible_overflow( digits ) ) {      return 0; }
            else if ( possible_underflow( digits ) ){ return 0; }
        }
        

        // Assemble the reversed result
        // int ans; already declared
        for ( int k = order; k >=0 ; k-- ) {
            d = digits[ k ];

            

            ans += d*p10(k);       

        }
        
        return ans;
    }
};
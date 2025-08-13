

#ifndef OPERA_H 
#define OPERA_H

#include "operations.cpp"

enum errType {
    valid = 0,
    syntaxError,
    numericalError,
    divByZero,
};

class Opera {

private:
    errType   m_errType = valid;
    double    m_val;
    Operation m_operation;
    Opera*    m_next;
    Opera*    m_prev;

public:

    Opera(double val=0, Operation operation=nothing){
        m_val       = val;
        m_operation = operation; 
        m_next      = nullptr;
        m_prev      = nullptr;
    }

    ~Opera(){  
        if (m_next != nullptr) {
            delete m_next;
            m_next = nullptr;
        }
    }

    double getVal()             { return m_val;  }
    Operation getOperation()    { return m_operation; }
    std::string showOperation() { return operationToString( m_operation ); }
    Opera* next()               { return m_next; }
    bool hasNext()              { return !(m_next==nullptr); }
    Opera* prev()               { return m_prev; }

    void changeOperation( Operation a ){ m_operation = a; }

    void removeParenthesis(  ) {
        m_operation = dropParenthesis( m_operation );
    }

    Opera* append(double val, Operation operation){

        Opera* p = this;
        Opera* q;

        while ( p != nullptr ){
            q = p;
            p = p->m_next;
        }

        p = new Opera( val, operation );
        p->m_prev = q;
        q->m_next = p;

        return p;
    }

    Opera* appendFront( double val, Operation operation ) {

        Opera* p = this;
        Opera* q = new Opera( val, operation );

        p->m_prev = q;
        q->m_next = p;

        return q;
    }

    void restitch(){
        if (m_next != nullptr) 
        {
            Opera* next = m_next;
            m_next      = next->m_next;  
            if (m_next != nullptr){
                m_next->m_prev = this;
            }                  
            //delete next;
        }        
    }

    void resolve(){

        // Opera class absorbs its neighbor into itself,
        // deletes the neighbor,
        // and replaces it with its neighbor's neighbor.
        // 
        // if m_peration is not admissible, does nothing

        if ( m_next == nullptr ){
            return;
        }

        switch (m_operation) {

            case plus:     
                m_val       = m_val + m_next->m_val; 
                m_operation = m_next->m_operation;
                restitch();
                break;
                
            case minus:    
                m_val       = m_val - m_next->m_val; 
                m_operation = m_next->m_operation;
                restitch();
                break;

            case times:    
                m_val       = m_val * m_next->m_val; 
                m_operation = m_next->m_operation;
                restitch();
                break;

            case divideby: 
                m_val       = m_val / m_next->m_val; 
                m_operation = m_next->m_operation;
                restitch();
                break;

            default:
                break;
        }
    }
};

#endif
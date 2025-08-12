#ifndef OPERATIONS_H
#define OPERATIONS_H

enum Operation {
    nothing = 0,
    plus,
    minus,
    times,
    divideby,
    
    nothingOparen, // may need a trick for this.
    plusOParen,
    minusOParen,
    timesOParen,
    dividebyOParen,

    cParenNothing,
    cParenPlus,
    cParenMinus,
    cParenTimes,
    cParenDiv,
};

enum OperationGroup {
    none = 0,
    parenthesis,
    multDiv,
    addSubtr,
};

std::string operationToString( Operation );
bool isOParen( Operation );
bool isCParen( Operation );
OperationGroup operationGroup( Operation );
Operation removeParenthesis( Operation );
Operation introduceOpenParenthesis( Operation );
Operation introduceCloseParenthesis( Operation );


//=====================================================================================

std::string operationToString( Operation x ){
    switch (x) {
        case nothing:           return " ";
        case plus:              return "+";       
        case minus:             return "-";
        case times:             return "*";
        case divideby:          return "/";

        case nothingOparen:     return  "(";
        case plusOParen:        return "+(";
        case minusOParen:       return "-(";
        case timesOParen:       return "*(";
        case dividebyOParen:    return "/(";

        case cParenNothing:     return ")";
        case cParenPlus:        return ")+";
        case cParenMinus:       return ")-";
        case cParenTimes:        return ")*";
        case cParenDiv:         return ")/";

        default:                return " ";
    }
}

bool isOParen( Operation x ) {
    if ( x == nothingOparen || 
         x == plusOParen || 
         x == minusOParen || 
         x == timesOParen || 
         x == dividebyOParen 
    ) 
    {
        return true;
    } else {
            return false;
    }
}

bool isCParen( Operation x ) {
    if ( x == cParenNothing || 
         x == cParenPlus ||
         x == cParenMinus ||
         x == cParenTimes ||
         x == cParenDiv 
    ) 
    {
        return true;
    } else {
        return false;
    }
}

OperationGroup operationGroup( Operation x ) {

    if ( x == nothing ){
        return none;

    } else if ( x == times || x == divideby) {
        return multDiv;

    } else if ( x == plus || x == minus ) {
        return addSubtr;

    } else {
        return parenthesis;

    }
}

Operation dropParenthesis( Operation x ) {

    switch (x) {
        case nothingOparen:     return nothing;
        case plusOParen:        return plus;
        case minusOParen:       return minus;
        case timesOParen:       return times;
        case dividebyOParen:    return divideby;

        case cParenNothing:     return nothing;
        case cParenPlus:        return plus;
        case cParenMinus:       return minus;
        case cParenTimes:       return times;
        case cParenDiv:         return divideby;

        default:                return x;
    }
}

Operation introduceOpenParenthesis( Operation x ) {

    switch (x) {
        case nothing:     return nothingOparen;
        case plus:        return plusOParen;
        case minus:       return minusOParen;
        case times:       return timesOParen;
        case divideby:    return dividebyOParen;
        default:          return x;
    }
}

Operation introduceCloseParenthesis( Operation x ) {

    switch (x) {
        case nothing:     return cParenNothing;
        case plus:        return cParenPlus;
        case minus:       return cParenMinus;
        case times:       return cParenTimes;
        case divideby:    return cParenDiv;
        default:          return x;
    }
}

#endif
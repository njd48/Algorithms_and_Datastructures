
%
% Matlab claims to pass by reference, unless the input data
% is modified within the function.  In the latter case, a copy
% would be automatically made to protect the input from
% unintended modification.  This should be observable in
% program speed
%
% I'm still not certain if there's an observable performance difference
% is this really happening?
%

n_tests = 120;


runtest(  int64( 2^ 5), n_tests );
runtest(  int64( 2^ 9), n_tests );
runtest(  int64( 2^ 9.5), n_tests );
runtest(  int64( 2^10), n_tests );
runtest(  int64( 2^10.5), n_tests );
runtest(  int64( 2^11), n_tests );


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function runtest( N_prob, n_tests )

    persistent flag;

    A = rand( N_prob, N_prob ) ;
    B = 0*A;
    
    time1 = 0;
    time2 = 0;

    % Test matquare1    
        for n = 1:n_tests

            A = rand( N_prob, N_prob );
            tic();

                B = matsquare1(A);

            time1 = time1 + toc();
        end
    
    
    % Test matquare2
        for n = 1:n_tests

            A = rand( N_prob, N_prob );
            tic();

                B = matsquare2(A);

            time2 = time2 + toc();
        end

    speedupfac = time2/time1;

    if isempty(flag)
        fprintf('over %i repeated tests...\n', n_tests);
        fprintf('prob size (N), time for A^2 byref, time for A^2 bycopy, factor of speedup \n');
        flag = 1;
    end
        fprintf('     %8.0i, \t\t  %2.9f, \t\t %2.9f, \t\t %2.9f \n', N_prob, time1, time2, speedupfac );

end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [B] = matsquare1( A )

    % Function will instantiate a new variable, B
    % Input (A) should be a square matrix.
    % A is not modified

    % report: from testing, this appears to have some
    %         observed speedup compared to that
    %         which modifies the variable inside the function

    B = A^2;

    % Modify the first element of B
    B(1,1) = 1;

end

function [B] = matsquare2( A )

    % Function will instantiate a new variable, B
    % Input (A) should be a square matrix.

    % A is modified.  Here we presume the interpreter
    % reads this line, and takes the input A as a copy
    % rather than a reference.

    A(1,1) = 1;

    B = A^2;

end


#include "KdV.cpp"

int main () {

    KdV_env sys;

    sys.dt      = 0.000001;
    sys.t_final = 1.0;
    sys.t_write = 0.025;

    std::cout << "sim begin.\n";

    sys.set_initial();
    sys.run();

    std::cout << "sim finished.\n";

    return 0;
}
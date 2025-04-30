

#include "KdV.cpp"

int main () {

    KdV_env sys;

    sys.dt      = 0.05;
    sys.t_final = 1.0;
    sys.t_write = 0.33;

    std::cout << "write period: " << sys.t_write << '\n';

    sys.set_initial();
    sys.run();

    return 0;
}
//

#include <iostream>


struct Planet
{
    int idno;
    
    const double mass;
    double r[3];
    double v[3];
};

void printPlanet( Planet planet)
{

    std::cout << "planet " << planet.idno << "\n";
    std::cout << "has mass " << planet.mass<< " kg, and \n";
    std::cout << "sits at  ( ";
    for ( int i=0;  i<3;  i++ )
    {
        std::cout << planet.r[i] << " ";
    } 
    std::cout << ") m from the origin\n";
    
    std::cout << "going ( ";
    for ( int i=0;  i<3;  i++ )
    {
        std::cout << planet.v[i] << " ";
    }  
    std::cout << ") m/s \n";

}

int main()
{
    
    Planet planet{ 0, 2.565e23,  {1.,0.,0.}, {0.,1.,0.} };

    printPlanet(planet);

    return 0;
}

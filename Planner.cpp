#include "Astar.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <Eigen/Eigen>




class Planner
{
private:
    Eigen::Vector3d start;
    Eigen::Vector3d goal;
    std::vector<Eigen::Vector3d> path;
    std::vector<Eigen::Vector3d> obstacles;
    double resolution;
    double robot_radius;





public:


}
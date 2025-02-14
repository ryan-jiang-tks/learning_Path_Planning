#include "include/Astar.hpp"
#include "include/voxel_map.hpp"

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
    voxel_map::VoxelMap map;






public:
Planner(Eigen::Vector3d start, Eigen::Vector3d goal, double resolution, double robot_radius, voxel_map::VoxelMap map)
: start(start), goal(goal), resolution(resolution), robot_radius(robot_radius),map(map)
{

}
    


inline void plan()
{

}


};


// int main()
// {
//     int a = 1;
//     Eigen::Vector3d start(0,0,0);
//     Eigen::Vector3d goal(10,10,10);
//     double resolution = 1;
//     double robot_radius = 1;
//     voxel_map::VoxelMap map(Eigen::Vector3i(10,10,10), Eigen::Vector3d(0,0,0), 1);


//     Planner planner(start,goal,resolution,robot_radius,map);
//     planner.plan();
// }
#include <memory>
#include <iostream>
#include <vector>
#include <Eigen3/Eigen/Eigen>
#include <string>
#include <cmath>
#include <ompl/util/Console.h>
#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/RealVectorStateSpace.h>
#include <ompl/geometric/planners/rrt/InformedRRTstar.h>
#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/base/objectives/PathLengthOptimizationObjective.h>
#include <ompl/base/DiscreteMotionValidator.h>
#include <ompl/base/spaces/SE3StateSpace.h>

namespace ob = ompl::base;
namespace og = ompl::geometric;




bool isStateValid(const ob::State *state)
{
    return true;
}

// void plan()
// {
//     // construct the state space we are planning in
//     auto space(std::make_shared<ob::SE3StateSpace>());


//     ob::RealVectorBounds bounds(3);
//     bounds.setLow(-1);
//     bounds.setHigh(1);
 
//     space->setBounds(bounds);


//     auto si(std::make_shared<ob::SpaceInformation>(space));    

//     si->setStateValidityChecker(isStateValid);

//     ob::ScopedState<> start(space);
//     start.random();

//     ob::ScopedState<> goal(space);
//     goal.random();

//     auto pdef(std::make_shared<ob::ProblemDefinition>(si));

//     pdef->setStartAndGoalStates(start, goal);

//     auto planner(std::make_shared<og::RRTConnect>(si));

//     planner->setProblemDefinition(pdef);

//     planner->setup();

//     ob::PlannerStatus solved = planner->ob::Planner::solve(1.0);

//     if (solved)
//     {
//         // get the goal representation from the problem definition (not the same as the goal state)
//         // and inquire about the found path
//         ob::PathPtr path = pdef->getSolutionPath();
//         std::cout << "Found solution:" << std::endl;
 
//         // print the path to screen
//         path->print(std::cout);
//     }

// }


int main()
{
    int a = 1;
    std::cout << "Hello World" << std::endl;
    ob::State *state();
    auto space(std::make_shared<ob::SE3StateSpace>());
    ob::RealVectorBounds bounds(3);
        bounds.setLow(-1);
        bounds.setHigh(1);
     
        space->setBounds(bounds);
    
    
        auto si(std::make_shared<ob::SpaceInformation>(space));    
    

 

    // plan();
    return 0;
}
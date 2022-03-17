# include <iostream>

# include <fstream>
# include <iomanip>
# include "spdlog/spdlog.h"
# include "yaml-cpp/yaml.h"
# include <Eigen/Eigen>
# include "OsqpEigen/OsqpEigen.h"

# include "driver_test.h"

using namespace Eigen;

void osqpTest() {
    Eigen::SparseMatrix<double> hessian;
    hessian.resize(2, 2);
    hessian.insert(0, 0) = 1;
    hessian.insert(1, 0) = -1;
    hessian.insert(0, 1) = -1;
    hessian.insert(1, 1) = 2;
    // std::cout << "hessian:" << std::endl << hessian << std::endl;

    VectorXd gradient;
    gradient.resize(2);
    gradient << -2,
                -6;
    // std::cout << "gradient:" << std::endl << gradient << std::endl;

    Eigen::SparseMatrix<double> linearMatrix;
    linearMatrix.resize(3, 2);
    linearMatrix.insert(0, 0) = 1;
    linearMatrix.insert(0, 1) = 1;
    linearMatrix.insert(1, 0) = -1;
    linearMatrix.insert(1, 1) = 2;
    linearMatrix.insert(2, 0) = 2;
    linearMatrix.insert(2, 1) = 1;
    // std::cout << "linearMatrix:" << std::endl << linearMatrix << std::endl;

    VectorXd lowerBound;
    lowerBound.resize(3);
    lowerBound << -OsqpEigen::INFTY,
                  -OsqpEigen::INFTY,
                  -OsqpEigen::INFTY;
    // std::cout << "lowerBound:" << std::endl << lowerBound << std::endl;

    VectorXd upperBound;
    upperBound.resize(3);
    upperBound << 2,
                  2,
                  3;
    // std::cout << "upperBound:" << std::endl << upperBound << std::endl;

    int numberOfVariables = 2; //A矩阵的列数
    int numberOfConstraints = 3; //A矩阵的行数

    // solve qp
    OsqpEigen::Solver solver;
    solver.settings()->setWarmStart(true);
    solver.settings()->setVerbosity(false);

    // set the initial data of the QP solver
    solver.data()->setNumberOfVariables(numberOfVariables);
    solver.data()->setNumberOfConstraints(numberOfConstraints);
    if(!solver.data()->setHessianMatrix(hessian)) {
        SPDLOG_ERROR("Wrong Hessian Matrix!");
    }
    if(!solver.data()->setGradient(gradient)) {
        SPDLOG_ERROR("Wrong Gradient Vector!");
    }
    if(!solver.data()->setLinearConstraintsMatrix(linearMatrix)) {
        SPDLOG_ERROR("Wrong Constraints Matrix!");
    }
    if(!solver.data()->setLowerBound(lowerBound)) {
        SPDLOG_ERROR("Wrong LowerBound Vector!");
    }
    if(!solver.data()->setUpperBound(upperBound)){
        SPDLOG_ERROR("Wrong UpperBound Vector!");
    }

    // instantiate the solver
    if(!solver.initSolver()) {
        SPDLOG_ERROR("Solver init failed!");
    }

    if(solver.solveProblem() != OsqpEigen::ErrorExitFlag::NoError) {
        SPDLOG_INFO("OSQP solved!");
    }

    VectorXd qpSolution;
    qpSolution = solver.getSolution();
    std::cout << qpSolution << std::endl;
}

int main(int, char**) {
    // std::cout << "Hello, world!\n";
    // DriverTest driverTest;
    // driverTest.Output();

    // spdlog::info("Welcome to spdlog!");
    // SPDLOG_INFO("Welcome to spdlog!");
    // //SPDLOG_DEBUG(...)
    // //SPDLOG_INFO(...)
    // //SPDLOG_WARN(...)
    // //SPDLOG_ERROR(...)
    // //SPDLOG_CRITICAL(...)

    // YAML::Node ppmRangeYaml;
    // std::ofstream fout("../config/null.yaml");
    // fout << ppmRangeYaml;

    osqpTest();
}

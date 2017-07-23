#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

  VectorXd rmse = VectorXd(4);
  rmse << 0, 0, 0, 0;


  int estimationsSize = estimations.size();
  if (estimationsSize != ground_truth.size() || estimationsSize == 0) {
    return rmse;
  }

  for(int i = 0; i < estimationsSize; i++) {

    VectorXd error = estimations[i] - ground_truth[i];
    error = error.array() * error.array();
    rmse += error;
  }

  rmse = rmse / estimationsSize;
  rmse = rmse.array().sqrt();

  return rmse;

}
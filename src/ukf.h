#ifndef UKF_H
#define UKF_H

#include "measurement_package.h"
#include "Eigen/Dense"
#include <vector>
#include <string>
#include <fstream>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class UKF 
{
    public:

        ///* initially set to false, set to true in first call of ProcessMeasurement
        bool is_initialized_;

        ///* if this is false, laser measurements will be ignored (except for init)
        bool use_laser_;

        ///* if this is false, radar measurements will be ignored (except for init)
        bool use_radar_;

        ///* state dimension
        int n_x_;
        
        ///* augmented state dimension
        int n_aug_;

        ///* sigma points dimension
        int n_sig_;

        ///* radar measurement dimension (r, phi, and r_dot)
        int n_z_radar_;

        ///* lidar measurement dimension (px, py)
        int n_z_lidar_;

        ///* sigma point spreading parameter
        double a_;
        double k_;
        double lambda_;

        ///* state vector: [pos1 pos2 vel_abs yaw_angle yaw_rate] in SI units and rad
        VectorXd x_;

        ///* state covariance matrix
        MatrixXd P_;

        ///* predicted sigma points matrix
        MatrixXd Xsig_pred_;

        ///* time when the state is true, in us
        long long time_us_;

        ///* process noise standard deviation longitudinal acceleration in m/s^2
        double std_a_;

        ///* process noise standard deviation yaw acceleration in rad/s^2
        double std_yawdd_;

        ///* laser measurement noise standard deviation position1 in m
        double std_laspx_;

        ///* laser measurement noise standard deviation position2 in m
        double std_laspy_;

        ///* radar measurement noise standard deviation radius in m
        double std_radr_;

        ///* radar measurement noise standard deviation angle in rad
        double std_radphi_;

        ///* radar measurement noise standard deviation radius change in m/s
        double std_radrd_ ;

        ///* weights of sigma points
        VectorXd weights_;

        ///* process noise covariance matrix
        MatrixXd Q_;

        ///* radar measurement noise covariance matrix
        MatrixXd R_radar_;

        ///* lidar measurement noise covariance matrix
        MatrixXd R_lidar_;

        double NIS_radar_;
        double NIS_lidar_;

        /**
         * constructor
         */
        UKF();

        /**
         * destructor
         */
        virtual ~UKF();

        /**
         * ProcessMeasurement
         * @param meas_package the latest measurement data of either radar or laser
         */
        void ProcessMeasurement(MeasurementPackage meas_package);

        /**
         * Prediction predicts sigma points, the state, and the state covariance matrix
         * @param delta_t time between k and k+1 in s
         */
        void Prediction(double delta_t);

        /**
         * updates the state and the state covariance matrix using a laser measurement
         * @param meas_package The measurement at k+1
         */
        void UpdateLidar(MeasurementPackage meas_package);

        /**
         * updates the state and the state covariance matrix using a radar measurement
         * @param meas_package The measurement at k+1
         */
        void UpdateRadar(MeasurementPackage meas_package);

        VectorXd PredictionCatch(double dt);
};

#endif /* UKF_H */

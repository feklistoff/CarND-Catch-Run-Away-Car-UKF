# Run Away Robot with Unscented Kalman Filter Bonus Challenge
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

## Overview

In this Bonus Challenge I've used an Unscented Kalman Filter to try and catch a car moving in a continuous circle at constant velocity. Also, I've used a Kalman Filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. The filter makes a prediction based on the sensor measurement and then update the expected position. See files in the `src` for the primary C++ files making up this project.

The run away car is sensed by a stationary sensor, that is able to measure both noisy lidar and radar data. The capture vehicle  need to use these measurements to close in on the run away car. To capture the run away car the capture vehicle needs to come within `0.1` unit distance of its position. However the capture car and the run away car have the same max velocity, so if the capture vehicle wants to catch the car, it will need to predict where the car will be ahead of time.

## Prerequisites

* cmake >= 3.5
* make >= 4.1 
* gcc/g++ >= 5.4
* uWebSocketIO

[This](https://github.com/udacity/CarND-Catch-Run-Away-Car-UKF) repository contains all instructions for the Project.

This project involves the Udacity's Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases).

## Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
4. Run it: `./UnscentedKF`

## Results

The result demonstrated in [this video](https://github.com/feklistoff/CarND-Catch-Run-Away-Car-UKF/blob/master/catch_a_car.mov). Also you can watch on [Youtube](https://youtu.be/A0vb_n9Rkl8).

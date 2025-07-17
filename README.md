# Parrot-Minidrone-Competition

Overview
This project was developed as an entry for the MathWorks Minidrone Competition 2024. Our goal was to followa path set by the simulator using image processing and tune our pid controllers to move efficiently, within the time limit using a Parrot Minidrone model.
We devised a Stateflow-based closed-loop flight control system in Simulink, implementing PID control for real-time yaw and thrust correction via visual feedback and applied Canny edge detection, Hough Transform, Gaussian filtering, and adaptive thresholding for a real-time
image processing pipeline, ensuring 98% precise line tracking, and Kalman filtering for noise reduction.

This repository contains all the code, models, and documentation related to our solution, demonstrating our approach and solution to the problem statement.

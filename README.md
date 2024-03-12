# Dynamics and Control for 1-DOF Robot Manipulator

## Introduction

This project focuses on system identification and the implementation of a PD controller for a 1-degree-of-freedom robot manipulator. The goal is to determine the dynamic parameters of the robot through system identification experiments and then implement a PD controller with model compensation. The provided `PD_control.c` file contains the code for the controller, and this README provides an overview of the tasks performed.

## System Identification

### Task 1: Determine Dynamic Parameters

In the `PD_control.c` file, the system identification involves determining the dynamic parameters: inertia (`I`), viscous friction (`B`), and gravitational constant (`G`). The function `PD_control` receives joint angle (`theta`), rotational velocity (`theta_dot`), reference angle (`theta_ref`), and reference velocity (`theta_dot_ref`). The following steps are taken to identify the parameters:

- **Inertia (`I`):**
  - Calculate the acceleration (`theta_double_dot`) based on the change in velocity.
  - Use the Torque and acceleration relationship to find the inertia constant.
  - Hardcode the inertia constant (`I`) for simplicity.

- **Viscous Friction (`B`):**
  - Calculate the Viscous Force based on the given Torque and velocity.
  - Use the Torque and velocity relationship to find the viscous constant (`B`).
  - Hardcode the viscous constant (`B`) for simplicity.

- **Gravitational Constant (`G`):**
  - Calculate the Gravitational Force based on the given Torque and joint angle.
  - Use the Torque and gravitational force relationship to find the gravitational constant (`G`).
  - Hardcode the gravitational constant (`G`) for simplicity.

### Results - System Parameters

After running the experiments and analyzing the data, the following system parameters are determined:

- Inertia (`I`): 0.051336
- Viscous Friction (`B`): 0.709188
- Gravitational Constant (`G`): 2.363021

## PD Controller Implementation

### Task 2: Implement PD Controller with Model Compensation

The implemented PD controller compensates for the identified dynamic parameters to achieve critically damped behavior. The controller uses the following control law:

\[ \text{Control Torque} = I \left( K_p(\theta - \theta_{\text{ref}}) + K_v \theta_{\text{dot}} \right) + (B \theta_{\text{dot}}) + (G \cos(\theta)) \]

where \( K_p \) and \( K_v \) are the proportional and derivative gains, respectively. For critically damped behavior, \( K_v = 2 \sqrt{K_p} \).

## Usage

1. Clone the provided repository containing the dynamic simulator.
2. Navigate to the `dyn` directory and use the provided `Imakefile` to create the Makefile by typing `xmkmf`.
3. Compile the simulator executable by typing `make`.
4. Run the simulator executable `Dynamics`.
5. Open the `PD_control.c` file and fill in the ID variable with a 10 digit number.
6. Implement system identification in the `PD_control` function by uncommenting the relevant code sections.
7. Implement the PD controller with model compensation in the same function.
8. Compile and run the simulator, observing the behavior of the robot manipulator.

## Results and Analysis

The system parameters and controller gains are hardcoded for simplicity. After implementing the PD controller, observe the behavior of the robot manipulator in the simulator. Analyze whether the manipulator achieves the desired critically damped behavior.

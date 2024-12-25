# Team 88168A Robotics Project

## Introduction

Welcome to Team 88168A's robotics project repository. This repository contains the source code for our team's robot used in various robotics competitions. We utilize the VEX Robotics platform, and our code is built to control the robot's movement and actions during matches.

Our team is focused on creating efficient and innovative solutions for autonomous and driver-controlled operations, integrating advanced controls, sensors, and feedback loops to ensure smooth functionality in competitive environments.

## Project Structure

This project uses the VEX Robotics V5 system, and our code is written in C++ using the VEX V5 C++ API. The repository contains the following key components:

- **Autonomous Code**: The code that runs when the robot is on its own during a match. It includes functions for handling the robot’s movements, sensors, and actions based on pre-programmed strategies.
- **Driver Control Code**: The code that responds to user inputs via the controller, allowing real-time control of the robot's motors, sensors, and actuators.
- **Sensor Integration**: We use various sensors (e.g., optical sensors, encoders) for autonomous navigation and feedback during the match.
- **Subsystems**: The robot includes several subsystems, such as the drivetrain, intake, and hang system, each controlled independently for optimal performance.

## Features

- **Autonomous Movement**: The robot moves autonomously using pre-programmed strategies, including navigation, object manipulation, and goal scoring.
- **Tank Drive Control**: The robot is controlled using tank drive, where the left and right motors are controlled based on joystick inputs.
- **Arm Control**: A custom arm control logic allows precise movement and positioning based on sensor feedback.
- **Sensor Feedback**: The robot uses sensors to detect objects, adjust its course, and interact with the environment.
  
## Key Components and Functions

- `control_tank()`: This function controls the left and right drive motors based on the joystick inputs from the controller, with deadband adjustments to ensure smooth control.
- `autonoteTask()`: Runs autonomously to detect and interact with objects based on the selected team color, controlling the intake and other actions.
- `hangControlTask()`: Controls the robot's hanging mechanism during autonomous or driver control, responding to button inputs to change the arm's position.
- `position_track_task()`: Handles real-time position tracking to ensure the robot maintains its heading and position during the match.

## Setup

1. Clone this repository to your local machine.
2. Open the project in VEXcode V5 or your preferred C++ IDE for VEX Robotics.
3. Connect your VEX V5 robot to your computer.
4. Build and download the code to the robot's brain.

## Usage

### Autonomous Control

- The robot will automatically perform pre-defined tasks when the match starts. The behavior of the robot during autonomous mode is based on the selected team color and the programmed strategy.

### Driver Control

- Use the VEX controller's joystick inputs to control the robot’s movement in tank drive mode. The left joystick controls the left side of the robot, and the right joystick controls the right side.

### Arm and Intake Control

- The robot's intake and arm control are handled through button presses on the controller, with specific logic for different actions like lifting or positioning the robot's arm.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- VEX Robotics
- Team 88168A for their hard work and dedication to the project.
- All supporters, mentors, and volunteers who made this project possible.

---

Feel free to explore, modify, and contribute to the repository as we continue to enhance our robot's capabilities for future competitions.

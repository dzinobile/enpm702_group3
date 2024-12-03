1. Create a workspace with the src directory: mkdir -p dev_ws/src
2. Build the workspace: cd dev_ws && colcon build
3. Add the the packages bot_waypoint_msgs and group3_rwa5 to the src folder
4. Build the Workspace again: cd dev_ws && colcon build
5. Source your workspace: source install/setup.bash
6. Launch the turtlebot in an empty world: ros2 launch turtlebot3_gazebo empty_world.launch.py
7. In another terminal window, run the controller: ros2 launch group3_rwa5 project_5
	
	

# Udacity-WhereamI (AMCL)
Robotic Software Engineering

<p> The project uses adaptive monte carlo localization to determine the location of the robot with respect to the surroundings. Initially the particles will be diverged. Once when robot starts to move it converges to present position of the robot. The project uses amcl package of ROS for achiving the same. The robot model uses hokuyo lidar as rangefinder. the project also contains a camera and a separate package ballchaser to follow white ball alone. Rviz tool is used to subscribed to get the camera and lidar measurements. Additionally the robot can be moved using teleop twist keyboard and particle convergence can be seen.
</p>

<h2> Installation Instructions </h2>

```
//Move to Udacity-WhereamI folder

catkin_make
source devel/setup.bash
roslaunch my_robot world.launch

//In another terminal move to same path
soruce devel/setup.bash
roslaunch my_robot/amcl.launch

```
<h2> Optional TeleopTwist keyboard instalaltions </h2>

```
\\Move to same path in another terminal
source devel/setup.bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

<h2> Output screens </h2>
<h3> Using Teleop twist keyboard </h3>
<img src="/assign1.JPG" alt="My cool logo"/>

<h3> AMCL initial stage where the particles are dispersed </h3>
<img src="/assign2.JPG" alt="My cool logo"/>

<h3> Movement using 2D Nav Goal </h3>
<img src="/assign3.JPG" alt="My cool logo"/>

<h3>Localization in Rviz (Particles are convered) </h3>
<img src="/assign4.JPG" alt="My cool logo"/>

<h3>Movement using Teleop Twist Keyboard </h3>
<img src="/assign5.JPG" alt="My cool logo"/>

<h2> Localization in Rviz (The Converged particles localizes as robot moves now).
<img src="/assign6.JPG" alt="My cool logo"/>

#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

ros::ServiceClient client;


void drive_bot(float lin_x, float ang_z)
{
     
 ball_chaser::DriveToTarget srv;
 srv.request.linear_x=lin_x;
 srv.request.angular_z=ang_z;

if(!client.call(srv))
ROS_ERROR("Failed");
 // TODO: Request a service and pass the velocities to it to drive the robot
}

void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
int left=0;
int right=0;
int front=0;
int y=0;   
for(int i=0;i<img.height;i++)
{

int u=(img.step)*(i+1);
for(int j=y;j<u;j+=3)

{

if((img.data[j]==white_pixel)&&(img.data[j+1]==white_pixel)&&(img.data[j+2]==white_pixel))

{
//ROS_INFO_STREAM("Found white ball");
if((j>=y)&&(j<(y+img.step/3)))
++left;

else if((j>=(y+img.step/3))&&(j<(y+(2*img.step/3))))
++front;

else if((j>=(y+(2*img.step/3)))&&(j<(y+img.step)))
++right;

}
}
y=u;
}
//if(front>0)
//drive_bot(0.5,0.0);

//if(left>0)
//drive_bot(0.0,0.5);

//if (right>0)
//drive_bot(0.0,-0.5);

if((left==0)&&(front==0)&&(right==0))
drive_bot(0.0,0.0);

else if((left==0)&&(front==0)&&(right>0))
drive_bot(0.0,-2.0);

else if((left==0)&&(front>0)&&(right==0))
drive_bot(2.0,0.0);

else if((left==0)&&(front>0)&&(right>0))
{
if(front>right)
{
//drive_bot(2.0,0.0);
//drive_bot(0.0,-2.0);
drive_bot(2.0,-2.0);
}
else
{
//drive_bot(0.0,-2.0);
//drive_bot(2.0,0.0);
drive_bot(2.0,-2.0);
}
}

else if((left>0)&&(front==0)&&(right==0))
drive_bot(0.0,2.0);

else if((left>0)&&(front>0)&&(right==0))
{
if(front>left)
{
//drive_bot(2.0,0.0);
//drive_bot(0.0,2.0);
drive_bot(2.0,2.0);
}
else
{
//drive_bot(0.0,2.0);
//drive_bot(2.0,0.0);

drive_bot(2.0,2.0);
}
}

else
drive_bot(1.0,0.0);



ROS_INFO_STREAM(std::to_string(left)+"\t"+std::to_string(right)+"\t"+std::to_string(front)+"\n");
    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
}

int main(int argc,char **argv)
{
ros::init(argc,argv,"process_image");
ros::NodeHandle n;

client=n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

ros::Subscriber sub1=n.subscribe("/camera/rgb/image_raw",10,process_image_callback);

ros::spin();

return 0;

}

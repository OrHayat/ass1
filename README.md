# ass1-Basic ros and opencv 

## assigment descriptions


Write 4 nodes:
1.  The first node will use OpenCV to read the image "colors.jpg" and publish it on a topic. 
2.  The second node will be used to read a color from the input, and publish it on a topic. 
3.  The third node will subscribe to both topics, receive the image and the color, find the coordinates for the center of the circle with this color and it’s radius. The coordinates will be advertised on a new topic.
4.  The last node will receive the coordinates and radius, recieve the image from the first topic, draw a circle around the circle of the selected color and save the new image to a file. 

## how to run this assigment
* $ roscore
* $ rosrun assigment1 color_node r g b
* $ rosrun assigment1 image_node 
* $ rosrun assigment1 find_circle 
* $ rosrun assigment1 draw

### eaxmple rgbs inputs to give to *color_node* 
- red    = 255,0,0
- blue   = 0,0,255
- green  = 0,255,0
- yellow = 255,255,0
- purple = 128,0,128

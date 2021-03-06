import avango
import avango.gua
import avango.script
from avango.script import field_has_changed

from SimpleViewer import SimpleViewer

import os
import sys

class TimedRotate(avango.script.Script):
  TimeIn = avango.SFFloat()
  MatrixOut = avango.gua.SFMatrix4()
  RotationSpeed = avango.SFFloat()

  def __init__(self):
    self.super(TimedRotate).__init__()
    self.RotationSpeed.value = 2.0

  @field_has_changed(TimeIn)
  def update(self):
    self.MatrixOut.value = avango.gua.make_rot_mat(self.TimeIn.value*self.RotationSpeed.value,
                                                   0.0, 1.0, 0.0)


tips = {
  -1:
"\n\
Hello! I'm GuaVE, the friendly, built-in shell \n\
of \033[92mguacamole\033[0m and I will be your guide today! \n\n\
If you accidentally killed the application during \n\
a previous run, you can restart at the last tip by \n\
launching \033[93m./start.sh TIP_ID\033[0m\n\n\
\033[92mguacamole\033[0m is a powerful scenegraph which can be \n\
scripted with python. In this tutorial I will teach \n\
you the basics that are neccessary to create an \n\
entire \033[92mguacamole\033[0m application. \n\n\
Here is your first task: Start the tutorial by \n\
pressing enter to ignore the error message and typing \n\
the command 'tip(0)' after my friendly 'gua>'-prompt!",

  0:
"\n----------------------------------------------------------\n\n\
Awesome! I knew you would make it! But there is \n\
still much to learn... \n\n\
You can use this console as a full-featured python-\n\
interpreter. Try the command 'a = 5+5', hit return \n\
and type 'a' and you will be greeted with the result! \n\
Or even more advanced: 'b = 42*a' followed by 'b'. \n\
You got it? It's python! Continue by typing 'tip(1)'!\n",

  1:
"\n----------------------------------------------------------\n\n\
Before I teach you how to create an incredibly awesome \n\
scene with \033[92mguacamole\033[0m, let me share some \n\
hints on the usage of my command prompt:\n\n\
  -> The up- and down arrow keys navigate through your \n\
     previously typed commands \n\
  -> Most of the time there is auto-completion with the \n\
     tab-key available \n\
  -> Copy & paste is down with Ctrl-Shift-C and \n\
     Ctrl-Shift-V \n\
  -> \033[91mCtrl-C kills guacamole!!!\033[0m Only use it, if you \n\
     really want to! \n\n\
Continue by typing 'tip(2)'!\n",

  2:
"\n----------------------------------------------------------\n\n\
Let's create an incredibly awesome scene with \n\
\033[92mguacamole\033[0m! First you will need a scenegraph. Create one\n\
by typing \n\n\
\033[93mgraph = avango.gua.nodes.SceneGraph(Name = 'scenegraph')\033[0m\n\n\
Afterwards continue with 'tip(3)'!\n",

 3:
"\n----------------------------------------------------------\n\n\
Well done! In order to help, I created a SimpleViewer \n\
for you. Assign the newly created scenegraph to my viewer \n\
by typing \n\n\
\033[93mviewer.SceneGraph.value = graph\033[0m\n\n\
You need to write \".value\" because SceneGraph is a field.\n\
Fields are a powerful tool for building complex dataflows and\n\
you will learn how to build your first dependency graph later.\n\
Just accept this syntax for the moment.\n\n\
Continue with the next tip! As an alternative to 'tip(4)',\n\
you may use 'next_tip()' as well.\n",

 4:
"\n----------------------------------------------------------\n\n\
Now you've got a scary, black window! Add some love by adding\n\
a background texture:\n\n\
\033[93mviewer.set_background_image('data/textures/checker.png')\033[0m\n\n\
(afterwards: tip(5) or 'next_tip()'!)\n",

  5:
"\n----------------------------------------------------------\n\n\
Now your scenegraph is still empty! Let's \n\
add some 3D-stuff! First you will need to load a 3D-model. \n\
Therefore you will need a TriMeshLoader: \n\n\
\033[93mloader = avango.gua.nodes.TriMeshLoader()\033[0m\n\n\
(afterwards: tip(6) or 'next_tip()'!)\n",

  6:
"\n----------------------------------------------------------\n\n\
Now you have to load a 3D-model as TriMeshNode. \n\
This is done by: \n\n\
\033[93mmonkey_node = loader.create_geometry_from_file('monkey', 'data/objects/monkey.obj', avango.gua.LoaderFlags.DEFAULTS)\033[0m\n\n\
The first parameter ('monkey') is the new node's name. \n\
The second is the 3D-model file and finally you can pass some flags \n\
to the loader. Just use the defaults.\n\n\
To assing a texture to the monkey, type:\n\n\
\033[93mmonkey_node.Material.value.set_uniform(\"ColorMap\", \"data/textures/stones.jpg\")\033[0m\n\n\
Continue by typing 'tip(7)' or 'next_tip()'!\n",

  7:
"\n----------------------------------------------------------\n\n\
Finally, you need to add the newly created monkey \n\
to your scenegraph. Type: \n\n\
\033[93mgraph.Root.value.Children.value.append(monkey_node)\033[0m\n\n\
Continue by typing 'tip(8)' or 'next_tip()'!\n",

  8:
"\n----------------------------------------------------------\n\n\
Have you ever been inside a monkey's head? No? Definitely not \n\
a good place to be! Let's add some controls for moving around: \n\n\
\033[93mviewer.start_navigation()\033[0m\n\n\
Now you can cruise around in your scene by using the W A S D \n\
keys and your mouse. \n\n\
Continue by typing 'tip(9)' or 'next_tip()'!\n",

 9:
"\n----------------------------------------------------------\n\n\
Awesome! But it's a bit dark in here. Let's add a \n\
lamp! You can do it! It's as simple as:\n\n\
\033[93mlamp_node = avango.gua.nodes.LightNode(Type=avango.gua.LightType.SPOT, Name='lamp', EnableShadows=True, EnableGodrays=True)\033[0m\n\n\
You'll have to transform it in order to see the light...\n\n\
\033[93mlamp_node.Transform.value = avango.gua.make_trans_mat(0, 3, 0) * avango.gua.make_rot_mat(-90, 1, 0, 0) * avango.gua.make_scale_mat(55, 55, 30)\033[0m\n\n\
...and add it to the scenegraph as well:\n\n\
\033[93mgraph.Root.value.Children.value.append(lamp_node)\033[0m\n\n\
Don't forget the next tip!",

 10:
"\n----------------------------------------------------------\n\n\
Beautiful! Isn't it? You got a nice monkey! Let's add \n\
a floor! First load it, then add it to the scenegraph! \n\n\
\033[93mplane_node = loader.create_geometry_from_file('floor', 'data/objects/plane.obj', avango.gua.LoaderFlags.DEFAULTS)\033[0m\n\n\
\033[93mplane_node.Material.value.set_uniform(\"ColorMap\", \"data/textures/tiles.jpg\")\033[0m\n\n\
\033[93mgraph.Root.value.Children.value.append(plane_node)\033[0m\n\n\
Continue by typing 'tip(11)' or 'next_tip()'!\n",

 11:
"\n----------------------------------------------------------\n\n\
For your convenience, I have added a function that is able \n\
to print the scenegraph for you. Just try it out by typing \n\n\
\033[93mprint_graph(graph.Root.value)\033[0m\n\n\
For the time being, just note the three nodes \"monkey\", \"lamp\"\n\
and \"floor\" you have added so far. The \"navigation\" node and its\n\
children have been added automatically during startup.\n\n\
You can use this function throughout the tutorial whenever you are\n\
unsure about the underlying scenegraph structure.\n\n\
Continue by typing 'tip(12)' or 'next_tip()'!\n",

 12:
"\n----------------------------------------------------------\n\n\
Okay, let's move the plane down a bit! \n\n\
\033[93mplane_node.Transform.value = avango.gua.make_trans_mat(0, -2, 0)\033[0m\n\n\
Continue by typing 'tip(13)' or 'next_tip()'!\n",

 13:
"\n----------------------------------------------------------\n\n\
Maybe a bit bigger?\n\n\
\033[93mplane_node.Transform.value = avango.gua.make_trans_mat(0, -2, 0) * avango.gua.make_scale_mat(5, 1, 5)\033[0m\n\n\
Continue by typing 'tip(14)' or 'next_tip()'!\n",

 14: 
"\n----------------------------------------------------------\n\n\
There are three transformation types:\n\n\
translation: avango.gua.make_trans_mat(x, y, z) \n\
scaling:     avango.gua.make_scale_mat(x, y, z) \n\
rotation:    avango.gua.make_rot_mat(angle, x, y, z) \n\n\
For your next task, type \n\n\
\033[93madd_sample_monkey(graph)\033[0m\n\n\
followed by 'tip(14)' or 'next_tip()'!\n",

  15:
"\n----------------------------------------------------------\n\n\
A new monkey appeared! Now try to set the position, \n\
rotation and scale of your original monkey to be exact \n\
the same! You're finished, if your monkey is exactly \n\
inside the other!\n\n\
When you're ready, 'tip(16)' or 'next_tip()'!\n",

  16:
"\n----------------------------------------------------------\n\n\
Well done (At least, I hope so)! Now on to some more \n\
stuff! Your scenegraph object has many nodes now, but all \n\
are attached to the root (verify that by printing the scene graph)!\n\
Let's create a group of objects, which are moved around together.\n\n\
You'll need a TransformNode:\n\n\
\033[93mmonkey_node.Transform.value = avango.gua.make_identity_mat()\033[0m\n\
\033[93mtransform_node = avango.gua.nodes.TransformNode(Name = 'group')\033[0m\n\
\033[93mgraph.Root.value.Children.value.append(transform_node)\033[0m\n\n\
Continue by typing 'tip(17)' or 'next_tip()'!\n",

  17:
"\n----------------------------------------------------------\n\n\
Now we need some objects we can attach to this group:\n\n\
\033[93mpot1 = loader.create_geometry_from_file('pot1', 'data/objects/teapot.obj', avango.gua.LoaderFlags.DEFAULTS)\033[0m\n\
\033[93mpot2 = loader.create_geometry_from_file('pot2', 'data/objects/teapot.obj', avango.gua.LoaderFlags.DEFAULTS)\033[0m\n\
\033[93mpot3 = loader.create_geometry_from_file('pot3', 'data/objects/teapot.obj', avango.gua.LoaderFlags.DEFAULTS)\033[0m\n\n\
Continue by typing 'tip(18)' or 'next_tip()'!\n",

  18:
"\n----------------------------------------------------------\n\n\
Now add them all to our group node:\n\n\
\033[93mtransform_node.Children.value = [pot1, pot2, pot3]\033[0m\n\n\
Check out the scenegraph layout to understand what you have just done.\n\n\
Continue by typing 'tip(19)' or 'next_tip()'!\n",

  19:
"\n----------------------------------------------------------\n\n\
Move them all to different places:\n\n\
\033[93mpot1.Transform.value = avango.gua.make_trans_mat(2,  0, 0) * avango.gua.make_scale_mat(0.2, 0.2, 0.2)\033[0m\n\
\033[93mpot2.Transform.value = avango.gua.make_trans_mat(0,  0, 2) * avango.gua.make_scale_mat(0.2, 0.2, 0.2)\033[0m\n\
\033[93mpot3.Transform.value = avango.gua.make_trans_mat(-2,  0, 0) * avango.gua.make_scale_mat(0.2, 0.2, 0.2)\033[0m\n\
Continue by typing 'tip(20)' or 'next_tip()'!\n",

  20:
"\n----------------------------------------------------------\n\n\
Now you may try to position all pots on the floor by \n\
moving the transform_node down!\n\n\
transform_node.Transform.value = ...\n\n\
Continue by typing 'tip(21)' or 'next_tip()'!\n",

  21:
"\n----------------------------------------------------------\n\n\
Let's get our monkey some new looks!\n\
In \033[92mguacamole\033[0m, each TriMeshNode has an assigned material.\n\
As a matter of fact, you can change a TriMeshNode's material at runtime. \n\
You can pass coefficients for Emissivity, Roughness and Metalness directly \n\
to the shader. You can also pass texture uniforms directly to the shader,\n\
just like I asked you to do already. Try:\n\n\
\033[93mmonkey_node.Material.value.set_uniform(\"ColorMap\", \"data/textures/grass.jpg\")\033[0m\n\n\
Afterwards, play around with the shading coefficients.\n\
You can try, for example:\n\n\
\033[93mmonkey_node.Material.value.set_uniform(\"Emissivity\", 1.0)\033[0m\n\n\
Continue by typing 'tip(22)' or 'next_tip()'!\n",

  22:
"\n----------------------------------------------------------\n\n\
Time for some fancy stuff!\n\
Throughout this tutorial you have worked with \033[92mguacamole\033[0m's nodes\n\
and even defined some hierarchical dependencies between them using the\n\
scenegraph structure.\n\
However, there is another way of defining dependencies in \033[92mguacamole\033[0m:\n\
A so called dependency graph.\n\
Let me show you, what this means...\n\n\
Move on by typing 'tip(23)' or 'next_tip()'!\n",

  23:
"\n----------------------------------------------------------\n\n\
I prepared a little something for you.\n\
There is an object called 'timed_rotate' which has a field called\n\
'MatrixOut'. This contains a matrix which rotates around the\n\
y-Axis and is being updated every frame.\n\
Let's use this to give your monkey some spin:\n\n\
\033[93mmonkey_node.Transform.connect_from(timed_rotate.MatrixOut)\033[0m\n\n\
Continue by typing 'tip(24)' or 'next_tip()'!\n",

  24:
"\n----------------------------------------------------------\n\n\
Let's speed this up! Use the field 'RotationSpeed' to controll\n\
how fast the monkey is spinning!\n\n\
\033[93mtimed_rotate.RotationSpeed.value = 50.0\033[0m\n\n\
Continue by typing 'tip(25)' or 'next_tip()'!\n",

  25:
"\n----------------------------------------------------------\n\n\
I bet you tried to set the rotation speed higher than 50.0, right? ;-)\n\n\
As you can see, you can define dependencies between fields by simply using\n\
the 'connect_from()' method! Now it's your turn!\n\
Make all of the teapots spin around by connecting the 'Transform' field\n\
of 'transform_node' to 'MatrixOut' of 'timed_rotate' as well!\n\n\
If you are done, continue by typing 'tip(26)' or 'next_tip()'!\n",

  26:
"\n----------------------------------------------------------\n\n\
Gosh! What happened! All your teapots are no longer on the floor!\n\
This is due to the timed_rotate's behaviour: It produces a rotation \n\
only and therefore all translations are lost! Let's fix that! \n\
You'll need to perform the following steps: \n\n\
  -> Create a new TransformNode which is responsible for the translation\n\
  -> Add the new TransformNode to your scenegraph\n\
  -> Detach the Teapot-Group from the root of your scenegraph \n\
     (hint: graph.Root.value.Children.value.remove( ... ))\n\
  -> Attach the Teapot-Group to your new TransformNode\n\n\
Now try to do this on your own! You can use the print_graph\n\
function to check the current layout of the scenegraph.\n\n\
If you're struggling -- the neccessary code comes with the next tip!\n\n\
Continue by typing 'tip(27)' or 'next_tip()'!\n",

  27:
"\n----------------------------------------------------------\n\n\
Here is how it's done:\n\n\
\033[93mtea_move_node = avango.gua.nodes.TransformNode(Name = 'teaMove')\033[0m\n\
\033[93mtea_move_node.Transform.value = avango.gua.make_trans_mat(0, -1.85, 0)\033[0m\n\
\033[93mgraph.Root.value.Children.value.remove(transform_node)\033[0m\n\
\033[93mgraph.Root.value.Children.value.append(tea_move_node)\033[0m\n\
\033[93mtea_move_node.Children.value.append(transform_node)\033[0m\n\n\
Continue by typing 'tip(28)' or 'next_tip()'!\n",

  28:
"\n----------------------------------------------------------\n\n\
Okay! So let's see what you have learned today:\n\
  -> Using me, GuaVE, as an interactive Python interpreter.\n\
  -> Creating a \033[92mguacamole\033[0m scenegraph and display it.\n\
     (tips 1 to 3)\n\
  -> Loading 3D-models and add them to the scenegraph.\n\
     (tips 6 to 8)\n\
  -> Adding lights to your scene.\n\
     (tip 9)\n\
  -> Translating, scaling and rotating objects.\n\
     (tips 10 to 15)\n\
  -> Grouping objects in the scene and manipulating them as a whole.\n\
     (tips 16 to 20)\n\
  -> Changing a geometry's material.\n\
     (tip 21)\n\
  -> Using field connections to describe dependency graphs.\n\
     (tips 22 to 27)\n\n\
This shall be it as a first glimpse on \033[92mguacamole\033[0m.\n\
Of course, there are a lot of other things to\n\
learn and to experiment with!\n\n\
Now have a look at the examples located\n\
in \033[93m/opt/avango/master/examples\033[0m. The simple_example,\n\
simple_physics and big_scenegraph_example directories\n\
are good starting points teaching how to write spicy\n\
\033[92mguacamole\033[0m applications!\n\n\
Anyhow, thank you for taking this little course\n\
and have fun fooling around with \033[92mguacamole\033[0m!\n",

  29:
 "I'm serious, this is the end of the tutorial! :-) \n"
}


### simple_example, simple_physics, big_scenegraph_example

current_tip = -1
tip_count = len(tips)
viewer = SimpleViewer()
timed_rotate = TimedRotate()

def launch_from(tip_id):
  
  if tip_id > 2:
    graph = avango.gua.nodes.SceneGraph(Name = 'scenegraph')
  if tip_id > 3:
    viewer.SceneGraph.value = graph
  if tip_id > 4:
    viewer.set_background_image('data/textures/checker.png')
  if tip_id > 5:
    loader = avango.gua.nodes.TriMeshLoader()
  if tip_id > 6:
    monkey_node = loader.create_geometry_from_file('monkey', 'data/objects/monkey.obj', avango.gua.LoaderFlags.DEFAULTS)
    monkey_node.Material.value.set_uniform("ColorMap", "data/textures/stones.jpg")
  if tip_id > 7:
    graph.Root.value.Children.value.append(monkey_node)
  if tip_id > 8:
    viewer.start_navigation()
  if tip_id > 9:
    lamp_node = avango.gua.nodes.LightNode(Type=avango.gua.LightType.SPOT, Name='lamp', EnableShadows=True, EnableGodrays=True)
    lamp_node.Transform.value = avango.gua.make_trans_mat(0, 3, 0) * avango.gua.make_rot_mat(-90, 1, 0, 0) * avango.gua.make_scale_mat(55, 55, 30)
    graph.Root.value.Children.value.append(lamp_node)
  if tip_id > 10:
    plane_node = loader.create_geometry_from_file('floor', 'data/objects/plane.obj', avango.gua.LoaderFlags.DEFAULTS)
    plane_node.Material.value.set_uniform("ColorMap", "data/textures/tiles.jpg")
    graph.Root.value.Children.value.append(plane_node)
  if tip_id > 12:
    plane_node.Transform.value = avango.gua.make_trans_mat(0, -2, 0)
  if tip_id > 13:
    plane_node.Transform.value = avango.gua.make_trans_mat(0, -2, 0) * avango.gua.make_scale_mat(5, 1, 5)
  if tip_id > 14:
    add_sample_monkey(graph)
  if tip_id > 15:
    monkey_node.Transform.value = avango.gua.make_trans_mat(2, 1, 0) * avango.gua.make_rot_mat(90, 0, 1, 0) * avango.gua.make_scale_mat(0.5, 0.5, 0.5)
  if tip_id > 16:
    monkey_node.Transform.value = avango.gua.make_identity_mat()
    transform_node = avango.gua.nodes.TransformNode(Name = 'group')
    graph.Root.value.Children.value.append(transform_node)
  if tip_id > 17:
    pot1 = loader.create_geometry_from_file('pot1', 'data/objects/teapot.obj', avango.gua.LoaderFlags.DEFAULTS)
    pot2 = loader.create_geometry_from_file('pot2', 'data/objects/teapot.obj', avango.gua.LoaderFlags.DEFAULTS)
    pot3 = loader.create_geometry_from_file('pot3', 'data/objects/teapot.obj', avango.gua.LoaderFlags.DEFAULTS)
  if tip_id > 18:
    transform_node.Children.value = [pot1, pot2, pot3]
  if tip_id > 19:
    pot1.Transform.value = avango.gua.make_trans_mat(2,  0, 0) * avango.gua.make_scale_mat(0.2, 0.2, 0.2)
    pot2.Transform.value = avango.gua.make_trans_mat(0,  0, 2) * avango.gua.make_scale_mat(0.2, 0.2, 0.2)
    pot3.Transform.value = avango.gua.make_trans_mat(-2,  0, 0) * avango.gua.make_scale_mat(0.2, 0.2, 0.2)
  if tip_id > 20:
    transform_node.Transform.value = avango.gua.make_trans_mat(0.0, 1.75, 0.0)
  if tip_id > 21:
    monkey_node.Material.value.set_uniform("ColorMap", "data/textures/grass.jpg")
    monkey_node.Material.value.set_uniform("Emissivity", 1.0)
  if tip_id > 23:
    monkey_node.Transform.connect_from(timed_rotate.MatrixOut)
  if tip_id > 24:
    timed_rotate.RotationSpeed.value = 50.0
  if tip_id > 25:
    transform_node.Transform.connect_from(timed_rotate.MatrixOut)
  if tip_id > 26:
    tea_move_node = avango.gua.nodes.TransformNode(Name = 'teaMove')
    tea_move_node.Transform.value = avango.gua.make_trans_mat(0, -1.85, 0)
    graph.Root.value.Children.value.remove(transform_node)
    graph.Root.value.Children.value.append(tea_move_node)
    tea_move_node.Children.value.append(transform_node)

  tip(tip_id)
  viewer.run(locals(), globals(), False)


def add_sample_monkey(graph):
  loader = avango.gua.nodes.TriMeshLoader()
  monkey = loader.create_geometry_from_file("another_monkey", "data/objects/monkey.obj", avango.gua.LoaderFlags.DEFAULTS)
  monkey.Material.value.set_uniform("ColorMap", "data/textures/stones.jpg")
  monkey.Transform.value = avango.gua.make_trans_mat(2, 1, 0) * avango.gua.make_rot_mat(90, 0, 1, 0) * avango.gua.make_scale_mat(0.5, 0.5, 0.5)
  graph.Root.value.Children.value.append(monkey)

def print_graph(root_node):
  stack = [(root_node, 0)]
  while stack:
    node, level = stack.pop()
    print("│   " * level + "├── {0} <{1}>".format(
      node.Name.value, node.__class__.__name__))
    stack.extend(
      [(child, level + 1) for child in reversed(node.Children.value)])

def tip(which):
  global current_tip
  global tips
  current_tip = max(min(which, tip_count - 2),-1)

  # launch file browser in final tip
  if current_tip == 28:
    os.system("nautilus /opt/avango/master/examples")


  print(tips[current_tip])

def next_tip():
  global current_tip
  tip(current_tip + 1)

def previous_tip():
  global current_tip
  tip(current_tip - 1)

def start(tip_id):
  global timed_rotate

  timer = avango.nodes.TimeSensor()
  timed_rotate.TimeIn.connect_from(timer.Time)

  logger = avango.gua.nodes.Logger(EnableWarning = True)

  launch_from(tip_id)


if __name__ == '__main__':

  if len(sys.argv) > 1:
    start(int(sys.argv[1]))
  else:
    start(-1)


<h1 align="center">
  Mario QT
</h1>
  
<p align="center">
  A playable Super Mario Bros Nes style Mario level editor
</p>

<div align="center">
 
  [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
  [![License: MIT](https://img.shields.io/badge/Play-Live-4cc71f?logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQBAMAAADt3eJSAAABhWlDQ1BJQ0MgcHJvZmlsZQAAKJF9kT1Iw0AcxV9TxQ8qFewg4pChOlkQFdFNqlgEC6Wt0KqDyaVf0KQhSXFxFFwLDn4sVh1cnHV1cBUEwQ8QZwcnRRcp8X9JoUWMB8f9eHfvcfcOEOplppod44CqWUYyFhUz2VWx6xUCguhBP2YlZurx1GIanuPrHj6+3kV4lve5P0efkjMZ4BOJ55huWMQbxNObls55nzjEipJCfE48ZtAFiR+5Lrv8xrngsMAzQ0Y6OU8cIhYLbSy3MSsaKvEUcVhRNcoXMi4rnLc4q+Uqa96TvzCQ01ZSXKc5jBiWEEcCImRUUUIZFiK0aqSYSNJ+1MM/5PgT5JLJVQIjxwIqUCE5fvA/+N2tmZ+ccJMCUaDzxbY/RoCuXaBRs+3vY9tunAD+Z+BKa/krdWDmk/RaSwsfAcFt4OK6pcl7wOUOMPikS4bkSH6aQj4PvJ/RN2WBgVugd83trbmP0wcgTV0t3wAHh8BogbLXPd7d3d7bv2ea/f0Ai1FysZRfcCcAAAAJcEhZcwAACxMAAAsTAQCanBgAAAAHdElNRQfoAg8JFwVuWDvvAAAAG1BMVEUAAACCdxeDdxeDdxjVAADWAAD/mAD/mAH///9fM8HFAAAAAXRSTlMAQObYZgAAAAFiS0dECIbelXoAAABfSURBVAgdBcHBDYQwFEPBp68lJXBGFkkBlLAV5OI7ioQ7oH9mAIAWAHu2AJttByhlLwFjZI+AoawsQIl0ACRZgNR1HlCS/ppFJNmzyP3rfl7RarNtwdVtW5RsT6CwAT7HHBXIkM0uegAAAABJRU5ErkJggg==)](https://colintr.fr/mario/Mario.html)
</div>


### Play it live at https://colintr.fr/mario/Mario.html !


## 🚀 Installation

For windows: <a id="raw-url" href="https://raw.githubusercontent.com/ColinTr/MarioQT/master/Mario_Editor_installer.exe">download the installer</a>

## 🎮 Controls

- <b>Q</b> and <b>D</b> for left and right control
- <b>Space</b> to jump
- <b>Shift</b> to shoot fireball
- <b>T</b> to show hitboxes
- <b>R</b> to restart the level
- <b>C</b> for power-up

![Screenshot](readme_imgs/ingame.png)


## 🔧 Updating and compiling the code

1. Download [Qt Creator](https://www.qt.io/download-qt-installer-oss) and install Qt 5.15.2 MSCV 2019

2. Compiling an executable (see https://www.youtube.com/watch?v=rFHPOZoqzcg):
	```
	cd C:\Qt\5.15.2\msvc2019\bin\
	windeployqt.exe C:\Users\Username\Desktop\Mario.exe
	```

3. Compiling for webassembly (see https://www.youtube.com/watch?v=YSAUoAI5hQA):
	```
	cd emsdk
	emsdk activate 1.39.8
	cd mario-webassembly-build
	qmake MarioQT\source_code
	mingw32-make
	```
	
	If you have memory errors during mingw32-make, add the following flag to the Mario.pro file:
	> QMAKE_LFLAGS+= "-s TOTAL_MEMORY=33554432"


## 🎥 Trailer

https://www.youtube.com/watch?v=-SCnSPH7mK8


## ❓ What is it

This software is part of the DI4 C++ QT project.
It was developed by Guillaume Bouchard, Colin Troisemaine, Alexandre Turpin, and Quentin Levieux.
The goal was to create a Mario-type platformer game using QT and the MVC pattern.
We aimed to reproduce the NES game Super Mario Bros.


## 💻 Installation

Since the project is a QT project, it is cross-platform. We recommend installing QTCreator for compiling the project (File -> "Open File or Project" and select <i>Mario.Pro</i>).


## 🛠️ Software Composition

The software is composed of several parts, the main part being the game itself.
There is also a graphical level editor that allows exporting created levels in JSON format, a key configuration window also exportable in JSON format, all accessible from the main menu.


## ⚙️ Game Inner Workings

The game follows the MVC model and is divided into three distinct parts:

- The model consists of subclasses of ObjectModel that represent all the objects in our game. The objects are divided into two categories: inerts (non-moving objects) and entities (objects with the advance() function).

- The view is composed of the GameView class, which is a QWidget and displays the objects on the screen using Visitor (see the design pattern).

- The controller with the GameController class, which contains the main loop of our game. GameController has a list of objects and, at each iteration of its main loop (the advance() function), calculates the new position of the objects, checks for collisions with other objects, resolves collisions if necessary, and finally animates the object. Then, it calls the view to repaint its scene.


## 📸 Game Screenshots

- Level editor:

![Screenshot](readme_imgs/leveleditor.png)

- Main menu:

![Screenshot](readme_imgs/menu.png)

- Options menu:

![Screenshot](readme_imgs/option.png)


## ⚖️ License

This code is released under the MIT license. See the LICENSE file for more information.

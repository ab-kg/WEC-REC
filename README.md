wec-rec 

Tasks have been implemented related to grpahics programming 
1. rendering a polygon
2. rendering a model 
3. implementing interactive camera
4. Frame Capture
5. Texture Mapping

how to build

git clone --recursive https://github.com/ab-kg/WEC-REC.git 

cd WEC-REC

mkdir build && cd build


* To generate proj files

cmake ..

* To build the executable 

cmake --build .


TASK1 ==> renders a polygon 
<img width="500" height="500" alt="hexagon" src="https://github.com/user-attachments/assets/d520dd62-8399-4796-ae5d-09a0169b9049" />
<img width="500" height="500" alt="hexagon" src="https://github.com/user-attachments/assets/9336a863-215f-4879-95a5-5bdfb5c09b07" />

TASK2 ==> renders .obj model with interactive camera

![realmodel](https://github.com/user-attachments/assets/c155c6b0-1eb4-4343-b3ec-a79cba972b39)

[MP4 Video Demo](https://drive.google.com/file/d/1ecvmgpcTJukxN4EXXk0_tmYD3b7dxspG/view?usp=sharing)

W - move forward 

S - move backward

A - move left 

D - move right 

LSHIFT - move down

SPACE - move up 

TASK3 ==> renders textured cube blocks 

![texture](https://github.com/user-attachments/assets/f70e3efe-e461-4ef6-af5a-145c85d82f1e)



# wec-rec  

Tasks have been implemented related to graphics programming:  

1. Rendering a polygon  
2. Rendering a model  
3. Implementing interactive camera  
4. Frame Capture  
5. Texture Mapping  

---

## TASK1 ⇒ renders a polygon  

<img width="500" height="400" alt="octagon" src="https://github.com/user-attachments/assets/8eeada1d-8f77-465b-b6e9-2ad6098b4b0d" />  

<img width="500" height="400" alt="hexagon" src="https://github.com/user-attachments/assets/9336a863-215f-4879-95a5-5bdfb5c09b07" />  

---

## TASK2 ⇒ renders .obj model with interactive camera  

![realmodel](https://github.com/user-attachments/assets/c155c6b0-1eb4-4343-b3ec-a79cba972b39)  

[![Video Demo](https://img.shields.io/badge/Watch-Demo-red?style=for-the-badge)](https://drive.google.com/file/d/1ecvmgpcTJukxN4EXXk0_tmYD3b7dxspG/view?usp=sharing)

**Controls:**  

| Key | Action |
|-----|--------|
| W | move forward |
| S | move backward |
| A | move left |
| D | move right |
| LSHIFT | move down |
| SPACE | move up |

---

## TASK3 ⇒ renders textured cube blocks  

![texture](https://github.com/user-attachments/assets/f70e3efe-e461-4ef6-af5a-145c85d82f1e)  

---

## How to build

[![Clone Repo](https://img.shields.io/badge/Git-Clone-blue?style=for-the-badge)](https://github.com/ab-kg/WEC-REC.git)

```bash
git clone --recursive https://github.com/ab-kg/WEC-REC.git 
cd WEC-REC
mkdir build && cd build
cmake ..  ( For generating proj files )
cmake --build . ( For building the executable ) 


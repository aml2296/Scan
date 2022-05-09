#ifndef MATERIAL
#define MATERIAL
enum Colors
{
    White,
    Red,
    Green,
    Blue,
    Black
};
enum MatType
{
    None
};

class BathMaterial
{
    Colors color = Red;
    MatType Type = None; 
};
#endif

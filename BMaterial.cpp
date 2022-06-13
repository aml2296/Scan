#ifndef MATERIAL
#define MATERIAL
enum class Colors
{
    White,
    Red,
    Green,
    Blue,
    Black
};
enum class MatType
{
    None = -1
};

class BathMaterial
{
    Colors color;
    MatType Type; 
};
#endif

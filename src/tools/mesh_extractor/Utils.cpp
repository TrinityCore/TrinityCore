#include "Utils.h"
#include "Constants.h"
#include <cstring>
#include "g3d/Matrix4.h"

const float Constants::TileSize = 533.0f + (1/3.0f);
const float Constants::MaxXY = 32.0f * Constants::TileSize;
const float Constants::ChunkSize = Constants::TileSize / 16.0f;
const float Constants::UnitSize = Constants::ChunkSize / 8.0f;
const float Constants::Origin[] = { -Constants::MaxXY, 0.0f, -Constants::MaxXY };
const float Constants::PI = 3.1415926f;

void Utils::Reverse(char word[])
{
    int len = strlen(word);
    for (int i = 0;i < len / 2; i++)
    {
        word[i] ^= word[len-i-1];
        word[len-i-1] ^= word[i];
        word[i] ^= word[len-i-1];
    }
}

std::string Utils::ReadString( FILE* file )
{
    std::string ret;
    int i = 0;
    while (true)
    {
        char b;
        fread(&b, sizeof(char), 1, file);
        if (b == 0)
            break;
        ret[i++] = b;
    }
    return ret;
}

uint32 Utils::Size( FILE* file )
{
    // store the old position
    uint32 offset = ftell(file);
    // Get file size
    fseek(file, 0, SEEK_END);
    uint32 size = ftell(file);
    // reset back to the old position
    fseek(file, offset, SEEK_SET);
    return size;
}

Vector3 Utils::ToRecast( Vector3 val )
{
    return Vector3(-val.y, val.z, -val.x);
}

std::string Utils::GetAdtPath( std::string world, int x, int y )
{
    return "World\\Maps\\" + world + "\\" + world + "_" + Utils::ToString(x) + "_" + Utils::ToString(y) + ".adt";
}

std::string Utils::FixModelPath( std::string path )
{
    std::string::size_type idx = path.rfind(".");
    // Bizarre way of changing extension but...
    if (idx != std::string::npos)
    {
        path[idx + 1] = "M";
        path[idx + 2] = "2";
    }
    return path;
}

G3D::Matrix4 Utils::RotationX(float angle)
{
    float _cos = cos(angle);
    float _sin = sin(angle);
    G3D::Matrix4 ret = G3D::Matrix4::identity();
    ret[2][2] = _cos;
    ret[2][3] = _sin;
    ret[3][2] = -_sin;
    ret[3][3] = _cos;
    return ret;
}

G3D::Matrix4 Utils::GetTransformation(IDefinition def)
{
    G3D::Matrix4 translation;
    if (def.Position.x == 0.0f && def.Position.y == 0.0f && def.Position.z == 0.0f)
        translation = G3D::Matrix4::identity();
    else
        translation = G3D::Matrix4::translation(-(def.Position.z - Constants::MaxXY),
            -(def.Position.x - Constants::MaxXY), def.Position.y);

    G3D::Matrix4 rotation = RotationX(ToRadians(def.Rotation.z)) * RotationY(ToRadians(def.Rotation.x)) * RotationZ(ToRadians(def.Rotation.y + 180));
    if (def.Scale() < 1.0f || def.Scale() > 1.0f)
        return G3D::Matrix4::scale(def.Scale()) * rotation * translation;
    return rotation * translation;
}

G3D::Matrix4 Utils::RotationY( float angle )
{
    float _cos = cos(angle);
    float _sin = sin(angle);
    G3D::Matrix4 ret = G3D::Matrix4::identity();
    ret[1][1] = _cos;
    ret[1][3] = -_sin;
    ret[3][1] = _sin;
    ret[3][3] = _cos;
    return ret;
}

G3D::Matrix4 Utils::RotationZ( float angle )
{
    float _cos = cos(angle);
    float _sin = sin(angle);
    G3D::Matrix4 ret = G3D::Matrix4::identity();
    ret[1][1] = _cos;
    ret[1][2] = _sin;
    ret[2][1] = -_sin;
    ret[2][2] = _cos;
    return ret;
}

float Utils::ToRadians( float degrees )
{
    return Constants::PI * degrees / 180.0f;
}

Vector3 Utils::VectorTransform( Vector3 vec, G3D::Matrix4 matrix )
{
    Vector3 ret;
    ret.x = vec.x * matrix[1][1] + vec.y * matrix[2][1] + vec.z * matrix[3][1] + matrix[4][1];
    ret.y = vec.x * matrix[1][2] + vec.y * matrix[2][2] + vec.z * matrix[3][2] + matrix[4][2];
    ret.z = vec.x * matrix[1][3] + vec.y * matrix[2][3] + vec.z * matrix[3][3] + matrix[4][3];
    return ret;
}

std::string Utils::GetPathBase( std::string path )
{
    int lastIndex = path.find_last_of("."); 
    if (lastIndex != std::string::npos)
        return path.substr(0, lastindex);
    return path;
}

Vector3 Vector3::Read( FILE* file )
{
    Vector3 ret;
    fread(&ret, sizeof(Vector3), 1, file);
    return ret;
}

Vector3 Utils::GetLiquidVert(G3D::Matrix4 transformation, Vector3 basePosition, float height, int x, int y)
{
    if (Utils::Distance(height, 0.0f) > 0.5f)
        basePosition.z = 0.0f;
    return Utils::VectorTransform(basePosition + Vector3(basePosition.x * Constants::UnitSize, basePosition.y * Constants::UnitSize, height), transformation);
}

float Utils::Distance( float x, float y )
{
    return sqrt(x*x + y*y);
}

std::string Utils::Replace( std::string str, const std::string& oldStr, const std::string& newStr )
{
    size_t pos = 0;
    while((pos = str.find(oldStr, pos)) != std::string::npos)
    {
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
    return str;
}

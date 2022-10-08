#include "blackrock_foundry.h"

Position const g_OreCrateSpawnPos[eFoundryDatas::MaxOreCrateSpawns] =
{
    { 16.221f, 3537.0501f, 280.97699f, 0.0f },
    { 31.512f, 3537.0601f, 280.97699f, 0.0f },
    { 1.4497f, 3548.2399f, 280.97699f, 0.0f },
    { -12.05f, 3567.3999f, 280.97699f, 0.0f },
    { -11.19f, 3585.7900f, 280.97699f, 0.0f },
    { -11.48f, 3599.4599f, 281.01300f, 0.0f },
    { 1.4514f, 3619.1299f, 281.01300f, 0.0f },
    { 17.313f, 3628.5400f, 281.01300f, 0.0f },
    { 37.201f, 3629.0701f, 281.01300f, 0.0f },
    { 52.556f, 3627.7299f, 281.01300f, 0.0f },
    { 69.613f, 3616.8799f, 280.97699f, 0.0f },
    { 80.066f, 3601.2900f, 280.97699f, 0.0f },
    { 80.977f, 3579.9099f, 280.97699f, 0.0f },
    { 79.835f, 3564.7900f, 280.97699f, 0.0f },
    { 69.385f, 3547.6599f, 280.97699f, 0.0f },
    { 53.776f, 3536.9299f, 280.97699f, 0.0f },
    { 16.865f, 3587.8701f, 281.01300f, 0.0f },
    { 16.045f, 3576.7500f, 280.97699f, 0.0f },
    { 52.951f, 3588.3701f, 280.97699f, 0.0f },
    { 51.832f, 3579.7500f, 280.97699f, 0.0f },
    { 42.146f, 3565.1799f, 280.97699f, 0.0f },
    { 32.075f, 3565.8799f, 280.97699f, 0.0f },
    { 38.521f, 3600.9699f, 280.97699f, 0.0f },
    { 29.146f, 3602.8601f, 280.97699f, 0.0f }
};

Position const g_MovePos[eFoundryDatas::MaxOregorgerMovePos] =
{
    { 29.788f, 3685.025f, 289.8583f, 0.0f },
    { 36.313f, 3677.135f, 290.9291f, 0.0f },
    { 40.641f, 3670.757f, 290.8677f, 0.0f },
    { 43.917f, 3664.390f, 290.9170f, 0.0f },
    { 45.461f, 3657.372f, 290.7451f, 0.0f },
    { 46.257f, 3652.046f, 290.9441f, 0.0f },
    { 46.144f, 3647.808f, 290.4916f, 0.0f },
    { 45.582f, 3642.901f, 290.1242f, 0.0f }
};

Position const g_JumpPos = { 52.8958f, 3617.03f, 280.894f, 4.673866f };

struct PointData
{
    uint8 I;
    uint8 J;
};

PointData const g_CollisionPoints[eFoundryDatas::MaxOregorgerCollisions] =
{
    { 4, 5 },   ///< ID 1: Linked to 4 and 7
    { 4, 4 },   ///< ID 2: Linked to 4 and 7
    { 5, 2 },   ///< ID 3: Linked to 6 and 1
    { 4, 2 },   ///< ID 4: Linked to 6 and 1
    { 2, 1 },   ///< ID 5: Linked to 3 and 8
    { 2, 2 },   ///< ID 6: Linked to 3 and 8
    { 1, 4 },   ///< ID 7: Linked to 2 and 5
    { 2, 4 }    ///< ID 8: Linked to 2 and 5
};

std::pair<uint8, uint8> const g_LinkedCollisionPoints[eFoundryDatas::MaxOregorgerCollisions] =
{
    { 4, 7 },
    { 4, 7 },
    { 6, 1 },
    { 6, 1 },
    { 3, 8 },
    { 3, 8 },
    { 2, 5 },
    { 2, 5 }
};

std::vector<G3D::Vector2> const g_MovementPaths[eFoundryDatas::MaxOregorgerCollisions][eFoundryDatas::MaxOregorgerCollisions] =
{
    /// ID 1
    {
        { }, { }, { },
        {
            { 51.9689f, 3565.5762f }
        },
        { }, { },
        {
            { 53.0510f, 3630.7195f },
            { 3.12688f, 3630.1829f },
            { 2.16871f, 3600.4983f }
        },
        { }
    },
    /// ID 2
    {
        { }, { }, { },
        {
            { 51.9689f, 3565.5762f }
        },
        { }, { },
        {
            { 53.0510f, 3630.7195f },
            { 3.12688f, 3630.1829f },
            { 2.16871f, 3600.4983f }
        },
        { }
    },
    /// ID 3
    {
        {
            { 81.7909f, 3566.0584f },
            { 82.0880f, 3616.8611f },
            { 52.5748f, 3615.9273f }
        },
        { }, { }, { }, { },
        {
            { 17.0675f, 3564.8752f }
        },
        { }, { }
    },
    /// ID 4
    {
        {
            { 81.7909f, 3566.0584f },
            { 82.0880f, 3616.8611f },
            { 52.5748f, 3615.9273f }
        },
        { }, { }, { }, { },
        {
            { 17.0675f, 3564.8752f }
        },
        { }, { }
    },
    /// ID 5
    {
        { }, { },
        {
            { 16.4645f, 3536.6384f },
            { 67.4501f, 3537.7356f },
            { 68.7993f, 3565.3203f }
        },
        { }, { }, { }, { },
        {
            { 17.5330f, 3601.7505f }
        }
    },
    /// ID 6
    {
        { }, { },
        {
            { 16.4645f, 3536.6384f },
            { 67.4501f, 3537.7356f },
            { 68.7993f, 3565.3203f }
        },
        { }, { }, { }, { },
        {
            { 17.5330f, 3601.7505f }
        }
    },
    /// ID 7
    {
        { },
        {
            { 52.0862f, 3601.2969f }
        },
        { }, { },
        {
            { -12.551f, 3600.4168f },
            { -13.469f, 3549.5161f },
            { 15.9366f, 3550.2180f }
        },
        { }, { }, { }
    },
    /// ID 8
    {
        { },
        {
            { 52.0862f, 3601.2969f }
        },
        { }, { },
        {
            { -12.551f, 3600.4168f },
            { -13.469f, 3549.5161f },
            { 15.9366f, 3550.2180f }
        },
        { }, { }, { }
    }
};

/// Some positions in Oregorger's room aren't accessible by players or creatures, just bypass them
bool const g_BypassPoints[eFoundryDatas::MaxOregorgerPatterns][eFoundryDatas::MaxOregorgerPatterns] =
{
    { true,  false, false, false, false, true,  true  },
    { false, false, true,  true,  false, false, false },
    { false, false, false, false, false, true,  false },
    { false, true,  false, true,  false, true,  false },
    { false, true,  false, false, false, false, false },
    { false, false, false, true,  true,  false, true  },
    { true,  false, false, false, false, false, true  }
};

float const g_OregorgerPatternsX[eFoundryDatas::MaxOregorgerPatterns] =
{
    -6.71f,
    10.28f,
    22.23f,
    44.96f,
    60.04f,
    76.24f,
    86.94f
};

float const g_OregorgerPatternsY[eFoundryDatas::MaxOregorgerPatterns] =
{
    3542.52f,
    3558.64f,
    3573.06f,
    3596.53f,
    3609.33f,
    3624.89f,
    3634.95f
};

Position const g_VolatileOreSpawn = { 34.08f, 3636.04f, 281.19f, 4.83f };

float g_BaseRunSpeed    = 2.85714f;
float g_P2RunSpeed      = g_BaseRunSpeed * 2.0f;

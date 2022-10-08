#include "blackrock_foundry.h"

enum eBlackhandActions
{
    BlackhandIntro,
    BlackhandEngaged,
    BlackhandDisengaged,
    BlackhandStartP2,
    BlackhandSpreadBlaze,
    BlackhandStartP3,
    BlackhandSlagEruption
};

enum eBlackhandCreatures
{
    DemolitionStalker           = 77572,
    MassiveDemolitionStalker    = 77577,
    RubblePile                  = 77405,
    IronSoldier                 = 77665,
    IronGunner                  = 77755,
    Siegemaker                  = 77342,
    SlagHole                    = 77357,
    SlagCrater                  = 77774,
    BlazeController             = 77610,
    Blaze                       = 77612,
    IronSentry                  = 77720,
    SlagBomb                    = 77343,
    BlackrockFoundryP2P3Trigger = 77628
};

enum eBlackhandObjects
{
    OreCollision        = 227540,
    SlagWrap            = 239118,
    StoragePortcullis1  = 233562,
    StoragePortcullis2  = 233563,
    StoragePortcullis3  = 233564,
    StoragePortcullis4  = 233565
};

enum eBlackhandDatas
{
    /// Counters
    MaxCosmeticMoves        = 5,
    MaxRegenCyclesP1        = 3,
    MaxRegenCyclesP2        = 4,
    MaxPhases               = 3,
    MaxStoragePortcullis    = 4,
    MaxBlazeSpreadCount     = 3,
    MaxIronSoldiers         = 6
};

static std::vector<uint32> g_EntriesToDespawn =
{
    eBlackhandCreatures::DemolitionStalker,
    eBlackhandCreatures::MassiveDemolitionStalker,
    eBlackhandCreatures::BlazeController,
    eBlackhandCreatures::Blaze,
    eBlackhandCreatures::SlagHole,
    eBlackhandCreatures::SlagCrater
};

static std::array<Position const, eBlackhandDatas::MaxCosmeticMoves> g_BlackhandCosmeticMoves =
{
    {
        { 539.39f, 3444.39f, 741.735f, 4.1741f },
        { 539.88f, 3545.10f, 741.735f, 2.0685f },
        { 598.67f, 3546.09f, 741.735f, 1.0506f },
        { 627.84f, 3494.27f, 741.735f, 0.0375f },
        { 597.74f, 3443.75f, 741.735f, 5.2721f }
    }
};

/// Regens every second, 3 power, then 3 power, then 4 power, 10 power every 3 seconds
static std::array<int32, eBlackhandDatas::MaxRegenCyclesP1> g_BlackhandRegenCyclesP1 =
{
    3, 3, 4
};

static std::array<int32, eBlackhandDatas::MaxRegenCyclesP2> g_BlackhandRegenCyclesP2 =
{
    2, 2, 2, 3
};

static std::array<int32, eBlackhandDatas::MaxPhases> g_BlackhandPhaseSwitchPcts =
{
    70, 30, 0
};

static std::array<Position const, eBlackhandDatas::MaxStoragePortcullis> g_SiegemakerSpawnPos =
{
    {
        { 633.0486f, 3544.559f, 605.4095f, 3.895919f },
        { 636.4879f, 3446.691f, 605.3715f, 2.560644f },
        { 541.1111f, 3572.627f, 605.4115f, 5.075389f },
        { 541.0052f, 3414.282f, 605.3871f, 1.160939f }
    }
};

Position const g_SlagWrapSpawnPos = { 568.623f, 3494.82f, 741.598f, 3.14159f };
Position const g_StartP2JumpPos = { 573.3621f, 3494.884f, 741.6487f, 2.767612f };
Position const g_SecondFloorJumpPos = { 565.961f, 3497.788f, 604.376f, 3.045664f };
Position const g_ThirdFloorJumpPos = { 565.9606f, 3500.114f, 511.844f, 4.094417f };

static std::vector<std::vector<Position>> g_IronSoldierSpawnPos =
{
    {
        { 570.4011f, 3432.209f, 619.0685f, 1.566986f },
        { 567.7239f, 3432.484f, 619.0663f, 1.560594f },
        { 570.3489f, 3433.858f, 619.0632f, 1.540382f },
        { 567.9739f, 3434.096f, 619.0582f, 1.181206f },
        { 568.2691f, 3436.276f, 619.0471f, 3.086635f },
        { 570.4601f, 3436.267f, 619.0514f, 0.015996f }
    },
    {
        { 565.3420f, 3557.065f, 619.1151f, 4.825490f },
        { 568.2864f, 3557.542f, 619.1151f, 5.177013f },
        { 568.6406f, 3555.532f, 619.1151f, 3.549165f },
        { 565.5417f, 3555.420f, 619.1151f, 5.998235f },
        { 569.0278f, 3553.868f, 619.1151f, 2.592803f },
        { 565.9254f, 3553.486f, 619.1151f, 1.683925f }
    }
};

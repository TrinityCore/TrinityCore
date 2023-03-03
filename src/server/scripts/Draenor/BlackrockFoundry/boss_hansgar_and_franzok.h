#include "blackrock_foundry.h"

Position const g_StampingPressCosmeticPos[4] =
{
    { 143.168f, 3492.93f, 130.463f, 0.0f },
    { 123.540f, 3507.37f, 130.466f, 0.0f },
    { 123.540f, 3478.47f, 130.466f, 0.0f },
    { 103.832f, 3492.93f, 130.468f, 0.0f }
};

Position const g_SmartStampCollisionPos[4] =
{
    { 146.668f, 3507.37f, 130.116f, 0.0f },
    { 139.668f, 3507.37f, 130.116f, 0.0f },
    { 127.040f, 3463.96f, 130.116f, 0.0f },
    { 120.040f, 3463.96f, 130.116f, 0.0f }
};

Position const g_StampingPressIntroPos[2] =
{
    { 143.168f, 3507.37f, 130.463f, 0.0f },
    { 123.540f, 3478.47f, 130.466f, 0.0f }
};

Position const g_HansgarJumpPosIn = { 103.434f, 3517.066f, 130.1161f, 0.0f };
Position const g_FranzokJumpPosIn = { 102.6545f, 3465.035f, 130.2772f, 0.0f };

Position const g_HansgarJumpPosOut = { 88.03299f, 3467.769f, 138.4438f, 3.141593f };
Position const g_HansgarJumpPosRetreat = { 85.60069f, 3517.861f, 138.235f, 3.141593f };

float const g_HansgarRetreatOrientation = 5.94246f;

float const g_ScorchingBurnsXPos = 182.5f;

/// Cyclic patterns which always happens for normal/heroic mode
std::vector<uint32> const g_SearingPlatesCycles[5] =
{
    { eFoundryGameObjects::ConveyorBelt002, eFoundryGameObjects::ConveyorBelt003, eFoundryGameObjects::ConveyorBelt004, eFoundryGameObjects::ConveyorBelt005, eFoundryGameObjects::ConveyorBelt001 },
    { eFoundryGameObjects::ConveyorBelt001, eFoundryGameObjects::ConveyorBelt002, eFoundryGameObjects::ConveyorBelt003, eFoundryGameObjects::ConveyorBelt004, eFoundryGameObjects::ConveyorBelt005 },
    { eFoundryGameObjects::ConveyorBelt005, eFoundryGameObjects::ConveyorBelt001, eFoundryGameObjects::ConveyorBelt002, eFoundryGameObjects::ConveyorBelt003, eFoundryGameObjects::ConveyorBelt004 },
    { eFoundryGameObjects::ConveyorBelt004, eFoundryGameObjects::ConveyorBelt005, eFoundryGameObjects::ConveyorBelt001, eFoundryGameObjects::ConveyorBelt002, eFoundryGameObjects::ConveyorBelt003 },
    { eFoundryGameObjects::ConveyorBelt003, eFoundryGameObjects::ConveyorBelt004, eFoundryGameObjects::ConveyorBelt005, eFoundryGameObjects::ConveyorBelt001, eFoundryGameObjects::ConveyorBelt002 }
};

/// Forge Overdrive spawn pos for each Conveyor Belt
std::map<uint32, Position const> g_ForgeOverdriveSpawnPos =
{
    { eFoundryGameObjects::ConveyorBelt001, { 191.8142f, 3522.539f, 130.5489f, 3.196286f } },
    { eFoundryGameObjects::ConveyorBelt002, { 191.7986f, 3508.009f, 130.5486f, 3.147189f } },
    { eFoundryGameObjects::ConveyorBelt003, { 191.5920f, 3492.890f, 130.5486f, 3.139562f } },
    { eFoundryGameObjects::ConveyorBelt004, { 190.5399f, 3478.265f, 130.3344f, 3.141593f } },
    { eFoundryGameObjects::ConveyorBelt005, { 190.8819f, 3463.978f, 130.5486f, 3.140998f } }
};

/// Forge Overdrive dest pos for each Conveyor Belt
std::map<uint32, Position const> g_ForgeOverdriveDestPos =
{
    { eFoundryGameObjects::ConveyorBelt001, { 74.61285f, 3522.023f, 130.4776f, 3.196286f } },
    { eFoundryGameObjects::ConveyorBelt002, { 72.65278f, 3507.342f, 130.7546f, 3.147189f } },
    { eFoundryGameObjects::ConveyorBelt003, { 71.13541f, 3493.135f, 130.5421f, 3.139562f } },
    { eFoundryGameObjects::ConveyorBelt004, { 80.53993f, 3478.265f, 130.3344f, 3.141593f } },
    { eFoundryGameObjects::ConveyorBelt005, { 76.74827f, 3464.046f, 130.4773f, 3.140998f } }
};

/// Movement Force directions for each Conveyor Belt
std::map<uint32, Position const> g_ConveyorForceMovesDirection =
{
    { eFoundryGameObjects::ConveyorBelt001, { 136.2731f, 3521.869f, 130.4693f, 0.0f } },
    { eFoundryGameObjects::ConveyorBelt002, { 136.0504f, 3507.557f, 130.4693f, 0.0f } },
    { eFoundryGameObjects::ConveyorBelt003, { 132.4271f, 3492.807f, 130.4693f, 0.0f } },
    { eFoundryGameObjects::ConveyorBelt004, { 132.4292f, 3478.443f, 130.4693f, 0.0f } },
    { eFoundryGameObjects::ConveyorBelt005, { 131.7153f, 3464.024f, 130.4693f, 0.0f } }
};

struct StampingPressData
{
    StampingPressData()
    {
       // StampingPresses = 0;
       // StampingPress   = 0;
    }

    StampingPressData(ObjectGuid p_Creature, ObjectGuid p_GameObject)
    {
        StampingPresses = p_Creature;
        StampingPress   = p_GameObject;
    }

    ObjectGuid StampingPresses; ///< Creature
    ObjectGuid StampingPress;   ///< GameObject
};

typedef std::list<StampingPressData> StampingPressList;

/// CoveyorBelt Entry - StampingPresses Y pos (or Scorching Burns Y pos)
typedef std::map<uint32, float> ConveyorDatas;

ConveyorDatas const g_ConveyorBeltBurns =
{
    { eFoundryGameObjects::ConveyorBelt001, 3522.769043f },
    { eFoundryGameObjects::ConveyorBelt002, 3507.606934f },
    { eFoundryGameObjects::ConveyorBelt003, 3492.773926f },
    { eFoundryGameObjects::ConveyorBelt004, 3477.840088f },
    { eFoundryGameObjects::ConveyorBelt005, 3461.691895f }
};

ConveyorDatas const g_ConveyorBeltPos =
{
    { eFoundryGameObjects::ConveyorBelt001, 3521.840088f },
    { eFoundryGameObjects::ConveyorBelt002, 3507.370117f },
    { eFoundryGameObjects::ConveyorBelt003, 3492.929932f },
    { eFoundryGameObjects::ConveyorBelt004, 3478.469971f },
    { eFoundryGameObjects::ConveyorBelt005, 3463.969961f }
};

////////////////////////////////////////////////////////////////////////////////
/// Stamping Presses possible patterns definition
////////////////////////////////////////////////////////////////////////////////
typedef std::vector<uint32> StampingPressPattern;

StampingPressPattern const g_FirstPattern =
{
    eFoundryGameObjects::StampingPress17,
    eFoundryGameObjects::StampingPress18,
    eFoundryGameObjects::StampingPress19,
    eFoundryGameObjects::StampingPress20,
    eFoundryGameObjects::StampingPress11,
    eFoundryGameObjects::StampingPress15,
    eFoundryGameObjects::StampingPress07,
    eFoundryGameObjects::StampingPress08,
    eFoundryGameObjects::StampingPress09,
    eFoundryGameObjects::StampingPress05
};

StampingPressPattern const g_SecondPattern =
{
    eFoundryGameObjects::StampingPress16,
    eFoundryGameObjects::StampingPress12,
    eFoundryGameObjects::StampingPress13,
    eFoundryGameObjects::StampingPress14,
    eFoundryGameObjects::StampingPress06,
    eFoundryGameObjects::StampingPress10,
    eFoundryGameObjects::StampingPress01,
    eFoundryGameObjects::StampingPress02,
    eFoundryGameObjects::StampingPress03,
    eFoundryGameObjects::StampingPress04
};

StampingPressPattern const g_ThirdPattern[4] =
{
    {
        eFoundryGameObjects::StampingPress17,
        eFoundryGameObjects::StampingPress18,
        eFoundryGameObjects::StampingPress19,
        eFoundryGameObjects::StampingPress20,
        eFoundryGameObjects::StampingPress15
    },
    {
        eFoundryGameObjects::StampingPress16,
        eFoundryGameObjects::StampingPress12,
        eFoundryGameObjects::StampingPress13,
        eFoundryGameObjects::StampingPress14,
        eFoundryGameObjects::StampingPress10
    },
    {
        eFoundryGameObjects::StampingPress11,
        eFoundryGameObjects::StampingPress07,
        eFoundryGameObjects::StampingPress08,
        eFoundryGameObjects::StampingPress09,
        eFoundryGameObjects::StampingPress05
    },
    {
        eFoundryGameObjects::StampingPress06,
        eFoundryGameObjects::StampingPress01,
        eFoundryGameObjects::StampingPress02,
        eFoundryGameObjects::StampingPress03,
        eFoundryGameObjects::StampingPress04
    }
};

StampingPressPattern const g_FourthPattern[5] =
{
    {
        eFoundryGameObjects::StampingPress08,
        eFoundryGameObjects::StampingPress02,
        eFoundryGameObjects::StampingPress04
    },
    {
        eFoundryGameObjects::StampingPress13,
        eFoundryGameObjects::StampingPress07,
        eFoundryGameObjects::StampingPress09,
        eFoundryGameObjects::StampingPress01,
        eFoundryGameObjects::StampingPress05
    },
    {
        eFoundryGameObjects::StampingPress18,
        eFoundryGameObjects::StampingPress12,
        eFoundryGameObjects::StampingPress14,
        eFoundryGameObjects::StampingPress06,
        eFoundryGameObjects::StampingPress10
    },
    {
        eFoundryGameObjects::StampingPress17,
        eFoundryGameObjects::StampingPress19,
        eFoundryGameObjects::StampingPress11,
        eFoundryGameObjects::StampingPress15
    },
    {
        eFoundryGameObjects::StampingPress16,
        eFoundryGameObjects::StampingPress20,
        eFoundryGameObjects::StampingPress03
    }
};

StampingPressPattern const g_FifthPattern[3] =
{
    {
        eFoundryGameObjects::StampingPress18,
        eFoundryGameObjects::StampingPress13,
        eFoundryGameObjects::StampingPress08,
        eFoundryGameObjects::StampingPress03
    },
    {
        eFoundryGameObjects::StampingPress19,
        eFoundryGameObjects::StampingPress20,
        eFoundryGameObjects::StampingPress14,
        eFoundryGameObjects::StampingPress15,
        eFoundryGameObjects::StampingPress06,
        eFoundryGameObjects::StampingPress07,
        eFoundryGameObjects::StampingPress01,
        eFoundryGameObjects::StampingPress02
    },
    {
        eFoundryGameObjects::StampingPress16,
        eFoundryGameObjects::StampingPress17,
        eFoundryGameObjects::StampingPress11,
        eFoundryGameObjects::StampingPress12,
        eFoundryGameObjects::StampingPress09,
        eFoundryGameObjects::StampingPress10,
        eFoundryGameObjects::StampingPress04,
        eFoundryGameObjects::StampingPress05
    }
};

StampingPressPattern const g_SixthPattern[2] =
{
    {
        eFoundryGameObjects::StampingPress16,
        eFoundryGameObjects::StampingPress18,
        eFoundryGameObjects::StampingPress20,
        eFoundryGameObjects::StampingPress12,
        eFoundryGameObjects::StampingPress14,
        eFoundryGameObjects::StampingPress06,
        eFoundryGameObjects::StampingPress08,
        eFoundryGameObjects::StampingPress10,
        eFoundryGameObjects::StampingPress02,
        eFoundryGameObjects::StampingPress04
    },
    {
        eFoundryGameObjects::StampingPress17,
        eFoundryGameObjects::StampingPress19,
        eFoundryGameObjects::StampingPress11,
        eFoundryGameObjects::StampingPress13,
        eFoundryGameObjects::StampingPress15,
        eFoundryGameObjects::StampingPress07,
        eFoundryGameObjects::StampingPress09,
        eFoundryGameObjects::StampingPress01,
        eFoundryGameObjects::StampingPress03,
        eFoundryGameObjects::StampingPress05
    }
};

StampingPressPattern const g_SeventhPattern[5] =
{
    {
        eFoundryGameObjects::StampingPress18,
        eFoundryGameObjects::StampingPress01,
        eFoundryGameObjects::StampingPress05
    },
    {
        eFoundryGameObjects::StampingPress17,
        eFoundryGameObjects::StampingPress19,
        eFoundryGameObjects::StampingPress13
    },
    {
        eFoundryGameObjects::StampingPress16,
        eFoundryGameObjects::StampingPress20,
        eFoundryGameObjects::StampingPress12,
        eFoundryGameObjects::StampingPress14,
        eFoundryGameObjects::StampingPress08
    },
    {
        eFoundryGameObjects::StampingPress11,
        eFoundryGameObjects::StampingPress15,
        eFoundryGameObjects::StampingPress07,
        eFoundryGameObjects::StampingPress09,
        eFoundryGameObjects::StampingPress03
    },
    {
        eFoundryGameObjects::StampingPress06,
        eFoundryGameObjects::StampingPress10,
        eFoundryGameObjects::StampingPress02,
        eFoundryGameObjects::StampingPress04
    }
};

/// Activation order
std::vector<StampingPressPattern> const g_PatternActivation[5] =
{
    {
        g_FirstPattern,
        g_SecondPattern,
        g_ThirdPattern[0],
        g_ThirdPattern[1],
        g_ThirdPattern[2],
        g_ThirdPattern[3],
        g_FirstPattern,
        g_SecondPattern
    },
    {
        g_FourthPattern[0],
        g_FourthPattern[1],
        g_FourthPattern[2],
        g_FourthPattern[3],
        g_FourthPattern[4],
        g_FourthPattern[0],
        g_FourthPattern[1],
        g_FourthPattern[2],
        g_FourthPattern[3],
        g_FourthPattern[4]
    },
    {
        g_FifthPattern[0],
        g_FifthPattern[1],
        g_FifthPattern[2],
        g_FifthPattern[0],
        g_FifthPattern[1],
        g_FifthPattern[2],
        g_FifthPattern[0]
    },
    {
        g_SixthPattern[0],
        g_SixthPattern[1],
        g_SixthPattern[0],
        g_SixthPattern[1]
    },
    {
        g_SeventhPattern[0],
        g_SeventhPattern[1],
        g_SeventhPattern[2],
        g_SeventhPattern[3],
        g_SeventhPattern[4]
    }
};
////////////////////////////////////////////////////////////////////////////////

void RespawnBrothers(Creature* p_Source, InstanceScript* p_Instance)
{
    if (p_Source == nullptr || p_Instance == nullptr)
        return;

    if (Creature* l_Other = ObjectAccessor::GetCreature(*p_Source, p_Instance->GetGuidData((p_Source->GetEntry() == eFoundryCreatures::BossFranzok) ? eFoundryCreatures::BossHansgar : eFoundryCreatures::BossFranzok)))
    {
        l_Other->Respawn();
        l_Other->GetMotionMaster()->MoveTargetedHome();
    }

  //  p_Instance->DoCombatStopOnPlayers();
}

void StartBrothers(Creature* p_Source, Unit* p_Target, InstanceScript* p_Instance)
{
    if (p_Source == nullptr || p_Target == nullptr || p_Instance == nullptr)
        return;

    uint32 l_Entry = (p_Source->GetEntry() == eFoundryCreatures::BossFranzok) ? eFoundryCreatures::BossHansgar : eFoundryCreatures::BossFranzok;
    if (Creature* l_Other = ObjectAccessor::GetCreature(*p_Source, p_Instance->GetGuidData(l_Entry)))
    {
        if (l_Other->IsAIEnabled)
            l_Other->AI()->AttackStart(p_Target);
    }
}

Creature* GetBrother(Creature* p_Source, InstanceScript* p_Instance)
{
    if (p_Source == nullptr || p_Instance == nullptr)
        return nullptr;

    uint32 l_Entry = (p_Source->GetEntry() == eFoundryCreatures::BossFranzok) ? eFoundryCreatures::BossHansgar : eFoundryCreatures::BossFranzok;
    if (Creature* l_Other = ObjectAccessor::GetCreature(*p_Source, p_Instance->GetGuidData(l_Entry)))
        return l_Other;

    return nullptr;
}

/// This class is used to activate Stamping Press
class StampingPressActivation : public BasicEvent
{
    public:
        StampingPressActivation(ObjectGuid p_Guid, uint32 p_AnimID, bool p_Maintain) : BasicEvent(), m_Guid(p_Guid), m_AnimID(p_AnimID), m_Maintain(p_Maintain) { }
        virtual ~StampingPressActivation() { }

        virtual bool Execute(uint64 /*p_EndTime*/, uint32 /*p_Time*/)
        {
            if (GameObject* l_GameObject = HashMapHolder<GameObject>::Find(m_Guid))
            {
              //  l_GameObject->SendGameObjectActivateAnimKit(m_AnimID, m_Maintain);

                /// Register AnimKitID to send it in UpdateObject
              //  l_GameObject->SetAIAnimKitId(m_AnimID, false);
            }

            return true;
        }

        virtual void Abort(uint64 /*p_EndTime*/) { }

    private:
        ObjectGuid m_Guid;
        uint32 m_AnimID;
        bool m_Maintain;
};

enum eStates
{
    BothInArena1,
    HansgarOut1,
    BothInArena2,
    FranzokOut,
    BothInArena3,
    HansgarOut2,
    BothInArenaFinal,
    MaxSwitchStates
};

enum eDatas
{
    DataMainTankHealth,
    DataOffTankHealth,  ///< ExplicitTarget of Crippling Suplex
    DataMaxTankHealths,
    DataStampTimer,

    /// Misc
    MaxStampingPresses      = 20,
    MaxConveyorBelts        = 5,
    MaxPatternActivation    = 5,
    DataBeltEntry           = 0,
    DataSpawnTimer          = 1
};

enum eCreatures
{
    MobStampingPresses          = 78358,
    BlackrockForgeSpecialist    = 79200,
    BlackrockEnforcer           = 79208,
    ScorchingBurns              = 78823,
    ForgeOverdrive              = 77258
};

enum eVisuals
{
    AnimStamp1      = 5924,
    AnimStamp2      = 6741,
    AnimStamp3      = 5836,
    BodySlamVisual  = 38379
};

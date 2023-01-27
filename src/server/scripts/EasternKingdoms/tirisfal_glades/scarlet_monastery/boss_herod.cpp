/*
 *
 */

#include "scriptPCH.h"

#define SAY_AGGRO                   -1189000
#define SAY_WHIRLWIND               -1189001
#define SAY_ENRAGE                  -1189002
#define SAY_KILL                    -1189003
#define EMOTE_ENRAGE                -1189004

#define SAY_TRAINEE_SPAWN           -1189022

#define SPELL_RUSHINGCHARGE         8260
#define SPELL_CLEAVE                15496
#define SPELL_WHIRLWIND             8989
#define SPELL_FRENZY                8269

enum
{
    NPC_SCARLET_MYRMIDON            = 4295,
    NPC_SCARLET_TRAINEE             = 6575,

    GO_HEROD_DOOR                   = 101854
};

struct Coords
{
    float x, y, z, o;
};

const Coords MyrmidonSpawn = { 1926.03f, -370.61f, 18.0f, 0.05f };
const Coords RoomCenter    = { 1965.09f, -431.61f, 6.79f, 0.0f };

struct boss_herodAI : ScriptedAI
{
    explicit boss_herodAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        boss_herodAI::Reset();
    }

    bool Enrage;
    bool TraineeSay;
    bool m_bWhirlwind;
    bool bMyrmidonsSpawned;
    uint8 NbTrainee;
    uint32 RushingCharge_Timer;
    uint32 Cleave_Timer;
    uint32 Whirlwind_Timer;
    uint32 m_uiRootTimer;
    uint32 uiRoomCheck;
    std::list<ObjectGuid> m_lMyrmidonGuids;

    void Reset() override
    {
        Enrage = false;
        TraineeSay = false;
        m_bWhirlwind = false;
        NbTrainee = 0;
        RushingCharge_Timer = 1500;
        Cleave_Timer = 12000;
        Whirlwind_Timer = urand(10000, 20000);
        m_uiRootTimer = 0;
        uiRoomCheck = 500;
        bMyrmidonsSpawned = false;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        SpawnMyrmidons();
        DoScriptText(SAY_AGGRO, m_creature);
        DoCastSpellIfCan(m_creature, SPELL_RUSHINGCHARGE);
    }

    void KilledUnit(Unit* /*pVictim*/) override
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_SCARLET_TRAINEE)
        {
            if (!TraineeSay)
            {
                DoScriptText(SAY_TRAINEE_SPAWN, pSummoned);
                TraineeSay = true;
            }

            if (NbTrainee < 10)
                pSummoned->GetMotionMaster()->MovePoint(0, 1940.257080f, -434.454315f, 17.094456f);
            else
                pSummoned->GetMotionMaster()->MovePoint(100, 1940.508301f, -428.826080f, 17.095098f);

            NbTrainee++; 
            return;
        }

        pSummoned->SetNoXP();
        m_lMyrmidonGuids.push_back(pSummoned->GetObjectGuid());
    }

    void EngageMyrmidons(Unit* victim)
    {
        if (!victim)
            return;

        for (const auto& guid : m_lMyrmidonGuids)
        {
            if (auto pMyrmidon = m_creature->GetMap()->GetCreature(guid))
            {
                if (!pMyrmidon->IsAlive() || pMyrmidon->GetVictim())
                    continue;
                if (victim->IsAlive())
                    pMyrmidon->SetInCombatWith(victim);
            }
        }
    }

    void SpawnMyrmidons()
    {
        bMyrmidonsSpawned = true;
        for (uint8 i = 0; i < 4; ++i)
        {
            m_creature->SummonCreature(NPC_SCARLET_MYRMIDON,
                MyrmidonSpawn.x + frand(-3.0, 3.0),
                MyrmidonSpawn.y + frand(-3.0, 3.0),
                MyrmidonSpawn.z,
                MyrmidonSpawn.o, TEMPSUMMON_DEAD_DESPAWN, 20000);
        }
    }

    void DespawnMyrmidons()
    {
        for (const auto& guid : m_lMyrmidonGuids)
        {
            if (auto pMyrmidon = m_creature->GetMap()->GetCreature(guid))
            {
                if (pMyrmidon->IsAlive() && !pMyrmidon->GetVictim())
                    pMyrmidon->ForcedDespawn();
            }
        }

        bMyrmidonsSpawned = false;
        m_lMyrmidonGuids.clear();
    }

    void EnterEvadeMode() override
    {
        m_creature->ClearUnitState(UNIT_STAT_ROOT);
        DespawnMyrmidons();
        ScriptedAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        DespawnMyrmidons();
        for (uint8 i = 0; i < 20; ++i)
            m_creature->SummonCreature(NPC_SCARLET_TRAINEE,
                                    1939.18f, -431.58f, 17.09f, 6.22f,
                                    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 180000);

        if (auto pDoor = m_creature->FindNearestGameObject(GO_HEROD_DOOR, 100.0f))
        {
            if (pDoor->GetGoState() != GO_STATE_ACTIVE)
                pDoor->UseDoorOrButton();
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // check if the target is still inside the room
        if (bMyrmidonsSpawned && uiRoomCheck <= diff)
        {
            if (!m_creature->IsWithinDist2d(RoomCenter.x, RoomCenter.y, 32.0f))
            {
                EngageMyrmidons(me->GetVictim());
            }
            uiRoomCheck = 500;
        }
        else uiRoomCheck -= diff;

        if (m_bWhirlwind)
        {
            if (m_uiRootTimer < diff)
            {
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
                m_bWhirlwind = false;
            }
            else
            {
                m_uiRootTimer -= diff;
                return;
            }
        }

        //If we are <50% hp goes Enraged
        if (!Enrage && m_creature->GetHealthPercent() <= 50.0f && !m_creature->IsNonMeleeSpellCasted(false))
        {
            if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_ENRAGE, m_creature);
                DoScriptText(SAY_ENRAGE, m_creature);
                Enrage = true;
            }
        }

        // Rushing Charge
        if (RushingCharge_Timer < diff)
        {
            auto pVictim = m_creature->GetVictim();

            if (pVictim && !pVictim->IsInRange(m_creature, 0.0f, MELEE_RANGE + 10.0f))
            {
                if (DoCastSpellIfCan(m_creature, SPELL_RUSHINGCHARGE) == CAST_OK)
                    RushingCharge_Timer = 4500;
            }
        }
        else
            RushingCharge_Timer -= diff;

        // Cleave
        if (Cleave_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                Cleave_Timer = 12000;
        }
        else
            Cleave_Timer -= diff;

        // Whirlwind
        if (Whirlwind_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WHIRLWIND) == CAST_OK)
            {
                m_creature->AddUnitState(UNIT_STAT_ROOT);
                m_bWhirlwind = true;
                m_uiRootTimer = 11000;
                DoScriptText(SAY_WHIRLWIND, m_creature);
                Whirlwind_Timer = urand(20000, 30000);
            }
        }
        else
            Whirlwind_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_herod(Creature* pCreature)
{
    return new boss_herodAI(pCreature);
}

struct mob_scarlet_traineeAI : ScriptedAI
{
    explicit mob_scarlet_traineeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Start_Timer = urand(1000, 6000);
        group1 = false;
        group2 = false;
        mob_scarlet_traineeAI::Reset();
    }

    uint32 Start_Timer;
    bool group1;
    bool group2;

    void Reset() override { }

    void UpdateAI(uint32 const diff) override
    {
        if (Start_Timer)
        {
            if (Start_Timer <= diff)
            {
                m_creature->SetSpeedRate(MOVE_WALK, 2.20f);

                if (group1)
                    m_creature->GetMotionMaster()->MovePoint(1, 1946.433594f, -435.955109f, 16.367277f);
                else if (group2)
                    m_creature->GetMotionMaster()->MovePoint(101, 1940.257080f, -434.454315f, 17.094456f);

                Start_Timer = 0;
            }
            else
                Start_Timer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void MovementInform(uint32 MovementType, uint32 id) override
    {
        if (MovementType == POINT_MOTION_TYPE)
        {
            switch (id)
            {
                case 0:
                    group1 = true;
                    break;
                case 100:
                    group2 = true;
                    break;
                case 1:
                    m_creature->GetMotionMaster()->MovePoint(2, 1952.834717f, -447.514130f, 13.804327f);
                    break;
                case 101:
                    m_creature->GetMotionMaster()->MovePoint(102, 1953.056763f, -416.109863f, 13.861217f);
                    break;
                case 2:
                    m_creature->GetMotionMaster()->MovePoint(3, 1965.592041f, -451.153778f, 11.272284f);
                    break;
                case 102:
                    m_creature->GetMotionMaster()->MovePoint(103, 1965.369629f, -412.147949f, 11.272387f);
                    break;
                case 3:
                    m_creature->GetMotionMaster()->MovePoint(4, 1982.692749f, -441.514343f, 11.272284f);
                    break;
                case 103:
                    m_creature->GetMotionMaster()->MovePoint(104, 1980.908081f, -421.008026f, 11.272387f);
                    break;
                case 4:
                    m_creature->GetMotionMaster()->MovePoint(5, 1978.061890f, -428.549500f, 11.272232f);
                    break;
                case 104:
                    m_creature->GetMotionMaster()->MovePoint(105, 1979.139038f, -434.856934f, 11.272370f);
                    break;
                case 5:
                    m_creature->GetMotionMaster()->MovePoint(6, 1971.447144f, -419.629272f, 8.087179f);
                    break;
                case 105:
                    m_creature->GetMotionMaster()->MovePoint(106, 1972.044800f, -442.568573f, 8.434578f);
                    break;
                case 6:
                    m_creature->GetMotionMaster()->MovePoint(7, 1964.354004f, -418.632904f, 6.177466f);
                    break;
                case 106:
                    m_creature->GetMotionMaster()->MovePoint(107, 1964.691162f, -444.223022f, 6.177622f);
                    break;
                case 7:
                case 107:
                    m_creature->GetMotionMaster()->MovePoint(116, 1965.039795f, -431.733856f, 6.177539f);
                    break;
            }
        }
    }
};

CreatureAI* GetAI_mob_scarlet_trainee(Creature* pCreature)
{
    return new mob_scarlet_traineeAI(pCreature);
}

/*
 *
 */

struct go_herod_leverAI : GameObjectAI
{
    explicit go_herod_leverAI(GameObject* pGo) : GameObjectAI(pGo)
    {

    }

    bool OnUse(Unit* /*pCaster*/) override
    {
        if (auto pDoor = me->FindNearestGameObject(GO_HEROD_DOOR, 40.0f))
        {
             if (pDoor->getLootState() == GO_READY || pDoor->getLootState() == GO_JUST_DEACTIVATED)
                 pDoor->UseDoorOrButton();
             else
                 pDoor->ResetDoorOrButton();
        }

        return true;
    }
};

GameObjectAI* GetAI_go_herod_lever(GameObject* pGo)
{
    return new go_herod_leverAI(pGo);
}

void AddSC_boss_herod()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_herod";
    newscript->GetAI = &GetAI_boss_herod;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_scarlet_trainee";
    newscript->GetAI = &GetAI_mob_scarlet_trainee;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_herod_lever";
    newscript->GOGetAI = &GetAI_go_herod_lever;
    newscript->RegisterSelf();
}

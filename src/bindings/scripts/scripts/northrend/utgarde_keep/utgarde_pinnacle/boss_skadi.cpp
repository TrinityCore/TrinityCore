/* Script Data Start
SDName: Boss skadi
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_skadi' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "utgarde_pinnacle.h"

//Phase 0 "gauntlet even" Skadi on a flying mount, waves of adds charging to the group periodicaly carrying harpoons
//Phase 1 Kill the Skadi drake mount with harppons launcher
//Phase 2 Kill the Skadi

//Skadi Spells
#define SPELL_CRUSH                              50234
#define H_SPELL_CRUSH                            59330
#define SPELL_POISONED_SPEAR                     50225
#define H_SPELL_POISONED_SPEAR                   59331
#define SPELL_WHIRLWIND                          50228 //random target,  but not the tank approx. every 20s
#define H_SPELL_WHIRLWIND                        59332

//Spawned creatures
#define CREATURE_YMIRJAR_WARRIOR                 26690
#define CREATURE_YMIRJAR_WITCH_DOCTOR            26691
#define CREATURE_YMIRJAR_HARPOONER               26692

#define DATA_MOUNT                               27043

//not in db
//Yell
#define SAY_AGGRO                             -1575004
#define SAY_KILL_1                            -1575005
#define SAY_KILL_2                            -1575006
#define SAY_KILL_3                            -1575007
#define SAY_DEATH                             -1575008
#define SAY_DRAKE_DEATH                       -1575009
#define SAY_DRAKE_HIT_1                       -1575010
#define SAY_DRAKE_HIT_2                       -1575011
#define SAY_DRAKE_BREATH_1                    -1575012
#define SAY_DRAKE_BREATH_2                    -1575013
#define SAY_DRAKE_BREATH_3                    -1575014

//Spawn locations
struct Locations
{
    float x, y, z;
    uint32 id;
};

static Locations SpawnLoc[]=
{
    {340.556, -511.493, 104.352},
    {367.741, -512.865, 104.828},
    {399.546, -512.755, 104.834},
    {430.551, -514.320, 105.055},
    {468.931, -513.555, 104.723}
};

enum CombatPhase
{
    FLYING,
    SKADI
};

struct TRINITY_DLL_DECL boss_skadiAI : public ScriptedAI
{
    boss_skadiAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiCrushTimer;
    uint32 uiPoisonedSpearTimer;
    uint32 uiWhirlwindTimer;
    uint32 uiMovementTimer;
    uint32 uiWaypointId;
    uint32 uiSpawnCounter;

    CombatPhase Phase;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiCrushTimer = 8000;
        uiPoisonedSpearTimer = 10000;
        uiWhirlwindTimer = 20000;
        uiSpawnCounter = 0;

        uiWaypointId = 0;

        Phase = SKADI;

        m_creature->Unmount();
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        if (pInstance)
            pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        m_creature->Mount(DATA_MOUNT);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->GetMotionMaster()->MovePoint(uiWaypointId, 340.259, -510.541, 120.869);

        Phase = FLYING;

        if (pInstance)
            pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        switch(Phase)
        {
            case FLYING:
                if (uiMovementTimer < diff)
                {
                    switch(uiWaypointId)
                    {
                        case 0: m_creature->GetMotionMaster()->MovePoint(uiWaypointId, 340.259, -510.541, 120.869); break;
                        case 1: m_creature->GetMotionMaster()->MovePoint(uiWaypointId, 472.977, -513.636, 120.869); break;
                        case 200:
                            m_creature->GetMotionMaster()->Clear();
                            m_creature->Unmount();
                            Phase = SKADI;
                            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                                AttackStart(pTarget);
                            break;
                    }
                } else uiMovementTimer -= diff;
                break;
            case SKADI:
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (uiCrushTimer < diff)
                {
                    DoCast(m_creature->getVictim(), HEROIC(SPELL_CRUSH, H_SPELL_CRUSH));
                    uiCrushTimer = 8000;
                } else uiCrushTimer -= diff;

                if (uiPoisonedSpearTimer < diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                        DoCast(pTarget, HEROIC(SPELL_POISONED_SPEAR, H_SPELL_POISONED_SPEAR));
                    uiPoisonedSpearTimer = 10000;
                } else uiPoisonedSpearTimer -= diff;

                if (uiWhirlwindTimer < diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                        m_creature->CastSpell(pTarget, HEROIC(SPELL_WHIRLWIND, H_SPELL_WHIRLWIND), false);
                } else uiWhirlwindTimer = 20000;

                DoMeleeAttackIfReady();
                break;
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2,SAY_KILL_3), m_creature);
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
                return;

        if (HeroicMode ? (uiSpawnCounter >= 4) : (uiSpawnCounter >= 5))
        {
            uiWaypointId = 200;
            uiMovementTimer = 3000;
        }
        else
        {
            switch(id)
            {
                case 0:
                    SpawnMobs(uiSpawnCounter);
                    uiWaypointId = 1;
                    ++uiSpawnCounter;
                    uiMovementTimer = 3000;
                    break;
                case 1:
                    SpawnMobs(uiSpawnCounter);
                    uiWaypointId = 0;
                    ++uiSpawnCounter;
                    uiMovementTimer = 3000;
                    break;
            }
        }
    }

    void SpawnMobs(uint32 spot)
    {
        uint8 uiMaxSpawn = (HeroicMode ? 6 : 5);
        for (uint8 i = 0; i < uiMaxSpawn; ++i)
        {
            Creature* pTemp;
            switch (rand()%3)
            {
                case 0: pTemp = m_creature->SummonCreature(CREATURE_YMIRJAR_WARRIOR, SpawnLoc[spot].x+rand()%5, SpawnLoc[spot].y+rand()%5, SpawnLoc[spot].z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                case 1: pTemp = m_creature->SummonCreature(CREATURE_YMIRJAR_WITCH_DOCTOR, SpawnLoc[spot].x+rand()%5, SpawnLoc[spot].y+rand()%5, SpawnLoc[spot].z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                case 2: pTemp = m_creature->SummonCreature(CREATURE_YMIRJAR_HARPOONER, SpawnLoc[spot].x+rand()%5, SpawnLoc[spot].y+rand()%5, SpawnLoc[spot].z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
            }
            if (pTemp)
            {
                pTemp->SetInCombatWithZone();
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    pTemp->AI()->AttackStart(pTarget);
            }
        }
    }
};

CreatureAI* GetAI_boss_skadi(Creature* pCreature)
{
    return new boss_skadiAI (pCreature);
}

void AddSC_boss_skadi()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_skadi";
    newscript->GetAI = &GetAI_boss_skadi;
    newscript->RegisterSelf();
}

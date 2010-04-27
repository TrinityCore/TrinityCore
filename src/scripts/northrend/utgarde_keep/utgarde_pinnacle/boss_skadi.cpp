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
#include "ScriptedPch.h"
#include "utgarde_pinnacle.h"

//Phase 0 "gauntlet even" Skadi on a flying mount, waves of adds charging to the group periodicaly carrying harpoons
//Phase 1 Kill the Skadi drake mount with harppons launcher
//Phase 2 Kill the Skadi

//Skadi Spells
#define SPELL_CRUSH                              50234
#define H_SPELL_CRUSH                            59330
#define SPELL_POISONED_SPEAR                     50225
#define H_SPELL_POISONED_SPEAR                   59331
#define SPELL_WHIRLWIND                          50228 //random target, but not the tank approx. every 20s
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

enum
{
    ACHIEV_TIMED_START_EVENT                      = 17726,
};

struct boss_skadiAI : public ScriptedAI
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

        me->Unmount();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        if (pInstance)
        {
            pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, NOT_STARTED);
            pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

        me->Mount(DATA_MOUNT);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->MovePoint(uiWaypointId, 340.259, -510.541, 120.869);

        Phase = FLYING;

        if (pInstance)
        {
            pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, IN_PROGRESS);
            pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        switch(Phase)
        {
            case FLYING:
                if (uiMovementTimer <= diff)
                {
                    switch(uiWaypointId)
                    {
                        case 0: me->GetMotionMaster()->MovePoint(uiWaypointId, 340.259, -510.541, 120.869); break;
                        case 1: me->GetMotionMaster()->MovePoint(uiWaypointId, 472.977, -513.636, 120.869); break;
                        case 200:
                            me->GetMotionMaster()->Clear();
                            me->Unmount();
                            Phase = SKADI;
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                AttackStart(pTarget);
                            break;
                    }
                } else uiMovementTimer -= diff;
                break;
            case SKADI:
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (uiCrushTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CRUSH);
                    uiCrushTimer = 8000;
                } else uiCrushTimer -= diff;

                if (uiPoisonedSpearTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, SPELL_POISONED_SPEAR);
                    uiPoisonedSpearTimer = 10000;
                } else uiPoisonedSpearTimer -= diff;

                if (uiWhirlwindTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        me->CastSpell(pTarget, DUNGEON_MODE(SPELL_WHIRLWIND, H_SPELL_WHIRLWIND), false);
                } else uiWhirlwindTimer = 20000;

                DoMeleeAttackIfReady();
                break;
        }
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
            pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, DONE);
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2,SAY_KILL_3), me);
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
                return;

        if (uiSpawnCounter >= DUNGEON_MODE(4, 5))
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
        uint8 uiMaxSpawn = DUNGEON_MODE(5, 6);
        for (uint8 i = 0; i < uiMaxSpawn; ++i)
        {
            Creature* pTemp = NULL;
            switch (urand(0,2))
            {
                case 0: pTemp = me->SummonCreature(CREATURE_YMIRJAR_WARRIOR, SpawnLoc[spot].x+rand()%5, SpawnLoc[spot].y+rand()%5, SpawnLoc[spot].z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                case 1: pTemp = me->SummonCreature(CREATURE_YMIRJAR_WITCH_DOCTOR, SpawnLoc[spot].x+rand()%5, SpawnLoc[spot].y+rand()%5, SpawnLoc[spot].z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                case 2: pTemp = me->SummonCreature(CREATURE_YMIRJAR_HARPOONER, SpawnLoc[spot].x+rand()%5, SpawnLoc[spot].y+rand()%5, SpawnLoc[spot].z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
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

/* Script Data Start
SDName: Boss slad_ran
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_slad_ran' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_gundrak.h"

//Spells
enum Spells
{
    SPELL_POISON_NOVA                           = 55081,
    H_SPELL_POISON_NOVA                         = 59842,
    SPELL_POWERFULL_BITE                        = 48287,
    H_SPELL_POWERFULL_BITE                      = 59840,
    SPELL_VENOM_BOLT                            = 54970,
    H_SPELL_VENOM_BOLT                          = 59839
};

//Yell
enum Yells
{
    SAY_AGGRO                                 = -1604017,
    SAY_SLAY_1                                = -1604018,
    SAY_SLAY_2                                = -1604019,
    SAY_SLAY_3                                = -1604020,
    SAY_DEATH                                 = -1604021,
    SAY_SUMMON_SNAKES                         = -1604022,
    SAY_SUMMON_CONSTRICTORS                   = -1604023
};

//Creatures
enum Creatures
{
    CREATURE_SNAKE                            = 29680,
    CREATURE_CONSTRICTORS                     = 29713
};

//Creatures' spells
enum ConstrictorSpells
{
    SPELL_GRIP_OF_SLAD_RAN                    = 55093,
    SPELL_VENOMOUS_BITE                       = 54987,
    H_SPELL_VENOMOUS_BITE                     = 58996
};

// Spawning locations
struct Locations
{
    float x, y, z, orientation;
};

static Locations SpawnLoc[]=
{
  {1783.81, 646.637, 133.948, 3.71755},
  {1775.03, 606.586, 134.165, 1.43117},
  {1717.39, 630.041, 129.282, 5.96903},
  {1765.66, 646.542, 134.02,  5.11381},
  {1716.76, 635.159, 129.282, 0.191986}
};

struct TRINITY_DLL_DECL boss_slad_ranAI : public ScriptedAI
{
    boss_slad_ranAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiPoisonNovaTimer;
    uint32 uiPowerfullBiteTimer;
    uint32 uiVenomBoltTimer;
    uint32 uiSpawnTimer;

    uint8 uiPhase;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiPoisonNovaTimer = 10000;
        uiPowerfullBiteTimer = 3000;
        uiVenomBoltTimer = 15000;
        uiSpawnTimer = 5000;
        uiPhase = 0;

        if (pInstance)
            pInstance->SetData(DATA_SLAD_RAN_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_SLAD_RAN_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiPoisonNovaTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_POISON_NOVA, H_SPELL_POISON_NOVA));
            uiPoisonNovaTimer = 15000;
        } else uiPoisonNovaTimer -= diff;

        if (uiPowerfullBiteTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_POWERFULL_BITE, H_SPELL_POWERFULL_BITE));
            uiPowerfullBiteTimer = 10000;
        } else uiPowerfullBiteTimer -= diff;

        if (uiVenomBoltTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_VENOM_BOLT, H_SPELL_VENOM_BOLT));
            uiVenomBoltTimer = 10000;
        } else uiVenomBoltTimer -= diff;

        if (uiPhase)
        {
            if(uiSpawnTimer < diff)
            {
                if (uiPhase == 1)
                    for (uint8 i = 0; i < (HeroicMode ? 5 : 3); ++i)
                        m_creature->SummonCreature(CREATURE_SNAKE, SpawnLoc[i].x, SpawnLoc[i].y, SpawnLoc[i].z, SpawnLoc[i].orientation, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
                if (uiPhase == 2)
                    for (uint8 i = 0; i < (HeroicMode ? 5 : 3); ++i)
                        m_creature->SummonCreature(CREATURE_CONSTRICTORS, SpawnLoc[i].x, SpawnLoc[i].y, SpawnLoc[i].z, SpawnLoc[i].orientation, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
                uiSpawnTimer = 5000;
            } else uiSpawnTimer -= diff;
        }

        if ((uiPhase == 0) && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 30)
        {
            DoScriptText(SAY_SUMMON_SNAKES,m_creature);
            uiPhase = 1;
        }
        if ((uiPhase == 1) && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)
        {
            DoScriptText(SAY_SUMMON_CONSTRICTORS,m_creature);
            uiPhase = 2;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_SLAD_RAN_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->GetMotionMaster()->MovePoint(0,m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ());

    }
};

struct TRINITY_DLL_DECL mob_slad_ran_constrictorAI : public ScriptedAI
{
    mob_slad_ran_constrictorAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiGripOfSladRanTimer;

    void Reset()
    {
        uiGripOfSladRanTimer = 1000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        if (uiGripOfSladRanTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_GRIP_OF_SLAD_RAN);
            uiGripOfSladRanTimer = 5000;
        } else uiGripOfSladRanTimer -= diff;;
    }

    ScriptedInstance* pInstance;
};

struct TRINITY_DLL_DECL mob_slad_ran_viperAI : public ScriptedAI
{
    mob_slad_ran_viperAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiVenomousBiteTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiVenomousBiteTimer = 2000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiVenomousBiteTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_VENOMOUS_BITE, H_SPELL_VENOMOUS_BITE));
            uiVenomousBiteTimer = 10000;
        } else uiVenomousBiteTimer -= diff;
    }
};

CreatureAI* GetAI_boss_slad_ran(Creature* pCreature)
{
    return new boss_slad_ranAI (pCreature);
}

CreatureAI* GetAI_mob_slad_ran_constrictor(Creature* pCreature)
{
    return new mob_slad_ran_constrictorAI (pCreature);
}

CreatureAI* GetAI_mob_slad_ran_viper(Creature* pCreature)
{
    return new mob_slad_ran_viperAI (pCreature);
}

void AddSC_boss_slad_ran()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_slad_ran";
    newscript->GetAI = &GetAI_boss_slad_ran;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_slad_ran_constrictor";
    newscript->GetAI = &GetAI_mob_slad_ran_constrictor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_slad_ran_viper";
    newscript->GetAI = &GetAI_mob_slad_ran_viper;
    newscript->RegisterSelf();
}

/* Script Data Start
SDName: Boss tharon_ja
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_tharon_ja' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_COURSE_OF_LIFE                          = 49527,
    SPELL_DECAY_FLESH                             = 49356, //casted at end of pahase 1, starts phase 2
    SPELL_EYE_BEAM                                = 49544,
    SPELL_LIGHTNING_BREATH                        = 49537,
    SPELL_POISON_CLOUD                            = 49548,
    SPELL_RAIN_OF_FIRE                            = 49518,
    SPELL_RETURN_FLESH                            = 53463, //Channeled spell ending phase two and returning to phase 1. This ability will stun the party for 6 seconds.
    SPELL_SHADOW_VOLLEY                           = 49528,
//Spells Heroic
    H_SPELL_COURSE_OF_LIFE                        = 59972,
    H_SPELL_EYE_BEAM                              = 59965,
    H_SPELL_LIGHTNING_BREATH                      = 59963,
    H_SPELL_POISON_CLOUD                          = 59969,
    H_SPELL_RAIN_OF_FIRE                          = 59971,
    H_SPELL_SHADOW_VOLLEY                         = 59973
};
enum PlayerSkills
{
//Players skills durring Phase2
    PLAYER_PHASE2_SLAYING_STRIKE                  = 50799,
    PLAYER_PHASE2_TAUNT                           = 49613,
    PLAYER_PHASE2_BONE_ARMOR                      = 49609,
    PLAYER_PHASE2_TOUCH_OF_LIFE                   = 49617
};
//Phase 1 all abilities except Eye beam
//Phase 2 turns players to skeletons with new abilities, boss grows skin

//not in db
enum Yells
{
    SAY_AGGRO                                   = -1600011,
    SAY_KILL_1                                  = -1600012,
    SAY_KILL_2                                  = -1600013,
    SAY_FLESH_1                                 = -1600014,
    SAY_FLESH_2                                 = -1600015,
    SAY_SKELETON_1                              = -1600016,
    SAY_SKELETON_2                              = -1600017,
    SAY_DEATH                                   = -1600018
};

struct TRINITY_DLL_DECL boss_tharon_jaAI : public ScriptedAI
{
    boss_tharon_jaAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_THARON_JA_EVENT, NOT_STARTED);
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_THARON_JA_EVENT, IN_PROGRESS);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2),m_creature);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH,m_creature);

        if (pInstance)
            pInstance->SetData(DATA_THARON_JA_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_tharon_ja(Creature* pCreature)
{
    return new boss_tharon_jaAI (pCreature);
}

void AddSC_boss_tharon_ja()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_tharon_ja";
    newscript->GetAI = &GetAI_boss_tharon_ja;
    newscript->RegisterSelf();
}

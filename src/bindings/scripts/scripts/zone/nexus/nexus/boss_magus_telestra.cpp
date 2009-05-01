/* Script Data Start
SDName: Boss magus_telestra
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_nexus.h"


//Spells

//phase 1
#define SPELL_ICE_NOVA          47772
#define SPELL_ICE_NOVA          56935
#define SPELL_FIREBOMB          47773
#define SPELL_FIREBOMB          56934
#define SPELL_GAVITY_WELL       47756

//Phase 2      -->50% HP (3 clones, Frost, Fire, Arcane)
//Frost Magus (npc 26930)
#define FROST_MAGUS_VISUAL      47706 //Dummy
#define SPELL_BLIZZARD_N        47727
#define SPELL_ICE_BARB_N        47729
//heroic
#define SPELL_BLIZZARD_H        56936
#define SPELL_ICE_BARB_H        56937

//Fire Magus (npc 26928)
#define FIRE_MAGUS_VISUAL       47705 //Dummy
#define SPELL_FIRE_BLAST        47721
#define SPELL_SCORCH            47723
//heroic
#define SPELL_FIRE_BLAST_H      56939
#define SPELL_SCORCH_H          56938

//Arcane Magus (npc 26929)
#define ARCANE_MAGUS_VISUAL     47704 //Dummy
#define SPELL_CRITTER           47731
#define SPELL_TIME_STOP         47736

//Yell
#define SAY_AGGRO             -1576010
#define SAY_KILL              -1576011
#define SAY_DEATH             -1576012
#define SAY_MERGE             -1576013
#define SAY_SPLIT_1           -1576014
#define SAY_SPLIT_2           -1576015


struct TRINITY_DLL_DECL boss_magus_telestraAI : public ScriptedAI
{
    boss_magus_telestraAI(Creature *c) : ScriptedAI(c) {}

    bool splited;
    uint64 Magus_frost,
           Magus_fire,
           Magus_arcane;

    void Reset()
    {
        splited = false;
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        if(!splited)
        {
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 50)
            {
                DoScriptText(SAY_SPLIT_1, m_creature);
                //HandleSplit
                splited = true;
            }
        }

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_magus_telestra(Creature *_Creature)
{
    return new boss_magus_telestraAI (_Creature);
}

void AddSC_boss_magus_telestra()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_magus_telestra";
    newscript->GetAI = &GetAI_boss_magus_telestra;
    newscript->RegisterSelf();
}

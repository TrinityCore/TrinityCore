/* Script Data Start
SDName: Boss archavon
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells Archavon
#define SPELL_ROCK_SHARDS                            60883 //Instant -- Hurls a jagged rock shard, inflicting 707 to 793 Physical damage to any enemies within 5 of the target.
#define SPELL_CRUSHING_LEAP                          60895 //Instant (10-80yr range) -- Leaps at an enemy, inflicting 8000 Physical damage, knocking all nearby enemies away, and creating a cloud of choking debris.
#define SPELL_CHOKING_CLOUD                          61672 //Leaving behind CRUSHING_LEAP --> Slams into the ground, kicking up an asphyxiating cloud of debris, inflicting 2828 to 3172 Nature damage per second to all enemies caught within and reducing their chance to hit by 50%.
//#define SPELL_STOMP         //48131  or  55292   or   60880
#define SPELL_IMPALE                                 60882 //Lifts an enemy off the ground with a spiked fist, inflicting 47125 to 52875 Physical damage and 9425 to 10575 additional damage each second for 8 sec.

//Spells Archavon Warders
#define SPELL_ROCK_SHOWER_N                          60919
#define SPELL_ROCK_SHOWER_H                          60923
#define SPELL_SHIELD_CRUSH_N                         60897
#define SPELL_SHIELD_CRUSH_H                         60899
#define SPELL_WHIRL_N                                60902
#define SPELL_WHIRL_H                                60916

//4 Warders spawned
#define ARCHAVON_WARDER                              32353 //npc 32353

//Yell
#define SAY_LEAP "Archavon the Stone Watcher lunges for $N!" //$N should be the target

struct TRINITY_DLL_DECL boss_archavonAI : public ScriptedAI
{
    boss_archavonAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit* who)  {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

/*######
##  Mob Archavon Warder
######*/
struct TRINITY_DLL_DECL mob_warderAI : public ScriptedAI //npc 32353
{
    mob_warderAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_warder(Creature *_Creature)
{
    return new mob_warderAI (_Creature);
}

CreatureAI* GetAI_boss_archavon(Creature *_Creature)
{
    return new boss_archavonAI (_Creature);
}

void AddSC_boss_archavon()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_archavon";
    newscript->GetAI = &GetAI_boss_archavon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_archavon_warder";
    newscript->GetAI = &GetAI_mob_warder;
    newscript->RegisterSelf();
}

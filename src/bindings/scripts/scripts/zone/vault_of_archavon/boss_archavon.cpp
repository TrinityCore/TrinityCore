/*** SQL START ***
UPDATE `creature_template` SET `ScriptName`='boss_archavon' WHERE `entry`='31125';
UPDATE `creature_template` SET `ScriptName`='mob_archavon_warder' WHERE `entry`='32353';
*** SQL END ***/
#include "precompiled.h"

//These are patchwerk's yell
#define SAY_AGGRO1              -1533017
#define SAY_AGGRO2              -1533018
#define SAY_SLAY                -1533019
#define SAY_DEATH               -1533020

#define EMOTE_BERSERK           -1533021
#define EMOTE_ENRAGE            -1533022

//Spells Archavon
#define SPELL_ROCK_SHARDS                           58678
#define SPELL_CRUSHING_LEAP                         HEROIC(58960,60894)//Instant (10-80yr range) -- Leaps at an enemy, inflicting 8000 Physical damage, knocking all nearby enemies away, and creating a cloud of choking debris.
#define SPELL_STOMP                                 HEROIC(58663,60880)
#define SPELL_IMPALE                                HEROIC(58666,60882) //Lifts an enemy off the ground with a spiked fist, inflicting 47125 to 52875 Physical damage and 9425 to 10575 additional damage each second for 8 sec.
#define SPELL_BERSERK								47008
//Spells Archavon Warders                      
#define SPELL_ROCK_SHOWER                           HEROIC(60919,60923)                                   
#define SPELL_SHIELD_CRUSH							HEROIC(60897,60899)                          
#define SPELL_WHIRL									HEROIC(60902,60916)

//4 Warders spawned
#define ARCHAVON_WARDER                             32353 //npc 32353

//Yell
#define SAY_LEAP "Archavon the Stone Watcher lunges for $N!" //$N should be the target

#define EVENT_ROCK_SHARDS		 1  //15s cd
#define EVENT_CHOKING_CLOUD		 2  //30s cd
#define EVENT_STOMP              3  //45s cd
#define EVENT_BERSERK            4  //300s cd 

//mob
#define EVENT_ROCK_SHOWER		 5  //set = 20s cd,unkown cd
#define EVENT_SHIELD_CRUSH		 6  //set = 30s cd
#define EVENT_WHIRL	             8  //set= 10s cd

struct TRINITY_DLL_DECL boss_archavonAI : public ScriptedAI
{
    boss_archavonAI(Creature *c) : ScriptedAI(c) {}

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void KilledUnit(Unit* Victim)
    {
        if(!(rand()%5))
            DoScriptText(SAY_SLAY, me);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, me);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(rand()%2 ? SAY_AGGRO1 : SAY_AGGRO2, me);
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_ROCK_SHARDS, 15000);
        events.ScheduleEvent(EVENT_CHOKING_CLOUD, 30000);
        events.ScheduleEvent(EVENT_STOMP, 45000);
        events.ScheduleEvent(EVENT_BERSERK, 300000);
    }


    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        events.Update(diff);

        if(me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_ROCK_SHARDS:
                {
                    if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ROCK_SHARDS);
                    events.ScheduleEvent(EVENT_ROCK_SHARDS, 15000);
                    return;
                }
                case EVENT_CHOKING_CLOUD:
                {
                    if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CRUSHING_LEAP, true); //10y~80y, ignore range
                    events.ScheduleEvent(EVENT_CHOKING_CLOUD, 30000);
                    return;
                }
                case EVENT_STOMP:
                {
                    DoCast(me->getVictim(), SPELL_STOMP, true);
                    DoCast(me->getVictim(), SPELL_IMPALE);
                    events.ScheduleEvent(EVENT_STOMP, 45000);
                    return;
                }
                case EVENT_BERSERK:
                {
                    DoCast(m_creature, SPELL_BERSERK);
                    DoScriptText(EMOTE_BERSERK, m_creature);  
                    return;
                }
            }
        }

        DoMeleeAttackIfReady();
    }
};

/*######
##  Mob Archavon Warder
######*/
struct TRINITY_DLL_DECL mob_warderAI : public ScriptedAI //npc 32353
{
    mob_warderAI(Creature *c) : ScriptedAI(c) {}

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_ROCK_SHOWER, 2000);
        events.ScheduleEvent(EVENT_SHIELD_CRUSH, 20000);
        events.ScheduleEvent(EVENT_WHIRL, 7500);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_ROCK_SHOWER:
                {
                    if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ROCK_SHOWER);
                    events.ScheduleEvent(EVENT_ROCK_SHARDS, 6000);
                    return;
                }
                case EVENT_SHIELD_CRUSH:
                DoCast(m_creature->getVictim(), SPELL_SHIELD_CRUSH);
                events.ScheduleEvent(EVENT_SHIELD_CRUSH, 20000);
                return;
                case EVENT_WHIRL:
                DoCast(m_creature->getVictim(), SPELL_WHIRL);
                events.ScheduleEvent(EVENT_WHIRL, 8000);
                return;
            }
        }
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

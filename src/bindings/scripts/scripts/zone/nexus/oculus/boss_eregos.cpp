/* Script Data Start
SDName: Boss eregos
SDAuthor: LordVanMartin
SD%Complete:
SDComment:  Encounter is done entirely on drake vehicles
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Types of drake mounts: Ruby(Tank),  Amber(DPS),  Emerald(Healer)
//Two Repeating phases

//Spells
#define SPELL_ARCANE_BARRAGE                       50804
#define SPELL_ARCANE_VOLLEY                        51153
#define SPELL_ENRAGED_ASSAULT                      51170
#define SPELL_PLANAR_ANOMALIES                     57959
#define SPELL_PLANAR_SHIFT                         51162

//Heroic
#define SPELL_ARCANE_BARRAGE_H                     59381
#define SPELL_ARCANE_VOLLEY_H                      59382

/*Ruby Drake ,
(npc 27756) (item 37860)
(summoned by spell Ruby Essence = 37860 ---> Call Amber Drake == 49462 ---> Summon 27756)
*/
#define NPC_RUBY_DRAKE_VEHICLE                     27756
#define SPELL_RIDE_RUBY_DRAKE_QUE                  49463          //Apply Aura: Periodic Trigger, Interval: 3 seconds ---> 49464
#define SPELL_RUBY_DRAKE_SADDLE                    49464          //Allows you to ride on the back of an Amber Drake. ---> Dummy

#define SPELL_RUBY_SEARING_WRATH                   50232          //(60 yds) - Instant - Breathes a stream of fire at an enemy dragon, dealing 6800 to 9200 Fire damage and then jumping to additional dragons within 30 yards. Each jump increases the damage by 50%. Affects up to 5 total targets
#define SPELL_RUBY_EVASIVE_AURA                    50248          //Instant - Allows the Ruby Drake to generate Evasive Charges when hit by hostile attacks and spells.
#define SPELL_RUBY_EVASIVE_MANEUVERS               50240          //Instant - 5 sec. cooldown - Allows your drake to dodge all incoming attacks and spells. Requires Evasive Charges to use. Each attack or spell dodged while this ability is active burns one Evasive Charge. Lasts 30 sec. or until all charges are exhausted.
//you do not have acces to until you kill Mage-Lord Urom
#define SPELL_RUBY_MARTYR                          50253          //Instant - 10 sec. cooldown - Redirect all harmful spells cast at friendly drakes to yourself for 10 sec.

/*Amber Drake,
(npc 27755)  (item 37859)
(summoned by spell Amber Essence = 37859 ---> Call Amber Drake == 49461 ---> Summon 27755)
*/
#define NPC_AMBER_DRAKE_VEHICLE                    27755
#define SPELL_RIDE_AMBER_DRAKE_QUE                 49459          //Apply Aura: Periodic Trigger, Interval: 3 seconds ---> 49460
#define SPELL_AMBER_DRAKE_SADDLE                   49460          //Allows you to ride on the back of an Amber Drake. ---> Dummy

#define SPELL_AMBER_SHOCK_LANCE                    49840         //(60 yds) - Instant - Deals 4822 to 5602 Arcane damage and detonates all Shock Charges on an enemy dragon. Damage is increased by 6525 for each detonated.
#define SPELL_AMBER_STOP_TIME                                    //Instant - 1 min cooldown - Halts the passage of time, freezing all enemy dragons in place for 10 sec. This attack applies 5 Shock Charges to each affected target.
//you do not have access to until you kill the  Mage-Lord Urom.
#define SPELL_AMBER_TEMPORAL_RIFT                  49592         //(60 yds) - Channeled - Channels a temporal rift on an enemy dragon for 10 sec. While trapped in the rift, all damage done to the target is increased by 100%. In addition, for every 15,000 damage done to a target affected by Temporal Rift, 1 Shock Charge is generated.

/*Emerald Drake,
(npc 27692)  (item 37815),
 (summoned by spell Emerald Essence = 37815 ---> Call Emerald Drake == 49345 ---> Summon 27692)
*/
#define NPC_EMERALD_DRAKE_VEHICLE                  27692
#define SPELL_RIDE_EMERALD_DRAKE_QUE               49427         //Apply Aura: Periodic Trigger, Interval: 3 seconds ---> 49346
#define SPELL_EMERALD_DRAKE_SADDLE                 49346         //Allows you to ride on the back of an Amber Drake. ---> Dummy

#define SPELL_EMERALD_LEECHING_POISON              50328         //(60 yds) - Instant - Poisons the enemy dragon, leeching 1300 to the caster every 2 sec. for 12 sec. Stacks up to 3 times.
#define SPELL_EMERALD_TOUCH_THE_NIGHTMARE          50341         //(60 yds) - Instant - Consumes 30% of the caster's max health to inflict 25,000 nature damage to an enemy dragon and reduce the damage it deals by 25% for 30 sec.
// you do not have access to until you kill the Mage-Lord Urom
#define SPELL_EMERALD_DREAM_FUNNEL                 50344         //(60 yds) - Channeled - Transfers 5% of the caster's max health to a friendly drake every second for 10 seconds as long as the caster channels.

struct TRINITY_DLL_DECL boss_eregosAI : public ScriptedAI
{
    boss_eregosAI(Creature *c) : ScriptedAI(c) {}

    uint32 phase;

    void Reset() {}
    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        phase =1;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)  {}
};

CreatureAI* GetAI_boss_eregos(Creature *_Creature)
{
    return new boss_eregosAI (_Creature);
}

void AddSC_boss_eregos()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_eregos";
    newscript->GetAI = &GetAI_boss_eregos;
    newscript->RegisterSelf();
}

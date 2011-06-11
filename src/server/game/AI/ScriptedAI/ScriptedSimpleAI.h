/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_SIMPLEAI_H
#define SC_SIMPLEAI_H

enum CastTarget
{
    CAST_SELF = 0,                  //Self cast
    CAST_HOSTILE_TARGET,            //Our current target (ie: highest aggro)
    CAST_HOSTILE_SECOND_AGGRO,      //Second highest aggro (generaly used for cleaves and some special attacks)
    CAST_HOSTILE_LAST_AGGRO,        //Dead last on aggro (no idea what this could be used for)
    CAST_HOSTILE_RANDOM,            //Just any random target on our threat list
    CAST_FRIENDLY_RANDOM,           //NOT YET IMPLEMENTED

    //Special cases
    CAST_KILLEDUNIT_VICTIM,         //Only works within KilledUnit function
    CAST_JUSTDIED_KILLER,           //Only works within JustDied function
};

#define MAX_SIMPLEAI_SPELLS 10

struct SimpleAI : public ScriptedAI
{
    SimpleAI(Creature *c);// : ScriptedAI(c);

    void Reset();

    void EnterCombat(Unit* /*who*/);

    void KilledUnit(Unit* /*victim*/);

    void DamageTaken(Unit *killer, uint32 &damage);

    void UpdateAI(const uint32 diff);

public:

    int32 Aggro_TextId[3];
    uint32 Aggro_Sound[3];

    int32 Death_TextId[3];
    uint32 Death_Sound[3];
    uint32 Death_Spell;
    uint32 Death_Target_Type;

    int32 Kill_TextId[3];
    uint32 Kill_Sound[3];
    uint32 Kill_Spell;
    uint32 Kill_Target_Type;

    struct SimpleAI_Spell
    {
        uint32 Spell_Id;                //Spell ID to cast
        int32 First_Cast;               //Delay for first cast
        uint32 Cooldown;                //Cooldown between casts
        uint32 CooldownRandomAddition;  //Random addition to cooldown (in range from 0 - CooldownRandomAddition)
        uint32 Cast_Target_Type;        //Target type (note that certain spells may ignore this)
        bool InterruptPreviousCast;     //Interrupt a previous cast if this spell needs to be cast
        bool Enabled;                   //Spell enabled or disabled (default: false)

        //3 texts to many?
        int32 TextId[3];
        uint32 Text_Sound[3];
    }Spell[MAX_SIMPLEAI_SPELLS];

protected:
    uint32 Spell_Timer[MAX_SIMPLEAI_SPELLS];
};

#endif


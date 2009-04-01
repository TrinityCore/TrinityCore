/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_GUARDAI_H
#define SC_GUARDAI_H

#define GENERIC_CREATURE_COOLDOWN 5000

struct TRINITY_DLL_DECL guardAI : public ScriptedAI
{
    guardAI(Creature *c) : ScriptedAI(c) {}

    uint32 GlobalCooldown;                                  //This variable acts like the global cooldown that players have (1.5 seconds)
    uint32 BuffTimer;                                       //This variable keeps track of buffs

    void Reset();

    void Aggro(Unit *who);

    void JustDied(Unit *Killer);

    void UpdateAI(const uint32 diff);
};
#endif


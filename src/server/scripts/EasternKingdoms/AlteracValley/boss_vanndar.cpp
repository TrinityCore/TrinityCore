/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"

enum Yells
{
    YELL_AGGRO                                    = -1810008,
    YELL_EVADE                                    = -1810009,
    YELL_RESPAWN1                                 = -1810010,
    YELL_RESPAWN2                                 = -1810011,
    YELL_RANDOM1                                  = -1810012,
    YELL_RANDOM2                                  = -1810013,
    YELL_RANDOM3                                  = -1810014,
    YELL_RANDOM4                                  = -1810015,
    YELL_RANDOM5                                  = -1810016,
    YELL_RANDOM6                                  = -1810017,
    YELL_RANDOM7                                  = -1810018
};

enum Spells
{
    SPELL_AVATAR                                  = 19135,
    SPELL_THUNDERCLAP                             = 15588,
    SPELL_STORMBOLT                               = 20685 // not sure
};

struct boss_vanndarAI : public ScriptedAI
{
       boss_vanndarAI(Creature *c) : ScriptedAI(c) {}


    uint32 uiAvatarTimer;
    uint32 uiThunderclapTimer;
    uint32 uiStormboltTimer;
    uint32 uiResetTimer;
    uint32 uiYellTimer;


    void Reset()
    {
        uiAvatarTimer = 3*IN_MILLISECONDS;
        uiThunderclapTimer = 4*IN_MILLISECONDS;
        uiStormboltTimer = 6*IN_MILLISECONDS;
        uiResetTimer = 5*IN_MILLISECONDS;
        uiYellTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS);
    }

    void Aggro(Unit * /*who*/)
    {
        DoScriptText(YELL_AGGRO, me);
    }

    void JustRespawned()
    {
        Reset();
        DoScriptText(RAND(YELL_RESPAWN1,YELL_RESPAWN2), me);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiAvatarTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_AVATAR);
            uiAvatarTimer =  urand(15*IN_MILLISECONDS,20*IN_MILLISECONDS);
        } else uiAvatarTimer -= diff;

        if (uiThunderclapTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_THUNDERCLAP);
            uiThunderclapTimer = urand(5*IN_MILLISECONDS,15*IN_MILLISECONDS);
        } else uiThunderclapTimer -= diff;

        if (uiStormboltTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_STORMBOLT);
            uiStormboltTimer = urand(10*IN_MILLISECONDS,25*IN_MILLISECONDS);
        } else uiStormboltTimer -= diff;

        if (uiYellTimer <= diff)
        {
            DoScriptText(RAND(YELL_RANDOM1,YELL_RANDOM2,YELL_RANDOM3,YELL_RANDOM4,YELL_RANDOM5,YELL_RANDOM6,YELL_RANDOM7), me);
            uiYellTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS); //20 to 30 seconds
        } else uiYellTimer -= diff;

        // check if creature is not outside of building
        if (uiResetTimer <= diff)
        {
            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
            {
                EnterEvadeMode();
                DoScriptText(YELL_EVADE, me);
            }
            uiResetTimer = 5*IN_MILLISECONDS;
        } else uiResetTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_vanndar(Creature *_Creature)
{
    return new boss_vanndarAI (_Creature);
}

void AddSC_boss_vanndar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_vanndar";
    newscript->GetAI = &GetAI_boss_vanndar;
    newscript->RegisterSelf();
}
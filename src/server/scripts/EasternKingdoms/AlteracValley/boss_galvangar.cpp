/* Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "ScriptPCH.h"

enum Spells
{
    SPELL_CLEAVE                                  = 15284,
    SPELL_FRIGHTENING_SHOUT                       = 19134,
    SPELL_WHIRLWIND1                              = 15589,
    SPELL_WHIRLWIND2                              = 13736,
    SPELL_MORTAL_STRIKE                           = 16856
};

enum Yells
{
    YELL_AGGRO                                    = -1810021,
    YELL_EVADE                                    = -1810022
};

struct boss_galvangarAI : public ScriptedAI
{
    boss_galvangarAI(Creature *c) : ScriptedAI(c) {}


    uint32 uiCleaveTimer;
    uint32 uiFrighteningShoutTimer;
    uint32 uiWhirlwind1Timer;
    uint32 uiWhirlwind2Timer;
    uint32 uiMortalStrikeTimer;
    uint32 uiResetTimer;


    void Reset()
    {
        uiCleaveTimer                     = urand(1*IN_MILISECONDS,9*IN_MILISECONDS);
        uiFrighteningShoutTimer           = urand(2*IN_MILISECONDS,19*IN_MILISECONDS);
        uiWhirlwind1Timer                 = urand(1*IN_MILISECONDS,13*IN_MILISECONDS);
        uiWhirlwind2Timer                 = urand(5*IN_MILISECONDS,20*IN_MILISECONDS);
        uiMortalStrikeTimer               = urand(5*IN_MILISECONDS,20*IN_MILISECONDS);
        uiResetTimer                      = 5*IN_MILISECONDS;
    }

    void Aggro(Unit * /*who*/)
    {
        DoScriptText(YELL_AGGRO, me);
    }

    void JustRespawned()
    {
        Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiCleaveTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_CLEAVE);
            uiCleaveTimer =  urand(10*IN_MILISECONDS,16*IN_MILISECONDS);
        } else uiCleaveTimer -= diff;

        if (uiFrighteningShoutTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_FRIGHTENING_SHOUT);
            uiFrighteningShoutTimer = urand(10*IN_MILISECONDS,15*IN_MILISECONDS);
        } else uiFrighteningShoutTimer -= diff;

        if (uiWhirlwind1Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_WHIRLWIND1);
            uiWhirlwind1Timer = urand(6*IN_MILISECONDS,10*IN_MILISECONDS);
        } else uiWhirlwind1Timer -= diff;

        if (uiWhirlwind2Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_WHIRLWIND2);
            uiWhirlwind2Timer = urand(10*IN_MILISECONDS,25*IN_MILISECONDS);
        } else uiWhirlwind2Timer -= diff;

        if (uiMortalStrikeTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
            uiMortalStrikeTimer = urand(10*IN_MILISECONDS,30*IN_MILISECONDS);
        } else uiMortalStrikeTimer -= diff;

        // check if creature is not outside of building
        if (uiResetTimer <= diff)
        {
            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
            {
                EnterEvadeMode();
                DoScriptText(YELL_EVADE, me);
            }
            uiResetTimer = 5*IN_MILISECONDS;
        } else uiResetTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_galvangar(Creature *_Creature)
{
    return new boss_galvangarAI (_Creature);
}

void AddSC_boss_galvangar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_galvangar";
    newscript->GetAI = &GetAI_boss_galvangar;
    newscript->RegisterSelf();
}

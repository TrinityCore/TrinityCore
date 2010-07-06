/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Doomlord_Kazzak
SD%Complete: 70
SDComment: Using incorrect spell for Mark of Kazzak
SDCategory: Hellfire Peninsula
EndScriptData */

#include "ScriptPCH.h"

#define SAY_INTRO                       -1000147
#define SAY_AGGRO1                      -1000148
#define SAY_AGGRO2                      -1000149
#define SAY_SURPREME1                   -1000154
#define SAY_SURPREME2                   -1000149
#define SAY_KILL1                       -1000150
#define SAY_KILL2                       -1000151
#define SAY_KILL3                       -1000152
#define SAY_DEATH                       -1000155
#define EMOTE_FRENZY                    -1000151
#define SAY_RAND1                       -1000158
#define SAY_RAND2                       -1000157

#define SPELL_SHADOWVOLLEY              32963
#define SPELL_CLEAVE                    31779
#define SPELL_THUNDERCLAP               36706
#define SPELL_VOIDBOLT                  39329
#define SPELL_MARKOFKAZZAK              32960
#define SPELL_ENRAGE                    32964
#define SPELL_CAPTURESOUL               32966
#define SPELL_TWISTEDREFLECTION         21063

struct boss_doomlordkazzakAI : public ScriptedAI
{
    boss_doomlordkazzakAI(Creature *c) : ScriptedAI(c) {}

    uint32 ShadowVolley_Timer;
    uint32 Cleave_Timer;
    uint32 ThunderClap_Timer;
    uint32 VoidBolt_Timer;
    uint32 MarkOfKazzak_Timer;
    uint32 Enrage_Timer;
    uint32 Twisted_Reflection_Timer;

    void Reset()
    {
        ShadowVolley_Timer = 6000 + rand()%4000;
        Cleave_Timer = 7000;
        ThunderClap_Timer = 14000 + rand()%4000;
        VoidBolt_Timer = 30000;
        MarkOfKazzak_Timer = 25000;
        Enrage_Timer = 60000;
        Twisted_Reflection_Timer = 33000;                   // Timer may be incorrect
    }

    void JustRespawned()
    {
        DoScriptText(SAY_INTRO, me);
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(RAND(SAY_AGGRO1,SAY_AGGRO2), me);
    }

    void KilledUnit(Unit* victim)
    {
        // When Kazzak kills a player (not pets/totems), he regens some health
         if (victim->GetTypeId() != TYPEID_PLAYER)
             return;

            DoCast(me, SPELL_CAPTURESOUL);

            DoScriptText(RAND(SAY_KILL1,SAY_KILL2,SAY_KILL3), me);
    }

    void JustDied(Unit * /*victim*/)
    {
        DoScriptText(SAY_DEATH, me);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //ShadowVolley_Timer
        if (ShadowVolley_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_SHADOWVOLLEY);
            ShadowVolley_Timer = 4000 + rand()%2000;
        } else ShadowVolley_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_CLEAVE);
            Cleave_Timer = 8000 + rand()%4000;
        } else Cleave_Timer -= diff;

        //ThunderClap_Timer
        if (ThunderClap_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_THUNDERCLAP);
            ThunderClap_Timer = 10000 + rand()%4000;
        } else ThunderClap_Timer -= diff;

        //VoidBolt_Timer
        if (VoidBolt_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_VOIDBOLT);
            VoidBolt_Timer = 15000 + rand()%3000;
        } else VoidBolt_Timer -= diff;

        //MarkOfKazzak_Timer
        if (MarkOfKazzak_Timer <= diff)
        {
            Unit* victim = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (victim->GetPower(POWER_MANA))
            {
                DoCast(victim, SPELL_MARKOFKAZZAK);
                MarkOfKazzak_Timer = 20000;
            }
        } else MarkOfKazzak_Timer -= diff;

        //Enrage_Timer
        if (Enrage_Timer <= diff)
        {
            DoScriptText(EMOTE_FRENZY, me);
            DoCast(me, SPELL_ENRAGE);
            Enrage_Timer = 30000;
        } else Enrage_Timer -= diff;

        if (Twisted_Reflection_Timer <= diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_TWISTEDREFLECTION);
            Twisted_Reflection_Timer = 15000;
        } else Twisted_Reflection_Timer -= diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_doomlordkazzak(Creature* pCreature)
{
    return new boss_doomlordkazzakAI (pCreature);
}

void AddSC_boss_doomlordkazzak()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_doomlord_kazzak";
    newscript->GetAI = &GetAI_boss_doomlordkazzak;
    newscript->RegisterSelf();
}


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
SDName: Boss_Doomwalker
SD%Complete: 100
SDComment:
SDCategory: Shadowmoon Valley
EndScriptData */

#include "ScriptPCH.h"

#define SAY_AGGRO                   -1000159
#define SAY_EARTHQUAKE_1            -1000160
#define SAY_EARTHQUAKE_2            -1000161
#define SAY_OVERRUN_1               -1000162
#define SAY_OVERRUN_2               -1000163
#define SAY_SLAY_1                  -1000164
#define SAY_SLAY_2                  -1000165
#define SAY_SLAY_3                  -1000166
#define SAY_DEATH                   -1000167

#define SPELL_EARTHQUAKE            32686
#define SPELL_SUNDER_ARMOR          33661
#define SPELL_CHAIN_LIGHTNING       33665
#define SPELL_OVERRUN               32636
#define SPELL_ENRAGE                33653
#define SPELL_MARK_DEATH            37128
#define SPELL_AURA_DEATH            37131

struct boss_doomwalkerAI : public ScriptedAI
{
    boss_doomwalkerAI(Creature *c) : ScriptedAI(c) {}

    uint32 Chain_Timer;
    uint32 Enrage_Timer;
    uint32 Overrun_Timer;
    uint32 Quake_Timer;
    uint32 Armor_Timer;

    bool InEnrage;

    void Reset()
    {
        Enrage_Timer    = 0;
        Armor_Timer     = 5000 + rand()%8000;
        Chain_Timer     = 10000 + rand()%20000;
        Quake_Timer     = 25000 + rand()%10000;
        Overrun_Timer   = 30000 + rand()%15000;

        InEnrage = false;
    }

    void KilledUnit(Unit* Victim)
    {
        Victim->CastSpell(Victim,SPELL_MARK_DEATH,0);

        if (rand()%5)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
    }

    void JustDied(Unit* /*Killer*/)
    {
        DoScriptText(SAY_DEATH, me);
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsHostileTo(who))
        {
            if (who->HasAura(SPELL_MARK_DEATH,0))
            {
                who->CastSpell(who,SPELL_AURA_DEATH,1);
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Spell Enrage, when hp <= 20% gain enrage
        if (((me->GetHealth()*100)/ me->GetMaxHealth()) <= 20)
        {
            if (Enrage_Timer <= diff)
            {
                DoCast(me, SPELL_ENRAGE);
                Enrage_Timer = 6000;
                InEnrage = true;
            } else Enrage_Timer -= diff;
        }

        //Spell Overrun
        if (Overrun_Timer <= diff)
        {
            DoScriptText(RAND(SAY_OVERRUN_1,SAY_OVERRUN_2), me);

            DoCast(me->getVictim(), SPELL_OVERRUN);
            Overrun_Timer = 25000 + rand()%15000;
        } else Overrun_Timer -= diff;

        //Spell Earthquake
        if (Quake_Timer <= diff)
        {
            if (rand()%2)
                return;

            DoScriptText(RAND(SAY_EARTHQUAKE_1,SAY_EARTHQUAKE_2), me);

            //remove enrage before casting earthquake because enrage + earthquake = 16000dmg over 8sec and all dead
            if (InEnrage)
                me->RemoveAura(SPELL_ENRAGE);

            DoCast(me, SPELL_EARTHQUAKE);
            Quake_Timer = 30000 + rand()%25000;
        } else Quake_Timer -= diff;

        //Spell Chain Lightning
        if (Chain_Timer <= diff)
        {
            Unit *pTarget = NULL;
            pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);

            if (!pTarget)
                pTarget = me->getVictim();

            if (pTarget)
                DoCast(pTarget, SPELL_CHAIN_LIGHTNING);

            Chain_Timer = 7000 + rand()%20000;
        } else Chain_Timer -= diff;

        //Spell Sunder Armor
        if (Armor_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_SUNDER_ARMOR);
            Armor_Timer = 10000 + rand()%15000;
        } else Armor_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_doomwalker(Creature* pCreature)
{
    return new boss_doomwalkerAI (pCreature);
}

void AddSC_boss_doomwalker()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_doomwalker";
    newscript->GetAI = &GetAI_boss_doomwalker;
    newscript->RegisterSelf();
}


/* Copyright (C) 2006 - 2009 kb_z
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Duskwood
SD%Complete: 100
SDComment: Quest Support:8735
SDCategory: Duskwood
EndScriptData */

#include "ScriptedPch.h"

/*######
# at_twilight_grove
######*/

bool AreaTrigger_at_twilight_grove(Player* pPlayer, const AreaTriggerEntry *at)
{
    if (pPlayer->HasQuestForItem(21149))
    {
        if(Unit* TCorrupter = pPlayer->SummonCreature(15625,-10328.16,-489.57,49.95,0,TEMPSUMMON_MANUAL_DESPAWN,60000))
        {
            TCorrupter->setFaction(14);
            TCorrupter->SetMaxHealth(832750);
        }
        if(Unit* CorrupterSpeaker = pPlayer->SummonCreature(1,pPlayer->GetPositionX(),pPlayer->GetPositionY(),pPlayer->GetPositionZ()-1,0,TEMPSUMMON_TIMED_DESPAWN,15000))
        {
            CorrupterSpeaker->SetName("Twilight Corrupter");
            CorrupterSpeaker->SetVisibility(VISIBILITY_ON);
            CorrupterSpeaker->MonsterYell("Come, $N. See what the Nightmare brings...",0,pPlayer->GetGUID());
        }
    }
    return false;
};

/*######
# boss_twilight_corrupter
######*/

#define SPELL_SOUL_CORRUPTION 25805
#define SPELL_CREATURE_OF_NIGHTMARE 25806
#define SPELL_LEVEL_UP 24312

struct boss_twilight_corrupterAI : public ScriptedAI
{
    boss_twilight_corrupterAI(Creature *c) : ScriptedAI(c) {}

    uint32 SoulCorruption_Timer;
    uint32 CreatureOfNightmare_Timer;
    uint8 KillCount;

    void Reset()
    {
        SoulCorruption_Timer = 15000;
        CreatureOfNightmare_Timer = 30000;
        KillCount = 0;
    }
    void EnterCombat(Unit* who)
    {
        m_creature->MonsterYell("The Nightmare cannot be stopped!",0,m_creature->GetGUID());
    }

    void KilledUnit(Unit* victim)
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            ++KillCount;
            m_creature->MonsterTextEmote("Twilight Corrupter squeezes the last bit of life out of $N and swallows their soul.", victim->GetGUID(),true);

            if (KillCount == 3)
            {
                DoCast(m_creature, SPELL_LEVEL_UP, true);
                KillCount = 0;
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;
        if (SoulCorruption_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SOUL_CORRUPTION);
            SoulCorruption_Timer = rand()%4000+15000; //gotta confirm Timers
        } else SoulCorruption_Timer-=diff;
        if (CreatureOfNightmare_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CREATURE_OF_NIGHTMARE);
            CreatureOfNightmare_Timer = 45000; //gotta confirm Timers
        } else CreatureOfNightmare_Timer-=diff;
        DoMeleeAttackIfReady();
    };
};
CreatureAI* GetAI_boss_twilight_corrupter(Creature* pCreature)
{
    return new boss_twilight_corrupterAI (pCreature);
}

void AddSC_duskwood()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_twilight_corrupter";
    newscript->GetAI = &GetAI_boss_twilight_corrupter;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_twilight_grove";
    newscript->pAreaTrigger = &AreaTrigger_at_twilight_grove;
    newscript->RegisterSelf();
}

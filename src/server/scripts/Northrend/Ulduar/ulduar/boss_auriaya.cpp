/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 *
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

#include "ScriptPCH.h"
#include "ulduar.h"

//boss_auriaya
#define SPELL_TERRIFYING_SCREECH          64386
#define SPELL_SETINEL_BLAST               64679
#define SPELL_SONIC_SCREECH               64422
#define SPELL_SUMMON_SWARMING_GUARDIAN    64397

enum Yells
{
    SAY_AGGRO                                   = -1603050,
    SAY_SLAY_1                                  = -1603051,
    SAY_SLAY_2                                  = -1603052,
    SAY_DEATH                                   = -1603053,
    SAY_BERSERK                                 = -1603054,
};

struct boss_auriaya_AI : public BossAI
{
    boss_auriaya_AI(Creature *pCreature) : BossAI(pCreature, TYPE_AURIAYA)
    {
    }

    uint32 TERRIFYING_SCREECH_Timer;
    uint32 SONIC_SCREECH_Timer;

    void Reset()
    {
        _Reset();
        TERRIFYING_SCREECH_Timer = 180000;
        SONIC_SCREECH_Timer = 30000;
    }

    void EnterCombat(Unit* /*who*/)
    {
        _EnterCombat();
        DoScriptText(SAY_AGGRO,me);
    }

    void KilledUnit(Unit* /*victim*/)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
    }

    void JustDied(Unit * /*victim*/)
    {
        DoScriptText(SAY_DEATH, me);
        _JustDied();
    }

    void MoveInLineOfSight(Unit* /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (TERRIFYING_SCREECH_Timer <= diff)
        {
            DoCast(SPELL_TERRIFYING_SCREECH);
            TERRIFYING_SCREECH_Timer = 180000;
        } else TERRIFYING_SCREECH_Timer -= diff;

        if (SONIC_SCREECH_Timer <= diff)
        {
            DoCastVictim(SPELL_SONIC_SCREECH);
            SONIC_SCREECH_Timer = 30000;
        } else SONIC_SCREECH_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_auriaya(Creature* pCreature)
{
    return new boss_auriaya_AI (pCreature);
}

void AddSC_boss_auriaya()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_auriaya";
    newscript->GetAI = &GetAI_boss_auriaya;
    newscript->RegisterSelf();
}

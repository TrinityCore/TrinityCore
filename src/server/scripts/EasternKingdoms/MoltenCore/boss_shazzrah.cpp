/* Copyright (C) 2006 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Shazzrah
SD%Complete: 75
SDComment: Teleport NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_ARCANEEXPLOSION           19712
#define SPELL_SHAZZRAHCURSE             19713
#define SPELL_DEADENMAGIC               19714
#define SPELL_COUNTERSPELL              19715

struct boss_shazzrahAI : public ScriptedAI
{
    boss_shazzrahAI(Creature *c) : ScriptedAI(c) {}

    uint32 ArcaneExplosion_Timer;
    uint32 ShazzrahCurse_Timer;
    uint32 DeadenMagic_Timer;
    uint32 Countspell_Timer;
    uint32 Blink_Timer;

    void Reset()
    {
        ArcaneExplosion_Timer = 6000;                       //These times are probably wrong
        ShazzrahCurse_Timer = 10000;
        DeadenMagic_Timer = 24000;
        Countspell_Timer = 15000;
        Blink_Timer = 30000;
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //ArcaneExplosion_Timer
        if (ArcaneExplosion_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_ARCANEEXPLOSION);
            ArcaneExplosion_Timer = 5000 + rand()%4000;
        } else ArcaneExplosion_Timer -= diff;

        //ShazzrahCurse_Timer
        if (ShazzrahCurse_Timer <= diff)
        {
            Unit *pTarget = NULL;
            pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (pTarget) DoCast(pTarget, SPELL_SHAZZRAHCURSE);

            ShazzrahCurse_Timer = 25000 + rand()%5000;
        } else ShazzrahCurse_Timer -= diff;

        //DeadenMagic_Timer
        if (DeadenMagic_Timer <= diff)
        {
            DoCast(me, SPELL_DEADENMAGIC);
            DeadenMagic_Timer = 35000;
        } else DeadenMagic_Timer -= diff;

        //Countspell_Timer
        if (Countspell_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_COUNTERSPELL);
            Countspell_Timer = 16000 + rand()%4000;
        } else Countspell_Timer -= diff;

        //Blink_Timer
        if (Blink_Timer <= diff)
        {
            // Teleporting him to a random gamer and casting Arcane Explosion after that.
            // Blink is not working cause of LoS System we need to do this hardcoded.
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0, 100, true))
            {
                DoTeleportTo(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ());
                DoCast(pTarget, SPELL_ARCANEEXPLOSION);
                DoResetThreat();
            }

            Blink_Timer = 45000;
        } else Blink_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_shazzrah(Creature* pCreature)
{
    return new boss_shazzrahAI (pCreature);
}

void AddSC_boss_shazzrah()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_shazzrah";
    newscript->GetAI = &GetAI_boss_shazzrah;
    newscript->RegisterSelf();
}


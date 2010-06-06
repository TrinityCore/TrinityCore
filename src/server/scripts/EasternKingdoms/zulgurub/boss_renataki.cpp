/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Renataki
SD%Complete: 100
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptedPch.h"
#include "zulgurub.h"

#define SPELL_AMBUSH            24337
#define SPELL_THOUSANDBLADES    24649

#define EQUIP_ID_MAIN_HAND      0           //was item display id 31818, but this id does not exist

struct boss_renatakiAI : public ScriptedAI
{
    boss_renatakiAI(Creature *c) : ScriptedAI(c) {}

    uint32 Invisible_Timer;
    uint32 Ambush_Timer;
    uint32 Visible_Timer;
    uint32 Aggro_Timer;
    uint32 ThousandBlades_Timer;

    bool Invisible;
    bool Ambushed;

    void Reset()
    {
        Invisible_Timer = 8000 + rand()%10000;
        Ambush_Timer = 3000;
        Visible_Timer = 4000;
        Aggro_Timer = 15000 + rand()%10000;
        ThousandBlades_Timer = 4000 + rand()%4000;

        Invisible = false;
        Ambushed = false;
    }

    void EnterCombat(Unit * /*who*/)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Invisible_Timer
        if (Invisible_Timer <= diff)
        {
            me->InterruptSpell(CURRENT_GENERIC_SPELL);

            SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
            me->SetDisplayId(11686);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            Invisible = true;

            Invisible_Timer = 15000 + rand()%15000;
        } else Invisible_Timer -= diff;

        if (Invisible)
        {
            if (Ambush_Timer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget)
                {
                    DoTeleportTo(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ());
                    DoCast(pTarget, SPELL_AMBUSH);
                }

                Ambushed = true;
                Ambush_Timer = 3000;
            } else Ambush_Timer -= diff;
        }

        if (Ambushed)
        {
            if (Visible_Timer <= diff)
            {
                me->InterruptSpell(CURRENT_GENERIC_SPELL);

                me->SetDisplayId(15268);
                SetEquipmentSlots(false, EQUIP_ID_MAIN_HAND, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                Invisible = false;

                Visible_Timer = 4000;
            } else Visible_Timer -= diff;
        }

        //Resetting some aggro so he attacks other gamers
        if (!Invisible)
            if (Aggro_Timer <= diff)
        {
            Unit *pTarget = NULL;
            pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);

            if (DoGetThreat(me->getVictim()))
                DoModifyThreatPercent(me->getVictim(),-50);

            if (pTarget)
                AttackStart(pTarget);

            Aggro_Timer = 7000 + rand()%13000;
        } else Aggro_Timer -= diff;

        if (!Invisible)
            if (ThousandBlades_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_THOUSANDBLADES);
            ThousandBlades_Timer = 7000 + rand()%5000;
        } else ThousandBlades_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_renataki(Creature* pCreature)
{
    return new boss_renatakiAI (pCreature);
}

void AddSC_boss_renataki()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_renataki";
    newscript->GetAI = &GetAI_boss_renataki;
    newscript->RegisterSelf();
}


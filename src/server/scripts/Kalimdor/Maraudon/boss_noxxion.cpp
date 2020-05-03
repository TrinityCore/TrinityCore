/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Boss_Noxxion
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptMgr.h"
#include "maraudon.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_TOXICVOLLEY           = 21687,
    SPELL_UPPERCUT              = 22916
};

class boss_noxxion : public CreatureScript
{
public:
    boss_noxxion() : CreatureScript("boss_noxxion") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMaraudonAI<boss_noxxionAI>(creature);
    }

    struct boss_noxxionAI : public ScriptedAI
    {
        boss_noxxionAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            ToxicVolleyTimer = 7000;
            UppercutTimer = 16000;
            AddsTimer = 19000;
            InvisibleTimer = 15000;                            //Too much too low?
            Invisible = false;
        }

        uint32 ToxicVolleyTimer;
        uint32 UppercutTimer;
        uint32 AddsTimer;
        uint32 InvisibleTimer;
        bool Invisible;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void SummonAdds(Unit* victim)
        {
            if (Creature* Add = DoSpawnCreature(13456, float(irand(-7, 7)), float(irand(-7, 7)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 90000))
                Add->AI()->AttackStart(victim);
        }

        void UpdateAI(uint32 diff) override
        {
            if (Invisible && InvisibleTimer <= diff)
            {
                //Become visible again
                me->SetFaction(14);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                //Noxxion model
                me->SetDisplayId(11172);
                Invisible = false;
                //me->m_canMove = true;
            }
            else if (Invisible)
            {
                InvisibleTimer -= diff;
                //Do nothing while invisible
                return;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //ToxicVolleyTimer
            if (ToxicVolleyTimer <= diff)
            {
                DoCastVictim(SPELL_TOXICVOLLEY);
                ToxicVolleyTimer = 9000;
            }
            else ToxicVolleyTimer -= diff;

            //UppercutTimer
            if (UppercutTimer <= diff)
            {
                DoCastVictim(SPELL_UPPERCUT);
                UppercutTimer = 12000;
            }
            else UppercutTimer -= diff;

            //AddsTimer
            if (!Invisible && AddsTimer <= diff)
            {
                //Interrupt any spell casting
                //me->m_canMove = true;
                me->InterruptNonMeleeSpells(false);
                me->SetFaction(35);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                // Invisible Model
                me->SetDisplayId(11686);
                SummonAdds(me->GetVictim());
                SummonAdds(me->GetVictim());
                SummonAdds(me->GetVictim());
                SummonAdds(me->GetVictim());
                SummonAdds(me->GetVictim());
                Invisible = true;
                InvisibleTimer = 15000;

                AddsTimer = 40000;
            }
            else AddsTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_noxxion()
{
    new boss_noxxion();
}

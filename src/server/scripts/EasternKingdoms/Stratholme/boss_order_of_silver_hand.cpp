/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Silver_Hand_Bosses
SD%Complete: 40
SDComment: Basic script to have support for Horde paladin epic mount (quest 9737). All 5 members of Order of the Silver Hand running this script (least for now)
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"
#include "Player.h"

/*#####
# Additional:
# Although this is a working solution, the correct would be in addition to check if Aurius is dead.
# Once player extinguish the eternal flame (cast spell 31497->start event 11206) Aurius should become hostile.
# Once Aurius is defeated, he should be the one summoning the ghosts.
#####*/

enum SH_CreatureIds
{
    SH_GREGOR                   = 17910,
    SH_CATHELA                  = 17911,
    SH_NEMAS                    = 17912,
    SH_AELMAR                   = 17913,
    SH_VICAR                    = 17914,
    SH_QUEST_CREDIT             = 17915
};

enum Spells
{
    SPELL_HOLY_LIGHT            = 25263,
    SPELL_DIVINE_SHIELD         = 13874
};

class boss_silver_hand_bosses : public CreatureScript
{
public:
    boss_silver_hand_bosses() : CreatureScript("boss_silver_hand_bosses") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_silver_hand_bossesAI>(creature);
    }

    struct boss_silver_hand_bossesAI : public ScriptedAI
    {
        boss_silver_hand_bossesAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            HolyLight_Timer = 20000;
            DivineShield_Timer = 20000;
        }

        InstanceScript* instance;

        uint32 HolyLight_Timer;
        uint32 DivineShield_Timer;

        void Reset() override
        {
            Initialize();

            switch (me->GetEntry())
            {
                case SH_AELMAR:
                    instance->SetData(TYPE_SH_AELMAR, 0);
                    break;
                case SH_CATHELA:
                    instance->SetData(TYPE_SH_CATHELA, 0);
                    break;
                case SH_GREGOR:
                    instance->SetData(TYPE_SH_GREGOR, 0);
                    break;
                case SH_NEMAS:
                    instance->SetData(TYPE_SH_NEMAS, 0);
                    break;
                case SH_VICAR:
                    instance->SetData(TYPE_SH_VICAR, 0);
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* killer) override
        {
            switch (me->GetEntry())
            {
                case SH_AELMAR:
                    instance->SetData(TYPE_SH_AELMAR, 2);
                    break;
                case SH_CATHELA:
                    instance->SetData(TYPE_SH_CATHELA, 2);
                    break;
                case SH_GREGOR:
                    instance->SetData(TYPE_SH_GREGOR, 2);
                    break;
                case SH_NEMAS:
                    instance->SetData(TYPE_SH_NEMAS, 2);
                    break;
                case SH_VICAR:
                    instance->SetData(TYPE_SH_VICAR, 2);
                    break;
            }

            if (instance->GetData(TYPE_SH_QUEST))
            {
                if (Player* player = killer->ToPlayer())
                    player->KilledMonsterCredit(SH_QUEST_CREDIT);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (HolyLight_Timer <= diff)
            {
                if (HealthBelowPct(20))
                {
                    DoCast(me, SPELL_HOLY_LIGHT);
                    HolyLight_Timer = 20000;
                }
            } else HolyLight_Timer -= diff;

            if (DivineShield_Timer <= diff)
            {
                if (HealthBelowPct(5))
                {
                    DoCast(me, SPELL_DIVINE_SHIELD);
                    DivineShield_Timer = 40000;
                }
            } else DivineShield_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_order_of_silver_hand()
{
    new boss_silver_hand_bosses();
}

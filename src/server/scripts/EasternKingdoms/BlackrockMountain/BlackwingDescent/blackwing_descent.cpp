/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "blackwing_descent.h"

enum Says
{
    SAY_INTRO_NORMAL = 0,
    SAY_INTRO_HEROIC = 1
};

class mob_nefarian_helper_heroic : public CreatureScript
{
public:
    mob_nefarian_helper_heroic() : CreatureScript("mob_nefarian_helper_heroic") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_nefarian_helper_heroicAI (creature);
    }

    struct mob_nefarian_helper_heroicAI : public ScriptedAI
    {
        mob_nefarian_helper_heroicAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }
    };
};

class mob_nefarian_yeller : public CreatureScript // 49580
{
public:
    mob_nefarian_yeller() : CreatureScript("mob_nefarian_yeller") { }

    struct mob_nefarian_yellerAI : public ScriptedAI
    {
        mob_nefarian_yellerAI(Creature* creature) : ScriptedAI(creature)
        {
            timer = 1000;
            introSaid = false;
            creature->SetReactState(REACT_PASSIVE);
            creature->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            creature->SetDisplayId(32440);
        }

        uint32 timer;
        bool introSaid;

        void UpdateAI(uint32 diff) override
        {
            if (timer <= diff)
            {
                if (Player* target = me->SelectNearestPlayer(20.0f))
                {
                    if (target->GetDistance(me) <= 20.0f && !introSaid)
                    {
                        if(!me->GetMap()->IsHeroic())
                            Talk(SAY_INTRO_NORMAL);
                        else
                            Talk(SAY_INTRO_HEROIC);

                        introSaid = true;

                        me->DespawnOrUnsummon(15000);
                    } else
                        timer = 1000;
                }
                else
                    timer = 1000;

            } else timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_nefarian_yellerAI(creature);
    }
};

void AddSC_blackwing_descent()
{
    new mob_nefarian_helper_heroic();
    new mob_nefarian_yeller();
}

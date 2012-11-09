/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "vortex_pinnacle.h"
#include "ScriptPCH.h"

enum eSpells
{
    SPELL_LIGHTNING_BOLT_NORMAL = 86331,
    SPELL_LIGHTNING_BOLT_HEROIC = 93990,
};

class boss_grand_vizier_ertan : public CreatureScript
{
public:
    boss_grand_vizier_ertan() : CreatureScript("boss_grand_vizier_ertan") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_grand_vizier_ertanAI (creature);
    }

    struct boss_grand_vizier_ertanAI : public ScriptedAI
    {
        boss_grand_vizier_ertanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 LightningBoltTimer;

        void Reset()
        {
            LightningBoltTimer = 7000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void JustDied(Unit* /*Killer*/)
        {
            instance->SetData(DATA_GRAND_VIZIER_ERTAN, DONE);

            Creature * Slipstream = me->SummonCreature(NPC_SLIPSTREAM, -775.51f, -70.93f, 640.31f, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            Slipstream->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                    player->ModifyCurrency(395, DUNGEON_MODE(3000, 7000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (LightningBoltTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    me->CastSpell(target, DUNGEON_MODE(SPELL_LIGHTNING_BOLT_NORMAL, SPELL_LIGHTNING_BOLT_HEROIC), true);

                LightningBoltTimer = urand(5*IN_MILLISECONDS, 7*IN_MILLISECONDS);
            } else LightningBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_grand_vizier_ertan()
{
    new boss_grand_vizier_ertan();
}
/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldTB.h"
#include "DB2Stores.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptSystem.h"
#include "SpellScript.h"
#include "WorldSession.h"

enum TBSpiritGuide
{
    SPELL_CHANNEL_SPIRIT_HEAL = 22011,

    GOSSIP_OPTION_ID_SLAGWORKS = 0,
    GOSSIP_OPTION_ID_IRONCLAD_GARRISON = 1,
    GOSSIP_OPTION_ID_WARDENS_VIGIL = 2,
    GOSSIP_OPTION_ID_EAST_SPIRE = 3,
    GOSSIP_OPTION_ID_WEST_SPIRE = 4,
    GOSSIP_OPTION_ID_SOUTH_SPIRE = 5,
};

class npc_tb_spirit_guide : public CreatureScript
{
    public:
        npc_tb_spirit_guide() : CreatureScript("npc_tb_spirit_guide") { }

        struct npc_tb_spirit_guideAI : public ScriptedAI
        {
            npc_tb_spirit_guideAI(Creature* creature) : ScriptedAI(creature) { }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoCast(me, SPELL_CHANNEL_SPIRIT_HEAL);
            }

            void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                player->PlayerTalkClass->SendCloseGossip();

                uint32 areaId = 0;
                switch (gossipListId)
                {
                    case GOSSIP_OPTION_ID_SLAGWORKS:
                        areaId = TB_GY_SLAGWORKS;
                        break;
                    case GOSSIP_OPTION_ID_IRONCLAD_GARRISON:
                        areaId = TB_GY_IRONCLAD_GARRISON;
                        break;
                    case GOSSIP_OPTION_ID_WARDENS_VIGIL:
                        areaId = TB_GY_WARDENS_VIGIL;
                        break;
                    case GOSSIP_OPTION_ID_EAST_SPIRE:
                        areaId = TB_GY_EAST_SPIRE;
                        break;
                    case GOSSIP_OPTION_ID_WEST_SPIRE:
                        areaId = TB_GY_WEST_SPIRE;
                        break;
                    case GOSSIP_OPTION_ID_SOUTH_SPIRE:
                        areaId = TB_GY_SOUTH_SPIRE;
                        break;
                    default:
                        return;
                }

                if (WorldSafeLocsEntry const* safeLoc = sWorldSafeLocsStore.LookupEntry(areaId))
                    player->TeleportTo(safeLoc->MapID, safeLoc->Loc.X, safeLoc->Loc.Y, safeLoc->Loc.Z, 0);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_tb_spirit_guideAI(creature);
        }
};

// 85123 - Siege Cannon - selects random target
class spell_siege_cannon : public SpellScriptLoader
{
public:
    spell_siege_cannon() : SpellScriptLoader("spell_siege_cannon") { }

    class spell_siege_cannon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_siege_cannon_SpellScript);

        void SelectRandomTarget(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_siege_cannon_SpellScript::SelectRandomTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_siege_cannon_SpellScript();
    }
};

void AddSC_tol_barad()
{
    new npc_tb_spirit_guide();
    new spell_siege_cannon();
}

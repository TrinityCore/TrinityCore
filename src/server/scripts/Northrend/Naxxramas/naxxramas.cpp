/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
 
#include "naxxramas.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

Position const HorsemenPos   = {2521.4895f, -2953.4926f, 245.5520f, 2.357414f};
Position const KelthuzadPos  = {3749.6799f, -5114.0600f, 142.1150f, 2.932150f};

enum Actions
{
    ACTION_TAUNT            = 1,
};

class at_millitary_quarter : public AreaTriggerScript
{
    public:
        at_millitary_quarter() : AreaTriggerScript("at_millitary_quarter") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
        {
            player->GetMap()->LoadGrid(HorsemenPos.GetPositionX(), HorsemenPos.GetPositionY());
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_HORSEMEN) != DONE)
                    if (Creature* Sir = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_SIR)))
                        Sir->AI()->DoAction(ACTION_TAUNT);
            return true;
        }
};

class go_naxxramas_portal : public GameObjectScript
{
    public:
        go_naxxramas_portal() : GameObjectScript("go_naxxramas_portal") {}

        bool OnGossipHello(Player* player, GameObject* go)
        {
            SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_PORTAL);
            if (!spell)
                return false;

            if (player->isInCombat())
            {
                Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }
            player->CastSpell(player, SPELL_PORTAL, true);

            return true;
         }
 };

class go_orb_of_naxxramas : public GameObjectScript
{
    public:
        go_orb_of_naxxramas() : GameObjectScript("go_orb_of_naxxramas") {}

        bool OnGossipHello(Player* player, GameObject* go)
        {
             SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_ORB_TELEPORT_1);
             SpellInfo const* spell2 = sSpellMgr->GetSpellInfo(SPELL_ORB_TELEPORT_2);
             switch (go->GetEntry())
             {
                case 202278:
                    if (player->isInCombat())
                    {
                        Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                        return true;
                    }
                    player->CastSpell(player, SPELL_ORB_TELEPORT_1, true);
                    break;
                case 202277:
                    if (player->isInCombat())
                    {
                        Spell::SendCastResult(player, spell2, 0, SPELL_FAILED_AFFECTING_COMBAT);
                        return true;
                    }
                    player->CastSpell(player, SPELL_ORB_TELEPORT_2, true);
                    break;
             }
             return true;
         }
 };

void AddSC_naxxramas()
{
    new at_millitary_quarter();
    new go_naxxramas_portal();
    new go_orb_of_naxxramas();
}
/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "LFGMgr.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"

// 240600 - Volatile Barrel
class go_volatile_barrel_stormheim : public GameObjectScript
{
public:
    go_volatile_barrel_stormheim() : GameObjectScript("go_volatile_barrel_stormheim") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(181981);

        player->SetPower(POWER_ALTERNATE_POWER, player->GetPower(POWER_ALTERNATE_POWER) + spellInfo->GetEffect(EFFECT_0)->BasePoints);

        for (int32 i = 0; i < spellInfo->GetEffect(EFFECT_0)->BasePoints; ++i)
            player->KilledMonsterCredit(91693, ObjectGuid::Empty);

        if (player->GetPower(POWER_ALTERNATE_POWER) >= 100)
            player->CastSpell(player, 181981, true);

        return true;
    }
};

class npc_grapple_point : public CreatureScript
{
public:
    npc_grapple_point() : CreatureScript("npc_grapple_point") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(38613) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(creature, 182467, true);
            player->GetMotionMaster()->MoveJump(creature->GetPosition(), 15.0f, 15.0f, 0, false);
            player->KilledMonsterCredit(91484, ObjectGuid::Empty);
        }
        return true;
    }
};

// 181981
class spell_pump : public SpellScriptLoader
{
public:
    spell_pump() : SpellScriptLoader("spell_pump") { }

    class spell_pump_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pump_SpellScript);

        void HandleEnergize(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->EnergizeBySpell(caster, GetSpellInfo()->Id, GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, POWER_ALTERNATE_POWER);
                if (Quest const* quest = sObjectMgr->GetQuestTemplate(38358))
                    for (QuestObjective const& obj : quest->GetObjectives())
                        if (obj.ObjectID == 91590)
                        {
                            caster->ToPlayer()->SetQuestObjectiveData(obj, 1);
                            caster->ToPlayer()->SendQuestUpdateAddCredit(quest, ObjectGuid::Empty, obj, 1);
                        }

                if (caster->GetPower(POWER_ALTERNATE_POWER) >= 100)
                    caster->ToPlayer()->KilledMonsterCredit(91590, ObjectGuid::Empty);

                if (caster->ToPlayer()->CanCompleteQuest(38358))
                    caster->ToPlayer()->CompleteQuest(38358);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pump_SpellScript::HandleEnergize, EFFECT_0, SPELL_EFFECT_KILL_CREDIT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pump_SpellScript();
    }
};

void AddSC_stormheim()
{
    new go_volatile_barrel_stormheim();
    new npc_grapple_point();
    new spell_pump();
}

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
#include "CreatureTextMgr.h"
#include "SpellScript.h"
#include "firelands.h"

enum Spells
{
    SPELL_SMOULDERING_QUEST_CHECK_A = 101089, // Alliance - Unverified
    SPELL_SMOULDERING_QUEST_CHECK_H = 101092  // Horde - Unverified
};

// http://www.wowhead.com/spell=101089/smouldering
// http://www.wowhead.com/spell=101092/smouldering
class spell_firelands_smouldering : public SpellScriptLoader
{
    public:
        spell_firelands_smouldering() : SpellScriptLoader("spell_firelands_smouldering") { }

        class spell_firelands_smouldering_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_firelands_smouldering_SpellScript);

            void CheckQuestStatus(std::list<WorldObject*>& targets)
            {
                bool raidHasQuest = false;

                targets.remove_if(PlayerCheck());
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_SMOULDERING_QUEST_CHECK_A:
                        for (auto target : targets)
                            if (Player* player = target->ToPlayer())
                                if (player->GetQuestStatus(QUEST_HEART_OF_FLAME_A) == QUEST_STATUS_INCOMPLETE)
                                    raidHasQuest = true;
                        break;
                    case SPELL_SMOULDERING_QUEST_CHECK_H:
                        for (auto target : targets)
                            if (Player* player = target->ToPlayer())
                                if (player->GetQuestStatus(QUEST_HEART_OF_FLAME_H) == QUEST_STATUS_INCOMPLETE)
                                    raidHasQuest = true;
                        break;
                    default:
                        break;
                }

                targets.clear();
                if (raidHasQuest)
                    targets.push_back(GetCaster());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_firelands_smouldering_SpellScript::CheckQuestStatus, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_firelands_smouldering_SpellScript();
        }
};

// http://www.wowhead.com/spell=101093/smouldering
class spell_firelands_smouldering_aura : public SpellScriptLoader
{
    public:
        spell_firelands_smouldering_aura() : SpellScriptLoader("spell_firelands_smouldering_aura") { }

        class spell_firelands_smouldering_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_firelands_smouldering_aura_SpellScript);

            void SetTarget(WorldObject*& target)
            {
                target = GetCaster();
            }

            void Register() override
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_firelands_smouldering_aura_SpellScript::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_firelands_smouldering_aura_SpellScript();
        }
};

void AddSC_firelands()
{
    new spell_firelands_smouldering();
    new spell_firelands_smouldering_aura();
}

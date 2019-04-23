/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "Player.h"
#include "ObjectMgr.h"

class scene_azsuna_runes : public SceneScript
{
public:
    scene_azsuna_runes() : SceneScript("scene_azsuna_runes") { }

    // Called when a player receive trigger from scene
    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate, std::string const& triggerName) override
    {
        if (triggerName == "Credit")
        {
            uint32 killCreditEntry = 0;

            switch (sceneTemplate->ScenePackageId)
            {
                case 1378: //Azsuna - Academy - Runes A(Arcane, Quest) - PRK
                case 1695: //Azsuna - Academy - Runes D(Arcane: Sophomore) - PRK
                case 1696: //Azsuna - Academy - Runes E(Arcane: Junior) - PRK
                case 1697: //Azsuna - Academy - Runes F(Arcane: Senior) - PRK
                    killCreditEntry = 89655;
                    break;
                case 1379: //Azsuna - Academy - Runes B(Fire, Quest) - PRK
                case 1698: //Azsuna - Academy - Runes G(Fire: Freshman) - PRK
                case 1699: //Azsuna - Academy - Runes H(Fire: Junior) - PRK
                case 1700: //Azsuna - Academy - Runes I(Fire: Senior) - PRK
                    killCreditEntry = 89656;
                    break;
                case 1380: //Azsuna - Academy - Runes C(Frost, Quest) - PRK
                case 1701: //Azsuna - Academy - Runes J(Frost: Freshman) - PRK
                case 1702: //Azsuna - Academy - Runes K(Frost: Junior) - PRK
                case 1703: //Azsuna - Academy - Runes L(Frost: Senior) - PRK
                    killCreditEntry = 89657;
                    break;
            }

            if (killCreditEntry)
                player->KilledMonsterCredit(killCreditEntry);
        }
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate) override
    {
        uint32 nextSceneSpellId = 0;

        switch (sceneTemplate->ScenePackageId)
        {
            case 1378: nextSceneSpellId = 223283; break; //Azsuna - Academy - Runes A(Arcane, Quest) - PRK, next : fire quest
            case 1379: nextSceneSpellId = 223287; break; //Azsuna - Academy - Runes B(Fire, Quest) - PRK, next : frost quest
            default:
            case 1695: //Azsuna - Academy - Runes D(Arcane: Sophomore) - PRK
            case 1696: //Azsuna - Academy - Runes E(Arcane: Junior) - PRK
            case 1697: //Azsuna - Academy - Runes F(Arcane: Senior) - PRK
            case 1698: //Azsuna - Academy - Runes G(Fire: Freshman) - PRK
            case 1699: //Azsuna - Academy - Runes H(Fire: Junior) - PRK
            case 1700: //Azsuna - Academy - Runes I(Fire: Senior) - PRK
            case 1380: //Azsuna - Academy - Runes C(Frost, Quest) - PRK
            case 1701: //Azsuna - Academy - Runes J(Frost: Freshman) - PRK
            case 1702: //Azsuna - Academy - Runes K(Frost: Junior) - PRK
            case 1703: //Azsuna - Academy - Runes L(Frost: Senior) - PRK
                break;
        }

        if (nextSceneSpellId)
            player->CastSpell(player, nextSceneSpellId, true);
    }
};

struct questnpc_soul_gem : public ScriptedAI
{
    questnpc_soul_gem(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        CheckForDeadDemons(me);
    }

    void CheckForDeadDemons(Creature* creature)
    {
        if (!creature->GetOwner() || !creature->GetOwner()->IsPlayer())
            return;

        std::list<Creature*> targets = creature->FindAllCreaturesInRange(15.0f);
        Player* owner = creature->GetOwner()->ToPlayer();

        for (Creature* target : targets)
        {
            if(!target->IsAlive())
            { 
                switch (target->GetEntry())
                {
                    case 90230:
                    case 90241:
                    case 93556:
                    case 93619:
                    case 101943:
                    case 103180:
                        target->DespawnOrUnsummon();
                        owner->KilledMonsterCredit(90298);
                        break;
                    default:
                        break;
                }
            }
        }
    }
};

enum eManaDrainedWhelpling
{
    NPC_AZUREWING_WHELPLING = 90336
};

// 90167
struct questnpc_mana_drained_whelpling : public ScriptedAI
{
    questnpc_mana_drained_whelpling(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) override
    {
        me->GetScheduler().Schedule(1s, [](TaskContext context)
        {
            Creature* crea = GetContextCreature();
            crea->UpdateEntry(NPC_AZUREWING_WHELPLING);
            crea->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            crea->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, 0);
        });

        me->GetScheduler().Schedule(3s, [](TaskContext context)
        {
            GetContextCreature()->SetCanFly(true);
            GetContextCreature()->GetMotionMaster()->MoveTakeoff(0, Position(1162.338135f, 6816.301270f, 236.106567f));
        });

        me->GetScheduler().Schedule(10s, [](TaskContext context)
        {
            GetContextCreature()->DisappearAndDie();
        });
    }
};

void AddSC_azsuna()
{
    new scene_azsuna_runes();
    RegisterCreatureAI(questnpc_soul_gem);
    RegisterCreatureAI(questnpc_mana_drained_whelpling);
}

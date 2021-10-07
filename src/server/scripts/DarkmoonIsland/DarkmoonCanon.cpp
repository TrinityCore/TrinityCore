/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AchievementMgr.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "DarkmoonIsland.h"

enum eSpells
{
    SPELL_CANON_PREPARATION     = 102112,
    SPELL_ROOT                  = 97936,

    SPELL_CANON_DEFLAGRATION    = 102121,
    SPELL_MAGIC_WINGS           = 102116,

    SPELL_TARGET_CREDIT         = 100962,
    SPELL_TARGET_CENTER         = 62173,
    SPELL_TARGET_NEAR           = 62175,
    SPELL_TARGET_MISS           = 62179
};

#define ACHIEVEMENT_BLASTENHEIMER_BULLSEYE  6021

class npc_canon_maxima : public CreatureScript
{
    public:
        npc_canon_maxima() : CreatureScript("npc_canon_maxima") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->GetQuestStatus(QUEST_HUMANOID_CANNONBALL) == QUEST_STATUS_INCOMPLETE)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Je souhaite devenir un homme canon !", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
        {
            if (!player->HasItemCount(ITEM_DARKMOON_TOKEN))
            {
                creature->Whisper("Vous devez posseder un Jeton de Sombrelune pour utiliser le canon !", LANG_UNIVERSAL, player);
                CloseGossipMenuFor(player);
                return true;
            }

            player->DestroyItemCount(ITEM_DARKMOON_TOKEN, 1, true);

            player->NearTeleportTo(-4018.15f, 6299.57f, 13.11f, 3.31f, true);
            player->CastSpell(player, SPELL_CANON_PREPARATION, false);
            player->CastSpell(player, SPELL_ROOT, false);

            CloseGossipMenuFor(player);
            return true;
        }
};

class npc_darkmoon_canon_target : public CreatureScript
{
    public:
        npc_darkmoon_canon_target() : CreatureScript("npc_darkmoon_canon_target") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_darkmoon_canon_targetAI(pCreature);
        }

        struct npc_darkmoon_canon_targetAI : ScriptedAI
        {
            npc_darkmoon_canon_targetAI(Creature* pCreature) : ScriptedAI(pCreature)
            {}

            void Reset() override
            {
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 30.0f);

                if (playerList.empty())
                    return;

                for (auto player: playerList)
                {
                    if (player->GetPositionZ() > 0.0f)
                        continue;

                    if (!player->HasAura(SPELL_CANON_DEFLAGRATION))
                        continue;

                    player->RemoveAurasDueToSpell(SPELL_CANON_DEFLAGRATION);

                    uint32 dist = me->GetDistance(player);
                    uint32 creditCount = 1;

                    if (dist <= 3.0f)
                    {
                        if (AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(ACHIEVEMENT_BLASTENHEIMER_BULLSEYE))
                            player->CompletedAchievement(achievementEntry);
                        me->AddAura(SPELL_TARGET_CENTER, player);
                        creditCount = 5;
                    }
                    else if (dist <= 10.0f)
                    {
                        me->AddAura(SPELL_TARGET_NEAR, player);
                        creditCount = 3;
                    }
                    else
                        me->AddAura(SPELL_TARGET_MISS, player);

                    for (uint8 i = 0; i < creditCount; ++i)
                        player->CastSpell(player, SPELL_TARGET_CREDIT, false);
                }
            }
        };
};

class npc_canon_fozlebub : public CreatureScript
{
    public:
        npc_canon_fozlebub() : CreatureScript("npc_canon_fozlebub") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->GetQuestStatus(QUEST_HUMANOID_CANNONBALL) != QUEST_STATUS_NONE)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Teleportez moi au canon !", GOSSIP_SENDER_MAIN, 0, "Souhaitez-vous payer 30 piece d'argent ?", 3000, false);

            player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
        {
            player->ModifyMoney(-3000);
            player->TeleportTo(974, -4019.00f, 6286.58f, 12.49f, 1.39f);

            CloseGossipMenuFor(player);
            return true;
        }
};

class spell_darkmoon_canon_preparation : public SpellScriptLoader
{
    public:
        spell_darkmoon_canon_preparation() : SpellScriptLoader("spell_darkmoon_canon_preparation") { }

        class spell_darkmoon_canon_preparation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_darkmoon_canon_preparation_AuraScript);

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                if (Player* target = GetTarget()->ToPlayer())
                {
                    target->RemoveAurasDueToSpell(SPELL_ROOT);
                    target->SetOrientation(3.31f);
                    target->CastSpell(target, SPELL_CANON_DEFLAGRATION, false); // Must be first
                    target->CastSpell(target, SPELL_MAGIC_WINGS, false);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_darkmoon_canon_preparation_AuraScript::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_darkmoon_canon_preparation_AuraScript();
        }
};

void AddSC_darkmoon_canon()
{
    new npc_canon_maxima();
    new npc_darkmoon_canon_target();
    new npc_canon_fozlebub();
    new spell_darkmoon_canon_preparation();
};

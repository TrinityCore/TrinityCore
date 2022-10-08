/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "WaypointManager.h"
#include "Vehicle.h"
#include "SceneMgr.h"
#include "MotionMaster.h"
#include "WorldSession.h"

// 91109 - Malfurion Stormrage
class npc_malfurion_valshara : public CreatureScript
{
public:
    npc_malfurion_valshara() : CreatureScript("npc_malfurion_valshara") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I am ready to aid you, Malfurion.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, 1, creature->GetGUID());

        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->KilledMonsterCredit(92742, ObjectGuid::Empty);
            player->CastSpell(player, 197680, true);
            break;
        }

        return true;
    }
};

// 92742 Ysera
class npc_ysera_valshara : public CreatureScript
{
public:
    npc_ysera_valshara() : CreatureScript("npc_ysera_valshara") { }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == 38595)
        {
            creature->Say("Cenarius's loss has left Malfurion unable to see reason.", LANG_UNIVERSAL);
            creature->Say("Make haste to the World Tree. He may be headed there, all too ready to take reckless risks.", LANG_UNIVERSAL);
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I am ready, Ysera. Let us find Malfurion!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        SendGossipMenuFor(player, 26531, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            if (Creature* ysera = creature->SummonCreature(92748, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 300000))
                player->CastSpell(ysera, 46598, true);
            break;
        }

        return true;
    }
};

enum SceneSpells
{
    SPELL_YSERAS_CORRUPTION_MOVIE = 228531,
    SPELL_KILL_CREDIT = 206723,
    SPELL_YSERA_POSTCORRUPTION = 218440
};

class movie_yseras_corruption : public PlayerScript
{
public:
    movie_yseras_corruption() : PlayerScript("movie_yseras_corruption") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        if (movieId == 473)
            player->CastSpell(player, SPELL_YSERA_POSTCORRUPTION, true);
    }
};

class npc_tyrande_scene : public CreatureScript
{
public:
    npc_tyrande_scene() : CreatureScript("npc_tyrande_scene") { }

    struct npc_tyrande_sceneAI : public ScriptedAI
    {
        npc_tyrande_sceneAI(Creature* creature) : ScriptedAI(creature) {}

        bool isScene;
        bool isMovie;
        uint32 sceneTimer;
        uint32 movieTimer;
        ObjectGuid playerGuid;

        void Reset()
        {
            isScene = false;
            isMovie = false;
            playerGuid = ObjectGuid::Empty;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!isScene && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 15.0f))
            {
                playerGuid = who->ToPlayer()->GetGUID();

                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                {
                    if (player->GetQuestStatus(38753) == QUEST_STATUS_INCOMPLETE)
                    {
                        isScene = true;
                        sceneTimer = 100;
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (isScene && !isMovie)
            {
                if (sceneTimer <= diff)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                    {
                        WorldPackets::Scenes::PlayScene packet;
                        packet.SceneID = 1194;
                        packet.PlaybackFlags = 20;
                        packet.SceneInstanceID = 3;
                        packet.SceneScriptPackageID = 1560;
                        packet.TransportGUID = player->GetTransGUID();
                        packet.Location = player->GetPosition();
                        player->GetSession()->SendPacket(packet.Write(), true);

                        movieTimer = 18000;
                        isMovie = true;
                        player->CastSpell(player, SPELL_KILL_CREDIT, true);
                    }
                }
                else sceneTimer -= diff;
            }

            if (isMovie)
            {
                if (movieTimer <= diff)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                    {
                        player->CastSpell(player, SPELL_YSERAS_CORRUPTION_MOVIE, true);

                        isMovie = false;
                    }
                }
                else movieTimer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tyrande_sceneAI(creature);
    }
};

enum SubduedNightwingAction
{
    ACTION_RETURN
};

// 221420 - Return
class spell_return_valshara : public SpellScriptLoader
{
public:
    spell_return_valshara() : SpellScriptLoader("spell_return_valshara") {}

    class spell_return_valshara_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_return_valshara_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Creature* creature = caster->FindNearestCreature(109827, 5.0f, true))
                    creature->GetMotionMaster()->MovePoint(0, 3419.750f, 6120.740f, 210.012f);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_return_valshara_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_return_valshara_SpellScript();
    }
};

// 111359 - Subdued Nightwing
class npc_subdued_nightwing : public CreatureScript
{
public:
    npc_subdued_nightwing() : CreatureScript("npc_subdued_nightwing") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(43702) == QUEST_STATUS_INCOMPLETE)
            if (Creature* creature = player->SummonCreature(109827, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000))
                player->CastSpell(creature, 46598, true);

        return true;
    }
};

// quest 39702
class npc_tele_q39702 : public CreatureScript
{
public:
    npc_tele_q39702() : CreatureScript("npc_tele_q39702") { }
    struct npc_tele_q39702AI : public ScriptedAI
    {
        npc_tele_q39702AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(39702) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 2.0f))
                    {
                        player->KilledMonsterCredit(96736);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tele_q39702AI(creature);
    }
};

class npc_92850 : public CreatureScript
{
public:
    npc_92850() : CreatureScript("npc_92850") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        switch (action)
        {
        case 1:
            player->CastSpell(player, 229829, true);
            player->PlayerTalkClass->ClearMenus();
            CloseGossipMenuFor(player);
            break;
        }

        return true;
    }
};

void AddSC_valsharah()
{
    new npc_malfurion_valshara();
    new npc_ysera_valshara();
    new movie_yseras_corruption();
    new npc_tyrande_scene();
    new spell_return_valshara();
    new npc_subdued_nightwing();
    new npc_tele_q39702();
    new npc_92850();
}

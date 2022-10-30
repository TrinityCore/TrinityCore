/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Object.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Conversation.h"
#include "TemporarySummon.h"

// Scripting in this section is from login to arriving on beach for alliance and horde

enum QuestScriptQuestWarmingUp
{
    QUEST_WARMING_UP                = 59926,
    CONVERSATION_WARMING_UP         = 12798,
    NPC_WARLORD_BREKA_GRIMAXE1      = 166573,
    NPC_WARLORD_BREKA_GRIMAXE2      = 166824
};

class quest_warming_up : public QuestScript
{
public:
    quest_warming_up() : QuestScript("quest_warming_up") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/ , QuestStatus newStatus) override
    {
        switch (newStatus)
        {
            case QUEST_STATE_COMPLETE:
                Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID(), nullptr);
                break;
            case QUEST_STATUS_REWARDED:
                if (Creature* breka1 = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE1, 5.0f))
                    if (Creature* breka2 = player->FindNearestCreature(NPC_WARLORD_BREKA_GRIMAXE2, 75.0f))
                        breka2->SummonPersonalClone(breka1->GetPosition(), TempSummonType(TEMPSUMMON_TIMED_DESPAWN), 18s, 0, 0, player);
                break;
            default:
                break;
        }
    }
};

enum PlayerScriptHordeShipCrash
{
    MOVIE_ALLIANCE_SHIP_CRASH = 895,
    MOVIE_HORDE_SHIP_CRASH    = 931,
    SPELL_ALLIANCE_SHIP_CRASH = 305446,
    SPELL_HORDE_SHIP_CRASH    = 325133
};

class player_ship_crash : public PlayerScript
{
public:
    player_ship_crash() : PlayerScript("player_ship_crash") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        switch (movieId)
        {
            case MOVIE_ALLIANCE_SHIP_CRASH:
                player->CastSpell(player, SPELL_ALLIANCE_SHIP_CRASH, true);
                break;
            case MOVIE_HORDE_SHIP_CRASH:
                player->CastSpell(player, SPELL_HORDE_SHIP_CRASH, true);
                break;
            default:
                break;
        }
    }
};

enum AllianceHordeShipSceneSpells
{
    SPELL_BEGIN_TUTORIAL = 295600,
    SPELL_KNOCKED_DOWN   = 305445,
    SPELL_CRASHED_LANDED = 325136
};

class scene_alliance_and_horde_ship : public SceneScript
{
public:
    scene_alliance_and_horde_ship() : SceneScript("scene_alliance_and_horde_ship") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }
};

class scene_alliance_and_horde_crash : public SceneScript
{
public:
    scene_alliance_and_horde_crash() : SceneScript("scene_alliance_and_horde_crash") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Begin Knockdown Aura")
            player->CastSpell(player, SPELL_KNOCKED_DOWN, true);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_CRASHED_LANDED, true);
    }
};

class spell_alliance_spell_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_alliance_spell_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alliance_spell_ship_crash_teleport::RelocateTransportOffset, EFFECT_4, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

class spell_horde_spell_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_horde_spell_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_horde_spell_ship_crash_teleport::RelocateTransportOffset, EFFECT_3, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

// Scripting in this section is from arriving on beach for alliance and horde

void AddSC_zone_exiles_reach()
{
    // Ship
    new quest_warming_up();
    new player_ship_crash();
    new scene_alliance_and_horde_ship();
    new scene_alliance_and_horde_crash();
    RegisterSpellScript(spell_alliance_spell_ship_crash_teleport);
    RegisterSpellScript(spell_horde_spell_ship_crash_teleport);
    // Beach
}

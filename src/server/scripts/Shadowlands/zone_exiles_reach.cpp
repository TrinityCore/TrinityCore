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

#include "Player.h"
#include "ScriptMgr.h"
#include "Conversation.h"

enum PlayerScriptQuestWarmingUp
{
    QUEST_WARMING_UP        = 59926,
    CONVERSATION_WARMING_UP = 12798
};

class playerscript_warming_up : public PlayerScript
{
public:
    playerscript_warming_up() : PlayerScript("playerscript_warming_up") { }

    void OnQuestStatusChange(Player* player, uint32 questId) override
    {
        if(questId == QUEST_WARMING_UP && player->GetQuestStatus(QUEST_WARMING_UP) == QUEST_STATUS_COMPLETE)
            Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID(), nullptr);
    }
};

enum PlayerScriptHordeShipCrash
{
    MOVIE_HORDE_SHIP_CRASH = 931,
    SPELL_HORDE_SHIP_CRASH = 325133
};

class playerscript_horde_ship_crash : public PlayerScript
{
public:
    playerscript_horde_ship_crash() : PlayerScript("playerscript_horde_ship_crash") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        if(movieId == MOVIE_HORDE_SHIP_CRASH)
            player->CastSpell(player, SPELL_HORDE_SHIP_CRASH, true);
    }
};

enum PlayerScriptAllianceShipCrash
{
    MOVIE_ALLIANCE_SHIP_CRASH = 895,
    SPELL_ALLIANCE_SHIP_CRASH = 305446
};

class playerscript_alliance_ship_crash : public PlayerScript
{
public:
    playerscript_alliance_ship_crash() : PlayerScript("playerscript_alliance_ship_crash") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        if (movieId == MOVIE_ALLIANCE_SHIP_CRASH)
            player->CastSpell(player, SPELL_ALLIANCE_SHIP_CRASH, true);
    }
};

class spell_q59928_spell_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_q59928_spell_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q59928_spell_ship_crash_teleport::RelocateTransportOffset, EFFECT_3, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

class spell_q58208_spell_ship_crash_teleport : public SpellScript
{
    PrepareSpellScript(spell_q58208_spell_ship_crash_teleport);

    void RelocateTransportOffset(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q58208_spell_ship_crash_teleport::RelocateTransportOffset, EFFECT_4, SPELL_EFFECT_TELEPORT_UNITS);
    }
};

void AddSC_zone_exiles_reach()
{
    new playerscript_warming_up();
    new playerscript_horde_ship_crash();
    new playerscript_alliance_ship_crash();
    RegisterSpellScript(spell_q59928_spell_ship_crash_teleport);
    RegisterSpellScript(spell_q58208_spell_ship_crash_teleport);
}

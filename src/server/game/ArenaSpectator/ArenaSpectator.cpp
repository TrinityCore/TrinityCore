/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ArenaSpectator.h"
#include "BattlegroundMgr.h"
#include "LFGMgr.h"
#include "Map.h"
#include "Pet.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "Types.h"
#include "World.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "WorldSession.h"

bool ArenaSpectator::HandleSpectatorSpectateCommand(ChatHandler* handler, std::string const& name)
{
    Player* player = handler->GetSession()->GetPlayer();
    std::list<std::string> errors;

    if (player->IsSpectator())
    {
        if (player->FindMap() && player->FindMap()->IsBattleArena())
        {
            HandleSpectatorWatchCommand(handler, name);
            return true;
        }
        handler->PSendSysMessage("You are already spectacting arena.");
        return true;
    }

    Player* spectate = ObjectAccessor::FindPlayerByName(name);
    if (!spectate)
    {
        handler->SendSysMessage("Requested player not found.");
        return true;
    }

    if (spectate->IsSpectator())
    {
        handler->SendSysMessage("Requested player is a spectator.");
        return true;
    }

    if (!spectate->FindMap() || !spectate->FindMap()->IsBattleArena())
    {
        handler->SendSysMessage("Requested player is not in arena.");
        return true;
    }

    BattlegroundMap* bgmap = ((BattlegroundMap*)spectate->FindMap());
    if (!bgmap->GetBG() || bgmap->GetBG()->GetStatus() == STATUS_WAIT_LEAVE)
    {
        handler->SendSysMessage("This arena battle has finished.");
        return true;
    }

    if (player->IsBeingTeleported() || !player->IsInWorld())
        errors.push_back("Can't use while being teleported.");

    if (!player->FindMap() || player->FindMap()->Instanceable())
        errors.push_back("Can't use while in instance, bg or arena.");

    if (player->GetVehicle())
        errors.push_back("Can't be on a vehicle.");

    if (player->IsInCombat())
        errors.push_back("Can't be in combat.");

    if (player->isUsingLfg())
        errors.push_back("Can't spectate while using LFG system.");

    if (player->InBattlegroundQueue())
        errors.push_back("Can't be queued for arena or bg.");

    if (player->GetGroup())
        errors.push_back("Can't be in a group.");

    if (player->HasUnitState(UNIT_STATE_ISOLATED))
        errors.push_back("Can't be isolated.");

    /*
    if (player->m_mover != player)
        errors.push_back("You must control yourself.");
        */

    if (player->IsInFlight())
        errors.push_back("Can't be in flight.");

    if (player->IsMounted())
        errors.push_back("Dismount before spectating.");

    if (!player->IsAlive())
        errors.push_back("Must be alive.");

    if (!player->m_Controlled.empty())
        errors.push_back("Can't be controlling creatures.");

    const Unit::VisibleAuraMap va = player->GetVisibleAuras();
    for (auto itr = va.begin(); itr != va.end(); ++itr)
        if (Aura* aura = itr->second->GetBase())
            if (!itr->second->IsPositive() && !aura->IsPermanent() && aura->GetDuration() < HOUR * IN_MILLISECONDS)
            {
                switch (aura->GetSpellInfo()->Id)
                {
                case lfg::LFG_SPELL_DUNGEON_DESERTER:
                case lfg::LFG_SPELL_DUNGEON_COOLDOWN:
                case 26013: // bg deserter
                case 57724: // sated
                case 57723: // exhaustion
                case 25771: // forbearance
                case 15007: // resurrection sickness
                case 24755: // Tricked or Treated (z eventu)
                    continue;
                }

                errors.push_back("Can't have negative auras.");
                break;
            }

    if (uint32 inviteInstanceId = player->GetPendingSpectatorInviteInstanceId())
    {
        if (Battleground* tbg = sBattlegroundMgr->GetBattleground(inviteInstanceId, BATTLEGROUND_TYPE_NONE))
            tbg->RemoveToBeTeleported(player->GetGUID());
        player->SetPendingSpectatorInviteInstanceId(0);
    }

    bool bgPreparation = false;
    if ((!handler->GetSession()->GetSecurity() && bgmap->GetBG()->GetStatus() != STATUS_IN_PROGRESS) ||
        (handler->GetSession()->GetSecurity() && bgmap->GetBG()->GetStatus() != STATUS_WAIT_JOIN && bgmap->GetBG()->GetStatus() != STATUS_IN_PROGRESS))
    {
        bgPreparation = true;
        handler->SendSysMessage("Arena is not in progress yet. You will be invited as soon as it starts.");
        bgmap->GetBG()->AddToBeTeleported(player->GetGUID(), spectate->GetGUID());
        player->SetPendingSpectatorInviteInstanceId(spectate->GetBattlegroundId());
    }

    if (!errors.empty())
    {
        handler->PSendSysMessage("To spectate, please fix the following:");
        for (std::list<std::string>::const_iterator itr = errors.begin(); itr != errors.end(); ++itr)
            handler->PSendSysMessage("- %s", (*itr).c_str());

        return true;
    }

    if (bgPreparation)
        return true;

    float z = spectate->GetMapId() == 618 ? std::max(28.27f, spectate->GetPositionZ() + 0.25f) : spectate->GetPositionZ() + 0.25f;

    player->SetPendingSpectatorForBG(spectate->GetBattlegroundId());
    player->SetBattlegroundId(spectate->GetBattlegroundId(), spectate->GetBattlegroundTypeId(), PLAYER_MAX_BATTLEGROUND_QUEUES, false, false, TEAM_NEUTRAL);
    player->SetEntryPoint();
    player->TeleportTo(spectate->GetMapId(), spectate->GetPositionX(), spectate->GetPositionY(), z, spectate->GetOrientation(), TELE_TO_GM_MODE);

    return true;
}

bool ArenaSpectator::HandleSpectatorWatchCommand(ChatHandler* handler, std::string const& name)
{
    Player* player = handler->GetSession()->GetPlayer();
    if (!player->IsSpectator())
        return true;

    if (!player->FindMap() || !player->FindMap()->IsBattleArena())
        return true;

    Battleground* bg = ((BattlegroundMap*)player->FindMap())->GetBG();
    if (!bg || bg->GetStatus() != STATUS_IN_PROGRESS)
        return true;

    Player* spectate = ObjectAccessor::FindPlayerByName(name);
    if (!spectate || !spectate->IsAlive() || spectate->IsSpectator() || spectate->GetGUID() == player->GetGUID() || !spectate->IsInWorld() || !spectate->FindMap() || spectate->IsBeingTeleported() || spectate->FindMap() != player->FindMap() || !bg->IsPlayerInBattleground(spectate->GetGUID()))
        return true;

    if (WorldObject* o = player->GetViewpoint())
        if (Unit* u = o->ToUnit())
        {
            u->RemoveAurasByType(SPELL_AURA_BIND_SIGHT, player->GetGUID());
            player->RemoveAurasDueToSpell(SPECTATOR_SPELL_BINDSIGHT, player->GetGUID(), (1 << EFFECT_1));

            if (u->GetGUID() == spectate->GetGUID())
                return true;
        }

    if (player->GetUInt64Value(PLAYER_FARSIGHT) || player->m_seer != player) // pussywizard: below this point we must not have a viewpoint!
        return true;

    if (player->HaveAtClient(spectate))
        player->CastSpell(spectate, SPECTATOR_SPELL_BINDSIGHT, true);

    return true;
}

void ArenaSpectator::CreatePacket(WorldPacket& data, std::string const& message)
{
    size_t len = message.length();
    data.Initialize(SMSG_MESSAGECHAT, 1 + 4 + 8 + 4 + 8 + 4 + 1 + len + 1);
    data << uint8(CHAT_MSG_WHISPER);
    data << uint32(LANG_ADDON);
    data << uint64(0);
    data << uint32(0);
    data << uint64(0);
    data << uint32(len + 1);
    data << message;
    data << uint8(0);
}

void ArenaSpectator::HandleResetCommand(Player* player)
{
    if (!player->FindMap() || !player->IsInWorld() || !player->FindMap()->IsBattleArena())
        return;

    Battleground* bg = ((BattlegroundMap*)player->FindMap())->GetBG();
    if (!bg || bg->GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::BattlegroundPlayerMap const& pl = bg->GetPlayers();
    for (Battleground::BattlegroundPlayerMap::const_iterator itr = pl.begin(); itr != pl.end(); ++itr)
    {
        if (player->HasReceivedSpectatorResetFor(itr->first))
            continue;

        Player* plr = bg->_GetPlayer(itr->first, itr->second.OfflineRemoveTime != 0, "spectating");
        player->AddReceivedSpectatorResetFor(itr->first);

        SendCommand_String(player, itr->first, "NME", plr->GetName().c_str());
        // Xinef: addon compatibility
        SendCommand_UInt32Value(player, itr->first, "TEM", plr->GetTeamId() == TEAM_ALLIANCE ? ALLIANCE : HORDE);
        SendCommand_UInt32Value(player, itr->first, "CLA", plr->GetClass());
        SendCommand_UInt32Value(player, itr->first, "MHP", plr->GetMaxHealth());
        SendCommand_UInt32Value(player, itr->first, "CHP", plr->GetHealth());
        SendCommand_UInt32Value(player, itr->first, "STA", plr->IsAlive() ? 1 : 0);
        Powers ptype = plr->GetPowerType();
        SendCommand_UInt32Value(player, itr->first, "PWT", ptype);
        SendCommand_UInt32Value(player, itr->first, "MPW", ptype == POWER_RAGE || ptype == POWER_RUNIC_POWER ? plr->GetMaxPower(ptype) / 10 : plr->GetMaxPower(ptype));
        SendCommand_UInt32Value(player, itr->first, "CPW", ptype == POWER_RAGE || ptype == POWER_RUNIC_POWER ? plr->GetPower(ptype) / 10 : plr->GetPower(ptype));
        Pet* pet = plr->GetPet();
        SendCommand_UInt32Value(player, itr->first, "PHP", pet && pet->GetCreatureTemplate()->family ? (uint32)pet->GetHealthPct() : 0);
        SendCommand_UInt32Value(player, itr->first, "PET", pet ? pet->GetCreatureTemplate()->family : 0);
        SendCommand_GUID(player, itr->first, "TRG", plr->GetTarget());
        SendCommand_UInt32Value(player, itr->first, "RES", 1);
        SendCommand_UInt32Value(player, itr->first, "CDC", 1);
        SendCommand_UInt32Value(player, itr->first, "TIM", (bg->GetStartTime() < 46 * MINUTE * IN_MILLISECONDS) ? (46 * MINUTE * IN_MILLISECONDS - bg->GetStartTime()) / IN_MILLISECONDS : 0);
        // "SPE" not here (only possible to send starting a new cast)

        // send all "CD"
        /*
        SpellCooldowns const& sc = plr->GetSpellCooldownMap();
        for (SpellCooldowns::const_iterator itrc = sc.begin(); itrc != sc.end(); ++itrc)
            if (itrc->second.sendToSpectator && itrc->second.maxduration >= SPECTATOR_COOLDOWN_MIN * IN_MILLISECONDS && itrc->second.maxduration <= SPECTATOR_COOLDOWN_MAX * IN_MILLISECONDS)
                if (uint32 cd = (getMSTimeDiff(getMSTime(), itrc->second.end) / 1000))
                    SendCommand_Cooldown(player, itr->first, "ACD", itrc->first, cd, itrc->second.maxduration / 1000);
        */

        // send all visible "AUR"
        Unit::VisibleAuraMap const visibleAuras = plr->GetVisibleAuras();
        for (Unit::VisibleAuraMap::const_iterator aitr = visibleAuras.begin(); aitr != visibleAuras.end(); ++aitr)
        {
            Aura* aura = aitr->second->GetBase();
            if (ShouldSendAura(aura, aitr->second->GetEffectMask(), plr->GetGUID(), false))
                SendCommand_Aura(player, itr->first, "AUR", aura->GetCasterGUID(), aura->GetSpellInfo()->Id, aura->GetSpellInfo()->IsPositive(), aura->GetSpellInfo()->Dispel, aura->GetDuration(), aura->GetMaxDuration(), (aura->GetCharges() > 1 ? aura->GetCharges() : aura->GetStackAmount()), false);
        }
    }
}

bool ArenaSpectator::ShouldSendAura(Aura* aura, uint8 effMask, ObjectGuid targetGUID, bool remove)
{
    if (aura->GetSpellInfo()->SpellIconID == 1 || aura->GetSpellInfo()->HasAttribute(SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
        return false;

    if (remove || aura->GetSpellInfo()->HasAttribute(SPELL_ATTR0_CU_DONT_BREAK_STEALTH) || aura->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_GENERIC)
        return true;

    for (uint8 i = EFFECT_0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (effMask & (1 << i))
        {
            AuraType at = aura->GetEffect(i)->GetAuraType();
            if ((aura->GetEffect(i)->GetAmount() && (aura->GetSpellInfo()->IsPositive() || targetGUID != aura->GetCasterGUID())) ||
                at == SPELL_AURA_MECHANIC_IMMUNITY || at == SPELL_AURA_EFFECT_IMMUNITY || at == SPELL_AURA_STATE_IMMUNITY || at == SPELL_AURA_SCHOOL_IMMUNITY || at == SPELL_AURA_DISPEL_IMMUNITY)
                return true;
        }
    }
    return false;
}

template<>
TC_GAME_API void ArenaSpectator::SendPacketTo(Player const* player, std::string&& message)
{
    WorldPacket data;
    CreatePacket(data, message);
    player->GetSession()->SendPacket(&data);
}

template<>
TC_GAME_API void ArenaSpectator::SendPacketTo(const Map* map, std::string&& message)
{
    if (!map->IsBattleArena())
        return;

    Battleground* bg = ((BattlegroundMap*)map)->GetBG();
    if (!bg || bg->GetStatus() != STATUS_IN_PROGRESS)
        return;

    WorldPacket data;
    CreatePacket(data, message);
    bg->SpectatorsSendPacket(data);
}

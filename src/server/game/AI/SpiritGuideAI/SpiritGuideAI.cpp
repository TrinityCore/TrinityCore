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

#include "SpiritGuideAI.h"
#include "Auras/SpellAuras.h"
#include "Creature.h"
#include "Player.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

SpiritGuideAI::SpiritGuideAI(Creature* creature) : SpiritGuideAI(creature, creature->GetScriptId()) { }

SpiritGuideAI::SpiritGuideAI(Creature* creature, uint32 scriptId) : CreatureAI(creature, scriptId) { }

int32 SpiritGuideAI::Permissible(Creature const* creature)
{
    if (creature->IsSpiritService())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

void SpiritGuideAI::OnDespawn()
{
    switch (me->GetFaction())
    {
        case HORDE_FACTION:
            SummonGraveyardTeleporter(NPC_HORDE_GRAVEYARD_TELEPORT);
            break;
        case ALLIANCE_FACTION:
            SummonGraveyardTeleporter(NPC_ALLIANCE_GRAVEYARD_TELEPORT);
            break;
        default:
            break;
    }
}

void SpiritGuideAI::SummonGraveyardTeleporter(uint32 npcEntry)
{
    // maybe NPC is summoned with these spells:
    // ID - 24237 Summon Alliance Graveyard Teleporter (SERVERSIDE)
    // ID - 46894 Summon Horde Graveyard Teleporter (SERVERSIDE)
    if (TempSummon* summon = me->SummonCreature(npcEntry, me->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 0s, 0, 0))
    {
        summon->SetDemonCreatorGUID(me->GetGUID());
        summon->CastSpell(summon, SPELL_GRAVEYARD_TELEPORT);
    }
}

void AreaSpiritGuideAI::UpdateAI(uint32 diff)
{
    _scheduler.Update(diff);
}

void AreaSpiritGuideAI::JustAppeared()
{
    ScheduleSpiritHealChannel();
}

void AreaSpiritGuideAI::OnChannelFinished(SpellInfo const* spell)
{
    if (spell->Id != SPELL_SPIRIT_HEAL_CHANNEL)
        return;

    ScheduleSpiritHealChannel();
}

void AreaSpiritGuideAI::ScheduleSpiritHealChannel()
{
    _scheduler.Schedule(1s, [this](TaskContext /*context*/)
    {
        DoCastSelf(SPELL_SPIRIT_HEAL_CHANNEL);
    });
}

bool PersonalSpiritGuideAI::OnSpiritHealerQuery(Player* player)
{
    if (Aura* aura = player->GetAura(SPELL_SPIRIT_HEAL_PLAYER_AURA))
    {
        player->SendAreaSpiritHealerQueryOpcode(me->GetGUID(), aura->GetDuration());
        return true;
    }

    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_SPIRIT_HEAL_PLAYER_AURA, DIFFICULTY_NONE))
    {
        DoCast(player, SPELL_SPIRIT_HEAL_PLAYER_AURA);
        player->SendAreaSpiritHealerQueryOpcode(me->GetGUID(), spellInfo->GetDuration());
        DoCastSelf(SPELL_SPIRIT_HEAL_CHANNEL_SELF);
        return true;
    }

    return false;
}

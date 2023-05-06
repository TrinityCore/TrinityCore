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

#include "AreaSpiritHealerAI.h"
#include "Creature.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum AreaSpiritHealerSpells
{
    SPELL_GRAVEYARD_TELEPORT        = 46893,
    SPELL_SPIRIT_HEAL_CHANNEL       = 22011,
};

enum AreaSpiritHealerCreatures
{
    NPC_ALLIANCE_GRAVEYARD_TELEPORT = 26350,
    NPC_HORDE_GRAVEYARD_TELEPORT    = 26351
};

AreaSpiritHealerAI::AreaSpiritHealerAI(Creature* creature) : NullCreatureAI(creature, creature->GetScriptId()) { }

AreaSpiritHealerAI::AreaSpiritHealerAI(Creature* creature, uint32 scriptId) : NullCreatureAI(creature, scriptId) { }

int32 AreaSpiritHealerAI::Permissible(Creature const* creature)
{
    if (creature->IsAreaSpiritHealer())
        return PERMIT_BASE_PROACTIVE;
    return PERMIT_BASE_NO;
}

void AreaSpiritHealerAI::SummonGraveyardTeleporter()
{
    uint32 npcEntry = NPC_HORDE_GRAVEYARD_TELEPORT;
    if (me->GetFaction() == FACTION_ALLIANCE_GENERIC)
        npcEntry = NPC_ALLIANCE_GRAVEYARD_TELEPORT;

    // maybe NPC is summoned with these spells:
    // ID - 24237 Summon Alliance Graveyard Teleporter (SERVERSIDE)
    // ID - 46894 Summon Horde Graveyard Teleporter (SERVERSIDE)
    if (TempSummon* summon = me->SummonCreature(npcEntry, me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 1s, 0, 0))
    {
        summon->SetDemonCreatorGUID(me->GetGUID());
        summon->CastSpell(summon, SPELL_GRAVEYARD_TELEPORT);
    }
}

void AreaSpiritHealerAI::ScheduleSpiritHealChannel()
{
    // @TODO: i dont like this check here yet
    // individual area spirit healers casting is implemented in WorldSession::HandleAreaSpiritHealerQueryOpcode
    if (me->IsAreaSpiritHealerIndividual())
        return;

    _scheduler.Schedule(1s, [this](TaskContext /*context*/)
    {
        DoCastSelf(SPELL_SPIRIT_HEAL_CHANNEL);
    });
}

void AreaSpiritHealerAI::JustAppeared()
{
    ScheduleSpiritHealChannel();
}

void AreaSpiritHealerAI::OnChannelFinished(SpellInfo const* spell)
{
    if (spell->Id != SPELL_SPIRIT_HEAL_CHANNEL)
        return;

    ScheduleSpiritHealChannel();
}

void AreaSpiritHealerAI::OnDespawn()
{
    SummonGraveyardTeleporter();
}

void AreaSpiritHealerAI::UpdateAI(uint32 diff)
{
    _scheduler.Update(diff);
}

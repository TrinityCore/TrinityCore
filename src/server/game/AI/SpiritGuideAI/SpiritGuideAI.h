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

#ifndef SpiritGuideAI_h__
#define SpiritGuideAI_h__

#include "CreatureAI.h"
#include "TaskScheduler.h"

struct TC_GAME_API SpiritGuideAI : public CreatureAI
{
public:
    static constexpr uint32 SPELL_GRAVEYARD_TELEPORT = 46893;

    static constexpr uint32 HORDE_FACTION = 83;
    static constexpr uint32 ALLIANCE_FACTION = 84;

    static constexpr uint32 NPC_ALLIANCE_GRAVEYARD_TELEPORT = 26350;
    static constexpr uint32 NPC_HORDE_GRAVEYARD_TELEPORT = 26351;

    explicit SpiritGuideAI(Creature* creature);
    explicit SpiritGuideAI(Creature* creature, uint32 scriptId);
    virtual ~SpiritGuideAI() { }

    static int32 Permissible(Creature const* creature);

    virtual void UpdateAI(uint32 /*diff*/) override { }

    virtual void OnDespawn() override;

    void SummonGraveyardTeleporter(uint32 npcEntry);

    // Called when a player queries the spirit healer timer information
    // return true to prevent automatic SMSG_AREA_SPIRIT_HEALER_TIME
    virtual bool OnSpiritHealerQuery(Player* /*player*/) { return false; }
    // Called when a player joins spirit healer queue
    virtual void OnSpiritHealerQueue(Player* /*player*/) { }
};

struct TC_GAME_API AreaSpiritGuideAI : public SpiritGuideAI
{
    static constexpr uint32 SPELL_SPIRIT_HEAL_CHANNEL = 22011;

    explicit AreaSpiritGuideAI(Creature* creature) : SpiritGuideAI(creature) { }
    explicit AreaSpiritGuideAI(Creature* creature, uint32 scriptId) : SpiritGuideAI(creature, scriptId) { }
    virtual ~AreaSpiritGuideAI() { }

    void UpdateAI(uint32 diff) override;

    void JustAppeared() override;

    void OnChannelFinished(SpellInfo const* spell) override;

    void ScheduleSpiritHealChannel();

private:
    TaskScheduler _scheduler;
};

struct TC_GAME_API PersonalSpiritGuideAI : public SpiritGuideAI
{
    static constexpr uint32 SPELL_SPIRIT_HEAL_PLAYER_AURA = 156758;
    static constexpr uint32 SPELL_SPIRIT_HEAL_CHANNEL_SELF = 305122;

    explicit PersonalSpiritGuideAI(Creature* creature) : SpiritGuideAI(creature) { }
    explicit PersonalSpiritGuideAI(Creature* creature, uint32 scriptId) : SpiritGuideAI(creature, scriptId) { }
    virtual ~PersonalSpiritGuideAI() { }

    bool OnSpiritHealerQuery(Player* player) override;
};

#endif

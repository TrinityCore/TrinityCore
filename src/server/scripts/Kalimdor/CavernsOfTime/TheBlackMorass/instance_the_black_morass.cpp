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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Containers.h"
#include "EventMap.h"
#include "InstanceScript.h"
#include "Player.h"
#include "the_black_morass.h"

static constexpr ObjectData creatureData[] =
{
    { NPC_MEDIVH,          DATA_MEDIVH },
    { NPC_SAAT,            DATA_SAAT   },
    { 0,                   0           } // END
};

static Position const PortalPosition1 = { -2030.832f, 7024.944f, 23.07182f, 3.141593f };
static Position const PortalPosition2 = { -1961.734f, 7029.528f, 21.8114f,  2.129302f };
static Position const PortalPosition3 = { -1887.695f, 7106.557f, 22.0495f,  4.956735f };
static Position const PortalPosition4 = { -1930.911f, 7183.597f, 23.00764f, 3.595378f };

class instance_the_black_morass : public InstanceMapScript
{
public:
    instance_the_black_morass() : InstanceMapScript(TBMScriptName, 269) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_black_morass_InstanceMapScript(map);
    }

    struct instance_the_black_morass_InstanceMapScript : public InstanceScript
    {
        instance_the_black_morass_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            LoadObjectData(creatureData, nullptr);
            SetBossNumber(EncounterCount);
            DoResetEvent();
        }

        void DoResetEvent()
        {
            EventState              = NOT_STARTED;
            RiftPortalCount         = 0;
            ShieldPercent           = 100;
            LastSummonRiftSpell     = 0;
            OpenRiftPortalsCount    = 0;

            DoUpdateWorldState(WORLD_STATE_BM_SHIELD, 100);
            DoUpdateWorldState(WORLD_STATE_BM, 0);
            DoUpdateWorldState(WORLD_STATE_BM_RIFT, 0);

            Events.CancelEvent(EVENT_SUMMON_PORTAL);
        }

        void OnPlayerEnter(Player* player) override
        {
            if (GetData(DATA_EVENT) != IN_PROGRESS && GetData(DATA_EVENT) != DONE)
            {
                player->SendUpdateWorldState(WORLD_STATE_BM_SHIELD, 100);
                player->SendUpdateWorldState(WORLD_STATE_BM, 0);
                player->SendUpdateWorldState(WORLD_STATE_BM_RIFT, 0);
            }
            else if (GetData(DATA_EVENT) == IN_PROGRESS)
            {
                player->SendUpdateWorldState(WORLD_STATE_BM_SHIELD, GetData(DATA_SHIELD_PCT));
                player->SendUpdateWorldState(WORLD_STATE_BM, 1);
                player->SendUpdateWorldState(WORLD_STATE_BM_RIFT, GetData(DATA_RIFT_COUNT));
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_DEJA:
                case DATA_TEMPORUS:
                    if (state == DONE)
                        SetData(DATA_RIFT, DONE);
                    break;
                case DATA_AEONUS:
                    if (state == DONE)
                    {
                        DoCastSpellOnPlayers(SPELL_THE_BLACK_MORASS_COMPLETE);
                        DoCastSpellOnPlayers(SPELL_THE_MASTERS_TOUCH_COMPLETE);
                        DoUpdateWorldState(WORLD_STATE_BM, 0);
                        SetData(DATA_EVENT, DONE);
                    }
                    break;
                default:
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_EVENT:
                    EventState = data;
                    switch (data)
                    {
                        case IN_PROGRESS:
                            DoUpdateWorldState(WORLD_STATE_BM, 1);
                            ScheduleEventNextPortal(0s);
                            if (Creature* saat = GetCreature(DATA_SAAT))
                                saat->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            break;
                        case DONE:
                            if (Creature* medivh = GetCreature(DATA_MEDIVH))
                                medivh->AI()->DoAction(ACTION_EPILOGUE);
                            if (Creature* saat = GetCreature(DATA_SAAT))
                                saat->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            break;
                        case FAIL:
                            DoResetEvent();
                            if (Creature* saat = GetCreature(DATA_SAAT))
                                saat->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            break;
                        default:
                            break;
                    }
                    break;
                case DATA_SHIELD_PCT:
                    if (data == SPECIAL && GetData(DATA_EVENT) == IN_PROGRESS)
                    {
                        --ShieldPercent;

                        DoUpdateWorldState(WORLD_STATE_BM_SHIELD, ShieldPercent);

                        switch (ShieldPercent)
                        {
                            case 75:
                                if (Creature* medivh = GetCreature(DATA_MEDIVH))
                                    medivh->AI()->DoAction(ACTION_SHIELD_75);
                                break;
                            case 50:
                                if (Creature* medivh = GetCreature(DATA_MEDIVH))
                                    medivh->AI()->DoAction(ACTION_SHIELD_50);
                                break;
                            case 25:
                                if (Creature* medivh = GetCreature(DATA_MEDIVH))
                                    medivh->AI()->DoAction(ACTION_SHIELD_25);
                                break;
                            case 0:
                                if (Creature* medivh = GetCreature(DATA_MEDIVH))
                                    medivh->AI()->DoAction(ACTION_SHIELD_0);
                                SetData(DATA_EVENT, FAIL);
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case DATA_RIFT:
                    switch (data)
                    {
                        case DONE:
                            --OpenRiftPortalsCount;
                            ScheduleEventNextPortal(125s);
                            break;
                        case SPECIAL:
                            --OpenRiftPortalsCount;
                            if (!OpenRiftPortalsCount)
                                ScheduleEventNextPortal(randtime(0s, 5s));
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_EVENT:
                    return EventState;
                case DATA_RIFT_COUNT:
                    return RiftPortalCount;
                case DATA_SHIELD_PCT:
                    return ShieldPercent;
            }

            return 0;
        }

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                case NPC_RIFT_LORD:
                case NPC_RIFT_LORD_ALT:
                case NPC_RIFT_KEEPER:
                case NPC_RIFT_KEEPER_ALT:
                    SetData(DATA_RIFT, SPECIAL);
                    break;
                case NPC_INFINITE_CHRONO_LORD:
                case NPC_INFINITE_TIMEREAVER:
                    SetData(DATA_RIFT, DONE);
                    break;
                default:
                    break;
            }
        }

        void DoSpawnPortal()
        {
            // Spells are guessed
            if (Creature* medivh = GetCreature(DATA_MEDIVH))
            {
                std::vector<uint32> availableSummonRiftSpells =
                {
                    SPELL_SUMMON_TIME_RIFT_EFFECT_1,
                    SPELL_SUMMON_TIME_RIFT_EFFECT_2,
                    SPELL_SUMMON_TIME_RIFT_EFFECT_3,
                    SPELL_SUMMON_TIME_RIFT_EFFECT_4
                };

                if (LastSummonRiftSpell)
                    std::erase(availableSummonRiftSpells, LastSummonRiftSpell);

                uint32 selectedSpell = Trinity::Containers::SelectRandomContainerElement(availableSummonRiftSpells);

                LastSummonRiftSpell = selectedSpell;

                medivh->CastSpell(nullptr, selectedSpell, true);

                ++OpenRiftPortalsCount;
            }
        }

        void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId) override
        {
            // Positions are sniffed but the way they are linked to events is guessed
            switch (eventId)
            {
                case EVENT_SUMMON_TIME_RIFT_1:
                    if (Creature* medivh = GetCreature(DATA_MEDIVH))
                        medivh->SummonCreature(NPC_TIME_RIFT, PortalPosition1, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                case EVENT_SUMMON_TIME_RIFT_2:
                    if (Creature* medivh = GetCreature(DATA_MEDIVH))
                        medivh->SummonCreature(NPC_TIME_RIFT, PortalPosition2, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                case EVENT_SUMMON_TIME_RIFT_3:
                    if (Creature* medivh = GetCreature(DATA_MEDIVH))
                        medivh->SummonCreature(NPC_TIME_RIFT, PortalPosition3, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                case EVENT_SUMMON_TIME_RIFT_4:
                    if (Creature* medivh = GetCreature(DATA_MEDIVH))
                        medivh->SummonCreature(NPC_TIME_RIFT, PortalPosition4, TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                default:
                    break;
            }
        }

        void Update(uint32 diff) override
        {
            Events.Update(diff);

            if (Events.ExecuteEvent() == EVENT_SUMMON_PORTAL)
            {
                ++RiftPortalCount;
                DoUpdateWorldState(WORLD_STATE_BM_RIFT, RiftPortalCount);
                DoSpawnPortal();
                if (RiftPortalCount != 6 && RiftPortalCount != 12 && RiftPortalCount != 18)
                    ScheduleEventNextPortal(RiftPortalCount > 12 ? 90s : 120s);
            }
        }

        void ScheduleEventNextPortal(Milliseconds nextPortalTime)
        {
            Events.RescheduleEvent(EVENT_SUMMON_PORTAL, nextPortalTime);
        }

        protected:
            EventMap Events;
            uint32 EventState;
            uint32 RiftPortalCount;
            uint32 ShieldPercent;
            uint32 LastSummonRiftSpell;
            uint32 OpenRiftPortalsCount;
    };

};

void AddSC_instance_the_black_morass()
{
    new instance_the_black_morass();
}

/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2005 - 2011 MaNGOS <http://www.getmangos.org/>
 * Copyright (C) 2008 - 2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
#include "bastion_of_twilight.h"

#define MAX_ENCOUNTER 5

class instance_the_bastion_of_twilight : public InstanceMapScript
{
public:
    instance_the_bastion_of_twilight() : InstanceMapScript("instance_the_bastion_of_twilight", 671) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_bastion_of_twilight_InstanceMapScript(map);
    }

    struct instance_the_bastion_of_twilight_InstanceMapScript: public InstanceScript
    {
        instance_the_bastion_of_twilight_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
             for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                 uiEncounter[i] = NOT_STARTED;

             uiFiendKills = 0;
             uiTeralionValionaHP = 0;
             uiAscendantCouncilPhase = 1;
        }

        bool IsEncounterInProgress() const override
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;

             return false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            Map::PlayerList const &players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                if (Player* pPlayer = players.begin()->GetSource())
                    uiTeamInInstance = pPlayer->GetTeam();
            }

            switch (creature->GetEntry())
            {
                case BOSS_WYRMBREAKER:
                    uiWyrmbreaker = creature->GetGUID();
                    if (Creature * SlateDrake = GetCreature(NPC_SLATE_DRAKE))
                    {
                        if (!SlateDrake->HasAura(SPELL_UNRESPONSIVE_DRAKE))
                        {
                            SlateDrake->AddAura(SPELL_MALEVOLENT_STRIKES,creature);
                        }
                    }
                    if (Creature * StormRider = GetCreature(NPC_STORM_RIDER))
                    {
                        if (!StormRider->HasAura(SPELL_UNRESPONSIVE_DRAKE))
                        {
                            StormRider->AddAura(SPELL_SHADOW_WARPED,creature);
                        }
                    }
                    if (Creature * NetherScion = GetCreature(NPC_NETHER_SCION))
                    {
                        if (!NetherScion->HasAura(SPELL_UNRESPONSIVE_DRAKE))
                        {
                            NetherScion->AddAura(SPELL_FRENZIED_ASSAULT,creature);
                        }
                    }
                    break;
                case BOSS_VALIONA:
                    uiValiona = creature->GetGUID();
                    break;
                case BOSS_THERALION:
                    uiTheralion = creature->GetGUID();
                    break;
                case BOSS_FELUDIUS:
                    uiFeludius = creature->GetGUID();
                    break;
                case BOSS_IGNACIOUS:
                    uiIgnacious = creature->GetGUID();
                    break;
                case BOSS_ARION:
                    uiArion = creature->GetGUID();
                    break;
                case BOSS_TERRASTRA:
                    uiTerrastra = creature->GetGUID();
                    break;
                case BOSS_MONSTROSITY:
                    uiMonstrosity = creature->GetGUID();
                    break;
                case BOSS_CHOGALL:
                    uiChogall = creature->GetGUID();
                    break;
                case BOSS_SINESRTA:
                    uiSinestra = creature->GetGUID();
                    break;
                case NPC_SLATE_DRAKE:
                    if (uiRandomDragons[0] == RANDOM_DRAGON_SLATE_DRAKE || uiRandomDragons[1] == RANDOM_DRAGON_SLATE_DRAKE)
                    {
                        creature->AddAura(SPELL_UNRESPONSIVE_DRAKE,creature);
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    }
                    uiSlateDrake = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    break;
                case NPC_STORM_RIDER:
                    if (uiRandomDragons[0] == RANDOM_DRAGON_STORM_RIDER || uiRandomDragons[1] == RANDOM_DRAGON_STORM_RIDER)
                    {
                        creature->AddAura(SPELL_UNRESPONSIVE_DRAKE,creature);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                    uiStormRider = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case NPC_NETHER_SCION:
                    if (uiRandomDragons[0] == RANDOM_DRAGON_NETHER_SCION || uiRandomDragons[1] == RANDOM_DRAGON_NETHER_SCION)
                    {
                        creature->AddAura(SPELL_UNRESPONSIVE_DRAKE,creature);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                    uiNetherScion = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case NPC_TIME_WARDEN:
                    uiTimeWarden = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                case NPC_PROTO_BEHEMOTH:
                    uiProtoBehemoth = creature->GetGUID();
                    if (Unit * TimeWarden = GetCreature(NPC_TIME_WARDEN))
                    {
                        if (!TimeWarden->HasAura(SPELL_UNRESPONSIVE_DRAKE))
                        {
                            // TimeWarden->AddAura(SPELL_DANCING_FLAMES,creature);
                        }
                    }
                    break;
                case NPC_CYCLON_WIND:
                    uiCyclonWinds = creature->GetGUID();
                    break;
            }
        }
        void SetGuidData(uint32 id, ObjectGuid data) override
        {
            switch (id)
            {
                case DATA_HB_VALIONA_THERALION:
                    uiValionaTheralionHealth = data ;
                    break;
                case DATA_ORB_0:
                    uiOrb0 = data;
                    break;
                case DATA_ORB_1:
                    uiOrb1 = data;
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_WYRMBREAKER:                  return uiWyrmbreaker;
                case DATA_VALIONA:                        return uiValiona;
                case DATA_THERALION:                    return uiTheralion;
                case DATA_FELUDIUS:                        return uiFeludius;
                case DATA_IGNACIOUS:                    return uiIgnacious;
                case DATA_ARION:                        return uiArion;
                case DATA_TERRASTRA:                    return uiTerrastra;
                case DATA_MONSTROSITY:                    return uiMonstrosity;
                case DATA_CHOGALL:                        return uiChogall;
                case DATA_SINESTRA:                     return uiSinestra;
                case DATA_HB_VALIONA_THERALION:         return uiValionaTheralionHealth;
                case DATA_ORB_0:                        return uiOrb0;
                case DATA_ORB_1:                        return uiOrb1;
                case NPC_SLATE_DRAKE:                    return uiSlateDrake;
                case NPC_STORM_RIDER:                    return uiStormRider;
                case NPC_NETHER_SCION:                    return uiNetherScion;
                case NPC_TIME_WARDEN:                    return uiTimeWarden;
                case NPC_PROTO_BEHEMOTH:                return uiProtoBehemoth;
                case NPC_CYCLON_WIND:                   return uiCyclonWinds;
            }

            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_WYRMBREAKER_EVENT:
                    uiEncounter[0] = data;
                    break;
                case DATA_VALIONA_THERALION_EVENT:
                    uiEncounter[1] = data;
                    break;
                case DATA_COUNCIL_EVENT:
                    uiEncounter[2] = data;
                    break;
                case DATA_CHOGALL_EVENT:
                    uiEncounter[3] = data;
                    break;
                case DATA_SINESTRA_EVENT:
                    uiEncounter[4] = data;
                    break;
                case DATA_VALIONA_TERALION_HP:
                    uiTeralionValionaHP = data;
                    data = 0;
                    break;
                case DATA_FIEND_KILLS:
                    uiFiendKills++;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_WYRMBREAKER_EVENT:                return uiEncounter[0];
                case DATA_VALIONA_THERALION_EVENT:            return uiEncounter[1];
                case DATA_COUNCIL_EVENT:                    return uiEncounter[2];
                case DATA_CHOGALL_EVENT:                    return uiEncounter[3];
                case DATA_SINESTRA_EVENT:                   return uiEncounter[4];
                case DATA_VALIONA_TERALION_HP:              return uiTeralionValionaHP;
                case DATA_FIEND_KILLS:                      return uiFiendKills;
            }

            return 0;
        }

        void ChangeState(ObjectGuid guid,bool active,bool finalphase)
        {
            Creature * creature = instance->GetCreature(guid);
            uint16 talkid;
            uint16 wayid;
            if (finalphase)
            {
                switch (creature->GetEntry())
                {
                case BOSS_FELUDIUS:
                    talkid = SAY_PHASE3_FELUDIUS;
                    wayid = WALK_FELUDIUS;
                    break;
                }
                creature->AI()->Talk(talkid);
                creature->UpdateWaypointID(wayid);
            }
            if (active)
            {
                creature->RemoveAura(creature->GetAura(8611,guid));
            }
            else
            {
                creature->AddAura(8611,creature);
            }
        }

        void ShiftPhase()
        {
            uiAscendantCouncilPhase++;
            if (uiAscendantCouncilPhase == 2)
            {
                ChangeState(GetGuidData(DATA_FELUDIUS),false,false);
                ChangeState(GetGuidData(DATA_IGNACIOUS),false,false);
                ChangeState(GetGuidData(DATA_ARION),true,false);
                ChangeState(GetGuidData(DATA_TERRASTRA),true,false);
            }
            else if (uiAscendantCouncilPhase == 3)
            {
            }
        }

        void Update(uint32 const diff) override
        {
            if (uiHalfusNormalTimer <= diff)
            {
                uiRandomDragons[0] = rand() % 3 +1;
                switch (uiRandomDragons[0])
                {
                    case RANDOM_DRAGON_STORM_RIDER:
                        uiRandomDragons[1] = rand() % 1 + 1;
                        break;
                    case RANDOM_DRAGON_NETHER_SCION:
                        uiRandomDragons[1] = rand() % 1 + 2;
                        if (uiRandomDragons[1] == RANDOM_DRAGON_NETHER_SCION)
                        {
                            uiRandomNumber = rand() % 10 + 1;
                            if (uiRandomNumber <= 5)
                            {
                                uiRandomDragons[1] = RANDOM_DRAGON_STORM_RIDER;
                            } else uiRandomDragons[1] = RANDOM_DRAGON_SLATE_DRAKE;
                        }
                        break;
                    case RANDOM_DRAGON_SLATE_DRAKE:
                        uiRandomDragons[1] = rand() % 1 + 2;
                        break;
                }
                uiRandomDragons[2] = rand() % 1 + 1;
            } else uiHalfusNormalTimer -= diff;
        }

    private:
        ObjectGuid uiWyrmbreaker;
        ObjectGuid uiValiona;
        ObjectGuid uiTheralion;
        ObjectGuid uiFeludius;
        ObjectGuid uiArion;
        ObjectGuid uiIgnacious;
        ObjectGuid uiTerrastra;
        ObjectGuid uiMonstrosity;
        ObjectGuid uiChogall;
        ObjectGuid uiSinestra;
        ObjectGuid uiSlateDrake;
        ObjectGuid uiStormRider;
        ObjectGuid uiNetherScion;
        ObjectGuid uiProtoBehemoth;
        ObjectGuid uiTimeWarden;
        ObjectGuid uiValionaTheralionHealth;
        ObjectGuid uiCyclonWinds;
        ObjectGuid uiOrb0;
        ObjectGuid uiOrb1;
        uint32 uiTeralionValionaHP;
        uint32 uiRandomDragons[3];
        uint32 uiRandomNumber;
        uint32 uiHalfusNormalTimer;
        uint32 uiTeamInInstance;
        uint32 uiFiendKills;
        uint32 uiEncounter[MAX_ENCOUNTER];
        uint8  uiAscendantCouncilPhase;
    };
};
void AddSC_instance_the_bastion_of_twilight()
{
    new instance_the_bastion_of_twilight();
}

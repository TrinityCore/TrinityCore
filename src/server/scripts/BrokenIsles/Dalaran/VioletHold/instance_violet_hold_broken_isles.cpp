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

#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureGroups.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "violet_hold_broken_isles.h"


Position const DefenseSystemLocation = { 4634.33056640625f, 4013.876708984375f, 123.175048828125f, 3.071779489517211914f }; // sniff

//Position const CyanigosaSpawnLocation = { 1922.109f, 804.4493f, 52.49254f, 3.176499f }; // sniff
//Position const CyanigosaJumpLocation = { 1888.32f,  804.473f,  38.3578f,  0.0f }; // sniff

//Position const SaboteurSpawnLocation = { 1886.251f, 803.0743f, 38.42326f, 3.211406f }; // sniff

uint32 const PortalPositionsSize = 5;
Position const PortalPositions[PortalPositionsSize] = // sniff
{
    { 0.f, 0.f, 0.f, 0.f }, // 0
    { 0.f, 0.f, 0.f, 0.f }, // 1
    { 0.f, 0.f, 0.f, 0.f }, // 2
    { 0.f, 0.f, 0.f, 0.f }, // 3
    { 0.f, 0.f, 0.f, 0.f }  // 4
};

uint32 const PortalElitePositionsSize = 3;
Position const PortalElitePositions[PortalElitePositionsSize] = // sniff
{
    { 0.f, 0.f, 0.f, 0.f }, // 5
    { 0.f, 0.f, 0.f, 0.f }, // 6
    { 0.f, 0.f, 0.f, 0.f }  // 7
};

uint32 const PortalIntroPositionsSize = 5;
Position const PortalIntroPositions[PortalIntroPositionsSize] = // sniff
{
    { 0.f, 0.f, 0.f, 0.f  }, // 0 - Intro
    { 0.f, 0.f, 0.f, 0.f  }, // 1 - Intro
    { 0.f, 0.f, 0.f, 0.f  }, // 2 - Intro
    { 0.f, 0.f, 0.f, 0.f  }, // 3 - Boss 1/2
    { 0.f, 0.f, 0.f, 0.f  }  // 4 - Boss 3
};

uint32 const EncouterPortalsCount = PortalPositionsSize + PortalElitePositionsSize;

uint32 const MoraggPathSize = 3;
Position const MoraggPath[MoraggPathSize] = // sniff
{
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f }
};

uint32 const ErekemPathSize = 3;
Position const ErekemPath[ErekemPathSize] = // sniff
{
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f }
};

uint32 const ErekemGuardLeftPathSize = 3;
Position const ErekemGuardLeftPath[ErekemGuardLeftPathSize] = // sniff
{
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f }
};

uint32 const ErekemGuardRightPathSize = 3;
Position const ErekemGuardRightPath[ErekemGuardRightPathSize] = // sniff
{
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f },
    { 0.f, 0.f, 0.f }
};

uint32 const IchoronPathSize = 5;
Position const IchoronPath[IchoronPathSize] = // sniff
{
    { 1942.041f, 749.5228f, 30.95229f },
    { 1930.571f, 762.9065f, 31.98814f },
    { 1923.657f, 770.6718f, 34.07256f },
    { 1910.631f, 784.4096f, 37.09015f },
    { 1906.595f, 788.3828f, 37.99429f }
};

uint32 const LavanthorPathSize = 3;
Position const LavanthorPath[LavanthorPathSize] = // sniff
{
    { 1844.557f, 748.7083f, 38.74205f },
    { 1854.618f, 761.5295f, 38.65631f },
    { 1862.17f,  773.2255f, 38.74879f }
};

uint32 const XevozzPathSize = 3;
Position const XevozzPath[XevozzPathSize] = // sniff
{
    { 1908.417f, 845.8502f, 38.71947f },
    { 1905.557f, 841.3157f, 38.65529f },
    { 1899.453f, 832.533f,  38.70752f }
};

uint32 const ZuramatPathSize = 3;
Position const ZuramatPath[ZuramatPathSize] = // sniff
{
    { 1934.151f, 860.9463f, 47.29499f },
    { 1927.085f, 852.1342f, 47.19214f },
    { 1923.226f, 847.3297f, 47.15541f }
};

enum Yells
{
    SAY_CYANIGOSA_SPAWN = 3,
    SAY_XEVOZZ_SPAWN = 3,
    SAY_EREKEM_SPAWN = 3,
    SAY_ICHORON_SPAWN = 3,
    SAY_ZURAMAT_SPAWN = 3,

    SOUND_MORAGG_SPAWN = 10112
};

enum Spells
{
    SPELL_CYANIGOSA_TRANSFORM = 58668,
    SPELL_CYANIGOSA_ARCANE_POWER_STATE = 49411,
    SPELL_MORAGG_EMOTE_ROAR = 48350,
    SPELL_LAVANTHOR_SPECIAL_UNARMED = 33334,
    SPELL_ZURAMAT_COSMETIC_CHANNEL_OMNI = 57552
};

ObjectData const creatureData[] =
{
    { NPC_FESTERFACE,            DATA_FESTERFACE            },
    { NPC_SHIVERMAW,             DATA_SHIVERMAW             },
    { NPC_BLOOD_PRINCE_THAL_ENA, DATA_BLOOD_PRINCE_THAL_ENA },
    { NPC_MINDFLAYER_HAAHRJ,     DATA_MINDFLAYER_HAAHRJ     },
    { NPC_MILLIFICENT_MANASTORM, DATA_MILLIFICENT_MANASTORM },
    { NPC_ANUB_ESSET,            DATA_ANUB_ESSET            },
    { NPC_SAEL_ORN,              DATA_SAEL_ORN              },
    { NPC_FEL_LORD_BETRUG,       NPC_FEL_LORD_BETRUG        },
    { NPC_SINCLARI,              DATA_SINCLARI              },
    { 0,                    0                               } // END
};

ObjectData const gameObjectData[] =
{
    { /*GO_EREKEM_GUARD_1_DOOR, DATA_EREKEM_LEFT_GUARD_CELL  */ },
    { /*GO_EREKEM_GUARD_2_DOOR, DATA_EREKEM_RIGHT_GUARD_CELL */ },
    { /*GO_EREKEM_DOOR,         DATA_EREKEM_CELL             */ },
    { /*GO_ZURAMAT_DOOR,        DATA_ZURAMAT_CELL            */ },
    { /*GO_LAVANTHOR_DOOR,      DATA_LAVANTHOR_CELL          */ },
    { /*GO_MORAGG_DOOR,         DATA_MORAGG_CELL             */ },
    { /*GO_ICHORON_DOOR,        DATA_ICHORON_CELL            */ },
    { /*GO_XEVOZZ_DOOR,         DATA_XEVOZZ_CELL             */ },
    { GO_MAIN_DOOR,             DATA_MAIN_DOOR                  },
    { 0,                      0                                 } // END
};

MinionData const minionData[] =
{
    { /*NPC_EREKEM_GUARD, DATA_EREKEM*/ },
    { 0,                0               } // END
};

DungeonEncounterData const encounters[] =
{
    { /*DATA_1ST_BOSS, {{ 2019 }} */ },
    { /*DATA_2ND_BOSS, {{ 2018 }} */ },
    { /*DATA_CYANIGOSA, {{ 2020 }}*/ }
};

class instance_viole_thold_broken_isles : public InstanceMapScript
{
public:
    instance_viole_thold_broken_isles() : InstanceMapScript(SCScriptName, 1544) { }

    struct instance_viole_thold_broken_isles_InstanceScript : public InstanceScript
    {
        instance_viole_thold_broken_isles_InstanceScript(InstanceMap* map) : InstanceScript(map),
            FirstBossId(*this, "FirstBossId", 0),
            SecondBossId(*this, "SecondBossId", 0)
        {

            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, gameObjectData);
            LoadMinionData(minionData);
            LoadDungeonEncounterData(encounters);

            DoorIntegrity = 100;
            WaveCount = 0;
            EventState = NOT_STARTED;

            LastPortalLocation = urand(0, EncouterPortalsCount - 1);

            Defenseless = true;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case NPC_FESTERFACE:
                for (uint8 i = 0; i < ErekemGuardCount; ++i)
                    if (ErekemGuardGUIDs[i].IsEmpty())
                    {
                        ErekemGuardGUIDs[i] = creature->GetGUID();
                        break;
                    }
                break;
            default:
                break;
            }
        }

        void OnCreatureRemove(Creature* creature) override
        {
            InstanceScript::OnCreatureRemove(creature);

            switch (creature->GetEntry())
            {
            case NPC_FESTERFACE:
                for (uint8 i = 0; i < ErekemGuardCount; ++i)
                    if (ErekemGuardGUIDs[i] == creature->GetGUID())
                    {
                        ErekemGuardGUIDs[i].Clear();
                        break;
                    }
                break;
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GO_ACTIVATION_CRYSTAL:
                for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                    if (ActivationCrystalGUIDs[i].IsEmpty())
                    {
                        ActivationCrystalGUIDs[i] = go->GetGUID();
                        break;
                    }
                break;
            default:
                break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            InstanceScript::OnGameObjectRemove(go);

            switch (go->GetEntry())
            {
            case GO_ACTIVATION_CRYSTAL:
                for (uint8 i = 0; i < ActivationCrystalCount; ++i)
                    if (ActivationCrystalGUIDs[i] == go->GetGUID())
                    {
                        ActivationCrystalGUIDs[i].Clear();
                        break;
                    }
                break;
            default:
                break;
            }
        }
    private:
        TaskScheduler Scheduler;

        static uint8 const ErekemGuardCount = 2;
        ObjectGuid ErekemGuardGUIDs[ErekemGuardCount];

        static uint8 const ActivationCrystalCount = 5;
        ObjectGuid ActivationCrystalGUIDs[ActivationCrystalCount];

        PersistentInstanceScriptValue<uint32> FirstBossId;
        PersistentInstanceScriptValue<uint32> SecondBossId;

        uint8 DoorIntegrity;
        uint8 WaveCount;
        uint8 EventState;
        uint8 LastPortalLocation;

        bool Defenseless;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_viole_thold_broken_isles_InstanceScript(map);
    }
};

struct areatrigger_violet_hold_broken_isles_entrance_conversation : AreaTriggerAI
{
    enum MiscIds
    {
        CONVERSATION_ENTRANCE = 3418
    };

    areatrigger_violet_hold_broken_isles_entrance_conversation(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;
        Conversation::CreateConversation(CONVERSATION_ENTRANCE, player, *player, player->GetGUID(), nullptr);
    }
};

void AddSC_instance_violet_hold_broken_isles()
{
    new instance_viole_thold_broken_isles();
    RegisterAreaTriggerAI(areatrigger_violet_hold_broken_isles_entrance_conversation);
}

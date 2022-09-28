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

/* ScriptData
SDName: Instance_Mount_Hyjal
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Hyjal Scripts
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "hyjal.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"

/* Battle of Mount Hyjal encounters:
0 - Rage Winterchill event
1 - Anetheron event
2 - Kaz'rogal event
3 - Azgalor event
4 - Archimonde event
*/

enum Yells
{
    YELL_ARCHIMONDE_INTRO = 8
};

ObjectData const creatureData[] =
{
    { RAGE_WINTERCHILL,   DATA_RAGEWINTERCHILL    },
    { ANETHERON,          DATA_ANETHERON          },
    { KAZROGAL,           DATA_KAZROGAL           },
    { AZGALOR,            DATA_AZGALOR            },
    { ARCHIMONDE,         DATA_ARCHIMONDE         },
    { JAINA,              DATA_JAINAPROUDMOORE    },
    { THRALL,             DATA_THRALL             },
    { TYRANDE,            DATA_TYRANDEWHISPERWIND },
    { NPC_CHANNEL_TARGET, DATA_CHANNEL_TARGET     },
    { 0,                  0                       } // END
};

class instance_hyjal : public InstanceMapScript
{
public:
    instance_hyjal() : InstanceMapScript(HyjalScriptName, 534) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_mount_hyjal_InstanceMapScript(map);
    }

    struct instance_mount_hyjal_InstanceMapScript : public InstanceScript
    {
        instance_mount_hyjal_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);

            RaidDamage = 0;
            Trash = 0;
            hordeRetreat = 0;
            allianceRetreat = 0;

            ArchiYell = false;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_HORDE_ENCAMPMENT_PORTAL:
                    HordeGate = go->GetGUID();
                    if (allianceRetreat)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    else
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_NIGHT_ELF_VILLAGE_PORTAL:
                    ElfGate = go->GetGUID();
                    if (hordeRetreat)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    else
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_ANCIENT_GEM:
                    m_uiAncientGemGUID.push_back(go->GetGUID());
                    break;
            }

            InstanceScript::OnGameObjectCreate(go);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case ARCHIMONDE:
                    if (GetBossState(DATA_AZGALOR) != DONE)
                    {
                        creature->SetVisible(false);
                        creature->SetReactState(REACT_PASSIVE);
                    }
                    break;
            }

            InstanceScript::OnCreatureCreate(creature);
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_RESET_TRASH_COUNT:
                    Trash = 0;
                    break;
                case DATA_TRASH:
                    if (data)
                        Trash = data;
                    else
                        Trash--;
                    DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, Trash);
                    break;
                case TYPE_RETREAT:
                    if (data == SPECIAL)
                    {
                        if (!m_uiAncientGemGUID.empty())
                        {
                            for (GuidList::const_iterator itr = m_uiAncientGemGUID.begin(); itr != m_uiAncientGemGUID.end(); ++itr)
                            {
                                //don't know how long it expected
                                DoRespawnGameObject(*itr, 24h);
                            }
                        }
                    }
                    break;
                case DATA_ALLIANCE_RETREAT:
                    allianceRetreat = data;
                    HandleGameObject(HordeGate, true);
                    SaveToDB();
                    break;
                case DATA_HORDE_RETREAT:
                    hordeRetreat = data;
                    HandleGameObject(ElfGate, true);
                    SaveToDB();
                    break;
                case DATA_RAIDDAMAGE:
                    RaidDamage += data;
                    if (RaidDamage >= MINRAIDDAMAGE)
                        RaidDamage = MINRAIDDAMAGE;
                    break;
                case DATA_RESET_RAIDDAMAGE:
                    RaidDamage = 0;
                    break;
            }

            TC_LOG_DEBUG("scripts", "Instance Hyjal: Instance data updated for event %u (Data=%u)", type, data);
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_AZGALOR:
                    if (state == DONE)
                    {
                        instance->LoadGrid(5581.49f, -3445.63f);
                        if (Creature* archimonde = GetCreature(DATA_ARCHIMONDE))
                        {
                            archimonde->SetVisible(true);
                            archimonde->SetReactState(REACT_AGGRESSIVE);

                            if (!ArchiYell)
                            {
                                ArchiYell = true;
                                archimonde->AI()->Talk(YELL_ARCHIMONDE_INTRO);
                            }
                        }
                    }
                    break;
            }

            return true;
        }

        void ReadSaveDataMore(std::istringstream& loadStream) override
        {
            loadStream >> allianceRetreat >> hordeRetreat >> RaidDamage;
        }

        void WriteSaveDataMore(std::ostringstream& saveStream) override
        {
            saveStream << allianceRetreat << ' ' << hordeRetreat << ' ' << RaidDamage;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TRASH:                return Trash;
                case DATA_ALLIANCE_RETREAT:     return allianceRetreat;
                case DATA_HORDE_RETREAT:        return hordeRetreat;
                case DATA_RAIDDAMAGE:           return RaidDamage;
            }
            return 0;
        }

        protected:
            GuidList m_uiAncientGemGUID;
            ObjectGuid HordeGate;
            ObjectGuid ElfGate;
            uint32 Trash;
            uint32 hordeRetreat;
            uint32 allianceRetreat;
            uint32 RaidDamage;
            bool ArchiYell;
    };
};

void AddSC_instance_mount_hyjal()
{
    new instance_hyjal();
}

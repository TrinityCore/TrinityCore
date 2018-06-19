/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "the_everbloom.h"

class instance_everbloom : public InstanceMapScript
{
public:
    instance_everbloom() : InstanceMapScript(CoSScriptName, 1279) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_everbloom_instancemapscript(map);
    }

    struct instance_everbloom_instancemapscript : public InstanceScript
    {
        instance_everbloom_instancemapscript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(EncounterCount);
        }

        ObjectGuid m_TaluGUID;
        ObjectGuid m_GolaGUID;
        ObjectGuid m_DulhuGUID;
        ObjectGuid m_WitherbarkGUID;
        ObjectGuid m_ArchmagesolGUID;
        ObjectGuid m_XeritacGUID;
        ObjectGuid m_YalnuGUID;
        uint32 m_CountGUID;

        std::vector<ObjectGuid> m_portalVisualCreatureGuid;

        void Initialize() override
        {
            m_CountGUID = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_WITHERBARK:
                    m_WitherbarkGUID = creature->GetGUID();
                    break;
                case NPC_EARTHSHAPER_TELU:
                    m_TaluGUID = creature->GetGUID();
                    break;
                case NPC_LIFE_WARDEN_GOLA:
                    m_GolaGUID = creature->GetGUID();
                    break;
                case NPC_DULHU:
                    m_DulhuGUID = creature->GetGUID();
                    break;
                case NPC_ARCHMAGE_SOL:
                    m_ArchmagesolGUID = creature->GetGUID();
                    break;
                case NPC_XERITAC:
                    m_XeritacGUID = creature->GetGUID();
                    break;
                case NPC_YALNU:
                    m_YalnuGUID = creature->GetGUID();
                    break;
                case NPC_SLG_GENERIC_MOP:
                    m_portalVisualCreatureGuid.push_back(creature->GetGUID());
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            /*switch (creature->GetEntry())
            {
                case NPC_YALNU:
                    if (creature->GetMap()->IsHeroic())
                    {
                        instance->DoCompleteAchievement(eEverbloomAchievements::AchivementTheEverbloomHeroic);
                    }
                    else
                    {
                        instance->DoCompleteAchievement(eEverbloomAchievements::AchievementTheEverbloomNormal);
                    }
                    break;
            }*/
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_EARTHSHAPER_TELU:
                    return m_TaluGUID;
                case DATA_LIFE_WARDEN_GOLA:
                    return m_GolaGUID;
                case DATA_DULHU:
                    return m_DulhuGUID;
                case DATA_WITHERBARK:
                    return m_WitherbarkGUID;
                case DATA_ARCHMAGE_SOL:
                    return m_ArchmagesolGUID;
                case DATA_XERITAC:
                    return m_XeritacGUID;
                case DATA_YALNU:
                    return m_YalnuGUID;
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_ARCHMAGE_SOL:
                {
                    for (ObjectGuid portalVisualGuid : m_portalVisualCreatureGuid)
                        if (Creature* portalVisual = instance->GetCreature(portalVisualGuid))
                            portalVisual->AddAura(169147, portalVisual);
                }
            }

            return true;
        }
    };
};

void AddSC_instance_everbloom()
{
    new instance_everbloom();
}

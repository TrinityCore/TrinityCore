/*
    http://uwow.biz
    Paladin Specialization: Retribution
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "broken_shore.h"

class instance_broken_shore : public InstanceMapScript
{
public:
    instance_broken_shore() : InstanceMapScript("instance_broken_shore", 1500) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_broken_shore_InstanceMapScript(map);
    }

    struct instance_broken_shore_InstanceMapScript : public InstanceScript
    {
        instance_broken_shore_InstanceMapScript(Map* map) : InstanceScript(map) {}

        std::list<Creature*> trashGUIDconteiner;
        std::list<GameObject*> DoorGUIDconteiner;
        ObjectGuid tyrosusGUID;
        uint8 alliesFight;

        void Initialize() override
        {
            trashGUIDconteiner.clear();
            DoorGUIDconteiner.clear();
            tyrosusGUID.Clear();

            alliesFight = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_ARGENT_PHALANX_1:
                case NPC_ARGENT_PHALANX_2:
                case NPC_ARGENT_DAWNBRINGER_1:
                case NPC_ARGENT_DAWNBRINGER_2:
                case NPC_RIGHTEOUS_CRUSADER_1:
                case NPC_RIGHTEOUS_CRUSADER_2:
                case NPC_RIGHTEOUS_CRUSADER_3:
                case NPC_WRATHGUARD_CLEAVER_1:
                case NPC_WRATHGUARD_CLEAVER_2:
                case NPC_RAVENOUS_FELSTALKER_1:
                case NPC_RAVENOUS_FELSTALKER_2:
                    if (creature->GetAreaId() == 7797)
                        trashGUIDconteiner.push_back(creature);
                    break;
                case NPC_LORD_MAXWELL_TYROSUS:
                    tyrosusGUID = creature->GetGUID();
                    break;
            }
        }

        void OnCreatureRemove(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_ARGENT_PHALANX_1:
                case NPC_ARGENT_PHALANX_2:
                case NPC_ARGENT_DAWNBRINGER_1:
                case NPC_ARGENT_DAWNBRINGER_2:
                case NPC_RIGHTEOUS_CRUSADER_1:
                case NPC_RIGHTEOUS_CRUSADER_2:
                case NPC_RIGHTEOUS_CRUSADER_3:
                case NPC_WRATHGUARD_CLEAVER_1:
                case NPC_WRATHGUARD_CLEAVER_2:
                case NPC_RAVENOUS_FELSTALKER_1:
                case NPC_RAVENOUS_FELSTALKER_2:
                    trashGUIDconteiner.remove(creature);
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_ZERUS_DOOR:
                case GO_BOSS_ZERUS_DOOR_1:
                case GO_BOSS_ZERUS_DOOR_2:
                    DoorGUIDconteiner.push_back(go);
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_TRASH_FIGHT:
                    alliesFight = data;
                    if (!trashGUIDconteiner.empty())
                        for (auto trash : trashGUIDconteiner)
                        {
                            if (trash && trash->IsInWorld() && trash->isAlive())
                            {
                                if (!trash->isInCombat())
                                    trash->AI()->DoZoneInCombat(trash, 100.0f);

                                if (trash->getFaction() == 1665)
                                {
                                    Position pos;
                                    trash->GetNearPosition(pos, 20.0f, 0.0f);
                                    trash->SetHomePosition(pos);
                                }
                            }
                        }
                    break;
                case DATA_KILL_TRASH:
                {
                    if (!trashGUIDconteiner.empty())
                        for (std::list<Creature*>::iterator itr = trashGUIDconteiner.begin(); itr != trashGUIDconteiner.end(); ++itr)
                        {
                            if (!(*itr) || !(*itr)->IsInWorld() || !(*itr)->isAlive())
                                continue;

                            (*itr)->Kill(*itr);
                        }
                    break;
                }
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TRASH_FIGHT:
                    return alliesFight;
                default:
                    return 0;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_LORD_MAXWELL_TYROSUS:
                    return tyrosusGUID;
                default:
                    return ObjectGuid::Empty;
            }
        }

        void onScenarionNextStep(uint32 newStep) override
        {
            switch (newStep)
            {
                case DATA_STAGE_3:
                    for (auto go : DoorGUIDconteiner)
                        if (go->GetEntry() == GO_ZERUS_DOOR)
                            HandleGameObject(go->GetGUID(), true);
                    break;
            }
        }

        void CreatureDies(Creature* creature, Unit* /*killer*/) override
        {
            switch (creature->GetEntry())
            {
                case NPC_BURNING_CRUSHER:
                    DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52858); //+12
                    break;
                case NPC_MOARG_BRUTALIZER:
                    DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52845); //+8
                    break;
                case NPC_WRATHGUARD_CLEAVER_1:
                case NPC_WRATHGUARD_CLEAVER_2:
                    DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52846); //+5
                    break;
                case NPC_RAVENOUS_FELSTALKER_1:
                case NPC_RAVENOUS_FELSTALKER_2:
                    DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 52847); //+3
                    break;
                case NPC_JAILER_ZERUS_BOSS:
                    DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46064); //Set Stage 4
                    for (auto go : DoorGUIDconteiner)
                    {
                        if (go->GetEntry() == GO_BOSS_ZERUS_DOOR_1)
                            HandleGameObject(go->GetGUID(), true);
                        if (go->GetEntry() == GO_BOSS_ZERUS_DOOR_2)
                            go->SetPhaseMask(1, true);
                    }
                    break;
            }
        }

        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_broken_shore()
{
    new instance_broken_shore();
}

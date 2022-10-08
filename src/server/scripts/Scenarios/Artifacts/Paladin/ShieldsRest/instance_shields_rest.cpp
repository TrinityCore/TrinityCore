/*
    http://uwow.biz
    Paladin Specialization: Protection
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shields_rest.h"



class instance_shields_rest : public InstanceMapScript
{
public:
    instance_shields_rest() : InstanceMapScript("instance_shields_rest", 1495) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shields_rest_InstanceMapScript(map);
    }

    struct instance_shields_rest_InstanceMapScript : public InstanceScript
    {
        instance_shields_rest_InstanceMapScript(Map* map) : InstanceScript(map) {}

        std::list<GameObject*> goDoorList;
        std::list<ObjectGuid> trashList;
        ObjectGuid eventDoorGUID;

        uint8 cryptstalkersDiedCount;
        uint8 windshaperDiedCount;
        uint8 igrimEvent;

        uint8 count_kills;
        uint8 count_kills1;
        uint16 scenarioid;

        void Initialize() override
        {
            goDoorList.clear();
            trashList.clear();
            eventDoorGUID.Clear();

            cryptstalkersDiedCount = 0;
            windshaperDiedCount = 0;
            igrimEvent = 0;
            count_kills = 0;
            count_kills1 = 0;
            scenarioid = 0;
        }

        void OnPlyerEnter(Player* player)
        {
            if (!player)
                return;

            player->AddDelayedEvent(3000, [player, this]() -> void
            {
                scenarioid = player->GetScenarioId();
            });
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_INVISIBLE_MAN:
                case NPC_ORIK_TRUEHEART_PET:
                case NPC_CATO_PET:
                    trashList.push_back(creature->GetGUID());
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_FIRST_DOOR:
                    goDoorList.push_back(go);
                    break;
                case GO_EVENT_DOOR:
                    eventDoorGUID = go->GetGUID();
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            if (unit->GetTypeId() == TYPEID_PLAYER)
            {
                unit->RemoveAurasDueToSpell(SPELL_SUMMON_ORIK);
                unit->RemoveAurasDueToSpell(SPELL_SUMMON_CATO);

                if (getScenarionStep() == DATA_STAGE_3)
                {
                    if (GameObject* go = instance->GetGameObject(eventDoorGUID))
                    {
                        go->ResetDoorOrButton();
                        go->SetLootState(GO_NOT_READY);
                    }
                }
            }

            switch (unit->GetEntry())
            {
                case NPC_INNA_THE_CRYPTSTALKER:
                case NPC_DRAKE_SHAE:
                {
                    cryptstalkersDiedCount++;
                    if (cryptstalkersDiedCount == 2)
                    {
                        if (!goDoorList.empty())
                            for (auto go : goDoorList)
                            {
                                if (go->GetDistance(doorPos[0]) < go->GetDistance(doorPos[1]))
                                    HandleGameObject(go->GetGUID(), true);
                            }
                        if (!trashList.empty())
                            for (auto trashGuid : trashList)
                            {
                                if (trashGuid.GetEntry() == NPC_INVISIBLE_MAN)
                                    if (Creature* wind = instance->GetCreature(trashGuid))
                                        wind->CastSpell(wind, SPELL_SPIRIT_WINDS_AT, true);
                            }
                    }
                    break;
                }
                case NPC_SPECTRAL_WINDSHAPER:
                    windshaperDiedCount++;
                    if (windshaperDiedCount == 3)
                    {
                        if (!trashList.empty())
                            for (auto trashGuid : trashList)
                            {
                                if (trashGuid.GetEntry() == NPC_INVISIBLE_MAN)
                                    if (Creature* wind = instance->GetCreature(trashGuid))
                                    {
                                        wind->RemoveAurasDueToSpell(SPELL_SPIRIT_WINDS_AT);
                                        wind->RemoveAllAreaObjects();
                                    }
                            }
                        if (GetData(DATA_YRGRIM_EVENT) == 2)
                            SetData(DATA_YRGRIM_EVENT, 3);
                    }
                    break;
                case 94813:
                    count_kills++;
                    if (count_kills == 2)
                    {
                        if (GameObject* go = unit->FindNearestGameObject(243541, 70.0f))
                            go->SetPhaseMask(4, true);
                        if (Creature* targ = unit->FindNearestCreature(96468, 100.0f, true))
                            targ->AI()->DoAction(1);
                    }
                    break;
                case 96455:
                    if (unit->GetPositionX() <= 4800.0f)
                        count_kills1++;
                    if (count_kills1 == 2)
                    {
                        if (Player* pl = unit->FindNearestPlayer(100.0f))
                            pl->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 46358);
                        if (GameObject* go = unit->FindNearestGameObject(243897, 70.0f))
                            go->SetPhaseMask(4, true);
                        if (GameObject* go = unit->FindNearestGameObject(248777, 70.0f))
                            go->SetPhaseMask(4, true);
                        if (Creature* targ = unit->FindNearestCreature(96468, 150.0f, true))
                            targ->AI()->DoAction(2);
                    }
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_YRGRIM_EVENT:
                {
                    igrimEvent = data;
                    if (!trashList.empty())
                        for (auto supportGuid : trashList)
                        {
                            if (supportGuid.GetEntry() == NPC_ORIK_TRUEHEART_PET || supportGuid.GetEntry() == NPC_CATO_PET)
                            {
                                if (Creature* support = instance->GetCreature(supportGuid))
                                {
                                    if (data == 2)
                                        support->CastSpell(support, SPELL_FIERCE_WINDS_STUN, true);
                                    else if (data == 3)
                                        support->RemoveAurasDueToSpell(SPELL_FIERCE_WINDS_STUN);
                                    else if (data == 5)
                                    {
                                        if (GameObject* go = instance->GetGameObject(eventDoorGUID))
                                            go->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_IN_USE);
                                    }
                                }
                            }
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
                case DATA_YRGRIM_EVENT:
                    return igrimEvent;
                default:
                    return 0;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return ObjectGuid::Empty;
            }
        }

        void ProcessEvent(WorldObject* obj, uint32 eventId) override
        {
            switch (eventId)
            {
                case 50566:
                    if (getScenarionStep() == DATA_STAGE_3)
                    {
                        DoUpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 50566); //Step 4
                        if (!goDoorList.empty())
                            for (auto go : goDoorList)
                            {
                                if (go->GetDistance(doorPos[1]) < go->GetDistance(doorPos[0]))
                                    HandleGameObject(go->GetGUID(), true);
                            }
                    }
                    if (GameObject* go = instance->GetGameObject(eventDoorGUID))
                        go->Delete();
                    break;
                case 50545:
                {
                    for (auto supportGuid : trashList)
                    {
                        if (supportGuid.GetEntry() == NPC_ORIK_TRUEHEART_PET || supportGuid.GetEntry() == NPC_CATO_PET)
                            if (Creature* support = instance->GetCreature(supportGuid))
                                support->AI()->DoAction(true);
                    }
                    break;
                }
                default:
                    break;
            }
        }

        void onScenarionNextStep(uint32 newStep) override
        {
            if (scenarioid && scenarioid != 1082)
                return;

            switch (newStep)
            {
                case DATA_STAGE_2:
                    DoCastSpellOnPlayers(SPELL_SUMMON_ORIK);
                    DoCastSpellOnPlayers(SPELL_SUMMON_CATO);
                    break;
            }
        }

        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_shields_rest()
{
    new instance_shields_rest();
}

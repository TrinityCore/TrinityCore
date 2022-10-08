/*
 * Copyright (C) 2022 BfaCore Reforged
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

 /*scenario_defense_of_aviana*/
enum DataTypes
{
    DATA_SKYLORD_SHADEGROVE = 0,
    DATA_MAX_ENCOUNTERS = 1,

    DATA_ILLYSANNA_PREEVENT_LOWER = 5,
    DATA_ILLYSANNA_PREEVENT_UPPER = 6,

    DATA_STAIRS_BOULDER_1 = 7,
    DATA_STAIRS_BOULDER_2 = 8,

    SCENARIO_ID = 1306,
    DATA_STEP_1 = 3195,
    DATA_STEP_2 = 3207,
    DATA_STEP_3 = 3208,
    DATA_STEP_4 = 3215,
    DATA_STEP_5 = 3209,

    NPC_SKYLORD_SHADEGROVE = 119808,
    NPC_TALONGUARD_LIFEGROWER = 119807,
    NPC_TALONGUARD_THORNHIDE = 119806,
    NPC_TALONGUARD_STALKER = 119805,
    NPC_TALONGUARD_STARCALLER = 119804,
    NPC_ISARA_RIVERSTRIDE = 50068,
    NPC_JANDUNEL_REEDWIND = 50070,
    NPC_DINORAE_SWIFTFEATHER = 119843,

    NPC_DARK_LOOTER = 121330,
    NPC_VOIDFLAME_TRICKSTER = 121328,
    NPC_WARBRINGER_FELBLADE = 119801,
    NPC_PLAGUERIDDEN_TRICKSTER = 121329,
    NPC_FELBOUND_TRICKSTER = 119802,
    NPC_DREAD_VANGUARD = 119810,
    NPC_DARK_PILLAGER = 119816,
    NPC_FLAMESPITTER = 119817,
    NPC_DARK_TRAPPER = 119812,
    NPC_FROZENSOUL_INTERROGATOR = 119815,


};
struct scenario_defense_of_aviana : public InstanceScript
{
    scenario_defense_of_aviana(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        talkednpc = false;
        backtopos = false;
        events.ScheduleEvent(DATA_STEP_1, 3s);

        SetData(DATA_SKYLORD_SHADEGROVE, NOT_STARTED);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        creature->SetFullHealth();

        if (creature->isDead())
            return;

        switch (creature->GetEntry())
        {
            case NPC_TALONGUARD_LIFEGROWER:
            case NPC_TALONGUARD_THORNHIDE:
            case NPC_TALONGUARD_STALKER:
            case NPC_TALONGUARD_STARCALLER:
            case NPC_ISARA_RIVERSTRIDE:
            case NPC_JANDUNEL_REEDWIND:
            case NPC_DINORAE_SWIFTFEATHER:
            {
                //creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                m_guardMobs.push_back(creature->GetGUID());
                break;
            }
            case NPC_SKYLORD_SHADEGROVE:
            {
                GUID_SKYLORD_SHADEGROVE = creature->GetGUID();
                break;
            }
            case NPC_DARK_LOOTER:
            case NPC_VOIDFLAME_TRICKSTER:
            case NPC_WARBRINGER_FELBLADE:
            case NPC_PLAGUERIDDEN_TRICKSTER:
            case NPC_FELBOUND_TRICKSTER:
            case NPC_DREAD_VANGUARD:
            case NPC_DARK_PILLAGER:
            case NPC_FLAMESPITTER:
            case NPC_DARK_TRAPPER:
            case NPC_FROZENSOUL_INTERROGATOR:
            {
                //creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                m_targetMobs.push_back(creature->GetGUID());
                break;
            }


        }
    }

    void OnUnitDeath(Unit* unit) override
    {
        if (!unit->IsCreature())
            return;

        switch (unit->GetEntry())
        {
        case NPC_TALONGUARD_LIFEGROWER:
        case NPC_TALONGUARD_THORNHIDE:
        case NPC_TALONGUARD_STALKER:
        case NPC_TALONGUARD_STARCALLER:
        case NPC_ISARA_RIVERSTRIDE:
        case NPC_JANDUNEL_REEDWIND:
        case NPC_DINORAE_SWIFTFEATHER:
        {
            //creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
            m_guardMobs.remove(unit->GetGUID());
            break;
        }
        case NPC_SKYLORD_SHADEGROVE:
        {
            SetData(DATA_SKYLORD_SHADEGROVE, DONE);
            break;
        }
        case NPC_DARK_LOOTER:
        case NPC_VOIDFLAME_TRICKSTER:
        case NPC_WARBRINGER_FELBLADE:
        case NPC_PLAGUERIDDEN_TRICKSTER:
        case NPC_FELBOUND_TRICKSTER:
        case NPC_DREAD_VANGUARD:
        case NPC_DARK_PILLAGER:
        case NPC_FLAMESPITTER:
        case NPC_DARK_TRAPPER:
        case NPC_FROZENSOUL_INTERROGATOR:
        {
            //creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
            m_targetMobs.remove(unit->GetGUID());
            break;
        }


        }

        if (m_targetMobs.size() == 0)
        {
           // SetData(DATA_SKYLORD_SHADEGROVE, DONE);
        }
    }

    void Update(uint32 diff) override
    {
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
            case DATA_STEP_1:
            {
                if (Creature* creaturenpc = instance->GetCreature(GUID_SKYLORD_SHADEGROVE))
                {
                    Player* player = creaturenpc->GetCharmerOrOwnerPlayerOrPlayerItself();

                    if (creaturenpc->IsWithinDist(player, 15.0f, false))
                    {
                        SetStepStatus(DATA_STEP_2);
                    }
                }
                if (talkednpc)
                {
                    events.CancelEvent(DATA_STEP_1);
                    //l_InstanceScript->SendScenarioState = DATA_STEP_2;
                    SetData(DATA_SKYLORD_SHADEGROVE, IN_PROGRESS);
                    events.ScheduleEvent(DATA_STEP_2, 3s);
                    break;
                }
                events.Repeat(4s);
                break;
            }
            case DATA_STEP_2:
            {
                if (m_targetMobs.size() == 0)
                {
                    events.CancelEvent(DATA_STEP_2);

                    for (ObjectGuid guid : m_guardMobs)
                    {

                        if (Creature* creature = instance->GetCreature(guid) )
                        {
                            creature->KillSelf();
                        }
                    }
                    //l_InstanceScript->SendScenarioState = DATA_STEP_3;
                    SetData(DATA_SKYLORD_SHADEGROVE, IN_PROGRESS);
                    events.ScheduleEvent(DATA_STEP_3, 3s);
                    break;
                }
                events.Repeat(4s);
                break;
            }
            case DATA_STEP_3:
            {
                if (Creature* creaturenpc = instance->GetCreature(GUID_SKYLORD_SHADEGROVE))
                {
                    Player* player = creaturenpc->GetCharmerOrOwnerPlayerOrPlayerItself();

                    if (creaturenpc->IsWithinDist(player, 15.0f, false))
                    {
                        SetStepStatus(DATA_STEP_4);
                    }
                }
                if (backtopos)
                {
                    events.CancelEvent(DATA_STEP_3);

                    //l_InstanceScript->SendScenarioState = DATA_STEP_4;
                    SetData(DATA_SKYLORD_SHADEGROVE, IN_PROGRESS);
                    events.ScheduleEvent(DATA_STEP_4, 3s);
                    break;
                }
                events.Repeat(4s);
                break;
            }
            case DATA_STEP_4:
            {
                if (Creature* creaturenpc = instance->GetCreature(GUID_SKYLORD_SHADEGROVE))
                {
                    creaturenpc->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    creaturenpc->GetMotionMaster()->MovePoint(0, 4917.127441f, -2745.260742f, 1437.6278f);
                    creaturenpc->SetFacingTo(2.855686f);

                    creaturenpc->GetMotionMaster()->MovePoint(1, 4902.825195f, -2754.8247f, 1437.6128f);
                    creaturenpc->SetFacingTo(0.737466f);
                    //creaturenpc->SetFaction(0);
                    //creaturenpc->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE| UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                }

                    events.CancelEvent(DATA_STEP_4);
                    events.ScheduleEvent(DATA_STEP_5, 5s);
                    break;


                break;
            }
            case DATA_STEP_5:
            {
                //l_InstanceScript->SendScenarioState = DATA_STEP_5;
                SetData(DATA_SKYLORD_SHADEGROVE, DONE);
                break;
            }


        }
    }

    void SetStepStatus(uint32 step)
    {
        switch (step)
        {
            case DATA_STEP_2:
            {
                talkednpc = true;
                break;
            }
            case DATA_STEP_4:
            {
                backtopos = true;
                break;
            }
        }

    }
private:

    EventMap events;
    bool talkednpc;
    bool backtopos;
    ObjectGuid GUID_SKYLORD_SHADEGROVE;
    std::list<ObjectGuid> m_guardMobs;
    std::list<ObjectGuid> m_targetMobs;

};

void AddSC_scenario_defense_of_aviana()
{
    RegisterInstanceScript(scenario_defense_of_aviana, 1730);
}

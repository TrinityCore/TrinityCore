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

#include "GameObject.h"
#include "InstanceScript.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "VMapFactory.h"
#include "mogu_shan_palace.h"

class instance_mogu_shan_palace : public InstanceMapScript
{
public:
    instance_mogu_shan_palace() : InstanceMapScript("instance_mogu_shan_palace", 994) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_mogu_shan_palace_InstanceMapScript(map);
    }

    struct instance_mogu_shan_palace_InstanceMapScript : public InstanceScript
    {
        /*
        ** Trial of the king.
        */
        ObjectGuid xin_GUID;
        ObjectGuid kuai_GUID;
        ObjectGuid ming_GUID;
        ObjectGuid haiyan_GUID;
        std::list<ObjectGuid> scrappers;
        std::list<ObjectGuid> adepts;
        std::list<ObjectGuid> grunts;
        /*
        ** End of the trial of the king.
        */
        /*
        ** Gekkan.
        */
        ObjectGuid gekkan;
        ObjectGuid glintrok_ironhide;
        ObjectGuid glintrok_skulker;
        ObjectGuid glintrok_oracle;
        ObjectGuid glintrok_hexxer;
        /*
        ** End of Gekkan.
        */
        /*
        ** Xin the weaponmaster.
        */
        std::list<ObjectGuid> animated_staffs;
        std::list<ObjectGuid> animated_axes;
        std::list<ObjectGuid> swordLauncherGuids;
        /*
        ** End of Xin the weaponmaster.
        */

        ObjectGuid doorBeforeTrialGUID;
        ObjectGuid trialChestGUID;
        ObjectGuid doorAfterTrialGUID;
        ObjectGuid doorBeforeKingGUID;

        instance_mogu_shan_palace_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
            xin_GUID = ObjectGuid::Empty;
            kuai_GUID = ObjectGuid::Empty;
            ming_GUID = ObjectGuid::Empty;
            haiyan_GUID = ObjectGuid::Empty;

            doorBeforeTrialGUID = ObjectGuid::Empty;
            trialChestGUID = ObjectGuid::Empty;
            doorAfterTrialGUID = ObjectGuid::Empty;
            doorBeforeKingGUID = ObjectGuid::Empty;

            gekkan = ObjectGuid::Empty;
            glintrok_ironhide = ObjectGuid::Empty;
            glintrok_skulker = ObjectGuid::Empty;
            glintrok_oracle = ObjectGuid::Empty;
            glintrok_hexxer = ObjectGuid::Empty;
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_TRIAL_OF_THE_KING:
                    HandleGameObject(doorBeforeTrialGUID, state != IN_PROGRESS);
                    if (GameObject* chest = instance->GetGameObject(trialChestGUID))
                    {
                        if (state == DONE)
                            PhasingHandler::ResetPhaseShift(chest);
                        else
                            PhasingHandler::AddPhase(chest, 176);
                    }
                    break;
                case DATA_GEKKAN:
                    HandleGameObject(doorAfterTrialGUID, state == DONE);
                    // Todo : mod temp portal phasemask
                    break;
                case DATA_XIN_THE_WEAPONMASTER:
                    HandleGameObject(doorBeforeTrialGUID, state != IN_PROGRESS);
                    break;
            }

            return true;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_DOOR_BEFORE_TRIAL:
                    doorBeforeTrialGUID = go->GetGUID();
                    break;
                case GO_TRIAL_CHEST:
                    trialChestGUID = go->GetGUID();
                    PhasingHandler::AddPhase(go, 176);
                    break;
                case GO_DOOR_AFTER_TRIAL:
                    doorAfterTrialGUID = go->GetGUID();
                    break;
                case GO_DOOR_BEFORE_KING:
                    doorBeforeKingGUID = go->GetGUID();
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            OnCreatureCreate_gekkan(creature);
            OnCreatureCreate_trial_of_the_king(creature);
            OnCreatureCreate_xin_the_weaponmaster(creature);
        }

        void OnUnitDeath(Unit* unit) override
        {
            OnUnitDeath_gekkan(unit);
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_GEKKAN_ADDS:
                    if (Creature* pGekkan = instance->GetCreature(gekkan))
                    {
                        if (Unit * target = pGekkan->SelectNearestTarget(100.0f))
                        {
                            pGekkan->AI()->AttackStart(target);

                            if (Creature* ironhide = instance->GetCreature(glintrok_ironhide))
                                ironhide->AI()->AttackStart(target);

                            if (Creature* skulker = instance->GetCreature(glintrok_skulker))
                                skulker->AI()->AttackStart(target);

                            if (Creature* oracle = instance->GetCreature(glintrok_oracle))
                                oracle->AI()->AttackStart(target);

                            if (Creature* hexxer = instance->GetCreature(glintrok_hexxer))
                                hexxer->AI()->AttackStart(target);
                        }
                    }
                    break;
            }

            SetData_trial_of_the_king(type, data);
            SetData_xin_the_weaponmaster(type, data);
        }

        uint32 GetData(uint32 /*type*/) const override
        {
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case TYPE_GET_ENTOURAGE_0:
                return glintrok_hexxer;
            case TYPE_GET_ENTOURAGE_1:
                return glintrok_ironhide;
            case TYPE_GET_ENTOURAGE_2:
                return glintrok_oracle;
            case TYPE_GET_ENTOURAGE_3:
                return glintrok_skulker;
            }
            return ObjectGuid::Empty;
        }

        void SetData_xin_the_weaponmaster(uint32 type, uint32 data)
        {
            switch (type)
            {
                case TYPE_ACTIVATE_ANIMATED_STAFF:
                {
                    if (Creature* creature = instance->GetCreature(Trinity::Containers::SelectRandomContainerElement(animated_staffs)))
                        if (creature->GetAI())
                            creature->GetAI()->DoAction(0); //ACTION_ACTIVATE
                    break;
                }
                case TYPE_ACTIVATE_ANIMATED_AXE:
                {
                    for (auto guid : animated_axes)
                    {
                        if (Creature* creature = instance->GetCreature(guid))
                        {
                            if (data)
                            {
                                creature->AddAura(SPELL_AXE_TOURBILOL, creature);
                                creature->AddAura(SPELL_PERMANENT_FEIGN_DEATH, creature);
                                creature->GetMotionMaster()->MoveRandom(50.0f);
                            }
                            else
                            {
                                creature->RemoveAurasDueToSpell(SPELL_AXE_TOURBILOL);
                                creature->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                                creature->GetMotionMaster()->MoveTargetedHome();
                            }
                        }
                    }
                    break;
                }
                case TYPE_ACTIVATE_SWORD:
                {
                    Position center;
                    center.Relocate(-4632.39f, -2613.20f, 22.0f);

                    bool randPos = urand(0, 1);

                    /*     Y
                           -
                       ***********
                       -> 1 * 2 <-
                     + *********** - X
                       -> 3 * 4 <-
                       ***********
                           +         */

                    for (auto itr: swordLauncherGuids)
                    {
                        bool mustActivate = false;

                        if (Creature* launcher = instance->GetCreature(itr))
                        {
                            if (randPos) // Zone 2 & 3
                            {
                                if ((launcher->GetPositionX() > center.GetPositionX() && launcher->GetPositionY() > center.GetPositionY())
                                    || (launcher->GetPositionX() < center.GetPositionX() && launcher->GetPositionY() < center.GetPositionY()))
                                    mustActivate = true;
                            }
                            else // Zone 1 & 4
                            {
                                if ((launcher->GetPositionX() > center.GetPositionX() && launcher->GetPositionY() < center.GetPositionY())
                                    || (launcher->GetPositionX() < center.GetPositionX() && launcher->GetPositionY() > center.GetPositionY()))
                                    mustActivate = true;
                            }

                            if (data && mustActivate)
                                launcher->AddAura(SPELL_THROW_AURA, launcher);
                            else
                                launcher->RemoveAurasDueToSpell(SPELL_THROW_AURA);
                        }
                    }
                }
                break;
            }
        }

        void OnCreatureCreate_xin_the_weaponmaster(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case 59481:
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case CREATURE_ANIMATED_STAFF:
                    animated_staffs.push_back(creature->GetGUID());
                    break;
                case CREATURE_ANIMATED_AXE:
                    animated_axes.push_back(creature->GetGUID());
                    creature->SetReactState(REACT_PASSIVE);
                    creature->SetVirtualItem(0, 30316);
                    break;
                case CREATURE_LAUNCH_SWORD:
                    swordLauncherGuids.push_back(creature->GetGUID());
                    creature->AddAura(SPELL_PERMANENT_FEIGN_DEATH, creature);
                    break;
            }
        }

        void OnUnitDeath_gekkan(Unit* unit)
        {
            if (unit->ToCreature())
            {
                switch (unit->ToCreature()->GetEntry())
                {
                    case CREATURE_GLINTROK_IRONHIDE:
                    case CREATURE_GLINTROK_SKULKER:
                    case CREATURE_GLINTROK_ORACLE:
                    case CREATURE_GLINTROK_HEXXER:
                    {
                        if (Creature* c = instance->GetCreature(gekkan))
                            if (c->GetAI())
                                c->GetAI()->DoAction(0); //ACTION_ENTOURAGE_DIED
                    }
                    break;
                }
            }
        }

        void OnCreatureCreate_gekkan(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case CREATURE_GEKKAN:
                    gekkan = creature->GetGUID();
                    break;
                case CREATURE_GLINTROK_IRONHIDE:
                    glintrok_ironhide = creature->GetGUID();
                    break;
                case CREATURE_GLINTROK_SKULKER:
                    glintrok_skulker = creature->GetGUID();
                    break;
                case CREATURE_GLINTROK_ORACLE:
                    glintrok_oracle = creature->GetGUID();
                    break;
                case CREATURE_GLINTROK_HEXXER:
                    glintrok_hexxer = creature->GetGUID();
                    break;
            }
        }

        void SetData_trial_of_the_king(uint32 type, uint32 data)
        {
            switch (type)
            {
                case TYPE_OUTRO_05:
                    {
                        if (Creature* haiyan = instance->GetCreature(haiyan_GUID))
                            if (haiyan->GetAI())
                                haiyan->GetAI()->DoAction(1); //ACTION_OUTRO_02
                    }
                    break;
                case TYPE_OUTRO_04:
                    {
                        if (Creature* kuai = instance->GetCreature(kuai_GUID))
                            if (kuai->GetAI())
                                kuai->GetAI()->DoAction(3); //ACTION_OUTRO_02
                    }
                    break;
                case TYPE_OUTRO_03:
                    {
                        if (Creature* ming = instance->GetCreature(ming_GUID))
                            if (ming->GetAI())
                                ming->GetAI()->DoAction(2); //ACTION_OUTRO_02
                    }
                    break;
                case TYPE_OUTRO_02:
                    {
                        if (Creature* haiyan = instance->GetCreature(haiyan_GUID))
                            if (haiyan->GetAI())
                                haiyan->GetAI()->DoAction(0); //ACTION_OUTRO_01
                    }
                    break;
                case TYPE_OUTRO_01:
                    {
                        if (Creature* ming = instance->GetCreature(ming_GUID))
                            if (ming->GetAI())
                                ming->GetAI()->DoAction(1); //ACTION_OUTRO_01
                    }
                    break;
                case TYPE_MING_INTRO:
                    {
                        if (Creature* ming = instance->GetCreature(ming_GUID))
                            if (ming->GetAI())
                                ming->GetAI()->DoAction(0); //ACTION_INTRO
                    }
                    break;
                case TYPE_WIPE_FIRST_BOSS:
                    {
                        Creature* xin = instance->GetCreature(xin_GUID);
                        if (!xin)
                            return;
                        xin->SetVisible(true);
                        if (xin->GetAI())
                            xin->GetAI()->Reset();
                        switch (data)
                        {
                        case 0:
                            for (auto guid : adepts)
                            {
                                Creature* creature = instance->GetCreature(guid);
                                if (!creature)
                                    continue;

                                if (creature && creature->GetAI())
                                    creature->GetAI()->DoAction(1); //EVENT_RETIRE
                                creature->RemoveAura(121569);
                            }
                            break;
                        case 1:
                            for (auto guid : scrappers)
                            {
                                Creature* creature = instance->GetCreature(guid);
                                if (!creature)
                                    continue;

                                if (creature && creature->GetAI())
                                    creature->GetAI()->DoAction(1); //EVENT_RETIRE
                                creature->RemoveAura(121569);
                            }
                            break;
                        case 2:
                            for (auto guid : grunts)
                            {
                                Creature* creature = instance->GetCreature(guid);
                                if (!creature)
                                    continue;

                                if (creature && creature->GetAI())
                                    creature->GetAI()->DoAction(1); //EVENT_RETIRE
                                creature->RemoveAura(121569);
                            }
                            break;
                        }
                    }
                    break;
                case TYPE_MING_ATTACK:
                    {
                        //Move the adepts
                        for (auto guid : adepts)
                        {
                            Creature* creature = instance->GetCreature(guid);

                            if (creature && creature->GetAI())
                                creature->GetAI()->DoAction(0); //EVENT_ENCOURAGE
                        }
                        Creature* ming = instance->GetCreature(ming_GUID);
                        if (!ming)
                            return;
                        ming->GetMotionMaster()->MovePoint(0, -4237.658f, -2613.860f, 16.48f);
                        ming->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        ming->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                case TYPE_KUAI_ATTACK:
                    {
                        //Move the scrappers
                        for (auto guid : scrappers)
                        {
                            Creature* creature = instance->GetCreature(guid);

                            if (creature && creature->GetAI())
                                creature->GetAI()->DoAction(0); //EVENT_ENCOURAGE
                        }
                        Creature* kuai = instance->GetCreature(kuai_GUID);
                        if (!kuai)
                            return;
                        kuai->GetMotionMaster()->MovePoint(0, -4215.359f, -2601.283f, 16.48f);
                        kuai->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        kuai->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                case TYPE_HAIYAN_ATTACK:
                    {
                        //Move the scrappers
                        for (auto guid : grunts)
                        {
                            Creature* creature = instance->GetCreature(guid);

                            if (creature && creature->GetAI())
                                creature->GetAI()->DoAction(0); //EVENT_ENCOURAGE
                        }
                        Creature* haiyan = instance->GetCreature(haiyan_GUID);
                        if (!haiyan)
                            return;
                        haiyan->GetMotionMaster()->MovePoint(0, -4215.772f, -2627.216f, 16.48f);
                        haiyan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        haiyan->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                case TYPE_ALL_ATTACK:
                    {
                        for (auto guid : adepts)
                        {
                            Creature* creature = instance->GetCreature(guid);

                            if (creature && creature->GetAI())
                                creature->GetAI()->DoAction(2); //ACTION_ATTACK

                            std::list<ObjectGuid>::iterator itr = grunts.begin();
                            std::advance(itr, urand(0, grunts.size() - 1));

                            Creature* grunt = instance->GetCreature(*itr);
                            if (creature && grunt)
                                creature->Attack(grunt, true);
                        }
                        for (auto guid : grunts)
                        {
                            Creature* creature = instance->GetCreature(guid);

                            if (creature && creature->GetAI())
                                creature->GetAI()->DoAction(2); //ACTION_ATTACK

                            std::list<ObjectGuid>::iterator itr = scrappers.begin();
                            std::advance(itr, urand(0, scrappers.size() - 1));

                            Creature* scrapper = instance->GetCreature(*itr);
                            if (creature && scrapper)
                                creature->Attack(scrapper, true);
                        }
                        for (auto guid : scrappers)
                        {
                            Creature* creature = instance->GetCreature(guid);

                            if (creature && creature->GetAI())
                                creature->GetAI()->DoAction(2); //ACTION_ATTACK

                            if (!adepts.empty())
                            {
                                std::list<ObjectGuid>::iterator itr = adepts.begin();

                                if (adepts.size() > 1)
                                    std::advance(itr, urand(0, adepts.size() - 1));

                                Creature* adept = instance->GetCreature(*itr);
                                if (creature && adept)
                                    creature->Attack(adept, true);
                            }
                        }

                        SetBossState(DATA_TRIAL_OF_THE_KING, DONE);
                    }
                    break;
                case TYPE_MING_RETIRED:
                    //Retire the adepts
                    for (auto guid : adepts)
                    {
                        Creature* creature = instance->GetCreature(guid);

                        if (creature && creature->GetAI())
                            creature->GetAI()->DoAction(1); //EVENT_RETIRE
                    }
                    break;
                case TYPE_KUAI_RETIRED:
                    //Retire the adepts
                    for (auto guid : scrappers)
                    {
                        Creature* creature = instance->GetCreature(guid);

                        if (creature && creature->GetAI())
                            creature->GetAI()->DoAction(1); //EVENT_RETIRE
                    }
                    break;
                case TYPE_HAIYAN_RETIRED:
                    //Retire the adepts
                    for (auto guid : grunts)
                    {
                        Creature* creature = instance->GetCreature(guid);

                        if (creature && creature->GetAI())
                            creature->GetAI()->DoAction(1); //EVENT_RETIRE
                    }
                    break;
            }
        }

        void OnCreatureCreate_trial_of_the_king(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case CREATURE_GURTHAN_SCRAPPER:
                    scrappers.push_back(creature->GetGUID());
                    break;
                case CREATURE_HARTHAK_ADEPT:
                    adepts.push_back(creature->GetGUID());
                    break;
                case CREATURE_KARGESH_GRUNT:
                    grunts.push_back(creature->GetGUID());
                    break;
                case CREATURE_KUAI_THE_BRUTE:
                    kuai_GUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case CREATURE_MING_THE_CUNNING:
                    ming_GUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case CREATURE_HAIYAN_THE_UNSTOPPABLE:
                    haiyan_GUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case CREATURE_XIN_THE_WEAPONMASTER_TRIGGER:
                    xin_GUID = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case CREATURE_WHIRLING_DERVISH:
                    break;
            }
        }
    };

};

class go_mogushan_palace_temp_portal : public GameObjectScript
{
public:
    go_mogushan_palace_temp_portal() : GameObjectScript("go_mogushan_palace_temp_portal") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetPositionZ() < 0.0f)
            player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), 22.31f, go->GetOrientation());
        else
            player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), -39.0f, go->GetOrientation());

        return false;
    }
};

void AddSC_instance_mogu_shan_palace()
{
    new instance_mogu_shan_palace();
    new go_mogushan_palace_temp_portal();
}

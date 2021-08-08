/*
    http://uwow.biz
    Invasion Azsuna
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class instance_invasion_HM : public InstanceMapScript
{
public:
    instance_invasion_HM() : InstanceMapScript("instance_invasion_HM", 1706) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_invasion_HM_InstanceMapScript(map);
    }

    struct instance_invasion_HM_InstanceMapScript : public InstanceScript
    {
        instance_invasion_HM_InstanceMapScript(Map* map) : InstanceScript(map) {}

        WorldLocation loc_res_pla;  // for respawn

        uint32 countAdds;
        uint32 NumWave;
        ObjectGuid Geomant_guid;
        ObjectGuid Mayla_guid;

        void Initialize() override
        {
            countAdds = 0;
            NumWave = 1;
            Geomant_guid.Clear();
            Mayla_guid.Clear();
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!player)
                return;
            
            if (player->GetQuestStatus(46182) != QUEST_STATUS_INCOMPLETE)
            {
                player->AddDelayedEvent(2000, [player]() -> void
                {
                    player->TeleportTo(1220, -834.95f, 4277.59f, 746.25f, 1.0f);
                });
                return;
            }

            player->AddDelayedEvent(5000, [player]() -> void
            {
                player->CreateConversation(4676);
            });
        }

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1706);

            uint32 graveyardId = 0;

            if (getScenarionStep() <= 5)
                graveyardId = 5945;
            else
                graveyardId = 5946;

            if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
                loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                loc_res_pla.SetMapId(gy->MapID);
            }

            return &loc_res_pla;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            if (creature->GetEntry() == 119942)
                Geomant_guid = creature->GetGUID();
            if (creature->GetEntry() == 119850)
                Mayla_guid = creature->GetGUID();
        }

        void OnUnitDeath(Unit* creature) override
        {
            switch (creature->GetEntry())
            {
                case 119859:
                case 120097:
                case 120099:
                    updateCriteriaForPlayers(57173);
                    break;
                case 119959:
                    updateCriteriaForPlayers(57595);
                    break;
                case 120060:
                case 119860:
                    if (getScenarionStep() == 2)
                    {
                        countAdds--;
                        if (countAdds == 0)
                        {
                            updateCriteriaForPlayers(57182);
                            DoSummonAdds(NumWave++);
                        }
                    }
                    break;
            }
        }

        void updateCriteriaForPlayers(int32 objective)
        {
            Map::PlayerList const &PlList = instance->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                {
                    if (objective > 0)
                        player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, objective);
                    else
                        player->CreateConversation(abs(objective));
                    break;
                }
        }

        void onScenarionNextStep(uint32 newStep) override
        {
            switch (newStep)
            {
                case 1:
                    updateCriteriaForPlayers(-4677);
                    break;
                case 2:
                    DoSummonAdds(NumWave++);
                    break;
                case 3:
                    if (Creature* geom = instance->GetCreature(Geomant_guid))
                    {
                        geom->SummonCreature(119957, 4100.27f, 4432.45f, 666.99f, 0.0f);
                        geom->SummonCreature(119959, 4083.18f, 4385.35f, 670.62f, 0.0f);
                        geom->Kill(geom);
                    }
                    if (Creature* mayla = instance->GetCreature(Mayla_guid))
                        mayla->AI()->Talk(2);
                    break;
                case 4:
                    if (Creature* mayla = instance->GetCreature(Mayla_guid))
                    {
                        mayla->AI()->Talk(3);
                        mayla->AI()->DoAction(1);
                    }
                    break;
                case 8:
                    updateCriteriaForPlayers(-4686);
                    break;
                case 10:
                    updateCriteriaForPlayers(-4690);
                    break;
            }
        }

        void DoSummonAdds(uint8 id)
        {
            if (id == 1)
            {
                if (Creature* cre = instance->GetCreature(Geomant_guid))
                {
                    if (Creature* add = cre->SummonCreature(120060, 4057.25f, 4434.91f, 665.91f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    if (Creature* add = cre->SummonCreature(120060, 4100.33f, 4436.91f, 665.91f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    if (Creature* add = cre->SummonCreature(119860, 4143.27f, 4396.79f, 666.76f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    countAdds = 3;

                    cre->CastSpell(cre, 71467);
                }
            }
            else if (id == 2)
            {
                if (Creature* mayla = instance->GetCreature(Mayla_guid))
                {
                    if (Creature* add = mayla->SummonCreature(120060, 4057.25f, 4434.91f, 665.91f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    if (Creature* add = mayla->SummonCreature(120060, 4100.33f, 4436.91f, 665.91f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    if (Creature* add = mayla->SummonCreature(119860, 4057.25f, 4434.91f, 665.91f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    if (Creature* add = mayla->SummonCreature(119860, 4100.33f, 4436.91f, 665.91f, 0.0f))
                    {
                        if (Creature* targ = add->FindNearestCreature(119854, 80.0f, true))
                            add->AI()->AttackStart(targ);
                    }
                    countAdds = 4;
                    mayla->AI()->Talk(1);
                    mayla->SummonCreature(119957, 4132.62f, 4398.68f, 667.63f);
                }
            }
        }
    };
};

void AddSC_instance_invasion_HM()
{
    new instance_invasion_HM();
}

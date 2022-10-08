/*
    http://uwow.biz
    BrokenShore
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class instance_AssaultBrokenShore : public InstanceMapScript
{
public:
    instance_AssaultBrokenShore() : InstanceMapScript("instance_AssaultBrokenShore", 1666) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_AssaultBrokenShore_InstanceMapScript(map);
    }

    struct instance_AssaultBrokenShore_InstanceMapScript : public InstanceScript
    {
        instance_AssaultBrokenShore_InstanceMapScript(Map* map) : InstanceScript(map) {}

        WorldLocation loc_res_pla;  // for respawn

        GuidList FriendlyMisc;

        ObjectGuid Arganot_guid;
        ObjectGuid Illidan_guid;
        ObjectGuid Mefistrot_guid;

        void Initialize() override
        {
            Arganot_guid.Clear();
            Mefistrot_guid.Clear();
            Illidan_guid.Clear();

            FriendlyMisc.clear();
        }

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1666);

            return &loc_res_pla;
        }

        void OnUnitDeath(Unit* creature) override
        {
            switch (creature->GetEntry())
            {
                case 116291:
                    updateCriteriaForPlayers(56500);
                    break;
                case 118551:
                    updateCriteriaForPlayers(56780);
                    break;
                    // 1
                case 118654:
                case 118453:
                case 118886:
                case 118456:
                    updateCriteriaForPlayers(56697);
                    break;
                    // 3
                case 120511:
                case 118711:
                case 118644:
                case 118647:
                case 118645:
                case 118656:
                case 118655:
                case 118708:
                case 118658:
                case 118563:
                case 118659:
                case 118646:
                case 118650:
                case 118648:
                case 118652:
                case 118653:
                case 118707:
                case 118688:
                case 118457:
                case 118416:
                    for (uint8 i = 0; i < urand(2, 3); i++)
                        updateCriteriaForPlayers(56779);
                    break;
                case 120746:
                    onScenarionNextStep(8);
                    break;
            }
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!player)
                return;

            player->CastSpell(player, 240155);

            player->AddDelayedEvent(5000, [player]() -> void
            {
                player->CastSpell(player, 243303); // summon

                std::list<Creature*> trash;
                GetCreatureListWithEntryInGrid(trash, player, 118412, 50.0f);
                for (std::list<Creature*>::iterator itr = trash.begin(); itr != trash.end(); ++itr)
                    (*itr)->CastSpell(*itr, 243303); // summon

                player->AddDelayedEvent(4000, [player]() -> void
                {
                    player->RemoveAura(240188);
                    player->CreateConversation(4526);
                });
            });
        }

        void updateCriteriaForPlayers(uint32 objective)
        {
            Map::PlayerList const &PlList = instance->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                {
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, objective);
                    break;
                }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case 119133:
                case 118412:
                case 121232:
                case 118966:
                case 121146:
                case 118969:
                case 118945:
                case 118444:
                    FriendlyMisc.push_back(creature->GetGUID());
                    break;
                case 118551:
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                    creature->SetVisible(false);
                    Arganot_guid = creature->GetGUID();
                    break;
                case 119130:
                    Illidan_guid = creature->GetGUID();
                    break;
                case 120746:
                    creature->SetVisible(false);
                    Mefistrot_guid = creature->GetGUID();
                    break;
            }
        }

        void onScenarionNextStep(uint32 newStep) override
        {
            switch (newStep)
            {
                case 4:
                {
                    if (Creature* arganot = instance->GetCreature(Arganot_guid))
                    {
                        arganot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                        arganot->SetVisible(true);
                        arganot->GetMotionMaster()->Clear();
                        if (Creature* illidan = instance->GetCreature(Illidan_guid))
                        {
                            arganot->GetMotionMaster()->MovePoint(0, illidan->GetPositionX(), illidan->GetPositionY(), illidan->GetPositionZ());
                            illidan->AI()->AttackStart(arganot);
                            arganot->AI()->AttackStart(illidan);
                        }
                    }
                    for (auto guid : FriendlyMisc)
                    {
                        if (Creature* cre = instance->GetCreature(guid))
                        {
                            cre->GetMotionMaster()->Clear();
                            cre->GetMotionMaster()->MovePath(11322709, false, irand(-8, 8), irand(-8, 8));
                        }
                    }
                    break;
                }
                case 20: // custom
                {
                    for (auto guid : FriendlyMisc)
                    {
                        if (Creature* cre = instance->GetCreature(guid))
                        {
                            cre->GetMotionMaster()->Clear();
                            cre->GetMotionMaster()->MovePath(11322707, false, irand(-8, 8), irand(-8, 8));
                        }
                    }
                    break;
                }
                case 2:
                {
                    Map::PlayerList const &PlList = instance->GetPlayers();

                    if (PlList.isEmpty())
                        return;

                    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                        if (Player* player = i->getSource())
                        {
                            player->CreateConversation(4829);
                            player->AddDelayedEvent(5000, [player]() -> void
                            {
                                player->CreateConversation(4831);
                            });

                            player->AddDelayedEvent(7000, [player]() -> void
                            {
                                player->CreateConversation(4832);
                            });
                            break;
                        }

                    for (auto guid : FriendlyMisc)
                    {
                        if (Creature* cre = instance->GetCreature(guid))
                        {
                            if (cre->GetPositionZ() <= 34.36f && cre->GetPositionX() <= -1524.42f) // only on the shore
                            {
                                cre->GetMotionMaster()->Clear();
                                cre->GetMotionMaster()->MovePath(11322705, false, irand(-5, 5), irand(-5, 5));
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    Map::PlayerList const &PlList = instance->GetPlayers();

                    if (PlList.isEmpty())
                        return;

                    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                        if (Player* player = i->getSource())
                        {
                            player->CreateConversation(4887);
                            break;
                        }

                    for (auto guid : FriendlyMisc)
                    {
                        if (Creature* cre = instance->GetCreature(guid))
                        {
                            if (cre->GetPositionY() >= 3144.0f)
                            {
                                cre->GetMotionMaster()->Clear();
                                cre->GetMotionMaster()->MovePath(11322706, false, irand(-5, 5), irand(-5, 5));
                            }
                        }
                    }
                    break;
                }
                case 7:
                {
                    if (Creature* mefistrot = instance->GetCreature(Mefistrot_guid))
                    {
                        mefistrot->SetVisible(true);
                        mefistrot->CreateConversation(4870);
                    }
                    break;
                }
                case 8:
                {
                    Map::PlayerList const &PlList = instance->GetPlayers();

                    if (PlList.isEmpty())
                        return;

                    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                        if (Player* player = i->getSource())
                        {
                            player->AddDelayedEvent(4000, [player]() -> void
                            {
                                player->CreateConversation(4892);
                                player->CompleteQuest(46734);
                            });

                            player->AddDelayedEvent(4000, [player]() -> void
                            {
                                player->CastSpell(player, 243824);
                            });
                        }

                    break;
                }
            }
        }
    };
};

void AddSC_instance_AssaultBrokenShore()
{
    new instance_AssaultBrokenShore();
}

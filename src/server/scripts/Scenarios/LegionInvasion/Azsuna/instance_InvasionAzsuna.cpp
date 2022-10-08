/*
    http://uwow.biz
    Invasion Azsuna
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class instance_InvasionAzsuna : public InstanceMapScript
{
public:
    instance_InvasionAzsuna() : InstanceMapScript("instance_InvasionAzsuna", 1705) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_InvasionAzsuna_InstanceMapScript(map);
    }

    struct instance_InvasionAzsuna_InstanceMapScript : public InstanceScript
    {
        instance_InvasionAzsuna_InstanceMapScript(Map* map) : InstanceScript(map) {}

        WorldLocation loc_res_pla;  // for respawn
        ObjectGuid bombarder_guid;
        uint32 BombsTimer;

        void Initialize() override
        {
            bombarder_guid.Clear();
            BombsTimer = urand(45000, 90000);
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!player)
                return;

            if (player->GetQuestStatus(46199) != QUEST_STATUS_INCOMPLETE)
            {
                player->AddDelayedEvent(2000, [player]() -> void
                {
                    player->TeleportTo(1220, -834.95f, 4277.59f, 746.25f, 1.0f);
                });
                return;
            }
            
            player->AddDelayedEvent(5000, [player]() -> void
            {
                player->CreateConversation(4587);
            });
        }

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1705);

            uint32 graveyardId = 0;

            if (getScenarionStep() >= 3)
                graveyardId = 5918;
            else
                graveyardId = 5917;

            if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
                loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                loc_res_pla.SetMapId(gy->MapID);
            }

            return &loc_res_pla;
        }

        void OnUnitDeath(Unit* creature) override
        {
            switch (creature->GetEntry())
            {
                case 119515:
                case 119516:
                case 119517:
                case 119466:
                case 119467:
                    updateCriteriaForPlayers(urand(1, 2) == 1 ? 56887 : 56888);
                    break;
            }
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
            if (creature->GetEntry() == 119130)
                bombarder_guid = creature->GetGUID();
        }

        void Update(uint32 diff) override
        {
            if (getScenarionStep() >= 2)
                return;

            if (BombsTimer <= diff)
            {
                if (Creature* bomber = instance->GetCreature(bombarder_guid))
                {
                    bomber->AI()->ZoneTalk(0);
                    Map::PlayerList const& players = instance->GetPlayers();

                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* player = itr->getSource())
                        {
                            if (player->isAlive() && !player->isGameMaster())
                                bomber->CastSpell(player, 235084);
                        }
                    }
                }
                BombsTimer = urand(45000, 90000);
            }
            else BombsTimer -= diff;
        }
    };
};

void AddSC_instance_InvasionAzsuna()
{
    new instance_InvasionAzsuna();
}

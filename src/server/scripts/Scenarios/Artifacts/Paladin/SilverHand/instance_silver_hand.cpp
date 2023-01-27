/*
    http://uwow.biz
    Paladin Specialization: Holy
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"


class instance_silver_hand : public InstanceMapScript
{
public:
    instance_silver_hand() : InstanceMapScript("instance_silver_hand", 1539) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_silver_hand_InstanceMapScript(map);
    }

    struct instance_silver_hand_InstanceMapScript : public InstanceScript
    {
        instance_silver_hand_InstanceMapScript(Map* map) : InstanceScript(map) {}

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case 106094:
                    if (creature->HasAura(211502))
                        creature->SetVisible(false);
                    break;
            }
        }

        WorldLocation loc_res_pla;

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        {
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1539);

            uint32 graveyardId = 5281;

            if (graveyardId)
            {
                if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
                {
                    loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                    loc_res_pla.SetMapId(gy->MapID);
                }
            }
            return &loc_res_pla;
        }
        
        void onScenarionNextStep(uint32 newStep) override
        {
            if (newStep == 8)
            {
                Map::PlayerList const &PlList = instance->GetPlayers();
                if (PlList.isEmpty())
                    return;
                
                for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                {
                    Player* player = i->getSource();
                    if (!player || !player->CanContact())
                        continue;

                    if (Creature* travar = player->FindNearestCreature(106676, 70.0f, true))
                        travar->AI()->DoAction(true);
                    break;
                }
            }
            if (newStep == 10)
            {
                Map::PlayerList const &PlList = instance->GetPlayers();

                if (PlList.isEmpty())
                    return;
                
                for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                {
                    Player* player = i->getSource();
                    if (!player || !player->CanContact())
                        continue;

                    if (Creature* travar = player->FindNearestCreature(106777, 70.0f, true))
                        travar->AI()->Talk(3);
                    if (Creature* boss = player->FindNearestCreature(106719, 70.0f, true))
                    {
                        boss->CastSpell(boss, 215260);
                        boss->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC| UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    }
                    break;
                }
            }
        }
    };
};

void AddSC_instance_silver_hand()
{
    new instance_silver_hand();
}

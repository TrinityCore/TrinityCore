/*
    http://uwow.biz
    Scenarios Instance Scripts
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

//rogue dreadblades 1545
struct instance_dreadblades : public InstanceScript
{
    instance_dreadblades(InstanceMap* map) : InstanceScript(map) {}
    
    WorldLocation loc_res_pla;

    WorldLocation* GetClosestGraveYard(float x, float y, float z) override
    {
        loc_res_pla.Relocate(x, y, z);
        loc_res_pla.SetMapId(1545);

        uint32 graveyardId = 5299;

        switch (getScenarionStep())
        {
        case 0:
        case 1:
        case 2:
            graveyardId = 5299;
            break;
        case 3:
        case 4:
            graveyardId = 5360;
            break;
        }

        if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
        {
            loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            loc_res_pla.SetMapId(gy->MapID);
        }
        return &loc_res_pla;
    }
};

// mage violethold 1494
struct instance_violethold_mage : public InstanceScript
{
    instance_violethold_mage(InstanceMap* map) : InstanceScript(map) {}

    WorldLocation loc_res_pla;

    WorldLocation* GetClosestGraveYard(float x, float y, float z) override
    {
        loc_res_pla.Relocate(x, y, z);
        loc_res_pla.SetMapId(1494);

        uint32 graveyardId = 5294;

        if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
        {
            loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            loc_res_pla.SetMapId(gy->MapID);
        }
        return &loc_res_pla;
    }
};

//mage & priest nexus 1583
struct instance_priest_mage_nexus_art : public InstanceScript
{
    instance_priest_mage_nexus_art(InstanceMap* map) : InstanceScript(map) {}

    WorldLocation loc_res_pla;

    WorldLocation* GetClosestGraveYard(float x, float y, float z) override
    {
        loc_res_pla.Relocate(x, y, z);
        loc_res_pla.SetMapId(1583);

        uint32 graveyardId = 5442;

        if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
        {
            loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            loc_res_pla.SetMapId(gy->MapID);
        }
        return &loc_res_pla;
    }
};

//nightborne open quest scenario 1840
struct instance_nightborne_sunwell : public InstanceScript
{
    instance_nightborne_sunwell(InstanceMap* map) : InstanceScript(map) {}

    WorldLocation loc_res_pla;

    WorldLocation* GetClosestGraveYard(float x, float y, float z) override
    {
        loc_res_pla.Relocate(x, y, z);
        loc_res_pla.SetMapId(1840);

        uint32 graveyardId = 6303;

        if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
        {
            loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            loc_res_pla.SetMapId(gy->MapID);
        }
        return &loc_res_pla;
    }
};

// frostmage
struct instance_faronaar_mage : public InstanceScript
{
    instance_faronaar_mage(InstanceMap* map) : InstanceScript(map) {}

    WorldLocation loc_res_pla;

    WorldLocation* GetClosestGraveYard(float x, float y, float z) override
    {
        loc_res_pla.Relocate(x, y, z);
        loc_res_pla.SetMapId(1616);

        uint32 graveyardId = 5511;

        if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
        {
            loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            loc_res_pla.SetMapId(gy->MapID);
        }
        return &loc_res_pla;
    }
};

// feraldruid
struct instance_ruins_of_falanaar_feral : public InstanceScript
{
    instance_ruins_of_falanaar_feral(InstanceMap* map) : InstanceScript(map) {}

    WorldLocation loc_res_pla;

    WorldLocation* GetClosestGraveYard(float x, float y, float z) override
    {
        loc_res_pla.Relocate(x, y, z);
        loc_res_pla.SetMapId(1612);

        uint32 graveyardId = 5514;

        if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
        {
            loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
            loc_res_pla.SetMapId(gy->MapID);
        }
        return &loc_res_pla;
    }
};

//116849
struct npc_stormstout_brewer_q45404 : public ScriptedAI
{
    npc_stormstout_brewer_q45404(Creature* creature) : ScriptedAI(creature) 
    {
        me->SetReactState(REACT_PASSIVE);
        detoxed = false;
    }

    bool detoxed;

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if ((spell->Id == 218164 || spell->Id == 115450) && !detoxed)
        {
            if (auto plr = caster->ToPlayer())
            {
                detoxed = true;
                Talk(0);
                plr->UpdateAchievementCriteria(CRITERIA_TYPE_KILL_CREATURE, 117025, 1, 0, plr, true);
                me->GetMotionMaster()->MoveRandom(12.f);
                me->DespawnOrUnsummon(7000);
            }
        }
    }
};

void AddSC_instance_class_art_scenarios()
{
    RegisterInstanceScript(instance_dreadblades, 1583);
    RegisterInstanceScript(instance_violethold_mage, 1545);
    RegisterInstanceScript(instance_priest_mage_nexus_art, 1583);
    RegisterInstanceScript(instance_nightborne_sunwell, 1840);
    RegisterInstanceScript(instance_faronaar_mage, 1616);
    RegisterInstanceScript(instance_ruins_of_falanaar_feral, 1612);
    RegisterCreatureAI(npc_stormstout_brewer_q45404);
}
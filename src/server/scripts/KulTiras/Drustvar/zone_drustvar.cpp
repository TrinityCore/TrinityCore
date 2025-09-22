/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "Conversation.h"
#include "ConversationAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum ReallyBigProblemData
{
    NPC_SUMMONED_THORNGUARD_IRONCLAW    = 140049,

    CONVO_ACTOR_THORNGUARD_IRONCLAW     = 65120,

    SPELL_DISMISS_TRADEWIND             = 274789
};

// 8790 - Conversation
class conversation_drustvar_really_big_problem_complete : public ConversationAI
{
public:
    conversation_drustvar_really_big_problem_complete(Conversation* conversation) : ConversationAI(conversation) {}

    void OnCreate(Unit* creator) override
    {
        Creature* thornguardIronclaw = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMONED_THORNGUARD_IRONCLAW, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!thornguardIronclaw)
            return;

        thornguardIronclaw->SetReactState(REACT_PASSIVE);
        thornguardIronclaw->SetImmuneToAll(true);

        conversation->AddActor(CONVO_ACTOR_THORNGUARD_IRONCLAW, 0, thornguardIronclaw->GetGUID());
        conversation->Start();
    }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();

        conversation->m_Events.AddEvent([conversation = conversation]()
        {
            Creature* thornguardIronclaw = conversation->GetActorCreature(0);
            if (!thornguardIronclaw)
                return;

            thornguardIronclaw->GetMotionMaster()->MovePoint(0, thornguardIronclaw->GetFirstCollisionPosition(20.0f, 0));
            thornguardIronclaw->CastSpell(thornguardIronclaw, SPELL_DISMISS_TRADEWIND, TRIGGERED_IGNORE_CAST_TIME);
        }, conversation->GetLastLineEndTime(privateOwnerLocale) + 3s);
    }
};

// 274789 - Dismiss Tradewind
class spell_drustvar_dismiss_tradewind : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* hitUnit = GetHitCreature())
        {
            if (hitUnit->GetEntry() == NPC_SUMMONED_THORNGUARD_IRONCLAW)
                hitUnit->DespawnOrUnsummon(2s);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_dismiss_tradewind::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ShootWickermanData
{
    // Creature
    NPC_DRUSTVAR_CHARGING_FAMILIAR      = 137841,
    NPC_FLETCHERS_HOLLOW_CONSCRIPT      = 126478,

    // Actions
    ACTION_SPAWN_CHARGING_FAMILIAR      = 0,

    // Spells
    SPELL_DRUSTVAR_SHOOT_WICKERMAN      = 255416,
    SPELL_DRUSTVAR_SHADOW_DISSOLVE_IN   = 237758,

    // Paths
    PATH_CHARGING_FAMILIAR_PATH         = 13784100, // until 13784112
};

struct ChargingFamiliarData
{
    Position SpawnPos;
    uint32 PathID;
};

ChargingFamiliarData ChargingFamiliarDatas[] = {
    { { -1107.751708984375f, 1306.234375f, 4.272790431976318359f, 5.828217506408691406f }, PATH_CHARGING_FAMILIAR_PATH + 0 },
    { { -1110.071166992187f, 1309.272583f, 4.426310539245605468f, 5.856356143951416015f }, PATH_CHARGING_FAMILIAR_PATH + 1 },
    { { -1115.628540039062f, 1270.461791f, 11.99121379852294921f, 4.980997085571289062f }, PATH_CHARGING_FAMILIAR_PATH + 2 },
    { { -1021.048583984375f, 1227.489624f, 7.336474418640136718f, 1.443549275398254394f }, PATH_CHARGING_FAMILIAR_PATH + 3 },
    { { -1107.543457031250f, 1310.699707f, 4.048464298248291015f, 5.869964599609375356f }, PATH_CHARGING_FAMILIAR_PATH + 4 },
    { { -1116.659790039062f, 1267.369750f, 12.42689323425292968f, 5.907102108001708984f }, PATH_CHARGING_FAMILIAR_PATH + 5 },
    { { -1107.930541992187f, 1318.392333f, 4.017061710357666015f, 5.871676445007324218f }, PATH_CHARGING_FAMILIAR_PATH + 6 },
    { { -1004.663208007812f, 1240.963500f, 6.007450103759765625f, 2.687578678131103515f }, PATH_CHARGING_FAMILIAR_PATH + 7 },
    { { -1109.645874023437f, 1314.925415f, 4.456899166107177734f, 5.855425834655761718f }, PATH_CHARGING_FAMILIAR_PATH + 8 },
    { { -1014.447875976562f, 1231.609375f, 7.548688411712646484f, 2.091593265533447265f }, PATH_CHARGING_FAMILIAR_PATH + 9 },
    { { -1104.810791015625f, 1313.993041f, 3.400579452514648437f, 5.872215747833251953f }, PATH_CHARGING_FAMILIAR_PATH + 10 },
    { { -1116.729125976562f, 1263.534790f, 12.73228836059570312f, 5.952130794525146484f }, PATH_CHARGING_FAMILIAR_PATH + 11 },
    { { -1099.619750976562f, 1317.060791f, 2.314694643020629882f, 5.868431091308593750f }, PATH_CHARGING_FAMILIAR_PATH + 12 },
};

// 126478 - Fletchers Hollow Conscript
struct npc_drustvar_shoot_wickerman_controller : public ScriptedAI
{
    npc_drustvar_shoot_wickerman_controller(Creature* creature) : ScriptedAI(creature) {}

    void SpawnChargingFamiliar()
    {
        ChargingFamiliarData const& data = Trinity::Containers::SelectRandomContainerElement(ChargingFamiliarDatas);
        if (Creature* familiar = me->SummonCreature(NPC_DRUSTVAR_CHARGING_FAMILIAR, data.SpawnPos))
            familiar->GetMotionMaster()->MovePath(data.PathID, false);
    }

    void JustAppeared() override
    {
        for (uint8 i = 0; i < 2; i++)
            SpawnChargingFamiliar();
    }

    void DoAction(int32 param) override
    {
        if (param == ACTION_SPAWN_CHARGING_FAMILIAR)
            SpawnChargingFamiliar();
    }
};

// 137841 - Charging Familair
struct npc_drustvar_charging_familiar : public ScriptedAI
{
    npc_drustvar_charging_familiar(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        DoCastSelf(SPELL_DRUSTVAR_SHADOW_DISSOLVE_IN);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* controller = me->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_FLETCHERS_HOLLOW_CONSCRIPT, .StringId = "ShootWickermanController" }))
            controller->AI()->DoAction(ACTION_SPAWN_CHARGING_FAMILIAR);
        me->DespawnOrUnsummon(5s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DRUSTVAR_SHOOT_WICKERMAN)
            me->KillSelf();
    }
};

// 164 - Areatrigger
struct at_drustvar_timbered_strand_shoot_wickerman : AreaTriggerAI
{
    at_drustvar_timbered_strand_shoot_wickerman(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsCreature() || unit->GetEntry() != NPC_DRUSTVAR_CHARGING_FAMILIAR)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_DRUSTVAR_SHOOT_WICKERMAN, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }
};

void AddSC_zone_drustvar()
{
    // Creature
    RegisterCreatureAI(npc_drustvar_shoot_wickerman_controller);
    RegisterCreatureAI(npc_drustvar_charging_familiar);

    // Conversation
    RegisterConversationAI(conversation_drustvar_really_big_problem_complete);

    // Areatrigger
    RegisterAreaTriggerAI(at_drustvar_timbered_strand_shoot_wickerman);

    // Spells
    RegisterSpellScript(spell_drustvar_dismiss_tradewind);
}

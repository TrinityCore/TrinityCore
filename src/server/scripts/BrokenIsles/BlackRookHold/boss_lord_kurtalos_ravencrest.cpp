/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "black_rook_hold.h"
#include "WaypointDefines.h"

enum Spells
{
    /// Phase 1

    // Kurtalos
    SPELL_UNERRING_SHEAR            = 198635,

    NPC_WHIRLING_BLADE              = 100861,
    SPELL_WHIRLING_BLADE            = 198641,
    SPELL_WHIRLING_BLADE_DAMAGE     = 198781,
    SPELL_WHIRLING_BLADE_AT         = 198782,

    SPELL_FEIGN_DEATH               = 35356,

    // Latosius
    SPELL_DARK_BLAST                = 198820,
    SPELL_SHADOW_BOLT               = 198833,
    SPELL_TELEPORT_OUT              = 198835,
    SPELL_TELEPORT_IN               = 199058,
    SPELL_SAP_SOUL                  = 198961,
    SPELL_DREADLORD_CONVERSATION    = 199239,
    SPELL_TRANSFORM                 = 199064,

    /// Phase 2 - Dantalionax
    SPELL_LEGACY_OF_THE_RAVENCREST  = 199368,

    NPC_STINGING_SWARM              = 101008,
    SPELL_STINGING_SWARM_VISUAL     = 199160,
    SPELL_STINGING_SWARM            = 201733,
    SPELL_STINGING_SWARM_REMOVAL    = 199157,
    SPELL_ITCHY                     = 199168,

    SPELL_CLOUD_OF_HYPNOSIS_SUMMON  = 199143,
    SPELL_CLOUD_OF_HYPNOSIS_AT      = 199092,
    SPELL_CLOUD_OF_HYPNOSIS_STUN    = 199097,

    SPELL_DREADLORDS_GUILE          = 199193,
    SPELL_DARK_OBLITERATION         = 199567,

    SPELL_SHADOW_BOLT_VOLLEY        = 202019,
};

Position centerPosition = { 3185.36f, 7409.95f, 270.38f, 1.079803f };

// 98965
struct boss_kurtalos_ravencrest : public BossAI
{
    boss_kurtalos_ravencrest(Creature* creature) : BossAI(creature, DATA_LORD_RAVENCREST) { }

    void Reset() override
    {
        BossAI::Reset();

        latosiusActionDone = false;
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetReactState(REACT_DEFENSIVE);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNERRING_SHEAR);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LEGACY_OF_THE_RAVENCREST);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_UNERRING_SHEAR, 5s);
        events.ScheduleEvent(SPELL_WHIRLING_BLADE, 15s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(10, damage))
        {
            if (!latosiusActionDone)
            {
                if (Creature* latosius = instance->GetCreature(NPC_LATOSIUS))
                {
                    events.Reset();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->Clear();
                    latosius->AI()->DoAction(SPECIAL);
                    latosiusActionDone = true;
                }
            }

            damage = 0;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (me->GetReactState() != REACT_PASSIVE)
            DoMeleeAttackIfReady();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_UNERRING_SHEAR:
                me->CastSpell(me->GetVictim(), SPELL_UNERRING_SHEAR, false);
                events.Repeat(10s, 15s);
                break;
            case SPELL_WHIRLING_BLADE:
                me->CastSpell(nullptr, SPELL_WHIRLING_BLADE, false);
                events.Repeat(45s, 60s);
                break;
            default:
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_WHIRLING_BLADE:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 0.f, true))
                    if (Creature* whirlingBlade = me->SummonCreature(NPC_WHIRLING_BLADE, me->GetPosition()))
                        whirlingBlade->AI()->SetGUID(target->GetGUID());

                break;
            }
        }
    }

    void JustDied(Unit* attacker) override
    {
        BossAI::JustDied(attacker);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNERRING_SHEAR);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LEGACY_OF_THE_RAVENCREST);
    }

private:
    bool latosiusActionDone = false;
};

// 100486
struct npc_kurtalos_whirling_blade : public ScriptedAI
{
    npc_kurtalos_whirling_blade(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(me, SPELL_WHIRLING_BLADE_AT, true);
        me->SetSpeed(MOVE_WALK, 2.0f);
        me->SetSpeed(MOVE_RUN, 2.0f);
    }

    void SetGUID(ObjectGuid guid, int32 /*id*/) override
    {
        Unit* target = ObjectAccessor::GetUnit(*me, guid);
        if (!target)
        {
            me->DisappearAndDie();
            return;
        }

        me->GetMotionMaster()->Clear();
        path.nodes.clear();

        path.nodes.push_back(WaypointNode(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()));
        path.nodes.push_back(WaypointNode(2, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation()));
        me->GetMotionMaster()->MovePath(path, true);
    }
private:
    WaypointPath path;
};

// Spell 198782
// AT 10185
struct at_kurtalos_whirling_blade : AreaTriggerAI
{
    at_kurtalos_whirling_blade(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(unit, SPELL_WHIRLING_BLADE_DAMAGE, true);
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
            if (TempSummon* temp = caster->ToTempSummon())
                temp->DespawnOrUnsummon();
    }
};

// 98970
struct npc_latosius : public ScriptedAI
{
    npc_latosius(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        SetCombatMovement(false);
        me->SetDisableGravity(false);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        me->UpdateEntry(NPC_LATOSIUS);
        SetEquipmentSlots(true);
        me->ClearUnitState(UNIT_STATE_CANNOT_TURN);

        if (!kurtalosSoulGUID.IsEmpty())
        {
            if (Creature* kurtalosSoul = ObjectAccessor::GetCreature(*me, kurtalosSoulGUID))
                kurtalosSoul->ToTempSummon()->DespawnOrUnsummon();

            kurtalosSoulGUID = ObjectGuid::Empty;
        }
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        if (IsLatosius())
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            me->CastSpell(nullptr, SPELL_TELEPORT_OUT, true);

            me->AddUnitState(UNIT_STATE_CANNOT_TURN);
            me->SetDisableGravity(true);
            me->NearTeleportTo({ 3206.10f, 7416.93f, 276.54f, 3.451702f });

            events.ScheduleEvent(SPELL_DARK_BLAST, 10s);
            events.ScheduleEvent(SPELL_SHADOW_BOLT, 5s);
        }
        else
        {
            events.ScheduleEvent(SPELL_SHADOW_BOLT_VOLLEY,          5s);
            events.ScheduleEvent(SPELL_CLOUD_OF_HYPNOSIS_SUMMON,    10s);
            events.ScheduleEvent(SPELL_DREADLORDS_GUILE,            20s);

            if (IsHeroic())
                events.ScheduleEvent(SPELL_STINGING_SWARM, 1s);
        }
    }

    void DoAction(int32 action) override
    {
        // Switch to Phase 2 event
        if (IsLatosius() && action == SPECIAL)
        {
            events.Reset();
            me->CastStop();

            TeleportToCenter();
            me->ClearUnitState(UNIT_STATE_CANNOT_TURN);

            me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
            {
                me->CastStop();
                me->CastSpell(nullptr, SPELL_SAP_SOUL, false);
            }).
            Schedule(9s, [this](TaskContext /*context*/)
            {
                me->UpdateEntry(NPC_DANTALIONAX);
                SetEquipmentSlots(false, 0, 0, 0);
                me->CastSpell(me, SPELL_DREADLORD_CONVERSATION, true);
                me->CastSpell(me, SPELL_TRANSFORM, true);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                AttackStart(me->GetVictim());

                if (Creature* kurtalos = instance->GetCreature(NPC_LORD_KURTALOS_RAVENCREST))
                {
                    kurtalos->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    kurtalos->CastSpell(kurtalos, SPELL_FEIGN_DEATH, true);

                    Position soulSummonPos = kurtalos->GetPosition();
                    soulSummonPos.m_positionZ += 2.f;

                    if (Creature* soulOfKurtalos = kurtalos->SummonCreature(NPC_SOUL_OF_RAVENCREST, soulSummonPos))
                    {
                        kurtalosSoulGUID = soulOfKurtalos->GetGUID();
                        soulOfKurtalos->SetDisableGravity(true);
                    }
                }
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (!UpdateVictim())
            return;

        ScriptedAI::UpdateAI(diff);

        switch (events.ExecuteEvent())
        {
            /// Latosius Phase 1
            case SPELL_DARK_BLAST:
                me->CastSpell(nullptr, SPELL_DARK_BLAST, false);
                events.Repeat(10s);
                break;
            case SPELL_SHADOW_BOLT:
                me->CastSpell(nullptr, SPELL_SHADOW_BOLT, false);
                events.Repeat(5s);
                break;
            /// Dantalionax Phase 2
            case SPELL_SHADOW_BOLT_VOLLEY:
                me->CastSpell(nullptr, SPELL_SHADOW_BOLT, false);
                events.Repeat(5s);
                break;
            case SPELL_CLOUD_OF_HYPNOSIS_SUMMON:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                    me->CastSpell(target->GetPosition(), SPELL_CLOUD_OF_HYPNOSIS_SUMMON, false);

                events.Repeat(20s);
                break;
            }
            case SPELL_DREADLORDS_GUILE:
                me->CastStop();
                me->CastSpell(nullptr, SPELL_DREADLORDS_GUILE, false);
                events.Repeat(30s);
                events.DelayEvents(25s); // 5s spell cast + 17s event + 2s security
                break;
            case SPELL_STINGING_SWARM:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true, -SPELL_STINGING_SWARM))
                    me->SummonCreature(NPC_STINGING_SWARM, *target, TEMPSUMMON_CORPSE_DESPAWN);
                events.Repeat(15s);
                break;
        }
    }

    void OnSuccessfulSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DREADLORDS_GUILE)
        {
            me->GetMotionMaster()->Clear();
            me->SetDisableGravity(true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            obliterationAngle = frand(0, 2.f * float(M_PI));
            me->AddUnitState(UNIT_STATE_CANNOT_TURN);

            me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
            {
                Position movePos;
                GetPositionWithDistInOrientation(&centerPosition, 20.f, obliterationAngle, movePos);
                movePos.m_positionZ = 273.f;

                me->CastSpell(nullptr, SPELL_TELEPORT_IN, true); // Visual
                me->NearTeleportTo(movePos);
                me->SetFacingTo(me->GetAngle(centerPosition));
                me->SetOrientation(me->GetAngle(centerPosition));
                me->SetTarget(ObjectGuid::Empty);

            }).Schedule(2s, [this](TaskContext /*context*/)
            {
                me->CastSpell(nullptr, SPELL_DARK_OBLITERATION, false);
            }).Schedule(5s, [this](TaskContext context)
            {
                if (context.GetRepeatCounter() >= 12)
                {
                    TeleportToCenter();
                    me->RemoveAurasDueToSpell(SPELL_DREADLORDS_GUILE);
                    me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                    if (me->GetVictim())
                    {
                        me->SetTarget(me->GetVictim()->GetGUID());
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                    }
                    return;
                }

                Position movePos;
                obliterationAngle += float(M_PI) / 12.f;
                GetPositionWithDistInOrientation(&centerPosition, 20.f, obliterationAngle, movePos);
                movePos.m_positionZ = 273.f;

                me->CastSpell(nullptr, SPELL_TELEPORT_IN, true); // Visual
                me->NearTeleportTo(movePos);
                me->SetFacingTo(me->GetAngle(centerPosition));

                context.Schedule(500ms, [this](TaskContext /*context*/)
                {
                    me->SetOrientation(me->GetAngle(centerPosition));
                    me->CastSpell(nullptr, SPELL_DARK_OBLITERATION, true);
                });
                context.Repeat(1s);
            });
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* kurtalos = instance->GetCreature(NPC_LORD_KURTALOS_RAVENCREST))
            kurtalos->KillSelf();
    }

private:
    inline bool IsLatosius() const
    {
        return me->GetEntry() == NPC_LATOSIUS;
    }

    void TeleportToCenter()
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        me->CastSpell(nullptr, SPELL_TELEPORT_IN, true); // Visual
        me->NearTeleportTo(centerPosition);
        me->SetDisableGravity(false);
    }

    ObjectGuid kurtalosSoulGUID;
    float obliterationAngle;
};

// 101054
struct npc_kurtalos_soul : public ScriptedAI
{
    npc_kurtalos_soul(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        Talk(0);

        me->GetScheduler().Schedule(3s, [this](TaskContext /*context*/)
        {
            me->CastSpell(nullptr, SPELL_LEGACY_OF_THE_RAVENCREST, false);
        });
    }
};

// 100994
struct npc_dantalionax_cloud_of_hypnosis : public ScriptedAI
{
    npc_dantalionax_cloud_of_hypnosis(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->CastSpell(me, SPELL_CLOUD_OF_HYPNOSIS_AT, true);
        me->SetSpeed(MOVE_WALK, 1.0f);
        me->SetSpeed(MOVE_RUN, 1.0f);
        me->GetMotionMaster()->MoveRandom(20.0f);
    }
};

// Spell 199092
// AT 10200
struct at_dantalionax_cloud_of_hypnosis : AreaTriggerAI
{
    at_dantalionax_cloud_of_hypnosis(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
            unit->CastSpell(unit, SPELL_CLOUD_OF_HYPNOSIS_STUN, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CLOUD_OF_HYPNOSIS_STUN);
    }
};

// 101008
struct npc_dantalionax_stinging_swarm : public ScriptedAI
{
    npc_dantalionax_stinging_swarm(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        Player* target = me->SelectNearestPlayer();

        if (!target)
        {
            me->DisappearAndDie();
            return;
        }

        me->CastSpell(target, SPELL_STINGING_SWARM, true);
        me->EnterVehicle(target);
        playerGUID = target->GetGUID();

        me->GetScheduler().Schedule(2s, [this](TaskContext context)
        {
            Player* player = ObjectAccessor::GetPlayer(*me, playerGUID);
            if (!player || !player->IsAlive())
            {
                me->DisappearAndDie();
                return;
            }

            context.Repeat();
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->GetHealth() <= damage)
        {
            me->CastSpell(nullptr, SPELL_STINGING_SWARM_REMOVAL, true);

            if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                player->RemoveAurasDueToSpell(SPELL_STINGING_SWARM);
        }
    }

    void UpdateAI(uint32 /*diff*/) override { }

private:
    ObjectGuid playerGUID;
};

void AddSC_boss_lord_kurtalos_ravencrest()
{
    RegisterCreatureAI(boss_kurtalos_ravencrest);
    RegisterCreatureAI(npc_kurtalos_whirling_blade);
    RegisterAreaTriggerAI(at_kurtalos_whirling_blade);
    RegisterCreatureAI(npc_latosius);
    RegisterCreatureAI(npc_kurtalos_soul);
    RegisterCreatureAI(npc_dantalionax_cloud_of_hypnosis);
    RegisterAreaTriggerAI(at_dantalionax_cloud_of_hypnosis);
    RegisterCreatureAI(npc_dantalionax_stinging_swarm);
}

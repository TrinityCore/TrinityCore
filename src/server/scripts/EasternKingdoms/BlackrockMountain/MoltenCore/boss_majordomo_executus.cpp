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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "molten_core.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum MajordomoTexts
{
    SAY_AGGRO                         = 0,
    SAY_SLAY                          = 1,
    SAY_DEFEAT_1                      = 2,
    SAY_DEFEAT_2                      = 3,
    SAY_DEFEAT_3                      = 4,
    SAY_SPAWN                         = 5,
    SAY_CHAMPION                      = 6,
    SAY_SUMMON_1                      = 7,
    SAY_SUMMON_2                      = 8,
    SAY_SUMMON_3                      = 9,
    SAY_SUMMON_4                      = 10
};

enum MajordomoSpells
{
    // Combat
    SPELL_AEGIS_OF_RAGNAROS           = 20620,
    SPELL_SEPARATION_ANXIETY          = 21094,
    SPELL_TELEPORT_VICTIM             = 20534,
    SPELL_TELEPORT_RANDOM             = 20618,
    SPELL_MAGIC_REFLECTION            = 20619,
    SPELL_DAMAGE_SHIELD               = 21075,

    SPELL_HATE_TO_ZERO                = 20538,
    SPELL_IMMUNITY                    = 21087,
    SPELL_CHAMPION                    = 21090,
    SPELL_ENCOURAGEMENT               = 21086,

    // Outro
    SPELL_TELEPORT_VISUAL             = 19484,
    SPELL_SUMMON_RAGNAROS             = 19774,

    // Scripts
    SPELL_SEPARATION_ANXIETY_EFFECT   = 21095
};

enum MajordomoEvents
{
    EVENT_AEGIS_OF_RAGNAROS           = 1,
    EVENT_SEPARATION_ANXIETY,
    EVENT_TELEPORT_VICTIM,
    EVENT_TELEPORT_RANDOM,
    EVENT_SHIELD,

    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3,
    EVENT_OUTRO_4,
    EVENT_OUTRO_5,

    EVENT_SUMMON_1,
    EVENT_SUMMON_2,
    EVENT_SUMMON_3,
    EVENT_SUMMON_4,
    EVENT_SUMMON_5,

    EVENT_DESPAWN_OBJECTS
};

enum MajordomoMisc
{
    GOSSIP_MENU_EVENT                 = 4108,
    FACTION_OUTRO                     = 1080,
    POINT_SUMMON                      = 0
};

Position const TeleToRagnarosPosition = { 848.9330f, -812.8750f, -229.60100f, 4.046000003814697265f };
Position const SummonRagnarosPosition = { 830.9636f, -814.7055f, -228.97328f, 5.445427417755126953f };

// 12018 - Majordomo Executus
struct boss_majordomo : public BossAI
{
    boss_majordomo(Creature* creature) : BossAI(creature, BOSS_MAJORDOMO_EXECUTUS), _deadFlamewakerCount(0) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(20, true);
        BossAI::InitializeAI();
    }

    void JustAppeared() override
    {
        if (instance->GetBossState(BOSS_MAJORDOMO_EXECUTUS) == DONE)
        {
            me->SetFaction(FACTION_OUTRO);
            me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }
        else
            Talk(SAY_SPAWN);
    }

    void Reset() override
    {
        _Reset();
        _deadFlamewakerCount = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        if (who->GetEntry() == NPC_RAGNAROS)
            return;

        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_AEGIS_OF_RAGNAROS, 0s);
        events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 0s);
        events.ScheduleEvent(EVENT_TELEPORT_VICTIM, 15s, 20s);
        events.ScheduleEvent(EVENT_TELEPORT_RANDOM, 25s, 30s);
        events.ScheduleEvent(EVENT_SHIELD, 25s, 30s);
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
    {
        if (attacker->GetEntry() == NPC_RAGNAROS)
            return;

        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    void JustReachedHome() override
    {
        _JustReachedHome();

        if (instance->GetBossState(BOSS_MAJORDOMO_EXECUTUS) != DONE)
            instance->instance->SpawnGroupSpawn(SPAWN_GROUP_FLAMEWAKERS, true);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_TELEPORT_VICTIM:
            case SPELL_TELEPORT_RANDOM:
                DoCastSelf(SPELL_HATE_TO_ZERO);
                break;
            case SPELL_CHAMPION:
                Talk(SAY_CHAMPION);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_FLAMEWAKER_DIES)
        {
            _deadFlamewakerCount++;

            switch (_deadFlamewakerCount)
            {
                case 4:
                    DoCastSelf(SPELL_IMMUNITY);
                    break;
                case 7:
                    DoCastSelf(SPELL_CHAMPION);
                    break;
                case 8:
                    _specialEvents.ScheduleEvent(EVENT_OUTRO_1, 0s);
                    break;
                default:
                    break;
            }

            DoCastSelf(SPELL_ENCOURAGEMENT);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void UpdateSpecialEvents(uint32 diff)
    {
        _specialEvents.Update(diff);

        while (uint32 eventId = _specialEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_OUTRO_1:
                    instance->UpdateEncounterStateForKilledCreature(me->GetEntry(), me);
                    Talk(SAY_DEFEAT_1);
                    me->SetFaction(FACTION_OUTRO);
                    me->SetImmuneToPC(true);
                    EnterEvadeMode();
                    _JustDied();
                    _specialEvents.ScheduleEvent(EVENT_OUTRO_2, 7s);
                    break;
                case EVENT_OUTRO_2:
                    Talk(SAY_DEFEAT_2);
                    _specialEvents.ScheduleEvent(EVENT_OUTRO_3, 7s);
                    break;
                case EVENT_OUTRO_3:
                    Talk(SAY_DEFEAT_3);
                    _specialEvents.ScheduleEvent(EVENT_OUTRO_4, 18s);
                    break;
                case EVENT_OUTRO_4:
                    DoCastSelf(SPELL_TELEPORT_VISUAL);
                    _specialEvents.ScheduleEvent(EVENT_OUTRO_5, 1s);
                    break;
                case EVENT_OUTRO_5:
                    me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    me->NearTeleportTo(TeleToRagnarosPosition);
                    break;

                case EVENT_SUMMON_1:
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    instance->instance->SpawnGroupSpawn(SPAWN_GROUP_LAVA_STEAM);
                    instance->instance->SpawnGroupSpawn(SPAWN_GROUP_LAVA_SPLASH);
                    _specialEvents.ScheduleEvent(EVENT_DESPAWN_OBJECTS, 30s);
                    _specialEvents.ScheduleEvent(EVENT_SUMMON_2, 5s);
                    break;
                case EVENT_SUMMON_2:
                    Talk(SAY_SUMMON_2);
                    DoCastSelf(SPELL_SUMMON_RAGNAROS);
                    me->SetWalk(true);
                    // He should move while casting spell but he starts to move only when spell cast is finished
                    // Orientation is not changed after reaching point
                    me->GetMotionMaster()->MovePoint(POINT_SUMMON, SummonRagnarosPosition, true, 5.445427417755126953f);
                    _specialEvents.ScheduleEvent(EVENT_SUMMON_3, 15s);
                    break;
                case EVENT_SUMMON_3:
                    Talk(SAY_SUMMON_3);
                    _specialEvents.ScheduleEvent(EVENT_SUMMON_4, 10s);
                    break;
                case EVENT_SUMMON_4:
                    instance->instance->SpawnGroupSpawn(SPAWN_GROUP_RAGNAROS);
                    _specialEvents.ScheduleEvent(EVENT_SUMMON_5, 20s);
                    break;
                case EVENT_SUMMON_5:
                    Talk(SAY_SUMMON_4);
                    break;

                case EVENT_DESPAWN_OBJECTS:
                    instance->instance->SpawnGroupDespawn(SPAWN_GROUP_LAVA_STEAM);
                    instance->instance->SpawnGroupDespawn(SPAWN_GROUP_LAVA_SPLASH);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateSpecialEvents(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_AEGIS_OF_RAGNAROS:
                    if (!me->HasAura(SPELL_AEGIS_OF_RAGNAROS))
                        DoCastSelf(SPELL_AEGIS_OF_RAGNAROS);
                    events.Repeat(0s, 10s);
                    break;
                case EVENT_SEPARATION_ANXIETY:
                    DoCastSelf(SPELL_SEPARATION_ANXIETY);
                    break;
                case EVENT_TELEPORT_VICTIM:
                    DoCastVictim(SPELL_TELEPORT_VICTIM);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_TELEPORT_RANDOM:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_TELEPORT_RANDOM);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_SHIELD:
                    DoCastSelf(RAND(SPELL_MAGIC_REFLECTION, SPELL_DAMAGE_SHIELD));
                    events.Repeat(30s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == GOSSIP_MENU_EVENT)
        {
            CloseGossipMenuFor(player);
            Talk(SAY_SUMMON_1, player);
            _specialEvents.ScheduleEvent(EVENT_SUMMON_1, 0s);
        }
        return false;
    }

private:
    uint8 _deadFlamewakerCount;
    EventMap _specialEvents;
};

// 21094 - Separation Anxiety
class spell_majordomo_separation_anxiety : public AuraScript
{
    PrepareAuraScript(spell_majordomo_separation_anxiety);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SEPARATION_ANXIETY_EFFECT });
    }

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = 5 * IN_MILLISECONDS;
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (Unit* caster = GetCaster())
            if (caster->IsAlive() && !caster->IsWithinDistInMap(target, aurEff->GetSpellEffectInfo().CalcRadius()))
                target->CastSpell(target, SPELL_SEPARATION_ANXIETY_EFFECT, true);
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_majordomo_separation_anxiety::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_majordomo_separation_anxiety::HandleDummyTick, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_boss_majordomo()
{
    RegisterMoltenCoreCreatureAI(boss_majordomo);
    RegisterSpellScript(spell_majordomo_separation_anxiety);
}

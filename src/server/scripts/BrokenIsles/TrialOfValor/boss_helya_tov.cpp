/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016-2019 MagicStorm
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

#include "trial_of_valor.h"
#include "CombatPackets.h"

enum Spells
{
    SPELL_CORROSIVE_NOVA                = 228872,
    SPELL_TAINT_OF_THE_SEA              = 228054,
    SPELL_TAINTED_EXPLOSION             = 228053,
    SPELL_TAINTED_ESSENCE               = 228052,
    SPELL_ORB_OF_CORRUPTION             = 227903,
    SPELL_ORB_OF_CORRUPTION_AURA        = 227926,
    SPELL_BILEWATER_BREATH              = 227967,
    SPELL_BILEWATER_LIQUEFACTION        = 227990,
    SPELL_BILEWATER_LIQUEFACTION_DMG    = 227992,
    SPELL_BILEWATER_CORROSION           = 227998,
    SPELL_BILEWATER_REDOX               = 227982,
    SPELL_BILEWATER_SUMMON              = 230216,
    SPELL_TENTACLE_SLAM                 = 231298,
    SPELL_TENTACLE_STRIKE               = 228767,
    SPELL_TORRENT                       = 228514,
    SPELL_FURY_OF_THE_MAW               = 228032,
    SPELL_FURY_OF_THE_MAW_AT            = 228027,
    SPELL_FURY_OF_THE_MAW_DMG           = 228055,
    SPELL_DECAY                         = 228121,
    SPELL_DECAY_DMG                     = 228127,
    SPELL_RAGING_TEMPEST                = 201119,
    SPELL_LANTERN_OF_DARKNESS           = 228619,
    SPELL_GHOSTLY_RAGE                  = 228611,
    SPELL_GIVE_NO_QUARTER               = 228632,
    SPELL_SLUDGE_NOVA                   = 228390,
    SPELL_ANCHOR_SLAM                   = 228519,
    SPELL_FETID_ROT                     = 193367,
    SPELL_RABID                         = 202476,
    SPELL_VIGOR                         = 203816,
    SPELL_RALLY_OF_THE_KEVALDIR         = 232346,
    SPELL_DARK_HARTRED                  = 232488,
    SPELL_MISTS_OF_HELHEIM              = 228372, // power alternate
    SPELL_SET_ENERGY_1                  = 232229,
    SPELL_SET_ENERGY_2                  = 232230,
    SPELL_ORB_OF_CORROSION              = 228058,
    SPELL_ORB_OF_CORROSION_CAST         = 228056,
    SPELL_ORB_OF_CORROSION_AURA         = 228061,
    SPELL_ORB_OF_CORROSION_AURA2        = 228057,
    SPELL_LONG_BOAT                     = 230464,
    SPELL_LONG_BOAT2                    = 230491,
};

enum Events
{
    EVENT_CORROSIVE_NOVA = 1,
    EVENT_TAINT_OF_THE_SEA,
    EVENT_ORB_OF_CORRUPTION_CAST,
    EVENT_ORB_OF_CORRUPTION,
    EVENT_BILEWATER_BREATH,
    EVENT_BILEWATER_SLIME_SUMMON,
    EVENT_START_PHASE2,
    EVENT_TORRENT,
    EVENT_FURY_OF_THE_MAW,
    EVENT_MISTS_OF_HELHEIM,
    EVENT_ORB_OF_CORROSION,
    EVENT_ORB_OF_CORROSION_CAST,
};

enum Says
{
    SAY_KILLED          = 1,
    SAY_PRE_COMBAT      = 2,
    SAY_COMBAT          = 3,
    SAY_TAINT           = 4,
    SAY_DARKNESS        = 5,
    SAY_SUMMON_BOSS     = 6,
    SAY_CORROSION       = 9,
    SAY_CORROSION2      = 11,
    SAY_DIED            = 12,
};

const Position decayingSpawns[10] =
{
    { 529.276f, 702.028f, -2.0632f, 4.31416f },
    { 539.448f, 699.825f, -2.43245f, 4.31416f },
    { 528.059f, 583.365f, -0.529168f, 1.75563f },
    { 491.255f, 586.115f, -0.529175f, 1.4199f },
    { 503.182f, 583.628f, -0.529175f, 1.36772f },
    { 517.481f, 719.132f, -3.38609f, 4.31416f },
    { 549.359f, 698.911f, -3.12035f, 4.31416f },
    { 522.04f, 709.505f, -2.51397f, 4.31416f },
    { 482.042f, 590.741f, -0.529178f, 1.5545f },
    { 515.188f, 580.21f, -0.529175f, 1.33011f },
};

const Position tentaclesSpawns[9] =
{
    { 556.79f, 674.844f, 18.2333f, 5.20108f },
    { 487.924f, 701.253f, 25.0983f, 3.19395f },
    { 468.806f, 616.033f, 2.87736f, 2.40855f },
    { 501.754f, 601.943f, 2.87736f, 1.43117f },
    { 482.585f, 606.337f, 2.87736f, 1.43117f },
    { 473.892f, 721.271f, 22.4441f, 4.4855f },
    { 543.917f, 676.76f, 2.87736f, 4.20624f },
    { 579.972f, 667.925f, 21.1616f, 3.21141f },
    { 500.231f, 698.972f, 2.87736f, 4.18879f },
};

class boss_helya_tov : public CreatureScript
{
public:

    boss_helya_tov() : CreatureScript("boss_helya_tov") { }

    struct boss_helya_tovAI : public BossAI
    {
        boss_helya_tovAI(Creature* creature) : BossAI(creature, DATA_HELYA)
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->SetCanFly(false);

            //me->setPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 100);

            me->CastSpell(me, SPELL_SET_ENERGY_1, true);
            me->CastSpell(me, SPELL_SET_ENERGY_2, true);

            me->SetMaxHealth(1410737280);
            me->SetHealth(1410737280);

            if (instance)
            {
                instance->SetBossState(DATA_HELYA, NOT_STARTED);

                if (instance->GetBossState(DATA_GUARM) == DONE)
                    if (GameObject* go = me->FindNearestGameObject(GO_GUARM_DOOR_HALYA, 1000.0f))
                        go->UseDoorOrButton(300000);
            }
        }

        bool isPhase2;
        bool isPhase3;
        bool isCorrosiveNova;
        bool furyOfTheMaw;
        bool firstFuryOfTheMaw;
        uint8 waveCount;
        bool sayPreCombat;

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

            me->SetUnitMovementFlags(MOVEMENTFLAG_ROOT);
            me->SetVisible(true);

            //me->setPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 100);

            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->CastSpell(me, SPELL_SET_ENERGY_1, true);
            //me->CastSpell(me, SPELL_SET_ENERGY_2, true);

            _Reset();
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_HELYA, FAIL);
            }

            isPhase2 = false;
            isPhase3 = false;
            isCorrosiveNova = false;
            furyOfTheMaw = false;
            firstFuryOfTheMaw = false;
            waveCount = 0;

            me->SetReactState(REACT_DEFENSIVE);

            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                instance->SetBossState(DATA_HELYA, IN_PROGRESS);
            }

            me->AddUnitFlag(UnitFlags(UNIT_FLAG_STUNNED));

            events.ScheduleEvent(EVENT_TAINT_OF_THE_SEA, 8 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ORB_OF_CORRUPTION_CAST, 12 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BILEWATER_BREATH, 25 * IN_MILLISECONDS);

            Talk(SAY_COMBAT);
            me->setActive(true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
                instance->SetBossState(DATA_HELYA, DONE);
            }

            Talk(SAY_DIED);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILLED);
        }

        void JustReachedHome() override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustReachedHome();
                instance->SetBossState(DATA_HELYA, FAIL);
            }
        }

        void SetInPhase3()
        {
            uint32 calcHealth = CalculatePct(me->GetMaxHealth(), 47);
            me->SetHealth(calcHealth);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
            events.ScheduleEvent(EVENT_TAINT_OF_THE_SEA, 8 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ORB_OF_CORROSION, 12 * IN_MILLISECONDS);
            me->SetReactState(REACT_AGGRESSIVE);
            me->GetMotionMaster()->MoveTargetedHome();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!sayPreCombat && instance && instance->GetBossState(DATA_GUARM) == DONE)
                Talk(SAY_PRE_COMBAT);

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->HealthBelowPct(65) && !isPhase2)
            {
                events.CancelEvent(EVENT_TAINT_OF_THE_SEA);
                events.CancelEvent(EVENT_ORB_OF_CORRUPTION_CAST);
                events.CancelEvent(EVENT_ORB_OF_CORRUPTION);
                events.CancelEvent(EVENT_BILEWATER_BREATH);
                events.CancelEvent(EVENT_BILEWATER_SLIME_SUMMON);

                events.ScheduleEvent(EVENT_MISTS_OF_HELHEIM, 1 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TORRENT, 7 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_START_PHASE2, 5 * IN_MILLISECONDS);

                me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_STUNNED));

                me->GetMotionMaster()->MovePoint(0, 578.031f, 792.5868f, 5.09298f);

                for (uint8 i = 0; i < 9; ++i)
                {
                    if (Creature* tentacle = me->SummonCreature(NPC_GRIPPING_TENTACLE, tentaclesSpawns[i], TEMPSUMMON_DEAD_DESPAWN))
                    {
                        tentacle->SetReactState(REACT_PASSIVE);
                        tentacle->AttackStop();
                    }
                }

                DoCast(SPELL_MISTS_OF_HELHEIM);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                isPhase2 = true;
            }

            if (Unit* target = me->GetVictim())
            {
                if (!isPhase2 && !me->IsWithinMeleeRange(target) && !isCorrosiveNova)
                {
                    events.ScheduleEvent(EVENT_CORROSIVE_NOVA, 3 * IN_MILLISECONDS);
                    isCorrosiveNova = true;
                }
            }

            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 1.0f && (!isPhase2 || isPhase3))
                me->GetMotionMaster()->MoveTargetedHome();

            if (isPhase2 && !isPhase3 && !me->FindNearestCreature(NPC_GRIPPING_TENTACLE, 1000.0f, true))
            {
                SetInPhase3();
                isPhase3 = true;
            }

            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CORROSIVE_NOVA:
                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_CORROSIVE_NOVA, true);

                        isCorrosiveNova = false;
                        break;

                    case EVENT_TAINT_OF_THE_SEA:
                        if (roll_chance_i(25))
                            Talk(SAY_TAINT);

                        for (uint8 i = 0; i < 3; ++i)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                                target->CastSpell(target, SPELL_TAINT_OF_THE_SEA, true);

                        events.ScheduleEvent(EVENT_TAINT_OF_THE_SEA, 8 * IN_MILLISECONDS);
                        break;

                    case EVENT_ORB_OF_CORRUPTION_CAST:
                        if (roll_chance_i(25))
                            Talk(SAY_DARKNESS);

                        me->CastSpell(me, SPELL_ORB_OF_CORRUPTION, true);

                        events.ScheduleEvent(EVENT_ORB_OF_CORRUPTION, 1 * IN_MILLISECONDS);
                        break;

                    case EVENT_ORB_OF_CORRUPTION:
                        for (uint8 i = 0; i < 3; ++i)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            {
                                if (Creature* corruption = me->SummonCreature(NPC_ORB_OF_CORRUPTION, *target, TEMPSUMMON_TIMED_DESPAWN, 30000))
                                {
                                    if (Player* player = corruption->SelectNearestPlayer(500.0f))
                                        corruption->GetMotionMaster()->MoveFollow(player, 1.0f, 0.0f);

                                    corruption->CastSpell(corruption, SPELL_ORB_OF_CORRUPTION_AURA, true);
                                }
                            }
                        }

                        events.ScheduleEvent(EVENT_ORB_OF_CORRUPTION_CAST, 12 * IN_MILLISECONDS);
                        break;

                    case EVENT_BILEWATER_BREATH:
                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_BILEWATER_BREATH, true);

                        events.ScheduleEvent(EVENT_BILEWATER_SLIME_SUMMON, 1 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_BILEWATER_BREATH, 25 * IN_MILLISECONDS);
                        break;

                    case EVENT_BILEWATER_SLIME_SUMMON:
                        for (uint8 i = 0; i < 5; ++i)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                                me->CastSpell(target, SPELL_BILEWATER_SUMMON, true);

                        break;

                    case EVENT_START_PHASE2:
                        me->SetFacingTo(4.29f);
                        furyOfTheMaw = true;

                        events.ScheduleEvent(EVENT_FURY_OF_THE_MAW, 0.1 * IN_MILLISECONDS);
                        break;

                    case EVENT_TORRENT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            me->CastSpell(target, SPELL_TORRENT, true);

                        events.ScheduleEvent(EVENT_TORRENT, 12 * IN_MILLISECONDS);
                        break;

                    case EVENT_FURY_OF_THE_MAW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            me->CastSpell(target, SPELL_FURY_OF_THE_MAW, true);

                        if (Creature* wave = me->SummonCreature(220, *me, TEMPSUMMON_TIMED_DESPAWN, 15000))
                        {
                            wave->SetWalk(false);
                            wave->SetReactState(REACT_PASSIVE);
                            wave->SetHealth(999999999999);
                            wave->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                            wave->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                            wave->GetMotionMaster()->MovePoint(0, 487.194f, 605.816f, 2.80f);
                            wave->CastSpell(wave, SPELL_FURY_OF_THE_MAW_AT, true);
                        }

                        if (waveCount == 0)
                        {
                            me->GetMotionMaster()->Clear();
                            me->SetFacingTo(4.29f);

                            for (uint8 i = 0; i < 22; ++i)
                                me->SummonCreature(NPC_DECAYING, decayingSpawns[i], TEMPSUMMON_DEAD_DESPAWN);
                        }

                        if (waveCount == 1 && !firstFuryOfTheMaw)
                        {
                            Talk(SAY_SUMMON_BOSS);

                            if (Creature* boatLeft = me->SummonCreature(NPC_KVALDIR_LONGBOAT, *me, TEMPSUMMON_TIMED_DESPAWN, 7000))
                            {
                                boatLeft->CastSpell(boatLeft, SPELL_LONG_BOAT2, true);
                                boatLeft->CastSpell(boatLeft, SPELL_LONG_BOAT, true);
                                boatLeft->SetWalk(false);
                                boatLeft->GetMotionMaster()->MovePoint(0, 513.408f, 604.351f, 4.439f);
                                if (Creature* nightWatchMariner = me->SummonCreature(NPC_NIGHT_WATCH_MARINER, 554.6414f, 646.1349f, 8.04011f, 0.9794775f, TEMPSUMMON_DEAD_DESPAWN))
                                    nightWatchMariner->CastSpell(boatLeft, 46598, true);
                            }

                            if (Creature* boatRight = me->SummonCreature(NPC_KVALDIR_LONGBOAT, *me, TEMPSUMMON_TIMED_DESPAWN, 7000))
                            {
                                boatRight->CastSpell(boatRight, SPELL_LONG_BOAT2, true);
                                boatRight->CastSpell(boatRight, SPELL_LONG_BOAT, true);
                                boatRight->SetWalk(false);
                                boatRight->GetMotionMaster()->MovePoint(0, 475.725f, 621.235f, 2.19f);
                                if (Creature* grimelord = me->SummonCreature(NPC_GRIMELORD, 487.194f, 605.816f, 2.80f, 5.537579f, TEMPSUMMON_DEAD_DESPAWN))
                                    grimelord->CastSpell(boatRight, 46598, true);
                            }
                            firstFuryOfTheMaw = true;
                        }

                        if (waveCount <= 8)
                        {
                            ++waveCount;

                            events.ScheduleEvent(EVENT_FURY_OF_THE_MAW, 5 * IN_MILLISECONDS);
                        }
                        else
                        {
                            waveCount = 0;
                            me->ModifyPower(POWER_ALTERNATE_POWER, -100);
                            furyOfTheMaw = false;
                        }

                        break;

                    case EVENT_MISTS_OF_HELHEIM:
                        if (!me->FindNearestCreature(220, 1000.0f, true))
                        {
                            me->ModifyPower(POWER_ALTERNATE_POWER, int32(2.222));
                            me->SetPower(POWER_ALTERNATE_POWER, me->GetPower(POWER_ALTERNATE_POWER));
                        }

                        /*for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (Player* player = i->GetSource())
                            {

                                WorldPackets::Combat::PowerUpdate packet;
                                packet.Guid = me->GetGUID();
                                /// @todo: Support multiple counts ?
                                packet.Powers.emplace_back(me->GetPower(POWER_ALTERNATE_POWER), POWER_ALTERNATE_POWER);
                                player->GetSession()->SendPacket(packet.Write());
                            }
                        }*/

                        if (me->GetDistance2d(578.031f, 792.5868f) < 1.0f && !isPhase3)
                            me->StopMoving();

                        if (isPhase2 && !furyOfTheMaw && me->GetPower(POWER_ALTERNATE_POWER) == 100)
                        {
                            events.ScheduleEvent(EVENT_FURY_OF_THE_MAW, 1 * IN_MILLISECONDS);
                            furyOfTheMaw = true;
                        }

                        events.ScheduleEvent(EVENT_MISTS_OF_HELHEIM, 0.8 * IN_MILLISECONDS);
                        break;

                    case EVENT_ORB_OF_CORROSION_CAST:
                        me->CastSpell(me, SPELL_ORB_OF_CORROSION_CAST, true);

                        events.ScheduleEvent(EVENT_ORB_OF_CORROSION, 1 * IN_MILLISECONDS);
                        break;

                    case EVENT_ORB_OF_CORROSION:

                        if (roll_chance_i(50))
                            Talk(SAY_CORROSION);
                        else
                            Talk(SAY_CORROSION2);

                        for (uint8 i = 0; i < 3; ++i)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            {
                                if (Creature* corrosion = me->SummonCreature(NPC_ORB_OF_CORROSION, *target, TEMPSUMMON_TIMED_DESPAWN, 30000))
                                {
                                    if (Player* player = corrosion->SelectNearestPlayer(500.0f))
                                        corrosion->GetMotionMaster()->MoveFollow(player, 1.0f, 0.0f);

                                    corrosion->CastSpell(corrosion, SPELL_ORB_OF_CORROSION_AURA, true);
                                    corrosion->CastSpell(corrosion, SPELL_ORB_OF_CORROSION_AURA2, true);
                                }
                            }
                        }

                        events.ScheduleEvent(EVENT_ORB_OF_CORROSION, 12 * IN_MILLISECONDS);
                        break;

                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfValorAI<boss_helya_tovAI>(creature);
    }
};

// 228054 - Taint of the sea
class spell_helya_taint_of_the_sea : public SpellScriptLoader
{
public:
    spell_helya_taint_of_the_sea() : SpellScriptLoader("spell_helya_taint_of_the_sea") { }

    class spell_helya_taint_of_the_sea_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_helya_taint_of_the_sea_AuraScript);

        void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            GetCaster()->CastSpell(GetTarget(), SPELL_TAINTED_EXPLOSION, true);
            GetCaster()->CastSpell(GetTarget(), SPELL_TAINTED_ESSENCE, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_helya_taint_of_the_sea_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_helya_taint_of_the_sea_AuraScript();
    }
};

// 227938 - Orb of Corruption damage
class spell_helya_orb_of_corruption_dmg : public SpellScriptLoader
{
public:
    spell_helya_orb_of_corruption_dmg() : SpellScriptLoader("spell_helya_orb_of_corruption_dmg") { }

    class spell_helya_orb_of_corruption_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_helya_orb_of_corruption_dmg_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return true;
        }

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, GetSpellInfo()->GetEffect(effIndex)->BasePoints, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_helya_orb_of_corruption_dmg_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_helya_orb_of_corruption_dmg_SpellScript();
    }
};

// 228062 - Orb of Corrosion damage
class spell_helya_orb_of_corrosion_dmg : public SpellScriptLoader
{
public:
    spell_helya_orb_of_corrosion_dmg() : SpellScriptLoader("spell_helya_orb_of_corrosion_dmg") { }

    class spell_helya_orb_of_corrosion_dmg_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_helya_orb_of_corrosion_dmg_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return true;
        }

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, GetSpellInfo()->GetEffect(effIndex)->BasePoints, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_helya_orb_of_corrosion_dmg_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_helya_orb_of_corrosion_dmg_SpellScript();
    }
};

// 227967 - Bilewater Breath
class spell_helya_bilewater_breath : public SpellScriptLoader
{
public:
    spell_helya_bilewater_breath() : SpellScriptLoader("spell_helya_bilewater_breath") { }

    class spell_helya_bilewater_breath_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_helya_bilewater_breath_SpellScript);

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, SPELL_BILEWATER_REDOX, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_helya_bilewater_breath_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_helya_bilewater_breath_SpellScript();
    }
};

// 114905 - Grapping Tentacle
class npc_gripping_tentacle : public CreatureScript
{
public:
    npc_gripping_tentacle() : CreatureScript("npc_gripping_tentacle") {}

    enum Events
    {
        EVENT_TENTACLE_SLAM = 1,
        EVENT_TENTACLE_STRIKE,
    };

    struct npc_gripping_tentacleAI : public ScriptedAI
    {
        npc_gripping_tentacleAI(Creature* creature) : ScriptedAI(creature)
        {
            InitializeAI();
            me->SetReactState(REACT_DEFENSIVE);
        }

        void Reset() override {}

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TENTACLE_SLAM:
                        DoCast(SPELL_TENTACLE_SLAM);

                        break;

                    case EVENT_TENTACLE_STRIKE:
                        DoCast(SPELL_TENTACLE_STRIKE);

                        break;

                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gripping_tentacleAI(creature);
    }
};

// 114553 Bilewater Slime
class npc_bilewater_slime : public CreatureScript
{
public:
    npc_bilewater_slime() : CreatureScript("npc_bilewater_slime") {}

    struct npc_bilewater_slimeAI : public ScriptedAI
    {
        npc_bilewater_slimeAI(Creature* creature) : ScriptedAI(creature)
        {
            InitializeAI();
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            me->SetFaction(14);
            me->AttackStop();
            me->CastSpell(me, 227990, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bilewater_slimeAI(creature);
    }
};

// 114812 - Night Watch Mariner
class npc_night_watch_mariner_tov : public CreatureScript
{
public:
    npc_night_watch_mariner_tov() : CreatureScript("npc_night_watch_mariner_tov") {}

    enum Events
    {
        EVENT_LANTERN_OF_DARKNESS = 1,
        EVENT_GHOSTLY_RAGE,
        EVENT_GIVE_NO_QUARTER,
        EVENT_JUMP_BOAT,
    };

    struct npc_night_watch_mariner_tovAI : public ScriptedAI
    {
        npc_night_watch_mariner_tovAI(Creature* creature) : ScriptedAI(creature)
        {
            InitializeAI();
        }

        InstanceScript* instance = me->GetInstanceScript();

        void Reset() override
        {
            events.ScheduleEvent(EVENT_LANTERN_OF_DARKNESS, 25 * IN_MILLISECONDS);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            events.ScheduleEvent(EVENT_JUMP_BOAT, 6.5 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_GHOSTLY_RAGE, 6 * IN_MILLISECONDS);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LANTERN_OF_DARKNESS:
                        DoCast(SPELL_LANTERN_OF_DARKNESS);

                        events.ScheduleEvent(EVENT_LANTERN_OF_DARKNESS, 25 * IN_MILLISECONDS);
                        break;

                    case EVENT_GHOSTLY_RAGE:
                        DoCast(SPELL_GHOSTLY_RAGE);

                        events.ScheduleEvent(EVENT_GHOSTLY_RAGE, 12 * IN_MILLISECONDS);
                        break;

                    case EVENT_GIVE_NO_QUARTER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                            me->CastSpell(target, SPELL_GIVE_NO_QUARTER, true);

                        events.ScheduleEvent(EVENT_GIVE_NO_QUARTER, 20 * IN_MILLISECONDS);
                        break;

                    case EVENT_JUMP_BOAT:
                        if (me->HasAura(46598))
                            me->RemoveAurasDueToSpell(46598);

                        me->GetMotionMaster()->MoveJump(546.672f, 625.083f, 9.988f, 0.48f, 15.0f, 5.0f);
                        break;

                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_night_watch_mariner_tovAI(creature);
    }
};

// 114709 - Grimelord
class npc_grimelord : public CreatureScript
{
public:
    npc_grimelord() : CreatureScript("npc_grimelord") {}

    enum Events
    {
        EVENT_SLUDGE_NOVA = 1,
        EVENT_ANCHOR_SLAM,
        EVENT_FETID_ROT,
        EVENT_JUMP_BOAT,
    };

    struct npc_grimelordAI : public ScriptedAI
    {
        npc_grimelordAI(Creature* creature) : ScriptedAI(creature)
        {
            InitializeAI();
        }

        InstanceScript* instance = me->GetInstanceScript();

        void Reset() override
        {
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            events.ScheduleEvent(EVENT_JUMP_BOAT, 6.5 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SLUDGE_NOVA, 15 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ANCHOR_SLAM, 6 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FETID_ROT, 30 * IN_MILLISECONDS);

            if (instance)
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SLUDGE_NOVA:
                    DoCast(SPELL_SLUDGE_NOVA);

                    events.ScheduleEvent(EVENT_SLUDGE_NOVA, 25 * IN_MILLISECONDS);
                    break;

                case EVENT_ANCHOR_SLAM:
                    DoCast(SPELL_ANCHOR_SLAM);

                    events.ScheduleEvent(EVENT_ANCHOR_SLAM, 12 * IN_MILLISECONDS);
                    break;

                case EVENT_FETID_ROT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true))
                        me->CastSpell(target, SPELL_FETID_ROT, true);

                    events.ScheduleEvent(EVENT_FETID_ROT, 20 * IN_MILLISECONDS);
                    break;

                case EVENT_JUMP_BOAT:
                    if (me->HasAura(46598))
                        me->RemoveAurasDueToSpell(46598);

                    me->GetMotionMaster()->MoveJump(454.174f, 673.818f, 11.190f, 1.52f, 15.0f, 5.0f);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_grimelordAI(creature);
    }
};

// 114568 - Decaying Minion
class npc_decaying_minion : public CreatureScript
{
public:
    npc_decaying_minion() : CreatureScript("npc_decaying_minion") {}

    enum Events
    {
        EVENT_RABID = 1,
        EVENT_VIGOR,
    };

    struct npc_decaying_minionAI : public ScriptedAI
    {
        npc_decaying_minionAI(Creature* creature) : ScriptedAI(creature)
        {
            InitializeAI();
        }

        ObjectGuid targetGuid;

        void Reset() override
        {
            targetGuid = ObjectGuid::Empty;

            events.ScheduleEvent(EVENT_RABID, 1 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_VIGOR, 6 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_RABID:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true))
                    {
                        targetGuid = target->GetGUID();
                        me->SetTarget(targetGuid);
                        me->AI()->AttackStart(target);
                    }

                    DoCast(SPELL_RABID);
                    break;

                case EVENT_VIGOR:
                    DoCast(SPELL_VIGOR);

                    events.ScheduleEvent(EVENT_VIGOR, 12 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_decaying_minionAI(creature);
    }
};

// 228027
class areatrigger_helya_fury_of_the_maw : public AreaTriggerEntityScript
{
public:
    areatrigger_helya_fury_of_the_maw() : AreaTriggerEntityScript("areatrigger_helya_fury_of_the_maw") { }

    struct areatrigger_helya_fury_of_the_mawAI : AreaTriggerAI
    {
        areatrigger_helya_fury_of_the_mawAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 damageTimer;
        Unit* caster = at->GetCaster();
        std::list<Unit*> targets;
        bool canKnockBack;

        void OnInitialize() override
        {
            damageTimer = 1000;
            //UPDATE `areatrigger_template` SET `Flags`= 4 WHERE `Id` IN (12897, 12879);
            //AreaTriggerTemplate const* attemplate = at->GetTemplate();
            //attemplate.Flags = 4;
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (!unit || unit->GetTypeId() != TYPEID_PLAYER)
                return;

            canKnockBack = true;

            if (!targets.empty())
            {
                for (auto target : targets)
                    if (unit == target)
                        canKnockBack = false;
            }

            if (canKnockBack)
                unit->SendMoveKnockBack(unit->ToPlayer(), 12.5f, -7.5f, -0.05161246f, -0.9986672f);

            targets.push_back(unit);

            if (!unit->HasAura(SPELL_FURY_OF_THE_MAW_DMG))
                caster->CastSpell(unit, SPELL_FURY_OF_THE_MAW_DMG, true);

            if (unit->HasAura(SPELL_BILEWATER_LIQUEFACTION_DMG))
                unit->RemoveAurasDueToSpell(SPELL_BILEWATER_LIQUEFACTION_DMG);

            if (unit->HasAura(SPELL_DECAY_DMG))
                unit->RemoveAurasDueToSpell(SPELL_DECAY_DMG);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_helya_fury_of_the_mawAI(areatrigger);
    }
};

// 228121
class areatrigger_helya_decay : public AreaTriggerEntityScript
{
public:
    areatrigger_helya_decay() : AreaTriggerEntityScript("areatrigger_helya_decay") { }

    struct areatrigger_helya_decayAI : AreaTriggerAI
    {
        areatrigger_helya_decayAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 damageTimer;
        Unit* caster = at->GetCaster();
        std::list<Unit*> targets;

        void OnInitialize() override
        {
            damageTimer = 1000;
        }

        void OnUpdate(uint32 diff) override
        {
            if (damageTimer <= diff)
            {
                if (!targets.empty())
                {
                    for (auto target : targets)
                        if (!target->HasAura(SPELL_DECAY_DMG))
                            caster->CastSpell(target, SPELL_DECAY_DMG, true);
                }

                damageTimer = 1000;
            }
            else
                damageTimer -= diff;
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->GetTypeId() == TYPEID_PLAYER)
                targets.push_back(unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->GetTypeId() == TYPEID_PLAYER)
                targets.push_back(unit);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_helya_decayAI(areatrigger);
    }
};

void AddSC_boss_helya_tov()
{
    new boss_helya_tov();
    new spell_helya_taint_of_the_sea();
    new spell_helya_orb_of_corruption_dmg();
    new spell_helya_orb_of_corrosion_dmg();
    new spell_helya_bilewater_breath();
    new npc_gripping_tentacle();
    new npc_bilewater_slime();
    new npc_night_watch_mariner_tov();
    new npc_grimelord();
    new npc_decaying_minion();
    new areatrigger_helya_fury_of_the_maw();
    new areatrigger_helya_decay();
}

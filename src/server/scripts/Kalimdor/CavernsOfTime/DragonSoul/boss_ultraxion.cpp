/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/* ScriptData
SDName: boss_ultraxion
Author: Bennu
SD%Complete: 100% (Oh yes!)
SDComment:
SDCategory: Boss Ultraxion
EndScriptData
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "dragon_soul.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "GameObject.h"

enum ScriptedTexts
{
    SAY_INTRO      = 0,
    SAY_AGGRO      = 1,
    SAY_ERUPTION   = 2,
    SAY_DEATH      = 3,
    SAY_KILL       = 4,
    SAY_TWILIGHT   = 5,
};

enum Events
{
    EVENT_START_FIGHT = 1,
    EVENT_TWILIGHT_ERUPTION,
    EVENT_TWILIGHT_BURST,
    EVENT_FADING_LIGHT,
    EVENT_HOUR_OF_TWILIGHT,
    EVENT_INTRO,
    EVENT_UNSTABLE_MONSTROSITY,
    // Aspect buff
    EVENT_THRALL_BUFF,
    EVENT_ALEXSTRASZA_BUFF,
    EVENT_YSERA_BUFF,
    EVENT_KALECGOS_BUFF,
    EVENT_NOZDORMU_BUFF,
};

enum Actions
{
    ACTION_LAST_DEF_OF_AZEROTH,
    ACTION_GIFT_OF_LIFE,
    ACTION_ESSENCE_OF_DREAMS,
    ACTION_SOURCE_OF_MAGIC,
    ACTION_TIMELOOP,
};

enum Spells
{
    SPELL_TWILIGHT_SHIFT            = 106369,
    SPELL_TWILIGHT_SHIFT_AURA       = 106368,
    SPELL_TWILIGHT_INSTABILITY      = 109176,
    SPELL_TWILIGHT_INSTABILITY_DMG  = 106375,
    SPELL_TWILIGHT_INSTABILITY_DUMMY= 106374,
    SPELL_HOUR_OF_TWILIGHT          = 106371,
    SPELL_HOUR_OF_TWILIGHT_CHECK    = 106370,
    SPELL_TWILIGHT_BURST            = 106415,
    SPELL_TWILIGHT_ERUPTION         = 106388,
    SPELL_LOOMING_DARKNESS_DEBUFF   = 106498,
    SPELL_LOOMING_DARKNESS          = 109231,
    SPELL_FADING_LIGHT              = 109075,
    SPELL_FADING_LIGHT_PERIOD       = 105925,
    SPELL_FADING_LIGHT_DPS          = 109075,
    SPELL_FADING_LIGHT_KILL         = 105926,
    SPELL_HEROIC_WILL_BUTTON        = 105554,
    SPELL_HEROIC_WILL_AURA          = 106108,
    SPELL_UNSTABLE_MONSTROSITY_6    = 106372,
    SPELL_UNSTABLE_MONSTROSITY_5    = 106376,
    SPELL_UNSTABLE_MONSTROSITY_4    = 106377,
    SPELL_UNSTABLE_MONSTROSITY_3    = 106378,
    SPELL_UNSTABLE_MONSTROSITY_2    = 106379,
    SPELL_UNSTABLE_MONSTROSITY_1    = 106380,
    SPELL_FADED_INTO_TWILIGHT       = 105927,
    SPELL_INTRO_COSMETIC            = 109405,

    // Aspects Debuff
    SPELL_LAST_DEF_OF_AZEROTH_DUMMY = 110327,
    SPELL_LAST_DEF_OF_AZEROTH_PROC  = 106182,
    SPELL_LAST_DEF_OF_AZEROTH_WARR  = 106080,
    SPELL_LAST_DEF_OF_AZEROTH_DRUID = 106224,
    SPELL_LAST_DEF_OF_AZEROTH_PALA  = 106226,
    SPELL_LAST_DEF_OF_AZEROTH_DK    = 106227,
    SPELL_TIMELOOP_HEAL             = 105992,
    SPELL_ESSENCE_OF_DREAMS_HEAL    = 105996,

    // Tank Stances
    SPELL_BLOOD_PRESENCE            = 48263,
    SPELL_RIGHTEOUS_FURY            = 25780,
    SPELL_DEFENSIVE_STANCE          = 71,
    SPELL_BEAR_FORM                 = 5487,
};

class boss_ultraxion : public CreatureScript
{
public:
    boss_ultraxion() : CreatureScript("boss_ultraxion") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ultraxionAI(creature);
    }

    struct boss_ultraxionAI: public BossAI
    {
        boss_ultraxionAI(Creature* creature) : BossAI(creature, DATA_ULTRAXION)
        {
            instance = creature->GetInstanceScript();
        }

        bool bIntro;
        InstanceScript* instance;
        EventMap events;

        void InitializeAI() override
        {
            Talk(SAY_INTRO);

            bIntro = false;
            _UnstableCounter = 0;
            DoZoneInCombat(me);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->MovePoint(0, ultraxionPos[1]);
            me->SetSpeed(MOVE_FLIGHT, 0.5f);
            //me->SetPhaseMask(17, true);

            events.ScheduleEvent(EVENT_INTRO, 1000);
            events.ScheduleEvent(EVENT_START_FIGHT, 26000);
        }

        void Reset() override
        {
            _Reset();
            _UnstableCounter = 0;
            events.Reset();
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEROIC_WILL_BUTTON);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEROIC_WILL_AURA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_AURA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_WARR);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_DRUID);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_PALA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_DK);

            for (uint32 x = 0; x <= 2; x++)
            {
                if (GameObject* crystal = me->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_GOOBER, 100.0f))
                    crystal->RemoveFromWorld();
            }

            if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_1, 200.0f, true))
                thrall->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            me->DespawnOrUnsummon();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            bIntro = true;
            _EnterCombat();
        }

        void UpdateAI(uint32 diff) override

        {
            if (bIntro == true)
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {

                case EVENT_INTRO:
                    DoCast(me, SPELL_INTRO_COSMETIC);
                    DoCast(me, SPELL_HEROIC_WILL_BUTTON);
                    DoCast(me, SPELL_TWILIGHT_SHIFT);
                    events.ScheduleEvent(EVENT_INTRO, 2000);
                    break;

                case EVENT_START_FIGHT:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(me, SPELL_UNSTABLE_MONSTROSITY_6);

                    events.CancelEvent(EVENT_INTRO);
                    events.ScheduleEvent(EVENT_TWILIGHT_ERUPTION, 360000);
                    events.ScheduleEvent(EVENT_HOUR_OF_TWILIGHT, 45000);
                    events.ScheduleEvent(EVENT_TWILIGHT_BURST, 10000);
                    events.ScheduleEvent(EVENT_UNSTABLE_MONSTROSITY, 60000);
                    events.ScheduleEvent(EVENT_THRALL_BUFF, 500);
                    events.ScheduleEvent(EVENT_ALEXSTRASZA_BUFF, 90000);
                    events.ScheduleEvent(EVENT_YSERA_BUFF, 150000);
                    events.ScheduleEvent(EVENT_KALECGOS_BUFF, 210000);
                    events.ScheduleEvent(EVENT_NOZDORMU_BUFF, 300000);
                    break;

                case EVENT_THRALL_BUFF:
                    if (Creature* thrall = me->FindNearestCreature(NPC_THRALL_1, 200.0f, true))
                        thrall->AI()->DoAction(ACTION_LAST_DEF_OF_AZEROTH);
                    break;

                case EVENT_ALEXSTRASZA_BUFF:
                    if (Creature* alexs = me->FindNearestCreature(NPC_ALEXTRASZA_THE_LIFE_BINDER, 200.0f, true))
                        alexs->AI()->DoAction(ACTION_GIFT_OF_LIFE);
                    break;

                case EVENT_YSERA_BUFF:
                    if (Creature* ysera = me->FindNearestCreature(NPC_YSERA_THE_AWAKENED, 50.0f, true))
                        ysera->AI()->DoAction(ACTION_ESSENCE_OF_DREAMS);
                    break;

                case EVENT_KALECGOS_BUFF:
                    if (Creature* kalec = me->FindNearestCreature(NPC_KALECGOS, 50.0f, true))
                        kalec->AI()->DoAction(ACTION_SOURCE_OF_MAGIC);
                    break;

                case EVENT_NOZDORMU_BUFF:
                    if (Creature* noz = me->FindNearestCreature(NPC_NOZDORMU_THE_TIMELESS_ONE, 50.0f, true))
                        noz->AI()->DoAction(ACTION_TIMELOOP);
                    break;

                case EVENT_TWILIGHT_ERUPTION:
                    Talk(SAY_ERUPTION);

                    DoCast(me, SPELL_TWILIGHT_ERUPTION);
                    break;

                case EVENT_TWILIGHT_BURST:
                    {
                        std::list<Player*> targets;
                        me->GetPlayerListInGrid(targets, 80.0f);

                        if (targets.size() == 0)
                        {
                            DoCast(me, SPELL_TWILIGHT_BURST);
                        }

                        events.ScheduleEvent(EVENT_TWILIGHT_BURST, 1000);
                    }
                    break;

                case EVENT_UNSTABLE_MONSTROSITY:

                    if (_UnstableCounter == 0)
                        DoCast(me, SPELL_UNSTABLE_MONSTROSITY_5);
                    else if (_UnstableCounter == 1)
                        DoCast(me, SPELL_UNSTABLE_MONSTROSITY_4);
                    else if (_UnstableCounter == 2)
                        DoCast(me, SPELL_UNSTABLE_MONSTROSITY_3);
                    else if (_UnstableCounter == 3)
                        DoCast(me, SPELL_UNSTABLE_MONSTROSITY_2);
                    else
                        DoCast(me, SPELL_UNSTABLE_MONSTROSITY_1);

                    _UnstableCounter++;
                    events.ScheduleEvent(EVENT_UNSTABLE_MONSTROSITY, 60000);
                    break;

                case EVENT_HOUR_OF_TWILIGHT:
                    Talk(SAY_TWILIGHT);

                    DoCast(me, SPELL_HOUR_OF_TWILIGHT);
                    events.ScheduleEvent(EVENT_HOUR_OF_TWILIGHT, 45000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* killer) override
        {
            Talk(SAY_DEATH);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            instance->SetBossState(DATA_ULTRAXION, DONE);

            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEROIC_WILL_BUTTON);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEROIC_WILL_AURA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_SHIFT_AURA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GIFT_OF_LIFE_BUFF);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ESSENCE_OF_DREAMS_BUFF);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOURCE_OF_MAGIC_BUFF);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TIMELOOP);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_WARR);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_DRUID);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_PALA);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAST_DEF_OF_AZEROTH_DK);

            for (uint32 x = 0; x <= 2; x++)
            {
                if (WorldObject* crystal = me->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_GOOBER, 100.0f))
                    crystal->RemoveFromWorld();
            }

            killer->SummonGameObject(RAID_MODE(GO_LESSER_CACHE_OF_THE_ASPECTS_10N, GO_LESSER_CACHE_OF_THE_ASPECTS_25N, GO_LESSER_CACHE_OF_THE_ASPECTS_10H, GO_LESSER_CACHE_OF_THE_ASPECTS_25H), -1753.63f, -2370.01f, 340.845f, 4.8f, QuaternionData(0.0f, 0.0f, -0.66913f, 0.743145f), 100000);
            _JustDied();
        }

    private:
        uint32 _UnstableCounter;

    };
};

class go_aspect_gift : public GameObjectScript
{
public:
    go_aspect_gift() : GameObjectScript("go_aspect_gift") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (player->GetSpecializationId() == TALENT_SPEC_PRIEST_HOLY         ||
            player->GetSpecializationId() == TALENT_SPEC_PRIEST_DISCIPLINE   ||
            player->GetSpecializationId() == TALENT_SPEC_PALADIN_HOLY        ||
            player->GetSpecializationId() == TALENT_SPEC_DRUID_RESTORATION   ||
            player->GetSpecializationId() == TALENT_SPEC_SHAMAN_RESTORATION )
            return false;

        return true;
    }
};

class spell_hour_of_twilight : public SpellScriptLoader
{
public:
    spell_hour_of_twilight() : SpellScriptLoader("spell_hour_of_twilight") { }

    class spell_hour_of_twilight_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hour_of_twilight_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_HOUR_OF_TWILIGHT))
                return false;
            return true;
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();

            if (Unit* caster = aurEff->GetCaster())
                if (Unit* victim = caster->GetVictim())
                    caster->CastSpell(victim, SPELL_FADING_LIGHT_PERIOD);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_hour_of_twilight_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hour_of_twilight_AuraScript();
    }
};

class TankCheck
{
public:
    TankCheck() { }

    bool operator()(WorldObject* unit)
    {
        return (!unit->ToUnit() || !(unit->ToUnit()->HasAura(SPELL_FADING_LIGHT_DPS)));
    }
};

class DarknessCheck
{
public:
    DarknessCheck() { }

    bool operator()(WorldObject* unit)
    {
        return (!unit->ToUnit() || !(unit->ToUnit()->HasAura(SPELL_LOOMING_DARKNESS_DEBUFF)));
    }
};

class RealmCheck
{
public:
    RealmCheck() { }

    bool operator()(WorldObject* unit)
    {
        return (!unit->ToUnit() || !(unit->ToUnit()->HasAura(SPELL_TWILIGHT_SHIFT_AURA)));
    }
};

class spell_hour_of_twilight_kill : public SpellScriptLoader
{

public:
    spell_hour_of_twilight_kill() : SpellScriptLoader("spell_hour_of_twilight_kill") { }

    class spell_hour_of_twilight_kill_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hour_of_twilight_kill_SpellScript);

        void FilterDamage(std::list<WorldObject*>& targets)
        {
            targets.remove_if(RealmCheck());
            TargetNumber = targets;
        }

        void FilterLooming(std::list<WorldObject*>& targets)
        {
            if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_10_N)
            {
                if (TargetNumber.size() < 1)
                    return;
                else
                    targets.clear();
            }

            if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_N)
            {
                if (TargetNumber.size() < 3)
                    return;
                else
                    targets.clear();
            }

            if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC)
            {
                if (TargetNumber.size() < 2)
                    return;
                else
                {
                    targets = TargetNumber;
                    targets.remove_if(DarknessCheck());
                }
            }

            if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
            {
                if (TargetNumber.size() < 5)
                    return;
                else
                {
                    targets = TargetNumber;
                    targets.remove_if(DarknessCheck());
                }
            }
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (GetHitUnit())
                    caster->CastSpell(caster, SPELL_TWILIGHT_SHIFT);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hour_of_twilight_kill_SpellScript::FilterDamage, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hour_of_twilight_kill_SpellScript::FilterLooming, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hour_of_twilight_kill_SpellScript::FilterDamage, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_hour_of_twilight_kill_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

        std::list<WorldObject*> TargetNumber;

    private:

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hour_of_twilight_kill_SpellScript();
    }
};

class spell_fading_light : public SpellScriptLoader
{
    public:
        spell_fading_light() : SpellScriptLoader("spell_fading_light") { }

        class spell_fading_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_fading_light_AuraScript);

            void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                aurEff->GetBase()->SetDuration(urand(5000, 10000));
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    if (!owner->HasAura(SPELL_HEROIC_WILL_AURA))
                        owner->CastSpell(owner, SPELL_FADING_LIGHT_KILL, true);
                    else
                    {
                        owner->CastSpell(owner, SPELL_FADED_INTO_TWILIGHT);
                        owner->RemoveAurasDueToSpell(SPELL_FADING_LIGHT_PERIOD);
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_fading_light_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_fading_light_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_fading_light_AuraScript();
        }
};

class NotVictimFilter
{
    public:
        NotVictimFilter(Unit* caster) : _victim(caster->GetVictim()){}

        bool operator()(WorldObject* target)
        {
            return target == _victim;
        }

    private:
        Unit* _victim;
};

class spell_fading_light_dps : public SpellScriptLoader
{
    public:
        spell_fading_light_dps() : SpellScriptLoader("spell_fading_light_dps") { }

    class spell_fading_light_dps_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_fading_light_dps_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {

            if (Unit* caster = GetCaster())
            {
                std::list<Player*> players;
                std::list<WorldObject*> dpsTargets;
                caster->GetPlayerListInGrid(players, 500.0f);

                for (auto player : players)
                {
                    if (player->GetSpecializationId() != TALENT_SPEC_PRIEST_HOLY        &&
                        player->GetSpecializationId() != TALENT_SPEC_PRIEST_DISCIPLINE  &&
                        player->GetSpecializationId() != TALENT_SPEC_PALADIN_HOLY       &&
                        player->GetSpecializationId() != TALENT_SPEC_DRUID_RESTORATION  &&
                        player->GetSpecializationId() != TALENT_SPEC_SHAMAN_RESTORATION &&
                        player->GetSpecializationId() != TALENT_SPEC_WARRIOR_PROTECTION &&
                        player->GetSpecializationId() != TALENT_SPEC_DEATHKNIGHT_BLOOD &&
                        player->GetSpecializationId() != TALENT_SPEC_PALADIN_PROTECTION &&
                        player->GetSpecializationId() != TALENT_SPEC_DRUID_BEAR)
                        dpsTargets.push_back(player);
                }

                targets = dpsTargets;

                targets.remove_if(NotVictimFilter(GetCaster()));

                if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_10_N)
                    Trinity::Containers::RandomResize(targets, 1);
                else if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC)
                    Trinity::Containers::RandomResize(targets, 2);
                else if (GetCaster()->GetMap() && GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_25_N)
                    Trinity::Containers::RandomResize(targets, 3);
                else
                    Trinity::Containers::RandomResize(targets, 6);
            }

        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fading_light_dps_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_fading_light_dps_SpellScript();
    }

    class spell_fading_light_dps_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_fading_light_dps_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_FADING_LIGHT_DPS))
                return false;
            return true;
        }

        void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            aurEff->GetBase()->SetDuration(urand(5000, 10000));
        }

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* owner = GetUnitOwner())
            {
                if (!owner->HasAura(SPELL_HEROIC_WILL_AURA))
                    owner->CastSpell(owner, SPELL_FADING_LIGHT_KILL, true);
                else
                {
                    owner->CastSpell(owner, SPELL_FADED_INTO_TWILIGHT);
                }
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_fading_light_dps_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_fading_light_dps_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

    };

        AuraScript* GetAuraScript() const override
        {
            return new spell_fading_light_dps_AuraScript();
        }
};

class spell_heroic_will : public SpellScriptLoader
{
    public:
        spell_heroic_will() : SpellScriptLoader("spell_heroic_will") { }

        class spell_heroic_will_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_heroic_will_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                    if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                        owner->CastSpell(owner, SPELL_TWILIGHT_SHIFT_AURA);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_heroic_will_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_PACIFY_SILENCE, AURA_EFFECT_HANDLE_REAL);
            }

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_heroic_will_AuraScript();
        }
};

class spell_twilight_instability : public SpellScriptLoader
{

public:
    spell_twilight_instability() : SpellScriptLoader("spell_twilight_instability") { }

    class spell_twilight_instability_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_twilight_instability_SpellScript);

        void FilterTarget(std::list<WorldObject*>& targets)
        {
            targets.remove_if(RealmCheck());
            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, SPELL_TWILIGHT_INSTABILITY_DMG);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_twilight_instability_SpellScript::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_twilight_instability_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }

    private:

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_twilight_instability_SpellScript();
    }
};

class spell_last_defender_of_azeroth : public SpellScriptLoader
{

public:
    spell_last_defender_of_azeroth() : SpellScriptLoader("spell_last_defender_of_azeroth") { }

    class spell_last_defender_of_azeroth_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_last_defender_of_azeroth_SpellScript);

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (GetHitUnit())
                {
                    caster->CastSpell(caster, SPELL_LAST_DEF_OF_AZEROTH_PROC);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_last_defender_of_azeroth_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }

    private:

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_last_defender_of_azeroth_SpellScript();
    }
};

class spell_last_defender_of_azeroth_dummy : public SpellScriptLoader
{

public:
    spell_last_defender_of_azeroth_dummy() : SpellScriptLoader("spell_last_defender_of_azeroth_dummy") { }

    class spell_last_defender_of_azeroth_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_last_defender_of_azeroth_dummy_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
            {
                if (target->HasAura(SPELL_BLOOD_PRESENCE))
                    target->CastSpell(target, SPELL_LAST_DEF_OF_AZEROTH_DK);
                else if (target->HasAura(SPELL_RIGHTEOUS_FURY))
                    target->CastSpell(target, SPELL_LAST_DEF_OF_AZEROTH_PALA);
                else if (target->HasAura(SPELL_BEAR_FORM))
                    target->CastSpell(target, SPELL_LAST_DEF_OF_AZEROTH_DRUID);
                else if (target->HasAura(SPELL_DEFENSIVE_STANCE))
                    target->CastSpell(target, SPELL_LAST_DEF_OF_AZEROTH_WARR);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_last_defender_of_azeroth_dummy_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

    private:

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_last_defender_of_azeroth_dummy_SpellScript();
    }
};

class spell_timeloop : public SpellScriptLoader
{
    public:
        spell_timeloop() : SpellScriptLoader("spell_timeloop") { }

        class spell_timeloop_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_timeloop_AuraScript);

            uint32 absorbChance;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TIMELOOP))
                    return false;
                return true;
            }

            bool Load() override
            {
                absorbChance = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
                return GetUnitOwner()->ToPlayer();
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                if (Unit* target = GetTarget())
                    if (GetTarget()->ToPlayer())
                    {
                        if (dmgInfo.GetDamage() < target->GetHealth() || !roll_chance_i(absorbChance))
                            return;

                        int32 bp0 = target->GetMaxHealth();

                        absorbAmount = dmgInfo.GetDamage();

                        target->CastCustomSpell(target, SPELL_TIMELOOP_HEAL, &bp0, 0, 0, true);
                        target->RemoveAurasDueToSpell(SPELL_TIMELOOP);
                    }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_timeloop_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_timeloop_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_timeloop_AuraScript();
        }
};

class spell_essence_of_dreams : public SpellScriptLoader
{
public:
    spell_essence_of_dreams() : SpellScriptLoader("spell_essence_of_dreams") { }

    class spell_essence_of_dreams_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_essence_of_dreams_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            if (Unit* owner = GetOwner()->ToPlayer())
            {
                if (owner->ToPlayer())
                {
                    int32 bp0 = eventInfo.GetHealInfo()->GetHeal() * 2;
                    std::list<Player*> targets;
                    owner->GetPlayerListInGrid(targets, 50.0f);

                    if (targets.empty())
                        return;

                    bp0 /= targets.size();

                    owner->CastCustomSpell(owner, SPELL_ESSENCE_OF_DREAMS_HEAL, &bp0, 0, 0, true);
                    owner->CastSpell(owner ,SPELL_ESSENCE_OF_DREAMS_BUFF);
                }

            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_essence_of_dreams_AuraScript::OnProc, EFFECT_1, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_essence_of_dreams_AuraScript();
    }
};

void AddSC_boss_ultraxion()
{
    new boss_ultraxion();
    new go_aspect_gift();
    new spell_hour_of_twilight();
    new spell_hour_of_twilight_kill();
    new spell_fading_light();
    new spell_fading_light_dps();
    new spell_heroic_will();
    new spell_twilight_instability();
    new spell_last_defender_of_azeroth();
    new spell_last_defender_of_azeroth_dummy();
    new spell_timeloop();
    new spell_essence_of_dreams();
}

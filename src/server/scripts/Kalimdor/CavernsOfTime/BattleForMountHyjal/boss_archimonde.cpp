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

/*
 * Is SAY_CHARM used somehow?
 * The way In-Combat Finger of Death is used requires additional research, it is not handled entirely
   correctly but the correct approach is unknown
 * Combat timers requires to be revisited
 * Archimonde should have big aggro radius
 * SPELL_SOUL_CHARGE_AURA is used but the exact usage and purpose is unknown
 * The way souls are unleashed requires additional research. Proc of auras is disabled, doesn't seem like they proc
 * The way Hand of Death is handled if Archimonde reaches Nordrassil requires additional research (exact distance or position are unknown)
 */

#include "ScriptMgr.h"
#include "hyjal.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum ArchimondeTexts
{
    SAY_INTRO                        = 0,
    SAY_AGGRO                        = 1,
    SAY_CHARM                        = 2,
    SAY_AIR_BURST                    = 3,
    SAY_DOOMFIRE                     = 4,
    SAY_SLAY                         = 5,
    SAY_DEATH                        = 6,
    SAY_ENRAGE                       = 7
};

enum ArchimondeSpells
{
    // Intro
    SPELL_DRAIN_WORLD_TREE_VISUAL    = 39140,

    // Combat
    SPELL_FINGER_OF_DEATH_COOLUP     = 39314,
    SPELL_FINGER_OF_DEATH            = 31984,
    SPELL_FEAR                       = 31970,
    SPELL_GRIP_OF_THE_LEGION         = 31972,
    SPELL_AIR_BURST                  = 32014,
    SPELL_DOOMFIRE_STRIKE            = 31903,
    SPELL_HAND_OF_DEATH              = 35354,

    SPELL_SOUL_CHARGE_AURA           = 32044,
    SPELL_SOUL_CHARGE_YELLOW         = 32045,
    SPELL_SOUL_CHARGE_GREEN          = 32051,
    SPELL_SOUL_CHARGE_RED            = 32052,
    SPELL_UNLEASH_SOUL_YELLOW        = 32054,
    SPELL_UNLEASH_SOUL_GREEN         = 32057,
    SPELL_UNLEASH_SOUL_RED           = 32053,

    // Epilogue
    SPELL_PROTECTION_OF_ELUNE        = 38528,
    SPELL_SUMMON_WISP                = 32114,
    SPELL_FINGER_OF_DEATH_NPC        = 32111,
    SPELL_FINGER_OF_DEATH_PLAYER     = 39369,
    SPELL_DENOUEMENT_WISP            = 32124,
    SPELL_DENOUEMENT                 = 32116,

    // Doomfire
    SPELL_DOOMFIRE_SPAWN             = 32074,
    SPELL_DOOMFIRE                   = 31945,

    // Ancient Wisp
    SPELL_ANCIENT_SPARK              = 39349,

    // Scripts
    SPELL_DRAIN_WORLD_TREE_VISUAL_2  = 39141,
    SPELL_RESIDUE_OF_ETERNITY        = 42205
};

enum ArchimondeEvents
{
    // Intro
    EVENT_DRAIN_WORLD_TREE           = 1,

    // Combat
    EVENT_FINGER_OF_DEATH_COOLUP,
    EVENT_FINGER_OF_DEATH,
    EVENT_FEAR,
    EVENT_GRIP_OF_THE_LEGION,
    EVENT_AIR_BURST,
    EVENT_DOOMFIRE,
    EVENT_HAND_OF_DEATH,
    EVENT_DISTANCE_CHECK,

    EVENT_UNLEASH_SOUL_YELLOW,
    EVENT_UNLEASH_SOUL_GREEN,
    EVENT_UNLEASH_SOUL_RED,

    // Epilogue
    EVENT_EPILOGUE_1,
    EVENT_EPILOGUE_2,
    EVENT_EPILOGUE_3,

    // Epilogue: Repeatable
    EVENT_SUMMON_WHISP,
    EVENT_FINGER_OF_DEATH_NPC,
    EVENT_FINGER_OF_DEATH_PLAYER
};

enum ArchimondeMisc
{
    SOUND_HORN                       = 10843,
    MUSIC_EPILOGUE                   = 11731,
    POINT_EPILOGUE                   = 0,
    POINT_DOOMFIRE                   = 0,
    GUID_DOOMFIRE                    = 0,
    NPC_DOOMFIRE                     = 18095,
    NPC_DOOMFIRE_SPIRIT              = 18104
};

Position const EpiloguePosition = { 5600.375f, -3458.6353f, 1577.3046f, 0.0f };
Position const NordrassilPosition = { 5503.713f, -3523.436f, 1608.781f, 0.0f };

// 17968 - Archimonde
struct boss_archimonde : public BossAI
{
    boss_archimonde(Creature* creature) : BossAI(creature, DATA_ARCHIMONDE), _isEpilogueStarted(false) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_DRAIN_WORLD_TREE, 0s);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        me->InterruptSpell(CURRENT_CHANNELED_SPELL);

        Talk(SAY_AGGRO);

        events.CancelEvent(EVENT_DRAIN_WORLD_TREE);
        events.ScheduleEvent(EVENT_FINGER_OF_DEATH_COOLUP, 15s, 20s);
        events.ScheduleEvent(EVENT_FEAR, 30s, 50s);
        events.ScheduleEvent(EVENT_GRIP_OF_THE_LEGION, 5s, 25s);
        events.ScheduleEvent(EVENT_AIR_BURST, 10s, 30s);
        events.ScheduleEvent(EVENT_DOOMFIRE, 9s);
        events.ScheduleEvent(EVENT_HAND_OF_DEATH, 10min);
        events.ScheduleEvent(EVENT_DISTANCE_CHECK, 5s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_AIR_BURST:
                if (roll_chance_i(50))
                    Talk(SAY_AIR_BURST);
                break;
            case SPELL_DOOMFIRE_STRIKE:
                if (roll_chance_i(50))
                    Talk(SAY_DOOMFIRE);
                break;
            case SPELL_HAND_OF_DEATH:
                Talk(SAY_ENRAGE);
                break;
            case SPELL_UNLEASH_SOUL_YELLOW:
                me->RemoveAuraFromStack(SPELL_SOUL_CHARGE_YELLOW);
                break;
            case SPELL_UNLEASH_SOUL_GREEN:
                me->RemoveAuraFromStack(SPELL_SOUL_CHARGE_GREEN);
                break;
            case SPELL_UNLEASH_SOUL_RED:
                me->RemoveAuraFromStack(SPELL_SOUL_CHARGE_RED);
                break;
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_FINGER_OF_DEATH_COOLUP:
                events.RescheduleEvent(EVENT_FINGER_OF_DEATH, 0s);
                break;
            case SPELL_SOUL_CHARGE_YELLOW:
                events.ScheduleEvent(EVENT_UNLEASH_SOUL_YELLOW, 0s, 45s);
                break;
            case SPELL_SOUL_CHARGE_GREEN:
                events.ScheduleEvent(EVENT_UNLEASH_SOUL_GREEN, 0s, 45s);
                break;
            case SPELL_SOUL_CHARGE_RED:
                events.ScheduleEvent(EVENT_UNLEASH_SOUL_RED, 0s, 45s);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && who != me)
        {
            damage = me->GetHealth() -1;
        }

        if (!_isEpilogueStarted && me->HealthBelowPctDamaged(10, damage))
        {
            _isEpilogueStarted = true;

            events.ScheduleEvent(EVENT_EPILOGUE_1, 0s);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE && pointId == POINT_EPILOGUE)
            events.ScheduleEvent(EVENT_EPILOGUE_2, 0s);
    }

    void JustSummoned(Creature* summoned) override
    {
        switch (summoned->GetEntry())
        {
            case NPC_DOOMFIRE_SPIRIT:
                _doomfireSpiritGUID = summoned->GetGUID();
                break;
            case NPC_DOOMFIRE:
                summoned->AI()->SetGUID(_doomfireSpiritGUID, GUID_DOOMFIRE);
                _doomfireSpiritGUID.Clear();
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ARCHIMONDE_INTRO)
            Talk(SAY_INTRO);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_SLAY);

            switch (victim->GetClass())
            {
                case CLASS_PRIEST:
                case CLASS_PALADIN:
                case CLASS_WARLOCK:
                    victim->CastSpell(victim, SPELL_SOUL_CHARGE_RED, true);
                    break;
                case CLASS_MAGE:
                case CLASS_ROGUE:
                case CLASS_WARRIOR:
                    victim->CastSpell(victim, SPELL_SOUL_CHARGE_YELLOW, true);
                    break;
                case CLASS_DRUID:
                case CLASS_SHAMAN:
                case CLASS_HUNTER:
                    victim->CastSpell(victim, SPELL_SOUL_CHARGE_GREEN, true);
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DRAIN_WORLD_TREE:
                        DoCastSelf(SPELL_DRAIN_WORLD_TREE_VISUAL);
                        events.Repeat(16900ms);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Combat
                case EVENT_FINGER_OF_DEATH_COOLUP:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastSelf(SPELL_FINGER_OF_DEATH_COOLUP);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_FINGER_OF_DEATH:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 200.0f, true))
                            DoCast(target, SPELL_FINGER_OF_DEATH);
                        events.Repeat(1200ms);
                    }
                    break;
                case EVENT_FEAR:
                    DoCastSelf(SPELL_FEAR);
                    events.Repeat(30s, 50s);
                    break;
                case EVENT_GRIP_OF_THE_LEGION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f, true, true, -SPELL_GRIP_OF_THE_LEGION))
                        DoCast(target, SPELL_GRIP_OF_THE_LEGION);
                    events.Repeat(5s, 25s);
                    break;
                case EVENT_AIR_BURST:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 60.0f, true))
                        DoCast(target, SPELL_AIR_BURST);
                    events.Repeat(25s, 40s);
                    break;
                case EVENT_DOOMFIRE:
                    DoCastSelf(SPELL_DOOMFIRE_STRIKE);
                    events.Repeat(7s, 9s);
                    break;
                case EVENT_HAND_OF_DEATH:
                    DoCastSelf(SPELL_HAND_OF_DEATH);
                    break;
                case EVENT_DISTANCE_CHECK:
                    if (me->GetDistance(NordrassilPosition) < 60.0f)
                        events.RescheduleEvent(EVENT_HAND_OF_DEATH, 0s);
                    else
                        events.Repeat(5s);
                    break;

                case EVENT_UNLEASH_SOUL_YELLOW:
                    DoCastSelf(SPELL_UNLEASH_SOUL_YELLOW);
                    break;
                case EVENT_UNLEASH_SOUL_GREEN:
                    DoCastSelf(SPELL_UNLEASH_SOUL_GREEN);
                    break;
                case EVENT_UNLEASH_SOUL_RED:
                    DoCastSelf(SPELL_UNLEASH_SOUL_RED);
                    break;

                // Epilogue
                case EVENT_EPILOGUE_1:
                    Talk(SAY_DEATH);
                    DoPlaySoundToSet(me, SOUND_HORN);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_EPILOGUE, EpiloguePosition);
                    events.Reset();
                    break;
                case EVENT_EPILOGUE_2:
                    me->PlayDirectMusic(MUSIC_EPILOGUE);
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_PROTECTION_OF_ELUNE);
                    events.ScheduleEvent(EVENT_SUMMON_WHISP, 2400ms);
                    events.ScheduleEvent(EVENT_FINGER_OF_DEATH_NPC, 2400ms);
                    events.ScheduleEvent(EVENT_FINGER_OF_DEATH_PLAYER, 4s);
                    events.ScheduleEvent(EVENT_EPILOGUE_3, 40s);
                    break;
                case EVENT_EPILOGUE_3:
                    DoCastSelf(SPELL_DENOUEMENT_WISP);
                    DoCastSelf(SPELL_DENOUEMENT);
                    break;

                // Epilogue: Repeatable
                case EVENT_SUMMON_WHISP:
                    for (uint8 i = 0; i < 4; ++i)
                        DoCastSelf(SPELL_SUMMON_WISP);
                    events.Repeat(2400ms);
                    break;
                case EVENT_FINGER_OF_DEATH_NPC:
                    DoCastSelf(SPELL_FINGER_OF_DEATH_NPC);
                    events.Repeat(1200ms);
                    break;
                case EVENT_FINGER_OF_DEATH_PLAYER:
                    DoCastSelf(SPELL_FINGER_OF_DEATH_PLAYER);
                    events.Repeat(4s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _isEpilogueStarted;
    ObjectGuid _doomfireSpiritGUID;
};

// 18095 - Doomfire
struct npc_doomfire : public ScriptedAI
{
    npc_doomfire(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler
            .Schedule(1200ms, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_DOOMFIRE_SPAWN);
                DoCastSelf(SPELL_DOOMFIRE);
            })
            .Schedule(1200ms, [this](TaskContext task)
            {
                if (Unit* target = ObjectAccessor::GetUnit(*me, _doomfireSpiritGUID))
                {
                    float x, y, z;
                    target->GetClosePoint(x, y, z, 0.0f, 1.0f, float(M_PI));
                    me->GetMotionMaster()->MovePoint(POINT_DOOMFIRE, x, y, z);
                    task.Repeat(1200ms);
                }
            });
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == GUID_DOOMFIRE)
            _doomfireSpiritGUID = guid;
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _doomfireSpiritGUID;
};

// 18104 - Doomfire Spirit
struct npc_doomfire_spirit : public ScriptedAI
{
    npc_doomfire_spirit(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            Position pos = me->GetPosition();
            float orientation = Position::NormalizeOrientation(me->GetOrientation() + RAND(0, -1, 1) * 0.785402f);
            me->MovePositionToFirstCollision(pos, 8.0f, orientation);
            me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), orientation);
            task.Repeat(1200ms);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 17946 - Ancient Wisp
struct npc_ancient_wisp : public ScriptedAI
{
    npc_ancient_wisp(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        me->SetCorpseDelay(20, true);
    }

    void JustAppeared() override
    {
        if (me->IsSummon())
            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                AttackStart(summoner);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            if (me->IsWithinDistInMap(me->GetVictim(), 10.0f))
                DoCastVictim(SPELL_ANCIENT_SPARK);
            task.Repeat(2400ms);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 39142 - Drain World Tree Dummy
class spell_archimonde_drain_world_tree_dummy : public SpellScript
{
    PrepareSpellScript(spell_archimonde_drain_world_tree_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAIN_WORLD_TREE_VISUAL_2 });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DRAIN_WORLD_TREE_VISUAL_2);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_archimonde_drain_world_tree_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 42201 - Eternal Silence
class spell_archimonde_eternal_silence : public AuraScript
{
    PrepareAuraScript(spell_archimonde_eternal_silence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RESIDUE_OF_ETERNITY });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_RESIDUE_OF_ETERNITY, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_archimonde_eternal_silence::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SILENCE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_archimonde()
{
    RegisterHyjalCreatureAI(boss_archimonde);
    RegisterHyjalCreatureAI(npc_doomfire);
    RegisterHyjalCreatureAI(npc_doomfire_spirit);
    RegisterHyjalCreatureAI(npc_ancient_wisp);
    RegisterSpellScript(spell_archimonde_drain_world_tree_dummy);
    RegisterSpellScript(spell_archimonde_eternal_silence);
}

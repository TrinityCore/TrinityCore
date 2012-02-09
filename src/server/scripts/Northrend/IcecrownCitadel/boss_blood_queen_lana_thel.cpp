/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "icecrown_citadel.h"

enum Texts
{
    SAY_AGGRO                   = 0,
    SAY_VAMPIRIC_BITE           = 1,
    SAY_MIND_CONTROL            = 2,
    EMOTE_BLOODTHIRST           = 3,
    SAY_SWARMING_SHADOWS        = 4,
    EMOTE_SWARMING_SHADOWS      = 5,
    SAY_PACT_OF_THE_DARKFALLEN  = 6,
    SAY_AIR_PHASE               = 7,
    SAY_KILL                    = 8,
    SAY_WIPE                    = 9,
    SAY_BERSERK                 = 10,
    SAY_DEATH                   = 11,
};

enum Spells
{
    SPELL_SHROUD_OF_SORROW                  = 70986,
    SPELL_FRENZIED_BLOODTHIRST_VISUAL       = 71949,
    SPELL_VAMPIRIC_BITE                     = 71726,
    SPELL_ESSENCE_OF_THE_BLOOD_QUEEN_PLR    = 70879,
    SPELL_FRENZIED_BLOODTHIRST              = 70877,
    SPELL_UNCONTROLLABLE_FRENZY             = 70923,
    SPELL_PRESENCE_OF_THE_DARKFALLEN        = 71952,
    SPELL_BLOOD_MIRROR_DAMAGE               = 70821,
    SPELL_BLOOD_MIRROR_VISUAL               = 71510,
    SPELL_BLOOD_MIRROR_DUMMY                = 70838,
    SPELL_DELIRIOUS_SLASH                   = 71623,
    SPELL_PACT_OF_THE_DARKFALLEN_TARGET     = 71336,
    SPELL_PACT_OF_THE_DARKFALLEN            = 71340,
    SPELL_PACT_OF_THE_DARKFALLEN_DAMAGE     = 71341,
    SPELL_SWARMING_SHADOWS                  = 71264,
    SPELL_TWILIGHT_BLOODBOLT_TARGET         = 71445,
    SPELL_TWILIGHT_BLOODBOLT                = 71446,
    SPELL_INCITE_TERROR                     = 73070,
    SPELL_BLOODBOLT_WHIRL                   = 71772,
    SPELL_ANNIHILATE                        = 71322,
};

enum Shadowmourne
{
    QUEST_BLOOD_INFUSION                    = 24756,
    ITEM_SHADOW_S_EDGE                      = 49888,

    SPELL_GUSHING_WOUND                     = 72132,
    SPELL_THIRST_QUENCHED                   = 72154,
};

uint32 const vampireAuras[3][MAX_DIFFICULTY] =
{
    {70867, 71473, 71532, 71533},
    {70879, 71525, 71530, 71531},
    {70877, 71474, 70877, 71474},
};

#define ESSENCE_OF_BLOOD_QUEEN     RAID_MODE<uint32>(70867, 71473, 71532, 71533)
#define ESSENCE_OF_BLOOD_QUEEN_PLR RAID_MODE<uint32>(70879, 71525, 71530, 71531)
#define FRENZIED_BLOODTHIRST       RAID_MODE<uint32>(70877, 71474, 70877, 71474)
#define DELIRIOUS_SLASH            RAID_MODE<uint32>(71623, 71624, 71625, 71626)

enum Events
{
    EVENT_BERSERK                   = 1,
    EVENT_VAMPIRIC_BITE             = 2,
    EVENT_BLOOD_MIRROR              = 3,
    EVENT_DELIRIOUS_SLASH           = 4,
    EVENT_PACT_OF_THE_DARKFALLEN    = 5,
    EVENT_SWARMING_SHADOWS          = 6,
    EVENT_TWILIGHT_BLOODBOLT        = 7,
    EVENT_AIR_PHASE                 = 8,
    EVENT_AIR_START_FLYING          = 9,
    EVENT_AIR_FLY_DOWN              = 10,

    EVENT_GROUP_NORMAL              = 1,
    EVENT_GROUP_CANCELLABLE         = 2,
};

enum Guids
{
    GUID_VAMPIRE    = 1,
    GUID_BLOODBOLT  = 2,
};

enum Points
{
    POINT_CENTER    = 1,
    POINT_AIR       = 2,
    POINT_GROUND    = 3,
    POINT_MINCHAR   = 4,
};

Position const centerPos  = {4595.7090f, 2769.4190f, 400.6368f, 0.000000f};
Position const airPos     = {4595.7090f, 2769.4190f, 422.3893f, 0.000000f};
Position const mincharPos = {4629.3711f, 2782.6089f, 424.6390f, 0.000000f};

bool IsVampire(Unit const* unit)
{
    for (uint8 i = 0; i < 3; ++i)
        if (unit->HasAura(vampireAuras[i][unit->GetMap()->GetSpawnMode()]))
            return true;
    return false;
}

class boss_blood_queen_lana_thel : public CreatureScript
{
    public:
        boss_blood_queen_lana_thel() : CreatureScript("boss_blood_queen_lana_thel") { }

        struct boss_blood_queen_lana_thelAI : public BossAI
        {
            boss_blood_queen_lana_thelAI(Creature* creature) : BossAI(creature, DATA_BLOOD_QUEEN_LANA_THEL)
            {
            }

            void Reset()
            {
                _Reset();
                events.ScheduleEvent(EVENT_BERSERK, 330000);
                events.ScheduleEvent(EVENT_VAMPIRIC_BITE, 15000);
                events.ScheduleEvent(EVENT_BLOOD_MIRROR, 2500, EVENT_GROUP_CANCELLABLE);
                events.ScheduleEvent(EVENT_DELIRIOUS_SLASH, urand(20000, 24000), EVENT_GROUP_NORMAL);
                events.ScheduleEvent(EVENT_PACT_OF_THE_DARKFALLEN, 15000, EVENT_GROUP_NORMAL);
                events.ScheduleEvent(EVENT_SWARMING_SHADOWS, 30500, EVENT_GROUP_NORMAL);
                events.ScheduleEvent(EVENT_TWILIGHT_BLOODBOLT, urand(20000, 25000), EVENT_GROUP_NORMAL);
                events.ScheduleEvent(EVENT_AIR_PHASE, 124000 + uint32(Is25ManRaid() ? 3000 : 0));
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNCONTROLLABLE_FRENZY);
                me->SetSpeed(MOVE_FLIGHT, 0.642857f, true);
                _offtank = NULL;
                _vampires.clear();
                _creditBloodQuickening = false;
                _killMinchar = false;
            }

            void EnterCombat(Unit* who)
            {
                if (!instance->CheckRequiredBosses(DATA_BLOOD_QUEEN_LANA_THEL, who->ToPlayer()))
                {
                    EnterEvadeMode();
                    instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
                    return;
                }

                me->setActive(true);
                DoZoneInCombat();
                Talk(SAY_AGGRO);
                instance->SetBossState(DATA_BLOOD_QUEEN_LANA_THEL, IN_PROGRESS);

                DoCast(me, SPELL_SHROUD_OF_SORROW, true);
                DoCast(me, SPELL_FRENZIED_BLOODTHIRST_VISUAL, true);
                _creditBloodQuickening = instance->GetData(DATA_BLOOD_QUICKENING_STATE) == IN_PROGRESS;
            }

            void JustDied(Unit* killer)
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->DoRemoveAurasDueToSpellOnPlayers(ESSENCE_OF_BLOOD_QUEEN);
                instance->DoRemoveAurasDueToSpellOnPlayers(ESSENCE_OF_BLOOD_QUEEN_PLR);
                instance->DoRemoveAurasDueToSpellOnPlayers(FRENZIED_BLOODTHIRST);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_UNCONTROLLABLE_FRENZY);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOOD_MIRROR_DAMAGE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOOD_MIRROR_VISUAL);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOOD_MIRROR_DUMMY);
                instance->DoRemoveAurasDueToSpellOnPlayers(DELIRIOUS_SLASH);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PACT_OF_THE_DARKFALLEN);
                // Blah, credit the quest
                if (_creditBloodQuickening)
                {
                    instance->SetData(DATA_BLOOD_QUICKENING_STATE, DONE);
                    if (Player* player = killer->ToPlayer())
                        player->RewardPlayerAndGroupAtEvent(NPC_INFILTRATOR_MINCHAR_BQ, player);
                    if (Creature* minchar = me->FindNearestCreature(NPC_INFILTRATOR_MINCHAR_BQ, 200.0f))
                    {
                        minchar->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                        minchar->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                        minchar->SetFlying(false);
                        minchar->SendMovementFlagUpdate();
                        minchar->RemoveAllAuras();
                        minchar->GetMotionMaster()->MoveCharge(4629.3711f, 2782.6089f, 401.5301f, SPEED_CHARGE/3.0f);
                    }
                }
            }

            void DoAction(int32 const action)
            {
                if (action != ACTION_KILL_MINCHAR)
                    return;

                if (instance->GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == IN_PROGRESS)
                    _killMinchar = true;
                else
                {
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                    me->SetFlying(true);
                    me->SendMovementFlagUpdate();
                    me->GetMotionMaster()->MovePoint(POINT_MINCHAR, mincharPos);
                }
            }

            void EnterEvadeMode()
            {
                _EnterEvadeMode();
                if (_killMinchar)
                {
                    _killMinchar = false;
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                    me->SetFlying(true);
                    me->GetMotionMaster()->MovePoint(POINT_MINCHAR, mincharPos);
                }
                else
                {
                    me->GetMotionMaster()->MoveTargetedHome();
                    Reset();
                }
            }

            void JustReachedHome()
            {
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                me->SetFlying(false);
                me->SetReactState(REACT_AGGRESSIVE);
                _JustReachedHome();
                Talk(SAY_WIPE);
                instance->SetBossState(DATA_BLOOD_QUEEN_LANA_THEL, FAIL);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void SetGUID(uint64 guid, int32 type = 0)
            {
                switch (type)
                {
                    case GUID_VAMPIRE:
                        _vampires.insert(guid);
                        break;
                    case GUID_BLOODBOLT:
                        _bloodboltedPlayers.insert(guid);
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_CENTER:
                        DoCast(me, SPELL_INCITE_TERROR);
                        events.ScheduleEvent(EVENT_AIR_PHASE, 100000 + uint32(Is25ManRaid() ? 0 : 20000));
                        events.RescheduleEvent(EVENT_SWARMING_SHADOWS, 30500, EVENT_GROUP_NORMAL);
                        events.RescheduleEvent(EVENT_PACT_OF_THE_DARKFALLEN, 25500, EVENT_GROUP_NORMAL);
                        events.ScheduleEvent(EVENT_AIR_START_FLYING, 5000);
                        break;
                    case POINT_AIR:
                        _bloodboltedPlayers.clear();
                        DoCast(me, SPELL_BLOODBOLT_WHIRL);
                        Talk(SAY_AIR_PHASE);
                        events.ScheduleEvent(EVENT_AIR_FLY_DOWN, 10000);
                        break;
                    case POINT_GROUND:
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                        me->SetFlying(false);
                        me->SendMovementFlagUpdate();
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Unit* victim = me->SelectVictim())
                            AttackStart(victim);
                        events.ScheduleEvent(EVENT_BLOOD_MIRROR, 2500, EVENT_GROUP_CANCELLABLE);
                        break;
                    case POINT_MINCHAR:
                        DoCast(me, SPELL_ANNIHILATE, true);
                        // already in evade mode
                        me->GetMotionMaster()->MoveTargetedHome();
                        Reset();
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoScriptText(EMOTE_GENERIC_BERSERK_RAID, me);
                            Talk(SAY_BERSERK);
                            DoCast(me, SPELL_BERSERK);
                            break;
                        case EVENT_VAMPIRIC_BITE:
                        {
                            std::list<Player*> targets;
                            SelectRandomTarget(false, &targets);
                            if (!targets.empty())
                            {
                                Unit* target = targets.front();
                                DoCast(target, SPELL_VAMPIRIC_BITE);
                                Talk(SAY_VAMPIRIC_BITE);
                                _vampires.insert(target->GetGUID());
                            }
                            break;
                        }
                        case EVENT_BLOOD_MIRROR:
                        {
                            // victim can be NULL when this is processed in the same update tick as EVENT_AIR_PHASE
                            if (me->getVictim())
                            {
                                Player* newOfftank = SelectRandomTarget(true);
                                if (_offtank != newOfftank)
                                {
                                    _offtank = newOfftank;
                                    if (_offtank)
                                    {
                                        // both spells have SPELL_ATTR5_SINGLE_TARGET_SPELL, no manual removal needed
                                        _offtank->CastSpell(me->getVictim(), SPELL_BLOOD_MIRROR_DAMAGE, true);
                                        me->getVictim()->CastSpell(_offtank, SPELL_BLOOD_MIRROR_DUMMY, true);
                                        DoCastVictim(SPELL_BLOOD_MIRROR_VISUAL);
                                        if (Item* shadowsEdge = _offtank->GetWeaponForAttack(BASE_ATTACK, true))
                                            if (!_offtank->HasAura(SPELL_THIRST_QUENCHED) && shadowsEdge->GetEntry() == ITEM_SHADOW_S_EDGE && !_offtank->HasAura(SPELL_GUSHING_WOUND))
                                                _offtank->CastSpell(_offtank, SPELL_GUSHING_WOUND, true);

                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_BLOOD_MIRROR, 2500, EVENT_GROUP_CANCELLABLE);
                            break;
                        }
                        case EVENT_DELIRIOUS_SLASH:
                            if (_offtank && !me->HasByteFlag(UNIT_FIELD_BYTES_1, 3, 0x03))
                                DoCast(_offtank, SPELL_DELIRIOUS_SLASH);
                            events.ScheduleEvent(EVENT_DELIRIOUS_SLASH, urand(20000, 24000), EVENT_GROUP_NORMAL);
                            break;
                        case EVENT_PACT_OF_THE_DARKFALLEN:
                        {
                            std::list<Player*> targets;
                            SelectRandomTarget(false, &targets);
                            uint32 targetCount = 2;
                            // do not combine these checks! we want it incremented TWICE when both conditions are met
                            if (IsHeroic())
                                ++targetCount;
                            if (Is25ManRaid())
                                ++targetCount;
                            Trinity::RandomResizeList<Player*>(targets, targetCount);
                            if (targets.size() > 1)
                            {
                                Talk(SAY_PACT_OF_THE_DARKFALLEN);
                                for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                    DoCast(*itr, SPELL_PACT_OF_THE_DARKFALLEN);
                            }
                            events.ScheduleEvent(EVENT_PACT_OF_THE_DARKFALLEN, 30500, EVENT_GROUP_NORMAL);
                            break;
                        }
                        case EVENT_SWARMING_SHADOWS:
                            if (Player* target = SelectRandomTarget(false))
                            {
                                Talk(EMOTE_SWARMING_SHADOWS, target->GetGUID());
                                Talk(SAY_SWARMING_SHADOWS);
                                DoCast(target, SPELL_SWARMING_SHADOWS);
                            }
                            events.ScheduleEvent(EVENT_SWARMING_SHADOWS, 30500, EVENT_GROUP_NORMAL);
                            break;
                        case EVENT_TWILIGHT_BLOODBOLT:
                        {
                            std::list<Player*> targets;
                            SelectRandomTarget(false, &targets);
                            Trinity::RandomResizeList<Player*>(targets, uint32(Is25ManRaid() ? 4 : 2));
                            for (std::list<Player*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                DoCast(*itr, SPELL_TWILIGHT_BLOODBOLT);
                            DoCast(me, SPELL_TWILIGHT_BLOODBOLT_TARGET);
                            events.ScheduleEvent(EVENT_TWILIGHT_BLOODBOLT, urand(10000, 15000), EVENT_GROUP_NORMAL);
                            break;
                        }
                        case EVENT_AIR_PHASE:
                            DoStopAttack();
                            me->SetReactState(REACT_PASSIVE);
                            events.DelayEvents(10000, EVENT_GROUP_NORMAL);
                            events.CancelEventGroup(EVENT_GROUP_CANCELLABLE);
                            me->GetMotionMaster()->MovePoint(POINT_CENTER, centerPos);
                            break;
                        case EVENT_AIR_START_FLYING:
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x01);
                            me->SetFlying(true);
                            me->SendMovementFlagUpdate();
                            me->GetMotionMaster()->MovePoint(POINT_AIR, airPos);
                            break;
                        case EVENT_AIR_FLY_DOWN:
                            me->GetMotionMaster()->MovePoint(POINT_GROUND, centerPos);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            bool WasVampire(uint64 guid)
            {
                return _vampires.count(guid) != 0;
            }

            bool WasBloodbolted(uint64 guid)
            {
                return _bloodboltedPlayers.count(guid) != 0;
            }

        private:
            // offtank for this encounter is the player standing closest to main tank
            Player* SelectRandomTarget(bool includeOfftank, std::list<Player*>* targetList = NULL)
            {
                std::list<HostileReference*> const& threatlist = me->getThreatManager().getThreatList();
                std::list<Player*> tempTargets;

                if (threatlist.empty())
                    return NULL;

                for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                    if (Unit* refTarget = (*itr)->getTarget())
                        if (refTarget != me->getVictim() && refTarget->GetTypeId() == TYPEID_PLAYER && (includeOfftank ? true : (refTarget != _offtank)))
                            tempTargets.push_back(refTarget->ToPlayer());

                if (tempTargets.empty())
                    return NULL;

                if (targetList)
                {
                    *targetList = tempTargets;
                    return NULL;
                }

                if (includeOfftank)
                {
                    tempTargets.sort(Trinity::ObjectDistanceOrderPred(me->getVictim()));
                    return tempTargets.front();
                }

                return SelectRandomContainerElement(tempTargets);
            }

            std::set<uint64> _vampires;
            std::set<uint64> _bloodboltedPlayers;
            Player* _offtank;
            bool _creditBloodQuickening;
            bool _killMinchar;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<boss_blood_queen_lana_thelAI>(creature);
        }
};

// helper for shortened code
typedef boss_blood_queen_lana_thel::boss_blood_queen_lana_thelAI LanaThelAI;

class spell_blood_queen_vampiric_bite : public SpellScriptLoader
{
    public:
        spell_blood_queen_vampiric_bite() : SpellScriptLoader("spell_blood_queen_vampiric_bite") { }

        class spell_blood_queen_vampiric_bite_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blood_queen_vampiric_bite_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_ESSENCE_OF_THE_BLOOD_QUEEN_PLR))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_FRENZIED_BLOODTHIRST))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_PRESENCE_OF_THE_DARKFALLEN))
                    return false;
                return true;
            }

            SpellCastResult CheckTarget()
            {
                if (IsVampire(GetTargetUnit()))
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_CANT_TARGET_VAMPIRES);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void OnCast()
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return;

                uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_FRENZIED_BLOODTHIRST, GetCaster());
                GetCaster()->RemoveAura(spellId, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
                GetCaster()->CastSpell(GetCaster(), SPELL_ESSENCE_OF_THE_BLOOD_QUEEN_PLR, true);
                // Presence of the Darkfallen buff on Blood-Queen
                if (GetCaster()->GetMap()->IsHeroic())
                    GetCaster()->CastSpell(GetCaster(), SPELL_PRESENCE_OF_THE_DARKFALLEN, true);
                // Shadowmourne questline
                if (GetCaster()->ToPlayer()->GetQuestStatus(QUEST_BLOOD_INFUSION) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Aura* aura = GetCaster()->GetAura(SPELL_GUSHING_WOUND))
                    {
                        if (aura->GetStackAmount() == 3)
                        {
                            GetCaster()->CastSpell(GetCaster(), SPELL_THIRST_QUENCHED, true);
                            GetCaster()->RemoveAura(aura);
                        }
                        else
                            GetCaster()->CastSpell(GetCaster(), SPELL_GUSHING_WOUND, true);
                    }
                }
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    if (Creature* bloodQueen = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(DATA_BLOOD_QUEEN_LANA_THEL)))
                        bloodQueen->AI()->SetGUID(GetHitUnit()->GetGUID(), GUID_VAMPIRE);
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_blood_queen_vampiric_bite_SpellScript::CheckTarget);
                BeforeHit += SpellHitFn(spell_blood_queen_vampiric_bite_SpellScript::OnCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_blood_queen_vampiric_bite_SpellScript();
        }
};

class spell_blood_queen_frenzied_bloodthirst : public SpellScriptLoader
{
    public:
        spell_blood_queen_frenzied_bloodthirst() : SpellScriptLoader("spell_blood_queen_frenzied_bloodthirst") { }

        class spell_blood_queen_frenzied_bloodthirst_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_blood_queen_frenzied_bloodthirst_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    if (Creature* bloodQueen = ObjectAccessor::GetCreature(*GetTarget(), instance->GetData64(DATA_BLOOD_QUEEN_LANA_THEL)))
                        bloodQueen->AI()->Talk(EMOTE_BLOODTHIRST, GetTarget()->GetGUID());
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (InstanceScript* instance = target->GetInstanceScript())
                        if (Creature* bloodQueen = ObjectAccessor::GetCreature(*target, instance->GetData64(DATA_BLOOD_QUEEN_LANA_THEL)))
                        {
                            // this needs to be done BEFORE charm aura or we hit an assert in Unit::SetCharmedBy
                            if (target->GetVehicleKit())
                                target->RemoveVehicleKit();

                            bloodQueen->AI()->Talk(SAY_MIND_CONTROL);
                            bloodQueen->CastSpell(target, SPELL_UNCONTROLLABLE_FRENZY, true);
                        }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_blood_queen_frenzied_bloodthirst_AuraScript::OnApply, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_blood_queen_frenzied_bloodthirst_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_blood_queen_frenzied_bloodthirst_AuraScript();
        }
};

class BloodboltHitCheck
{
    public:
        explicit BloodboltHitCheck(LanaThelAI* ai) : _ai(ai) {}

        bool operator()(Unit* unit)
        {
            return _ai->WasBloodbolted(unit->GetGUID());
        }

    private:
        LanaThelAI* _ai;
};

class spell_blood_queen_bloodbolt : public SpellScriptLoader
{
    public:
        spell_blood_queen_bloodbolt() : SpellScriptLoader("spell_blood_queen_bloodbolt") { }

        class spell_blood_queen_bloodbolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blood_queen_bloodbolt_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TWILIGHT_BLOODBOLT))
                    return false;
                return true;
            }

            bool Load()
            {
                return GetCaster()->GetEntry() == NPC_BLOOD_QUEEN_LANA_THEL;
            }

            void FilterTargets(std::list<Unit*>& targets)
            {
                uint32 targetCount = (targets.size() + 2) / 3;
                targets.remove_if (BloodboltHitCheck(static_cast<LanaThelAI*>(GetCaster()->GetAI())));
                Trinity::RandomResizeList(targets, targetCount);
                // mark targets now, effect hook has missile travel time delay (might cast next in that time)
                for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    GetCaster()->GetAI()->SetGUID((*itr)->GetGUID(), GUID_BLOODBOLT);
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_TWILIGHT_BLOODBOLT, true);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_blood_queen_bloodbolt_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_blood_queen_bloodbolt_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_blood_queen_bloodbolt_SpellScript();
        }
};

class spell_blood_queen_pact_of_the_darkfallen : public SpellScriptLoader
{
    public:
        spell_blood_queen_pact_of_the_darkfallen() : SpellScriptLoader("spell_blood_queen_pact_of_the_darkfallen") { }

        class spell_blood_queen_pact_of_the_darkfallen_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blood_queen_pact_of_the_darkfallen_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if (Trinity::UnitAuraCheck(false, SPELL_PACT_OF_THE_DARKFALLEN));

                bool remove = true;
                std::list<Unit*>::const_iterator itrEnd = unitList.end(), itr, itr2;
                // we can do this, unitList is MAX 4 in size
                for (itr = unitList.begin(); itr != itrEnd && remove; ++itr)
                {
                    if (!GetCaster()->IsWithinDist(*itr, 5.0f, false))
                        remove = false;

                    for (itr2 = unitList.begin(); itr2 != itrEnd && remove; ++itr2)
                        if (itr != itr2 && !(*itr2)->IsWithinDist(*itr, 5.0f, false))
                            remove = false;
                }

                if (remove)
                {
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    {
                        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PACT_OF_THE_DARKFALLEN);
                        unitList.clear();
                    }
                }
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_blood_queen_pact_of_the_darkfallen_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_blood_queen_pact_of_the_darkfallen_SpellScript();
        }
};

class spell_blood_queen_pact_of_the_darkfallen_dmg : public SpellScriptLoader
{
    public:
        spell_blood_queen_pact_of_the_darkfallen_dmg() : SpellScriptLoader("spell_blood_queen_pact_of_the_darkfallen_dmg") { }

        class spell_blood_queen_pact_of_the_darkfallen_dmg_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_blood_queen_pact_of_the_darkfallen_dmg_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PACT_OF_THE_DARKFALLEN_DAMAGE))
                    return false;
                return true;
            }

            // this is an additional effect to be executed
            void PeriodicTick(AuraEffect const* aurEff)
            {
                SpellInfo const* damageSpell = sSpellMgr->GetSpellInfo(SPELL_PACT_OF_THE_DARKFALLEN_DAMAGE);
                int32 damage = damageSpell->Effects[EFFECT_0].CalcValue();
                float multiplier = 0.3375f + 0.1f * uint32(aurEff->GetTickNumber()/10); // do not convert to 0.01f - we need tick number/10 as INT (damage increases every 10 ticks)
                damage = int32(damage * multiplier);
                GetTarget()->CastCustomSpell(SPELL_PACT_OF_THE_DARKFALLEN_DAMAGE, SPELLVALUE_BASE_POINT0, damage, GetTarget(), true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_blood_queen_pact_of_the_darkfallen_dmg_AuraScript::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_blood_queen_pact_of_the_darkfallen_dmg_AuraScript();
        }
};

class spell_blood_queen_pact_of_the_darkfallen_dmg_target : public SpellScriptLoader
{
    public:
        spell_blood_queen_pact_of_the_darkfallen_dmg_target() : SpellScriptLoader("spell_blood_queen_pact_of_the_darkfallen_dmg_target") { }

        class spell_blood_queen_pact_of_the_darkfallen_dmg_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blood_queen_pact_of_the_darkfallen_dmg_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if (Trinity::UnitAuraCheck(true, SPELL_PACT_OF_THE_DARKFALLEN));
                unitList.push_back(GetCaster());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_blood_queen_pact_of_the_darkfallen_dmg_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_blood_queen_pact_of_the_darkfallen_dmg_SpellScript();
        }
};

class achievement_once_bitten_twice_shy_n : public AchievementCriteriaScript
{
    public:
        achievement_once_bitten_twice_shy_n() : AchievementCriteriaScript("achievement_once_bitten_twice_shy_n") { }

        bool OnCheck(Player* source, Unit* target)
        {
            if (!target)
                return false;

            if (LanaThelAI* lanaThelAI = CAST_AI(LanaThelAI, target->GetAI()))
                return !lanaThelAI->WasVampire(source->GetGUID());
            return false;
        }
};

class achievement_once_bitten_twice_shy_v : public AchievementCriteriaScript
{
    public:
        achievement_once_bitten_twice_shy_v() : AchievementCriteriaScript("achievement_once_bitten_twice_shy_v") { }

        bool OnCheck(Player* source, Unit* target)
        {
            if (!target)
                return false;

            if (LanaThelAI* lanaThelAI = CAST_AI(LanaThelAI, target->GetAI()))
                return lanaThelAI->WasVampire(source->GetGUID());
            return false;
        }
};

void AddSC_boss_blood_queen_lana_thel()
{
    new boss_blood_queen_lana_thel();
    new spell_blood_queen_vampiric_bite();
    new spell_blood_queen_frenzied_bloodthirst();
    new spell_blood_queen_bloodbolt();
    new spell_blood_queen_pact_of_the_darkfallen();
    new spell_blood_queen_pact_of_the_darkfallen_dmg();
    new spell_blood_queen_pact_of_the_darkfallen_dmg_target();
    new achievement_once_bitten_twice_shy_n();
    new achievement_once_bitten_twice_shy_v();
}

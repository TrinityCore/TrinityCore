/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellAuraEffects.h"
#include "icecrown_citadel.h"

enum Texts
{
    SAY_AGGRO                           = 0, // You are fools to have come to this place! The icy winds of Northrend will consume your souls!
    SAY_UNCHAINED_MAGIC                 = 1, // Suffer, mortals, as your pathetic magic betrays you!
    EMOTE_WARN_BLISTERING_COLD          = 2, // %s prepares to unleash a wave of blistering cold!
    SAY_BLISTERING_COLD                 = 3, // Can you feel the cold hand of death upon your heart?
    SAY_RESPITE_FOR_A_TORMENTED_SOUL    = 4, // Aaah! It burns! What sorcery is this?!
    SAY_AIR_PHASE                       = 5, // Your incursion ends here! None shall survive!
    SAY_PHASE_2                         = 6, // Now feel my master's limitless power and despair!
    EMOTE_WARN_FROZEN_ORB               = 7, // %s fires a frozen orb towards $N!
    SAY_KILL                            = 8, // Perish!
                                             // A flaw of mortality...
    SAY_BERSERK                         = 9, // Enough! I tire of these games!
    SAY_DEATH                           = 10, // Free...at last...
};

enum Spells
{
    // Sindragosa
    SPELL_SINDRAGOSA_S_FURY     = 70608,
    SPELL_TANK_MARKER           = 71039,
    SPELL_FROST_AURA            = 70084,
    SPELL_PERMAEATING_CHILL     = 70109,
    SPELL_CLEAVE                = 19983,
    SPELL_TAIL_SMASH            = 71077,
    SPELL_FROST_BREATH_P1       = 69649,
    SPELL_FROST_BREATH_P2       = 73061,
    SPELL_UNCHAINED_MAGIC       = 69762,
    SPELL_BACKLASH              = 69770,
    SPELL_ICY_GRIP              = 70117,
    SPELL_ICY_GRIP_JUMP         = 70122,
    SPELL_BLISTERING_COLD       = 70123,
    SPELL_FROST_BEACON          = 70126,
    SPELL_ICE_TOMB_TARGET       = 69712,
    SPELL_ICE_TOMB_DUMMY        = 69675,
    SPELL_ICE_TOMB_UNTARGETABLE = 69700,
    SPELL_ICE_TOMB_DAMAGE       = 70157,
    SPELL_ASPHYXIATION          = 71665,
    SPELL_FROST_BOMB_TRIGGER    = 69846,
    SPELL_FROST_BOMB_VISUAL     = 70022,
    SPELL_FROST_BOMB            = 69845,
    SPELL_MYSTIC_BUFFET         = 70128,

    // Spinestalker
    SPELL_BELLOWING_ROAR        = 36922,
    SPELL_CLEAVE_SPINESTALKER   = 40505,
    SPELL_TAIL_SWEEP            = 71370,

    // Rimefang
    SPELL_FROST_BREATH          = 71386,
    SPELL_FROST_AURA_RIMEFANG   = 71387,
    SPELL_ICY_BLAST             = 71376,
    SPELL_ICY_BLAST_AREA        = 71380,

    // Frostwarden Handler
    SPELL_FOCUS_FIRE            = 71350,
    SPELL_ORDER_WHELP           = 71357,
    SPELL_CONCUSSIVE_SHOCK      = 71337,
};

enum Events
{
    // Sindragosa
    EVENT_BERSERK                   = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_TAIL_SMASH                = 3,
    EVENT_FROST_BREATH              = 4,
    EVENT_UNCHAINED_MAGIC           = 5,
    EVENT_ICY_GRIP                  = 6,
    EVENT_BLISTERING_COLD           = 7,
    EVENT_BLISTERING_COLD_YELL      = 8,
    EVENT_AIR_PHASE                 = 9,
    EVENT_ICE_TOMB                  = 10,
    EVENT_FROST_BOMB                = 11,
    EVENT_LAND                      = 12,

    // Spinestalker
    EVENT_BELLOWING_ROAR            = 13,
    EVENT_CLEAVE_SPINESTALKER       = 14,
    EVENT_TAIL_SWEEP                = 15,

    // Rimefang
    EVENT_FROST_BREATH_RIMEFANG     = 16,
    EVENT_ICY_BLAST                 = 17,
    EVENT_ICY_BLAST_CAST            = 18,

    // Trash
    EVENT_FROSTWARDEN_ORDER_WHELP   = 19,
    EVENT_CONCUSSIVE_SHOCK          = 20,

    // event groups
    EVENT_GROUP_LAND_PHASE          = 1,
};

enum FrostwingData
{
    DATA_MYSTIC_BUFFET_STACK    = 0,
    DATA_FROSTWYRM_OWNER        = 1,
    DATA_WHELP_MARKER           = 2,
    DATA_LINKED_GAMEOBJECT      = 3,
    DATA_TRAPPED_PLAYER         = 4,
};

enum MovementPoints
{
    POINT_FROSTWYRM_FLY_IN  = 1,
    POINT_FROSTWYRM_LAND    = 2,
    POINT_AIR_PHASE         = 3,
    POINT_LAND              = 4,
};

enum Shadowmourne
{
    QUEST_FROST_INFUSION        = 24757,
    ITEM_SHADOW_S_EDGE          = 49888,

    SPELL_FROST_INFUSION        = 72292,
    SPELL_FROST_IMBUED_BLADE    = 72290,
};

Position const RimefangFlyPos      = {4413.309f, 2456.421f, 223.3795f, 2.890186f};
Position const RimefangLandPos     = {4413.309f, 2456.421f, 203.3848f, 2.890186f};
Position const SpinestalkerFlyPos  = {4418.895f, 2514.233f, 220.4864f, 3.396045f};
Position const SpinestalkerLandPos = {4418.895f, 2514.233f, 203.3848f, 3.396045f};
Position const SindragosaSpawnPos  = {4818.700f, 2483.710f, 287.0650f, 3.089233f};
Position const SindragosaFlyPos    = {4475.190f, 2484.570f, 234.8510f, 3.141593f};
Position const SindragosaLandPos   = {4419.190f, 2484.570f, 203.3848f, 3.141593f};
Position const SindragosaAirPos    = {4475.990f, 2484.430f, 247.9340f, 3.141593f};

class FrostwyrmLandEvent : public BasicEvent
{
    public:
        FrostwyrmLandEvent(Creature& owner, Position const& dest) : _owner(owner), _dest(dest) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/)
        {
            _owner.GetMotionMaster()->MovePoint(POINT_FROSTWYRM_LAND, _dest);
            return true;
        }

    private:
        Creature& _owner;
        Position const& _dest;
};

class boss_sindragosa : public CreatureScript
{
    public:
        boss_sindragosa() : CreatureScript("boss_sindragosa") { }

        struct boss_sindragosaAI : public BossAI
        {
            boss_sindragosaAI(Creature* creature) : BossAI(creature, DATA_SINDRAGOSA)
            {
            }

            void Reset()
            {
                BossAI::Reset();
                me->SetReactState(REACT_DEFENSIVE);
                DoCast(me, SPELL_TANK_MARKER, true);
                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_CLEAVE, 10000, EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_TAIL_SMASH, 20000, EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FROST_BREATH, urand(8000, 12000), EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_UNCHAINED_MAGIC, urand(9000, 14000), EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_ICY_GRIP, 33500, EVENT_GROUP_LAND_PHASE);
                _mysticBuffetStack = 0;
                _firstAirPhaseDone = false;
                _isThirdPhase = false;

                if (instance->GetData(DATA_SINDRAGOSA_FROSTWYRMS) != 255)
                {
                    me->SetFlying(true);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                }
            }

            void JustDied(Unit* killer)
            {
                BossAI::JustDied(killer);
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* victim)
            {
                if (!instance->CheckRequiredBosses(DATA_SINDRAGOSA, victim->ToPlayer()))
                {
                    EnterEvadeMode();
                    instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
                    return;
                }

                BossAI::EnterCombat(victim);
                DoCast(me, SPELL_FROST_AURA);
                DoCast(me, SPELL_PERMAEATING_CHILL);
                Talk(SAY_AGGRO);
            }

            void JustReachedHome()
            {
                BossAI::JustReachedHome();
                instance->SetBossState(DATA_SINDRAGOSA, FAIL);
                me->SetFlying(false);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_START_FROSTWYRM)
                {
                    instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, 255);
                    if (me->isDead())
                        return;

                    me->setActive(true);
                    me->SetSpeed(MOVE_FLIGHT, 4.0f);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    float moveTime = me->GetExactDist(&SindragosaFlyPos)/(me->GetSpeed(MOVE_FLIGHT)*0.001f);
                    me->m_Events.AddEvent(new FrostwyrmLandEvent(*me, SindragosaLandPos), me->m_Events.CalculateTime(uint64(moveTime) + 250));
                    me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, SindragosaFlyPos);
                    DoCast(me, SPELL_SINDRAGOSA_S_FURY);
                }
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_MYSTIC_BUFFET_STACK)
                    return _mysticBuffetStack;
                return 0xFFFFFFFF;
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_FROSTWYRM_LAND:
                        me->setActive(false);
                        me->SetFlying(false);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SetHomePosition(SindragosaLandPos);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->SetSpeed(MOVE_FLIGHT, 2.0f);

                        // Sindragosa enters combat as soon as she lands
                        DoZoneInCombat();
                        break;
                    case POINT_AIR_PHASE:
                        me->CastCustomSpell(SPELL_ICE_TOMB_TARGET, SPELLVALUE_MAX_TARGETS, RAID_MODE<int32>(2, 5, 2, 6), false);
                        events.ScheduleEvent(EVENT_FROST_BOMB, 8000);
                        break;
                    case POINT_LAND:
                        me->SetFlying(false);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SetReactState(REACT_DEFENSIVE);
                        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                            me->GetMotionMaster()->MovementExpired();
                        DoStartMovement(me->getVictim());
                        // trigger Asphyxiation
                        summons.DoAction(NPC_ICE_TOMB, ACTION_TRIGGER_ASPHYXIATION);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!_firstAirPhaseDone && !HealthAbovePct(85))
                {
                    events.ScheduleEvent(EVENT_AIR_PHASE, 100);
                    _firstAirPhaseDone = true;
                }
                else if (!_isThirdPhase && !HealthAbovePct(35))
                {
                    Talk(SAY_PHASE_2);
                    events.CancelEvent(EVENT_AIR_PHASE);
                    events.ScheduleEvent(EVENT_ICE_TOMB, urand(7000, 10000));
                    events.RescheduleEvent(EVENT_ICY_GRIP, urand(35000, 40000));
                    DoCast(me, SPELL_MYSTIC_BUFFET, true);
                    _isThirdPhase = true;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                BossAI::SummonedCreatureDespawn(summon);
                if (summon->GetEntry() == NPC_ICE_TOMB)
                    summon->AI()->JustDied(summon);
            }

            void SpellHitTarget(Unit* target, SpellEntry const* spell)
            {
                if (uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(70127, me))
                    if (spellId == spell->Id)
                        if (Aura const* mysticBuffet = target->GetAura(spell->Id))
                            _mysticBuffetStack = std::max<uint8>(_mysticBuffetStack, mysticBuffet->GetStackAmount());

                // Frost Infusion
                if (Player* player = target->ToPlayer())
                {
                    if (uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(_isThirdPhase ? SPELL_FROST_BREATH_P2 : SPELL_FROST_BREATH_P1, me))
                    {
                        if (player->GetQuestStatus(QUEST_FROST_INFUSION) != QUEST_STATUS_REWARDED && spellId == spell->Id)
                        {
                            if (Item* shadowsEdge = player->GetWeaponForAttack(BASE_ATTACK, true))
                            {
                                if (!player->HasAura(SPELL_FROST_IMBUED_BLADE) && shadowsEdge->GetEntry() == ITEM_SHADOW_S_EDGE)
                                {
                                    if (Aura* infusion = player->GetAura(SPELL_FROST_INFUSION))
                                    {
                                        if (infusion->GetStackAmount() == 3)
                                        {
                                            player->CastSpell(player, SPELL_FROST_IMBUED_BLADE, true);
                                            player->RemoveAura(infusion);
                                        }
                                        else
                                            player->CastSpell(player, SPELL_FROST_INFUSION, true);
                                    }
                                    else
                                        player->CastSpell(player, SPELL_FROST_INFUSION, true);
                                }
                            }
                        }
                    }
                }

                if (spell->Id == SPELL_FROST_BOMB_TRIGGER)
                {
                    target->CastSpell(target, SPELL_FROST_BOMB, true);
                    target->RemoveAurasDueToSpell(SPELL_FROST_BOMB_VISUAL);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
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
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(15000, 20000), EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_TAIL_SMASH:
                            DoCast(me, SPELL_TAIL_SMASH);
                            events.ScheduleEvent(EVENT_TAIL_SMASH, urand(27000, 32000), EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_FROST_BREATH:
                            DoCastVictim(_isThirdPhase ? SPELL_FROST_BREATH_P2 : SPELL_FROST_BREATH_P1);
                            events.ScheduleEvent(EVENT_FROST_BREATH, urand(20000, 25000), EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_UNCHAINED_MAGIC:
                            Talk(SAY_UNCHAINED_MAGIC);
                            DoCast(me, SPELL_UNCHAINED_MAGIC);
                            events.ScheduleEvent(EVENT_UNCHAINED_MAGIC, urand(30000, 35000), EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_ICY_GRIP:
                            DoCast(me, SPELL_ICY_GRIP);
                            events.ScheduleEvent(EVENT_ICY_GRIP, urand(70000, 75000), EVENT_GROUP_LAND_PHASE);
                            events.ScheduleEvent(EVENT_BLISTERING_COLD, 1000, EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_BLISTERING_COLD:
                            Talk(EMOTE_WARN_BLISTERING_COLD);
                            DoCast(me, SPELL_BLISTERING_COLD);
                            events.ScheduleEvent(EVENT_BLISTERING_COLD_YELL, 5000, EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_BLISTERING_COLD_YELL:
                            Talk(SAY_BLISTERING_COLD);
                            break;
                        case EVENT_AIR_PHASE:
                            Talk(SAY_AIR_PHASE);
                            me->SetFlying(true);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            me->SetReactState(REACT_PASSIVE);
                            me->GetMotionMaster()->MovePoint(POINT_AIR_PHASE, SindragosaAirPos);
                            events.DelayEvents(45000, EVENT_GROUP_LAND_PHASE);
                            events.ScheduleEvent(EVENT_AIR_PHASE, 110000);
                            events.RescheduleEvent(EVENT_UNCHAINED_MAGIC, urand(55000, 60000), EVENT_GROUP_LAND_PHASE);
                            events.ScheduleEvent(EVENT_LAND, 45000);
                            break;
                        case EVENT_ICE_TOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_ICE_TOMB_UNTARGETABLE))
                            {
                                Talk(EMOTE_WARN_FROZEN_ORB, target->GetGUID());
                                DoCast(target, SPELL_ICE_TOMB_DUMMY, true);
                            }
                            events.ScheduleEvent(EVENT_ICE_TOMB, urand(16000, 23000));
                            break;
                        case EVENT_FROST_BOMB:
                        {
                            float destX, destY, destZ;
                            destX = float(rand_norm()) * 117.25f + 4339.25f;
                            if (destX > 4371.5f && destX < 4432.0f)
                                destY = float(rand_norm()) * 111.0f + 2429.0f;
                            else
                                destY = float(rand_norm()) * 31.23f + 2454.64f;
                            destZ = 205.0f; // random number close to ground, get exact in next call
                            me->UpdateGroundPositionZ(destX, destY, destZ);
                            Position pos;
                            pos.Relocate(destX, destY, destZ);
                            if (TempSummon* summ = me->SummonCreature(NPC_FROST_BOMB, pos, TEMPSUMMON_TIMED_DESPAWN, 40000))
                            {
                                summ->CastSpell(summ, SPELL_FROST_BOMB_VISUAL, true);
                                DoCast(summ, SPELL_FROST_BOMB_TRIGGER);
                                //me->CastSpell(destX, destY, destZ, SPELL_FROST_BOMB_TRIGGER, false);
                            }
                            events.ScheduleEvent(EVENT_FROST_BOMB, urand(5000, 10000));
                            break;
                        }
                        case EVENT_LAND:
                        {
                            events.CancelEvent(EVENT_FROST_BOMB);
                            me->GetMotionMaster()->MovePoint(POINT_LAND, SindragosaLandPos);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _mysticBuffetStack;
            bool _firstAirPhaseDone;
            bool _isThirdPhase;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<boss_sindragosaAI>(creature);
        }
};

class npc_ice_tomb : public CreatureScript
{
    public:
        npc_ice_tomb() : CreatureScript("npc_ice_tomb") { }

        struct npc_ice_tombAI : public Scripted_NoMovementAI
        {
            npc_ice_tombAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                _trappedPlayerGUID = 0;
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void SetGUID(uint64 const& guid, int32 type/* = 0 */)
            {
                if (type == DATA_TRAPPED_PLAYER)
                {
                    _trappedPlayerGUID = guid;
                    _existenceCheckTimer = 1000;
                }
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_TRIGGER_ASPHYXIATION)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _trappedPlayerGUID))
                        player->CastSpell(player, SPELL_ASPHYXIATION, true);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->RemoveAllGameObjects();

                if (Player* player = ObjectAccessor::GetPlayer(*me, _trappedPlayerGUID))
                {
                    _trappedPlayerGUID = 0;
                    player->RemoveAurasDueToSpell(SPELL_ICE_TOMB_DAMAGE);
                    player->RemoveAurasDueToSpell(SPELL_ASPHYXIATION);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!_trappedPlayerGUID)
                    return;

                if (_existenceCheckTimer <= diff)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, _trappedPlayerGUID);
                    if (!player || player->isDead() || !player->HasAura(SPELL_ICE_TOMB_DAMAGE))
                    {
                        // Remove object
                        JustDied(me);
                        me->DespawnOrUnsummon();
                        return;
                    }
                    _existenceCheckTimer = 1000;
                }
                else
                    _existenceCheckTimer -= diff;
            }

        private:
            uint64 _trappedPlayerGUID;
            uint32 _existenceCheckTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_ice_tombAI>(creature);
        }
};

class npc_spinestalker : public CreatureScript
{
    public:
        npc_spinestalker() : CreatureScript("npc_spinestalker") { }

        struct npc_spinestalkerAI : public ScriptedAI
        {
            npc_spinestalkerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_BELLOWING_ROAR, urand(20000, 25000));
                _events.ScheduleEvent(EVENT_CLEAVE_SPINESTALKER, urand(10000, 15000));
                _events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(8000, 12000));
                me->SetReactState(REACT_DEFENSIVE);

                if (_instance->GetData(DATA_SPINESTALKER) != 255)
                {
                    me->SetFlying(true);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                }
            }

            void JustRespawned()
            {
                ScriptedAI::JustRespawned();
                _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, 1);  // this cannot be in Reset because reset also happens on evade
            }

            void JustDied(Unit* /*killer*/)
            {
                _events.Reset();
                _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, 0);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_START_FROSTWYRM)
                {
                    _instance->SetData(DATA_SPINESTALKER, 255);
                    if (me->isDead())
                        return;

                    me->setActive(true);
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    float moveTime = me->GetExactDist(&SpinestalkerFlyPos)/(me->GetSpeed(MOVE_FLIGHT)*0.001f);
                    me->m_Events.AddEvent(new FrostwyrmLandEvent(*me, SpinestalkerLandPos), me->m_Events.CalculateTime(uint64(moveTime) + 250));
                    me->SetDefaultMovementType(IDLE_MOTION_TYPE);
                    me->GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);
                    me->StopMoving();
                    me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, SpinestalkerFlyPos);
                }
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE || point != POINT_FROSTWYRM_LAND)
                    return;

                me->setActive(false);
                me->SetFlying(false);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->SetHomePosition(SpinestalkerLandPos);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BELLOWING_ROAR:
                            DoCast(me, SPELL_BELLOWING_ROAR);
                            _events.ScheduleEvent(EVENT_BELLOWING_ROAR, urand(25000, 30000));
                            break;
                        case EVENT_CLEAVE_SPINESTALKER:
                            DoCastVictim(SPELL_CLEAVE_SPINESTALKER);
                            _events.ScheduleEvent(EVENT_CLEAVE_SPINESTALKER, urand(10000, 15000));
                            break;
                        case EVENT_TAIL_SWEEP:
                            DoCast(me, SPELL_TAIL_SWEEP);
                            _events.ScheduleEvent(EVENT_TAIL_SWEEP, urand(22000, 25000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_spinestalkerAI>(creature);
        }
};

class npc_rimefang : public CreatureScript
{
    public:
        npc_rimefang() : CreatureScript("npc_rimefang_icc") { }

        struct npc_rimefangAI : public ScriptedAI
        {
            npc_rimefangAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_FROST_BREATH_RIMEFANG, urand(12000, 15000));
                _events.ScheduleEvent(EVENT_ICY_BLAST, urand(30000, 35000));
                me->SetReactState(REACT_DEFENSIVE);
                _icyBlastCounter = 0;

                if (_instance->GetData(DATA_RIMEFANG) != 255)
                {
                    me->SetFlying(true);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                }
            }

            void JustRespawned()
            {
                ScriptedAI::JustRespawned();
                _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, 1);  // this cannot be in Reset because reset also happens on evade
            }

            void JustDied(Unit* /*killer*/)
            {
                _events.Reset();
                _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, 0);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_START_FROSTWYRM)
                {
                    _instance->SetData(DATA_RIMEFANG, 255);
                    if (me->isDead())
                        return;

                    me->setActive(true);
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    float moveTime = me->GetExactDist(&RimefangFlyPos)/(me->GetSpeed(MOVE_FLIGHT)*0.001f);
                    me->m_Events.AddEvent(new FrostwyrmLandEvent(*me, RimefangLandPos), me->m_Events.CalculateTime(uint64(moveTime) + 250));
                    me->SetDefaultMovementType(IDLE_MOTION_TYPE);
                    me->GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);
                    me->StopMoving();
                    me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, RimefangFlyPos);
                }
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE || point != POINT_FROSTWYRM_LAND)
                    return;

                me->setActive(false);
                me->SetFlying(false);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->SetHomePosition(RimefangLandPos);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            }

            void EnterCombat(Unit* /*victim*/)
            {
                DoCast(me, SPELL_FROST_AURA_RIMEFANG, true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FROST_BREATH_RIMEFANG:
                            DoCast(me, SPELL_FROST_BREATH);
                            _events.ScheduleEvent(EVENT_FROST_BREATH_RIMEFANG, urand(35000, 40000));
                            break;
                        case EVENT_ICY_BLAST:
                        {
                            _icyBlastCounter = RAID_MODE<uint8>(5, 7, 6, 8);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->SetFlying(true);
                            me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, RimefangFlyPos);
                            float moveTime = me->GetExactDist(&RimefangFlyPos)/(me->GetSpeed(MOVE_FLIGHT)*0.001f);
                            _events.ScheduleEvent(EVENT_ICY_BLAST, uint64(moveTime) + urand(60000, 70000));
                            _events.ScheduleEvent(EVENT_ICY_BLAST_CAST, uint64(moveTime) + 250);
                            break;
                        }
                        case EVENT_ICY_BLAST_CAST:
                            if (--_icyBlastCounter)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                {
                                    me->SetFacingToObject(target);
                                    DoCast(target, SPELL_ICY_BLAST);
                                }
                                _events.ScheduleEvent(EVENT_ICY_BLAST_CAST, 3000);
                            }
                            else if (Unit* victim = me->SelectVictim())
                            {
                                me->SetReactState(REACT_DEFENSIVE);
                                AttackStart(victim);
                                me->SetFlying(false);
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            uint8 _icyBlastCounter;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_rimefangAI>(creature);
        }
};

class npc_sindragosa_trash : public CreatureScript
{
    public:
        npc_sindragosa_trash() : CreatureScript("npc_sindragosa_trash") { }

        struct npc_sindragosa_trashAI : public ScriptedAI
        {
            npc_sindragosa_trashAI(Creature* creature) : ScriptedAI(creature)
            {
                _frostwyrmId = (creature->GetHomePosition().GetPositionY() < 2484.35f) ? DATA_RIMEFANG : DATA_SPINESTALKER;
                _instance = creature->GetInstanceScript();
            }

            void InitializeAI()
            {
                // Increase add count
                if (!me->isDead())
                    _instance->SetData(_frostwyrmId, 1);  // this cannot be in Reset because reset also happens on evade
            }

            void Reset()
            {
                // This is shared AI for handler and whelps
                if (me->GetEntry() == NPC_FROSTWARDEN_HANDLER)
                {
                    _events.ScheduleEvent(EVENT_FROSTWARDEN_ORDER_WHELP, 3000);
                    _events.ScheduleEvent(EVENT_CONCUSSIVE_SHOCK, urand(8000, 10000));
                }

                _isTaunted = false;
            }

            void JustRespawned()
            {
                ScriptedAI::JustRespawned();

                // Increase add count
                _instance->SetData(_frostwyrmId, 1);  // this cannot be in Reset because reset also happens on evade
            }

            void JustDied(Unit* /*killer*/)
            {
                // Decrease add count
                _instance->SetData(_frostwyrmId, 0);
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_WHELP_MARKER)
                    _isTaunted = data != 0;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_FROSTWYRM_OWNER)
                    return _frostwyrmId;
                else if (type == DATA_WHELP_MARKER)
                    return uint32(_isTaunted);
                return 0;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FROSTWARDEN_ORDER_WHELP:
                            DoCast(me, SPELL_ORDER_WHELP);
                            _events.ScheduleEvent(EVENT_FROSTWARDEN_ORDER_WHELP, 3000);
                            break;
                        case EVENT_CONCUSSIVE_SHOCK:
                            DoCast(me, SPELL_CONCUSSIVE_SHOCK);
                            _events.ScheduleEvent(EVENT_CONCUSSIVE_SHOCK, urand(10000, 13000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            uint32 _frostwyrmId;
            bool _isTaunted; // Frostwing Whelp only
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_sindragosa_trashAI>(creature);
        }
};

class spell_sindragosa_s_fury : public SpellScriptLoader
{
    public:
        spell_sindragosa_s_fury() : SpellScriptLoader("spell_sindragosa_s_fury") { }

        class spell_sindragosa_s_fury_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sindragosa_s_fury_SpellScript);

            bool Load()
            {
                _targetCount = 0;
                return true;
            }

            void CountTargets(std::list<Unit*>& unitList)
            {
                _targetCount = unitList.size();
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                if (!GetHitUnit()->isAlive())
                    return;

                float resistance = float(GetHitUnit()->GetResistance(GetFirstSchoolInMask(SpellSchoolMask(GetSpellInfo()->SchoolMask))));
                uint32 minResistFactor = uint32((resistance / (resistance + 510.0f))* 10.0f) * 2;
                uint32 randomResist = urand(0, (9 - minResistFactor) * 100)/100 + minResistFactor;

                uint32 damage = (uint32(GetEffectValue()/_targetCount) * randomResist) / 10;

                SpellNonMeleeDamage damageInfo(GetCaster(), GetHitUnit(), GetSpellInfo()->Id, GetSpellInfo()->SchoolMask);
                damageInfo.damage = damage;
                GetCaster()->SendSpellNonMeleeDamageLog(&damageInfo);
                GetCaster()->DealSpellDamage(&damageInfo, false);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_sindragosa_s_fury_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_sindragosa_s_fury_SpellScript::CountTargets, EFFECT_1, TARGET_UNIT_AREA_ENTRY_DST);
            }

            uint32 _targetCount;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sindragosa_s_fury_SpellScript();
        }
};

class UnchainedMagicTargetSelector
{
    public:
        UnchainedMagicTargetSelector() { }

        bool operator()(Unit* unit)
        {
            return unit->getPowerType() != POWER_MANA;
        }
};

class spell_sindragosa_unchained_magic : public SpellScriptLoader
{
    public:
        spell_sindragosa_unchained_magic() : SpellScriptLoader("spell_sindragosa_unchained_magic") { }

        class spell_sindragosa_unchained_magic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sindragosa_unchained_magic_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(UnchainedMagicTargetSelector());
                uint32 maxSize = uint32(GetCaster()->GetMap()->GetSpawnMode() & 1 ? 5 : 2);
                if (unitList.size() > maxSize)
                    Trinity::RandomResizeList(unitList, maxSize);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_sindragosa_unchained_magic_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sindragosa_unchained_magic_SpellScript();
        }
};

class spell_sindragosa_instability : public SpellScriptLoader
{
    public:
        spell_sindragosa_instability() : SpellScriptLoader("spell_sindragosa_instability") { }

        class spell_sindragosa_instability_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sindragosa_instability_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_BACKLASH))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    GetTarget()->CastCustomSpell(SPELL_BACKLASH, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff, GetCasterGUID());
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_sindragosa_instability_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sindragosa_instability_AuraScript();
        }
};

class spell_sindragosa_frost_beacon : public SpellScriptLoader
{
    public:
        spell_sindragosa_frost_beacon() : SpellScriptLoader("spell_sindragosa_frost_beacon") { }

        class spell_sindragosa_frost_beacon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sindragosa_frost_beacon_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ICE_TOMB_DAMAGE))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetTarget(), SPELL_ICE_TOMB_DAMAGE, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sindragosa_frost_beacon_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sindragosa_frost_beacon_AuraScript();
        }
};

class spell_sindragosa_ice_tomb : public SpellScriptLoader
{
    public:
        spell_sindragosa_ice_tomb() : SpellScriptLoader("spell_sindragosa_ice_tomb_trap") { }

        class spell_sindragosa_ice_tomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sindragosa_ice_tomb_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sObjectMgr->GetCreatureTemplate(NPC_ICE_TOMB))
                    return false;
                if (!sObjectMgr->GetGameObjectTemplate(GO_ICE_BLOCK))
                    return false;
                return true;
            }

            void SummonTomb()
            {
                Position pos;
                GetHitUnit()->GetPosition(&pos);
                if (TempSummon* summon = GetCaster()->SummonCreature(NPC_ICE_TOMB, pos))
                {
                    summon->AI()->SetGUID(GetHitUnit()->GetGUID(), DATA_TRAPPED_PLAYER);
                    if (GameObject* go = summon->SummonGameObject(GO_ICE_BLOCK, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 0))
                    {
                        go->SetSpellId(SPELL_ICE_TOMB_DAMAGE);
                        summon->AddGameObject(go);
                    }
                }
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_sindragosa_ice_tomb_SpellScript::SummonTomb);
            }
        };

        class spell_sindragosa_ice_tomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sindragosa_ice_tomb_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sindragosa_ice_tomb_AuraScript::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sindragosa_ice_tomb_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_sindragosa_ice_tomb_AuraScript();
        }
};

class FrostBombTargetSelector
{
    public:
        FrostBombTargetSelector(Unit* caster, std::list<Creature*> const& collisionList) : _caster(caster), _collisionList(collisionList) { }

        bool operator()(Unit* unit)
        {
            if (unit->HasAura(SPELL_ICE_TOMB_DAMAGE))
                return true;

            for (std::list<Creature*>::const_iterator itr = _collisionList.begin(); itr != _collisionList.end(); ++itr)
                if ((*itr)->IsInBetween(_caster, unit))
                    return true;

            return false;
        }

    private:
        Unit* _caster;
        std::list<Creature*> const& _collisionList;
};

class spell_sindragosa_collision_filter : public SpellScriptLoader
{
    public:
        spell_sindragosa_collision_filter() : SpellScriptLoader("spell_sindragosa_collision_filter") { }

        class spell_sindragosa_collision_filter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sindragosa_collision_filter_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ICE_TOMB_DAMAGE))
                    return false;
                return true;
            }

            void FilterTargets(std::list<Unit*>& unitList)
            {
                std::list<Creature*> tombs;
                GetCreatureListWithEntryInGrid(tombs, GetCaster(), NPC_ICE_TOMB, 200.0f);
                unitList.remove_if(FrostBombTargetSelector(GetCaster(), tombs));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_sindragosa_collision_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sindragosa_collision_filter_SpellScript();
        }
};

class spell_sindragosa_icy_grip : public SpellScriptLoader
{
    public:
        spell_sindragosa_icy_grip() : SpellScriptLoader("spell_sindragosa_icy_grip") { }

        class spell_sindragosa_icy_grip_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sindragosa_icy_grip_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ICY_GRIP_JUMP))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetCaster(), SPELL_ICY_GRIP_JUMP, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_sindragosa_icy_grip_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sindragosa_icy_grip_SpellScript();
        }
};

class spell_rimefang_icy_blast : public SpellScriptLoader
{
    public:
        spell_rimefang_icy_blast() : SpellScriptLoader("spell_rimefang_icy_blast") { }

        class spell_rimefang_icy_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rimefang_icy_blast_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ICY_BLAST_AREA))
                    return false;
                return true;
            }

            void HandleTriggerMissile(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Position const* pos = GetTargetDest())
                    if (TempSummon* summon = GetCaster()->SummonCreature(NPC_ICY_BLAST, *pos, TEMPSUMMON_TIMED_DESPAWN, 40000))
                        summon->CastSpell(summon, SPELL_ICY_BLAST_AREA, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_rimefang_icy_blast_SpellScript::HandleTriggerMissile, EFFECT_1, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_rimefang_icy_blast_SpellScript();
        }
};

class OrderWhelpTargetSelector
{
    public:
        explicit OrderWhelpTargetSelector(Creature* owner) : _owner(owner) { }

        bool operator()(Creature* creature)
        {
            if (!creature->AI()->GetData(DATA_WHELP_MARKER) && creature->AI()->GetData(DATA_FROSTWYRM_OWNER) == _owner->AI()->GetData(DATA_FROSTWYRM_OWNER))
                return false;
            return true;
        }

    private:
        Creature* _owner;
};

class spell_frostwarden_handler_order_whelp : public SpellScriptLoader
{
    public:
        spell_frostwarden_handler_order_whelp() : SpellScriptLoader("spell_frostwarden_handler_order_whelp") { }

        class spell_frostwarden_handler_order_whelp_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_frostwarden_handler_order_whelp_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_FOCUS_FIRE))
                    return false;
                return true;
            }

            void FilterTargets(std::list<Unit*>& unitList)
            {
                for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end();)
                {
                    if ((*itr)->GetTypeId() != TYPEID_PLAYER)
                        unitList.erase(itr++);
                    else
                        ++itr;
                }

                std::list<Unit*>::iterator itr = unitList.begin();
                std::advance(itr, urand(0, unitList.size()-1));
                Unit* target = *itr;
                unitList.clear();
                unitList.push_back(target);
            }

            void HandleForcedCast(SpellEffIndex effIndex)
            {
                // caster is Frostwarden Handler, target is player, caster of triggered is whelp
                PreventHitDefaultEffect(effIndex);
                std::list<Creature*> unitList;
                GetCreatureListWithEntryInGrid(unitList, GetCaster(), NPC_FROSTWING_WHELP, 150.0f);
                if (Creature* creature = GetCaster()->ToCreature())
                    unitList.remove_if(OrderWhelpTargetSelector(creature));

                std::list<Creature*>::iterator itr = unitList.begin();
                std::advance(itr, urand(0, unitList.size()-1));
                (*itr)->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_frostwarden_handler_order_whelp_SpellScript::HandleForcedCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_frostwarden_handler_order_whelp_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_DST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_frostwarden_handler_order_whelp_SpellScript();
        }
};

class spell_frostwarden_handler_focus_fire : public SpellScriptLoader
{
    public:
        spell_frostwarden_handler_focus_fire() : SpellScriptLoader("spell_frostwarden_handler_focus_fire") { }

        class spell_frostwarden_handler_focus_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_frostwarden_handler_focus_fire_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->AddThreat(GetHitUnit(), float(GetEffectValue()));
                GetCaster()->GetAI()->SetData(DATA_WHELP_MARKER, 1);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_frostwarden_handler_focus_fire_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        class spell_frostwarden_handler_focus_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_frostwarden_handler_focus_fire_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                {
                    caster->AddThreat(GetTarget(), -float(SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), EFFECT_1)));
                    caster->GetAI()->SetData(DATA_WHELP_MARKER, 0);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_frostwarden_handler_focus_fire_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_frostwarden_handler_focus_fire_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_frostwarden_handler_focus_fire_AuraScript();
        }
};

class at_sindragosa_lair : public AreaTriggerScript
{
    public:
        at_sindragosa_lair() : AreaTriggerScript("at_sindragosa_lair") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (!instance->GetData(DATA_SPINESTALKER))
                    if (Creature* spinestalker = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_SPINESTALKER)))
                        spinestalker->AI()->DoAction(ACTION_START_FROSTWYRM);

                if (!instance->GetData(DATA_RIMEFANG))
                    if (Creature* rimefang = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_RIMEFANG)))
                        rimefang->AI()->DoAction(ACTION_START_FROSTWYRM);

                if (!instance->GetData(DATA_SINDRAGOSA_FROSTWYRMS) && instance->GetBossState(DATA_SINDRAGOSA) != DONE)
                {
                    if (player->GetMap()->IsHeroic() && !instance->GetData(DATA_HEROIC_ATTEMPTS))
                        return true;

                    player->GetMap()->LoadGrid(SindragosaSpawnPos.GetPositionX(), SindragosaSpawnPos.GetPositionY());
                    if (Creature* sindragosa = player->GetMap()->SummonCreature(NPC_SINDRAGOSA, SindragosaSpawnPos))
                        sindragosa->AI()->DoAction(ACTION_START_FROSTWYRM);
                }
            }

            return true;
        }
};

class achievement_all_you_can_eat : public AchievementCriteriaScript
{
    public:
        achievement_all_you_can_eat() : AchievementCriteriaScript("achievement_all_you_can_eat") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;
            return target->GetAI()->GetData(DATA_MYSTIC_BUFFET_STACK) <= 5;
        }
};

void AddSC_boss_sindragosa()
{
    new boss_sindragosa();
    new npc_ice_tomb();
    new npc_spinestalker();
    new npc_rimefang();
    new npc_sindragosa_trash();
    new spell_sindragosa_s_fury();
    new spell_sindragosa_unchained_magic();
    new spell_sindragosa_instability();
    new spell_sindragosa_frost_beacon();
    new spell_sindragosa_ice_tomb();
    new spell_sindragosa_collision_filter();
    new spell_sindragosa_icy_grip();
    new spell_rimefang_icy_blast();
    new spell_frostwarden_handler_order_whelp();
    new spell_frostwarden_handler_focus_fire();
    new spell_trigger_spell_from_caster("spell_sindragosa_ice_tomb", SPELL_ICE_TOMB_DUMMY);
    new spell_trigger_spell_from_caster("spell_sindragosa_ice_tomb_dummy", SPELL_FROST_BEACON);
    new at_sindragosa_lair();
    new achievement_all_you_can_eat();
}

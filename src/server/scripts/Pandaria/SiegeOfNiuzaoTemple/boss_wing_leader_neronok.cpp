#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum GeneralSpells
{
    SPELL_HURL_BRICK = 121762,
    SPELL_CAUSTIC_PITCH_SELECTOR = 121440,
    SPELL_QUICK_DRY_RESIN = 121447,
};

enum GeneralEvents
{
    EVEMNT_FLY_TO_OPPOSITE_SIDE_OF_BRIDGE = 1,
    EVENT_CHECK_IF_REACHED_WP,
    EVENT_CAST_GUSTING_WINDS_1,
    EVENT_CAST_GUSTING_WINDS_2,
    EVENT_CAST_GUSTING_WINDS_3,
    EVENT_CAST_HURL_BRICK,
    EVENT_CAST_CAUSTIC_PITCH,
    EVENT_CAST_QUICK_DRY_RESIN,
};

enum GeneralPoints
{
    POINT_MOVE_UP = 1,

    POINT_MAIN_SIDE_GROUND,
    POINT_MAIN_SIDE_AIR_FROM_GROUND,
    POINT_MAIN_SIDE_AIR_FROM_OTHER_SIDE,

    POINT_OTHER_SIDE_GROUND,
    POINT_OTHER_SIDE_AIR_FROM_GROUND,
    POINT_OTHER_SIDE_AIR_FROM_MAIN_SIDE,
};

//struct BridgePositionMoveStruct
//{
//    uint32 pointId;
//    Position pos;
//};

Position BridgeSidePositions[4] =
{
    { 1887.084f, 5178.723f, 131.1692f, 0.0f }, //! Ground 1
    { 1877.906f, 5187.085f, 142.7834f, 0.0f }, //! Air 1

    { 1810.470f, 5249.528f, 131.1700f, 0.0f }, //! Ground 2
    { 1818.120f, 5242.493f, 142.5388f, 0.0f }, //! Air 2
};

class boss_wing_leader_neronok : public CreatureScript
{
public:
    boss_wing_leader_neronok() : CreatureScript("boss_wing_leader_neronok") { }

    struct boss_wing_leader_neronokAI : public BossAI
    {
        boss_wing_leader_neronokAI(Creature* creature) : BossAI(creature, 0) { }

        bool isOnOtherSideOfBridge, isFlyingToOppositeSide, performedFirstFly;

        uint32 lastPointId;

        uint8 castedGustingWindsCounter;

        void Reset()
        {
            _Reset();
            lastPointId = 0;
            castedGustingWindsCounter = 0;
            isFlyingToOppositeSide = false;
            isOnOtherSideOfBridge = false;
            performedFirstFly = false;
            SetCombatMovement(false);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            RemoveAuraFromPlayers(SPELL_QUICK_DRY_RESIN);
        }

        void JustRespawned()
        {
            Reset();
        }

        void AttackStart(Unit* who)
        {
            AttackStartNoMove(who);
        }

        void EnterCombat(Unit* who)
        {
            _EnterCombat();

            Talk(0, who);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVEMNT_FLY_TO_OPPOSITE_SIDE_OF_BRIDGE, urand(20000, 25000));
            events.ScheduleEvent(EVENT_CAST_HURL_BRICK, 1000);
            events.ScheduleEvent(EVENT_CAST_CAUSTIC_PITCH, urand(3000, 5000));
            events.ScheduleEvent(EVENT_CAST_QUICK_DRY_RESIN, urand(19000, 25000));

        }

        void JustDied(Unit* killer)
        {
            _JustDied();

            RemoveAuraFromPlayers(SPELL_QUICK_DRY_RESIN);

            Talk(3, killer);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void KilledUnit(Unit* victim)
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(3, victim);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
        }

        void JustReachedHome()
        {
            summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned)
        {
            summons.Summon(summoned);
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            /*
            POINT_MAIN_SIDE_GROUND,
            POINT_MAIN_SIDE_AIR_FROM_GROUND,
            POINT_MAIN_SIDE_AIR_FROM_OTHER_SIDE,

            POINT_OTHER_SIDE_GROUND,
            POINT_OTHER_SIDE_AIR_FROM_GROUND,
            POINT_OTHER_SIDE_AIR_FROM_MAIN_SIDE,
            */
        }

        void HandleReachedPointId(uint32 pointId)
        {
            switch (pointId)
            {
            case POINT_MAIN_SIDE_GROUND:
                isOnOtherSideOfBridge = false;
                isFlyingToOppositeSide = false;
                me->SetReactState(REACT_AGGRESSIVE);
                AttackStartNoMove(me->SelectNearestPlayer(100.0f));
                events.CancelEvent(EVENT_CHECK_IF_REACHED_WP);
                //events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_1, 1000);
                //events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_2, 1000 + 4000 + 5000);
                //events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_3, 1000 + 4000 + 5000 + 4000 + 5000);
                //castedGustingWindsCounter = 0;
                break;
            case POINT_OTHER_SIDE_GROUND:
                isOnOtherSideOfBridge = true;
                isFlyingToOppositeSide = false;
                me->SetReactState(REACT_AGGRESSIVE);
                AttackStartNoMove(me->SelectNearestPlayer(100.0f));
                events.CancelEvent(EVENT_CHECK_IF_REACHED_WP);
                //events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_1, 1000);
                //events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_2, 1000 + 4000 + 5000);
                //events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_3, 1000 + 4000 + 5000 + 4000 + 5000);
                //castedGustingWindsCounter = 0;
                break;
            case POINT_MAIN_SIDE_AIR_FROM_GROUND:
                PrepareForFly();
                MoveToPoint(POINT_OTHER_SIDE_AIR_FROM_MAIN_SIDE, BridgeSidePositions[3]);
                break;
            case POINT_OTHER_SIDE_AIR_FROM_MAIN_SIDE:
                PrepareForFly();
                MoveToPoint(POINT_OTHER_SIDE_GROUND, BridgeSidePositions[2]);
                break;
            case POINT_OTHER_SIDE_AIR_FROM_GROUND:
                PrepareForFly();
                MoveToPoint(POINT_MAIN_SIDE_AIR_FROM_OTHER_SIDE, BridgeSidePositions[1]);
                break;
            case POINT_MAIN_SIDE_AIR_FROM_OTHER_SIDE:
                PrepareForFly();
                MoveToPoint(POINT_MAIN_SIDE_GROUND, BridgeSidePositions[0]);
                break;
            }
        }

        void PrepareForFly()
        {
            //events.CancelEvent(EVENT_CAST_GUSTING_WINDS_1);
            //events.CancelEvent(EVENT_CAST_GUSTING_WINDS_2);
            //events.CancelEvent(EVENT_CAST_GUSTING_WINDS_3);
            isFlyingToOppositeSide = true;
            ReSetSpeed();
            DoStopAttack();
            me->SetCanFly(true);
            me->SetReactState(REACT_PASSIVE);
        }

        void ReSetSpeed()
        {
            //! First set 2.4, then 2.5 to force client update (creds to shocker)
            me->SetSpeed(MOVE_FLIGHT, 2.4f);
            me->SetSpeed(MOVE_RUN, 2.4f);
            me->SetSpeed(MOVE_FLIGHT, 2.5f);
            me->SetSpeed(MOVE_RUN, 2.5f);
        }
        void MoveToPoint(uint32 pointId, Position loc)
        {
            lastPointId = pointId;
            me->GetMotionMaster()->MovePoint(pointId, loc, false);
        }

        Position GetPositionForPointId(uint32 pointId)
        {
            switch (lastPointId)
            {
            case POINT_MAIN_SIDE_GROUND:
                return BridgeSidePositions[0];
            case POINT_OTHER_SIDE_GROUND:
                return BridgeSidePositions[2];
                break;
            case POINT_MAIN_SIDE_AIR_FROM_GROUND:
            case POINT_MAIN_SIDE_AIR_FROM_OTHER_SIDE:
                return BridgeSidePositions[1];
                break;
            case POINT_OTHER_SIDE_AIR_FROM_MAIN_SIDE:
            case POINT_OTHER_SIDE_AIR_FROM_GROUND:
                return BridgeSidePositions[3];
                break;
            }

            return BridgeSidePositions[0];
        }

        void UpdateAI(uint32 diff)
        {
            //if (isFlyingToOppositeSide)
            //{
            //    me->SetSpeed(MOVE_WALK, 2.5f, true);
            //    me->SetSpeed(MOVE_FLIGHT, 2.5f, true);
            //    me->SetSpeed(MOVE_RUN, 2.5f, true);
            //}

            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))// || isFlyingToOppositeSide)
                return;

            switch (events.ExecuteEvent())
            {
            case EVEMNT_FLY_TO_OPPOSITE_SIDE_OF_BRIDGE:
                PrepareForFly();
                Talk(1);
                Talk(2);

                if (!isOnOtherSideOfBridge)
                {
                    performedFirstFly = true;
                    MoveToPoint(POINT_MAIN_SIDE_AIR_FROM_GROUND, BridgeSidePositions[1]);
                    events.ScheduleEvent(EVEMNT_FLY_TO_OPPOSITE_SIDE_OF_BRIDGE, 30000 + urand(16000, 21000));
                }
                else
                    MoveToPoint(POINT_OTHER_SIDE_AIR_FROM_GROUND, BridgeSidePositions[3]);

                events.ScheduleEvent(EVENT_CHECK_IF_REACHED_WP, 500);
                events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_1, 8000 + 1000);
                events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_2, 8000 + 1000 + 4000 + 5000);
                events.ScheduleEvent(EVENT_CAST_GUSTING_WINDS_3, 8000 + 1000 + 4000 + 5000 + 4000 + 5000);
                break;
            case EVENT_CHECK_IF_REACHED_WP:
                if (me->GetDistance(GetPositionForPointId(lastPointId)) < 2.5f)
                    HandleReachedPointId(lastPointId);

                events.ScheduleEvent(EVENT_CHECK_IF_REACHED_WP, 500);
                break;
            case EVENT_CAST_GUSTING_WINDS_1:
            case EVENT_CAST_GUSTING_WINDS_2:
            case EVENT_CAST_GUSTING_WINDS_3:
                //DoCast(isOnOtherSideOfBridge ? 121284 : 121282);

                if (isOnOtherSideOfBridge)
                    me->CastSpell(me, 121284, false);
                else
                    me->CastSpell(me, 121282, false);

                break;
            case EVENT_CAST_HURL_BRICK:
                me->CastSpell(me->GetVictim(), SPELL_HURL_BRICK, false);
                events.ScheduleEvent(EVENT_CAST_HURL_BRICK, urand(2000, 4000));
                break;
            case EVENT_CAST_CAUSTIC_PITCH:
                me->CastSpell(me, SPELL_CAUSTIC_PITCH_SELECTOR, false);
                events.ScheduleEvent(EVENT_CAST_CAUSTIC_PITCH, urand(8000, 14000));
                break;
            case EVENT_CAST_QUICK_DRY_RESIN:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    me->AddAura(SPELL_QUICK_DRY_RESIN, target);

                events.ScheduleEvent(EVENT_CAST_QUICK_DRY_RESIN, urand(19000, 25000));
                break;
            }

            DoMeleeAttackIfReady();
        }

        bool CheckInRoom()
        {
            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 200.0f)
            {
                EnterEvadeMode();
                return false;
            }

            return true;
        }

        void RemoveAuraFromPlayers(uint32 spell)
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();

            if (!players.isEmpty())
                for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                    if (Player* player = i->GetSource())
                        player->RemoveAurasDueToSpell(spell);
        }

        /*void ForcePlayersMoveByGustingWinds(Player* player)
        {
            ObjectGuid plrGuid = player->GetGUID();
            WorldPacket data(SMSG_CLIENT_MOVE_APPLY_MOVEMENT_FORCE);
            float xOffset = -5.4f, yOffset = 5.8f, zOffset = 0.0f;

            data.WriteBit(plrGuid[2]);
            data.WriteBit(plrGuid[3]);
            data.WriteBits(0, 2);
            data.WriteBit(plrGuid[7]);
            data.WriteBit(plrGuid[5]);
            data.WriteBit(plrGuid[0]);
            data.WriteBit(plrGuid[1]);
            data.WriteBit(plrGuid[6]);
            data.WriteBit(plrGuid[4]);
            data.FlushBits();
            data.WriteByteSeq(plrGuid[6]);
            data << float(yOffset); // Y offset
            data.WriteByteSeq(plrGuid[4]);
            data << float(zOffset); // Z offset
            data << int32(0);
            data << int32(0x10001000); // movement ID ?
            data.WriteByteSeq(plrGuid[5]);
            data << float(8.0f); // magnitude
            data.WriteByteSeq(plrGuid[0]);
            data.WriteByteSeq(plrGuid[7]);
            data.WriteByteSeq(plrGuid[1]);
            data.WriteByteSeq(plrGuid[3]);
            data.WriteByteSeq(plrGuid[2]);
            data << int32(0);
            data << float(xOffset); // X offset
            player->SendDirectMessage(&data);
        }

        void ForcePlayersMoveStopByGustingWinds(Player* player)
        {
            ObjectGuid plrGuid = player->GetGUID();
            WorldPacket data(SMSG_CLIENT_MOVE_REMOVE_MOVEMENT_FORCE);

            data.WriteBit(plrGuid[1]);
            data.WriteBit(plrGuid[2]);
            data.WriteBit(plrGuid[4]);
            data.WriteBit(plrGuid[7]);
            data.WriteBit(plrGuid[6]);
            data.WriteBit(plrGuid[0]);
            data.WriteBit(plrGuid[5]);
            data.WriteBit(plrGuid[3]);
            data.WriteByteSeq(plrGuid[4]);
            data.WriteByteSeq(plrGuid[7]);
            data.WriteByteSeq(plrGuid[0]);
            data << int32(0);
            data.WriteByteSeq(plrGuid[1]);
            data.WriteByteSeq(plrGuid[3]);
            data.WriteByteSeq(plrGuid[5]);
            data << int32(0x10001000); // movement ID ?
            data.WriteByteSeq(plrGuid[6]);
            data.WriteByteSeq(plrGuid[2]);
            player->SendDirectMessage(&data);
        }*/
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_wing_leader_neronokAI(creature);
    }
};

class npc_wing_leader_neronok_sticky_resin : public CreatureScript
{
public:
    npc_wing_leader_neronok_sticky_resin() : CreatureScript("npc_wing_leader_neronok_sticky_resin") { }

    struct npc_wing_leader_neronok_sticky_resinAI : public ScriptedAI
    {
        npc_wing_leader_neronok_sticky_resinAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            me->CastSpell(me, 121443, false);
            me->SetReactState(REACT_PASSIVE);
        }

        void JustRespawned()
        {
            Reset();
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_wing_leader_neronok_sticky_resinAI(creature);
    }
};

class CausticPitchTargetSelector
{
public:
    CausticPitchTargetSelector() { }

    bool operator()(WorldObject* object)
    {
        return !object || object->GetTypeId() != TYPEID_PLAYER;
    }
};

class spell_wing_leader_neronok_caustic_pitch_target_selector : public SpellScriptLoader
{
public:
    spell_wing_leader_neronok_caustic_pitch_target_selector() : SpellScriptLoader("spell_wing_leader_neronok_caustic_pitch_target_selector") { }

    class spell_wing_leader_neronok_caustic_pitch_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_wing_leader_neronok_caustic_pitch_target_selector_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(CausticPitchTargetSelector());
            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleScript(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    Position pos;
                    target->GetPosition();
                    caster->MovePosition(pos, 9.5f * (float)rand_norm(), (float)rand_norm() * static_cast<float>(2 * M_PI));
                    caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, true);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wing_leader_neronok_caustic_pitch_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_wing_leader_neronok_caustic_pitch_target_selector_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_wing_leader_neronok_caustic_pitch_target_selector_SpellScript();
    }
};

class LowerAlternatePowerEvent : public BasicEvent
{
public:
    LowerAlternatePowerEvent(Player& target) : BasicEvent(), _target(target) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/)
    {
        _target.SetPower(POWER_ALTERNATE_POWER, _target.GetPower(POWER_ALTERNATE_POWER) - urand(1, 30));
        return true;
    }

private:
    Player& _target;
};

class spell_wing_leader_neronok_quick_dry_resin_aura : public SpellScriptLoader
{
public:
    spell_wing_leader_neronok_quick_dry_resin_aura() : SpellScriptLoader("spell_wing_leader_neronok_quick_dry_resin_aura") { }

    class spell_wing_leader_neronok_quick_dry_resin_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_wing_leader_neronok_quick_dry_resin_aura_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* targetUnit = GetTarget())
            {
                if (Player* target = targetUnit->ToPlayer())
                {
                    //if (target->m_movementInfo.jump.fallTime)
                    //{
                    //    //target->SetPower(POWER_ALTERNATE_POWER, target->GetPower(POWER_ALTERNATE_POWER) - urand(3, 5));
                    //    //for (int i = 0; i < 2; ++i)
                    //        target->m_Events.AddEvent(new LowerAlternatePowerEvent(*target), target->m_Events.CalculateTime((0 + 1) * 100));
                    //}
                    //else

                    if (target->m_movementInfo.jump.fallTime)
                    {
                        uint32 number = urand(1, 2);
                        //std::stringstream ss;
                        //ss << "Power: " << target->GetPower(POWER_ALTERNATE_POWER) << ". Taking out: " << number;
                        //target->MonsterSay(ss.str().c_str(), LANG_UNIVERSAL, target);
                        target->SetPower(POWER_ALTERNATE_POWER, target->GetPower(POWER_ALTERNATE_POWER) - number);
                    }
                    else
                        if (urand(0, 2) == 0)
                            target->SetPower(POWER_ALTERNATE_POWER, target->GetPower(POWER_ALTERNATE_POWER) + urand(1, 2));

                    if (target->GetPower(POWER_ALTERNATE_POWER) >= 100)
                    {
                        target->RemoveAurasDueToSpell(SPELL_QUICK_DRY_RESIN);
                        //target->CastSpell(target, 122063, false); //! Screen effect
                        target->CastSpell(target, 121448, false); //! Encased in Resin
                    }
                    else if (target->GetPower(POWER_ALTERNATE_POWER) <= 1)
                    {
                        target->RemoveAurasDueToSpell(SPELL_QUICK_DRY_RESIN);
                        target->CastSpell(target, 121449, false); //! Invigorated
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_wing_leader_neronok_quick_dry_resin_aura_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_wing_leader_neronok_quick_dry_resin_aura_AuraScript();
    }
};

void AddSC_boss_wing_leader_neronok()
{
    new boss_wing_leader_neronok();

    new npc_wing_leader_neronok_sticky_resin();

    new spell_wing_leader_neronok_caustic_pitch_target_selector();
    new spell_wing_leader_neronok_quick_dry_resin_aura();
    //new spell_wing_leader_neronok_gusting_winds();
}
///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "black_rook_hold.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_VENGEFUL_SHEAR = 1,
//    SAY_DARK_RUSH = 2,
//    SAY_WARN_DARK_RUSH = 3,
//    SAY_PHASE_FLY = 4,
//    SAY_EYE_BEAMS = 5,
//    SAY_WARN_EYE_BEAMS = 6,
//    SAY_DEATH = 7,
//};
//
//enum Spells
//{
//    SPELL_FURY_POWER_OVERRIDE = 197367,
//    SPELL_REGEN_POWER = 197394,
//    SPELL_BRUTAL_GLAIVE = 197546,
//    SPELL_VENGEFUL_SHEAR = 197418,
//    SPELL_DARK_RUSH_FILTER = 197478,
//    SPELL_DARK_RUSH_CHARGE = 197484,
//    SPELL_PHASE_FLY_JUMP = 197622,
//    SPELL_EYE_BEAMS = 197674,
//    SPELL_EYE_BEAMS_AURA = 197696,
//    SPELL_EYE_BEAMS_AT = 197703,
//    SPELL_FIXATE_BEAM = 197687,
//
//    //Christmas
//    SPELL_CHRISTMAS_CAP = 220873,
//
//    //Other
//    SPELL_BOULDER_EXPLODE_AT = 222378,
//    SPELL_BOULDER_EXPLODE_REMOVE = 222388,
//
//    SPELL_DRINK_ANCIENT_POTION = 200784,
//    SPELL_HYPERACTIVE_DUMMY = 201064,
//    SPELL_HYPERACTIVE_AT = 201063, //Dmg 201062
//    SPELL_DIZZY_STUN = 201070,
//    SPELL_INDIGESTION_DUMMY = 200958,
//    SPELL_INDIGESTION_CHANNEL = 200913,
//    SPELL_FRENZY_POTION = 201061,
//};
//
//enum eEvents
//{
//    EVENT_BRUTAL_GLAIVE = 1,
//    EVENT_VENGEFUL_SHEAR = 2,
//    EVENT_DARK_RUSH_1 = 3,
//    EVENT_DARK_RUSH_2 = 4,
//    EVENT_SUMMON_ADDS = 5,
//    EVENT_EYE_BEAMS = 6,
//    EVENT_PHASE_FLY = 7,
//    EVENT_PHASE_GROUND = 8,
//
//    DATA_ACHIEVEMENT,
//
//    EVENT_1,
//    EVENT_2,
//    EVENT_3,
//};
//
//std::vector<std::pair<uint32, Position>> introSumPos
//{
//    {98706, {3104.32f, 7320.2f,  96.0f, 0.91f}},  //Commander Shemdah'sohn
//    {98275, {3121.12f, 7335.8f, 86.37f, 1.18f}},  //Risen Archer
//    {98275, {3114.48f, 7340.4f, 86.37f, 0.73f}},  //Risen Archer
//    {98275, {3096.66f, 7343.5f, 102.69f, 5.64f}}, //Risen Archer
//    {98275, {3129.64f, 7319.1f, 102.78f, 2.94f}}, //Risen Archer
//    {98280, {3114.86f, 7346.0f, 86.50f, 0.20f}},  //Risen Arcanist
//    {98691, {3125.06f, 7336.8f, 86.46f, 1.68f}},  //Risen Scout
//    {98691, {3111.49f, 7364.9f, 102.69f, 5.60f}}, //Risen Scout
//    {98691, {3145.1f,  7340.7f, 102.78f, 2.63f}}  //Risen Scout
//};
//
//Position const summonsPos[2] =
//{
//    {3105.11f, 7296.94f, 103.28f, 3.14f}, //NPC_RISEN_ARCANIST
//    {3083.07f, 7313.35f, 103.28f, 4.92f}  //NPC_SOUL_TORN_VANGUARD
//};
//
////98696
//struct boss_illysanna_ravencrest : public BossAI
//{
//    boss_illysanna_ravencrest(Creature* creature) : BossAI(creature, DATA_ILLYSANNA)
//    {
//        if (me->IsAlive())
//            Intro();
//    }
//
//    std::list<ObjectGuid> trashGuidList;
//    bool phaseTwo = false;
//    bool achievement = true;
//    uint8 trashDiedCount = 0;
//
//    void Intro()
//    {
//        if (instance->GetData(DATA_ILLYSANNA_INTRO) == DONE)
//        {
//            me->SetHomePosition(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ(), 3.6f);
//            me->SetFacingTo(3.6f);
//            return;
//        }
//
//        instance->SetData(DATA_ILLYSANNA_INTRO, IN_PROGRESS);
//        me->SetReactState(REACT_PASSIVE);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//
//        for (auto& pair : introSumPos)
//        {
//            if (auto trash = me->SummonCreature(pair.first, pair.second))
//            {
//                if (trash->GetPositionZ() > 100.0f || trash->GetEntry() == NPC_COMMANDER_SHEMDAHSOHN)
//                {
//                    trashGuidList.push_back(trash->GetGUID());
//                    trash->SetReactState(REACT_PASSIVE);
//                    trash->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                    trash->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                    trash->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//                }
//            }
//        }
//    }
//
//    void Reset() override
//    {
//        _Reset();
//        me->SetPower(POWER_ENERGY, 100);
//        DoCast(me, SPELL_FURY_POWER_OVERRIDE, true);
//        DoCast(me, SPELL_REGEN_POWER, true);
//        me->SetReactState(REACT_AGGRESSIVE);
//        me->SetCanFly(true);
//        phaseTwo = false;
//        achievement = true;
//
//        if (!IsCombatMovementAllowed())
//            SetCombatMovement(true);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        DefaultEvents();
//        Talk(SAY_AGGRO);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        _JustDied();
//    }
//
//    void DefaultEvents()
//    {
//        events.RescheduleEvent(EVENT_BRUTAL_GLAIVE, 6000);
//        events.RescheduleEvent(EVENT_VENGEFUL_SHEAR, 9000);
//        events.RescheduleEvent(EVENT_DARK_RUSH_1, 12000);
//    }
//
//    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SPELL_DARK_RUSH_FILTER:
//            Talk(SAY_WARN_DARK_RUSH);
//            break;
//        case SPELL_VENGEFUL_SHEAR:
//                DoCast(target, 197429, true); //debuff: mod damage
//            break;
//        case SPELL_EYE_BEAMS:
//        {
//            Talk(SAY_WARN_EYE_BEAMS);
//            if (auto stalker = me->SummonCreature(NPC_EYE_BEAM_STALKER, target->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 12000))
//                DoCast(stalker, SPELL_EYE_BEAMS_AURA, true);
//            break;
//        }
//        default:
//            break;
//        }
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == EFFECT_MOTION_TYPE)
//        {
//            if (id == SPELL_PHASE_FLY_JUMP)
//            {
//                Talk(SAY_EYE_BEAMS);
//                me->GetMotionMaster()->Clear(false);
//                me->SetFacingTo(4.05f);
//                events.RescheduleEvent(EVENT_SUMMON_ADDS, 1000);
//                events.RescheduleEvent(EVENT_EYE_BEAMS, 2000);
//            }
//            if (id == 1)
//            {
//                me->SetCanFly(true);
//                me->SetReactState(REACT_AGGRESSIVE);
//                DoCast(me, SPELL_REGEN_POWER, true);
//                phaseTwo = false;
//            }
//        }
//
//        if (type == POINT_MOTION_TYPE)
//        {
//            if (id == SPELL_DARK_RUSH_CHARGE)
//                events.RescheduleEvent(EVENT_DARK_RUSH_2, 500);
//        }
//    }
//
//    void DoAction(int32 const action) override
//    {
//        if (!phaseTwo)
//        {
//            phaseTwo = true;
//            events.RescheduleEvent(EVENT_PHASE_FLY, 500);
//        }
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        if (type == DATA_ACHIEVEMENT)
//            return achievement;
//
//        return 0;
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//    {
//        switch (summon->GetEntry())
//        {
//        case NPC_RISEN_ARCANIST:
//        case NPC_SOUL_TORN_VANGUARD:
//            achievement = false;
//            break;
//        case NPC_INTRO_RISEN_ARCHER:
//        case NPC_INTRO_RISEN_ARCANIST:
//        case NPC_INTRP_RISEN_SCOUT:
//        case NPC_COMMANDER_SHEMDAHSOHN:
//        {
//            ++trashDiedCount;
//
//            if (trashDiedCount == 4)
//            {
//                for (auto guid : trashGuidList)
//                {
//                    if (auto trash = Creature::GetCreature(*me, guid))
//                    {
//                        Position pos;
//                        float x, y;
//                        trash->GetNearPoint2D(x,y, 15.0f, 0.0f);
//                        pos.m_positionZ = trash->GetPositionZ();
//                        trash->SetHomePosition(pos);
//                        trash->GetMotionMaster()->MoveJump(pos, 15.0f, 10.0f, 15.0f);
//                    }
//                }
//                for (auto guid : trashGuidList)
//                {
//                    if (auto trash = Creature::GetCreature(*me, guid))
//                    {
//                        trash->SetReactState(REACT_AGGRESSIVE);
//                        trash->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                        trash->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                        trash->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
//                        trash->AI()->DoZoneInCombat(trash, 60.0f);
//                    }
//                }
//            }
//            else if (trashDiedCount == 9)
//            {
//                instance->SetData(DATA_ILLYSANNA_INTRO, DONE);
//                me->SetHomePosition(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ(), 3.6f);
//                me->SetFacingTo(3.6f);
//                me->SetReactState(REACT_AGGRESSIVE);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
//            }
//            break;
//        }
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_BRUTAL_GLAIVE:
//                if (auto pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true, false ,-SPELL_BRUTAL_GLAIVE))
//                    DoCast(pTarget, SPELL_BRUTAL_GLAIVE);
//                else if (auto pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true, false))
//                    DoCast(pTarget, SPELL_BRUTAL_GLAIVE);
//                events.RescheduleEvent(EVENT_BRUTAL_GLAIVE, 16000);
//                break;
//            case EVENT_VENGEFUL_SHEAR:
//                Talk(SAY_VENGEFUL_SHEAR);
//                DoCastVictim(SPELL_VENGEFUL_SHEAR);
//                events.RescheduleEvent(EVENT_VENGEFUL_SHEAR, urandms(12, 15));
//                break;
//            case EVENT_DARK_RUSH_1:
//                Talk(SAY_DARK_RUSH);
//                DoCast(SPELL_DARK_RUSH_FILTER);
//                for (auto id : { EVENT_BRUTAL_GLAIVE, EVENT_VENGEFUL_SHEAR, EVENT_PHASE_FLY })
//                    events.RescheduleEvent(id, 9000, true);
//                SetCombatMovement(true);
//                events.RescheduleEvent(EVENT_DARK_RUSH_1, 30000);
//                events.RescheduleEvent(EVENT_DARK_RUSH_2, 6000);
//                break;
//            case EVENT_DARK_RUSH_2:
//                if (SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, false , SPELL_DARK_RUSH_FILTER))
//                    DoCast(me, SPELL_DARK_RUSH_CHARGE, true);
//                break;
//            case EVENT_SUMMON_ADDS:
//                if (me->GetMap()->GetDifficultyID() != DIFFICULTY_LFR && me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
//                    me->SummonCreature(NPC_RISEN_ARCANIST, summonsPos[0]);
//                me->SummonCreature(NPC_SOUL_TORN_VANGUARD, summonsPos[1]);
//                break;
//            case EVENT_EYE_BEAMS:
//            {
//                int8 powerCount = me->GetPower(POWER_ENERGY) - 34;
//                if (powerCount <= 0)
//                {
//                    powerCount = 0;
//                    events.RescheduleEvent(EVENT_PHASE_GROUND, 14000);
//                }
//                else
//                    events.RescheduleEvent(EVENT_EYE_BEAMS, 13000);
//                DoCast(SPELL_EYE_BEAMS);
//                me->SetPower(POWER_ENERGY, powerCount);
//                break;
//            }
//            case EVENT_PHASE_FLY:
//                Talk(SAY_PHASE_FLY);
//                events.Reset();
//                me->AttackStop();
//                me->RemoveAurasDueToSpell(SPELL_REGEN_POWER);
//                me->SetCanFly(true);
//                DoCast(me, SPELL_PHASE_FLY_JUMP, true);
//                break;
//            case EVENT_PHASE_GROUND:
//                DefaultEvents();
//                DoCast(me, SPELL_FURY_POWER_OVERRIDE, true);
//                me->GetMotionMaster()->MoveJump(3089.76f, 7299.66f, 103.53f, 25, 15, 1); //HomePos
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////100436
//struct npc_illysanna_eye_beam_stalker : public ScriptedAI
//{
//    npc_illysanna_eye_beam_stalker(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//    ObjectGuid targetGuid;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        events.RescheduleEvent(EVENT_1, 500);
//        events.RescheduleEvent(EVENT_2, 1000);
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        damage = 0;
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//            {
//                if (auto summoner = me->GetOwner())
//                    if (auto target = summoner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                    {
//                        targetGuid = target->GetGUID();
//                        me->CastSpell(target, SPELL_FIXATE_BEAM, true);
//                    }
//                events.RescheduleEvent(EVENT_1, 6000);
//                break;
//            }
//            case EVENT_2:
//                if (auto plrTarget = ObjectAccessor::GetUnit(*me, targetGuid))
//                    me->GetMotionMaster()->MovePoint(1, plrTarget->GetPosition(), false);
//                events.RescheduleEvent(EVENT_2, 500);
//                break;
//            }
//        }
//    }
//};
//
////98706
//struct npc_illysanna_commandir : public ScriptedAI
//{
//    npc_illysanna_commandir(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//
//    void Reset() override
//    {
//        events.Reset();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        events.ScheduleEvent(EVENT_1, 8000);
//        events.ScheduleEvent(EVENT_2, 12000);
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        me->SetReactState(REACT_AGGRESSIVE);
//    }
//
//    void DoAction(int32 const action) override
//    {
//        Talk(0);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//                me->AttackStop();
//                me->SetReactState(REACT_AGGRESSIVE);
//                me->CastSpell(me, 200261);
//                events.RescheduleEvent(EVENT_1, 22000);
//                break;
//            case EVENT_2:
//                DoCast(225998);
//                events.RescheduleEvent(EVENT_2, 30000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////100486
//struct npc_illysanna_trash_generic : public ScriptedAI
//{
//    npc_illysanna_trash_generic(Creature* creature) : ScriptedAI(creature) {}
//
//    void Reset() override {}
//
//    void JustEngagedWith(Unit* /*who*/) override {}
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        DoSpellAttackIfReady(197797);
//    }
//};
//
////111706
//struct npc_brh_boulder : public ScriptedAI
//{
//    npc_brh_boulder(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void Reset()
//    {
//        DoCast(me, SPELL_BOULDER_EXPLODE_AT, true);
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == EFFECT_MOTION_TYPE)
//        {
//            me->CastSpell(me, SPELL_BOULDER_EXPLODE_REMOVE, false);
//            me->DespawnOrUnsummon(100);
//        }
//    }
//
//    void UpdateAI(uint32 diff) override {}
//};
//
////98792
//struct npc_brh_wyrmtongue_scavenger : public ScriptedAI
//{
//    npc_brh_wyrmtongue_scavenger(Creature* creature) : ScriptedAI(creature) {}
//
//    ObjectGuid fixateGUID;
//    uint8 ancientEvent = 0;
//    uint32 healthPct = 66;
//    uint32 indigestionTimer = 0;
//    uint32 hyperactiveTimer = 0;
//
//    void Reset()
//    {
//        fixateGUID.Clear();
//        me->SetReactState(REACT_AGGRESSIVE);
//        indigestionTimer = 0;
//        hyperactiveTimer = 0;
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        SetAncientEvent(true);
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (HealthBelowPct(healthPct))
//        {
//            healthPct = 0;
//            me->CastSpell(me, SPELL_DRINK_ANCIENT_POTION);
//        }
//    }
//
//    void SpellHit(Unit* caster, SpellInfo const* spell) override
//    {
//        if (spell->Id == SPELL_DRINK_ANCIENT_POTION && !ancientEvent)
//        {
//            ancientEvent = urand(1, 3);
//            SetAncientEvent();
//        }
//    }
//
//    void SetAncientEvent(bool JustEngagedWith = false)
//    {
//        switch (ancientEvent)
//        {
//        case 1:
//            if (!JustEngagedWith)
//                Talk(0);
//            me->AttackStop();
//            DoCast(me, SPELL_HYPERACTIVE_DUMMY, true);
//            hyperactiveTimer = 500;
//            break;
//        case 2:
//            DoCast(me, SPELL_INDIGESTION_DUMMY, true);
//            indigestionTimer = 2000;
//            break;
//        case 3:
//            if (!JustEngagedWith)
//                DoCast(me, SPELL_FRENZY_POTION, true);
//            break;
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        if (me->HasUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED))
//            return;
//
//        if (indigestionTimer)
//        {
//            if (indigestionTimer <= diff)
//            {
//                indigestionTimer = 2000;
//
//                if (auto victim = me->GetVictim())
//                {
//                    if (me->IsWithinMeleeRange(victim))
//                    {
//                        indigestionTimer = 0;
//                        me->AttackStop();
//                        me->CastSpell(me, SPELL_INDIGESTION_CHANNEL);
//                    }
//                }
//            }
//            else
//                indigestionTimer -= diff;
//        }
//
//        if (hyperactiveTimer)
//        {
//            if (hyperactiveTimer <= diff)
//            {
//                hyperactiveTimer = 1000;
//                auto target = ObjectAccessor::GetUnit(*me, fixateGUID);
//
//                if (target && target->IsAlive() && target->HasAura(SPELL_HYPERACTIVE_AT, me->GetGUID()))
//                    me->GetMotionMaster()->MovePoint(1, target->GetPosition(), false);
//                else if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                {
//                    hyperactiveTimer = 3500;
//                    fixateGUID = target->GetGUID();
//                    me->CastSpell(target, SPELL_HYPERACTIVE_AT);
//                }
//            }
//            else
//                hyperactiveTimer -= diff;
//        }
//
//        if (!ancientEvent || ancientEvent == 3)
//            DoMeleeAttackIfReady();
//    }
//};
//
////197394
//class spell_illysanna_periodic_energize : public AuraScript
//{
//    PrepareAuraScript(spell_illysanna_periodic_energize);
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        auto caster = GetCaster()->ToCreature();
//        if (!caster || !caster->IsInCombat())
//            return;
//
//        uint8 powerCount = caster->GetPower(POWER_ENERGY);
//
//        if (powerCount < 100)
//            caster->SetPower(POWER_ENERGY, powerCount + 1);
//        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
//            caster->AI()->DoAction(true);
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_illysanna_periodic_energize::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////197696
//class spell_illysanna_eye_beams : public AuraScript
//{
//    PrepareAuraScript(spell_illysanna_eye_beams);
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (!GetCaster() || !GetTarget())
//            return;
//
//        GetCaster()->CastSpell(GetTarget(), SPELL_EYE_BEAMS_AT, true);
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_illysanna_eye_beams::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////197484
//class spell_illysanna_dark_rush : public SpellScript
//{
//    PrepareSpellScript(spell_illysanna_dark_rush);
//
//    std::list<WorldObject*> tempTargets;
//    Position savePos;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!tempTargets.empty())
//        {
//            targets = tempTargets;
//            return;
//        }
//
//        targets.remove_if([this](WorldObject* object) -> bool
//        {
//            if (object == nullptr || !object->IsPlayer() || !object->ToUnit()->HasAura(SPELL_DARK_RUSH_FILTER))
//                return true;
//
//            return false;
//        });
//
//        if (GetCaster() && !targets.empty())
//        {
//            targets.resize(1);
//
//            if (auto object = targets.front())
//            {
//                tempTargets.push_back(object);
//                savePos = object->GetPosition();
//            }
//        }
//    }
//
//    void HandleDummy(SpellEffIndex effectIndex)
//    {
//        if (tempTargets.empty())
//        {
//            PreventHitEffect(effectIndex);
//            return;
//        }
//
//        //GetCaster()->GetMotionMaster()->MoveCharge(savePos, 20.0f);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_illysanna_dark_rush::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_illysanna_dark_rush::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
//        OnEffectLaunch += SpellEffectFn(spell_illysanna_dark_rush::HandleDummy, EFFECT_3, SPELL_EFFECT_CREATE_AREATRIGGER);
//    }
//};
//
////32384
//class achievement_adds_more_like_bads : public AchievementCriteriaScript
//{
//public:
//    achievement_adds_more_like_bads() : AchievementCriteriaScript("achievement_adds_more_like_bads") { }
//
//    bool OnCheck(Player* /*player*/, Unit* target) override
//    {
//        if (!target)
//            return false;
//
//        if (auto boss = target->ToCreature())
//            if (boss->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || boss->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE)
//                if (boss->GetAI()->GetData(DATA_ACHIEVEMENT))
//                    return true;
//
//        return false;
//    }
//};
//
//void AddSC_boss_illysanna_ravencrest()
//{
//    RegisterCreatureAI(boss_illysanna_ravencrest);
//    RegisterCreatureAI(npc_illysanna_eye_beam_stalker);
//    RegisterCreatureAI(npc_illysanna_commandir);
//    RegisterCreatureAI(npc_illysanna_trash_generic);
//    RegisterCreatureAI(npc_brh_boulder);
//    RegisterCreatureAI(npc_brh_wyrmtongue_scavenger);
//    RegisterAuraScript(spell_illysanna_periodic_energize);
//    RegisterAuraScript(spell_illysanna_eye_beams);
//    RegisterSpellScript(spell_illysanna_dark_rush);
//    new achievement_adds_more_like_bads();
//}

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
//#include "neltharions_lair.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_SUM = 0,
//    SAY_EMOTE = 1,
//};
//
//enum Spells
//{
//    SPELL_INTRO_MYSTIC = 209625, //Boss 03 Intro Mystic Cast - визуально прячется?
//    SPELL_INTRO_EMERGE = 209641, //Boss 03 Intro Emerge - hit npc 105766
//    SPELL_GAIN_ENERGY = 200086,
//    SPELL_PUTRID_SKIES = 198963,
//    SPELL_FRENZY = 199775,
//    SPELL_RANCID_MAW = 205549,
//    SPELL_TOXIC_WRETCH = 210150,
//    SPELL_TOXIC_WRETCH_AT = 210159,
//    SPELL_SPIKED_TONGUE_CHANNEL = 199178,
//    SPELL_SPIKED_TONGUE_CHECK_R = 199335, //Check Radius
//    SPELL_SPIKED_TONGUE_RIDE = 205417,
//    SPELL_SPIKED_TONGUE = 199176,
//    SPELL_SPIKED_TONGUE_AT = 199187,
//    SPELL_SPIKED_TONGUE_DMG = 199705,
//    SPELL_SPIKED_TONGUE_JUMP = 204136,
//    SPELL_RAVENOUS = 199246,
//    SPELL_DEVOUR_FANATIC = 216797,
//
//    //Heroic
//    SPELL_CALL_ANGRY_CROWD = 217028,
//
//    //Tresh
//    SPELL_JUMP_VISUAL = 184483,
//    SPELL_FANATICS_SACRIFICE = 209906,
//    SPELL_RANCID_MAW_ROOT = 205609, //Movement speed reduced by 80%.
//    SPELL_FANATIC_SACRIFICE = 209902,
//
//    SPELL_HURLING_ROCKS = 199245,
//};
//
//enum eEvents
//{
//    EVENT_RANCID_MAW = 1,
//    EVENT_TOXIC_WRETCH = 2,
//    EVENT_SUM_WORMSPEAKER = 3,
//
//    //Heroic
//    EVENT_CALL_ANGRY_CROWD = 4,
//
//    EVENT_1,
//    EVENT_2,
//};
//
//enum Misc
//{
//    DATA_ACHIEVEMENT,
//};
//
//Position const speakerPos[6] =
//{
//    {3045.07f, 1807.39f, -44.13f, 3.54f},
//    {3048.89f, 1799.60f, -45.43f, 3.35f},
//    {3033.45f, 1791.01f, -61.25f, 2.44f},
//    {3024.77f, 1802.29f, -60.10f, 2.44f},
//    {2995.22f, 1808.65f, -61.29f, 1.82f},
//    {3009.69f, 1826.31f, -60.35f, 3.08f}
//};
//
////91005
//struct boss_naraxas : public BossAI
//{
//    boss_naraxas(Creature* creature) : BossAI(creature, DATA_NARAXAS), summons(me)
//    {
//        SetCombatMovement(false);
//        me->SetMaxPower(POWER_MANA, 100);
//        DoCast(me, SPELL_INTRO_MYSTIC, true);
//    }
//
//    SummonList summons;
//    bool introDone = false;
//    bool introDone1 = false;
//    bool stacksdone = false;
//    uint8 berserkPct = 0;
//    uint16 checkMeleeTimer = 0;
//
//    void Reset() override
//    {
//        _Reset();
//        summons.DespawnAll();
//        me->RemoveAurasDueToSpell(SPELL_GAIN_ENERGY);
//        me->RemoveAurasDueToSpell(SPELL_FRENZY);
//        me->RemoveAurasDueToSpell(SPELL_RAVENOUS);
//        me->SetPower(POWER_MANA, 0);
//        stacksdone = false;
//        berserkPct = 21;
//        checkMeleeTimer = 2000;
//
//        if (auto sum = me->SummonCreature(NPC_ANGRY_CROWD, 3034.80f, 1815.17f, -32.28f))
//            sum->SetReactState(REACT_PASSIVE);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        DoCast(me, SPELL_GAIN_ENERGY, true);
//
//        events.RescheduleEvent(EVENT_RANCID_MAW, 8000);
//        events.RescheduleEvent(EVENT_TOXIC_WRETCH, 12000);
//        events.RescheduleEvent(EVENT_SUM_WORMSPEAKER, 7000);
//
//        //Heroic
//        events.RescheduleEvent(EVENT_CALL_ANGRY_CROWD, 4000); //?? ???????????
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        _DespawnAtEvade(15);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        _JustDied();
//        summons.DespawnAll();
//
//        if (auto target = me->FindNearestCreature(100700, 50, true))
//            target->CastSpell(target, 208691); //conversation
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        switch (type)
//        {
//        case DATA_ACHIEVEMENT:
//            return stacksdone ? 1 : 0;
//        }
//        return 0;
//    }
//
//    void MoveInLineOfSight(Unit* who) override
//    {
//        if (!who->IsPlayer())
//            return;
//
//        if (!introDone && me->IsWithinDistInMap(who, 115.0f))
//        {
//            who->CastSpell(who, 209582, true);
//            introDone = true;
//        }
//
//        if (!introDone1 && me->IsWithinDistInMap(who, 80.0f))
//        {
//            me->CastSpell(me, 209629, true);
//            me->RemoveAurasDueToSpell(SPELL_INTRO_MYSTIC);
//            if (Creature* target = me->FindNearestCreature(105766, 30, true))
//            {
//                me->CastSpell(target, SPELL_INTRO_EMERGE);
//                target->SetVisible(false);
//            }
//            introDone1 = true;
//        }
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (me->HealthBelowPct(berserkPct))
//        {
//            berserkPct = 0;
//            DoCast(me, SPELL_FRENZY, true);
//        }
//
//        if (damage >= me->GetHealth())
//        {
//            if (Aura const* aura = me->GetAura(SPELL_RAVENOUS))
//            {
//                if (aura->GetStackAmount() >= 6)
//                    stacksdone = true;
//            }
//        }
//    }
//
//    void SpellHit(Unit* caster, const SpellInfo* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SPELL_TOXIC_WRETCH:
//        {
//            Position pos;
//            float dist;
//            for (uint8 i = 0; i < 12; ++i)
//            {
//                dist = frand(10, 20);
//                me->GetNearPosition(dist, frand(-2.0f, 2.0f));
//                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_TOXIC_WRETCH_AT, true);
//            }
//            break;
//        }
//        case SPELL_FANATIC_SACRIFICE: //Trash Serach Boss
//            DoCast(caster, SPELL_DEVOUR_FANATIC);
//            break;
//        case SPELL_SPIKED_TONGUE:
//            DoCastVictim(SPELL_SPIKED_TONGUE_CHANNEL, true);
//            DoCast(me, SPELL_SPIKED_TONGUE_AT, true);
//            break;
//        }
//    }
//
//    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//    {
//        if (spell->Id == SPELL_CALL_ANGRY_CROWD)
//            target->CastSpell(target, SPELL_HURLING_ROCKS, true);
//
//        if (spell->Id == SPELL_SPIKED_TONGUE_CHECK_R) //Check Radius
//        {
//            if (me->IsInCombat() && me->GetDistance(target) <= 10.0f)
//            {
//                target->RemoveAurasDueToSpell(SPELL_SPIKED_TONGUE_CHANNEL);
//                me->RemoveDynObject(SPELL_SPIKED_TONGUE_AT);
//                DoCast(target, SPELL_SPIKED_TONGUE_RIDE, true);
//            }
//        }
//    }
//
//    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
//    {
//        if (!who || !me->IsInCombat() || !who->IsAlive())
//            return;
//
//        if (apply)
//        {
//            DoCast(who, SPELL_SPIKED_TONGUE_DMG, true);
//            me->CastSpell(me, SPELL_RAVENOUS, true);
//        }
//        else
//        {
//            if (!who->IsPlayer())
//                who->Kill(who,who);
//            else
//            {
//                Position pos = { 3013.55f + frand(-1.5f, 1.5f), 1807.02f + frand(-1.5f, 1.5f), -60.5f };
//                who->CastSpell(pos, SPELL_SPIKED_TONGUE_JUMP, true);
//            }
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
//        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_SPIKED_TONGUE_CHANNEL))
//            return;
//
//        if (checkMeleeTimer <= diff)
//        {
//            if (me->GetVictim())
//                if (!me->IsWithinMeleeRange(me->GetVictim()))
//                    DoCast(SPELL_PUTRID_SKIES);
//
//            checkMeleeTimer = 2000;
//        }
//        else
//            checkMeleeTimer -= diff;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_RANCID_MAW:
//                DoCast(SPELL_RANCID_MAW);
//                events.RescheduleEvent(EVENT_RANCID_MAW, 18000);
//                break;
//            case EVENT_TOXIC_WRETCH:
//                DoCast(SPELL_TOXIC_WRETCH);
//                events.RescheduleEvent(EVENT_TOXIC_WRETCH, 14000);
//                break;
//            case EVENT_SUM_WORMSPEAKER:
//                Talk(SAY_SUM);
//                for (uint8 i = 0; i < 2; ++i)
//                {
//                    if (auto sum = me->SummonCreature(NPC_WORMSPEAKER_DEVOUT, speakerPos[i]))
//                        sum->AI()->DoAction(i);
//                }
//                events.RescheduleEvent(EVENT_SUM_WORMSPEAKER, 64000);
//                break;
//            case EVENT_CALL_ANGRY_CROWD:
//                DoCast(SPELL_CALL_ANGRY_CROWD);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////101075
//struct npc_naraxas_wormspeaker_devout : public ScriptedAI
//{
//    npc_naraxas_wormspeaker_devout(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//    uint8 jumpIdx = 0;
//
//    void Reset() override
//    {
//        events.Reset();
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoZoneInCombat(me, 120.0f);
//        events.RescheduleEvent(EVENT_1, 1000);
//    }
//
//    void DoAction(int32 const actionId)
//    {
//        jumpIdx = actionId;
//        me->SetHomePosition(speakerPos[jumpIdx + 4]);
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == EFFECT_MOTION_TYPE)
//        {
//            if (id == 0)
//            {
//                me->RemoveAurasDueToSpell(SPELL_JUMP_VISUAL);
//                events.RescheduleEvent(EVENT_2, 1000);
//            }
//        }
//        if (type == POINT_MOTION_TYPE && id == 1)
//        {
//            me->GetMotionMaster()->Clear();
//
//            if (me->GetDistance(speakerPos[jumpIdx + 4]) > 3.0f)
//                events.RescheduleEvent(EVENT_2, 1000);
//            else
//                DoCast(me, SPELL_FANATICS_SACRIFICE, true);
//        }
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
//                DoCast(me, SPELL_JUMP_VISUAL, true);
//                me->GetMotionMaster()->MoveJump(speakerPos[jumpIdx + 2], 15.0f, 15.0f, 0);
//                break;
//            case EVENT_2:
//                me->GetMotionMaster()->MovePoint(1, speakerPos[jumpIdx + 4]);
//                break;
//            }
//        }
//    }
//};
//
////200086
//class spell_naraxas_gain_energy : public AuraScript
//{
//    PrepareAuraScript(spell_naraxas_gain_energy);
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        Unit* caster = GetCaster();
//        if (!caster)
//            return;
//
//        if (caster->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (caster->GetPower(POWER_MANA) >= 100)
//        {
//            caster->CastSpell(caster, SPELL_SPIKED_TONGUE);
//
//            if (Creature* target = caster->FindNearestCreature(91005, 50, true))
//                target->AI()->Talk(SAY_EMOTE);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_naraxas_gain_energy::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
//    }
//};
//
////
//class achievement_cant_eat_just_one : public AchievementCriteriaScript
//{
//public:
//    achievement_cant_eat_just_one() : AchievementCriteriaScript("achievement_cant_eat_just_one") { }
//
//    bool OnCheck(Player* /*player*/, Unit* target) override
//    {
//        if (!target)
//            return false;
//
//        if (Creature* boss = target->ToCreature())
//            if (boss->IsAIEnabled && (boss->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || boss->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE))
//                if (boss->AI()->GetData(DATA_ACHIEVEMENT))
//                    return true;
//
//        return false;
//    }
//};
//
//void AddSC_boss_naraxas()
//{
//    RegisterCreatureAI(boss_naraxas);
//    RegisterCreatureAI(npc_naraxas_wormspeaker_devout);
//    RegisterAuraScript(spell_naraxas_gain_energy);
//    new achievement_cant_eat_just_one();
//}

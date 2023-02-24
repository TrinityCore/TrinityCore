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
//#include "antorus.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_WAKE_OF_FLAME = 1,
//    SAY_WARN_TAESHALACH_TECHNIQUE = 2,
//    SAY_TAESHALACH_TECHNIQUE = 3,
//    SAY_PRE_PHASE_2 = 4,
//    SAY_PHASE_2 = 5,
//    SAY_FLARE = 6,
//    SAY_PRE_PHASE_3 = 7,
//    SAY_PHASE_3 = 8,
//    SAY_DEATH = 9,
//};
//
//enum Spells
//{
//    SPELL_OUTRO_CONV = 254315,
//    SPELL_ENABLE_ALTER_POWER = 243429, // "Flames Off"
//    SPELL_TAESHALACH_REACH = 243431, // Visual sword
//    SPELL_PERIODIC_ENERGY = 244792, // "Burning Will of Taeshalach"
//    SPELL_BERSERK = 26662,
//    SPELL_DAILY_ESSENCE_AGGRAMAR = 305316,
//
//    //Combo Events
//    SPELL_TAESHALACH_TECHNIQUE = 244688, // Cost energy
//    SPELL_FOE_BREAKER = 245458,
//    SPELL_FLAME_REND = 245463,
//    SPELL_FLAME_REND_DMG = 244033,
//    SPELL_FLAME_REND_JUMP = 244208,
//    SPELL_BURNING_RAGE = 244713,
//    SPELL_SEARING_TEMPEST = 245301,
//    SPELL_SEARING_TEMPEST_DMG = 246014,
//    SPELL_EMPOWERED_FOE_BREAKER = 255059, //> Mythic
//    SPELL_EMPOWERED_FOE_BREAKER_DUMMY = 255060,
//    SPELL_EMPOWERED_FLAME_REND = 255058,
//    SPELL_EMPOWERED_FLAME_REND_DMG = 247079,
//    SPELL_EMPOWERED_SEARING_TEMPEST = 255061,
//    SPELL_EMPOWERED_SEARING_TEMPEST_DMG = 255062,
//    SPELL_EMPOWERED_SEARING_TEMPEST_AT = 255063,
//    SPELL_SEARING_BINDING_STUN = 255528,
//    SPELL_SEARING_BINDING_EXPLOSION = 255530, //<
//
//    //Default events
//    SPELL_TAESHALACH_REACH_DMG = 244675,
//    SPELL_TAESHALACH_REACH_MOD = 245990,
//    SPELL_SCORCHING_BLAZE_FILTER = 245993,
//    SPELL_SCORCHING_BLAZE_AURA = 245994,
//    SPELL_SCORCHING_BLAZE_MARK = 246036,
//    SPELL_WAKE_OF_FLAME_DUMMY = 244693,
//    SPELL_WAKE_OF_FLAME_AT = 244718,
//    SPELL_WAKE_OF_FLAME_PERIODIC = 247158, //>Heroic+
//    SPELL_WAKE_OF_FLAME_FILTER = 254257, //<
//    SPELL_FLARE_FILTER = 245983,
//    SPELL_FLARE_MISSILE_1 = 245924,
//    SPELL_FLARE_DUMMY_1 = 244935, //12yard
//    SPELL_FLARE_MISSILE_2 = 245926,
//    SPELL_FLARE_DUMMY_2 = 244937, //15yard
//    SPELL_FLARE_MISSILE_3 = 245927,
//    SPELL_FLARE_DUMMY_3 = 244938, //18yard
//    SPELL_FLARE_DMG = 245391,
//    SPELL_EMPOWERED_FLARE_FILTER = 246037,
//    SPELL_EMPOWERED_FLARE_MISSILE_1 = 246051,
//    SPELL_EMPOWERED_FLARE_DUMMY_1 = 246054, //12yard
//    SPELL_EMPOWERED_FLARE_MISSILE_2 = 246052,
//    SPELL_EMPOWERED_FLARE_DUMMY_2 = 246055, //15yard
//    SPELL_EMPOWERED_FLARE_MISSILE_3 = 246053,
//    SPELL_EMPOWERED_FLARE_DUMMY_3 = 246056, //18yard
//    SPELL_EMPOWERED_FLARE_DMG = 245392,
//
//    SPELL_RAVENOUS_BLAZE_FILTER = 254451, //> Mythic
//    SPELL_RAVENOUS_BLAZE_FILTER_5M = 254458,
//    SPELL_RAVENOUS_BLAZE_FILTER_10M = 254459,
//    SPELL_RAVENOUS_BLAZE_FILTER_15M = 254460,
//    SPELL_RAVENOUS_BLAZE_FILTER_20M = 254461,
//    SPELL_CATALYZED = 247091,
//    SPELL_UNLEASHED_FLAME = 254329, //<
//
//    //Phase switch
//    SPELL_CORRUPT_AEGIS_AT = 244894,
//    SPELL_SUMMON_EMBER = 245056,
//    SPELL_SUMMON_EMBER_2 = 245057,
//    SPELL_SUMMON_FLAMES = 245582,
//    SPELL_WROUGHT_IN_FLAME = 245911, //Ember Taeshalach
//    SPELL_BLAZING_ERUPTION = 244912,
//    SPELL_REDUCE_PARRY_AND_BLOCK = 110470,
//    SPELL_MOLTEN_REMNANTS_AT = 245905, //Heroic+
//    SPELL_TAESHALACH_SPAWN_COSMETICS = 245088, //Flames Taeshalach
//    SPELL_CATALYZING_PRESENCE_AT = 244901,
//    SPELL_UNCHECKED_FLAME = 245631,
//    SPELL_METEOR_SWARM_AURA = 244678,
//    SPELL_METEOR_SWARM_SMALL_FILTER = 244680, //AOE 6yard
//    SPELL_METEOR_SWARM_SMALL_MISSILE = 245767,
//    SPELL_METEOR_SWARM_BIG_FILTER = 245919, //AOE 12yard
//    SPELL_METEOR_SWARM_BIG_MISSILE = 245920,
//};
//
//enum Events
//{
//    EVENT_COMBO = 1,
//    EVENT_SCORCHING_BLAZE = 2,
//    EVENT_WAKE_OF_FLAME = 3,
//    EVENT_PHASE_SWITCH = 4,
//    EVENT_FLARE = 5,
//    EVENT_EMPOWERED_FLARE = 6,
//
//    //Mythic
//    EVENT_RAVENOUS_BLAZE = 7,
//};
//
//enum Misc
//{
//    PHASE_1 = 0,
//    PHASE_2 = 1,
//    PHASE_3 = 2
//};
//
//enum Miscs
//{
//    ACTION_1 = 1,
//};
//
//Position const outroPos[4] =
//{
//    {-12646.00f, -2292.10f, 2514.26f, 1.44f},
//    {-12639.39f, -2293.25f, 2514.26f, 1.44f},
//    {-12630.38f, -2293.25f, 2514.26f, 1.60f},
//    {-12621.95f, -2293.79f, 2514.26f, 1.66f}
//};
//
//Position const centrPos = { -12634.27f, -2254.4f, 2514.26f };
//
//uint32 const entryOutro[4] = { 128169, 129876, 125683, 125682 };
//
////121975
//struct boss_aggramar : BossAI
//{
//    boss_aggramar(Creature* creature) : BossAI(creature, DATA_AGGRAMAR)
//    {
//       /* if (IsLFR())
//            comboSpell[0] = { SPELL_FLAME_REND, SPELL_FLAME_REND, SPELL_FLAME_REND, SPELL_FLAME_REND, SPELL_SEARING_TEMPEST };
//        else if (IsNormalRaid() || IsHeroicRaid())
//            comboSpell[0] = { SPELL_FOE_BREAKER, SPELL_FLAME_REND, SPELL_FOE_BREAKER, SPELL_FLAME_REND, SPELL_SEARING_TEMPEST };
//        else if (IsMythicRaid())
//        {
//            comboSpell[0] = { SPELL_FLAME_REND,  SPELL_FOE_BREAKER,     SPELL_FOE_BREAKER,     SPELL_SEARING_TEMPEST, SPELL_FLAME_REND };
//            comboSpell[1] = { SPELL_FLAME_REND,  SPELL_SEARING_TEMPEST, SPELL_FOE_BREAKER,     SPELL_FOE_BREAKER,     SPELL_FLAME_REND };
//            comboSpell[2] = { SPELL_FOE_BREAKER, SPELL_FLAME_REND,      SPELL_SEARING_TEMPEST, SPELL_FOE_BREAKER,     SPELL_FLAME_REND };
//            comboSpell[3] = { SPELL_FOE_BREAKER, SPELL_SEARING_TEMPEST, SPELL_FLAME_REND,      SPELL_FOE_BREAKER,     SPELL_FLAME_REND };
//        }*///tmp
//    }
//
//    std::vector<uint32> comboSpell[4];
//    uint8 comboCounter = 0;
//    uint8 comboRand = 0;
//    uint8 healthPct = 0;
//    uint8 flamesCount = 0;
//    uint8 phase = 0;
//    uint32 berserkTimer = 0;
//
//    void Reset() override
//    {
//        //me->SetPower(me->GetPowerType(), IsMythicRaid() ? 60 : 0);
//        me->SetReactState(REACT_AGGRESSIVE);
//        DoCast(me, SPELL_ENABLE_ALTER_POWER, true);
//        DoCast(me, SPELL_TAESHALACH_REACH, true);
//        healthPct = 81;
//        flamesCount = 0;
//        berserkTimer = 0;
//        phase = PHASE_1;
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        Talk(SAY_AGGRO);
//        DefaultEvents();
//
//        //if (IsMythicRaid())
//        //    berserkTimer = 540 * IN_MILLISECONDS;//tmp
//    }
//
//    void DefaultEvents(bool nextPhase = false)
//    {
//        if (nextPhase)
//            ++phase;
//
//        DoCast(me, SPELL_PERIODIC_ENERGY, true);
//
//        //switch (phase)
//        //{
//        //case PHASE_1:
//        //    if (IsMythicRaid())
//        //    {
//        //        events.RescheduleEvent(EVENT_RAVENOUS_BLAZE, 4000);
//        //        events.RescheduleEvent(EVENT_WAKE_OF_FLAME, 11000);
//        //    }
//        //    else
//        //    {
//        //        events.RescheduleEvent(EVENT_SCORCHING_BLAZE, 5500);
//        //        events.RescheduleEvent(EVENT_WAKE_OF_FLAME, 6000);
//        //    }
//        //    break;
//        //case PHASE_2:
//        //    if (IsMythicRaid())
//        //        events.RescheduleEvent(EVENT_RAVENOUS_BLAZE, 23000);
//        //    else
//        //        events.RescheduleEvent(EVENT_SCORCHING_BLAZE, 6000);
//        //    events.RescheduleEvent(EVENT_FLARE, 10000);
//        //    break;
//        //case PHASE_3:
//        //    if (IsMythicRaid())
//        //        events.RescheduleEvent(EVENT_RAVENOUS_BLAZE, 23000);
//        //    else
//        //        events.RescheduleEvent(EVENT_SCORCHING_BLAZE, 6000);
//        //    events.RescheduleEvent(EVENT_EMPOWERED_FLARE, 10000);
//        //    break;
//        //}//tmp
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//
//        Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
//        for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
//            if (Player* player = i->GetSource())
//                player->CastSpell(player, SPELL_DAILY_ESSENCE_AGGRAMAR, true);
//
//        AddDelayedEvent(3000, [this]() -> void
//        {
//            for (uint8 i = 0; i < 4; ++i)
//                me->SummonCreature(entryOutro[i], outroPos[i]);
//
//            AddDelayedEvent(1000, [this]() -> void
//            {
//                me->CastSpell(me, SPELL_OUTRO_CONV, true);
//            });
//        });
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//
//        if (summon->GetEntry() == NPC_FLAME_OF_TAESHALACH)
//        {
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
//            ++flamesCount;
//        }
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//    {
//        if (summon->GetEntry() == NPC_FLAME_OF_TAESHALACH)
//        {
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
//
//            if (--flamesCount == 0)
//            {
//                Talk(phase == PHASE_1 ? SAY_PHASE_2 : SAY_PHASE_3);
//                me->RemoveAurasDueToSpell(SPELL_CORRUPT_AEGIS_AT);
//                me->SetReactState(REACT_AGGRESSIVE);
//                DefaultEvents(true);
//            }
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//        case SPELL_TAESHALACH_TECHNIQUE:
//            Talk(SAY_WARN_TAESHALACH_TECHNIQUE);
//            Talk(SAY_TAESHALACH_TECHNIQUE);
//            events.Reset();
//            comboCounter = 0;
//           /* comboRand = IsMythicRaid() ? urand(0, 3) : 0;
//            events.RescheduleEvent(EVENT_COMBO, 100);*///tmp
//            break;
//        case SPELL_FLAME_REND:
//            me->CastSpell(me->GetVictim(), SPELL_FLAME_REND_DMG, true);
//            break;
//        case SPELL_EMPOWERED_FLAME_REND:
//            me->CastSpell(me->GetVictim(), SPELL_EMPOWERED_FLAME_REND_DMG, true);
//            break;
//        case SPELL_EMPOWERED_FOE_BREAKER:
//            me->CastSpell(me->GetVictim(), SPELL_EMPOWERED_FOE_BREAKER_DUMMY, true);
//            break;
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) 
//    {
//        switch (spell->Id)
//        {
//        case SPELL_TAESHALACH_REACH_DMG:
//            DoCast(target, SPELL_TAESHALACH_REACH_MOD, true);
//            break;
//        case SPELL_WAKE_OF_FLAME_DUMMY:
//        {
//            Position pos;
//            float angle = me->GetRelativeAngle(target) - 1.57f;
//            for (uint8 i = 0; i < 3; ++i)
//            {
//                me->GetNearPosition(5.0f, angle);
//                //pos.m_orientation = me->GetAngle(pos.GetPositionX(), pos.GetPositionY());
//                me->CastSpell(pos, SPELL_WAKE_OF_FLAME_AT, true);
//                angle += 1.57f;
//            }
//            break;
//        }
//        case SPELL_FLARE_DUMMY_1:
//        case SPELL_FLARE_DUMMY_2:
//        case SPELL_FLARE_DUMMY_3:
//            if (target->IsPlayer())
//                me->CastSpell(target, SPELL_FLARE_DMG, true);
//            //else if (IsMythicRaid() && target->GetEntry() == NPC_EMBER_OF_TAESHALACH)
//            //    target->CastSpell(target, SPELL_CATALYZED, true);////tmp
//            break;
//        case SPELL_EMPOWERED_FLARE_DUMMY_1:
//        case SPELL_EMPOWERED_FLARE_DUMMY_2:
//        case SPELL_EMPOWERED_FLARE_DUMMY_3:
//            if (target->IsPlayer())
//                me->CastSpell(target, SPELL_EMPOWERED_FLARE_DMG, true);
//            break;
//        case SPELL_WAKE_OF_FLAME_FILTER:
//        {
//            Position pos;
//            me->GetNearPosition(5.0f, me->GetRelativeAngle(target));
//            //pos.m_orientation = me->GetAngle(pos.GetPositionX(), pos.GetPositionY());
//            me->CastSpell(pos, SPELL_WAKE_OF_FLAME_AT, true);
//            break;
//        }
//        case SPELL_SEARING_TEMPEST:
//            if (target->IsPlayer())
//                me->CastSpell(target, SPELL_SEARING_TEMPEST_DMG, true);
//            //else if (IsMythicRaid() && target->GetEntry() == NPC_EMBER_OF_TAESHALACH)
//            //    target->CastSpell(target, SPELL_CATALYZED, true);//tmp
//            break;
//        case SPELL_EMPOWERED_SEARING_TEMPEST:
//            if (target->IsPlayer())
//                me->CastSpell(target, SPELL_EMPOWERED_SEARING_TEMPEST_DMG, true);
//            //else if (IsMythicRaid() && target->GetEntry() == NPC_EMBER_OF_TAESHALACH)
//            //    target->CastSpell(target, SPELL_CATALYZED, true);//tmp
//            break;
//        case SPELL_EMPOWERED_FOE_BREAKER:
//            if (target->IsPlayer())
//                me->CastSpell(target, SPELL_SEARING_BINDING_STUN, true);
//            break;
//        }
//    }
//
//    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
//    {
//        if (!me->IsInCombat() || mode != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (spellId == SPELL_SEARING_BINDING_STUN)
//            target->CastSpell(target, SPELL_SEARING_BINDING_EXPLOSION, true);
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (me->HealthBelowPct(healthPct))
//
//        {
//            healthPct = healthPct == 81 ? 41 : 0;
//            events.Reset();
//            //events.RescheduleEvent(EVENT_PHASE_SWITCH, 100);//tmp
//            me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGY);
//            me->SetPower(POWER_ENERGY, 0);
//        }
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == POINT_MOTION_TYPE && id == 1)
//        {
//            Talk(phase == PHASE_1 ? SAY_PRE_PHASE_2 : SAY_PRE_PHASE_3);
//            me->CastSpell(me, SPELL_CORRUPT_AEGIS_AT, true);
//
// /*           if (phase == PHASE_2 || IsHeroicPlusRaid())
//                me->CastSpell(me, SPELL_METEOR_SWARM_AURA, true);*///tmp
//
//            //if (IsHeroicPlusRaid() && phase == PHASE_2)
//            //    me->CastSpell(me, SPELL_WAKE_OF_FLAME_PERIODIC, true);
//            //tmp
//            Position pos;
//            float angle = 0.0f;
//            uint32 delay = 100;
//
//            for (uint8 i = 0; i < 6; ++i)
//            {
//                me->GetNearPosition(50.0f, angle);
//                me->CastSpell(pos, SPELL_SUMMON_EMBER, true);
//                angle += 1.046f;
//            }
//
//            angle = -1.57f;
//
//            for (uint8 i = 0; i < 2; ++i)
//            {
//                me->GetNearPosition(15.0f, angle);
//                me->CastSpell(pos, SPELL_SUMMON_FLAMES, true);
//                angle += 3.14f;
//            }
//        }
//    }
//
//    uint32 GetCombatSpell()
//    {
//        uint32 spellId = comboSpell[comboRand][comboCounter++];
//
//        //if (!IsMythicRaid())
//        //    return spellId;//tmp
//
//        switch (spellId)
//        {
//        case SPELL_FLAME_REND:
//            return SPELL_EMPOWERED_FLAME_REND;
//        case SPELL_FOE_BREAKER:
//            return phase == PHASE_3 ? SPELL_EMPOWERED_FOE_BREAKER : spellId;
//        case SPELL_SEARING_TEMPEST:
//        {
//            if (phase == PHASE_1)
//                return spellId;
//
//            me->CastSpell(me, SPELL_EMPOWERED_SEARING_TEMPEST_AT, true);
//            return SPELL_EMPOWERED_SEARING_TEMPEST;
//        }
//        default:
//            return spellId;
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
//        if (berserkTimer)
//        {
//            if (berserkTimer <= diff)
//            {
//                berserkTimer = 0;
//                me->CastSpell(me, SPELL_BERSERK, true);
//            }
//            else
//                berserkTimer -= diff;
//        }
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_COMBO:
//                if (comboCounter == 5)
//                {
//                    DefaultEvents();
//                    break;
//                }
//                me->CastSpell(me, GetCombatSpell());
//                //events.RescheduleEvent(EVENT_COMBO, IsMythicRaid() ? 3500 : 5000);//tmp
//                break;
//            case EVENT_SCORCHING_BLAZE:
//                DoCast(SPELL_SCORCHING_BLAZE_FILTER);
//                //events.RescheduleEvent(EVENT_SCORCHING_BLAZE, 6500);//tmp
//                break;
//            case EVENT_WAKE_OF_FLAME:
//                Talk(SAY_WAKE_OF_FLAME);
//                me->CastSpell(me->GetVictim(), SPELL_WAKE_OF_FLAME_DUMMY);
//                //events.RescheduleEvent(EVENT_WAKE_OF_FLAME, 24000);//tmp
//                break;
//            case EVENT_PHASE_SWITCH:
//                me->AttackStop();
//                me->GetMotionMaster()->MovePoint(1, centrPos);
//                break;
//            case EVENT_FLARE:
//                Talk(SAY_FLARE);
//                DoCast(SPELL_FLARE_FILTER);
//                //if (!IsMythicRaid())
//                //    events.RescheduleEvent(EVENT_FLARE, 15000);//tmp
//                break;
//            case EVENT_EMPOWERED_FLARE:
//                Talk(SAY_FLARE);
//                DoCast(SPELL_EMPOWERED_FLARE_FILTER);
//                //if (!IsMythicRaid())
//                //    events.RescheduleEvent(EVENT_EMPOWERED_FLARE, 15000);//tmp
//                break;
//            case EVENT_RAVENOUS_BLAZE:
//                DoCast(SPELL_RAVENOUS_BLAZE_FILTER);
//                //events.RescheduleEvent(EVENT_RAVENOUS_BLAZE, 22000);//tmp
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////122532
//struct npc_aggramar_ember_of_taeshalach : ScriptedAI
//{
//    explicit npc_aggramar_ember_of_taeshalach(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//    }
//
//    bool eruption = false;
//    bool moltenRemnants = false;
//    uint32 moveTimer = 0;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        moveTimer = 1000;
//        me->SetPower(POWER_ENERGY, 0);
//        DoZoneInCombat(me, 100.0f);
//        DoCast(me, SPELL_REDUCE_PARRY_AND_BLOCK, true);
//        DoCast(me, SPELL_WROUGHT_IN_FLAME, true);
//    }
//
//    void Reset() override {}
//
//    void DoAction(int32 const actionId)
//    {
//        if (eruption)
//            return;
//
//        if (actionId == ACTION_1)
//        {
//            eruption = true;
//            moveTimer = 0;
//
//            if (auto owner = me->GetOwner())
//                me->CastSpell(me, SPELL_BLAZING_ERUPTION, true);
//
//            me->StopMoving();
//            AddDelayedEvent(500, [this]() -> void { me->DespawnOrUnsummon(); });
//        }
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        //if (IsHeroicPlusRaid() && damage >= me->GetHealth())
//        //{
//        //    damage = 0;
//
//        //    if (!moltenRemnants && !eruption)
//        //    {
//        //        moltenRemnants = true;
//        //        moveTimer = 0;
//        //        me->StopMoving();
//        //        me->CastSpell(me, SPELL_MOLTEN_REMNANTS_AT, true);
//        //        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
//        //        me->SetHealth(me->GetMaxHealth());
//        //    }
//        //}
//    }//tmp
//
//    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//    {
//        if (apply)
//            return;
//
//        if (spellId == SPELL_MOLTEN_REMNANTS_AT)
//        {
//            moveTimer = 1000;
//            moltenRemnants = false;
//            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
//        }
//
//        if (spellId == SPELL_CATALYZED && mode == AURA_REMOVE_BY_ENEMY_SPELL)
//            me->CastSpell(me, SPELL_UNLEASHED_FLAME, true);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (moveTimer)
//        {
//            if (moveTimer <= diff)
//            {
//                moveTimer = 500;
//
//                if (auto owner = me->GetOwner())
//                {
//                    if (me->GetExactDist2d(owner) <= 10.0f)
//                    {
//                        DoAction(ACTION_1);
//                        return;
//                    }
//                }
//            }
//            else
//                moveTimer -= diff;
//        }
//    }
//};
//
////121985
//struct npc_aggramar_flame_of_taeshalach : ScriptedAI
//{
//    explicit npc_aggramar_flame_of_taeshalach(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoZoneInCombat(me, 100.0f);
//        me->SetReactState(REACT_AGGRESSIVE);
//        DoCast(me, SPELL_TAESHALACH_SPAWN_COSMETICS, true);
//        DoCast(me, SPELL_CATALYZING_PRESENCE_AT, true);
//        DoCast(me, SPELL_UNCHECKED_FLAME, true);
//    }
//
//    void Reset() override {}
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        DoMeleeAttackIfReady();
//    }
//};
//
////244792
//class spell_aggramar_energize_periodic : public AuraScript
//{
//    PrepareAuraScript(spell_aggramar_energize_periodic);
//
//    uint8 tickCount = 0;
//    uint8 powerCount = 0;
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        auto caster = GetCaster();
//        if (!caster || !caster->IsInCombat())
//            return;
//
//        powerCount = caster->GetPower(caster->GetPowerType());
//
//        if (powerCount == 0 || powerCount == 20 || powerCount == 40 || powerCount == 57 || powerCount == 80)
//            tickCount = 2;
//        else
//            tickCount = 3;
//
//        if (powerCount < 100)
//            caster->SetPower(caster->GetPowerType(), powerCount + tickCount);
//        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
//        {
//            caster->CastSpell(caster, SPELL_TAESHALACH_TECHNIQUE);
//            aurEff->GetBase()->Remove();
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_aggramar_energize_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////245911
//class spell_aggramar_wrought_in_flame : public AuraScript
//{
//    PrepareAuraScript(spell_aggramar_wrought_in_flame);
//
//    float powerCount = 0.0f;
//    float tickCount = 0.0f;
//    float scaleSize = 0.0f;
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        tickCount = float(aurEff->GetAmount() * 0.01f);
//    }
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        auto caster = GetCaster();
//        if (!caster)
//            return;
//
//        powerCount += tickCount;
//
//        if (powerCount < 100.0f)
//        {
//            caster->SetPower(caster->GetPowerType(), powerCount);
//
//            if (auto _aurEff = GetAura()->GetEffect(EFFECT_3))
//                _aurEff->ChangeAmount(++scaleSize);
//        }
//        else
//            caster->GetAI()->DoAction(ACTION_1);
//    }
//
//    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
//    {
//        amount = -1;
//    }
//
//    void Register() override
//    {
//        OnEffectApply += AuraEffectApplyFn(spell_aggramar_wrought_in_flame::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_aggramar_wrought_in_flame::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_aggramar_wrought_in_flame::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
//    }
//};
//
////244678
//class spell_aggramar_meteor_swarm : public AuraScript
//{
//    PrepareAuraScript(spell_aggramar_meteor_swarm);
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (!GetCaster())
//            return;
//
//        if (aurEff->GetTickNumber() % 3)
//            GetCaster()->CastSpell(GetCaster(), SPELL_METEOR_SWARM_SMALL_FILTER, true);
//        else
//            GetCaster()->CastSpell(GetCaster(), SPELL_METEOR_SWARM_BIG_FILTER, true);
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_aggramar_meteor_swarm::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////254452
//class spell_aggramar_ravenous_blaze : public AuraScript
//{
//    PrepareAuraScript(spell_aggramar_ravenous_blaze);
//
//    uint8 counter = 0;
//    uint32 spellId[4] = { SPELL_RAVENOUS_BLAZE_FILTER_5M, SPELL_RAVENOUS_BLAZE_FILTER_10M, SPELL_RAVENOUS_BLAZE_FILTER_15M, SPELL_RAVENOUS_BLAZE_FILTER_20M };
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (!GetTarget())
//            return;
//
//        if (!(aurEff->GetTickNumber() % 4))
//            GetTarget()->CastSpell(GetTarget(), spellId[counter++], true);
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_aggramar_ravenous_blaze::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////245458, 255059
//class spell_aggramar_foe_breaker_filter : public SpellScript
//{
//    PrepareSpellScript(spell_aggramar_foe_breaker_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        targets.remove_if([this](WorldObject* object) -> bool
//        {
//            if (object == nullptr || !object->IsPlayer())
//                return true;
//
//            if (GetCaster()->isInBack(object))
//                return true;
//
//            return false;
//        });
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aggramar_foe_breaker_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////244033, 247079
//class spell_aggramar_flame_rend_filter : public SpellScript
//{
//    PrepareSpellScript(spell_aggramar_flame_rend_filter);
//
//    float jumpPct = 1.0f;
//    float playerMod = 1.0f;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        uint32 playersCount = GetCaster()->GetMap()->GetPlayersCountExceptGMs();
//
//        if (playersCount > 10)
//            playerMod = float(playersCount * 0.1f);
//
//        jumpPct = 100.0f - float(targets.size() / playersCount) * 100.0f;
//
//        if (jumpPct >= 75.0f) // targets <= 25% players = cast buff
//            GetCaster()->CastSpell(GetCaster(), SPELL_BURNING_RAGE, true);
//        else if (jumpPct < 25.0f)
//            jumpPct = 25.0f;
//    }
//
//    void HandleDamage(SpellEffIndex effIndex)
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        SetHitDamage(GetHitDamage() * playerMod);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aggramar_flame_rend_filter::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
//        OnEffectHitTarget += SpellEffectFn(spell_aggramar_flame_rend_filter::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////245993
//class spell_aggramar_scorching_blaze_filter : public SpellScript
//{
//    PrepareSpellScript(spell_aggramar_scorching_blaze_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        targets.remove_if([this](WorldObject* object) -> bool
//        {
//            if (object == nullptr || !object->IsPlayer())
//                return true;
//
//            if (object->ToPlayer()->HasAura(SPELL_SCORCHING_BLAZE_MARK))
//                return true;
//
//            return false;
//        });
//
//        uint32 playerCount = GetCaster()->GetMap()->GetPlayersCountExceptGMs();
//
//       /* if (playerCount <= 10)
//            Trinity::Containers::RandomResize(targets, 3);
//        else if (playerCount <= 13)
//            Trinity::Containers::RandomResize(targets, 4);
//        else if (playerCount <= 16)
//            Trinity::Containers::RandomResize(targets, 5);
//        else if (playerCount <= 20)
//            Trinity::Containers::RandomResize(targets, 6);
//        else if (playerCount <= 24)
//            Trinity::Containers::RandomResize(targets, 7);
//        else if (playerCount <= 26)
//            Trinity::Containers::RandomResize(targets, 8);
//        else if (playerCount <= 30)
//            Trinity::Containers::RandomResize(targets, 9);*///tmp
//
//        for (auto object : targets)
//        {
//            GetCaster()->CastSpell(object->ToUnit(), SPELL_SCORCHING_BLAZE_MARK, true);
//            GetCaster()->CastSpell(object->ToUnit(), SPELL_SCORCHING_BLAZE_AURA, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aggramar_scorching_blaze_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////245983, 246037
//class spell_aggramar_flare_filter : public SpellScript
//{
//    PrepareSpellScript(spell_aggramar_flare_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        targets.remove_if([this](WorldObject* object) -> bool
//        {
//            if (object == nullptr || !object->IsPlayer())
//                return true;
//
//            return false;
//        });
//
//        Trinity::Containers::RandomResize(targets, 3);
//
//        uint8 counter = 0;
//        uint32 spellFlare[2][3] =
//        {
//            {SPELL_FLARE_MISSILE_1, SPELL_FLARE_MISSILE_2, SPELL_FLARE_MISSILE_3},
//            {SPELL_EMPOWERED_FLARE_MISSILE_1, SPELL_EMPOWERED_FLARE_MISSILE_2, SPELL_EMPOWERED_FLARE_MISSILE_3}
//        };
//        uint32 delay = 0;
//
//        for (auto object : targets)
//        {
//            GetCaster()->CastSpell(object->ToUnit(), SPELL_EMPOWERED_FLARE_FILTER, true);
//            delay += 750;
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_aggramar_flare_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////246054, 246055, 246056
//class spell_aggramar_command_empowered_flare : public SpellScript
//{
//    PrepareSpellScript(spell_aggramar_command_empowered_flare);
//
//    void HandleScript(SpellEffIndex /*effectIndex*/)
//    {
//        if (!GetCaster() || !GetHitDest())
//            return;
//
//        uint8 maxCount = 3;
//
//        if (GetCaster()->GetMap()->IsMythic())
//        {
//            maxCount = 5;
//            GetCaster()->CastSpell(GetCaster()->GetPosition(), SPELL_SUMMON_EMBER_2, true);
//        }
//
//        Position pos;
//        float angle = 0.0f;
//        for (uint8 i = 0; i < maxCount; ++i)
//        {
//            //GetHitDest()->SimplePosXYRelocationByAngle(pos, 5.0f, angle);
//            //pos.m_orientation = GetHitDest()->GetAngle(pos.GetPositionX(), pos.GetPositionY());
//            GetCaster()->CastSpell(pos, SPELL_WAKE_OF_FLAME_AT, true);
//            angle += 6.28f / maxCount;
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectLaunch += SpellEffectFn(spell_aggramar_command_empowered_flare::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
//    }
//};
////void AddSC_boss_aggramar()
//void AddSC_boss_aggramar()
//{
//    RegisterCreatureAI(boss_aggramar);
//    RegisterCreatureAI(npc_aggramar_ember_of_taeshalach);
//    RegisterCreatureAI(npc_aggramar_flame_of_taeshalach);
//    //RegisterAuraScript(spell_aggramar_energize_periodic);
//    //RegisterAuraScript(spell_aggramar_wrought_in_flame);
//    //RegisterAuraScript(spell_aggramar_meteor_swarm);
//    //RegisterAuraScript(spell_aggramar_ravenous_blaze);//tmp
//    RegisterSpellScript(spell_aggramar_foe_breaker_filter);
//    RegisterSpellScript(spell_aggramar_flame_rend_filter);
//    RegisterSpellScript(spell_aggramar_scorching_blaze_filter);
//    RegisterSpellScript(spell_aggramar_flare_filter);
//    RegisterSpellScript(spell_aggramar_command_empowered_flare);
//}

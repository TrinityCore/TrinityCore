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
//#include "GameObject.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_WARN_SLEEP_CANISTER = 1,
//    SAY_SLEEP_CANISTER = 2,
//    SAY_CHARGED_BLASTS = 3,
//    SAY_EMPOWERED_SHRAPNEL_BLAST = 4,
//    SAY_SWITCH_PHASE_1 = 5,
//    SAY_SWITCH_PHASE_2 = 6,
//    SAY_SWITCH_PHASE_3 = 7,
//    SAY_SWITCH_PHASE_4 = 8,
//    SAY_DEATH = 9,
//};
//
//enum Spells
//{
//    SPELL_OUTRO_CONV = 251475,
//    SPELL_SPAWN_VISUAL = 249569,
//    SPELL_INFERNAL_ROCKETS_1 = 248252,
//    SPELL_INFERNAL_ROCKETS_2 = 248255,
//    SPELL_BERSERK = 26662,
//    SPELL_DAILY_ESSENCE_IMONAR = 305312,
//
//    //Phase 1
//    SPELL_SHOCK_LANCE = 247367,
//    SPELL_SLEEP_CANISTER_FILTER = 254244,
//    SPELL_SLEEP_CANISTER_MARK = 255029,
//    SPELL_SLUMBER_GAS_STUN = 247565,
//    SPELL_PULSE_GRENADE = 247376,
//    SPELL_PULSE_GRENADE_FILTER_1 = 247373,
//    SPELL_PULSE_GRENADE_FILTER_2 = 247375,
//    SPELL_PULSE_GRENADE_SUMMON = 247381,
//    SPELL_PULSE_GRENADE_AT = 247397,
//    SPELL_SHOCKED = 250224,
//
//    //Phase 2
//    SPELL_SEVER = 247687,
//    SPELL_SHRAPNEL_BLAST = 247923,
//    SPELL_SHRAPNEL_BLAST_AT = 247939,
//    SPELL_CHARGED_BLASTS = 248254,
//    SPELL_CHARGED_BLASTS_AT = 247707, //>Ship casts
//    SPELL_CHARGED_BLASTS_FILTER = 247711,
//    SPELL_CHARGED_BLASTS_MARK = 247704, //Target Mark
//    SPELL_CHARGED_BLASTS_DUMMY = 247727, //unk
//    SPELL_CHARGED_BLASTS_DUMMY_MARK = 248968, //Hide untarget mark
//    SPELL_CHARGED_BLASTS_SCALE = 257197, // Mod Size Player
//    SPELL_CHARGED_BLASTS_DMG = 247716,
//    SPELL_SHIP_SPAWN_VISUAL = 251446, //<
//
//    //Phase 3
//    SPELL_EMPOWERED_SHOCK_LANCE = 250255,
//    SPELL_EMPOWERED_PULSE_GRENADE = 248068,
//    SPELL_EMPOWERED_SHRAPNEL_BLAST = 248070,
//    SPELL_SHIP_SHRAPNEL_BLAST = 248076, //>Ship casts
//    SPELL_SHIP_SHRAPNEL_BLAST_MISSILE_1 = 248077,
//    SPELL_SHIP_SHRAPNEL_BLAST_MISSILE_2 = 248080, //<
//
//    //Change phase 1
//    SPELL_P1_JETPACKS = 248995,
//    SPELL_P1_PULSE_GRENADE_FILTER = 248223,
//    SPELL_P1_PULSE_GRENADE_AT = 247668,
//    SPELL_P1_PULSE_GRENADE_KNOCK = 250002,
//    SPELL_P1_STASIS_TRAP_FILTER = 248224,
//    SPELL_P1_STASIS_TRAP_AT = 247637,
//    SPELL_P1_INFERNAL_LANDING = 255472,
//    SPELL_P1_CONFLAGRATION = 248233,
//    SPELL_P1_CONFLAGRATION_FILTER = 248313,
//    SPELL_P1_P2_CONFLAGRATION_DUMMY = 248315,
//    SPELL_P1_CONFLAGRATION_AT = 248208,
//
//    //Change phase 2
//    SPELL_P2_JETPACKS = 248194,
//    SPELL_P2_BLASTWIRE_FILTER = 248237,
//    SPELL_P2_BLASTWIRE_AT = 247955,
//    SPELL_P2_SHRAPNEL_FILTER = 248238,
//    SPELL_P2_SHRAPNEL_AT = 247944,
//    SPELL_P2_CONFLAGRATION = 250135,
//    SPELL_P2_CONFLAGRATION_FILTER = 250136,
//    SPELL_P2_CONFLAGRATION_AT = 250138,
//    SPELL_P2_INFERNAL_LANDING = 248250,
//};
//
//enum Events
//{
//    //Phase 1
//    EVENT_SHOCK_LANCE = 1,
//    EVENT_SLEEP_CANISTER = 2,
//    EVENT_PULSE_GRENADE = 3,
//
//    //Phase 2
//    EVENT_SEVER = 4,
//    EVENT_SHRAPNEL_BLAST = 5,
//    EVENT_CHARGED_BLASTS = 6,
//
//    //Phase 3
//    EVENT_EMPOWERED_SHOCK_LANCE = 7,
//    EVENT_EMPOWERED_PULSE_GRENADE = 8,
//    EVENT_EMPOWERED_SHRAPNEL_BLAST = 9,
//};
//
//enum Misc
//{
//    PHASE_1 = 0,
//    PHASE_2,
//    PHASE_3,
//    PHASE_4,
//    PHASE_5,
//
//    PATH_CHANGE_PHASE_FIRST = 12415800,
//    PATH_CHANGE_PHASE_SECOND = 12415801,
//};
//
//Position const centrPlatformPos[2] =
//{
//    {-10574.5f, 8723.3f, 1871.56f},
//    {-10575.8f, 8538.3f, 1871.53f}
//};
//
//Position const bFirePos[9] =
//{
//    {-10561.67f, 8664.34f, 1878.7f, 1.36f}, //Left
//    {-10554.88f, 8641.35f, 1878.7f, 2.33f},
//    {-10560.06f, 8630.49f, 1878.7f, 1.53f},
//    {-10560.54f, 8600.84f, 1878.8f, 1.57f},
//    {-10560.57f, 8595.66f, 1878.8f, 1.57f},
//    {-10588.57f, 8595.09f, 1878.7f, 1.57f}, //Right
//    {-10589.34f, 8652.25f, 1878.7f, 1.58f},
//    {-10588.86f, 8624.69f, 1878.7f, 1.58f},
//    {-10588.45f, 8664.40f, 1878.7f, 1.58f}
//};
//
//Position const bigShipPos[2] =
//{
//    {-10533.5f, 8757.92f, 1892.45f, 4.14f},
//    {-10616.6f, 8708.64f, 1904.49f, 0.57f},
//};
//
//std::list<Position> smallShipPos =
//{
//    {-10627.9f, 8495.83f, 1878.13f, 0.64f},
//    {-10625.3f, 8535.34f, 1878.15f, 0.01f},
//    {-10621.7f, 8571.31f, 1878.13f, 5.63f},
//    {-10538.6f, 8499.77f, 1878.13f, 2.35f},
//    {-10531.3f, 8555.84f, 1878.13f, 3.56f}
//};
//
////124158
//struct boss_imonar : BossAI
//{
//    boss_imonar(Creature* creature) : BossAI(creature, DATA_IMONAR) {}
//
//    ObjectGuid teleporterGUID;
//    bool switchPhase = false;
//    uint8 curPlatformId = 0;
//    uint8 phase = 0;
//    uint8 healthPct = 0;
//    uint32 infernalTimer = 0;
//    uint32 conflagrationTimer = 0;
//    uint32 berserkTimer = 0;
//
//    void Reset() override
//    {
//        _Reset();
//        switchPhase = false;
//        phase = 0;
//        infernalTimer = 0;
//        healthPct = IsMythicRaid() ? 81 : 67;
//        curPlatformId = 0;
//        berserkTimer = 0;
//        me->SetReactState(REACT_AGGRESSIVE);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        Talk(SAY_AGGRO);
//        DefaultEvent();
//        infernalTimer = 2000;
//        SetVisibleTeleporter(false);
//
//        if (IsMythicRaid())
//            berserkTimer = 480 * IN_MILLISECONDS;
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        BossAI::EnterEvadeMode();
//        me->SetCanFly(false);
//        me->StopMoving();
//        me->GetMotionMaster()->MoveIdle();
//        me->SetHomePosition(-10574.5f, 8713.98f, 1871.85f, 4.71f);
//        me->NearTeleportTo(me->GetHomePosition());
//        SetVisibleTeleporter(true);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EMPOWERED_SHOCK_LANCE);
//    }
//
//    void DefaultEvent()
//    {
//        switch (phase)
//        {
//        case PHASE_1:
//            if (IsMythicRaid())
//            {
//                events.RescheduleEvent(EVENT_SHOCK_LANCE, 4000);
//                events.RescheduleEvent(EVENT_SLEEP_CANISTER, 6000);
//                events.RescheduleEvent(EVENT_EMPOWERED_PULSE_GRENADE, 14000);
//            }
//            else
//            {
//                events.RescheduleEvent(EVENT_SHOCK_LANCE, 4000);
//                events.RescheduleEvent(EVENT_SLEEP_CANISTER, 6000);
//                events.RescheduleEvent(EVENT_PULSE_GRENADE, 15000);
//            }
//            break;
//        case PHASE_2:
//            events.RescheduleEvent(EVENT_SEVER, 7000);
//            events.RescheduleEvent(EVENT_SHRAPNEL_BLAST, 13000);
//            events.RescheduleEvent(EVENT_CHARGED_BLASTS, 8000);
//            break;
//        case PHASE_3:
//            if (IsMythicRaid())
//            {
//                events.RescheduleEvent(EVENT_SHOCK_LANCE, 4000);
//                events.RescheduleEvent(EVENT_SLEEP_CANISTER, 7000);
//                events.RescheduleEvent(EVENT_EMPOWERED_PULSE_GRENADE, 12000);
//                events.RescheduleEvent(EVENT_SHRAPNEL_BLAST, 15000);
//            }
//            else
//            {
//                events.RescheduleEvent(EVENT_EMPOWERED_SHOCK_LANCE, 5000);
//                events.RescheduleEvent(EVENT_EMPOWERED_PULSE_GRENADE, 6000);
//                events.RescheduleEvent(EVENT_EMPOWERED_SHRAPNEL_BLAST, 16000);
//            }
//            break;
//        case PHASE_4: //>Mythic
//            events.RescheduleEvent(EVENT_SEVER, 7000);
//            events.RescheduleEvent(EVENT_EMPOWERED_SHRAPNEL_BLAST, 11000);
//            events.RescheduleEvent(EVENT_CHARGED_BLASTS, 8000);
//            events.RescheduleEvent(EVENT_SLEEP_CANISTER, 10000);
//            break;
//        case PHASE_5: //<
//            events.RescheduleEvent(EVENT_EMPOWERED_SHOCK_LANCE, 5000);
//            events.RescheduleEvent(EVENT_EMPOWERED_PULSE_GRENADE, 6000);
//            events.RescheduleEvent(EVENT_EMPOWERED_SHRAPNEL_BLAST, 16000);
//            events.RescheduleEvent(EVENT_SLEEP_CANISTER, 12000);
//            break;
//        }
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        _JustDied();
//        SetVisibleTeleporter(true);
//        //instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EMPOWERED_SHOCK_LANCE);
//        //instance->DoCastSpellOnPlayers(SPELL_DAILY_ESSENCE_IMONAR);
//
//        AddDelayedEvent(3000, [this]() -> void
//        {
//            //Russians -.-
//            //instance->instance->LoadGrid(-10608.08f, 9002.58f);
//            //instance->instance->LoadGrid(-10574.31f, 8488.62f);
//            me->CastSpell(me, SPELL_OUTRO_CONV, true);
//        });
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//
//        switch (summon->GetEntry())
//        {
//        case NPC_PULSE_GRENADE:
//            summon->CastSpell(summon, SPELL_PULSE_GRENADE_AT, true);
//            break;
//        case NPC_SHRAPNEL_BLAST:
//            summon->CastSpell(summon, SPELL_SHRAPNEL_BLAST_AT, true);
//            break;
//        }
//    }
//
//    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
//    {
//        if (mode != AURA_REMOVE_BY_EXPIRE && mode != AURA_REMOVE_BY_ENEMY_SPELL)
//            return;
//
//        if (spellId == SPELL_SLEEP_CANISTER_MARK)
//            target->CastSpell(target, SPELL_SLUMBER_GAS_STUN, true);
//    }
//
//    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//    {
//        if (apply || !me->IsInCombat())
//            return;
//
//        if (spellId == SPELL_P1_CONFLAGRATION || spellId == SPELL_P2_CONFLAGRATION)
//        {
//            conflagrationTimer = 0;
//            infernalTimer = 3000;
//            me->RemoveDynObject(16404); //Bridge fire
//            DefaultEvent();
//            me->SetReactState(REACT_AGGRESSIVE);
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SPELL_P1_PULSE_GRENADE_FILTER:
//            if (!target->HasAura(SPELL_P1_PULSE_GRENADE_AT) && !target->HasAura(SPELL_P1_STASIS_TRAP_AT))
//                target->CastSpell(target, SPELL_P1_PULSE_GRENADE_AT, true);
//            break;
//        case SPELL_P1_STASIS_TRAP_FILTER:
//            if (!target->HasAura(SPELL_P1_PULSE_GRENADE_AT) && !target->HasAura(SPELL_P1_STASIS_TRAP_AT))
//                target->CastSpell(target, SPELL_P1_STASIS_TRAP_AT, true);
//            break;
//        case SPELL_P2_BLASTWIRE_FILTER:
//            if (!target->HasAura(SPELL_P1_PULSE_GRENADE_AT) && !target->HasAura(SPELL_P1_STASIS_TRAP_AT) &&
//                !target->HasAura(SPELL_P2_BLASTWIRE_AT) && !target->HasAura(SPELL_P2_SHRAPNEL_AT))
//            {
//                target->CastSpell(target, SPELL_P2_BLASTWIRE_AT, true);
//            }
//            break;
//        case SPELL_P2_SHRAPNEL_FILTER:
//            if (!target->HasAura(SPELL_P1_PULSE_GRENADE_AT) && !target->HasAura(SPELL_P1_STASIS_TRAP_AT) &&
//                !target->HasAura(SPELL_P2_BLASTWIRE_AT) && !target->HasAura(SPELL_P2_SHRAPNEL_AT))
//            {
//                target->CastSpell(target, SPELL_P2_SHRAPNEL_AT, true);
//            }
//            break;
//        case SPELL_P1_CONFLAGRATION_FILTER:
//        case SPELL_P2_CONFLAGRATION_FILTER:
//            target->CastSpell(target, SPELL_P1_P2_CONFLAGRATION_DUMMY, true);
//            target->CastSpell(target, curPlatformId ? SPELL_P1_CONFLAGRATION_AT : SPELL_P2_CONFLAGRATION_AT);
//            break;
//        case SPELL_SLEEP_CANISTER_FILTER:
//            Talk(SAY_WARN_SLEEP_CANISTER, target);
//            break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//        case SPELL_CHARGED_BLASTS:
//        {
//            std::list<Position> posList = smallShipPos;
//            Trinity::Containers::RandomResize(posList, 2);
//            me->SummonCreature(NPC_BOMBING_RUN, posList.front(), TEMPSUMMON_TIMED_DESPAWN, 45 * IN_MILLISECONDS);
//            me->SummonCreature(NPC_BOMBING_RUN, posList.back(), TEMPSUMMON_TIMED_DESPAWN, 45 * IN_MILLISECONDS);
//            Talk(SAY_CHARGED_BLASTS);
//            break;
//        }
//        case SPELL_EMPOWERED_SHRAPNEL_BLAST:
//            me->SummonCreature(NPC_ARTILLERY_STRIKE, bigShipPos[urand(0, 1)]);
//            Talk(SAY_EMPOWERED_SHRAPNEL_BLAST);
//            break;
//        case SPELL_SLEEP_CANISTER_FILTER:
//            Talk(SAY_SLEEP_CANISTER);
//            break;
//        }
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (me->HealthBelowPct(healthPct))
//        {
//            if (IsMythicRaid())
//                healthPct = healthPct > 21 ? healthPct -= 20 : 0;
//            else
//                healthPct = healthPct == 67 ? 34 : 0;
//
//            Talk(SAY_SWITCH_PHASE_1 + phase);
//            ++phase;
//            infernalTimer = 0;
//            events.Reset();
//            me->AttackStop();
//            me->SetCanFly(true);
//            switchPhase = true;
//            me->GetMotionMaster()->MovePath(!curPlatformId ? PATH_CHANGE_PHASE_FIRST : PATH_CHANGE_PHASE_SECOND, false);
//            me->CastSpell(me, !curPlatformId ? SPELL_P1_JETPACKS : SPELL_P2_JETPACKS, true);
//
//            //for (uint8 i = 0; i < 9; ++i)
//               // me->create(0, bFirePos[i].GetPositionX(), bFirePos[i].GetPositionY(), bFirePos[i].GetPositionZ(), bFirePos[i].GetOrientation(), 16404);
//        }
//    }
//
//    void LastWPReached()
//    {
//        if (!me->IsInCombat())
//            return;
//
//        curPlatformId = curPlatformId ? 0 : 1;
//        me->SetCanFly(false);
//        switchPhase = false;
//        me->RemoveAurasDueToSpell(curPlatformId ? SPELL_P1_JETPACKS : SPELL_P2_JETPACKS);
//        me->CastSpell(me, curPlatformId ? SPELL_P1_INFERNAL_LANDING : SPELL_P2_INFERNAL_LANDING, true);
//        me->SetFacingTo(curPlatformId ? 1.53f : 4.70f);
//        me->CastSpell(me, curPlatformId ? SPELL_P1_CONFLAGRATION : SPELL_P2_CONFLAGRATION, false);
//
//        if (IsHeroicPlusRaid())
//            conflagrationTimer = 1000;
//    }
//
//    void CheckPlatformPlayers()
//    {
//        bool find = false;
//        uint32 spellid[2] = { 247651, 247653 };
//
//        instance->DoOnPlayers([&](Player* player)
//        {
//            if (player->GetDistance(centrPlatformPos[curPlatformId]) < 35.0f)
//            {
//                if (!player->HasAura(spellid[curPlatformId]))
//                    player->CastSpell(player, spellid[curPlatformId], true);
//            }
//            else
//            {
//                find = true;
//                player->RemoveAurasDueToSpell(spellid[curPlatformId]);
//            }
//        });
//
//        if (find)
//            me->CastSpell(me, curPlatformId ? SPELL_INFERNAL_ROCKETS_2 : SPELL_INFERNAL_ROCKETS_1, true);
//    }
//
//    void SetVisibleTeleporter(bool visible)
//    {
//        if(Creature* temp = me->FindNearestCreature(128303, 100.0f))
//        temp->SetVisible(visible);
//    };
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
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
//        if (infernalTimer)
//        {
//            if (infernalTimer <= diff)
//            {
//                infernalTimer = 2000;
//                CheckPlatformPlayers();
//            }
//            else
//                infernalTimer -= diff;
//        }
//
//        if (conflagrationTimer)
//        {
//            if (conflagrationTimer <= diff)
//            {
//                conflagrationTimer = 3000;
//                DoCast(me, curPlatformId ? SPELL_P1_CONFLAGRATION_FILTER : SPELL_P2_CONFLAGRATION_FILTER, true);
//            }
//            else
//                conflagrationTimer -= diff;
//        }
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
//            case EVENT_SHOCK_LANCE:
//                me->CastSpell(me->GetVictim(), SPELL_SHOCK_LANCE);
//                events.RescheduleEvent(EVENT_SHOCK_LANCE, 5000);
//                break;
//            case EVENT_SLEEP_CANISTER:
//                DoCast(SPELL_SLEEP_CANISTER_FILTER);
//                events.RescheduleEvent(EVENT_SLEEP_CANISTER, 12000);
//                break;
//            case EVENT_PULSE_GRENADE:
//                DoCast(SPELL_PULSE_GRENADE);
//                events.RescheduleEvent(EVENT_PULSE_GRENADE, 17000);
//                break;
//            case EVENT_SEVER:
//                me->CastSpell(me->GetVictim(), SPELL_SEVER);
//                events.RescheduleEvent(EVENT_SEVER, 7000);
//                break;
//            case EVENT_SHRAPNEL_BLAST:
//                DoCast(SPELL_SHRAPNEL_BLAST);
//                events.RescheduleEvent(EVENT_SHRAPNEL_BLAST, 14000);
//                break;
//            case EVENT_CHARGED_BLASTS:
//                DoCast(SPELL_CHARGED_BLASTS);
//                events.RescheduleEvent(EVENT_CHARGED_BLASTS, 20000);
//                break;
//            case EVENT_EMPOWERED_SHOCK_LANCE:
//                me->CastSpell(me->GetVictim(), SPELL_EMPOWERED_SHOCK_LANCE);
//                events.RescheduleEvent(EVENT_EMPOWERED_SHOCK_LANCE, 10000);
//                break;
//            case EVENT_EMPOWERED_PULSE_GRENADE:
//                DoCast(SPELL_EMPOWERED_PULSE_GRENADE);
//                events.RescheduleEvent(EVENT_EMPOWERED_PULSE_GRENADE, 27000);
//                break;
//            case EVENT_EMPOWERED_SHRAPNEL_BLAST:
//                DoCast(SPELL_EMPOWERED_SHRAPNEL_BLAST);
//                events.RescheduleEvent(EVENT_EMPOWERED_SHRAPNEL_BLAST, 22000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////124704, 124889
//struct npc_imonar_ship_generic : public ScriptedAI
//{
//    npc_imonar_ship_generic(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoCast(me, SPELL_SHIP_SPAWN_VISUAL, true);
//
//        if (me->GetEntry() == NPC_BOMBING_RUN)
//        {
//            me->CastSpell(me, SPELL_CHARGED_BLASTS_FILTER, true);
//            AddDelayedCombat(12000, [this]() -> void { if (me) me->SetVisible(false); });
//        }
//        else if (me->GetEntry() == NPC_ARTILLERY_STRIKE)
//            me->CastSpell(me, SPELL_SHIP_SHRAPNEL_BLAST, false);
//    }
//
//    void Reset() override {}
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SPELL_CHARGED_BLASTS_FILTER:
//            me->SetTarget(target->GetGUID());
//            me->CastSpell(target, SPELL_CHARGED_BLASTS_SCALE, true);
//            me->CastSpell(target, SPELL_CHARGED_BLASTS_DUMMY_MARK, true);
//            me->CastSpell(target, SPELL_CHARGED_BLASTS_MARK);
//            me->CastSpell(me, SPELL_CHARGED_BLASTS_AT, true);
//            break;
//        case SPELL_CHARGED_BLASTS_MARK:
//            me->SetFacingToObject(target);
//            me->CastSpell(target, SPELL_CHARGED_BLASTS_DUMMY, true);
//            me->CastSpell(target, SPELL_CHARGED_BLASTS_DMG, true);
//            break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        if (spell->Id == SPELL_SHIP_SHRAPNEL_BLAST)
//        {
//            auto owner = me->GetOwner();
//            if (!owner)
//                return;
//
//
//                    me->CastSpell(SPELL_SHIP_SHRAPNEL_BLAST_MISSILE_1, true);
//            
//
//            AddDelayedCombat(8000, [this]() -> void { if (me) me->DespawnOrUnsummon(); });
//        }
//    }
//
//    void UpdateAI(uint32 diff) override {}
//};
//
////124928
//struct npc_imonar_traps : public ScriptedAI
//{
//    npc_imonar_traps(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void Reset() override {}
//
//    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
//    {
//        if ((createATSpellId == SPELL_PULSE_GRENADE_AT || createATSpellId == SPELL_P1_PULSE_GRENADE_AT) && caster && caster->GetMap()->IsHeroic())
//            caster->CastSpell(caster, SPELL_SHOCKED, true);
//
//        if (createATSpellId == SPELL_P1_PULSE_GRENADE_AT)
//            me->CastSpell(me, SPELL_P1_PULSE_GRENADE_KNOCK, true);
//    }
//
//    void UpdateAI(uint32 diff) override {}
//};
//
////250078, 250256
//class spell_imonar_electrify : public SpellScript
//{
//    PrepareSpellScript(spell_imonar_electrify);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        if (uint32 count = GetCaster()->GetAuraCount(SPELL_SHOCK_LANCE) + GetCaster()->GetAuraCount(SPELL_EMPOWERED_SHOCK_LANCE))
//            Trinity::Containers::RandomResize(targets, count);
//        else
//            targets.clear();
//    }
//
//    void Register()
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_imonar_electrify::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
//    }
//};
//
////248995, 248194
//class spell_imonar_jetpacks : public AuraScript
//{
//    PrepareAuraScript(spell_imonar_jetpacks);
//
//    bool switcher = true;
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (aurEff->GetTickNumber() % 2)
//        {
//            if (switcher)
//            {
//                switcher = false;
//
//                if (GetId() == SPELL_P1_JETPACKS)
//                    GetCaster()->CastSpell(GetCaster(), SPELL_P1_PULSE_GRENADE_FILTER, true);
//                else
//                    GetCaster()->CastSpell(GetCaster(), SPELL_P2_SHRAPNEL_FILTER, true);
//            }
//            else
//            {
//                switcher = true;
//
//                if (GetId() == SPELL_P1_JETPACKS)
//                    GetCaster()->CastSpell(GetCaster(), SPELL_P1_STASIS_TRAP_FILTER, true);
//                else
//                    GetCaster()->CastSpell(GetCaster(), SPELL_P2_BLASTWIRE_FILTER, true);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_imonar_jetpacks::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
//void AddSC_boss_imonar()
//{
//    RegisterCreatureAI(boss_imonar);
//    RegisterCreatureAI(npc_imonar_ship_generic);
//    RegisterCreatureAI(npc_imonar_traps);
//    RegisterSpellScript(spell_imonar_electrify);
//    RegisterAuraScript(spell_imonar_jetpacks);
//}

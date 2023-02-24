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
//#include "emerald_nightmare.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_NIGHTMARE_BLADES = 1,
//    SAY_MANIFEST_CORRUPTION = 2,
//    SAY_DARKENING_SOUL = 3,
//    SAY_PEREPHASE = 4,
//    SAY_DEATH = 5,
//};
//
//enum Spells
//{
//    SPELL_XAVIUS_ENERGIZE = 226192,
//    SPELL_XAVIUS_ENERGIZE_PHASE_1 = 226184,
//    SPELL_XAVIUS_ENERGIZE_PHASE_2 = 226193,
//    SPELL_XAVIUS_ENERGIZE_PHASE_3 = 226185,
//    SPELL_UNFATHOMABLE_REALITY = 207160,
//
//    //Phase 1
//    SPELL_LURKING_ERUPTION = 208322,
//    SPELL_MANIFEST_CORRUPTION = 210264,
//    SPELL_DARKENING_SOUL = 206651,
//    SPELL_DARKENING_SOUL_AOE = 207859,
//    SPELL_DARKENING_SOUL_ENERGY = 206652,
//    SPELL_NIGHTMARE_BLADES_FILTER = 209000, //Check target
//    SPELL_NIGHTMARE_BLADES_FILTER_2 = 211579, //Sum trigger
//    SPELL_NIGHTMARE_BLADES_SUM = 206653,
//    SPELL_NIGHTMARE_BLADES_MARK = 209001,
//    SPELL_NIGHTMARE_BLADES_MARK_2 = 211802,
//    SPELL_NIGHTMARE_BLADES_DMG = 206656,
//
//    //Phase 2
//    SPELL_BLACKENING_SOUL = 209158,
//    SPELL_BLACKENED = 205612,
//    SPELL_BLACKENED_TAINTING_ENERGY = 207853,
//    SPELL_NIGHTMARE_INFUSION = 209443,
//    SPELL_CALL_OF_NIGHTMARES = 205588, //Energy cost
//    SPELL_SPAWN_INCONCEIVABLE = 205739, //Summon Inconceivable Horror
//    SPELL_TAINTED_DISCHARGE_TRIG_AT = 208362,
//    SPELL_TAINTED_DISCHARGE_AT = 208363,
//    SPELL_CORRUPTION_METEOR = 206308,
//
//    //Phase 3
//    SPELL_WRITHING_DEEP = 226194, //Energy cost
//
//    //Phase 2: Heroic
//    SPELL_BONDS_OF_TERROR = 209032,
//    SPELL_BONDS_OF_TERROR_AURA = 209034,
//    SPELL_BONDS_OF_TERROR_AURA_2 = 210451,
//
//    //Player spells
//    SPELL_NIGHTMARE_TORMENT_ALT_POWER = 189960,
//    SPELL_NIGHTMARE_TORMENT_TICK = 226227,
//    SPELL_THE_DREAMING_SUM_CLONE = 206000,
//    SPELL_THE_DREAMING_CLONE_IMAGE = 206002,
//    SPELL_DREAM_SIMULACRUM = 206005,
//    SPELL_AWAKENING_DREAM = 207634,
//    SPELL_INSANITY_LEVEL_1 = 210203,
//    SPELL_INSANITY_LEVEL_2 = 210204,
//    SPELL_DESCENT_INTO_MADNESS = 208431,
//    SPELL_CORRUPTION_MADNESS = 207409,
//
//    //Player clone spells
//    SPELL_DREAMING_CLONE_ABORB = 189449,
//
//    //Dread Abomination
//    SPELL_CORRUPTION_CRUSHING_SHADOWS = 208748,
//
//    //Lurking Terror
//    SPELL_TORMENTING_FIXATION_FILTER = 205770,
//    SPELL_TORMENTING_FIXATION = 205771,
//    SPELL_TORMENTING_INFECTION_AT = 217989, //Normal
//    SPELL_TORMENTING_INFECTION_DMG = 217990,
//    SPELL_TORMENTING_DETONATION_AT = 205780, //Heroic
//    SPELL_TORMENTING_DETONATION_DMG = 205782,
//
//    //Corruption Horror
//    SPELL_CORRUPTION_HORROR_BIRTH = 213345,
//    SPELL_TORMENTING_SWIPE = 224649,
//    SPELL_CORRUPTING_NOVA = 207830,
//
//    //Inconceivable Horror
//    SPELL_DARK_RUINATION = 209288,
//    SPELL_TAINTED_DISCHARGE_SUM = 212124, //Summon Inconceivable Horror
//
//    //Nightmare Tentacle
//    SPELL_NIGHTMARE_BOLT = 206920,
//};
//
//enum eEvents
//{
//    EVENT_ABOMINATION_CRUSHING = 1,
//    EVENT_DARKENING_SOUL = 2,
//    EVENT_NIGHTMARE_BLADES = 3,
//    EVENT_BLACKENING_SOUL = 4,
//    EVENT_NIGHTMARE_INFUSION = 5,
//    EVENT_CORRUPTION_METEOR = 6,
//    EVENT_CHECK_ALT_POWER = 7,
//
//    //Heroic
//    EVENT_BONDS_OF_TERROR,
//};
//
//enum ePhase
//{
//    PHASE_1 = 0,
//    PHASE_2,
//    PHASE_3
//};
//
//Position const dreadPos[8] =
//{
//    {-3061.0f, -4959.0f, 147.78f, 5.4f},
//    {-2919.0f, -5101.0f, 147.78f, 2.3f},
//    {-3090.0f, -5030.0f, 147.78f, 0.0f},
//    {-3061.0f, -5101.0f, 147.78f, 0.7f},
//    {-2990.0f, -5130.0f, 147.78f, 1.5f},
//    {-2919.0f, -4959.0f, 147.78f, 3.9f},
//    {-2990.0f, -4930.0f, 147.78f, 4.7f},
//    {-2890.0f, -5030.0f, 147.78f, 3.1f}
//};
//
//Position const centrPos = { -2990.16f, -5029.85f, 147.78f };
//
//Position const eventPos[10] =
//{
//    {-2953.67f, -5117.50f, 147.70f, 0.0f},
//    {-2938.12f, -4980.82f, 147.70f, 0.0f},
//    {-3069.40f, -4997.82f, 147.70f, 0.0f},
//
//    {-2960.12f, -5043.86f, 147.70f, 0.0f},
//    {-2995.12f, -4992.84f, 147.70f, 0.0f},
//    {-3015.60f, -5056.74f, 147.70f, 0.0f},
//
//    {-3030.53f, -5054.32f, 147.70f, 0.0f},
//    {-2971.15f, -5066.08f, 147.70f, 0.0f},
//    {-2956.51f, -4994.40f, 147.70f, 0.0f},
//    {-3030.22f, -4992.07f, 147.70f, 0.0f}
//
//};
//
//enum Misc
//{
//    EVENT_1 = 1,
//    EVENT_2,
//    EVENT_3,
//    EVENT_4,
//    EVENT_5,
//    EVENT_6,
//
//    ACTION_1,
//};
////103769
//struct boss_xavius : public BossAI
//{
//    boss_xavius(Creature* creature) : BossAI(creature, DATA_XAVIUS) {}
//
//    bool intro = true;
//    uint8 healthPct = 0;
//    uint8 healthPhasePct = 0;
//    uint8 eventPhase = 0;
//
//    void Reset() override
//    {
//        _Reset();
//        healthPct = 95;
//        healthPhasePct = 65;
//        eventPhase = 0;
//        me->SetPower(POWER_ENERGY, 30);
//
//        if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) == DONE) // only after pre-event boss can start to do any things
//        {
//            if (intro)
//            {
//                intro = false;
//                me->SetVisible(true);
//                me->SetHomePosition(-3019.56f, -5060.41f, 147.70f, me->GetHomePosition().GetOrientation());
//                me->GetMotionMaster()->MovePoint(0, -3019.56f, -5060.41f, 147.70f);
//            }
//            me->SetReactState(REACT_AGGRESSIVE);
//            for (uint8 i = 0; i < 8; ++i)
//                me->SummonCreature(NPC_DREAD_ABOMINATION, dreadPos[i]);
//        }
//        else
//        {
//            me->SetVisible(false);
//            me->SetReactState(REACT_PASSIVE);
//        }
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        Talk(SAY_AGGRO);
//        _JustEngagedWith();
//        ClearPlayerAuras();
//        DoCast(me, SPELL_XAVIUS_ENERGIZE_PHASE_1, true);
//        DoCast(me, SPELL_UNFATHOMABLE_REALITY, true);
//        instance->DoCastSpellOnPlayers(SPELL_NIGHTMARE_TORMENT_ALT_POWER);
//
//        StartEvents(PHASE_1);
//
//        if (auto yzera = me->SummonCreature(NPC_YZERA, -2988.90f, -5028.98f, 182.07f))
//            yzera->CastSpell(yzera, 222713, false);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        _JustDied();
//        ClearPlayerAuras();
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        BossAI::EnterEvadeMode();
//        ClearPlayerAuras();
//    }
//
//    void StartEvents(uint8 phase)
//    {
//        events.Reset();
//        eventPhase = phase;
//
//        switch (phase)
//        {
//        case PHASE_1:
//            events.RescheduleEvent(EVENT_ABOMINATION_CRUSHING, 12000);
//            events.RescheduleEvent(EVENT_DARKENING_SOUL, 7000);
//            events.RescheduleEvent(EVENT_NIGHTMARE_BLADES, 18000);
//            break;
//        case PHASE_2:
//            events.RescheduleEvent(EVENT_BLACKENING_SOUL, 7000);
//            events.RescheduleEvent(EVENT_CORRUPTION_METEOR, 21000);
//            events.RescheduleEvent(EVENT_NIGHTMARE_INFUSION, 32000);
//            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
//                events.RescheduleEvent(EVENT_BONDS_OF_TERROR, 12000);
//            break;
//        case PHASE_3:
//            events.RescheduleEvent(EVENT_BLACKENING_SOUL, 7000);
//            events.RescheduleEvent(EVENT_NIGHTMARE_BLADES, 18000);
//            events.RescheduleEvent(EVENT_CORRUPTION_METEOR, 21000);
//            events.RescheduleEvent(EVENT_NIGHTMARE_INFUSION, 32000);
//            break;
//        }
//        events.RescheduleEvent(EVENT_CHECK_ALT_POWER, 2000);
//    }
//
//    void DamageTaken(Unit* attacker, uint32& damage)
//    {
//        if (!attacker->HasAura(SPELL_NIGHTMARE_TORMENT_ALT_POWER))
//        {
//            damage = 0;
//            return;
//        }
//
//        if (me->HealthBelowPct(healthPct))
//        {
//            if (healthPct > 60)
//                healthPct = 60;
//            else
//                healthPct = 0;
//
//            std::list<Player*> playerList;
//            GetPlayerListInGrid(playerList, me, 100.0f);
//            if (!playerList.empty())
//            {
//                Trinity::Containers::RandomResize(playerList, playerList.size() > 1 ? playerList.size() / 2 : 1);
//
//                for (auto const& player : playerList)
//                {
//                    if (!player || !player->IsAlive() || player->IsGameMaster())
//                        continue;
//
//                    player->CastSpell(player, SPELL_THE_DREAMING_SUM_CLONE, true);
//                }
//                if (auto yzera = me->FindNearestCreature(NPC_YZERA, 100.0f, true))
//                    yzera->CastSpell(yzera, 222713, false);
//            }
//        }
//        //Regulates events phases
//        if (me->HealthBelowPct(healthPhasePct))
//        {
//            Talk(SAY_PEREPHASE);
//            if (healthPhasePct > 30) //65%
//            {
//                StartEvents(PHASE_2);
//                healthPhasePct = 30;
//            }
//            else
//            {
//                StartEvents(PHASE_3);
//                healthPhasePct = 0;
//            }
//        }
//    }
//
//    void SpellHit(Unit* caster, const SpellInfo* spell) override
//    {
//        if (spell->Id == SPELL_CALL_OF_NIGHTMARES)
//        {
//            Position pos;
//            float angle = 0.0f;
//            for (uint8 i = 0; i < 6; ++i)
//            {
//                angle = frand(0, 6.0f);
//                me->CastSpell(pos, SPELL_TAINTED_DISCHARGE_SUM, true);
//            }
//        }
//    }
//
//    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//    {
//        if (spell->Id == SPELL_NIGHTMARE_BLADES_MARK)
//        {
//           // if (auto pTarget = SelectTarget(SELECT_TARGET_RANDOM, checkPlayers(), 150.0f, true, -SPELL_NIGHTMARE_BLADES_MARK))
//                DoCast(SPELL_NIGHTMARE_BLADES_MARK_2);
//            Talk(SAY_NIGHTMARE_BLADES);
//        }
//    }
//
//    void OnAreaTriggerDespawn(uint32 spellId, Position pos, bool duration)
//    {
//        if (duration && spellId == SPELL_TAINTED_DISCHARGE_AT)
//            me->CastSpell(pos, SPELL_TAINTED_DISCHARGE_SUM, true);
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        if (type == DATA_XAVIUS)
//            return eventPhase;
//        return 0;
//    }
//
//    void ClearPlayerAuras()
//    {
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTMARE_TORMENT_ALT_POWER);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTMARE_TORMENT_TICK);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INSANITY_LEVEL_1);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INSANITY_LEVEL_2);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DREAM_SIMULACRUM);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DESCENT_INTO_MADNESS);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTION_MADNESS);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLACKENING_SOUL);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BONDS_OF_TERROR_AURA);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BONDS_OF_TERROR_AURA_2);
//    }
//
//
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
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_ABOMINATION_CRUSHING:
//            {
//                EntryCheckPredicate pred(NPC_DREAD_ABOMINATION);
//                summons.DoAction(ACTION_1, pred, 1);
//                events.RescheduleEvent(EVENT_ABOMINATION_CRUSHING, 10000);
//                break;
//            }
//            case EVENT_DARKENING_SOUL:
//                DoCastVictim(SPELL_DARKENING_SOUL);
//                events.RescheduleEvent(EVENT_DARKENING_SOUL, 8000);
//                if (urand(0, 3) == 3)
//                    Talk(SAY_DARKENING_SOUL);
//                break;
//            case EVENT_NIGHTMARE_BLADES:
//               
//                    DoCast(SPELL_NIGHTMARE_BLADES_MARK);
//                    DoCast(SPELL_NIGHTMARE_BLADES_MARK_2);
//                events.RescheduleEvent(EVENT_NIGHTMARE_BLADES, 16000);
//                break;
//            case EVENT_BLACKENING_SOUL:
//                DoCastVictim(SPELL_BLACKENING_SOUL);
//                events.RescheduleEvent(EVENT_BLACKENING_SOUL, 7000);
//                break;
//            case EVENT_NIGHTMARE_INFUSION:
//                DoCast(me, SPELL_NIGHTMARE_INFUSION, true);
//                events.RescheduleEvent(EVENT_NIGHTMARE_INFUSION, 62000);
//                break;
//            case EVENT_CORRUPTION_METEOR:
//                DoCast(me, SPELL_CORRUPTION_METEOR, true);
//                events.RescheduleEvent(EVENT_CORRUPTION_METEOR, 29000);
//                break;
//            case EVENT_CHECK_ALT_POWER:
//            {
//                instance->DoOnPlayers([](Player* player)
//                {
//                    if (player->IsAlive() && !player->IsGameMaster() && !player->HasAura(SPELL_NIGHTMARE_TORMENT_ALT_POWER))
//                        player->CastSpell(player, SPELL_NIGHTMARE_TORMENT_ALT_POWER, true);
//                });
//                events.RescheduleEvent(EVENT_CHECK_ALT_POWER, 2000);
//                break;
//            }
//            case EVENT_BONDS_OF_TERROR:
//            {
//                uint8 freePlayerCount = 0;
//                std::list<Player*> threatlist;
//                me->GetPlayerListInGrid(threatlist, 200.0f);
//                for (auto ref : threatlist)
//                {
//                    if (!ref->HasAura(SPELL_BONDS_OF_TERROR_AURA) && !ref->HasAura(SPELL_BONDS_OF_TERROR_AURA_2) &&
//                        (me->GetVictim() && me->GetVictim()->GetGUID() != ref->GetGUID()))
//                    {
//                        ++freePlayerCount;
//                    }
//                }
//                if (freePlayerCount > 1)
//                    DoCast(me, SPELL_BONDS_OF_TERROR, true);
//                events.RescheduleEvent(EVENT_BONDS_OF_TERROR, 12000);
//                break;
//            }
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////104096
//struct npc_xavius_sleeping_version : public ScriptedAI
//{
//    npc_xavius_sleeping_version(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        instance = me->GetInstanceScript();
//    }
//
//    InstanceScript* instance;
//    uint16 checkStateBoss = 0;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        checkStateBoss = 1000;
//        summoner->CastSpell(me, SPELL_THE_DREAMING_CLONE_IMAGE, true);
//        DoCast(me, SPELL_DREAMING_CLONE_ABORB, true);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (checkStateBoss)
//        {
//            if (checkStateBoss <= diff)
//            {
//                checkStateBoss = 1000;
//
//                if (instance->GetBossState(DATA_XAVIUS) != IN_PROGRESS)
//                {
//                    checkStateBoss = 0;
//                    me->DespawnOrUnsummon();
//                }
//            }
//            else checkStateBoss -= diff;
//        }
//    }
//};
//
////105343
//struct npc_xavius_dread_abomination : public ScriptedAI
//{
//    npc_xavius_dread_abomination(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//        me->SetReactState(REACT_PASSIVE);
//        me->SetVisible(false);
//    }
//
//    EventMap events;
//
//    void Reset() override {}
//
//    void DoAction(int32 const action) override
//    {
//        events.RescheduleEvent(EVENT_1, 100);
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
//                events.RescheduleEvent(EVENT_2, 500);
//                break;
//            case EVENT_2:
//                me->SetVisible(true);
//                events.RescheduleEvent(EVENT_3, 1000);
//                break;
//            case EVENT_3:
//                DoCast(SPELL_CORRUPTION_CRUSHING_SHADOWS);
//                events.RescheduleEvent(EVENT_4, 5000);
//                break;
//            case EVENT_4:
//                me->SetVisible(false);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////103694
//struct npc_xavius_lurking_terror : public ScriptedAI
//{
//    npc_xavius_lurking_terror(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->SetSpeed(MOVE_RUN, 0.6f);
//        me->SetSpeed(MOVE_WALK, 0.6f);
//    }
//
//    EventMap events;
//    ObjectGuid targetGUID;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        events.RescheduleEvent(EVENT_1, 2000);
//        events.RescheduleEvent(EVENT_3, 3000);
//    }
//
//    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//    {
//        if (spell->Id == SPELL_TORMENTING_FIXATION_FILTER)
//        {
//            DoCast(target, SPELL_TORMENTING_FIXATION, true);
//            targetGUID = target->GetGUID();
//            events.RescheduleEvent(EVENT_2, 1000);
//        }
//    }
//
//    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
//    {
//        if (spellId == SPELL_TORMENTING_INFECTION_DMG || spellId == SPELL_TORMENTING_DETONATION_DMG)
//        {
//            events.Reset();
//            me->GetMotionMaster()->Clear();
//            me->DespawnOrUnsummon(1000);
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
//                DoCast(me, SPELL_TORMENTING_FIXATION_FILTER, true);
//                break;
//            case EVENT_2:
//                if (auto target = ObjectAccessor::GetUnit(*me, targetGUID))
//                {
//                    me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//                    events.RescheduleEvent(EVENT_2, 500);
//                }
//                else
//                    events.RescheduleEvent(EVENT_1, 1000);
//                break;
//            case EVENT_3:
//                if (!IsMythicRaid())
//                    DoCast(me, SPELL_TORMENTING_INFECTION_AT, true);
//                else
//                    DoCast(me, SPELL_TORMENTING_DETONATION_AT, true);
//                break;
//            }
//        }
//    }
//};
//
////103695
//struct npc_xavius_corruption_horror : public ScriptedAI
//{
//    npc_xavius_corruption_horror(Creature* creature) : ScriptedAI(creature) {}
//
//    EventMap events;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        DoCast(me, SPELL_CORRUPTION_HORROR_BIRTH, true);
//        DoZoneInCombat(me, 100.0f);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        events.RescheduleEvent(EVENT_1, 9000);
//        events.RescheduleEvent(EVENT_2, 14000);
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
//                DoCastVictim(SPELL_TORMENTING_SWIPE);
//                events.RescheduleEvent(EVENT_1, 10000);
//                break;
//            case EVENT_2:
//                DoCast(SPELL_CORRUPTING_NOVA);
//                events.RescheduleEvent(EVENT_2, 20000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////104422
//struct npc_xavius_nightmare_blades : public ScriptedAI
//{
//    npc_xavius_nightmare_blades(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//    std::list<ObjectGuid> listGuid;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner)
//    {
//        listGuid.clear();
//        events.RescheduleEvent(EVENT_1, 200);
//    }
//
//    bool GetObjectData(ObjectGuid const& guid) 
//    {
//        bool find = false;
//
//        for (auto targetGuid : listGuid)
//            if (targetGuid == guid)
//                find = true;
//
//        if (!find)
//            listGuid.push_back(guid);
//
//        return find;
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
//                if (auto owner = me->GetOwner())
//                    if (auto target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true, SPELL_NIGHTMARE_BLADES_MARK))
//                    {
//                        Position pos;
//                        float angle = target->GetRelativeAngle(me);
//                        float dist = me->GetDistance(target) + 20.0f;
//                        target->GetNearPosition(dist, angle);
//
//                        float angle2 = pos.GetRelativeAngle(target);
//                        float dist2 = 8.0f;
//                        for (uint8 i = 0; i < 18; ++i)
//                        {
//                            me->CastSpell(pos, SPELL_NIGHTMARE_BLADES_DMG, true);
//                        }
//                    }
//                break;
//            }
//            }
//        }
//    }
//};
//
////105611
//struct npc_xavius_inconceivable_horror : public ScriptedAI
//{
//    npc_xavius_inconceivable_horror(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->SetSpeed(MOVE_RUN, 0.3f);
//        me->SetSpeed(MOVE_WALK, 0.3f);
//    }
//
//    EventMap events;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        events.RescheduleEvent(EVENT_1, 1000);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (auto owner = me->GetOwner())
//            if (owner->IsInCombat())
//                owner->CastSpell(me->GetPosition(), SPELL_TAINTED_DISCHARGE_TRIG_AT, true);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
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
//                if (auto owner = me->GetOwner())
//                {
//                    if (me->GetDistance(owner) > 10.0f)
//                    {
//                        Position pos;
//                        me->GetNearPosition(me->GetDistance(owner) / 2, me->GetRelativeAngle(owner));
//                        me->GetMotionMaster()->MovePoint(1, pos);
//                        events.RescheduleEvent(EVENT_1, 1000);
//                    }
//                    else
//                    {
//                        me->GetMotionMaster()->Clear();
//                        me->SetFacingToObject(owner);
//                        DoCast(SPELL_DARK_RUINATION);
//                        events.RescheduleEvent(EVENT_1, 5000);
//                    }
//                }
//                break;
//            }
//        }
//    }
//};
//
////104592
//struct npc_xavius_nightmare_tentacle : public ScriptedAI
//{
//    npc_xavius_nightmare_tentacle(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        SetCombatMovement(false);
//    }
//
//    EventMap events;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        events.RescheduleEvent(EVENT_1, 500);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
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
//                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
//                    DoCast(target, SPELL_NIGHTMARE_BOLT);
//                events.RescheduleEvent(EVENT_1, urand(3, 5) * IN_MILLISECONDS);
//                break;
//            }
//        }
//    }
//};
//
//// 109847
//struct npc_xavius_event_conroller : public ScriptedAI
//{
//    npc_xavius_event_conroller(Creature* creature) : ScriptedAI(creature), summons(me)
//    {
//        instance = me->GetInstanceScript();
//        countAdds = 0;
//        checkEvade = 1000;
//        SetCanSeeEvenInPassiveMode(true);
//        if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) == NOT_STARTED)
//        {
//            for (int i = 0; i < 9; ++i)
//            {
//                me->SummonCreature(NPC_SMALL_TRASH, eventPos[6].GetPositionX() + irand(-15, 15), eventPos[6].GetPositionY() + irand(-15, 15), eventPos[6].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//            }
//            for (int i = 0; i < 9; ++i)
//            {
//                me->SummonCreature(NPC_SMALL_TRASH, eventPos[7].GetPositionX() + irand(-15, 15), eventPos[7].GetPositionY() + irand(-15, 15), eventPos[7].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//            }
//            for (int i = 0; i < 9; ++i)
//            {
//                me->SummonCreature(NPC_SMALL_TRASH, eventPos[8].GetPositionX() + irand(-15, 15), eventPos[8].GetPositionY() + irand(-15, 15), eventPos[8].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//            }
//            for (int i = 0; i < 9; ++i)
//            {
//                me->SummonCreature(NPC_SMALL_TRASH, eventPos[9].GetPositionX() + irand(-15, 15), eventPos[9].GetPositionY() + irand(-15, 15), eventPos[9].GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//            }
//        }
//    }
//
//    SummonList summons;
//    EventMap events;
//    InstanceScript* instance; // DATA_PRE_EVENT_XAVIUS
//
//    uint8 countAdds = 0;
//    uint32 checkEvade = 0;
//
//    void MoveInLineOfSight(Unit* who) override
//    {
//        if (who->GetTypeId() != TYPEID_PLAYER)
//            return;
//
//        if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) != NOT_STARTED)
//            return;
//
//        if (me->GetExactDist2d(who) <= 17.0f)
//            return;
//        events.Reset();
//        instance->SetBossState(DATA_PRE_EVENT_XAVIUS, IN_PROGRESS);
//        std::list<Creature*> addsList;
//        GetCreatureListWithEntryInGrid(addsList, me, NPC_SMALL_TRASH, 150.0f);
//        for (auto creature : addsList)
//        {
//            creature->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//            creature->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            creature->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            creature->GetMotionMaster()->MovePoint(0, (2.0 * creature->GetPositionX() - me->GetPositionX()), (2.0 * creature->GetPositionY() - me->GetPositionY()), creature->GetPositionZ()); // way for nice despawn
//            creature->DespawnOrUnsummon(3000);
//        }
//        events.RescheduleEvent(EVENT_1, 5000);
//        countAdds = 0;
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//        // DoZoneInCombat(summon, 100.0f);
//        if (summon->GetEntry() == NPC_SMALL_TRASH)
//            summon->GetMotionMaster()->MoveRandom(5.0f);
//        else if (auto target = me->SelectNearestPlayer(100.0f))
//            summon->AI()->AttackStart(target);
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//    {
//        if (summon->GetEntry() != NPC_IN_THE_SHADOW && summon->GetEntry() != NPC_NIGHTMARE_AMALGAMATION && summon->GetEntry() != NPC_SHADOW_POUNDER)
//            return;
//
//        ++countAdds;
//
//        switch (countAdds)
//        {
//        case 3:
//            events.RescheduleEvent(EVENT_2, 3000);
//            break;
//        case 6:
//            events.RescheduleEvent(EVENT_3, 3000);
//            break;
//        case 12:
//            events.RescheduleEvent(EVENT_5, 5000);
//            break;
//        default:
//            break;
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (checkEvade <= diff)
//        {
//            if (instance->GetBossState(DATA_PRE_EVENT_XAVIUS) == IN_PROGRESS)
//                if (!me->SelectNearestPlayer(70.0f))
//                {
//                    events.Reset();
//                    instance->SetBossState(DATA_PRE_EVENT_XAVIUS, NOT_STARTED);
//                    summons.DespawnAll();
//                }
//            checkEvade = 1000;
//        }
//        else
//            checkEvade -= diff;
//
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//                for (uint8 i = 0; i < 3; ++i)
//                    me->SummonCreature(NPC_IN_THE_SHADOW, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                events.RescheduleEvent(EVENT_6, 5000);
//                break;
//            case EVENT_2:
//                for (uint8 i = 0; i < 3; ++i)
//                    me->SummonCreature(NPC_NIGHTMARE_AMALGAMATION, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                events.RescheduleEvent(EVENT_6, 5000);
//                break;
//            case EVENT_3:
//                for (uint8 i = 0; i < 2; ++i)
//                    me->SummonCreature(NPC_NIGHTMARE_AMALGAMATION, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                me->SummonCreature(NPC_IN_THE_SHADOW, eventPos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                events.RescheduleEvent(EVENT_4, 7000);
//                events.RescheduleEvent(EVENT_6, 5000);
//                break;
//            case EVENT_4:
//                for (uint8 i = 3; i < 6; ++i)
//                    me->SummonCreature(NPC_SHADOW_POUNDER, eventPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                break;
//            case EVENT_5:
//            {
//                instance->SetBossState(DATA_PRE_EVENT_XAVIUS, DONE);
//                if (auto boss = me->FindNearestCreature(NPC_XAVIUS, 100.0f, true))
//                    boss->AI()->Reset();
//                events.Reset();
//                summons.DespawnAll();
//                break;
//            }
//            case EVENT_6:
//                for (uint8 i = 0; i < 6; ++i)
//                    me->SummonCreature(NPC_DARK_DEVOURERS, me->GetPositionX() + irand(-25, 25), me->GetPositionY() + irand(-25, 25), me->GetPositionZ());
//                break;
//            }
//        }
//    }
//};
//
////226184
//class spell_xavius_periodic_energize : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_periodic_energize);
//
//    uint8 castCount = 0;
//    bool hightTick = false;
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
//        {
//            if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_2)
//            {
//                if (hightTick)
//                {
//                    caster->SetPower(POWER_ENERGY, powerCount + 3);
//                    hightTick = false;
//                }
//                else
//                {
//                    caster->SetPower(POWER_ENERGY, powerCount + 2);
//                    hightTick = true;
//                }
//            }
//            else
//                caster->SetPower(POWER_ENERGY, powerCount + 5);
//        }
//        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
//        {
//            if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_1)
//            {
//                if (castCount++ < 3)
//                    caster->CastSpell(caster, SPELL_LURKING_ERUPTION, true);
//                else
//                {
//                    castCount = 0;
//                    caster->CastSpell(caster, SPELL_MANIFEST_CORRUPTION, true);
//                    caster->AI()->Talk(SAY_MANIFEST_CORRUPTION);
//                }
//                caster->SetPower(POWER_ENERGY, 0);
//            }
//            else if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_2)
//            {
//                caster->CastSpell(caster, SPELL_CALL_OF_NIGHTMARES);
//            }
//            else if (caster->AI()->GetData(DATA_XAVIUS) == PHASE_3)
//            {
//                caster->CastSpell(caster, SPELL_WRITHING_DEEP);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_periodic_energize::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////206005
//class spell_xavius_dream_simulacrum : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_dream_simulacrum);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (auto player = GetTarget()->ToPlayer())
//        {
//            if (auto instance = player->GetInstanceScript())
//                if (instance->GetBossState(DATA_XAVIUS) != IN_PROGRESS)
//                    return;
//
//
//
//                    player->ResetAllPowers();
//                    player->RemoveAllAurasOnDeath();
//                    player->CastSpell(SPELL_AWAKENING_DREAM, true);
//
//            
//        }
//    }
//
//    void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
//    {
//        if (!GetTarget())
//            return;
//
//        if (dmgInfo.GetDamage() < GetTarget()->GetHealth())
//            absorbAmount = 0;
//        else
//            this->Remove();
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_xavius_dream_simulacrum::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
//        OnEffectAbsorb += AuraEffectAbsorbFn(spell_xavius_dream_simulacrum::OnAbsorb, EFFECT_0);
//    }
//};
//
////189960
//class spell_xavius_nightmare_torment_alt_power : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_nightmare_torment_alt_power);
//
//    bool madnes = false;
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (!GetCaster())
//            return;
//
//        if (auto player = GetCaster()->ToPlayer())
//        {
//            uint8 altPower = player->GetPower(POWER_ALTERNATE_POWER);
//
//            if (altPower < 100 && madnes)
//                madnes = false;
//
//            if (altPower >= 33 && altPower < 66 && !player->HasAura(SPELL_INSANITY_LEVEL_1))
//                player->CastSpell(player, SPELL_INSANITY_LEVEL_1, true);
//            else if (altPower < 33 && player->HasAura(SPELL_INSANITY_LEVEL_1))
//                player->RemoveAurasDueToSpell(SPELL_INSANITY_LEVEL_1);
//
//            if (altPower >= 66 && altPower < 100 && !player->HasAura(SPELL_INSANITY_LEVEL_2))
//                player->CastSpell(player, SPELL_INSANITY_LEVEL_2, true);
//            else if (altPower < 66 && player->HasAura(SPELL_INSANITY_LEVEL_2))
//                player->RemoveAurasDueToSpell(SPELL_INSANITY_LEVEL_2);
//
//            if (altPower >= 100 && !madnes)
//            {
//                madnes = true;
//                player->CastSpell(player, SPELL_DESCENT_INTO_MADNESS, true);
//            }
//        }
//    }
//
//    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
//    {
//        amount = 1;
//    }
//
//    void Absorb(AuraEffect* /*AuraEffect**/, DamageInfo& dmgInfo, uint32& absorbAmount)
//    {
//        absorbAmount = 0;
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_nightmare_torment_alt_power::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_xavius_nightmare_torment_alt_power::CalculateAmount, EFFECT_2, SPELL_AURA_SCHOOL_HEAL_ABSORB);
//        OnEffectAbsorb += AuraEffectAbsorbFn(spell_xavius_nightmare_torment_alt_power::Absorb, EFFECT_2);
//    }
//};
//
////208860
//class spell_xavius_crushing_shadows : public SpellScript
//{
//    PrepareSpellScript(spell_xavius_crushing_shadows);
//
//    void DealDamage()
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        Position const* pos = GetExplTargetDest();
//        float distance = pos->GetExactDist2d(GetHitUnit());
//        float radius = GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius(GetCaster());
//        uint32 damage = GetHitDamage() * (1.0f - ((distance * 3.0f) / radius));
//
//        SetHitDamage(damage);
//    }
//
//    void Register() override
//    {
//        OnHit += SpellHitFn(spell_xavius_crushing_shadows::DealDamage);
//    }
//};
//
////207160
//class spell_xavius_unfathomable_reality : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_unfathomable_reality);
//
//        void OnPereodic(AuraEffect const* aurEff)
//    {
//        if (!GetCaster())
//            return;
//
//        Position pos;
//        GetCaster()->GetRandomNearPosition(60.0f);
//        GetCaster()->CastSpell(pos, 206878, true);
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_xavius_unfathomable_reality::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////208431
//class spell_xavius_descent_into_madness : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_descent_into_madness);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (auto player = GetTarget()->ToPlayer())
//        {
//            if (player->HasAura(SPELL_DREAM_SIMULACRUM))
//            {
//                player->RemoveAurasDueToSpell(SPELL_DREAM_SIMULACRUM);
//                return;
//            }
//
//            if (auto instance = player->GetInstanceScript())
//                if (instance->GetBossState(DATA_XAVIUS) == IN_PROGRESS)
//                    if (auto xavius = instance->instance->GetCreature(instance->GetGuidData(NPC_XAVIUS)))
//                    {
//                        xavius->CastSpell(player, SPELL_CORRUPTION_MADNESS, true);
//                    }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_xavius_descent_into_madness::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////206651, 209158
//class spell_xavius_darkening_soul : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_darkening_soul);
//
//    bool remove = false;
//    bool dispel = false;
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
//
//        if (!GetCaster() || !GetTarget() || mode != AURA_REMOVE_BY_ENEMY_SPELL || remove)
//            return;
//
//        if (GetTarget())
//        {
//            remove = true;
//
//            if (GetId() == SPELL_DARKENING_SOUL)
//                GetTarget()->CastSpell(GetTarget(), SPELL_DARKENING_SOUL_AOE, true);
//            else if (GetId() == SPELL_BLACKENING_SOUL)
//                GetTarget()->CastSpell(GetTarget(), SPELL_BLACKENED, true);
//        }
//    }
//
//    void HandleDispel(DispelInfo* dispelInfo)
//    {
//        if (!GetCaster() || dispel)
//            return;
//
//        if (auto dispeller = dispelInfo->GetDispeller())
//        {
//            dispel = true;
//
//            if (GetId() == SPELL_DARKENING_SOUL)
//                dispeller->CastSpell(dispeller, SPELL_DARKENING_SOUL_ENERGY, true);
//            else if (GetId() == SPELL_BLACKENING_SOUL)
//                dispeller->CastSpell(dispeller, SPELL_BLACKENED_TAINTING_ENERGY, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnDispel += AuraDispelFn(spell_xavius_darkening_soul::HandleDispel);
//        OnEffectRemove += AuraEffectRemoveFn(spell_xavius_darkening_soul::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////211802
//class spell_xavius_nightmare_blades : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_nightmare_blades);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetCaster() || !GetTarget())
//            return;
//
//        if (!GetTarget()->HasAura(SPELL_NIGHTMARE_BLADES_MARK))
//            GetCaster()->CastSpell(GetTarget(), SPELL_NIGHTMARE_BLADES_SUM, true);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_xavius_nightmare_blades::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////206656
//class spell_xavius_nightmare_blades_dmg_filter : public SpellScript
//{
//    PrepareSpellScript(spell_xavius_nightmare_blades_dmg_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        targets.remove_if([this](WorldObject* object) -> bool
//        {
//            if (object == nullptr)
//                return true;
//
//            return false;
//        });
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xavius_nightmare_blades_dmg_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xavius_nightmare_blades_dmg_filter::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
//    }
//};
//
////210451
//class spell_xavius_bonds_of_terror : public AuraScript
//{
//    PrepareAuraScript(spell_xavius_bonds_of_terror);
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetCaster() && GetCaster()->HasAura(SPELL_BONDS_OF_TERROR_AURA))
//            GetCaster()->RemoveAurasDueToSpell(SPELL_BONDS_OF_TERROR_AURA);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_xavius_bonds_of_terror::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////226194
//class spell_xavius_writhing_deep : public SpellScript
//{
//    PrepareSpellScript(spell_xavius_writhing_deep);
//
//    void HandleScript(SpellEffIndex effIndex)
//    {
//        PreventHitDefaultEffect(effIndex);
//
//        if (auto caster = GetCaster())
//        {
//            Position pos;
//            caster->GetNearPosition(frand(15.0f, 25.0f), urand(0, 6));
//            uint32 spellId = GetSpellInfo()->GetEffect(effIndex)->TriggerSpell;
//            uint32 delay = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
//            caster->CastSpell(pos, spellId, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
//        OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep::HandleScript, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
//        OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep::HandleScript, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
//        OnEffectLaunch += SpellEffectFn(spell_xavius_writhing_deep::HandleScript, EFFECT_3, SPELL_EFFECT_TRIGGER_SPELL);
//    }
//};
//
////207830
//class spell_xavius_corrupting_nova : public SpellScript
//{
//    PrepareSpellScript(spell_xavius_corrupting_nova);
//
//    void HandleScriptEffect(SpellEffIndex effIndex)
//    {
//        PreventHitDefaultEffect(EFFECT_1);
//
//        if (auto target = GetHitUnit())
//            if (target->HasAura(SPELL_NIGHTMARE_TORMENT_ALT_POWER))
//            {
//                uint32 power = target->GetPower(POWER_ALTERNATE_POWER);
//                target->SetPower(POWER_ALTERNATE_POWER, power + 5);
//            }
//    }
//
//    void Register() override
//    {
//        OnEffectLaunchTarget += SpellEffectFn(spell_xavius_corrupting_nova::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
//    }
//};
//
////206369, 207849
//class spell_xavius_corruption_meteor : public SpellScript
//{
//    PrepareSpellScript(spell_xavius_corruption_meteor);
//
//    uint8 targetCount = 0;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (targets.size() > 1)
//            targetCount = targets.size();
//    }
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetCaster() || !GetHitUnit() || targetCount == 0)
//            return;
//
//        SetHitDamage(GetHitDamage() / targetCount);
//    }
//
//    void HandleEnergy(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetCaster() || !GetHitUnit() || targetCount == 0)
//            return;
//
//        SetEffectValue(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints / targetCount);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xavius_corruption_meteor::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//        OnEffectHitTarget += SpellEffectFn(spell_xavius_corruption_meteor::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//        OnEffectHitTarget += SpellEffectFn(spell_xavius_corruption_meteor::HandleEnergy, EFFECT_0, SPELL_EFFECT_ENERGIZE);
//    }
//};
//
////223216
//class spell_teleport_to_rift : public AuraScript
//{
//    PrepareAuraScript(spell_teleport_to_rift);
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTarget() && GetTarget()->IsPlayer())
//        {
//            GetTarget()->GetMotionMaster()->MovePath(9370973, false);
//            GetTarget()->ToPlayer()->SetClientControl(GetTarget(), 0);
//            GetTarget()->ToPlayer()->SetCanFly(true);
//        }
//    }
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTarget() && GetTarget()->IsPlayer())
//        {
//            GetTarget()->ToPlayer()->SetClientControl(GetTarget(), 1);
//            GetTarget()->ToPlayer()->SetCanFly(false);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectApply += AuraEffectApplyFn(spell_teleport_to_rift::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
//        OnEffectRemove += AuraEffectRemoveFn(spell_teleport_to_rift::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
//void AddSC_xavius()
//{
//    RegisterCreatureAI(boss_xavius);
//    RegisterCreatureAI(npc_xavius_sleeping_version);
//    RegisterCreatureAI(npc_xavius_dread_abomination);
//    RegisterCreatureAI(npc_xavius_lurking_terror);
//    RegisterCreatureAI(npc_xavius_corruption_horror);
//    RegisterCreatureAI(npc_xavius_nightmare_blades);
//    RegisterCreatureAI(npc_xavius_inconceivable_horror);
//    RegisterCreatureAI(npc_xavius_nightmare_tentacle);
//    RegisterCreatureAI(npc_xavius_event_conroller);
//    RegisterAuraScript(spell_xavius_periodic_energize);
//    RegisterAuraScript(spell_xavius_dream_simulacrum);
//    RegisterAuraScript(spell_xavius_nightmare_torment_alt_power);
//    RegisterSpellScript(spell_xavius_crushing_shadows);
//    RegisterAuraScript(spell_xavius_unfathomable_reality);
//    RegisterAuraScript(spell_xavius_descent_into_madness);
//    RegisterAuraScript(spell_xavius_darkening_soul);
//    RegisterAuraScript(spell_xavius_nightmare_blades);
//    RegisterSpellScript(spell_xavius_nightmare_blades_dmg_filter);
//    RegisterAuraScript(spell_xavius_bonds_of_terror);
//    RegisterSpellScript(spell_xavius_writhing_deep);
//    RegisterSpellScript(spell_xavius_corrupting_nova);
//    RegisterSpellScript(spell_xavius_corruption_meteor);
//    RegisterAuraScript(spell_teleport_to_rift);}

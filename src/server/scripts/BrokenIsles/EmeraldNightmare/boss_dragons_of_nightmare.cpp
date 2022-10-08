/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "CreatureGroups.h"
#include "ScriptMgr.h"
#include "emerald_nightmare.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_CALL = 1,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_EMPTY_ENERGY = 205283, //224200, 203909, 204719?
    SPELL_ENERGIZE_UP = 205284,
    SPELL_REMOVE_MARK_TAERAR = 224627,
    SPELL_REMOVE_MARK_LETHON = 224626,
    SPELL_REMOVE_MARK_EMERISS = 224625,
    SPELL_NIGHTMARE_BOND = 203966, //Share damage. 203969
    SPELL_CORRUPTED_BREATH = 203028,
    SPELL_TAIL_LASH = 204119,
    SPELL_ENERGIZE_DRAGONS = 205281,
    SPELL_SLUMBERING_NIGHTMARE = 203110,

    //Ysondre - 102679
    SPELL_MARK_OF_YSONDRE = 203083,
    SPELL_ENERGIZE_YSONDRE = 205282,
    SPELL_NIGHTMARE_BLAST = 203147,
    SPELL_CALL_DEFILED_SPIRIT = 207573,

    //Taerar - 102681
    SPELL_MARK_OF_TAERAR = 203085,
    SPELL_SHADES_OF_TAERAR = 204100,
    SPELL_SEEPING_FOG = 205331,
    SPELL_BELLOWING_ROAR_AURA = 205172, //Heroic+
    SPELL_BELLOWING_ROAR = 204078,

    //Lethon - 102682
    SPELL_MARK_OF_LETHON = 203086,
    SPELL_SIPHON_SPIRIT = 203888,
    SPELL_SIPHON_SPIRIT_SUM = 203837,
    SPELL_DARK_OFFERING_LETHON = 203896,
    SPELL_DARK_OFFERING_YSONDRE = 203897,
    SPELL_GLOOM_AURA = 206758,
    SPELL_SHADOW_BURST = 204030, //Heroic+

    //Emeriss - 102683
    SPELL_MARK_OF_EMERISS = 203084,
    SPELL_NIGHTMARE_ENERGY = 224200,
    SPELL_GROUNDED = 204719,
    SPELL_VOLATILE_INFECTION = 203787,
    SPELL_ESSENCE_OF_CORRUPTION = 205298,

    //Nightmare Bloom - 102804
    SPELL_NIGHTMARE_BLOOM_VISUAL = 203672,
    SPELL_NIGHTMARE_BLOOM_DUMMY = 205945,
    SPELL_NIGHTMARE_BLOOM_DUMMY_2 = 207681,
    SPELL_NIGHTMARE_BLOOM_DUMMY_3 = 220938,
    SPELL_NIGHTMARE_BLOOM_DUMMY_4 = 211497,
    SPELL_NIGHTMARE_BLOOM_AT = 203687,
    SPELL_NIGHTMARE_BLOOM_PERIODIC = 205278,

    //Defiled Druid Spirit - 103080
    SPELL_DEFILED_SPIRIT_ROOT = 203768,
    SPELL_DEFILED_ERUPTION = 203771,

    //Essence of Corruption - 103691
    SPELL_CORRUPTION = 205300,

    //Shade of Taerar - 103145
    SPELL_NIGHTMARE_VISAGE = 204084,
    SPELL_CORRUPTED_BREATH_2 = 204767,
    SPELL_TAIL_LASH_2 = 204768,

    //Dread Horror - 103044
    SPELL_WASTING_DREAD_AT = 204729, //Heroic
    SPELL_UNRELENTING = 221419, //Mythic. Нужна инфа с офа, как часто использует эту способность. Пока что раз в 10 секунд.

    //Corrupted Mushroom
    SPELL_CORRUPTED_BURST_4 = 203817,
    SPELL_CORRUPTED_BURST_7 = 203827,
    SPELL_CORRUPTED_BURST_10 = 203828,
};

enum eEvents
{
    EVENT_CORRUPTED_BREATH = 1,

    //Ysondre
    EVENT_SWITCH_DRAGONS = 2,
    EVENT_NIGHTMARE_BLAST = 3,
    EVENT_CALL_DEFILED_SPIRIT = 4,

    //Taerar
    EVENT_SHADES_OF_TAERAR = 5,
    EVENT_SEEPING_FOG = 6,

    //Emeriss
    EVENT_VOLATILE_INFECTION = 7,
    EVENT_ESSENCE_OF_CORRUPTION = 8,

    //Lethon
    EVENT_SIPHON_SPIRIT = 9,
    EVENT_SHADOW_BURST = 10, //Heroic+

    //Mythic
    EVENT_TAIL_LASH = 11,
};

Position const dragonPos[5] =
{
    {617.51f, -12807.0f,  4.84f, 3.39f},
    {674.78f, -12875.5f, 42.21f, 2.91f},
    {623.48f, -12845.71f, 4.13f, 2.47f},
    //Mythic
    {681.84f, -12869.25f, 43.62f, 2.74f},
    {662.45f, -12893.78f, 43.62f, 2.31f}
};

//102679
struct boss_dragon_ysondre : public BossAI
{
    boss_dragon_ysondre(Creature* creature) : BossAI(creature, DATA_DRAGON_NIGHTMARE)
    {
     //   group_member = sFormationMgr->CreateCustomFormation(me);
        helpersList = { NPC_TAERAR, NPC_LETHON, NPC_EMERISS };
        Trinity::Containers::RandomResize(helpersList, IsMythic() ? 3 : 2);
    }

    std::vector<uint32> helpersList;
    FormationInfo* group_member;
    uint8 eventPhaseHP;
    bool introDone = false;

    void Reset() override
    {
        _Reset();
        DoCast(me, SPELL_EMPTY_ENERGY, true);
        eventPhaseHP = 71;

        me->GetMotionMaster()->MoveIdle();
        me->NearTeleportTo(me->GetHomePosition());

        if (auto dragon = me->SummonCreature(helpersList[0], dragonPos[0]))
            if (CreatureGroup* f = me->GetFormation())
               // f->AddMember(dragon, group_member);

        if (IsMythic())
        {
            for (uint8 i = 0; i < 2; ++i)
                if (auto dragon = me->SummonCreature(helpersList[1 + i], dragonPos[3 + i]))
                {
                    dragon->SetReactState(REACT_PASSIVE);
                   // dragon->AI()->SetFlyMode(true);
                    dragon->SetVisible(false);
                }
        }
        else
        {
            if (auto dragon = me->SummonCreature(helpersList[1], dragonPos[1]))
            {
                dragon->SetReactState(REACT_PASSIVE);
            //    dragon->AI()->SetFlyMode(true);
                dragon->SetVisible(false);
            }
        }

        DespawnTrash();
    }

    void EnterCombat(Unit* who) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        DoCast(me, SPELL_ENERGIZE_YSONDRE, true);
        DoCast(me, SPELL_MARK_OF_YSONDRE, true);

        events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 16000);
        events.RescheduleEvent(EVENT_SWITCH_DRAGONS, 1000);
        events.RescheduleEvent(EVENT_NIGHTMARE_BLAST, 40000);

        if (IsMythic())
            events.RescheduleEvent(EVENT_TAIL_LASH, 5000);

      //  DoActionSummon(helpersList[0], ACTION_3);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (!introDone && me->IsWithinDistInMap(who, 150.0f))
        {
            introDone = true;
         //   who->CreateConversation(3608);
        }
        BossAI::MoveInLineOfSight(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DespawnTrash();
        Talk(SAY_DEATH);
    }

    void DespawnTrash()
    {
        std::list<Creature*> creList;
        GetCreatureListWithEntryInGrid(creList, me, NPC_NIGHTMARE_BLOOM, 120.0f);
        GetCreatureListWithEntryInGrid(creList, me, NPC_ESSENCE_OF_CORRUPTION, 120.0f);
        GetCreatureListWithEntryInGrid(creList, me, NPC_SHADE_OF_TAERAR, 120.0f);
        GetCreatureListWithEntryInGrid(creList, me, NPC_SEEPING_FOG, 120.0f);
        GetCreatureListWithEntryInGrid(creList, me, NPC_SPIRIT_SHADE, 120.0f);
        GetCreatureListWithEntryInGrid(creList, me, NPC_DREAD_HORROR, 120.0f);
        for (auto const& trash : creList)
        {
            if (trash && trash->IsInWorld())
                trash->DespawnOrUnsummon();
        }
    }

/*    void DoAction(int32 const action, Creature* caller) //override
    {
        switch (action)
        {
        case 1:
            if (auto f = me->GetFormation())
              //  f->AddMember(caller, group_member);
            break;
        case 2:
            if (auto f = me->GetFormation())
                f->RemoveMember(caller);
            break;
        case 4: //Special Attack
            events.RescheduleEvent(EVENT_CALL_DEFILED_SPIRIT, 100);
            break;
        }
    }*/

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

     //   if (CheckHomeDistToEvade(diff, 100.0f, 576.33f, -12813.32f, 6.17f))
        //    return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CORRUPTED_BREATH:
                DoCastVictim(SPELL_CORRUPTED_BREATH);
                events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 32000);
                break;
            case EVENT_SWITCH_DRAGONS:
                if (me->HealthBelowPct(eventPhaseHP))
                {
                    if (eventPhaseHP > 41)
                    {
                        eventPhaseHP = 41;
                        EntryCheckPredicate pred0(helpersList[0]);
                        summons.DoAction(1, pred0);
                        EntryCheckPredicate pred1(helpersList[1]);
                        summons.DoAction(2, pred1);
                    }
                    else
                    {
                        eventPhaseHP = 0;
                        if (IsMythic())
                        {
                            EntryCheckPredicate pred0(helpersList[1]);
                            summons.DoAction(1, pred0);
                            EntryCheckPredicate pred1(helpersList[2]);
                            summons.DoAction(2, pred1);
                        }
                        else
                        {
                            EntryCheckPredicate pred0(helpersList[0]);
                            summons.DoAction(2, pred0);
                            EntryCheckPredicate pred1(helpersList[1]);
                            summons.DoAction(1, pred1);
                        }
                        break;
                    }
                }
                events.RescheduleEvent(EVENT_SWITCH_DRAGONS, 1000);
                break;
            case EVENT_NIGHTMARE_BLAST:
                DoCast(SPELL_NIGHTMARE_BLAST);
                events.RescheduleEvent(EVENT_NIGHTMARE_BLAST, 15000);
                break;
            case EVENT_CALL_DEFILED_SPIRIT:
                Talk(SAY_CALL);
                DoCast(SPELL_CALL_DEFILED_SPIRIT);
                break;
            case EVENT_TAIL_LASH:
                DoCast(SPELL_TAIL_LASH);
                events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//102681
struct boss_dragon_taerar : public ScriptedAI
{
    boss_dragon_taerar(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetSpeed(MOVE_FLIGHT, 2.0f);
    }

    InstanceScript* instance;
    EventMap events;

    void Reset() override
    {
        me->SetMaxPower(POWER_ENERGY, 100);
        DoCast(me, SPELL_EMPTY_ENERGY, true);
    }

    void EnterCombat(Unit* who) override
    {
        DoCast(me, SPELL_ENERGIZE_UP, true);
        Talk(SAY_AGGRO);
        DoZoneInCombat(me, 150.0f);
    }

    void DefaultEvents()
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->RemoveAurasDueToSpell(SPELL_BELLOWING_ROAR_AURA);
        DoCast(me, SPELL_MARK_OF_TAERAR, true);
        DoCast(me, SPELL_ENERGIZE_DRAGONS, true);
        events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 16000);
        events.RescheduleEvent(EVENT_SEEPING_FOG, 26000);

        if (IsMythic())
            events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
    }

    void JustDied(Unit* /*killer*/) override {}

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case 1:
            if (auto owner = me->GetOwner())
                owner->GetAI()->DoAction(2); //Leave group
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
          //  SetFlyMode(true);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->RemoveAurasDueToSpell(SPELL_MARK_OF_TAERAR);
            me->RemoveAurasDueToSpell(SPELL_ENERGIZE_DRAGONS);
            me->GetMotionMaster()->MovePoint(1, dragonPos[1].GetPosition(), false);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;
        case 2:
            me->SetVisible(true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->GetMotionMaster()->MovePoint(2, dragonPos[2].GetPosition(), false);
            //No break!
        case 3:
            DefaultEvents();
            break;
        case 4: //Special Attack
            events.RescheduleEvent(EVENT_SHADES_OF_TAERAR, 100);
            break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->SetFacingTo(2.47f);

            if (IsHeroic())
                DoCast(me, SPELL_BELLOWING_ROAR_AURA, true);
        }
        else if (id == 2)
        {
           // SetFlyMode(false);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat(me, 150.0f);
            if (auto owner = me->GetOwner())
            {
                me->SetHealth(owner->GetHealth());
                owner->GetAI()->DoAction(1); //Invite group
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

       // if (me->GetReactState() == REACT_AGGRESSIVE && CheckHomeDistToEvade(diff, 100.0f, 576.33f, -12813.32f, 6.17f))
        {
            if (auto owner = me->GetOwner())
                if (auto summoner = owner->ToCreature())
                    if (summoner->IsInCombat())
                        summoner->AI()->EnterEvadeMode();
            return;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CORRUPTED_BREATH:
                DoCastVictim(SPELL_CORRUPTED_BREATH);
                events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 32000);
                break;
            case EVENT_SHADES_OF_TAERAR:
                DoCast(SPELL_SHADES_OF_TAERAR);
                Talk(1);
                break;
            case EVENT_SEEPING_FOG:
                DoCast(me, SPELL_SEEPING_FOG, true);
                events.RescheduleEvent(EVENT_SEEPING_FOG, 16000);
                break;
            case EVENT_TAIL_LASH:
                DoCast(SPELL_TAIL_LASH);
                events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//102682
struct boss_dragon_lethon : public ScriptedAI
{
    boss_dragon_lethon(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetSpeed(MOVE_FLIGHT, 2.0f);
    }

    InstanceScript* instance;
    EventMap events;

    void Reset() override
    {
        me->SetMaxPower(POWER_ENERGY, 100);
        DoCast(me, SPELL_EMPTY_ENERGY, true);
    }

    void EnterCombat(Unit* who) override
    {
        DoCast(me, SPELL_ENERGIZE_UP, true);
        Talk(SAY_AGGRO);
        DoZoneInCombat(me, 150.0f);
    }

    void DefaultEvents()
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        DoCast(me, SPELL_MARK_OF_LETHON, true);
        DoCast(me, SPELL_ENERGIZE_DRAGONS, true);
        DoCast(me, SPELL_GLOOM_AURA, true);
        events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 16000);
        events.CancelEvent(EVENT_SHADOW_BURST);

        if (IsMythic())
            events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
    }

    void JustDied(Unit* /*killer*/) override {}

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case 1:
            if (auto owner = me->GetOwner())
                if (auto summoner = owner->ToCreature())
                    summoner->AI()->DoAction(2); //Leave group
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
           // SetFlyMode(true);
            me->RemoveAurasDueToSpell(SPELL_MARK_OF_LETHON);
            me->RemoveAurasDueToSpell(SPELL_ENERGIZE_DRAGONS);
            me->RemoveAurasDueToSpell(SPELL_GLOOM_AURA);
            me->GetMotionMaster()->MovePoint(1, dragonPos[1].GetPosition(), false);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;
        case 2:
            me->SetVisible(true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->GetMotionMaster()->MovePoint(2, dragonPos[2].GetPosition(), false);
            //No break!
        case 3:
            DefaultEvents();
            break;
        case 4: //Special Attack
            events.RescheduleEvent(EVENT_SIPHON_SPIRIT, 100);
            break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->SetFacingTo(2.47f);

            if (IsHeroic())
                events.RescheduleEvent(EVENT_SHADOW_BURST, 15000);
        }
        else if (id == 2)
        {
           // SetFlyMode(false);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat(me, 150.0f);
            if (auto owner = me->GetOwner())
            {
                me->SetHealth(owner->GetHealth());
                owner->GetAI()->DoAction(1); //Invite group
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

     //   if (me->GetReactState() == REACT_AGGRESSIVE && CheckHomeDistToEvade(diff, 100.0f, 576.33f, -12813.32f, 6.17f))
        {
            if (auto owner = me->GetOwner()->ToCreature())
                if (owner && owner->IsInCombat())
                    owner->AI()->EnterEvadeMode();
            return;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CORRUPTED_BREATH:
                DoCastVictim(SPELL_CORRUPTED_BREATH);
                events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 32000);
                break;
            case EVENT_SIPHON_SPIRIT:
                DoCast(SPELL_SIPHON_SPIRIT);
                Talk(1);
                Talk(2);
                break;
            case EVENT_SHADOW_BURST:
                DoCast(me, SPELL_SHADOW_BURST, true);
                events.RescheduleEvent(EVENT_SHADOW_BURST, 15000);
                break;
            case EVENT_TAIL_LASH:
                DoCast(SPELL_TAIL_LASH);
                events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//102683
struct boss_dragon_emeriss : public ScriptedAI
{
    boss_dragon_emeriss(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetSpeed(MOVE_FLIGHT, 2.0f);
    }

    InstanceScript* instance;
    EventMap events;

    void Reset() override
    {
        me->SetMaxPower(POWER_ENERGY, 100);
        DoCast(me, SPELL_EMPTY_ENERGY, true);
        DoCast(me, SPELL_NIGHTMARE_ENERGY, true);
    }

    void EnterCombat(Unit* who) override
    {
        DoCast(me, SPELL_ENERGIZE_UP, true);
        Talk(SAY_AGGRO);
        DoZoneInCombat(me, 150.0f);
    }

    void DefaultEvents()
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        DoCast(me, SPELL_MARK_OF_EMERISS, true);
        DoCast(me, SPELL_ENERGIZE_DRAGONS, true);
        events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 16000);
        events.RescheduleEvent(EVENT_ESSENCE_OF_CORRUPTION, 30000);

        if (IsMythic())
            events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
    }

    void JustDied(Unit* /*killer*/) override {}

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case 1:
            if (auto owner = me->GetOwner())
                owner->GetAI()->DoAction(2); //Leave group
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
           // SetFlyMode(true);
            me->RemoveAurasDueToSpell(SPELL_MARK_OF_EMERISS);
            me->RemoveAurasDueToSpell(SPELL_ENERGIZE_DRAGONS);
            me->GetMotionMaster()->MovePoint(1, dragonPos[1].GetPosition(), false);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            break;
        case 2:
            me->SetVisible(true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->GetMotionMaster()->MovePoint(2, dragonPos[2].GetPosition(), false);
            //No break!
        case 3:
            DefaultEvents();
            break;
        case 4: //Special Attack
            events.RescheduleEvent(EVENT_VOLATILE_INFECTION, 100);
            break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            me->SetFacingTo(2.47f);
        }
        else if (id == 2)
        {
          //  SetFlyMode(false);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat(me, 150.0f);
            if (auto owner = me->GetOwner())
            {
                me->SetHealth(owner->GetHealth());
                owner->GetAI()->DoAction(1); //Invite group
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

      //  if (me->GetReactState() == REACT_AGGRESSIVE && CheckHomeDistToEvade(diff, 100.0f, 576.33f, -12813.32f, 6.17f))
        {
            if (auto owner = me->GetOwner())
                if (auto summoner = owner->ToCreature())
                    if (summoner->IsInCombat())
                        summoner->AI()->EnterEvadeMode();
            return;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_CORRUPTED_BREATH:
                DoCastVictim(SPELL_CORRUPTED_BREATH);
                events.RescheduleEvent(EVENT_CORRUPTED_BREATH, 32000);
                break;
            case EVENT_VOLATILE_INFECTION:
                DoCast(me, SPELL_VOLATILE_INFECTION, true);
                break;
            case EVENT_ESSENCE_OF_CORRUPTION:
                DoCast(me, SPELL_ESSENCE_OF_CORRUPTION, true);
                events.RescheduleEvent(EVENT_ESSENCE_OF_CORRUPTION, 30000);
                break;
            case EVENT_TAIL_LASH:
                DoCast(SPELL_TAIL_LASH);
                events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//102804
struct npc_ysondre_nightmare_bloom : public ScriptedAI
{
    npc_ysondre_nightmare_bloom(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    uint32 despawnTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_NIGHTMARE_BLOOM_VISUAL, true);
        DoCast(me, SPELL_NIGHTMARE_BLOOM_DUMMY, true);
        DoCast(me, SPELL_NIGHTMARE_BLOOM_AT, true);
        DoCast(me, SPELL_NIGHTMARE_BLOOM_PERIODIC, true);

        uint8 playerCount = me->GetMap()->GetPlayersCountExceptGMs();

        if (IsMythic())
            despawnTimer = 30000;
        else if (playerCount < 20)
            despawnTimer = 20000;
        else if (playerCount >= 20 && playerCount <= 30)
            despawnTimer = 40000;
    }

    void UpdateAI(uint32 diff) override
    {
        if (despawnTimer)
        {
            if (despawnTimer <= diff)
            {
                despawnTimer = 0;
                me->DespawnOrUnsummon(100);
            }
            else
                despawnTimer -= diff;
        }
    }
};

//103080
struct npc_ysondre_defiled_druid_spirit : public ScriptedAI
{
    npc_ysondre_defiled_druid_spirit(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    uint16 explodeTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        explodeTimer = 500;
        DoCast(me, SPELL_DEFILED_SPIRIT_ROOT, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (explodeTimer)
        {
            if (explodeTimer <= diff)
            {
                explodeTimer = 0;
                me->DespawnOrUnsummon(8000);
                DoCast(SPELL_DEFILED_ERUPTION);
            }
            else
                explodeTimer -= diff;
        }
    }
};

//103145
struct npc_ysondre_shade_of_taerar : public ScriptedAI
{
    npc_ysondre_shade_of_taerar(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_NIGHTMARE_VISAGE, true); //Scale
        DoZoneInCombat(me, 150.0f);
        events.RescheduleEvent(1, 5000);
        if (IsMythic())
            events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                DoCastVictim(SPELL_CORRUPTED_BREATH_2);
                events.RescheduleEvent(1, 30000);
                break;
            case EVENT_TAIL_LASH:
                DoCast(SPELL_TAIL_LASH_2);
                events.RescheduleEvent(EVENT_TAIL_LASH, 5000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//103100
struct npc_ysondre_spirit_shade : public ScriptedAI
{
    npc_ysondre_spirit_shade(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetSpeed(MOVE_RUN, 0.5f);
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    InstanceScript* instance;
    bool despawn = false;
    uint16 moveTimer = 0;
    uint16 checkBossStateTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        moveTimer = 500;
        checkBossStateTimer = 1000;

        summoner->CastSpell(me, 203840, true); //Clone Player
        DoCast(me, 203950, true); //Mod Scale
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            if (auto lethon = instance->instance->GetCreature(instance->GetGuidData(NPC_LETHON)))
            {
                if (me->GetDistance(lethon) < 5.0f)
                {
                    if (!despawn)
                    {
                        despawn = true;
                        moveTimer = 0;
                        me->CastSpell(me, SPELL_DARK_OFFERING_LETHON, true);
                        me->CastSpell(me, SPELL_DARK_OFFERING_YSONDRE, true);
                        me->GetMotionMaster()->Clear();
                        me->DespawnOrUnsummon(1000);
                    }
                }
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkBossStateTimer)
        {
            if (checkBossStateTimer <= diff)
            {
                checkBossStateTimer = 1000;

                if (instance->GetBossState(DATA_DRAGON_NIGHTMARE) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }
                if (auto lethon = instance->instance->GetCreature(instance->GetGuidData(NPC_LETHON)))
                {
                    //if (lethon->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1))
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }
                }
            }
            else
                checkBossStateTimer -= diff;
        }

        if (moveTimer)
        {
            if (moveTimer <= diff)
            {
                moveTimer = 2000;

                if (!me->HasUnitState(UNIT_STATE_STUNNED))
                {
                    if (auto lethon = instance->instance->GetCreature(instance->GetGuidData(NPC_LETHON)))
                        me->GetMotionMaster()->MovePoint(1, lethon->GetPosition());
                }
            }
            else
                moveTimer -= diff;
        }
    }
};

//103044
struct npc_ysondre_dread_horror : public ScriptedAI
{
    npc_ysondre_dread_horror(Creature* creature) : ScriptedAI(creature) {}

    uint16 unrelentingTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        if (IsHeroic())
        {
            DoCast(me, SPELL_WASTING_DREAD_AT, true);

            if (IsMythic())
                unrelentingTimer = 10000;
        }

        DoZoneInCombat(me, 100.0f);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (unrelentingTimer)
        {
            if (unrelentingTimer <= diff)
            {
                unrelentingTimer = 10000;
                DoCast(me, SPELL_UNRELENTING, true);
            }
            else
                unrelentingTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

//103095, 103096, 103097
struct npc_ysondre_corrupted_mushroom : public ScriptedAI
{
    npc_ysondre_corrupted_mushroom(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
    }

    EventMap events;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        switch (me->GetEntry())
        {
        case NPC_CORRUPTED_MUSHROOM_SMALL:
            events.RescheduleEvent(1, 500);
            break;
        case NPC_CORRUPTED_MUSHROOM_MEDIUM:
            events.RescheduleEvent(2, 500);
            break;
        case NPC_CORRUPTED_MUSHROOM_BIG:
            events.RescheduleEvent(3, 500);
            break;
        }
        events.RescheduleEvent(4, 5000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                DoCast(me, SPELL_CORRUPTED_BURST_4, false);
                break;
            case 2:
                DoCast(me, SPELL_CORRUPTED_BURST_7, false);
                break;
            case 3:
                DoCast(me, SPELL_CORRUPTED_BURST_10, false);
                break;
            case 4:
                me->DespawnOrUnsummon(100);
                break;
            }
        }
    }
};

//111852
struct npc_en_rothos : public ScriptedAI
{
    npc_en_rothos(Creature* creature) : ScriptedAI(creature)
    {
      //  SetFlyMode(true);
    }

    EventMap events;

    void DespawnTrash()
    {
        std::list<Creature*> creatureList;
        me->GetCreatureListWithEntryInGrid(creatureList, 113214, 100.0f);
        for (auto trash : creatureList)
            trash->DespawnOrUnsummon();
    }

    void Reset() override
    {
        events.Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        DespawnTrash();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
       // SetFlyMode(true);
        ScriptedAI::EnterEvadeMode();
        me->NearTeleportTo(me->GetHomePosition());
        DespawnTrash();
    }

    void EnterCombat(Unit* /*who*/) override
    {
       // SetFlyMode(false);
        me->SetReactState(REACT_PASSIVE);
        me->SetReactState(REACT_AGGRESSIVE);
        events.RescheduleEvent(1, 8000);
        events.RescheduleEvent(2, 12000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                DoCastVictim(223697);
                events.RescheduleEvent(1, 15000);
                break;
            case 2:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(target, 223735);
                events.RescheduleEvent(2, 12000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//205281, 205282
class spell_ysondre_periodic_energize : public AuraScript
{
    PrepareAuraScript(spell_ysondre_periodic_energize);

    bool fullPower = false;

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsInCombat())
            return;

        uint8 powerCount = caster->GetPower(POWER_ENERGY);

        if (powerCount < 100)
        {
            caster->SetPower(POWER_ENERGY, powerCount + 2);
            if (fullPower)
                fullPower = false;
        }
        else
        {
            if (!fullPower)
            {
                fullPower = true;

                if (GetCaster()->GetEntry() == NPC_YSONDRE)
                    caster->AI()->DoAction(4);
                else
                    caster->AI()->DoAction(4);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ysondre_periodic_energize::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//203102,203121,203124,203125
class spell_ysondre_marks : public AuraScript
{
    PrepareAuraScript(spell_ysondre_marks);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget())
            return;

     //   if (auto aura = aurEff->GetBase())
        //    if (aura->GetStackAmount() == 10)
                GetTarget()->CastSpell(GetTarget(), SPELL_SLUMBERING_NIGHTMARE, true);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_ysondre_marks::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAPPLY);
    }
};

//203110
class spell_ysondre_slumbering_nightmare : public AuraScript
{
    PrepareAuraScript(spell_ysondre_slumbering_nightmare);

    void CalculateMaxDuration(int32& duration)
    {
        if (!GetCaster())
            return;

        if (GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_LFR)
            duration = 10000;
        else
            duration = 30000;
    }

    void Register() override
    {
     //   DoCalcMaxDuration += AuraCalcMaxDurationFn(spell_ysondre_slumbering_nightmare::CalculateMaxDuration);
    }
};

//203686
class spell_ysondre_nightmare_bloom : public SpellScript
{
    PrepareSpellScript(spell_ysondre_nightmare_bloom);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (GetCaster() && targets.empty())
            if (auto owner = GetCaster()->GetOwner())
                GetCaster()->CastSpell(GetCaster(), 203667, true, 0, 0, owner->GetGUID());
    }

    void HandleOnHit()
    {
        if (GetCaster() && GetHitUnit())
            GetCaster()->CastSpell(GetHitUnit(), 203690, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ysondre_nightmare_bloom::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnHit += SpellHitFn(spell_ysondre_nightmare_bloom::HandleOnHit);
    }
};

//204044
class spell_ysondre_shadow_burst_filter : public SpellScript
{
    PrepareSpellScript(spell_ysondre_shadow_burst_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
      //  if (GetCaster())
           // targets.sort(Trinity::UnitSortDistance(true, GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ysondre_shadow_burst_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ysondre_shadow_burst_filter::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

//204040
class spell_ysondre_shadow_burst : public AuraScript
{
    PrepareAuraScript(spell_ysondre_shadow_burst);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
     //   if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
       //     return;

        GetTarget()->CastSpell(GetTarget(), 204044, true, 0, 0, GetCaster()->GetGUID());
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_ysondre_shadow_burst::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//205172
class spell_ysondre_bellowing_roar : public AuraScript
{
    PrepareAuraScript(spell_ysondre_bellowing_roar);

        void OnPeriodic(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        //GetCaster()->AI()->Talk();
        GetCaster()->CastSpell(GetCaster(), SPELL_BELLOWING_ROAR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ysondre_bellowing_roar::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//203888
class spell_ysondre_siphon_spirit_filter : public SpellScript
{
    PrepareSpellScript(spell_ysondre_siphon_spirit_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

       // targets.sort(Trinity::UnitSortDistance(false, GetCaster()));

        if (GetCaster()->GetMap()->IsMythic())
        {
            if (targets.size() > 6)
                targets.resize(6);
        }
        else
        {
            uint32 playerCount = GetCaster()->GetMap()->GetPlayersCountExceptGMs() / 5 + 1;

            if (targets.size() > playerCount)
                targets.resize(playerCount);
        }

        for (auto object : targets)
        {
            if (auto target = object->ToUnit())
                target->CastSpell(target, SPELL_SIPHON_SPIRIT_SUM, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ysondre_siphon_spirit_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_dragons_of_nightmare()
{
    RegisterCreatureAI(boss_dragon_ysondre);
    RegisterCreatureAI(boss_dragon_taerar);
    RegisterCreatureAI(boss_dragon_lethon);
    RegisterCreatureAI(boss_dragon_emeriss);
    RegisterCreatureAI(npc_ysondre_nightmare_bloom);
    RegisterCreatureAI(npc_ysondre_defiled_druid_spirit);
    RegisterCreatureAI(npc_ysondre_shade_of_taerar);
    RegisterCreatureAI(npc_ysondre_spirit_shade);
    RegisterCreatureAI(npc_ysondre_dread_horror);
    RegisterCreatureAI(npc_ysondre_corrupted_mushroom);
    RegisterCreatureAI(npc_en_rothos);
    RegisterSpellScript(spell_ysondre_shadow_burst_filter);
    RegisterAuraScript(spell_ysondre_shadow_burst);
    RegisterAuraScript(spell_ysondre_periodic_energize);
    RegisterAuraScript(spell_ysondre_marks);
    RegisterAuraScript(spell_ysondre_slumbering_nightmare);
    RegisterSpellScript(spell_ysondre_nightmare_bloom);
    RegisterAuraScript(spell_ysondre_bellowing_roar);
    RegisterSpellScript(spell_ysondre_siphon_spirit_filter);
}

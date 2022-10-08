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

#include "ScriptMgr.h"
#include "CreatureGroups.h"
#include "emerald_nightmare.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_ANNOUNCE = 4,
    SAY_EVADE = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    //ilgynoth
    SPELL_DARK_RECONSTITUTION = 210781,
    SPELL_FINAL_TORPOR = 223121,
    SPELL_CURSED_BLOOD = 215128,
    SPELL_CURSED_BLOOD_EXPLOSION = 215143,
    SPELL_DARKEST_NIGHTMARE_AT = 210786,
    SPELL_KNOCKBACK_AT = 224929,
    SPELL_RECOVERY_TELEPORT = 222531,
    SPELL_KILL_WHISPER = 222173, //? Il'gynoth Kill Whisper

    //Eye ilgynoth
    SPELL_NIGHTMARE_GAZE = 210931,
    SPELL_SUM_NIGHTMARE_HORROR = 210289,

    //Mythic
    SPELL_DEATH_BLOSSOM = 218415, //Remove AT cast
    SPELL_DEATH_BLOSSOM_AT = 215761,
    SPELL_DEATH_BLOSSOM_VISUAL = 215763,
    SPELL_DEATH_BLOSSOM_DMG = 215836,
    SPELL_DISPERSED_SPORES = 215845,
    SPELL_VIOLENT_BLOODBURST = 215971,
    SPELL_VIOLENT_BLOODBURST_AT = 215975,
    SPELL_SUM_SHRIVELED_EYESTALK = 216131,

    //Dominator Tentacle - 105304
    SPELL_NIGHTMARISH_FURY = 215234,
    SPELL_GROUND_SLAM_DMG = 208689,
    SPELL_GROUND_SLAM_VISUAL = 212723,
    SPELL_RUPTURING_ROAR = 208685,

    //Deathglare Tentacle - 105322
    SPELL_MIND_FLAY = 208697,

    //Corruptor Tentacle - 105383
    SPELL_SPEW_CORRUPTION = 208928,

    //Nightmare Horror - 105591
    SPELL_SEEPING_CORRUPTION = 209387,
    SPELL_EYE_OF_FATE = 210984,

    //Nightmare Ichor - 105721
    SPELL_FIXATE = 210099,
    SPELL_NIGHTMARE_EXPLOSION = 209471,
    SPELL_NIGHTMARE_EXPLOSION_PCT = 210048,
    SPELL_REABSORPTION = 212942,

    //Other
    SPELL_SPAWN_BLOOD = 209965,
};

enum eEvents
{
    EVENT_SUMMON_1 = 1,
    EVENT_SUMMON_2 = 2,
    EVENT_SUMMON_3 = 3,
    EVENT_SUMMON_4 = 4,
    EVENT_SUMMON_5 = 5,
    EVENT_SUMMON_6 = 6,
    EVENT_SUMMON_7 = 7,
    EVENT_DARK_RECONSTITUTION = 8,
    EVENT_CURSED_BLOOD = 9,
    EVENT_EYE_RESPAWN = 10,
    EVENT_ANNOUNCE = 11,
    EVENT_ANNOUNCE_FINAL = 12,
    EVENT_CHECK_TARGET_DISTANCE = 13,

    //Mythic
    EVENT_SUM_SHRIVELED_EYESTALK,
    EVENT_DEATH_BLOSSOM
};

Position const sumPos[4] =
{
    {-12818.1f, 12328.3f, -245.72f, 3.79f}, //105906 - Eye of Ilgynoth
    {-12843.59f, 12331.40f, -246.01f, 3.56f},
    {-12821.79f, 12302.79f, -246.01f, 3.83f},
    {-12856.12f, 12296.79f, -253.16f, 0.72f} //Horror
};

Position const blossPos[22] =
{
    {-12843.5f, 12321.6f, -250.77f},
    {-12840.4f, 12297.1f, -251.92f},
    {-12822.7f, 12281.8f, -250.72f},
    {-12832.5f, 12290.1f, -251.82f},
    {-12848.9f, 12327.6f, -250.40f},
    {-12837.4f, 12314.9f, -250.81f},
    {-12831.4f, 12308.4f, -250.07f},
    {-12824.1f, 12300.7f, -248.79f},
    {-12814.5f, 12290.5f, -248.35f},
    {-12848.0f, 12303.3f, -252.25f},
    {-12854.7f, 12310.2f, -252.30f},
    {-12861.6f, 12319.4f, -252.85f},
    {-12852.3f, 12319.2f, -251.93f},
    {-12844.8f, 12311.6f, -251.94f},
    {-12839.7f, 12305.9f, -251.59f},
    {-12831.2f, 12298.9f, -250.53f},
    {-12823.5f, 12291.4f, -249.49f},
    {-12830.6f, 12277.5f, -252.17f},
    {-12842.2f, 12285.1f, -253.12f},
    {-12852.0f, 12290.9f, -253.25f},
    {-12858.0f, 12298.5f, -253.22f},
    {-12864.3f, 12307.0f, -253.70f}
};

//105393
struct boss_ilgynoth : public BossAI
{
    boss_ilgynoth(Creature* creature) : BossAI(creature, DATA_ILGYNOTH), summons(me)
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
    }

    SummonList summons;
    FormationInfo* group_member = nullptr;
    bool specialPhase = false;
    bool finalTorpor = false;
    uint8 AnnText = 0;

    void Reset() override
    {
        _Reset();
        summons.DespawnAll();
        RemoveAT();
        CreateGroupAndSummonTrash();
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
        instance->SetData(DATA_EYE_ILGYNOTH, IN_PROGRESS);
        specialPhase = false;
        finalTorpor = false;
        DoCast(me, SPELL_KNOCKBACK_AT, true);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode();
        TeleportPlayer();
    }

    void CreateGroupAndSummonTrash()
    {
        if (group_member)
            sFormationMgr->RemoveCreatureFromGroup(me->GetFormation(), me);

    //    group_member = sFormationMgr->CreateCustomFormation(me);

        me->SummonCreature(NPC_EYE_OF_ILGYNOTH, sumPos[0]);
        me->SummonCreature(NPC_DOMINATOR_TENTACLE, sumPos[1]);
        me->SummonCreature(NPC_DOMINATOR_TENTACLE, sumPos[2]);
    }

    void RemoveAT()
    {
        std::list<AreaTrigger*> list;
     //   me->GetAreaTriggerListWithEntryInGrid(list, 11189, 150.0f); //Nightmare Corruption - 208931
      //  for (auto at : list)
          //  at->Despawn();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        me->SummonCreature(NPC_EYE_OF_ILGYNOTH, true);
        me->SummonCreature(NPC_DOMINATOR_TENTACLE, true);
        DoCast(me, SPELL_DARKEST_NIGHTMARE_AT, true);
        TeleportPlayer();
     //   TalkWhisper(SAY_AGGRO);

        events.RescheduleEvent(EVENT_SUMMON_1, 20000); //Sum Deathglare
        events.RescheduleEvent(EVENT_CHECK_TARGET_DISTANCE, 2000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        summons.DespawnAll();
        RemoveAT();
        instance->SetData(DATA_EYE_ILGYNOTH, DONE);
      //  TalkWhisper(SAY_DEATH);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
        case NPC_EYE_OF_ILGYNOTH:
        case NPC_DOMINATOR_TENTACLE:
            if (CreatureGroup* f = me->GetFormation())
              //  f->AddMember(summon, group_member);
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_EYE_OF_ILGYNOTH)
        {
            events.Reset();
            specialPhase = true;
            instance->SetData(DATA_EYE_ILGYNOTH, DONE);
         //   me->RemoveAreaObject(SPELL_DARKEST_NIGHTMARE_AT);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
            events.RescheduleEvent(EVENT_DARK_RECONSTITUTION, 10000);
            events.RescheduleEvent(EVENT_CURSED_BLOOD, 15000);

            if (GetDifficulty() == DIFFICULTY_MYTHIC_RAID)
            {
                if (finalTorpor)
                    events.RescheduleEvent(EVENT_SUM_SHRIVELED_EYESTALK, 16000);

                if (me->GetHealth() > me->CountPctFromMaxHealth(33))
                    me->SetHealth(me->GetHealth() - me->CountPctFromMaxHealth(33));
                else if (me->GetHealthPct() > 10)
                    me->SetHealth(me->CountPctFromMaxHealth(10));
            }
        }
    }

    void TeleportPlayer()
    {
        std::list<Player*> players;
        GetPlayerListInGrid(players, me, 25.0f);
        for (auto const& player : players)
            player->CastSpell(player, SPELL_RECOVERY_TELEPORT, true);
    }

    void SummomRandPos(uint8 count, uint32 entry)
    {
        for (uint8 i = 0; i < count; ++i)
        {
            uint8 rand = urand(1, 2);
//            float angle = frand(0.f, M_PI * 2.f);
         //   float x = sumPos[rand].GetPositionX() + (5.0f * std::cos(angle));
        //    float y = sumPos[rand].GetPositionY() + (5.0f * std::sin(angle));
         //   me->SummonCreature(entry, x, y, sumPos[rand].GetPositionZ());
        }
    }

  //  void TalkWhisper(uint8 text)
  //  {
        //instance->instance->ApplyOnEveryPlayer([&](Player* player)
      //  {
      //      Talk(text, player->GetGUID());
    //    });
 //   }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SUMMON_1:
                SummomRandPos(1, NPC_DEATHGLARE_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_2, 70000); //Next: 2 Corruptors
                break;
            case EVENT_SUMMON_2:
                SummomRandPos(2, NPC_CORRUPTOR_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_3, 6000); //Next: 2 Deathglare
                break;
            case EVENT_SUMMON_3:
                SummomRandPos(2, NPC_DEATHGLARE_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_4, 84000); //Next: 1 Deathglare
                break;
            case EVENT_SUMMON_4:
                SummomRandPos(1, NPC_DEATHGLARE_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_5, 4000); //Next: 2 Corruptors
                break;
            case EVENT_SUMMON_5:
                SummomRandPos(2, NPC_CORRUPTOR_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_6, 40000); //Next: 1 Corruptors
                break;
            case EVENT_SUMMON_6:
                SummomRandPos(1, NPC_CORRUPTOR_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_7, 15000); //Next: 1 Deathglare
                break;
            case EVENT_SUMMON_7:
                SummomRandPos(1, NPC_DEATHGLARE_TENTACLE);
                events.RescheduleEvent(EVENT_SUMMON_6, 30000); //Next: Нет инфы. Повторим?
                break;
            case EVENT_DARK_RECONSTITUTION:
              //  me->CastSpellDelay(me, SPELL_DARKEST_NIGHTMARE_AT, true, IsMythicRaid() ? 54000 : 49000);
                DoCast(finalTorpor ? SPELL_FINAL_TORPOR : SPELL_DARK_RECONSTITUTION);
                finalTorpor = true;
                events.RescheduleEvent(EVENT_ANNOUNCE_FINAL, 45000);
                events.RescheduleEvent(EVENT_EYE_RESPAWN, 51000);
                events.RescheduleEvent(EVENT_ANNOUNCE, 10000);
                AnnText = 1;
                break;
            case EVENT_CURSED_BLOOD:
                DoCast(me, SPELL_CURSED_BLOOD, true);
                events.RescheduleEvent(EVENT_CURSED_BLOOD, 15000);
                break;
            case EVENT_SUM_SHRIVELED_EYESTALK:
            {
                Position pos;
                float angle = 0.0f;
                for (uint8 i = 0; i < 6; ++i)
                {
                    angle += 1.0f;
                    me->GetNearPosition(20.0f, angle);
                    me->CastSpell(pos, SPELL_SUM_SHRIVELED_EYESTALK, true);
                }
                events.RescheduleEvent(EVENT_SUM_SHRIVELED_EYESTALK, 20000);
                break;
            }
            case EVENT_EYE_RESPAWN:
                events.Reset();
                instance->SetData(DATA_EYE_ILGYNOTH, IN_PROGRESS);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                me->SummonCreature(NPC_EYE_OF_ILGYNOTH, sumPos[0]);
                TeleportPlayer();
              //  TalkWhisper(SAY_EVADE);
                specialPhase = false;
                events.RescheduleEvent(EVENT_SUMMON_1, 20000); //Sum Deathglare
                events.RescheduleEvent(EVENT_CHECK_TARGET_DISTANCE, 2000);
                break;
            case EVENT_ANNOUNCE_FINAL:
                Talk(SAY_ANNOUNCE);
                break;
            case EVENT_ANNOUNCE:
               // TalkWhisper(AnnText);
                if (AnnText == 1)
                {
                    ++AnnText;
                    events.RescheduleEvent(EVENT_ANNOUNCE, 20000);
                }
                break;
            case EVENT_CHECK_TARGET_DISTANCE:
            {
                if (!specialPhase)
                    TeleportPlayer();

                bool closestPlayers = false;
                std::list<HostileReference*> threatlist = me->getThreatManager().getThreatList();
                for (auto ref : threatlist)
                {
                  //  if (auto target = me->GetUnit(*me, ref->getUnitGuid()))
                  //  {
                    //    if (me->GetDistance(target) < 150.0f)
                      //  {
                            closestPlayers = true;
                            break;
                        }
                    }
                }
              //  if (!closestPlayers)
             //   {
               //     EnterEvadeMode();
                 //   return;
              //  }
              //  events.RescheduleEvent(EVENT_CHECK_TARGET_DISTANCE, 2000);
               // break;
         //   }
         //   }
        }
    }
};

//105906
struct npc_eye_of_ilgynoth : public ScriptedAI
{
    npc_eye_of_ilgynoth(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        SetCombatMovement(false);
    }

    InstanceScript* instance;
    EventMap events;
    bool introDone = false;

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->IsInCombat())
        {
            DoZoneInCombat();
            DoAction(true);
        }
    }

    void Reset() override {}

    void EnterCombat(Unit* /*who*/) override
    {
        DoZoneInCombat();
        events.RescheduleEvent(1, 2000);
        events.RescheduleEvent(2, 65000); //Summon Nightmare Horror

        if (GetDifficulty() == DIFFICULTY_MYTHIC_RAID)
            events.RescheduleEvent(EVENT_DEATH_BLOSSOM, 60000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (!introDone && me->IsWithinDistInMap(who, 250.0f))
        {
            introDone = true;
           // Conversation* conversation = new Conversation;
          //  if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 3617, who, nullptr, who->GetPosition()))
           //     delete conversation;
        }
        ScriptedAI::MoveInLineOfSight(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DoAction(int32 const action) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
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
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 120.0f, true))
                {
                    DoResetThreat();
                    me->AddThreat(pTarget, 100000.0f);
                    DoCast(pTarget, SPELL_NIGHTMARE_GAZE);
                }
                events.RescheduleEvent(1, 2000);
                break;
            case 2:
                if (Unit* summoner = me->GetOwner())
                    if (Creature* horror = summoner->SummonCreature(NPC_NIGHTMARE_HORROR, sumPos[3]))
                    {
                        DoCast(horror, SPELL_SUM_NIGHTMARE_HORROR, true);
                        horror->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                    }
                Talk(0);
                events.RescheduleEvent(2, 3 * MINUTE * IN_MILLISECONDS + 40 * IN_MILLISECONDS); //3m40s
                break;
            case EVENT_DEATH_BLOSSOM:
                DoCast(SPELL_DEATH_BLOSSOM);
                if (auto summoner = me->GetOwner())
                {
                    std::list<uint8> randList;
                    for (uint8 i = 0; i < 22; ++i)
                        randList.push_back(i);

                    Trinity::Containers::RandomResize(randList, 10);

                    for (auto idx : randList)
                        if (auto blossom = summoner->SummonCreature(NPC_DEATH_BLOSSOM, blossPos[idx], TEMPSUMMON_TIMED_DESPAWN, 16000))
                        {
                            blossom->CastSpell(blossom, SPELL_DEATH_BLOSSOM_AT, true);
                            blossom->CastSpell(blossom, SPELL_DEATH_BLOSSOM_VISUAL, true);
                        }
                }
                events.RescheduleEvent(EVENT_DEATH_BLOSSOM, 100000); //1m40s
                break;
            }
        }
    }
};

//105304, 105322, 105383, 108821
struct npc_ilgynoth_tentacles : public ScriptedAI
{
    npc_ilgynoth_tentacles(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        SetCombatMovement(false);
    }

    InstanceScript* instance;
    EventMap events;
    uint8 bloodCount = 0;
    uint32 rupturingRoarTimer = 0;

    void Reset() override {}

    void EnterCombat(Unit* /*who*/) override
    {
        DoZoneInCombat();

        switch (me->GetEntry())
        {
        case NPC_DOMINATOR_TENTACLE:
            events.RescheduleEvent(1, 7000);
            events.RescheduleEvent(2, 13000);
            rupturingRoarTimer = 4000;
            break;
        case NPC_DEATHGLARE_TENTACLE:
        case NPC_SHRIVELED_EYESTALK:
            events.RescheduleEvent(3, 2000);
            break;
        case NPC_CORRUPTOR_TENTACLE:
            events.RescheduleEvent(4, 2000);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetEntry() == NPC_SHRIVELED_EYESTALK)
            return;

        if (me->GetEntry() == NPC_CORRUPTOR_TENTACLE)
            bloodCount = 1;
        else
            bloodCount = 2;

        if (auto summoner = me->GetOwner())
            for (uint8 i = 0; i < bloodCount; ++i)
                me->CastSpell(me, SPELL_SPAWN_BLOOD, true, nullptr, nullptr, summoner->GetGUID());

        if (me->GetEntry() == NPC_DOMINATOR_TENTACLE)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DoAction(int32 const action) override
    {
        if (me->GetEntry() == NPC_DOMINATOR_TENTACLE)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (me->GetEntry() != NPC_DOMINATOR_TENTACLE)
            DoZoneInCombat();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_NIGHTMARISH_FURY))
            return;

        if (rupturingRoarTimer)
        {
            if (rupturingRoarTimer <= diff)
            {
                rupturingRoarTimer = 3000;

                if (auto target = SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f, true))
                {
                    if (!me->IsWithinMeleeRange(target))
                    {
                        DoCast(SPELL_RUPTURING_ROAR);
                        return;
                    }
                }
            }
            else
                rupturingRoarTimer -= diff;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                DoCast(SPELL_NIGHTMARISH_FURY);
                events.RescheduleEvent(1, 11000);
                break;
            case 2:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                {
                    DoCast(target, SPELL_GROUND_SLAM_DMG);
                    float dist = 0.0f;
                    float angle = me->GetRelativeAngle(target);
                    for (uint8 i = 0; i < 73; ++i)
                    {
                        Position groundPos;
                        me->GetClosePoint(groundPos.m_positionX, groundPos.m_positionY, groundPos.m_positionZ, 1.0f, dist, angle + frand(-0.12f, 0.12f));
                        dist += 0.54f;
                       // AddDelayedEvent(50 * i, [this, groundPos]() -> void
                       // {
                            if (me && me->IsAlive() && me->IsInCombat())
                                me->CastSpell(groundPos, SPELL_GROUND_SLAM_VISUAL, true);
                       // });
                    }
                }
                events.RescheduleEvent(2, 22000);
                break;
            case 3:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 120.0f, true))
                    DoCast(target, SPELL_MIND_FLAY);
                events.RescheduleEvent(3, urandms(9, 12));
                break;
            case 4:
                DoCast(me, SPELL_SPEW_CORRUPTION, true);
                events.RescheduleEvent(4, 10000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//105591
struct npc_ilgynoth_nightmare_horror : public ScriptedAI
{
    npc_ilgynoth_nightmare_horror(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;
    EventMap events;
    uint8 power = 0;
    uint32 tickPower_Timer = 0;

    void Reset() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        tickPower_Timer = 1000;
    }

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 120.0f);
        events.RescheduleEvent(1, 5000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetOwner())
            for (uint8 i = 0; i < 4; ++i)
                me->CastSpell(me, SPELL_SPAWN_BLOOD, true, nullptr, nullptr, summoner->GetGUID());
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

        if (tickPower_Timer <= diff)
        {
            tickPower_Timer = 500;

            if (me->GetReactState() == REACT_AGGRESSIVE)
            {
                power = me->GetPower(POWER_ENERGY);
                if (power < 100)
                    me->SetPower(POWER_ENERGY, power + 5);
                else
                    DoCast(SPELL_EYE_OF_FATE);
            }
        }
        else
            tickPower_Timer -= diff;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                me->SetReactState(REACT_AGGRESSIVE);
                if (instance)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//105721
struct npc_ilgynoth_nightmare_ichor : public ScriptedAI
{
    npc_ilgynoth_nightmare_ichor(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
    }

    EventMap events;
    bool explosion = false;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat(me, 120.0f);
        events.RescheduleEvent(1, 1000);
        events.RescheduleEvent(3, 2000);
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_FIXATE)
        {
            me->SetReactState(REACT_PASSIVE);
            DoResetThreat();
            me->AddThreat(target, 100000.0f);
            AttackStart(target);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;

            if (!explosion)
            {
                explosion = true;
                events.Reset();
                me->InterruptNonMeleeSpells(false);
                me->SetReactState(REACT_PASSIVE);
                me->StopMoving();
                DoCast(SPELL_NIGHTMARE_EXPLOSION);
                events.RescheduleEvent(2, 3000);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                if (!me->GetVictim() || !me->GetVictim()->HasAura(SPELL_FIXATE, me->GetGUID()))
                {
                    DoCast(me, SPELL_FIXATE, true);
                    me->ClearUnitState(UNIT_STATE_CASTING);
                }
                events.RescheduleEvent(1, 2000);
                break;
            case 2:
                DoCast(me, SPELL_NIGHTMARE_EXPLOSION_PCT, true);
                me->Kill(me);
                break;
            case 3:
                if (auto summoner = me->GetOwner())
                    if (me->GetDistance(summoner) <= 20.0f)
                    {
                        explosion = true;
                        me->SetReactState(REACT_PASSIVE);
                        me->DespawnOrUnsummon(1000);
                        DoCast(me, SPELL_REABSORPTION, true);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                        break;
                    }
                events.RescheduleEvent(3, 2000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//218415
class spell_ilgynoth_death_blossom : public SpellScript
{
    PrepareSpellScript(spell_ilgynoth_death_blossom);

    void HandleOnHit()
    {
        if (GetCaster() && GetHitUnit())
        {
            if (GetHitUnit()->HasAura(SPELL_DEATH_BLOSSOM_VISUAL))
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DISPERSED_SPORES);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_DEATH_BLOSSOM_VISUAL);
            }
            else
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DEATH_BLOSSOM_DMG);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_ilgynoth_death_blossom::HandleOnHit);
    }
};

//215128
class spell_ilgynoth_cursed_blood : public AuraScript
{
    PrepareAuraScript(spell_ilgynoth_cursed_blood);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
     //   if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
       //     return;

        GetTarget()->CastSpell(GetTarget(), SPELL_CURSED_BLOOD_EXPLOSION, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_ilgynoth_cursed_blood::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//209471 - HACK!!!
class spell_ilgynoth_nightmare_explosion : public SpellScript
{
    PrepareSpellScript(spell_ilgynoth_nightmare_explosion);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (GetCaster() && GetCaster()->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            targets.clear();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ilgynoth_nightmare_explosion::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

//210048
class spell_ilgynoth_nightmare_explosion_pct : public SpellScript
{
    PrepareSpellScript(spell_ilgynoth_nightmare_explosion_pct);

    uint8 dmgPct = 0;

    void HandleDamage(SpellEffIndex effIndex)
    {
        if (GetHitUnit())
        {
            switch (GetHitUnit()->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_LFR:
                dmgPct = 7;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                dmgPct = 4;
                break;
            default:
                dmgPct = 5;
                break;
            }
            SetHitDamage(GetHitUnit()->CountPctFromMaxHealth(dmgPct));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ilgynoth_nightmare_explosion_pct::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_ilgynoth()
{
    RegisterCreatureAI(boss_ilgynoth);
    RegisterCreatureAI(npc_eye_of_ilgynoth);
    RegisterCreatureAI(npc_ilgynoth_tentacles);
    RegisterCreatureAI(npc_ilgynoth_nightmare_horror);
    RegisterCreatureAI(npc_ilgynoth_nightmare_ichor);
    RegisterSpellScript(spell_ilgynoth_death_blossom);
    RegisterAuraScript(spell_ilgynoth_cursed_blood);
    RegisterSpellScript(spell_ilgynoth_nightmare_explosion);
    RegisterSpellScript(spell_ilgynoth_nightmare_explosion_pct);
}

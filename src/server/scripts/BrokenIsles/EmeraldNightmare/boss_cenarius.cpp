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

#include "Conversation.h"
#include "AreaTriggerAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "emerald_nightmare.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_FORCES_OF_NIGHTMARE_EMOTE = 1,
    SAY_FORCES_OF_NIGHTMARE = 2,
    SAY_NIGHTMARE_BRAMBLES = 3,
    SAY_DEATH = 6,
};

enum Spells
{
    //Phase 1
    SPELL_CREEPING_NIGHTMARES = 210280,
    SPELL_FORCES_OF_NIGHTMARE = 212726,
    SPELL_NIGHTMARE_BRAMBLES_SUM = 210290,
    SPELL_AURA_OF_DREAD_THORNS = 210346,
    SPELL_SUM_ENTANGLING_NIGHTMARES = 214454,

    //Phase 2
    SPELL_OVERWHELMING_NIGHTMARE = 217368, //?
    SPELL_NIGHTMARE_BLAST_SAVER = 214706,
    SPELL_SPEAR_OF_NIGHTMARES = 214529,
    SPELL_NIGHTMARES_AT = 214711, //Dmg 214712

    //Mythic
    SPELL_NIGHTMARE_BLAST = 213162,
    SPELL_BEASTS_OF_NIGHTMARE = 214876,

    //Trash
        //Malfurion Stormrage - 106482
        SPELL_CLEANSING_GROUND_FILTER = 212630,
        SPELL_CLEANSING_GROUND_AT = 212639,
        SPELL_CLEANSING_GROUND_STAGE_2 = 214249,
        SPELL_STORMS_RAGE = 214713,

        //Nightmare Sapling - 106427
        SPELL_GERMINATING = 210861,
        SPELL_NIGHTMARE_GERMINATE = 210974,
        SPELL_ALLIES_GERMINATE = 212175,

        //Tormented Souls - 106895
        SPELL_TORMENTED = 212178,
        SPELL_WISPS_VISUAL_CORRUPTED = 212466,
        SPELL_WISPS_VISUAL_ALLIES = 212467,
        SPELL_SUM_NIGHTMARE_WISPS = 212188,
        SPELL_SUM_ALLIES_WISPS = 212192,

        //Corrupted Emerald Egg - 106898
        SPELL_INCUBATING = 212231,
        SPELL_SUM_NIGHTMARE_DRAKE = 212233,
        SPELL_SUM_ALLIES_DRAKE = 212235,

        //Corrupted Nature - 106899
        SPELL_DRYAD_DUMMY = 212241,
        SPELL_DRYAD_VISUAL = 212424,
        SPELL_SUM_NIGHTMARE_DRYAD = 212242,
        SPELL_SUM_ALLIES_DRYAD = 212243,

        //ALLIES_WISP - 106659
        SPELL_CLEANSING_DETONATE_VIS = 213403,
        SPELL_CLEANSING_DETONATE_AT = 211878,

        //CLEANSED_ANCIENT - 106667
        SPELL_NATURES_FURY = 215099,
        SPELL_REPLENISHING_ROOTS = 211619,

        //EMERALD_DRAKE - 106809
        SPELL_ANCIENT_DREAM_FILTER = 211935,
        SPELL_POISON_BLAST = 216510,

        //REDEEMED_SISTER - 106831
        SPELL_UNBOUND_TOUCH_FILTER = 211976,
        SPELL_JAVELIN_TOSS = 215106,

        //CORRUPTED_WISP - 106304
        SPELL_DESTRUCTIVE_NIGHTMARES = 210617,
        SPELL_DESTRUCTIVE_NIGHTMARES_DMG = 210619,
        SPELL_CORRUPTED_DETONATE = 226713, //Mythic

        //NIGHTMARE_ANCIENT - 105468
        SPELL_DESICCATING_STOMP_DUMMY = 226816,
        SPELL_DESICCATING_STOMP = 211073,
        SPELL_DESICCATING_STOMP_MYTHIC = 226821, //Mythic
        SPELL_DESICCATION = 211156,

        //ROTTEN_DRAKE - 105494
        SPELL_ROTTEN_BREATH_FILTER = 211189,
        SPELL_ROTTEN_BREATH_SUM_TRIGGER = 211188,
        SPELL_ROTTEN_BREATH_DMG = 211192,
        SPELL_NIGHTMARE_BUFFET = 211180,

        //NPC_TWISTED_SISTER - 105495
        SPELL_NIGHTMARE_JAVELIN = 211498,
        SPELL_TWISTED_TOUCH_OF_LIFE_FILTER = 211462,
        SPELL_SCORNED_TOUCH_FILTER = 211487,

        //NIGHTMARE_BRAMBLES - 106167
        SPELL_NIGHTMARE_BRAMBLES_AT = 210331,
        SPELL_NIGHTMARE_BRAMBLES_AT_PER = 210312,
        SPELL_NIGHTMARE_BRAMBLES_UNKNOWN = 210316, //?

        //ENTANGLING_ROOTS - 108040
        SPELL_ENTANGLING_NIGHTMARES_VIS = 214460,
        SPELL_ENTANGLING_NIGHTMARES_AURA = 214463,
        SPELL_ENTANGLING_NIGHTMARES_VEH = 214462,
        SPELL_ENTANGLING_NIGHTMARES_STUN = 214505,

        //BEAST_OF_NIGHTMARE - 108208
        SPELL_GRIPPING_FOG_AT = 214878,

        //Other
        SPELL_NIGHTMARE_DISSOLVE_IN = 212461,
        SPELL_NIGHTMARE_DISSOLVE_OUT = 212563,
        SPELL_DUDE_TRACKER_AT = 212622,
        SPELL_SUMMON_DRAKES_DUMMY = 212604,
        SPELL_CLEANSED_GROUND = 212170,
        SPELL_CAST_HELPFUL_SPELL = 211639,
        SPELL_CLEANSED_DISSOLVE_OUT = 212562,
        SPELL_DISSOLVE_CLEANSED_IN = 210988,
        SPELL_NIGHTMARE_ENERGY = 224200,
        SPELL_COSMETIC_CHANNEL = 225782,
};

enum eEvents
{
    EVENT_FORCES_OF_NIGHTMARE = 1,
    EVENT_NIGHTMARE_BRAMBLES = 2,
    EVENT_OVERWHELMING_NIGHTMARE = 3,
    EVENT_NIGHTMARE_BLAST_SAVER = 4,
    EVENT_SPEAR_OF_NIGHTMARES = 5,
    EVENT_CHECH_EVADE = 6,
    EVENT_NIGHTMARE_BLAST_OR_BEAST = 7, //Mythic

    EVENT_SCENE,
};

enum eVisualKit
{
    BRAMBLES_KIT_1 = 67102, //SMSG_PLAY_SPELL_VISUAL_KIT
};

Position const forcesPos[4] =
{
    {11392.7f, -12723.7f, 487.0f},  //NPC_TORMENTED_SOULS
    {11339.5f, -12719.2f, 487.33f}, //NPC_NIGHTMARE_SAPLING
    {11340.0f, -12667.8f, 487.45f}, //NPC_CORRUPTED_NATURE
    {11391.2f, -12670.0f, 487.18f}, //NPC_CORRUPTED_EMERALD_EGG
};

Position const malfurionPos[1] =
{
    {11359.50f, -12665.90f, 487.30f, 4.79f}
};

Position const centrPos = { 11366.2f, -12695.1f, 486.91f };

Position const beastsPos[9] =
{
    {11408.86f, -12738.13f, 488.3f, 2.42f}, //+
    {11405.04f, -12698.67f, 488.0f, 3.06f},
    {11409.42f, -12661.88f, 488.0f, 3.74f}, //+
    {11375.43f, -12660.12f, 487.0f, 4.64f},
    {11354.59f, -12653.14f, 488.3f, 4.86f},
    {11331.45f, -12661.74f, 488.4f, 5.38f}, //+
    {11328.11f, -12700.74f, 487.4f, 0.06f},
    {11335.28f, -12734.77f, 488.0f, 0.97f},
    {11366.40f, -12742.10f, 488.2f, 1.64f}, //+
};

//104636
struct boss_cenarius : public BossAI
{
    boss_cenarius(Creature* creature) : BossAI(creature, DATA_CENARIUS)
    {
        DoCast(SPELL_COSMETIC_CHANNEL); // visual
    }

    bool firstConv = false;
    bool secondPhase = false;
    uint8 powerCount = 0; //Hack
    uint8 powerTick = 0;
    uint8 waveCount = 0;
    uint16 powerTimer = 0;

    void Reset() override
    {
        _Reset();
        firstConv = false;
        secondPhase = false;
        powerTimer = 0;
        powerTick = 1;
        waveCount = 0;
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 90);
        DoCast(me, SPELL_NIGHTMARE_ENERGY, true);
        me->SummonCreature(NPC_MALFURION_STORMRAGE, malfurionPos[0]);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        DoCast(me, SPELL_CREEPING_NIGHTMARES, true);
        powerTimer = 1000;

       // DoActionSummon(NPC_MALFURION_STORMRAGE, ACTION_1);

        events.RescheduleEvent(EVENT_NIGHTMARE_BRAMBLES, 25000);
        events.RescheduleEvent(EVENT_CHECH_EVADE, 2000);

        if (IsMythic())
            events.RescheduleEvent(EVENT_NIGHTMARE_BLAST_OR_BEAST, 30000);

        Talk(SAY_AGGRO);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        if (auto malf = me->SummonCreature(NPC_MALFURION_STORMRAGE, me->GetPositionX() + 5.0f, me->GetPositionY() + 5.0f, me->GetPositionZ())) // outro
        {
           // malf->SetFacingTo(me);
            malf->AI()->DoAction(4);
        }
    }

    void SpellHit(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_FORCES_OF_NIGHTMARE)
        {
            switch (waveCount)
            {
            case 1:
                me->SummonCreature(NPC_TORMENTED_SOULS, forcesPos[0], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_NIGHTMARE_SAPLING, forcesPos[1], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_EMERALD_EGG, forcesPos[3], TEMPSUMMON_TIMED_DESPAWN, 13000);
                break;
            case 2:
                me->SummonCreature(NPC_TORMENTED_SOULS, forcesPos[0], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[2], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_EMERALD_EGG, forcesPos[3], TEMPSUMMON_TIMED_DESPAWN, 13000);
                break;
            case 3:
                me->SummonCreature(NPC_NIGHTMARE_SAPLING, forcesPos[1], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[2], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[3], TEMPSUMMON_TIMED_DESPAWN, 13000);
                break;
            case 4:
                me->SummonCreature(NPC_TORMENTED_SOULS, forcesPos[0], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_EMERALD_EGG, forcesPos[2], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_EMERALD_EGG, forcesPos[3], TEMPSUMMON_TIMED_DESPAWN, 13000);
                break;
            case 5:
                me->SummonCreature(NPC_NIGHTMARE_SAPLING, forcesPos[1], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[2], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[3], TEMPSUMMON_TIMED_DESPAWN, 13000);
                break;
            case 6:
                me->SummonCreature(NPC_TORMENTED_SOULS, forcesPos[0], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[2], TEMPSUMMON_TIMED_DESPAWN, 13000);
                me->SummonCreature(NPC_CORRUPTED_NATURE, forcesPos[3], TEMPSUMMON_TIMED_DESPAWN, 13000);
                break;
            }
            DoCast(me, SPELL_AURA_OF_DREAD_THORNS, true);
        }

        if (spell->Id == SPELL_BEASTS_OF_NIGHTMARE)
        {
            Position posLeft;
            Position posRight;

            std::list<uint8> randList;
            for (uint8 i = 0; i < 9; ++i)
                randList.push_back(i);

            Trinity::Containers::RandomResize(randList, 2);

            for (std::list<uint8>::iterator itr = randList.begin(); itr != randList.end(); ++itr)
            {
                switch (*itr)
                {
                case 0:
                case 2:
                case 5:
                case 8:
                {
                    float dist = 1.5f;

                    for (uint8 i = 0; i < 3; ++i)
                    {
                      //  beastsPos[*itr].SimplePosXYRelocationByAngle(posLeft, dist, M_PI / 3); //Left
                       // beastsPos[*itr].SimplePosXYRelocationByAngle(posRight, dist, -M_PI / 3); //Right
                        me->SummonCreature(NPC_BEAST_OF_NIGHTMARE, posLeft.GetPositionX(), posLeft.GetPositionY(), posLeft.GetPositionZ(), beastsPos[*itr].GetOrientation());
                        me->SummonCreature(NPC_BEAST_OF_NIGHTMARE, posRight.GetPositionX(), posRight.GetPositionY(), posRight.GetPositionZ(), beastsPos[*itr].GetOrientation());
                        dist += 4;
                    }
                    break;
                }
                default:
                {
                    float dist = 1.5f;

                    for (uint8 i = 0; i < 3; ++i)
                    {
                      //  beastsPos[*itr].SimplePosXYRelocationByAngle(posLeft, dist, M_PI / 2); //Left
                     //   beastsPos[*itr].SimplePosXYRelocationByAngle(posRight, dist, -M_PI / 2); //Right
                        me->SummonCreature(NPC_BEAST_OF_NIGHTMARE, posLeft);
                        me->SummonCreature(NPC_BEAST_OF_NIGHTMARE, posRight);
                        dist += 4;
                    }
                    break;
                }
                break;
                }
            }
        }
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (me->HealthBelowPct(35) && !secondPhase)
        {
            secondPhase = true;
            me->SetReactState(REACT_PASSIVE);
            events.RescheduleEvent(EVENT_OVERWHELMING_NIGHTMARE, 100);
            events.RescheduleEvent(EVENT_SPEAR_OF_NIGHTMARES, 21000);
           // DoActionSummon(NPC_MALFURION_STORMRAGE, ACTION_3);
            Conversation* conversation = new Conversation;
          //  if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(3417), , attacker, nullptr, attacker->GetPosition()))
                delete conversation;
        }
        if (me->HealthBelowPct(65) && !firstConv)
        {
            firstConv = true;
            Conversation* conversation = new Conversation;
            //if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 3416, attacker, nullptr, attacker->GetPosition()))
                delete conversation;
            events.RescheduleEvent(EVENT_SCENE, 20000);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (powerTimer) //???! ? ????? ??? ???? ? ????.
        {
            if (powerTimer <= diff)
            {
                powerTimer = 1000;
                powerCount = me->GetPower(POWER_ENERGY);
                if (powerCount < 100)
                {
                    if (powerTick < 2)
                    {
                        powerTick++;
                        me->SetPower(POWER_ENERGY, powerCount + 1);
                    }
                    else
                    {
                        powerTick = 0;
                        me->SetPower(POWER_ENERGY, powerCount + 2);
                    }
                }
                else
                {
                    if (!me->HasUnitState(UNIT_STATE_CASTING))
                        events.RescheduleEvent(EVENT_FORCES_OF_NIGHTMARE, 100);
                }
            }
            else
                powerTimer -= diff;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FORCES_OF_NIGHTMARE:
            {
                if (!secondPhase && waveCount < 6)
                {
                    ++waveCount;
                    DoCast(SPELL_FORCES_OF_NIGHTMARE);
                    EntryCheckPredicate pred(NPC_MALFURION_STORMRAGE);
                    summons.DoAction(2, pred);
                    Talk(SAY_FORCES_OF_NIGHTMARE_EMOTE);
                    Talk(SAY_FORCES_OF_NIGHTMARE);
                }
                else
                {
                    if (auto malfurion = me->FindNearestCreature(NPC_MALFURION_STORMRAGE, 100.0f))
                        DoCast(malfurion, SPELL_SUM_ENTANGLING_NIGHTMARES);
                }
                break;
            }
            case EVENT_NIGHTMARE_BRAMBLES:
                if (auto pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                    DoCast(pTarget, SPELL_NIGHTMARE_BRAMBLES_SUM);
                Talk(SAY_NIGHTMARE_BRAMBLES);
                events.RescheduleEvent(EVENT_NIGHTMARE_BRAMBLES, 30000);
                break;
            case EVENT_OVERWHELMING_NIGHTMARE:
                DoCast(me, SPELL_OVERWHELMING_NIGHTMARE, true);
                events.RescheduleEvent(EVENT_NIGHTMARE_BLAST_SAVER, 4000);
                break;
            case EVENT_NIGHTMARE_BLAST_SAVER:
                me->RemoveAurasDueToSpell(SPELL_NIGHTMARE_ENERGY);
                DoCast(me, SPELL_NIGHTMARE_BLAST_SAVER, true);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case EVENT_SPEAR_OF_NIGHTMARES:
                DoCastVictim(SPELL_SPEAR_OF_NIGHTMARES);
                events.RescheduleEvent(EVENT_SPEAR_OF_NIGHTMARES, 18000);
                break;
            case EVENT_CHECH_EVADE:
                if (me->GetDistance(centrPos) > 46.0f)
                    EnterEvadeMode();
                events.RescheduleEvent(EVENT_CHECH_EVADE, 2000);
                break;
            case EVENT_NIGHTMARE_BLAST_OR_BEAST:
                if (!secondPhase && waveCount < 6)
                    DoCastVictim(SPELL_NIGHTMARE_BLAST);
                else
                    DoCast(SPELL_BEASTS_OF_NIGHTMARE);
                events.RescheduleEvent(EVENT_NIGHTMARE_BLAST_OR_BEAST, 30000);
                break;
            case EVENT_SCENE:
                Conversation* conversation = new Conversation;
                //if (!conversation->CreateConversation(sObjectMgr->GetGenerator<HighGuid::Conversation>()->Generate(), 3406, me, nullptr, me->GetPosition()))
                    delete conversation;
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//106427, 106895, 106898, 106899
struct npc_cenarius_force_summoner : public ScriptedAI
{
    npc_cenarius_force_summoner(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
    }

    EventMap events;
    ObjectGuid ownerGuid;
    bool alies = false;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        ownerGuid = summoner->GetGUID();

        switch (me->GetEntry())
        {
        case NPC_NIGHTMARE_SAPLING:
            DoCast(me, SPELL_GERMINATING, true);
            events.RescheduleEvent(1, 10000);
            break;
        case NPC_TORMENTED_SOULS:
            DoCast(me, SPELL_TORMENTED, true);
            DoCast(me, SPELL_WISPS_VISUAL_CORRUPTED, true);
            events.RescheduleEvent(2, 10000);
            break;
        case NPC_CORRUPTED_EMERALD_EGG:
            DoCast(me, SPELL_INCUBATING, true);
            events.RescheduleEvent(3, 10000);
            break;
        case NPC_CORRUPTED_NATURE:
            DoCast(me, SPELL_DRYAD_DUMMY, true);
            DoCast(me, SPELL_DRYAD_VISUAL, true);
            events.RescheduleEvent(4, 10000);
            break;
        }
        DoCast(me, SPELL_NIGHTMARE_DISSOLVE_IN, true);
        DoCast(me, SPELL_DUDE_TRACKER_AT, true);
        DoCast(me, SPELL_SUMMON_DRAKES_DUMMY, true);
        events.RescheduleEvent(5, 10000);
    }

    void SpellHit(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_CLEANSED_GROUND)
        {
            alies = true;

            if (me->GetEntry() == NPC_TORMENTED_SOULS)
            {
                me->RemoveAurasDueToSpell(SPELL_WISPS_VISUAL_CORRUPTED);
                DoCast(me, SPELL_WISPS_VISUAL_ALLIES, true);
            }
        }
    }
    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                me->CastSpell(me, alies ? SPELL_ALLIES_GERMINATE : SPELL_NIGHTMARE_GERMINATE, true, 0, 0, ownerGuid);
                break;
            case 2:
            {
                Position pos;
               // centrPos.SimplePosXYRelocationByAngle(pos, 30.0f, frand(0.0f, 6.0f));
                for (uint8 i = 0; i < 5; ++i)
                    me->CastSpell(pos, alies ? SPELL_SUM_ALLIES_WISPS : SPELL_SUM_NIGHTMARE_WISPS, true, 0, 0, ownerGuid);
                break;
            }
            case 3:
                me->CastSpell(me, alies ? SPELL_SUM_ALLIES_DRAKE : SPELL_SUM_NIGHTMARE_DRAKE, true, 0, 0, ownerGuid);
                break;
            case 4:
                me->CastSpell(me, alies ? SPELL_SUM_ALLIES_DRYAD : SPELL_SUM_NIGHTMARE_DRYAD, true, 0, 0, ownerGuid);
                break;
            case 5:
                DoCast(me, SPELL_NIGHTMARE_DISSOLVE_OUT, true);
                break;
            }
        }
    }
};

//105468, 106304, 105494, 105495
struct npc_cenarius_forces_of_nightmare : public ScriptedAI
{
    npc_cenarius_forces_of_nightmare(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    InstanceScript* instance;
    EventMap events;
    bool switchTarget = false; //Wisp
    bool buffet = false; //Drake

    void Reset() override {}

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetEntry() != NPC_CORRUPTED_WISP)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        else
            me->CastSpell(me, SPELL_CORRUPTED_DETONATE, true);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat();

        switch (me->GetEntry())
        {
        case NPC_CORRUPTED_WISP:
            me->SetSpeed(MOVE_RUN, 0.6f);
            me->SetReactState(REACT_PASSIVE);
            me->CastSpell(me, SPELL_DESTRUCTIVE_NIGHTMARES, true);
            SwitchTarget();
            break;
        case NPC_NIGHTMARE_ANCIENT:
            DefaultEvents(50);
            break;
        case NPC_ROTTEN_DRAKE:
            buffet = false;
            DefaultEvents(30);
            break;
        case NPC_TWISTED_SISTER:
            DefaultEvents(80);
            events.RescheduleEvent(2, 3000);
            events.RescheduleEvent(3, 11000);
            break;
        }
    }

    void DefaultEvents(uint8 powerCount)
    {
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, powerCount);
        DoCast(me, SPELL_DISSOLVE_CLEANSED_IN, true);
        DoCast(me, SPELL_NIGHTMARE_ENERGY, true);
        DoCast(me, SPELL_CAST_HELPFUL_SPELL, true);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_DESTRUCTIVE_NIGHTMARES_DMG:
            SwitchTarget();
            break;
        case SPELL_ROTTEN_BREATH_FILTER:
            me->SetReactState(REACT_PASSIVE);
//            me->SetFacingTo;//(target);
            me->SetReactState(REACT_AGGRESSIVE);
            if (auto rotten = me->FindNearestCreature(NPC_ROTTEN_BREATH_TRIG, 100.0f))
              //  me->CastSpellDelay(rotten, SPELL_ROTTEN_BREATH_DMG, false, 100);
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->GetEntry() == NPC_ROTTEN_DRAKE)
            if (me->HealthBelowPct(46) && !buffet)
            {
                buffet = true;
                DoCast(me, SPELL_NIGHTMARE_BUFFET, true);
            }
    }

    void SwitchTarget(bool allowTank = false)
    {
        if (switchTarget)
            return;

     //   auto pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, [this](Unit const* t) { return t->IsPlayer() && !t->ToPlayer()->IsInTankSpec(); });
      //  if (!pTarget)
       //     pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true);

     //   if (pTarget)
        {
            switchTarget = true;
            DoResetThreat();
          //  me->AddThreat(pTarget, 10000.0f);
//            AttackStart;
            events.RescheduleEvent(1, 2000);
        }
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
                switchTarget = false;
                break;
            case 2:
                if (auto pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                    DoCast(pTarget, SPELL_NIGHTMARE_JAVELIN);
                events.RescheduleEvent(2, urand(5, 8) * IN_MILLISECONDS);
                break;
            case 3:
                DoCast(me, SPELL_TWISTED_TOUCH_OF_LIFE_FILTER, true);
                events.RescheduleEvent(3, 12000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//106667, 106659, 106809, 106831
struct npc_cenarius_allies_of_nature : public ScriptedAI
{
    npc_cenarius_allies_of_nature(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    EventMap events;
    ObjectGuid ownerGuid;
    uint32 spell = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        ownerGuid = summoner->GetGUID();

        switch (me->GetEntry())
        {
        case NPC_ALLIES_WISP:
            DoCast(me, SPELL_CLEANSING_DETONATE_VIS, true);
            events.RescheduleEvent(1, 1000);
            break;
        case NPC_CLEANSED_ANCIENT:
            spell = SPELL_NATURES_FURY;
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 80);
            DefaultEvents();
            break;
        case NPC_EMERALD_DRAKE:
            spell = SPELL_POISON_BLAST;
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 100);
            //SetFlyMode(true);
            DefaultEvents();
            break;
        case NPC_REDEEMED_SISTER:
            spell = SPELL_JAVELIN_TOSS;
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 56);
            DefaultEvents();
            break;
        }
    }

    void DefaultEvents()
    {
        DoCast(me, SPELL_CAST_HELPFUL_SPELL, true);
        DoCast(me, SPELL_DISSOLVE_CLEANSED_IN, true);
        events.RescheduleEvent(2, 2000);
        events.RescheduleEvent(3, 58000);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_CLEANSING_DETONATE_AT)
            me->DespawnOrUnsummon(500);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) || ownerGuid.IsEmpty())
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                me->CastSpell(me, SPELL_CLEANSING_DETONATE_AT, false, 0, 0, ownerGuid);
                break;
            case 2:
            {
                if (auto owner = me->GetOwner())
                {
                    if (me->GetDistance(owner) > 20.0f)
                    {
                        Position pos;
                        me->GetNearPosition(me->GetDistance(owner) / 2, me->GetRelativeAngle(owner));
                        me->GetMotionMaster()->MovePoint(1, pos);
                    }
                    else
                    {
//                        me->SetFacingTo;// (owner);
                        DoCast(spell);
                    }
                }
                events.RescheduleEvent(2, 3600);
                break;
            }
            case 3:
                events.Reset();
                me->CastStop();
                DoCast(me, SPELL_CLEANSED_DISSOLVE_OUT, true);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//106482
struct npc_cenarius_malfurion_stormrage : public ScriptedAI
{
    npc_cenarius_malfurion_stormrage(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    InstanceScript* instance;
    EventMap events;
    bool introStart = false;
    bool introDone = false;
    bool firstSay = false;
    uint8 powerTick = 0;
    uint16 powerTimer = 0;
    uint32 powerCount = 0;
    uint32 maxPower = 0;
    uint32 introTimer = 0;

    void Reset() override
    {
        me->SetMaxPower(POWER_MANA, 295104);
        maxPower = me->GetMaxPower(POWER_MANA);
        powerCount = 0;
        powerTick = 0;
        powerTimer = 0;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer() || me->GetPositionZ() <= 590.0f)
            return;

        if (!introDone && me->IsWithinDistInMap(who, 70.0f))
        {
            introDone = true;
           // who->CreateConversation(3602);
            DoCast(225937);
            introTimer = 5000;
            introStart = true;
            firstSay = false;
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->GetEntry() == NPC_CENARIUS)
        {
            me->setRegeneratingHealth(false);
            me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
        }
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case 1:
            events.RescheduleEvent(1, 500);
            break;
        case 2:
            events.RescheduleEvent(2, 3000);
            break;
        case 3:
            me->SetPower(POWER_MANA, CalculatePct(maxPower, 50));
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            powerTimer = 1000;
            break;
        case 4:
            events.RescheduleEvent(5, 4000); // outro
            break;
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_CLEANSING_GROUND_FILTER)
            DoCast(target, SPELL_CLEANSING_GROUND_AT, true);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetOwner())
            if (Creature* owner = me->GetOwner()->ToCreature())
                owner->AI()->EnterEvadeMode();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (powerTimer) //???! ? ????? ??? ???? ? ????.
        {
            if (powerTimer <= diff)
            {
                powerTimer = 1000;
                powerCount = me->GetPower(POWER_MANA);
                if (powerCount < maxPower)
                {
                    if (powerTick < 2)
                    {
                        powerTick++;
                        me->SetPower(POWER_MANA, powerCount + CalculatePct(maxPower, 2));
                    }
                    else
                    {
                        powerTick = 0;
                        me->SetPower(POWER_MANA, powerCount + CalculatePct(maxPower, 1));
                    }
                }
                else if (!me->HasUnitState(UNIT_STATE_STUNNED))
                {
                    events.RescheduleEvent(3, 100);
                    me->SetPower(POWER_MANA, 0);
                }
            }
            else
                powerTimer -= diff;
        }

        if (introStart) // intro on the start
        {
            if (introTimer <= diff)
            {
                if (!firstSay)
                {
                    Talk(0);
                    firstSay = true;
                }
                else
                {
                    Talk(1);
                    introStart = false;
                }
                introTimer = 16000;
            }
            else
                introTimer -= diff;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
            {
                if (auto owner = me->GetOwner())
                {
                    if (me->GetDistance(owner) > 20.0f)
                    {
                        Position pos;
                        me->GetNearPosition(me->GetDistance(owner) / 2, me->GetRelativeAngle(owner));
                        me->GetMotionMaster()->MovePoint(1, pos);
                    }
                    else
                    {
                        me->SetFacingToObject(owner);
                        DoCast(SPELL_STORMS_RAGE);
                    }
                }
                events.RescheduleEvent(1, 2000);
                break;
            }
            case 2:
                DoCast(SPELL_CLEANSING_GROUND_FILTER);
                Talk(2);
                break;
            case 3:
                DoCast(SPELL_CLEANSING_GROUND_STAGE_2);
                events.DelayEvents(3000);
                events.RescheduleEvent(4, 100); //???. ????? ??????????? ??????
                break;
            case 4:
                if (auto owner = me->GetOwner())
                    if (auto target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                        DoCast(target, SPELL_CLEANSING_GROUND_AT, true);
                break;
            case 5: // outro
                Talk(3);
                if (auto owner = me->GetOwner())
                    me->CastSpell(owner, 225790);
                events.RescheduleEvent(6, 10000);
                break;
            case 6:
                Talk(4);
                if (auto owner = me->GetOwner())
                    me->AddAura(225790, owner);
                events.RescheduleEvent(7, 10000);
                break;
            case 7:
                Talk(5);
                events.RescheduleEvent(8, 10000);
                break;
            case 8:
                Talk(6);
                events.RescheduleEvent(9, 10000);
                break;
            case 9:
                Talk(7);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//106167
struct npc_cenarius_nightmare_brambles : public ScriptedAI
{
    npc_cenarius_nightmare_brambles(Creature* creature) : ScriptedAI(creature)
    {
        me->SetSpeed(MOVE_RUN, 0.5f);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    EventMap events;
    ObjectGuid playerGUID;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        events.RescheduleEvent(1, 1000);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        damage = 0;
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                DoCast(me, SPELL_NIGHTMARE_BRAMBLES_AT, true);
                DoCast(me, SPELL_NIGHTMARE_BRAMBLES_AT_PER, true);
                DoCast(me, SPELL_NIGHTMARE_BRAMBLES_UNKNOWN, true);
                events.RescheduleEvent(2, 1000);
                events.RescheduleEvent(3, 2000);
                break;
            case 2:
            {
                events.RescheduleEvent(2, 2000);

                //if (auto player = Player::GetPlayer(*me, playerGUID))
                  //  if (player->isAlive() && (player->GetDistance(me) < 100.0f))
                        break;

                if (auto owner = me->GetOwner())
                    if (auto target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 80.0f, true))
                        playerGUID = target->GetGUID();
                break;
            }
            case 3:
              //  me->SendPlaySpellVisualKit(0, BRAMBLES_KIT_1);
              //  if (auto player = Player::GetPlayer(*me, playerGUID))
                  //  me->GetMotionMaster()->MovePoint(1, player->GetPosition());
                events.RescheduleEvent(3, 1000);
                break;
            }
        }
    }
};

//108040
struct npc_cenarius_entangling_roots : public ScriptedAI
{
    npc_cenarius_entangling_roots(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_ENTANGLING_NIGHTMARES_VIS, true);
        DoCast(me, SPELL_NIGHTMARE_DISSOLVE_IN, true);
        DoCast(me, SPELL_ENTANGLING_NIGHTMARES_AURA, true);
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_ENTANGLING_NIGHTMARES_VEH)
        {
            target->CastSpell(me, 46598, true); //Ride vehicle
            DoCast(me, SPELL_ENTANGLING_NIGHTMARES_STUN, true);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (auto malfurion = me->FindNearestCreature(NPC_MALFURION_STORMRAGE, 30.0f))
            malfurion->RemoveAurasDueToSpell(SPELL_ENTANGLING_NIGHTMARES_STUN);
    }

    void UpdateAI(uint32 diff) override {}
};

//108208
struct npc_cenarius_beast_of_nightmare : public ScriptedAI
{
    npc_cenarius_beast_of_nightmare(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
    }

    uint16 moveTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        moveTimer = 2000;
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_GRIPPING_FOG_AT)
        {
            Position pos;
            me->GetNearPosition(100.0f, 0.0f);
            me->GetMotionMaster()->MovePoint(1, pos, false);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (id == 1)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (moveTimer)
        {
            if (moveTimer <= diff)
            {
                moveTimer = 0;
                DoCast(me, SPELL_GRIPPING_FOG_AT, true);
            }
            else
                moveTimer -= diff;
        }
    }
};

//212630
class spell_cenarius_cleansing_ground : public SpellScript
{
    PrepareSpellScript(spell_cenarius_cleansing_ground);

    void FilterTargets(std::list<WorldObject*>& targetsList)
    {
        std::vector<WorldObject*> tempCreature;

        for (auto creature : targetsList)
        {
            switch (creature->GetEntry())
            {
            case NPC_NIGHTMARE_SAPLING:
            case NPC_TORMENTED_SOULS:
            case NPC_CORRUPTED_EMERALD_EGG:
            case NPC_CORRUPTED_NATURE:
                tempCreature.push_back(creature);
                break;
            default:
                break;
            }
        }
        uint8 counter[4] = { 0, 0, 0, 0 };

        for (auto plr : targetsList)
        {
            if (plr->GetTypeId() != TYPEID_PLAYER)
                continue;

            for (uint8 i = 0; i < tempCreature.size(); ++i)
            {
                if (tempCreature[i]->GetDistance(plr) < 33.0f && i < 4)
                    ++counter[i];
            }
        }

        uint8 saveCount = counter[0];
        uint8 selectId = 0;

        for (uint8 i = 1; i < 4; ++i)
        {
            if (saveCount < counter[i])
            {
                saveCount = counter[i];
                selectId = i;
            }
        }
        targetsList.clear();
        if (!tempCreature.empty())
            targetsList.push_back(tempCreature[selectId]);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_cenarius_cleansing_ground::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

//212188, 212192
class spell_cenarius_sum_wisp : public SpellScript
{
    PrepareSpellScript(spell_cenarius_sum_wisp);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_0);

        Position pos;
      //  centrPos.SimplePosXYRelocationByAngle(pos, 30.0f, frand(0.0f, 6.0f));
        WorldLocation* dest = const_cast<WorldLocation*>(GetExplTargetDest());
        dest->Relocate(pos);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_cenarius_sum_wisp::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

//211639
class spell_cenarius_allies_periodic_energize : public AuraScript
{
    PrepareAuraScript(spell_cenarius_allies_periodic_energize);

    uint8 powerTick = 0;

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster)
            return;

        uint8 powerCount = caster->GetPower(POWER_ENERGY);

        if (powerCount < 100)
        {
            switch (caster->GetEntry())
            {
            case NPC_CLEANSED_ANCIENT:
            {
                if (powerTick++ < 7)
                    caster->SetPower(POWER_ENERGY, powerCount + 3);
                else
                {
                    powerTick = 0;
                    caster->SetPower(POWER_ENERGY, powerCount + 2);
                }
                break;
            }
            case NPC_EMERALD_DRAKE:
            {
                if (powerTick++ < 2)
                    caster->SetPower(POWER_ENERGY, powerCount + 3);
                else
                {
                    powerTick = 0;
                    caster->SetPower(POWER_ENERGY, powerCount + 2);
                }
                break;
            }
            case NPC_REDEEMED_SISTER:
            case NPC_NIGHTMARE_ANCIENT:
            {
                if (powerTick++ < 2)
                    caster->SetPower(POWER_ENERGY, powerCount + 3);
                else
                {
                    powerTick = 0;
                    caster->SetPower(POWER_ENERGY, powerCount + 4);
                }
                break;
            }
            case NPC_ROTTEN_DRAKE:
                caster->SetPower(POWER_ENERGY, powerCount + 4);
                break;
            case NPC_TWISTED_SISTER:
                caster->SetPower(POWER_ENERGY, powerCount + 5);
                break;
            }
        }
        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
        {
            switch (caster->GetEntry())
            {
            case NPC_CLEANSED_ANCIENT:
                caster->CastSpell(caster, SPELL_REPLENISHING_ROOTS);
                break;
            case NPC_EMERALD_DRAKE:
                caster->CastSpell(caster, SPELL_ANCIENT_DREAM_FILTER);
                break;
            case NPC_REDEEMED_SISTER:
                caster->CastSpell(caster, SPELL_UNBOUND_TOUCH_FILTER, true);
                break;
            case NPC_NIGHTMARE_ANCIENT:
                if (caster->GetMap()->IsMythic())
                {
                    caster->SetPower(POWER_ENERGY, 0);
                    caster->CastSpell(caster, SPELL_DESICCATING_STOMP_MYTHIC);
                  //  caster->CastSpellDelay(caster, SPELL_DESICCATING_STOMP_MYTHIC, false, 3200);
                }
                else
                    caster->CastSpell(caster, SPELL_DESICCATING_STOMP);
                break;
            case NPC_ROTTEN_DRAKE:
                caster->CastSpell(caster, SPELL_ROTTEN_BREATH_FILTER);
                break;
            case NPC_TWISTED_SISTER:
                caster->CastSpell(caster, SPELL_SCORNED_TOUCH_FILTER);
                break;
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_cenarius_allies_periodic_energize::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//211935
class spell_cenarius_ancient_dream_filter : public SpellScript
{
    PrepareSpellScript(spell_cenarius_ancient_dream_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.clear();

        if (GetCaster())
            if (auto owner = GetCaster()->GetOwner())
                if (owner->GetVictim())
                    targets.push_back(owner->GetVictim());
    }

    void HandleOnHit()
    {
        if (GetCaster() && GetHitUnit())
            GetHitUnit()->CastSpell(GetHitUnit(), 211939, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_cenarius_ancient_dream_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnHit += SpellHitFn(spell_cenarius_ancient_dream_filter::HandleOnHit);
    }
};

//211939
class spell_cenarius_ancient_dream : public AuraScript
{
    PrepareAuraScript(spell_cenarius_ancient_dream);

    void CalculateAmount(AuraEffect const* /*AuraEffect**/, float& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, float& absorbAmount)
    {
        if (auto target = GetTarget())
        {
            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

           // target->SetHealth(target->CountPctFromMaxHealth(GetSpellInfo()->[EFFECT_1]->BasePoints));
          //  aurEff->GetBase()->Remove();
        }
    }

    void Register() override
    {
       // DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_cenarius_ancient_dream::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
     //   OnEffectAbsorb += AuraEffectAbsorbFn(spell_cenarius_ancient_dream::Absorb, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

//211073, 226821
class spell_cenarius_desiccating_stomp_filter : public SpellScript
{
    PrepareSpellScript(spell_cenarius_desiccating_stomp_filter);

    bool targetsEmpty = false;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targetsEmpty = targets.size();
    }

    void OnAfterCast()
    {
        if (GetCaster() && targetsEmpty)
            GetCaster()->CastSpell(GetCaster(), SPELL_DESICCATION, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_cenarius_desiccating_stomp_filter::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterCast += SpellCastFn(spell_cenarius_desiccating_stomp_filter::OnAfterCast);
    }
};

//211462
class spell_cenarius_twisted_touch_of_life_filter : public SpellScript
{
    PrepareSpellScript(spell_cenarius_twisted_touch_of_life_filter);

    void FilterTargets(std::list<WorldObject*>& targetsList)
    {
        std::list<WorldObject*> tempCreature;

        for (auto creature : targetsList)
            if (creature->GetEntry() == NPC_NIGHTMARE_ANCIENT || creature->GetEntry() == NPC_ROTTEN_DRAKE || creature->GetEntry() == NPC_TWISTED_SISTER)
                tempCreature.push_back(creature);

        //tempCreature.sort(Trinity::UnitHealthState(true));

        if (tempCreature.size() > 1)
            tempCreature.resize(1);

        if (!tempCreature.empty())
            targetsList = tempCreature;
    }

    void HandleOnHit()
    {
      //  if (GetCaster() && GetHitUnit())
         //   GetCaster()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[EFFECT_0]->BasePoints);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_cenarius_twisted_touch_of_life_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnHit += SpellHitFn(spell_cenarius_twisted_touch_of_life_filter::HandleOnHit);
    }
};

//210340
class spell_cenarius_dread_thorns_reflects : public AuraScript
{
    PrepareAuraScript(spell_cenarius_dread_thorns_reflects);

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (!GetCaster())
            return;

        auto target = eventInfo.GetProcTarget();
        if (!target)
            return;

        //float damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), GetSpellInfo()->Effects[EFFECT_0]->BasePoints);
      //  if (!damage)
           // return;

        //GetCaster()->CastCustomSpell(target, 210342, &damage, nullptr, nullptr, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_cenarius_dread_thorns_reflects::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

//214529
class spell_cenarius_spear_of_nightmares : public SpellScript
{
    PrepareSpellScript(spell_cenarius_spear_of_nightmares);

    void HandleScript(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        float scale = GetHitDamage() / GetSpellInfo()->GetEffect(EFFECT_0, GetCaster()->GetMap()->GetDifficultyID())->CalcValue();
       // GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_NIGHTMARES_AT, &scale, nullptr, nullptr, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_cenarius_spear_of_nightmares::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//Entry: 7297 (Custom: 11750)
struct at_cenarius_nightmare_blast : AreaTriggerAI
{
    at_cenarius_nightmare_blast(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    float createScale = 0.0f;
    uint32 createScaleTimer = 0;

    void OnCreate() override
    {
       // createScale = CalculatePct(50.0f, at->GetSpellValue()->EffectBasePoints[0] * 100.0f);
        createScaleTimer = 200;
    }

    void OnUpdate(uint32 diff) override
    {
        if (createScaleTimer)
        {
            if (createScaleTimer <= diff)
            {
                createScaleTimer = 200;

            //    if (at->GetRadius() < createScale)
               //     at->SetSphereScale(0.15f, 200, false);
              //  else
                 //   createScaleTimer = 0;
            }
            else
                createScaleTimer -= diff;
        }
    }
};

void AddSC_boss_cenarius()
{
    RegisterCreatureAI(boss_cenarius);
    RegisterCreatureAI(npc_cenarius_force_summoner);
    RegisterCreatureAI(npc_cenarius_forces_of_nightmare);
    RegisterCreatureAI(npc_cenarius_allies_of_nature);
    RegisterCreatureAI(npc_cenarius_malfurion_stormrage);
    RegisterCreatureAI(npc_cenarius_nightmare_brambles);
    RegisterCreatureAI(npc_cenarius_entangling_roots);
    RegisterCreatureAI(npc_cenarius_beast_of_nightmare);
    RegisterSpellScript(spell_cenarius_cleansing_ground);
    RegisterSpellScript(spell_cenarius_sum_wisp);
    RegisterAuraScript(spell_cenarius_allies_periodic_energize);
    RegisterSpellScript(spell_cenarius_ancient_dream_filter);
    RegisterAuraScript(spell_cenarius_ancient_dream);
    RegisterSpellScript(spell_cenarius_desiccating_stomp_filter);
    RegisterSpellScript(spell_cenarius_twisted_touch_of_life_filter);
    RegisterAuraScript(spell_cenarius_dread_thorns_reflects);
    RegisterSpellScript(spell_cenarius_spear_of_nightmares);
    RegisterAreaTriggerAI(at_cenarius_nightmare_blast);
}

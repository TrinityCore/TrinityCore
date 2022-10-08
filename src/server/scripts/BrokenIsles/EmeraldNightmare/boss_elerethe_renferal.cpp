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
#include "emerald_nightmare.h"

enum Says
{
    SAY_FEEDING_TIME = 0,
    SAY_GATHERING_CLOUDS = 1,
    SAY_RAZOR_WING = 2,
    SAY_AGGRO = 3,
    SAY_FEEDING_TIME_1 = 4,
    SAY_GATHERING_CLOUDS_1 = 5,
    SAY_RAZOR_WING_1 = 6,
};

enum Spells
{
    SPELL_SPIDER_START = 210284, //?? ???????????? ?? ????? ???? 21737?
    SPELL_ENERGY_TRACKER_TRANSFORM = 225364,
    SPELL_ENERGY_TRANSFORM_COST = 210366,
    SPELL_TRANSFORM_DISSOLVE = 210309,
    SPELL_WEB_WRAPPED = 215188, //?
    SPELL_BERSERK = 26662,

    //Phase One - Spider form
    SPELL_SPIDER_TRANSFORM_DUMMY = 210326, //226020?
    SPELL_SPIDER_TRANSFORM = 210292,
    SPELL_WEB_OF_PAIN_FILTER = 215288,
    SPELL_FEEDING_TIME = 212364,
    SPELL_FEEDING_TIME_2 = 214305, //?
    SPELL_FEEDING_TIME_FILTER = 214311,
    SPELL_FEEDING_TIME_SUM_STALKER = 214275, //NPC_VILE_AMBUSH_STALKER
    SPELL_VILE_AMBUSH_FILTER = 214328,
    SPELL_VILE_AMBUSH_MISSILE = 214339,
    SPELL_VILE_AMBUSH_JUMP = 214346,
    SPELL_VILE_AMBUSH_VISUAL_JUMP = 215253,
    SPELL_NECROTIC_VENOM = 215443,
    SPELL_VENOMOUS_POOL_AOE = 213781, //Heroic
    SPELL_PAIN_LASH = 215306, //Mythic
    SPELL_TANGLED_WEBS_AT = 217982, //Cast - 224833

    //Phase Second - Darkwing form
    SPELL_DARKWING_FORM_DUMMY = 210308,
    SPELL_DARKWING_FORM = 210293,
    SPELL_TWISTING_SHADOWS_FILTER = 210864,
    SPELL_TWISTING_SHADOWS_AT = 210792, //casters: 106350, 111439
    SPELL_GATHERING_CLOUDS = 212707,
    SPELL_SHIMMERING_FEATHER_TRIG = 213064,
    SPELL_RAZOR_WING_FILTER = 210553,
    SPELL_RAZOR_WING = 210547,
    SPELL_RAZOR_WING_VISUAL = 212842,
    SPELL_RAZOR_WING_DMG = 212853,
    SPELL_DARK_STORM_FILTER = 210948,
    SPELL_DARK_STORM_AURA = 211122,
    SPELL_DARK_STORM_AT = 211124,
    SPELL_RAKING_TALONS = 215582,
    SPELL_RAKING_TALONS_2 = 222037,
    SPELL_FOUL_WINDS = 211137,
    SPELL_VIOLENT_WINDS = 218124, //Mythic

    //Other
    SPELL_DRUID_TRANSFORM = 226017, //?
    SPELL_SPIDER_TRANSFORM_2 = 228523, //?? ??????? ????? (21737) ??? ???.
    SPELL_SHIMMERING_FEATHER = 212993,
    SPELL_SHIMMERING_FEATHER_OVERRIDE = 221913,
    SPELL_SWARM = 214450, //Mythic buff boss
};

enum eEvents
{
    //Phase One - Spider form
    EVENT_WEB_OF_PAIN = 1,
    EVENT_FEEDING_TIME = 2,
    EVENT_NECROTIC_VENOM = 3,
    EVENT_SPIDER_TRANSFORM = 4,

    //Phase Second - Darkwing form
    EVENT_DARKWING_FORM = 5,
    EVENT_TWISTING_SHADOWS = 6,
    EVENT_GATHERING_CLOUDS = 7,
    EVENT_SUM_SHIMMERING_FEATHER = 8,
    EVENT_RAZOR_WING = 9,
    EVENT_DARK_STORM = 10,
    EVENT_RAKING_TALONS = 11,
    EVENT_VIOLENT_WINDS = 12,

    EVENT_REACT_AGGRESSIVE = 13,
    EVENT_NEXT_PLATFORM = 14,
    EVENT_CHECH_PLAYER = 15,
};

enum eTransform
{
    SPIDER_FORM = 1,
    DARKWING_FORM = 2
};

enum EGmisc
{
    //SMSG_SET_MOVEMENT_ANIM_KIT
    ANIM_1 = 753,
    ANIM_2 = 2737,

    //SMSG_PLAY_ONE_SHOT_ANIM_KIT
    ANIM_3 = 9779,

    SPELL_EGG_DUMMY_1 = 223438,
    SPELL_EGG_DUMMY_2 = 215508,
    SPELL_SUM_SKITTERING_SPIDERLING = 215505, //4x
};

Position const platformPos[3] =
{
    {11405.59f, 11400.70f, -85.32f},
    {11376.42f, 11224.97f, -102.0f},
    {11538.02f, 11298.43f, -87.06f}
};

Position const spiderPos[12] =
{
    {11411.42f, 11402.46f, -51.12f}, //Platform 1
    {11413.96f, 11369.06f, -50.60f},
    {11434.47f, 11374.71f, -51.50f},
    {11373.11f, 11388.3f,  -50.58f},
    {11343.57f, 11240.51f, -44.54f}, //Platform 2
    {11382.04f, 11262.68f, -53.15f},
    {11403.85f, 11224.34f, -51.75f},
    {11377.61f, 11199.40f, -45.50f},
    {11537.53f, 11264.99f, -47.43f}, //Platform 3
    {11503.03f, 11288.73f, -45.12f},
    {11522.21f, 11323.06f, -43.80f},
    {11552.95f, 11302.63f, -38.93f}
};

Position const twistBridgePos[5] =
{
    {11362.16f, 11372.33f, -87.34f}, //NPC_TWISTING_SHADOWS_BRIDGE
    {11449.68f, 11389.96f, -85.37f},
    {11365.16f, 11308.75f, -98.53f},
    {11491.63f, 11268.83f, -89.58f},
    {11456.38f, 11238.37f, -93.77f}
};

Position const eventTwistBridgePos[7] =
{
    {11446.38f, 11233.84f, -95.04f},
    {11363.54f, 11370.07f, -87.67f},
    {11421.69f, 11379.41f, -85.65f},
    {11376.41f, 11396.77f, -84.34f},
    {11385.76f, 11380.19f, -85.75f},
    {11427.25f, 11392.06f, -85.07f},
    {11443.09f, 11387.54f, -85.45f}
};

//106087
struct boss_elerethe_renferal : public BossAI
{
    boss_elerethe_renferal(Creature* creature) : BossAI(creature, DATA_RENFERAL)
    {
        me->SetSpeed(MOVE_FLIGHT, 4.0f);
        me->m_SightDistance = 350.0f;
        Intro();
    }

    bool introDone = false;
    uint8 introCount = 0;
    uint8 platformId = 0;
    uint16 checkEvadeTimer = 0;
    uint32 berserkTimer = 0;

    void Intro()
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
        me->SetVisible(false);
       // me->CastSpellDelay(me, SPELL_DRUID_TRANSFORM, true, 1000);

        me->SummonCreature(NPC_INTRO_SHADOWFEATHER, 11396.70f, 11259.00f, -98.38f, 4.35f); //birdie
        me->SummonCreature(NPC_INTRO_NIGHTMOTHER, 11556.90f, 11291.40f, -84.95f, 2.85f); //spider

        for (uint8 i = 0; i < 7; ++i)
        {
            auto shadows = me->SummonCreature(NPC_TWISTING_SHADOWS, eventTwistBridgePos[i]);
            if (i == 0)
                shadows->GetMotionMaster()->MovePath(10635000, true);
        }
        if (auto fakeBoss = me->SummonCreature(113609, me->GetPosition()))
        {
            fakeBoss->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
            fakeBoss->SetReactState(REACT_PASSIVE);
            fakeBoss->SetOrientation(4.62f);
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_INTRO_SHADOWFEATHER:
        case NPC_INTRO_NIGHTMOTHER:
        {
            if (++introCount == 2)
            {
                introDone = true;
                me->SetVisible(true);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAllAuras();
                RemoveEventTrash();
            }
            break;
        }
        }
    }

    void Reset() override
    {
        _Reset();
        me->SetPower(POWER_ENERGY, 0);
        if (introDone)
            me->SetReactState(REACT_AGGRESSIVE);
        platformId = 0;
        checkEvadeTimer = 2000;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        me->SetReactState(REACT_AGGRESSIVE);
        DoCast(me, SPELL_ENERGY_TRACKER_TRANSFORM, true);
        DoCast(me, SPELL_WEB_WRAPPED, true);
        berserkTimer = 9 * MINUTE * IN_MILLISECONDS;

        EventsForm(SPIDER_FORM);
        Talk(SAY_AGGRO);
    }

    void JustDied(Unit* /*killer*/) override
    {
       // me->SetAnimTier(0);
        RemoveEventTrash();
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode();
        RemoveEventTrash();
        me->RemoveAllAuras();
       // me->SetAnimTier(0);
        me->NearTeleportTo(11405.6f, 11400.7f, -85.32f, 4.62f);
        me->GetMotionMaster()->MoveIdle();
    }

    void RemoveEventTrash()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(215464);
        instance->DoRemoveAurasDueToSpellOnPlayers(215460);
        instance->DoRemoveAurasDueToSpellOnPlayers(215449);

        std::list<AreaTrigger*> list;
      //  me->GetAreaTriggerListWithEntryInGrid(list, 11547, 222.0f); //NECROTIC_VENOM - 213123
        for (auto at : list)
         //   at->Despawn();

        std::list<Creature*> creatureList;
       // me->GetCreatureListWithEntryInGrid(creatureList, NPC_TWISTING_SHADOWS, 222.0f);
       // me->GetCreatureListWithEntryInGrid(creatureList, 113609, 222.0f);
      //  for (auto creature : creatureList)
          //  creature->DespawnOrUnsummon();
    }

    void EventsForm(uint8 form)
    {
        switch (form)
        {
        case SPIDER_FORM:
            events.RescheduleEvent(EVENT_WEB_OF_PAIN, 6000);
            events.RescheduleEvent(EVENT_NECROTIC_VENOM, 12000);
            events.RescheduleEvent(EVENT_FEEDING_TIME, 16000);
            break;
        case DARKWING_FORM:
            events.RescheduleEvent(EVENT_TWISTING_SHADOWS, 7000);
            events.RescheduleEvent(EVENT_GATHERING_CLOUDS, 16000);
            events.RescheduleEvent(EVENT_DARK_STORM, 26000);
            events.RescheduleEvent(EVENT_RAZOR_WING, 59000);
            if (IsMythic())
                events.RescheduleEvent(EVENT_VIOLENT_WINDS, 40500);
            break;
        }
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_FEEDING_TIME:
            checkEvadeTimer = 15000;
            me->SetReactState(REACT_PASSIVE);
            me->SetDisableGravity(true);
        //    me->GetMotionMaster()->MoveTakeoff(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 32.0f);
            break;
        case SPELL_ENERGY_TRANSFORM_COST:
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->RemoveAurasDueToSpell(SPELL_ENERGY_TRACKER_TRANSFORM);
            if (me->HasAura(SPELL_DARKWING_FORM))
                events.RescheduleEvent(EVENT_SPIDER_TRANSFORM, 0);
            else
                events.RescheduleEvent(EVENT_DARKWING_FORM, 0);
            break;
        case SPELL_SPIDER_TRANSFORM_DUMMY:
        case SPELL_DARKWING_FORM_DUMMY:
            events.RescheduleEvent(EVENT_REACT_AGGRESSIVE, 5000);
            break;
        }
    }

    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_FEEDING_TIME_FILTER:
            DoCast(target, SPELL_FEEDING_TIME_SUM_STALKER, true);
          //  me->GetMotionMaster()->MoveTakeoff(2, target->GetPositionX(), target->GetPositionY(), me->GetPositionZ());
            break;
        case SPELL_VILE_AMBUSH_FILTER:
            DoCast(me, SPELL_VILE_AMBUSH_VISUAL_JUMP, true);
            DoCast(target, SPELL_VILE_AMBUSH_MISSILE, true);
            break;
        case SPELL_RAZOR_WING_FILTER:
            me->SetReactState(REACT_PASSIVE);
            //me->SetFacingTo(target);
            DoCast(target, SPELL_RAZOR_WING);
            events.RescheduleEvent(EVENT_REACT_AGGRESSIVE, 5000);
            break;
        case SPELL_RAZOR_WING:
            DoCast(target, SPELL_RAZOR_WING_VISUAL, true);
            DoCast(target, SPELL_RAZOR_WING_DMG, true);
            break;
        }
    }

  /*  void SpellFinishCast(const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_RAKING_TALONS)
        {
            if (auto victim = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 15.0f, true))
                me->CastSpellDelay(victim, SPELL_RAKING_TALONS_2, false, 100);
        }
    }

    void OnAreaTriggerDespawn(uint32 spellId, Position pos, bool duration) override
    {
        if (duration)
            return;

        //Venomous Pool AOE
        if (spellId == 213123 || spellId == 222925 || spellId == 225519)
            if (GetDifficultyID() == DIFFICULTY_HEROIC_RAID || GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                DoCast(me, SPELL_VENOMOUS_POOL_AOE, true);
    }
    */
    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == EFFECT_MOTION_TYPE)
        {
            switch (id)
            {
            case 1:
            {
                uint8 spiderPosId = 0;
                if (platformId == 1)
                    spiderPosId = 4;
                else if (platformId == 2)
                    spiderPosId = 8;
                for (uint8 i = spiderPosId; i < 4 + spiderPosId; ++i)
                    me->SummonCreature(NPC_VENOMOUS_SPIDERLING, spiderPos[i]);
                DoCast(me, SPELL_FEEDING_TIME_FILTER, true);
                break;
            }
            case 2:
                DoCast(me, SPELL_VILE_AMBUSH_FILTER, true);
                break;
            case SPELL_VILE_AMBUSH_JUMP:
            //    me->SetAnimTier(0);
                me->SetDisableGravity(false);
                me->SetReactState(REACT_AGGRESSIVE);
                if (IsMythic())
                 //   me->CastSpellDelay(me, SPELL_TANGLED_WEBS_AT, true, 100);
                break;
            }
        }
        if (type == WAYPOINT_MOTION_TYPE)
        {
            if (id == 4)
            {
               // SetFlyMode(false);
                DoCast(me, SPELL_DARK_STORM_AT, true);
                checkEvadeTimer = 2000;
                events.RescheduleEvent(EVENT_CHECH_PLAYER, 5000);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;
                DoCast(me, SPELL_BERSERK, true);
            }
            else
                berserkTimer -= diff;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (checkEvadeTimer)
        {
            if (checkEvadeTimer <= diff)
            {
                checkEvadeTimer = 2000;
                if (me->GetDistance(platformPos[platformId]) > 45.0f)
                {
                    Talk(11); //Platform Evade
                   // EnterEvadeMode();
                    return;
                }
            }
            else
                checkEvadeTimer -= diff;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_REACT_AGGRESSIVE:
                me->SetReactState(REACT_AGGRESSIVE);
                if (!me->HasAura(SPELL_ENERGY_TRACKER_TRANSFORM))
                    DoCast(me, SPELL_ENERGY_TRACKER_TRANSFORM, true);
                break;
            case EVENT_SPIDER_TRANSFORM:
                me->RemoveAurasDueToSpell(SPELL_DARKWING_FORM);
                me->RemoveAurasDueToSpell(SPELL_DARK_STORM_AURA);
                //me->RemoveAreaObject(SPELL_DARK_STORM_AT);
                DoCast(me, SPELL_SPIDER_TRANSFORM, true);
                DoCast(SPELL_SPIDER_TRANSFORM_DUMMY);
                EventsForm(SPIDER_FORM);
                break;
            case EVENT_DARKWING_FORM:
                me->RemoveAurasDueToSpell(SPELL_SPIDER_TRANSFORM);
                DoCast(me, SPELL_DARKWING_FORM, true);
                DoCast(SPELL_DARKWING_FORM_DUMMY);
                EventsForm(DARKWING_FORM);
                break;
            case EVENT_WEB_OF_PAIN:
                DoCast(SPELL_WEB_OF_PAIN_FILTER);
                break;
            case EVENT_FEEDING_TIME:
                Talk(SAY_FEEDING_TIME);
                Talk(SAY_FEEDING_TIME_1);
                DoCast(SPELL_FEEDING_TIME);
                events.RescheduleEvent(EVENT_FEEDING_TIME, 50000);
                break;
            case EVENT_NECROTIC_VENOM:
                DoCast(SPELL_NECROTIC_VENOM);
                events.RescheduleEvent(EVENT_NECROTIC_VENOM, 22000);
                break;
            case EVENT_TWISTING_SHADOWS:
                DoCast(SPELL_TWISTING_SHADOWS_FILTER);
                events.RescheduleEvent(EVENT_TWISTING_SHADOWS, 40000);
                break;
            case EVENT_GATHERING_CLOUDS:
                Talk(SAY_GATHERING_CLOUDS);
                Talk(SAY_GATHERING_CLOUDS_1);
                DoCast(SPELL_GATHERING_CLOUDS);
                events.RescheduleEvent(EVENT_SUM_SHIMMERING_FEATHER, 8000);
                break;
            case EVENT_SUM_SHIMMERING_FEATHER:
            {
                Position pos;
                float angle = -1.0f;
                for (uint8 i = 0; i < 8; ++i)
                {
                  //  me->GetNearPosition(pos, 15.0f, angle);
                    me->CastSpell(pos.GetPosition(), SPELL_SHIMMERING_FEATHER_TRIG, true);
                    angle += 0.25f;
                }
                break;
            }
            case EVENT_RAZOR_WING:
                Talk(SAY_RAZOR_WING);
                Talk(SAY_RAZOR_WING_1);
                DoCast(me, SPELL_RAZOR_WING_FILTER, true);
                events.RescheduleEvent(EVENT_RAZOR_WING, 32000);
                break;
            case EVENT_DARK_STORM:
                for (uint8 i = 0; i < 5; ++i)
                    me->SummonCreature(NPC_TWISTING_SHADOWS_BRIDGE, twistBridgePos[i]);
                DoCast(SPELL_DARK_STORM_FILTER);
                events.RescheduleEvent(EVENT_NEXT_PLATFORM, 5000);
                break;
            case EVENT_RAKING_TALONS:
              //  DoCastTopAggro(SPELL_RAKING_TALONS);
                events.RescheduleEvent(EVENT_RAKING_TALONS, 30000);
                break;
            case EVENT_VIOLENT_WINDS:
                DoCast(SPELL_VIOLENT_WINDS);
                events.RescheduleEvent(EVENT_VIOLENT_WINDS, 40500);
                break;
            case EVENT_NEXT_PLATFORM:
                checkEvadeTimer = 0;
                me->SetReactState(REACT_PASSIVE);
                DoCast(me, SPELL_DARK_STORM_AURA, true);
               // SetFlyMode(true);
                me->GetMotionMaster()->MovePath(me->GetEntry() * 100 + platformId, false);
                if (++platformId == 3)
                    platformId = 0;
                break;
            case EVENT_CHECH_PLAYER:
                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 30.0f, true))
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.RescheduleEvent(EVENT_RAKING_TALONS, 7000);
                }
                else
                    events.RescheduleEvent(EVENT_CHECH_PLAYER, 1000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//107459
struct npc_elerethe_venomous_spiderling : public ScriptedAI
{
    npc_elerethe_venomous_spiderling(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
    }

    uint32 moveTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetDisableGravity(true);
        moveTimer = 500;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        me->SetDisableGravity(false);
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
        me->SetReactState(REACT_AGGRESSIVE);
        DoZoneInCombat(me, 120.0f);

        if (IsMythic())
            me->CastSpell(me, SPELL_SWARM, true);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (auto summoner = me->GetOwner())
            me->CastSpell(me, 213123, true, NULL, NULL, summoner->GetGUID());
    }

    void UpdateAI(uint32 diff) override
    {
        if (moveTimer)
        {
            if (moveTimer <= diff)
            {
                moveTimer = 0;
                me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 32.0f);
            }
            else
                moveTimer -= diff;
        }

        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        DoMeleeAttackIfReady();
    }
};

//106350, 107767, 111439
struct npc_elerethe_twisting_shadows : public ScriptedAI
{
    npc_elerethe_twisting_shadows(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    EventMap events;
    ObjectGuid playerGUID;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        if (me->GetEntry() == 107767) //Twisting Passenger
            return;

        if ((me->GetEntry() == NPC_TWISTING_SHADOWS) && (summoner->IsInCombat()))
            me->GetMotionMaster()->MoveRandom(10.0f);

        if (me->GetEntry() == NPC_TWISTING_SHADOWS_BRIDGE)
        {
            for (uint8 i = 0; i < 5; ++i)
                if (me->GetDistance(twistBridgePos[i]) < 5.0f)
                    me->GetMotionMaster()->MovePath((me->GetEntry() * 100 + i), true);
        }

        DoCast(me, SPELL_TWISTING_SHADOWS_AT, true);
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (me->GetEntry() != 107767 || apply)
            return;

        playerGUID = who->GetGUID();
        events.RescheduleEvent(1, 300);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
                    player->KnockbackFrom(me->GetPositionX(), me->GetPositionY(), 30, 10);
                break;
            }
        }
    }
};

//108540
struct npc_elerethe_surging_egg_sac : public ScriptedAI
{
    npc_elerethe_surging_egg_sac(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    EventMap events;
    bool animSwitch = false;

    void Reset() override
    {
        events.RescheduleEvent(1, frand(1000, 10000));
        events.RescheduleEvent(2, 500);
    }

    void SpellHit(Unit* caster, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_EGG_DUMMY_1)
        {
            DoCast(me, SPELL_EGG_DUMMY_2, true);
        //    me->PlayOneShotAnimKit(ANIM_3);
        }
        if (spell->Id == SPELL_EGG_DUMMY_2)
        {
            for (uint8 i = 0; i < 4; ++i)
            {
                Position pos;
                me->GetRandomNearPosition(3.0f);
                me->CastSpell(pos, SPELL_SUM_SKITTERING_SPIDERLING, true);
            }
            me->DespawnOrUnsummon(3000);
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
                me->SetMovementAnimKitId(animSwitch ? ANIM_1 : ANIM_2);
                animSwitch = animSwitch ? false : true;
                events.RescheduleEvent(1, 2500);
                break;
            case 2:
            {
                if (instance->GetBossState(DATA_RENFERAL) == IN_PROGRESS)
                {
                   // if (Unit* plr = me->FindNearestPlayer(5.0f))
                       // if (me->GetDistance(plr) < 2.0f)
                        {
                            events.Reset();
                            DoCast(me, SPELL_EGG_DUMMY_1, true);
                            break;
                        }
                }
                events.RescheduleEvent(2, 500);
                break;
            }
            }
        }
    }
};

//112039
struct npc_en_venomous_spider : public ScriptedAI
{
    npc_en_venomous_spider(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
        std::list<Creature*> creatureList;
        me->GetCreatureListWithEntryInGrid(creatureList, 113626, 100.0f);
        for (auto creature : creatureList)
            creature->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->CastSpell(me, 222925, true);
    }

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.RescheduleEvent(1, urandms(5, 6));
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == 226070)
        {
            Position pos;
            pos = me->GetPosition();
            pos.m_positionZ += 40.0f;
            me->SummonCreature(113626, pos);
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
                me->SetReactState(REACT_PASSIVE);
                me->SetReactState(REACT_AGGRESSIVE);
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, 226073, true);
                events.RescheduleEvent(2, 1500);
                events.RescheduleEvent(1, urandms(24, 25));
                break;
            case 2:
                DoCast(226070);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//111980
struct npc_en_nightmother : public ScriptedAI
{
    npc_en_nightmother(Creature* creature) : ScriptedAI(creature)
    {
        me->SetSpeed(MOVE_FLIGHT, 4.0f);
    }

    EventMap events;
    uint32 jumpTimer;

    void Reset() override
    {
        events.Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetDisableGravity(false);
        me->SetCanFly(false);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.RescheduleEvent(1, urandms(4, 5));
        events.RescheduleEvent(2, 15000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (jumpTimer)
        {
            if (jumpTimer <= diff)
            {
                jumpTimer = 0;
                me->SetDisableGravity(false);
                me->SetCanFly(false);
                me->GetMotionMaster()->Clear();
                me->SetReactState(REACT_AGGRESSIVE);
            }
            else
                jumpTimer -= diff;
        }

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                DoCast(223057);
                events.RescheduleEvent(1, urandms(10, 13));
                break;
            case 2:
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetDisableGravity(true);
                me->SetCanFly(true);
               // me->GetMotionMaster()->MoveTakeoff(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 32.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                {
                    me->CastSpell(target, 223022, true);
                    jumpTimer = 6000;
                    events.DelayEvent(1, 7000);
                }
                events.RescheduleEvent(2, 29000);
                break;
            }
            }
        }
        DoMeleeAttackIfReady();
    }
};

//111975
struct npc_en_shadowfeather : public ScriptedAI
{
    npc_en_shadowfeather(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.RescheduleEvent(1, 35000);
        events.RescheduleEvent(2, 4000);
    }

    void Reset() override
    {
        events.Reset();
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
                events.DelayEvent(2, 6000);
                DoCast(222999);
                events.RescheduleEvent(1, 22000);
                break;
            case 2:
                DoCastVictim(222996);
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                {
                  //  me->CastSpellDelay(target, 222996, false, 4000);
                 //   me->CastSpellDelay(target, 222996, false, 8000);
                }
                events.RescheduleEvent(2, 20000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//106311
struct npc_en_venomous_spiderling : public ScriptedAI
{
    npc_en_venomous_spiderling(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;
    uint32 checkBossState = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        checkBossState = 2000;
        DoZoneInCombat(me, 150.0f);

        if (IsMythic())
            me->CastSpell(me, SPELL_SWARM, true);
    }

    void Reset() override {}

    void EnterCombat(Unit* /*who*/) override {}

    void UpdateAI(uint32 diff) override
    {
        if (checkBossState)
        {
            if (checkBossState <= diff)
            {
                checkBossState = 2000;

                if (instance->GetBossState(DATA_RENFERAL) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }
            }
            else
                checkBossState -= diff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

//223029
class spell_en_wretched_ambush : public SpellScript
{
    PrepareSpellScript(spell_en_wretched_ambush);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        auto caster = GetCaster();
        auto target = GetHitUnit();
        if (!caster || !target)
            return;

        float dist = caster->GetDistance(target);
        if (dist < 15.0f)
            SetHitDamage(GetHitDamage() * (0.1f + 0.9f * (15.0f - dist) / 15.0f));
        else
            SetHitDamage(GetHitDamage() * 0.1f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_en_wretched_ambush::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//225364
class spell_elerethe_energy_tracker_transform : public AuraScript
{
    PrepareAuraScript(spell_elerethe_energy_tracker_transform);

    uint8 powerTick = 0;

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsInCombat())
            return;

        uint8 powerCount = caster->GetPower(POWER_ENERGY);

        if (powerCount < 100)
        {
            if (powerTick < 9)
            {
                powerTick++;
                caster->SetPower(POWER_ENERGY, powerCount + 1);
            }
            else
            {
                powerTick = 0;
                caster->SetPower(POWER_ENERGY, powerCount + 2);
            }
        }
        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
            caster->CastSpell(caster, SPELL_ENERGY_TRANSFORM_COST);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_elerethe_energy_tracker_transform::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//215288
class spell_elerethe_web_of_pain_filter : public SpellScript
{
    PrepareSpellScript(spell_elerethe_web_of_pain_filter);

    Unit* secondTarget = nullptr;

    void FilterTargets(std::list<WorldObject*>& targetsList)
    {
        std::list<WorldObject*> tankList;

        if (targetsList.size() > 1)
        {
            secondTarget = nullptr;

            for (auto plrTarget : targetsList)
            {
                if (auto plr = plrTarget->ToPlayer())
                {
                   // if (plr->isInTankSpec())
                        tankList.push_front(plrTarget);
                   // else
                    {
                        if (!secondTarget && plrTarget->ToUnit())
                            secondTarget = plrTarget->ToUnit();
                        else if (secondTarget && plrTarget->ToUnit())
                        {
                            secondTarget->CastSpell(plrTarget->ToUnit(), 215300, true);
                            plrTarget->ToUnit()->CastSpell(secondTarget, 215307, true);
                            break;
                        }
                    }
                }
            }
        }

        if (tankList.size() > 1)
        {
            secondTarget = nullptr;

            for (auto tankTarget : tankList)
            {
                if (!secondTarget && tankTarget->ToUnit())
                    secondTarget = tankTarget->ToUnit();
                else if (secondTarget && tankTarget->ToUnit())
                {
                    secondTarget->CastSpell(tankTarget->ToUnit(), 215300, true);
                    tankTarget->ToUnit()->CastSpell(secondTarget, 215307, true);
                    return;
                }
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elerethe_web_of_pain_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//215300, 215307
class spell_elerethe_web_of_pain : public AuraScript
{
    PrepareAuraScript(spell_elerethe_web_of_pain);

    void CalculateAmount(AuraEffect const* /*aurEff*/, float& amount, bool& /*canBeRecalculated*/)
    {
        amount = 100;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, float& absorbAmount)
    {
        absorbAmount = 0;

        if (!GetCaster() || !GetTarget() || !dmgInfo.GetAttacker() || dmgInfo.GetAttacker()->IsPlayer())
            return;

       // if (float dmg = dmgInfo.GetDamage())
        //    GetTarget()->CastCustomSpell(GetCaster(), 233485, &dmg, nullptr, nullptr, true);
    }

    void OnTick(AuraEffect const* aurEff)
    {
        if (!GetCaster() || !GetTarget() || GetCaster()->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            return;

       // GetCaster()->GetMap()->ApplyOnEveryPlayer([&](Player* player)
       // {
         //   if (player->GetGUID() == GetCaster()->GetGUID() || player->GetGUID() == GetTarget()->GetGUID())
           //     return;

         //   if (player->IsInBetween(GetCaster(), GetTarget(), 1.0f))
            //    player->CastSpell(player, SPELL_PAIN_LASH, true);
      //  });
    }

    void Register() override
    {
       // DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_elerethe_web_of_pain::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
      //  OnEffectAbsorb += AuraEffectAbsorbFn(spell_elerethe_web_of_pain::Absorb, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_elerethe_web_of_pain::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//214348
class spell_elerethe_vile_ambush : public SpellScript
{
    PrepareSpellScript(spell_elerethe_vile_ambush);

    void DealDamage()
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        float distance = GetCaster()->GetExactDist2d(GetHitUnit());
       // float radius = GetSpellInfo()->Effects[EFFECT_0]->CalcRadius(GetCaster());
        uint32 perc;
        if (distance < 15.0f)
            perc = 100 - (distance / 10) * 30;
      //  else
         //   perc = 20 - (distance / radius) * 30;

        uint32 damage = CalculatePct(GetHitDamage(), perc);
        SetHitDamage(damage);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_elerethe_vile_ambush::DealDamage);
    }
};

//214311
class spell_elerethe_feeding_time_filter : public SpellScript
{
    PrepareSpellScript(spell_elerethe_feeding_time_filter);

    void FilterTargets(std::list<WorldObject*>& targetsList)
    {
        std::list<WorldObject*> tempTargets;
        for (auto target : targetsList)
            if (GetCaster()->IsWithinLOSInMap(target))
                tempTargets.push_back(target);

        targetsList.clear();

        if (!tempTargets.empty())
            targetsList = tempTargets;
        else
        {
            if (auto caster = GetCaster()->ToCreature())
            {
                caster->AI()->Talk(10);
                caster->AI()->EnterEvadeMode();
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elerethe_feeding_time_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//215449
class spell_elerethe_necrotic_venom : public AuraScript
{
    PrepareAuraScript(spell_elerethe_necrotic_venom);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
       // if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

     //   GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0]->BasePoints, true, nullptr, nullptr, GetCaster()->GetGUID());
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_elerethe_necrotic_venom::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

//212993
class spell_elerethe_shimmering_feather_proc : public AuraScript
{
    PrepareAuraScript(spell_elerethe_shimmering_feather_proc);

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (GetCaster())
            GetCaster()->CastSpell(GetCaster(), SPELL_SHIMMERING_FEATHER_OVERRIDE, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_elerethe_shimmering_feather_proc::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_elerethe_renferal()
{
    RegisterCreatureAI(boss_elerethe_renferal);
    RegisterCreatureAI(npc_elerethe_venomous_spiderling);
    RegisterCreatureAI(npc_elerethe_twisting_shadows);
    RegisterCreatureAI(npc_elerethe_surging_egg_sac);
    RegisterCreatureAI(npc_en_venomous_spider);
    RegisterCreatureAI(npc_en_nightmother);
    RegisterCreatureAI(npc_en_shadowfeather);
    RegisterCreatureAI(npc_en_venomous_spiderling);
    RegisterAuraScript(spell_elerethe_energy_tracker_transform);
    RegisterSpellScript(spell_elerethe_web_of_pain_filter);
    RegisterAuraScript(spell_elerethe_web_of_pain);
    RegisterSpellScript(spell_elerethe_vile_ambush);
    RegisterSpellScript(spell_elerethe_feeding_time_filter);
    RegisterAuraScript(spell_elerethe_necrotic_venom);
    RegisterAuraScript(spell_elerethe_shimmering_feather_proc);
    RegisterSpellScript(spell_en_wretched_ambush);
}

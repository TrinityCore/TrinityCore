/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "tomb_of_sargeras.h"

enum Says
{
    //Captain Yathae Moonstrike
    SAY_TWILIGHT_VOLLEY = 0,
    SAY_INCORPOREAL_SHOT_WARN = 1,
    SAY_RAPID_SHOT = 2,

    //Priestess Lunaspyre
    SAY_EMBRACE_ECLIPSE_WARN = 0,
    SAY_EMBRACE_ECLIPSE = 1,
    SAY_MOON_BURN = 2,
};

enum Spells
{
    SPELL_SHARED_HEALTH = 235215,
    SPELL_PHASE_1_CONVERSATION = 243034,
    SPELL_PHASE_2_CONVERSATION = 243044,
    SPELL_PHASE_3_CONVERSATION = 243047,
    SPELL_INCORPOREAL_TELEPORT = 236115,
    SPELL_LUNAR_GHOST = 235268,
    SPELL_LUNAR_GHOST_CAT = 235270,
    SPELL_CORPOREAL_GHOST = 234999,
    SPELL_CORPOREAL_GHOST_MOUNT = 236324,
    SPELL_BERSERK = 243262,

    SPELL_FONT_OF_ELUNE_AT = 236357,
    SPELL_LIGHT_SIDE_MOON_AT = 234565,
    SPELL_LIGHT_SIDE_MOON_WANING = 234587,
    SPELL_LIGHT_SIDE_MOON_DUMMY = 234664,
    SPELL_LUNAR_SUFFUSION = 234995,
    SPELL_DARK_SIDE_MOON_AT = 234657,
    SPELL_DARK_SIDE_MOON_WANING_AT = 234659,
    SPELL_DARK_SIDE_MOON_DUMMY = 234668,
    SPELL_UMBRA_SUFFUSION = 234996,
    SPELL_ASTRAL_PURGE = 234998,
    SPELL_ASTRAL_VULNERABILITY = 236330, //Mythic

    //Huntress Kasparian
    SPELL_MOON_GLAIVE = 236547,
    SPELL_DISCORPORATE = 236550,
    SPELL_TWILIGHT_GLAIVE_FILTER = 237561,
    SPELL_TWILIGHT_GLAIVE_AT = 236529, //Dmg 236541
    SPELL_SABERLEAP = 236344,
    SPELL_SPECTRAL_GLAIVE = 237633,
    SPELL_GLAIVE_STORM_FILTER_BIG = 239378,
    SPELL_GLAIVE_STORM_FILTER_MEDIUM = 239382,
    SPELL_GLAIVE_STORM_FILTER_SMALL = 239385,
    SPELL_GLAIVE_STORM_AT_BIG = 239379,
    SPELL_GLAIVE_STORM_AT_MEDIUM = 239383,
    SPELL_GLAIVE_STORM_AT_SMALL = 239386,

    //Priestess Lunaspyre
    SPELL_MOON_BURN_FILTER = 236518,
    SPELL_MOON_BURN_DMG = 236519,
    SPELL_LUNAR_STRIKE = 237632,
    SPELL_LUNAR_BEACON = 236712,
    SPELL_LUNAR_BARRAGE_MARK = 236717,
    SPELL_LUNAR_BARRAGE_AT = 236726,
    SPELL_LUNAR_FIRE = 239264,
    SPELL_EMBRACE_ECLIPSE = 233263,
    SPELL_EMBRACE_ECLIPSE_FRIEND = 233264,
    SPELL_LUNAR_DETONATION = 237782,
    SPELL_UMBRA_DETONATION = 233284,

    //Captain Yathae Moonstrike
    SPELL_INCORPOREAL_SHOT_FILTER = 236304,
    SPELL_INCORPOREAL_SHOT_MARK = 236305,
    SPELL_INCORPOREAL_SHOT_DMG_BETWEEN = 236306,
    SPELL_INCORPOREAL_SHOT_DMG_AOE = 248911,
    SPELL_INCORPOREAL_SHOT_VISUAL = 237570,
    SPELL_TWILIGHT_VOLLEY_AT = 236442,
    SPELL_SHADOW_SHOT = 237630,
    SPELL_CALL_MOONTALON = 236694,
    SPELL_RAPID_SHOT_FILTER_MARK = 236672,
    SPELL_RAPID_SHOT_FILTER_DMG = 236600,
    SPELL_RAPID_SHOT_MARK = 236596,
    SPELL_RAPID_SHOT_DMG = 236603,

    //Moontalon
    SPELL_MOONTALON_DISSOLVE_IN = 239960,
    SPELL_DEATHLY_SCREECH = 236697,

    //achieve add
    SPELL_CRY_OF_THE_LOST_SOULS = 242494,
};

enum eEvents
{
    //Huntress Kasparian
    EVENT_MOON_GLAIVE = 1,
    EVENT_TWILIGHT_GLAIVE = 2,
    EVENT_JUMP_KASPARIAN = 3,
    EVENT_SPECTRAL_GLAIVE = 4,
    EVENT_GLAIVE_STORM = 5,

    //Priestess Lunaspyre
    EVENT_MOON_BURN = 1,
    EVENT_LUNAR_STRIKE = 2,
    EVENT_TP_LUNASPERE = 3,
    EVENT_LUNAR_BEACON = 4,
    EVENT_LUNAR_FIRE = 5,
    EVENT_EMBRACE_ECLIPSE = 6,

    //Captain Yathae
    EVENT_INCORPOREAL_SHOT = 1,
    EVENT_TWILIGHT_VOLLEY = 2,
    EVENT_SHADOW_SHOT = 3,
    EVENT_TP_YATHAE = 4,
    EVENT_CALL_MOONTALON = 5,
    EVENT_RAPID_SHOT = 6,
};

enum Achieve { ACHIEVEMENT = 1 };

uint32 const sistersEntry[3] =
{
    NPC_HUNTRESS_KASPARIAN,
    NPC_PRIESTESS_LUNASPYRE,
    NPC_CAPTAIN_YATHAE
};

Position const sistersPos[3] =
{
    {6208.61f, -1026.84f, 2899.56f, 2.77f},
    {6208.68f, -1037.31f, 2899.55f, 2.97f},
    {6215.13f, -1019.96f, 2899.55f, 2.66f}
};

Position const centrPos = { 6190.06f, -1020.03f, 2899.50f };

//118182
struct boss_sisters_of_the_moon : BossAI
{
    explicit boss_sisters_of_the_moon(Creature* creature) : BossAI(creature, DATA_SISTERS_OF_THEMOON)
    {
        if (me->IsAlive())
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
          //  me->AddDelayedCombat(500, [=]() -> void { DoAction(ACTION_1); });
        }
    }

    std::vector<ObjectGuid> sistersVector;
    bool lightSideMoon = true;
    uint8 sisterDiedCount = 0;
    uint32 sideMoonTimer = 0;
    uint32 berserkTimer = 0;

    void Reset() override
    {
        if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) != NOT_STARTED)
            instance->SetBossState(DATA_SISTERS_OF_THEMOON, NOT_STARTED);
    }

    void DoAction(int32 const action) override
    {
        if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) == DONE)
            return;

        switch (action)
        {
        case 1: //Summon Sister
        {
            sistersVector.clear();
            sisterDiedCount = 0;
            for (uint8 i = 0; i < 3; ++i)
                if (auto sister = me->SummonCreature(sistersEntry[i], sistersPos[i]))
                {
                    sistersVector.push_back(sister->GetGUID());
                    sister->CastSpell(sister, SPELL_SHARED_HEALTH, true);
                }
            break;
        }
        case 2: //Despawn after evade 
        {
            if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) != NOT_STARTED)
            {
                instance->SetBossState(DATA_SISTERS_OF_THEMOON, NOT_STARTED);

             //   if (auto kasparian = Creature::GetCreature(*me, sistersVector[0]))
                //    instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, kasparian);

                sideMoonTimer = 0;
                berserkTimer = 0;
                me->RemoveAurasDueToSpell(SPELL_FONT_OF_ELUNE_AT);
                //me->RemoveAllAreaObjects();

                for (auto const& guid : sistersVector)
                {
                 //  if (auto sister = Creature::GetCreature(*me, guid))
                    {
                       // instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, sister);
                      //  sister->AI()->DoAction(ACTION_2); //Despawn summons
                     //   sister->SetReactState(REACT_PASSIVE);
                    //    sister->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                      //  sister->DespawnOrUnsummon(200);
                    }
                }
               // AddDelayedCombat(5000, [=]() -> void { DoAction(ACTION_1); });
            }
            break;
        }
        case 3: //Enter Combat
        {
            if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) != IN_PROGRESS)
            {
                instance->SetBossState(DATA_SISTERS_OF_THEMOON, IN_PROGRESS);

              //  if (auto kasparian = Creature::GetCreature(*me, sistersVector[0]))
               //     instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_START, kasparian);

                DoCast(me, SPELL_FONT_OF_ELUNE_AT, true);
                DoCast(me, SPELL_DARK_SIDE_MOON_AT, true);
                lightSideMoon = true;
                sideMoonTimer = 48000;

                if (IsMythic())
                    berserkTimer = 11 * MINUTE * IN_MILLISECONDS;

                for (auto const& guid : sistersVector)
                {
                   // if (auto sister = Creature::GetCreature(*me, guid))
                   //     if (sister->isAlive() && !sister->isInCombat())
                     //       sister->AI()->DoZoneInCombat(sister, 100.0f);
                }
            }
            break;
        }
        case 4: //Phase 2
        {
           // if (auto lunaspyre = Creature::GetCreature(*me, sistersVector[1]))
            //    lunaspyre->AI()->DoAction(ACTION_1); //Lunaspyre set Phase 2

           // if (auto yathae = Creature::GetCreature(*me, sistersVector[2]))
           //     yathae->AI()->DoAction(ACTION_1); //Yathae set Phase 2
            break;
        }
        case 5: //Phase 3
        {
           // if (auto kasparian = Creature::GetCreature(*me, sistersVector[0]))
             //   kasparian->CastSpell(kasparian, SPELL_PHASE_3_CONVERSATION, true);

          //  if (auto lunaspyre = Creature::GetCreature(*me, sistersVector[1]))
            //    lunaspyre->AI()->DoAction(ACTION_3); //Lunaspyre set Phase 3
        }
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_HUNTRESS_KASPARIAN:
        case NPC_PRIESTESS_LUNASPYRE:
        case NPC_CAPTAIN_YATHAE:
        {
            if (++sisterDiedCount == 3)
            {
                if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) != DONE)
                {
                    instance->SetBossState(DATA_SISTERS_OF_THEMOON, DONE);

                  ////  if (auto kasparian = Creature::GetCreature(*me, sistersVector[0]))
                  //      instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, kasparian);
                }
                me->RemoveAurasDueToSpell(SPELL_FONT_OF_ELUNE_AT);
               // me->RemoveAllAreaObjects();
                me->DespawnOrUnsummon();
            }
            break;
        }
        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (sideMoonTimer)
        {
            if (sideMoonTimer <= diff)
            {
                DoCast(me, lightSideMoon ? SPELL_LIGHT_SIDE_MOON_AT : SPELL_DARK_SIDE_MOON_AT, true);
                lightSideMoon = lightSideMoon ? false : true;
                sideMoonTimer = 54000;

               // if (auto kasparian = Unit::GetCreature(*me, sistersVector[0]))
               //     kasparian->AI()->DoAction(ACTION_4); //Glaive Storm

               // if (auto lunaspyre = Unit::GetCreature(*me, sistersVector[1]))
                //    lunaspyre->AI()->DoAction(ACTION_4); //Embrace of the Eclipse

              //  if (auto yathae = Unit::GetCreature(*me, sistersVector[2]))
               //     yathae->AI()->DoAction(ACTION_3); //Incorporeal Shot
            }
            else
                sideMoonTimer -= diff;
        }

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;

                for (auto const& guid : sistersVector)
                {
                   // if (auto boss = Unit::GetCreature(*me, guid))
                     //   boss->CastSpell(boss, SPELL_BERSERK, true);
                }
            }
            else
                berserkTimer -= diff;
        }
    }
};

//118523
struct npc_sister_kasparian : ScriptedAI
{
    explicit npc_sister_kasparian(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_DEFENSIVE);
    }

    InstanceScript* instance;
    EventMap events;
    uint8 phase = 0;
    uint8 healthPct = 71;
    bool achieveAddData = false;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_CORPOREAL_GHOST_MOUNT, true);
    }

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        DoCast(me, SPELL_PHASE_1_CONVERSATION, true);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(3);

       // DefaultEvents(++phase);
        achieveAddData = false;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == ACHIEVEMENT)
            return achieveAddData ? 1 : 0;
        return 0;
    }
    /*
    void DefaultEvents(uint8 phase)
    {
        events.Reset();

        switch (phase)
        {
        case 1:
            events.RescheduleEvent(EVENT_MOON_GLAIVE, 14000);
            events.RescheduleEvent(EVENT_TWILIGHT_GLAIVE, 20000);
            break;
        case 2:
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            //me->RemoveAurasAllDots();
            DoCast(me, SPELL_LUNAR_GHOST, true);
            DoCast(me, SPELL_LUNAR_GHOST_CAT, true);
            DoCast(me, SPELL_PHASE_2_CONVERSATION, true);
            if (auto summoner = me->GetOwner())
            {
                summoner->GetAI()->DoAction(4); //Phase 2
            }
          //  me->AddDelayedCombat(2000, [=]() -> void
            {
                me->CastSpell(me->GetHomePosition(), SPELL_SABERLEAP, true);
          //  });
            events.RescheduleEvent(EVENT_JUMP_KASPARIAN, 20000);
            events.RescheduleEvent(EVENT_TWILIGHT_GLAIVE, 8000);
            events.RescheduleEvent(EVENT_SPECTRAL_GLAIVE, 5000);
            break;
        }
    }
        */
    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(2);
    }

    void JustDied(Unit* killer) override
    {
        me->Dismount();
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_TWILIGHT_GLAIVE_FILTER:
          //  me->SetFacingTo(target);
            me->CastSpell(target, SPELL_TWILIGHT_GLAIVE_AT, false);
            break;
        }
    }
/*
    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId) override
    {
        if (!target || target->GetEntry() != NPC_GLAIVE_TARGET)
            return;

        switch (createATSpellId)
        {
        case SPELL_GLAIVE_STORM_AT_BIG:
            target->CastSpell(target, SPELL_GLAIVE_STORM_FILTER_MEDIUM, true, nullptr, nullptr, me->GetGUID());
            break;
        }
    }
    */
    void MovementInform(uint32 type, uint32 id)
    {
        if (type == EFFECT_MOTION_TYPE)
        {
            switch (id)
            {
            case SPELL_SABERLEAP:
               // me->AddDelayedCombat(500, [=]() -> void { me->SetFacingTo(centrPos.GetAngle(me) - M_PI); });
                break;
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (healthPct && me->HealthBelowPct(healthPct))
        {
            healthPct = 0;
          //  DefaultEvents(++phase);
        }

        if (me->HealthBelowPct(20) && !achieveAddData)
        {
            achieveAddData = true;
            if (auto add = instance->instance->GetCreature(instance->GetGuidData(NPC_SISTERS_ACH_ADD)))
                if (add->IsAIEnabled)
                    add->AI()->DoAction(1);
        }
    }

    void DoAction(int32 const actionID) override
    {
        switch (actionID)
        {
        case 1:
            achieveAddData = true;
            break;
        case 4:
            if ((phase == 2 && IsHeroic()) || phase == 3)
                events.RescheduleEvent(EVENT_GLAIVE_STORM, 500);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

       // if (CheckHomeDistToEvade(diff, 22.0f, 6190.06f, -1020.03f, 2899.5f))
       //     return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MOON_GLAIVE:
            //    DoCastTopAggro(SPELL_MOON_GLAIVE);
                events.RescheduleEvent(EVENT_MOON_GLAIVE, 18000);
                break;
            case EVENT_TWILIGHT_GLAIVE:
                DoCast(SPELL_TWILIGHT_GLAIVE_FILTER);
                if (phase > 1)
                    events.DelayEvents(3000);
                events.RescheduleEvent(EVENT_TWILIGHT_GLAIVE, 18000);
                break;
            case EVENT_JUMP_KASPARIAN:
            {
                Position pos;
                //centrPos.SimplePosXYRelocationByAngle(pos, 18.0f, centrPos.GetAngle(me) + frand(1.5f, 3.14f));
                me->GetMotionMaster()->Clear();
                me->CastSpell(pos, SPELL_SABERLEAP, false);
                events.DelayEvents(1500);
                events.RescheduleEvent(EVENT_JUMP_KASPARIAN, urand(20, 35) * IN_MILLISECONDS);
                break;
            }
            case EVENT_SPECTRAL_GLAIVE:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                {
                 //   me->SetFacingTo(target);
                    DoCast(target, SPELL_SPECTRAL_GLAIVE);
                }
                events.RescheduleEvent(EVENT_SPECTRAL_GLAIVE, 5000);
                break;
            case EVENT_GLAIVE_STORM:
                events.DelayEvents(100);
                DoCast(SPELL_GLAIVE_STORM_FILTER_BIG);
                break;
            }
        }
        if (phase == 1)
            DoMeleeAttackIfReady();
    }
};

//118518
struct npc_sister_lunaspyre : ScriptedAI
{
    explicit npc_sister_lunaspyre(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    EventMap events;
    uint8 phase = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_LUNAR_GHOST, true);
    }

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        //me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_STATE_READY2HL);
        DefaultEvents(++phase);
    }

    void DefaultEvents(uint8 phase)
    {
        events.Reset();

        switch (phase)
        {
        case 1:
            events.RescheduleEvent(EVENT_MOON_BURN, 10000);
            events.RescheduleEvent(EVENT_LUNAR_STRIKE, 500);
            events.RescheduleEvent(EVENT_TP_LUNASPERE, 16000);
            break;
        case 3:
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SetReactState(REACT_AGGRESSIVE);
            events.RescheduleEvent(EVENT_LUNAR_BEACON, 18000);
            events.RescheduleEvent(EVENT_MOON_BURN, 10000);
            events.RescheduleEvent(EVENT_LUNAR_FIRE, 7000);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetOwner())
            summoner->GetAI()->DoAction(2);
    }

  //  void JustDied(Unit* killer) override
 //   {
  //      instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
     //   me->RemoveAllAreaObjects();
  //  }

 //   bool IsDisableGenerateLoot() override
  //  {
   //     return true;
   // }

    void DoAction(int32 const actionID) override
    {
        switch (actionID)
        {
        case 1:
            ++phase;
            break;
        case 2:
         //   me->RemoveAllAreaObjects();
            break;
        case 3:
            DefaultEvents(++phase);
            DoCast(me, SPELL_CORPOREAL_GHOST, true);
            me->CastSpell(centrPos, SPELL_INCORPOREAL_TELEPORT, true);
            break;
        case 4:
            if ((phase == 1 && IsHeroic()) || phase == 2)
                events.RescheduleEvent(EVENT_EMBRACE_ECLIPSE, 500);
            break;
        }
    }

    void SpellFinishCast(const SpellInfo* spell) //override
    {
        switch (spell->Id)
        {
        case SPELL_INCORPOREAL_TELEPORT:
          //  me->AddDelayedCombat(1000, [=]() -> void { me->SetFacingTo(centrPos.GetAngle(me) - M_PI); });
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_MOON_BURN_FILTER:
            me->CastSpell(target, SPELL_MOON_BURN_DMG, true);
            break;
        }
    }

   /* void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode) override
    {
        if (me->isInCombat() && target && mode == AURA_REMOVE_BY_EXPIRE)
        {
            switch (spellId)
            {
            case SPELL_LUNAR_BEACON:
                target->CastSpell(target, SPELL_LUNAR_BARRAGE_MARK, true);
                break;
            }
        }
    }
    */
    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

      //  if (CheckHomeDistToEvade(diff, 22.0f, 6190.06f, -1020.03f, 2899.5f))
         //   return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_MOON_BURN:
                Talk(SAY_MOON_BURN);
                DoCast(SPELL_MOON_BURN_FILTER);
                events.RescheduleEvent(EVENT_MOON_BURN, 24000);
                break;
            case EVENT_LUNAR_STRIKE:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                {
                  //  me->SetFacingTo(target);
                    DoCast(target, SPELL_LUNAR_STRIKE);
                }
                events.RescheduleEvent(EVENT_LUNAR_STRIKE, 5500);
                break;
            case EVENT_TP_LUNASPERE:
            {
                Position pos;
               // centrPos.SimplePosXYRelocationByAngle(pos, 23.0f, centrPos.GetAngle(me) + frand(1.5f, 3.14f));
                me->GetMotionMaster()->Clear();
                me->CastSpell(pos, SPELL_INCORPOREAL_TELEPORT, false);
                events.DelayEvents(1500);
                events.RescheduleEvent(EVENT_TP_LUNASPERE, urand(20, 40) * IN_MILLISECONDS);
                break;
            }
            case EVENT_LUNAR_BEACON:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 1, 60.0f, true))
                    DoCast(target, SPELL_LUNAR_BEACON);
                events.RescheduleEvent(EVENT_LUNAR_BEACON, 22000);
                break;
            case EVENT_LUNAR_FIRE:
               // DoCastTopAggro(SPELL_LUNAR_FIRE);
                events.RescheduleEvent(EVENT_LUNAR_FIRE, 11000);
                break;
            case EVENT_EMBRACE_ECLIPSE:
                Talk(SAY_EMBRACE_ECLIPSE_WARN);
                Talk(SAY_EMBRACE_ECLIPSE);
                DoCast(me, SPELL_EMBRACE_ECLIPSE, true);
                break;
            }
        }
        if (phase == 3)
            DoMeleeAttackIfReady();
    }
};
/*
//118374
struct npc_sister_yathae : ScriptedAI
{
    explicit npc_sister_yathae(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    SummonList summons;
    InstanceScript* instance;
    EventMap events;
    uint8 phase = 0;
    uint8 healthPct = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_LUNAR_GHOST, true);
    }

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        DefaultEvents(++phase);
    }

    void DefaultEvents(uint8 phase)
    {
        events.Reset();

        switch (phase)
        {
        case 1:
            me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_STATE_READY_BOW);
            me->SetSheath(SHEATH_STATE_RANGED);
            events.RescheduleEvent(EVENT_TWILIGHT_VOLLEY, 16000);
            events.RescheduleEvent(EVENT_SHADOW_SHOT, 5000);
            events.RescheduleEvent(EVENT_TP_YATHAE, 5000);
            break;
        case 2:
            me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_ONESHOT_NONE);
            me->SetSheath(SHEATH_STATE_MELEE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_AGGRESSIVE, 2000);
            events.RescheduleEvent(EVENT_CALL_MOONTALON, 6000);
            events.RescheduleEvent(EVENT_TWILIGHT_VOLLEY, 12000);
            events.RescheduleEvent(EVENT_RAPID_SHOT, 18000);
            break;
        case 3:
            me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_STATE_READY_BOW);
            me->SetSheath(SHEATH_STATE_RANGED);
            me->StopAttack(true);
            me->SetUnitFlags(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAurasAllDots();
            DoCast(me, SPELL_LUNAR_GHOST, true);
            if (auto summoner = me->GetAnyOwner())
            {
                summoner->GetAI()->DoAction(ACTION_5); //Phase 3
            }
            me->AddDelayedCombat(2000, [=]() -> void
            {
                me->CastSpell(me->GetHomePosition(), SPELL_INCORPOREAL_TELEPORT, true);
            });
            events.RescheduleEvent(EVENT_TWILIGHT_VOLLEY, 28000);
            events.RescheduleEvent(EVENT_SHADOW_SHOT, 5000);
            break;
        }
    }

    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (auto summoner = me->GetAnyOwner())
            summoner->GetAI()->DoAction(ACTION_2);
    }

    void JustDied(Unit* killer) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->RemoveAllAreaObjects();
        summons.DespawnAll();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

   // bool IsDisableGenerateLoot() override
    {
        return true;
    }

    void DoAction(int32 const actionID) override
    {
        switch (actionID)
        {
        case 1:
            DefaultEvents(++phase);
            DoCast(me, SPELL_CORPOREAL_GHOST, true);
            me->CastSpell(centrPos, SPELL_INCORPOREAL_TELEPORT, true);
            healthPct = 41;
            break;
        case 2:
           // me->RemoveAllAreaObjects();
            summons.DespawnAll();
            break;
        case 3:
            if (phase == 1 || (phase == 3 && IsHeroic()))
                events.RescheduleEvent(EVENT_INCORPOREAL_SHOT, 500);
            break;
        }
    }

    void DamageTaken(Unit* /attacker/, uint32& damage) override
    {
        if (healthPct && me->HealthBelowPct(healthPct))
        {
            healthPct = 0;
            DefaultEvents(++phase);
        }
    }

    void SpellFinishCast(const SpellInfo* spell) //override
    {
        switch (spell->Id)
        {
        case SPELL_INCORPOREAL_TELEPORT:
          //  me->AddDelayedCombat(1000, [=]() -> void { me->SetFacingTo(centrPos.GetAngle(me) - M_PI); });
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_INCORPOREAL_SHOT_FILTER:
            me->CastSpell(target, SPELL_INCORPOREAL_SHOT_MARK, true);
            break;
        case SPELL_RAPID_SHOT_FILTER_MARK:
            me->CastSpell(target, SPELL_RAPID_SHOT_MARK, true);
            break;
        case SPELL_RAPID_SHOT_FILTER_DMG:
            me->CastSpell(target, SPELL_RAPID_SHOT_DMG, true);
            break;
        }
    }
    /*
   // void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode) override
   // {
        if (me->IsInCombat() && target && mode == AURA_REMOVE_BY_EXPIRE)
        {
            switch (spellId)
            {
            case SPELL_INCORPOREAL_SHOT_MARK:
                me->CastSpell(target, SPELL_INCORPOREAL_SHOT_VISUAL, true);
                me->CastSpell(target, SPELL_INCORPOREAL_SHOT_DMG_BETWEEN, true);
                break;
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

        //if (CheckHomeDistToEvade(diff, 22.0f, 6190.06f, -1020.03f, 2899.5f))
         //   return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_INCORPOREAL_SHOT:
                DoCast(SPELL_INCORPOREAL_SHOT_FILTER);
                break;
           // case EVENT_TWILIGHT_VOLLEY:
             //   if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit const* t) { return t->IsPlayer() && t->ToPlayer()->IsRangedDamageDealer(true); }))
               // {
                   // me->SetFacingTo(target);
                  //  me->CastSpell(target, SPELL_TWILIGHT_VOLLEY_AT);
               // }
                 if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                {
                   // me->SetFacingTo(target);
                    me->CastSpell(target, SPELL_TWILIGHT_VOLLEY_AT);
                }
             //   Talk(SAY_TWILIGHT_VOLLEY);
              //  if (phase == 1 || phase == 3)
                   // events.RescheduleEvent(EVENT_TWILIGHT_VOLLEY, 20000);
              //  else if (phase == 2)
                  //  events.RescheduleEvent(EVENT_TWILIGHT_VOLLEY, 15000);
              //  break;
            case EVENT_SHADOW_SHOT:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                {
                  //  me->SetFacingTo(target);
                    DoCast(target, SPELL_SHADOW_SHOT, true);
                }
                events.RescheduleEvent(EVENT_SHADOW_SHOT, 5500);
                break;
            case EVENT_TP_YATHAE:
            {
                Position pos;
               // centrPos.SimplePosXYRelocationByAngle(pos, phase == 1 ? 18.0f : 23.0f, centrPos.GetAngle(me) + frand(1.5f, 3.14f));
                me->GetMotionMaster()->Clear();
                me->CastSpell(pos, SPELL_INCORPOREAL_TELEPORT, false);
                events.DelayEvents(1500);
                events.RescheduleEvent(EVENT_TP_YATHAE, 18000);
                break;
            }
            case EVENT_CALL_MOONTALON:
                DoCast(SPELL_CALL_MOONTALON);
                break;
            case EVENT_RAPID_SHOT:
                Talk(SAY_RAPID_SHOT);
                DoCast(SPELL_RAPID_SHOT_FILTER_MARK);
                events.RescheduleEvent(EVENT_RAPID_SHOT, 18000);
                break;
            }
        }
        if (phase == 2)
            DoMeleeAttackIfReady();
    }
};
*/
//119205
struct npc_sistersmoon_moontalon : public ScriptedAI
{
    npc_sistersmoon_moontalon(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;
    bool screech = false;
    uint32 screechTimer = 0;

    void Reset() override {}

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_MOONTALON_DISSOLVE_IN, true);
        DoZoneInCombat(me, 100.0f);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void JustDied(Unit* killer) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!screech && me->HealthBelowPct(26))
        {
            screech = true;
            screechTimer = 3000;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (screechTimer)
        {
            if (screechTimer <= diff)
            {
                screechTimer = 6000;
                DoCast(me, SPELL_DEATHLY_SCREECH, true);
            }
            else
                screechTimer -= diff;
        }
        DoMeleeAttackIfReady();
    }
};

//119054
struct npc_sistersmoon_glaive_target : public ScriptedAI
{
    npc_sistersmoon_glaive_target(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;

    void Reset() override {}

    /*void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId) override
    {
        if (!target || target->GetEntry() != NPC_GLAIVE_TARGET)
            return;

        switch (createATSpellId)
        {
        case SPELL_GLAIVE_STORM_AT_MEDIUM:
            if (auto kasparian = instance->instance->GetCreature(instance->GetGuidData(NPC_HUNTRESS_KASPARIAN)))
                target->CastSpell(target, SPELL_GLAIVE_STORM_FILTER_SMALL, true, nullptr, nullptr, kasparian->GetGUID());
            break;
        }
    }*/

    void UpdateAI(uint32 diff) override {}
};

//121498
struct npc_sistersmoon_twilight_soul : public ScriptedAI
{
    npc_sistersmoon_twilight_soul(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        DoCast(154441);
    }

    InstanceScript* instance;
    uint32 castCry = 15000;

    void DoAction(int32 const action) override
    {
        if (action == 1)
        {
            me->RemoveAura(154441);
            DoCast(180343);
            me->SetObjectScale(1.3f);
        }
    }

    void JustDied(Unit* killer) override
    {
        if (me->HasAura(180343))
            if (auto boss = instance->instance->GetCreature(instance->GetGuidData(NPC_HUNTRESS_KASPARIAN)))
                if (boss->IsAIEnabled)
                    boss->AI()->DoAction(6);
    }

    void Reset() override
    {
        castCry = 15000;
        me->SetObjectScale(1.0f);
        DoCast(154441);
        me->RemoveAura(180343);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (castCry <= diff)
        {
            DoCast(SPELL_CRY_OF_THE_LOST_SOULS);
            castCry = urand(15000, 18000);
        }
        else castCry -= diff;
    }
};

//236306
class spell_sistersmoon_incorporeal_shot_filter : public SpellScript
{
    PrepareSpellScript(spell_sistersmoon_incorporeal_shot_filter);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> tempTargets;
        for (auto object : targets)
        {
            if (object->IsPlayer())
                tempTargets.push_back(object);
        }

        targets = tempTargets;
        targetsCount = targets.size();

        if (GetCaster() && targets.size() < 6)
            GetCaster()->CastSpell(GetCaster(), SPELL_INCORPOREAL_SHOT_DMG_AOE, true);
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void Register() override
    {
       //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sistersmoon_incorporeal_shot_filter::FilterTargets, EFFECT_0, TARGET_UNIT_BETWEEN_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_sistersmoon_incorporeal_shot_filter::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//239378, 239382, 239385
class spell_sistersmoon_glaive_storm_filter : public SpellScript
{
    PrepareSpellScript(spell_sistersmoon_glaive_storm_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        std::list<WorldObject*> tempTargets;

        for (auto target : targets)
        {
            if (GetCaster()->GetDistance(target) > 18.0f)
                tempTargets.push_back(target);
        }
        targets = tempTargets;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sistersmoon_glaive_storm_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

//234998
class spell_sistersmoon_astral_purge : public SpellScript
{
    PrepareSpellScript(spell_sistersmoon_astral_purge);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() && GetHitUnit())
        {
            if (GetCaster()->GetGUID() == GetHitUnit()->GetGUID())
            {
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_MOON_BURN_DMG);
                GetHitUnit()->RemoveAurasDueToSpell(SPELL_DISCORPORATE);
            }

            if (GetCaster()->GetMap()->IsMythic())
            {
                //> Mechanic hack
                float mod = 1.0f;
                AddPct(mod, GetHitUnit()->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC, 35));
                SetHitDamage(GetHitDamage() * mod);
                //<
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_ASTRAL_VULNERABILITY, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sistersmoon_astral_purge::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//233263, 233264
class spell_sistersmoon_embrace_eclipse : public AuraScript
{
    PrepareAuraScript(spell_sistersmoon_embrace_eclipse);

    float damage = 0;

    void CalculateAmount(AuraEffect const* /*aurEff*/, float & amount, bool& /*canBeRecalculated*/)
    {
        damage = amount;
    }

    void Absorb(AuraEffect* /*AuraEffect**/, DamageInfo& dmgInfo, float& absorbAmount)
    {
        damage = absorbAmount;
    }

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (GetTarget() && damage)
        {
          //  if (GetId() == SPELL_EMBRACE_ECLIPSE)
           //     GetTarget()->CastCustomSpell(GetTarget(), SPELL_UMBRA_DETONATION, &damage, NULL, NULL, true);
          //  else if (GetId() == SPELL_EMBRACE_ECLIPSE_FRIEND)
             //   GetTarget()->CastCustomSpell(GetTarget(), SPELL_LUNAR_DETONATION, &damage, NULL, NULL, true);
        }
    }

    void Register() override
    {
      //  DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sistersmoon_embrace_eclipse::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
      //  DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sistersmoon_embrace_eclipse::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectRemove += AuraEffectRemoveFn(spell_sistersmoon_embrace_eclipse::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_sistersmoon_embrace_eclipse::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
       // OnEffectAbsorb += AuraEffectAbsorbFn(spell_sistersmoon_embrace_eclipse::Absorb, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
       // OnEffectAbsorb += AuraEffectAbsorbFn(spell_sistersmoon_embrace_eclipse::Absorb, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

//234664, 234668
class spell_sistersmoon_side_moon : public AuraScript
{
    PrepareAuraScript(spell_sistersmoon_side_moon);

    void OnTick(AuraEffect const* aurEff)
    {
        auto target = GetUnitOwner();
        if (!target)
            return;

        if (auto instance = target->GetInstanceScript())
        {
            if (instance->GetBossState(DATA_SISTERS_OF_THEMOON) != IN_PROGRESS)
            {
               // aurEff->GetBase()->Remove();
                return;
            }
        }

        if (GetId() == SPELL_LIGHT_SIDE_MOON_DUMMY)
        {
            if (Aura* aura = target->GetAura(SPELL_DARK_SIDE_MOON_DUMMY))
            {
                target->CastSpell(target, SPELL_ASTRAL_PURGE, true);
                aura->Remove();
            }
            target->CastSpell(target, SPELL_LUNAR_SUFFUSION, true);
        }
        else if (GetId() == SPELL_DARK_SIDE_MOON_DUMMY)
        {
            if (Aura* aura = target->GetAura(SPELL_LIGHT_SIDE_MOON_DUMMY))
            {
                target->CastSpell(target, SPELL_ASTRAL_PURGE, true);
                aura->Remove();
            }
            target->CastSpell(target, SPELL_UMBRA_SUFFUSION, true);
        }
    }

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (auto target = GetTarget())
        {
            target->RemoveAurasDueToSpell(SPELL_LUNAR_SUFFUSION);
            target->RemoveAurasDueToSpell(SPELL_UMBRA_SUFFUSION);
        }
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sistersmoon_side_moon::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_sistersmoon_side_moon::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//236717
class spell_sistersmoon_lunar_barrage : public AuraScript
{
    PrepareAuraScript(spell_sistersmoon_lunar_barrage);

    void OnTick(AuraEffect const* aurEff)
    {
        auto target = GetUnitOwner();
        if (!target)
            return;

        if (auto instance = target->GetInstanceScript())
            if (auto priest = instance->instance->GetCreature(instance->GetGuidData(NPC_PRIESTESS_LUNASPYRE)))
                target->CastSpell(target, SPELL_LUNAR_BARRAGE_AT, true, nullptr, nullptr, priest->GetGUID());
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sistersmoon_lunar_barrage::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

/*
//14928, 14929, 14930
struct at_sistersmoon_glaive_storm : AreaTriggerAI
{
    at_sistersmoon_glaive_storm(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    std::list<ObjectGuid> guidList;

    void OnCreate() override
    {
        if (auto caster = at->GetCaster())
        {
            std::list<Creature*> closestList;
            GetCreatureListWithEntryInGrid(closestList, caster, NPC_GLAIVE_TARGET, 15.0f);
            for (auto creature : closestList)
                guidList.push_back(creature->GetGUID());
        }
    }

 //   bool IsValidTarget(Unit* caster, Unit* target, AreaTriggerActionMoment actionM) override
   // {
        for (auto badGuid : guidList)
            if (badGuid == target->GetGUID())
                return false;

        if (target->GetEntry() != NPC_GLAIVE_TARGET)
            return false;

        if (at->GetDistance(target) > 1.0f)
            return false;

        return true;
    }
};

//13559, 13568
struct at_sistersmoon_moon : AreaTriggerAI
{
    at_sistersmoon_moon(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

   // bool IsValidTarget(Unit* caster, Unit* target, AreaTriggerActionMoment actionM) override
    {
        if (!target || target->HasAura(27827)) //Spirit of Redemption
            return false;

        Position startPos{ 6169.41f, -1037.37f, 2899.46f };
        Position endPos{ 6210.92f, -1002.75f, 2899.46f };
        Position end, endLeft, endRight;
        float dist = 55.0f;
        float angle = endPos.GetAngle(&startPos);
        float angleLeft = angle + (-M_PI / 2);
        float angleRight = angle + (M_PI / 2);
       // endPos.SimplePosXYRelocationByAngle(end, dist * (1.0f - at->GetProgress()), angle);
       // end.SimplePosXYRelocationByAngle(endLeft, dist, angleLeft);
       // end.SimplePosXYRelocationByAngle(endRight, dist, angleRight);

        uint32 spellId = at->GetSpellId() == SPELL_DARK_SIDE_MOON_AT ? SPELL_LIGHT_SIDE_MOON_DUMMY : SPELL_DARK_SIDE_MOON_DUMMY;
        uint32 spellIdMirror = at->GetSpellId() == SPELL_DARK_SIDE_MOON_AT ? SPELL_DARK_SIDE_MOON_DUMMY : SPELL_LIGHT_SIDE_MOON_DUMMY;

     //   if (end.IsLinesCross(endPos, *target, endLeft, endRight))
        {
            if (!target->HasAura(spellId))
                target->CastSpell(target, spellId, true);
        }
       // else
        {
            if (!target->HasAura(spellIdMirror))
                target->CastSpell(target, spellIdMirror, true);
        }

        return true;
    }
};
*/
class achievement_wax_on_wax_off : public AchievementCriteriaScript
{
public:
    achievement_wax_on_wax_off() : AchievementCriteriaScript("achievement_wax_on_wax_off") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Creature* boss = target->ToCreature())
            if (boss->GetAI()->GetData(ACHIEVEMENT))
                return true;

        return false;
    }
};

void AddSC_boss_sisters_of_moon()
{
    RegisterCreatureAI(boss_sisters_of_the_moon);
    RegisterCreatureAI(npc_sister_kasparian);
    RegisterCreatureAI(npc_sister_lunaspyre);
    //RegisterCreatureAI(npc_sister_yathae);
    RegisterCreatureAI(npc_sistersmoon_moontalon);
    RegisterCreatureAI(npc_sistersmoon_glaive_target);
    RegisterCreatureAI(npc_sistersmoon_twilight_soul);
    RegisterSpellScript(spell_sistersmoon_incorporeal_shot_filter);
    RegisterSpellScript(spell_sistersmoon_glaive_storm_filter);
    RegisterSpellScript(spell_sistersmoon_astral_purge);
    //RegisterAuraScript(spell_sistersmoon_embrace_eclipse);
    RegisterAuraScript(spell_sistersmoon_side_moon);
    RegisterAuraScript(spell_sistersmoon_lunar_barrage);
   // RegisterAreaTriggerAI(at_sistersmoon_glaive_storm);
    //RegisterAreaTriggerAI(at_sistersmoon_moon);
    new achievement_wax_on_wax_off();
}

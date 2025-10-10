/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "CombatAI.h"
#include "Containers.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*######
## npc_argent_valiant
######*/

enum ArgentValiant
{
    SPELL_CHARGE                = 63010,
    SPELL_SHIELD_BREAKER        = 65147,
    SPELL_KILL_CREDIT           = 63049
};

struct npc_argent_valiant : public ScriptedAI
{
    npc_argent_valiant(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        creature->GetMotionMaster()->MovePoint(0, 8599.258f, 963.951f, 547.553f);
        creature->SetFaction(FACTION_FRIENDLY); //wrong faction in db?
    }

    void Initialize()
    {
        uiChargeTimer = 7000;
        uiShieldBreakerTimer = 10000;
    }

    uint32 uiChargeTimer;
    uint32 uiShieldBreakerTimer;

    void Reset() override
    {
        Initialize();
    }

    void MovementInform(uint32 uiType, uint32 /*uiId*/) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        me->SetFaction(FACTION_MONSTER);
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (uiDamage > me->GetHealth() && pDoneBy && pDoneBy->GetTypeId() == TYPEID_PLAYER)
        {
            uiDamage = 0;
            pDoneBy->CastSpell(pDoneBy, SPELL_KILL_CREDIT, true);
            me->SetFaction(FACTION_FRIENDLY);
            me->DespawnOrUnsummon(5s);
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            EnterEvadeMode();
        }
    }

    void UpdateAI(uint32 uiDiff) override
    {
        if (!UpdateVictim())
            return;

        if (uiChargeTimer <= uiDiff)
        {
            DoCastVictim(SPELL_CHARGE);
            uiChargeTimer = 7000;
        } else uiChargeTimer -= uiDiff;

        if (uiShieldBreakerTimer <= uiDiff)
        {
            DoCastVictim(SPELL_SHIELD_BREAKER);
            uiShieldBreakerTimer = 10000;
        } else uiShieldBreakerTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

/*######
## npc_guardian_pavilion
######*/

enum GuardianPavilion
{
    SPELL_TRESPASSER_H                            = 63987,
    AREA_SUNREAVER_PAVILION                       = 4676,

    AREA_SILVER_COVENANT_PAVILION                 = 4677,
    SPELL_TRESPASSER_A                            = 63986,
};

struct npc_guardian_pavilion : public ScriptedAI
{
    npc_guardian_pavilion(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void MoveInLineOfSight(Unit* who) override

    {
        if (me->GetAreaId() != AREA_SUNREAVER_PAVILION && me->GetAreaId() != AREA_SILVER_COVENANT_PAVILION)
            return;

        if (!who || who->GetTypeId() != TYPEID_PLAYER || !me->IsHostileTo(who) || !me->isInBackInMap(who, 5.0f))
            return;

        if (who->HasAura(SPELL_TRESPASSER_H) || who->HasAura(SPELL_TRESPASSER_A))
            return;

        if (who->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
            who->CastSpell(who, SPELL_TRESPASSER_H, true);
        else
            who->CastSpell(who, SPELL_TRESPASSER_A, true);

    }
};

/*######
* npc_tournament_training_dummy
######*/
enum TournamentDummy
{
    NPC_CHARGE_TARGET         = 33272,
    NPC_MELEE_TARGET          = 33229,
    NPC_RANGED_TARGET         = 33243,

    SPELL_CHARGE_CREDIT       = 62658,
    SPELL_MELEE_CREDIT        = 62672,
    SPELL_RANGED_CREDIT       = 62673,

    SPELL_PLAYER_THRUST       = 62544,
    SPELL_PLAYER_BREAK_SHIELD = 62626,
    SPELL_PLAYER_CHARGE       = 62874,

    SPELL_RANGED_DEFEND       = 62719,
    SPELL_CHARGE_DEFEND       = 64100,
    SPELL_VULNERABLE          = 62665,

    SPELL_COUNTERATTACK       = 62709,

    EVENT_DUMMY_RECAST_DEFEND = 1,
    EVENT_DUMMY_RESET         = 2,
};

struct npc_tournament_training_dummy : ScriptedAI
{
    npc_tournament_training_dummy(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        SetCombatMovement(false);
    }

    void Initialize()
    {
        isVulnerable = false;
    }

    EventMap events;
    bool isVulnerable;

    void Reset() override
    {
        me->SetControlled(true, UNIT_STATE_STUNNED);
        Initialize();

        events.Reset();
        events.ScheduleEvent(EVENT_DUMMY_RECAST_DEFEND, 5s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeMode(why))
            return;

        Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = 0;
        events.RescheduleEvent(EVENT_DUMMY_RESET, 10s);
    }

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        Unit* unitCaster = caster->ToUnit();
        if (!unitCaster)
            return;

        switch (me->GetEntry())
        {
            case NPC_CHARGE_TARGET:
                if (spellInfo->Id == SPELL_PLAYER_CHARGE)
                    if (isVulnerable)
                        DoCast(unitCaster, SPELL_CHARGE_CREDIT, true);
                break;
            case NPC_MELEE_TARGET:
                if (spellInfo->Id == SPELL_PLAYER_THRUST)
                {
                    DoCast(unitCaster, SPELL_MELEE_CREDIT, true);

                    if (Unit* target = unitCaster->GetVehicleBase())
                        DoCast(target, SPELL_COUNTERATTACK, true);
                }
                break;
            case NPC_RANGED_TARGET:
                if (spellInfo->Id == SPELL_PLAYER_BREAK_SHIELD)
                    if (isVulnerable)
                        DoCast(unitCaster, SPELL_RANGED_CREDIT, true);
                break;
        }

        if (spellInfo->Id == SPELL_PLAYER_BREAK_SHIELD)
            if (!me->HasAura(SPELL_CHARGE_DEFEND) && !me->HasAura(SPELL_RANGED_DEFEND))
                isVulnerable = true;
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        switch (events.ExecuteEvent())
        {
            case EVENT_DUMMY_RECAST_DEFEND:
                switch (me->GetEntry())
                {
                    case NPC_CHARGE_TARGET:
                    {
                        if (!me->HasAura(SPELL_CHARGE_DEFEND))
                            DoCast(me, SPELL_CHARGE_DEFEND, true);
                        break;
                    }
                    case NPC_RANGED_TARGET:
                    {
                        Aura* defend = me->GetAura(SPELL_RANGED_DEFEND);
                        if (!defend || defend->GetStackAmount() < 3 || defend->GetDuration() <= 8000)
                            DoCast(me, SPELL_RANGED_DEFEND, true);
                        break;
                    }
                }
                isVulnerable = false;
                events.ScheduleEvent(EVENT_DUMMY_RECAST_DEFEND, 5s);
                break;
            case EVENT_DUMMY_RESET:
                if (UpdateVictim())
                {
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    events.ScheduleEvent(EVENT_DUMMY_RESET, 10s);
                }
                break;
        }

        if (!UpdateVictim())
            return;

        if (!me->HasUnitState(UNIT_STATE_STUNNED))
            me->SetControlled(true, UNIT_STATE_STUNNED);
    }

    void MoveInLineOfSight(Unit* /*who*/) override { }

};

// Battle for Crusaders' Pinnacle
enum BlessedBanner
{
    SPELL_BLESSING_OF_THE_CRUSADE       = 58026,
    SPELL_THREAT_PULSE                  = 58113,
    SPELL_CRUSADERS_SPIRE_VICTORY       = 58084,
    SPELL_TORCH                         = 58121,

    NPC_BLESSED_BANNER                  = 30891,
    NPC_CRUSADER_LORD_DALFORS           = 31003,
    NPC_ARGENT_BATTLE_PRIEST            = 30919,
    NPC_ARGENT_MASON                    = 30900,
    NPC_REANIMATED_CAPTAIN              = 30986,
    NPC_SCOURGE_DRUDGE                  = 30984,
    NPC_HIDEOUS_PLAGEBRINGER            = 30987,
    NPC_HALOF_THE_DEATHBRINGER          = 30989,
    NPC_LK                              = 31013,

    BANNER_SAY                          = 0, // "The Blessed Banner of the Crusade has been planted.\n Defend the banner from all attackers!"
    DALFORS_SAY_PRE_1                   = 0, // "BY THE LIGHT! Those damned monsters! Look at what they've done to our people!"
    DALFORS_SAY_PRE_2                   = 1, // "Burn it down, boys. Burn it all down."
    DALFORS_SAY_START                   = 2, // "Let 'em come. They'll pay for what they've done!"
    DALFORS_YELL_FINISHED               = 3, // "We've done it, lads! We've taken the pinnacle from the Scourge! Report to Father Gustav at once and tell him the good news! We're gonna get to buildin' and settin' up! Go!"
    LK_TALK_1                           = 0, // "Leave no survivors!"
    LK_TALK_2                           = 1, // "Cower before my terrible creations!"
    LK_TALK_3                           = 2, // "Feast my children! Feast upon the flesh of the living!"
    LK_TALK_4                           = 3, // "Lay down your arms and surrender your souls!"

    EVENT_SPAWN                         = 1,
    EVENT_INTRO_1                       = 2,
    EVENT_INTRO_2                       = 3,
    EVENT_INTRO_3                       = 4,
    EVENT_MASON_ACTION                  = 5,
    EVENT_START_FIGHT                   = 6,
    EVENT_WAVE_SPAWN                    = 7,
    EVENT_HALOF                         = 8,
    EVENT_ENDED                         = 9,
};

Position const DalforsPos[3] =
{
    {6458.703f, 403.858f, 490.498f, 3.1205f}, // Dalfors spawn point
    {6422.950f, 423.335f, 510.451f, 0.0f}, // Dalfors intro pos
    {6426.343f, 420.515f, 508.650f, 0.0f}, // Dalfors fight pos
};

Position const Priest1Pos[2] =
{
    {6462.025f, 403.681f, 489.721f, 3.1007f}, // priest1 spawn point
    {6421.480f, 423.576f, 510.781f, 5.7421f}, // priest1 intro pos
};

Position const Priest2Pos[2] =
{
    {6463.969f, 407.198f, 489.240f, 2.2689f}, // priest2 spawn point
    {6419.778f, 421.404f, 510.972f, 5.7421f}, // priest2 intro pos
};

Position const Priest3Pos[2] =
{
    {6464.371f, 400.944f, 489.186f, 6.1610f}, // priest3 spawn point
    {6423.516f, 425.782f, 510.774f, 5.7421f}, // priest3 intro pos
};

Position const Mason1Pos[3] =
{
    {6462.929f, 409.826f, 489.392f, 3.0968f}, // mason1 spawn point
    {6428.163f, 421.960f, 508.297f, 0.0f}, // mason1 intro pos
    {6414.335f, 454.904f, 511.395f, 2.8972f}, // mason1 action pos
};

Position const Mason2Pos[3] =
{
    {6462.650f, 405.670f, 489.576f, 2.9414f}, // mason2 spawn point
    {6426.250f, 419.194f, 508.219f, 0.0f}, // mason2 intro pos
    {6415.014f, 446.849f, 511.395f, 3.1241f}, // mason2 action pos
};

Position const Mason3Pos[3] =
{
    {6462.646f, 401.218f, 489.601f, 2.7864f}, // mason3 spawn point
    {6423.855f, 416.598f, 508.305f, 0.0f}, // mason3 intro pos
    {6417.070f, 438.824f, 511.395f, 3.6651f}, // mason3 action pos
};

struct npc_blessed_banner : public ScriptedAI
{
    npc_blessed_banner(Creature* creature) : ScriptedAI(creature), Summons(me)
    {
        HalofSpawned = false;
        PhaseCount = 0;

        SetCombatMovement(false);
    }

    EventMap events;

    bool HalofSpawned;

    uint32 PhaseCount;

    SummonList Summons;

    ObjectGuid guidDalfors;
    ObjectGuid guidPriest[3];
    ObjectGuid guidMason[3];
    ObjectGuid guidHalof;

    void Reset() override
    {
        me->SetRegenerateHealth(false);
        DoCast(SPELL_THREAT_PULSE);
        Talk(BANNER_SAY);
        events.ScheduleEvent(EVENT_SPAWN, 3s);
    }

    void JustEngagedWith(Unit* /*who*/) override { }

    void MoveInLineOfSight(Unit* /*who*/) override { }

    void JustSummoned(Creature* Summoned) override
    {
        Summons.Summon(Summoned);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        switch (events.ExecuteEvent())
        {
            case EVENT_SPAWN:
                {
                    if (Creature* Dalfors = DoSummon(NPC_CRUSADER_LORD_DALFORS, DalforsPos[0]))
                    {
                        guidDalfors = Dalfors->GetGUID();
                        Dalfors->GetMotionMaster()->MovePoint(0, DalforsPos[1]);
                    }
                    if (Creature* Priest1 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest1Pos[0]))
                    {
                        guidPriest[0] = Priest1->GetGUID();
                        Priest1->GetMotionMaster()->MovePoint(0, Priest1Pos[1]);
                    }
                    if (Creature* Priest2 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest2Pos[0]))
                    {
                        guidPriest[1] = Priest2->GetGUID();
                        Priest2->GetMotionMaster()->MovePoint(0, Priest2Pos[1]);
                    }
                    if (Creature* Priest3 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest3Pos[0]))
                    {
                        guidPriest[2] = Priest3->GetGUID();
                        Priest3->GetMotionMaster()->MovePoint(0, Priest3Pos[1]);
                    }
                    if (Creature* Mason1 = DoSummon(NPC_ARGENT_MASON, Mason1Pos[0]))
                    {
                        guidMason[0] = Mason1->GetGUID();
                        Mason1->GetMotionMaster()->MovePoint(0, Mason1Pos[1]);
                    }
                    if (Creature* Mason2 = DoSummon(NPC_ARGENT_MASON, Mason2Pos[0]))
                    {
                        guidMason[1] = Mason2->GetGUID();
                        Mason2->GetMotionMaster()->MovePoint(0, Mason2Pos[1]);
                    }
                    if (Creature* Mason3 = DoSummon(NPC_ARGENT_MASON, Mason3Pos[0]))
                    {
                        guidMason[2] = Mason3->GetGUID();
                        Mason3->GetMotionMaster()->MovePoint(0, Mason3Pos[1]);
                    }
                    events.ScheduleEvent(EVENT_INTRO_1, 15s);
                }
                break;
            case EVENT_INTRO_1:
                {
                    if (Creature* Dalfors = ObjectAccessor::GetCreature(*me, guidDalfors))
                        Dalfors->AI()->Talk(DALFORS_SAY_PRE_1);
                    events.ScheduleEvent(EVENT_INTRO_2, 5s);
                }
                break;
            case EVENT_INTRO_2:
                {
                    if (Creature* Dalfors = ObjectAccessor::GetCreature(*me, guidDalfors))
                    {
                        Dalfors->SetFacingTo(6.215f);
                        Dalfors->AI()->Talk(DALFORS_SAY_PRE_2);
                    }
                events.ScheduleEvent(EVENT_INTRO_3, 5s);
                }
                break;
            case EVENT_INTRO_3:
                {
                    if (Creature* Dalfors = ObjectAccessor::GetCreature(*me, guidDalfors))
                    {
                        Dalfors->GetMotionMaster()->MovePoint(0, DalforsPos[2]);
                        Dalfors->SetHomePosition(DalforsPos[2]);
                    }
                    if (Creature* Priest1 = ObjectAccessor::GetCreature(*me, guidPriest[0]))
                    {
                        Priest1->SetFacingTo(5.7421f);
                        Priest1->SetHomePosition(Priest1Pos[1]);
                    }
                    if (Creature* Priest2 = ObjectAccessor::GetCreature(*me, guidPriest[1]))
                    {
                        Priest2->SetFacingTo(5.7421f);
                        Priest2->SetHomePosition(Priest2Pos[1]);
                    }
                    if (Creature* Priest3 = ObjectAccessor::GetCreature(*me, guidPriest[2]))
                    {
                        Priest3->SetFacingTo(5.7421f);
                        Priest3->SetHomePosition(Priest3Pos[1]);
                    }
                    if (Creature* Mason1 = ObjectAccessor::GetCreature(*me, guidMason[0]))
                    {
                        Mason1->GetMotionMaster()->MovePoint(0, Mason1Pos[2]);
                        Mason1->SetHomePosition(Mason1Pos[2]);
                    }
                    if (Creature* Mason2 = ObjectAccessor::GetCreature(*me, guidMason[1]))
                    {
                        Mason2->GetMotionMaster()->MovePoint(0, Mason2Pos[2]);
                        Mason2->SetHomePosition(Mason2Pos[2]);
                    }
                    if (Creature* Mason3 = ObjectAccessor::GetCreature(*me, guidMason[2]))
                    {
                        Mason3->GetMotionMaster()->MovePoint(0, Mason3Pos[2]);
                        Mason3->SetHomePosition(Mason3Pos[2]);
                    }
                    events.ScheduleEvent(EVENT_START_FIGHT, 5s);
                    events.ScheduleEvent(EVENT_MASON_ACTION, 15s);
                }
                break;
            case EVENT_MASON_ACTION:
                {
                    if (Creature* Mason1 = ObjectAccessor::GetCreature(*me, guidMason[0]))
                    {
                        Mason1->SetFacingTo(2.8972f);
                        Mason1->AI()->SetData(1, 1); // triggers SAI actions on npc
                    }
                    if (Creature* Mason2 = ObjectAccessor::GetCreature(*me, guidMason[1]))
                    {
                        Mason2->SetFacingTo(3.1241f);
                        Mason2->AI()->SetData(1, 1); // triggers SAI actions on npc
                    }
                    if (Creature* Mason3 = ObjectAccessor::GetCreature(*me, guidMason[2]))
                    {
                        Mason3->SetFacingTo(3.6651f);
                        Mason3->AI()->SetData(1, 1); // triggers SAI actions on npc
                    }
                }
                break;
            case EVENT_START_FIGHT:
                {
                    if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                        LK->AI()->Talk(LK_TALK_1);
                    if (Creature* Dalfors = ObjectAccessor::GetCreature(*me, guidDalfors))
                        Dalfors->AI()->Talk(DALFORS_SAY_START);
                    events.ScheduleEvent(EVENT_WAVE_SPAWN, 1s);
                }
                break;
            case EVENT_WAVE_SPAWN:
                {
                    if (PhaseCount == 3)
                    {
                        if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                            LK->AI()->Talk(LK_TALK_2);
                    }
                    else if (PhaseCount == 6)
                    {
                        if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                            LK->AI()->Talk(LK_TALK_3);
                    }
                    if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason3Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                    if (urand(0, 1) == 0)
                    {
                        if (Creature* tempsum = DoSummon(NPC_HIDEOUS_PLAGEBRINGER, Mason1Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                        if (Creature* tempsum = DoSummon(NPC_HIDEOUS_PLAGEBRINGER, Mason2Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                    }
                    else
                    {
                        if (Creature* tempsum = DoSummon(NPC_REANIMATED_CAPTAIN, Mason1Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                        if (Creature* tempsum = DoSummon(NPC_REANIMATED_CAPTAIN, Mason2Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                    }

                    PhaseCount++;

                    if (PhaseCount < 8)
                        events.ScheduleEvent(EVENT_WAVE_SPAWN, 10s, 20s);
                    else
                        events.ScheduleEvent(EVENT_HALOF, 10s, 20s);
                }
                break;
            case EVENT_HALOF:
                {
                    if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                        LK->AI()->Talk(LK_TALK_4);
                    if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason1Pos[0]))
                    {
                        tempsum->SetHomePosition(DalforsPos[2]);
                        tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                    }
                    if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason2Pos[0]))
                    {
                        tempsum->SetHomePosition(DalforsPos[2]);
                        tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                    }
                    if (Creature* tempsum = DoSummon(NPC_HALOF_THE_DEATHBRINGER, DalforsPos[0]))
                    {
                        HalofSpawned = true;
                        guidHalof = tempsum->GetGUID();
                        tempsum->SetHomePosition(DalforsPos[2]);
                        tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                    }
                }
                break;
            case EVENT_ENDED:
                {
                    Summons.DespawnAll();
                    me->DespawnOrUnsummon();
                }
                break;
        }

        if (PhaseCount == 8)
            if (Creature* Halof = ObjectAccessor::GetCreature(*me, guidHalof))
                if (Halof->isDead())
                {
                    DoCast(me, SPELL_CRUSADERS_SPIRE_VICTORY, true);
                    Summons.DespawnEntry(NPC_HIDEOUS_PLAGEBRINGER);
                    Summons.DespawnEntry(NPC_REANIMATED_CAPTAIN);
                    Summons.DespawnEntry(NPC_SCOURGE_DRUDGE);
                    Summons.DespawnEntry(NPC_HALOF_THE_DEATHBRINGER);
                    if (Creature* Dalfors = ObjectAccessor::GetCreature(*me, guidDalfors))
                        Dalfors->AI()->Talk(DALFORS_YELL_FINISHED);
                    events.ScheduleEvent(EVENT_ENDED, 10s);
                }
    }
};

/*######
## Borrowed Technology - Id: 13291, The Solution Solution (daily) - Id: 13292, Volatility - Id: 13239, Volatiliy - Id: 13261 (daily)
######*/

enum BorrowedTechnologyAndVolatility
{
    // Spells
    SPELL_GRAB             = 59318,
    SPELL_PING_BUNNY       = 59375,
    SPELL_IMMOLATION       = 54690,
    SPELL_EXPLOSION        = 59335,
    SPELL_RIDE             = 59319,

    // Points
    POINT_GRAB_DECOY       = 1,
    POINT_FLY_AWAY         = 2,

    // Events
    EVENT_FLY_AWAY         = 1
};

struct npc_frostbrood_skytalon : public VehicleAI
{
    npc_frostbrood_skytalon(Creature* creature) : VehicleAI(creature) { }

    EventMap events;

    void IsSummonedBy(WorldObject* summoner) override
    {
        me->GetMotionMaster()->MovePoint(POINT_GRAB_DECOY, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_GRAB_DECOY)
            if (TempSummon* summon = me->ToTempSummon())
                if (Unit* summoner = summon->GetSummonerUnit())
                    DoCast(summoner, SPELL_GRAB);
    }

    void UpdateAI(uint32 diff) override
    {
        VehicleAI::UpdateAI(diff);
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_FLY_AWAY)
            {
                Position randomPosOnRadius;
                randomPosOnRadius.m_positionZ = (me->GetPositionZ() + 40.0f);
                me->GetNearPoint2D(nullptr, randomPosOnRadius.m_positionX, randomPosOnRadius.m_positionY, 40.0f, me->GetAbsoluteAngle(me));
                me->GetMotionMaster()->MovePoint(POINT_FLY_AWAY, randomPosOnRadius);
            }
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_EXPLOSION:
                DoCast(me, SPELL_IMMOLATION);
                break;
            case SPELL_RIDE:
                DoCastAOE(SPELL_PING_BUNNY);
                events.ScheduleEvent(EVENT_FLY_AWAY, 100ms);
                break;
        }
    }
};

/*######
## Quest 12887, 12892: It's All Fun and Games
######*/

// 55288 - It's All Fun and Games: The Ocular On Death
class spell_icecrown_the_ocular_on_death : public SpellScript
{
    PrepareSpellScript(spell_icecrown_the_ocular_on_death);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
            target->CastSpell(target, uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_the_ocular_on_death::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 14077, 14144: The Light's Mercy
######*/

// 66411 - Summon Tualiq Proxy
class spell_icecrown_summon_tualiq_proxy : public SpellScript
{
    PrepareSpellScript(spell_icecrown_summon_tualiq_proxy);

    void SetDest(SpellDestination& dest)
    {
        Position const offset = { 0.0f, 0.0f, 30.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_icecrown_summon_tualiq_proxy::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

/*######
## Quest 14076 & 14092: Breakfast Of Champions
######*/

enum BreakfastOfChampions
{
    SPELL_SUMMON_DEEP_JORMUNGAR     = 66510,
    SPELL_STORMFORGED_MOLE_MACHINE  = 66492
};

// 66512 - Pound Drum
class spell_icecrown_pound_drum : public SpellScript
{
    PrepareSpellScript(spell_icecrown_pound_drum);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_DEEP_JORMUNGAR, SPELL_STORMFORGED_MOLE_MACHINE });
    }

    void HandleSummon()
    {
        GetCaster()->CastSpell(GetCaster(), roll_chance_i(50) ? SPELL_SUMMON_DEEP_JORMUNGAR : SPELL_STORMFORGED_MOLE_MACHINE, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_icecrown_pound_drum::HandleSummon);
    }
};

/*######
## Quest 14112 & 14145: What Do You Feed a Yeti, Anyway?
######*/

enum ChumTheWaterSummons
{
    SPELL_SUMMON_ANGRY_KVALDIR           = 66737,
    SPELL_SUMMON_NORTH_SEA_MAKO          = 66738,
    SPELL_SUMMON_NORTH_SEA_THRESHER      = 66739,
    SPELL_SUMMON_NORTH_SEA_BLUE_SHARK    = 66740
};

std::array<uint32, 4> const ChumTheWaterSummonSpells =
{
    SPELL_SUMMON_ANGRY_KVALDIR,
    SPELL_SUMMON_NORTH_SEA_MAKO,
    SPELL_SUMMON_NORTH_SEA_THRESHER,
    SPELL_SUMMON_NORTH_SEA_BLUE_SHARK
};

// 66741 - Chum the Water
class spell_icecrown_chum_the_water : public SpellScript
{
    PrepareSpellScript(spell_icecrown_chum_the_water);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(ChumTheWaterSummonSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, Trinity::Containers::SelectRandomContainerElement(ChumTheWaterSummonSpells));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_icecrown_chum_the_water::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 13121: Through the Eye
######*/

enum ThroughTheEye
{
    SPELL_SUMMON_IMAGE_OF_VARDMADRA        = 57891,
    SPELL_SUMMON_IMAGE_OF_SHADOW_CULTIST   = 57885,
    SPELL_USING_THE_EYE_OF_THE_LK          = 57889,
    TEXT_USING_THE_EYE_OF_THE_LK           = 31493
};

// 25732 - Through the Eye: Eye of the Lich King
class spell_icecrown_through_the_eye_the_eye_of_the_lk : public AuraScript
{
    PrepareAuraScript(spell_icecrown_through_the_eye_the_eye_of_the_lk);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_IMAGE_OF_VARDMADRA, SPELL_SUMMON_IMAGE_OF_SHADOW_CULTIST }) &&
            sObjectMgr->GetBroadcastText(TEXT_USING_THE_EYE_OF_THE_LK);
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* target = GetTarget()->ToPlayer())
            target->Unit::Whisper(TEXT_USING_THE_EYE_OF_THE_LK, target, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_SUMMON_IMAGE_OF_VARDMADRA, true);
        target->CastSpell(target, SPELL_SUMMON_IMAGE_OF_SHADOW_CULTIST, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_icecrown_through_the_eye_the_eye_of_the_lk::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_icecrown_through_the_eye_the_eye_of_the_lk::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 57884 - Through the Eye: Kill Credit to Master
class spell_icecrown_through_the_eye_kill_credit_to_master : public SpellScript
{
    PrepareSpellScript(spell_icecrown_through_the_eye_kill_credit_to_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_USING_THE_EYE_OF_THE_LK });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_USING_THE_EYE_OF_THE_LK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_through_the_eye_kill_credit_to_master::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 13008: Scourge Tactics
######*/

// 56515 - Summon Freed Crusader
class spell_icecrown_summon_freed_crusader : public SpellScript
{
    PrepareSpellScript(spell_icecrown_summon_freed_crusader);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_summon_freed_crusader::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 13236, 13395: Army of the Damned
######*/

enum ArmyOfTheDamned
{
    SPELL_GIFT_OF_THE_LICH_KING     = 58915,
    SPELL_CONSUME_MINIONS           = 58919
};

// 58916 - Gift of the Lich King
class spell_icecrown_gift_of_the_lich_king : public SpellScript
{
    PrepareSpellScript(spell_icecrown_gift_of_the_lich_king);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GIFT_OF_THE_LICH_KING });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_GIFT_OF_THE_LICH_KING);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_gift_of_the_lich_king::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 58917 - Consume Minions
class spell_icecrown_consume_minions : public SpellScript
{
    PrepareSpellScript(spell_icecrown_consume_minions);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CONSUME_MINIONS });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_CONSUME_MINIONS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_consume_minions::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 12995: Leave Our Mark
######*/

enum LeaveOurMark
{
    NPC_LEAVE_OUR_MARK_KILL_CREDIT_BUNNY     = 30220
};

// 23301 - Ebon Blade Banner
class spell_icecrown_ebon_blade_banner : public SpellScript
{
    PrepareSpellScript(spell_icecrown_ebon_blade_banner);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            caster->KilledMonsterCredit(NPC_LEAVE_OUR_MARK_KILL_CREDIT_BUNNY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_ebon_blade_banner::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 13400: The Hunter and the Prince
######*/

enum TheHunterAndThePrince
{
    SPELL_ILLIDAN_KILL_CREDIT      = 61748
};

// 61752 - Illidan Kill Credit Master
class spell_icecrown_illidan_kill_credit_master : public SpellScript
{
   PrepareSpellScript(spell_icecrown_illidan_kill_credit_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ILLIDAN_KILL_CREDIT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->IsVehicle())
            if (Unit* passenger = caster->GetVehicleKit()->GetPassenger(0))
                passenger->CastSpell(passenger, SPELL_ILLIDAN_KILL_CREDIT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_illidan_kill_credit_master::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*######
## Quest 13280, 13283: King of the Mountain
######*/

enum KingOfTheMountain
{
    NPC_KING_OF_THE_MOUNTAINT_KC         = 31766,
    SPELL_PLANT_HORDE_BATTLE_STANDARD    = 59643,
    SPELL_HORDE_BATTLE_STANDARD_STATE    = 59642,
    SPELL_ALLIANCE_BATTLE_STANDARD_STATE = 4339,
    SPELL_JUMP_ROCKET_BLAST              = 4340
};

// 4338 - Plant Alliance Battle Standard
// 59643 - Plant Horde Battle Standard
class spell_icecrown_plant_battle_standard : public SpellScript
{
    PrepareSpellScript(spell_icecrown_plant_battle_standard);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        uint32 triggeredSpellID = SPELL_ALLIANCE_BATTLE_STANDARD_STATE;

        caster->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
        if (caster->IsVehicle())
            if (Unit* player = caster->GetVehicleKit()->GetPassenger(0))
                player->ToPlayer()->KilledMonsterCredit(NPC_KING_OF_THE_MOUNTAINT_KC);

        if (GetSpellInfo()->Id == SPELL_PLANT_HORDE_BATTLE_STANDARD)
            triggeredSpellID = SPELL_HORDE_BATTLE_STANDARD_STATE;

        target->RemoveAllAuras();
        target->CastSpell(target, triggeredSpellID, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_plant_battle_standard::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 4336 - Jump Jets
class spell_icecrown_jump_jets : public SpellScript
{
    PrepareSpellScript(spell_icecrown_jump_jets);

    void HandleCast()
    {
        Unit* caster = GetCaster();
        if (caster->IsVehicle())
            if (Unit* rocketBunny = caster->GetVehicleKit()->GetPassenger(1))
                rocketBunny->CastSpell(rocketBunny, SPELL_JUMP_ROCKET_BLAST, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_icecrown_jump_jets::HandleCast);
    }
};

/*######
## Quest 13291: Borrowed Technology / 13292: The Solution Solution (Daily) / 13239: Volatility / 13261: Volatiliy (Daily)
######*/

enum BorrowedTechnology
{
    SPELL_RIDE_FROST_WYRM         = 59319
};

// 59318 - Grab Fake Soldier
class spell_icecrown_grab_fake_soldier : public SpellScript
{
    PrepareSpellScript(spell_icecrown_grab_fake_soldier);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE_FROST_WYRM });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitCreature())
            return;
        // TO DO: Being triggered is hack, but in checkcast it doesn't pass aurastate requirements.
        // Beside that the decoy won't keep it's freeze animation state when enter.
        GetHitCreature()->CastSpell(GetCaster(), SPELL_RIDE_FROST_WYRM, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_grab_fake_soldier::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 59303 - Summon Frost Wyrm
class spell_icecrown_summon_frost_wyrm : public SpellScript
{
    PrepareSpellScript(spell_icecrown_summon_frost_wyrm);

    void SetDest(SpellDestination& dest)
    {
        // Adjust effect summon position
        Position const offset = { 0.0f, 0.0f, 20.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_icecrown_summon_frost_wyrm::SetDest, EFFECT_0, TARGET_DEST_CASTER_BACK);
    }
};

/*######
## Quest 12847: Second Chances
######*/

// 12601 - Second Chances: Summon Landgren's Soul Moveto Target Bunny
class spell_icecrown_summon_soul_moveto_bunny : public SpellScript
{
    PrepareSpellScript(spell_icecrown_summon_soul_moveto_bunny);

    void SetDest(SpellDestination& dest)
    {
        // Adjust effect summon position
        Position const offset = { 0.0f, 0.0f, 2.5f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_icecrown_summon_soul_moveto_bunny::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

/*######
## Quest 13086: The Last Line Of Defense
######*/

enum TheLastLineOfDefense
{
    SPELL_POWERING_UP_THE_CORE     = 57608
};

// 57387 - Argent Cannon Assault
class spell_icecrown_argent_cannon_assault : public SpellScript
{
    PrepareSpellScript(spell_icecrown_argent_cannon_assault);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POWERING_UP_THE_CORE });
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_POWERING_UP_THE_CORE, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_icecrown_argent_cannon_assault::HandleAfterCast);
    }
};

// 57385 - Argent Cannon
// 57412 - Reckoning Bomb
class spell_icecrown_cannons_target : public SpellScript
{
    PrepareSpellScript(spell_icecrown_cannons_target);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation const* pos = GetExplTargetDest())
            GetCaster()->CastSpell(pos->GetPosition(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_icecrown_cannons_target::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*######
## Quest 13790, 13793, 13811, 13814: Among the Champions / 13665, 13745, 13750, 13756, 13761, 13767, 13772, 13777, 13782, 13787: The Grand Melee
######*/

class spell_icecrown_bested_trigger : public SpellScript
{
    PrepareSpellScript(spell_icecrown_bested_trigger);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit()->GetCharmerOrOwnerOrSelf();
        target->CastSpell(target, uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_bested_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 13264, 13276, 13288, 13289: That's Abominable!
######*/

enum ThatsAbominable
{
    AREA_THE_BROKEN_FRONT                       =  4507,
    AREA_MORD_RETHAR_THE_DEATH_GATE             =  4508,

    NPC_DRAKKARI_CHIEFTAINK                     = 29099,
    NPC_ICY_GHOUL                               = 31142,
    NPC_VICIOUS_GEIST                           = 31147,
    NPC_RISEN_ALLIANCE_SOLDIERS                 = 31205,
    NPC_RENIMATED_ABOMINATION                   = 31692,

    QUEST_FUEL_FOR_THE_FIRE                     = 12690,

    SPELL_BLOATED_ABOMINATION_FEIGN_DEATH       = 52593,
    SPELL_BURST_AT_THE_SEAMS_BONE               = 52516,
    SPELL_EXPLODE_ABOMINATION_MEAT              = 52520,
    SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT       = 52523,
    SPELL_TROLL_EXPLOSION                       = 52565,
    SPELL_EXPLODE_TROLL_MEAT                    = 52578,
    SPELL_EXPLODE_TROLL_BLOODY_MEAT             = 52580,

    SPELL_BURST_AT_THE_SEAMS_59576              = 59576, //script/knockback, That's Abominable
    SPELL_BURST_AT_THE_SEAMS_59579              = 59579, //dummy
    SPELL_BURST_AT_THE_SEAMS_52510              = 52510, //script/knockback, Fuel for the Fire
    SPELL_BURST_AT_THE_SEAMS_52508              = 52508, //damage 20000
    SPELL_BURST_AT_THE_SEAMS_59580              = 59580, //damage 50000

    SPELL_ASSIGN_GHOUL_KILL_CREDIT_TO_MASTER    = 59590,
    SPELL_ASSIGN_GEIST_KILL_CREDIT_TO_MASTER    = 60041,
    SPELL_ASSIGN_SKELETON_KILL_CREDIT_TO_MASTER = 60039,

    SPELL_DRAKKARI_SKULLCRUSHER_CREDIT          = 52590,
    SPELL_SUMMON_DRAKKARI_CHIEFTAIN             = 52616,
    SPELL_DRAKKARI_CHIEFTAINK_KILL_CREDIT       = 52620
};

// 59576 - Burst at the Seams
class spell_icecrown_burst_at_the_seams_59576 : public SpellScript
{
    PrepareSpellScript(spell_icecrown_burst_at_the_seams_59576);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BURST_AT_THE_SEAMS_59576,
            SPELL_BLOATED_ABOMINATION_FEIGN_DEATH,
            SPELL_BURST_AT_THE_SEAMS_59579,
            SPELL_BURST_AT_THE_SEAMS_BONE,
            SPELL_EXPLODE_ABOMINATION_MEAT,
            SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetCaster()->ToCreature())
        {
            creature->CastSpell(creature, SPELL_BLOATED_ABOMINATION_FEIGN_DEATH, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_59579, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_MEAT, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_burst_at_the_seams_59576::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 59579 - Burst at the Seams
class spell_icecrown_burst_at_the_seams_59579 : public AuraScript
{
    PrepareAuraScript(spell_icecrown_burst_at_the_seams_59579);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_TROLL_EXPLOSION, true);
        target->CastSpell(target, SPELL_EXPLODE_ABOMINATION_MEAT, true);
        target->CastSpell(target, SPELL_EXPLODE_TROLL_MEAT, true);
        target->CastSpell(target, SPELL_EXPLODE_TROLL_MEAT, true);
        target->CastSpell(target, SPELL_EXPLODE_TROLL_BLOODY_MEAT, true);
        target->CastSpell(target, SPELL_BURST_AT_THE_SEAMS_BONE, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (Unit* caster = GetCaster())
        {
            switch (target->GetEntry())
            {
                case NPC_ICY_GHOUL:
                    target->CastSpell(caster, SPELL_ASSIGN_GHOUL_KILL_CREDIT_TO_MASTER, true);
                    break;
                case NPC_VICIOUS_GEIST:
                    target->CastSpell(caster, SPELL_ASSIGN_GEIST_KILL_CREDIT_TO_MASTER, true);
                    break;
                case NPC_RISEN_ALLIANCE_SOLDIERS:
                    target->CastSpell(caster, SPELL_ASSIGN_SKELETON_KILL_CREDIT_TO_MASTER, true);
                    break;
            }
        }
        target->CastSpell(target, SPELL_BURST_AT_THE_SEAMS_59580, true);
    }

    void Register() override
    {
        AfterEffectApply  += AuraEffectApplyFn(spell_icecrown_burst_at_the_seams_59579::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_icecrown_burst_at_the_seams_59579::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 52593 - Bloated Abomination Feign Death
class spell_icecrown_bloated_abom_feign_death : public AuraScript
{
    PrepareAuraScript(spell_icecrown_bloated_abom_feign_death);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetDynamicFlag(UNIT_DYNFLAG_DEAD);
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (Creature* creature = target->ToCreature())
            creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectApply  += AuraEffectApplyFn(spell_icecrown_bloated_abom_feign_death::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_icecrown_bloated_abom_feign_death::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 76245 - Area Restrict Abom
class spell_icecrown_area_restrict_abom : public SpellScript
{
    PrepareSpellScript(spell_icecrown_area_restrict_abom);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature()) {
            uint32 area = creature->GetAreaId();
            if (area != AREA_THE_BROKEN_FRONT && area != AREA_MORD_RETHAR_THE_DEATH_GATE)
                creature->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_area_restrict_abom::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 59590 - Assign Ghoul Kill Credit to Master
// 60039 - Assign Skeleton Kill Credit to Master
// 60041 - Assign Geist Kill Credit to Master
class spell_icecrown_assign_credit_to_master : public SpellScript
{
    PrepareSpellScript(spell_icecrown_assign_credit_to_master);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Unit* owner = target->GetOwner())
            {
                owner->CastSpell(owner, GetEffectValue(), true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_assign_credit_to_master::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 52510 - Burst at the Seams
class spell_icecrown_burst_at_the_seams_52510 : public SpellScript
{
    PrepareSpellScript(spell_icecrown_burst_at_the_seams_52510);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BURST_AT_THE_SEAMS_52510,
            SPELL_BURST_AT_THE_SEAMS_52508,
            SPELL_BURST_AT_THE_SEAMS_59580,
            SPELL_BURST_AT_THE_SEAMS_BONE,
            SPELL_EXPLODE_ABOMINATION_MEAT,
            SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT
        });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleKnockBack(SpellEffIndex /*effIndex*/)
    {
        if (Unit* creature = GetHitCreature())
        {
            if (Unit* charmer = GetCaster()->GetCharmerOrOwner())
            {
                if (Player* player = charmer->ToPlayer())
                {
                    if (player->GetQuestStatus(QUEST_FUEL_FOR_THE_FIRE) == QUEST_STATUS_INCOMPLETE)
                    {
                        creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
                        creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_MEAT, true);
                        creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
                        creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_52508, true);
                        creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_59580, true);

                        player->CastSpell(player, SPELL_DRAKKARI_SKULLCRUSHER_CREDIT, true);
                        uint16 count = player->GetReqKillOrCastCurrentCount(QUEST_FUEL_FOR_THE_FIRE, NPC_DRAKKARI_CHIEFTAINK);
                        if ((count % 20) == 0)
                            player->CastSpell(player, SPELL_SUMMON_DRAKKARI_CHIEFTAIN, true);
                    }
                }
            }
        }
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->ToCreature()->DespawnOrUnsummon(2s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_burst_at_the_seams_52510::HandleKnockBack, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_burst_at_the_seams_52510::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 13082: The Boon of A'dal
######*/

enum TheBoonOfAdal
{
    SPELL_SUMMON_SPIRIT_OF_BRIDENBRAD       = 57747,
    SPELL_SEE_QUEST_INVISIBILITY_1          = 57745,
    SPELL_SUMMON_ADAL                       = 57746,
    SPELL_SUMMON_MORI                       = 57782,
    SPELL_SUMMON_KURI                       = 57786,
    SPELL_SUMMON_LIGHT_BUNNY                = 57773
};

// 57787 - Forcecast Bridenbrad Ascension
class spell_icecrown_forcecast_bridenbrad_ascension : public SpellScript
{
    PrepareSpellScript(spell_icecrown_forcecast_bridenbrad_ascension);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_SPIRIT_OF_BRIDENBRAD,
            SPELL_SEE_QUEST_INVISIBILITY_1,
            SPELL_SUMMON_ADAL,
            SPELL_SUMMON_MORI,
            SPELL_SUMMON_KURI,
            SPELL_SUMMON_LIGHT_BUNNY
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_SUMMON_SPIRIT_OF_BRIDENBRAD);
        target->RemoveAurasDueToSpell(SPELL_SEE_QUEST_INVISIBILITY_1);
        target->CastSpell(target, SPELL_SUMMON_ADAL);
        target->CastSpell(target, SPELL_SUMMON_MORI);
        target->CastSpell(target, SPELL_SUMMON_KURI);
        target->CastSpell(target, SPELL_SUMMON_LIGHT_BUNNY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icecrown_forcecast_bridenbrad_ascension::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_icecrown()
{
    RegisterCreatureAI(npc_argent_valiant);
    RegisterCreatureAI(npc_guardian_pavilion);
    RegisterCreatureAI(npc_tournament_training_dummy);
    RegisterCreatureAI(npc_blessed_banner);
    RegisterCreatureAI(npc_frostbrood_skytalon);
    RegisterSpellScript(spell_icecrown_the_ocular_on_death);
    RegisterSpellScript(spell_icecrown_summon_tualiq_proxy);
    RegisterSpellScript(spell_icecrown_pound_drum);
    RegisterSpellScript(spell_icecrown_chum_the_water);
    RegisterSpellScript(spell_icecrown_through_the_eye_the_eye_of_the_lk);
    RegisterSpellScript(spell_icecrown_through_the_eye_kill_credit_to_master);
    RegisterSpellScript(spell_icecrown_summon_freed_crusader);
    RegisterSpellScript(spell_icecrown_gift_of_the_lich_king);
    RegisterSpellScript(spell_icecrown_consume_minions);
    RegisterSpellScript(spell_icecrown_ebon_blade_banner);
    RegisterSpellScript(spell_icecrown_illidan_kill_credit_master);
    RegisterSpellScript(spell_icecrown_plant_battle_standard);
    RegisterSpellScript(spell_icecrown_jump_jets);
    RegisterSpellScript(spell_icecrown_grab_fake_soldier);
    RegisterSpellScript(spell_icecrown_summon_frost_wyrm);
    RegisterSpellScript(spell_icecrown_summon_soul_moveto_bunny);
    RegisterSpellScript(spell_icecrown_argent_cannon_assault);
    RegisterSpellScript(spell_icecrown_cannons_target);
    RegisterSpellScript(spell_icecrown_bested_trigger);
    RegisterSpellScript(spell_icecrown_burst_at_the_seams_59576);
    RegisterSpellScript(spell_icecrown_burst_at_the_seams_59579);
    RegisterSpellScript(spell_icecrown_bloated_abom_feign_death);
    RegisterSpellScript(spell_icecrown_area_restrict_abom);
    RegisterSpellScript(spell_icecrown_assign_credit_to_master);
    RegisterSpellScript(spell_icecrown_burst_at_the_seams_52510);
    RegisterSpellScript(spell_icecrown_forcecast_bridenbrad_ascension);
}

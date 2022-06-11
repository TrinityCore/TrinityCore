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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

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
}

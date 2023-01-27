#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h" 
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "VehicleDefines.h"
#include "SpellInfo.h"

#include "throne_of_thunder.h"

enum Yells
{
    // Boss
    ANN_TURTLES = 0,      // Tortos lets out a booming call, attracting nearby turtles.
    ANN_FURIOUS_BREATH                    // Tortos prepares to unleash a [Furious Stone Breath]!
};

enum Spells
{
    // Boss
    SPELL_ZERO_POWER = 72242,  // No Regen

    SPELL_KICK_SHELL_A = 134030, // Boss aura for adding mechanic abilities to players in 130y radius.

    SPELL_CALL_OF_TORTOS = 136294, // Dummy on eff 0 for summoning 3 turtles.
    SPELL_FURIOUS_STONE_BREATH = 133939, // Triggers damage each 500 ms + prevents Fury regen for duration.
    SPELL_GROWING_FURY = 136010, // When no players are in melee range. Adds 10 Fury.
    SPELL_SNAPPING_BITE = 135251, // On tank, main ability.

    SPELL_QUAKE_STOMP = 134920, // Massive AOE damage. Interruptible. Triggers SPELL_ROCKFALL_STOMP.
    SPELL_ROCKFALL_STOMP = 134915, // 8 second aura triggering SPELL_ROCKFALL_STOMP_S_TRIG each 500 ms.
    SPELL_ROCKFALL_STOMP_S_TRIG = 140431, // Dummy on eff 0 for SPELL_ROCKFALL_SUMMON on random player.

    SPELL_ROCKFALL_AURA = 134849, // Triggers SPELL_ROCKFALL_AURA_S_TRIG each 10 seconds. Permanent boss aura in fight.
    SPELL_ROCKFALL_AURA_S_TRIG = 134364, // Dummy on eff 0 for SPELL_ROCKFALL_SUMMON on random player.
    SPELL_ROCKFALL_SUMMON = 134365, // Summons NPC_ROCKFALL_TORTOS.

    SPELL_SUMMON_BATS = 136686, // Summons 8 Vampiric Cave Bats.

    // Adds

    // Whirl Turtle
    SPELL_SPINNING_SHELL_VISUAL = 133974, // Spin + aura visual.
    SPELL_SPINNING_SHELL_DUMMY = 140443, // Speed decrease + periodic dummy on effect 1 for SPELL_SPINNING_SHELL_DMG.
    SPELL_SPINNING_SHELL_DMG = 134011, // Damage and knockback.

    SPELL_SHELL_BLOCK = 133971, // Damage immune and kickable state aura.

    SPELL_KICK_SHELL_TRIGGER = 134031, // Spell from mechanic abilities button. Sends turtles forward fast. Needs turtle aura SPELL_SHELL_BLOCK to become usable.
    SPELL_KICK_SHELL_STUN = 134073, // Unused.

    SPELL_SHELL_CONCUSSION = 134092, // When kicked, aura triggering SPELL_SHELL_CONCUSSION_INT and SPELL_SHELL_CONCUSSION_D_IN each 300 ms.
    SPELL_SHELL_CONCUSSION_INT = 134091, // Spell casting interruption for 3 seconds in 8y.
    SPELL_SHELL_CONCUSSION_D_IN = 136431, // Damage taken increase by 50% in 8y.

    // Vampiric Cave Bat
    SPELL_DRAIN_THE_WEAK_A = 135103, // Triggers SPELL_DRAIN_THE_WEAK_DMG if target is below 35% health and drains 50x damage dealt.
    SPELL_DRAIN_THE_WEAK_DMG = 135101, // 25% weapon damage.

    // Rockfall
    SPELL_ROCKFALL = 134475, // Visual on ground and triggers 134539 missile drop + damage after 5 seconds.

    // Humming Crystal - HEROIC only.
    SPELL_CRYSTAL_SHELL_AURA = 137552, // Adds SPELL_CRYSTAL_SHELL_ABS, SPELL_CRYSTAL_SHELL_MOD_ABS to player attackers.
    SPELL_CRYSTAL_SHELL_ABS = 137633, // Eff 0 absorb, eff 1 dummy for absorbing max 15% of player's hp.
    SPELL_CRYSTAL_SHELL_MOD_ABS = 137648, // Eff 0 mod absorb %, eff 1 dummy for adding player aura SPELL_CRYSTAL_SHELL_CAPPED on cap when absorbing max 75% player hp.
    SPELL_CRYSTAL_SHELL_CAPPED = 140701  // "Maximum capacity" dummy aura from Crystal Shield (at 5 stacks).
};

enum Npcs
{
    // Boss
    NPC_WHIRL_TURTLE = 67966,
    NPC_VAMPIRIC_CAVE_BAT = 69352,
    NPC_ROCKFALL_TORTOS = 68219,

    // Misc
    NPC_HUMMING_CRYSTAL = 69639  // HEROIC only. When attacked adds Crystal Shell debuff to player atacker.
};

enum Events
{
    // Boss
    EVENT_CALL_OF_TORTOS = 1,
    EVENT_FURIOUS_STONE_BREATH,
    EVENT_RESET_CAST,
    EVENT_SNAPPING_BITE,
    EVENT_QUAKE_STOMP,
    EVENT_SUMMON_BATS,
    EVENT_DAMAGE_PLAYERS_SPIN,
    EVENT_GROWING_FURY,
    EVENT_REGEN_FURY_POWER,

    EVENT_BERSERK,

    // Whirl Turtle
    EVENT_SHELL_BLOCK,
    EVENT_CAST_SHELL_CONCUSSION,
    EVENT_KICKED,
    EVENT_MOVE_STOP,

    // Rockfall trigger
    EVENT_DESPAWN_ME,
    EVENT_MAKE_PLAYERS_IMMUNE_TO_AOE,
};

enum Timers
{
    // Boss
    TIMER_CALL_OF_TORTOS_F = 21000,
    TIMER_CALL_OF_TORTOS_S = 60500,

    TIMER_QUAKE_STOMP_F = 27000,
    TIMER_QUAKE_STOMP_S = 47000,

    TIMER_FURIOUS_STONE_BREATH = 500,
    TIMER_RESET_CAST = 6000,

    TIMER_SNAPPING_BITE_N = 12000,
    TIMER_SNAPPING_BITE_H = 8000,

    TIMER_CALL_BATS_F = 57000,
    TIMER_CALL_BATS_S = 50000,

    TIMER_GROWING_FURY = 6000,
    TIMER_REGEN_FURY_POWER = 450,

    TIMER_BERSERK_H = 600000, // 10 minutes (Heroic).
    TIMER_BERSERK = 780000  // 13 minutes.
};

enum iActions : uint32
{
    ACTION_ACTIVATE_INTRO = 1
};

static const Position aTurtlePos[3] =
{
    { 6046.86f, 4906.66f, -61.18f },
    { 6032.83f, 4906.31f, -61.18f },
    { 6040.08f, 4907.01f, -61.18f },
};

static const Position aBatPos[4] =
{
    { 6043.39f, 5039.37f, -16.43f, 4.66f },
    { 6040.19f, 4922.61f, -15.34f, 1.53f },
    { 6092.45f, 4958.73f, -14.09f, 2.82f },
    { 5996.11f, 4978.12f, -11.01f, 6.21f }
};

static const Position TurtleWp = { 6041.33f, 4940.45f, -61.f };

class boss_tortos : public CreatureScript
{
public:
    boss_tortos() : CreatureScript("boss_tortos") { }

    struct boss_tortosAI : public BossAI
    {
        boss_tortosAI(Creature* creature) : BossAI(creature, DATA_TORTOS), summons(me), vehicle(creature->GetVehicleKit())
        {
            instance = creature->GetInstanceScript();
            ASSERT(vehicle);
        }

        InstanceScript* instance;
        Vehicle* vehicle;
        SummonList summons;
        EventMap events;
        EventMap energyRegen;
        bool breathScheduled;

        uint32 m_growingFuryCooldown;

        void Reset() override
        {
            events.Reset();
            energyRegen.Reset();
            summons.DespawnAll();

            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            DoCast(me, SPELL_ZERO_POWER);
            me->SetPower(POWER_ENERGY, 0);
            //me->RemoveFlag(UNIT_FIELD_FLAGS2, UNIT_FLAG2_REGENERATE_POWER);
            me->AddUnitState(UNIT_STATE_ROOT);

            breathScheduled = false;

            if (instance)
                instance->SetData(DATA_TORTOS, NOT_STARTED);

            _Reset();
        }

        void SpellHit(Unit* pCaster, SpellInfo const* pSpell) override
        {
            if (pSpell->Id == SPELL_SHELL_CONCUSSION_INT)
            {
                if (breathScheduled)
                    me->SetPower(POWER_ENERGY, 0);
                pCaster->InterruptSpell(CURRENT_CHANNELED_SPELL);
                pCaster->InterruptSpell(CURRENT_GENERIC_SPELL);
            }
        }

        void EnterCombat(Unit* who) override
        {
            me->AddAura(SPELL_KICK_SHELL_A, me);
            me->AddAura(SPELL_ROCKFALL_AURA, me);

            events.ScheduleEvent(EVENT_CALL_OF_TORTOS, TIMER_CALL_OF_TORTOS_F);
            events.ScheduleEvent(EVENT_SNAPPING_BITE, IsHeroic() ? TIMER_SNAPPING_BITE_H : TIMER_SNAPPING_BITE_N);
            events.ScheduleEvent(EVENT_QUAKE_STOMP, TIMER_QUAKE_STOMP_F);
            events.ScheduleEvent(EVENT_SUMMON_BATS, TIMER_CALL_BATS_F);

            events.ScheduleEvent(EVENT_GROWING_FURY, 3000, 0, 0);
            energyRegen.ScheduleEvent(EVENT_REGEN_FURY_POWER, TIMER_REGEN_FURY_POWER);
            energyRegen.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);

            m_growingFuryCooldown = 8000;

            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetData(DATA_TORTOS, IN_PROGRESS);
            }

            _EnterCombat();

            if (me->GetMap()->IsHeroic())
                SpawnCrystals();
        }

        void DespawnCrystals()
        {
            std::list<Creature*> crystals;
            me->GetCreatureListWithEntryInGrid(crystals, NPC_HUMMING_CRYSTAL, 500.0f);
            if (!crystals.empty())
                for (std::list<Creature*>::const_iterator itr = crystals.begin(); itr != crystals.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void SpawnCrystals()
        {
            me->SummonCreature(NPC_HUMMING_CRYSTAL, 6073.92f, 4942.84f, -61.70f, 5.33f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_HUMMING_CRYSTAL, 6084.85f, 4962.51f, -62.26f, 6.13f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_HUMMING_CRYSTAL, 6006.00f, 4951.70f, -62.30f, 4.01f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_HUMMING_CRYSTAL, 6007.39f, 4991.19f, -61.52f, 2.36f, TEMPSUMMON_MANUAL_DESPAWN);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            me->AddUnitState(UNIT_STATE_EVADE);

            me->RemoveAllAuras();
            Reset();
            me->DeleteThreatList();
            me->CombatStop(true);
            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
            {
                instance->SetData(DATA_TORTOS, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove

            }
            DespawnCrystals();
        }

        void JustReachedHome() override
        {
            me->ClearUnitState(UNIT_STATE_EVADE);
            DoCast(me, SPELL_ZERO_POWER);
            me->SetPower(POWER_ENERGY, 0);

            _JustReachedHome();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            summon->setActive(true);

            if (me->IsInCombat())
                summon->SetInCombatWithZone();
        }

        void DoMeleeOrGrowingFury()
        {
            Unit* victim = me->GetVictim();
            //Make sure our attack is ready and we aren't currently casting before checking distance
            if (me->isAttackReady())
            {
                if (me->IsWithinMeleeRange(victim))
                {
                    me->AttackerStateUpdate(victim);
                    me->resetAttackTimer();
                    return;
                }
                else
                {
                    ThreatContainer::StorageType threatList = me->getThreatManager().getThreatList();

                    for (ThreatContainer::StorageType::const_iterator itr = threatList.cbegin(); itr != threatList.cend(); ++itr)
                    {
                        if (Unit* target = (*itr)->getTarget())
                        {
                            if (me->IsWithinMeleeRange(target))
                            {
                                me->AttackerStateUpdate(target);
                                me->resetAttackTimer();
                                return;
                            }
                        }
                    }
                }

                if (!m_growingFuryCooldown)
                {
                    //events.ScheduleEvent(EVENT_GROWING_FURY, 1500);
                    m_growingFuryCooldown = 3000;
                }
            }
        }

        void JustDied(Unit* killer) override
        {
            summons.DespawnAll();

            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(DATA_TORTOS, DONE);
            }

            _JustDied();

            DespawnCrystals();
        }

        void UpdateAI(uint32 diff)
        {

            if (!UpdateVictim() || !CheckInRoom())
                return;

            /* @ RAGELESS FIXME
            if (instance && instance->IsWipe())
            {
                EnterEvadeMode();
                return;
            }
            */

            energyRegen.Update(diff);

            switch (energyRegen.ExecuteEvent())
            {
            case EVENT_REGEN_FURY_POWER:
                me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 1);
                energyRegen.ScheduleEvent(EVENT_REGEN_FURY_POWER, TIMER_REGEN_FURY_POWER);
                break;
            case EVENT_BERSERK:
                DoCast(me, SPELL_BERSERK);
                break;
            case EVENT_RESET_CAST:
                breathScheduled = false;
                break;
            }

            if (m_growingFuryCooldown)
            {
                if (m_growingFuryCooldown <= diff)
                    m_growingFuryCooldown = 0;
                else
                    m_growingFuryCooldown -= diff;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetPower(POWER_ENERGY) == 100 && !breathScheduled)
            {
                events.ScheduleEvent(EVENT_FURIOUS_STONE_BREATH, TIMER_FURIOUS_STONE_BREATH);
                breathScheduled = true;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CALL_OF_TORTOS:
                    Talk(ANN_TURTLES);
                    DoCast(me, SPELL_CALL_OF_TORTOS);
                    events.ScheduleEvent(EVENT_CALL_OF_TORTOS, TIMER_CALL_OF_TORTOS_S);
                    break;

                case EVENT_FURIOUS_STONE_BREATH:
                    Talk(ANN_FURIOUS_BREATH);
                    DoCast(me, SPELL_FURIOUS_STONE_BREATH);
                    energyRegen.RescheduleEvent(EVENT_REGEN_FURY_POWER, 5000);
                    energyRegen.ScheduleEvent(EVENT_RESET_CAST, 500);
                    break;

                case EVENT_SNAPPING_BITE:
                    DoCast(me->GetVictim(), SPELL_SNAPPING_BITE);
                    events.ScheduleEvent(EVENT_SNAPPING_BITE, IsHeroic() ? TIMER_SNAPPING_BITE_H : TIMER_SNAPPING_BITE_N);
                    break;

                case EVENT_QUAKE_STOMP:
                    DoCast(me, SPELL_QUAKE_STOMP);
                    events.ScheduleEvent(EVENT_QUAKE_STOMP, TIMER_QUAKE_STOMP_S);
                    break;

                case EVENT_SUMMON_BATS:
                {
                    Position pos = aBatPos[urand(0, 3)];
                    me->CastSpell(pos.m_positionX, pos.m_positionY, pos.m_positionZ, SPELL_SUMMON_BATS, true);
                    events.ScheduleEvent(EVENT_SUMMON_BATS, TIMER_CALL_BATS_S);
                    break;
                }
                case EVENT_GROWING_FURY:
                {
                    if (Unit* target = me->GetVictim())
                    {
                        if (!target)
                            return;
                        if (me->GetExactDist2d(target) > 25.0f) // if distance ( melee range ) is more than 20 yards > cast growing fury
                        {
                            me->CastSpell(me, SPELL_GROWING_FURY);
                        }
                    }
                    events.ScheduleEvent(EVENT_GROWING_FURY, 3000, 0, 0);
                    break;
                }
                default: break;
                }
            }

            DoMeleeOrGrowingFury();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_tortosAI(creature);
    }
};

// Whirl Turtle 67966
class npc_whirl_turtle : public CreatureScript
{
    enum events : uint32
    {
        EVENT_NONE,
        EVENT_MOVE,
        EVENT_INIT_MOVE
    };
public:
    npc_whirl_turtle() : CreatureScript("npc_whirl_turtle") { }

    struct npc_whirl_turtleAI : public ScriptedAI
    {
        npc_whirl_turtleAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;
        bool shellBlocked;
        bool failSafe;

        void IsSummonedBy(Unit* summoner)
        {
            me->SetInCombatWithZone();
            me->SetReactState(REACT_PASSIVE);
            //me->SetSpeed(MOVE_RUN, 3.0f, true);
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_DAMAGE_PLAYERS_SPIN, 500);
            events.ScheduleEvent(EVENT_MOVE, 3000, 0, 0);
        }

        void Move()
        {
            if (Creature* pTortos = me->FindNearestCreature(BOSS_TORTOS, 50.0f, true))
            {
                std::list<Unit*>targetList;
                std::list<HostileReference*> threatList = pTortos->getThreatManager().getThreatList();
                uint32 max_size = (pTortos->GetMap()->Is25ManRaid() ? 8 : 3);

                if (threatList.size() > max_size)
                {

                    for (auto itr = threatList.cbegin(); itr != threatList.cend(); ++itr)
                    {
                        if (Unit* target = (*itr)->getTarget())
                        {
                            if (target && target->ToPlayer() && target->GetExactDist2d(me) > 20.f && !target->HasAura(SPELL_SPINNING_SHELL_DUMMY))//(&DefaultTargetSelector(target, -20.f, true, -SPELL_SPINNING_SHELL_DUMMY)))
                                targetList.push_back(target);
                        }
                    }

                    if (!targetList.empty())
                    {
                        std::list<Unit*>::iterator find = targetList.begin();
                        std::advance(find, urand(0, targetList.size() - 1));

                        if (Unit* pTarget = *find)
                        {
                            me->GetMotionMaster()->MovementExpired();
                            me->GetMotionMaster()->MovePoint(2, *pTarget);

                            events.ScheduleEvent(EVENT_MOVE, 5000 + rand() % 2000);
                            return;
                        }
                    }

                    std::list<HostileReference*>::iterator find = threatList.begin();
                    std::advance(find, urand(0 /*1*/, threatList.size() - 1));

                    if (Unit* pTarget = (*find)->getTarget())
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePoint(2, *pTarget);

                        events.ScheduleEvent(EVENT_MOVE, 5000 + rand() % 2000);
                        return;
                    }
                }
            }

            Position pos;
            me->GetRandomNearPosition(25.f);
            me->GetMotionMaster()->MovePoint(2, pos);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) override
        {
            if (uiType != POINT_MOTION_TYPE || shellBlocked)
                return;

            if (uiPointId == 4)
            {
                events.ScheduleEvent(EVENT_MOVE, 200 + rand() % 500);
                me->SetWalk(true);
            }
            if (uiPointId == 2)
                events.RescheduleEvent(EVENT_MOVE, 200);
        }

        void Reset()
        {
            me->SetInCombatWithZone();
            me->SetReactState(REACT_PASSIVE);
            // me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SPINNING_SHELL_DMG, true);
            me->AddAura(SPELL_SPINNING_SHELL_VISUAL, me);
            me->AddAura(SPELL_SPINNING_SHELL_DUMMY, me);
            failSafe = false;
            shellBlocked = false;
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_KICK_SHELL_TRIGGER)
            {
                me->RemoveAura(42716); // root
                me->AddUnitState(UNIT_STATE_ROOT);
                me->AddAura(SPELL_SHELL_CONCUSSION, me);
                events.ScheduleEvent(EVENT_CAST_SHELL_CONCUSSION, 500);
                float x, y, z;
                caster->GetClosePoint(x, y, z, caster->GetObjectSize() / 3, 80.0f);
                me->GetMotionMaster()->MoveCharge(x, y, z + 2, 30.0f);
                me->DespawnOrUnsummon(9000);
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (me->HealthBelowPct(3) && !shellBlocked)
            {
                me->RemoveAurasDueToSpell(SPELL_SPINNING_SHELL_VISUAL);
                me->RemoveAurasDueToSpell(SPELL_SPINNING_SHELL_DUMMY);
                me->AddUnitState(UNIT_STATE_ROOT);
                events.CancelEvent(EVENT_INIT_MOVE);
                events.CancelEvent(EVENT_MOVE);
                events.CancelEvent(EVENT_MOVE_STOP);
                events.CancelEvent(EVENT_DAMAGE_PLAYERS_SPIN);
                me->AddAura(42716, me); // root
                me->AddAura(SPELL_SHELL_BLOCK, me);
                //me->GetMotionMaster()->MovementExpired();
                //me->GetMotionMaster()->MoveIdle();
                shellBlocked = true;
            }
            if (me->HealthBelowPct(2) && !failSafe)
            {
                failSafe = true;
                damage = 0;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_MOVE:
            {
                std::list<Unit*> targets;
                SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
                if (!targets.empty())
                    if (targets.size() >= 1)
                        targets.resize(1);

                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if ((*itr)->IsFalling())
                    {
                        events.ScheduleEvent(EVENT_MOVE_STOP, 2000, 0, 0);
                        return;
                    }
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                events.ScheduleEvent(EVENT_MOVE_STOP, 5000, 0, 0);
                break;
            }
            case EVENT_MOVE_STOP:
            {
                Position pos;
                me->GetRandomNearPosition(25.0f);
                me->GetMotionMaster()->MovePoint(3, pos);
                events.ScheduleEvent(EVENT_MOVE, 5000, 0, 0);
                break;
            }
            case EVENT_INIT_MOVE:
                me->GetRandomPoint(me->GetPosition(), 15.0f);
                me->GetMotionMaster()->MovePoint(4, me->GetPosition());
                break;
            case EVENT_DAMAGE_PLAYERS_SPIN:
            {
                Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (Player* player = i->GetSource())
                        {
                            if (player->GetDistance(me) < 3.0f)
                                player->CastSpell(player, SPELL_SPINNING_SHELL_DMG, true);
                        }
                    }
                }
                events.ScheduleEvent(EVENT_DAMAGE_PLAYERS_SPIN, 2000, 0, 0);
                break;
            }
            case EVENT_CAST_SHELL_CONCUSSION:
            {
                std::list<Creature*> trigger;
                GetCreatureListWithEntryInGrid(trigger, me, NPC_VAMPIRIC_CAVE_BAT, 200.0f);
                if (!trigger.empty())
                {
                    for (Creature* trig : trigger)
                    {
                        if (trig->GetExactDist2d(me), 3.5f)
                        {
                            trig->AddAura(SPELL_SHELL_CONCUSSION_D_IN, trig);
                        }
                    }
                }
                events.ScheduleEvent(EVENT_CAST_SHELL_CONCUSSION, 100);
                break;
            }
            }
        }

        void DamagePlayers()
        {
            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* player = i->GetSource())
                    {
                        if (player->GetDistance(me) < 5)
                            player->CastSpell(player, SPELL_SPINNING_SHELL_DMG, true);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_whirl_turtleAI(creature);
    }
};

// Vampiric Cave Bat 69352
class npc_vampiric_cave_bat : public CreatureScript
{
public:
    npc_vampiric_cave_bat() : CreatureScript("npc_vampiric_cave_bat") { }

    struct npc_vampiric_cave_batAI : public ScriptedAI
    {
        npc_vampiric_cave_batAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            Reset();
            DoZoneInCombat(me, 130.0f);
        }

        void Reset()
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_FLYING | MOVEMENTFLAG_CAN_FLY);
            me->AddAura(SPELL_DRAIN_THE_WEAK_A, me);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vampiric_cave_batAI(creature);
    }
};

// Rockfall 68219
class npc_rockfall_tortos : public CreatureScript
{
public:
    npc_rockfall_tortos() : CreatureScript("npc_rockfall_tortos") { }

    struct npc_rockfall_tortosAI : public ScriptedAI
    {
        npc_rockfall_tortosAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        EventMap events;

        void IsSummonedBy(Unit* /*summoner*/)
        {
            Reset();
            DoCast(me, SPELL_ROCKFALL, true);
            events.ScheduleEvent(EVENT_DESPAWN_ME, 6500, 0, 0);
            events.ScheduleEvent(EVENT_MAKE_PLAYERS_IMMUNE_TO_AOE, 500, 0, 0);
            //me->DespawnOrUnsummon(7000);
        }

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void JustDied(Unit*)
        {
            RemoveImmunity();
        }

        void RemoveImmunity()
        {
            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* player = i->GetSource())
                    {
                        player->ApplySpellImmune(0, IMMUNITY_ID, 134476, false); // remove rockfall AOE DAMAGE
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DESPAWN_ME:
                    me->Kill(me);
                    me->DespawnOrUnsummon(1000);
                    break;
                case EVENT_MAKE_PLAYERS_IMMUNE_TO_AOE:
                {
                    Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (Player* player = i->GetSource())
                            {
                                if (player->GetExactDist(me) < 5.0f)
                                    player->ApplySpellImmune(0, IMMUNITY_ID, 134476, true); // add rockfall AOE DAMAGE
                                else if (player->GetExactDist(me) > 4.0f)
                                    player->ApplySpellImmune(0, IMMUNITY_ID, 134476, false); // remove rockfall aoe damage
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_MAKE_PLAYERS_IMMUNE_TO_AOE, 300, 0, 0);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_rockfall_tortosAI(creature);
    }
};

// Humming Crystal 69639 - HEROIC only
class npc_humming_crystal : public CreatureScript
{
public:
    npc_humming_crystal() : CreatureScript("npc_humming_crystal") { }

    struct npc_humming_crystalAI : public ScriptedAI
    {
        npc_humming_crystalAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            Reset();
            //me->AddAura(SPELL_CRYSTAL_SHELL_AURA, me);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            //me->AddAura(SPELL_CRYSTAL_SHELL_AURA, attacker);
            attacker->CastSpell(attacker, 137633, true);
            attacker->CastSpell(attacker, 137648, true);
        }

        void Reset()
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 diff) { }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_humming_crystalAI(creature);
    }
};

// Call of Tortos 136294
class spell_call_of_tortos : public SpellScriptLoader
{
public:
    spell_call_of_tortos() : SpellScriptLoader("spell_call_of_tortos") { }

    class spell_call_of_tortos_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_call_of_tortos_SpellScript);

        void HandleAfterCast() // SpellEffIndex /*effIndex*/
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            for (uint8 i = 0; i < 3; ++i)
                caster->SummonCreature(NPC_WHIRL_TURTLE, aTurtlePos[i], TEMPSUMMON_MANUAL_DESPAWN);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_call_of_tortos_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_call_of_tortos_SpellScript();
    }
};

// Rockfall 140431, 134364
class spell_rockfall_trigger_tortos : public SpellScriptLoader
{
public:
    spell_rockfall_trigger_tortos() : SpellScriptLoader("spell_rockfall_trigger_tortos") { }

    class spell_rockfall_trigger_tortos_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rockfall_trigger_tortos_SpellScript);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());

            if (targets.size() > 1)
                Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rockfall_trigger_tortos_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_rockfall_trigger_tortos_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rockfall_trigger_tortos_SpellScript();
    }
};

class spell_rockfall_damage : public SpellScriptLoader
{
    enum eSpells : uint32
    {
        SPELL_ROCKFALL_LARGE_AOE = 134476
    };
public:
    spell_rockfall_damage() : SpellScriptLoader("spell_rockfall_damage") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleOnCast()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_ROCKFALL_LARGE_AOE, true);
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_impl::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spell_rockfall_aoe_damage : public SpellScriptLoader
{
public:
    spell_rockfall_aoe_damage() : SpellScriptLoader("spell_rockfall_aoe_damage") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

class spinningShellPredicate
{
private:
    Unit* caster;
public:
    spinningShellPredicate(Unit* _caster) : caster(_caster) {}

    bool operator()(WorldObject* target) const
    {
        if (target->GetExactDist2d(caster) < 5.1f && target->GetPositionZ() <= (caster->GetPositionZ() + 1.f))
            return false;

        return true;
    }
};

// Spinning Shell 140443
class spell_spinning_shell : public SpellScriptLoader
{
public:
    spell_spinning_shell() : SpellScriptLoader("spell_spinning_shell") { }

    class spell_spinning_shell_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_spinning_shell_AuraScript);

            void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            if (!caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
            {
                PreventDefaultAction();
                Remove(AURA_REMOVE_BY_EXPIRE);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_spinning_shell_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_spinning_shell_AuraScript();
    }
};

class spell_shell_concussion : public SpellScriptLoader
{
public:
    spell_shell_concussion() : SpellScriptLoader("spell_shell_concussion") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if([this](WorldObject* target) -> bool
                {
                    return target->ToUnit() && target->ToUnit()->HasAura(SPELL_SHELL_CONCUSSION_D_IN);
                });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

// Drain the Weak 135103
class spell_drain_the_weak : public SpellScriptLoader
{
public:
    spell_drain_the_weak() : SpellScriptLoader("spell_drain_the_weak") { }

    class spell_drain_the_weak_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_drain_the_weak_AuraScript);

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            Unit* target = GetCaster()->GetVictim();

            if (!caster || !target)
                return;


                caster->CastSpell(target, SPELL_DRAIN_THE_WEAK_DMG, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_drain_the_weak_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_drain_the_weak_AuraScript();
    }
};

class spell_drain_the_weak_damage : public SpellScriptLoader
{
    enum eSpells : uint32
    {
        SPELL_DRAIN_THE_WEAK_HEAL = 135102
    };
public:
    spell_drain_the_weak_damage() : SpellScriptLoader("spell_drain_the_weak_damage") {}

    class spell_impl : public SpellScript
    {
        PrepareSpellScript(spell_impl);

        void HandleEffectHitTarget(SpellEffIndex eff_idx)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_DRAIN_THE_WEAK_HEAL);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_impl::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_impl();
    }
};

// Crystal Shell 137633
class spell_crystal_shell_aura : public SpellScriptLoader
{
public:
    spell_crystal_shell_aura() : SpellScriptLoader("spell_crystal_shell_aura") { }

    class spell_crystal_shell_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_crystal_shell_aura_AuraScript);

        void CalculateAmount(AuraEffect const* auraEffect, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount += GetCaster()->CountPctFromMaxHealth(15);
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* target = GetCaster();
            if (!target)
                return;
            if (target->HasAura(SPELL_CRYSTAL_SHELL_CAPPED))
            {
                target->RemoveAura(137648); // healing absorb
                target->RemoveAura(SPELL_CRYSTAL_SHELL_CAPPED);
            }
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_crystal_shell_aura_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_crystal_shell_aura_AuraScript::OnAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_crystal_shell_aura_AuraScript();
    }
};

// 137648
class spell_crystal_shell_absorb : public SpellScriptLoader
{
public:
    spell_crystal_shell_absorb() : SpellScriptLoader("spell_crystal_shell_absorb") { }

    class spell_crystal_shell_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_crystal_shell_absorb_AuraScript);

        void OnProc(const AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            //int32 amount = aurEff->GetSpellInfo()->Effects[EFFECT_0].BasePoints;

            if (Unit* target = GetCaster())
            {
                if (!target)
                    return;
                if (target->HasAura(SPELL_CRYSTAL_SHELL_CAPPED))
                    return;

                if (Aura* shell = target->GetAura(137633))
                {
                    if (Aura* absorb = target->GetAura(137648))
                    {

                        if (!shell || !absorb)
                            return;

                        //int32 amount = absorb->GetSpellInfo()->Effects[EFFECT_0].BasePoints;
                        int32 amount = eventInfo.GetHealInfo()->GetHeal();
                        int32 base = shell->GetEffect(EFFECT_0)->GetAmount();
                        shell->GetEffect(EFFECT_0)->SetAmount(amount + base);
                        uint32 newAmount = amount + base;
                        if (newAmount > target->CountPctFromMaxHealth(75))
                        {
                            newAmount = target->CountPctFromMaxHealth(75);
                            target->AddAura(SPELL_CRYSTAL_SHELL_CAPPED, target);
                            target->RemoveAura(137648); // healing absorb
                        }
                    }
                }
            }
        }


        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_crystal_shell_absorb_AuraScript::OnProc, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_crystal_shell_absorb_AuraScript();
    }
};

// Quake Stomp 134920
class spell_tortos_quake_stomp : public SpellScriptLoader
{
public:
    spell_tortos_quake_stomp() : SpellScriptLoader("spell_tortos_quake_stomp") { }

    class spell_tortos_quake_stomp_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tortos_quake_stomp_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;
            if (caster->GetMap()->IsHeroic())
            {
                uint32 damage = target->CountPctFromMaxHealth(100);
                // resilience/armor/absorb
                //SpellNonMeleeDamage damageInfo(caster, target, GetSpellInfo()->Id, GetSpellInfo()->SchoolMask);
                //caster->CalculateSpellDamageTaken(&damageInfo, damage, GetSpellInfo());
               // damage = damageInfo.damage;
                //bfa_SendWorldText("damage = %d", damage);
                SetHitDamage(GetHitDamage() + 10000);
                //bfa_SendWorldText("damage = %d", damage);
            }
            else
            {
                uint32 damage = target->CountPctFromMaxHealth(65);
                // resilience/armor/absorb
               // SpellNonMeleeDamage damageInfo(caster, target, GetSpellInfo()->Id, GetSpellInfo()->SchoolMask);
                //caster->CalculateSpellDamageTaken(&damageInfo, damage, GetSpellInfo());
                //damage = damageInfo.damage;
                //bfa_SendWorldText("damage = %d", damage);
                SetHitDamage(GetHitDamage() + 10000);
                //bfa_SendWorldText("damage = %d", damage);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_tortos_quake_stomp_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_tortos_quake_stomp_SpellScript();
    }
};

class spell_furious_stone_breath : public SpellScriptLoader
{
public:
    spell_furious_stone_breath() : SpellScriptLoader("spell_furious_stone_breath") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Creature* pCreature = GetCaster()->ToCreature())
                pCreature->SetPower(POWER_ENERGY, 0);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

// 133946
class spell_furious_stone_breath_damage : public SpellScriptLoader
{
public:
    spell_furious_stone_breath_damage() : SpellScriptLoader("spell_furious_stone_breath_damage") {}

    class spell_furious_stone_breath_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_furious_stone_breath_damage_SpellScript);

        void CheckDamageOnLfr()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

        }

        void Register()
        {
            OnCast += SpellCastFn(spell_furious_stone_breath_damage_SpellScript::CheckDamageOnLfr);
        }
    };


    SpellScript* GetSpellScript() const
    {
        return new spell_furious_stone_breath_damage_SpellScript();
    }
};

/*** INTRO ***/

enum LeiShenIntroYells
{
    SAY_LEI_SHEN_INTRO_1 = 0, // You have swept the filth from my doorstep. Perhaps, you are worthy of my attention. - sound 35587
    SAY_LEI_SHEN_INTRO_2,     // But...your trespass ends here. None may enter my forbidden stronghold. I shall rebuild this bridge with your bones for bricks." - sound 35588
};

enum LeiShenEvents
{
    EVENT_LEI_SHEN_SEND_CINEMATIC = 1,
    EVENT_LEI_SHEN_I_1,
    EVENT_LEI_SHEN_I_2,
    EVENT_LEI_SHEN_VISUAL_CAST,
    EVENT_LEI_SHEN_DESTROY_BRIDGE,
    EVENT_LEI_SHEN_TELEPORT_PLAYERS
};

enum LeiShenIntroSpells
{
    SPELL_PLATFORM_DUMMY = 82827,
    SPELL_BRIDGE_VIS_S = 139853, // Boss visual
    SPELL_TELEPORT_DEPTH = 139852  // Tortos tele spell
};

enum LeiShenIntroCreatures
{
    NPC_BRIDGE_TRIGGER = 66305,
    NPC_TORTOS_TRIGGER = 55091
};

enum LeiShenIntroGo
{
    GO_TORTOS_BRIDGE = 218869
};

static const Position pMidBridge = { 6046.22f, 5100.34f, 154.f };

// Lei Shen - tortos intro 70437
class npc_lei_shen_tortos : public CreatureScript
{
    enum eTimers : uint32
    {
        EVENT_DESTROY_BRIDGE = 26
    };
public:
    npc_lei_shen_tortos() : CreatureScript("npc_lei_shen_tortos") { }

    struct npc_lei_shen_tortosAI : public ScriptedAI
    {
        npc_lei_shen_tortosAI(Creature* creature) : ScriptedAI(creature)
        {
            introDone = false;
        }

        EventMap events;
        bool introDone;

        void Reset() override
        {
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);

            if (me->GetInstanceScript()->GetData(TYPE_TORTOS_INTRO) == DONE)
            {
                events.ScheduleEvent(EVENT_DESTROY_BRIDGE, 200);
                me->SetReactState(REACT_PASSIVE);
                me->SetVisible(false);
            }
        }

        void DoAction(int32 iAction) override
        {
            if (!introDone)
            {
                if (iAction == ACTION_ACTIVATE_INTRO)
                {
                    introDone = true;

                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_LEI_SHEN_SEND_CINEMATIC, 100);
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DESTROY_BRIDGE:
                    if (GameObject* bridge = me->FindNearestGameObject(GO_TORTOS_BRIDGE, 300.0f))
                        bridge->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                    me->setActive(false);
                    break;
                case EVENT_LEI_SHEN_SEND_CINEMATIC:
                    events.CancelEvent(EVENT_DESTROY_BRIDGE);
                    if (Creature* pCreature = me->SummonCreature(NPC_BRIDGE_TRIGGER, pMidBridge, TEMPSUMMON_TIMED_DESPAWN, 60000))
                    {
                        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                if (Player* player = i->GetSource())
                                {
                                    Position playerPos;
                                    pCreature->GetRandomNearPosition(16.0f);
                                    playerPos.m_positionZ = 154.f;

                                    player->NearTeleportTo(playerPos.GetPositionX(), playerPos.GetPositionY(), playerPos.GetPositionZ(), player->GetAngle(me));

                                    if (Aura* slowfall = player->AddAura(130, player))
                                    {
                                        slowfall->SetMaxDuration(3 * MINUTE * IN_MILLISECONDS);
                                        slowfall->SetDuration(3 * MINUTE * IN_MILLISECONDS);
                                    }
                                    player->SendCinematicStart(271);
                                }
                            }
                        }
                    }
                    if (me->GetInstanceScript())
                        me->GetInstanceScript()->SetData(TYPE_TORTOS_INTRO, DONE);
                    events.ScheduleEvent(EVENT_LEI_SHEN_I_1, 5900); // at 6 seconds.
                    break;

                case EVENT_LEI_SHEN_I_1:
                    Talk(SAY_LEI_SHEN_INTRO_1);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                    events.ScheduleEvent(EVENT_LEI_SHEN_I_2, 8000); // at 14 seconds.
                    break;

                case EVENT_LEI_SHEN_I_2:
                    Talk(SAY_LEI_SHEN_INTRO_2);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    events.ScheduleEvent(EVENT_LEI_SHEN_VISUAL_CAST, 8000); // at 22 seconds.
                    break;

                case EVENT_LEI_SHEN_VISUAL_CAST:
                    DoCast(me, SPELL_BRIDGE_VIS_S);
                    events.ScheduleEvent(EVENT_LEI_SHEN_DESTROY_BRIDGE, 4000); // at 26 seconds.
                    break;

                case EVENT_LEI_SHEN_DESTROY_BRIDGE:
                {
                    if (GameObject* bridge = me->FindNearestGameObject(GO_TORTOS_BRIDGE, 300.0f))
                        bridge->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                    events.ScheduleEvent(EVENT_LEI_SHEN_TELEPORT_PLAYERS, 16000); // at 41 seconds.
                }
                break;
                case EVENT_LEI_SHEN_TELEPORT_PLAYERS:
                    me->GetMap()->LoadGrid(6041.180f, 5100.50f);
                    DoCast(SPELL_TELEPORT_DEPTH);
                    me->SetVisible(false);
                    break;

                default: break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lei_shen_tortosAI(creature);
    }
};

// Call Lightning 139853
class spell_lei_shen_tortos_bridge_call_lightning : public SpellScriptLoader
{
public:
    spell_lei_shen_tortos_bridge_call_lightning() : SpellScriptLoader("spell_lei_shen_tortos_bridge_call_lightning") { }

    class spell_lei_shen_tortos_bridge_call_lightning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_lei_shen_tortos_bridge_call_lightning_AuraScript);

            float min_dist;

        bool Load()
        {
            min_dist = 0.f;
            return true;
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            std::list<Creature*> trigger;
            GetCreatureListWithEntryInGrid(trigger, caster, NPC_BRIDGE_TRIGGER, 600.0f);
            if (!trigger.empty())
            {
                trigger.sort(Trinity::ObjectDistanceOrderPred(caster));
                for (Creature* trig : trigger)
                {
                    if (trig->GetExactDist2d(caster) > min_dist)
                    {
                        min_dist = trig->GetExactDist2d(caster);
                        trig->CastSpell(trig, SPELL_PLATFORM_DUMMY, false);
                        break;
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_lei_shen_tortos_bridge_call_lightning_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_lei_shen_tortos_bridge_call_lightning_AuraScript();
    }
};

class spell_teleport_all : public SpellScriptLoader
{
public:
    spell_teleport_all() : SpellScriptLoader("spell_teleport_all") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleAuraEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* Owner = GetOwner()->ToUnit())
            {
                Owner->SetControlled(false, UNIT_STATE_STUNNED);
                Owner->NearTeleportTo(6041.22f, 5085.77f, -42.f, 4.81f);

                Owner->RemoveAurasDueToSpell(130);
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(aura_impl::HandleAuraEffectRemove, EFFECT_1, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

class spell_waterspout_aura : public SpellScriptLoader
{
public:
    spell_waterspout_aura() : SpellScriptLoader("spell_waterspout_aura") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void HandleOnPeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();

            if (Unit* pOwner = GetOwner()->ToUnit())
            {
                pOwner->CastSpell(pOwner, 139165, true);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(aura_impl::HandleOnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

void AddSC_boss_tortos()
{
    new boss_tortos();
    new npc_whirl_turtle();
    new npc_vampiric_cave_bat();
    new npc_rockfall_tortos();
    new npc_humming_crystal();
    new spell_call_of_tortos();
    new spell_rockfall_trigger_tortos();
    new spell_rockfall_damage();
    new spell_rockfall_aoe_damage();
    new spell_spinning_shell();
    new spell_shell_concussion();
    new spell_drain_the_weak();
    new spell_drain_the_weak_damage();
    new spell_crystal_shell_aura();
    new spell_tortos_quake_stomp();
    new spell_furious_stone_breath();
    new npc_lei_shen_tortos();
    new spell_lei_shen_tortos_bridge_call_lightning();
    new spell_teleport_all();
    new spell_waterspout_aura();
    new spell_crystal_shell_absorb();
    new spell_furious_stone_breath_damage;
}

/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "lost_city_of_the_tolvir.h"
#include "Vehicle.h"

enum eSpells
{
    SPELL_HAMMER_FIST                              = 83655,
    // Mystic Trap
    SPELL_MYSTIC_TRAP_FIND_TARGET                  = 83644,
    SPELL_TOLVIR_MINE_PLAYER_SEARCH_TRIGGER        = 83111,
    SPELL_THROW_LAND_MINES                         = 83122,
    SPELL_TOLVIR_LAND_MINE_VISUAL                  = 83110,
    SPELL_TOLVIR_LAND_MIVE_PERIODIC                = 85523,
    SPELL_MYSTIC_TRAP                              = 83171,
    SPELL_DETONATE_TRAPS                           = 91263,
    // Bad Intentions
    SPELL_BAD_INTENTIONS                           = 83113,
    SPELL_THROW_VISUAL                             = 83371,
    SPELL_HARD_IMPACT                              = 83339,
    SPELL_RIDE_VEHICLE_HARDCODED                   = 46598,
    SPELL_HURL_SCRIPT                              = 83236,
    SPELL_HURL_RIDE                                = 83235,
    // Shockwave
    SPELL_SHOCKWAVE                                = 83445,
    SPELL_SHOCKWAVE_VISUAL                         = 83130,
    SPELL_SHOCKWAVE_STALKER_VISUAL                 = 83127,
    SPELL_SHOCKWAVE_DAMAGE                         = 83454,
    SPELL_SUMMON_SHOCKWAVE                         = 83128,
};

enum eCreatures
{
    NPC_MYSTIC_TRAP_TARGET                         = 44840,
    NPC_BAD_INTENTIONS_TARGET                      = 44586,
};

enum eEvents
{
    EVENT_SUMMON_LAND_MINES                        = 1,
    EVENT_COUNTDOWN_LAND_MINES                     = 2,
    EVENT_SUMMON_SHOCKWAVE                         = 3,
    EVENT_HAMMER_FIST                              = 4,
    EVENT_BAD_INTENTIONS                           = 5,
    EVENT_AFTER_SHOCKWAVE                          = 6,
};

enum ePhases
{
    LAND_MINE_STATE_JUSTADDED                      = 0x1,
    LAND_MINE_STATE_ACTIVATED                      = 0x2,
    LAND_MINE_STATE_COUNTDOWN                      = 0x4,
    LAND_MINE_STATE_DETONATED                      = 0x8,
};

enum Texts
{
    SAY_FINISH                                     = 0,
    SAY_START                                      = 1,
    SAY_CAST_SHOCKVAWE_1                           = 2,
    SAY_CAST_SHOCKVAWE_2                           = 3,
    YELL_KILL_PLAYER_1                             = 4,
    YELL_TREAD_LIGHTLY                             = 5,
};

class boss_general_husam : public CreatureScript
{
public:
    boss_general_husam() : CreatureScript("boss_general_husam") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_general_husamAI (creature);
    }

    struct boss_general_husamAI : public ScriptedAI
    {
        boss_general_husamAI(Creature* creature) : ScriptedAI(creature), lSummons(me)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        }

        SummonList lSummons;
        InstanceScript* instance;
        uint8 uiHammerFistCount;
        EventMap events;

        void Reset() override
        {
            if (Vehicle* vehicle = me->GetVehicleKit())
                vehicle->RemoveAllPassengers();

            if (instance)
                instance->SetData(DATA_GENERAL_HUSAM, NOT_STARTED);

            lSummons.DespawnAll();
            events.Reset();
            uiHammerFistCount = 0;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
                me->CastSpell(who, SPELL_HURL_SCRIPT, false);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (instance)
                instance->SetData(DATA_GENERAL_HUSAM, IN_PROGRESS);

            Talk(SAY_START);
            events.ScheduleEvent(EVENT_SUMMON_LAND_MINES, 3000);
            // To do: fix client crash
            //events.ScheduleEvent(EVENT_SUMMON_SHOCKWAVE, urand(12000, 17000));
            events.ScheduleEvent(EVENT_HAMMER_FIST, 5000);
            //events.ScheduleEvent(EVENT_BAD_INTENTIONS, urand(7000, 11000));

            if (IsHeroic())
                events.ScheduleEvent(EVENT_COUNTDOWN_LAND_MINES, 15000);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == 44798)
            {
                float x, y, z;
                summoned->GetPosition(x, y, z);

                if (Creature* mine = me->SummonCreature(44796, x, y, z))
                    mine->EnterVehicle(summoned);
            }

            lSummons.Summon(summoned);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->IsPlayer())
                Talk(YELL_KILL_PLAYER_1);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
                instance->SetData(DATA_GENERAL_HUSAM, DONE);

            Talk(SAY_FINISH);
            lSummons.DespawnAll();
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
                    case EVENT_COUNTDOWN_LAND_MINES:
                        Talk(YELL_TREAD_LIGHTLY);
                        events.ScheduleEvent(EVENT_COUNTDOWN_LAND_MINES, 15000);
                        me->CastSpell(me, SPELL_DETONATE_TRAPS, false);
                        break;
                    case EVENT_SUMMON_LAND_MINES:
                        {
                            me->CastSpell(me, SPELL_MYSTIC_TRAP_FIND_TARGET, false);
                            std::list<Creature*> lTriggers;
                            me->GetCreatureListWithEntryInGrid(lTriggers, NPC_MYSTIC_TRAP_TARGET, 50.0f);

                            if (!lTriggers.empty())
                                for (std::list<Creature*>::const_iterator itr = lTriggers.begin(); itr != lTriggers.end(); ++itr)
                                    if (*itr)
                                        me->CastSpell((*itr), SPELL_THROW_LAND_MINES, false);

                            events.ScheduleEvent(EVENT_SUMMON_LAND_MINES, 11000);
                        }
                        break;
                    case EVENT_SUMMON_SHOCKWAVE:
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            Talk(SAY_CAST_SHOCKVAWE_1);
                            Talk(SAY_CAST_SHOCKVAWE_2);

                            float _x, _y, x, y, z, o;
                            me->GetPosition(x, y, z, o);

                            for (int i = 0; i < 4; ++i)
                            {
                                _x = x + 3.0f * cos(o);
                                _y = y + 3.0f * sin(o);
                                me->SummonCreature(44711, _x, _y, z, o);
                                o += float(M_PI) / 2;
                            }

                            me->CastSpell(me, SPELL_SHOCKWAVE, false);
                            events.ScheduleEvent(EVENT_AFTER_SHOCKWAVE, 5500);
                        }
                        break;
                    case EVENT_AFTER_SHOCKWAVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_SUMMON_SHOCKWAVE, urand(25000, 50000));
                        break;
                    case EVENT_HAMMER_FIST:
                        {
                            ++uiHammerFistCount;
                            me->CastSpell(me->GetVictim(), SPELL_HAMMER_FIST, false);

                            if (uiHammerFistCount < 4)
                                events.ScheduleEvent(EVENT_HAMMER_FIST, 500);
                            else
                            {
                                uiHammerFistCount = 0;
                                events.ScheduleEvent(EVENT_HAMMER_FIST, urand(5000, 15000));
                            }
                        }
                        break;
                    case EVENT_BAD_INTENTIONS:
                        {
                            events.ScheduleEvent(EVENT_BAD_INTENTIONS, urand(15000, 20000));

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                                me->CastSpell(target, SPELL_BAD_INTENTIONS, false);
                        }
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_land_mine : public CreatureScript
{
public:
    npc_land_mine() : CreatureScript("npc_land_mine") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_land_mineAI (creature);
    }

    struct npc_land_mineAI : public ScriptedAI
    {
        npc_land_mineAI(Creature* creature) : ScriptedAI(creature)
        {
            uiState = LAND_MINE_STATE_JUSTADDED;
            uiDespawnTimer = 1000;
            uiActivationTimer = 2000;
            uiCountdownTimer = urand(20000, 35000);
            me->SetInCombatWithZone();
        }

        uint32 uiActivationTimer;
        uint32 uiCountdownTimer;
        uint32 uiDespawnTimer;
        uint8 uiState;

        void AddMineState(uint32 state)
        {
            uiState |= state;
        }

        bool HasMineState(const uint32 state) const
        {
            return (uiState & state);
        }

        void ClearMineState(uint32 state)
        {
            uiState &= ~state;
        }

        void StartCountDown()
        {
            if (HasMineState(LAND_MINE_STATE_DETONATED | LAND_MINE_STATE_COUNTDOWN) || !HasMineState(LAND_MINE_STATE_ACTIVATED))
                return;

            AddMineState(LAND_MINE_STATE_DETONATED);
            AddMineState(LAND_MINE_STATE_COUNTDOWN);
            me->AddAura(SPELL_TOLVIR_LAND_MIVE_PERIODIC, me);
            uiDespawnTimer = 5500;
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_DETONATE_TRAPS)
                StartCountDown();
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (spell->Id == 83112)
            {
                float x, y, _x, _y;
                me->GetPosition(x, y);
                target->GetPosition(_x, _y);

                if (sqrt(pow(x - _x, 2) + pow(y - _y, 2)) < 1.4f)
                {
                    if (!HasMineState(LAND_MINE_STATE_ACTIVATED))
                        return;

                    ClearMineState(LAND_MINE_STATE_ACTIVATED);
                    AddMineState(LAND_MINE_STATE_DETONATED);
                    uiDespawnTimer = 1000;
                    me->CastSpell(target, SPELL_MYSTIC_TRAP, true);
                    me->RemoveAura(SPELL_TOLVIR_LAND_MINE_VISUAL);
                    me->RemoveAura(SPELL_TOLVIR_MINE_PLAYER_SEARCH_TRIGGER);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (HasMineState(LAND_MINE_STATE_JUSTADDED))
            {
                if (uiActivationTimer <= diff)
                {
                    ClearMineState(LAND_MINE_STATE_JUSTADDED);
                    AddMineState(LAND_MINE_STATE_ACTIVATED);
                    me->AddAura(SPELL_TOLVIR_LAND_MINE_VISUAL, me);
                    me->AddAura(SPELL_TOLVIR_MINE_PLAYER_SEARCH_TRIGGER, me);
                }
                else
                    uiActivationTimer -= diff;
            }

            if (HasMineState(LAND_MINE_STATE_ACTIVATED) && !HasMineState(LAND_MINE_STATE_COUNTDOWN))
            {
                if (uiCountdownTimer <= diff)
                    StartCountDown();
                else
                    uiCountdownTimer -= diff;
            }

            if (HasMineState(LAND_MINE_STATE_DETONATED))
            {
                if (uiDespawnTimer <= diff)
                {
                    if (Creature* pMineVehicle = me->GetVehicleCreatureBase())
                        pMineVehicle->DespawnOrUnsummon();

                    me->DespawnOrUnsummon();
                }
                else
                    uiDespawnTimer -= diff;
            }
        }
    };
};

class npc_shockwave_stalker : public CreatureScript
{
public:
    npc_shockwave_stalker() : CreatureScript("npc_shockwave_stalker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shockwave_stalkerAI (creature);
    }

    struct npc_shockwave_stalkerAI : public ScriptedAI
    {
        npc_shockwave_stalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            lSummonedGUID.clear();
            CanCheck = true;
            uiCheckTimer = 250;
            instance = creature->GetInstanceScript();

            if (me->IsSummon())
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                {
                    float x, y, _x, _y, z = me->GetPositionZ();
                    summoner->GetPosition(_x, _y);
                    pos.Relocate(_x, _y, z);
                    me->GetNearPoint2D(x, y, 40.0f, M_PI - me->GetAngle(_x, _y));
                    me->GetMotionMaster()->MovePoint(0, x, y, z);
                }
        }

        InstanceScript* instance;
        std::list<ObjectGuid> lSummonedGUID;
        Position pos;
        uint32 uiCheckTimer;
        bool CanCheck;

        void JustSummoned(Creature* summoned) override
        {
            summoned->SetReactState(REACT_PASSIVE);
            summoned->SetInCombatWithZone();
            summoned->AddAura(SPELL_SHOCKWAVE_STALKER_VISUAL, summoned);

            if (instance)
                if (Creature* husam = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GENERAL_HUSAM)))
                    husam->AI()->JustSummoned(summoned);

            lSummonedGUID.push_back(summoned->GetGUID());
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_SHOCKWAVE || spell->Id == 91257)
            {
                caster->CastSpell(me, SPELL_SHOCKWAVE_VISUAL, true);
                me->RemoveAllAuras();
                CanCheck = false;

                if (lSummonedGUID.empty())
                    return;

                for (std::list<ObjectGuid>::const_iterator itr = lSummonedGUID.begin(); itr != lSummonedGUID.end(); ++itr)
                    if (Creature* shockwave = ObjectAccessor::GetCreature(*me, (*itr)))
                    {
                        shockwave->CastSpell(shockwave, SPELL_SHOCKWAVE_DAMAGE, true);
                        shockwave->RemoveAllAuras();
                    }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (CanCheck)
            {
                if (uiCheckTimer <= diff)
                {
                    uiCheckTimer = 250;
                    float x, y;
                    me->GetPosition(x, y);

                    if (pos.GetExactDist2d(x, y) >= 4.0f)
                    {
                        float dist = me->GetDistance(pos);
                        float _x, _y, _z = me->GetPositionZ();
                        me->GetNearPoint2D(_x, _y, dist - 4.0f, me->GetAngle(&pos));
                        me->CastSpell(_x, _y, _z, SPELL_SUMMON_SHOCKWAVE, true);
                    }
                }
                else
                    uiCheckTimer -= diff;
            }
        }
    };
};

class npc_bad_intentios_target : public CreatureScript
{
public:
    npc_bad_intentios_target() : CreatureScript("npc_bad_intentios_target") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bad_intentios_targetAI (creature);
    }

    struct npc_bad_intentios_targetAI : public ScriptedAI
    {
        npc_bad_intentios_targetAI(Creature* creature) : ScriptedAI(creature){}

        uint32 uiExitTimer;
        bool Passenger;

        void Reset() override
        {
            uiExitTimer = 1000;
            Passenger = false;

            if (Vehicle* vehicle = me->GetVehicleKit())
                vehicle->RemoveAllPassengers();
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                me->CastSpell(who, SPELL_HARD_IMPACT, false);
                Passenger = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (Passenger)
            {
                if (uiExitTimer <= diff)
                    Reset();
                else
                    uiExitTimer -= diff;
            }
        }
    };
};

class spell_bad_intentions: public SpellScriptLoader
{
    public:
        spell_bad_intentions() : SpellScriptLoader("spell_bad_intentions") { }

        class spell_bad_intentions_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_bad_intentions_SpellScript);

            void HandleScript(SpellEffIndex /*effect*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!(caster && target))
                    return;

                target->CastSpell(caster, SPELL_RIDE_VEHICLE_HARDCODED, false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_bad_intentions_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_bad_intentions_SpellScript();
        }
};

class spell_hurl: public SpellScriptLoader
{
    public:
        spell_hurl() : SpellScriptLoader("spell_hurl") { }

        class spell_hurl_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hurl_SpellScript);

            void HandleScript(SpellEffIndex /*effect*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!(caster && target))
                    return;

                target->ExitVehicle();
                caster->CastSpell(caster, SPELL_THROW_VISUAL, false);
                target->CastSpell(target, SPELL_HURL_RIDE, false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hurl_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hurl_SpellScript();
        }
};

void AddSC_boss_general_husam()
{
    new boss_general_husam();
    new npc_land_mine();
    new npc_shockwave_stalker();
    new npc_bad_intentios_target();

    new spell_bad_intentions();
    new spell_hurl();
}

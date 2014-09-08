/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "Player.h"
#include "SpellInfo.h"
#include "naxxramas.h"

enum Yells
{
    EMOTE_AIR_PHASE         = 0,
    EMOTE_GROUND_PHASE      = 1,
    EMOTE_BREATH            = 2,
    EMOTE_ENRAGE            = 3
};

enum Spells
{
    SPELL_FROST_AURA        = 28531,
    SPELL_CLEAVE            = 19983,
    SPELL_TAIL_SWEEP        = 55697,
    SPELL_SUMMON_BLIZZARD   = 28560,
    SPELL_LIFE_DRAIN        = 28542,
    SPELL_ICEBOLT           = 28522,
    SPELL_FROST_BREATH      = 29318,
    SPELL_FROST_EXPLOSION   = 28524,
    SPELL_FROST_MISSILE     = 30101,
    SPELL_BERSERK           = 26662,
    SPELL_DIES              = 29357,
    SPELL_CHILL             = 28547,
};

enum Phases
{
    PHASE_NULL          = 0,
    PHASE_BIRTH,
    PHASE_GROUND,
    PHASE_FLIGHT
};

enum Events
{
    EVENT_BERSERK       = 1,
    EVENT_CLEAVE,
    EVENT_TAIL,
    EVENT_DRAIN,
    EVENT_BLIZZARD,
    EVENT_FLIGHT,
    EVENT_LIFTOFF,
    EVENT_ICEBOLT,
    EVENT_BREATH,
    EVENT_EXPLOSION,
    EVENT_LAND,
    EVENT_GROUND,
    EVENT_BIRTH
};

enum Misc
{
    NPC_BLIZZARD            = 16474,
    GO_ICEBLOCK             = 181247,

    // The Hundred Club
    DATA_THE_HUNDRED_CLUB   = 21462147,
    MAX_FROST_RESISTANCE    = 100
};

typedef std::map<uint64, uint64> IceBlockMap;

class boss_sapphiron : public CreatureScript
{
    public:
        boss_sapphiron() : CreatureScript("boss_sapphiron") { }

        struct boss_sapphironAI : public BossAI
        {
            boss_sapphironAI(Creature* creature) :
                BossAI(creature, BOSS_SAPPHIRON), _phase(PHASE_NULL),
                _map(me->GetMap())
            { }

            void InitializeAI() override
            {
                _canTheHundredClub = true;

                float x, y, z;
                me->GetPosition(x, y, z);
                me->SummonGameObject(GO_BIRTH, x, y, z, 0, 0, 0, 0, 0, 0);
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);

                BossAI::InitializeAI();
            }

            void Reset() override
            {
                _Reset();

                if (_phase == PHASE_FLIGHT)
                    ClearIceBlock();

                _phase = PHASE_NULL;

                _canTheHundredClub = true;
                _checkFrostResistTimer = 5 * IN_MILLISECONDS;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();

                me->CastSpell(me, SPELL_FROST_AURA, true);

                events.ScheduleEvent(EVENT_BERSERK, 15 * MINUTE * IN_MILLISECONDS);
                EnterPhaseGround();

                CheckPlayersFrostResist();
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_ICEBOLT)
                {
                    IceBlockMap::iterator itr = _iceblocks.find(target->GetGUID());
                    if (itr != _iceblocks.end() && !itr->second)
                    {
                        if (GameObject* iceblock = me->SummonGameObject(GO_ICEBLOCK, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, 0, 0, 0, 0, 25))
                            itr->second = iceblock->GetGUID();
                    }
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                me->CastSpell(me, SPELL_DIES, true);

                CheckPlayersFrostResist();
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id == 1)
                    events.ScheduleEvent(EVENT_LIFTOFF, 0);
            }

            void DoAction(int32 param) override
            {
                if (param == DATA_SAPPHIRON_BIRTH)
                {
                    _phase = PHASE_BIRTH;
                    events.ScheduleEvent(EVENT_BIRTH, 23 * IN_MILLISECONDS);
                }
            }

            void CheckPlayersFrostResist()
            {
                if (_canTheHundredClub && _map && _map->IsRaid())
                {
                    Map::PlayerList const &players = _map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (itr->GetSource()->GetResistance(SPELL_SCHOOL_FROST) > MAX_FROST_RESISTANCE)
                        {
                            _canTheHundredClub = false;
                            break;
                        }
                    }
                }
            }

            void EnterPhaseGround()
            {
                _phase = PHASE_GROUND;
                me->SetReactState(REACT_AGGRESSIVE);
                events.SetPhase(PHASE_GROUND);
                events.ScheduleEvent(EVENT_CLEAVE, urand(5, 15) * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_TAIL, urand(5, 15) * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_DRAIN, 24 * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_BLIZZARD, urand(5, 10) * IN_MILLISECONDS, 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_FLIGHT, 45 * IN_MILLISECONDS);
            }

            void ClearIceBlock()
            {
                for (IceBlockMap::const_iterator itr = _iceblocks.begin(); itr != _iceblocks.end(); ++itr)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, itr->first))
                        player->RemoveAura(SPELL_ICEBOLT);

                    if (GameObject* go = ObjectAccessor::GetGameObject(*me, itr->second))
                        go->Delete();
                }
                _iceblocks.clear();
            }

            uint32 GetData(uint32 data) const override
            {
                if (data == DATA_THE_HUNDRED_CLUB)
                    return _canTheHundredClub;

                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!_phase)
                    return;

                events.Update(diff);

                if ((_phase != PHASE_BIRTH && !UpdateVictim()) || !CheckInRoom())
                    return;

                if (_canTheHundredClub)
                {
                    if (_checkFrostResistTimer <= diff)
                    {
                        CheckPlayersFrostResist();
                        _checkFrostResistTimer = 5 * IN_MILLISECONDS;
                    }
                    else
                        _checkFrostResistTimer -= diff;
                 }

                if (_phase == PHASE_GROUND)
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_BERSERK:
                                Talk(EMOTE_ENRAGE);
                                DoCast(me, SPELL_BERSERK);
                                return;
                            case EVENT_CLEAVE:
                                DoCastVictim(SPELL_CLEAVE);
                                events.ScheduleEvent(EVENT_CLEAVE, urand(5, 15) * IN_MILLISECONDS, 0, PHASE_GROUND);
                                return;
                            case EVENT_TAIL:
                                DoCastAOE(SPELL_TAIL_SWEEP);
                                events.ScheduleEvent(EVENT_TAIL, urand(5, 15) * IN_MILLISECONDS, 0, PHASE_GROUND);
                                return;
                            case EVENT_DRAIN:
                                DoCastAOE(SPELL_LIFE_DRAIN);
                                events.ScheduleEvent(EVENT_DRAIN, 24 * IN_MILLISECONDS, 0, PHASE_GROUND);
                                return;
                            case EVENT_BLIZZARD:
                            {
                                //DoCastAOE(SPELL_SUMMON_BLIZZARD);
                                if (Creature* summon = DoSummon(NPC_BLIZZARD, me, 0.0f, urand(25, 30) * IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                    summon->GetMotionMaster()->MoveRandom(40);
                                events.ScheduleEvent(EVENT_BLIZZARD, RAID_MODE(20, 7) * IN_MILLISECONDS, 0, PHASE_GROUND);
                                break;
                            }
                            case EVENT_FLIGHT:
                                if (HealthAbovePct(10))
                                {
                                    _phase = PHASE_FLIGHT;
                                    events.SetPhase(PHASE_FLIGHT);
                                    me->SetReactState(REACT_PASSIVE);
                                    me->AttackStop();
                                    float x, y, z, o;
                                    me->GetHomePosition(x, y, z, o);
                                    me->GetMotionMaster()->MovePoint(1, x, y, z);
                                    return;
                                }
                                break;
                        }
                    }

                    DoMeleeAttackIfReady();
                }
                else
                {
                    if (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_LIFTOFF:
                                Talk(EMOTE_AIR_PHASE);
                                me->SetDisableGravity(true);
                                events.ScheduleEvent(EVENT_ICEBOLT, 1500);
                                _iceboltCount = RAID_MODE(2, 3);
                                return;
                            case EVENT_ICEBOLT:
                            {
                                std::vector<Unit*> targets;
                                std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                                for (; i != me->getThreatManager().getThreatList().end(); ++i)
                                    if ((*i)->getTarget()->GetTypeId() == TYPEID_PLAYER && !(*i)->getTarget()->HasAura(SPELL_ICEBOLT))
                                        targets.push_back((*i)->getTarget());

                                if (targets.empty())
                                    _iceboltCount = 0;
                                else
                                {
                                    std::vector<Unit*>::const_iterator itr = targets.begin();
                                    advance(itr, rand32() % targets.size());
                                    _iceblocks.insert(std::make_pair((*itr)->GetGUID(), 0));
                                    DoCast(*itr, SPELL_ICEBOLT);
                                    --_iceboltCount;
                                }

                                if (_iceboltCount)
                                    events.ScheduleEvent(EVENT_ICEBOLT, 1 * IN_MILLISECONDS);
                                else
                                    events.ScheduleEvent(EVENT_BREATH, 1 * IN_MILLISECONDS);
                                return;
                            }
                            case EVENT_BREATH:
                            {
                                Talk(EMOTE_BREATH);
                                DoCastAOE(SPELL_FROST_MISSILE);
                                events.ScheduleEvent(EVENT_EXPLOSION, 8 * IN_MILLISECONDS);
                                return;
                            }
                            case EVENT_EXPLOSION:
                                CastExplosion();
                                ClearIceBlock();
                                events.ScheduleEvent(EVENT_LAND, 3 * IN_MILLISECONDS);
                                return;
                            case EVENT_LAND:
                                me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                                Talk(EMOTE_GROUND_PHASE);
                                me->SetDisableGravity(false);
                                events.ScheduleEvent(EVENT_GROUND, 1500);
                                return;
                            case EVENT_GROUND:
                                EnterPhaseGround();
                                return;
                            case EVENT_BIRTH:
                                me->SetVisible(true);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                me->SetReactState(REACT_AGGRESSIVE);
                                return;
                        }
                    }
                }
            }

            void CastExplosion()
            {
                DoZoneInCombat(); // make sure everyone is in threatlist
                std::vector<Unit*> targets;
                std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                for (; i != me->getThreatManager().getThreatList().end(); ++i)
                {
                    Unit* target = (*i)->getTarget();
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;

                    if (target->HasAura(SPELL_ICEBOLT))
                    {
                        target->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FROST_EXPLOSION, true);
                        targets.push_back(target);
                        continue;
                    }

                    for (IceBlockMap::const_iterator itr = _iceblocks.begin(); itr != _iceblocks.end(); ++itr)
                    {
                        if (GameObject* go = ObjectAccessor::GetGameObject(*me, itr->second))
                        {
                            if (go->IsInBetween(me, target, 2.0f)
                                && me->GetExactDist2d(target->GetPositionX(), target->GetPositionY()) - me->GetExactDist2d(go->GetPositionX(), go->GetPositionY()) < 5.0f)
                            {
                                target->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FROST_EXPLOSION, true);
                                targets.push_back(target);
                                break;
                            }
                        }
                    }
                }

                me->CastSpell(me, SPELL_FROST_EXPLOSION, true);

                for (std::vector<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    (*itr)->ApplySpellImmune(0, IMMUNITY_ID, SPELL_FROST_EXPLOSION, false);
            }

        private:
            Phases _phase;
            uint32 _iceboltCount;
            IceBlockMap _iceblocks;
            bool _canTheHundredClub;
            uint32 _checkFrostResistTimer;
            Map* _map;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_sapphironAI(creature);
        }
};

class achievement_the_hundred_club : public AchievementCriteriaScript
{
    public:
        achievement_the_hundred_club() : AchievementCriteriaScript("achievement_the_hundred_club") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_THE_HUNDRED_CLUB);
        }
};

void AddSC_boss_sapphiron()
{
    new boss_sapphiron();
    new achievement_the_hundred_club();
}

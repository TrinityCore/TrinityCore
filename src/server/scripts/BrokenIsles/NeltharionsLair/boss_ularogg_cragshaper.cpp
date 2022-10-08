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

#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "neltharions_lair.h"
#include "CreatureTextMgr.h"
#include "Log.h"
#include "Spell.h"
#include "GameObject.h"

class at_mountain_strike : public AreaTriggerEntityScript
{
public:
    at_mountain_strike() : AreaTriggerEntityScript("at_mountain_strike") { }

    struct at_mountain_strikeAI : AreaTriggerAI
    {
        at_mountain_strikeAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit && unit->ToPlayer())
                playerGuid = unit->GetGUID();
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit && unit->ToPlayer())
                playerGuid = ObjectGuid::Empty;
        }

        void OnUpdate(uint32 /*diff*/) override
        {
            if (!playerGuid.Empty)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*at, playerGuid))
                {
                    if (at->GetDuration() <= 1000)
                    {
                        player->CastSpell(player, 198475, false);
                        playerGuid = ObjectGuid::Empty;
                    }
                }
            }
        }

    private:
        ObjectGuid playerGuid;
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mountain_strikeAI(areatrigger);
    }
};

// 216292 , 210164 (Naraxas toxic retch too) , 200722, 200338 (Dargrul lanslide and Crystal spike too)
class spell_mountain_strike_dest : public SpellScriptLoader
{
public:
    spell_mountain_strike_dest() : SpellScriptLoader("spell_mountain_strike_dest") { }

    class spell_mountain_strike_dest_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mountain_strike_dest_SpellScript);

        void ModDestHeight(SpellDestination& dest)
        {
            if (Unit* caster = GetCaster())
            {
                if (InstanceScript* instance = caster->GetInstanceScript())
                {
                    Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                    std::list<Player*> validPlayers;
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* _player = i->GetSource();
                            if (_player && _player->IsAlive() && caster->IsWithinDistInMap(_player, 85.0f))
                                    validPlayers.push_back(_player);
                        }
                    }

                    if (validPlayers.size() == 0)
                        return;

                    uint8 selectPlr = urand(1, validPlayers.size());
                    uint8 i = 0;
                    for (auto validPlr : validPlayers)
                    {
                        ++i;
                        if (i == selectPlr)
                        {
                            Position pos = validPlr->GetPosition();
                            dest.Relocate(pos);
                            break;
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_mountain_strike_dest_SpellScript::ModDestHeight, EFFECT_0, TARGET_DEST_DEST_RANDOM);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mountain_strike_dest_SpellScript();
    }
};

class boss_ularogg_cragshaper : public CreatureScript
{
public:
    boss_ularogg_cragshaper() : CreatureScript("boss_ularogg_cragshaper") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ularogg_cragshaper_AI(creature);
    }

    enum eTexts
    {
        TALK_AGGRO                        = 0,
        TALK_STRIKE_OF_THE_MOUNTAIN       = 1,
        TALK_STRIKE_OF_THE_MOUNTAIN_2     = 2,
        TALK_MOUNTAIN_STANCE              = 3,
        TALK_DEATH                        = 4,
        TALK_MOUNTAIN_STANCE_PHRASE       = 5,
        TALK_KILL                         = 6,
    };

    enum eEvents
    {
        EVENT_MANAREGEN_TICK              = 1,
        EVENT_BELLOW_OF_THE_DEEPS         = 2,
        EVENT_STRIKE_OF_THE_MOUNTAIN      = 3,
        EVENT_SUNDER                      = 4,
        EVENT_PHASE_2                     = 5,
        EVENT_START_ATTACK                = 6,
        EVENT_PHASE_2_INVISIBLE           = 7,
        EVENT_IDOLS_MOTION                = 8
    };

    enum eSpells
    {
        SPELL_BELLOW_OF_THE_DEEPS         = 193375,
        SPELL_STRIKE_OF_THE_MOUNTAIN      = 216290,
        SPELL_SUNDER                      = 198496,
        SPELL_STANCE_OF_THE_MOUNTAIN      = 198565
    };

    struct boss_ularogg_cragshaper_AI : public BossAI
    {
        boss_ularogg_cragshaper_AI(Creature* creature) : BossAI(creature, DATA_ULAROGG_CRAGSHAPER) 
        { 
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        }

        EventMap events;
        InstanceScript* instance;
        bool manaRegenerated = false;
        bool inSecondPhase = false;
        bool isJumpedToCenter = false;
        bool allowUpdateVictim = false;
        uint8 idolsPoint = 0;
        std::list<Position> idolsPositions;

        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
            me->SetPower(POWER_MANA, 0);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!isJumpedToCenter && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && me->IsWithinDistInMap(who, 35.0f))
            {
                me->GetMotionMaster()->MoveJump(ularoggJumpPos, 15.0f, 15.0f, EVENT_JUMP, true);
                if (me->GetPositionX() < 2858)
                {
                    isJumpedToCenter = true;
                    events.ScheduleEvent(EVENT_START_ATTACK, 5 * IN_MILLISECONDS);
                }
            }
        }

        void Reset() override
        {
            _Reset();
            events.Reset();
            me->SetPower(POWER_MANA, 0);

            manaRegenerated = false;
            inSecondPhase = false;
            isJumpedToCenter = false;
            allowUpdateVictim = false;
            idolsPoint = 0;
            me->SetVisible(true);

            if (instance)
            {
                instance->SetData(DATA_ULAROGG_CRAGSHAPER, NOT_STARTED);
                instance->SetData(DATA_CENTER_IDOL_KILLED, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(TALK_AGGRO);
            me->SetInCombatWithZone();
            me->SetPower(POWER_MANA, 0);

            events.ScheduleEvent(EVENT_MANAREGEN_TICK, 1s);
            events.ScheduleEvent(EVENT_BELLOW_OF_THE_DEEPS, 4s, 6s);
            events.ScheduleEvent(EVENT_SUNDER, 2s);
            events.ScheduleEvent(EVENT_STRIKE_OF_THE_MOUNTAIN, 10s);

            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetData(DATA_ULAROGG_CRAGSHAPER, IN_PROGRESS);
            }
        }

        void JustDied(Unit* /*unit*/) override
        {
            Talk(TALK_DEATH);

            if (GameObject* barrier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_BARRIER_ULAROGG)))
                barrier->SetGoState(GO_STATE_ACTIVE);

            instance->SetData(DATA_ULAROGG_CRAGSHAPER, DONE);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(TALK_KILL);
        }

        void EnterEvadeMode(EvadeReason) override
        {
            me->SetPower(POWER_MANA, 0);
            manaRegenerated = false;
            inSecondPhase = false;
            allowUpdateVictim = false;
            BossAI::EnterEvadeMode();
            if (instance)
            {
                instance->SetData(DATA_ULAROGG_CRAGSHAPER, FAIL);
                instance->SetData(DATA_CENTER_IDOL_KILLED, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
            isJumpedToCenter = false;
            me->SetVisible(true);
        }

        int32 round(float v)
        { 
            return floor(v + 0.5f); 
        }

        void FillIdolsPositions(Creature* leftIdol, Creature* centerIdol, Creature* rightIdol, Creature* backIdol, Creature* frontIdol)
        {
            idolsPositions.clear();
            for (uint8 i = 0; i < 18; ++i)
            {
                if (round(leftIdol->GetPositionX()) == round(ularoggIdolsPositions[i][0]) &&
                    round(leftIdol->GetPositionY()) == round(ularoggIdolsPositions[i][1]) &&
                    round(leftIdol->GetPositionZ()) == round(ularoggIdolsPositions[i][2]))
                    continue;

                if (round(centerIdol->GetPositionX()) == round(ularoggIdolsPositions[i][0]) &&
                    round(centerIdol->GetPositionY()) == round(ularoggIdolsPositions[i][1]) &&
                    round(centerIdol->GetPositionZ()) == round(ularoggIdolsPositions[i][2]))
                    continue;

                if (round(rightIdol->GetPositionX()) == round(ularoggIdolsPositions[i][0]) &&
                    round(rightIdol->GetPositionY()) == round(ularoggIdolsPositions[i][1]) &&
                    round(rightIdol->GetPositionZ()) == round(ularoggIdolsPositions[i][2]))
                    continue;

                if (instance && instance->instance->GetDifficultyID() >= 2 && backIdol && frontIdol)
                {
                    if (round(backIdol->GetPositionX()) == round(ularoggIdolsPositions[i][0]) &&
                        round(backIdol->GetPositionY()) == round(ularoggIdolsPositions[i][1]) &&
                        round(backIdol->GetPositionZ()) == round(ularoggIdolsPositions[i][2]))
                        continue;

                    if (round(frontIdol->GetPositionX()) == round(ularoggIdolsPositions[i][0]) &&
                        round(frontIdol->GetPositionY()) == round(ularoggIdolsPositions[i][1]) &&
                        round(frontIdol->GetPositionZ()) == round(ularoggIdolsPositions[i][2]))
                        continue;
                }

                idolsPositions.push_back(Position(ularoggIdolsPositions[i][0], ularoggIdolsPositions[i][1], ularoggIdolsPositions[i][2], 0.0f));
            }
        }

        Position SelectRandomIdolPos(uint8 randomIndex)
        {
            uint8 i = 0;
            for (auto idolsPoss : idolsPositions)
            {
                if (i == randomIndex)
                    return idolsPoss;
                ++i;
            }
            return Position(0.0f, 0.0f, 0.0f, 0.0f);
        }

        void UpdateAI(uint32 diff) override
        {
            if (instance && instance->GetData(DATA_CENTER_IDOL_KILLED) == DONE && inSecondPhase)
            {
                me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionX(), me->GetOrientation(), 55.0f, 55.0f, EVENT_JUMP, true);
                me->SetVisible(true);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAllAuras();
                allowUpdateVictim = true;
                inSecondPhase = false;
                manaRegenerated = false;
                me->SetPower(POWER_MANA, 0);
                events.ScheduleEvent(EVENT_MANAREGEN_TICK, 1s);
                events.ScheduleEvent(EVENT_BELLOW_OF_THE_DEEPS, 4s, 6s);
                events.ScheduleEvent(EVENT_SUNDER, 2s);
                events.ScheduleEvent(EVENT_STRIKE_OF_THE_MOUNTAIN, 10s);
            }

            if (!UpdateVictim() && allowUpdateVictim)
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_MANAREGEN_TICK:
                    if (!manaRegenerated && !inSecondPhase && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA))
                    {
                        if (instance)
                        {
                            float manaRegenMod = 2.857f;
                            if (instance->instance->GetDifficultyID() == DIFFICULTY_MYTHIC)
                                manaRegenMod = 4;

                            me->SetPower(POWER_MANA, me->GetPower(POWER_MANA)+(me->GetMaxPower(POWER_MANA)*manaRegenMod/100));

                            if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                            {
                                manaRegenerated = true;
                                events.ScheduleEvent(EVENT_PHASE_2, 3s);
                                me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                                me->SetReactState(REACT_PASSIVE);
                                me->RemoveAllAuras();
                                me->RemoveAllAttackers();
                                allowUpdateVictim = false;
                                me->AttackStop();
                                me->GetMotionMaster()->MoveJump(ularoggJumpPos, 15.0f, 15.0f, EVENT_JUMP, true);
                            }
                            else
                                events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2s);
                        }
                    }
                    break;
                case EVENT_SUNDER:
                    if (!inSecondPhase)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_SUNDER, false);
                        events.ScheduleEvent(EVENT_SUNDER, 6s, 10s);
                    }
                    break;
                case EVENT_BELLOW_OF_THE_DEEPS:
                    if (!inSecondPhase)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_BELLOW_OF_THE_DEEPS, false);
                        events.ScheduleEvent(EVENT_BELLOW_OF_THE_DEEPS, 6s, 10s);
                    }
                    break;
                case EVENT_STRIKE_OF_THE_MOUNTAIN:
                    if (!inSecondPhase)
                    {
                        uint8 randomTalk = urand(TALK_STRIKE_OF_THE_MOUNTAIN, TALK_STRIKE_OF_THE_MOUNTAIN_2);
                        Talk(randomTalk);
                        me->CastSpell(me->GetVictim(), SPELL_STRIKE_OF_THE_MOUNTAIN, false);
                        events.ScheduleEvent(EVENT_STRIKE_OF_THE_MOUNTAIN, 12s, 15s);
                    }
                    break;
                case EVENT_PHASE_2:
                    if (!inSecondPhase)
                    {
                        Talk(TALK_MOUNTAIN_STANCE);
                        Talk(TALK_MOUNTAIN_STANCE_PHRASE);
                        instance->SetData(DATA_CENTER_IDOL_KILLED, NOT_STARTED);
                        me->CastSpell(me, SPELL_STANCE_OF_THE_MOUNTAIN, false);
                        events.ScheduleEvent(EVENT_PHASE_2_INVISIBLE, 700);
                        inSecondPhase = true;
                    }
                    break;
                case EVENT_START_ATTACK:
                    if (!inSecondPhase)
                    {
                        me->SetReactState(REACT_DEFENSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        allowUpdateVictim = true;
                    }
                    break;
                case EVENT_PHASE_2_INVISIBLE:
                    if (!ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CENTER_IDOL)))
                    {
                        TC_LOG_ERROR("misc", "!centerIdol");
                        instance->SetData(DATA_CENTER_IDOL_KILLED, NOT_STARTED);
                        me->CastSpell(me, SPELL_STANCE_OF_THE_MOUNTAIN, false);
                        events.ScheduleEvent(EVENT_PHASE_2_INVISIBLE, 500);
                    }
                    else
                    {
                        me->SetVisible(false);
                        events.ScheduleEvent(EVENT_IDOLS_MOTION, 3s);
                    }
                    break;
                case EVENT_IDOLS_MOTION:
                    Creature* centerIdol = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CENTER_IDOL));
                    Creature* leftIdol = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LEFT_IDOL));
                    Creature* rightIdol = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RIGHT_IDOL));
                    Creature* backIdol = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BACK_IDOL));
                    Creature* frontIdol = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FRONT_IDOL));

                    if (centerIdol && leftIdol && rightIdol)
                    {
                        FillIdolsPositions(leftIdol, centerIdol, rightIdol, backIdol, frontIdol);
                        Position leftIdolPos = SelectRandomIdolPos(urand(0, idolsPositions.size()-1));

                        FillIdolsPositions(leftIdol, centerIdol, rightIdol, backIdol, frontIdol);
                        for (std::list<Position>::iterator idPoss = idolsPositions.begin(); idPoss != idolsPositions.end(); ++idPoss)
                            if (*idPoss == leftIdolPos)
                                idPoss = idolsPositions.erase(idPoss);

                        Position centerIdolPos = SelectRandomIdolPos(urand(0, idolsPositions.size()-1));

                        FillIdolsPositions(leftIdol, centerIdol, rightIdol, backIdol, frontIdol);
                        for (std::list<Position>::iterator idPoss = idolsPositions.begin(); idPoss != idolsPositions.end(); ++idPoss)
                        {
                            if (*idPoss == leftIdolPos)
                                idPoss = idolsPositions.erase(idPoss);

                            if (*idPoss == centerIdolPos)
                                idPoss = idolsPositions.erase(idPoss);
                        }

                        Position rightIdolPos = SelectRandomIdolPos(urand(0, idolsPositions.size()-1));

                        if (instance && instance->instance->GetDifficultyID() >= 2 && backIdol && frontIdol)
                        {
                            FillIdolsPositions(leftIdol, centerIdol, rightIdol, backIdol, frontIdol);
                            for (std::list<Position>::iterator idPoss = idolsPositions.begin(); idPoss != idolsPositions.end(); ++idPoss)
                            {
                                if (*idPoss == leftIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);

                                if (*idPoss == centerIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);

                                if (*idPoss == rightIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);
                            }

                            Position backIdolPos = SelectRandomIdolPos(urand(0, idolsPositions.size()-1));

                            FillIdolsPositions(leftIdol, centerIdol, rightIdol, backIdol, frontIdol);
                            for (std::list<Position>::iterator idPoss = idolsPositions.begin(); idPoss != idolsPositions.end(); ++idPoss)
                            {
                                if (*idPoss == leftIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);

                                if (*idPoss == centerIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);

                                if (*idPoss == rightIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);

                                if (*idPoss == backIdolPos)
                                    idPoss = idolsPositions.erase(idPoss);
                            }

                            Position frontIdolPos = SelectRandomIdolPos(urand(0, idolsPositions.size()-1));
                            frontIdol->GetMotionMaster()->MovePoint(idolsPoint, frontIdolPos);
                            backIdol->GetMotionMaster()->MovePoint(idolsPoint, backIdolPos);
                        }
                        leftIdol->GetMotionMaster()->MovePoint(idolsPoint, leftIdolPos);
                        centerIdol->GetMotionMaster()->MovePoint(idolsPoint, centerIdolPos);
                        rightIdol->GetMotionMaster()->MovePoint(idolsPoint, rightIdolPos);
                    }
                    ++idolsPoint;

                    if (idolsPoint <= 8)
                        events.ScheduleEvent(EVENT_IDOLS_MOTION, 500);
                    else
                    {
                        std::list<Creature*> idolsList;
                        idolsList.push_back(centerIdol);
                        idolsList.push_back(leftIdol);
                        idolsList.push_back(rightIdol);
                        idolsList.push_back(backIdol);
                        idolsList.push_back(frontIdol);
                        for (auto Idol : idolsList)
                        {
                            if (Idol)
                            {
                                Idol->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                                Idol->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                                Idol->AddAura(193267, Idol);
                            }
                        }
                        idolsPoint = 0;
                    }
                    break;
            }
            
            DoMeleeAttackIfReady();
        }
    }; 
};

// 100818
class mob_bellowing_idol_mountain_stance : public CreatureScript
{
public:
    mob_bellowing_idol_mountain_stance() : CreatureScript("mob_bellowing_idol_mountain_stance") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_bellowing_idol_mountain_stance_AI(creature);
    }

    enum eSpells
    {
        SPELL_FALLING_DERBIS = 193271,
        SPELL_DERBIS_AURA    = 193267,
    };

    struct mob_bellowing_idol_mountain_stance_AI : public ScriptedAI
    {
        InstanceScript* instance;

        mob_bellowing_idol_mountain_stance_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            float allSpeed = 3.0f;
            me->SetSpeedRate(MOVE_WALK, allSpeed);
            me->SetSpeedRate(MOVE_RUN, allSpeed);
            me->SetSpeedRate(MOVE_SWIM, allSpeed);
            me->SetSpeedRate(MOVE_FLIGHT, allSpeed);
            instance = me->GetInstanceScript();
        }

        void JustDied(Unit* /*unit*/) override
        {
            if (instance)
                if (me->GetGUID() == instance->GetGuidData(DATA_CENTER_IDOL))
                    instance->SetData(DATA_CENTER_IDOL_KILLED, DONE);
        }

        uint32 derbisTime = 3000;
        void UpdateAI(uint32 diff) override
        {
            if (instance && instance->GetData(DATA_CENTER_IDOL_KILLED) == DONE)
                me->DespawnOrUnsummon();

            if (me->HasAura(SPELL_DERBIS_AURA))
            {
                if (derbisTime <= diff)
                {
                    if (InstanceScript* instance = me->GetInstanceScript())
                    {
                        Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                        std::list<Player*> validPlayers;
                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                Player* _player = i->GetSource();
                                if (_player && _player->IsAlive() && me->IsWithinDistInMap(_player, 85.0f))
                                        validPlayers.push_back(_player);
                            }
                        }

                        if (validPlayers.size() == 0)
                            return;

                        uint8 selectPlr = urand(1, validPlayers.size());
                        uint8 i = 0;
                        for (auto validPlr : validPlayers)
                        {
                            ++i;
                            if (i == selectPlr)
                            {
                                me->CastSpell(validPlr, SPELL_FALLING_DERBIS, false);
                                break;
                            }
                        }
                    }
                    derbisTime = 3000;
                }
                else
                    derbisTime -= diff;
            }
        }
    };
};

// 98081
class mob_bellowing_idol : public CreatureScript
{
public:
    mob_bellowing_idol() : CreatureScript("mob_bellowing_idol") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_bellowing_idol_AI(creature);
    }

    enum eSpells
    {
        SPELL_FALLING_DERBIS = 193271,
        SPELL_DERBIS_AURA    = 193267,
    };

    struct mob_bellowing_idol_AI : public ScriptedAI
    {
        mob_bellowing_idol_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddAura(SPELL_DERBIS_AURA, me);
        }

        uint32 derbisTime = 3000;

        void UpdateAI(uint32 diff) override
        {
            if (derbisTime <= diff)
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                    std::list<Player*> validPlayers;
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* _player = i->GetSource();
                            if (_player && _player->IsAlive() && me->IsWithinDistInMap(_player, 85.0f))
                                    validPlayers.push_back(_player);
                        }
                    }

                    if (validPlayers.size() == 0)
                        return;

                    uint8 selectPlr = urand(1, validPlayers.size());
                    uint8 i = 0;
                    for (auto validPlr : validPlayers)
                    {
                        ++i;
                        if (i == selectPlr)
                        {
                            me->CastSpell(validPlr, SPELL_FALLING_DERBIS, false);
                            break;
                        }
                    }
                }
                derbisTime = 3000;
            }
            else
                derbisTime -= diff;
        }
    };
};

// 198565
class spell_ularogg_mountain_stance : public SpellScriptLoader
{
public:
    spell_ularogg_mountain_stance() : SpellScriptLoader("spell_ularogg_mountain_stance") { }

    class spell_ularogg_mountain_stance_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ularogg_mountain_stance_SpellScript);

        void SpawnOtherIdols()
        {
            if (Unit* caster = GetCaster())
            {
                if (InstanceScript* instance = caster->GetInstanceScript())
                {
                    caster->SummonCreature(100818, ularoggRightIdolStartPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, -1);
                    caster->SummonCreature(100818, ularoggLeftIdolStartPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, -1);
                    if (instance->instance->GetDifficultyID() >= 2)
                    {
                        caster->SummonCreature(100818, ularoggBackIdolStartPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, -1);
                        caster->SummonCreature(100818, ularoggFrontIdolStartPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, -1);
                    }
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_ularogg_mountain_stance_SpellScript::SpawnOtherIdols);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ularogg_mountain_stance_SpellScript();
    }
};

// 193270
class spell_idol_falling_debris : public SpellScriptLoader
{
public:
    spell_idol_falling_debris() : SpellScriptLoader("spell_idol_falling_debris") { }

    class spell_idol_falling_debris_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_idol_falling_debris_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, 193271, false);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_idol_falling_debris_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_idol_falling_debris_SpellScript();
    }
};

// 216290
class spell_mountain_strike_trigger : public SpellScriptLoader
{
public:
    spell_mountain_strike_trigger() : SpellScriptLoader("spell_mountain_strike_trigger") { }

    class spell_mountain_strike_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mountain_strike_trigger_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, 216292, false);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_mountain_strike_trigger_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mountain_strike_trigger_SpellScript();
    }
};

void AddSC_boss_ularogg_cragshaper()
{
    new boss_ularogg_cragshaper();
    new mob_bellowing_idol();
    new mob_bellowing_idol_mountain_stance();
    new spell_ularogg_mountain_stance();
    new spell_idol_falling_debris();
    new at_mountain_strike();
    new spell_mountain_strike_trigger();
    new spell_mountain_strike_dest();
}

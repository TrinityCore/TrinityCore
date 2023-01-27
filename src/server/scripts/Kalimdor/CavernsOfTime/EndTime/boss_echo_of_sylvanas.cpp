/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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

/* ScriptData
SDName: boss_echo_of_sylvanas
SD%Complete:
SDComment:
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "end_time.h"
#include "SpellInfo.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"

#define SAY_AGGRO       "Another band of Deathwing's converts? I'll be sure your death is especially painful."
#define SOU_AGGRO       25966
#define SAY_IMMUNITY    "Watch, heathens, as death surrounds you!"
#define SOU_IMMUNITY    25970
#define SAY_DEATH       "This... isn't how it's supposed to... end!"
#define SOU_DEATH       25967

enum Spells
{
    SPELL_SUMMON_GHOUL_N            = 100894,
    SPELL_SUMMON_GHOUL_NE           = 100917,
    SPELL_SUMMON_GHOUL_NW           = 100918,
    SPELL_SUMMON_GHOUL_E            = 100919,
    SPELL_SUMMON_GHOUL_W            = 100920,
    SPELL_SUMMON_GHOUL_S            = 100921,
    SPELL_SUMMON_GHOUL_SE           = 100923,
    SPELL_SUMMON_GHOUL_SW           = 100924,
    SPELL_SUMMON_GHOUL              = 101200,
    SPELL_WRACKING_PAIN_LINK        = 100862,
    SPELL_WRACKING_PAIN_DMG         = 101221,
    SPELL_TELEPORT                  = 101398,
    SPELL_DEATH_GRIP                = 101397,
    SPELL_GHOUL_CIRCLE              = 100867,
    SPELL_CALLING_IMMUNITY          = 100686,
    SPELL_CALLING_SHADOWS           = 105766,
    SPELL_JUMP                      = 101528,
    SPELL_SACRIFICE                 = 101348,
    SPELL_SHRIEK_HIGHBORNE          = 101412,
    SPELL_BLACK_ARROW               = 101404,
    SPELL_UNHOLY_SHOT               = 101411,
    SPELL_BLIGHTED_ARROWS_VISUAL    = 101552,
    SPELL_BLIGHTED_ARROWS_EXPLOSION = 100763
};

enum Events
{
    // SYLVANAS EVENTS
    EVENT_TELEPORT = 1,
    EVENT_DEATH_GRIP,
    EVENT_SACRIFICE,
    EVENT_SHRIEK_HIGHBORNE,
    EVENT_BLACK_ARROW,
    EVENT_UNHOLY_SHOT,
    EVENT_BLIGHTED_ARROW,
    EVENT_BLIGHTED_JUMP,

    // ADD EVENTS
    EVENT_WRACKING_PAIN_LINK,
    EVENT_SUMMON_GHOUL,
    EVENT_CALLING_SHADOWS,
    EVENT_MOVE,
    EVENT_FOLLOW,
    EVENT_BEHIND,
    EVENT_EXPLODE,
    EVENT_DESPAWN
};

enum Misc
{
    NPC_GHOUL_SUMMONER              = 54197,
    NPC_RISEN_GHOUL                 = 54191
};

const float TelePoint [4] =
{
    3845.41f, 911.09f, 56.0422f, 0.4015f
};

class boss_echo_of_sylvanas : public CreatureScript
{
    public:
        boss_echo_of_sylvanas() : CreatureScript("boss_echo_of_sylvanas") { }

        struct boss_echo_of_sylvanasAI : public BossAI
        {
            boss_echo_of_sylvanasAI(Creature* creature) : BossAI(creature, DATA_SYLVANAS), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;

            void Reset() override
            {
                _Reset();
                me->SetReactState(REACT_DEFENSIVE);
            }

            void InitializeAI() override
            {
                me->SetReactState(REACT_DEFENSIVE);
                JustReachedHome();
            }

            void JustReachedHome() override
            {
                _JustReachedHome();
                DoCast(me, SPELL_CALLING_IMMUNITY);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                me->setActive(true);
                DoZoneInCombat();

                events.Reset();
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);

                me->RemoveAurasDueToSpell(SPELL_CALLING_IMMUNITY);
                events.ScheduleEvent(EVENT_SHRIEK_HIGHBORNE, urand(6000,10000));
                events.ScheduleEvent(EVENT_BLACK_ARROW, urand(2000,6000));
                events.ScheduleEvent(EVENT_UNHOLY_SHOT, urand(2000,6000));
                events.ScheduleEvent(EVENT_TELEPORT, 40000);
                //events.ScheduleEvent(EVENT_BLIGHTED_JUMP, 12000);

                me->SetReactState(REACT_AGGRESSIVE);
                me->Yell(SAY_AGGRO, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                me->Yell(SAY_DEATH, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_DEATH);
                instance->SetData(DATA_BOSS_COUNT, 1);
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TELEPORT:
                            // She teleport herself and she stops the melee attacks
                            events.Reset();
                            DoStopAttack();
                            me->Relocate(TelePoint[0], TelePoint[1], TelePoint[2], 0.0f);

                            me->SetReactState(REACT_PASSIVE);

                            DoCast(me, SPELL_TELEPORT);
                            DoCast(me, SPELL_CALLING_IMMUNITY);

                            events.ScheduleEvent(EVENT_DEATH_GRIP, 2000);
                            me->Yell(SAY_IMMUNITY, LANG_UNIVERSAL);
                            DoPlaySoundToSet(me, SOU_IMMUNITY);
                            break;
                        case EVENT_DEATH_GRIP:
                            // She summons ghoul summoners
                            DoCast(me, SPELL_SUMMON_GHOUL_N);
                            DoCast(me, SPELL_SUMMON_GHOUL_NE);
                            DoCast(me, SPELL_SUMMON_GHOUL_E);
                            DoCast(me, SPELL_SUMMON_GHOUL_SE);
                            DoCast(me, SPELL_SUMMON_GHOUL_S);
                            DoCast(me, SPELL_SUMMON_GHOUL_SW);
                            DoCast(me, SPELL_SUMMON_GHOUL_W);
                            DoCast(me, SPELL_SUMMON_GHOUL_NW);

                            // She grips all players to her position
                            DoCastAOE(SPELL_DEATH_GRIP);

                            events.ScheduleEvent(EVENT_SACRIFICE, 33000);
                            break;
                        case EVENT_SACRIFICE:
                            // all ghouls reach her position in about 20 secs
                            // then she casts Sacrifice and star newly melee attacks
                            DoCastAOE(SPELL_SACRIFICE);
                            Summons.DespawnAll();
                            me->SetReactState(REACT_AGGRESSIVE);

                            me->RemoveAurasDueToSpell(SPELL_CALLING_IMMUNITY);

                            events.ScheduleEvent(EVENT_SHRIEK_HIGHBORNE, urand(6000,10000));
                            events.ScheduleEvent(EVENT_BLACK_ARROW, urand(2000,6000));
                            events.ScheduleEvent(EVENT_UNHOLY_SHOT, urand(2000,6000));
                            events.ScheduleEvent(EVENT_TELEPORT, 40000);
                            break;
                        case EVENT_SHRIEK_HIGHBORNE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_SHRIEK_HIGHBORNE);
                            break;
                        case EVENT_BLACK_ARROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_BLACK_ARROW);
                            events.CancelEvent(EVENT_UNHOLY_SHOT);
                            events.CancelEvent(EVENT_BLIGHTED_ARROW);
                            events.ScheduleEvent(EVENT_BLIGHTED_ARROW, urand(10000,15000));
                            events.ScheduleEvent(EVENT_UNHOLY_SHOT, urand(10000,15000));
                            break;
                        case EVENT_UNHOLY_SHOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_UNHOLY_SHOT);
                            events.CancelEvent(EVENT_BLACK_ARROW);
                            events.CancelEvent(EVENT_BLIGHTED_ARROW);
                            events.ScheduleEvent(EVENT_BLIGHTED_ARROW, urand(10000,15000));
                            events.ScheduleEvent(EVENT_BLACK_ARROW, urand(10000,15000));
                            break;
                        /*case EVENT_BLIGHTED_JUMP:
                            me->CastSpell(me, EVENT_JUMP, true);
                            break;*/
                        case EVENT_BLIGHTED_ARROW:
                            events.CancelEvent(EVENT_UNHOLY_SHOT);
                            events.CancelEvent(EVENT_BLACK_ARROW);
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100, true))
                            {
                                // Spell save in the following float variable
                                // the position of a random player
                                float targetPosX = target->GetPositionX();
                                float targetPosY = target->GetPositionY();
                                float targetPosZ = target->GetPositionZ();
                                float targetOrie = target->GetOrientation();
                                // dist is the distance between pools
                                float dist = 4.0f;
                                // Sylvanas summon 5 pools lined up in a row
                                // they have the same orientation of target
                                me->SummonCreature(54403,targetPosX, targetPosY, targetPosZ);
                                me->SummonCreature(54403,targetPosX + dist * cos(targetOrie), targetPosY + dist * sin(targetOrie), targetPosZ);
                                me->SummonCreature(54403,targetPosX - dist * cos(targetOrie), targetPosY - dist * sin(targetOrie), targetPosZ);
                                me->SummonCreature(54403,targetPosX + 2 * dist * cos(targetOrie), targetPosY + 2 * dist * sin(targetOrie), targetPosZ);
                                me->SummonCreature(54403,targetPosX + 3 * dist * cos(targetOrie), targetPosY + 3 * dist * sin(targetOrie), targetPosZ);
                                // They explode in class mob_blighted_arrows
                                // TODO: sylvanas doesn't do the animation of blighted arrow
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_echo_of_sylvanasAI(creature);
        }
};

class mob_ghoul_summoner : public CreatureScript
{
    public:
        mob_ghoul_summoner() : CreatureScript("mob_ghoul_summoner") { }

        struct mob_ghoul_summonerAI : public ScriptedAI
        {
            mob_ghoul_summonerAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            float size;

            void InitializeAI() override
            {
                size = 2.5f;
                me->GetMotionMaster()->Clear();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->SetReactState(REACT_PASSIVE);
                if (Creature* sylvanas = instance->GetCreature(NPC_ECHO_OF_SYLVANAS))
                    me->SetTarget(sylvanas->GetGUID());
                me->SetSpeed(MOVE_WALK, 0.4f);
                me->SetWalk(true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCast(me, SPELL_GHOUL_CIRCLE);
                events.ScheduleEvent(EVENT_SUMMON_GHOUL, 1000);
                events.ScheduleEvent(EVENT_CALLING_SHADOWS, 7000);
                events.ScheduleEvent(EVENT_DESPAWN, 33000);
            }


            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                size -= 0.0035f;

                me->SetObjectScale(size);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Ghoul summoner summons its own ghoul
                        case EVENT_SUMMON_GHOUL:
                            DoCast(me, SPELL_SUMMON_GHOUL);
                            break;
                        // Ghoul summoner adds itself shadow aura (visual)
                        case EVENT_CALLING_SHADOWS:
                            DoCast(me, SPELL_CALLING_SHADOWS);
                            me->GetMotionMaster()->MovePoint(0, TelePoint[0], TelePoint[1], TelePoint[2], TelePoint[3]);
                            break;
                        case EVENT_DESPAWN:
                            me->DisappearAndDie();
                            break;
                    }
                }
            }


        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ghoul_summonerAI(creature);
        }
};

class mob_risen_ghoul : public CreatureScript
{
    public:
        mob_risen_ghoul() : CreatureScript("mob_risen_ghoul") { }

        struct mob_risen_ghoulAI : public ScriptedAI
        {
            mob_risen_ghoulAI(Creature* creature) : ScriptedAI(creature) { }

            InstanceScript* instance;
            EventMap events;
            uint8 i;
            uint32 checkTimer;
            float arc;
            float checkDistance;

            void InitializeAI() override
            {
                instance = me->GetInstanceScript();

                if (!instance)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                me->GetMotionMaster()->Clear();
                me->SetReactState(REACT_PASSIVE);
                if (Creature* sylvanas = instance->GetCreature(NPC_ECHO_OF_SYLVANAS))
                    me->SetTarget(sylvanas->GetGUID());
                me->SetSpeed(MOVE_WALK, 0.4f);
                me->SetWalk(true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                events.Reset();
                me->SetSpeed(MOVE_WALK, 0.4f);
                me->SetWalk(true);
                events.ScheduleEvent(EVENT_WRACKING_PAIN_LINK, 4000);
                events.ScheduleEvent(EVENT_DESPAWN, 33000);
                checkTimer = 5000;
                arc = float(M_PI);
                checkDistance = 50.0f;
            }

            void JustDied(Unit* /*killer*/) override
            {
                // When ghoul dies, it has to kill its own summoner (the nearest)
                me->DisappearAndDie();
                if (Creature* summoner = GetClosestCreatureWithEntry(me, NPC_GHOUL_SUMMONER, 100.0f))
                    summoner->DisappearAndDie();
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                // We have to check if a player is between two adjacent ghouls
                // First step: we make a list of all ghouls in 30 ys
                // nextGhoul1 & nextGhoul2 are the two nearby ghoul (one to the left and one to the right)
                Unit* nextGhoul1 = nullptr;
                Unit* nextGhoul2 = nullptr;
                std::list<Unit*> Ghouls;
                Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, Ghouls, u_check);
                Cell::VisitAllObjects(me, searcher, 30.0f);
                for (std::list<Unit*>::const_iterator iter = Ghouls.begin(); iter != Ghouls.end(); ++iter)
                {
                    // Skip creatures that aren't ghouls
                    if ((*iter)->GetEntry() != NPC_RISEN_GHOUL && nextGhoul1 && nextGhoul2)
                        continue;

                    if (Creature* sylvanas = instance->GetCreature(NPC_ECHO_OF_SYLVANAS))
                    {
                        // We have to check if the angle between ghoul (me), sylvanas and the adjacent ghoul
                        float meX = me->GetPositionX();
                        float meY = me->GetPositionY();
                        float sylvanasX = sylvanas->GetPositionX();
                        float sylvanasY = sylvanas->GetPositionY();
                        float nearbyGhoulX = (*iter)->GetPositionX();
                        float nearbyGhoulY = (*iter)->GetPositionY();

                        float squareAB = sqrt(pow((meX - sylvanasX), 2) + pow((meY - sylvanasY), 2));
                        float squareBC = sqrt(pow((sylvanasX - nearbyGhoulX), 2) + pow((sylvanasY - nearbyGhoulY), 2));

                        float cosAngle = ((meX - sylvanasX) * (nearbyGhoulX - sylvanasX) + (meY - sylvanasY) * (nearbyGhoulY - sylvanasY)) / (squareAB * squareBC);

                        // If the agle is minor than 90°
                        // (*iter) is the right ghoul for which we could check if player is in between
                        if (acos(cosAngle) < 1.57f && !nextGhoul1)
                        {
                            nextGhoul1 = (*iter);
                        }

                        // If the agle is major than 270°
                        // (*iter) is the right ghoul for which we could check if player is in between
                        if (acos(cosAngle) > 4.71f && !nextGhoul2)
                        {
                            nextGhoul2 = (*iter);
                        }
                    }
                }

                if (nextGhoul1)
                {
                    if (Map* map = me->GetMap())
                    {
                        if (map && map->IsDungeon())
                        {
                            std::list<Player*> PlayerList;
                            Map::PlayerList const& Players = map->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                            {
                                if (Player* player = itr->GetSource())
                                {
                                    // If player is in between two adjacent ghouls
                                    // player will be hitted by Wracking Pain
                                    if (player->IsInBetween(me, nextGhoul1, 1.5f))
                                    {
                                        player->CastSpell(player, SPELL_WRACKING_PAIN_DMG, true);
                                    }
                                }
                            }
                        }
                    }
                }

                if (nextGhoul2)
                {
                    if (Map* map = me->GetMap())
                    {
                        if (map && map->IsDungeon())
                        {
                            std::list<Player*> PlayerList;
                            Map::PlayerList const& Players = map->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                            {
                                if (Player* player = itr->GetSource())
                                {
                                    // If player is in between two adjacent ghouls
                                    // player will be hitted by Wracking Pain
                                    if (player->IsInBetween(me, nextGhoul2, 1.5f))
                                    {
                                        player->CastSpell(player, SPELL_WRACKING_PAIN_DMG, true);
                                    }
                                }
                            }
                        }
                    }
                }

                if (checkTimer <= diff)
                {
                    arc -= 0.009817f;
                    checkDistance -= 0.1675f;
                    if (Map* map = me->GetMap())
                    {
                        std::list<Player*> PlayerList;
                        Map::PlayerList const& Players = map->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                            {
                                if (me->isInBackInMap(player, checkDistance, arc))
                                {
                                    player->CastSpell(player, SPELL_WRACKING_PAIN_DMG, true);
                                }
                            }
                        }
                    }
                }
                else
                    checkTimer -= diff;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WRACKING_PAIN_LINK:
                        {
                            DoCastAOE(SPELL_WRACKING_PAIN_LINK);
                            me->GetMotionMaster()->MovePoint(0, TelePoint[0], TelePoint[1], TelePoint[2], TelePoint[3]);
                        }
                        break;
                        case EVENT_DESPAWN:
                            me->DisappearAndDie();
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_risen_ghoulAI(creature);
        }
};

class spell_wracking_pain_link : public SpellScriptLoader
{
    public:
        spell_wracking_pain_link() : SpellScriptLoader("spell_wracking_pain_link") { }

        class spell_wracking_pain_link_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wracking_pain_link_SpellScript);

            void CountTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](const WorldObject* target)
                {
                    return target->GetEntry() != NPC_RISEN_GHOUL;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wracking_pain_link_SpellScript::CountTargets, EFFECT_0,  TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wracking_pain_link_SpellScript();
        }
};

class mob_blighted_arrows : public CreatureScript
{
    public:
        mob_blighted_arrows() : CreatureScript("mob_blighted_arrows") { }

        struct mob_blighted_arrowsAI : public ScriptedAI
        {
            mob_blighted_arrowsAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;

            void InitializeAI() override
            {
                DoStopAttack();
                me->SetReactState(REACT_PASSIVE);
                me->setActive(false);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoStopAttack();
                me->setActive(false);
                events.Reset();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->SetReactState(REACT_PASSIVE);
                DoCastAOE(SPELL_BLIGHTED_ARROWS_VISUAL);
                events.ScheduleEvent(EVENT_EXPLODE, 5000);
                events.ScheduleEvent(EVENT_DESPAWN, 10000);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_EXPLODE:
                        me->RemoveAurasDueToSpell(SPELL_BLIGHTED_ARROWS_VISUAL);
                        DoCastAOE(SPELL_BLIGHTED_ARROWS_EXPLOSION);
                        break;
                    case EVENT_DESPAWN:
                        me->DisappearAndDie();
                        break;
                    default:
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_blighted_arrowsAI(creature);
        }
};

void AddSC_boss_echo_of_sylvanas()
{
    new boss_echo_of_sylvanas();
    new mob_ghoul_summoner();
    new mob_risen_ghoul();
    new spell_wracking_pain_link();
    new mob_blighted_arrows();
}

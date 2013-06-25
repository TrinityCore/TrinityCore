/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "blackwing_lair.h"
#include "Player.h"

enum Events
{
    // Victor Nefarius
    EVENT_SPAWN_ADD            = 1,
    EVENT_SHADOW_BOLT          = 2,
    EVENT_FEAR                 = 3,
    EVENT_MIND_CONTROL         = 4,

    // Victor Nefarius UBRS Events
    EVENT_PLAYER_CHECK         = 5,
    EVENT_GYTH_REND_1          = 6,
    EVENT_GYTH_REND_2          = 7,
    EVENT_GYTH_REND_3          = 8,
    EVENT_GYTH_REND_4          = 9,
    EVENT_GYTH_REND_5          = 10,
    EVENT_GYTH_REND_6          = 11,

    // Nefarian
    EVENT_SHADOWFLAME          = 12,
    EVENT_VEILOFSHADOW         = 13,
    EVENT_CLEAVE               = 14,
    EVENT_TAILLASH             = 15,
    EVENT_CLASSCALL            = 16
};

enum Says
{
    // Victor Nefarius
    // UBRS text
    SAY_GYTH_REND_1            = 0,
    SAY_GYTH_REND_2            = 1,
    SAY_GYTH_REND_3            = 2,
    SAY_GYTH_REND_4            = 3,
    SAY_GYTH_REND_5            = 4,
    SAY_GYTH_REND_6            = 5,
    SAY_GYTH_REND_7            = 6,
    SAY_GYTH_REND_8            = 7,
    SAY_GYTH_REND_9            = 8,
    SAY_GYTH_REND_10           = 9,
    // BWL text
    SAY_GAMESBEGIN_1           = 10,
    SAY_GAMESBEGIN_2           = 11,
 // SAY_VAEL_INTRO             = 12, Not used - when he corrupts Vaelastrasz

    // Nefarian
    SAY_RANDOM                 = 0,
    SAY_RAISE_SKELETONS        = 1,
    SAY_SLAY                   = 2,
    SAY_DEATH                  = 3,

    SAY_MAGE                   = 4,
    SAY_WARRIOR                = 5,
    SAY_DRUID                  = 6,
    SAY_PRIEST                 = 7,
    SAY_PALADIN                = 8,
    SAY_SHAMAN                 = 9,
    SAY_WARLOCK                = 10,
    SAY_HUNTER                 = 11,
    SAY_ROGUE                  = 12,
    SAY_DEATH_KNIGHT           = 13
};

enum Gameobjects
{
    // UBRS
    OBJECT_DR_PORTCULLIS       = 175185
};

enum Gossip
{
   GOSSIP_ID                   = 21332,
};

enum Creatures
{
    // UBRS
    NPC_REND_BLACKHAND         = 10429,
    // BWL
    NPC_BRONZE_DRAKANOID       = 14263,
    NPC_BLUE_DRAKANOID         = 14261,
    NPC_RED_DRAKANOID          = 14264,
    NPC_GREEN_DRAKANOID        = 14262,
    NPC_BLACK_DRAKANOID        = 14265,
    NPC_CHROMATIC_DRAKANOID    = 14302,
    NPC_BONE_CONSTRUCT         = 14605
};

enum Spells
{
    // Victor Nefarius
    // UBRS Spells
    SPELL_CHROMATIC_CHAOS       = 16337, // Self Cast hits 10339
    SPELL_VAELASTRASZZ_SPAWN    = 16354, // Self Cast Depawn one sec after
    // BWL Spells
    SPELL_SHADOWBOLT            = 22677,
    SPELL_SHADOWBOLT_VOLLEY     = 22665,
    SPELL_SHADOW_COMMAND        = 22667,
    SPELL_FEAR                  = 22678,

    SPELL_NEFARIANS_BARRIER     = 22663,

    // Nefarian
    SPELL_SHADOWFLAME_INITIAL   = 22992,
    SPELL_SHADOWFLAME           = 22539,
    SPELL_BELLOWINGROAR         = 22686,
    SPELL_VEILOFSHADOW          = 7068,
    SPELL_CLEAVE                = 20691,
    SPELL_TAILLASH              = 23364,

    SPELL_MAGE                  = 23410,     // wild magic
    SPELL_WARRIOR               = 23397,     // beserk
    SPELL_DRUID                 = 23398,     // cat form
    SPELL_PRIEST                = 23401,     // corrupted healing
    SPELL_PALADIN               = 23418,     // syphon blessing
    SPELL_SHAMAN                = 23425,     // totems
    SPELL_WARLOCK               = 23427,     // infernals
    SPELL_HUNTER                = 23436,     // bow broke
    SPELL_ROGUE                 = 23414,     // Paralise
    SPELL_DEATH_KNIGHT          = 49576      // Death Grip
};

Position const DrakeSpawnLoc[2] = // drakonid
{
    {-7591.151855f, -1204.051880f, 476.800476f, 3.0f},
    {-7514.598633f, -1150.448853f, 476.796570f, 3.0f}
};

Position const NefarianLoc[2] =
{
    {-7449.763672f, -1387.816040f, 526.783691f, 3.0f}, // nefarian spawn
    {-7535.456543f, -1279.562500f, 476.798706f, 3.0f}  // nefarian move
};

uint32 const Entry[5] = {NPC_BRONZE_DRAKANOID, NPC_BLUE_DRAKANOID, NPC_RED_DRAKANOID, NPC_GREEN_DRAKANOID, NPC_BLACK_DRAKANOID};

class boss_victor_nefarius : public CreatureScript
{
public:
    boss_victor_nefarius() : CreatureScript("boss_victor_nefarius") { }

    struct boss_victor_nefariusAI : public BossAI
    {
        boss_victor_nefariusAI(Creature* creature) : BossAI(creature, BOSS_NEFARIAN) { }

        void Reset()
        {
            if (me->GetMapId() == 229)
            {
                playerGUID = 0;
                events.ScheduleEvent(EVENT_PLAYER_CHECK, 10000);
            }

            if (me->GetMapId() == 469)
            {
                if (!me->FindNearestCreature(NPC_NEFARIAN, 1000.0f, true))
                    _Reset();
                SpawnedAdds = 0;

                me->SetVisible(true);
                me->SetPhaseMask(1, true);
                me->SetUInt32Value(UNIT_NPC_FLAGS, 1);
                me->setFaction(35);
                me->SetStandState(UNIT_STAND_STATE_SIT_HIGH_CHAIR);
                me->RemoveAura(SPELL_NEFARIANS_BARRIER);
            }
        }

        void JustReachedHome()
        {
            Reset();
        }

        void BeginEvent(Player* target)
        {
            _EnterCombat();

            Talk(SAY_GAMESBEGIN_2);

            me->setFaction(103);
            me->SetUInt32Value(UNIT_NPC_FLAGS, 0);
            DoCast(me, SPELL_NEFARIANS_BARRIER);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            AttackStart(target);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(3000, 10000));
            events.ScheduleEvent(EVENT_FEAR, urand(10000, 20000));
            //events.ScheduleEvent(EVENT_MIND_CONTROL, urand(30000, 35000));
            events.ScheduleEvent(EVENT_SPAWN_ADD, 10000);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
        {
            if (summon->GetEntry() != NPC_NEFARIAN)
            {
                summon->UpdateEntry(NPC_BONE_CONSTRUCT);
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                summon->SetReactState(REACT_PASSIVE);
                summon->SetStandState(UNIT_STAND_STATE_DEAD);
            }
        }

        void JustSummoned(Creature* /*summon*/) {}

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (me->GetMapId() == 229) // UBRS EVENTS
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PLAYER_CHECK:
                        {
                            Map::PlayerList const &players = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                if (Player* player = itr->GetSource()->ToPlayer())
                                {
                                    if (me->GetDistance(player) < 30.0f && player->IsAlive() && !player->IsGameMaster())
                                    {
                                        playerGUID = player->GetGUID();
                                        me->SetInFront(player);
                                        me->SendMovementFlagUpdate();
                                        events.ScheduleEvent(EVENT_GYTH_REND_1, 1000);
                                    }
                                    else
                                        events.ScheduleEvent(EVENT_PLAYER_CHECK, 10000);
                                }
                            break;
                        }
                        case EVENT_GYTH_REND_1:
                            Talk(SAY_GYTH_REND_1);
                            events.ScheduleEvent(EVENT_GYTH_REND_2, 4000);
                            break;
                        case EVENT_GYTH_REND_2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                            events.ScheduleEvent(EVENT_GYTH_REND_3, 4000);
                            break;
                        case EVENT_GYTH_REND_3:
                            Talk(SAY_GYTH_REND_2);
                            events.ScheduleEvent(EVENT_GYTH_REND_4, 2000);
                            break;
                        case EVENT_GYTH_REND_4:
                            if (GameObject* portcullis = me->FindNearestGameObject(OBJECT_DR_PORTCULLIS, 50.0f))
                                portcullis->SetGoState(GO_STATE_READY);
                            events.ScheduleEvent(EVENT_GYTH_REND_5, 2000);
                            break;
                        case EVENT_GYTH_REND_5:
                            if (Creature* rend = me->FindNearestCreature(NPC_REND_BLACKHAND, 5.0f, true))
                                me->SetInFront(rend);
                            me->SendMovementFlagUpdate();
                            events.ScheduleEvent(EVENT_GYTH_REND_5, 4000);
                            break;
                        case EVENT_GYTH_REND_6:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            events.ScheduleEvent(EVENT_GYTH_REND_6, 4000);
                        default:
                            break;
                    }
                }
            }

            if (me->GetMapId() != 469)
                return;

            // Only do this if we haven't spawned nefarian yet
            if (UpdateVictim() && SpawnedAdds <= 42)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_BOLT:
                            switch (urand(0, 1))
                            {
                                case 0:
                                    DoCastVictim(SPELL_SHADOWBOLT_VOLLEY);
                                    break;
                                case 1:
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                                        DoCast(target, SPELL_SHADOWBOLT);
                                    break;
                            }
                            DoResetThreat();
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(3000, 10000));
                            break;
                        case EVENT_FEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                                DoCast(target, SPELL_FEAR);
                            events.ScheduleEvent(EVENT_FEAR, urand(10000, 20000));
                            break;
                        case EVENT_MIND_CONTROL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                                DoCast(target, SPELL_SHADOW_COMMAND);
                            events.ScheduleEvent(EVENT_MIND_CONTROL, urand(30000, 35000));
                            break;
                        case EVENT_SPAWN_ADD:
                            for (uint8 i=0; i<2; ++i)
                            {
                                uint32 CreatureID;
                                if (urand(0, 2) == 0)
                                    CreatureID = NPC_CHROMATIC_DRAKANOID;
                                else
                                    CreatureID = Entry[urand(0, 4)];
                                if (Creature* dragon = me->SummonCreature(CreatureID, DrakeSpawnLoc[i]))
                                {
                                    dragon->setFaction(103);
                                    dragon->AI()->AttackStart(me->GetVictim());
                                }

                                if (++SpawnedAdds >= 42)
                                {
                                    if (Creature* nefarian = me->SummonCreature(NPC_NEFARIAN, NefarianLoc[0]))
                                    {
                                        nefarian->setActive(true);
                                        nefarian->SetCanFly(true);
                                        nefarian->SetDisableGravity(true);
                                        nefarian->AI()->DoCastAOE(SPELL_SHADOWFLAME_INITIAL);
                                        nefarian->GetMotionMaster()->MovePoint(1, NefarianLoc[1]);
                                    }
                                    events.CancelEvent(EVENT_MIND_CONTROL);
                                    events.CancelEvent(EVENT_FEAR);
                                    events.CancelEvent(EVENT_SHADOW_BOLT);
                                    me->SetVisible(false);
                                    return;
                                }
                            }
                            events.ScheduleEvent(EVENT_SPAWN_ADD, 4000);
                            break;
                    }
                }
            }
        }

        void sGossipSelect(Player* player, uint32 sender, uint32 action)
        {
            if (sender == GOSSIP_ID && action == 0)
            {
                player->CLOSE_GOSSIP_MENU();
                Talk(SAY_GAMESBEGIN_1);
                BeginEvent(player);
            }
        }

        private:
            // UBRS
            uint64 playerGUID;
            // BWL
            uint32 SpawnedAdds;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_victor_nefariusAI (creature);
    }
};

class boss_nefarian : public CreatureScript
{
public:
    boss_nefarian() : CreatureScript("boss_nefarian") { }

    struct boss_nefarianAI : public BossAI
    {
        boss_nefarianAI(Creature* creature) : BossAI(creature, BOSS_NEFARIAN) { }

        void Reset()
        {
            Phase3 = false;
            canDespawn = false;
            DespawnTimer = 30000;
        }

        void JustReachedHome()
        {
            canDespawn = true;
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOWFLAME, 12000);
            events.ScheduleEvent(EVENT_FEAR, urand(25000, 35000));
            events.ScheduleEvent(EVENT_VEILOFSHADOW, urand(25000, 35000));
            events.ScheduleEvent(EVENT_CLEAVE, 7000);
            //events.ScheduleEvent(EVENT_TAILLASH, 10000);
            events.ScheduleEvent(EVENT_CLASSCALL, urand(30000, 35000));
            Talk(SAY_RANDOM);
        }

        void JustDied(Unit* /*Killer*/)
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* victim)
        {
            if (rand()%5)
                return;

            Talk(SAY_SLAY, victim->GetGUID());
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                me->SetInCombatWithZone();
                if (me->GetVictim())
                    AttackStart(me->GetVictim());
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (canDespawn && DespawnTimer <= diff)
            {
                if (instance)
                    instance->SetBossState(BOSS_NEFARIAN, FAIL);

                std::list<Creature*> constructList;
                me->GetCreatureListWithEntryInGrid(constructList, NPC_BONE_CONSTRUCT, 500.0f);
                for (std::list<Creature*>::const_iterator itr = constructList.begin(); itr != constructList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

            } else DespawnTimer -= diff;

            if (!UpdateVictim())
                return;

            if (canDespawn)
                canDespawn = false;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOWFLAME:
                        DoCastVictim(SPELL_SHADOWFLAME);
                        events.ScheduleEvent(EVENT_SHADOWFLAME, 12000);
                        break;
                    case EVENT_FEAR:
                        DoCastVictim(SPELL_BELLOWINGROAR);
                        events.ScheduleEvent(EVENT_FEAR, urand(25000, 35000));
                        break;
                    case EVENT_VEILOFSHADOW:
                        DoCastVictim(SPELL_VEILOFSHADOW);
                        events.ScheduleEvent(EVENT_VEILOFSHADOW, urand(25000, 35000));
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 7000);
                        break;
                    case EVENT_TAILLASH:
                        // Cast NYI since we need a better check for behind target
                        DoCastVictim(SPELL_TAILLASH);
                        events.ScheduleEvent(EVENT_TAILLASH, 10000);
                        break;
                    case EVENT_CLASSCALL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            switch (target->getClass())
                        {
                            case CLASS_MAGE:
                                Talk(SAY_MAGE);
                                DoCast(me, SPELL_MAGE);
                                break;
                            case CLASS_WARRIOR:
                                Talk(SAY_WARRIOR);
                                DoCast(me, SPELL_WARRIOR);
                                break;
                            case CLASS_DRUID:
                                Talk(SAY_DRUID);
                                DoCast(target, SPELL_DRUID);
                                break;
                            case CLASS_PRIEST:
                                Talk(SAY_PRIEST);
                                DoCast(me, SPELL_PRIEST);
                                break;
                            case CLASS_PALADIN:
                                Talk(SAY_PALADIN);
                                DoCast(me, SPELL_PALADIN);
                                break;
                            case CLASS_SHAMAN:
                                Talk(SAY_SHAMAN);
                                DoCast(me, SPELL_SHAMAN);
                                break;
                            case CLASS_WARLOCK:
                                Talk(SAY_WARLOCK);
                                DoCast(me, SPELL_WARLOCK);
                                break;
                            case CLASS_HUNTER:
                                Talk(SAY_HUNTER);
                                DoCast(me, SPELL_HUNTER);
                                break;
                            case CLASS_ROGUE:
                                Talk(SAY_ROGUE);
                                DoCast(me, SPELL_ROGUE);
                                break;
                            case CLASS_DEATH_KNIGHT:
                                Talk(SAY_DEATH_KNIGHT);
                                DoCast(me, SPELL_DEATH_KNIGHT);
                                break;
                            default:
                                break;
                        }
                        events.ScheduleEvent(EVENT_CLASSCALL, urand(30000, 35000));
                        break;
                }
            }

            // Phase3 begins when health below 20 pct
            if (!Phase3 && HealthBelowPct(20))
            {
                std::list<Creature*> constructList;
                me->GetCreatureListWithEntryInGrid(constructList, NPC_BONE_CONSTRUCT, 500.0f);
                for (std::list<Creature*>::const_iterator itr = constructList.begin(); itr != constructList.end(); ++itr)
                    if ((*itr) && !(*itr)->IsAlive())
                    {
                        (*itr)->Respawn();
                        (*itr)->SetInCombatWithZone();
                        (*itr)->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        (*itr)->SetReactState(REACT_AGGRESSIVE);
                        (*itr)->SetStandState(UNIT_STAND_STATE_STAND);
                    }

                Phase3 = true;
                Talk(SAY_RAISE_SKELETONS);
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool canDespawn;
        uint32 DespawnTimer;
        bool Phase3;

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_nefarianAI (creature);
    }
};

void AddSC_boss_nefarian()
{
    new boss_victor_nefarius();
    new boss_nefarian();
}

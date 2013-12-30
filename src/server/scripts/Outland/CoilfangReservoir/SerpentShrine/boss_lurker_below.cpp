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

/* ScriptData
SDName: boss_the_lurker_below
SD%Complete: 80
SDComment: Coilfang Frenzy, find out how could we fishing in the strangepool
SDCategory: The Lurker Below
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"
#include "Spell.h"
#include "Player.h"

enum Spells
{
    SPELL_SPOUT             = 37433,
    SPELL_SPOUT_ANIM        = 42835,
    SPELL_SPOUT_BREATH      = 37431,
    SPELL_KNOCKBACK         = 19813,
    SPELL_GEYSER            = 37478,
    SPELL_WHIRL             = 37660,
    SPELL_WATERBOLT         = 37138,
    SPELL_SUBMERGE          = 37550,
    SPELL_EMERGE            = 20568,


    // Ambusher spells
    SPELL_SPREAD_SHOT       = 37790,
    SPELL_SHOOT             = 37770,
    // Guardian spells
    SPELL_ARCINGSMASH       = 38761, // Wrong SpellId. Can't find the right one.
    SPELL_HAMSTRING         = 26211
};

enum Creatures
{
    NPC_COILFANG_GUARDIAN   = 21873,
    NPC_COILFANG_AMBUSHER   = 21865
};

#define EMOTE_SPOUT "The Lurker Below takes a deep breath."

#define SPOUT_DIST  100

float AddPos[9][3] =
{
    // MOVE_AMBUSHER_1 X, Y, Z
    {2.8553810f, -459.823914f, -19.182686f},
    {12.400000f, -466.042267f, -19.182686f},
    {51.366653f, -460.836060f, -19.182686f},
    {62.597980f, -457.433044f, -19.182686f},
    {77.607452f, -384.302765f, -19.182686f},
    {63.897900f, -378.984924f, -19.182686f},
    {34.447250f, -387.333618f, -19.182686f},
    {14.388216f, -423.468018f, -19.625271f},
    {42.471519f, -445.115295f, -19.769423f}
};

class boss_the_lurker_below : public CreatureScript
{
public:
    boss_the_lurker_below() : CreatureScript("boss_the_lurker_below") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_the_lurker_belowAI>(creature);
    }

    struct boss_the_lurker_belowAI : public ScriptedAI
    {
        boss_the_lurker_belowAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            SetCombatMovement(false);
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList Summons;

        bool Spawned;
        bool Submerged;
        bool InRange;
        bool CanStartEvent;
        uint32 RotTimer;
        uint32 SpoutAnimTimer;
        uint32 WaterboltTimer;
        uint32 SpoutTimer;
        uint32 WhirlTimer;
        uint32 PhaseTimer;
        uint32 GeyserTimer;
        uint32 CheckTimer;
        uint32 WaitTimer;
        uint32 WaitTimer2;

        bool CheckCanStart()//check if players fished
        {
            if (instance && instance->GetData(DATA_STRANGE_POOL) == NOT_STARTED)
                return false;
            return true;
        }
        void Reset() OVERRIDE
        {
            me->SetSwim(true);
            me->SetDisableGravity(true);
            SpoutAnimTimer = 1000;
            RotTimer = 0;
            WaterboltTimer = 15000; // give time to get in range when fight starts
            SpoutTimer = 45000;
            WhirlTimer = 18000; // after avery spout
            PhaseTimer = 120000;
            GeyserTimer = rand()%5000 + 15000;
            CheckTimer = 15000; // give time to get in range when fight starts
            WaitTimer = 60000; // never reached
            WaitTimer2 = 60000; // never reached

            Submerged = true; // will be false at combat start
            Spawned = false;
            InRange = false;
            CanStartEvent = false;

            Summons.DespawnAll();

            instance->SetData(DATA_THELURKERBELOWEVENT, NOT_STARTED);
            instance->SetData(DATA_STRANGE_POOL, NOT_STARTED);
            DoCast(me, SPELL_SUBMERGE); // submerge anim
            me->SetVisible(false); // we start invis under water, submerged
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            instance->SetData(DATA_THELURKERBELOWEVENT, DONE);
            instance->SetData(DATA_STRANGE_POOL, IN_PROGRESS);

            Summons.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            instance->SetData(DATA_THELURKERBELOWEVENT, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!CanStartEvent) // boss is invisible, don't attack
                return;
            if (!me->GetVictim() && who->IsValidAttackTarget(me))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius))
                    AttackStart(who);
            }
        }

        void MovementInform(uint32 type, uint32 /*id*/) OVERRIDE
        {
            if (type == ROTATE_MOTION_TYPE)
                me->SetReactState(REACT_AGGRESSIVE);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!CanStartEvent) // boss is invisible, don't attack
            {
                if (CheckCanStart())
                {
                    if (Submerged)
                    {
                        me->SetVisible(true);
                        Submerged = false;
                        WaitTimer2 = 500;
                    }

                    if (!Submerged && WaitTimer2 <= diff) // wait 500ms before emerge anim
                    {
                        me->RemoveAllAuras();
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                        DoCast(me, SPELL_EMERGE, false);
                        WaitTimer2 = 60000; // never reached
                        WaitTimer = 3000;
                    }
                    else
                        WaitTimer2 -= diff;

                    if (WaitTimer <= diff) // wait 3secs for emerge anim, then attack
                    {
                        WaitTimer = 3000;
                        CanStartEvent = true; // fresh fished from pool
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    else
                        WaitTimer -= diff;
                }
                return;
            }

            if (me->getThreatManager().getThreatList().empty()) // check if should evade
            {
                if (me->IsInCombat())
                    EnterEvadeMode();
                return;
            }
            if (!Submerged)
            {
                if (PhaseTimer <= diff)
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_SUBMERGE);
                    PhaseTimer = 60000; // 60secs submerged
                    Submerged = true;
                } else PhaseTimer-=diff;

                if (SpoutTimer <= diff)
                {
                    me->MonsterTextEmote(EMOTE_SPOUT, NULL, true);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveRotate(20000, urand(0, 1) ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
                    SpoutTimer = 45000;
                    WhirlTimer = 20000; // whirl directly after spout
                    RotTimer = 20000;
                    return;
                } else SpoutTimer -= diff;

                // Whirl directly after a Spout and at random times
                if (WhirlTimer <= diff)
                {
                    WhirlTimer = 18000;
                    DoCast(me, SPELL_WHIRL);
                } else WhirlTimer -= diff;

                if (CheckTimer <= diff)//check if there are players in melee range
                {
                    InRange = false;
                    Map* map = me->GetMap();
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (me->IsWithinMeleeRange(i->GetSource()))
                                InRange = true;
                        }
                    }
                    CheckTimer = 2000;
                } else CheckTimer -= diff;

                if (RotTimer)
                {
                    Map* map = me->GetMap();
                    if (map->IsDungeon())
                    {
                        Map::PlayerList const &PlayerList = map->GetPlayers();
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (i->GetSource() && i->GetSource()->IsAlive() && me->HasInArc(float(diff/20000*M_PI*2), i->GetSource()) && me->IsWithinDist(i->GetSource(), SPOUT_DIST) && !i->GetSource()->IsInWater())
                                DoCast(i->GetSource(), SPELL_SPOUT, true); // only knock back players in arc, in 100yards, not in water
                        }
                    }

                    if (SpoutAnimTimer <= diff)
                    {
                        DoCast(me, SPELL_SPOUT_ANIM, true);
                        SpoutAnimTimer = 1000;
                    } else SpoutAnimTimer -= diff;

                    if (RotTimer <= diff)
                    {
                        RotTimer = 0;
                    } else RotTimer -= diff;
                    return;
                }

                if (GeyserTimer <= diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                    if (!target && me->GetVictim())
                        target = me->GetVictim();
                    if (target)
                        DoCast(target, SPELL_GEYSER, true);
                    GeyserTimer = rand()%5000 + 15000;
                } else GeyserTimer -= diff;

                if (!InRange) // if on players in melee range cast Waterbolt
                {
                    if (WaterboltTimer <= diff)
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        if (!target && me->GetVictim())
                            target = me->GetVictim();
                        if (target)
                            DoCast(target, SPELL_WATERBOLT, true);
                        WaterboltTimer = 3000;
                    } else WaterboltTimer -= diff;
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();

            }
            else // submerged
            {
                if (PhaseTimer <= diff)
                {
                    Submerged = false;
                    me->InterruptNonMeleeSpells(false); // shouldn't be any
                    me->RemoveAllAuras();
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveFlag(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SUBMERGED);
                    DoCast(me, SPELL_EMERGE, true);
                    Spawned = false;
                    SpoutTimer = 3000; // directly cast Spout after emerging!
                    PhaseTimer = 120000;
                    return;
                } else PhaseTimer-=diff;

                if (me->getThreatManager().getThreatList().empty()) // check if should evade
                {
                    EnterEvadeMode();
                    return;
                }

                if (!me->IsInCombat())
                    DoZoneInCombat();

                if (!Spawned)
                {
                    me->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    // spawn adds
                    for (uint8 i = 0; i < 9; ++i)
                        if (Creature* summoned = me->SummonCreature(i < 6 ? NPC_COILFANG_AMBUSHER : NPC_COILFANG_GUARDIAN, AddPos[i][0], AddPos[i][1], AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0))
                            Summons.Summon(summoned);
                    Spawned = true;
                }
            }
        }
     };
};

class npc_coilfang_ambusher : public CreatureScript
{
public:
    npc_coilfang_ambusher() : CreatureScript("npc_coilfang_ambusher") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_coilfang_ambusherAI(creature);
    }

    struct npc_coilfang_ambusherAI : public ScriptedAI
    {
        npc_coilfang_ambusherAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        uint32 MultiShotTimer;
        uint32 ShootBowTimer;

        void Reset() OVERRIDE
        {
            MultiShotTimer = 10000;
            ShootBowTimer = 4000;
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!who || me->GetVictim())
                return;

            if (who->isInAccessiblePlaceFor(me) && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 45))
                AttackStart(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (MultiShotTimer <= diff)
            {
                if (me->GetVictim())
                    DoCastVictim(SPELL_SPREAD_SHOT, true);

                MultiShotTimer = 10000+rand()%10000;
                ShootBowTimer += 1500; // add global cooldown
            } else MultiShotTimer -= diff;

            if (ShootBowTimer <= diff)
            {
                int bp0 = 1100;
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    me->CastCustomSpell(target, SPELL_SHOOT, &bp0, NULL, NULL, true);
                ShootBowTimer = 4000+rand()%5000;
                MultiShotTimer += 1500; // add global cooldown
            } else ShootBowTimer -= diff;
        }
    };

};

class go_strange_pool : public GameObjectScript
{
    public:
        go_strange_pool() : GameObjectScript("go_strange_pool") { }

        bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
        {
            // 25%
            if (InstanceScript* instanceScript = go->GetInstanceScript())
                if (!urand(0, 3))
                {
                    if (instanceScript->GetData(DATA_STRANGE_POOL) == NOT_STARTED)
                    {
                        go->CastSpell(player, 54587);
                        instanceScript->SetData(DATA_STRANGE_POOL, IN_PROGRESS);
                    }
                    return true;
                }

            return false;
        }
};

void AddSC_boss_the_lurker_below()
{
    new boss_the_lurker_below();
    new npc_coilfang_ambusher();
    new go_strange_pool();
}

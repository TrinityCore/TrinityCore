/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "serpent_shrine.h"
#include "ScriptedSimpleAI.h"
#include "Spell.h"

#define SPELL_SPOUT         37433
#define SPELL_SPOUT_ANIM    42835
#define SPELL_SPOUT_BREATH  37431
#define SPELL_KNOCKBACK     19813
#define SPELL_GEYSER        37478
#define SPELL_WHIRL         37660
#define SPELL_WATERBOLT     37138
#define SPELL_SUBMERGE      37550
#define SPELL_EMERGE        20568

#define EMOTE_SPOUT "The Lurker Below takes a deep breath."

#define SPOUT_DIST  100

#define MOB_COILFANG_GUARDIAN 21873
#define MOB_COILFANG_AMBUSHER 21865

//Ambusher spells
#define SPELL_SPREAD_SHOT   37790
#define SPELL_SHOOT         37770

//Guardian spells
#define SPELL_ARCINGSMASH   38761 // Wrong SpellId. Can't find the right one.
#define SPELL_HAMSTRING     26211

float AddPos[9][3] =
{
    {2.8553810f, -459.823914f, -19.182686f},   //MOVE_AMBUSHER_1 X, Y, Z
    {12.400000f, -466.042267f, -19.182686f},   //MOVE_AMBUSHER_2 X, Y, Z
    {51.366653f, -460.836060f, -19.182686f},   //MOVE_AMBUSHER_3 X, Y, Z
    {62.597980f, -457.433044f, -19.182686f},   //MOVE_AMBUSHER_4 X, Y, Z
    {77.607452f, -384.302765f, -19.182686f},   //MOVE_AMBUSHER_5 X, Y, Z
    {63.897900f, -378.984924f, -19.182686f},   //MOVE_AMBUSHER_6 X, Y, Z
    {34.447250f, -387.333618f, -19.182686f},   //MOVE_GUARDIAN_1 X, Y, Z
    {14.388216f, -423.468018f, -19.625271f},   //MOVE_GUARDIAN_2 X, Y, Z
    {42.471519f, -445.115295f, -19.769423f}    //MOVE_GUARDIAN_3 X, Y, Z
};

class boss_the_lurker_below : public CreatureScript
{
public:
    boss_the_lurker_below() : CreatureScript("boss_the_lurker_below") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_the_lurker_belowAI (pCreature);
    }

    struct boss_the_lurker_belowAI : public Scripted_NoMovementAI
    {
        boss_the_lurker_belowAI(Creature *c) : Scripted_NoMovementAI(c), Summons(me)
        {
            pInstance = c->GetInstanceScript();
            SpellEntry *TempSpell = GET_SPELL(SPELL_SPOUT_ANIM);
            if (TempSpell)
            {
                TempSpell->Effect[0] = 0;//remove all spell effect, only anim is needed
                TempSpell->Effect[1] = 0;
                TempSpell->Effect[2] = 0;
            }
        }

        InstanceScript* pInstance;
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
            if (pInstance && pInstance->GetData(DATA_STRANGE_POOL) == NOT_STARTED)
                return false;
            return true;
        }
        void Reset()
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_LEVITATING);
            SpoutAnimTimer = 1000;
            RotTimer = 0;
            WaterboltTimer = 15000;//give time to get in range when fight starts
            SpoutTimer = 45000;
            WhirlTimer = 18000;//after avery spout
            PhaseTimer = 120000;
            GeyserTimer = rand()%5000 + 15000;
            CheckTimer = 15000;//give time to get in range when fight starts
            WaitTimer = 60000;//never reached
            WaitTimer2 = 60000;//never reached

            Submerged = true;//will be false at combat start
            Spawned = false;
            InRange = false;
            CanStartEvent = false;

            Summons.DespawnAll();

            if (pInstance)
            {
                pInstance->SetData(DATA_THELURKERBELOWEVENT, NOT_STARTED);
                pInstance->SetData(DATA_STRANGE_POOL, NOT_STARTED);
            }
            DoCast(me, SPELL_SUBMERGE);//submerge anim
            me->SetVisible(false);//we start invis under water, submerged
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_THELURKERBELOWEVENT, DONE);

            Summons.DespawnAll();
        }

        void EnterCombat(Unit * who)
        {
            if (pInstance)
                pInstance->SetData(DATA_THELURKERBELOWEVENT, IN_PROGRESS);
            Scripted_NoMovementAI::EnterCombat(who);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!CanStartEvent)//boss is invisible, don't attack
                return;
            if (!me->getVictim() && who->isTargetableForAttack() && (me->IsHostileTo(who)))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius))
                {
                    AttackStart(who);
                }
            }
        }

        void MovementInform(uint32 type, uint32 /*id*/)
        {
            if (type == ROTATE_MOTION_TYPE)
                me->SetReactState(REACT_AGGRESSIVE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!CanStartEvent)//boss is invisible, don't attack
            {
                if (CheckCanStart())
                {
                    if (Submerged)
                    {
                        me->SetVisible(true);
                        Submerged = false;
                        WaitTimer2 = 500;
                    }
                    if (!Submerged && WaitTimer2 <= diff)//wait 500ms before emerge anim
                    {
                        me->RemoveAllAuras();
                        me->RemoveFlag(UNIT_NPC_EMOTESTATE,EMOTE_STATE_SUBMERGED);
                        DoCast(me, SPELL_EMERGE, false);
                        WaitTimer2 = 60000;//never reached
                        WaitTimer = 3000;
                    } else WaitTimer2 -= diff;

                    if (WaitTimer <= diff)//wait 3secs for emerge anim, then attack
                    {
                        WaitTimer = 3000;
                        CanStartEvent=true;//fresh fished from pool
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    } else WaitTimer -= diff;
                }
                return;
            }

            if (me->getThreatManager().getThreatList().empty())//check if should evade
            {
                if (me->isInCombat())
                    EnterEvadeMode();
                return;
            }
            if (!Submerged)
            {
                if (PhaseTimer <= diff)
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_SUBMERGE);
                    PhaseTimer = 60000;//60secs submerged
                    Submerged = true;
                } else PhaseTimer-=diff;

                if (SpoutTimer <= diff)
                {
                    me->MonsterTextEmote(EMOTE_SPOUT,0,true);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveRotate(20000, rand()%2 ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
                    SpoutTimer = 45000;
                    WhirlTimer = 20000;//whirl directly after spout
                    RotTimer = 20000;
                    return;
                } else SpoutTimer -= diff;

                //Whirl directly after a Spout and at random times
                if (WhirlTimer <= diff)
                {
                    WhirlTimer = 18000;
                    DoCast(me, SPELL_WHIRL);
                } else WhirlTimer -= diff;

                if (CheckTimer <= diff)//check if there are players in melee range
                {
                    InRange = false;
                    Map* pMap = me->GetMap();
                    Map::PlayerList const &PlayerList = pMap->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (me->IsWithinMeleeRange(i->getSource()))
                                InRange = true;
                        }
                    }
                    CheckTimer = 2000;
                } else CheckTimer -= diff;

                if (RotTimer)
                {
                    Map* pMap = me->GetMap();
                    if (pMap->IsDungeon())
                    {
                        Map::PlayerList const &PlayerList = pMap->GetPlayers();
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (i->getSource() && i->getSource()->isAlive() && me->HasInArc(float(diff/20000*M_PI*2),i->getSource()) && me->IsWithinDist(i->getSource(), SPOUT_DIST) && !i->getSource()->IsInWater())
                                DoCast(i->getSource(), SPELL_SPOUT, true);//only knock back palyers in arc, in 100yards, not in water
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
                    Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
                    if (!pTarget && me->getVictim())
                        pTarget = me->getVictim();
                    if (pTarget)
                        DoCast(pTarget, SPELL_GEYSER, true);
                    GeyserTimer = rand()%5000 + 15000;
                } else GeyserTimer -= diff;

                if (!InRange)//if on players in melee range cast Waterbolt
                {
                    if (WaterboltTimer <= diff)
                    {
                        Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                        if (!pTarget && me->getVictim())
                            pTarget = me->getVictim();
                        if (pTarget)
                            DoCast(pTarget, SPELL_WATERBOLT, true);
                        WaterboltTimer = 3000;
                    } else WaterboltTimer -= diff;
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();

            }else//submerged
            {
                if (PhaseTimer <= diff)
                {
                    Submerged = false;
                    me->InterruptNonMeleeSpells(false);//shouldn't be any
                    me->RemoveAllAuras();
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->RemoveFlag(UNIT_NPC_EMOTESTATE,EMOTE_STATE_SUBMERGED);
                    DoCast(me, SPELL_EMERGE, true);
                    Spawned = false;
                    SpoutTimer = 3000; // directly cast Spout after emerging!
                    PhaseTimer = 120000;
                    return;
                } else PhaseTimer-=diff;

                if (me->getThreatManager().getThreatList().empty())//check if should evade
                {
                    EnterEvadeMode();
                    return;
                }
                if (!me->isInCombat())
                    DoZoneInCombat();

                if (!Spawned)
                {
                    me->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    //spawn adds
                    for (uint8 i = 0; i < 9; ++i)
                    {
                        Creature* Summoned;
                        if (i < 6)
                            Summoned = me->SummonCreature(MOB_COILFANG_AMBUSHER,AddPos[i][0],AddPos[i][1],AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        else Summoned = me->SummonCreature(MOB_COILFANG_GUARDIAN,AddPos[i][0],AddPos[i][1],AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0);

                        if (Summoned)
                            Summons.Summon(Summoned);
                    }
                    Spawned = true;
                }
            }
        }
     };
};

class mob_coilfang_guardian : public CreatureScript
{
public:
    mob_coilfang_guardian() : CreatureScript("mob_coilfang_guardian") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        SimpleAI* ai = new SimpleAI (pCreature);

        ai->Spell[0].Enabled = true;
        ai->Spell[0].Spell_Id = SPELL_ARCINGSMASH;
        ai->Spell[0].Cooldown = 15000;
        ai->Spell[0].First_Cast = 5000;
        ai->Spell[0].Cast_Target_Type = CAST_HOSTILE_TARGET;

        ai->Spell[1].Enabled = true;
        ai->Spell[1].Spell_Id = SPELL_HAMSTRING;
        ai->Spell[1].Cooldown = 10000;
        ai->Spell[1].First_Cast = 2000;
        ai->Spell[1].Cast_Target_Type = CAST_HOSTILE_TARGET;

        return ai;
    }

};

class mob_coilfang_ambusher : public CreatureScript
{
public:
    mob_coilfang_ambusher() : CreatureScript("mob_coilfang_ambusher") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_coilfang_ambusherAI (pCreature);
    }

    struct mob_coilfang_ambusherAI : public Scripted_NoMovementAI
    {
        mob_coilfang_ambusherAI(Creature *c) : Scripted_NoMovementAI(c)
        {
            SpellEntry *TempSpell = GET_SPELL(SPELL_SHOOT);
            if (TempSpell)
                TempSpell->Effect[0] = 2;//change spell effect from weapon % dmg to simple phisical dmg
        }

        uint32 MultiShotTimer;
        uint32 ShootBowTimer;

        void Reset()
        {
            MultiShotTimer = 10000;
            ShootBowTimer = 4000;

        }

        void EnterCombat(Unit * /*who*/)
        {

        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who || me->getVictim()) return;

            if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(me) && me->IsHostileTo(who) && me->IsWithinDistInMap(who, 45))
            {
                AttackStart(who);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (MultiShotTimer <= diff)
            {
                if (me->getVictim())
                    DoCast(me->getVictim(), SPELL_SPREAD_SHOT, true);

                MultiShotTimer = 10000+rand()%10000;
                ShootBowTimer += 1500;//add global cooldown
            } else MultiShotTimer -= diff;

            if (ShootBowTimer <= diff)
            {
                Unit *pTarget = NULL;
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                int bp0 = 1100;
                if (pTarget)
                    me->CastCustomSpell(pTarget,SPELL_SHOOT,&bp0,NULL,NULL,true);
                ShootBowTimer = 4000+rand()%5000;
                MultiShotTimer += 1500;//add global cooldown
            } else ShootBowTimer -= diff;
        }
    };

};

void AddSC_boss_the_lurker_below()
{
    new boss_the_lurker_below();
    new mob_coilfang_guardian();
    new mob_coilfang_ambusher();
}

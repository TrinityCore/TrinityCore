/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: boss_the_lurker_below
SD%Complete: 80
SDComment: Coilfang Frenzy, find out how could we fishing in the strangepool
SDCategory: The Lurker Below
EndScriptData */

#include "precompiled.h"
#include "serpent_shrine.h"
#include "simple_ai.h"
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
    {2.8553810, -459.823914, -19.182686},   //MOVE_AMBUSHER_1 X, Y, Z
    {12.400000, -466.042267, -19.182686},   //MOVE_AMBUSHER_2 X, Y, Z
    {51.366653, -460.836060, -19.182686},   //MOVE_AMBUSHER_3 X, Y, Z
    {62.597980, -457.433044, -19.182686},   //MOVE_AMBUSHER_4 X, Y, Z
    {77.607452, -384.302765, -19.182686},   //MOVE_AMBUSHER_5 X, Y, Z
    {63.897900, -378.984924, -19.182686},   //MOVE_AMBUSHER_6 X, Y, Z
    {34.447250, -387.333618, -19.182686},   //MOVE_GUARDIAN_1 X, Y, Z
    {14.388216, -423.468018, -19.625271},   //MOVE_GUARDIAN_2 X, Y, Z
    {42.471519, -445.115295, -19.769423}    //MOVE_GUARDIAN_3 X, Y, Z
};

struct TRINITY_DLL_DECL boss_the_lurker_belowAI : public Scripted_NoMovementAI
{
    boss_the_lurker_belowAI(Creature *c) : Scripted_NoMovementAI(c), Summons(m_creature)
    {
        pInstance = c->GetInstanceData();
        SpellEntry *TempSpell = GET_SPELL(SPELL_SPOUT_ANIM);
        if (TempSpell)
        {
            TempSpell->Effect[0] = 0;//remove all spell effect, only anim is needed
            TempSpell->Effect[1] = 0;
            TempSpell->Effect[2] = 0;
        }
    }

    ScriptedInstance* pInstance;
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
        if(pInstance && pInstance->GetData(DATA_STRANGE_POOL) == NOT_STARTED)
            return false;
        return true;
    }
    void Reset()
    {
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING + MOVEMENTFLAG_LEVITATING);
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
        DoCast(m_creature,SPELL_SUBMERGE);//submerge anim
        m_creature->SetVisibility(VISIBILITY_OFF);//we start invis under water, submerged
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    void JustDied(Unit* Killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_THELURKERBELOWEVENT, DONE);

        Summons.DespawnAll();
    }

    void EnterCombat(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_THELURKERBELOWEVENT, IN_PROGRESS);
        Scripted_NoMovementAI::EnterCombat(who);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if(!CanStartEvent)//boss is invisible, don't attack
            return;
        if (!m_creature->getVictim() && who->isTargetableForAttack() && (m_creature->IsHostileTo(who)))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius))
            {
                AttackStart(who);
            }
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type == ROTATE_MOTION_TYPE)
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!CanStartEvent)//boss is invisible, don't attack
        {
            if(CheckCanStart())
            {
                if(Submerged)
                {
                    m_creature->SetVisibility(VISIBILITY_ON);
                    Submerged = false;
                    WaitTimer2 = 500;
                }
                if(!Submerged && WaitTimer2 < diff)//wait 500ms before emerge anim
                {
                    m_creature->RemoveAllAuras();
                    m_creature->RemoveFlag(UNIT_NPC_EMOTESTATE,EMOTE_STATE_SUBMERGED);
                    DoCast(m_creature,SPELL_EMERGE,false);
                    WaitTimer2 = 60000;//never reached
                    WaitTimer = 3000;
                }else WaitTimer2 -= diff;

                if(WaitTimer < diff)//wait 3secs for emerge anim, then attack
                {
                    WaitTimer = 3000;
                    CanStartEvent=true;//fresh fished from pool
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }else WaitTimer -= diff;
            }
            return;
        }

        if(m_creature->getThreatManager().getThreatList().empty())//check if should evade
        {
            if(m_creature->isInCombat())
                EnterEvadeMode();
            return;
        }
        if (!Submerged)
        {
            if (PhaseTimer < diff)
            {
                m_creature->InterruptNonMeleeSpells(false);
                DoCast(m_creature,SPELL_SUBMERGE);
                PhaseTimer = 60000;//60secs submerged
                Submerged = true;
            }else PhaseTimer-=diff;

            if (SpoutTimer < diff)
            {
                m_creature->MonsterTextEmote(EMOTE_SPOUT,0,true);
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveRotate(20000, rand()%2 ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
                SpoutTimer = 45000;
                WhirlTimer = 20000;//whirl directly after spout
                RotTimer = 20000;
                return;
            }else SpoutTimer -= diff;

            //Whirl directly after a Spout and at random times
            if (WhirlTimer < diff)
            {
                WhirlTimer = 18000;
                DoCast(m_creature,SPELL_WHIRL);
            }else WhirlTimer -= diff;

            if(CheckTimer < diff)//check if there are players in melee range
            {
                InRange = false;
                Map* pMap = m_creature->GetMap();
                Map::PlayerList const &PlayerList = pMap->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if(m_creature->IsWithinMeleeRange(i->getSource()))
                            InRange = true;
                    }
                }
                CheckTimer = 2000;
            }else CheckTimer -= diff;

            if(RotTimer)
            {
                Map* pMap = m_creature->GetMap();
                if (pMap->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (i->getSource() && i->getSource()->isAlive() && m_creature->HasInArc((double)diff/20000*(double)M_PI*2,i->getSource()) && m_creature->IsWithinDist(i->getSource(), SPOUT_DIST) && !i->getSource()->IsInWater())
                            DoCast(i->getSource(),SPELL_SPOUT,true);//only knock back palyers in arc, in 100yards, not in water
                    }
                }

                if(SpoutAnimTimer < diff)
                {
                    DoCast(m_creature,SPELL_SPOUT_ANIM,true);
                    SpoutAnimTimer = 1000;
                }else SpoutAnimTimer -= diff;

                if(RotTimer < diff)
                {
                    RotTimer = 0;
                }else RotTimer -= diff;
                return;
            }

            if (GeyserTimer < diff)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM,1);
                if (!target && m_creature->getVictim())
                    target = m_creature->getVictim();
                if (target)
                    DoCast(target,SPELL_GEYSER,true);
                GeyserTimer = rand()%5000 + 15000;
            }else GeyserTimer -= diff;

            if(!InRange)//if on players in melee range cast Waterbolt
            {
                if (WaterboltTimer < diff)
                {
                    Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    if (!target && m_creature->getVictim())
                        target = m_creature->getVictim();
                    if (target)
                        DoCast(target,SPELL_WATERBOLT,true);
                    WaterboltTimer = 3000;
                }else WaterboltTimer -= diff;
            }

            if (!UpdateCombatState())
                return;

            DoMeleeAttackIfReady();

        }else//submerged
        {
            if (PhaseTimer < diff)
            {
                Submerged = false;
                m_creature->InterruptNonMeleeSpells(false);//shouldn't be any
                m_creature->RemoveAllAuras();
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                m_creature->RemoveFlag(UNIT_NPC_EMOTESTATE,EMOTE_STATE_SUBMERGED);
                DoCast(m_creature,SPELL_EMERGE,true);
                Spawned = false;
                SpoutTimer = 3000; // directly cast Spout after emerging!
                PhaseTimer = 120000;
                return;
            }else PhaseTimer-=diff;

            if(m_creature->getThreatManager().getThreatList().empty())//check if should evade
            {
                EnterEvadeMode();
                return;
            }
            if (!m_creature->isInCombat())
                DoZoneInCombat();

            if (!Spawned)
            {
                m_creature->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                //spawn adds
                for (uint8 i = 0; i < 9; ++i)
                {
                    Creature* Summoned;
                    if (i < 6)
                        Summoned = m_creature->SummonCreature(MOB_COILFANG_AMBUSHER,AddPos[i][0],AddPos[i][1],AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    else Summoned = m_creature->SummonCreature(MOB_COILFANG_GUARDIAN,AddPos[i][0],AddPos[i][1],AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0);

                    if (Summoned)
                        Summons.Summon(Summoned);
                }
                Spawned = true;
            }
        }
    }
 };

CreatureAI* GetAI_mob_coilfang_guardian(Creature* pCreature)
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

struct TRINITY_DLL_DECL mob_coilfang_ambusherAI : public Scripted_NoMovementAI
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

    void EnterCombat(Unit *who)
    {

    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim()) return;

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who) && m_creature->IsWithinDistInMap(who, 45))
        {
            AttackStart(who);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (MultiShotTimer < diff)
        {
            if (m_creature->getVictim())
                DoCast(m_creature->getVictim(), SPELL_SPREAD_SHOT, true);

            MultiShotTimer = 10000+rand()%10000;
            ShootBowTimer += 1500;//add global cooldown
        }else MultiShotTimer -= diff;

        if (ShootBowTimer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            int bp0 = 1100;
            if (target)
                m_creature->CastCustomSpell(target,SPELL_SHOOT,&bp0,NULL,NULL,true);
            ShootBowTimer = 4000+rand()%5000;
            MultiShotTimer += 1500;//add global cooldown
        }else ShootBowTimer -= diff;
    }
};

CreatureAI* GetAI_mob_coilfang_ambusher(Creature* pCreature)
{
    return new mob_coilfang_ambusherAI (pCreature);
}

CreatureAI* GetAI_boss_the_lurker_below(Creature* pCreature)
{
    return new boss_the_lurker_belowAI (pCreature);
}

void AddSC_boss_the_lurker_below()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_the_lurker_below";
    newscript->GetAI = &GetAI_boss_the_lurker_below;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_coilfang_guardian";
    newscript->GetAI = &GetAI_mob_coilfang_guardian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_coilfang_ambusher";
    newscript->GetAI = &GetAI_mob_coilfang_ambusher;
    newscript->RegisterSelf();
}



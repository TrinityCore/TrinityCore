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
#include "def_serpent_shrine.h"
#include "../../../creature/simple_ai.h"
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
#define SPELL_SCALDINGWATER 37284

#define EMOTE_SPOUT "takes a deep breath."

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

enum RotationType
{
    NOROTATE = 0,
    CLOCKWISE = 1,
    COUNTERCLOCKWISE = 2,
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

    double SpoutAngle;

    uint8 RotType;

    uint32 RotTimer;
    uint32 SpoutAnimTimer;
    uint32 WaterboltTimer;
    uint32 SpoutTimer;
    uint32 WhirlTimer;//after avery spout
    uint32 PhaseTimer;
    uint32 GeyserTimer;

    void Reset()
    {
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING + MOVEMENTFLAG_LEVITATING);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetCorpseDelay(1000*60*60);

        RotType = NOROTATE;

        SpoutAngle = 0;
        SpoutAnimTimer = 1000;
        RotTimer = 20000;
        WaterboltTimer = 3000;
        SpoutTimer = 15000;
        WhirlTimer = 18000;//after avery spout
        PhaseTimer = 120000;
        GeyserTimer = rand()%5000 + 15000;

        Submerged = false;
        Spawned = false;

        Summons.DespawnAll();

        if (pInstance)
            pInstance->SetData(DATA_THELURKERBELOWEVENT, NOT_STARTED);

        /*if (pInstance->GetData(DATA_STRANGE_POOL) != DONE)
        {
            m_creature->SetReactState(REACT_PASSIVE);
            m_creature->SetVisibility(VISIBILITY_OFF);
        }else {
            m_creature->SetVisibility(VISIBILITY_ON);
            m_creature->SetReactState(REACT_AGGRESSIVE);
        }*/
    }

     void MoveInLineOfSight(Unit *who)
     {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
                AttackStart(who);
        }
     }

     void EnterCombat(Unit *who)
     {
         if (pInstance)
            pInstance->SetData(DATA_THELURKERBELOWEVENT, IN_PROGRESS);

         if (!who || m_creature->getVictim())
            return;

         if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
         {
             float attackRadius = m_creature->GetAttackDistance(who);
             if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
                 AttackStart(who);
         }
     }

     void JustDied(Unit* Killer)
     {
         if (pInstance)
            pInstance->SetData(DATA_THELURKERBELOWEVENT, DONE);

         Summons.DespawnAll();
     }

     void Rotate(const uint32 diff)
     {
         bool Spout = false;
         switch (RotType)
         {
         case NOROTATE:
             return;
         case CLOCKWISE://20secs for 360turn
             //no target if rotating!
             m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
             SpoutAngle += (double)diff/20000*(double)M_PI*2;
             if (SpoutAngle >= M_PI*2)SpoutAngle = 0;
             m_creature->SetOrientation(SpoutAngle);
             m_creature->StopMoving();
             Spout = true;
             break;
         case COUNTERCLOCKWISE://20secs for 360turn
             //no target if rotating!
             m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
             SpoutAngle -= (double)diff/20000*(double)M_PI*2;
             if (SpoutAngle <= 0)SpoutAngle = M_PI*2;
             m_creature->SetOrientation(SpoutAngle);
             m_creature->StopMoving();
             Spout = true;
             break;
         }

         if (!Spout)
             return;

         if (RotTimer<diff)//end rotate
         {
             RotType = NOROTATE;//set norotate state
             RotTimer=20000;
             m_creature->InterruptNonMeleeSpells(false);
             WhirlTimer = 4000; //whirl directly after spout ends
             return;
         }else RotTimer-=diff;

         if (SpoutAnimTimer<diff)
         {
             DoCast(m_creature,SPELL_SPOUT_ANIM,true);
             SpoutAnimTimer = 1000;
         }else SpoutAnimTimer-=diff;

         Map* pMap = m_creature->GetMap();
         if (pMap->IsDungeon() && pInstance->GetData(DATA_THELURKERBELOWEVENT) == IN_PROGRESS)
         {
             Map::PlayerList const &PlayerList = pMap->GetPlayers();
             for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
             {
                 Player *target = i->getSource();
                 if (target && target->isAlive() && m_creature->HasInArc((double)diff/20000*(double)M_PI*2,target) && m_creature->IsWithinDist(target, SPOUT_DIST) && !target->IsInWater())
                     DoCast(target,SPELL_SPOUT,true);//only knock back palyers in arc, in 100yards, not in water
             }
         }
     }

     void StartRotate(Unit* victim)
     {
         switch (rand()%2)
         {
         case 0: RotType = CLOCKWISE; break;
         case 1: RotType = COUNTERCLOCKWISE; break;
         }
         RotTimer=20000;

         if (victim)
             SpoutAngle = m_creature->GetAngle(victim);

         m_creature->MonsterTextEmote(EMOTE_SPOUT,0,true);
         //DoCast(m_creature,SPELL_SPOUT_BREATH);//take breath anim
     }

     void UpdateAI(const uint32 diff)
     {
         //Return since we have no target
         if (!UpdateVictim() /*|| !m_creature->getVictim()*/)//rotate resets target
             return;

          //Check if players in water and if in water cast spell
         Map* pMap = m_creature->GetMap();
         if (pMap->IsDungeon() && pInstance->GetData(DATA_THELURKERBELOWEVENT) == IN_PROGRESS)
         {
             Map::PlayerList const &PlayerList = pMap->GetPlayers();

             if (PlayerList.isEmpty())
                 return;

             for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
             {
                 if (i->getSource()->isAlive() && i->getSource()->IsInWater() && !i->getSource()->HasAura(SPELL_SCALDINGWATER))
                     i->getSource()->CastSpell(i->getSource(), SPELL_SCALDINGWATER, true);
                 else if (!i->getSource()->IsInWater())
                     i->getSource()->RemoveAurasDueToSpell(SPELL_SCALDINGWATER);
             }
         }

         Rotate(diff);//always check rotate things
         if (!Submerged)
         {
             if (PhaseTimer < diff)
             {
                 m_creature->InterruptNonMeleeSpells(false);
                 DoCast(m_creature,SPELL_SUBMERGE);
                 PhaseTimer = 60000;//60secs submerged
                 Submerged = true;
             }else PhaseTimer-=diff;
         }

         if (!Submerged && RotType == NOROTATE)//is not spouting and not submerged
         {
             if (SpoutTimer < diff)
             {
                 if (m_creature->getVictim() && RotType == NOROTATE)
                     StartRotate(m_creature->getVictim());//start spout and random rotate

                 SpoutTimer= 35000;
                 return;
             }else SpoutTimer -= diff;

             //Whirl directly after a Spout and at random times
             if (WhirlTimer < diff)
             {
                 WhirlTimer = rand()%5000 + 15000;
                 DoCast(m_creature,SPELL_WHIRL);
                 WaterboltTimer += 5000;//add 5secs to waterbolt timer, to add some time to run back to boss
             }else WhirlTimer -= diff;

             if (GeyserTimer < diff)
             {
                 Unit* target = NULL;
                 target = SelectUnit(SELECT_TARGET_RANDOM,1);

                 if (target)
                    DoCast(target,SPELL_GEYSER,true);
                 else
                     target = SelectUnit(SELECT_TARGET_RANDOM,0);
                 if (target)
                     DoCast(target,SPELL_GEYSER,true);

                 GeyserTimer = rand()%5000 + 15000;
             }else GeyserTimer -= diff;

             if (WaterboltTimer < diff)
             {
                 Unit* target = SelectTarget(SELECT_TARGET_NEAREST,0,14,true);
                 if (!target)
                 {
                     target = SelectUnit(SELECT_TARGET_RANDOM,0);
                     if (target)
                         DoCast(target,SPELL_WATERBOLT);
                 }
                 WaterboltTimer = 3000;
             }else WaterboltTimer -= diff;

             if (!UpdateVictim())
                return;

             DoMeleeAttackIfReady();

         }else if (!Submerged)
             return;
         else if (Submerged)//phase 2, submerged
         {
             if (PhaseTimer < diff)
             {
                 Submerged = false;
                 m_creature->InterruptNonMeleeSpells(false);//shouldn't be any
                 m_creature->RemoveAllAuras();
                 m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                 m_creature->RemoveFlag(UNIT_NPC_EMOTESTATE,EMOTE_STATE_SUBMERGED);
                 m_creature->RemoveFlag(UNIT_FIELD_BYTES_1,9);
                 DoCast(m_creature,SPELL_EMERGE);
                 Spawned = false;
                 SpoutTimer = 4000; // directly cast Spout after emerging!
                 WhirlTimer = 26000;
                 PhaseTimer = 120000;
                 return;
             }else PhaseTimer-=diff;

             if (!m_creature->isInCombat())
                 DoZoneInCombat();

             if (!Spawned)
             {
                 m_creature->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                 //spawn adds
                 for (uint8 i = 0; i < 9; ++i)
                 {
                     Creature* Summoned;
                     if (i < 7)
                         Summoned = m_creature->SummonCreature(MOB_COILFANG_AMBUSHER,AddPos[i][0],AddPos[i][1],AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                     else Summoned = m_creature->SummonCreature(MOB_COILFANG_GUARDIAN,AddPos[i][0],AddPos[i][1],AddPos[i][2], 0, TEMPSUMMON_CORPSE_DESPAWN, 0);

                     if (Summoned)
                        Summons.Summon(Summoned);
                     Spawned = true;
                 }
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

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
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

            MultiShotTimer = 10000;
            ShootBowTimer += 1500;//add global cooldown
        }else MultiShotTimer -= diff;

        if (ShootBowTimer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            int bp0 = 1100;
            if (target)
                m_creature->CastCustomSpell(target,SPELL_SHOOT,&bp0,NULL,NULL,true);
            ShootBowTimer = 4000;
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
    newscript->Name="boss_the_lurker_below";
    newscript->GetAI = &GetAI_boss_the_lurker_below;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_coilfang_guardian";
    newscript->GetAI = &GetAI_mob_coilfang_guardian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_coilfang_ambusher";
    newscript->GetAI = &GetAI_mob_coilfang_ambusher;
    newscript->RegisterSelf();
}



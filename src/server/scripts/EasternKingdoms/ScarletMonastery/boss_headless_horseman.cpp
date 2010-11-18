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
SDName: Boss_Headless_Horseman
SD%Complete:
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptPCH.h"
#include "SpellMgr.h"
#include "scarlet_monastery.h"

//this texts are already used by 3975 and 3976
#define SAY_ENTRANCE                -1189001
#define SAY_REJOINED                -1189002
#define SAY_LOST_HEAD               -1189003
#define SAY_CONFLAGRATION           -1189004
#define SAY_SPROUTING_PUMPKINS      -1189005
#define SAY_PLAYER_DEATH            -1189006
#define SAY_DEATH                   -1189007

uint32 RandomLaugh[] = {11965, 11975, 11976};

    // Entryes
#define HH_MOUNTED                  23682
#define HH_UNHORSED                 23800
#define HEAD                        23775
#define PULSING_PUMPKIN             23694
#define PUMPKIN_FIEND               23545
#define HELPER                      23686
#define WISP_INVIS                  24034

    //Spells
#define SPELL_CLEAVE                42587
#define SPELL_CONFLAGRATION         42380       //Phase 2, can't find real spell(Dim Fire?)
//#define SPELL_CONFL_SPEED         22587       //8% increase speed, value 22587 from SPELL_CONFLAGRATION mains that spell?
#define SPELL_SUMMON_PUMPKIN        42394

#define SPELL_WHIRLWIND             43116
#define SPELL_IMMUNE                42556
#define SPELL_BODY_REGEN            42403
#define SPELL_CONFUSE               43105

#define SPELL_FLYING_HEAD           42399       //visual flying head
#define SPELL_HEAD                  42413       //visual buff, "head"
#define SPELL_HEAD_IS_DEAD          42428       //at killing head, Phase 3

#define SPELL_PUMPKIN_AURA          42280
#define SPELL_PUMPKIN_AURA_GREEN    42294
#define SPELL_SQUASH_SOUL           42514
#define SPELL_SPROUTING             42281
#define SPELL_SPROUT_BODY           42285

    //Effects
#define SPELL_RHYME_BIG             42909
//#define SPELL_RHYME_SMALL         42910
#define SPELL_HEAD_SPEAKS           43129
#define SPELL_HEAD_LANDS            42400
#define SPELL_BODY_FLAME            42074
#define SPELL_HEAD_FLAME            42971
//#define SPELL_ENRAGE_VISUAL       42438       // he uses this spell?
#define SPELL_WISP_BLUE             42821
#define SPELL_WISP_FLIGHT_PORT      42818
//#define SPELL_WISP_INVIS          42823
#define SPELL_SMOKE                 42355
#define SPELL_DEATH                 42566       //not correct spell

struct Locations
{
    float x, y, z;
};

static Locations FlightPoint[]=
{
    {1754.00f,1346.00f,17.50f},
    {1765.00f,1347.00f,19.00f},
    {1784.00f,1346.80f,25.40f},
    {1803.30f,1347.60f,33.00f},
    {1824.00f,1350.00f,42.60f},
    {1838.80f,1353.20f,49.80f},
    {1852.00f,1357.60f,55.70f},
    {1861.30f,1364.00f,59.40f},
    {1866.30f,1374.80f,61.70f},
    {1864.00f,1387.30f,63.20f},
    {1854.80f,1399.40f,64.10f},
    {1844.00f,1406.90f,64.10f},
    {1824.30f,1411.40f,63.30f},
    {1801.00f,1412.30f,60.40f},
    {1782.00f,1410.10f,55.50f},
    {1770.50f,1405.20f,50.30f},
    {1765.20f,1400.70f,46.60f},
    {1761.40f,1393.40f,41.70f},
    {1759.10f,1386.70f,36.60f},
    {1757.80f,1378.20f,29.00f},
    {1758.00f,1367.00f,19.51f}
};

static Locations Spawn[]=
{
    {1776.27f,1348.74f,19.20f},        //spawn point for pumpkin shrine mob
    {1765.28f,1347.46f,17.55f}     //spawn point for smoke
};

static const char* Text[]=
{
    "Horseman rise...",
    "Your time is nigh...",
    "You felt death once...",
    "Now, know demise!"
};

#define EMOTE_LAUGHS    "Headless Horseman laughs"

class mob_wisp_invis : public CreatureScript
{
public:
    mob_wisp_invis() : CreatureScript("mob_wisp_invis") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_wisp_invisAI (pCreature);
    }

    struct mob_wisp_invisAI : public ScriptedAI
    {
        mob_wisp_invisAI(Creature *c) : ScriptedAI(c)
        {
            Creaturetype = delay = spell = spell2 = 0;
            //that's hack but there are no info about range of this spells in dbc
            SpellEntry *wisp = GET_SPELL(SPELL_WISP_BLUE);
            if (wisp)
                wisp->rangeIndex = 6; //100 yards
            SpellEntry *port = GET_SPELL(SPELL_WISP_FLIGHT_PORT);
            if (port)
                port->rangeIndex = 6;
        }

        uint32 Creaturetype;
        uint32 delay;
        uint32 spell;
        uint32 spell2;
        void Reset(){}
        void EnterCombat(Unit * /*who*/){}
        void SetType(uint32 _type)
        {
            switch(Creaturetype = _type)
            {
                case 1:
                    spell = SPELL_PUMPKIN_AURA_GREEN;
                    break;
                case 2:
                    delay = 15000;
                    spell = SPELL_BODY_FLAME;
                    spell2 = SPELL_DEATH;
                    break;
                case 3:
                    delay = 15000;
                    spell = SPELL_SMOKE;
                    break;
                case 4:
                    delay = 7000;
                    spell2 = SPELL_WISP_BLUE;
                    break;
            }
            if (spell)
                DoCast(me, spell);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_WISP_FLIGHT_PORT && Creaturetype == 4)
                me->SetDisplayId(2027);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who || Creaturetype != 1 || !who->isTargetableForAttack())
                return;

            if (me->IsWithinDist(who, 0.1f, false) && !who->HasAura(SPELL_SQUASH_SOUL))
                DoCast(who, SPELL_SQUASH_SOUL);
        }

        void UpdateAI(const uint32 diff)
        {
            if (delay)
            {
                if (delay <= diff)
                {
                    me->RemoveAurasDueToSpell(SPELL_SMOKE);
                    if (spell2)
                        DoCast(me, spell2);
                    delay = 0;
                } else delay -= diff;
            }
        }
    };

};

class mob_head : public CreatureScript
{
public:
    mob_head() : CreatureScript("mob_head") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_headAI (pCreature);
    }

    struct mob_headAI : public ScriptedAI
    {
        mob_headAI(Creature *c) : ScriptedAI(c) {}

        uint64 bodyGUID;

        uint32 Phase;
        uint32 laugh;
        uint32 wait;

        bool withbody;
        bool die;

        void Reset()
        {
            Phase = 0;
            bodyGUID = 0;
            die = false;
            withbody = true;
            wait = 1000;
            laugh = urand(15000,30000);
        }

        void EnterCombat(Unit * /*who*/) {}
        void SaySound(int32 textEntry, Unit *pTarget = 0)
        {
            DoScriptText(textEntry, me, pTarget);
            //DoCast(me, SPELL_HEAD_SPEAKS, true);
            Creature *speaker = DoSpawnCreature(HELPER,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,1000);
            if (speaker)
                speaker->CastSpell(speaker,SPELL_HEAD_SPEAKS,false);
            laugh += 3000;
        }

        void DamageTaken(Unit* /*done_by*/,uint32 &damage)
        {
            if (withbody)
                return;

            switch(Phase)
            {
                case 1:
                    if (me->HealthBelowPctDamaged(67, damage))
                        Disappear();
                    break;
                case 2:
                    if (me->HealthBelowPctDamaged(34, damage))
                        Disappear();
                    break;
                case 3:
                    if (damage >= me->GetHealth())
                    {
                        die = true;
                        withbody = true;
                        wait = 300;
                        damage = me->GetHealth() - me->CountPctFromMaxHealth(1);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->StopMoving();
                        //me->GetMotionMaster()->MoveIdle();
                        DoCast(me, SPELL_HEAD_IS_DEAD);
                    }
                    break;
            }
        }

        void SpellHit(Unit *caster, const SpellEntry* spell)
        {
            if (!withbody)
                return;

            if (spell->Id == SPELL_FLYING_HEAD)
            {
                if (Phase < 3) ++Phase;
                else Phase = 3;
                withbody = false;
                if (!bodyGUID)
                    bodyGUID = caster->GetGUID();
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_HEAD_LANDS, true);
                DoCast(me, SPELL_HEAD, false);
                SaySound(SAY_LOST_HEAD);
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveFleeing(caster->getVictim());
            }
        }

        void Disappear();
        void UpdateAI(const uint32 diff)
        {
            if (!withbody)
            {
                if (wait <= diff)
                {
                    wait = 1000;
                    if (!me->getVictim()) return;
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveFleeing(me->getVictim());
                } else wait -= diff;

                if (laugh <= diff)
                {
                    laugh = urand(15000,30000);
                    DoPlaySoundToSet(me, RandomLaugh[urand(0,2)]);
                    //DoCast(me, SPELL_HEAD_SPEAKS, true); //this spell remove buff "head"
                    Creature *speaker = DoSpawnCreature(HELPER,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,1000);
                    if (speaker)
                        speaker->CastSpell(speaker,SPELL_HEAD_SPEAKS,false);
                    me->MonsterTextEmote(EMOTE_LAUGHS,NULL);
                } else laugh -= diff;
            }
            else
            {
                if (die)
                {
                    if (wait <= diff)
                    {
                        die = false;
                        if (Unit *body = Unit::GetUnit((*me), bodyGUID))
                            body->Kill(body);
                        me->Kill(me);
                    } else wait -= diff;
                }
            }
        }
    };

};

class boss_headless_horseman : public CreatureScript
{
public:
    boss_headless_horseman() : CreatureScript("boss_headless_horseman") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_headless_horsemanAI (pCreature);
    }

    struct boss_headless_horsemanAI : public ScriptedAI
    {
        boss_headless_horsemanAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint64 headGUID;
        uint64 PlayerGUID;

        uint32 Phase;
        uint32 id;
        uint32 count;
        uint32 say_timer;

        uint32 conflagrate;
        uint32 summonadds;
        uint32 cleave;
        uint32 regen;
        uint32 whirlwind;
        uint32 laugh;
        uint32 burn;

        bool withhead;
        bool returned;
        bool IsFlying;
        bool wp_reached;
        bool burned;

        void Reset()
        {
            Phase = 1;
            conflagrate = 15000;
            summonadds = 15000;
            laugh = urand(16000,20000);
            cleave = 2000;
            regen = 1000;
            burn = 6000;
            count = 0;
            say_timer = 3000;

            withhead = true;
            returned = true;
            burned = false;
            IsFlying = false;
            DoCast(me, SPELL_HEAD);
            if (headGUID)
            {
                if (Creature* Head = Unit::GetCreature((*me), headGUID))
                    Head->DisappearAndDie();

                headGUID = 0;
            }

            //if (pInstance)
            //    pInstance->SetData(DATA_HORSEMAN_EVENT, NOT_STARTED);
        }

        void FlyMode()
        {
            me->SetVisible(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT | MOVEMENTFLAG_LEVITATING);
            me->SetSpeed(MOVE_WALK,5.0f,true);
            wp_reached = false;
            count = 0;
            say_timer = 3000;
            id = 0;
            Phase = 0;
        }

        void MovementInform(uint32 type, uint32 i)
        {
            if (type != POINT_MOTION_TYPE || !IsFlying || i != id)
                return;

            wp_reached = true;

            switch (id)
            {
                case 0:
                    me->SetVisible(true);
                    break;
                case 1:
                {
                    if (Creature *smoke = me->SummonCreature(HELPER,Spawn[1].x,Spawn[1].y,Spawn[1].z,0,TEMPSUMMON_TIMED_DESPAWN,20000))
                        CAST_AI(mob_wisp_invis::mob_wisp_invisAI, smoke->AI())->SetType(3);
                    DoCast(me, SPELL_RHYME_BIG);
                    break;
                }
                case 6:
                    if (pInstance)
                        pInstance->SetData(GAMEOBJECT_PUMPKIN_SHRINE, 0);   //hide gameobject
                    break;
                case 19:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT | MOVEMENTFLAG_LEVITATING);
                    break;
                case 20:
                {
                    Phase = 1;
                    IsFlying = false;
                    wp_reached = false;
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    SaySound(SAY_ENTRANCE);
                    if (Unit *plr = Unit::GetUnit((*me),PlayerGUID))
                        DoStartMovement(plr);
                    break;
                }
            }
            ++id;
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_HORSEMAN_EVENT, IN_PROGRESS);
            DoZoneInCombat();
        }
        void AttackStart(Unit* who) {ScriptedAI::AttackStart(who);}
        void MoveInLineOfSight(Unit *who)
        {
            if (withhead && Phase != 0)
                ScriptedAI::MoveInLineOfSight(who);
        }
        void KilledUnit(Unit *plr)
        {
            if (plr->GetTypeId() == TYPEID_PLAYER)
            {
                if (withhead)
                    SaySound(SAY_PLAYER_DEATH);
                //maybe possible when player dies from conflagration
                else if (Creature *Head = Unit::GetCreature((*me), headGUID))
                    CAST_AI(mob_head::mob_headAI, Head->AI())->SaySound(SAY_PLAYER_DEATH);
            }
        }

        void SaySound(int32 textEntry, Unit *pTarget = 0)
        {
            DoScriptText(textEntry, me, pTarget);
            laugh += 4000;
        }

        Player* SelectRandomPlayer(float range = 0.0f, bool checkLoS = true)
        {
            Map* pMap = me->GetMap();
            if (!pMap->IsDungeon()) return NULL;

            Map::PlayerList const &PlayerList = pMap->GetPlayers();
            Map::PlayerList::const_iterator i;
            if (PlayerList.isEmpty()) return NULL;

            std::list<Player*> temp;
            std::list<Player*>::const_iterator j;

            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if ((me->IsWithinLOSInMap(i->getSource()) || !checkLoS) && me->getVictim() != i->getSource() &&
                    me->IsWithinDistInMap(i->getSource(), range) && i->getSource()->isAlive())
                    temp.push_back(i->getSource());

            if (temp.size())
            {
                j = temp.begin();
                advance(j, rand()%temp.size());
                return (*j);
            }
            return NULL;
        }

        void SpellHitTarget(Unit* unit, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_CONFLAGRATION && unit->HasAura(SPELL_CONFLAGRATION))
                SaySound(SAY_CONFLAGRATION,unit);
        }

        void JustDied(Unit* /*killer*/)
        {
            me->StopMoving();
            //me->GetMotionMaster()->MoveIdle();
            SaySound(SAY_DEATH);
            if (Creature *flame = DoSpawnCreature(HELPER,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,60000))
                flame->CastSpell(flame,SPELL_BODY_FLAME,false);
            if (Creature *wisp = DoSpawnCreature(WISP_INVIS,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,60000))
                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, wisp->AI())->SetType(4);
            if (pInstance)
                pInstance->SetData(DATA_HORSEMAN_EVENT, DONE);
        }

        void SpellHit(Unit *caster, const SpellEntry* spell)
        {
            if (withhead)
                return;

            if (spell->Id == SPELL_FLYING_HEAD)
            {
                if (Phase < 3)
                    ++Phase;
                else
                    Phase = 3;
                withhead = true;
                me->RemoveAllAuras();
                me->SetName("Headless Horseman");
                me->SetFullHealth();
                SaySound(SAY_REJOINED);
                DoCast(me, SPELL_HEAD);
                caster->GetMotionMaster()->Clear(false);
                caster->GetMotionMaster()->MoveFollow(me,6,float(urand(0,5)));
                //DoResetThreat();//not sure if need
                std::list<HostileReference*>::const_iterator itr;
                for (itr = caster->getThreatManager().getThreatList().begin(); itr != caster->getThreatManager().getThreatList().end(); ++itr)
                {
                    Unit* pUnit = Unit::GetUnit((*me), (*itr)->getUnitGuid());
                    if (pUnit && pUnit->isAlive() && pUnit != caster)
                        me->AddThreat(pUnit,caster->getThreatManager().getThreat(pUnit));
                }
            }
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (damage >= me->GetHealth() && withhead)
            {
                withhead = false;
                returned = false;
                damage = me->GetHealth() - me->CountPctFromMaxHealth(1);
                me->RemoveAllAuras();
                me->SetName("Headless Horseman, Unhorsed");

                if (!headGUID)
                    headGUID = DoSpawnCreature(HEAD, float(rand()%6), float(rand()%6),0,0,TEMPSUMMON_DEAD_DESPAWN,0)->GetGUID();
                Unit* Head = Unit::GetUnit((*me), headGUID);
                if (Head && Head->isAlive())
                {
                    Head->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    //Head->CastSpell(Head,SPELL_HEAD_INVIS,false);
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_IMMUNE, true);
                    DoCast(me, SPELL_BODY_REGEN, true);
                    DoCast(Head, SPELL_FLYING_HEAD, true);
                    DoCast(me, SPELL_CONFUSE, false);                     //test
                    done_by->ProcDamageAndSpell(me,PROC_FLAG_KILL,PROC_FLAG_KILLED,PROC_EX_NONE,0);
                    whirlwind = urand(4000,8000);
                    regen = 0;
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (withhead)
            {
                switch(Phase)
                {
                    case 0:
                    {
                        if (!IsFlying)
                        {
                            if (say_timer <= diff)
                            {
                                say_timer = 3000;
                                Player *plr = SelectRandomPlayer(100.0f, false);
                                if (count < 3)
                                {
                                    if (plr)
                                        plr->Say(Text[count], 0);
                                }
                                else
                                {
                                    DoCast(me, SPELL_RHYME_BIG);
                                    if (plr)
                                    {
                                        plr->Say(Text[count], 0);
                                        plr->HandleEmoteCommand(ANIM_EMOTE_SHOUT);
                                    }
                                    wp_reached = true;
                                    IsFlying = true;
                                    count = 0;
                                    break;
                                }
                                ++count;
                            } else say_timer -= diff;
                        }
                        else
                        {
                            if (wp_reached)
                            {
                                wp_reached = false;
                                me->GetMotionMaster()->Clear(false);
                                me->GetMotionMaster()->MovePoint(id,FlightPoint[id].x,FlightPoint[id].y,FlightPoint[id].z);
                            }
                        }
                    }
                    break;
                    case 1:
                        if (burned)
                            break;
                        if (burn <= diff)
                        {
                            if (Creature *flame = me->SummonCreature(HELPER,Spawn[0].x,Spawn[0].y,Spawn[0].z,0,TEMPSUMMON_TIMED_DESPAWN,17000))
                                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, flame->AI())->SetType(2);
                            burned = true;
                        } else burn -= diff;
                        break;
                    case 2:
                        if (conflagrate <= diff)
                        {
                            if (Unit *plr = SelectRandomPlayer(30.0f))
                                DoCast(plr, SPELL_CONFLAGRATION, false);
                            conflagrate = urand(10000,16000);
                        } else conflagrate -= diff;
                        break;
                    case 3:
                        if (summonadds <= diff)
                        {
                            me->InterruptNonMeleeSpells(false);
                            DoCast(me, SPELL_SUMMON_PUMPKIN);
                            SaySound(SAY_SPROUTING_PUMPKINS);
                            summonadds = urand(25000,35000);
                        } else summonadds -= diff;
                        break;
                }

                if (laugh <= diff)
                {
                    laugh = urand(11000,22000);
                    me->MonsterTextEmote(EMOTE_LAUGHS,NULL);
                    DoPlaySoundToSet(me, RandomLaugh[rand()%3]);
                } else laugh -= diff;

                if (UpdateVictim())
                {
                    DoMeleeAttackIfReady();
                    if (cleave <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        cleave = urand(2000,6000);       //1 cleave per 2.0f-6.0fsec
                    } else cleave -= diff;
                }
            }
            else
            {
                if (regen <= diff)
                {
                    regen = 1000;                   //"body calls head"
                    if (me->IsFullHealth() && !returned)
                    {
                        if (Phase > 1)
                            --Phase;
                        else
                            Phase = 1;
                        Creature* Head = Unit::GetCreature((*me), headGUID);
                        if (Head && Head->isAlive())
                        {
                            CAST_AI(mob_head::mob_headAI, Head->AI())->Phase = Phase;
                            CAST_AI(mob_head::mob_headAI, Head->AI())->Disappear();
                        }
                        return;
                    }
                }
                else regen -= diff;

                if (whirlwind <= diff)
                {
                    whirlwind = urand(4000,8000);
                    if (urand(0,1))
                    {
                        me->RemoveAurasDueToSpell(SPELL_CONFUSE);
                        DoCast(me, SPELL_WHIRLWIND, true);
                        DoCast(me, SPELL_CONFUSE);
                    } else
                        me->RemoveAurasDueToSpell(SPELL_WHIRLWIND);
                } else whirlwind -= diff;
            }
        }
    };

};



class mob_pulsing_pumpkin : public CreatureScript
{
public:
    mob_pulsing_pumpkin() : CreatureScript("mob_pulsing_pumpkin") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_pulsing_pumpkinAI (pCreature);
    }

    struct mob_pulsing_pumpkinAI : public ScriptedAI
    {
        mob_pulsing_pumpkinAI(Creature *c) : ScriptedAI(c) {}

        bool sprouted;
        uint64 debuffGUID;

        void Reset()
        {
            float x, y, z;
            me->GetPosition(x, y, z);   //this visual aura some under ground
            me->GetMap()->CreatureRelocation(me, x,y,z + 0.35f, 0.0f);
            Despawn();
            Creature *debuff = DoSpawnCreature(HELPER,0,0,0,0,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,14500);
            if (debuff)
            {
                debuff->SetDisplayId(me->GetDisplayId());
                debuff->CastSpell(debuff,SPELL_PUMPKIN_AURA_GREEN,false);
                CAST_AI(mob_wisp_invis::mob_wisp_invisAI, debuff->AI())->SetType(1);
                debuffGUID = debuff->GetGUID();
            }
            sprouted = false;
            DoCast(me, SPELL_PUMPKIN_AURA, true);
            DoCast(me, SPELL_SPROUTING);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_STUNNED);
        }

        void EnterCombat(Unit * /*who*/){}

        void SpellHit(Unit * /*caster*/, const SpellEntry *spell)
        {
            if (spell->Id == SPELL_SPROUTING)
            {
                sprouted = true;
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_STUNNED);
                DoCast(me, SPELL_SPROUT_BODY, true);
                me->UpdateEntry(PUMPKIN_FIEND);
                DoStartMovement(me->getVictim());
            }
        }

        void Despawn()
        {
            if (!debuffGUID) return;
            Unit *debuff = Unit::GetUnit((*me),debuffGUID);
            if (debuff)
                debuff->SetVisible(false);
                debuffGUID = 0;
        }

        void JustDied(Unit * /*killer*/) { if (!sprouted) Despawn(); }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who || !who->isTargetableForAttack() || !me->IsHostileTo(who) || me->getVictim())
                return;

            me->AddThreat(who,0.0f);
            if (sprouted)
                DoStartMovement(who);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (sprouted && UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };

};

class go_loosely_turned_soil : public GameObjectScript
{
public:
    go_loosely_turned_soil() : GameObjectScript("go_loosely_turned_soil") { }

    bool OnGossipHello(Player* pPlayer, GameObject* soil)
    {
        InstanceScript* pInstance = pPlayer->GetInstanceScript();
        if (pInstance)
        {
            if (pInstance->GetData(DATA_HORSEMAN_EVENT) != NOT_STARTED)
                return true;
            pInstance->SetData(DATA_HORSEMAN_EVENT, IN_PROGRESS);
        }
    /*  if (soil->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER && plr->getLevel() > 64)
        {
            plr->PrepareQuestMenu(soil->GetGUID());
            plr->SendPreparedQuest(soil->GetGUID());
        }
        if (plr->GetQuestStatus(11405) == QUEST_STATUS_INCOMPLETE && plr->getLevel() > 64)
        { */
            pPlayer->AreaExploredOrEventHappens(11405);
            if (Creature *horseman = soil->SummonCreature(HH_MOUNTED,FlightPoint[20].x,FlightPoint[20].y,FlightPoint[20].z,0,TEMPSUMMON_MANUAL_DESPAWN,0))
            {
                CAST_AI(boss_headless_horseman::boss_headless_horsemanAI, horseman->AI())->PlayerGUID = pPlayer->GetGUID();
                CAST_AI(boss_headless_horseman::boss_headless_horsemanAI, horseman->AI())->FlyMode();
            }
        //}
        return true;
    }

};

void mob_head::mob_headAI::Disappear()
{
    if (withbody)
        return;
    if (bodyGUID)
    {
        Creature *body = Unit::GetCreature((*me), bodyGUID);
        if (body && body->isAlive())
        {
            withbody = true;
            me->RemoveAllAuras();
            body->RemoveAurasDueToSpell(SPELL_IMMUNE);//hack, SpellHit doesn't calls if body has immune aura
            DoCast(body, SPELL_FLYING_HEAD);
            me->SetFullHealth();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->MoveIdle();
            CAST_AI(boss_headless_horseman::boss_headless_horsemanAI, body->AI())->returned = true;
        }
    }
}

void AddSC_boss_headless_horseman()
{
    new boss_headless_horseman();
    new mob_head();
    new mob_pulsing_pumpkin();
    new mob_wisp_invis();
    new go_loosely_turned_soil();
}

/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Janalai
SD%Complete: 100
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "ScriptPCH.h"
#include "zulaman.h"
#include "GridNotifiers.h"

enum eEnums
{
    SAY_AGGRO                   = -1568000,
    SAY_FIRE_BOMBS              = -1568001,
    SAY_SUMMON_HATCHER          = -1568002,
    SAY_ALL_EGGS                = -1568003,
    SAY_BERSERK                 = -1568004,
    SAY_SLAY_1                  = -1568005,
    SAY_SLAY_2                  = -1568006,
    SAY_DEATH                   = -1568007,
    SAY_EVENT_STRANGERS         = -1568008,
    SAY_EVENT_FRIENDS           = -1568009,

// Jan'alai
    SPELL_FLAME_BREATH          = 43140,
    SPELL_FIRE_WALL             = 43113,
    SPELL_ENRAGE                = 44779,
    SPELL_SUMMON_PLAYERS        = 43097,
    SPELL_TELE_TO_CENTER        = 43098, // coord
    SPELL_HATCH_ALL             = 43144,
    SPELL_BERSERK               = 45078,

// -- Fire Bob Spells
    SPELL_FIRE_BOMB_CHANNEL     = 42621, // last forever
    SPELL_FIRE_BOMB_THROW       = 42628, // throw visual
    SPELL_FIRE_BOMB_DUMMY       = 42629, // bomb visual
    SPELL_FIRE_BOMB_DAMAGE      = 42630,

// --Summons
    MOB_AMANI_HATCHER           = 23818,
    MOB_HATCHLING               = 23598,   // 42493
    MOB_EGG                     = 23817,
    MOB_FIRE_BOMB               = 23920,

// -- Hatcher Spells
    SPELL_HATCH_EGG             = 42471,   // 43734
    SPELL_SUMMON_HATCHLING      = 42493,

// -- Hatchling Spells
    SPELL_FLAMEBUFFET           = 43299
};

const int area_dx = 44;
const int area_dy = 51;

float JanalainPos[1][3] =
{
    {-33.93f, 1149.27f, 19}
};

float FireWallCoords[4][4] =
{
    {-10.13f, 1149.27f, 19, 3.1415f},
    {-33.93f, 1123.90f, 19, 0.5f*3.1415f},
    {-54.80f, 1150.08f, 19, 0},
    {-33.93f, 1175.68f, 19, 1.5f*3.1415f}
};

float hatcherway[2][5][3] =
{
    {
        {-87.46f, 1170.09f, 6},
        {-74.41f, 1154.75f, 6},
        {-52.74f, 1153.32f, 19},
        {-33.37f, 1172.46f, 19},
        {-33.09f, 1203.87f, 19}
    },
    {
        {-86.57f, 1132.85f, 6},
        {-73.94f, 1146.00f, 6},
        {-52.29f, 1146.51f, 19},
        {-33.57f, 1125.72f, 19},
        {-34.29f, 1095.22f, 19}
    }
};
class boss_janalai : public CreatureScript
{
    public:

        boss_janalai()
            : CreatureScript("boss_janalai")
        {
        }

        struct boss_janalaiAI : public ScriptedAI
        {
            boss_janalaiAI(Creature* c) : ScriptedAI(c)
            {
                pInstance = c->GetInstanceScript();
            }

            InstanceScript *pInstance;

            uint32 FireBreathTimer;
            uint32 BombTimer;
            uint32 BombSequenceTimer;
            uint32 BombCount;
            uint32 HatcherTimer;
            uint32 EnrageTimer;

            bool noeggs;
            bool enraged;
            bool isBombing;

            bool isFlameBreathing;

            uint64 FireBombGUIDs[40];

            void Reset()
            {
                if (pInstance)
                    pInstance->SetData(DATA_JANALAIEVENT, NOT_STARTED);

                FireBreathTimer = 8000;
                BombTimer = 30000;
                BombSequenceTimer = 1000;
                BombCount = 0;
                HatcherTimer = 10000;
                EnrageTimer = MINUTE*5*IN_MILLISECONDS;

                noeggs = false;
                isBombing =false;
                enraged = false;

                isFlameBreathing = false;

                for (uint8 i = 0; i < 40; ++i)
                    FireBombGUIDs[i] = 0;

                HatchAllEggs(1);
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DEATH, me);

                if (pInstance)
                    pInstance->SetData(DATA_JANALAIEVENT, DONE);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (pInstance)
                    pInstance->SetData(DATA_JANALAIEVENT, IN_PROGRESS);

                DoScriptText(SAY_AGGRO, me);
        //        DoZoneInCombat();
            }

            void DamageDealt(Unit* pTarget, uint32 &damage, DamageEffectType /*damagetype*/)
            {
                if (isFlameBreathing)
                {
                    if (!me->HasInArc(M_PI/6, pTarget))
                        damage = 0;
                }
            }

            void FireWall()
            {
                uint8 WallNum;
                Creature* wall = NULL;
                for (uint8 i = 0; i < 4; ++i)
                {
                    if (i == 0 || i == 2)
                        WallNum = 3;
                    else
                        WallNum = 2;

                    for (uint8 j = 0; j < WallNum; j++)
                    {
                        if (WallNum == 3)
                            wall = me->SummonCreature(MOB_FIRE_BOMB, FireWallCoords[i][0], FireWallCoords[i][1]+5*(j-1), FireWallCoords[i][2], FireWallCoords[i][3], TEMPSUMMON_TIMED_DESPAWN, 15000);
                        else
                            wall = me->SummonCreature(MOB_FIRE_BOMB, FireWallCoords[i][0]-2+4*j, FireWallCoords[i][1], FireWallCoords[i][2], FireWallCoords[i][3], TEMPSUMMON_TIMED_DESPAWN, 15000);
                        if (wall) wall->CastSpell(wall, SPELL_FIRE_WALL, true);
                    }
                }
            }

            void SpawnBombs()
            {
                float dx, dy;
                for (int i(0); i < 40; ++i)
                {
                    dx = float(irand(-area_dx/2, area_dx/2));
                    dy = float(irand(-area_dy/2, area_dy/2));

                    Creature* bomb = DoSpawnCreature(MOB_FIRE_BOMB, dx, dy, 0, 0, TEMPSUMMON_TIMED_DESPAWN, 15000);
                    if (bomb) FireBombGUIDs[i] = bomb->GetGUID();
                }
                BombCount = 0;
            }

            bool HatchAllEggs(uint32 uiAction) //1: reset, 2: isHatching all
            {
                std::list<Creature*> templist;
                float x, y, z;
                me->GetPosition(x, y, z);

                {
                    CellPair pair(Trinity::ComputeCellPair(x, y));
                    Cell cell(pair);
                    cell.data.Part.reserved = ALL_DISTRICT;
                    cell.SetNoCreate();

                    Trinity::AllCreaturesOfEntryInRange check(me, MOB_EGG, 100);
                    Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, templist, check);

                    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);

                    cell.Visit(pair, cSearcher, *(me->GetMap()));
                }

                //sLog->outError("Eggs %d at middle", templist.size());
                if (templist.empty())
                    return false;

                for (std::list<Creature*>::const_iterator i = templist.begin(); i != templist.end(); ++i)
                {
                    if (uiAction == 1)
                       (*i)->SetDisplayId(10056);
                    else if (uiAction == 2 &&(*i)->GetDisplayId() != 11686)
                       (*i)->CastSpell(*i, SPELL_HATCH_EGG, false);
                }
                return true;
            }

            void Boom()
            {
                std::list<Creature*> templist;
                float x, y, z;
                me->GetPosition(x, y, z);

                {
                    CellPair pair(Trinity::ComputeCellPair(x, y));
                    Cell cell(pair);
                    cell.data.Part.reserved = ALL_DISTRICT;
                    cell.SetNoCreate();

                    Trinity::AllCreaturesOfEntryInRange check(me, MOB_FIRE_BOMB, 100);
                    Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, templist, check);

                    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);

                    cell.Visit(pair, cSearcher, *(me->GetMap()));
                }
                for (std::list<Creature*>::const_iterator i = templist.begin(); i != templist.end(); ++i)
                {
                   (*i)->CastSpell(*i, SPELL_FIRE_BOMB_DAMAGE, true);
                   (*i)->RemoveAllAuras();
                }
            }

            void HandleBombSequence()
            {
                if (BombCount < 40)
                {
                    if (Unit* FireBomb = Unit::GetUnit((*me), FireBombGUIDs[BombCount]))
                    {
                        FireBomb->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DoCast(FireBomb, SPELL_FIRE_BOMB_THROW, true);
                        FireBomb->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    ++BombCount;
                    if (BombCount == 40)
                    {
                        BombSequenceTimer = 5000;
                    } else BombSequenceTimer = 100;
                }
                else
                {
                    Boom();
                    isBombing = false;
                    BombTimer = urand(20000, 40000);
                    me->RemoveAurasDueToSpell(SPELL_FIRE_BOMB_CHANNEL);
                    if (EnrageTimer <= 10000)
                        EnrageTimer = 0;
                    else
                        EnrageTimer -= 10000;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (isFlameBreathing)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                        isFlameBreathing = false;
                    else
                        return;
                }

                if (isBombing)
                {
                    if (BombSequenceTimer <= diff)
                        HandleBombSequence();
                    else
                        BombSequenceTimer -= diff;
                    return;
                }

                if (!UpdateVictim())
                    return;

                //enrage if under 25% hp before 5 min.
                if (!enraged && HealthBelowPct(25))
                    EnrageTimer = 0;

                if (EnrageTimer <= diff)
                {
                    if (!enraged)
                    {
                        DoCast(me, SPELL_ENRAGE, true);
                        enraged = true;
                        EnrageTimer = 300000;
                    }
                    else
                    {
                        DoScriptText(SAY_BERSERK, me);
                        DoCast(me, SPELL_BERSERK, true);
                        EnrageTimer = 300000;
                    }
                } else EnrageTimer -= diff;

                if (BombTimer <= diff)
                {
                    DoScriptText(SAY_FIRE_BOMBS, me);

                    me->AttackStop();
                    me->GetMotionMaster()->Clear();
                    DoTeleportTo(JanalainPos[0][0], JanalainPos[0][1], JanalainPos[0][2]);
                    me->StopMoving();
                    DoCast(me, SPELL_FIRE_BOMB_CHANNEL, false);
                    //DoTeleportPlayer(me, JanalainPos[0][0], JanalainPos[0][1], JanalainPos[0][2], 0);
                    //DoCast(me, SPELL_TELE_TO_CENTER, true);

                    FireWall();
                    SpawnBombs();
                    isBombing = true;
                    BombSequenceTimer = 100;

                    //Teleport every Player into the middle
                    Map* pMap = me->GetMap();
                    if (!pMap->IsDungeon()) return;
                    Map::PlayerList const &PlayerList = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        if (Player* i_pl = i->getSource())
                            if (i_pl->isAlive())
                                DoTeleportPlayer(i_pl, JanalainPos[0][0]-5+rand()%10, JanalainPos[0][1]-5+rand()%10, JanalainPos[0][2], 0);
                    //DoCast(Temp, SPELL_SUMMON_PLAYERS, true) // core bug, spell does not work if too far
                    return;
                } else BombTimer -= diff;

                if (!noeggs)
                {
                    if (HealthBelowPct(35))
                    {
                        DoScriptText(SAY_ALL_EGGS, me);

                        me->AttackStop();
                        me->GetMotionMaster()->Clear();
                        DoTeleportTo(JanalainPos[0][0], JanalainPos[0][1], JanalainPos[0][2]);
                        me->StopMoving();
                        DoCast(me, SPELL_HATCH_ALL, false);
                        HatchAllEggs(2);
                        noeggs = true;
                    }
                    else if (HatcherTimer <= diff)
                    {
                        if (HatchAllEggs(0))
                        {
                            DoScriptText(SAY_SUMMON_HATCHER, me);
                            me->SummonCreature(MOB_AMANI_HATCHER, hatcherway[0][0][0], hatcherway[0][0][1], hatcherway[0][0][2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                            me->SummonCreature(MOB_AMANI_HATCHER, hatcherway[1][0][0], hatcherway[1][0][1], hatcherway[1][0][2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                            HatcherTimer = 90000;
                        }
                        else
                            noeggs = true;
                    } else HatcherTimer -= diff;
                }

                EnterEvadeIfOutOfCombatArea(diff);

                DoMeleeAttackIfReady();

                if (FireBreathTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        me->AttackStop();
                        me->GetMotionMaster()->Clear();
                        DoCast(pTarget, SPELL_FLAME_BREATH, false);
                        me->StopMoving();
                        isFlameBreathing = true;
                    }
                    FireBreathTimer = 8000;
                } else FireBreathTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_janalaiAI(creature);
        }
};

class mob_janalai_firebomb : public CreatureScript
{
    public:

        mob_janalai_firebomb()
            : CreatureScript("mob_janalai_firebomb")
        {
        }

        struct mob_janalai_firebombAI : public ScriptedAI
        {
            mob_janalai_firebombAI(Creature* c) : ScriptedAI(c){}

            void Reset() {}

            void SpellHit(Unit* /*caster*/, const SpellEntry *spell)
            {
                if (spell->Id == SPELL_FIRE_BOMB_THROW)
                    DoCast(me, SPELL_FIRE_BOMB_DUMMY, true);
            }

            void EnterCombat(Unit* /*who*/) {}

            void AttackStart(Unit* /*who*/) {}

            void MoveInLineOfSight(Unit* /*who*/) {}

            void UpdateAI(const uint32 /*diff*/) {}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_janalai_firebombAI(creature);
        }
};

class mob_janalai_hatcher : public CreatureScript
{
    public:

        mob_janalai_hatcher()
            : CreatureScript("mob_janalai_hatcher")
        {
        }

        struct mob_janalai_hatcherAI : public ScriptedAI
        {
            mob_janalai_hatcherAI(Creature* c) : ScriptedAI(c)
            {
                pInstance =c->GetInstanceScript();
            }

            InstanceScript *pInstance;

            uint32 waypoint;
            uint32 HatchNum;
            uint32 WaitTimer;

            bool side;
            bool hasChangedSide;
            bool isHatching;

            void Reset()
            {
                me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                side =(me->GetPositionY() < 1150);
                waypoint = 0;
                isHatching = false;
                hasChangedSide = false;
                WaitTimer = 1;
                HatchNum = 0;
            }

            bool HatchEggs(uint32 num)
            {
                std::list<Creature*> templist;
                float x, y, z;
                me->GetPosition(x, y, z);

                {
                    CellPair pair(Trinity::ComputeCellPair(x, y));
                    Cell cell(pair);
                    cell.data.Part.reserved = ALL_DISTRICT;
                    cell.SetNoCreate();

                    Trinity::AllCreaturesOfEntryInRange check(me, 23817, 50);
                    Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, templist, check);

                    TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange>, GridTypeMapContainer> cSearcher(searcher);

                    cell.Visit(pair, cSearcher, *(me->GetMap()));
                }

                //sLog->outError("Eggs %d at %d", templist.size(), side);

                for (std::list<Creature*>::const_iterator i = templist.begin(); i != templist.end() && num > 0; ++i)
                    if ((*i)->GetDisplayId() != 11686)
                    {
                       (*i)->CastSpell(*i, SPELL_HATCH_EGG, false);
                        num--;
                    }

                return num == 0;   // if num == 0, no more templist
            }

            void EnterCombat(Unit* /*who*/) {}
            void AttackStart(Unit* /*who*/) {}
            void MoveInLineOfSight(Unit* /*who*/) {}
            void MovementInform(uint32, uint32)
            {
                if (waypoint == 5)
                {
                    isHatching = true;
                    HatchNum = 1;
                    WaitTimer = 5000;
                }
                else
                    WaitTimer = 1;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!pInstance || !(pInstance->GetData(DATA_JANALAIEVENT) == IN_PROGRESS))
                {
                    me->DisappearAndDie();
                    return;
                }

                if (!isHatching)
                {
                    if (WaitTimer)
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, hatcherway[side][waypoint][0], hatcherway[side][waypoint][1], hatcherway[side][waypoint][2]);
                        ++waypoint;
                        WaitTimer = 0;
                    }
                }
                else
                {
                    if (WaitTimer <= diff)
                    {
                        if (HatchEggs(HatchNum))
                        {
                            ++HatchNum;
                            WaitTimer = 10000;
                        }
                        else if (!hasChangedSide)
                        {
                            side = side ? 0 : 1;
                            isHatching = false;
                            waypoint = 3;
                            WaitTimer = 1;
                            hasChangedSide = true;
                        }
                        else
                            me->DisappearAndDie();

                    } else WaitTimer -= diff;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_janalai_hatcherAI(creature);
        }
};

class mob_janalai_hatchling : public CreatureScript
{
    public:

        mob_janalai_hatchling()
            : CreatureScript("mob_janalai_hatchling")
        {
        }

        struct mob_janalai_hatchlingAI : public ScriptedAI
        {
            mob_janalai_hatchlingAI(Creature* c) : ScriptedAI(c)
            {
                pInstance =c->GetInstanceScript();
            }

            InstanceScript *pInstance;
            uint32 BuffetTimer;

            void Reset()
            {
                BuffetTimer = 7000;
                if (me->GetPositionY() > 1150)
                    me->GetMotionMaster()->MovePoint(0, hatcherway[0][3][0]+rand()%4-2, 1150.0f+rand()%4-2, hatcherway[0][3][2]);
                else
                    me->GetMotionMaster()->MovePoint(0, hatcherway[1][3][0]+rand()%4-2, 1150.0f+rand()%4-2, hatcherway[1][3][2]);

                me->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
            }

            void EnterCombat(Unit* /*who*/) {/*DoZoneInCombat();*/}

            void UpdateAI(const uint32 diff)
            {
                if (!pInstance || !(pInstance->GetData(DATA_JANALAIEVENT) == IN_PROGRESS))
                {
                    me->DisappearAndDie();
                    return;
                }

                if (!UpdateVictim())
                    return;

                if (BuffetTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_FLAMEBUFFET, false);
                    BuffetTimer = 10000;
                } else BuffetTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_janalai_hatchlingAI(creature);
        }
};

class mob_janalai_egg : public CreatureScript
{
public:
    mob_janalai_egg(): CreatureScript("mob_janalai_egg") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_janalai_eggAI(creature);
    }

    struct mob_janalai_eggAI : public ScriptedAI
    {
        mob_janalai_eggAI(Creature* creature) : ScriptedAI(creature){}

        void Reset() {}

        void UpdateAI(uint32 const /*diff*/) {}

        void SpellHit(Unit* /*caster*/, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_HATCH_EGG)
            {
                DoCast(SPELL_SUMMON_HATCHLING);
            }
        }
    };

};

void AddSC_boss_janalai()
{
    new boss_janalai();
    new mob_janalai_firebomb();
    new mob_janalai_hatcher();
    new mob_janalai_hatchling();
    new mob_janalai_egg();
}


/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ahnkahet.h"

enum Spells
{
    SPELL_BLOODTHIRST                             = 55968, // Trigger Spell + add aura
    SPELL_CONJURE_FLAME_SPHERE                    = 55931,
    SPELL_FLAME_SPHERE_SUMMON_1                   = 55895, // 1x 30106
    H_SPELL_FLAME_SPHERE_SUMMON_1                 = 59511, // 1x 31686
    H_SPELL_FLAME_SPHERE_SUMMON_2                 = 59512, // 1x 31687
    SPELL_FLAME_SPHERE_SPAWN_EFFECT               = 55891,
    SPELL_FLAME_SPHERE_VISUAL                     = 55928,
    SPELL_FLAME_SPHERE_PERIODIC                   = 55926,
    H_SPELL_FLAME_SPHERE_PERIODIC                 = 59508,
    SPELL_FLAME_SPHERE_DEATH_EFFECT               = 55947,
    SPELL_BEAM_VISUAL                             = 60342,
    SPELL_EMBRACE_OF_THE_VAMPYR                   = 55959,
    H_SPELL_EMBRACE_OF_THE_VAMPYR                 = 59513,
    SPELL_VANISH                                  = 55964,
    CREATURE_FLAME_SPHERE                         = 30106,
    H_CREATURE_FLAME_SPHERE_1                     = 31686,
    H_CREATURE_FLAME_SPHERE_2                     = 31687,
    SPELL_HOVER_FALL                              = 60425
};

enum Misc
{
    DATA_EMBRACE_DMG                              = 20000,
    H_DATA_EMBRACE_DMG                            = 40000,
    DATA_SPHERE_DISTANCE                          = 15
};

#define DATA_SPHERE_ANGLE_OFFSET                    0.7f
#define DATA_GROUND_POSITION_Z                      11.30809f

enum Yells
{
    SAY_1                                         = 0,
    SAY_WARNING                                   = 1,
    SAY_AGGRO                                     = 2,
    SAY_SLAY                                      = 3,
    SAY_DEATH                                     = 4,
    SAY_FEED                                      = 5,
    SAY_VANISH                                    = 6
};
enum CombatPhase
{
    NORMAL,
    CASTING_FLAME_SPHERES,
    JUST_VANISHED,
    VANISHED,
    FEEDING
};
enum GameObjects
{
    GO_SPHERE1                                    = 193093,
    GO_SPHERE2                                    = 193094
};

class boss_taldaram : public CreatureScript
{
public:
    boss_taldaram() : CreatureScript("boss_taldaram") { }

    struct boss_taldaramAI : public ScriptedAI
    {
        boss_taldaramAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->SetDisableGravity(true);
        }

        uint32 uiBloodthirstTimer;
        uint32 uiVanishTimer;
        uint32 uiWaitTimer;
        uint32 uiEmbraceTimer;
        uint32 uiEmbraceTakenDamage;
        uint32 uiFlamesphereTimer;
        uint32 uiPhaseTimer;

        uint64 uiEmbraceTarget;

        CombatPhase Phase;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiBloodthirstTimer = 10*IN_MILLISECONDS;
            uiVanishTimer = urand(25*IN_MILLISECONDS, 35*IN_MILLISECONDS);
            uiEmbraceTimer = 20*IN_MILLISECONDS;
            uiFlamesphereTimer = 5*IN_MILLISECONDS;
            uiEmbraceTakenDamage = 0;
            Phase = NORMAL;
            uiPhaseTimer = 0;
            uiEmbraceTarget = 0;
            if (instance)
                instance->SetData(DATA_PRINCE_TALDARAM_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (instance)
                instance->SetData(DATA_PRINCE_TALDARAM_EVENT, IN_PROGRESS);
            Talk(SAY_AGGRO);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;
            if (uiPhaseTimer <= diff)
            {
                switch (Phase)
                {
                    case CASTING_FLAME_SPHERES:
                    {
                        Creature* pSpheres[3];

                        //DoCast(me, SPELL_FLAME_SPHERE_SUMMON_1);
                        pSpheres[0] = DoSpawnCreature(CREATURE_FLAME_SPHERE, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10*IN_MILLISECONDS);
                        Unit* pSphereTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                        if (pSphereTarget && pSpheres[0])
                        {
                            float angle, x, y;
                            angle = pSpheres[0]->GetAngle(pSphereTarget);
                            x = pSpheres[0]->GetPositionX() + DATA_SPHERE_DISTANCE * std::cos(angle);
                            y = pSpheres[0]->GetPositionY() + DATA_SPHERE_DISTANCE * std::sin(angle);
                            pSpheres[0]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[0]->GetPositionZ());
                        }
                        if (IsHeroic())
                        {
                            //DoCast(me, H_SPELL_FLAME_SPHERE_SUMMON_1);
                            pSpheres[1] = DoSpawnCreature(H_CREATURE_FLAME_SPHERE_1, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10*IN_MILLISECONDS);
                            //DoCast(me, H_SPELL_FLAME_SPHERE_SUMMON_2);
                            pSpheres[2] = DoSpawnCreature(H_CREATURE_FLAME_SPHERE_2, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10*IN_MILLISECONDS);
                            if (pSphereTarget && pSpheres[1] && pSpheres[2])
                            {
                                float angle, x, y;
                                angle = pSpheres[1]->GetAngle(pSphereTarget) + DATA_SPHERE_ANGLE_OFFSET;
                                x = pSpheres[1]->GetPositionX() + DATA_SPHERE_DISTANCE/2 * std::cos(angle);
                                y = pSpheres[1]->GetPositionY() + DATA_SPHERE_DISTANCE/2 * std::sin(angle);
                                pSpheres[1]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[1]->GetPositionZ());
                                angle = pSpheres[2]->GetAngle(pSphereTarget) - DATA_SPHERE_ANGLE_OFFSET;
                                x = pSpheres[2]->GetPositionX() + DATA_SPHERE_DISTANCE/2 * std::cos(angle);
                                y = pSpheres[2]->GetPositionY() + DATA_SPHERE_DISTANCE/2 * std::sin(angle);
                                pSpheres[2]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[2]->GetPositionZ());
                            }
                        }

                        Phase = NORMAL;
                        uiPhaseTimer = 0;
                        break;
                    }
                    case JUST_VANISHED:
                        if (Unit* pEmbraceTarget = GetEmbraceTarget())
                        {
                            me->GetMotionMaster()->Clear();
                            me->SetSpeed(MOVE_WALK, 2.0f, true);
                            me->GetMotionMaster()->MoveChase(pEmbraceTarget);
                        }
                        Phase = VANISHED;
                        uiPhaseTimer = 1300;
                        break;
                    case VANISHED:
                        if (Unit* pEmbraceTarget = GetEmbraceTarget())
                            DoCast(pEmbraceTarget, DUNGEON_MODE(SPELL_EMBRACE_OF_THE_VAMPYR, H_SPELL_EMBRACE_OF_THE_VAMPYR));
                        Talk(SAY_FEED);
                        me->GetMotionMaster()->Clear();
                        me->SetSpeed(MOVE_WALK, 1.0f, true);
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        Phase = FEEDING;
                        uiPhaseTimer = 20*IN_MILLISECONDS;
                        break;
                    case FEEDING:
                        Phase = NORMAL;
                        uiPhaseTimer = 0;
                        uiEmbraceTarget = 0;
                        break;
                    case NORMAL:
                        if (uiBloodthirstTimer <= diff)
                        {
                            DoCast(me, SPELL_BLOODTHIRST);
                            uiBloodthirstTimer = 10*IN_MILLISECONDS;
                        } else uiBloodthirstTimer -= diff;

                        if (uiFlamesphereTimer <= diff)
                        {
                            // because TARGET_UNIT_TARGET_ENEMY we need a target selected to cast
                            DoCastVictim(SPELL_CONJURE_FLAME_SPHERE);
                            Phase = CASTING_FLAME_SPHERES;
                            uiPhaseTimer = 3*IN_MILLISECONDS + diff;
                            uiFlamesphereTimer = 15*IN_MILLISECONDS;
                        } else uiFlamesphereTimer -= diff;

                        if (uiVanishTimer <= diff)
                        {
                            //Count alive players
                            Unit* target = NULL;
                            std::list<HostileReference*> t_list = me->getThreatManager().getThreatList();
                            std::vector<Unit*> target_list;
                            for (std::list<HostileReference*>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                            {
                                target = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                // exclude pets & totems
                                if (target && target->GetTypeId() == TYPEID_PLAYER && target->IsAlive())
                                    target_list.push_back(target);
                                target = NULL;
                            }
                            //He only vanishes if there are 3 or more alive players
                            if (target_list.size() > 2)
                            {
                                Talk(SAY_VANISH);
                                DoCast(me, SPELL_VANISH);
                                Phase = JUST_VANISHED;
                                uiPhaseTimer = 500;
                                if (Unit* pEmbraceTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                    uiEmbraceTarget = pEmbraceTarget->GetGUID();

                            }
                            uiVanishTimer = urand(25*IN_MILLISECONDS, 35*IN_MILLISECONDS);
                        } else uiVanishTimer -= diff;

                        DoMeleeAttackIfReady();
                    break;
                }
            } else uiPhaseTimer -= diff;
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) OVERRIDE
        {
            Unit* pEmbraceTarget = GetEmbraceTarget();

            if (Phase == FEEDING && pEmbraceTarget && pEmbraceTarget->IsAlive())
            {
              uiEmbraceTakenDamage += damage;
              if (uiEmbraceTakenDamage > (uint32) DUNGEON_MODE(DATA_EMBRACE_DMG, H_DATA_EMBRACE_DMG))
              {
                  Phase = NORMAL;
                  uiPhaseTimer = 0;
                  uiEmbraceTarget = 0;
                  me->CastStop();
              }
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_PRINCE_TALDARAM_EVENT, DONE);
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Unit* pEmbraceTarget = GetEmbraceTarget();
            if (Phase == FEEDING && pEmbraceTarget && victim == pEmbraceTarget)
            {
                Phase = NORMAL;
                uiPhaseTimer = 0;
                uiEmbraceTarget = 0;
            }
            Talk(SAY_SLAY);
        }

        bool CheckSpheres()
        {
            if (!instance)
                return false;

            uint64 uiSphereGuids[2];
            uiSphereGuids[0] = instance->GetData64(DATA_SPHERE1);
            uiSphereGuids[1] = instance->GetData64(DATA_SPHERE2);

            for (uint8 i=0; i < 2; ++i)
            {
                GameObject* pSpheres = instance->instance->GetGameObject(uiSphereGuids[i]);
                if (!pSpheres)
                    return false;
                if (pSpheres->GetGoState() != GO_STATE_ACTIVE)
                    return false;
            }
            RemovePrison();
            return true;
        }

        Unit* GetEmbraceTarget()
        {
            if (!uiEmbraceTarget)
                return NULL;

            return Unit::GetUnit(*me, uiEmbraceTarget);
        }

        void RemovePrison()
        {
            if (!instance)
                return;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAurasDueToSpell(SPELL_BEAM_VISUAL);
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), DATA_GROUND_POSITION_Z, me->GetOrientation());
            DoCast(SPELL_HOVER_FALL);
            me->SetDisableGravity(false);
            me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
            Talk(SAY_WARNING);
            uint64 prison_GUID = instance->GetData64(DATA_PRINCE_TALDARAM_PLATFORM);
            instance->HandleGameObject(prison_GUID, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_taldaramAI(creature);
    }
};

class npc_taldaram_flamesphere : public CreatureScript
{
public:
    npc_taldaram_flamesphere() : CreatureScript("npc_taldaram_flamesphere") { }

    struct npc_taldaram_flamesphereAI : public ScriptedAI
    {
        npc_taldaram_flamesphereAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiDespawnTimer;
        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->setFaction(16);
            me->SetObjectScale(1.0f);
            DoCast(me, SPELL_FLAME_SPHERE_VISUAL);
            DoCast(me, SPELL_FLAME_SPHERE_SPAWN_EFFECT);
            DoCast(me, SPELL_FLAME_SPHERE_PERIODIC);
            uiDespawnTimer = 10*IN_MILLISECONDS;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}


        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (uiDespawnTimer <= diff)
                me->DisappearAndDie();
            else
                uiDespawnTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_taldaram_flamesphereAI(creature);
    }
};

class prince_taldaram_sphere : public GameObjectScript
{
public:
    prince_taldaram_sphere() : GameObjectScript("prince_taldaram_sphere") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go) OVERRIDE
    {
        InstanceScript* instance = go->GetInstanceScript();
        if (!instance)
            return true;

        Creature* pPrinceTaldaram = Unit::GetCreature(*go, instance->GetData64(DATA_PRINCE_TALDARAM));
        if (pPrinceTaldaram && pPrinceTaldaram->IsAlive())
        {
            // maybe these are hacks :(
            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            go->SetGoState(GO_STATE_ACTIVE);

            switch (go->GetEntry())
            {
                case GO_SPHERE1:
                    instance->SetData(DATA_SPHERE1_EVENT, IN_PROGRESS);
                    pPrinceTaldaram->AI()->Talk(SAY_1);
                    break;

                case GO_SPHERE2:
                    instance->SetData(DATA_SPHERE2_EVENT, IN_PROGRESS);
                    pPrinceTaldaram->AI()->Talk(SAY_1);
                    break;
            }

            CAST_AI(boss_taldaram::boss_taldaramAI, pPrinceTaldaram->AI())->CheckSpheres();
        }
        return true;
    }
};

void AddSC_boss_taldaram()
{
    new boss_taldaram();
    new npc_taldaram_flamesphere();
    new prince_taldaram_sphere();
}

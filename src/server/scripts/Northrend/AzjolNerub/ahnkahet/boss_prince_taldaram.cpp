/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ahnkahet.h"

#define DATA_SPHERE_ANGLE_OFFSET    0.7f
#define DATA_GROUND_POSITION_Z      11.4f

enum Spells
{
    SPELL_BLOODTHIRST               = 55968, // Trigger Spell + add aura
    SPELL_CONJURE_FLAME_SPHERE      = 55931,
    SPELL_FLAME_SPHERE_SUMMON_1     = 55895, // 1x 30106
    H_SPELL_FLAME_SPHERE_SUMMON_1   = 59511, // 1x 31686
    H_SPELL_FLAME_SPHERE_SUMMON_2   = 59512, // 1x 31687
    SPELL_FLAME_SPHERE_SPAWN_EFFECT = 55891,
    SPELL_FLAME_SPHERE_VISUAL       = 55928,
    SPELL_FLAME_SPHERE_PERIODIC     = 55926,
    H_SPELL_FLAME_SPHERE_PERIODIC   = 59508,
    SPELL_FLAME_SPHERE_DEATH_EFFECT = 55947,
    SPELL_BEAM_VISUAL               = 60342,
    SPELL_EMBRACE_OF_THE_VAMPYR     = 55959,
    H_SPELL_EMBRACE_OF_THE_VAMPYR   = 59513,
    SPELL_VANISH                    = 55964,
    CREATURE_FLAME_SPHERE           = 30106,
    H_CREATURE_FLAME_SPHERE_1       = 31686,
    H_CREATURE_FLAME_SPHERE_2       = 31687
};

enum Misc
{
    DATA_EMBRACE_DMG        = 20000,
    H_DATA_EMBRACE_DMG      = 40000,
    DATA_SPHERE_DISTANCE    = 20,
    SPHERE_MODEL            = 26767
};

enum Yells
{
    SAY_AGGRO       = -1619021,
    SAY_SLAY_1      = -1619022,
    SAY_SLAY_2      = -1619023,
    SAY_DEATH       = -1619024,
    SAY_FEED_1      = -1619025,
    SAY_FEED_2      = -1619026,
    SAY_VANISH_1    = -1619027,
    SAY_VANISH_2    = -1619028
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
    GO_SPHERE1  = 193093,
    GO_SPHERE2  = 193094
};

class boss_taldaram : public CreatureScript
{
public:
    boss_taldaram() : CreatureScript("boss_taldaram") { }

    struct boss_taldaramAI : public ScriptedAI
    {
        boss_taldaramAI(Creature * c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->AddAura(SPELL_BEAM_VISUAL, me);
        }

        void Reset()
        {
            uiBloodthirstTimer = 5 * IN_MILLISECONDS;
            uiVanishTimer = urand(25 * IN_MILLISECONDS, 35 * IN_MILLISECONDS);
            uiEmbraceTimer = SEKUNDEN_20;
            uiFlamesphereTimer = SEKUNDEN_10;
            uiEmbraceTakenDamage = 0;
            Phase = NORMAL;
            uiPhaseTimer = 0;
            uiEmbraceTarget = 0;
            health = 0;

            if (pInstance)
                pInstance->SetData(DATA_PRINCE_TALDARAM_EVENT, NOT_STARTED);

            if (!CheckSpheres())
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_PRINCE_TALDARAM_EVENT, IN_PROGRESS);

            DoScriptText(SAY_AGGRO, me);

            DoZoneInCombat();
        }

        void DamageTaken(Unit * /*done_by*/, uint32 & damage)
        {
            Unit * pEmbraceTarget = GetEmbraceTarget();

            if (Phase == FEEDING && pEmbraceTarget && pEmbraceTarget->isAlive())
            {
                uiEmbraceTakenDamage += damage;
                if (uiEmbraceTakenDamage > uint32(DUNGEON_MODE(DATA_EMBRACE_DMG, H_DATA_EMBRACE_DMG)))
                {
                    Phase = NORMAL;
                    uiPhaseTimer = 0;
                    uiEmbraceTarget = 0;
                    me->CastStop();
                }
            }
        }

        void JustDied(Unit * /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_PRINCE_TALDARAM_EVENT, DONE);
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;

            Unit * pEmbraceTarget = GetEmbraceTarget();
            if (Phase == FEEDING && pEmbraceTarget && victim == pEmbraceTarget)
            {
                Phase = NORMAL;
                uiPhaseTimer = 0;
                uiEmbraceTarget = 0;
            }
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        bool CheckSpheres()
        {
            if (!pInstance)
                return false;

            uint64 uiSphereGuids[2];
            uiSphereGuids[0] = pInstance->GetData64(DATA_SPHERE1);
            uiSphereGuids[1] = pInstance->GetData64(DATA_SPHERE2);

            for (uint8 i=0; i<2; ++i)
            {
                GameObject * pSpheres = pInstance->instance->GetGameObject(uiSphereGuids[i]);
                if (!pSpheres)
                    return false;

                if (pSpheres->GetGoState() != GO_STATE_ACTIVE)
                    return false;
            }
            RemovePrison();
            return true;
        }

        Unit * GetEmbraceTarget()
        {
            if (!uiEmbraceTarget)
                return NULL;

            return Unit::GetUnit(*me, uiEmbraceTarget);
        }

        void RemovePrison()
        {
            if (!pInstance)
                return;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAurasDueToSpell(SPELL_BEAM_VISUAL);
            me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), DATA_GROUND_POSITION_Z, me->GetOrientation());
            me->GetMotionMaster()->MoveTargetedHome();
            uint64 prison_GUID = pInstance->GetData64(DATA_PRINCE_TALDARAM_PLATFORM);
            pInstance->HandleGameObject(prison_GUID, true);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiPhaseTimer <= diff)
            {
                switch (Phase)
                {
                    case CASTING_FLAME_SPHERES:
                    {
                        Creature * pSpheres[3];

                        //DoCast(me, SPELL_FLAME_SPHERE_SUMMON_1, true);
                        pSpheres[0] = DoSpawnCreature(CREATURE_FLAME_SPHERE, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, SEKUNDEN_10);

                        Unit * pSphereTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                        float angle, x, y;

                        if (pSphereTarget && pSpheres[0])
                        {
                            angle = pSpheres[0]->GetAngle(pSphereTarget);
                            x = pSpheres[0]->GetPositionX() + DATA_SPHERE_DISTANCE * cos(angle);
                            y = pSpheres[0]->GetPositionY() + DATA_SPHERE_DISTANCE * sin(angle);
                            pSpheres[0]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[0]->GetPositionZ());
                        }

                        if (IsHeroic())
                        {
                            //DoCast(me, H_SPELL_FLAME_SPHERE_SUMMON_1, true);
                            pSpheres[1] = DoSpawnCreature(H_CREATURE_FLAME_SPHERE_1, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, SEKUNDEN_10);
                            //DoCast(me, H_SPELL_FLAME_SPHERE_SUMMON_2, true);
                            pSpheres[2] = DoSpawnCreature(H_CREATURE_FLAME_SPHERE_2, 0, 0, 5, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, SEKUNDEN_10);

                            pSphereTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);

                            if (pSphereTarget && pSpheres[1] && pSpheres[2])
                            {
                                angle = pSpheres[1]->GetAngle(pSphereTarget) + DATA_SPHERE_ANGLE_OFFSET;
                                x = pSpheres[1]->GetPositionX() + DATA_SPHERE_DISTANCE/2 * cos(angle);
                                y = pSpheres[1]->GetPositionY() + DATA_SPHERE_DISTANCE/2 * sin(angle);
                                pSpheres[1]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[1]->GetPositionZ());

                                pSphereTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);

                                if (pSphereTarget && pSpheres[1] && pSpheres[2])
                                {
                                    angle = pSpheres[2]->GetAngle(pSphereTarget) - DATA_SPHERE_ANGLE_OFFSET;
                                    x = pSpheres[2]->GetPositionX() + DATA_SPHERE_DISTANCE/2 * cos(angle);
                                    y = pSpheres[2]->GetPositionY() + DATA_SPHERE_DISTANCE/2 * sin(angle);
                                    pSpheres[2]->GetMotionMaster()->MovePoint(0, x, y, pSpheres[2]->GetPositionZ());
                                }
                            }
                        }
                        Phase = NORMAL;
                        uiPhaseTimer = 0;
                        break;
                    }
                    case JUST_VANISHED:
                        if (me->HasUnitState(UNIT_STAT_CASTING))
                            return;

                        if (Unit * pEmbraceTarget = GetEmbraceTarget())
                        {
                            me->AttackStop();
                            me->SetSpeed(MOVE_WALK, 2.0f, true);
                            me->GetMotionMaster()->MoveChase(pEmbraceTarget);
                        }
                        Phase = VANISHED;
                        uiPhaseTimer = 1300;
                        break;
                    case VANISHED:
                        if (me->HasUnitState(UNIT_STAT_CASTING))
                            return;

                        me->SetHealth(health);

                        if (Unit * pEmbraceTarget = GetEmbraceTarget())
                            DoCast(pEmbraceTarget, SPELL_EMBRACE_OF_THE_VAMPYR);

                        me->AttackStop();
                        me->SetSpeed(MOVE_WALK, 1.0f, true);
                        me->GetMotionMaster()->MoveChase(me->getVictim());

                        Phase = FEEDING;
                        uiPhaseTimer = SEKUNDEN_20;
                        break;
                    case FEEDING:
                        Phase = NORMAL;
                        uiPhaseTimer = 0;
                        uiEmbraceTarget = 0;
                        break;
                    case NORMAL:
                        if (me->HasUnitState(UNIT_STAT_CASTING))
                            return;

                        if (uiBloodthirstTimer <= diff)
                        {
                            DoCast(me->getVictim(), SPELL_BLOODTHIRST);
                            uiBloodthirstTimer = SEKUNDEN_10;
                        } else uiBloodthirstTimer -= diff;

                        if (uiFlamesphereTimer <= diff)
                        {
                            DoCast(me, SPELL_CONJURE_FLAME_SPHERE);
                            Phase = CASTING_FLAME_SPHERES;
                            uiPhaseTimer = 3 * IN_MILLISECONDS + diff;
                            uiFlamesphereTimer = SEKUNDEN_20;
                        } else uiFlamesphereTimer -= diff;

                        if (uiVanishTimer <= diff)
                        {
                            // Count alive players
                            Unit * target = NULL;
                            std::list<HostileReference *> t_list = me->getThreatManager().getThreatList();
                            std::vector<Unit *> target_list;
                            for (std::list<HostileReference *>::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                            {
                                target = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                // exclude pets & totems
                                if (target && target->GetTypeId() == TYPEID_PLAYER && target->isAlive())
                                    target_list.push_back(target);
                                target = NULL;
                            }
                            // He only vanishes if there are 3 or more alive players
                            if (target_list.size() > 2)
                            {
                                health = me->GetHealth();

                                DoScriptText(RAND(SAY_VANISH_1, SAY_VANISH_2), me);
                                DoCast(me, SPELL_VANISH);

                                Phase = JUST_VANISHED;
                                uiPhaseTimer = 500;

                                if (Unit * pEmbraceTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                    uiEmbraceTarget = pEmbraceTarget->GetGUID();
                            }
                            uiVanishTimer = urand(SEKUNDEN_20, SEKUNDEN_30);
                        } else uiVanishTimer -= diff;

                        DoMeleeAttackIfReady();
                    break;
                }
            } else uiPhaseTimer -= diff;
        }
    private:
        InstanceScript * pInstance;
        CombatPhase Phase;
        uint32 uiBloodthirstTimer;
        uint32 uiVanishTimer;
        uint32 uiWaitTimer;
        uint32 uiEmbraceTimer;
        uint32 uiEmbraceTakenDamage;
        uint32 uiFlamesphereTimer;
        uint32 uiPhaseTimer;
        uint32 health; // Speichern der aktuellen HP, da er beim Vanish HP sehr schnell regeneriert!
        uint64 uiEmbraceTarget;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_taldaramAI(creature);
    }
};

class mob_taldaram_flamesphere : public CreatureScript
{
public:
    mob_taldaram_flamesphere() : CreatureScript("mob_taldaram_flamesphere") { }

    struct mob_taldaram_flamesphereAI : public ScriptedAI
    {
        mob_taldaram_flamesphereAI(Creature * c) : ScriptedAI(c)
        {
        }

        uint32 DespawnTimer;

        void Reset()
        {
            me->SetDisplayId(SPHERE_MODEL); // Korrekte Anzeige erzwingen!
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->setFaction(16);

            DoCast(me, SPELL_FLAME_SPHERE_VISUAL, true);
            DoCast(me, SPELL_FLAME_SPHERE_SPAWN_EFFECT, true);
            DoCast(me, SPELL_FLAME_SPHERE_PERIODIC, true);

            DespawnTimer = 9500;
        }

        void EnterCombat(Unit * /*who*/) { }
        void MoveInLineOfSight(Unit * /*who*/) { }
        void AttackStart(Unit * /*who*/, float /*dist*/ = 0) { }

        void UpdateAI(const uint32 diff)
        {
            if (DespawnTimer && DespawnTimer <= diff)
            {
                DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT);
                me->SetTimeUntilDisappear(500);
                DespawnTimer = 0;
            }
            else
                DespawnTimer -= diff;
        }
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new mob_taldaram_flamesphereAI(creature);
    }
};

class prince_taldaram_sphere : public GameObjectScript
{
public:
    prince_taldaram_sphere() : GameObjectScript("prince_taldaram_sphere") { }

    bool OnGossipHello(Player * /*player*/, GameObject * pGO)
    {
        InstanceScript * pInstance = pGO->GetInstanceScript();

        Creature * pPrinceTaldaram = Unit::GetCreature(*pGO, pInstance ? pInstance->GetData64(DATA_PRINCE_TALDARAM) : 0);
        if (pPrinceTaldaram && pPrinceTaldaram->isAlive())
        {
            // maybe these are hacks :(
            pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            pGO->SetGoState(GO_STATE_ACTIVE);

            switch(pGO->GetEntry())
            {
                case GO_SPHERE1:
                    pInstance->SetData(DATA_SPHERE1_EVENT, IN_PROGRESS);
                    pInstance->SetData64(DATA_SPHERE1, pGO->GetGUID());
                    break;
                case GO_SPHERE2:
                    pInstance->SetData(DATA_SPHERE2_EVENT, IN_PROGRESS);
                    pInstance->SetData64(DATA_SPHERE2, pGO->GetGUID());
                    break;
            }
            CAST_AI(boss_taldaram::boss_taldaramAI, pPrinceTaldaram->AI())->CheckSpheres();
        }
        return true;
    }
};

void AddSC_boss_taldaram()
{
    new boss_taldaram;
    new mob_taldaram_flamesphere;
    new prince_taldaram_sphere;
}

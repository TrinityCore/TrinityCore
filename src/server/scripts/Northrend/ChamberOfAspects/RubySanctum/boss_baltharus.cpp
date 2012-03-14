/*
* Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "ruby_sanctum.h"


struct Locations
{
    float x, y, z;
};

static Locations SpawnLoc[]=
{
    {3152.329834f, 359.41757f, 85.301605f}, // Baltharus target point
    {3153.06f, 389.486f, 86.2596f}, // Baltharus initial point
};

enum Equipment
{
    EQUIP_MAIN = 49888,
    EQUIP_OFFHAND = EQUIP_NO_CHANGE,
    EQUIP_RANGED = EQUIP_NO_CHANGE,
    EQUIP_DONE = EQUIP_NO_CHANGE,
};

enum BossSpells
{
    SPELL_BLADE_TEMPEST = 75125, // every 22 secs
    SPELL_ENERVATING_BRAND = 74502, // friendlys in 12yards = 74505
    SPELL_REPELLING_WAVE = 74509, // once if call clone
    SPELL_SABER_LASH = 40504, // every 10-15 secs
    SPELL_SUMMON_CLONE = 74511, // summons npc 39899 (Clone)
    SPELL_CHANNEL_SPELL = 76221, // Channeling dummy spell
};

/*######
## boss_baltharus
######*/

class boss_baltharus : public CreatureScript
{
public:
    boss_baltharus() : CreatureScript("boss_baltharus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_baltharusAI(pCreature);
    }

    struct boss_baltharusAI : public ScriptedAI
    {
        boss_baltharusAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;
        Creature* pDummyTarget;
        Creature* pClone;
        bool inCombat;
        bool intro;
        uint8 uiStage;

        uint32 m_uiChannelTimer;
        uint32 m_uiEnevatingTimer;
        uint32 m_uiSaberLashTimer;

        void Reset()
        {
            if(!pInstance)
                return;

            if (me->isAlive()) pInstance->SetData(TYPE_BALTHARUS, NOT_STARTED);
            me->SetRespawnDelay(7*DAY);

            uiStage = 0;
            pClone = NULL;
            inCombat = false;
            intro = false;

            m_uiChannelTimer = 1*IN_MILLISECONDS;
            m_uiEnevatingTimer = urand(10*IN_MILLISECONDS,25*IN_MILLISECONDS);
            m_uiSaberLashTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);

            if (pDummyTarget = me->GetMap()->GetCreature( pInstance->GetData64(NPC_BALTHARUS_TARGET)))
            {
                if (!pDummyTarget->isAlive()) pDummyTarget->Respawn();

                pDummyTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pDummyTarget->GetMotionMaster()->MoveIdle();
            }
            else if (pDummyTarget = me->SummonCreature(NPC_BALTHARUS_TARGET, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0.0f, TEMPSUMMON_MANUAL_DESPAWN, 1000))
            {
                pDummyTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pDummyTarget->GetMotionMaster()->MoveIdle();
            }

            if(Creature* pTarget = me->GetMap()->GetCreature( pInstance->GetData64(NPC_XERESTRASZA)))
                me->SetUInt64Value(UNIT_FIELD_TARGET, pTarget->GetGUID());
        }

        void JustReachedHome()
        {
            if (!pInstance) return;

            pInstance->SetData(TYPE_BALTHARUS, FAIL);
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if(!pInstance || intro ||
                pWho->GetTypeId() != TYPEID_PLAYER ||
                !pWho->IsWithinDistInMap(me, 60.0f)) return;

            pInstance->SetData(TYPE_EVENT, 10);
            DoScriptText(-1666305,me);
            intro = true;
        }

        void JustDied(Unit* pKiller)
        {
            if (!pInstance) return;

          // if (pDummyTarget && pDummyTarget->isSummon())
          // pDummyTarget->ForcedDespawn();

            DoScriptText(-1666303,me);
            pInstance->SetData(TYPE_BALTHARUS, DONE);
        }

        void KilledUnit(Unit* victim)
        {
        switch (urand(0,1)) {
            case 0:
                   DoScriptText(-1666301,me,victim);
                   break;
            case 1:
                   DoScriptText(-1666302,me,victim);
                   break;
            }
        }

        void JustSummoned(Creature* summoned)
        {
            if(!pInstance || !summoned) return;

            if ( summoned->GetEntry() != NPC_BALTHARUS_TARGET )
            {
                 if (!pClone) pClone = summoned;
                 else if (!pClone->isAlive()) pClone = summoned;
                 pClone->SetInCombatWithZone();
            }
        }

        void SummonedCreatureJustDied(Creature* summoned)
        {
             if (!pInstance || !summoned) return;

             if (summoned == pClone) pClone = NULL;
        }

        void EnterCombat(Unit* pWho)
        {
            if (!pInstance) return;
            if (pWho->GetTypeId() != TYPEID_PLAYER) return;

            if (pDummyTarget) pDummyTarget->ForcedDespawn();

            SetEquipmentSlots(false, EQUIP_MAIN, EQUIP_OFFHAND, EQUIP_RANGED);

            inCombat = true;
            me->InterruptNonMeleeSpells(true);
            SetCombatMovement(true);
            pInstance->SetData(TYPE_BALTHARUS, IN_PROGRESS);
            DoScriptText(-1666300,me);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (!pInstance) return;

            if (!me || !me->isAlive())
                return;

            if(pDoneBy->GetGUID() == me->GetGUID())
              return;

            if (pClone && pClone->isAlive())
            {
                pDoneBy->DealDamage(pClone, uiDamage, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                uiDamage = 0;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!pInstance) return;

            if (!inCombat && !me->IsNonMeleeSpellCasted(false))
            {
                if (m_uiChannelTimer <= diff)
                {
                    DoCast(pDummyTarget, SPELL_CHANNEL_SPELL);
                    m_uiChannelTimer = 1*IN_MILLISECONDS;
                } else m_uiChannelTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            switch (uiStage)
            {
                case 0:
                     if ( HealthBelowPct(67)) uiStage = 1;
                     break;

                case 1:
                     me->InterruptNonMeleeSpells(true);
                     if (Is25ManRaid())
                         DoCast(SPELL_SUMMON_CLONE);
                     uiStage = 2;
                     break;

                case 2:
                     if (me->IsNonMeleeSpellCasted(false)) return;
                     DoCast(SPELL_REPELLING_WAVE);
                     uiStage = 3;

                case 3:
                     if ( HealthBelowPct(51)) uiStage = 4;
                     break;

                case 4:
                     me->InterruptNonMeleeSpells(true);
                     if (!Is25ManRaid())
                            DoCast(SPELL_SUMMON_CLONE);
                     uiStage = 5;
                     break;

                case 5:
                     if (me->IsNonMeleeSpellCasted(false)) return;
                     DoCast(SPELL_REPELLING_WAVE);
                     uiStage = 6;

                case 6:
                     if ( HealthBelowPct(34)) uiStage = 7;
                     break;

                case 7:
                     me->InterruptNonMeleeSpells(true);
                     if (Is25ManRaid())
                         DoCast(SPELL_SUMMON_CLONE);
                     uiStage = 8;
                     break;

                case 8:
                     if (me->IsNonMeleeSpellCasted(false)) return;
                     DoCast(SPELL_REPELLING_WAVE);
                     uiStage = 9;

                case 9:
                default:
                     break;
            }

            if (m_uiEnevatingTimer <= diff)
            {
                DoCast(SPELL_ENERVATING_BRAND);
                m_uiEnevatingTimer = urand(10*IN_MILLISECONDS,25*IN_MILLISECONDS);
            } else m_uiEnevatingTimer -= diff;

            if (m_uiSaberLashTimer <= diff)
            {
                DoCast(SPELL_SABER_LASH);
                m_uiSaberLashTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
            } else m_uiSaberLashTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};



/*######
## mob_baltharus_clone
######*/

class mob_baltharus_clone : public CreatureScript
{
public:
    mob_baltharus_clone() : CreatureScript("mob_baltharus_clone") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_baltharus_cloneAI(pCreature);
    }

    struct mob_baltharus_cloneAI : public ScriptedAI
    {
        mob_baltharus_cloneAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;

        uint32 m_uiBladeTempestTimer;
        uint32 m_uiEnevatingTimer;
        uint32 m_uiSaberLashTimer;

        void Reset()
        {
            if(!pInstance) return;

            m_uiBladeTempestTimer = 22*IN_MILLISECONDS;
            m_uiEnevatingTimer = urand(10*IN_MILLISECONDS,25*IN_MILLISECONDS);
            m_uiSaberLashTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);

            me->SetRespawnDelay(7*DAY);
        }

        void KilledUnit(Unit* victim)
        {
        switch (urand(0,1)) {
            case 0:
                   DoScriptText(-1666301,me,victim);
                   break;
            case 1:
                   DoScriptText(-1666302,me,victim);
                   break;
            }
        }

        void JustDied(Unit* pKiller)
        {
            if (!pInstance) return;
        }

        void EnterCombat(Unit* pWho)
        {
            if (!pInstance) return;

            SetEquipmentSlots(false, EQUIP_MAIN, EQUIP_OFFHAND, EQUIP_RANGED);

            me->SetInCombatWithZone();
        }

        void UpdateAI(const uint32 diff)
        {

            if (!pInstance) return;

            if (pInstance->GetData(TYPE_BALTHARUS) != IN_PROGRESS)
                me->ForcedDespawn();

            if (!UpdateVictim())
                return;

            if (m_uiBladeTempestTimer <= diff)
            {
                DoCast(me,SPELL_BLADE_TEMPEST);
                m_uiBladeTempestTimer = 22*IN_MILLISECONDS;
            } else m_uiBladeTempestTimer -= diff;

            if (m_uiEnevatingTimer <= diff)
            {
                DoCast(SPELL_ENERVATING_BRAND);
                m_uiEnevatingTimer = urand(10*IN_MILLISECONDS,25*IN_MILLISECONDS);
            } else m_uiEnevatingTimer -= diff;

            if (m_uiSaberLashTimer <= diff)
            {
                DoCast(SPELL_SABER_LASH);
                m_uiSaberLashTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
            } else m_uiSaberLashTimer -= diff;


            DoMeleeAttackIfReady();
        }
    };
};


/*######
## mob_xerestrasza
######*/

static Locations SpawnLocXer[]=
{
    {3155.540039f, 342.391998f, 84.596802f}, // 0 - start point
    {3152.329834f, 359.41757f, 85.301605f}, // 1 - second say
    {3152.078369f, 383.939178f, 86.337875f}, // 2 - other says and staying
    {3154.99f, 535.637f, 72.8887f}, // 3 - Halion spawn point
};

class mob_xerestrasza : public CreatureScript
{
public:
    mob_xerestrasza() : CreatureScript("mob_xerestrasza") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_xerestraszaAI(pCreature);
    }

    struct mob_xerestraszaAI : public ScriptedAI
    {
        mob_xerestraszaAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;
        uint32 nextEvent;
        uint32 nextPoint;
        uint32 UpdateTimer;
        bool movementstarted;
        bool onSessionEvent;

        void Reset()
        {
            if(!pInstance) return;
            nextEvent = 0;
            nextPoint = 0;
            movementstarted = false;
            UpdateTimer = 2000;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            pInstance->SetData(TYPE_XERESTRASZA, NOT_STARTED);
            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            me->SetSpeed(MOVE_WALK, 0.8f, true);
            me->SetRespawnDelay(7*DAY);
       }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || !movementstarted) return;
            if (id == nextPoint)
            {
                movementstarted = false;
                pInstance->SetData(TYPE_EVENT,nextEvent);
                me->GetMotionMaster()->MovementExpired();
            }
        }

        void StartMovement(uint32 id, uint32 _nextEvent)
        {
            nextPoint = id;
            nextEvent = _nextEvent;
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(id, SpawnLocXer[id].x, SpawnLocXer[id].y, SpawnLocXer[id].z);
            pInstance->SetData(TYPE_EVENT,0);
            movementstarted = true;
        }

        void AttackStart(Unit *who)
        {
            //ignore all attackstart commands
            return;
        }

        void MoveInLineOfSight(Unit *who)
        {
            if(!pInstance || !who || who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (pInstance->GetData(TYPE_BALTHARUS) != DONE
                || pInstance->GetData(TYPE_XERESTRASZA) != NOT_STARTED) return;

            if(!who->IsWithinDistInMap(me, 60.0f)) return;

            pInstance->SetData(TYPE_XERESTRASZA, IN_PROGRESS);
            pInstance->SetData(TYPE_EVENT, 30);
            onSessionEvent = true;
        }

        void UpdateAI(const uint32 diff)
        {
            if(!pInstance) return;

            if (pInstance->GetData(TYPE_EVENT_NPC) == NPC_XERESTRASZA)
            {
                UpdateTimer = pInstance->GetData(TYPE_EVENT_TIMER);
                if (UpdateTimer <= diff)
                {
                    switch (pInstance->GetData(TYPE_EVENT))
                    {
// Xerestrasza intro
                        case 10:
                              UpdateTimer = 7000;
                              pInstance->SetData(TYPE_EVENT, 20);
                              break;
                        case 20:
                              DoScriptText(-1666000,me);
                              pInstance->SetData(TYPE_EVENT,0);
                              break;
// Xerestrasza event
                        case 30:
                             // me->SetActive(true);
                              DoScriptText(-1666001,me);
                              StartMovement(1,40);
                              break;
                        case 40:
                              DoScriptText(-1666002,me);
                              StartMovement(2,50);
                              break;
                        case 50:
                              DoScriptText(-1666003,me);
                              UpdateTimer = 12000;
                              pInstance->SetData(TYPE_EVENT,60);
                              break;
                        case 60:
                              DoScriptText(-1666004,me);
                              UpdateTimer = 12000;
                              pInstance->SetData(TYPE_EVENT,70);
                              break;
                        case 70:
                              DoScriptText(-1666005,me);
                              UpdateTimer = 10000;
                              pInstance->SetData(TYPE_EVENT,80);
                              break;
                        case 80:
                              DoScriptText(-1666006,me);
                              UpdateTimer = 10000;
                              pInstance->SetData(TYPE_EVENT,90);
                              break;
                        case 90:
                              DoScriptText(-1666007,me);
                              UpdateTimer = 10000;
                              pInstance->SetData(TYPE_EVENT,100);
                              break;
                        case 100:
                              DoScriptText(-1666008,me);
                              UpdateTimer = 4000;
                              pInstance->SetData(TYPE_EVENT,110);
                              break;
                        case 110:
                              UpdateTimer = 2000;
                              pInstance->SetData(TYPE_EVENT,0);
                              pInstance->SetData(TYPE_XERESTRASZA, DONE);
                              me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                              me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                             // me->SetActive(false);
                              break;
// Halion spawn
                        case 200:
                              //me->SetActive(true);
                              {
                              Creature* pHalion = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_REAL));
                              if (pInstance->GetData(TYPE_BALTHARUS) == DONE &&
                                  pInstance->GetData(TYPE_RAGEFIRE) == DONE &&
                                  pInstance->GetData(TYPE_XERESTRASZA) == DONE &&
                                  pInstance->GetData(TYPE_ZARITHRIAN) == DONE &&
                                  pInstance->GetData(TYPE_HALION) != DONE)
                                  {
                                  if (!pHalion)
                                      pHalion = me->SummonCreature(NPC_HALION_REAL, SpawnLocXer[3].x, SpawnLocXer[3].y, SpawnLocXer[3].z, 6.23f, TEMPSUMMON_MANUAL_DESPAWN, HOUR*IN_MILLISECONDS);
                                  if (pHalion && !pHalion->isAlive())
                                      pHalion->Respawn();
                                  if (pHalion)
                                      pHalion->SetCreatorGUID(0);
                                  }
                              }
                              UpdateTimer = 4000;
                              pInstance->SetData(TYPE_EVENT,210);
                              break;
                        case 210:
                              //me->SetActive(false);
                              UpdateTimer = 2000;
                              pInstance->SetData(TYPE_EVENT,0);
                              break;

                        default:
                          break;
                    }
                 } else UpdateTimer -= diff;
                 pInstance->SetData(TYPE_EVENT_TIMER, UpdateTimer);
            }
        }
    };
};


void AddSC_boss_baltharus()
{
    new boss_baltharus();
    new mob_baltharus_clone();
    new mob_xerestrasza();
}
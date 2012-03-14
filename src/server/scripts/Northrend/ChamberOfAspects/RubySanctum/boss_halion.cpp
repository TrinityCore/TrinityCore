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

enum
{
    SPELL_TWILIGHT_PRECISION		= 78243, // Increases Halion's chance to hit by 5% and decreases all players' chance to dodge by 20%
    SPELL_BERSERK					= 26662, // Increases the caster's attack and movement speeds by 150% and all damage it deals by 500% for 5 min. Also grants immunity to Taunt effects.
    SPELL_START_PHASE2				= 74808, // Phases the caster into the Twilight realm, leaving behind a large rift.
    SPELL_TWILIGHT_ENTER			= 74807, // Phases the caster into the Twilight realm - phase 32
    SPELL_TWILIGHT_ENTER2			= 74812, //
    SPELL_SUMMON_TWILIGHT_PORTAL	= 74809, //

    SPELL_FIRE_PILLAR				= 76006, // Visual intro
    SPELL_FIERY_EXPLOSION			= 76010, // Visual intro

	//NEED SCRIPT
    SPELL_TAIL_LASH 				= 74531, // A sweeping tail strike hits all enemies behind the caster, inflicting 3063 to 3937 damage and stunning them for 2 sec.
    SPELL_TWILIGHT_DIVISION 		= 75063, // Phases the caster, allowing him to exist and act simultaneously in both the material and Twilight realms.
    SPELL_TWILIGHT_CUTTER 			= 77844, // Inflicts 13,875 to 16,125 Shadow damage every second to players touched by the shadow beam
    SPELL_TWILIGHT_CUTTER_CHANNEL 	= 74768, // Channeling shadow cutter visual + trigger 74769
	
    //CORPOREALITY
    SPELL_CORPOREALITY_EVEN			= 74826, // Deals & receives normal damage
    SPELL_CORPOREALITY_20I			= 74827, // Damage dealt increased by 10% & Damage taken increased by 15%
    SPELL_CORPOREALITY_40I			= 74828, // Damage dealt increased by 30% & Damage taken increased by 50%
    SPELL_CORPOREALITY_60I			= 74829, // Damage dealt increased by 60% & Damage taken increased by 100%
    SPELL_CORPOREALITY_80I			= 74830, // Damage dealt increased by 100% & Damage taken increased by 200%
    SPELL_CORPOREALITY_100I			= 74831, // Damage dealt increased by 200% & Damage taken increased by 400%
    SPELL_CORPOREALITY_20D			= 74832, // Damage dealt reduced by 10% & Damage taken reduced by 15%
    SPELL_CORPOREALITY_40D			= 74833, // Damage dealt reduced by 30% & Damage taken reduced by 50%
    SPELL_CORPOREALITY_60D			= 74834, // Damage dealt reduced by 60% & Damage taken reduced by 100%
    SPELL_CORPOREALITY_80D			= 74835, // Damage dealt reduced by 100% & Damage taken reduced by 200%
    SPELL_CORPOREALITY_100D			= 74836, // Damage dealt reduced by 200% & Damage taken reduced by 400%
    //METEOR STRIKE
    SPELL_METEOR					= 74637, // Script Start (summon NPC_METEOR_STRIKE)
    SPELL_METEOR_IMPACT				= 74641, // IMPACT ZONE FOR METEOR
    SPELL_METEOR_STRIKE				= 74648, // Inflicts 18,750 to 21,250 Fire damage to enemies within 12 yards of the targeted area. Takes about 5 seconds to land.
    SPELL_METEOR_FLAME				= 74718, // FLAME FROM METEOR
    //N10
    SPELL_FLAME_BREATH				= 74525, // Inflicts 17,500 to 22,500 Fire damage to players in front of Halion
    SPELL_DARK_BREATH				= 74806, // Inflicts 17,500 to 22,500 Shadow damage to players in front of Halion
    SPELL_DUSK_SHROUD				= 75484, // Inflicts 3,000 Shadow damage every 2 seconds to everyone in the Twilight Realm
    //Combustion
    NPC_COMBUSTION					= 40001,
    SPELL_MARK_OF_COMBUSTION		= 74567, // Dummy effect only
    SPELL_FIERY_COMBUSTION			= 74562, // Inflicts 4,000 Fire damage every 2 seconds for 30 seconds to a random raider. Every time Fiery Combustion does damage, it applies a stackable Mark of Combustion.
    SPELL_COMBUSTION_EXPLODE		= 74607,
    SPELL_COMBUSTION_AURA			= 74629,
    //Consumption
    NPC_CONSUMPTION					= 40135,
    SPELL_MARK_OF_CONSUMPTION		= 74795, // Dummy effect only
    SPELL_SOUL_CONSUMPTION			= 74792, // Inflicts 4,000 Shadow damage every 2 seconds for 30 seconds to a random raider. Every time Soul Consumption does damage, it applies a stackable Mark of Consumption.
    SPELL_CONSUMPTION_EXPLODE		= 74799,
    SPELL_CONSUMPTION_AURA			= 74803,
	SPELL_GROW_UP					= 36300,
    //Summons
    NPC_METEOR_STRIKE				= 40029, //casts "impact zone" then meteor
    NPC_METEOR_STRIKE_1				= 40041,
    NPC_METEOR_STRIKE_2				= 40042,
	NPC_ORB_CUTTER					= 40081,
	
    FR_RADIUS						= 45,

    //SAYS
    SAY_HALION_SPAWN				= -1666100, //17499 Meddlesome insects, you're too late! The Ruby Sanctum is lost.
    SAY_HALION_AGGRO				= -1666101, //17500 Your world teeters on the brink of annihilation. You will all bear witness to the coming of a new age of destruction!
    SAY_HALION_SLAY_1				= -1666102, //17501 Another hero falls.
    SAY_HALION_SLAY_2				= -1666103, //17502 Ha Ha Ha!
    SAY_HALION_DEATH				= -1666104, //17503 Relish this victory mortals, for it will be your last. This world will burn with the Master's return!
    SAY_HALION_BERSERK				= -1666105, //17504 Not good enough!
    SAY_HALION_SPECIAL_1			= -1666106, //17505 The heavens burn!
    SAY_HALION_SPECIAL_2			= -1666107, //17506 Beware the shadow!
    SAY_HALION_PHASE_2				= -1666108, //17507 You will find only suffering within the realm of Twilight. Enter if you dare.
    SAY_HALION_PHASE_3				= -1666109, //17508 I am the light AND the darkness! Cower mortals before the Herald of Deathwing!
    EMOTE_WARNING					= -1666110, //orbs charge warning
    EMOTE_REAL_PUSH					= -1666111, // Out of real world message
    EMOTE_REAL_PULL					= -1666112, // To real world message
    EMOTE_TWIL_PUSH					= -1666113, // Out of twilight world message
    EMOTE_TWIL_PULL					= -1666114, // To twilight world message
};

struct Locations
{
    float x, y, z;
};

static Locations SpawnLoc[]=
{
    {3154.99f, 535.637f, 72.8887f}, // 0 - Halion spawn point (center)
};

/*######
## boss_halion_real (Physical version)
######*/
uint32 Rdmg, Tdmg;

class boss_halion_real : public CreatureScript
{
public:
    boss_halion_real() : CreatureScript("boss_halion_real") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_halion_realAI(pCreature);
    }

    struct boss_halion_realAI : public ScriptedAI
    {
        boss_halion_realAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;

        bool intro;
        uint8 stage;
        uint8 nextPoint;
        uint32 m_uiIntroTimer;
        uint32 m_uiIntroAppTimer;
        uint32 m_uiEnrage;
        uint32 m_uiFlameTimer;
        uint32 m_uiFieryTimer;
        uint32 m_uiMeteorTimer;
        uint32 m_uiTailLashTimer;
        bool MovementStarted;

        void Reset()
        {
            if(!pInstance)
                return;
            me->SetRespawnDelay(7*DAY);

            if (me->isAlive())
            {
                pInstance->SetData(TYPE_HALION, NOT_STARTED);
                pInstance->SetData(TYPE_HALION_EVENT, FAIL);
                me->SetDisplayId(11686);
            }

            setStage(0);
            nextPoint = 0;
            intro = false;
            m_uiIntroTimer = 1*IN_MILLISECONDS;
            m_uiIntroAppTimer = 30*IN_MILLISECONDS;
            m_uiEnrage = 600*IN_MILLISECONDS;
            m_uiFlameTimer = urand(10*IN_MILLISECONDS,18*IN_MILLISECONDS);
            m_uiFieryTimer = urand(30*IN_MILLISECONDS,40*IN_MILLISECONDS);
            m_uiMeteorTimer = urand(30*IN_MILLISECONDS,35*IN_MILLISECONDS);
            m_uiTailLashTimer = urand(15*IN_MILLISECONDS,25*IN_MILLISECONDS);
			Rdmg = 0;
            SetCombatMovement(true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (GameObject* pGoPortal = me->FindNearestGameObject(GO_HALION_PORTAL_1, 50.0f))
                pGoPortal->Delete();
            if (GameObject* pGoPortal = me->FindNearestGameObject(GO_HALION_PORTAL_2, 50.0f))
                pGoPortal->Delete();
            if (GameObject* pGoPortal = me->FindNearestGameObject(GO_HALION_PORTAL_3, 50.0f))
				pGoPortal->Delete();
			me->RemoveAurasDueToSpell(SPELL_TWILIGHT_ENTER);
        }

        void setStage(uint8 phase)
        {
            stage = phase;
        }

        uint8 getStage()
        {
            return stage;
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (!pInstance) 
				return;

            if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER) 
				return;

			if (pInstance->GetData(TYPE_ZARITHRIAN) == DONE)
			{
				if (!intro && pWho->IsWithinDistInMap(me, 60.0f))
					{
						DoScriptText(-1666100,me);
						intro = true;
					}
					
		        if (intro && !me->isInCombat() && pWho->IsWithinDistInMap(me, 20.0f))
			    {
					me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
					me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
					me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
					me->SetInCombatWith(pWho);
					SetCombatMovement(false);
					me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE);
					me->GetMotionMaster()->MoveIdle();
					setStage(10);
				}
			}else return;

        }

		
		void JustReachedHome()
        {
            if (!pInstance)
				return;
            if (pInstance->GetData(TYPE_HALION_EVENT) != FAIL || getStage() == 0)
                return;
				
			ScriptedAI::JustReachedHome();
        }

        void EnterEvadeMode()
        {
            if (!pInstance) return;

            if (pInstance->GetData(TYPE_HALION_EVENT) != FAIL) return;

            ScriptedAI::EnterEvadeMode();
        }

        void JustDied(Unit* pKiller)
        {
            if (!pInstance)
                return;
			if (GameObject* pGoPortal = me->FindNearestGameObject(GO_HALION_PORTAL_1, 50.0f))
				pGoPortal->Delete();
            DoScriptText(-1666104,me);
			if (Creature* pclone = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_TWILIGHT)))
			{
				if (pclone->isAlive())
				{
					pclone->SetHealth(1);
				}
			}
			pInstance->SetData(TYPE_HALION, DONE);
            me->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            pInstance->SetData(TYPE_COUNTER, COUNTER_OFF);
			// Updating achievements for all players in the map - not only in real world
			Map* pMap = me->GetMap();
			Map::PlayerList const &pList = pMap->GetPlayers();
				if (pList.isEmpty()) return;
			for(Map::PlayerList::const_iterator i = pList.begin(); i != pList.end(); ++i)
			{
				if (Player* player = i->getSource())
				{
					if (!player) continue;
					if (player->isGameMaster()) continue;
					if (!player->IsInMap(me)) continue;
					player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, me->GetEntry());
				}
			}		
		}

        void KilledUnit(Unit* victim)
        {
            switch (urand(0,1))
            {
                case 0:
                    DoScriptText(-1666106,me,victim);
                    break;
                case 1:
                    DoScriptText(-1666107,me,victim);
                    break;
            }
        }

        void EnterCombat(Unit* pWho)
        {
            if (!pInstance)
                return;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            DoCast(SPELL_TWILIGHT_PRECISION);
            me->SetInCombatWithZone();
            pInstance->SetData(TYPE_HALION, IN_PROGRESS);
            DoScriptText(-1666101,me);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (!pInstance) return;

            if (type != POINT_MOTION_TYPE || !MovementStarted) return;

            if (id == nextPoint) 
			{
				me->GetMotionMaster()->MovementExpired();
                MovementStarted = false;
            }
        }

        void StartMovement(uint32 id)
        {
            nextPoint = id;
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(id, SpawnLoc[id].x, SpawnLoc[id].y, SpawnLoc[id].z);
            MovementStarted = true;
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
		{
			if (!pInstance)
				return;
			Rdmg += uiDamage;
			Creature * pHalionTwilight = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_TWILIGHT));
			if (!pHalionTwilight)
				return;
			if (pHalionTwilight->GetHealth()<=1 || !pHalionTwilight->isAlive())
				return;
			if (uiDamage < me->GetHealth())
			{
				pHalionTwilight->SetHealth(me->GetHealth()-uiDamage);
			}
		}

        void UpdateAI(const uint32 uiDiff)
        {
            if (!pInstance)
                return;

            if (!UpdateVictim())
                return;

			switch (getStage())
            {
                case 10: //PHASE INTRO
                    if (m_uiIntroTimer <= uiDiff)
                    {
                        DoCast(SPELL_FIRE_PILLAR);
                        m_uiIntroAppTimer = 10*IN_MILLISECONDS;
                        m_uiIntroTimer = 30*IN_MILLISECONDS;
                    } else m_uiIntroTimer -= uiDiff;

                    if (m_uiIntroAppTimer <= uiDiff)
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                        me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE);
                        DoCast(SPELL_FIERY_EXPLOSION);
                        me->SetDisplayId(31952);
                        SetCombatMovement(true);
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                        setStage(0);
                        m_uiIntroAppTimer = 30*IN_MILLISECONDS;
                    } else m_uiIntroAppTimer -= uiDiff;
                    break;
                case 0: //PHASE 1 PHYSICAL REALM
                    if (m_uiFlameTimer <= uiDiff)
                    {
                        DoCast(SPELL_FLAME_BREATH);
                        m_uiFlameTimer = urand(12*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiFlameTimer -= uiDiff;

                    if (m_uiTailLashTimer <= uiDiff)
                    {
                        DoCast(SPELL_TAIL_LASH);
                        m_uiTailLashTimer = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiTailLashTimer -= uiDiff;

                    if (m_uiFieryTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 45.0f, true))
                            DoCast(pTarget, SPELL_FIERY_COMBUSTION);
                        else if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                            DoCast(pTarget, SPELL_FIERY_COMBUSTION);
                        m_uiFieryTimer = urand(25*IN_MILLISECONDS,40*IN_MILLISECONDS);
                    } else m_uiFieryTimer -= uiDiff;

                    if (m_uiMeteorTimer <= uiDiff)
                    {
                        DoCast(SPELL_METEOR);
                        m_uiMeteorTimer = urand(30*IN_MILLISECONDS,35*IN_MILLISECONDS);
                    } else m_uiMeteorTimer -= uiDiff;

                    if (HealthBelowPct(76)) 
					{
                        setStage(1);
                        me->AttackStop();
                        me->InterruptNonMeleeSpells(true);
                        SetCombatMovement(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    break;
                case 1: // Switch to phase 2
                    {
						DoScriptText(-1666108,me);
						pInstance->SetData(TYPE_HALION_EVENT, NOT_STARTED);
						StartMovement(0);
						{
							Creature* pControl = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_CONTROL));
							if (!pControl)
								pControl = me->SummonCreature(NPC_HALION_CONTROL, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 1000);
							else if (!pControl->isAlive())
								pControl->Respawn();
							pControl->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
							me->SetInCombatWith(pControl);
							pControl->SetInCombatWith(me);
						}
						setStage(2);
						break;
                    }
                case 2:
                    if (MovementStarted) return;
                    DoCast(me, SPELL_SUMMON_TWILIGHT_PORTAL);
                    setStage(3);
                    if (GameObject* pGoPortal = pInstance->instance->GetGameObject(pInstance->GetData64(GO_HALION_PORTAL_1)))
                          pGoPortal->SetPhaseMask(31,true);
                    if (GameObject* pGoRing = pInstance->instance->GetGameObject(pInstance->GetData64(GO_FLAME_RING)))
                          pGoRing->SetPhaseMask(65535,true);
                    break;
                case 3:
                    if (me->IsNonMeleeSpellCasted(false)) return;
                    DoCast(SPELL_START_PHASE2);
                    setStage(4);
                    break;

                case 4:
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        if (Creature* pControl = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_CONTROL)))
                        {
                            me->SetInCombatWith(pControl);
                            pControl->SetInCombatWith(me);
                        }
                        Creature* pTwilight = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_TWILIGHT));
                        if (!pTwilight)
                            pTwilight = me->SummonCreature(NPC_HALION_TWILIGHT, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 1000);
                        else if (!pTwilight->isAlive())
                            pTwilight->Respawn();
                        pTwilight->SetCreatorGUID(0);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        setStage(5);
                    }
                    break;

                case 5: // HALION awaiting end battle in TWILIGHT REALM
                    if (pInstance->GetData(TYPE_HALION_EVENT) == IN_PROGRESS)
                        {
                            me->RemoveAurasDueToSpell(SPELL_START_PHASE2);
                            if (Creature* pControl = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_CONTROL)))
                            {
                                me->SetInCombatWith(pControl);
                                pControl->SetInCombatWith(me);
                            }
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->SetHealth(me->GetMaxHealth()/2);
                            me->SetInCombatWithZone();
                            setStage(6);
                        }
                    return;
                case 6: // Switch to phase 3
                    DoScriptText(-1666109,me);
                    pInstance->SetData(TYPE_HALION_EVENT, SPECIAL);
                    setStage(7);
                    break;
                case 7:
                    if (me->IsNonMeleeSpellCasted(false)) return;
                    if (me->getVictim()->GetTypeId() != TYPEID_PLAYER) return;
                    SetCombatMovement(true);
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    setStage(8);
                    break;
                case 8: //PHASE 3 BOTH REALMS
					if(Creature* pTwilight = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_TWILIGHT)))
						if (pTwilight->isAlive())
							me->SetHealth(pTwilight->GetHealth());
					if (m_uiFlameTimer <= uiDiff)
                    {
                         DoCast(SPELL_FLAME_BREATH);
                         m_uiFlameTimer = urand(12*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiFlameTimer -= uiDiff;

					if (m_uiTailLashTimer <= uiDiff)
                    {
                         DoCast(SPELL_TAIL_LASH);
                         m_uiTailLashTimer = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiTailLashTimer -= uiDiff;

					if (m_uiFieryTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 45.0f, true))
                            DoCast(pTarget, SPELL_FIERY_COMBUSTION);
                        else if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                            DoCast(pTarget, SPELL_FIERY_COMBUSTION);
                        m_uiFieryTimer = urand(25*IN_MILLISECONDS,40*IN_MILLISECONDS);
                    } else m_uiFieryTimer -= uiDiff;

					if (m_uiMeteorTimer <= uiDiff)
                    {
                        DoCast(SPELL_METEOR);
                        m_uiMeteorTimer = urand(30*IN_MILLISECONDS,35*IN_MILLISECONDS);
                    } else m_uiMeteorTimer -= uiDiff;
					break;
                default:
                    break;
            }

            if (m_uiEnrage <= uiDiff)
            {
                 DoCast(SPELL_BERSERK);
                 m_uiEnrage = 600*IN_MILLISECONDS;
                 DoScriptText(-1666105,me);
            } else m_uiEnrage -= uiDiff;

            DoMeleeAttackIfReady();

        }
    };
};

/*######
## boss_halion_twilight (Twilight version)
######*/

class boss_halion_twilight : public CreatureScript
{
public:
    boss_halion_twilight() : CreatureScript("boss_halion_twilight") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_halion_twilightAI(pCreature);
    }

    struct boss_halion_twilightAI : public ScriptedAI
    {
        boss_halion_twilightAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;


        uint8 stage;
        bool intro;
        uint32 m_uiEnrage;
        uint32 m_uiDuskTimer;
        uint32 m_uiDarkBreathTimer;
        uint32 m_uiSoulCunsumTimer;
        uint32 m_uiTailLashTimer;

        void Reset()
        {
            if(!pInstance)
                return;
            me->SetRespawnDelay(7*DAY);
            setStage(0);
            intro = false;
            m_uiEnrage = 600*IN_MILLISECONDS;
            m_uiDuskTimer = 2*IN_MILLISECONDS;
			Tdmg = 0;
            m_uiDarkBreathTimer = urand(12*IN_MILLISECONDS,20*IN_MILLISECONDS);
            m_uiSoulCunsumTimer = urand(30*IN_MILLISECONDS,40*IN_MILLISECONDS);
            m_uiTailLashTimer = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);

            me->SetInCombatWithZone();
            if (Creature* pControl = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_CONTROL)))
            {
                me->SetInCombatWith(pControl);
                pControl->SetInCombatWith(me);
            }

            Creature* pFocus = me->GetMap()->GetCreature(pInstance->GetData64(NPC_ORB_ROTATION_FOCUS));
            if (!pFocus )
                pFocus = me->SummonCreature(NPC_ORB_ROTATION_FOCUS, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 1000);
            else if (!pFocus->isAlive())
                pFocus->Respawn();

            if (Creature* pReal = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_REAL)))
                if (pReal->isAlive())
                    me->SetHealth(pReal->GetHealth());
            if (!me->HasAura(SPELL_TWILIGHT_ENTER))
                 DoCast(me, SPELL_TWILIGHT_ENTER);
        }

        void setStage(uint8 phase)
        {
            stage = phase;
        }

        uint8 getStage()
        {
            return stage;
        }

        void JustReachedHome()
        {
            if (!pInstance) return;
            if (pInstance->GetData(TYPE_HALION_EVENT) != FAIL || getStage() == 0)
                return;
			ScriptedAI::JustReachedHome();
        }

        void EnterEvadeMode()
        {

            if (!pInstance) return;

            if (pInstance->GetData(TYPE_HALION_EVENT) != FAIL || getStage() == 0)
                return;

            ScriptedAI::EnterEvadeMode();
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (!pInstance) return;

            if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER) return;

            if ( !intro && pWho->IsWithinDistInMap(me, 20.0f))
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                intro = true;
                AttackStart(pWho);
                setStage(1);
                DoCast(SPELL_TWILIGHT_PRECISION);
            }

        }

        void JustDied(Unit* pKiller)
        {
            if (!pInstance)
                return;
            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_ENTER);
			if (Creature* pReal = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_REAL)))
            if (!pReal->isAlive())
            {
                pInstance->SetData(TYPE_HALION, DONE);
                pReal->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                pInstance->SetData(TYPE_COUNTER, COUNTER_OFF);
            }
			me->ForcedDespawn();
        }

        void KilledUnit(Unit* victim)
        {
            switch (urand(0,1))
            {
                case 0:
                    DoScriptText(-1666106,me,victim);
                    break;
                case 1:
                    DoScriptText(-1666107,me,victim);
                    break;
            }
        }

        void EnterCombat(Unit* pWho)
        {
            if (!pInstance)
                return;
        }

		void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
		{
			if (!pInstance)
				return;
			Tdmg += uiDamage;
			Creature * pHalionReal = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_REAL));
			if (!pHalionReal)
				return;
			if (pHalionReal->GetHealth()<=1 || !pHalionReal->isAlive())
				return;
			if (uiDamage < me->GetHealth())
			{
				pHalionReal->SetHealth(me->GetHealth()-uiDamage);
			}
		}


        void UpdateAI(const uint32 uiDiff)
        {

            if (!me->HasAura(SPELL_TWILIGHT_ENTER))
                 DoCast(me, SPELL_TWILIGHT_ENTER);

            if (!pInstance)
            {
                me->ForcedDespawn();
                return;
            }

			if (pInstance->GetData(TYPE_HALION) != DONE)
			{
				if (!pInstance || pInstance->GetData(TYPE_HALION) != IN_PROGRESS || pInstance->GetData(TYPE_HALION_EVENT) == FAIL)
				{
					if (Creature* pReal = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_REAL)))
						if (!pReal->isAlive())
							pReal->Respawn();
					me->ForcedDespawn();
				}
			}

            if (!UpdateVictim())
                return;

            switch (getStage())
            {
                case 1: //SPAWNED - Twilight realm
                    if (m_uiDuskTimer <= uiDiff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                            DoCast(SPELL_DUSK_SHROUD);
                        m_uiDuskTimer = 2*IN_MILLISECONDS;
                    } else m_uiDuskTimer -= uiDiff;

                    if (m_uiDarkBreathTimer <= uiDiff)
                    {
                        DoCast(SPELL_DARK_BREATH);
                        m_uiDarkBreathTimer = urand(12*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiDarkBreathTimer -= uiDiff;

                    if (m_uiTailLashTimer <= uiDiff)
                    {
                        DoCast(SPELL_TAIL_LASH);
                        m_uiTailLashTimer = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiTailLashTimer -= uiDiff;

                    if (m_uiSoulCunsumTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 45.0f, true))
                            DoCast(pTarget, SPELL_SOUL_CONSUMPTION);
                        else if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                            DoCast(pTarget, SPELL_SOUL_CONSUMPTION);
                        m_uiSoulCunsumTimer = urand(25*IN_MILLISECONDS,40*IN_MILLISECONDS);
                    } else m_uiSoulCunsumTimer -= uiDiff;

                    if (HealthBelowPct(51))	{setStage(2);}
                    break;
                case 2: //To two realms
                    pInstance->SetData(TYPE_HALION_EVENT, IN_PROGRESS);
                    DoScriptText(-1666109,me);
                    if (GameObject* pGoPortal = me->SummonGameObject(GO_HALION_PORTAL_3, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 4.47206f, 0, 0, 0.786772f, -0.617243f, 99999999))
                    {
                        pGoPortal->SetPhaseMask(32,true);
                        pGoPortal->SetRespawnTime(9999999);
                        pGoPortal->SetOwnerGUID(NULL);
                    }
                    DoCast(SPELL_TWILIGHT_DIVISION);
                    setStage(3);
                    break;
                case 3: //PHASE 3 BOTH REALMS
					if (m_uiDuskTimer <= uiDiff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                           DoCast(SPELL_DUSK_SHROUD);
                        m_uiDuskTimer = 2*IN_MILLISECONDS;
                    } else m_uiDuskTimer -= uiDiff;

                    if (m_uiDarkBreathTimer <= uiDiff)
                    {
                        DoCast(SPELL_DARK_BREATH);
                        m_uiDarkBreathTimer = urand(12*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiDarkBreathTimer -= uiDiff;

                    if (m_uiTailLashTimer <= uiDiff)
                    {
                        DoCast(SPELL_TAIL_LASH);
                        m_uiTailLashTimer = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);
                    } else m_uiTailLashTimer -= uiDiff;

                    if (m_uiSoulCunsumTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 45.0f, true))
                            DoCast(pTarget, SPELL_SOUL_CONSUMPTION);
                        else if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCast(pTarget, SPELL_SOUL_CONSUMPTION);
                        m_uiSoulCunsumTimer = urand(25*IN_MILLISECONDS,40*IN_MILLISECONDS);
                    } else m_uiSoulCunsumTimer -= uiDiff;
                    break;
                default:
                    break;
            }

            if (m_uiEnrage <= uiDiff)
            {
                DoCast(SPELL_BERSERK);
                m_uiEnrage = 600*IN_MILLISECONDS;
                DoScriptText(-1666105,me);
            } else m_uiEnrage -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};


/*######
## mob_halion_control
######*/

struct HalionBuffLine
{
    uint32 real, twilight; // Buff pair
	uint8 disp_corp;           // Displayed Corporeality
};

static HalionBuffLine Buff[]=
{
    {SPELL_CORPOREALITY_100D , SPELL_CORPOREALITY_100I , 0  },
    {SPELL_CORPOREALITY_80D  , SPELL_CORPOREALITY_80I  , 10 },
    {SPELL_CORPOREALITY_60D  , SPELL_CORPOREALITY_60I  , 20 },
    {SPELL_CORPOREALITY_40D  , SPELL_CORPOREALITY_40I  , 30 },
    {SPELL_CORPOREALITY_20D  , SPELL_CORPOREALITY_20I  , 40 },
    {SPELL_CORPOREALITY_EVEN , SPELL_CORPOREALITY_EVEN , 50 },
    {SPELL_CORPOREALITY_20I  , SPELL_CORPOREALITY_20D  , 60 },
    {SPELL_CORPOREALITY_40I  , SPELL_CORPOREALITY_40D  , 70 },
    {SPELL_CORPOREALITY_60I  , SPELL_CORPOREALITY_60D  , 80 },
    {SPELL_CORPOREALITY_80I  , SPELL_CORPOREALITY_80D  , 90 },
    {SPELL_CORPOREALITY_100I , SPELL_CORPOREALITY_100D , 100 },
};


class mob_halion_control : public CreatureScript
{
public:
    mob_halion_control() : CreatureScript("mob_halion_control") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_halion_controlAI(pCreature);
    }

    struct mob_halion_controlAI : public ScriptedAI
    {
        mob_halion_controlAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;
        Creature* pHalionReal;
        Creature* pHalionTwilight;
        uint32 m_lastBuffReal, m_lastBuffTwilight, m_lastBuffNum;
        uint32 m_uiCorporealityTimer;
        bool m_detectplayers;
		uint8 m_lastCorpReal;

        void Reset()
        {
            if (!pInstance) return;

            m_uiCorporealityTimer = 5*IN_MILLISECONDS;
            m_detectplayers = true;
            me->SetDisplayId(11686);
            me->SetPhaseMask(65535, true);
            me->SetRespawnDelay(7*DAY);
            SetCombatMovement(false);
            m_lastBuffReal = 0;
            m_lastBuffTwilight = 0;
			m_lastBuffNum = 5;
			m_lastCorpReal = 50;
            pInstance->SetData(TYPE_COUNTER, COUNTER_OFF);
            pInstance->SetData(TYPE_HALION_EVENT, NOT_STARTED);
        }

        void AttackStart(Unit *who)
        {
            //ignore all attackstart commands
            return;
        }

        bool doSearchPlayerAtRange(float range)
        {
            Map* pMap = me->GetMap();
            if (pMap && pMap->IsDungeon())
            {
                Map::PlayerList const &PlayerList = pMap->GetPlayers();
                if (!PlayerList.isEmpty())
                   for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                   {
                       if (!i->getSource()->IsInMap(me)) continue;
                       if (i->getSource()->isGameMaster()) continue;
                       if (i->getSource()->isAlive() && i->getSource()->IsWithinDistInMap(me, range))
                           return true;
                   }
            }
            return false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!pInstance)
            {
                me->ForcedDespawn();
                return;
            }

            if (pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
            {
                me->ForcedDespawn();
                return;
            }

            if (m_uiCorporealityTimer <= diff)
            {
                if (!doSearchPlayerAtRange(100.0f))
                {
                    sLog->outDebug(LOG_FILTER_MAPS, "ruby_sanctum: cannot detect players in range! ");
                    if (!m_detectplayers)
                    {
                        pInstance->SetData(TYPE_HALION_EVENT, FAIL);
                        pInstance->SetData(TYPE_HALION, FAIL);
                        me->ForcedDespawn();
                    } 
                else 
                {
                    m_detectplayers = false;
                }
            } 
            else 
            {
                m_detectplayers = true;
            }

                if (pInstance->GetData(TYPE_HALION_EVENT) != SPECIAL) return;
				pHalionReal = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_REAL));
				pHalionTwilight = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_TWILIGHT));
				pHalionTwilight->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
				float p_MaxHP = pHalionReal->GetMaxHealth();
				float p_RealHP = (pHalionReal && pHalionReal->isAlive()) ? Rdmg/p_MaxHP*100 : 0.0f;
				float p_TwilightHP = (pHalionTwilight && pHalionTwilight->isAlive()) ? Tdmg/p_MaxHP*100 : 0.0f;
				Rdmg = 0;
				Tdmg = 0;
				float m_diff = (p_TwilightHP - p_RealHP);
				int32 buffnum;

				if (m_diff<0)
				{
					buffnum = m_lastBuffNum - 1;
				}
				else
				{
					if (m_diff>0)
					{
						buffnum = m_lastBuffNum + 1;
					}
					else
					{
						buffnum = m_lastBuffNum;
					}
				}

				if (buffnum<0) buffnum = 0;
				if (buffnum>10) buffnum = 10;
				
				if (!m_lastBuffReal || m_lastBuffReal != Buff[buffnum].real)
				{
					if (pHalionReal && pHalionReal->isAlive())
                    {
						if (m_lastBuffReal)
						{
							pHalionReal->RemoveAurasDueToSpell(m_lastBuffReal);
						}
						pHalionReal->CastSpell(pHalionReal, Buff[buffnum].real, true);
                        m_lastBuffReal = Buff[buffnum].real;
					}
				}

                if (m_lastCorpReal - Buff[buffnum].disp_corp < 0)
                {
                    DoScriptText(EMOTE_REAL_PULL, pHalionReal);
                    DoScriptText(EMOTE_TWIL_PUSH, pHalionTwilight);
                }
                else if (m_lastCorpReal - Buff[buffnum].disp_corp > 0)
                {
                    DoScriptText(EMOTE_REAL_PUSH, pHalionReal);
                    DoScriptText(EMOTE_TWIL_PULL, pHalionTwilight);
                }
				
                m_lastBuffReal = Buff[buffnum].real;
                m_lastCorpReal = (uint8)Buff[buffnum].disp_corp;
                m_lastBuffNum = buffnum;
				
				if (!m_lastBuffTwilight || m_lastBuffTwilight != Buff[buffnum].twilight)
                {
                    if (pHalionTwilight && pHalionTwilight->isAlive())
                    {
                        if (m_lastBuffTwilight)
						{
							pHalionTwilight->RemoveAurasDueToSpell(m_lastBuffTwilight);
						}
                        pHalionTwilight->CastSpell(pHalionTwilight, Buff[buffnum].twilight, true);
                        m_lastBuffTwilight = Buff[buffnum].twilight;
                    }
                }

                pInstance->SetData(TYPE_COUNTER, m_lastCorpReal);

                m_uiCorporealityTimer = 10*IN_MILLISECONDS;

            } else m_uiCorporealityTimer -= diff;

        }

    };
};


/*######
## mob_orb_rotation_focus
######*/
class mob_orb_rotation_focus : public CreatureScript
{
public:
    mob_orb_rotation_focus() : CreatureScript("mob_orb_rotation_focus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_orb_rotation_focusAI(pCreature);
    }

    struct mob_orb_rotation_focusAI : public ScriptedAI
    {
        mob_orb_rotation_focusAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;

        uint32 m_timer;
		float m_direction, m_nextdirection;
		bool m_warning;
		bool m_warning2;
		Creature* m_pulsar_N;
		Creature* m_pulsar_S;
		Creature* m_pulsar_E;
		Creature* m_pulsar_W;	

        void Reset()
        {
            //me->SetDisplayId(11686);
            me->SetRespawnDelay(7*DAY);
            me->SetPhaseMask(65535, true);
            SetCombatMovement(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_direction = 0.0f;
            m_nextdirection = 0.0f;
            m_timer = 50000;
            m_warning = false;

            m_pulsar_N = me->GetMap()->GetCreature(pInstance->GetData64(NPC_SHADOW_PULSAR_N));
			if (!m_pulsar_N )
			{
				float x,y;
				me->GetNearPoint2D(x, y, FR_RADIUS, m_direction);
				m_pulsar_N = me->SummonCreature(NPC_SHADOW_PULSAR_N, x, y, me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
			} else if (!m_pulsar_N->isAlive())
                    m_pulsar_N->Respawn();

			m_pulsar_S = me->GetMap()->GetCreature(pInstance->GetData64(NPC_SHADOW_PULSAR_S));
			if (!m_pulsar_S)
			{
				float x,y;
				me->GetNearPoint2D(x, y, FR_RADIUS, m_direction + M_PI);
				m_pulsar_S = me->SummonCreature(NPC_SHADOW_PULSAR_S, x, y, me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
			} else if (!m_pulsar_S->isAlive())
						m_pulsar_S->Respawn();
			}

        void AttackStart(Unit *who)
        {
            //ignore all attackstart commands
            return;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!pInstance)
                  me->ForcedDespawn();
            if (pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
                  me->ForcedDespawn();

            if (pInstance->GetData(DATA_ORB_S) == DONE && pInstance->GetData(DATA_ORB_N) == DONE)
            {
                m_direction = m_nextdirection;
                m_nextdirection = (m_direction - M_PI/64.0f);
                if (m_nextdirection < 0.0f ) m_nextdirection = m_nextdirection + 2.0f*M_PI;
                pInstance->SetData(DATA_ORB_DIRECTION, (uint32)(m_nextdirection*1000));
                pInstance->SetData(DATA_ORB_N, SPECIAL);
                pInstance->SetData(DATA_ORB_S, SPECIAL);
                sLog->outDebug(LOG_FILTER_MAPS, "EventMGR: creature %u send direction %u ",me->GetEntry(),pInstance->GetData(DATA_ORB_DIRECTION));
            }

            if (m_timer%30000 - 3000 <= uiDiff && !m_warning)
            {
                DoScriptText(-1666110,me);
                m_warning = true;
            }
			
			if (m_timer%30000 - 1000 < uiDiff && !m_warning2)
			{
				Creature * pHalionTwilight = me->GetMap()->GetCreature(pInstance->GetData64(NPC_HALION_TWILIGHT));
				if (pHalionTwilight)
				{
					DoScriptText(SAY_HALION_SPECIAL_2, pHalionTwilight);
					m_warning2 = true;
				}
			}
			
			if (m_timer > 20000 && m_timer < 30000)
			{
				m_pulsar_N->CastSpell(m_pulsar_S, SPELL_TWILIGHT_CUTTER_CHANNEL, true);

				Map* pMap = me->GetMap();
				Map::PlayerList const &pList = pMap->GetPlayers();
					if (pList.isEmpty()) return;

				for(Map::PlayerList::const_iterator i = pList.begin(); i != pList.end(); ++i)
				{
					if (Player* player = i->getSource())
					{
						if (!player->HasAura(SPELL_TWILIGHT_ENTER)) 
							return;
						if (player->isAlive())
						{
							float AB = m_pulsar_N->GetDistance2d(m_pulsar_S)+1;
							float BC = m_pulsar_N->GetDistance2d(player)+1;
							float AC = m_pulsar_S->GetDistance2d(player)+1;
							float p = (AB + BC + AC)/2;
							float DC = (2*sqrt(p*(p-AB)*(p-BC)*(p-AC)))/AB;
							//debug_log("DC = %06.6f (AB = %06.6f, BC = %06.6f, AC = %06.6f, p = %06.6f)", DC, AB, BC, AC, p);
							if (DC < 3.75f || DC > 52.0f)
							{
								player->CastSpell(player, SPELL_TWILIGHT_CUTTER, true, 0, 0, m_pulsar_N->GetGUID());
							}
						}
					}
				}
			}

			if (m_timer <= uiDiff)
			{
				float x,y;
				me->GetNearPoint2D(x, y, FR_RADIUS, m_nextdirection);
				me->SummonCreature(NPC_ORB_CARRIER, x, y, me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
				m_timer = 50000;
				m_warning = false;
			} else m_timer -= uiDiff;
        }
    };
};


/*######
## mob_halion_orb
######*/
class mob_halion_orb : public CreatureScript
{
public:
    mob_halion_orb() : CreatureScript("mob_halion_orb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_halion_orbAI(pCreature);
    }

    struct mob_halion_orbAI : public ScriptedAI
    {
        mob_halion_orbAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;

        float m_direction,m_delta;
        uint32 m_flag;
        uint32 m_flag1;
        bool MovementStarted;
        Creature* focus;
        uint32 nextPoint;
		uint32 tc_timmer;

        void Reset()
        {
            if (!pInstance) return;
            me->SetRespawnDelay(7*DAY);
            SetCombatMovement(false);
			tc_timmer = 30000;
            me->SetPhaseMask(32, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            if (me->GetEntry() == NPC_SHADOW_PULSAR_N)
            {
                m_flag = DATA_ORB_N;
                m_delta = 0.0f;
            } else if (me->GetEntry() == NPC_SHADOW_PULSAR_S)
            {
                m_flag = DATA_ORB_S;
                m_delta = M_PI;
            };
			me->SetSpeed(MOVE_WALK, 8.0f);
			me->SetSpeed(MOVE_RUN, 8.0f);
            m_direction = 0.0f;
            nextPoint = 0;
            MovementStarted = false;
            pInstance->SetData(m_flag, DONE);
            sLog->outDebug(LOG_FILTER_MAPS, "EventMGR: creature %u assume m_flag %u ",me->GetEntry(),m_flag);
        }

        void AttackStart(Unit *who)
        {
            //ignore all attackstart commands
            return;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (!pInstance) return;

            if (type != POINT_MOTION_TYPE || !MovementStarted) return;

            if (id == nextPoint)
			{
				me->GetMotionMaster()->MovementExpired();
                MovementStarted = false;
                pInstance->SetData(m_flag, DONE);
            }
        }

        void StartMovement(uint32 id)
        {
            if (!pInstance) return;
            nextPoint = id;
            float x,y;
            pInstance->SetData(m_flag, IN_PROGRESS);
            MovementStarted = true;
            m_direction = ((float)pInstance->GetData(DATA_ORB_DIRECTION)/1000 + m_delta);
            if (m_direction > 2.0f*M_PI) m_direction = m_direction - 2.0f*M_PI;
            if (focus = me->GetMap()->GetCreature(pInstance->GetData64(NPC_ORB_ROTATION_FOCUS)))
                focus->GetNearPoint2D(x, y, FR_RADIUS, m_direction);
                else me->ForcedDespawn();
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(id, x, y, me->GetPositionZ());
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!pInstance)
                  me->ForcedDespawn();
            if (pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
                  me->ForcedDespawn();

            if (!MovementStarted && pInstance->GetData(m_flag) == SPECIAL)
            {
				StartMovement(1);
            }

        }
    };
};


/*######
## mob_orb_carrier
######*/
class mob_orb_carrier : public CreatureScript
{
public:
    mob_orb_carrier() : CreatureScript("mob_orb_carrier") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_orb_carrierAI(pCreature);
    }

    struct mob_orb_carrierAI : public ScriptedAI
    {
        mob_orb_carrierAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;

        bool MovementStarted;

        void Reset()
        {
            me->SetRespawnDelay(7*DAY);
            SetCombatMovement(false);
            me->SetPhaseMask(32, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            MovementStarted = false;
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING); //or remove???
            me->SetSpeed(MOVE_RUN, 10.0f, true);
        }

        void AttackStart(Unit *pWho)
        {
            return;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (!pInstance) return;

            if (type != POINT_MOTION_TYPE || !MovementStarted) return;

            if (id == 1)
			{
                me->GetMotionMaster()->MovementExpired();
                MovementStarted = false;
				me->ForcedDespawn();
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!pInstance || pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
                  me->ForcedDespawn();

            if (!MovementStarted)
			{
				float x,y;
				float m_direction = ((float)pInstance->GetData(DATA_ORB_DIRECTION)/1000.0f + M_PI - M_PI/32.0f);
				if (m_direction > 2.0f*M_PI) m_direction = m_direction - 2.0f*M_PI;
				if (Creature* focus = me->GetMap()->GetCreature(pInstance->GetData64(NPC_ORB_ROTATION_FOCUS)))
					focus->GetNearPoint2D(x, y, FR_RADIUS, m_direction);
				else me->ForcedDespawn();
				me->GetMotionMaster()->Clear();
				me->GetMotionMaster()->MovePoint(1, x, y, me->GetPositionZ());
				MovementStarted = true;
			}

        }

    };
};

/*######
## mob_soul_consumption
######*/
class mob_soul_consumption : public CreatureScript
{
public:
    mob_soul_consumption() : CreatureScript("mob_soul_consumption") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_soul_consumptionAI(pCreature);
    }

    struct mob_soul_consumptionAI : public ScriptedAI
    {
        mob_soul_consumptionAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        float m_Size0;
        float m_Size;
        uint32 m_uiConsumptTimer;
		bool grow;

        void Reset()
        {
            me->SetPhaseMask(32,true);
            SetCombatMovement(false);
            m_uiConsumptTimer = 60*IN_MILLISECONDS;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoCast(SPELL_CONSUMPTION_AURA);
            m_Size0 = me->GetFloatValue(OBJECT_FIELD_SCALE_X);
            m_Size = m_Size0;
			grow = false;
        }

        void AttackStart(Unit *pWho)
        {
            return;
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
                me->ForcedDespawn();

            if (m_uiConsumptTimer <= diff)
            {
                me->ForcedDespawn();
            } 
			else m_uiConsumptTimer -= diff;

			Map::PlayerList const &players = m_pInstance->instance->GetPlayers();
			for(Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
			{
				if(Player* pPlayer = i->getSource())
				{
					if(pPlayer->isAlive() && pPlayer->HasAura(SPELL_MARK_OF_CONSUMPTION))
					{
						Aura *pAura = pPlayer->GetAura(SPELL_MARK_OF_CONSUMPTION);
						uint32 stacs;
						stacs= pAura->GetStackAmount();
						if(!grow)
						{
							m_Size = (m_Size + (stacs*0.1));
							me->SetFloatValue(OBJECT_FIELD_SCALE_X, m_Size);
							m_pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_CONSUMPTION);
							grow = true;
						}
					}
				}
			}
        }
    };
};

/*######
## mob_fiery_combustion
######*/
class mob_fiery_combustion : public CreatureScript
{
public:
    mob_fiery_combustion() : CreatureScript("mob_fiery_combustion") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_fiery_combustionAI(pCreature);
    }

    struct mob_fiery_combustionAI : public ScriptedAI
    {
        mob_fiery_combustionAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (InstanceScript*)pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        float m_Size0;
        float m_Size;
        uint32 m_uiConbustTimer;
		bool grow;

        void Reset()
        {
			me->SetPhaseMask(1,true);
            m_uiConbustTimer = 60*IN_MILLISECONDS;
            SetCombatMovement(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoCast(SPELL_COMBUSTION_AURA);
            m_Size0 = me->GetFloatValue(OBJECT_FIELD_SCALE_X);
            m_Size = m_Size0;
			grow = false;
        }

        void AttackStart(Unit *pWho)
        {
            return;
        }

        void UpdateAI(const uint32 diff)
        {
            if(m_pInstance && m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
                me->ForcedDespawn();

            if (m_uiConbustTimer <= diff)
            {
                me->ForcedDespawn();
            } else m_uiConbustTimer -= diff;

			Map::PlayerList const &players = m_pInstance->instance->GetPlayers();
			for(Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
			{
				if(Player* pPlayer = i->getSource())
				{
					if(pPlayer->isAlive() && pPlayer->HasAura(SPELL_MARK_OF_COMBUSTION))
					{
						Aura *pAura = pPlayer->GetAura(SPELL_MARK_OF_COMBUSTION);
						uint32 stacs;
						stacs= pAura->GetStackAmount();
						if(!grow)
						{
							m_Size = (m_Size + (stacs*0.1));
							me->SetFloatValue(OBJECT_FIELD_SCALE_X, m_Size);
							me->RemoveAura(SPELL_MARK_OF_COMBUSTION, pPlayer->GetGUID());
							m_pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MARK_OF_COMBUSTION);
							grow = true;
						}
					}
				}
			}
        }

    };
};

/*######
## mob_halion_meteor
######*/
#define TARGETS_10 5
#define TARGETS_25 7
class mob_halion_meteor : public CreatureScript
{
public:
    mob_halion_meteor() : CreatureScript("mob_halion_meteor") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_halion_meteorAI(pCreature);
    }

    struct mob_halion_meteorAI : public ScriptedAI
    {
        mob_halion_meteorAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            Reset();
        }

        float direction;
        uint8 stage;
        uint32 m_uiMeteorImpactTimer;
        uint32 m_uiMeteorStrikeTimer;

        void setStage(uint8 phase)
        {
            stage = phase;
        }

        uint8 getStage()
        {
            return stage;
        }

        void Reset()
        {
            me->SetDisplayId(11686);
            me->SetRespawnDelay(7*DAY);
            SetCombatMovement(false);
            m_uiMeteorImpactTimer = 0.5*IN_MILLISECONDS;
            m_uiMeteorStrikeTimer = 4.5*IN_MILLISECONDS;
            setStage(0);
            me->SetInCombatWithZone();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            switch (getStage())
            {
                case 0:
                    if (m_uiMeteorImpactTimer <= uiDiff)
                    {
                        DoCast(SPELL_METEOR_IMPACT);
                        m_uiMeteorImpactTimer = 0.5*IN_MILLISECONDS;
                        setStage(1);
                    } else m_uiMeteorImpactTimer -= uiDiff;
                    break;
                case 1:
                    if (m_uiMeteorStrikeTimer <= uiDiff)
                    {
                        DoCast(SPELL_METEOR_STRIKE);
                        m_uiMeteorStrikeTimer = 4.5*IN_MILLISECONDS;
                        setStage(2);
                    } else m_uiMeteorStrikeTimer -= uiDiff;
                    break;
                case 2:
                    // Place summon flames there
                    {
                        direction = 2.0f*M_PI*((float)urand(0,15)/16.0f);
                        float x, y, radius;
                        radius = 0.0f;
                        for(uint8 i = 0; i < RAID_MODE(TARGETS_10,TARGETS_25,TARGETS_10,TARGETS_25); ++i)
                        {
                            radius = radius + 5.0f;
                            me->GetNearPoint2D(x, y, radius, direction);
                            me->SummonCreature(NPC_METEOR_STRIKE_1, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                            me->GetNearPoint2D(x, y, radius, direction+M_PI);
                            me->SummonCreature(NPC_METEOR_STRIKE_1, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                        }
                    };
                    {
                        direction = direction + M_PI/4;
                        float x, y, radius;
                        radius = 0.0f;
                        for(uint8 i = 0; i < RAID_MODE(TARGETS_10,TARGETS_25,TARGETS_10,TARGETS_25); ++i)
                        {
                            radius = radius + 5.0f;
                            me->GetNearPoint2D(x, y, radius, direction);
                            me->SummonCreature(NPC_METEOR_STRIKE_1, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                            me->GetNearPoint2D(x, y, radius, direction+M_PI);
                            me->SummonCreature(NPC_METEOR_STRIKE_1, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                        }
                    };
                    setStage(3);
                    break;
                case 3:
                    if (m_uiMeteorImpactTimer <= uiDiff)
                    {
                        DoCast(SPELL_METEOR_IMPACT);
                        me->ForcedDespawn();
                        m_uiMeteorImpactTimer = 0.5*IN_MILLISECONDS;
                    } else m_uiMeteorImpactTimer -= uiDiff;
                    break;
                default:
                     break;
            }
        }
    };
};


/*######
## mob_halion_flame
######*/
class mob_halion_flame : public CreatureScript
{
public:
    mob_halion_flame() : CreatureScript("mob_halion_flame") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_halion_flameAI(pCreature);
    }

    struct mob_halion_flameAI : public ScriptedAI
    {
        mob_halion_flameAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            Reset();
        }

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisplayId(11686);
            me->SetRespawnDelay(7*DAY);
            SetCombatMovement(false);
            me->SetInCombatWithZone();
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!me->HasAura(SPELL_METEOR_FLAME))
                DoCast(SPELL_METEOR_FLAME);
        }

    };
};


class go_halion_portal_twilight : public GameObjectScript
{
    public:

        go_halion_portal_twilight() : GameObjectScript("go_halion_portal_twilight") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            InstanceScript* pInstance = (InstanceScript*)go->GetInstanceScript();
            if(!pInstance) return false;
            player->CastSpell(player,SPELL_TWILIGHT_ENTER,false);
            return true;
        }
};

class go_halion_portal_real : public GameObjectScript
{
    public:

        go_halion_portal_real() : GameObjectScript("go_halion_portal_real") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            InstanceScript* pInstance = (InstanceScript*)go->GetInstanceScript();
            if(!pInstance) return false;
            player->RemoveAurasDueToSpell(SPELL_TWILIGHT_ENTER);
            return true;
        }
};


/*######
## spell_halion_fiery_combustion 74562
## DELETE FROM `spell_script_names` WHERE `spell_id`=74562 AND `ScriptName`='spell_halion_fiery_combustion';
## INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74562,'spell_halion_fiery_combustion');
######*/
class spell_halion_fiery_combustion : public SpellScriptLoader
{
    public:
        spell_halion_fiery_combustion() : SpellScriptLoader("spell_halion_fiery_combustion") { }

        class spell_halion_fiery_combustion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_fiery_combustion_AuraScript)
            enum Spells
            {
                SPELL_MARK_OF_COMBUSTION = 74567,
                SPELL_COMBUSTION_EXPLODE = 74607
            };

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MARK_OF_COMBUSTION))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_COMBUSTION_EXPLODE))
                    return false;
                return true;
            }

            void HandlePeriodicTick(AuraEffect const * /*aurEff*/)
            {
                if (Unit* pTarget = GetTarget())
                    pTarget->CastSpell(pTarget, SPELL_MARK_OF_COMBUSTION, true);
            }

            void HandleEffectRemove(AuraEffect const * /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* pTarget = GetTarget())
                {
                    if (Aura *mark = pTarget->GetAura(SPELL_MARK_OF_COMBUSTION))
                    {
                        int32 bp = 2000 * mark->GetStackAmount();
                        pTarget->CastCustomSpell(pTarget, SPELL_COMBUSTION_EXPLODE, &bp, 0, 0, true);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_fiery_combustion_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                OnEffectRemove += AuraEffectRemoveFn(spell_halion_fiery_combustion_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_fiery_combustion_AuraScript();
        }
};

/*######
## spell_halion_soul_consumption 74792
## DELETE FROM `spell_script_names` WHERE `spell_id`=74792 AND `ScriptName`='spell_halion_soul_consumption';
## INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (74792,'spell_halion_soul_consumption');
######*/
class spell_halion_soul_consumption : public SpellScriptLoader
{
    public:
        spell_halion_soul_consumption() : SpellScriptLoader("spell_halion_soul_consumption") { }

        class spell_halion_soul_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_soul_consumption_AuraScript)
            enum Spells
            {
                SPELL_MARK_OF_CONSUMPTION = 74795,
                SPELL_CONSUMPTION_EXPLODE = 74799
            };

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MARK_OF_CONSUMPTION))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_CONSUMPTION_EXPLODE))
                    return false;
                return true;
            }

            void HandlePeriodicTick(AuraEffect const * /*aurEff*/)
            {
                if (Unit* pTarget = GetTarget())
                    pTarget->CastSpell(pTarget, SPELL_MARK_OF_CONSUMPTION, true);
            }

            void HandleEffectRemove(AuraEffect const * /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* pTarget = GetTarget())
                {
                    if (Aura *mark = pTarget->GetAura(SPELL_MARK_OF_CONSUMPTION))
                    {
                        int32 bp = 2000 * mark->GetStackAmount();
                        pTarget->CastCustomSpell(pTarget, SPELL_CONSUMPTION_EXPLODE, &bp, 0, 0, true);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_soul_consumption_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                OnEffectRemove += AuraEffectRemoveFn(spell_halion_soul_consumption_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_soul_consumption_AuraScript();
        }
};

void AddSC_boss_halion()
{
    new boss_halion_real();
    new boss_halion_twilight();
    new mob_halion_meteor();
    new mob_halion_flame();
    new mob_halion_orb();
    new mob_halion_control();
    new mob_orb_rotation_focus();
    new mob_orb_carrier();
    new mob_soul_consumption();
    new mob_fiery_combustion();
    new go_halion_portal_twilight();
    new go_halion_portal_real();
    new spell_halion_fiery_combustion();
    new spell_halion_soul_consumption();
}
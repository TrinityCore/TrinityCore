/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
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

/*
    TODO:
        Add achievments
        Boombot explosion only hurt allies to the npc at the moment
        Boombot explosion visual
        Test the enrage timer
        Fix gravity bomb - tractor beam.
        Fix void zone spell
        If the boss is to close to a scrap pile -> no summon
        make the life sparks visible...
*/

#include "ScriptedPch.h"
#include "ulduar.h"

enum Spells
{
    SPELL_TYMPANIC_TANTRUM                      = 62776,
    SPELL_SEARING_LIGHT_10                      = 63018,
    SPELL_SEARING_LIGHT_25                      = 65121,

    SPELL_GRAVITY_BOMB_10                       = 63024,
    SPELL_GRAVITY_BOMB_25                       = 63234,
    SPELL_GRAVITY_BOMB_AURA_10                  = 63025,
    SPELL_GRAVITY_BOMB_AURA_25                  = 63233,

    SPELL_HEARTBREAK_10                         = 65737,
    SPELL_HEARTBREAK_25                         = 64193,

    SPELL_ENRAGE                                = 26662,

    //------------------VOID ZONE--------------------
    SPELL_VOID_ZONE_10                          = 64203,
    SPELL_VOID_ZONE_25                          = 64235,

    // Life Spark
    SPELL_STATIC_CHARGED_10                     = 64227,
    SPELL_STATIC_CHARGED_25                     = 64236,
    SPELL_SHOCK                                 = 64230,

    //----------------XT-002 HEART-------------------
    SPELL_EXPOSED_HEART                         = 63849,

    //---------------XM-024 PUMMELLER----------------
    SPELL_ARCING_SMASH                          = 8374,
    SPELL_TRAMPLE                               = 5568,
    SPELL_UPPERCUT                              = 10966,

    //------------------BOOMBOT-----------------------
    SPELL_BOOM                                  = 62834,
};

enum Timers
{
    TIMER_TYMPANIC_TANTRUM_MIN                  = 32000,
    TIMER_TYMPANIC_TANTRUM_MAX                  = 36000,
    TIMER_SEARING_LIGHT                         = 20000,
    TIMER_SPAWN_LIFE_SPARK                      = 9000,
    TIMER_GRAVITY_BOMB                          = 20000,
    TIMER_HEART_PHASE                           = 30000,
    TIMER_ENRAGE                                = 600000,
    TIMER_GRAVITY_BOMB_AURA                     = 8900,

    TIMER_VOID_ZONE                             = 3000,

    // Life Spark
    TIMER_SHOCK                                 = 12000,

    // Pummeller
    // Timers may be off
    TIMER_ARCING_SMASH                          = 27000,
    TIMER_TRAMPLE                               = 22000,
    TIMER_UPPERCUT                              = 17000,

    TIMER_SPAWN_ADD                             = 12000,
};

enum Creatures
{
    NPC_VOID_ZONE                               = 34001,
    NPC_LIFE_SPARK                              = 34004,
    NPC_XT002_HEART                             = 33329,
    NPC_XS013_SCRAPBOT                          = 33343,
    NPC_XM024_PUMMELLER                         = 33344,
    NPC_XE321_BOOMBOT                           = 33346,
};

enum Actions
{
    ACTION_ENTER_HARD_MODE                      = 0,
};

enum XT002Data
{
    DATA_TRANSFERED_HEALTH                      = 0,
};

enum Yells
{
    SAY_AGGRO                                   = -1603300,
    SAY_HEART_OPENED                            = -1603301,
    SAY_HEART_CLOSED                            = -1603302,
    SAY_TYMPANIC_TANTRUM                        = -1603303,
    SAY_SLAY_1                                  = -1603304,
    SAY_SLAY_2                                  = -1603305,
    SAY_BERSERK                                 = -1603306,
    SAY_DEATH                                   = -1603307,
    SAY_SUMMON                                  = -1603308,
};

//#define GRAVITY_BOMB_DMG_MIN_10                11700
//#define GRAVITY_BOMB_DMG_MAX_10                12300
//#define GRAVITY_BOMB_DMG_MIN_25                14625
//#define GRAVITY_BOMB_DMG_MAX_25                15375
//#define GRAVITY_BOMB_RADIUS                    12

//#define VOID_ZONE_DMG_10                      5000
//#define VOID_ZONE_DMG_25                      7500
//#define VOID_ZONE_RADIUS                      


/************************************************
-----------------SPAWN LOCATIONS-----------------
************************************************/
//Shared Z-level
#define SPAWN_Z                                 412
//Lower right
#define LR_X                                    796
#define LR_Y                                    -94
//Lower left
#define LL_X                                    796
#define LL_Y                                    57
//Upper right
#define UR_X                                    890
#define UR_Y                                    -82
//Upper left
#define UL_X                                    894
#define UL_Y                                    62

/*-------------------------------------------------------
 *
 *        XT-002 DECONSTRUCTOR
 *
 *///----------------------------------------------------
struct boss_xt002_AI : public BossAI
{
    boss_xt002_AI(Creature *pCreature) : BossAI(pCreature, TYPE_XT002)
    {
    }

    uint32 uiSearingLightTimer;
    uint32 uiSpawnLifeSparkTimer;
    uint32 uiGravityBombTimer;
    uint32 uiGravityBombAuraTimer;
    uint32 uiTympanicTantrumTimer;
    uint32 uiHeartPhaseTimer;
    uint32 uiSpawnAddTimer;
    uint32 uiEnrageTimer;
    
    bool searing_light_active;
    uint64 uiSearingLightTarget;

    bool gravity_bomb_active;
    uint64 uiGravityBombTarget;

    uint8 phase;
    uint8 heart_exposed;
    bool enraged;

    uint32 transferHealth;
    bool enterHardMode;
    bool hardMode;

    void Reset()
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);

        //Makes XT-002 to cast a light bomb 10 seconds after aggro.
        uiSearingLightTimer = TIMER_SEARING_LIGHT/2;
        uiSpawnLifeSparkTimer = TIMER_SPAWN_LIFE_SPARK;
        uiGravityBombTimer = TIMER_GRAVITY_BOMB;
        uiGravityBombAuraTimer = TIMER_GRAVITY_BOMB_AURA;
        uiHeartPhaseTimer = TIMER_HEART_PHASE;
        uiSpawnAddTimer = TIMER_SPAWN_ADD;
        uiEnrageTimer = TIMER_ENRAGE;

        //Tantrum is casted a bit slower the first time.
        uiTympanicTantrumTimer = urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX) * 2;

        searing_light_active = false;
        gravity_bomb_active = false;
        enraged = false;
        hardMode = false;
        enterHardMode = false;

        phase = 1;
        heart_exposed = 0;
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        _EnterCombat();
    }

    void DoAction(const int32 action)
    {
        switch (action)
        {
            case ACTION_ENTER_HARD_MODE:
                if (!hardMode)
                {
                    hardMode = true;

                    // Enter hard mode
                    enterHardMode = true;

                    // set max health
                    m_creature->SetHealth(m_creature->GetMaxHealth());

                    // Get his heartbreak buff
                    m_creature->CastSpell(m_creature, RAID_MODE(SPELL_HEARTBREAK_10, SPELL_HEARTBREAK_25), true);
                }
                break;
        }
    }

    void SetData(uint32 id, uint32 value)
    {
        switch(id)
        {
            case DATA_TRANSFERED_HEALTH:
                transferHealth = value;
                break;
        }
    }

    void KilledUnit(Unit* victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);
        _JustDied();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (enterHardMode)
        {
            SetPhaseOne();
            enterHardMode = false;
        }

        // Handles spell casting. These spells only occur during phase 1 and hard mode
        if (phase == 1 || hardMode)
        {
            if (uiSearingLightTimer <= diff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(pTarget, RAID_MODE(SPELL_SEARING_LIGHT_10, SPELL_SEARING_LIGHT_25));
                    uiSearingLightTarget = pTarget->GetGUID();
                }
                uiSpawnLifeSparkTimer = TIMER_SPAWN_LIFE_SPARK;
                if (hardMode)
                    searing_light_active = true;
                uiSearingLightTimer = TIMER_SEARING_LIGHT;
            } else uiSearingLightTimer -= diff;

            if (uiGravityBombTimer <= diff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(pTarget, RAID_MODE(SPELL_GRAVITY_BOMB_10,SPELL_GRAVITY_BOMB_25));
                    uiGravityBombTarget = pTarget->GetGUID();
                }
                uiGravityBombTimer = TIMER_GRAVITY_BOMB;
                gravity_bomb_active = true;
            } else uiGravityBombTimer -= diff;

            if (uiTympanicTantrumTimer <= 0)
            {
                DoScriptText(SAY_TYMPANIC_TANTRUM, m_creature);
                DoCast(SPELL_TYMPANIC_TANTRUM);
                uiTympanicTantrumTimer = urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX);
            } else uiTympanicTantrumTimer -= diff;
        }

        if (!hardMode)
        {
            if (phase == 1)
            {
                if (HealthBelowPct(75) && heart_exposed == 0)
                {
                    exposeHeart();
                }
                else if (HealthBelowPct(50) && heart_exposed == 1)
                {
                    exposeHeart();
                }
                else if (HealthBelowPct(25) && heart_exposed == 2)
                {
                    exposeHeart();
                }

                DoMeleeAttackIfReady();
            }
            else
            {
                //Stop moving
                m_creature->StopMoving();

                //Start summoning adds
                if (uiSpawnAddTimer <= diff)
                {
                    DoScriptText(SAY_SUMMON, m_creature);

                    // Spawn Pummeller
                    switch (rand() % 4)
                    {
                        case 0: m_creature->SummonCreature(NPC_XM024_PUMMELLER, LR_X, LR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        case 1: m_creature->SummonCreature(NPC_XM024_PUMMELLER, LL_X, LL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        case 2: m_creature->SummonCreature(NPC_XM024_PUMMELLER, UR_X, UR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        case 3: m_creature->SummonCreature(NPC_XM024_PUMMELLER, UL_X, UL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                    }

                    // Spawn 5 Bombs
                    for (int8 n = 0; n < 5; n++)
                    {
                        //Some randomes are added so they wont spawn in a pile
                        switch(rand() % 4)
                        {
                            case 0: m_creature->SummonCreature(NPC_XS013_SCRAPBOT, irand(LR_X - 3, LR_X + 3), irand(LR_Y - 3, LR_Y + 3), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                            case 1: m_creature->SummonCreature(NPC_XS013_SCRAPBOT, irand(LL_X - 3, LL_X + 3), irand(LL_Y - 3, LL_Y + 3), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                            case 2: m_creature->SummonCreature(NPC_XS013_SCRAPBOT, irand(UR_X - 3, UR_X + 3), irand(UR_Y - 3, UR_Y + 3), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                            case 3: m_creature->SummonCreature(NPC_XS013_SCRAPBOT, irand(UL_X - 3, UL_X + 3), irand(UL_Y - 3, UL_Y + 3), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        }
                    }
            
                    //Spawn 5 Scrapbots
                    switch (rand() % 4)
                    {
                        case 0: m_creature->SummonCreature(NPC_XE321_BOOMBOT, LR_X, LR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        case 1: m_creature->SummonCreature(NPC_XE321_BOOMBOT, LL_X, LL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        case 2: m_creature->SummonCreature(NPC_XE321_BOOMBOT, UR_X, UR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                        case 3: m_creature->SummonCreature(NPC_XE321_BOOMBOT, UL_X, UL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                    }

                    uiSpawnAddTimer = TIMER_SPAWN_ADD;
                } else uiSpawnAddTimer -= diff;

                // Is the phase over?
                if (uiHeartPhaseTimer <= diff)
                {
                    DoScriptText(SAY_HEART_CLOSED, m_creature);
                    SetPhaseOne();
                }
                else
                    uiHeartPhaseTimer -= diff;
            }
        }
        else
        {
            // Adding life sparks when searing light debuff runs out if hard mode
            if (searing_light_active)
            {
                if (uiSpawnLifeSparkTimer <= diff)
                {
                    if (Unit *pSearingLightTarget = m_creature->GetUnit(*m_creature, uiSearingLightTarget))
                        pSearingLightTarget->SummonCreature(NPC_LIFE_SPARK, pSearingLightTarget->GetPositionX(), pSearingLightTarget->GetPositionY(), pSearingLightTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                    uiSpawnLifeSparkTimer = TIMER_SPAWN_LIFE_SPARK;
                    searing_light_active = false;
                } else uiSpawnLifeSparkTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
        
        if (gravity_bomb_active)
        {
            if (uiGravityBombAuraTimer <= diff)
            {
                if (Unit *pGravityBombTarget = m_creature->GetUnit(*m_creature, uiGravityBombTarget))
                {
                    pGravityBombTarget->RemoveAurasDueToSpell(RAID_MODE(SPELL_GRAVITY_BOMB_10,SPELL_GRAVITY_BOMB_25));
                    if (hardMode)
                    {
                        //Remains spawned for 3 minutes
                        pGravityBombTarget->SummonCreature(NPC_VOID_ZONE, pGravityBombTarget->GetPositionX(), pGravityBombTarget->GetPositionY(), pGravityBombTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
                    }
                }

                gravity_bomb_active = false;
                uiGravityBombAuraTimer = TIMER_GRAVITY_BOMB_AURA;
                //gravityBomb();
            } else uiGravityBombAuraTimer -= diff;
        }

        //Enrage stuff
        if (!enraged)
            if (uiEnrageTimer <= diff)
            {
                DoScriptText(SAY_BERSERK, m_creature);
                DoCast(m_creature, SPELL_ENRAGE);
                enraged = true;
            } else uiEnrageTimer -= diff;
    }

    void exposeHeart()
    {
        //Make untargetable
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

        //Summon the heart npc
        m_creature->SummonCreature(NPC_XT002_HEART, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ() + 7, 0, TEMPSUMMON_TIMED_DESPAWN, TIMER_HEART_PHASE);
        
        // Start "end of phase 2 timer"
        uiHeartPhaseTimer = TIMER_HEART_PHASE;

        //Phase 2 has offically started
        phase = 2;
        heart_exposed++;

        //Reset the add spawning timer
        uiSpawnAddTimer = TIMER_SPAWN_ADD;

        DoScriptText(SAY_HEART_OPENED, m_creature);
    }

    void SetPhaseOne()
    {
        uiSearingLightTimer = TIMER_SEARING_LIGHT / 2;
        uiGravityBombTimer = TIMER_GRAVITY_BOMB;
        uiTympanicTantrumTimer = urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX);
        uiSpawnAddTimer = TIMER_SPAWN_ADD;

        if (!hardMode)
            m_creature->ModifyHealth(-((int32)transferHealth));

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        phase = 1;
    }

    // TODO: put in comment and kept for reference. The spell should be fixed properly in spell system, if necessary.
    ////Have to do this the custom way since the original spell messes up player movement
    //void gravityBomb()
    //{
    //    uint32 maxDamage = RAID_MODE(GRAVITY_BOMB_DMG_MAX_10, GRAVITY_BOMB_DMG_MAX_25);
    //    uint32 minDamage = RAID_MODE(GRAVITY_BOMB_DMG_MIN_10, GRAVITY_BOMB_DMG_MIN_25);
    //    uint16 range = GRAVITY_BOMB_RADIUS;
    //    Map* pMap = me->GetMap();
    //    if (pMap && pMap->IsDungeon())
    //    {
    //        Map::PlayerList const &PlayerList = pMap->GetPlayers();
    //        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
    //        {
    //            //If a player is within the range of the spell
    //            if (i->getSource() && i->getSource()->GetDistance2d(pGravityBombTarget) <= range)
    //            {
    //                //Deal damage to the victim
    //                int32 damage = urand(minDamage, maxDamage);
    //                i->getSource()->ModifyHealth(-damage);
    //                m_creature->SendSpellNonMeleeDamageLog(i->getSource(), SPELL_GRAVITY_BOMB_AURA_10, damage, SPELL_SCHOOL_MASK_SHADOW, 0, 0, false, 0);

    //                //Replacing the tractor beam effect
    //                i->getSource()->JumpTo(pGravityBombTarget, 5);
    //            }
    //        }
    //    }
    //}
};

CreatureAI* GetAI_boss_xt002(Creature* pCreature)
{
    return new boss_xt002_AI(pCreature);
}

/*-------------------------------------------------------
 *
 *        XT-002 HEART
 *
 *///----------------------------------------------------
struct mob_xt002_heartAI : public ScriptedAI
{
    mob_xt002_heartAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        DoCast(m_creature, SPELL_EXPOSED_HEART);
    }

    ScriptedInstance* m_pInstance;

    void JustDied(Unit *victim)
    {
        if (m_pInstance)
            if (Creature* pXT002 = m_creature->GetCreature(*m_creature, m_pInstance->GetData64(TYPE_XT002)))
                if (pXT002->AI())
                    pXT002->AI()->DoAction(ACTION_ENTER_HARD_MODE);

        //removes the aura
        m_creature->RemoveAurasDueToSpell(SPELL_EXPOSED_HEART);
    }

    void DamageTaken(Unit *pDone, uint32 &damage)
    {
        if (Creature* pXT002 = m_creature->GetCreature(*m_creature, m_pInstance->GetData64(TYPE_XT002)))
            if (pXT002->AI())
            {
                uint32 health = m_creature->GetHealth();
                health -= damage;
                if (health < 0)
                    health = 0;

                pXT002->AI()->SetData(DATA_TRANSFERED_HEALTH, m_creature->GetMaxHealth() - health);
            }
    }
};

CreatureAI* GetAI_mob_xt002_heart(Creature* pCreature)
{
    return new mob_xt002_heartAI(pCreature);
}

/*-------------------------------------------------------
 *
 *        XS-013 SCRAPBOT
 *
 *///----------------------------------------------------
struct mob_scrapbotAI : public ScriptedAI
{
    mob_scrapbotAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = m_creature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    void Reset()
    {
        m_creature->SetReactState(REACT_PASSIVE);

        if (Creature* pXT002 = m_creature->GetCreature(*m_creature, m_pInstance->GetData64(TYPE_XT002)))
            m_creature->GetMotionMaster()->MoveChase(pXT002);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Creature* pXT002 = m_creature->GetCreature(*m_creature, m_pInstance->GetData64(TYPE_XT002)))
        {
            if (m_creature->GetDistance2d(pXT002) <= 0.5)
            {
                // TODO Send raid message

                // Increase health with 1 percent
                pXT002->ModifyHealth(pXT002->GetMaxHealth() * 0.01);

                // Despawns the scrapbot
                m_creature->ForcedDespawn();
            }
        }
    }
};

CreatureAI* GetAI_mob_scrapbot(Creature* pCreature)
{
    return new mob_scrapbotAI(pCreature);
}

/*-------------------------------------------------------
 *
 *        XM-024 PUMMELLER
 *
 *///----------------------------------------------------
struct mob_pummellerAI : public ScriptedAI
{
    mob_pummellerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;
    int32 uiArcingSmashTimer;
    int32 uiTrampleTimer;
    int32 uiUppercutTimer;

    void Reset()
    {
        uiArcingSmashTimer = TIMER_ARCING_SMASH;
        uiTrampleTimer = TIMER_TRAMPLE;
        uiUppercutTimer = TIMER_UPPERCUT;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        
        if (m_creature->IsWithinMeleeRange(m_creature->getVictim()))
        {
            if (uiArcingSmashTimer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_ARCING_SMASH);
                uiArcingSmashTimer = TIMER_ARCING_SMASH;
            } else uiArcingSmashTimer -= diff;

            if (uiTrampleTimer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_TRAMPLE);
                uiTrampleTimer = TIMER_TRAMPLE;
            } else uiTrampleTimer -= diff;

            if (uiUppercutTimer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_UPPERCUT);
                uiUppercutTimer = TIMER_UPPERCUT;
            } else uiUppercutTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_pummeller(Creature* pCreature)
{
    return new mob_pummellerAI(pCreature);
}

/*-------------------------------------------------------
 *
 *        XE-321 BOOMBOT
 *
 *///----------------------------------------------------
struct mob_boombotAI : public ScriptedAI
{
    mob_boombotAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    void Reset()
    {
        m_creature->SetReactState(REACT_PASSIVE);

        if (Creature* pXT002 = m_creature->GetCreature(*m_creature, m_pInstance->GetData64(TYPE_XT002)))
            m_creature->GetMotionMaster()->MoveChase(pXT002);
    }

    void JustDied(Unit *killer)
    {
        DoCast(SPELL_BOOM);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Creature* pXT002 = m_creature->GetCreature(*m_creature, m_pInstance->GetData64(TYPE_XT002)))
        {
            if (m_creature->GetDistance2d(pXT002) <= 0.5)
            {
                //Explosion
                DoCast(m_creature, SPELL_BOOM);

                //Despawns the boombot
                m_creature->ForcedDespawn();
            }
        }
    }
};

CreatureAI* GetAI_mob_boombot(Creature* pCreature)
{
    return new mob_boombotAI(pCreature);
}

/*-------------------------------------------------------
 *
 *        VOID ZONE
 *
 *///----------------------------------------------------
struct mob_void_zoneAI : public ScriptedAI
{
    mob_void_zoneAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
    }

    ScriptedInstance* m_pInstance;
    uint32 uiVoidZoneTimer;

    void Reset()
    {
        uiVoidZoneTimer = TIMER_VOID_ZONE;
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiVoidZoneTimer <= diff)
        {
            //voidZone();
            uiVoidZoneTimer = TIMER_VOID_ZONE;
        } else uiVoidZoneTimer -= diff;
    }

    // TODO: put in comment and kept for reference. The spell should be fixed properly in spell system, if necessary.
    //void voidZone()
    //{
    //    Map* pMap = me->GetMap();
    //    if (pMap && pMap->IsDungeon())
    //    {
    //        Map::PlayerList const &PlayerList = pMap->GetPlayers();
    //        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
    //        {
    //            // If a player is within the range of the spell
    //            if (i->getSource() && i->getSource()->GetDistance2d(m_creature) <= 16)
    //            {
    //                // Deal damage to the victim
    //                int32 damage = RAID_MODE(VOID_ZONE_DMG_10, VOID_ZONE_DMG_25);
    //                m_creature->DealDamage(i->getSource(), damage, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_SHADOW);
    //            }
    //        }
    //    }
    //}
};

CreatureAI* GetAI_mob_void_zone(Creature* pCreature)
{
    return new mob_void_zoneAI(pCreature);
}

/*-------------------------------------------------------
 *
 *        LIFE SPARK
 *
 *///----------------------------------------------------
struct mob_life_sparkAI : public ScriptedAI
{
    mob_life_sparkAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;
    uint32 uiShockTimer;

    void Reset()
    {
        DoCast(m_creature, RAID_MODE(SPELL_STATIC_CHARGED_10, SPELL_STATIC_CHARGED_25));
        uiShockTimer = 0; // first one is immediate.
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiShockTimer <= diff)
        {
            if (m_creature->IsWithinMeleeRange(m_creature->getVictim()))
            {
                DoCast(m_creature->getVictim(), SPELL_SHOCK);
                uiShockTimer = TIMER_SHOCK;
            }
        }
        else uiShockTimer -= diff;
    }
};

CreatureAI* GetAI_mob_life_spark(Creature* pCreature)
{
    return new mob_life_sparkAI(pCreature);
}

void AddSC_boss_xt002()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_xt002";
    newscript->GetAI = &GetAI_boss_xt002;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_xt002_heart";
    newscript->GetAI = &GetAI_mob_xt002_heart;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_scrapbot";
    newscript->GetAI = &GetAI_mob_scrapbot;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_pummeller";
    newscript->GetAI = &GetAI_mob_pummeller;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_boombot";
    newscript->GetAI = &GetAI_mob_boombot;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_void_zone";
    newscript->GetAI = &GetAI_mob_void_zone;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_life_spark";
    newscript->GetAI = &GetAI_mob_life_spark;
    newscript->RegisterSelf();
}

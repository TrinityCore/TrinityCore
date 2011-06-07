/*
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

/*
    TODO:
        Add achievments
        Boombot explosion only hurt allies to the npc at the moment
        Boombot explosion visual
        Fix gravity bomb - tractor beam.    /? Need test
        Fix void zone spell                 /? Need test
        If the boss is to close to a scrap pile -> no summon 
        make the life sparks visible...     /? Need test
        Phase transition kneel/stand up animation
        Tympanic Tantrum needs its range reduced
        Proper scripts for adds (scrapbots should enter vehicle)
        Codestyle
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ulduar.h"

enum Spells
{
    SPELL_TYMPANIC_TANTRUM                      = 62776,
    SPELL_SEARING_LIGHT_10                      = 63018,
    SPELL_SEARING_LIGHT_25                      = 65121,

    SPELL_SUMMON_LIFE_SPARK                     = 64210,
    SPELL_SUMMON_VOID_ZONE                      = 64203,

    SPELL_GRAVITY_BOMB_10                       = 63024,
    SPELL_GRAVITY_BOMB_25                       = 64234,
    SPELL_GRAVITY_BOMB_AURA_10                  = 63025,
    SPELL_GRAVITY_BOMB_AURA_25                  = 63233,

    SPELL_HEARTBREAK_10                         = 65737,
    SPELL_HEARTBREAK_25                         = 64193,

    // Cast by 33337 at Heartbreak:
    SPELL_RECHARGE_PUMMELER                     = 62831,    // Summons 33344
    SPELL_RECHARGE_SCRAPBOT                     = 62828,    // Summons 33343
    SPELL_RECHARGE_BOOMBOT                      = 62835,    // Summons 33346

    // Cast by 33329 on 33337 (visual?)
    SPELL_ENERGY_ORB                            = 62790,    // Triggers 62826 - needs spellscript for periodic tick to cast one of the random spells above

    SPELL_HEART_HEAL_TO_FULL                    = 17683,
    SPELL_HEART_OVERLOAD                        = 62789,

    SPELL_HEART_LIGHTNING_TETHER                = 64799,    // Cast on self?
    SPELL_HEART_RIDE_VEHICLE                    = 63313,
    SPELL_ENRAGE                                = 26662,
    SPELL_STAND                                 = 37752,
    SPELL_SUBMERGE                              = 37751,

    //------------------VOID ZONE--------------------
    SPELL_VOID_ZONE_10                          = 64203,
    SPELL_VOID_ZONE_25                          = 64235,

    // Life Spark
    SPELL_STATIC_CHARGED_10                     = 64227,
    SPELL_STATIC_CHARGED_25                     = 64236,
    SPELL_SHOCK                                 = 64230,

    //----------------XT-002 HEART-------------------
    SPELL_EXPOSED_HEART                         = 63849,
    // Channeled

    //---------------XM-024 PUMMELLER----------------
    SPELL_ARCING_SMASH                          = 8374,
    SPELL_TRAMPLE                               = 5568,
    SPELL_UPPERCUT                              = 10966,

    // Scrabot:
    SPELL_SCRAPBOT_RIDE_VEHICLE                 = 47020,
    SPELL_SUICIDE                               = 7,

    //------------------BOOMBOT-----------------------
    SPELL_BOOM                                  = 62834,
};

enum Events
{
    EVENT_TYMPANIC_TANTRUM = 1,
    EVENT_SEARING_LIGHT,
    EVENT_GRAVITY_BOMB,
    EVENT_HEART_PHASE,
    EVENT_ENERGY_ORB,
    EVENT_DISPOSE_HEART,
    EVENT_ENRAGE,
};

enum Timers
{
    TIMER_TYMPANIC_TANTRUM_MIN                  = 32000,
    TIMER_TYMPANIC_TANTRUM_MAX                  = 36000,
    TIMER_SEARING_LIGHT                         = 20000,
    TIMER_GRAVITY_BOMB                          = 20000,
    TIMER_HEART_PHASE                           = 30000,
    TIMER_ENERGY_ORB_MIN                        = 9000,
    TIMER_ENERGY_ORB_MAX                        = 10000,
    TIMER_ENRAGE                                = 600000,

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

enum
{
    ACHIEV_TIMED_START_EVENT                      = 21027,
};

const Position SpawnPos[4] = 
{
    {888.69f, 25.63f, 409.81f, 1.58f},
    {896.74f, 68.08f, 412.24f, 4.03f},
    {895.88f, -93.45f, 441.95f, 2.21f},
    {787.33f, -92.33f, 412.01f, 0.83f}
};

#define HEART_VEHICLE_SEAT 0

/*-------------------------------------------------------
 *
 *        XT-002 DECONSTRUCTOR
 *
 *///----------------------------------------------------
class boss_xt002 : public CreatureScript
{
    public:
        boss_xt002() : CreatureScript("boss_xt002") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
        return GetUlduarAI<boss_xt002_AI>(pCreature);
        }

        struct boss_xt002_AI : public BossAI
        {
            boss_xt002_AI(Creature *pCreature) : BossAI(pCreature, BOSS_XT002)
            {
            }

            uint8 _phase;
            uint8 _heartExposed;

            uint32 transferHealth;
            bool enterHardMode;
            bool hardMode;

            void Reset()
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);

                hardMode = false;
                enterHardMode = false;

                _phase = 1;
                _heartExposed = 0;

                if (instance)
                    instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
                _EnterCombat();

                events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE);
                events.ScheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB);
                events.ScheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT);
                //Tantrum is casted a bit slower the first time.
                events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX) * 2);

                if (instance)
                    instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
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
                            me->SetFullHealth();

                            // Get his heartbreak buff
                            me->CastSpell(me, RAID_MODE(SPELL_HEARTBREAK_10, SPELL_HEARTBREAK_25), true);

                            me->AddLootMode(LOOT_MODE_HARD_MODE_1);
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

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void JustDied(Unit * /*victim*/)
            {
                DoScriptText(SAY_DEATH, me);
                _JustDied();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                if (!hardMode && _phase == 1 && !HealthAbovePct(100 - 25 * (_heartExposed+1)))
                    ExposeHeart();
            }

            void UpdateAI(const uint32 diff)
            {
                if (_phase == 1 && !UpdateVictim())
                    return;

                events.Update(diff);

                if (enterHardMode)
                {
                    SetPhaseOne();
                    enterHardMode = false;
                }

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                // Handles spell casting. These spells only occur during phase 1 and hard mode
                if (_phase == 1)
                    {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_SEARING_LIGHT:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, RAID_MODE(SPELL_SEARING_LIGHT_10, SPELL_SEARING_LIGHT_25));

                                events.RepeatEvent(TIMER_SEARING_LIGHT);
                                break;
                            case EVENT_GRAVITY_BOMB:
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(pTarget, RAID_MODE(SPELL_GRAVITY_BOMB_10, SPELL_GRAVITY_BOMB_25));

                                events.RepeatEvent(TIMER_GRAVITY_BOMB);
                                break;
                            case EVENT_TYMPANIC_TANTRUM:
                                DoScriptText(SAY_TYMPANIC_TANTRUM, me);
                                DoCast(SPELL_TYMPANIC_TANTRUM);
                                events.RepeatEvent(urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX));
                                break;
                            case EVENT_ENRAGE:
                                DoScriptText(SAY_BERSERK, me);
                                DoCast(me, SPELL_ENRAGE);
                                break;
                        }
                    }
                    DoMeleeAttackIfReady();
                }
                else if (_phase == 2)
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                            case EVENT_DISPOSE_HEART:
                                SetPhaseOne();
                                break;
                    }
                }
            }

            void ExposeHeart()
            {
                //Make untargetable
                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_6 | UNIT_FLAG_PET_IN_COMBAT | UNIT_FLAG_UNK_15 | UNIT_FLAG_IN_COMBAT | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);

                //DoCast(SPELL_SUBMERGE); -- Need proper kneel dummy
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitState(UNIT_STAT_STUNNED);

                Unit* heart = me->GetVehicleKit() ? me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT) : NULL;
                if (heart)
                {
                    heart->CastSpell(heart, SPELL_HEART_OVERLOAD, false);
                    heart->CastSpell(me, SPELL_HEART_LIGHTNING_TETHER, false);
                    heart->CastSpell(heart, SPELL_HEART_HEAL_TO_FULL, true);
                    heart->CastSpell(heart, SPELL_EXPOSED_HEART, false);    // Channeled

                    //heart->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    heart->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT | UNIT_FLAG_UNK_15 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_29);
                    heart->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            
                }

                // Start "end of phase 2 timer"
                events.ScheduleEvent(EVENT_DISPOSE_HEART, TIMER_HEART_PHASE);

                // Phase 2 has officially started
                _phase = 2;
                _heartExposed++;

                DoScriptText(SAY_HEART_OPENED, me);
            }

            void SetPhaseOne()
            {
                DoScriptText(SAY_HEART_CLOSED, me);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);

                //DoCast(SPELL_STAND);
                me->SetReactState(REACT_AGGRESSIVE);
                //me->SetStandState(UNIT_STAND_STATE_STAND);
                me->ClearUnitState(UNIT_STAT_STUNNED);

                _phase = 1;

                events.RescheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT / 2);
                events.RescheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB);
                events.RescheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX));

                Unit* heart = me->GetVehicleKit() ? me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT) : NULL;
                if (!heart)
                    return;

                heart->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                heart->RemoveAurasDueToSpell(SPELL_EXPOSED_HEART);

                if (!hardMode)
                {
                    if (!transferHealth)
                        transferHealth = (heart->GetMaxHealth() - heart->GetHealth());

                    me->ModifyHealth(-((int32)transferHealth));
                }
            }
        };
};


/*-------------------------------------------------------
 *
 *        XT-002 HEART
 *
 *///----------------------------------------------------
class mob_xt002_heart : public CreatureScript
{
public:
    mob_xt002_heart() : CreatureScript("mob_xt002_heart") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_xt002_heartAI(pCreature);
    }

    struct mob_xt002_heartAI : public ScriptedAI
    {
        mob_xt002_heartAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* m_pInstance;
        uint32 _damageTaken;

        void DamageTaken(Unit * /*pDone*/, uint32 &damage)
        {
            Creature* XT002 = me->GetCreature(*me, m_pInstance->GetData64(BOSS_XT002));
            if (!XT002 || !XT002->AI())
                return;

            if (damage >= me->GetHealth())
            {
                XT002->AI()->SetData(DATA_TRANSFERED_HEALTH, me->GetMaxHealth());
                XT002->AI()->DoAction(ACTION_ENTER_HARD_MODE);
                damage = 0;                
            }
        }
    };

};

/*-------------------------------------------------------
 *
 *        XS-013 SCRAPBOT
 *
 *///----------------------------------------------------
class mob_scrapbot : public CreatureScript
{
public:
    mob_scrapbot() : CreatureScript("mob_scrapbot") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_scrapbotAI(pCreature);
    }

    struct mob_scrapbotAI : public ScriptedAI
    {
        mob_scrapbotAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = me->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            if (Creature* pXT002 = me->GetCreature(*me, m_pInstance->GetData64(BOSS_XT002)))
                me->GetMotionMaster()->MoveFollow(pXT002, 0.0f, 0.0f);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (Creature* pXT002 = me->GetCreature(*me, m_pInstance->GetData64(BOSS_XT002)))
            {
                if (me->GetDistance2d(pXT002) <= 0.5)
                {
                    // TODO Send raid message

                    // Increase health with 1 percent
                    pXT002->ModifyHealth(int32(pXT002->CountPctFromMaxHealth(1)));

                    // Despawns the scrapbot
                    me->DespawnOrUnsummon();
                }
            }
        }
    };

};

/*-------------------------------------------------------
 *
 *        XM-024 PUMMELLER
 *
 *///----------------------------------------------------
class mob_pummeller : public CreatureScript
{
public:
    mob_pummeller() : CreatureScript("mob_pummeller") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_pummellerAI(pCreature);
    }

    struct mob_pummellerAI : public ScriptedAI
    {
        mob_pummellerAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;
        uint32 uiArcingSmashTimer;
        uint32 uiTrampleTimer;
        uint32 uiUppercutTimer;

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

            if (me->IsWithinMeleeRange(me->getVictim()))
            {
                if (uiArcingSmashTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_ARCING_SMASH);
                    uiArcingSmashTimer = TIMER_ARCING_SMASH;
                } else uiArcingSmashTimer -= diff;

                if (uiTrampleTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_TRAMPLE);
                    uiTrampleTimer = TIMER_TRAMPLE;
                } else uiTrampleTimer -= diff;

                if (uiUppercutTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_UPPERCUT);
                    uiUppercutTimer = TIMER_UPPERCUT;
                } else uiUppercutTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

/*-------------------------------------------------------
 *
 *        XE-321 BOOMBOT
 *
 *///----------------------------------------------------
class mob_boombot : public CreatureScript
{
public:
    mob_boombot() : CreatureScript("mob_boombot") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_boombotAI(pCreature);
    }

    struct mob_boombotAI : public ScriptedAI
    {
        mob_boombotAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            if (Creature* pXT002 = me->GetCreature(*me, m_pInstance->GetData64(BOSS_XT002)))
                me->GetMotionMaster()->MoveFollow(pXT002, 0.0f, 0.0f);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (Creature* pXT002 = me->GetCreature(*me, m_pInstance->GetData64(BOSS_XT002)))
            {
                if (me->GetDistance2d(pXT002) <= 0.5)
                {
                    //Explosion
                    DoCast(me, SPELL_BOOM);

                    //Despawns the boombot
                    me->DespawnOrUnsummon();
                }
            }
        }
    };

};


/*-------------------------------------------------------
 *
 *        LIFE SPARK
 *
 *///----------------------------------------------------
class mob_life_spark : public CreatureScript
{
public:
    mob_life_spark() : CreatureScript("mob_life_spark") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_life_sparkAI(pCreature);
    }

    struct mob_life_sparkAI : public ScriptedAI
    {
        mob_life_sparkAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;
        uint32 uiShockTimer;

        void Reset()
        {
            DoCast(me, RAID_MODE(SPELL_STATIC_CHARGED_10, SPELL_STATIC_CHARGED_25));
            uiShockTimer = 0; // first one is immediate.
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiShockTimer <= diff)
            {
                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    DoCast(me->getVictim(), SPELL_SHOCK);
                    uiShockTimer = TIMER_SHOCK;
                }
            }
            else uiShockTimer -= diff;
        }
    };

};

class spell_xt002_searing_light_spawn_life_spark : public SpellScriptLoader
{
    public:
        spell_xt002_searing_light_spawn_life_spark() : SpellScriptLoader("spell_xt002_searing_light_spawn_life_spark") { }

        class spell_xt002_searing_light_spawn_life_spark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_searing_light_spawn_life_spark_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_SUMMON_LIFE_SPARK))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Player* plr = GetOwner()->ToPlayer())
                    if (Unit* xt002 = GetCaster())
                        if (xt002->HasAura(aurEff->GetAmount()))   // Heartbreak aura indicating hard mode
                            plr->CastSpell(plr, SPELL_SUMMON_LIFE_SPARK, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_searing_light_spawn_life_spark_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_xt002_searing_light_spawn_life_spark_AuraScript();
        }
};

class spell_xt002_gravity_bomb_spawn_void_zone : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_spawn_void_zone() : SpellScriptLoader("spell_xt002_gravity_bomb_spawn_void_zone") { }

        class spell_xt002_gravity_bomb_spawn_void_zone_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_gravity_bomb_spawn_void_zone_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_SUMMON_VOID_ZONE))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Player* plr = GetOwner()->ToPlayer())
                    if (Unit* xt002 = GetCaster())
                        if (xt002->HasAura(aurEff->GetAmount()))   // Heartbreak aura indicating hard mode
                            plr->CastSpell(plr, SPELL_SUMMON_VOID_ZONE, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_gravity_bomb_spawn_void_zone_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_xt002_gravity_bomb_spawn_void_zone_AuraScript();
        }
};

class spell_xt002_heart_overload_periodic : public SpellScriptLoader
{
    public:
        spell_xt002_heart_overload_periodic() : SpellScriptLoader("spell_xt002_heart_overload_periodic") { }

        class spell_xt002_heart_overload_periodic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_heart_overload_periodic_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ENERGY_ORB))
                    return false;

                if (!sSpellStore.LookupEntry(SPELL_RECHARGE_BOOMBOT))
                    return false;

                if (!sSpellStore.LookupEntry(SPELL_RECHARGE_PUMMELER))
                    return false;

                if (!sSpellStore.LookupEntry(SPELL_RECHARGE_SCRAPBOT))
                    return false;

                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    {
                        if (Unit* toyPile = ObjectAccessor::GetUnit(*caster, instance->GetData64(DATA_TOY_PILE_0 + urand(0, 3))))
                        {
                            caster->CastSpell(toyPile, SPELL_ENERGY_ORB, true);

                            // This should probably be incorporated in a dummy effect handler, but I've had trouble getting the correct target
                            // Weighed randomization (approximation)
                            uint32 const spells[] = { SPELL_RECHARGE_SCRAPBOT, SPELL_RECHARGE_SCRAPBOT, SPELL_RECHARGE_SCRAPBOT,
                                SPELL_RECHARGE_PUMMELER, SPELL_RECHARGE_BOOMBOT };

                            for (uint8 i = 0; i < 5; ++i)
                            {
                                uint8 a = urand(0, 4);
                                uint32 spellId = spells[a];
                                toyPile->CastSpell(toyPile, spellId, true);
                            }
                        }
                    }

                    DoScriptText(SAY_SUMMON, caster->GetVehicleBase());
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_xt002_heart_overload_periodic_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_heart_overload_periodic_SpellScript();
        }
};

void AddSC_boss_xt002()
{
    new mob_xt002_heart();
    new mob_scrapbot();
    new mob_pummeller();
    new mob_boombot();

    new mob_life_spark();
    new boss_xt002();

    new spell_xt002_searing_light_spawn_life_spark();
    new spell_xt002_gravity_bomb_spawn_void_zone();
    new spell_xt002_heart_overload_periodic();
}

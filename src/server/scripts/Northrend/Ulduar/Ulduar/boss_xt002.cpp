/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
        Achievments:
            Nerf Scrapbots - in Scrapbot script

        make the life sparks visible...
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_TYMPANIC_TANTRUM                      = 62776,
    SPELL_SEARING_LIGHT_10                      = 63018,
    SPELL_SEARING_LIGHT_25                      = 65121,

    SPELL_GRAVITY_BOMB_10                       = 63024,
    SPELL_GRAVITY_BOMB_25                       = 64234,

    SPELL_HEARTBREAK_10                         = 65737,
    SPELL_HEARTBREAK_25                         = 64193,

    SPELL_HEART_EXPOSED                         = 62789,

    SPELL_ENRAGE                                = 26662,

    //------------------VOID ZONE--------------------
    SPELL_VOID_ZONE_10                          = 64203,
    SPELL_VOID_ZONE_25                          = 64235,
    SPELL_CONSUMPTION_10                        = 64208,
    SPELL_CONSUMPTION_25                        = 64206,

    // Life Spark
    SPELL_STATIC_CHARGED_10                     = 64227,
    SPELL_STATIC_CHARGED_25                     = 64236,
    SPELL_SHOCK                                 = 64230,

    //----------------XT-002 HEART-------------------
    SPELL_EXPOSED_HEART                         = 63849,
    SPELL_HEART_RIDE_XT002                      = 63852,

    //---------------XM-024 PUMMELLER----------------
    SPELL_ARCING_SMASH                          = 8374,
    SPELL_TRAMPLE                               = 5568,
    SPELL_UPPERCUT                              = 10966,

    //------------------BOOMBOT-----------------------
    SPELL_BOOM                                  = 62834,
    SPELL_AURA_BOOMBOT                          = 65032,

    //-----------------SCRAPBOT-----------------------
    SPELL_HEAL_XT002                            = 62832,

    // Achievement-related spells
    SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS     = 65037
};

enum Creatures
{
    NPC_VOID_ZONE                               = 34001,
    NPC_LIFE_SPARK                              = 34004,
    NPC_XT002_HEART                             = 33329,
    NPC_XS013_SCRAPBOT                          = 33343,
    NPC_XM024_PUMMELLER                         = 33344,
    NPC_XE321_BOOMBOT                           = 33346
};

enum Actions
{
    ACTION_ENTER_HARD_MODE,
    ACTION_XT002_REACHED
};

enum Data
{
    DATA_TRANSFERED_HEALTH,
    DATA_HARD_MODE,
    DATA_HEALTH_RECOVERED,
    DATA_GRAVITY_BOMB_CASUALTY
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
    SAY_SUMMON                                  = -1603308
};

enum
{
    ACHIEV_TIMED_START_EVENT                    = 21027
};

#define EMOTE_TYMPANIC "XT-002 Deconstructor begins to cause the earth to quake."
#define EMOTE_HEART    "XT-002 Deconstructor's heart is exposed and leaking energy."
#define EMOTE_REPAIR   "XT-002 Deconstructor consumes a scrap bot to repair himself!"

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

class boss_xt002 : public CreatureScript
{
    public:
        boss_xt002() : CreatureScript("boss_xt002") { }

        struct boss_xt002_AI : public BossAI
        {
            boss_xt002_AI(Creature* creature) : BossAI(creature, BOSS_XT002)
            {
            }

            void Reset()
            {
                _Reset();
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
                me->ResetLootMode();

                _searingLightTimer = 10*IN_MILLISECONDS;
                _gravityBombTimer = 20*IN_MILLISECONDS;
                _heartPhaseTimer = 30*IN_MILLISECONDS;
                _spawnAddTimer = 12*IN_MILLISECONDS;
                _enrageTimer = 10*MINUTE*IN_MILLISECONDS;
                _tympanicTantrumTimer = RAID_MODE<uint32>(35000, 50000); // DBM

                _enraged = false;
                _hardMode = false;
                _enterHardMode = false;
                _healthRecovered = false;
                _gravityBombCasualty = false;

                _phase = 1;
                _heartExposed = 0;

                if (instance)
                    instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
                _EnterCombat();

                if (instance)
                    instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            void JustSummoned(Creature* summoned)
            {
                summons.Summon(summoned);
                DoZoneInCombat(summoned);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_ENTER_HARD_MODE:
                        if (!_hardMode)
                        {
                            _hardMode = true;
                            me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                            // Enter hard mode
                            _enterHardMode = true;
                            // set max health
                            me->SetFullHealth();
                            // Get his heartbreak buff
                            me->CastSpell(me, RAID_MODE<uint32>(SPELL_HEARTBREAK_10, SPELL_HEARTBREAK_25), true);
                        }
                        break;
                    case ACTION_XT002_REACHED:
                        _healthRecovered = true;
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_HARD_MODE:
                        return _hardMode ? 1 : 0;
                    case DATA_HEALTH_RECOVERED:
                        return _healthRecovered ? 1 : 0;
                    case DATA_GRAVITY_BOMB_CASUALTY:
                        return _gravityBombCasualty ? 1 : 0;
                }

                return 0;
            }

            void SetData(uint32 id, uint32 data)
            {
                switch (id)
                {
                    case DATA_TRANSFERED_HEALTH:
                        _transferHealth = data;
                        break;
                    case DATA_GRAVITY_BOMB_CASUALTY:
                        _gravityBombCasualty = (data > 0) ? true : false;
                        break;
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
            }

            void JustDied(Unit* /*victim*/)
            {
                me->RemoveAllAuras();
                DoScriptText(SAY_DEATH, me);
                _JustDied();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _DoAggroPulse(diff);

                if (_enterHardMode)
                {
                    SetPhaseOne();
                    _enterHardMode = false;
                }

                // Handles spell casting. These spells only occur during phase 1 or hard mode
                if (_phase == 1 || _hardMode)
                {
                    if (_searingLightTimer <= diff)
                    {
                        if (!me->HasAura(SPELL_TYMPANIC_TANTRUM))
                            DoCast(me, RAID_MODE<uint32>(SPELL_SEARING_LIGHT_10, SPELL_SEARING_LIGHT_25), true);
                        _searingLightTimer = 20*IN_MILLISECONDS;
                    }
                    else
                        _searingLightTimer -= diff;

                    if (_gravityBombTimer <= diff)
                    {
                        if (!me->HasAura(SPELL_TYMPANIC_TANTRUM))
                            DoCast(me, RAID_MODE<uint32>(SPELL_GRAVITY_BOMB_10, SPELL_GRAVITY_BOMB_25), true);
                        _gravityBombTimer = 20*IN_MILLISECONDS;
                    }
                    else
                        _gravityBombTimer -= diff;

                    if (_tympanicTantrumTimer <= diff)
                    {
                        DoScriptText(SAY_TYMPANIC_TANTRUM, me);
                        me->MonsterTextEmote(EMOTE_TYMPANIC, 0, true);
                        DoCast(SPELL_TYMPANIC_TANTRUM);
                        _tympanicTantrumTimer = 1*MINUTE*IN_MILLISECONDS;
                    }
                    else
                        _tympanicTantrumTimer -= diff;
                }

                if (!_hardMode)
                {
                    if (_phase == 1)
                    {
                        if (HealthBelowPct(100 - (_heartExposed + 1) * 25))
                            exposeHeart();

                        DoMeleeAttackIfReady();
                    }
                    else
                    {
                        // Start summoning adds
                        if (_spawnAddTimer <= diff)
                        {
                            DoScriptText(SAY_SUMMON, me);

                            // Spawn Pummeller
                            switch (rand() % 4)
                            {
                                case 0: me->SummonCreature(NPC_XM024_PUMMELLER, LR_X, LR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                case 1: me->SummonCreature(NPC_XM024_PUMMELLER, LL_X, LL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                case 2: me->SummonCreature(NPC_XM024_PUMMELLER, UR_X, UR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                case 3: me->SummonCreature(NPC_XM024_PUMMELLER, UL_X, UL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                            }

                            // Spawn 5 Scrapbots
                            for (int8 n = 0; n < 5; ++n)
                            {
                                // Some randomes are added so they wont spawn in a pile
                                switch (rand() % 4)
                                {
                                    case 0: me->SummonCreature(NPC_XS013_SCRAPBOT, float(irand(LR_X - 3, LR_X + 3)), float(irand(LR_Y - 3, LR_Y + 3)), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                    case 1: me->SummonCreature(NPC_XS013_SCRAPBOT, float(irand(LL_X - 3, LL_X + 3)), float(irand(LL_Y - 3, LL_Y + 3)), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                    case 2: me->SummonCreature(NPC_XS013_SCRAPBOT, float(irand(UR_X - 3, UR_X + 3)), float(irand(UR_Y - 3, UR_Y + 3)), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                    case 3: me->SummonCreature(NPC_XS013_SCRAPBOT, float(irand(UL_X - 3, UL_X + 3)), float(irand(UL_Y - 3, UL_Y + 3)), SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                }
                            }

                            // Spawn 3 Bombs
                            for (int8 n = 0; n < 3; ++n)
                            {
                                switch (rand() % 4)
                                {
                                    case 0: me->SummonCreature(NPC_XE321_BOOMBOT, LR_X, LR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                    case 1: me->SummonCreature(NPC_XE321_BOOMBOT, LL_X, LL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                    case 2: me->SummonCreature(NPC_XE321_BOOMBOT, UR_X, UR_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                    case 3: me->SummonCreature(NPC_XE321_BOOMBOT, UL_X, UL_Y, SPAWN_Z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000); break;
                                }
                            }

                            _spawnAddTimer = 12*IN_MILLISECONDS;
                        }
                        else
                            _spawnAddTimer -= diff;

                        // Is the phase over?
                        if (_heartPhaseTimer <= diff)
                        {
                            DoScriptText(SAY_HEART_CLOSED, me);
                            SetPhaseOne();
                        }
                        else
                            _heartPhaseTimer -= diff;
                    }
                }
                else
                    DoMeleeAttackIfReady();

                if (!_enraged)
                {
                    if (_enrageTimer <= diff)
                    {
                        DoScriptText(SAY_BERSERK, me);
                        DoCast(me, SPELL_ENRAGE, true);
                        _enraged = true;
                    }
                    else
                        _enrageTimer -= diff;
                }
            }

            // NOT BLIZZLIKE ... Heart is Spawned the whole Encounter ... VX - 002 is a vehicle
            void exposeHeart()
            {
                me->GetMotionMaster()->MoveIdle();
                me->SetStandState(UNIT_STAND_STATE_SUBMERGED);

                // Remove if still active?
                me->RemoveAurasDueToSpell(SPELL_TYMPANIC_TANTRUM);

                // Make untargetable
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);

                // Summon the heart npc
                if (Creature* heart = me->SummonCreature(NPC_XT002_HEART, *me, TEMPSUMMON_TIMED_DESPAWN, 30*IN_MILLISECONDS))
                {
                    heart->EnterVehicle(me, 1);
                    heart->ClearUnitState(UNIT_STATE_ONVEHICLE); // Hack
                    heart->SetInCombatWithZone();
                    heart->CastSpell(heart, SPELL_EXPOSED_HEART, true);
                }

                // Start "end of phase 2 timer"
                _heartPhaseTimer = 30*IN_MILLISECONDS;

                // Phase 2 has offically started
                _phase = 2;
                ++_heartExposed;

                // Reset the add spawning timer
                _spawnAddTimer = 12*IN_MILLISECONDS;

                DoScriptText(SAY_HEART_OPENED, me);
                me->MonsterTextEmote(EMOTE_HEART, 0, true);
            }

            void SetPhaseOne()
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->GetMotionMaster()->MoveChase(me->getVictim());

                _searingLightTimer = 15*IN_MILLISECONDS;
                _gravityBombTimer = 25*IN_MILLISECONDS;
                _tympanicTantrumTimer = 60*IN_MILLISECONDS;
                _spawnAddTimer = 12*IN_MILLISECONDS;

                if (!_hardMode)
                {
                    me->ModifyHealth(-((int32)_transferHealth));
                    me->LowerPlayerDamageReq(_transferHealth);
                }

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);
                _phase = 1;
            }

        private:
            uint32 _searingLightTimer;
            uint32 _gravityBombTimer;
            uint32 _tympanicTantrumTimer;
            uint32 _heartPhaseTimer;
            uint32 _spawnAddTimer;
            uint32 _enrageTimer;

            uint8 _phase;
            uint8 _heartExposed;
            uint32 _transferHealth;

            bool _enraged;
            bool _enterHardMode;
            bool _hardMode;
            bool _healthRecovered;
            bool _gravityBombCasualty;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_xt002_AI(creature);
        }
};

class mob_xt002_heart : public CreatureScript
{
    public:
        mob_xt002_heart() : CreatureScript("mob_xt002_heart") { }

        struct mob_xt002_heartAI : public Scripted_NoMovementAI
        {
            mob_xt002_heartAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                _instance = creature->GetInstanceScript();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void JustDied(Unit* /*victim*/)
            {
                if (_instance)
                    if (Creature* XT002 = me->GetCreature(*me, _instance ? _instance->GetData64(BOSS_XT002) : 0))
                        if (XT002->AI())
                            XT002->AI()->DoAction(ACTION_ENTER_HARD_MODE);

                //removes the aura
                me->RemoveAurasDueToSpell(SPELL_EXPOSED_HEART);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (Creature* XT002 = me->GetCreature(*me, _instance ? _instance->GetData64(BOSS_XT002) : 0))
                    if (XT002->AI())
                    {
                        uint32 health = me->GetHealth();
                        if (health <= damage)
                            health = 0;
                        else
                            health -= damage;
                        XT002->AI()->SetData(DATA_TRANSFERED_HEALTH, me->GetMaxHealth() - health);
                    }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                // TODO: find better solution
                if (!me->HasAura(SPELL_EXPOSED_HEART))
                    me->AddAura(SPELL_EXPOSED_HEART, me);
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_xt002_heartAI(creature);
        }
};

class mob_scrapbot : public CreatureScript
{
    public:
        mob_scrapbot() : CreatureScript("mob_scrapbot") { }

        struct mob_scrapbotAI : public ScriptedAI
        {
            mob_scrapbotAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = me->GetInstanceScript();
                _nearCheckTimer = 5*IN_MILLISECONDS;
                _casted = false;
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);

                if (Creature* XT002 = me->GetCreature(*me, _instance ? _instance->GetData64(BOSS_XT002) : 0))
                    me->GetMotionMaster()->MoveFollow(XT002, 1, float(2*M_PI*rand_norm()));
            }

            void UpdateAI(uint32 const diff)
            {
                if (_nearCheckTimer <= diff)
                {
                    if (Creature* XT002 = me->GetCreature(*me, _instance ? _instance->GetData64(BOSS_XT002) : 0))
                        if (!_casted && XT002->isAlive())
                            if (me->GetDistance2d(XT002) <= 2)
                            {
                                _casted = true;
                                XT002->MonsterTextEmote(EMOTE_REPAIR, 0, true);
                                XT002->CastSpell(XT002, SPELL_HEAL_XT002, true);
                                XT002->AI()->DoAction(ACTION_XT002_REACHED);
                                me->DespawnOrUnsummon(500);
                            }

                    _nearCheckTimer = 1*IN_MILLISECONDS;
                }
                else
                    _nearCheckTimer -= diff;
            }

        private:
            InstanceScript* _instance;
            uint32 _nearCheckTimer;
            bool _casted;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_scrapbotAI(creature);
        }
};

class mob_pummeller : public CreatureScript
{
    public:
        mob_pummeller() : CreatureScript("mob_pummeller") { }

        struct mob_pummellerAI : public ScriptedAI
        {
            mob_pummellerAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                _arcingSmashTimer = 7*IN_MILLISECONDS;
                _trampleTimer = 2*IN_MILLISECONDS;
                _uppercutTimer = 10*IN_MILLISECONDS;

                if (Player* target = me->SelectNearestPlayer(500.0f))
                    AttackStart(target);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->getVictim()))
                {
                    if (_arcingSmashTimer <= diff)
                    {
                        DoCastVictim(SPELL_ARCING_SMASH);
                        _arcingSmashTimer = 7*IN_MILLISECONDS;
                    }
                    else
                        _arcingSmashTimer -= diff;

                    if (_trampleTimer <= diff)
                    {
                        DoCastVictim(SPELL_TRAMPLE);
                        _trampleTimer = 2*IN_MILLISECONDS;
                    }
                    else
                        _trampleTimer -= diff;

                    if (_uppercutTimer <= diff)
                    {
                        DoCastVictim(SPELL_UPPERCUT);
                        _uppercutTimer = 10*IN_MILLISECONDS;
                    }
                    else
                        _uppercutTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _arcingSmashTimer;
            uint32 _trampleTimer;
            uint32 _uppercutTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_pummellerAI(creature);
        }
};

class BoomEvent : public BasicEvent
{
    public:
        BoomEvent(Creature* me) : _me(me)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            // This hack is here because we suspect our implementation of spell effect execution on targets
            // is done in the wrong order. We suspect that EFFECT_0 needs to be applied on all targets,
            // then EFFECT_1, etc - instead of applying each effect on target1, then target2, etc.
            // The above situation causes the visual for this spell to be bugged, so we remove the instakill
            // effect and implement a script hack for that.

            _me->CastSpell(_me, SPELL_BOOM, false);
            return true;
        }

    private:
        Creature* _me;
};

class mob_boombot : public CreatureScript
{
    public:
        mob_boombot() : CreatureScript("mob_boombot") { }

        struct mob_boombotAI : public ScriptedAI
        {
            mob_boombotAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _boomed = false;

                DoCast(SPELL_AURA_BOOMBOT); // For achievement

                // HACK/workaround:
                // these values aren't confirmed - lack of data - and the values in DB are incorrect
                // these values are needed for correct damage of Boom spell
                me->SetFloatValue(UNIT_FIELD_MINDAMAGE, 15000.0f);
                me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, 18000.0f);
                me->SetDisplayId(19139);
                me->SetSpeed(MOVE_RUN, 0.5f, true);

                // Todo: proper waypoints?
                if (Creature* xt002 = ObjectAccessor::GetCreature(*me, _instance ? _instance->GetData64(BOSS_XT002) : 0))
                    me->GetMotionMaster()->MoveFollow(xt002, 0.0f, 0.0f);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (damage >= (me->GetHealth() - me->GetMaxHealth() * 0.5f) && !_boomed)
                {
                    _boomed = true; // Prevent recursive calls

                    WorldPacket data(SMSG_SPELLINSTAKILLLOG, 8+8+4);
                    data << uint64(me->GetGUID());
                    data << uint64(me->GetGUID());
                    data << uint32(SPELL_BOOM);
                    me->SendMessageToSet(&data, false);

                    me->DealDamage(me, me->GetHealth(), NULL, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);

                    damage = 0;

                    // Visual only seems to work if the instant kill event is delayed or the spell itself is delayed
                    // Casting done from player and caster source has the same targetinfo flags,
                    // so that can't be the issue
                    // See BoomEvent class
                    // Schedule 1s delayed
                    me->m_Events.AddEvent(new BoomEvent(me), me->m_Events.CalculateTime(1*IN_MILLISECONDS));
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!UpdateVictim())
                    return;
            }

           private:
                InstanceScript* _instance;
                bool _boomed;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_boombotAI(creature);
        }
};

class mob_void_zone : public CreatureScript
{
    public:
        mob_void_zone() : CreatureScript("mob_void_zone") { }

        struct mob_void_zoneAI : public Scripted_NoMovementAI
        {
            mob_void_zoneAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                _consumptionTimer = 3*IN_MILLISECONDS;
            }

            void UpdateAI(const uint32 diff)
            {
                if (_consumptionTimer <= diff)
                {
                    int32 dmg = RAID_MODE<uint32>(5000, 7500);
                    me->CastCustomSpell(me, RAID_MODE<uint32>(SPELL_CONSUMPTION_10, SPELL_CONSUMPTION_25), &dmg, 0, 0, false);
                    _consumptionTimer = 3*IN_MILLISECONDS;
                }
                else
                    _consumptionTimer -= diff;
            }

        private:
            uint32 _consumptionTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_void_zoneAI(creature);
        }
};

class mob_life_spark : public CreatureScript
{
    public:
        mob_life_spark() : CreatureScript("mob_life_spark") { }

        struct mob_life_sparkAI : public ScriptedAI
        {
            mob_life_sparkAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                DoCast(me, RAID_MODE<uint32>(SPELL_STATIC_CHARGED_10, SPELL_STATIC_CHARGED_25));
                _shockTimer = 0; // first one is immediate.
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_shockTimer <= diff)
                {
                    if (me->IsWithinMeleeRange(me->getVictim()))
                    {
                        DoCastVictim(SPELL_SHOCK);
                        _shockTimer = 12*IN_MILLISECONDS;
                    }
                }
                else
                    _shockTimer -= diff;
            }

        private:
            uint32 _shockTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_life_sparkAI(creature);
        }
};

class BombTargetSelector : public std::unary_function<Unit *, bool>
{
    public:
        BombTargetSelector(Creature* me, const Unit* victim) : _me(me), _victim(victim) {}

        bool operator() (Unit* target)
        {
            if (target == _victim && _me->getThreatManager().getThreatList().size() > 1)
                return true;

            return false;
        }

        Creature* _me;
        Unit const* _victim;
};

class spell_xt002_searing_light : public SpellScriptLoader
{
    public:
        spell_xt002_searing_light() : SpellScriptLoader("spell_xt002_searing_light") { }

        class spell_xt002_searing_light_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_searing_light_targeting_SpellScript);

            bool Load()
            {
                _target = NULL;
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(BombTargetSelector(GetCaster()->ToCreature(), GetCaster()->getVictim()));

                if (unitList.empty())
                    return;

                _target = SelectRandomContainerElement(unitList);
                unitList.clear();
                unitList.push_back(_target);
            }

            void SetTarget(std::list<Unit*>& unitList)
            {
                unitList.clear();
                if (_target)
                    unitList.push_back(_target);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_xt002_searing_light_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_xt002_searing_light_targeting_SpellScript::SetTarget, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            }

            Unit* _target;
        };

        class spell_xt002_searing_light_spawn_life_spark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_searing_light_spawn_life_spark_AuraScript);

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetOwner()->ToPlayer())
                    if (Unit* xt002 = GetCaster())
                        if (xt002->HasAura(aurEff->GetAmount())) // Heartbreak aura indicating hard mode
                            xt002->SummonCreature(NPC_LIFE_SPARK, *player, TEMPSUMMON_TIMED_DESPAWN, 3*MINUTE*IN_MILLISECONDS);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_searing_light_spawn_life_spark_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_searing_light_targeting_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_xt002_searing_light_spawn_life_spark_AuraScript();
        }
};

class spell_xt002_gravity_bomb : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb() : SpellScriptLoader("spell_xt002_gravity_bomb") { }

        class spell_xt002_gravity_bomb_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_gravity_bomb_targeting_SpellScript);

            bool Load()
            {
                _target = NULL;
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(BombTargetSelector(GetCaster()->ToCreature(), GetCaster()->getVictim()));

                if (unitList.empty())
                    return;

                _target = SelectRandomContainerElement(unitList);
                unitList.clear();
                unitList.push_back(_target);
            }

            void SetTarget(std::list<Unit*>& unitList)
            {
                unitList.clear();
                if (_target)
                    unitList.push_back(_target);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_xt002_gravity_bomb_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_xt002_gravity_bomb_targeting_SpellScript::SetTarget, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
            }

            Unit* _target;
        };

        class spell_xt002_gravity_bomb_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_gravity_bomb_aura_AuraScript);

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetOwner()->ToPlayer())
                    if (Unit* xt002 = GetCaster())
                        if (xt002->HasAura(aurEff->GetAmount())) // Heartbreak aura indicating hard mode
                            xt002->SummonCreature(NPC_VOID_ZONE, *player, TEMPSUMMON_TIMED_DESPAWN, 3*MINUTE*IN_MILLISECONDS);
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* xt002 = GetCaster();
                if (!xt002)
                    return;

                Unit* owner = GetOwner()->ToUnit();
                if (!owner)
                    return;

                if (aurEff->GetAmount() >= int32(owner->GetHealth()))
                    if (xt002->GetAI())
                        xt002->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_xt002_gravity_bomb_aura_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_gravity_bomb_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_gravity_bomb_targeting_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_xt002_gravity_bomb_aura_AuraScript();
        }
};

class spell_xt002_gravity_bomb_damage : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_damage() : SpellScriptLoader("spell_xt002_gravity_bomb_damage") { }

        class spell_xt002_gravity_bomb_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_gravity_bomb_damage_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (GetHitDamage() >= int32(GetHitUnit()->GetHealth()))
                    if (caster->GetAI())
                        caster->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_xt002_gravity_bomb_damage_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_gravity_bomb_damage_SpellScript();
        }
};

class spell_xt002_tympanic_tantrum : public SpellScriptLoader
{
    public:
        spell_xt002_tympanic_tantrum() : SpellScriptLoader("spell_xt002_tympanic_tantrum") { }

        class spell_xt002_tympanic_tantrum_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_tympanic_tantrum_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(PlayerOrPetCheck());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_xt002_tympanic_tantrum_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_xt002_tympanic_tantrum_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_xt002_tympanic_tantrum_SpellScript();
        }
};

class achievement_nerf_engineering : public AchievementCriteriaScript
{
    public:
        achievement_nerf_engineering() : AchievementCriteriaScript("achievement_nerf_engineering") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target || !target->GetAI())
                return false;

            return !(target->GetAI()->GetData(DATA_HEALTH_RECOVERED));
        }
};

class achievement_heartbreaker : public AchievementCriteriaScript
{
    public:
        achievement_heartbreaker() : AchievementCriteriaScript("achievement_heartbreaker") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target || !target->GetAI())
                return false;

            return target->GetAI()->GetData(DATA_HARD_MODE);
        }
};

class achievement_nerf_gravity_bombs : public AchievementCriteriaScript
{
    public:
        achievement_nerf_gravity_bombs() : AchievementCriteriaScript("achievement_nerf_gravity_bombs") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target || !target->GetAI())
                return false;

            return !(target->GetAI()->GetData(DATA_GRAVITY_BOMB_CASUALTY));
        }
};

void AddSC_boss_xt002()
{
    new boss_xt002();
    new mob_xt002_heart();
    new mob_scrapbot();
    new mob_pummeller();
    new mob_boombot();
    new mob_void_zone();
    new mob_life_spark();
    new spell_xt002_searing_light();
    new spell_xt002_gravity_bomb();
    new spell_xt002_gravity_bomb_damage();
    new spell_xt002_tympanic_tantrum();
    new achievement_nerf_engineering();
    new achievement_heartbreaker();
    new achievement_nerf_gravity_bombs();
}

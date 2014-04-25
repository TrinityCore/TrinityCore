/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Bosses_Opera
SD%Complete: 90
SDComment: Oz, Hood, and RAJ event implemented. RAJ event requires more testing.
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "karazhan.h"
#include "Player.h"
#include "SpellInfo.h"

/***********************************/
/*** OPERA WIZARD OF OZ EVENT *****/
/*********************************/
enum Says
{
    SAY_DOROTHEE_DEATH          = 0,
    SAY_DOROTHEE_SUMMON         = 1,
    SAY_DOROTHEE_TITO_DEATH     = 2,
    SAY_DOROTHEE_AGGRO          = 3,

    SAY_ROAR_AGGRO              = 0,
    SAY_ROAR_DEATH              = 1,
    SAY_ROAR_SLAY               = 2,

    SAY_STRAWMAN_AGGRO          = 0,
    SAY_STRAWMAN_DEATH          = 1,
    SAY_STRAWMAN_SLAY           = 2,

    SAY_TINHEAD_AGGRO           = 0,
    SAY_TINHEAD_DEATH           = 1,
    SAY_TINHEAD_SLAY            = 2,
    EMOTE_RUST                  = 3,

    SAY_CRONE_AGGRO             = 0,
    SAY_CRONE_DEATH             = 1,
    SAY_CRONE_SLAY              = 2,
};

enum Spells
{
    // Dorothee
    SPELL_WATERBOLT         = 31012,
    SPELL_SCREAM            = 31013,
    SPELL_SUMMONTITO        = 31014,

    // Tito
    SPELL_YIPPING           = 31015,

    // Strawman
    SPELL_BRAIN_BASH        = 31046,
    SPELL_BRAIN_WIPE        = 31069,
    SPELL_BURNING_STRAW     = 31075,

    // Tinhead
    SPELL_CLEAVE            = 31043,
    SPELL_RUST              = 31086,

    // Roar
    SPELL_MANGLE            = 31041,
    SPELL_SHRED             = 31042,
    SPELL_FRIGHTENED_SCREAM = 31013,

    // Crone
    SPELL_CHAIN_LIGHTNING   = 32337,

    // Cyclone
    SPELL_KNOCKBACK         = 32334,
    SPELL_CYCLONE_VISUAL    = 32332,
};

enum Creatures
{
    CREATURE_TITO           = 17548,
    CREATURE_CYCLONE        = 18412,
    CREATURE_CRONE          = 18168,
};

void SummonCroneIfReady(InstanceScript* instance, Creature* creature)
{
    instance->SetData(DATA_OPERA_OZ_DEATHCOUNT, SPECIAL);  // Increment DeathCount

    if (instance->GetData(DATA_OPERA_OZ_DEATHCOUNT) == 4)
    {
        if (Creature* pCrone = creature->SummonCreature(CREATURE_CRONE, -10891.96f, -1755.95f, creature->GetPositionZ(), 4.64f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, HOUR*2*IN_MILLISECONDS))
        {
            if (creature->GetVictim())
                pCrone->AI()->AttackStart(creature->GetVictim());
        }
    }
};

class boss_dorothee : public CreatureScript
{
public:
    boss_dorothee() : CreatureScript("boss_dorothee") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_dorotheeAI>(creature);
    }

    struct boss_dorotheeAI : public ScriptedAI
    {
        boss_dorotheeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 AggroTimer;

        uint32 WaterBoltTimer;
        uint32 FearTimer;
        uint32 SummonTitoTimer;

        bool SummonedTito;
        bool TitoDied;

        void Reset() OVERRIDE
        {
            AggroTimer = 500;

            WaterBoltTimer = 5000;
            FearTimer = 15000;
            SummonTitoTimer = 47500;

            SummonedTito = false;
            TitoDied = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_DOROTHEE_AGGRO);
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void SummonTito();

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DOROTHEE_DEATH);

            SummonCroneIfReady(instance, me);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (AggroTimer)
            {
                if (AggroTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    AggroTimer = 0;
                } else AggroTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (WaterBoltTimer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_WATERBOLT);
                WaterBoltTimer = TitoDied ? 1500 : 5000;
            } else WaterBoltTimer -= diff;

            if (FearTimer <= diff)
            {
                DoCastVictim(SPELL_SCREAM);
                FearTimer = 30000;
            } else FearTimer -= diff;

            if (!SummonedTito)
            {
                if (SummonTitoTimer <= diff)
                    SummonTito();
                else SummonTitoTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_tito : public CreatureScript
{
public:
    npc_tito() : CreatureScript("npc_tito") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_titoAI(creature);
    }

    struct npc_titoAI : public ScriptedAI
    {
        npc_titoAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 DorotheeGUID;
        uint32 YipTimer;

        void Reset() OVERRIDE
        {
            DorotheeGUID = 0;
            YipTimer = 10000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (DorotheeGUID)
            {
                Creature* Dorothee = (Unit::GetCreature((*me), DorotheeGUID));
                if (Dorothee && Dorothee->IsAlive())
                {
                    CAST_AI(boss_dorothee::boss_dorotheeAI, Dorothee->AI())->TitoDied = true;
                    Talk(SAY_DOROTHEE_TITO_DEATH, Dorothee);
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (YipTimer <= diff)
            {
                DoCastVictim(SPELL_YIPPING);
                YipTimer = 10000;
            } else YipTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void boss_dorothee::boss_dorotheeAI::SummonTito()
{
    if (Creature* pTito = me->SummonCreature(CREATURE_TITO, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
    {
        Talk(SAY_DOROTHEE_SUMMON);
        CAST_AI(npc_tito::npc_titoAI, pTito->AI())->DorotheeGUID = me->GetGUID();
        pTito->AI()->AttackStart(me->GetVictim());
        SummonedTito = true;
        TitoDied = false;
    }
}

class boss_strawman : public CreatureScript
{
public:
    boss_strawman() : CreatureScript("boss_strawman") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_strawmanAI>(creature);
    }

    struct boss_strawmanAI : public ScriptedAI
    {
        boss_strawmanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 AggroTimer;
        uint32 BrainBashTimer;
        uint32 BrainWipeTimer;

        void Reset() OVERRIDE
        {
            AggroTimer = 13000;
            BrainBashTimer = 5000;
            BrainWipeTimer = 7000;
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_STRAWMAN_AGGRO);
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* Spell) OVERRIDE
        {
            if ((Spell->SchoolMask == SPELL_SCHOOL_MASK_FIRE) && (!(rand()%10)))
            {
                /*
                    if (not direct damage(aoe, dot))
                        return;
                */

                DoCast(me, SPELL_BURNING_STRAW, true);
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_STRAWMAN_DEATH);

            SummonCroneIfReady(instance, me);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_STRAWMAN_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (AggroTimer)
            {
                if (AggroTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    AggroTimer = 0;
                } else AggroTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (BrainBashTimer <= diff)
            {
                DoCastVictim(SPELL_BRAIN_BASH);
                BrainBashTimer = 15000;
            } else BrainBashTimer -= diff;

            if (BrainWipeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_BRAIN_WIPE);
                BrainWipeTimer = 20000;
            } else BrainWipeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_tinhead : public CreatureScript
{
public:
    boss_tinhead() : CreatureScript("boss_tinhead") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_tinheadAI>(creature);
    }

    struct boss_tinheadAI : public ScriptedAI
    {
        boss_tinheadAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 AggroTimer;
        uint32 CleaveTimer;
        uint32 RustTimer;

        uint8 RustCount;

        void Reset() OVERRIDE
        {
            AggroTimer = 15000;
            CleaveTimer = 5000;
            RustTimer   = 30000;

            RustCount   = 0;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_TINHEAD_AGGRO);
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_TINHEAD_DEATH);

            SummonCroneIfReady(instance, me);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_TINHEAD_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (AggroTimer)
            {
                if (AggroTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    AggroTimer = 0;
                } else AggroTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (CleaveTimer <= diff)
            {
                DoCastVictim(SPELL_CLEAVE);
                CleaveTimer = 5000;
            } else CleaveTimer -= diff;

            if (RustCount < 8)
            {
                if (RustTimer <= diff)
                {
                    ++RustCount;
                    Talk(EMOTE_RUST);
                    DoCast(me, SPELL_RUST);
                    RustTimer = 6000;
                } else RustTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class boss_roar : public CreatureScript
{
public:
    boss_roar() : CreatureScript("boss_roar") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_roarAI>(creature);
    }

    struct boss_roarAI : public ScriptedAI
    {
        boss_roarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 AggroTimer;
        uint32 MangleTimer;
        uint32 ShredTimer;
        uint32 ScreamTimer;

        void Reset() OVERRIDE
        {
            AggroTimer = 20000;
            MangleTimer = 5000;
            ShredTimer  = 10000;
            ScreamTimer = 15000;
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::AttackStart(who);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_ROAR_AGGRO);
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_ROAR_DEATH);

            SummonCroneIfReady(instance, me);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_ROAR_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (AggroTimer)
            {
                if (AggroTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    AggroTimer = 0;
                } else AggroTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (MangleTimer <= diff)
            {
                DoCastVictim(SPELL_MANGLE);
                MangleTimer = urand(5000, 8000);
            } else MangleTimer -= diff;

            if (ShredTimer <= diff)
            {
                DoCastVictim(SPELL_SHRED);
                ShredTimer = urand(10000, 15000);
            } else ShredTimer -= diff;

            if (ScreamTimer <= diff)
            {
                DoCastVictim(SPELL_FRIGHTENED_SCREAM);
                ScreamTimer = urand(20000, 30000);
            } else ScreamTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class boss_crone : public CreatureScript
{
public:
    boss_crone() : CreatureScript("boss_crone") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_croneAI>(creature);
    }

    struct boss_croneAI : public ScriptedAI
    {
        boss_croneAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 CycloneTimer;
        uint32 ChainLightningTimer;

        void Reset() OVERRIDE
        {
            CycloneTimer = 30000;
            ChainLightningTimer = 10000;
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
           Talk(SAY_CRONE_SLAY);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_CRONE_AGGRO);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_CRONE_DEATH);

            instance->SetData(TYPE_OPERA, DONE);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORLEFT), true);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORRIGHT), true);

            if (GameObject* pSideEntrance = instance->instance->GetGameObject(instance->GetData64(DATA_GO_SIDE_ENTRANCE_DOOR)))
                pSideEntrance->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            if (CycloneTimer <= diff)
            {
                if (Creature* Cyclone = DoSpawnCreature(CREATURE_CYCLONE, float(urand(0, 9)), float(urand(0, 9)), 0, 0, TEMPSUMMON_TIMED_DESPAWN, 15000))
                    Cyclone->CastSpell(Cyclone, SPELL_CYCLONE_VISUAL, true);
                CycloneTimer = 30000;
            } else CycloneTimer -= diff;

            if (ChainLightningTimer <= diff)
            {
                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                ChainLightningTimer = 15000;
            } else ChainLightningTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_cyclone : public CreatureScript
{
public:
    npc_cyclone() : CreatureScript("npc_cyclone") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_cycloneAI(creature);
    }

    struct npc_cycloneAI : public ScriptedAI
    {
        npc_cycloneAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 MoveTimer;

        void Reset() OVERRIDE
        {
            MoveTimer = 1000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE

        {
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!me->HasAura(SPELL_KNOCKBACK))
                DoCast(me, SPELL_KNOCKBACK, true);

            if (MoveTimer <= diff)
            {
                Position pos = me->GetRandomNearPosition(10);
                me->GetMotionMaster()->MovePoint(0, pos);
                MoveTimer = urand(5000, 8000);
            } else MoveTimer -= diff;
        }
    };
};

/**************************************/
/**** Opera Red Riding Hood Event* ***/
/************************************/
enum RedRidingHood
{
    SAY_WOLF_AGGRO                  = 0,
    SAY_WOLF_SLAY                   = 1,
    SAY_WOLF_HOOD                   = 2,
    SOUND_WOLF_DEATH                = 9275,

    SPELL_LITTLE_RED_RIDING_HOOD    = 30768,
    SPELL_TERRIFYING_HOWL           = 30752,
    SPELL_WIDE_SWIPE                = 30761,

    CREATURE_BIG_BAD_WOLF           = 17521,
};


#define GOSSIP_GRANDMA          "What phat lewtz you have grandmother?"



class npc_grandmother : public CreatureScript
{
public:
    npc_grandmother() : CreatureScript("npc_grandmother") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF)
        {
            if (Creature* pBigBadWolf = creature->SummonCreature(CREATURE_BIG_BAD_WOLF, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, HOUR*2*IN_MILLISECONDS))
                pBigBadWolf->AI()->AttackStart(player);

            creature->DespawnOrUnsummon();
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_GRANDMA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->SEND_GOSSIP_MENU(8990, creature->GetGUID());

        return true;
    }
};

class boss_bigbadwolf : public CreatureScript
{
public:
    boss_bigbadwolf() : CreatureScript("boss_bigbadwolf") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_bigbadwolfAI>(creature);
    }

    struct boss_bigbadwolfAI : public ScriptedAI
    {
        boss_bigbadwolfAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 ChaseTimer;
        uint32 FearTimer;
        uint32 SwipeTimer;

        uint64 HoodGUID;
        float TempThreat;

        bool IsChasing;

        void Reset() OVERRIDE
        {
            ChaseTimer = 30000;
            FearTimer = urand(25000, 35000);
            SwipeTimer = 5000;

            HoodGUID = 0;
            TempThreat = 0;

            IsChasing = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_WOLF_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_WOLF_SLAY);
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            DoPlaySoundToSet(me, SOUND_WOLF_DEATH);

            instance->SetData(TYPE_OPERA, DONE);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORLEFT), true);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORRIGHT), true);

            if (GameObject* pSideEntrance = instance->instance->GetGameObject(instance->GetData64(DATA_GO_SIDE_ENTRANCE_DOOR)))
                pSideEntrance->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();

            if (ChaseTimer <= diff)
            {
                if (!IsChasing)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        Talk(SAY_WOLF_HOOD);
                        DoCast(target, SPELL_LITTLE_RED_RIDING_HOOD, true);
                        TempThreat = DoGetThreat(target);
                        if (TempThreat)
                            DoModifyThreatPercent(target, -100);
                        HoodGUID = target->GetGUID();
                        me->AddThreat(target, 1000000.0f);
                        ChaseTimer = 20000;
                        IsChasing = true;
                    }
                }
                else
                {
                    IsChasing = false;

                    if (Unit* target = Unit::GetUnit(*me, HoodGUID))
                    {
                        HoodGUID = 0;
                        if (DoGetThreat(target))
                            DoModifyThreatPercent(target, -100);
                        me->AddThreat(target, TempThreat);
                        TempThreat = 0;
                    }

                    ChaseTimer = 40000;
                }
            } else ChaseTimer -= diff;

            if (IsChasing)
                return;

            if (FearTimer <= diff)
            {
                DoCastVictim(SPELL_TERRIFYING_HOWL);
                FearTimer = urand(25000, 35000);
            } else FearTimer -= diff;

            if (SwipeTimer <= diff)
            {
                DoCastVictim(SPELL_WIDE_SWIPE);
                SwipeTimer = urand(25000, 30000);
            } else SwipeTimer -= diff;
        }
    };
};

/**********************************************/
/******** Opera Romeo and Juliet Event* ******/
/********************************************/

enum JulianneRomulo
{
    /**** Speech *****/
    SAY_JULIANNE_AGGRO              = 0,
    SAY_JULIANNE_ENTER              = 1,
    SAY_JULIANNE_DEATH01            = 2,
    SAY_JULIANNE_DEATH02            = 3,
    SAY_JULIANNE_RESURRECT          = 4,
    SAY_JULIANNE_SLAY               = 5,

    SAY_ROMULO_AGGRO                = 0,
    SAY_ROMULO_DEATH                = 1,
    SAY_ROMULO_ENTER                = 2,
    SAY_ROMULO_RESURRECT            = 3,
    SAY_ROMULO_SLAY                 = 4,

    SPELL_BLINDING_PASSION          = 30890,
    SPELL_DEVOTION                  = 30887,
    SPELL_ETERNAL_AFFECTION         = 30878,
    SPELL_POWERFUL_ATTRACTION       = 30889,
    SPELL_DRINK_POISON              = 30907,

    SPELL_BACKWARD_LUNGE            = 30815,
    SPELL_DARING                    = 30841,
    SPELL_DEADLY_SWATHE             = 30817,
    SPELL_POISON_THRUST             = 30822,

    SPELL_UNDYING_LOVE              = 30951,
    SPELL_RES_VISUAL                = 24171,

    CREATURE_ROMULO                 = 17533,
    ROMULO_X                        = -10900,
    ROMULO_Y                        = -1758,
};


enum RAJPhase
{
    PHASE_JULIANNE      = 0,
    PHASE_ROMULO        = 1,
    PHASE_BOTH          = 2,
};

void PretendToDie(Creature* creature)
{
    creature->InterruptNonMeleeSpells(true);
    creature->RemoveAllAuras();
    creature->SetHealth(0);
    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    creature->GetMotionMaster()->MovementExpired(false);
    creature->GetMotionMaster()->MoveIdle();
    creature->SetStandState(UNIT_STAND_STATE_DEAD);
}

void Resurrect(Creature* target)
{
    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    target->SetFullHealth();
    target->SetStandState(UNIT_STAND_STATE_STAND);
    target->CastSpell(target, SPELL_RES_VISUAL, true);
    if (target->GetVictim())
    {
        target->GetMotionMaster()->MoveChase(target->GetVictim());
        target->AI()->AttackStart(target->GetVictim());
    }
        else
            target->GetMotionMaster()->Initialize();
}

class boss_julianne : public CreatureScript
{
public:
    boss_julianne() : CreatureScript("boss_julianne") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_julianneAI>(creature);
    }

    struct boss_julianneAI : public ScriptedAI
    {
        boss_julianneAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            EntryYellTimer = 1000;
            AggroYellTimer = 10000;
            IsFakingDeath = false;
        }

        InstanceScript* instance;

        uint32 EntryYellTimer;
        uint32 AggroYellTimer;

        uint64 RomuloGUID;

        uint32 Phase;

        uint32 BlindingPassionTimer;
        uint32 DevotionTimer;
        uint32 EternalAffectionTimer;
        uint32 PowerfulAttractionTimer;
        uint32 SummonRomuloTimer;
        uint32 ResurrectTimer;
        uint32 DrinkPoisonTimer;
        uint32 ResurrectSelfTimer;

        bool IsFakingDeath;
        bool SummonedRomulo;
        bool RomuloDead;

        void Reset() OVERRIDE
        {
            RomuloGUID = 0;
            Phase = PHASE_JULIANNE;

            BlindingPassionTimer = 30000;
            DevotionTimer = 15000;
            EternalAffectionTimer = 25000;
            PowerfulAttractionTimer = 5000;
            SummonRomuloTimer = 10000;
            DrinkPoisonTimer = 0;
            ResurrectSelfTimer = 0;

            if (IsFakingDeath)
            {
                Resurrect(me);
                IsFakingDeath = false;
            }

            SummonedRomulo = false;
            RomuloDead = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* Spell) OVERRIDE
        {
            if (Spell->Id == SPELL_DRINK_POISON)
            {
                Talk(SAY_JULIANNE_DEATH01);
                DrinkPoisonTimer = 2500;
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) OVERRIDE;

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_JULIANNE_DEATH02);

            instance->SetData(TYPE_OPERA, DONE);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORLEFT), true);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORRIGHT), true);
            if (GameObject* pSideEntrance = instance->instance->GetGameObject(instance->GetData64(DATA_GO_SIDE_ENTRANCE_DOOR)))
                pSideEntrance->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
           Talk(SAY_JULIANNE_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE;
    };
};

class boss_romulo : public CreatureScript
{
public:
    boss_romulo() : CreatureScript("boss_romulo") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_romuloAI>(creature);
    }

    struct boss_romuloAI : public ScriptedAI
    {
        boss_romuloAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            EntryYellTimer = 8000;
            AggroYellTimer = 15000;
        }

        InstanceScript* instance;

        uint64 JulianneGUID;
        uint32 Phase;

        uint32 EntryYellTimer;
        uint32 AggroYellTimer;
        uint32 BackwardLungeTimer;
        uint32 DaringTimer;
        uint32 DeadlySwatheTimer;
        uint32 PoisonThrustTimer;
        uint32 ResurrectTimer;

        bool IsFakingDeath;
        bool JulianneDead;

        void Reset() OVERRIDE
        {
            JulianneGUID = 0;
            Phase = PHASE_ROMULO;

            BackwardLungeTimer = 15000;
            DaringTimer = 20000;
            DeadlySwatheTimer = 25000;
            PoisonThrustTimer = 10000;
            ResurrectTimer = 10000;

            IsFakingDeath = false;
            JulianneDead = false;
        }

        void JustReachedHome() OVERRIDE
        {
            me->DespawnOrUnsummon();
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) OVERRIDE
        {
            if (damage < me->GetHealth())
                return;

            //anything below only used if incoming damage will kill

            if (Phase == PHASE_ROMULO)
            {
                Talk(SAY_ROMULO_DEATH);
                PretendToDie(me);
                IsFakingDeath = true;
                Phase = PHASE_BOTH;

                if (Creature* Julianne = (Unit::GetCreature((*me), JulianneGUID)))
                {
                    CAST_AI(boss_julianne::boss_julianneAI, Julianne->AI())->RomuloDead = true;
                    CAST_AI(boss_julianne::boss_julianneAI, Julianne->AI())->ResurrectSelfTimer = 10000;
                }

                damage = 0;
                return;
            }

            if (Phase == PHASE_BOTH)
            {
                if (JulianneDead)
                {
                    if (Creature* Julianne = (Unit::GetCreature((*me), JulianneGUID)))
                    {
                        Julianne->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Julianne->GetMotionMaster()->Clear();
                        Julianne->setDeathState(JUST_DIED);
                        Julianne->CombatStop(true);
                        Julianne->DeleteThreatList();
                        Julianne->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                    }
                    return;
                }

                if (Creature* Julianne = (Unit::GetCreature((*me), JulianneGUID)))
                {
                    PretendToDie(me);
                    IsFakingDeath = true;
                    CAST_AI(boss_julianne::boss_julianneAI, Julianne->AI())->ResurrectTimer = 10000;
                    CAST_AI(boss_julianne::boss_julianneAI, Julianne->AI())->RomuloDead = true;
                    damage = 0;
                    return;
                }
            }

            TC_LOG_ERROR("scripts", "boss_romuloAI: DamageTaken reach end of code, that should not happen.");
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_ROMULO_AGGRO);
            if (JulianneGUID)
            {
                Creature* Julianne = (Unit::GetCreature((*me), JulianneGUID));
                if (Julianne && Julianne->GetVictim())
                {
                    me->AddThreat(Julianne->GetVictim(), 1.0f);
                    AttackStart(Julianne->GetVictim());
                }
            }
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_ROMULO_DEATH);

            instance->SetData(TYPE_OPERA, DONE);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORLEFT), true);
            instance->HandleGameObject(instance->GetData64(DATA_GO_STAGEDOORRIGHT), true);

            if (GameObject* pSideEntrance = instance->instance->GetGameObject(instance->GetData64(DATA_GO_SIDE_ENTRANCE_DOOR)))
                pSideEntrance->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_ROMULO_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim() || IsFakingDeath)
                return;

            if (JulianneDead)
            {
                if (ResurrectTimer <= diff)
                {
                    Creature* Julianne = (Unit::GetCreature((*me), JulianneGUID));
                    if (Julianne && CAST_AI(boss_julianne::boss_julianneAI, Julianne->AI())->IsFakingDeath)
                    {
                        Talk(SAY_ROMULO_RESURRECT);
                        Resurrect(Julianne);
                        CAST_AI(boss_julianne::boss_julianneAI, Julianne->AI())->IsFakingDeath = false;
                        JulianneDead = false;
                        ResurrectTimer = 10000;
                    }
                } else ResurrectTimer -= diff;
            }

            if (BackwardLungeTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
                if (target && !me->HasInArc(M_PI, target))
                {
                    DoCast(target, SPELL_BACKWARD_LUNGE);
                    BackwardLungeTimer = urand(15000, 30000);
                }
            } else BackwardLungeTimer -= diff;

            if (DaringTimer <= diff)
            {
                DoCast(me, SPELL_DARING);
                DaringTimer = urand(20000, 40000);
            } else DaringTimer -= diff;

            if (DeadlySwatheTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_DEADLY_SWATHE);
                DeadlySwatheTimer = urand(15000, 25000);
            } else DeadlySwatheTimer -= diff;

            if (PoisonThrustTimer <= diff)
            {
                DoCastVictim(SPELL_POISON_THRUST);
                PoisonThrustTimer = urand(10000, 20000);
            } else PoisonThrustTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void boss_julianne::boss_julianneAI::UpdateAI(uint32 diff)
{
    if (EntryYellTimer)
    {
        if (EntryYellTimer <= diff)
        {
            Talk(SAY_JULIANNE_ENTER);
            EntryYellTimer = 0;
        } else EntryYellTimer -= diff;
    }

    if (AggroYellTimer)
    {
        if (AggroYellTimer <= diff)
        {
            Talk(SAY_JULIANNE_AGGRO);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->setFaction(16);
            AggroYellTimer = 0;
        } else AggroYellTimer -= diff;
    }

    if (DrinkPoisonTimer)
    {
        //will do this 2secs after spell hit. this is time to display visual as expected
        if (DrinkPoisonTimer <= diff)
        {
            PretendToDie(me);
            Phase = PHASE_ROMULO;
            SummonRomuloTimer = 10000;
            DrinkPoisonTimer = 0;
        } else DrinkPoisonTimer -= diff;
    }

    if (Phase == PHASE_ROMULO && !SummonedRomulo)
    {
        if (SummonRomuloTimer <= diff)
        {
            if (Creature* pRomulo = me->SummonCreature(CREATURE_ROMULO, ROMULO_X, ROMULO_Y, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, HOUR*2*IN_MILLISECONDS))
            {
                RomuloGUID = pRomulo->GetGUID();
                CAST_AI(boss_romulo::boss_romuloAI, pRomulo->AI())->JulianneGUID = me->GetGUID();
                CAST_AI(boss_romulo::boss_romuloAI, pRomulo->AI())->Phase = PHASE_ROMULO;
                DoZoneInCombat(pRomulo);

                pRomulo->setFaction(16);
            }
            SummonedRomulo = true;
        } else SummonRomuloTimer -= diff;
    }

    if (ResurrectSelfTimer)
    {
        if (ResurrectSelfTimer <= diff)
        {
            Resurrect(me);
            Phase = PHASE_BOTH;
            IsFakingDeath = false;

            if (me->GetVictim())
                AttackStart(me->GetVictim());

            ResurrectSelfTimer = 0;
            ResurrectTimer = 1000;
        } else ResurrectSelfTimer -= diff;
    }

    if (!UpdateVictim() || IsFakingDeath)
        return;

    if (RomuloDead)
    {
        if (ResurrectTimer <= diff)
        {
            Creature* Romulo = (Unit::GetCreature((*me), RomuloGUID));
            if (Romulo && CAST_AI(boss_romulo::boss_romuloAI, Romulo->AI())->IsFakingDeath)
            {
                Talk(SAY_JULIANNE_RESURRECT);
                Resurrect(Romulo);
                CAST_AI(boss_romulo::boss_romuloAI, Romulo->AI())->IsFakingDeath = false;
                RomuloDead = false;
                ResurrectTimer = 10000;
            }
        } else ResurrectTimer -= diff;
    }

    if (BlindingPassionTimer <= diff)
    {
        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            DoCast(target, SPELL_BLINDING_PASSION);
        BlindingPassionTimer = urand(30000, 45000);
    } else BlindingPassionTimer -= diff;

    if (DevotionTimer <= diff)
    {
        DoCast(me, SPELL_DEVOTION);
        DevotionTimer = urand(15000, 45000);
    } else DevotionTimer -= diff;

    if (PowerfulAttractionTimer <= diff)
    {
        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_POWERFUL_ATTRACTION);
        PowerfulAttractionTimer = urand(5000, 30000);
    } else PowerfulAttractionTimer -= diff;

    if (EternalAffectionTimer <= diff)
    {
        if (urand(0, 1) && SummonedRomulo)
        {
            Creature* Romulo = (Unit::GetCreature((*me), RomuloGUID));
            if (Romulo && Romulo->IsAlive() && !RomuloDead)
                DoCast(Romulo, SPELL_ETERNAL_AFFECTION);
        } else DoCast(me, SPELL_ETERNAL_AFFECTION);

        EternalAffectionTimer = urand(45000, 60000);
    } else EternalAffectionTimer -= diff;

    DoMeleeAttackIfReady();
}

void boss_julianne::boss_julianneAI::DamageTaken(Unit* /*done_by*/, uint32 &damage)
{
    if (damage < me->GetHealth())
        return;

    //anything below only used if incoming damage will kill

    if (Phase == PHASE_JULIANNE)
    {
        damage = 0;

        //this means already drinking, so return
        if (IsFakingDeath)
            return;

        me->InterruptNonMeleeSpells(true);
        DoCast(me, SPELL_DRINK_POISON);

        IsFakingDeath = true;
        //IS THIS USEFULL? Creature* Julianne = (Unit::GetCreature((*me), JulianneGUID));
        return;
    }

    if (Phase == PHASE_ROMULO)
    {
        TC_LOG_ERROR("scripts", "boss_julianneAI: cannot take damage in PHASE_ROMULO, why was i here?");
        damage = 0;
        return;
    }

    if (Phase == PHASE_BOTH)
    {
        //if this is true then we have to kill romulo too
        if (RomuloDead)
        {
            if (Creature* Romulo = (Unit::GetCreature((*me), RomuloGUID)))
            {
                Romulo->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                Romulo->GetMotionMaster()->Clear();
                Romulo->setDeathState(JUST_DIED);
                Romulo->CombatStop(true);
                Romulo->DeleteThreatList();
                Romulo->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }

            return;
        }

        //if not already returned, then romulo is alive and we can pretend die
        if (Creature* Romulo = (Unit::GetCreature((*me), RomuloGUID)))
        {
            PretendToDie(me);
            IsFakingDeath = true;
            CAST_AI(boss_romulo::boss_romuloAI, Romulo->AI())->ResurrectTimer = 10000;
            CAST_AI(boss_romulo::boss_romuloAI, Romulo->AI())->JulianneDead = true;
            damage = 0;
            return;
        }
    }
    TC_LOG_ERROR("scripts", "boss_julianneAI: DamageTaken reach end of code, that should not happen.");
}

void AddSC_bosses_opera()
{
    new boss_dorothee();
    new boss_strawman();
    new boss_tinhead();
    new boss_roar();
    new boss_crone();
    new npc_tito();
    new npc_cyclone();
    new npc_grandmother();
    new boss_bigbadwolf();
    new boss_julianne();
    new boss_romulo();
}

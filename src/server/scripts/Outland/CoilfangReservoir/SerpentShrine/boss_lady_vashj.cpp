/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Boss_Lady_Vashj
SD%Complete: 99
SDComment: Missing blizzlike Shield Generators coords
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"
#include "TemporarySummon.h"

enum LadyVashj
{
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_PHASE1                  = 2,
    SAY_PHASE2                  = 3,
    SAY_PHASE3                  = 4,
    SAY_BOWSHOT                 = 5,
    SAY_SLAY                    = 6,
    SAY_DEATH                   = 7,

    SPELL_SURGE                 = 38044,
    SPELL_MULTI_SHOT            = 38310,
    SPELL_SHOCK_BLAST           = 38509,
    SPELL_ENTANGLE              = 38316,
    SPELL_STATIC_CHARGE_TRIGGER = 38280,
    SPELL_FORKED_LIGHTNING      = 40088,
    SPELL_SHOOT                 = 40873,
    SPELL_POISON_BOLT           = 40095,
    SPELL_TOXIC_SPORES          = 38575,
    SPELL_MAGIC_BARRIER         = 38112,

    SHIED_GENERATOR_CHANNEL     = 19870,
    ENCHANTED_ELEMENTAL         = 21958,
    TAINTED_ELEMENTAL           = 22009,
    COILFANG_STRIDER            = 22056,
    COILFANG_ELITE              = 22055,
    TOXIC_SPOREBAT              = 22140,
    TOXIC_SPORES_TRIGGER        = 22207
};

#define MIDDLE_X                30.134f
#define MIDDLE_Y                -923.65f
#define MIDDLE_Z                42.9f

#define SPOREBAT_X              30.977156f
#define SPOREBAT_Y                  -925.297761f
#define SPOREBAT_Z                  77.176567f
#define SPOREBAT_O                  5.223932f

float ElementPos[8][4] =
{
    {8.3f, -835.3f, 21.9f, 5.0f},
    {53.4f, -835.3f, 21.9f, 4.5f},
    {96.0f, -861.9f, 21.8f, 4.0f},
    {96.0f, -986.4f, 21.4f, 2.5f},
    {54.4f, -1010.6f, 22, 1.8f},
    {9.8f, -1012, 21.7f, 1.4f},
    {-35.0f, -987.6f, 21.5f, 0.8f},
    {-58.9f, -901.6f, 21.5f, 6.0f}
};

float ElementWPPos[8][3] =
{
    {71.700752f, -883.905884f, 41.097168f},
    {45.039848f, -868.022827f, 41.097015f},
    {14.585141f, -867.894470f, 41.097061f},
    {-25.415508f, -906.737732f, 41.097061f},
    {-11.801594f, -963.405884f, 41.097067f},
    {14.556657f, -979.051514f, 41.097137f},
    {43.466549f, -979.406677f, 41.097027f},
    {69.945908f, -964.663940f, 41.097054f}
};

float SporebatWPPos[8][3] =
{
    {31.6f, -896.3f, 59.1f},
    {9.1f,  -913.9f, 56.0f},
    {5.2f,  -934.4f, 52.4f},
    {20.7f, -946.9f, 49.7f},
    {41.0f, -941.9f, 51.0f},
    {47.7f, -927.3f, 55.0f},
    {42.2f, -912.4f, 51.7f},
    {27.0f, -905.9f, 50.0f}
};

float CoilfangElitePos[3][4] =
{
    {28.84f, -923.28f, 42.9f, 6.0f},
    {31.183281f, -953.502625f, 41.523602f, 1.640957f},
    {58.895180f, -923.124268f, 41.545307f, 3.152848f}
};

float CoilfangStriderPos[3][4] =
{
    {66.427010f, -948.778503f, 41.262245f, 2.584220f},
    {7.513962f, -959.538208f, 41.300422f, 1.034629f},
    {-12.843201f, -907.798401f, 41.239620f, 6.087094f}
};

float ShieldGeneratorChannelPos[4][4] =
{
    {49.6262f, -902.181f, 43.0975f, 3.95683f},
    {10.988f, -901.616f, 42.5371f, 5.4373f},
    {10.3859f, -944.036f, 42.5446f, 0.779888f},
    {49.3126f, -943.398f, 42.5501f, 2.40174f}
};

struct boss_lady_vashj : public BossAI
{
    boss_lady_vashj(Creature* creature) : BossAI(creature, BOSS_LADY_VASHJ)
    {
        Initialize();
        instance = creature->GetInstanceScript();
        Intro = false;
        JustCreated = true;
        CanAttack = false;
        creature->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE); // set it only once on Creature create (no need do intro if wiped)
    }

    void Initialize()
    {
        AggroTimer = 19000;
        ShockBlastTimer = 1 + rand32() % 60000;
        EntangleTimer = 30000;
        StaticChargeTimer = 10000 + rand32() % 15000;
        ForkedLightningTimer = 2000;
        CheckTimer = 15000;
        EnchantedElementalTimer = 5000;
        TaintedElementalTimer = 50000;
        CoilfangEliteTimer = 45000 + rand32() % 5000;
        CoilfangStriderTimer = 60000 + rand32() % 10000;
        SummonSporebatTimer = 10000;
        SummonSporebatStaticTimer = 30000;
        EnchantedElementalPos = 0;
        Phase = 0;

        Entangle = false;
    }

    InstanceScript* instance;

    ObjectGuid ShieldGeneratorChannel[4];

    uint32 AggroTimer;
    uint32 ShockBlastTimer;
    uint32 EntangleTimer;
    uint32 StaticChargeTimer;
    uint32 ForkedLightningTimer;
    uint32 CheckTimer;
    uint32 EnchantedElementalTimer;
    uint32 TaintedElementalTimer;
    uint32 CoilfangEliteTimer;
    uint32 CoilfangStriderTimer;
    uint32 SummonSporebatTimer;
    uint32 SummonSporebatStaticTimer;
    uint8 EnchantedElementalPos;
    uint8 Phase;

    bool Entangle;
    bool Intro;
    bool CanAttack;
    bool JustCreated;

    void Reset() override
    {
        Initialize();

        if (JustCreated)
        {
            CanAttack = false;
            JustCreated = false;
        } else CanAttack = true;

        for (uint8 i = 0; i < 4; ++i)
        {
            if (!ShieldGeneratorChannel[i].IsEmpty())
            {
                if (Unit* remo = ObjectAccessor::GetUnit(*me, ShieldGeneratorChannel[i]))
                {
                    remo->setDeathState(JUST_DIED);
                    ShieldGeneratorChannel[i].Clear();
                }
            }
        }

        _Reset();

        me->SetCorpseDelay(1000*60*60);
        me->SetCanMelee(true);
    }

    // Called when a tainted elemental dies
    void EventTaintedElementalDeath()
    {
        // the next will spawn 50 seconds after the previous one's death
        if (TaintedElementalTimer > 50000)
            TaintedElementalTimer = 50000;
    }
    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);

        _JustDied();
    }

    void StartEvent(Unit* who)
    {
        Talk(SAY_AGGRO);

        Phase = 1;

        _JustEngagedWith(who);
    }

    void JustEngagedWith(Unit* who) override
    {
        // remove old tainted cores to prevent cheating in phase 2
        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
            if (Player* player = itr->GetSource())
                player->DestroyItemCount(31088, 1, true);
        StartEvent(who); // this is JustEngagedWith(), so were are 100% in combat, start the event

        if (Phase != 2)
            AttackStart(who);
    }

    void MoveInLineOfSight(Unit* who) override

    {
        if (!Intro)
        {
            Intro = true;
            Talk(SAY_INTRO);
        }
        if (!CanAttack)
            return;
        if (!who || me->GetVictim())
            return;

        if (me->CanCreatureAttack(who))
        {
            float attackRadius = me->GetAttackDistance(who);
            if (me->IsWithinDistInMap(who, attackRadius) && me->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && me->IsWithinLOSInMap(who))
            {
                if (!me->IsInCombat()) // AttackStart() sets UNIT_FLAG_IN_COMBAT, so this msut be before attacking
                    StartEvent(who);

                if (Phase != 2)
                    AttackStart(who);
            }
        }
    }

    void CastShootOrMultishot()
    {
        switch (urand(0, 1))
        {
            case 0:
                // Shoot
                // Used in Phases 1 and 3 after Entangle or while having nobody in melee range. A shot that hits her target for 4097-5543 Physical damage.
                DoCastVictim(SPELL_SHOOT);
                break;
            case 1:
                // Multishot
                // Used in Phases 1 and 3 after Entangle or while having nobody in melee range. A shot that hits 1 person and 4 people around him for 6475-7525 physical damage.
                DoCastVictim(SPELL_MULTI_SHOT);
                break;
        }
        if (rand32() % 3)
        {
            Talk(SAY_BOWSHOT);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!CanAttack && Intro)
        {
            if (AggroTimer <= diff)
            {
                CanAttack = true;
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                AggroTimer=19000;
            }
            else
            {
                AggroTimer -= diff;
                return;
            }
        }
        // to prevent abuses during phase 2
        if (Phase == 2 && !me->GetVictim() && me->IsInCombat())
        {
            EnterEvadeMode();
            return;
        }
        // Return since we have no target
        if (!UpdateVictim())
            return;

        if (Phase == 1 || Phase == 3)
        {
            // ShockBlastTimer
            if (ShockBlastTimer <= diff)
            {
                // Shock Burst
                // Randomly used in Phases 1 and 3 on Vashj's target, it's a Shock spell doing 8325-9675 nature damage and stunning the target for 5 seconds, during which she will not attack her target but switch to the next person on the aggro list.
                DoCastVictim(SPELL_SHOCK_BLAST);

                ShockBlastTimer = 1000 + rand32() % 14000;       // random cooldown
            } else ShockBlastTimer -= diff;

            // StaticChargeTimer
            if (StaticChargeTimer <= diff)
            {
                // Static Charge
                // Used on random people (only 1 person at any given time) in Phases 1 and 3, it's a debuff doing 2775 to 3225 Nature damage to the target and everybody in about 5 yards around it, every 1 seconds for 30 seconds. It can be removed by Cloak of Shadows, Iceblock, Divine Shield, etc, but not by Cleanse or Dispel Magic.
                Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 200, true);
                if (target && !target->HasAura(SPELL_STATIC_CHARGE_TRIGGER))
                    DoCast(target, SPELL_STATIC_CHARGE_TRIGGER); // cast Static Charge every 2 seconds for 20 seconds

                StaticChargeTimer = 10000 + rand32() % 20000;
            } else StaticChargeTimer -= diff;

            // EntangleTimer
            if (EntangleTimer <= diff)
            {
                if (!Entangle)
                {
                    // Entangle
                    // Used in Phases 1 and 3, it casts Entangling Roots on everybody in a 15 yard radius of Vashj, immobilzing them for 10 seconds and dealing 500 damage every 2 seconds. It's not a magic effect so it cannot be dispelled, but is removed by various buffs such as Cloak of Shadows or Blessing of Freedom.
                    DoCastVictim(SPELL_ENTANGLE);
                    Entangle = true;
                    EntangleTimer = 10000;
                }
                else
                {
                    CastShootOrMultishot();
                    Entangle = false;
                    EntangleTimer = 20000 + rand32() % 5000;
                }
            } else EntangleTimer -= diff;

            // Phase 1
            if (Phase == 1)
            {
                // Start phase 2
                if (HealthBelowPct(70))
                {
                    // Phase 2 begins when Vashj hits 70%. She will run to the middle of her platform and surround herself in a shield making her invulerable.
                    Phase = 2;
                    me->SetCanMelee(false);

                    me->GetMotionMaster()->Clear();
                    DoTeleportTo(MIDDLE_X, MIDDLE_Y, MIDDLE_Z);

                    for (uint8 i = 0; i < 4; ++i)
                        if (Creature* creature = me->SummonCreature(SHIED_GENERATOR_CHANNEL, ShieldGeneratorChannelPos[i][0],  ShieldGeneratorChannelPos[i][1],  ShieldGeneratorChannelPos[i][2],  ShieldGeneratorChannelPos[i][3], TEMPSUMMON_CORPSE_DESPAWN))
                            ShieldGeneratorChannel[i] = creature->GetGUID();

                    Talk(SAY_PHASE2);
                }
            }
            // Phase 3
            else
            {
                // SummonSporebatTimer
                if (SummonSporebatTimer <= diff)
                {
                    if (Creature* sporebat = me->SummonCreature(TOXIC_SPOREBAT, SPOREBAT_X, SPOREBAT_Y, SPOREBAT_Z, SPOREBAT_O, TEMPSUMMON_CORPSE_DESPAWN))
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                            sporebat->AI()->AttackStart(target);

                    // summon sporebats faster and faster
                    if (SummonSporebatStaticTimer > 1000)
                        SummonSporebatStaticTimer -= 1000;

                    SummonSporebatTimer = SummonSporebatStaticTimer;

                    if (SummonSporebatTimer < 5000)
                        SummonSporebatTimer = 5000;

                } else SummonSporebatTimer -= diff;
            }

            // CheckTimer - used to check if somebody is in melee range
            if (CheckTimer <= diff)
            {
                bool inMeleeRange = false;
                for (auto* ref : me->GetThreatManager().GetUnsortedThreatList())
                {
                    Unit* target = ref->GetVictim();
                    if (target->IsWithinMeleeRange(me)) // if in melee range
                    {
                        inMeleeRange = true;
                        break;
                    }
                }

                // if nobody is in melee range
                if (!inMeleeRange)
                    CastShootOrMultishot();

                CheckTimer = 5000;
            } else CheckTimer -= diff;
        }
        // Phase 2
        else
        {
            // ForkedLightningTimer
            if (ForkedLightningTimer <= diff)
            {
                // Forked Lightning
                // Used constantly in Phase 2, it shoots out completely randomly targeted bolts of lightning which hit everybody in a roughtly 60 degree cone in front of Vashj for 2313-2687 nature damage.
                Unit* target = SelectTarget(SelectTargetMethod::Random, 0);

                if (!target)
                    target = me->GetVictim();

                DoCast(target, SPELL_FORKED_LIGHTNING);

                ForkedLightningTimer = 2000 + rand32() % 6000;
            } else ForkedLightningTimer -= diff;

            // EnchantedElementalTimer
            if (EnchantedElementalTimer <= diff)
            {
                me->SummonCreature(ENCHANTED_ELEMENTAL, ElementPos[EnchantedElementalPos][0], ElementPos[EnchantedElementalPos][1], ElementPos[EnchantedElementalPos][2], ElementPos[EnchantedElementalPos][3], TEMPSUMMON_CORPSE_DESPAWN);

                if (EnchantedElementalPos == 7)
                    EnchantedElementalPos = 0;
                else
                    ++EnchantedElementalPos;

                EnchantedElementalTimer = 10000 + rand32() % 5000;
            } else EnchantedElementalTimer -= diff;

            // TaintedElementalTimer
            if (TaintedElementalTimer <= diff)
            {
                uint32 pos = rand32() % 8;
                me->SummonCreature(TAINTED_ELEMENTAL, ElementPos[pos][0], ElementPos[pos][1], ElementPos[pos][2], ElementPos[pos][3], TEMPSUMMON_DEAD_DESPAWN);

                TaintedElementalTimer = 120000;
            } else TaintedElementalTimer -= diff;

            // CoilfangEliteTimer
            if (CoilfangEliteTimer <= diff)
            {
                uint32 pos = rand32() % 3;
                Creature* coilfangElite = me->SummonCreature(COILFANG_ELITE, CoilfangElitePos[pos][0], CoilfangElitePos[pos][1], CoilfangElitePos[pos][2], CoilfangElitePos[pos][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5s);
                if (coilfangElite)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        coilfangElite->AI()->AttackStart(target);
                    else if (me->GetVictim())
                        coilfangElite->AI()->AttackStart(me->GetVictim());
                }
                CoilfangEliteTimer = 45000 + rand32() % 5000;
            } else CoilfangEliteTimer -= diff;

            // CoilfangStriderTimer
            if (CoilfangStriderTimer <= diff)
            {
                uint32 pos = rand32() % 3;
                if (Creature* CoilfangStrider = me->SummonCreature(COILFANG_STRIDER, CoilfangStriderPos[pos][0], CoilfangStriderPos[pos][1], CoilfangStriderPos[pos][2], CoilfangStriderPos[pos][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5s))
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        CoilfangStrider->AI()->AttackStart(target);
                    else if (me->GetVictim())
                        CoilfangStrider->AI()->AttackStart(me->GetVictim());
                }
                CoilfangStriderTimer = 60000 + rand32() % 10000;
            } else CoilfangStriderTimer -= diff;

            // CheckTimer
            if (CheckTimer <= diff)
            {
                // Start Phase 3
                if (instance->GetData(DATA_CANSTARTPHASE3))
                {
                    // set life 50%
                    me->SetHealth(me->CountPctFromMaxHealth(50));

                    me->RemoveAurasDueToSpell(SPELL_MAGIC_BARRIER);

                    me->SetCanMelee(true);

                    Talk(SAY_PHASE3);

                    Phase = 3;

                    // return to the tank
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                }
                CheckTimer = 1000;
            } else CheckTimer -= diff;
        }
    }
};

// Enchanted Elemental
// If one of them reaches Vashj he will increase her damage done by 5%.
struct npc_enchanted_elemental : public ScriptedAI
{
    npc_enchanted_elemental(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        Move = 0;
        Phase = 1;

        X = ElementWPPos[0][0];
        Y = ElementWPPos[0][1];
        Z = ElementWPPos[0][2];
    }

    InstanceScript* instance;
    uint32 Move;
    uint32 Phase;
    float X, Y, Z;

    ObjectGuid VashjGUID;

    void Reset() override
    {
        me->SetSpeedRate(MOVE_WALK, 0.6f); // walk
        me->SetSpeedRate(MOVE_RUN, 0.6f); // run
        Initialize();

        //search for nearest waypoint (up on stairs)
        for (uint32 i = 1; i < 8; ++i)
        {
            if (me->GetDistance(ElementWPPos[i][0], ElementWPPos[i][1], ElementWPPos[i][2]) < me->GetDistance(X, Y, Z))
            {
                X = ElementWPPos[i][0];
                Y = ElementWPPos[i][1];
                Z = ElementWPPos[i][2];
            }
        }

        VashjGUID = instance->GetGuidData(DATA_LADYVASHJ);
    }

    void JustEngagedWith(Unit* /*who*/) override { }

    void MoveInLineOfSight(Unit* /*who*/) override { }

    void UpdateAI(uint32 diff) override
    {
        if (!VashjGUID)
            return;

        if (Move <= diff)
        {
            me->SetWalk(true);
            if (Phase == 1)
                me->GetMotionMaster()->MovePoint(0, X, Y, Z);
            if (Phase == 1 && me->IsWithinDist3d(X, Y, Z, 0.1f))
                Phase = 2;
            if (Phase == 2)
            {
                me->GetMotionMaster()->MovePoint(0, MIDDLE_X, MIDDLE_Y, MIDDLE_Z);
                Phase = 3;
            }
            if (Phase == 3)
            {
                me->GetMotionMaster()->MovePoint(0, MIDDLE_X, MIDDLE_Y, MIDDLE_Z);
                if (me->IsWithinDist3d(MIDDLE_X, MIDDLE_Y, MIDDLE_Z, 3))
                    DoCast(me, SPELL_SURGE);
            }
            if (Creature* vashj = ObjectAccessor::GetCreature(*me, VashjGUID))
                if (!vashj->IsInCombat() || ENSURE_AI(boss_lady_vashj, vashj->AI())->Phase != 2 || vashj->isDead())
                    me->KillSelf();
            Move = 1000;
        } else Move -= diff;
    }
};

// Tainted Elemental
// This mob has 7, 900 life, doesn't move, and shoots Poison Bolts at one person anywhere in the area, doing 3, 000 nature damage and placing a posion doing 2, 000 damage every 2 seconds. He will switch targets often, or sometimes just hang on a single player, but there is nothing you can do about it except heal the damage and kill the Tainted Elemental
struct npc_tainted_elemental : public ScriptedAI
{
    npc_tainted_elemental(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        PoisonBoltTimer = 5000 + rand32() % 5000;
        DespawnTimer = 30000;
    }

    InstanceScript* instance;

    uint32 PoisonBoltTimer;
    uint32 DespawnTimer;

    void Reset() override
    {
        Initialize();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* vashj = ObjectAccessor::GetCreature((*me), instance->GetGuidData(DATA_LADYVASHJ)))
            ENSURE_AI(boss_lady_vashj, vashj->AI())->EventTaintedElementalDeath();
    }

    void JustEngagedWith(Unit* who) override
    {
        AddThreat(who, 0.1f);
    }

    void UpdateAI(uint32 diff) override
    {
        // PoisonBoltTimer
        if (PoisonBoltTimer <= diff)
        {
            Unit* target = SelectTarget(SelectTargetMethod::Random, 0);

            if (target && target->IsWithinDistInMap(me, 30))
                DoCast(target, SPELL_POISON_BOLT);

            PoisonBoltTimer = 5000 + rand32() % 5000;
        } else PoisonBoltTimer -= diff;

        // DespawnTimer
        if (DespawnTimer <= diff)
        {
            // call Unsummon()
            me->setDeathState(DEAD);

            // to prevent crashes
            DespawnTimer = 1000;
        } else DespawnTimer -= diff;
    }
};

//Toxic Sporebat
//Toxic Spores: Used in Phase 3 by the Spore Bats, it creates a contaminated green patch of ground, dealing about 2775-3225 nature damage every second to anyone who stands in it.
struct npc_toxic_sporebat : public ScriptedAI
{
    npc_toxic_sporebat(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        MovementTimer = 0;
        ToxicSporeTimer = 5000;
        BoltTimer = 5500;
        CheckTimer = 1000;
    }

    InstanceScript* instance;

    uint32 MovementTimer;
    uint32 ToxicSporeTimer;
    uint32 BoltTimer;
    uint32 CheckTimer;

    void Reset() override
    {
        me->SetDisableGravity(true);
        me->SetFaction(FACTION_MONSTER);
        Initialize();
    }

    void MoveInLineOfSight(Unit* /*who*/) override
    {
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
            MovementTimer = 0;
    }

    void UpdateAI(uint32 diff) override
    {
        // Random movement
        if (MovementTimer <= diff)
        {
            uint32 rndpos = rand32() % 8;
            me->GetMotionMaster()->MovePoint(1, SporebatWPPos[rndpos][0], SporebatWPPos[rndpos][1], SporebatWPPos[rndpos][2]);
            MovementTimer = 6000;
        } else MovementTimer -= diff;

        // toxic spores
        if (BoltTimer <= diff)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            {
                if (Creature* trig = me->SummonCreature(TOXIC_SPORES_TRIGGER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 30s))
                {
                    trig->SetFaction(FACTION_MONSTER);
                    trig->CastSpell(trig, SPELL_TOXIC_SPORES, true);
                }
            }
            BoltTimer = 10000 + rand32() % 5000;
        }
        else BoltTimer -= diff;

        // CheckTimer
        if (CheckTimer <= diff)
        {
            // check if vashj is death
            Unit* Vashj = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_LADYVASHJ));
            if (!Vashj || !Vashj->IsAlive() || ENSURE_AI(boss_lady_vashj, Vashj->ToCreature()->AI())->Phase != 3)
            {
                // remove
                me->SetFaction(FACTION_FRIENDLY);
                me->DespawnOrUnsummon();
                return;
            }

            CheckTimer = 1000;
        }
        else
            CheckTimer -= diff;
    }
};

struct npc_shield_generator_channel : public ScriptedAI
{
    npc_shield_generator_channel(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        CheckTimer = 0;
        Cast = false;
    }

    InstanceScript* instance;
    uint32 CheckTimer;
    bool Cast;

    void Reset() override
    {
        Initialize();
        me->SetDisplayId(11686); // invisible
    }

    void MoveInLineOfSight(Unit* /*who*/) override { }

    void UpdateAI(uint32 diff) override
    {
        if (CheckTimer <= diff)
        {
            Unit* vashj = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_LADYVASHJ));

            if (vashj && vashj->IsAlive())
            {
                // start visual channel
                if (!Cast || !vashj->HasAura(SPELL_MAGIC_BARRIER))
                {
                    DoCast(vashj, SPELL_MAGIC_BARRIER, true);
                    Cast = true;
                }
            }
            CheckTimer = 1000;
        } else CheckTimer -= diff;
    }
};

class item_tainted_core : public ItemScript
{
public:
    item_tainted_core() : ItemScript("item_tainted_core") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& targets, ObjectGuid /*castId*/) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return true;

        Creature* vashj = ObjectAccessor::GetCreature((*player), instance->GetGuidData(DATA_LADYVASHJ));
        if (vashj && (ENSURE_AI(boss_lady_vashj, vashj->AI())->Phase == 2))
        {
            if (GameObject* gObj = targets.GetGOTarget())
            {
                uint32 identifier;
                uint8 channelIdentifier;
                switch (gObj->GetEntry())
                {
                    case 185052:
                        identifier = DATA_SHIELDGENERATOR1;
                        channelIdentifier = 0;
                        break;
                    case 185053:
                        identifier = DATA_SHIELDGENERATOR2;
                        channelIdentifier = 1;
                        break;
                    case 185051:
                        identifier = DATA_SHIELDGENERATOR3;
                        channelIdentifier = 2;
                        break;
                    case 185054:
                        identifier = DATA_SHIELDGENERATOR4;
                        channelIdentifier = 3;
                        break;
                    default:
                        return true;
                }

                if (instance->GetData(identifier))
                    return true;

                // get and remove channel
                if (Unit* channel = ObjectAccessor::GetCreature(*vashj, ENSURE_AI(boss_lady_vashj, vashj->AI())->ShieldGeneratorChannel[channelIdentifier]))
                    channel->setDeathState(JUST_DIED); // call Unsummon()

                instance->SetData(identifier, 1);

                // remove this item
                player->DestroyItemCount(31088, 1, true);
                return true;
            }
            else if (targets.GetUnitTarget()->GetTypeId() == TYPEID_UNIT)
                return false;
            else if (targets.GetUnitTarget()->GetTypeId() == TYPEID_PLAYER)
            {
                player->DestroyItemCount(31088, 1, true);
                player->CastSpell(targets.GetUnitTarget(), 38134, true);
                return true;
            }
        }
        return true;
    }

};

void AddSC_boss_lady_vashj()
{
    RegisterSerpentshrineCavernCreatureAI(boss_lady_vashj);
    RegisterSerpentshrineCavernCreatureAI(npc_enchanted_elemental);
    RegisterSerpentshrineCavernCreatureAI(npc_tainted_elemental);
    RegisterSerpentshrineCavernCreatureAI(npc_toxic_sporebat);
    RegisterSerpentshrineCavernCreatureAI(npc_shield_generator_channel);
    new item_tainted_core();
}

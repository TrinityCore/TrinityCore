/*
 * Copyright (c) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
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
#include "utgarde_pinnacle.h"

#define SPELL_POISONED_SPEAR    DUNGEON_MODE(50255, 59331)

static Position SpawnLoc = { 468.931f, -513.555f, 104.723f, 0 };
static Position Location[] =
{
    // Boss
    {341.740997f, -516.955017f, 104.66900f, 0}, // 0
    {293.299f, -505.95f, 142.03f, 0},           // 1
    {301.664f, -535.164f, 146.097f, 0},         // 2
    {521.031006f, -544.667847f, 128.80064f, 0}, // 3
    {477.311981f, -509.296814f, 104.72308f, 0}, // 4
    {341.740997f, -516.955017f, 104.66900f, 0}, // 5
    {341.740997f, -516.955017f, 104.66900f, 0}, // 6
    {341.740997f, -516.955017f, 104.66900f, 0}, // 7
    // Triggers Left
    {469.661f, -484.546f, 104.712f, 0},         // 8
    {483.315f, -485.028f, 104.718f, 0},         // 9
    {476.87f, -487.994f, 104.735f, 0},          //10
    {477.512f, -497.772f, 104.728f, 0},         //11
    {486.287f, -500.759f, 104.722f, 0},         //12
    {480.1f, -503.895f, 104.722f, 0},           //13
    {472.391f, -505.103f, 104.723f, 0},         //14
    {478.885f, -510.803f, 104.723f, 0},         //15
    {489.529f, -508.615f, 104.723f, 0},         //16
    {484.272f, -508.589f, 104.723f, 0},         //17
    {465.328f, -506.495f, 104.427f, 0},         //18
    {456.885f, -508.104f, 104.447f, 0},         //19
    {450.177f, -507.989f, 105.247f, 0},         //20
    {442.273f, -508.029f, 104.813f, 0},         //21
    {434.225f, -508.19f, 104.787f, 0},          //22
    {423.902f, -508.525f, 104.274f, 0},         //23
    {414.551f, -508.645f, 105.136f, 0},         //24
    {405.787f, -508.755f, 104.988f, 0},         //25
    {398.812f, -507.224f, 104.82f, 0},          //26
    {389.702f, -506.846f, 104.729f, 0},         //27
    {381.856f, -506.76f, 104.756f, 0},          //28
    {372.881f, -507.254f, 104.779f, 0},         //29
    {364.978f, -508.182f, 104.673f, 0},         //30
    {357.633f, -508.075f, 104.647f, 0},         //31
    {350.008f, -506.826f, 104.588f, 0},         //32
    {341.69f, -506.77f, 104.499f, 0},           //33
    {335.31f, -505.745f, 105.18f, 0},           //34
    {471.178f, -510.74f, 104.723f, 0},          //35
    {461.759f, -510.365f, 104.199f, 0},         //36
    {424.07287f, -510.082916f, 104.711082f, 0}, //37
    // Triggers Right
    {489.46f, -513.297f, 105.413f, 0},          //38
    {485.706f, -517.175f, 104.724f, 0},         //39
    {480.98f, -519.313f, 104.724f, 0},          //40
    {475.05f, -520.52f, 104.724f, 0},           //41
    {482.97f, -512.099f, 104.724f, 0},          //42
    {477.082f, -514.172f, 104.724f, 0},         //43
    {468.991f, -516.691f, 104.724f, 0},         //44
    {461.722f, -517.063f, 104.627f, 0},         //45
    {455.88f, -517.681f, 104.707f, 0},          //46
    {450.499f, -519.099f, 104.701f, 0},         //47
    {444.889f, -518.963f, 104.82f, 0},          //48
    {440.181f, -518.893f, 104.861f, 0},         //49
    {434.393f, -518.758f, 104.891f, 0},         //50
    {429.328f, -518.583f, 104.904f, 0},         //51
    {423.844f, -518.394f, 105.004f, 0},         //52
    {418.707f, -518.266f, 105.135f, 0},         //53
    {413.377f, -518.085f, 105.153f, 0},         //54
    {407.277f, -517.844f, 104.893f, 0},         //55
    {401.082f, -517.443f, 104.723f, 0},         //56
    {394.933f, -514.64f, 104.724f, 0},          //57
    {388.917f, -514.688f, 104.734f, 0},         //58
    {383.814f, -515.834f, 104.73f, 0},          //59
    {377.887f, -518.653f, 104.777f, 0},         //60
    {371.376f, -518.289f, 104.781f, 0},         //61
    {365.669f, -517.822f, 104.758f, 0},         //62
    {359.572f, -517.314f, 104.706f, 0},         //63
    {353.632f, -517.146f, 104.647f, 0},         //64
    {347.998f, -517.038f, 104.538f, 0},         //65
    {341.803f, -516.98f, 104.584f, 0},          //66
    {335.879f, -516.674f, 104.628f, 0},         //67
    {329.871f, -515.92f, 104.711f, 0},          //68
    // Breach Zone
    {485.4577f, -511.2515f, 115.3011f, 0},      //69
    {435.1892f, -514.5232f, 118.6719f, 0},      //70
    {413.9327f, -540.9407f, 138.2614f, 0},      //71
};

enum eYells
{
    SAY_AGGRO           = -1575004,
    SAY_KILL_1          = -1575005,
    SAY_KILL_2          = -1575006,
    EMOTE_RANGE         = -1575007, // Skadi
    SAY_DEATH           = -1575008,
    SAY_DRAKE_DEATH     = -1575009,
    EMOTE_BREATH        = -1575010, // Grauf
    SAY_DRAKE_BREATH_1  = -1575011,
    SAY_DRAKE_BREATH_2  = -1575012,
    SAY_DRAKE_BREATH_3  = -1575013
};

enum eCombatPhase
{
    FLYING,
    SKADI
};

enum eSpells
{
    SPELL_CRUSH                 = 50234,
    SPELL_WHIRLWIND             = 50228,
    SPELL_RAPID_FIRE            = 56570,
    SPELL_HARPOON_DAMAGE        = 56578,
    SPELL_FREEZING_CLOUD        = 47579,
    SPELL_HARPUNE_ERSCHAFFEN    = 56790
};

enum eCreature
{
    CREATURE_YMIRJAR_WARRIOR        = 26690,
    CREATURE_YMIRJAR_WITCH_DOCTOR   = 26691,
    CREATURE_YMIRJAR_HARPOONER      = 26692,
    CREATURE_TRIGGER                = 28351,
    CREATURE_GRAUF_DISPLAY_ID       = 27043
};

enum eAchievments
{
    ACHIEV_TIMED_START_EVENT = 17726
};

class boss_skadi : public CreatureScript
{
public:
    boss_skadi() : CreatureScript("boss_skadi") { }

    struct boss_skadiAI : public ScriptedAI
    {
        boss_skadiAI(Creature * c) : ScriptedAI(c), Summons(me)
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            TriggerGUIDs.clear();

            CrushTimer = 8000;
            PoisonedSpearTimer = 10000;
            WhirlwindTimer = 20000;
            MountTimer = 3000;
            WaypointId = 0;
            SaidEmote = false;
            SpellHitCount = 0;

            Phase = SKADI;

            Summons.DespawnAll();

            me->SetSpeed(MOVE_FLIGHT, 3.0f);

            if (instance)
            {
                if (!me->IsMounted())
                {
                    me->SetFlying(false);
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);

                    if (Creature * grauf = me->GetMap()->GetCreature(instance->GetData64(DATA_MOB_GRAUF)))
                    {
                        if (!grauf->isAlive())
                            grauf->Respawn(true);
                    }
                    else
                        me->SummonCreature(MOB_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);

                }
                instance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, NOT_STARTED);
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }
        }

        void DamageTaken(Unit * /*attacker*/, uint32 & damage)
        {
            if (!me->isInCombat() || Phase != SKADI || me->IsMounted())
                damage = 0;
        }

        void JustReachedHome()
        {
            me->Unmount();
            me->SetFlying(false);
            me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

            if (instance)
            {
                if (Creature * grauf = me->GetMap()->GetCreature(instance->GetData64(DATA_MOB_GRAUF)))
                {
                    if (!grauf->isAlive())
                        grauf->Respawn(true);
                }
                else
                    me->SummonCreature(MOB_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
            }
            me->UpdateObjectVisibility(true);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

            Phase = FLYING;

            MovementTimer = 1000;
            SummonTimer = 10000;

            DoZoneInCombat();

            if (instance)
            {
                instance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, IN_PROGRESS);
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);

                me->GetMotionMaster()->MoveJump(Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 5.0f, 10.0f);
                MountTimer = 1000;
                Summons.DespawnEntry(MOB_GRAUF);
            }
        }

        void JustSummoned(Creature * summoned)
        {
            switch (summoned->GetEntry())
            {
                case CREATURE_YMIRJAR_WARRIOR:
                case CREATURE_YMIRJAR_WITCH_DOCTOR:
                case CREATURE_YMIRJAR_HARPOONER:
                    summoned->setActive(true);
                    summoned->SetInCombatWithZone();
                    if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summoned->AI()->AttackStart(target);
                    break;
                case CREATURE_TRIGGER:
                    summoned->CastSpell((Unit*)NULL, SPELL_FREEZING_CLOUD, true);
                    summoned->ForcedDespawn(10*IN_MILLISECONDS);
                    break;
            }
            Summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature * summoned)
        {
            Summons.Despawn(summoned);
        }

        void SpellHit(Unit * /*caster*/, const SpellInfo * spell)
        {
            if (spell->Id == SPELL_HARPOON_DAMAGE)
            {
                ++SpellHitCount;

                if (SpellHitCount >= 3)
                {
                    Phase = SKADI;

                    me->Unmount();
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                    if (Creature* grauf = me->SummonCreature(MOB_GRAUF, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3 * IN_MILLISECONDS))
                    {
                        grauf->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                        grauf->GetMotionMaster()->MoveFall(0);
                        grauf->SetTimeUntilDisappear(SEKUNDEN_10);

                        DoScriptText(SAY_DRAKE_DEATH, me);
                    }
                    me->SetFlying(false);
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MoveJump(Location[4].GetPositionX(), Location[4].GetPositionY(), Location[4].GetPositionZ(), 5.0f, 10.0f);
                    me->SetHealth(me->GetMaxHealth());
                    me->UpdateObjectVisibility(true);

                    if (Unit * target = me->SelectNearestPlayer())
                        AttackStart(target);

                    CrushTimer = 8000;
                    PoisonedSpearTimer = 10000;
                    WhirlwindTimer = 20000;
                }
            }
        }

        void JustDied(Unit * /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            Summons.DespawnAll();

            if (instance)
                instance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, DONE);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
        }

        void SpawnMobs()
        {
            for (uint8 i=0; i<DUNGEON_MODE(5, 6); ++i)
                switch (urand(0, 2))
                {
                    case 0: me->SummonCreature(CREATURE_YMIRJAR_WARRIOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                    case 1: me->SummonCreature(CREATURE_YMIRJAR_WITCH_DOCTOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                    case 2: me->SummonCreature(CREATURE_YMIRJAR_HARPOONER, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                }
        }

        void SpawnTrigger()
        {
            uint8 iStart = 0;
            uint8 iEnd = 0;

            switch (urand(0, 1))
            {
                case 0:
                    iStart = 8;
                    iEnd = 37;
                    break;
                case 1:
                    iStart = 38;
                    iEnd = 68;
                    break;
                default:
                    break;
            }
            for (uint32 i=iStart; i<iEnd; ++i)
                if (Creature * cr = me->SummonCreature(CREATURE_TRIGGER, Location[i], TEMPSUMMON_TIMED_DESPAWN, 5 * IN_MILLISECONDS))
                {
                    cr->SetVisible(false);
                    cr->setFaction(35);
                }
        }

        void UpdateAI(const uint32 diff)
        {
            switch(Phase)
            {
                case FLYING:
                    if (!UpdateVictim())
                        return;

                    if (me->GetPositionX() >= 519)
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        if (!SaidEmote)
                        {
                            DoScriptText(EMOTE_RANGE, me);
                            SaidEmote = true;
                        }
                    }
                    else
                    {
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        SaidEmote = false;
                    }

                    if (MountTimer && MountTimer <= diff)
                    {
                        me->Mount(CREATURE_GRAUF_DISPLAY_ID);
                        MountTimer = 0;
                    } else MountTimer -= diff;

                    if (SummonTimer <= diff)
                    {
                        SpawnMobs();
                        SummonTimer = 25000;
                    } else SummonTimer -= diff;

                    if (MovementTimer <= diff)
                    {
                        switch(WaypointId)
                        {
                            case 0:
                                me->GetMotionMaster()->MovePoint(0, Location[1].GetPositionX(), Location[1].GetPositionY(), Location[1].GetPositionZ());
                                MovementTimer = 5000;
                                break;
                            case 1:
                                me->GetMotionMaster()->MovePoint(0, Location[2].GetPositionX(), Location[2].GetPositionY(), Location[2].GetPositionZ());
                                MovementTimer = 2000;
                                break;
                            case 2:
                                me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                                MovementTimer = 15000;
                                break;
                            case 3:
                                me->GetMotionMaster()->MovePoint(0, Location[69].GetPositionX(), Location[69].GetPositionY(), Location[69].GetPositionZ());
                                DoScriptText(RAND(SAY_DRAKE_BREATH_1, SAY_DRAKE_BREATH_2), me);
                                DoScriptText(EMOTE_BREATH, me);
                                MovementTimer = 2500;
                                break;
                            case 4:
                                me->GetMotionMaster()->MovePoint(0, Location[70].GetPositionX(), Location[70].GetPositionY(), Location[70].GetPositionZ());
                                MovementTimer = 2000;
                                SpawnTrigger();
                                break;
                            case 5:
                                me->GetMotionMaster()->MovePoint(0, Location[71].GetPositionX(), Location[71].GetPositionY(), Location[71].GetPositionZ());
                                MovementTimer = 3000;
                                break;
                            case 6:
                                me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                                WaypointId = 2;
                                MovementTimer = 15000;
                                break;
                        }
                        ++WaypointId;
                    } else MovementTimer -= diff;
                    break;
                case SKADI:
                    if (!UpdateVictim())
                        return;

                    if (me->HasUnitState(UNIT_STAT_CASTING))
                        return;

                    if (CrushTimer <= diff)
                    {
                        DoCastVictim(SPELL_CRUSH);
                        CrushTimer = 8000;
                    } else CrushTimer -= diff;

                    if (PoisonedSpearTimer <= diff)
                    {
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_POISONED_SPEAR);

                        PoisonedSpearTimer = SEKUNDEN_10;
                    } else PoisonedSpearTimer -= diff;

                    if (WhirlwindTimer <= diff)
                    {
                        DoCastAOE(SPELL_WHIRLWIND);
                        WhirlwindTimer = SEKUNDEN_20;
                    } else WhirlwindTimer -= diff;

                    DoMeleeAttackIfReady();
                    break;
            }
        }
    private:
        InstanceScript * instance;
        SummonList Summons;
        eCombatPhase Phase;
        std::vector<uint64> TriggerGUIDs;

        uint32 CrushTimer;
        uint32 PoisonedSpearTimer;
        uint32 WhirlwindTimer;
        uint32 WaypointId;
        uint32 MovementTimer;
        uint32 MountTimer;
        uint32 SummonTimer;
        uint8 SpellHitCount;
        bool SaidEmote;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new boss_skadiAI(creature);
    }
};

class go_harpoon_launcher : public GameObjectScript
{
public:
    go_harpoon_launcher() : GameObjectScript("go_harpoon_launcher") { }

    bool OnGossipHello(Player * player, GameObject * pGO)
    {
        InstanceScript * instance = pGO->GetInstanceScript();
        if (!instance)
            return false;

        if (Creature * skadi = pGO->GetMap()->GetCreature(instance->GetData64(DATA_SKADI_THE_RUTHLESS)))
            player->CastSpell(skadi, SPELL_RAPID_FIRE, true);

        return false;
    }
};

class go_skadi_harpune : public GameObjectScript
{
public:
    go_skadi_harpune() : GameObjectScript("go_skadi_harpune") { }

    bool OnGossipHello(Player * player, GameObject * /*pGO*/)
    {
        if (!player || !player->isValid())
            return false;

        player->CastSpell(player, SPELL_HARPUNE_ERSCHAFFEN, true);
        return false;
    }
};

void AddSC_boss_skadi()
{
    new boss_skadi();
    new go_harpoon_launcher();
    new go_skadi_harpune();
}

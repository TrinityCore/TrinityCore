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

/* Script Data Start
SDName: Boss_Skadi
SDAuthor: LordVanMartin, JohnHoliver
SD%Complete: 90%
SDComment: <Known Bugs>
               After Unmount() he appears to still be flying even with SetFlying(false)
           </Known Bugs>
SDCategory: Utgarde Pinnacle
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "utgarde_pinnacle.h"
#include "Player.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_AGGRO                           = 0,
    SAY_KILL                            = 1,
    EMOTE_RANGE                         = 2,
    SAY_DEATH                           = 3,
    SAY_DRAKE_DEATH                     = 4,
    EMOTE_BREATH                        = 5,
    SAY_DRAKE_BREATH                    = 6
};

static Position SpawnLoc = {468.931f, -513.555f, 104.723f, 0};
static Position Location[]=
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

enum CombatPhase
{
    FLYING,
    SKADI
};

enum Spells
{
    // Skadi Spells
    SPELL_CRUSH             = 50234,
    SPELL_POISONED_SPEAR    = 50225, //isn't being cast
    SPELL_WHIRLWIND         = 50228, //random target, but not the tank approx. every 20s
    SPELL_RAPID_FIRE        = 56570,
    SPELL_HARPOON_DAMAGE    = 56578,
    SPELL_FREEZING_CLOUD    = 47579,
};

enum Creatures
{
    NPC_YMIRJAR_WARRIOR       = 26690,
    NPC_YMIRJAR_WITCH_DOCTOR  = 26691,
    NPC_YMIRJAR_HARPOONER     = 26692,
    NPC_GRAUF                 = 26893,
    NPC_TRIGGER               = 28351,
    DATA_MOUNT                     = 27043,
};

enum Achievments
{
    ACHIEV_TIMED_START_EVENT                      = 17726,
};

class boss_skadi : public CreatureScript
{
public:
    boss_skadi() : CreatureScript("boss_skadi") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_skadiAI>(creature);
    }

    struct boss_skadiAI : public ScriptedAI
    {
        boss_skadiAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
            m_uiGraufGUID = 0;
        }

        InstanceScript* instance;
        SummonList Summons;
        uint64 m_uiGraufGUID;
        std::vector<uint64> triggersGUID;

        uint32 m_uiCrushTimer;
        uint32 m_uiPoisonedSpearTimer;
        uint32 m_uiWhirlwindTimer;
        uint32 m_uiWaypointId;
        uint32 m_uiMovementTimer;
        uint32 m_uiMountTimer;
        uint32 m_uiSummonTimer;
        uint8  m_uiSpellHitCount;
        bool   m_bSaidEmote;

        CombatPhase Phase;

        void Reset() OVERRIDE
        {
            triggersGUID.clear();

            m_uiCrushTimer = 8000;
            m_uiPoisonedSpearTimer = 10000;
            m_uiWhirlwindTimer = 20000;
            m_uiMountTimer = 3000;
            m_uiWaypointId = 0;
            m_bSaidEmote = false;
            m_uiSpellHitCount = 0;

            Phase = SKADI;

            Summons.DespawnAll();
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
            if ((Unit::GetCreature(*me, m_uiGraufGUID) == NULL) && !me->IsMounted())
                 me->SummonCreature(NPC_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
            instance->SetBossState(DATA_SKADI_THE_RUTHLESS, NOT_STARTED);
            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void JustReachedHome() OVERRIDE
        {
            me->SetCanFly(false);
            me->Dismount();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            if (!Unit::GetCreature(*me, m_uiGraufGUID))
                me->SummonCreature(NPC_GRAUF, Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 3.0f);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

            Phase = FLYING;

            m_uiMovementTimer = 1000;
            m_uiSummonTimer = 10000;
            me->SetInCombatWithZone();
            instance->SetBossState(DATA_SKADI_THE_RUTHLESS, IN_PROGRESS);
            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            me->GetMotionMaster()->MoveJump(Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 5.0f, 10.0f);
            me->SetWalk(false);
            m_uiMountTimer = 1000;
            Summons.DespawnEntry(NPC_GRAUF);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            switch (summoned->GetEntry())
            {
                case NPC_GRAUF:
                    m_uiGraufGUID = summoned->GetGUID();
                    break;
                case NPC_YMIRJAR_WARRIOR:
                case NPC_YMIRJAR_WITCH_DOCTOR:
                case NPC_YMIRJAR_HARPOONER:
                    summoned->setActive(true);
                    summoned->SetInCombatWithZone();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summoned->AI()->AttackStart(target);
                    break;
                case NPC_TRIGGER:
                    summoned->CastSpell((Unit*)NULL, SPELL_FREEZING_CLOUD, true);
                    summoned->DespawnOrUnsummon(10*IN_MILLISECONDS);
                    break;
            }
            Summons.Summon(summoned);
        }

        void SummonedCreatureDespawn(Creature* summoned) OVERRIDE
        {
            if (summoned->GetEntry() == NPC_GRAUF)
                m_uiGraufGUID = 0;
            Summons.Despawn(summoned);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) OVERRIDE
        {
            if (spell->Id == SPELL_HARPOON_DAMAGE)
            {
                m_uiSpellHitCount++;
                if (m_uiSpellHitCount >= 3)
                {
                    Phase = SKADI;
                    me->SetCanFly(false);
                    me->Dismount();
                    if (Creature* pGrauf = me->SummonCreature(NPC_GRAUF, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS))
                    {
                        pGrauf->GetMotionMaster()->MoveFall();
                        pGrauf->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                    }
                    me->GetMotionMaster()->MoveJump(Location[4].GetPositionX(), Location[4].GetPositionY(), Location[4].GetPositionZ(), 5.0f, 10.0f);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    Talk(SAY_DRAKE_DEATH);
                    m_uiCrushTimer = 8000;
                    m_uiPoisonedSpearTimer = 10000;
                    m_uiWhirlwindTimer = 20000;
                    me->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
                }
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            switch (Phase)
            {
                case FLYING:
                    if (!UpdateVictim())
                        return;

                    if (me->GetPositionX() >= 519)
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        if (!m_bSaidEmote)
                        {
                            Talk(EMOTE_RANGE);
                            m_bSaidEmote = true;
                        }
                    }
                    else
                    {
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        m_bSaidEmote = false;
                    }

                    if (m_uiMountTimer && m_uiMountTimer <= diff)
                    {
                        me->Mount(DATA_MOUNT);
                        me->SetCanFly(true);
                        m_uiMountTimer = 0;
                    } else m_uiMountTimer -= diff;

                    if (m_uiSummonTimer <= diff)
                    {
                        SpawnMobs();
                        m_uiSummonTimer = 25000;
                    } else m_uiSummonTimer -= diff;

                    if (m_uiMovementTimer <= diff)
                    {
                        switch (m_uiWaypointId)
                        {
                            case 0:
                                me->GetMotionMaster()->MovePoint(0, Location[1].GetPositionX(), Location[1].GetPositionY(), Location[1].GetPositionZ());
                                m_uiMovementTimer = 5000;
                                break;
                            case 1:
                                me->GetMotionMaster()->MovePoint(0, Location[2].GetPositionX(), Location[2].GetPositionY(), Location[2].GetPositionZ());
                                m_uiMovementTimer = 2000;
                                break;
                            case 2:
                                me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                                m_uiMovementTimer = 15000;
                                break;
                            case 3:
                                me->GetMotionMaster()->MovePoint(0, Location[69].GetPositionX(), Location[69].GetPositionY(), Location[69].GetPositionZ());
                                Talk(SAY_DRAKE_BREATH);
                                Talk(EMOTE_BREATH);
                                m_uiMovementTimer = 2500;
                                break;
                            case 4:
                                me->GetMotionMaster()->MovePoint(0, Location[70].GetPositionX(), Location[70].GetPositionY(), Location[70].GetPositionZ());
                                m_uiMovementTimer = 2000;
                                SpawnTrigger();
                                break;
                            case 5:
                                me->GetMotionMaster()->MovePoint(0, Location[71].GetPositionX(), Location[71].GetPositionY(), Location[71].GetPositionZ());
                                m_uiMovementTimer = 3000;
                                break;
                            case 6:
                                me->GetMotionMaster()->MovePoint(0, Location[3].GetPositionX(), Location[3].GetPositionY(), Location[3].GetPositionZ());
                                m_uiWaypointId = 2;
                                m_uiMovementTimer = 15000;
                                break;
                        }
                        m_uiWaypointId++;
                    } else m_uiMovementTimer -= diff;
                    break;
                case SKADI:
                    //Return since we have no target
                    if (!UpdateVictim())
                        return;

                    if (m_uiCrushTimer <= diff)
                    {
                        DoCastVictim(SPELL_CRUSH);
                        m_uiCrushTimer = 8000;
                    } else m_uiCrushTimer -= diff;

                    if (m_uiPoisonedSpearTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_POISONED_SPEAR);
                        m_uiPoisonedSpearTimer = 10000;
                    } else m_uiPoisonedSpearTimer -= diff;

                    if (m_uiWhirlwindTimer <= diff)
                    {
                        DoCastAOE(SPELL_WHIRLWIND);
                        m_uiWhirlwindTimer = 20000;
                    } else m_uiWhirlwindTimer -= diff;

                    DoMeleeAttackIfReady();
                    break;
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);
            Summons.DespawnAll();
            instance->SetBossState(DATA_SKADI_THE_RUTHLESS, DONE);
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void SpawnMobs()
        {
            for (uint8 i = 0; i < DUNGEON_MODE(5, 6); ++i)
            {
                switch (urand(0, 2))
                {
                    case 0:
                        me->SummonCreature(NPC_YMIRJAR_WARRIOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        break;

                    case 1:
                        me->SummonCreature(NPC_YMIRJAR_WITCH_DOCTOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        break;

                    case 2:
                        me->SummonCreature(NPC_YMIRJAR_HARPOONER, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        break;
                }
            }
        }

        void SpawnTrigger()
        {
            uint8 iStart = 0, iEnd = 0;
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
            for (uint32 i = iStart; i < iEnd; ++i)
                me->SummonCreature(NPC_TRIGGER, Location[i]);
        }
    };

};

class go_harpoon_launcher : public GameObjectScript
{
public:
    go_harpoon_launcher() : GameObjectScript("go_harpoon_launcher") { }

    bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
    {
        InstanceScript* instance = go->GetInstanceScript();
        if (!instance)
            return false;

        if (Creature* pSkadi = Unit::GetCreature(*go, instance->GetData64(DATA_SKADI_THE_RUTHLESS)))
            player->CastSpell(pSkadi, SPELL_RAPID_FIRE, true);

        return false;
    }

};

void AddSC_boss_skadi()
{
    new boss_skadi();
    new go_harpoon_launcher();
}

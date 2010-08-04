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

/* Script Data Start
SDName: Boss_Skadi
SDAuthor: LordVanMartin, JohnHoliver
SD%Complete: 90%
SDComment: <Known Bugs>
               After Unmount() he appears to still be flying even with SetFlying(false)
           </Known Bugs>
SDCategory: Utgarde Pinnacle
Script Data End */

#include "ScriptPCH.h"
#include "utgarde_pinnacle.h"

//Yell
enum eYells
{
    SAY_AGGRO                           = -1575004,
    SAY_KILL_1                          = -1575005,
    SAY_KILL_2                          = -1575006,
    EMOTE_RANGE                         = -1575007, //Skadi
    SAY_DEATH                           = -1575008,
    SAY_DRAKE_DEATH                     = -1575009,
    EMOTE_BREATH                        = -1575010, //Grauf
    SAY_DRAKE_BREATH_1                  = -1575011,
    SAY_DRAKE_BREATH_2                  = -1575012,
    SAY_DRAKE_BREATH_3                  = -1575013,
};

static Position SpawnLoc = {468.931, -513.555, 104.723};
static Position Location[]=
{
    // Boss
    {341.740997, -516.955017, 104.66900}, // 0
    {293.299, -505.95, 142.03},           // 1
    {301.664, -535.164, 146.097},         // 2
    {521.031006, -544.667847, 128.80064}, // 3
    {477.311981, -509.296814, 104.72308}, // 4
    {341.740997, -516.955017, 104.66900}, // 5
    {341.740997, -516.955017, 104.66900}, // 6
    {341.740997, -516.955017, 104.66900}, // 7
    // Triggers Left
    {469.661, -484.546, 104.712},         // 8
    {483.315, -485.028, 104.718},         // 9
    {476.87, -487.994, 104.735},          //10
    {477.512, -497.772, 104.728},         //11
    {486.287, -500.759, 104.722},         //12
    {480.1, -503.895, 104.722},           //13
    {472.391, -505.103, 104.723},         //14
    {478.885, -510.803, 104.723},         //15
    {489.529, -508.615, 104.723},         //16
    {484.272, -508.589, 104.723},         //17
    {465.328, -506.495, 104.427},         //18
    {456.885, -508.104, 104.447},         //19
    {450.177, -507.989, 105.247},         //20
    {442.273, -508.029, 104.813},         //21
    {434.225, -508.19, 104.787},          //22
    {423.902, -508.525, 104.274},         //23
    {414.551, -508.645, 105.136},         //24
    {405.787, -508.755, 104.988},         //25
    {398.812, -507.224, 104.82},          //26
    {389.702, -506.846, 104.729},         //27
    {381.856, -506.76, 104.756},          //28
    {372.881, -507.254, 104.779},         //29
    {364.978, -508.182, 104.673},         //30
    {357.633, -508.075, 104.647},         //31
    {350.008, -506.826, 104.588},         //32
    {341.69, -506.77, 104.499},           //33
    {335.31, -505.745, 105.18},           //34
    {471.178, -510.74, 104.723},          //35
    {461.759, -510.365, 104.199},         //36
    {424.07287, -510.082916, 104.711082}, //37
    // Triggers Right
    {489.46, -513.297, 105.413},          //38
    {485.706, -517.175, 104.724},         //39
    {480.98, -519.313, 104.724},          //40
    {475.05, -520.52, 104.724},           //41
    {482.97, -512.099, 104.724},          //42
    {477.082, -514.172, 104.724},         //43
    {468.991, -516.691, 104.724},         //44
    {461.722, -517.063, 104.627},         //45
    {455.88, -517.681, 104.707},          //46
    {450.499, -519.099, 104.701},         //47
    {444.889, -518.963, 104.82},          //48
    {440.181, -518.893, 104.861},         //49
    {434.393, -518.758, 104.891},         //50
    {429.328, -518.583, 104.904},         //51
    {423.844, -518.394, 105.004},         //52
    {418.707, -518.266, 105.135},         //53
    {413.377, -518.085, 105.153},         //54
    {407.277, -517.844, 104.893},         //55
    {401.082, -517.443, 104.723},         //56
    {394.933, -514.64, 104.724},          //57
    {388.917, -514.688, 104.734},         //58
    {383.814, -515.834, 104.73},          //59
    {377.887, -518.653, 104.777},         //60
    {371.376, -518.289, 104.781},         //61
    {365.669, -517.822, 104.758},         //62
    {359.572, -517.314, 104.706},         //63
    {353.632, -517.146, 104.647},         //64
    {347.998, -517.038, 104.538},         //65
    {341.803, -516.98, 104.584},          //66
    {335.879, -516.674, 104.628},         //67
    {329.871, -515.92, 104.711},          //68
    // Breach Zone
    {485.4577, -511.2515, 115.3011},      //69
    {435.1892, -514.5232, 118.6719},      //70
    {413.9327, -540.9407, 138.2614},      //71
};

enum eCombatPhase
{
    FLYING,
    SKADI
};

enum eSpells
{
    //Skadi Spells
    SPELL_CRUSH             = 50234,
    SPELL_POISONED_SPEAR    = 50225, //isn't being casted =/
    SPELL_WHIRLWIND         = 50228, //random target, but not the tank approx. every 20s
    SPELL_RAPID_FIRE        = 56570,
    SPELL_HARPOON_DAMAGE    = 56578,
    SPELL_FREEZING_CLOUD    = 47579,
};

enum eCreature
{
    CREATURE_YMIRJAR_WARRIOR       = 26690,
    CREATURE_YMIRJAR_WITCH_DOCTOR  = 26691,
    CREATURE_YMIRJAR_HARPOONER     = 26692,
    CREATURE_GRAUF                 = 26893,
    CREATURE_TRIGGER               = 28351,
    DATA_MOUNT                     = 27043,
};

enum eAchievments
{
    ACHIEV_TIMED_START_EVENT                      = 17726,
};

struct boss_skadiAI : public ScriptedAI
{
    boss_skadiAI(Creature *c) : ScriptedAI(c), Summons(me)
    {
        m_pInstance = c->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;
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

    eCombatPhase Phase;

    void Reset()
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
        if ((Unit::GetCreature((*me), m_uiGraufGUID) == NULL) && !me->IsMounted())
             me->SummonCreature(CREATURE_GRAUF,Location[0].GetPositionX(),Location[0].GetPositionY(),Location[0].GetPositionZ(),3.0f);
        if (m_pInstance)
        {
            m_pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, NOT_STARTED);
            m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
    }

    void JustReachedHome()
    {
        me->SetFlying(false);
        me->Unmount();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        if (Unit::GetCreature((*me), m_uiGraufGUID) == NULL)
            me->SummonCreature(CREATURE_GRAUF,Location[0].GetPositionX(),Location[0].GetPositionY(),Location[0].GetPositionZ(),3.0f);
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

        Phase = FLYING;

        m_uiMovementTimer = 1000;
        m_uiSummonTimer = 10000;
        me->SetInCombatWithZone();
        if (m_pInstance)
        {
            m_pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, IN_PROGRESS);
            m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            me->GetMotionMaster()->MoveJump(Location[0].GetPositionX(), Location[0].GetPositionY(), Location[0].GetPositionZ(), 5.0f, 10.0f);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            m_uiMountTimer = 1000;
            Summons.DespawnEntry(CREATURE_GRAUF);
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        switch (pSummoned->GetEntry())
        {
            case CREATURE_GRAUF:
                m_uiGraufGUID = pSummoned->GetGUID();
                break;
            case CREATURE_YMIRJAR_WARRIOR:
            case CREATURE_YMIRJAR_WITCH_DOCTOR:
            case CREATURE_YMIRJAR_HARPOONER:
                pSummoned->setActive(true);
                pSummoned->SetInCombatWithZone();
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    pSummoned->AI()->AttackStart(pTarget);
                break;
            case CREATURE_TRIGGER:
                pSummoned->CastSpell((Unit*)NULL, SPELL_FREEZING_CLOUD, true);
                pSummoned->ForcedDespawn(10*IN_MILLISECONDS);
                break;
        }
        Summons.Summon(pSummoned);
    }

    void SummonedCreatureDespawn(Creature* pSummoned) 
    {
        if (pSummoned->GetEntry() == CREATURE_GRAUF)
            m_uiGraufGUID = 0;
        Summons.Despawn(pSummoned);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_HARPOON_DAMAGE)
        {
            m_uiSpellHitCount++;
            if (m_uiSpellHitCount >= 5)
            {
                Phase = SKADI;
                me->SetFlying(false);
                me->Unmount();
                if(Creature* pGrauf = me->SummonCreature(CREATURE_GRAUF, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS))
                {
                    pGrauf->GetMotionMaster()->MoveFall(0);
                    pGrauf->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                }
                sLog.outBasic("[Skadi] Fly off");
                me->GetMotionMaster()->MoveJump(Location[4].GetPositionX(), Location[4].GetPositionY(), Location[4].GetPositionZ(), 5.0f, 10.0f);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                DoScriptText(SAY_DRAKE_DEATH, me);
                m_uiCrushTimer = 8000;
                m_uiPoisonedSpearTimer = 10000;
                m_uiWhirlwindTimer = 20000;
                me->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
            }
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
                    if (!m_bSaidEmote)
                    {
                        DoScriptText(EMOTE_RANGE, me);
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
                    me->SetFlying(true);
                    m_uiMountTimer = 0;
                } else m_uiMountTimer -= diff;
                
                if (m_uiSummonTimer <= diff)
                {
                    SpawnMobs();
                    m_uiSummonTimer = 25000;
                } else m_uiSummonTimer -= diff;

                if (m_uiMovementTimer <= diff)
                {
                    switch(m_uiWaypointId)
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
                            DoScriptText(RAND(SAY_DRAKE_BREATH_1,SAY_DRAKE_BREATH_2), me);
                            DoScriptText(EMOTE_BREATH, me);
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
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_POISONED_SPEAR);
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

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);
        Summons.DespawnAll();
        if (m_pInstance)
            m_pInstance->SetData(DATA_SKADI_THE_RUTHLESS_EVENT, DONE);
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), me);
    }

    void SpawnMobs()
    {
        for (uint8 i = 0; i < DUNGEON_MODE(5,6); ++i)
        {
            switch (urand(0,2))
            {
                case 0: me->SummonCreature(CREATURE_YMIRJAR_WARRIOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                case 1: me->SummonCreature(CREATURE_YMIRJAR_WITCH_DOCTOR, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
                case 2: me->SummonCreature(CREATURE_YMIRJAR_HARPOONER, SpawnLoc.GetPositionX()+rand()%5, SpawnLoc.GetPositionY()+rand()%5, SpawnLoc.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000); break;
            }
        }
    }

    void SpawnTrigger()
    {
        uint8 iStart,iEnd;
        switch (urand(0,1))
        {
            case 0:
                iStart = 8;
                iEnd = 37;
                break;
            case 1:
                iStart = 38;
                iEnd = 68;
                break;
        }
        for(uint32 i = iStart; i < iEnd; ++i)
            me->SummonCreature(CREATURE_TRIGGER,Location[i]);
    }
};

bool GOHello_go_harpoon_launcher(Player *pPlayer, GameObject *pGO)
{
    ScriptedInstance* m_pInstance = pGO->GetInstanceData();
    if (!m_pInstance) return false;

    if (Creature* pSkadi = Unit::GetCreature((*pGO),m_pInstance->GetData64(DATA_SKADI_THE_RUTHLESS)))
    {
        pPlayer->CastSpell(pSkadi,SPELL_RAPID_FIRE, true);
    }
    return false;
}

CreatureAI* GetAI_boss_skadi(Creature* pCreature)
{
    return new boss_skadiAI (pCreature);
}

void AddSC_boss_skadi()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_skadi";
    newscript->GetAI = &GetAI_boss_skadi;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "go_harpoon_launcher";
    newscript->pGOHello = &GOHello_go_harpoon_launcher;
    newscript->RegisterSelf();
}

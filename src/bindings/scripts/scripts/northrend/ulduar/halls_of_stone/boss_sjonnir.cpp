/* Script Data Start
SDName: Boss sjonnir
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_sjonnir' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_halls_of_stone.h"

enum Spells
{
    SPELL_LIGHTING_RING                        = 51849, //Periodic Trigger (interval 2s) spell = 50841
    H_SPELL_LIGHTING_RING                      = 59861, //Periodic Trigger (interval 2s) spell = 59849
    SPELL_LIGHTING_RING_1                      = 50840, //Periodic Trigger (interval 2s) spell = 50841
    H_SPELL_LIGHTING_RING_1                    = 59848, //Periodic Trigger (interval 2s) spell = 59849
    SPELL_STATIC_CHARGE                        = 50834, //Periodic Trigger 2s interval, spell =50835
    H_SPELL_STATIC_CHARGE                      = 59846, //Periodic Trigger 2s interval, spell =50847
    SPELL_CHAIN_LIGHTING                       = 50830,
    H_SPELL_CHAIN_LIGHTING                     = 59844,
    SPELL_LIGHTING_SHIELD                      = 50831,
    H_SPELL_LIGHTING_SHIELD                    = 59845,
    SPELL_FRENZY                               = 28747
};

enum Yells
{
    SAY_AGGRO                               = -1603011,
    SAY_SLAY_1                              = -1603012,
    SAY_SLAY_2                              = -1603013,
    SAY_SLAY_3                              = -1603014,
    SAY_DEATH                               = -1603015
};

#define EMOTE_GENERIC_FRENZY                  -1000002

enum Creatures
{
    CREATURE_FORGED_IRON_TROGG              = 27979,
    CREATURE_MALFORMED_OOZE                 = 27981,
    CREATURE_FORGED_IRON_DWARF              = 27982,
    CREATURE_IRON_SLUDGE                    = 28165
};

enum Misc
{
    DATA_TIME_BEFORE_OOZE                   = 150000, //2min 30 secs
    ACHIEVEMENT_ABUSE_THE_OOZE              = 2155
};

struct Locations
{
    float x, y, z;
};

static Locations PipeLocations[] =
{
  {1295.44, 734.07, 200.3}, //left
  {1297.7,  595.6,  199.9} //right
};

static Locations CenterPoint = {1295.21, 667.157, 189.691};

struct TRINITY_DLL_DECL boss_sjonnirAI : public ScriptedAI
{
    boss_sjonnirAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    bool bIsFrenzy;

    uint32 uiChainLightningTimer;
    uint32 uiLightningShieldTimer;
    uint32 uiStaticChargeTimer;
    uint32 uiLightningRingTimer;
    uint32 uiSummonTimer;
    uint32 uiFrenzyTimer;
    uint32 uiEncounterTimer;
    uint32 uiKilledIronSludges;

    ScriptedInstance* pInstance;

    void Reset()
    {
        bIsFrenzy = false;

        uiEncounterTimer = 0;
        uiChainLightningTimer = 3000 + rand()%5000;
        uiLightningShieldTimer = 20000 + rand()%5000;
        uiStaticChargeTimer = 20000 + rand()%5000;
        uiLightningRingTimer = 30000 + rand()%5000;
        uiSummonTimer = 5000;
        uiFrenzyTimer = 300000; //5 minutes
        uiKilledIronSludges = 0;

        if (pInstance)
            pInstance->SetData(DATA_SJONNIR_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        uiEncounterTimer = 0;

        if (pInstance)
            pInstance->SetData(DATA_SJONNIR_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiChainLightningTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, HEROIC(SPELL_CHAIN_LIGHTING, H_SPELL_CHAIN_LIGHTING));
            uiChainLightningTimer = 10000 + rand()%5000;
        } else uiChainLightningTimer -= diff;

        if (uiLightningShieldTimer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_LIGHTING_SHIELD, H_SPELL_LIGHTING_SHIELD));
            uiLightningShieldTimer -= diff;
        }

        if (uiStaticChargeTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_STATIC_CHARGE, H_SPELL_STATIC_CHARGE));
            uiStaticChargeTimer = 20000 + rand()%5000;
        } uiStaticChargeTimer -= diff;

        if (uiLightningRingTimer < diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature, HEROIC(SPELL_LIGHTING_RING, H_SPELL_LIGHTING_RING));
            uiLightningRingTimer = 30000 + rand()%5000;
        } else uiLightningRingTimer -= diff;

        if (uiSummonTimer < diff)
        {
            uint32 uiSummonPipe = rand()%2;
            m_creature->SummonCreature(uiEncounterTimer > DATA_TIME_BEFORE_OOZE ? CREATURE_MALFORMED_OOZE :
                                       RAND(CREATURE_FORGED_IRON_DWARF,CREATURE_FORGED_IRON_TROGG),
                                       PipeLocations[uiSummonPipe].x, PipeLocations[uiSummonPipe].y, PipeLocations[uiSummonPipe].z, 0.0f,
                                       TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
            uiSummonTimer = 20000;
        } else uiSummonTimer -= diff;

        if (!bIsFrenzy)
        {
          if (uiFrenzyTimer < diff)
          {
              DoCast(m_creature, SPELL_FRENZY);
              bIsFrenzy = true;
          }
          else uiFrenzyTimer -= diff;
        }

        uiEncounterTimer +=diff;

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* summon)
    {
        summon->GetMotionMaster()->MovePoint(0, CenterPoint.x, CenterPoint.y, CenterPoint.z);
        /*if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            summon->AI()->AttackStart(pTarget);*/
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (HeroicMode && uiKilledIronSludges > 4)
        {
            AchievementEntry const *AchievAbuseTheOoze = GetAchievementStore()->LookupEntry(ACHIEVEMENT_ABUSE_THE_OOZE);
            if (AchievAbuseTheOoze)
            {
                Map* pMap = m_creature->GetMap();
                if (pMap && pMap->IsDungeon())
                {
                    Map::PlayerList const &players = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        itr->getSource()->CompletedAchievement(AchievAbuseTheOoze);
                }
            }
        }

        if (pInstance)
            pInstance->SetData(DATA_SJONNIR_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }

    void KilledIronSludge()
    {
        ++uiKilledIronSludges;
    }
};

CreatureAI* GetAI_boss_sjonnir(Creature* pCreature)
{
    return new boss_sjonnirAI (pCreature);
}

struct TRINITY_DLL_DECL mob_malformed_oozeAI : public ScriptedAI
{
    mob_malformed_oozeAI(Creature *c) : ScriptedAI(c) {}

    uint32 uiMergeTimer;
    bool bIsMerging;

    void Reset()
    {
        uiMergeTimer = 5000;
        bIsMerging = false;
    }

    void UpdateAI(const uint32 diff)
    {
        if (bIsMerging)
        {
            if (uiMergeTimer < diff)
            {
                if (Creature* pTemp = m_creature->FindNearestCreature(CREATURE_MALFORMED_OOZE, 1.0f, true))
                {
                    DoSpawnCreature(CREATURE_IRON_SLUDGE, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                    pTemp->DisappearAndDie();
                    m_creature->DisappearAndDie();
                } else bIsMerging = false;
            } else uiMergeTimer -= diff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;
        bIsMerging = true;
    }
};

CreatureAI* GetAI_mob_malformed_ooze(Creature* pCreature)
{
    return new mob_malformed_oozeAI(pCreature);
}

struct TRINITY_DLL_DECL mob_iron_sludgeAI : public ScriptedAI
{
    mob_iron_sludgeAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            if(Creature* pSjonnir = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_SJONNIR)))
                CAST_AI(boss_sjonnirAI, pSjonnir->AI())->KilledIronSludge();
    }
};

CreatureAI* GetAI_mob_iron_sludge(Creature* pCreature)
{
    return new mob_iron_sludgeAI(pCreature);
}

void AddSC_boss_sjonnir()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_sjonnir";
    newscript->GetAI = &GetAI_boss_sjonnir;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_malformed_ooze";
    newscript->GetAI = &GetAI_mob_malformed_ooze;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_iron_sludge";
    newscript->GetAI = &GetAI_mob_iron_sludge;
    newscript->RegisterSelf();
}

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
    CREATURE_FORGED_IRON_DWARF              = 27982
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
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        bIsFrenzy = false;
        
        uiChainLightningTimer = 3000 + rand()%5000;
        uiLightningShieldTimer = 20000 + rand()%5000;
        uiStaticChargeTimer = 20000 + rand()%5000;
        uiLightningRingTimer = 30000 + rand()%5000;
        uiSummonTimer = 5000;
        uiFrenzyTimer = 300000; //5 minutes
        
        if (pInstance)
            pInstance->SetData(DATA_SJONNIR_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
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
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
            while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (pTarget)
                DoCast(pTarget, HeroicMode ? H_SPELL_CHAIN_LIGHTING : SPELL_CHAIN_LIGHTING);
            uiChainLightningTimer = 10000 + rand()%5000;
        } else uiChainLightningTimer -= diff;
        
        if (uiLightningShieldTimer < diff)
        {
            DoCast(m_creature, HeroicMode ? H_SPELL_LIGHTING_SHIELD : SPELL_LIGHTING_SHIELD);
            uiLightningShieldTimer -= diff;
        }
        
        if (uiStaticChargeTimer < diff)
        {
            DoCast(m_creature->getVictim(), HeroicMode ? H_SPELL_STATIC_CHARGE : SPELL_STATIC_CHARGE);
            uiStaticChargeTimer = 20000 + rand()%5000;
        } uiStaticChargeTimer -= diff;
        
        if (uiLightningRingTimer < diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature, HeroicMode ? H_SPELL_LIGHTING_RING : SPELL_LIGHTING_RING);
            uiLightningRingTimer = 30000 + rand()%5000;
        } else uiLightningRingTimer -= diff;
        
        if (uiSummonTimer < diff)
        {
            uint32 uiSummonPipe = rand()%2;
            m_creature->SummonCreature(RAND(CREATURE_FORGED_IRON_DWARF,CREATURE_FORGED_IRON_TROGG,CREATURE_MALFORMED_OOZE),
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

        DoMeleeAttackIfReady();
    }
    
    void JustSummoned(Creature* summon)
    {
        Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
        while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
            pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
        if (pTarget)
            summon->AI()->AttackStart(pTarget);
    }
    
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_SJONNIR_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_sjonnir(Creature* pCreature)
{
    return new boss_sjonnirAI (pCreature);
}

void AddSC_boss_sjonnir()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_sjonnir";
    newscript->GetAI = &GetAI_boss_sjonnir;
    newscript->RegisterSelf();
}

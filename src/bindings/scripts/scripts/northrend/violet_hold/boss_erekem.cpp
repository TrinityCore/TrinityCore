/* Script Data Start
SDName: Boss erekem
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_violet_hold.h"

enum Spells
{
    SPELL_BLOODLUST                                = 54516,
    SPELL_BREAK_BONDS                              = 59463,
    SPELL_CHAIN_HEAL                               = 54481,
    H_SPELL_CHAIN_HEAL                             = 59473,
    SPELL_EARTH_SHIELD                             = 54479,
    H_SPELL_EARTH_SHIELD                           = 59471,
    SPELL_EARTH_SHOCK                              = 54511,
    SPELL_LIGHTNING_BOLT                           = 53044,
    SPELL_STORMSTRIKE                              = 51876
};

//not in db
enum Yells
{
    SAY_AGGRO                                   = -1608010,
    SAY_SLAY_1                                  = -1608011,
    SAY_SLAY_2                                  = -1608012,
    SAY_SLAY_3                                  = -1608013,
    SAY_DEATH                                   = -1608014,
    SAY_SPAWN                                   = -1608015,
    SAY_ADD_KILLED                              = -1608016,
    SAY_BOTH_ADDS_KILLED                        = -1608017
};

struct TRINITY_DLL_DECL boss_erekemAI : public ScriptedAI
{
    boss_erekemAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiBloodlustTimer;
    uint32 uiChainHealTimer;
    uint32 uiEarthShockTimer;
    uint32 uiLightningBoltTimer;
    uint32 uiEarthShieldTimer;

    Creature* pGuard1;
    Creature* pGuard2;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiBloodlustTimer = 15000;
        uiChainHealTimer = 0;
        uiEarthShockTimer = urand(2000,8000);
        uiLightningBoltTimer = urand(5000,10000);
        uiEarthShieldTimer = 20000;
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoCast(m_creature, HEROIC(SPELL_EARTH_SHIELD, H_SPELL_EARTH_SHIELD));

        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }
    }

    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //spam stormstrike in hc mode if spawns are dead
        if (HeroicMode)
        {
            if (pGuard1 && !pGuard1->isAlive() && pGuard2 && !pGuard2->isAlive())
            {
                DoCast(m_creature->getVictim(), SPELL_STORMSTRIKE);
            }
        }

        if (uiEarthShieldTimer < diff)
        {
            DoCast(m_creature, HEROIC(SPELL_EARTH_SHIELD, H_SPELL_EARTH_SHIELD));
            uiEarthShieldTimer = 20000;
        } else uiEarthShieldTimer -= diff;

        if (uiChainHealTimer < diff)
        {
            if (Creature *pTarget = GetChainHealTarget())
            {
                DoCast(pTarget,HeroicMode ? H_SPELL_CHAIN_HEAL : SPELL_CHAIN_HEAL);
                //If one of the adds is dead spawn heals faster
                uiChainHealTimer = ((pGuard1 && !pGuard1->isAlive()) || (pGuard2 && !pGuard2->isAlive()) ? 3000 : 8000) + rand()%3000;
            }
        } else uiChainHealTimer -= diff;

        if (uiBloodlustTimer < diff)
        {
            DoCast(m_creature,SPELL_BLOODLUST);
            uiBloodlustTimer = urand(35000,45000);
        } else uiBloodlustTimer -= diff;


        if (uiEarthShockTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_EARTH_SHOCK);
            uiEarthShockTimer = urand(8000,13000);
        } else uiEarthShockTimer -= diff;

        if (uiLightningBoltTimer < diff)
        {
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
            while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                SelectUnit(SELECT_TARGET_RANDOM,0);
            if (pTarget)
                DoCast(pTarget, SPELL_LIGHTNING_BOLT);
            uiLightningBoltTimer = urand(18000,24000);
        } else uiLightningBoltTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
            {
                pInstance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                pInstance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
            {
                pInstance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                pInstance->SetData(DATA_WAVE_COUNT, 13);
            }
        }
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }

    Creature* GetChainHealTarget()
    {
        Creature* pTarget = NULL;
        return pTarget;
    }
};

CreatureAI* GetAI_boss_erekem(Creature* pCreature)
{
    return new boss_erekemAI (pCreature);
}

struct TRINITY_DLL_DECL mob_erekem_guardAI : public ScriptedAI
{
    mob_erekem_guardAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiEarthShieldTimer;
    uint32 uiLightningBoltTimer;
    uint32 uiBloodlustTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiEarthShieldTimer = 20000;
        uiLightningBoltTimer = urand(0,5000);
        uiBloodlustTimer = urand(8000,18000);
    }

    void EnterCombat(Unit* who)
    {
        DoCast(m_creature, H_SPELL_EARTH_SHIELD);
    }

    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if (uiEarthShieldTimer < diff)
        {
            DoCast(m_creature, H_SPELL_EARTH_SHIELD);
            uiEarthShieldTimer = 20000;
        } else uiEarthShieldTimer -= diff;

        if (uiLightningBoltTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_LIGHTNING_BOLT);
            uiLightningBoltTimer = urand(18000,24000);
        } else uiLightningBoltTimer -= diff;

        if (uiBloodlustTimer < diff)
        {
            DoCast(m_creature,SPELL_BLOODLUST);
            uiBloodlustTimer = urand(35000,45000);
        } else uiBloodlustTimer -= diff;
    }
};

CreatureAI* GetAI_mob_erekem_guard(Creature* pCreature)
{
    return new mob_erekem_guardAI (pCreature);
}


void AddSC_boss_erekem()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_erekem";
    newscript->GetAI = &GetAI_boss_erekem;
    newscript->RegisterSelf();

    newscript->Name = "mob_erekem_guard";
    newscript->GetAI = &GetAI_mob_erekem_guard;
    newscript->RegisterSelf();
}

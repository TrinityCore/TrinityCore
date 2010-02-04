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
#include "ScriptedPch.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_BLOODLUST                             = SPELL_BLOODLUST_54516,
    SPELL_BREAK_BONDS                           = SPELL_BREAK_BONDS_59463,
    SPELL_CHAIN_HEAL                            = SPELL_CHAIN_HEAL_54481,
    H_SPELL_CHAIN_HEAL                          = SPELL_CHAIN_HEAL_59473,
    SPELL_EARTH_SHIELD                          = SPELL_EARTH_SHIELD_54479,
    H_SPELL_EARTH_SHIELD                        = SPELL_EARTH_SHIELD_59471,
    SPELL_EARTH_SHOCK                           = SPELL_EARTH_SHOCK_54511,
    SPELL_LIGHTNING_BOLT                        = SPELL_LIGHTNING_BOLT_53044,
    SPELL_STORMSTRIKE                           = SPELL_STORMSTRIKE_51876
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

        pGuard1 = pInstance->instance->GetCreature(pInstance->GetData64(DATA_EREKEM_GUARD_1));
        if (pGuard1 && !pGuard1->isAlive())
            pGuard1->Respawn();

        pGuard2 = pInstance->instance->GetCreature(pInstance->GetData64(DATA_EREKEM_GUARD_2));
        if (pGuard2 && !pGuard2->isAlive())
            pGuard2->Respawn();
    }

    void AttackStart(Unit* pWho)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(pWho, true))
        {
            m_creature->AddThreat(pWho, 0.0f);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);
            DoStartMovement(pWho);

            if (pInstance)
            {
                if (pGuard1)
                {
                    pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    if (!pGuard1->getVictim() && pGuard1->AI())
                        pGuard1->AI()->AttackStart(pWho);
                }
     
                if (pGuard2)
                {
                    pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    if (!pGuard2->getVictim() && pGuard2->AI())
                        pGuard2->AI()->AttackStart(pWho);
                }
            }
        }
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoCast(m_creature, DUNGEON_MODE(SPELL_EARTH_SHIELD, H_SPELL_EARTH_SHIELD));

        if (pInstance)
        {
            pGuard1 = pInstance->instance->GetCreature(pInstance->GetData64(DATA_EREKEM_GUARD_1));
            pGuard2 = pInstance->instance->GetCreature(pInstance->GetData64(DATA_EREKEM_GUARD_2));

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
        if (IsHeroic())
        {
            if (pGuard1 && !pGuard1->isAlive() && pGuard2 && !pGuard2->isAlive())
            {
                DoCast(m_creature->getVictim(), SPELL_STORMSTRIKE);
            }
        }

        if (uiEarthShieldTimer <= diff)
        {
            DoCast(m_creature, DUNGEON_MODE(SPELL_EARTH_SHIELD, H_SPELL_EARTH_SHIELD));
            uiEarthShieldTimer = 20000;
        } else uiEarthShieldTimer -= diff;

        if (uiChainHealTimer <= diff)
        {
            if (Creature *pTarget = GetChainHealTarget())
            {
                DoCast(pTarget, DUNGEON_MODE(SPELL_CHAIN_HEAL, H_SPELL_CHAIN_HEAL));
                //If one of the adds is dead spawn heals faster
                uiChainHealTimer = ((pGuard1 && !pGuard1->isAlive()) || (pGuard2 && !pGuard2->isAlive()) ? 3000 : 8000) + rand()%3000;
            }
        } else uiChainHealTimer -= diff;

        if (uiBloodlustTimer <= diff)
        {
            DoCast(m_creature, SPELL_BLOODLUST);
            uiBloodlustTimer = urand(35000,45000);
        } else uiBloodlustTimer -= diff;

        if (uiEarthShockTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_EARTH_SHOCK);
            uiEarthShockTimer = urand(8000,13000);
        } else uiEarthShockTimer -= diff;

        if (uiLightningBoltTimer <= diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
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
        if (HealthBelowPct(85))
            return m_creature;
        if (pGuard1 && pGuard1->isAlive() && (pGuard1->GetHealth()*100 <= pGuard1->GetMaxHealth() * 75))
            return pGuard1;
        if (pGuard2 && pGuard2->isAlive() && (pGuard2->GetHealth()*100 <= pGuard2->GetMaxHealth() * 75))
            return pGuard2;
        return NULL;
    }
};

CreatureAI* GetAI_boss_erekem(Creature* pCreature)
{
    return new boss_erekemAI (pCreature);
}

enum GuardSpells
{
    SPELL_GUSHING_WOUND                   = 39215,
    SPELL_HOWLING_SCREECH                 = 54462,
    SPELL_STRIKE                          = 14516
};

struct TRINITY_DLL_DECL mob_erekem_guardAI : public ScriptedAI
{
    mob_erekem_guardAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiGushingWoundTimer;
    uint32 uiHowlingScreechTimer;
    uint32 uiStrikeTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiStrikeTimer = urand(4000,8000);
        uiHowlingScreechTimer = urand(8000,13000);
        uiGushingWoundTimer = urand(1000,3000);
    }

    void AttackStart(Unit* pWho)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(pWho, true))
        {
            m_creature->AddThreat(pWho, 0.0f);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);
            DoStartMovement(pWho);
        }
    }

    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();

        if (uiStrikeTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_STRIKE);
            uiStrikeTimer = urand(4000,8000);
        } else uiStrikeTimer -= diff;

        if (uiHowlingScreechTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_HOWLING_SCREECH);
            uiHowlingScreechTimer = urand(8000,13000);
        } else uiHowlingScreechTimer -= diff;

        if (uiGushingWoundTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_GUSHING_WOUND);
            uiGushingWoundTimer = urand(7000,12000);
        } else uiGushingWoundTimer -= diff;
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

    newscript = new Script;
    newscript->Name = "mob_erekem_guard";
    newscript->GetAI = &GetAI_mob_erekem_guard;
    newscript->RegisterSelf();
}

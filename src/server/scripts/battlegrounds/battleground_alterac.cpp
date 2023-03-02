/*
SDName: Alterac
SD%Complete:
SDComment:
SDCategory: BG
EndScriptData */

#include "scriptPCH.h"
#include "CreatureGroups.h"

/*
Vanndar: Thunderclap (about 200-300 nature damage per player in range not been upgraded since vanilla, Time between attacks increased by 33%, movement speed reduced by 40%.) Storm Bolt (about 450 nature damage, stuns for 8 seconds, dispellable, used on non tanks) Avatar (50% increased damage and armor, up for 15 seconds, comes back up about 15-20 seconds later) Drek'thar: Whirlwind (2 second cast time, weapon damage to all in range) Frenzy (167% damage increase and attack speed increase by 50%, lasts 2 minutes, goes up after about 15-20 seconds from the start of fight) Knockdown (Infli
*/


/*######
## npc_Vanndar
######*/

enum
{
    NPC_VANNDAR           = 11948,

    SPELL_AVATAR          = 19135,
    SPELL_STORMBOLT       = 19136,
    SPELL_THUNDERCLAP     = 15588,

    SAY_VANNDAR_AGGRO     = 10243,
    SAY_VANNDAR_RESET     = 10373,
    SAY_VANNDAR_BUFF1     = 12351,
    SAY_VANNDAR_BUFF2     = 12352,
    SAY_VANNDAR_RAID_WIPE = 10374,
    SAY_VANNDAR_FIGHT1    = 8838,
    SAY_VANNDAR_FIGHT2    = 8839,
    SAY_VANNDAR_FIGHT3    = 8840,
    SAY_VANNDAR_FIGHT4    = 8841,
    SAY_VANNDAR_FIGHT5    = 8842,
    SAY_VANNDAR_FIGHT6    = 8843
};

uint16 const vandar_fight_texts[] = { SAY_VANNDAR_FIGHT1 , SAY_VANNDAR_FIGHT2, SAY_VANNDAR_FIGHT3, SAY_VANNDAR_FIGHT4, SAY_VANNDAR_FIGHT5,  SAY_VANNDAR_FIGHT6 };

#define POSITION_VANNDAR_CENTER_X        722.4f
#define POSITION_VANNDAR_CENTER_Y        -11.0f

class npc_alterac_bossHelper
{
        class ThreatListCopier : public ThreatListProcesser
        {
            public:
                ThreatListCopier(Unit* destination) : _dest(destination) {}
                bool Process(Unit* unit) override
                {
                    _dest->AI()->AttackStart(unit);
                    return false;
                }
                Unit* _dest;
        };
    public:
        npc_alterac_bossHelper(Creature* c) : me(c) {}
        void AddLinkedMob(uint32 entry)
        {
            m_linkedEntries.push_back(entry);
        }
        void AggroLinkedMobsIfNeeded()
        {
            std::list<Creature*> creaturesLinked;
            for (uint32 entry : m_linkedEntries)
                GetCreatureListWithEntryInGrid(creaturesLinked, me, entry, 100.0f);
            for (const auto& it : creaturesLinked)
                if (it->IsAlive() && !it->IsInCombat())
                {
                    ThreatListCopier* c = new ThreatListCopier(it);
                    me->ProcessThreatList(c);
                    delete c;
                }
        }
    private:
        Creature* me;
        std::vector<uint32> m_linkedEntries;
};

struct npc_VanndarAI : public ScriptedAI, public npc_alterac_bossHelper
{
    npc_VanndarAI(Creature* pCreature) : ScriptedAI(pCreature), npc_alterac_bossHelper(pCreature)
    {
        AddLinkedMob(13333);
        for (int i = 14762; i <= 14769; ++i)
            AddLinkedMob(i);
        Reset();
    }

    uint32 m_uiGlobalCooldown;
    uint32 m_uiAvatar_Timer;
    uint32 m_uiStormbolt_Timer;
    uint32 m_uiThunderclap_Timer;
    bool m_bAggro;
    bool m_bCombat1;
    bool m_bCombat2;
    bool m_bCombat3;
    bool m_bCombat4;
    bool m_bCombat5;
    bool m_bLeashed;

    void Reset() override
    {
        m_uiGlobalCooldown = 0;

        m_uiAvatar_Timer = urand(12000, 20000);
        m_uiStormbolt_Timer = 8000;
        m_uiThunderclap_Timer = 5000;
        m_creature->ClearUnitState(UNIT_STAT_ROOT);
        m_bAggro = true;
        m_bLeashed = false;
        m_bCombat1 = true;
        m_bCombat2 = true;
        m_bCombat3 = true;
        m_bCombat4 = true;
        m_bCombat5 = true;
    }

    void EnterEvadeMode() override
    {
        if (m_bLeashed)
            DoScriptText(SAY_VANNDAR_RESET, m_creature);
        else
            DoScriptText(SAY_VANNDAR_RAID_WIPE, m_creature);

        m_bLeashed = false;
        ScriptedAI::EnterEvadeMode();
    }

    void Aggro(Unit* pWho) override
    {
        if (m_bAggro)
        {
            DoScriptText(SAY_VANNDAR_AGGRO, m_creature);
            m_bAggro = false;
        }
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->GetVictim())
            return;

        if ((pWho->GetDistance(m_creature) < 23.0f) && (m_creature->IsHostileTo(pWho)))
            AttackStart(pWho);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_creature->GetMapId() == 30)
            if (m_creature->GetDistance2d(POSITION_VANNDAR_CENTER_X, POSITION_VANNDAR_CENTER_Y) > 35.0f)
            {
                m_creature->CombatStop();
                m_creature->SetHealth(m_creature->GetMaxHealth());
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
                m_bLeashed = true;
                EnterEvadeMode();
                return;
            }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // GlobalCD non ecoule.
        if (m_uiGlobalCooldown > diff)
            m_uiGlobalCooldown -= diff;
        else
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_uiGlobalCooldown = 1;
            else
                m_uiGlobalCooldown = 0;
        }

        // SPELL_AVATAR
        if (m_uiAvatar_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_AVATAR) == CAST_OK)
                {
                    m_uiAvatar_Timer = urand(20000, 30000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiAvatar_Timer -= diff;

        // SPELL_STORMBOLT
        if (m_uiStormbolt_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_STORMBOLT) == CAST_OK)
                {
                    m_uiStormbolt_Timer = urand(8000, 10000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiStormbolt_Timer -= diff;

        // SPELL_THUNDERCLAP
        if (m_uiThunderclap_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_THUNDERCLAP) == CAST_OK)
                {
                    m_uiThunderclap_Timer = urand(5000, 8000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiThunderclap_Timer -= diff;

        if (m_creature->GetHealthPercent() < 80.0f && m_bCombat1)
        {
            DoScriptText(vandar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat1 = false;
        }

        if (m_creature->GetHealthPercent() < 60.0f && m_bCombat2)
        {
            DoScriptText(vandar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat2 = false;
        }

        if (m_creature->GetHealthPercent() < 40.0f && m_bCombat3)
        {
            DoScriptText(vandar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat3 = false;
        }

        if (m_creature->GetHealthPercent() < 20.0f && m_bCombat4)
        {
            DoScriptText(vandar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat4 = false;
        }

        if (m_creature->GetHealthPercent() < 5.0f && m_bCombat5)
        {
            DoScriptText(vandar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat5 = false;
        }

        AggroLinkedMobsIfNeeded();
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_Vanndar(Creature* m_creature)
{
    return new npc_VanndarAI(m_creature);
}


/*######
## npc_DrekThar
######*/

enum
{
    NPC_DREAKTHAR          = 11946,

    SPELL_FRENZY           = 28747,
    SPELL_WHIRLWIND_DKT    = 13736,
    SPELL_KNOCKDOWN        = 19128,

    SAY_DREKTHAR_AGGRO     = 10245,
    SAY_DREKTHAR_RESET     = 10377,
    SAY_DREKTHAR_RAID_WIPE = 10376,
    SAY_DREKTHAR_FIGHT1    = 8844,
    SAY_DREKTHAR_FIGHT2    = 8845,
    SAY_DREKTHAR_FIGHT3    = 8846,
    SAY_DREKTHAR_FIGHT4    = 8847,
    SAY_DREKTHAR_FIGHT5    = 8848,
    SAY_DREKTHAR_FIGHT6    = 8849
};

uint16 const drekthar_fight_texts[] = { SAY_DREKTHAR_FIGHT1, SAY_DREKTHAR_FIGHT2, SAY_DREKTHAR_FIGHT3, SAY_DREKTHAR_FIGHT4, SAY_DREKTHAR_FIGHT5, SAY_DREKTHAR_FIGHT6 };

#define    POSITION_DKT_CENTER_X         -1370.9f
#define    POSITION_DKT_CENTER_Y          -219.8f

// Duros 12121 Drakan 12122

/*

8269 +118 +60% 2min
8599 +60 +30% 2 min
12795 +60 +30%
15061 non
15097 non
15716 non

18501 non
19516 +0 +9%
19953 +500 +50% 10 sec
23537 +240 +50%
24318 +50% +65% 2 min
effet 1 = mod damage done
effet 2 = mod spaad
25503 ours
26527 +250 +75% 2 min
27897 explo arc
28131 +25% +40% 5 min
28468 +150%
28747 +100% +50% 10 min
28798 +150% +75% 30 min

Correct : damage + 167%, speed 50%
*/
/* Il doit repop les 2 chiens quand il est reset */

struct npc_DrekTharAI : public ScriptedAI, public npc_alterac_bossHelper
{
    npc_DrekTharAI(Creature* pCreature) : ScriptedAI(pCreature), npc_alterac_bossHelper(pCreature)
    {
        AddLinkedMob(12121);
        AddLinkedMob(12122);
        for (int i = 14772; i <= 14777; ++i)
            AddLinkedMob(i);
        Reset();
    }

    uint32 m_uiGlobalCooldown;
    uint32 m_uiWhirlwind_Timer;
    uint32 m_uiKnockDown_Timer;
    uint32 m_uiFrenzy_Timer;
    uint32 m_uiIsInWhirlwind_Timer;
    bool m_bAggro;
    bool m_bCombat1;
    bool m_bCombat2;
    bool m_bCombat3;
    bool m_bCombat4;
    bool m_bCombat5;
    bool m_bLeashed;

    void Reset() override
    {
        m_uiGlobalCooldown = 0;

        m_uiWhirlwind_Timer = urand(8000, 12000);
        m_uiIsInWhirlwind_Timer = 0;
        m_uiKnockDown_Timer = 18000;
        m_uiFrenzy_Timer = 1000;
        m_creature->ClearUnitState(UNIT_STAT_ROOT);
        m_bAggro = true;
        m_bLeashed = false;
        m_bCombat1 = true;
        m_bCombat2 = true;
        m_bCombat3 = true;
        m_bCombat4 = true;
        m_bCombat5 = true;
        m_creature->RemoveAurasDueToSpell(SPELL_FRENZY);

        std::list<Creature*> m_Wolf;
        GetCreatureListWithEntryInGrid(m_Wolf, m_creature, 12121, 100.0f);
        for (const auto& it : m_Wolf)
            if (!it->IsAlive())
                it->Respawn();
        m_Wolf.clear();

        GetCreatureListWithEntryInGrid(m_Wolf, m_creature, 12122, 100.0f);
        for (const auto& it : m_Wolf)
            if (!it->IsAlive())
                it->Respawn();
        m_Wolf.clear();

    }

    void EnterEvadeMode() override
    {
        if (m_bLeashed)
            DoScriptText(SAY_DREKTHAR_RESET, m_creature);
        else
            DoScriptText(SAY_DREKTHAR_RAID_WIPE, m_creature);

        m_bLeashed = false;
        ScriptedAI::EnterEvadeMode();
    }

    void Aggro(Unit* pWho) override
    {
        if (m_bAggro)
        {
            DoScriptText(SAY_DREKTHAR_AGGRO, m_creature);
            m_bAggro = false;
        }
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->GetVictim())
            return;

        if ((pWho->GetDistance(m_creature) < 22.0f) && (m_creature->IsHostileTo(pWho)))
            AttackStart(pWho);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_creature->GetMapId() == 30)
        {
            if (m_creature->GetDistance2d(POSITION_DKT_CENTER_X, POSITION_DKT_CENTER_Y) > 33.0f)
            {
                m_creature->CombatStop();
                m_creature->SetHealth(m_creature->GetMaxHealth());
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
                m_bLeashed = true;
                EnterEvadeMode();
                return;
            }
        }

        if (m_uiIsInWhirlwind_Timer < diff)
            m_uiIsInWhirlwind_Timer = 0;
        else
            m_uiIsInWhirlwind_Timer -= diff;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // GlobalCD non ecoule.
        if (m_uiGlobalCooldown > diff)
            m_uiGlobalCooldown -= diff;
        else
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_uiGlobalCooldown = 1;
            else
                m_uiGlobalCooldown = 0;
        }

        if (m_uiIsInWhirlwind_Timer == 0)
        {
            if (m_creature->HasUnitState(UNIT_STAT_ROOT))
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
        }
        else
        {
            if (!m_creature->HasUnitState(UNIT_STAT_ROOT))
                m_creature->AddUnitState(UNIT_STAT_ROOT);
        }

        // SPELL_WHIRLWIND
        if (m_uiWhirlwind_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_WHIRLWIND_DKT) == CAST_OK)
                {
                    m_uiWhirlwind_Timer = urand(12000, 16000);
                    m_uiIsInWhirlwind_Timer = 2000;
                    m_uiGlobalCooldown = 2000;
                }
            }
        }
        else
            m_uiWhirlwind_Timer -= diff;

        // SPELL_KNOCKDOWN
        if (m_uiKnockDown_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKDOWN) == CAST_OK)
                {
                    m_uiKnockDown_Timer = urand(16000, 24000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiKnockDown_Timer -= diff;

        // SPELL_FRENZY
        if (m_uiFrenzy_Timer < diff)
        {
            if (!m_uiGlobalCooldown && m_creature->GetHealthPercent() <= 30.0f)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
                {
                    m_uiFrenzy_Timer = 120000;
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiFrenzy_Timer -= diff;

        if (m_creature->GetHealthPercent() < 80.0f && m_bCombat1)
        {
            DoScriptText(drekthar_fight_texts[urand(0,5)], m_creature);
            m_bCombat1 = false;
        }

        if (m_creature->GetHealthPercent() < 60.0f && m_bCombat2)
        {
            DoScriptText(drekthar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat2 = false;
        }

        if (m_creature->GetHealthPercent() < 40.0f && m_bCombat3)
        {
            DoScriptText(drekthar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat3 = false;
        }

        if (m_creature->GetHealthPercent() < 20.0f && m_bCombat4)
        {
            DoScriptText(drekthar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat4 = false;
        }

        if (m_creature->GetHealthPercent() < 5.0f && m_bCombat5)
        {
            DoScriptText(drekthar_fight_texts[urand(0, 5)], m_creature);
            m_bCombat5 = false;
        }

        AggroLinkedMobsIfNeeded();
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_DrekThar(Creature* m_creature)
{
    return new npc_DrekTharAI(m_creature);
}


/*######
## npc_Balinda
######*/

enum
{
    NPC_BALINDA         = 11949,

    SPELL_FIREBALL      = 20420,
    SPELL_FROSTBOLT     = 5530,
    SPELL_CONEOFCOLD    = 22746,
    SPELL_ARCANEEXPLO   = 19712,
    SPELL_POLYMORPH     = 15534,

    SAY_BALINDA_AGGRO   = 10054,
    SAY_BALINDA_HALF_HP = 10056,
    SAY_BALINDA_RESET   = 10375
};

#define POSITION_BAL_CENTER_X       -57.7f
#define POSITION_BAL_CENTER_Y       -286.6f

struct npc_BalindaAI : public ScriptedAI
{
    npc_BalindaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_bReset = false;
        Reset();
    }

    // ScriptedInstance* m_pInstance; // remplacer par BG?

    uint32 m_uiGlobalCooldown;

    uint32 m_uiFireball_Timer;
    uint32 m_uiFrostbolt_Timer;
    uint32 m_uiConeOfCold_Timer;
    uint32 m_uiArcaneExplo_Timer;
    uint32 m_uiPolymorph_Timer;
    bool   m_sayBalinda;
    bool   m_bSayAggro;
    bool   m_bReset;

    void Reset() override
    {
        m_uiGlobalCooldown = 0;

        m_uiFireball_Timer = 0;
        m_uiFrostbolt_Timer = 0;
        m_uiConeOfCold_Timer = 1500;
        m_uiArcaneExplo_Timer = 2000;
        m_uiPolymorph_Timer = 1750;
        m_creature->ClearUnitState(UNIT_STAT_ROOT);
        if (m_bReset)
            DoScriptText(SAY_BALINDA_RESET, m_creature);
        m_bReset = true;
        m_sayBalinda = true;
        m_bSayAggro = true;
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->GetVictim())
            return;

        if ((pWho->GetDistance(m_creature) < 28.0f) && (m_creature->IsHostileTo(pWho)))
            AttackStart(pWho);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_bSayAggro)
        {
            DoScriptText(SAY_BALINDA_AGGRO, m_creature);
            m_bSayAggro = false;
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetMapId() == 30)
            if (m_creature->GetDistance2d(POSITION_BAL_CENTER_X, POSITION_BAL_CENTER_Y) > 45.0f)
            {
                m_creature->CombatStop();
                m_creature->SetHealth(m_creature->GetMaxHealth());
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
                EnterEvadeMode();
                return;
            }

        if (m_sayBalinda)
        {
            if (m_creature->GetHealthPercent() < 50.0f)
            {
                DoScriptText(SAY_BALINDA_HALF_HP, m_creature);
                m_sayBalinda = false;
            }
        }

        // GlobalCD non ecoule.
        if (m_uiGlobalCooldown > diff)
            m_uiGlobalCooldown -= diff;
        else
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_uiGlobalCooldown = 1;
            else
                m_uiGlobalCooldown = 0;
        }

        if (((m_creature->GetDistance(m_creature->GetVictim()) > 25.0f) || (m_creature->GetDistance(m_creature->GetVictim()) < 5.0f))
            || (!m_creature->IsWithinLOSInMap(m_creature->GetVictim())))
        {
            if (m_creature->HasUnitState(UNIT_STAT_ROOT))
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
        }
        else
        {
            if (!m_creature->HasUnitState(UNIT_STAT_ROOT))
                m_creature->AddUnitState(UNIT_STAT_ROOT);
        }

        // ARCANE EXPLOSION
        if (m_uiArcaneExplo_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                uint32 uiTargetInRangeCount = 0;
                ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
                for (const auto i : tList)
                {
                    if (ObjectGuid uiTargetGuid = i->getUnitGuid())
                    {
                        if (Unit* pTarget = m_creature->GetMap()->GetUnit(uiTargetGuid))
                        {
                            if (m_creature->IsWithinDistInMap(pTarget, 6.0f))
                                uiTargetInRangeCount++;
                        }
                    }
                }
                if (urand(0, 1000) > (1000 * (3 / (uiTargetInRangeCount + 1))))
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ARCANEEXPLO) == CAST_OK)
                    {
                        m_uiArcaneExplo_Timer = urand(6000, 9000);
                        m_uiGlobalCooldown = 1000;
                    }
                }
                else
                    m_uiArcaneExplo_Timer = 1000;
            }
        }
        else
            m_uiArcaneExplo_Timer -= diff;

        // CONE OF COLD
        if (m_uiConeOfCold_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (m_creature->GetVictim()->GetDistance(m_creature) < 10.0f)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CONEOFCOLD) == CAST_OK)
                    {
                        m_uiConeOfCold_Timer = urand(12000, 16000);
                        m_uiGlobalCooldown = 1000;
                    }
                }
                else
                    m_uiConeOfCold_Timer = 2000;
            }
        }
        else
            m_uiConeOfCold_Timer -= diff;

        // SPELL_POLYMORPH
        if (m_uiPolymorph_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 1))
                {
                    // Update target.
                    if (DoCastSpellIfCan(pTarget, SPELL_POLYMORPH) == CAST_OK)
                    {
                        m_uiPolymorph_Timer = urand(16000, 20000);
                        m_uiGlobalCooldown = 1000;
                    }
                }
                else
                    m_uiPolymorph_Timer = 2000;
            }
        }
        else
            m_uiPolymorph_Timer -= diff;

        // SPELL_FROSTBOLT
        if (m_uiFrostbolt_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (m_creature->GetVictim()->GetDistance(m_creature) > 15.0f)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FROSTBOLT) == CAST_OK)
                    {
                        m_uiFrostbolt_Timer = urand(8000, 12000);
                        m_uiGlobalCooldown = 1000;
                    }
                }
                else
                    m_uiConeOfCold_Timer = 2000;
            }
        }
        else
            m_uiFrostbolt_Timer -= diff;

        // SPELL_FIREBALL
        if (m_uiFireball_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FIREBALL) == CAST_OK)
                {
                    m_uiFireball_Timer = urand(2500, 3000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiFireball_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_Balinda(Creature* m_creature)
{
    return new npc_BalindaAI(m_creature);
}

/*######
## npc_Galvangar
######*/

enum
{
    NPC_GALVANGAR         = 11947,

    SPELL_WHIRLWIND_GAL   = 13736,
    SPELL_MORTALSTRIKE    = 16856,
    SPELL_CLEAVE          = 15284,
    SPELL_FRIGHTSHOUT     = 19134,

    SAY_GALVANGAR_AGGRO   = 10055,
    SAY_GALVANGAR_HALF_HP = 10057,
    SAY_GALVANGAR_RESET   = 10378
};

#define POSITION_GAL_CENTER_X            -545.2f
#define POSITION_GAL_CENTER_Y            -165.3f

struct npc_GalvangarAI : public ScriptedAI
{
    npc_GalvangarAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_bReset = false;
        Reset();
    }

    uint32 m_uiGlobalCooldown;

    uint32 m_uiWhirlwind_Timer;
    uint32 m_uiMortalStrike_Timer;
    uint32 m_uiCleave_Timer;
    uint32 m_uiFrighteningShout_Timer;
    uint32 m_uiIsInWhirlwind_Timer;
    bool   m_bSayGalvangar;
    bool   m_bSayAggro;
    bool   m_bReset;

    void Aggro(Unit* pWho) override
    {
        if (m_bSayAggro)
        {
            DoScriptText(SAY_GALVANGAR_AGGRO, m_creature);
            m_bSayAggro = false;
        }
    }

    void Reset() override
    {
        m_uiGlobalCooldown = 0;

        m_uiWhirlwind_Timer = urand(8000, 12000);
        m_uiIsInWhirlwind_Timer = 0;
        m_uiMortalStrike_Timer = 7000;
        m_uiCleave_Timer = 4000;
        m_uiFrighteningShout_Timer = m_uiWhirlwind_Timer + urand(1000, 5000);
        m_creature->ClearUnitState(UNIT_STAT_ROOT);
        if (m_bReset)
            DoScriptText(SAY_GALVANGAR_RESET, m_creature);
        m_bReset = true;
        m_bSayGalvangar = true;
        m_bSayAggro     = true;
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->GetVictim())
            return;

        if ((pWho->GetDistance(m_creature) < 28.0f) && (m_creature->IsHostileTo(pWho)))
            AttackStart(pWho);
    }

    void UpdateAI(uint32 const diff) override
    {

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetMapId() == 30)
        {
            if (m_creature->GetDistance2d(POSITION_GAL_CENTER_X, POSITION_GAL_CENTER_Y) > 45.0f)
            {
                m_creature->CombatStop();
                m_creature->SetHealth(m_creature->GetMaxHealth());
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
                EnterEvadeMode();
                return;
            }
        }

        if (m_uiIsInWhirlwind_Timer < diff)
            m_uiIsInWhirlwind_Timer = 0;
        else
            m_uiIsInWhirlwind_Timer -= diff;


        if (m_bSayGalvangar)
        {
            if (m_creature->GetHealthPercent() < 50.0f)
            {
                DoScriptText(SAY_GALVANGAR_HALF_HP, m_creature);
                m_bSayGalvangar = false;
            }
        }

        // GlobalCD non ecoule.
        if (m_uiGlobalCooldown > diff)
            m_uiGlobalCooldown -= diff;
        else
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_uiGlobalCooldown = 1;
            else
                m_uiGlobalCooldown = 0;
        }

        if (m_uiIsInWhirlwind_Timer == 0)
        {
            if (m_creature->HasUnitState(UNIT_STAT_ROOT))
                m_creature->ClearUnitState(UNIT_STAT_ROOT);
        }
        else
        {
            if (!m_creature->HasUnitState(UNIT_STAT_ROOT))
                m_creature->AddUnitState(UNIT_STAT_ROOT);
        }

        // SPELL_WHIRLWIND_GAL
        if (m_uiWhirlwind_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                uint32 uiTargetInRangeCount = 0;
                ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
                for (const auto i : tList)
                {
                    if (ObjectGuid uiTargetGuid = i->getUnitGuid())
                    {
                        if (Unit* pTarget = m_creature->GetMap()->GetUnit(uiTargetGuid))
                        {
                            if (m_creature->IsWithinDistInMap(pTarget, 6.0f))
                                uiTargetInRangeCount++;
                        }
                    }
                }
                if (urand(0, 1000) > (1000 * (3 / (uiTargetInRangeCount + 1))))
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WHIRLWIND_GAL) == CAST_OK)
                    {
                        m_uiWhirlwind_Timer = urand(10000, 16000);
                        m_uiIsInWhirlwind_Timer = 2000;
                        m_uiGlobalCooldown = 2000;
                    }
                }
                else
                    m_uiWhirlwind_Timer = 1000;
            }
        }
        else
            m_uiWhirlwind_Timer -= diff;

        // SPELL_FRIGHTSHOUT
        if (m_uiFrighteningShout_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FRIGHTSHOUT) == CAST_OK)
                {
                    m_uiFrighteningShout_Timer = urand(24000, 32000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiFrighteningShout_Timer -= diff;

        // SPELL_CLEAVE
        if (m_uiCleave_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                {
                    m_uiCleave_Timer = urand(7000, 9000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiCleave_Timer -= diff;

        // SPELL_MORTALSTRIKE
        if (m_uiMortalStrike_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTALSTRIKE) == CAST_OK)
                {
                    m_uiMortalStrike_Timer = urand(9000, 13000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiMortalStrike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_Galvangar(Creature* m_creature)
{
    return new npc_GalvangarAI(m_creature);
}

/*######
## npc_WarMaster
######*/

// #define NPC_WARMASTER   14762 to 14769 (ally)

enum
{
    SPELL_CHARGE       = 22911,
    SPELL_CLEAVE_WM    = 20684,
    SPELL_DEMORALSHOUT = 23511,
    SPELL_ENRAGE_WM    = 8599,
    SPELL_WHIRLWIND_WM = 13736
};

struct npc_WarMasterAI : public ScriptedAI
{
    npc_WarMasterAI(Creature* pCreature) : ScriptedAI(pCreature), m_isKilled(false)
    {
        // m_pInstance = (ScriptedInstance*)m_creature->GetInstanceData();
        Reset();
    }

    // ScriptedInstance* m_pInstance; // remplacer par BG?
    uint32 m_uiGlobalCooldown;
    uint32 m_uiCharge_Timer;
    uint32 m_uiCleave_Timer;
    uint32 m_uiShout_Timer;
    uint32 m_uiWhirlwind_Timer;
    uint32 m_uiIsInWhirlwind_Timer;
    uint32 m_uiEnrage_Timer;
    bool   m_isKilled;

    void Reset() override
    {
        m_uiGlobalCooldown  = 0;
        m_uiCharge_Timer    = 0;
        m_uiCleave_Timer    = 8000;
        m_uiShout_Timer     = 4000;
        m_uiWhirlwind_Timer = 12000;
        m_uiEnrage_Timer    = 0;
        m_uiIsInWhirlwind_Timer = 0;
        m_creature->ClearUnitState(UNIT_STAT_ROOT);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->GetVictim())
            return;

        if (pWho->GetDistance(m_creature) < 22.0f && m_creature->IsValidAttackTarget(pWho))
        {
            AttackStart(pWho);
            if (DoCastSpellIfCan(pWho, SPELL_CHARGE) == CAST_OK)
                m_uiCharge_Timer = 12000;
        }
    }

    void JustDied(Unit* killer) override
    {
        m_isKilled = true;
    }

    void UpdateAI(uint32 const diff) override
    {
        /* Prevents the following bug:
         *  The war master is killed
         *  The linked objective is tagged and then defended
         *  The war master respawns
         */
        if (m_isKilled)
        {
            m_creature->DeleteLater();
            return;
        }
        if (m_uiIsInWhirlwind_Timer < diff)
            m_uiIsInWhirlwind_Timer = 0;
        else
            m_uiIsInWhirlwind_Timer -= diff;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // GlobalCD non ecoule.
        if (m_uiGlobalCooldown > diff)
            m_uiGlobalCooldown -= diff;
        else
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_uiGlobalCooldown = 1;
            else
                m_uiGlobalCooldown = 0;
        }

        if (!m_uiIsInWhirlwind_Timer)
            m_creature->ClearUnitState(UNIT_STAT_ROOT);
        else
            m_creature->AddUnitState(UNIT_STAT_ROOT);

        // SPELL_WHIRLWIND_WM
        if (m_uiWhirlwind_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_WHIRLWIND_WM) == CAST_OK)
                {
                    if (m_uiIsInWhirlwind_Timer < diff)
                    {
                        m_uiIsInWhirlwind_Timer = 4000;
                        m_uiWhirlwind_Timer = 2000;
                    }
                    else
                        m_uiWhirlwind_Timer = urand(11000, 13000);
                    m_uiGlobalCooldown = 2000;
                }
            }
        }
        else
            m_uiWhirlwind_Timer -= diff;

        // SPELL_ENRAGE_WM
        if (m_uiEnrage_Timer < diff)
        {
            if (!m_uiGlobalCooldown && (m_creature->GetHealthPercent() <= 30.0f))
            {
                if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE_WM) == CAST_OK)
                {
                    m_uiEnrage_Timer = 120000;
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiEnrage_Timer -= diff;

        // CHARGE
        if (m_uiCharge_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (Unit* pTarget = m_creature->GetVictimInRange(8.0f, 25.0f))
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_CHARGE) == CAST_OK)
                    {
                        m_uiCharge_Timer = urand(12000, 18000);
                        m_uiGlobalCooldown = 250;
                    }
                }
                else
                    m_uiCharge_Timer = urand(5000, 10000);
            }
        }
        else
            m_uiCharge_Timer -= diff;

        // SPELL_CLEAVE_WM
        if (m_uiCleave_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_CLEAVE_WM) == CAST_OK)
                {
                    m_uiCleave_Timer = urand(8000, 10000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiCleave_Timer -= diff;

        // SPELL_DEMORALSHOUT
        if (m_uiShout_Timer < diff)
        {
            if (!m_uiGlobalCooldown)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_DEMORALSHOUT) == CAST_OK)
                {
                    m_uiShout_Timer = urand(14000, 20000);
                    m_uiGlobalCooldown = 1000;
                }
            }
        }
        else
            m_uiShout_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_WarMaster(Creature* m_creature)
{
    return new npc_WarMasterAI(m_creature);
}

/*######
## npc_AlteracBowman
######*/

enum
{
    NPC_STROMPIKEBOWMAN     = 13358,
    NPC_FROSTWOLFBOWMAN     = 13359,
    SPELL_SHOOT             = 22121,
    SPELL_ROOT_SELF         = 17507,
    SHOOT_SPEED             = 1700,
};

struct npc_AlteracBowmanAI : public ScriptedAI
{
    npc_AlteracBowmanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_creature->AddAura(SPELL_ROOT_SELF, ADD_AURA_PERMANENT);
        SetCombatMovement(false);
        Reset();
    }

    uint32 m_uiShoot_Timer;
    uint32 m_uiReset_Timer;

    void JustReachedHome() override
    {
        m_creature->AddAura(SPELL_ROOT_SELF, ADD_AURA_PERMANENT);
    }
    void Reset() override
    {
        m_uiShoot_Timer = 100;
        m_uiReset_Timer = 3000;
    }

    bool TargetWithinShootRange(Unit* pTarget)
    {
        return m_creature->GetDistance(pTarget) < 80.0f && m_creature->IsWithinLOSInMap(pTarget);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (pWho && !m_creature->GetVictim() && m_creature->IsValidAttackTarget(pWho) && TargetWithinShootRange(pWho))
            AttackStart(pWho);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->IsInEvadeMode() && (!m_creature->GetVictim() || !TargetWithinShootRange(m_creature->GetVictim())))
        {
            if (m_uiReset_Timer < diff)
            {
                m_uiReset_Timer = 3000;
                EnterEvadeMode();
                return;
            }
            else
                m_uiReset_Timer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiShoot_Timer < diff)
        {
            if (!m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHOOT) == CAST_OK)
                    m_uiShoot_Timer = SHOOT_SPEED;
            }
        }
        else
            m_uiShoot_Timer -= diff;

        DoMeleeAttackIfReady();
    }
    void GetAIInformation(ChatHandler& reader) override
    {
        reader.PSendSysMessage("npc_AlteracBowmanAI::GetAIInformation");
        reader.PSendSysMessage("victim: %s", m_creature->GetVictim() ? m_creature->GetVictim()->GetName() : "nullptr");
        reader.PSendSysMessage("evade_mode: %u", m_creature->IsInEvadeMode());
        ScriptedAI::GetAIInformation(reader);
    }
};

CreatureAI* GetAI_npc_AlteracBowman(Creature* m_creature)
{
    return new npc_AlteracBowmanAI(m_creature);
}

/*######
## npc_AlteracDardosh
######*/

struct npc_AlteracDardoshAI : public ScriptedAI
{
    npc_AlteracDardoshAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        // m_pInstance = (ScriptedInstance*)m_creature->GetInstanceData();
        Reset();
    }

    // ScriptedInstance* m_pInstance; // remplacer par BG?
    uint32 m_uiCleave_Timer;

    void Reset() override
    {
        m_uiCleave_Timer = 1000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiCleave_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleave_Timer = 3000;
        }
        else
            m_uiCleave_Timer -= diff;

        DoMeleeAttackIfReady();

    }
};

CreatureAI* GetAI_npc_AlteracDardosh(Creature* m_creature)
{
    return new npc_AlteracDardoshAI(m_creature);
}

/*********************************************
 *            UPDATED ALTERAC                *
 *********************************************/

enum
{
    POINT_LAST_POINT    = 0xFFFFFF
};

enum
{
    QUEST_TAME_HORDE                = 7001,
    QUEST_TAME_ALLIANCE             = 7027,

    FROSTWOLF_MUZZLE                = 17626,
    STORMPIKE_TRAINING_COLLAR       = 17689,

    NPC_TAME_MASTER_HORDE           = 13616,
    NPC_TAME_MASTER_ALLIANCE        = 13617,

    NPC_RAM                         = 10990,
    NPC_WOLF                        = 10981,
    NPC_RAM_TAMED                   = 10989,
    NPC_WOLF_TAMED                  = 10985,

    SPELL_COLLAR_USING_ALLIANCE     = 21866,
    SPELL_TAME_BEAST_PLAYER_ALLIANCE = 21867,
    SPELL_COLLAR_USING_HORDE        = 21794,
    SPELL_TAME_BEAST_PLAYER_HORDE   = 21795,

    SPELL_TAME_OWNED_BY_PLAYER      = 21869,
    SPELL_PLAYER_OWNED_BY_TAMED     = 21872,
    SPELL_TAME_BEAST_GOSSIP         = 18362
};

/** Give a Muzzle / Collar to the player if he don't have one */
bool GossipHello_AV_npc_ram_wolf(Player* pPlayer, Creature* pCreature)
{
    bool isAllowedToGetItem = true;
    uint32 entryCreature;

    /** Show quest menu */
    pPlayer->PrepareQuestMenu(pCreature->GetGUID());
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());

    /** Select corresponding item depending on NPC faction */
    uint32 itemId = 0;
    if (pCreature->GetEntry() == NPC_TAME_MASTER_HORDE)
        itemId = FROSTWOLF_MUZZLE;
    else if (pCreature->GetEntry() == NPC_TAME_MASTER_ALLIANCE)
        itemId = STORMPIKE_TRAINING_COLLAR;

    /** Prepare Quest and Creature ID depending on the NPC faction */
    if (pCreature->GetEntry() == NPC_TAME_MASTER_HORDE)
        entryCreature = NPC_WOLF_TAMED;
    else if (pCreature->GetEntry() == NPC_TAME_MASTER_ALLIANCE)
        entryCreature = NPC_RAM_TAMED;
    else
        return true;

    /** Get a list of all tamed created on 100 meters radius around NPC */
    std::list<Creature*> ramWolfTamedList;
    GetCreatureListWithEntryInGrid(ramWolfTamedList, pCreature, entryCreature, 250.0f);

    for (const auto& it : ramWolfTamedList)
    {
        /** Check if the Tamed beast has a player as owner */
        ObjectGuid playerOwner(HIGHGUID_PLAYER, it->AI()->GetData(0));
        if (Player* player = pCreature->GetMap()->GetPlayer(playerOwner))
            if (player->GetGUID() == pPlayer->GetGUID())
                isAllowedToGetItem = false;
    }

    /** Give the corresponding item to the player if he don't have one already */
    if (!pPlayer->HasItemCount(itemId, 1, true) && isAllowedToGetItem)
    {
        uint32 noSpaceForCount = 0;
        ItemPosCountVec dest;
        uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1, &noSpaceForCount);

        if (msg == EQUIP_ERR_OK)
        {
            Item* pItem = pPlayer->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(5060));
            pPlayer->SendNewItem(pItem, 1, true, false);
        }
    }
    return true;
}

struct npc_ram_wolf_tamedAI : public ScriptedAI
{
    npc_ram_wolf_tamedAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    ObjectGuid playerGuid;

    uint32 GetData(uint32) override
    {
        return playerGuid.GetCounter();
    }

    void Reset() override
    {
    }

    void ResetEvent()
    {
        Reset();
        m_creature->DisappearAndDie();
    }

    void SpellHit(Unit* caster, SpellEntry const* spell) override
    {
        if (spell->Id == SPELL_COLLAR_USING_ALLIANCE || spell->Id == SPELL_COLLAR_USING_HORDE)
            AttackStart(caster);
        else if (spell->Id == SPELL_TAME_BEAST_PLAYER_ALLIANCE || spell->Id == SPELL_TAME_BEAST_PLAYER_HORDE)
        {

            EnterEvadeMode();
            m_creature->SetFactionTemplateId(35);

            /** Link the tamed creature to the player it shall follow */
            m_creature->CastSpell(m_creature, SPELL_TAME_OWNED_BY_PLAYER, true);
            m_creature->CastSpell(caster, SPELL_PLAYER_OWNED_BY_TAMED, true);

            /** Update creature for tamed one */
            if (m_creature->GetEntry() == NPC_RAM)
                m_creature->UpdateEntry(NPC_RAM_TAMED);
            else if (m_creature->GetEntry() == NPC_WOLF)
                m_creature->UpdateEntry(NPC_WOLF_TAMED);

            /** Creature now need to follow the player everywhere */
            if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
                m_creature->GetMotionMaster()->MoveIdle();

            /** Set owner information, specific to Alterac Valley Tamed Beast */
            playerGuid = caster->GetObjectGuid();


            m_creature->GetMotionMaster()->MoveFollow(caster, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

            /** Set owner information, specific to Alterac Valley Tamed Beast */
            //            playerGuid = caster->GetObjectGuid();
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        /** The tamed beast musn't attack */
        if (m_creature->GetEntry() == NPC_RAM_TAMED || m_creature->GetEntry() == NPC_WOLF_TAMED)
        {
            /** If the player died, remove the tamed beast */
            ObjectGuid playerOwner(HIGHGUID_PLAYER, m_creature->AI()->GetData(0));
            if (Player* player = m_creature->GetMap()->GetPlayer(playerOwner))
            {
                if (player->IsDead())
                {
                    /** Make the tamed beast disappears, respawn in 2min30 */
                    m_creature->SetRespawnDelay(180);
                    m_creature->SetDeathState(JUST_DIED);

                    /** Change back entry to standard beast */
                    if (m_creature->GetEntry() == NPC_RAM_TAMED)
                        m_creature->UpdateEntry(NPC_RAM);
                    else if (m_creature->GetEntry() == NPC_WOLF_TAMED)
                        m_creature->UpdateEntry(NPC_WOLF);

                    m_creature->RemoveCorpse();
                }
            }
            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

struct RamWolfMasterAI : public ScriptedAI
{
    RamWolfMasterAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        /** Prepare Quest and Creature ID depending on the NPC faction */
        if (m_creature->GetEntry() == NPC_TAME_MASTER_HORDE)
        {
            m_uiEntryCreature = NPC_WOLF_TAMED;
            m_uiEntryQuest    = QUEST_TAME_HORDE;
        }
        else if (m_creature->GetEntry() == NPC_TAME_MASTER_ALLIANCE)
        {
            m_uiEntryCreature = NPC_RAM_TAMED;
            m_uiEntryQuest    = QUEST_TAME_ALLIANCE;
        }
        Reset();
    }

    uint32 m_uiEntryCreature;
    uint32 m_uiEntryQuest;
    uint32 m_uiCheckTimer;

    void Reset() override
    {
        m_uiCheckTimer = 200;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        /** Check if Tamed beast are in 10 meters radius */
        if (m_uiCheckTimer < uiDiff)
        {
            if (m_uiEntryCreature != 0)
            {
                /** Get a list of all tamed created on 10 meters radius around NPC */
                std::list<Creature*> ramWolfTamedList;
                GetCreatureListWithEntryInGrid(ramWolfTamedList, m_creature, m_uiEntryCreature, 10.0f);

                for (const auto& it : ramWolfTamedList)
                {
                    /** Check if the Tamed beast has a player as owner */
                    ObjectGuid playerOwner(HIGHGUID_PLAYER, it->AI()->GetData(0));
                    if (Player* player = m_creature->GetMap()->GetPlayer(playerOwner))
                    {
                        /** If the quest isn't completed, complete it */
                        player->GroupEventHappens(m_uiEntryQuest, it);
                        player->SendQuestCompleteEvent(m_uiEntryQuest); //Visual event doesn't validate the quest
                        player->SetQuestStatus(m_uiEntryQuest, QUEST_STATUS_COMPLETE);

                        /** Make the tamed beast disappears, respawn in 2min30 */
                        it->SetRespawnDelay(180);
                        it->SetDeathState(JUST_DIED);

                        /** Change back entry to standard beast */
                        if (it->GetEntry() == NPC_RAM_TAMED)
                            it->UpdateEntry(NPC_RAM);
                        else if (it->GetEntry() == NPC_WOLF_TAMED)
                            it->UpdateEntry(NPC_WOLF);

                        it->RemoveCorpse();
                    }
                }
                ramWolfTamedList.clear();
            }
            m_uiCheckTimer = 200;
        }
        else
            m_uiCheckTimer -= uiDiff;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

/***************************************************************/
/** CHALLENGE ALTERAC INVOCATION : AERIAL, CAVALRY, WORLD BOSS */
/***************************************************************/

enum
{
    /** HORDE */
    ITEM_STORMPIKE_BLOOD_HORDE      = 17306, /** WORLD BOSS ASSAULT */
    ITEM_FROSTWOLF_HIDE             = 17643, /** CAVALRY ASSAULT    */
    QUEST_TAMED_FROSTWOLVES         =  7001, /** CAVALRY ASSAULT    */
    ITEM_STORMPIKE_SOLDIER_FLESH    = 17326, /** AERIAL ASSAULT     */
    ITEM_STORMPIKE_LIEUTENANT_FLESH = 17327, /** AERIAL ASSAULT     */
    ITEM_STORMPIKE_COMMANDER_FLESH  = 17328, /** AERIAL ASSAULT     */
    ITEM_IRONDEEP_SUPPLIES          = 17522, /** GROUND ASSAULT     */
    ITEM_COLDTOOTH_SUPPLIES         = 17542, /** GROUND ASSAULT     */
    ID_REPUTATION_FROSTWOLF         =   729,
    ITEM_BEACON_MULVERICK           = 17323,
    ITEM_BEACON_GUSE                = 17324,
    ITEM_BEACON_JETZOR              = 17325,
    ITEM_ASSAULT_ORDER_FROSTWOLF    = 17442,
    QUEST_TROOPS_ORDER_H            = 6901,

    /** ALLIANCE */
    ITEM_STORM_CRYSTAL              = 17423, /** WORLD BOSS ASSAULT */
    ITEM_ALTERAC_RAM_HIDE           = 17642, /** CAVALRY ASSAULT    */
    QUEST_TAMED_RAMS                =  7027, /** CAVALRY ASSAULT    */
    ITEM_FROSTWOLF_SOLDIER_MEDAL    = 17502, /** AERIAL ASSAULT     */
    ITEM_FROSTWOLF_LIEUTENANT_MEDAL = 17503, /** AERIAL ASSAULT     */
    ITEM_FROSTWOLF_COMMANDER_MEDAL  = 17504, /** AERIAL ASSAULT     */
    ID_REPUTATION_STORMPIKE         =   730,
    ITEM_BEACON_ICHMAN              = 17505,
    ITEM_BEACON_VIPORE              = 17506,
    ITEM_BEACON_SLIDORE             = 17507,
    ITEM_ASSAULT_ORDER_STORMPIKE    = 17353,
    QUEST_TROOPS_ORDER_A            = 6846,

    AV_NPC_ENTRY_MULVERICK   = 13181,
    AV_NPC_ENTRY_JEZTOR      = 13180,
    AV_NPC_ENTRY_GUSE        = 13179,
    AV_NPC_ENTRY_REGZAR      = 13176,
    AV_NPC_ENTRY_MURGOT      = 13257,
    AV_NPC_ENTRY_SLIDORE     = 13438,
    AV_NPC_ENTRY_ICHMAN      = 13437,
    AV_NPC_ENTRY_VIPORE      = 13439,
    AV_NPC_WARRIDER_MULVERICK = 14945,
    AV_NPC_WARRIDER_JEZTOR   = 14944,
    AV_NPC_WARRIDER_GUSE     = 14943,
    AV_NPC_WARRIDER_SLIDORE  = 14946,
    AV_NPC_WARRIDER_ICHMAN   = 14947,
    AV_NPC_WARRIDER_VIPORE   = 14948,
    AV_NPC_WARRIDER          = 13178,
    AV_NPC_AERIEGRYPHON      = 13161,

    AV_NPC_WOLFRIDER         = 13440,
    AV_NPC_WOLFRIDER_CMD     = 13441,
    AV_NPC_RAMRIDER          = 13576,
    AV_NPC_RAMRIDER_CMD      = 13577,

    AV_NPC_QUARTERMASTER     = 12097,
    AV_NPC_WARMASTER_CMD     = 13449,
    AV_NPC_FROSTWOLF_REAVER  = 13528,
    AV_NPC_SEASONED_REAVER   = 13529,
    AV_NPC_VETERAN_REAVER    = 13530,
    AV_NPC_CHAMPION_REAVER   = 13531,

    AV_NPC_QUARTERMASTER_A   = 12096,
    AV_NPC_MARSHAL_TERAVAINE = 13446,
    AV_NPC_STORMPIKE_COMMANDO = 13524,
    AV_NPC_SEASONED_COMMANDO = 13525,
    AV_NPC_VETERAN_COMMANDO  = 13526,
    AV_NPC_CHAMPION_COMMANDO = 13527,

    /** World Boss event */
    AV_NPC_PRIMALIST_THURLOGA = 13236,
    AV_NPC_FROSTWOLF_SHAMAN  = 13284,
    AV_INVOCATION_SPELL      = 11206,
    AV_NPC_ARCHDRUID_RENFERAL = 13442,
    AV_NPC_DRUID_OF_THE_GROVE = 13443,

    OBJECT_WB_A_INVOCATION = 178670,
    OBJECT_WB_H_INVOCATION = 178465,
};

/********GENERIC AI EVENT *******/
enum
{
    SPELL_AV_INVISIBLE       = 24699,
    SPELL_AV_VISUALTRANSFORM = 24085,
    WAR_RIDER_DISPLAY_ID     = 11012,
    AERIAL_GRYPHON_ID        = 1148,
};

/*******TROOPS********/
struct AV_NpcEventTroopsAI : public npc_escortAI
{
    AV_NpcEventTroopsAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        isLeaderDead    = false;
        leaderDie_Timer = 600000;//600000;
        isAggro         = false;
        isOnHisOwn      = false;
        Reset();
    }

    bool   isAggro;
    bool   isOnHisOwn;
    bool   isLeaderDead;
    uint32 Point;
    uint32 leaderDie_Timer;

    void Reset() override
    {
        /** Use the corresponding mount depending on the NPC */
        if (m_creature->GetEntry() == AV_NPC_RAMRIDER)
            m_creature->Mount(2786);
        else if (m_creature->GetEntry() == AV_NPC_WOLFRIDER)
            m_creature->Mount(10278);

        if (m_creature->GetRespawnDelay() == 432000  && !isOnHisOwn)
        {
            if (AV_NpcEventTroopsAI* pEscortAI = dynamic_cast<AV_NpcEventTroopsAI*>(m_creature->AI()))
            {
                if (!pEscortAI->HasEscortState(STATE_ESCORT_ESCORTING))
                {
                    pEscortAI->Start(true, 0, nullptr, false);
                    pEscortAI->setCurrentWP(getCurrentWP());
                    isOnHisOwn = true;
                }
            }
        }
        else if (isOnHisOwn)
            SetEscortPaused(false);

    }

    void Aggro(Unit* pWho) override
    {
        /** Cavalry dismount in case of aggro situation */
        if (m_creature->GetEntry() == AV_NPC_RAMRIDER ||
            m_creature->GetEntry() == AV_NPC_WOLFRIDER)
            m_creature->Unmount();

        /** Stop escort AI once aggro is detected */
        isAggro = true;
        SetEscortPaused(true);
    }

    void WaypointReached(uint32 i) override
    {
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        uint32 commander_id = 0;

        if (m_creature->GetEntry() == AV_NPC_WOLFRIDER)
            commander_id = AV_NPC_WOLFRIDER_CMD;
        else if (m_creature->GetEntry() == AV_NPC_RAMRIDER)
            commander_id = AV_NPC_RAMRIDER_CMD;

        if (!isLeaderDead && commander_id != 0)
        {
            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, commander_id, 200.0f);
            for (const auto& it : m_RamRiderList)
                if (it->IsDead())
                    isLeaderDead = true;
            m_RamRiderList.clear();
        }
        else if (isLeaderDead)
        {
            if (leaderDie_Timer < uiDiff)
            {
                m_creature->DisappearAndDie();
            }
            else
                leaderDie_Timer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

enum
{
    SAY_KORRAK_SPAWN = 9038
};

/** Korrak should appear after 2 hours of battle */
class npc_korrak_the_bloodragerAI: public ScriptedAI
{
    public:
        npc_korrak_the_bloodragerAI(Creature* c) : ScriptedAI(c), m_appeared(false)
        {
            Reset();
            m_yell = false;
        }
        void Reset() override
        {
        }
        void UpdateAI(uint32 const diff) override
        {
            if (!m_appeared)
            {
                m_creature->DisappearAndDie();
                m_creature->SetRespawnTime(7200);
                m_appeared = true;
                return;
            }
            else
            {
                if (!m_yell)
                {
                    DoScriptText(SAY_KORRAK_SPAWN, m_creature);
                    m_yell = true;
                }
            }
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
                return;
            DoMeleeAttackIfReady();
        }
    protected:
        bool        m_appeared;
        bool        m_yell;
};

enum
{
    SPELL_CHAIN_LIGHTNING  =   16006,
    SPELL_EARTHBIND_TOTEM  =   15786,
    SPELL_FLAME_SHOCK      =   15616,
    SPELL_LIGHNING_BOLT    =   15234,
    SPELL_HEALING_WAVE     =   12492,
    SPELL_ENTANGLING_ROOTS =  22127,
    SPELL_STARFIRE         =  21668,
    SPELL_THORNS           =  22128,
    SPELL_REJUVENATION     =  15981,

    SAY_LOKHOLAR_SPAWNED   = 8626,
    SAY_PRIMALIST_THURLOGA = 8632,
    SAY_ARCHDRUID_RENFERAL = 8735,
    SAY_WOLFRIDER_CMD      = 8890,
    SAY_WARCRY_HORDE       = 8891,
    SAY_RAMRIDER_CMD       = 8906,
    SAY_WARCRY_ALIANCE     = 8908
};

struct AV_NpcEventAI : public npc_escortAI
{
    /** Specific AI for AV_NPC_PRIMALIST_THURLOGA */
    uint32 m_uiChainLightning_Timer;
    uint32 m_uiEarthbindTotem_Timer;
    uint32 m_uiFlameShock_Timer;
    uint32 m_uiHealingWave_Timer;
    uint32 m_uiLightningBolt_Timer;
    bool   m_bThurlogaBoss;
    bool   m_bRenferalBoss;

    /** Specific AI for AV_NPC_ARCHDRUID_RENFERAL */
    uint32 m_uiEntanglingRoots_Timer;
    uint32 m_uiStarFire_Timer;
    uint32 m_uiRejuvenation_Timer;

    uint32 m_uiTransform_Timer;
    uint32 m_uiDisappear_Timer;
    bool   b_isTransformed;
    bool   b_isCavalrySpawned;
    bool   b_isNPCMovedToChannelingPointWB;
    bool   b_isNPCStartedMovingToChannelingPointWB;
    uint32 m_faction_id;
    bool   b_isTroopsSpawned;
    bool   isAggro;
    bool   isGobSummoned;
    bool   b_isDead;
    bool   b_isSpeechDone;
    uint32 Event_Timer;
    uint32 Point;
    char   sMessage[200];
    bool    m_bWarRiderSummoned;
    uint32 m_uiDespawn_Timer;
    float  av_x;
    float  av_y;
    float  av_z;

    AV_NpcEventAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_bRenferalBoss                         = false;
        m_bThurlogaBoss                         = false;
        b_isSpeechDone                          = false;
        isAggro                                 = false;
        isGobSummoned                           = false;
        b_isNPCMovedToChannelingPointWB         = false;
        b_isNPCStartedMovingToChannelingPointWB = false;
        m_bWarRiderSummoned = false;
        m_uiDespawn_Timer = 0;
        b_isDead = false;
        av_x = m_creature->GetPositionX();
        av_y = m_creature->GetPositionY();
        av_z = m_creature->GetPositionZ();

        /** Re initialize escort state */
        //SetEscortPaused(false);
        //AddEscortState(STATE_ESCORT_NONE);
        Reset();
    }

    void checkTroopsStatus(uint32 const uiDiff, uint32 creature_entry)
    {
        if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(m_creature->GetMap()))
        {
            if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
            {
                if (bg->getPlayerGoStatus(BG_TEAM_HORDE, BG_AV_GROUND_ASSAULT) && creature_entry == AV_NPC_QUARTERMASTER)
                {
                    if (!b_isTroopsSpawned)
                    {
                        b_isTroopsSpawned = true;
                        bg->setPlayerGoStatus(BG_TEAM_HORDE, BG_AV_GROUND_ASSAULT, false);
                        m_creature->SummonCreature(AV_NPC_WARMASTER_CMD,
                                                   -470.38f, -51.84f, 41, 5.93f, TEMPSUMMON_CORPSE_DESPAWN, 10000);

                        uint32 m_uiRessourcesLevel = bg->getReinforcementLevelGroundUnit(BG_TEAM_HORDE);
                        uint32 m_uiTroopsType;
                        switch (m_uiRessourcesLevel)
                        {
                            case AV_NPC_BASIC:
                                m_uiTroopsType = AV_NPC_FROSTWOLF_REAVER;
                                break;
                            case AV_NPC_SEASONED:
                                m_uiTroopsType = AV_NPC_SEASONED_REAVER;
                                break;
                            case AV_NPC_VETERAN:
                                m_uiTroopsType = AV_NPC_VETERAN_REAVER;
                                break;
                            case AV_NPC_CHAMPION:
                                m_uiTroopsType = AV_NPC_CHAMPION_REAVER;
                                break;
                            default:
                                m_uiTroopsType = AV_NPC_FROSTWOLF_REAVER;
                                break;
                        }

                        /** Formula to spawn corresponding NPC */
                        float m_uiX = -472.2f;
                        float m_uiY = -48.4f;
                        float m_uiO = 5.93f;
                        int32 m_uiCoeff = 0;
                        for (int i = 0; i < 10; i++)
                        {
                            if (i == 5)
                            {
                                m_uiX = -474.8f;
                                m_uiY = -48.7f;
                                m_uiCoeff = 0;
                            }
                            m_creature->SummonCreature(m_uiTroopsType,
                                                       m_uiX - 0.4f * m_uiCoeff,
                                                       m_uiY - 1.6f * m_uiCoeff,
                                                       41.3f,
                                                       m_uiO,
                                                       TEMPSUMMON_CORPSE_DESPAWN, 10000);
                            m_uiCoeff = m_uiCoeff + 1;
                        }
                    }
                }
                else if (bg->getPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_GROUND_ASSAULT) && creature_entry == AV_NPC_QUARTERMASTER_A)
                {
                    if (!b_isTroopsSpawned)
                    {
                        b_isTroopsSpawned = true;
                        bg->setPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_GROUND_ASSAULT, false);
                        m_creature->SummonCreature(AV_NPC_MARSHAL_TERAVAINE,
                                                   -243.75f, -431.32f, 20, 2.59f, TEMPSUMMON_CORPSE_DESPAWN, 10000);

                        uint32 m_uiRessourcesLevel = bg->getReinforcementLevelGroundUnit(BG_TEAM_ALLIANCE);
                        uint32 m_uiTroopsType = AV_NPC_STORMPIKE_COMMANDO;
                        switch (m_uiRessourcesLevel)
                        {
                            case AV_NPC_SEASONED:
                                m_uiTroopsType = AV_NPC_SEASONED_COMMANDO;
                                break;
                            case AV_NPC_VETERAN:
                                m_uiTroopsType = AV_NPC_VETERAN_COMMANDO;
                                break;
                            case AV_NPC_CHAMPION:
                                m_uiTroopsType = AV_NPC_CHAMPION_COMMANDO;
                                break;
                        }

                        /** Formula to spawn corresponding NPC */
                        float x = -240.9f;
                        float y = -431.11f;
                        float o = 2.59f;
                        for (int i = 0; i < 10; i++)
                        {
                            if (i == 5)
                            {
                                x = -238.35f;
                                y = -432.42f;
                            }

                            m_creature->SummonCreature(m_uiTroopsType,
                                                       x - i % 5,
                                                       y - i % 5,
                                                       20.2f,
                                                       o,
                                                       TEMPSUMMON_CORPSE_DESPAWN, 10000);
                        }
                    }
                }
            }
        }
    }

    void checkCavalryStatus(uint32 const uiDiff, uint32 creature_entry)
    {
        if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(m_creature->GetMap()))
        {
            if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
            {
                if (bg->getPlayerGoStatus(BG_TEAM_HORDE, BG_AV_CAVALRY_ASSAULT) && creature_entry == AV_NPC_WOLFRIDER_CMD)
                {
                    if (!b_isCavalrySpawned)
                    {
                        b_isCavalrySpawned = true;
                        bg->setPlayerGoStatus(BG_TEAM_HORDE, BG_AV_CAVALRY_ASSAULT, false);

                        /** Formula to spawn corresponding NPC */
                        float x = -1230;
                        float y = -611;
                        float o = 5.4f;
                        for (int i = 0; i < 8; i++)
                        {
                            if (i == 4)
                            {
                                x = -1223;
                                y = -619;
                                o = 2.22f;
                            }
                            m_creature->SummonCreature(AV_NPC_WOLFRIDER,
                                                       x - 4 * (i % 5),
                                                       y - 3 * (i % 5),
                                                       54,
                                                       o,
                                                       TEMPSUMMON_CORPSE_DESPAWN, 10000);
                        }
                    }
                }
                if (bg->getPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_CAVALRY_ASSAULT) && creature_entry == AV_NPC_RAMRIDER_CMD)
                {
                    if (!b_isCavalrySpawned)
                    {
                        b_isCavalrySpawned = true;
                        bg->setPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_CAVALRY_ASSAULT, false);

                        /** Formula to spawn corresponding NPC */
                        float x = 610;
                        float y = -35;
                        float o = 0.6f;
                        for (int i = 0; i < 8; i++)
                        {
                            if (i == 4)
                            {
                                x = 607;
                                y = -37;
                            }
                            m_creature->SummonCreature(AV_NPC_RAMRIDER,
                                                       x + 2 * (i % 5),
                                                       y - 3 * (i % 5),
                                                       45,
                                                       o,
                                                       TEMPSUMMON_CORPSE_DESPAWN, 10000);
                        }
                    }
                }
            }
        }
    }

    void checkAerialStatus(uint32 const uiDiff, uint32 creature_entry)
    {
        if (m_bWarRiderSummoned)
            return;
        if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(m_creature->GetMap()))
        {
            if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
            {
                if ((bg->getPlayerGoStatus(BG_TEAM_HORDE, BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER) && creature_entry == AV_NPC_ENTRY_GUSE) ||
                    (bg->getPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER) && creature_entry == AV_NPC_ENTRY_SLIDORE) ||
                    (bg->getPlayerGoStatus(BG_TEAM_HORDE, BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT) && creature_entry == AV_NPC_ENTRY_JEZTOR) ||
                    (bg->getPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT) && creature_entry == AV_NPC_ENTRY_VIPORE) ||
                    (bg->getPlayerGoStatus(BG_TEAM_HORDE, BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER) && creature_entry == AV_NPC_ENTRY_MULVERICK) ||
                    (bg->getPlayerGoStatus(BG_TEAM_ALLIANCE, BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER) && creature_entry == AV_NPC_ENTRY_ICHMAN))
                {
                    if (m_uiTransform_Timer < uiDiff)
                    {
                        if (!b_isTransformed)
                        {
                            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            b_isTransformed = true;

                            m_creature->SetDisplayId(WAR_RIDER_DISPLAY_ID);
                            if (creature_entry == AV_NPC_ENTRY_GUSE ||
                                creature_entry == AV_NPC_ENTRY_JEZTOR ||
                                creature_entry == AV_NPC_ENTRY_MULVERICK)
                                m_creature->SetDisplayId(WAR_RIDER_DISPLAY_ID);
                            else
                                m_creature->SetDisplayId(AERIAL_GRYPHON_ID);
                            m_creature->SetFly(true);
                            m_creature->SetWalk(false);
                            if (IsCombatMovementEnabled())
                                SetCombatMovement(false);

                            DoCastSpellIfCan(m_creature, SPELL_AV_VISUALTRANSFORM);
                            m_creature->GetMotionMaster()->MovePoint(0,
                                    m_creature->GetPositionX(),
                                    m_creature->GetPositionY(),
                                    m_creature->GetPositionZ() + 30.0f);
                        }
                    }
                    else
                        m_uiTransform_Timer -= uiDiff;

                    if (b_isTransformed)
                    {
                        if (m_uiDisappear_Timer < uiDiff)
                        {
                            m_creature->AddAura(SPELL_AV_INVISIBLE, ADD_AURA_PERMANENT);
                            m_bWarRiderSummoned = true;
                            uint32 summonEntry = 0;
                            switch (creature_entry)
                            {
                                case AV_NPC_ENTRY_MULVERICK:
                                    summonEntry = AV_NPC_WARRIDER_MULVERICK;
                                    break;
                                case AV_NPC_ENTRY_GUSE:
                                    summonEntry = AV_NPC_WARRIDER_GUSE;
                                    break;
                                case AV_NPC_ENTRY_JEZTOR:
                                    summonEntry = AV_NPC_WARRIDER_JEZTOR;
                                    break;
                                case AV_NPC_ENTRY_SLIDORE:
                                    summonEntry = AV_NPC_WARRIDER_SLIDORE;
                                    break;
                                case AV_NPC_ENTRY_VIPORE:
                                    summonEntry = AV_NPC_WARRIDER_VIPORE;
                                    break;
                                case AV_NPC_ENTRY_ICHMAN:
                                    summonEntry = AV_NPC_WARRIDER_ICHMAN;
                                    break;
                                default:
                                    return;
                            }
                            m_creature->SummonCreature(summonEntry,
                                                       m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 10000);
                        }
                        else
                            m_uiDisappear_Timer -= uiDiff;
                    }
                }
            }
        }
    }

    void JustRespawned() override
    {
        b_isSpeechDone = false;
        isGobSummoned = false;
        m_bThurlogaBoss = false;
        m_bRenferalBoss = false;
        b_isDead = false;
        isAggro = false;
        Point = 0;

        DoTeleportTo(av_x, av_y, av_z);
        m_creature->SetHomePosition(av_x, av_y, av_z, 0.0f);
        m_creature->GetMotionMaster()->MovePoint(POINT_LAST_POINT, av_x, av_y, av_z);

        if (AV_NpcEventTroopsAI* pEscortAI = dynamic_cast<AV_NpcEventTroopsAI*>(m_creature->AI()))
        {
            pEscortAI->Stop();
            pEscortAI->JustRespawned();
        }

        /** Respawn Primalist at her original place with the adds */
        if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
        {
            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_FROSTWOLF_SHAMAN, 1000.0f);
            for (const auto& it : m_RamRiderList)
            {
                it->Unmount();
                it->Respawn();
            }
            m_RamRiderList.clear();
        }
        /** Respawn Archdruid at her original place with the adds */
        else if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
        {
            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_DRUID_OF_THE_GROVE, 1000.0f);
            for (const auto& it : m_RamRiderList)
            {
                it->Unmount();
                it->Respawn();
            }
            m_RamRiderList.clear();
        }
        else if (m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
        {
            Stop();
            b_isCavalrySpawned = false;
            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_WOLFRIDER, 1000.0f);
            for (const auto& it : m_RamRiderList)
            {
                it->DisappearAndDie();
            }
            m_RamRiderList.clear();
        }
        if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD)
        {
            Stop();
            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_WOLFRIDER, 1000.0f);
            for (const auto& it : m_RamRiderList)
            {
                it->SetRespawnDelay(432000);
                it->SetDeathState(JUST_DIED);
                it->RemoveCorpse();
            }
            m_RamRiderList.clear();
        }
    }

    void Reset() override
    {
        if ((m_creature->GetEntry() == AV_NPC_ENTRY_VIPORE && m_creature->GetDistance(-1221.27f, -354.51f, 57.7f) < 5.0f) ||
            (m_creature->GetEntry() == AV_NPC_ENTRY_ICHMAN && m_creature->GetDistance(-1291.28f, -266.65f, 91.66f) < 5.0f))
            m_creature->SetStandState(UNIT_STAND_STATE_SIT);

        if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD)
            m_creature->Mount(2786);
        else if (m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
            m_creature->Mount(10278);
        else if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA &&
                 b_isNPCStartedMovingToChannelingPointWB &&
                 !b_isNPCMovedToChannelingPointWB)
            m_creature->Mount(12245);
        else if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL &&
                 b_isNPCStartedMovingToChannelingPointWB &&
                 !b_isNPCMovedToChannelingPointWB)
            m_creature->Mount(6080);

        if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
        {
            m_uiChainLightning_Timer = 10000;
            m_uiEarthbindTotem_Timer = 0;
            m_uiFlameShock_Timer     = 5000;
            m_uiHealingWave_Timer    = 0;
            m_uiLightningBolt_Timer  = 7500;
        }
        else if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
        {
            m_uiEntanglingRoots_Timer = 3000;
            m_uiStarFire_Timer = 0;
            m_uiRejuvenation_Timer = 10000;
        }

        m_uiTransform_Timer = 5000;
        m_uiDisappear_Timer = 5000;
        b_isTransformed = false;
        b_isTroopsSpawned = false;
        b_isCavalrySpawned = false;

        b_isDead = false;

        if (isAggro)
        {
            SetEscortPaused(false);
            m_creature->SetWalk(false);
            isAggro = false;
        }
    }

    void Aggro(Unit* pWho) override
    {
        /** Cavalry dismount in case of aggro situation */
        if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD ||
            m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
            m_creature->Unmount();
        else if ((m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA ||
                  m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL) &&
                 b_isNPCStartedMovingToChannelingPointWB &&
                 !b_isNPCMovedToChannelingPointWB)
            m_creature->Unmount();

        if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
            m_creature->CastSpell(m_creature, SPELL_EARTHBIND_TOTEM, false);

        isAggro = true;
        SetEscortPaused(true);
    }

    void WaypointReached(uint32 i) override
    {
        switch (i)
        {
            case 0:
                if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                    m_creature->SetWalk(true);
                break;
            case 2:
                if (m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
                {
                    SetEscortPaused(true);
                    DoScriptText(SAY_WOLFRIDER_CMD, m_creature);
                    Event_Timer = 6000;
                    Point = i;
                }
                break;
            case 3:
                if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
                {
                    b_isNPCStartedMovingToChannelingPointWB = true;
                    m_creature->SetWalk(false);
                    m_creature->Mount(6080);

                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_DRUID_OF_THE_GROVE, 40.0f);
                    for (const auto& it : m_RamRiderList)
                        it->Mount(9695); //2786
                    m_RamRiderList.clear();
                }
                break;
            case 5:
                if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD)
                {
                    SetEscortPaused(true);
                    DoScriptText(SAY_RAMRIDER_CMD, m_creature);
                    Event_Timer = 6000;
                    Point = i;
                }
                break;
            case 6:
                if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                {
                    b_isNPCStartedMovingToChannelingPointWB = true;
                    m_creature->Mount(12245);
                    m_creature->SetWalk(false);

                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_FROSTWOLF_SHAMAN, 40.0f);
                    for (const auto& it : m_RamRiderList)
                        it->Mount(10278);
                    m_RamRiderList.clear();
                }
                break;
            case 42:
                if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                {
                    b_isNPCStartedMovingToChannelingPointWB = true;
                    b_isNPCMovedToChannelingPointWB = true;
                    m_creature->Unmount();
                    m_creature->SetWalk(true);

                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_FROSTWOLF_SHAMAN, 40.0f);
                    for (const auto& it : m_RamRiderList)
                        it->Unmount();
                    m_RamRiderList.clear();
                }
                break;
            case 43:
                if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                {
                    DoScriptText(SAY_PRIMALIST_THURLOGA, m_creature);
                    m_creature->CastSpell(m_creature, AV_INVOCATION_SPELL, false);

                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_FROSTWOLF_SHAMAN, 30.0f);
                    for (const auto& it : m_RamRiderList)
                        it->CastSpell(m_creature, AV_INVOCATION_SPELL, false);
                    m_RamRiderList.clear();

                    m_creature->SummonGameObject(OBJECT_WB_H_INVOCATION, -360.006989f, -130.33f, 26.4321f, 5.6635f, 0, 0, 0, 0, -1, false);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                    isGobSummoned = true;
                }
                break;
            case 48:
                if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
                {
                    b_isNPCStartedMovingToChannelingPointWB = true;
                    b_isNPCMovedToChannelingPointWB = true;
                    m_creature->Unmount();
                    m_creature->SetWalk(true);

                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_DRUID_OF_THE_GROVE, 40.0f);
                    for (const auto& it : m_RamRiderList)
                        it->Unmount();
                    m_RamRiderList.clear();
                }
                break;
            case 49:
                if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
                {
                    DoScriptText(SAY_ARCHDRUID_RENFERAL, m_creature);
                    m_creature->CastSpell(m_creature, AV_INVOCATION_SPELL, false);

                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_DRUID_OF_THE_GROVE, 30.0f);
                    for (const auto& it : m_RamRiderList)
                        it->CastSpell(m_creature, AV_INVOCATION_SPELL, false);
                    m_RamRiderList.clear();

                    m_creature->SummonGameObject(OBJECT_WB_A_INVOCATION, -199.7f, -342.698f, 6.809f, 1.69646f, 0, 0, 0, 0, -1, false);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                    isGobSummoned = true;
                }
                break;
            case 66:
                if (m_creature->GetEntry() == AV_NPC_ENTRY_SLIDORE)
                {
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            case 74:
                if (m_creature->GetEntry() == AV_NPC_ENTRY_GUSE)
                {
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            case 76:
                if (m_creature->GetEntry() == AV_NPC_ENTRY_VIPORE)
                {
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            case 81:
                if (m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
                {
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            case 84:
                if (m_creature->GetEntry() == AV_NPC_ENTRY_JEZTOR)
                {
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            case 92:
                if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD)
                {
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                else if (m_creature->GetEntry() == AV_NPC_ENTRY_ICHMAN)
                {
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            case 97:
                if (m_creature->GetEntry() == AV_NPC_ENTRY_MULVERICK)
                {
                    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();//SetEscortPaused(true);
                }
                break;
            default:
                break;
                //Our commander has fallen! The time of revenge has come! Kill them all !
        }
    }

    void JustDied(Unit* pWho) override
    {
        /** Unlock speech for Cavalry again */
        b_isSpeechDone = false;
        isAggro = false;

        if (!b_isDead)
        {
            uint32 m_followers = 0;

            if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD)
                m_followers = AV_NPC_RAMRIDER;
            else if (m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
                m_followers = AV_NPC_WOLFRIDER;
            else if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                m_followers = AV_NPC_FROSTWOLF_SHAMAN;
            else if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
                m_followers = AV_NPC_DRUID_OF_THE_GROVE;
            else if (m_creature->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
            {
                if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(m_creature->GetMap()))
                {
                    if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
                    {
                        uint32 m_uiRessourcesLevel = bg->getReinforcementLevelGroundUnit(BG_TEAM_ALLIANCE);
                        m_followers = AV_NPC_STORMPIKE_COMMANDO;
                        switch (m_uiRessourcesLevel)
                        {
                            case AV_NPC_SEASONED:
                                m_followers = AV_NPC_SEASONED_COMMANDO;
                                break;
                            case AV_NPC_VETERAN:
                                m_followers = AV_NPC_VETERAN_COMMANDO;
                                break;
                            case AV_NPC_CHAMPION:
                                m_followers = AV_NPC_CHAMPION_COMMANDO;
                                break;
                        }
                    }
                }
            }
            else if (m_creature->GetEntry() == AV_NPC_WARMASTER_CMD)
            {
                if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(m_creature->GetMap()))
                {
                    if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
                    {
                        uint32 m_uiRessourcesLevel = bg->getReinforcementLevelGroundUnit(BG_TEAM_HORDE);
                        switch (m_uiRessourcesLevel)
                        {
                            case AV_NPC_BASIC:
                                m_followers = AV_NPC_FROSTWOLF_REAVER;
                                break;
                            case AV_NPC_SEASONED:
                                m_followers = AV_NPC_SEASONED_REAVER;
                                break;
                            case AV_NPC_VETERAN:
                                m_followers = AV_NPC_VETERAN_REAVER;
                                break;
                            case AV_NPC_CHAMPION:
                                m_followers = AV_NPC_CHAMPION_REAVER;
                                break;
                            default:
                                m_followers = AV_NPC_FROSTWOLF_REAVER;
                                break;
                        }
                    }
                }
            }

            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, m_followers, 100.0f);
            for (const auto& it : m_RamRiderList)
            {
                if (AV_NpcEventTroopsAI* pEscortAI = dynamic_cast<AV_NpcEventTroopsAI*>(it->AI()))
                {
                    pEscortAI->Reset();
                    it->SetRespawnDelay(432000);
                    pEscortAI->Start(true, 0, nullptr, false);
                    pEscortAI->setCurrentWP(getCurrentWP());
                }
            }
            m_RamRiderList.clear();
            b_isDead = true;
        }
    }

    void UpdateRenferalAI(uint32 const uiDiff)
    {
        if (m_uiEntanglingRoots_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ENTANGLING_ROOTS) == CAST_OK)
                m_uiEntanglingRoots_Timer = urand(9000, 13000);
        }
        else
            m_uiEntanglingRoots_Timer -= uiDiff;

        if (m_uiRejuvenation_Timer < uiDiff)
        {
            m_creature->CastSpell(m_creature, SPELL_REJUVENATION, true);
            m_uiRejuvenation_Timer = 17000;
        }
        else
            m_uiRejuvenation_Timer -= uiDiff;

        if (m_uiStarFire_Timer < uiDiff)
        {
            m_creature->CastSpell(m_creature->GetVictim(), SPELL_STARFIRE, false);
            m_uiStarFire_Timer = 7000;
        }
        else
            m_uiStarFire_Timer -= uiDiff;
    }

    void UpdateThurlogaAI(uint32 const uiDiff)
    {
        if (m_uiChainLightning_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CHAIN_LIGHTNING) == CAST_OK)
                m_uiChainLightning_Timer = urand(15000, 18000);
        }
        else
            m_uiChainLightning_Timer -= uiDiff;

        if (m_uiFlameShock_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FLAME_SHOCK) == CAST_OK)
                m_uiFlameShock_Timer = urand(8000, 9000);
        }
        else
            m_uiFlameShock_Timer -= uiDiff;

        if (m_uiLightningBolt_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_LIGHNING_BOLT) == CAST_OK)
                m_uiLightningBolt_Timer = urand(11000, 12000);
        }
        else
            m_uiLightningBolt_Timer -= uiDiff;

        if (m_uiHealingWave_Timer < uiDiff)
        {
            if (m_creature->GetHealthPercent() < 70.0f)
            {
                m_creature->CastSpell(m_creature, SPELL_HEALING_WAVE, false);
                m_uiHealingWave_Timer = 7000;
            }
        }
        else
            m_uiHealingWave_Timer -= uiDiff;

        if (m_uiEarthbindTotem_Timer < uiDiff)
        {
            if (!m_creature->FindNearestCreature(2630, 20.0f, true)) // Earth totem
            {
                m_creature->CastSpell(m_creature, SPELL_EARTHBIND_TOTEM, false);
                m_uiEarthbindTotem_Timer = 14000;
            }
        }
        else
            m_uiEarthbindTotem_Timer -= uiDiff;
    }


    void UpdateEscortAI(uint32 const uiDiff) override
    {
        switch (m_creature->GetEntry())
        {
            /** Aerial creature */
            case AV_NPC_ENTRY_MULVERICK:
                checkAerialStatus(uiDiff, AV_NPC_ENTRY_MULVERICK);
                break;
            case AV_NPC_ENTRY_JEZTOR:
                checkAerialStatus(uiDiff, AV_NPC_ENTRY_JEZTOR);
                break;
            case AV_NPC_ENTRY_GUSE:
                checkAerialStatus(uiDiff, AV_NPC_ENTRY_GUSE);
                break;
            case AV_NPC_ENTRY_ICHMAN:
                checkAerialStatus(uiDiff, AV_NPC_ENTRY_ICHMAN);
                break;
            case AV_NPC_ENTRY_VIPORE:
                checkAerialStatus(uiDiff, AV_NPC_ENTRY_VIPORE);
                break;
            case AV_NPC_ENTRY_SLIDORE:
                checkAerialStatus(uiDiff, AV_NPC_ENTRY_SLIDORE);
                break;

            /** Cavalry creature */
            case AV_NPC_WOLFRIDER_CMD:
                if (!b_isCavalrySpawned)
                    checkCavalryStatus(uiDiff, AV_NPC_WOLFRIDER_CMD);
                break;
            case AV_NPC_RAMRIDER_CMD:
                if (!b_isCavalrySpawned)
                    checkCavalryStatus(uiDiff, AV_NPC_RAMRIDER_CMD);
                break;

            /** Troops creature */
            case AV_NPC_QUARTERMASTER:
                if (!b_isTroopsSpawned)
                    checkTroopsStatus(uiDiff, AV_NPC_QUARTERMASTER);
                break;
            case AV_NPC_QUARTERMASTER_A:
                if (!b_isTroopsSpawned)
                    checkTroopsStatus(uiDiff, AV_NPC_QUARTERMASTER_A);
                break;

            default:
                break;
        }

        if (Event_Timer <= uiDiff)
        {
            switch (Point)
            {
                case 2:
                    if (m_creature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
                    {
                        if (!b_isSpeechDone)
                        {
                            b_isSpeechDone = true;

                            std::list<Creature*> m_RamRiderList;
                            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_WOLFRIDER, 50.0f);
                            for (const auto& it : m_RamRiderList)
                            {
                                DoScriptText(SAY_WARCRY_HORDE, it);
                                it->SetWalk(false);
                                it->JoinCreatureGroup(m_creature,
                                                         m_creature->GetAngle(it) - it->GetOrientation(),
                                                         m_creature->GetDistance(it),
                                                         OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER | OPTION_EVADE_TOGETHER);
                            }
                            m_RamRiderList.clear();
                        }
                        SetEscortPaused(false);
                        Event_Timer = 0;
                    }
                    break;
                case 5:
                    if (m_creature->GetEntry() == AV_NPC_RAMRIDER_CMD)
                    {
                        if (!b_isSpeechDone)
                        {
                            b_isSpeechDone = true;

                            std::list<Creature*> m_RamRiderList;
                            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_RAMRIDER, 20.0f);
                            for (const auto& it : m_RamRiderList)
                            {
                                DoScriptText(SAY_WARCRY_ALIANCE, it);
                                it->SetWalk(false);
                                it->JoinCreatureGroup(m_creature,
                                                         m_creature->GetAngle(it) - it->GetOrientation(),
                                                         m_creature->GetDistance(it),
                                                         OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER | OPTION_EVADE_TOGETHER);
                            }
                            m_RamRiderList.clear();
                        }
                        SetEscortPaused(false);
                        Event_Timer = 0;
                    }
                    break;
                default:
                    break;
            }
        }
        else
            Event_Timer -= uiDiff;

        if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
        {
            GameObject* pInvocation = m_creature->FindNearestGameObject(OBJECT_WB_H_INVOCATION, 250.0f);
            if (isGobSummoned && !pInvocation && m_creature->GetDistance(-360.16f, -130.41f, 27.07f) < 100)
            {
                if (!m_bThurlogaBoss)
                {
                    m_bThurlogaBoss = true;
                    DoScriptText(SAY_LOKHOLAR_SPAWNED, m_creature);
                    m_uiDespawn_Timer = 600000;
                }
            }

            if (m_uiDespawn_Timer < uiDiff)
            {
                if (m_bThurlogaBoss)
                {
                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_FROSTWOLF_SHAMAN, 100.0f);
                    for (const auto& it : m_RamRiderList)
                    {
                        it->Unmount();
                        it->DisappearAndDie();
                    }
                    m_RamRiderList.clear();
                    m_creature->DisappearAndDie();
                    JustRespawned();
                }
            }
            else
                m_uiDespawn_Timer -= uiDiff;
        }
        else if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
        {
            GameObject* pInvocation = m_creature->FindNearestGameObject(OBJECT_WB_A_INVOCATION, 250.0f);
            if (isGobSummoned && !pInvocation && m_creature->GetDistance(-199.64f, -342.7f, 7.67f) < 100.0f)
            {
                if (!m_bRenferalBoss)
                {
                    m_bRenferalBoss = true;
                    m_uiDespawn_Timer = 6000;
                }
            }

            if (m_uiDespawn_Timer < uiDiff)
            {
                if (m_bRenferalBoss)
                {
                    std::list<Creature*> m_RamRiderList;
                    GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_DRUID_OF_THE_GROVE, 100.0f);
                    for (const auto& it : m_RamRiderList)
                    {
                        it->Unmount();
                        it->DisappearAndDie();
                    }
                    m_RamRiderList.clear();
                    m_creature->DisappearAndDie();
                    JustRespawned();
                }
            }
            else
                m_uiDespawn_Timer -= uiDiff;
        }


        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
            UpdateThurlogaAI(uiDiff);

        if (m_creature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL)
            UpdateRenferalAI(uiDiff);

        DoMeleeAttackIfReady();
    }
};


/** Update status of items / NPC completion for Alterac Valley quests challenges :
 * Aerial assault, Cavalry assault, Troops assault or World Boss Assault */
bool QuestComplete_npc_AVBlood_collector(Player* pPlayer, Creature* pQuestGiver, Quest const* pQuest)
{
    /** Check if NPC is linked to a quest */
    if ((!pQuest->ReqItemId[0] || !pQuest->ReqItemCount[0]) &&
        (pQuest->GetQuestId() != QUEST_TAMED_FROSTWOLVES &&  pQuest->GetQuestId() != QUEST_TAMED_RAMS))
        return false;

    uint32 m_faction_id           = (pPlayer->GetTeam() == ALLIANCE) ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE;
    uint32 m_ressources_delivered = pQuest->ReqItemCount[0];
    uint32 m_challenge;

    if (BattleGround* bg = pPlayer->GetBattleGround())
    {
        if (bg->GetTypeID() == BATTLEGROUND_AV)
        {
            /** Quest isn't completed because of an item but because a creature
              * came near quest giver -specific case- */
            if (pQuest->GetQuestId() == QUEST_TAMED_FROSTWOLVES ||
                pQuest->GetQuestId() == QUEST_TAMED_RAMS)
            {
                m_challenge            = BG_AV_TAMED_CAVALRY_ASSAULT;
                m_ressources_delivered = 1;
            }
            else
            {
                switch (pQuest->ReqItemId[0])
                {
                    case ITEM_STORMPIKE_BLOOD_HORDE:
                    case ITEM_STORM_CRYSTAL:
                        m_challenge = BG_AV_BLOOD_WORLDBOSS_ASSAULT;
                        break;
                    case ITEM_FROSTWOLF_HIDE:
                    case ITEM_ALTERAC_RAM_HIDE:
                        m_challenge = BG_AV_HIDE_CAVALRY_ASSAULT;
                        break;
                    case ITEM_STORMPIKE_SOLDIER_FLESH:
                    case ITEM_FROSTWOLF_SOLDIER_MEDAL:
                        m_challenge = BG_AV_SOLDIER_AIR_ASSAULT;
                        break;
                    case ITEM_STORMPIKE_LIEUTENANT_FLESH:
                    case ITEM_FROSTWOLF_LIEUTENANT_MEDAL:
                        m_challenge = BG_AV_LIEUTENANT_AIR_ASSAULT;
                        break;
                    case ITEM_STORMPIKE_COMMANDER_FLESH:
                    case ITEM_FROSTWOLF_COMMANDER_MEDAL:
                        m_challenge = BG_AV_COMMANDER_AIR_ASSAULT;
                        break;
                    case ITEM_IRONDEEP_SUPPLIES:
                        m_challenge = BG_AV_IRONDEEP_GROUND_ASSAULT;
                        break;
                    case ITEM_COLDTOOTH_SUPPLIES:
                        m_challenge = BG_AV_COLDTOOTH_GROUND_ASSAULT;
                        break;
                    case 17422:
                        m_challenge = 0;
                        return false;
                        break;

                    default:
                        sLog.outInfo("[Alterac] QuestComplete_npc_AVBlood_collector called with quest %u reqItem=%u unknown !", pQuest->GetQuestId(), pQuest->ReqItemId[0]);
                        return false;
                }
            }

            ((BattleGroundAV*)bg)->setChallengeInvocationCounter(
                m_faction_id,
                m_challenge,
                m_ressources_delivered);

            if ((m_challenge == BG_AV_BLOOD_WORLDBOSS_ASSAULT) && ((BattleGroundAV*)bg)->isWorldBossChallengeInvocationReady(m_faction_id))
            {
                uint32 playerFactionId = (pPlayer->GetTeam() == ALLIANCE) ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE;
                ((BattleGroundAV*)bg)->resetWorldBossChallengeInvocation(playerFactionId);
                /** World Boss challenge is unique, won't give opportunity to
                complete quest once again in the current battleground */
                ((BattleGroundAV*)bg)->
                    setPlayerGoStatus(playerFactionId, BG_AV_WORLDBOSS_ASSAULT, true);

                /** Start NPC movement for World Boss event */
                if (AV_NpcEventAI* pEscortAI = dynamic_cast<AV_NpcEventAI*>(pQuestGiver->AI()))
                {
                    pEscortAI->Start(true, 0, nullptr, false);
                    pQuestGiver->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pQuestGiver->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                    pQuestGiver->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
                }
            }

        }
    }
    return true;
}

enum
{
    GOSSIP_UPGRADE_SEASONED = 8718,
    GOSSIP_UPGRADE_VETERAN = 8719,
    GOSSIP_UPGRADE_CHAMPION = 8723,
    GOSSIP_GROUND_ASSAULT = 9128,
    GOSSIP_NEXT_UPGRADE = 9130,

    GOSSIP_BEACON_WEST_HORDE = 8669,
    GOSSIP_BEACON_WEST_ALLY = 8799,
    GOSSIP_BEACON_EAST_ALLY = 8796,
    GOSSIP_BEACON_EAST_HORDE = 8667,
    GOSSIP_BEACON_SNOWFALL_HORDE = 8671,
    GOSSIP_BEACON_SNOWFALL_ALLY = 8793,
    GOSSIP_BEACON_NEUTRAL = 8702,

    GOSSIP_ASSAULT_CAVALRY = 8903,
    GOSSIP_ASSAULT_GROUND = 9050,
    
    GOSSIP_ASSAULT_AIR_GUSE = 10341,
    GOSSIP_ASSAULT_AIR_SLIDORE = 10351,
    GOSSIP_ASSAULT_AIR_JEZTOR = 10343,
    GOSSIP_ASSAULT_AIR_VIPORE = 10353,
    GOSSIP_ASSAULT_AIR_MULV = 10346,
    GOSSIP_ASSAULT_AIR_ICH = 10349,

    GOSSIP_RENFERAL_BOSS1 = 8757,
    GOSSIP_RENFERAL_BOSS2 = 8759,
    GOSSIP_RENFERAL_BOSS3 = 8761,

    GOSSIP_THURLOGA_BOSS1 = 8641,
    GOSSIP_THURLOGA_BOSS2 = 8643,
    GOSSIP_THURLOGA_BOSS3 = 8645,

    NPCTEXT_RENFERAL_BOSS1 = 6175,
    NPCTEXT_RENFERAL_BOSS2 = 6176,
    NPCTEXT_RENFERAL_BOSS3 = 6177,

    NPCTEXT_THURLOGA_BOSS1 = 6098,
    NPCTEXT_THURLOGA_BOSS2 = 6099,
    NPCTEXT_THURLOGA_BOSS3 = 6100,
};

/** Check status of items / NPC completion for Alterac Valley quests challenges :
 * Aerial assault, Cavalry assault, Troops assault or World Boss Assault.
 * If challenge is completed and reputation is compatible, add a GOSSIP menu
 * to launch the corresponding assault. */
bool GossipHello_npc_AVBlood_collector(Player* pPlayer, Creature* pCreature)
{
    bool   b_objectiveReached = false;
    bool   b_objectiveGlobalAirAssaultSoldier    = false;
    bool   b_objectiveGlobalAirAssaultLieutenant = false;
    bool   b_objectiveGlobalAirAssaultCommander  = false;
    uint32 m_faction_id = (pPlayer->GetTeam() == ALLIANCE) ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE;
    uint32 m_actual_ressources = 0;
    uint32 m_actual_ressources2 = 0;
    uint32 m_objective_ressources = 0;
    uint32 m_challenge = 0;
    uint32 m_minRepAssault = 0;

    uint16 uiMessage = 0;
    uint16 uiMessageGlobalAirAssault = 0;

    if (pCreature->GetEntry() == AV_NPC_QUARTERMASTER_A || pCreature->GetEntry() == AV_NPC_QUARTERMASTER)
    {
        m_challenge = BG_AV_NB_CHALLENGES;
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());


        if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(pCreature->GetMap()))
        {
            if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
            {

                m_actual_ressources  = bg->getChallengeInvocationCounter(m_faction_id, BG_AV_IRONDEEP_GROUND_ASSAULT);
                m_actual_ressources2 = bg->getChallengeInvocationCounter(m_faction_id, BG_AV_COLDTOOTH_GROUND_ASSAULT);

            }
        }

        if (m_actual_ressources + m_actual_ressources2 > 230)
            m_challenge = m_challenge + 14;
        else if (m_actual_ressources + m_actual_ressources2 > 140)
            m_challenge = m_challenge + 12;
        else if (m_actual_ressources > 210 && m_actual_ressources2 > 50)
            m_challenge = m_challenge + 14;
        else if (m_actual_ressources > 110 && m_actual_ressources2 > 20)
            m_challenge = m_challenge + 12;
        else
            m_challenge = m_challenge + 13;



        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_GROUND_ASSAULT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + m_challenge + 1);

        //        if (pCreature->IsVendor())
        //            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        //       pPlayer->SEND_GOSSIP_MENU(6255, pCreature->GetGUID());
        //       return true;
    }


    if (pCreature->GetEntry() == AV_NPC_ENTRY_MURGOT || pCreature->GetEntry() == AV_NPC_ENTRY_REGZAR)
    {
        m_challenge = BG_AV_NB_CHALLENGES;
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (BattleGroundMap* bgMap = dynamic_cast<BattleGroundMap*>(pCreature->GetMap()))
        {
            if (BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(bgMap->GetBG()))
            {
                m_actual_ressources = bg->GetActualArmorRessources(m_faction_id);
                if (m_actual_ressources < 500)
                {
                    if (m_actual_ressources <= 200)
                        m_challenge = m_challenge + 0;
                    else if (m_actual_ressources < 400)
                        m_challenge = m_challenge + 1;
                    else
                        m_challenge = m_challenge + 4;
                }
                else if (m_actual_ressources < 1000)
                {
                    if (m_actual_ressources <= 700)
                        m_challenge = m_challenge + 0;
                    else if (m_actual_ressources < 900)
                        m_challenge = m_challenge + 2;
                    else
                        m_challenge = m_challenge + 5;
                }
                else if (m_actual_ressources < 1500)
                {
                    if (m_actual_ressources <= 1200)
                        m_challenge = m_challenge + 0;
                    else if (m_actual_ressources < 1400)
                        m_challenge = m_challenge + 3;
                    else
                        m_challenge = m_challenge + 6;
                }
                switch (bg->getReinforcementLevelGroundUnit(m_faction_id))
                {
                    case AV_NPC_BASIC:
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_NEXT_UPGRADE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + m_challenge + 1);

                        if ((pPlayer->GetReputationRank(ID_REPUTATION_FROSTWOLF) >= REP_HONORED ||
                             pPlayer->GetReputationRank(ID_REPUTATION_STORMPIKE) >= REP_HONORED) && m_actual_ressources >= 500)
                        {
                            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UPGRADE_SEASONED, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 500 + 1);
                        }

                        pPlayer->SEND_GOSSIP_MENU(6073, pCreature->GetGUID());
                        break;
                    case AV_NPC_SEASONED:
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_NEXT_UPGRADE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + m_challenge + 1);

                        if ((pPlayer->GetReputationRank(ID_REPUTATION_FROSTWOLF) >= REP_HONORED ||
                             pPlayer->GetReputationRank(ID_REPUTATION_STORMPIKE) >= REP_HONORED) && m_actual_ressources >= 1000)
                        {
                            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UPGRADE_VETERAN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1000 + 1);
                        }

                        pPlayer->SEND_GOSSIP_MENU(6217, pCreature->GetGUID());
                        break;
                    case AV_NPC_VETERAN:
                        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_NEXT_UPGRADE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + m_challenge + 1);

                        if ((pPlayer->GetReputationRank(ID_REPUTATION_FROSTWOLF) >= REP_HONORED ||
                             pPlayer->GetReputationRank(ID_REPUTATION_STORMPIKE) >= REP_HONORED) && m_actual_ressources >= 1500)
                        {
                            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UPGRADE_CHAMPION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1500 + 1);
                        }

                        pPlayer->SEND_GOSSIP_MENU(6218, pCreature->GetGUID());
                        break;
                    case AV_NPC_CHAMPION:
                        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
                        break;
                    default:
                        break;
                }
            }
        }
        return true;
    }

    if (pCreature->GetEntry() == AV_NPC_ENTRY_GUSE ||
        pCreature->GetEntry() == AV_NPC_ENTRY_JEZTOR ||
        pCreature->GetEntry() == AV_NPC_ENTRY_MULVERICK)
    {
        if (pCreature->GetEntry() == AV_NPC_ENTRY_MULVERICK ||
            pCreature->GetEntry() == AV_NPC_ENTRY_JEZTOR ||
            pCreature->GetEntry() == AV_NPC_ENTRY_GUSE)
        {
            pCreature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
        }

        if (pCreature->GetDistance(-1338.6f, -328.16f, 90.8f) > 15.0f && m_faction_id == BG_TEAM_HORDE)
        {
            if (AV_NpcEventAI* pEscortAI = dynamic_cast<AV_NpcEventAI*>(pCreature->AI()))
            {
                pCreature->SetFactionTemplateId(1194);
                pEscortAI->Start(true, 0, nullptr, false);
                pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
                pCreature->SetWalk(false);
                pCreature->SetFactionTemplateId(pPlayer->GetFactionTemplateId());
                if (pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                    pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            }
            return false;
        }
        else if (pCreature->GetDistance(-1338.6f, -328.16f, 90.8f) < 15.0f)
            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }
    else if (pCreature->GetEntry() == AV_NPC_ENTRY_SLIDORE ||
             pCreature->GetEntry() == AV_NPC_ENTRY_ICHMAN ||
             pCreature->GetEntry() == AV_NPC_ENTRY_VIPORE)
    {

        if (pCreature->GetDistance(575.116f, -51.90f, 37.62f) > 15.0f && m_faction_id == BG_TEAM_ALLIANCE)
        {
            if (AV_NpcEventAI* pEscortAI = dynamic_cast<AV_NpcEventAI*>(pCreature->AI()))
            {
                if (pCreature->GetEntry() == AV_NPC_ENTRY_VIPORE)
                    pCreature->CastSpell(pCreature, 5759, false);

                pCreature->SetFactionTemplateId(1194);
                pEscortAI->Start(true, 0, nullptr, false);
                pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
                pCreature->SetWalk(false);
                pCreature->SetFactionTemplateId(pPlayer->GetFactionTemplateId());
                if (pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                    pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            }
            return false;
        }
        else
        {
            if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }
    }

    QuestRelationsMapBounds bounds = sObjectMgr.GetCreatureQuestRelationsMapBounds(pCreature->GetEntry());
    if (pCreature->GetEntry() != AV_NPC_MARSHAL_TERAVAINE)
    {
        for (QuestRelationsMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
        {
            uint32 quest_id = itr->second;
            if (!quest_id)
                continue;
            Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);
            if (!pQuest)
                continue;
            if (pQuest->ReqItemId[0] == 0)
                continue;

            if (BattleGround* bg = pPlayer->GetBattleGround())
            {
                if (bg->GetTypeID() == BATTLEGROUND_AV)
                {
                    /** Quest isn't completed because of an item but because a creature
                      * came near quest giver -specific case- */
                    if (pQuest->GetQuestId() == QUEST_TAMED_FROSTWOLVES ||
                        pQuest->GetQuestId() == QUEST_TAMED_RAMS)
                    {
                        m_challenge     = BG_AV_TAMED_CAVALRY_ASSAULT;
                        m_minRepAssault = ((BattleGroundAV*)bg)->
                                          getMinReputationNeeded(BG_AV_CAVALRY_ASSAULT);
                    }
                    else
                    {
                        switch (pQuest->ReqItemId[0])
                        {
                            case ITEM_FROSTWOLF_HIDE:
                            case ITEM_ALTERAC_RAM_HIDE:
                                m_challenge = BG_AV_HIDE_CAVALRY_ASSAULT;
                                m_minRepAssault = ((BattleGroundAV*)bg)->
                                                  getMinReputationNeeded(BG_AV_CAVALRY_ASSAULT);
                                break;
                            case ITEM_STORMPIKE_SOLDIER_FLESH:
                            case ITEM_FROSTWOLF_SOLDIER_MEDAL:
                                m_challenge = BG_AV_SOLDIER_AIR_ASSAULT;
                                m_minRepAssault = ((BattleGroundAV*)bg)->
                                                  getMinReputationNeeded(BG_AV_AIR_ASSAULT_BEACON_SOLDIER);
                                break;
                            case ITEM_STORMPIKE_LIEUTENANT_FLESH:
                            case ITEM_FROSTWOLF_LIEUTENANT_MEDAL:
                                m_challenge = BG_AV_LIEUTENANT_AIR_ASSAULT;
                                m_minRepAssault = ((BattleGroundAV*)bg)->
                                                  getMinReputationNeeded(BG_AV_AIR_ASSAULT_BEACON_LIEUTENANT);
                                break;
                            case ITEM_STORMPIKE_COMMANDER_FLESH:
                            case ITEM_FROSTWOLF_COMMANDER_MEDAL:
                                m_challenge = BG_AV_COMMANDER_AIR_ASSAULT;
                                m_minRepAssault = ((BattleGroundAV*)bg)->
                                                  getMinReputationNeeded(BG_AV_AIR_ASSAULT_BEACON_COMMANDER);
                                break;
                            case ITEM_IRONDEEP_SUPPLIES:
                                m_challenge = BG_AV_IRONDEEP_GROUND_ASSAULT;
                                m_minRepAssault = ((BattleGroundAV*)bg)->
                                                  getMinReputationNeeded(BG_AV_GROUND_ASSAULT);
                                break;
                            case ITEM_COLDTOOTH_SUPPLIES:
                                m_challenge = BG_AV_COLDTOOTH_GROUND_ASSAULT;
                                m_minRepAssault = ((BattleGroundAV*)bg)->
                                                  getMinReputationNeeded(BG_AV_GROUND_ASSAULT);
                                break;

                            default:
                                m_challenge = BG_AV_WRONG_VALUE;
                                m_minRepAssault = 0; // Give neutral value in case of
                                break;
                        }
                    }

                    /** Display a message regarding ressources status for corresponding event */
                    if (m_challenge != BG_AV_WRONG_VALUE)
                    {
                        m_actual_ressources = ((BattleGroundAV*)bg)->
                                              getChallengeInvocationCounter(
                                                  m_faction_id,
                                                  m_challenge);
                        m_objective_ressources = ((BattleGroundAV*)bg)->
                                                 getChallengeInvocationGoals(
                                                     m_faction_id,
                                                     m_challenge);

                    }
                    else /** Error case */
                    {
                        m_actual_ressources = 0;
                        m_objective_ressources = 1;
                    }

                    /** Check if the corresponding amount of ressources is OK pour an assault */
                    if (m_actual_ressources >= m_objective_ressources)
                    {
                        switch (m_challenge)
                        {
                            case BG_AV_SOLDIER_AIR_ASSAULT:
                                b_objectiveReached = ((BattleGroundAV*)bg)->
                                                     isAerialChallengeInvocationReady(m_faction_id,
                                                             BG_AV_AIR_ASSAULT_BEACON_SOLDIER);

                                if (pPlayer->GetTeam() == ALLIANCE)
                                    uiMessage = GOSSIP_BEACON_EAST_ALLY;
                                else
                                    uiMessage = GOSSIP_BEACON_EAST_HORDE;
                                break;

                            case BG_AV_LIEUTENANT_AIR_ASSAULT:
                                b_objectiveReached = ((BattleGroundAV*)bg)->
                                                     isAerialChallengeInvocationReady(m_faction_id,
                                                             BG_AV_AIR_ASSAULT_BEACON_LIEUTENANT);

                                if (pPlayer->GetTeam() == ALLIANCE)
                                    uiMessage = GOSSIP_BEACON_WEST_ALLY;
                                else
                                    uiMessage = GOSSIP_BEACON_WEST_HORDE;
                                break;

                            case BG_AV_COMMANDER_AIR_ASSAULT:
                                b_objectiveReached = ((BattleGroundAV*)bg)->
                                                     isAerialChallengeInvocationReady(m_faction_id,
                                                             BG_AV_AIR_ASSAULT_BEACON_COMMANDER);

                                if (pPlayer->GetTeam() == ALLIANCE)
                                    uiMessage = GOSSIP_BEACON_SNOWFALL_ALLY;
                                else
                                    uiMessage = GOSSIP_BEACON_SNOWFALL_HORDE;
                                break;

                            case BG_AV_HIDE_CAVALRY_ASSAULT:
                            case BG_AV_TAMED_CAVALRY_ASSAULT:
                                b_objectiveReached = ((BattleGroundAV*)bg)->
                                                     isCavalryChallengeInvocationReady(m_faction_id);

                                uiMessage = GOSSIP_ASSAULT_CAVALRY;
                                break;

                            case BG_AV_IRONDEEP_GROUND_ASSAULT:
                            case BG_AV_COLDTOOTH_GROUND_ASSAULT:
                                b_objectiveReached = ((BattleGroundAV*)bg)->
                                                     isGroundChallengeInvocationReady(m_faction_id);

                                uiMessage = GOSSIP_ASSAULT_GROUND;
                                break;

                            default:
                                break;
                        }
                    }
                    /** Specific case for global air assault : needs 3 aerial resources ready */
                    if (((BattleGroundAV*)bg)->
                        isAerialChallengeInvocationReady(m_faction_id, BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER) &&
                        (pCreature->GetEntry() == AV_NPC_ENTRY_GUSE ||
                         pCreature->GetEntry() == AV_NPC_ENTRY_SLIDORE))
                    {
                        b_objectiveGlobalAirAssaultSoldier = true;
                        if (pCreature->GetEntry() == AV_NPC_ENTRY_GUSE)
                            uiMessageGlobalAirAssault = GOSSIP_ASSAULT_AIR_GUSE;
                        else
                            uiMessageGlobalAirAssault = GOSSIP_ASSAULT_AIR_SLIDORE;
                    }
                    if (((BattleGroundAV*)bg)->
                        isAerialChallengeInvocationReady(m_faction_id,
                                                         BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT) &&
                        (pCreature->GetEntry() == AV_NPC_ENTRY_JEZTOR ||
                         pCreature->GetEntry() == AV_NPC_ENTRY_VIPORE))
                    {
                        b_objectiveGlobalAirAssaultLieutenant = true;
                        if (pCreature->GetEntry() == AV_NPC_ENTRY_JEZTOR)
                            uiMessageGlobalAirAssault = GOSSIP_ASSAULT_AIR_JEZTOR;
                        else
                            uiMessageGlobalAirAssault = GOSSIP_ASSAULT_AIR_VIPORE;
                    }
                    if (((BattleGroundAV*)bg)->
                        isAerialChallengeInvocationReady(m_faction_id,
                                                         BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER) &&
                        (pCreature->GetEntry() == AV_NPC_ENTRY_MULVERICK ||
                         pCreature->GetEntry() == AV_NPC_ENTRY_ICHMAN))
                    {
                        b_objectiveGlobalAirAssaultCommander = true;
                        if (pCreature->GetEntry() == AV_NPC_ENTRY_MULVERICK)
                            uiMessageGlobalAirAssault = GOSSIP_ASSAULT_AIR_MULV;
                        else
                            uiMessageGlobalAirAssault = GOSSIP_ASSAULT_AIR_ICH;
                    }
                }
            }
        }
    }

    if (pCreature->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
    {
        uiMessage = GOSSIP_ASSAULT_CAVALRY;
        b_objectiveReached = true;
        m_challenge = BG_AV_IRONDEEP_GROUND_ASSAULT;
    }

    /** An assault if available */
    if (b_objectiveReached)
    {
        //        pCreature->MonsterSay(sMessage, 0, 0);
        m_minRepAssault = 3;

        if (pCreature->GetEntry() != AV_NPC_MARSHAL_TERAVAINE)
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        /** Check if the player got enough reputation to launch the assault */
        if (pPlayer->GetReputationRank(ID_REPUTATION_FROSTWOLF) >= m_minRepAssault ||
            pPlayer->GetReputationRank(ID_REPUTATION_STORMPIKE) >= m_minRepAssault)
        {
            /** TODO in case of a standard aerial attack, NPC needs to give a beacon
             * to the player : it's a completed quest player needs to validate to receive
             * the corresponding object. */

            /** Add new gossip for launching order */
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,
                                     uiMessage,
                                     GOSSIP_SENDER_MAIN,
                                     GOSSIP_ACTION_INFO_DEF + m_challenge + 1);

            if (b_objectiveGlobalAirAssaultSoldier &&
                (pCreature->GetEntry() == AV_NPC_ENTRY_GUSE ||
                 pCreature->GetEntry() == AV_NPC_ENTRY_SLIDORE))
            {
                /** Add new gossip for launching order */
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,
                                         uiMessageGlobalAirAssault,
                                         GOSSIP_SENDER_MAIN,
                                         GOSSIP_ACTION_INFO_DEF + BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER + 1 + 50);
            }
            else if (b_objectiveGlobalAirAssaultLieutenant &&
                     (pCreature->GetEntry() == AV_NPC_ENTRY_JEZTOR ||
                      pCreature->GetEntry() == AV_NPC_ENTRY_VIPORE))
            {
                /** Add new gossip for launching order */
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,
                                         uiMessageGlobalAirAssault,
                                         GOSSIP_SENDER_MAIN,
                                         GOSSIP_ACTION_INFO_DEF + BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT + 1 + 50);
            }
            else if (b_objectiveGlobalAirAssaultCommander &&
                     (pCreature->GetEntry() == AV_NPC_ENTRY_MULVERICK ||
                      pCreature->GetEntry() == AV_NPC_ENTRY_ICHMAN))
            {
                /** Add new gossip for launching order */
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,
                                         uiMessageGlobalAirAssault,
                                         GOSSIP_SENDER_MAIN,
                                         GOSSIP_ACTION_INFO_DEF + BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER + 1 + 50);
            }

            if (pCreature->GetEntry() == AV_NPC_QUARTERMASTER_A || pCreature->GetEntry() == AV_NPC_QUARTERMASTER)
            {
                if (pCreature->IsVendor())
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

                pPlayer->SEND_GOSSIP_MENU(6255, pCreature->GetGUID());

                return true;
            }
            else
            {
                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature),
                                          pCreature->GetObjectGuid());
            }
        }
        /** Emote showing end of resources gathering */
        pCreature->HandleEmote(EMOTE_ONESHOT_BOW);
        return true;
    }
    else if (pCreature->IsQuestGiver())
    {
        if (pCreature->GetEntry() == AV_NPC_QUARTERMASTER_A || pCreature->GetEntry() == AV_NPC_QUARTERMASTER)
        {
            if (pCreature->IsVendor())
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            pPlayer->SEND_GOSSIP_MENU(6255, pCreature->GetGUID());
            return true;
        }

        if (pCreature->GetEntry() == AV_NPC_ARCHDRUID_RENFERAL || pCreature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
        {
            if (BattleGround* bg = pPlayer->GetBattleGround())
            {
                uint32 currentCounter = ((BattleGroundAV*)bg)->getChallengeInvocationCounter(m_faction_id, BG_AV_BLOOD_WORLDBOSS_ASSAULT);
                uint32 gossipOptionBroadcastID = 0;
                uint8 gossipOptionID = 0;

                if (currentCounter >= 160)
                {
                    gossipOptionID = 2;
                    gossipOptionBroadcastID = (m_faction_id == BG_TEAM_ALLIANCE) ? GOSSIP_RENFERAL_BOSS3 : GOSSIP_THURLOGA_BOSS3;
                }
                else if (currentCounter >= 100)
                {
                    gossipOptionID = 1;
                    gossipOptionBroadcastID = (m_faction_id == BG_TEAM_ALLIANCE) ? GOSSIP_RENFERAL_BOSS2 : GOSSIP_THURLOGA_BOSS2;
                }
                else
                    gossipOptionBroadcastID = (m_faction_id == BG_TEAM_ALLIANCE) ? GOSSIP_RENFERAL_BOSS1 : GOSSIP_THURLOGA_BOSS1;

                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, gossipOptionBroadcastID, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + BG_AV_BLOOD_WORLDBOSS_ASSAULT + 200 + gossipOptionID);
            }
        }

        /** NPC keep is gossip menu */
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    }
    return true;
}

/*********TROOPS CHIEF ************/

struct AV_npc_troops_chief_EventAI : public npc_escortAI
{
    uint32 m_faction_id;
    bool   isAggro;
    bool   b_isSpeechDone;
    uint32 Event_Timer;
    uint32 Point;

    AV_npc_troops_chief_EventAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        b_isSpeechDone = false;
        isAggro = false;
        Reset();
    }

    void Reset() override
    {
        if (isAggro)
        {
            SetEscortPaused(false);
            float fPosX, fPosY, fPosZ;
            m_creature->GetCombatStartPosition(fPosX, fPosY, fPosZ);
            m_creature->GetMotionMaster()->MovePoint(POINT_LAST_POINT, fPosX, fPosY, fPosZ);
            isAggro = false;
        }
    }

    void Aggro(Unit* pWho) override
    {
        isAggro = true;
        SetEscortPaused(true);
    }

    void WaypointReached(uint32 i) override
    {
        switch (i)
        {
            case 2:
                if (m_creature->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
                {
                    SetEscortPaused(true);
                    DoScriptText(SAY_RAMRIDER_CMD, m_creature);
                    Event_Timer = 6000;
                    Point = i;
                }
                else if (m_creature->GetEntry() == AV_NPC_WARMASTER_CMD)
                {
                    SetEscortPaused(true);
                    DoScriptText(SAY_WOLFRIDER_CMD, m_creature);
                    Event_Timer = 6000;
                    Point = i;
                }
                break;
            case 48:
                if (m_creature->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
                {
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();
                }
                break;
            case 53:
                if (m_creature->GetEntry() == AV_NPC_WARMASTER_CMD)
                {
                    m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                    Stop();
                }
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* pWho) override
    {
        isAggro = false;
        // Unlock speech for Cavalry again
        b_isSpeechDone = false;
        uint32 m_uiTroopsType = 0;

        if (m_creature->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
            m_uiTroopsType = AV_NPC_FROSTWOLF_REAVER;
        else if (m_creature->GetEntry() == AV_NPC_WARMASTER_CMD)
            m_uiTroopsType = AV_NPC_STORMPIKE_COMMANDO;
        else
            return;

        /** Loop to check all 4 possibles kind of troops for each faction
         * This method is used since every possible kind got an idea incremented one by one */
        for (int i = 0; i < 4; i++)
        {
            std::list<Creature*> m_RamRiderList;
            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, m_uiTroopsType + i, 100.0f);
            for (const auto& it : m_RamRiderList)
            {
                /** Start escort for troops since leader is dead */
                if (AV_npc_troops_chief_EventAI* pEscortAI = dynamic_cast<AV_npc_troops_chief_EventAI*>(it->AI()))
                    pEscortAI->Start(true, 0, nullptr, false);
            }
            m_RamRiderList.clear();
        }


    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        uint32 m_uiTroopsType = 0;
        uint16 m_uiWarcryBC;

        if (m_creature->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
        {
            m_uiTroopsType = AV_NPC_STORMPIKE_COMMANDO;
            m_uiWarcryBC = SAY_WARCRY_ALIANCE;
        }
        else if (m_creature->GetEntry() == AV_NPC_WARMASTER_CMD)
        {
            m_uiTroopsType = AV_NPC_FROSTWOLF_REAVER;
            m_uiWarcryBC = SAY_WARCRY_HORDE;
        }

        if (Event_Timer <= uiDiff)
        {
            switch (Point)
            {
                case 2:
                {
                    if (!b_isSpeechDone)
                    {
                        b_isSpeechDone = true;
                        m_creature->SetWalk(false);
                        /** Loop to check all 4 possibles kind of troops for each faction
                         * This method is used since every possible kind got an idea incremented one by one */
                        for (int i = 0; i < 4; i++)
                        {
                            std::list<Creature*> m_RamRiderList;
                            GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, m_uiTroopsType + i, 40.0f);
                            for (const auto& it : m_RamRiderList)
                            {
                                DoScriptText(m_uiWarcryBC, it);
                                it->SetWalk(false);

                                /** Link all the troops to the leader */
                                it->JoinCreatureGroup(m_creature,
                                                         m_creature->GetAngle(it) - it->GetOrientation(),
                                                         m_creature->GetDistance(it),
                                                         OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER | OPTION_EVADE_TOGETHER);
                            }
                            m_RamRiderList.clear();
                        }
                    }
                    SetEscortPaused(false);
                    Event_Timer = 0;
                    break;
                }

                default:
                    break;
            }
        }
        else
            Event_Timer -= uiDiff;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

bool QuestComplete_AV_npc_ram_wolf(Player* pPlayer, Creature* pQuestGiver, Quest const* pQuest)
{
    if (pQuestGiver->GetEntry() == NPC_TAME_MASTER_ALLIANCE)
        pPlayer->SetQuestStatus(pQuest->GetQuestId(), QUEST_STATUS_NONE);
    return false;
}

bool QuestComplete_AV_npc_troops_chief(Player* pPlayer, Creature* pQuestGiver, Quest const* pQuest)
{
    /** Check if NPC is linked to a quest */
    if (!pQuest->ReqItemId[0] || !pQuest->ReqItemCount[0])
        return false;

    uint32 m_faction_id           = (pPlayer->GetTeam() == ALLIANCE) ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE;

    if (pQuestGiver->GetEntry() == AV_NPC_MARSHAL_TERAVAINE)
    {
        pQuestGiver->HandleEmote(EMOTE_ONESHOT_SHOUT);
    }
    else if (pQuestGiver->GetEntry() == AV_NPC_WARMASTER_CMD)
    {
        pQuestGiver->HandleEmote(EMOTE_ONESHOT_SHOUT);
    }

    if (BattleGround* bg = pPlayer->GetBattleGround())
    {
        if (bg->GetTypeID() == BATTLEGROUND_AV)
        {
            /** Quest isn't completed because of an item but because a creature
              * came near quest giver -specific case- */
            if (pQuest->GetQuestId() == QUEST_TROOPS_ORDER_H ||
                pQuest->GetQuestId() == QUEST_TROOPS_ORDER_A)
            {
                ((BattleGroundAV*)bg)->resetGroundChallengeInvocation(m_faction_id);
                ((BattleGroundAV*)bg)->setPlayerGoStatus(m_faction_id, BG_AV_GROUND_ASSAULT, true);

                if (AV_npc_troops_chief_EventAI* pEscortAI = dynamic_cast<AV_npc_troops_chief_EventAI*>(pQuestGiver->AI()))
                {
                    pEscortAI->Start(true, 0, nullptr, false);
                    pQuestGiver->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pQuestGiver->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                    pQuestGiver->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
                    pQuestGiver->SetWalk(true);
                }
            }
        }
    }
    return true;
}

/********END TROOPS CHIEF*******/


/***************/

enum
{
    SAY_WOLFRIDER = 8887,
    SAY_RAMRIDER  = 8905,
    SAY_PATROL    = 8907,
    SAY_REAVERS   = 8913,
    SAY_GUSE      = 10339,
    SAY_JEZTOR    = 10342,
    SAY_MULV      = 10347,
    SAY_VIPORE    = 10357,
    SAY_ICHMAN    = 10358,
};

bool GossipSelect_npc_AVBlood_collector(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    uint16 uiMessage = 0;
    uint32 challenge  = uiAction - (GOSSIP_ACTION_INFO_DEF + 1);

    if (uiAction == GOSSIP_ACTION_TRADE)
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
    else if (uiAction >= GOSSIP_ACTION_INFO_DEF + 1)
    {

        if (pCreature->GetEntry() != AV_NPC_ENTRY_MURGOT && pCreature->GetEntry() != AV_NPC_ENTRY_REGZAR &&
            challenge < BG_AV_NB_CHALLENGES + 10)
            pPlayer->CLOSE_GOSSIP_MENU();

        /** Emote message */
        if (pCreature->GetEntry() == AV_NPC_RAMRIDER_CMD)
            uiMessage = SAY_RAMRIDER;
        else if (pCreature->GetEntry() == AV_NPC_WOLFRIDER_CMD)
            uiMessage = SAY_WOLFRIDER;
        else if (pCreature->GetEntry() == AV_NPC_QUARTERMASTER_A)
            uiMessage = SAY_PATROL;
        else if (pCreature->GetEntry() == AV_NPC_QUARTERMASTER)
            uiMessage = SAY_REAVERS;
        else if (pCreature->GetEntry() == AV_NPC_ENTRY_JEZTOR)
            uiMessage = SAY_JEZTOR;
        else if (pCreature->GetEntry() == AV_NPC_ENTRY_GUSE)
            uiMessage = SAY_GUSE;
        else if (pCreature->GetEntry() == AV_NPC_ENTRY_MULVERICK)
            uiMessage = SAY_MULV;
        else if (pCreature->GetEntry() == AV_NPC_ENTRY_ICHMAN)
            uiMessage = SAY_ICHMAN;
        else if (pCreature->GetEntry() == AV_NPC_ENTRY_VIPORE)
            uiMessage = SAY_VIPORE;

        if (pCreature->GetEntry() != AV_NPC_ENTRY_MURGOT && pCreature->GetEntry() != AV_NPC_ENTRY_REGZAR &&
            challenge < BG_AV_NB_CHALLENGES + 10)
        {
            DoScriptText(uiMessage, pCreature);
            pCreature->HandleEmote(EMOTE_ONESHOT_SHOUT);
        }

        /** RESET CHALLENGE RESOURCES */
        if (BattleGround* bg = pPlayer->GetBattleGround())
        {
            if (bg->GetTypeID() == BATTLEGROUND_AV)
            {
                uint32 playerFactionId = (pPlayer->GetTeam() == ALLIANCE) ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE;
                //                uint32 challenge  = uiAction - (GOSSIP_ACTION_INFO_DEF + 1);
                uint32 itemId    = 0;

                /** Reset corresponding challenge resources */
                switch (challenge)
                {
                    case BG_AV_SOLDIER_AIR_ASSAULT:
                        ((BattleGroundAV*)bg)->
                        resetAerialChallengeInvocation(playerFactionId,
                                                       BG_AV_AIR_ASSAULT_BEACON_SOLDIER);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_AIR_ASSAULT_BEACON_SOLDIER, true);

                        /** Select beacon item depending on the player faction */
                        if (playerFactionId == BG_TEAM_HORDE)
                            itemId = ITEM_BEACON_GUSE;
                        else
                            itemId = ITEM_BEACON_VIPORE;

                        if (!pPlayer->HasItemCount(itemId, 1, true))
                        {
                            uint32 noSpaceForCount = 0;
                            ItemPosCountVec dest;
                            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT,
                                                                 dest, itemId, 1, &noSpaceForCount);

                            if (msg == EQUIP_ERR_OK)
                            {
                                Item* pItem = pPlayer->StoreNewItem(dest, itemId,
                                                                    true, Item::GenerateItemRandomPropertyId(itemId));
                                pPlayer->SendNewItem(pItem, 1, true, false);
                            }
                        }
                        break;

                    case BG_AV_LIEUTENANT_AIR_ASSAULT:
                        ((BattleGroundAV*)bg)->
                        resetAerialChallengeInvocation(playerFactionId,
                                                       BG_AV_AIR_ASSAULT_BEACON_LIEUTENANT);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_AIR_ASSAULT_BEACON_LIEUTENANT, true);

                        /** Select beacon item depending on the player faction */
                        if (playerFactionId == BG_TEAM_HORDE)
                            itemId = ITEM_BEACON_JETZOR;
                        else
                            itemId = ITEM_BEACON_SLIDORE;

                        /** Generate corresponding object*/
                        if (!pPlayer->HasItemCount(itemId, 1, true))
                        {
                            uint32 noSpaceForCount = 0;
                            ItemPosCountVec dest;
                            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT,
                                                                 dest, itemId, 1, &noSpaceForCount);
                            if (msg == EQUIP_ERR_OK)
                            {
                                Item* pItem = pPlayer->StoreNewItem(dest, itemId,
                                                                    true, Item::GenerateItemRandomPropertyId(itemId));
                                pPlayer->SendNewItem(pItem, 1, true, false);
                            }
                        }

                        break;

                    case BG_AV_COMMANDER_AIR_ASSAULT:
                        ((BattleGroundAV*)bg)->
                        resetAerialChallengeInvocation(playerFactionId,
                                                       BG_AV_AIR_ASSAULT_BEACON_COMMANDER);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_AIR_ASSAULT_BEACON_COMMANDER, true);

                        /** Select beacon item depending on the player faction */
                        if (playerFactionId == BG_TEAM_HORDE)
                            itemId = ITEM_BEACON_MULVERICK;
                        else
                            itemId = ITEM_BEACON_ICHMAN;

                        if (!pPlayer->HasItemCount(itemId, 1, true))
                        {
                            uint32 noSpaceForCount = 0;
                            ItemPosCountVec dest;
                            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT,
                                                                 dest, itemId, 1, &noSpaceForCount);
                            if (msg == EQUIP_ERR_OK)
                            {
                                Item* pItem = pPlayer->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
                                pPlayer->SendNewItem(pItem, 1, true, false);
                            }
                        }
                        break;

                    case BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER+50:
                        ((BattleGroundAV*)bg)->
                        resetAerialChallengeInvocation(playerFactionId,
                                                       BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_AIR_ASSAULT_GLOBAL_SOLDIER, true);
                        break;

                    case BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT+50:
                        ((BattleGroundAV*)bg)->
                        resetAerialChallengeInvocation(playerFactionId,
                                                       BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_AIR_ASSAULT_GLOBAL_LIEUTENANT, true);
                        break;

                    case BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER+50:
                        ((BattleGroundAV*)bg)->
                        resetAerialChallengeInvocation(playerFactionId,
                                                       BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_AIR_ASSAULT_GLOBAL_COMMANDER, true);
                        break;

                    case BG_AV_HIDE_CAVALRY_ASSAULT:
                    case BG_AV_TAMED_CAVALRY_ASSAULT:
                        ((BattleGroundAV*)bg)->
                        resetCavalryChallengeInvocation(playerFactionId);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_CAVALRY_ASSAULT, true);

                        if (AV_NpcEventAI* pEscortAI = dynamic_cast<AV_NpcEventAI*>(pCreature->AI()))
                        {
                            pEscortAI->Start(true, 0, nullptr, false);
                            //pCreature->SetFactionTemplateId(pPlayer->GetFactionTemplateId());
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
                            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
                        }
                        break;

                    case BG_AV_IRONDEEP_GROUND_ASSAULT:
                    case BG_AV_COLDTOOTH_GROUND_ASSAULT:
                        ((BattleGroundAV*)bg)->
                        resetGroundChallengeInvocation(playerFactionId);

                        if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                            pCreature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        ((BattleGroundAV*)bg)->
                        setPlayerGoStatus(playerFactionId, BG_AV_GROUND_ASSAULT, true);


                        /** Select beacon item depending on the player faction */
                        if (playerFactionId == BG_TEAM_HORDE)
                            itemId = ITEM_ASSAULT_ORDER_FROSTWOLF;
                        else
                            itemId = ITEM_ASSAULT_ORDER_STORMPIKE;

                        if (!pPlayer->HasItemCount(itemId, 1, true))
                        {
                            uint32 noSpaceForCount = 0;
                            ItemPosCountVec dest;
                            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT,
                                                                 dest, itemId, 1, &noSpaceForCount);
                            if (msg == EQUIP_ERR_OK)
                            {
                                Item* pItem = pPlayer->StoreNewItem(dest, itemId,
                                                                    true, Item::GenerateItemRandomPropertyId(itemId));
                                pPlayer->SendNewItem(pItem, 1, true, false);
                            }
                        }
                        break;
                    case BG_AV_NB_CHALLENGES:
                        pPlayer->SEND_GOSSIP_MENU(6784, pCreature->GetGUID()); //I barely have any supplies for upgrades.
                        break;
                    case BG_AV_NB_CHALLENGES+1:
                        pPlayer->SEND_GOSSIP_MENU(6780, pCreature->GetGUID()); //I have about half the supplies needed to upgrade to seasoned units.
                        break;
                    case BG_AV_NB_CHALLENGES+2:
                        pPlayer->SEND_GOSSIP_MENU(6781, pCreature->GetGUID()); //I have about half the supplies needed to upgrade to veteran units.
                        break;
                    case BG_AV_NB_CHALLENGES+3:
                        pPlayer->SEND_GOSSIP_MENU(6783, pCreature->GetGUID()); //I have about half the supplies needed to upgrade to champion units.
                        break;
                    case BG_AV_NB_CHALLENGES+4:
                        pPlayer->SEND_GOSSIP_MENU(6778, pCreature->GetGUID()); //I almost have enough supplies to upgrade our troops to seasoned.
                        break;
                    case BG_AV_NB_CHALLENGES+5:
                        pPlayer->SEND_GOSSIP_MENU(6779, pCreature->GetGUID()); //I almost have enough supplies to upgrade our troops to veteran.
                        break;
                    case BG_AV_NB_CHALLENGES+6:
                        pPlayer->SEND_GOSSIP_MENU(6782, pCreature->GetGUID()); //I almost have enough supplies to upgrade our troops to champion.
                        break;
                    case BG_AV_NB_CHALLENGES+13:
                        pPlayer->SEND_GOSSIP_MENU(6733, pCreature->GetGUID());
                        break;
                    case BG_AV_NB_CHALLENGES+12:
                        pPlayer->SEND_GOSSIP_MENU(6732, pCreature->GetGUID());
                        break;
                    case BG_AV_NB_CHALLENGES+14:
                        pPlayer->SEND_GOSSIP_MENU(6731, pCreature->GetGUID());
                        break;
                    case BG_AV_BLOOD_WORLDBOSS_ASSAULT + 199:
                        if (pCreature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                            pPlayer->SEND_GOSSIP_MENU(NPCTEXT_THURLOGA_BOSS1, pCreature->GetGUID());
                        else
                            pPlayer->SEND_GOSSIP_MENU(NPCTEXT_RENFERAL_BOSS1, pCreature->GetGUID());
                        break;
                    case BG_AV_BLOOD_WORLDBOSS_ASSAULT + 200:
                        if (pCreature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                            pPlayer->SEND_GOSSIP_MENU(NPCTEXT_THURLOGA_BOSS2, pCreature->GetGUID());
                        else
                            pPlayer->SEND_GOSSIP_MENU(NPCTEXT_RENFERAL_BOSS2, pCreature->GetGUID());
                        break;
                    case BG_AV_BLOOD_WORLDBOSS_ASSAULT + 201:
                        if (pCreature->GetEntry() == AV_NPC_PRIMALIST_THURLOGA)
                            pPlayer->SEND_GOSSIP_MENU(NPCTEXT_THURLOGA_BOSS3, pCreature->GetGUID());
                        else
                            pPlayer->SEND_GOSSIP_MENU(NPCTEXT_RENFERAL_BOSS3, pCreature->GetGUID());
                        break;
                    case 500:
                        ((BattleGroundAV*)bg)->UpgradeArmor(pCreature, pPlayer);
                        break;
                    case 1000:
                        ((BattleGroundAV*)bg)->UpgradeArmor(pCreature, pPlayer);
                        break;
                    case 1500:
                        ((BattleGroundAV*)bg)->UpgradeArmor(pCreature, pPlayer);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}

/**********/

enum
{
    SPELL_AV_FIREBALL         = 22088,
    SPELL_AV_FIREBALL_VOLLEY  = 15285,
    SPELL_AV_STUN_BOMB_ATTACK = 21188,
};

/** Scripted used for aerial strike by the following NPC :
 * Guse's      War Rider (entry:14943) # Patrol between Icewing Bunker and Stormpike Graveyard
 * Jetzor's    War Rider (entry:14944) # Patrol between Stormpike graveyard and Dun Baldar North Bunker
 * Mulverick's War Rider (entry:14945) # Dun Baldar base
 * Slidore's   Gryphon   (entry:14946) # Patrol between Tower Point and Frostwolf graveyard
 * Ichman's    Gryphon   (entry:14947) # Frostwolf village
 * Vipore's    Gryphon   (entry:14948) # Frostwolf village
 *
 * Seems like NPC got 130.000hp, elite, 3850 armor, 20 resist all magic schools, 259/345 physical damage
 *
 * Actually these NPC got a model equivalent to the mount only.
 * No NPC are on the mount (same case as on on official server.
 *
 * GROWTH POTENTIAL :
 * ### Add sounds features (ex: http://www.wowhead.com/npc=14948#sounds)
 * ### Aerial unit were bugged on official, it was possible to pull the unit so that it touch the ground
 * */

struct MoveLocations
{
    float x, y, z, an;
};

#define AV_RadiusPatrol 20

struct AV_WarRiderAI : public ScriptedAI
{
    AV_WarRiderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_creature->SetCasterChaseDistance(25.0f);
        m_creature->SetWanderDistance(55.0f);
        isMovingToPoint = false;
        Reset();
    }

    uint32 m_uiTimerGoDown;
    uint32 m_uiCurrentWaypoint;
    uint32 m_uiFireball_Timer;
    uint32 m_uiFireballVolley_Timer;
    uint32 m_uiStunBombAttack_Timer;
    bool isAttacking;
    bool isMovingToPoint;

    void Reset() override
    {
        isAttacking = false;
        m_creature->SetFly(true);
        m_creature->SetWalk(false);
        m_uiCurrentWaypoint      = 0;
        m_uiFireball_Timer       =  0;
        m_uiFireballVolley_Timer =  8000;
        m_uiStunBombAttack_Timer = 13000;
        m_uiTimerGoDown = 2000;
    }
    void JustReachedHome() override
    {
        m_creature->GetMotionMaster()->MoveRandom();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!isMovingToPoint)
        {
            float x, y, z;
            switch (m_creature->GetEntry())
            {
                case AV_NPC_WARRIDER_GUSE:
                case AV_NPC_WARRIDER_MULVERICK:
                case AV_NPC_WARRIDER_JEZTOR:
                    x = 618.4f;
                    y = -87.97f,
                    z = 85.77f;
                    break;
                case AV_NPC_WARRIDER_SLIDORE:
                case AV_NPC_WARRIDER_ICHMAN:
                case AV_NPC_WARRIDER_VIPORE:
                    x = -1311.53f;
                    y = -355.28f;
                    z = 130.93f;
                    break;
                default:
                    return;
            }
            //m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
            m_creature->SetHomePosition(x, y, z, 0.);
            isMovingToPoint = true;
            EnterEvadeMode();
            return;
        }


        /** Patrol moving in circle from the spawn position */
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            // Find new target
            if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != HOME_MOTION_TYPE)
                if (Unit* target = m_creature->SelectNearestTarget(50.0f))
                    AttackStart(target);
            return;
        }

        if (m_creature->IsWithinDistInMap(m_creature->GetVictim(), 30.0f))
        {
            if (m_uiFireball_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_AV_FIREBALL) == CAST_OK)
                    m_uiFireball_Timer = 5000;
            }
            else
                m_uiFireball_Timer -= uiDiff;

            if (m_uiFireballVolley_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_AV_FIREBALL_VOLLEY) == CAST_OK)
                    m_uiFireballVolley_Timer = 7500;
            }
            else
                m_uiFireballVolley_Timer -= uiDiff;

            if (m_uiStunBombAttack_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_AV_STUN_BOMB_ATTACK) == CAST_OK)
                    m_uiStunBombAttack_Timer = 9000;
            }
            else
                m_uiStunBombAttack_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
        // else : ChaseMovement will handle it :)
    }
};

enum
{
    AV_GOB_MULVERICK_BEACON = 178549,
    AV_GOB_GUSE_BEACON      = 178545,
    AV_GOB_JETZOR_BEACON    = 178547,
    AV_GOB_ICHMAN_BEACON    = 178726,
    AV_GOB_VIPORE_BEACON    = 178724,
    AV_GOB_SLIDOR_BEACON    = 178725,
};

struct AV_BeaconInvocationObjectAI : public GameObjectAI
{
    AV_BeaconInvocationObjectAI(GameObject* gobj) : GameObjectAI(gobj)
    {
        /** The summon effect changes the level to the caster level. As a consequence, it is impossible to use the gobj. Let's restore it. */
        gobj->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
        Reset();
        switch (gobj->GetEntry())
        {
            case AV_GOB_ICHMAN_BEACON:
            case AV_GOB_VIPORE_BEACON:
            case AV_GOB_SLIDOR_BEACON:
                m_isAllianceBeacon = true;
                break;
            default:
                m_isAllianceBeacon = false;
                break;
        }

        gobj->SetOwnerGuid(ObjectGuid());
        if (m_isAllianceBeacon)
            gobj->SetUInt32Value(GAMEOBJECT_FACTION, 83);
        else
            gobj->SetUInt32Value(GAMEOBJECT_FACTION, 84);

    }

    bool   m_isAllianceBeacon;
    uint32 m_invocationTimer;

    void Reset()
    {
        m_invocationTimer = 60000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_invocationTimer < uiDiff)
        {
            /** Spawn a War rider creature */
            me->SummonCreature(m_isAllianceBeacon ? AV_NPC_AERIEGRYPHON : AV_NPC_WARRIDER,
                               me->GetPositionX(),
                               me->GetPositionY(),
                               me->GetPositionZ() + 30,
                               me->GetOrientation(),
                               TEMPSUMMON_CORPSE_DESPAWN, 10000);

            /** Delete beacon */
            me->AddObjectToRemoveList();
        }
        else
            m_invocationTimer -= uiDiff;
    }
    /** Triggered when a player successfully finishes the channelling. Disable the beacon. */
    bool OnUse(Unit* /*user*/) override
    {
        me->AddObjectToRemoveList();
        return true;
    }
};

class go_av_landmineAI: public GameObjectAI
{
    public:
        go_av_landmineAI(GameObject* gobj) : GameObjectAI(gobj), m_respawnTimer(180)
        {
            switch (gobj->GetEntry())
            {
                case GOBJ_LANDMINE_H2:
                    m_eventIdx = BG_AV_LANDMINES_HORDE;
                    break;
                case GOBJ_LANDMINE_A2:
                    m_eventIdx = BG_AV_LANDMINES_ALLIANCE;
                    break;
            }
            if (GameObjectData const* info = me->GetGOData())
                m_respawnTimer = info->GetRandomRespawnTime();
        }
        void UpdateAI(uint32 const diff) override
        {
            if (me->isSpawned())
                return;
            Map* map = me->GetMap();
            if (!map->IsBattleGround())
                return;
            BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(((BattleGroundMap*)map)->GetBG());
            if (!bg)
                return;
            if (!bg->IsActiveEvent(m_eventIdx, 0))
                me->SetRespawnTime(urand(m_respawnTimer / 2, m_respawnTimer));
        }
        bool OnUse(Unit* user) override
        {
            if (!me->IsHostileTo(user))
                return true; // Do not attack friends !
            me->Despawn();
            return false; // Deal the damage.
        }
    protected:
        uint8 m_eventIdx;
        uint32 m_respawnTimer;
};

/******* WORLD BOSS HORDE ********/

enum
{
    SPELL_WB_BLIZZARD      = 21367,
    SPELL_WB_FROSTBOLT     = 21369,
    SPELL_WB_FROSTNOVA     = 14907,
    SPELL_WB_FROSTSHOCK    = 19133,
    SPELL_WB_ICEBLAST      = 15878,
    SPELL_WB_ICETOMB       = 16869,
    SPELL_WB_SWELLOFSOULS  = 21307,
};

class av_world_boss_baseai: public npc_escortAI
{
        uint8 m_bgEvent;
    public:
        av_world_boss_baseai(Creature* c, uint8 bgEvent) : npc_escortAI(c), m_bgEvent(bgEvent)
        {
            Map* m = c->GetMap();
            if (!m || !m->IsBattleGround())
                return;
            BattleGround* bg = ((BattleGroundMap*)m)->GetBG();
            if (bg->IsActiveEvent(bgEvent, 0))
            {
                m_creature->DeleteLater();
                return;
            }
            bg->SpawnEvent(bgEvent, 0, true, true);
        }
        void EnterEvadeMode() override
        {
            // Modified version of npc_escortAI::EnterEvadeMode
            Unit::SpellAuraHolderMap& creatureAuras = m_creature->GetSpellAuraHolderMap();
            for (Unit::SpellAuraHolderMap::iterator iter = creatureAuras.begin(); iter != creatureAuras.end();)
            {
                if (!iter->second->IsPositive())
                {
                    m_creature->RemoveSpellAuraHolder(iter->second, AURA_REMOVE_BY_DEFAULT);
                    iter = creatureAuras.begin();
                }
                else
                    ++iter;
            }
            m_creature->DeleteThreatList();
            m_creature->CombatStop(true);
            m_creature->SetLootRecipient(nullptr);

            // Back on escart_ai path.
            ReturnToCombatStartPosition();
            Reset();
        }
        void JustDied(Unit* killer) override
        {
            Map* m = m_creature->GetMap();
            if (!m || !m->IsBattleGround())
                return;
            BattleGround* bg = ((BattleGroundMap*)m)->GetBG();
            bg->SpawnEvent(m_bgEvent, 0, false, true); // Despawn double wordboss protection

            ScriptedAI::JustDied(killer);
        }
};

enum
{
    SAY_LOKHOLAR_SPAWN_1 = 8616,
    SAY_LOKHOLAR_SPAWN_2 = 8617,
    SAY_LOKHOLAR_KILLED_PLAYER = 8618,
    SAY_LOKHOLAR_REACHED_BASE = 8740,
};

struct AV_NpcEventWorldBoss_H_AI : public av_world_boss_baseai
{
    AV_NpcEventWorldBoss_H_AI(Creature* pCreature) : av_world_boss_baseai(pCreature, BG_AV_BOSS_LOKHOLAR_H)
    {
        isAggro = false;
        isEngageModeStarted = false;
        isInvocated = false;

        Map::PlayerList const &liste = m_creature->GetMap()->GetPlayers();
        for (const auto& i : liste)
        {
            if (i.getSource()->IsAlive())
                i.getSource()->RemoveAurasDueToSpell(11206);
        }

        /** Once invocation is done, World Boss doesn't start waypoint path for 10 minutes. */
        m_uiEngageTimer = 1000; //600000

        /** Once WB is invocated, suppress invocation rune to disable further invocation (only one per Battleground) */
        std::list<GameObject*> invocationObjectList;
        GetGameObjectListWithEntryInGrid(invocationObjectList, m_creature, OBJECT_WB_H_INVOCATION, 200.0f);
        for (const auto& it : invocationObjectList)
            it->Delete();

        /** Stop invocation from Frostwolf Shaman */
        std::list<Creature*> ramRidersList;
        GetCreatureListWithEntryInGrid(ramRidersList, m_creature, AV_NPC_FROSTWOLF_SHAMAN, 200.0f);
        for (const auto& it : ramRidersList)
            it->InterruptNonMeleeSpells(true);

        /** Stop invocation from Thurloga */
        std::list<Creature*> thurlogaList;
        GetCreatureListWithEntryInGrid(thurlogaList, m_creature, AV_NPC_PRIMALIST_THURLOGA, 200.0f);
        for (const auto& it : thurlogaList)
            it->InterruptNonMeleeSpells(true);

        isYelling = false;
        Reset();
    }

    uint32 m_uiBlizzardTimer;
    uint32 m_uiFrostBoltTimer;
    uint32 m_uiFrostNovaTimer;
    uint32 m_uiFrostShockTimer;
    uint32 m_uiIceBlastTimer;
    uint32 m_uiIceTombTimer;
    bool   isAggro;
    bool   isEngageModeStarted;
    uint32 Point;
    uint32 m_uiEngageTimer;
    bool   isInvocated;
    bool   isYelling;

    void Reset() override
    {
        m_uiBlizzardTimer   = 10000;
        m_uiFrostBoltTimer  = 1000;
        m_uiFrostNovaTimer  = 8500;
        m_uiFrostShockTimer = 4000;
        m_uiIceBlastTimer   = 9000;
        m_uiIceTombTimer    = 5500;

        if (isAggro)
        {
            SetEscortPaused(false);
            float fPosX, fPosY, fPosZ;
            m_creature->GetCombatStartPosition(fPosX, fPosY, fPosZ);
            m_creature->GetMotionMaster()->MovePoint(POINT_LAST_POINT, fPosX, fPosY, fPosZ);
            m_creature->SetWalk(true);
            isAggro = false;
        }
    }

    void Aggro(Unit* pWho) override
    {
        isAggro = true;
        SetEscortPaused(true);
    }

    void WaypointReached(uint32 i) override
    {
        /** If last waypoint reached, then say "Your base is forfeit, puny mortals!" */
        switch (i)
        {
            case 30:
                DoScriptText(SAY_LOKHOLAR_REACHED_BASE, m_creature);
                m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f);
                break;
            case 31:
                Stop();
                break;
        }
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
        {
            /** Each time a player is killed, cast Swell of Souls spell.
             * Maximum of 20 stacks allowed. */
            DoScriptText(SAY_LOKHOLAR_KILLED_PLAYER, m_creature);
            DoCastSpellIfCan(m_creature, SPELL_WB_SWELLOFSOULS, true);
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!isYelling)
        {
            DoScriptText(SAY_LOKHOLAR_SPAWN_1, m_creature);

            static ScriptInfo si;
            si.command = SCRIPT_COMMAND_TALK;
            si.talk.textId[0] = SAY_LOKHOLAR_SPAWN_2;
            m_creature->GetMap()->ScriptCommandStart(si, 3, m_creature->GetObjectGuid(), m_creature->GetObjectGuid());

            isYelling = true;
        }

        if (!isInvocated)
        {
            m_creature->SetHomePosition(-260.0f, -290.0f, 6.7f, 0.0f);
            m_creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
            m_creature->SetWanderDistance(55.0f);
            m_creature->SetWalk(false);
            isInvocated = true;
        }
        if (m_uiEngageTimer < uiDiff && !isEngageModeStarted)
        {
            /** Start waypoint path system */
            Start(false, 0, nullptr, false);
            isEngageModeStarted = true;
        }
        else
            m_uiEngageTimer -= uiDiff;


        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiBlizzardTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_BLIZZARD) == CAST_OK)
                m_uiBlizzardTimer = urand(10000, 12000);
        }
        else
            m_uiBlizzardTimer -= uiDiff;

        if (m_uiFrostBoltTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_FROSTBOLT) == CAST_OK)
                m_uiFrostBoltTimer = urand(4500, 6500);
        }
        else
            m_uiFrostBoltTimer -= uiDiff;

        if (m_uiFrostNovaTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_FROSTNOVA) == CAST_OK)
                m_uiFrostNovaTimer = urand(8000, 12000);
        }
        else
            m_uiFrostNovaTimer -= uiDiff;

        if (m_uiFrostShockTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_FROSTSHOCK) == CAST_OK)
                m_uiFrostShockTimer = urand(3000, 5000);
        }
        else
            m_uiFrostShockTimer -= uiDiff;

        if (m_uiIceBlastTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_ICEBLAST) == CAST_OK)
                m_uiIceBlastTimer = urand(10000, 12000);
        }
        else
            m_uiIceBlastTimer -= uiDiff;

        if (m_uiIceTombTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_ICETOMB) == CAST_OK)
                m_uiIceTombTimer = urand(8000, 12000);
        }
        else
            m_uiIceTombTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

/******* WORLD BOSS HORDE ********/

enum
{
    SPELL_WB_ROOTS         = 20654,
    SPELL_WB_FAERIEFIRE    = 21670,
    SPELL_WB_MOONFIRE      = 21669,
    SPELL_WB_STARFIRE      = 21668,
    SPELL_WB_WRATH         = 21667,

    SAY_IVUS_SPAWNED       = 8736,
    SAY_IVUS_PAST_FIELD    = 8737,
    SAY_IVUS_REACHED_BASE  = 8739,
};

struct AV_NpcEventWorldBoss_A_AI : public av_world_boss_baseai
{
    AV_NpcEventWorldBoss_A_AI(Creature* pCreature) : av_world_boss_baseai(pCreature, BG_AV_BOSS_IVUS_A)
    {
        isAggro = false;
        isEngageModeStarted = false;

        /** Once invocation is done, World Boss doesn't start waypoint path for 10 minutes. */
        m_uiEngageTimer = 1000; //600000;
        isInvocated = false;

        Map::PlayerList const &liste = m_creature->GetMap()->GetPlayers();
        for (const auto& i : liste)
        {
            if (i.getSource()->IsAlive())
                i.getSource()->RemoveAurasDueToSpell(11206);
        }

        /** Once WB is invocated, suppress invocation rune to disable further invocation (only one per Battleground) */
        std::list<GameObject*> m_invocationObjectList;
        GetGameObjectListWithEntryInGrid(m_invocationObjectList, m_creature, OBJECT_WB_A_INVOCATION, 200.0f);
        for (const auto& it : m_invocationObjectList)
            it->Delete();
        m_invocationObjectList.clear();

        /** Stop invocation from Druid of the Grove */
        std::list<Creature*> m_RamRiderList;
        GetCreatureListWithEntryInGrid(m_RamRiderList, m_creature, AV_NPC_DRUID_OF_THE_GROVE, 200.0f);
        for (const auto& it : m_RamRiderList)
            it->InterruptNonMeleeSpells(true);
        m_RamRiderList.clear();

        /** Stop invocation from Renferal */
        std::list<Creature*> m_RenferalList;
        GetCreatureListWithEntryInGrid(m_RenferalList, m_creature, AV_NPC_ARCHDRUID_RENFERAL, 200.0f);
        for (const auto& it : m_RenferalList)
            it->InterruptNonMeleeSpells(true);
        m_RenferalList.clear();

        Reset();
    }

    uint32 m_uiRootsTimer;
    uint32 m_uiFaerieFireTimer;
    uint32 m_uiMoonFireTimer;
    uint32 m_uiStarFireTimer;
    uint32 m_uiWrathTimer;
    bool   isAggro;
    bool   isEngageModeStarted;
    uint32 Point;
    uint32 m_uiEngageTimer;
    bool   isInvocated;

    void Reset() override
    {
        m_uiRootsTimer      = 8500;
        m_uiFaerieFireTimer = 5500;
        m_uiMoonFireTimer   = 7000;
        m_uiStarFireTimer   = 10000;
        m_uiWrathTimer      = 1000;

        if (isAggro)
        {
            SetEscortPaused(false);
            float fPosX, fPosY, fPosZ;
            m_creature->GetCombatStartPosition(fPosX, fPosY, fPosZ);
            m_creature->GetMotionMaster()->MovePoint(POINT_LAST_POINT, fPosX, fPosY, fPosZ);
            m_creature->SetWalk(true);
            isAggro = false;
        }
    }

    void Aggro(Unit* pWho) override
    {
        isAggro = true;
        SetEscortPaused(true);
    }

    void WaypointReached(uint32 i) override
    {
        if (i == 1)
            DoScriptText(SAY_IVUS_PAST_FIELD, m_creature);
        else if (i == 21)
        {
            DoScriptText(SAY_IVUS_REACHED_BASE, m_creature);
            Stop();
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!isInvocated)
        {
            DoScriptText(SAY_IVUS_SPAWNED, m_creature);
            m_creature->SetHomePosition(-260.0f, -290.0f, 6.7f, 0.0f);
            m_creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
            m_creature->SetWanderDistance(55.0f);
            m_creature->SetWalk(false);
            isInvocated = true;
        }

        if (m_uiEngageTimer < uiDiff && !isEngageModeStarted)
        {
            /** Start waypoint path system */
            Start(false, 0, nullptr, false);
            isEngageModeStarted = true;
        }
        else
            m_uiEngageTimer -= uiDiff;


        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiRootsTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_WB_ROOTS) == CAST_OK)
                m_uiRootsTimer = urand(6000, 8000);
        }
        else
            m_uiRootsTimer -= uiDiff;

        if (m_uiFaerieFireTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_FAERIEFIRE) == CAST_OK)
                m_uiFaerieFireTimer = urand(3000, 7000);
        }
        else
            m_uiFaerieFireTimer -= uiDiff;

        if (m_uiMoonFireTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_MOONFIRE) == CAST_OK)
                m_uiMoonFireTimer = urand(8000, 12000);
        }
        else
            m_uiMoonFireTimer -= uiDiff;

        if (m_uiStarFireTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_STARFIRE) == CAST_OK)
                m_uiStarFireTimer = urand(3000, 7000);
        }
        else
            m_uiStarFireTimer -= uiDiff;

        if (m_uiWrathTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WB_WRATH) == CAST_OK)
                m_uiWrathTimer = urand(1000, 3000);
        }
        else
            m_uiWrathTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

enum
{
    COMMANDER_RANDOLPH          = 13139,
    COMMANDER_DARDOSH           = 13140,
    COMMANDER_MULFORT           = 13153,
    COMMANDER_LOUIS             = 13154,
    COMMANDER_DUFFY             = 13319,
    COMMANDER_KARL              = 13320,

    LIEUTENANT_SPENCER          = 13138,
    LIEUTENANT_LARGENT          = 13296,
    LIEUTENANT_STOUTHANDLE      = 13297,
    LIEUTENANT_GREYWAND         = 13298,
    LIEUTENANT_LONADIN          = 13299,
    LIEUTENANT_MANCUSO          = 13300,
    COMMANDER_MORTIMER          = 13318,

    LIEUTENANT_GRUMMUS          = 13145, //no mount for sure
    LIEUTENANT_LEWIS            = 13147,
    LIEUTENANT_MURP             = 13146, //no mount for sure
    LIEUTENANT_STRONGHOOF       = 13143,
    LIEUTENANT_VOLTALAR         = 13144,
    LIEUTENANT_RUGBA            = 13137,
    COMMANDER_MALGOR            = 13152,

    MOUNT_WAR_KODO              = 14348, //OK
    MOUNT_WAR_HORSE             = 14337, //OK
    MOUNT_WAR_BLUE_STRIDER      =  6569, //OK
    MOUNT_WAR_WOLF              = 14334, //OK
    MOUNT_WAR_RAM               = 14577,
    MOUNT_SKELETAL_HORSE        = 10672, //OK
    MOUNT_WAR_RAPTOR            = 14388, //OK
    MOUNT_NIGHTSABER            = 9991   //OK
};

struct AV_CommanderAI : public ScriptedAI
{
    AV_CommanderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        m_uiGripOfCommand_Timer = 0;
    }

    uint32 m_uiGripOfCommand_Timer;

    void Reset() override
    {
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        switch (m_creature->GetEntry())
        {
            case COMMANDER_RANDOLPH:
            case COMMANDER_DARDOSH:
            case COMMANDER_MULFORT:
            case COMMANDER_LOUIS:
            case COMMANDER_DUFFY:
            case COMMANDER_KARL:
                // Aura of command
                if (m_uiGripOfCommand_Timer < uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, 21172) == CAST_OK)
                        m_uiGripOfCommand_Timer = 9000;
                }
                else
                    m_uiGripOfCommand_Timer -= uiDiff;
                break;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

struct AV_DismountAI : public ScriptedAI
{
    AV_DismountAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        m_uiGripOfCommand_Timer = 0;
    }

    uint32 m_uiMount;
    uint32 m_uiGripOfCommand_Timer;

    void Reset() override
    {
        switch (m_creature->GetEntry())
        {
            case LIEUTENANT_LONADIN:
                m_uiMount = MOUNT_NIGHTSABER;
                break;
            case LIEUTENANT_VOLTALAR:
                m_uiMount = MOUNT_WAR_RAPTOR;
                break;
            case LIEUTENANT_LEWIS:
                m_uiMount = MOUNT_SKELETAL_HORSE;
                break;
            case LIEUTENANT_STOUTHANDLE:
            case COMMANDER_MORTIMER:
                m_uiMount = MOUNT_WAR_RAM;
                break;
            case LIEUTENANT_RUGBA:
            case COMMANDER_MALGOR:
                m_uiMount = MOUNT_WAR_WOLF;
                break;
            case LIEUTENANT_GREYWAND:
                m_uiMount = MOUNT_WAR_BLUE_STRIDER;
                break;
            case LIEUTENANT_STRONGHOOF:
                m_uiMount = MOUNT_WAR_KODO;
                break;
            case LIEUTENANT_LARGENT:
            case LIEUTENANT_SPENCER:
            case LIEUTENANT_MANCUSO:
                m_uiMount = MOUNT_WAR_HORSE;
                break;
            default:
                break;
        }

        m_creature->Mount(m_uiMount);
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->Unmount();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        switch (m_creature->GetEntry())
        {
            case COMMANDER_MALGOR:
            case COMMANDER_MORTIMER:
                // Aura of command
                if (m_uiGripOfCommand_Timer < uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, 21172) == CAST_OK)
                        m_uiGripOfCommand_Timer = 9000;
                }
                else
                    m_uiGripOfCommand_Timer -= uiDiff;
                break;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_FROST_SHOCK      =   21401,
    SPELL_LIGHTNING_SHIELD =   12550,
};

/******************/
struct FrostwolfShamanAI : public ScriptedAI
{
    FrostwolfShamanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        b_isUsingMount = false;
        b_isChanneling = false;
        Reset();
    }

    uint32 m_uiFrostShock_Timer;
    uint32 m_uiHealingWave_Timer;
    uint32 m_uiLightningShield_Timer;
    bool   b_isUsingMount;
    bool   b_isFirstAggro;
    bool   b_isChanneling;

    void Reset() override
    {
        m_creature->CastSpell(m_creature, SPELL_LIGHTNING_SHIELD, false);
        m_uiFrostShock_Timer = 5000;
        m_uiHealingWave_Timer = 0;
        b_isFirstAggro = true;
        if (b_isUsingMount)
            m_creature->Mount(10278);
        if (b_isChanneling)
            m_creature->CastSpell(m_creature, AV_INVOCATION_SPELL, false);
    }

    void Aggro(Unit* pWho) override
    {
        if (b_isFirstAggro)
        {
            b_isUsingMount = m_creature->IsMounted();
            b_isFirstAggro = false;
            if (m_creature->HasAura(AV_INVOCATION_SPELL))
            {
                b_isChanneling = true;
                m_creature->InterruptNonMeleeSpells(true);
            }
            else
                b_isChanneling = false;
        }
        m_creature->Unmount();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiFrostShock_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FROST_SHOCK) == CAST_OK)
                m_uiFrostShock_Timer = urand(5000, 6000);
        }
        else
            m_uiFrostShock_Timer -= uiDiff;

        if (m_uiHealingWave_Timer < uiDiff)
        {
            if (m_creature->GetHealthPercent() < 70.0f)
            {
                m_creature->CastSpell(m_creature, SPELL_HEALING_WAVE, false);
                m_uiHealingWave_Timer = 7000;
            }
        }
        else
            m_uiHealingWave_Timer -= uiDiff;

        if (m_uiLightningShield_Timer < uiDiff && !m_creature->HasAura(SPELL_LIGHTNING_SHIELD))
        {
            m_creature->CastSpell(m_creature, SPELL_LIGHTNING_SHIELD, false);
            m_uiLightningShield_Timer = urand(9000, 11000);
        }
        else
            m_uiLightningShield_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

struct DruidOfTheGroveAI : public ScriptedAI
{
    DruidOfTheGroveAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        b_isUsingMount = false;
        b_isChanneling = false;
        Reset();
    }

    uint32 m_uiEntanglingRoots_Timer;
    uint32 m_uiStarFire_Timer;
    uint32 m_uiThorns_Timer;
    bool   b_isUsingMount;
    bool   b_isFirstAggro;
    bool   b_isChanneling;

    void Reset() override
    {
        m_creature->CastSpell(m_creature, SPELL_THORNS, false);
        m_uiEntanglingRoots_Timer = 3000;
        m_uiStarFire_Timer = 0;
        b_isFirstAggro = true;
        if (b_isUsingMount)
            m_creature->Mount(9695); //10278
        if (b_isChanneling)
            m_creature->CastSpell(m_creature, AV_INVOCATION_SPELL, false);
    }

    void Aggro(Unit* pWho) override
    {
        if (b_isFirstAggro)
        {
            b_isUsingMount = m_creature->IsMounted();
            b_isFirstAggro = false;
            if (m_creature->HasAura(AV_INVOCATION_SPELL))
            {
                b_isChanneling = true;
                m_creature->InterruptNonMeleeSpells(true);
            }
            else
                b_isChanneling = false;
        }
        m_creature->Unmount();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiEntanglingRoots_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ENTANGLING_ROOTS) == CAST_OK)
                m_uiEntanglingRoots_Timer = urand(9000, 13000);
        }
        else
            m_uiEntanglingRoots_Timer -= uiDiff;

        if (m_uiStarFire_Timer < uiDiff)
        {
            m_creature->CastSpell(m_creature->GetVictim(), SPELL_STARFIRE, false);
            m_uiStarFire_Timer = urand(7000, 9500);
        }
        else
            m_uiStarFire_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_ram_wolf_tamed(Creature* pCreature)
{
    return new npc_ram_wolf_tamedAI(pCreature);
}

CreatureAI* GetAI_RamWolfMasterAI(Creature* pCreature)
{
    return new RamWolfMasterAI(pCreature);
}

CreatureAI* GetAI_FrostwolfShamanAI(Creature* pCreature)
{
    return new FrostwolfShamanAI(pCreature);
}

CreatureAI* GetAI_AV_DismountAI(Creature* pCreature)
{
    return new AV_DismountAI(pCreature);
}

CreatureAI* GetAI_AV_CommanderAI(Creature* pCreature)
{
    return new AV_CommanderAI(pCreature);
}

CreatureAI* GetAI_npc_worldboss_A_AV(Creature* pCreature)
{
    return new AV_NpcEventWorldBoss_A_AI(pCreature);
}

CreatureAI* GetAI_npc_worldboss_H_AV(Creature* pCreature)
{
    return new AV_NpcEventWorldBoss_H_AI(pCreature);
}

CreatureAI* GetAI_npc_troops_chiefAV(Creature* pCreature)
{
    return new AV_npc_troops_chief_EventAI(pCreature);
}

CreatureAI* GetAI_npc_eventAV(Creature* pCreature)
{
    return new AV_NpcEventAI(pCreature);
}

CreatureAI* GetAI_npc_eventTroopsAV(Creature* pCreature)
{
    return new AV_NpcEventTroopsAI(pCreature);
}

CreatureAI* GetAI_npc_korrak_the_bloodrager(Creature* pCreature)
{
    return new npc_korrak_the_bloodragerAI(pCreature);
}

CreatureAI* GetAI_AV_WarRiderAI(Creature* pCreature)
{
    return new AV_WarRiderAI(pCreature);
}

GameObjectAI* GetAI_AV_BeaconInvocationObjectAI(GameObject* gameobject)
{
    return new AV_BeaconInvocationObjectAI(gameobject);
}

CreatureAI* GetAI_DruidOfTheGroveAI(Creature* pCreature)
{
    return new DruidOfTheGroveAI(pCreature);
}

GameObjectAI* GetAI_go_av_landmine(GameObject* gobj)
{
    return new go_av_landmineAI(gobj);
}


/* Battle NPCs from the middle of the BattleGround */
// getReinforcementLevelGroundUnit => AV_NPC_BASIC
class npc_av_battle_npc_summoner: public ScriptedAI
{
    public:
        npc_av_battle_npc_summoner(Creature* c, uint32 factionId, float targetX, float targetY, float targetZ):
            ScriptedAI(c),
            m_timer(0),
            m_totalElapsedTime(0),
            m_despawnAfterTime(0),
            m_factionId(factionId),
            m_destX(targetX),
            m_destY(targetY),
            m_destZ(targetZ)
        {
            Reset();
        }
        void Reset() override
        {
            m_timer = 0;
        }

        void SetInitialTimer(uint32 t)
        {
            m_timer = t;
        }
        void SetDespawnTimer(uint32 t)
        {
            m_despawnAfterTime = t;
        }

        uint32 SelectCreatureEntry() const
        {
            Map* m = m_creature->GetMap();
            if (!m->IsBattleGround())
                return 0;
            BattleGroundAV* bgAv = dynamic_cast<BattleGroundAV*>(((BattleGroundMap*)m)->GetBG());
            switch (m_factionId)
            {
                case BG_TEAM_ALLIANCE:
                    switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                    {
                        case AV_NPC_BASIC:
                            return PickRandomValue(12048, 12127, 12047);
                        case AV_NPC_SEASONED:
                            return PickRandomValue(13327, 13324, 13325);
                        case AV_NPC_VETERAN:
                            return PickRandomValue(13336, 13333, 13335);
                        case AV_NPC_CHAMPION:
                            return PickRandomValue(13427, 13424, 13426);
                    }
                    return 0;
                case BG_TEAM_HORDE:
                    switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                    {
                        case AV_NPC_BASIC:
                            return PickRandomValue(12052, 12051);
                        case AV_NPC_SEASONED:
                            return PickRandomValue(13330, 13329);
                        case AV_NPC_VETERAN:
                            return PickRandomValue(13337, 13334);
                        case AV_NPC_CHAMPION:
                            return PickRandomValue(13428, 13425);
                    }
                    return 0;
                default: // Trolls
                    switch (urand(0, 7))
                    {
                        case 0:
                            return 13957;
                        case 1:
                            return 12157;
                        case 2:
                            return 12156;
                        case 3:
                            return 10983;
                        case 4:
                            return 13958;
                        case 5:
                            return 11679;
                        default:
                            return 13956;
                    }
                    break;
            }
        }

        void OnRemoveFromWorld() override
        {
            for (const auto& guid : m_summoned)
                if (Creature* c = m_creature->GetMap()->GetCreature(guid))
                    c->DeleteLater();
        }

        void UpdateAI(uint32 const diff) override
        {
            /* Despawn when the capitain is killed */
            bool despawn = false;
            Map* m = m_creature->GetMap();
            if (!m->IsBattleGround())
                return;
            BattleGroundAV* bgAv = dynamic_cast<BattleGroundAV*>(((BattleGroundMap*)m)->GetBG());
            if (!bgAv)
                return;
            if (m_factionId == BG_TEAM_ALLIANCE && bgAv->IsActiveEvent(BG_AV_NodeEventCaptainDead_A, 0))
                despawn = true;
            else if (m_factionId == BG_TEAM_HORDE && bgAv->IsActiveEvent(BG_AV_NodeEventCaptainDead_H, 0))
                despawn = true;
            else if (bgAv->IsActiveEvent(BG_AV_BOSS_IVUS_A, 0) || bgAv->IsActiveEvent(BG_AV_BOSS_LOKHOLAR_H, 0))
                despawn = true;

            if (despawn)
            {
                m_creature->DeleteLater();
                return;
            }

            /* Handle automatic despawn timer */
            m_totalElapsedTime += diff;
            if (m_despawnAfterTime && m_totalElapsedTime > m_despawnAfterTime)
            {
                m_creature->DeleteLater();
                return;
            }

            /* Handle spawns */
            if (m_timer < diff)
            {
                m_timer = TIMER_CHECK_NPC_SPAWN;
                for (auto& guid : m_summoned)
                {
                    if (!m_creature->GetMap()->GetCreature(guid))
                    {
                        float x, y, z;
                        m_creature->GetPosition(x, y, z);
                        m_creature->GetMap()->GetWalkRandomPosition(nullptr, x, y, z, 5.0f);
                        if (Creature* c = m_creature->SummonCreature(SelectCreatureEntry(), x, y, z, 0.0f, TEMPSUMMON_CORPSE_DESPAWN))
                        {
                            guid = c->GetObjectGuid();
                            x = m_destX;
                            y = m_destY;
                            z = m_destZ;
                            m_creature->GetMap()->GetWalkRandomPosition(nullptr, x, y, z, 20.0f);
                            c->SetHomePosition(x, y, z, frand(0, 2 * M_PI_F));
                            c->SetWanderDistance(10.0f);
                            c->SetDefaultMovementType(RANDOM_MOTION_TYPE);
                            c->SetWalk(false);
                            c->GetMotionMaster()->MovePoint(0, x, y, z, MOVE_PATHFINDING);
                            break;
                        }
                    }
                }  
            }
            else
                m_timer -= diff;
        }

    protected:
        const static uint32 TIMER_CHECK_NPC_SPAWN = 10000;
        const static uint32 TOTAL_NPC_PER_SPAWN = 5;
        ObjectGuid m_summoned[TOTAL_NPC_PER_SPAWN];
        uint32 m_timer;
        uint32 m_totalElapsedTime;
        uint32 m_despawnAfterTime;
        uint32 m_factionId;
        float  m_destX;
        float  m_destY;
        float  m_destZ;
};

CreatureAI* GetAI_npc_av_battle_npc_summoner_a2(Creature* c)
{
    npc_av_battle_npc_summoner* script = new npc_av_battle_npc_summoner(c, BG_TEAM_ALLIANCE, -296, -285, 7);
    script->SetInitialTimer(urand(0, 10000));
    script->SetDespawnTimer(urand(6000, 7200) * 1000); // 1h40 -> 2h: stop spawning
    return script;
}

CreatureAI* GetAI_npc_av_battle_npc_summoner_h2(Creature* c)
{
    npc_av_battle_npc_summoner* script = new npc_av_battle_npc_summoner(c, BG_TEAM_HORDE, -226, -305, 7);
    script->SetInitialTimer(urand(0, 10000));
    script->SetDespawnTimer(urand(6000, 7200) * 1000); // 1h40 -> 2h: stop spawning
    return script;
}

CreatureAI* GetAI_npc_av_battle_npc_summoner_trolls(Creature* c)
{
    npc_av_battle_npc_summoner* script = new npc_av_battle_npc_summoner(c, 2, -256, -301, 7);
    script->SetInitialTimer(urand(3600, 7200) * 1000); // Starts spawning after 1h to 2h
    return script;
}

enum
{
    SPELL_BOMB              =   9143,  /* Distance spell */
    SPELL_FLASH_BOMB        =   29419, /* Only Fear beast, Druid form included */
    SPELL_LANDMINE          =   22498, /* Put a landmine on the ground */
};

struct MineNPC_AI : public ScriptedAI
{
    MineNPC_AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    bool   m_bIsBombLaunched;
    uint32 m_uiBomb_Timer;
    uint32 m_uiFlashBomb_Timer;
    uint32 m_uiLandMine_Timer;

    void Reset() override
    {
        m_bIsBombLaunched         = false;
        m_uiBomb_Timer            = 2700;
        m_uiFlashBomb_Timer       = 5000;
        m_uiLandMine_Timer        = 9000;
    }

    void JustRespawned() override
    {
        Map* map = me->GetMap();
        if (!map->IsBattleGround())
            return;
        BattleGroundAV* bg = dynamic_cast<BattleGroundAV*>(((BattleGroundMap*)map)->GetBG());
        if (!bg)
            return;
        switch (me->GetEntry())
        {
            case NPC_LANDMINES_LAYER_A2:
                bg->ActivateEventWithoutSpawn(BG_AV_LANDMINES_ALLIANCE, 0);
                break;
            case NPC_LANDMINES_LAYER_H2:
                bg->ActivateEventWithoutSpawn(BG_AV_LANDMINES_HORDE, 0);
                break;
        }
    }
    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }
    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        /*        A druid in changeform is also condisered as a pet.
         *
         *        Source : "Apparently, he is impossible to tank as a bear.
         *        I got feared by his Flash Bomb attack four times over the
         *        course of the fight - each time for a full 9 seconds."*/
        if (m_uiFlashBomb_Timer < uiDiff)
        {
            m_bIsBombLaunched = false;
            Map* pMap = m_creature->GetMap();
            if (!pMap)
                return;

            Map::PlayerList const &PlayerList = pMap->GetPlayers();

            for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end() && !m_bIsBombLaunched; ++itr)
            {
                Player* pPlayer = itr->getSource();
                if (!pPlayer)
                    continue;
                Unit*   pPet    = pPlayer->GetPet();

                /** Range limit set to 35 meters/yards */
                if (pPlayer->IsInFeralForm() && m_creature->GetDistance2d(pPlayer) < 35.0f)
                {
                    if (DoCastSpellIfCan(pPlayer, SPELL_FLASH_BOMB) == CAST_OK)
                        m_uiFlashBomb_Timer = 7500;
                    m_bIsBombLaunched = true;
                }
                else if (pPet && m_creature->GetDistance2d(pPet) < 35.0f)
                {
                    if (DoCastSpellIfCan(pPet, SPELL_FLASH_BOMB) == CAST_OK)
                        m_uiFlashBomb_Timer = 7500;
                    m_bIsBombLaunched = true;
                }
            }
        }
        else
            m_uiFlashBomb_Timer -= uiDiff;

        /** Launch a Bomb on random target */
        if (m_uiBomb_Timer < uiDiff)
        {
            Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BOMB);
                m_uiBomb_Timer = 7500;
            }
        }
        else
            m_uiBomb_Timer -= uiDiff;

        /** Put a landmine on the ground */
        if (m_uiLandMine_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_LANDMINE);
            m_uiLandMine_Timer = 9000;
        }
        else
            m_uiLandMine_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_AV_MineNPC_AI(Creature* pCreature)
{
    return new MineNPC_AI(pCreature);
}

struct AV_mineNpcAI : public ScriptedAI
{
    AV_mineNpcAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_creature->GetPosition(m_destX, m_destY, m_destZ);
        m_originalEntry = m_creature->GetEntry();
        Reset();
    }

    float  m_destX;
    float  m_destY;
    float  m_destZ;
    uint32 m_originalEntry;

    void Reset() override
    {
    }

    void JustRespawned() override
    {
        uint32 m_newEntry = SelectCreatureEntry();
        if (m_newEntry != 0 && m_creature->GetEntry() != m_newEntry)
            m_creature->UpdateEntry(m_newEntry);
    }

    uint32 SelectCreatureEntry() const
    {
        Map* m = m_creature->GetMap();
        if (!m->IsBattleGround())
            return 0;
        BattleGroundAV* bgAv = dynamic_cast<BattleGroundAV*>(((BattleGroundMap*)m)->GetBG());
        uint32 m_factionId;
        if (m_creature->GetFactionTemplateId() == 85)
            m_factionId = 1;
        else
            m_factionId = 0;

        switch (m_originalEntry)
        {
            case 13089:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13089;
                    case AV_NPC_SEASONED:
                        return 13534;
                    case AV_NPC_VETERAN:
                        return 13535;
                    case AV_NPC_CHAMPION:
                        return 13536;
                }
                return 0;

            case 13097:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13097;
                    case AV_NPC_SEASONED:
                        return 13537;
                    case AV_NPC_VETERAN:
                        return 13538;
                    case AV_NPC_CHAMPION:
                        return 13539;
                }
                return 0;

            case 13099:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13099;
                    case AV_NPC_SEASONED:
                        return 13540;
                    case AV_NPC_VETERAN:
                        return 13541;
                    case AV_NPC_CHAMPION:
                        return 13542;
                }
                return 0;

            case 13081:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13081;
                    case AV_NPC_SEASONED:
                        return 13543;
                    case AV_NPC_VETERAN:
                        return 13544;
                    case AV_NPC_CHAMPION:
                        return 13545;
                }
                return 0;

            case 13080:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13080;
                    case AV_NPC_SEASONED:
                        return 13552;
                    case AV_NPC_VETERAN:
                        return 13553;
                    case AV_NPC_CHAMPION:
                        return 13554;
                }
                return 0;

            case 13098:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13098;
                    case AV_NPC_SEASONED:
                        return 13555;
                    case AV_NPC_VETERAN:
                        return 13556;
                    case AV_NPC_CHAMPION:
                        return 13557;
                }
                return 0;

            case 13096:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13096;
                    case AV_NPC_SEASONED:
                        return 13546;
                    case AV_NPC_VETERAN:
                        return 13547;
                    case AV_NPC_CHAMPION:
                        return 13548;
                }
                return 0;

            case 13087:
                switch (bgAv->getReinforcementLevelGroundUnit(m_factionId))
                {
                    case AV_NPC_BASIC:
                        return 13087;
                    case AV_NPC_SEASONED:
                        return 13549;
                    case AV_NPC_VETERAN:
                        return 13550;
                    case AV_NPC_CHAMPION:
                        return 13551;
                }
                return 0;
        }
        return 0;
    }

    void UpdateAI(uint32 const diff) override
    {
        uint32 m_newEntry = SelectCreatureEntry();
        if (m_newEntry != 0 && m_creature->GetEntry() != m_newEntry)
            m_creature->UpdateEntry(m_newEntry);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_AV_Mines_AI(Creature* pCreature)
{
    return new AV_mineNpcAI(pCreature);
}

class npc_av_trigger_for_questAI: public ScriptedAI
{
    public:
        npc_av_trigger_for_questAI(Creature* c) : ScriptedAI(c)
        {
            Reset();
        }
        void Reset() override
        {
        }
        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsPlayer() || !who->IsWithinDist(m_creature, 10.0f, false))
                return;
            who->ToPlayer()->KilledMonsterCredit(m_creature->GetEntry(), m_creature->GetObjectGuid());
        }
};

CreatureAI* GetAI_npc_av_trigger_for_quest(Creature* creature)
{
    return new npc_av_trigger_for_questAI(creature);
}

void AddSC_bg_alterac()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "AV_landmine";
    newscript->GetAI = &GetAI_AV_MineNPC_AI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "AV_mines";
    newscript->GetAI = &GetAI_AV_Mines_AI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "AV_dismount";
    newscript->GetAI = &GetAI_AV_DismountAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "AV_commander";
    newscript->GetAI = &GetAI_AV_CommanderAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_frostwolf_shaman";
    newscript->GetAI = &GetAI_FrostwolfShamanAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_druid_of_the_grove";
    newscript->GetAI = &GetAI_DruidOfTheGroveAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_AV_troops_chief";
    newscript->GetAI = &GetAI_npc_troops_chiefAV;
    newscript->pQuestRewardedNPC = &QuestComplete_AV_npc_troops_chief;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_av_beacon";
    newscript->GOGetAI = &GetAI_AV_BeaconInvocationObjectAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "av_warrider";
    newscript->GetAI = &GetAI_AV_WarRiderAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_Vanndar";
    newscript->GetAI = &GetAI_npc_Vanndar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_DrekThar";
    newscript->GetAI = &GetAI_npc_DrekThar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_Balinda";
    newscript->GetAI = &GetAI_npc_Balinda;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_Galvangar";
    newscript->GetAI = &GetAI_npc_Galvangar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_WarMaster";
    newscript->GetAI = &GetAI_npc_WarMaster;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_AlteracBowman";
    newscript->GetAI = &GetAI_npc_AlteracBowman;
    newscript->RegisterSelf();
    /*
    newscript = new Script;
    newscript->Name = "npc_AlteracDardosh";
    newscript->GetAI = &GetAI_npc_AlteracDardosh;
    newscript->RegisterSelf();
    */
    newscript = new Script;
    newscript->Name = "npc_ram_wolf_tamed";
    newscript->GetAI = &GetAI_npc_ram_wolf_tamed;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_worldboss_h_av";
    newscript->GetAI = &GetAI_npc_worldboss_H_AV;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_worldboss_a_av";
    newscript->GetAI = &GetAI_npc_worldboss_A_AV;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_cavalry";
    newscript->GetAI = &GetAI_npc_eventTroopsAV;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_korrak_the_bloodrager";
    newscript->GetAI = &GetAI_npc_korrak_the_bloodrager;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_AV_blood_collector";
    newscript->pGossipHello = &GossipHello_npc_AVBlood_collector;
    newscript->pQuestRewardedNPC = &QuestComplete_npc_AVBlood_collector;
    newscript->pGossipSelect = &GossipSelect_npc_AVBlood_collector;
    newscript->GetAI = &GetAI_npc_eventAV;
    newscript->RegisterSelf();
    /*
    newscript = new Script;
    newscript->Name = "npc_ram_wolf_quest";
    newscript->pQuestRewardedNPC = &QuestComplete_AV_npc_ram_wolf;
    newscript->RegisterSelf();
    */
    newscript = new Script;
    newscript->Name = "npc_ram_wolf_master";
    newscript->pGossipHello = &GossipHello_AV_npc_ram_wolf;
    newscript->pQuestRewardedNPC = &QuestComplete_npc_AVBlood_collector;
    newscript->GetAI = &GetAI_RamWolfMasterAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_av_landmine";
    newscript->GOGetAI = &GetAI_go_av_landmine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_av_battle_npc_summoner_a2";
    newscript->GetAI = &GetAI_npc_av_battle_npc_summoner_a2;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_av_battle_npc_summoner_h2";
    newscript->GetAI = &GetAI_npc_av_battle_npc_summoner_h2;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_av_battle_npc_summoner_trolls";
    newscript->GetAI = &GetAI_npc_av_battle_npc_summoner_trolls;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_av_trigger_for_quest";
    newscript->GetAI = &GetAI_npc_av_trigger_for_quest;
    newscript->RegisterSelf();
}

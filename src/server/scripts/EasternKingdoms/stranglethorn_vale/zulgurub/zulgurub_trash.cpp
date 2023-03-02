
#include "scriptPCH.h"
#include "zulgurub.h"

enum
{
    SPELL_THROW              =   16075,
    SPELL_AXE_FLURRY         =   24018,
    SPELL_FRENZY             =    8269,
};

struct GurubashiAxeThrowerAI : public ScriptedAI
{
    GurubashiAxeThrowerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiThrow_Timer;
    uint32 m_uiAxeFlurry_Timer;
    bool   m_bEnrage;

    void Reset() override
    {
        m_uiAxeFlurry_Timer   = 10000;
        m_uiThrow_Timer       = 5000;
        m_bEnrage             = false;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiAxeFlurry_Timer < uiDiff)
        {
            if (!m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_AXE_FLURRY) == CAST_OK)
                    m_uiAxeFlurry_Timer = urand(14000, 19000);
            }
        }
        else
            m_uiAxeFlurry_Timer -= uiDiff;

        if (m_uiThrow_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THROW) == CAST_OK)
                m_uiThrow_Timer = urand(4000, 7000);
        }
        else
            m_uiThrow_Timer -= uiDiff;

        if (m_creature->GetHealthPercent() < 50.0f && !m_bEnrage)
        {
            m_creature->CastSpell(m_creature, SPELL_FRENZY, false);
            m_bEnrage = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_GurubashiAxeThrower(Creature* pCreature)
{
    return new GurubashiAxeThrowerAI(pCreature);
}

enum
{
    SPELL_THUNDERCLAP        =   15588,
    SPELL_FEAR               =   16508,
    SPELL_ENRAGE             =    8269,
    SPELL_KNOCKBACK          =   11130,
};

struct GurubashiBerserkerAI : public ScriptedAI
{
    GurubashiBerserkerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiKnockBack_Timer;
    uint32 m_uiThunderClap_Timer;
    uint32 m_uiFear_Timer;
    bool   m_bEnrage;

    void Reset() override
    {
        m_uiKnockBack_Timer   = 10000;
        m_uiThunderClap_Timer = 5000;
        m_uiFear_Timer        = 15000;
        m_bEnrage             = false;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiKnockBack_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCKBACK) == CAST_OK)
            {
                DoResetThreat();
                m_uiKnockBack_Timer = 10000;
            }
        }
        else
            m_uiKnockBack_Timer -= uiDiff;

        if (m_uiThunderClap_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THUNDERCLAP) == CAST_OK)
                m_uiThunderClap_Timer = urand(14000, 16000);
        }
        else
            m_uiThunderClap_Timer -= uiDiff;

        if (m_uiFear_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FEAR) == CAST_OK)
            {
                m_uiFear_Timer = urand(25000, 30000);
                DoResetThreat();
            }
        }
        else
            m_uiFear_Timer -= uiDiff;

        if (m_creature->GetHealthPercent() < 50.0f && !m_bEnrage)
        {
            m_creature->CastSpell(m_creature, SPELL_ENRAGE, false);
            m_bEnrage = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_GurubashiBerserker(Creature* pCreature)
{
    return new GurubashiBerserkerAI(pCreature);
}


// npc_hakkari_doctor (11831)
/*
5 Techniques
- Maléfice http://www.wowhead.com/spell=24053
- Libération des crapauds http://www.wowhead.com/spell=24058
- Horion de l'ombre http://www.wowhead.com/spell=17289
- Rapetisser http://www.wowhead.com/spell=24054 Sort lancé mais pas d'effet de réduction de taille

Particularité :
Quand le sorcier-docteur meurt, un Esprit Vaudou (http://www.wowhead.com/npc=15009) apparait.
Il se dirige lentement vers une cible prise au hasard puis explose (explosion spirituelle http://www.wowhead.com/spell=24050) s'il touche la cible ; il disparait ensuite.
S'il ne touche personne, l'esprit vaudou disparait au bout de quelques secondes.
*/
struct npc_hakkari_doctor : public ScriptedAI
{
    npc_hakkari_doctor(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiMaleficeTimer;
    uint32 m_uiCrapaudsTimer;
    uint32 m_uiCrapaudsLiberationTimer;
    uint32 m_uiOrionOmbreTimer;

    void Reset() override
    {
        m_uiMaleficeTimer = 5000;
        m_uiCrapaudsTimer = 15000;
        m_uiCrapaudsLiberationTimer = 15000;
        m_uiOrionOmbreTimer = 4000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiMaleficeTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->GetFarthestVictimInRange(10.0f, 20.0f))
            {
                DoCastSpellIfCan(pTarget, 24053);
                m_uiMaleficeTimer = urand(20000, 40000);
            }
        }
        else
            m_uiMaleficeTimer -= uiDiff;

        if (m_uiCrapaudsTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->GetFarthestVictimInRange(10.0f, 20.0f))
            {
                for (uint8 i = 0; i < 4; ++i)
                    m_creature->SummonCreatureAndAttack(15010, pTarget);
                m_uiCrapaudsTimer = urand(10, 40) * 1000;
            }
        }
        else
            m_uiCrapaudsTimer -= uiDiff;

        if (m_uiCrapaudsLiberationTimer < uiDiff)
        {
            if (Creature* pCrapaud = m_creature->FindNearestCreature(15010, 40.0f))
            {
                pCrapaud->CastSpell(pCrapaud, 24065, true);
                pCrapaud->DisappearAndDie();
            }
            m_uiCrapaudsLiberationTimer = 1000;
        }
        else
            m_uiCrapaudsLiberationTimer -= uiDiff;

        if (m_uiOrionOmbreTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->GetFarthestVictimInRange(10.0f, 20.0f))
            {
                m_creature->CastSpell(pTarget, 17289, true);
                m_uiOrionOmbreTimer = urand(5000, 20000);
            }
        }
        else
            m_uiOrionOmbreTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller) override
    {
        m_creature->SummonCreatureAndAttack(15009, pKiller);
    }
};

CreatureAI* GetAI_npc_hakkari_doctor(Creature* pCreature)
{
    return new npc_hakkari_doctor(pCreature);
}

// npc_esprit_vaudou (15009)
struct npc_esprit_vaudou : public ScriptedAI
{
    npc_esprit_vaudou(Creature* pCreature) : ScriptedAI(pCreature)
    {
        // Intuables !
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        Reset();
    }

    void Reset() override
    {
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (Unit* pVictim = m_creature->GetVictim())
        {
            if (pVictim->GetDistance(m_creature) < 5.0f)
            {
                pVictim->CastSpell(pVictim, 24050, true);
                m_creature->AddObjectToRemoveList();
                return;
            }
        }
    }
};

CreatureAI* GetAI_npc_esprit_vaudou(Creature* pCreature)
{
    return new npc_esprit_vaudou(pCreature);
}

// npc_fils_hakkar (11357)
struct npc_fils_hakkar : public ScriptedAI
{
    npc_fils_hakkar(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiKnockDownTimer;
    uint32 m_uiTrashTimer;

    void Reset() override
    {
        m_uiKnockDownTimer = 10000;
        m_uiTrashTimer = 5000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiTrashTimer < uiDiff)
        {
            m_creature->CastSpell(m_creature, 3391, true);
            m_uiTrashTimer = urand(20000, 40000);
        }
        else
            m_uiTrashTimer -= uiDiff;

        if (m_uiKnockDownTimer < uiDiff)
        {
            m_creature->CastSpell(m_creature->GetVictim(), 16790, true);
            m_uiKnockDownTimer = urand(5000, 10000);
        }
        else
            m_uiKnockDownTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller) override
    {
        m_creature->CastSpell(m_creature, 24320, true);//24840
    }
};

CreatureAI* GetAI_npc_fils_hakkar(Creature* pCreature)
{
    return new npc_fils_hakkar(pCreature);
}

struct go_pile_dechetsAI: public GameObjectAI
{
    go_pile_dechetsAI(GameObject* pGo) : GameObjectAI(pGo), Actif(false), m_pGo(pGo) {}

    bool Actif;
    GameObject * const m_pGo;

    bool OnUse(Unit* pUser) override
    {
        if (pUser->IsWithinDistInMap(m_pGo, 5.0f) && !Actif && (urand(0, 2)))
        {
            if (Creature* Guru = pUser->SummonCreature(15047, pUser->GetPositionX(), pUser->GetPositionY(), pUser->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 20000))
            {
                Guru->AddUnitState(UNIT_STAT_ROOT);

                Map::PlayerList const& players = Guru->GetMap()->GetPlayers();
                bool OtherPlayerFound = false;
                for (const auto& itr : players)
                {
                    Player* pPlayer = itr.getSource();
                    if (pPlayer && pPlayer->IsAlive() && pUser->IsWithinDistInMap(pPlayer, 60.0f) && pUser->IsWithinLOSInMap(pPlayer) &&
                            pPlayer != pUser->ToPlayer() && !pPlayer->IsGameMaster())
                    {
                        Guru->AddThreat(pPlayer);
                        Guru->SetInCombatWith(pPlayer);
                        OtherPlayerFound = true;
                    }
                }

                if (OtherPlayerFound)
                {
                    Guru->CastSpell(pUser, 24178, true);
                    Guru->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    Guru->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Guru->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);

                    if (Unit* pTarget = Guru->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                        Guru->AI()->AttackStart(pTarget);
                }
                else
                {
                    // Ustaag
                    // SelectRandomFriendlyTarget
                    // les amis de faction 28 (troll dans ZG) sont... faction 14 (monster) ???
                    // en attendant...
                    std::list<Creature*> MobList;
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11361, 45.0f);          // Tigre Zulien
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11831, 45.0f);          // Sorcier Docteur
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11350, 45.0f);          // Lanceur de Haches
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11830, 45.0f);          // Prêtre
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11368, 45.0f);          // Chauve Souris Sanguinaire
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11365, 45.0f);          // Panthère
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11353, 45.0f);          // Buveur de sang
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11356, 45.0f);          // Champion Guru
                    GetCreatureListWithEntryInGrid(MobList, Guru, 14821, 45.0f);          // Raptor razza
                    GetCreatureListWithEntryInGrid(MobList, Guru, 14532, 45.0f);          // Fils du venin
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11370, 45.0f);          // Sombre veuve
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11360, 45.0f);          // Jeune Zulien
                    GetCreatureListWithEntryInGrid(MobList, Guru, 14825, 45.0f);          // Maitresse dessechée
                    GetCreatureListWithEntryInGrid(MobList, Guru, 14882, 45.0f);          // Maitresse Atalai
                    GetCreatureListWithEntryInGrid(MobList, Guru, 14826, 45.0f);          // Troll sacrifié
                    GetCreatureListWithEntryInGrid(MobList, Guru, 11351, 45.0f);          // Chasseur tête

                    for (const auto& itr : MobList)
                    {
                        if (pUser->IsWithinLOSInMap(itr) && pUser->IsWithinDistInMap(itr, 45.0f) && itr->IsAlive())
                        {
                            if (Player* pPlay = pUser->ToPlayer())
                            {
                                if (pPlay->GetTeam() == HORDE)
                                    Guru->SetFactionTemplateId(1);    // Human
                                else if (pPlay->GetTeam() == ALLIANCE)
                                    Guru->SetFactionTemplateId(2);    // Orc

                                Guru->AddThreat(itr);
                                Guru->SetInCombatWith(itr);
                                Guru->CastSpell(pUser, 24178, true);
                                Guru->AddUnitState(UNIT_STAT_ROOT);
                                Guru->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                Guru->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Guru->SetFactionTemplateId(14); // Troll Bloodscalp
                                break;
                            }
                        }
                    }
                }
            }
            Actif = true;
            return true;
        }
        else
            return false;
    }
};

GameObjectAI* GetAIgo_pile_dechets(GameObject *pGo)
{
    return new go_pile_dechetsAI(pGo);
}

void AddSC_zg_trash()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_gurubashi_berserker";
    newscript->GetAI = &GetAI_GurubashiBerserker;
    newscript->RegisterSelf();
    /*
    newscript = new Script;
    newscript->Name = "npc_gurubashi_axethrower";
    newscript->GetAI = &GetAI_GurubashiAxeThrower;
    newscript->RegisterSelf();
    */
    newscript = new Script;
    newscript->Name = "npc_hakkari_doctor";
    newscript->GetAI = &GetAI_npc_hakkari_doctor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_esprit_vaudou";
    newscript->GetAI = &GetAI_npc_esprit_vaudou;
    newscript->RegisterSelf();
    /*
    newscript = new Script;
    newscript->Name = "npc_fils_hakkar";
    newscript->GetAI = &GetAI_npc_fils_hakkar;
    newscript->RegisterSelf();
    */
    newscript = new Script;
    newscript->Name = "go_pile_dechets";
    newscript->GOGetAI = &GetAIgo_pile_dechets;
    newscript->RegisterSelf();
}

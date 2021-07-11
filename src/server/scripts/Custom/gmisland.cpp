#include "scriptPCH.h"

// TODO
// 12898 : Joli visuel. Aura bleue autour du caster.

struct boss_gmislandAI : public ScriptedAI
{
    boss_gmislandAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        uiGeneralTimer = 0;
        uiLastFusee    = 0;

        // Explosions
        spells.push_back(25938);
        spells.push_back(27745);
        spells.push_back(23918);
        // Visu nova de feu
        spells.push_back(19823);
        // Eclair qui tombe du ciel
        spells.push_back(19984);
        // Apparition visuel de cyclone
        spells.push_back(8609);
        // GM OFF
        spells.push_back(1509);
        // GM ON
        spells.push_back(18139);

        // Dispell ALLS
        gmSpells.push_back(25565);
        // Allo bleu
        gmSpells.push_back(12898);
        // Super heal
        gmSpells.push_back(1908);
        // Un espece d'eclair qui descend du ciel :)
        gmSpells.push_back(11826);
        // Augmente intel
        gmSpells.push_back(12864);
        gmSpells.push_back(28136);
    }

    uint32 uiGlobalCD;
    uint32 uiGmRefreshTimer;
    uint32 uiGeneralTimer;
    uint32 uiLastFusee;

    std::vector<uint32> spells;
    std::vector<uint32> gmSpells;

    void Reset() override
    {
        uiGlobalCD       = 0;
        uiGmRefreshTimer = 0;
        m_creature->SetObjectScale(1.0f);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            Player* plr = ((Player*)who);
            if (plr->IsGameMaster())
            {
                if (uiGmRefreshTimer > 1500)
                {
                    if (urand(0, 1)) // GM OFF
                        plr->CastSpell(plr,  1509, true);
                    else           // GM ON
                        plr->CastSpell(plr, 18139, true);
                }
                else
                    uiGmRefreshTimer = 0;
                // On a deja dit bonjour !
                if (plr->HasAura(1908))
                    return;
                std::vector<uint32>::iterator it;
                for (it = gmSpells.begin(); it != gmSpells.end(); ++it)
                    plr->CastSpell(plr, (*it), true);
                m_creature->MonsterSay("Bienvenu a la maison, Maitre Supreme !", LANG_UNIVERSAL, 0);
            }
            else
            {
                if (!urand(0, 200))
                {
                    m_creature->MonsterSay("Alerte, intrus ! Alerte intrus ! IN-TRU-SION !!", LANG_UNIVERSAL, 0);
                    m_creature->Attack(plr, true);
                }
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        uiGeneralTimer += uiDiff;
        uiGmRefreshTimer += uiDiff;
        if (!m_creature->GetVictim())
        {
            Reset();
            if ((uiGeneralTimer - uiLastFusee) > 4000)
            {
                if (urand(0, 1))
                    m_creature->CastSpell(m_creature,  1509, true);
                else
                    m_creature->CastSpell(m_creature, 18139, true);
                uiLastFusee = uiGeneralTimer;
            }
            return;
        }

        if (m_creature->GetHealthPercent() < 20.0f)
        {
            m_creature->MonsterSay("Sans rire, vous pensiez me tuer ? Me revoici en plein forme !", LANG_UNIVERSAL, 0);
            m_creature->SetHealth(m_creature->GetMaxHealth());
            // Sort visuel "tout rouge"
            m_creature->CastSpell(m_creature, 28330, false);
            return;
        }
        uiGlobalCD += uiDiff;
        if (uiGlobalCD > 1500)
        {
            uiGlobalCD = 0;
            m_creature->CastSpell(m_creature, spells[urand(0, spells.size() - 1)], false);
            switch (urand(0, 20))
            {
                case 0:
                    m_creature->MonsterYell("Prendez garde au Gardien !", LANG_UNIVERSAL, 0);
                    break;
                case 1:
                    m_creature->MonsterSay("N'insistez pas, vous ne passerez pas.", LANG_UNIVERSAL, 0);
                    break;
                case 2:
                    m_creature->MonsterYell("ILE DES MJS ATTAQUEE ! Demande Renforts immediatement !", LANG_UNIVERSAL, 0);
                    break;
                case 3:
                    m_creature->MonsterSay("Vous ne derangerez pas les MJs : ils sont en reunion !", LANG_UNIVERSAL, 0);
                    break;
                case 4:
                    if (Unit* mort = m_creature->GetVictim())
                    {
                        if (mort->IsAlive())
                        {
                            // "Presque" mort :p
                            mort->DealDamage(mort, mort->GetHealth() - 50, nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                            m_creature->MonsterSay("Tiens, toi t'es mort !", LANG_UNIVERSAL, 0);
                        }
                    }
                    break;
                /*
                // Trop mechant
                case 9:
                    if(Unit* pauvreVictime = m_creature->GetVictim())
                    {
                        if(pauvreVictime->GetTypeId() == TYPEID_PLAYER && pauvreVictime->IsAlive())
                        {
                            // Mais qui retirera ce "setConfused" ... ? :P
                            pauvreVictime->SetConfused(true, m_creature->GetGUID(), 5);
                        }
                    }
                    break;*/
                case 10:
                case 11:
                case 12:
                case 13:
                    m_creature->SetObjectScale(m_creature->GetObjectScale() * 1.15f);
                    break;
                case 14:
                case 15:
                    m_creature->SetObjectScale(m_creature->GetObjectScale() * 0.85f);
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_gmisland(Creature* pCreature)
{
    return new boss_gmislandAI(pCreature);
}

void AddSC_gmisland()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_gmisland";
    pNewScript->GetAI = &GetAI_boss_gmisland;
    pNewScript->RegisterSelf();
}

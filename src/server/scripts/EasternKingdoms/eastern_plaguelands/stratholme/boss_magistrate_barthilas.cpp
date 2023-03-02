#include "scriptPCH.h"
#include "stratholme.h"

#define TEXTE_PORTE_SERVICE "Intruders at the service gate! Baron Rivendare must be warned!"

#define SPELL_DRAININGBLOW      16793
#define SPELL_CROWDPUMMEL       10887
#define SPELL_MIGHTYBLOW        14099
#define SPELL_FURIOUS_ANGER     16791

#define MODEL_NORMAL            10433
#define MODEL_HUMAN             3637

struct boss_magistrate_barthilasAI : public ScriptedAI
{
    boss_magistrate_barthilasAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 DrainingBlow_Timer;
    uint32 CrowdPummel_Timer;
    uint32 MightyBlow_Timer;
    uint32 FuriousAnger_Timer;
    uint32 AngerCount;
    uint32 m_mvt_timer;
    char m_mvt_id;

    void Reset() override
    {
        DrainingBlow_Timer = 16000;
        CrowdPummel_Timer = 12000;
        MightyBlow_Timer = 8000;
        FuriousAnger_Timer = 5000;
        AngerCount = 0;
        m_mvt_timer = 0;
        m_mvt_id = 0;

        if (m_creature->IsAlive())
            m_creature->SetDisplayId(MODEL_NORMAL);
        else
            m_creature->SetDisplayId(MODEL_HUMAN);
    }

    void ReceiveEmote(Player* pPlayer, uint32 emote) override
    {
        if (emote == 1000 && m_mvt_id == 0)
        {
            float xDest = 3668.3f;
            float yDest = -3607.4f;
            float zDest = 137.2f;
            float x = xDest - m_creature->GetPositionX();
            float y = yDest - m_creature->GetPositionY();
            float speed = m_creature->GetSpeed(MOVE_RUN) * 0.001f;

            m_creature->MonsterYell(TEXTE_PORTE_SERVICE, LANG_UNIVERSAL);

            if (m_creature->IsWalking())
                m_creature->SetWalk(false);

            m_creature->MonsterMove(xDest, yDest, zDest);
            m_mvt_timer = static_cast<uint32>(sqrt((x * x) + (y * y)) / speed);
            m_mvt_id++;
        }
    }

    void MoveInLineOfSight(Unit *who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) && m_creature->IsWithinDistInMap(who, 10.0f))
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
        ScriptedAI::MoveInLineOfSight(who);
    }

    void JustDied(Unit* Killer) override
    {
        m_creature->SetDisplayId(MODEL_HUMAN);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (m_mvt_id > 0)
        {
            if (m_mvt_timer < diff)
            {
                if (m_mvt_id == 1)
                {
                    float xDest = 3725.5;
                    float yDest = -3600;
                    float zDest = 142.4f;
                    float xOrigine = 3668.3f;
                    float yOrigine = -3607.4f;
                    float zOrigine = 137.2f;
                    float x = xDest - xOrigine;
                    float y = yDest - yOrigine;
                    float speed = m_creature->GetSpeed(MOVE_RUN) * 0.001f;

                    m_creature->GetMap()->CreatureRelocation(m_creature, xOrigine, yOrigine, zOrigine, 0);

                    m_creature->MonsterMove(xDest, yDest, zDest);
                    m_mvt_timer = static_cast<uint32>(sqrt((x * x) + (y * y)) / speed);
                    m_mvt_id++;
                }
                else
                {
                    m_creature->GetMap()->CreatureRelocation(m_creature, 4066.3f, -3534.5f, 122.6f, 2.48137f);
                    m_mvt_timer = 0;
                    m_mvt_id = -1;
                }
            }
            else m_mvt_timer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (FuriousAnger_Timer < diff)
        {
            FuriousAnger_Timer = 4000;
            if (AngerCount > 25)
                return;

            ++AngerCount;
            m_creature->CastSpell(m_creature, SPELL_FURIOUS_ANGER, false);
        }
        else FuriousAnger_Timer -= diff;

        //DrainingBlow
        if (DrainingBlow_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DRAININGBLOW);
            DrainingBlow_Timer = 15000;
        }
        else DrainingBlow_Timer -= diff;

        //CrowdPummel
        if (CrowdPummel_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CROWDPUMMEL);
            CrowdPummel_Timer = 15000;
        }
        else CrowdPummel_Timer -= diff;

        //MightyBlow
        if (MightyBlow_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIGHTYBLOW);
            MightyBlow_Timer = 20000;
        }
        else MightyBlow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_magistrate_barthilas(Creature* pCreature)
{
    return new boss_magistrate_barthilasAI(pCreature);
}

void AddSC_boss_magistrate_barthilas()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_magistrate_barthilas";
    newscript->GetAI = &GetAI_boss_magistrate_barthilas;
    newscript->RegisterSelf();
}

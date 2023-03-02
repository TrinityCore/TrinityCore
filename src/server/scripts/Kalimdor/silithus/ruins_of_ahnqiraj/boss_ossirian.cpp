/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111=    -1307  USA
 */

/* ScriptData
SDName: Boss_Ossirian
SD%Complete: 99
SDComment:
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "ruins_of_ahnqiraj.h"

#include <array>

enum
{
    SAY_SURPREME1               =    -1509018,
    SAY_SURPREME2               =    -1509019,
    SAY_SURPREME3               =    -1509020,

    SAY_AGGRO                   =    -1509025,

    SAY_SLAY                    =    -1509026,
    SAY_DEATH                   =    -1509027,

    SPELL_CURSE_OF_TONGUES      =  25195,
    SPELL_STRENGTH_OF_OSSIRIAN  =  25176,
    SPELL_SUMMON_PLAYER         =  20477,
    SPELL_WAR_STOMP             =  25188,

    // Tornado
    NPC_TORNADO                 =  15428,
    SPELL_ENVELOPING_WINDS      =  25189,
    SPELL_SANDSTORM             =  25160
};

std::array<uint32, 5> const SpellWeakness =
{
    25177u, //Fire weakness
    25178u, //Frost weakness
    25180u, //Nature weakness
    25183u, //Shadow weakness
    25181u  //Arcane weakness
};

std::array<SpawnLocations, 2> const TornadoSpawn =
{{
    { -9444.0f, 1857.0f, 85.55f },
    { -9352.0f, 2012.0f, 85.55f }
}};

struct boss_ossirianAI : public ScriptedAI
{
    boss_ossirianAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = dynamic_cast<instance_ruins_of_ahnqiraj*>(pCreature->GetInstanceData());
        if (!m_pInstance)
        {
            m_creature->AddObjectToRemoveList();
            return;
        }

        Reset();
    }

    instance_ruins_of_ahnqiraj* m_pInstance;

    uint32 m_uiSpeed_Timer;
    uint32 m_uiCurseOfTongues_Timer;
    uint32 m_uiStrengthOfOssirian_Timer;
    uint32 m_uiWarStomp_Timer;
    uint32 m_uiEnvelopingWinds_Timer;

    std::vector<ObjectGuid> TmpThreatList;
    std::vector<float> TmpThreatVal;
    std::vector<uint64> TornadoGUIDs;

    std::list<uint32> pylonIndexHistory;
    bool m_bIsEnraged;
    bool m_bAggro;

    void Reset() override
    {
        m_bAggro = false;

        DoCast(m_creature, SPELL_STRENGTH_OF_OSSIRIAN);

        m_uiSpeed_Timer = 10000;
        m_creature->SetSpeedRate(MOVE_RUN,  1.0f);
        m_creature->SetSpeedRate(MOVE_WALK, 1.0f);

        m_uiCurseOfTongues_Timer     = 30000;
        m_uiStrengthOfOssirian_Timer = 25000;
        m_uiWarStomp_Timer           = 25000;
        m_uiEnvelopingWinds_Timer    = 20000;

        TmpThreatList.clear();
        TmpThreatVal.clear();

        m_bIsEnraged = true;

        if (!TornadoGUIDs.empty())
        {
            int i = -1;
            while (++i < TornadoGUIDs.size())
            {
                Creature *Crea = m_creature->GetMap()->GetCreature(TornadoGUIDs[i]);
                if (Crea)
                    Crea->AddObjectToRemoveList();
            }
        }

        TornadoGUIDs.clear();

        /** weather reseted to normal, seems like after aggro of Ossirian, weather needs to stay in sandstorm mode */
        uint32 zoneid = m_creature->GetZoneId();
        m_creature->GetMap()->SetWeather(zoneid, WEATHER_TYPE_FINE, 0, false);

        m_pInstance->SetData(TYPE_OSSIRIAN, FAIL);
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_ENVELOPING_WINDS)
        {
            TmpThreatVal.push_back(m_creature->GetThreatManager().getThreat(pCaster));
            TmpThreatList.push_back(pCaster->GetObjectGuid());
            m_creature->GetThreatManager().modifyThreatPercent(pCaster, -100);
        }
    }

    void SpellHit(Unit* pUnit, SpellEntry const* pSpell) override
    {
        for (uint32 i : SpellWeakness)
        {
            if (pSpell->Id == i)
            {
                m_uiStrengthOfOssirian_Timer = 45000;

                if (m_bIsEnraged || m_creature->HasAura(SPELL_STRENGTH_OF_OSSIRIAN))
                {
                    m_creature->RemoveAurasDueToSpell(SPELL_STRENGTH_OF_OSSIRIAN);
                    m_bIsEnraged = false;
                }

                break;
            }
        }
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();
        DoCast(m_creature, SPELL_STRENGTH_OF_OSSIRIAN);
        for (const auto& i : TornadoSpawn)
        {
            Creature *pCreature = m_creature->SummonCreature(NPC_TORNADO,
                                  i.x,
                                  i.y,
                                  i.z,
                                  0,
                                  TEMPSUMMON_MANUAL_DESPAWN,
                                  0);
            if (pCreature)
            {
                pCreature->CastSpell(pCreature, SPELL_SANDSTORM, true);
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pCreature->AI()->AttackStart(m_creature->GetVictim());
                TornadoGUIDs.push_back(pCreature->GetGUID());
            }
        }

        if (!m_bAggro)
        {
            m_bAggro = true;
            m_uiSpeed_Timer = 10000;
            m_pInstance->SpawnNewCrystals(ObjectGuid());
        }

        uint32 zoneid = m_creature->GetZoneId();
        m_creature->GetMap()->SetWeather(zoneid, WEATHER_TYPE_STORM, 1, false);

        m_pInstance->SetData(TYPE_OSSIRIAN, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (!TornadoGUIDs.empty())
        {
            int i = -1;
            while (++i < TornadoGUIDs.size())
            {
                Creature *Crea = m_creature->GetMap()->GetCreature(TornadoGUIDs[i]);
                if (Crea)
                    Crea->ForcedDespawn();
            }
        }

        m_pInstance->SetData(TYPE_OSSIRIAN, DONE);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_SLAY, m_creature);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiCurseOfTongues_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSE_OF_TONGUES) == CAST_OK)
                m_uiCurseOfTongues_Timer = 10000 + rand() % 10000;
        }
        else
            m_uiCurseOfTongues_Timer -= uiDiff;

        if (m_uiSpeed_Timer >= uiDiff)
        {
            m_uiSpeed_Timer -= uiDiff;
            m_creature->SetSpeedRate(MOVE_RUN, (2.0f - m_uiSpeed_Timer*1.0f/10000));
        }

        if (!m_bIsEnraged && m_uiStrengthOfOssirian_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_STRENGTH_OF_OSSIRIAN) == CAST_OK)
            {
                m_bIsEnraged = true;
            }
        }
        else
            m_uiStrengthOfOssirian_Timer -= uiDiff;

        if (m_uiWarStomp_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_WAR_STOMP) == CAST_OK)
                m_uiWarStomp_Timer = 25000 + (rand() % 10000);
        }
        else
            m_uiWarStomp_Timer -= uiDiff;

        if (m_uiEnvelopingWinds_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ENVELOPING_WINDS) == CAST_OK)
                m_uiEnvelopingWinds_Timer = 15000;
        }
        else
            m_uiEnvelopingWinds_Timer -= uiDiff;

        if (!TmpThreatList.empty())
        {
            int i = -1;
            while (++i < TmpThreatList.size())
            {
                if (Unit* unit = m_creature->GetMap()->GetUnit(TmpThreatList[i]))
                {
                    if (unit->IsAlive())
                    {
                        if (unit->HasAura(SPELL_ENVELOPING_WINDS))
                            continue;
                        m_creature->GetThreatManager().addThreat(unit, TmpThreatVal[i]);
                    }
                }
                TmpThreatList.erase(TmpThreatList.begin() + i);
                TmpThreatVal.erase(TmpThreatVal.begin() + i);
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_ossirian(Creature* pCreature)
{
    return new boss_ossirianAI(pCreature);
}

struct generic_random_moveAI : public ScriptedAI
{
    generic_random_moveAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiTimer;

    void Reset() override
    {
        m_uiTimer = 5000;
        SetCombatMovement(false);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiTimer < uiDiff)
        {
            if (!urand(0, 2))
            {
                std::vector<Player*> PlayerList;
                Map::PlayerList const &liste = m_creature->GetMap()->GetPlayers();
                for (const auto& i : liste)
                {
                    if (i.getSource()->GetDistance2d(m_creature) < MAX_VISIBILITY_DISTANCE)
                        PlayerList.push_back(i.getSource());
                }
                if (!PlayerList.empty())
                {
                    Player *tmp = PlayerList[urand(0, PlayerList.size() - 1)];
                    m_creature->MonsterMove(tmp->GetPositionX(), tmp->GetPositionY(), tmp->GetPositionZ());
                    m_uiTimer = (urand(5000, 20000));
                }
            }
            else if (urand(0, 3))
            {
                float rx;
                float ry;
                float rz;
                m_creature->GetRandomPoint(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 50.0f, rx, ry, rz);
                m_creature->MonsterMove(rx, ry, rz);
                m_uiTimer = (urand(3000, 10000));
            }
            m_uiTimer = 2000;
        }
        else
            m_uiTimer -= uiDiff;
    }
};

struct ossirian_crystalAI : public GameObjectAI
{
    ossirian_crystalAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* user) override
    {
        instance_ruins_of_ahnqiraj* pInstance = dynamic_cast<instance_ruins_of_ahnqiraj*>(me->GetInstanceData());

        if (!pInstance)
        {
            sLog.outInfo("[OSSIRIAN/Crystal][Inst %03u] ERROR: No instance", user->GetInstanceId());
            return false;
        }

        // Already used
        if (Creature* trigger = GetClosestCreatureWithEntry(me, CRYSTAL_TRIGGER, 5.0f))
            return true;

        // Spawn new crystals even if Ossirian is out of range
        pInstance->SpawnNewCrystals(me->GetObjectGuid());

        Creature* ossirian = GetClosestCreatureWithEntry(me, NPC_OSSIRIAN, 300.0f);

        if (!ossirian)
        {
            sLog.outInfo("[OSSIRIAN/Crystal][Inst %03u] ERROR: No Ossirian found (guid %u)", user->GetInstanceId(), pInstance->GetData64(DATA_OSSIRIAN));
            return false;
        }

        // Encounter not started
        if (!ossirian->SelectHostileTarget() || !ossirian->GetVictim())
            return true;

        Creature* triggerCrystalPylons = me->SummonCreature(CRYSTAL_TRIGGER,
                                            me->GetPositionX(),
                                            me->GetPositionY(),
                                            me->GetPositionZ(),
                                            me->GetOrientation(),
                                            TEMPSUMMON_TIMED_DESPAWN,
                                            8000);

        if (triggerCrystalPylons)
            triggerCrystalPylons->CastSpell(ossirian, SpellWeakness[urand(0, 4)], true);

        return false;
    }
};


GameObjectAI* GetAI_ossirian_crystal(GameObject* pGo)
{
    return new ossirian_crystalAI(pGo);
}


CreatureAI* GetAI_generic_random_move(Creature* pCreature)
{
    return new generic_random_moveAI(pCreature);
}

void AddSC_boss_ossirian()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_ossirian";
    newscript->GetAI = &GetAI_boss_ossirian;
    newscript->RegisterSelf();
    /*
    newscript = new Script;
    newscript->Name = "generic_random_move";
    newscript->GetAI = &GetAI_generic_random_move;
    newscript->RegisterSelf();
    */
    newscript = new Script;
    newscript->Name = "ossirian_crystal";
    newscript->GOGetAI = &GetAI_ossirian_crystal;
    newscript->RegisterSelf();
}

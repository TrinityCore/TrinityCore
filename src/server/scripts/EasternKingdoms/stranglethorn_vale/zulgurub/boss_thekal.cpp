/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Thekal
SD%Complete: 95
SDComment: Almost finished.
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"


#define SAY_AGGRO               -1309009
#define SAY_DEATH               -1309010

#define EMOTE_DIES              -1309027
#define EMOTE_RESURRECT         -1309028

#define SPELL_MORTALCLEAVE        22859
#define SPELL_SILENCE             22666
#define SPELL_FRENZY              24185
#define SPELL_FORCEPUNCH          24189
#define SPELL_CHARGE              24408
#define SPELL_ENRAGE              8269
#define SPELL_SUMMONTIGERS        24183
#define NPC_TIGER                 15068
#define SPELL_TIGER_FORM          24169
#define SPELL_RESURRECT           24173                     //We will not use this spell.

//Zealot Lor'Khan Spells
#define SPELL_SHIELD              25020
#define SPELL_BLOODLUST           24185
#define SPELL_GREATERHEAL         24208
#define SPELL_DISARM              22691

//Zealot Lor'Khan Spells
#define SPELL_SWEEPINGSTRIKES     18765
#define SPELL_SINISTERSTRIKE      15667
#define SPELL_GOUGE               24698
#define SPELL_KICK                15614
#define SPELL_BLIND               21060

#define ZELOTH_LOR_KHAN           11347
#define ZELOTH_ZATH               11348

#define RESSURECT_TIMER           7000

/*
INSERT INTO creature_template SET entry=14966, modelid_1=14792, modelid_2=14792, name="High Priest Thekal Transform Visual";
INSERT INTO creature_template SET entry=15109, modelid_1=15214, modelid_2=15214, name="Primal Blessing Visual";
*/

class ChargeUnitSelector : public ThreatListProcesser
{
public:
    ChargeUnitSelector(Unit* thekal) : _victim(nullptr), _charger(thekal)
    {
        ASSERT(_charger);
    }
    bool Process(Unit* unit) override
    {
        ASSERT(unit);

        // Imperatif de verifier ces conditions
        if (!unit->IsMoving())
            return false;
        float currDist = unit->GetDistance(_charger);
        if (currDist > 35.0f || currDist < 5.0f)
            return false;

        // Ensuite on classe les autres potentielles victimes
        if (_victim)
        {
            float bestDist = _victim->GetDistance(_charger);
            if (currDist > bestDist)
                _victim = unit;
        }
        else
            _victim = unit;
        return false;
    }
    Unit* GetUnit()
    {
        return _victim;
    }
    Unit* _victim;
    Unit* _charger;
};

void DoRessurectUnit(Unit* pUnit, Unit* pVictim);

struct zg_rez_add : public ScriptedAI
{
    zg_rez_add(Creature* pCreature, uint32 instMobType) : ScriptedAI(pCreature),
        m_uiInstMobType(instMobType), m_uiRessurectTimer(0), m_uiRezzeurGUID(0), m_reallyDead(false), m_justRevived(false)
    {
        m_pInstance = (instance_zulgurub*)pCreature->GetInstanceData();
    }
    void SetRealyDead(bool value)
    {
        m_reallyDead = value;
    }
    bool CanBeLooted() const override
    {
        return m_reallyDead;
    }
    void Aggro(Unit *who) override
    {
        if (m_pInstance)
            m_pInstance->SetData(m_uiInstMobType, IN_PROGRESS);
        ScriptedAI::Aggro(who);
    }

    void JustDied(Unit* Killer) override
    {
        DoScriptText(EMOTE_DIES, m_creature);
        Unit* pRezzer = nullptr;
        // Mort et non selectionnable (= pas de loots)
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (m_pInstance)
        {
            pRezzer = m_pInstance->Thekal_GetUnitThatCanRez();
        }
        if (pRezzer)
        {
            m_uiRezzeurGUID = pRezzer->GetGUID();
            m_uiRessurectTimer = RESSURECT_TIMER;
        }
        else // Personne pour le rez : Adds morts : passage en phase 2 (tigre).
        {
            m_uiRessurectTimer = 10000;
            m_uiRezzeurGUID = 0;
        }
    }
    bool HandleWaitRez(uint32 const uiDiff)
    {
        if (!m_pInstance)
            return false;

        if (m_uiRessurectTimer > 2000 && (m_uiRessurectTimer - uiDiff) < 2000)
        {
            if (Unit* pRezzeur = m_pInstance->instance->GetUnit(m_uiRezzeurGUID))
            {
                if (pRezzeur->IsAlive())
                {
                    pRezzeur->InterruptNonMeleeSpells(true);
                    pRezzeur->CastSpell(m_creature, SPELL_RESURRECT, false);
                }
            }
        }
        if (m_uiRessurectTimer < uiDiff)
        {
            if (m_uiRezzeurGUID)
            {
                if (Unit* pRezzeur = m_pInstance->instance->GetUnit(m_uiRezzeurGUID))
                {
                    if (!pRezzeur->IsAlive())
                    {
                        m_uiRessurectTimer = 8000;
                        m_uiRezzeurGUID = 0;
                        return true;
                    }
                }
            }

            if (Unit* pFriend = m_pInstance->Thekal_GetUnitThatCanRez())
                DoRessurectUnit(m_creature, pFriend->GetVictim());
            else
            {
                // Apres les 10 sec sans rez :
                return false;
            }
        }
        else
            m_uiRessurectTimer -= uiDiff;
        return true;
    }
    void EnterCombat(Unit* who) override
    {
        if (!m_pInstance)
            return;

        Creature *pThekal = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_THEKAL));
        Creature *pZath = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_ZATH));
        Creature *pLorkhan = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_LORKHAN));
        if (pThekal && pThekal->AI())
            pThekal->AI()->AttackStart(who);
        if (pZath && pZath->AI())
            pZath->AI()->AttackStart(who);
        if (pLorkhan && pLorkhan->AI())
            pLorkhan->AI()->AttackStart(who);
        ScriptedAI::EnterCombat(who);
    }
    void UpdateAI(uint32 const diff) override
    {
        if (m_justRevived)
        {
            m_creature->SendSpellGo(m_creature, 20770);
            m_justRevived = false;
        }
    }
    void Reset() override
    {
        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(m_uiInstMobType, NOT_STARTED);
    }

    uint32 m_uiInstMobType;
    instance_zulgurub* m_pInstance;
    uint32 m_uiRessurectTimer;
    uint64 m_uiRezzeurGUID;
    bool m_reallyDead;
    bool m_justRevived;
};

void DoRessurectUnit(Unit* unit, Unit* victim)
{
    DEBUG_UNIT(unit, DEBUG_AI, "Rez %s", unit->GetName());
    float x, y, z, o;
    unit->GetPosition(x, y, z);
    o = unit->GetOrientation();

    unit->SetStandState(UNIT_STAND_STATE_STAND);
    unit->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    unit->SetHealth(unit->GetMaxHealth());

    unit->AttackStop();

    if (Creature* creature = unit->ToCreature())
    {
        DoScriptText(EMOTE_RESURRECT, creature);
        creature->Respawn();
        creature->NearTeleportTo(x, y, z, o);
        // TRES DANGEREUX.
        // Peut provoquer un stack overflow, donc faire gaffe en modifiant le script.
        // Permet d'effectuer *vraiment* le respawn du mob, pour pouvoir attaquer la victime, et avoir le visuel du sort.
        creature->Update(0, 0);
        creature->SendSpellGo(creature, 20770);
        if (victim)
            creature->AI()->AttackStart(victim);
    }
}


#define TIGER_COUNT 2

struct boss_thekalAI : public zg_rez_add
{
    boss_thekalAI(Creature* pCreature) : zg_rez_add(pCreature, TYPE_THEKAL)
    {
        for (uint64 & guid : TigerGUIDs)
            guid = 0;
        Reset();
    }

    uint32 MortalCleave_Timer;
    uint32 Silence_Timer;
    uint32 Frenzy_Timer;
    uint32 ForcePunch_Timer;
    uint32 Charge_Timer;
    uint32 Enrage_Timer;
    uint32 CheckTigers_Timer;
    uint32 NoTargetReset_Timer;
    uint64 TigerGUIDs[TIGER_COUNT];

    bool Enraged;
    bool PhaseTwo;

    void GetAIInformation(ChatHandler& handler) override
    {
        handler.SendSysMessage("DEBUG -- THEKAL");
        handler.PSendSysMessage("Can be looted : [%s]", CanBeLooted() ? "YES" : "NO");
        handler.PSendSysMessage("PhaseTwo = %s, Enraged = %s", PhaseTwo ? "true" : "false", Enraged ? "true" : "false");
        handler.SendSysMessage("Timers :");
        handler.PSendSysMessage("[%u:%u:%u:%u:%u:%u:%u:%u]",
                                MortalCleave_Timer, Silence_Timer, Frenzy_Timer, ForcePunch_Timer, Charge_Timer, Enrage_Timer, CheckTigers_Timer, NoTargetReset_Timer);
    }
    void Reset() override
    {
        m_creature->ResetStats();

        MortalCleave_Timer = 4000;
        Silence_Timer = 9000;
        Frenzy_Timer = 30000;
        ForcePunch_Timer = 4000;
        Charge_Timer = 12000;
        Enrage_Timer = 32000;
        CheckTigers_Timer = 25000;

        Enraged = false;

        // Si en phase 2 avant de reset, faut repop les 2 adds.
        m_creature->RespawnNearCreaturesByEntry(ZELOTH_LOR_KHAN, 100.0f);
        m_creature->RespawnNearCreaturesByEntry(ZELOTH_ZATH, 100.0f);
        PhaseTwo = false;
        zg_rez_add::Reset();
    }

    void JustDied(Unit* Killer) override
    {
        // Si reelement mort ...
        if (PhaseTwo)
        {
            DoScriptText(SAY_DEATH, m_creature);
            DEBUG_UNIT(m_creature, DEBUG_AI, "Thekal is dead for real");

            if (m_pInstance)
            {
                m_pInstance->SetData(TYPE_LORKHAN, DONE);
                m_pInstance->SetData(TYPE_ZATH, DONE);
                m_pInstance->SetData(TYPE_THEKAL, DONE);
            }

            // Remove a Hakkar Power stack.
            m_creature->CastSpell(m_creature, SPELL_HAKKAR_POWER_DOWN, true);

            ScriptedAI::JustDied(Killer);
        }
        else
        {
            // Mettre tout le monde en combat.
            DEBUG_UNIT(m_creature, DEBUG_AI, "Thekal fake death. Put map in combat.");
            Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
            for (const auto& player : players)
                if (player.getSource()->GetDistance(m_creature) < 200.0f)
                {
                    player.getSource()->SetCombatTimer(20000);
                    player.getSource()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                }
            zg_rez_add::JustDied(Killer);
        }
    }
    void UpdateAI_corpse(uint32 const uiDiff) override
    {
        if (PhaseTwo || !m_pInstance)
            return; // La c'est vraiment fini.

        if (!zg_rez_add::HandleWaitRez(uiDiff))
        {
            // Apres les 10 sec sans rez :
            // Rez
            DoRessurectUnit(m_creature, nullptr);
            m_creature->SetEntry(14509);
            // Phase 2
            DoSetInPhaseTwo();
            zg_rez_add::SetRealyDead(true);
        }
    }


    void JustRespawned() override
    {
        // Pour ne pas appeller ScriptedAI::JustRespawned qui appelle "Reset()"
    }

    void EnterEvadeMode() override
    {
        SetRealyDead(false);
        Reset();
        zg_rez_add::EnterEvadeMode();
    }

    void Aggro(Unit *who) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_THEKAL, IN_PROGRESS);
        if (PhaseTwo)
            DoScriptText(SAY_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();
    }

    void DoSetInPhaseTwo()
    {
        DEBUG_UNIT(m_creature, DEBUG_AI, "Thekal : set P2.");
        PhaseTwo = true;
        DoCastSpellIfCan(m_creature, SPELL_TIGER_FORM);
        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.00f);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        CreatureInfo const *cinfo = m_creature->GetCreatureInfo();
        m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->dmg_min + ((cinfo->dmg_min / 100) * 40)));
        m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->dmg_max + ((cinfo->dmg_max / 100) * 40)));
        m_creature->UpdateDamagePhysical(BASE_ATTACK);

        NoTargetReset_Timer = 5000;
        m_creature->DespawnNearCreaturesByEntry(ZELOTH_LOR_KHAN, 100.0f);
        m_creature->DespawnNearCreaturesByEntry(ZELOTH_ZATH, 100.0f);
    }

    void CheckTiger(uint64& guid)
    {
        Creature* pTiger = m_creature->GetMap()->GetCreature(guid);
        if (!pTiger || !pTiger->IsAlive())
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (Unit* pCrea = m_creature->SummonCreatureAndAttack(NPC_TIGER, pTarget))
                    guid = pCrea->GetGUID();
            }
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->IsAlive())
            return;
        zg_rez_add::UpdateAI(diff);
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (PhaseTwo)
            {
                if (NoTargetReset_Timer < diff)
                {
                    EnterEvadeMode();
                    return;
                }
                else
                {
                    // On tente tout de même de trouver une cible.
                    Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
                    float nearestDist = 200.0f;
                    Player* target = nullptr;
                    for (const auto& player : players)
                        if (m_creature->CanAttack(player.getSource()))
                            if (player.getSource()->GetDistance(m_creature) < nearestDist)
                            {
                                nearestDist = player.getSource()->GetDistance(m_creature);
                                target = player.getSource();
                            }
                    if (target)
                        AttackStart(target);
                    NoTargetReset_Timer -= diff;
                }
            }
            return;
        }

        if (!PhaseTwo)
        {
            if (MortalCleave_Timer < diff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MORTALCLEAVE);
                MortalCleave_Timer = urand(15000, 20000);
            }
            else
                MortalCleave_Timer -= diff;

            if (Silence_Timer < diff)
            {
                if (m_creature->CastSpellOnHostileCasterInRange(SPELL_SILENCE, 0.0f, 40.0f, false))
                    Silence_Timer = urand(20000, 25000);
                else
                    Silence_Timer = 2000;
            }
            else
                Silence_Timer -= diff;
        }
        else
        {
            if (Charge_Timer < diff)
            {
                ChargeUnitSelector* selector = new ChargeUnitSelector(m_creature);
                m_creature->ProcessThreatList(selector);
                if (Unit* target = selector->GetUnit())
                {
                    DoResetThreat();
                    m_creature->GetThreatManager().modifyThreatPercent(target, 100);
                    DoCastSpellIfCan(target, SPELL_CHARGE);
                    Charge_Timer = urand(15000, 22000);
                }
                else
                    Charge_Timer = 500; // On reverifiera dans 500ms
                delete selector;
            }
            else
                Charge_Timer -= diff;

            if (Frenzy_Timer < diff)
            {
                DoCastSpellIfCan(m_creature, SPELL_FRENZY);
                Frenzy_Timer = 30000;
            }
            else
                Frenzy_Timer -= diff;

            if (ForcePunch_Timer < diff)
            {
                m_creature->CastSpell(m_creature->GetVictim(), SPELL_FORCEPUNCH, true);
                ForcePunch_Timer = urand(16000, 21000);
            }
            else
                ForcePunch_Timer -= diff;

            if (m_creature->GetHealthPercent() < 11.0f && !m_creature->HasAura(SPELL_ENRAGE))
            {
                DoCastSpellIfCan(m_creature, SPELL_ENRAGE);
                Enraged = true;
            }

            if (CheckTigers_Timer < diff)
            {
                for (uint64 & guid : TigerGUIDs)
                    CheckTiger(guid);
                CheckTigers_Timer = 10000;
            }
            else
                CheckTigers_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

//Zealot Lor'Khan
struct mob_zealot_lorkhanAI : public zg_rez_add
{
    mob_zealot_lorkhanAI(Creature* pCreature) : zg_rez_add(pCreature, TYPE_LORKHAN)
    {
        bRealyDead = false;
        Reset();
    }

    uint32 Shield_Timer;
    uint32 BloodLust_Timer;
    uint32 GreaterHeal_Timer;
    uint32 Disarm_Timer;

    uint32 Resurrect_Timer;
    uint64 uiRezzeurGUID;
    bool bRealyDead;

    void Reset() override
    {
        Shield_Timer = 1000;
        BloodLust_Timer = 16000;
        GreaterHeal_Timer = 32000;
        Disarm_Timer = 6000;

        Resurrect_Timer = 10000;
        uiRezzeurGUID = 0;

        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        zg_rez_add::Reset();
    }

    void JustDied(Unit* Killer) override
    {
        zg_rez_add::JustDied(Killer);
    }

    void UpdateAI_corpse(uint32 const uiDiff) override
    {
        if (!zg_rez_add::HandleWaitRez(uiDiff))
            zg_rez_add::SetRealyDead(true);
    }

    void UpdateAI(uint32 const diff) override
    {
        zg_rez_add::UpdateAI(diff);
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Shield_Timer
        if (Shield_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_SHIELD);
            Shield_Timer = 61000;
        }
        else Shield_Timer -= diff;

        //BloodLust_Timer
        if (BloodLust_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_BLOODLUST);
            BloodLust_Timer = urand(20000, 28000);
        }
        else BloodLust_Timer -= diff;

        //GreaterHeal
        if (GreaterHeal_Timer < diff)
        {
            // Lorkhan prioritizes himself with heal when under 50%
            if (m_creature->GetHealthPercent() < 50.0f)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_GREATERHEAL) == CAST_OK)
                    GreaterHeal_Timer = 12000;
            }
            else if (Unit* pTarget = m_creature->FindLowestHpFriendlyUnit(100.0f, 9500))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_GREATERHEAL) == CAST_OK)
                    GreaterHeal_Timer = 12000;
            }
        }
        else
            GreaterHeal_Timer -= diff;

        //Disarm_Timer
        if (Disarm_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DISARM);
            Disarm_Timer = urand(15000, 25000);
        }
        else Disarm_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//Zealot Zath
struct mob_zealot_zathAI : public zg_rez_add
{
    mob_zealot_zathAI(Creature* pCreature) : zg_rez_add(pCreature, TYPE_ZATH)
    {
        bRealyDead = false;
        Reset();
    }

    uint32 SweepingStrikes_Timer;
    uint32 SinisterStrike_Timer;
    uint32 Gouge_Timer;
    uint32 Kick_Timer;
    uint32 Blind_Timer;

    uint32 Resurrect_Timer;
    uint64 uiRezzeurGUID;
    bool bRealyDead;

    void Reset() override
    {
        SweepingStrikes_Timer = 13000;
        SinisterStrike_Timer = 8000;
        Gouge_Timer = 25000;
        Kick_Timer = 18000;
        Blind_Timer = 5000;

        Resurrect_Timer = 10000;
        uiRezzeurGUID = 0;

        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        zg_rez_add::Reset();
    }

    void JustDied(Unit* Killer) override
    {
        zg_rez_add::JustDied(Killer);
    }

    void UpdateAI_corpse(uint32 const uiDiff) override
    {
        if (!zg_rez_add::HandleWaitRez(uiDiff))
            zg_rez_add::SetRealyDead(true);
    }

    void UpdateAI(uint32 const diff) override
    {
        zg_rez_add::UpdateAI(diff);
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //SweepingStrikes_Timer
        if (SweepingStrikes_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SWEEPINGSTRIKES);
            SweepingStrikes_Timer = urand(22000, 26000);
        }
        else SweepingStrikes_Timer -= diff;

        //SinisterStrike_Timer
        if (SinisterStrike_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SINISTERSTRIKE);
            SinisterStrike_Timer = urand(8000, 16000);
        }
        else SinisterStrike_Timer -= diff;

        //Gouge_Timer
        if (Gouge_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_GOUGE);

            if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -100);

            Gouge_Timer = urand(17000, 27000);
        }
        else Gouge_Timer -= diff;

        //Kick_Timer
        if (Kick_Timer < diff)
        {
            if(m_creature->GetVictim()->IsNonMeleeSpellCasted(false))
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KICK);
                Kick_Timer = urand(15000, 25000);
            }
        }
        else Kick_Timer -= diff;

        //Blind_Timer
        if (Blind_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BLIND);
            Blind_Timer = urand(10000, 20000);
        }
        else Blind_Timer -= diff;


        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_thekal(Creature* pCreature)
{
    return new boss_thekalAI(pCreature);
}

CreatureAI* GetAI_mob_zealot_lorkhan(Creature* pCreature)
{
    return new mob_zealot_lorkhanAI(pCreature);
}

CreatureAI* GetAI_mob_zealot_zath(Creature* pCreature)
{
    return new mob_zealot_zathAI(pCreature);
}

void AddSC_boss_thekal()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_thekal";
    newscript->GetAI = &GetAI_boss_thekal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_zealot_lorkhan";
    newscript->GetAI = &GetAI_mob_zealot_lorkhan;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_zealot_zath";
    newscript->GetAI = &GetAI_mob_zealot_zath;
    newscript->RegisterSelf();
}

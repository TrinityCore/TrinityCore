/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_archaedas
SD%Complete: 100
SDComment: Archaedas is activated when 3 prople click on his altar.
Every 10 seconds he will awaken one of his minions along the wall.
At 66%, he will awaken the 6 Guardians.
At 33%, he will awaken the Vault Walkers
On his death the vault door opens.
EndScriptData */

#include "precompiled.h"


#define SAY_AGGRO           "Who dares awaken Archaedas? Who dares the wrath of the makers!"
#define SOUND_AGGRO         5855

#define SAY_SUMMON          "Awake ye servants, defend the discs!"
#define SOUND_SUMMON        5856

#define SAY_SUMMON2         "To my side, brothers. For the makers!"
#define SOUND_SUMMON2       5857

#define SAY_KILL            "Reckless mortal."
#define SOUND_KILL            5858

#define SPELL_GROUND_TREMOR           6524
#define SPELL_ARCHAEDAS_AWAKEN        10347
#define SPELL_BOSS_OBJECT_VISUAL      11206
#define SPELL_BOSS_AGGRO              10340
#define SPELL_SUB_BOSS_AGGRO          11568
#define SPELL_AWAKEN_VAULT_WALKER     10258
#define SPELL_AWAKEN_EARTHEN_GUARDIAN 10252

struct TRINITY_DLL_DECL boss_archaedasAI : public ScriptedAI
{
    boss_archaedasAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = (m_creature->GetInstanceData());
    }

    uint32 Tremor_Timer;
    int32  Awaken_Timer;
    uint32 WallMinionTimer;
    bool wakingUp;

    bool guardiansAwake;
    bool vaultWalkersAwake;
    ScriptedInstance* pInstance;

    void Reset()
    {
        Tremor_Timer = 60000;
        Awaken_Timer = 0;
        WallMinionTimer = 10000;

        wakingUp = false;
        guardiansAwake = false;
        vaultWalkersAwake = false;

        if (pInstance) pInstance->SetData (NULL, 5);    // respawn any dead minions
        m_creature->setFaction(35);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

    }

    void ActivateMinion (uint64 guid, bool flag)
    {
        Unit *minion = Unit::GetUnit(*m_creature, guid);

        if (minion && minion->isAlive())
        {
            DoCast (minion, SPELL_AWAKEN_VAULT_WALKER, flag);
            minion->CastSpell(minion, SPELL_ARCHAEDAS_AWAKEN,true);
        }
    }


    void EnterCombat(Unit *who)
    {
        m_creature->setFaction (14);
        m_creature->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag (UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE);
    }

    void SpellHit (Unit* caster, const SpellEntry *spell)
    {
        // Being woken up from the altar, start the awaken sequence
        if (spell == GetSpellStore()->LookupEntry(SPELL_ARCHAEDAS_AWAKEN)) {
            DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_AGGRO);
            Awaken_Timer = 4000;
            wakingUp = true;
        }
    }

    void KilledUnit(Unit *victim)
    {
        DoYell(SAY_KILL,LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_KILL);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!pInstance)
            return;
        // we're still doing awaken animation
        if (wakingUp && Awaken_Timer >= 0) {
            Awaken_Timer -= diff;
            return;        // dont do anything until we are done
        } else if (wakingUp && Awaken_Timer <= 0) {
            wakingUp = false;
            AttackStart(Unit::GetUnit(*m_creature, pInstance->GetData64(0)));
            return;     // dont want to continue until we finish the AttackStart method
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;


        // wake a wall minion
        if (WallMinionTimer < diff) {
            pInstance->SetData (NULL, 2);

            WallMinionTimer = 10000;
        } else WallMinionTimer -= diff;

        //If we are <66 summon the guardians
        if (!guardiansAwake && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 66) {
            ActivateMinion(pInstance->GetData64(5),true);   // EarthenGuardian1
            ActivateMinion(pInstance->GetData64(6),true);   // EarthenGuardian2
            ActivateMinion(pInstance->GetData64(7),true);   // EarthenGuardian3
            ActivateMinion(pInstance->GetData64(8),true);   // EarthenGuardian4
            ActivateMinion(pInstance->GetData64(9),true);   // EarthenGuardian5
            ActivateMinion(pInstance->GetData64(10),false); // EarthenGuardian6
            DoYell(SAY_SUMMON,LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_SUMMON);
            guardiansAwake = true;
        }

        //If we are <33 summon the vault walkers
        if (!vaultWalkersAwake && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 33) {
            ActivateMinion(pInstance->GetData64(1),true);    // VaultWalker1
            ActivateMinion(pInstance->GetData64(2),true);    // VaultWalker2
            ActivateMinion(pInstance->GetData64(3),true);    // VaultWalker3
            ActivateMinion(pInstance->GetData64(4),false);    // VaultWalker4
            DoYell(SAY_SUMMON2, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_SUMMON2);
            vaultWalkersAwake = true;
        }


        if (Tremor_Timer < diff)
        {
            //Cast
            DoCast(m_creature->getVictim(),SPELL_GROUND_TREMOR);

            //45 seconds until we should cast this agian
            Tremor_Timer  = 45000;
        }else Tremor_Timer  -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied (Unit *killer) {
        if (pInstance)
        {
            pInstance->SetData(NULL,3);        // open the vault door
            pInstance->SetData(NULL,4);        // deactivate his minions
        }
    }

};

CreatureAI* GetAI_boss_archaedas(Creature* pCreature)
{
    return new boss_archaedasAI (pCreature);
}

/* ScriptData
SDName: mob_archaedas_minions
SD%Complete: 100
SDComment: These mobs are initially frozen until Archaedas awakens them
one at a time.
EndScriptData */


#define SPELL_ARCHAEDAS_AWAKEN        10347

struct TRINITY_DLL_DECL mob_archaedas_minionsAI : public ScriptedAI
{
    mob_archaedas_minionsAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = (m_creature->GetInstanceData());
    }

    uint32 Arcing_Timer;
    int32 Awaken_Timer;
    bool wakingUp;

    bool amIAwake;
    ScriptedInstance* pInstance;

    void Reset()
    {
        Arcing_Timer = 3000;
        Awaken_Timer = 0;

        wakingUp = false;
        amIAwake = false;

        m_creature->setFaction(35);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        m_creature->RemoveAllAuras();
    }

    void EnterCombat(Unit *who)
    {
        m_creature->setFaction (14);
        m_creature->RemoveAllAuras();
        m_creature->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        amIAwake = true;
    }

    void SpellHit (Unit* caster, const SpellEntry *spell) {
        // time to wake up, start animation
        if (spell == GetSpellStore()->LookupEntry(SPELL_ARCHAEDAS_AWAKEN)){
            Awaken_Timer = 5000;
            wakingUp = true;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (amIAwake)
            ScriptedAI::MoveInLineOfSight(who);
    }

    void UpdateAI(const uint32 diff)
    {
        // we're still in the awaken animation
        if (wakingUp && Awaken_Timer >= 0) {
            Awaken_Timer -= diff;
            return;        // dont do anything until we are done
        } else if (wakingUp && Awaken_Timer <= 0) {
            wakingUp = false;
            amIAwake = true;
            AttackStart(Unit::GetUnit(*m_creature, pInstance->GetData64(0))); // whoWokeArchaedasGUID
            return;     // dont want to continue until we finish the AttackStart method
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;


        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_archaedas_minions(Creature* pCreature)
{
    return new mob_archaedas_minionsAI (pCreature);
}

/* ScriptData
SDName: go_altar_archaedas
SD%Complete: 100
SDComment: Needs 3 people to activate the Archaedas script
SDCategory: Uldaman
EndScriptData */


#define OBJECT_ALTAR_OF_ARCHAEDAS   133234

#define NUMBER_NEEDED_TO_ACTIVATE 3

#define SPELL_BOSS_OBJECT_VISUAL    11206

uint64 altarOfArchaedasCount[5];
int32 altarOfArchaedasCounter=0;


bool GOHello_go_altar_of_archaedas(Player* pPlayer, GameObject* go)
{
    bool alreadyUsed;
    go->AddUse ();

    alreadyUsed = false;
    for (uint32 loop=0; loop<5; loop++) {
        if (altarOfArchaedasCount[loop] == pPlayer->GetGUID()) alreadyUsed = true;
    }
    if (!alreadyUsed)
        altarOfArchaedasCount[altarOfArchaedasCounter++] = pPlayer->GetGUID();

    pPlayer->CastSpell (pPlayer, SPELL_BOSS_OBJECT_VISUAL, false);

    if (altarOfArchaedasCounter < NUMBER_NEEDED_TO_ACTIVATE) {
        return false;        // not enough people yet
    }

    // Check to make sure at least three people are still casting
    uint32 count=0;
    Unit *pTarget;
    for (uint32 x=0; x<=5; x++) {
        pTarget = Unit::GetUnit(*pPlayer, altarOfArchaedasCount[x]);
        if (!pTarget) continue;
        if (pTarget->IsNonMeleeSpellCasted(true)) count++;
        if (count >= NUMBER_NEEDED_TO_ACTIVATE) break;
    }

    if (count < NUMBER_NEEDED_TO_ACTIVATE) {
        return false;            // not enough people
    }

    ScriptedInstance* pInstance = (pPlayer->GetInstanceData());
    if (!pInstance) return false;
    pInstance->SetData(NULL,0);
    pInstance->SetData64(0,pPlayer->GetGUID());     // activate archaedas

    return false;
}

/* ScriptData
SDName: mob_stonekeepers
SD%Complete: 100
SDComment: After activating the altar of the keepers, the stone keepers will
wake up one by one.
EndScriptData */

#include "precompiled.h"

#define SPELL_SELF_DESTRUCT           9874

struct TRINITY_DLL_DECL mob_stonekeepersAI : public ScriptedAI
{
    mob_stonekeepersAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = (m_creature->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    void Reset()
    {
        m_creature->setFaction(35);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        m_creature->RemoveAllAuras();
    }

    void EnterCombat(Unit *who)
    {
        m_creature->setFaction (14);
        m_creature->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
    }

    void UpdateAI(const uint32 diff)
    {

        //Return since we have no target
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit *attacker)
    {
        DoCast (m_creature, SPELL_SELF_DESTRUCT,true);
        if (pInstance)
            pInstance->SetData(NULL, 1);    // activate next stonekeeper
    }

};

CreatureAI* GetAI_mob_stonekeepers(Creature* pCreature)
{
    return new mob_stonekeepersAI (pCreature);
}

/* ScriptData
SDName: go_altar_of_the_keepers
SD%Complete: 100
SDComment: Need 3 people to activate to open the altar.  One by one the StoneKeepers will activate.  After all four are dead than the door will open.
SDCategory: Uldaman
EndScriptData */


#define SPELL_BOSS_OBJECT_VISUAL    11206

#define NUMBER_NEEDED_TO_ACTIVATE 3

static uint64 altarOfTheKeeperCount[5];
static uint32 altarOfTheKeeperCounter=0;

bool GOHello_go_altar_of_the_keepers(Player* pPlayer, GameObject* go)
{
    ScriptedInstance* pInstance = (pPlayer->GetInstanceData());
    if (!pInstance) return true;

    bool alreadyUsed;

    go->AddUse ();

    alreadyUsed = false;
    for (uint32 loop=0; loop<5; ++loop)
    {
        if (altarOfTheKeeperCount[loop] == pPlayer->GetGUID())
            alreadyUsed = true;
    }
    if (!alreadyUsed && altarOfTheKeeperCounter < 5)
        altarOfTheKeeperCount[altarOfTheKeeperCounter++] = pPlayer->GetGUID();
    pPlayer->CastSpell (pPlayer, SPELL_BOSS_OBJECT_VISUAL, false);

    if (altarOfTheKeeperCounter < NUMBER_NEEDED_TO_ACTIVATE)
    {
        //error_log ("not enough people yet, altarOfTheKeeperCounter = %d", altarOfTheKeeperCounter);
        return false;        // not enough people yet
    }

    // Check to make sure at least three people are still casting
    uint32 count=0;
    Unit *pTarget;
    for (uint32 x = 0; x < 5; ++x)
    {
        pTarget = Unit::GetUnit(*pPlayer, altarOfTheKeeperCount[x]);
        //error_log ("number of people currently activating it: %d", x+1);
        if (!pTarget) continue;
        if (pTarget->IsNonMeleeSpellCasted(true)) count++;
        if (count >= NUMBER_NEEDED_TO_ACTIVATE) break;
    }

    if (count < NUMBER_NEEDED_TO_ACTIVATE)
    {
        // error_log ("still not enough people");
        return true;            // not enough people
    }

    //error_log ("activating stone keepers");
    pInstance->SetData(NULL,1);        // activate the Stone Keepers
    return true;
}

void AddSC_boss_archaedas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_archaedas";
    newscript->GetAI = &GetAI_boss_archaedas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_altar_of_archaedas";
    newscript->pGOHello = &GOHello_go_altar_of_archaedas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_archaedas_minions";
    newscript->GetAI = &GetAI_mob_archaedas_minions;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="go_altar_of_the_keepers";
    newscript->pGOHello = &GOHello_go_altar_of_the_keepers;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_stonekeepers";
    newscript->GetAI = &GetAI_mob_stonekeepers;
    newscript->RegisterSelf();
}


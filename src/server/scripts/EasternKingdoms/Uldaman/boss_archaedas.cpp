/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: boss_archaedas
SD%Complete: 100
SDComment: Archaedas is activated when 1 person (was 3, changed in 3.0.8) clicks on his altar.
Every 10 seconds he will awaken one of his minions along the wall.
At 66%, he will awaken the 6 Guardians.
At 33%, he will awaken the Vault Walkers
On his death the vault door opens.
EndScriptData */

#include "ScriptPCH.h"

#define SAY_AGGRO           "Who dares awaken Archaedas? Who dares the wrath of the makers!"
#define SOUND_AGGRO         5855

#define SAY_SUMMON          "Awake ye servants, defend the discs!"
#define SOUND_SUMMON        5856

#define SAY_SUMMON2         "To my side, brothers. For the makers!"
#define SOUND_SUMMON2       5857

#define SAY_KILL            "Reckless mortal."
#define SOUND_KILL          5858

enum eSpells
{
    SPELL_GROUND_TREMOR              = 6524,
    SPELL_ARCHAEDAS_AWAKEN           = 10347,
    SPELL_BOSS_OBJECT_VISUAL         = 11206,
    SPELL_BOSS_AGGRO                 = 10340,
    SPELL_SUB_BOSS_AGGRO             = 11568,
    SPELL_AWAKEN_VAULT_WALKER        = 10258,
    SPELL_AWAKEN_EARTHEN_GUARDIAN    = 10252,
};

class boss_archaedas : public CreatureScript
{
    public:

        boss_archaedas()
            : CreatureScript("boss_archaedas")
        {
        }

        struct boss_archaedasAI : public ScriptedAI
        {
            boss_archaedasAI(Creature *c) : ScriptedAI(c)
            {
                pInstance = me->GetInstanceData();
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

                if (pInstance)
                    pInstance->SetData (NULL, 5);    // respawn any dead minions
                me->setFaction(35);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }

            void ActivateMinion (uint64 guid, bool flag)
            {
                Unit *minion = Unit::GetUnit(*me, guid);

                if (minion && minion->isAlive())
                {
                    DoCast (minion, SPELL_AWAKEN_VAULT_WALKER, flag);
                    minion->CastSpell(minion, SPELL_ARCHAEDAS_AWAKEN,true);
                }
            }

            void EnterCombat(Unit * /*who*/)
            {
                me->setFaction (14);
                me->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag (UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE);
            }

            void SpellHit (Unit* /*caster*/, const SpellEntry *spell)
            {
                // Being woken up from the altar, start the awaken sequence
                if (spell == GetSpellStore()->LookupEntry(SPELL_ARCHAEDAS_AWAKEN)) {
                    me->MonsterYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(me,SOUND_AGGRO);
                    Awaken_Timer = 4000;
                    wakingUp = true;
                }
            }

            void KilledUnit(Unit * /*victim*/)
            {
                me->MonsterYell(SAY_KILL,LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(me, SOUND_KILL);
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
                    AttackStart(Unit::GetUnit(*me, pInstance->GetData64(0)));
                    return;     // dont want to continue until we finish the AttackStart method
                }

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                // wake a wall minion
                if (WallMinionTimer <= diff) {
                    pInstance->SetData (NULL, 2);

                    WallMinionTimer = 10000;
                } else WallMinionTimer -= diff;

                //If we are <66 summon the guardians
                if (!guardiansAwake && me->GetHealth()*100 / me->GetMaxHealth() <= 66) {
                    ActivateMinion(pInstance->GetData64(5),true);   // EarthenGuardian1
                    ActivateMinion(pInstance->GetData64(6),true);   // EarthenGuardian2
                    ActivateMinion(pInstance->GetData64(7),true);   // EarthenGuardian3
                    ActivateMinion(pInstance->GetData64(8),true);   // EarthenGuardian4
                    ActivateMinion(pInstance->GetData64(9),true);   // EarthenGuardian5
                    ActivateMinion(pInstance->GetData64(10),false); // EarthenGuardian6
                    me->MonsterYell(SAY_SUMMON,LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(me, SOUND_SUMMON);
                    guardiansAwake = true;
                }

                //If we are <33 summon the vault walkers
                if (!vaultWalkersAwake && me->GetHealth()*100 / me->GetMaxHealth() <= 33) {
                    ActivateMinion(pInstance->GetData64(1),true);    // VaultWalker1
                    ActivateMinion(pInstance->GetData64(2),true);    // VaultWalker2
                    ActivateMinion(pInstance->GetData64(3),true);    // VaultWalker3
                    ActivateMinion(pInstance->GetData64(4),false);    // VaultWalker4
                    me->MonsterYell(SAY_SUMMON2, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(me, SOUND_SUMMON2);
                    vaultWalkersAwake = true;
                }

                if (Tremor_Timer <= diff)
                {
                    //Cast
                    DoCast(me->getVictim(), SPELL_GROUND_TREMOR);

                    //45 seconds until we should cast this agian
                    Tremor_Timer  = 45000;
                } else Tremor_Timer  -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied (Unit *pKiller) {
                if (pInstance)
                {
                    pInstance->SetData(NULL,3);        // open the vault door
                    pInstance->SetData(NULL,4);        // deactivate his minions
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_archaedasAI(creature);
        }
};

/* ScriptData
SDName: mob_archaedas_minions
SD%Complete: 100
SDComment: These mobs are initially frozen until Archaedas awakens them
one at a time.
EndScriptData */

#define SPELL_ARCHAEDAS_AWAKEN  10347

class mob_archaedas_minions : public CreatureScript
{
    public:

        mob_archaedas_minions()
            : CreatureScript("mob_archaedas_minions")
        {
        }

        struct mob_archaedas_minionsAI : public ScriptedAI
        {
            mob_archaedas_minionsAI(Creature *c) : ScriptedAI(c)
            {
                pInstance = me->GetInstanceData();
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

                me->setFaction(35);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->RemoveAllAuras();
            }

            void EnterCombat(Unit * /*who*/)
            {
                me->setFaction (14);
                me->RemoveAllAuras();
                me->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                amIAwake = true;
            }

            void SpellHit (Unit* /*caster*/, const SpellEntry *spell) {
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
                    // AttackStart(Unit::GetUnit(*me, pInstance->GetData64(0))); // whoWokeArchaedasGUID
                    return;     // dont want to continue until we finish the AttackStart method
                }

                //Return since we have no target
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_archaedas_minionsAI(creature);
        }
};

/* ScriptData
SDName: mob_stonekeepers
SD%Complete: 100
SDComment: After activating the altar of the keepers, the stone keepers will
wake up one by one.
EndScriptData */

#define SPELL_SELF_DESTRUCT 9874

class mob_stonekeepers : public CreatureScript
{
    public:

        mob_stonekeepers()
            : CreatureScript("mob_stonekeepers")
        {
        }

        struct mob_stonekeepersAI : public ScriptedAI
        {
            mob_stonekeepersAI(Creature *c) : ScriptedAI(c)
            {
                pInstance = (me->GetInstanceData());
            }

            ScriptedInstance* pInstance;

            void Reset()
            {
                me->setFaction(35);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->RemoveAllAuras();
            }

            void EnterCombat(Unit * /*who*/)
            {
                me->setFaction (14);
                me->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit * /*attacker*/)
            {
                DoCast (me, SPELL_SELF_DESTRUCT,true);
                if (pInstance)
                    pInstance->SetData(NULL, 1);    // activate next stonekeeper
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_stonekeepersAI(creature);
        }
};

/* ScriptData
SDName: go_altar_archaedas
SD%Complete: 100
SDComment: Needs 1 person to activate the Archaedas script
SDCategory: Uldaman
EndScriptData */

#define SPELL_BOSS_OBJECT_VISUAL    11206

class go_altar_of_archaedas : public CreatureScript
{
    public:

        go_altar_of_archaedas()
            : CreatureScript("go_altar_of_archaedas")
        {
        }

        bool OnGossipHello(Player* pPlayer, GameObject* /*pGo*/)
        {
            ScriptedInstance* pInstance = pPlayer->GetInstanceData();
            if (!pInstance)
                return false;

            pPlayer->CastSpell (pPlayer, SPELL_BOSS_OBJECT_VISUAL, false);

            pInstance->SetData(NULL,0);
            pInstance->SetData64(0,pPlayer->GetGUID());     // activate archaedas
            return false;
        }
};

/* ScriptData
SDName: go_altar_of_the_keepers
SD%Complete: 100
SDComment: Need 1 person to activate to open the altar.  One by one the StoneKeepers will activate.  After all four are dead than the door will open.
SDCategory: Uldaman
EndScriptData */

#define SPELL_BOSS_OBJECT_VISUAL    11206

class go_altar_of_the_keepers : public CreatureScript
{
    public:

        go_altar_of_the_keepers()
            : CreatureScript("go_altar_of_the_keepers")
        {
        }

        bool OnGossipHello(Player* pPlayer, GameObject* /*pGo*/)
        {
            ScriptedInstance* pInstance = pPlayer->GetInstanceData();
            if (!pInstance)
                return false;

            pPlayer->CastSpell (pPlayer, SPELL_BOSS_OBJECT_VISUAL, false);

            pInstance->SetData(NULL,1); // activate the Stone Keepers
            return false;
        }
};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_boss_archaedas()
{
    new boss_archaedas();
    new mob_archaedas_minions();
    new mob_stonekeepers();
    new go_altar_of_archaedas();
    new go_altar_of_the_keepers();
}


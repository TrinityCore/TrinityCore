/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ahnkahet.h"

//not in db
enum Yells
{
    SAY_AGGRO                                     = -1619014,
    SAY_SLAY_1                                    = -1619015,
    SAY_SLAY_2                                    = -1619016,
    SAY_SLAY_3                                    = -1619017,
    SAY_DEATH                                     = -1619018,
    SAY_EGG_SAC_1                                 = -1619019,
    SAY_EGG_SAC_2                                 = -1619020
};

enum Spells
{
    SPELL_BROOD_PLAGUE                            = 56130,
    H_SPELL_BROOD_PLAGUE                          = 59467,
    H_SPELL_BROOD_RAGE                            = 59465,
    SPELL_ENRAGE                                  = 26662, // Enraged if too far away from home
    SPELL_SUMMON_SWARMERS                         = 56119, //2x 30178  -- 2x every 10secs
    SPELL_SUMMON_SWARM_GUARD                      = 56120, //1x 30176  -- every 25secs
};

enum Creatures
{
    MOB_AHNKAHAR_SWARMER                          = 30178,
    MOB_AHNKAHAR_GUARDIAN_ENTRY                   = 30176
};

#define ACTION_AHNKAHAR_GUARDIAN_DEAD             1
#define DATA_RESPECT_YOUR_ELDERS                  2

#define EMOTE_HATCHES                       "An Ahn'kahar Guardian hatches!"

class boss_elder_nadox : public CreatureScript
{
    public:
        boss_elder_nadox() : CreatureScript("boss_elder_nadox") { }

        struct boss_elder_nadoxAI : public ScriptedAI
        {
            boss_elder_nadoxAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            uint32 uiPlagueTimer;
            uint32 uiRagueTimer;

            uint32 uiSwarmerSpawnTimer;
            uint32 uiGuardSpawnTimer;
            uint32 uiEnrageTimer;

            bool bGuardSpawned;
            bool respectYourElders;

            InstanceScript* instance;

            void Reset()
            {
                uiPlagueTimer = 13000;
                uiRagueTimer = 20000;

                uiSwarmerSpawnTimer = 10000;
                uiGuardSpawnTimer = 25000;

                uiEnrageTimer = 5000;

                bGuardSpawned = false;
                respectYourElders = true;

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_DEATH, me);

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, IN_PROGRESS);
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
            }

            void JustDied(Unit* /*who*/)
            {
                DoScriptText(SAY_SLAY_3, me); //SAY_SLAY_3 on death?

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, DONE);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_AHNKAHAR_GUARDIAN_DEAD)
                    respectYourElders = false;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_RESPECT_YOUR_ELDERS)
                    return respectYourElders ? 1 : 0;

                return 0;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (uiPlagueTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_BROOD_PLAGUE);
                    uiPlagueTimer = 15000;
                }
                else
                    uiPlagueTimer -= diff;

                if (IsHeroic())
                {
                    if (uiRagueTimer <= diff)
                    {
                        if (Creature* Swarmer = me->FindNearestCreature(MOB_AHNKAHAR_SWARMER, 35.0f))
                        {
                            DoCast(Swarmer, H_SPELL_BROOD_RAGE, true);
                            uiRagueTimer = 15000;
                        }
                    }
                    else
                        uiRagueTimer -= diff;
                }

                if (uiSwarmerSpawnTimer <= diff)
                {
                    DoCast(me, SPELL_SUMMON_SWARMERS, true);
                    DoCast(me, SPELL_SUMMON_SWARMERS);
                    if (urand(1, 3) == 3) // 33% chance of dialog
                        DoScriptText(RAND(SAY_EGG_SAC_1, SAY_EGG_SAC_2), me);

                    uiSwarmerSpawnTimer = 10000;
                }
                else
                    uiSwarmerSpawnTimer -= diff;

                if (!bGuardSpawned && uiGuardSpawnTimer <= diff)
                {
                    me->MonsterTextEmote(EMOTE_HATCHES, me->GetGUID(), true);
                    DoCast(me, SPELL_SUMMON_SWARM_GUARD);
                    bGuardSpawned = true;
                }
                else
                    uiGuardSpawnTimer -= diff;

                if (uiEnrageTimer <= diff)
                {
                    if (me->HasAura(SPELL_ENRAGE, 0))
                        return;

                    float x, y, z, o;
                    me->GetHomePosition(x, y, z, o);
                    if (z < 24)
                        if (!me->IsNonMeleeSpellCasted(false))
                            DoCast(me, SPELL_ENRAGE, true);

                    uiEnrageTimer = 5000;
                }
                else
                    uiEnrageTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_elder_nadoxAI(creature);
        }
};

enum AddSpells
{
    SPELL_SPRINT                                  = 56354,
    SPELL_GUARDIAN_AURA                           = 56151
};

class mob_ahnkahar_nerubian : public CreatureScript
{
    public:
        mob_ahnkahar_nerubian() : CreatureScript("mob_ahnkahar_nerubian") { }

        struct mob_ahnkahar_nerubianAI : public ScriptedAI
        {
            mob_ahnkahar_nerubianAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 uiSprintTimer;

            void Reset()
            {
                if (me->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
                    DoCast(me, SPELL_GUARDIAN_AURA, true);
                uiSprintTimer = 10000;
            }

            void JustDied(Unit* /*who*/)
            {
                if (me->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
                    if (Creature* Nadox = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ELDER_NADOX)))
                        Nadox->AI()->DoAction(ACTION_AHNKAHAR_GUARDIAN_DEAD);
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
                    me->RemoveAurasDueToSpell(SPELL_GUARDIAN_AURA);

                if (instance)
                    if (instance->GetData(DATA_ELDER_NADOX_EVENT) != IN_PROGRESS)
                        me->DespawnOrUnsummon();

                if (uiSprintTimer <= diff)
                {
                    DoCast(me, SPELL_SPRINT);
                    uiSprintTimer = 25000;
                }
                else
                    uiSprintTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ahnkahar_nerubianAI(creature);
        }
};

//HACK: No, AI. Replace with proper db content?
class mob_nadox_eggs : public CreatureScript
{
public:
    mob_nadox_eggs() : CreatureScript("mob_nadox_eggs") { }

    struct mob_nadox_eggsAI : public Scripted_NoMovementAI
    {
        mob_nadox_eggsAI(Creature* c) : Scripted_NoMovementAI(c)
        {
            c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            c->UpdateAllStats();
        }
        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*victim*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(const uint32 /*diff*/) {}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_nadox_eggsAI(creature);
    }
};

class achievement_respect_your_elders : public AchievementCriteriaScript
{
    public:
        achievement_respect_your_elders() : AchievementCriteriaScript("achievement_respect_your_elders")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Nadox = target->ToCreature())
                if (Nadox->AI()->GetData(DATA_RESPECT_YOUR_ELDERS))
                    return true;

            return false;
        }
};

void AddSC_boss_elder_nadox()
{
    new boss_elder_nadox;
    new mob_ahnkahar_nerubian;
    new mob_nadox_eggs;
    new achievement_respect_your_elders();
}

/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ulduar.h"

enum eYells
{
    SAY_AGGRO                                    = -1603290,
    SAY_SLAY_1                                   = -1603291,
    SAY_SLAY_2                                   = -1603292,
    SAY_SURGE_OF_DARKNESS                        = -1603293,
    SAY_DEATH                                    = -1603294,
    SAY_BERSERK                                  = -1603295,
    SAY_HARDMODE                                 = -1603296,
};

enum eEmotes
{
    EMOTE_VAPORS                                 = -1603289,
    EMOTE_ANIMUS                                 = -1603297,
    EMOTE_BARRIER                                = -1603298,
    EMOTE_SURGE_OF_DARKNESS                      = -1603299,
};

enum eSpells
{
    SPELL_AURA_OF_DESPAIR                        = 62692,
    SPELL_MARK_OF_THE_FACELESS                   = 63276,
    SPELL_SARONITE_BARRIER                       = 63364,
    SPELL_SEARING_FLAMES                         = 62661,
    SPELL_SHADOW_CRASH                           = 62660,
    SPELL_SHADOW_CRASH_HIT                       = 62659, 
    SPELL_SURGE_OF_DARKNESS                      = 62662,
    SPELL_SARONITE_VAPORS                        = 63323,
    SPELL_SUMMON_SARONITE_VAPORS                 = 63081,
    SPELL_PROFOUND_OF_DARKNESS                   = 63420,
    SPELL_BERSERK                                = 26662,

    SPELL_SUMMON_SARONITE_ANIMUS                 = 63145,
    SPELL_VISUAL_SARONITE_ANIMUS                 = 63319,
    SPELL_PROFOUND_DARKNESS                      = 63420,

    SPELL_CORRUPTED_RAGE                         = 68415,
    SPELL_SHAMANTIC_RAGE                         = 30823,
};

enum eActions
{
    ACTION_VAPORS_SPAWN,
    ACTION_VAPORS_DIE,
    ACTION_ANIMUS_DIE,
};

enum eEvents
{
    EVENT_SHADOW_CRASH                           = 1,
    EVENT_SEARING_FLAMES                         = 2,
    EVENT_SURGE_OF_DARKNESS                      = 3,
    EVENT_MARK_OF_THE_FACELESS                   = 4,
    EVENT_SARONITE_VAPORS                        = 5,
    EVENT_BERSERK                                = 6,
};
 
#define ACHIEVEMENT_SMELL_SARONITE               RAID_MODE(3181, 3188)
#define ACHIEVEMENT_SHADOWDODGER                 RAID_MODE(2996, 2997)

class boss_general_vezax : public CreatureScript
{
public:
    boss_general_vezax() : CreatureScript("boss_general_vezax") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_general_vezaxAI(pCreature);
    }

    struct boss_general_vezaxAI : public BossAI
    {
        boss_general_vezaxAI(Creature *pCreature) : BossAI(pCreature, TYPE_VEZAX)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
        }

        bool bShadowDodger;
        bool bSmellSaronite; /*HardMode*/
        bool bAnimusDead; /*Check against getting a HardMode achievement before killing Saronite Animus*/
        uint8 uiVaporCount;

        void Reset()
        {
            _Reset();

            events.Reset();
            summons.DespawnAll();
            me->ResetLootMode();
            bShadowDodger = true;
            bSmellSaronite = true;
            bAnimusDead = false;
            uiVaporCount = 0;
        }

        void EnterCombat(Unit * /*pWho*/)
        {
            _EnterCombat();
            
            DoScriptText(SAY_AGGRO, me);
            DoCast(me, SPELL_AURA_OF_DESPAIR);
            CheckShamanisticRage();

            events.Reset();
            events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(8000, 10000));
            events.ScheduleEvent(EVENT_SEARING_FLAMES, 12000);
            events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(35000, 40000));
            events.ScheduleEvent(EVENT_SARONITE_VAPORS, 30000);
            events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 60000);
            events.ScheduleEvent(EVENT_BERSERK, 600000);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            events.Update(uiDiff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 uiEventId = events.ExecuteEvent())
            {
                switch (uiEventId)
                {
                    case EVENT_SHADOW_CRASH:
                        if (Unit * pTarget = GetPlayerAtMinimumRange(15.0f))
                            DoCast(pTarget, SPELL_SHADOW_CRASH);
                        events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(8000, 12000));
                        break;
                    case EVENT_SEARING_FLAMES:
                        DoCastAOE(SPELL_SEARING_FLAMES);
                        events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(14000, 17500));
                        break;
                    case EVENT_MARK_OF_THE_FACELESS:
                        Unit* pTarget;
                        /*  He will not cast this on players within 15 yards of him. 
                            However, if there are not at least 9 people outside of 15 yards 
                            he will start casting it on players inside 15 yards melee and tank included.
                        */
                        if (!(pTarget = CheckPlayersInRange(RAID_MODE(4,9), 15.0f, 50.f)))
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM); 
                        DoCast(pTarget, SPELL_MARK_OF_THE_FACELESS);
                        events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(35000, 45000));
                        break;
                    case EVENT_SURGE_OF_DARKNESS:
                        DoScriptText(EMOTE_SURGE_OF_DARKNESS, me);
                        DoScriptText(SAY_SURGE_OF_DARKNESS, me);
                        DoCast(me, SPELL_SURGE_OF_DARKNESS);
                        events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, urand(50000, 70000));
                        break;
                    case EVENT_SARONITE_VAPORS:
                        DoCast(SPELL_SUMMON_SARONITE_VAPORS);
                        events.ScheduleEvent(EVENT_SARONITE_VAPORS, urand(30000, 35000));
                        
                        if (++uiVaporCount == 6 && bSmellSaronite)
                        {
                            DoScriptText(SAY_HARDMODE, me);
                            DoScriptText(EMOTE_BARRIER, me);
                            summons.DespawnAll();
                            DoCast(me, SPELL_SARONITE_BARRIER);
                            DoCast(SPELL_SUMMON_SARONITE_ANIMUS);
                            me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                            events.CancelEvent(EVENT_SARONITE_VAPORS);
                            events.CancelEvent(EVENT_SEARING_FLAMES);
                        }
                        break;
                    case EVENT_BERSERK:
                        DoScriptText(SAY_BERSERK, me);
                        DoCast(me, SPELL_BERSERK);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void SpellHitTarget(Unit * pWho, const SpellEntry * pSpell)
        {
            if (pWho && pWho->GetTypeId() == TYPEID_PLAYER && pSpell->Id == SPELL_SHADOW_CRASH_HIT)
                bShadowDodger = false;
        }

        void KilledUnit(Unit * /*pWho*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void JustDied(Unit * /*pWho*/)
        {
            _JustDied();
            
            DoScriptText(SAY_DEATH, me);

            if (instance)
            {
                if (bShadowDodger)
                    instance->DoCompleteAchievement(ACHIEVEMENT_SHADOWDODGER);

                if (bSmellSaronite && bAnimusDead)
                    instance->DoCompleteAchievement(ACHIEVEMENT_SMELL_SARONITE);
            }
        }

        void CheckShamanisticRage()
        {
            if (instance)
            {
                Map * pMap = me->GetMap();
                if (pMap && pMap->IsDungeon())
                {
                    /* If Shaman has Shamanistic Rage and use it during the fight, it will cast Corrupted Rage on him */
                    Map::PlayerList const &Players = pMap->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                        if (Player * pPlayer = itr->getSource())
                            if (pPlayer->HasSpell(SPELL_SHAMANTIC_RAGE))
                                pPlayer->CastSpell(pPlayer, SPELL_CORRUPTED_RAGE, false);
                }
            }
        }

        void DoAction(const int32 uiAction)
        {
            switch (uiAction)
            {
                case ACTION_VAPORS_DIE:
                    bSmellSaronite = false;
                    break;
                case ACTION_ANIMUS_DIE:
                    me->RemoveAurasDueToSpell(SPELL_SARONITE_BARRIER);
                    events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(7000, 12000));
                    bAnimusDead = true;
                    break;
            }
        }

        /*  Player Range Check
            Purpose: If there are uiPlayersMin people within uiRangeMin, uiRangeMax: return a random players in that range.
            If not, return NULL and allow other target selection
        */
        Unit * CheckPlayersInRange(uint32 uiPlayersMin, float uiRangeMin, float uiRangeMax)
        {
            Map * pMap = me->GetMap();
            if (pMap && pMap->IsDungeon())
            {
                std::list<Player*> PlayerList;
                Map::PlayerList const &Players = pMap->GetPlayers();
                for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                {
                    if (Player * pPlayer = itr->getSource())
                    {
                        float uiDistance = pPlayer->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                        if (uiRangeMin < uiDistance || uiDistance > uiRangeMax)
                            continue;

                        PlayerList.push_back(pPlayer);
                    }
                }

                if (PlayerList.empty())
                    return NULL;

                size_t size = PlayerList.size();
                if (size < uiPlayersMin)
                    return NULL;

                std::list<Player*>::const_iterator itr = PlayerList.begin();
                std::advance(itr, urand(0, size - 1));
                return *itr;
            }
            else
                return NULL;
        }
    };
};

class boss_saronite_animus : public CreatureScript
{
public:
    boss_saronite_animus() : CreatureScript("npc_saronite_animus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_saronite_animusAI(pCreature);
    }

    struct boss_saronite_animusAI : public ScriptedAI
    {
        boss_saronite_animusAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
            DoScriptText(EMOTE_BARRIER, me);
        }

        InstanceScript * pInstance;

        uint32 uiProfoundOfDarknessTimer;

        void Reset()
        {
            DoCast(me, SPELL_VISUAL_SARONITE_ANIMUS);
            uiProfoundOfDarknessTimer = 3000;
        }

        void JustDied(Unit * /*pWho*/)
        {
            if (Creature * pVezax = me->GetCreature(*me, pInstance ? pInstance->GetData64(TYPE_VEZAX) : 0))
                pVezax->AI()->DoAction(ACTION_ANIMUS_DIE);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;
            
            if (uiProfoundOfDarknessTimer <= uiDiff)
            {
                DoCastAOE(SPELL_PROFOUND_DARKNESS);
                uiProfoundOfDarknessTimer = 3000;
            }
            else
                uiProfoundOfDarknessTimer -= uiDiff;
            
            DoMeleeAttackIfReady();
        }
    };
};

class npc_saronite_vapors : public CreatureScript
{
public:
    npc_saronite_vapors() : CreatureScript("npc_saronite_vapors") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_saronite_vaporsAI(pCreature);
    }

    struct npc_saronite_vaporsAI : public ScriptedAI
    {
        npc_saronite_vaporsAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            DoScriptText(EMOTE_VAPORS, me);
            pInstance = pCreature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
            me->SetReactState(REACT_PASSIVE);
            uiRandomMoveTimer = 1000;
        }

        InstanceScript * pInstance;

        uint32 uiRandomMoveTimer;

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiRandomMoveTimer <= uiDiff)
            {
                me->GetMotionMaster()->MoveRandom(30.0f);
                uiRandomMoveTimer = urand(5000, 7500);
            }
            else
                uiRandomMoveTimer -= uiDiff;
        }

        void DamageTaken(Unit * /*pWho*/, uint32 &uiDamage)
        {
            // This can't be on JustDied. In 63322 dummy handler caster needs to be this NPC
            // if caster == target then damage mods will increase the damage taken
            if (uiDamage >= me->GetHealth())
            {
                uiDamage = 0;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);
                me->SetHealth(me->GetMaxHealth());
                me->RemoveAllAuras();
                DoCast(me, SPELL_SARONITE_VAPORS);
                me->DespawnOrUnsummon(30000);
                
                if (Creature * pVezax = me->GetCreature(*me, pInstance ? pInstance->GetData64(TYPE_VEZAX) : 0))
                    pVezax->AI()->DoAction(ACTION_VAPORS_DIE);
            }
        }
    };
};

void AddSC_boss_general_vezax()
{
    new boss_general_vezax();
    new boss_saronite_animus();
    new npc_saronite_vapors();
}

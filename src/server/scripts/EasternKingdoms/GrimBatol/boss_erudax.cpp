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
#include "grim_batol.h"

#define SAY_AGGRO "The darkest days are still ahead!"
#define SAY_DEATH "Ywaq maq oou; ywaq maq ssaggh. Yawq ma shg'fhn."
#define SAY_SUMMON "Come, suffering... Enter, chaos!"
#define SAY_SHADOW_GALE "F'lakh ghet! The shadow's hunger cannot be sated!"
#define SAY_KILL "More flesh for the offering!"

enum Spells
{
    // Erudax
    SPELL_ENFEEBLING_BLOW               = 75789,
    SPELL_SHADOW_GALE_SUMMON            = 75655,
    SPELL_SHADOW_GALE_DAMAGE            = 75692,
    SPELL_SHADOW_GALE_VISUAL            = 75664,
    SPELL_SHADOW_GALE_SPEED_TRIGGER     = 75675,
    SPELL_SPAWN_FACELESS                = 75704,
    SPELL_TWILIGHT_PORTAL_VISUAL        = 95716,
    SPELL_SHIELD_OF_NIGHTMARE           = 75809,
    SPELL_BINDING_SHADOWS               = 79466,
    SPELL_UMBRAL_MENDING                = 79467,
    SPELL_TWILIGHT_CORRUPTION           = 75569,

    // Alexstraszas Eggs
    SPELL_SUMMON_TWILIGHT_HATCHLINGS = 91058,
};

enum Events
{
    EVENT_ENFEEBLING_BLOW                   = 1,
    EVENT_SHADOW_GALE                       = 2,
    EVENT_SUMMON_FACELESS                   = 3,
    EVENT_REMOVE_TWILIGHT_PORTAL            = 4,
    EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY    = 5,
    EVENT_BINDING_SHADOWS                   = 6,
    EVENT_TRIGGER_GALE_CHECK_PLAYERS        = 7,
};

enum Points
{
    POINT_FACELESS_IS_AT_AN_EGG = 1,
    POINT_ERUDAX_IS_AT_STALKER  = 2,
};

class boss_erudax: public CreatureScript
{
public:
    boss_erudax() : CreatureScript("boss_erudax") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_erudaxAI (creature);
    }

    struct boss_erudaxAI : public ScriptedAI
    {
        boss_erudaxAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        Unit* FacelessPortalStalker;
        Unit* ShadowGaleTrigger;

        InstanceScript* pInstance;
        EventMap events;

        SummonList Summons;
        bool ShouldSummonAdds;

        void Reset()
        {
            me->GetMotionMaster()->MoveTargetedHome();
            ShouldSummonAdds = false;

            events.Reset();
            ResetMinions();
        }

        void EnterCombat(Unit* /*who*/)
        {
            ShouldSummonAdds = false;

            me->SetReactState(REACT_AGGRESSIVE);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(me->getVictim());

            events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, 4000);
            events.ScheduleEvent(EVENT_BINDING_SHADOWS, 9000);
            events.ScheduleEvent(EVENT_SHADOW_GALE, 20000);

            me->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);

            if(FacelessPortalStalker = me->SummonCreature(NPC_FACELESS_PORTAL_STALKER,-641.515f,-827.8f,235.5f,3.069f,TEMPSUMMON_MANUAL_DESPAWN))
                FacelessPortalStalker->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(ShouldSummonAdds)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(me->getVictim());

                if ((rand()%2))
                    me->MonsterYell(SAY_SUMMON, LANG_UNIVERSAL, NULL);

                if(FacelessPortalStalker)
                {
                    FacelessPortalStalker->GetAI()->DoCast(FacelessPortalStalker,SPELL_TWILIGHT_PORTAL_VISUAL,true);
                    events.ScheduleEvent(EVENT_REMOVE_TWILIGHT_PORTAL, 7000);

                    FacelessPortalStalker->GetAI()->DoCast(FacelessPortalStalker,SPELL_SPAWN_FACELESS,true);

                    ShouldSummonAdds = false;
                    events.ScheduleEvent(EVENT_SHADOW_GALE, urand(40000,44000));
                }
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ENFEEBLING_BLOW:
                        DoCastVictim(SPELL_ENFEEBLING_BLOW);
                        events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, urand(19000,24000));
                        break;
                    case EVENT_SHADOW_GALE:
                        DoCastAOE(SPELL_SHADOW_GALE_SUMMON,true);
                        if (Creature* ShadowGaleTrigger = me->FindNearestCreature(NPC_SHADOW_GALE_STALKER, 50.0f, true))
                        {
                           me->SetReactState(REACT_PASSIVE);
                           me->GetMotionMaster()->MovePoint(POINT_ERUDAX_IS_AT_STALKER,ShadowGaleTrigger->GetPositionX(),ShadowGaleTrigger->GetPositionY(),ShadowGaleTrigger->GetPositionZ());
                        }
                        break;
                    case EVENT_REMOVE_TWILIGHT_PORTAL:
                        if(FacelessPortalStalker)
                           FacelessPortalStalker->RemoveAllAuras();
                        break;
                    case EVENT_BINDING_SHADOWS:
                        if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                            DoCast(tempTarget,SPELL_BINDING_SHADOWS);
                        events.ScheduleEvent(EVENT_BINDING_SHADOWS, urand(12000,17000));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void KilledUnit(Unit* victim)
        {
            me->MonsterYell(SAY_KILL, LANG_UNIVERSAL, NULL);
        }

        virtual void JustReachedHome()
        {
            ResetMinions();
        }

        void JustDied(Unit* /*killer*/)
        {
            ResetMinions();
            me->MonsterYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        }

        void JustSummoned(Creature* summon)
        {
            if(summon)
            {
                summon->setActive(true);
                Summons.Summon(summon);
            }
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            if (summon->GetCreatureTemplate()->Entry == NPC_SHADOW_GALE_STALKER)
            {
                ShouldSummonAdds = true;
            }
            Summons.Despawn(summon);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case POINT_ERUDAX_IS_AT_STALKER:
                        if (Creature* ShadowGaleTrigger = me->FindNearestCreature(NPC_SHADOW_GALE_STALKER, 2.0f, true))
                        {
                           ShadowGaleTrigger->GetAI()->DoCast(ShadowGaleTrigger,SPELL_SHADOW_GALE_SPEED_TRIGGER,false);
                           DoCastAOE(SPELL_SHADOW_GALE_VISUAL);
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        void ResetMinions()
        {
            Summons.DespawnAll();
            RespawnEggs();
        }

        void RespawnEggs()
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, NPC_ALEXSTRASZAS_EGG, 1000.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
            {
                if((*iter)->isDead())
                    (*iter)->Respawn();

                (*iter)->SetHealth(77500);
                (*iter)->SetMaxHealth(77500);
            }
        }
    };
};

class mob_faceless : public CreatureScript
{
public:
    mob_faceless() : CreatureScript("mob_faceless") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_facelessAI (creature);
    }

    struct mob_facelessAI : public ScriptedAI
    {
        mob_facelessAI(Creature* creature) : ScriptedAI(creature)
        {
            pTarget = NULL;
            isAtAnEgg = false;
            isCastingUmbraMending = false;
        }

        Creature* pTarget;
        Unit* pErudax;

        bool isAtAnEgg;
        bool isCastingUmbraMending;

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            pTarget = GetRandomEgg();

            DoZoneInCombat();

            if(me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY, 3000);

            if(pTarget)
                me->GetMotionMaster()->MovePoint(POINT_FACELESS_IS_AT_AN_EGG,pTarget->GetPositionX()-4.0f,pTarget->GetPositionY()-4.0f,pTarget->GetPositionZ());

            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (pTarget == NULL || !isAtAnEgg || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY:
                        DoCast(me, SPELL_SHIELD_OF_NIGHTMARE, true);
                        break;
                    default:
                        break;
                }
            }

            if(isCastingUmbraMending)
            {
                pTarget = GetNextEgg();

                if(pTarget)
                    me->GetMotionMaster()->MovePoint(POINT_FACELESS_IS_AT_AN_EGG,pTarget->GetPositionX(),pTarget->GetPositionY(),pTarget->GetPositionZ());

                isAtAnEgg = false;
                isCastingUmbraMending = false;
                return;
            }

            if(pTarget)
            {
                if(pTarget->isDead())
                {
                    if(Unit* pErudax = me->FindNearestCreature(BOSS_ERUDAX,1000.0f, true))
                        DoCast(pErudax, SPELL_UMBRAL_MENDING,false);

                    isCastingUmbraMending = true;
                    return;
                }

                pTarget->AI()->DoZoneInCombat();

                DoCast(pTarget,SPELL_TWILIGHT_CORRUPTION,true);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case POINT_FACELESS_IS_AT_AN_EGG:
                        isAtAnEgg = true;
                        break;
                    default:
                        break;
                }
            }
        }

        void JustDied(Unit* killer)
        {
            if(isAtAnEgg && pTarget->isAlive())
                pTarget->RemoveAllAuras();
        }

        Creature* GetRandomEgg()
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, NPC_ALEXSTRASZAS_EGG, 300.0f);

            if (creatures.empty())
                return GetNextEgg();

            uint32 c = 0;
            uint32 r = urand(0,creatures.size());

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
            {
                if (c == r)
                    return (*iter);
                c++;
            }
            return GetNextEgg();
        }

        inline Creature* GetNextEgg()
        {
            return me->FindNearestCreature(NPC_ALEXSTRASZAS_EGG,1000.0f, true);
        }
    };
};

class mob_alexstraszas_eggs : public CreatureScript
{
public:
    mob_alexstraszas_eggs() : CreatureScript("mob_alexstraszas_eggs") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_alexstraszas_eggsAI (creature);
    }

    struct mob_alexstraszas_eggsAI : public ScriptedAI
    {
        mob_alexstraszas_eggsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 TwilightCorruptionTimer;

        void Reset()
        {
            TwilightCorruptionTimer = 9 * IN_MILLISECONDS;
        }

        void JustDied(Unit* killer)
        {
            DoCastAOE(SPELL_SUMMON_TWILIGHT_HATCHLINGS, true);
        }

        void JustSummoned(Creature* summon)
        {
            if(summon)
            {
                summon->setActive(true);
                summon->AI()->DoZoneInCombat();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(me->HasAura(75569))
            {
                if (TwilightCorruptionTimer <= diff)
                {
                    me->DealDamage(me,me->GetHealth());
                    TwilightCorruptionTimer = 9 * IN_MILLISECONDS;
                } else TwilightCorruptionTimer -= diff;
            }
        }
    };
};


class ShadowGaleTargetSelector
{
public:
    explicit ShadowGaleTargetSelector(Unit* _caster) : caster(_caster) { }

    bool operator() (Unit* unit)
    {
        // Hostile only
        if(!unit->IsHostileTo(caster))
            return true;

        // Area Bind? Not Sure About This
        if(caster->GetAreaId() != unit->GetAreaId())
            return true;

        // Min Distance? How Much?
        return unit->IsWithinDist(caster, 2.5f);
    }

private:
    Unit* caster;
};

class spell_shadow_gale_visual : public SpellScriptLoader
{
    public:
        spell_shadow_gale_visual() : SpellScriptLoader("spell_shadow_gale_visual") { }

        class spell_shadow_gale_visual_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_gale_visual_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetUnit());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadow_gale_visual_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shadow_gale_visual_SpellScript();
        }
};

void AddSC_boss_erudax()
{
    new boss_erudax();
    new mob_faceless();
    new mob_alexstraszas_eggs();
    new spell_shadow_gale_visual();
}
/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010-2011 Project Trinity <http://www.projecttrinity.org/>
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

#include "ScriptMgr.h"
#include "grim_batol.h"

enum Yells
{
    SAY_AGGRO                                 = 0,
    SAY_DEATH                                 = 1,
    SAY_SUMMON                                = 2,
    SAY_SHADOW_GALE                           = 3,
    SAY_GALE                                  = 4,
    EMOTE_KILLED                              = 5,
    SAY_SHADOW_GALE_ANNOUNCE                  = 6,
    SAY_TWILIGHT_CORRUPTION_ANNOUNCE          = 7
};

enum Spells
{
    SPELL_ENFEEBLING_BLOW                     = 75789,
    SPELL_SHADOW_GALE                         = 75664,
    SPELL_SHADOW_GALE_SPEED_TRIGGER           = 75675,
    SPELL_SPAWN_FACELESS                      = 75704,
    SPELL_TWILIGHT_PORTAL_VISUAL              = 95716,
    SPELL_SHIELD_OF_NIGHTMARE                 = 75809,
    SPELL_BINDING_SHADOWS                     = 79466,
    SPELL_UMBRAL_MENDING                      = 79467,
    SPELL_TWILIGHT_CORRUPTION                 = 75520,
    SPELL_SIPHON                              = 75755,
    SPELL_SUMMON_TWILIGHT_HATCHLINGS          = 91058,
    SPELL_SHADOW_GALE_SPEED                   = 75694,
    SPELL_SUMMON_SHADOWGALE_TRIGGER           = 75655
};

enum Events
{
    EVENT_NONE                               = 1,
    EVENT_ENFEEBLING_BLOW                    = 2,
    EVENT_SHADOW_GALE                        = 3,
    EVENT_SUMMON_FACELESS                    = 4,
    EVENT_REMOVE_TWILIGHT_PORTAL             = 5,
    EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY     = 6,
    EVENT_BINDING_SHADOWS                    = 7,
    EVENT_TRIGGER_GALE_CHECK_PLAYERS         = 8,
    EVENT_SIPHON                             = 9,
    EVENT_TARGET_EGG                         = 10,
    EVENT_UMBRAL                             = 11
};

enum Points
{
    POINT_FACELESS_IS_AT_AN_EGG              = 1,
    POINT_ERUDAX_IS_AT_STALKER               = 2
};

enum achievements {
    //    instance->DoCompleteAchievement(
    ACHIEVEMENT_GRIMBATOL                    = 4840,
    ACHIEVEMENT_GRIMBATOL_HEROIC             = 5062,
    ACHIEVEMENT_WITHOUT_CORRUPTION           = 5298,
    ACHIEVEMENT_GRIMBATOL_GUILD_GROUP        = 5138
};


class boss_erudax: public CreatureScript
{
public:
    boss_erudax() : CreatureScript("boss_erudax") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_erudaxAI (creature);
    }

    struct boss_erudaxAI : public ScriptedAI
    {
        boss_erudaxAI(Creature* pCreature) : ScriptedAI(pCreature), ShouldSummonAdds(false)
        {
            pInstance = pCreature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_ID, 79466, true); // Binding Shadows
        }

        void Reset() override
        {
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
            ResetMinions();
            RemoveShadowGaleDebuffFromPlayers();
            if (pInstance)
                pInstance->SetData(DATA_ERUDAX, NOT_STARTED);
            FacelessPortalStalkerGUID = ObjectGuid::Empty;
            isCorruption = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            ShouldSummonAdds = false;
            me->SetReactState(REACT_AGGRESSIVE);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(me->GetVictim());
            events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, 4000);
            events.ScheduleEvent(EVENT_BINDING_SHADOWS, 9000);
            events.ScheduleEvent(EVENT_SHADOW_GALE, 20000);
            Talk(0);
            if (Creature *FacelessPortalStalker = me->SummonCreature(NPC_FACELESS_PORTAL_STALKER, -641.515f, -827.8f, 235.5f, 3.069f, TEMPSUMMON_MANUAL_DESPAWN))
            {
                FacelessPortalStalker->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);
                FacelessPortalStalkerGUID = FacelessPortalStalker->GetGUID();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (ShouldSummonAdds)
            {
                DespawnCreatures(NPC_SHADOW_GALE_STALKER);
                RemoveShadowGaleDebuffFromPlayers();
                me->SetReactState(REACT_AGGRESSIVE);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(me->GetVictim());
                if (rand() % 2)
                    Talk(1);
                if (Creature *FacelessPortalStalker = ObjectAccessor::GetCreature(*me, FacelessPortalStalkerGUID))
                    FacelessPortalStalker->GetAI()->DoCast(FacelessPortalStalker, SPELL_TWILIGHT_PORTAL_VISUAL, true);
                    Talk(SAY_TWILIGHT_CORRUPTION_ANNOUNCE);
                events.ScheduleEvent(EVENT_REMOVE_TWILIGHT_PORTAL, 7000);
                if (Creature *FacelessPortalStalker = ObjectAccessor::GetCreature(*me, FacelessPortalStalkerGUID))
                    FacelessPortalStalker->GetAI()->DoCast(FacelessPortalStalker,SPELL_SPAWN_FACELESS,true);
                ShouldSummonAdds = false;
                events.ScheduleEvent(EVENT_SHADOW_GALE, urand(40000,44000));
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
                    {
                        me->SetReactState(REACT_PASSIVE);
                        Talk(2);
                        Position pos;
                        Position curPos = me->GetPosition();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            curPos = target->GetPosition();
                        pos = me->GetRandomPoint(curPos, 15.0f);
                        me->SummonCreature(40567, pos, TEMPSUMMON_MANUAL_DESPAWN);
                        break;
                    }
                    case EVENT_REMOVE_TWILIGHT_PORTAL:
                        if (Creature *FacelessPortalStalker = ObjectAccessor::GetCreature(*me, FacelessPortalStalkerGUID))
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

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(4);
        }

        virtual void JustReachedHome() override
        {
            ResetMinions();
        }


        void JustDied(Unit* /*killer*/) override
        {
            ResetMinions();
            RemoveShadowGaleDebuffFromPlayers();
            Talk(3);
            if (pInstance)
            {
                pInstance->SetData(DATA_ERUDAX, DONE);
                pInstance->DoCompleteAchievement(ACHIEVEMENT_GRIMBATOL);
                if (IsHeroic())
                {
                    pInstance->DoCompleteAchievement(ACHIEVEMENT_GRIMBATOL_HEROIC);
                    if (!isCorruption)
                        pInstance->DoCompleteAchievement(ACHIEVEMENT_WITHOUT_CORRUPTION);
                    /*if (pInstance->IsInGuildGroup())
                        pInstance->DoCompleteAchievement(ACHIEVEMENT_GRIMBATOL_GUILD_GROUP);*/
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summon->setActive(true);
            switch (summon->GetEntry())
            {
                case NPC_SHADOW_GALE_STALKER:
                    Talk(SAY_SHADOW_GALE_ANNOUNCE);
                    summon->CastSpell(summon, SPELL_SHADOW_GALE_SPEED_TRIGGER, false);
                    me->CastSpell(summon, SPELL_SHADOW_GALE, false);
                    ShouldSummonAdds = true;
                    break;
                default:
                    break;
            }
        }

        bool isCorruption;
    private:
        void ResetMinions()
        {
            DespawnCreatures(NPC_FACELESS);
            DespawnCreatures(NPC_FACELESS_HC);
            DespawnCreatures(NPC_FACELESS_PORTAL_STALKER);
            DespawnCreatures(NPC_TWILIGHT_HATCHLING);
            DespawnCreatures(NPC_SHADOW_GALE_STALKER);
            RespawnEggs();
        }

        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
            if (creatures.empty())
                return;
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        void RespawnEggs()
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, NPC_ALEXSTRASZAS_EGG, 1000.0f);
            if (creatures.empty())
                return;
            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
            {
                if ((*iter)->isDead())
                    (*iter)->Respawn();
                (*iter)->SetHealth(77500);
                (*iter)->SetMaxHealth(77500);
            }
        }

        void RemoveShadowGaleDebuffFromPlayers()
        {
            Map::PlayerList const &PlayerList =  me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    i->GetSource()->RemoveAura(SPELL_SHADOW_GALE_SPEED);
        }

        ObjectGuid FacelessPortalStalkerGUID;
        InstanceScript* pInstance;
        EventMap events;
        bool ShouldSummonAdds;
    };
};

class mob_faceless : public CreatureScript
{
public:
    mob_faceless() : CreatureScript("mob_faceless") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_facelessAI (creature);
    }

    struct mob_facelessAI : public ScriptedAI
    {
        mob_facelessAI(Creature* creature) : ScriptedAI(creature), isAtAnEgg(false), instance(creature->GetInstanceScript())  {}

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            Creature* pTarget = nullptr;
            pTargetGUID = ObjectGuid::Empty;
            pTarget = GetRandomEgg();
            DoZoneInCombat();
            if (me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY, 3000);
            isAtAnEgg = false;
            if (pTarget != NULL)
            {
                me->GetMotionMaster()->MovePoint(POINT_FACELESS_IS_AT_AN_EGG,pTarget->GetPositionX()-4.0f,pTarget->GetPositionY()-4.0f,pTarget->GetPositionZ());
                pTargetGUID = pTarget->GetGUID();
                pTarget->AI()->DoZoneInCombat();
            }
            events.ScheduleEvent(EVENT_TARGET_EGG, 0);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!isAtAnEgg || me->HasUnitState(UNIT_STATE_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TARGET_EGG:
                    {
                        Creature *pTarget = NULL;
                        pTargetGUID = ObjectGuid::Empty;
                        isAtAnEgg = false;
                        pTarget = GetRandomEgg();
                        if (pTarget != NULL)
                        {
                            me->GetMotionMaster()->MovePoint(POINT_FACELESS_IS_AT_AN_EGG,pTarget->GetPositionX()-4.0f,pTarget->GetPositionY()-4.0f,pTarget->GetPositionZ());
                            pTargetGUID = pTarget->GetGUID();
                            pTarget->AI()->DoZoneInCombat();
                        }
                        events.ScheduleEvent(EVENT_TARGET_EGG, 2000);
                        break;
                    }
                    case EVENT_CAST_SHIELD_OF_NIGHTMARE_DELAY:
                    {
                        DoCast(me, SPELL_SHIELD_OF_NIGHTMARE, true);
                        break;
                    }
                    case EVENT_SIPHON:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SIPHON);
                        events.ScheduleEvent(EVENT_SIPHON, urand(9500, 12000));
                        break;
                    }
                    case EVENT_UMBRAL:
                    {
                        if (Unit* pErudax = me->FindNearestCreature(BOSS_ERUDAX,1000.0f, true))
                            DoCast(pErudax, SPELL_UMBRAL_MENDING, false);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case POINT_FACELESS_IS_AT_AN_EGG:
                    {
                        if (instance)
                            if (Creature *c = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ERUDAX)))
                                CAST_AI(boss_erudax::boss_erudaxAI, c->AI())->isCorruption = true;
                        me->CastCustomSpell(SPELL_TWILIGHT_CORRUPTION, SPELLVALUE_MAX_TARGETS, 3, me, false);
                        isAtAnEgg = true;
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                if (victim->GetEntry() == 40486)
                {
                    events.Reset();
                    events.ScheduleEvent(EVENT_SIPHON, 5000);
                    events.ScheduleEvent(EVENT_UMBRAL, 1000);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                }
        }

    private:
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

        ObjectGuid pTargetGUID;
        bool isAtAnEgg;
        EventMap events;
        InstanceScript *instance;
    };
};

class mob_alexstraszas_eggs : public CreatureScript
{
public:
    mob_alexstraszas_eggs() : CreatureScript("mob_alexstraszas_eggs") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_alexstraszas_eggsAI (creature);
    }

    struct mob_alexstraszas_eggsAI : public ScriptedAI
    {
        mob_alexstraszas_eggsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCastAOE(SPELL_SUMMON_TWILIGHT_HATCHLINGS, true);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->setActive(true);
            summon->AI()->DoZoneInCombat();
            if (GetPlayerAtMinimumRange(0))
                summon->Attack(GetPlayerAtMinimumRange(0), true);
        }
    };
};

class DistanceCheck
{
public:
    explicit DistanceCheck(Unit* _caster) : caster(_caster) { }

    bool operator() (WorldObject* unit) const
    {
        if (caster->GetExactDist2d(unit) <= 4.0f || unit->GetGUID() == caster->GetGUID())
            return true;
        return false;
    }

    Unit* caster;
};


class spell_shadow_gale_damage : public SpellScriptLoader
{
public:
    spell_shadow_gale_damage() : SpellScriptLoader("spell_shadow_gale_damage") { }

    class spell_shadow_gale_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadow_gale_damage_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targetList)
        {
            targetList.remove_if(DistanceCheck(GetCaster()));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadow_gale_damage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadow_gale_damage_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadow_gale_damage_SpellScript();
    }
};

void AddSC_boss_erudax()
{
    new boss_erudax();
    new mob_faceless();
    new mob_alexstraszas_eggs();
    new spell_shadow_gale_damage();
}

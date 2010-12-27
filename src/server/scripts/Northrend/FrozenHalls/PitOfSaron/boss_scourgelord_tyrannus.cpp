/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "pit_of_saron.h"

/*
 * TODO:
 *  - Intro/Outro
 *  - improve script of Rimefang
 */

enum Yells
{
    SAY_AMBUSH_1                                = -1658050,
    SAY_AMBUSH_2                                = -1658051,
    SAY_GAUNTLET_START                          = -1658052,
    SAY_INTRO_1                                 = -1658053,
    SAY_INTRO_2                                 = -1658054,

    SAY_AGGRO                                   = -1658055,
    SAY_SLAY_1                                  = -1658056,
    SAY_SLAY_2                                  = -1658057,
    SAY_DEATH                                   = -1658058,
    SAY_MARK_RIMEFANG_1                         = -1658059,
    SAY_MARK_RIMEFANG_2                         = -1658060,
    SAY_DARK_MIGHT_1                            = -1658061,
    SAY_DARK_MIGHT_2                            = -1658062,

    SAY_GORKUN_OUTRO_1                          = -1658063,
    SAY_GORKUN_OUTRO_2                          = -1658064,
    SAY_JAYNA_OUTRO_3                           = -1658065,
    SAY_SYLVANAS_OUTRO_3                        = -1658066,
    SAY_JAYNA_OUTRO_4                           = -1658067,
    SAY_SYLVANAS_OUTRO_4                        = -1658068,
    SAY_JAYNA_OUTRO_5                           = -1658069,
};

enum Spells
{
    SPELL_FORCEFUL_SMASH                        = 69155,
    H_SPELL_FORCEFUL_SMASH                      = 69627,
    SPELL_OVERLORDS_BRAND                       = 69172,
    SPELL_OVERLORD_BRAND_DAMAGE                 = 69189,
    SPELL_OVERLORD_BRAND_HEAL                   = 69190,
    SPELL_DARK_MIGHT                            = 69167,
    H_SPELL_DARK_MIGHT                          = 69629,
    SPELL_HOARFROST                             = 69246,
    SPELL_MARK_OF_RIMEFANG                      = 69275,
    SPELL_ICY_BLAST                             = 69233,
    H_SPELL_ICY_BLAST                           = 69646,
    SPELL_ICY_BLAST_2                           = 69238,
    H_SPELL_ICY_BLAST_2                         = 69628,
};

enum Events
{
    EVENT_NONE,
    EVENT_FORCEFUL_SMASH,
    EVENT_OVERLORDS_BRAND,
    EVENT_DARK_MIGHT,

    // Rimefang
    EVENT_MARK_OF_RIMEFANG,
    EVENT_HOARFROST,
    EVENT_ICY_BLAST,
    EVENT_ICY_BLAST_2,
};

enum Misc
{
    SEAT_TYRANNUS = 0
};

class boss_tyrannus : public CreatureScript
{
public:
    boss_tyrannus() : CreatureScript("boss_tyrannus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_tyrannusAI(pCreature);
    }

    struct boss_tyrannusAI : public ScriptedAI
    {
        boss_tyrannusAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
            events.Reset();

            if (pInstance)
                pInstance->SetData(DATA_TYRANNUS_EVENT, NOT_STARTED);
        }

        Creature* GetRimefang()
        {
            return me->GetCreature(*me, pInstance->GetData64(DATA_RIMEFANG));
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            me->ExitVehicle();

            // restore health if any damage done during intro
            me->SetFullHealth();

            if (pInstance)
                pInstance->SetData(DATA_TYRANNUS_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 10000);
            events.ScheduleEvent(EVENT_OVERLORDS_BRAND, 35000);
            events.ScheduleEvent(EVENT_DARK_MIGHT, 40000);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
            {
                pInstance->SetData(DATA_TYRANNUS_EVENT, DONE);
                if (Creature* pRimefang = GetRimefang())
                    pRimefang->ForcedDespawn();
            }
        }

        void UpdateAI(const uint32 diff)
        {
             //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_FORCEFUL_SMASH:
                        DoCast(me->getVictim(), SPELL_FORCEFUL_SMASH);
                        events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 10000);
                        return;
                    case EVENT_OVERLORDS_BRAND:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_OVERLORDS_BRAND);
                        events.ScheduleEvent(EVENT_OVERLORDS_BRAND, 45000);
                        return;
                    case EVENT_DARK_MIGHT:
                        DoScriptText(SAY_DARK_MIGHT_1, me);
                        DoScriptText(SAY_DARK_MIGHT_2, me);
                        DoCast(me, SPELL_DARK_MIGHT);
                        events.ScheduleEvent(EVENT_DARK_MIGHT, 60000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class boss_rimefang : public CreatureScript
{
public:
    boss_rimefang() : CreatureScript("boss_rimefang") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_rimefangAI(pCreature);
    }

    struct boss_rimefangAI : public ScriptedAI
    {
        boss_rimefangAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            me->InterruptSpell(CURRENT_GENERIC_SPELL);
            me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->InterruptSpell(CURRENT_GENERIC_SPELL);
            me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, 25000);
            events.ScheduleEvent(EVENT_ICY_BLAST, 35000);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_MARK_OF_RIMEFANG:
                        DoScriptText(SAY_MARK_RIMEFANG_1, me);
                        DoScriptText(SAY_MARK_RIMEFANG_2, me);

                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_MARK_OF_RIMEFANG);
                        events.ScheduleEvent(EVENT_HOARFROST, 5000);
                        return;
                    case EVENT_HOARFROST:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_HOARFROST);
                        events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, 20000);
                        return;
                    case EVENT_ICY_BLAST:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_ICY_BLAST);
                        events.ScheduleEvent(EVENT_ICY_BLAST_2, 5000);
                        return;
                    case EVENT_ICY_BLAST_2:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget->getVictim(), SPELL_ICY_BLAST_2);
                        events.ScheduleEvent(EVENT_ICY_BLAST, 30000);
                        return;
                }
            }
        }
    };

};

class player_overlord_brandAI : public PlayerAI
{
    public:
        player_overlord_brandAI(Player* pPlayer) : PlayerAI(pPlayer)
        {
            tyrannus = NULL;
        }

        void SetGUID(const uint64& guid, int32 /*type*/)
        {
            tyrannus = ObjectAccessor::GetCreature(*me, guid);
            if (!tyrannus)
                me->IsAIEnabled = false;
        }

        void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/)
        {
            me->CastCustomSpell(SPELL_OVERLORD_BRAND_DAMAGE, SPELLVALUE_BASE_POINT0, damage, tyrannus->getVictim(), true, NULL, NULL, tyrannus->GetGUID());
        }

        void HealDone(Unit* /*target*/, uint32& addHealth)
        {
            me->CastCustomSpell(SPELL_OVERLORD_BRAND_HEAL, SPELLVALUE_BASE_POINT0, int32(addHealth*5.5f), tyrannus, true, NULL, NULL, tyrannus->GetGUID());
        }

        void UpdateAI(const uint32 /*diff*/) { }

    private:
        Creature* tyrannus;
};

class spell_tyrannus_overlord_brand : public SpellScriptLoader
{
    public:
        spell_tyrannus_overlord_brand() : SpellScriptLoader("spell_tyrannus_overlord_brand") { }

        class spell_tyrannus_overlord_brand_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_tyrannus_overlord_brand_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                oldAI = GetTarget()->GetAI();
                GetTarget()->SetAI(new player_overlord_brandAI(GetTarget()->ToPlayer()));
                GetTarget()->GetAI()->SetGUID(GetCasterGUID());
                oldAIState = GetTarget()->IsAIEnabled;
                GetTarget()->IsAIEnabled = true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                delete GetTarget()->GetAI();
                GetTarget()->SetAI(oldAI);
                GetTarget()->IsAIEnabled = oldAIState;
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_tyrannus_overlord_brand_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_tyrannus_overlord_brand_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            UnitAI* oldAI;
            bool oldAIState;
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_tyrannus_overlord_brand_AuraScript();
        }
};

void AddSC_boss_tyrannus()
{
    new boss_tyrannus();
    new boss_rimefang();
    new spell_tyrannus_overlord_brand();
}

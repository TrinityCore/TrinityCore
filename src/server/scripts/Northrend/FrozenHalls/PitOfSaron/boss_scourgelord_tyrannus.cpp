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

// TODO: Outro, und Raufang zum Fliegen überreden!

enum Yells
{
    SAY_AMBUSH_1            = -1658050,
    SAY_AMBUSH_2            = -1658051,
    SAY_GAUNTLET_START      = -1658052,
    SAY_INTRO_1             = -1658053,
    SAY_INTRO_2             = -1658054,

    SAY_AGGRO               = -1658055,
    SAY_SLAY_1              = -1658056,
    SAY_SLAY_2              = -1658057,
    SAY_DEATH               = -1658058,
    SAY_MARK_RIMEFANG_1     = -1658059,
    SAY_MARK_RIMEFANG_2     = -1658060,
    SAY_DARK_MIGHT_1        = -1658061,
    SAY_DARK_MIGHT_2        = -1658062,

    SAY_GORKUN_OUTRO_1      = -1658063,
    SAY_GORKUN_OUTRO_2      = -1658064,
    SAY_JAYNA_OUTRO_3       = -1658065,
    SAY_SYLVANAS_OUTRO_3    = -1658066,
    SAY_JAYNA_OUTRO_4       = -1658067,
    SAY_SYLVANAS_OUTRO_4    = -1658068,
    SAY_JAYNA_OUTRO_5       = -1658069
};

enum Spells
{
    SPELL_OVERLORDS_BRAND       = 69172,
    SPELL_OVERLORD_BRAND_DAMAGE = 69189,
    SPELL_OVERLORD_BRAND_HEAL   = 69190,
    SPELL_HOARFROST             = 69246,
    SPELL_MARK_OF_RIMEFANG      = 69275,
    SPELL_ICY_BLAST_CAST        = 69232
};

#define SPELL_DARK_MIGHT            DUNGEON_MODE(69167,69629)
#define SPELL_FORCEFUL_SMASH        DUNGEON_MODE(69155,69627)

#define SPELL_ICY_BLAST_EINSCHLAG   DUNGEON_MODE(69233,69646)
#define SPELL_ICY_BLAST_AOE         DUNGEON_MODE(69238,69628)

enum Events
{
    EVENT_NONE,
    EVENT_FORCEFUL_SMASH,
    EVENT_OVERLORDS_BRAND,
    EVENT_DARK_MIGHT,

    // Rimefang
    EVENT_MARK_OF_RIMEFANG,
    EVENT_HOARFROST,
    EVENT_ICY_BLAST_CAST,
    EVENT_ICY_BLAST_EINSCHLAG,
    EVENT_ICY_BLAST_AOE,

    EVENT_INTRO_1,
    EVENT_INTRO_2
};

enum Misc
{
    SEAT_TYRANNUS   = 0,
    NPC_EISIGE_LUFT = 36731
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
            IntroCnt = 0;
            RF = NULL;
        }

        InstanceScript* pInstance;
        EventMap events;
        EventMap eventsI;
        uint8 IntroCnt;
        Creature* RF;

        void Reset()
        {
            events.Reset();
            eventsI.Reset();

            if (pInstance)
            {
                if (!IntroCnt)
                {
                    me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
                    pInstance->SetData(DATA_TYRANNUS_EVENT, NOT_STARTED);
                }
                else
                    pInstance->SetData(DATA_TYRANNUS_EVENT, FAIL);
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who)
                return;

            if (!IntroCnt)
            {
                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (me->IsHostileTo(who) && me->IsWithinDistInMap(who, 60))
                    RunIntro();
            }
            return;
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32& uiDamage)
        {
            if (IntroCnt < 3)
                uiDamage = 0;
        }

        void RunIntro()
        {
            switch(IntroCnt)
            {
                case 0:
                    DoScriptText(SAY_INTRO_1, me);
                    eventsI.ScheduleEvent(EVENT_INTRO_1, 15000);
                    break;
                case 1:
                    DoScriptText(SAY_INTRO_2, me);
                    eventsI.ScheduleEvent(EVENT_INTRO_2, 14000);
                    break;
                case 2:
                    me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->ExitVehicle();
                    break;
            }
            ++IntroCnt;
        }

        Creature* GetRimefang()
        {
            if (!pInstance)
                return NULL;

            return me->GetMap()->GetCreature(pInstance->GetData64(DATA_RIMEFANG));
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_TYRANNUS_EVENT, IN_PROGRESS);

            DoZoneInCombat(me);

            if (IntroCnt > 2)
                DoScriptText(SAY_AGGRO, me);

            events.ScheduleEvent(EVENT_DARK_MIGHT, urand(10000,20000));
            events.ScheduleEvent(EVENT_OVERLORDS_BRAND, urand(5000,10000));
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Creature* pRimefang = GetRimefang())
                pRimefang->ForcedDespawn();

            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_TYRANNUS_EVENT, DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!RF)
                if (RF = GetRimefang())
                    me->EnterVehicle(RF, SEAT_TYRANNUS);

            eventsI.Update(diff);

            if (IntroCnt < 3)
            {
                while (uint32 eventId = eventsI.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_INTRO_1: eventsI.CancelEvent(EVENT_INTRO_1); RunIntro(); break;
                        case EVENT_INTRO_2: eventsI.CancelEvent(EVENT_INTRO_2); RunIntro(); break;
                    }
                }
                return;
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_DARK_MIGHT:
                        DoScriptText(SAY_DARK_MIGHT_1, me);
                        DoScriptText(SAY_DARK_MIGHT_2, me);
                        DoCast(me, SPELL_DARK_MIGHT);
                        events.RescheduleEvent(EVENT_DARK_MIGHT, 50000);
                        events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 5000);
                        break;
                    case EVENT_FORCEFUL_SMASH:
                        DoCastVictim(SPELL_FORCEFUL_SMASH);
                        events.CancelEvent(EVENT_FORCEFUL_SMASH);
                        break;
                    case EVENT_OVERLORDS_BRAND:
                        if (Unit *pTarget = me->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true, -SPELL_OVERLORDS_BRAND))
                            DoCast(pTarget, SPELL_OVERLORDS_BRAND);
                        events.ScheduleEvent(EVENT_OVERLORDS_BRAND, 30000);
                        break;
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
            Tyr = NULL;

            c->m_isCaster;
            c->m_CasterDefaultMaxCombatRange = 199;

            c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            c->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING|MOVEMENTFLAG_SWIMMING);
            c->AddUnitMovementFlag(MOVEMENTFLAG_HOVER|MOVEMENTFLAG_CAN_FLY|MOVEMENTFLAG_FLYING);
        }

        InstanceScript* pInstance;
        EventMap events;
        Creature* Tyr;

        void Reset()
        {
            events.Reset();
        }

        // Er kommt sonst runter zu den Usern, im Kampf! :-(
        // TODO: Muss so geschrieben werden, dass er nur in der Luft bleibt, und fliegt.
        // Bekomme ich im Moment um's Verrecken nicht hin, er geht und steht dumm in der Luft rum. :-(
        void AttackStart(Unit* who)
        {
            if (who && me->Attack(who, true))
                DoStartNoMovement(who);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!who)
                return;

            if (pInstance && pInstance->GetData(DATA_TYRANNUS_EVENT) != IN_PROGRESS)
                return;

            if (me->IsHostileTo(who))
            {
                if (me->IsWithinDistInMap(who, 60))
                    EnterCombat(who);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance && pInstance->GetData(DATA_TYRANNUS_EVENT) != IN_PROGRESS)
                return;

            DoZoneInCombat(me);

            events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, urand(20000,30000));
            events.ScheduleEvent(EVENT_ICY_BLAST_CAST, urand(10000,20000));
        }

        Unit* GetTriggerTarget()
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                Position PosTri;
                pTarget->GetNearPosition(PosTri, 3, float(urand(0,360)));

                if (TempSummon *summ = me->SummonCreature(NPC_EISIGE_LUFT, PosTri, TEMPSUMMON_TIMED_DESPAWN, 60000))
                    return summ;
            }
            return NULL;
        }

        Creature* GetTyrannus()
        {
            if (!pInstance)
                return NULL;

            return me->GetMap()->GetCreature(pInstance->GetData64(DATA_TYRANNUS));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!Tyr)
                Tyr = GetTyrannus();

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
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        {
                            if (Tyr)
                                DoScriptText(SAY_MARK_RIMEFANG_1, Tyr, me);
                            DoScriptText(SAY_MARK_RIMEFANG_2, me, pTarget);
                            DoCast(pTarget, SPELL_MARK_OF_RIMEFANG);
                        }
                        events.CancelEvent(EVENT_MARK_OF_RIMEFANG);
                        events.ScheduleEvent(EVENT_HOARFROST, 5000);
                        break;
                    case EVENT_HOARFROST:
                        if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_HOARFROST);
                        events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, urand(20000,30000));
                        break;
                    case EVENT_ICY_BLAST_CAST:
                        if (Unit *pTarget = GetTriggerTarget())
                            DoCast(pTarget, SPELL_ICY_BLAST_CAST);
                        events.RescheduleEvent(EVENT_ICY_BLAST_CAST, urand(20000,40000));
                        break;
                }
            }
        }
    };

};

class mob_eisige_luft_raufang_icc5 : public CreatureScript
{
public:
    mob_eisige_luft_raufang_icc5() : CreatureScript("mob_eisige_luft_raufang_icc5") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_eisige_luft_raufang_icc5AI(pCreature);
    }

    struct mob_eisige_luft_raufang_icc5AI: public ScriptedAI
    {
        mob_eisige_luft_raufang_icc5AI(Creature *c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_ICY_BLAST_EINSCHLAG, 1800);
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_ICY_BLAST_EINSCHLAG:
                        DoCast(me, SPELL_ICY_BLAST_EINSCHLAG);
                        events.CancelEvent(EVENT_ICY_BLAST_EINSCHLAG);
                        events.ScheduleEvent(EVENT_ICY_BLAST_AOE, 500);
                        break;
                    case EVENT_ICY_BLAST_AOE:
                        DoCast(me, SPELL_ICY_BLAST_AOE, true);
                        events.CancelEvent(EVENT_ICY_BLAST_AOE);
                        break;
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
            tyrannus = me->GetMap()->GetCreature(guid);
            if (!tyrannus)
                me->IsAIEnabled = false;
        }

        void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/)
        {
            if (tyrannus)
                me->CastCustomSpell(SPELL_OVERLORD_BRAND_DAMAGE, SPELLVALUE_BASE_POINT0, damage, tyrannus->getVictim(), true, NULL, NULL, tyrannus->GetGUID());
        }

        void HealDone(Unit* /*target*/, uint32& addHealth)
        {
            if (tyrannus)
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
    new mob_eisige_luft_raufang_icc5();
    new spell_tyrannus_overlord_brand();
}

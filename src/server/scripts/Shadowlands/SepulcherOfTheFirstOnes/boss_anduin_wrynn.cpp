/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "CellImpl.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "G3DPosition.hpp"
#include <G3D/Box.h>
#include <G3D/CoordinateFrame.h>
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "UpdateFields.h"
#include "G3D/Vector2.h"
#include "Unit.h"
#include "sepulcher_of_the_first_ones.h"



enum Spells
{

    // Dark Zeal
    SPELL_DARK_ZEAL_AURA = 364247,
    SPELL_DARK_ZEAL_BUFF = 364248,

    // Hopebreaker
    SPELL_HOPEBREAKER = 361815,
    SPELL_HOPEBREAKER_DAMAGE = 361816,
    SPELL_HOPEBREAKER_DEBUFF = 361817,
    SPELL_HOPEBREAKER_DEBUFF_DAMAGE = 361818,
    SPELL_HOPEBREAKER_CLEAR = 364237,


    //Lost Soul
    SPELL_LOST_SOUL = 362055,

    // Anduin Progression Aura
    SPELL_ANDUIN_PROGRESSION_AURA = 369317,

    //Jaina Spells
    SPELL_BLINK = 362844,
    SPELL_FROST_BOLT = 362843,

    // Uther Spells
    SPELL_BLADE_OF_JUSTICE = 363971,
};

enum Phases
{

};

enum Events
{
    EVENT_DARK_ZEAL = 1,
    EVENT_HOPEBREAKER = 2,
    


};

enum Actions
{

};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_HOPEBREAKER = 1,
    SAY_SLAY = 9,
    SAY_EMPOWERED_HOPEBREAKER = 10,
    SAY_DISENGAGE = 11,
};

enum Conversations
{
    CONVERSATION_INTRO = 17368
};

enum SpawnGroups
{
    SPAWN_GROUP_INITIAL = 0
};

enum Points
{

};

enum SpellVisualKits
{

};

enum SpellVisuals
{

};

enum WorldStates
{

};

enum MiscData // Music
{

};

enum Miscellanea
{

};











// Anduin Wrynn - 181954
struct boss_anduin_wrynn : public BossAI
{
    boss_anduin_wrynn(Creature* creature) : BossAI(creature, DATA_ANDUIN_WRYNN) { }


    void JustAppeared() override
    {
        scheduler.ClearValidator();
        me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        DoCast(me, SPELL_DARK_ZEAL_AURA);

    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_DISENGAGE);

        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPEBREAKER_DEBUFF);



        _DespawnAtEvade();
    }



    void KilledUnit(Unit* victim) override
    {

        Talk(SAY_SLAY);

    }




    void JustEngagedWith(Unit* who) override
    {
        if (!me->HasAura(SPELL_DARK_ZEAL_AURA))
            DoCastSelf(SPELL_DARK_ZEAL_AURA, false);

        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_HOPEBREAKER, 5s);
        



    }

    void UpdateAI(uint32 diff) override
    {

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_HOPEBREAKER:
            {
                DoCast(me, SPELL_HOPEBREAKER);
                Talk(SAY_HOPEBREAKER);
                events.Repeat(24s);
                break;
            }

            {

            }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap events;




};

// Dark Zeal - 364247
class spell_anduin_wrynn_dark_zeal : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_dark_zeal);

    ObjectGuid currentTarget;

    bool Load() override
    {
        currentTarget = ObjectGuid::Empty;
        return true;
    }

    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetActionTarget();

        GetCaster()->CastSpell(GetCaster(), SPELL_DARK_ZEAL_BUFF, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 30000));

        if (!caster || !target)
            return;

        if (target->GetGUID() == currentTarget)
            return;

        PreventDefaultAction();
        caster->RemoveAura(SPELL_DARK_ZEAL_BUFF);
        currentTarget = target->GetGUID();
    }

    void Register() override
    {

        OnEffectProc += AuraEffectProcFn(spell_anduin_wrynn_dark_zeal::OnProc, EFFECT_0, SPELL_AURA_DUMMY);

    }

    AuraScript* GetAuraScript() const
    {
        return new spell_anduin_wrynn_dark_zeal();
    }

};

// Hopebreaker - 361815
class spell_anduin_wrynn_hopebreaker : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_hopebreaker);

    void OnPrecast() override
    {
        GetCaster()->AttackStop();
    }

    void HandleAfterCast()
    {
        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 500.0f);

        for (Player* target : targetList)
        { 
            GetCaster()->CastSpell(target, SPELL_HOPEBREAKER_DAMAGE, true);
            GetCaster()->CastSpell(target, SPELL_HOPEBREAKER_DEBUFF, true);
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_anduin_wrynn_hopebreaker::HandleAfterCast);
    }
};

// Hopebreaker Periodic - 361817
class spell_anduin_wrynn_hopebreaker_periodic : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_hopebreaker_periodic);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        GetCaster()->CastSpell(GetTarget(), SPELL_HOPEBREAKER_DEBUFF_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_hopebreaker_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        
    }
};





void AddSC_boss_anduin_wrynn()
{
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_anduin_wrynn);

    RegisterSpellScript(spell_anduin_wrynn_dark_zeal); 
    RegisterSpellScript(spell_anduin_wrynn_hopebreaker);
    RegisterSpellScript(spell_anduin_wrynn_hopebreaker_periodic);
}

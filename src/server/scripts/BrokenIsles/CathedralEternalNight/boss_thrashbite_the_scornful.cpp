/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "cathedral_of_eternal_night.h"
#include "GameObject.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "MotionMaster.h"


enum Says
{
    SAY_AGGRO           = 0,
    SAY_PULVERISING     = 1,
    SAY_SCORNFUL        = 2,
    SAY_SCORNFUL_DMG    = 3,
    SAY_DEATH           = 4,
};

enum Spells
{
    SPELL_PULVERIZING_CUDGEL                = 237276,  // 5 + 27
    SPELL_HEAVE_CUDGEL                      = 243124, // 15 (7) + 38 + summon + 243158
    SPELL_SCORNFUL_GAZE                     = 237726,  //  27 + repeat 
    SPELL_SCORNFUL_GAZE_DMG                 = 238469,  
    SPELL_SCORNFUL_GAZE_STUN                = 240547, 
    
    // mythic summon book
};

enum eEvents
{
    EVENT_PULVERIZING_CUDGEL = 1,
    EVENT_HEAVE_CUDGEL,
    EVENT_SCORNFUL_GAZE,
    EVENT_SCORNFUL_DMG,
    EVENT_SCORNFUL_STUN
};

enum BooksNpc
{
    NPC_FICTIONAL_BOOK                      = 121384,
    NPC_SATIRICAL_BOOK                      = 121364,
    NPC_BIOGRAPHICAL_BOOK                   = 121392,
};


std::map<uint32, uint32> npc_books = 
{
    {0, NPC_FICTIONAL_BOOK},
    {1, NPC_SATIRICAL_BOOK},
    {2, NPC_BIOGRAPHICAL_BOOK}
};

// 117194
class boss_thrashbite_the_scornful : public CreatureScript
{
public:
    boss_thrashbite_the_scornful() : CreatureScript("boss_thrashbite_the_scornful") {}

    struct boss_thrashbite_the_scornfulAI : public BossAI
    {
        boss_thrashbite_the_scornfulAI(Creature* creature) : BossAI(creature, DATA_THRASHBITE) 
        {
          //  me->AddDelayedEvent(3000, [this] () -> void
           // {
                bool canVisible = false;
                if (Creature* gazzerax = instance->instance->GetCreature(instance->GetGuidData(NPC_GAZERAX)))
                {
                    if (!gazzerax->IsAlive())
                        canVisible = true;
                }
                else
                    canVisible = true;
                
                if (canVisible)
                {
                 //   me->AddDelayedEvent(1000, [this] () -> void { 
                    
                        me->SetVisible(true);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));
                        me->SetReactState(REACT_DEFENSIVE);
                  //  });
                }
          //  });
                
        }

        void Reset() override
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            events.RescheduleEvent(EVENT_PULVERIZING_CUDGEL, 5000);
            events.RescheduleEvent(EVENT_HEAVE_CUDGEL, 14000);
            events.RescheduleEvent(EVENT_SCORNFUL_GAZE, 29000);
        }


        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE || !id)
                return;
            
            events.DelayEvents(1000);

            if (id == 1)
                events.RescheduleEvent(EVENT_SCORNFUL_DMG, 10);
            else
                events.RescheduleEvent(EVENT_SCORNFUL_STUN, 10);
        }
        
        void JustSummoned(Creature* summon) override
        {            
            summons.Summon(summon);
            
            if (summon->GetEntry() == 121710)
            {
                summon->SetReactState(REACT_PASSIVE);
               // me->CastSpellDuration(me, 243158, true, 12000, 1);
                summon->NearTeleportTo(-573.15f, 2526.32f, 439.68f, 6.27f);
                summon->CastSpell(summon, 240948);
                summon->GetMotionMaster()->MovePath(387381, false);
                return;
            }
            
            DoZoneInCombat(summon, 150.0f);
        }
        
        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasAura(SPELL_SCORNFUL_GAZE_STUN))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_PULVERIZING_CUDGEL:
                        Talk(SAY_PULVERISING);
                        DoCast(SPELL_PULVERIZING_CUDGEL);
                        events.RescheduleEvent(EVENT_PULVERIZING_CUDGEL, 34000);
                        break;
                    case EVENT_HEAVE_CUDGEL:
                        DoCast(SPELL_HEAVE_CUDGEL);
                        events.RescheduleEvent(EVENT_HEAVE_CUDGEL, 36000);
                        break;
                    case EVENT_SCORNFUL_GAZE:
                        Talk(SAY_SCORNFUL);
                         if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(SPELL_SCORNFUL_GAZE);
                        events.RescheduleEvent(EVENT_SCORNFUL_GAZE, 36000);
                        events.DelayEvents(1000);
                        break;
                    case EVENT_SCORNFUL_DMG:
                        Talk(SAY_SCORNFUL_DMG);
                        DoCast(SPELL_SCORNFUL_GAZE_DMG);
                        break;
                    case EVENT_SCORNFUL_STUN:
                        DoCast(SPELL_SCORNFUL_GAZE_STUN);
                        
                        // ???? ???????? =P
                        std::list<GameObject*> gobs;
                        GetGameObjectListWithEntryInGrid(gobs, me, GO_THRASHBITE_BOOKCASE_1, 5.0f);
                        GetGameObjectListWithEntryInGrid(gobs, me, GO_THRASHBITE_BOOKCASE_2, 5.0f);
                        GetGameObjectListWithEntryInGrid(gobs, me, GO_THRASHBITE_BOOKCASE_3, 5.0f);
                        GetGameObjectListWithEntryInGrid(gobs, me, GO_THRASHBITE_BOOKCASE_4, 5.0f);

                        if (!gobs.empty())
                        {
                            GameObject* select = nullptr;
                            for (std::list<GameObject*>::iterator itr = gobs.begin(); itr != gobs.end(); ++itr)
                            {
                                if ((!select || me->GetDistance2d(*itr) < me->GetDistance2d(select))  && (*itr)->GetGoState() != GO_STATE_ACTIVE)
                                    select = *itr;
                            }
                            
                            if (select)
                                select->SetGoState(GO_STATE_ACTIVE);
                        }
                        
                        if (Difficulty() != DIFFICULTY_HEROIC)
                        {
                            std::map<uint32, uint32> temp_npc_books = {npc_books };
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                uint32 entry = temp_npc_books[urand(0, temp_npc_books.size())];
                                me->SummonCreature(entry, me->GetPositionX() + frand(-5, 5), me->GetPositionY() + frand(-5, 5), me->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                                
                                auto itr = temp_npc_books.find(entry);
                                if (itr != temp_npc_books.end())
                                    temp_npc_books.erase(itr);
                            }
                        }
                        
                        break;
                    
                }
            }
            DoMeleeAttackIfReady();
        }
       

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_thrashbite_the_scornfulAI (creature);
    }
};

// 237726
class spell_coen_scornful_gaze : public SpellScriptLoader
{
    public:
        spell_coen_scornful_gaze() : SpellScriptLoader("spell_coen_scornful_gaze") { }

        class spell_coen_scornful_gaze_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_coen_scornful_gaze_AuraScript);

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;
                
                Unit* caster = GetCaster();
                if (!caster || caster->isDead() || !caster->IsInCombat())
                    return;

                Unit* target = GetTarget();
                if (!target || target->isDead())
                    return;
             
                std::list<GameObject*> gobs;
                GetGameObjectListWithEntryInGrid(gobs, caster, GO_THRASHBITE_BOOKCASE_1, caster->GetDistance2d(target));
                GetGameObjectListWithEntryInGrid(gobs, caster, GO_THRASHBITE_BOOKCASE_2, caster->GetDistance2d(target));
                GetGameObjectListWithEntryInGrid(gobs, caster, GO_THRASHBITE_BOOKCASE_3, caster->GetDistance2d(target));
                GetGameObjectListWithEntryInGrid(gobs, caster, GO_THRASHBITE_BOOKCASE_4, caster->GetDistance2d(target));
                
                WorldObject* select = target;
                
                if (!gobs.empty())
                    for (std::list<GameObject*>::iterator itr = gobs.begin(); itr != gobs.end(); ++itr)
                       // if ((!select || caster->GetDistance2d(*itr) < caster->GetDistance2d(select)) && (*itr)->IsInBetween(caster, target->GetPositionX(), target->GetPositionY(), 9.0f)  && (*itr)->GetGoState() != GO_STATE_ACTIVE)
                      //      select = (*itr);
                        
                std::list<Player*> players;
               // GetPlayerListInGrid(players, caster, caster->GetDistance2d(target));
               
                
               // if (!players.empty())
                   // for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                        //if ((!select || caster->GetDistance2d(*itr) < caster->GetDistance2d(select)) && (*itr)->IsInBetween(caster, target->GetPositionX(), target->GetPositionY(), 9.0f))
                       //     select = (*itr);
                        
                if (!select)
                    return;
                
               // caster->GetMotionMaster()->MoveCharge(select->GetPosition(), SPEED_CHARGE, select->IsPlayer() ? 1 : 2);
            }


            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_coen_scornful_gaze_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_coen_scornful_gaze_AuraScript();
        }
};

// 238484
class spell_coen_beguiling_bio : public SpellScriptLoader
{
    public:                                                      
        spell_coen_beguiling_bio() : SpellScriptLoader("spell_coen_beguiling_bio") { }


        class spell_coen_beguiling_bio_AuraScript : public AuraScript 
        {
            PrepareAuraScript(spell_coen_beguiling_bio_AuraScript);

            void OnPereodic(AuraEffect const* /*aurEff*/) 
            {
                if (Unit* target = GetTarget())
                    if (target->GetHealthPct() <= 30)
                        target->RemoveAurasDueToSpell(238484);
            }

            void Register() 
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_coen_beguiling_bio_AuraScript::OnPereodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_coen_beguiling_bio_AuraScript();
        }
};

enum MobSpells
{
    SPELL_BLINDING_GLARE = 239232,
    SPELL_FEL_GLARE = 239201,
    SPELL_FOCUSED_DESTRUCTION = 239235,
};
struct npc_gazerax_118723 : public ScriptedAI
{
    npc_gazerax_118723(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* target = instance->GetCreature(NPC_THRASHBITE_THE_SCORNFUL))
            target->AI()->DoAction(1);
    }

    void EnterCombat(Unit* /*victim*/) override
    {
        events.ScheduleEvent(SPELL_BLINDING_GLARE, 5000);
        events.ScheduleEvent(SPELL_FEL_GLARE, 5000);
        events.ScheduleEvent(SPELL_FOCUSED_DESTRUCTION, 5000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_BLINDING_GLARE:
            {
                DoCast(SPELL_BLINDING_GLARE);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_FEL_GLARE:
            {
                DoCast(SPELL_FEL_GLARE);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_FOCUSED_DESTRUCTION:
            {
                DoCast(SPELL_FOCUSED_DESTRUCTION);
                events.Repeat(5s, 10s);
                break;
            }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }
private:
    InstanceScript* instance;
};

void AddSC_boss_thrashbite_the_scornful()
{
    new boss_thrashbite_the_scornful();
    RegisterCreatureAI(npc_gazerax_118723);
    new spell_coen_scornful_gaze();
    new spell_coen_beguiling_bio();
}

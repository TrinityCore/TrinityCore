///*
//* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
//* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "siege_of_the_niuzoa_temple.h"
//
//enum spells
//{
//    MALLEABLE_RESIN = 121421,
//    RESIN_WEAVING = 121114,
//    ENCASED_IN_RESIN = 121116,
//    RESIN_SHELL = 120946,
//    RESIDUE = 120938,
//};
//
//enum Events
//{
//    EVENT_CAST_BUFF_RESIN = 0,
//    EVENT_DECAST_BUFF_RESIN = 1,
//    EVENT_RESIN_CAST = 2,
//    EVENT_RESIN_WEAVER = 3,
//    EVENT_PHASE_RESIN = 4,
//    EVENT_COOLDOWN = 5,
//    EVENT_HIT = 6,
//};
//
//class mob_sikthik_guardian : public CreatureScript
//{
//public:
//    mob_sikthik_guardian() : CreatureScript("mob_sikthik_guardian") {}
//
//    struct mob_sikthik_guardianAI : public ScriptedAI
//    {
//        mob_sikthik_guardianAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (IsHeroic())
//            {
//                me->SetMaxHealth(1222596);
//                me->SetHealth(1222596);
//            }
//            else
//            {
//                me->SetMaxHealth(984852);
//                me->SetHealth(984852);
//            }
//            // hardened reisin
//            if (!me->FindNearestGameObject(213174, 600.0f))
//                if (Creature* Boss = me->FindNearestCreature(61567, 300))
//                    if (Boss->isAlive())
//                        me->SummonGameObject(213174, 1529.017090f, 5242.277344f, 190.664276f, 1.541654f, 0, 0, 0, 0, 0, 0);
//            // gong
//            if (!me->FindNearestGameObject(209626, 600.0f))
//                if (Creature* Boss = me->FindNearestCreature(61567, 300))
//                    if (Boss->isAlive())
//                        me->SummonGameObject(209626, 1536.709961f, 5285.120117f, 185.223999f, 4.709950f, 0, 0, 0, 0, 0, 0);
//
//            // pavalak door
//            if (!me->FindNearestGameObject(213286, 600.0f))
//                if (Creature* Boss = me->FindNearestCreature(61567, 300))
//                    if (Boss->isAlive())
//                        me->SummonGameObject(213286, 1623.802002f, 5404.150879f, 138.700287f, 6.088324f, 0, 0, 0, 0, 0, 0);
//        }
//
//        uint32 malleableResinTimer;
//        uint32 stuckinresinTimer;
//
//        void Reset()
//        {
//            malleableResinTimer = urand(5000, 8000);
//            stuckinresinTimer = urand(16000, 25000);
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//            if (malleableResinTimer <= diff)
//            {
//                if (Unit* target = me->SelectNearestTarget(5.0f))
//                    if (!target->IsFriendlyTo(me))
//                        me->CastSpell(target, MALLEABLE_RESIN, true);
//                malleableResinTimer = urand(8000, 12000);
//            }
//            else
//                malleableResinTimer -= diff;
//
//            if (stuckinresinTimer <= diff)
//            {
//                if (Unit* target = me->SelectNearestTarget(5.0f))
//                    if (!target->IsFriendlyTo(me))
//                        me->CastSpell(target, ENCASED_IN_RESIN, true);
//                stuckinresinTimer = urand(16000, 25000);
//            }
//            else
//                stuckinresinTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_sikthik_guardianAI(creature);
//    }
//};
//
//class mob_resin_flake : public CreatureScript
//{
//public:
//    mob_resin_flake() : CreatureScript("mob_resin_flake") {}
//
//    struct mob_resin_flakeAI : public ScriptedAI
//    {
//        mob_resin_flakeAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (IsHeroic())
//            {
//                me->SetMaxHealth(611298);
//                me->SetHealth(611298);
//            }
//            else
//            {
//                me->SetMaxHealth(393941);
//                me->SetHealth(393941);
//            }
//        }
//
//
//        void JustDied(Unit* killer)
//        {
//            if (me && me->IsInWorld() && killer && killer->IsInWorld() && killer->GetTypeId() == TYPEID_PLAYER)
//            {
//                me->DealDamage(killer, 4500);
//
//                if (!killer->HasAura(120938))
//                {
//                    me->AddAura(120938, killer);
//                }
//                else if (killer->HasAura(120938))
//                {
//                    if (killer->IsHostileTo(me))
//                    {
//                        killer->SetAuraStack(120938, killer, killer->GetAura(120938)->GetStackAmount() + 1);
//                    }
//                }
//            }
//
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_resin_flakeAI(creature);
//    }
//};
//class spell_resin_weaving : public SpellScriptLoader
//{
//public:
//    spell_resin_weaving() : SpellScriptLoader("spell_resin_weaving") { }
//
//    class spell_resin_weaving_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_resin_weaving_AuraScript);
//
//        void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (Unit* caster = GetCaster())
//            {
//                if (Unit* target = GetTarget())
//                {
//                    AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
//                    if (removeMode == AURA_REMOVE_BY_EXPIRE)
//                        caster->CastSpell(target, ENCASED_IN_RESIN, true);
//                }
//            }
//        }
//        void Register()
//        {
//            OnEffectRemove += AuraEffectRemoveFn(spell_resin_weaving_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const
//    {
//        return new spell_resin_weaving_AuraScript();
//    }
//};
//class mob_sikthik_amber_weaver : public CreatureScript
//{
//public:
//    mob_sikthik_amber_weaver() : CreatureScript("mob_sikthik_amber_weaver") {}
//
//    struct mob_sikthik_amber_weaverAI : public ScriptedAI
//    {
//        mob_sikthik_amber_weaverAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (IsHeroic())
//            {
//                me->SetMaxHealth(1222596);
//                me->SetHealth(1222596);
//            }
//            else
//            {
//                me->SetMaxHealth(984852);
//                me->SetHealth(984852);
//            }
//        }
//
//        uint32 resinWeavingTimer;
//        uint32 resinShellTimer;
//        bool resinShellOnlyOne;
//
//        void Reset()
//        {
//            resinWeavingTimer = urand(10000, 12000);
//            resinShellTimer = urand(8000, 15000);
//            resinShellOnlyOne = true;
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//            if (resinWeavingTimer <= diff)
//            {
//                if (Unit* target = me->SelectNearestTarget(5.0f))
//                    if (!target->IsFriendlyTo(me))
//                        me->CastSpell(target, RESIN_WEAVING, true);
//                resinWeavingTimer = urand(10000, 12000);
//            }
//            else
//                resinWeavingTimer -= diff;
//
//            if (resinShellTimer <= diff && resinShellOnlyOne == true)
//            {
//                if (Unit* target = me->SelectNearestTarget(5.0f))
//                {
//                    me->CastSpell(me, RESIN_SHELL, true);
//                    resinShellOnlyOne = false;
//                }
//            }
//            else
//                resinShellTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new mob_sikthik_amber_weaverAI(creature);
//    }
//};
//class Resin_Trigger : public CreatureScript
//{
//public:
//    Resin_Trigger() : CreatureScript("Resin_Trigger") { }
//
//    struct Resin_Trigger_AI : public CreatureAI
//    {
//        Resin_Trigger_AI(Creature* creature) : CreatureAI(creature)
//        {
//            me->AddExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);
//        }
//        void Reset()
//        {
//            events.Reset();
//            events.ScheduleEvent(EVENT_CAST_BUFF_RESIN, 100);
//            events.ScheduleEvent(EVENT_DECAST_BUFF_RESIN, 9600);
//        }
//        void UpdateAI(uint32 const diff)
//        {
//            events.Update(diff);
//            std::list<Unit*> tempList;
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_CAST_BUFF_RESIN:
//                {
//                    if (TempSummon* summon = me->ToTempSummon())
//                    {
//                        if (!summon->GetSummoner())
//                            return;
//
//                        if (Creature* creature = summon->GetSummoner()->ToCreature())
//                        {
//                            JadeCore::AnyCreatureInObjectRangeCheck check(me, 2.0f);
//                            JadeCore::UnitListSearcher<JadeCore::AnyCreatureInObjectRangeCheck> searcher(me, tempList, check);
//                            me->VisitNearbyObject(2.0f, searcher);
//
//                            for (std::list<Unit*>::const_iterator it = tempList.begin(); it != tempList.end(); ++it)
//                            {
//                                if (!(*it))
//                                    continue;
//
//                                if (!me->IsFriendlyTo(*it))
//                                    continue;
//
//                                if (me->IsWithinDistInMap((*it), 2.0f, true))
//                                {
//                                    if (!(*it)->HasAura(120955))
//                                    {
//                                        me->AddAura(120955, (*it));
//                                    }
//
//                                    if ((*it)->HasAura(120955))
//                                    {
//                                        if (AuraPtr aura = (*it)->GetAura(120955, me->GetGUID()))
//                                        {
//                                            aura->SetMaxDuration(200);
//                                            aura->SetDuration(200);
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                    break;
//                }
//                case EVENT_DECAST_BUFF_RESIN:
//                {
//                    for (std::list<Unit*>::const_iterator it = tempList.begin(); it != tempList.end(); ++it)
//                    {
//                        if (!(*it))
//                            continue;
//
//                        if (!(*it)->isAlive())
//                            continue;
//
//                        // remove aura
//                        (*it)->RemoveAura(120955, me->GetGUID());
//                    }
//                    break;
//                }
//                }
//            }
//        }
//    private:
//        EventMap events;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Resin_Trigger_AI(creature);
//    }
//
//};
//class Resin_Traps : public CreatureScript
//{
//public:
//    Resin_Traps() : CreatureScript("Resin_Traps") { }
//
//    struct Resin_Trigger_AI : public CreatureAI
//    {
//        Resin_Trigger_AI(Creature* creature) : CreatureAI(creature)
//        {
//            me->AddExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);
//
//            /*
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
//            */
//
//            if (me->GetEntry() == 457851)
//                me->SetObjectScale(0.5);
//            else
//                me->SetObjectScale(1.0);
//        }
//        bool Used;
//
//        void Reset()
//        {
//            Used = false;
//            events.Reset();
//            me->CastSpell(me, 120591);
//            if (me->GetEntry() == 457851)
//                events.ScheduleEvent(EVENT_PHASE_RESIN, urand(5000, 5000));
//        }
//        void UpdateAI(uint32 const diff)
//        {
//            events.Update(diff);
//
//            if (me->GetEntry() == 457851)
//            {
//                if (Player* pl = me->SelectNearestPlayer(1.0))
//                {
//                    if (pl->IsWithinDistInMap(me, 1.0f, true) && !Used)
//                    {
//                        bool Used = true;
//                        events.ScheduleEvent(EVENT_COOLDOWN, 1000);
//                        events.ScheduleEvent(EVENT_HIT, 100);
//                    }
//                }
//            }
//            else
//            {
//                std::list<Creature*> list_p;
//                JadeCore::AnyCreatureInObjectRangeCheck check(me, 2.0f);
//                JadeCore::CreatureListSearcher<JadeCore::AnyCreatureInObjectRangeCheck> searcher(me, list_p, check);
//                me->VisitNearbyObject(2.0, searcher);
//
//                for (std::list<Creature*>::const_iterator itr = list_p.begin(); itr != list_p.end(); itr++)
//                {
//                    if ((*itr)->IsWithinDistInMap(me, 2.0f, true) && (*itr)->getFaction() != 35)
//                    {
//                        (*itr)->AddAura(120269, (*itr));
//                    }
//                }
//            }
//            if (!me->HasAura(120591))
//            {
//                me->CastSpell(me, 120591);
//            }
//
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_COOLDOWN:
//                    Used = false;
//                    break;
//                case EVENT_PHASE_RESIN:
//                    if (me->GetPhaseMask() == 1)
//                    {
//                        me->SetPhaseMask(6, true);
//                    }
//                    else if (me->GetPhaseMask() == 6)
//                    {
//                        me->SetPhaseMask(1, true);
//                    }
//                    events.ScheduleEvent(EVENT_PHASE_RESIN, urand(7000, 7000));
//                    break;
//                case EVENT_HIT:
//                    if (me->GetEntry() == 457851)
//                    {
//                        if (Player* pl = me->SelectNearestPlayer(1.0))
//                        {
//                            if (pl->IsWithinDistInMap(me, 1.0f, true) && !Used)
//                            {
//                                me->AddAura(120593, pl);
//                            }
//                        }
//                    }
//                    else
//                    {
//                        if (Unit* pl = me->SelectNearestTarget(1.0))
//                        {
//                            if (pl->IsWithinDistInMap(me, 1.0f, true) && !Used && pl->GetTypeId() != TYPEID_PLAYER)
//                            {
//                                pl->AddAura(120269, pl);
//                            }
//                        }
//                    }
//                    break;
//                }
//            }
//        }
//    private:
//        EventMap events;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Resin_Trigger_AI(creature);
//    }
//
//};
//class residue_after_damage : public SpellScriptLoader
//{
//public:
//    residue_after_damage() : SpellScriptLoader("residue_after_damage") { }
//
//    class residue_after_damagespellscript : public SpellScript
//    {
//        PrepareSpellScript(residue_after_damagespellscript);
//
//        void HandleAfterHit()
//        {
//            if (GetCaster())
//            {
//                if (GetHitUnit())
//                {
//                    if (Unit* target = GetHitUnit())
//                    {
//                        GetCaster()->DealDamage(target, urand(4500, 5000));
//                    }
//                }
//            }
//        }
//
//        void Register()
//        {
//            AfterHit += SpellHitFn(residue_after_damagespellscript::HandleAfterHit);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new residue_after_damagespellscript();
//    }
//};
//
//class quest_shado_pan_prisoner : public CreatureScript
//{
//public:
//    quest_shado_pan_prisoner() : CreatureScript("quest_shado_pan_prisoner") {}
//
//    struct quest_shado_pan_prisonerAI : public ScriptedAI
//    {
//        quest_shado_pan_prisonerAI(Creature* creature) : ScriptedAI(creature)
//        {
//        }
//        bool CanWP;
//        bool HasWP;
//
//        void Reset()
//        {
//            me->setFaction(35);
//            me->SetReactState(REACT_PASSIVE);
//            me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
//
//            CanWP = false;
//            HasWP = false;
//            if (!me->FindNearestGameObject(214734, 2.0f))
//            {
//                me->SummonGameObject(214734, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), 0, 0, 0, 0, 0, 0);
//            }
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            events.Update(diff);
//
//
//            if (CanWP)
//            {
//                std::list<Player*> PL_list;
//
//                JadeCore::AnyPlayerInObjectRangeCheck check(me, 30.0f);
//                JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//                me->VisitNearbyObject(30.0f, searcher);
//
//                for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//                {
//                    if (!(*it))
//                        return;
//
//                    (*it)->KilledMonsterCredit(64520);
//                }
//                CanWP = false;
//                me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
//                if (!HasWP)
//                {
//                    HasWP = true;
//
//                    if (MotionMaster* motion = me->GetMotionMaster())
//                    {
//                        if (Player* nearest = me->SelectNearestPlayer(8.0f))
//                        {
//                            motion->MovePoint(1, nearest->GetPositionX(), nearest->GetPositionY(), nearest->GetPositionZ());
//
//                            if (GameObject* cage = me->FindNearestGameObject(214734, 7.0f))
//                            {
//                                cage->Delete();
//                                me->DespawnOrUnsummon(1000);
//                            }
//                        }
//                    }
//                }
//            }
//
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new quest_shado_pan_prisonerAI(creature);
//    }
//};
//class Sikthik_cage : public GameObjectScript
//{
//public:
//    Sikthik_cage() : GameObjectScript("Sikthik_cage") { }
//
//    void OnGameObjectStateChanged(GameObject* go, uint32 state)
//    {
//        if (Creature* ShadoPanPrisoner = go->FindNearestCreature(64520, 5.0f, true))
//        {
//            if (quest_shado_pan_prisoner::quest_shado_pan_prisonerAI* linkAI = CAST_AI(quest_shado_pan_prisoner::quest_shado_pan_prisonerAI, ShadoPanPrisoner->GetAI()))
//            {
//                if (!linkAI->CanWP)
//                {
//                    linkAI->CanWP = true;
//                }
//            }
//        }
//    }
//};
//
//void AddSC_siege_of_the_niuzoa_temple()
//{
//    new Sikthik_cage();
//    new quest_shado_pan_prisoner();
//    new Resin_Traps();
//    new residue_after_damage();
//    new mob_sikthik_amber_weaver();
//    new Resin_Trigger();
//    new mob_sikthik_guardian();
//    new mob_resin_flake();
//    new spell_resin_weaving();
//}

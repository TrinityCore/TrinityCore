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
#include "utgarde_pinnacle.h"

enum Spells
{
    SPELL_SVALA_TRANSFORMING1                     = 54140,
    SPELL_SVALA_TRANSFORMING2                     = 54205,
    SPELL_TRANSFORMING_CHANNEL                    = 54142,

    SPELL_CALL_FLAMES                             = 48258, // caster effect only, triggers event 17841
    SPELL_SINSTER_STRIKE                          = 15667,
    H_SPELL_SINSTER_STRIKE                        = 59409,

    SPELL_RITUAL_PREPARATION                      = 48267,
    SPELL_RITUAL_OF_THE_SWORD                     = 48276,
    SPELL_RITUAL_STRIKE_TRIGGER                   = 48331, // triggers 48277 & 59930, needs NPC_RITUAL_TARGET as spell_script_target
    SPELL_RITUAL_DISARM                           = 54159,
    SPELL_RITUAL_STRIKE_EFF_1                     = 48277,
    SPELL_RITUAL_STRIKE_EFF_2                     = 59930,
    
    SPELL_SUMMONED_VIS                            = 64446,
    SPELL_RITUAL_CHANNELER_1                      = 48271,
    SPELL_RITUAL_CHANNELER_2                      = 48274,
    SPELL_RITUAL_CHANNELER_3                      = 48275,

    // Ritual Channeler spells
    SPELL_PARALYZE                                = 48278,
    SPELL_SHADOWS_IN_THE_DARK                     = 59407,

    // Scourge Hulk spells
    SPELL_MIGHTY_BLOW                             = 48697,
    SPELL_VOLATILE_INFECTION                      = 56785,
    H_SPELL_VOLATILE_INFECTION                    = 59228
};

enum Yells
{
    // Svala
    SAY_SVALA_INTRO_0                             = 0,

    // Svala Sorrowgrave
    SAY_SVALA_INTRO_1                             = 0,
    SAY_SVALA_INTRO_2                             = 1,
    SAY_AGGRO                                     = 2,
    SAY_SLAY                                      = 3,
    SAY_DEATH                                     = 4,
    SAY_SACRIFICE_PLAYER                          = 5,
    
    // Image of Arthas
    SAY_DIALOG_OF_ARTHAS_1                        = 0,
    SAY_DIALOG_OF_ARTHAS_2                        = 1
};

enum Creatures
{
    CREATURE_ARTHAS                               = 29280, // Image of Arthas
    CREATURE_SVALA_SORROWGRAVE                    = 26668, // Svala after transformation
    CREATURE_SVALA                                = 29281, // Svala before transformation
    CREATURE_RITUAL_CHANNELER                     = 27281,
    CREATURE_SPECTATOR                            = 26667,
    CREATURE_RITUAL_TARGET                        = 27327,
    CREATURE_FLAME_BRAZIER                        = 27273,
    CREATURE_SCOURGE_HULK                         = 26555
};

enum Objects
{
    OBJECT_UTGARDE_MIRROR                         = 191745
};

enum SvalaPhase
{
    IDLE,
    INTRO,
    NORMAL,
    SACRIFICING,
    SVALADEAD
};

#define DATA_INCREDIBLE_HULK 2043

static const float spectatorWP[2][3] = 
{
    {296.95f,-312.76f,86.36f},
    {297.69f,-275.81f,86.36f}
};

static Position ArthasPos = { 295.81f, -366.16f, 92.57f, 1.58f };

class boss_svala : public CreatureScript
{
public:
    boss_svala() : CreatureScript("boss_svala") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_svalaAI (creature);
    }

    struct boss_svalaAI : public ScriptedAI
    {
        boss_svalaAI(Creature* creature) : ScriptedAI(creature), summons(creature)
        {
            instance = creature->GetInstanceScript();
            Phase = IDLE;

            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RITUAL_STRIKE_EFF_1, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_RITUAL_STRIKE_EFF_2, true);
        }

        InstanceScript* instance;
        SummonList summons;
        SvalaPhase Phase;
        
        Position pos;
        float x, y, z;

        uint32 introTimer;
        uint8 introPhase;
        uint8 sacrePhase;

        TempSummon* arthas;
        uint64 arthasGUID;

        uint32 sinsterStrikeTimer;
        uint32 callFlamesTimer;
        uint32 sacrificeTimer;

        bool sacrificed;

        void Reset()
        {
            sacrificed = false;
            SetCombatMovement(true);

            summons.DespawnAll();
            me->RemoveAllAuras();
            
            if (Phase > INTRO)
            {
                me->SetFlying(true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            }

            if (Phase > NORMAL)
                Phase = NORMAL;

            introTimer = 1 * IN_MILLISECONDS;
            introPhase = 0;
            arthasGUID = 0;

            if (instance)
            {
                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, NOT_STARTED);
                instance->SetData64(DATA_SACRIFICED_PLAYER, 0);
            }
        }
        
        void JustReachedHome()
        {
            if (Phase > INTRO)
            {
                me->SetFlying(false);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->SetOrientation(1.58f);
                me->SendMovementFlagUpdate();
            }
        }
        
        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            
            sinsterStrikeTimer = 7 * IN_MILLISECONDS;
            callFlamesTimer = urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);

            if (instance)
                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, IN_PROGRESS);
        }
        
        void JustSummoned(Creature* summon)
        {
            if (summon->GetEntry() == CREATURE_RITUAL_CHANNELER)
                summon->CastSpell(summon, SPELL_SUMMONED_VIS, true);
            
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            summons.Despawn(summon);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;

            if (Phase == IDLE && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 40))
            {
                Phase = INTRO;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                
                if (GameObject* mirror = GetClosestGameObjectWithEntry(me, OBJECT_UTGARDE_MIRROR, 100.0f))
                    mirror->SetGoState(GO_STATE_READY);

                if (Creature* arthas = me->SummonCreature(CREATURE_ARTHAS, ArthasPos, TEMPSUMMON_MANUAL_DESPAWN))
                {
                    arthas->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    arthasGUID = arthas->GetGUID();
                }
            }
        }
        
        void KilledUnit(Unit* victim)
        {
            if (victim != me)
                Talk(SAY_SLAY);
        }
        
        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            if (Phase == SVALADEAD)
            {
                if (attacker != me)
                    damage = 0;
                return;
            }

            if (damage >= me->GetHealth())
            {
                if (Phase == SACRIFICING)
                    SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);

                me->GetPosition(x, y, z);
                z = me->GetMap()->GetHeight(x, y, z, true, 50);

                if (me->GetPositionZ() > z)
                {
                    damage = 0;
                    Phase = SVALADEAD;
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAllAuras();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetHealth(1);

                    SetCombatMovement(false);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_FLYDEATH);
                    me->GetMotionMaster()->MoveFall(z, 1);
                }
            }
        }

        void MovementInform(uint32 motionType, uint32 pointId)
        {
            if (motionType != POINT_MOTION_TYPE)
                return;

            if (pointId == 1)
            {
                me->Relocate(x, y, z, me->GetOrientation());
                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
        }

        void JustDied(Unit* killer)
        {
            summons.DespawnAll();

            if (instance)
                instance->SetData(DATA_SVALA_SORROWGRAVE_EVENT, DONE);

            Talk(SAY_DEATH);
        }
        
        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_RITUAL_STRIKE_EFF_1 && Phase != NORMAL && Phase != SVALADEAD)
            {
                Phase = NORMAL;
                SetCombatMovement(true);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300, true))
                    me->GetMotionMaster()->MoveChase(target);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (Phase == IDLE)
                return;

            if (Phase == INTRO)
            {
                if (introTimer <= diff)
                {
                    Creature* arthas = Unit::GetCreature(*me, arthasGUID);
                    if (!arthas)
                        return;

                    switch (introPhase)
                    {
                        case 0:
                            Talk(SAY_SVALA_INTRO_0);
                            ++introPhase;
                            introTimer = 8100;
                            break;
                        case 1:
                            arthas->AI()->Talk(SAY_DIALOG_OF_ARTHAS_1);
                            ++introPhase;
                            introTimer = 10000;
                            break;
                        case 2:
                            arthas->CastSpell(me, SPELL_TRANSFORMING_CHANNEL, false);
                            me->SetFlying(true);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            pos.Relocate(me);
                            pos.m_positionZ += 8.0f;
                            me->GetMotionMaster()->MoveTakeoff(0, pos, 3.30078125f);
                            // spectators flee event
                            if (instance)
                            {
                                std::list<Creature*> lspectatorList;
                                GetCreatureListWithEntryInGrid(lspectatorList, me, CREATURE_SPECTATOR, 100.0f);
                                for(std::list<Creature*>::iterator itr = lspectatorList.begin(); itr != lspectatorList.end(); ++itr)
                                {
                                    if ((*itr)->isAlive())
                                    {
                                        (*itr)->SetStandState(UNIT_STAND_STATE_STAND);
                                        (*itr)->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                        (*itr)->GetMotionMaster()->MovePoint(1, spectatorWP[0][0], spectatorWP[0][1], spectatorWP[0][2]);
                                    }
                                }
                            }
                            ++introPhase;
                            introTimer = 4200;
                            break;
                        case 3:
                            me->CastSpell(me, SPELL_SVALA_TRANSFORMING1, false);
                            ++introPhase;
                            introTimer = 6200;
                            break;
                        case 4:
                            me->CastSpell(me, SPELL_SVALA_TRANSFORMING2, false);
                            arthas->InterruptNonMeleeSpells(true);
                            me->RemoveAllAuras();
                            me->UpdateEntry(CREATURE_SVALA_SORROWGRAVE);
                            me->SetFacingToObject(arthas);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            ++introPhase;
                            introTimer = 3200;
                            break;
                        case 5:
                            Talk(SAY_SVALA_INTRO_1);
                            ++introPhase;
                            introTimer = 10000;
                            break;
                        case 6:
                            arthas->AI()->Talk(SAY_DIALOG_OF_ARTHAS_2);
                            ++introPhase;
                            introTimer = 7200;
                            break;
                        case 7:
                            Talk(SAY_SVALA_INTRO_2);
                            me->SetOrientation(1.58f);
                            me->SendMovementFlagUpdate();
                            arthas->SetVisible(false);
                            ++introPhase;
                            introTimer = 13800;
                            break;
                        case 8:
                            me->SetFlying(false);
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            me->SendMovementFlagUpdate();
                            pos.Relocate(me);
                            pos.m_positionX = me->GetHomePosition().GetPositionX();
                            pos.m_positionY = me->GetHomePosition().GetPositionY();
                            pos.m_positionZ = 90.6065f;
                            me->GetMotionMaster()->MoveLand(0, pos, 6.247422f);
                            ++introPhase;
                            introTimer = 3000;
                            break;
                        case 9:
                            if (GameObject* mirror = GetClosestGameObjectWithEntry(me, OBJECT_UTGARDE_MIRROR, 100.0f))
                                mirror->SetGoState(GO_STATE_ACTIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            arthas->DespawnOrUnsummon();
                            arthasGUID = 0;
                            Phase = NORMAL;
                            break;
                    }
                } else introTimer -= diff;

                return;
            }

            if (Phase == NORMAL)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->getVictim()) && me->HasUnitMovementFlag(MOVEMENTFLAG_LEVITATING))
                {
                    me->SetFlying(false);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SendMovementFlagUpdate();
                }

                if (sinsterStrikeTimer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SINSTER_STRIKE);
                    sinsterStrikeTimer = urand(5 * IN_MILLISECONDS, 9 * IN_MILLISECONDS);
                } else sinsterStrikeTimer -= diff;

                if (callFlamesTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        DoCast(target, SPELL_CALL_FLAMES);
                        callFlamesTimer = urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
                    }
                } else callFlamesTimer -= diff;

                if (!sacrificed)
                {
                    if (HealthBelowPct(50))
                    {
                        if (Unit* sacrificeTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                        {
                            if (instance)
                                instance->SetData64(DATA_SACRIFICED_PLAYER, sacrificeTarget->GetGUID());

                            Talk(SAY_SACRIFICE_PLAYER);

                            DoCast(sacrificeTarget, SPELL_RITUAL_PREPARATION);

                            SetCombatMovement(false);
                            me->SetFlying(true);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

                            Phase = SACRIFICING;
                            sacrePhase = 0;
                            sacrificeTimer = 1 * IN_MILLISECONDS;

                            DoCast(me, SPELL_RITUAL_OF_THE_SWORD);
                            sacrificed = true;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
            else  //SACRIFICING
            {
                if (sacrificeTimer <= diff)
                {
                    switch (sacrePhase)
                    {
                        case 0:
                            // spawn ritual channelers
                            if (instance)
                            {
                                DoCast(me, SPELL_RITUAL_CHANNELER_1, true);
                                DoCast(me, SPELL_RITUAL_CHANNELER_2, true);
                                DoCast(me, SPELL_RITUAL_CHANNELER_3, true);
                            }
                            ++sacrePhase;
                            sacrificeTimer = 2 * IN_MILLISECONDS;
                            break;
                        case 1:
                            me->StopMoving();
                            me->GetMotionMaster()->MoveIdle();
                            me->InterruptNonMeleeSpells(true);
                            DoCast(me, SPELL_RITUAL_STRIKE_TRIGGER, true);
                            ++sacrePhase;
                            sacrificeTimer = 200;
                            break;
                        case 2:
                            DoCast(me, SPELL_RITUAL_DISARM);
                            ++sacrePhase;
                            break;
                        case 3:
                            break;
                    }
                }
                else sacrificeTimer -= diff;
            }
        }
    };

};

class npc_ritual_channeler : public CreatureScript
{
public:
    npc_ritual_channeler() : CreatureScript("npc_ritual_channeler") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ritual_channelerAI(creature);
    }

    struct npc_ritual_channelerAI : public Scripted_NoMovementAI
    {
        npc_ritual_channelerAI(Creature* creature) :Scripted_NoMovementAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 paralyzeTimer;

        void Reset()
        {
            paralyzeTimer = 1600;
            if (instance)
                if (IsHeroic())
                    DoCast(me, SPELL_SHADOWS_IN_THE_DARK);
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (paralyzeTimer <= diff)
            {
                if (instance)
                    if (Unit* victim = me->GetUnit(*me, instance->GetData64(DATA_SACRIFICED_PLAYER)))
                        DoCast(victim, SPELL_PARALYZE, false);

                paralyzeTimer = 200;
            }
            else
                paralyzeTimer -= diff;
        }
    };
};

class npc_spectator : public CreatureScript
{
public:
    npc_spectator() : CreatureScript("npc_spectator") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spectatorAI(creature);
    }

    struct npc_spectatorAI : public ScriptedAI
    {
        npc_spectatorAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() { }

        void MovementInform(uint32 motionType, uint32 pointId)
        {
            if (motionType == POINT_MOTION_TYPE)
            {
                if (pointId == 1)
                    me->GetMotionMaster()->MovePoint(2,spectatorWP[1][0],spectatorWP[1][1],spectatorWP[1][2]);
                else if (pointId == 2)
                    me->DespawnOrUnsummon(1000);
            }
        }
    };
};

class checkRitualTarget
{
    public:
        explicit checkRitualTarget(Unit* _caster) : caster(_caster) { }

        bool operator() (Unit* unit)
        {
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (instance->GetData64(DATA_SACRIFICED_PLAYER) == unit->GetGUID())
                    return false;

            return true;
        }

    private:
        Unit* caster;
};

class spell_paralyze_pinnacle : public SpellScriptLoader
{
    public:
        spell_paralyze_pinnacle() : SpellScriptLoader("spell_paralyze_pinnacle") { }

        class spell_paralyze_pinnacle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_paralyze_pinnacle_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(checkRitualTarget(GetCaster()));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_paralyze_pinnacle_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_paralyze_pinnacle_SpellScript();
        }
};

class npc_scourge_hulk : public CreatureScript
{
    public:
        npc_scourge_hulk() : CreatureScript("npc_scourge_hulk") { }

        struct npc_scourge_hulkAI : public ScriptedAI
        {
            npc_scourge_hulkAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 mightyBlow;
            uint32 volatileInfection;

            void Reset()
            {
                mightyBlow = urand(4000, 9000);
                volatileInfection = urand(10000, 14000);
                killedByRitualStrike = false;
            }

            uint32 GetData(uint32 type)
            {
                return type == DATA_INCREDIBLE_HULK ? killedByRitualStrike : 0;
            }
            
            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (damage >= me->GetHealth() && attacker->GetEntry() == CREATURE_SVALA_SORROWGRAVE)
                    killedByRitualStrike = true;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (mightyBlow <= diff)
                {
                    if (Unit* victim = me->getVictim())
                        if (!victim->HasUnitState(UNIT_STAT_STUNNED))    // Prevent knocking back a ritual player
                            DoCast(victim, SPELL_MIGHTY_BLOW);
                    mightyBlow = urand(12000, 17000);
                }
                else
                    mightyBlow -= diff;

                if (volatileInfection <= diff)
                {
                    DoCastVictim(SPELL_VOLATILE_INFECTION);
                    volatileInfection = urand(13000, 17000);
                }
                else
                    volatileInfection -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            bool killedByRitualStrike;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_scourge_hulkAI(creature);
        }
};

class achievement_incredible_hulk : public AchievementCriteriaScript
{
    public:
        achievement_incredible_hulk() : AchievementCriteriaScript("achievement_incredible_hulk") { }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            return target && target->IsAIEnabled && target->GetAI()->GetData(DATA_INCREDIBLE_HULK);
        }
};

void AddSC_boss_svala()
{
    new boss_svala();
    new npc_ritual_channeler();
    new npc_spectator();
    new spell_paralyze_pinnacle();
    new npc_scourge_hulk();
    new achievement_incredible_hulk();
}

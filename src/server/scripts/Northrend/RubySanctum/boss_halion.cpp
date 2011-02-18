/* Copyright (C) 2010 Easy for TrinityCore <http://trinity-core.ru/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "ruby_sanctum.h"

enum eTexts
{
    SAY_SPAWN       = -1752027,
    SAY_AGGRO       = -1752028,
    SAY_SLAY1       = -1752029,
    SAY_SLAY2       = -1752030,
    SAY_DEATH       = -1752031,
    SAY_BERSERK     = -1752032,
    SAY_SPECIAL1    = -1752033,
    SAY_SPECIAL2    = -1752034,
    SAY_PHASE2      = -1752035,
    SAY_PHASE3      = -1752036
};

enum eSpells
{
    SPELL_FIRE_PILLAR               = 76006,
    SPELL_FIERY_EXPLOSION           = 76010,
    //All
    SPELL_TWILIGHT_PRECISION        = 78243,
    SPELL_CLEAVE                    = 74524,
    SPELL_TAIL_LASH                 = 74531,
    SPELL_BERSEK                    = 26662,
    SPELL_TWILIGHT_DIVISION         = 75063,
    SPELL_SUMMON_TWILIGHT_PORTAL    = 74809,

    SPELL_METEOR_TARGET             = 74641,
    SPELL_METEOR_STRIKE             = 74637,
    SPELL_METEOR_DAMAGE             = 74648,
    SPELL_METEOR_FLAME              = 74713,

    //halion
    SPELL_FLAME_BREATH_10_NORMAL    = 74525,
    SPELL_FLAME_BREATH_25_NORMAL    = 74526,
    SPELL_FLAME_BREATH_10_HEROIC    = 74527,
    SPELL_FLAME_BREATH_25_HEROIC    = 74528,
    SPELL_FIERY_COMBUSTION          = 74562,

    //twilight halion
    SPELL_DUSK_SHROUD               = 75476,
    SPELL_SOUL_CONSUMPTION          = 74792,
    SPELL_DARK_BREATH_10_NORMAL     = 74806,
    SPELL_DARK_BREATH_25_NORMAL     = 75954,
    SPELL_DARK_BREATH_10_HEROIC     = 75955,
    SPELL_DARK_BREATH_25_HEROIC     = 75956,

    SPELL_AURE_TWILIGHT             = 74807
};

struct SpellsCorporeality
{
    uint32 SpellId1;
    uint32 SpellId2;
};

static const SpellsCorporeality sCorporeality[11] =
{
    {74827, 74832},
    {74828, 74833},
    {74829, 74834},
    {74830, 74835},
    {74831, 74836},
    {74832, 74827},
    {74833, 74828},
    {74834, 74829},
    {74835, 74830},
    {74836, 74831},
    {74826, 74826}
};

enum eEvents
{
    EVENT_CAST_TWILIGHT_PRECISION   = 1,
    EVENT_CAST_CLEAVE               = 2,
    EVENT_CAST_FIERY_COMBUSTION     = 3,
    EVENT_CAST_TAIL_LASH            = 4,
    EVENT_CAST_FLAME_BREATH         = 5,
    EVENT_CAST_DARK_BREATH          = 6,
    EVENT_CAST_SOUL_CONSUMPTION     = 7,
    EVENT_CAST_DUSK_SHROUD          = 8,
    EVENT_FLAME_WALL                = 9,
    EVENT_CAST_BERSEK               = 10,
    EVENT_DPS                       = 11,
    EVENT_METEOR_STRIKE             = 12,
    EVENT_METEOR_DAMAGE             = 13,
    EVENT_METEOR_FLAME              = 14,
    EVENT_FIRE_PILLAR               = 15
};

enum ePhases
{
    PHASE_ALL = 0,
    PHASE_1   = 1,
    PHASE_2   = 2,
    PHASE_3   = 3,

    PHASE_1_MASK  = 1 << PHASE_1,
    PHASE_2_MASK  = 1 << PHASE_2,
    PHASE_3_MASK  = 1 << PHASE_3
};

Creature* pHalion;
Creature* pTwilight;
uint32 HalionDamage, TwilightDamage;
uint32 HalionAura, TwilightAura;

class boss_halion : public CreatureScript
{
    public:
        boss_halion() : CreatureScript("boss_halion") { }

        struct boss_halionAI : public BossAI
        {
            boss_halionAI(Creature *pCreature) : BossAI(pCreature, DATA_HALION)
                {
                    ASSERT(instance);
                    pHalion = me;
                }

            void Reset()
            {
                if (instance->GetData(DATA_TWILIGHT_HALION)==IN_PROGRESS || instance->GetBossState(DATA_HALION)==IN_PROGRESS)
                {
                    return;
                }
                instance->SetBossState(DATA_HALION, NOT_STARTED);
                events.Reset();
                events.SetPhase(PHASE_1);
                events.ScheduleEvent(EVENT_CAST_TWILIGHT_PRECISION, 1000);
                events.ScheduleEvent(EVENT_CAST_CLEAVE, 15000);
                events.ScheduleEvent(EVENT_CAST_TAIL_LASH, urand(10000,15000));
                events.ScheduleEvent(EVENT_CAST_FLAME_BREATH, urand(20000,25000));
                events.ScheduleEvent(EVENT_CAST_FIERY_COMBUSTION, 15000);
                events.ScheduleEvent(EVENT_METEOR_STRIKE, 20000);
                events.ScheduleEvent(SPELL_BERSEK, 9999999);
                PercentDamage = 0;
                HalionDamage = 0;
                HalionAura = 0;
                RemoveAllGO();
                summons.DespawnEntry(40142);
                }

            void RemoveAllGO()
            {
                if (GameObject* flame1 = instance->instance->GetGameObject(instance->GetData64(GO_FLAME_WALLS2)))
                {
                    flame1->Delete();
                }
                if (GameObject* flame2 = instance->instance->GetGameObject(instance->GetData64(GO_FLAME_WALLS3)))
                {
                    flame2->Delete();
                }
                if (GameObject* portal1 = instance->instance->GetGameObject(instance->GetData64(GO_TWILIGHT_PORTAL1)))
                {
                    portal1->Delete();
                }
                if (GameObject* portal2 = instance->instance->GetGameObject(instance->GetData64(GO_TWILIGHT_PORTAL2)))
                {
                    portal2->Delete();
                }
            }

            void MeteorStrike()
            {
                float x,y,z;
                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget)
                {
                    pTarget->GetPosition(x,y,z);
                    me->SummonCreature(NPC_METEOR_STRIKE, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 999999);
                }
            }

            void EnterCombat(Unit*)
            {
                instance->SetBossState(DATA_HALION, IN_PROGRESS);

                if (events.GetPhaseMask() & PHASE_3_MASK)
                {
                    return;
                }

                events.ScheduleEvent(EVENT_FLAME_WALL, 3000,0,PHASE_1);
                DoScriptText(SAY_AGGRO, me);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                if (events.GetPhaseMask() & PHASE_3_MASK)
                {
                    if (instance->GetData(DATA_DAMAGE) > 0)
                        me->SetHealth(instance->GetData(DATA_DAMAGE));
                    else
                        if (instance->GetData(DATA_TWILIGHT_HALION)==IN_PROGRESS)
                            me->SetHealth(1);
                }

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                events.Update(diff);

                if ((events.GetPhaseMask() & PHASE_1_MASK) || (events.GetPhaseMask() & PHASE_3_MASK))
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CAST_TWILIGHT_PRECISION:
                                DoCast(me, SPELL_TWILIGHT_PRECISION); // not working
                                me->AddAura(SPELL_TWILIGHT_PRECISION, me); //test
                                break;
                            case EVENT_FLAME_WALL:
                                if (GameObject* go_flame1 = me->SummonGameObject(GO_FLAME_WALLS2, 3154.56f, 535.418f, 72.8889f, 4.47206f, 0, 0, 0.786772f, -0.617243f, 999999))
                                {
                                    go_flame1->SetPhaseMask(1,true);
                                }
                                if (GameObject* go_flame2 = me->SummonGameObject(GO_FLAME_WALLS3, 3154.56f, 535.418f, 72.8889f, 4.47206f, 0, 0, 0.786772f, -0.617243f, 999999))
                                {
                                    go_flame2->SetPhaseMask(32,true);
                                }
                                break;
                            case EVENT_CAST_TAIL_LASH:
                                DoCast(SPELL_TAIL_LASH);
                                events.ScheduleEvent(EVENT_CAST_TAIL_LASH, urand(10000,15000));
                                break;
                            case EVENT_CAST_CLEAVE:
                                DoCast(SPELL_CLEAVE);
                                events.ScheduleEvent(EVENT_CAST_CLEAVE, 15000);
                                break;
                            case EVENT_METEOR_STRIKE:
                                MeteorStrike();
                                events.ScheduleEvent(EVENT_METEOR_STRIKE, 20000);
                                break;
                            case EVENT_CAST_FLAME_BREATH:
                                DoCast(RAID_MODE(SPELL_FLAME_BREATH_10_NORMAL, SPELL_FLAME_BREATH_25_NORMAL, SPELL_FLAME_BREATH_10_HEROIC, SPELL_FLAME_BREATH_25_HEROIC));
                                events.ScheduleEvent(EVENT_CAST_FLAME_BREATH, urand(20000,25000));break;
                            case EVENT_DPS:
                                CastCorporeality();
                                events.ScheduleEvent(EVENT_DPS, 5000,0,PHASE_3);
                                break;
                            case EVENT_CAST_FIERY_COMBUSTION:
                                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                                if (pTarget && !pTarget->HasAura(SPELL_FIERY_COMBUSTION))
                                    DoCast(pTarget, SPELL_FIERY_COMBUSTION);
                                events.ScheduleEvent(EVENT_CAST_FIERY_COMBUSTION, 15000);
                                break;
                        }
                    }
                }

                if ((events.GetPhaseMask() & PHASE_1_MASK) && me->HealthBelowPct(75))
                {
                    events.SetPhase(PHASE_2);
                    instance->SetBossState(DATA_HALION, SPECIAL);
                    DoScriptText(SAY_PHASE2, me);
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoCast(me, SPELL_SUMMON_TWILIGHT_PORTAL);
                    DoCast(me, SPELL_TWILIGHT_DIVISION);
                    me->SummonCreature(NPC_TWILIGHT_HALION,SpawnPosHalion);
                    me->SetVisible(false);
                }
                DoMeleeAttackIfReady();
            }

            void CastCorporeality()
            {
                if (!(events.GetPhaseMask() & PHASE_3_MASK))
                        return;
                uint32 TotalDamage = HalionDamage+TwilightDamage;
                if (TotalDamage > 0)
                {
                    PercentDamage = HalionDamage * 100 / TotalDamage;
                }
                else
                {
                    PercentDamage = 50;
                }
                HalionDamage = 0;
                TwilightDamage = 0;
                if (TwilightAura!=0)
                {
                    pTwilight->RemoveAurasDueToSpell(TwilightAura);
                }
                if (HalionAura!=0)
                {
                    pHalion->RemoveAurasDueToSpell(HalionAura);
                }

                uint8 idAura;
                if (PercentDamage < 5)
                {
                    idAura = 9;
                }
                else if (PercentDamage < 15)
                {
                    idAura = 8;
                }
                else if (PercentDamage < 25)
                {
                    idAura = 7;
                }
                else if (PercentDamage < 35)
                {
                    idAura = 6;
                }
                else if (PercentDamage < 45)
                {
                    idAura = 5;
                }
                else if (PercentDamage < 55)
                {
                    idAura = 10;
                }
                else if (PercentDamage < 65)
                {
                    idAura = 0;
                }
                else if (PercentDamage < 75)
                {
                    idAura = 1;
                }
                else if (PercentDamage < 85)
                {
                    idAura = 2;
                }
                else if (PercentDamage < 95)
                {
                    idAura = 3;
                }
                else
                {
                    idAura = 4;
                }
                pHalion->CastSpell(pHalion, sCorporeality[idAura].SpellId1, true);
                pTwilight->CastSpell(pTwilight, sCorporeality[idAura].SpellId2, true);
                HalionAura=sCorporeality[idAura].SpellId1;
                TwilightAura=sCorporeality[idAura].SpellId2;
            }

            void SetPhase3()
            {
                events.SetPhase(PHASE_3);
                if (GameObject* portal = me->SummonGameObject(GO_TWILIGHT_PORTAL2, 3154.56f, 535.418f, 72.8889f, 4.47206f, 0, 0, 0.786772f, -0.617243f, 99999999))
                {
                    portal->SetPhaseMask(32,true);
                    portal->SetRespawnTime(9999999);
                }
                events.ScheduleEvent(EVENT_DPS, 5000,0,PHASE_3);
                pHalion->SetHealth(pTwilight->GetHealth());
            }

            void DamageTaken(Unit* /*who*/, uint32 &dmg)
            {
                if (!(events.GetPhaseMask() & PHASE_3_MASK))
                        return;
                HalionDamage += dmg;    

                instance->SetData(DATA_DAMAGE, me->GetHealth() >= dmg ? me->GetHealth() - dmg : 0);
            }

            void JustSummoned(Creature *summon)
            {
                if (summon->GetEntry()==NPC_TWILIGHT_HALION)
                {
                    summon->SetPhaseMask(32,true);
                    summons.Summon(summon);
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2), me);
            }

            void JustReachedHome()
            {
                if (instance->GetBossState(DATA_HALION)!=SPECIAL)
                {
                    instance->SetBossState(DATA_HALION,FAIL);
                    RemoveAllGO();
                }
            }

            void JustDied(Unit*)
            {
                _JustDied();
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURE_TWILIGHT);
                RemoveAllGO();
                DoScriptText(SAY_DEATH, me);
                switch(instance->instance->GetDifficulty())
                {
                 case RAID_DIFFICULTY_10MAN_NORMAL:
                          instance->DoCompleteAchievement(TWILIGHT_DESTROYER_NORMAL_10);
                 case RAID_DIFFICULTY_10MAN_HEROIC:
                            instance->DoCompleteAchievement(TWILIGHT_DESTROYER_HEROIC_10);
                 case RAID_DIFFICULTY_25MAN_NORMAL:
                           instance->DoCompleteAchievement(TWILIGHT_DESTROYER_NORMAL_25);
                  case RAID_DIFFICULTY_25MAN_HEROIC:
                             instance->DoCompleteAchievement(TWILIGHT_DESTROYER_HEROIC_25);

                 }
             }

        private:
            uint32 PercentDamage;
        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
                return new boss_halionAI(pCreature);
        }

};

class boss_twilight_halion : public CreatureScript
{
    public:
        boss_twilight_halion() : CreatureScript("boss_twilight_halion") { }

        struct boss_twilight_halionAI : public ScriptedAI
        {
            boss_twilight_halionAI(Creature *pCreature) : ScriptedAI(pCreature)
                {
                    pInstance = me->GetInstanceScript();
                    pTwilight = me;
                }

            void Reset()
            {
                if (pInstance->GetBossState(DATA_HALION)!=SPECIAL)
                    return;
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                events.Reset();
                events.SetPhase(PHASE_2);
                events.ScheduleEvent(EVENT_CAST_TWILIGHT_PRECISION, 1000);
                events.ScheduleEvent(EVENT_CAST_CLEAVE, 15000);
                events.ScheduleEvent(EVENT_CAST_TAIL_LASH, urand(10000,15000));
                events.ScheduleEvent(EVENT_CAST_DUSK_SHROUD, urand(15000,20000));
                events.ScheduleEvent(EVENT_CAST_DARK_BREATH, urand(20000,25000));
                events.ScheduleEvent(EVENT_CAST_SOUL_CONSUMPTION, urand(15000,25000));
                events.ScheduleEvent(EVENT_CAST_BERSEK, 9999999);
                me->SetMaxHealth(pHalion->GetMaxHealth());
                TwilightDamage = 0;
            }

            void EnterCombat(Unit*)
            {
                me->SetHealth(pHalion->GetHealth());
                pInstance->SetData(DATA_TWILIGHT_HALION,IN_PROGRESS);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (events.GetPhaseMask() & PHASE_3_MASK)
                {
                    if (pInstance->GetData(DATA_DAMAGE) != 0)
                        me->SetHealth(pInstance->GetData(DATA_DAMAGE));
                    else
                        me->SetHealth(1);
                }

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_TWILIGHT_PRECISION:
                            DoCast(me, SPELL_TWILIGHT_PRECISION);
                            break;
                        case EVENT_CAST_TAIL_LASH:
                            DoCast(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_CAST_TAIL_LASH, urand(10000,15000));
                            break;
                        case EVENT_CAST_DARK_BREATH:
                            DoCast(RAID_MODE(SPELL_DARK_BREATH_10_NORMAL, SPELL_DARK_BREATH_25_NORMAL, SPELL_DARK_BREATH_10_HEROIC, SPELL_DARK_BREATH_25_HEROIC));
                            events.ScheduleEvent(EVENT_CAST_DARK_BREATH, urand(20000,25000));break;
                        case EVENT_CAST_CLEAVE:
                            DoCast(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CAST_CLEAVE, 15000);
                            break;
                        case EVENT_CAST_DUSK_SHROUD:
                            DoCastAOE(SPELL_DUSK_SHROUD,true);
                            events.ScheduleEvent(EVENT_CAST_DUSK_SHROUD, urand(15000,20000));
                            break;
                        case EVENT_CAST_SOUL_CONSUMPTION:
                            DoCast(SPELL_SOUL_CONSUMPTION);
                            events.ScheduleEvent(EVENT_CAST_SOUL_CONSUMPTION, urand(15000,25000));
                            break;
                        case EVENT_CAST_BERSEK:
                            DoCast(me, SPELL_BERSEK);
                            events.ScheduleEvent(EVENT_CAST_BERSEK, 9999999);
                            break;
                        case EVENT_DPS:
                            if (pInstance->GetBossState(DATA_HALION)==SPECIAL)
                                CAST_AI(boss_halion::boss_halionAI, pHalion->AI())->CastCorporeality();
                            events.ScheduleEvent(EVENT_DPS, 5000,0,PHASE_3);
                            break;
                    }
                }

                if ((events.GetPhaseMask() & PHASE_2_MASK) && me->HealthBelowPct(50))
                {
                    pInstance->SetData(DATA_DAMAGE, me->GetHealth());
                    events.SetPhase(PHASE_3);
                    DoScriptText(SAY_PHASE3, me);
                    pHalion->SetReactState(REACT_AGGRESSIVE);
                    pHalion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pHalion->SetVisible(true);
                    CAST_AI(boss_halion::boss_halionAI, pHalion->AI())->SetPhase3();
                    events.ScheduleEvent(EVENT_DPS, 5000,0,PHASE_3);
                }

                DoMeleeAttackIfReady();
            }

            void DamageTaken(Unit* /*who*/, uint32 &dmg)
            {
                if (!(events.GetPhaseMask() & PHASE_3_MASK))
                        return;
                TwilightDamage += dmg;    

                pInstance->SetData(DATA_DAMAGE, me->GetHealth() >= dmg ? me->GetHealth() - dmg : 0);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2), me);
            }

            void JustReachedHome()
            {
                pInstance->SetData(DATA_TWILIGHT_HALION, FAIL);
                if (pInstance->GetBossState(DATA_HALION)==SPECIAL)
                    pInstance->SetBossState(DATA_HALION,FAIL);
                CAST_AI(boss_halion::boss_halionAI, pHalion->AI())->Reset();
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURE_TWILIGHT);
            }

            void JustDied(Unit*)
            {
                pInstance->SetData(DATA_TWILIGHT_HALION,DONE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURE_TWILIGHT);
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
                return new boss_twilight_halionAI(pCreature);
        }

};

class spell_halion_portal : public SpellScriptLoader
{
    public:
        spell_halion_portal() : SpellScriptLoader("spell_halion_portal") { }

        class spell_halion_portal_SpellScript : public SpellScript
        {
	    PrepareSpellScript(spell_halion_portal_SpellScript)
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                PreventHitDefaultEffect(EFFECT_0);
                GetHitPlayer()->RemoveAurasDueToSpell(SPELL_AURE_TWILIGHT);
                GetHitPlayer()->SetPhaseMask(1,true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_halion_portal_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_portal_SpellScript();
        }
};

class npc_meteor_strike : public CreatureScript
{
    public:
        npc_meteor_strike() : CreatureScript("npc_meteor_strike") { }

        struct npc_meteor_strikeAI : public ScriptedAI
        {
            npc_meteor_strikeAI(Creature *pCreature) : ScriptedAI(pCreature){}

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                DoCast(me, SPELL_METEOR_STRIKE);
                events.Reset();
                events.ScheduleEvent(EVENT_METEOR_DAMAGE, 7000);
                events.ScheduleEvent(EVENT_METEOR_STRIKE, 1000);
                me->ForcedDespawn(15000);
                angle = (float)(urand(0,62)/10);
                dist = 0;
                count = 0;
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_METEOR_STRIKE:
                            DoCastAOE(SPELL_METEOR_TARGET);
                            break;
                        case EVENT_METEOR_DAMAGE:
                            DoCastAOE(SPELL_METEOR_DAMAGE);
                            events.ScheduleEvent(EVENT_METEOR_FLAME, 1000);
                            break;
                        case EVENT_METEOR_FLAME:
                            float x, y;
                            dist += 5;
                            count ++;
                            me->GetNearPoint2D(x, y, dist, angle);
                            me->SummonCreature(NPC_METEOR_FLAME,x,y,me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,999999);
                            me->GetNearPoint2D(x, y, dist, angle+M_PI);
                            me->SummonCreature(NPC_METEOR_FLAME,x,y,me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,999999);
                            me->GetNearPoint2D(x, y, dist, angle+3*M_PI/2);
                            me->SummonCreature(NPC_METEOR_FLAME,x,y,me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,999999);
                            me->GetNearPoint2D(x, y, dist, angle+M_PI/2);
                            me->SummonCreature(NPC_METEOR_FLAME,x,y,me->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,999999);
                            if (count < 8)
                                events.ScheduleEvent(EVENT_METEOR_FLAME, 1000);
                            break;
                    }
                }
            }

        private:
            EventMap events;
            float dist, angle;
            uint8 count;

        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
            return new npc_meteor_strikeAI(pCreature);
        }
};

class npc_spell_meteor_strike : public CreatureScript
{
    public:
        npc_spell_meteor_strike() : CreatureScript("npc_spell_meteor_strike") { }

        struct npc_spell_meteor_strikeAI : public ScriptedAI
        {
            npc_spell_meteor_strikeAI(Creature *pCreature) : ScriptedAI(pCreature){}

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                me->ForcedDespawn(10000);
            }

        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
            return new npc_spell_meteor_strikeAI(pCreature);
        }
};

class npc_meteor_flame : public CreatureScript
{
    public:
        npc_meteor_flame() : CreatureScript("npc_meteor_flame") { }

        struct npc_meteor_flameAI : public ScriptedAI
        {
            npc_meteor_flameAI(Creature *pCreature) : ScriptedAI(pCreature){}

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                DoCast(me,SPELL_METEOR_FLAME);

                me->ForcedDespawn(10000);
            }
        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
            return new npc_meteor_flameAI(pCreature);
        }
};

class npc_summon_halion : public CreatureScript
{
    public:
        npc_summon_halion() : CreatureScript("npc_summon_halion") { }

        struct npc_summon_halionAI : public ScriptedAI
        {
            npc_summon_halionAI(Creature *pCreature) : ScriptedAI(pCreature){}

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
                events.Reset();
                events.ScheduleEvent(EVENT_FIRE_PILLAR, 10000);
                DoCast(me,SPELL_FIRE_PILLAR);

                me->ForcedDespawn(20000);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIRE_PILLAR:
                            DoCastAOE(SPELL_FIERY_EXPLOSION);
                            pHalion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pHalion->SetVisible(true);
                            pHalion->SetReactState(REACT_AGGRESSIVE);
                            break;
                    }
                }
            }

        private:
            EventMap events;

        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
            return new npc_summon_halionAI(pCreature);
        }
};

void AddSC_boss_halion()
{
    new boss_halion();
    new boss_twilight_halion();
    new spell_halion_portal();
    new npc_meteor_strike();
    new npc_spell_meteor_strike();
    new npc_meteor_flame();
    new npc_summon_halion();
}
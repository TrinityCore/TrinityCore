/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "firelands.h"
#include "ObjectMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"

enum ScriptTexts
{
    SAY_SPAWN           = 8,
    SAY_AGGRO           = 0,
    SAY_RIPLIMB         = 4,
    SAY_RAGEFACE        = 5,
    SAY_KILL            = 7,
    SAY_MAGMA_RUPTURE   = 6,
    SAY_SPEAR           = 2,
    SAY_DEATH           = 1,
    SAY_DOG             = 3,
    SAY_DISENGAGE       = 9,
};

enum Spells
{
    // Shannox
    SPELL_BERSERK                   = 26662,
    SPELL_ARCING_SLASH              = 99931,
    SPELL_HURL_SPEAR_AOE            = 100031,
    SPELL_HURL_SPEAR_SUMMON         = 99978,
    SPELL_HURL_SPEAR_DMG            = 100002,
    SPELL_SPEAR_TARGET              = 99988,
    SPELL_SPEAR_VISUAL              = 100005,
    SPELL_FETCH_SPEAR               = 100026,
    SPELL_MAGMA_RUPTURE             = 99840,
    SPELL_MAGMA_RUPTURE_MISSILE     = 99841,
    SPELL_MAGMA_FLARE               = 100495,
    SPELL_FRENZY                    = 100522,
    SPELL_THROW_IMMOLATION_TRAP     = 99839,
    SPELL_IMMOLATION_TRAP_DMG       = 99838,
    SPELL_THROW_CRYSTAL_PRISON_TRAP = 99836,
    SPELL_CRYSTAL_PRISON_TRAP       = 99837,

    // Riplimb
    SPELL_LIMB_RIP                  = 99832,
    SPELL_DOGGED_DETERMINATION      = 101111,

    // Rageface
    SPELL_FACE_RAGE                 = 99945,
    SPELL_FACE_RAGE_DUMMY           = 100129,
    SPELL_RAGE                      = 100415,

    // Shared
    SPELL_SEPARATION_ANXIETY        = 99835,
    SPELL_FEEDING_FRENZY            = 100655,
    SPELL_FRENZIED_DEVOTION         = 100064,
    SPELL_WARRY                     = 100167,
    SPELL_WARRY_25                  = 101215,
    SPELL_WARRY_10H                 = 101216,
    SPELL_WARRY_25H                 = 101217,
};

enum Events
{
    EVENT_BERSERK               = 1,
    EVENT_ARCING_SLASH          = 2,
    EVENT_IMMOLATION_TRAP       = 3,
    EVENT_CRYSTAL_PRISON_TRAP   = 4,
    EVENT_HURL_SPEAR            = 5,
    EVENT_MAGMA_RUPTURE         = 6,
    EVENT_LIMB_RIP              = 7,
    EVENT_FETCH_SPEAR           = 8,
    EVENT_SEPARATION_ANXIETY    = 9,
    EVENT_CHANGE_TARGET         = 10,
    EVENT_FACE_RAGE             = 11,
    EVENT_RESURRECT             = 12,
    EVENT_MAGMA_RUPTURE_2       = 13,
    EVENT_UNIT_IN_LOS           = 14,
    EVENT_CHECK_COMBAT          = 15,
};

enum Adds
{
    NPC_SPEAR_OF_SHANNOX_1  = 53752, // only target?
    NPC_SPEAR_OF_SHANNOX_2  = 54112,
    NPC_CRYSTAL_PRISON_TRAP = 53713,
    NPC_CRYSTAL_PRISON      = 53819,
    NPC_IMMOLATION_TRAP     = 53724,
};

enum Other
{
    ACTION_HURL_SPEAR       = 1,
    ACTION_RESURRECT        = 2,
    POINT_SPEAR_OF_SHANNOX  = 3,
    DATA_TRAPPED_PLAYER     = 4,
    DATA_TRAPPED_DOG        = 5,
};

enum AreaIds
{
    AREA_1          = 5764, // Логово Бет'тилак
    AREA_2          = 5821, // Порочный путь
    AREA_3          = 5766, // Каменный Венец
    AREA_4          = 5791, // Гряда Древнего Пламени
    AREA_5          = 5765, // Огненный портал
};

const Position dogPos[2] =
{
    {-153.604f, 198.994f, 46.174f, 3.68f}, // Riplimb
    {-145.179f, 184.976f, 46.168f, 3.34f}  // Rageface
};

class boss_shannox : public CreatureScript
{
    public:
        boss_shannox() : CreatureScript("boss_shannox") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new boss_shannoxAI(pCreature);
        }

        struct boss_shannoxAI : public BossAI
        {
            boss_shannoxAI(Creature* pCreature) : BossAI(pCreature, DATA_SHANNOX)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                bIntro = false;
            }

            bool areas[5];
            bool bIntro;
            bool bRiplimbDead;
            bool bRagefaceDead;
            bool bFrenzy;

            void InitializeAI() override
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(FLScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            bool AllowAchieve()
            {
                for (uint8 i = 0; i < 5; ++i)
                    if (!areas[i])
                        return false;
                return true;
            }

            void Reset() override
            {
                _Reset();

                me->SummonCreature(NPC_RIPLIMB, dogPos[0]);
                me->SummonCreature(NPC_RAGEFACE, dogPos[1]);
                bRiplimbDead = false;
                bRagefaceDead = false;
                bFrenzy = false;
                memset(areas, false, sizeof(areas));
            }

            void DamageTaken(Unit* attacker, uint32 &damage) override
            {
                if (attacker->GetGUID() == me->GetGUID())
                    damage = 0;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!bIntro && me->GetDistance2d(who) < 100.0f)
                {
                    bIntro = true;
                    Talk(SAY_SPAWN);
                }
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_RESURRECT:
                        bRiplimbDead = false;
                        events.CancelEvent(EVENT_MAGMA_RUPTURE);
                        events.ScheduleEvent(EVENT_HURL_SPEAR, urand(5000, 10000));
                        break;
                }
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                if (summon->GetEntry() == NPC_RIPLIMB)
                {
                    bRiplimbDead = true;
                    Talk(SAY_RIPLIMB);
                    if (!IsHeroic())
                        DoCast(me, SPELL_FRENZY, true);
                    events.CancelEvent(EVENT_HURL_SPEAR);
                    events.ScheduleEvent(EVENT_MAGMA_RUPTURE, urand(5000, 15000));
                }
                else if (summon->GetEntry() == NPC_RAGEFACE)
                {
                    bRagefaceDead = true;
                    Talk(SAY_RAGEFACE);
                    if (!IsHeroic())
                        DoCast(me, SPELL_FRENZY, true);
                }
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                if (Creature* pRiplimb = me->FindNearestCreature(NPC_RIPLIMB, 300.0f))
                    DoZoneInCombat(pRiplimb);
                if (Creature* pRageface = me->FindNearestCreature(NPC_RAGEFACE, 300.0f))
                    DoZoneInCombat(pRageface);

                bRiplimbDead = false;
                bRagefaceDead = false;
                bFrenzy = false;
                memset(areas, false, sizeof(areas));

                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HURL_SPEAR, 15000);
                events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 2000);
                events.ScheduleEvent(EVENT_IMMOLATION_TRAP, urand(10000, 20000));
                events.ScheduleEvent(EVENT_CRYSTAL_PRISON_TRAP, urand(10000, 25500));
                events.ScheduleEvent(EVENT_ARCING_SLASH, urand(10000, 12000));
                events.ScheduleEvent(EVENT_CHECK_COMBAT, 5000);
                DoZoneInCombat();
                instance->SetBossState(DATA_SHANNOX, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* /*who*/) override
            {
                Talk(SAY_KILL);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (me->IsInCombat())
                    DoZoneInCombat(summon);

                if (summon->GetEntry() == NPC_SPEAR_OF_SHANNOX_1)
                {
                    Talk(SAY_SPEAR);
                    DoCast(summon, SPELL_HURL_SPEAR_DMG);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                // Bucket List
                switch (me->GetAreaId())
                {
                    case AREA_1:
                        if (!areas[0])
                            areas[0] = true;
                        break;
                    case AREA_2:
                        if (!areas[1])
                            areas[1] = true;
                        break;
                    case AREA_3:
                        if (!areas[2])
                            areas[2] = true;
                        break;
                    case AREA_4:
                        if (!areas[3])
                            areas[3] = true;
                        break;
                    case AREA_5:
                        if (!areas[4])
                            areas[4] = true;
                        break;
                }

                events.Update(diff);

                if (!IsHeroic() && !bFrenzy && me->HealthBelowPct(30))
                {
                    bFrenzy = true;

                    if (Creature* pRiplimb = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RIPLIMB)))
                        if (pRiplimb->IsAlive())
                            pRiplimb->CastSpell(pRiplimb, SPELL_FRENZIED_DEVOTION, true);

                    if (Creature* pRageface = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RAGEFACE)))
                        if (pRageface->IsAlive())
                            pRageface->CastSpell(pRageface, SPELL_FRENZIED_DEVOTION, true);
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_COMBAT:
                            if (me->IsInCombat())
                            {
                                if (Creature* pRiplimb = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RIPLIMB)))
                                    if (!pRiplimb->IsInCombat() && !pRiplimb->IsInEvadeMode())
                                        if (pRiplimb->IsAlive())
                                            DoZoneInCombat(pRiplimb);

                                if (Creature* pRageface = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RAGEFACE)))
                                    if (!pRageface->IsInCombat() && !pRageface->IsInEvadeMode())
                                        if (pRageface->IsAlive())
                                            DoZoneInCombat(pRageface);
                            }
                            events.ScheduleEvent(EVENT_CHECK_COMBAT, 5000);
                        case EVENT_SEPARATION_ANXIETY:
                            if (Creature* pRiplimb = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RIPLIMB)))
                                if (pRiplimb->IsAlive() && !me->IsWithinDist(pRiplimb, 80.0f) && !me->HasAura(SPELL_SEPARATION_ANXIETY))
                                    DoCast(me, SPELL_SEPARATION_ANXIETY, true);
                            if (Creature* pRageface = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RAGEFACE)))
                                if (pRageface->IsAlive() && !me->IsWithinDist(pRageface, 80.0f) && !me->HasAura(SPELL_SEPARATION_ANXIETY))
                                    DoCast(me, SPELL_SEPARATION_ANXIETY, true);
                            events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 2000);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        case EVENT_ARCING_SLASH:
                            DoCastVictim(SPELL_ARCING_SLASH);
                            events.ScheduleEvent(EVENT_ARCING_SLASH, urand(18000, 22000));
                            break;
                        case EVENT_HURL_SPEAR:
                            if (Creature* pRiplimb = me->FindNearestCreature(NPC_RIPLIMB, 300.0f))
                                DoCast(pRiplimb, SPELL_HURL_SPEAR_SUMMON, true);
                            events.ScheduleEvent(EVENT_HURL_SPEAR, 42000);
                            break;
                        case EVENT_IMMOLATION_TRAP:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_THROW_IMMOLATION_TRAP);
                            events.ScheduleEvent(EVENT_IMMOLATION_TRAP, urand(23000, 30000));
                            break;
                        case EVENT_CRYSTAL_PRISON_TRAP:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(pTarget, SPELL_THROW_CRYSTAL_PRISON_TRAP);
                            events.ScheduleEvent(EVENT_CRYSTAL_PRISON_TRAP, 25500);
                            break;
                        case EVENT_MAGMA_RUPTURE:
                            Talk(SAY_MAGMA_RUPTURE);
                            DoCast(me, SPELL_MAGMA_RUPTURE);
                            events.ScheduleEvent(EVENT_MAGMA_RUPTURE_2, 1500);
                            events.ScheduleEvent(EVENT_MAGMA_RUPTURE, 20000);
                            break;
                        case EVENT_MAGMA_RUPTURE_2:
                            // There will be a spiral, 3 "circles", 20 points per circle
                            Position pos;
                            for (uint8 i = 0; i < 60; ++i)
                            {
                                pos = me->GetNearPosition(15.0f + i * 0.75f, (M_PI * i) / 10);
                                pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, MAX_HEIGHT);
                                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_MAGMA_RUPTURE_MISSILE, true);
                            }
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_shannox_riplimb : public CreatureScript
{
    public:
        npc_shannox_riplimb() : CreatureScript("npc_shannox_riplimb") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_shannox_riplimbAI(pCreature);
        }

        struct npc_shannox_riplimbAI : public ScriptedAI
        {
            npc_shannox_riplimbAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->setActive(true);
                me->SetSpeed(MOVE_RUN, 1.1f);
                pInstance = me->GetInstanceScript();
            }

            InstanceScript* pInstance;
            bool bFetch;
            EventMap events;
            bool bDead;

            void Reset() override
            {
                bFetch = false;
                bDead = false;
                events.Reset();
                if (IsHeroic())
                    DoCast(me, SPELL_FEEDING_FRENZY, true);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Creature* pShannox = me->FindNearestCreature(NPC_SHANNOX, 300.0f))
                    DoZoneInCombat(pShannox);
                if (Creature* pRageface = me->FindNearestCreature(NPC_RAGEFACE, 300.0f))
                    DoZoneInCombat(pRageface);

                DoZoneInCombat();
                events.ScheduleEvent(EVENT_LIMB_RIP, 6000);
                events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 3000);
                events.ScheduleEvent(EVENT_CHECK_COMBAT, 5000);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
            {
                if (!IsHeroic())
                    return;

                if (damage >= me->GetHealth() && !bDead)
                {
                    bDead = true;
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    events.Reset();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->RemoveAllAuras();
                    events.ScheduleEvent(EVENT_RESURRECT, 30000);
                }
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_HURL_SPEAR:
                        if (bDead)
                        {
                            if (Creature* pSpear = me->FindNearestCreature(NPC_SPEAR_OF_SHANNOX_1, 300.0f))
                                pSpear->DespawnOrUnsummon();
                            return;
                        }
                        events.Reset();
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->RemoveMovementImpairingAuras();
                        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, false);
                        DoCast(me, SPELL_DOGGED_DETERMINATION, true);
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == POINT_SPEAR_OF_SHANNOX)
                    {
                        if (Creature* pSpear = me->FindNearestCreature(NPC_SPEAR_OF_SHANNOX_1, 300.0f))
                            pSpear->DespawnOrUnsummon();
                        DoCast(me, SPELL_FETCH_SPEAR, true);
                        events.ScheduleEvent(EVENT_FETCH_SPEAR, 500);
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (bFetch)
                {
                    if (me->FindNearestCreature(NPC_SHANNOX, 1.0f))
                    {
                        bFetch = false;
                        me->RemoveAurasDueToSpell(SPELL_DOGGED_DETERMINATION);
                        me->RemoveAurasDueToSpell(SPELL_FETCH_SPEAR);
                        me->GetMotionMaster()->MovementExpired();
                        me->RemoveMovementImpairingAuras();
                        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_LIMB_RIP, 5000);
                        if (me->GetVictim())
                            AttackStart(me->GetVictim());
                        else
                        {
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0.0f, 0.0f, true))
                                AttackStart(pTarget);
                        }
                    }
                    return;
                }

                if (!UpdateVictim() && !bDead)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_COMBAT:
                            if (me->IsInCombat())
                            {
                                if (Creature* pRageface = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_RAGEFACE)))
                                    if (!pRageface->IsInCombat() && !pRageface->IsInEvadeMode())
                                        if (pRageface->IsAlive())
                                            DoZoneInCombat(pRageface);

                                if (Creature* pShannox = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                                    if (!pShannox->IsInCombat() && !pShannox->IsInEvadeMode())
                                        if (pShannox->IsAlive())
                                            DoZoneInCombat(pShannox);
                            }
                            events.ScheduleEvent(EVENT_CHECK_COMBAT, 5000);
                            break;
                        case EVENT_SEPARATION_ANXIETY:
                            if (!me->FindNearestCreature(NPC_SHANNOX, 80.0f) && !me->HasAura(SPELL_SEPARATION_ANXIETY))
                                DoCast(me, SPELL_SEPARATION_ANXIETY, true);
                            events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 2000);
                            break;
                        case EVENT_FETCH_SPEAR:
                            if (pInstance)
                                if (Creature* pShannox = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                                {
                                    bFetch = true;
                                    me->GetMotionMaster()->MovementExpired(false);
                                    me->GetMotionMaster()->MoveFollow(pShannox, 0.0f, 0.0f);
                                }
                            break;
                        case EVENT_LIMB_RIP:
                            DoCastVictim(SPELL_LIMB_RIP);
                            events.ScheduleEvent(EVENT_LIMB_RIP, urand(20000, 22000));
                            break;
                        case EVENT_RESURRECT:
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            me->SetHealth(me->GetMaxHealth());
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                            if (pInstance)
                                if (Unit* pShannox = ObjectAccessor::GetUnit(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                                    pShannox->GetAI()->DoAction(ACTION_RESURRECT);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class npc_shannox_rageface : public CreatureScript
{
    public:
        npc_shannox_rageface() : CreatureScript("npc_shannox_rageface") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_shannox_ragefaceAI(pCreature);
        }

        struct npc_shannox_ragefaceAI : public ScriptedAI
        {
            npc_shannox_ragefaceAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->setActive(true);
                me->SetSpeed(MOVE_RUN, 1.1f);
                pInstance = me->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
                if (IsHeroic())
                    DoCast(me, SPELL_FEEDING_FRENZY, true);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Creature* pShannox = me->FindNearestCreature(NPC_SHANNOX, 300.0f))
                    DoZoneInCombat(pShannox);
                if (Creature* pRiplimb = me->FindNearestCreature(NPC_RIPLIMB, 300.0f))
                    DoZoneInCombat(pRiplimb);

                DoZoneInCombat();
                events.ScheduleEvent(EVENT_FACE_RAGE, 7000);
                events.ScheduleEvent(EVENT_CHANGE_TARGET, 5000);
                events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 3000);
                events.ScheduleEvent(EVENT_CHECK_COMBAT, 5000);
            }

            void DamageTaken(Unit* who, uint32 &damage) override
            {
                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (AuraEffect const* aurEff = me->GetAuraEffect(RAID_MODE(100129, 101212, 101213, 101214), EFFECT_1))
                {
                    if (int32(damage) >= aurEff->GetAmount())
                    {
                        me->InterruptSpell(CURRENT_CHANNELED_SPELL, false);
                        DoResetThreat();
                        DoCast(who, SPELL_RAGE, true);
                        me->AddThreat(who, 10000000.0f);
                        AttackStart(who);
                        events.ScheduleEvent(EVENT_FACE_RAGE, 27000);
                        me->RemoveAurasDueToSpell(RAID_MODE(100129, 101212, 101213, 101214));
                    }
                }
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id == EVENT_JUMP)
                {
                    if (Unit* pTarget = me->GetVictim())
                        DoCast(pTarget, 99947, true);
                }
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
                        case EVENT_CHECK_COMBAT:
                            if (me->IsInCombat())
                            {
                                if (Creature* pRiplimb = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_RIPLIMB)))
                                    if (!pRiplimb->IsInCombat() && !pRiplimb->IsInEvadeMode())
                                        if (pRiplimb->IsAlive())
                                            DoZoneInCombat(pRiplimb);

                                if (Creature* pShannox = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                                    if (!pShannox->IsInCombat() && !pShannox->IsInEvadeMode())
                                        if (pShannox->IsAlive())
                                            DoZoneInCombat(pShannox);
                            }
                            events.ScheduleEvent(EVENT_CHECK_COMBAT, 5000);
                            break;
                        case EVENT_SEPARATION_ANXIETY:
                            if (!me->FindNearestCreature(NPC_SHANNOX, 80.0f) && !me->HasAura(SPELL_SEPARATION_ANXIETY))
                                DoCast(me, SPELL_SEPARATION_ANXIETY, true);
                            events.ScheduleEvent(EVENT_SEPARATION_ANXIETY, 2000);
                            break;
                        case EVENT_FACE_RAGE:
                            if (pInstance)
                                if (Creature* pShannox = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                                    pShannox->AI()->Talk(SAY_DOG);
                            DoCastVictim(SPELL_FACE_RAGE);
                            break;
                        case EVENT_CHANGE_TARGET:
                            if (pInstance && !(me->GetVictim() && me->GetVictim()->HasAura(SPELL_RAGE)) && !me->HasAura(SPELL_FACE_RAGE_DUMMY))
                            {
                                DoResetThreat();
                                if (Creature* pShannox = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                                {
                                    if (Unit* pTarget = pShannox->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                    {
                                        me->AddThreat(pTarget, 10000000.0f);
                                        AttackStart(pTarget);
                                    }
                                }
                                else
                                {
                                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                    {

                                        me->AddThreat(pTarget, 10000000.0f);
                                        AttackStart(pTarget);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_CHANGE_TARGET, 7000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class npc_shannox_spear_of_shannox : public CreatureScript
{
    public:
        npc_shannox_spear_of_shannox() : CreatureScript("npc_shannox_spear_of_shannox") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_shannox_spear_of_shannoxAI(pCreature);
        }

        struct npc_shannox_spear_of_shannoxAI : public Scripted_NoMovementAI
        {
            npc_shannox_spear_of_shannoxAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                pInstance = me->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                DoCast(me, SPELL_SPEAR_TARGET, true);
            }

            void SpellHit(Unit* /*caster*/, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id == SPELL_HURL_SPEAR_DMG)
                {
                    std::list<Creature*> creatureList;
                    me->GetCreatureListWithEntryInGrid(creatureList, NPC_DULL_EMBERSTONE_FOCUS, 50.0f);
                    if (!creatureList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                        {
                            if (Creature* pFocus = (*itr)->ToCreature())
                            {
                                pFocus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                pFocus->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                pFocus->CastSpell(pFocus, SPELL_TRANSFORM_CHARGED_EMBERSTONE_FOCUS, true);
                            }
                        }
                    }

                    me->RemoveAurasDueToSpell(SPELL_SPEAR_TARGET);
                    DoCast(me, SPELL_MAGMA_FLARE, true);
                    DoCast(me, SPELL_SPEAR_VISUAL, true);

                    if (pInstance)
                    {
                        if (Creature* pShannox = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(DATA_SHANNOX)))
                        {
                            // There will be a spiral, 3 "circles", 20 points per circle
                            Position pos;
                            for (uint8 i = 0; i < 60; ++i)
                            {
                                pos = me->GetNearPosition(15.0f + i * 0.75f, (M_PI * i) / 10);
                                pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, MAX_HEIGHT);
                                pShannox->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_MAGMA_RUPTURE_MISSILE, true);
                            }
                        }
                    }

                    if (Creature* pRiplimb = me->FindNearestCreature(NPC_RIPLIMB, 300.0f))
                    {
                        pRiplimb->AI()->DoAction(ACTION_HURL_SPEAR);
                        pRiplimb->GetMotionMaster()->MovePoint(POINT_SPEAR_OF_SHANNOX, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    }
                }
            }
        };
};

class npc_shannox_immolation_trap : public CreatureScript
{
    public:
        npc_shannox_immolation_trap() : CreatureScript("npc_shannox_immolation_trap") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_shannox_immolation_trapAI(pCreature);
        }

        struct npc_shannox_immolation_trapAI : public Scripted_NoMovementAI
        {
            npc_shannox_immolation_trapAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                bReady = false;
                bExplode = false;
                uiReadyTimer = 3000;
            }

            bool bReady;
            bool bExplode;
            uint32 uiReadyTimer;

            void UpdateAI(uint32 diff) override
            {
                if (!bReady)
                {
                    if (uiReadyTimer <= diff)
                        bReady = true;
                    else
                        uiReadyTimer -= diff;
                }
                else if (bReady && !bExplode)
                {
                    if (Player* pPlayer = me->SelectNearestPlayer(0.1f))
                    {
                        bExplode = true;
                        pPlayer->CastSpell(pPlayer, SPELL_IMMOLATION_TRAP_DMG, true);
                        me->DespawnOrUnsummon(1000);
                    }
                    else if (Creature* pRiplimb = me->FindNearestCreature(NPC_RIPLIMB, 0.1f))
                    {
                        if (!pRiplimb->HasAura(SPELL_WARRY) &&
                            !pRiplimb->HasAura(SPELL_WARRY_25) &&
                            !pRiplimb->HasAura(SPELL_WARRY_10H) &&
                            !pRiplimb->HasAura(SPELL_WARRY_25H))
                        {
                            bExplode = true;
                            pRiplimb->CastSpell(pRiplimb, SPELL_IMMOLATION_TRAP_DMG, true);
                            me->DespawnOrUnsummon(500);
                        }
                    }
                    else if (Creature* pRageface = me->FindNearestCreature(NPC_RAGEFACE, 0.1f))
                    {
                        if(!pRageface->HasAura(SPELL_WARRY) &&
                            !pRageface->HasAura(SPELL_WARRY_25) &&
                            !pRageface->HasAura(SPELL_WARRY_10H) &&
                            !pRageface->HasAura(SPELL_WARRY_25H))
                        {
                            bExplode = true;
                            pRageface->CastSpell(pRageface, SPELL_IMMOLATION_TRAP_DMG, true);
                            me->DespawnOrUnsummon(500);
                        }
                    }
                }
            }
        };
};

class npc_shannox_crystal_prison_trap : public CreatureScript
{
    public:
        npc_shannox_crystal_prison_trap() : CreatureScript("npc_shannox_crystal_prison_trap") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_shannox_crystal_prison_trapAI(pCreature);
        }

        struct npc_shannox_crystal_prison_trapAI : public Scripted_NoMovementAI
        {
            npc_shannox_crystal_prison_trapAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                bReady = false;
                bExplode = false;
                uiReadyTimer = 3000;
            }

            bool bReady;
            bool bExplode;
            uint32 uiReadyTimer;

            void UpdateAI(uint32 diff) override
            {
                if (!bReady)
                {
                    if (uiReadyTimer <= diff)
                        bReady = true;
                    else
                        uiReadyTimer -= diff;
                }
                else if (bReady && !bExplode)
                {
                    if (Player* pPlayer = me->SelectNearestPlayer(0.1f))
                    {
                        bExplode = true;
                        pPlayer->CastSpell(pPlayer, SPELL_CRYSTAL_PRISON_TRAP, true);
                        me->DespawnOrUnsummon(500);
                    }
                    else if (Creature* pRiplimb = me->FindNearestCreature(NPC_RIPLIMB, 0.1f))
                    {
                        if (!pRiplimb->HasAura(SPELL_WARRY) &&
                            !pRiplimb->HasAura(SPELL_WARRY_25) &&
                            !pRiplimb->HasAura(SPELL_WARRY_10H) &&
                            !pRiplimb->HasAura(SPELL_WARRY_25H))
                        {
                            bExplode = true;
                            pRiplimb->CastSpell(pRiplimb, SPELL_CRYSTAL_PRISON_TRAP, true);
                            me->DespawnOrUnsummon(500);
                        }
                    }
                    else if (Creature* pRageface = me->FindNearestCreature(NPC_RAGEFACE, 0.1f))
                    {
                        if (!pRageface->HasAura(SPELL_WARRY) &&
                            !pRageface->HasAura(SPELL_WARRY_25) &&
                            !pRageface->HasAura(SPELL_WARRY_10H) &&
                            !pRageface->HasAura(SPELL_WARRY_25H))
                        {
                            bExplode = true;
                            pRageface->CastSpell(pRageface, SPELL_CRYSTAL_PRISON_TRAP, true);
                            me->DespawnOrUnsummon(500);
                        }
                    }
                }
            }
        };
};

class npc_shannox_crystal_prison : public CreatureScript
{
    public:
        npc_shannox_crystal_prison() : CreatureScript("npc_shannox_crystal_prison") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_shannox_crystal_prisonAI(creature);
        }

        struct npc_shannox_crystal_prisonAI : public Scripted_NoMovementAI
        {
            npc_shannox_crystal_prisonAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                bDog = false;
            }

            ObjectGuid trappedUnit;
            uint32 existenceCheckTimer;
            bool bDog;
            uint32 dogTimer;

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                trappedUnit = guid;
                existenceCheckTimer = 1000;

                if (type == DATA_TRAPPED_DOG)
                {
                    bDog = true;
                    dogTimer = 10000;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (!bDog)
                    DoCast(me, SPELL_CREATE_EMBERSTONE_FRAGMENT, true);
                bDog = false;
                if (Unit* unit = ObjectAccessor::GetUnit(*me, trappedUnit))
                {
                    trappedUnit = ObjectGuid::Empty;
                    unit->RemoveAurasDueToSpell(SPELL_CRYSTAL_PRISON_TRAP);
                }
                me->DespawnOrUnsummon(800);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!trappedUnit)
                    return;

                if (existenceCheckTimer <= diff)
                {
                    Unit* unit = ObjectAccessor::GetUnit(*me, trappedUnit);
                    if (!unit || unit->isDead() || !unit->HasAura(SPELL_CRYSTAL_PRISON_TRAP))
                    {
                        JustDied(me);
                        return;
                    }
                }
                else
                    existenceCheckTimer -= diff;

                if (bDog)
                {
                    if (dogTimer <= diff)
                        JustDied(me);
                    else
                        dogTimer -= diff;
                }
            }
        };
};

class spell_shannox_riplimb_dogged_determination : public SpellScriptLoader
{
    public:
        spell_shannox_riplimb_dogged_determination() : SpellScriptLoader("spell_shannox_riplimb_dogged_determination") { }

        class spell_shannox_riplimb_dogged_determination_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shannox_riplimb_dogged_determination_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;

                if (Aura* aur = GetAura())
                {
                    if (AuraEffect* auraEff = aur->GetEffect(EFFECT_0))
                    {
                        int32 curr_amount = auraEff->GetAmount();
                        if (curr_amount < 100)
                            auraEff->SetAmount(curr_amount + 5);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_shannox_riplimb_dogged_determination_AuraScript::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shannox_riplimb_dogged_determination_AuraScript();
        }
};

class spell_shannox_crystal_prison_trap : public SpellScriptLoader
{
    public:
        spell_shannox_crystal_prison_trap() : SpellScriptLoader("spell_shannox_crystal_prison_trap") { }

        class spell_shannox_crystal_prison_trap_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shannox_crystal_prison_trap_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster() || !GetTarget())
                    return;

                if (Creature* pCrystalPrison = GetCaster()->SummonCreature(NPC_CRYSTAL_PRISON, GetTarget()->GetPosition()))
                    pCrystalPrison->AI()->SetGUID(GetTarget()->GetGUID(), (GetTarget()->GetTypeId() == TYPEID_PLAYER)? DATA_TRAPPED_PLAYER: DATA_TRAPPED_DOG);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                if (GetTarget()->GetEntry() == NPC_RIPLIMB || GetTarget()->GetEntry() == NPC_RAGEFACE)
                    GetTarget()->CastSpell(GetTarget(), SPELL_WARRY, true);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_shannox_crystal_prison_trap_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_shannox_crystal_prison_trap_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shannox_crystal_prison_trap_AuraScript();
        }
};

class spell_shannox_immolation_trap : public SpellScriptLoader
{
    public:
        spell_shannox_immolation_trap() : SpellScriptLoader("spell_shannox_immolation_trap") { }


        class spell_shannox_immolation_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shannox_immolation_trap_SpellScript);


            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit() && (GetHitUnit()->GetEntry() == NPC_RIPLIMB || GetHitUnit()->GetEntry() == NPC_RAGEFACE))
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_WARRY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_shannox_immolation_trap_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shannox_immolation_trap_SpellScript();
        }
};

typedef boss_shannox::boss_shannoxAI ShannoxAI;

class achievement_bucket_list : public AchievementCriteriaScript
{
    public:
        achievement_bucket_list() : AchievementCriteriaScript("achievement_bucket_list") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (ShannoxAI* shannoxAI = CAST_AI(ShannoxAI, target->GetAI()))
                return shannoxAI->AllowAchieve();

            return false;
        }
};

void AddSC_boss_shannox()
{
    new boss_shannox();
    new npc_shannox_riplimb();
    new npc_shannox_rageface();
    new npc_shannox_spear_of_shannox();
    new npc_shannox_immolation_trap();
    new npc_shannox_crystal_prison_trap();
    new npc_shannox_crystal_prison();
    new spell_shannox_riplimb_dogged_determination();
    new spell_shannox_crystal_prison_trap();
    new spell_shannox_immolation_trap();
    new achievement_bucket_list();
}

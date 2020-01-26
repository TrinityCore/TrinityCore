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

/* ScriptData
SDName: Boss_Kalecgos
SD%Complete: 95
SDComment:
SDCategory: Sunwell_Plateau
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "sunwell_plateau.h"
#include "TemporarySummon.h"

enum Yells
{
    SAY_SATH_AGGRO                  = 0,
    SAY_SATH_SLAY                   = 1,
    SAY_SATH_DEATH                  = 2,
    SAY_SATH_SPELL1                 = 3,
    SAY_SATH_SPELL2                 = 4,

    SAY_EVIL_AGGRO                  = 0,
    SAY_EVIL_SLAY                   = 1,
    SAY_GOOD_PLRWIN                 = 2,
    SAY_EVIL_ENRAGE                 = 3,

    SAY_GOOD_AGGRO                  = 0,
    SAY_GOOD_NEAR_DEATH             = 1,
    SAY_GOOD_NEAR_DEATH2            = 2
};

enum Spells
{
    AURA_SUNWELL_RADIANCE           = 45769,
    AURA_SPECTRAL_EXHAUSTION        = 44867,
    AURA_SPECTRAL_REALM             = 46021,
    AURA_SPECTRAL_INVISIBILITY      = 44801,
    AURA_DEMONIC_VISUAL             = 44800,

    SPELL_SPECTRAL_BLAST            = 44869,
    SPELL_TELEPORT_SPECTRAL         = 46019,
    SPELL_ARCANE_BUFFET             = 45018,
    SPELL_FROST_BREATH              = 44799,
    SPELL_TAIL_LASH                 = 45122,

    SPELL_BANISH                    = 136466,          // Changed in MoP  - Patch 5.3 for solo player.
    SPELL_TRANSFORM_KALEC           = 44670,
    SPELL_ENRAGE                    = 44807,

    SPELL_CORRUPTION_STRIKE         = 45029,
    SPELL_AGONY_CURSE               = 45032,
    SPELL_SHADOW_BOLT               = 45031,

    SPELL_HEROIC_STRIKE             = 45026,
    SPELL_REVITALIZE                = 45027
};

enum SWPActions
{
    DO_ENRAGE                       =  1,
    DO_BANISH                       =  2
};

enum Misc
{
    FLY_X                           = 1679,
    FLY_Y                           = 900,
    FLY_Z                           = 82,
    CENTER_X                        = 1705,
    CENTER_Y                        = 930,
    RADIUS                          = 30,
    MAX_PLAYERS_IN_SPECTRAL_REALM   = 0 // over this, teleport object won't work, 0 disables check
};

#define DRAGON_REALM_Z  53.079f
#define DEMON_REALM_Z   -74.558f

uint32 WildMagic[] = { 44978, 45001, 45002, 45004, 45006, 45010 };

class boss_kalecgos : public CreatureScript
{
public:
    boss_kalecgos() : CreatureScript("boss_kalecgos") { }

    struct boss_kalecgosAI : public ScriptedAI
    {
        boss_kalecgosAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            bJustReset = false;
            me->setActive(true);
        }

        void Initialize()
        {
            SathGUID.Clear();
            ArcaneBuffetTimer = 8000;
            FrostBreathTimer = 15000;
            WildMagicTimer = 10000;
            TailLashTimer = 25000;
            SpectralBlastTimer = urand(20000, 25000);
            CheckTimer = 1000;
            ResetTimer = 30000;

            TalkTimer = 0;
            TalkSequence = 0;
            isFriendly = false;
            isEnraged = false;
            isBanished = false;
        }

        InstanceScript* instance;

        uint32 ArcaneBuffetTimer;
        uint32 FrostBreathTimer;
        uint32 WildMagicTimer;
        uint32 SpectralBlastTimer;
        uint32 TailLashTimer;
        uint32 CheckTimer;
        uint32 TalkTimer;
        uint32 TalkSequence;
        uint32 ResetTimer;

        bool isFriendly;
        bool isEnraged;
        bool isBanished;
        bool bJustReset;

        ObjectGuid SathGUID;

        void Reset() override
        {
            SathGUID = instance->GetGuidData(DATA_SATHROVARR);
            instance->SetBossState(DATA_KALECGOS, NOT_STARTED);

            if (Creature* Sath = ObjectAccessor::GetCreature(*me, SathGUID))
                Sath->AI()->EnterEvadeMode();

            me->setFaction(14);
            if (!bJustReset) //first reset at create
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->SetDisableGravity(false);
                me->SetVisible(true);
                me->SetStandState(UNIT_STAND_STATE_SLEEP);
            }
            me->SetFullHealth(); //dunno why it does not resets health at evade..
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (me->HasAura(SPELL_BANISH))
                return;

            bJustReset = true;
            me->SetVisible(false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            ScriptedAI::EnterEvadeMode(why);
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
                case DO_ENRAGE:
                    isEnraged = true;
                    me->CastSpell(me, SPELL_ENRAGE, true);
                    break;
                case DO_BANISH:
                    isBanished = true;
                    me->CastSpell(me, SPELL_BANISH, true);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (TalkTimer)
            {
                if (!TalkSequence)
                {
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAllAuras();
                    me->DeleteThreatList();
                    me->CombatStop();
                    ++TalkSequence;
                }
                if (TalkTimer <= diff)
                {
                    if (isFriendly)
                        GoodEnding();
                    else
                        BadEnding();
                    ++TalkSequence;
                } else TalkTimer -= diff;
            }
            else
            {
                if (bJustReset)
                {
                    if (ResetTimer <= diff)
                    {
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        me->SetDisableGravity(false);
                        me->SetVisible(true);
                        me->SetStandState(UNIT_STAND_STATE_SLEEP);
                        ResetTimer = 10000;
                        bJustReset = false;
                    } else ResetTimer -= diff;
                    return;
                }

                if (!UpdateVictim())
                    return;

                if (CheckTimer <= diff)
                {
                    if (me->GetDistance(CENTER_X, CENTER_Y, DRAGON_REALM_Z) >= 75)
                    {
                        EnterEvadeMode(EVADE_REASON_BOUNDARY);
                        return;
                    }
                    if (HealthBelowPct(10) && !isEnraged)
                    {
                        if (Creature* Sath = ObjectAccessor::GetCreature(*me, SathGUID))
                            Sath->AI()->DoAction(DO_ENRAGE);
                        DoAction(DO_ENRAGE);
                    }
                    if (!isBanished && HealthBelowPct(1))
                    {
                        if (Creature* Sath = ObjectAccessor::GetCreature(*me, SathGUID))
                        {
                            if (Sath->HasAura(SPELL_BANISH))
                            {
                                Sath->DealDamage(Sath, Sath->GetHealth());
                                return;
                            }
                            else
                                DoAction(DO_BANISH);
                        }
                        else
                        {
                            TC_LOG_ERROR("scripts", "Didn't find Shathrowar. Kalecgos event reseted.");
                            EnterEvadeMode(EVADE_REASON_OTHER);
                            return;
                        }
                    }
                    CheckTimer = 1000;
                } else CheckTimer -= diff;

                if (ArcaneBuffetTimer <= diff)
                {
                    DoCastAOE(SPELL_ARCANE_BUFFET);
                    ArcaneBuffetTimer = 8000;
                } else ArcaneBuffetTimer -= diff;

                if (FrostBreathTimer <= diff)
                {
                    DoCastAOE(SPELL_FROST_BREATH);
                    FrostBreathTimer = 15000;
                } else FrostBreathTimer -= diff;

                if (TailLashTimer <= diff)
                {
                    DoCastAOE(SPELL_TAIL_LASH);
                    TailLashTimer = 15000;
                } else TailLashTimer -= diff;

                if (WildMagicTimer <= diff)
                {
                    DoCastAOE(WildMagic[rand32() % 6]);
                    WildMagicTimer = 20000;
                } else WildMagicTimer -= diff;

                if (SpectralBlastTimer <= diff)
                {
                    ThreatContainer::StorageType const& m_threatlist = me->getThreatManager().getThreatList();
                    std::list<Unit*> targetList;
                    for (ThreatContainer::StorageType::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                    {
                        Unit* target = (*itr)->getTarget();
                        if (target
                                && target->GetTypeId() == TYPEID_PLAYER
                                && (!target->GetVictim() || target->GetGUID() != me->EnsureVictim()->GetGUID())
                                && target->GetPositionZ() > me->GetPositionZ() - 5
                                && !target->HasAura(AURA_SPECTRAL_EXHAUSTION))
                        {
                            targetList.push_back(target);
                        }
                    }
                    if (targetList.empty())
                    {
                        SpectralBlastTimer = 1000;
                        return;
                    }

                    std::list<Unit*>::const_iterator i = targetList.begin();
                    advance(i, rand32() % targetList.size());
                    if ((*i))
                    {
                        (*i)->CastSpell((*i), SPELL_SPECTRAL_BLAST, true);
                        SpectralBlastTimer = 20000 + rand32() % 5000;
                    } else SpectralBlastTimer = 1000;
                } else SpectralBlastTimer -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (bJustReset)//boss is invisible, don't attack
                return;

            if (!me->GetVictim() && me->IsValidAttackTarget(who))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius))
                    AttackStart(who);
            }
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->SetStandState(UNIT_STAND_STATE_STAND);
            Talk(SAY_EVIL_AGGRO);
            DoZoneInCombat();

            instance->SetBossState(DATA_KALECGOS, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_EVIL_SLAY);
        }

        void MovementInform(uint32 type, uint32 /*id*/) override
        {
            if (type != POINT_MOTION_TYPE)
                return;
            me->SetVisible(false);
            if (isFriendly)
            {
                me->setDeathState(JUST_DIED);
                me->GetMap()->ToInstanceMap()->PermBindAllPlayers();
            }
            else
            {
                me->GetMotionMaster()->MoveTargetedHome();
                TalkTimer = 1000;
            }
        }

        void GoodEnding()
        {
            switch (TalkSequence)
            {
                case 1:
                    me->setFaction(35);
                    TalkTimer = 1000;
                    break;
                case 2:
                    Talk(SAY_GOOD_PLRWIN);
                    TalkTimer = 10000;
                    break;
                case 3:
                    me->SetDisableGravity(true);
                    me->GetMotionMaster()->MovePoint(0, FLY_X, FLY_Y, FLY_Z);
                    TalkTimer = 600000;
                    break;
                default:
                    break;
            }
        }

        void BadEnding()
        {
            switch (TalkSequence)
            {
                case 1:
                    Talk(SAY_EVIL_ENRAGE);
                    TalkTimer = 3000;
                    break;
                case 2:
                    me->SetDisableGravity(true);
                    me->GetMotionMaster()->MovePoint(0, FLY_X, FLY_Y, FLY_Z);
                    TalkTimer = 15000;
                    break;
                case 3:
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_kalecgosAI>(creature);
    }
};

class boss_kalec : public CreatureScript
{
public:
    boss_kalec() : CreatureScript("boss_kalec") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_kalecAI>(creature);
    }

    struct boss_kalecAI : public ScriptedAI
    {
        InstanceScript* instance;

        uint32 RevitalizeTimer;
        uint32 HeroicStrikeTimer;
        uint32 YellTimer;
        uint32 YellSequence;

        ObjectGuid SathGUID;

        bool isEnraged; // if demon is enraged

        boss_kalecAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            RevitalizeTimer = 5000;
            HeroicStrikeTimer = 3000;
            YellTimer = 5000;
            YellSequence = 0;

            isEnraged = false;
        }

        void Reset() override
        {
            SathGUID = instance->GetGuidData(DATA_SATHROVARR);

            Initialize();
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (done_by->GetGUID() != SathGUID)
                damage = 0;
            else if (isEnraged)
                damage *= 3;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->HasAura(AURA_SPECTRAL_INVISIBILITY))
                me->CastSpell(me, AURA_SPECTRAL_INVISIBILITY, true);

            if (!UpdateVictim())
                return;

            if (YellTimer <= diff)
            {
                switch (YellSequence)
                {
                    case 0:
                        Talk(SAY_GOOD_AGGRO);
                        ++YellSequence;
                        break;
                    case 1:
                        if (HealthBelowPct(50))
                        {
                            Talk(SAY_GOOD_NEAR_DEATH);
                            ++YellSequence;
                        }
                        break;
                    case 2:
                        if (HealthBelowPct(10))
                        {
                            Talk(SAY_GOOD_NEAR_DEATH2);
                            ++YellSequence;
                        }
                        break;
                    default:
                        break;
                }
                YellTimer = 5000;
            }

            if (RevitalizeTimer <= diff)
            {
                DoCast(me, SPELL_REVITALIZE);
                RevitalizeTimer = 5000;
            } else RevitalizeTimer -= diff;

            if (HeroicStrikeTimer <= diff)
            {
                DoCastVictim(SPELL_HEROIC_STRIKE);
                HeroicStrikeTimer = 2000;
            } else HeroicStrikeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class kalecgos_teleporter : public GameObjectScript
{
public:
    kalecgos_teleporter() : GameObjectScript("kalecgos_teleporter") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
#if MAX_PLAYERS_IN_SPECTRAL_REALM > 0
        uint8 SpectralPlayers = 0;
        Map::PlayerList const &PlayerList = go->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        {
            if (i->GetSource() && i->GetSource()->GetPositionZ() < DEMON_REALM_Z + 5)
                ++SpectralPlayers;
        }

        if (player->HasAura(AURA_SPECTRAL_EXHAUSTION) || SpectralPlayers >= MAX_PLAYERS_IN_SPECTRAL_REALM)
        {
            return true;
        }
#else
        (void)go;
#endif

        player->CastSpell(player, SPELL_TELEPORT_SPECTRAL, true);
        return true;
    }
};

class boss_sathrovarr : public CreatureScript
{
public:
    boss_sathrovarr() : CreatureScript("boss_sathrovarr") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunwellPlateauAI<boss_sathrovarrAI>(creature);
    }

    struct boss_sathrovarrAI : public ScriptedAI
    {
        boss_sathrovarrAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            ShadowBoltTimer = urand(7, 10) * 1000;
            AgonyCurseTimer = 20000;
            CorruptionStrikeTimer = 13000;
            CheckTimer = 1000;
            ResetThreat = 1000;
            isEnraged = false;
            isBanished = false;
        }

        InstanceScript* instance;

        uint32 CorruptionStrikeTimer;
        uint32 AgonyCurseTimer;
        uint32 ShadowBoltTimer;
        uint32 CheckTimer;
        uint32 ResetThreat;

        ObjectGuid KalecGUID;
        ObjectGuid KalecgosGUID;

        bool isEnraged;
        bool isBanished;

        void Reset() override
        {
            me->SetFullHealth();//dunno why it does not resets health at evade..
            me->setActive(true);
            KalecgosGUID = instance->GetGuidData(DATA_KALECGOS_DRAGON);
            instance->SetBossState(DATA_KALECGOS, NOT_STARTED);
            if (!KalecGUID.IsEmpty())
            {
                if (Creature* Kalec = ObjectAccessor::GetCreature(*me, KalecGUID))
                    Kalec->setDeathState(JUST_DIED);
                KalecGUID.Clear();
            }

            Initialize();

            me->CastSpell(me, AURA_DEMONIC_VISUAL, true);
            TeleportAllPlayersBack();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* Kalec = me->SummonCreature(NPC_KALEC, me->GetPositionX() + 10, me->GetPositionY() + 5, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
            {
                KalecGUID = Kalec->GetGUID();
                me->CombatStart(Kalec);
                me->AddThreat(Kalec, 100.0f);
                Kalec->setActive(true);
            }
            Talk(SAY_SATH_AGGRO);
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void KilledUnit(Unit* target) override
        {
            if (target->GetGUID() == KalecGUID)
            {
                TeleportAllPlayersBack();
                if (Creature* Kalecgos = ObjectAccessor::GetCreature(*me, KalecgosGUID))
                {
                    ENSURE_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->TalkTimer = 1;
                    ENSURE_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->isFriendly = false;
                }
                EnterEvadeMode();
                return;
            }
            Talk(SAY_SATH_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_SATH_DEATH);
            me->SetPosition(me->GetPositionX(), me->GetPositionY(), DRAGON_REALM_Z, me->GetOrientation());
            TeleportAllPlayersBack();
            if (Creature* Kalecgos = ObjectAccessor::GetCreature(*me, KalecgosGUID))
            {
                ENSURE_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->TalkTimer = 1;
                ENSURE_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->isFriendly = true;
            }

            instance->SetBossState(DATA_KALECGOS, DONE);
        }

        void TeleportAllPlayersBack()
        {
            Map::PlayerList const &playerList = me->GetMap()->GetPlayers();
            Position const& homePos = me->GetHomePosition();
            for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                Player* player = itr->GetSource();
                if (player->IsInDist(&homePos, 50.0f) && player->GetPositionZ() <= DEMON_REALM_Z + 10.f)
                {
                    player->RemoveAura(AURA_SPECTRAL_REALM);
                    player->TeleportTo(me->GetMap()->GetId(), player->GetPositionX(),
                        player->GetPositionY(), DRAGON_REALM_Z + 5, player->GetOrientation());
                }
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
                case DO_ENRAGE:
                    isEnraged = true;
                    me->CastSpell(me, SPELL_ENRAGE, true);
                    break;
                case DO_BANISH:
                    isBanished = true;
                    me->CastSpell(me, SPELL_BANISH, true);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->HasAura(AURA_SPECTRAL_INVISIBILITY))
                me->CastSpell(me, AURA_SPECTRAL_INVISIBILITY, true);

            if (!UpdateVictim())
                return;

            if (CheckTimer <= diff)
            {
                Creature* Kalec = ObjectAccessor::GetCreature(*me, KalecGUID);
                if (!Kalec || !Kalec->IsAlive())
                {
                    if (Creature* Kalecgos = ObjectAccessor::GetCreature(*me, KalecgosGUID))
                        Kalecgos->AI()->EnterEvadeMode();
                    return;
                }

                if (HealthBelowPct(10) && !isEnraged)
                {
                    if (Creature* Kalecgos = ObjectAccessor::GetCreature(*me, KalecgosGUID))
                        Kalecgos->AI()->DoAction(DO_ENRAGE);
                    DoAction(DO_ENRAGE);
                }

                Creature* Kalecgos = ObjectAccessor::GetCreature(*me, KalecgosGUID);
                if (Kalecgos && !Kalecgos->IsInCombat())
                {
                    EnterEvadeMode();
                    return;
                }

                if (!isBanished && HealthBelowPct(1))
                {
                    if (Kalecgos)
                    {
                        if (Kalecgos->HasAura(SPELL_BANISH))
                        {
                            me->DealDamage(me, me->GetHealth());
                            return;
                        }
                        DoAction(DO_BANISH);
                    }
                    else
                    {
                        EnterEvadeMode();
                        return;
                    }
                }
                CheckTimer = 1000;
            } else CheckTimer -= diff;

            if (ResetThreat <= diff)
            {
                ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
                for (ThreatContainer::StorageType::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid()))
                        if (unit->GetPositionZ() > me->GetPositionZ() + 5)
                            me->getThreatManager().modifyThreatPercent(unit, -100);
                }
                ResetThreat = 1000;
            } else ResetThreat -= diff;

            if (ShadowBoltTimer <= diff)
            {
                if (!(rand32() % 5))
                    Talk(SAY_SATH_SPELL1);
                DoCast(me, SPELL_SHADOW_BOLT);
                ShadowBoltTimer = 7000 + (rand32() % 3000);
            } else ShadowBoltTimer -= diff;

            if (AgonyCurseTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                if (!target)
                    target = me->GetVictim();
                DoCast(target, SPELL_AGONY_CURSE);
                AgonyCurseTimer = 20000;
            } else AgonyCurseTimer -= diff;

            if (CorruptionStrikeTimer <= diff)
            {
                if (!(rand32() % 5))Talk(SAY_SATH_SPELL2);
                DoCastVictim(SPELL_CORRUPTION_STRIKE);
                CorruptionStrikeTimer = 13000;
            } else CorruptionStrikeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_kalecgos()
{
    new boss_kalecgos();
    new boss_sathrovarr();
    new boss_kalec();
    new kalecgos_teleporter();
}

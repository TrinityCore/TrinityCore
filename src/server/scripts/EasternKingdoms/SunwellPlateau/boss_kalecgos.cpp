/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "sunwell_plateau.h"
#include "Player.h"
#include "WorldSession.h"

enum Yells
{
    SAY_SATH_AGGRO                              = 0,
    SAY_SATH_SLAY                               = 1,
    SAY_SATH_DEATH                              = 2,
    SAY_SATH_SPELL1                             = 3,
    SAY_SATH_SPELL2                             = 4,

    SAY_EVIL_AGGRO                              = 0,
    SAY_EVIL_SLAY                               = 1,
    SAY_GOOD_PLRWIN                             = 2,
    SAY_EVIL_ENRAGE                             = 3,

    SAY_GOOD_AGGRO                              = 0,
    SAY_GOOD_NEAR_DEATH                         = 1,
    SAY_GOOD_NEAR_DEATH2                        = 2,
};

enum Spells
{
    AURA_SUNWELL_RADIANCE                       = 45769,
    AURA_SPECTRAL_EXHAUSTION                    = 44867,
    AURA_SPECTRAL_REALM                         = 46021,
    AURA_SPECTRAL_INVISIBILITY                  = 44801,
    AURA_DEMONIC_VISUAL                         = 44800,

    SPELL_SPECTRAL_BLAST                        = 44869,
    SPELL_TELEPORT_SPECTRAL                     = 46019,
    SPELL_ARCANE_BUFFET                         = 45018,
    SPELL_FROST_BREATH                          = 44799,
    SPELL_TAIL_LASH                             = 45122,

    SPELL_BANISH                                = 44836,
    SPELL_TRANSFORM_KALEC                       = 44670,
    SPELL_ENRAGE                                = 44807,

    SPELL_CORRUPTION_STRIKE                     = 45029,
    SPELL_AGONY_CURSE                           = 45032,
    SPELL_SHADOW_BOLT                           = 45031,

    SPELL_HEROIC_STRIKE                         = 45026,
    SPELL_REVITALIZE                            = 45027
};

enum SWPActions
{
    DO_ENRAGE                                   =  1,
    DO_BANISH                                   =  2,
};

#define GO_FAILED   "You are unable to use this currently."

#define EMOTE_UNABLE_TO_FIND    "is unable to find Kalecgos"

#define FLY_X   1679
#define FLY_Y   900
#define FLY_Z   82

#define CENTER_X    1705
#define CENTER_Y    930
#define RADIUS      30

#define DRAGON_REALM_Z  53.079f
#define DEMON_REALM_Z   -74.558f

#define MAX_PLAYERS_IN_SPECTRAL_REALM 0 //over this, teleport object won't work, 0 disables check

uint32 WildMagic[] = { 44978, 45001, 45002, 45004, 45006, 45010 };

class boss_kalecgos : public CreatureScript
{
public:
    boss_kalecgos() : CreatureScript("boss_kalecgos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kalecgosAI (creature);
    }

    struct boss_kalecgosAI : public ScriptedAI
    {
        boss_kalecgosAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            SathGUID = 0;
            DoorGUID = 0;
            bJustReset = false;
            me->setActive(true);
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

        uint64 SathGUID;
        uint64 DoorGUID;

        void Reset()
        {
            if (instance)
            {
                SathGUID = instance->GetData64(DATA_SATHROVARR);
                instance->SetData(DATA_KALECGOS_EVENT, NOT_STARTED);
            }

            if (Creature* Sath = Unit::GetCreature(*me, SathGUID))
                Sath->AI()->EnterEvadeMode();

            me->setFaction(14);
            if (!bJustReset) //first reset at create
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                me->SetDisableGravity(false);
                me->SetVisible(true);
                me->SetStandState(UNIT_STAND_STATE_SLEEP);
            }
            me->SetFullHealth();//dunno why it does not resets health at evade..
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

        void EnterEvadeMode()
        {
            bJustReset = true;
            me->SetVisible(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            ScriptedAI::EnterEvadeMode();
        }

        void DoAction(int32 param)
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

        void UpdateAI(uint32 diff)
        {
            if (TalkTimer)
            {
                if (!TalkSequence)
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
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
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
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
                        me->AI()->EnterEvadeMode();
                        return;
                    }
                    if (HealthBelowPct(10) && !isEnraged)
                    {
                        if (Creature* Sath = Unit::GetCreature(*me, SathGUID))
                            Sath->AI()->DoAction(DO_ENRAGE);
                        DoAction(DO_ENRAGE);
                    }
                    if (!isBanished && HealthBelowPct(1))
                    {
                        if (Creature* Sath = Unit::GetCreature(*me, SathGUID))
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
                            TC_LOG_ERROR(LOG_FILTER_TSCR, "Didn't find Shathrowar. Kalecgos event reseted.");
                            EnterEvadeMode();
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
                    DoCastAOE(WildMagic[rand()%6]);
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
                                && target->GetGUID() != me->GetVictim()->GetGUID()
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
                    advance(i, rand()%targetList.size());
                    if ((*i))
                    {
                        (*i)->CastSpell((*i), SPELL_SPECTRAL_BLAST, true);
                        SpectralBlastTimer = 20000+rand()%5000;
                    } else SpectralBlastTimer = 1000;
                } else SpectralBlastTimer -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MoveInLineOfSight(Unit* who)
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

        void DamageTaken(Unit* done_by, uint32 &damage)
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->SetStandState(UNIT_STAND_STATE_STAND);
            Talk(SAY_EVIL_AGGRO);
            DoZoneInCombat();

            if (instance)
                instance->SetData(DATA_KALECGOS_EVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_EVIL_SLAY);
        }

        void MovementInform(uint32 type, uint32 /*id*/)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            me->SetVisible(false);
            if (isFriendly)
            {
                me->setDeathState(JUST_DIED);

                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player)
                            me->GetMap()->ToInstanceMap()->PermBindAllPlayers(player);
                    }
                }
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
                EnterEvadeMode();
                break;
            default:
                break;
            }
        }
    };
};

class boss_kalec : public CreatureScript
{
public:
    boss_kalec() : CreatureScript("boss_kalec") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kalecAI (creature);
    }

    struct boss_kalecAI : public ScriptedAI
    {
        InstanceScript* instance;

        uint32 RevitalizeTimer;
        uint32 HeroicStrikeTimer;
        uint32 YellTimer;
        uint32 YellSequence;

        uint64 SathGUID;

        bool isEnraged; // if demon is enraged

        boss_kalecAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset()
        {
            if (instance)
                SathGUID = instance->GetData64(DATA_SATHROVARR);

            RevitalizeTimer = 5000;
            HeroicStrikeTimer = 3000;
            YellTimer = 5000;
            YellSequence = 0;

            isEnraged = false;
        }

        void DamageTaken(Unit* done_by, uint32 &damage)
        {
            if (done_by->GetGUID() != SathGUID)
                damage = 0;
            else if (isEnraged)
                damage *= 3;
        }

        void UpdateAI(uint32 diff)
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
                DoCast(me->GetVictim(), SPELL_HEROIC_STRIKE);
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

    bool OnGossipHello(Player* player, GameObject* go)
    {
        uint8 SpectralPlayers = 0;
        Map* map = go->GetMap();
        if (!map->IsDungeon())
            return true;

        Map::PlayerList const &PlayerList = map->GetPlayers();
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        {
            if (i->GetSource() && i->GetSource()->GetPositionZ() < DEMON_REALM_Z + 5)
                ++SpectralPlayers;
        }
        uint8 MaxSpectralPlayers =  MAX_PLAYERS_IN_SPECTRAL_REALM;
        if (player->HasAura(AURA_SPECTRAL_EXHAUSTION) || (MaxSpectralPlayers && SpectralPlayers >= MaxSpectralPlayers))
            player->GetSession()->SendNotification(GO_FAILED);
        else
            player->CastSpell(player, SPELL_TELEPORT_SPECTRAL, true);
        return true;
    }
};

class boss_sathrovarr : public CreatureScript
{
public:
    boss_sathrovarr() : CreatureScript("boss_sathrovarr") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_sathrovarrAI (creature);
    }

    struct boss_sathrovarrAI : public ScriptedAI
    {
        boss_sathrovarrAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            KalecGUID = 0;
            KalecgosGUID = 0;
        }

        InstanceScript* instance;

        uint32 CorruptionStrikeTimer;
        uint32 AgonyCurseTimer;
        uint32 ShadowBoltTimer;
        uint32 CheckTimer;
        uint32 ResetThreat;

        uint64 KalecGUID;
        uint64 KalecgosGUID;

        bool isEnraged;
        bool isBanished;

        void Reset()
        {
            me->SetFullHealth();//dunno why it does not resets health at evade..
            me->setActive(true);
            if (instance)
            {
                KalecgosGUID = instance->GetData64(DATA_KALECGOS_DRAGON);
                instance->SetData(DATA_KALECGOS_EVENT, NOT_STARTED);
            }
            if (KalecGUID)
            {
                if (Creature* Kalec = Unit::GetCreature(*me, KalecGUID))
                    Kalec->setDeathState(JUST_DIED);
                KalecGUID = 0;
            }

            ShadowBoltTimer = urand(7, 10) * 1000;
            AgonyCurseTimer = 20000;
            CorruptionStrikeTimer = 13000;
            CheckTimer = 1000;
            ResetThreat = 1000;
            isEnraged = false;
            isBanished = false;

            me->CastSpell(me, AURA_DEMONIC_VISUAL, true);
            TeleportAllPlayersBack();
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Creature* Kalec = me->SummonCreature(MOB_KALEC, me->GetPositionX() + 10, me->GetPositionY() + 5, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
            {
                KalecGUID = Kalec->GetGUID();
                me->CombatStart(Kalec);
                me->AddThreat(Kalec, 100.0f);
                Kalec->setActive(true);
            }
            Talk(SAY_SATH_AGGRO);
        }

        void DamageTaken(Unit* done_by, uint32 &damage)
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void KilledUnit(Unit* target)
        {
            if (target->GetGUID() == KalecGUID)
            {
                TeleportAllPlayersBack();
                if (Creature* Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
                {
                    CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->TalkTimer = 1;
                    CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->isFriendly = false;
                }
                EnterEvadeMode();
                return;
            }
            Talk(SAY_SATH_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_SATH_DEATH);
            me->SetPosition(me->GetPositionX(), me->GetPositionY(), DRAGON_REALM_Z, me->GetOrientation());
            TeleportAllPlayersBack();
            if (Creature* Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
            {
                CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->TalkTimer = 1;
                CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->isFriendly = true;
            }

            if (instance)
                instance->SetData(DATA_KALECGOS_EVENT, DONE);
        }

        void TeleportAllPlayersBack()
        {
            Map* map = me->GetMap();
            if (!map->IsDungeon())
                return;

            Map::PlayerList const &PlayerList = map->GetPlayers();
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if (i->GetSource()->GetPositionZ() <= DRAGON_REALM_Z-5)
                {
                    i->GetSource()->RemoveAura(AURA_SPECTRAL_REALM);
                    i->GetSource()->TeleportTo(me->GetMap()->GetId(), i->GetSource()->GetPositionX(), i->GetSource()->GetPositionY(), DRAGON_REALM_Z+5, i->GetSource()->GetOrientation());
                }
            }
        }

        void DoAction(int32 param)
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

        void UpdateAI(uint32 diff)
        {
            if (!me->HasAura(AURA_SPECTRAL_INVISIBILITY))
                me->CastSpell(me, AURA_SPECTRAL_INVISIBILITY, true);
            if (!UpdateVictim())
                return;

            if (CheckTimer <= diff)
            {
                Creature* Kalec = Unit::GetCreature(*me, KalecGUID);
                if (!Kalec || !Kalec->IsAlive())
                {
                    if (Creature* Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
                        Kalecgos->AI()->EnterEvadeMode();
                    return;
                }

                if (HealthBelowPct(10) && !isEnraged)
                {
                    if (Creature* Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
                        Kalecgos->AI()->DoAction(DO_ENRAGE);
                    DoAction(DO_ENRAGE);
                }

                Creature* Kalecgos = Unit::GetCreature(*me, KalecgosGUID);
                if (Kalecgos && !Kalecgos->IsInCombat())
                {
                    me->AI()->EnterEvadeMode();
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
                        me->MonsterTextEmote(EMOTE_UNABLE_TO_FIND, 0);
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
                    if (Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                        if (unit->GetPositionZ() > me->GetPositionZ() + 5)
                            me->getThreatManager().modifyThreatPercent(unit, -100);
                }
                ResetThreat = 1000;
            } else ResetThreat -= diff;

            if (ShadowBoltTimer <= diff)
            {
                if (!(rand()%5))Talk(SAY_SATH_SPELL1);
                DoCast(me, SPELL_SHADOW_BOLT);
                ShadowBoltTimer = 7000+(rand()%3000);
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
                if (!(rand()%5))Talk(SAY_SATH_SPELL2);
                DoCast(me->GetVictim(), SPELL_CORRUPTION_STRIKE);
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

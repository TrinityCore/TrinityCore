/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "sunwell_plateau.h"

enum Yells
{
    //Kalecgos dragon form
    SAY_EVIL_AGGRO                               = -1580000,
    SAY_EVIL_SPELL1                              = -1580001,
    SAY_EVIL_SPELL2                              = -1580002,
    SAY_EVIL_SLAY1                               = -1580003,
    SAY_EVIL_SLAY2                               = -1580004,
    SAY_EVIL_ENRAGE                              = -1580005,

    //Kalecgos humanoid form
    SAY_GOOD_AGGRO                               = -1580006,
    SAY_GOOD_NEAR_DEATH                          = -1580007,
    SAY_GOOD_NEAR_DEATH2                         = -1580008,
    SAY_GOOD_PLRWIN                              = -1580009,

    //Sathrovarr
    SAY_SATH_AGGRO                               = -1580010,
    SAY_SATH_DEATH                               = -1580011,
    SAY_SATH_SPELL1                              = -1580012,
    SAY_SATH_SPELL2                              = -1580013,
    SAY_SATH_SLAY1                               = -1580014,
    SAY_SATH_SLAY2                               = -1580015,
    SAY_SATH_ENRAGE                              = -1580016,
};

enum Spells
{
    AURA_SUNWELL_RADIANCE                        = 45769,
    AURA_SPECTRAL_EXHAUSTION                     = 44867,
    AURA_SPECTRAL_REALM                          = 46021,
    AURA_SPECTRAL_INVISIBILITY                   = 44801,
    AURA_DEMONIC_VISUAL                          = 44800,

    SPELL_SPECTRAL_BLAST                         = 44869,
    SPELL_TELEPORT_SPECTRAL                      = 46019,
    SPELL_ARCANE_BUFFET                          = 45018,
    SPELL_FROST_BREATH                           = 44799,
    SPELL_TAIL_LASH                              = 45122,

    SPELL_BANISH                                 = 44836,
    SPELL_TRANSFORM_KALEC                        = 44670,
    SPELL_ENRAGE                                 = 44807,

    SPELL_CORRUPTION_STRIKE                      = 45029,
    SPELL_AGONY_CURSE                            = 45032,
    SPELL_SHADOW_BOLT                            = 45031,

    SPELL_HEROIC_STRIKE                          = 45026,
    SPELL_REVITALIZE                             = 45027
};

enum SWPActions
{
    DO_ENRAGE                                    =  1,
    DO_BANISH                                    =  2,
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kalecgosAI (pCreature);
    }

    struct boss_kalecgosAI : public ScriptedAI
    {
        boss_kalecgosAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            SathGUID = 0;
            DoorGUID = 0;
            bJustReset = false;
            me->setActive(true);
            SpellEntry *TempSpell = GET_SPELL(SPELL_SPECTRAL_BLAST);
            if (TempSpell)
                TempSpell->EffectImplicitTargetB[0] = TARGET_UNIT_TARGET_ENEMY;
        }

        InstanceScript *pInstance;

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
            if (pInstance)
            {
                SathGUID = pInstance->GetData64(DATA_SATHROVARR);
                pInstance->SetData(DATA_KALECGOS_EVENT, NOT_STARTED);
            }

            if (Creature *Sath = Unit::GetCreature(*me, SathGUID))
                Sath->AI()->EnterEvadeMode();

            me->setFaction(14);
            if (!bJustReset) //first reset at create
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->SetVisibility(VISIBILITY_ON);
                me->SetStandState(UNIT_STAND_STATE_SLEEP);
            }
            me->SetFullHealth();//dunno why it does not resets health at evade..
            ArcaneBuffetTimer = 8000;
            FrostBreathTimer = 15000;
            WildMagicTimer = 10000;
            TailLashTimer = 25000;
            SpectralBlastTimer = urand(20000,25000);
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
            me->SetVisibility(VISIBILITY_OFF);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            ScriptedAI::EnterEvadeMode();
        }

        void DoAction(const int32 param)
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

        void UpdateAI(const uint32 diff)
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
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SetVisibility(VISIBILITY_ON);
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
                            sLog.outError("TSCR: Didn't find Shathrowar. Kalecgos event reseted.");
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
                    std::list<HostileReference*> &m_threatlist = me->getThreatManager().getThreatList();
                    std::list<Unit*> targetList;
                    for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                        if ((*itr)->getTarget() && (*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER && (*itr)->getTarget()->GetGUID() != me->getVictim()->GetGUID() && !(*itr)->getTarget()->HasAura(AURA_SPECTRAL_EXHAUSTION) && (*itr)->getTarget()->GetPositionZ() > me->GetPositionZ()-5)
                            targetList.push_back((*itr)->getTarget());
                    if (targetList.empty())
                    {
                        SpectralBlastTimer = 1000;
                        return;
                    }
                    std::list<Unit*>::const_iterator i = targetList.begin();
                    advance(i, rand()%targetList.size());
                    if ((*i))
                    {
                        (*i)->CastSpell((*i), SPELL_SPECTRAL_BLAST,true);
                        SpectralBlastTimer = 20000+rand()%5000;
                    } else SpectralBlastTimer = 1000;
                } else SpectralBlastTimer -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (bJustReset)//boss is invisible, don't attack
                return;

            if (!me->getVictim() && who->isTargetableForAttack() && (me->IsHostileTo(who)))
            {
                float attackRadius = me->GetAttackDistance(who);
                if (me->IsWithinDistInMap(who, attackRadius))
                    AttackStart(who);
            }
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoScriptText(SAY_EVIL_AGGRO, me);
            DoZoneInCombat();

            if (pInstance)
                pInstance->SetData(DATA_KALECGOS_EVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_EVIL_SLAY1,SAY_EVIL_SLAY2), me);
        }

        void MovementInform(uint32 type,uint32 /*id*/)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            me->SetVisibility(VISIBILITY_OFF);
            if (isFriendly)
            {
                me->setDeathState(JUST_DIED);

                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* pPlayer = itr->getSource();
                        if (pPlayer)
                            me->GetMap()->ToInstanceMap()->PermBindAllPlayers(pPlayer);
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
            switch(TalkSequence)
            {
            case 1:
                me->setFaction(35);
                TalkTimer = 1000;
                break;
            case 2:
                DoScriptText(SAY_GOOD_PLRWIN, me);
                TalkTimer = 10000;
                break;
            case 3:
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->GetMotionMaster()->MovePoint(0,FLY_X,FLY_Y,FLY_Z);
                TalkTimer = 600000;
                break;
            default:
                break;
            }
        }

        void BadEnding()
        {
            switch(TalkSequence)
            {
            case 1:
                DoScriptText(SAY_EVIL_ENRAGE, me);
                TalkTimer = 3000;
                break;
            case 2:
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                me->GetMotionMaster()->MovePoint(0,FLY_X,FLY_Y,FLY_Z);
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kalecAI (pCreature);
    }

    struct boss_kalecAI : public ScriptedAI
    {
        InstanceScript *pInstance;

        uint32 RevitalizeTimer;
        uint32 HeroicStrikeTimer;
        uint32 YellTimer;
        uint32 YellSequence;

        uint64 SathGUID;

        bool isEnraged; // if demon is enraged

        boss_kalecAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        void Reset()
        {
            if (pInstance)
                SathGUID = pInstance->GetData64(DATA_SATHROVARR);

            RevitalizeTimer = 5000;
            HeroicStrikeTimer = 3000;
            YellTimer = 5000;
            YellSequence = 0;

            isEnraged = false;
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (done_by->GetGUID() != SathGUID)
                damage = 0;
            else if (isEnraged)
                damage *= 3;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->HasAura(AURA_SPECTRAL_INVISIBILITY))
                me->CastSpell(me, AURA_SPECTRAL_INVISIBILITY, true);
            if (!UpdateVictim())
                return;

            if (YellTimer <= diff)
            {
                switch(YellSequence)
                {
                case 0:
                    DoScriptText(SAY_GOOD_AGGRO, me);
                    ++YellSequence;
                    break;
                case 1:
                    if (HealthBelowPct(50))
                    {
                        DoScriptText(SAY_GOOD_NEAR_DEATH, me);
                        ++YellSequence;
                    }
                    break;
                case 2:
                    if (HealthBelowPct(10))
                    {
                        DoScriptText(SAY_GOOD_NEAR_DEATH2, me);
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
                DoCast(me->getVictim(), SPELL_HEROIC_STRIKE);
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

    bool OnGossipHello(Player* pPlayer, GameObject* pGo)
    {
        uint8 SpectralPlayers = 0;
        Map* pMap = pGo->GetMap();
        if (!pMap->IsDungeon())
            return true;

        Map::PlayerList const &PlayerList = pMap->GetPlayers();
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        {
            if (i->getSource() && i->getSource()->GetPositionZ() < DEMON_REALM_Z + 5)
                ++SpectralPlayers;
        }
        uint8 MaxSpectralPlayers =  MAX_PLAYERS_IN_SPECTRAL_REALM;
        if (pPlayer->HasAura(AURA_SPECTRAL_EXHAUSTION) || (MaxSpectralPlayers && SpectralPlayers >= MaxSpectralPlayers))
            pPlayer->GetSession()->SendNotification(GO_FAILED);
        else
            pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_SPECTRAL, true);
        return true;
    }

};

class boss_sathrovarr : public CreatureScript
{
public:
    boss_sathrovarr() : CreatureScript("boss_sathrovarr") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sathrovarrAI (pCreature);
    }

    struct boss_sathrovarrAI : public ScriptedAI
    {
        boss_sathrovarrAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            KalecGUID = 0;
            KalecgosGUID = 0;
        }

        InstanceScript *pInstance;

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
            if (pInstance)
            {
                KalecgosGUID = pInstance->GetData64(DATA_KALECGOS_DRAGON);
                pInstance->SetData(DATA_KALECGOS_EVENT, NOT_STARTED);
            }
            if (KalecGUID)
            {
                if (Creature* Kalec = Unit::GetCreature(*me, KalecGUID))
                    Kalec->setDeathState(JUST_DIED);
                KalecGUID = 0;
            }

            ShadowBoltTimer = 7000 + rand()%3 * 1000;
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
            if (Creature *Kalec = me->SummonCreature(MOB_KALEC, me->GetPositionX() + 10, me->GetPositionY() + 5, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
            {
                KalecGUID = Kalec->GetGUID();
                me->CombatStart(Kalec);
                me->AddThreat(Kalec, 100.0f);
                Kalec->setActive(true);
            }
            DoScriptText(SAY_SATH_AGGRO, me);
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if (damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void KilledUnit(Unit *pTarget)
        {
            if (pTarget->GetGUID() == KalecGUID)
            {
                TeleportAllPlayersBack();
                if (Creature *Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
                {
                    CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->TalkTimer = 1;
                    CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->isFriendly = false;
                }
                EnterEvadeMode();
                return;
            }
            DoScriptText(RAND(SAY_SATH_SLAY1,SAY_SATH_SLAY2), me);
        }

        void JustDied(Unit * /*killer*/)
        {
            DoScriptText(SAY_SATH_DEATH, me);
            me->GetMap()->CreatureRelocation(me, me->GetPositionX(), me->GetPositionY(), DRAGON_REALM_Z, me->GetOrientation());
            TeleportAllPlayersBack();
            if (Creature *Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
            {
                CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->TalkTimer = 1;
                CAST_AI(boss_kalecgos::boss_kalecgosAI, Kalecgos->AI())->isFriendly = true;
            }

            if (pInstance)
                pInstance->SetData(DATA_KALECGOS_EVENT, DONE);
        }

        void TeleportAllPlayersBack()
        {
            Map* pMap = me->GetMap();
            if (!pMap->IsDungeon()) return;
            Map::PlayerList const &PlayerList = pMap->GetPlayers();
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if (i->getSource()->GetPositionZ() <= DRAGON_REALM_Z-5)
                {
                    i->getSource()->RemoveAura(AURA_SPECTRAL_REALM);
                    i->getSource()->TeleportTo(me->GetMap()->GetId(),i->getSource()->GetPositionX(),i->getSource()->GetPositionY(),DRAGON_REALM_Z+5,i->getSource()->GetOrientation());
                }
            }
        }

        void DoAction(const int32 param)
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

        void UpdateAI(const uint32 diff)
        {
            if (!me->HasAura(AURA_SPECTRAL_INVISIBILITY))
                me->CastSpell(me, AURA_SPECTRAL_INVISIBILITY, true);
            if (!UpdateVictim())
                return;

            if (CheckTimer <= diff)
            {
                Creature *Kalec = Unit::GetCreature(*me, KalecGUID);
                if (!Kalec || (Kalec && !Kalec->isAlive()))
                {
                    if (Creature *Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
                        Kalecgos->AI()->EnterEvadeMode();
                        return;
                }
                if (HealthBelowPct(10) && !isEnraged)
                {
                    if (Creature* Kalecgos = Unit::GetCreature(*me, KalecgosGUID))
                        Kalecgos->AI()->DoAction(DO_ENRAGE);
                    DoAction(DO_ENRAGE);
                }
                Creature *Kalecgos = Unit::GetCreature(*me, KalecgosGUID);
                if (Kalecgos)
                {
                    if (!Kalecgos->isInCombat())
                    {
                        me->AI()->EnterEvadeMode();
                        return;
                    }
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
                        else
                            DoAction(DO_BANISH);
                    }
                    else
                    {
                        me->MonsterTextEmote(EMOTE_UNABLE_TO_FIND, NULL);
                        EnterEvadeMode();
                        return;
                    }
                }
                CheckTimer = 1000;
            } else CheckTimer -= diff;

            if (ResetThreat <= diff)
            {
                for (std::list<HostileReference*>::const_iterator itr = me->getThreatManager().getThreatList().begin(); itr != me->getThreatManager().getThreatList().end(); ++itr)
                {
                    if (Unit* pUnit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                    {
                        if (pUnit->GetPositionZ() > me->GetPositionZ()+5)
                        {
                            me->getThreatManager().modifyThreatPercent(pUnit,-100);
                        }
                    }
                }
                ResetThreat = 1000;
            } else ResetThreat -= diff;

            if (ShadowBoltTimer <= diff)
            {
                if (!(rand()%5))DoScriptText(SAY_SATH_SPELL1, me);
                DoCast(me, SPELL_SHADOW_BOLT);
                ShadowBoltTimer = 7000+(rand()%3000);
            } else ShadowBoltTimer -= diff;

            if (AgonyCurseTimer <= diff)
            {
                Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (!pTarget) pTarget = me->getVictim();
                DoCast(pTarget, SPELL_AGONY_CURSE);
                AgonyCurseTimer = 20000;
            } else AgonyCurseTimer -= diff;

            if (CorruptionStrikeTimer <= diff)
            {
                if (!(rand()%5))DoScriptText(SAY_SATH_SPELL2, me);
                DoCast(me->getVictim(), SPELL_CORRUPTION_STRIKE);
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

/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

enum Quotes
{
    //Kalecgos dragon form
    SAY_EVIL_AGGRO          = -1580000,
    SAY_EVIL_SPELL1         = -1580001,
    SAY_EVIL_SPELL2         = -1580002,
    SAY_EVIL_SLAY1          = -1580003,
    SAY_EVIL_SLAY2          = -1580004,
    SAY_EVIL_ENRAGE         = -1580005,

    //Kalecgos humanoid form
    SAY_GOOD_AGGRO          = -1580006,
    SAY_GOOD_NEAR_DEATH     = -1580007,
    SAY_GOOD_NEAR_DEATH2    = -1580008,
    SAY_GOOD_PLRWIN         = -1580009,

    //Shattrowar
    SAY_SATH_AGGRO          = -1580010,
    SAY_SATH_DEATH          = -1580011,
    SAY_SATH_SPELL1         = -1580012,
    SAY_SATH_SPELL2         = -1580013,
    SAY_SATH_SLAY1          = -1580014,
    SAY_SATH_SLAY2          = -1580015,
    SAY_SATH_ENRAGE         = -1580016
};

enum SpellIds
{
    AURA_SUNWELL_RADIANCE       =   45769,
    AURA_SPECTRAL_EXHAUSTION    =   44867,
    AURA_SPECTRAL_REALM         =   46021,
    AURA_SPECTRAL_INVISIBILITY  =   44801,
    AURA_DEMONIC_VISUAL         =   44800,

    SPELL_SPECTRAL_BLAST        =   44869,
    SPELL_TELEPORT_SPECTRAL     =   46019,
    SPELL_ARCANE_BUFFET         =   45018,
    SPELL_FROST_BREATH          =   44799,
    SPELL_TAIL_LASH             =   45122,

    SPELL_BANISH                =   44836,
    SPELL_TRANSFORM_KALEC       =   44670,
    SPELL_ENRAGE                =   44807,

    SPELL_CORRUPTION_STRIKE     =   45029,
    SPELL_AGONY_CURSE           =   45032,
    SPELL_SHADOW_BOLT           =   45031,

    SPELL_HEROIC_STRIKE         =   45026,
    SPELL_REVITALIZE            =   45027
};

enum Kalecgos_Creatures
{
    //MOB_KALECGOS    =  24850,
    //MOB_KALEC       =  24891,
    //MOB_SATHROVARR  =  24892
};

#define GO_FAILED   "You are unable to use this currently."

#define FLY_X   1679
#define FLY_Y   900
#define FLY_Z   82

#define CENTER_X    1705
#define CENTER_Y    930
#define RADIUS      30

#define DRAGON_REALM_Z  53.079f
#define DEMON_REALM_Z   -74.558f

uint32 WildMagic[]= { 44978, 45001, 45002, 45004, 45006, 45010 };

class boss_kalecgos : public CreatureScript
{
public:
    boss_kalecgos() : CreatureScript("boss_kalecgos") {}

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
        uint32 Close_Timer;
        uint32 ResetThreat;

        bool isFriendly;
        bool isEnraged;
        bool isBanished;
        bool doorClosed;

        uint64 SathGUID;

        void Reset()
        {
            if(pInstance)
            {
                SathGUID = pInstance->GetData64(DATA_SATHROVARR);

                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_FORECEFIELD_COLL_1),true);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_FORECEFIELD_COLL_2),true);
            }

            Unit *Sath = Unit::GetUnit(*me,SathGUID);
            if(Sath) ((Creature*)Sath)->AI()->EnterEvadeMode();


            me->setFaction(14);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            me->SetVisible(true);
            me->SetStandState(UNIT_STAND_STATE_SLEEP);

            ArcaneBuffetTimer = 8000;
            FrostBreathTimer = 15000;
            WildMagicTimer = 10000;
            TailLashTimer = 25000;
            SpectralBlastTimer = 20000+(rand()%5000);
            CheckTimer = SpectralBlastTimer+20000; //after spectral blast
            doorClosed = false;
            Close_Timer = 10000;
            ResetThreat  = 1000;

            TalkTimer = 0;
            TalkSequence = 0;
            isFriendly = false;
            isEnraged = false;
            isBanished = false;
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if(damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->SetStandState(UNIT_STAND_STATE_STAND);
            DoScriptText(SAY_EVIL_AGGRO, me);
            DoZoneInCombat();

            if(pInstance)
                pInstance->SetData(DATA_KALECGOS_EVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(SAY_EVIL_SLAY1, me); break;
            case 1: DoScriptText(SAY_EVIL_SLAY2, me); break;
            }
        }

        void MovementInform(uint32 type,uint32 id)
        {
            if(type != POINT_MOTION_TYPE)
                return;

            if(id != 1)
                return;

            me->SetVisible(false);
            if(isFriendly)
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
                TalkTimer = 30000;
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
                me->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(1,FLY_X,FLY_Y,FLY_Z);
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
                me->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(1,FLY_X,FLY_Y,FLY_Z);
                TalkTimer = 600000;
                break;
            case 3:
                EnterEvadeMode();
                break;
            default:
                break;
            }
        }

        bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
        {
            if(me->IsNonMeleeSpellCasted(false)) return false;

            DoCast(victim,spellId,triggered);
            return true;
        }

        bool TryDoCastAOE(uint32 spellId, bool triggered = false)
        {
            if(me->IsNonMeleeSpellCasted(false)) return false;

            DoCastAOE(spellId,triggered);
            return true;
        }

        void UpdateAI(const uint32 diff);
    };
};

class boss_sathrovarr : public CreatureScript
{
public:
    boss_sathrovarr() : CreatureScript("boss_sathrovarr") {}

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
            if(pInstance)
                KalecgosGUID = pInstance->GetData64(DATA_KALECGOS_DRAGON);

            if(KalecGUID)
            {
                if(Unit* Kalec = Unit::GetUnit(*me, KalecGUID))
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

            if(pInstance)
                pInstance->SetData(DATA_KALECGOS_EVENT, NOT_STARTED);

            DoCast(me,AURA_SPECTRAL_INVISIBILITY,true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Creature *Kalec = me->SummonCreature(MOB_KALEC, me->GetPositionX() + 10, me->GetPositionY() + 5, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);
            if(Kalec)
            {
                Kalec->CastSpell(Kalec,AURA_SPECTRAL_INVISIBILITY,true);
                KalecGUID = Kalec->GetGUID();
                me->CombatStart(Kalec);
                me->AddThreat(Kalec, 100.0f);
            }
            DoScriptText(SAY_SATH_AGGRO, me);
        }

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if(damage >= me->GetHealth() && done_by != me)
                damage = 0;
        }

        void KilledUnit(Unit *target)
        {
            if(target->GetGUID() == KalecGUID)
            {
                TeleportAllPlayersBack();
                if(Unit *Kalecgos = Unit::GetUnit(*me, KalecgosGUID))
                {
                    CAST_AI(boss_kalecgos::boss_kalecgosAI,((Creature*)Kalecgos)->AI())->TalkTimer = 1;
                    CAST_AI(boss_kalecgos::boss_kalecgosAI,((Creature*)Kalecgos)->AI())->isFriendly = false;
                }
                EnterEvadeMode();
                return;
            }
            switch(rand()%2)
            {
            case 0: DoScriptText(SAY_SATH_SLAY1, me); break;
            case 1: DoScriptText(SAY_SATH_SLAY2, me); break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_SATH_DEATH, me);
            me->Relocate(me->GetPositionX(), me->GetPositionY(), DRAGON_REALM_Z, me->GetOrientation());
            me->RemoveAurasDueToSpell(AURA_SPECTRAL_INVISIBILITY);
            TeleportAllPlayersBack();
            if(Unit *Kalecgos = Unit::GetUnit(*me, KalecgosGUID))
            {
                CAST_AI(boss_kalecgos::boss_kalecgosAI,((Creature*)Kalecgos)->AI())->TalkTimer = 1;
                CAST_AI(boss_kalecgos::boss_kalecgosAI,((Creature*)Kalecgos)->AI())->isFriendly = true;
            }

            if(pInstance)
                pInstance->SetData(DATA_KALECGOS_EVENT, DONE);
        }

        void TeleportAllPlayersBack()
        {
            Map *map = me->GetMap();
            if(!map->IsDungeon()) return;
            Map::PlayerList const &PlayerList = map->GetPlayers();
            Map::PlayerList::const_iterator i;
            for(i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if(Player* i_pl = i->getSource())
                    if(i_pl->HasAuraEffect(AURA_SPECTRAL_REALM,0))
                        i_pl->RemoveAurasDueToSpell(AURA_SPECTRAL_REALM);
        }

        bool TryDoCast(Unit *victim, uint32 spellId, bool triggered = false)
        {
            if(me->IsNonMeleeSpellCasted(false)) return false;

            DoCast(victim,spellId,triggered);
            return true;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if(CheckTimer <= diff)
            {
                if (((me->GetHealth()*100 / me->GetMaxHealth()) < 10) && !isEnraged)
                {
                    Unit* Kalecgos = Unit::GetUnit(*me, KalecgosGUID);
                    if(Kalecgos)
                    {
                        Kalecgos->CastSpell(Kalecgos, SPELL_ENRAGE, true);
                        CAST_AI(boss_kalecgos::boss_kalecgosAI,((Creature*)Kalecgos)->AI())->isEnraged = true;
                    }
                    DoCast(me, SPELL_ENRAGE, true);
                    isEnraged = true;
                }

                if(!isBanished && (me->GetHealth()*100)/me->GetMaxHealth() < 1)
                {
                    if(Unit *Kalecgos = Unit::GetUnit(*me, KalecgosGUID))
                    {
                        if(CAST_AI(boss_kalecgos::boss_kalecgosAI,((Creature*)Kalecgos)->AI())->isBanished)
                        {
                            me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                            return;
                        }
                        else
                        {
                            DoCast(me, SPELL_BANISH);
                            isBanished = true;
                        }
                    }
                    else
                    {
                        sLog->outError("Sathrovarr is unable to find Kalecgos");
                        EnterEvadeMode();
                        return;
                    }
                }
                CheckTimer = 1000;
            }else CheckTimer -= diff;

            if(ResetThreat <= diff)
            {
                if ( ( me->getVictim()->HasAuraEffect(AURA_SPECTRAL_EXHAUSTION,0)) && (me->getVictim()->GetTypeId() == TYPEID_PLAYER) )
                {
                    for(std::list<HostileReference*>::iterator itr = me->getThreatManager().getThreatList().begin(); itr != me->getThreatManager().getThreatList().end(); ++itr)
                    {
                        if(((*itr)->getUnitGuid()) ==  (me->getVictim()->GetGUID()))
                        {
                            (*itr)->removeReference();
                            break;
                        }
                    }
                }
                ResetThreat = 1000;
            }else ResetThreat -= diff;

            if(ShadowBoltTimer <= diff)
            {
                if(TryDoCast(me, SPELL_SHADOW_BOLT))
                {
                    DoScriptText(SAY_SATH_SPELL1, me);
                    ShadowBoltTimer = 7000+(rand()%3000);
                }
            }else ShadowBoltTimer -= diff;

            if(AgonyCurseTimer <= diff)
            {
                Unit *ptarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if(!ptarget) ptarget = me->getVictim();
                if(TryDoCast(ptarget, SPELL_AGONY_CURSE))
                    AgonyCurseTimer = 20000;
            }else AgonyCurseTimer -= diff;

            if(CorruptionStrikeTimer <= diff)
            {
                if(TryDoCast(me->getVictim(), SPELL_CORRUPTION_STRIKE))
                {
                    DoScriptText(SAY_SATH_SPELL2, me);
                    CorruptionStrikeTimer = 13000;
                }
            }else CorruptionStrikeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

    void boss_kalecgos::boss_kalecgosAI::UpdateAI(const uint32 diff)
    {
        if(TalkTimer)
        {
            if(!TalkSequence)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                me->InterruptNonMeleeSpells(true);
                me->RemoveAllAuras();
                me->DeleteThreatList();
                me->CombatStop();
                TalkSequence++;

                if(pInstance)
                {
                    pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_FORECEFIELD_COLL_1),true);
                    pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_FORECEFIELD_COLL_2),true);
                }
            }
            if(TalkTimer <= diff)
            {
                if(isFriendly)
                    GoodEnding();
                else
                    BadEnding();
                TalkSequence++;
            }else TalkTimer -= diff;
        }
        else
        {
            if (!UpdateVictim())
                return;

            if(!doorClosed)
            {
                if(Close_Timer <= diff)
                {
                    if(pInstance)
                    {
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_FORECEFIELD_COLL_1),false);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_FORECEFIELD_COLL_2),false);
                        doorClosed = true;
                    }
                    Close_Timer = 10000;
                }else Close_Timer -= diff;
            }

            if(ResetThreat <= diff)
            {
                if ( ( me->getVictim()->HasAuraEffect(AURA_SPECTRAL_REALM,0)) && (me->getVictim()->GetTypeId() == TYPEID_PLAYER) )
                {
                    for(std::list<HostileReference*>::iterator itr = me->getThreatManager().getThreatList().begin(); itr != me->getThreatManager().getThreatList().end(); ++itr)
                    {
                        if(((*itr)->getUnitGuid()) ==  (me->getVictim()->GetGUID()))
                        {
                            (*itr)->removeReference();
                            break;
                        }
                    }
                }

                if(me->getVictim() && (me->getVictim()->HasAuraEffect(AURA_SPECTRAL_REALM,0) || me->GetPositionZ() < DRAGON_REALM_Z-10))
                    me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);

                ResetThreat = 1000;
            }else ResetThreat -= diff;

            if(CheckTimer <= diff)
                {
                    if (((me->GetHealth()*100 / me->GetMaxHealth()) < 10) && !isEnraged)
                    {
                        Unit* Sath = Unit::GetUnit(*me, SathGUID);
                        if(Sath)
                        {
                            Sath->CastSpell(Sath, SPELL_ENRAGE, true);
                            CAST_AI(boss_sathrovarr::boss_sathrovarrAI,((Creature*)Sath)->AI())->isEnraged = true;
                        }
                        DoCast(me, SPELL_ENRAGE, true);
                        isEnraged = true;
                    }

                    if(!isBanished && (me->GetHealth()*100)/me->GetMaxHealth() < 1)
                    {
                        if(Unit *Sath = Unit::GetUnit(*me, SathGUID))
                        {
                            if(CAST_AI(boss_sathrovarr::boss_sathrovarrAI,((Creature*)Sath)->AI())->isBanished)
                            {
                                Sath->DealDamage(Sath, Sath->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                                return;
                            }
                            else
                            {
                                DoCast(me, SPELL_BANISH);
                                isBanished = true;
                            }
                        }
                        else
                        {
                            sLog->outError("TSCR: Didn't find Shathrowar. Kalecgos event reseted.");
                            EnterEvadeMode();
                            return;
                        }
                    }
                    CheckTimer = 1000;
            }else CheckTimer -= diff;

            if(ArcaneBuffetTimer <= diff)
            {
                if(TryDoCastAOE(SPELL_ARCANE_BUFFET))
                    ArcaneBuffetTimer = 8000;
            }else ArcaneBuffetTimer -= diff;

            if(FrostBreathTimer <= diff)
            {
                if(TryDoCastAOE(SPELL_FROST_BREATH))
                    FrostBreathTimer = 15000;
            }else FrostBreathTimer -= diff;

            if(TailLashTimer <= diff)
            {
                if(TryDoCastAOE(SPELL_TAIL_LASH))
                    TailLashTimer = 15000;
            }else TailLashTimer -= diff;

            if(WildMagicTimer <= diff)
            {
                if(TryDoCastAOE(WildMagic[rand()%6]))
                    WildMagicTimer = 20000;
            }else WildMagicTimer -= diff;

            if(SpectralBlastTimer <= diff)
            {
                //this is a hack. we need to find a victim without aura in core
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
                if( target && target->isAlive() && !(target->HasAuraEffect(AURA_SPECTRAL_EXHAUSTION, 0)) )
                {
                    if(TryDoCast(target, SPELL_SPECTRAL_BLAST))
                        SpectralBlastTimer = 20000+(rand()%5000);
                }
                else
                {
                    SpectralBlastTimer = 1000;
                }
            }else SpectralBlastTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

class boss_kalec : public CreatureScript
{
public:
    boss_kalec() : CreatureScript("boss_kalec") {}

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

        boss_kalecAI(Creature *c) : ScriptedAI(c){
            pInstance = c->GetInstanceScript();
        }

        void Reset()
        {
            if(pInstance)
                SathGUID = pInstance->GetData64(DATA_SATHROVARR);

            RevitalizeTimer = 5000;
            HeroicStrikeTimer = 3000;
            YellTimer = 5000;
            YellSequence = 0;

            isEnraged = false;
        }

        void EnterCombat(Unit* who) {}

        void DamageTaken(Unit *done_by, uint32 &damage)
        {
            if(done_by->GetGUID() != SathGUID)
                damage = 0;
            else if(isEnraged)
                damage *= 3;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if(YellTimer <= diff)
            {
                switch(YellSequence)
                {
                case 0:
                    DoScriptText(SAY_GOOD_AGGRO, me);
                    YellSequence++;
                    break;
                case 1:
                    if((me->GetHealth()*100)/me->GetMaxHealth() < 50)
                    {
                        DoScriptText(SAY_GOOD_NEAR_DEATH, me);
                        YellSequence++;
                    }
                    break;
                case 2:
                    if((me->GetHealth()*100)/me->GetMaxHealth() < 10)
                    {
                        DoScriptText(SAY_GOOD_NEAR_DEATH2, me);
                        YellSequence++;
                    }
                    break;
                default:
                    break;
                }
                YellTimer = 5000;
            }

            if(RevitalizeTimer <= diff)
            {
                DoCast(me, SPELL_REVITALIZE);
                RevitalizeTimer = 5000;
            }else RevitalizeTimer -= diff;

            if(HeroicStrikeTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HEROIC_STRIKE);
                HeroicStrikeTimer = 2000;
            }else HeroicStrikeTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class kalecgos_teleporter : GameObjectScript
{
public:
    kalecgos_teleporter() : GameObjectScript("kalecgos_teleporter") {}

    bool OnGossipHello(Player *player, GameObject* _GO)
    {
        if(player->HasAuraEffect(AURA_SPECTRAL_EXHAUSTION, 0))
            player->GetSession()->SendNotification(GO_FAILED);
        else
            player->CastSpell(player, SPELL_TELEPORT_SPECTRAL, true);
        return true;
    }
};
void AddSC_boss_kalecgos()
{
    new boss_kalecgos();
    new boss_sathrovarr();
    new boss_kalec();
    new kalecgos_teleporter();
}

/* Copyright ?2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/* ScriptData
SDName: Boss_Kalecgos
SD%Complete: 0
SDComment: VERIFY SCRIPT
EndScriptData */

#include "precompiled.h"
#include "def_sunwell_plateau.h"

#define KALECGOS_SAY_AGGRO             "No longer will I be a slave to Malygos! Challenge me and you will be destroyed!"
#define KALECGOS_SOUND_AGGRO           12422
#define KALECGOS_SAY_SPELL_1           "I will purge you!"
#define KALECGOS_SOUND_SPELL_1         12423
#define KALECGOS_SAY_SPELL_2           "Your pain has only begun!"
#define KALECGOS_SOUND_SPELL_2         12424
#define KALECGOS_SAY_KILL_1            "In the name of Kil'jaeden!"
#define KALECGOS_SOUND_KILL_1          12425
#define KALECGOS_SAY_KILL_2            "You were warned!"
#define KALECGOS_SOUND_KILL_2          12426
#define KALECGOS_SAY_FLY_AWAY          "My awakening is complete! You shall all perish!"
#define KALECGOS_SOUND_FLY_AWAY        12427
#define KALECGOS_SAY_WIN               "I am forever in your debt. Once we have triumphed over Kil'jaeden, this entire world will be in your debt as well."
#define KALECGOS_SOUND_WIN             12431

#define SATH_SAY_AGGRO           "Gyahaha... There will be no reprieve. My work here is nearly finished."
#define SATH_SOUND_AGGRO         12451
#define SATH_SAY_DIE             "I'm... never on... the losing... side..."
#define SATH_SOUND_DIE           12452
#define SATH_SAY_SPELL_1         "Your misery is my delight!"
#define SATH_SOUND_SPELL_1       12453
#define SATH_SAY_SPELL_2         "I will watch you bleed!"
#define SATH_SOUND_SPELL_2       12454
#define SATH_SAY_KILL_1          "Pitious mortal!"
#define SATH_SOUND_KILL_1        12455
#define SATH_SAY_KILL_2          "Haven't you heard? I always win!"
#define SATH_SOUND_KILL_2        12456
#define SATH_SAY_ENRAGE          "I have toyed with you long enough!"
#define SATH_SOUND_ENRAGE        12457

#define KALEC_SAY_AGGRO         "I need... your help... Cannot... resist him... much longer..."
#define KALEC_SOUND_AGGRO       12428
#define KALEC_SAY_LOSING1       "Aaahhh! Help me, before I lose my mind!"
#define KALEC_SOUND_LOSING1     12429
#define KALEC_SAY_LOSING2       "Hurry! There is not much of me left!" //???
#define KALEC_SOUND_LOSING2     12430

#define GO_FAILED               "You are unable to use this currently."

#define FLY_X       1679
#define FLY_Y       900
#define FLY_Z       82

#define CENTER_X    1705
#define CENTER_Y    930
#define RADIUS      30

#define AURA_SUNWELL_RADIANCE           45769
#define AURA_SPECTRAL_EXHAUSTION        44867
#define AURA_SPECTRAL_REALM             46021
#define AURA_SPECTRAL_INVISIBILITY      44801
#define AURA_DEMONIC_VISUAL             44800

#define SPELL_SPECTRAL_BLAST            44869
#define SPELL_TELEPORT_SPECTRAL         46019
#define SPELL_ARCANE_BUFFET             45018
#define SPELL_FROST_BREATH              44799
#define SPELL_TAIL_LASH                 45122

#define SPELL_BANISH                    44836
#define SPELL_TRANSFORM_KALEC           44670
#define SPELL_ENRAGE                    44807

#define SPELL_CORRUPTION_STRIKE         45029
#define SPELL_AGONY_CURSE               45032
#define SPELL_SHADOW_BOLT               45031

#define SPELL_HEROIC_STRIKE             45026
#define SPELL_REVITALIZE                45027

#define MOB_KALECGOS    24850
#define MOB_KALEC       24891
#define MOB_SATHROVARR  24892

#define DRAGON_REALM_Z  53.079
#define DEMON_REALM_Z   -74.558

uint32 WildMagic[]= { 44978, 45001, 45002, 45004, 45006, 45010 };


struct TRINITY_DLL_DECL boss_kalecgosAI : public ScriptedAI
{
    boss_kalecgosAI(Creature *c) : ScriptedAI(c) 
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        SathGUID = 0;
        DoorGUID = 0;
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 ArcaneBuffetTimer;
    uint32 FrostBreathTimer;
    uint32 WildMagicTimer;
    uint32 SpectralBlastTimer;
    uint32 TailLashTimer;
    uint32 CheckTimer;
    uint32 TalkTimer;
    uint32 TalkSequence;

    bool isFriendly;
    bool isEnraged;
    bool isBanished;

    uint64 SathGUID;
    uint64 DoorGUID;

    void Reset()
    {
        if(pInstance)
        {
            uint64 SathGUID = pInstance->GetData64(DATA_SATHROVARR);
            uint64 DoorGUID = pInstance->GetData64(DATA_GO_FORCEFIELD);
        }

        Unit *Sath = Unit::GetUnit(*m_creature,SathGUID);
        if(Sath) ((Creature*)Sath)->AI()->EnterEvadeMode();

        GameObject *Door = GameObject::GetGameObject(*m_creature, DoorGUID);
        if(Door) Door->SetLootState(GO_JUST_DEACTIVATED);

        m_creature->setFaction(14);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->SetStandState(PLAYER_STATE_SLEEP);

        ArcaneBuffetTimer = 8000;
        FrostBreathTimer = 15000;
        WildMagicTimer = 10000;
        TailLashTimer = 25000;
        SpectralBlastTimer = 20000+(rand()%5000);
        CheckTimer = SpectralBlastTimer+20000; //after spectral blast

        TalkTimer = 0;
        TalkSequence = 0;
        isFriendly = false;
        isEnraged = false;
        isBanished = false;
        //m_creature->CastSpell(m_creature, AURA_SUNWELL_RADIANCE, true);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth() && done_by != m_creature)
            damage = 0;
    }

    void Aggro(Unit* who)
    {
        m_creature->SetStandState(PLAYER_STATE_NONE);
        DoYell(KALECGOS_SAY_AGGRO, LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, KALECGOS_SOUND_AGGRO);
        GameObject *Door = GameObject::GetGameObject(*m_creature, DoorGUID);
        if(Door) Door->SetLootState(GO_ACTIVATED);
        DoZoneInCombat();
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
        case 0:
            DoYell(KALECGOS_SAY_KILL_1,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,KALECGOS_SOUND_KILL_1);
            break;
        case 1:
            DoYell(KALECGOS_SAY_KILL_2,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,KALECGOS_SOUND_KILL_2);
            break;
        }
    }

    void MovementInform(uint32 type,uint32 id)
    {
        m_creature->SetVisibility(VISIBILITY_OFF);
        if(isFriendly)
            m_creature->setDeathState(JUST_DIED);
        else
        {
            m_creature->GetMotionMaster()->MoveTargetedHome();
            TalkTimer = 30000;
        }
    }

    void GoodEnding()
    {
        switch(TalkSequence)
        {
        case 1:
            m_creature->setFaction(35);
            DoCast(m_creature, SPELL_TRANSFORM_KALEC);
            TalkTimer = 1000;
            break;
        case 2:
            DoSay(KALECGOS_SAY_WIN, LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature, KALECGOS_SOUND_WIN);
            TalkTimer = 10000;
            break;
        case 3:
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MovePoint(0,FLY_X,FLY_Y,FLY_Z);
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
            DoYell(KALECGOS_SAY_FLY_AWAY,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,KALECGOS_SOUND_FLY_AWAY);
            TalkTimer = 3000;
            break;
        case 2:
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MovePoint(0,FLY_X,FLY_Y,FLY_Z);
            TalkTimer = 600000;
            break;
        case 3:
            EnterEvadeMode();
            break;
        default:
            break;
        }
    }

    void UpdateAI(const uint32 diff);
};

struct TRINITY_DLL_DECL boss_sathrovarrAI : public ScriptedAI
{
    boss_sathrovarrAI(Creature *c) : ScriptedAI(c) 
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        KalecGUID = 0;
        KalecgosGUID = 0;
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 CorruptionStrikeTimer;
    uint32 AgonyCurseTimer;
    uint32 ShadowBoltTimer;
    uint32 CheckTimer;

    uint64 KalecGUID;
    uint64 KalecgosGUID;

    bool isEnraged;
    bool isBanished;

    void Reset()
    {
        if(pInstance)
            KalecgosGUID = pInstance->GetData64(DATA_KALECGOS_DRAGON);

        if(KalecGUID)
        {
            if(Unit* Kalec = Unit::GetUnit(*m_creature, KalecGUID))
                Kalec->setDeathState(JUST_DIED);
            KalecGUID = 0;
        }

        ShadowBoltTimer = 7000 + rand()%3 * 1000;
        AgonyCurseTimer = 20000;
        CorruptionStrikeTimer = 13000;
        CheckTimer = 1000;
        isEnraged = false;
        isBanished = false;
        //m_creature->CastSpell(m_creature, AURA_SPECTRAL_INVISIBILITY, true);
        //m_creature->CastSpell(m_creature, AURA_SUNWELL_RADIANCE, true);
        //m_creature->CastSpell(m_creature, AURA_DEMONIC_VISUAL, true);
    }

    void Aggro(Unit* who)
    {
        Creature *Kalec = m_creature->SummonCreature(MOB_KALEC, m_creature->GetPositionX() + 10, m_creature->GetPositionY() + 5, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);
        if(Kalec)
        {
            KalecGUID = Kalec->GetGUID();
            m_creature->CombatStart(Kalec);
            m_creature->AddThreat(Kalec, 100.0f);
        }
        DoYell(SATH_SAY_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SATH_SOUND_AGGRO);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth() && done_by != m_creature)
            damage = 0;
    }

    void KilledUnit(Unit *target)
    {
        if(target->GetGUID() == KalecGUID)
        {
            TeleportAllPlayersBack();
            if(Unit *Kalecgos = Unit::GetUnit(*m_creature, KalecgosGUID))
            {
                ((boss_kalecgosAI*)((Creature*)Kalecgos)->AI())->TalkTimer = 1;
                ((boss_kalecgosAI*)((Creature*)Kalecgos)->AI())->isFriendly = false;
            }
            EnterEvadeMode();
            return;
        }
        switch(rand()%2)
        {
        case 0:
            DoYell(SATH_SAY_KILL_1,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SATH_SOUND_KILL_1);
            break;
        case 1:
            DoYell(SATH_SAY_KILL_2,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SATH_SOUND_KILL_2);
            break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoYell(SATH_SAY_DIE, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SATH_SOUND_DIE);
        m_creature->Relocate(m_creature->GetPositionX(), m_creature->GetPositionY(), DRAGON_REALM_Z, m_creature->GetOrientation());
        TeleportAllPlayersBack();
        if(Unit *Kalecgos = Unit::GetUnit(*m_creature, KalecgosGUID))
        {
            ((boss_kalecgosAI*)((Creature*)Kalecgos)->AI())->TalkTimer = 1;
            ((boss_kalecgosAI*)((Creature*)Kalecgos)->AI())->isFriendly = true;
        }
    }

    void TeleportAllPlayersBack()
    {
        Map *map = m_creature->GetMap();
        if(!map->IsDungeon()) return;
        Map::PlayerList const &PlayerList = map->GetPlayers();
        Map::PlayerList::const_iterator i;
        for(i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if(Player* i_pl = i->getSource())
                if(i_pl->HasAura(AURA_SPECTRAL_REALM,0))
                    i_pl->RemoveAurasDueToSpell(AURA_SPECTRAL_REALM);
    }

    void Enrage(); // demon and dragon should enrage at the same time

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() && !m_creature->getVictim())
            return;	

        if(CheckTimer < diff)
        {
            if(!isEnraged && (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 10)
                Enrage();

            if(!isBanished && (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 1)
            {
                if(Unit *Kalecgos = Unit::GetUnit(*m_creature, KalecgosGUID))
                {
                    if(((boss_kalecgosAI*)((Creature*)Kalecgos)->AI())->isBanished)
                    {
                        m_creature->setDeathState(JUST_DIED);
                        return;
                    }
                    else
                    {
                        m_creature->CastSpell(m_creature, SPELL_BANISH, true);
                        isBanished = true;
                    }
                }
                else
                {
                    DoTextEmote("is unable to find Kalecgos", NULL);
                    EnterEvadeMode();
                }
            }
            CheckTimer = 1000;
        }else CheckTimer -= diff;

        if(ShadowBoltTimer < diff)
        {
            DoCast(m_creature, SPELL_SHADOW_BOLT);
            ShadowBoltTimer = 7000+(rand()%3000);
        }else ShadowBoltTimer -= diff;

        if(AgonyCurseTimer < diff)
        {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if(!target) target = m_creature->getVictim();
            DoCast(target, SPELL_AGONY_CURSE);
            AgonyCurseTimer = 20000;
        }else AgonyCurseTimer -= diff;

        if(CorruptionStrikeTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CORRUPTION_STRIKE);
            CorruptionStrikeTimer = 13000;
        }else CorruptionStrikeTimer -= diff;

        DoMeleeAttackIfReady();	
    }
};

struct TRINITY_DLL_DECL boss_kalecAI : public ScriptedAI
{
    ScriptedInstance *pInstance;

    uint32 RevitalizeTimer;
    uint32 HeroicStrikeTimer;
    uint32 YellTimer;
    uint32 YellSequence;

    uint64 SathGUID;

    bool isEnraged; // if demon is enraged

    boss_kalecAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
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

        //m_creature->CastSpell(m_creature, AURA_SPECTRAL_INVISIBILITY, true);
        //m_creature->CastSpell(m_creature, AURA_SUNWELL_RADIANCE, true);
    }

    void Aggro(Unit* who) {}

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if(done_by->GetGUID() != SathGUID)
            damage = 0;
        else if(isEnraged)
            damage *= 3;
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->getVictim()) // only victim is Sath
        {
            EnterEvadeMode();
            return;
        }

        if(YellTimer < diff)
        {
            switch(YellSequence)
            {
            case 0:
                DoYell(KALEC_SAY_AGGRO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, KALEC_SOUND_AGGRO);
                YellSequence++;
                break;
            case 1:
                if((m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 50)
                {
                    DoYell(KALEC_SAY_LOSING1, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(m_creature, KALEC_SOUND_LOSING1);
                    YellSequence++;
                }
                break;
            case 2:
                if((m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 10)
                {
                    DoYell(KALEC_SAY_LOSING2, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(m_creature, KALEC_SOUND_LOSING2);
                    YellSequence++;
                }
                break;
            default:
                break;
            }
            YellTimer = 5000;
        }

        if(RevitalizeTimer < diff)
        {
            DoCast(m_creature, SPELL_REVITALIZE);
            RevitalizeTimer = 5000;
        }else RevitalizeTimer -= diff;

        if(HeroicStrikeTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_HEROIC_STRIKE);
            HeroicStrikeTimer = 2000;
        }else HeroicStrikeTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

void boss_kalecgosAI::UpdateAI(const uint32 diff)
{
    if(TalkTimer)
    {
        if(!TalkSequence)
        {
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
            m_creature->InterruptNonMeleeSpells(true);
            m_creature->RemoveAllAuras();
            m_creature->DeleteThreatList();
            m_creature->CombatStop();
            GameObject *Door = GameObject::GetGameObject(*m_creature, DoorGUID);
            if(Door) Door->SetLootState(GO_JUST_DEACTIVATED);
            TalkSequence++;
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
        if (!m_creature->SelectHostilTarget() && !m_creature->getVictim())
            return;

        if(CheckTimer < diff)
        {
            if(!isEnraged && (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 10)
            {
                if(Unit *Sath = Unit::GetUnit(*m_creature, SathGUID))
                    ((boss_sathrovarrAI*)((Creature*)Sath)->AI())->Enrage();
            }

            if(!isBanished && (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 1)
            {
                if(Unit *Sath = Unit::GetUnit(*m_creature, SathGUID))
                {
                    if(((boss_sathrovarrAI*)((Creature*)Sath)->AI())->isBanished)
                        Sath->setDeathState(JUST_DIED);
                    else
                    {
                        m_creature->CastSpell(m_creature, SPELL_BANISH, true);
                        isBanished = true;
                    }
                }
                else 
                {
                    DoTextEmote("is unable to find Sath", NULL);
                    EnterEvadeMode();
                }
            }
            CheckTimer = 1000; //every 1 sec we check this
        }else CheckTimer -= diff;

        if(ArcaneBuffetTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_ARCANE_BUFFET);
            ArcaneBuffetTimer = 8000;
        }else ArcaneBuffetTimer -= diff;

        if(FrostBreathTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FROST_BREATH);
            FrostBreathTimer = 15000;
        }else FrostBreathTimer -= diff;

        if(TailLashTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_TAIL_LASH);
            TailLashTimer = 15000;
        }else TailLashTimer -= diff;

        if(WildMagicTimer < diff)
        {
            DoCast(m_creature, WildMagic[rand()%6]);
            WildMagicTimer = 20000;
        }else WildMagicTimer -= diff;

        if(SpectralBlastTimer < diff)
        {
            m_creature->CastSpell(m_creature, SPELL_SPECTRAL_BLAST, true);
            SpectralBlastTimer = 20000+(rand()%5000);
        }else SpectralBlastTimer -= diff;

        DoMeleeAttackIfReady();
    }
}

void boss_sathrovarrAI::Enrage()
{
    Unit *Kalecgos = Unit::GetUnit(*m_creature, KalecgosGUID);
    Unit *Kalec = Unit::GetUnit(*m_creature, KalecGUID);
    if(!Kalecgos)
    {
        error_log("SD2 ERROR: unable to find Kalecgos");
        return;
    }
    if(!Kalec)
    {
        error_log("SD2 ERROR: unable to find Kalec");
        return;
    }
    DoYell(SATH_SAY_ENRAGE,LANG_UNIVERSAL,NULL);
    m_creature->CastSpell(m_creature, SPELL_ENRAGE, true);
    Kalecgos->CastSpell(Kalecgos, SPELL_ENRAGE, true);
    isEnraged = true;
    ((boss_kalecgosAI*)((Creature*)Kalecgos)->AI())->isEnraged = true;
    ((boss_kalecAI*)((Creature*)Kalec)->AI())->isEnraged = true;
}

bool GOkalocegos_teleporter(Player *player, GameObject* _GO)
{
    if(player->HasAura(AURA_SPECTRAL_EXHAUSTION, 0))
        player->GetSession()->SendNotification(GO_FAILED);
    else
        player->CastSpell(player, SPELL_TELEPORT_SPECTRAL, true);
    return true;
}

CreatureAI* GetAI_boss_kalecgos(Creature *_Creature)
{
    return new boss_kalecgosAI (_Creature);
}

CreatureAI* GetAI_boss_Sathrovarr(Creature *_Creature)
{
    return new boss_sathrovarrAI (_Creature);
}

CreatureAI* GetAI_boss_kalec(Creature *_Creature)
{
    return new boss_kalecAI (_Creature);
}

void AddSC_boss_kalecgos()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_kalecgos";
    newscript->GetAI = GetAI_boss_kalecgos;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_sathrovarr";
    newscript->GetAI = GetAI_boss_Sathrovarr;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_kalec";
    newscript->GetAI = GetAI_boss_kalec;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="kalocegos_teleporter";
    newscript->pGOHello = &GOkalocegos_teleporter;
    m_scripts[nrscripts++] = newscript;
}
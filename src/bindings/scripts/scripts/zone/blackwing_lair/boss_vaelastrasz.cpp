/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Vaelastrasz
SD%Complete: 75
SDComment: Burning Adrenaline not correctly implemented in core
SDCategory: Blackwing Lair
EndScriptData */

#include "precompiled.h"

#define SPELL_ESSENCEOFTHERED       23513
#define SPELL_FLAMEBREATH           23461
#define SPELL_FIRENOVA              23462
#define SPELL_TAILSWIPE             15847
#define SPELL_BURNINGADRENALINE     23620
#define SPELL_CLEAVE                20684                   //Chain cleave is most likely named something different and contains a dummy effect

#define SAY_LINE1           "Too late...friends. Nefarius' corruption has taken hold. I cannot...control myself. "
#define SOUND_LINE1         8281

#define SAY_LINE2           "I beg you Mortals, flee! Flee before I lose all control. The Black Fire rages within my heart. I must release it!"
#define SOUND_LINE2         8282

#define SAY_LINE3           "FLAME! DEATH! DESTRUCTION! COWER MORTALS BEFORE THE WRATH OF LORD....NO! I MUST FIGHT THIS!"
#define SOUND_LINE3         8283

#define SAY_HALFLIFE        "Nefarius' hate has made me stronger than ever before. You should have fled, while you could, mortals! The fury of Blackrock courses through my veins! "
#define SOUND_HALFLIFE      8285

#define SAY_KILLTARGET      "Forgive me $N, your death only adds to my failure."
#define SOUND_KILLTARGET    8284

#define GOSSIP_ITEM         "Start Event <Needs Gossip Text>"

struct TRINITY_DLL_DECL boss_vaelAI : public ScriptedAI
{
    boss_vaelAI(Creature *c) : ScriptedAI(c)
    {
        c->SetUInt32Value(UNIT_NPC_FLAGS,1);
        c->setFaction(35);
        c->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        Reset();
    }

    uint64 PlayerGUID;
    uint32 SpeachTimer;
    uint32 SpeachNum;
    uint32 Cleave_Timer;
    uint32 FlameBreath_Timer;
    uint32 FireNova_Timer;
    uint32 BurningAdrenalineCaster_Timer;
    uint32 BurningAdrenalineTank_Timer;
    uint32 TailSwipe_Timer;
    bool HasYelled;
    bool DoingSpeach;

    void Reset()
    {
        PlayerGUID = 0;
        SpeachTimer = 0;
        SpeachNum = 0;
        Cleave_Timer = 8000;                                //These times are probably wrong
        FlameBreath_Timer = 11000;
        BurningAdrenalineCaster_Timer = 15000;
        BurningAdrenalineTank_Timer = 45000;
        FireNova_Timer = 5000;
        TailSwipe_Timer = 20000;
        HasYelled = false;
        DoingSpeach = false;

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(1, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    void BeginSpeach(Unit* target)
    {
        //Stand up and begin speach
        PlayerGUID = target->GetGUID();

        //10 seconds
        DoYell(SAY_LINE1,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_LINE1);
        SpeachTimer = 10000;
        SpeachNum = 0;
        DoingSpeach = true;
    }

    void KilledUnit(Unit *victim)
    {
        if (rand()%5)
            return;

        DoYell(SAY_KILLTARGET,LANG_UNIVERSAL,victim);
        DoPlaySoundToSet(m_creature,SOUND_KILLTARGET);
    }

    void Aggro(Unit *who)
    {
        DoCast(m_creature,SPELL_ESSENCEOFTHERED);
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        //Speach
        if (DoingSpeach)
            if (SpeachTimer < diff)
        {
            switch (SpeachNum)
            {
                case 0:
                    //16 seconds till next line
                    DoYell(SAY_LINE2,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(m_creature,SOUND_LINE2);
                    SpeachTimer = 16000;
                    SpeachNum++;
                    break;

                case 1:
                    //This one is actually 16 seconds but we only go to 10 seconds because he starts attacking after he says "I must fight this!"
                    DoYell(SAY_LINE3,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(m_creature,SOUND_LINE3);
                    SpeachTimer = 10000;
                    SpeachNum++;
                    break;

                case 2:
                default:
                    m_creature->setFaction(103);
                    m_creature->SetHealth(int(m_creature->GetMaxHealth()*.3));
                    if (PlayerGUID && Unit::GetUnit((*m_creature),PlayerGUID))
                    {
                        DoStartAttackAndMovement(Unit::GetUnit((*m_creature),PlayerGUID));
                        DoCast(m_creature,SPELL_ESSENCEOFTHERED);
                    }

                    SpeachTimer = 0;
                    DoingSpeach = false;
                    break;
            }
        }else SpeachTimer -= diff;

        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        // Yell if hp lower than 15%
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 15 && !HasYelled)
        {
            //Say our dialog
            DoYell(SAY_HALFLIFE,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_HALFLIFE);
            HasYelled = true;
        }

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 15000;
        }else Cleave_Timer -= diff;

        //FlameBreath_Timer
        if (FlameBreath_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FLAMEBREATH);
            FlameBreath_Timer = 4000 + rand()%4000;
        }else FlameBreath_Timer -= diff;

        //BurningAdrenalineCaster_Timer
        if (BurningAdrenalineCaster_Timer < diff)
        {
            Unit* target = NULL;

            int i = 0 ;
            while (i < 3)                                   // max 3 tries to get a random target with power_mana
            {
                ++i;
                target = SelectUnit(SELECT_TARGET_RANDOM,1);//not aggro leader
                if (target)
                    if (target->getPowerType() == POWER_MANA)
                        i=3;
            }
            if (target)                                     // cast on self (see below)
                target->CastSpell(target,SPELL_BURNINGADRENALINE,1);

            BurningAdrenalineCaster_Timer = 15000;
        }else BurningAdrenalineCaster_Timer -= diff;

        //BurningAdrenalineTank_Timer
        if (BurningAdrenalineTank_Timer < diff)
        {
            // have the victim cast the spell on himself otherwise the third effect aura will be applied
            // to Vael instead of the player

            m_creature->getVictim()->CastSpell(m_creature->getVictim(),SPELL_BURNINGADRENALINE,1);

            BurningAdrenalineTank_Timer = 45000;
        }else BurningAdrenalineTank_Timer -= diff;

        //FireNova_Timer
        if (FireNova_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FIRENOVA);
            FireNova_Timer = 5000;
        }else FireNova_Timer -= diff;

        //TailSwipe_Timer
        if (TailSwipe_Timer < diff)
        {
            //Only cast if we are behind
            /*if (!m_creature->HasInArc( M_PI, m_creature->getVictim()))
            {
            DoCast(m_creature->getVictim(),SPELL_TAILSWIPE);
            }*/

            TailSwipe_Timer = 20000;
        }else TailSwipe_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

void SendDefaultMenu_boss_vael(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)               //Fight time
    {
        player->CLOSE_GOSSIP_MENU();
        ((boss_vaelAI*)_Creature->AI())->BeginSpeach((Unit*)player);
    }
}

bool GossipSelect_boss_vael(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_boss_vael(player, _Creature, action);

    return true;
}

bool GossipHello_boss_vael(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->SEND_GOSSIP_MENU(907,_Creature->GetGUID());

    return true;
}

CreatureAI* GetAI_boss_vael(Creature *_Creature)
{
    return new boss_vaelAI (_Creature);
}

void AddSC_boss_vael()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_vaelastrasz";
    newscript->GetAI = GetAI_boss_vael;
    newscript->pGossipHello = &GossipHello_boss_vael;
    newscript->pGossipSelect = &GossipSelect_boss_vael;
    m_scripts[nrscripts++] = newscript;
}

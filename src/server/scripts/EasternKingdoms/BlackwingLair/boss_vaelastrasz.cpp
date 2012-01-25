/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2012 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Vaelastrasz
SD%Complete: 75
SDComment: Burning Adrenaline not correctly implemented in core
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptPCH.h"

enum Says
{
   SAY_LINE1           = -1469026,
   SAY_LINE2           = -1469027,
   SAY_LINE3           = -1469028,
   SAY_HALFLIFE        = -1469029,
   SAY_KILLTARGET      = -1469030
};

#define GOSSIP_ITEM         "Start Event <Needs Gossip Text>"

enum Spells
{
   SPELL_ESSENCEOFTHERED       = 23513,
   SPELL_FLAMEBREATH           = 23461,
   SPELL_FIRENOVA              = 23462,
   SPELL_TAILSWIPE             = 15847,
   SPELL_BURNINGADRENALINE     = 23620,
   SPELL_CLEAVE                = 20684   //Chain cleave is most likely named something different and contains a dummy effect
};

class boss_vaelastrasz : public CreatureScript
{
public:
    boss_vaelastrasz() : CreatureScript("boss_vaelastrasz") { }

    void SendDefaultMenu(Player* player, Creature* creature, uint32 Action)
    {
        if (Action == GOSSIP_ACTION_INFO_DEF + 1)               //Fight time
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(boss_vaelastrasz::boss_vaelAI, creature->AI())->BeginSpeech(player);
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 Sender, uint32 Action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (Sender == GOSSIP_SENDER_MAIN)
            SendDefaultMenu(player, creature, Action);

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(907, creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vaelAI (creature);
    }

    struct boss_vaelAI : public ScriptedAI
    {
        boss_vaelAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            creature->setFaction(35);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        uint64 PlayerGUID;
        uint32 SpeechTimer;
        uint32 SpeechNum;
        uint32 Cleave_Timer;
        uint32 FlameBreath_Timer;
        uint32 FireNova_Timer;
        uint32 BurningAdrenalineCaster_Timer;
        uint32 BurningAdrenalineTank_Timer;
        uint32 TailSwipe_Timer;
        bool HasYelled;
        bool DoingSpeech;

        void Reset()
        {
            PlayerGUID             = 0;
            SpeechTimer            = 0;
            SpeechNum              = 0;
            Cleave_Timer           = 8000;     //These times are probably wrong
            FlameBreath_Timer      = 11000;
            BurningAdrenalineCaster_Timer    = 15000;
            BurningAdrenalineTank_Timer      = 45000;
            FireNova_Timer         = 5000;
            TailSwipe_Timer        = 20000;
            HasYelled              = false;
            DoingSpeech            = false;
        }

        void BeginSpeech(Unit* target)
        {
            //Stand up and begin speach
            PlayerGUID = target->GetGUID();

            //10 seconds
            DoScriptText(SAY_LINE1, me);

            SpeechTimer = 10000;
            SpeechNum = 0;
            DoingSpeech = true;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void KilledUnit(Unit* victim)
        {
            if (rand()%5)
                return;

            DoScriptText(SAY_KILLTARGET, me, victim);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCast(me, SPELL_ESSENCEOFTHERED);
            DoZoneInCombat();
            me->SetHealth(me->CountPctFromMaxHealth(30));
            // now drop damage requirement to be able to take loot
            me->ResetPlayerDamageReq();
        }

        void UpdateAI(const uint32 diff)
        {
            //Speech
            if (DoingSpeech)
            {
                if (SpeechTimer <= diff)
                {
                    switch (SpeechNum)
                    {
                        case 0:
                            //16 seconds till next line
                            DoScriptText(SAY_LINE2, me);
                            SpeechTimer = 16000;
                            ++SpeechNum;
                            break;
                        case 1:
                            //This one is actually 16 seconds but we only go to 10 seconds because he starts attacking after he says "I must fight this!"
                            DoScriptText(SAY_LINE3, me);
                            SpeechTimer = 10000;
                            ++SpeechNum;
                            break;
                        case 2:
                            me->setFaction(103);
                            if (PlayerGUID && Unit::GetUnit((*me), PlayerGUID))
                            {
                                AttackStart(Unit::GetUnit((*me), PlayerGUID));
                                DoCast(me, SPELL_ESSENCEOFTHERED);
                            }
                            SpeechTimer = 0;
                            DoingSpeech = false;
                            break;
                    }
                } else SpeechTimer -= diff;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            // Yell if hp lower than 15%
            if (HealthBelowPct(15) && !HasYelled)
            {
                DoScriptText(SAY_HALFLIFE, me);
                HasYelled = true;
            }

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 15000;
            } else Cleave_Timer -= diff;

            //FlameBreath_Timer
            if (FlameBreath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FLAMEBREATH);
                FlameBreath_Timer = urand(4000, 8000);
            } else FlameBreath_Timer -= diff;

            //BurningAdrenalineCaster_Timer
            if (BurningAdrenalineCaster_Timer <= diff)
            {
                Unit* target = NULL;

                uint8 i = 0;
                while (i < 3)   // max 3 tries to get a random target with power_mana
                {
                    ++i;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true); //not aggro leader
                    if (target && target->getPowerType() == POWER_MANA)
                            i = 3;
                }
                if (target)                                     // cast on self (see below)
                    target->CastSpell(target, SPELL_BURNINGADRENALINE, 1);

                BurningAdrenalineCaster_Timer = 15000;
            } else BurningAdrenalineCaster_Timer -= diff;

            //BurningAdrenalineTank_Timer
            if (BurningAdrenalineTank_Timer <= diff)
            {
                // have the victim cast the spell on himself otherwise the third effect aura will be applied
                // to Vael instead of the player
                me->getVictim()->CastSpell(me->getVictim(), SPELL_BURNINGADRENALINE, 1);

                BurningAdrenalineTank_Timer = 45000;
            } else BurningAdrenalineTank_Timer -= diff;

            //FireNova_Timer
            if (FireNova_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FIRENOVA);
                FireNova_Timer = 5000;
            } else FireNova_Timer -= diff;

            //TailSwipe_Timer
            if (TailSwipe_Timer <= diff)
            {
                //Only cast if we are behind
                /*if (!me->HasInArc(M_PI, me->getVictim()))
                {
                DoCast(me->getVictim(), SPELL_TAILSWIPE);
                }*/

                TailSwipe_Timer = 20000;
            } else TailSwipe_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_vael()
{
    new boss_vaelastrasz();
}

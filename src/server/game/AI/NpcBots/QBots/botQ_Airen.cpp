#include "bot_ai.h"
#include "Group.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "WorldSession.h"
/*
Bot Quest npc Airen by Graff onlysuffering@gmail.com
Complete - 0%
TODO:
*/
#define ACT                 GOSSIP_ACTION_INFO_DEF

class Airen_chapter1 : public CreatureScript
{
public:
    Airen_chapter1() : CreatureScript("npc_Airen_qI") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new Airen_AI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, GOSSIP_ICON_CHAT, "nothing here", 6000, ACT + 1, "nothing here either", 0 * COPPER, true);
        player->PlayerTalkClass->SendGossipMenu(GOSSIP_MURDER, creature->GetGUID());

        std::ostringstream msg;
        msg << "..." << player->GetName() << ", huh?";
        bot_ai::BotSpeak(msg.str(), CHAT_MSG_WHISPER, LANG_UNIVERSAL, creature->GetGUID(), player->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (sender)
        {
            case 6000:
            {
                if (action == ACT + 1)
                {
                    if (!player->HasEnoughMoney(1 * COPPER))
                    {
                        player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                        break;
                    }
                    player->ModifyMoney(-(1 * COPPER));
                }

                break;
            }
            default:
                break;
        }

        CloseGossipMenuFor(player);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
    {
        player->PlayerTalkClass->ClearMenus();
        std::string answer = "asd";

        switch (sender)
        {
            case 6000:
            {
                if (action == ACT + 1 && code == answer)
                    bot_ai::BotSpeak("hehe", CHAT_MSG_YELL, LANG_UNIVERSAL, creature->GetGUID(), player->GetGUID());
                break;
            }
        }

        CloseGossipMenuFor(player);
        return true;
    }

    struct Airen_AI : public ScriptedAI
    {
        Airen_AI(Creature* creature) : ScriptedAI(creature) { }

        void EnterCombat(Unit*) { }
        void Aggro(Unit*) { }
        void AttackStart(Unit*) { }
        void KilledUnit(Unit*) { }
		void EnterEvadeMode(EvadeReason /*why*/) { }
        void MoveInLineOfSight(Unit*) { }
        void JustDied(Unit*) { me->DisappearAndDie(); }

        void UpdateAI(uint32 /*diff*/)
        {
        }

        void Reset()
        {
            me->SetCreateHealth(213000213);
            me->SetMaxHealth(me->GetCreateHealth());
            me->SetFullHealth();

            me->setPowerType(POWER_RAGE);
            me->SetMaxPower(POWER_RAGE, 10000);
            me->SetPower(POWER_RAGE, me->GetMaxPower(POWER_RAGE));
        }

        void DamageTaken(Unit* /*u*/, uint32& damage)
        {
            damage = me->GetHealth() > 1 ? 1 : 0;
        }
    };
};

void AddSC_BotQuests_chapter1()
{
    new Airen_chapter1();
}

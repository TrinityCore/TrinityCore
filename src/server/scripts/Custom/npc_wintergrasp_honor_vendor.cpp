#include "ScriptPCH.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "Config.h"

class npc_wintergrasp_honor_vendor : public CreatureScript
{
public:
    npc_wintergrasp_honor_vendor() : CreatureScript("npc_wintergrasp_honor_vendor") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Я хочу обменять очки чести на Почётные знаки Озера Ледяных Оков", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            pPlayer->SEND_VENDORLIST(pCreature->GetGUID());

        Map::PlayerList const &playerList = pCreature->GetMap()->GetPlayers();
        if (!playerList.isEmpty())
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player *iPlayer = i->getSource())
                {
                    if (!iPlayer->isGameMaster() && iPlayer->GetDistance(pCreature) <= 100.0f)
                        iPlayer->SetPvP(true);
                }
        return true;
    }
};

/*######
## mob_flyhack_banner
## Special for Verybad xD
######*/
class mob_flyhack_banner : public CreatureScript
{
public:
    mob_flyhack_banner() : CreatureScript("mob_flyhack_banner") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_flyhack_bannerAI(pCreature);
    }

    struct mob_flyhack_bannerAI : public ScriptedAI
    {
        mob_flyhack_bannerAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            Reset();
        }

        void Reset()
        {
        }

        void MoveInLineOfSight(Unit* pWho) 
        {
            if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER) return;

            if (pWho->IsWithinDistInMap(me, 60.0f) && pWho->ToPlayer()->GetSession()->GetSecurity() < SEC_GAMEMASTER)
            {
                if (pWho->HasAuraType(SPELL_AURA_FLY) || pWho->HasAuraType(SPELL_AURA_WATER_WALK)
                || pWho->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || pWho->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED))
                     return;

                std::string sText = ("Игрок: " + std::string(pWho->GetName()) + " получил премию Дарвина.");

                sWorld->SendGMText(LANG_GM_BROADCAST, sText.c_str());

                if (SpellEntry const *spellInfo = sSpellStore.LookupEntry(9454))
                    Aura::TryCreate(spellInfo, pWho, pWho);

                sWorld->AutoBanDebug(pWho->GetName(), sText.c_str(), sConfig->GetIntDefault("RealmID", 0), me->GetGUIDLow(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), pWho->GetMapId(), pWho->GetPositionX(), pWho->GetPositionY(), pWho->GetPositionZ());
                sWorld->BanAccount(BAN_CHARACTER, pWho->GetName(), "0", sText.c_str(), "Very autobanner");

            }

        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    };
};

/*#####
#INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('19752', 'spell_divine_intervention');
#####*/
class spell_divine_intervention : public SpellScriptLoader
{
    public:
        spell_divine_intervention() : SpellScriptLoader("spell_divine_intervention") { }

        class spell_divine_interventionSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_divine_interventionSpellScript);

            void HandleBeforeHit()
            {
                if (Unit * target = GetHitUnit())
                {
                   if (target->GetTypeId() != TYPEID_PLAYER)
                   {
                       PreventHitEffect(EFFECT_0);
                       PreventHitEffect(EFFECT_1);
                   }
                }
            }


            void Register()
            {
                BeforeHit += SpellHitFn(spell_divine_interventionSpellScript::HandleBeforeHit);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_divine_interventionSpellScript();
        }
};

void AddSC_npc_wintergrasp_honor_vendor()
{
    new npc_wintergrasp_honor_vendor;
    new mob_flyhack_banner;
    new spell_divine_intervention;
}

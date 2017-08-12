#include <ScriptPCH.h>
#include "ScriptedGossip.h"
#include "WorldSession.h"
#include "Chat.h"


struct vip_ai : public CreatureAI {
    uint32 MainMenu = 17777;
    uint32 MorphMenu = 17778;
    uint32 ActionInformation = 500;
    uint32 ActionHeal = 501;
    uint32 ActionMaxSkill = 502;
    uint32 ActionShowMorhps = 503;
    uint32 ActionLearnRidingSkills = 504;
    uint32 ActionBufs = 505;
    uint32 ActionGoods = 506;

    vip_ai(Creature *c) : CreatureAI(c) {

    }

	        void UpdateAI(uint32 diff) override {

        }


    virtual bool GossipHello(Player *player) override {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Информация о VIP", MainMenu, ActionInformation);
        if (player->IsGameMaster() || player->GetSession()->IsPremium()) {
            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Попольните ХП", MainMenu, ActionHeal);
            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Повысить скили", MainMenu, ActionMaxSkill);
            // AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Поменять морф", MainMenu, ActionShowMorhps);
            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "|cff000080Изучить верховую езду", MainMenu,
                             ActionLearnRidingSkills);
            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "|cff000080Бафы", MainMenu, ActionBufs);
            AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "|cff000080Предметы", MainMenu, ActionGoods);

        }

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me);

        return true;
    }


    virtual bool GossipSelect(Player *player, uint32 sender, uint32 action) override {
//	me->Whisper("Hello", LANG_UNIVERSAL, player);
//	me->Whisper(std::to_string(sender), LANG_UNIVERSAL, player);
//	me->Whisper(std::to_string(action), LANG_UNIVERSAL, player);
        ClearGossipMenuFor(player);

        if (sender == 0) {
            if (action == 1) {
                if (player->IsInCombat()) {
                    me->Whisper("Извини " + player->GetName() + ", но ты в бою. Я немогу исцелят тебя. ",
                                LANG_UNIVERSAL, player);
                } else if (player->GetMaxHealth() == player->GetHealth() && (player->getPowerType() == POWER_MANA &&
                                                                             player->GetPower(POWER_MANA) ==
                                                                             player->GetMaxPower(POWER_MANA))) {
                    me->Whisper(player->GetName() + ", ты уже здоров ", LANG_UNIVERSAL, player);
                } else {
                    player->SetHealth(player->GetMaxHealth());

                    if (player->getPowerType() == POWER_MANA) {
                        player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
                    }

                    me->Say("Исцелись " + player->GetName(), LANG_UNIVERSAL);

                    me->HandleEmoteCommand(EMOTE_ONESHOT_SPELL_CAST);
                    player->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                }
            } else if (action == 2) {
		player->UpdateWeaponsSkillsToMaxSkillsForLevel();
                me->Whisper("Твои навики повышени", LANG_UNIVERSAL, player);
                ClearGossipMenuFor(player);
                CloseGossipMenuFor(player);
            } else if (action == ActionShowMorhps) {
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Стар крафт мурлок", MorphMenu, 500);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Ворген", MorphMenu, 501);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Пандарен монах", MorphMenu, 502);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Маг гном", MorphMenu, 503);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Таурен", MorphMenu, 504);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Нежить", MorphMenu, 505);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Человек", MorphMenu, 506);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Король лич", MorphMenu, 507);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Тирион Фолдринг", MorphMenu, 508);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Утер Светоносный", MorphMenu, 509);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Артас", MorphMenu, 510);
                ///////////// From SPGM
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Алгалон", MorphMenu, 711);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Судьболом", MorphMenu, 712);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Дум Лорд", MorphMenu, 713);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Ониксия", MorphMenu, 714);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Таддиус", MorphMenu, 715);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Глут", MorphMenu, 716);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Мексна", MorphMenu, 717);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Сапфирон", MorphMenu, 718);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Нот Чумной", MorphMenu, 719);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Кел` Тузад", MorphMenu, 720);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Кел` Талас", MorphMenu, 721);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "К'Тун", MorphMenu, 722);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Тралл", MorphMenu, 723);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Илидан", MorphMenu, 724);
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "Снять все морфы", MorphMenu, 725);

                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me);
            } else if (action == 3) {
                player->LearnSpell(33388, false);
                player->LearnSpell(33391, false);
                player->LearnSpell(34090, false);
                player->LearnSpell(34091, false);

                player->UpdateSkill(762, 300);
                me->Whisper("|cffff6060[VIP]:|r Вы выучили верховую езду!", LANG_UNIVERSAL, player);
            } else if (action == 4) {
                player->CastSpell(player, 30550, true);
                player->CastSpell(player, 23766, true);
                player->CastSpell(player, 23769, true);
                player->CastSpell(player, 23738, true);
                player->CastSpell(player, 23737, true);
                player->CastSpell(player, 23736, true);
                player->CastSpell(player, 23767, true);
                player->CastSpell(player, 23735, true);
                player->CastSpell(player, 23768, true);

                me->Whisper("|cffff6060[VIP]:|r На вас наложены  |cFF76EE00V.I.P бафы|r!", LANG_UNIVERSAL,
                            player);
            } else if (action == 5) {
                me->Say("Чем могу помочь " + player->GetSession()->GetPlayerName() + "?", LANG_UNIVERSAL);
                ClearGossipMenuFor(player);
                player->GetSession()->SendListInventory(me->GetGUID(), 250040);
                return true;
            }

        } else if (sender == MorphMenu) {
            player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);

            switch (action) {
                case 500:
                    player->SetDisplayId(29348);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
                    break;

                case 501:
                    player->SetDisplayId(657);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                    break;

                case 502:
                    player->SetDisplayId(30414);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
                    break;

                case 503:
                    player->SetDisplayId(28586);
                    break;

                case 504:
                    player->SetDisplayId(30199);
                    break;

                case 505:
                    player->SetDisplayId(2789);
                    break;

                case 506:
                    player->SetDisplayId(16280);
                    break;

                case 507:
                    player->SetDisplayId(24191);
                    break;

                case 508:
                    player->SetDisplayId(22209);
                    break;

                case 509:
                    player->SetDisplayId(23889);
                    break;

                case 510:
                    player->SetDisplayId(24949);
                    break;

                case 711: // Algalon
                    player->SetDisplayId(28641);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
                    break;

                case 712: // Doomwalker
                    player->SetDisplayId(16630);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
                    break;

                case 713: // Doomlord kazzak
                    player->SetDisplayId(17887);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.10f);
                    break;

                case 714: // Onyxia
                    player->SetDisplayId(8570);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
                    break;

                case 715: // Thaddius
                    player->SetDisplayId(16137);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
                    break;

                case 716: // Gluth
                    player->SetDisplayId(16064);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
                    break;

                case 717: // Maexxna
                    player->SetDisplayId(15928);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.15f);
                    break;

                case 718: // Sapphiron
                    player->SetDisplayId(16033);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
                    break;

                case 719: // Noth The Plaguebringer
                    player->SetDisplayId(16590);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
                    break;

                case 720: // Kel'Thuzad
                    player->SetDisplayId(15945);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
                    break;

                case 721: // Kael'thas Sunstrider
                    player->SetDisplayId(20023);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
                    break;

                case 722: // C'thun
                    player->SetDisplayId(15786);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
                    break;

                case 723: // Thrall
                    player->SetDisplayId(4527);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                    break;

                case 724:// Illidan
                    player->SetDisplayId(21135);
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
                    break;

                case 725: // Demorph Player (remove all morphs)
                    player->DeMorph();
                    player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                    break;
            }
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);
        }
        return true;
    }
};


class example_creature : public CreatureScript {
public:

    example_creature() : CreatureScript("my_script") { }


    CreatureAI* GetAI(Creature* creature) const override
    {
        return new vip_ai(creature);
    }
};


void AddSC_my_script() {
    new example_creature();
}



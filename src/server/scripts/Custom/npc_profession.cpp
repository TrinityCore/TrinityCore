//#include "PrecompiledHeaders/ScriptPCH.h"
//#include "Language.h"
//#include "SpellPackets.h"
//
//class npc_profession : public CreatureScript
//{
//public:
//    npc_profession() : CreatureScript("npc_profession") {}
//
//    void CreatureWhisperBasedOnBool(const char* text, Creature* _creature, Player* player, bool value)
//    {
//        if (value)
//            _creature->MonsterWhisper(text, player->GetGUID());
//    }
//
//    uint32 PlayerMaxLevel() const
//    {
//        return sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
//    }
//
//    bool PlayerHasItemOrSpell(const Player* plr, uint32 itemId, uint32 spellId) const
//    {
//        return plr->HasItemCount(itemId, 1, true) || const_cast<Player*>(plr)->HasSpell(spellId);
//    }
//
//    bool OnGossipHello(Player* player, Creature* _creature) override
//    {
//        player->ADD_GOSSIP_ITEM(9, "List of professions", GOSSIP_SENDER_MAIN, 196);
//        player->ADD_GOSSIP_ITEM(7, "Farewell", GOSSIP_SENDER_MAIN, 220);
//        player->PlayerTalkClass->SendGossipMenu(20011, _creature->GetGUID());
//        return true;
//    }
//
//    bool LearnAllRecipesInProfession(Player* player, SkillType skill)
//    {
//        SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(skill);
//        if (!SkillInfo)
//            return false;
//
//        ChatHandler handler(player->GetSession());
//        player->GetAchievementMgr()->m_canUpdateAchiev = 0;
//        LearnSkillRecipesHelper(player, SkillInfo->ID);
//        player->GetAchievementMgr()->m_canUpdateAchiev = 1;
//
//        char const* skill_name = SkillInfo->DisplayName[DEFAULT_LOCALE].Str[DEFAULT_LOCALE];
//        player->SetSkill(SkillInfo->ID, player->GetSkillStep(SkillInfo->ID), 800, 800);
//        handler.PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, skill_name);
//        return true;
//    }
//
//    void LearnSkillRecipesHelper(Player* player, uint32 skill_id)
//    {
//        uint32 classmask = player->getClassMask();
//
//        WorldPackets::Spells::LearnedSpells packet;
//        for (SkillLineAbilityEntry const* skillLine : sDB2Manager._skillLineAbilityContainer[skill_id])
//        {
//            // not high rank
//            if (skillLine->SupercedesSpell)
//                continue;
//
//            // skip racial skills
//            if (skillLine->RaceMask != 0)
//                continue;
//
//            // skip wrong class skills
//            if (skillLine->ClassMask && (skillLine->ClassMask & classmask) == 0)
//                continue;
//
//            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->Spell);
//            if (!spellInfo)
//                continue;
//
//            if (player->addSpell(skillLine->Spell, true, true, false, false))
//                packet.SpellID.push_back(skillLine->Spell);
//        }
//        player->SendDirectMessage(packet.Write());
//    }
//
//    bool IsSecondarySkill(SkillType skill) const
//    {
//        return skill == SKILL_COOKING || skill == SKILL_FIRST_AID;
//    }
//
//    void CompleteLearnProfession(Player* player, Creature* creature, SkillType skill)
//    {
//        if (!player->GetFreePrimaryProfessionPoints() && !IsSecondarySkill(skill))
//            creature->MonsterWhisper("You've already learned two professions!", player->GetGUID());
//        else
//        {
//            if (!LearnAllRecipesInProfession(player, skill))
//                creature->MonsterWhisper("Internal error!", player->GetGUID());
//        }
//    }
//
//    bool OnGossipSelect(Player* player, Creature* _creature, uint32 /*uiSender*/, uint32 uiAction) override
//    {
//        player->PlayerTalkClass->ClearMenus();
//
//        switch (uiAction)
//        {
//        case 200:
//            player->ADD_GOSSIP_ITEM(9, "List of professions", GOSSIP_SENDER_MAIN, 196);
//            player->ADD_GOSSIP_ITEM(7, "Farewell", GOSSIP_SENDER_MAIN, 220);
//            player->PlayerTalkClass->SendGossipMenu(20011, _creature->GetGUID());
//            break;
//
//        case 220:
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//
//        case 196:
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Alchemy", GOSSIP_SENDER_MAIN, 1);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Smithing", GOSSIP_SENDER_MAIN, 2);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Tannery", GOSSIP_SENDER_MAIN, 3);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Tailoring", GOSSIP_SENDER_MAIN, 4);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Engineering", GOSSIP_SENDER_MAIN, 5);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Charging", GOSSIP_SENDER_MAIN, 6);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Jewelry", GOSSIP_SENDER_MAIN, 7);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Description", GOSSIP_SENDER_MAIN, 8);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Cookery", GOSSIP_SENDER_MAIN, 9);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "First Aid", GOSSIP_SENDER_MAIN, 10);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Compliance", GOSSIP_SENDER_MAIN, 11);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Skinning", GOSSIP_SENDER_MAIN, 12);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Mining", GOSSIP_SENDER_MAIN, 13);
//            player->ADD_GOSSIP_ITEM(4, "Back to Main Menu!", GOSSIP_SENDER_MAIN, 200);
//            player->PlayerTalkClass->SendGossipMenu(20011, _creature->GetGUID());
//            break;
//        case 1:
//            if (player->HasSkill(SKILL_ALCHEMY))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//
//            CompleteLearnProfession(player, _creature, SKILL_ALCHEMY);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 2:
//            if (player->HasSkill(SKILL_BLACKSMITHING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_BLACKSMITHING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 3:
//            if (player->HasSkill(SKILL_LEATHERWORKING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_LEATHERWORKING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 4:
//            if (player->HasSkill(SKILL_TAILORING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_TAILORING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 5:
//            if (player->HasSkill(SKILL_ENGINEERING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_ENGINEERING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 6:
//            if (player->HasSkill(SKILL_ENCHANTING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_ENCHANTING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 7:
//            if (player->HasSkill(SKILL_JEWELCRAFTING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_JEWELCRAFTING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 8:
//            if (player->HasSkill(SKILL_INSCRIPTION))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//            CompleteLearnProfession(player, _creature, SKILL_INSCRIPTION);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 9:
//            // if (player->HasSkill(SKILL_COOKING))
//            // {
//                // _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                // player->PlayerTalkClass->SendCloseGossip();
//                // break;
//            // }
//            CompleteLearnProfession(player, _creature, SKILL_COOKING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 10:
//            // if (player->HasSkill(SKILL_FIRST_AID))
//            // {
//                // _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                // player->PlayerTalkClass->SendCloseGossip();
//                // break;
//            // }
//            CompleteLearnProfession(player, _creature, SKILL_FIRST_AID);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 11:
//            if (player->HasSkill(SKILL_HERBALISM))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//
//            CompleteLearnProfession(player, _creature, SKILL_HERBALISM);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 12:
//            if (player->HasSkill(SKILL_SKINNING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//
//            CompleteLearnProfession(player, _creature, SKILL_SKINNING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        case 13:
//            if (player->HasSkill(SKILL_MINING))
//            {
//                _creature->MonsterWhisper("You've already mastered the profession.!", player->GetGUID());
//                player->PlayerTalkClass->SendCloseGossip();
//                break;
//            }
//
//            CompleteLearnProfession(player, _creature, SKILL_MINING);
//            player->PlayerTalkClass->SendCloseGossip();
//            break;
//        }
//
//        return true;
//    }
//};
//
//void AddSC_npc_profession()
//{
//    new npc_profession();
//}

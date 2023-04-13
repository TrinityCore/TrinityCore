////From:https://uiwow.com/thread-3910-1-1.html?_dsign=f36fb958
//class DD_RemoveGem : public ItemScript
//{
//public: 
//        DD_RemoveGem() : ItemScript("DD_RemoveGem"){}
//        
//        uint32 _gemid[3] = { 0, 0, 0 };
//
//        uint64 _guid = 0;
//
//        bool OnUse(Player* player, Item* item, SpellCastTargets const& targets)
//        {
//                
//                player->PlayerTalkClass->ClearMenus();
//
//                Item * targetItem = player->GetItemByGuid(targets.GetItemTargetGUID());
//
//                if (!targetItem)
//                        return false;
//        
//                _guid = targetItem->GetGUID();
//
//                std::string targetsItem_name = sRequestTempMgr->GetItemLink(targetItem->GetEntry());
//                
//                std::string _gemname[3] = { "","","" };
//
//                uint8 i = 0;
//                
//                for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT + MAX_GEM_SOCKETS; ++enchant_slot)
//                {
//                        
//                        uint32 enchant_id = targetItem->GetEnchantmentId(EnchantmentSlot(enchant_slot));
//                        if (!enchant_id)
//                                continue;
//                        
//                        SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
//                        if (!enchantEntry)
//                                continue;
//                        
//                        uint32 gemid = enchantEntry->GemID;
//                        if (gemid)
//                        {
//                                ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemid);
//                                if (gemProto)
//                                {
//                                        _gemid[i] = gemid;
//                                        _gemname[i] = sRequestTempMgr->GetItemLink(gemid).empty() ? "" : sRequestTempMgr->GetItemLink(gemid);
//                                }
//                                
//                        }
//                        ++i;
//                }
//
//                if (_gemname[0].empty() && _gemname[1].empty() && _gemname[2].empty())
//                        return false;//在这里可以补一个提示，当然偷懒也可以不补
//
//                std::string str = "你确定需要摘除 " + targetsItem_name + "上的";
//                str += _gemname[0].empty() ? "" : "\n" + _gemname[0];
//                str += _gemname[1].empty() ? "" : "\n" + _gemname[1];
//                str += _gemname[2].empty() ? "" : "\n" + _gemname[2];
//                str += "\n吗？";
//
//                player->ADD_GOSSIP_ITEM_EXTENDED(-1, "", GOSSIP_SENDER_COMMONFUN_REMOVEGEM, GOSSIP_ACTION_COMMONFUN_REMOVEGEM + targets.GetItemTargetEntry(), str, 0, false);
//                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
//                return true;
//
//        }
//
//        void OnGossipSelect(Player* player, Item* item, uint32 sender, uint32 action)
//        { 
//                player->PlayerTalkClass->ClearMenus();
//
//                if (sender == GOSSIP_SENDER_COMMONFUN_REMOVEGEM)
//                {
//                        uint32 tartargetsItemid = action - GOSSIP_ACTION_COMMONFUN_REMOVEGEM;
//
//                        if (_guid == 0)
//                                return;
//
//                        Item * targetItem = player->GetItemByGuid(_guid);
//
//                        if (!targetItem)
//                                return;
//
//                        uint8 i = 0;
//
//                        for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT + MAX_GEM_SOCKETS; ++enchant_slot)
//                        {
//                                targetItem->ClearEnchantment(EnchantmentSlot(enchant_slot));
//                                player->AddItem(_gemid[i], 1);
//                                ++i;
//                        }
//                        player->DestroyItemCount(item->GetEntry(), 1, true);
//                }
//        }
//};

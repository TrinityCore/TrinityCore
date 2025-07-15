-- npc professions tailor
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8530,8531,8532) AND `OptionID` IN (1,2);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8531, 1, 0, 'Please teach me how to become a Spellcloth tailor', 20241, 0, 0, 0, 0, 0, 200000, '*WARNING!* You can only select one tailoring specialization.', 20246, 0),
(8531, 2, 0, 'I wish to unlearn Spellfire Tailoring', 21566, 0, 0, 0, 0, 0, 1500000, 'Forgetting your skill in Spellfire Tailoring is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Spellfire Tailoring to create!$b$bAre you absolutely sure?', 21660, 0),
(8530, 1, 0, 'Please teach me how to become a Mooncloth tailor', 20240, 0, 0, 0, 0, 0, 200000, '*WARNING!* You can only select one tailoring specialization.', 20247, 0),
(8530, 2, 0, 'I wish to unlearn Mooncloth Tailoring', 21659, 0, 0, 0, 0, 0, 1500000, 'Forgetting your skill in Mooncloth Tailoring is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Mooncloth Tailoring to create!$b$bAre you absolutely sure?', 21662, 0),
(8532, 1, 0, 'Please teach me how to become a Shadoweave tailor', 20237, 0, 0, 0, 0, 0, 200000, '*WARNING!* You can only select one tailoring specialization.', 20248, 0),
(8532, 2, 0, 'I wish to unlearn Shadoweave Tailoring', 21658, 0, 0, 0, 0, 0, 1500000, 'Forgetting your skill in Shadoweave Tailoring is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Shadoweave Tailoring to create!$b$bAre you absolutely sure?', 21661, 0);

-- npc professions alchemy (https://tbc.wowhead.com/spell=41564/unlearn-elixir-mastery#comments)
UPDATE `creature_template` SET `ScriptName`='npc_prof_alchemy' WHERE `entry` IN (17909,19052,22427);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (7571,8540,8542) AND `OptionID` IN (1,2);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8542, 1, 0, 'I\'ve trained as an alchemist once again.  I wish to specialize in transmutations.', 20292, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(8542, 2, 0, 'I wish to unlearn Transmutation Mastery.', 21876, 0, 0, 0, 0, 0, 1500000, 'Forgetting your skill in Transmutation Mastery is not something to do lightly.Are you absolutely sure?', 21872, 0),
(8540, 1, 0, 'I\'ve trained as an alchemist once again.  I wish to specialize in elixirs.', 20289, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(8540, 2, 0, 'I wish to unlearn Elixir Mastery.', 21875, 0, 0, 0, 0, 0, 1500000, 'Forgetting your skill in Elixir Mastery is not something to do lightly.Are you absolutely sure?', 21871, 0),
(7571, 1, 0, 'I\'ve trained as an alchemist once again.  I wish to specialize in potions.', 20287, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(7571, 2, 0, 'I wish to unlearn Potion Mastery.', 21874, 0, 0, 0, 0, 0, 1500000, 'Forgetting your skill in Potion Mastery is not something to do lightly.Are you absolutely sure?', 21870, 0);

-- npc professions leatherworking
UPDATE `creature_template` SET `gossip_menu_id`=3071 WHERE `entry`=7871;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3067,3068,3069,3070,3071,3072) AND `OptionID` IN (1,2,3,4);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3067, 1, 0, 'I am absolutely certain that I want to learn dragonscale leatherworking.', 11889, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(3067, 2, 0, 'I wish to unlearn dragonscale leatherworking!', 18977, 0, 0, 0, 0, 0, 250000, 'Forgetting dragonscale leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require dragonscale leatherworking as well!', 18976, 0),
(3067, 3, 0, 'I wish to unlearn dragonscale leatherworking!', 18977, 0, 0, 0, 0, 0, 500000, 'Forgetting dragonscale leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require dragonscale leatherworking as well!', 18976, 0),
(3067, 4, 0, 'I wish to unlearn dragonscale leatherworking!', 18977, 0, 0, 0, 0, 0, 1000000, 'Forgetting dragonscale leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require dragonscale leatherworking as well!', 18976, 0),
(3068, 1, 0, 'I am absolutely certain that I want to learn dragonscale leatherworking.', 11889, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(3068, 2, 0, 'I wish to unlearn dragonscale leatherworking!', 18977, 0, 0, 0, 0, 0, 250000, 'Forgetting dragonscale leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require dragonscale leatherworking as well!', 18976, 0),
(3068, 3, 0, 'I wish to unlearn dragonscale leatherworking!', 18977, 0, 0, 0, 0, 0, 500000, 'Forgetting dragonscale leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require dragonscale leatherworking as well!', 18976, 0),
(3068, 4, 0, 'I wish to unlearn dragonscale leatherworking!', 18977, 0, 0, 0, 0, 0, 1000000, 'Forgetting dragonscale leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require dragonscale leatherworking as well!', 18976, 0),
(3070, 1, 0, 'I am absolutely certain that I want to learn elemental leatherworking.', 11890, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(3070, 2, 0, 'I wish to unlearn elemental leatherworking!', 18917, 0, 0, 0, 0, 0, 250000, 'Forgetting elemental leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require elemental leatherworking as well!', 18923, 0),
(3070, 3, 0, 'I wish to unlearn elemental leatherworking!', 18917, 0, 0, 0, 0, 0, 500000, 'Forgetting elemental leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require elemental leatherworking as well!', 18923, 0),
(3070, 4, 0, 'I wish to unlearn elemental leatherworking!', 18917, 0, 0, 0, 0, 0, 1000000, 'Forgetting elemental leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require elemental leatherworking as well!', 18923, 0),
(3069, 1, 0, 'I am absolutely certain that I want to learn elemental leatherworking.', 11890, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(3069, 2, 0, 'I wish to unlearn elemental leatherworking!', 18917, 0, 0, 0, 0, 0, 250000, 'Forgetting elemental leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require elemental leatherworking as well!', 18923, 0),
(3069, 3, 0, 'I wish to unlearn elemental leatherworking!', 18917, 0, 0, 0, 0, 0, 500000, 'Forgetting elemental leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require elemental leatherworking as well!', 18923, 0),
(3069, 4, 0, 'I wish to unlearn elemental leatherworking!', 18917, 0, 0, 0, 0, 0, 1000000, 'Forgetting elemental leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require elemental leatherworking as well!', 18923, 0),
(3072, 1, 0, 'I am absolutely certain that I want to learn tribal leatherworking.', 11891, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(3072, 2, 0, 'I wish to unlearn tribal leatherworking!', 18975, 0, 0, 0, 0, 0, 250000, 'Forgetting tribal leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require tribal leatherworking as well!', 18974, 0),
(3072, 3, 0, 'I wish to unlearn tribal leatherworking!', 18975, 0, 0, 0, 0, 0, 500000, 'Forgetting tribal leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require tribal leatherworking as well!', 18974, 0),
(3072, 4, 0, 'I wish to unlearn tribal leatherworking!', 18975, 0, 0, 0, 0, 0, 1000000, 'Forgetting tribal leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require tribal leatherworking as well!', 18974, 0),
(3071, 1, 0, 'I am absolutely certain that I want to learn tribal leatherworking.', 11891, 0, 0, 0, 0, 0, 200000, NULL, 0, 0),
(3071, 2, 0, 'I wish to unlearn tribal leatherworking!', 18975, 0, 0, 0, 0, 0, 250000, 'Forgetting tribal leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require tribal leatherworking as well!', 18974, 0),
(3071, 3, 0, 'I wish to unlearn tribal leatherworking!', 18975, 0, 0, 0, 0, 0, 500000, 'Forgetting tribal leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require tribal leatherworking as well!', 18974, 0),
(3071, 4, 0, 'I wish to unlearn tribal leatherworking!', 18975, 0, 0, 0, 0, 0, 1000000, 'Forgetting tribal leatherworking is not something to do lightly.  If you choose to abandon it you will forget all recipes that require tribal leatherworking as well!', 18974, 0);

-- npc professions blacksmithing
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3182,3187,3201,3202,597,3203) AND `OptionID` IN (1,2);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6090,6089,6091) AND `OptionID` IN (1,2,3,4);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3182, 1, 0, 'I wish to become a weaponsmith.', 6477, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(3182, 2, 0, 'I wish to become an armorsmith.', 6476, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(3187, 1, 0, 'I wish to become a weaponsmith.', 6477, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(3187, 2, 0, 'I wish to become an armorsmith.', 6476, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(3201, 1, 0, 'I wish to unlearn Weaponsmithing!', 19007, 0, 0, 0, 0, 0, 50000, 'Forgetting your Weaponsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Weaponsmithing to create!', 19008, 0),
(3201, 2, 0, 'I wish to unlearn Weaponsmithing!', 19007, 0, 0, 0, 0, 0, 100000, 'Forgetting your Weaponsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Weaponsmithing to create!', 19008, 0),
(3202, 1, 0, 'I wish to unlearn Weaponsmithing!', 19007, 0, 0, 0, 0, 0, 50000, 'Forgetting your Weaponsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Weaponsmithing to create!', 19008, 0),
(3202, 2, 0, 'I wish to unlearn Weaponsmithing!', 19007, 0, 0, 0, 0, 0, 100000, 'Forgetting your Weaponsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Weaponsmithing to create!', 19008, 0),
(597, 1, 0, 'I wish to unlearn Armorsmithing!', 19010, 0, 0, 0, 0, 0, 50000, 'Forgetting your Armorsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Armorsmithing to create!', 19011, 0),
(597, 2, 0, 'I wish to unlearn Armorsmithing!', 19010, 0, 0, 0, 0, 0, 100000, 'Forgetting your Armorsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Armorsmithing to create!', 19011, 0),
(3203, 1, 0, 'I wish to unlearn Armorsmithing!', 19010, 0, 0, 0, 0, 0, 50000, 'Forgetting your Armorsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Armorsmithing to create!', 19011, 0),
(3203, 2, 0, 'I wish to unlearn Armorsmithing!', 19010, 0, 0, 0, 0, 0, 100000, 'Forgetting your Armorsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Armorsmithing to create!', 19011, 0),
(6090, 1, 0, 'Please teach me how to become a hammersmith, Lilith.', 9988, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(6090, 2, 0, 'I wish to unlearn Hammersmithing!', 18990, 0, 0, 0, 0, 0, 250000, 'Forgetting your Hammersmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Hammersmithing to create!', 18991, 0),
(6090, 3, 0, 'I wish to unlearn Hammersmithing!', 18990, 0, 0, 0, 0, 0, 500000, 'Forgetting your Hammersmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Hammersmithing to create!', 18991, 0),
(6090, 4, 0, 'I wish to unlearn Hammersmithing!', 18990, 0, 0, 0, 0, 0, 1000000, 'Forgetting your Hammersmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Hammersmithing to create!', 18991, 0),
(6089, 1, 0, 'Please teach me how to become an axesmith, Kilram.', 9985, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(6089, 2, 0, 'I wish to unlearn Axesmithing!', 18986, 0, 0, 0, 0, 0, 250000, 'Forgetting your Axesmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Axesmithing to create!', 18987, 0),
(6089, 3, 0, 'I wish to unlearn Axesmithing!', 18986, 0, 0, 0, 0, 0, 500000, 'Forgetting your Axesmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Axesmithing to create!', 18987, 0),
(6089, 4, 0, 'I wish to unlearn Axesmithing!', 18986, 0, 0, 0, 0, 0, 1000000, 'Forgetting your Axesmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require Axesmithing to create!', 18987, 0),
(6091, 1, 0, 'Please teach me how to become a swordsmith, Seril.', 9991, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(6091, 2, 0, 'I wish to unlearn Swordsmithing!', 18982, 0, 0, 0, 0, 0, 250000, 'Forgetting your swordsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require swordsmithing to create!', 18983, 0),
(6091, 3, 0, 'I wish to unlearn Swordsmithing!', 18982, 0, 0, 0, 0, 0, 500000, 'Forgetting your swordsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require swordsmithing to create!', 18983, 0),
(6091, 4, 0, 'I wish to unlearn Swordsmithing!', 18982, 0, 0, 0, 0, 0, 1000000, 'Forgetting your swordsmithing skill is not something to do lightly.  If you choose to abandon it you will forget all recipes that require swordsmithing to create!', 18983, 0);

-- npc professions engineering
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6092,6094,8308,8306) AND `OptionID` IN (2);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6092, 2, 0, 'This Dimensional Imploder sounds dangerous!  How can I make one?', 9994, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(6094, 2, 0, 'I must build a beacon for this marvelous device!', 9997, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(8308, 2, 0, 'This Dimensional Imploder sounds dangerous!  How can I make one?', 9994, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(8306, 2, 0, 'I must build a beacon for this marvelous device!', 9997, 0, 0, 0, 0, 0, 0, NULL, 0, 0);

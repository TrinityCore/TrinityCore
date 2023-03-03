-- Engineering Trainer Dazaralor NPC Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '131840';
UPDATE `creature_template` SET `gossip_menu_id` = '23267' WHERE `entry` = '131840';
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (23267, 1, 1, 'Let me browse your goods.', 2823, 3, 128, 27481);
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (23267, 0, 3, 'Train me in Engineering.', 47119, 5, 16, 27481);
REPLACE INTO `gossip_menu`(`MenuId`, `TextId`, `VerifiedBuild`) VALUES (23267, 36051, 27481);

-- Jewelcrafting Trainer Dazaralor Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '122695';
UPDATE `creature_template` SET `gossip_menu_id` = '21870' WHERE `entry` = '122695';
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (21870, 1, 1, 'Let me browse your goods.', 2823, 3, 128, 27481);
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (21870, 0, 3, 'Train me in Jewelcrafting.', 47114, 5, 16, 27481);
REPLACE INTO `gossip_menu`(`MenuId`, `TextId`, `VerifiedBuild`) VALUES (21870, 33427, 27481);

-- Leatherworking Trainer Dazaralor Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '122698';
UPDATE `creature_template` SET `gossip_menu_id` = '23263' WHERE `entry` = '122698';
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (23263, 1, 1, 'Let me browse your goods.', 2823, 3, 128, 27481);
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (23263, 0, 3, 'Train me in Leatherworking.', 47115, 5, 16, 27481);
REPLACE INTO `gossip_menu`(`MenuId`, `TextId`, `VerifiedBuild`) VALUES (23263, 36036, 27481);

-- Tailoring Trainer Dazaralor Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '122700';
UPDATE `creature_template` SET `gossip_menu_id` = '23265' WHERE `entry` = '122700';
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (23265, 1, 1, 'Let me browse your goods.', 2823, 3, 128, 27481);
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (23265, 0, 3, 'Train me in Tailoring.', 47118, 5, 16, 27481);
REPLACE INTO `gossip_menu`(`MenuId`, `TextId`, `VerifiedBuild`) VALUES (23265, 36045, 27481);

-- Inscription Trainer Dazaralor Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '132264';
UPDATE `creature_template` SET `gossip_menu_id` = '21872' WHERE `entry` = '132264';
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (21872, 3, 1, 'Let me browse your goods.', 2823, 3, 128, 27481);
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (21872, 0, 3, 'Train me in Inscription.', 47113, 5, 16, 27481);
REPLACE INTO `gossip_menu`(`MenuId`, `TextId`, `VerifiedBuild`) VALUES (21872, 33429, 27481);

-- Inscription Trainer Dazaralor 2 Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '130901';
UPDATE `creature_template` SET `gossip_menu_id` = '21874' WHERE `entry` = '130901';
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (21874, 3, 1, 'Let me browse your goods.', 2823, 3, 128, 27481);
REPLACE INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES (21874, 0, 3, 'Train me in Inscription.', 47113, 5, 16, 27481);
REPLACE INTO `gossip_menu`(`MenuId`, `TextId`, `VerifiedBuild`) VALUES (21874, 33429, 27481);

-- Blacksmithing Trainer Dazaralor
UPDATE `creature_template` SET `npcflag` = '4307' WHERE `entry` = '127112';

-- Skinning Trainer Dazaralor
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '122699';
UPDATE `npc_vendor` SET `OverrideGoldCost` = 10000000 WHERE `entry` = 122699 AND `item` = 163839;

-- Mining Trainer Dazaralor 
UPDATE `npc_vendor` SET `OverrideGoldCost` = 10000000 WHERE `entry` = 122694 AND `item` = 163837;

-- Enchanting Trainer Dazaralor
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '122702';

-- Alchemy Trainer Dazaralor
UPDATE `creature_template` SET `npcflag` = '211' WHERE `entry` = '122703';
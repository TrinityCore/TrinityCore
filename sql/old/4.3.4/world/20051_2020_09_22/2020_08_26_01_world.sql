UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=9015 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=8886 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=7777 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=7777 AND `OptionIndex`=10);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3329 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3329 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=10769 AND `OptionIndex`=8);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=11134 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=11135 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3354 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3354 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3533 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3580 AND `OptionIndex`=6);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=3283 AND `OptionIndex`=3);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=7788 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=7777 AND `OptionIndex`=9);
UPDATE `gossip_menu_option_action` SET `ActionPoiId`=0 WHERE (`MenuId`=7788 AND `OptionIndex`=4);

UPDATE `gossip_menu_option` SET `OptionText`='Teach me the ways of the spirits.', `OptionBroadcastTextId`=7658, `VerifiedBuild`=15050 WHERE (`MenuId`=5123 AND `OptionIndex`=0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=8540;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES
(8540, 0, 3, 'I would like to train.', 0, 0, 0, 15050),
(8540, 1, 0, 'I wish to unlearn Elixir Mastery.', 21875, 1, 1, 0),
(8540, 2, 0, 'I\'ve trained as an alchemist once again.  I wish to specialize in elixirs.', 20289, 1, 1, 0);


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8540;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8540, 1, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, '', 'Gossip option requires level 68 or higher'),
(15, 8540, 1, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, '', 'Gossip option requires an Alchemy skill of 350 or higher'),
(15, 8540, 1, 0, 0, 25, 0, 28677, 0, 0, 0, 0, 0, '', 'Gossip option requires player to have the spell \'Elixir Master\' learned'),
(15, 8540, 2, 0, 0, 27, 0, 68, 3, 0, 0, 0, 0, '', 'Gossip option requires level 68 or higher'),
(15, 8540, 2, 0, 0, 7, 0, 171, 350, 0, 0, 0, 0, '', 'Gossip option requires an Alchemy skill of 350 or higher'),
(15, 8540, 2, 0, 0, 25, 0, 28672, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Transmutation Master\' NOT learned'),
(15, 8540, 2, 0, 0, 25, 0, 28677, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Elixir Master\' NOT learned'),
(15, 8540, 2, 0, 0, 25, 0, 28675, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Potion Master\' NOT learned'),
(15, 8540, 2, 0, 0, 8, 0, 10899, 0, 0, 0, 0, 0, '', 'Gossip option requires player to have the quest \'Master of Transmutation\' rewarded OR'),
(15, 8540, 2, 0, 1, 27, 0, 68, 3, 0, 0, 0, 0, '', 'Gossip option requires level 68 or higher'),
(15, 8540, 2, 0, 1, 7, 0, 171, 350, 0, 0, 0, 0, '', 'Gossip option requires an Alchemy skill of 350 or higher'),
(15, 8540, 2, 0, 1, 25, 0, 28672, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Transmutation Master\' NOT learned'),
(15, 8540, 2, 0, 1, 25, 0, 28677, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Elixir Master\' NOT learned'),
(15, 8540, 2, 0, 1, 25, 0, 28675, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Potion Master\' NOT learned'),
(15, 8540, 2, 0, 1, 8, 0, 10902, 0, 0, 0, 0, 0, '', 'Gossip option requires player to have the quest \'Master of Elixirs\' rewarded OR'),
(15, 8540, 2, 0, 2, 27, 0, 68, 3, 0, 0, 0, 0, '', 'Gossip option requires level 68 or higher'),
(15, 8540, 2, 0, 2, 7, 0, 171, 350, 0, 0, 0, 0, '', 'Gossip option requires an Alchemy skill of 350 or higher'),
(15, 8540, 2, 0, 2, 25, 0, 28672, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Transmutation Master\' NOT learned'),
(15, 8540, 2, 0, 2, 25, 0, 28677, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Elixir Master\' NOT learned'),
(15, 8540, 2, 0, 2, 25, 0, 28675, 0, 0, 1, 0, 0, '', 'Gossip option requires player to have the spell \'Potion Master\' NOT learned'),
(15, 8540, 2, 0, 2, 8, 0, 10897, 0, 0, 0, 0, 0, '', 'Gossip option requires player to have the quest \'Master of Potions\' rewarded');

UPDATE `gossip_menu_option` SET `OptionText`='Yes, Scryer.  You may possess me.', `VerifiedBuild`=15050 WHERE (`MenuId`=8510 AND `OptionIndex`=0);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=12052 AND `OptionIndex`=2) OR (`MenuId`=12052 AND `OptionIndex`=1) OR (`MenuId`=8497 AND `OptionIndex`=0) OR (`MenuId`=10767 AND `OptionIndex`=14) OR (`MenuId`=1969 AND `OptionIndex`=0) OR (`MenuId`=6917 AND `OptionIndex`=0) OR (`MenuId`=12914 AND `OptionIndex`=0) OR (`MenuId`=12799 AND `OptionIndex`=0) OR (`MenuId`=12827 AND `OptionIndex`=0) OR (`MenuId`=12826 AND `OptionIndex`=0) OR (`MenuId`=1161 AND `OptionIndex`=0) OR (`MenuId`=8851 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(12052, 2, 10371, 0),
(12052, 1, 4463, 0),
(8497, 0, 8397, 0),
(10767, 14, 10762, 0),
(1969, 0, 8765, 0),
(6917, 0, 6936, 0),
(12914, 0, 12915, 0),
(12799, 0, 12902, 0),
(12827, 0, 12828, 0),
(12826, 0, 12827, 0),
(1161, 0, 1162, 0),
(8851, 2, 12855, 0);

UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10755,`ActionPoiId`=0 WHERE (`MenuId`=10769 AND `OptionIndex`=7);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10766,`ActionPoiId`=0 WHERE (`MenuId`=10769 AND `OptionIndex`=10);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6211,`ActionPoiId`=0 WHERE (`MenuId`=6209 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=6211,`ActionPoiId`=0 WHERE (`MenuId`=6187 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=4463,`ActionPoiId`=0 WHERE (`MenuId`=4667 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=4463,`ActionPoiId`=0 WHERE (`MenuId`=4529 AND `OptionIndex`=1);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=10744,`ActionPoiId`=0 WHERE (`MenuId`=10767 AND `OptionIndex`=4);

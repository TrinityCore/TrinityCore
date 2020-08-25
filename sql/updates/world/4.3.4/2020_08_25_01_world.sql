DELETE FROM `gossip_menu_option` WHERE (`MenuId`=4005 AND `OptionIndex`=1) OR (`MenuId`=3162 AND `OptionIndex`=1) OR (`MenuId`=4006 AND `OptionIndex`=1) OR (`MenuId`=708 AND `OptionIndex`=1) OR (`MenuId`=708 AND `OptionIndex`=0) OR (`MenuId`=12825 AND `OptionIndex`=0) OR (`MenuId`=10780 AND `OptionIndex`=0) OR (`MenuId`=11607 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(4005, 1, 1, 'I would like to buy from you.', 2583, 15354), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(3162, 1, 1, 'I would like to buy from you.', 2583, 15354), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(4006, 1, 1, 'I would like to buy from you.', 2583, 15354), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(708, 1, 8, 'I want to create a guild crest.', 3415, 15354),
(708, 0, 7, 'How do I form a guild?', 3413, 15354),
(12825, 0, 0, 'Here\'s some water, Anren. Let\'s get you out of this cave.', 51760, 15354),
(10780, 0, 0, 'I brought you something to eat.', 36351, 15354),
(11607, 0, 0, 'L\'ghorek, can you give me another Attuned Runestone of Binding?', 44517, 15354);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 52940, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12977) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 52357, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12799) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 49776, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12646) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 48869, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12449) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12433) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 48133, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12353) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47684, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12279) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47686, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12278) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47688, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12277) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47674, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12276) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47676, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12275) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47678, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12274) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47662, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12273) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47664, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12272) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46824, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12147) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46824, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12146) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 45533, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 12017) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 43650, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 11689) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 42597, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 11626) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37806, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10963) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37780, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10960) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37520, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10941) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37476, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10938) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37474, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10937) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37472, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10935) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36975, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10882) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36829, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10858) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36406, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10797) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36361, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10785) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36359, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10784) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36355, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10782) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36353, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10781) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36410, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10780) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36399, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10780) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 34245, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10437) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 32154, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10082) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 44649, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10078) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 32176, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10043) AND (`OptionIndex` = 12);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 32180, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10043) AND (`OptionIndex` = 10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 33141, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 10043) AND (`OptionIndex` = 8);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 7869) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 3398, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 7812) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 12535, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 7290) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 12599, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 7290) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 12082, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 7147) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 11026, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 6629) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 1290) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 4308, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 1290) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 4419, `VerifiedBuild` = 15354 WHERE  (`MenuId` = 1141) AND (`OptionIndex` = 0);

--
SET @ENTRY := 27914;
UPDATE `creature_template` SET `gossip_menu_id`=9619, `npcflag`=129 WHERE `entry`=@ENTRY;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9619;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9619, 0, 0, 'How does this work?', 27298, 1, 1, 9620, 0, 0, 0, '', 0),
(9619, 1, 1, 'Show me what you have to trade.', 27299, 3, 128, 0, 0, 0, 0, '', 0);

DELETE FROM `gossip_menu` WHERE `entry` IN (9619,9620) AND `text_id` IN (13005,13006);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(9619, 13005),
(9620, 13006);

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(@ENTRY, 0, 0, 'I have arrived. Shall we set to work, then?', 12, 0, 100, 0, 0, 0, 'Ethereal Soul-Trader', 27295),
(@ENTRY, 1, 0, 'Ah, more essence to capture...', 12, 0, 100, 0, 0, 0, 'Ethereal Soul-Trader', 27336),
(@ENTRY, 2, 0, 'Here is your share.', 12, 0, 100, 0, 0, 0, 'Ethereal Soul-Trader', 27341);

DELETE FROM `npc_text` WHERE `ID` IN (13005,13006);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `BroadcastTextID2`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `BroadcastTextID3`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `BroadcastTextID4`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `BroadcastTextID5`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `BroadcastTextID6`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `BroadcastTextID7`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `VerifiedBuild`) VALUES 
(13005, 'How may this one help you, $gsir:madame;?', '', 27296, 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 18019),
(13006, 'My business partner slays things; I drain a portion of their essence... a pittance, really; the slightest of slivers. It won''t be missed.$B$BStill, to fulfil my portion of the contract, I pay in Ethereal Credits.$B$BOne may redeem these credits for items I sell at any time. I''m bound to have something that will interest you...', '', 27300, 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 18019);

DELETE FROM `npc_vendor` WHERE `entry`=@ENTRY;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(@ENTRY, 0, 38308, 0, 0, 2411), -- Ethereal Essence Sphere
(@ENTRY, 1, 38300, 0, 0, 2411), -- Diluted Ethereum Essence
(@ENTRY, 2, 38294, 0, 0, 2412), -- Ethereal Liqueur
(@ENTRY, 3, 38291, 0, 0, 2408), -- Ethereal Mutagen
(@ENTRY, 4, 38163, 0, 0, 2408), -- Soul-Trader's Head Wrap
(@ENTRY, 5, 38160, 0, 0, 2410), -- Soul-trader's Bindings
(@ENTRY, 6, 38286, 0, 0, 2407), -- Soul-Trader's Pauldrons
(@ENTRY, 7, 38285, 0, 0, 2408), -- Soul-Trader's Waistband
(@ENTRY, 8, 38161, 0, 0, 2409), -- Soul-Trader's Gloves
(@ENTRY, 9, 38162, 0, 0, 2409); -- Soul-Trader's Boots

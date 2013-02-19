-- Quest 11082 Seeker of Truth
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8701 AND `text_id`=10940;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8701,10940);
DELETE FROM `gossip_menu` WHERE `entry`=8695 AND `text_id`=10941;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8695,10941);
DELETE FROM `gossip_menu` WHERE `entry`=8700 AND `text_id`=10942;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8700,10942);
DELETE FROM `gossip_menu` WHERE `entry`=8699 AND `text_id`=10943;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8699,10943);
DELETE FROM `gossip_menu` WHERE `entry`=8698 AND `text_id`=10944;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8698,10944);
DELETE FROM `gossip_menu` WHERE `entry`=8697 AND `text_id`=10945;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8697,10945);
DELETE FROM `gossip_menu` WHERE `entry`=8696 AND `text_id`=10946;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8696,10946);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8701 WHERE `entry`=23309;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8701,8695,8700,8699,8698,8697) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8701,0,0, 'I am here for you, overseer.',1,1,8695,0,0,0, ''),
(8695,0,0, 'How dare you question an overseer of the Dragonmaw!',1,1,8700,0,0,0, ''),
(8700,0,0, 'Who speaks of me? What are you talking about, broken?',1,1,8699,0,0,0, ''),
(8699,0,0, 'Continue please.',1,1,8698,0,0,0, ''),
(8698,0,0, 'Who are these bidders?',1,1,8697,0,0,0, ''),
(8697,0,0, 'Well... yes.',1,1,8696,0,0,0, '');
-- Gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8701;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8701,0,0,9,11082,0,0,0,'','Show gossip option if player has Quest 11082 Seeker of Truth');
-- Insert npc_text from http://www.wowwiki.com/Quest:Seeker_of_Truth
DELETE FROM `npc_text` WHERE `ID` BETWEEN 10940 AND 10946;
INSERT INTO `npc_text` (`ID`,`prob0`,`text0_0`,`text0_1`,`lang0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`prob1`,`text1_0`,`text1_1`,`lang1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`prob2`,`text2_0`,`text2_1`,`lang2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`prob3`,`text3_0`,`text3_1`,`lang3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`prob4`,`text4_0`,`text4_1`,`lang4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`prob5`,`text5_0`,`text5_1`,`lang5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`prob6`,`text6_0`,`text6_1`,`lang6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`prob7`,`text7_0`,`text7_1`,`lang7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(10940,1,'<The Murkblood overseer grunts.>','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1),
(10941,1,'They sent you to kill me, eh? So predictable... Creatures ruled by terror are all the same.$B$BBut you... You are not one of them...','',0,0,6,0,274,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1),
(10942,1,'Overseer?$B$BYou are no more an overseer than I am the king of Stormwind. Yes... You are the one they speak of.','',0,0,6,0,396,0,273,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1),
(10943,1,'The Netherwing. They speak to us. They offered us peace and protection. Something the broken have never truly felt. We accepted their offer and assisted Toranaku in rousing the creatures of this mine - at great personal cost to us. Many of my brothers gave their lives for this offensive. We were attempting to make the mine uninhabitable, forcing the Dragonmaw to relocate and ultimately move off of this island.','',0,0,396,0,396,0,396,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1),
(10944,1,'The Dragonmaw are corrupt. They are strip-mining this island of all natural resources and using those resources to supply Illidan''s armies out of the Black Temple. They take much for themselves, however, and sell whatever they have hidden away to the highest bidder.','',0,0,396,0,396,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1),
(10945,1,'We do not know. We believe that the Black dragonflight is involved as are some independent third parties. That is why you are here, <race>. You will unravel this mystery from the inside and bring redemption to Netherwing.$B$BAnd now... I can only assume she asked you to bring back my hand.','',0,0,274,0,396,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1),
(10946,1,'I gladly make such a sacrifice if it means the downfall of the Dragonmaw.','',0,0,273,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,1);
-- SAI for Murkblood Overseer
SET @ENTRY := 23309; -- NPC entry
SET @SPELL := 41121; -- Giving a Hand
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,8697,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0,'Murkblood Overseer - On gossip Option select - cast spell');
-- Add item 32726 "Murkblood Escape Plans" to creature loot by Warpten
DELETE FROM `creature_loot_template` WHERE `item`=32726;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(23286,32726,15,1,0,1,1),
(23324,32726,15,1,0,1,1);
-- Loot Conditions by mweinelt
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup` IN (23286,23324)  AND `SourceEntry`=32726;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,23286,32726,0,5,1015,4,0,0, '', 'Murkblood Escape Plans - when Netherwing friendly'),
(1,23324,32726,0,5,1015,4,0,0, '', 'Murkblood Escape Plans - when Netherwing friendly'),
(1,23286,32726,1,2,32726,1,0,0, '', 'Murkblood Escape Plans - can only have one at a time'),
(1,23324,32726,1,2,32726,1,0,0, '', 'Murkblood Escape Plans - can only have one at a time'),
(1,23286,32726,2,9,11081,1,0,0, '', 'Murkblood Escape Plans - not when q11081 already taken'),
(1,23324,32726,2,9,11081,1,0,0, '', 'Murkblood Escape Plans - not when q11081 already taken');

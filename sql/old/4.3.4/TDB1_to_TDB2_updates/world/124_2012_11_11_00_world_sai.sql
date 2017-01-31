-- Update creature gossip_menu_option from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8803,8808,8894,9045,9621,9879,9895,9987,10117,10218) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9879 AND `id`=1;                 
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8803,0,1, 'I need some booze, Coot.',3,128,0,0,0,0, ''),
(8808,0,1, 'I require some components, Sorely.',3,128,0,0,0,0, ''),
(8894,0,0, 'I need to fly to the Windrunner Official business!',1,1,0,0,0,0, ''),
(9045,0,0, 'I don''t have time for chit-chat, Lou. Take me to Scalawag Point.',1,1,0,0,0,0, ''),
(9621,0,0, 'Harry said I could use his bomber to Bael''gun''s. I''m ready to go!',1,1,0,0,0,0, ''),
(9879,0,3, 'Train me',5,16,0,0,0,0, ''),
(9879,1,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),
(9895,0,3, 'Train me',5,16,0,0,0,0, ''),
(9987,0,3, 'Train me',5,16,0,0,0,0, ''),
(10117,0,3, 'Train me',5,16,0,0,0,0, ''),
(10218,0,0, '<Get in the bomber and return to Scalawag Point.>',1,1,0,0,0,0, '');
-- Insert gossip menu from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8803 AND `text_id`=11287;
DELETE FROM `gossip_menu` WHERE `entry`=8808 AND `text_id`=11297;
DELETE FROM `gossip_menu` WHERE `entry`=8820 AND `text_id`=11352;
DELETE FROM `gossip_menu` WHERE `entry`=8832 AND `text_id`=11418;
DELETE FROM `gossip_menu` WHERE `entry`=8839 AND `text_id`=11436;
DELETE FROM `gossip_menu` WHERE `entry`=8893 AND `text_id`=11655;
DELETE FROM `gossip_menu` WHERE `entry`=8900 AND `text_id`=11691;
DELETE FROM `gossip_menu` WHERE `entry`=8957 AND `text_id`=11746;
DELETE FROM `gossip_menu` WHERE `entry`=8985 AND `text_id`=12130;
DELETE FROM `gossip_menu` WHERE `entry`=9008 AND `text_id`=12170;
DELETE FROM `gossip_menu` WHERE `entry`=9045 AND `text_id`=12222;
DELETE FROM `gossip_menu` WHERE `entry`=9346 AND `text_id`=12646;
DELETE FROM `gossip_menu` WHERE `entry`=9895 AND `text_id`=13738;
DELETE FROM `gossip_menu` WHERE `entry`=9987 AND `text_id`=13841;
DELETE FROM `gossip_menu` WHERE `entry`=10117 AND `text_id`=14043;
DELETE FROM `gossip_menu` WHERE `entry`=10218 AND `text_id`=14205;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(8803,11287),
(8808,11297),
(8820,11352),
(8832,11418),
(8839,11436),
(8893,11655),
(8900,11691),
(8957,11746),
(8985,12130),
(9008,12170),
(9045,12222),
(9346,12646),
(9895,13738),
(9987,13841),
(10117,14043),
(10218,14205);
-- Insert creature gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8803 WHERE `entry`=23737; -- Coot "The Stranger" Albertson
UPDATE `creature_template` SET `gossip_menu_id`=8808 WHERE `entry`=23732; -- Sorely Twitchblade
UPDATE `creature_template` SET `gossip_menu_id`=8820 WHERE `entry`=23862; -- Finlay Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=8832 WHERE `entry`=23770; -- Cannoneer Ely
UPDATE `creature_template` SET `gossip_menu_id`=8839 WHERE `entry`=23906; -- Scout Knowles
UPDATE `creature_template` SET `gossip_menu_id`=8893 WHERE `entry`=24106; -- Scout Valory
UPDATE `creature_template` SET `gossip_menu_id`=8900 WHERE `entry`=24135; -- Greatmother Ankha
UPDATE `creature_template` SET `gossip_menu_id`=8957 WHERE `entry`=23833; -- Explorer Jaren
UPDATE `creature_template` SET `gossip_menu_id`=8985 WHERE `entry`=24544; -- Old Icefin
UPDATE `creature_template` SET `gossip_menu_id`=9008, `npcflag`=`npcflag`|1 WHERE `entry`=24643; -- Grezzix Spindlesnap
UPDATE `creature_template` SET `gossip_menu_id`=9045, `npcflag`=1, `AIName`='SmartAI' WHERE `entry`=24896; -- Lou the Cabin Boy
UPDATE `creature_template` SET `gossip_menu_id`=9346 WHERE `entry`=26540; -- Drenk Spannerspark
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry` IN (24067,24154,24350); -- Mahana Frosthoof, Mary Darrow, Robert Clarke
UPDATE `creature_template` SET `gossip_menu_id`=9879 WHERE `entry`=26959; -- Booker Kells
UPDATE `creature_template` SET `gossip_menu_id`=9895 WHERE `entry`=26960; -- Carter Tiffens
UPDATE `creature_template` SET `gossip_menu_id`=9987 WHERE `entry`=26953; -- Thomas Kolichio
UPDATE `creature_template` SET `gossip_menu_id`=10117 WHERE `entry`=26964; -- Alexandra McQueen
UPDATE `creature_template` SET `gossip_menu_id`=10218, `AIName`='SmartAI' WHERE `entry`=28277; -- Harry's Bomber
-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID` IN (12130,13702);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(12130,'<Old Icefin eyes you warily, his fishy eye blinking as he bobs his head up and down once in a curt dismissal.>','',0,1,0,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(13702,'How may I help you?','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);
-- Insert creature_text from sniff
DELETE FROM `creature_text` WHERE `entry` IN (27923,27933);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27923,0,0,'Hang on to your hat, $N! To Scalawag we go!',12,0,100,0,0,0,'Lou the Cabin Boy'),
(27923,1,0,'YAAARRRRR! Here we be, matey! Scalawag Point!',12,0,100,0,0,0,'Lou the Cabin Boy'),
(27933,0,0,'Enjoy the ride! It''s a one way trip!',12,0,100,3,0,0,'Alanya');
-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8894,9045,9621,10218) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8894,9546) AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8894,0,0,0,9,0,11229,0,0,0,0,'','Bathandler Camille - Show gossip option only if player has taken quest 11229'),
(15,8894,1,0,0,9,0,11170,0,0,0,0,'','Bathandler Camille - Show gossip option only if player has taken quest 11170'),
(15,9045,0,0,0,9,0,11509,0,0,0,0,'','Lou the Cabin Boy - Show gossip option only if player has taken quest 11509'),
(15,9546,1,0,0,9,0,12298,0,0,0,0,'','Greer Orehammer - Show gossip option only if player has taken quest 12298'),
(15,9621,0,0,0,9,0,11567,0,0,0,0,'','Alanya - Show gossip option only if player has taken quest 11567'),
(15,10218,0,0,0,9,0,11567,0,0,0,0,'','Harry''s Bomber - Show gossip option if player has taken quest 11567');
-- SmartAIs
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27933;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=23816;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23859 AND `source_type`=0 AND `id` IN (3,4); -- this npc had already a SmartAI so deleting just the new lines
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23816,24896,27933,28277) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23816,0,0,2,62,0,100,0,8894,0,0,0,85,43074,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bathandler Camille - On gossip select - Invoker spellcast'),
(23816,0,1,2,62,0,100,0,8894,1,0,0,85,43136,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bathandler Camille - On gossip select - Invoker spellcast'),
(23816,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bathandler Camille - On gossip select - Close gossip'),
(23859,0,3,4,62,0,100,0,9546,1,0,0,11,48862,0,0,0,0,0,7,0,0,0,0,0,0,0,'Greer Orehammer - On gossip select - Invoker spellcast'),
(23859,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Greer Orehammer - On gossip select - Close gossip'),
(24896,0,0,1,62,0,100,0,9045,0,0,0,11,50004,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lou the Cabin Boy - On gossip select - Spellcast'),
(24896,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lou the Cabin Boy - On gossip select - Close gossip'),
(27933,0,0,1,62,0,100,0,9621,0,0,0,11,50038,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alanya - On gossip select - Spellcast'),
(27933,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alanya - On gossip select - Close gossip'),
(27933,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alanya - On gossip select - Say line'),
(28277,0,0,1,62,0,100,0,10218,0,0,0,11,61604,0,0,0,0,0,7,0,0,0,0,0,0,0,'Harry''s Bomber - On gossip select - Spellcast'),
(28277,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Harry''s Bomber - On gossip select - Close gossip');
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=24896; -- that was absolutely not correct
DELETE FROM `spell_target_position` WHERE `id` IN (50005,50039,61605);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(50005,571,595.208,-2796.47,-0.124098,3.66519), -- Summon Lou the Cabin Boy
(50039,571,-170.469,-3588.19,-0.221146,4.2586), -- Summon Harry's Bomber
(61605,571,89.7416,-6286.08,1.17903,1.58825); -- Summon Harry's Bomber

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9414 AND `text_id`=12657;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9414,12657);
DELETE FROM `gossip_menu` WHERE `entry`=9428 AND `text_id`=12678;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9428,12678);
DELETE FROM `gossip_menu` WHERE `entry`=9460 AND `text_id`=12720;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9460,12720);
DELETE FROM `gossip_menu` WHERE `entry`=9477 AND `text_id`=12735;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9477,12735);
DELETE FROM `gossip_menu` WHERE `entry`=9483 AND `text_id`=12751;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9483,12751);
DELETE FROM `gossip_menu` WHERE `entry`=9519 AND `text_id`=12824;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9519,12824);
DELETE FROM `gossip_menu` WHERE `entry`=9540 AND `text_id`=12853;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9540,12853);
DELETE FROM `gossip_menu` WHERE `entry`=9571 AND `text_id`=12906;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9571,12906);
DELETE FROM `gossip_menu` WHERE `entry`=9614 AND `text_id`=11607;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9614,11607);
DELETE FROM `gossip_menu` WHERE `entry`=9632 AND `text_id`=13033;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9632,13033);
DELETE FROM `gossip_menu` WHERE `entry`=9785 AND `text_id`=7778;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9785,7778);
DELETE FROM `gossip_menu` WHERE `entry`=10175 AND `text_id`=14122;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10175,14122);
DELETE FROM `gossip_menu` WHERE `entry`=10176 AND `text_id`=14121;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10176,14121);
DELETE FROM `gossip_menu` WHERE `entry`=10177 AND `text_id`=14120;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10177,14120);
DELETE FROM `gossip_menu` WHERE `entry`=10178 AND `text_id`=14119;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10178,14119);
DELETE FROM `gossip_menu` WHERE `entry`=10258 AND `text_id`=14245;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10258,14245);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=26721;
UPDATE `creature_template` SET `gossip_menu_id`=9614 WHERE `entry`=26709;
UPDATE `creature_template` SET `gossip_menu_id`=9617 WHERE `entry`=26379;
UPDATE `creature_template` SET `gossip_menu_id`=9460 WHERE `entry`=26985;
UPDATE `creature_template` SET `gossip_menu_id`=9428 WHERE `entry`=26415;
UPDATE `creature_template` SET `gossip_menu_id`=9540 WHERE `entry`=27243;
UPDATE `creature_template` SET `gossip_menu_id`=348 WHERE `entry`=27027;
UPDATE `creature_template` SET `gossip_menu_id`=9632 WHERE `entry`=27037;
UPDATE `creature_template` SET `gossip_menu_id`=9571 WHERE `entry`=26860;
UPDATE `creature_template` SET `gossip_menu_id`=9477 WHERE `entry`=27125;
UPDATE `creature_template` SET `gossip_menu_id`=9519 WHERE `entry`=27388;
UPDATE `creature_template` SET `gossip_menu_id`=10258 WHERE `entry`=26666;
UPDATE `creature_template` SET `gossip_menu_id`=344 WHERE `entry`=26680;
UPDATE `creature_template` SET `gossip_menu_id`=9785 WHERE `entry`=26853;
UPDATE `creature_template` SET `gossip_menu_id`=348 WHERE `entry`=24149;
UPDATE `creature_template` SET `gossip_menu_id`=9483 WHERE `entry`=27172;
UPDATE `creature_template` SET `gossip_menu_id`=10178 WHERE `entry`=30381;
UPDATE `creature_template` SET `gossip_menu_id`=344 WHERE `entry`=29971;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9614,348,344) AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9513,9632,9785,10178,10177,10176) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9460,9477) AND `id` IN (2);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9477) AND `id` IN (4);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (348,344) AND `id` IN (2,3);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (342) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9614,0,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(9614,1,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(9513,0,0, 'I am ready to be teleported to Dalaran.',1,1,0,0,0,0,0, ''),
(9460,2,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(348,0,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(348,1,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(9632,0,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(9477,2,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(9477,4,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(344,0,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(344,1,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(9785,0,2, 'Show me where I can fly.',4,8192,0,0,0,0,0, ''),
(10178,0,0, 'Tell me of yourself, Xarantaur. Why are you called the Witness?',1,1,10177,0,0,0,0, ''),
(10177,0,0, 'Please, go on.',1,1,10176,0,0,0,0, ''),
(10176,0,0, 'They?',1,1,10175,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=10689 AND `text_id`=14824;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10689,14824);
DELETE FROM `gossip_menu` WHERE `entry`=7856 AND `text_id`=9618;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7856,9618);
DELETE FROM `gossip_menu` WHERE `entry`=7857 AND `text_id`=9620;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7857,9620);
DELETE FROM `gossip_menu` WHERE `entry`=9114 AND `text_id`=10249;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9114,10249);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10689 WHERE `entry`=34771;
UPDATE `creature_template` SET `gossip_menu_id`=8903 WHERE `entry`=33971;
UPDATE `creature_template` SET `gossip_menu_id`=7856 WHERE `entry`=18245;
UPDATE `creature_template` SET `gossip_menu_id`=7857 WHERE `entry`=18913;
UPDATE `creature_template` SET `gossip_menu_id`=9114 WHERE `entry`=21088;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8903,9114) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7856,7857) AND `id` IN (1);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7856) AND `id` IN (2);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7857) AND `id` IN (6);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8903,0,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(7856,1,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(7856,2,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(7857,1,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(7857,6,1, 'What do you have for sale?',3,128,0,0,0,0,0, ''),
(9114,0,5, 'Make this inn your home.',8,65536,0,0,0,0,0, '');

-- Misc Innkeepers SAI
SET @GOSSIP := 342;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6272,6727,6740,6790,8931,24057,27066);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6272,6727,6740,6790,8931,24057,27066);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6272,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Janene - On gossip option 0 select - Close gossip'),
(6272,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Janene - On gossip option 0 select - Player cast Trick or Treat on self'),
(6727,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Brianna - On gossip option 0 select - Close gossip'),
(6727,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Brianna - On gossip option 0 select - Player cast Trick or Treat on self'),
(6740,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Allison - On gossip option 0 select - Close gossip'),
(6740,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Innkeeper Allison - On gossip option 0 select - Player cast Trick or Treat on self'),
(6790,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Trelayne - On gossip option 0 select - Close gossip'),
(6790,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Trelayne - On gossip option 0 select - Player cast Trick or Treat on self'),
(8931,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Heather - On gossip option 0 select - Close gossip'),
(8931,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Heather - On gossip option 0 select - Player cast Trick or Treat on self'),
(24057,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Christina Daniels - On gossip option 0 select - Close gossip'),
(24057,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Christina Daniels - On gossip option 0 select - Player cast Trick or Treat on self'),
(27066,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Jennifer Bell - On gossip option 0 select - Close gossip'),
(27066,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Jennifer Bell - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP;
DELETE FROM `gossip_scripts` WHERE `id`=3420;
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=10211;
DELETE FROM `gossip_scripts` WHERE `id`=1021101;

-- Misc Innkeepers SAI
SET @GOSSIP := 344;
SET @MENUID := 2;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (3934,7714,11116,26680,29971);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3934,7714,11116,26680,29971);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3934,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Boorand Plainswind - On gossip option 2 select - Close gossip'),
(3934,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Boorand Plainswind - On gossip option 2 select - Player cast Trick or Treat on self'),
(7714,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Byula - On gossip option 2 select - Close gossip'),
(7714,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Byula - On gossip option 2 select - Player cast Trick or Treat on self'),
(11116,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Abeqwa - On gossip option 2 select - Close gossip'),
(11116,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Abeqwa - On gossip option 2 select - Player cast Trick or Treat on self'),
(26680,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Aiyan Coldwind - On gossip option 2 select - Close gossip'),
(26680,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Aiyan Coldwind - On gossip option 2 select - Player cast Trick or Treat on self'),
(29971,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Wabada Whiteflower - On gossip option 2 select - Close gossip'),
(29971,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Wabada Whiteflower - On gossip option 2 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 345;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (1464,5111,6734,7744,29926);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1464,5111,6734,7744,29926);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1464,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Helbrek - On gossip option 0 select - Close gossip'),
(1464,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Helbrek - On gossip option 0 select - Player cast Trick or Treat on self'),
(5111,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Firebrew - On gossip option 0 select - Close gossip'),
(5111,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Firebrew - On gossip option 0 select - Player cast Trick or Treat on self'),
(6734,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Hearthstove - On gossip option 0 select - Close gossip'),
(6734,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Hearthstove - On gossip option 0 select - Player cast Trick or Treat on self'),
(7744,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Thulfram - On gossip option 0 select - Close gossip'),
(7744,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Thulfram - On gossip option 0 select - Player cast Trick or Treat on self'),
(29926,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gunda Boldhammer - On gossip option 0 select - Close gossip'),
(29926,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gunda Boldhammer - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1290;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (5814,6928,6930,7731,9356,12196,18957,19319,19470);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5814,6928,6930,7731,9356,12196,18957,19319,19470);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5814,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Thulbek - On gossip option 0 select - Close gossip'),
(5814,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Thulbek - On gossip option 0 select - Player cast Trick or Treat on self'),
(6928,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Grosk - On gossip option 0 select - Close gossip'),
(6928,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Grosk - On gossip option 0 select - Player cast Trick or Treat on self'),
(6930,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Karakul - On gossip option 0 select - Close gossip'),
(6930,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Karakul - On gossip option 0 select - Player cast Trick or Treat on self'),
(7731,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Jayka - On gossip option 0 select - Close gossip'),
(7731,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Jayka - On gossip option 0 select - Player cast Trick or Treat on self'),
(9356,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shul''kar - On gossip option 0 select - Close gossip'),
(9356,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shul''kar - On gossip option 0 select - Player cast Trick or Treat on self'),
(12196,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kaylisk - On gossip option 0 select - Close gossip'),
(12196,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kaylisk - On gossip option 0 select - Player cast Trick or Treat on self'),
(18957,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Grilka - On gossip option 0 select - Close gossip'),
(18957,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Grilka - On gossip option 0 select - Player cast Trick or Treat on self'),
(19319,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Darg Bloodclaw - On gossip option 0 select - Close gossip'),
(19319,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Darg Bloodclaw - On gossip option 0 select - Player cast Trick or Treat on self'),
(19470,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gholah - On gossip option 0 select - Close gossip'),
(19470,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gholah - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Innkeeper Shaussiy does not require script
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry` IN (6737);

-- Misc Innkeepers SAI
SET @GOSSIP := 348;
SET @MENUID := 2;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6741,24342,27027,24149);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6741,24342,27027,24149);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6741,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Norman - On gossip option 2 select - Close gossip'),
(6741,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Norman - On gossip option 2 select - Player cast Trick or Treat on self'),
(24342,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Timothy Holland - On gossip option 2 select - Close gossip'),
(24342,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Timothy Holland - On gossip option 2 select - Player cast Trick or Treat on self'),
(27027,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mrs. Winterby - On gossip option 2 select - Close gossip'),
(27027,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mrs. Winterby - On gossip option 2 select - Player cast Trick or Treat on self'),
(24149,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Basil Osgood - On gossip option 2 select - Close gossip'),
(24149,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Basil Osgood - On gossip option 2 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 349;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6791,6807,11118,29904);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6791,6807,11118,29904);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6791,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Wiley - On gossip option 0 select - Close gossip'),
(6791,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Wiley - On gossip option 0 select - Player cast Trick or Treat on self'),
(6807,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Skindle - On gossip option 0 select - Close gossip'),
(6807,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Skindle - On gossip option 0 select - Player cast Trick or Treat on self'),
(11118,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Vizzie - On gossip option 0 select - Close gossip'),
(11118,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Vizzie - On gossip option 0 select - Player cast Trick or Treat on self'),
(29904,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Smilin'' Slirk Brassknob - On gossip option 0 select - Close gossip'),
(29904,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Smilin'' Slirk Brassknob - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1291;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (295,2352);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (295,2352);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(295,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Farley - On gossip option 0 select - Close gossip'),
(295,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Farley - On gossip option 0 select - Player cast Trick or Treat on self'),
(2352,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Anderson - On gossip option 0 select - Close gossip'),
(2352,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Anderson - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1293;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6736,19495);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6736,19495);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6736,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Keldamyr - On gossip option 0 select - Close gossip'),
(6736,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Keldamyr - On gossip option 0 select - Player cast Trick or Treat on self'),
(19495,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shaunessy - On gossip option 0 select - Close gossip'),
(19495,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shaunessy - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1294;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6747);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6747);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6747,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kauth - On gossip option 0 select - Close gossip'),
(6747,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kauth - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1296;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (2388,5688,6739,25278);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2388,5688,6739,25278);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2388,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shay - On gossip option 0 select - Close gossip'),
(2388,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shay - On gossip option 0 select - Player cast Trick or Treat on self'),
(5688,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Renee - On gossip option 0 select - Close gossip'),
(5688,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Renee - On gossip option 0 select - Player cast Trick or Treat on self'),
(6739,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Bates - On gossip option 0 select - Close gossip'),
(6739,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Bates - On gossip option 0 select - Player cast Trick or Treat on self'),
(25278,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Williamson - On gossip option 0 select - Close gossip'),
(25278,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Williamson - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1297;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (1247);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1247);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1247,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Belm - On gossip option 0 select - Close gossip'),
(1247,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Belm - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 1581;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6735,7736,16458,6738,11103);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6735,7736,16458,6738,11103);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6735,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Saelienne - On gossip option 0 select - Close gossip'),
(6735,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Saelienne - On gossip option 0 select - Player cast Trick or Treat on self'),
(7736,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shyria - On gossip option 0 select - Close gossip'),
(7736,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Shyria - On gossip option 0 select - Player cast Trick or Treat on self'),
(16458,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Faralia - On gossip option 0 select - Close gossip'),
(16458,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Faralia - On gossip option 0 select - Player cast Trick or Treat on self'),
(6738,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kimlya - On gossip option 0 select - Close gossip'),
(6738,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kimlya - On gossip option 0 select - Player cast Trick or Treat on self'),
(11103,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Lyshaerya - On gossip option 0 select - Close gossip'),
(11103,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Lyshaerya - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 441;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (6929);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6929);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6929,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Gryshka - On gossip option 0 select - Close gossip'),
(6929,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Gryshka - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,23,1637,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 6525;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (15174);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15174);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15174,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Calandrath - On gossip option 0 select - Close gossip'),
(15174,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Calandrath - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 6620;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (15433);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15433);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15433,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Delaniel - On gossip option 0 select - Close gossip'),
(15433,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Delaniel - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7173;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (16256);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16256);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16256,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Jessica Chambers - On gossip option 0 select - Close gossip'),
(16256,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Jessica Chambers - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7288;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (17630,16618,16542);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17630,16618,16542);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17630,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Jovia - On gossip option 0 select - Close gossip'),
(17630,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Jovia - On gossip option 0 select - Player cast Trick or Treat on self'),
(16618,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Velandra - On gossip option 0 select - Close gossip'),
(16618,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Velandra - On gossip option 0 select - Player cast Trick or Treat on self'),
(16542,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kalarin - On gossip option 0 select - Close gossip'),
(16542,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kalarin - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7301;
SET @MENUID := 2;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (16826);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16826);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16826,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Sid Limbardi - On gossip option 0 select - Close gossip'),
(16826,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Sid Limbardi - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7324;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (15397);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15397);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15397,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Marniel Amberlight - On gossip option 0 select - Close gossip'),
(15397,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Marniel Amberlight - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7468;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (16553);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16553);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16553,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Caregiver Chellan - On gossip option 0 select - Close gossip'),
(16553,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Caregiver Chellan - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7481;
SET @MENUID := 0;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (18914,18908);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18914,18908);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18914,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Caregiver Isel - On gossip option 0 select - Close gossip'),
(18914,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Caregiver Isel - On gossip option 0 select - Player cast Trick or Treat on self'),
(18908,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kerp - On gossip option 0 select - Close gossip'),
(18908,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Kerp - On gossip option 0 select - Player cast Trick or Treat on self');
-- Add Gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

-- Misc Innkeepers SAI
SET @GOSSIP := 7855;
SET @MENUID := 2;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` IN (18907);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18907);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18907,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Coryth Stoktron - On gossip option 0 select - Close gossip'),
(18907,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Coryth Stoktron - On gossip option 0 select - Player cast Trick or Treat on self');
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=@MENUID;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,@MENUID,0, 'Trick or Treat!',1,1,0,0,0,0,0, '');
-- Add Gossip condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,@MENUID,0,11,24755,0,0,0,'',NULL),(15,@GOSSIP,@MENUID,0,12,12,0,0,0,'',NULL);

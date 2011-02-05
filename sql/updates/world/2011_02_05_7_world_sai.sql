-- Fix Quest 11460 "Trust is Earned"
-- UPDATE Hidalgo the Master Falconer "Add Excelsior to vehicle and add gossip flag"
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` IN (24750,24752);
DELETE FROM `vehicle_accessory` WHERE `entry`=24750;
INSERT INTO `vehicle_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(24750,24751,0,1, 'Excelsior rides Hidalgo the Master Falconer');
DELETE FROM `creature` WHERE `guid`=88103;
-- add missing text to Hidalgo the Master Falconer and Rock Falcon
DELETE FROM `gossip_menu` WHERE `entry` IN (8998,9007) AND `text_id` IN (12153,12168);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(8998,12153),(9007,12168);
-- Add gossip_menu condition for 8998 and 9007
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (8998,9007);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9007;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(14,8998,12185,8,11460,0), -- Must have Quest 11460 rewarded
(14,9007,12168,9,11460,0), -- Must have quest 11460 taken not complete
(15,9007,0,2,34102,1), -- Must have at least 1 count of item 34102
(15,9007,0,9,11460,0); -- Must have quest 11460 taken not complete
-- Creature Gossip_menu_option Update
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9007) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9007,0,0, 'Feed the grub to the Rock Falcon.',1,1,0,0,0,0,0, '');
SET @ENTRY := 24752; -- Rock Falcon SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9007,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'On gossip option Close Gossip'), -- Player needs to cast this on self "not working"
(@ENTRY,0,1,0,61,0,100,0,100,100,100,100,86,44363,0,7,0,0,0,7,0,0,0,0,0,0,0,'Player selfcast spell');

-- Maiden of Winter's Breath Lake SAI For Quest "The Edge Of Winter"
SET @ENTRY := 33303; -- NPC entry
SET @ERROR1 := 1334; -- Error Message 1
SET @ERROR2 := 1335; -- Error Message 2
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,75,45776,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Apply aura on spawn'),
(@ENTRY,0,1,0,8,0,100,0,62767,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,28,45776,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove aura'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Face Player'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text 0'),
(@ENTRY*100,9,3,0,0,0,100,0,6000,6000,6000,6000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text 1'),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,5000,5000,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset Orientation'),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,75,45776,0,0,0,0,0,1,0,0,0,0,0,0,0,'Replace Aura');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=33303;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33303,0,0, 'Thank you, mortal, for freeing me from this curse. I beg you, take this blade.',0,0,100,1,0,0, 'Maiden of Winter''s Breath Lake'),
(33303,1,0, 'It has brought me naught but ill. Mayhap you can find someone who will contain its power.',0,0,100,1,0,0, 'Maiden of Winter''s Breath Lake');
-- Condition Target for Spell Break Curse of Ice must be npc 33303 with aura 45776
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=62767;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`COMMENT`) VALUES
(17,62767,19,33303,0,0,@ERROR1, 'Break Curse of Ice Required Target Maiden of Winter''s Breath Lake'),
(17,62767,1,45776,0,1,@ERROR2, 'Break Curse of Ice Required Target Needs Aura Ice Block');
-- Add Error Strings
DELETE FROM `trinity_string` WHERE `entry` IN (@ERROR1,@ERROR2);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(@ERROR1, 'Requires Maiden of Winter''s Breath Lake'),
(@ERROR2, 'You can''t use that right now');

-- Conversation between Crusader Lord Dalfors & Crusader Sunborn, Argent Vangard "Crusader Lord Dalfors Envoker"
SET @ENTRY := 30224;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
UPDATE `smart_scripts` SET `target_type`=1, `comment`=  'The Ebon Watcher: Load script every 4 min ooc' WHERE `entryorguid`=30377 AND `source_type` =0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,60000,150000,150000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Load script every 2.5 min ooc'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Crusader Lord Dalfors text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,9,30225,0,10,0,0,0,0,'Crusader Sunborn Say text 0'),
(@ENTRY*100,9,2,0,0,0,100,0,4000,4000,0,0,5,14,0,0,0,0,0,9,30225,0,10,0,0,0,0,'Crusader Sunborn emote');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (30224,30225);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30224,0,0, 'What''s on yer mind, lad?',0,0,100,6,0,0, 'Crusader Lord Dalfors'),
(30225,0,0, 'Eversong Woods, Dalfors. I''m thinking about how beautiful it was before Arthas cut a swathe of death through it...',0,0,100,1,0,0, 'Crusader Sunborn');


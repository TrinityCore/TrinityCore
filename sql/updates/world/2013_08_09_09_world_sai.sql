-- Archmage Pentarus SAI
SET @ENTRY := 28160; -- NPC entry
SET @SPELL := 50859;  -- Flight to Sholazar
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,10024,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - On gossip option select  - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - Cast Flight to Sholazar on player'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Archmage Pentarus - Script - say 0');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=28160 AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28160,0,0, 'I''ll send you on my flying machine. Keep your eyes peeled for clues about what might''ve happened to Hemet!',12,0,100,25,0,0, 'Archmage Pentarus');
-- Gossip conditions for Archmage Pentarus
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10024;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10024,0,0,28,12521,0,0,0,'','Show gossip option if player has quest Where in the World is Hemet Nesingwary?');
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10024 AND `id`=1;
/*
-- Add spell target position
DELETE FROM `spell_target_position` WHERE `id`=50859;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(50859,571,5832.892,482.8708,658.2753,0.9121326);
*/
-- Update Archmage Pentarus' Flying Machine
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=28192;

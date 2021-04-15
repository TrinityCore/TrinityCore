-- Fix Quest 13231 The Broken Front and 13232 Finish Me!
-- Dying Soldier SAI
SET @ENTRY  := 31304;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,10040,0,0,0,11,58955,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Cast Alliance Quest Aura on player'),
(@ENTRY,0,1,2,62,0,100,0,10040,3,0,0,11,58955,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Cast Alliance Quest Aura on player'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Close Gossip'),
(@ENTRY,0,3,4,62,0,100,0,10040,1,0,0,85,59226,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Player cast Finish It on npc'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Close Gossip'),
(@ENTRY,0,6,7,8,0,100,0,59226,0,0,0,11,3240,2,0,0,0,0,1,0,0,0,0,0,0,0,'Dying Soldier - On Spellhit - Cast Bloody Explosion on self'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,33,31312,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dying Soldier - On Gossip Option Select - Give Kill credit to player');
-- Update Gossip
SET @GOSSIP := 10040;
-- Add conditions for gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,13948,0,28,13231,0,0,0,0,'','Only show gossip text 13948 if player has quest 13231 Complete'),
(14,@GOSSIP,13948,0,14,13232,0,0,0,0,'','Only show gossip text 13948 if player has quest 13232 Not Taken'),
(14,@GOSSIP,14035,0,9,13232,0,0,0,0,'','Only show gossip text 14035 if player has quest 13232 active');
-- Add conditions for gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,0,0,9,13231,0,0,0,0,'','Only show gossip option 0 if player has if player has quest 13231 active'),
(15,@GOSSIP,1,0,9,13232,0,0,0,0,'','Only show gossip option 1 if player has if player has quest 13232 active'),
(15,@GOSSIP,3,0,28,13231,0,0,0,0,'','Only show gossip option 3 if player has quest 13231 Complete'),
(15,@GOSSIP,3,0,14,13232,0,0,0,0,'','Only show gossip option 3 if player has quest 13232 Not Taken');
-- Update Gossip options
UPDATE `gossip_menu_option` SET `action_menu_id`=10041 WHERE `menu_id`=10040 AND `id`=0;
-- Fix npcflags for Dying Soldier
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=31304;
UPDATE `creature` SET `npcflag`=3 WHERE `guid`=122230;
UPDATE `creature` SET `npcflag`=0 WHERE `guid`=122233;
-- Quest conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`=13232;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,13232,0,28,13231,0,0,0,0, '', 'Quest 13232 Finish Me! Requires Quest 13231 The Broken Front to be complete'),
(20,0,13232,0,28,13231,0,0,0,0, '', 'Quest 13232 Finish Me! Requires Quest 13231 The Broken Front to be complete');

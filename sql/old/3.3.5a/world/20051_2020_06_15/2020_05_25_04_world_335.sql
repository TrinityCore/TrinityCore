-- Inconspicuous Landmark SAI
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 142189;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 142189 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(142189,1,0,0,64,0,100,0,1,0,0,0,0,85,11462,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Inconspicuous Landmark - On Gossip Hello - Self Cast 'Summon Pirate Treasure and Trigger Mob'");

-- Pirate treasure trigger mob
UPDATE `creature_template` SET `flags_extra` = `flags_extra` |0x80 WHERE `entry` = 7898;
UPDATE `smart_scripts` SET `event_flags` = 0, `comment` = "Pirate treasure trigger mob - On Just Created - Run Script" WHERE `entryorguid` = 7898 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `event_param3` = 0, `event_param4` = 0 WHERE `entryorguid` = 789800 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 789800 AND `source_type` = 9 AND `id` = 5;

-- Treasure Hunting Pirate SAI (Source: ACID 4.0.3 Official Data)
-- Original script was without initial timers for the 'Strike' and without the third emote
SET @ID := 7899;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Treasure Hunting Pirate - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,6100,16400,8200,18100,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Treasure Hunting Pirate - In Combat - Cast 'Strike'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Hey!  Get away from our treasure!",12,0,100,0,0,0,3931,0,"Treasure Hunting Pirate"),
(@ID,0,1,"That's our treasure, you lubber!",12,0,100,0,0,0,3932,0,"Treasure Hunting Pirate"),
(@ID,0,2,"We didn't hide this stuff just you could steal it!",12,0,100,0,0,0,3933,0,"Treasure Hunting Pirate");

-- Treasure Hunting Swashbuckler SAI (Source: ACID 4.0.3 Official Data)
-- Original script was without the third emote
SET @ID := 7901;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Treasure Hunting Swashbuckler - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,10200,23100,21900,28400,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Treasure Hunting Swashbuckler - In Combat - Cast 'Disarm'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Hey!  Get away from our treasure!",12,0,100,0,0,0,3931,0,"Treasure Hunting Swashbuckler"),
(@ID,0,1,"That's our treasure, you lubber!",12,0,100,0,0,0,3932,0,"Treasure Hunting Swashbuckler"),
(@ID,0,2,"We didn't hide this stuff just you could steal it!",12,0,100,0,0,0,3933,0,"Treasure Hunting Swashbuckler");

-- Treasure Hunting Buccaneer SAI (Source: ACID 4.0.3 Official Data)
-- Original script was without initial timers for the 'Strike' and without the third emote
SET @ID := 7902;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Treasure Hunting Buccaneer - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,6100,16400,8200,18100,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Treasure Hunting Buccaneer - In Combat - Cast 'Strike'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Hey!  Get away from our treasure!",12,0,100,0,0,0,3931,0,"Treasure Hunting Buccaneer"),
(@ID,0,1,"That's our treasure, you lubber!",12,0,100,0,0,0,3932,0,"Treasure Hunting Buccaneer"),
(@ID,0,2,"We didn't hide this stuff just you could steal it!",12,0,100,0,0,0,3933,0,"Treasure Hunting Buccaneer");
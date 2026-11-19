-- Everything else is done and works well
UPDATE `conditions` SET `SourceEntry` = 10921, `NegativeCondition` = 1 WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 8677;

-- Fel Crystalforge SAI (Source: Current script & https://www.youtube.com/watch?v=WUEOrClIEX8)
SET @ID := 185919;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,1,0,0,62,0,100,0,8672,0,0,0,0,85,40964,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fel Crystalforge - On Gossip Option 0 Selected - Invoker Cast 'Fel Crystalforge: Create 1 Flask'"),
(@ID,1,1,0,62,0,100,0,8672,1,0,0,0,85,40965,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fel Crystalforge - On Gossip Option 1 Selected - Invoker Cast 'Fel Crystalforge: Create 5 Flasks'");

-- Fel Crystalforge SAI (Source: Current script & https://www.youtube.com/watch?v=WUEOrClIEX8)
SET @ID := 185920;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,1,0,0,62,0,100,0,8672,0,0,0,0,85,40964,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fel Crystalforge - On Gossip Option 0 Selected - Invoker Cast 'Fel Crystalforge: Create 1 Flask'"),
(@ID,1,1,0,62,0,100,0,8672,1,0,0,0,85,40965,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fel Crystalforge - On Gossip Option 1 Selected - Invoker Cast 'Fel Crystalforge: Create 5 Flasks'");

-- Bash'ir Crystalforge SAI (Source: Current script & https://www.youtube.com/watch?v=opp2STjJq4s)
SET @ID := 185921;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,1,0,0,62,0,100,0,8677,0,0,0,0,85,40968,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bash'ir Crystalforge - On Gossip Option 0 Selected - Invoker Cast 'Bash'ir Crystalforge: Create 1 Flask'"),
(@ID,1,1,0,62,0,100,0,8677,1,0,0,0,85,40970,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bash'ir Crystalforge - On Gossip Option 1 Selected - Invoker Cast 'Bash'ir Crystalforge: Create 5 Flasks'");

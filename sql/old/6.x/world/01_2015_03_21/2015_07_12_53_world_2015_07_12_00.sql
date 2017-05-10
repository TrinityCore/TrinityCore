--
DELETE FROM `gameobject_template` WHERE `entry`=175622;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `size`, `data3`, `data6`, `VerifiedBuild`) VALUES
(175622,6,477,'Rookery Egg Spawner',1,15745,-1,-18019);

SET @ENTRY   := 10161;  -- NPC entry
SET @SPELL1  := 15750;  -- Rookery Whelp Spawn-in Spell
SET @obj     := 175622; -- Rookery Egg Spawner
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@obj;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@obj;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,11,@SPELL1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rookery Whelp - On spawn - Cast Rookery Whelp Spawn-in Spell'),
(@obj,1,0,0,63,0,100,0,0,0,0,0,99,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rookery Egg Spawner - Jsut created - SET_LOOT_STATE 3');

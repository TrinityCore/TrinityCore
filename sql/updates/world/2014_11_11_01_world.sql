DELETE FROM `creature_template_addon` WHERE `entry`=25383;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(25383, 0, 0x0, 0x1, '45617'); -- 25383 - 45617

DELETE FROM `smart_scripts`  WHERE  `entryorguid`IN(25471,25472,25473) AND `source_type`=0;
UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(25471,25472,25473);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN(4857,4858,4860);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4857,'SmartTrigger'),
(4858,'SmartTrigger'),
(4860,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(4857,4858,4860) AND `source_type`=2;
INSERT  INTO `smart_scripts`  (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)  VALUES
(4857,2,0,1,46,0,100,0,4857,0,0,0,85,45627,2,0,0,0,0,7,0,0,0,0,0,0,0,'Area Trigger 4857 - On Trigger - invoker cast Temple A Credit'),
(4858,2,0,1,46,0,100,0,4858,0,0,0,85,45628,2,0,0,0,0,7,0,0,0,0,0,0,0,'Area Trigger 4858 - On Trigger - invoker cast Temple B Credit'),
(4860,2,0,1,46,0,100,0,4860,0,0,0,85,45629,2,0,0,0,0,7,0,0,0,0,0,0,0,'Area Trigger 4860 - On Trigger - invoker cast Temple C Credit');

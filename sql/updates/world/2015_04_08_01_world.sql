-- Dragonmaw Tower Controller
-- Actionlist SAI
SET @ENTRY := 23370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY, 0, 0,0,10,0,100,0,1,20,15000,15000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Tower Controller - ooc los - Say Line 0");

-- Add text
DELETE FROM `creature_text` WHERE `entry`=23370;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(23370, 0, 0, 'MULVERICK!', 14, 0, 100, 22, 0, 0, 'Dragonmaw Tower Controller', 21429);
       
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`, `ConditionTarget`, `ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@ENTRY,0,0,31,3,22274,0,0,'','event require creature 22274');

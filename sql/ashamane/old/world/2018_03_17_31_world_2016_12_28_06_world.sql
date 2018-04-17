-- The Fallen Exarch (10915)
DELETE FROM `event_scripts` WHERE `id`=14444;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE entry=184999;

DELETE FROM `smart_scripts` WHERE `entryorguid`=184999 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(184999, 1, 0, 0, 64, 0, 100, 0, 1, 0, 0, 0, 12, 22452, 4, 30000, 0, 0, 0, 8, 0, 0, 0, -3361.91, 5153.95, -9.00, 1.57, 'Auchenai Coffin - On Gossip Hello - Summon Creature');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=184999;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 1, 184999, 1, 0, 29, 1, 22452, 80, 0, 1, 0, 0, '', 'No NPC Nearby to run action');

DELETE FROM `creature_template_addon` WHERE `entry`=22452;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(22452,0,1,"17327");

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=22452;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=0 WHERE `entry`=21903;
UPDATE `creature` SET `modelid`=20597 WHERE `id`=21903;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22452 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2245200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22452, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 2245200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - Just created - action list'),
(2245200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, 0, 21024, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - action list - morph'),
(2245200, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - action list - Say Line 0'),
(2245200, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 36004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - action list - CAST 36004'),
(2245200, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.72, 'Reanimated Exarch - action list - Set Orientation'),
(2245200, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - action list - Remove Unit Flags'),
(2245200, 9, 5, 0, 0, 0, 100, 0, 500, 500, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - action list - Attack Start'),
(22452, 0, 1, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 8258, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reanimated Exarch - In Combat - Cast Devotion Aura');

DELETE FROM `creature_text` WHERE `CreatureID`=22452;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(22452, 0, 0, 'You have brought me back too soon! I am weak yet... What is this! Who... It matters not! DIE!', 12, 0, 100, 1, 0, 0, 20298, 'Reanimated Exarch');

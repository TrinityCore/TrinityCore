-- Fuel for the Fire
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 28843;
DELETE FROM `smart_scripts` WHERE `source_type`IN (9) AND `entryorguid`IN (2884400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2884400,9,0,0,0,0,100,0,1000,1000,0,0,11,51744,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakkari Skullcrusher - On Script - Cast Suicide');
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (28873,28875);
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (28875);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(28875, 0, 0, 1, 0);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28873,28875) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2887300,2887500) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28873,0,0,0,54,0,100,0,0,0,0,0,80,2887300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Chieftain - Just summoned - Run Script"),
(2887300,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,3,0,0,23,0,0,0,0,0,0,0,"Drakkari Chieftain - On Script - move to pos"),
(2887300,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Chieftain - On Script - Say Line 0"),
(2887300,9,2,0,0,0,100,0,3000,3000,0,0,11,52602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Chieftain - On Script - cast to summon"),
(28875,0,0,0,54,0,100,0,0,0,0,0,80,2887500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shalewing - On just summoned - Run Script"),
(2887500,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shalewing - On Script - Set active"),
(2887500,9,1,0,0,0,100,0,1000,1000,0,0,11,52613,0,0,0,0,0,23,0,0,0,0,0,0,0,"Shalewing - On Script - cast snow"),
(2887500,9,2,0,0,0,100,0,1000,1000,0,0,85,46957,0,0,0,0,0,23,0,0,0,0,0,0,0,"Shalewing - On Script - cast stunn"),
(2887500,9,3,0,0,0,100,0,1000,1000,0,0,69,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Shalewingn - On Script - move to pos"),
(2887500,9,4,0,0,0,100,0,20000,20000,0,0,41,0,0,0,0,0,0,19,28873,0,0,0,0,0,0,"Drakkari Chieftain - On Script - despawn"),
(2887500,9,5,0,0,0,100,0,500,500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shalewing - On Script - despawn"),
(28875,0,1,0,27,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,6279.0581, -2144.0812, 395.522491,0,"Shalewing - On passenger boarded - Run Script"),
(28875,0,2,3,34,0,100,1,0,1,0,0,86,46598,2,23,0,0,0,1,0,0,0,0,0,0,0,"Shalewing - On movement informer - Cross cast ride"),
(28875,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,28873,0,0,0,0,0,0,"Shalewing - On movement informer - Say Line 1");
-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (28873);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28873,0,0,"We gunna drive all da scourge outta Zul'Drak, mon - startin' with you!",12,0,100,0,0,0,28997,0,"Drakkari Chieftain"),
(28873,0,1,"Die, nasty scourge!",12,0,100,0,0,0,28995,0,"Drakkari Chieftain"),
(28873,0,2,"I come to avenge my bruddas, mon!",12,0,100,0,0,0,28994,0,"Drakkari Chieftain"),
(28873,0,3,"Now you gunna die, mon!",12,0,100,0,0,0,28993,0,"Drakkari Chieftain"),
(28873,1,0,"Aaah....",12,0,100,0,0,0,28999,0,"Drakkari Chieftain"),
(28873,1,1,"Ooof!",12,0,100,0,0,0,29000,0,"Drakkari Chieftain"),
(28873,1,2,"Owww!",12,0,100,0,0,0,29001,0,"Drakkari Chieftain"),
(28873,1,3,"Wha?!...",12,0,100,0,0,0,28998,0,"Drakkari Chieftain");

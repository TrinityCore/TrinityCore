--
SET @SPAWN_GROUP_ID := 402; -- 4

-- Prisoners
UPDATE `creature` SET `StringId` = 'BroggokPrisonerCell1' WHERE `guid` IN (100219,100236,100237);
UPDATE `creature` SET `StringId` = 'BroggokPrisonerCell2' WHERE `guid` IN (99293,100063,100064);
UPDATE `creature` SET `StringId` = 'BroggokPrisonerCell3' WHERE `guid` IN (99859,99908,100217,100218);
UPDATE `creature` SET `StringId` = 'BroggokPrisonerCell4' WHERE `guid` IN (99299,99300,99347,100182);

UPDATE `creature_template` SET `unit_flags` = 32832 WHERE `entry` IN (17398,17429,18612,18603);

UPDATE `creature` SET `unit_flags` = 0, `StringId` = 'BroggokPrisonerHighCell' WHERE `id` IN (17398,17429) AND `unit_flags` = 768;

UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` IN (17398,17429);
UPDATE `creature` SET `spawntimesecs` = 7200 WHERE `id` IN (17398,17429) AND `StringId` IS NULL;

DELETE FROM `creature_text` WHERE `CreatureID` IN (17398,17429);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17398,0,0,"We are the true Horde!",12,0,100,0,0,0,16697,0,"Nascent Fel Orc"),
(17398,0,1,"For Kargath!  For Victory!",12,0,100,0,0,0,16698,0,"Nascent Fel Orc"),
(17398,0,2,"Gakarah ma!",12,0,100,0,0,0,16699,0,"Nascent Fel Orc"),
(17398,0,3,"The blood is our power! ",12,0,100,0,0,0,16700,0,"Nascent Fel Orc"),
(17398,0,4,"Lok'tar Illadari!\n",12,0,100,0,0,0,16701,0,"Nascent Fel Orc"),
(17398,0,5,"This world is OURS!",12,0,100,0,0,0,16702,0,"Nascent Fel Orc"),
(17398,0,6,"Lok narash!",12,0,100,0,0,0,16703,0,"Nascent Fel Orc"),

(17429,0,0,"We are the true Horde!",12,0,100,0,0,0,16697,0,"Fel Orc Neophyte"),
(17429,0,1,"For Kargath!  For Victory!",12,0,100,0,0,0,16698,0,"Fel Orc Neophyte"),
(17429,0,2,"Gakarah ma!",12,0,100,0,0,0,16699,0,"Fel Orc Neophyte"),
(17429,0,3,"The blood is our power! ",12,0,100,0,0,0,16700,0,"Fel Orc Neophyte"),
(17429,0,4,"Lok'tar Illadari!\n",12,0,100,0,0,0,16701,0,"Fel Orc Neophyte"),
(17429,0,5,"This world is OURS!",12,0,100,0,0,0,16702,0,"Fel Orc Neophyte"),
(17429,0,6,"Lok narash!",12,0,100,0,0,0,16703,0,"Fel Orc Neophyte");

DELETE FROM `spawn_group` WHERE `spawnId` IN (100219,100236,100237,99293,100063,100064,99859,99908,100217,100218,99299,99300,99347,100182) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,100219),
(@SPAWN_GROUP_ID+0,0,100236),
(@SPAWN_GROUP_ID+0,0,100237),

(@SPAWN_GROUP_ID+1,0,99293),
(@SPAWN_GROUP_ID+1,0,100063),
(@SPAWN_GROUP_ID+1,0,100064),

(@SPAWN_GROUP_ID+2,0,99859),
(@SPAWN_GROUP_ID+2,0,99908),
(@SPAWN_GROUP_ID+2,0,100217),
(@SPAWN_GROUP_ID+2,0,100218),

(@SPAWN_GROUP_ID+3,0,99299),
(@SPAWN_GROUP_ID+3,0,99300),
(@SPAWN_GROUP_ID+3,0,99347),
(@SPAWN_GROUP_ID+3,0,100182);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Blood Furnace - Broggok Prisoners Cell 1",4), -- 402
(@SPAWN_GROUP_ID+1,"Blood Furnace - Broggok Prisoners Cell 2",4), -- 403
(@SPAWN_GROUP_ID+2,"Blood Furnace - Broggok Prisoners Cell 3",4), -- 404
(@SPAWN_GROUP_ID+3,"Blood Furnace - Broggok Prisoners Cell 4",4); -- 405

-- Broggok Poison Cloud
DELETE FROM `creature_template_addon` WHERE `entry` IN (17662,18602);
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 30914;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 17662;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17662 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17662,0,0,0,11,0,100,2,0,0,0,0,0,11,30914,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Broggok Poison Cloud - On Spawn - Cast 'Poison' (Normal)"),
(17662,0,1,0,11,0,100,4,0,0,0,0,0,11,38462,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Broggok Poison Cloud - On Spawn - Cast 'Poison' (Heroic)"),
(17662,0,2,0,11,0,100,0,0,0,0,0,0,11,19951,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Broggok Poison Cloud - On Spawn - Cast 'Pacify Self'"),
(17662,0,3,0,11,0,100,0,0,0,0,0,0,11,25900,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Broggok Poison Cloud - On Spawn - Cast 'Stun Self'");

-- InCombat Trigger
UPDATE `creature_template` SET `AIName` = 'SmartAI', `flags_extra` = `flags_extra` &~ 2 WHERE `entry` = 16006;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 16006 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16006,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"InCombat Trigger - On AI Initialize - Set Reactstate Passive"),
(16006,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"InCombat Trigger - On Spawn - Set In Combat With Zone");

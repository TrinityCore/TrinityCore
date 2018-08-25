UPDATE `gameobject_template` SET `scriptname`="go_dark_iron_pillow" WHERE `entry`=179828;
UPDATE `gameobject_loot_template` SET `QuestRequired` = 0, `LootMode` = 1 WHERE `entry` = 16841;

DELETE FROM `creature_text` WHERE `CreatureID` IN (14635, 14636);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14636,0,0,"Thieves! Scallywags! Rapscallions! Come face me gigantic pillas!",14,0,100,0,0,0,9810,2,"Chambermaid Pillaclencher"),
(14635,0,0,"Our pillas! Someone has stolen our pillas!",      14,0,100,0,0,0,9799,2,"Sleepy Dark Iron Worker"),
(14635,1,0,"We'll not let this act of madness go unpunished!",14,0,100,0,0,0,9800,2,"Sleepy Dark Iron Worker");


UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName`="" WHERE `entry` = 14636;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 14636 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14636, 0, 0, 0,11, 0, 100,   0,    0,    0,     0,     0, 0,  1,     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - On Respawn - Say Line 0"),
(14636, 0, 1, 0, 0, 0, 100,   0, 2000, 5000, 12000, 20000, 0, 11, 23417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - In Combat - Cast 'Smother'"),
(14636, 0, 2, 0, 0, 0, 100,   0, 5000, 8000, 14000, 20000, 0, 11, 23416, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - In Combat - Cast 'Pillow Fight'"),
(14636, 0, 3, 0, 6, 0, 100, 513,    0,    0,     0,     0, 0, 11, 23408, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - On Just Died - Cast 'Serverside - Drop Pillow DND' (No Repeat)");

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName`="" WHERE `entry` = 179829;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 179829 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(179829,1,0,0,1,0,100,0, 20000, 20000,0,0,0,107,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,"Dark Iron Pillow Event Generator - Out of Combat - Spawn group 0"),
(179829,1,1,0,1,0,100,0, 40000, 40000,0,0,0,107,1,0,0,0,0,0, 0,0,0,0,0,0,0,0,"Dark Iron Pillow Event Generator - Out of Combat - Spawn group 1"),
(179829,1,2,0,1,0,100,0, 60000, 60000,0,0,0, 12,14636,4,300000,0,0,0, 8,0,0,0,-6545.88,-1345.29,208.89,0,"Dark Iron Pillow Event Generator - Out of Combat - Spawn Chambermaid Pillaclencher");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 179829 AND `summonerType` = 1;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(179829,1,0,14635,-6572.45,-1310.50,208.7,4.64,4,60000),
(179829,1,0,14635,-6564.14,-1302.53,208.7,3.03,4,60000),
(179829,1,0,14635,-6570.53,-1308.43,208.7,4.33,4,60000),
(179829,1,0,14635,-6568.07,-1307.88,208.7,0.43,4,60000),
(179829,1,0,14635,-6569.30,-1307.43,208.7,2.28,4,60000),
(179829,1,0,14635,-6570.06,-1309.11,208.7,4.78,4,60000),
(179829,1,0,14635,-6570.92,-1306.46,208.7,2.01,4,60000),
(179829,1,0,14635,-6572.97,-1307.99,208.7,2.73,4,60000),
(179829,1,0,14635,-6570.86,-1305.61,208.7,0.39,4,60000),
(179829,1,0,14635,-6569.16,-1303.52,208.7,1.74,4,60000),
(179829,1,1,14635,-6481.94,-1348.87,212.1,5.26,4,60000),
(179829,1,1,14635,-6484.19,-1351.50,212.1,2.83,4,60000),
(179829,1,1,14635,-6486.89,-1348.43,212.1,4.00,4,60000),
(179829,1,1,14635,-6485.70,-1352.91,212.1,5.37,4,60000),
(179829,1,1,14635,-6485.44,-1352.21,212.1,3.14,4,60000),
(179829,1,1,14635,-6486.94,-1347.89,212.1,2.47,4,60000),
(179829,1,1,14635,-6480.59,-1354.61,212.1,1.74,4,60000),
(179829,1,1,14635,-6484.67,-1347.36,212.1,2.19,4,60000),
(179829,1,1,14635,-6481.27,-1347.58,212.1,2.36,4,60000),
(179829,1,1,14635,-6482.87,-1348.54,212.1,5.01,4,60000);


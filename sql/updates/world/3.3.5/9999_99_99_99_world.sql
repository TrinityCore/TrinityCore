UPDATE `gameobject_template` SET `scriptname`="go_dark_iron_pillow" WHERE `entry`=179828;
UPDATE `gameobject_loot_template` SET `QuestRequired` = 0, `LootMode` = 1 WHERE `entry` = 16841;

DELETE FROM `creature_text` WHERE `CreatureID` IN (14635, 14636);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14636,0,0,"Thieves! Scallywags! Rapscallions! Come face me gigantic pillas!",14,0,100,0,0,0,9810,2,"Chambermaid Pillaclencher"),
(14635,0,0,"Our pillas! Someone has stolen our pillas!",      14,0,100,0,0,0,9799,2,"Sleepy Dark Iron Worker"),
(14635,1,0,"We'll not let this act of madness go unpunished!",14,0,100,0,0,0,9800,2,"Sleepy Dark Iron Worker");


UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 14636;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14636;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14636, 0, 0, 0,11, 0, 100,   0,    0,    0,     0,     0, 0,  1,     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - On Respawn - Say Line 0"),
(14636, 0, 1, 0, 0, 0, 100,   0, 2000, 5000, 12000, 20000, 0, 11, 23417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - In Combat - Cast 'Smother'"),
(14636, 0, 2, 0, 0, 0, 100,   0, 5000, 8000, 14000, 20000, 0, 11, 23416, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - In Combat - Cast 'Pillow Fight'"),
(14636, 0, 3, 0, 6, 0, 100, 513,    0,    0,     0,     0, 0, 11, 23408, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chambermaid Pillaclencher - On Just Died - Cast 'Serverside - Drop Pillow DND' (No Repeat)");

UPDATE `gameobject` SET `rotation0`=0.21970865, `rotation1`=-0.68592155, `rotation2`=0.16001302, `rotation3`=0.6750078 WHERE `guid`=208348;
UPDATE `creature_template` SET `gossip_menu_id`=11651 WHERE  `entry`=234;

DELETE FROM `creature_sparring_template` WHERE `CreatureID` IN (54371, 54372, 54373);
INSERT INTO `creature_sparring_template` (`CreatureID`, `HealthLimitPct`) VALUES
(54371, 85),
(54372, 85),
(54373, 85);

DELETE FROM `creature_text` WHERE `CreatureID` = 42386 AND `GroupID` = 11;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42386, 11, 0, 'Thank you, kind and gentle stranger.', 12, 7, 100, 1, 0, 0, 42486, 'Homeless Stormwind Citizen to Westfall Stew'),
(42386, 11, 1, 'Westfall stew? I\'ll never forget this moment!', 12, 7, 100, 5, 0, 0, 42487, 'Homeless Stormwind Citizen to Westfall Stew'),
(42386, 11, 2, 'I\'d know that smell anywhere! Salma\'s famous stew!', 12, 7, 100, 5, 0, 0, 42488, 'Homeless Stormwind Citizen to Westfall Stew'),
(42386, 11, 3, 'Maybe... maybe life is worth living.', 12, 7, 100, 5, 0, 0, 42489, 'Homeless Stormwind Citizen to Westfall Stew'),
(42386, 11, 4, 'Bless you, friend.', 12, 7, 100, 1, 0, 0, 42490, 'Homeless Stormwind Citizen to Westfall Stew');

DELETE FROM `creature_text` WHERE `CreatureID` = 42384 AND `GroupID` = 12;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42384, 12, 0, 'Thank you, kind and gentle stranger.', 12, 7, 100, 1, 0, 0, 42486, 'Homeless Stormwind Citizen to Westfall Stew'),
(42384, 12, 1, 'Westfall stew? I\'ll never forget this moment!', 12, 7, 100, 5, 0, 0, 42487, 'Homeless Stormwind Citizen to Westfall Stew'),
(42384, 12, 2, 'I\'d know that smell anywhere! Salma\'s famous stew!', 12, 7, 100, 5, 0, 0, 42488, 'Homeless Stormwind Citizen to Westfall Stew'),
(42384, 12, 3, 'Maybe... maybe life is worth living.', 12, 7, 100, 5, 0, 0, 42489, 'Homeless Stormwind Citizen to Westfall Stew'),
(42384, 12, 4, 'Bless you, friend.', 12, 7, 100, 1, 0, 0, 42490, 'Homeless Stormwind Citizen to Westfall Stew');

DELETE FROM `creature_text` WHERE `CreatureID` = 42383 AND `GroupID` = 17;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42383, 17, 0, 'Thank you, kind and gentle stranger.', 12, 7, 100, 1, 0, 0, 42486, 'Homeless Stormwind Citizen to Westfall Stew'),
(42383, 17, 1, 'Westfall stew? I\'ll never forget this moment!', 12, 7, 100, 5, 0, 0, 42487, 'Homeless Stormwind Citizen to Westfall Stew'),
(42383, 17, 2, 'I\'d know that smell anywhere! Salma\'s famous stew!', 12, 7, 100, 5, 0, 0, 42488, 'Homeless Stormwind Citizen to Westfall Stew'),
(42383, 17, 3, 'Maybe... maybe life is worth living.', 12, 7, 100, 5, 0, 0, 42489, 'Homeless Stormwind Citizen to Westfall Stew'),
(42383, 17, 4, 'Bless you, friend.', 12, 7, 100, 1, 0, 0, 42490, 'Homeless Stormwind Citizen to Westfall Stew');

DELETE FROM `creature_text` WHERE `CreatureID` = 42391 AND `GroupID` = 11;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42391, 11, 0, 'Thank you, kind and gentle stranger.', 12, 7, 100, 1, 0, 0, 42486, 'Homeless Stormwind Citizen to Westfall Stew'),
(42391, 11, 1, 'Westfall stew? I\'ll never forget this moment!', 12, 7, 100, 5, 0, 0, 42487, 'Homeless Stormwind Citizen to Westfall Stew'),
(42391, 11, 2, 'I\'d know that smell anywhere! Salma\'s famous stew!', 12, 7, 100, 5, 0, 0, 42488, 'Homeless Stormwind Citizen to Westfall Stew'),
(42391, 11, 3, 'Maybe... maybe life is worth living.', 12, 7, 100, 5, 0, 0, 42489, 'Homeless Stormwind Citizen to Westfall Stew'),
(42391, 11, 4, 'Bless you, friend.', 12, 7, 100, 1, 0, 0, 42490, 'Homeless Stormwind Citizen to Westfall Stew');

DELETE FROM `creature_text` WHERE `CreatureID` = 42400 AND `GroupID` = 6;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42400, 6, 0, 'Thank you, kind and gentle stranger.', 12, 7, 100, 1, 0, 0, 42486, 'Homeless Stormwind Citizen to Westfall Stew'),
(42400, 6, 1, 'Westfall stew? I\'ll never forget this moment!', 12, 7, 100, 5, 0, 0, 42487, 'Homeless Stormwind Citizen to Westfall Stew'),
(42400, 6, 2, 'I\'d know that smell anywhere! Salma\'s famous stew!', 12, 7, 100, 5, 0, 0, 42488, 'Homeless Stormwind Citizen to Westfall Stew'),
(42400, 6, 3, 'Maybe... maybe life is worth living.', 12, 7, 100, 5, 0, 0, 42489, 'Homeless Stormwind Citizen to Westfall Stew'),
(42400, 6, 4, 'Bless you, friend.', 12, 7, 100, 1, 0, 0, 42490, 'Homeless Stormwind Citizen to Westfall Stew');

UPDATE `creature_template` SET `ScriptName`='npc_westfall_homless_stormwind_citizen' WHERE `entry`=42384;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_homless_stormwind_citizen' WHERE `entry`=42386;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_homless_stormwind_citizen' WHERE `entry`=42383;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_westfall_stew' WHERE `entry`=42617;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_west_plains_drifter' WHERE `entry`=42400;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_west_plains_drifter' WHERE `entry`=42391;
UPDATE `creature` SET `ScriptName`='npc_westfall_west_plains_drifter_walk_to_sentinel' WHERE `guid`=280419;

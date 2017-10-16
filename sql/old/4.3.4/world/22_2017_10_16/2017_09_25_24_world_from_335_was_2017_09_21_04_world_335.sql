/*
-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (2949, 2950, 2951);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2949, 2950, 2951) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2949, 0, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Tanner - On Aggro - Say Line 0"),
(2949, 0, 1, 0, 0, 0, 100, 0, 0, 0, 2700, 2700, 11, 9739, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Palemane Tanner - In Combat - Cast 'Wrath'"),
(2949, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Tanner - Between 0-15% Health - Flee For Assist"),
(2950, 0, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Skinner - On Aggro - Say Line 0"),
(2950, 0, 1, 0, 2, 0, 100, 0, 16, 40, 20000, 30000, 11, 774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Skinner - Between 16-40% Health - Cast 'Rejuvenation'"),
(2950, 0, 2, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Skinner - Between 0-15% Health - Flee For Assist"),
(2951, 0, 0, 0, 4, 0, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Poacher - On Aggro - Say Line 0"),
(2951, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3000, 3000, 11, 6660, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Palemane Poacher - In Combat - Cast 'Shoot'"),
(2951, 0, 2, 0, 0, 0, 100, 0, 0, 0, 7000, 13000, 11, 1516, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Palemane Poacher - In Combat - Cast 'Quick Shot'"),
(2951, 0, 3, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Palemane Poacher - Between 0-15% Health - Flee For Assist");

DELETE FROM `creature_text` WHERE `CreatureID` IN (2949, 2950, 2951);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2949, 0, 0, "Grrrr... fresh meat!", 12, 0, 100, 0, 0, 0, 1870, 0, "Palemane Tanner"),
(2949, 0, 1, "More bones to gnaw on...", 12, 0, 100, 0, 0, 0, 1871, 0, "Palemane Tanner"),
(2950, 0, 0, "Grrrr... fresh meat!", 12, 0, 100, 0, 0, 0, 1870, 0, "Palemane Skinner"),
(2950, 0, 1, "More bones to gnaw on...", 12, 0, 100, 0, 0, 0, 1871, 0, "Palemane Skinner"),
(2951, 0, 0, "Grrrr... fresh meat!", 12, 0, 100, 0, 0, 0, 1870, 0, "Palemane Poacher"),
(2951, 0, 1, "More bones to gnaw on...", 12, 0, 100, 0, 0, 0, 1871, 0, "Palemane Poacher");

UPDATE `creature_equip_template` SET `ItemID1`=1900, `VerifiedBuild`=-18019 WHERE `CreatureID`=2950;
UPDATE `creature_equip_template` SET `ItemID1`=1896, `ItemID2`=2051 WHERE `CreatureID`=2951;
*/

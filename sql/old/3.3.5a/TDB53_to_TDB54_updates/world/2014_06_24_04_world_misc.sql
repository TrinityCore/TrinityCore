--
UPDATE `creature` SET `spawntimesecs`=300 WHERE  `guid`=86749;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 21057;

DELETE FROM `smart_scripts` WHERE `entryorguid`=21057;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21057, 0, 0, 1,38, 0, 100, 0, 1, 1, 45000, 45000, 45, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - On Data Set 1 1 - Set Data 10'),
(21057, 0, 1, 2,61, 0, 100, 0, 0, 0, 0, 0, 19, 756, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - Linked with Previous Event - Remove unit flags'),
(21057, 0, 2, 3,61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - Linked with Previous Event - Set Visible'),
(21057, 0, 3, 0,61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - Linked with Previous Event - Say'),
(21057, 0, 4, 5,25, 0, 100, 0, 0, 0, 0, 0, 18, 756, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - On spawn - Add unit flags'),
(21057, 0, 5, 0,61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - Linked with Previous Event - Set Invisible'),
(21057, 0, 6, 7,21, 0, 100, 0, 0, 0, 0, 0, 18, 756, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - On Creature reached home - Add unit flags'),
(21057, 0, 7, 0,61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - Linked with Previous Event - Set Invisible'),
(21057, 0, 8, 0,9, 0, 100, 0, 0, 8, 8000, 11000, 11, 35924, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - On Range - Cast Energy Flux'),
(21057, 0, 9, 10,6, 0, 100, 0, 0, 0, 0, 0, 11, 37957, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Nexus-Prince Razaan - On Death - Spawn Collection of Souls');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 20609;

DELETE FROM `smart_scripts` WHERE `entryorguid`=20609;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20609, 0, 0, 0, 0, 0, 100 , 0, 0, 0, 8000, 11000, 85, 36513, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razaani Nexus Stalker - IC - Cast Intangible Presence'),
(20609, 0, 1, 0, 9, 0, 100 , 0, 0, 10, 6000, 10000, 11, 11975, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razaani Nexus Stalker - On Range - Cast Arcane Explosion'),
(20609, 0, 2, 0, 6, 0, 25 , 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 86749, 21057, 0, 0, 0, 0, 0, 'Razaani Nexus Stalker - On Death - Set Data on Nexus-Prince Razaan');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 20614;

DELETE FROM `smart_scripts` WHERE `entryorguid`=20614;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20614, 0, 0, 0, 9, 0, 100 , 0, 0, 8, 5000, 8000, 11, 36508, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razaani Spell-Thief - On Range - Cast Arcane Explosion'),
(20614, 0, 1, 0, 6, 0, 25 , 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 86749, 21057, 0, 0, 0, 0, 0, 'Razaani Spell-Thief - On Death - Set Data on Nexus-Prince Razaan');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 20601;

DELETE FROM `smart_scripts` WHERE `entryorguid`=20601;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20601, 0, 0, 0, 9, 0, 100 , 0, 0,10, 5000, 8000, 11, 35922, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razaani Raider - On Range - Cast Energy Flare'),
(20601, 0, 1, 0, 0, 0, 100 , 0, 0,5000, 8000, 15000, 11, 32920, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razaani Raider - IC - Cast Warp'),
(20601, 0, 2, 0, 6, 0, 25 , 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 86749, 21057, 0, 0, 0, 0, 0, 'Razaani Raider - On Death - Set Data on Nexus-Prince Razaan');

DELETE FROM `creature_text` WHERE `entry` =21057;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES (21057, 0, 0, 'Who dares to interrupt my operation?', 14, 0, 100, 0, 0, 0, 'Nexus-Prince Razaan', 18714);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=21057;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 21057, 0, 0, 36, 1, 0, 0, 0, 0, 0, '','Only execute SAI if Nexus-Prince Razaan alive');

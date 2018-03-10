-- Stormwind City Guard
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6800,6801,6802,6803,6804) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6800,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted On"),
(6800,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6800,9,2,0,0,0,100,0,2000,2000,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Wave'"),
(6800,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6800,9,4,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted Off"),
(6801,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted On"),
(6801,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6801,9,2,0,0,0,100,0,2000,2000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Salute'"),
(6801,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6801,9,4,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted Off"),
(6802,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted On"),
(6802,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6802,9,2,0,0,0,100,0,2000,2000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Bow'"),
(6802,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6802,9,4,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted Off"),
(6803,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted On"),
(6803,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6803,9,2,0,0,0,100,0,2000,2000,0,0,5,23,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Flex'"),
(6803,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6803,9,4,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted Off"),
(6804,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted On"),
(6804,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6804,9,2,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Play Emote 'Point'"),
(6804,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Orientation"),
(6804,9,4,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Set Rooted Off");

-- Stormwind City Patroller
DELETE FROM `smart_scripts` WHERE `entryorguid`=1976 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10,11);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1976,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind City Patroller - In Combat - Cast 'Shoot'"),
(1976,0,2,0,9,0,100,0,0,5,11000,14000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - Within 0-5 Range - Cast 'Shield Block'"),
(1976,0,3,0,0,0,100,0,5000,9000,8000,13000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind City Patroller - In Combat - Cast 'Revenge'"),
(1976,0,4,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Wave' - Run Script"),
(1976,0,5,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Salute' - Run Script"),
(1976,0,6,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Kiss' - Run Script"),
(1976,0,7,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Shy' - Run Script"),
(1976,0,8,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Rude' - Run Script"),
(1976,0,9,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Chicken' - Run Script"),
(1976,0,10,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On Received Emote 'Bow' - Run Script");

-- Stormwind Royal Guard
DELETE FROM `smart_scripts` WHERE `entryorguid`=1756 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1756,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Royal Guard - In Combat - Cast 'Shoot'"),
(1756,0,2,0,9,0,100,0,0,5,11000,14000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - Within 0-5 Range - Cast 'Shield Block'"),
(1756,0,3,0,0,0,100,0,5000,9000,8000,13000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Royal Guard - In Combat - Cast 'Revenge'"),
(1756,0,4,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Wave' - Run Script"),
(1756,0,5,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Salute' - Run Script"),
(1756,0,6,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Kiss' - Run Script"),
(1756,0,7,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Shy' - Run Script"),
(1756,0,8,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Rude' - Run Script"),
(1756,0,9,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Chicken' - Run Script"),
(1756,0,10,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Received Emote 'Bow' - Run Script");

-- Orgrimmar Grunt
DELETE FROM `smart_scripts` WHERE `entryorguid`=3296 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10,11);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3296,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Orgrimmar Grunt - In Combat - Cast 'Shoot'"),
(3296,0,2,0,0,0,100,0,5000,9000,8000,13000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Orgrimmar Grunt - In Combat - Cast 'Cleave'"),
(3296,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(3296,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - Between 0-30% Health - Say Line 0 (No Repeat)"),
(3296,0,5,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Wave' - Run Script"),
(3296,0,6,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Salute' - Run Script"),
(3296,0,7,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Kiss' - Run Script"),
(3296,0,8,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Shy' - Run Script"),
(3296,0,9,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Rude' - Run Script"),
(3296,0,10,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Chicken' - Run Script"),
(3296,0,11,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On Received Emote 'Bow' - Run Script");

DELETE FROM `creature_text` WHERE `CreatureID`=3296 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3296,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Orgrimmar Grunt");

-- Kor'kron Elite
DELETE FROM `smart_scripts` WHERE `entryorguid`=14304 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10,11);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14304,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Elite - In Combat - Cast 'Shoot'"),
(14304,0,2,0,0,0,100,0,5000,9000,8000,13000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Elite - In Combat - Cast 'Cleave'"),
(14304,0,3,0,2,0,100,0,0,30,120000,120000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - Between 0-30% Health - Cast 'Enrage'"),
(14304,0,4,0,2,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - Between 0-30% Health - Say Line 1 (No Repeat)"),
(14304,0,5,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Wave' - Run Script"),
(14304,0,6,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Salute' - Run Script"),
(14304,0,7,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Kiss' - Run Script"),
(14304,0,8,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Shy' - Run Script"),
(14304,0,9,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Rude' - Run Script"),
(14304,0,10,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Chicken' - Run Script"),
(14304,0,11,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Elite - On Received Emote 'Bow' - Run Script");

DELETE FROM `creature_text` WHERE `CreatureID`=14304 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14304,1,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Kor'kron Elite");

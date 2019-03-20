-- 
DELETE FROM `gameobject` WHERE `guid` IN (6687,6688,6689);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(6687, 188019, 571, 0, 0, 1, 1, 3739.25, 5047.19, 2.57367, 2.70438, -0, -0, -0.9762, -0.21687, 300, 255, 1),
(6688, 188019, 571, 0, 0, 1, 1, 3390.51, 5137.37, 16.1839, 2.64766, -0, -0, -0.969659, -0.244463, 300, 255, 1),
(6689, 188019, 571, 0, 0, 1, 1, 3515.22, 5017.28, 1.93156, 1.74533, -0, -0, -0.766045, -0.642787, 300, 255, 1);

DELETE FROM `creature_text` WHERE `CreatureID`=25807;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25807,0,0,"Are you crazy? You're about to blow us sky high! I'll take care of this wreck once everything else is finished.",12,0,100,0,0,0,25043,0,"Iggy Tailspin Cogtoggle");

DELETE FROM `smart_scripts` WHERE `entryorguid`=-119150 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-119150,0,0,0,8,0,100,512,46171,0,0,0,1,0,0,0,0,0,0,19,25807,20,0,0,0,0,0,"East Crash - On Spellhit - say text");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25845, 25847, 25846) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25845,0,1,0,8,0,100,512,46171,0,0,0,11,34521,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwest Crash - On Spellhit - cast Serverside - Summon Fire"),
(25846,0,1,0,8,0,100,512,46171,0,0,0,11,34521,0,0,0,0,0,1,0,0,0,0,0,0,0,"South Crash - On Spellhit - cast Serverside - Summon Fire"),
(25847,0,1,0,8,0,100,512,46171,0,0,0,11,34521,0,0,0,0,0,1,0,0,0,0,0,0,0,"East Crash - On Spellhit - cast Serverside - Summon Fire");

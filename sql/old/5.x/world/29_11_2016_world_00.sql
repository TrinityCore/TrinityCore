SET @BP_ENTRY = 951;
SET @SI_ENTRY = 49869;

UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id`=@BP_ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BP_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @BP_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@BP_ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1800000, 1800000, 11, 13864, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brother Paxton - Every 30 Minutes - Cast 'Power Word: Fortitude'"),
(@BP_ENTRY, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 53, 0, 95100, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brother Paxton - On Reset - Start Waypoint Path"),
(@BP_ENTRY, 0, 2, 3, 40, 0, 25, 0, 0, 0, 0, 0, 54, 7000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brother Paxton - Pause Waypoint"),
(@BP_ENTRY, 0, 3, 0, 61, 0, 20, 0, 0, 0, 0, 0, 88, 95100, 95103, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brother Paxton - Random Timed Action");
DELETE FROM `waypoints` WHERE `entry`=@BP_ENTRY*100;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@BP_ENTRY*100, 1, -8829.18, -147.578, 80.4889, 'Brother Paxton Waypoint Path 01'),
(@BP_ENTRY*100, 2, -8822.08, -146.456, 80.877, 'Brother Paxton Waypoint Path 02'),
(@BP_ENTRY*100, 3, -8817.2, -150.924, 81.5878, 'Brother Paxton Waypoint Path 03'),
(@BP_ENTRY*100, 4, -8811.99, -159.78, 81.614, 'Brother Paxton Waypoint Path 04');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@BP_ENTRY*100, (@BP_ENTRY*100)+1, (@BP_ENTRY*100)+2, (@BP_ENTRY*100)+3) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@BP_ENTRY*100, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @SI_ENTRY, 10, 0, 0, 0, 0, 0, 'Stormwind Infantry - Yell For Help'),
(@BP_ENTRY*100, 9, 1, 0, 0, 0, 100, 1, 600, 600, 0, 0, 11, 66097, 0, 0, 0, 0, 0, 19, @SI_ENTRY, 10, 0, 0, 0, 0, 0, 'Brother Paxton - Cast Penance'),
(@BP_ENTRY*100, 9, 2, 0, 0, 0, 100, 1, 600, 600, 0, 0, 1, 2, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Say Text'),
((@BP_ENTRY*100)+1, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @SI_ENTRY, 10, 0, 0, 0, 0, 0, 'Stormwind Infantry - Yell For Help'),
((@BP_ENTRY*100)+1, 9, 1, 0, 0, 0, 100, 1, 600, 600, 0, 0, 11, 38588, 0, 0, 0, 0, 0, 19, @SI_ENTRY, 10, 0, 0, 0, 0, 0, 'Brother Paxton - Cast Flash Heal'),
((@BP_ENTRY*100)+1, 9, 2, 0, 0, 0, 100, 1, 600, 600, 0, 0, 1, 2, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Say Text'),
((@BP_ENTRY*100)+2, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @SI_ENTRY, 10, 0, 0, 0, 0, 0, 'Stormwind Infantry - Yell For Help'),
((@BP_ENTRY*100)+2, 9, 1, 0, 0, 0, 100, 1, 600, 600, 0, 0, 11, 8362, 0, 0, 0, 0, 0, 19, @SI_ENTRY, 10, 0, 0, 0, 0, 0, 'Brother Paxton - Cast Renew'),
((@BP_ENTRY*100)+2, 9, 2, 0, 0, 0, 100, 1, 600, 600, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Say Text'),
((@BP_ENTRY*100)+3, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 11, 93091, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Cast AOE Heal'),
((@BP_ENTRY*100)+3, 9, 1, 0, 0, 0, 100, 1, 600, 600, 0, 0, 1, 1, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Brother Paxton - Say Text');
DELETE FROM `creature_text` WHERE `entry` IN (@BP_ENTRY,@SI_ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@BP_ENTRY, 0, 0, 'BY THE LIGHT BE RENEWED!', 12, 0, 100, 0, 0, 0, 'Brother Paxton - Renew Cast Phrase'),
(@BP_ENTRY, 1, 0, 'AND I LAY MY HANDS UPON YOU!', 12, 0, 100, 0, 0, 0, 'Brother Paxton - Renew Cast Phrase'),
(@BP_ENTRY, 1, 1, 'Let the Holy Light embrace you!', 12, 0, 100, 0, 0, 0, 'Brother Paxton - Healing Cast Phrase'),
(@BP_ENTRY, 2, 0, 'Be healed, brother!', 12, 0, 100, 0, 0, 0, 'Brother Paxton - Healing Cast Phrase'),
(@BP_ENTRY, 2, 1, 'FIGHT ON, BROTHER!', 12, 0, 100, 0, 0, 0, 'Brother Paxton - Healing Cast Phrase'),
(@SI_ENTRY, 0, 0, 'HELP!', 12, 0, 100, 0, 0, 0, 'Stormwind Infantry - Call For Heal'),
(@SI_ENTRY, 0, 1, 'I need a heal!', 12, 0, 100, 0, 0, 0, 'Stormwind Infantry - Call For Heal'),
(@SI_ENTRY, 0, 2, 'I could use a heal, brother!', 12, 0, 100, 0, 0, 0, 'Stormwind Infantry - Call For Heal'),
(@SI_ENTRY, 0, 3, 'Make yourself useful and heal me, Paxton!', 12, 0, 100, 0, 0, 0, 'Stormwind Infantry - Call For Heal');

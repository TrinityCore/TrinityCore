-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=34230;
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=31242;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry`=30159;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30159,31242) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3124200) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30159, 0, 0, 0, 27, 0, 100, 512, 0, 0, 0, 0, 0, 53, 1, 30159, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn's Proto-Drake - On Passenger Boarded - Start Waypoint"),
(30159, 0, 1, 2, 40, 0, 100, 513, 9, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn's Proto-Drake - On Waypoint 9 Reached - Despawn Instant (No Repeat)"),
(30159, 0, 2, 0, 61, 0, 100, 513, 9, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31242, 20, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn's Proto-Drake - On Waypoint 9 Reached - Set Data 1 1 (No Repeat)"),
(31242, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 0, 11, 61165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Out of Combat - Cast 'Frostbite Weapon'"),
(31242, 0, 1, 0, 9, 0, 100, 0, 0, 2, 10000, 15000, 0, 11, 57635, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Within 0-2 Range - Cast 'Disengage'"),
(31242, 0, 2, 0, 9, 0, 100, 0, 0, 3, 8000, 20000, 0, 11, 61170, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Within 0-3 Range - Cast 'Flash Freeze'"),
(31242, 0, 3, 0, 9, 0, 100, 0, 5, 30, 5000, 10000, 0, 11, 61168, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Within 5-30 Range - Cast 'Throw'"),
(31242, 0, 4, 0, 60, 0, 100, 1, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On update - Say text"),
(31242, 0, 5, 0, 5, 0, 100, 512, 0, 0, 0, 0, 0, 45, 20, 20, 0, 0, 0, 0, 10, 123494, 31135, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Killed Unit - Set Data 20 20"),
(31242, 0, 6, 0, 6, 0, 100, 512, 0, 0, 1, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 123494, 31135, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Just Died - Set Data 3 3"),
(31242, 0, 7, 8, 1, 0, 100, 513, 60000, 60000, 0, 0, 0, 45, 19, 19, 0, 0, 0, 0, 10, 123494, 31135, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Out of Combat - Set Data 19 19"),
(31242, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Out of Combat - Despawn"),
(31242, 0, 9, 10, 54, 0, 100, 0, 0, 0, 0, 0, 0, 12, 30159, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Just Summoned - Summon Creature 'Sigrid Iceborn's Proto-Drake' (No Repeat)"),
(31242, 0, 10, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 19, 30159, 100, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Just Summoned - Cast 'Ride Vehicle Hardcoded' (No Repeat)"),
(31242, 0, 11, 12, 38, 0, 100, 513, 1, 1, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Data Set 1 1 - Set Home Position (No Repeat)"),
(31242, 0, 12, 13, 61, 0, 100, 513, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 90, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Data Set 1 1 - Start Attacking (No Repeat)"),
(31242, 0, 13, 0, 61, 0, 100, 513, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Data Set 1 1 - Say Line 1 (No Repeat)"),
(31242, 0, 14, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - Ooc - Remove immune tp PC/Npc"),
(31242, 0, 15, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On Just Summoned - Set immune tp PC/Npc"),
(31242, 0, 16, 0, 31, 0, 100, 0, 61170, 0, 2000, 2000, 0, 11, 57635, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Sigrid Iceborn - On spell hit target - Cast 'Disengage'");

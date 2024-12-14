 -- Timed list 4947900 smart ai
SET @ENTRY := 4947900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Last action invoker: Close gossip'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove npc flags QUESTGIVER'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove stand state KNEEL'),
(@ENTRY, 9, 3, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 87071, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell  Alchemy (87071) on Self'),
(@ENTRY, 9, 4, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 92388, 0, 0, 0, 0, 0, 19, 8584, 15, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast spell  Curing Ivveron (92388) on Closest alive creature Iverron (8584) in 15 yards'),
(@ENTRY, 9, 5, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk Iverron\'s poison is cured, but it will take some time for hi... (0) to invoker'),
(@ENTRY, 9, 6, 0, '', 0, 0, 100, 0, 7000, 7000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 7, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Add npc flags QUESTGIVER');

-- Set Moonwell Bunny as trigger 
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=34575;

-- Fix Iverron Location from sniff
UPDATE `creature` SET `position_x`=10547.4599609375, `position_y`=874.11456298828125, `position_z`=1309.520751953125, `orientation`=0.667657673358917236 WHERE `guid`=313191;
UPDATE `creature` SET `position_x`=10547.3720703125, `position_y`=874.19097900390625, `position_z`=1309.529052734375, `orientation`=2.501891136169433593 WHERE `guid`=331007;
UPDATE `creature_template_addon` SET `StandState`=0 WHERE `entry`=8584;

-- Fix Dentaria Silverglade Location from sniff
UPDATE `creature` SET `position_x`=10545.201171875, `position_y`=875.4375, `position_z`=1309.362548828125, `orientation`=5.992145538330078125 WHERE `guid`=313193;
UPDATE `creature` SET `position_x`=10545.201171875, `position_y`=875.4375, `position_z`=1309.36279296875, `orientation`=5.97093057632446289 WHERE `guid`=331003;

DELETE FROM `creature_template_addon` WHERE `entry` IN (28961, 30980, 28965, 30982);
INSERT INTO `creature_template_addon` (`entry`,`bytes2`, `auras`) VALUES
(28961, 0, '52898'),
(30980, 0, '52898'),
(28965, 0, '52881'),
(30982, 0, '52881');

 -- Titanium Siegebreaker smart ai
SET @ENTRY := 28961;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 514, 0, 40, 10000, 15000, 11, 52891, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-40%% (check every 10000 - 15000 ms) - Self: Cast spell Blade Turning (52891) with flags interrupt previous, triggered, Flag unknown 4 on Self'),
(@ENTRY, 0, 1, 0, 2, 0, 100, 516, 0, 50, 10000, 15000, 11, 59173, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-50%% (check every 10000 - 15000 ms) - Self: Cast spell Blade Turning (59173) with flags interrupt previous, triggered, Flag unknown 4 on Self'),
(@ENTRY, 0, 2, 3, 7, 0, 100, 512, 0, 0, 0, 0, 22, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On evade - Set event phase to phase 5'),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On evade - Self: Set sheath to Melee'),
(@ENTRY, 0, 4, 0, 4, 0, 100, 512, 0, 0, 0, 0, 28, 16245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Remove aura due to spell Freeze Anim (16245)'),
(@ENTRY, 0, 5, 6, 38, 0, 35, 512, 1, 1, 0, 0, 19, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Remove UNIT_FLAGS to IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 80, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Attack Closest player in 80 yards'),
(@ENTRY, 0, 7, 0, 2, 0, 100, 513, 0, 20, 0, 0, 11, 19134, 2, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-20%% (check once) - Self: Cast spell Frightening Shout (19134) with flags triggered on Threat list'),
(@ENTRY, 0, 8, 0, 9, 0, 100, 512, 0, 5, 10000, 15000, 11, 52890, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'When victim in range 0 - 5 yards (check every 10000 - 15000 ms) - Self: Cast spell Penetrating Strike (52890) with flags triggered on Victim'),
(@ENTRY, 0, 9, 10, 63, 0, 100, 0, 0, 0, 0, 0, 85, 16245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Cast spell Freeze Anim (16245) on self'),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set UNIT_FLAGS to IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE');

 -- Titanium Thunderer smart ai
SET @ENTRY := 28965;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 514, 0, 40, 12000, 18000, 11, 52879, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-40%% (check every 12000 - 18000 ms) - Self: Cast spell Deflection (52879) with flags interrupt previous, triggered, Flag unknown 4 on Self'),
(@ENTRY, 0, 1, 0, 2, 0, 100, 516, 0, 65, 12000, 18000, 11, 59181, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-65%% (check every 12000 - 18000 ms) - Self: Cast spell Deflection (59181) with flags interrupt previous, triggered, Flag unknown 4 on Self'),
(@ENTRY, 0, 2, 3, 7, 0, 100, 512, 0, 0, 0, 0, 22, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On evade - Set event phase to phase 5'),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On evade - Self: Set sheath to Melee'),
(@ENTRY, 0, 4, 0, 4, 0, 100, 512, 0, 0, 0, 0, 28, 16245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On aggro - Self: Remove aura due to spell Freeze Anim (16245)'),
(@ENTRY, 0, 5, 6, 38, 0, 35, 512, 1, 1, 0, 0, 19, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Remove UNIT_FLAGS to IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE'),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 80, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Attack Closest player in 80 yards'),
(@ENTRY, 0, 7, 0, 13, 0, 100, 515, 45000, 60000, 0, 0, 11, 52885, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'When victim is casting anyspell (check once) - Self: Cast spell Deadly Throw (52885) with flags triggered on Victim'),
(@ENTRY, 0, 8, 0, 13, 0, 100, 517, 45000, 60000, 0, 0, 11, 59180, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'When victim is casting anyspell (check once) - Self: Cast spell Deadly Throw (59180) with flags triggered on Victim'),
(@ENTRY, 0, 9, 0, 0, 0, 100, 514, 0, 5000, 7000, 15000, 11, 52904, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Every 7 - 15 seconds (0 - 5s initially) (IC) - Self: Cast spell Throw (52904) with flags triggered on Random hostile'),
(@ENTRY, 0, 10, 0, 0, 0, 100, 516, 0, 5000, 7000, 15000, 11, 59179, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Every 7 - 15 seconds (0 - 5s initially) (IC) - Self: Cast spell Throw (59179) with flags triggered on Random hostile'),
(@ENTRY, 0, 11, 12, 63, 0, 100, 0, 0, 0, 0, 0, 85, 16245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Cast spell Freeze Anim (16245) on self'),
(@ENTRY, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set UNIT_FLAGS to IMMUNE_TO_PC, IMMUNE_TO_NPC, NOT_SELECTABLE');

-- Creature Enslaved Gronn Brute 40166 SAI
SET @ENTRY := 40166;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 20000, 30000, 30000, 11, 76138, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 20000 ms (and later repeats every 30000 and 30000 ms) - Self: Cast spell 76138 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 4000, 5000, 11000, 12000, 11, 76703, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 5000 ms (and later repeats every 11000 and 12000 ms) - Self: Cast spell 76703 on Victim // ");

-- Twilight Beguiler
UPDATE `creature_template` SET `ScriptName`= 'npc_grim_batol_twilight_beguiler' WHERE `entry`= 40167;

DELETE FROM `conditions` WHERE `SourceEntry` IN (76138, 74867, 74884, 76151, 90719) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 3, 76138, 0, 0, 31, 0, 3, 40167, 0, 0, 0, '', 'Gronn Knockback Cosmetic - Target Twilight Beguiler'),
(13, 1, 74867, 0, 0, 31, 0, 3, 40166, 0, 0, 0, '', 'Enslave Gronn Cosmetic - Target Enslaved Gronn Brute'),
(13, 1, 74884, 0, 0, 31, 0, 3, 40166, 0, 0, 0, '', 'Enslave Gronn Cosmetic - Target Enslaved Gronn Brute'),
(13, 3, 76151, 0, 0, 31, 0, 3, 40166, 0, 0, 0, '', 'Beguile - Target Enslaved Gronn Brute'),
(13, 3, 90719, 0, 0, 31, 0, 3, 40166, 0, 0, 0, '', 'Beguile - Target Enslaved Gronn Brute');

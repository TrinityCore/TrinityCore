-- Saragosa
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (26231);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(26231, 1, 1, 1, 0);

 -- Saragosa smart ai
SET @ENTRY := 26231;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 1, 100, 1, 6000, 6000, 0, 0, 28, 46789, 0, 0, 0, 0, 0, 19, 26265, 40, 0, 0, 0, 0, 0, 'Time = 6 seconds (OOC) - Closest alive creature Saragosa\'s End Invisman (26265) in 40 yards: Remove aura due to spell  Blue Power Focus (46789)'),
(@ENTRY, 0, 1, 2, 1, 1, 100, 1, 12000, 12000, 0, 0, 12, 26232, 1, 120000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 12 seconds (OOC) - Self: Summon creature Saragosa (26232) at Self\'s position, moved by offset (0, 0, 0, 0) as summon type timed or dead despawn with duration 120 seconds'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 12 seconds (OOC) - Self: Despawn instantly'),
(@ENTRY, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Set event phase to phase 1');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 26231 AND `SourceId` = 0;

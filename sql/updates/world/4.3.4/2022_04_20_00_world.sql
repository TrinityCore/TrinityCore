DELETE FROM `creature_template_addon` WHERE `entry` IN (52654, 52806);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(52654, 1, '70878'),
(52806, 1, '70878');

DELETE FROM `creature_addon` WHERE `guid` IN (313596, 313597, 313595, 313594, 313586, 313579, 313581, 313582, 313584, 313585, 313588);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(313596, 0, 1, 333, ''),
(313597, 0, 1, 333, ''),
(313595, 0, 1, 333, ''),
(313594, 0, 1, 333, ''),
(313588, 1, 1, 0, '70878'),
(313585, 1, 1, 0, '70878'),
(313579, 1, 1, 0, '70878');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160115;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectAura`, `EffectBasePoints`, `EffectMiscValue`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160115, 6, 26, 0, 0, 1, 0, 70878, 0, '(Serverside/Non-DB2) Root Self');

UPDATE `spell_dbc` SET `DurationIndex`= 21 WHERE `Id`= 70878;

 -- Bwemba
SET @ENTRY := 52654;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 1000, 4000, 4000, 4000, 10, 1, 274, 273, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 4 seconds - Self: Play random emote: ONESHOT_TALK(DNR) (1), ONESHOT_NO(DNR) (274), ONESHOT_YES(DNR) (273),");

 -- Commander Sharp
SET @ENTRY := 53352;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 1000, 4000, 4000, 4000, 10, 1, 274, 5, 6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 4 - 4 seconds (1 - 4s initially) - Self: Play random emote: ONESHOT_TALK(DNR) (1), ONESHOT_NO(DNR) (274), ONESHOT_EXCLAMATION(DNR) (5), ONESHOT_QUESTION (6),");

-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=52265;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=28683;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 52265, 0, 0, 31, 1, 3, 28605, 0, 0, 0, 0, "", "Spell 'Repo' can only target Havenshire Stallion OR"),
(17, 0, 52265, 0, 1, 31, 1, 3, 28606, 0, 0, 0, 0, "", "Spell 'Repo' can only target Havenshire Mare OR"),
(17, 0, 52265, 0, 2, 31, 1, 3, 28607, 0, 0, 0, 0, "", "Spell 'Repo' can only target Havenshire Colt"),
(22, 1, 28683, 0, 0, 1, 0, 52263, 0, 0, 0, 0, 0, "", "Run SAI script if invoker has aura 'Stolen Horse'");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=28683;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28683;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `COMMENT`) VALUES
(28683, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 11, 52265, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Stable Master Kitrik - On Aggro - Cast 'Repo'"),
(28683, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stable Master Kitrik- On Aggro - Say Line 0"),
(28683, 0, 2, 0, 5, 0, 100, 0, 5000, 5000, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Stable Master Kitrik - On Player Kill - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=28683;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28683, 0, 0, "Dirty, stinkin', horse thief!", 12, 0, 100, 0, 0, 0, 28675, 0, "Stable Master Kitrik"),
(28683, 0, 1, "Nobody steals Kitrik's horses!", 12, 0, 100, 0, 0, 0, 28676, 0, "Stable Master Kitrik"),
(28683, 0, 2, "You'll be hanging at the gallows soon...", 12, 0, 100, 0, 0, 0, 28677, 0, "Stable Master Kitrik"),
(28683, 0, 3, "How many more of you do I need to send back to the Lich King in pieces before he'll stop?", 12, 0, 100, 0, 0, 0, 28678, 0, "Stable Master Kitrik"),
(28683, 1, 0, "And keep the change, ya filthy animal!", 12, 0, 100, 0, 0, 0, 28702, 0, "Stable Master Kitrik"),
(28683, 1, 1, "Perhaps you'll think twice about stealin' one of Kitrik's horses next time, eh?", 12, 0, 100, 0, 0, 0, 28703, 0, "Stable Master Kitrik"),
(28683, 1, 2, "Is that all you got?", 12, 0, 100, 0, 0, 0, 28704, 0, "Stable Master Kitrik"),
(28683, 1, 3, "What a colossal waste of time.", 12, 0, 100, 0, 0, 0, 28705, 0, "Stable Master Kitrik"),
(28683, 1, 4, "At least make me work for it next time.", 12, 0, 100, 0, 0, 0, 28706, 0, "Stable Master Kitrik");

-- UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0 WHERE `DisplayID`=2498;

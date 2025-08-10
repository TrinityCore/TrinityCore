-- 
SET @ENTRY := 17000;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `Comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - Just summoned - Action List'),
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - Action List - Set immune to pc'),
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 145, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - Action List - Set immune to npc'),
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 24240, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - cast- Spawn Red Lightning'),
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - Action List - Say line 0'),
(@ENTRY*100, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - Action List - Remove immune to pc'),
(@ENTRY*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 145, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - Action List - Remove immune to npc'),
(@ENTRY*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Aggonis - Action List - Attack'),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 3000, 4000, 10000, 14000, 11, 21068, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - IC - Cast Corruption'),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 10000, 15000, 11, 22678, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Aggonis - IC - Cast Fear');
DELETE FROM `creature_text` WHERE `CreatureID` = @ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `Comment`, `BroadcastTextId`) VALUES
(@ENTRY, 0, 0, "Fools!  You seek to abjure my father's presence?  Death awaits you, mortals!", 12, 0, 100, 0, 0, 0, 'Aggonis', 13157);

UPDATE `event_scripts` SET `x`=421.45572, `y`=3466.6333, `z`=63.432034 WHERE `id` = 10362;

DELETE FROM `conditions` WHERE `SourceEntry`= 29297 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 29297 , 0, 0, 29, 0, 17000, 100, 0, 1, 0, 0, '', 'Item - Cleansing Vial DND - Must not be near Aggonis to cast');

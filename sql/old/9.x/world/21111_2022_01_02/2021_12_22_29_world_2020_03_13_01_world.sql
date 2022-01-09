-- A Necessary Distraction
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry` = 21506;
DELETE FROM `creature_addon` WHERE `guid` = 75420;
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry` = 21506;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21503;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21503, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 28, 37833, 0, 0, 0, 0, 0, 19, 21506, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - On reset - Remove aura'),
(21503, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 38722, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - On reset - Cast Channel'),
(21503, 0, 2, 0, 0, 0, 100, 0, 5000, 8000, 10000, 16000, 11, 32707, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - IC - Cast Incinerate'),
(21503, 0, 3, 0, 0, 0, 100, 0, 0, 3000, 3000, 3000, 11, 9613, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - IC - Cast Shadow Bolt'),
(21503, 0, 4, 5, 38, 0, 100, 0, 1, 1, 1000, 1000, 28, 37833, 0, 0, 0, 0, 0, 19, 21506, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - On Data set - Remove aura'),
(21503, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 38722, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Warlock - On Data set - Cast Channel');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 21506 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21506, 0, 0, 0, 23, 0, 100, 0, 38722, 1, 5000, 5000, 11, 37833, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On aura x1 - Cast ban'),
(21506, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On reset - Set unit Flag'),
(21506, 0, 2, 3, 8, 0, 100, 0, 37834, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spell hit - Remove flag'),
(21506, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 33, 21892, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spell hit - Give Credit'),
(21506, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 28, 37833, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spell hit - Remove Aura'),
(21506, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 21503, 40, 0, 0, 0, 0, 0, 'Azaloth - On Spell hit - Attack'),
(21506, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 11, 38750, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spellhit - Cast Warstomp'),
(21506, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Spellhit - Say Text'),
(21506, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 38722, 1, 0, 0, 0, 11, 21503, 40, 0, 0, 0, 0, 0, 'Azaloth - On Spellhit - Inturrupt cast'),
(21506, 0, 9, 0, 9, 0, 100, 0, 0, 5, 8000, 15000, 11, 40504, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - On Range - Cast Cleave'),
(21506, 0, 10, 0, 0, 0, 100, 0, 8000, 8000,8000 , 12000, 11, 11443, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - IC - Cast Cripple'),
(21506, 0, 11, 0, 0, 0, 100, 0, 5000, 10000, 12000 , 15000, 11, 38741, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Azaloth - IC - Cast Rain of Fire'),
(21506, 0, 12, 0, 25, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 21503, 40, 0, 0, 0, 0, 0, 'Azaloth - On reset - Set data');

DELETE FROM `creature_text` WHERE `CreatureID`=21506;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21506,0,0,"Illidan's lapdogs!  You will pay for my imprisonment with your lives!",14,0,100,0,0,0,19577,0,'Azaloth');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (37834);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 37834, 0, 0, 31, 1, 3, 21506, 0, 0, 0, 0, '', 'Requires Azaloth');

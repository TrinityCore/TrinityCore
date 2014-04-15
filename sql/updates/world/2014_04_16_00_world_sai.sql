-- Runes of Compulsion (Quest: 12093)
SET @RUNEWEAVER := 26820; -- Iron Rune-Weaver
SET @RUNE := 26785; -- Directional Rune
SET @DR1 := 188471; -- Directional Rune 1
SET @DR2 := 188505; -- Directional Rune 2
SET @DR3 := 188506; -- Directional Rune 3
SET @DR4 := 188507; -- Directional Rune 4
SET @OD := 26920; -- Overseer Durval
SET @OK := 26921; -- Overseer Korgan
SET @OL := 26922; -- Overseer Lochli
SET @OB := 26923; -- Overseer Brunon

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@RUNEWEAVER, @RUNE, @OD, @OK, @OL, @OB);
UPDATE `creature_template` SET `faction_A`=1954, `faction_H`=1954 WHERE `entry` IN (@OD, @OK, @OL, @OB);
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry` IN (@DR1, @DR2, @DR3, @DR4);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@RUNEWEAVER, @RUNE, @OD, @OK, @OL, @OB);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@RUNE*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@RUNEWEAVER, 0, 0, 1, 1, 0, 100, 1, 1000, 1000, 1000, 1000, 11, 47463, 2, 0, 0, 0, 0, 11, @RUNE, 30, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On spawn & reset - Channel Rune-Weaver Channel on Directional Rune'),
(@RUNEWEAVER, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 15, @DR1, 30, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On spawn & reset - Reset Directional Rune 1'),
(@RUNEWEAVER, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 15, @DR2, 30, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On spawn & reset - Reset Directional Rune 2'),
(@RUNEWEAVER, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 15, @DR3, 30, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On spawn & reset - Reset Directional Rune 3'),
(@RUNEWEAVER, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 15, @DR4, 30, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On spawn & reset - Reset Directional Rune 4'),
(@RUNEWEAVER, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 45, 2, 1, 0, 0, 0, 0, 11, @RUNE, 30, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On Reset - Set Data 2 1 on Directional Rune'),
(@RUNEWEAVER, 0, 6, 0, 0, 0, 100, 0, 4000, 7000, 10000, 16000, 11, 52713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - Combat - Cast Rune Weaving on victim'),
(@RUNEWEAVER, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, @RUNE, 50, 0, 0, 0, 0, 0, 'Iron Rune-Weaver - On Death - Set Data 1 1 on Directional Rune'),
(@RUNE, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Directional Rune - On Data 1 1 - Increase Phase'),
(@RUNE, 0, 1, 0, 38, 0, 100, 0, 2, 1, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Directional Rune - On Data 2 1 - Reset to Phase 0'),
(@RUNE, 0, 2, 0, 60, 8, 100, 0, 0, 0, 0, 0, 12, @OD, 1, 120000, 0, 0, 0, 8, 0, 0, 0, 4485.58, -4655.58, 77.65009, 3.228859, 'Directional Rune - On Update OOC in Phase 4 - Summon Overseer Durval'),
(@RUNE, 0, 3, 0, 60, 8, 100, 0, 0, 0, 0, 0, 12, @OK, 1, 120000, 0, 0, 0, 8, 0, 0, 0, 4317.391, -4882.59, 33.49857, 4.520403, 'Directional Rune - On Update OOC in Phase 4 - Summon Overseer Korgan'),
(@RUNE, 0, 4, 0, 60, 8, 100, 0, 0, 0, 0, 0, 12, @OL, 1, 120000, 0, 0, 0, 8, 0, 0, 0, 4215.784, -5049.129, 5.86421, 2.75762, 'Directional Rune - On Update OOC in Phase 4 - Summon Overseer Lochli'),
(@RUNE, 0, 5, 0, 60, 8, 100, 0, 0, 0, 0, 0, 12, @OB, 1, 120000, 0, 0, 0, 8, 0, 0, 0, 3986.997, -5246.744, 7.280532, 0.8901179, 'Directional Rune - On Update OOC in Phase 4 - Summon Overseer Brunon'),
(@RUNE, 0, 6, 0, 60, 8, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Directional Rune - On Update OOC in Phase 4 - Reset to Phase 0'),
(@OD, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Durval - On Just Summoned - Say'),
(@OD, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47693, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Durval - On Link - Cast Spawn - Blue Lightning'),
(@OD, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 15, @DR1, 10, 0, 0, 0, 0, 0, 'Overseer Durval - On Link - Activate Directional Rune 1'),
(@OD, 0, 3, 0, 0, 0, 100, 0, 5000, 9000, 8000, 11000, 11, 52715, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Durval - In Combat - Cast Rune of Destruction'),
(@OK, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Korgan - On Just Summoned - Say'),
(@OK, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47693, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Korgan - On Link - Cast Spawn - Blue Lightning'),
(@OK, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 15, @DR2, 10, 0, 0, 0, 0, 0, 'Overseer Korgan - On Link - Activate Directional Rune 2'),
(@OK, 0, 3, 0, 0, 0, 100, 0, 3000, 5000, 7000, 9000, 11, 32018, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overseer Korgan - In Combat - Cast Call Lightning'),
(@OK, 0, 4, 0, 2, 0, 100, 0, 0, 30, 12000, 16000, 11, 52714, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Korgan - Between 0-30% Health - Cast Revitalizing Rune'),
(@OL, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Lochli - On Just Summoned - Say'),
(@OL, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47693, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Lochli - On Link - Cast Spawn - Blue Lightning'),
(@OL, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 15, @DR3, 10, 0, 0, 0, 0, 0, 'Overseer Lochli - On Link - Activate Directional Rune 3'),
(@OL, 0, 3, 0, 0, 0, 100, 0, 8000, 12000, 11000, 15000, 11, 52717, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Lochli - In Combat - Cast Thunderstorm'),
(@OB, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Brunon - On Just Summoned - Say'),
(@OB, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47693, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overseer Brunon - On Link - Cast Spawn - Blue Lightning'),
(@OB, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 15, @DR4, 10, 0, 0, 0, 0, 0, 'Overseer Brunon - On Link - Activate Directional Rune 4');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@RUNE; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, @RUNE, 0, 0, 30, 1, @DR1, 5, 0, 0, 0, 0, '', 'Execute SAI id 2 only if within 5 yards of Directional Rune 1'),
(22, 4, @RUNE, 0, 0, 30, 1, @DR2, 5, 0, 0, 0, 0, '', 'Execute SAI id 3 only if within 5 yards of Directional Rune 2'),
(22, 5, @RUNE, 0, 0, 30, 1, @DR3, 5, 0, 0, 0, 0, '', 'Execute SAI id 4 only if within 5 yards of Directional Rune 3'),
(22, 6, @RUNE, 0, 0, 30, 1, @DR4, 5, 0, 0, 0, 0, '', 'Execute SAI id 5 only if within 5 yards of Directional Rune 4');

DELETE FROM `creature_text` WHERE `entry` IN (@OD, @OK, @OL, @OB);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@OD, 0, 0, 'You''ll pay for this!', 12, 0, 100, 25, 0, 0, 'Overseer Durval', 26090),
(@OD, 0, 1, 'Fool! You''ll never get away with this!', 12, 0, 100, 25, 0, 0, 'Overseer Durval', 26091),
(@OD, 0, 2, 'You dare to defy the sons of iron?', 12, 0, 100, 25, 0, 0, 'Overseer Durval', 26092),
(@OD, 0, 3, 'What do you think you''re doing?', 12, 0, 100, 25, 0, 0, 'Overseer Durval', 26089),
(@OK, 0, 0, 'You''ll pay for this!', 12, 0, 100, 25, 0, 0, 'Overseer Korgan', 26090),
(@OK, 0, 1, 'Fool! You''ll never get away with this!', 12, 0, 100, 25, 0, 0, 'Overseer Korgan', 26091),
(@OK, 0, 2, 'You dare to defy the sons of iron?', 12, 0, 100, 25, 0, 0, 'Overseer Korgan', 26092),
(@OK, 0, 3, 'What do you think you''re doing?', 12, 0, 100, 25, 0, 0, 'Overseer Korgan', 26089),
(@OL, 0, 0, 'You''ll pay for this!', 12, 0, 100, 25, 0, 0, 'Overseer Lochli', 26090),
(@OL, 0, 1, 'Fool! You''ll never get away with this!', 12, 0, 100, 25, 0, 0, 'Overseer Lochli', 26091),
(@OL, 0, 2, 'You dare to defy the sons of iron?', 12, 0, 100, 25, 0, 0, 'Overseer Lochli', 26092),
(@OL, 0, 3, 'What do you think you''re doing?', 12, 0, 100, 25, 0, 0, 'Overseer Lochli', 26089),
(@OB, 0, 0, 'You''ll pay for this!', 12, 0, 100, 25, 0, 0, 'Overseer Brunon', 26090),
(@OB, 0, 1, 'Fool! You''ll never get away with this!', 12, 0, 100, 25, 0, 0, 'Overseer Brunon', 26091),
(@OB, 0, 2, 'You dare to defy the sons of iron?', 12, 0, 100, 25, 0, 0, 'Overseer Brunon', 26092),
(@OB, 0, 3, 'What do you think you''re doing?', 12, 0, 100, 25, 0, 0, 'Overseer Brunon', 26089);

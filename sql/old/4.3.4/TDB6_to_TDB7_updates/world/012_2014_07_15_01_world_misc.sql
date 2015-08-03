--
SET @STINKER := 23274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@STINKER;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@STINKER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@STINKER, 0, 1, 8,75, 0, 100, 0, 0, 7383, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 7383, 0, 0, 0, 0, 0, 0, 'Stinker - On Black Tabby Cat within 20yrds - Store Targetlist'),
(@STINKER, 0, 2, 8,75, 0, 100, 0, 0, 7385, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 7385, 0, 0, 0, 0, 0, 0, 'Stinker - On Bombay Cat within 20yrds - Store Targetlist'),
(@STINKER, 0, 3, 8,75, 0, 100, 0, 0, 22816, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 22816, 0, 0, 0, 0, 0, 0, 'Stinker - On Black Cat within 20yrds - Store Targetlist'),
(@STINKER, 0, 4, 8,75, 0, 100, 0, 0, 7384, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 7384, 0, 0, 0, 0, 0, 0, 'Stinker - On Cornish Rex Cat within 20yrds - Store Targetlist'),
(@STINKER, 0, 5, 8,75, 0, 100, 0, 0, 7382, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 7382, 0, 0, 0, 0, 0, 0, 'Stinker - On Orange Tabby within 20yrds - Store Targetlist'),
(@STINKER, 0, 6, 8,75, 0, 100, 0, 0, 7380, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 7380, 0, 0, 0, 0, 0, 0, 'Stinker - On Siamese Cat within 20yrds - Store Targetlist'),
(@STINKER, 0, 7, 8,75, 0, 100, 0, 0, 7381, 20, 90000, 64, 1, 0, 0, 0, 0, 0, 19, 7381, 0, 0, 0, 0, 0, 0, 'Stinker - On Silver Tabby Cat within 20yrds - Store Targetlist'),
(@STINKER, 0, 8, 9,61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event - Cast Stinker In Love - Set Phase 1'),
(@STINKER, 0, 9, 10,61, 0, 100, 0, 0, 0, 0, 0, 11, 62002, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event - Cast Stinker In Love'),
(@STINKER, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 62001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event - Cast Stinker Passive'),
(@STINKER, 0, 11, 12,1, 1, 100, 0, 0, 0, 2000, 5000, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - OOC (Phase 1) - Set Run'),
(@STINKER, 0, 12, 13,61, 1, 100, 0, 0, 0, 0, 0, 11, 62002, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event (Phase 1) - Cast Stinker In Love'),
(@STINKER, 0, 13, 0,61, 1, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event (Phase 1) - Follow Stored Target'),
(@STINKER, 0, 14, 0,1, 1, 100, 0, 30000, 45000, 30000, 45000, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - OOC (Phase 1) - Set Phase 2'),
(@STINKER, 0, 15, 16,23, 1, 100, 0, 62002, 0, 0, 0, 11, 62004, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - On Has No Aura (Stinker in love) (Phase 1) - Cast Stinker Heartbroken'),
(@STINKER, 0, 16, 17,61, 1, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event (Phase 1) - Set Phase 0'),
(@STINKER, 0, 17, 21,61, 0, 100, 0, 0, 0, 0, 0, 28, 62001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event  - Remove aura stinker passive'),
(@STINKER, 0, 18, 19,23, 2, 100, 0, 62002, 0, 0, 0, 11, 62004, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - On Has No Aura (Stinker in love) (Phase 2) - Cast Stinker Heartbroken'),
(@STINKER, 0, 19, 20,61, 2, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event (Phase 2) - Set Phase 0'),
(@STINKER, 0, 20, 21,61, 0, 100, 0, 0, 0, 0, 0, 28, 62001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event  - Remove aura stinker passive'),
(@STINKER, 0, 21, 22,61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event  - Follow'),
(@STINKER, 0, 22, 0,61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Stinker - Linked with Previous Event  - Follow');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(62000,62002,62004);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 62000, 0, 0, 31, 0, 3, 7383, 0, 0, 0, 0, '', 'Stinker Periodic Hits Black Tabby Cat'),
(13, 1, 62000, 0, 1, 31, 0, 3, 7385, 0, 0, 0, 0, '', 'Stinker Periodic Hits Bombay Cat'),
(13, 1, 62000, 0, 2, 31, 0, 3, 22816, 0, 0, 0, 0, '', 'Stinker Periodic Hits Black Cat'),
(13, 1, 62000, 0, 3, 31, 0, 3, 7384, 0, 0, 0, 0, '', 'Stinker Periodic Hits Cornish Rex Cat'),
(13, 1, 62000, 0, 4, 31, 0, 3, 7382, 0, 0, 0, 0, '', 'Stinker Periodic Hits Orange Tabby Cat'),
(13, 1, 62000, 0, 5, 31, 0, 3, 7380, 0, 0, 0, 0, '', 'Stinker Periodic Hits Siamese Cat'),
(13, 1, 62000, 0, 6, 31, 0, 3, 7381, 0, 0, 0, 0, '', 'Stinker Periodic Hits Silver Tabby'),
(13, 1, 62002, 0, 0, 31, 0, 3, 7383, 0, 0, 0, 0, '', 'Stinker In Love Hits Black Tabby Cat'),
(13, 1, 62002, 0, 1, 31, 0, 3, 7385, 0, 0, 0, 0, '', 'Stinker In Love Hits Bombay Cat'),
(13, 1, 62002, 0, 2, 31, 0, 3, 22816, 0, 0, 0, 0, '', 'Stinker In Love Hits Black Cat'),
(13, 1, 62002, 0, 3, 31, 0, 3, 7384, 0, 0, 0, 0, '', 'Stinker In Love Hits Cornish Rex Cat'),
(13, 1, 62002, 0, 4, 31, 0, 3, 7382, 0, 0, 0, 0, '', 'Stinker In Love Hits Orange Tabby Cat'),
(13, 1, 62002, 0, 5, 31, 0, 3, 7380, 0, 0, 0, 0, '', 'Stinker In Love Hits Siamese Cat'),
(13, 1, 62002, 0, 6, 31, 0, 3, 7381, 0, 0, 0, 0, '', 'Stinker In Love Hits Silver Tabby Cat'),
(13, 1, 62002, 0, 7, 31, 0, 3, @STINKER, 0, 0, 0, 0, '', 'Stinker In Love Hits Stinker'),
(13, 1, 62004, 0, 8, 31, 0, 3, @STINKER, 0, 0, 0, 0, '', 'Stinker Heartbroken Hits Stinker');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN(7383,7385,22816,7384,10338,7382,7380,10337,7381);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (7383,7385,22816,7384,10338,7382,7380,10337,7381) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7383, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Tabby Cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(7383, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Tabby Cat - On Has No Aura (Stinker in love) - Evade'),
(7385, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombay Cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(7385, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombay Cat - On Has No Aura (Stinker in love) - Evade'),
(22816, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(22816, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Black Cat - On Has No Aura (Stinker in love) - Evade'),
(7384, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cornish Rex Cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(7384, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cornish Rex Cat - On Has No Aura (Stinker in love) - Evade'),
(7382, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orange Tabby Cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(7382, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orange Tabby Cat - On Has No Aura (Stinker in love) - Evade'),
(7380, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Siamese Cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(7380, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Siamese Cat - On Has No Aura (Stinker in love) - Evade'),
(7381, 0, 0, 0,23, 0, 100, 0, 62002, 1, 10000, 0, 11, 62000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silver Tabby cat - On Has Aura (Stinker in love) - Cast Stinker Periodic'),
(7381, 0, 1, 0,23, 0, 100, 0, 62002, 0, 10000, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Silver Tabby Cat - On Has No Aura (Stinker in love) - Evade');

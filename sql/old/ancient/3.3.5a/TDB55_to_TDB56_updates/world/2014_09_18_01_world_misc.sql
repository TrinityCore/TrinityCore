SET @CGuid := 74518;

DELETE FROM `creature` WHERE `id`IN(24014,29393)AND `guid` BETWEEN @CGUID AND @CGUID+3;
UPDATE `creature_template` SET `faction`=21, `unit_flags`=33536, `unit_flags2`=2099200 WHERE  `entry`=29394;

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 24014, 571, 1, 1,  2846.022, -3855.99, 248.6132, 5.315152, 120, 0, 0), -- 24014 (Area: 495)
(@CGUID+1, 24014, 571, 1, 1,  2846.136, -3866.035, 248.6132, 0.4537856, 120, 0, 0), -- 24014 (Area: 495)
(@CGUID+2, 24014, 571, 1, 1,  2855.766, -3859.292, 248.6132, 3.944444, 120, 0, 0), -- 24014 (Area: 495)
(@CGUID+3, 29393, 571, 1, 1,  2851.356, -3863.74, 248.6132, 5.305801, 120, 0, 0); -- 29393 (Area: 495)

DELETE FROM `creature_text` WHERE `entry` IN(29394,24023);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(29394, 0, 0, 'Not yet, Ymiron, I have other plans for you. You will serve me better within Utgarde Pinnacle. And if these insects survive to find you again, you will get the chance to avenge your wife.', 14, 0, 100, 1, 0, 14748, 'The Lich King',23803),
(24023, 0, 0, 'Give me your souls that I might slay the enemy!', 14, 0, 100, 0, 0, 13774, 'Queen Angerboda',22622),
(24023, 1, 0, 'You will not stop my work here!  My husband-king will awaken!', 14, 0, 100, 0, 0, 13775, 'Queen Angerboda',22636),
(24023, 2, 0, 'The ritual proceeds too slowly. More sacrifices are needed!', 14, 0, 100, 0, 0, 0, 'Queen Angerboda',23802),
(24023, 2, 1, 'Soon, my love. Soon you will waken and all of Azeroth will know fear!', 14, 0, 100, 0, 0, 0, 'Queen Angerboda',23795),
(24023, 2, 2, 'Awaken, Ymiron, the time of your continued reign is nigh.', 14, 0, 100, 0, 0, 0, 'Queen Angerboda',23796),
(24023, 2, 3, 'Double your efforts! King Ymiron will awaken and then he will ascend!', 14, 0, 100, 0, 0, 0, 'Queen Angerboda',23799),
(24023, 2, 4, 'Sleep no longer, my love. With the might of the Lich King behind you, the world will tremble.', 14, 0, 100, 0, 0, 0, 'Queen Angerboda',23797),
(24023, 2, 5, 'Why is this ritual taking so long? Your master promised that your assistance would speed the process!', 14, 0, 100, 0, 0, 0, 'Queen Angerboda',23798);

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`IN(24023,29394,29394,29393);
UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=29393;
UPDATE `creature_template` SET `unit_flags`=32768 WHERE  `entry`=24023;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(42808,42809);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 42808, 0, 0, 31, 0, 3, 24014, 0, 0, 0, 0, '', 'Queen Angerbodas On Reaction 2 Beam - Targets Necrolord'),
(13, 1, 42809, 0, 0, 31, 0, 3, 24023, 0, 0, 0, 0, '', 'Queen Angerboda Soul Absorption - Targets Queen Angerboda');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-@CGUID,-@CGUID-1,-@CGUID-2,24023,2402300,2401400,29394,2939400,29393);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24023, 0, 0, 0, 1, 2, 100, 0, 0, 0, 1000, 1000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - OOC (Phase 2) - Cast Queen Angerboda: Soul Beam'),
(24023, 0, 1, 0, 1, 1, 100, 0, 0, 0, 1000, 1000, 11, 42808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - OOC (Phase 2) - Cast Queen Angerboda: Soul Beam'),
(24023, 0, 2, 0, 10, 0, 100, 0, 0, 50, 60000, 90000, 80, 2402300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - OOC LOS (Phase 2) - Run Script'),
(24023, 0, 3, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - OOC LOS (Phase 2) - Run Script'),
(24023, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - On Agro - Say Line 2'),
(24023, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 12, 29394, 1, 60000, 0, 0, 0, 8, 0, 0, 0, 2850.257, -3872.007, 248.6132, 1.413717, 'Queen Angerboda - On Death - Summon the Lich king'),
(24023, 0, 6, 7, 25, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - On Reset - Set Phase 2'),
(24023, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @CGUID, 24014, 0, 0, 0, 0, 0, 'Queen Angerboda - On Reset - Respawn Necrolord 1'),
(24023, 0, 8, 8, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @CGUID+1, 24014, 0, 0, 0, 0, 0, 'Queen Angerboda - On Reset - Respawn Necrolord 2'),
(24023, 0, 9, 8, 61, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, @CGUID+2, 24014, 0, 0, 0, 0, 0, 'Queen Angerboda - On Reset - Respawn Necrolord 3'),
(24023, 0, 10, 0, 1, 0, 100, 0, 0, 45000, 45000, 90000, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - OOC - Say'),

(29394, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2939400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Just Summoned - Run Script'),
(29394, 0, 1, 0, 1, 2, 100, 0, 0, 0, 1000, 1000, 11, 42811, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'The Lich King - OOC (Phase 2) - Cast Teleport Other'),
(29393, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 11, 34427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'King Ymiron - On Data Set - Cast Ethereal Teleport'),
(29393, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'King Ymiron - On Data Set - Cast Ethereal Teleport'),
(2939400, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 34427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Cast Ethereal Teleport'),
(2939400, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Say'),
(2939400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Set Orientation'),
(2939400, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Cast Teleport Other'),
(2939400, 9, 5, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Despawn King Ymiron'),
(2939400, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Cast Teleport Other'),
(2939400, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 92, 0, 42811, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Interupt'),
(2939400, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 34427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Cast Ethereal Teleport'),
(2939400, 9, 9, 0, 0, 0, 100, 0, 500, 500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - Script 1 - Despawn'),
(2402300, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 92, 0, 44473, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - Script 1 - Interupt'),
(2402300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - Script 1 - Remove Aura Queen Angerboda: Soul Beam'),
(2402300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - Script 1 - Say Line 1'),
(2402300, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 24014, 0, 100, 0, 0, 0, 0, 'Queen Angerboda - Script 1 - Set Data'),
(2402300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - Script 1 - Set Data'),
(2401400, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Queen Angerboda - Script 1 - Set Data'),
(-@CGUID, 0, 0, 0, 1, 2, 100, 0, 0, 0, 3000, 3000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'Necrolord - OOC (Phase 2) - Cast Queen Angerboda: Soul Beam'),
(-@CGUID, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 92, 0, 44473, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42809, 0, 0, 0, 0, 0, 19, 24023, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2401400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID, 0, 6, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID-1, 0, 0, 0, 1, 2, 100, 0, 0, 0, 3000, 3000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'Necrolord - OOC (Phase 2) - Cast Queen Angerboda: Soul Beam'),
(-@CGUID-1, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 92, 0, 44473, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID-1, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID-1, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42809, 0, 0, 0, 0, 0, 19, 24023, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID-1, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2401400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID-1, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID-1, 0, 6, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID-2, 0, 0, 0, 1, 2, 100, 0, 0, 0, 3000, 3000, 11, 44473, 0, 0, 0, 0, 0, 19, 29393, 0, 0, 0, 0, 0, 0, 'Necrolord - OOC (Phase 2) - Cast Queen Angerboda: Soul Beam'),
(-@CGUID-2, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 92, 0, 44473, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID-2, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID-2, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 42809, 0, 0, 0, 0, 0, 19, 24023, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Cast Queen Angerboda Soul Absorption'),
(-@CGUID-2, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2401400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID-2, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die'),
(-@CGUID-2, 0, 6, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Necrolord - On Data Set - Die');

DELETE FROM `creature_template_addon` WHERE `entry`=29394;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(29394, 0, 0x0, 0x0, '41408'); -- 29394 - 41408

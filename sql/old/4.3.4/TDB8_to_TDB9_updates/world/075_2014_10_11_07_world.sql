UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE  `guid` IN(121055,121049);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(58108,58118);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 58108, 0, 0, 31, 0, 3, 30995, 0, 0, 0, 0, '', 'Patches Chain targets Patches Chain Target'),
(13, 1, 58118, 0, 0, 31, 0, 3, 30992, 0, 0, 0, 0, '', 'Patches Revenge targets Doctor Sabnok');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE  `entry`=193025;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(30992,30993,30995);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30992,30993,30995) and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3099200,3099300) and `source_type`=9;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=193025;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(193025, 1, 0 ,1, 70, 0, 100, 0, 2, 0, 0,0,45,1,1,0,0,0,0,19,30993,0,0,0, 0, 0, 0, 'Metal Stake - On State Changed - Set Data 1 1 on "Patches"'),
(193025, 1, 1 ,0, 61, 0, 100, 0, 0, 0, 0,0,104,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Metal Stake - On State Changed - Set Flag In Use"'),
(193025, 1, 2 ,0, 38, 0, 100, 0, 2, 2, 0,0,104,4,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Metal Stake - On Data Set - Remove Flag In Use"'),
(30992, 0, 0, 0, 6,  0, 100, 0, 0, 0, 0, 0, 45, 3 , 3, 0, 0, 0, 0, 19, 30993, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - On Death - Set Data 3 3 on "Patches"'),
(30992, 0, 1, 0,54,  0, 100, 0, 0, 0, 0, 0, 53, 0 , 30992, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - On Just Summoned - Start WP'),
(30992, 0, 2, 0,40,  0, 100, 0, 10, 30992, 0, 0, 45, 2 , 2, 0, 0, 0, 0, 19, 30993, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Reached WP10 - Set Data 2 2 on "Patches"'),
(30992, 0, 3, 4,40,  0, 100, 0, 14, 30992, 0, 0, 101, 0 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Reached WP14 - Set Home Position'),
(30992, 0, 4, 5,61,  0, 100, 0, 0, 0, 0, 0, 8, 2 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Reached WP14 - Set Hostile'),
(30992, 0, 5, 7,61,  0, 100, 0, 0, 0, 0, 0, 80, 3099200 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Reached WP14 - Run Script'),
(30992, 0, 6, 0,11,  0, 100, 0, 0, 0, 0, 0, 18, 256 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - On Spawn - Set Unit Flags'),
(30992, 0, 7, 0,61,  0, 100, 0, 0, 0, 0, 0, 45, 5 , 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - On Reached WP14 - Set Data 5 5 on "Patches"'),
(30993, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 2 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - On Respawn - Set Phase 2'),
(30993, 0, 1, 0, 1, 2, 100, 0, 0, 0, 3000, 3000, 11, 58108 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - OOC (Phase 2) - Cast Patches Chain'),
(30993, 0, 2, 3, 38,  0, 100, 0, 1, 1, 300000, 300000, 22, 0 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - On Data Set 1 1 - Set Phase 1'),
(30993, 0, 3, 4, 61,  0, 100, 0, 0, 0, 0, 0, 28, 58108 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - On Data Set 1 1 - Remove Aura Patches Chain'),
(30993, 0, 4, 5,61,  0, 100, 0, 0, 0, 0, 0, 45, 1 , 1, 0, 0, 0, 0, 19, 30995, 0, 0, 0, 0, 0, 0, '"Patches" - On Data Set 1 1 - Set Data 1 1 on Patches chain target'),
(30993, 0, 5, 6, 61,  0, 100, 0, 0, 0, 0, 0, 12, 30992 , 2, 300000, 0, 0, 0, 8, 0, 0, 0, 6630.52, 3167.312, 659.3602, 2.740049, '"Patches" - On Data Set 1 1 - Summon Doctor Sabnok'),
(30993, 0, 6, 7, 61,  0, 100, 0, 0, 0, 0, 0, 1, 1 , 0, 0, 0, 0, 0, 1, 0, 0, 0,  0, 0, 0, 0, '"Patches" - On Data Set 1 1 - Say Line 1'),
(30993, 0, 7, 0, 61,  0, 100, 0, 0, 0, 0, 0, 2, 2036 , 0, 0, 0, 0, 0, 1, 0, 0, 0,  0, 0, 0, 0, '"Patches" - On Data Set 1 1 - Set Faction'),
(30993, 0, 8, 9, 38,  0, 100, 0, 3, 3, 0, 0, 11, 59115 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches" - On Data Set 3 3 - Cast Patches Credit'),
(30993, 0, 9, 0, 61,  0, 100, 0, 0, 0, 0, 0, 41, 5000 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches" - On Data Set 3 3 - Despawn'),
(30993, 0, 10, 15, 38,  0, 100, 0, 5, 5, 0, 0, 89, 0 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches" - On On Data Set 5 5 - Turn Random Move Off'),
(30993, 0, 11, 0, 38,  0, 100, 0, 4, 4, 0, 0, 80, 3099300 , 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches" - On Data Set 4 4 - Run Script'),
(30993, 0, 12, 13, 11,  0, 100, 0, 0, 0, 0, 0, 45, 1 , 1, 0, 0, 0, 0, 14, 62005, 193025, 0, 0, 0, 0, 0, 'Patches" - On Respawn - Set Data 1 1 on Metal Stake'),
(30993, 0, 13, 14, 61,  0, 100, 0, 0, 0, 0, 0, 89, 5 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches" - On Respawn - Set Random Movement'),
(30993, 0, 14, 0, 61,  0, 100, 0, 0, 0, 0, 0, 18, 768 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches" - On Respawn - Set Unit Flags'),
(30993, 0, 15, 0, 61,  0, 100, 0, 0, 0, 0, 0, 66, 0 , 0, 0, 0, 0, 0, 19, 30992, 0, 0, 0, 0, 0, 0, 'Patches" - On On Data Set 5 5 - Face Doctor Sabnok'),
(30995, 0, 0, 0, 38,  0, 100, 0, 1, 1, 0, 0, 28, 58108 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Patches Chain Target - On Data Set 1 1 - Remove Aura Patches Chain'),
(3099200, 9, 0, 0, 0,  0, 100, 0, 0, 0, 0, 0, 66, 0 , 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Script - Face Player'),
(3099200, 9, 1, 0, 0,  0, 100, 0, 0, 0, 0, 0, 5, 21 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Script - Play Emote OneShotApplaud'),
(3099200, 9, 2, 0, 0,  0, 100, 0, 1000, 1000, 0, 0, 1, 1 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Script - Say Line 1'),
(3099200, 9, 3, 0, 0,  0, 100, 0, 6000, 6000, 0, 0, 1, 2 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Script - Say Line 2'),
(3099200, 9, 4, 0, 0,  0, 100, 0, 6000, 6000, 0, 0, 1, 3 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Script - Say Line 3'),
(3099200, 9, 5, 0, 0,  0, 100, 0, 4000, 4000, 0, 0, 5, 11 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Script - Play Emote OneShotLaugh'),
(3099200, 9, 6, 0, 0,  0, 100, 0, 0, 0, 0, 0, 45, 4 , 4, 0, 0, 0, 0, 19, 30993, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Set Data 4 4 on "Patches"'),
(3099200, 9, 7, 0, 0,  0, 100, 0, 0, 0, 0, 0, 19, 256 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Doctor Sabnok - Set Unit Flags"'),
(3099300, 9, 0, 0, 0,  0, 100, 0, 3000, 3000, 0, 0, 8, 2 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - Script - Set Hostile'),
(3099300, 9, 1, 0, 0,  0, 100, 0, 0, 0, 0, 0, 19, 768 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - Script - Set Unit Flags'),
(3099300, 9, 2, 0, 0,  0, 100, 0, 0, 0, 0, 0, 49, 0 , 0, 0, 0, 0, 0, 19, 30992, 0, 0, 0, 0, 0, 0, '"Patches" - Script - Start Attack'),
(3099300, 9, 3, 0, 0,  0, 100, 0, 0, 0, 0, 0, 1, 2 , 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '"Patches" - Script - Say Line 2'),
(3099300, 9, 4, 0, 0,  0, 100, 0, 4000, 4000, 0, 0, 11, 58118 , 0, 0, 0, 0, 0, 19, 30992, 0, 0, 0, 0, 0, 0, '"Patches" - Script - Cast Patches Revenge');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=30993;

DELETE FROM `creature_text` WHERE `entry` IN(30992,30993);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(30992, 1, 0, 'Oh, bravo. Do you feel proud of yourself now that you''ve unleashed this terrible mistake?', 12, 0, 100, 21, 0, 0, 'Doctor Sabnok',31550),
(30992, 2, 0, 'I already had him scheduled for disposal, but I suppose we can speed up the process a bit.', 12, 0, 100, 1, 0, 0, 'Doctor Sabnok',31551),
(30992, 3, 0, 'It''s a pity so many fine, and reusable, parts will go to waste... ', 12, 0, 100, 11, 0, 0, 'Doctor Sabnok',31553),
(30993, 1, 0, 'Patches get revenge on Doctor Sabnok!', 12, 0, 100, 51, 0, 0, '\"Patches\"',31556),
(30993, 2, 0, 'Patches not going to be cut open or sewn up no more!', 12, 0, 100, 1, 0, 0, '\"Patches\"',31554);

DELETE FROM `creature` WHERE `id` =30992;

UPDATE `creature_template` SET `faction`=974, `speed_run`=1.142857, `unit_flags`=0 WHERE  `entry`=30992;
UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry` =30993;

DELETE FROM `waypoints` WHERE `entry` IN(30992,30993);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(30992, 1, 6631.495, 3167.087, 659.3602, 'Doctor Sabnok'),
(30992, 2, 6630.52, 3167.312, 659.3602, 'Doctor Sabnok'),
(30992, 3, 6626.219, 3169.138, 658.8849, 'Doctor Sabnok'),
(30992, 4, 6625.229, 3169.558, 658.8132, 'Doctor Sabnok'),
(30992, 5, 6619.998, 3171.78, 656.6917, 'Doctor Sabnok'),
(30992, 6, 6618.303, 3172.5, 655.796, 'Doctor Sabnok'),
(30992, 7, 6618.303, 3172.5, 655.796, 'Doctor Sabnok'),
(30992, 8, 6618.216, 3172.712, 655.967, 'Doctor Sabnok'),
(30992, 9, 6614.216, 3176.462, 654.217, 'Doctor Sabnok'),
(30992, 10, 6613.862, 3176.668, 653.9982, 'Doctor Sabnok'),
(30992, 11, 6612.862, 3177.668, 653.7482, 'Doctor Sabnok'),
(30992, 12, 6606.399, 3184.294, 649.7903, 'Doctor Sabnok'),
(30992, 13, 6606.399, 3185.794, 649.2903, 'Doctor Sabnok'),
(30992, 14, 6606.149, 3189.544, 648.5403, 'Doctor Sabnok');

DELETE FROM `creature_template_addon` WHERE `entry` IN (30993);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(30993, 0, 0x0, 0x1, '54262'); -- 30993 - 54262

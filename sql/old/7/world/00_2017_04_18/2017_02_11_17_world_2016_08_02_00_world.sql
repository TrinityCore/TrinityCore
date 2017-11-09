UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`IN(25769,24730,25456,25457,25458);
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE  `entry`=25769;
UPDATE `creature_template` SET `unit_flags`=33587968 WHERE  `entry`IN(25456,25457);
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE  `entry`IN(25458);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25769,24730,25456,25457,25458) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(2574201,2473000,2545600,2545800) AND `source_type`=9;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25769,24730) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` =25742 AND `source_type`=0 AND `id`=2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24730, 0, 0, 0, 20, 0, 100, 0, 11695, 0, 0, 0, 80, 2473000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Tamer Barah - On Quest Reward (The Horn of Elemental Fury) - Run Script'),
(25769, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 45979, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Small Elemental - On Just Summoned - Cast Elemental Beam'),
(25769, 0, 1, 2, 1, 0, 100, 1, 8000, 8000, 0, 0, 28, 45979, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Small Elemental - OOC (8 Sec) - Remove Aura'),
(25769, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Small Elemental - OOC (8 Sec) - Set Bytes 1'),
(25742, 0, 2, 0, 54, 0, 100, 1, 0, 0, 0, 0, 80, 2574201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alluvius - On Just Summoned - Run Script 2'),
(2574201, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alluvius - Script 2 - Play emote OneShotAttackUnarmed'),
(2574201, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 24730, 0, 0, 0, 0, 0, 0, 'Alluvius - Script 2 - Say Line 0'),
(2473000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Tamer Barah - Script - Set NPC Flags'),
(2473000, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 43320, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Tamer Barah - Script - Cast Windwarden Channeling'),
(2473000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25771, 1, 12000, 0, 0, 0, 8, 0, 0, 0, 3526.857, 4215.892, 16.89778, 0.9599311, 'Wind Tamer Barah - Script - Summon Ice Elemental Target'),
(2473000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25769, 1, 10000, 0, 0, 0, 8, 0, 0, 0, 3526.76, 4208.782, 12.51583, 0.9599311, 'Wind Tamer Barah - Script - Summon Small Elemental'),
(2473000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25769, 1, 10000, 0, 0, 0, 8, 0, 0, 0, 3530.082, 4210.271, 12.5575, 1.029744, 'Wind Tamer Barah - Script - Summon Small Elemental'),
(2473000, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25769, 1, 10000, 0, 0, 0, 8, 0, 0, 0, 3533.227, 4213.772, 12.55055, 2.80998, 'Wind Tamer Barah - Script - Summon Small Elemental'),
(2473000, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25769, 1, 10000, 0, 0, 0, 8, 0, 0, 0, 3531.661, 4218.423, 12.57833, 0.9250245, 'Wind Tamer Barah - Script - Summon Small Elemental'),
(2473000, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25769, 1, 10000, 0, 0, 0, 8, 0, 0, 0, 3528.847, 4221.306, 12.52278, 2.75762, 'Wind Tamer Barah - Script - Summon Small Elemental'),
(2473000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 25769, 1, 10000, 0, 0, 0, 8, 0, 0, 0, 3524.509, 4220.787, 12.59916, 3.630285, 'Wind Tamer Barah - Script - Summon Small Elemental'),
(2473000, 9, 9, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 12, 25742, 1, 7000, 0, 0, 0, 8, 0, 0, 0, 3526.815, 4215.751, 13.3075, 3.752458, 'Wind Tamer Barah - Script - Summon Alluvius'),
(2473000, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 92,0, 43320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Tamer Barah - Script - Remove Aura'),
(2473000, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Tamer Barah - Script - Set NPC Flags'),
(25458, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 25458, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Farseer Grimwalkers Spirit - On Just Summoned - Start WP'),
(25458, 0, 1, 0, 40, 0, 100, 0, 2, 25458, 0, 0, 80, 2545800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Farseer Grimwalkers Spirit - On Reached WP2 - Run Script'),
(25457, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 45581, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Magmoth Shaman - On Data Set - Cast Spirit Shackle'),
(25456, 0, 0, 2, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 25456, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Kaganishu - On Just Summoned - Start WP'),
(25456, 0, 1, 0, 40, 0, 100, 0, 2, 25456, 0, 0, 80, 2545600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Kaganishu - On Reached WP2 - Run Script'),
(25456, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 50, 187679, 14, 0, 0, 0, 0, 8, 0, 0, 0, 4528.167, 5678.6, 82.23339, 0.6283169, 'Vision of Kaganishu - On Just Summoned - Spawn Blue aura, short column, scale 6'),
(2545600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 45595, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Kaganishu - Script - Cast Fireball'),
(2545600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Kaganishu - Script - Say'),
(2545800, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 25457, 0, 40, 0, 0, 0, 0, 'Vision of Farseer Grimwalkers Spirit - Script - Set Data on Vision of Magmoth Shaman'), -- 21:09:47.563
(2545800, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 17, 383, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Farseer Grimwalkers Spirit - Script - Set Emote State'), -- 21:09:47.563
(2545800, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25339, 0, 0, 0, 0, 0, 0, 'Vision of Farseer Grimwalkers Spirit - Script - Say Line 0'), -- 21:09:44.297
(2545800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 45605, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vision of Farseer Grimwalkers Spirit - Script - Cast Vision of Air: Kill Credit'); -- 21:09:57.953

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(45979,45581);

DELETE FROM `smart_scripts` WHERE `entryorguid`=30886 AND `source_type`=0 AND `id`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30886, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 30232, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Subjugated Iskalder - Out of Combat - Start Follow Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=25742;

DELETE FROM `creature_text` WHERE `entry`IN(24730,25339,25456);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(24730, 0, 0, 'With the power of the horn, I bind you to its wielder''s will!', 12, 0, 100, 0, 0, 0, 24963, 'Wind Tamer Barah to Player'),
(25339, 0, 0, 'Oh no... they''ve shackled his spirit!', 12, 1, 100, 5, 0, 0, 24683, 'Spirit Talker Snarlfang'),
(25456, 0, 0, 'KAGANISHU!', 12, 0, 100, 0, 0, 0, 24658, 'Vision of Kaganishu');

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 45979, 0, 0, 31, 0, 3, 25771, 0, 0, 0, 0, '', 'Elemental Beam only targets Ice Elemental Target'),
(13, 1, 45581, 0, 0, 31, 0, 3, 25458, 0, 0, 0, 0, '', 'Spirit Shackle only targets Vision of Farseer Grimwalkers Spirit'),
(22, 1, 25742, 0, 0, 23, 1, 4037, 0, 0, 1, 0, 0, '', 'Alluvius - Only Run SAI if not summoned in Taunka le village'),
(22, 4, 25742, 0, 0, 23, 1, 4037, 0, 0, 0, 0, 0, '', 'Alluvius - Only Run SAI if summoned in Taunka le village');


DELETE FROM `waypoints` WHERE `entry`IN(25456,25458);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25456, 1, 4525.928, 5677.233, 81.70667, 'Vision of Kaganishu'),
(25456, 2, 4527.502, 5678.359, 81.88042, 'Vision of Kaganishu'),
(25458, 1, 4528.928, 5679.599, 81.99405, 'Vision of Farseer Grimwalkers Spirit'),
(25458, 2, 4528.823, 5679.591, 83.10519, 'Vision of Farseer Grimwalkers Spirit');

DELETE FROM `event_scripts` WHERE `id`=16716;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(16716, 5, 10, 25424, 16000, 0, 4529.002, 5679.642, 82.36562, 3.769911),
(16716, 6, 10, 25457, 15000, 0, 4528.024, 5680.72, 82.29639, 5.497787),
(16716, 6, 10, 25457, 15000, 0, 4530.323, 5680.649, 82.45662, 3.769911),
(16716, 6, 10, 25457, 15000, 0, 4529.922, 5678.596, 82.38788, 2.286381),
(16716, 7, 10, 25456, 14000, 0, 4525.962, 5677.239, 82.14642, 0.6290413),
(16716, 12, 10,25458, 9000, 0, 4528.883, 5679.529, 82.23911, 0.6290413);

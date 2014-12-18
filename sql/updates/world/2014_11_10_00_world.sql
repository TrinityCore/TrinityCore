SET @OGUID=5544;
SET @CGUID=75010;

DELETE FROM `gameobject` WHERE  `guid`=21202;

DELETE FROM `gameobject` WHERE `guid` = @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 188463, 571, 1, 1,  4045.556, 2193.373, 152.0166, 4.729844, 0, 0, 0, 1, 120, 255, 1); -- 188463 (Area: 65)

UPDATE `creature_template` SET `unit_flags`=32768 WHERE  `entry`=26608;

DELETE FROM `creature_addon` WHERE  `guid`=85321;

DELETE FROM `creature_template_addon` WHERE `entry`IN(26772,26608,26656,26654);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(26772, 0, 0x10000, 0x1, ''), -- 26772 - 29266
(26608, 0, 0x10000, 0x1, '47020'), -- 26608 - 47020
(26656, 0, 0x10000, 0x1, ''), -- 26656
(26654, 0, 0x10000, 0x1, ''); -- 26654 - 47273

UPDATE `creature` SET `spawntimesecs`=120 WHERE  `guid`=85321;

DELETE FROM `creature` WHERE `id` IN(26772,26608,26656);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phasemask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 26772, 571, 1, 1,  4026.681, 2196.83, 151.8157, 0.5235988, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+1, 26772, 571, 1, 1,  4057.075, 2189.563, 151.9275, 2.216568, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+2, 26772, 571, 1, 1,  4066.369, 2203.186, 151.8947, 2.827433, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+3, 26772, 571, 1, 1,  4028.012, 2220.003, 151.6349, 5.689773, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+4, 26772, 571, 1, 1,  4087.59, 2197.294, 150.3048, 5.899213, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+5, 26772, 571, 1, 1,  4062.908, 2222.086, 152.0691, 3.438299, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+6, 26772, 571, 1, 1,  4069.837, 2216.063, 151.6581, 3.420845, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+7, 26772, 571, 1, 1,  4059.205, 2234.109, 151.6747, 4.031711, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+8, 26772, 571, 1, 1,  4085.448, 2212.562, 150.3048, 2.600541, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+9, 26772, 571, 1, 1,  4102.396, 2215.324, 150.5771, 2.9147, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+10, 26772, 571, 1, 1,  4094.654, 2231.302, 150.3048, 4.39823, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+11, 26772, 571, 1, 1,  4085.341, 2238.712, 150.3048, 6.265732, 120, 0, 0), -- 26772 (Area: 65)
(@CGUID+12, 26608, 571, 1, 1,  4112.918, 2231.335, 221.9723, 3.281219, 120, 0, 0), -- 26608 (Area: 65)
(@CGUID+13, 26656, 571, 1, 1,  4041.442, 2205.44, 151.8544, 1.58825, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+14, 26656, 571, 1, 1,  4046.042, 2203.535, 151.8609, 1.780236, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+15, 26656, 571, 1, 1,  4039.123, 2210.314, 151.9584, 5.654867, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+16, 26656, 571, 1, 1,  4050.549, 2205.821, 151.8495, 1.745329, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+17, 26656, 571, 1, 1,  4045.468, 2217.318, 151.895, 3.961897, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+18, 26656, 571, 1, 1,  4052.386, 2210.654, 151.7681, 2.303835, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+19, 26656, 571, 1, 1,  4040.73, 2215.186, 151.9743, 1.692969, 120, 0, 0), -- 26656 (Area: 65)
(@CGUID+20, 26656, 571, 1, 1,  4050.493, 2215.687, 151.6617, 0, 120, 0, 0); -- 26656 (Area: 65)

DELETE FROM `creature_text` WHERE `entry`IN(26654,26608);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(26654, 0, 0, 'Release me, fiends!', 12, 0, 100, 15, 0, 0, 'Roanauk Icemist',25828),
(26654, 0, 1, 'Pray to whatever gods you believe in that I am never freed!', 12, 0, 100, 15, 0, 0, 'Roanauk Icemist',25829),
(26654, 1, 0, 'I... am... FREE!', 14, 0, 100, 22, 0, 0, 'Roanauk Icemist',25954),
(26654, 2, 0, 'What have they done to my people...', 12, 0, 100, 6, 0, 0, 'Roanauk Icemist',25955),
(26654, 3, 0, 'You will face the full fury of the ancestors for what you have done, monster!', 14, 0, 100, 22, 0, 0, 'Roanauk Icemist',25956),
(26654, 4, 0, 'Rebirth comes, my brothers... Rise... Rise and fight once more.', 12, 0, 100, 0, 0, 0, 'Roanauk Icemist',25957),
(26654, 5, 0, 'FOR ICEMIST! FOR THE TAUNKA!', 14, 0, 100, 0, 0, 0, 'Roanauk Icemist',25958),
(26654, 6, 0, 'Come down and face me, insect!', 14, 0, 100, 15, 0, 0, 'Roanauk Icemist',25962),
(26654, 7, 0, 'Then I will force you down! Wind grant me flight!', 14, 0, 100, 15, 0, 0, 'Roanauk Icemist',25963),
(26608, 0, 0, 'Give in, Taunka! Your will cannot hold out against the Scourge!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25952),
(26608, 0, 1, 'Leave no survivors!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25951),
(26608, 0, 2, 'Tear this pitiful village apart!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25950),
(26608, 1, 0, 'Your freedom will be short lived, Icemist!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25959),
(26608, 2, 0, 'Insolent mortal! You will be consumed!', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25964),
(26608, 3, 0, 'ARRGGH!! It cannot be! How...', 14, 0, 100, 15, 0, 0, 'Under-King Anub''et''kan',25965),
(26608, 4, 0, 'Anub''et''kan is defeated! Take a fragment of his husk as proof of your victory!', 41, 0, 100, 0, 0, 0, 'Under-King Anub''et''kan',25999);

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =188463;

DELETE FROM `smart_scripts` WHERE `entryorguid` =188463 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(188463,1,0,1,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,26654,0,0,0,0,0,0,'Anub ar Mechanism - On State Changed - Set Data on Roanauk Icemist'),
(188463,1,1,0,61,0,100,0,2,0,0,0,70,600,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anub ar Mechanism - On State Changed - Despawn GO');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(26654,26772,26608,26656);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26654,26772,26608,26656) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2665400,2665401,2665402,2660800) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26654, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2665400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Data Set 1 1 - Run Script'),

(26654, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 26656, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Set Data 1 1 on Anub''ar Prison'),
(26654, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Set Phase 1'),
(26654, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Cast Icemist''s Prison'),
(26654, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Spawn - Set Passive'),
(26654, 0, 5, 0, 1, 1, 100, 0, 5000, 30000, 120000, 150000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - OOC (Phase 1) - Say Line 0'),
(26654, 0, 6, 0, 34, 0, 100, 0, 0, 1, 0, 0, 80, 2665401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Reached WP1 - Run Script'),
(26654, 0, 7, 0, 1, 0, 100, 0, 0, 0, 15000, 35000, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - OOC - Play emote OneShotRoar'),
(26654, 0, 8, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 2665402, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Data Set - Despawn'),
(26654, 0, 9, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 47379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Agro - Cast Icemist''s Blessing'),
(26654, 0, 10, 0, 11, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - On Respawn - Reset Scripts'),

(26656, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, 47272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anub''ar Prison - On Data Set 1 1 - Cast Anub''ar Prison'),
(26656, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 28, 47272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anub''ar Prison - On Data Set 2 2 - Remove Anub''ar Prison'),
(26772, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Spawn - Set Unit Flags'),
(26772, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Spawn - Cast Permament Feign Death'),
(26772, 0, 2, 3, 8, 0, 100, 0, 47378, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Spell Hit (Glory of the Ancestors) - Set Unit Flags'),
(26772, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Cast Permament Feign Death'),
(26772, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Unit Flags 2'),
(26772, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Dynamic Flags'),
(26772, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 91, 257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Agressive'),
(26772, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On On Spell Hit (Glory of the Ancestors) - Set Agressive'),
(26772, 0, 8, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Icemist Warrior - On Data Set - Despawn'),
(26608, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 97, 15, 10,  0, 0, 0, 0,  1, 0, 0, 0,4088.679932, 2219.449951, 150.304993, 0, 'Under-King Anub''et''kan - On Data Set - Jump to Position'),
(26608, 0, 2, 0, 1, 0, 100, 0, 0, 0, 25000, 45000, 1, 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - OOC - Say Line 0'),
(26608, 0, 2, 3, 6, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Say Line 3'),
(26608, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Say Line 4'),
(26608, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 11, 47400, 2, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Cast Summon Husk'),
(26608, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1,  0, 0, 0, 0, 9, 26772, 0, 200, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Set Data on Icemist'),
(26608, 0, 6, 10, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0,  0, 19, 26654, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death  - Set Data on Roanauk Icemist'),
(26608, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Data Set - Set Agressive'),
(26608, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 19, 768, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Data Set - Set Unit Flags'),
(26608, 0, 9, 0, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Spawn - Set Unit Flags'),
(26608, 0, 1, 7, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2660800, 2, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Data Set - Run Script'),
(26608, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - On Death - Despawn'),
(2660800, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 101, 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Under-King Anub''et''kan - Script - Set Home Position'),
(2665400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Say Line 1'),
(2665400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 47273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Remove Aura Icemist''s Prison'),
(2665400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 26656, 0, 200, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Data 2 2 on Anub''ar Prison'),
(2665400, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Set Phase 2'),
(2665400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 26654, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script - Start WP'),
(2665401, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 2'),
(2665401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 2'),
(2665401, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 3'),
(2665401, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 1 on Under-King Anub''et''kan'),
(2665401, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 47378, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Cast Glory of the Ancestors'),
(2665401, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 4'),
(2665401, 9, 6, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 11, 47379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Cast Icemist''s Blessing'),
(2665401, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 5'),
(2665401, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 6'),
(2665401, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 2 on Under-King Anub''et''kan'),
(2665401, 9, 10, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 7'),
(2665401, 9, 11, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Say Line 7'),
(2665401, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Set Unit Flags'),
(2665401, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Set Home Position'),
(2665401, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Set Agressive'),
(2665401, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 26608, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 2 - Attack'),


(2665402, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 3 - Set Invisible'),
(2665402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Roanauk Icemist - Script 3 - Die');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(47378,47379);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 47378, 0, 0, 31, 0, 3, 26772, 0, 0, 0, 0, '', 'Glory of the Ancestors targets Icemist Warrior'),

(13, 1, 47379, 0, 0, 31, 0, 3, 26772, 0, 0, 0, 0, '', 'Icemists Blessing targets Icemist Warrior'),
(13, 1, 47379, 0, 1, 31, 0, 3, 26654, 0, 0, 0, 0, '', 'Icemists Blessing targets Roanauk Icemist'),
(13, 1, 47379, 0, 2, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Icemists Blessing targets Player');

DELETE FROM `waypoints` WHERE `entry`=26654;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(26654, 1, 4067.684, 2214.182, 151.9559, 'Roanauk Icemist');

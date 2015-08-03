SET @CGuid := 129851;

UPDATE `creature_template` SET `AIName`= 'SmartAI',`faction`=21, `unit_flags`=32832 WHERE  `entry`=31283;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`flags_extra`=128 WHERE  `entry`=32406;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31290;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=31316;

DELETE FROM `creature` WHERE  `id` IN(31283,31316,37967,38505);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31283, 571, 1, 1, 5826.424, 2029.934, 503.993, 5.951573, 120, 0, 0), -- 31283 (Area: 210)
(@CGUID+1, 31316, 571, 1, 1, 5894.918, 2027.746, 513.1389, 3.212954, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+2, 31316, 571, 1, 1, 5873.27, 2020.346, 506.469, 2.86509, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+4, 37967, 571, 1, 1, 5699.498, 2143.675, 798.1427, 1.710423, 120, 0, 0), -- 37967 (Area: 210)
(@CGUID+5, 37967, 571, 1, 1, 5683.006, 2145.111, 798.1452, 1.186824, 120, 0, 0), -- 37967 (Area: 210)
(@CGUID+6, 37967, 571, 1, 1, 5679.912, 2107.91, 798.1375, 6.230825, 120, 0, 0), -- 37967 (Area: 210)
(@CGUID+7, 37967, 571, 1, 1, 5691.881, 2090.5, 798.1375, 2.181662, 120, 0, 0), -- 37967 (Area: 210)
(@CGUID+8, 31316, 571, 1, 1, 5851.897, 2064.396, 504.0805, 4.502924, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+9, 31316, 571, 1, 1, 5869.164, 2064.59, 504.6295, 3.909517, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+10, 38505, 571, 1, 1, 5897.904, 2104.522, 636.1191, 3.206179, 120, 0, 0), -- 38505 (Area: 210)
(@CGUID+11, 31316, 571, 1, 1, 5890.246, 2049.392, 512.1957, 3.944444, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+12, 31316, 571, 1, 1, 5868.647, 2049.936, 504.2659, 3.490694, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+13, 37967, 571, 1, 1, 5652.406, 2089.361, 798.1375, 1.710423, 120, 0, 0), -- 37967 (Area: 210)
(@CGUID+14, 31316, 571, 1, 1, 5829.46, 2031.393, 503.99, 1.32645, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+15, 31316, 571, 1, 1, 5831.737, 2024.352, 503.9846, 2.722714, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+16, 31316, 571, 1, 1, 5830.665, 1991.727, 503.9239, 1.727821, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+17, 31316, 571, 1, 1, 5859.231, 1992.497, 505.6942, 2.356147, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+18, 31316, 571, 1, 1, 5879.035, 1999.875, 509.5721, 2.598193, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+19, 31316, 571, 1, 1, 5866.767, 1990.259, 507.4477, 2.698404, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+20, 31316, 571, 1, 1, 5834.902, 2001.664, 503.9163, 1.867513, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+21, 31316, 571, 1, 1, 5922.788, 2040.055, 517.6266, 3.787891, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+22, 31316, 571, 1, 1, 5809.299, 1981.393, 503.9012, 3.176498, 120, 0, 0), -- 31316 (Area: 210)
(@CGUID+23, 31316, 571, 1, 1, 5881.739, 1963.927, 517.0669, 1.012561, 120, 0, 0); -- 31316 (Area: 210)

DELETE FROM `creature_template_addon` WHERE `entry` IN(31283,32406);
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=32406;

INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(31283, 0, 0, 0, 0, 0, '55667'),
(32406, 0, 0, 0, 0, 0, '60977 60984');

DELETE FROM `creature_text` WHERE `entry` IN(31283,31290);

INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(31283, 0, 0, 'Ah, the hand of the Ebon Blade has finally come to claim me. I tremble in fear.', 14, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31283, 1, 0, 'Hah! That''s all you''ve got? I''m surprised you even made it to the citadel.', 14, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31283, 2, 0, 'The Lich King has given me power beyond your wildest nightmares. Behold!', 14, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31283, 3, 0, 'It all ends here.', 14, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31283, 4, 0, '%s chuckles knowingly.', 16, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31283, 5, 0, 'The Lich King shall extinquish... every... last... one... of you.', 14, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31283, 6, 0, 'There you are Darion! I was wondering when you''d crawl forth!', 14, 0, 100, 0, 0, 0, 'Orbaz Bloodbane'),
(31290, 0, 0, 'Orbaz Bloodbane, self proclaimed hand of the Lich King.', 14, 0, 100, 0, 0, 0, 'Highlord Darion Mograine'),
(31290, 1, 0, 'Couldn''t wait for me to be out of the way so that you could sieze control?', 14, 0, 100, 0, 0, 0, 'Highlord Darion Mograine'),
(31290, 2, 0, 'You''ll never have what it takes to lead anything, Orbaz, not even a legion of mindless skeletons.', 14, 0, 100, 0, 0, 0, 'Highlord Darion Mograine'),
(31290, 3, 0, 'Good riddance.', 14, 0, 100, 0, 0, 0, 'Highlord Darion Mograine');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(31283,31290,3128300,3129000,3129001,31316);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31316,0,0,0,1,0,100,0,0,15000,15000,30000,11,58962,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ebon Blade Reaper - OOC - Cast Summon Death Knight Adept'),
(31316,0,1,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ebon Blade Reaper - On Spawn - Set Defensive'),

(31283,0,0,0,4,0,100,0,0,0,0,0,80,3128300,2,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - On Agro - Run Script'),
(31283,0,1,0,0,0,100,0,1500,5000,15000,20000,11,61015,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - IC - Cast Empower Runeblade'),
(31283,0,2,0,9,0,100,0,0,5,9000,15000,11,60186,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - On Range - Cast Plague Strike'),
(31283,0,3,0,0,0,100,0,15000,20000,7000,9000,11,60987,0,0,0,0,0,2,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - IC - Cast Summon Ominous Cloud'),
(31283,0,4,0,2,0,100,1,0,50,0,0,11,58939,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - On Less than 50% HP - Cast Summon Darion Morgraine'),
(31283,0,5,6,6,0,100,1,0,0,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - On Death - Say Line 6'),
(31283,0,6,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,31290,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - On Death Set Data (Darion Morgraine)'),
(31290,0,0,1,54,0,100,0,0,0,0,0,80,3129000,2,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - On Just Summoned - Run Script'),
(31290,0,1,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - On Just Summoned - Set Agressive'),
(31290,0,2,0,38,0,100,0,1,1,0,0,80,3129001,2,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - On Data Set - Run Script 2'),
(3129000,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,31283,0,0,0,0,0,0,'Darion Morgraine - Script - Face Orbaz Bloodbane'),
(3129000,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - Script - Say Line 1'),
(3129000,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - Script - Say Line 2'),
(3129000,9,3,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,31283,0,0,0,0,0,0,'Darion Morgraine - Script - Attack Orbaz Bloodbane'),
(3129000,9,4,0,0,0,100,0,7000,7000,0,0,1,6,0,0,0,0,0,19,31283,0,0,0,0,0,0,'Darion Morgraine - Script - Say Line 7 (Orbaz Bloodbane)'),
(3129000,9,5,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - Script - Set Home Position'),
(3129000,9,6,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - Script - Say Line 3'),
(3129001,9,0,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - Script 2 - Say Line 4'),
(3129001,9,1,0,0,0,100,0,10000,10000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darion Morgraine - Script 2 - Despawn'),
(3128300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - Script - Say Line 1'),
(3128300,9,1,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - Script - Say Line 2'),
(3128300,9,2,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - Script - Say Line 3'),
(3128300,9,3,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - Script - Say Line 4'),
(3128300,9,4,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Orbaz Bloodbane <The Hand of Suffering> - Script - Say Line 5');

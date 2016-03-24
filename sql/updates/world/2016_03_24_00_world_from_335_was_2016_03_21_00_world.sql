--
SET @OGUID := 63491;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(16834,16833,19766,19763,19764,16915,18827,18828,19408);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`IN(183941,183936,183940);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(16834,16833,19766,19763,19764,16915,18827,18828,19408) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1976600,1976300,1976400) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(183941,183936,183940) AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18828, 0, 0, 0, 1, 0, 100, 0, 30000, 60000, 30000, 60000, 11, 33016, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Camera Shaker - OOC - Cast Internal Shake Camera'), 
(19408, 0, 0, 0, 14, 0, 100, 0, 1000, 30, 45000, 60000, 11, 34086, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Maiden of Grief - On Friendly Heath Deficit - Whipped Frenzy'), 
(19408, 0, 1, 0, 9, 0, 100, 0, 0, 5, 10000, 15000, 11, 15968, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Maiden of Grief - On Range - Cast Lash of Pain'), 
(18827, 0, 0, 1, 2, 0, 100, 1, 0, 15, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gan''arg Sapper - On 15% - Say Line 0'), 
(18827, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 11, 33974, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gan''arg Sapper - On 15% - Cast Power Burn'), 
(18827, 0, 2, 0, 0, 0, 100, 0, 0, 2000, 45000, 60000, 11, 33895, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gan''arg Sapper - IC - Cast Set Charge'), 
(16915, 0, 0, 0, 1, 0, 100, 0, 30000, 60000, 30000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Foreman Razelcraz - OOC - Say Line 0'), 
(16915, 0, 1, 0, 1, 0, 100, 0, 45000, 90000, 45000, 90000, 11, 34396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Foreman Razelcraz - OOC - Cast Zap'), 
(16915, 0, 2, 0, 1, 0, 100, 0, 20000, 40000, 20000, 40000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Foreman Razelcraz - OOC - Play emote oneshotkick'), 
(16834, 0, 0, 0, 20, 0, 100, 0, 9423, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Obadei - On Quest Reward (Return to Obadei) - Say Line 0'), 
(16833, 0, 0, 1, 20, 0, 100, 0, 9424, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 16834, 11000, 0, 0, 0, 0, 0, 'Makuru - On Quest Reward (Makurus Vengeance) - Say Line 1 on Anchorite Obadei'), 
(16833, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 1, 0, 0, 0, 0, 0, 19, 16834, 0, 0, 0, 0, 0, 0, 'Makuru - On Quest Reward (Makurus Vengeance) - Face Anchorite Obadei'),
(16833, 0, 2, 3, 52, 0, 100, 0, 1, 16834, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Makuru - On Text Over (Line 1 on Anchorite Obadei) - Say Line 0'),
(16833, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 16834, 0, 0, 0, 0, 0, 0, 'Makuru - On Text Over Line 0  - Say Line 2 on Anchorite Obadei'),
(183941, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 19766, 0, 0, 0, 0, 0, 0, 'Jakks Cage - On Gameobject State Changed - Set Data 0 1'),
(19766, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 1976600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jakk - On Data Set 0 1 - Run Script (Phase 1)'),
(1976600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jakk - On Script - Set Data 0 0'),
(1976600, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jakk - On Script - Move Forward 10 Yards'),
(1976600, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jakk - On Script - Say Line 0'),
(1976600, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 32, 0, 0, 0, 0, 0, 0, 20, 183941, 0, 0, 0, 0, 0, 0, 'Jakk - On Script - Reset GO'),
(1976600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jakk - On Script - Despawn Instant'),
(183936, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 19763, 0, 0, 0, 0, 0, 0, 'Mannis Cage - On Gameobject State Changed - Set Data 0 1'),
(19763, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 1976300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Manni - On Data Set 0 1 - Run Script (Phase 1)'),
(1976300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Manni - On Script - Set Data 0 0'),
(1976300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Manni - On Script - Move Forward 10 Yards'),
(1976300, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Manni - On Script - Say Line 0'),
(1976300, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 32, 0, 0, 0, 0, 0, 0, 20, 183936, 0, 0, 0, 0, 0, 0, 'Manni - On Script - Reset GO'),
(1976300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Manni - On Script - Despawn Instant'),
(183940, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 19764, 0, 0, 0, 0, 0, 0, 'Mohs Cage - On Gameobject State Changed - Set Data 0 1'),
(19764, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 1976400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Moh - On Data Set 0 1 - Run Script (Phase 1)'),
(1976400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Moh - On Script - Set Data 0 0'),
(1976400, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Moh - On Script - Move Forward 10 Yards'),
(1976400, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Moh - On Script - Say Line 0'),
(1976400, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 32, 0, 0, 0, 0, 0, 0, 20, 183940, 0, 0, 0, 0, 0, 0, 'Moh - On Script - Reset GO'),
(1976400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Moh - On Script - Despawn Instant');

DELETE FROM `creature_text` WHERE `entry`in(16834,16833,19766,19763,19764,16915,18827);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(16915, 0, 0, 'I''ll get you working yet, you bucket of junk.', 12, 0, 100, 1, 0, 0, 17798, 0, 'Foreman Razelcraz'),
(16915, 0, 1, 'What?!  You don''t think I can do it?  I''ll show you...once I get my parts, that is.', 12, 0, 100, 1, 0, 0, 17802, 0, 'Foreman Razelcraz'),
(16915, 0, 2, 'It moved!  I swear, I saw it move!', 12, 0, 100, 0, 0, 0, 17804, 0, 'Foreman Razelcraz'),
(16915, 0, 3, 'Ouch!  That''s not right.', 12, 0, 100, 0, 0, 0, 17805, 0, 'Foreman Razelcraz'),
(16915, 0, 4, 'Oh yeah, it''s real funny isn''t it?', 12, 0, 100, 1, 0, 0, 17803, 0, 'Foreman Razelcraz'),
(16834, 0, 0, 'No!  Not... Sedai!  The orcs must pay!', 12, 0, 100, 1, 0, 0, 13997, 0, 'Anchorite Obadei'),
(16834, 1, 0, 'What have you done, Makuru?!  These are not our ways!', 12, 0, 100, 0, 0, 0, 13991, 0, 'Anchorite Obadei'),
(16834, 2, 0, 'I understand how you feel Makuru.  Sedai was my brother after all.  Yet we can''t disgrace his memory by going against his very ideals.', 12, 0, 100, 0, 0, 0, 13992, 0, 'Makuru'),
(16833, 1, 0, 'The orcs hate us, Obadei!  They''ve killed many of us before!  They deserve death and worse.', 12, 0, 100, 0, 0, 0, 13996, 0, 'Makuru'),
(19766, 0, 0, 'I don''t know which is worse, getting eaten by fel orcs or working for that slave master Razelcraz! Oh well, thanks anyways!', 12, 0, 100, 66, 0, 0, 17410, 0, 'Jakk'),
(19763, 0, 0, 'Thank goodness you got here, it was almost dinner time!', 12, 0, 100, 3, 0, 0, 17407, 0, 'Manni'),
(19764, 0, 0, 'I thought I was a goner for sure.', 12, 0, 100, 4, 0, 0, 17409, 0, 'Moh'),
(18827, 0, 0, '%s''s eyes glow red as he begins to cackle madly!.', 16, 7, 100, 0, 0, 0, 16771, 0, 'Gan''arg Sapper');


DELETE FROM gameobject WHERE `id` =183934;
INSERT INTO gameobject (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 183934, 530, 0, 0, 1, 1, 9.587782, 3181.049, 9.555613, 2.111848, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+1, 183934, 530, 0, 0, 1, 1, -15.59028, 3096.009, 0.048549, 2.862335, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+2, 183934, 530, 0, 0, 1, 1, 74.26378, 3039.501, -0.616187, 4.415683, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+3, 183934, 530, 0, 0, 1, 1, 185.5247, 3007.743, -0.824237, 2.652894, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+4, 183934, 530, 0, 0, 1, 1, 193.6588, 3062.065, -0.588734, 2.042035, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+5, 183934, 530, 0, 0, 1, 1, 263.3892, 3016.845, -0.839023, 6.003934, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+6, 183934, 530, 0, 0, 1, 1, 44.87815, 3077.427, -1.222514, 0.05235888, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+7, 183934, 530, 0, 0, 1, 1, 22.71669, 3097.806, -0.868156, 5.567601, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+8, 183934, 530, 0, 0, 1, 1, 20.05642, 3070.531, -0.681531, 5.969027, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+9, 183934, 530, 0, 0, 1, 1, 26.94727, 3130.273, -0.856446, 4.76475, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+10, 183934, 530, 0, 0, 1, 1, 101.7286, 3043.015, -1.222528, 5.480334, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+11, 183934, 530, 0, 0, 1, 1, 174.7734, 3039.325, -0.794917, 0.6806767, 0, 0, 0, 1, 120, 255, 1, 20886), -- 183934 (Area: 0)
(@OGUID+12, 183934, 530, 0, 0, 1, 1, 263.3892, 3016.845, -0.839023, 6.003934, 0, 0, 0, 1, 120, 255, 1, 20886); -- 183934 (Area: 0)


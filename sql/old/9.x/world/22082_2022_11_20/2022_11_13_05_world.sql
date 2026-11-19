SET @CGUID := 651638;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 91074, 1220, 7334, 7554, '0', 0, 0, 0, 0, -637.25701904296875, 5818.14794921875, 31.22601127624511718, 2.416151762008666992, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46597), -- Fallen Priestess (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+1, 91074, 1220, 7334, 7554, '0', 0, 0, 0, 0, -553.02862548828125, 5827.27734375, 31.05961799621582031, 5.548243522644042968, 120, 10, 0, 3923, 0, 1, 0, 0, 0, 46597), -- Fallen Priestess (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+2, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -578.03497314453125, 5898.4833984375, 29.34551048278808593, 3.187661409378051757, 120, 0, 0, 1177, 1534, 0, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform)
(@CGUID+3, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -580.87841796875, 5864.9951171875, 30.36772727966308593, 5.64469146728515625, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+4, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -579.9532470703125, 5924.71484375, 29.39070320129394531, 3.616674423217773437, 120, 0, 0, 1177, 1534, 0, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform)
(@CGUID+5, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -575.71380615234375, 5861.6591796875, 29.64555931091308593, 5.675688743591308593, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+6, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -580.04412841796875, 5892.828125, 29.34551048278808593, 3.500956296920776367, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+7, 91074, 1220, 7334, 7554, '0', 0, 0, 0, 0, -540.20489501953125, 5963.4443359375, 30.63412284851074218, 0.722543299198150634, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Fallen Priestess (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform)
(@CGUID+8, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -567.06268310546875, 5863.39208984375, 29.47466087341308593, 0.842033684253692626, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+9, 89850, 1220, 7334, 7554, '0', 0, 0, 0, 0, -617.40277099609375, 5898.05810546875, 59.55356216430664062, 3.184758663177490234, 120, 0, 0, 18828, 3801, 0, 0, 0, 0, 46597), -- The Oracle (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform, 180800 - The Oracle Channel)
(@CGUID+10, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -516.45361328125, 5875.36865234375, 29.32003402709960937, 0.433743834495544433, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+11, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -587.699462890625, 5925.1474609375, 29.38713645935058593, 3.294421672821044921, 120, 0, 0, 1177, 1534, 0, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform)
(@CGUID+12, 91074, 1220, 7334, 7554, '0', 0, 0, 0, 0, -585.2483, 5877.711, 50.9758, 0.077372439205646514, 120, 0, 0, 3923, 0, 2, 0, 0, 0, 46597), -- Fallen Priestess (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+13, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -505.204071044921875, 5887.873046875, 29.32003402709960937, 1.177370905876159667, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+14, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -578.130126953125, 5893.978515625, 29.34551048278808593, 5.608664512634277343, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+15, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -579.850341796875, 5928.12060546875, 29.34551048278808593, 5.56905984878540039, 120, 0, 0, 1177, 1534, 0, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform)
(@CGUID+16, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -516.9281005859375, 5879.0654296875, 29.32003402709960937, 1.247085213661193847, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+17, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -505.92559814453125, 5887.96630859375, 29.32003402709960937, 1.777860403060913085, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+18, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -524.319580078125, 5960.0654296875, 30.55173110961914062, 2.53598642349243164, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+19, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -523.71234130859375, 5961.29345703125, 30.45990753173828125, 3.014310836791992187, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+20, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -549.77935791015625, 5907.4931640625, 27.94503402709960937, 1.683527708053588867, 120, 0, 0, 1177, 1534, 0, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform)
(@CGUID+21, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -521.3729248046875, 5955.57080078125, 30.85639190673828125, 4.683836936950683593, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+22, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -517.15252685546875, 5937.650390625, 29.60403251647949218, 4.069017410278320312, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+23, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -514.57098388671875, 5930.2158203125, 29.34052276611328125, 2.004674911499023437, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+24, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -516.495361328125, 5933.95654296875, 29.37763214111328125, 2.719545364379882812, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+25, 106913, 1220, 7334, 7554, '0', 0, 0, 0, 0, -543.26043701171875, 5899.931640625, 27.32589530944824218, 0, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: Garden of Elune - Difficulty: 0) (Auras: 212221 - Arcane Font Area Aura)
(@CGUID+26, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -539.24322509765625, 5897.26904296875, 27.94503402709960937, 5.746972084045410156, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+27, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -541.37908935546875, 5903.96484375, 27.94503402709960937, 2.910319805145263671, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+28, 91074, 1220, 7334, 7554, '0', 0, 0, 0, 0, -506.5989990234375, 5902.01025390625, 42.88776779174804687, 4.362694740295410156, 120, 0, 0, 3923, 0, 2, 0, 0, 0, 46597), -- Fallen Priestess (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+29, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -504.166015625, 5885.416015625, 29.32003402709960937, 6.143881797790527343, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597), -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)
(@CGUID+30, 91073, 1220, 7334, 7554, '0', 0, 0, 0, 0, -517.55902099609375, 5878.6796875, 29.32003402709960937, 0.498492121696472167, 120, 10, 0, 1177, 1534, 1, 0, 0, 0, 46597); -- Shadowfiend (Area: Garden of Elune - Difficulty: 0) (Auras: 34429 - Shadowform) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '34429'), -- Fallen Priestess - 34429 - Shadowform
(@CGUID+1, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '34429'), -- Fallen Priestess - 34429 - Shadowform
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+7, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '34429'), -- Fallen Priestess - 34429 - Shadowform
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+9, 0, 0, 33554432, 1, 0, 0, 0, 0, 3, '34429 180800'), -- The Oracle - 34429 - Shadowform, 180800 - The Oracle Channel
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+12, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '34429'), -- Fallen Priestess - 34429 - Shadowform
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, 0, '212221'), -- Font of Arcane Energy - 212221 - Arcane Font Area Aura
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+28, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '34429'), -- Fallen Priestess - 34429 - Shadowform
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'), -- Shadowfiend - 34429 - Shadowform
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, 0, '34429'); -- Shadowfiend - 34429 - Shadowform

SET @PATH := (@CGUID+12) * 10;
UPDATE `creature_addon` SET `path_id` = @PATH WHERE `guid` = @CGUID+12;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -585.2483, 5877.711, 50.9758, 0),
(@PATH, 1, -571.1528, 5881.028, 51.72993, 0),
(@PATH, 2, -558.5243, 5885.581, 44.68542, 0),
(@PATH, 3, -541.6528, 5883.705, 43.42733, 0),
(@PATH, 4, -523.6702, 5890.212, 43.57803, 0),
(@PATH, 5, -513.1945, 5889.158, 43.13347, 0),
(@PATH, 6, -506.6337, 5901.915, 42.80594, 0),
(@PATH, 7, -504.2014, 5908.583, 48.53978, 0),
(@PATH, 8, -504.4948, 5936.169, 46.83148, 0),
(@PATH, 9, -518.1962, 5956.958, 49.67833, 0),
(@PATH, 10, -541.1389, 5959.043, 52.9966, 0),
(@PATH, 11, -564.934, 5946.511, 53.74192, 0),
(@PATH, 12, -585.6215, 5936.971, 47.63262, 0),
(@PATH, 13, -592.2743, 5923.099, 50.64303, 0),
(@PATH, 14, -585.6215, 5936.971, 47.63262, 0),
(@PATH, 15, -564.934, 5946.511, 53.74192, 0),
(@PATH, 16, -541.1389, 5959.043, 52.9966, 0),
(@PATH, 17, -518.1962, 5956.958, 49.67833, 0),
(@PATH, 18, -504.4948, 5936.169, 46.83148, 0),
(@PATH, 19, -504.2014, 5908.583, 48.53978, 0),
(@PATH, 20, -506.6337, 5901.915, 42.80594, 0),
(@PATH, 21, -513.1945, 5889.158, 43.13347, 0),
(@PATH, 22, -523.6702, 5890.212, 43.57803, 0),
(@PATH, 23, -541.6528, 5883.705, 43.42733, 0),
(@PATH, 24, -558.5243, 5885.581, 44.68542, 0),
(@PATH, 25, -571.1528, 5881.028, 51.72993, 0),
(@PATH, 26, -585.2483, 5877.711, 50.9758, 0),
(@PATH, 27, -594.3768, 5873.931, 51.44189, 0);

SET @PATH := (@CGUID+28) * 10;
UPDATE `creature_addon` SET `path_id` = @PATH WHERE `guid` = @CGUID+28;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -536.7743, 5857.884, 43.81964, 0),
(@PATH, 1, -560.0695, 5861.874, 43.85038, 0),
(@PATH, 2, -572.4114, 5874.359, 44.91866, 0),
(@PATH, 3, -580.8455, 5891.378, 44.51083, 0),
(@PATH, 4, -585.441, 5906.236, 45.30875, 0),
(@PATH, 5, -580.8455, 5891.378, 44.51083, 0),
(@PATH, 6, -572.4114, 5874.359, 44.91866, 0),
(@PATH, 7, -560.0695, 5861.874, 43.85038, 0),
(@PATH, 8, -536.7743, 5857.884, 43.81964, 0),
(@PATH, 9, -510.4184, 5859.929, 44.31264, 0),
(@PATH, 10, -494.5972, 5879.706, 48.50173, 0),
(@PATH, 11, -510.4184, 5859.929, 44.31264, 0);

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=16777217 WHERE `entry`=106913; -- Font of Arcane Energy
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=91073; -- Shadowfiend

DELETE FROM `creature_template_movement` WHERE `CreatureId`=91074;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(91074, 1, 0, 1, 0, 0, 0, NULL);

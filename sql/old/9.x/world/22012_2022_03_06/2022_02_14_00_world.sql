SET @CGUID := 1050673;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 168397, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4548.8203125, -4543.896484375, 6505.51513671875, 5.315079212188720703, 7200, 3, 0, 5, 0, 1, 0, 0, 0, 42010), -- Soulwing Flitter (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4517.55224609375, -4477.84033203125, 6499.1943359375, 3.626362562179565429, 7200, 0, 0, 6755, 0, 0, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+2, 168437, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4581.080078125, -4486.03515625, 6483.37939453125, 1.323262929916381835, 7200, 4, 0, 27, 0, 1, 0, 0, 0, 42010), -- Riverfall Hatchling (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4562.7421875, -4482.61865234375, 6489.9892578125, 1.947251677513122558, 7200, 4, 0, 6755, 0, 1, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 168624, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4554.44580078125, -4509.3857421875, 6501.22314453125, 5.897574901580810546, 7200, 3, 0, 5, 0, 1, 0, 0, 0, 42010), -- Spiritwing Flitter (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4525.22509765625, -4540.35107421875, 6515.6962890625, 5.648643016815185546, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+6, 168437, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4560.14697265625, -4471.55908203125, 6491.5751953125, 2.378290414810180664, 7200, 4, 0, 27, 0, 1, 0, 0, 0, 42010), -- Riverfall Hatchling (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4593.56396484375, -4453.86181640625, 6515.18603515625, 2.353317975997924804, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+8, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4578.01123046875, -4473.8994140625, 6482.61767578125, 4.101346969604492187, 7200, 4, 0, 6755, 0, 1, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4530.07470703125, -4557.78369140625, 6532.90478515625, 1.17114269733428955, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+10, 168437, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4593.53515625, -4475.2060546875, 6483.12939453125, 0.62026369571685791, 7200, 4, 0, 27, 0, 1, 0, 0, 0, 42010), -- Riverfall Hatchling (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4514.90087890625, -4486.02783203125, 6522.21337890625, 4.731200218200683593, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+12, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4591.015625, -4522.5, 6498.501953125, 0, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+13, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4591.1494140625, -4468.88916015625, 6483.86572265625, 5.225974082946777343, 7200, 0, 0, 6755, 0, 0, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+14, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4531.88427734375, -4484.33056640625, 6497.072265625, 1.632946729660034179, 7200, 4, 0, 6755, 0, 1, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4516.0791015625, -4497.2783203125, 6518.74169921875, 1.478560686111450195, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+16, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4567.7646484375, -4493.99169921875, 6490.42822265625, 0.996877312660217285, 7200, 4, 0, 6755, 0, 1, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 170399, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4582.982421875, -4528.3017578125, 6512.3046875, 5.081422805786132812, 7200, 3, 0, 2702, 0, 1, 0, 0, 0, 42010), -- Eternal Flutterer (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+18, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4599.580078125, -4464.455078125, 6483.86328125, 5.989694118499755859, 7200, 0, 0, 6755, 0, 0, 0, 0, 0, 42010), -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+19, 168437, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4522.7265625, -4481.349609375, 6497.072265625, 0.292805433273315429, 7200, 4, 0, 27, 0, 1, 0, 0, 0, 42010), -- Riverfall Hatchling (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 168502, 2222, 10534, 10534, '0', 0, 0, 0, 0, -4590.06103515625, -4483.50830078125, 6483.12939453125, 3.439382553100585937, 7200, 4, 0, 6755, 0, 1, 0, 0, 0, 42010); -- Riverfall Snapper (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'),
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'),
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703');

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 170399;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(170399, 1, 0, 1, 0, 0, 0);

-- SAI and Script for Riverfall Snapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` = 168502;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 168502 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(168502, 0, 0, 0, 0, 0, 100, 0, 1000, 3000, 3000, 8000, 0, '', 11, 250208, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Riverfall Snapper - init. 1-3s and repeat every 3-8s - cast \"Snapping Bite\" 250208 - to Victim');

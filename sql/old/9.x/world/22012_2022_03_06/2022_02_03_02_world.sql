-- 
SET @CGUID := 1050571;
SET @OGUID := 600215;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 158509, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4429.30419921875, -4427.51953125, 6571.00732421875, 0.433615148067474365, 7200, 3, 0, 1830, 0, 1, 0, 0, 0, 42010), -- Effervescent Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 158509, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4350.84033203125, -4469.80322265625, 6577.0771484375, 3.96711277961730957, 7200, 3, 0, 1830, 0, 1, 0, 0, 0, 42010), -- Effervescent Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 156228, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4435.12158203125, -4445.88916015625, 6567.78515625, 4.897258758544921875, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 42010), -- Kyrian Aspirant (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 158509, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4427.240234375, -4425.9921875, 6571.42236328125, 6.115936279296875, 7200, 3, 0, 1830, 0, 1, 0, 0, 0, 42010), -- Effervescent Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 158510, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4426.96337890625, -4492.57373046875, 6570.6103515625, 2.243681907653808593, 7200, 3, 0, 3050, 0, 1, 0, 0, 0, 42010), -- Eternal Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 170415, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4375.01025390625, -4508.82275390625, 6564.52734375, 0, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 42010), -- Travel with Kleia (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 174794, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4433.0244140625, -4442.9375, 6568.81640625, 5.388559341430664062, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 42010), -- Kyrian Steward (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 154631, 2222, 10534, 11013, '0', 0, 0, 0, 1, -4436.11962890625, -4475.80908203125, 6567.779296875, 0.526129841804504394, 7200, 0, 0, 294775, 100, 0, 0, 0, 0, 42010), -- Elysian Bulwark (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+8, 154630, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4380.7568359375, -4491.486328125, 6566.70703125, 5.015207290649414062, 7200, 0, 0, 176865, 100, 0, 0, 0, 0, 42010), -- Elysian Guardian (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+9, 156228, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4426.29150390625, -4484.21533203125, 6568.8125, 0.87540823221206665, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 42010), -- Kyrian Aspirant (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 156228, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4424.13720703125, -4481.2119140625, 6567.779296875, 3.246274232864379882, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 42010), -- Kyrian Aspirant (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 158509, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4437.2744140625, -4429.78076171875, 6571.42041015625, 4.301297664642333984, 7200, 3, 0, 1830, 0, 1, 0, 0, 0, 42010), -- Effervescent Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 158510, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4371.2705078125, -4427.52734375, 6572.78564453125, 5.560556411743164062, 7200, 3, 0, 3050, 0, 1, 0, 0, 0, 42010), -- Eternal Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 156228, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4437.4755859375, -4448.59228515625, 6567.783203125, 6.073504447937011718, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 42010), -- Kyrian Aspirant (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 158510, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4377.06103515625, -4466.60888671875, 6572.1630859375, 3.919882774353027343, 7200, 3, 0, 3050, 0, 1, 0, 0, 0, 42010), -- Eternal Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 158509, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4342.44140625, -4470.4853515625, 6577.48046875, 5.529840946197509765, 7200, 3, 0, 1830, 0, 1, 0, 0, 0, 42010), -- Effervescent Glimmerfly (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 174635, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4396.8525390625, -4457.41845703125, 6567.8095703125, 3.825057744979858398, 7200, 0, 0, 6100, 100, 0, 0, 0, 0, 42010), -- Depleted Praetor (Area: -Unknown- - Difficulty: 0) (Auras: 201326 - Permanent Feign Death (Spawn, Untrackable, No Stun), 29266 - Permanent Feign Death)
(@CGUID+17, 158509, 2222, 10534, 11013, '0', 0, 0, 0, 0, -4350.80517578125, -4465.1279296875, 6577.78076171875, 3.927998781204223632, 7200, 3, 0, 1830, 0, 1, 0, 0, 0, 42010); -- Effervescent Glimmerfly (Area: -Unknown- - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+6, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Kyrian Steward
(@CGUID+9, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Kyrian Aspirant

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 344725, 2222, 10534, 11013, '0', 0, 0, -4369.22216796875, -4541.80908203125, 6559.80712890625, 0.30828145146369934, 0, 0, 0.153531074523925781, 0.988143801689147949, 7200, 255, 0, 42010); -- Birds (Area: -Unknown- - Difficulty: 0)

-- SAI Scripts
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` = 156228;

DELETE FROM `smart_scripts` WHERE (`entryorguid` = (-(@CGUID+2)) AND `source_type` = 0) OR (`entryorguid` = (-(@CGUID+10)) AND `source_type` = 0) OR (`entryorguid` = (-(@CGUID+13)) AND `source_type` = 0);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+2), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 5000, 10000, 0, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kyrian Aspirant - After 1-5s and repeat every 5-10s - use Emote 1 - to self'),
(-(@CGUID+10), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 5000, 10000, 0, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kyrian Aspirant - After 1-5s and repeat every 5-10s - use Emote 1 - to self'),
(-(@CGUID+13), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 5000, 10000, 0, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Kyrian Aspirant - After 1-5s and repeat every 5-10s - use Emote 1 - to self');

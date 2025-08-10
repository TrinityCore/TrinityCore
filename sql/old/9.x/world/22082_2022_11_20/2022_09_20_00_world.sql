SET @OGUID := 500512;

-- Delete old Lightbeam and Sign
DELETE FROM `gameobject` WHERE `guid` IN (202730, 202731);
DELETE FROM `gameobject_addon` WHERE `guid` IN (202730, 202731);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 292624, 0, 28, 196, '0', '0', 0, 1021.328125, -1817.296875, 77.22247314453125, 3.028127431869506835, 0, 0, 0.998391151428222656, 0.056702151894569396, 120, 255, 1, 45338), -- Bench (Area: Uther's Tomb - Difficulty: 0)
(@OGUID+1, 292625, 0, 28, 196, '0', '0', 0, 1017.1353759765625, -1803.1649169921875, 77.27005767822265625, 3.77864241600036621, 0, 0, -0.94969844818115234, 0.313165903091430664, 120, 255, 1, 45338), -- Bench (Area: Uther's Tomb - Difficulty: 0)
(@OGUID+2, 268164, 0, 28, 196, '0', '0', 0, 971.2603759765625, -1825.2972412109375, 83.30905914306640625, 0.38397151231765747, 0.007682323455810546, -0.03952312469482421, 0.190653800964355468, 0.980831325054168701, 120, 255, 1, 45338); -- Uther the Lightbringer (Area: Uther's Tomb - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+2, 0, 0, 0.147809371352195739, 0.989015877246856689, 0, 0); -- Uther the Lightbringer

-- Update Template
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=1854; -- High Priest Thel'danis
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=17253; -- Defile Uther's Tomb Trigger

-- Update GameObject
UPDATE `gameobject_template` SET `ContentTuningId`=25, `VerifiedBuild`=45338 WHERE `entry`=181653; -- Temp Uther's Statue

-- Update Page text
UPDATE `page_text` SET `Text`='Here lies Uther the Lightbringer\nFirst Paladin - Founder of the Order of the Silver Hand\n\nUther lived and died to defend the kingdom of Lordaeron. Though he was betrayed by his most beloved student, we believe that his spirit lives on. He continues to watch over us, even as the shadows close in around our ruined land. His light is the light of all humanity - and so long as we honor his example, it shall never fade.\n\n- Anonymous', `VerifiedBuild`=45338 WHERE `ID`=292; -- 292

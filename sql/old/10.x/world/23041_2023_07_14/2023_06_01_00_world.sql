SET @CGUID := 9003905;
SET @OGUID := 9000358;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 203482, 0, 1519, 6292, '0', 20143, 0, 0, 0, -8348.486328125, 198.5260467529296875, 170.681671142578125, 0, 120, 0, 0, 29962, 0, 0, 0, 0, 0, 49801), -- Grapple Point (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+1, 198884, 0, 1519, 6292, '0', 20340, 0, 0, 1, -8352.515625, 203.548614501953125, 170.6827239990234375, 0, 120, 0, 0, 2258380, 0, 0, 0, 0, 0, 49801), -- Master Mathias Shaw (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+2, 198885, 0, 1519, 6292, '0', 20143, 0, 0, 1, -8348.736328125, 204.638885498046875, 170.604766845703125, 2.94677591323852539, 120, 0, 0, 112919, 100, 0, 0, 0, 0, 49801), -- SI:7 Agent (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@CGUID+3, 198886, 0, 1519, 6292, '0', 20143, 0, 0, 0, -8350.3125, 204.6319427490234375, 170.63250732421875, 0.768349647521972656, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49801); -- Defias Thief (Area: Stormwind Keep - Difficulty: 0) CreateObject1 (Auras: 130966 - Permanent Feign Death, 400557 - Permanent Feign Death ( Small Dark Blood Pool, no anim))

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 395704, 0, 1519, 6292, '0', 20143, 0, -8343.4912109375, 191.4184112548828125, 139.559326171875, 0, 0, 0, 0, 1, 120, 255, 1, 49801), -- Grappling Hook (Area: Stormwind Keep - Difficulty: 0) CreateObject1
(@OGUID+1, 386399, 0, 1519, 6292, '0', 20143, 0, -8349.263671875, 200.4756927490234375, 167.5677032470703125, 2.180500268936157226, 0, 0, 0.886742591857910156, 0.462263554334640502, 120, 255, 1, 49801); -- Defias Rope (Area: Stormwind Keep - Difficulty: 0) CreateObject1

-- Creature Template
DELETE FROM `creature_template_addon` WHERE `entry` IN (198884 /*198884 (Master Mathias Shaw)*/, 198886 /*198886 (Defias Thief) - Permanent Feign Death, Permanent Feign Death ( Small Dark Blood Pool, no anim)*/, 198885 /*198885 (SI:7 Agent)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198884, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 198884 (Master Mathias Shaw)
(198886, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '130966 400557'), -- 198886 (Defias Thief) - Permanent Feign Death, Permanent Feign Death ( Small Dark Blood Pool, no anim)
(198885, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 198885 (SI:7 Agent)

UPDATE `creature_template` SET `faction`=34, `BaseAttackTime`=1000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=198886; -- Defias Thief
UPDATE `creature_template` SET `faction`=12, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198885; -- SI:7 Agent
UPDATE `creature_template` SET `faction`=12, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=198884; -- Master Mathias Shaw
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217, `flags_extra`=128 WHERE `entry`=203482; -- Grapple Point

-- GameObject Template
DELETE FROM `gameobject_template` WHERE `entry` IN (395704 /*Grappling Hook*/, 386399 /*Defias Rope*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(395704, 10, 77771, 'Grappling Hook', '', '', '', 1.5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 406255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49801), -- Grappling Hook
(386399, 5, 9806, 'Defias Rope', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49801); -- Defias Rope

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (386399 /*Defias Rope*/, 395704 /*Grappling Hook*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(386399, 0, 545259520, 0, 0), -- Defias Rope
(395704, 0, 545259520, 0, 0); -- Grappling Hook

-- Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (198885,198884));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(198885, 1, 155765, 0, 0, 0, 0, 0, 0, 0, 0, 49801), -- SI:7 Agent
(198884, 1, 47104, 0, 0, 47104, 0, 0, 0, 0, 0, 49801); -- Master Mathias Shaw

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (20143, 20340);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(20340, 'Cosmetic - See Master Mathias Shawn behind Stormwind Keep'),
(20143, 'Cosmetic - See SI7 Agent and Defias Thief behind Stormwind Keep');

DELETE FROM `phase_area` WHERE (`AreaId` = 1519 AND `PhaseId` IN (20143, 20340));
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 20340, 'Cosmetic - See Master Mathias Shawn behind Stormwind Keep'),
(1519, 20143, 'Cosmetic - See SI7 Agent and Defias Thief behind Stormwind Keep');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (20340, 20143) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 20340, 0, 0, 0, 47, 0, 75265, 2 | 8 | 64, 0, 0, 'Apply Phase 20340 if Quest 75265 is in progress | complete | rewarded'),
(26, 20340, 0, 0, 0, 47, 0, 72405, 2 | 8 | 64, 0, 1, 'Apply Phase 20340 if Quest 72405 is not in progress | complete | rewarded'),
(26, 20143, 0, 0, 0, 47, 0, 75265, 2 | 8 | 64, 0, 0, 'Apply Phase 20340 if Quest 75265 is in progress | complete | rewarded');

-- Update Condition for Phase 20675
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 20675 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 20675, 0, 0, 0, 16, 0, 0x1, 0, 0, 0, 'Apply Phase 20675 if player is Human'),
(26, 20675, 0, 0, 0, 27, 0, 50, 3, 0, 0, 'Apply Phase 20675 if player is level 50 or higher'),
(26, 20675, 0, 0, 0, 47, 0, 72405, 2 | 8 | 64, 0, 1, 'Apply Phase 20675 if Quest 72405 is not in progress | complete | rewarded');

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=75265;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75265, 0, 0, 0, 0, 0, 0, 0, 0, 'It\'s good you are here.', 49801); -- An Urgent Matter

DELETE FROM `quest_details` WHERE `ID`=72405;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72405, 1, 1, 0, 0, 0, 0, 0, 0, 49801); -- An Unlikely Informant

DELETE FROM `creature_queststarter` WHERE (`id`=198884 AND `quest`=72405);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(198884, 72405, 49801); -- An Unlikely Informant offered Master Mathias Shaw

DELETE FROM `creature_questender` WHERE (`id`=198884 AND `quest`=75265);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(198884, 75265, 49801); -- An Urgent Matter ended by Master Mathias Shaw

UPDATE `quest_template_addon` SET `ExclusiveGroup` = 75265, `NextQuestID` = 72405 WHERE `ID` IN (75265, 72644);

-- Difficulty stuff
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (198886,198885,198884,203482,201194,1860,199340,91226));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(198886, 0, 0, 0, 1281, 9, 1, 1, 227299, 0, 0, 49801),
(198885, 0, 0, 0, 1281, 9, 1, 1, 227298, 0, 0, 49801),
(198884, 0, 0, 0, 1281, 9, 20, 1, 227297, 0, 0, 49801),
(203482, 0, 0, 0, 2043, 8, 1, 1, 232579, 1610612752, 117440518, 49801),
(201194, 0, 0, 0, 864, 9, 1, 1, 229773, 0, 0, 49801),
(1860, 0, 0, 0, 482, 9, 1, 2, 1533, 0, 1, 49801),
(199340, 0, 0, 0, 1281, 9, 0.60000002384185791, 1, 227766, 0, 0, 49801),
(91226, 0, 0, 0, 371, 9, 1, 1, 90587, 0, 0, 49801);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=49801 WHERE (`DifficultyID`=0 AND `Entry` IN (26125,158276,45226,47325,47324,47320,65061,65066,65060,65065,65058,70296,65072,69334,65078,65074,65048,65068,68868,62106,65076,65063,65071,129679,143711,50927,50933,176242,4730,141020,14602,12359,12358,133409,158125,133408,158123,158119,133411,14555,4753,126332,112698,133672,158120,50305,14556,162393,133433,50307,172572,133509,133396,112686,133363,130069,167032,4423,42782,20716,121541,141079,112694,44395,133675,16908,62954,19269,43842,43841,7232,3681,5509,133431,80069,133441,1416,1472,43690,29725,7798,5512,197253,144135,197269,197267,5510,5511,144133,47649,62822,62821,2334,49748,6579,14563,957,5413,43823,11026,45306,5519,5518,140403,140253,140407,11069,43723,43825,43824,43724,44235,1649,68,2879,144134,47688,43725,44392,44394,61809,49540,44393,20407,43840,43034,5517,44236,5515,5516,1976,61080,63596,2620,63607,721,42421,69822,142789,142787,49908,49907,142788,69823,142786,1412,1752,4960,50088,51348,2285,1439,93296,17103,93307,61081,24729,51938,143208,151256,151255,34998,151251,34997,15187,1440,72654,1751,1750,32520,35365,175138,111190,2504,44241,44243,44238,38821,44239,151247,1756,151249));

DELETE FROM `creature_model_info` WHERE `DisplayID`=111365;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(111365, 1, 1.5, 0, 49801);

UPDATE `creature_model_info` SET `VerifiedBuild`=49801 WHERE `DisplayID` IN (24992, 71448, 107884, 72253, 92726, 77264, 34336, 35540, 35539, 35537, 45876, 43719, 39641, 43718, 43721, 43717, 47980, 43723, 47467, 43726, 43724, 45871, 41281, 46986, 42352, 43725, 43720, 43722, 99401, 82867, 87971, 2306, 100179, 2788, 1460, 14632, 6444, 6080, 93415, 46929, 18054, 83233, 82897, 93417, 93408, 93409, 82899, 14332, 5070, 41667, 72181, 83229, 14613, 93410, 37884, 93413, 37014, 14331, 90788, 82919, 37015, 98008, 83236, 82895, 83234, 86654, 80978, 28416, 68845, 82875, 37118, 82923, 24877, 2451, 77397, 1659, 19732, 27823, 14614, 72178, 18889, 33840, 18890, 81303, 81304, 33529, 33528, 6007, 10045, 99398, 83230, 46544, 82925, 4998, 86659, 5570, 33471, 26450, 6844, 3311, 109484, 87992, 109485, 4271, 3306, 86656, 3307, 5446, 2273, 8805, 42722, 42720, 36597, 86660, 5378, 14375, 99392, 4997, 99395, 99394, 34396, 37109, 3315, 37114, 37115, 3314, 37124, 86665, 2256, 32776, 10477, 33494, 33523, 8794, 99396, 33495, 99393, 48989, 3167, 99391, 5043, 8796, 99500, 33496, 719, 33839, 42250, 1141, 33838, 19598, 33527, 33497, 3310, 33740, 99390, 3309, 99389, 4558, 1072, 36620, 4626, 18055, 62354, 47710, 5369, 85246, 47711, 18931, 37310, 2961, 37311, 5075, 1758, 63522, 16854, 63521, 134, 344, 31174, 338, 15594, 328, 91081, 29515, 91080, 29514, 87011, 15321, 5553, 262, 5077, 5565, 99949, 21342, 99947, 29796, 78345, 11686, 1573, 33747, 33748, 33745, 21072, 33746, 99951, 91079, 99950, 34004, 257);
UPDATE `creature_model_info` SET `BoundingRadius`=1.60000002384185791, `VerifiedBuild`=49801 WHERE `DisplayID`=87972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=0.5, `VerifiedBuild`=49801 WHERE `DisplayID`=74513;
UPDATE `creature_model_info` SET `BoundingRadius`=0.226091504096984863, `CombatReach`=1, `VerifiedBuild`=49801 WHERE `DisplayID`=44820;

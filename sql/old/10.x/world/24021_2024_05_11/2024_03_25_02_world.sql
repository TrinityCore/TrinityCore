SET @CGUID := 7000334;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 152000, 1643, 8717, 8717, '0', 13113, 0, 0, 0, 1012.2117919921875, -535.2430419921875, 14.00807094573974609, 1.495678186416625976, 120, 0, 0, 78950, 0, 0, NULL, NULL, NULL, NULL, 53877); -- Dori'thur (Area: Boralus Harbor - Difficulty: 0) CreateObject1 (Auras: 286376 - Scroll Visual)

-- Template addon
DELETE FROM `creature_template_addon` WHERE `entry` = 152000;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(152000, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '286376'); -- 152000 (Dori'thur) - Scroll Visual

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 13113;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(13113, 'Cosmetic - See Dorithur in Boralus');

DELETE FROM `phase_area` WHERE `PhaseId` = 13113;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8717, 13113, 'See Dorithur in Boralus');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 13113 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 13113, 0, 0, 0, 47, 0, 53847, 2|8|64, 0, 1, 'Apply Phase 13113 if Quest 53847 is not in Progress | complete | rewarded');

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=53847;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(53847, 0, 0, 0, 0, 0, 0, 0, 0, 53877); -- On Whispered Winds

DELETE FROM `creature_queststarter` WHERE (`id`=152000 AND `quest`=53847);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(152000, 53847, 53877); -- On Whispered Winds offered by Dori'thur

-- Model & Difficulty
UPDATE `creature_model_info` SET `VerifiedBuild`=53877 WHERE `DisplayID` IN (87630, 88262, 79014, 342, 64074, 78632, 41408, 81312, 41667, 94459, 78631, 88271, 88594, 34450, 84139, 87613, 84069, 94462, 76871, 91012, 87803, 77523, 81291, 5565, 87800, 85758, 86168, 87801, 87761, 81166, 88690, 15275, 77687, 84173, 87495, 85277, 83521, 82995, 83093, 84812, 88051, 87782, 85228, 87796, 86640, 88607, 55344, 38801, 90165, 86443, 84166, 77041, 75719, 75855, 90661, 13069, 82026, 83532, 87788, 86639, 60256, 87638, 26353, 87596, 85280, 87811, 53108, 81313, 88613, 24052, 76552, 86471, 76549, 82025, 33719, 1141, 88612, 82024, 76907, 76222, 88604, 165, 32681, 83056, 78483, 61206, 80893, 88605, 72253, 87808, 88611, 27823, 87805, 76890, 86950, 75910, 75877, 44575, 87806, 84415, 87565, 86764, 78196, 91011, 87807, 87614, 53107, 91009, 86027, 89353, 84174, 58202, 83057, 88608, 87602, 83531, 88825, 91067, 82047, 77055, 88609, 88606, 27681, 83533, 62093, 87422, 46710, 87698, 41325, 88049, 90161, 32646, 87810, 85293, 88837, 61205, 88827, 32778, 86763, 78869, 85771, 88610, 42178, 87804, 88492, 88881, 89604, 89354, 82148, 28047, 88615, 88490, 89352, 79383, 88614, 86472, 85767);
UPDATE `creature_model_info` SET `BoundingRadius`=0.48793041706085205, `CombatReach`=0.625, `VerifiedBuild`=53877 WHERE `DisplayID`=80264;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=53877 WHERE `DisplayID`=86641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.430494368076324462, `CombatReach`=1.65000009536743164, `VerifiedBuild`=53877 WHERE `DisplayID`=86715;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.499999880790710449, `VerifiedBuild`=53877 WHERE `DisplayID`=89355;

UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=53877 WHERE (`Entry`=152000 AND `DifficultyID`=0); -- Dori'thur

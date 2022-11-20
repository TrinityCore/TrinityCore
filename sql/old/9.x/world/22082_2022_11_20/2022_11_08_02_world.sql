SET @CGUID := 651481;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89978, 1220, 7334, 7346, '0', 4475, 0, 0, 0, 1076.59375, 6590.37158203125, 139.73748779296875, 0.793651819229125976, 120, 0, 0, 3923000, 1534, 0, 0, 0, 0, 46366); -- Projection of Senegos

DELETE FROM `creature_template_addon` WHERE `entry` = 89978;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(89978, 0, 0, 0, 1, 0, 0, 0, 0, 3, ''); -- 89978 (Projection of Senegos)

UPDATE `creature_template` SET `gossip_menu_id`= 18195, `minlevel`=45, `maxlevel`=45, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2131968, `VerifiedBuild`=46366 WHERE `entry`=89978; -- Projection of Senegos

UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE `id`=89978 AND `quest`=37855;

DELETE FROM `creature_queststarter` WHERE (`id`=90916 AND `quest`=37856) OR (`id`=89975 AND `quest` = 37855);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(89975, 37855, 46366); -- The Last of the Last offered Senegos

UPDATE `quest_details` SET `VerifiedBuild`=46366 WHERE `ID` = 37855;

UPDATE `quest_poi_points` SET `VerifiedBuild`=46366 WHERE (`QuestID`=37855 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37855 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_template` SET `VerifiedBuild`=46366 WHERE `ID`=37855; -- The Last of the Last

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID` = 37855;

UPDATE `quest_poi` SET `VerifiedBuild`=46366 WHERE (`QuestID`=37855 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37855 AND `BlobIndex`=0 AND `Idx1`=0);

DELETE FROM `phase_name` WHERE `ID` = 4475;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4475, 'Cosmetic - See Projection of Senegos');

DELETE FROM `phase_area` WHERE `AreaId` IN (7346, 7359, 7338, 7361) AND `PhaseId` = 4475;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7346, 4475, 'Cosmetic - See Projection of Senegos in Azurewing Whelplands'), -- Rhut'van Passage
(7338, 4475, 'Cosmetic - See Projection of Senegos in Azurewing Whelplands'), -- Runas's Hovel
(7361, 4475, 'Cosmetic - See Projection of Senegos in Azurewing Whelplands'), -- Ley-Ruins of Zarkhenar
(7359, 4475, 'Cosmetic - See Projection of Senegos in Azurewing Whelplands'); -- Azurewing Whelplands Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4475  AND `SourceEntry` IN (7346, 7359, 7338, 7361));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4475, 7359, 0, 0, 47, 0, 37855, 2 | 64, 0, 0, 'Apply Phase 4475 if Quest 37855 is completed | rewarded'),
(26, 4475, 7359, 0, 0, 47, 0, 37857, 2 | 64, 0, 1, 'Apply Phase 4475 if Quest 37857 is not completed | rewarded'),
(26, 4475, 7338, 0, 0, 47, 0, 37855, 2 | 64, 0, 0, 'Apply Phase 4475 if Quest 37855 is completed | rewarded'),
(26, 4475, 7338, 0, 0, 47, 0, 37857, 2 | 64, 0, 1, 'Apply Phase 4475 if Quest 37857 is not completed | rewarded'),
(26, 4475, 7361, 0, 0, 47, 0, 37855, 2 | 64, 0, 0, 'Apply Phase 4475 if Quest 37855 is completed | rewarded'),
(26, 4475, 7361, 0, 0, 47, 0, 37857, 2 | 64, 0, 1, 'Apply Phase 4475 if Quest 37857 is not completed | rewarded'),
(26, 4475, 7346, 0, 0, 47, 0, 37855, 2 | 64, 0, 0, 'Apply Phase 4475 if Quest 37855 is completed | rewarded'),
(26, 4475, 7346, 0, 0, 47, 0, 37857, 2 | 64, 0, 1, 'Apply Phase 4475 if Quest 37857 is not completed | rewarded');

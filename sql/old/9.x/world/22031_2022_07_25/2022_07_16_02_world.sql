SET @CGUID := 460545;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 79470, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1935.3177490234375, 339.6163330078125, 89.04918670654296875, 4.966650962829589843, 7200, 0, 0, 9852, 1283, 0, 0, 0, 0, 44232), -- Vindicator Maraad (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 79241, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1929.1805419921875, 334.369781494140625, 89.06130218505859375, 5.631825923919677734, 7200, 0, 0, 2955600, 19245, 0, 0, 0, 0, 44232), -- Prophet Velen (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 79567, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1928.1666259765625, 331.390625, 89.19445037841796875, 6.268841266632080078, 7200, 0, 0, 2463, 1283, 0, 0, 0, 0, 44232); -- Yrel (Area: -Unknown- - Difficulty: 0) (Auras: 73299 - Crazy Mana Regen, 150626 - Righteous Fury)

DELETE FROM `creature_template_addon` WHERE `entry` = 79567;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(79567, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73299 150626'); -- 79567 (Yrel) - Crazy Mana Regen, Righteous Fury

UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=79567; -- Yrel
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=82037; -- Lunarfall Raven
UPDATE `creature_template` SET `gossip_menu_id`=16404, `minlevel`=40, `maxlevel`=40 WHERE `entry`=79241; -- Prophet Velen
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=79470; -- Vindicator Maraad

-- Condition for Visibility
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 5 AND `SourceEntry` = 79470) OR (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 5 AND `SourceEntry` = 79241) OR (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 5 AND `SourceEntry` = 79567);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(32, 5, 79470, 0, 0, 47, 0, 34582, 66, 0, 0, 'Vindicator Maraad gets visible if Quest: 34582 is complete/rewarded'),
(32, 5, 79241, 0, 0, 47, 0, 34582, 66, 0, 0, 'Prophet Velen gets visible if Quest: 34582 is complete/rewarded'),
(32, 5, 79567, 0, 0, 47, 0, 34582, 66, 0, 0, 'Yrel gets visible if Quest: 34582 is complete/rewarded');

-- Questchain
DELETE FROM `quest_template_addon` WHERE `ID` = 34583;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(34583, 0, 0, 0, 34582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

SET @CGUID := 7000292;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 98354, 1481, 7705, 7741, '0', 5305, 0, 0, 1, 1005.67022705078125, 2958.5, -10.4730129241943359, 4.753751754760742187, 120, 0, 0, 29507, 0, 0, NULL, NULL, NULL, NULL, 51237), -- Kor'vas Bloodthorn (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+1, 98229, 1481, 7705, 7741, '0', 5305, 0, 0, 1, 998.9774169921875, 2958.63720703125, -10.4732141494750976, 4.743113517761230468, 120, 0, 0, 31060, 0, 0, NULL, NULL, NULL, NULL, 51237); -- Kayn Sunfury (Area: Despair Ridge - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Kor'vas Bloodthorn
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Kayn Sunfury

-- Creature Template
UPDATE `creature_template` SET `npcflag`=281474976710659 WHERE `entry`=98229; -- Kayn Sunfury

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5305 AND `areaId` = 7741;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7741, 5305, 'Kayn Sunfury and Korvas Bloodthorn at Legion Banner');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5305 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5305, 0, 0, 0, 47, 0, 40077, 2|64, 0, 0, 'Apply Phase 5305 if Quest 40077 is complete | rewarded'),
(26, 5305, 0, 0, 0, 47, 0, 40378, 2|8|64, 0, 1, 'Apply Phase 5305 if Quest 40378 is not complete | in progress | rewarded');

-- Gossip
UPDATE `gossip_menu_option` SET `GossipOptionID`=44511, `ActionMenuID`=18993, `VerifiedBuild`=51237 WHERE (`MenuID`=18864 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=44448, `OptionBroadcastTextId`=11964, `ActionMenuID`=18864, `VerifiedBuild`=51237 WHERE (`MenuID`=18993 AND `OptionID`=0); -- OptionBroadcastTextID: 11964 - 101473

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=40077;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(40077, 1, 0, 0, 0, 0, 0, 0, 0, 'That ought to get their attention.\n\nNow, onto the business of summoning in the rest of our forces.', 51237); -- The Invasion Begins

UPDATE `quest_poi` SET `VerifiedBuild`=51237 WHERE (`QuestID`=39279 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=39279 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=39279 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=39279 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=39279 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=39279 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=76106 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=76106 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=76106 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=76106 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=40077 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=40077 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=40077 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=40077 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=51237 WHERE (`QuestID`=39279 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=39279 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=39279 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=39279 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=39279 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=11) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=10) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=39279 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=76106 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=76106 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=76106 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=76106 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=40077 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=40077 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=40077 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=40077 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=40378;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40378, 0, 0, 0, 0, 0, 0, 0, 0, 51237); -- Enter the Illidari: Ashtongue

DELETE FROM `creature_queststarter` WHERE (`id`=98229 AND `quest`=40378);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(98229, 40378, 51237); -- Enter the Illidari: Ashtongue offered Kayn Sunfury

DELETE FROM `quest_template_addon` WHERE `ID` = 40378;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(40378, 0, 0, 0, 40077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

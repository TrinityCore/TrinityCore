SET @OGUID := 700055;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 384859, 2444, 13862, 14498, '0', 19931, 0, 534.55902099609375, -1109.4791259765625, 895.48077392578125, 4.90020751953125, 0, 0, -0.63768482208251953, 0.770297348499298095, 120, 255, 1, 47213), -- Chef's Hoard (Area: The Ruby Feast - Difficulty: 0)
(@OGUID+1, 384858, 2444, 13862, 14498, '0', 19930, 0, 534.55902099609375, -1109.4791259765625, 895.48077392578125, 4.90020751953125, 0, 0, -0.63768482208251953, 0.770297348499298095, 120, 255, 1, 47213); -- Chef's Hoard (Area: The Ruby Feast - Difficulty: 0)

DELETE FROM `gameobject_template` WHERE `entry` = 384858;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(384858, 3, 73228, 'Chef\'s Hoard', '', '', '', 0.75, 1690, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115196, 0, 0, 0, 0, 2401, 47213); -- Chef's Hoard

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=384858 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(384858, 0, 202013, 47213); -- Chef's Hoard

DELETE FROM `gameobject_template_addon` WHERE `entry` = 384858;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(384858, 0, 2113540, 0, 0); -- Chef's Hoard

DELETE FROM `gameobject_loot_template` WHERE (`Entry` = 115196 AND `Item` = 202013);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(115196, 202013, 0, 100, 1, 1, 0, 1, 1, 'Ruby Recipe Journal VIII for Quest: 67071');

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID` = 67071;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(67071, 0, 0, 0, 0, 0, 0, 0, 0, 'Catch a fish for a mortal, they will eat for a day.\n\nTeach a mortal to cook, they will eat for a lifetime.\n\nGive a mortal your most prized recipe, they will think of you each time they make it. At least we hope you do.\n\n<Morsel and Rumi smile at you like only good friends can.>\n\nCome back any time, $n! The meal is on us!', 47213); -- What a Long, Sweet Trip It's Been

DELETE FROM `quest_details` WHERE `ID` = 67071;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(67071, 0, 0, 0, 0, 0, 0, 0, 0, 47213); -- What a Long, Sweet Trip It's Been

DELETE FROM `quest_request_items` WHERE `ID` = 67071;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(67071, 0, 0, 0, 0, 'Our hoard is just behind the cauldron.\n\nNot to worry though, we lowered the sealing enchantment and deathly magical traps for you!', 47213); -- What a Long, Sweet Trip It's Been

DELETE FROM `creature_queststarter` WHERE (`id`=189479 AND `quest`=67071);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(189479, 67071, 47213); -- What a Long, Sweet Trip It's Been offered Rumiastrasza

DELETE FROM `creature_questender` WHERE (`id`=189479 AND `quest`=67071);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(189479, 67071, 47213); -- What a Long, Sweet Trip It's Been ended by Rumiastrasza

UPDATE `quest_poi` SET `VerifiedBuild`=47213 WHERE (`QuestID`=67071 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=67071 AND `BlobIndex`=0 AND `Idx1`=0);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (19930, 19931);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19930, 'Cosmetic - See Chef\'s Hoard (lootable) at Ruby Feast'),
(19931, 'Cosmetic - See Chef\'s Hoard (non-lootable) at Ruby Feast');

DELETE FROM `phase_area` WHERE `AreaId` = 13862 AND `PhaseId` IN (19930, 19931);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13862, 19930, 'See Chef\'s Hoard (lootable) at Ruby Feast'),
(13862, 19931, 'See Chef\'s Hoard (non-lootable) at Ruby Feast');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (19930, 19931) AND `SourceEntry` = 13862;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 19930, 13862, 0, 0, 47, 0, 67071, 8 | 2, 0, 0, 'Apply Phase 19930 if Quest 67071 is in progress | completed'),
(26, 19931, 13862, 0, 0, 47, 0, 67071, 8 | 2, 0, 1, 'Apply Phase 19931 if Quest 67071 is not in progress | completed');

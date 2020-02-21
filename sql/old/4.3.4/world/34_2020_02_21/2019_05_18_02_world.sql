-- Fix Quest 27942 "Idolatry"

-- Furious Specter
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=47220;
UPDATE `creature_template` SET `mingold`=1500, `maxgold`=3500 WHERE `entry`=47220;
-- Eternal Protector
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=47227;
UPDATE `creature_template` SET `mingold`=1500, `maxgold`=3500 WHERE `entry`=47227;

-- Fix access to Quest 27943 "Angered Spirits"
UPDATE `quest_template_addon` SET `NextQuestID`=27950, `ExclusiveGroup`=0 WHERE `ID`=27942;
UPDATE `quest_template_addon` SET `NextQuestID`=27950, `ExclusiveGroup`=0 WHERE `ID`=27943;

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=27950 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 27950, 0, 1, 8, 0, 27942, 0, 0, 0, 0, 0, '', 'Quest Gobbles! available if quest Idolatry has been rewarded.');

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=27950 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 27950, 0, 1, 8, 0, 27943, 0, 0, 0, 0, 0, '', 'Quest Gobbles! available if quest Angered Spirits has been rewarded.');

DELETE FROM `quest_offer_reward` WHERE `ID`=27942;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`,`Emote2`,`RewardText`) VALUES
(27942, 396, 0, 'Zhese look to be of sufficient quality.$b$bVizh zhese, ve are vone shtep closah to zhe cleansink ritual.');

-- Add quest reward text "Missed from previous fix"
DELETE FROM `quest_offer_reward` WHERE `ID`=27928;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`,`Emote2`,`RewardText`) VALUES
(27928, 5, 0, 'Oh, these are exquisite!$b$bThe commander will be able to make a winter uniform with these.');

-- Add quest reward text "Missed from previous fix"
DELETE FROM `quest_offer_reward` WHERE `ID`=27941;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`,`Emote2`,`RewardText`) VALUES
(27941, 396, 0, 'Most efficient work, $c.$b$bYou should rise rapidly through the ranks.');

-- Furious Specter & Eternal Protector Loot to be redone in future Minor fix here
UPDATE `creature_loot_template` SET `Chance`=15, `GroupId`=1, `Comment`='Embersilk Cloth' WHERE `Entry`=47220 AND `Item`=53010;
UPDATE `creature_loot_template` SET `Chance`=15, `GroupId`=1, `MaxCount`=3, `Comment`='Embersilk Cloth' WHERE `Entry`=47227 AND `Item`=53010;

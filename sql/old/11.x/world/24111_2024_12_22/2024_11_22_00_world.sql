SET @CGUID := 4000252;
SET @CONDREFID := 40003;

-- Creature templates
DELETE FROM `creature_template_addon` WHERE `entry` IN (55789);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(55789, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 55789 (Rell Nightwind)

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57534 WHERE (`Entry`=55789 AND `DifficultyID`=0); -- 55789 (Rell Nightwind) - Amphibious, CanSwim
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (55789) AND `DifficultyID`=1;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=395264 AND `id`=55789;
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 55789, 0, 1519, 1519, '0', 1687, 0, 0, 0, -8458.5244140625, 352.993072509765625, 135.6565399169921875, 5.409669876098632812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534); -- Rell Nightwind (Area: Stormwind City - Difficulty: 0) CreateObject1

-- Quests
DELETE FROM `ui_map_quest_line` WHERE (`QuestLineId`=1379 AND `UIMapId` IN (36,37));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(36, 1379, 57534),
(37, 1379, 57534);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=57534 WHERE (`UIMapId`=36 AND `QuestLineId` IN (947,433,402,396,386)) OR (`UIMapId`=37 AND `QuestLineId` IN (5593,5570,5519,5513,5511,5482,5458,5382,5377,5372,1323,1289,1276,1217,1128,1030,1000,972,957,929,926,916,858,797,781,737,637,635,576,575,566,547,546,539,533,532,526,425,402,347,346,300,289,262,259,240,198,131,1226,589,421));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=57534 WHERE (`UIMapId`=49 AND `QuestLineId` IN (1090,433,426,289)) OR (`UIMapId`=84 AND `QuestLineId` IN (5593,5519,5513,5511,5497,5482,5458,5382,5377,5372,1379,1289,1276,1128,1030,1000,972,957,929,926,916,858,797,781,737,637,635,576,575,547,546,539,533,532,526,347,346,300,289,262,259,240,198,131,589,421));

DELETE FROM `quest_details` WHERE `ID` IN (60965 /*Mists of Pandaria: Onward to Adventure in Pandaria*/, 49556 /*Hero's Call: Jade Forest!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(60965, 0, 0, 0, 0, 0, 0, 0, 0, 57534), -- Mists of Pandaria: Onward to Adventure in Pandaria
(49556, 0, 0, 0, 0, 0, 0, 0, 0, 57534); -- Hero's Call: Jade Forest!

UPDATE `quest_details` SET `VerifiedBuild`=57534 WHERE `ID` IN (29547, 26365, 60125);

DELETE FROM `quest_offer_reward` WHERE `ID`=60965;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(60965, 0, 0, 0, 0, 0, 0, 0, 0, '<Quilen, tigers, and virmen... oh my! Time to see what Pandaria has to offer.>', 57534); -- Mists of Pandaria: Onward to Adventure in Pandaria

UPDATE `quest_offer_reward` SET `VerifiedBuild`=57534 WHERE `ID` IN (29547, 28716, 60125, 49556);

UPDATE `creature_queststarter` SET `VerifiedBuild`=57534 WHERE (`id`=1750 AND `quest`=29547);

DELETE FROM `creature_questender` WHERE (`id`=54870 AND `quest` IN (29854,29857));
DELETE FROM `creature_questender` WHERE (`id`=55789 AND `quest` IN (49556,49866));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(55789, 49556, 57534),
(55789, 49866, 57534);

UPDATE `creature_questender` SET `VerifiedBuild`=57534 WHERE (`id`=55789 AND `quest` IN (29547,60125));

DELETE FROM `quest_template_addon` WHERE `ID` IN (29548, 29547, 49556, 49866, 60125);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29547, 0, 0, 175344, 0, 29548, 29547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(49556, 0, 0, 175344, 0, 29548, 29547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(49866, 0, 0, 175344, 0, 29548, 29547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(60125, 0, 0, 175344, 0, 29548, 29547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=49866;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,49866,0,'','','Deprecated quest: Mists of Pandaria: To Pandaria!');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND`SourceEntry`=29547;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,29547,0,0,56,0,85466,0,0,'',0,0,0,'','Show quest 29547 if PlayerCondition 85466 is satisfied');

DELETE FROM `quest_greeting` WHERE (`ID`=1750 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(1750, 0, 0, 0, '', 57534); -- 1750

-- Phases
DELETE FROM `phase_area` WHERE `PhaseId`=1687;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 1687, 'Stormwind City: See Rell Nightwind');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=1687;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (-3,-@CONDREFID);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,1687,0,0,0,-@CONDREFID,0,0,0,0,'',1,0,0,'','Apply phase 1687 if condition reference 40003 is not fulfilled'),
(-@CONDREFID,0,0,0,0,47,0,29547,66,0,'',1,0,0,'','Apply condition reference if quest 29547 is not complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,49556,66,0,'',1,0,0,'','Apply condition reference if quest 49556 is not complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,49866,66,0,'',1,0,0,'','Apply condition reference if quest 49866 is not complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,60125,66,0,'',1,0,0,'','Apply condition reference if quest 60125 is not complete | rewarded'),
(-@CONDREFID,0,0,0,1,47,0,29548,64,0,'',0,0,0,'','Apply condition reference if quest 29548 is rewarded');

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=55789;

DELETE FROM `smart_scripts` WHERE `entryorguid`=55789 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55789,0,0,0,'',11,0,100,0,0,0,0,0,0,'',11,132606,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Rell Nightwind - On respawn - Cast ''Summon Collision Object''');

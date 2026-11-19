SET @CGUID := 4000147;
SET @CONDREFID := 40000;

-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry` IN (55054, 54870); -- General Nazgrim
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags2`=0x800 WHERE `entry`=39605; -- Garrosh Hellscream

DELETE FROM `creature_template_addon` WHERE `entry` IN (61869,61868,61867,61866,61846,61845,61844,55054,54870);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(61869, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61869 (Snuff)
(61868, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61868 (Zin'jun)
(61867, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61867 (Kiryn)
(61866, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61866 (Shokia)
(61846, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61846 (Gorrok)
(61845, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61845 (Hellscream's Vanguard)
(61844, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, ''), -- 61844 (Rivett Clutchpop)
(55054, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, ''), -- 55054 (General Nazgrim)
(54870, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, ''); -- 54870 (General Nazgrim)

UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=39605; -- 39605 (Garrosh Hellscream)

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=56819 WHERE (`Entry`=61846 AND `DifficultyID`=0); -- 61846 (Gorrok) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=56819 WHERE (`Entry`=55054 AND `DifficultyID`=0); -- 55054 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=56819 WHERE (`Entry`=54870 AND `DifficultyID`=0); -- 54870 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=56819 WHERE (`Entry`=39605 AND `DifficultyID`=0); -- 39605 (Garrosh Hellscream) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=56819 WHERE (`DifficultyID`=0 AND `Entry` IN (201314,199275,199264,199202,185670,185669,185473,185472,176261,175084,152643,130911,121541,89830,88702,88701,73151,72654,63626,62822,62821,62115,62114,61869,61868,61867,61866,61845,61844,58155,52034,51195,50488,50477,50323,49837,49743,49737,49622,49131,47571,47253,47248,47247,47246,47233,46742,46741,46709,46708,46572,46556,46555,46512,46359,46358,46357,45339,45337,44948,44919,44918,44868,44867,44866,44865,44851,44338,44160,44158,42506,37072,35068,34765,32520,31723,31720,28960,27489,26537,25075,24935,24931,24930,24929,24927,24926,24924,23635,20493,20492,20491,20490,20489,20488,20486,15476,14881,14499,14498,12796,12136,11017,9564,7010,6929,6466,5817,5614,5613,5611,5610,5609,5606,5188,4047,3413,3412,3372,3371,3370,3369,3368,3367,3342,3331,3328,3323,3319,3314,3313,3312,3310,3296,3144,2857));
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (61869,61868,61867,61866,61846,61845,61844,55054,54870) AND `DifficultyID`=1;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 54870, 1, 1637, 5356, '0', 0, 0, 0, 1, 1670.8055419921875, -4353.01220703125, 26.84072494506835937, 3.000042438507080078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- General Nazgrim (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 90442 - Generic Quest Invisibility 17)
(@CGUID+1, 55054, 1, 1637, 5356, '0', 0, 0, 0, 1, 1840.6458740234375, -4419.41650390625, 135.3163604736328125, 0.715584993362426757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- General Nazgrim (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+2, 61844, 1, 1637, 5356, '0', 0, 0, 0, 0, 1843.9322509765625, -4420.845703125, 135.316131591796875, 1.820238590240478515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Rivett Clutchpop (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+3, 61845, 1, 1637, 5356, '0', 0, 0, 0, 0, 1847.8072509765625, -4408.08154296875, 135.1502532958984375, 3.938601016998291015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+4, 61845, 1, 1637, 5356, '0', 0, 0, 0, 0, 1851.7396240234375, -4417.5869140625, 135.3153839111328125, 2.529423952102661132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+5, 61845, 1, 1637, 5356, '0', 0, 0, 0, 0, 1851.407958984375, -4411.51220703125, 135.148284912109375, 3.939165115356445312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Hellscream's Vanguard (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+6, 61846, 1, 1637, 5356, '0', 0, 0, 0, 0, 1842.060791015625, -4408.59375, 135.3155059814453125, 5.53992462158203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Gorrok (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+7, 61866, 1, 1637, 5356, '0', 0, 0, 0, 0, 1848.9254150390625, -4419, 135.315643310546875, 3.363948583602905273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Shokia (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+8, 61867, 1, 1637, 5356, '0', 0, 0, 0, 0, 1847.0538330078125, -4419.12353515625, 135.3157501220703125, 0.157710805535316467, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Kiryn (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+9, 61868, 1, 1637, 5356, '0', 0, 0, 0, 0, 1840.3541259765625, -4412.35595703125, 135.316162109375, 5.835348129272460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819), -- Zin'jun (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+10, 61869, 1, 1637, 5356, '0', 0, 0, 0, 0, 1839.85595703125, -4415.26025390625, 135.3163604736328125, 5.805415153503417968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56819); -- Snuff (Area: Grommash Hold - Difficulty: 0) CreateObject1 (Auras: 94223 - Generic Quest Invisibility 25)

UPDATE `creature` SET `zoneId`=1637, `areaId`=5356, `PhaseId`=1167, `position_x`=1665.99658203125, `position_y`=-4354.52978515625, `position_z`=26.43378829956054687, `orientation`=2.923297643661499023, `VerifiedBuild`=56819 WHERE `guid`=310903 AND `id`=39605; -- Garrosh Hellscream (Area: Grommash Hold - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, '90442'), -- General Nazgrim - 90442 - Generic Quest Invisibility 17
(@CGUID+1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3, '94223'), -- General Nazgrim - 94223 - Generic Quest Invisibility 25
(@CGUID+2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Rivett Clutchpop - 94223 - Generic Quest Invisibility 25
(@CGUID+3, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Hellscream's Vanguard - 94223 - Generic Quest Invisibility 25
(@CGUID+4, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Hellscream's Vanguard - 94223 - Generic Quest Invisibility 25
(@CGUID+5, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Hellscream's Vanguard - 94223 - Generic Quest Invisibility 25
(@CGUID+6, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Gorrok - 94223 - Generic Quest Invisibility 25
(@CGUID+7, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Shokia - 94223 - Generic Quest Invisibility 25
(@CGUID+8, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Kiryn - 94223 - Generic Quest Invisibility 25
(@CGUID+9, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'), -- Zin'jun - 94223 - Generic Quest Invisibility 25
(@CGUID+10, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, '94223'); -- Snuff - 94223 - Generic Quest Invisibility 25

-- Quests
DELETE FROM `ui_map_quest_line` WHERE (`QuestLineId`=550 AND `UIMapId` IN (85,76));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(85, 550, 56819),
(76, 550, 56819);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=56819 WHERE (`UIMapId`=85 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1129,1107,1003,973,919,860,802,796,780,636,574,546,539,531,516,377,300,290,263,261,260,612));

UPDATE `quest_poi` SET `VerifiedBuild`=56819 WHERE (`QuestID`=60964 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60964 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29612 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29612 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29612 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60126 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60126 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49538 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49538 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29611 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29611 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29611 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=56819 WHERE (`QuestID`=60964 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60964 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29612 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29612 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29612 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60126 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60126 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49538 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49538 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29611 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29611 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29611 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (29612, 60964);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29612, 0, 0, 0, 0, 0, 0, 0, 0, 56819), -- The Art of War
(60964, 0, 0, 0, 0, 0, 0, 0, 0, 56819); -- Mists of Pandaria: Onward to Adventure in Pandaria

UPDATE `quest_details` SET `VerifiedBuild`=56819 WHERE `ID` IN (60126, 49538, 29611);

DELETE FROM `quest_request_items` WHERE `ID` IN (29611 /*The Art of War*/, 29612 /*The Art of War*/, 49538 /*Warchief's Command: Jade Forest!*/, 60126 /*Mists of Pandaria: To Pandaria!*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29611, 0, 0, 0, 0, 'Blood and thunder, $r.', 56819), -- The Art of War
(29612, 0, 0, 0, 0, 'Blood and thunder, $n!', 56819), -- The Art of War
(49538, 0, 0, 0, 0, 'Lok''tar ogar, $n.', 56819), -- Warchief's Command: Jade Forest!
(60126, 0, 0, 0, 0, '', 56819); -- Mists of Pandaria: To Pandaria!

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29612, 60964);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29612, 1, 153, 0, 0, 0, 500, 0, 0, 'Ahh, good. You''re here. And not a moment too soon...', 56819), -- The Art of War
(60964, 0, 0, 0, 0, 0, 0, 0, 0, '<Quilen, tigers, and virmen... oh my! Time to see what Pandaria has to offer.>', 56819); -- Mists of Pandaria: Onward to Adventure in Pandaria

UPDATE `quest_offer_reward` SET `VerifiedBuild`=56819 WHERE `ID` IN (29611, 60126, 49538);

DELETE FROM `creature_queststarter` WHERE (`id`=54870 AND `quest` IN (29611,29612));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(54870, 29611, 56819), -- The Art of War offered by General Nazgrim
(54870, 29612, 56819); -- The Art of War offered by General Nazgrim

DELETE FROM `creature_questender` WHERE (`id`=54870 AND `quest` IN (60126,49852,49538));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(54870, 60126, 56819), -- Mists of Pandaria: To Pandaria! ended by General Nazgrim
(54870, 49852, 56819), -- To Pandaria! ended by General Nazgrim
(54870, 49538, 56819); -- Warchief's Command: Jade Forest! ended by General Nazgrim

UPDATE `creature_questender` SET `VerifiedBuild`=56819 WHERE (`id`=54870 AND `quest` IN (29611,29612));

DELETE FROM `quest_template_addon` WHERE `ID` IN (29611, 29612, 49538, 49852, 60126);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29611, 0, 0, 0, 0, 31853, 29611, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(29612, 0, 0, 0, 0, 31853, 29611, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(49538, 0, 0, 0, 0, 31853, 29611, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(49852, 0, 0, 0, 0, 31853, 29611, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(60126, 0, 0, 0, 0, 31853, 29611, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=49852;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,49852,0,'','','Deprecated quest: To Pandaria!');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND`SourceEntry` IN (29611, 29612);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,29611,0,0,47,0,26194,64,0,'',1,0,0,'','Show quest 29611 if quest 26194 is not rewarded'),
(19,0,29611,0,0,56,0,85466,0,0,'',0,0,0,'','Show quest 29611 if PlayerCondition 85466 is satisfied'),
(19,0,29612,0,0,47,0,26194,64,0,'',0,0,0,'','Show quest 29612 if quest 26194 is rewarded'),
(19,0,29612,0,0,56,0,85466,0,0,'',0,0,0,'','Show quest 29612 if PlayerCondition 85466 is satisfied');

-- Spell area
DELETE FROM `spell_area` WHERE `spell`=98546 AND `area`=5356;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(98546,5356,0,31853,0,0x4E02B3B2,2,1,64,1);

-- Phases
DELETE FROM `phase_area` WHERE `PhaseId`=1167;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5356, 1167, 'Orgrimmar - Grommash Hold: Cosmetic - Orgrimmar - Grommash Hold - See Garrosh');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=1167;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (-3,-@CONDREFID);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,1167,0,0,0,-@CONDREFID,0,0,0,0,'',1,0,0,'','Apply phase 1167 if condition reference 40000 is not fulfilled'),
(-@CONDREFID,0,0,0,0,47,0,29611,1,0,'',0,0,0,'','Apply condition reference if quest 29611 is not taken | complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,29612,1,0,'',0,0,0,'','Apply condition reference if quest 29612 is not taken | complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,49538,1,0,'',0,0,0,'','Apply condition reference if quest 49538 is not taken | complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,49852,1,0,'',0,0,0,'','Apply condition reference if quest 49852 is not taken | complete | rewarded'),
(-@CONDREFID,0,0,0,0,47,0,60126,1,0,'',0,0,0,'','Apply condition reference if quest 60126 is not taken | complete | rewarded'),
(-@CONDREFID,0,0,0,1,47,0,31853,64,0,'',0,0,0,'','Apply condition reference if quest 31853 is rewarded');

UPDATE `conditions` SET `ConditionTypeOrReference`=-@CONDREFID, `Comment`='Apply phase 16786 if condition reference 40000 is fulfilled' WHERE `ConditionTypeOrReference`=-3;

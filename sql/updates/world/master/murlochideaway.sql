-- Misc
UPDATE `conditions` SET `ElseGroup`=0 WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (149917,156622);
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (149917,156622,156612,156609,156610,166784,166800,166786,166791,166796);
UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=768, `unit_flags2`=34816 WHERE entry=156626;

DELETE FROM `creature_text` WHERE `CreatureID` IN (156626,166782,166787,166792,166797) AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(156626, 0, 0, '$n! Thank the Light! Are you injured?', 12, 0, 100, 3, 0, 152736, 178506, 0, 'Captain Garrick'),
(166782, 0, 0, '$n! You survived! We need to regroup at once.', 12, 0, 100, 3, 0, 156954, 195918, 0, 'Warlord Breka Grimaxe'),
(166787, 0, 0, 'My thanks. We\'ll find the expedition yet.', 12, 0, 100, 0, 0, 156979, 195930, 0, 'Bo'),
(166792, 0, 0, 'Mark my words, that storm was unnatural.', 12, 0, 100, 0, 0, 156978, 195932, 0, 'Mithdran Dawntracker'),
(166797, 0, 0, 'Quite the storm. Probably hit the first boat, too.', 12, 0, 100, 0, 0, 155934, 195924, 0, 'Lana Jordan');

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=10, `LevelScalingDeltaMax`=10 WHERE `Entry`=165359;

-- Questing

DELETE FROM `creature_queststarter` WHERE `id`=156626 AND `quest` IN (55122,54951);
DELETE FROM `creature_queststarter` WHERE `id`=166782 AND `quest` IN (59929,59930);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156626, 55122, 45745), -- Alliance
(156626, 54951, 45745),
(166782, 59929, 46455), -- Horde
(166782, 59930, 46455);

DELETE FROM `creature_questender` WHERE `id` IN (156626,166782);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156626, 55122, 45745), -- Alliance
(156626, 54951, 45745),
(166782, 59929, 46455), -- Horde
(166782, 59930, 46455);

DELETE FROM `quest_template_addon` WHERE `ID` IN (55122,54951,59929,59930);
INSERT INTO `quest_template_addon` (`ID`,`NextQuestID`) VALUES
(55122,54951), -- Alliance
(54951,54952),
(59929,59930), -- Horde
(59930,59931);

-- Conversations

-- Alliance conversation for Captain Garrick, Kee-La, Bjorn Stouthands, Austin Huxworth
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12043,12044,12127,11685,12128,14432,14437,12058);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12043,71223,1052006,0,0,0,0,0,45745), -- Alliance
(12044,0,0,0,0,0,0,1,45745),
(12044,69830,0,1,0,0,0,0,45745),
(12127,71535,1052012,1,0,0,0,0,45745),
(11685,71536,1052013,1,0,0,0,0,45745),
(12128,71534,1052014,1,0,0,0,0,45745),
(14432,75904,1052015,1,0,0,0,0,45745), -- Horde
(14437,76283,0,2,0,0,0,0,45745), -- Horde
(12058,71297,0,0,0,0,0,0,45745), -- Alliance
(12058,69830,0,1,0,0,0,0,45745), -- Alliance
(12058,76284,0,2,0,0,0,0,45745), -- Horde
(12058,76283,0,3,0,0,0,0,45745); -- Horde

DELETE FROM `conversation_line_template` WHERE `Id` IN (29262,29305,29263,29559,29556,29561,29322,34645,36134,36151,36152,36153);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29262,0,0,0,45745), -- Alliance
(29305,0,0,0,45745),
(29263,0,1,0,45745),
(29559,0,1,0,45745),
(29556,0,1,0,45745),
(29561,0,1,0,45745),
(29322,0,0,0,45745),
(34645,0,1,0,45745),
(36134,0,1,0,45745), -- Horde
(36151,0,2,0,45745),
(36152,0,2,0,45745),
(36153,0,3,0,45745);

DELETE FROM `conversation_template` WHERE `Id` IN (12043,12044,12127,11685,12128,14432,14437,12058);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12043,29262,0,'',45745), -- Alliance
(12044,29305,0,'',45745),
(12127,29558,0,'',45745),
(11685,29557,0,'',45745),
(12128,29560,0,'',45745),
(14432,36133,0,'',45745), -- Horde
(14437,36149,0,'',45745),
(12058,29322,0,'',45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29262,29263,29305,29559,29556,29561,29322,34645,36134,36151,36152,36153);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29262,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29262 if team is Alliance'), -- Alliance
(29,0,29263,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29263 if team is Alliance'),
(29,0,29305,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29305 if team is Alliance'),
(29,0,29556,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29557 if team is Alliance'),
(29,0,29559,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29559 if team is Alliance'),
(29,0,29561,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29561 if team is Alliance'),
(29,0,29322,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29322 if team is Alliance'),
(29,0,34645,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34645 if team is Alliance'),
(29,0,36134,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36134 if team is Horde'), -- Horde
(29,0,36151,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36151 if team is Horde'),
(29,0,36152,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36152 if team is Horde'),
(29,0,36153,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36153 if team is Horde');

-- Beach alliance scripting
UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=768, `unit_flags2`=34816, AIName="",`ScriptName`="npc_captain_garrick_beach" WHERE entry=156626;
UPDATE `creature_template` SET `ScriptName`="npc_warlord_grimaxe_beach" WHERE `entry`=166782;
UPDATE `creature_template` SET `ScriptName`="npc_healed_by_leader_beach" WHERE `entry` IN (149917,156622,166784,166800);
UPDATE `quest_template_addon` SET `ScriptName`='quest_emergency_first_aid' WHERE `ID` IN (54951,59930);
UPDATE `quest_template_addon` SET `ScriptName`='quest_finding_the_lost_expedition' WHERE `ID` IN (54952,59931);
UPDATE `creature_template` SET `ScriptName`="npc_leader_summoned_survivor_beach" WHERE `entry` IN (165359,166805);
UPDATE `creature_template` SET `ScriptName`="npc_alliance_survivors_beach_laying" WHERE `entry` IN (156609,156610,156612);
UPDATE `creature_template` SET `ScriptName`="npc_alliance_survivors_beach_standing" WHERE `entry` IN (151088,151089,154170);
UPDATE `creature_template` SET `ScriptName`="npc_horde_survivors_beach_laying" WHERE `entry` IN (166786,166791,166796);
UPDATE `creature_template` SET `ScriptName`="npc_horde_survivors_beach_standing" WHERE `entry` IN (166787,166792,166797);
UPDATE `creature_template` SET `ScriptName`="npc_murloc_spearhunter_watershaper" WHERE `entry` IN (150228,150229);

-- Pathing

-- Pathing for Private Cole 149917 and Grunt Throg 166784 "Emergency First Aid"
SET @PATH := 1052007 * 10;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-425.59723,-2607.6094,0.6097671,NULL,0,0,0,100,0),
(@PATH,2,-416.96875,-2603.981,0.6097671,NULL,0,0,0,100,0),
(@PATH,3,-405.7066,-2599.0903,1.5887985,NULL,0,0,0,100,0),
(@PATH,4,-396.3125,-2595.6328,2.8700066,NULL,0,0,0,100,0);

-- Pathing for Quartermaster Richter 156622 and Provisioner Jin'hake 166800 "Emergency First Aid"
SET @PATH := 1052008 * 10;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-399.375,-2597.3906,2.019909,NULL,0,0,0,100,0),
(@PATH,2,-391.84723,-2593.486,3.8800163,NULL,0,0,0,100,0);

-- Pathing for Bo quest "Emergency First Aid"
SET @PATH := 1052021 * 10;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-437.55035,-2610.1511,0.5548096,NULL,0,1,0,100,0);

-- Pathing for Mithdran Dawntracker "Emergency First Aid"
SET @PATH := 1052022 * 10;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-436.05557,-2607.8057,0.39855957,NULL,0,1,0,100,0);

-- Pathing for Lana Jordan "Emergency First Aid"
SET @PATH := 1052023 * 10;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-433.9479,-2608.7449,0.5111084,NULL,0,1,0,100,0);

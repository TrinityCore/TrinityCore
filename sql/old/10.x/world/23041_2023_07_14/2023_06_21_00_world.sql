-- *** Missing Spawns ***

SET @CGUID := 1051980;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0,174971,2369,10424,13377,'0',0,0,-1,0,0,-17.644917,-6.061374,9.000128,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+1,174971,2369,10424,13377,'0',0,0,-1,0,0,-16.248755,-2.245914,8.885136,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+2,174971,2369,10424,13377,'0',0,0,-1,0,0,-4.609498,-7.722448,8.843941,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+3,174971,2369,10424,13377,'0',0,0,-1,0,0,-17.633347,5.349984,8.993013,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+4,174971,2369,10424,13377,'0',0,0,-1,0,0,-7.1927896,-1.4265188,9.105859,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+5,174971,2369,10424,13377,'0',0,0,-1,0,0,-3.5559115,-6.8839636,8.878474,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+6,174971,2369,10424,13377,'0',0,0,-1,0,0,-16.220743,-7.592815,8.926627,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+7,174971,2369,10424,13377,'0',0,0,-1,0,0,-17.212137,0.9415215,8.992922,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+8,174971,2369,10424,13377,'0',0,0,-1,0,0,-7.1881604,4.13693,8.805241,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+9,174971,2369,10424,13377,'0',0,0,-1,0,0,-3.8145015,-9.154231,8.854396,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+10,168039,2369,10424,13377,'0',0,0,-1,0,0,-10.630922,-11.896218,8.97435,1.7062142,120,0,0,1,0,0,0,0,45745), -- hBoat
(@CGUID+11,174971,2261,10424,10639,'0',0,0,-1,0,0,3.8316922,5.474146,5.2092524,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+12,174971,2261,10424,10639,'0',0,0,-1,0,0,2.6647408,6.4705987,5.1801515,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+13,174971,2261,10424,10639,'0',0,0,-1,0,0,9.56842,4.517551,5.1502733,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+14,174971,2261,10424,10639,'0',0,0,-1,0,0,6.701894,6.1971374,5.194476,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+15,174971,2261,10424,10639,'0',0,0,-1,0,0,7.199659,-5.407894,5.216199,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+16,174971,2261,10424,10639,'0',0,0,-1,0,0,0.4600576,-6.25066,5.2069707,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+17,174971,2261,10424,10639,'0',0,0,-1,0,0,3.8914397,-6.136929,5.1904373,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+18,174971,2261,10424,10639,'0',0,0,-1,0,0,0.9357995,5.2422814,5.221966,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+19,174971,2261,10424,10639,'0',0,0,-1,0,0,6.4270716,4.5759077,5.2394466,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+20,174971,2261,10424,10639,'0',0,0,-1,0,0,-9.461674,-4.971889,5.456243,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+21,174971,2261,10424,10639,'0',0,0,-1,0,0,-7.5362535,4.9206376,5.2989116,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+22,174971,2261,10424,10639,'0',0,0,-1,0,0,-6.4343257,-4.8330746,5.2104034,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+23,174971,2261,10424,10639,'0',0,0,-1,0,0,8.676258,-4.551461,5.2418213,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+24,174971,2261,10424,10639,'0',0,0,-1,0,0,-3.2766402,-5.403929,5.293099,0,120,0,0,1,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+25,156403,2261,10424,10639,'0',0,0,-1,0,0,8.402318,-0.14915128,5.2594776,3.2919948,120,0,0,1,0,0,0,0,45745); -- aBoat

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(129,0,@CGUID+0), -- Horde
(129,0,@CGUID+1),
(129,0,@CGUID+2),
(129,0,@CGUID+3),
(129,0,@CGUID+4),
(129,0,@CGUID+5),
(129,0,@CGUID+6),
(129,0,@CGUID+7),
(129,0,@CGUID+8),
(129,0,@CGUID+9),
(129,0,@CGUID+10),
(128,0,@CGUID+11), -- Alliance
(128,0,@CGUID+12),
(128,0,@CGUID+13),
(128,0,@CGUID+14),
(128,0,@CGUID+15),
(128,0,@CGUID+16),
(128,0,@CGUID+17),
(128,0,@CGUID+18),
(128,0,@CGUID+19),
(128,0,@CGUID+20),
(128,0,@CGUID+21),
(128,0,@CGUID+22),
(128,0,@CGUID+23),
(128,0,@CGUID+24),
(128,0,@CGUID+25);

-- *** Creature Fixes ***

-- Misc creature and template fixes
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=1050189;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `map`=2369 AND `spawntimesecs`=7200;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=166827;
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (174971,168039);
UPDATE `creature_template` SET `faction`=35,`unit_flags`=33554432,`unit_flags2`=2048,`unit_flags3`=524320 WHERE `entry`=166814;
UPDATE `creature_template` SET `faction`=35,`unit_flags`=64,`unit_flags2`=2048,`unit_flags3`=524288 WHERE `entry`=157051;

-- Gryphons had 2 riders
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE `entry`=156345;

-- Summon data for sparing partners
DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (157051,166814);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(157051,155607,NULL,NULL),
(166814,166815,NULL,NULL);

-- *** Creature Text ***

DELETE FROM `creature_text` WHERE `CreatureID` IN (156280,160664,166824,166583,166827,157051,166814) AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(156280, 0, 0, 'Private Cole will run you through the rest of the drills. I need to discuss this storm with the helmsman.', 12, 0, 100, 0, 0, 152734, 184106, 0, 'Captain Garrick'),
(156280, 1, 0, 'Everyone below decks! Now!', 12, 0, 100, 0, 0, 152735, 177674, 0, 'Captain Garrick'),
(160664, 0, 0, 'Captain! We can\'t weather this storm for long!', 12, 0, 100, 0, 0, 152849, 177675, 0, 'Private Cole'),
(166824, 0, 0, 'Throg will spar with you for now. I must speak to the crew about the rain.', 12, 0, 100, 0, 0, 156952, 199040, 0, 'Warlord Breka Grimaxe'),
(166583, 0, 0, 'Warlord! This storm will soon overwhelm us!', 12, 0, 100, 0, 0, 156977, 195892, 0, 'Grunt Throg'),
(166827, 1, 0, 'Soldiers, brace yourselves!', 12, 0, 100, 0, 0, 156953, 195893, 0, 'Warlord Breka Grimaxe'),
(157051, 0, 0, 'I yield! Well, I\'d say you\'re more than ready for whatever we find on that island.', 12, 0, 100, 4, 0, 152848, 177677, 0, 'Alliance Sparing Partner'),
(166814, 0, 0, 'I concede! Your strength will see our mission through.', 12, 0, 100, 4, 0, 156976, 195857, 0, 'Horde Sparing Partner');

-- *** Phasing ***

DELETE FROM `phase_area` WHERE `AreaId`=13377 AND `PhaseId` IN (14355);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(13377,14355, 'NPE Horde Ship - Decoration NPCs initial');

DELETE FROM `phase_area` WHERE `AreaId`=10639 AND `PhaseId` IN (14350);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10639,14350, 'NPE Alliance Ship - Captain Garrick pre Quest 56775 rewarded upper deck');

DELETE FROM `phase_name` WHERE `ID` IN (13861,14349,14350,14353,14355,15284,15287,15514,15516);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(13861,'Cosmetic - NPE Alliance Ship - Decoration NPCs lower deck storm'),
(14349,'Cosmetic - NPE Alliance Ship - Captain Garrick deck'),
(14350,'Cosmetic - NPE Alliance Ship - Captain Garrick upper deck'),
(14353,'Cosmetic - NPE Alliance Ship - Private Cole on deck initial'),
(14355,'Cosmetic - NPE Alliance Ship - Decoration NPCs deck'),
(15284,'Cosmetic - NPE Horde Ship - Grunt Throg deck initial'),
(15287,'Cosmetic - NPE Horde Ship - Grunt Throg storm'),
(15514,'Cosmetic - NPE Horde Ship - Decoration NPCs deck initial'),
(15516,'Cosmetic - NPE Horde Ship - Decoration NPCs deck storm');

-- *** Conditions ***

-- Spawn Conditions for Warlord Breka Grimaxe spawns Phase 1
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (166573,166824,166827) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166573,0,0,47,0,59926,11,0,0,0,0,'','Spawn of creature with entry 166573 requires Quest 59926 not rewarded'),
(32,5,166824,0,0,47,0,59926,64,0,0,0,0,'','Spawn of creature with entry 166824 requires Quest 59926 rewarded'),
(32,5,166824,0,0,47,0,59928,2,0,1,0,0,'','Spawn of creature with entry 166824 requires Quest 59928 not complete'),
(32,5,166827,0,0,47,0,59928,2,0,0,0,0,'','Spawn of creature with entry 166827 requires Quest 59928 complete');

-- Phase conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15284,15514,15287,15516) AND `SourceEntry`=13377;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15284,13377,0,0,47,0,59927,8,0,1,0,0,'','Allow Phase 15284 if Quest 59927 (Stand Your Ground) is not inprogress'),
(26,15284,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15284 if Quest 59928 (Brace for Impact) is not complete'),
(26,15514,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15514 if Quest 59928 (Brace for Impact) is not Complete'),
(26,15287,13377,0,0,47,0,59928,2,0,0,0,0,'','Allow Phase 15287 if Quest 59928 (Brace for Impact) is complete'),
(26,15516,13377,0,0,47,0,59928,2,0,0,0,0,'','Allow Phase 15516 if Quest 59928 (Brace for Impact) is Complete');

-- Fix condition showing Alliance quest phase on horde on ship
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13861,14350,14353) AND `SourceEntry`=10639;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13861,10639,0,0,47,0,54933,2,0,0,0,0,'','Apply Phase 13861 if Quest 54933 (Freeing the Light) is complete'),
(26,14350,10639,0,0,47,0,56775,64,0,0,0,0,'','Apply Phase 14350 if Quest 56775 (Warming Up) is rewarded'),
(26,14350,10639,0,0,47,0,58208,2,0,1,0,0,'','Apply Phase 14350 if Quest 58208 (Brace for Impact) is not complete'),
(26,14353,10639,0,0,47,0,58208,2,0,0,0,0,'','Allow Phase 14353 if Quest 58208 (Brace for Impact) is complete');

UPDATE `conditions` SET `ConditionValue1`=58208, `Comment`='Apply Phase 13861 if Quest 58208 (Brace for Impact) is complete' WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=13861 AND `SourceEntry`=10639;

-- *** Spells ***

DELETE FROM `spell_script_names` WHERE `spell_id` IN (303065,325108);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(303065,'spell_summon_sparring_partner'),
(325108,'spell_summon_sparring_partner');

-- Crash movie spell cast on player for "Brace for Impact" quest rewarded Alliance and Horde
DELETE FROM `spell_area` WHERE `spell` IN (346797,346799);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(346797,10453,58208,0,305425,0,2,1,64,0),
(346799,10453,59928,0,325131,0,2,1,64,0);

-- Wrong storm spell in db
UPDATE `spell_area` SET `spell`=305421 WHERE `spell`=305422;

-- Teleport spell locations for "Brace for Impact" quest rewarded Alliance and Horde
DELETE FROM `spell_target_position` WHERE `ID` IN (305425,325131);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(305425,4,2175,-462.4,-2619.8,0.4,45745),
(325131,3,2175,-462.4,-2619.8,0.4,45745);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305464,325136,290901,305445);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305464,'spell_crash_landed_alliance'),
(325136,'spell_crash_landed_horde'),
(290901,'spell_attention_exiles_reach_tutorial'),
(305445,'spell_knocked_down_exiles_reach_beach');

-- *** Scenes ***

-- Add scene scripts
UPDATE `scene_template` SET `ScriptName`='scene_alliance_and_horde_ship' WHERE `SceneId` IN (2236,2486);
DELETE FROM `scene_template` WHERE `SceneId` IN (2334,2487);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2334,16,2708,0,'scene_alliance_and_horde_crash'), -- Alliance
(2487,16,2708,0,'scene_alliance_and_horde_crash'); -- Horde

-- *** Conversations ***

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (10768,12818,12798,14422,14423,14424);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(10768,73720,1050145,0,0,0,0,0,45745), -- Alliance
(10768,75916,1050189,1,0,0,0,0,45745), -- Horde
(12818,73720,1050145,0,0,0,0,0,45745), -- Alliance
(12818,75916,1050189,1,0,0,0,0,45745), -- Horde
(12798,73720,1050145,0,0,0,0,0,45745), -- Alliance
(12798,75916,1050189,1,0,0,0,0,45745), -- Horde
(14422,68598,0,0,0,0,0,0,45745), -- Alliance
(14422,75920,0,1,0,0,0,0,45745), -- Horde
(14423,68598,0,0,0,0,0,0,45745), -- Alliance
(14423,75920,0,1,0,0,0,0,45745), -- Horde
(14424,68598,0,0,0,0,0,0,45745), -- Alliance
(14424,75920,0,1,0,0,0,0,45745); -- Horde

DELETE FROM `conversation_line_template` WHERE `Id` IN (32717,35650,31445,36093,31382,36096,36099,36100,36101,36102,36103,36104);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(32717,0,0,0,45745), -- Alliance
(35650,0,1,0,45745), -- Horde
(31445,0,0,0,45745), -- Alliance
(36093,0,1,0,45745), -- Horde
(31382,0,0,0,45745), -- Alliance
(36096,0,1,0,45745), -- Horde
(36099,0,0,0,45745), -- Alliance
(36100,0,1,0,45745), -- Horde
(36101,0,0,0,45745), -- Alliance
(36102,0,1,0,45745), -- Horde
(36103,0,0,0,45745), -- Alliance
(36104,0,1,0,45745); -- Horde

DELETE FROM `conversation_template` WHERE `Id` IN (10768,12818,12798,14422,14423,14424);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(10768,32717,0,'',45745),
(12818,31445,0,'',45745),
(12798,31382,0,'',45745),
(14422,36099,0,'',45745),
(14423,36101,0,'',45745),
(14424,36103,0,'',45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (32717,35650,31445,36093,31382,36096,36099,36100,36101,36102,36103,36104);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,32717,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 32717 if team is Alliance'),
(29,0,35650,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 35650 if team is horde'),
(29,0,31445,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 31445 if team is Alliance'),
(29,0,36093,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36093 if team is horde'),
(29,0,31382,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 31382 if team is Alliance'),
(29,0,36096,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36096 if team is horde'),
(29,0,36099,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36099 if team is Alliance'),
(29,0,36100,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36100 if team is horde'),
(29,0,36101,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36101 if team is Alliance'),
(29,0,36102,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36102 if team is horde'),
(29,0,36103,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36103 if team is Alliance'),
(29,0,36104,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36104 if team is horde');

-- *** Creature scripts ***

UPDATE `creature_template` SET `ScriptName`="npc_captain_garrick_ship" WHERE entry IN (156280);
UPDATE `creature_template` SET `ScriptName`="npc_warlord_grimaxe_lower_ship" WHERE entry IN (166824);
UPDATE `creature_template` SET `ScriptName`="npc_warlord_grimaxe_upper_ship" WHERE entry IN (166827);
UPDATE `creature_template` SET `ScriptName`='npc_sparring_partner_exiles_reach' WHERE `entry` IN (157051,166814);
UPDATE `creature_template` SET `ScriptName`="npc_cole_ship" WHERE entry IN (160664);
UPDATE `creature_template` SET `ScriptName`="npc_throg_ship" WHERE entry IN (166583);
UPDATE `creature_template` SET `ScriptName`="npc_crew_ship" WHERE entry IN (157042,157043,157044,157046,166585,166590,166794,166799);
UPDATE `creature_template` SET `ScriptName`="npc_pet_ship" WHERE entry IN (167337,167342,167343,167344,167345,167346,167347,167348,167349,167350,167351,167352,167375);

-- *** Quest scripts ***

DELETE FROM `quest_template_addon` WHERE `ID` IN (56775,59926); 
INSERT INTO `quest_template_addon` (`ID`,`ScriptName`) VALUES
(56775,'q56775_warming_up'),
(59926,'q59926_warming_up');

UPDATE `quest_template_addon` SET `ScriptName`='quest_stand_your_ground' WHERE `ID` IN (58209,59927);
UPDATE `quest_template_addon` SET `ScriptName`='quest_brace_for_impact' WHERE `ID` IN (58208,59928);

-- *** String IDs ***

UPDATE `creature` SET `StringId`="q58209_cole" WHERE `guid`=1050146;
UPDATE `creature` SET `StringId`="q56775_garrick_lower_deck" WHERE `guid`=1050145;
UPDATE `creature` SET `StringId`="q56775_garrick_upper_deck" WHERE `guid`=1050589;
UPDATE `creature` SET `StringId`="q58208_garrick" WHERE `guid`=1050176;
UPDATE `creature` SET `StringId`="q58208_richter" WHERE `guid`=1050177;
UPDATE `creature` SET `StringId`="q58208_austin" WHERE `guid`=1050178;
UPDATE `creature` SET `StringId`="q58208_bjorn" WHERE `guid`=1050179;
UPDATE `creature` SET `StringId`="q58208_keela" WHERE `guid`=1050180;
UPDATE `creature` SET `StringId`="q58208_cole" WHERE `guid`=1050181;
UPDATE `creature` SET `StringId`="q58208_wolf" WHERE `guid`=1050152;
UPDATE `creature` SET `StringId`="q58208_bear" WHERE `guid`=1050148;
UPDATE `creature` SET `StringId`="q58208_tiger" WHERE `guid`=1050150;
UPDATE `creature` SET `StringId`="q58208_bunny" WHERE `guid`=1050154;
UPDATE `creature` SET `StringId`="q58208_moth" WHERE `guid`=1050156;
UPDATE `creature` SET `StringId`="q58208_dog" WHERE `guid`=1050158;
UPDATE `creature` SET `StringId`="q58208_turtle" WHERE `guid`=1050160;
UPDATE `creature` SET `StringId`="q59927_throg" WHERE `guid`=1050187;
UPDATE `creature` SET `StringId`="q59926_grimaxe_lower_deck" WHERE `guid`=1050189;
UPDATE `creature` SET `StringId`="q59926_grimaxe_upper_deck" WHERE `guid`=1050190;
UPDATE `creature` SET `StringId`="q59928_grimaxe" WHERE `guid`=1050191;
UPDATE `creature` SET `StringId`="q59928_bo" WHERE `guid`=1050201;
UPDATE `creature` SET `StringId`="q59928_mithdran" WHERE `guid`=1050199;
UPDATE `creature` SET `StringId`="q59928_lana" WHERE `guid`=1050198;
UPDATE `creature` SET `StringId`="q59928_jinhake" WHERE `guid`=1050200;
UPDATE `creature` SET `StringId`="q59928_throg" WHERE `guid`=1050188;
UPDATE `creature` SET `StringId`="q59928_wolf" WHERE `guid`=1050203;
UPDATE `creature` SET `StringId`="q59928_bat" WHERE `guid`=1050205;
UPDATE `creature` SET `StringId`="q59928_plainstrider" WHERE `guid`=1050207;
UPDATE `creature` SET `StringId`="q59928_raptor" WHERE `guid`=1050209;
UPDATE `creature` SET `StringId`="q59928_scorpion" WHERE `guid`=1050213;
UPDATE `creature` SET `StringId`="q59928_dragonhawk" WHERE `guid`=1050211;
UPDATE `creature` SET `StringId`="q59928_turtle" WHERE `guid`=1050215;

-- *** Pathing ***

-- Pathing for Captain Garrick post "Quest: Warming Up"
SET @PATH := 10501450;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH,@PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11.810547,0.9602051,5.5279408,NULL,0,0,0,100,0),
(@PATH+1,1,-0.3022461,-1.409729,5.774313,NULL,0,0,0,100,0),
(@PATH+1,2,4.697754,-2.659729,5.524313,NULL,0,0,0,100,0),
(@PATH+1,3,8.697754,-4.159729,5.524313,NULL,0,0,0,100,0),
(@PATH+1,4,12.447754,-5.159729,5.524313,NULL,0,0,0,100,0),
(@PATH+1,5,15.947754,-5.409729,6.274313,NULL,0,0,0,100,0),
(@PATH+1,6,18.947754,-5.409729,9.274313,NULL,0,0,0,100,0),
(@PATH+1,7,21.197754,-4.659729,9.774313,NULL,0,0,0,100,0),
(@PATH+1,8,30.197754,-3.659729,11.024313,NULL,0,0,0,100,0),
(@PATH+1,9,37.706055,-3.779663,12.020686,NULL,0,0,0,100,0),
(@PATH+1,10,37.83252,-1.4055176,12.501659,NULL,0,0,0,100,0);

-- Pathing for Captain Garrick "Quest: Brace for Impact"
SET @PATH := 10505890;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH,@PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,38.556152,-0.6357422,13.232409,NULL,0,1,0,100,0),
(@PATH,2,35.56421,-1.1977539,12.1479,NULL,0,1,0,100,0),
(@PATH,3,32.572266,-1.7597656,11.063391,NULL,0,1,0,100,0),
(@PATH,4,28.660645,-2.8950195,10.562886,NULL,0,1,0,100,0),
(@PATH,5,22.253174,-4.680664,9.82038,NULL,0,1,0,100,0),
(@PATH,6,18.129395,-4.897949,8.297633,NULL,0,1,0,100,0),
(@PATH,7,13.874268,-5.3256836,5.080761,NULL,0,1,0,100,0),
(@PATH,8,10.271484,-5.2910156,5.001395,NULL,0,1,0,100,0),
(@PATH,9,4.762451,-3.1137695,5.1861935,NULL,0,1,0,100,0),
(@PATH+1,1,11.084107,3.9018552,5.28156,NULL,0,1,0,100,0),
(@PATH+1,2,17.084106,4.9018555,5.53156,NULL,0,1,0,100,0),
(@PATH+1,3,26.905762,5.4174805,4.876927,NULL,0,1,0,100,0);

-- Pathing for Warlord Breka Grimaxe "Quest: Warming Up"
SET @PATH := 10501900;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH,@PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10.602051,8.918945,8.779607,NULL,0,0,0,100,0),
(@PATH+1,1,2.480713,9.498291,9.528435,NULL,0,1,0,100,0),
(@PATH+1,2,3.480713,9.748291,9.778435,NULL,0,1,0,100,0),
(@PATH+1,3,3.730713,9.998291,10.028435,NULL,0,1,0,100,0),
(@PATH+1,4,5.230713,12.248291,10.778435,NULL,0,1,0,100,0),
(@PATH+1,5,6.730713,11.748291,12.278435,NULL,0,1,0,100,0),
(@PATH+1,6,9.230713,10.748291,14.778435,NULL,0,1,0,100,0),
(@PATH+1,7,12.480713,9.498291,17.778435,NULL,0,1,0,100,0),
(@PATH+1,8,13.730713,9.498291,18.528435,NULL,0,1,0,100,0),
(@PATH+1,9,14.480713,9.248291,18.778435,NULL,0,1,0,100,0),
(@PATH+1,10,15.480713,8.998291,18.778435,NULL,0,1,0,100,0),
(@PATH+1,11,15.480713,6.748291,18.778435,NULL,0,1,0,100,0),
(@PATH+1,12,15.730713,5.748291,18.778435,NULL,0,1,0,100,0),
(@PATH+1,13,15.230713,5.498291,18.778435,NULL,0,1,0,100,0),
(@PATH+1,14,15.230713,5.248291,18.778435,NULL,0,1,0,100,0),
(@PATH+1,15,15.980713,4.248291,19.528435,NULL,0,1,0,100,0),
(@PATH+1,16,18.480713,3.248291,22.028435,NULL,0,1,0,100,0),
(@PATH+1,17,23.480713,2.248291,26.278435,NULL,0,1,0,100,0),
(@PATH+1,18,24.480713,0.24829102,26.528435,NULL,0,1,0,100,0),
(@PATH+1,19,25.730713,-1.751709,27.278435,NULL,0,1,0,100,0),
(@PATH+1,20,28.730713,-6.001709,27.278435,NULL,0,1,0,100,0),
(@PATH+1,21,29.730713,-5.751709,27.528435,NULL,0,1,0,100,0),
(@PATH+1,22,32.730713,-7.501709,30.278435,NULL,0,1,0,100,0),
(@PATH+1,23,35.480713,-6.751709,33.528435,NULL,0,1,0,100,0),
(@PATH+1,24,35.980713,-6.501709,33.778435,NULL,0,1,0,100,0),
(@PATH+1,25,38.730713,-5.501709,34.528435,NULL,0,1,0,100,0),
(@PATH+1,26,39.980713,-5.001709,35.028435,NULL,0,1,0,100,0),
(@PATH+1,27,40.980713,-4.751709,36.028435,NULL,0,1,0,100,0),
(@PATH+1,28,44.480713,-4.001709,39.778435,NULL,0,1,0,100,0),
(@PATH+1,29,45.563477,-3.4223633,39.777264,NULL,0,1,0,100,0);

-- Pathing for Warlord Breka Grimaxe "Quest: Brace for Impact"
SET @PATH := 10501910;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH,@PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,23.386414,-1.0205078,26.200092,NULL,0,1,0,100,0),
(@PATH,2,14.803528,1.5292969,18.348095,NULL,0,1,0,100,0),
(@PATH,3,15.010681,5.6401367,18.400091,NULL,0,1,0,100,0),
(@PATH,4,13.93335,10.104649,18.484093,NULL,0,1,0,100,0),
(@PATH,5,1.4016113,10.96875,9.103544,NULL,0,1,0,100,0),
(@PATH+1,1,-5.3898315,-0.84814453,9.203571,NULL,0,1,0,100,0);

-- Sparing Partner "Quest: Stand Your Ground"
DELETE FROM `waypoint_data` WHERE `id` IN (10501460,10501870);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501460,1,-13.461914,0.69628906,5.677742,NULL,0,0,0,100,0),
(10501460,2,-13.461914,0.69628906,5.677742,6.143559,1000,0,0,100,0),
(10501460,3,-13.461914,0.69628906,5.677742,NULL,0,0,0,100,0),
(10501870,1,-10.846191,11.937012,8.9623165,NULL,0,0,0,100,0),
(10501870,2,-10.846191,11.937012,8.9623165,4.677482,1000,0,0,100,0),
(10501870,3,-10.846191,11.937012,8.9623165,NULL,0,0,0,100,0);

-- Pathing for Alliance Pets "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501510);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501510,1,-0.4882717,7.923595,5.247307,NULL,0,1,0,100,0),
(10501510,2,4.7617283,6.173595,5.247307,NULL,0,1,0,100,0),
(10501510,3,8.511728,5.173595,5.247307,NULL,0,1,0,100,0),
(10501510,4,13.511728,3.423595,5.497307,NULL,0,1,0,100,0),
(10501510,5,14.761728,4.423595,5.497307,NULL,0,1,0,100,0),
(10501510,6,16.011728,4.673595,5.497307,NULL,0,1,0,100,0),
(10501510,7,17.261728,5.173595,5.497307,NULL,0,1,0,100,0),
(10501510,8,17.511728,4.923595,5.747307,NULL,0,1,0,100,0),
(10501510,9,20.011728,5.173595,5.497307,NULL,0,1,0,100,0),
(10501510,10,21.511728,4.673595,4.997307,NULL,0,1,0,100,0),
(10501510,11,23.511728,4.173595,5.247307,NULL,0,1,0,100,0),
(10501510,12,25.011728,3.923595,5.247307,NULL,0,1,0,100,0),
(10501510,13,27.011728,2.923595,5.247307,NULL,0,1,0,100,0),
(10501510,14,31.261728,-1.826405,4.997307,NULL,0,1,0,100,0),
(10501510,15,31.472656,-2.2216797,4.8911333,NULL,0,1,0,100,0);

-- Pathing for Horde Pets "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10502020);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10502020,1,-8.303954,-4.049614,9.174974,NULL,0,1,0,100,0),
(10502020,2,-6.053954,-4.299614,9.174974,NULL,0,1,0,100,0),
(10502020,3,-5.553954,-4.549614,9.174974,NULL,0,1,0,100,0),
(10502020,4,-3.5539541,-4.549614,9.424974,NULL,0,1,0,100,0),
(10502020,5,-2.8039541,-4.549614,9.424974,NULL,0,1,0,100,0),
(10502020,6,-1.7705078,-5.0163574,9.223818,NULL,0,1,0,100,0);

-- Pathing for Quartermaster Richter "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501770);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501770,1,-0.9053688,-5.5730305,5.2387342,NULL,0,1,0,100,0),
(10501770,2,0.5946312,-1.3230305,5.4887342,NULL,0,1,0,100,0),
(10501770,3,3.5946312,2.4269695,5.4887342,NULL,0,1,0,100,0),
(10501770,4,9.844631,4.9269695,5.2387342,NULL,0,1,0,100,0),
(10501770,5,17.344631,5.6769695,5.4887342,NULL,0,1,0,100,0),
(10501770,6,24.344631,5.1769695,4.9887342,NULL,0,1,0,100,0),
(10501770,7,26.844631,4.1769695,4.9887342,NULL,0,1,0,100,0),
(10501770,8,30.037842,0.7416992,4.877288,NULL,0,1,0,100,0);

-- Pathing for Kee-la "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501800);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501800,1,-9.640718,3.819191,5.6868877,NULL,0,1,0,100,0),
(10501800,2,-3.890718,3.319191,5.4368877,NULL,0,1,0,100,0),
(10501800,3,1.609282,3.819191,5.4368877,NULL,0,1,0,100,0),
(10501800,4,10.359282,4.819191,5.1868877,NULL,0,1,0,100,0),
(10501800,5,16.609282,5.569191,5.1868877,NULL,0,1,0,100,0),
(10501800,6,23.859282,5.069191,5.1868877,NULL,0,1,0,100,0),
(10501800,7,27.859282,4.069191,5.1868877,NULL,0,1,0,100,0),
(10501800,8,29.109282,-0.43080902,5.1868877,NULL,0,1,0,100,0),
(10501800,9,27.582764,-0.94091797,4.871175,NULL,0,1,0,100,0);

-- Pathing for Bjorn Stouthands "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501790);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501790,1,7.726696,-7.4220815,5.1850023,NULL,0,1,0,100,0),
(10501790,2,7.976696,-2.4220815,5.4350023,NULL,0,1,0,100,0),
(10501790,3,11.726696,3.5779185,5.1850023,NULL,0,1,0,100,0),
(10501790,4,16.976696,5.5779185,5.1850023,NULL,0,1,0,100,0),
(10501790,5,21.726696,5.8279185,4.9350023,NULL,0,1,0,100,0),
(10501790,6,25.476696,5.5779185,4.9350023,NULL,0,1,0,100,0),
(10501790,7,29.112793,4.151367,4.889695,NULL,0,1,0,100,0);

-- Pathing for Austin Huxworth "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501780);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501780,1,-1.4587336,8.48258,5.233676,NULL,0,1,0,100,0),
(10501780,2,7.2912664,6.2325807,5.233676,NULL,0,1,0,100,0),
(10501780,3,19.541267,5.4825807,5.233676,NULL,0,1,0,100,0),
(10501780,4,27.791267,4.7325807,4.983676,NULL,0,1,0,100,0),
(10501780,5,30.068604,2.567871,4.8888426,NULL,0,1,0,100,0);

-- Pathing for Private Cole "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501461);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501461,1,30.931396,6.4296875,4.817522,NULL,0,1,0,100,0);

-- Pathing for Grunt Throg "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501871);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501871,1,-3.9334717,1.109375,9.06326,NULL,0,1,0,100,0);

-- Pathing for Bo "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10502010);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10502010,1,1.2434692,5.4038086,9.206478,NULL,0,1,0,100,0);

-- Pathing for Mithdran Dawntracker "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501990);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501990,1,-2.8079834,-3.972168,9.100056,NULL,0,1,0,100,0);

-- Pathing for Lana Jordan "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10501980);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501980,1,-4.3847656,-2.7675781,9.160941,NULL,0,1,0,100,0);

-- Pathing for Provisoner Jin'hake "Quest: Brace for Impact"
DELETE FROM `waypoint_data` WHERE `id` IN (10502000);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10502000,1,-2.8266602,3.7973633,9.252101,NULL,0,1,0,100,0);

-- 
SET @CGUID := 1050182;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- InvisBunny
(@CGUID+0, 168236, 2369, 10424, 13377, '0', 0, 0, 0, 0, 0, 0, 0.183333337306976318, 0, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- InvisBunny (Area: -Unknown- - Difficulty: 0) (Auras: 327210 - -Unknown-)
-- Combat Dummy
(@CGUID+1, 160737, 2369, 10424, 13377, '0', 0, 0, 0, 0, -6.01600074768066406, 14.65951347351074218, 8.938409805297851562, 4.409868717193603515, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+2, 160737, 2369, 10424, 13377, '0', 0, 0, 0, 0, 0.768780171871185302, 12.79329395294189453, 9.043284416198730468, 4.020448684692382812, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+3, 160737, 2369, 10424, 13377, '0', 0, 0, 0, 0, -16.2326946258544921, 13.6585397720336914, 9.025111198425292968, 4.718774318695068359, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
(@CGUID+4, 160737, 2369, 10424, 13377, '0', 0, 0, 0, 0, -21.3803920745849609, 11.55309772491455078, 9.188772201538085937, 5.509765148162841796, 5, 0, 0, 114, 0, 0, 0, 0, 0, 41079), -- Combat Dummy (Area: -Unknown- - Difficulty: 0) (Auras: 344178 - -Unknown-)
-- Grunt Throg init Spawn Phase 15284
(@CGUID+5, 166583, 2369, 10424, 13377, '0', 15284, 0, 0, 0, -10.8986406326293945, 12.04399967193603515, 8.7872467041015625, 4.891136646270751953, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Grunt Throg (Area: -Unknown- - Difficulty: 0)
-- Grunt Throg stage 2 Phase 15287
(@CGUID+6, 166583, 2369, 10424, 13377, '0', 15287, 0, 0, 0, -3.93338513374328613, 1.109456777572631835, 9.280095100402832031, 3.353884696960449218, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Grunt Throg (Area: -Unknown- - Difficulty: 0)
-- Warlord Breka Grimaxe (since Spawntracking is not yet implemented we will Spawn her in Phase 0)
(@CGUID+7, 166573, 2369, 10424, 13377, '0', 0, 0, 0, 0, -10.769322395324707, 2.162891387939453125, 8.808107376098632812, 4.544299602508544921, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Warlord Breka Grimaxe (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 166824, 2369, 10424, 13377, '0', 0, 0, 0, 0, 45.563568115234375, -3.42231941223144531, 39.7888641357421875, 3.164201021194458007, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Warlord Breka Grimaxe (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 166827, 2369, 10424, 13377, '0', 0, 0, 0, 0, -5.41240262985229492, -0.8876546025276184, 9.240930557250976562, 3.146518230438232421, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Warlord Breka Grimaxe (Area: -Unknown- - Difficulty: 0)
-- Helmsmann & Apprentice Phase 0
(@CGUID+10, 172033, 2369, 10424, 13377, '0', 0, 0, 0, 0, 44.20788955688476562, 0.251497060060501098, 39.80583953857421875, 3.316708564758300781, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Helmsman Da'vees (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 171872, 2369, 10424, 13377, '0', 0, 0, 0, 0, 44.98254013061523437, 1.969390511512756347, 39.93940353393554687, 3.866490840911865234, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Apprentice Kutz (Area: -Unknown- - Difficulty: 0)
-- Decoration NPC´s Stage 1 Phase 15514
(@CGUID+12, 166799, 2369, 10424, 13377, '0', 15514, 0, 0, 0, -41.61962890625, 2.964843273162841796, 11.11386013031005859, 3.694048881530761718, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Provisoner Jin'hake (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 166585, 2369, 10424, 13377, '0', 15514, 0, 0, 0, -17.7134113311767578, -11.105330467224121, 9.08591461181640625, 6.058129310607910156, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Bo (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 166590, 2369, 10424, 13377, '0', 15514, 0, 0, 0, -24.4954071044921875, -4.35194730758666992, 9.221498489379882812, 0.865965783596038818, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Mithdran Dawntracker (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 166794, 2369, 10424, 13377, '0', 15514, 0, 0, 0, -5.1404428482055664, -14.9065370559692382, 9.045268058776855468, 4.623098373413085937, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Lana Jordan (Area: -Unknown- - Difficulty: 0) (Auras: 220252 - Spyglass)
-- Decpration NPC´s Stage 2 Phase 15516
(@CGUID+16, 166794, 2369, 10424, 13377, '0', 15516, 0, 0, 0, -4.38476991653442382, -2.767333984375, 9.195878982543945312, 2.258589506149291992, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Lana Jordan (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 166590, 2369, 10424, 13377, '0', 15516, 0, 0, 0, -2.80787324905395507, -3.97242283821105957, 9.240862846374511718, 3.152601003646850585, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Mithdran Dawntracker (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 166799, 2369, 10424, 13377, '0', 15516, 0, 0, 0, -2.82660245895385742, 3.797952890396118164, 9.229074478149414062, 3.56589365005493164, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Provisoner Jin'hake (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 166585, 2369, 10424, 13377, '0', 15516, 0, 0, 0, 1.243511676788330078, 5.404080390930175781, 9.381532669067382812, 3.520429611206054687, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- Bo (Area: -Unknown- - Difficulty: 0)
-- Orc Hunter Wolf
(@CGUID+20, 167346, 2369, 10424, 13377, '0', 15393, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Wolf (Area: -Unknown- - Difficulty: 0)
(@CGUID+21, 167346, 2369, 10424, 13377, '0', 15407, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Wolf (Area: -Unknown- - Difficulty: 0)
-- Undead Hunter Bat
(@CGUID+22, 167351, 2369, 10424, 13377, '0', 15394, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Bat (Area: -Unknown- - Difficulty: 0)
(@CGUID+23, 167351, 2369, 10424, 13377, '0', 15408, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Bat (Area: -Unknown- - Difficulty: 0)
-- Tauren Hunter Plainstrider
(@CGUID+24, 167349, 2369, 10424, 13377, '0', 15395, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Plainstrider (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 167349, 2369, 10424, 13377, '0', 15409, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Plainstrider (Area: -Unknown- - Difficulty: 0)
-- Troll Hunter Raptor
(@CGUID+26, 167350, 2369, 10424, 13377, '0', 15396, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Raptor (Area: -Unknown- - Difficulty: 0)
(@CGUID+27, 167350, 2369, 10424, 13377, '0', 15410, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Raptor (Area: -Unknown- - Difficulty: 0)
-- Bloodelf Hunter Dragonhawk
(@CGUID+28, 167343, 2369, 10424, 13377, '0', 15397, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Dragonhawk (Area: -Unknown- - Difficulty: 0)
(@CGUID+29, 167343, 2369, 10424, 13377, '0', 15411, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Dragonhawk (Area: -Unknown- - Difficulty: 0)
-- Goblin Hunter Scorpion
(@CGUID+30, 167344, 2369, 10424, 13377, '0', 15392, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Scorpion (Area: -Unknown- - Difficulty: 0)
(@CGUID+31, 167344, 2369, 10424, 13377, '0', 15406, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Scorpion (Area: -Unknown- - Difficulty: 0)
-- Pandaren Horde Hunter Turtle
(@CGUID+32, 167348, 2369, 10424, 13377, '0', 15398, 0, 0, 0, -22.7512664794921875, -3.23329925537109375, 9.205839157104492187, 3.860316991806030273, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079), -- Turtle (Area: -Unknown- - Difficulty: 0)
(@CGUID+33, 167348, 2369, 10424, 13377, '0', 15412, 0, 0, 0, -1.7705014944076538, -5.01630401611328125, 9.265521049499511718, 2.696678876876831054, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41079); -- Turtle (Area: -Unknown- - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, '327210'), -- InvisBunny - 327210 - -Unknown-
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, '344178'), -- Combat Dummy - 344178 - -Unknown-
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, '344178'), -- Combat Dummy - 344178 - -Unknown-
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '344178'), -- Combat Dummy - 344178 - -Unknown-
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '344178'), -- Combat Dummy - 344178 - -Unknown-
(@CGUID+14, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Mithdran Dawntracker
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, '220252'); -- Lana Jordan - 220252 - Spyglass

UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=157070; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167343; -- Dragonhawk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167348; -- Turtle

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (167346, 167351, 167349, 167350, 167344) AND `DifficultyID`=0;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(167346, 0, 0, 0, 482, 41079),
(167351, 0, 0, 0, 482, 41079),
(167349, 0, 0, 0, 482, 41079),
(167350, 0, 0, 0, 482, 41079),
(167344, 0, 0, 0, 482, 41079);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (59928 /*-Unknown-*/, 59927 /*-Unknown-*/, 59926 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(59928, 397, 0, 0, 0, 0, 0, 0, 0, 'This ship won\'t make it to the island in one piece.\n\nHold on to something, and pray that the elements will spare us from a grim death at sea.', 41079), -- -Unknown-
(59927, 25, 0, 0, 0, 0, 0, 0, 0, 'You show promise, $c. Perhaps you too will find glory on the island!', 41079), -- -Unknown-
(59926, 669, 397, 0, 0, 0, 259, 0, 0, 'Good, you\'ve kept training since we set sail.\n\nI need to speak with the crew about this storm. \n\nSpar with Throg. He will assess your skills and decide on your role once we make landfall.', 41079); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (59928 /*-Unknown-*/, 59927 /*-Unknown-*/, 59926 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59928, 11, 1, 6, 0, 0, 0, 0, 0, 41079), -- -Unknown-
(59927, 66, 4, 0, 0, 0, 0, 0, 0, 41079), -- -Unknown-
(59926, 669, 397, 0, 0, 0, 0, 0, 0, 41079); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=59926;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(59926, 0, 0, 0, 0, 'Do not bother me! Go and attack those combat dummies. Show me your power.', 41079); -- -Unknown-

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 13377 AND `PhaseId` IN (15284, 15514, 15287, 15516, 15393, 15407, 15394, 15408, 15395, 15409, 15396, 15410, 15397, 15411, 15392, 15406, 15398, 15412);
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(13377, 15284, 'NPE Horde Ship - Grunt Throg initial (Quest 59928 incomplete)'),
(13377, 15514, 'NPE Horde Ship - Decoration NPC´s Stage 1 (Quest 59927 incomplete)'),
(13377, 15287, 'NPE Horde Ship - Grunt Throg during Storm (Quest 59928 complete)'),
(13377, 15516, 'NPE Horde Ship - Decoration NPC´s Stage 2 (Quest 59927 complete)'),
(13377, 15393, 'NPE Horde Ship - Orc Hunter only: Wolf (Quest 59927 incomplete)'),
(13377, 15407, 'NPE Horde Ship - Orc Hunter only: Wolf (Quest 59927 complete'),
(13377, 15394, 'NPE Horde Ship - Undead Hunter only: Bat (Quest 59927 incomplete)'),
(13377, 15408, 'NPE Horde Ship - Undead Hunter only: Bat (Quest 59927 complete'),
(13377, 15395, 'NPE Horde Ship - Tauren Hunter only: Plainstrider (Quest 59927 incomplete)'),
(13377, 15409, 'NPE Horde Ship - Tauren Hunter only: Plainstrider (Quest 59927 complete'),
(13377, 15396, 'NPE Horde Ship - Troll Hunter only: Raptor (Quest 59927 incomplete)'),
(13377, 15410, 'NPE Horde Ship - Troll Hunter only: Raptor (Quest 59927 complete'),
(13377, 15397, 'NPE Horde Ship - Bloodelf Hunter only: Dragonhawk (Quest 59927 incomplete)'),
(13377, 15411, 'NPE Horde Ship - Bloodelf Hunter only: Dragonhawk (Quest 59927 complete'),
(13377, 15392, 'NPE Horde Ship - Goblin Hunter only: Scorpion (Quest 59927 incomplete)'),
(13377, 15406, 'NPE Horde Ship - Goblin Hunter only: Scorpion (Quest 59927 complete'),
(13377, 15398, 'NPE Horde Ship - Pandaren Hunter only: Turtle (Quest 59927 incomplete)'),
(13377, 15412, 'NPE Horde Ship - Pandaren Hunter only: Turtle (Quest 59927 complete');

-- Condition
DELETE FROM `conditions` WHERE `SourceEntry` = 13377 AND `SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (15393, 15407, 15394, 15408, 15395, 15409, 15396, 15410, 15397, 15411, 15392, 15406, 15398, 15412, 15284, 15287, 15514, 15516);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Orc
(26, 15393, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15393 if Player is Hunter'),
(26, 15393, 13377, 0, 0, 16, 0, 2, 0, 0, 0, 0, 0, '', 'Allow Phase 15393 if Player is Orc'),
(26, 15393, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15393 if Quest 59928 is NOT Complete'),
(26, 15407, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15407 if Player is Hunter'),
(26, 15407, 13377, 0, 0, 16, 0, 2, 0, 0, 0, 0, 0, '', 'Allow Phase 15407 if Player is Orc'),
(26, 15407, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15407 if Quest 59928 is complete'),
-- Undead
(26, 15394, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15394 if Player is Hunter'),
(26, 15394, 13377, 0, 0, 16, 0, 16, 0, 0, 0, 0, 0, '', 'Allow Phase 15394 if Player is Undead'),
(26, 15394, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15394 if Quest 59928 is NOT Complete'),
(26, 15408, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15408 if Player is Hunter'),
(26, 15408, 13377, 0, 0, 16, 0, 16, 0, 0, 0, 0, 0, '', 'Allow Phase 15408 if Player is Undead'),
(26, 15408, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15408 if Quest 59928 is complete'),
-- Tauren
(26, 15395, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15395 if Player is Hunter'),
(26, 15395, 13377, 0, 0, 16, 0, 32, 0, 0, 0, 0, 0, '', 'Allow Phase 15395 if Player is Tauren'),
(26, 15395, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15395 if Quest 59928 is NOT Complete'),
(26, 15409, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15409 if Player is Hunter'),
(26, 15409, 13377, 0, 0, 16, 0, 32, 0, 0, 0, 0, 0, '', 'Allow Phase 15409 if Player is Tauren'),
(26, 15409, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15409 if Quest 59928 is complete'),
-- Troll
(26, 15396, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15396 if Player is Hunter'),
(26, 15396, 13377, 0, 0, 16, 0, 128, 0, 0, 0, 0, 0, '', 'Allow Phase 15396 if Player is Troll'),
(26, 15396, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15396 if Quest 59928 is NOT Complete'),
(26, 15410, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15410 if Player is Hunter'),
(26, 15410, 13377, 0, 0, 16, 0, 128, 0, 0, 0, 0, 0, '', 'Allow Phase 15410 if Player is Troll'),
(26, 15410, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15410 if Quest 59928 is complete'),
-- Bloodelf
(26, 15397, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15397 if Player is Hunter'),
(26, 15397, 13377, 0, 0, 16, 0, 512, 0, 0, 0, 0, 0, '', 'Allow Phase 15397 if Player is Bloodelf'),
(26, 15397, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15397 if Quest 59928 is NOT Complete'),
(26, 15411, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15411 if Player is Hunter'),
(26, 15411, 13377, 0, 0, 16, 0, 512, 0, 0, 0, 0, 0, '', 'Allow Phase 15411 if Player is Bloodelf'),
(26, 15411, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15411 if Quest 59928 is complete'),
-- Goblin
(26, 15392, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15392 if Player is Hunter'),
(26, 15392, 13377, 0, 0, 16, 0, 256, 0, 0, 0, 0, 0, '', 'Allow Phase 15392 if Player is Goblin'),
(26, 15392, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15392 if Quest 59928 is NOT Complete'),
(26, 15406, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15406 if Player is Hunter'),
(26, 15406, 13377, 0, 0, 16, 0, 256, 0, 0, 0, 0, 0, '', 'Allow 15406 Phase if Player is Goblin'),
(26, 15406, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15406 if Quest 59928 is complete'),
-- Pandaren Horde
(26, 15398, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15398 if Player is Hunter'),
(26, 15398, 13377, 0, 0, 16, 0, 33554432, 0, 0, 0, 0, 0, '', 'Allow Phase 15398 if Player is Pandaren (H)'),
(26, 15398, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15398 if Quest 59928 is NOT Complete'),
(26, 15412, 13377, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Allow Phase 15412 if Player is Hunter'),
(26, 15412, 13377, 0, 0, 16, 0, 33554432, 0, 0, 0, 0, 0, '', 'Allow Phase 15412 if Player is Pandaren (H)'),
(26, 15412, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15412 if Quest 59928 is complete'),
-- Grunt Throg init Spawn
(26, 15284, 13377, 0, 0, 9, 0, 59927, 0, 0, 1, 0, 0, '', 'Allow Phase 15284 if Quest 59927 IS NOT taken'),
(26, 15284, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15284 if Quest 59928 IS NOT complete'),
-- Grunt Throg Stage 2
(26, 15287, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15287 if Quest 59928 IS complete'),
-- decoration npcs stage 1
(26, 15514, 13377, 0, 0, 28, 0, 59928, 0, 0, 1, 0, 0, '', 'Allow Phase 15514 if Quest 59928 is NOT Complete'),
-- decoration npcs stage 2
(26, 15516, 13377, 0, 0, 28, 0, 59928, 0, 0, 0, 0, 0, '', 'Allow Phase 15516 if Quest 59928 IS Complete');

-- Spell Area Weather Spells
DELETE FROM `spell_area` WHERE `spell` IN (305420, 305422) AND `area` = 13377;
INSERT INTO `spell_area`(`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(305420, 13377, 59926, 59928, 0, 0, 2, 3, 2 | 64, 1), -- Medium Fog + Rain
(305422, 13377, 59928, 59928, 0, 0, 2, 3, 2, 2); -- Heavy Fog + Rain

-- Queststarter & ender
DELETE FROM `creature_queststarter` WHERE `id` IN (166573, 166583) AND `quest` IN (59926, 59927, 59928);
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(166573, 59926),
(166583, 59927),
(166583, 59928);

DELETE FROM `creature_questender` WHERE `id` IN (166573, 166583, 166827) AND `quest` IN (59926, 59927, 59928);
INSERT INTO `creature_questender`(`id`, `quest`) VALUES
(166573, 59926),
(166583, 59927),
(166827, 59928);

DELETE FROM `quest_template_addon` WHERE `ID` IN (59927, 59928);
INSERT INTO `quest_template_addon`(`ID`, `PrevQuestID`) VALUES
(59927, 59926),
(59928, 59927);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (166585, 166799);

-- SAI Script & Waypoints for Provisoner Jin'hake @CGUID+12
SET @PATH := @CGUID+12 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 8.30078, 12.125, 13.3435, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 13.8032, 11.0442, 18.1657, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 16.9492, 9.31494, 18.3897, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 15.1211, 5.56055, 18.4001, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 11.6182, 2.92236, 17.9941, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7.2959, 1.16357, 17.4112, 0, 5178, 0, 0, 100, 0),
(@PATH, 6, 14.583, -4.97949, 18.3768, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 14.7632, -10.4277, 18.4486, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 11.0645, -11.5469, 16.2649, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 3.74414, -11.3711, 9.50393, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 0.431641, -11.1504, 8.98569, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -7.00732, -10.6382, 8.82762, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -14.3809, -10.0054, 8.97586, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -21.9228, -7.88721, 9.17933, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -20.043, -2.24805, 9.06756, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -21.4981, 2.65869, 9.0749, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -24.1103, 3.74219, 9.15793, 0, 4884, 0, 0, 100, 0),
(@PATH, 17, -29.5435, 7.5625, 9.8443, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -35.3257, 6.84473, 11.4777, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -41.6206, 2.96435, 11.1139, 0, 4620, 0, 0, 100, 0),
(@PATH, 20, -34.8911, 6.4458, 11.4744, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -24.8857, 7.32568, 9.19802, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -14.5552, 7.96387, 8.89298, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 2.57422, 9.37939, 9.19418, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 8.300781, `position_y`= 12.125, `position_z`= 13.34348, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+12, @PATH, 1);

DELETE FROM `smart_scripts` WHERE (`entryorguid`=-(@CGUID+12) AND `source_type`=0) OR (`entryorguid`=16679900 AND `source_type`=9);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+12), 0, 0, 0, 34, 0, 100, 0, 0, 5, 0, 0, 0, '', 80, 16679900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Provisoner Jin\'hake - On MovementInform Point 5 - start run Action List - to self'),
(-(@CGUID+12), 0, 1, 0, 34, 0, 100, 0, 0, 16, 0, 0, 0, '', 80, 16679900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Provisoner Jin\'hake - On MovementInform Point 16 - start run Action List - to self'),
(-(@CGUID+12), 0, 2, 0, 34, 0, 100, 0, 0, 19, 0, 0, 0, '', 80, 16679900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Provisoner Jin\'hake - On MovementInform Point 19 - start run Action List - to self'),
(16679900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Provisoner Jin\'hake - On Script - Set Byte 1 (8) - to Self'),
(16679900, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 0, '', 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Provisoner Jin\'hake - On Script - After 4s - Remove Byte 1 (8) - to self');

-- SAI Script & Waypoints for Bo @CGUID+13
SET @PATH := @CGUID+13 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, -12.9731, -12.1904, 8.9556, 0, 0, 0, 0, 100, 0),
(@PATH, 1, -4.01465, -12.0762, 8.91277, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 3.39355, -10.3062, 9.50703, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7.84326, -10.7778, 13.019, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 11.9995, -10.7715, 17.1649, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 15.9995, -7.54053, 18.2837, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 18.9536, -8.97021, 18.7168, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 19.0859, -11.4033, 18.8046, 0, 4983, 0, 0, 100, 0),
(@PATH, 8, 3.2060, -10.3905, 9.19429, 0,0, 0, 0, 100, 0),
(@PATH, 9, -21.6543, -10.2046, 9.19429, 0, 5141, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= -12.97314, `position_y`= -12.19043, `position_z`= 8.9556, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+13, @PATH, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+13), 16658500) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+13), 0, 0, 0, 34, 0, 100, 0, 0, 9, 0, 0, 0, '', 80, 16658500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bo - On Movementinform Point 9 - start run Action list - to self'),
(16658500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 4.1265, 'Bo - On Script - Set Orientation to target_o'),
(16658500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 1000, 1000, 0, '', 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bo - On Script - Set Byte 1 to self'),
(16658500, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 4000, 4000, 0, '', 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bo - On Script - After 4s remove Byte 1 to self');

-- research of horde ship shows that this PhaseID´s are horde only and both NPCs are in Phase 0
DELETE FROM `phase_area` WHERE `AreaId` = 10639 AND `PhaseId` IN (15286, 15284);
UPDATE `creature` SET `PhaseId`=0 WHERE `guid` IN (1050162, 1050161, 1050163);

-- Warchief Kargath Bladefist
UPDATE `creature_template` SET `unit_flags` = 33554432, `ScriptName` = 'npc_warchiefs_portal' WHERE `entry` = 17611;
DELETE FROM `creature` WHERE `id` = 17611;

DELETE FROM `waypoints` WHERE `entry` = 17621;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(17621,1,312.5911,-84.185234,1.9369955,NULL,0,'Heathen Guard'),
(17621,2,301.18335,-83.94184,1.9370384,NULL,0,'Heathen Guard'),
(17621,3,289.016,-83.993065,1.9303827,NULL,0,'Heathen Guard'),
(17621,4,279.15543,-84.08081,2.189514,NULL,0,'Heathen Guard'),
(17621,5,274.1177,-84.06761,2.3095038,NULL,0,'Heathen Guard');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17621 AND `source_type` = 0 AND `id` IN (3,4);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17622 AND `source_type` = 0 AND `id` IN (5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17623 AND `source_type` = 0 AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17621,0,3,0,54,0,100,0,0,0,0,0,0,53,1,17621,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heathen Guard - On Just Summoned - Start Waypoint"),
(17621,0,4,0,40,0,100,0,5,17621,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heathen Guard - On Waypoint 5 Reached - Set In Combat With Zone"),

(17622,0,5,0,54,0,100,0,0,0,0,0,0,53,1,17621,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sharpshooter Guard - On Just Summoned - Start Waypoint"),
(17622,0,6,0,40,0,100,0,5,17621,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sharpshooter Guard - On Waypoint 5 Reached - Set In Combat With Zone"),

(17623,0,5,0,54,0,100,0,0,0,0,0,0,53,1,17621,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reaver Guard - On Just Summoned - Start Waypoint"),
(17623,0,6,0,40,0,100,0,5,17621,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reaver Guard - On Waypoint 5 Reached - Set In Combat With Zone");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (30751,30738);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30751,0,0,31,0,3,20709,0,0,0,0,"","Group 0: Spell 'Blade Dance Charge' (Effect 0) targets creature 'Blade Dance Target'"),
(13,1,30738,0,0,31,0,3,20709,0,0,0,0,"","Group 0: Spell 'Blade Dance Targeting' (Effect 0) targets creature 'Blade Dance Target'");

DELETE FROM `creature_text` WHERE `CreatureID` = 16808 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16808,5,0,"Cowards! You'll never draw me into the shadows!",14,0,100,0,0,0,18367,0,"kargath SAY_LEASH");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 16808;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(16808,0,0,17611,336.707,-84.0521,1.99244,3.124140,8,0,"Warchief Kargath Bladefist - Group 0 - Warchief's Portal"),

(16808,0,1,17695,287.038,-88.1788,2.06635,2.443460,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin"),
(16808,0,1,17695,167.829,-86.5578,1.99496,0.890118,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin"),
(16808,0,1,17695,292.149,-82.2527,1.99739,2.932150,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin"),
(16808,0,1,17695,172.682,-80.6569,2.08346,5.427970,7,300000,"Warchief Kargath Bladefist - Group 1 - Shattered Hand Assassin");

UPDATE `creature_template_addon` SET `auras` = '19818' WHERE `entry` = 16808;

DELETE FROM `creature` WHERE `guid` IN (86464,86465,86466);
DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` IN (86464,86465,86466);

-- Warbringer O'mrogg
DELETE FROM `creature` WHERE `guid` IN (130847,130848) AND `id` IN (19523,19524);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(130847, 19523, 540, 0, 0, 3, 1, 0, 0, 374.378570556640625, 51.28566360473632812, 30.643890380859375, 0.03490658476948738, 86400, 0, 0, 74, 0, 0, 0, 0, 0, 14007),
(130848, 19524, 540, 0, 0, 3, 1, 0, 0, 374.356475830078125, 64.50481414794921875, 31.22058868408203125, 6.0737457275390625, 86400, 0, 0, 74, 0, 0, 0, 0, 0, 14007);

UPDATE `creature_template` SET `flags_extra` = `flags_extra`|128 WHERE `entry` IN (19523,19524,20572,20573);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=16809 AND `ID`=2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(16809, 2, 29479, 0, 0, 61967);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (19523,19524,20572,20573);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(19523,1,1,1,1,0,0,NULL),
(20572,1,1,1,1,0,0,NULL),
(19524,1,1,1,1,0,0,NULL),
(20573,1,1,1,1,0,0,NULL);

DELETE FROM `creature_text` WHERE `CreatureID` IN (19523,19524,16809);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16809,0,0,"%s roars!",16,0,100,0,0,0,14029,0,"omrogg EMOTE_ROAR"),

-- Smash! 15:26:08.000 -- Why don't you let me do the talking? 15:26:11.000 -- Hey! 15:26:14.000
-- https://youtu.be/9aHROEXiVSA?t=1548
/* L */ (19523,0,0,"Smash!",                                                    14,0,100,0,0,10306,14046,0,"omrogg SAY_AGGRO_1"),
/* R */ (19524,0,0,"Why don't you let me do the talking?",                      14,0,100,0,0,10317,14047,0,"omrogg SAY_AGGRO_1_1"),
/* L */ (19523,1,0,"Hey!",                                                      14,0,100,0,0,10307,16917,0,"omrogg SAY_AGGRO_1_2"),

-- https://youtu.be/cmZMZFc09oM?t=26
/* L */ (19523,2,0,"If you nice me let you live.",                              14,0,100,0,0,10308,14048,0,"omrogg SAY_AGGRO_2"),
/* R */ (19524,1,0,"No, we will NOT let you live.",                             14,0,100,0,0,10318,16916,0,"omrogg SAY_AGGRO_2_1"),

-- https://youtu.be/c7anPGIo9pA?t=5
/* L */ (19523,3,0,"Me hungry.",                                                14,0,100,0,0,10309,16918,0,"omrogg SAY_AGGRO_3"),
/* R */ (19524,2,0,"You're always hungry.  That's why we so fat!",              14,0,100,0,0,10319,16919,0,"omrogg SAY_AGGRO_3_1"),

-- Me not like this one... 15:26:36.000 -- Hey, you numbskull! 15:26:39.000 -- We kill his friend! 15:26:41.000
-- https://youtu.be/FfjIPe1F7v4?t=1810
/* L */ (19523,4,0,"Me not like this one...",                                   14,0,100,0,0,10300,14043,0,"omrogg SAY_ATTACK_1"),
/* R */ (19524,3,0,"Hey, you numbskull!",                                       14,0,100,0,0,10312,14044,0,"omrogg SAY_ATTACK_1_1"),
/* L */ (19523,5,0,"We kill his friend!",                                       14,0,100,0,0,10301,14045,0,"omrogg SAY_ATTACK_1_2"),

-- https://youtu.be/H4hvmeYjIYI?t=3130
/* L */ (19523,6,0,"We kill someone else!",                                     14,0,100,0,0,10302,16895,0,"omrogg SAY_ATTACK_2"),
/* R */ (19524,4,0,"I'm not done yet, idiot!",                                  14,0,100,0,0,10313,16896,0,"omrogg SAY_ATTACK_2_1"),

-- https://youtu.be/H4hvmeYjIYI?t=3197
/* L */ (19523,7,0,"You stay here.  Me go kill someone else!",                  14,0,100,0,0,10303,16898,0,"omrogg SAY_ATTACK_3"),
/* R */ (19524,5,0,"That's not funny!",                                         14,0,100,0,0,10314,16899,0,"omrogg SAY_ATTACK_3_1"),
/* L */ (19523,8,0,"Ha ha ha.",                                                 14,0,100,0,0,10304,16900,0,"omrogg SAY_ATTACK_3_2"),

-- https://youtu.be/0phkTyrfzpo?t=484
/* R */ (19524,6,0,"What are you doing?",                                       14,0,100,0,0,10315,16901,0,"omrogg SAY_ATTACK_4"),
/* L */ (19523,9,0,"Me get bored.",                                             14,0,100,0,0,10305,16902,0,"omrogg SAY_ATTACK_4_1"),
/* R */ (19524,7,0,"Bored? He was almost dead!",                                14,0,100,0,0,10316,16903,0,"omrogg SAY_ATTACK_4_2"),

-- https://wowpedia.fandom.com/wiki/Warbringer_O%27mrogg
/* R */ (19524,8,0,"I'm tired.  You kill next one!",                            14,0,100,0,0,10320,16921,0,"omrogg SAY_SLAY_1"),

-- https://wowpedia.fandom.com/wiki/Warbringer_O%27mrogg
/* L */ (19523,10,0,"This one die easy!",                                       14,0,100,0,0,10310,16922,0,"omrogg SAY_SLAY_2"),
/* R */ (19524,9,0,"That's because I do all the hard work!",                    14,0,100,0,0,10321,16923,0,"omrogg SAY_SLAY_2_1"),

-- This all... your fault! 15:26:57.000 -- I... hate... you. 15:27:00.000
-- https://youtu.be/FfjIPe1F7v4?t=1830
/* L */ (19523,11,0,"This all... your fault!",                                  14,0,100,0,0,10311,16924,0,"omrogg SAY_DEATH_1"),
/* R */ (19524,10,0,"I... hate... you.",                                        14,0,100,0,0,10322,16925,0,"omrogg SAY_DEATH_1_1");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_omrogg_burning_maul';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30598, 'spell_omrogg_burning_maul'),
(36056, 'spell_omrogg_burning_maul');

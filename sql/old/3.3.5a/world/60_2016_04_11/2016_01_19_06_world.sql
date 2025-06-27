-- gothik the harvester rework
-- creature (13 entries)
SET @CGUID = 127618; -- PR NOTE: This needs to match the value set in boss_gothik.cpp for the CGUID_TRIGGER const

-- boss messages
DELETE FROM `creature_text` WHERE `entry`=16060;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(16060,0,0,"Foolishly you have sought your own demise.",14,100,8807,13030,3,"Gothik SAY_INTRO_1"),
(16060,1,0,"Brazenly you have disregarded powers beyond your understanding.",14,100,0,13031,3,"Gothik SAY_INTRO_2"),
(16060,2,0,"You have fought hard to invade the realm of the harvester.",14,100,0,13032,3,"Gothik SAY_INTRO_3"),
(16060,3,0,"Now there is only one way out- to walk the lonely path of the damned.",14,100,0,13033,3,"Gothik SAY_INTRO_4"),
(16060,4,0,"I have waited long enough. Now you face the harvester of souls.",14,100,8808,13028,3,"Gothik SAY_PHASE_TWO"),
(16060,5,0,"I... am... undone.",14,100,8805,13026,3,"Gothik SAY_DEATH"),
(16060,6,0,"Death is the only escape!",14,20,8806,13027,3,"Gothik SAY_KILL"),
(16060,7,0,"%s teleports into the fray!",41,100,0,32306,3,"Gothik EMOTE_PHASE_TWO"),
(16060,8,0,"The central gate opens!",41,100,0,32307,3,"Gothik EMOTE_GATE_OPENED");

-- minion AI
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_livingtrainee" WHERE `entry`=16124;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_livingknight" WHERE `entry`=16125;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_livingrider" WHERE `entry`=16126;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectraltrainee" WHERE `entry`=16127;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectralknight" WHERE `entry`=16148;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectralrider" WHERE `entry`=16150;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectralhorse" WHERE `entry`=16149;

-- minion difficulty spell entries
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (55604,27825,27831,27989,56408,27993,55606,27994,55648);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(55604,55604,55645), -- death plague
(27831,27831,55638), -- shadow bolt volley
(27989,27989,56407), -- arcane explosion
(55606,55606,55608), -- unholy aura
(27994,27994,55646), -- drain life
(55648,55648,27995); -- unholy frenzy

-- rider damage aura + visual aura
DELETE FROM `creature_template_addon` WHERE `entry` IN (16126,29986,16148,29990,16150,29988);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`auras`) VALUES
(16126,25278,"55606"),
(29986,25278,"55608"),
(16148,    0,"10848"),
(29990,    0,"10848"),
(16150,    0,"55606 10848"),
(29988,    0,"55608 10848");

-- trigger AI
UPDATE `creature_template` SET `ScriptName`="npc_gothik_trigger",`InhabitType`=7 WHERE `entry`=16137;
-- re-do spawn locations for triggers
DELETE FROM `creature` WHERE `id`=16137;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`) VALUES
(@CGUID+00,16137,533,3,1,2643.731,-3399.681,284.1829,0,0,0,0), -- living   side soul  trigger (south)
(@CGUID+01,16137,533,3,1,2739.995,-3399.779,284.2946,0,0,0,0), -- living   side soul  trigger (north)
(@CGUID+02,16137,533,3,1,2643.731,-3321.727,284.2327,0,0,0,0), -- spectral side soul  trigger (south)
(@CGUID+03,16137,533,3,1,2739.995,-3321.727,284.2316,0,0,0,0), -- spectral side soul  trigger (north)
(@CGUID+04,16137,533,3,1,2692.161,-3430.746,268.6462,0,0,0,0), -- living   side spawn trigger (center back)
(@CGUID+05,16137,533,3,1,2714.562,-3430.61 ,268.6462,0,0,0,0), -- living   side spawn trigger (north)
(@CGUID+06,16137,533,3,1,2692.213,-3428.783,268.6462,0,0,0,0), -- living   side spawn trigger (center front)
(@CGUID+07,16137,533,3,1,2669.581,-3428.859,268.6462,0,0,0,0), -- living   side spawn trigger (south)
(@CGUID+08,16137,533,3,1,2733.457,-3349.388,267.7677,0,0,0,0), -- spectral side spawn trigger (northeast)
(@CGUID+09,16137,533,3,1,2725.818,-3309.567,267.7686,0,0,0,0), -- spectral side spawn trigger (northwest)
(@CGUID+10,16137,533,3,1,2700.269,-3322.354,267.7678,0,0,0,0), -- spectral side spawn trigger (center)
(@CGUID+11,16137,533,3,1,2664.872,-3340.749,267.7674,0,0,0,0), -- spectral side spawn trigger (southeast)
(@CGUID+12,16137,533,3,1,2683.886,-3304.213,267.768 ,0,0,0,0); -- spectral side spawn trigger (southwest)

-- make visuals target proper triggers
-- to anchor 1: 27892 (Trainee), 27928 (DK), 27935 (Rider)
-- to anchor 2: 27893 (Trainee), 27929 (DK), 27936 (Rider)
-- anchor -> skull: 27915 (Trainee), 27931 (DK), 27937 (Rider)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (27892,27928,27935,27893,27929,27936,27915,27931,27937);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ElseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(13,1,27892,31,0,0,3,16137,@CGUID+0,"To Anchor 1 - Target Anchor Living South"),
(13,1,27892,31,0,1,3,16137,@CGUID+1,"To Anchor 1 - Target Anchor Living North"),
(13,1,27928,31,0,0,3,16137,@CGUID+0,"To Anchor 1 - Target Anchor Living South"),
(13,1,27928,31,0,1,3,16137,@CGUID+1,"To Anchor 1 - Target Anchor Living North"),
(13,1,27935,31,0,0,3,16137,@CGUID+0,"To Anchor 1 - Target Anchor Living South"),
(13,1,27935,31,0,1,3,16137,@CGUID+1,"To Anchor 1 - Target Anchor Living North"),

(13,1,27893,31,0,0,3,16137,@CGUID+2,"To Anchor 2 - Target Anchor Spectral South"),
(13,1,27893,31,0,1,3,16137,@CGUID+3,"To Anchor 2 - Target Anchor Spectral North"),
(13,1,27929,31,0,0,3,16137,@CGUID+2,"To Anchor 2 - Target Anchor Spectral South"),
(13,1,27929,31,0,1,3,16137,@CGUID+3,"To Anchor 2 - Target Anchor Spectral North"),
(13,1,27936,31,0,0,3,16137,@CGUID+2,"To Anchor 2 - Target Anchor Spectral South"),
(13,1,27936,31,0,1,3,16137,@CGUID+3,"To Anchor 2 - Target Anchor Spectral North");

-- disable LoS check for visuals to ensure they always work
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (27892,27928,27935,27893,27929,27936,27915,27931,27937);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,27892,64,"Gothik - To Anchor 1 - Ignore LoS"),
(0,27928,64,"Gothik - To Anchor 1 - Ignore LoS"),
(0,27935,64,"Gothik - To Anchor 1 - Ignore LoS"),
(0,27893,64,"Gothik - To Anchor 2 - Ignore LoS"),
(0,27929,64,"Gothik - To Anchor 2 - Ignore LoS"),
(0,27936,64,"Gothik - To Anchor 2 - Ignore LoS"),
(0,27915,64,"Gothik - Anchor To Skulls - Ignore LoS"),
(0,27931,64,"Gothik - Anchor To Skulls - Ignore LoS"),
(0,27937,64,"Gothik - Anchor To Skulls - Ignore LoS");

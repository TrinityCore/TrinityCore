DELETE FROM `script_texts` WHERE `entry` BETWEEN -1603019 AND -1603000;
UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName` IN ('boss_algalon','mob_collapsing_star');

-- Difficulty linking
UPDATE `creature_template` SET `difficulty_entry_1`=34296 WHERE `entry`=32953; -- Black Hole

UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`faction_A`=35,`faction_H`=35,`unit_flags`=0x8300,`equipment_id`=2478 WHERE `entry`=34064; -- Brann Bronzebeard
UPDATE `creature_template` SET `speed_walk`=4,`speed_run`=2.14286,`exp`=2,`minlevel`=83,`maxlevel`=83,`faction_A`=190,`faction_H`=190,`unit_flags`=0x8100,`BaseAttackTime`=1000,`equipment_id`=2479 WHERE `entry` IN (32871,33070); -- Algalon the Observer
UPDATE `creature_template` SET `faction_A`=190,`faction_H`=190,`exp`=2,`minlevel`=83,`maxlevel`=83,`unit_flags`=0x2000000,`speed_run`=1,`InhabitType`=4 WHERE `entry`=34246; -- Azeroth
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`minlevel`=74,`maxlevel`=74,`unit_flags`=0x2000000,`flags_extra`=0x80,`InhabitType`=4 WHERE `entry`=33086; -- Algalon Stalker
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`unit_flags`=0x2008000,`speed_run`=1,`equipment_id`=2480,`InhabitType`=4 WHERE `entry` IN (33052,33116); -- Living Constellation
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`speed_run`=1,`RegenHealth`=0 WHERE `entry` IN (32955,34215); -- Collapsing Star
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=0x2000000,`speed_run`=1,`InhabitType`=4 WHERE `entry` IN (32953,34296); -- Black Hole
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`minlevel`=81,`maxlevel`=81,`unit_flags`=0x8000,`speed_walk`=4,`speed_run`=1.42857,`InhabitType`=4 WHERE `entry` IN(33089,34097,34221,34222); -- Dark Matter
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`unit_flags`=0x2000000,`flags_extra`=0x80 WHERE `entry`=34100; -- Algalon Void Zone Visual Stalker
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`unit_flags`=0x2000000,`speed_run`=1,`InhabitType`=4 WHERE `entry`=34099; -- Worm Hole
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`minlevel`=74,`maxlevel`=74,`unit_flags`=0x2000000,`flags_extra`=0x80,`InhabitType`=4 WHERE `entry`=33104; -- Algalon Stalker Asteroid Target 01
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`minlevel`=74,`maxlevel`=74,`unit_flags`=0x2000000,`flags_extra`=0x80,`InhabitType`=4 WHERE `entry`=33105; -- Algalon Stalker Asteroid Target 02

UPDATE `creature_model_info` SET `bounding_radius`=0.93,`combat_reach`=9,`gender`=0 WHERE `modelid`=28641; -- Algalon the Observer
UPDATE `creature_model_info` SET `bounding_radius`=0.02,`combat_reach`=0.2,`gender`=2 WHERE `modelid`=29133; -- Azeroth
UPDATE `creature_model_info` SET `bounding_radius`=0.62,`combat_reach`=0,`gender`=2 WHERE `modelid`=28741; -- Living Constellation
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=28988; -- Collapsing Star
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=28460; -- Black Hole

UPDATE `gameobject_template` SET `faction`=114,`flags`=32 WHERE `entry`=194910; -- Doodad_UL_SigilDoor_03
UPDATE `gameobject_template` SET `data0`=579 WHERE `entry`=194628; -- Celestial Planetarium Access

UPDATE `creature_template` SET `ScriptName`='boss_algalon_the_observer' WHERE `entry`=32871; -- Algalon the Observer
UPDATE `creature_template` SET `ScriptName`='npc_living_constellation' WHERE `entry`=33052; -- Living Constellation
UPDATE `creature_template` SET `ScriptName`='npc_collapsing_star' WHERE `entry`=32955; -- Collapsing Star
UPDATE `creature_template` SET `ScriptName`='npc_brann_bronzebeard_algalon' WHERE `entry`=34064; -- Brann Bronzebeard
UPDATE `gameobject_template` SET `ScriptName`='go_celestial_planetarium_access' WHERE `entry` IN (194628,194752); -- Celestial Planetarium Access
UPDATE `creature_template` SET `AIName`='NullCreatureAI' WHERE `entry` IN (32953,34099); -- Black Hole

DELETE FROM `creature` WHERE `guid` IN (41781,41783,41790,41811,41812,41814,41819,41820,41821,41822,41823,41875);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(41781,33086,603,3,1,1627.400,-339.4133,417.4044,1.378810,7200,0,0), -- Algalon Stalker
(41783,33086,603,3,1,1622.681,-344.2576,417.3955,1.378810,7200,0,0), -- Algalon Stalker
(41790,33086,603,3,1,1629.984,-271.4798,417.4045,4.782202,7200,0,0), -- Algalon Stalker
(41811,33086,603,3,1,1630.005,-345.5189,417.3955,1.378810,7200,0,0), -- Algalon Stalker
(41812,33089,603,3,16,1622.451,-321.1563,417.6188,4.677482,7200,20,1), -- Dark Matter
(41814,33089,603,3,16,1649.438,-319.8127,418.3941,1.082104,7200,20,1), -- Dark Matter
(41819,33089,603,3,16,1615.060,-291.6816,417.7796,3.490659,7200,20,1), -- Dark Matter
(41820,33089,603,3,16,1647.005,-288.6790,417.3955,3.490659,7200,20,1), -- Dark Matter
(41821,33089,603,3,16,1622.451,-321.1563,417.6188,4.677482,7200,20,1), -- Dark Matter
(41822,33089,603,3,16,1649.438,-319.8127,418.3941,1.082104,7200,20,1), -- Dark Matter
(41823,33089,603,3,16,1615.060,-291.6816,417.7796,3.490659,7200,20,1), -- Dark Matter
(41875,33089,603,3,16,1647.005,-288.6790,417.3955,3.490659,7200,20,1); -- Dark Matter

SET @OGUID := 252;
DELETE FROM `gameobject` WHERE `id` IN (194767,194910,194911,194715,194716,194148,194253,194628,194752,194821,194822);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+00,194767,603,3,17,1632.024,-182.9211,427.6681,0.000000,0,0,8.742278E-08,1, 604800,255,1), -- Doodad_UL_SigilDoor_01
(@OGUID+04,194911,603,3,17,1632.024,-182.9211,408.4224,3.141593,0,0,8.742278E-08,1, 604800,255,1), -- Doodad_UL_SigilDoor_02
(@OGUID+10,194910,603,3,17,1632.053,-266.1495,438.5608,0.000000,0,0,8.742278E-08,1, 604800,255,0), -- Doodad_UL_SigilDoor_03
(@OGUID+12,194715,603,3,17,1632.053,-307.6541,417.3211,0.000000,0,0,8.742278E-08,1, 604800,255,0), -- Doodad_UL_UniverseFloor_01
(@OGUID+19,194716,603,3,17,1632.251,-307.5483,416.2641,0.000000,0,0,8.742278E-08,1, 604800,255,1), -- Doodad_UL_UniverseFloor_02
(@OGUID+22,194148,603,3,17,1632.053,-307.6541,417.3211,0.000000,0,0,8.742278E-08,1, 604800,255,1), -- Doodad_UL_UniverseGlobe01
(@OGUID+24,194253,603,3,17,1631.908,-246.4970,417.3211,0.000000,0,0,8.742278E-08,1, 604800,255,1), -- Doodad_UL_Ulduar_Trapdoor_03
(@OGUID+29,194628,603,1, 1,1646.182,-174.6881,427.2536,1.553341,0,0,0.000000E-00,1, 604800,255,1), -- Celestial Planetarium Access
(@OGUID+33,194752,603,2, 1,1646.182,-174.6881,427.2536,1.553341,0,0,0.000000E-00,1, 604800,255,1), -- Celestial Planetarium Access
(@OGUID+37,194821,603,1, 1,1632.099,-306.5609,417.3210,4.694937,0,0,0.000000E-00,1,-604800,255,1), -- Gift of the Observer (10 man)
(@OGUID+46,194822,603,2, 1,1632.099,-306.5609,417.3210,4.694937,0,0,0.000000E-00,1,-604800,255,1); -- Gift of the Observer (25 man)

DELETE FROM `creature_equip_template` WHERE `entry` IN (2478,2479,2480);
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(2478,1903,25972,0),
(2479,45985,45985,0),
(2480,44952,0,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (32871,33070,33052,33116,33089,34221,34097,34222,33105);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(32871,0,0x0000000,0x0,NULL), -- Algalon the Observer
(33070,0,0x0000000,0x0,NULL), -- Algalon the Observer
(33052,0,0x3000000,0x1,NULL), -- Living Constellation
(33116,0,0x3000000,0x1,NULL), -- Living Constellation
(33089,0,0x3000000,0x1,NULL), -- Dark Matter
(34221,0,0x3000000,0x1,NULL), -- Dark Matter
(34097,0,0x3000000,0x1,NULL), -- Unleashed Dark Matter
(34222,0,0x3000000,0x1,NULL), -- Unleashed Dark Matter
(33105,0,0x3000000,0x1,NULL); -- Algalon Stalker Asteroid Target 02

DELETE FROM `creature_text` WHERE `entry` IN (32871,34064);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`emote`,`comment`) VALUES
(34064,0,0,'We did it, lads! We got here before Algalon''s arrival. Maybe we can rig the systems to interfere with his analysis--',14,15824,0,'Brann Bronzebeard - SAY_BRANN_ALGALON_INTRO_1'),
(34064,1,0,'I''ll head back to the Archivum and see if I can jam his signal. I might be able to buy us some time while you take care of him.',12,15825,0,'Brann Bronzebeard - SAY_BRANN_ALGALON_INTRO_2'),
(34064,2,0,'I know just the place. Will you be all right?',14,15823,6,'Brann Bronzebeard - SAY_BRANN_ALGALON_OUTRO'),
(32871,0,0,'Translocation complete. Commencing planetary analysis of Azeroth.',12,15405,0,'Algalon the Observer - SAY_ALGALON_INTRO_1'),
(32871,1,0,'Stand back, mortals. I''m not here to fight you.',12,15406,0,'Algalon the Observer - SAY_ALGALON_INTRO_2'),
(32871,2,0,'It is in the universe''s best interest to re-originate this planet should my analysis find systemic corruption. Do not interfere.',12,15407,0,'Algalon the Observer - SAY_ALGALON_INTRO_3'),
(32871,3,0,'Your actions are illogical. All possible results for this encounter have been calculated. The Pantheon will receive the Observer''s message regardless of outcome.',14,15386,0,'Algalon the Observer - SAY_ALGALON_START_TIMER'),
(32871,4,0,'See your world through my eyes: A universe so vast as to be immeasurable - incomprehensible even to your greatest minds.',14,15390,1,'Algalon the Observer - SAY_ALGALON_AGGRO'),
(32871,5,0,'The stars come to my aid!',14,15392,0,'Algalon the Observer - SAY_ALGALON_COLLAPSING_STAR'),
(32871,6,0,'%s begins to Summon Collapsing Stars!',41,0,0,'Algalon the Observer - EMOTE_ALGALON_COLLAPSING_STAR'),
(32871,7,0,'Witness the fury of the cosmos!',14,15396,0,'Algalon the Observer - SAY_ALGALONG_BIG_BANG'),
(32871,8,0,'%s begins to cast Big Bang!',41,0,0,'Algalon the Observer - EMOTE_ALGALON_BIG_BANG'),
(32871,9,0,'You are out of time.',14,15394,0,'Algalon the Observer - SAY_ALGALON_ASCEND'),
(32871,10,0,'%s begins to cast Cosmic Smash!',41,0,0,'Algalon the Observer - EMOTE_ALGALON_COSMIC_SMASH'),
(32871,11,0,'Behold the tools of creation!',14,15397,0,'Algalon the Observer - SAY_ALGALON_PHASE_TWO'),
(32871,12,0,'I have seen worlds bathed in the Makers'' flames, their denizens fading without as much as a whimper. Entire planetary systems born and razed in the time that it takes your mortal hearts to beat once. Yet all throughout, my own heart devoid of emotion... of empathy. I. Have. Felt. Nothing. A million-million lives wasted. Had they all held within them your tenacity? Had they all loved life as you do?',14,15393,1,'Algalon the Observer - SAY_ALGALON_OUTRO_1'),
(32871,13,0,'Perhaps it is your imperfections... that which grants you free will... that allows you to persevere against all cosmically calculated odds. You prevail where the Titan''s own perfect creations have failed.',14,15401,1,'Algalon the Observer - SAY_ALGALON_OUTRO_2'),
(32871,14,0,'I''ve rearranged the reply code - your planet will be spared. I cannot be certain of my own calculations anymore.',14,15402,1,'Algalon the Observer - SAY_ALGALON_OUTRO_3'),
(32871,15,0,'I lack the strength to transmit the signal. You must... hurry... find a place of power... close to the skies.',14,15403,1,'Algalon the Observer - SAY_ALGALON_OUTRO_4'),
(32871,16,0,'Do not worry about my fate, Bronzen. If the signal is not transmitted in time, re-origination will proceed regardless. Save... your world...',14,15404,1,'Algalon the Observer - SAY_ALGALON_OUTRO_5'),
(32871,17,0,'Analysis complete. There is partial corruption in the planet''s life-support systems as well as complete corruption in most of the planet''s defense mechanisms.',12,15398,0,'Algalon the Observer - SAY_ALGALON_DESPAWN_1'),
(32871,18,0,'Begin uplink: Reply Code: ''Omega''. Planetary re-origination requested.',12,15399,0,'Algalon the Observer - SAY_ALGALON_DESPAWN_2'),
(32871,19,0,'Farewell, mortals. Your bravery is admirable, for such flawed creatures.',12,15400,0,'Algalon the Observer - SAY_ALGALON_DESPAWN_3'),
(32871,20,0,'Loss of life unavoidable.',14,15387,0,'Algalon the Observer - SAY_ALGALON_KILL'),
(32871,20,1,'I do what I must.',14,15388,0,'Algalon the Observer - SAY_ALGALON_KILL');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (64996,62266,65509,62304,64597);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,1,64996,31,3,34246,'Algalon the Observer - Reorigination on Azeroth'),
(13,1,62266,31,3,33052,'Algalon Stalker - target Living Constellation'),
(13,1,65509,31,3,33052,'Black Hole - target Living Constellation'),
(13,1,62304,31,3,33104,'Cosmic Smash - target trigger'),
(13,1,64597,31,3,33104,'Cosmic Smash - target trigger');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_phase_punch';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_arcane_barrage';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_trigger_3_adds';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_collapse';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_big_bang';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_remove_phase';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_cosmic_smash';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_cosmic_smash_damage';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_algalon_supermassive_fail';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64412,'spell_algalon_phase_punch'),
(64599,'spell_algalon_arcane_barrage'),
(64607,'spell_algalon_arcane_barrage'),
(62266,'spell_algalon_trigger_3_adds'),
(62018,'spell_algalon_collapse'),
(64443,'spell_algalon_big_bang'),
(64584,'spell_algalon_big_bang'),
(64445,'spell_algalon_remove_phase'),
(62295,'spell_algalon_cosmic_smash'),
(62311,'spell_algalon_cosmic_smash_damage'),
(64596,'spell_algalon_cosmic_smash_damage'),
(65311,'spell_algalon_supermassive_fail');

SET @DIFF_ID := 3262;
DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN @DIFF_ID AND @DIFF_ID+5;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(@DIFF_ID+0,64395,64592),
(@DIFF_ID+1,64599,64607),
(@DIFF_ID+2,64443,64584),
(@DIFF_ID+3,64122,65108),
(@DIFF_ID+4,62301,64598),
(@DIFF_ID+5,62304,64597);

UPDATE `instance_encounters` SET `creditType`=1,`creditEntry`=65184 WHERE `entry` IN (757,771); -- Algalon the Observer

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10565,10566,10678,9990,9991,10567,10569,10698,10780,10781,10782,10783,10568,10570);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10565,10566,10678,9990,9991,10567,10569,10698,10780,10781,10782,10783,10568,10570);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10565,12,0,0,''), -- Algalon the Observer kills (Ulduar 10 player)
(10566,12,1,0,''), -- Algalon the Observer kills (Ulduar 25 player)
(10678,12,0,0,''), -- Herald of the Titans
(10678,18,0,0,''), -- Herald of the Titans
(9990,12,0,0,''), -- Lich King 10-player bosses killed
(9991,12,1,0,''), -- Lich King 25-player bosses killed
(10567,12,0,0,''), -- Observed (10 player)
(10569,12,1,0,''), -- Observed (25 player)
(10698,12,1,0,''), -- Realm First! Celestial Defender
(10780,12,0,0,''), -- Supermassive (10 player)
(10781,12,0,0,''), -- Supermassive (10 player)
(10782,12,1,0,''), -- Supermassive (25 player)
(10783,12,1,0,''), -- Supermassive (25 player)
(10568,11,0,0,'achievement_he_feeds_on_your_tears'), -- He Feeds On Your Tears (10 player)
(10568,12,0,0,''), -- He Feeds On Your Tears (10 player)
(10570,11,0,0,'achievement_he_feeds_on_your_tears'), -- He Feeds On Your Tears (25 player)
(10570,12,1,0,''); -- He Feeds On Your Tears (25 player)

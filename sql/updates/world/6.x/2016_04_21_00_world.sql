-- Gate of the Setting Sun
UPDATE instance_template SET script='instance_gate_setting_sun' WHERE map=962;
UPDATE creature_template SET ScriptName='npc_serpent_spine_defender' WHERE entry=58146;
UPDATE creature_template SET ScriptName='npc_krikthik_bombarder' WHERE entry=56706;
UPDATE gameobject_template SET ScriptName='at_first_door' WHERE entry=8359;
UPDATE gameobject_template SET ScriptName='go_setting_sun_brasier' WHERE entry=213507;
INSERT INTO gamobject_template (entry,ScriptName) VALUES (400001,'go_setting_sun_temp_portal');
INSERT INTO gamobject_template (entry,ScriptName) VALUES (400002,'go_setting_sun_temp_portal');
UPDATE creature_template SET ScriptName='vehicle_artillery_to_wall' WHERE entry=66904;
INSERT INTO areatrigger_scripts values (8359,'at_first_door');
-- Rimok
UPDATE creature_template SET ScriptName='boss_commander_rimok' WHERE entry=56636;
UPDATE creature_template SET ScriptName='npc_krikthik_swarmer' WHERE entry=59835;
UPDATE creature_template SET ScriptName='npc_krikthik_saboteur' WHERE entry=60447;
UPDATE creature_template SET ScriptName='npc_add_generator' WHERE entry=59834;
INSERT INTO spell_script_names (spell_id,ScriptName) values (120559,'spell_rimok_saboteur_bombard');
-- Raigonn
UPDATE creature_template SET ScriptName='boss_raigonn' WHERE entry=56877;
UPDATE creature_template SET ScriptName='npc_raigonn_weak_spot' WHERE entry=56895;
UPDATE creature_template SET ScriptName='npc_krikthik_protectorat' WHERE entry=56929;
UPDATE creature_template SET ScriptName='npc_krikthik_engulfer' WHERE entry=56912;
UPDATE creature_template SET ScriptName='npc_krikthik_swarm_bringer' WHERE entry=56930;
UPDATE creature_template SET ScriptName='vehicle_artillery' WHERE entry=59819;
-- Kiptilak
UPDATE creature_template SET ScriptName='boss_saboteur_kiptilak' WHERE entry=56906;
UPDATE creature_template SET ScriptName='npc_instable_munition' WHERE entry=56917;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56911;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56918;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56919;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=56920;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59205;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59206;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59207;
UPDATE creature_template SET ScriptName='npc_munition_explosion_bunny' WHERE entry=59208;
INSERT INTO spell_script_names (spell_id,ScriptName) values (107268,'spell_kiptilak_sabotage');
-- Gadok
UPDATE creature_template SET ScriptName='boss_striker_gadok' WHERE entry=56589;
UPDATE creature_template SET ScriptName='npc_krikthik_striker' WHERE entry=59778;
UPDATE creature_template SET ScriptName='npc_krikthik_disruptor' WHERE entry=59794;
UPDATE creature_template SET ScriptName='npc_flak_cannon' WHERE entry=60421;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116298,'spell_gadok_strafing');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106933,'spell_prey_time');
-- Spawns
SET @CGUID := 9002627;
SET @OGUID := 9001495;

DELETE FROM creature WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+866;
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 63973, 870, 0, 0, 1, 0,0, 0, 0, 801.9918, 2220.898, 418.9878, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+1, 63973, 870, 0, 0, 1, 0,0, 0, 0, 710.5352, 2243.503, 465.3316, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+2, 63973, 870, 0, 0, 1, 0,0, 0, 0, 694.6005, 2257.75, 456.7957, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+3, 63973, 870, 0, 0, 1, 0,0, 0, 0, 633.7285, 2262.25, 455.2311, 5.182938, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+4, 63973, 870, 0, 0, 1, 0,0, 0, 0, 728.2323, 2260.846, 477.3626, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+5, 63973, 870, 0, 0, 1, 0,0, 0, 0, 811.5815, 2239.021, 403.6077, 4.781409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+6, 63973, 870, 0, 0, 1, 0,0, 0, 0, 841.8303, 2195.021, 399.1599, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+7, 63973, 870, 0, 0, 1, 0,0, 0, 0, 779.6903, 2260.385, 454.3055, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+8, 63973, 870, 0, 0, 1, 0,0, 0, 0, 731.2462, 2252.142, 477.3641, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+9, 63973, 870, 0, 0, 1, 0,0, 0, 0, 845.6812, 2194.041, 399.5006, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+10, 63973, 870, 0, 0, 1, 0,0, 0, 0, 809.4796, 2230.474, 403.2515, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+11, 63973, 870, 0, 0, 1, 0,0, 0, 0, 695.6012, 2274.006, 462.0834, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+12, 63973, 870, 0, 0, 1, 0,0, 0, 0, 804.6012, 2233.083, 403.2577, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+13, 63973, 870, 0, 0, 1, 0,0, 0, 0, 825.4819, 2211.849, 401.3613, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+14, 63973, 870, 0, 0, 1, 0,0, 0, 0, 705.4828, 2242.829, 467.6496, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+15, 63973, 870, 0, 0, 1, 0,0, 0, 0, 814.412, 2235.139, 420.5798, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+16, 63973, 870, 0, 0, 1, 0,0, 0, 0, 789.5231, 2227.183, 448.3854, 3.771488, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+17, 63973, 870, 0, 0, 1, 0,0, 0, 0, 765.8951, 2254.982, 477.6983, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+18, 63973, 870, 0, 0, 1, 0,0, 0, 0, 690.7145, 2262.118, 456.4814, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+19, 63973, 870, 0, 0, 1, 0,0, 0, 0, 819.7767, 2230.286, 403.2626, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: -Unknown-)
(@CGUID+20, 56890, 962, 0, 0, 3, 0,0, 0, 0, 722.1784, 2139.882, 401.2762, 6.229497, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+21, 65337, 962, 0, 0, 3, 0,0, 0, 0, 719.6649, 2265.719, 388.054, 4.668733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+22, 56890, 962, 0, 0, 3, 0,0, 0, 0, 727.7535, 2191.326, 387.5984, 4.849447, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+23, 56889, 962, 0, 0, 3, 0,0, 0, 0, 727.4496, 2196.792, 386.1543, 4.840083, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+24, 56890, 962, 0, 0, 3, 0,0, 0, 0, 715.4496, 2191.691, 387.5021, 4.639258, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+25, 58824, 962, 0, 0, 3, 0,0, 0, 0, 838.6337, 2225.828, 354.665, 0.7679449, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+26, 65337, 962, 0, 0, 3, 0,0, 0, 0, 720.6754, 2263.826, 388.1197, 4.668733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+27, 58824, 962, 0, 0, 3, 0,0, 0, 0, 884.9358, 2204.432, 354.6621, 1.099557, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+28, 64467, 962, 0, 0, 3, 0,0, 0, 0, 715.8715, 2113.328, 403.3548, 1.309397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Bowmistress Li (Area: Gate of the Setting Sun) (Auras: 120856 - Pandaren Arrows 01 Stack)
(@CGUID+29, 58824, 962, 0, 0, 3, 0,0, 0, 0, 838.4705, 2235.337, 354.6557, 0.7330383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+30, 65337, 962, 0, 0, 3, 0,0, 0, 0, 723.007, 2265.686, 388.0705, 4.668733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+31, 58824, 962, 0, 0, 3, 0,0, 0, 0, 838.1962, 2254.889, 354.6598, 0.6283185, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+32, 58824, 962, 0, 0, 3, 0,0, 0, 0, 838.3594, 2245.38, 354.6501, 0.6806784, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+33, 58824, 962, 0, 0, 3, 0,0, 0, 0, 851.0799, 2204.273, 354.5946, 0.9075712, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+34, 65111, 962, 0, 0, 3, 0,0, 0, 0, 725.8264, 2139.686, 401.5892, 3.19946, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+35, 65337, 962, 0, 0, 3, 0,0, 0, 0, 724.3073, 2263.873, 388.1285, 4.668733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+36, 58824, 962, 0, 0, 3, 0,0, 0, 0, 865.3281, 2204.167, 354.6479, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+37, 58824, 962, 0, 0, 3, 0,0, 0, 0, 856.0833, 2204.26, 354.5682, 0.9424778, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+38, 65337, 962, 0, 0, 3, 0,0, 0, 0, 727.8715, 2165.83, 395.1302, 1.561776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+39, 65337, 962, 0, 0, 3, 0,0, 0, 0, 722.7396, 2262.415, 388.1232, 4.668733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+40, 65337, 962, 0, 0, 3, 0,0, 0, 0, 718.7344, 2263.41, 388.1324, 4.668733, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+41, 58824, 962, 0, 0, 3, 0,0, 0, 0, 874.7604, 2203.925, 354.631, 1.029744, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+42, 65337, 962, 0, 0, 3, 0,0, 0, 0, 721.4236, 2159.003, 396.7852, 1.561776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+43, 65337, 962, 0, 0, 3, 0,0, 0, 0, 715.0452, 2167.715, 394.5749, 1.561776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+44, 56889, 962, 0, 0, 3, 0,0, 0, 0, 716.6684, 2195.675, 386.4492, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+45, 58824, 962, 0, 0, 3, 0,0, 0, 0, 837.7413, 2264.08, 354.649, 0.5585054, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+46, 58202, 962, 0, 0, 3, 0,0, 0, 0, 840.1146, 2316.743, 381.6425, 3.071779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+47, 56484, 962, 0, 0, 3, 0,0, 0, 0, 823.0972, 2373.34, 390.863, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+48, 56484, 962, 0, 0, 3, 0,0, 0, 0, 825.5538, 2373.445, 390.539, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+49, 58824, 962, 0, 0, 3, 0,0, 0, 0, 838.3785, 2273.389, 354.6193, 0.5061455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+50, 56484, 962, 0, 0, 3, 0,0, 0, 0, 841.816, 2373.122, 390.863, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+51, 56484, 962, 0, 0, 3, 0,0, 0, 0, 816.5729, 2373.009, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+52, 58824, 962, 0, 0, 3, 0,0, 0, 0, 928.9739, 2229.486, 363.8914, 1.343904, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+53, 59820, 962, 0, 0, 3, 0,0, 0, 0, 924.0191, 2238.885, 296.1889, 1.63317, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+54, 56484, 962, 0, 0, 3, 0,0, 0, 0, 819.8229, 2373.439, 390.863, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+55, 56906, 962, 0, 0, 3, 0,0, 0, 0, 721.5851, 2320.382, 388.1262, 4.694936, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Saboteur Kip'tilak (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+56, 63992, 962, 0, 0, 3, 0,0, 0, 0, 832.1215, 2375.984, 390.539, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Explosion Target Stalker 1 (Area: Gate of the Setting Sun)
(@CGUID+57, 56484, 962, 0, 0, 3, 0,0, 0, 0, 855.1545, 2373.405, 390.863, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+58, 56799, 962, 0, 0, 3, 0,0, 0, 0, 829.8336, 2363.341, 451.6788, 1.369115, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombadier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+59, 56484, 962, 0, 0, 3, 0,0, 0, 0, 850.6111, 2373.54, 390.863, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+60, 58824, 962, 0, 0, 3, 0,0, 0, 0, 938.4063, 2229.245, 363.8882, 1.43117, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+61, 58824, 962, 0, 0, 3, 0,0, 0, 0, 894.368, 2204.193, 354.6707, 1.151917, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+62, 58109, 962, 0, 0, 3, 0,0, 0, 0, 846.9375, 2306.958, 379.2108, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Mantid Infiltrator Rope Stalker (Area: Gate of the Setting Sun)
(@CGUID+63, 58824, 962, 0, 0, 3, 0,0, 0, 0, 987.7413, 2228.858, 363.868, 1.867502, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+64, 58844, 962, 0, 0, 3, 0,0, 0, 0, 967.993, 2228.905, 363.8909, 1.658063, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Tar Tosser (Area: Gate of the Setting Sun)
(@CGUID+65, 58109, 962, 0, 0, 3, 0,0, 0, 0, 846.941, 2316.686, 379.2108, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Mantid Infiltrator Rope Stalker (Area: Gate of the Setting Sun)
(@CGUID+66, 59820, 962, 0, 0, 3, 0,0, 0, 0, 862.033, 2247.047, 296.1889, 0.5666195, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+67, 56484, 962, 0, 0, 3, 0,0, 0, 0, 832.8958, 2373.703, 390.539, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+68, 58109, 962, 0, 0, 3, 0,0, 0, 0, 846.8438, 2297.382, 379.9061, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Mantid Infiltrator Rope Stalker (Area: Gate of the Setting Sun)
(@CGUID+69, 58824, 962, 0, 0, 3, 0,0, 0, 0, 997.1736, 2228.616, 363.8508, 1.954769, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+70, 56484, 962, 0, 0, 3, 0,0, 0, 0, 828.4271, 2373.429, 390.539, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+71, 56484, 962, 0, 0, 3, 0,0, 0, 0, 830.6945, 2373.109, 390.1924, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+72, 58844, 962, 0, 0, 3, 0,0, 0, 0, 948.0139, 2228.84, 363.8657, 1.466077, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Tar Tosser (Area: Gate of the Setting Sun)
(@CGUID+73, 58202, 962, 0, 0, 3, 0,0, 0, 0, 840.0364, 2306.993, 381.6425, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+74, 58844, 962, 0, 0, 3, 0,0, 0, 0, 978.5278, 2229.436, 363.9021, 1.745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Tar Tosser (Area: Gate of the Setting Sun)
(@CGUID+75, 56484, 962, 0, 0, 3, 0,0, 0, 0, 846.3715, 2373.469, 390.863, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+76, 56484, 962, 0, 0, 3, 0,0, 0, 0, 835.8403, 2373, 390.539, 1.342752, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+77, 56484, 962, 0, 0, 3, 0,0, 0, 0, 838.9774, 2372.642, 390.863, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+78, 58202, 962, 0, 0, 3, 0,0, 0, 0, 840.4688, 2297.559, 381.6425, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+79, 58844, 962, 0, 0, 3, 0,0, 0, 0, 958.5486, 2229.37, 363.9197, 1.570796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Tar Tosser (Area: Gate of the Setting Sun)
(@CGUID+80, 56501, 962, 0, 0, 3, 0,0, 0, 0, 806.2066, 2454.769, 325.5831, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+81, 56502, 962, 0, 0, 3, 0,0, 0, 0, 961.3261, 2377.526, 316.6568, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+82, 59820, 962, 0, 0, 3, 0,0, 0, 0, 1047.151, 2245.236, 296.1889, 2.196415, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+83, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1022.814, 2204.049, 354.6587, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+84, 56502, 962, 0, 0, 3, 0,0, 0, 0, 951.5056, 2396.718, 339.0734, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+85, 63192, 962, 0, 0, 3, 0,0, 0, 0, 958.8055, 2366.009, 401.7852, 4.684969, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Cosmetic Client Stalker (Area: Gate of the Setting Sun) (Auras: 123463 - Mantid Army)
(@CGUID+86, 56502, 962, 0, 0, 3, 0,0, 0, 0, 964.3753, 2379.875, 321.2456, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+87, 56501, 962, 0, 0, 3, 0,0, 0, 0, 815.3976, 2457.458, 328.0863, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+88, 56502, 962, 0, 0, 3, 0,0, 0, 0, 954.5824, 2377.91, 316.7445, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+89, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1032.247, 2203.809, 354.6757, 2.094395, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+90, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1061.097, 2203.839, 354.5728, 2.234021, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+91, 56502, 962, 0, 0, 3, 0,0, 0, 0, 952.3632, 2379.569, 321.226, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+92, 59820, 962, 0, 0, 3, 0,0, 0, 0, 991.8837, 2239.323, 296.1889, 1.63317, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+93, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1066.969, 2203.938, 354.5577, 2.268928, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+94, 56502, 962, 0, 0, 3, 0,0, 0, 0, 966.4816, 2396.331, 338.7084, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+95, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1041.79, 2204.484, 354.6683, 2.146755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+96, 56502, 962, 0, 0, 3, 0,0, 0, 0, 965.9611, 2384.625, 332.6545, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+97, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1051.222, 2204.243, 354.6511, 2.199115, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+98, 56502, 962, 0, 0, 3, 0,0, 0, 0, 951.0538, 2384.333, 332.6101, 4.684154, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Gate Stalker (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+99, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.953, 2206.415, 354.644, 2.321288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+100, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.906, 2225.747, 354.657, 2.408554, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+101, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.955, 2264.354, 354.6766, 2.600541, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+102, 59801, 962, 0, 0, 3, 0,0, 0, 0, 1025.731, 2366.896, 392.222, 3.831994, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Wind Shaper (Area: Gate of the Setting Sun) (Auras: 115421 - Gale Force)
(@CGUID+103, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1019.809, 2368.542, 392.222, 6.034866, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+104, 56501, 962, 0, 0, 3, 0,0, 0, 0, 858.6111, 2461.333, 320.9142, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+105, 59723, 962, 0, 0, 3, 0,0, 0, 0, 772.8889, 2481.762, 448.3826, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Explosion Caster Stalker (Area: Gate of the Setting Sun)
(@CGUID+106, 58146, 962, 0, 0, 3, 0,0, 0, 0, 1024.073, 2361.882, 392.1534, 0.1131168, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+107, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.458, 2236.106, 354.6169, 2.443461, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+108, 56501, 962, 0, 0, 3, 0,0, 0, 0, 823.1233, 2459.172, 324.393, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+109, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1079.097, 2245.417, 354.6465, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+110, 58108, 962, 0, 0, 3, 0,0, 0, 0, 1028.276, 2362.359, 392.0016, 1.128354, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+111, 56501, 962, 0, 0, 3, 0,0, 0, 0, 866.6996, 2458.771, 320.7973, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+112, 58146, 962, 0, 0, 3, 0,0, 0, 0, 1019.693, 2364.38, 392.0016, 6.052016, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun)
(@CGUID+113, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.701, 2274.233, 354.646, 2.670354, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+114, 56501, 962, 0, 0, 3, 0,0, 0, 0, 841.8993, 2460.599, 325.8065, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+115, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1076.361, 2204.16, 354.6593, 2.303835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+116, 56501, 962, 0, 0, 3, 0,0, 0, 0, 830.875, 2459.58, 327.0668, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+117, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.271, 2216.436, 354.6638, 2.356194, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+118, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.318, 2255.043, 354.6444, 2.548181, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+119, 56501, 962, 0, 0, 3, 0,0, 0, 0, 847.4028, 2461.052, 327.0659, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+120, 58146, 962, 0, 0, 3, 0,0, 0, 0, 1193.078, 2304.769, 432.0682, 3.063904, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 128667 - Self On Fire)
(@CGUID+121, 58146, 962, 0, 0, 3, 0,0, 0, 0, 1197.488, 2306.592, 433.536, 3.063904, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 128667 - Self On Fire)
(@CGUID+122, 59886, 962, 0, 0, 3, 0,0, 0, 0, 763.0625, 2527.113, 415.0979, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+123, 59721, 962, 0, 0, 3, 0,0, 0, 0, 1078.41, 2379.063, 390.6265, 1.585699, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Explosion Target Stalker 2 (Area: Gate of the Setting Sun)
(@CGUID+124, 63991, 962, 0, 0, 3, 0,0, 0, 0, 1087.036, 2309.695, 381.3186, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Explosion Target Stalker 3 (Area: Gate of the Setting Sun)
(@CGUID+125, 59886, 962, 0, 0, 3, 0,0, 0, 0, 853.0799, 2533.713, 418.1794, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+126, 59723, 962, 0, 0, 3, 0,0, 0, 0, 1132.477, 2429.314, 445.8561, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Explosion Caster Stalker (Area: Gate of the Setting Sun)
(@CGUID+127, 58146, 962, 0, 0, 3, 0,0, 0, 0, 1029.983, 2365.962, 392.222, 3.158291, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+128, 59886, 962, 0, 0, 3, 0,0, 0, 0, 868.3524, 2516.587, 402.2791, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+129, 56799, 962, 0, 0, 3, 0,0, 0, 0, 1085.717, 2357.421, 451.132, 4.575776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombadier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+130, 56799, 962, 0, 0, 3, 0,0, 0, 0, 1155.206, 2412.033, 487.1257, 3.200162, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombadier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+131, 59886, 962, 0, 0, 3, 0,0, 0, 0, 797.5434, 2530.683, 394.6903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+132, 59886, 962, 0, 0, 3, 0,0, 0, 0, 831.0816, 2526.302, 407.7186, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+133, 59886, 962, 0, 0, 3, 0,0, 0, 0, 809.8177, 2537.774, 414.6712, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+134, 56799, 962, 0, 0, 3, 0,0, 0, 0, 994.2604, 2462.469, 435.2683, 3.042425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombadier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+135, 59886, 962, 0, 0, 3, 0,0, 0, 0, 751.1649, 2515.042, 407.1907, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+136, 59886, 962, 0, 0, 3, 0,0, 0, 0, 797.6042, 2512.929, 379.0449, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+137, 59886, 962, 0, 0, 3, 0,0, 0, 0, 774.132, 2528.425, 387.3473, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+138, 58824, 962, 0, 0, 3, 0,0, 0, 0, 1078.674, 2283.488, 354.6693, 2.722714, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Courtyard Defender (Area: Gate of the Setting Sun)
(@CGUID+139, 58146, 962, 0, 0, 3, 0,0, 0, 0, 1195.415, 2301.682, 432.8714, 3.063904, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun) (Auras: 128667 - Self On Fire)
(@CGUID+140, 59886, 962, 0, 0, 3, 0,0, 0, 0, 846.1077, 2512.896, 387.4301, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Panda Archer Target Spawner (Area: Gate of the Setting Sun) (Auras: 115141 - Creature Spawner - Flying Mantids)
(@CGUID+141, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1266.952, 2262.419, 417.1066, 2.602643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+142, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1265.827, 2249.717, 447.5013, 3.998654, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+143, 60415, 962, 0, 0, 3, 0,0, 0, 0, 1235.795, 2295.309, 430.9078, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon (Area: Gate of the Setting Sun) (Auras: 92406 - Cosmetic - Loot Sparkles (3.00))
(@CGUID+144, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1307.289, 2217.758, 426.4943, 5.342766, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+145, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1267.132, 2332.311, 411.029, 1.521391, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+146, 60415, 962, 0, 0, 3, 0,0, 0, 0, 1235.783, 2313.644, 430.9078, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon (Area: Gate of the Setting Sun) (Auras: 92406 - Cosmetic - Loot Sparkles (3.00))
(@CGUID+147, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1270.64, 2240.433, 441.4445, 4.996321, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+148, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1312.093, 2215.78, 427.554, 0.08159323, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+149, 56875, 962, 0, 0, 3, 0,0, 0, 0, 680.7177, 2217.818, 318.6917, 5.357609, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Demolisher (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+150, 56876, 962, 0, 0, 3, 0,0, 0, 0, 687.4636, 2213.168, 319.3004, 5.333796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Sapper (Area: Gate of the Setting Sun) (Auras: 127498 - Mod Scale 105-110%)
(@CGUID+151, 56875, 962, 0, 0, 3, 0,0, 0, 0, 691.9785, 2217.471, 318.7864, 5.388058, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Demolisher (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+152, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1290.276, 2281.531, 409.0657, 2.517965, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+153, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1267.822, 2315.624, 411.8469, 1.154709, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+154, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1289.078, 2297.541, 427.976, 4.958421, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+155, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1291.901, 2284.155, 422.0557, 6.049444, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+156, 59892, 962, 0, 0, 3, 0,0, 0, 0, 866.4202, 2506.392, 403.4951, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+157, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1282.662, 2311.497, 442.9108, 4.328579, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+158, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1300.212, 2239.307, 425.8184, 3.936069, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+159, 59892, 962, 0, 0, 3, 0,0, 0, 0, 756.4246, 2506.128, 408.2034, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+160, 59892, 962, 0, 0, 3, 0,0, 0, 0, 802.8037, 2509.994, 396.4752, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+161, 59892, 962, 0, 0, 3, 0,0, 0, 0, 851.3963, 2512.584, 417.3061, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+162, 59892, 962, 0, 0, 3, 0,0, 0, 0, 813.4312, 2516.855, 414.2596, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+163, 59892, 962, 0, 0, 3, 0,0, 0, 0, 786.1553, 2498.451, 390.5534, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+164, 59892, 962, 0, 0, 3, 0,0, 0, 0, 832.7953, 2494.046, 407.2628, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+165, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1293.462, 2221.876, 409.088, 2.659176, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+166, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.3144, 2468.238, 385.8262, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+167, 59892, 962, 0, 0, 3, 0,0, 0, 0, 844.0694, 2466.27, 391.914, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+168, 59892, 962, 0, 0, 3, 0,0, 0, 0, 782.9505, 2485.04, 412.1816, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+169, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1292.416, 2237.602, 456.034, 2.591236, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+170, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1293.464, 2286.179, 418.7321, 1.14142, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+171, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.2056, 2513.277, 408.6708, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+172, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.1642, 2510.958, 380.525, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+173, 59892, 962, 0, 0, 3, 0,0, 0, 0, 763.9376, 2525.261, 416.5781, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+174, 59892, 962, 0, 0, 3, 0,0, 0, 0, 846.0178, 2510.849, 388.9102, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+175, 59892, 962, 0, 0, 3, 0,0, 0, 0, 814.2127, 2512.331, 413.8069, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+176, 59892, 962, 0, 0, 3, 0,0, 0, 0, 833.0396, 2489.448, 406.9682, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+177, 59892, 962, 0, 0, 3, 0,0, 0, 0, 787.8699, 2494.177, 390.8162, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+178, 59892, 962, 0, 0, 3, 0,0, 0, 0, 865.5769, 2501.942, 403.3514, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+179, 59892, 962, 0, 0, 3, 0,0, 0, 0, 803.9426, 2505.515, 396.5482, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+180, 59892, 962, 0, 0, 3, 0,0, 0, 0, 851.0327, 2508.02, 416.7433, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+181, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1304.92, 2279.957, 429.5331, 4.767167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+182, 59892, 962, 0, 0, 3, 0,0, 0, 0, 776.0351, 2523.68, 389.0023, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+183, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.0478, 2528.698, 396.1704, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+184, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.4331, 2511.738, 403.6677, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+185, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.6807, 2510.778, 408.5074, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+186, 59892, 962, 0, 0, 3, 0,0, 0, 0, 846.0178, 2510.849, 388.9102, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+187, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.1642, 2510.958, 380.525, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+188, 59892, 962, 0, 0, 3, 0,0, 0, 0, 763.9376, 2525.261, 416.5781, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+189, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1305.787, 2258.674, 407.6093, 5.729371, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings, 132441 - Mantid Wings)
(@CGUID+190, 56484, 962, 0, 0, 3, 0,0, 0, 0, 897.0035, 2397.55, 390.8646, 6.178465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+191, 59892, 962, 0, 0, 3, 0,0, 0, 0, 850.6706, 2503.473, 416.1827, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+192, 59892, 962, 0, 0, 3, 0,0, 0, 0, 814.9911, 2507.825, 413.3558, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+193, 59892, 962, 0, 0, 3, 0,0, 0, 0, 833.2839, 2484.851, 406.6736, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+194, 56484, 962, 0, 0, 3, 0,0, 0, 0, 902.1945, 2397.681, 390.8646, 6.178465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+195, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.0083, 2526.24, 388.8449, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+196, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.2066, 2523.941, 409.1786, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+197, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8919, 2531.358, 419.621, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+198, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.1323, 2528.365, 396.1759, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+199, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.218, 2535.455, 416.1212, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+200, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.3247, 2513.075, 408.6576, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+201, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.9303, 2514.362, 403.7524, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+202, 59892, 962, 0, 0, 3, 0,0, 0, 0, 846.0084, 2510.633, 388.9248, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+203, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.228, 2510.734, 380.5528, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+204, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.0259, 2525.074, 416.5576, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+205, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.1899, 2524.256, 409.1988, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+206, 59892, 962, 0, 0, 3, 0,0, 0, 0, 774.8942, 2526.524, 388.8275, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+207, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.4482, 2527.123, 396.1961, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+208, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7916, 2530.099, 419.4657, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+209, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.4382, 2534.18, 415.9937, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+210, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.989, 2511.95, 408.584, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+211, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.6868, 2513.076, 403.7109, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+212, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9506, 2509.311, 389.0139, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+213, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.5787, 2523.904, 416.4298, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+214, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.5786, 2509.501, 380.7058, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+215, 56876, 962, 0, 0, 3, 0,0, 0, 0, 647.743, 2245.103, 393.0125, 0.01865949, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Sapper (Area: Gate of the Setting Sun) (Auras: 127498 - Mod Scale 105-110%)
(@CGUID+216, 65401, 962, 0, 0, 3, 0,0, 0, 0, 654.5504, 2198.443, 405.9452, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Glider (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings)
(@CGUID+217, 56875, 962, 0, 0, 3, 0,0, 0, 0, 642.6178, 2233.218, 385.1442, 0.1698024, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Demolisher (Area: Gate of the Setting Sun) (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+218, 56876, 962, 0, 0, 3, 0,0, 0, 0, 637.4183, 2236.736, 394.2426, 0.1386647, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Sapper (Area: Gate of the Setting Sun) (Auras: 127498 - Mod Scale 105-110%)
(@CGUID+219, 65401, 962, 0, 0, 3, 0,0, 0, 0, 654.882, 2195.736, 405.9452, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Glider (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings)
(@CGUID+220, 65400, 962, 0, 0, 3, 0,0, 0, 0, 655.6875, 2197.104, 405.9452, 0.2468398, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Glider (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings)
(@CGUID+221, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.1899, 2524.256, 409.1988, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+222, 59892, 962, 0, 0, 3, 0,0, 0, 0, 774.8942, 2526.524, 388.8275, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+223, 56484, 962, 0, 0, 3, 0,0, 0, 0, 902.1649, 2403.391, 390.8629, 6.178465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+224, 56484, 962, 0, 0, 3, 0,0, 0, 0, 902.5278, 2411.924, 390.8646, 6.178465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+225, 56484, 962, 0, 0, 3, 0,0, 0, 0, 896.9792, 2410.401, 390.8629, 6.178465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+226, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.0478, 2528.698, 396.1704, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+227, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.166, 2535.756, 416.1514, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+228, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.9168, 2531.671, 419.6596, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+229, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.5066, 2511.073, 408.5267, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+230, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.4969, 2512.074, 403.6785, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+231, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9065, 2508.303, 389.0818, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+232, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.8557, 2508.527, 380.8267, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+233, 59892, 962, 0, 0, 3, 0,0, 0, 0, 765.0126, 2522.987, 416.3295, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+234, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.1975, 2524.112, 409.1895, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+235, 59892, 962, 0, 0, 3, 0,0, 0, 0, 774.9446, 2526.398, 388.8352, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+236, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.0812, 2528.567, 396.1726, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+237, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.1844, 2535.65, 416.1407, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+238, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.9069, 2531.546, 419.6442, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+239, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.9488, 2514.459, 403.7555, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+240, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.2606, 2513.184, 408.6647, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+241, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.1985, 2510.838, 380.54, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+242, 59892, 962, 0, 0, 3, 0,0, 0, 0, 846.0127, 2510.732, 388.9181, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+243, 59892, 962, 0, 0, 3, 0,0, 0, 0, 765.5194, 2521.914, 416.2123, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+244, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.2477, 2523.168, 409.129, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+245, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.2969, 2525.52, 388.8892, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+246, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.3147, 2527.648, 396.1876, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+247, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8328, 2530.617, 419.5296, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+248, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.3434, 2534.729, 416.0486, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+249, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.6866, 2512.462, 408.6175, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463); -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)

INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.796, 2513.653, 403.7295, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+251, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9828, 2510.049, 388.9642, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+252, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.3751, 2510.217, 380.617, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+253, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.2639, 2524.57, 416.5026, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+254, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1056.951, 2432.901, 351.001, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+255, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1047.01, 2438.681, 346.3424, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+256, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1063.608, 2437.309, 350.444, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+257, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.306, 2522.07, 409.0587, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+258, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.7062, 2524.5, 388.9519, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+259, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.5728, 2526.633, 396.2041, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+260, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7503, 2529.581, 419.4019, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+261, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.5223, 2533.693, 415.9449, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+262, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1071.771, 2437.807, 353.4225, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+263, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.5776, 2512.5, 403.6923, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+264, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.2684, 2511.476, 408.5531, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+265, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.7976, 2523.441, 416.3792, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+266, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.7233, 2508.993, 380.769, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+267, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9285, 2508.807, 389.0479, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+268, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.3696, 2520.874, 408.982, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+269, 59892, 962, 0, 0, 3, 0,0, 0, 0, 776.1492, 2523.396, 389.0198, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+270, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.6578, 2528.419, 419.2587, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+271, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.7181, 2532.56, 415.8315, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+272, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.8597, 2525.505, 396.2225, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+273, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1083.424, 2436.913, 362.5964, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+274, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.371, 2511.41, 403.6571, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+275, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.8318, 2510.522, 408.4907, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+276, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.8759, 2507.601, 389.1291, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+277, 59892, 962, 0, 0, 3, 0,0, 0, 0, 799.0469, 2507.855, 380.9102, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+278, 59892, 962, 0, 0, 3, 0,0, 0, 0, 765.3121, 2522.353, 416.2602, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+279, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.2224, 2523.645, 409.1595, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+280, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.1123, 2525.98, 388.8609, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+281, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.1813, 2528.173, 396.179, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+282, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8763, 2531.162, 419.5968, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+283, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.2501, 2535.269, 416.1026, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+284, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.4484, 2512.866, 408.6439, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+285, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.8833, 2514.114, 403.7444, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+286, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.999, 2510.417, 388.9393, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+287, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.2794, 2510.553, 380.5753, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+288, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.1104, 2524.895, 416.5381, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+289, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.5821, 2524.809, 388.9329, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+290, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.2888, 2522.394, 409.0794, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+291, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.449, 2534.118, 415.9875, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+292, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.4682, 2527.044, 396.1974, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+293, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7838, 2530, 419.4536, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+294, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.67, 2512.988, 403.708, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+295, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.021, 2511.896, 408.5805, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+296, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.5761, 2509.51, 380.7048, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+297, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.5749, 2523.912, 416.4307, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+298, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9514, 2509.329, 389.0127, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+299, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.9982, 2523.772, 388.9966, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+300, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.3477, 2521.287, 409.0085, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+301, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.7663, 2525.872, 396.2165, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+302, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.6554, 2532.923, 415.8678, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+303, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.6898, 2528.822, 419.3083, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+304, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.6807, 2510.778, 408.5074, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+305, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.4264, 2511.702, 403.6665, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+306, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.8923, 2507.979, 389.1036, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+307, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.944, 2508.217, 380.8652, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+308, 59892, 962, 0, 0, 3, 0,0, 0, 0, 765.1508, 2522.694, 416.2975, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+309, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.0419, 2526.156, 388.8501, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+310, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.2114, 2523.852, 409.1728, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+311, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.1323, 2528.365, 396.1759, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+312, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.2211, 2535.437, 416.1195, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+313, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8919, 2531.358, 419.621, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+314, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.3568, 2513.021, 408.6541, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+315, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.9186, 2514.3, 403.7504, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+316, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.0297, 2525.066, 416.5568, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+317, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.2304, 2510.726, 380.5539, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+318, 59892, 962, 0, 0, 3, 0,0, 0, 0, 846.008, 2510.625, 388.9254, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+319, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.1899, 2524.256, 409.1988, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+320, 59892, 962, 0, 0, 3, 0,0, 0, 0, 774.8942, 2526.524, 388.8275, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+321, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.4107, 2534.339, 416.0096, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+322, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8044, 2530.26, 419.4856, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+323, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.4059, 2527.289, 396.1934, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+324, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.9477, 2512.02, 408.5886, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+325, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.7019, 2513.156, 403.7135, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+326, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.5394, 2509.639, 380.6887, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+327, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9568, 2509.455, 389.0042, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+328, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.5135, 2524.042, 416.4449, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+329, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1093.365, 2431.134, 363.0448, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+330, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1100.021, 2435.542, 366.4697, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+331, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.3261, 2521.692, 409.0345, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+332, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.8472, 2524.148, 388.9735, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+333, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.5988, 2533.25, 415.9006, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+334, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.6818, 2526.205, 396.2111, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+335, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7162, 2529.152, 419.349, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+336, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.5137, 2512.163, 403.6814, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+337, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.447, 2511.174, 408.5333, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+338, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9148, 2508.492, 389.0691, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+339, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.932, 2523.157, 416.3481, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+340, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.8018, 2508.717, 380.8032, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+341, 59793, 962, 0, 0, 3, 0,0, 0, 0, 1377.262, 2280.453, 426.9559, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Bonfire Target Stalker 1 (Area: Gate of the Setting Sun)
(@CGUID+342, 59792, 962, 0, 0, 3, 0,0, 0, 0, 1376.672, 2280.478, 401.5854, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Bonfire Caster Stalker (Area: Gate of the Setting Sun)
(@CGUID+343, 56501, 962, 0, 0, 3, 0,0, 0, 0, 1108.184, 2436.04, 366.4537, 3.089233, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Panda Archer Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+344, 66419, 962, 0, 0, 3, 0,0, 0, 0, 1025.599, 2386.094, 392.2328, 1.572707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun) (Auras: 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun))
(@CGUID+345, 63848, 962, 0, 0, 3, 0,0, 0, 0, 1377.245, 2280.538, 403.3015, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Great Wall Bonfire Target Stalker 2 (Area: Gate of the Setting Sun) (Auras: 124677 - Great Wall Bonfire Dummy Flame)
(@CGUID+346, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1062.845, 2376.186, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+347, 66419, 962, 0, 0, 3, 0,0, 0, 0, 1022.175, 2399.766, 390.856, 5.933926, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun) (Auras: 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun))
(@CGUID+348, 66419, 962, 0, 0, 3, 0,0, 0, 0, 1029.738, 2399.646, 390.8318, 1.211506, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun) (Auras: 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun))
(@CGUID+349, 66419, 962, 0, 0, 3, 0,0, 0, 0, 1023.826, 2406.969, 390.863, 5.238289, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun) (Auras: 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun))
(@CGUID+350, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1067.585, 2376.273, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+351, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1058.396, 2376.163, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+352, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1091.375, 2379.878, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+353, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1090.47, 2384.816, 390.8629, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+354, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1095.075, 2376.691, 390.8646, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+355, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1083.542, 2377.16, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+356, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1086.674, 2381.932, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+357, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1080.149, 2379.797, 390.8629, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+358, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1088.766, 2377.488, 390.5389, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+359, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1075.224, 2377.047, 390.8628, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+360, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1082.319, 2385.139, 390.8629, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+361, 56484, 962, 0, 0, 3, 0,0, 0, 0, 1071.453, 2377.405, 390.8409, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Marksman (Area: Gate of the Setting Sun)
(@CGUID+362, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.1909, 2524.238, 409.1976, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+363, 58108, 962, 0, 0, 3, 0,0, 0, 0, 855.5851, 2301.481, 366.5475, 3.03068, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+364, 59892, 962, 0, 0, 3, 0,0, 0, 0, 774.8976, 2526.516, 388.828, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+365, 58108, 962, 0, 0, 3, 0,0, 0, 0, 855.0886, 2311.141, 366.5475, 3.275075, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+366, 58108, 962, 0, 0, 3, 0,0, 0, 0, 855.1684, 2291.764, 366.5475, 2.734993, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Infiltrator (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+367, 59801, 962, 0, 0, 3, 0,0, 0, 0, 855.4739, 2320.972, 366.5475, 3.39458, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Wind Shaper (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+368, 58146, 962, 0, 0, 3, 0,0, 0, 0, 875.9305, 2366.613, 392.0073, 3.114033, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun)
(@CGUID+369, 58146, 962, 0, 0, 3, 0,0, 0, 0, 876.7587, 2363.806, 392.0038, 3.140817, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun)
(@CGUID+370, 58146, 962, 0, 0, 3, 0,0, 0, 0, 876.5851, 2369.505, 392.004, 3.118612, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun)
(@CGUID+371, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.7701, 2532.259, 415.8014, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+372, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.9309, 2525.225, 396.2271, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+373, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.6365, 2528.152, 419.2256, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+374, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.3256, 2511.17, 403.6494, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+375, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.9601, 2510.304, 408.4764, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+376, 59892, 962, 0, 0, 3, 0,0, 0, 0, 799.0935, 2507.691, 380.9305, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+377, 59892, 962, 0, 0, 3, 0,0, 0, 0, 765.3812, 2522.207, 416.2442, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+378, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.8691, 2507.448, 389.1394, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+379, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.242, 2523.276, 409.1359, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+380, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.2532, 2525.629, 388.8825, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+381, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.2858, 2527.762, 396.1857, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+382, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8428, 2530.742, 419.545, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+383, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.3266, 2534.826, 416.0583, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+384, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.682, 2512.47, 408.618, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+385, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.7909, 2513.626, 403.7286, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+386, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9789, 2509.958, 388.9702, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+387, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.402, 2510.122, 380.6288, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+388, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.3062, 2524.481, 416.4928, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+389, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.713, 2524.483, 388.9529, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+390, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.3075, 2522.043, 409.0569, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+391, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.595, 2526.546, 396.2055, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+392, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7446, 2529.509, 419.3931, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+393, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.5392, 2533.596, 415.9352, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+394, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.5692, 2512.456, 403.6909, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+395, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.2958, 2511.43, 408.55, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+396, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9222, 2508.663, 389.0576, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+397, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.8629, 2523.303, 416.3641, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+398, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.765, 2508.846, 380.7871, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+399, 65537, 962, 0, 0, 3, 0,0, 0, 0, 1236.449, 2303.819, 432.396, 3.019419, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Cannoneer (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+400, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.3672, 2520.919, 408.9849, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+401, 59892, 962, 0, 0, 3, 0,0, 0, 0, 776.1357, 2523.429, 389.0177, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+402, 56824, 962, 0, 0, 3, 0,0, 0, 0, 1153.398, 2304.578, 430.9078, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 South Stalker (Area: Gate of the Setting Sun)
(@CGUID+403, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1176.436, 2307.017, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+404, 60421, 962, 0, 0, 3, 0,0, 0, 0, 1278.594, 2298.271, 422.7147, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+405, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1168.061, 2303.835, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+406, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1155.297, 2292.524, 418.6444, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun)
(@CGUID+407, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1160.995, 2297.714, 431.0042, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+408, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1151.504, 2300.33, 431.0042, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+409, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1179.238, 2300.137, 430.8999, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+410, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1153.582, 2302.292, 372.5509, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun)
(@CGUID+411, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1153.212, 2309.707, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+412, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1178.491, 2313.707, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+413, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1159.309, 2306.861, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+414, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1164.96, 2312.873, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+415, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1181.361, 2329.389, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+416, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1172.724, 2288.72, 431.0042, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+417, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1164.828, 2292.042, 430.9325, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+418, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1178.927, 2307.528, 430.8993, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+419, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1185.917, 2345.007, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+420, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1154.47, 2312.214, 374.48, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun)
(@CGUID+421, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1155.469, 2315.49, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+422, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1178.705, 2316.769, 430.9062, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+423, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1155.337, 2294.66, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+424, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1171.276, 2297.899, 430.9078, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+425, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1170.293, 2311.104, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+426, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1172.37, 2317.628, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+427, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.8909, 2525.382, 396.2245, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+428, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.7426, 2532.418, 415.8173, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+429, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.6493, 2528.312, 419.2455, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+430, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.3575, 2511.339, 403.6548, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+431, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.8868, 2510.428, 408.4846, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+432, 59892, 962, 0, 0, 3, 0,0, 0, 0, 799.0469, 2507.855, 380.9102, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+433, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.877, 2507.628, 389.1273, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+434, 59892, 962, 0, 0, 3, 0,0, 0, 0, 765.3082, 2522.361, 416.2611, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+435, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1189.132, 2331.748, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+436, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1186.314, 2337.165, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+437, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1192.632, 2312.078, 430.8867, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+438, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1180.599, 2280.151, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+439, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1184.682, 2286.161, 430.9071, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+440, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1187.339, 2307.637, 430.8879, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+441, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1192.314, 2319.523, 430.9047, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+442, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1179.227, 2295.717, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+443, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1183.648, 2299.712, 430.8951, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+444, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1184.653, 2324.601, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+445, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1190.731, 2303.398, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+446, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1182.474, 2289.481, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+447, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1192.627, 2346.934, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+448, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1184.767, 2309.172, 430.8936, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+449, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1185.646, 2318.503, 430.9012, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+450, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1185.814, 2297.587, 430.9051, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+451, 56823, 962, 0, 0, 3, 0,0, 0, 0, 1195.299, 2348.941, 431.0042, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West Stalker (Area: Gate of the Setting Sun)
(@CGUID+452, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1191.832, 2341.684, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+453, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1180.252, 2302.342, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+454, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1185.957, 2288.269, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+455, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1192.67, 2325.609, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+456, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1184.807, 2309.938, 430.9056, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+457, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1181.724, 2291.49, 430.9022, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+458, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1183.738, 2316.799, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+459, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1192.012, 2315.111, 430.8996, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+460, 59750, 962, 0, 0, 3, 0,0, 0, 0, 1192.174, 2324.908, 388.0399, 4.951303, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+461, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1201.502, 2314.248, 430.8917, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+462, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1196.349, 2298.715, 430.8897, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+463, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1191.313, 2283.917, 430.905, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+464, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1204.854, 2342.958, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+465, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1187.057, 2277.894, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+466, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1199.26, 2310.498, 431.1726, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+467, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1188.618, 2292.361, 430.897, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+468, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1201.408, 2346.724, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+469, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1189.87, 2293.099, 430.9038, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+470, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1201.892, 2319.726, 430.9026, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+471, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1191.215, 2304.453, 431.261, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+472, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1185.514, 2262.104, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+473, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1199.693, 2320.042, 430.8997, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+474, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1185.146, 2272.611, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+475, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1195.911, 2289.592, 430.9019, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+476, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1195.311, 2298.109, 431.229, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+477, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1200.151, 2303.599, 431.1694, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+478, 59750, 962, 0, 0, 3, 0,0, 0, 0, 1198.26, 2324.012, 388.0378, 4.613867, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+479, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1197.129, 2333.905, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+480, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1204.399, 2334.653, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+481, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1197.715, 2342.059, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+482, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1195.09, 2319.564, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+483, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1201.804, 2327.667, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+484, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1196.946, 2307.667, 430.8875, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+485, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1205.594, 2296.972, 430.8936, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+486, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1209.792, 2328.396, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+487, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1208.925, 2320.512, 430.8997, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+488, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1200.988, 2293.036, 430.8954, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+489, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1205.099, 2290.387, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+490, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1200.184, 2268.231, 430.9078, 1.570796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+491, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1202.675, 2286.399, 430.9044, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+492, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1208.8, 2321.467, 430.9074, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+493, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1195.408, 2260.941, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+494, 56825, 962, 0, 0, 3, 0,0, 0, 0, 1195.392, 2263.441, 430.9078, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 East Stalker (Area: Gate of the Setting Sun)
(@CGUID+495, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1190.925, 2268.899, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+496, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1194.264, 2275.458, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+497, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1209.004, 2289.476, 430.9053, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+498, 59750, 962, 0, 0, 3, 0,0, 0, 0, 1199.023, 2284.88, 388.0399, 1.678284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+499, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1210.849, 2313.625, 430.8904, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463); -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)

INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1196.09, 2287.603, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+501, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1212.172, 2304.205, 431.3223, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+502, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1200.28, 2278.512, 430.9078, 1.570796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+503, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1205.66, 2298.566, 430.8938, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+504, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1205.637, 2306.016, 430.8911, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+505, 59750, 962, 0, 0, 3, 0,0, 0, 0, 1193.99, 2285.373, 388.0374, 1.403921, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+506, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1208.715, 2312.115, 430.899, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+507, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1209.264, 2302.906, 430.8977, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+508, 60421, 962, 0, 0, 3, 0,0, 0, 0, 1327.012, 2301.769, 429.0417, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+509, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1234.193, 2308.073, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+510, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1214.446, 2290.556, 430.9011, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+511, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1221.401, 2289.757, 430.9076, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+512, 60421, 962, 0, 0, 3, 0,0, 0, 0, 1308.313, 2306.637, 427.2734, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+513, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1205.958, 2271.913, 430.9078, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+514, 60421, 962, 0, 0, 3, 0,0, 0, 0, 1317.186, 2297.085, 442.4991, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+515, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1218.144, 2306.8, 430.8949, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+516, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1221.62, 2318.205, 430.9075, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+517, 56743, 962, 0, 0, 3, 0,0, 0, 0, 1212.493, 2300.649, 388.0373, 1.64061, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun)
(@CGUID+518, 60421, 962, 0, 0, 3, 0,0, 0, 0, 1328.234, 2289.271, 428.285, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+519, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1205.222, 2262.389, 430.9078, 1.570796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+520, 56742, 962, 0, 0, 3, 0,0, 0, 0, 1212.681, 2308.269, 388.0399, 4.590216, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Defender (Area: Gate of the Setting Sun)
(@CGUID+521, 56745, 962, 0, 0, 3, 0,0, 0, 0, 1209.174, 2301.856, 388.036, 0.6457718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent's Spine Trainee (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+522, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1229.526, 2313.462, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+523, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1227.512, 2295.318, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+524, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1224.182, 2310.505, 430.9046, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+525, 60421, 962, 0, 0, 3, 0,0, 0, 0, 1299.243, 2311.641, 431.1498, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flak Cannon Target Stalker (Area: Gate of the Setting Sun)
(@CGUID+526, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1209.495, 2279.707, 430.9079, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+527, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1212.519, 2297.418, 431.3361, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+528, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1220.453, 2297.722, 430.9011, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+529, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1226.561, 2302.566, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+530, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1216.918, 2314.785, 430.8988, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+531, 56913, 962, 0, 0, 3, 0,0, 0, 0, 1210.304, 2292.929, 430.9038, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 West/East Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+532, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1234.731, 2302.203, 430.9078, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+533, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.231, 2523.483, 409.1492, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+534, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.1761, 2525.821, 388.8707, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+535, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.2324, 2527.972, 396.1823, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+536, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.2899, 2535.039, 416.0796, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+537, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.8606, 2530.965, 419.5726, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+538, 56822, 962, 0, 0, 3, 0,0, 0, 0, 1238.007, 2304.644, 430.9078, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North Stalker (Area: Gate of the Setting Sun)
(@CGUID+539, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1289.137, 2325.063, 383.1507, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 116621 - Great Wall Boss 3 Big Add Spawn Periodic Trigger)
(@CGUID+540, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1274.983, 2296.366, 381.8893, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+541, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1287.851, 2298.672, 384.4548, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+542, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1273.316, 2304.073, 381.3447, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+543, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1275.061, 2325.038, 378.1627, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger)
(@CGUID+544, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1239.464, 2307.422, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+545, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1287.557, 2305.78, 384.1411, 6.230825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+546, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1279.127, 2304.028, 382.1141, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+547, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1239.484, 2298.634, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+548, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1269.983, 2309.198, 381.6533, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+549, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1235.821, 2295.092, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+550, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1267.948, 2300.158, 381.6533, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+551, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1282.91, 2324.458, 378.2498, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger)
(@CGUID+552, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1276.552, 2311.734, 382.0971, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+553, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1280.91, 2297.688, 382.6741, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+554, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1278.642, 2324.42, 376.9382, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger)
(@CGUID+555, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1284.212, 2302.292, 383.3684, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+556, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1283.326, 2311.799, 383.1249, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+557, 56932, 962, 0, 0, 3, 0,0, 0, 0, 1237.356, 2314.082, 430.9079, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 2 North/South Strafe Stalkers (Area: Gate of the Setting Sun) (Auras: 116298 - Strafing Run)
(@CGUID+558, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.5492, 2512.695, 408.6328, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+559, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.8463, 2513.918, 403.7381, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+560, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9836, 2510.066, 388.963, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+561, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.3726, 2510.226, 380.616, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+562, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.2601, 2524.578, 416.5035, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+563, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1308.424, 2298.58, 389.9059, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+564, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1304.785, 2302.484, 388.669, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+565, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1291.01, 2308.773, 385.5676, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+566, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1297.238, 2310.007, 387.2453, 4.537856, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+567, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1297.49, 2300.089, 387.1104, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+568, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1308.604, 2311.639, 390.122, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+569, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1295.667, 2324.818, 382.075, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger)
(@CGUID+570, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1301.53, 2297.179, 388.0056, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+571, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1312.929, 2295.234, 392.4688, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+572, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1304.644, 2324.523, 384.4969, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger)
(@CGUID+573, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1303.696, 2308.851, 388.8099, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+574, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1299.62, 2304.863, 387.401, 4.537856, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+575, 59834, 962, 0, 0, 3, 0,0, 0, 0, 1300.455, 2324.823, 383.6881, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Boss 3 Encounter Add Generator (Area: Gate of the Setting Sun) (Auras: 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger)
(@CGUID+576, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1294.106, 2303.743, 386.0432, 4.537856, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+577, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1293.188, 2295.764, 385.9353, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+578, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1310.521, 2305.349, 390.304, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+579, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1313.031, 2308.514, 391.3875, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+580, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.6022, 2524.759, 388.936, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+581, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.2913, 2522.349, 409.0765, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+582, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.4627, 2534.038, 415.9795, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+583, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.486, 2526.974, 396.1985, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+584, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7781, 2529.929, 419.4448, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+585, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.9706, 2514.574, 403.7592, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+586, 59892, 962, 0, 0, 3, 0,0, 0, 0, 752.2056, 2513.277, 408.6708, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+587, 59892, 962, 0, 0, 3, 0,0, 0, 0, 845.9502, 2509.302, 389.0145, 4.66871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+588, 59892, 962, 0, 0, 3, 0,0, 0, 0, 764.5903, 2523.88, 416.4271, 5.15397, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+589, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.5884, 2509.467, 380.7101, 4.989481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+590, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1319.986, 2309.693, 392.9219, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+591, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1317.689, 2300.854, 392.1292, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+592, 59892, 962, 0, 0, 3, 0,0, 0, 0, 831.3357, 2521.512, 409.0229, 4.76548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+593, 59892, 962, 0, 0, 3, 0,0, 0, 0, 775.9143, 2523.981, 388.9838, 5.093877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+594, 59892, 962, 0, 0, 3, 0,0, 0, 0, 798.7107, 2526.091, 396.2129, 4.961393, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+595, 59892, 962, 0, 0, 3, 0,0, 0, 0, 810.6202, 2533.126, 415.8882, 4.883455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+596, 59892, 962, 0, 0, 3, 0,0, 0, 0, 852.7076, 2529.045, 419.3358, 4.632896, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+597, 59892, 962, 0, 0, 3, 0,0, 0, 0, 867.4785, 2511.977, 403.6754, 4.525125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+598, 59892, 962, 0, 0, 3, 0,0, 0, 0, 753.5524, 2510.995, 408.5216, 5.24551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Invader (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+599, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1143.014, 2393.224, 401.2359, 2.67759, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+600, 59801, 962, 0, 0, 3, 0,0, 0, 0, 1129.952, 2397.194, 401.4712, 3.079451, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Wind Shaper (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+601, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1137.495, 2397.874, 401.0901, 2.970252, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+602, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1329.931, 2298.299, 394.6539, 0.3141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+603, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1333.217, 2309.165, 395.2979, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+604, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1325.158, 2306.67, 393.9858, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+605, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1325.866, 2301.783, 393.8511, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: 106875 - Fire Bomb)
(@CGUID+606, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1325.212, 2294.345, 394.2215, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+607, 56709, 962, 0, 0, 3, 0,0, 0, 0, 1319.424, 2296.043, 392.9848, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Flying Mantid Bombing Stalker (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+608, 64553, 962, 0, 0, 3, 0,0, 0, 0, 1371.441, 2282.965, 401.4077, 2.718086, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- "Lighting the Way" Kill Credit (Area: Gate of the Setting Sun)
(@CGUID+609, 65555, 962, 0, 0, 3, 0,0, 0, 0, 1370.002, 2283.599, 401.3283, 2.701643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Bonfire Teleport Stalker (Area: Gate of the Setting Sun)
(@CGUID+610, 56706, 962, 0, 0, 3, 0,0, 0, 0, 1343.847, 2294.859, 422.4663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Bombardier (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings)
(@CGUID+611, 59794, 962, 0, 0, 3, 0,0, 0, 0, 1236.734, 2278.387, 437.3962, 1.579291, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Disruptor (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings)
(@CGUID+612, 59794, 962, 0, 0, 3, 0,0, 0, 0, 1237.29, 2332.217, 435.8299, 5.20612, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Disruptor (Area: Gate of the Setting Sun) (Auras: 126316 - Green Mantid Wings)
(@CGUID+613, 59778, 962, 0, 0, 3, 0,0, 0, 0, 1192.198, 2376.832, 442.8781, 5.248713, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Striker (Area: Gate of the Setting Sun) (Auras: 138393 - Blue Mantid Wings)
(@CGUID+614, 59778, 962, 0, 0, 3, 0,0, 0, 0, 1198.648, 2380.932, 446.2177, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Striker (Area: Gate of the Setting Sun) (Auras: 138393 - Blue Mantid Wings)
(@CGUID+615, 59778, 962, 0, 0, 3, 0,0, 0, 0, 1192.396, 2375.583, 442.769, 4.866328, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Striker (Area: Gate of the Setting Sun) (Auras: 138393 - Blue Mantid Wings)
(@CGUID+616, 59778, 962, 0, 0, 3, 0,0, 0, 0, 1198.648, 2380.932, 446.2177, 4.126297, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Striker (Area: Gate of the Setting Sun) (Auras: 138393 - Blue Mantid Wings)
(@CGUID+617, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1278.627, 2326.328, 378.4445, 4.711166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: 115430 - Enrage)
(@CGUID+618, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1283.127, 2326.195, 378.5784, 4.683353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+619, 56636, 962, 0, 0, 3, 0,0, 0, 0, 1264.226, 2304.488, 381.4279, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Commander Ri'mok (Area: Gate of the Setting Sun)
(@CGUID+620, 59801, 962, 0, 0, 3, 0,0, 0, 0, 1296.132, 2325.401, 382.3396, 4.545639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Wind Shaper (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+621, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1300.052, 2325.217, 382.6831, 4.666473, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+622, 59801, 962, 0, 0, 3, 0,0, 0, 0, 1274.707, 2326.514, 378.0805, 4.72244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Wind Shaper (Area: Gate of the Setting Sun) (Auras: 115421 - Gale Force)
(@CGUID+623, 59800, 962, 0, 0, 3, 0,0, 0, 0, 1304.552, 2325.082, 382.8384, 4.595585, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Rager (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+624, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1026.156, 2323.703, 390.8629, 1.853857, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+625, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1024.941, 2363.078, 392.222, 1.621097, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+626, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1075.267, 2362.431, 390.8628, 2.450659, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+627, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+628, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1062.424, 2362.849, 390.8628, 0.9542149, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+629, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1098.698, 2305.023, 381.3185, 3.177293, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+630, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1030.917, 2369.373, 392.0016, 3.339632, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+631, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1069.814, 2360.618, 390.8628, 1.886694, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+632, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+633, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1031.609, 2325.516, 390.8629, 2.611764, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+634, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1030.394, 2364.891, 392.0016, 2.636719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+635, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1075.79, 2366.913, 390.5388, 2.878922, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+636, 61213, 962, 0, 0, 3, 0,0, 0, 0, 1024.401, 2329.738, 390.863, 4.99545, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Conscript (Area: Gate of the Setting Sun)
(@CGUID+637, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+638, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1018.766, 2325.934, 390.8629, 0.5937341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+639, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1017.55, 2365.309, 392.0016, 0.3780964, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+640, 60502, 962, 0, 0, 3, 0,0, 0, 0, 1032.132, 2329.998, 390.8629, 3.17523, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Disciple (Area: Gate of the Setting Sun)
(@CGUID+641, 61213, 962, 0, 0, 3, 0,0, 0, 0, 1066.983, 2369.281, 390.8628, 4.607564, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Conscript (Area: Gate of the Setting Sun)
(@CGUID+642, 61213, 962, 0, 0, 3, 0,0, 0, 0, 1024.583, 2368.103, 392.222, 0.1981428, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Conscript (Area: Gate of the Setting Sun)
(@CGUID+643, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+644, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+645, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+646, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+647, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+648, 64710, 962, 0, 0, 3, 0,0, 0, 0, 844.2726, 2316.179, 382.2684, 6.088803, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Rope (Area: Gate of the Setting Sun) (Auras: 126493 - Rope Visual)
(@CGUID+649, 64710, 962, 0, 0, 3, 0,0, 0, 0, 845.1736, 2299.464, 383.7637, 6.088803, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Rope (Area: Gate of the Setting Sun) (Auras: 126493 - Rope Visual)
(@CGUID+650, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+651, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+652, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+653, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+654, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+655, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+656, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+657, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+658, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+659, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+660, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+661, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Gate of the Setting Sun)
(@CGUID+662, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+663, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+664, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+665, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+666, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+667, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+668, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+669, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: 0)
(@CGUID+670, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+671, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+672, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+673, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+674, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+675, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+676, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+677, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+678, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+679, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+680, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+681, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+682, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+683, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+684, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+685, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+686, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+687, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+688, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+689, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+690, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+691, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+692, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+693, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+694, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+695, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+696, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+697, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+698, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+699, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+700, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+701, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+702, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+703, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+704, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+705, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+706, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+707, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+708, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+709, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+710, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+711, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+712, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+713, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+714, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+715, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+716, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+717, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+718, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+719, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+720, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+721, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+722, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+723, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+724, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+725, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+726, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+727, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+728, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+729, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+730, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+731, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+732, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+733, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+734, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+735, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+736, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+737, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+738, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+739, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+740, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+741, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+742, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.163, 2272.198, 388.2441, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+743, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1190.233, 2336.802, 388.2513, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+744, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1200.34, 2272.934, 388.2462, 1.665215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+745, 66905, 962, 0, 0, 3, 0,0, 0, 0, 1199.783, 2336.757, 388.2466, 4.71409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Pandaren Cannoneer (Area: Ancient Courtyard)
(@CGUID+746, 64467, 962, 0, 0, 3, 0,0, 0, 0, 958.2674, 2169.422, 296.1889, 1.56877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Bowmistress Li (Area: Ancient Courtyard) (Auras: 120856 - Pandaren Arrows 01 Stack)
(@CGUID+747, 61981, 870, 0, 0, 1, 0,0, 0, 0, 656.8941, 2113.799, 326.9063, 3.553615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+748, 62000, 870, 0, 0, 1, 0,0, 0, 0, 664.8316, 2098.441, 330.2693, 1.416869, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner (Area: Gate of the Setting Sun) (Auras: 52391 - Ride Vehicle)
(@CGUID+749, 61981, 870, 0, 0, 1, 0,0, 0, 0, 657.941, 2101.399, 330.0087, 4.220236, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463); -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)

INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+750, 61981, 870, 0, 0, 1, 0,0, 0, 0, 691.6441, 2152.25, 327.2798, 3.305534, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+751, 61968, 870, 0, 0, 1, 0,0, 0, 0, 653.3976, 2116.538, 371.9426, 6.161381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Marksman (Area: Gate of the Setting Sun)
(@CGUID+752, 62112, 870, 0, 0, 1, 0,0, 0, 0, 649.0434, 2122.863, 369.1852, 3.126311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Bowmistress Li (Area: Gate of the Setting Sun) (Auras: 120856 - Pandaren Arrows 01 Stack)
(@CGUID+753, 62000, 870, 0, 0, 1, 0,0, 0, 0, 704.1743, 2146.381, 340.2925, 0.01745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner (Area: Gate of the Setting Sun) (Auras: 52391 - Ride Vehicle, 120685 - Shoot Me Aura)
(@CGUID+754, 61981, 870, 0, 0, 1, 0,0, 0, 0, 701.8299, 2119.167, 331.6825, 5.350321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 127358 - Seek and Destroy, 70628 - Permanent Feign Death)
(@CGUID+755, 61981, 870, 0, 0, 1, 0,0, 0, 0, 701.1927, 2135.075, 330.219, 4.948637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+756, 61968, 870, 0, 0, 1, 0,0, 0, 0, 707.7413, 2136.158, 404.2854, 3.18957, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Marksman (Area: Gate of the Setting Sun)
(@CGUID+757, 58448, 870, 0, 0, 1, 0,0, 0, 0, 660.743, 2061.326, 345.1932, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Black Bengal Goat (Area: Gate of the Setting Sun)
(@CGUID+758, 61981, 870, 0, 0, 1, 0,0, 0, 0, 700.9792, 2141.389, 329.2101, 0.3719259, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+759, 61981, 870, 0, 0, 1, 0,0, 0, 0, 658.0903, 2127.769, 326.3663, 1.847141, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+760, 61981, 870, 0, 0, 1, 0,0, 0, 0, 699.8663, 2127.74, 330.8203, 3.476103, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+761, 58448, 870, 0, 0, 1, 0,0, 0, 0, 690.533, 2053.099, 340.1196, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Black Bengal Goat (Area: Gate of the Setting Sun)
(@CGUID+762, 58065, 870, 0, 0, 1, 0,0, 0, 0, 654.132, 2121.583, 368.2335, 0.1594919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- General Purpose Bunny (DLA) (Area: Gate of the Setting Sun)
(@CGUID+763, 58992, 870, 0, 0, 1, 0,0, 0, 0, 694.5608, 2004.845, 325.5174, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+764, 62077, 870, 0, 0, 1, 0,0, 0, 0, 658.5799, 2139.052, 325.9835, 2.627373, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Egg (Area: Gate of the Setting Sun)
(@CGUID+765, 62000, 870, 0, 0, 1, 0,0, 0, 0, 703.0349, 2165.988, 325.7411, 0.07928482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner (Area: Gate of the Setting Sun)
(@CGUID+766, 61981, 870, 0, 0, 1, 0,0, 0, 0, 702.3976, 2161.417, 325.8164, 1.038547, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+767, 58992, 870, 0, 0, 1, 0,0, 0, 0, 700.1754, 2004.696, 325.5174, 4.380776, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+768, 58449, 870, 0, 0, 1, 0,0, 0, 0, 753.6129, 2043.325, 319.0481, 3.670398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Wooly Yak (Area: Gate of the Setting Sun)
(@CGUID+769, 62143, 870, 0, 0, 1, 0,0, 0, 0, 658.8411, 2140.153, 325.869, 6.26739, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Hatchling (Area: Gate of the Setting Sun)
(@CGUID+770, 58992, 870, 0, 0, 1, 0,0, 0, 0, 689.1788, 2004.247, 325.5174, 5.009095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+771, 62077, 870, 0, 0, 1, 0,0, 0, 0, 659.8594, 2132.91, 326.7957, 5.139526, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Egg (Area: Gate of the Setting Sun)
(@CGUID+772, 63497, 870, 0, 0, 1, 0,0, 0, 0, 610.0486, 2120.95, 368.1391, 1.916121, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Mai of the Wall (Area: Gate of the Setting Sun)
(@CGUID+773, 62143, 870, 0, 0, 1, 0,0, 0, 0, 661.611, 2140.357, 326.0363, 3.215063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Hatchling (Area: Gate of the Setting Sun)
(@CGUID+774, 65172, 870, 0, 0, 1, 0,0, 0, 0, 617.0347, 2120.123, 368.1391, 1.309094, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Len at Arms (Area: Gate of the Setting Sun)
(@CGUID+775, 61968, 870, 0, 0, 1, 0,0, 0, 0, 707.7899, 2154.962, 400.2479, 3.18957, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Marksman (Area: Gate of the Setting Sun)
(@CGUID+776, 58992, 870, 0, 0, 1, 0,0, 0, 0, 681.6493, 2004.111, 325.5174, 5.358161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+777, 57444, 870, 0, 0, 1, 0,0, 0, 0, 770.1795, 2070.68, 356.7887, 0.9496652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent Rider (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded, 130792 - HMC Dummy Effect Periodic Aura A)
(@CGUID+778, 61968, 870, 0, 0, 1, 0,0, 0, 0, 633.0486, 2138.523, 370.2616, 1.743476, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Marksman (Area: Gate of the Setting Sun)
(@CGUID+779, 63841, 870, 0, 0, 1, 0,0, 0, 0, 763.4343, 2102.423, 328.1765, 1.971097, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Golden Civet (Area: Gate of the Setting Sun)
(@CGUID+780, 58448, 870, 0, 0, 1, 0,0, 0, 0, 629.7621, 2045.283, 349.8982, 3.839724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Black Bengal Goat (Area: Gate of the Setting Sun)
(@CGUID+781, 67004, 870, 0, 0, 1, 0,0, 0, 0, 736.1702, 2017.439, 316.6101, 5.319618, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+782, 58992, 870, 0, 0, 1, 0,0, 0, 0, 703.9045, 2000.465, 325.5174, 4.08407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+783, 58992, 870, 0, 0, 1, 0,0, 0, 0, 680.4601, 1998.436, 325.5174, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+784, 62143, 870, 0, 0, 1, 0,0, 0, 0, 647.7246, 2148.533, 325.7513, 5.050745, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Hatchling (Area: Gate of the Setting Sun)
(@CGUID+785, 67004, 870, 0, 0, 1, 0,0, 0, 0, 732.8055, 2017.74, 316.6101, 5.53548, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+786, 58992, 870, 0, 0, 1, 0,0, 0, 0, 693.625, 2001.821, 325.5174, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+787, 61968, 870, 0, 0, 1, 0,0, 0, 0, 614.5121, 2139.628, 370.2602, 1.443744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Marksman (Area: Gate of the Setting Sun)
(@CGUID+788, 62077, 870, 0, 0, 1, 0,0, 0, 0, 644.8594, 2146.998, 325.8164, 4.48388, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Egg (Area: Gate of the Setting Sun)
(@CGUID+789, 67004, 870, 0, 0, 1, 0,0, 0, 0, 730.2136, 2013.875, 316.6054, 5.882375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+790, 58731, 870, 0, 0, 1, 0,0, 0, 0, 745.3785, 2022.373, 316.5384, 4.923487, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+791, 58992, 870, 0, 0, 1, 0,0, 0, 0, 710.0399, 2000.856, 325.5174, 3.857178, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+792, 58731, 870, 0, 0, 1, 0,0, 0, 0, 736.3646, 2020.498, 316.6101, 5.158413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+793, 61968, 870, 0, 0, 1, 0,0, 0, 0, 707.7309, 2174.286, 394.66, 3.18957, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Marksman (Area: Gate of the Setting Sun)
(@CGUID+794, 58505, 870, 0, 0, 1, 0,0, 0, 0, 715.5851, 2003.403, 325.5174, 3.478615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Golden Lotus Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+795, 58992, 870, 0, 0, 1, 0,0, 0, 0, 678.7708, 2002.252, 325.5174, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+796, 58731, 870, 0, 0, 1, 0,0, 0, 0, 733.3854, 2014.601, 316.6034, 5.730264, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+797, 67004, 870, 0, 0, 1, 0,0, 0, 0, 740.6354, 2021.865, 316.6101, 4.921476, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+798, 61981, 870, 0, 0, 1, 0,0, 0, 0, 701.7344, 2173.96, 325.8235, 5.350321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Tender (Area: Gate of the Setting Sun) (Auras: 70628 - Permanent Feign Death)
(@CGUID+799, 67004, 870, 0, 0, 1, 0,0, 0, 0, 739.5139, 2019.108, 316.6101, 5.022001, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+800, 58505, 870, 0, 0, 1, 0,0, 0, 0, 721.4809, 1991.915, 325.517, 3.500773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Golden Lotus Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+801, 58994, 870, 0, 0, 1, 0,0, 0, 0, 694.4202, 1987.3, 325.5174, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Battle Ring Controller (Area: Gate of the Setting Sun)
(@CGUID+802, 58992, 870, 0, 0, 1, 0,0, 0, 0, 711.3924, 1996.944, 325.5174, 3.647738, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+803, 58731, 870, 0, 0, 1, 0,0, 0, 0, 760.6493, 2027.457, 316.16, 2.405218, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+804, 58992, 870, 0, 0, 1, 0,0, 0, 0, 710.6146, 1986.797, 325.5174, 3.106686, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+805, 62143, 870, 0, 0, 1, 0,0, 0, 0, 644.791, 2158.333, 325.6263, 2.038989, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Hatchling (Area: Gate of the Setting Sun)
(@CGUID+806, 60931, 870, 0, 0, 1, 0,0, 0, 0, 776.1007, 2043.01, 316.1573, 4.852327, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+807, 60931, 870, 0, 0, 1, 0,0, 0, 0, 773.2934, 2042.406, 316.1573, 4.620387, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+808, 53714, 870, 0, 0, 1, 0,0, 0, 0, 773.2222, 2042.691, 316.1573, 6.074687, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+809, 53714, 870, 0, 0, 1, 0,0, 0, 0, 758.2483, 2029.568, 316.2283, 0.4359062, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+810, 62077, 870, 0, 0, 1, 0,0, 0, 0, 642.0121, 2149.372, 325.8164, 5.139526, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner Egg (Area: Gate of the Setting Sun)
(@CGUID+811, 58731, 870, 0, 0, 1, 0,0, 0, 0, 773.2708, 2039.743, 316.1573, 1.527657, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+812, 58743, 870, 0, 0, 1, 0,0, 0, 0, 740.9792, 2012.915, 316.5772, 2.056908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Yumi Goldenpaw (Area: Gate of the Setting Sun)
(@CGUID+813, 58731, 870, 0, 0, 1, 0,0, 0, 0, 743.2656, 2019.632, 316.58, 4.600669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+814, 58992, 870, 0, 0, 1, 0,0, 0, 0, 714.6215, 1993.233, 325.5174, 3.420845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+815, 58992, 870, 0, 0, 1, 0,0, 0, 0, 674.6875, 1988.729, 325.5174, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+816, 53714, 870, 0, 0, 1, 0,0, 0, 0, 775.9479, 2043.274, 316.1573, 0.01609934, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+817, 58992, 870, 0, 0, 1, 0,0, 0, 0, 712.9236, 1990.293, 325.5174, 3.298672, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+818, 53714, 870, 0, 0, 1, 0,0, 0, 0, 760.0764, 2031.675, 316.3264, 0.6605044, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+819, 58992, 870, 0, 0, 1, 0,0, 0, 0, 674.7066, 1984.832, 325.5174, 0.1047198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+820, 58992, 870, 0, 0, 1, 0,0, 0, 0, 676.1979, 1992.504, 325.5174, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+821, 63973, 870, 0, 0, 1, 0,0, 0, 0, 746.5385, 2123.788, 464.9616, 4.78141, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+822, 60931, 870, 0, 0, 1, 0,0, 0, 0, 758.4965, 2029.439, 316.2413, 5.53414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Training Target (Area: Gate of the Setting Sun)
(@CGUID+823, 63976, 870, 0, 0, 1, 0,0, 0, 0, 792.441, 2226.13, 376.1818, 6.242296, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Needler (Area: Gate of the Setting Sun) (Auras: 138393 - Blue Mantid Wings, 132441 - Mantid Wings)
(@CGUID+824, 63973, 870, 0, 0, 1, 0,0, 0, 0, 863.6274, 2155.66, 395.1134, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+825, 63973, 870, 0, 0, 1, 0,0, 0, 0, 760.712, 2125.291, 464.9684, 4.781411, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+826, 58505, 870, 0, 0, 1, 0,0, 0, 0, 785.5989, 2051.281, 316.2177, 0.6482624, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Golden Lotus Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+827, 63973, 870, 0, 0, 1, 0,0, 0, 0, 774.1471, 2222.354, 438.8806, 3.770814, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+828, 63973, 870, 0, 0, 1, 0,0, 0, 0, 633.0428, 2235.149, 442.0807, 2.319779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+829, 58449, 870, 0, 0, 1, 0,0, 0, 0, 783.6788, 2066.137, 316.2278, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Wooly Yak (Area: Gate of the Setting Sun)
(@CGUID+830, 63973, 870, 0, 0, 1, 0,0, 0, 0, 813.4222, 2151.695, 390.1884, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+831, 63973, 870, 0, 0, 1, 0,0, 0, 0, 831.1331, 2126.144, 415.9905, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+832, 65336, 870, 0, 0, 1, 0,0, 0, 0, 832.4965, 2087.599, 315.9681, 4.021967, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- War Serpent (Area: Gate of the Setting Sun)
(@CGUID+833, 63973, 870, 0, 0, 1, 0,0, 0, 0, 863.433, 2118.673, 411.3624, 4.781408, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+834, 58505, 870, 0, 0, 1, 0,0, 0, 0, 787.1476, 2052.238, 316.2292, 3.923385, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Golden Lotus Defender (Area: Gate of the Setting Sun) (Auras: )
(@CGUID+835, 63973, 870, 0, 0, 1, 0,0, 0, 0, 650.809, 2223.156, 429.4743, 4.781409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+836, 58449, 870, 0, 0, 1, 0,0, 0, 0, 787.3281, 2070.365, 316.2268, 3.839724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Wooly Yak (Area: Gate of the Setting Sun)
(@CGUID+837, 63973, 870, 0, 0, 1, 0,0, 0, 0, 813.306, 2215.192, 420.3219, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+838, 63973, 870, 0, 0, 1, 0,0, 0, 0, 790.559, 2577.734, 449.5804, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+839, 63973, 870, 0, 0, 1, 0,0, 0, 0, 816.7069, 2095.434, 392.3065, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+840, 57444, 870, 0, 0, 1, 0,0, 0, 0, 858.5362, 2092.475, 394.4728, 2.126697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Serpent Rider (Area: Gate of the Setting Sun) (Auras: 46598 - Ride Vehicle Hardcoded, 130792 - HMC Dummy Effect Periodic Aura A)
(@CGUID+841, 63973, 870, 0, 0, 1, 0,0, 0, 0, 645.9813, 2257.042, 423.283, 4.781403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+842, 67004, 870, 0, 0, 1, 0,0, 0, 0, 776.6979, 2040.41, 316.1573, 1.759597, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Aspiring Trainee (Area: Gate of the Setting Sun)
(@CGUID+843, 58992, 870, 0, 0, 1, 0,0, 0, 0, 715.0868, 1983.707, 325.5174, 2.96706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Shado-Pan Trainee (Area: Gate of the Setting Sun)
(@CGUID+844, 63973, 870, 0, 0, 1, 0,0, 0, 0, 867.3831, 2151.971, 394.782, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+845, 63973, 870, 0, 0, 1, 0,0, 0, 0, 795.2042, 2232.167, 438.8283, 3.968619, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+846, 63973, 870, 0, 0, 1, 0,0, 0, 0, 803.582, 2243.571, 421.8972, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+847, 62000, 870, 0, 0, 1, 0,0, 0, 0, 652.0925, 2146.51, 326.0292, 0.7777289, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner (Area: Gate of the Setting Sun) (Auras: 52391 - Ride Vehicle)
(@CGUID+848, 63973, 870, 0, 0, 1, 0,0, 0, 0, 664.5811, 2270.418, 424.8396, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+849, 63973, 870, 0, 0, 1, 0,0, 0, 0, 838.7955, 2192.508, 416.5003, 4.781405, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+850, 63973, 870, 0, 0, 1, 0,0, 0, 0, 658.2312, 2248.675, 427.8449, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+851, 63973, 870, 0, 0, 1, 0,0, 0, 0, 649.3109, 2242.361, 419.4598, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+852, 63973, 870, 0, 0, 1, 0,0, 0, 0, 839.7849, 2183.555, 396.7134, 4.781408, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+853, 63973, 870, 0, 0, 1, 0,0, 0, 0, 638.2216, 2225.23, 420.7003, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+854, 63973, 870, 0, 0, 1, 0,0, 0, 0, 654.6544, 2273.442, 424.8608, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+855, 63973, 870, 0, 0, 1, 0,0, 0, 0, 664.7048, 2255.803, 422.9639, 4.781404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+856, 63973, 870, 0, 0, 1, 0,0, 0, 0, 671.2526, 2271.56, 423.572, 4.78141, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+857, 63973, 870, 0, 0, 1, 0,0, 0, 0, 785.5549, 2221.375, 444.1289, 3.846117, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+858, 63973, 870, 0, 0, 1, 0,0, 0, 0, 639.0376, 2245.2, 425.5849, 4.781409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+859, 63973, 870, 0, 0, 1, 0,0, 0, 0, 670.9864, 2241.366, 420.0759, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+860, 63973, 870, 0, 0, 1, 0,0, 0, 0, 635.9111, 2244.754, 420.3707, 4.781406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+861, 63973, 870, 0, 0, 1, 0,0, 0, 0, 832.2422, 2199.158, 400.514, 4.781408, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+862, 63973, 870, 0, 0, 1, 0,0, 0, 0, 791.0431, 2238.064, 452.2161, 3.943969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+863, 63973, 870, 0, 0, 1, 0,0, 0, 0, 828.5349, 2214.14, 402.7011, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+864, 63973, 870, 0, 0, 1, 0,0, 0, 0, 682.8423, 2241.536, 456.8488, 4.781407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
(@CGUID+865, 62000, 870, 0, 0, 1, 0,0, 0, 0, 687.3041, 2142.198, 327.8401, 0.2006529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463), -- Dreadspinner (Area: Gate of the Setting Sun)
(@CGUID+866, 63973, 870, 0, 0, 1, 0,0, 0, 0, 863.7463, 2144.875, 411.5997, 4.781408, 120, 0, 0, 0, 0, 0, 0, 0, 0, 21463); -- Krik'thik Swarmer (Area: Gate of the Setting Sun)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+866;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+1, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+2, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+3, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+4, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+5, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+6, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+7, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+8, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+9, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+10, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+11, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+12, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+13, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+14, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+15, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+16, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+17, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+18, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+19, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+20, 0, 0, 0, 1, 0, '123978'), -- Krik'thik Infiltrator - 123978 - Mod Scale 95-120%
(@CGUID+21, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+22, 0, 0, 0, 1, 0, '123978'), -- Krik'thik Infiltrator - 123978 - Mod Scale 95-120%
(@CGUID+23, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+24, 0, 0, 0, 1, 0, '123978'), -- Krik'thik Infiltrator - 123978 - Mod Scale 95-120%
(@CGUID+25, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+26, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+27, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+28, 0, 0, 0, 2, 0, '120856'), -- Bowmistress Li - 120856 - Pandaren Arrows 01 Stack
(@CGUID+29, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+30, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+31, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+32, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+33, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+34, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+35, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+36, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+37, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+38, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+39, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+40, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+41, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+42, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+43, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+44, 0, 0, 0, 1, 0, '123978'), -- Serpent's Spine Defender - 123978 - Mod Scale 95-120%
(@CGUID+45, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+47, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+48, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+49, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+50, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+51, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+52, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+53, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+54, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+55, 0, 0, 0, 1, 0, '126316 132441'), -- Saboteur Kip'tilak - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+56, 0, 0, 0, 1, 0, ''), -- Great Wall Explosion Target Stalker 1
(@CGUID+57, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+58, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombadier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+59, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+60, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+61, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+62, 0, 0, 50331648, 1, 0, ''), -- Mantid Infiltrator Rope Stalker
(@CGUID+63, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+64, 0, 0, 0, 2, 0, ''), -- Panda Tar Tosser
(@CGUID+65, 0, 0, 50331648, 1, 0, ''), -- Mantid Infiltrator Rope Stalker
(@CGUID+66, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+67, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+68, 0, 0, 50331648, 1, 0, ''), -- Mantid Infiltrator Rope Stalker
(@CGUID+69, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+70, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+71, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+72, 0, 0, 0, 2, 0, ''), -- Panda Tar Tosser
(@CGUID+73, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+74, 0, 0, 0, 2, 0, ''), -- Panda Tar Tosser
(@CGUID+75, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+76, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+77, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+78, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+79, 0, 0, 0, 2, 0, ''), -- Panda Tar Tosser
(@CGUID+80, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+81, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+82, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+83, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+84, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+85, 0, 0, 0, 1, 0, '123463'), -- Cosmetic Client Stalker - 123463 - Mantid Army
(@CGUID+86, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+87, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+88, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+89, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+90, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+91, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+92, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+93, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+94, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+95, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+96, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+97, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+98, 0, 0, 0, 1, 0, '46598'), -- Panda Archer Target Gate Stalker - 46598 - Ride Vehicle Hardcoded
(@CGUID+99, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+100, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+101, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+102, 0, 0, 0, 1, 0, '115421'), -- Krik'thik Wind Shaper - 115421 - Gale Force
(@CGUID+103, 0, 0, 0, 1, 0, ''), -- Krik'thik Rager
(@CGUID+104, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+105, 0, 0, 0, 1, 0, ''), -- Great Wall Explosion Caster Stalker
(@CGUID+106, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+107, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+108, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+109, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+110, 0, 0, 0, 1, 0, ''), -- Krik'thik Infiltrator
(@CGUID+111, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+112, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+113, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+114, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+115, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+116, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+117, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+118, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+119, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+120, 0, 0, 50331648, 1, 0, '128667'), -- Serpent's Spine Defender - 128667 - Self On Fire
(@CGUID+121, 0, 0, 50331648, 1, 0, '128667'), -- Serpent's Spine Defender - 128667 - Self On Fire
(@CGUID+122, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+123, 0, 0, 0, 1, 0, ''), -- Great Wall Explosion Target Stalker 2
(@CGUID+124, 0, 0, 0, 1, 0, ''), -- Great Wall Explosion Target Stalker 3
(@CGUID+125, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+126, 0, 0, 0, 1, 0, ''), -- Great Wall Explosion Caster Stalker
(@CGUID+127, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+128, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+129, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombadier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+130, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombadier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+131, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+132, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+133, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+134, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombadier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+135, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+136, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+137, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+138, 0, 0, 0, 2, 0, ''), -- Courtyard Defender
(@CGUID+139, 0, 0, 50331648, 1, 0, '128667'), -- Serpent's Spine Defender - 128667 - Self On Fire
(@CGUID+140, 0, 0, 0, 1, 0, '115141'), -- Great Wall Panda Archer Target Spawner - 115141 - Creature Spawner - Flying Mantids
(@CGUID+141, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+142, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+143, 0, 0, 0, 1, 0, '92406'), -- Flak Cannon - 92406 - Cosmetic - Loot Sparkles (3.00)
(@CGUID+144, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+145, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+146, 0, 0, 0, 1, 0, '92406'), -- Flak Cannon - 92406 - Cosmetic - Loot Sparkles (3.00)
(@CGUID+147, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+148, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+149, 0, 0, 0, 1, 0, '123978'), -- Krik'thik Demolisher - 123978 - Mod Scale 95-120%
(@CGUID+150, 0, 0, 0, 1, 0, '127498'), -- Krik'thik Sapper - 127498 - Mod Scale 105-110%
(@CGUID+151, 0, 0, 0, 1, 0, '123978'), -- Krik'thik Demolisher - 123978 - Mod Scale 95-120%
(@CGUID+152, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+153, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+154, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+155, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+156, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+157, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+158, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+159, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+160, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+161, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+162, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+163, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+164, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+165, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+166, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+167, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+168, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+169, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+170, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+171, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+172, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+173, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+174, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+175, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+176, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+177, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+178, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+179, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+180, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+181, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+182, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+183, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+184, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+185, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+186, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+187, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+188, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+189, 0, 0, 50331648, 1, 0, '126316 132441'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings, 132441 - Mantid Wings
(@CGUID+190, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+191, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+192, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+193, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+194, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+195, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+196, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+197, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+198, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+199, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+200, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+201, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+202, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+203, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+204, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+205, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+206, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+207, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+208, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+209, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+210, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+211, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+212, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+213, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+214, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+215, 0, 0, 0, 1, 0, '127498'), -- Krik'thik Sapper - 127498 - Mod Scale 105-110%
(@CGUID+216, 0, 0, 50331648, 1, 0, '126316'), -- Krik'thik Glider - 126316 - Green Mantid Wings
(@CGUID+217, 0, 0, 0, 1, 0, '123978'), -- Krik'thik Demolisher - 123978 - Mod Scale 95-120%
(@CGUID+218, 0, 0, 0, 1, 0, '127498'), -- Krik'thik Sapper - 127498 - Mod Scale 105-110%
(@CGUID+219, 0, 0, 50331648, 1, 0, '126316'), -- Krik'thik Glider - 126316 - Green Mantid Wings
(@CGUID+220, 0, 0, 50331648, 1, 0, '126316'), -- Krik'thik Glider - 126316 - Green Mantid Wings
(@CGUID+221, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+222, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+223, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+224, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+225, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+226, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+227, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+228, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+229, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+230, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+231, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+232, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+233, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+234, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+235, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+236, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+237, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+238, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+239, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+240, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+241, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+242, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+243, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+244, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+245, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+246, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+247, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+248, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+249, 0, 0, 0, 1, 0, '46598'); -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+251, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+252, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+253, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+254, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+255, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+256, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+257, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+258, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+259, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+260, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+261, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+262, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+263, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+264, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+265, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+266, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+267, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+268, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+269, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+270, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+271, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+272, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+273, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+274, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+275, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+276, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+277, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+278, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+279, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+280, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+281, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+282, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+283, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+284, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+285, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+286, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+287, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+288, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+289, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+290, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+291, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+292, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+293, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+294, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+295, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+296, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+297, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+298, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+299, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+300, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+301, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+302, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+303, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+304, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+305, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+306, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+307, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+308, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+309, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+310, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+311, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+312, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+313, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+314, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+315, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+316, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+317, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+318, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+319, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+320, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+321, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+322, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+323, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+324, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+325, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+326, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+327, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+328, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+329, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+330, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+331, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+332, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+333, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+334, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+335, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+336, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+337, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+338, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+339, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+340, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+341, 0, 0, 0, 1, 0, ''), -- Great Wall Bonfire Target Stalker 1
(@CGUID+342, 0, 0, 0, 1, 0, ''), -- Great Wall Bonfire Caster Stalker
(@CGUID+343, 0, 0, 0, 1, 0, ''), -- Panda Archer Target Stalker
(@CGUID+344, 0, 0, 0, 1, 0, '111672 96733'), -- Serpent's Spine Marksman - 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun)
(@CGUID+345, 0, 0, 50331648, 1, 0, '124677'), -- Great Wall Bonfire Target Stalker 2 - 124677 - Great Wall Bonfire Dummy Flame
(@CGUID+346, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+347, 0, 0, 0, 1, 0, '111672 96733'), -- Serpent's Spine Marksman - 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun)
(@CGUID+348, 0, 0, 0, 1, 0, '111672 96733'), -- Serpent's Spine Marksman - 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun)
(@CGUID+349, 0, 0, 0, 1, 0, '111672 96733'), -- Serpent's Spine Marksman - 111672 - Resurrect Requirement, 96733 - Permanent Feign Death (Stun)
(@CGUID+350, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+351, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+352, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+353, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+354, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+355, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+356, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+357, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+358, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+359, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+360, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+361, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Marksman
(@CGUID+362, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+363, 0, 0, 0, 1, 0, ''), -- Krik'thik Infiltrator
(@CGUID+364, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+365, 0, 0, 0, 1, 0, ''), -- Krik'thik Infiltrator
(@CGUID+366, 0, 0, 0, 1, 0, ''), -- Krik'thik Infiltrator
(@CGUID+367, 0, 0, 0, 1, 0, ''), -- Krik'thik Wind Shaper
(@CGUID+368, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+369, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+370, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+371, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+372, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+373, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+374, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+375, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+376, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+377, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+378, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+379, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+380, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+381, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+382, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+383, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+384, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+385, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+386, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+387, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+388, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+389, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+390, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+391, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+392, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+393, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+394, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+395, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+396, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+397, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+398, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+399, 0, 0, 0, 1, 0, '46598'), -- Serpent's Spine Cannoneer - 46598 - Ride Vehicle Hardcoded
(@CGUID+400, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+401, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+402, 0, 0, 0, 1, 0, ''), -- Boss 2 South Stalker
(@CGUID+403, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+404, 0, 0, 0, 1, 0, ''), -- Flak Cannon Target Stalker
(@CGUID+405, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+406, 0, 0, 0, 1, 0, ''), -- Boss 2 North/South Strafe Stalkers
(@CGUID+407, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+408, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+409, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+410, 0, 0, 0, 1, 0, ''), -- Boss 2 North/South Strafe Stalkers
(@CGUID+411, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+412, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+413, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+414, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+415, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+416, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+417, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+418, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+419, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+420, 0, 0, 0, 1, 0, ''), -- Boss 2 North/South Strafe Stalkers
(@CGUID+421, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+422, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+423, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+424, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+425, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+426, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+427, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+428, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+429, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+430, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+431, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+432, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+433, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+434, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+435, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+436, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+437, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+438, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+439, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+440, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+441, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+442, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+443, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+444, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+445, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+446, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+447, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+448, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+449, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+450, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+451, 0, 0, 0, 1, 0, ''), -- Boss 2 West Stalker
(@CGUID+452, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+453, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+454, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+455, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+456, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+457, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+458, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+459, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+460, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Cannoneer
(@CGUID+461, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+462, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+463, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+464, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+465, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+466, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+467, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+468, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+469, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+470, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+471, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+472, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+473, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+474, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+475, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+476, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+477, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+478, 0, 0, 8, 1, 0, ''), -- Serpent's Spine Cannoneer
(@CGUID+479, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+480, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+481, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+482, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+483, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+484, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+485, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+486, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+487, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+488, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+489, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+490, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+491, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+492, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+493, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+494, 0, 0, 0, 1, 0, ''), -- Boss 2 East Stalker
(@CGUID+495, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+496, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+497, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+498, 0, 0, 8, 1, 0, ''), -- Serpent's Spine Cannoneer
(@CGUID+499, 0, 0, 0, 1, 0, '116298'); -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+501, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+502, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+503, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+504, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+505, 0, 0, 1, 1, 0, ''), -- Serpent's Spine Cannoneer
(@CGUID+506, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+507, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+508, 0, 0, 0, 1, 0, ''), -- Flak Cannon Target Stalker
(@CGUID+509, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+510, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+511, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+512, 0, 0, 0, 1, 0, ''), -- Flak Cannon Target Stalker
(@CGUID+513, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+514, 0, 0, 0, 1, 0, ''), -- Flak Cannon Target Stalker
(@CGUID+515, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+516, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+517, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+518, 0, 0, 0, 1, 0, ''), -- Flak Cannon Target Stalker
(@CGUID+519, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+520, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Defender
(@CGUID+521, 0, 0, 0, 1, 0, ''), -- Serpent's Spine Trainee
(@CGUID+522, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+523, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+524, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+525, 0, 0, 0, 1, 0, ''), -- Flak Cannon Target Stalker
(@CGUID+526, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+527, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+528, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+529, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+530, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+531, 0, 0, 0, 1, 0, '116298'), -- Boss 2 West/East Strafe Stalkers - 116298 - Strafing Run
(@CGUID+532, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+533, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+534, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+535, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+536, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+537, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+538, 0, 0, 0, 1, 0, ''), -- Boss 2 North Stalker
(@CGUID+539, 0, 0, 0, 1, 0, '116621'), -- Boss 3 Encounter Add Generator - 116621 - Great Wall Boss 3 Big Add Spawn Periodic Trigger
(@CGUID+540, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+541, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+542, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+543, 0, 0, 0, 1, 0, '115052'), -- Boss 3 Encounter Add Generator - 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger
(@CGUID+544, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+545, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+546, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+547, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+548, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+549, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+550, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+551, 0, 0, 0, 1, 0, '115052'), -- Boss 3 Encounter Add Generator - 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger
(@CGUID+552, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+553, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+554, 0, 0, 0, 1, 0, '115052'), -- Boss 3 Encounter Add Generator - 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger
(@CGUID+555, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+556, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+557, 0, 0, 0, 1, 0, '116298'), -- Boss 2 North/South Strafe Stalkers - 116298 - Strafing Run
(@CGUID+558, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+559, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+560, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+561, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+562, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+563, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+564, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+565, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+566, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+567, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+568, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+569, 0, 0, 0, 1, 0, '115052'), -- Boss 3 Encounter Add Generator - 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger
(@CGUID+570, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+571, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+572, 0, 0, 0, 1, 0, '115052'), -- Boss 3 Encounter Add Generator - 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger
(@CGUID+573, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+574, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+575, 0, 0, 0, 1, 0, '115052'), -- Boss 3 Encounter Add Generator - 115052 - Great Wall Boss 3 Add Spawn Periodic Trigger
(@CGUID+576, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+577, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+578, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+579, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+580, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+581, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+582, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+583, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+584, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+585, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+586, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+587, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+588, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+589, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+590, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+591, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+592, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+593, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+594, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+595, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+596, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+597, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+598, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Invader - 46598 - Ride Vehicle Hardcoded
(@CGUID+599, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Rager - 46598 - Ride Vehicle Hardcoded
(@CGUID+600, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Wind Shaper - 46598 - Ride Vehicle Hardcoded
(@CGUID+601, 0, 0, 0, 1, 0, '46598'), -- Krik'thik Rager - 46598 - Ride Vehicle Hardcoded
(@CGUID+602, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+603, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+604, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+605, 0, 0, 0, 1, 0, '106875'), -- Flying Mantid Bombing Stalker - 106875 - Fire Bomb
(@CGUID+606, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+607, 0, 0, 0, 1, 0, ''), -- Flying Mantid Bombing Stalker
(@CGUID+608, 0, 0, 0, 1, 0, ''), -- "Lighting the Way" Kill Credit
(@CGUID+609, 0, 0, 50331648, 1, 0, ''), -- Bonfire Teleport Stalker
(@CGUID+610, 0, 0, 50331648, 1, 0, '126316'), -- Krik'thik Bombardier - 126316 - Green Mantid Wings
(@CGUID+611, 0, 0, 50331648, 1, 0, '126316'), -- Krik'thik Disruptor - 126316 - Green Mantid Wings
(@CGUID+612, 0, 0, 50331648, 1, 0, '126316'), -- Krik'thik Disruptor - 126316 - Green Mantid Wings
(@CGUID+613, 0, 0, 50331648, 1, 0, '138393'), -- Krik'thik Striker - 138393 - Blue Mantid Wings
(@CGUID+614, 0, 0, 50331648, 1, 0, '138393'), -- Krik'thik Striker - 138393 - Blue Mantid Wings
(@CGUID+615, 0, 0, 50331648, 1, 0, '138393'), -- Krik'thik Striker - 138393 - Blue Mantid Wings
(@CGUID+616, 0, 0, 50331648, 1, 0, '138393'), -- Krik'thik Striker - 138393 - Blue Mantid Wings
(@CGUID+617, 0, 0, 0, 1, 0, '115430'), -- Krik'thik Rager - 115430 - Enrage
(@CGUID+618, 0, 0, 0, 1, 0, ''), -- Krik'thik Rager
(@CGUID+619, 0, 0, 0, 1, 0, ''), -- Commander Ri'mok
(@CGUID+620, 0, 0, 0, 1, 0, ''), -- Krik'thik Wind Shaper
(@CGUID+621, 0, 0, 0, 1, 0, ''), -- Krik'thik Rager
(@CGUID+622, 0, 0, 0, 1, 0, '115421'), -- Krik'thik Wind Shaper - 115421 - Gale Force
(@CGUID+623, 0, 0, 0, 1, 0, ''), -- Krik'thik Rager
(@CGUID+624, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+625, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+626, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+627, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+628, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+629, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+630, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+631, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+632, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+633, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+634, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+635, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+636, 0, 0, 0, 1, 0, ''), -- Krik'thik Conscript
(@CGUID+637, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+638, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+639, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+640, 0, 0, 0, 1, 0, ''), -- Pandaren Disciple
(@CGUID+641, 0, 0, 0, 1, 0, ''), -- Krik'thik Conscript
(@CGUID+642, 0, 0, 0, 1, 0, ''), -- Krik'thik Conscript
(@CGUID+643, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+644, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+645, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+646, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+647, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+648, 0, 0, 0, 1, 0, '126493'), -- Rope - 126493 - Rope Visual
(@CGUID+649, 0, 0, 0, 1, 0, '126493'), -- Rope - 126493 - Rope Visual
(@CGUID+650, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+651, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+652, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+653, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+654, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+655, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+656, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+657, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+658, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+659, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+660, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+661, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+662, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+663, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+664, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+665, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+666, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+667, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+668, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+669, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+670, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+671, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+672, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+673, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+674, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+675, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+676, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+677, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+678, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+679, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+680, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+681, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+682, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+683, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+684, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+685, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+686, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+687, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+688, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+689, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+690, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+691, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+692, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+693, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+694, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+695, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+696, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+697, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+698, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+699, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+700, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+701, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+702, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+703, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+704, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+705, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+706, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+707, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+708, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+709, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+710, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+711, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+712, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+713, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+714, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+715, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+716, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+717, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+718, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+719, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+720, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+721, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+722, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+723, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+724, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+725, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+726, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+727, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+728, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+729, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+730, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+731, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+732, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+733, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+734, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+735, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+736, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+737, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+738, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+739, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+740, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+741, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+742, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+743, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+744, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+745, 0, 0, 0, 1, 0, ''), -- Pandaren Cannoneer
(@CGUID+746, 0, 0, 0, 2, 0, '120856'), -- Bowmistress Li - 120856 - Pandaren Arrows 01 Stack
(@CGUID+747, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+748, 0, 0, 0, 1, 0, '52391'), -- Dreadspinner - 52391 - Ride Vehicle
(@CGUID+749, 0, 0, 0, 1, 0, '70628'); -- Dreadspinner Tender - 70628 - Permanent Feign Death

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+750, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+751, 0, 0, 0, 2, 0, ''), -- Shado-Pan Marksman
(@CGUID+752, 0, 0, 0, 2, 0, '120856'), -- Bowmistress Li - 120856 - Pandaren Arrows 01 Stack
(@CGUID+753, 0, 0, 0, 1, 0, '52391 120685'), -- Dreadspinner - 52391 - Ride Vehicle, 120685 - Shoot Me Aura
(@CGUID+754, 0, 0, 0, 1, 0, '127358 70628'), -- Dreadspinner Tender - 127358 - Seek and Destroy, 70628 - Permanent Feign Death
(@CGUID+755, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+756, 0, 0, 0, 2, 0, ''), -- Shado-Pan Marksman
(@CGUID+757, 0, 0, 0, 1, 0, ''), -- Black Bengal Goat
(@CGUID+758, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+759, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+760, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+761, 0, 0, 0, 1, 0, ''), -- Black Bengal Goat
(@CGUID+762, 0, 0, 0, 1, 0, ''), -- General Purpose Bunny (DLA)
(@CGUID+763, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+764, 0, 0, 0, 1, 0, ''), -- Dreadspinner Egg
(@CGUID+765, 0, 0, 0, 1, 0, ''), -- Dreadspinner
(@CGUID+766, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+767, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+768, 0, 0, 0, 1, 0, ''), -- Wooly Yak
(@CGUID+769, 0, 0, 0, 1, 0, ''), -- Dreadspinner Hatchling
(@CGUID+770, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+771, 0, 0, 0, 1, 0, ''), -- Dreadspinner Egg
(@CGUID+772, 0, 0, 0, 1, 0, ''), -- Mai of the Wall
(@CGUID+773, 0, 0, 0, 1, 0, ''), -- Dreadspinner Hatchling
(@CGUID+774, 0, 0, 0, 1, 0, ''), -- Len at Arms
(@CGUID+775, 0, 0, 0, 2, 0, ''), -- Shado-Pan Marksman
(@CGUID+776, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+777, 0, 0, 0, 1, 0, '46598 130792'), -- Serpent Rider - 46598 - Ride Vehicle Hardcoded, 130792 - HMC Dummy Effect Periodic Aura A
(@CGUID+778, 0, 0, 0, 2, 0, ''), -- Shado-Pan Marksman
(@CGUID+779, 0, 0, 0, 1, 0, ''), -- Golden Civet
(@CGUID+780, 0, 0, 0, 1, 0, ''), -- Black Bengal Goat
(@CGUID+781, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+782, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+783, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+784, 0, 0, 0, 1, 0, ''), -- Dreadspinner Hatchling
(@CGUID+785, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+786, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+787, 0, 0, 0, 2, 0, ''), -- Shado-Pan Marksman
(@CGUID+788, 0, 0, 0, 1, 0, ''), -- Dreadspinner Egg
(@CGUID+789, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+790, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+791, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+792, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+793, 0, 0, 0, 2, 0, ''), -- Shado-Pan Marksman
(@CGUID+794, 0, 0, 0, 256, 0, ''), -- Golden Lotus Defender
(@CGUID+795, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+796, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+797, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+798, 0, 0, 0, 1, 0, '70628'), -- Dreadspinner Tender - 70628 - Permanent Feign Death
(@CGUID+799, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+800, 0, 0, 0, 256, 0, ''), -- Golden Lotus Defender
(@CGUID+801, 0, 0, 0, 1, 0, ''), -- Battle Ring Controller
(@CGUID+802, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+803, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+804, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+805, 0, 0, 0, 1, 0, ''), -- Dreadspinner Hatchling
(@CGUID+806, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+807, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+808, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+809, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+810, 0, 0, 0, 1, 0, ''), -- Dreadspinner Egg
(@CGUID+811, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+812, 0, 0, 0, 1, 0, ''), -- Yumi Goldenpaw
(@CGUID+813, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+814, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+815, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+816, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+817, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+818, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+819, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+820, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+821, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+822, 0, 0, 0, 1, 0, ''), -- Training Target
(@CGUID+823, 0, 0, 50331648, 1, 0, '138393 132441'), -- Krik'thik Needler - 138393 - Blue Mantid Wings, 132441 - Mantid Wings
(@CGUID+824, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+825, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+826, 0, 0, 0, 256, 0, ''), -- Golden Lotus Defender
(@CGUID+827, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+828, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+829, 0, 0, 0, 1, 0, ''), -- Wooly Yak
(@CGUID+830, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+831, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+832, 0, 0, 0, 1, 0, ''), -- War Serpent
(@CGUID+833, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+834, 0, 0, 0, 256, 0, ''), -- Golden Lotus Defender
(@CGUID+835, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+836, 0, 0, 0, 1, 0, ''), -- Wooly Yak
(@CGUID+837, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+838, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+839, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+840, 0, 0, 0, 1, 0, '46598 130792'), -- Serpent Rider - 46598 - Ride Vehicle Hardcoded, 130792 - HMC Dummy Effect Periodic Aura A
(@CGUID+841, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+842, 0, 0, 0, 1, 0, ''), -- Aspiring Trainee
(@CGUID+843, 0, 0, 8, 1, 0, ''), -- Shado-Pan Trainee
(@CGUID+844, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+845, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+846, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+847, 0, 0, 0, 1, 0, '52391'), -- Dreadspinner - 52391 - Ride Vehicle
(@CGUID+848, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+849, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+850, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+851, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+852, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+853, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+854, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+855, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+856, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+857, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+858, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+859, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+860, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+861, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+862, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+863, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+864, 0, 0, 50331648, 1, 0, ''), -- Krik'thik Swarmer
(@CGUID+865, 0, 0, 0, 1, 0, ''), -- Dreadspinner
(@CGUID+866, 0, 0, 50331648, 1, 0, ''); -- Krik'thik Swarmer

DELETE FROM gameobject WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+134;
INSERT INTO gameobject (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 214629, 962, 0, 0, 3, '',0, 721.6077, 2278.021, 387.9438, 1.570796, 0, 0, 0, 1, 7200, 255, 0, 21463), -- Great Wall - Demolition Crew - Boss Wall (Area: Gate of the Setting Sun)
(@OGUID+1, 215757, 962, 0, 0, 3, '',0, 694.1823, 2302.281, 387.9574, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+2, 215757, 962, 0, 0, 3, '',0, 748.4583, 2303.002, 387.9446, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+3, 215757, 962, 0, 0, 3, '',0, 751.9913, 2304.021, 387.9936, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+4, 215757, 962, 0, 0, 3, '',0, 692.125, 2302.997, 389.4222, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+5, 215757, 962, 0, 0, 3, '',0, 751.8472, 2302.142, 387.9978, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+6, 215757, 962, 0, 0, 3, '',0, 750.4114, 2304.054, 390.2531, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+7, 215757, 962, 0, 0, 3, '',0, 694.3264, 2304.16, 387.9746, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+8, 215757, 962, 0, 0, 3, '',0, 692.7465, 2303.785, 390.1983, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+9, 212899, 962, 0, 0, 3, '',0, 721.6458, 2097.759, 403.9807, 1.611702, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Instance Portal (Party + Heroic + Challenge) (Area: Gate of the Setting Sun)
(@OGUID+10, 215757, 962, 0, 0, 3, '',0, 693.9514, 2305.163, 389.123, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+11, 215757, 962, 0, 0, 3, '',0, 751.6163, 2305.024, 389.0996, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+12, 215757, 962, 0, 0, 3, '',0, 692.7448, 2303.517, 387.9784, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+13, 212983, 962, 0, 0, 3, '',0, 759.2026, 2304.528, 388.1629, 0, 0, 0, -0.7071068, 0.7071068, 7200, 255, 1, 21463), -- Doodad_GreatWall_Door_002 (Area: Gate of the Setting Sun)
(@OGUID+14, 215757, 962, 0, 0, 3, '',0, 692.4722, 2304.281, 389.3729, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+15, 212982, 962, 0, 0, 3, '',0, 721.7745, 2267.161, 388.1629, 4.71239, 0, 0, -0.7071068, 0.7071068, 7200, 255, 1, 21463), -- Doodad_GreatWall_Door_001 (Area: Gate of the Setting Sun)
(@OGUID+16, 215757, 962, 0, 0, 3, '',0, 750.4097, 2303.378, 387.9716, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+17, 215757, 962, 0, 0, 3, '',0, 750.1371, 2304.142, 389.0996, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+18, 215757, 962, 0, 0, 3, '',0, 692.3195, 2301.826, 387.9742, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+19, 215757, 962, 0, 0, 3, '',0, 693.5989, 2303.563, 389.3244, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+20, 215757, 962, 0, 0, 3, '',0, 749.9844, 2301.688, 387.96, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+21, 215757, 962, 0, 0, 3, '',0, 749.7899, 2302.858, 389.0996, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+22, 215757, 962, 0, 0, 3, '',0, 690.7934, 2303.142, 388.0311, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+23, 215757, 962, 0, 0, 3, '',0, 751.2639, 2303.424, 389.0996, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+24, 215757, 962, 0, 0, 3, '',0, 748.8073, 2304.651, 387.9494, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+25, 215757, 962, 0, 0, 3, '',0, 720.7153, 2334.116, 388, 1.76883, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+26, 215757, 962, 0, 0, 3, '',0, 720.8438, 2335.181, 389.077, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+27, 215757, 962, 0, 0, 3, '',0, 691.1424, 2304.792, 388.0006, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+28, 215757, 962, 0, 0, 3, '',0, 748.9202, 2306.406, 387.951, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+29, 214261, 962, 0, 0, 3, '',0, 958.9986, 2223.245, 295.0975, 1.570796, 0, 0, -0.7071068, 0.7071068, 7200, 255, 1, 21463), -- Courtyard Portcullis (Area: Gate of the Setting Sun)
(@OGUID+30, 215757, 962, 0, 0, 3, '',0, 722.6927, 2334.321, 387.9726, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+31, 215757, 962, 0, 0, 3, '',0, 752.1667, 2306.078, 387.9913, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+32, 215757, 962, 0, 0, 3, '',0, 721.9965, 2333.905, 389.077, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+33, 215757, 962, 0, 0, 3, '',0, 750.625, 2305.57, 390.2531, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+34, 215757, 962, 0, 0, 3, '',0, 691.2552, 2306.545, 388.0285, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+35, 215757, 962, 0, 0, 3, '',0, 750.7604, 2307.212, 387.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+36, 215757, 962, 0, 0, 3, '',0, 724.4358, 2334.234, 387.9491, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+37, 215757, 962, 0, 0, 3, '',0, 694.5018, 2306.219, 387.954, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+38, 215757, 962, 0, 0, 3, '',0, 749.7639, 2305.649, 389.0996, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+39, 215757, 962, 0, 0, 3, '',0, 722.4809, 2335.148, 389.077, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+40, 215757, 962, 0, 0, 3, '',0, 692.7621, 2305.252, 390.1723, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+41, 212899, 962, 0, 0, 3, '',0, 958.9496, 2161.863, 296.1056, 1.611702, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Instance Portal (Party + Heroic + Challenge) (Area: Gate of the Setting Sun)
(@OGUID+42, 215757, 962, 0, 0, 3, '',0, 723.4445, 2332.481, 387.9661, 1.76883, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+43, 215757, 962, 0, 0, 3, '',0, 693.0955, 2307.351, 387.9659, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+44, 214888, 962, 0, 0, 3, '',0, 916.9691, 2366.781, 392.188, 3.814697E-06, 0, 0, -0.7071068, 0.7071068, 7200, 255, 0, 21463), -- Doodad_GreatWall_Door_020 (Area: Gate of the Setting Sun)
(@OGUID+45, 215757, 962, 0, 0, 3, '',0, 750.5972, 2305.358, 387.9743, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+46, 215757, 962, 0, 0, 3, '',0, 723.6215, 2335.972, 387.9554, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+47, 215757, 962, 0, 0, 3, '',0, 692.0989, 2305.788, 389.0771, 5.656416, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+48, 215757, 962, 0, 0, 3, '',0, 723.3281, 2333.814, 389.077, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+49, 215757, 962, 0, 0, 3, '',0, 721.7587, 2332.5, 387.986, 1.76883, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+50, 215757, 962, 0, 0, 3, '',0, 692.9323, 2305.497, 387.9758, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+51, 215757, 962, 0, 0, 3, '',0, 719.7014, 2335.512, 388.0436, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+52, 215757, 962, 0, 0, 3, '',0, 721.7535, 2335.745, 387.9805, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+53, 215757, 962, 0, 0, 3, '',0, 720.9896, 2333.998, 389.8886, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+54, 215757, 962, 0, 0, 3, '',0, 722.4323, 2334.271, 390.085, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+55, 215757, 962, 0, 0, 3, '',0, 718.8629, 2333.911, 388.0109, 1.76883, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+56, 215757, 962, 0, 0, 3, '',0, 720.0174, 2332.264, 388.0415, 1.76883, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+57, 215757, 962, 0, 0, 3, '',0, 720.5938, 2333.241, 389.077, 1.142057, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Mantid Bomb (Area: Gate of the Setting Sun)
(@OGUID+58, 213200, 962, 0, 0, 3, '',0, 963.9757, 2300.161, 299.3063, 4.71239, 2.115961E-43, 0, 0, 1, 7200, 255, 1, 21463), -- Corner A (Area: Gate of the Setting Sun)
(@OGUID+59, 211245, 962, 0, 0, 3, '',0, 958.6177, 2364.442, 296.5369, 4.71239, 0, 0, -0.7071068, 0.7071068, 7200, 255, 1, 21463), -- Doodad_VEB_greatDoorPhase_001 (Area: Gate of the Setting Sun)
(@OGUID+60, 211291, 962, 0, 0, 3, '',0, 721.8168, 2304.537, 152.4351, 4.71239, 0, 0, -0.7071068, 0.7071068, 7200, 255, 24, 21463), -- 0 (Area: Gate of the Setting Sun)
(@OGUID+61, 211246, 962, 0, 0, 3, '',0, 959.4006, 2364.442, 296.5369, 4.71239, 0, 0, -0.7071068, 0.7071068, 7200, 255, 1, 21463), -- Doodad_VEB_greatDoorPhase_003 (Area: Gate of the Setting Sun)
(@OGUID+62, 214887, 962, 0, 0, 3, '',0, 1000.012, 2366.781, 392.188, 3.141593, 0, 0, -0.7071068, 0.7071068, 7200, 255, 0, 21463), -- Doodad_GreatWall_Door_019 (Area: Gate of the Setting Sun)
(@OGUID+63, 212986, 962, 0, 0, 3, '',0, 1077.574, 2216.28, 314.4737, 3.141593, 0, 0, -0.7071068, 0.7071068, 7200, 255, 0, 21463), -- Doodad_GreatWall_Door_014 (Area: Gate of the Setting Sun)
(@OGUID+64, 213198, 962, 0, 0, 3, '',0, 963.9757, 2300.161, 299.3063, 4.71239, 2.143987E-43, 0, 0, 1, 7200, 255, 1, 21463), -- Corner Piece C (Area: Gate of the Setting Sun)
(@OGUID+65, 212984, 962, 0, 0, 3, '',0, 1157.993, 2304.547, 388.1629, 3.141593, 0, 0, -0.7071068, 0.7071068, 7200, 255, 0, 21463), -- Doodad_GreatWall_Door_004 (Area: Gate of the Setting Sun)
(@OGUID+66, 211013, 962, 0, 0, 3, '',0, 1195.209, 2304.521, 430.2219, 4.71239, 0, 0, -0.7071068, 0.7071068, 7200, 255, 24, 21463), -- 0 (Area: Gate of the Setting Sun)
(@OGUID+67, 213199, 962, 0, 0, 3, '',0, 963.9757, 2300.161, 299.3063, 4.71239, 2.129974E-43, 0, 0, 1, 7200, 255, 1, 21463), -- Wall Corner B (Area: Gate of the Setting Sun)
(@OGUID+68, 215379, 962, 0, 0, 3, '',0, 1900.313, 2054.458, 455.8952, 6.230826, 0, 0, 0.9996573, 0.02617679, 7200, 255, 1, 21463), -- Doodad_GreatWall_Door_001 (Area: Gate of the Setting Sun)
(@OGUID+69, 215380, 962, 0, 0, 3, '',0, 1864.354, 2021.446, 455.8952, 4.66003, 0, 0, 0.9996573, 0.02617679, 7200, 255, 1, 21463), -- Doodad_GreatWall_Door_002 (Area: Gate of the Setting Sun)
(@OGUID+70, 212985, 962, 0, 0, 3, '',0, 1232.729, 2304.545, 388.1629, 0, 0, 0, -0.7071068, 0.7071068, 7200, 255, 0, 21463), -- Doodad_GreatWall_Door_005 (Area: Gate of the Setting Sun)
(@OGUID+71, 214629, 962, 0, 0, 3, '',0, 748.4184, 2304.536, 387.9441, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Great Wall - Demolition Crew - Boss Wall (Area: Gate of the Setting Sun)
(@OGUID+72, 214629, 962, 0, 0, 3, '',0, 721.934, 2331.214, 387.9455, 1.570796, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Great Wall - Demolition Crew - Boss Wall (Area: Gate of the Setting Sun)
(@OGUID+73, 214629, 962, 0, 0, 3, '',0, 695.3594, 2304.514, 388.0284, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Great Wall - Demolition Crew - Boss Wall (Area: Gate of the Setting Sun)
(@OGUID+74, 211129, 962, 0, 0, 3, '',0, 1376.821, 2280.453, 401.5878, 0, 0, 0, 0, 1, 7200, 255, 0, 21463), -- Signal Flame (Area: Gate of the Setting Sun)
(@OGUID+75, 213507, 962, 0, 0, 3, '',0, 1377.181, 2280.181, 451.7255, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Signal Fire (Area: Gate of the Setting Sun)
(@OGUID+76, 211284, 962, 0, 0, 3, '',0, 1195.418, 2296.464, 430.8045, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Lever (Area: Gate of the Setting Sun)
(@OGUID+77, 211284, 962, 0, 0, 3, '',0, 1195.389, 2297.177, 387.9297, 0, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Lever (Area: Gate of the Setting Sun)
(@OGUID+78, 214252, 962, 0, 0, 3, '',0, 845.5382, 2316.089, 381.2306, 1.898492, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Rope (Area: Gate of the Setting Sun)
(@OGUID+79, 214252, 962, 0, 0, 3, '',0, 846.5018, 2299.373, 382.977, 1.898492, 0, 0, 0, 1, 7200, 255, 1, 21463), -- Rope (Area: Gate of the Setting Sun)
(@OGUID+80, 212048, 870, 0, 0, 1, '',0, 688.7205, 2130.908, 329.2965, 6.118029, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+81, 212048, 870, 0, 0, 1, '',0, 708.8038, 2137.479, 404.2021, 2.026069, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+82, 214169, 870, 0, 0, 1, '',0, 655.0243, 2089.201, 370.3979, 4.363326, 0, 0, 0, 1, 120, 255, 1, 21463), -- Meeting Stone (Area: Gate of the Setting Sun)
(@OGUID+83, 212048, 870, 0, 0, 1, '',0, 708.4861, 2137.241, 404.2021, 0.4728961, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+84, 212899, 870, 0, 0, 1, '',0, 698.7274, 2079.701, 374.6942, 3.203973, 0, 0, 0, 1, 120, 255, 1, 21463), -- Instance Portal (Party + Heroic + Challenge) (Area: Gate of the Setting Sun)
(@OGUID+85, 212229, 870, 0, 0, 1, '',0, 653.2708, 2121.406, 370.1175, 3.677761, 0, 0, 0, 1, 120, 255, 1, 21463), -- Shado-Pan Rope (Area: Gate of the Setting Sun)
(@OGUID+86, 212048, 870, 0, 0, 1, '',0, 653.5364, 2114.431, 371.8593, 2.026069, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+87, 212048, 870, 0, 0, 1, '',0, 653.2188, 2114.193, 371.8593, 0.4728961, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+88, 212048, 870, 0, 0, 1, '',0, 680.8108, 2145.448, 325.7331, 6.118029, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+89, 212048, 870, 0, 0, 1, '',0, 702.1858, 2136.736, 330.0667, 6.118029, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+90, 212048, 870, 0, 0, 1, '',0, 697.5417, 2148.688, 327.6833, 6.118029, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+91, 212047, 870, 0, 0, 1, '',0, 631.6754, 2137.967, 370.1783, 0.3976982, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrows 02 Stack (Area: Gate of the Setting Sun)
(@OGUID+92, 212047, 870, 0, 0, 1, '',0, 708.5156, 2157.302, 400.1646, 0.3976982, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrows 02 Stack (Area: Gate of the Setting Sun)
(@OGUID+93, 215393, 870, 0, 0, 1, '',0, 656.9305, 2120.571, 326.6563, 3.55649, 0, 0, 0, 1, 120, 255, 1, 21463), -- Shado-Pan Rope (Area: Gate of the Setting Sun)
(@OGUID+94, 212047, 870, 0, 0, 1, '',0, 708.3351, 2172.561, 394.5767, 2.268343, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrows 02 Stack (Area: Gate of the Setting Sun)
(@OGUID+95, 212048, 870, 0, 0, 1, '',0, 616.1979, 2140.09, 370.1769, 2.985936, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+96, 212048, 870, 0, 0, 1, '',0, 616.5226, 2140.028, 370.1769, 3.018512, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+97, 212048, 870, 0, 0, 1, '',0, 617.1632, 2139.938, 370.1769, 3.018512, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+98, 212048, 870, 0, 0, 1, '',0, 616.8386, 2140, 370.1769, 2.985936, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+99, 212048, 870, 0, 0, 1, '',0, 688.7066, 2159.488, 325.7414, 6.118029, 0, 0, 0, 1, 120, 255, 1, 21463), -- Pandaren Arrow 01 (Area: Gate of the Setting Sun)
(@OGUID+100, 214404, 870, 0, 0, 1, '',0, 774.5677, 2043.026, 316.074, 0.1806636, 0, 0, 0, 1, 120, 255, 1, 21463), -- Training Target Post (Area: Gate of the Setting Sun)
(@OGUID+101, 214404, 870, 0, 0, 1, '',0, 759.1371, 2030.649, 316.1875, 0.8250687, 0, 0, 0, 1, 120, 255, 1, 21463), -- Training Target Post (Area: Gate of the Setting Sun)
(@OGUID+102, 210565, 870, 0, 0, 1, '',0, 784.5139, 2082.12, 316.0738, 0, 0, 0, 0, 1, 120, 255, 1, 21463), -- Dark Soil (Area: Gate of the Setting Sun)
(@OGUID+103, 213395, 870, 0, 0, 1, '',0, 721.7745, 2267.161, 388.1629, 4.71239, 0, 0, -0.7071068, 0.7071068, 120, 255, 0, 21463), -- Doodad_GreatWall_Door_001 (Area: Gate of the Setting Sun)
(@OGUID+104, 213314, 870, 0, 0, 1, '',0, 687.7483, 2178.031, 325.3961, 1.375986, 0, 0, 0, 1, 120, 255, 1, 21463), -- Gurthani Tablet (Area: Gate of the Setting Sun)
(@OGUID+105, 213347, 870, 0, 0, 1, '',0, 624.0417, 1726.644, 351.9688, 6.011365, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+106, 213347, 870, 0, 0, 1, '',0, 646.2188, 1715.542, 351.9688, 6.011365, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+107, 213349, 870, 0, 0, 1, '',0, 639.9653, 1739.165, 351.9688, 1.843083, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+108, 212927, 870, 0, 0, 1, '',0, 619.7743, 1703.286, 352.3808, 1.89426, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+109, 212927, 870, 0, 0, 1, '',0, 609.9271, 1723.547, 351.9688, 3.352066, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+110, 216060, 870, 0, 0, 1, '',0, 958.9986, 2157.532, 295.0975, 1.570796, 0, 0, -0.7071068, 0.7071068, 120, 255, 1, 21463), -- Doodad_VR_Portcullis01 (Area: Gate of the Setting Sun)
(@OGUID+111, 213347, 870, 0, 0, 1, '',0, 654.507, 1714.859, 351.9688, 5.548899, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+112, 213347, 870, 0, 0, 1, '',0, 616.7465, 1726.898, 351.9688, 1.624689, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+113, 212927, 870, 0, 0, 1, '',0, 660.658, 1718.766, 351.9688, 5.97854, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+114, 215363, 870, 0, 0, 1, '',0, 958.9986, 2223.245, 295.0975, 1.570796, 0, 0, -0.7071068, 0.7071068, 120, 255, 1, 21463), -- Doodad_VR_Portcullis02 (Area: Gate of the Setting Sun)
(@OGUID+115, 215364, 870, 0, 0, 1, '',0, 916.9691, 2366.781, 392.188, 5.722046E-06, 0, 0, -0.7071068, 0.7071068, 120, 255, 0, 21463), -- Doodad_GreatWall_Door_020 (Area: Gate of the Setting Sun)
(@OGUID+116, 215910, 870, 0, 0, 1, '',0, 421.1927, 2235.835, 247.0724, 0.1371686, 0, 0, 0, 1, 120, 255, 1, 21463), -- Sha GroundPatch Med Tendrils (Area: Gate of the Setting Sun)
(@OGUID+117, 213347, 870, 0, 0, 1, '',0, 667.8177, 1722.056, 351.9688, 1.994817, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+118, 212927, 870, 0, 0, 1, '',0, 627.9202, 1702.271, 352.1979, 2.170158, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+119, 214645, 870, 0, 0, 1, '',0, 406.9132, 2244.415, 244.0805, 0.306374, 0, 0, 0, 1, 120, 255, 1, 21463), -- Low Poly Fire Anim (Sha) (Area: Gate of the Setting Sun)
(@OGUID+120, 213347, 870, 0, 0, 1, '',0, 653.9219, 1721.689, 351.9688, 4.519422, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+121, 212975, 870, 0, 0, 1, '',0, 721.8168, 2304.537, 152.4351, 4.71239, 0, 0, -0.7071068, 0.7071068, 120, 255, 24, 21463), -- 0 (Area: Gate of the Setting Sun)
(@OGUID+122, 214645, 870, 0, 0, 1, '',0, 429.3507, 2248.83, 245.3312, 0.02512713, 0, 0, 0, 1, 120, 255, 1, 21463), -- Low Poly Fire Anim (Sha) (Area: Gate of the Setting Sun)
(@OGUID+123, 213347, 870, 0, 0, 1, '',0, 629.6042, 1709.365, 352.0167, 1.89426, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+124, 213347, 870, 0, 0, 1, '',0, 636.6875, 1715.54, 351.9688, 1.843083, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+125, 213349, 870, 0, 0, 1, '',0, 623.1129, 1710.326, 352.1389, 1.35203, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+126, 214645, 870, 0, 0, 1, '',0, 432.4531, 2252.168, 245.2583, 0.4386342, 0, 0, 0, 1, 120, 255, 1, 21463), -- Low Poly Fire Anim (Sha) (Area: Gate of the Setting Sun)
(@OGUID+127, 213396, 870, 0, 0, 1, '',0, 759.2026, 2304.528, 388.1629, 0, 0, 0, -0.7071068, 0.7071068, 120, 255, 0, 21463), -- Doodad_GreatWall_Door_002 (Area: Gate of the Setting Sun)
(@OGUID+128, 213347, 870, 0, 0, 1, '',0, 605.6545, 1690.877, 352.1808, 1.745517, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+129, 213347, 870, 0, 0, 1, '',0, 617.1927, 1689.953, 352.7275, 2.211151, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+130, 215365, 870, 0, 0, 1, '',0, 958.6177, 2364.442, 296.5369, 4.71239, 0, 0, -0.7071068, 0.7071068, 120, 255, 1, 21463), -- Doodad_VEB_greatDoorPhase_001 (Area: Gate of the Setting Sun)
(@OGUID+131, 215366, 870, 0, 0, 1, '',0, 959.4006, 2364.442, 296.5369, 4.71239, 0, 0, -0.7071068, 0.7071068, 120, 255, 1, 21463), -- Doodad_VEB_greatDoorPhase_003 (Area: Gate of the Setting Sun)
(@OGUID+132, 213347, 870, 0, 0, 1, '',0, 640.4132, 1695.929, 352.2264, 1.89426, 0, 0, 0, 1, 120, 255, 1, 21463), -- Whitepetal Lily (Area: Gate of the Setting Sun)
(@OGUID+133, 212976, 870, 0, 0, 1, '',0, 1195.209, 2304.521, 430.2219, 4.71239, 0, 0, -0.7071068, 0.7071068, 120, 255, 24, 21463), -- 0 (Area: Gate of the Setting Sun)
(@OGUID+134, 213347, 870, 0, 0, 1, '',0, 640.132, 1688.17, 352.4894, 5.691125, 0, 0, 0, 1, 120, 255, 1, 21463); -- Whitepetal Lily (Area: Gate of the Setting Sun)

DELETE FROM creature_template_addon WHERE `entry` IN (65172 /*65172 (Len at Arms)*/, 63497 /*63497 (Mai of the Wall)*/, 62143 /*62143 (Dreadspinner Hatchling)*/, 62077 /*62077 (Dreadspinner Egg)*/, 58065 /*58065 (General Purpose Bunny (DLA))*/, 62112 /*62112 (Bowmistress Li) - Pandaren Arrows 01 Stack*/, 61968 /*61968 (Shado-Pan Marksman)*/, 62000 /*62000 (Dreadspinner) - Ride Vehicle*/, 61981 /*61981 (Dreadspinner Tender) - Permanent Feign Death*/, 64710 /*64710 (Rope) - Rope Visual*/, 61213 /*61213 (Krik'thik Conscript)*/, 66905 /*66905 (Pandaren Cannoneer)*/, 60502 /*60502 (Pandaren Disciple)*/, 56636 /*56636 (Commander Ri'mok)*/, 59778 /*59778 (Krik'thik Striker) - Blue Mantid Wings*/, 59794 /*59794 (Krik'thik Disruptor) - Green Mantid Wings*/, 65555 /*65555 (Bonfire Teleport Stalker)*/, 64553 /*64553 ("Lighting the Way" Kill Credit)*/, 56709 /*56709 (Flying Mantid Bombing Stalker)*/, 59834 /*59834 (Boss 3 Encounter Add Generator) - Great Wall Boss 3 Big Add Spawn Periodic Trigger*/, 56822 /*56822 (Boss 2 North Stalker)*/, 56745 /*56745 (Serpent's Spine Trainee)*/, 56742 /*56742 (Serpent's Spine Defender)*/, 56743 /*56743 (Serpent's Spine Defender)*/, 56825 /*56825 (Boss 2 East Stalker)*/, 59750 /*59750 (Serpent's Spine Cannoneer)*/, 56823 /*56823 (Boss 2 West Stalker)*/, 56913 /*56913 (Boss 2 West/East Strafe Stalkers) - Strafing Run*/, 60421 /*60421 (Flak Cannon Target Stalker)*/, 56932 /*56932 (Boss 2 North/South Strafe Stalkers) - Strafing Run*/, 56824 /*56824 (Boss 2 South Stalker)*/, 65537 /*65537 (Serpent's Spine Cannoneer) - Ride Vehicle Hardcoded*/, 63848 /*63848 (Great Wall Bonfire Target Stalker 2) - Great Wall Bonfire Dummy Flame*/, 66419 /*66419 (Serpent's Spine Marksman) - Resurrect Requirement, Permanent Feign Death (Stun)*/, 59792 /*59792 (Great Wall Bonfire Caster Stalker)*/, 59793 /*59793 (Great Wall Bonfire Target Stalker 1)*/, 65400 /*65400 (Krik'thik Glider) - Green Mantid Wings*/, 65401 /*65401 (Krik'thik Glider) - Green Mantid Wings*/, 59892 /*59892 (Krik'thik Invader) - Ride Vehicle Hardcoded*/, 56876 /*56876 (Krik'thik Sapper) - Mod Scale 105-110%*/, 56875 /*56875 (Krik'thik Demolisher) - Mod Scale 95-120%*/, 60415 /*60415 (Flak Cannon) - Cosmetic - Loot Sparkles (3.00)*/, 56706 /*56706 (Krik'thik Bombardier) - Green Mantid Wings, Mantid Wings*/, 63991 /*63991 (Great Wall Explosion Target Stalker 3)*/, 59721 /*59721 (Great Wall Explosion Target Stalker 2)*/, 59886 /*59886 (Great Wall Panda Archer Target Spawner) - Creature Spawner - Flying Mantids*/, 58108 /*58108 (Krik'thik Infiltrator)*/, 58146 /*58146 (Serpent's Spine Defender)*/, 59723 /*59723 (Great Wall Explosion Caster Stalker)*/, 59800 /*59800 (Krik'thik Rager)*/, 59801 /*59801 (Krik'thik Wind Shaper) - Gale Force*/, 63192 /*63192 (Cosmetic Client Stalker) - Mantid Army*/, 56502 /*56502 (Panda Archer Target Gate Stalker) - Ride Vehicle Hardcoded*/, 56501 /*56501 (Panda Archer Target Stalker)*/, 58844 /*58844 (Panda Tar Tosser)*/, 58109 /*58109 (Mantid Infiltrator Rope Stalker)*/, 56799 /*56799 (Krik'thik Bombadier) - Green Mantid Wings, Mantid Wings*/, 63992 /*63992 (Great Wall Explosion Target Stalker 1)*/, 56906 /*56906 (Saboteur Kip'tilak) - Green Mantid Wings, Mantid Wings*/, 59820 /*59820 (Pandaren Cannoneer)*/, 56484 /*56484 (Serpent's Spine Marksman)*/, 58202 /*58202 (Serpent's Spine Defender)*/, 65111 /*65111 (Serpent's Spine Defender) - Mod Scale 95-120%*/, 64467 /*64467 (Bowmistress Li) - Pandaren Arrows 01 Stack*/, 58824 /*58824 (Courtyard Defender)*/, 56889 /*56889 (Serpent's Spine Defender) - Mod Scale 95-120%*/, 65337 /*65337 (Serpent's Spine Defender) - Mod Scale 95-120%*/, 56890 /*56890 (Krik'thik Infiltrator) - Mod Scale 95-120%*/);
INSERT INTO creature_template_addon (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(65172, 0, 0, 0, 1, 0, ''), -- 65172 (Len at Arms)
(63497, 0, 0, 0, 1, 0, ''), -- 63497 (Mai of the Wall)
(62143, 0, 0, 0, 1, 0, ''), -- 62143 (Dreadspinner Hatchling)
(62077, 0, 0, 0, 1, 0, ''), -- 62077 (Dreadspinner Egg)
(58065, 0, 0, 0, 1, 0, ''), -- 58065 (General Purpose Bunny (DLA))
(62112, 0, 0, 0, 2, 0, '120856'), -- 62112 (Bowmistress Li) - Pandaren Arrows 01 Stack
(61968, 0, 0, 0, 2, 0, ''), -- 61968 (Shado-Pan Marksman)
(62000, 0, 0, 0, 1, 0, '52391'), -- 62000 (Dreadspinner) - Ride Vehicle
(61981, 0, 0, 0, 1, 0, '70628'), -- 61981 (Dreadspinner Tender) - Permanent Feign Death
(64710, 0, 0, 0, 1, 0, '126493'), -- 64710 (Rope) - Rope Visual
(61213, 0, 0, 0, 1, 0, ''), -- 61213 (Krik'thik Conscript)
(66905, 0, 0, 0, 1, 0, ''), -- 66905 (Pandaren Cannoneer)
(60502, 0, 0, 0, 1, 0, ''), -- 60502 (Pandaren Disciple)
(56636, 0, 0, 0, 1, 0, ''), -- 56636 (Commander Ri'mok)
(59778, 0, 0, 50331648, 1, 0, '138393'), -- 59778 (Krik'thik Striker) - Blue Mantid Wings
(59794, 0, 0, 50331648, 1, 0, '126316'), -- 59794 (Krik'thik Disruptor) - Green Mantid Wings
(65555, 0, 0, 50331648, 1, 0, ''), -- 65555 (Bonfire Teleport Stalker)
(64553, 0, 0, 0, 1, 0, ''), -- 64553 ("Lighting the Way" Kill Credit)
(56709, 0, 0, 0, 1, 0, ''), -- 56709 (Flying Mantid Bombing Stalker)
(59834, 0, 0, 0, 1, 0, '116621'), -- 59834 (Boss 3 Encounter Add Generator) - Great Wall Boss 3 Big Add Spawn Periodic Trigger
(56822, 0, 0, 0, 1, 0, ''), -- 56822 (Boss 2 North Stalker)
(56745, 0, 0, 0, 1, 0, ''), -- 56745 (Serpent's Spine Trainee)
(56742, 0, 0, 0, 1, 0, ''), -- 56742 (Serpent's Spine Defender)
(56743, 0, 0, 0, 1, 0, ''), -- 56743 (Serpent's Spine Defender)
(56825, 0, 0, 0, 1, 0, ''), -- 56825 (Boss 2 East Stalker)
(59750, 0, 0, 0, 1, 0, ''), -- 59750 (Serpent's Spine Cannoneer)
(56823, 0, 0, 0, 1, 0, ''), -- 56823 (Boss 2 West Stalker)
(56913, 0, 0, 0, 1, 0, '116298'), -- 56913 (Boss 2 West/East Strafe Stalkers) - Strafing Run
(60421, 0, 0, 0, 1, 0, ''), -- 60421 (Flak Cannon Target Stalker)
(56932, 0, 0, 0, 1, 0, '116298'), -- 56932 (Boss 2 North/South Strafe Stalkers) - Strafing Run
(56824, 0, 0, 0, 1, 0, ''), -- 56824 (Boss 2 South Stalker)
(65537, 0, 0, 0, 1, 0, '46598'), -- 65537 (Serpent's Spine Cannoneer) - Ride Vehicle Hardcoded
(63848, 0, 0, 50331648, 1, 0, '124677'), -- 63848 (Great Wall Bonfire Target Stalker 2) - Great Wall Bonfire Dummy Flame
(66419, 0, 0, 0, 1, 0, '111672 96733'), -- 66419 (Serpent's Spine Marksman) - Resurrect Requirement, Permanent Feign Death (Stun)
(59792, 0, 0, 0, 1, 0, ''), -- 59792 (Great Wall Bonfire Caster Stalker)
(59793, 0, 0, 0, 1, 0, ''), -- 59793 (Great Wall Bonfire Target Stalker 1)
(65400, 0, 0, 50331648, 1, 0, '126316'), -- 65400 (Krik'thik Glider) - Green Mantid Wings
(65401, 0, 0, 50331648, 1, 0, '126316'), -- 65401 (Krik'thik Glider) - Green Mantid Wings
(59892, 0, 0, 0, 1, 0, '46598'), -- 59892 (Krik'thik Invader) - Ride Vehicle Hardcoded
(56876, 0, 0, 0, 1, 0, '127498'), -- 56876 (Krik'thik Sapper) - Mod Scale 105-110%
(56875, 0, 0, 0, 1, 0, '123978'), -- 56875 (Krik'thik Demolisher) - Mod Scale 95-120%
(60415, 0, 0, 0, 1, 0, '92406'), -- 60415 (Flak Cannon) - Cosmetic - Loot Sparkles (3.00)
(56706, 0, 0, 50331648, 1, 0, '126316 132441'), -- 56706 (Krik'thik Bombardier) - Green Mantid Wings, Mantid Wings
(63991, 0, 0, 0, 1, 0, ''), -- 63991 (Great Wall Explosion Target Stalker 3)
(59721, 0, 0, 0, 1, 0, ''), -- 59721 (Great Wall Explosion Target Stalker 2)
(59886, 0, 0, 0, 1, 0, '115141'), -- 59886 (Great Wall Panda Archer Target Spawner) - Creature Spawner - Flying Mantids
(58108, 0, 0, 0, 1, 0, ''), -- 58108 (Krik'thik Infiltrator)
(58146, 0, 0, 0, 1, 0, ''), -- 58146 (Serpent's Spine Defender)
(59723, 0, 0, 0, 1, 0, ''), -- 59723 (Great Wall Explosion Caster Stalker)
(59800, 0, 0, 0, 1, 0, ''), -- 59800 (Krik'thik Rager)
(59801, 0, 0, 0, 1, 0, '115421'), -- 59801 (Krik'thik Wind Shaper) - Gale Force
(63192, 0, 0, 0, 1, 0, '123463'), -- 63192 (Cosmetic Client Stalker) - Mantid Army
(56502, 0, 0, 0, 1, 0, '46598'), -- 56502 (Panda Archer Target Gate Stalker) - Ride Vehicle Hardcoded
(56501, 0, 0, 0, 1, 0, ''), -- 56501 (Panda Archer Target Stalker)
(58844, 0, 0, 0, 2, 0, ''), -- 58844 (Panda Tar Tosser)
(58109, 0, 0, 50331648, 1, 0, ''), -- 58109 (Mantid Infiltrator Rope Stalker)
(56799, 0, 0, 50331648, 1, 0, '126316 132441'), -- 56799 (Krik'thik Bombadier) - Green Mantid Wings, Mantid Wings
(63992, 0, 0, 0, 1, 0, ''), -- 63992 (Great Wall Explosion Target Stalker 1)
(56906, 0, 0, 0, 1, 0, '126316 132441'), -- 56906 (Saboteur Kip'tilak) - Green Mantid Wings, Mantid Wings
(59820, 0, 0, 0, 1, 0, ''), -- 59820 (Pandaren Cannoneer)
(56484, 0, 0, 0, 1, 0, ''), -- 56484 (Serpent's Spine Marksman)
(58202, 0, 0, 0, 1, 0, ''), -- 58202 (Serpent's Spine Defender)
(65111, 0, 0, 0, 1, 0, '123978'), -- 65111 (Serpent's Spine Defender) - Mod Scale 95-120%
(64467, 0, 0, 0, 2, 0, '120856'), -- 64467 (Bowmistress Li) - Pandaren Arrows 01 Stack
(58824, 0, 0, 0, 2, 0, ''), -- 58824 (Courtyard Defender)
(56889, 0, 0, 0, 1, 0, '123978'), -- 56889 (Serpent's Spine Defender) - Mod Scale 95-120%
(65337, 0, 0, 0, 1, 0, '123978'), -- 65337 (Serpent's Spine Defender) - Mod Scale 95-120%
(56890, 0, 0, 0, 1, 0, '123978'); -- 56890 (Krik'thik Infiltrator) - Mod Scale 95-120%

UPDATE creature_equip_template SET `ItemID1`=73208, `ItemID3`=73212 WHERE (`CreatureID`=58731 AND `ID`=1); -- 0

DELETE FROM gossip_menu WHERE (`entry`=14559 AND `text_id`=20581) OR (`entry`=14493 AND `text_id`=20499);
INSERT INTO gossip_menu (`entry`, `text_id`) VALUES
(14559, 20581), -- 64467 (Bowmistress Li)
(14493, 20499); -- 64467 (Bowmistress Li)

/*
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(56636, UNKNOWN, UNKNOWN, 'The gates are about to fall. Quickly! Slaughter these meddlers!', 14, 0, 100, UNKNOWN, 0, 29076, '59340', 'Commander Ri''mok to Player'),
(56743, UNKNOWN, UNKNOWN, 'But the mantid have overrun the area. There''s no clear path!', 12, 0, 100, UNKNOWN, 0, UNKNOWN, '55756', 'Serpent''s Spine Defender to Player'),
(65111, UNKNOWN, UNKNOWN, 'The mantid artillery is here, you must hurry heroes!', 12, 0, 100, 397, 0, UNKNOWN, '64838', 'Serpent''s Spine Defender to Krik''thik Infiltrator'),
(58146, UNKNOWN, UNKNOWN, 'Hold them off! Protect the archers!', 14, 0, 100, UNKNOWN, 0, UNKNOWN, '56892', 'Serpent''s Spine Defender to Player'),
(56742, UNKNOWN, UNKNOWN, 'We''ve got to light that signal fire. Without reinforcements, they''ll destroy the gate!', 12, 0, 100, UNKNOWN, 0, UNKNOWN, '55755', 'Serpent''s Spine Defender to Player'),
(56745, UNKNOWN, UNKNOWN, 'Don''t worry! I can make it!', 12, 0, 100, UNKNOWN, 0, UNKNOWN, '55757', 'Serpent''s Spine Trainee to Player'),
(58202, UNKNOWN, UNKNOWN, 'Ggrgll!', 14, 0, 100, UNKNOWN, 0, UNKNOWN, '66517', 'Serpent''s Spine Defender to Player'),
(56589, UNKNOWN, UNKNOWN, 'I''ll hurl your corpses from this tower.', 14, 0, 100, UNKNOWN, 0, 29375, '62888', 'Striker Ga''dok'),
(56877, UNKNOWN, UNKNOWN, 'The |cFFFE9A2EKrik''thik Protectorate|r reinforcements appear!', 41, 0, 100, UNKNOWN, 0, UNKNOWN, '57601', 'Raigonn to Raigonn'),
(56906, UNKNOWN, UNKNOWN, 'Gate?! I''m going to bring this whole wall down!', 14, 0, 100, UNKNOWN, 0, 29341, '55896', 'Saboteur Kip''tilak');
*/

INSERT INTO npc_spellclick_spells (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(60415, 116554, 2, 3),
(64710, 126553, 2, 3),
(65336, 127885, 2, 3);

UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=58835; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56930; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56928; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56912; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56929; -- 0
UPDATE creature_template SET `npcflag`=16777216, `speed_walk`=2, `speed_run`=0.7142857, `VerifiedBuild`=21463 WHERE `entry`=64710; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=64740; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=60502; -- 0
UPDATE creature_template SET `minlevel`=92, `maxlevel`=92, `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=61213; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=66905; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59835; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59836; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56895; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56877; -- 0
UPDATE creature_template SET `speed_run`=2, `VerifiedBuild`=21463 WHERE `entry`=56636; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59813; -- 0
UPDATE creature_template SET `minlevel`=89, `maxlevel`=89, `speed_run`=2, `VerifiedBuild`=21463 WHERE `entry`=59778; -- 0
UPDATE creature_template SET `minlevel`=89, `maxlevel`=89, `speed_run`=2, `VerifiedBuild`=21463 WHERE `entry`=59794; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=64553; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=65555; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59954; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59955; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56822; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59834; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56709; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56743; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56742; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56745; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56825; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59750; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56823; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=60421; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56824; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56913; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56932; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56589; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=65537; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59793; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=63848; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59792; -- 0
UPDATE creature_template SET `dynamicflags`=64, `VerifiedBuild`=21463 WHERE `entry`=66419; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59208; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59207; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59206; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59205; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56917; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56879; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56880; -- 0
UPDATE creature_template SET `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=65401; -- 0
UPDATE creature_template SET `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=65400; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56920; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56919; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56918; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56911; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56896; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59885; -- 0
UPDATE creature_template SET `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=59892; -- 0
UPDATE creature_template SET `minlevel`=90, `maxlevel`=90, `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=56876; -- 0
UPDATE creature_template SET `minlevel`=90, `maxlevel`=90, `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=56875; -- 0
UPDATE creature_template SET `speed_run`=2, `VerifiedBuild`=21463 WHERE `entry`=56706; -- 0
UPDATE creature_template SET `npcflag`=16777216, `speed_run`=1, `VerifiedBuild`=21463 WHERE `entry`=60415; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59721; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=63991; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59886; -- 0
UPDATE creature_template SET `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=59801; -- 0
UPDATE creature_template SET `speed_run`=0.9920629, `unit_flags`=0, `VerifiedBuild`=21463 WHERE `entry`=58108; -- 0
UPDATE creature_template SET `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=59800; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=58146; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59723; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=61177; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56502; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56501; -- 0
UPDATE creature_template SET `speed_walk`=2, `speed_run`=0.7142857, `VerifiedBuild`=21463 WHERE `entry`=63192; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=63992; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56484; -- 0
UPDATE creature_template SET `speed_run`=2, `VerifiedBuild`=21463 WHERE `entry`=56799; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=58844; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=58202; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59820; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=58109; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=59819; -- 0
UPDATE creature_template SET `minlevel`=92, `maxlevel`=92, `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=56906; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=66904; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=58824; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=56889; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=65337; -- 0
UPDATE creature_template SET `VerifiedBuild`=21463 WHERE `entry`=65111; -- 0
UPDATE creature_template SET `minlevel`=90, `maxlevel`=90, `speed_run`=0.9920629, `VerifiedBuild`=21463 WHERE `entry`=56890; -- 0
UPDATE creature_template SET `gossip_menu_id`=14493, `VerifiedBuild`=21463 WHERE `entry`=64467; -- 0

UPDATE gameobject_template SET `IconName`='interact', `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=214252; -- 0
UPDATE gameobject_template SET `IconName`='interact', `faction`=35, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=211284; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data9`=1, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=213507; -- 0
UPDATE gameobject_template SET `IconName`='interact', `flags`=48, `Data9`=1, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=211129; -- 0
UPDATE gameobject_template SET `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=215379; -- 0
UPDATE gameobject_template SET `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=215380; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=212985; -- 0
UPDATE gameobject_template SET `Data4`=5701096, `Data5`=962, `Data6`=23333, `Data7`=5701096, `Data9`=5701096, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=211013; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=212984; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data18`=152, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=213199; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data18`=153, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=213198; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=212986; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=214887; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=211246; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=211245; -- 0
UPDATE gameobject_template SET `Data4`=5701096, `Data5`=870, `Data7`=5701096, `Data9`=5701096, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=211291; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=214888; -- 0
UPDATE gameobject_template SET `faction`=1375, `flags`=32, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=214261; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data18`=151, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=213200; -- 0
UPDATE gameobject_template SET `Data15`=5793, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=215757; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data8`=1, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=212983; -- 0
UPDATE gameobject_template SET `faction`=1375, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=214629; -- 0
UPDATE gameobject_template SET `faction`=114, `flags`=32, `Data8`=1, `Data24`=0, `Data25`=0, `Data26`=0, `Data27`=0, `Data28`=0, `Data29`=0, `Data30`=0, `Data31`=0, `Data32`=0, `VerifiedBuild`=21463 WHERE `entry`=212982; -- 0

DELETE FROM npc_text WHERE `ID` IN (20581 /*20581*/, 20499 /*20499*/);
INSERT INTO npc_text (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(20581, 1, 0, 0, 0, 0, 0, 0, 0, 64858, 0, 0, 0, 0, 0, 0, 0, 21463), -- 20581
(20499, 1, 0, 0, 0, 0, 0, 0, 0, 64685, 0, 0, 0, 0, 0, 0, 0, 21463); -- 20499

UPDATE creature SET spawnMask = 262 WHERE map = 962;
UPDATE gameobject SET spawnMask = 262 WHERE map = 962;

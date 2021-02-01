-- Sniffed
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 27952 WHERE `Id` = 50158; -- Wyrmrest Temple - Protector Transform (Red)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 27954 WHERE `Id` = 50159; -- Wyrmrest Temple - Protector Transform (Green)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 27955 WHERE `Id` = 50160; -- Wyrmrest Temple - Protector Transform (Bronze)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 28250 WHERE `Id` = 51117; -- Wyrmrest Temple - Protector Transform (Black)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 28251 WHERE `Id` = 51118; -- Wyrmrest Temple - Protector Transform (Blue)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 28252 WHERE `Id` = 51119; -- Wyrmrest Temple - Protector Transform (Nether)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 30077 WHERE `Id` = 55827; -- Wyrmrest Temple - Warden Transform (Black)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 30076 WHERE `Id` = 55828; -- Wyrmrest Temple - Warden Transform (Blue)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 30073 WHERE `Id` = 55829; -- Wyrmrest Temple - Warden Transform (Green)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 30059 WHERE `Id` = 55830; -- Wyrmrest Temple - Warden Transform (Bronze)
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 56, `EffectMiscValue1` = 30072 WHERE `Id` = 55831; -- Wyrmrest Temple - Warden Transform (Red)

-- Warden of the Chamber, auras are static
DELETE FROM `creature_addon` WHERE `guid` IN (105487,105488,105489,105495,131055,131056,131058,131059,131063,131064);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES
(131063,257,"55827"),
(131064,257,"55827"),
(105495,257,"55828"),
(105487,257,"55828"),
(131058,257,"55829"),
(131055,257,"55829"),
(105489,257,"55830"),
(105488,257,"55830"),
(131056,257,"55831"),
(131059,257,"55831");

-- Native model, 14357 is disabled
UPDATE `creature` SET `modelid` = 20737, `VerifiedBuild` = 12340 WHERE `id` = 30058;
-- Fix positions
UPDATE `creature` SET `position_x` = 3590.49, `position_y` = 190.253, `position_z` = -113.678, `orientation` = 6.0912 WHERE `guid` = 131056 AND `id` = 30058;
UPDATE `creature` SET `position_x` = 3611.36, `position_y` = 204.749, `position_z` = -113.681, `orientation` = 5.46288 WHERE `guid` = 131059 AND `id` = 30058;

-- Wyrmrest Protector, auras and equipment are linked together
-- all spawned with position_z > 100 are temp summons and always spawns with random model from template (not from auras)
-- and their equipment is always 7. No idea what exactly they do, there are multiple spawn positions and seems like some
-- of them moves randomly on walks on paths. Don't wanna add more of them or remove existing because I have no idea how they works
-- Since we can't add guid scripts to all of them(100 rows), non-static ones will share the same script
DELETE FROM `creature_equip_template` WHERE `CreatureID` = 27953;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(27953, 7, 31273, 0, 19368, 12340), -- 27953
(27953, 6, 32729, 0, 19368, 12340), -- 27953 51118 Wyrmrest Temple - Protector Transform (Blue) 14356
(27953, 5, 38488, 0, 19368, 12340), -- 27953 50158 Wyrmrest Temple - Protector Transform (Red) 14357
(27953, 4, 38209, 0, 19368, 12340), -- 27953 50159 Wyrmrest Temple - Protector Transform (Green) 14359
(27953, 3, 38487, 0, 19368, 12340), -- 27953 51117 Wyrmrest Temple - Protector Transform (Black) 14355
(27953, 2, 38491, 0, 19368, 12340), -- 27953 50160 Wyrmrest Temple - Protector Transform (Bronze) 14358
(27953, 1, 38490, 0, 19368, 12340); -- 27953 51119 Wyrmrest Temple - Protector Transform (Nether) 25257

-- Native model is random
UPDATE `creature` SET `modelid` = 0, `equipment_id` = 0, `VerifiedBuild` = 12340 WHERE `id` = 27953 AND `position_z` < 100;
UPDATE `creature` SET `modelid` = 0, `equipment_id` = 7 WHERE `id` = 27953 AND `position_z` > 100;

-- Missing
DELETE FROM `creature` WHERE `guid` = 131122 AND `id` = 27953;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131122, 27953, 571, 1, 1, 0, 3452.65, 250.009, 52.3788, 3.29867, 300, 0, 0, 12340);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27953 AND `source_type` = 0 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2795300 AND 2795305 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27953,0,4,0,63,0,100,0,0,0,0,0,0,88,2795300,2795305,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Just Created - Run Random Script"),

(2795300,9,0,0,0,0,100,0,0,0,0,0,0,75,51119,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Add Aura 'Wyrmrest Temple - Protector Transform (Nether)'"),
(2795300,9,1,0,0,0,100,0,0,0,0,0,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Change Equipment"),

(2795301,9,0,0,0,0,100,0,0,0,0,0,0,75,50160,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Add Aura 'Wyrmrest Temple - Protector Transform (Bronze)'"),
(2795301,9,1,0,0,0,100,0,0,0,0,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Change Equipment"),

(2795302,9,0,0,0,0,100,0,0,0,0,0,0,75,51117,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Add Aura 'Wyrmrest Temple - Protector Transform (Black)'"),
(2795302,9,1,0,0,0,100,0,0,0,0,0,0,71,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Change Equipment"),

(2795303,9,0,0,0,0,100,0,0,0,0,0,0,75,50159,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Add Aura 'Wyrmrest Temple - Protector Transform (Green)'"),
(2795303,9,1,0,0,0,100,0,0,0,0,0,0,71,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Change Equipment"),

(2795304,9,0,0,0,0,100,0,0,0,0,0,0,75,50158,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Add Aura 'Wyrmrest Temple - Protector Transform (Red)'"),
(2795304,9,1,0,0,0,100,0,0,0,0,0,0,71,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Change Equipment"),

(2795305,9,0,0,0,0,100,0,0,0,0,0,0,75,51118,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Add Aura 'Wyrmrest Temple - Protector Transform (Blue)'"),
(2795305,9,1,0,0,0,100,0,0,0,0,0,0,71,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmrest Protector - On Script - Change Equipment");

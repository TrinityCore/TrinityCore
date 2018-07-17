SET @GUID = 210118260;

-- Missing creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+5;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@GUID, 91784, 1456, 8040, 8081, 8388870, 0, 0, 0, -1, 0, 0, -3682.653, 4417.024, 32.44474, 8.969724, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 22810),
(@GUID + 1, 91789, 1456, 8040, 8081, 8388870, 0, 0, 0, -1, 0, 0, -3436.209961, 4573.152832, -0.437313, 1.887289, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 22810),
(@GUID + 2, 91797, 1456, 8040, 8081, 8388870, 0, 0, 0, -1, 0, 0, -3432.059082, 4199.836914, 29.184990, 4.172674, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 22810),
(@GUID + 3, 100248, 1456, 8040, 8081, 8388870, 0, 0, 0, -1, 0, 0, -3473.757, 4280.27, 1.937165, 1.719073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 22810),
(@GUID + 4, 97063, 1456, 8040, 8081, 8388870, 0, 0, 0, -1, 0, 0, -3486.264, 4386.87, -3.580416, 1.719073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 22810),
(@GUID + 5, 97713, 1456, 8040, 8081, 8388870, 0, 0, 0, -1, 0, 0, -3486.264, 4386.87, -3.580416, 1.719073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 22810);

UPDATE `creature_template` SET `ScriptName` = 'boss_king_deepbeard' WHERE `entry` = 91797;

-- King Deepbeard - Call the Seas
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193051;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 193051, 0, 0, 31, 0, 3, 97844, 0, 0, 0, 0, '', 'Call of Seas can implicitly hit only invisible bunnies around King Deepbeard');

UPDATE `areatrigger_template` SET `ScriptName` = 'at_king_deepbeard_call_the_seas' WHERE `id` = 9683;

-- King Deepbeard - Gaseous Bubbles / Gaseous Explosion
DELETE FROM `spell_script_names` WHERE `spell_id` = 193018;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193018, 'aura_king_deepbeard_gaseous_bubbles');

-- King Deepbeard - Quake
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193152;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 193152, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Quake can implicitly hit only players around King Deepbeard');

UPDATE `creature_template` SET `ScriptName` = 'npc_king_deepbeard_quake' WHERE `entry` = 97916;

UPDATE `creature_template` SET `ScriptName` = 'boss_lady_hatecoil' WHERE `entry` = 91789;

-- Handled in the script instead
UPDATE `creature_template_addon` SET `auras` = NULL WHERE entry = 91789;

DELETE FROM `spell_script_names` WHERE `spell_id` = 193245;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193245, 'aura_king_deepbeard_gain_energy');

-- Lady Hatecoil - Static Nova
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193597;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 193597, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Static Nova can implicitly hit only players around Lady Hatecoil not near a Sand Dune'),
(13, 3, 193597, 0, 0, 29, 0, 97853, 5, 0, 1, 0, 0, '', 'Static Nova can implicitly hit only players around Lady Hatecoil not near a Sand Dune');

-- Lady Hatecoil - Focused Lightning
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193611;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 193611, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Focused Lightning can implicitly hit only players around Lady Hatecoil');

DELETE FROM `spell_script_names` WHERE `spell_id` = 193611;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193611, 'spell_lady_hatecoil_focused_lightning');

UPDATE `creature_template` SET `flags_extra` = 2, `modelid1` = 31183, `modelid2` = 0 WHERE `entry` = 97853;

-- Lady Hatecoil - Beckon Storm
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193682;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 193682, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Beckon Storm can implicitly hit only players around Lady Hatecoil');

DELETE FROM `spell_script_names` WHERE `spell_id` = 193682;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193682, 'spell_lady_hatecoil_beckon_storm');

-- Lady Hatecoil - Curse of the Witch
DELETE FROM `spell_script_names` WHERE `spell_id` IN (193698, 193712, 193716);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193698, 'aura_lady_hatecoil_curse_of_the_witch'),
(193712, 'spell_lady_hatecoil_curse_of_the_witch'),
(193716, 'spell_lady_hatecoil_curse_of_the_witch');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193720;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 193720, 0, 0, 31, 0, 3, 98293, 0, 0, 0, 0, '', 'Curse of the Witch (instakill) can implicitly hit only Saltsea Globule');

-- Lady Hatecoil - Crackling Thunder
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 197324;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 197324, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Crackling Thunder can implicitly hit only players around Lady Hatecoil');

DELETE FROM `spell_script_names` WHERE `spell_id` = 197324;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(197324, 'spell_lady_hatecoil_crackling_thunder');

-- Lady Hatecoil - Monsoon
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 196624;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 196624, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Monsoon can implicitly hit only players around Lady Hatecoil');

DELETE FROM `spell_script_names` WHERE `spell_id` = 196624;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(196624, 'spell_lady_hatecoil_monsoon_target');

UPDATE `creature_template` SET `ScriptName` = 'npc_lady_hatecoil_monsoon' WHERE `entry` = 99852;

-- Custom AT
DELETE FROM `areatrigger_template` WHERE `id`=100101;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(100101, 0, 4, 4, 4, 0, 0, 0, 0, 'at_lady_hatecoil_monsoon', 0);

DELETE FROM `spell_areatrigger` WHERE `SpellMiscId`=5274;
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5274, 100101, 0, 0, 0, 0, 0, 0, 0, 0);

-- Saltsea Globule SAI
SET @ENTRY := 98293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,193636,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltsea Globule - On Just Died - Cast 'Watery Splash'");

UPDATE `creature_template` SET `ScriptName` = 'boss_serpentrix' WHERE `entry` = 91808;

-- Serpentrix - Poison Spit
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 192050;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 192050, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Poison Spit can implicitly hit only players around Serpentrix');

DELETE FROM `spell_script_names` WHERE `spell_id` = 192050;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(192050, 'spell_serpentrix_poison_spit');

-- Serpentrix - Toxic Wound
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 191855;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 191855, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Toxic Wound can implicitly hit only players around Serpentrix');

-- Serpentrix - Toxic Puddle
UPDATE `areatrigger_template` SET `ScriptName` = 'at_serpentrix_toxic_puddle' WHERE `id` = 9574;

-- Hydra Spawns are spawned dynamically
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 97259);
DELETE FROM `creature` WHERE `id` = 97259;

DELETE FROM `spell_script_names` WHERE `spell_id` = 191873;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191873, 'spell_serpentrix_submerge');

-- Serpentix - Hydra Head
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 202680;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 202680, 0, 0, 29, 0, 97259, 0, 0, 0, 0, 0, '', 'Hydra Head can implicitly hit only Hydra Spawns around Serpentix');

-- Serpentix - Rampage
DELETE FROM `spell_script_names` WHERE `spell_id` = 191850;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191850, 'spell_serpentix_rampage_aura');

UPDATE `creature_template` SET `ScriptName` = 'npc_blazing_hydra_spawn' WHERE `entry` = 97259;

-- Blazing Hydra Spawn - Blazing Nova
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 192003;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 192003, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Blazing Nova can implicitly hit only players around Blazing Hydra Spawn');

-- Arcane Hydra Spawn
UPDATE `creature_template` SET `ScriptName` = 'npc_arcane_hydra_spawn' WHERE `entry` = 97260;
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=97260; -- Arcane Hydra Spawn

-- Wrath of Azshara
UPDATE `creature_template` SET `ScriptName` = 'boss_wrath_of_azshara' WHERE `entry` = 96028;
UPDATE `creature_addon` ca JOIN `creature` c ON c.guid = ca.guid SET `auras` = '197164' WHERE c.id = 96028;

-- Wrath of Azshara - Surging Waters
UPDATE `areatrigger_template` SET `ScriptName` = 'at_wrath_of_azshara_surging_waters' WHERE `id` = 9640;

-- Wrath of Azshara - Wrongly spawned Tidal Wave npc
DELETE FROM `creature` WHERE `id` = 97739;

-- Wrath of Azshara - Mystic Tornado
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 192680;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 192680, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Mystic Tornado can implicitly hit only players around Wrath of Azshara');

UPDATE `areatrigger_template` SET `ScriptName` = 'at_wrath_of_azshara_mystic_tornado' WHERE `id` = 9647;

DELETE FROM `spell_script_names` WHERE `spell_id` = 192680;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(192680, 'spell_wrath_of_azshara_mystic_tornado');

UPDATE creature_template SET modelid1 = 1126, flags_extra = 2 WHERE entry = 97673;

UPDATE `areatrigger_template` SET `ScriptName` = 'at_wrath_of_azshara_tidal_wave' WHERE `id` = 9671;

-- Wrath of Azshara - Arcane Bomb
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 192705;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 192705, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Arcane Bomb can implicitly hit only players around Wrath of Azshara');

DELETE FROM `spell_script_names` WHERE `spell_id` = 192705;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(192705, 'spell_wrath_of_azshara_arcane_bomb_target');

UPDATE `creature_template` SET `modelid2` = 0, `modelid1` = 31379, `flags_extra` = 2 WHERE `entry` = 97691;

-- Arcane Bomb SAI
SET @ENTRY := 97691;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Bomb - On Reset - Disable Combat Movement");

-- Hatecoil Warrior SAI
SET @ENTRY := 91781;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,115385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Warrior - On Aggro - Cast 'Rush'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,14000,16000,11,195094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Warrior - In Combat - Cast 'Coral Slash'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Warrior - Between 0-50% Health - Cast 'Enrage' (No Repeat)");

-- Hatecoil Stormweaver SAI
SET @ENTRY := 91783;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,4000,15000,11,195108,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatecoil Stormweaver - In Combat - Cast 'Lightning Blast'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,12000,15000,11,195109,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatecoil Stormweaver - In Combat - Cast 'Arc Lightning'"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,10000,13000,11,196870,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Stormweaver - In Combat - Cast 'Storm'");

-- Hatecoil Wrangler SAI
SET @ENTRY := 100216;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,3000,6000,11,197137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Wrangler - In Combat - Cast 'Throw Spear'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,8000,15000,11,197144,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hatecoil Wrangler - In Combat - Cast 'Hooked Net'"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,15000,20000,11,197141,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Wrangler - In Combat - Cast 'Lightning Prod'"),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Wrangler - On Aggro - Say Line 0");

-- Hatecoil Wrangler - Lightning Prod
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 197141;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 197141, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Lightning Prod can implicitly hit players around Hatecoil Wrangler'),
(13, 3, 197141, 0, 1, 29, 0, 91785, 0, 0, 0, 0, 0, '', 'Lightning Prod can implicitly hit Wandering Shellbacks');

-- Wandering Shellback SAI
SET @ENTRY := 91785;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,14000,16000,11,195105,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wandering Shellback - In Combat - Cast 'Crunching Bite'"),
(@ENTRY,0,1,0,0,0,100,0,25000,35000,35000,40000,11,195104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wandering Shellback - In Combat - Cast 'Spiked Carapace'"),
(@ENTRY,0,2,0,8,0,100,0,197141,0,0,0,49,0,0,0,0,0,0,17,0,50,0,0,0,0,0,"Wandering Shellback - On Spellhit 'Lightning Prod' - Attack nearby player"),
(@ENTRY,0,3,0,8,0,100,0,197141,0,0,0,11,15716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wandering Shellback - In Combat - Cast 'Enrage'");

-- Hatecoil Oracle SAI
SET @ENTRY := 95861;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3000,11,195037,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Oracle - In Combat - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,10000,20000,11,195046,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Oracle - In Combat - Cast 'Rejuvenating Waters'");

-- Hatecoil Crusher SAI
SET @ENTRY := 91782;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,8000,8000,11,195172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Crusher - In Combat - Cast 'Mighty Slam'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,8000,8000,11,195129,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Crusher - In Combat - Cast 'Thundering Stomp'");

-- Gritslime Snail SAI
SET @ENTRY := 91786;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,8000,12000,11,195473,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gritslime Snail - In Combat - Cast 'Abrasive Slime'");

-- Saltsea Droplet SAI
SET @ENTRY := 97172;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,193636,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saltsea Droplet - On Just Died - Cast 'Watery Splash'");

-- Cove Seagull SAI
SET @ENTRY := 91787;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,15000,20000,11,195561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cove Seagull - In Combat - Cast 'Blinding Peck'");

-- Hatecoil Arcanist - Aqua Spout
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 196027;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 196027, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Aqua Spout can implicitly hit only players around Hatecoil Arcanist');

DELETE FROM `spell_script_names` WHERE `spell_id` = 196027;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(196027, 'spell_hatecoil_arcanist_aqua_spout');

-- Hatecoil Arcanist SAI
SET @ENTRY := 97171;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,16000,11,196027,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Arcanist - In Combat - Cast 'Aqua Spout'"),
(@ENTRY,0,1,0,0,0,100,0,500,500,8000,16000,11,196028,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Arcanist - In Combat - Cast 'Arcane Rebound'"),
(@ENTRY,0,2,0,0,0,100,0,10000,15000,12000,16000,11,197105,0,0,0,0,0,6,0,0,0,0,0,0,0,"Hatecoil Arcanist - In Combat - Cast 'Polymorph: Fish'"),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,34,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Arcanist - On Just Died - Set Instance Data 5 to 0"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Arcanist - On Just Died - Say Line 0");

-- Restless Tides SAI
SET @ENTRY := 97173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,12000,20000,25000,11,195253,0,0,0,0,0,6,0,0,0,0,0,0,0,"Restless Tides - In Combat - Cast 'Imprisoning Bubble'"),
(@ENTRY,0,1,0,0,0,100,0,10000,12000,15000,25000,11,195284,0,0,0,0,0,1,0,0,0,0,0,0,0,"Restless Tides - In Combat - Cast 'Undertow'");

-- Hatecoil Wavebinder SAI
SET @ENTRY := 97170;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,500,3000,3000,11,195232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatecoil Wavebinder - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,25000,30000,11,196031,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Wavebinder - In Combat - Cast 'Bubble Shield'"),
(@ENTRY,0,2,0,0,0,100,0,5000,10000,6000,10000,11,195234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatecoil Wavebinder - In Combat - Cast 'Call Waters'");

-- Water Elemental SAI
SET @ENTRY := 99300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,500,1250,1250,11,195595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Water Elemental - In Combat - Cast 'Water Ball'");

-- Bubble Shield applies Feedback if absorbed damage is DPS'd out
DELETE FROM `spell_script_names` WHERE `spell_id` = 196031;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(196031, 'aura_hatecoil_wavebinder_bubble_shield');

-- Animated Storm - Water Spout
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 195528;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 195528, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Water Spout can implicitly hit only players around Animated Storm');

DELETE FROM `spell_script_names` WHERE `spell_id` = 195528;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(195528, 'spell_animated_storm_water_spout');

-- Custom AT
DELETE FROM `areatrigger_template` WHERE `id`=100100;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(100100, 0, 0, 4, 4, 0, 0, 0, 0, 'at_animated_storm_water_spout', 0);

DELETE FROM `spell_areatrigger` WHERE `SpellMiscId`=5187;
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5187, 100100, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` = 103674;

-- Animated Storm SAI
SET @ENTRY := 95920;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,6000,8000,11,195528,0,0,0,0,0,1,0,0,0,0,0,0,0,"Animated Storm - In Combat - Cast 'Water Spout'");

-- Bitterbrine Scavenger SAI
SET @ENTRY := 95940;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,13000,17000,11,196058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Lethargic Toxin'"),
(@ENTRY,0,1,0,0,0,100,0,1500,4000,13000,17000,11,196060,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Numbing Toxin'"),
(@ENTRY,0,2,0,0,0,100,0,4500,8000,13000,17000,11,196059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Sea-Brine Toxin'");

-- Bitterbrine Scavenger SAI
SET @ENTRY := 99629;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,13000,17000,11,196058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Lethargic Toxin'"),
(@ENTRY,0,1,0,0,0,100,0,1500,4000,13000,17000,11,196060,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Numbing Toxin'"),
(@ENTRY,0,2,0,0,0,100,0,4500,8000,13000,17000,11,196059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Sea-Brine Toxin'");

-- Bitterbrine Scavenger SAI
SET @ENTRY := 106785;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,13000,17000,11,196058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Lethargic Toxin'"),
(@ENTRY,0,1,0,0,0,100,0,1500,4000,13000,17000,11,196060,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Numbing Toxin'"),
(@ENTRY,0,2,0,0,0,100,0,4500,8000,13000,17000,11,196059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Sea-Brine Toxin'");

-- Bitterbrine Scavenger SAI
SET @ENTRY := 106786;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,13000,17000,11,196058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Lethargic Toxin'"),
(@ENTRY,0,1,0,0,0,100,0,1500,4000,13000,17000,11,196060,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Numbing Toxin'"),
(@ENTRY,0,2,0,0,0,100,0,4500,8000,13000,17000,11,196059,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bitterbrine Scavenger - In Combat - Cast 'Sea-Brine Toxin'");

-- Saltscale Lurker SAI
SET @ENTRY := 91794;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,10000,15000,11,196064,0,0,0,0,0,2,0,0,0,0,0,0,0,"Saltscale Lurker - In Combat - Cast 'Tearing Bite'");

-- Skrog Wavecrasher SAI
SET @ENTRY := 91796;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,18000,18000,11,195944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skrog Wavecrasher - In Combat - Cast 'Rising Fury'"),
(@ENTRY,0,1,0,0,0,100,0,8250,8250,18000,18000,11,195945,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skrog Wavecrasher - In Combat - Cast 'Rising Fury (buff)'");

-- Skrog Tidestomper - Massive Quake
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 195827;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 195827, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Massive Quake can implicitly hit only players around Skrog Tidestomper');

DELETE FROM `spell_script_names` WHERE `spell_id` = 195827;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(195827, 'spell_skrog_tidestomper_massive_quake');

UPDATE `areatrigger_template` SET `ScriptName` = 'at_skrog_tidestomper_massive_quake' WHERE `id` = 10655;

-- Skrog Tidestomper SAI
SET @ENTRY := 95939;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,20000,20000,11,195801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skrog Tidestomper - In Combat - Cast 'Massive Quake'");

-- Seaspray Crab SAI
SET @ENTRY := 91793;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,15000,20000,11,196111,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seaspray Crab - In Combat - Cast 'Jagged Claws'");

-- Mak'rana Siltwalker SAI
SET @ENTRY := 91790;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,10000,12000,11,196127,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mak'rana Siltwalker - In Combat - Cast 'Spray Sand'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,15000,20000,11,196144,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mak'rana Siltwalker - In Combat - Cast 'Sandstorm'");

-- Mak'rana Hardshell SAI
SET @ENTRY := 95947;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,10000,15000,11,196175,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mak'rana Hardshell - In Combat - Cast 'Armorshell'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 196175;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(196175, 'aura_makrana_hardshell_armorshell');

-- Stormwake Hydra SAI
SET @ENTRY := 91792;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,3000,5000,11,196287,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwake Hydra - In Combat - Cast 'Roiling Storm'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,8000,12000,11,196292,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormwake Hydra - In Combat - Cast 'Chaotic Tempest'");

-- Missing data for Saltsea Globules, Hatecoil Shellbreaker and Hatecoil Crestrider
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16 WHERE `entry` IN (98293, 97269, 97264);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=98, `LevelScalingMax`=110, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1 WHERE `entry` IN (98293, 97269, 97264);

-- Wrath of Azshara nagas - Storm Conduit
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 193196;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 193196, 0, 0, 31, 0, 3, 96028, 0, 0, 0, 0, '', 'Storm Conduit can implicitly hit only Wrath of Azshara');

-- Extra NPC under Wrath of Azshara
DELETE FROM `creature` WHERE `id` IN (111936, 111374, 106780);

-- Tidestone of Golganneth Scale & State Visual
UPDATE `creature_template_addon` SET `auras` = '211850' WHERE `entry` = 106780;

UPDATE `creature_template` SET `ScriptName` = 'npc_wrath_of_azshara_naga' WHERE `entry` IN (98173, 100248, 100249, 100250);

-- Violent Winds - Weatherman part
DELETE FROM `spell_script_names` WHERE `spell_id` IN (191792, 191805, 192649);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191792, 'aura_eoa_violent_winds_broadcast'),
(191805, 'aura_eoa_violent_winds_broadcast'),
(192649, 'aura_eoa_violent_winds_broadcast');

-- Violent Winds - Player part
DELETE FROM `spell_script_names` WHERE `spell_id` = 191797;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(191797, 'aura_eoa_violent_winds_force_move');

-- No Violent Winds at the beginning (it starts when 2 bosses are killed)
UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 97063;

-- Lightning Strikes
DELETE FROM `spell_script_names` WHERE `spell_id` = 192737;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(192737, 'aura_eoa_lightning_strikes');

-- Creature texts
DELETE FROM `creature_text` WHERE `CreatureID`=91784;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(91784, 0, 0, 'Hmph. Intruders. They will not get far.', 14, 0, 100, 0, 0, 54193, 0, 'Warlord Parjesh on line of sight'),
(91784, 200, 0, 'Ah, we meet again, weakling. Now it''s just you and me... and my guards!', 14, 0, 100, 0, 0, 54181, 0, 'Warlord Parjesh on EnterCombat'),
(91784, 1, 0, '|TInterface\\Icons\\Spell_Shadow_UnholyFrenzy:20|tWarlord Parjesh |cFFFF0000|Hspell:197064|h[Enrages]|h|r!', 41, 0, 100, 0, 0, 0, 0, 'Warlord Parjesh on Enrage'),
(91784, 201, 0, 'Get my point?', 14, 0, 100, 0, 0, 54186, 0, 'Warlord Parjesh to Warlord Parjesh'),
(91784, 202, 0, 'You can''t stop.... the storm...', 14, 0, 100, 0, 0, 54182, 0, 'Warlord Parjesh on death');

DELETE FROM `creature_text` WHERE `CreatureID`=91789;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(91789, 0, 0, 'It seems we have pests...', 14, 0, 100, 0, 0, 56655, 0, 'Lady Hatecoil on line of sight'),
(91789, 200, 0, 'Continue the ritual! I will handle these fools!', 14, 0, 100, 0, 0, 54194, 0, 'Lady Hatecoil on EnterCombat'),
(91789, 1, 0, 'Just you wait...', 14, 0, 100, 0, 0, 54201, 0, 'Lady Hatecoil'),
(91789, 2, 0, '|TInterface\\Icons\\Spell_Shaman_StaticShock:20|t%s starts to invoke a |cFFFF0000|Hspell:193597|h[Static Nova]|h|r. Get out of the water!', 41, 0, 100, 0, 0, 54201, 0, 'Lady Hatecoil'),
(91789, 3, 0, '|TInterface\\Icons\\Spell_Frost_SummonWaterElemental:20|t%s begins to cast |cFFFF0000|Hspell:193682|h[Beckon Storm]|h|r!', 41, 0, 100, 0, 0, 0, 0, 'Lady Hatecoil'),
(91789, 4, 0, 'The waters rise...', 14, 0, 100, 0, 0, 54204, 0, 'Lady Hatecoil'),
(91789, 5, 0, 'A storm is gathering...', 14, 0, 100, 0, 0, 54203, 0, 'Lady Hatecoil'),
(91789, 6, 0, 'Can you feel the winds? They come for you...', 14, 0, 100, 0, 0, 54195, 0, 'Lady Hatecoil to Player');

DELETE FROM `creature_text` WHERE `CreatureID`=91797;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(91797, 200, 0, 'You weaklings will drown beneath these waves!', 14, 0, 100, 0, 0, 54316, 0, 'King Deepbeard to Player'),
(91797, 1, 0, 'How long can you hold your breath, I wonder?', 14, 0, 100, 0, 0, 54312, 0, 'King Deepbeard'),
(91797, 1, 1, 'Pity you cannot survive without air!', 14, 0, 100, 0, 0, 54313, 0, 'King Deepbeard'),
(91797, 2, 0, 'The earth trembles before the rising tide!', 14, 0, 100, 0, 0, 54315, 0, 'King Deepbeard'),
(91797, 3, 0, '|TInterface\\Icons\\spell_frost_summonwaterelemental:20|t%s begins to cast |cFFFF0000|Hspell:193051|h[Call the Seas]|h|r!', 41, 0, 100, 0, 0, 54310, 0, 'King Deepbeard'),
(91797, 3, 1, 'Seas! Obey my command!', 14, 0, 100, 0, 0, 54310, 0, 'King Deepbeard'),
(91797, 4, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 0, 'King Deepbeard'),
(91797, 202, 0, 'You haven''t won. She is almost here...', 14, 0, 100, 0, 0, 54318, 0, 'King Deepbeard to Player');

DELETE FROM `creature_text` WHERE `CreatureID`=91808;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(91808, 0, 0, '|TInterface\\Icons\\inv_misc_volatilewater:20|t%s begins to |cFFFF0000|Hspell:191873|h[Submerge]|h|r!', 41, 0, 100, 0, 0, 0, 0, 'Serpentrix');

DELETE FROM `creature_text` WHERE `CreatureID`=96028;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(96028, 0, 0, 'THE STORM AWAKENS.', 14, 0, 100, 0, 0, 54318, 0, 'Wrath of Azshara'),
(96028, 200, 0, 'THE TIDES RISE!', 14, 0, 100, 0, 0, 54207, 0, 'Wrath of Azshara to Player'),
(96028, 201, 0, 'ALL WILL BE ERADICATED!', 14, 0, 100, 0, 0, 54205, 0, 'Wrath of Azshara to Player'),
(96028, 201, 1, 'CRUSH!', 14, 0, 100, 0, 0, 54213, 0, 'Wrath of Azshara'),
(96028, 1, 0, '|TInterface\\Icons\\inv_misc_herb_stormvine:20|t%s begins to emit a |cFFFF0000|Hspell:192985|h[Cry of Wrath]|h|r!', 41, 0, 100, 0, 0, 54208, 0, 'Wrath of Azshara'),
(96028, 2, 0, 'TEMPEST!', 14, 0, 100, 0, 0, 54208, 0, 'Wrath of Azshara'),
(96028, 3, 0, '|TInterface\\Icons\\INV_Enchant_EssenceArcaneSmall:20|t%s targets |cFFFF0000$n|r with a massive |cFFFF0000|Hspell:192708|h[Arcane Bomb]|h|r!', 41, 0, 100, 0, 0, 54215, 0, 'Wrath of Azshara to Player'),
(96028, 202, 0, 'SEEK... MAGIC...', 14, 0, 100, 0, 0, 54215, 0, 'Wrath of Azshara to Player'),
(96028, 202, 1, 'WATER... ETERNAL...', 14, 0, 100, 0, 0, 54206, 0, 'Wrath of Azshara to Player');

DELETE FROM `creature_text` WHERE `CreatureID` IN (97171, 98173, 100216, 100248, 100249, 100250);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(97171, 0, 0, 'The shielding weakens!', 14, 0, 100, 0, 0, 0, 0, 'Hatecoil Arcanist to Player'),
(97171, 0, 1, 'Lady Hatecoil is vulnerable! She must not fall!', 14, 0, 100, 0, 0, 0, 0, 'Hatecoil Arcanist to Player'),
(98173, 0, 0, 'We need more time!', 14, 0, 100, 0, 0, 54207, 0, 'Mystic Ssa''veh to Player'),
(100216, 0, 0, 'The landwalkers are here! We will drive them back by salt and scale!', 14, 0, 100, 0, 0, 0, 0, 'Hatecoil Wrangler to Player'),
(100248, 0, 0, 'No! The ritual is not yet complete!', 14, 0, 100, 0, 0, 0, 0, 'Ritualist Lesha to Player'),
(100249, 0, 0, 'The bindings weaken...', 14, 0, 100, 0, 0, 0, 0, 'Channeler Varisz to Player'),
(100250, 0, 0, 'It is still forming!', 14, 0, 100, 0, 0, 0, 0, 'Binder Ashioi to Player');

-- Lightning Strikes
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 192794;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 192794, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Lightning Strikes can implicitly hit only players');

DELETE FROM `spell_script_names` WHERE `spell_id` = 192794;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(192794, 'spell_eoa_lightning_strikes_damage');

-- Disable non-implemented achievements
DELETE FROM `criteria_data` WHERE `criteria_id` IN (29398, 29404);
INSERT INTO `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(29398, 11, 0, 0, 'achievement_but_you_say_hes_just_a_friend'),
(29404, 11, 0, 0, 'achievement_stay_salty');

UPDATE creature SET SpawnDist = 0 WHERE id = 91808;

DELETE FROM scenarios WHERE map IN (1456, 1501);
INSERT INTO scenarios VALUES
(1456, 0, 1169, 1169),
(1501, 0, 1166, 1166);

DELETE FROM spell_area WHERE spell IN (191815, 212614, 191816, 212615);
INSERT INTO spell_area VALUES
(191815, 8040, 0, 0, 0, -1, 0, 2, 2, 64, 11),
(212614, 8040, 0, 0, 0, -1, 0, 2, 2, 64, 11),
(191816, 8040, 0, 0, 0, -1, 0, 2, 2, 64, 11),
(212615, 8040, 0, 0, 0, -1, 0, 2, 2, 64, 11);

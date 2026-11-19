-- Spawns
SET @CGUID := 450000;
DELETE FROM `creature` WHERE `guid`= @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 122450, 1712, 8638, 9280, "14,15,16,17", 169, 0, 0, 0, -3292.458, 9822.647, -63.49804, 4.729585, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Garothi Worldbreaker

SET @OGUID := 300000;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278488, 1712, 8638, 8638, '14,15,16,17', 169, 0, -3330.073, 9823.818, -66.76595, 4.92183, 0.02519464, 0.01764011, -0.6292171, 0.7766207, 7200, 255, 1, 30706), -- Rock (Area: -Unknown- - Difficulty: 15)
(@OGUID+1, 253128, 1712, 8638, 8638, '14,15,16,17', 169, 0, -3429.696, 9523.502, 14.88574, 0.254501, 0, 0, 0.1269073, 0.9919146, 7200, 255, 1, 30706), -- Instance Portal (Area: -Unknown- - Difficulty: 15)
(@OGUID+2, 277365, 1712, 8638, 8638, '14,15,16,17', 169, 0, -3324.769, 9814.266, -68.07056, 2.050762, 0, 0, 0.8549118, 0.5187734, 7200, 255, 1, 30706); -- Collision (Area: -Unknown- - Difficulty: 15)

-- Add Missing Gameobject Template Data
DELETE FROM `gameobject_template` WHERE `entry` IN (278488, 277365, 253128);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(278488, 0, 46128, 'Rock', '', '', '', 0.5500001, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30706), -- Rock
(277365, 0, 6391, 'Collision', '', '', '', 3.289998, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30706), -- Collision
(253128, 5, 6450, 'Instance Portal', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30706); -- Instance Portal

-- Gameobject Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278488, 277365, 253128);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(277365, 0, 48), -- Collision
(253128, 0, 32), -- Instance Portal
(278488, 0, 48); -- Rock

-- Instance Script
DELETE FROM `instance_template` WHERE `map`= 1712;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1712, 0, 'instance_antorus_the_burning_throne', 0);

-- Instance Encounter
DELETE FROM `instance_encounters` WHERE `entry`= 2076;
INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES
(2076, 0, 122450, 0, 'Garothi Worldbreaker');

-- Template Updates
-- Garothi Worldbreaker
UPDATE `creature_template` SET `minlevel`= 113, `maxlevel`= 113, `faction`= 14, `unit_class`= 1, `InhabitType`= 12,  `unit_flags2`= 4227072, `VehicleId`= 5430, `mechanic_immune_mask`= 650854271, `ScriptName`= 'boss_garothi_worldbreaker', `flags_extra` = 1 WHERE `entry`= 122450;
-- Annihilator
UPDATE `creature_template` SET `minlevel`= 113, `maxlevel`= 113, `faction`= 14, `unit_class`= 1, `InhabitType`= 12, `unit_flags`= 33554432, `unit_flags2`= 32768, `baseattacktime`= 1500, `VehicleId`= 5430, `mechanic_immune_mask`= 650854271 WHERE `entry`= 122778;
-- Decimator
UPDATE `creature_template` SET `minlevel`= 113, `maxlevel`= 113, `faction`= 14, `unit_class`= 1, `InhabitType`= 12, `unit_flags`= 33554432, `unit_flags2`= 32768, `baseattacktime`= 1500, `VehicleId`= 5430, `mechanic_immune_mask`= 650854271 WHERE `entry`= 122773;
-- Annihilation
UPDATE `creature_template` SET `minlevel`= 113, `maxlevel`= 113, `faction`= 14, `unit_class`= 1, `InhabitType`= 8, `unit_flags`= 33554432, `unit_flags2`= 2048, `flags_extra`= 128 WHERE `entry`= 122818;
-- Garothi Worldbreaker (Surging Fel)
UPDATE `creature_template` SET `minlevel`= 113, `maxlevel`= 113, `faction`= 14, `unit_class`= 1, `InhabitType`= 12, `unit_flags`= 33554432, `unit_flags2`= 34816, `flags_extra`= 128 WHERE `entry`= 124167;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_garothi_apocalypse_drive',
'spell_garothi_fel_bombardment_selector',
'spell_garothi_fel_bombardment_warning',
'spell_garothi_fel_bombardment_periodic',
'spell_garothi_searing_barrage_periodic',
'spell_garothi_searing_barrage_dummy',
'spell_garothi_searing_barrage_selector',
'spell_garothi_decimation_selector',
'spell_garothi_decimation_warning',
'spell_garothi_carnage',
'spell_garothi_annihilation_selector',
'spell_garothi_annihilation_triggered',
'spell_garothi_eradication',
'spell_garothi_surging_fel',
'spell_garothi_cannon_chooser');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(244152, 'spell_garothi_apocalypse_drive'),
(244150, 'spell_garothi_fel_bombardment_selector'),
(246220, 'spell_garothi_fel_bombardment_warning'),
(244536, 'spell_garothi_fel_bombardment_periodic'),
(244398, 'spell_garothi_searing_barrage_dummy'),
(246369, 'spell_garothi_searing_barrage_dummy'),
(246360, 'spell_garothi_searing_barrage_selector'),
(244399, 'spell_garothi_decimation_selector'),
(244410, 'spell_garothi_decimation_warning'),
(244106, 'spell_garothi_carnage'),
(247572, 'spell_garothi_annihilation_selector'),
(244761, 'spell_garothi_annihilation_triggered'),
(244969, 'spell_garothi_eradication'),
(246655, 'spell_garothi_surging_fel'),
(245124, 'spell_garothi_cannon_chooser');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (122450, 122778, 122773);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(122450, 0, 0, 0, 0, 0, '246839'), -- 122450 (Garothi Worldbreaker) - Helmet
(122778, 0, 0, 0, 0, 0, '107829'), -- 122778 (Annihilator) - Update Interactions
(122773, 0, 0, 0, 0, 0, '107829'); -- 122773 (Decimator) - Update Interactions

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (122450, 122773);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Garothi Worldbreaker
(122450, 0, 0, 'Enemy combatants detected. Threat level nominal.', 14, 0, 100, 0, 0, 86397, 132426, 0, 'Garothi Worldbreaker - Aggro'),
(122450, 1, 0, 'Targets cleared.', 14, 0, 100, 0, 0, 86401, 132427, 0, 'Garothi Worldbreaker - Evade 1'),
(122450, 1, 1, 'Enemy combatants neutralized.', 14, 0, 100, 0, 0, 86974, 135270, 0, 'Garothi Worldbreaker - Evade 2'),
(122450, 1, 2, 'No hostile targets remaining. Continuing patrol.', 14, 0, 100, 0, 0, 86975, 135271, 0, 'Garothi Worldbreaker - Evade 3'),
(122450, 2, 0, '|TInterface\\ICONS\\Ability_BossFelMagnaron_HandEmpowered.blp:20|t %s is powering the |cFFF00000|Hspell:244152|h[Apocalypse Drive]|h|r!', 41, 0, 100, 0, 0, 0, 132631, 0, 'Garothi Worldbreaker - Announce Apocalypse Drive'),
(122450, 3, 0, 'Apocalypse drive engaged.', 14, 0, 100, 0, 0, 86399, 132433, 0, 'Garothi Worldbreaker - Apocalpyse Drive'),
(122450, 4, 0, '|TInterface\\ICONS\\ABILITY_WARRIOR_COLOSSUSSMASH.BLP:20|t The Garothi Worldbreaker rears back for |cFFF00000|Hspell:244969|h[Eradication]|h|r! Run away!', 41, 0, 100, 0, 0, 0, 138536, 0, 'Garothi Worldbreaker - Announce Eradication'),
(122450, 5, 0, 'Systems re-engaged, rerouting power. Weapons primed.', 14, 0, 100, 0, 0, 86400, 132434, 0, 'Garothi Worldbreaker - Finish Apocalypse Drive'),
(122450, 6, 0, 'Targets aquired.', 14, 0, 100, 0, 0, 86971, 135267, 0, 'Garothi Worldbreaker - Decimation 1'),
(122450, 6, 1, 'Targets acquired for decimation.', 14, 0, 100, 0, 0, 86393, 132429, 0, 'Garothi Worldbreaker - Decimation 2'),
(122450, 6, 2, 'Weapon system primed, target locked.', 14, 0, 100, 0, 0, 86395, 132431, 0, 'Garothi Worldbreaker - Decimation 3'),
(122450, 7, 0, 'Leave none alive.', 14, 0, 100, 0, 0, 86396, 132432, 0, 'Garothi Worldbreaker - Annihilation 1'),
(122450, 7, 1, 'Cannon primed for annihilation.', 14, 0, 100, 0, 0, 86394, 132430, 0, 'Garothi Worldbreaker - Annihilation 2'),
(122450, 8, 0, '|TInterface\\ICONS\\ABILITY_HUNTER_SNIPERSHOT.BLP:20|t You are targeted for |cFFF00000|Hspell:244536|h[Fel Bombardment]|h|r!', 42, 0, 100, 0, 0, 0, 132630, 0, 'Garothi Worldbreaker - Announce Fel Bombardment'),
(122450, 9, 0, 'Hostile destroyed.', 14, 0, 100, 0, 0, 86978, 135275, 0, 'Garothi Worldbreaker - Slay 1'),
(122450, 9, 1, 'Threat terminated.', 14, 0, 100, 0, 0, 86977, 135274, 0, 'Garothi Worldbreaker - Slay 2'),
(122450, 9, 2, 'Exterminated.', 14, 0, 100, 0, 0, 86976, 135273, 0, 'Garothi Worldbreaker - Slay 3'),
(122450, 10, 0, 'Critical system failure...', 14, 0, 100, 0, 0, 86398, 132428, 0, 'Garothi Worldbreaker - Death 1'),
(122450, 10, 1, 'Power core... rupturing...', 14, 0, 100, 0, 0, 86972, 135268, 0, 'Garothi Worldbreaker - Death 2'),
(122450, 10, 2, 'Termination imminent...', 14, 0, 100, 0, 0, 86973, 135269, 0, 'Garothi Worldbreaker - Death 3'),
-- Decimator
(122773, 0, 0, '|TInterface\\ICONS\\ABILITY_MAGE_FIRESTARTER.BLP:20|t You are targeted for |cFFF00000|Hspell:244410|h[Decimation]|h|r!', 42, 0, 100, 0, 0, 0, 132901, 0, 'Decimator - Announce Decimation');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (247572, 244761, 245237, 246012) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 247572, 0, 0, 51, 0, 5, 122818, 0, 0, 0, '', 'Annihilation - Target Annihilation'),
(13, 2, 245237, 0, 1, 51, 0, 5, 122773, 0, 0, 0, '', 'Empowered - Target Annihilator'),
(13, 2, 245237, 0, 2, 51, 0, 5, 122778, 0, 0, 0, '', 'Empowered - Target Decimator'),
(13, 1, 246012, 0, 0, 51, 0, 5, 122773, 0, 0, 0, '', 'Restore Health - Target Annihilator'),
(13, 1, 246012, 0, 1, 51, 0, 5, 122778, 0, 0, 0, '', 'Restore Health - Target Decimator');

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 122450 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
-- SUMMON_GROUP_ID_SURGING_FEL = 0
(122450, 0, 0, 124167, -3262, 9810.797, -63.93631, 4.577713, 8, 0),
(122450, 0, 0, 124167, -3277, 9810.8, -63.68398, 4.577713, 8, 0),
(122450, 0, 0, 124167, -3307, 9810.8, -63.85229, 4.577713, 8, 0),
(122450, 0, 0, 124167, -3322, 9810.8, -64.84264, 4.577713, 8, 0),
(122450, 0, 0, 124167, -3292, 9810.797, -64.07504, 4.577713, 8, 0);

-- Vehicle Accessories
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 122450;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(122450, 122773, 1, 1, 'Garothi Worldbreaker - Decimator', 6, 200), -- Garothi Worldbreaker - Decimator
(122450, 122778, 0, 1, 'Garothi Worldbreaker - Annihilator', 6, 200); -- Garothi Worldbreaker - Annihilator

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 122450;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(122450, 237873, 1, 1);

-- Model Data
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (76534, 77168, 77029);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`) VALUES
(76534, 20.02365, 30, 0),
(77168, 3.944656, 75, 0),
(77029, 3.944656, 75, 0);

-- Areatriggers
DELETE FROM `areatrigger_template` WHERE `Id` IN (15496, 0);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(15496, 0, 4, 4, 4, 0, 0, 0, 0, 'at_garothi_annihilation', 26365),
(0, 3, 4, 0, 0, 0, 0, 0, 0, '', 26365);

DELETE FROM `spell_areatrigger` WHERE `SpellMiscId` IN (10662, 10876);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`) VALUES
(10662, 15496),
(10876, 0);

DELETE FROM `areatrigger_template_polygon_vertices` WHERE `AreaTriggerId`= 0;
INSERT INTO `areatrigger_template_polygon_vertices` (`AreaTriggerId`, `Idx`, `VerticeX`, `VerticeY`, `VerifiedBuild`) VALUES
(0, 0, 0, -15, 26365),
(0, 1, 0, 15, 26365),
(0, 2, 100, -15, 26365),
(0, 3, 100, -15, 26365);

-- Procs
DELETE FROM `spell_proc` WHERE `SpellId`= 244106;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(244106, 0, 0, 0, 0x00000008, 0, 0, 0, 0, 0);

-- Custom Attributes
DELETE FROM `spell_custom_attr` WHERE `entry` IN (244761, 244410);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(244761, 0x8),
(244410, 0x1000);

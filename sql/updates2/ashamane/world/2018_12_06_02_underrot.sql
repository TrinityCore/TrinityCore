DELETE FROM `areatrigger_template` WHERE `Id` IN (17135);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(17135, 4, 4, 2.5, 2.5, 20, 20, 0.3, 0.3, 'at_creeping_rot', 27481);

DELETE FROM `creature_summon_groups` WHERE summonerID = 1841 AND summonerType = 2;
INSERT INTO `creature_summon_groups` VALUES
(1841, 2, 1, 144306, 1024.94, 1050.99, 33.4707, 0.8341,  8, 0),
(1841, 2, 1, 144306, 1025.44, 1066.86, 33.3309, 5.471, 	 8, 0),
(1841, 2, 1, 144306, 1040.15, 1066.87, 33.4068, 3.99352, 8, 0),
(1841, 2, 1, 144306, 1041.1,  1051.63, 33.536,  2.44391, 8, 0);

DELETE FROM creature WHERE id = 144306;
UPDATE creature_template SET scriptname = "npc_underrot_volatile_pod" WHERE entry = 139127;

DELETE FROM spell_script_names WHERE scriptname = "aura_cragmaw_tantrum_energy";
INSERT INTO spell_script_names VALUES
(271775, "aura_cragmaw_tantrum_energy");

DELETE FROM `areatrigger_template` WHERE `Id`=18227;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(18227, 4, 0, 2, 2, 10, 10, 3, 3, "at_underrot_volatile_pod", 28153);

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=13726 AND `AreaTriggerId`=18227);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(13726, 18227, 0, 0, 0, 0, 0, 3000, 3000, 28153); -- SpellId : 273300

DELETE FROM `spell_areatrigger_splines` WHERE `SpellMiscId` = 13726;
INSERT INTO `spell_areatrigger_splines` (`SpellMiscId`, `Idx`, `X`) VALUES
(13726, 0, 0),
(13726, 1, 40);

UPDATE creature_template SET speed_walk = 0.5, speed_run = 0.57143 WHERE entry = 137458;

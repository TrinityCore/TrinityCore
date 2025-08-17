--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_netherstorm_detonate_teleporter' WHERE `ScriptName` = 'spell_detonate_teleporter';

-- Shouldn't be used for teleport, only to trigger events
DELETE FROM `areatrigger_teleport` WHERE `ID` = 4523;

DELETE FROM `gameobject` WHERE `guid` = 91320 AND `id` = 184606;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(91320,184606,530,0,0,1,1,4799.248,3779.397,211.75,0,0,0,0,1,300,0,1,'',NULL,0);

UPDATE `spell_script_names` SET `ScriptName` = 'spell_netherstorm_socrethars_stone' WHERE `ScriptName` = 'spell_item_socrethars_stone';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_hellfire_peninsula_purify_helboar_meat' WHERE `ScriptName` = 'spell_item_purify_helboar_meat';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_hellfire_peninsula_absorb_eye_of_grillok' WHERE `ScriptName` = 'spell_item_absorb_eye_of_grillok';

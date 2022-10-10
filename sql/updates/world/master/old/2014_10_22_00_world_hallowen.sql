/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- Fix LFG entrance.
UPDATE `lfg_entrances` SET `position_x` = '1124.57', `position_y` = '511.299', `position_z` = '0.9892', `orientation` = '1.53889' WHERE `lfg_entrances`.`dungeonId` = 285;

--
UPDATE `instance_template` SET `script` = 'instance_scarlet_monastery_old' WHERE `instance_template`.`map` = 189;
UPDATE `instance_template` SET `script` = 'instance_scarlet_monastery' WHERE `instance_template`.`map` = 1004;

--
UPDATE `creature_template` SET `InhabitType` = '5' WHERE `creature_template`.`entry` = 23682;

--
DELETE FROM game_event_gameobject WHERE guid in (SELECT guid FROM gameobject WHERE id in (186267, 186269, 186314));
DELETE FROM `gameobject` WHERE `id` in (186267, 186269, 186314);

INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES
(186267, 1004, 6109, 6384, 2, 1, 1105.59, 615.93, 1.26502, 0.298859, 0, 0, 0.148874, 0.988856, 300, 0, 1, 0),
(186269, 1004, 6109, 6384, 2, 1, 1105.81, 614.33, 0.0722986, 0.277653, 0, 0, 0.138381, 0.990379, 300, 0, 1, 0),
(186269, 1004, 6109, 6384, 2, 1, 1103.89, 615.79, 0.0294258, 0.062454, 0, 0, 0.0312219, 0.999512, 300, 0, 1, 0),
(186269, 1004, 6109, 6384, 2, 1, 1105.32, 617.699, 0.0985973, 0.270585, 0, 0, 0.13488, 0.990862, 300, 0, 1, 0),
(186269, 1004, 6109, 6384, 2, 1, 1107.45, 616.274, 0.184674, 0.294147, 0, 0, 0.146544, 0.989204, 300, 0, 1, 0),
(186314, 1004, 6109, 6384, 2, 1, 1097.96, 613.258, 0.10568, 0.42295, 0, 0, 0.209902, 0.977722, 300, 0, 1, 0);
INSERT INTO game_event_gameobject (eventEntry, game_event_gameobject.guid) SELECT 12, guid FROM  gameobject WHERE `id` in (186267, 186269, 186314);

-- Hack Q29075 Q29376
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('95958', 'spell_hallowen_torch_wickerman');
UPDATE `gameobject` SET state = 1 WHERE `id` = 180433;
UPDATE `gameobject_template` SET `flags` = `flags` | 0x10, `ScriptName` = 'go_hallow_wickerman' WHERE entry  = 180433;
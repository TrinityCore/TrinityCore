/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

DELETE FROM `creature` WHERE id = 36600 AND phaseMask =1;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(36600, 648, 1, 1, 534.8264, 3270.589, 0.2805953, 1.675516, 120, 0, 0);

--
UPDATE `gameobject` SET `phaseMask` = `phaseMask` | 10124 WHERE `map` = 648 AND `phaseMask` = 18433;

--
DELETE FROM `conditions` WHERE `SourceGroup` = 10808 AND SourceTypeOrReferenceId = 15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '10808', '0', '0', '0', '9', '0', '14244', '0', '0', '0', '0', '', NULL);

--
UPDATE `quest_template` SET `CompleteScript` = '0' WHERE `Id` = 14245;
DELETE FROM `quest_end_scripts` WHERE id = 13;

--
UPDATE `quest_template` SET `SourceItemId` = '52484' WHERE `quest_template`.`Id` = 25122;

-- --------------------------------
--          PHASE 32768
-- --------------------------------

DELETE FROM spell_area WHERE spell = 73756 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('73756', '4720', '25184', '25265', '0', '0', '2', '1', '66', '74');

-- --------------------------------
--          PHASE 65536
-- --------------------------------

DELETE FROM spell_area WHERE spell = 74025 AND  area = 4720;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('74025', '4720', '25265', '0', '0', '0', '2', '1', '74', '0');
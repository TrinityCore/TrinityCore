-- HoL General Bjarngrim event Temporary Electrical Charge
-- Clear wrong aura
UPDATE `creature_addon` SET `auras`='' WHERE `guid` = 126981;

-- add spell link for Temporary Electrical Charge
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='-52098' AND `spell_effect`='52092';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
('-52098', '52092', '0', 'Charge Up - Temporary Electrical Charge');

-- Set 10 sec delay on platforms where boss gets Temporary Electrical Charge
UPDATE `waypoint_data` SET `delay`=10000 WHERE `id`=1269810 AND `point` IN (2, 5, 11, 14);

-- Cast self Charge Up to get Temporary Electrical Charge
DELETE FROM `waypoint_scripts` WHERE `id`=12698101;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(12698101, 0, 14, 52092, 1, 0, 0, 0, 0, 0, 855),
(12698101, 2, 15, 52098, 1, 0, 0, 0, 0, 0, 856);
UPDATE `waypoint_data` SET `action`=12698101 WHERE `id`=1269810 AND `point` IN (5, 14);

-- Remove aura Temporary Electrical Charge
DELETE FROM `waypoint_scripts` WHERE `id`=12698102;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(12698102, 0, 14, 52092, 1, 0, 0, 0, 0, 0, 857);
UPDATE `waypoint_data` SET `action`=12698102 WHERE `id`=1269810 AND `point` IN (2, 3, 4, 11, 12, 13);

-- Lightning Struck achievement
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=6835;
DELETE FROM `achievement_criteria_data` WHERE `type`=11 AND `criteria_id`=6835;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6835, 11, 0, 0, 'achievement_lightning_struck');

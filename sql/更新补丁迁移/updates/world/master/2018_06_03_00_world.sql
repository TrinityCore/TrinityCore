-- 
DELETE FROM `creature` WHERE `guid`=252238;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(252238, 40825, 643, 5004, 5004, 3, 169, 0, 0, 0, -164.4549, 636.033, 286.4521, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365);

UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry` IN (40788,49082);
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry` IN (40825,49072);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=40825;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(40825, 40788, 0, 0, 'Mindbender Ghur sha', 8, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=40825 AND `spell_id`=69063;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(40825, 69063, 1, 0);

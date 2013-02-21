-- Insert missing NPCs into the instance normal

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) 
VALUES(38112, 668, 1, 1, 0, 1, 5338.22, 1978.67, 709.319, 2.25591, 300, 0, 0, 377468, 0, 0, 0, 0, 0);


INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) 
VALUES(38113, 668, 1, 1, 0, 1, 5278.55, 2035.78, 709.32, 5.53337, 300, 0, 0, 539240, 0, 0, 0, 0, 0);



insert into `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) 
values('36723','2321','1','1','1','1042','1','6259.79','438.038','23.7918','0.617761','275','10','0','222','0','1','0','0','0');

-- Update unit flags for creature error fix "has enpty threat list" not agro boss - instance normal



UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38112;
UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38113;
UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38172;
UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38173;
UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38175;
UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38176;
UPDATE `creature_template` SET `unit_flags`= 528 WHERE `entry`=38177;


-- Update Script Name for Frostsworn General NPC

UPDATE `creature_template` SET `ScriptName`= "npc_frostsworn_general" WHERE `entry`=36723;

-- Delete NPCs Lich King and Uther unused in DB

DELETE FROM `world`.`creature` WHERE `creature`.`guid` = 202294;
DELETE FROM `world`.`creature` WHERE `creature`.`guid` = 202301;
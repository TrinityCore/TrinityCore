-- Delete mistake and rebuild data

DELETE FROM `creature` WHERE `id`=38112;
DELETE FROM `creature` WHERE `id`=38113;
DELETE FROM `creature` WHERE `id`=36723;

-- Insert missing NPCs into the instance normal

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) 
VALUES(NULL,38112, 668, 3, 1, 0, 1, 5338.22, 1978.67, 709.319, 2.25591, 300, 0, 0, 377468, 0, 0, 0, 0, 0);


INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) 
VALUES(NULL,38113, 668, 3, 1, 0, 1, 5278.55, 2035.78, 709.32, 5.53337, 300, 0, 0, 539240, 0, 0, 0, 0, 0);



INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) 
VALUES(NULL,36723,668,3,1,0,1,5413.99,2116.61,707.694,3.90288,300,0,0,315000,0,0,0,0,0);



-- Update unit flags for creature error fix "has empty threat list"  - Instance Normal

UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38112;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38113;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38172;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38173;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38175;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38176;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38177;


-- Update unit flags for creature error fix "has empty threat list"  - Instance Heroic

UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38599;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38603;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38524;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38525;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38563;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38544;
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry`=38564;
UPDATE `creature_template` SET `unit_flags`= 64  WHERE `entry`=37720;



-- Update Script Name for Frostsworn General NPC

UPDATE `creature_template` SET `ScriptName`= "npc_frostsworn_general" WHERE `entry`=36723;

-- Delete NPCs Lich King and Uther unused in DB

DELETE FROM `world`.`creature` WHERE `creature`.`guid` = 202294;
DELETE FROM `world`.`creature` WHERE `creature`.`guid` = 202301;

-- Delete Says And Rebuild

DELETE FROM `creature_text` WHERE `entry` = 36723;

-- Says Frostsworn General

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) 
VALUES(36723,0,0,"You are not worthy to face the Lich King!",12,0,100,0,0,16921,"HOR");

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) 
VALUES(36723,1,0,"Master, I have failed...!",12,0,100,0,0,16922,"HOR");


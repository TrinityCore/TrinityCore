-- Thanks to @Xanvial <-PRO <-DEV for clean codestyle on this sql Nice Job Man!

SET @CGUID := xxx;  -- set by dev

-- Delete mistake/unused creature and rebuild data
DELETE FROM `creature` WHERE `id` IN (38112, 38113, 36723);
DELETE FROM `creature` WHERE `guid` IN (202294, 202301);    -- Lich King and Uther
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGUID+0, 38112, 668, 3, 1, 0, 1, 5338.22, 1978.67, 709.319, 2.25591, 300, 0, 0, 377468, 0, 0, 0, 0, 0),
(@CGUID+1, 38113, 668, 3, 1, 0, 1, 5278.55, 2035.78, 709.32, 5.53337, 300, 0, 0, 539240, 0, 0, 0, 0, 0),
(@CGUID+2, 36723, 668, 3, 1, 0, 1, 5413.99, 2116.61, 707.694, 3.90288, 300, 0, 0, 315000, 0, 0, 0, 0, 0);

-- Update unit flags for creature error fix "has empty threat list"  - Instance Normal and Heroic
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry` IN (38112, 38113, 38172, 38173, 38175, 38176, 38177, 38599, 38603, 38524, 38525, 38563, 38544, 38564);
UPDATE `creature_template` SET `unit_flags`= 64  WHERE `entry`= 37720;

-- Update Script Name for Frostsworn General NPC
UPDATE `creature_template` SET `ScriptName`= "npc_frostsworn_general" WHERE `entry`=36723;

-- Delete Says And Rebuild
DELETE FROM `creature_text` WHERE `entry` = 36723;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36723,0,0,"You are not worthy to face the Lich King!",12,0,100,0,0,16921,"HOR"),
(36723,1,0,"Master, I have failed...!",12,0,100,0,0,16922,"HOR");
--  Gluth's emote texts
DELETE FROM `creature_text` WHERE `entry` = '15932';
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15932,0,0,41,0,100,"gluth EMOTE_ZOMBIE","%s spots a nearby zombie to devour!"),
(15932,1,0,41,0,100,"gluth EMOTE_ENRAGE","%s becomes enraged!"),
(15932,2,0,41,0,100,"gluth EMOTE_DECIMATE","%s decimates all nearby flesh!");

-- Zombie's Infected Wound Aura
DELETE FROM `creature_template_addon` WHERE `entry` IN (16360, 30303);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`,`emote`, `auras`)
VALUES
(16360, 0, 0, 0, 0, 0, 29307),
(30303, 0, 0, 0, 0, 0, 29307);

-- Add missing text and update old one
-- Malygos
UPDATE `creature_text` SET `probability`=100 WHERE `entry`=28859; -- Was at 0 for some reason
UPDATE `creature_text` SET `text`='Unthinkable! The mortals will destroy... everything! My sister, what have you...',`sound`=14540 WHERE `entry`=28859 AND `groupid`=14 AND `id`=0;
DELETE FROM `creature_text` WHERE `entry`=28859 AND `groupid` IN (15,16);
DELETE FROM `creature_text` WHERE `entry`=30084;
INSERT INTO `creature_text` (`entry`,`groupid`,`text`,`type`,`probability`,`sound`,`comment`) VALUES
(28859,15, '%s fixes his eyes on you!', 42,100,0, 'Malygos'),
(28859,16, 'I am without limits here. The rules of your cherished reality do not apply. In this realm, I am in control!',14,100,14515, 'Malygos'),
(30084,0, 'A Power Spark forms from a nearby rift!',41,100,14522, 'Power spark to portal');
-- Alexstrasza, add missing sounds
UPDATE `creature_text` SET `probability`=100,`sound`=14406 WHERE `entry`=32295 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `probability`=100,`sound`=14407 WHERE `entry`=32295 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `probability`=100,`sound`=14408 WHERE `entry`=32295 AND `groupid`=2 AND `id`=0;
UPDATE `creature_text` SET `probability`=100,`sound`=14409 WHERE `entry`=32295 AND `groupid`=3 AND `id`=0;

-- Update portal InhabitType, otherwise it falls on summon
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=30118;

-- Update drakes templates
UPDATE `creature_template` SET `unit_flags`=8,`InhabitType`=4 WHERE `entry`=30161; -- no fly aura present only enabled gravity in sniffs

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (30084,30161);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30084,0,0,50331648,1,0,'55845'), -- Power Spark
(30161,0,0,50331648,1,0,'60534'); -- Wyrmrest Skytalon (uses no fly aura)

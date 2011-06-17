UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=29598; -- Icefang
UPDATE `creature_template` SET `spell1`=54897, `spell2`=54907, `spell3`=54788 WHERE `entry`=29602; -- Icefang
-- Last spell (spell3) shouldn't be show to the client, core implementation of vehicle spells needs to change.
DELETE FROM `creature_template_addon` WHERE `entry`=29598;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29598,0,0,1,0, NULL); -- Icefang

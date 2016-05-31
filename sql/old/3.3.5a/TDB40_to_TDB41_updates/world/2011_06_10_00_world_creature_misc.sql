-- Template updates for creature 33346 (XE-321 Boombot)
UPDATE `creature_template` SET `speed_run`=0.42857 WHERE `entry`=33346; -- XE-321 Boombot
-- Addon data for creature 33346 (XE-321 Boombot)
DELETE FROM `creature_template_addon` WHERE `entry`=33346;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33346,0,0,1,0, NULL); -- XE-321 Boombot

-- Template updates for creature 33344 (XM-024 Pummeller)
-- Addon data for creature 33344 (XM-024 Pummeller)
DELETE FROM `creature_template_addon` WHERE `entry`=33344;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33344,0,0,1,0, NULL); -- XM-024 Pummeller

-- Template updates for creature 33343 (XS-013 Scrapbot)
UPDATE `creature_template` SET `speed_run`=0.42857 WHERE `entry`=33343; -- XS-013 Scrapbot
-- Addon data for creature 33343 (XS-013 Scrapbot)
DELETE FROM `creature_template_addon` WHERE `entry`=33343;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33343,0,0,1,0, NULL); -- XS-013 Scrapbot

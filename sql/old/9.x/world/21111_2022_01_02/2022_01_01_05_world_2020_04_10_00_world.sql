-- 
UPDATE `creature` SET `modelid`=0 WHERE `id`=37592;
UPDATE `creature_template` SET `gossip_menu_id`=10925  WHERE `entry` IN (37618);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2  WHERE `entry` IN (37614,37580);
UPDATE `creature_template` SET `gossip_menu_id`=10922  WHERE `entry` IN (37592,37591,37607,37606); -- must be changed to 10923 for the summoned npcs once Forgemaster Garfrost killed
-- missing gossip used by Arthas in COS "Are you ready to face Mal'Ganis with me?"
DELETE FROM `gossip_menu` WHERE  `MenuId`=9712 AND `TextId`=13287;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(9712, 13287, 11159); -- 26499

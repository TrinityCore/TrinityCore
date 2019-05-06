-- 
SET @MENUID := 2421;
UPDATE `creature_template` SET `gossip_menu_id`=@MENUID WHERE `entry`=9273;
DELETE FROM `gossip_menu` WHERE `MenuID`=@MENUID;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(@MENUID, 3093, 0);

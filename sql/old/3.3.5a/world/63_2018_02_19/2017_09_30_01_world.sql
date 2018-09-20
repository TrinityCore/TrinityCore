-- 
SET @MENUID := 7513;
UPDATE `creature_template` SET `gossip_menu_id`=@MENUID WHERE `entry`=17637;
DELETE FROM `gossip_menu` WHERE `MenuID`=@MENUID;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(@MENUID, 9110, 0);

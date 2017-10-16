/*
-- 
SET @MENUID := 5817;
UPDATE `creature_template` SET `gossip_menu_id`=@MENUID WHERE `entry`=14436;
DELETE FROM `gossip_menu` WHERE `MenuID`=@MENUID;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(@MENUID, 6990, 0);
*/

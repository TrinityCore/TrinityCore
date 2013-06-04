UPDATE `creature_template` SET `gossip_menu_id`=10466 WHERE `entry`=33558;
UPDATE `creature_template` SET `gossip_menu_id`=10471 WHERE `entry`=33561;
UPDATE `creature_template` SET `gossip_menu_id`=10465 WHERE `entry`=33562;

SET @OLDGOSSIP := 21000;
SET @NEWGOSSIP := 9935;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21007;
SET @NEWGOSSIP := 9941;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21024;
SET @NEWGOSSIP := 9937;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21038;
SET @NEWGOSSIP := 9938;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21049;
SET @NEWGOSSIP := 9931;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21067;
SET @NEWGOSSIP := 9945;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21048;
SET @NEWGOSSIP := 9946;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21039;
SET @NEWGOSSIP := 9948;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21065;
SET @NEWGOSSIP := 9953;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21035;
SET @NEWGOSSIP := 9954;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21010;
SET @NEWGOSSIP := 9959;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21069;
SET @NEWGOSSIP := 9961;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21028;
SET @NEWGOSSIP := 9963;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21001;
SET @NEWGOSSIP := 9964;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21027;
SET @NEWGOSSIP := 9966;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21064;
SET @NEWGOSSIP := 9968;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21041;
SET @NEWGOSSIP := 9971;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21074;
SET @NEWGOSSIP := 9972;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21015;
SET @NEWGOSSIP := 9975;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

SET @OLDGOSSIP := 21019;
SET @NEWGOSSIP := 9980;
UPDATE `creature_template` SET `gossip_menu_id`=@NEWGOSSIP WHERE `gossip_menu_id`=@OLDGOSSIP;
UPDATE `gossip_menu` SET `entry`=@NEWGOSSIP WHERE `entry`=@OLDGOSSIP;
UPDATE `gossip_menu_option` SET `menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP;
UPDATE `conditions` SET `SourceGroup`=@NEWGOSSIP WHERE `SourceGroup`=@OLDGOSSIP AND `SourceTypeOrReferenceId`=15;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56278;

DELETE FROM `db_script_string` WHERE `entry`=2000000077;
INSERT INTO `db_script_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`)VALUES
(2000000077,'%s gestures to the pitcher of water sitting on the edge of the well.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

SET @GOSSIP := 4535;
SET @OLD := 663;
SET @NEW := 563;
UPDATE `conditions` SET `SourceEntry`=@NEW WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@GOSSIP AND `SourceEntry`=@OLD;
UPDATE `gossip_menu` SET `text_id`=@NEW WHERE `entry`=@GOSSIP AND `text_id`=@OLD;

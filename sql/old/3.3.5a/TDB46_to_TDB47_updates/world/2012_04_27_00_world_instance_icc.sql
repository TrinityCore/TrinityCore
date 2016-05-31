DELETE FROM `creature_text` WHERE `entry`=37813 AND `groupid`=14;
INSERT INTO `creature_text` (`entry`,`groupid`,`text`,`type`,`comment`) VALUES (37813,14,'%s''s Blood Beasts gain the scent of blood!',41,'Deathbringer Saurfang - EMOTE_SCENT_OF_BLOOD');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=72771;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,3,72771,31,3,38508,'Deathbringer Saurfang - Scent of Blood on Blood Beast');

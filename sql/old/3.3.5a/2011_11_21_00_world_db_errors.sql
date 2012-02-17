UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=11054;
UPDATE `conditions` SET `SourceTypeOrReferenceId`=17 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47305 AND `ConditionTypeOrReference`=20;
UPDATE `conditions` SET `SourceTypeOrReferenceId`=18, `SourceEntry`=36732, `ConditionTypeOrReference`=24 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47305 AND `ConditionTypeOrReference`=18;
UPDATE `smart_scripts` SET `target_param1`=35 WHERE `entryorguid`=2275 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_param1`=35 WHERE `entryorguid`=1806901 AND `source_type`=9 AND `id`=3;

DELETE FROM `db_script_string` WHERE `entry` IN (2000000102, 2000000103, 2000000104);
INSERT INTO `db_script_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(2000000102,'Oh, darn...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(2000000103,'Ok, let''s get started!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(2000000104,'... oops.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

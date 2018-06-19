-- ADB 735.00 world
UPDATE `updates` SET `state`='ARCHIVED';
UPDATE `version` SET `db_version`='ADB 735.00', `cache_id`=7 LIMIT 1;
INSERT IGNORE INTO `updates_include` VALUES ('$/sql/ashamane/old/world', 'ARCHIVED');

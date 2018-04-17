-- ADB 735.00 hotfixes
UPDATE `updates` SET `state`='ARCHIVED';
INSERT IGNORE INTO `updates_include` VALUES ('$/sql/ashamane/old/hotfixes', 'ARCHIVED');

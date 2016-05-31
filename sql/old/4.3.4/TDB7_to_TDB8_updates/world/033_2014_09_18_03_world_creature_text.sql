ALTER TABLE `creature_text`
  CHANGE `BroadcastTextID` `BroadcastTextId` MEDIUMINT(6) DEFAULT 0 NOT NULL  AFTER `sound`,
  ADD COLUMN `TextRange` TINYINT(3) UNSIGNED DEFAULT 0 NOT NULL AFTER `BroadcastTextId`;

-- Zone
UPDATE `creature_text` SET `TextRange`=2 WHERE `entry`=15214;

-- Map
UPDATE `creature_text` SET `TextRange`=3 WHERE `entry` IN (29, 14848, 22515, 26527, 27915, 30084);


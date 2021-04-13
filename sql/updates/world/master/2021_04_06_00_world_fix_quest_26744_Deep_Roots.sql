INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`, `Comment`) VALUES ('57', '60295', '1', '') ON DUPLICATE KEY UPDATE `Entry`=57;
UPDATE `gameobject_template` SET `Data1`='57' WHERE  `entry`=57;
UPDATE `gameobject_template` SET `castBarCaption`='Obtaining' WHERE  `entry`=57;

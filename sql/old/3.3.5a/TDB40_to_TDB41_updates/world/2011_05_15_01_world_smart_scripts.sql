DELETE FROM `smart_scripts` WHERE `entryorguid` = 4625 AND `source_type` = 0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` VALUES
(4625,0,0,0,1,0,100,3,0,1100,0,1100,11,7083,2,0,0,0,0,1,0,0,0,0,0,0,0,'Ward Keepers - Cast the Guard Spell'),
(4625,0,1,0,6,0,100,2,0,0,0,0,34,1,1,0,0,0,0,0,0,0,0,0,0,0,0,'Ward Keepers - Send Event on Die');

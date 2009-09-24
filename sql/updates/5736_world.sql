
UPDATE `creature_template` SET `ScriptName`='boss_krik_thir' where `entry`=28684;

INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (28684,-1601000, 'This kingdom belongs to the Scourge! Only the dead may enter.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'SAY_AGGRO boss_krik_thir'),
   (28684,-1601001, 'You were foolish to come.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'SAY_SLAY_1 boss_krik_thir'),
   (28684,-1601002, 'As Anub''Arak commands!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'SAY_SLAY_2 boss_krik_thir'),
   (28684,-1601003, 'I should be grateful. But I long ago lost the capacity.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 0, 0, 'SAY_DEATH boss_krik_thir');

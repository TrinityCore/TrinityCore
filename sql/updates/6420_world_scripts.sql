UPDATE `creature_template` SET `ScriptName`='npc_tyrion' WHERE `entry`=7766;
UPDATE `creature_template` SET `ScriptName`='npc_tyrion_spybot' WHERE `entry`=8856;
UPDATE `creature_template` SET `ScriptName`='npc_lord_gregor_lescovar' WHERE `entry`=1754;
UPDATE `creature_template` SET `ScriptName`='npc_marzon_silent_blade' WHERE `entry`=1755;

DELETE FROM `script_texts` WHERE `entry` IN (-1000499,-1000450,-1000451,-1000452,-1000453,-1000454,-1000455,-1000456,-1000457,-1000458,-1000459,-1000460,-1000461,-1000462,-1000463);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (8856,-1000499,'By your command!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (7766,-1000450,'Wait here. Spybot will make Lescovar come out as soon as possible. Be ready! Attack only after you''ve overheard their conversation.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (8856,-1000451,'Good day to you both. I would speak to Lord Lescovar.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1756,-1000452,'Of course. He awaits you in the library.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (8856,-1000453,'Thank you. The Light be with you both.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (8856,-1000454,'Milord, your guest has arrived. He awaits your presence.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1754,-1000455,'Ah, thank you kindly. I will leave you to the library while I tend to this small matter.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (8856,-1000456,'I shall use the time wisely, milord. Thank you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1754,-1000457,'It''s time for my meditation, leave me.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1756,-1000458,'Yes, sir!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1754,-1000459,'There you are. What news from Westfall?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1755,-1000460,'VanCleef sends word that the plans are underway. But he''s hear rumors about someone snooping about.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (1754,-1000461,'Hmm, it could be that meddle Shaw. I will see what I can discover. Be off with you. I''ll contact you again soon.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (7766,-1000462,'That''s it! That''s what you were waiting for! KILL THEM!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,''),
   (1755,-1000463,'The Defias shall succeed! No meek adventurer will stop us!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'');

DELETE FROM `script_waypoint` WHERE `entry` = 1754;
INSERT INTO `script_waypoint` VALUES
   (1754, 1, -8334.89, 394.130, 122.274, 0, ''),
   (1754, 2, -8335.58, 393.519, 122.275, 0, ''),
   (1754, 3, -8352.99, 379.932, 122.275, 0, ''),
   (1754, 4, -8356.65, 385.247, 122.275, 0, ''),
   (1754, 5, -8364.29, 395.317, 122.275, 0, ''),
   (1754, 6, -8361.75, 402.852, 122.275, 0, ''),
   (1754, 7, -8359.94, 410.92, 122.275, 0, ''),
   (1754, 8, -8362.84, 415.409, 122.275, 0, ''),
   (1754, 9, -8370.42, 424.6, 122.275, 0, ''),
   (1754, 10, -8380.45, 437.115, 122.275, 0, ''),
   (1754, 11, -8386.37, 444.906, 122.275, 0, ''),
   (1754, 12, -8388.5, 447.314, 123.275, 0, ''),
   (1754, 13, -8390.25, 449.247, 124.275, 0, ''),
   (1754, 14, -8392.84, 452.397, 123.761, 0, ''),
   (1754, 15, -8397.52, 457.326, 123.761, 0, ''),
   (1754, 16, -8402.42, 461.646, 123.761, 0, ''),
   (1754, 17, -8409.52, 462.677, 123.761, 0, '');

DELETE FROM `script_waypoint` WHERE `entry` = 8856;
INSERT INTO `script_waypoint` VALUES
   (8856, 1, -8409.34, 453.345, 123.761, 0, ''),
   (8856, 2, -8409.52, 462.677, 123.761, 0, ''),
   (8856, 3, -8402.42, 461.646, 123.761, 0, ''),
   (8856, 4, -8397.52, 457.326, 123.761, 0, ''),
   (8856, 5, -8392.84, 452.397, 123.761, 0, ''),
   (8856, 6, -8390.25, 449.247, 124.275, 0, ''),
   (8856, 7, -8388.5, 447.314, 123.275, 0, ''),
   (8856, 8, -8386.37, 444.906, 122.275, 0, ''),
   (8856, 9, -8380.45, 437.115, 122.275, 0, ''),
   (8856, 10, -8370.42, 424.6, 122.275, 0, ''),
   (8856, 11, -8362.84, 415.409, 122.275, 0, ''),
   (8856, 12, -8359.94, 410.92, 122.275, 0, ''),
   (8856, 13, -8361.75, 402.852, 122.275, 0, ''),
   (8856, 14, -8364.29, 395.317, 122.275, 0, ''),
   (8856, 15, -8356.65, 385.247, 122.275, 0, ''),
   (8856, 16, -8352.99, 379.932, 122.275, 0, ''),
   (8856, 17, -8335.58, 393.519, 122.275, 0, ''),
   (8856, 18, -8334.89, 394.13, 122.274, 0, ''); 

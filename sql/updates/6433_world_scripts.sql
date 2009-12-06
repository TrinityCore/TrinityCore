UPDATE `creature_template` SET `ScriptName` = 'npc_korrak_bloodrager' WHERE `entry`=30023;

DELETE FROM `script_texts` WHERE `entry` IN (-1571033 -1571034);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(30007,-1571033,'The champion of the Winterax trolls has challenged you, Treeofdoom! I hope you''re ready!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
(30007,-1571034,'Hailling from the distant mountains of Alterac, one of the fiercest competitors this arena has ever seen: KORRAK THE BLOODRAGER!!!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13363,1,0,0,'');

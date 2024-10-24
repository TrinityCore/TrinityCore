--
DELETE FROM `creature_template_npcbot_wander_nodes` WHERE `id` IN (2396,2406);
INSERT INTO `creature_template_npcbot_wander_nodes`(`id`,`name`,`mapid`,`zoneid`,`areaid`,`minlevel`,`maxlevel`,`flags`,`x`,`y`,`z`,`o`,`links`) VALUES
('2396','ArathiBasinSpawnA','529','3358','3417','20','80','3','1289.51','1286.41','-14.466','3.89804','2397:0 '),
('2406','ArathiBasinSpawnH','529','3358','3418','20','80','5','704.074','704.457','-16.4305','0.79572','2407:0 ');

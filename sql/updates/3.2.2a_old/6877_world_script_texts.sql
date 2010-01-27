DELETE FROM `script_texts` WHERE `entry` IN (-1000464,-1000465,-1000466,-1000467,-1000468);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (349,-1000464,'My wounds are grave. Forgive my slow pace but my injuries won''t allow me to walk any faster.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (349,-1000465,'Ah, fresh air, at last! I need a moment to reset.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (349,-1000466,'The Blackrock infestation is thick in these parts. I will do my best to keep the pace. Let''s go!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (349,-1000467,'Marshal Marris, sir. Corporal Keeshan of the 12th Sabre Regiment returned from battle and reporting for duty!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
   (349,-1000468,'Brave adventurer, thank you for rescuing me! I am sure Marshal Marris will reward your kind deed.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'');

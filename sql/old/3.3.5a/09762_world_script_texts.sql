DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000522 AND -1000517;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1000517,'A-Me good. Good, A-Me. Follow... follow A-Me. Home. A-Me go home.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_ame - SAY_READY'),
(0,-1000518,'$c, no hurt A-Me. A-Me good.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_ame - SAY_AGGRO1'),
(0,-1000519,'Good... good, A-Me. A-Me good. Home. Find home.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_ame - SAY_SEARCH'),
(0,-1000520,'Danger. Danger! $c try hurt A-Me.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_ame - SAY_AGGRO2'),
(0,-1000521,'Bad, $c. $c, bad!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_ame - SAY_AGGRO3'),
(0,-1000522,'A-Me home! A-Me good! Good A-Me. Home. Home. Home.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_ame - SAY_FINISH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000525 AND -1000523;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1000523,'Saeed is currently engaged or awaiting orders to engage. You may check directly east of me and see if Saeed is ready for you. If he is not present then he is off fighting another battle. I recommend that you wait for him to return before attacking Dimensius.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,4,0,0,'npc_professor_dabiri - WHISPER_DABIRI'),
(0,-1000524,'Bessy, is that you?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_bessy - SAY_THADELL_1'),
(0,-1000525,'Thank you for bringing back my Bessy, $N. I couldn''t live without her!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_bessy - SAY_THADELL_2');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000574 AND -1000571;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1000571,'Ok let''s get out of here!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_isla_starmane - SAY_PROGRESS_1'),
(0,-1000572,'You sure you''re ready? Take a moment.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_isla_starmane - SAY_PROGRESS_2'),
(0,-1000573,'Alright, let''s do this!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_isla_starmane - SAY_PROGRESS_3'),
(0,-1000574,'Ok, I think I can make it on my own from here. Thank you so much for breaking me out of there!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'npc_isla_starmane - SAY_PROGRESS_4');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000621 AND -1000606;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1000606,'Come, $N. Lord Stormrage awaits.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'OVERLORD_SAY_1'),
(0,-1000607,'Lord Illidan will be here shortly.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'OVERLORD_SAY_2'),
(0,-1000609,'But... My lord, I do not understand. $N... He is the orc that has...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'OVERLORD_SAY_4'),
(0,-1000610,'It will be done, my lord.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'OVERLORD_SAY_5'),
(0,-1000611,'So you thought to make a fool of Mor''ghor, eh? Before you are delivered to Lord Illidan, you will feel pain that you could not know to exist. I will take pleasure in exacting my own vengeance.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,25,'OVERLORD_SAY_6'),
(0,-1000612,'Warriors of Dragonmaw, gather ''round! One among you has attained the rank of highlord! Bow your heads in reverence! Show your respect and allegiance to Highlord $N!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,22,'OVERLORD_YELL_1'),
(0,-1000613,'All hail Lord Illidan!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,66,'OVERLORD_YELL_2'),
(0,-1000614,'What is the meaning of this, Mor''ghor?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'LORD_ILLIDAN_SAY_1'),
(0,-1000615,'SILENCE!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,22,'LORD_ILLIDAN_SAY_2'),
(0,-1000616,'Blathering idiot. You incomprehensibly incompetent buffoon...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'LORD_ILLIDAN_SAY_3'),
(0,-1000617,'THIS is your hero?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,6,'LORD_ILLIDAN_SAY_4'),
(0,-1000618,'You have been deceived, imbecile.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'LORD_ILLIDAN_SAY_5'),
(0,-1000619,'This... whole... operation... HAS BEEN COMPROMISED!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,22,'LORD_ILLIDAN_SAY_6'),
(0,-1000620,'I expect to see this insect''s carcass in pieces in my lair within the hour. Fail and you will suffer a fate so much worse than death.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'LORD_ILLIDAN_SAY_7'),
(0,-1000621,'You will not harm the boy, Mor''ghor! Quickly, $N, climb on my back!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,22,'YARZILL_THE_MERC_SAY');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000636 AND -1000629;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1000629,'What''s the big idea, Spark?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'geezle - GEEZLE_SAY_1'),
(0,-1000630,'What''s the big idea? You nearly blew my cover, idiot! I told you to put the compass and navigation maps somewhere safe - not out in the open for any fool to discover.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,4,'geezle - SPARK_SAY_2'),
(0,-1000631,'The Master has gone to great lengths to secure information about the whereabouts of the Exodar. You could have blown the entire operation, including the cover of our spy on the inside.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'geezle - SPARK_SAY_3'),
(0,-1000632,'Relax, Spark! I have it all under control. We''ll strip mine the Exodar right out from under ''em - making both you and I very, very rich in the process.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,4,'geezle - GEEZLE_SAY_4'),
(0,-1000633,'Relax? Do you know what Kael''thas does to those that fail him, Geezle? Eternal suffering and pain... Do NOT screw this up, fool.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'geezle - SPARK_SAY_5'),
(0,-1000634,'Our Bloodmyst scouts have located our contact. The fool, Velen, will soon leave himself open and defenseless -- long enough for us to strike! Now get out of my sight before I vaporize you...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'geezle - SPARK_SAY_6'),
(0,-1000635,'Yes, sir. It won''t happen again...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'geezle - GEEZLE_SAY_7'),
(0,-1000636,'picks up the naga flag.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,2,0,0,'geezle - EMOTE_SPARK');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800070 AND -1800064;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1800064,'Beware! We are attacked!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_0'),
(0,-1800065,'It must be the purity of the Mark of the Lightbringer that is drawing forth the Scourge to attack us. We must proceed with caution lest we be overwhelmed!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_1'),
(0,-1800066,'This land truly needs to be cleansed by the Light! Let us continue on to the tomb. It isn''t far now...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_2'),
(0,-1800067,'Be welcome, friends!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_3'),
(0,-1800068,'Thank you for coming here in remembrance of me. Your efforts in recovering that symbol, while unnecessary, are certainly touching to an old man''s heart. ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_4'),
(0,-1800069,'Please, rise my friend. Keep the Blessing as a symbol of the strength of the Light and how heroes long gone might once again rise in each of us to inspire. ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_5'),
(0,-1800070,'Thank you my friend for making this possible. This is a day that I shall never forget! I think I will stay a while. Please return to High Priestess MacDonnell at the camp. I know that she''ll be keenly interested to know of what has transpired here.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_anchorite_truuen - SAY_WP_6');

DELETE FROM `script_texts` WHERE `entry`=-1000600;
INSERT INTO `script_texts`(`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(0,-1000600,'Ow! OK, I''ll get back to work, $N!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,11,1,'npc_lazy_peon - SAY_WP_0');

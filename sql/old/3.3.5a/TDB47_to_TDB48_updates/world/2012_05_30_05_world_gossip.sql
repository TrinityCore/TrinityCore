-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8388 WHERE `entry`=21118; -- Razak Ironsides
UPDATE `creature_template` SET `gossip_menu_id`=8306 WHERE `entry`=21494; -- Smiles O'Byron
UPDATE `creature_template` SET `gossip_menu_id`=8385 WHERE `entry`=21824; -- Dizzy Dina
UPDATE `creature_template` SET `gossip_menu_id`=8303 WHERE `entry`=21460; -- Tally Zapnabber
UPDATE `creature_template` SET `gossip_menu_id`=8304 WHERE `entry`=21461; -- Rally Zapnabber
UPDATE `creature_template` SET `gossip_menu_id`=8351 WHERE `entry`=21690; -- R-3D0
UPDATE `creature_template` SET `gossip_menu_id`=8370 WHERE `entry`=21755; -- Nickwinkle the Metro-Gnome
UPDATE `creature_template` SET `gossip_menu_id`=8429 WHERE `entry`=21981; -- Overseer Nuaar
UPDATE `creature_template` SET `gossip_menu_id`=8432 WHERE `entry`=21983; -- Samia Inkling
UPDATE `creature_template` SET `gossip_menu_id`=8431 WHERE `entry`=22007; -- Tree Warden Chawn
UPDATE `creature_template` SET `gossip_menu_id`=8436 WHERE `entry`=22019; -- Kolphis Darkscale
UPDATE `creature_template` SET `gossip_menu_id`=8447 WHERE `entry`=22020; -- O'Mally Zapnabber
UPDATE `creature_template` SET `gossip_menu_id`=8508 WHERE `entry`=22053; -- Mosswood the Ancient
UPDATE `creature_template` SET `gossip_menu_id`=8490 WHERE `entry`=22099; -- Wyrmcult Provisioner
UPDATE `creature_template` SET `gossip_menu_id`=8491 WHERE `entry`=22103; -- Baron Sablemane
UPDATE `creature_template` SET `gossip_menu_id`=8523 WHERE `entry`=22127; -- Wildlord Antelarion
UPDATE `creature_template` SET `gossip_menu_id`=8496 WHERE `entry`=22149; -- Commander Haephus Stonewall
UPDATE `creature_template` SET `gossip_menu_id`=8506 WHERE `entry`=22215; -- Treebole
UPDATE `creature_template` SET `gossip_menu_id`=8723 WHERE `entry`=22264; -- Ogri'la Steelshaper
UPDATE `creature_template` SET `gossip_menu_id`=8717, `npcflag`=`npcflag`|1 WHERE `entry`=22266; -- Food Vendor
UPDATE `creature_template` SET `gossip_menu_id`=8716, `npcflag`=`npcflag`|1 WHERE `entry`=22270; -- Ogri'la Merchant
UPDATE `creature_template` SET `gossip_menu_id`=8722, `npcflag`=`npcflag`|1 WHERE `entry`=22271; -- Ogri'la Trader
UPDATE `creature_template` SET `gossip_menu_id`=8529 WHERE `entry`=22386; -- Watcher Moonshade
UPDATE `creature_template` SET `gossip_menu_id`=8615 WHERE `entry`=22924; -- Arthorn Windsong
UPDATE `creature_template` SET `gossip_menu_id`=8620 WHERE `entry`=22941; -- Mog'dorg the Wizened
UPDATE `creature_template` SET `gossip_menu_id`=8657 WHERE `entry`=22995; -- Chort
UPDATE `creature_template` SET `gossip_menu_id`=8753 WHERE `entry`=23038; -- Sky Commander Adaris
UPDATE `creature_template` SET `gossip_menu_id`=8630 WHERE `entry`=23048; -- Sky Sergeant Doryn
UPDATE `creature_template` SET `gossip_menu_id`=8640, `npcflag`=`npcflag`|1 WHERE `entry`=23052; -- Bloodmaul Supplicant
UPDATE `creature_template` SET `gossip_menu_id`=8640, `npcflag`=`npcflag`|1 WHERE `entry`=23053; -- Bladespire Supplicant
UPDATE `creature_template` SET `gossip_menu_id`=8721, `npcflag`=`npcflag`|1 WHERE `entry`=23110; -- Ogri'la Keg King
UPDATE `creature_template` SET `gossip_menu_id`=8724 WHERE `entry`=23112; -- Mingo
UPDATE `creature_template` SET `gossip_menu_id`=8642, `npcflag`=`npcflag`|1 WHERE `entry`=23120; -- Sky Sergeant Vanderlip
UPDATE `creature_template` SET `gossip_menu_id`=8737 WHERE `entry`=23208; -- Skyguard Pyrotechnician
UPDATE `creature_template` SET `gossip_menu_id`=8679 WHERE `entry`=23253; -- Kronk
UPDATE `creature_template` SET `gossip_menu_id`=8667 WHERE `entry`=23306; -- Hazzik
UPDATE `creature_template` SET `gossip_menu_id`=8670 WHERE `entry`=23335; -- Skyguard Khatie
UPDATE `creature_template` SET `gossip_menu_id`=8683 WHERE `entry`=23363; -- Sahaak
UPDATE `creature_template` SET `gossip_menu_id`=8718 WHERE `entry`=23413; -- Skyguard Handler Irena
UPDATE `creature_template` SET `gossip_menu_id`=8719 WHERE `entry`=23415; -- Skyguard Handler Deesak
UPDATE `creature_template` SET `gossip_menu_id`=8726 WHERE `entry`=23428; -- Jho'nass
UPDATE `creature_template` SET `gossip_menu_id`=8736 WHERE `entry`=23473; -- Aether-tech Apprentice

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8303 AND `text_id` IN (10359,10569);
DELETE FROM `gossip_menu` WHERE `entry`=8304 AND `text_id` IN (10360,10537);
DELETE FROM `gossip_menu` WHERE `entry`=8306 AND `text_id`=10410;
DELETE FROM `gossip_menu` WHERE `entry`=8343 AND `text_id`=10363;
DELETE FROM `gossip_menu` WHERE `entry`=8351 AND `text_id`=10422;
DELETE FROM `gossip_menu` WHERE `entry`=8370 AND `text_id`=10444;
DELETE FROM `gossip_menu` WHERE `entry`=8385 AND `text_id`=10466;
DELETE FROM `gossip_menu` WHERE `entry`=8388 AND `text_id`=10469;
DELETE FROM `gossip_menu` WHERE `entry`=8429 AND `text_id`=10532;
DELETE FROM `gossip_menu` WHERE `entry`=8430 AND `text_id`=10533;
DELETE FROM `gossip_menu` WHERE `entry`=8431 AND `text_id`=10534;
DELETE FROM `gossip_menu` WHERE `entry`=8432 AND `text_id`=10538;
DELETE FROM `gossip_menu` WHERE `entry`=8435 AND `text_id`=10541;
DELETE FROM `gossip_menu` WHERE `entry`=8436 AND `text_id`=10539;
DELETE FROM `gossip_menu` WHERE `entry`=8437 AND `text_id`=10542;
DELETE FROM `gossip_menu` WHERE `entry`=8438 AND `text_id`=10543;
DELETE FROM `gossip_menu` WHERE `entry`=8439 AND `text_id`=10544;
DELETE FROM `gossip_menu` WHERE `entry`=8440 AND `text_id`=10545;
DELETE FROM `gossip_menu` WHERE `entry`=8447 AND `text_id`=10554;
DELETE FROM `gossip_menu` WHERE `entry`=8454 AND `text_id`=10561;
DELETE FROM `gossip_menu` WHERE `entry`=8455 AND `text_id`=10562;
DELETE FROM `gossip_menu` WHERE `entry`=8490 AND `text_id`=10602;
DELETE FROM `gossip_menu` WHERE `entry`=8491 AND `text_id`=10603;
DELETE FROM `gossip_menu` WHERE `entry`=8496 AND `text_id`=10612;
DELETE FROM `gossip_menu` WHERE `entry`=8506 AND `text_id`=10637;
DELETE FROM `gossip_menu` WHERE `entry`=8508 AND `text_id`=10640;
DELETE FROM `gossip_menu` WHERE `entry`=8523 AND `text_id`=10657;
DELETE FROM `gossip_menu` WHERE `entry`=8529 AND `text_id`=10667;
DELETE FROM `gossip_menu` WHERE `entry`=8615 AND `text_id`=10793;
DELETE FROM `gossip_menu` WHERE `entry`=8620 AND `text_id` IN (10800,10860);
DELETE FROM `gossip_menu` WHERE `entry`=8630 AND `text_id`=10819;
DELETE FROM `gossip_menu` WHERE `entry`=8640 AND `text_id`=10838;
DELETE FROM `gossip_menu` WHERE `entry`=8642 AND `text_id` IN (10841,10992,10994,10995);
DELETE FROM `gossip_menu` WHERE `entry`=8657 AND `text_id` IN (10877,10878);
DELETE FROM `gossip_menu` WHERE `entry`=8660 AND `text_id` IN (10888,11057);
DELETE FROM `gossip_menu` WHERE `entry`=8667 AND `text_id`=10903;
DELETE FROM `gossip_menu` WHERE `entry`=8669 AND `text_id` IN (10906,10938,10988,10989,10990,10991);
DELETE FROM `gossip_menu` WHERE `entry`=8670 AND `text_id` IN (10907,10997,11001,11002,11004);
DELETE FROM `gossip_menu` WHERE `entry`=8671 AND `text_id` IN (10909,10951);
DELETE FROM `gossip_menu` WHERE `entry`=8672 AND `text_id` IN (10910,10922);
DELETE FROM `gossip_menu` WHERE `entry`=8674 AND `text_id`=10912;
DELETE FROM `gossip_menu` WHERE `entry`=8675 AND `text_id`=10915;
DELETE FROM `gossip_menu` WHERE `entry`=8678 AND `text_id` IN (10916,10917,10918,11013,11015,11018);
DELETE FROM `gossip_menu` WHERE `entry`=8679 AND `text_id` IN (10919,10920,11027,11028);
DELETE FROM `gossip_menu` WHERE `entry`=8680 AND `text_id` IN (10923,10924,10925,11019,11020,11021);
DELETE FROM `gossip_menu` WHERE `entry`=8681 AND `text_id` IN (10926,10927,11007,11009,11010,11011);
DELETE FROM `gossip_menu` WHERE `entry`=8683 AND `text_id`=10953;
DELETE FROM `gossip_menu` WHERE `entry`=8685 AND `text_id` IN (10931,10932);
DELETE FROM `gossip_menu` WHERE `entry`=8687 AND `text_id`=11058;
DELETE FROM `gossip_menu` WHERE `entry`=8689 AND `text_id` IN (10931,10932);
DELETE FROM `gossip_menu` WHERE `entry`=8690 AND `text_id` IN (10931,10932);
DELETE FROM `gossip_menu` WHERE `entry`=8691 AND `text_id` IN (10931,10932);
DELETE FROM `gossip_menu` WHERE `entry`=8716 AND `text_id` IN (10965,10966,10967,10968,10969);
DELETE FROM `gossip_menu` WHERE `entry`=8717 AND `text_id` IN (10972,10973,10974,10975,10976);
DELETE FROM `gossip_menu` WHERE `entry`=8718 AND `text_id` IN (10977,10978);
DELETE FROM `gossip_menu` WHERE `entry`=8719 AND `text_id` IN (10979,10980);
DELETE FROM `gossip_menu` WHERE `entry`=8721 AND `text_id` IN (10983,10984,10985,10986,10987);
DELETE FROM `gossip_menu` WHERE `entry`=8722 AND `text_id` IN (10993,10996,10998,10999,11000);
DELETE FROM `gossip_menu` WHERE `entry`=8723 AND `text_id` IN (11008,11012,11014,11016,11017);
DELETE FROM `gossip_menu` WHERE `entry`=8724 AND `text_id` IN (11022,11023,11024,11025,11026);
DELETE FROM `gossip_menu` WHERE `entry`=8726 AND `text_id` IN (11029,11036,11037,11038);
DELETE FROM `gossip_menu` WHERE `entry`=8736 AND `text_id`=11066;
DELETE FROM `gossip_menu` WHERE `entry`=8737 AND `text_id` IN (11059,11060,11061,11063);
DELETE FROM `gossip_menu` WHERE `entry`=8753 AND `text_id`=11089;
DELETE FROM `gossip_menu` WHERE `entry`=8757 AND `text_id` IN (11094,11095);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(8303,10359),(8303,10569),
(8304,10537),(8304,10360),
(8306,10410),
(8343,10363),
(8351,10422),
(8370,10444),
(8385,10466),
(8388,10469),
(8429,10532),
(8430,10533),
(8431,10534),
(8435,10541),
(8436,10539),
(8437,10542),
(8438,10543),
(8439,10544),
(8440,10545),
(8447,10554),
(8454,10561),
(8455,10562),
(8490,10602),
(8491,10603),
(8496,10612),
(8506,10637),
(8508,10640),
(8523,10657),
(8529,10667),
(8615,10793),
(8620,10800),(8620,10860),
(8630,10819),
(8640,10838),
(8642,10841),(8642,10992),(8642,10994),(8642,10995),
(8657,10877),(8657,10878),
(8660,10888),(8660,11057),
(8667,10903),
(8669,10906),(8669,10938),(8669,10988),(8669,10989),(8669,10990),(8669,10991),
(8670,10907),(8670,10997),(8670,11001),(8670,11002),(8670,11004),
(8671,10909),(8671,10951),
(8672,10910),(8672,10922),
(8674,10912),
(8675,10915),
(8678,10916),(8678,10917),(8678,10918),(8678,11013),(8678,11015),(8678,11018),
(8679,10919),(8679,10920),(8679,11027),(8679,11028),
(8680,10923),(8680,10924),(8680,10925),(8680,11019),(8680,11020),(8680,11021),
(8681,10926),(8681,10927),(8681,11007),(8681,11009),(8681,11010),(8681,11011),
(8683,10953),
(8685,10931),(8685,10932),
(8687,11058),
(8689,10931),(8689,10932),
(8690,10931),(8690,10932),
(8691,10931),(8691,10932),
(8716,10965),(8716,10966),(8716,10967),(8716,10968),(8716,10969),
(8717,10976),(8717,10975),(8717,10974),(8717,10973),(8717,10972),
(8718,10977),(8718,10978),
(8719,10979),(8719,10980),
(8721,10983),(8721,10984),(8721,10985),(8721,10986),(8721,10987),
(8722,10993),(8722,10996),(8722,10998),(8722,10999),(8722,11000),
(8723,11008),(8723,11012),(8723,11014),(8723,11016),(8723,11017),
(8724,11022),(8724,11023),(8724,11024),(8724,11025),(8724,11026),
(8726,11029),(8726,11036),(8726,11037),(8726,11038),
(8736,11066),
(8737,11059),(8737,11060),(8737,11061),(8737,11063),
(8753,11089),
(8757,11094),(8757,11095);

-- Creature Gossip_menu_option insert from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8303,8429,8435,8436,8437,8438,8439,8454,8490,8660,8661,8671,8672,8673,8674,8675,8676,8677,8679,8683,8685,8687,8689,8690,8691,8716,8717,8718,8719,8721,8722,8723,8724,8726,8737) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8672,8677,8718,8719) AND `id` IN (1);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8304 AND `id` IN (0,1,2,3,4,5);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8306 AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8455 AND `id` IN (0,1,2,3,4);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8660 AND `id` IN (0,1,2,3);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8679 AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(8303,0,0,'I need another waiver!',1,1,0,0,0,0,''), -- Spellcast 38255
(8304,0,0,'I''m ready for my test flight!',1,1,0,0,0,0,''),
(8304,1,0,'Take me to Singing Ridge.',1,1,8454,0,0,0,''),
(8304,2,0,'Send me to Razaan''s Landing!',1,1,0,0,0,0,''),
(8304,3,0,'Take me to Ruuan.',1,1,0,0,0,0,''),
(8304,4,0,'Send me to Raven''s Wood!',1,1,0,0,0,0,''),
(8304,5,0,'I want to fly to an old location!',1,1,8455,0,0,0,''),
(8306,1,0,'Why are you so far from Toshley''s Station?',1,1,8343,0,0,0,''),
(8429,0,0,'Overseer, I am here to negotiate on behalf of the Cenarion Expedition.',1,1,8430,0,0,0,''),
(8435,0,0,'Oh, it''s not my fault, I can assure you.',1,1,8437,0,0,0,''),
(8436,0,0,'I''m fine, thank you.  You asked for me?',1,1,8435,0,0,0,''),
(8437,0,0,'Um, no... no, I don''t want that at all.',1,1,8438,0,0,0,''),
(8438,0,0,'Impressive.  When do we attack?',1,1,8439,0,0,0,''),
(8439,0,0,'Absolutely!',1,1,8440,0,0,0,''),
(8454,0,0,'I have the signed waiver!  Fire me into the Singing Ridge!',1,1,0,0,0,0,''),
(8455,0,0,'Send me back to the Jagged Ridge.',1,1,0,0,0,0,''),
(8455,1,0,'Send me back to the Singing Ridge.',1,1,0,0,0,0,''),
(8455,2,0,'Send me back to Razaan''s Landing.',1,1,0,0,0,0,''),
(8455,3,0,'Send me back to Ruuan.',1,1,0,0,0,0,''),
(8455,4,0,'Send me back to Raven''s Wood.',1,1,0,0,0,0,''),
(8490,0,1,'Very well, let me see what you''ve got.',3,128,0,0,0,0,''),
(8660,0,0,'<Call forth Gezzarak the Huntress.>',1,1,0,0,0,0,''),
(8660,1,0,'<Call forth Darkscreecher Akkarai.>',1,1,0,0,0,0,''),
(8660,2,0,'<Call forth Karrog.>',1,1,0,0,0,0,''),
(8660,3,0,'<Call forth Vakkiz the Windrager.>',1,1,0,0,0,0,''),
(8661,0,1,'Show me your assortment of, err... things.',3,128,0,0,0,0,''),
(8671,0,0,'Place 35 Apexis Shards into the prism.',1,1,0,0,0,0,''),
(8672,0,0,'Purchase 1 Unstable Flask of the Beast for the cost of 10 Apexis Shards',1,1,8673,0,0,0,''),
(8672,1,0,'Purchase 5 Unstable Flasks of the Beast for the cost of 50 Apexis Shards',1,1,8674,0,0,0,''),
(8673,0,0,'Use the fel crystalforge to make another purchase.',1,1,8672,0,0,0,''),
(8674,0,0,'Use the fel crystalforge to make another purchase.',1,1,8672,0,0,0,''),
(8675,0,0,'Use the Bash''ir crystalforge to make another purchase.',1,1,8677,0,0,0,''),
(8676,0,0,'Use the Bash''ir crystalforge to make another purchase.',1,1,8677,0,0,0,''),
(8677,0,0,'Purchase 1 Unstable Flask of the Sorcerer for the cost of 10 Apexis Shards',1,1,8676,0,0,0,''),
(8677,1,0,'Purchase 5 Unstable Flasks of the Sorcerer for the cost of 50 Apexis Shards',1,1,8675,0,0,0,''),
(8679,0,0,'Kronk, tell me about the charged crystal foci.',1,1,8757,0,0,0,''),
(8683,0,1,'Skwak!',3,128,0,0,0,0,''),
(8685,0,0,'Place 35 Apexis Shards near the dragon egg to crack it open.',1,1,0,0,0,0,''),
(8687,0,0,'<Call forth Terokk.>',1,1,0,0,0,0,''),
(8689,0,0,'Place 35 Apexis Shards near the dragon egg to crack it open.',1,1,0,0,0,0,''),
(8690,0,0,'Place 35 Apexis Shards near the dragon egg to crack it open.',1,1,0,0,0,0,''),
(8691,0,0,'Place 35 Apexis Shards near the dragon egg to crack it open.',1,1,0,0,0,0,''),
(8716,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(8717,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(8718,1,0,'Yes, I''d love a ride to Blackwind Landing.',1,1,0,0,0,0,''),
(8719,1,0,'Absolutely!  Send me to the Skyguard Outpost.',1,1,0,0,0,0,''),
(8721,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(8722,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(8723,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(8724,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(8726,0,1,'Jho''nass, let me see what you have to offer.',3,128,0,0,0,0,''),
(8737,0,1,'Let me browse your goods.',3,128,0,0,0,0,'');

-- Insert npc_text from sniff
DELETE FROM `npc_text` WHERE `ID` IN (10838,10878,10909,10915,10918,10968,10977,10984,10985,10986,10987,10990,10991,10993,10996,10998,10999,11012,11013,11014,11015,11020,11022,11023,11024,11037,11063);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(10838,'Yes, $g king : queen;?','',0,1,0,1,0,0,0,0,'You kill gronn!  Now you fight things from sky?','',0,1,0,15,0,0,0,0,'Me life for $N!','',0,1,0,15,0,0,0,0,'Dis drink good!','',0,1,0,1,0,0,0,0,'If $G King : Queen; $N dance, me dance!','',0,1,0,1,0,0,0,0,'$G King : Queen; not angry with me?','',0,1,0,1,0,0,0,0,'Why you look at me like dat?  You not gonna kiss me, right!?','',0,1,0,1,0,0,0,0,'Now all Sons of Gruul dead!  Now new $g king : queen; lead all ogres to Ogri''la!','',0,1,0,15,0,0,0,0,12340),
(10878,'Da $g king : queen;!  Chort ready to serve.','',0,1,0,2,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10909,'Burning eyes within the prism fill your mind with a sense of dread...','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10915,'<As you place your apexis shards within the hollow of the Bash''ir crystalforge and pull the lever, the device literally disintegrates them.  A few moments later your flasks appear at your feet.>','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10918,'The boy''s too stupid still to say it -- not enough crystal exposure yet -- but, he''s thankful for what you did in getting him those flasks.$B$BNow, only nine more sons to go.  Gah!$B$B<Both of Torkus''s heads sigh.>$B$BWant to take one of them off of our hands?  We''ll sell him to you cheap.','',0,1,0,1,0,5,0,6,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10968,'Mighty one! How can we serve you?','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10977,'','Hey, comrade.  If you get yourself in good with the Skyguard, I can offer you a direct flight to our base, Blackwind Landing, in the Skethyl Mountains.$B$BDo you like my beautiful nether ray?  It is lovely.',0,1,0,1,0,6,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10984,'Everyone''s gotta drink. What can we get for you?','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10985,'Greetings $G brother:sister;, how can we help?','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10986,'Our drinks should quench even the mightiest of thirsts.','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10987,'Drink or be gone!','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10990,'Yer gettin'' ta be something of a revered figure ''round here, $g boy : girl;!  If''n I didn''t know better, I''d say ye were gunnin'' fer me job!!!$B$BAll the same, if ye keep up the way ye have been, ye''ll deserve it!','',0,1,0,5,0,396,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10991,'What can I say, $N?  Yer the finest o'' the Sha''tari Skyguard!$B$BJust don''t be lettin'' that go ta yer head.  I can still teach ya a thing or two, $g lad : lass;!$B$B<Sky Commander Keller grins at you and winks.>','',0,1,0,2,0,11,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10993,'How can we be of service, exalted one?','',0,1,1,16,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10996,'We are happy to provide you with supplies.','',0,1,1,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10998,'Honored $G brother:sister;, how can we help?','',0,1,1,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(10999,'Friend! It''s been too long.  What can we get for you?','',0,1,1,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11013,'It''s an honor to have a $r such as yourself aiding us ogres.  You''re keeping our hope of a better future alive.$B$BNow if we could just get rid of these headaches.  Are you sure you don''t want one of our sons?','',0,1,0,1,0,6,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11012,'There are few things you can trust in life. Steel, you can trust.','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11014,'What is steel compared to the hand that shapes it?','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11015,'It''s amazing how much you''ve helped us out.  We dare say that if it weren''t for you, we''d already have been overrun by the demons, or fried to a crisp by the Black Dragonflight!$B$BOn a side note, we did mention that we''d sell you one of our sons, cheap, right?  No, not interested?','',0,1,0,1,0,6,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11020,'Gahk like little, $r $N.  Yous kill da big demon; make all da little demons scared!$B$B<Gahk''s heads both grin at you.>','',0,1,0,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11022,'What can we get for you, our exalted $G brother:sister;?','',0,1,1,16,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11023,'How might we be of assistance?','',0,1,1,1,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11024,'Honored $G brother:sister;, how may we help?','',0,1,1,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11037,'You''re like something of a revered figure around here, $g man : kitten;.  Seems like everyone''s talking about you.  That''s cool.$B$BLet''s see if there''s something in stock that you''re interested in.  We have a lot of nice stuff.','',0,1,0,25,0,1,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(11063,'You can never be too prepared.','',0,1,1,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8303 AND `SourceEntry`=10569;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8304 AND `SourceEntry`=10537;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8620 AND `SourceEntry`=10860;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8642 AND `SourceEntry` IN (10992,10994,10995);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8657 AND `SourceEntry`=10878;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8660 AND `SourceEntry`=11057;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8669 AND `SourceEntry` IN (10938,10988,10989,10990,10991);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8670 AND `SourceEntry` IN (10997,11001,11002,11004);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8671 AND `SourceEntry`=10951;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8672 AND `SourceEntry`=10922;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8677 AND `SourceEntry`=10913;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8678 AND `SourceEntry` IN (10917,10918,11013,11015,11018);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8679 AND `SourceEntry` IN (10920,11027,11028);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8680 AND `SourceEntry` IN (10923,10924,10925,11019,11020,11021);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8681 AND `SourceEntry` IN (10926,10927,11007,11009,11010,11011);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (8685,8689,8690,8691) AND `SourceEntry`=10932;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8716 AND `SourceEntry` IN (10965,10966,10968,10969);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8717 AND `SourceEntry` IN (10972,10973,10974,10975,10976);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8718 AND `SourceEntry`=10978;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8719 AND `SourceEntry`=10979;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8721 AND `SourceEntry` IN (10983,10984,10985,10986,10987);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8722 AND `SourceEntry` IN (10993,10996,10998,10999,11000);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8723 AND `SourceEntry` IN (11008,11012,11014,11016,11017);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8724 AND `SourceEntry` IN (11022,11023,11024,11025,11026);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8726 AND `SourceEntry` IN (11036,11037,11038);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8737 AND `SourceEntry` IN (11060,11061,11063);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8757 AND `SourceEntry`=11095;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8304 AND `SourceEntry` IN (0,1,2,3,4,5);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8429 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8454 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8455 AND `SourceEntry` IN (0,1,2,3,4);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8660 AND `SourceEntry` IN (0,1,2,3);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8671 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8672 AND `SourceEntry` IN (0,1);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8677 AND `SourceEntry` IN (0,1);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8685 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8687 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8689 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8690 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8691 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8718 AND `SourceEntry`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8719 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,8303,10569,0,0,8,10557,0,0,0,0,'','Tally Zapnabber - Show different gossip if player has completed quest 10557'),
(14,8304,10537,0,0,1,37108,0,0,0,0,'','Rally Zapnabber - Show different gossip if player is affected by aura 37108'),
(14,8620,10860,0,0,8,11000,0,0,0,0,'','Mog''dorg the Wizened - Show different gossip if player has rewarded quest 11000'),
(14,8642,10992,0,0,5,1031,32,0,0,0,'','Sky Sergeant Vanderlip - Show different gossip if player is honored with Sha''tari Skyguards'),
(14,8642,10994,0,0,5,1031,64,0,0,0,'','Sky Sergeant Vanderlip - Show different gossip if player is revered with Sha''tari Skyguards'),
(14,8642,10995,0,0,5,1031,128,0,0,0,'','Sky Sergeant Vanderlip - Show different gossip if player is exalted with Sha''tari Skyguards'),
(14,8657,10878,0,0,8,11000,0,0,0,0,'','Chort - Show different gossip if player has rewarded quest 11000'),
(14,8660,11057,0,0,2,32620,1,0,0,0,'','Skull Pile - Show different gossip if player has item 32620'),
(14,8669,10938,0,0,8,11065,0,0,0,0,'','Sky Commander Keller - Show different gossip if player has rewarded quest 11065'),
(14,8669,10938,0,0,8,11010,0,0,0,0,'','Sky Commander Keller - Show different gossip if player has rewarded quest 11010'),
(14,8669,10988,0,0,8,11062,0,0,0,0,'','Sky Commander Keller - Show different gossip if player has rewarded quest 11062'),
(14,8669,10989,0,0,5,1031,32,0,0,0,'','Sky Commander Keller - Show different gossip if player is honored with Sha''tari Skyguards'),
(14,8669,10990,0,0,5,1031,64,0,0,0,'','Sky Commander Keller - Show different gossip if player is revered with Sha''tari Skyguards'),
(14,8669,10991,0,0,5,1031,128,0,0,0,'','Sky Commander Keller - Show different gossip if player is exalted with Sha''tari Skyguards'),
(14,8670,10997,0,0,8,11065,0,0,0,0,'','Skyguard Khatie - Show different gossip if player has rewarded quest 11065'),
(14,8670,11001,0,0,5,1031,32,0,0,0,'','Skyguard Khatie - Show different gossip if player is honored with Sha''tari Skyguards'),
(14,8670,11002,0,0,5,1031,64,0,0,0,'','Skyguard Khatie - Show different gossip if player is revered with Sha''tari Skyguards'),
(14,8670,11004,0,0,5,1031,128,0,0,0,'','Skyguard Khatie - Show different gossip if player is exalted with Sha''tari Skyguards'),
(14,8671,10951,0,0,2,32569,35,0,1,0,'','Fel Crystal Prism - Show different gossip if player does not have 35 of item 32569'),
(14,8672,10922,0,0,2,32569,10,0,1,0,'','Fel Crystalforge - Show different gossip if player has 10 of item 32569'),
(14,8677,10913,0,0,2,32569,10,0,0,0,'','Bash''ir Crystalforge - Show different gossip if player has 10 of item 32569'),
(14,8678,10917,0,0,8,11030,0,0,0,0,'','Torkus - Show different gossip if player has rewarded quest 11030'),
(14,8678,10918,0,0,8,11061,0,0,0,0,'','Torkus - Show different gossip if player has rewarded quest 11061'),
(14,8678,11013,0,0,5,1038,32,0,0,0,'','Torkus - Show different gossip if player is honored with Ogri''la'),
(14,8678,11015,0,0,5,1038,64,0,0,0,'','Torkus - Show different gossip if player is revered with Ogri''la'),
(14,8678,11018,0,0,5,1038,128,0,0,0,'','Torkus - Show different gossip if player is exalted with Ogri''la'),
(14,8679,10920,0,0,8,11026,0,0,0,0,'','Kronk - Show different gossip if player has rewarded quest 11026'),
(14,8679,11027,0,0,5,1038,64,0,0,0,'','Kronk - Show different gossip if player is revered with Ogri''la'),
(14,8679,11028,0,0,5,1038,128,0,0,0,'','Kronk - Show different gossip if player is exalted with Ogri''la'),
(14,8680,10923,0,0,5,1038,32+16+8,0,0,0,'','Gahk - Show different gossip if player is neutral, friendly or honored with Ogri''la'),
(14,8680,10924,0,0,8,11026,0,0,0,0,'','Gahk - Show different gossip if player has rewarded quest 11026'),
(14,8680,10925,0,0,8,11060,0,0,0,0,'','Gahk - Show different gossip if player has rewarded quest 11060'),
(14,8680,11019,0,0,5,1038,64,0,0,0,'','Gahk - Show different gossip if player is revered with Ogri''la'),
(14,8680,11020,0,0,8,11079,0,0,0,0,'','Gahk - Show different gossip if player has rewarded quest 11079'),
(14,8680,11021,0,0,5,1038,128,0,0,0,'','Gahk - Show different gossip if player is exalted with Ogri''la'),
(14,8681,10926,0,0,5,1038,16+8,0,0,0,'','Chu''a''lor - Show different gossip if player is neutral or friendly with Ogri''la'),
(14,8681,10927,0,0,8,11025,0,0,0,0,'','Chu''a''lor - Show different gossip if player has rewarded quest 11025'),
(14,8681,11007,0,0,8,11058,0,0,0,0,'','Chu''a''lor - Show different gossip if player has rewarded quest 11058'),
(14,8681,11009,0,0,5,1038,32,0,0,0,'','Chu''a''lor - Show different gossip if player is honored with Ogri''la'),
(14,8681,11010,0,0,5,1038,64,0,0,0,'','Chu''a''lor - Show different gossip if player is revered with Ogri''la'),
(14,8681,11011,0,0,5,1038,128,0,0,0,'','Chu''a''lor - Show different gossip if player is exalted with Ogri''la'),
(14,8685,10932,0,0,2,32569,35,0,1,0,'','Show different gossip if player has 35 of item 32569'),
(14,8689,10932,0,0,2,32569,35,0,1,0,'','Show different gossip if player has 35 of item 32569'),
(14,8690,10932,0,0,2,32569,35,0,1,0,'','Show different gossip if player has 35 of item 32569'),
(14,8691,10932,0,0,2,32569,35,0,1,0,'','Show different gossip if player has 35 of item 32569'),
(14,8716,10965,0,0,5,1038,16,0,0,0,'','Ogri''la Merchant - Show different gossip if player is friendly with Ogri''la'),
(14,8716,10966,0,0,5,1038,32,0,0,0,'','Ogri''la Merchant - Show different gossip if player is honored with Ogri''la'),
(14,8716,10968,0,0,5,1038,64,0,0,0,'','Ogri''la Merchant - Show different gossip if player is revered with Ogri''la'),
(14,8716,10969,0,0,5,1038,128,0,0,0,'','Ogri''la Merchant - Show different gossip if player is exalted with Ogri''la'),
(14,8717,10972,0,0,5,1038,128,0,0,0,'','Food Vendor - Show different gossip if player is exalted with Ogri''la'),
(14,8717,10973,0,0,5,1038,64,0,0,0,'','Food Vendor - Show different gossip if player is revered with Ogri''la'),
(14,8717,10974,0,0,5,1038,32,0,0,0,'','Food Vendor - Show different gossip if player is honored with Ogri''la'),
(14,8717,10975,0,0,5,1038,16,0,0,0,'','Food Vendor - Show different gossip if player is friendly with Ogri''la'),
(14,8717,10976,0,0,5,1038,8,0,0,0,'','Food Vendor - Show different gossip if player is neutral with Ogri''la'),
(14,8718,10978,0,0,5,1031,224,0,0,0,'','Skyguard Handler Irena - Show different gossip if player is honored, revered or exalted with Sha''tari Skyguards'),
(14,8719,10979,0,0,5,1031,224,0,0,0,'','Skyguard Handler Deesak - Show different gossip if player is honored, revered or exalted with Sha''tari Skyguards'),
(14,8721,10983,0,0,5,1038,128,0,0,0,'','Ogri''la Keg King - Show different gossip if player is exalted with Ogri''la'),
(14,8721,10984,0,0,5,1038,64,0,0,0,'','Ogri''la Keg King - Show different gossip if player is revered with Ogri''la'),
(14,8721,10985,0,0,5,1038,32,0,0,0,'','Ogri''la Keg King - Show different gossip if player is honored with Ogri''la'),
(14,8721,10986,0,0,5,1038,16,0,0,0,'','Ogri''la Keg King - Show different gossip if player is friendly with Ogri''la'),
(14,8721,10987,0,0,5,1038,8,0,0,0,'','Ogri''la Keg King - Show different gossip if player is neutral with Ogri''la'),
(14,8722,10993,0,0,5,1038,128,0,0,0,'','Ogri''la Trader - Show different gossip if player is exalted with Ogri''la'),
(14,8722,10996,0,0,5,1038,64,0,0,0,'','Ogri''la Trader - Show different gossip if player is revered with Ogri''la'),
(14,8722,10998,0,0,5,1038,32,0,0,0,'','Ogri''la Trader - Show different gossip if player is honored with Ogri''la'),
(14,8722,10999,0,0,5,1038,16,0,0,0,'','Ogri''la Trader - Show different gossip if player is friendly with Ogri''la'),
(14,8722,11000,0,0,5,1038,8,0,0,0,'','Ogri''la Trader - Show different gossip if player is neutral with Ogri''la'),
(14,8723,11008,0,0,5,1038,128,0,0,0,'','Ogri''la Steelshaper - Show different gossip if player is exalted with Ogri''la'),
(14,8723,11012,0,0,5,1038,64,0,0,0,'','Ogri''la Steelshaper - Show different gossip if player is revered with Ogri''la'),
(14,8723,11014,0,0,5,1038,32,0,0,0,'','Ogri''la Steelshaper - Show different gossip if player is honored with Ogri''la'),
(14,8723,11016,0,0,5,1038,16,0,0,0,'','Ogri''la Steelshaper - Show different gossip if player is friendly with Ogri''la'),
(14,8723,11017,0,0,5,1038,8,0,0,0,'','Ogri''la Steelshaper - Show different gossip if player is neutral with Ogri''la'),
(14,8724,11022,0,0,5,1038,128,0,0,0,'','Mingo - Show different gossip if player is exalted with Ogri''la'),
(14,8724,11023,0,0,5,1038,64,0,0,0,'','Mingo - Show different gossip if player is revered with Ogri''la'),
(14,8724,11024,0,0,5,1038,32,0,0,0,'','Mingo - Show different gossip if player is honored with Ogri''la'),
(14,8724,11025,0,0,5,1038,16,0,0,0,'','Mingo - Show different gossip if player is friendly with Ogri''la'),
(14,8724,11026,0,0,5,1038,8,0,0,0,'','Mingo - Show different gossip if player is neutral with Ogri''la'),
(14,8726,11036,0,0,5,1038,32,0,0,0,'','Jho''nass - Show different gossip if player is honored with Ogri''la'),
(14,8726,11037,0,0,5,1038,64,0,0,0,'','Jho''nass - Show different gossip if player is revered with Ogri''la'),
(14,8726,11038,0,0,5,1038,128,0,0,0,'','Jho''nass - Show different gossip if player is exalted with Ogri''la'),
(14,8737,11063,0,0,5,1031,32,0,0,0,'','Skyguard Pyrotechnician - Show different gossip if player is honored with Sha''tari Skyguards'),
(14,8737,11061,0,0,5,1031,64,0,0,0,'','Skyguard Pyrotechnician - Show different gossip if player is revered with Sha''tari Skyguards'),
(14,8737,11060,0,0,5,1031,128,0,0,0,'','Skyguard Pyrotechnician - Show different gossip if player is exalted with Sha''tari Skyguards'),
(14,8757,11095,0,0,5,1038,224,0,0,0,'','Kronk - Show different gossip if player is honored, revered or exalted with Ogri''la'),

(15,8304,0,0,0,9,10557,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has taken quest 10557'),
(15,8304,1,0,0,9,10710,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has taken quest 10710'),
(15,8304,2,0,0,9,10711,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has taken quest 10711'),
(15,8304,3,0,0,9,10712,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has taken quest 10712'),
(15,8304,4,0,0,9,10716,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has taken quest 10716'),
(15,8304,5,0,0,8,10557,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has taken quest 10557'),
(15,8429,0,0,0,9,10682,0,0,0,0,'','Overseer Nuaar - Show gossip option only if player has taken quest 10682'),
(15,8454,0,0,0,2,30539,1,0,0,0,'','Rally Zapnabber - Show gossip option only if player has item 30539'),
(15,8455,1,0,0,8,10710,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has completed quest 10710'),
(15,8455,2,0,0,8,10711,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has completed quest 10711'),
(15,8455,3,0,0,8,10712,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has completed quest 10712'),
(15,8455,4,0,0,8,10716,0,0,0,0,'','Rally Zapnabber - Show gossip option only if player has completed quest 10716'),
(15,8660,0,0,0,9,11885,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11885'),
(15,8660,1,0,0,9,11885,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11885'),
(15,8660,2,0,0,9,11885,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11885'),
(15,8660,3,0,0,9,11885,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11885'),
(15,8660,0,0,1,9,11074,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11074'),
(15,8660,1,0,1,9,11074,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11074'),
(15,8660,2,0,1,9,11074,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11074'),
(15,8660,3,0,1,9,11074,0,0,0,0,'','Skull Pile - Show gossip option only if player has taken quest 11074'),
(15,8671,0,0,0,2,32569,35,0,0,0,'','Fel Crystal Prism - Show gossip option only if player has 35 of item 32569'),
(15,8672,0,0,0,2,32569,10,0,0,0,'','Fel Crystalforge - Show gossip option only if player has 10 of item 32569'),
(15,8672,1,0,0,2,32569,50,0,0,0,'','Fel Crystalforge - Show gossip option only if player has 50 of item 32569'),
(15,8677,0,0,0,2,32569,10,0,0,0,'','Bash''ir Crystalforge - Show gossip option only if player has 10 of item 32569'),
(15,8677,1,0,0,2,32569,50,0,0,0,'','Bash''ir Crystalforge - Show gossip option only if player has 50 of item 32569'),
(15,8685,0,0,0,2,32569,35,0,0,0,'','Show gossip option only if player has 35 of item 32569'),
(15,8687,0,0,0,2,32720,1,0,0,0,'','Ancient Skull Pile - Show gossip option only if player has 1 of item 32720'),
(15,8689,0,0,0,2,32569,35,0,0,0,'','Show gossip option only if player has 35 of item 32569'),
(15,8690,0,0,0,2,32569,35,0,0,0,'','Show gossip option only if player has 35 of item 32569'),
(15,8691,0,0,0,2,32569,35,0,0,0,'','Show gossip option only if player has 35 of item 32569'),
(15,8718,1,0,0,5,1031,224,0,0,0,'','Skyguard Handler Irena - Show gossip option only if player is honored, revered or exalted with Sha''tari Skyguards'),
(15,8719,1,0,0,5,1031,224,0,0,0,'','Skyguard Handler Deesak - Show gossip option only if player is honored, revered or exalted with Sha''tari Skyguards');

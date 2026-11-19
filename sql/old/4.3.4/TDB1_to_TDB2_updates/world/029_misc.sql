DELETE FROM `gameobject_template` WHERE `entry` IN (195524, 195523, 205886);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(195524, 5, 8936, 'The Ultimate Bomb', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(195523, 5, 9191, 'The Goblin Lisa', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205886, 3, 10079, 'Watcher Head', '', 'Extricating', '', 93, 34758, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47578, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.6, 61975, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-


UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171544; -- Dwarven Brazier
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171569; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171570; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171571; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171572; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171573; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171574; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171575; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171576; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171577; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171578; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=171579; -- Wooden Chair
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=180861; -- Firework Rocket, Type 1 Blue BIG
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=180863; -- Firework Rocket, Type 1 Purple BIG
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=180865; -- Firework Rocket, Type 1 Yellow BIG
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=186465; -- Lighthouse Beam


DELETE FROM `npc_text` WHERE `ID` IN (15001, 14595, 14681, 14694, 17549, 16638);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(15001, 'Warrior-Matic NX-01 online.$B$BPlease insert coins for training.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 15001
(14595, 'What? $N, you''re not a warlock.$B$BThere''s nothing that I can teach a $c like you, $g sir : ma''am;.', '', 0, 1, 6, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 14595
(14681, '', 'Hi, babe! How do I look?', 0, 1, 4, 0, 0, 0, 0, 0, '', 'I missed you so much! Where have you been?$B$BAre you going to answer me, or just stand there?', 0, 1, 6, 0, 0, 0, 0, 0, '', 'Do you like my outfit?  It''s for the party. I charged it to your account.', 0, 1, 6, 0, 0, 0, 0, 0, '', 'There was another guy just hitting on me. Oh, the nerve!$B$BWill you beat him up for me, sweetie? Thanks. Love ya!', 0, 1, 5, 0, 0, 0, 0, 0, '', 'I can''t wait for the day when you rise to the top. Just think, I''ll be able to call myself Mrs. Trade Prince$B$BNot to mention buy all that stuff I''ve always wanted!!!', 0, 1, 1, 0, 0, 0, 0, 0, '', 'Be careful out there. I heard that there are Southsea pirates in the bay.$B$BHmm, maybe I should go check for myself...', 0, 1, 1, 0, 0, 0, 0, 0, '', 'Can we go on a nice, romantic picnic on top of Mount Kajaro?$B$BMake sure you pickup my favorite champagne!', 0, 1, 6, 0, 0, 0, 0, 0, '', 'You''ve got a miscievious look in your eye. What have you been up to, babe?$B$BWell?', 0, 1, 6, 0, 0, 0, 0, 0, 15595), -- 14681
(14694, 'Beat it, pal, before I give you the ol'' Chip Endale fist to the face!', '', 0, 1, 5, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 14694
(17549, '', 'Yeah? Whadya want?', 0, 1, 6, 0, 0, 0, 0, 0, '', 'I don''t talk to no $g scrub : trash;!', 0, 1, 274, 0, 0, 0, 0, 0, '', 'You''re not quite in my league, honey.', 0, 1, 25, 0, 0, 0, 0, 0, '', 'I didn''t talk to you back in school and I''m sure not going to start now.', 0, 1, 1, 0, 0, 0, 0, 0, '', 'That''s an interesting... \"outfit\" you''re wearing.', 0, 1, 11, 0, 0, 0, 0, 0, '', 'Yes. I''d love a refill. Fetch one and be quick about it.', 0, 1, 1, 0, 0, 0, 0, 0, '', 'This is the Trade Prince''s party, sweetie. Invite only!', 0, 1, 396, 0, 0, 0, 0, 0, '', '$N, right? Word of advice: don''t let the Trade Prince catch you around here. He knows you''re after his job.$B$BEveryone knows.', 0, 1, 6, 0, 0, 0, 0, 0, 15595), -- 17549
(16638, 'Twilight''s Hammer has infiltrated my city. Left unchecked, they''ll rot it to the core. Before we besiege their stronghold in the Highlands, I must be certain that Stormwind is safe from their machinations.$B$BI need more feet on the ground, reliable eyes and ears throughout the city. An experienced $c like yourself would be invaluable.$B$BAre you prepared to help Stormwind''s cause?', '', 0, 1, 6, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 16638



UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=2234; -- 2234
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=14791; -- 14791




DELETE FROM `gossip_menu_option` WHERE (`menu_id`=10043 AND `id`=0) OR (`menu_id`=10043 AND `id`=1) OR (`menu_id`=10043 AND `id`=2) OR (`menu_id`=10043 AND `id`=3) OR (`menu_id`=10043 AND `id`=4) OR (`menu_id`=10043 AND `id`=5) OR (`menu_id`=10043 AND `id`=6) OR (`menu_id`=10043 AND `id`=7) OR (`menu_id`=10043 AND `id`=8) OR (`menu_id`=10043 AND `id`=9) OR (`menu_id`=10043 AND `id`=10) OR (`menu_id`=10043 AND `id`=11) OR (`menu_id`=10043 AND `id`=12) OR (`menu_id`=10043 AND `id`=13) OR (`menu_id`=10057 AND `id`=0) OR (`menu_id`=10057 AND `id`=1) OR (`menu_id`=10057 AND `id`=2) OR (`menu_id`=10089 AND `id`=0) OR (`menu_id`=10089 AND `id`=1) OR (`menu_id`=10089 AND `id`=2) OR (`menu_id`=10058 AND `id`=0) OR (`menu_id`=10058 AND `id`=1) OR (`menu_id`=10084 AND `id`=0) OR (`menu_id`=10084 AND `id`=1) OR (`menu_id`=10084 AND `id`=2) OR (`menu_id`=10090 AND `id`=0) OR (`menu_id`=10090 AND `id`=1) OR (`menu_id`=10090 AND `id`=2) OR (`menu_id`=10056 AND `id`=0) OR (`menu_id`=10056 AND `id`=1) OR (`menu_id`=10056 AND `id`=2) OR (`menu_id`=10056 AND `id`=3) OR (`menu_id`=10056 AND `id`=4) OR (`menu_id`=10056 AND `id`=5) OR (`menu_id`=10056 AND `id`=6) OR (`menu_id`=10056 AND `id`=7) OR (`menu_id`=10056 AND `id`=8) OR (`menu_id`=10056 AND `id`=9) OR (`menu_id`=10056 AND `id`=10) OR (`menu_id`=10056 AND `id`=11) OR (`menu_id`=10082 AND `id`=3) OR (`menu_id`=10082 AND `id`=4) OR (`menu_id`=10173 AND `id`=0) OR (`menu_id`=10173 AND `id`=1) OR (`menu_id`=10173 AND `id`=2) OR (`menu_id`=10173 AND `id`=3) OR (`menu_id`=10173 AND `id`=4) OR (`menu_id`=10173 AND `id`=5) OR (`menu_id`=10173 AND `id`=6) OR (`menu_id`=10173 AND `id`=7) OR (`menu_id`=10173 AND `id`=8) OR (`menu_id`=10173 AND `id`=9) OR (`menu_id`=10173 AND `id`=10) OR (`menu_id`=10173 AND `id`=11) OR (`menu_id`=10173 AND `id`=12) OR (`menu_id`=10173 AND `id`=13) OR (`menu_id`=10173 AND `id`=14) OR (`menu_id`=10821 AND `id`=0) OR (`menu_id`=12516 AND `id`=0) OR (`menu_id`=12516 AND `id`=1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(10043, 0, 0, 'Arena', 0, 0, ''), -- Whirt the All-Knowing
(10043, 1, 0, 'Auction House', 0, 0, ''), -- Whirt the All-Knowing
(10043, 2, 0, 'Bank', 0, 0, ''), -- Whirt the All-Knowing
(10043, 3, 0, 'Barber', 0, 0, ''), -- Whirt the All-Knowing
(10043, 4, 0, 'Battlemasters', 0, 0, ''), -- Whirt the All-Knowing
(10043, 5, 0, 'Flight Master', 0, 0, ''), -- Whirt the All-Knowing
(10043, 6, 0, 'Guild Master & Vendor', 0, 0, ''), -- Whirt the All-Knowing
(10043, 7, 0, 'Inn', 0, 0, ''), -- Whirt the All-Knowing
(10043, 8, 0, 'Locksmith', 0, 0, ''), -- Whirt the All-Knowing
(10043, 9, 0, 'Mailbox', 0, 0, ''), -- Whirt the All-Knowing
(10043, 10, 0, 'Points of Interest', 0, 0, ''), -- Whirt the All-Knowing
(10043, 11, 0, 'Stable Master', 0, 0, ''), -- Whirt the All-Knowing
(10043, 12, 0, 'Trainers', 0, 0, ''), -- Whirt the All-Knowing
(10043, 13, 0, 'Vendors', 0, 0, ''), -- Whirt the All-Knowing
(10057, 0, 0, 'Eastern Sewer Entrance', 0, 0, ''), -- Whirt the All-Knowing
(10057, 1, 0, 'Western Sewer Entrance', 0, 0, ''), -- Whirt the All-Knowing
(10057, 2, 0, 'Well Entrance', 0, 0, ''), -- Whirt the All-Knowing
(10089, 0, 0, 'Northern Bank', 0, 0, ''), -- Whirt the All-Knowing
(10089, 1, 0, 'Southern Bank', 0, 0, ''), -- Whirt the All-Knowing
(10089, 2, 0, 'Sewers', 0, 0, ''), -- Whirt the All-Knowing
(10058, 0, 0, 'The Alliance Quarter', 0, 0, ''), -- Mona Everspring
(10058, 1, 0, 'The Horde Quarter', 0, 0, ''), -- Mona Everspring
(10084, 0, 0, 'Alliance Inn', 0, 0, ''), -- Mona Everspring
(10084, 1, 0, 'Horde Inn', 0, 0, ''), -- Mona Everspring
(10084, 2, 0, 'Sewers', 0, 0, ''), -- Mona Everspring
(10090, 0, 0, 'Inn', 0, 0, ''), -- Mona Everspring
(10090, 1, 0, 'Bank', 0, 0, ''), -- Mona Everspring
(10090, 2, 0, 'Krasus'' Landing', 0, 0, ''), -- Mona Everspring
(10056, 0, 0, 'The Alliance Quarter', 0, 0, ''), -- Whirt the All-Knowing
(10056, 1, 0, 'The Horde Quarter', 0, 0, ''), -- Whirt the All-Knowing
(10056, 2, 0, 'The Violet Citadel', 0, 0, ''), -- Whirt the All-Knowing
(10056, 3, 0, 'The Violet Hold', 0, 0, ''), -- Whirt the All-Knowing
(10056, 4, 0, 'Sewers', 0, 0, ''), -- Whirt the All-Knowing
(10056, 5, 0, 'Trade District', 0, 0, ''), -- Whirt the All-Knowing
(10056, 6, 0, 'Krasus'' Landing', 0, 0, ''), -- Whirt the All-Knowing
(10056, 7, 0, 'Antonidas Memorial', 0, 0, ''), -- Whirt the All-Knowing
(10056, 8, 0, 'Runeweaver Square', 0, 0, ''), -- Whirt the All-Knowing
(10056, 9, 0, 'The Eventide', 0, 0, ''), -- Whirt the All-Knowing
(10056, 10, 0, 'Cemetery', 0, 0, ''), -- Whirt the All-Knowing
(10056, 11, 0, 'Lexicon of Power', 0, 0, ''), -- Whirt the All-Knowing
(10082, 3, 0, 'Cold Weather Flying Trainer', 0, 0, ''), -- Whirt the All-Knowing
(10082, 4, 0, 'Portal Trainer', 0, 0, ''), -- Whirt the All-Knowing
(10173, 0, 0, 'Armor', 0, 0, ''), -- Whirt the All-Knowing
(10173, 1, 0, 'Clothing', 0, 0, ''), -- Whirt the All-Knowing
(10173, 2, 0, 'Emblem Gear', 0, 0, ''), -- Whirt the All-Knowing
(10173, 3, 0, 'Flowers', 0, 0, ''), -- Whirt the All-Knowing
(10173, 4, 0, 'Fruit', 0, 0, ''), -- Whirt the All-Knowing
(10173, 5, 0, 'General Goods', 0, 0, ''), -- Whirt the All-Knowing
(10173, 6, 0, 'Jewelry', 0, 0, ''), -- Whirt the All-Knowing
(10173, 7, 0, 'Pet Supplies & Exotic Mounts', 0, 0, ''), -- Whirt the All-Knowing
(10173, 8, 0, 'Pie, Pastry & Cakes', 0, 0, ''), -- Whirt the All-Knowing
(10173, 9, 0, 'Reagents & Magical Goods', 0, 0, ''), -- Whirt the All-Knowing
(10173, 10, 0, 'Toys', 0, 0, ''), -- Whirt the All-Knowing
(10173, 11, 0, 'Trade Supplies', 0, 0, ''), -- Whirt the All-Knowing
(10173, 12, 0, 'Trinkets, Relics & Off-hand Items', 0, 0, ''), -- Whirt the All-Knowing
(10173, 13, 0, 'Weapons', 0, 0, ''), -- Whirt the All-Knowing
(10173, 14, 0, 'Wine & Cheese', 0, 0, ''), -- Whirt the All-Knowing
(10821, 0, 3, 'I require warrior training.', 0, 0, ''), -- Warrior-Matic NX-01
(12516, 0, 3, 'I would like to train further in the ways of the Light.', 0, 0, ''), -- Sister Darnhald
(12516, 1, 0, 'I wish to unlearn my talents.', 0, 0, ''); -- Sister Darnhald

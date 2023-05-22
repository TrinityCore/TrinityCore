UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3008; -- Mak
UPDATE `creature_template` SET `gossip_menu_id`=1290 WHERE `entry`=6928; -- Innkeeper Grosk
UPDATE `creature_template` SET `gossip_menu_id`=12017, `minlevel`=35, `maxlevel`=35, `speed_walk`=1 WHERE `entry`=45407; -- Ibdil the Mender
UPDATE `creature_template` SET `gossip_menu_id`=15131 WHERE `entry`=14741; -- Huntsman Markhor
UPDATE `creature_template` SET `gossip_menu_id`=18677 WHERE `entry`=96362; -- Izzy Hollyfizzle
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=126330; -- Rakle the Wretched
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=140960; -- Yuwija
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=143555; -- Xander Silberman
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=154002; -- Atolia Seapearl

DELETE FROM `gossip_menu` WHERE `MenuID` IN (21447,22817,24257,24288,24386,24406,25235,25278,25592,25644,25680,25688,26065,26067,26177,26421,26571,26600,26642);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21447, 32653, 45745), -- 126330 (Rakle the Wretched)
(22817, 35328, 45745), -- 140960 (Yuwija)
(24257, 37995, 45745), -- 154002 (Atolia Seapearl)
(24288, 38084, 45745), -- 151633 (Karn Deepweld)
(24386, 38248, 45745), -- 143555 (Xander Silberman)
(24406, 38308, 45745), -- 155496 (Wrathion)
(25235, 39780, 45745), -- 159238 (Atticus)
(25278, 40584, 45745), -- 162804 (Ve'nari)
(25592, 40426, 45745), -- 167603 (Fixer Bixie)
(25644, 40480, 45745), -- 161678 (Mama Tomalin)
(25680, 40532, 45745), -- 168032 (Flwngyrr)
(25688, 40559, 45745), -- 168122 (Foreman Scug)
(26065, 39082, 45745), -- 160091 (Ta'ruca)
(26067, 39082, 45745), -- 171808 (Ta'tru)
(26177, 41539, 45745), -- 161298 (Nourman)
(26421, 41905, 45745), -- 166640 (Au'larrynar)
(26571, 42199, 45745), -- 174766 (Cortinarius)
(26600, 42332, 45745), -- 173705 (Archivist Janeera)
(26642, 42366, 45745); -- 158556 (Aithlyn)

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5721,7047,8047,11573,15131,15133,21447,22817,24257,24288,24386,24406,25235,25278,25592,25644,25680,25688,26065,26067,26177,26421,26571,26600,26642);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5721, 0, 1, 'Show me what hooch you\'ve got to sell, Kreeg.', 9372, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(5721, 1, 0, 'What do you mean, buy?!  I\'m the king now... and it\'s good to be the king!', 9373, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(7047, 0, 1, 'Let\'s see what you have.', 11820, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(8047, 0, 1, 'Please repair my items.', 17481, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(11573, 0, 1, 'Show me your goods, Denni\'ka.', 41855, 512, 0, 0, 0, 0, 0, NULL, 0, 45745),
(15131, 1, 1, 'I\'m looking for a lost companion.', 56613, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(15131, 2, 0, 'I\'d like to heal and revive my battle pets.', 64115, 1, 0, 0, 0, 0, 1000, 'A small fee for supplies is required.', 66369, 45745),
(15131, 3, 0, 'I\'d like to heal and revive my battle pets.', 64115, 1, 0, 15145, 0, 0, 0, NULL, 0, 45745),
(15133, 1, 1, 'I\'m looking for a lost companion.', 56613, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(15133, 2, 0, 'I\'d like to heal and revive my battle pets.', 64115, 1, 0, 0, 0, 0, 1000, 'A small fee for supplies is required.', 66369, 45745),
(15133, 3, 0, 'I\'d like to heal and revive my battle pets.', 64115, 1, 0, 15145, 0, 0, 0, NULL, 0, 45745),
(21447, 0, 5, 'May I rest here?', 41414, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(21447, 1, 1, 'Show me your wares.', 58437, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(22817, 0, 5, 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(22817, 1, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24257, 1, 1, 'I wish to browse your wares.', 4424, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24288, 1, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24386, 0, 1, 'I wish to browse your wares.', 4424, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24406, 0, 1, 'I would like to exchange my Coalescing Visions and Corrupted Mementos.', 186484, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(24406, 2, 0, 'What lies next for you, Wrathion?', 188093, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25235, 0, 0, 'I have a fashion accessory for you.', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25235, 1, 0, 'I need your assistance.', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25235, 2, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25278, 5, 1, 'What do you have to trade?', 0, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25278, 11, 0, 'Your cartel says they know what you did. Is there something you\'re not telling me?', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25278, 17, 0, '<Listen to Ve\'nari\'s message>', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25592, 0, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25644, 0, 5, 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25644, 1, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25644, 2, 0, 'I have a fashion accessory for you.', 0, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25680, 0, 1, 'I would like to buy from you.', 2583, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25680, 1, 5, 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(25688, 0, 1, 'Would you have anything to trade for Infused Rubies?', 0, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26065, 0, 1, 'What sort of delicacies do you have for sale?', 0, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26067, 0, 1, 'I am looking to make a trade.', 0, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26177, 0, 1, 'Would you have anything to trade for Infused Rubies?', 0, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26421, 0, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26571, 0, 1, 'Show me what you have available.', 108794, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26600, 0, 1, 'I wish to browse your wares.', 4424, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26642, 0, 1, 'How may I help you?', 30864, 128, 0, 0, 0, 0, 0, NULL, 0, 45745);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=4308 WHERE `MenuID`=1290 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822 WHERE `MenuID`=1290 AND `OptionID`=1;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=45745 WHERE `MenuID`=1290;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=45745 WHERE `MenuID`=12017;

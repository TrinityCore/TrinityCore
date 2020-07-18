--
DELETE FROM `item_loot_template` WHERE `Entry` IN (50301,54218);
INSERT INTO `item_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(50301,46779,0,36.36,0,1,1,50,50,'Landro\'s Pet Box, Path of Cenarius'),
(50301,35223,0,36.36,0,1,1,50,50,'Landro\'s Pet Box, Papa Hummel\'s Old-Fashioned Pet Biscuit'),
(50301,45047,0,27.28,0,1,1,50,50,'Landro\'s Pet Box, Sandbox Tiger'),
(50301,32588,0,0.45,0,1,2,1,1,'Landro\'s Pet Box, Banana Charm'),
(50301,38050,0,0.45,0,1,2,1,1,'Landro\'s Pet Box, Soul-Trader Beacon'),
(50301,34493,0,0.10,0,1,2,1,1,'Landro\'s Pet Box, Dragon Kite'),
(54218,46779,0,36.36,0,1,1,50,50,'Landro\'s Gift Box, Path of Cenarius'),
(54218,35223,0,36.36,0,1,1,50,50,'Landro\'s Gift Box, Papa Hummel\'s Old-Fashioned Pet Biscuit'),
(54218,45047,0,27.28,0,1,1,50,50,'Landro\'s Gift Box, Sandbox Tiger'),
(54218,23720,0,0.50,0,1,2,1,1,'Landro\'s Gift Box, Riding Turtle'),
(54218,49284,0,0.30,0,1,2,1,1,'Landro\'s Gift Box, Reins of the Swift Spectral Tiger'),
(54218,49283,0,0.30,0,1,2,1,1,'Landro\'s Gift Box, Reins of the Spectral Tiger'),
(54218,49286,0,0.30,0,1,2,1,1,'Landro\'s Gift Box, X-51 Nether-Rocket X-TREME'),
(54218,49285,0,0.10,0,1,2,1,1,'Landro\'s Gift Box, X-51 Nether-Rocket'),
(54218,49282,0,0.20,0,1,2,1,1,'Landro\'s Gift Box, Big Battle Bear');

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11672 AND `OptionIndex`=0) OR (`MenuId`=12990 AND `OptionIndex`=0) OR (`MenuId`=10685 AND `OptionIndex`=0) OR (`MenuId`=5542 AND `OptionIndex`=0) OR (`MenuId`=4356 AND `OptionIndex`=0) OR (`MenuId`=8851 AND `OptionIndex`=3) OR (`MenuId`=8851 AND `OptionIndex`=2) OR (`MenuId`=8851 AND `OptionIndex`=1) OR (`MenuId`=5709 AND `OptionIndex`=0) OR (`MenuId`=6917 AND `OptionIndex`=0) OR (`MenuId`=12812 AND `OptionIndex`=0) OR (`MenuId`=10520 AND `OptionIndex`=0) OR (`MenuId`=8062 AND `OptionIndex`=1) OR (`MenuId`=12009 AND `OptionIndex`=0) OR (`MenuId`=2741 AND `OptionIndex`=0) OR (`MenuId`=3501 AND `OptionIndex`=0) OR (`MenuId`=5181 AND `OptionIndex`=0) OR (`MenuId`=11878 AND `OptionIndex`=1) OR (`MenuId`=11878 AND `OptionIndex`=0) OR (`MenuId`=10639 AND `OptionIndex`=0) OR (`MenuId`=10703 AND `OptionIndex`=0) OR (`MenuId`=10680 AND `OptionIndex`=1) OR (`MenuId`=10691 AND `OptionIndex`=0) OR (`MenuId`=12669 AND `OptionIndex`=3) OR (`MenuId`=8950 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(11672, 0, 1, 'I would like to buy from you.', 2583, 15050), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(12990, 0, 0, 'You turned Fandral Staghelm over to the Twilight\'s Hammer. Why have you betrayed the dragonflights?', 52961, 15050),
(10685, 0, 3, 'I require priest training.', 11072, 15050),
(5542, 0, 1, 'Show me what\'s for sale.', 9037, 15050),
(4356, 0, 3, 'Train me.', 3266, 15050),
(8851, 3, 0, 'Profession Trainer', 2869, 15050), -- OptionBroadcastTextID: 2869 - 3430 - 4896 - 5112 - 5352 - 5916 - 6912 - 7022 - 7095 - 15250 - 19210 - 45382
(8851, 2, 0, 'Class Trainer', 2868, 15050), -- OptionBroadcastTextID: 2868 - 3429 - 4891 - 5088 - 5360 - 5915 - 6911 - 6999 - 7078 - 15234 - 32202 - 45378
(8851, 1, 0, 'Bank', 3426, 15050), -- OptionBroadcastTextID: 3426 - 5908 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628
(5709, 0, 0, 'Game? Are you crazy?', 9352, 15050),
(6917, 0, 0, 'How can I summon Omen?', 11689, 15050),
(12812, 0, 0, 'I need use of a wyvern to fly me to where the Darkspear emissary went.', 51628, 15050),
(10520, 0, 0, 'Togrik, can you wake up the prisoner again?', 34709, 15050),
(8062, 1, 0, 'Attempt to contact Wind Trader Marid.', 17638, 15050),
(12009, 0, 0, 'I\'ve come at your call, Stonemother.', 45522, 15050),
(2741, 0, 3, 'Train me.', 3266, 15050),
(3501, 0, 1, 'I would like to buy from you.', 2583, 15050), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(5181, 0, 1, 'Let me browse your seasonal fare.', 8786, 15050),
(11878, 1, 0, 'I wish to unlearn my talents.', 8271, 15050), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(11878, 0, 3, 'Teach me the ways of the spirits.', 7658, 15050),
(10639, 0, 0, 'Finding yourself without a Vortex Gem, you reach into the runestone to acquire another.', 35564, 15050),
(10703, 0, 0, 'I am prepared to join you in battle, Hydronis!', 36079, 15050),
(10680, 1, 0, 'I need another Slitherblade Charm, Korrah.', 50632, 15050),
(10691, 0, 0, 'I need another trident.', 50633, 15050),
(12669, 3, 0, 'Can you take me to the Laboratory?', 50694, 15050),
(8950, 0, 1, 'Let me browse your goods.', 2823, 15050); -- OptionBroadcastTextID: 2823 - 7509 - 8097

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40645, `VerifiedBuild`=15050 WHERE (`MenuId`=11427 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40362, `VerifiedBuild`=15050 WHERE (`MenuId`=11372 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=15050 WHERE (`MenuId`=347 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51768, `VerifiedBuild`=15050 WHERE (`MenuId`=12828 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51765, `VerifiedBuild`=15050 WHERE (`MenuId`=12827 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=51763, `VerifiedBuild`=15050 WHERE (`MenuId`=12826 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50035, `VerifiedBuild`=15050 WHERE (`MenuId`=12578 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48787, `VerifiedBuild`=15050 WHERE (`MenuId`=12441 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48095, `VerifiedBuild`=15050 WHERE (`MenuId`=12343 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47936, `VerifiedBuild`=15050 WHERE (`MenuId`=12301 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=56943, `VerifiedBuild`=15050 WHERE (`MenuId`=13389 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33207, `VerifiedBuild`=15050 WHERE (`MenuId`=10277 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33209, `VerifiedBuild`=15050 WHERE (`MenuId`=10278 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36067, `VerifiedBuild`=15050 WHERE (`MenuId`=12716 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=36067, `VerifiedBuild`=15050 WHERE (`MenuId`=10837 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34817, `VerifiedBuild`=15050 WHERE (`MenuId`=10528 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34720, `VerifiedBuild`=15050 WHERE (`MenuId`=10521 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34719, `VerifiedBuild`=15050 WHERE (`MenuId`=10521 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34718, `VerifiedBuild`=15050 WHERE (`MenuId`=10521 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34717, `VerifiedBuild`=15050 WHERE (`MenuId`=10521 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34716, `VerifiedBuild`=15050 WHERE (`MenuId`=10521 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34693, `VerifiedBuild`=15050 WHERE (`MenuId`=10519 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34629, `VerifiedBuild`=15050 WHERE (`MenuId`=10514 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=15050 WHERE (`MenuId`=11873 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44674, `VerifiedBuild`=15050 WHERE (`MenuId`=11872 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50849, `VerifiedBuild`=15050 WHERE (`MenuId`=12725 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33211, `VerifiedBuild`=15050 WHERE (`MenuId`=10279 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33186, `VerifiedBuild`=15050 WHERE (`MenuId`=10272 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=46613, `VerifiedBuild`=15050 WHERE (`MenuId`=12133 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=9817, `VerifiedBuild`=15050 WHERE (`MenuId`=11361 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=19755, `VerifiedBuild`=15050 WHERE (`MenuId`=8460 AND `OptionIndex`=0);

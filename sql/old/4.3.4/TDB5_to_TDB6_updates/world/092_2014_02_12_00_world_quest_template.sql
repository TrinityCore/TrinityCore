-- Fix quest Wine Shop Advert to use proper player gender in gossip text
UPDATE `quest_template` SET `OfferRewardText`='Ah, so you\'ve seen Renato? Well here you are, $G sir:madam;. A bottle of our special pinot noir. You\'ll not find its equal in all of Azeroth!' WHERE `id`=332;
-- Fix quest gossip for quest 33: Wolves Across The Border
-- Questgiver incorrectly thanks player for meat after asking them to get pelts
UPDATE `quest_template` SET `OfferRewardText`='\'Twas a grim task, friend, but you held up your part of the bargain.\r\n\r\nI have some things here you might want - take your pick!' WHERE `id`=33;
UPDATE `quest_template` SET `RequestItemsText`='Hey $N. How goes the hunt for diseased young wolves?' WHERE `id`=33;

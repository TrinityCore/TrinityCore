/*
-- fix sons of hodir reputation amounts to correspond to 3.3.5 retail
UPDATE `quest_template` SET `RewardFactionOverride1`=65000 WHERE `id` IN (13559,13108,13003); -- Hodir's Tribute awards 650 rep per turn-in; Whatever it Takes! and Thrusing Hodir's Spear also award 650 rep
UPDATE `quest_template` SET `RewardFactionOverride1`=2860000 WHERE `id` IN (12915,12924); -- Mending Fences and A Spark of Hope award 28600 rep
UPDATE `quest_template` SET `RewardFactionOverride1`=32500 WHERE `id` IN (12924,13011,12975,12985,13001); -- Forging an Alliance, Jormuttar is Soo Fat..., In Memoriam, Forging a Head, Raising Hodir's Spear reward 325 rep each
UPDATE `quest_template` SET `RewardFactionOverride1`=45500 WHERE `id` IN (12981,12977,13010,13420,13421,13006,12994,13046); -- Hot and Cold, Blowing Hodir's Horn, 'Krolmir, Hammer of Storms', Everfrost, Remember Everfrost!, Polishing the Helm, Spy Hunter, Feeding Arngrim each award 455 reputation
UPDATE `quest_template` SET `RewardFactionOverride1`=32500 WHERE `id` = 12987; -- Mounting Hodir's Helm awards 325 rep
UPDATE `quest_template` SET `RewardFactionOverride1`=97 WHERE `id` = 12976; -- A Monument to the Fallen awards 97 rep
*/

-- Shadow Hunder Denjai Queststarter and Endings

DELETE FROM `creature_queststarter` WHERE `id` IN (96014);
DELETE FROM `creature_questender` WHERE `id` IN (96014);

INSERT INTO `creature_queststarter` VALUES
(96014, 39510), -- Shadow Hunter Denjai, A Little Wetwork
(96014, 39511), -- Shadow Hunter Denjai, Blood of Fallen Brothers
(96014, 39509), -- Shadow Hunter Denjai, Bloodied Blades of Zeth'Gol
(96014, 39513), -- Shadow Hunter Denjai, Disarming Sha'naar
(96014, 39514), -- Shadow Hunter Denjai, Harnessing Their Power
(96014, 39526), -- Shadow Hunter Denjai, Pressing the Attack
(96014, 39512); -- Shadow Hunter Denjai, Secrets of the Shadow Council

INSERT INTO `creature_questender` VALUES
(96014, 39510), -- Shadow Hunter Denjai, A Little Wetwork
(96014, 39511), -- Shadow Hunter Denjai, Blood of Fallen Brothers
(96014, 39509), -- Shadow Hunter Denjai, Bloodied Blades of Zeth'Gol
(96014, 39513), -- Shadow Hunter Denjai, Disarming Sha'naar
(96014, 39514), -- Shadow Hunter Denjai, Harnessing Their Power
(96014, 39604), -- Shadow Hunter Denjai, I Sunk Your Battleship
(96014, 39526), -- Shadow Hunter Denjai, Pressing the Attack
(96014, 39512); -- Shadow Hunter Denjai, Secrets of the Shadow Council

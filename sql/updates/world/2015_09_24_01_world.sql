-- Vindicator Krethos Queststarter and endings

DELETE FROM `creature_queststarter` WHERE `id` IN (90974);
DELETE FROM `creature_questender` WHERE `id` IN (90974);

INSERT INTO `creature_queststarter` VALUES
(90974, 39568), -- Vindicator Krethos, A Little Wetwork
(90974, 39567), -- Vindicator Krethos, Bloodied Blades of Zeth'Gol
(90974, 39569), -- Vindicator Krethos, Breaking Their Fel Bonds
(90974, 39571), -- Vindicator Krethos, Disarming Sha'naar
(90974, 39573), -- Vindicator Krethos, Harnessing Their Power
(90974, 39574), -- Vindicator Krethos, Pressing the Attack
(90974, 39570); -- Vindicator Krethos, Secrets of the Shadow Council

INSERT INTO `creature_questender` VALUES
(90974, 39568), -- Vindicator Krethos, A Little Wetwork
(90974, 39567), -- Vindicator Krethos, Bloodied Blades of Zeth'Gol
(90974, 39569), -- Vindicator Krethos, Breaking Their Fel Bonds
(90974, 39571), -- Vindicator Krethos, Disarming Sha'naar
(90974, 39573), -- Vindicator Krethos, Harnessing Their Power
(90974, 39601), -- Vindicator Krethos, I Sunk Your Battleship
(90974, 39574), -- Vindicator Krethos, Pressing the Attack
(90974, 39570); -- Vindicator Krethos, Secrets of the Shadow Council

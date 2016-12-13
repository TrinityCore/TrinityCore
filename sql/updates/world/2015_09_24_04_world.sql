-- Draka Queststarter and Endings

DELETE FROM `creature_queststarter` WHERE `id` IN (90481);
DELETE FROM `creature_questender` WHERE `id` IN (90481);

INSERT INTO `creature_queststarter` VALUES
(90481, 38415), -- Draka, Garrison Campaign: Onslaught at Auchindoun
(90481, 38453), -- Draka, Garrison Campaign: The Bane of the Bleeding Hollow
(90481, 38458), -- Draka, Garrison Campaign: The Warlock
(90481, 39423), -- Draka, Shipyard Report
(90481, 38577); -- Draka, The Battle for the West

INSERT INTO `creature_questender` VALUES
(90481, 37940), -- Draka, Assault on Ironhold Harbor
(90481, 38441), -- Draka, Assault on The Fel Forge
(90481, 38252), -- Draka, Assault on the Ruins of Kra'nak
(90481, 38449), -- Draka, Assault on the Temple of Sha'naar
(90481, 38586), -- Draka, Assault on the Throne of Kil'jaeden
(90481, 38047), -- Draka, Battle At The Iron Front
(90481, 38044), -- Draka, Bleeding the Bleeding Hollow
(90481, 38001), -- Draka, Commander in the Field!
(90481, 37935), -- Draka, The Assault Base
(90481, 38989); -- Draka, Your Orders, General?

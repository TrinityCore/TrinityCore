-- Exarch Yrel Queststarter and Endings

DELETE FROM `creature_queststarter` WHERE `id` IN (90309);
DELETE FROM `creature_questender` WHERE `id` IN (90309);

INSERT INTO `creature_queststarter` VALUES
(90309, 38421), -- Exarch Yrel, Garrison Campaign: Onslaught at Auchindoun
(90309, 38560), -- Exarch Yrel, Garrison Campaign: The Bane of the Bleeding Hollow
(90309, 38561), -- Exarch Yrel, Garrison Campaign: The Warlock
(90309, 39422), -- Exarch Yrel, Shipyard Report
(90309, 38581); -- Exarch Yrel, The Battle for the West

INSERT INTO `creature_questender` VALUES
(90309, 37891), -- Exarch Yrel, Assault on Ironhold Harbor
(90309, 38440), -- Exarch Yrel, Assault on The Fel Forge
(90309, 38250), -- Exarch Yrel, Assault on the Ruins of Kra'nak
(90309, 37968), -- Exarch Yrel, Assault on the Temple of Sha'naar
(90309, 38585), -- Exarch Yrel, Assault on the Throne of Kil'jaeden
(90309, 38046), -- Exarch Yrel, Battle At The Iron Front
(90309, 38045), -- Exarch Yrel, Bleeding the Bleeding Hollow
(90309, 38446), -- Exarch Yrel, Commander in the Field!
(90309, 38445), -- Exarch Yrel, The Assault Base
(90309, 38996); -- Exarch Yrel, Your Orders, General?

-- Merchant Maku (142668), the howdah vendor on the Mighty Caravan Brutosaur.
-- Stock is the 30 items Wowhead lists for him (https://www.wowhead.com/npc=142668/merchant-maku).
-- Prices are the item buy prices, which match that list. Stock is unlimited.

DELETE FROM `npc_vendor` WHERE `entry` = 142668;

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `BonusListIDs`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(142668, 1, 6256, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Fishing Pole
(142668, 2, 6530, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Nightcrawlers
(142668, 3, 38682, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Enchanting Vellum
(142668, 4, 39354, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Light Parchment
(142668, 5, 158186, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Distilled Water
(142668, 6, 158205, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Acacia Powder
(142668, 7, 159919, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Salted Tideway Cod
(142668, 8, 159920, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Fermented Greatshark
(142668, 9, 159959, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Nylon Thread
(142668, 10, 160059, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Amber Tanning Oil
(142668, 11, 160298, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Durable Flux
(142668, 12, 160398, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Choral Honey
(142668, 13, 160399, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Wild Flour
(142668, 14, 160400, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Foosaka
(142668, 15, 160502, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Chemical Blasting Cap
(142668, 16, 160705, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Major's Frothy Coffee
(142668, 17, 160709, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Fresh Potato
(142668, 18, 160710, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Wild Berries
(142668, 19, 160711, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Aromatic Fish Oil
(142668, 20, 160712, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Powdered Sugar
(142668, 21, 161128, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Seaside Leafy Greens Mix
(142668, 22, 161373, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Seared Simmerfin
(142668, 23, 161383, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Jancunda Nigiri
(142668, 24, 162559, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Hearty Swamp Gumbo
(142668, 25, 162588, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Weathered Scrollcase
(142668, 26, 163075, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Stormshore Haddock
(142668, 27, 163076, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Murkfathom Herring
(142668, 28, 163077, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Glacier Bay Halibut
(142668, 29, 163203, 0, 0, 0, 1, NULL, 0, 0, 69933), -- Hypersensitive Azeritometer Sensor
(142668, 30, 163569, 0, 0, 0, 1, NULL, 0, 0, 69933); -- Insulated Wiring

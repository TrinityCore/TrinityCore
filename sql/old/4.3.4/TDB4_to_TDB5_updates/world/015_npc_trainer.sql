DELETE FROM `npc_trainer` WHERE `entry` IN (200300, 200302, 200303, 200304, 200305);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
-- Riding
(200300, 33389, 32000, 0, 0, 20), -- Apprentice Riding
(200300, 33392, 400000, 762, 75, 40), -- Journeyman Riding
-- Fishing
(200302, 54084, 80000, 356, 275, 0), -- Master Fishing
(200302, 18249, 20000, 356, 200, 0), -- Artisan Fishing
(200302, 7733, 80, 0, 0, 5), -- Apprentice Fishing
(200302, 7734, 400, 356, 50, 0), -- Journeyman Fishing
(200302, 54083, 8000, 356, 125, 0), -- Expert Fishing
(200302, 88869, 400000, 356, 425, 0), -- Illustrious Grand Master Fishing
(200302, 51293, 120000, 356, 350, 0), -- Grand Master Fishing
-- First Aid
(200303, 10841, 8000, 129, 240, 0), -- Heavy Mageweave Bandage
(200303, 18629, 16000, 129, 260, 0), -- Runecloth Bandage
(200303, 18630, 16000, 129, 290, 0), -- Heavy Runecloth Bandage
(200303, 10847, 20000, 129, 200, 35), -- Artisan First Aid
(200303, 10840, 8000, 129, 210, 0), -- Mageweave Bandage
(200303, 7929, 4000, 129, 180, 0), -- Heavy Silk Bandage
(200303, 7928, 4000, 129, 150, 0), -- Silk Bandage
(200303, 54254, 800, 129, 125, 0), -- Expert First Aid
(200303, 3277, 200, 129, 80, 0), -- Wool Bandage
(200303, 3278, 800, 129, 115, 0), -- Heavy Wool Bandage
(200303, 7934, 200, 129, 80, 0), -- Anti-Venom
(200303, 3280, 400, 129, 50, 0), -- Journeyman First Aid
(200303, 3279, 80, 0, 0, 0), -- Apprentice First Aid
(200303, 3276, 80, 129, 40, 0), -- Heavy Linen Bandage
(200303, 27033, 32000, 129, 330, 0), -- Heavy Netherweave Bandage
(200303, 54255, 80000, 129, 275, 50), -- Master First Aid
(200303, 27032, 16000, 129, 300, 0), -- Netherweave Bandage
(200303, 45546, 48000, 129, 400, 0), -- Heavy Frostweave Bandage
(200303, 50299, 120000, 129, 350, 65), -- Grand Master First Aid
(200303, 45545, 32000, 129, 350, 0), -- Frostweave Bandage
(200303, 88893, 64000, 129, 525, 0), -- Dense Embersilk Bandage
(200303, 74560, 200000, 129, 425, 75), -- Illustrious Grand Master First Aid
(200303, 74556, 48000, 129, 425, 0), -- Embersilk Bandage
(200303, 74557, 64000, 129, 475, 0), -- Heavy Embersilk Bandage
(200303, 74558, 12000, 129, 525, 0), -- Field Bandage: Dense Embersilk
-- Archaeology
(200304, 80836, 800, 0, 0, 20), -- Apprentice Archaeology
(200304, 89129, 800, 794, 50, 20), -- Journeyman Archaeology
(200304, 89724, 20000, 794, 200, 35), -- Artisan Archaeology
(200304, 89726, 120000, 794, 350, 65), -- Grand Master Archaeology
(200304, 89723, 800, 794, 125, 20), -- Expert Archaeology
(200304, 89725, 80000, 794, 275, 50), -- Master Archaeology
(200304, 89727, 200000, 794, 425, 75), -- Illustrious Grand Master Archaeology
-- Cooking
(200305, 45551, 16000, 185, 350, 0), -- Worm Delight
(200305, 51295, 280000, 185, 350, 0), -- Grand Master Cook
(200305, 45552, 16000, 185, 350, 0), -- Roasted Worg
(200305, 45560, 8000, 185, 350, 0), -- Smoked Rockfin
(200305, 45564, 16000, 185, 350, 0), -- Smoked Salmon
(200305, 45549, 16000, 185, 350, 0), -- Mammoth Meal
(200305, 45553, 16000, 185, 350, 0), -- Rhino Dogs
(200305, 45561, 8000, 185, 350, 0), -- Grilled Bonescale
(200305, 45565, 16000, 185, 350, 0), -- Poached Nettlefish
(200305, 45569, 16000, 185, 350, 0), -- Baked Manta Ray
(200305, 58065, 16000, 185, 350, 0), -- Dalaran Clam Chowder
(200305, 45550, 16000, 185, 350, 0), -- Shoveltusk Steak
(200305, 45554, 40000, 185, 375, 0), -- Great Feast
(200305, 45562, 8000, 185, 350, 0), -- Sauteed Goby
(200305, 45566, 16000, 185, 350, 0), -- Pickled Fangtooth
(200305, 64358, 40000, 185, 400, 0), -- Black Jelly
(200305, 45563, 16000, 185, 350, 0), -- Grilled Sculpin
(200305, 42296, 12000, 185, 320, 0), -- Stewed Trout
(200305, 42302, 16000, 185, 350, 0), -- Fisherman's Feast
(200305, 42305, 16000, 185, 350, 0), -- Hot Buttered Trout
(200305, 54256, 80000, 185, 275, 0), -- Master Cook
(200305, 88006, 28000, 185, 425, 0), -- Blackened Surprise
(200305, 88015, 24000, 185, 415, 0), -- Darkbrew Lager
(200305, 88054, 400000, 185, 425, 0), -- Illustrious Grand Master Cook
(200305, 18261, 20000, 185, 200, 0), -- Artisan Cook
(200305, 46688, 5200, 185, 250, 0), -- Juicy Bear Burger
(200305, 46684, 5200, 185, 250, 0), -- Charred Bear Kabobs
(200305, 18240, 4800, 185, 240, 0), -- Grilled Squid
(200305, 18243, 5200, 185, 250, 0), -- Nightfin Soup
(200305, 18244, 5200, 185, 250, 0), -- Poached Sunscale Salmon
(200305, 4094, 400, 185, 175, 0), -- Barbecued Buzzard Wing
(200305, 54257, 8000, 185, 125, 0), -- Expert Cook
(200305, 21175, 3200, 185, 200, 0), -- Spider Sausage
(200305, 3400, 400, 185, 175, 0), -- Soothing Turtle Bisque
(200305, 18238, 4000, 185, 225, 0), -- Spotted Yellowtail
(200305, 2546, 120, 185, 80, 0), -- Dry Pork Ribs
(200305, 6500, 240, 185, 125, 0), -- Goblin Deviled Clams
(200305, 3399, 360, 185, 150, 0), -- Tasty Lion Steak
(200305, 3412, 400, 185, 50, 0), -- Journeyman Cook
(200305, 37836, 8, 185, 1, 0), -- Spice Bread
(200305, 2539, 40, 185, 10, 0), -- Spiced Wolf Meat
(200305, 2541, 80, 185, 50, 0), -- Coyote Steak
(200305, 2544, 160, 185, 75, 0), -- Crab Cake
(200305, 6499, 80, 185, 50, 0), -- Boiled Clams
(200305, 6415, 80, 185, 50, 0), -- Fillet of Frenzy
(200305, 6412, 40, 185, 10, 0), -- Kaldorei Spider Kabob
(200305, 2551, 80, 0, 0, 0), -- Apprentice Cook
(200305, 93741, 64, 185, 40, 0); -- Venison Jerky


-- These cost have a reputation reduction
UPDATE `npc_trainer` SET `spellcost`=`spellcost`*1.25 WHERE `entry` IN (200300, 200302, 200303, 200304, 200305);

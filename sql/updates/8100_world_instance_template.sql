/*
AZEROTH
Shadowfang Keep Entrance, Stormwind Stockades Entrance, DeadMines Entrance, Uldaman Entrance, Gnomeregan Entrance,
Altar of Atal'Hakkar Entrance, Scarlet Monastery - Graveyard (Entrance), Blackrock Spire - Searing Gorge Instance (Inside),
Blackrock Mountain - Searing Gorge Instance?, Scholomance Entrance, Zul'Gurub Entrance, Stratholme - Eastern Plaguelands Instance,
Karazhan, Main (Entrance)
*/
UPDATE `instance_template` SET `parent` = 0 WHERE `map` IN (33, 34, 36, 70, 90, 109, 189, 229, 230, 289, 309, 329, 532);

/*
KALIMDOR
The Barrens - Wailing Caverns, Razorfen Kraul Entrance, Blackphantom Deeps Entrance, Razorfen Downs Entrance,
Zul'Farrak Entrance, Onyxia's Lair Entrance, Caverns Of Time, Black Morass (Entrance), Maraudon,
Ragefire Chasm - Ogrimmar Instance, Dire Maul, Ruins Of Ahn'Qiraj (Outside), Ahn'Qiraj Temple (Outside),
Battle Of Mount Hyjal, Alliance Base (Entrance), Culling of Stratholme (entrance), Caverns Of Time, Old Hillsbrad Foothills (Entrance)
*/
UPDATE `instance_template` SET `parent` = 1 WHERE `map` IN (43, 47, 48, 129, 209, 249, 269, 349, 389, 429, 509, 531, 534, 560, 595);

/*
OUTLAND
The Shattered Halls (Entrance), The Blood Furnace (Entrance), Hellfire Ramparts (Entrance), Magtheridon's Lair (Entrance),
The Steamvault (Entrance), The Underbog (Entrance), The Slave Pens (Entrance), Serpentshrine Cavern (Entrance),
The Eye (Entrance), The Arcatraz (Entrance), The Botanica (Entrance), The Mechanar (Entrance),
Shadow Labyrinth (Entrance), Sethekk Halls (Entrance), Mana Tombs (Entrance), Auchenai Crypts (Entrance),
Black Temple (Entrance), Gruul's Lair (Entrance),
Zul'Aman (Entrance), Sunwell Plateau (Entrance), Magisters' Terrace (Entrance),
*/
UPDATE `instance_template` SET `parent` = 530 WHERE `map` IN (540, 542, 543, 544, 545, 546, 547, 548, 550, 552, 553, 554, 555, 556, 557, 558, 564, 565, 568, 580, 585);

/*
NORTHREND
Chamber of Aspects, Obsidian Sanctum (entrance), Utgarde Keep (entrance), Utgarde Pinnacle (entrance),
The Nexus (entrance), The Oculus (entrance), Naxxramas (to frostwyrm lair), Violet Hold (entrance),
Gundrak (entrance north), Ulduar, Halls of Lightning (entrance), Ulduar, Halls of Stone (entrance),
Azjol-Nerub (entrance), Ahn'Kahet (entrance), Drak'Tharon Keep (entrance), The Eye of Eternity (entrance),
Vault of Archavon (Entrance), Ulduar Raid entrance, Trial of the Champion, Trial of the Crusader,
*/
UPDATE `instance_template` SET `parent` = 571 WHERE `map` IN (615, 574, 575, 576, 578, 533, 608, 604, 602, 599, 601, 619, 600, 616, 624, 603, 650, 649);

-- The Molten Bridge
UPDATE `instance_template` SET `parent` = 230 WHERE `map` = 409;

-- Blackwing Lair - Blackrock Mountain - Eastern Kingdoms
UPDATE `instance_template` SET `parent` = 229 WHERE `map` = 469;


/*
NOT ASSIGNED, SET TO DBC VALUE
*/

/*
DBC VALUE 0
Warsong Gulch, Alterac Valley, Arathi Basin, Eye of the Storm, Nagrand Arena, Blades Edge Arena, Ruins of Lordaeron,
Isle of Conquest, Strand of the Ancients
*/
UPDATE `instance_template` SET `parent` = 0 WHERE `map` IN (489, 529, 566, 559, 562, 572, 628, 607);
/*
DBC VALUE 4294967295
Alterac Valley
*/
UPDATE `instance_template` SET `parent` = 4294967295 WHERE `map` IN (30);

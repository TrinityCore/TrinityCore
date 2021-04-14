UPDATE `creature` SET `equipment_id`=-1 WHERE `id` IN (26437,27185,27290,29016,32702,32706);
UPDATE `creature` SET `equipment_id`=1 WHERE `id` IN (1035,11941,14277,1477,1478,15045,15046,15062,15063,15064,15074,15075,15086,15089,16802,
16825,16831,16864,17056,17191,18278,18408,18488,18547,19071,19159,19164,19169,19170,19171,19355,19425,19444,19661,20102,202,20876,21448,22016,
23698,23748,23766,23863,24006,24322,24436,24938,25094,25115,25234,25235,25238,25240,25248,25258,25259,25261,25271,25317,25342,25343,25496,25967,
25975,25994,26112,26113,26179,26184,26477,26604,26795,27044,27062,27207,27271,27293,27298,27301,27316,
27359,27432,27557,27566,27665,2784,28260,28490,28852,29152,29195,29325,29427,29497,29505,29506,29731,300,30571,30627,
32704,32710,32711,3309,3318,3319,3320,334,34838,36154,37696,37846,38316,3875,40492,4507,464,486,54,5697,5734,5841,7207,7804,7999,
8216,823,8402);

DELETE FROM `creature_equip_template` WHERE `entry` IN (1035,11941,14277,1477,1478,15045,15046,15062,15063,15064,15074,15075,15086,15089,
16802,16825,16831,16864,17056,17191,18278,18408,18488,18547,19071,19159,19164,19169,19170,19171,19355,19425,19444,19661,20102,202,20876,
21448,22016,23698,23748,23766,23863,24006,24322,24436,24938,25094,25115,25234,25235,25238,25240,25248,25258,25259,25261,25271,25317,25342,
25343,25496,25967,25975,25994,26112,26113,26179,26184,26437,26477,26604,26795,27044,27062,27185,27207,27271,27290,
27293,27298,27301,27316,27359,27432,27557,27566,27665,2784,28260,28490,28852,29016,29152,29195,29325,29427,29497,29505,29506,29731,300,
30571,30627,32702,32704,32706,32710,32711,3309,3318,3319,3320,334,34838,36154,37696,37846,38316,3875,40492,4507,464,486,54,5697,
5734,5841,7207,7804,7999,8216,823,8402);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(1035 , 1, 1896 , 2051 , 0), -- Dragonmaw Swamprunner
(11941, 1, 13861, 0, 0), -- Yori Crackhelm
(14277, 1, 0, 0, 13147), -- Lady Zephris
(1477 , 1, 2705 , 0, 0), -- Christoph Faral
(1478 , 1, 2705 , 0, 0), -- Aedis Brom
(15045, 1, 3367 , 0, 0), -- Arathi Farmer
(15046, 1, 3367 , 0, 0), -- Forsaken Farmer
(15062, 1, 19015, 0, 0), -- Arathi Lumberjack
(15063, 1, 1903 , 0, 0), -- Arathi Blacksmith
(15064, 1, 1903 , 0, 0), -- Forsaken Blacksmith
(15074, 1, 1910 , 0, 0), -- Arathi Miner
(15075, 1, 1910 , 0, 0), -- Forsaken Miner
(15086, 1, 3367 , 0, 0), -- Arathi Stablehand
(15089, 1, 19015, 0, 0), -- Forsaken Lumberjack
(16802, 1, 14882, 24038, 0), -- Lor'themar Theron
(16825, 1, 2703 , 0, 0), -- Father Malgor Devidicus
(16831, 1, 2704 , 13407, 0), -- Nethergarde Infantry
(16864, 1, 2717 , 3757 , 0), -- Stormwind Infantry
(17056, 1, 13612, 0, 0), -- Eversong Partygoer
(17191, 1, 6228 , 0, 0), -- Siltfin Oracle
(18278, 1, 1903 , 0, 0), -- Pilot Marsha
(18408, 1, 1903 , 0, 0), -- Warden Moi'bff Jill
(18488, 1, 27849, 27849, 0), -- Telaari Watcher
(18547, 1, 12751, 0, 0), -- Scryer Arcanist
(19071, 1, 27852, 0, 0), -- Telaari Elekk Rider
(19159, 1, 1903 , 0, 0), -- Allerian Peasant Cosmetic
(19164, 1, 2707 , 0, 0), -- Refugee Child
(19169, 1, 2705 , 0, 0), -- Blood Elf Commoner
(19170, 1, 2827 , 0, 0), -- Peasant Refugee
(19171, 1, 33963, 0, 0), -- Draenei Commoner
(19355, 1, 1903 , 0, 0), -- Shadowmoon Peon
(19425, 1, 1903 , 0, 0), -- Orgrimmar Peon
(19444, 1, 1903 , 0, 0), -- Peasant Worker
(19661, 1, 1911 , 0, 0), -- Viggz Shinesparked
(20102, 1, 2703 , 0, 0), -- Goblin Commoner
(202  , 1, 1896 , 0, 0), -- Skeletal Horror
(20876, 1, 1903 , 0, 0), -- Human Refugee
(21448, 1, 5291 , 0, 2552) , -- Gadgetzan Sniper
(22016, 1, 31205, 31205, 0), -- Eclipsion Soldier
(23698, 1, 13861, 0, 0), -- Drunken Brewfest Reveler
(23748, 1, 12744, 12745, 0), -- Kurzel
(23766, 1, 2717 , 0, 0), -- Morgom
(23863, 1, 33975, 0, 0), -- Zul'jin
(24006, 1, 3362 , 0, 0), -- Foreman Tionn
(24322, 1, 34816, 0, 0), -- Ancient Citizen of Nifflevar
(24436, 1, 2029 , 0, 0), -- Gargoth
(24938, 1, 34301, 0, 34277), -- Shattered Sun Marksman
(25094, 1, 2704 , 0, 0), -- Navigator Tah're
(25115, 1, 31743, 34588, 0), -- Shattered Sun Warrior
(25234, 1, 2028 , 0, 0), -- Stormfleet Deckhand
(25235, 1, 2028 , 0, 0), -- Hilda Stoneforge
(25238, 1, 2028 , 0, 0), -- Gamlen
(25240, 1, 2028 , 0, 0), -- Bromm
(25248, 1, 853  , 0, 0), -- "Salty" John Thorpe
(25258, 1, 2703 , 0, 0), -- Footman Rob
(25259, 1, 2703 , 0, 0), -- Footman George
(25261, 1, 2703 , 0, 0), -- Footman Chuck
(25271, 1, 2028 , 0, 0), -- Valiance Keep Worker
(25317, 1, 2178 , 0, 0), -- Civilian Recruit
(25342, 1, 10612, 12456, 0), -- Dead Caravan Guard
(25343, 1, 10616, 0, 0), -- Dead Caravan Worker
(25496, 1, 34816, 34819, 0), -- Kvaldir Mist Lord
(25967, 1, 13861, 0, 0), -- Zephyr
(25975, 1, 1906 , 2081 , 0), -- Master Fire Eater
(25994, 1, 1906 , 2081 , 0), -- Flame Eater
(26112, 1, 1902 , 0, 0), -- Bor'gorok Peon
(26113, 1, 1906 , 2081 , 0), -- Master Flame Eater
(26179, 1, 1117 , 0, 0), -- Taunka'le Refugee
(26184, 1, 1117 , 0, 0), -- Taunka'le Refugee
(26437, 1, 34639, 0, 0), -- Taunka Soldier
(26437, 2, 34640, 21549, 0), -- Taunka Soldier
(26477, 1, 32610, 0, 0), -- Dead Mage Hunter
(26604, 1, 2717 , 0, 0), -- Mack Fearsen
(26795, 1, 19970, 0, 0), -- Drakkari Oracle
(27044, 1, 2827 , 0, 0), -- Ordal McLumpkins
(27062, 1, 0, 13611, 0), -- Brom Armstrong
(27185, 1, 0, 13611, 0), -- Kuk'uq
(27185, 2, 14535, 0, 0), -- Kuk'uq
(27207, 1, 768  , 0, 0), -- Onslaught Workman
(27271, 1, 0, 13341, 0), -- Initiate Knapp
(27290, 1, 25587, 13604, 0), -- Hungering Dead
(27290, 2, 3346 , 0, 0), -- Hungering Dead
(27290, 3, 3367 , 0, 0), -- Hungering Dead
(27293, 1, 5278 , 0, 0), -- Amberpine Woodsman
(27298, 1, 0, 12859, 0), -- Apprentice Ranch
(27301, 1, 3699 , 0, 0), -- Apprentice Trotter
(27316, 1, 28648, 0, 0), -- Inquisitor Hallard
(27359, 1, 3346 , 0, 0), -- Trapped Wintergarde Villager
(27432, 1, 3350 , 0, 0), -- Warsong Hold Peon
(27557, 1, 34682, 0, 0), -- Warsong Elite
(27566, 1, 34784, 0, 0), -- Unu'pe Villager
(27665, 1, 34682, 0, 0), -- Kor'kron Pillager
(2784 , 1, 12883, 12883, 0), -- King Magni Bronzebeard
(28260, 1, 33521, 0, 0), -- Defeated Argent Footman
(28490, 1, 13505, 0, 0), -- Disciple of Frost
(28852, 1, 12322, 0, 0), -- Dead Mam'toth Disciple
(29016, 1, 1911 , 0, 0), -- Steam Tank Engineer
(29016, 2, 31824, 0, 0), -- Steam Tank Engineer
(29152, 1, 1911 , 0, 0), -- Stormwind Dock Worker
(29195, 1, 13505, 0, 0), -- Lady Alistra
(29325, 1, 6256 , 0, 0), -- Torgo the Younger
(29427, 1, 2901 , 0, 0), -- Captive Vrykul
(29497, 1, 28442, 0, 0), -- Walther Whiteford
(29505, 1, 5956 , 13611, 0), -- Imindril Spearsong
(29506, 1, 5956 , 0, 0), -- Orland Schaeffer
(29731, 1, 33318, 0, 0), -- Frostborn Iceshaper
(300  , 1, 2023 , 0, 0), -- Zzarc' Vul
(30571, 1, 2196 , 0, 0), -- Michael Belfast
(30627, 1, 49919, 50798, 0), -- Nightmare Figment
(32702, 1, 44638, 0, 0), -- Drog Skullbreaker
(32702, 2, 44654, 0, 0), -- Drog Skullbreaker
(32704, 1, 44638, 0, 0), -- Danric the Bold
(32706, 1, 44638, 0, 0), -- Saedelin Whitedawn
(32706, 2, 44654, 0, 0), -- Saedelin Whitedawn
(32710, 1, 0, 0, 44635), -- Garl Grimgrizzle
(32711, 1, 0, 0, 44643), -- Warp-Huntress Kula
(3309 , 1, 12852, 12855, 0), -- Karus
(3318 , 1, 12856, 12859, 0), -- Koma
(3319 , 1, 0, 1985 , 0), -- Sana
(3320 , 1, 12850, 12745, 0), -- Soran
(334  , 1, 2178 , 2052 , 0), -- Gath'Ilzogg
(34838, 1, 34817, 0, 0), -- Kvaldir Reaver
(36154, 1, 2703 , 0, 0), -- [DND] Valgarde Peon
(37696, 1, 14533, 0, 0), -- Crusader Halford
(37846, 1, 49767, 0, 0), -- Blood-Queen Lana'thel
(38316, 1, 2028 , 0, 0), -- Ormus the Penitent
(3875 , 1, 2827 , 0, 0), -- Haunted Servitor
(40492, 1, 33979, 0, 0), -- Zild'jian
(4507 , 1, 1906 , 0, 0), -- Daisy
(464  , 1, 1899 , 143  , 0), -- Guard Parker
(486  , 1, 1983 , 0, 0), -- Tharil'zun
(54   , 1, 1903 , 0, 0), -- Corina Steele
(5697 , 1, 2717 , 0, 0), -- Theresa
(5734 , 1, 2199 , 0, 0), -- Apothecary Keever
(5841 , 1, 3432 , 0, 0), -- Rocklance
(7207 , 1, 6651 , 0, 0), -- Doc Mixilpixil
(7804 , 1, 2182 , 0, 0), -- Trenton Lighthammer
(7999 , 1, 5598 , 0, 14105), -- Tyrande Whisperwind
(8216 , 1, 11762, 11762, 0), -- Retherokk the Berserker
(823  , 1, 1896 , 0, 0), -- Deputy Willem
(8402 , 1, 2901 , 0, 0); -- Enslaved Archaeologist

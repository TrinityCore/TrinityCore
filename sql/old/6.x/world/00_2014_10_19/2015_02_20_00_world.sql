-- Gameobject QuestStarters
DELETE FROM `gameobject_queststarter` WHERE `id` IN (212181, 216322, 211754, 218765, 215844, 214062, 218072, 213767, 209673, 213973, 221413, 209845, 221376, 212389, 214562, 214871, 214903, 215705, 218750);
INSERT INTO `gameobject_queststarter` (`id`, `quest`) VALUES 
(212181, 29743), -- GO: Ancient Statue Q: Monstrosity
(216322, 32222), -- GO: Bounty Board Q: Wanted: Chief Engineer Cogwrench
(216322, 32223), -- GO: Bounty Board Q: Wanted: Lieutenant Ethan Jacobson
(211754, 30797), -- GO: Curious Text Q: It Was Almost Alive
(218765, 32643), -- GO: Empty Crate Q: Work Order: Dominance Offensive II
(218765, 32646), -- GO: Empty Crate Q: Work Order: Operation: Shieldwall II
(218765, 32648), -- GO: Empty Crate Q: Work Order: Golden Lotus II
(218765, 32650), -- GO: Empty Crate Q: Work Order: Shado-Pan II
(218765, 32657), -- GO: Empty Crate Q: Work Order: The August Celestials II
(218765, 32659), -- GO: Empty Crate Q: Work Order: The Klaxxi II
(218765, 32943), -- GO: Empty Crate Q: Work Order: Sunreaver Onslaught II
(218765, 32945), -- GO: Empty Crate Q: Work Order: Kirin Tor Offensive II
(215844, 31999), -- GO: Flagpole Q: Nazgrim's Command
(214062, 31398), -- GO: Glowing Amber Q: Falling to Pieces
(218072, 32505), -- GO: Head of the Chamberlain Q: The Crumbled Chamberlain
(213767, 31315), -- GO: Hidden Treasure Q: The Heartland Legacy
(209673, 29782), -- GO: Jade Tiger Pillar Q: Stronger Than Bone
(213973, 31010), -- GO: Klaxxi Sonic Relay Q: In Her Clutch
(221413, 33107), -- GO: Lin Family Scroll Q: Bad Feeling, Worse Result
(209845, 29889), -- GO: Mouthwatering Brew Q: Borrowed Brew
(221376, 33018), -- GO: Old Sign Fragment Q: Noodle Secrets Long Forgotten
(212389, 31068), -- GO: Scroll of Auspice Q: Sacred Recipe
(214562, 31661), -- GO: Sha-Haunted Crystal Q: A Source of Terrifying Power
(214871, 29747), -- GO: Shattered Destroyer Q: Break the Cycle
(214871, 29748), -- GO: Shattered Destroyer Q: Simulacrumble
(214903, 29755), -- GO: The Tan-Chao Q: Pei-Back
(215705, 30534), -- GO: Tillers Shrine Q: A Second Hand
(218750, 32642), -- GO: Work Orders Q: Work Order: Dominance Offensive I
(218750, 32647), -- GO: Work Orders Q: Work Order: Golden Lotus I
(218750, 32944), -- GO: Work Orders Q: Work Order: Kirin Tor Offensive I
(218750, 32645), -- GO: Work Orders Q: Work Order: Operation: Shieldwall I
(218750, 32649), -- GO: Work Orders Q: Work Order: Shado-Pan I
(218750, 32942), -- GO: Work Orders Q: Work Order: Sunreaver Onslaught I
(218750, 32653), -- GO: Work Orders Q: Work Order: The August Celestials I
(218750, 32658); -- GO: Work Orders Q: Work Order: The Klaxxi I

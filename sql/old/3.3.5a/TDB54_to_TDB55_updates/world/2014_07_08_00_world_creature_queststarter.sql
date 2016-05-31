-- Alliance
--
DELETE FROM `creature_queststarter` WHERE `quest` IN (6071,6072,6073,6074,6075,6076,9757);

-- Thorgas Grimson (Coldridge Valley, Dun Morogh)
-- Note: There is a discrepancy wether this NPC actually starts the chain, wowhead is outdated
SET @npcId=895;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6072); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6075); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Tristane Shadowstone (Brenwall Village, Dun Morogh)
-- Note: This NPC is not a trainer but wowhead / wowwiki show that she offers the starter. Possibly because she is in a quest hub.
SET @npcId=11807;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6072); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6075); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Ayanna Everstride (Teldrassil)
SET @npcId=3596;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6071); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6074); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Jocaste (Darnassus)
SET @npcId=4146;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6071); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6074); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Dorion (Darnassus)
SET @npcId=4205;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6071); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6074); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Regnus Thundergranite (Ironforge)
SET @npcId=5117;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6072); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6074); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Einris Brightspear (Stormwind)
SET @npcId=5515;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6073); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6076); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Acteon (Azuremyst Isle)
SET @npcId=17110;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6073); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6074); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Deremiis (The Exodar)
SET @npcId=16738;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6073); -- Night Elf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6074); -- Dwarf
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9757); -- Draenei

-- Horde
-- 
DELETE FROM `creature_queststarter` WHERE `quest` IN (6065,6066,6067,6068,6069,6070,9617,10530);

-- Kary Thunderhorn (Thunder Bluff)
SET @npcId=3038;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6066); -- Tauren
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6068); -- Orc / Troll
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9617); -- Blood Elf

-- Lanka Farshot (Camp Narache)
SET @npcId=3061;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6067); -- Tauren
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6069); -- Orc / Troll
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9617); -- Blood Elf

-- Jen'shan Note: Unknown location, wowhead data was outdated
SET @npcId=3154;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6067); -- Tauren
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6069); -- Orc / Troll
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9617); -- Blood Elf

-- Thotar (Durotar)
SET @npcId=3171;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6065); -- Tauren
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6069); -- Orc / Troll
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9617); -- Blood Elf

-- Sian'dur - Note: Unknown location, wowhead data was outdated
SET @npcId=3407;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6067); -- Tauren
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6070); -- Orc / Troll
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9617); -- Blood Elf

-- Telenus (Farstrider Square) - NOTE: He is actually a "Pet Trainer"
SET @npcId=16271;
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6067); -- Tauren
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,6069); -- Orc / Troll
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES (@npcId,9617); -- Blood Elf

-- Fixing Portal to Vale of the Eternal Blossoms --
UPDATE gameobject_template SET Data0 = 132623 WHERE entry = 216057;
UPDATE gameobject_template SET Data0 = 132625 WHERE entry = 216058;

-- Fixing Portal to Stormshield --
-- Fixing Portal to Ashran from Stormwind and Orgrimmar and Correct Default Name -
UPDATE gameobject_template SET NAME = "Portal to Ashran" AND Data0 = 167221 WHERE entry = 237733; -- Orgrimmar
UPDATE gameobject_template SET NAME = "Portal to Ashran" AND VerifiedBuild = 25996 WHERE entry = 243477; -- Stormwind

UPDATE gameobject SET id = 243477 WHERE guid = 1479210; -- Correct Spawn in Stormwind Keep

-- Also Fix some Bugged Portal Trainers --
UPDATE creature_template SET gossip_menu_id = 12235 AND npcflag = 49 WHERE entry = 47253;
UPDATE creature_template SET gossip_menu_id = 20496 AND npcflag = 49 WHERE entry = 96786;
UPDATE creature_template SET npcflag = 17 WHERE entry = 88254;

-- Add Missing Data for Julia Watkins --
DELETE FROM npc_trainer WHERE ID = 88254;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`, `Index`) VALUES
(88254,3562,5100,0,0,0,0),
(88254,3565,5100,0,0,0,0),
(88254,3561,5100,0,0,0,0),
(88254,10059,16500,0,0,0,0),
(88254,11416,16500,0,0,0,0),
(88254,11419,16500,0,0,0,0),
(88254,32266,16500,0,0,0,0),
(88254,32271,5100,0,0,0,0),
(88254,33690,81000,0,0,0,0),
(88254,33691,105000,0,0,0,0),
(88254,49359,5100,0,0,0,0),
(88254,49360,16500,0,0,0,0),
(88254,53140,150000,0,0,0,0),
(88254,53142,168000,0,0,0,0),
(88254,88342,282000,0,0,0,0),
(88254,88345,282000,0,0,0,0),
(88254,132620,423000,0,0,0,0),
(88254,132621,423000,0,0,0,0),
(88254,176248,635000,0,0,0,0),
(88254,176246,635000,0,0,0,0),
(88254,224869,500000,0,0,0,0),
(88254,224871,500000,0,0,0,0);
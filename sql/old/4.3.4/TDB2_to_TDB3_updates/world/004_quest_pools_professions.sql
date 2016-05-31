SET @PTGUID := 358; -- 14 needed

-- Jewelcrafting Daily Quests
-- --------------------------

-- Insert Jewelcrafting Daily Pool Templates
DELETE FROM `pool_template` WHERE `entry` IN (@PTGUID+0, @PTGUID+1);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@PTGUID+0, 1, 'Marith Lazuria - Daily Quests'), -- Marith Lazuria <Jewelcrafting Supplies>
(@PTGUID+1, 1, 'Isabel Jones - Daily Quests'); -- Isabel Jones <Jewelcrafting Design Vendor>

-- Insert Jewelcrafting Daily Quest Pools
DELETE FROM `pool_quest` WHERE `entry` IN (25160, 25162, 25158, 25161, 25159, 25154, 25156, 25105, 25155, 25157);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(25160, @PTGUID+0, 'A Present for Lila'),
(25162, @PTGUID+0, 'Elemental Goo'),
(25158, @PTGUID+0, 'Nibbler! No!'),
(25161, @PTGUID+0, 'Ogrezonians in the Mood'),
(25159, @PTGUID+0, 'The Latest Fashion!'),
(25154, @PTGUID+1, 'A Present for Lila'),
(25156, @PTGUID+1, 'Elemental Goo'),
(25105, @PTGUID+1, 'Nibbler! No!'),
(25155, @PTGUID+1, 'Ogrezonians in the Mood'),
(25157, @PTGUID+1, 'The Latest Fashion!');

-- Update Quests to correct Faction and MinLevel Requirements
UPDATE `quest_template` SET `RequiredRaces`=946 WHERE `Id` IN (25160, 25162, 25158, 25161, 25159); -- Horde only Jewelcrafting Daily Quests
UPDATE `quest_template` SET `RequiredRaces`=2098253 WHERE `Id` IN (25154, 25156, 25105, 25155, 25157); -- Alliance only Jewelcrafting Daily Quests


-- Cooking Daily Quests
-- --------------------

-- Insert Cooking Daily Pool Templates
DELETE FROM `pool_template` WHERE `entry` BETWEEN @PTGUID+2 AND @PTGUID+7;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@PTGUID+2, 1, 'Aska Mistrunner - Daily Quests'), -- Aska Mistrunner <Cooking Trainer> (Thunder Bluff)
(@PTGUID+3, 1, 'Marogg - Daily Quests'), -- Marogg <Infantry Chef> (Orgrimmar)
(@PTGUID+4, 1, 'Eunice Burch - Daily Quests'), -- Eunice Burch <Cooking Trainer> (Undercity)
(@PTGUID+5, 1, 'Robby Flay - Daily Quests'), -- Robby Flay <Head Chef> (Stormwind)
(@PTGUID+6, 1, 'Daryl Riknussun - Daily Quests'), -- Daryl Riknussun <Cooking Trainer> (Ironforge)
(@PTGUID+7, 1, 'Alegorn - Daily Quests'); -- Alegorn <Cooking Trainer> (Darnassus)

-- Insert Cooking Daily Quest Pools
DELETE FROM `pool_quest` WHERE `entry` IN (29362, 29364, 29363, 29365, 29358, 26227, 26226, 26235, 26220, 26233, 29333, 29315, 29332, 29334, 29360, 26190, 26177, 26192, 26153, 26183, 29352, 29351, 29355, 29356, 29353, 29316, 29314, 29318, 29357, 29313);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(29362, @PTGUID+2, '"Magic" Mushrooms'),
(29364, @PTGUID+2, 'Corn Mash'),
(29363, @PTGUID+2, 'Mulgore Spice Bread'),
(29365, @PTGUID+2, 'Perfectly Picked Portions'),
(29358, @PTGUID+2, 'Pining for Nuts'),
(26227, @PTGUID+3, 'Careful, This Fruit Bites Back'),
(26226, @PTGUID+3, 'Crawfish Creole'),
(26235, @PTGUID+3, 'Even Thieves Get Hungry'),
(26220, @PTGUID+3, 'Everything Is Better with Bacon'),
(26233, @PTGUID+3, 'Stealing From Our Own'), -- TODO: Trolls should get Quest 26234 instead of 26233
(29333, @PTGUID+4, 'Escargot A Go-Go'),
(29315, @PTGUID+4, 'Fungus Among Us'),
(29332, @PTGUID+4, 'Lily, Oh Lily'),
(29334, @PTGUID+4, 'Roach Coach'),
(29360, @PTGUID+4, 'Would You Like Some Flies With That?'),
(26190, @PTGUID+5, 'A Fisherman''s Feast'),
(26177, @PTGUID+5, 'Feeling Crabby?'),
(26192, @PTGUID+5, 'Orphans Like Cookies Too!'),
(26153, @PTGUID+5, 'Penny''s Pumpkin Pancakes'),
(26183, @PTGUID+5, 'The King''s Cider'),
(29352, @PTGUID+6, 'A Fowl Shortage'),
(29351, @PTGUID+6, 'A Round for the Guards'),
(29355, @PTGUID+6, 'Can''t Get Enough Spice Bread'),
(29356, @PTGUID+6, 'I Need to Cask a Favor'),
(29353, @PTGUID+6, 'Keepin'' the Haggis Flowin'''),
(29316, @PTGUID+7, 'Back to Basics'),
(29314, @PTGUID+7, 'Remembering the Ancestors'),
(29318, @PTGUID+7, 'Ribs for the Sentinels'),
(29357, @PTGUID+7, 'Spice Bread Aplenty'),
(29313, @PTGUID+7, 'The Secret to Perfect Kimchi');

-- Update Quests to correct Faction and MinLevel Requirements
UPDATE `quest_template` SET `RequiredRaces`=946 WHERE `Id` IN (29362, 29364, 29363, 29365, 29358, 26227, 26226, 26235, 26220, 29333, 29315, 29332, 29334, 29360); -- Horde only Cooking Daily Quests
UPDATE `quest_template` SET `RequiredRaces`=818 WHERE `Id`=26233; -- All Horde Races except Troll
UPDATE `quest_template` SET `RequiredRaces`=2098253 WHERE `Id` IN (26190, 26177, 26192, 26153, 26183, 29352, 29351, 29355, 29356, 29353, 29316, 29314, 29318, 29357, 29313); -- Alliance only Cooking Daily Quests


-- Fishing Daily Quests
-- --------------------

-- Insert Fishing Daily Pool Templates
DELETE FROM `pool_template` WHERE `entry` BETWEEN @PTGUID+8 AND @PTGUID+13;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(@PTGUID+8, 1, 'Razgar - Daily Quests'), -- Razgar <Master Angler> (Orgrimmar)
(@PTGUID+9, 1, 'Kah Mistrunner - Daily Quests'), -- Kah Mistrunner <Fishing Trainer> (Thunder Bluff)
(@PTGUID+10, 1, 'Armand Cromwell - Daily Quests'), -- Armand Cromwell <Fishing Trainer> (Undercity)
(@PTGUID+11, 1, 'Catherine Leland - Daily Quests'), -- Catherine Leland <Fishing Supplies> (Stormwind)
(@PTGUID+12, 1, 'Grimnur Stonebrand - Daily Quests'), -- Grimnur Stonebrand <Fishing Trainer> (Ironforge)
(@PTGUID+13, 1, 'Astaia - Daily Quests'); -- Astaia <Fishing Trainer> (Darnassus)

-- Insert Fishing Daily Quest Pools
DELETE FROM `pool_quest` WHERE `entry` IN (26588, 26572, 26557, 26543, 26556, 29349, 29345, 29354, 29348, 29346, 29317, 29320, 29361, 29319, 29322, 26488, 26420, 26414, 26442, 26536, 29342, 29344, 29347, 29343, 29350, 29325, 29359, 29321, 29323, 29324);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(26588, @PTGUID+8, 'A Furious Catch'),
(26572, @PTGUID+8, 'A Golden Opportunity'),
(26557, @PTGUID+8, 'A Staggering Effort'),
(26543, @PTGUID+8, 'Clammy Hands'),
(26556, @PTGUID+8, 'No Dumping Allowed'),
(29349, @PTGUID+9, 'Craving Crayfish'),
(29345, @PTGUID+9, 'Pond Predators'),
(29354, @PTGUID+9, 'Shiny Baubles'),
(29348, @PTGUID+9, 'The Race to Restock'),
(29346, @PTGUID+9, 'The Ring''s the Thing'),
(29317, @PTGUID+10, 'Fish Head'),
(29320, @PTGUID+10, 'Like Pike?'),
(29361, @PTGUID+10, 'Moat Monster!'),
(29319, @PTGUID+10, 'Tadpole Terror'),
(29322, @PTGUID+10, 'Time for Slime'),
(26488, @PTGUID+11, 'Big Gulp'),
(26420, @PTGUID+11, 'Diggin'' For Worms'),
(26414, @PTGUID+11, 'Hitting a Walleye'),
(26442, @PTGUID+11, 'Rock Lobster'),
(26536, @PTGUID+11, 'Thunder Falls'),
(29342, @PTGUID+12, 'Cold Water Fishing'),
(29344, @PTGUID+12, 'Fish fer Squirky'),
(29347, @PTGUID+12, 'Live Bait'),
(29343, @PTGUID+12, 'One fer the Ages'),
(29350, @PTGUID+12, 'The Gnomish Bait-o-Matic'),
(29325, @PTGUID+13, 'A Slippery Snack'),
(29359, @PTGUID+13, 'An Old Favorite'),
(29321, @PTGUID+13, 'Happy as a Clam Digger'),
(29323, @PTGUID+13, 'Stocking Up'),
(29324, @PTGUID+13, 'The Sister''s Pendant');

-- Update Quests to correct Faction and MinLevel Requirements
UPDATE `quest_template` SET `RequiredRaces`=946 WHERE `Id` IN (26588, 26572, 26557, 26543, 26556, 29349, 29345, 29354, 29348, 29346, 29317, 29320, 29361, 29319, 29322); -- Horde only Fishing Daily Quests
UPDATE `quest_template` SET `RequiredRaces`=2098253 WHERE `Id` IN (26488, 26420, 26414, 26442, 26536, 29342, 29344, 29347, 29343, 29350, 29325, 29359, 29321, 29323, 29324); -- Alliance only Fishing Daily Quests

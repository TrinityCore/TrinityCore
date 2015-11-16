--  1 = Alterac Valley
--  2 = Warsong Gulch
--  3 = Arathi Basin
--  7 = Eye of The Storm
--  4 = Nagrand Arena
--  5 = Blades's Edge Arena
--  6 = All Arena
--  8 = Ruins of Lordaeron
--  9 = Strand of the Ancients
-- 10 = Dalaran Sewers
-- 11 = The Ring of Valor
-- 30 = Isle of Conquest
-- 32 = Random battleground

-- MinPlayersPerTeam
UPDATE `battleground_template` SET `MinPlayersPerTeam` = 2  WHERE `ID` = 2; -- Warsong Gulch
UPDATE `battleground_template` SET `MinPlayersPerTeam` = 3  WHERE `ID` IN (3, 7, 9); -- Arathi Basin, Eye of The Storm, Strand of the Ancients
UPDATE `battleground_template` SET `MinPlayersPerTeam` = 10 WHERE `ID` = 1; -- Alterac Valley
UPDATE `battleground_template` SET `MinPlayersPerTeam` = 3  WHERE `ID` = 32; -- RBG

-- Weights
UPDATE `battleground_template` SET `Weight` = 0  WHERE `ID` = 1;       -- Alterac Valley
UPDATE `battleground_template` SET `Weight` = 0  WHERE `ID` = 30;      -- Isle of Conquest
UPDATE `battleground_template` SET `Weight` = 3  WHERE `ID` = 2;       -- Warsong Gulch
UPDATE `battleground_template` SET `Weight` = 2  WHERE `ID` = 9;       -- Strand of the Ancients
UPDATE `battleground_template` SET `Weight` = 3  WHERE `ID` IN (3, 7); -- Arathi Basin, Eye of The Storm

-- Allow 'Dalaran Sewers' and 'The Ring of Valor' for 2v2 and 3v3 too
UPDATE `azerothshard-world`.`battleground_template` SET `MinPlayersPerTeam`=0 WHERE `ID`=10;
UPDATE `azerothshard-world`.`battleground_template` SET `MinPlayersPerTeam`=0 WHERE `ID`=11;

-- Enable 'Dalaran Sewers'
DELETE FROM `azerothshard-world`.`disables` WHERE  `sourceType`=3 AND `entry`=10;

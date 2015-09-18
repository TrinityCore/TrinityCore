UPDATE `battleground_template` SET `MinPlayersPerTeam` = 2 WHERE `ID` = 2; -- Warsong Gulch
UPDATE `battleground_template` SET `MinPlayersPerTeam` = 5 WHERE `ID` IN (3, 7, 9); -- Arathi Basin, Eye of The Storm, Strand of the Ancients
UPDATE `battleground_template` SET `MinPlayersPerTeam` = 10 WHERE `ID` = 1; -- Alterac Valley

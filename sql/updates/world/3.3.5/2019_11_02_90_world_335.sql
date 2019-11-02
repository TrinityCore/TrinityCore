
-- Alterac Valley
UPDATE `battleground_template`
SET `MinPlayersPerTeam` = 10, `MaxPlayersPerTeam` = 20
WHERE ID = 1;

-- Warsong Gulch
UPDATE `battleground_template`
SET `MinPlayersPerTeam` = 3, `MaxPlayersPerTeam` = 6
WHERE ID = 2;

-- Arathi Basin
UPDATE `battleground_template`
SET `MinPlayersPerTeam` = 5, `MaxPlayersPerTeam` = 10
WHERE ID = 3;

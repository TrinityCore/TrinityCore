UPDATE `battleground_template` SET `MaxPlayersPerTeam`=5 WHERE `id` IN (4, 5, 6, 8);
UPDATE `battleground_template` SET `MinPlayersPerTeam`=8 WHERE `id`=9;
UPDATE `battleground_template` SET `MinPlayersPerTeam`=10 WHERE `id` IN (1, 30);
UPDATE `battleground_template` SET `MinPlayersPerTeam`=0 WHERE `id` IN (10, 11);
UPDATE `battleground_template` SET `MinPlayersPerTeam`=5, `MaxPlayersPerTeam`=40 WHERE `id`=32;

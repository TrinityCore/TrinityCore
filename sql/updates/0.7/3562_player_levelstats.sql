DELETE FROM player_levelstats WHERE race=2 and class=4 and level=19;
DELETE FROM player_levelstats WHERE race=2 and class=4 and level=20;
INSERT INTO player_levelstats VALUES
('2', '4', '19', '391', '0', '38', '44', '35', '20', '30'),
('2', '4', '20', '414', '0', '38', '46', '36', '20', '30');
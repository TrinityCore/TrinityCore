DELETE FROM `battleground_template` WHERE `id` IN (100, 101, 102);
INSERT INTO `battleground_template` (`id`, `MinPlayersPerTeam`, `MaxPlayersPerTeam`, `MinLvl`, `MaxLvl`, `AllianceStartLoc`, `AllianceStartO`, `HordeStartLoc`, `HordeStartO`, `StartMaxDist`, `Weight`, `ScriptName`, `Comment`) VALUES
(100, 5, 10, 10, 85, 0, 0, 0, 0, 0, 1, '', 'Rated Battleground 10x10'),
(101, 8, 15, 20, 85, 0, 0, 0, 0, 0, 1, '', 'Rated Battleground 15x15'),
(102, 10, 25, 71, 85, 0, 0, 0, 0, 0, 1, '', 'Rated Battleground 25x25');

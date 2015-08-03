--
DELETE FROM `battleground_template` WHERE `id` IN (108, 120);
INSERT INTO `battleground_template` (`id`, `MinPlayersPerTeam`, `MaxPlayersPerTeam`, `MinLvl`, `MaxLvl`, `AllianceStartLoc`, `AllianceStartO`, `HordeStartLoc`, `HordeStartO`, `StartMaxDist`, `Weight`, `ScriptName`, `Comment`) VALUES
(108, 5, 10, 85, 85, 1726, 0, 1727, 0, 0, 0, '', 'Twin Peaks'),
(120, 5, 10, 85, 85, 1798, 0, 1799, 0, 0, 0, '', 'The Battle for Gilneas');

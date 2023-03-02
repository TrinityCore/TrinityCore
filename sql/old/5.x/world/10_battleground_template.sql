-- Silvershard Mines
DELETE FROM `battleground_template` WHERE `id` = 708;
INSERT INTO `battleground_template` (`id`, `MinPlayersPerTeam`, `MaxPlayersPerTeam`, `MinLvl`, `MaxLvl`, `AllianceStartLoc`, `AllianceStartO`, `HordeStartLoc`, `HordeStartO`, `StartMaxDist`, `Weight`, `ScriptName`, `Comment`) VALUES
('708', '5', '5', '90', '90', '4062', '0', '4061', '0', '0', '1', '', 'Silvershard Mines');

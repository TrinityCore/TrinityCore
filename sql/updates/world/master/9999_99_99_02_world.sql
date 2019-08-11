
DELETE FROM `battleground_template` WHERE `ID`=719;
INSERT INTO `battleground_template` (`ID`, `MinPlayersPerTeam`, `MaxPlayersPerTeam`, `MinLvl`, `MaxLvl`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `ScriptName`, `Comment`) VALUES
(719, 0, 5, 90, 120, 4136, 4137, 10, 1,'', 'Tol\'viron Arena');

# TrinityCore - WowPacketParser
# File name: arena_legion1.awps.pkt
# Detected build: V8_0_1_28153
# Detected locale: enUS
# Targeted database: BattleForAzeroth
# Parsing date: 11/25/2018 17:59:06

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (250430, 250431);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(250430, 114, 32),
(250431, 114, 32);


DELETE FROM `gameobject_template` WHERE `entry` IN (250431, 250430);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(250431, 0, 34136, 'Roots', '', '', '', 1.11, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153),
(250430, 0, 34136, 'Roots', '', '', '', 1.12, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153);

DELETE FROM `battleground_template` WHERE ID = 816;
INSERT INTO `battleground_template` (`ID`, `MinPlayersPerTeam`, `MaxPlayersPerTeam`, `MinLvl`, `MaxLvl`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `ScriptName`, `Comment`) VALUES
('816', '0', '5', '90', '120', '5307', '5308', '0', '100', '', 'Ashamane\'s Fall Arena');

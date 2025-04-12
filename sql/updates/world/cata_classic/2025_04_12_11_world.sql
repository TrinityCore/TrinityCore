-- Remove some post Cataclysm spawns (Construction site blockers)
DELETE FROM `gameobject` WHERE `guid` IN (501819, 501820, 501821, 502263);
DELETE FROM `gameobject_addon` WHERE `guid` IN (501819, 501820, 501821, 502263);

DELETE FROM `transports` WHERE `guid` IN (1, 2, 6, 8, 9, 11);
INSERT INTO `transports` (`guid`, `entry`, `Name`, `phaseUseFlags`, `phaseId`, `phaseGroup`, `ScriptName`) VALUES
(1, 176495, 'Undercity, Tirisfal Glades and Grom\'gol Base Camp, Stranglethorn Vale ("The Purple Princess")', 0, 0, 0, ''),
(2, 176310, 'Stormwind Harbor and Auberdine, Darkshore ("Ship (The Bravery)")', 0, 0, 0, ''),
(6, 164871, 'Orgrimmar, Durotar and Undercity, Tirisfal Glades ("The Thundercaller")', 0, 0, 0, ''),
(8, 177233, 'The Forgotten Coast, Feralas and Feathermoon Stronghold, Sardor Isle, Feralas ("Feathermoon Ferry")', 0, 0, 0, ''),
(9, 181646, 'Valaar\'s Berth, Azuremyst Isle and Auberdine, Darkshore ("Elune\'s Blessing")', 0, 0, 0, ''),
(11, 181689, 'Undercity, Tirisfal Glades and Vengeance Landing, Howling Fjord ("Zeppelin, Horde (Cloudkisser)")', 0, 0, 0, '');

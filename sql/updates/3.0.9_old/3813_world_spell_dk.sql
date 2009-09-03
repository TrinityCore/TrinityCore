UPDATE `creature_template` SET maxhealth = 133525, minhealth = 133525, maxmana = 51360, minmana = 51360, spell1 = 53114, spell2 = 53112, spell3=53110, VehicleId = 156 where entry = 28670;
UPDATE `creature_template` SET `ScriptName`='npc_dkc1_gothik' WHERE `entry`=28658;

-- gift of harvester
DELETE FROM `spell_script_target` WHERE entry IN (52479);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52479,1,28819),
(52479,1,28822);

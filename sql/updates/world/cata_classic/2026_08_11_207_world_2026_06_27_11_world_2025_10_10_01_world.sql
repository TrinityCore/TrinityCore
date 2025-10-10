--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_drakkari_colossus_surge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(54801, 'spell_drakkari_colossus_surge');

DELETE FROM `spawn_group` WHERE (`groupId` = '33') and (`spawnType` = '0') and (`spawnId` = '127071');
DELETE FROM `spawn_group` WHERE (`groupId` = '33') and (`spawnType` = '0') and (`spawnId` = '127072');
DELETE FROM `spawn_group` WHERE (`groupId` = '33') and (`spawnType` = '0') and (`spawnId` = '127073');
DELETE FROM `spawn_group` WHERE (`groupId` = '33') and (`spawnType` = '0') and (`spawnId` = '127074');
DELETE FROM `spawn_group` WHERE (`groupId` = '33') and (`spawnType` = '0') and (`spawnId` = '127075');

DELETE FROM `spawn_group_template` WHERE `groupId`=328;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(328,'Gundrak - Drakkari Colossus',4);

DELETE FROM `spawn_group` WHERE `groupId`=328;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(328,0,127071),
(328,0,127072),
(328,0,127073),
(328,0,127074),
(328,0,127075);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` =328;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(604,1,23,328,2);

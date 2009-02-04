-- battleground
DELETE FROM `battleground_template` WHERE `id` IN (9,10,11);
INSERT INTO `battleground_template` VALUES
(9,0,0,0,0,1367,0,1368,0),
(10,5,5,10,80,1362,0,1363,0),
(11,5,5,10,80,1364,0,1365,0);

-- command
DELETE FROM `command` WHERE name = 'reload';
DELETE FROM `command` WHERE `name` = 'modify runicpower';
INSERT INTO `command` VALUES
('modify runicpower',1,'Syntax: .modify runicpower #newrunicpower\r\n\r\nModify the runic power of the selected player. If no player is selected, modify your runic power.');

-- string
DELETE FROM `trinity_string` WHERE `entry` in (345,346);
INSERT INTO `trinity_string` VALUES
(345,'Forced customize for player %s will be requested at next login.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(346,'Forced customize for player %s (GUID #%u) will be requested at next login.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `trinity_string` WHERE entry in (712,717,718,719);
INSERT INTO `trinity_string` VALUES
(712,'|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] A: %u/%u, H: %u/%u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(717,'|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] Started!|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(718,'|cffff0000[Arena Queue Announcer]:|r %s -- Joined : %ux%u : %u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(719,'|cffff0000[Arena Queue Announcer]:|r %s -- Exited : %ux%u : %u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `trinity_string` WHERE entry in (720,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736);
INSERT INTO `trinity_string` VALUES
(720,'Your group is too large for this battleground. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(721,'Your group is too large for this arena. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(722,'Your group has members not in your arena team. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(723,'Your group does not have enough players to join this match.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(724,'The Gold Team wins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(725,'The Green Team wins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(726,'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(727,'Your group has an offline member. Please remove him before joining.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(728,'Your group has players from the opposing faction. You can\'t join the battleground as a group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(729,'Your group has players from different battleground brakets. You can\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(730,'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(731,'Someone in your party is Deserter. You can\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(732,'Someone in your party is already in three battleground queues. You cannot join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(733,'You cannot teleport to a battleground or arena map.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(734,'You cannot summon players to a battleground or arena map.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(735,'You must be in GM mode to teleport to a player in a battleground.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(736,'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `trinity_string` WHERE entry in (1122,1123,1124,1125,1126,1127,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1138);

DELETE FROM `trinity_string` WHERE `entry` IN (173,174);
INSERT INTO `trinity_string` VALUES
(173,'You changed runic power of %s to %i/%i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(174,'%s changed your runic power to %i/%i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `trinity_string` WHERE `entry` IN (521,1109,1122);
INSERT INTO `trinity_string` VALUES
(521,'%d - |cffffffff|Hskill:%d|h[%s %s]|h|r %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1109,'%d - %s %s %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1122,'(%u/%u +perm %u +temp %u)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


-- data

INSERT INTO world.player_classlevelstats SELECT * FROM mangos.player_classlevelstats;
INSERT INTO world.player_levelstats SELECT * FROM mangos.player_levelstats;
INSERT INTO world.playercreateinfo_spell SELECT * FROM mangos.playercreateinfo_spell;
INSERT INTO world.playercreateinfo_action SELECT * FROM mangos.playercreateinfo_action;
INSERT INTO world.spell_learn_spell SELECT * FROM mangos.spell_learn_spell;
INSERT INTO world.player_xp_for_level SELECT * FROM mangos.player_xp_for_level;
INSERT INTO world.spell_loot_template SELECT * FROM mangos.spell_loot_template;


DELETE FROM `item_template` WHERE entry IN (34648,34649,34650,34651,34652,34653,34655,34656,34657,34658,34659,38145,38147,41751);
INSERT INTO `item_template` VALUES
(34648,4,4,-1,'Acherus Knight\'s Greaves',51496,2,32768,1,51,10,8,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,10,7,12,3,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,392,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,55,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34649,4,4,-1,'Acherus Knight\'s Gauntlets',51498,2,32768,1,34,6,10,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,15,7,6,32,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,356,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34650,4,4,-1,'Acherus Knight\'s Tunic',51494,2,32768,1,69,13,5,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,20,7,11,32,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,570,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,115,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34651,4,4,-1,'Acherus Knight\'s Girdle',51497,2,32768,1,35,7,6,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,2,4,10,32,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,320,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34652,4,4,-1,'Acherus Knight\'s Hood',51495,2,32768,1,52,10,1,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,15,7,15,32,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,463,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34653,4,4,-1,'Acherus Knight\'s Wristguard',51500,2,32768,1,36,7,9,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,7,31,7,7,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,249,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34655,4,4,-1,'Acherus Knight\'s Pauldrons',51501,2,32768,1,54,10,3,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,11,3,9,7,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,427,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34656,4,4,-1,'Acherus Knight\'s Cover',51499,2,32768,1,73,14,7,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,13,3,10,7,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,499,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,85,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34657,4,0,-1,'Choker of Damnation',6539,2,32768,1,2303,575,2,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,9,7,8,31,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34658,4,0,-1,'Plague Band',963,2,32768,1,534,133,11,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,11,3,6,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34659,4,1,-1,'Acherus Knight\'s Shroud',49738,2,32768,1,31,6,16,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,2,4,12,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(38145,1,0,-1,'Deathweave Bag',1282,1,32768,1,0,0,18,-1,-1,35,0,0,0,0,0,0,0,0,0,1,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(38147,4,0,-1,'Corrupted Band',963,2,32768,1,534,133,11,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,11,3,6,32,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(41751,0,5,-1,'Black Mushroom',36728,1,0,1,100,5,0,-1,-1,65,55,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27094,0,-1,0,0,11,1000,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0);

ALTER TABLE db_version CHANGE COLUMN required_6941_01_mangos_spell_learn_spell required_6944_01_mangos_mangos_string bit;

DELETE FROM mangos_string WHERE entry in (712,717,718,719);
INSERT INTO mangos_string VALUES
(712,'|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] A: %u/%u, H: %u/%u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(717,'|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] Started!|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(718,'|cffff0000[Arena Queue Announcer]:|r %s -- Joined : %ux%u : %u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(719,'|cffff0000[Arena Queue Announcer]:|r %s -- Exited : %ux%u : %u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM mangos_string WHERE entry in (720,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736);
INSERT INTO mangos_string VALUES
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

DELETE FROM mangos_string WHERE entry in (1122,1123,1124,1125,1126,1127,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1138);

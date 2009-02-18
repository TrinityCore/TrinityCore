DELETE FROM `command` WHERE `name` = "flusharenapoints";
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('flusharenapoints','3','Syntax: .flusharenapoints\r\n\r\nUse it to distribute arena points based on arena team ratings, and start a new week.');

DELETE FROM trinity_string WHERE entry BETWEEN 1122 AND 1138;

INSERT INTO trinity_string (entry, content_default) VALUES
    (1122,'Your group is too large for this battleground. Please regroup to join.'),
    (1123,'Your group is too large for this arena. Please regroup to join.'),
    (1124,'Your group has members not in your arena team. Please regroup to join.'),
    (1125,'Your group does not have enough players to join this match.'),
    (1126,'The Gold Team wins!'),
    (1127,'The Green Team wins!'),
    (1128, 'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.'),
    (1129, 'Your group has an offline member. Please remove him before joining.'),
    (1130, 'Your group has players from the opposing faction. You can\'t join the battleground as a group.'),
    (1131, 'Your group has players from different battleground brakets. You can\'t join as group.'),
    (1132, 'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.'),
    (1133, 'Someone in your party is Deserter. You can\'t join as group.'),
    (1134, 'Someone in your party is already in three battleground queues. You cannot join as group.'),
    (1135, 'You cannot teleport to a battleground or arena map.'),
    (1136, 'You cannot summon players to a battleground or arena map.'),
    (1137, 'You must be in GM mode to teleport to a player in a battleground.'),
    (1138, 'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.');

DELETE FROM trinity_string WHERE entry = 714 OR entry = 716;


DELETE FROM `instance_template` WHERE `map` IN ('489', '30', '529', '566', '559', '562', '572');
INSERT INTO `instance_template` (`map`, `parent`, `levelMin`, `levelMax`, `maxPlayers`, `reset_delay`) VALUES 
('489', '0', '10', '0', '50', '0'),
('30', '0', '10', '0', '50', '0'),
('529', '0', '10', '0', '50', '0'),
('566', '0', '10', '0', '50', '0'),
('559', '0', '10', '0', '50', '0'),
('562', '0', '10', '0', '50', '0'),
('572', '0', '10', '0', '50', '0');

DELETE FROM `command` WHERE `name` = "flusharenapoints";
DELETE FROM `command` WHERE `name` = "debug arena";
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('flusharenapoints',3,'Syntax: .flusharenapoints\r\n\r\nUse it to distribute arena points based on arena team ratings, and start a new week.'),
('debug arena',3,'Syntax: .debug arena\r\n\r\n Toggles arena 1v1 or normal mode.');


DELETE FROM trinity_string WHERE entry IN (711,712);
DELETE FROM trinity_string WHERE entry BETWEEN 730 AND 745;
INSERT INTO trinity_string (entry, content_default) VALUES
    (711,'Your group is too large for this battleground. Please regroup to join.'),
    (712,'Your group is too large for this arena. Please regroup to join.'),
    (730,'Your group has members not in your arena team. Please regroup to join.'),
    (731,'Your group does not have enough players to join this match.'),
    (732,'The Gold Team wins!'),
    (733,'The Green Team wins!'),
    (734, 'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.'),
    (735, 'Your group has an offline member. Please remove him before joining.'),
    (736, 'Your group has players from the opposing faction. You can\'t join the battleground as a group.'),
    (737, 'Your group has players from different battleground brakets. You can\'t join as group.'),
    (738, 'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.'),
    (739, 'Someone in your party is Deserter. You can\'t join as group.'),
    (740, 'Someone in your party is already in three battleground queues. You cannot join as group.'),
    (741, 'You cannot teleport to a battleground or arena map.'),
    (742, 'You cannot summon players to a battleground or arena map.'),
    (743, 'You must be in GM mode to teleport to a player in a battleground.'),
    (744, 'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.'),
    (745, 'Arena testing turned %s');
    

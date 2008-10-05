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


DELETE FROM mangos_string WHERE entry BETWEEN 711 AND 728;
INSERT INTO mangos_string (entry, content_default) VALUES
    (711,'Your group is too large for this battleground. Please regroup to join.'),
    (712,'Your group is too large for this arena. Please regroup to join.'),
    (713,'Your group has members not in your arena team. Please regroup to join.'),
    (714,'Your group does not have enough players to join this match.'),
    (715,'The Gold Team wins!'),
    (716,'The Green Team wins!'),
    (717, 'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.'),
    (718, 'Your group has an offline member. Please remove him before joining.'),
    (719, 'Your group has players from the opposing faction. You can\'t join the battleground as a group.'),
    (720, 'Your group has players from different battleground brakets. You can\'t join as group.'),
    (721, 'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.'),
    (722, 'Someone in your party is Deserter. You can\'t join as group.'),
    (723, 'Someone in your party is already in three battleground queues. You cannot join as group.'),
    (724, 'You cannot teleport to a battleground or arena map.'),
    (725, 'You cannot summon players to a battleground or arena map.'),
    (726, 'You must be in GM mode to teleport to a player in a battleground.'),
    (727, 'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.'),
    (728, 'Arena testing turned %s');
    

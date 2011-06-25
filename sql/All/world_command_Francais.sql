/* World Command Francais */
DELETE FROM `command` WHERE name IN ('jail','jailinfo','unjail','jailreload');
INSERT INTO `command` (name, security, help) VALUES
('jail', 1, 'Syntaxe: .jail #personage #heures #raison\nEmprisonner un \'personnage\' pendant \'heures\' pour la \'raison\'.'),
('jailinfo', 0, 'Syntaxe: .jailinfo\nVoir le statut de vos emprisonnements.'),
('unjail', 1, 'Syntaxe: .unjail #personnages\nLibérer le \'personnage\' de la prison.'),
('jailreload', 3, 'Syntaxe: .jailreload\nRecharger la configuration du Jail.');

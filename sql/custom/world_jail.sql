DELETE FROM `command` WHERE name IN ('jail', 'jailinfo', 'unjail', 'jailreload', 'pinfo', 'clearjail');
INSERT INTO `command` (name, security, help) VALUES
('jail',       1, 'Syntax: .jail $char_name $hours $reason\nJailed the \'character\' for \'hours\' with the \'reason\'.'),
('jailinfo',   0, 'Syntax: .jailinfo\nShows your jail status.'),
('unjail',     1, 'Syntax: .unjail $char_name\nRealeases the \'character\' out of the jail.'),
('jailreload', 3, 'Syntax: .jailreload\nLoads the jail config new.'),
('clearjail',  5, 'Syntax: .clearjail $char_name\nRemoves all jail records for character with entered name from DB.'),
('pinfo',      2, 'Syntax: .pinfo [$player_name] [rep] [jail]\nOutput account information for selected player or player find by $player_name.\nIf \'rep\' parameter is provided it shows the reputation information for players.\nIf \'jail\' parameter is provided it shows the jail information for players.');

DELETE FROM trinity_string WHERE `entry` IN (950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983);
INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (950, 'You are jailed by %s for %u hour(s)!', NULL, 'Vous tes emprisonn par %s pour %u heures!', 'Du wurdest von \'%s\' f?r %u Stunde(n) eingebuchtet!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (951, '%s wrote this as reason: %s', NULL, '%s a crit ceci comme tant la raison de votre emprisonnement: %s.', '\'%s\' gab dies als Grund an: %s', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (952, '%s was jailed by you for %u hour(s).', NULL, 'Vous avez emprisonn %s pour %u heures!', '\'%s\' wurde von dir f?r %u Stunde(n) eingebuchtet.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (953, 'You was released out of the jail by %s.', NULL, 'Vous avez t liber de la prison par %s.', '\'%s\' hat dich aus dem Knast entlassen.', NULL, NULL, NULL, NULL, NULL);

   INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (954, 'You have released %s out of the jail.', NULL, 'Vous avez liber %s de la prison.', 'Du hast \'%s\' aus dem Knast geholt.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (955, 'No reason given or reason is < %u chars!', NULL, 'Aucune raison d\\\'emprisonnement donne ou la raison est < %u personnages.', 'Du hast keinen Grund angegeben, oder der Grund ist < %u Zeichen!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (956, 'No name given!', NULL, 'Aucun nom donn!', 'Du hast keinen Namen angegeben!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (957, 'No time given!', NULL, 'Aucun temps donn!', 'Du hast keine Zeit angegeben!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (958, 'The jailtime must be between 1 and %u hours!', NULL, 'Le temps d\\\'emprisonnement est situ entre 1 et %u heures!', 'Die Jail-Zeit muss zwischen 1 und %u Std. liegen!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (959, 'The character (%s) is not jailed!', NULL, '%s n\\\'est pas emprisonn!', 'Der Charakter \'%s\' ist ?berhaupt nicht im Knast!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (960, 'Command forbidden for jailed characters!', NULL, 'Commandes interdites pour les personnages emprisons!', 'Sorry, aber das d?rfen Gefangene nicht!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (961, 'You have %u hour(s) left in the jail.', NULL, 'Vous avez %u heures  attendre avant de quitter la prison.', 'Du musst noch %u Stunde(n) absitzen.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (962, 'You have %u minute(s) left in the jail.', NULL, 'Vous avez %u minutes attendre avant de quitter la prison.', 'Du musst noch %u Minute(n) absitzen.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (963, 'You\'re a free like a bird! ;-)', NULL, 'Vous tes libre.', 'Du bist frei wie ein Vogel! ;-)', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (964, '%s was %u times jailed and has %u minute(s) left. Last time jailed by %s. Last reason was: \'%s\'', NULL, '%s a t librde prison, il avait t emprisonn pour %u et a t libr au aprs %u minutes. Il avait t emprisonn par %s, pour la raison suivante: %s', '\'%s\' war bis jetzt %u mal im Knast, und hat noch %u Minute(n) abzusitzen.\n Zuletzt eingebuchtet von: \'%s\'\nLetzter Grund: %s', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (965, '%s was never jailed.', NULL, '%s n\\\'a jamais t emprisonn.', '\'%s\' hat eine wei?e Weste.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (966, 'You can\'t jail yourself!', NULL, 'Vous ne pouvez pas vous emprisonner vous-m me!', 'Du kannst dich nicht selber einbuchten!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (967, 'You can\'t unjail yourself!', NULL, 'Vous ne pouvez pas vous librer vous m me!', 'So weit kommt es noch, da? Knastbr?der sich selber befreien! :-(', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (968, '|cffff0000[!!! ATTENTION - IMPORTANT - WARNING !!!\r\n You were already %u times in prison beim %u mal your character will be deleted\r\n|cffff0000!!! ATTENTION - IMPORTANT - WARNING !!!]', NULL, '|cffff0000[!!!ATTENTION - ATTENTION - ATTENTION!!!\r\n Vous étiez déjà %u fois en prison en %u fois, votre personnage supprimé\r\n|cffff0000!!! ATTENTION - ATTENTION - ATTENTION !!!]', '|cffff0000[!!! ACHTUNG - WICHTIG - WARNUNG !!!\r\n Du warst schon %u mal in Knast beim %u mal wird dein Charakter gelöscht\r\n|cffff0000!!! ACHTUNG - WICHTIG - WARNUNG !!!]', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (969, 'The character \'', NULL, 'Le personnage ', 'Der Charakter \'', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (970, '\' was jailed for ', NULL, ' a t emprisonn pour ', '\' wurde f?r ', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (971, ' hour(s) by the GM character \'', NULL, ' heure(s) par le MJ ', ' Stunde(n) von dem GM-Charakter \'', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (972, '\'. The reason is: ', NULL, '. La raison est: ', '\' eingebuchtet. Der Grund ist: ', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (973, 'The jail configuration was reloaded.', NULL, 'La configuration de jail a t recharge.', 'Die Gef?ngnis-Konfiguration wurde neu geladen.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (974, '>> Jail config loaded.', NULL, '>> Configuration du jail charge.', '>> Gef?ngnis-Konfiguration geladen.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (975, 'Can\'t load jail config! Table empty or missed! Use characters_jail.sql!', NULL, 'Impossible de charger la configuration du jail! Table vide ou innexistante! Appliquez characters_jail.sql!', 'Fehler beim laden der Gef?ngnis-Konfiguration! Der Table \'jail_conf\' ist leer oder nicht vorhanden! Nutze die \'characters_jail.sql\'!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (976, 'Set all jail config settings to default...', NULL, 'Placez tous les param tres de configuration de prison par d faut.', 'Setze die Konfiguration des Gef?ngnisses auf Standardwerte...', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (977, 'The Character \'%s\'  is jailed and teleported into the jail.', NULL, 'Le personnage %s  est emprisonn et t leport dans la prison.', 'Der Charakter \'%s\'  ist ein Knastbruder und wird in den Knast teleportiert.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (978, 'The Character \'%s\'  was released out of the jail.', NULL, 'Le personnage %s  est liber  de prison.', 'Der Charakter \'%s\'  wurde aus dem Knast entlassen.', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (979, 'A character with this name doesn\'t exists!', NULL, 'Il n\'y a aucun personnage portant ce nom.', 'Ein Charakter mit diesem Namen gibt es nicht!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (980, '|cffff0000[!!! ATTENTION - IMPORTANT - WARNING !!!\r\n You were already %u times in prison beim %u mal your account  will be banned!\r\n|cffff0000!!! ATTENTION - IMPORTANT - WARNING !!!]', NULL, '|cffff0000[!!!ATTENTION - ATTENTION - ATTENTION!!!\r\n Vous avez %u fois en prison en %u fois votre compte sera banni\r\n|cffff0000!!! ATTENTION - ATTENTION - ATTENTION !!!]', '|cffff0000[!!! ACHTUNG - WICHTIG - WARNUNG !!!\r\n Du hast %u mal in Knast beim %u mal wird dein Account gebannt\r\n|cffff0000!!! ACHTUNG - WICHTIG - WARNUNG !!!]', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (981, 'Max. jailtimes reached!', NULL, 'Nombre maximum d\'Jails atteint!', 'Maximale Anzahl an Jails erreicht!', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (982, 'Robotron', NULL, 'Robotron', 'Robotron', NULL, NULL, NULL, NULL, NULL);

INSERT INTO trinity_string
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`)
VALUES
   (983, 'Your Jail status was reset to 0 gesatzt', NULL, 'Votre statut a été Jail à 0 gesatzt', 'Dein Jail status wurde auf 0 zurück gesatzt', NULL, NULL, NULL, NULL, NULL);

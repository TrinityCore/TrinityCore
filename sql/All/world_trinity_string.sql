/* World trinity_string */
SET NAMES 'utf8';
DELETE FROM trinity_string WHERE `entry` IN (950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983);

INSERT INTO `trinity_string` VALUES 
('950', 'You are jailed by \'%s\' for %u hour(s)!', null, 'Vous tes emprisonn par \'%s\' pour %u heures!', 'Du wurdest von \'%s\' für %u Stunde(n) eingebuchtet!', null, null, null, null, null),
('951', '\'%s\' wrote this as reason: \'%s\'', null, '%s a crit ceci comme tant la raison de votre emprisonnement: %s.', '\'%s\' gab dies als Grund an: \'%s\'', null, null, null, null, null),
('952', '\'%s\' was jailed by you for %u hour(s).', null, 'Vous avez emprisonn %s pour %u heures!', '\'%s\' wurde von dir für %u Stunde(n) eingebuchtet.', null, null, null, null, null),
('953', 'You was released out of the jail by %s.', null, 'Vous avez t liber de la prison par %s.', '\'%s\' hat dich aus dem Knast entlassen.', null, null, null, null, null),
('954', 'You have released %s out of the jail.', null, 'Vous avez liber \'%s\' de la prison.', 'Du hast \'%s\' aus dem Knast geholt.', null, null, null, null, null),
('955', 'No reason given or reason is < %u chars!', null, 'Aucune raison d\\\'emprisonnement donne ou la raison est < %u personnages.', 'Du hast keinen Grund angegeben, oder der Grund ist < %u Zeichen!', null, null, null, null, null),
('956', 'No name given!', null, 'Aucun nom donn!', 'Du hast keinen Namen angegeben!', null, null, null, null, null),
('957', 'No time given!', null, 'Aucun temps donn!', 'Du hast keine Zeit angegeben!', null, null, null, null, null),
('958', 'The jailtime must be between 1 and %u hours!', null, 'Le temps d\\\'emprisonnement est situ entre 1 et %u heures!', 'Die Jail-Zeit muss zwischen 1 und %u Std. liegen!', null, null, null, null, null),
('959', 'The character \'%s\' is not jailed!', null, '\'%s\' n\\\'est pas emprisonn!', 'Der Charakter \'%s\' ist Überhaupt nicht im Knast!', null, null, null, null, null),
('960', 'Command forbidden for jailed characters!', null, 'Commandes interdites pour les personnages emprisons!', 'Sorry, aber das d?rfen Gefangene nicht!', null, null, null, null, null),
('961', 'You have %u hour(s) left in the jail.', null, 'Vous avez %u heures  attendre avant de quitter la prison.', 'Du musst noch %u Stunde(n) absitzen.', null, null, null, null, null),
('962', 'You have %u minute(s) left in the jail.', null, 'Vous avez %u minutes attendre avant de quitter la prison.', 'Du musst noch %u Minute(n) absitzen.', null, null, null, null, null),
('963', 'You\'re a free like a bird! ;-)', null, 'Vous tes libre.', 'Du bist frei wie ein Vogel! ;-)', null, null, null, null, null),
('964', '%s was %u times jailed and has %u minute(s) left. Last time jailed by %s. Last reason was: \'%s\'', null, '%s a t librde prison, il avait t emprisonn pour %u et a t libr au aprs %u minutes. Il avait t emprisonn par %s, pour la raison suivante: %s', '\'%s\' war bis jetzt %u mal im Knast, und hat noch %u Minute(n) abzusitzen.\n Zuletzt eingebuchtet von: \'%s\'\nLetzter Grund: %s', null, null, null, null, null),
('965', '\'%s\' was never jailed.', null, '\'%s\' n\\\'a jamais t emprisonn.', '\'%s\' hat eine weiße Weste.', null, null, null, null, null),
('966', 'You can\'t jail yourself!', null, 'Vous ne pouvez pas vous emprisonner vous-m me!', 'Du kannst dich nicht selber einbuchten!', null, null, null, null, null),
('967', 'You can\'t unjail yourself!', null, 'Vous ne pouvez pas vous librer vous m me!', 'So weit kommt es noch, daß Knastbruder sich selber befreien! :-(', null, null, null, null, null),
('968', '|cffff0000[!!! ATTENTION - IMPORTANT - WARNING !!!\r\n You were already %u times in prison. If you are in Jail for a total of  %u times, your character will be deleted\r\n|cffff0000!!! ATTENTION - IMPORTANT - WARNING !!!]', null, '|cffff0000[!!!ATTENTION - ATTENTION - ATTENTION!!!\r\n Vous étiez déjà %u fois en prison en %u fois, votre personnage supprimé\r\n|cffff0000!!! ATTENTION - ATTENTION - ATTENTION !!!]', '|cffff0000[!!! ACHTUNG - WICHTIG - WARNUNG !!!\r\n Du warst schon %u mal in Knast beim %u mal wird dein Charakter gelöscht\r\n|cffff0000!!! ACHTUNG - WICHTIG - WARNUNG !!!]', null, null, null, null, null),
('969', 'The character \'', null, 'Le personnage ', 'Der Charakter \'', null, null, null, null, null),
('970', '\' was jailed for ', null, ' a t emprisonn pour ', '\' wurde für ', null, null, null, null, null),
('971', ' hour(s) by the GM character \'', null, ' heure(s) par le MJ ', ' Stunde(n) von dem GM-Charakter \'', null, null, null, null, null),
('972', '\'. The reason is: ', null, '. La raison est: ', '\' eingebuchtet. Der Grund ist: ', null, null, null, null, null),
('973', 'The jail configuration was reloaded.', null, 'La configuration de jail a t recharge.', 'Die Gefängnis-Konfiguration wurde neu geladen.', null, null, null, null, null),
('974', '>> Trinity Jail config loaded.', null, '>> Configuration du jail charge.', '>> Gefängnis-Konfiguration geladen.', null, null, null, null, null),
('975', 'Can\'t load jail config! Table empty or missed! Use characters_jail.sql!', null, 'Impossible de charger la configuration du jail! Table vide ou innexistante! Appliquez characters_jail.sql!', 'Fehler beim laden der Gef?ngnis-Konfiguration! Der Table \'jail_conf\' ist leer oder nicht vorhanden! Nutze die \'characters_jail.sql\'!', null, null, null, null, null),
('976', 'Set all jail config settings to default...', null, 'Placez tous les param tres de configuration de prison par d faut.', 'Setze die Konfiguration des Gef?ngnisses auf Standardwerte...', null, null, null, null, null),
('977', 'The Character \'%s\'  is jailed and teleportet into the jail.', null, 'Le personnage \'%s\'  est emprisonn et t leport dans la prison.', 'Der Charakter \'%s\'  ist ein Knastbruder und wird in den Knast teleportiert.', null, null, null, null, null),
('978', 'The Character \'%s\'  was released out of the jail.', null, 'Le personnage %s  est liber  de prison.', 'Der Charakter \'%s\'  wurde aus dem Knast entlassen.', null, null, null, null, null),
('979', 'A character with this name doesn\'t exists!', null, 'Il n\'y a aucun personnage portant ce nom.', 'Ein Charakter mit diesem Namen gibt es nicht!', null, null, null, null, null),
('980', '|cffff0000[!!! ATTENTION - IMPORTANT - WARNING !!!\r\n You were already %u times in prison. If you are in Jail for a total of  %u times, your account  will be banned!\r\n|cffff0000!!! ATTENTION - IMPORTANT - WARNING !!!]', null, '|cffff0000[!!!ATTENTION - ATTENTION - ATTENTION!!!\r\n Vous avez %u fois en prison en %u fois votre compte sera banni\r\n|cffff0000!!! ATTENTION - ATTENTION - ATTENTION !!!]', '|cffff0000[!!! ACHTUNG - WICHTIG - WARNUNG !!!\r\n Du hast %u mal in Knast beim %u mal wird dein Account gebannt\r\n|cffff0000!!! ACHTUNG - WICHTIG - WARNUNG !!!]', null, null, null, null, null),
('981', 'Max. jailtimes reached!', null, 'Nombre maximum d\'Jails atteint!', 'Maximale Anzahl an Jails erreicht!', null, null, null, null, null),
('982', 'Robotron', null, 'Robotron', 'Robotron', null, null, null, null, null),
('983', 'Your Jail status was reset to 0 ', null, 'Votre statut a été Jail à 0 ', 'Dein Jail status wurde auf 0 zurück gesatzt', null, null, null, null, null);



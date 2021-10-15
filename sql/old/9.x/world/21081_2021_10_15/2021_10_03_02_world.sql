--
-- 25152 Tu lugar en el mundo
-- https://es.wowhead.com/quest=25152
DELETE FROM `quest_offer_reward_locale` WHERE `ID`='25152' AND `locale`='esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES ('25152', 'esES', 'Otro de los reclutas de Kaltunk, ¿eh?$B$BPues sí que están mal las cosas, si esto es lo mejor que puede ofrecer la Horda. No importa. Para cuando te llegue el momento de salir del Valle, serás un guerrero digno de la Horda.', '0');

-- 25126 Dientes afilados
-- https://es.wowhead.com/quest=25126
-- Blizzard server (quest_request_items_locale)
DELETE FROM `quest_request_items_locale` WHERE `ID`='25126' AND `locale`='esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES ('25126', 'esES','Espero que no hayas vuelto para intentar convencerme de que has terminado tu tarea, $n, ¿verdad? No, claro que no. Esperaría algo mejor de ti.', '0');
DELETE FROM `quest_offer_reward_locale` WHERE `ID`='25126' AND `locale`='esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES ('25126', 'esES', 'Umm... no está mal, $n. Pero que no se te suba a la cabeza... tendrás que luchar con cosas mucho más duras que un jabalí en tu carrera.$B$BSin embargo, has mostrado tu valía, y tu siguiente prueba será contra un adversario mucho más peligroso, necesitarás algo más de protección.', '0');

-- 25172 Invasores en nuestro hogar
-- https://es.wowhead.com/quest=25172
-- Blizzard server (quest_request_items_locale)
DELETE FROM `quest_request_items_locale` WHERE `ID`='25172' AND `locale`='esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES ('25172', 'esES', 'Rápido, $n. Despacha a estos humanos en nuestro valle.', '0');
DELETE FROM `quest_offer_reward_locale` WHERE `ID`='25172' AND `locale`='esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES ('25172', 'esES', 'Ejecutados con rapidez y discreción. Un trabajo bien hecho.', '0');

-- 25127 Aguijón de escórpido
-- https://es.wowhead.com/quest=25127
DELETE FROM `quest_request_items_locale` WHERE `ID`='25127' AND `locale`='esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES ('25127', 'esES', 'El caparazón de un escórpido no es tan resistente como para disuadir la fuerza y determinación de un guerrero. Golpea fuerte y sin dudas, y los escórpidos serán una presa fácil.', '0');
DELETE FROM `quest_offer_reward_locale` WHERE `ID`='25127' AND `locale`='esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES ('25127', 'esES', 'De tus luchas con los escórpidos debes sacar una lección importante. Tanto el menor como el mayor de tus oponentes pueden enviarte directo al infierno. En el combate cualquier cosa y en cualquier número o tamaño puede llevarte a la perdición.$B$BNo tengo nada más que enseñarte, $n. Te has portado bien y seguiré con mucho interés tus progresos.\r\n', '0');

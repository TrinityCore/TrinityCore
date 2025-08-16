-- Quest
DELETE FROM `quest_offer_reward_locale` WHERE `locale`='esMX' AND `ID` IN (24959,28608,26799,28652,24960,25089,26800);
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(24959, 'esMX', 'Hola. Tú debes de ser... ¿$n?', 61967),
(28608, 'esMX', 'Es exactamente lo que necesitaba. Vas a ser una gran baza para los Renegados, $n.$b$bSe rumorea que en tu vida anterior fuiste $gun:una; $c de renombre. A lo mejor debería asignarte una tarea más emocionante.', 61967),
(26799, 'esMX', 'Ni siquiera el poder de las Val\'kyr bastó para salvar a estas criaturas. Estaban condenadas desde el principio.$b$bTe conseguí algo de equipo, $n. No es mucho, pero te ayudará.', 61967),
(28652, 'esMX', '¿Sí? ¿Y tú quién eres?', 61967),
(24960, 'esMX', 'Has hecho bien, $c. Como puedes ver, no todos nos hemos resignado a nuestro destino. Me alegra ver que estás deseando trabajar, al menos.$b$bValdred será un recurso valioso para los Renegados. En cuanto a los otros dos... No hay mucho que podamos hacer. No podemos obligarlos a que se unan a nosotros.', 61967),
(25089, 'esMX', 'Últimamente esas Val\'kyr no dan abasto resucitando a $glos novatos:las novatas; como tú. Esta mañana ya he visto varias docenas de cadáveres corriendo por estas colinas.$b$bPero tú eres $gel:la; $c más $gprometedor:prometedora; que he visto en lo que va de día.', 61967),
(26800, 'esMX', 'Buen trabajo, $n, sabía que no eras $gun:una; inútil.$b$bTen, quédate con uno de estos. Los guardias de la Muerte tienen montones enteros de estos trastos cogiendo polvo.', 61967);

DELETE FROM `quest_request_items_locale` WHERE `locale`='esMX' AND `ID` IN (28608,26799,24960,26800);
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(28608, 'esMX', 'Encontrarás los objetos en el Sepulcro Sombrío. Creo que me los dejé en mi mesa de trabajo.', 61967),
(26799, 'esMX', 'No llegarás lejos en esta nueva vida si no puedes matar ni a las más débiles y descerebradas de las criaturas, $n. No vuelvas hasta que puedas informar de tu éxito.', 61967),
(24960, 'esMX', 'Se acabó el perder el tiempo. Ahora estás entre los Renegados, y los nuestros ocupan un escalafón más alto.', 61967),
(26800, 'esMX', '¿Has conseguido recuperar algún cadáver?', 61967);

UPDATE `quest_request_items` SET `CompletionText`='You will not go far in this new life if you are unable to kill even the weakest, most brainless creatures, $n.  Do not return until you have success to report.', `VerifiedBuild`=61967 WHERE `ID`=26799; -- Those That Couldn't Be Saved

DELETE FROM `quest_request_items` WHERE `ID`=26800;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26800, 0, 6, 0, 0, 'Have you managed to scavenge up some corpses?', 61967); -- Recruitment

-- 783 Una amenaza del interior
-- https://es.classic.wowhead.com/quest=783
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 783 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (783, 'esES', 'Más voluntarios, estupendo.$B$BEspero que seáis suficientes.$B$BLas tierras humanas se ven amenazadas desde el exterior y nuestras tropas están en las fronteras; por eso no tenemos protección en el interior.$B$BEsta baralla tiene muchos frentes, $n. Prepárate para una campaña muy larga.', 0);

-- 15 Investigar la Mina del Eco
-- https://es.classic.wowhead.com/quest=15
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Investigar_la_Mina_del_Eco
DELETE FROM `quest_request_items_locale` WHERE `ID` = 15 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (15, 'esES', '¿Has cumplido tu misión? ', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 15 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (15, 'esES', 'No me gusta que haya kobolds en la mina; eso no puede ser bueno. Bien, acepta esto como pago, y vuelve a hablar conmigo cuando quieras; puede que tengas que volver a la mina...', 0);

-- 3101 Una carta consagrada
-- https://es.classic.wowhead.com/quest=3101
UPDATE `quest_template_locale` SET `Details` = '$n, me han pedido que te diera esto en cuanto volvieras de los campamentos kóbold. Parece una carta sellada con la insignia del hermano Sammuel, nuestro instructor de paladines. Es mejor que la leas antes de dedicarte a cualquier otra cosa. ' WHERE `ID` = 3101 AND `locale` = 'esES';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 3101 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (3101, 'esES', 'Por fin nos conocemos. Te doy la bienvenida a Villanorte. Aquí aprenderás mucho, pero antes o después tu camino te llevará a Ventormenta. Hasta entonces, ten paciencia y aprende.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3101 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3101, 'esES', 'Debes saber que eres un símbolo para muchos; no lo olvides nunca. La Luz Sagrada brilla en ti, visible tanto para amigos como para enemigos.$B$BA medida que adquieres sabiduría y poder, tendrás que aprender otras facultades. Cuando quieras continuar tu instrucción, ven a verme de nuevo. ¡Suerte, $c! ', 0);

-- 21 Escaramuza en la Mina del eco
-- https://es.classic.wowhead.com/quest=21
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Escaramuza_en_la_Mina_del_Eco
DELETE FROM `quest_request_items_locale` WHERE `ID` = 21 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (21, 'esES', 'Sé que es un trabajo sangriento, $n, pero es vital para la seguridad de Villanorte. ¿Has cumplido la misión?', 0);

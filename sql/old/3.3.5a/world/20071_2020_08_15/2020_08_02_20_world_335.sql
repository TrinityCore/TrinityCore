-- 40 Un peligro con olor a pescado
-- https://es.wowhead.com/quest=40
-- https://wow-es.gamepedia.com/Misión:Un peligro con olor a pescado
SET @ID := 40;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, hablé con Remy. Lo respeto como mercader, aunque los informes de los múrlocs del este han sido, por decirlo suavemente, demasiado superficiales.$B$BTomo nota de tu preocupación pero, si no recibo un informe militar sobre la amenaza múrloc, no puedo enviar más tropas al este.', 0);

-- 76 La Cantera de Jaspe
-- https://es.wowhead.com/quest=76
-- https://wow-es.gamepedia.com/Misión:La Cantera de Jaspe
SET @ID := 76;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Que la Luz esté contigo, $n. ¿Qué vienes a informarme? ¿Has explorado la Cantera de Jaspe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Dices que hay kóbolds en la Cantera de Jaspe? ¡Maldita sea! ¡La situación empeora cada minuto!$B$BGracias por el informe, $n. Aunque habría preferido que trajeras buenas noticias, claro.', 0);

-- 60 Las velas de los kóbolds
-- https://es.wowhead.com/quest=60
-- https://wow-es.gamepedia.com/Misión:Las velas de los kóbolds
SET @ID := 60;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has reunido las velas ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Estabas ocupado cazando algún kóbold que otro, ¿eh? Gracias por las velas, $n, aquí tienes tu recompensa.', 0);

-- 106 Jóvenes enamorados
-- https://es.wowhead.com/quest=106
-- https://wow-es.gamepedia.com/Misión:Jóvenes enamorados
SET @ID := 106;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡¿Que tienes qué?! Maybell es la luz que ilumina mi tediosa vida. ¡Déjame ver su carta, deprisa!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ah! No puedo soportar estar separado de ella. ¡¡Tengo que verla!!', 0);

-- 85 El collar perdido
-- https://es.wowhead.com/quest=85
-- https://wow-es.gamepedia.com/Misión:El collar perdido
SET @ID := 85;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que has perdido qué? Pues yo no he robado ningún collar, ¡no soy un ladrón!$B$BCreo que sé quién lo hizo, pero... <sonríe> tengo demasiada hambre para que me funcione la memoria.', 0);

-- 88 ¡Princesa debe morir!
-- https://es.wowhead.com/quest=88
-- https://wow-es.gamepedia.com/Misión:¡Princesa debe morir!
SET @ID := 88;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿La has visto ya? ¿Te has ocupado de ella?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Menos mal! ¡Esa cerda se estaba poniendo tan gorda que se habría comido toda nuestra cosecha! Gracias, $n.', 0);

-- 111 Habla con la abuelita
-- https://es.wowhead.com/quest=111
-- https://wow-es.gamepedia.com/Misión:Habla con la abuelita
SET @ID := 111;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mientras nuestras familias sigan siendo enemigas, Tommy Joe y Maybell no tendrán futuro. Pero quizás podamos reunirlos, aunque sea por poco tiempo.$B$BMm, ¿qué podríamos hacer?', 0);

-- 86 Un pastel para Billy
-- https://es.wowhead.com/quest=86
-- https://wow-es.gamepedia.com/Misión:Un pastel para Billy
SET @ID := 86;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'No creo que esté bien dar de comer al pillo que me robó el collar, pero si es lo que hay que hacer para recuperar lo que es mío, ¡habrá que hacerlo!$B$B¿Tienes la carne de jabalí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Aunque esta carne de jabalí sea dura, cocinándola a fuego lento es más que suficiente. ¡Seguro que sale un jugoso pastel!', 0);

-- 84 Vuelve con Billy
-- https://es.wowhead.com/quest=84
-- https://wow-es.gamepedia.com/Misión:Vuelve con Billy
SET @ID := 84;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ay... ¡Me muero de hambre! ¿Me has traído el pastel, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Mm, qué rico! ¡Este pastel es lo mejor que he comido en mi vida!$B$BCreo que me está volviendo la memoria...', 0);

-- 87 Dientes de Oro
-- https://es.classic.wowhead.com/quest=87
SET @ID := 87;
UPDATE `quest_template_locale` SET `Details` = 'Estaba jugando cerca de la Mina Abisal y creo que se me cayó... esto... quiero decir, creo que vi el collar de la señora. No me preguntes cómo llegó allí, ¡porque no lo sé!$B$BPues eso, que vi a un enorme kóbold con dientes de oro que lo recogía y entraba corriendo a la mina. Si encuentras a ese kóbold, encontrarás el collar, ¡lo juro!', `VerifiedBuild` = '0' WHERE `ID` = @ID AND `locale` = 'esES'; 
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Has encontrado mi collar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, lo has encontrado! ¡Gracias, muchas gracias!$B$BTen, toma esto. Era de mi marido. Siempre dijo que le traía suerte. ¡Es una pena que no lo llevara en su última campaña! *snif*', 0);

-- 107 Una nota para William
-- https://es.wowhead.com/quest=107
-- https://wow-es.gamepedia.com/Misión:Una nota para William
SET @ID := 107;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que tienes una nota de la abuelita Pedregosa, ¿eh? ¡Hace años que no veo a Mildred! Me pregunto qué dirá...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Cómo compadezco a esas pobres almas... Maybell y Tommy Joe. También yo fui joven y también conocí el amor... una vez.$B$B¡Debe de haber algo que pueda hacer para ayudarles! Deja que piense...', 0);

-- 112 La Recolección de Kelp
-- https://es.wowhead.com/quest=112
-- https://wow-es.gamepedia.com/Misión:La Recolección de Kelp
SET @ID := 112;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes el Kelp de Cristal? Estoy seguro de que Maybell está ansiosa por ver a su novio...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ya las tengo. ¡Gran Trabajo! Ahora espera un momento mientras hago la pócima...', 0);

-- 114 La fuga
-- https://es.wowhead.com/quest=114
-- https://wow-es.gamepedia.com/Misión:La fuga
SET @ID := 114;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Entregaste mi carta a Tommy Joe? ¿Y qué dijo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ay! Me siento muy culpable por engañar a mi familia, pero no puedo ignorar lo que siento por Tommy Joe.$B$BGracias, $n. Beberé este licor en cuanto tenga la oportunidad de escaparme para ir a ver a mi amado.', 0);

-- 16 Dale de beber a Gerard
-- https://es.wowhead.com/quest=16
-- https://wow-es.gamepedia.com/Misión:Dale de beber a Gerard
SET @ID := 16;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'La agricultura es un trabajo que da mucha sed y estoy siempre en busca de agua manantial refrescante.$B$BSi tienes algo estoy dispuesto a hacer un intercambio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Gracias, $n! Y vuelve si quieres hacer otro intercambio.', 0);

-- 61 Un envío para Ventormenta
-- https://es.wowhead.com/quest=61
-- https://wow-es.gamepedia.com/Misión:Un envío para Ventormenta
SET @ID := 61;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Oh, ¿Un envío de mi hermano? ¡Espléndido! ¡La fortuna brilla en mí hoy!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Aquí está tu pago... y mientras estás aquí, ¡Echa un vistazo! Estoy seguro de que tenemos alguna poción o abalorio útil para ti.', 0);

-- 332 Publicidad de la bodega
-- https://es.wowhead.com/quest=332
-- https://wow-es.gamepedia.com/Misión:Publicidad de la bodega
SET @ID := 332;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Saludos y $gbienvenido:bienvenida;, $gseñor:señora;. ¿Has probado ya alguno de nuestros vinos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Entonces has visto a Renato? Aquí estamos, $gcaballero:dama;. Una botella de nuestro Dalaran Noir especial. ¡No encontrarás nada mejor en todo Azeroth!', 0);

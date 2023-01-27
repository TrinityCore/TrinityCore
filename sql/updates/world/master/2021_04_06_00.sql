-- DB update 2021_04_05_04 -> 2021_04_06_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_05_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_05_04 2021_04_06_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617676191107839800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617676191107839800');

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

-- 18 Hermandad de ladrones
-- https://es.classic.wowhead.com/quest=18
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Hermandad_de_ladrones
DELETE FROM `quest_request_items_locale` WHERE `ID` = 18 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (18, 'esES', '¿Me traes los pañuelos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 18 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (18, 'esES', 'De vuelta con algunos pañuelos, ya veo... El Ejército de Ventormenta te agradece tu ayuda.', 0);

-- 5261 Eagan Desollapelambres
-- https://es.classic.wowhead.com/quest=5261
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5261 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (5261, 'esES', 'Estoy buscando a alguien que cace lobos, ¿te interesa?', 0);

-- 33 Los lobos cruzan la frontera
-- https://es.wowhead.com/quest=33
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Los_lobos_cruzan_la_frontera
DELETE FROM `quest_request_items_locale` WHERE `ID` = 33 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (33, 'esES', 'Hola, $n. ¿Cómo va la caza de los lobos jóvenes malsanos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 33 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (33, 'esES', 'Era una tarea amarga, $gamigo:amiga;, pero has cumplido tu parte del trato.$B$BTengo algunas cosas que quizás te interesen, ¡elije lo que quieras!', 0);

-- 3903 Milly Osworth
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Milly_Osworth
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3903 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3903, 'esES', '¿Que te envía el Ayudante del Alguacil Willem? Es valiente y voluntarioso, pero está en la Abadía de Villanorte...$B$B¿Tú podrías ayudarme?', 0);

-- 3904 La cosecha de Milly
-- https://wow-es.gamepedia.com/Misi%C3%B3n:La_cosecha_de_Milly
DELETE FROM `quest_request_items_locale` WHERE `ID` = 3904 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (3904, 'esES', '¿Traes la cosecha, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3904 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3904, 'esES', '¡Gracias, $n! ¡Has salvado mi cosecha! Espero que hayas dada una lección a unos cuantos Defias.$B$B¡Aunque tengamos pocas tropas, tenemos la suerte de contar con valientes como tú!', 0);

-- 3905 Informe de la vendimia
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Informe_de_la_vendimia
DELETE FROM `quest_request_items_locale` WHERE `ID` = 3905 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (3905, 'esES', '¡Te veo muy bien! ¡Siéntate y tómate algo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3905 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3905, 'esES', 'Veamos...$B$BOh, has salvado la uva; me preocupé cuando me habló de esos villanos en los viñedos. Por suerte, nunca perdí la fe en la Luz.$B$BY ahora, gracias a tu valor, podremos hacer vino. Que la Luz te acompañe y te proteja, $n. ', 0);

-- 6 La recompensa por Garrick Piesuaves 
-- https://wow-es.gamepedia.com/Misi%C3%B3n:La_recompensa_por_Garrick_Piesuaves
DELETE FROM `quest_request_items_locale` WHERE `ID` = 6 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (6, 'esES', '¿Has encontrado la choza de Garrick? ¿Has acabado con él?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 6 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (6, 'esES', '¡Lo has conseguido! Elwynn te estará muy agradecido por esto. ¡Acabas de ganarte una hermosa recompensa!', 0);

-- 54 Informa en Villadorada
-- https://es.wowhead.com/quest=54
DELETE FROM `quest_request_items_locale` WHERE `ID` = 54 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (54, 'esES', '¿Traes noticias de McBride? Villanorte es un jardín comparada con el Bosque de Elwynn; me pregunto qué querrá McBride.$B$BDame los documentos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 54 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (54, 'esES', 'Dice que te han nombrado ayudante del alguacil de Ventormenta. Enhorabuena.$B$BY buena suerte, el trabajo no será fácil ahora que el ejército parece que anda ocupado con la nobleza.$B$BQué misteriosa es la política en estos tiempos difíciles...', 0);

-- 2158 Descanso y relajación
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Descanso_y_relajaci%C3%B3n
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 2158 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (2158, 'esES', '¡Descanso y relax para quien no puede más! ¡Ese es nuestro lema! Por favor, toma asiento cerca del fuego y da un respiro a tus cansados huesos.$B$B¿Te gustaría probar una selección de nuestra excelente comida y bebida? ', 0);

-- 62 La Mina Abisal
-- https://wow-es.gamepedia.com/Misi%C3%B3n:La_Mina_Abisal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 62 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (62, 'esES', '¿Qué tienes que informar, $n? ¿Has estado en la Mina Abisal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 62 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (62, 'esES', 'Esta es una mala noticia. ¿Qué será lo siguiente, dragones? Vamos a tener que aumentar nuestras patrullas cerca de la mina. Gracias por tu trabajo, $n. Y mantente al tanto... Podría tener otra tarea para ti.', 0);

-- 47 Intercambio de polvo de oro
-- https://es.wowhead.com/quest=47
-- https://wow-es.gamepedia.com/Misión:Intercambio_de_polvo_de_oro
DELETE FROM `quest_request_items_locale` WHERE `ID` = 47 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (47, 'esES', '¡Psst! ¿Tienes ese Polvo de Oro para mí... para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 47 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (47, 'esES', 'Gracias por el Polvo de oro, $n. Aquí tienes tu dinero y... este detalle de mis socios. Puede que lo encuentres útil... útil. ', 0);

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

-- 35 Más preocupaciones
-- https://es.wowhead.com/quest=35
-- https://wow-es.gamepedia.com/Misión:Más preocupaciones
SET @ID := 35;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, los múrlocs se han asentado a lo largo de los ríos del este de Elwynn. No sabemos por qué están ahí, pero son agresivos y, además, ¡son hasta un poco inteligentes!', 0);

-- 52 Proteger la frontera
-- https://es.wowhead.com/quest=52
-- https://wow-es.gamepedia.com/Misión:Proteger la frontera
SET @ID := 52;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has matado a esos lobos y a los osos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por tu ayuda, $n. Debe de haber algo en el bosque que está agitando a esos animales.$B$BSea lo que sea, espero que no salga de allí.', 0);

-- 37 Encuentra a los guardias perdidos
-- https://es.wowhead.com/quest=37
-- https://wow-es.gamepedia.com/Misión:Encuentra a los guardias perdidos
SET @ID := 37;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Aunque el cuerpo ha sido saqueado, cerca de él hay un medallón que nadie ha recogido. Tiene una inscripción: "Lacayo Malakai Roca".', 0);

-- 45 Descubre el destino de Rolf
-- https://es.wowhead.com/quest=45
-- https://wow-es.gamepedia.com/Misión:Descubre el destino de Rolf
SET @ID := 45;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Alrededor del cuello del cadáver hay un medallón de metal con una inscripción que reza: "Lacayo Rolf Hartford".', 0);

-- 39 Entrega el informe de Thomas
-- https://es.classic.wowhead.com/quest=39
SET @ID := 39;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm, son noticias preocupantes. Nuestras defensas ya están bastante mermadas y, ahora que hemos perdido a Rolf y Malakai a manos de esos murlocs, estamos incluso peor.$B$BSi las cosas no mejoran, para el final de la semana habrá un combate en Villadorada.', 0);

-- 59 Armadura de paño y cuero
-- https://es.wowhead.com/quest=59
-- https://wow-es.gamepedia.com/Misión:Armadura de paño y cuero
SET @ID := 59;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El ejército de Ventormenta me ha encargado que suministre a sus tropas tela y armaduras de cuero.$B$BSi tienes un marcador para mí, estaré encantada de hacerte algo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, gracias por el marcador. Por favor, elige la armadura que quieras.$B$BBuena suerte, valiente $c. Espero que esta armadura te sirva bien.', 0);

-- 1097 La tarea de Elmore
-- https://es.wowhead.com/quest=1097
-- https://wow-es.gamepedia.com/Misión:La tarea de Elmore
SET @ID := 1097;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Estás aquí para ayudar con la entrega? ¡Estupendo!', 0);

-- 239 El Cuartel de Arroyoeste necesita ayuda
-- https://es.wowhead.com/quest=239
-- https://wow-es.gamepedia.com/Misión:El Cuartel de Arroyoeste necesita ayuda
SET @ID := 239;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Te envía el alguacil Dughan, ¿eh? No eres del ejército, pero bueno, si te manda Dughan, me basta como referencia.$B$BNuestra situación es, como mínimo, apurada. Espero que puedas echarnos una mano.', 0);

-- 11 Recompensas por los gnolls Zarparrío
-- https://es.wowhead.com/quest=11
-- https://wow-es.gamepedia.com/Misión:Recompensas por los gnolls Zarparrío
SET @ID := 11;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Saludos, $n. ¿Has estado matando gnolls...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Has estado muy ocupado! Muchas gracias, $n.', 0);

-- 176 Se busca: Hogger
-- https://es.wowhead.com/quest=176
-- https://wow-es.gamepedia.com/Misión:Se busca: Hogger
SET @ID := 176;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, Hogger ha sido un auténtico estorbo para mí y para mis hombres. ¿Tines algo de que informar sobre la bestia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que ha hecho QUÉ?$B$BGenial, ahora tenemos una bestia sanguinaria justo bajo las calles de Ventormenta con todo un ejército de gnolls a su disposición. Qué gran mejora, ya me siento más seguro.$B$BAquí tienes tu recompensa, $n, pero prométeme que irás a ver a los guardias de las Mazmorras en algún momento para asegurarte de que todo va bien.', 0);

-- 176 Se busca: Hogger
-- https://es.classic.wowhead.com/quest=176
SET @ID := 176;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, Hogger ha sido un auténtico estorbo para mí y para mis hombres. ¿Tines algo de que informar sobre la bestia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ja! ¡Muy bien! ¡Empezaba a creer que nadie conseguiría abatir a ese monstruo!$B$BAquí tienes, $n. Y gracias, ese gnoll era un dolor de cabeza tan monumental como la Cumbre de Roca Negra!', 0);

-- 46 Recompensas por los múrlocs
-- https://es.wowhead.com/quest=46
-- https://wow-es.gamepedia.com/Misión:Recompensas por los múrlocs
SET @ID := 46;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo va la caza, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes las aletas? ¡Genial! El alguacil Dughan está ansioso por recibir noticias del estado de la situación en Elwynn y me gustaría decirle que empezamos a controlar la situación.$B$BTus acciones han contribuido a que sea posible.', 0);

-- 83 Pañuelos de lino rojo
-- https://es.wowhead.com/quest=83
-- https://wow-es.gamepedia.com/Misión:Pañuelos de lino rojo
SET @ID := 83;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me estoy quedando sin lino, $n. ¿No tendrás tú algo de lino que me puedas dar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, qué pañuelos tan estupendos... son un poco ásperos, pero...$B$B¡Ten!', 0);

-- 5545 El cumplimiento del plazo
-- https://es.wowhead.com/quest=5545
-- https://wow-es.gamepedia.com/Misión:El cumplimiento del plazo
SET @ID := 5545;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ese plazo se acerca cada vez más, $c. Te lo ruego, date prisa en recoger la madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Fantástico! Gracias a ti, debería poder cumplir con el plazo. Quisiera demostrarte mi agradecimiento dándote algunas monedas.$B$BGracias y adiós.', 0);

-- 109 Habla con Gryan Mantorrecio
-- https://es.classic.wowhead.com/quest=109
SET @ID := 109;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que te ha enviado aquí mi amigo, ¿eh? Qué amable por su parte.$B$BBien, te diré que la monarquía de Ventormenta nos ha abandonado. Ahora son Las Milicias del Pueblo las que mantienen la tierra a salvo de la corrupción. Si nuestra causa te interesa, puedo ofrecer a tus habilidades de combate un trabajo al servicio de la libertad.', 0);

-- 64 La reliquia olvidada
-- https://es.classic.wowhead.com/quest=64
SET @ID := 64;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Por casualidad, ¿no conseguirías encontrar mi reloj, verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Mi reloj! ¡Muchas gracias, amable señor!$B$BSolo somos unos pobres granjeros y hemos perdido nuestras tierras, pero, por favor, acepta esta recompensa como una muestra de nuestro aprecio.', 0);

-- 151 La pobre y vieja Blanchy
-- https://es.classic.wowhead.com/quest=151
SET @ID := 151;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'La Vieja Blanchy está en las últimas. ¿Has podido encontrar algo de avena?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Muchísimas gracias, $n! ¡La pobre Vieja Blanchy se pondrá tan contenta!', 0);

-- 36 Estofado de los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=36
SET @ID := 36;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Voy a echar mucho de menos a Verna Furlbrow. ¿No la verías por casualidad cuando estuviste por ahí, verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esa Verna siempre fue una muchacha encantadora. La echaré de menos en los Páramos de Poniente pero, entre tú y yo, es una chica de ciudad y en Ventormenta estará muy a gusto. ¡Pero basta de chácharas! ¡Tenemos que hacer el estofado de los Páramos de Poniente!', 0);

-- 9 Campos de la muerte
-- https://es.classic.wowhead.com/quest=9
SET @ID := 9;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ya veo que has vuelto! Espero que hayas trabajado duro limpiando esos campos de esos vigias de la cosecha. ¿Ya mataste a veinte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo amigo. Te has ganado bien tu sueldo. Quién sabe, quizás los Páramos de Poniente vuelvan a ser prósperos.', 0);

-- 22 Pastel de hígado de dentosangre
-- https://es.classic.wowhead.com/quest=22
SET @ID := 22;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Todo lo que necesito para mi famosa empanada de carne son 8 hígados de dentosangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Son perfectos, $n! Muchas gracias. El granjero Saldean y yo vamos a darnos un gran festín. Toma, esto es para ti, por todo el trabajo. No pensarías que iba a dejar que un $c como tú se fuera con hambre, ¿eh?', 0);

-- 38 Estofado de los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=38
SET @ID := 38;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Vuelve con estos ingredientes:$B$B 3 piezas de carne fibrosa de buitre$B 3 morros de dentosangre$B 3 ojos de múrloc$B 3 okras', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Esa okra servirá para dar algo de consistencia al caldo, perfecto! Ahora solo nos falta por añadir carne fibrosa de buitre, unos cuantos ojos de múrloc y esos deliciosos morros de dentosangre... ¡y ya estará listo! Por toda tu ayuda, $n, ¡quiero que te lleves el primer lote de estofado de los Páramos de Poniente!', 0);

-- 109 Habla con Gryan Mantorrecio
-- https://es.classic.wowhead.com/quest=109
SET @ID := 109;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que te ha enviado aquí mi amigo, ¿eh? Qué amable por su parte.$B$BBien, te diré que la monarquía de Ventormenta nos ha abandonado. Ahora son Las Milicias del Pueblo las que mantienen la tierra a salvo de la corrupción. Si nuestra causa te interesa, puedo ofrecer a tus habilidades de combate un trabajo al servicio de la libertad.', 0);

-- 2998 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=2998
SET @ID := 2998;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Es hermoso estar en Ventormenta, ¿no?$B$BEl momento no podría haber sido mejor, $n.', 0);

-- 1643 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1643
SET @ID := 1643;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Oh, hola amor. ¿Cómo van tus aventuras? Me alegra saber que te va bien.$B$BOh, ¿yo? Gracias por preguntar, estoy bien, considerando todas las cosas.$B$BEl aumento de comerciantes ha disminuido la cantidad de cuero y tela de la que las personas están dispuestas a desprenderse en estos días, por lo que ha sido más difícil hacer ropa para los niños en el orfanato, pero nos las arreglaremos. Por "nosotros" me refiero a mi esposo y a mí. Está en Ironforge tratando de buscar ayuda de los ciudadanos allí.', 0);

-- 1644 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1644
SET @ID := 1644;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Espero que mi John esté teniendo más suerte en Forjaz. No le gusta ir allí porque tiene que dejarnos a mí y a los niños solos, pero sabe que tiene que hacerse. Es tan bueno...$B$BAlgunos años han sido más difíciles que otros, pero este desde luego, ha sido el más duro de todos. Parece que haya algo en el aire que anuncia un gran cambio. Pero... ¿quién sabe?', 0);

DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Muchas gracias, $n! ¡Muchas, muchas gracias!$B$BLos niños estarán felices, de verdad. ¡Y a mí me has ahorrado tanto tiempo! Ahora podré concentrarme en las otras necesidades de los niños. Y, con suerte, mi John podrá volver a casa antes de lo que pensábamos.$B$BGracias de nuevo, $n. Sabía que podía contar con la caridad de los demás. Que la Luz sea contigo.', 0);

-- 153 Pañuelos rojos de cuero
-- https://es.classic.wowhead.com/quest=153
SET @ID := 153;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 15 pañuelos de cuero rojo y te pagaré bien.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo, $r. Por favor, acepta uno de estos objetos como pago por tu trabajo.', 0);

-- 12 La Milicia Popular
-- https://es.classic.wowhead.com/quest=12
SET @ID := 12;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Quizás no me he explicado bien. Para demostrar que mereces servir a las Milicias del Pueblo y a la Luz, tienes que matar a 15 tramperos Defias y a 15 contrabandistas Defias. Vuelve aquí cuando lo hayas hecho.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Mi explorador ha sido testigo de tus hazañas. Estás dando muy buenas pruebas de tu valía.', 0);

-- 102 En patrulla por los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=102
SET @ID := 102;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ya has reunido 8 zarpas de esos gnolls traidores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Contando con valientes aventureros como tú luchando del lado de Las Milicias del Pueblo, los Páramos de Poniente podrán volver a ser el próspero granero que una vez fueron. Por favor, acepta esto como reconocimiento por tus incansables esfuerzos.', 0);

-- 6181 Mensajero a toda prisa
-- https://es.classic.wowhead.com/quest=6181
SET @ID := 6181;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Parece que tienes prisa. ¡Entonces has venido al lugar adecuado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes que llevar esta nota a Ventormenta! Ningún problema, ¡puedes coger uno de mis grifos!', 0);

-- 6281 Prosigue hasta Ventormenta
-- https://es.classic.wowhead.com/quest=6281
SET @ID := 6281;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has estado viajando, ¿eh? ¿Has estado en algún sitio interesante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ¿una nota del intendente Lewis? No me sorprende que necesite más equipo. La Colina del Centinela está bastante lejos, en una tierra casi olvidada por Ventormenta.$B$BMuchas gracias, $n. Toma algo de dinero para cubrir los gastos del viaje.', 0);

-- 6261 Dungar Tragolargo
-- https://es.classic.wowhead.com/quest=6261
SET @ID := 6261;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Eso que tienes sobre la frente es sudor, $gmuchacho:muchacha;? Has tenido que correr mucho. ¡La próxima vez coge un grifo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Un cajón para los Páramos de Poniente, eh? ¿Has estado ya allí antes? Si es así no hay ningún problema, amigo. ¡Tengo muchos grifos entrenados para recorrer esa ruta!', 0);

-- 6285 Regresa junto a Lewis
-- https://es.classic.wowhead.com/quest=6285
SET @ID := 6285;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ya has vuelto de Ventormenta? ¿Ha enviado Osric la armadura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Genial, ¡has traído la armadura! Repartiremos esto entre quien lo necesite.$B$BGracias, $n. Tus esfuerzos nos han sido de gran ayuda. Y ahora que ya estás familiarizado con los grifos, ¡espero que vuelvas a menudo y prestes tu ayuda a la Colina del Centinela!', 0);

-- 13 La Milicia Popular
-- https://es.classic.wowhead.com/quest=13
SET @ID := 13;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'No tenemos tiempo para hablar, $n. Los saqueadores de Defias están negando a la gente de Páramos de Poniente la paz y la prosperidad que se merecen. Asegúrese de que al menos 15 saqueadores Defias y 15 despojadores Defias hayan sido asesinados. Eso enviará un mensaje claro de que la corrupción no es bienvenida aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hasta ahora tus hazañas no han dejado de probar tu valía para las Milicias del Pueblo.', 0);

-- 65 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=65
SET @ID := 65;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Así que vienes de parte de Mantorrecio? Bien, estoy en deuda con él.', 0);

-- 14 La Milicia Popular
-- https://es.classic.wowhead.com/quest=14
SET @ID := 14;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, ahora no hay tiempo para charlas. Si aún deseas demostrar tu valía ante la Milicia Popular, debes matar a los Defias que te indiqué anteriormente. Vuelve a mí cuando hayas completado tu deber.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Cuando dejé las tierras malditas de Lordaeron, regresé para encontrar mi patria sumida en una situación desalentadora. Pero aún hay esperanza para los Páramos de Poniente. Has demostrado tu valor en la batalla, y es evidente que sirves con honor a nuestra causa. Me es por ello un gran honor ordenarte como miembro de Las Milicias del Pueblo. Que la Luz guíe siempre tu camino.', 0);

-- 1780 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1780
SET @ID := 1780;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Qué pronto has vuelto, $n. ¿Y qué has conseguido en este tiempo que no has estado en la Catedral?$B$B¿Has conseguido ayudar en alguna noble causa? Quizás hayas aprendido el valor de la caridad o algo más sobre tus obligaciones para con los habitantes de Azeroth. Dime a quién has ayudado y cómo... Vaya, estoy impresionado, $n, las tuyas son sin duda acciones de alguien que sigue el camino de la Luz y antepone el bien de los demás al propio.$B$BTu sacrificio se verá recompensado con el tiempo.', 0);

-- 1781 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1781
SET @ID := 1781;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '*tose*$B$BEs un placer conocerte, $r. No prestes atención a mis heridas. Este buen sacerdote se ocupará del viejo Gazin. No necesitaré el poder de ese Símbolo de la Vida que has traído... al menos, no todavía.$B$BAsí que te envía Duthorian, ¿eh? Muy bien. Te diré exactamente lo que nos ocurrió a mí y a mi amigo Henze. Y, con un poco de suerte y algo de habilidad por tu parte, quizás puedas ayudarnos a todos.', 0);

-- 1786 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1786
SET @ID := 1786;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, $ghermano:hermana;.$B$BVeo que portas el Símbolo de la Vida, ¿puedo deducir de eso que te envían Duthorian o Gazin?$B$BCaí ante los hechizos de los Defias cuando Gazin y yo intentábamos hacernos con sus planes. Conseguí aguantar el tiempo suficiente para que Gazin escapara, pero al final, su magia me superó.$B$BY entonces llegaste tú y me trajiste de nuevo a la vida. La habilidad de utilizar el Símbolo no la tiene cualquiera, $n. Debes apreciar lo que significa que pudieras utilizarlo con ayuda de tu fe.', 0);

-- 1787 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1787
SET @ID := 1787;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Henze está a salvo, $n? ¿Tuviste éxito?$B$BEntre tu habilidad con las armas y el poder de la Luz, creo que la Vigilia de los Héroes estará a salvo de cualquier amenaza de los Defias, pero eso deben decirlo el Rey y sus consejeros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Estupendo! Lo has conseguido, has salvado a Henze. ¡Es evidente que la Luz está en ti, $n!', 0);

-- 1788 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1788
SET @ID := 1788;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has actuado bien, $n. Deberías enorgullecerte de lo que has conseguido.$B$BDeberías estar $gorgulloso:orgullosa; de tus habilidades. No todo el mundo puede utilizar el poder del Símbolo de la Vida. Si puedes invocar a la Luz para devolver a los muertos a la vida, es que estás $gpreparado:preparada; para uno de los mayores honores de los paladines: el poder de resucitar.$B$BPodrás devolver a la vida a compañeros caídos, tal y como hiciste con Henze.$B$BCuídate, $n. La Luz te ilumina. Recíbela en ti.', 0);

-- 399 Principios humildes
-- https://es.classic.wowhead.com/quest=399
SET @ID := 399;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡$n! ¿Has tenido suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, muchas gracias, $n! No me sirve de nada, pero el valor sentimental... No hace falta que te dé las gracias por traerme esto... y veo que has tenido que sufrir algún que otro percance para conseguirlo, sin mencionar el tiempo que has perdido yendo a Páramos de Poniente. Tienes mi gratitud. Acepta esto como muestra de ello.', 0);

-- 353 Una entrega a Pico Tormenta
-- https://es.wowhead.com/quest=353
-- https://wow-es.gamepedia.com/Misión:Una entrega a Pico Tormenta
SET @ID := 353;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has venido hasta aquí desde Ventormenta? He oído que las cosas se están poniendo feas en las tierras humanas, con forajidos y orcos campando a sus anchas. ¡Un lugar perfecto para que un $c demuestre su valía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ajá! ¿Así que Grimand ha terminado mi hacha por fin? ¡Me muero por probarla con algunos troggs y kóbolds!$B$BMuchas gracias, $n. Has hecho un largo viaje para entregármela. Acepta unas monedas por tu trabajo.', 0);

-- 6661 A por las ratas del tranvía subterráneo
-- https://es.wowhead.com/quest=6661
SET @ID := 6661;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Eeeh... pillastre, ¿por qué tardas tanto tiempo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto va bien, $gamigo:amiga;. Mi hermano las necesita vivitas y coleando, de lo contrario se ponen amargas ... No querrás probar ninguna brocheta de rata agria.', 0);

-- 6662 Mi hermano Niblis
-- https://es.wowhead.com/quest=6662
-- https://wow-es.gamepedia.com/Misión:Mi hermano Niblis
SET @ID := 6662;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Nipsy pone su dedo índice a través de uno de los agujeros de aire en el cartón.>$B$BVivo y coleando... ¡y justo a tiempo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Pobre Monty. Desde el incidente de Gnomeregan, no ha sido el mismo. Ese niño nunca ha visto un océano en su vida, y mucho menos ser una especie de pirata.$B$B<Nipsy suspira.>$B$BAl menos mantiene el flujo de las criaturas retorciéndose.', 0);

-- 117 Cerveza Cebatruenos
-- https://es.classic.wowhead.com/quest=117
SET @ID := 117;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Rápido, $gamigo:amiga; y date prisa$BNuestra cerveza está de risa$BMás cerveza y menos comida,$BDadnos lúpulo para hacer birra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Lúpulo y cebada, malta y levadura$BNi te imaginas cómo se disfruta,$B$BDeja de pedir, deja de gemir$B¡La cerveza Cebatruenos ya viene en su barril!', 0);

-- 103 Guardián de la Llama
-- https://es.classic.wowhead.com/quest=103
SET @ID := 103;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'La llama no arderá mucho tiempo sin aceite, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Loado seas, valiente $c. Las rocas de la Costa de los Páramos de Poniente estarán iluminadas gracias a ti. Mientras la antorcha esté iluminada se salvarán muchas vidas.', 0);

-- 104 La amenaza costera
-- https://es.classic.wowhead.com/quest=104
SET @ID := 104;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Aún no has conseguido aniquilar a la amenaza conocida como Viejo Ojosombrío? Ha sido visto recorriendo la costa de los Páramos de Poniente.$B$BVuelve a verme cuando esa bestia esté muerta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que el infecto pagano Ojosombrío está muerto. Bien hecho, $n. Tus manos han dado fin a una vida, pero han podido salvar muchas otras. El Mare Magnum, aun tan lleno de peligros como está, será algo más seguro esta noche gracias a tus hazañas.', 0);

-- 152 Hay moros en la costa
-- https://es.classic.wowhead.com/quest=152
SET @ID := 152;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mata 7 cazamareas, 7 guerreros, 7 oráculos y 7 correcostas y procuraré que seas $grecompensado:recompensada;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Tienes talento para el combate. Gracias a ti, la Costa de los Páramos de Poniente es un lugar más seguro.', 0);

-- 244 Gnolls invasores
-- https://es.classic.wowhead.com/quest=244
SET @ID := 244;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Hay gnolls de Crestagrana tan cerca de Elwynn? Puede que planeen una invasión... ¡Los de Villa del Lago ya no serán los únicos humanos bajo asedio!$B$BAquí tienes el pago, pese a las noticias que traes. Y en qué mal momento: carecemos de recursos.', 0);

-- 246 Evaluar la amenaza
-- https://es.classic.wowhead.com/quest=246
SET @ID := 246;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Disculpe, $n, pero tenemos mucho que hacer como para mantener nuestras manos atadas aquí. Si no tiene nada que informar, entonces debo ocuparme de otros asuntos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<El ayudante del alguacil Feldon escucha tu informe...>$B$BAsí que hay un grupo numeroso de gnolls de los duros. Seguro que no te ha sido fácil recopilar esta información.$B$BTen, $n, y gracias por tu ayuda.$B$BHabla con el alguacil Marris y el magistrado Salomón en Villa del Lago. Necesitarán tu ayuda; la situación empeora por momentos.', 0);

-- 129 Una comida gratis
-- https://es.classic.wowhead.com/quest=129
SET @ID := 129;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que Darcy me envía la comida? Pues venga, ¡a mover el bigote!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, me muero de hambre. ¡Proteger la ciudad de los orcos y los gnolls es un trabajo duro!', 0);

-- 14079 Aprende a montar en el Bosque de Elwynn
-- https://es.wowhead.com/quest=14079
SET @ID := 14079;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ¿recibiste mi carta? Bien.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Entonces, ¿comenzaremos tu entrenamiento de Aprendiz de Jinete?', 0);

-- 130 Una visita al herborista
-- https://es.classic.wowhead.com/quest=130
SET @ID := 130;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Un ramo de flores? ¿Acabas de llegar y ya estás con romances?$B$BNo es por chafardear, pero los amores juveniles son tan bonitos... sobre todo en tiempos de guerra.', 0);

-- 131 Un ramo de narcisos
-- https://es.classic.wowhead.com/quest=131
SET @ID := 131;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Le gustó la comida a Parker?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Qué bonitas! ¡Y qué bien huelen!$B$BPero son las flores favoritas de Martie. ¿No me digas que Parker te mandó a comprarle las flores a esa bruja? No le dijiste que eran para mí, ¿verdad? Porque si lo sabía, seguro que puso veneno.$B$BEn fin, no es culpa tuya. Gracias, y aquí tienes la comida.', 0);

-- 3741 El collar de Hilary
-- https://es.classic.wowhead.com/quest=3741
SET @ID := 3741;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, ¿has encontrado mi collar? Papá dice que hay monstruos en el lago; ¿has visto alguno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por encontrar mi collar, $gseñor:señora; $c... Mi gatita también dice gracias, ¿a que sí, Effsee?', 0);

-- 125 Las herramientas perdidas
-- https://es.classic.wowhead.com/quest=125
SET @ID := 125;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Me traes las herramientas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Excelente trabajo, $n. Pensé que no volvería a ver mis herramientas.', 0);

-- 150 Cazadores furtivos
-- https://es.classic.wowhead.com/quest=150
SET @ID := 150;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes las aletas? ¡Tenemos que echar a los múrlocs del lago!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo, $n.$B$BEs raro que estén tan lejos del mar; puede que estuvieran huyendo de algo...', 0);

-- 127 Pescado a la venta
-- https://es.classic.wowhead.com/quest=127
SET @ID := 127;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ha sido un placer!', 0);

-- 89 El puente sempiterno
-- https://es.classic.wowhead.com/quest=89
SET @ID := 89;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡El puente no va a construirse solo! ¿Dónde están las picas y los remaches?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo, $n. Con esto podemos ir avanzando los trabajos del puente.', 0);

-- 92 Estofado Crestagrana
-- https://es.classic.wowhead.com/quest=92
SET @ID := 92;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 5 filetes de carne dura de cóndor, 5 morros de dentosangre grandes y 5 raciones de carne de araña crujiente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Muchas gracias, $n. Aquí tienes el delicioso estofado de Crestagrana prometido.', 0);

-- 34 Una visita poco grata
-- https://es.classic.wowhead.com/quest=34
SET @ID := 34;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has acabado ya con Panzallena?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Por fin! Gracias, $n, me has hecho un favor enorme. ¡Este año el jardín estará precioso!', 0);

-- 20 La amenaza de los Roca Negra
-- https://es.classic.wowhead.com/quest=20
SET @ID := 20;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has estado liquidando orcos, $n? Demuéstramelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ahora hay muchos menos orcos de los que ocuparse; gracias.', 0);

-- 128 La recompensa de Roca Negra
-- https://es.classic.wowhead.com/quest=128
SET @ID := 128;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Regresa una vez que hayas matado a 15 campeones de Roca Negra', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has mostrado gran valor frente a los Roca Negra, $c. Nos has prestado un gran servicio.', 0);

-- 115 Magia de las Sombras
-- https://es.classic.wowhead.com/quest=115
SET @ID := 115;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo va con los taumaturgos umbríos? ¿Tienes los orbes de medianoche?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, $n. Acabaré con ellos de inmediato.', 0);

-- 169 Se busca: Gath'Ilzogg
-- https://es.classic.wowhead.com/quest=169
SET @ID := 169;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué llevas ahí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Buen trabajo, $n! Gath\'Ilzogg es responsable de la muerte de muchos humanos. Nos hemos vengado. ¡Estamos un paso más cerca de reconquistar el castillo!', 0);

-- 386 Lo que sucede alrededor...
-- https://es.classic.wowhead.com/quest=386
SET @ID := 386;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ya has estado en las Mazmorras de Ventormenta? Temo que el poder que ha mantenido a Targor con vida acabe por conseguir liberarlo. Fue sentenciado a muerte, no a ser un títere político.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Targor el Pavoroso ha caído al fin. Me alegro. Buen trabajo, $n. A veces solo se puede hacer justicia al margen de los tribunales y los políticos.', 0);
-- 120 Mensajero a Ventormenta
-- https://es.classic.wowhead.com/quest=120
SET @ID := 120;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué llevas ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Descansa, $c.$B$BEl magistrado Solomon es un líder de los nobles; siempre atiendo a sus palabras. Voy a reunirme con el Rey para exponerle la situación. Dile al magistrado que enviaremos refuerzos en cuanto Su Majestad dé la orden.', 0);
-- 121 Mensajero a Ventormenta
-- https://es.classic.wowhead.com/quest=121
SET @ID := 121;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué noticias envía el General? ¿Vienen refuerzos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por todo, $c. Acepta estas monedas por tus servicios a Villa del Lago y Ventormenta.$B$BY ahora disculpa, pero esta correspondencia me intriga; está pasando algo turbio. Temo que se avecine otro conflicto.', 0);
-- 116 Tiempos de sequía
-- https://es.classic.wowhead.com/quest=116
SET @ID := 116;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito que vayas a recoger un barril de cerveza Cebatruenos de Tragoamargo Cebatruenos, que está en las colinas de Páramos de Poniente, uno de vino dulce en Ventormenta, una botella de licor de luna en Villa Oscura y una de ron dulce en Villadorada. Tráeme todo eso y te ganarás una recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Buen trabajo, $n! Sé qué caminos has tenido que recorrer para traer este licor. ¡Esto complacerá a mis patronos!$B$BMi esposa cose muy bien; acepta esta capa en agradecimiento por tus servicios.', 0);
-- 118 El precio de unas herraduras
-- https://es.classic.wowhead.com/quest=118
SET @ID := 118;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué dices? ¿Que vienes de parte de Verner? Pues dame la nota. ¡Y habla más alto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que necesita herraduras, ¿eh?', 0);
-- 132 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=132
SET @ID := 132;
UPDATE `quest_template_locale` SET `Title` = 'La hermandad de los Defias' WHERE `ID` = @ID AND locale = 'esES';
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me alegro de verte de vuelta, $n. ¿Qué tenía que decir Wiley?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Bah! Debería haber acabado con esa escoria cuando tuve oportunidad de hacerlo. Pero esta información es crucial. Buen trabajo.', 0);
-- 135 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=135
SET @ID := 135;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué asuntos tienes conmigo? Soy un hombre muy ocupado...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Creo que este asunto es mucho más complicado de lo que cree Mantorrecio.', 0);
-- 141 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=141
SET @ID := 141;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ha conseguido aclarar algo el maestro Shaw?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Edwin VanCleef... conozco muy bien ese nombre. Me desconcierta pensar que un hombre con tanto talento y tan trabajador pudiera convertirse en tal escoria. Necesitaré más pruebas antes de creerlo.', 0);
-- 388 El color de la sangre
-- https://es.classic.wowhead.com/quest=388
SET @ID := 388;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Veo que has vuelto, $c. ¿Has conseguido 10 pañuelos de lana roja de esa escoria Defias de las Mazmorras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Y estos pañuelos, símbolos asquerosos de corrupción, son por lo que mi Mac tuvo que morir? Qué gran pérdida. Qué trágico sacrificio.$B$BPero en fin, no puedo vivir en el pasado. Has de saber, $n, que tus actos han conseguido que se haga justicia con mi familia.', 0);
-- 142 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=142
SET @ID := 142;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, ¿pudiste reunir alguna información? ¿Localizaste al mensajero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto es sin duda alguna una prueba clara de que VanCleef está al mando. Ahora todo lo que tenemos que saber es dónde se oculta la banda Defias.$B$BTuvimos un golpe de suerte mientras estabas fuera. Capturamos a un ladrón que intentaba robar el carro de Saldean. Ha prometido guiarnos hasta la ladronera a cambio de su vida. Quiero que defiendas al traidor para que pueda enseñarnos la ladronera. Vuelve a verme cuando hayas descubierto su localización.', 0);
-- 155 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=155
SET @ID := 155;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué negocio tienes conmigo? Soy un hombre muy ocupado...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Excelente, $n! Ahora que sabemos dónde se oculta, VanCleef ya es nuestro.', 0);
-- 166 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=166
SET @ID := 166;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué tal va la caza y captura de Edwin Van Cleef?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, tu valentía es extraordinaria. Las Milicias del Pueblo te agradecen los servicios prestados a las gentes de los Páramos de Poniente. Ahora que VanCleef ha muerto, estamos ante el comienzo del fin de la Hermandad Defias. Esperemos que en un día no muy lejano la paz volverá a bendecir los llanos de estas tierras.', 0);
-- 119 Regresa junto a Verner
-- https://es.classic.wowhead.com/quest=119
SET @ID := 119;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Me alegro de verte! ¿Traes las herraduras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, me hacía mucha falta.$B$BAh, hay una nota... ¿Cómo? ¡¿Argus quiere que le pague?! ¡Bah!$B$BBueno, gracias por tu ayuda.', 0);
-- 143 Mensajero a los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=143
SET @ID := 143;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Saludos, $c. ¿Qué te trae a hablar con Las Milicias del Pueblo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has servido bien a tu maestro.', 0);
-- 214 Pañuelos rojos de seda
-- https://es.classic.wowhead.com/quest=214
SET @ID := 214;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has estado defendiendo nuestra tierra de la banda Defias? Si es así enséñame 10 pañuelos de seda roja como prueba.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Bien hecho, $n! En nombre de Las Milicias del Pueblo te rindo homenaje por todos tus esfuerzos. Pronto, y gracias a la ayuda de valientes como tú, devolveremos esta tierra a su pueblo.', 0);
-- 144 Mensajero a los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=144
SET @ID := 144;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Están Las Milicias del Pueblo en camino? ¿Traes buenas noticias de Gryan Mantorrecio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto no es nada bueno. No me había dado cuenta de que Mantorrecio está igual que nosotros. ¿Qué campaña es tan importante como para enviar al ejército de Ventormenta lejos de su gente? Lo sabré a su debido tiempo.$B$BTen, acepta estas monedas en pago por tus servicios Puede que vuelva a contratarte.', 0);
-- 122 Escamas de barriga
-- https://es.classic.wowhead.com/quest=122
SET @ID := 122;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Si no le envío las escamas a Argus, mandará a alguien a buscarlas. ¿Las tienes o no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, con esto pagaré a Argus.', 0);
-- 124 El aullido de los gnolls
-- https://es.classic.wowhead.com/quest=124
SET @ID := 124;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mis caballos todavía parecen asustados, y todavía escucho a ese maldito lobo llorar por la noche. ¡Por favor, $n, haz algo con esos Gnolls!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por tu ayuda, $n.', 0);
-- 126 El aullido de las colinas
-- https://es.classic.wowhead.com/quest=126
SET @ID := 126;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ululante es peligroso, $n. Entenderé que no seas capaz de enfrentarte a él.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias de nuevo. El ejército de Ventormenta está tan ocupado con los orcos que no hay tropas para proteger Crestagrana de otras amenazas, como los gnolls.', 0);
-- 91 Ley de Solomon
-- https://es.classic.wowhead.com/quest=91
SET @ID := 91;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 10 colgantes Pellejo Negro y te recompensaré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El Tribunal de Villa del Lago reconoce tu entrega a la justicia, $n. Gracias por ayudar a mantener la ley y el orden en el Reino.', 0);
-- 19 Tharil'zun
-- https://es.classic.wowhead.com/quest=19
SET @ID := 19;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Los orcos de Roca Negra siguen atacando. ¿Has acabado con Tharil\'zun?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Era fuerte y cruel; seguro que no fue fácil derrotarlo. Gracias; aquí tienes tu recompensa.', 0);
-- 180 Se busca: Teniente Fangore
-- https://es.classic.wowhead.com/quest=180
SET @ID := 180;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué nuevas nos traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Así que el malvado Fangore ha muerto? Pues buen viaje. Admiro tu valor, $c. Tienes la gratitud de Villa del Lago.', 0);
-- 145 Mensajero a Villa Oscura
-- https://es.classic.wowhead.com/quest=145
SET @ID := 145;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Parece que vienes de lejos, $c. ¿Qué te trae a Villa Oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por venir hasta aquí. Esta información es muy importante.', 0);

-- 66 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=66
SET @ID := 66;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, así que te manda Lady Eva...', 0);
-- 101 El Tótem de castigo
-- https://es.classic.wowhead.com/quest=101
SET @ID := 101;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 10 colmillos de necrófago, 10 dedos de esqueleto y 5 frascos de veneno de araña. Así haré un encantamiento a un Tótem de castigo que dañará a aquellos que intenten causarte daño a ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Muy inteligente por tu parte, $n. Este Tótem de castigo te protegerá del mal que acecha por todo Azeroth y más allá. Cuando te sientas amenazado, confórtate con el aura mágica de este tótem. Sé valiente, $c. Necesitarás todo el valor del que puedas hacer acopio, pues veo mucha sangre en tu futuro.', 0);
-- 90 Kebab de lobo sazonado
-- https://es.classic.wowhead.com/quest=90
SET @ID := 90;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has conseguido ya las 10 ijadas magras de lobo? ¿Y qué hay de las hierbas de Felicia de Ventormenta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Buen trabajo, $n! ¡Disfruta esta delicatessen llamada kebab de lobo salpimentado!', 0);
-- 56 La Guardia Nocturna
-- https://es.classic.wowhead.com/quest=56
SET @ID := 56;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has matado a esos guerreros y magos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Espléndido, $n. Serás recompensado por los servicios prestados a la gente de Villa Oscura.', 0);
-- 221 Ferocanis en el bosque
-- https://es.classic.wowhead.com/quest=221
SET @ID := 221;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Vuelves tan pronto, $N? Espero que no hayas venido a decirme que te has rendido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Te has desenvuelto bien contra los Correoscuros, $n. Pero parece que su número es irreducible. Cada vez que hacemos un progreso, llegan más a tomar el relevo.$B$B¿Qué maléfico poder es el que les trae aquí? ¿Por qué han irrumpido de esta manera en nuestro infeliz reino?$B$BTendré fe en el maestro Carevin. Sin duda, él llegará hasta el fondo del asunto.', 0);
-- 57 La Guardia Nocturna
-- https://es.classic.wowhead.com/quest=57
SET @ID := 57;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Vuelve a mí una vez que hayas matado a 15 Malignos esqueléticos y 15 Horrores esqueléticos, $N.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Las gentes de Villa Oscura te dan las gracias, $n. Has demostrado ser un gran aliado de la Guardia Nocturna.', 0);
-- 222 Ferocanis en el bosque
-- https://es.classic.wowhead.com/quest=222
SET @ID := 222;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te intimidaron las bestias? ¡Pero no temas, $N, los que defienden la Luz nunca caerán!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'A decir verdad, $n, no creía que llegarías tan lejos. Pero está claro que me equivoqué contigo. De hecho, si deseas unirte formalmente a la lucha del maestro Carevin, será un placer escribirte una carta de recomendación.', 0);
-- 223 Ferocanis en el bosque
-- https://es.classic.wowhead.com/quest=223
SET @ID := 223;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sí? ¿Qué quieres? Habla deprisa, tengo asuntos urgentes que atender.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Perdona mi frío recibimiento, $n, pero ya te habrás dado cuenta de que soy un hombre muy ocupado. Veo que has impresionado a Calor, cosa que no es en absoluto fácil de conseguir, y veo que te ha dado una recomendación.$B$BHemos de afrontar seres de lo más desagradable, $n, y necesitamos la ayuda de cualquiera que haya demostrado su valía. Combatimos contra demonios, no-muertos y contra aquellos que les proporcionan ayuda. Mantente alerta, sé $gprecavido:precavida; y no confíes en nadie que no colabore con nuestra causa.$B$BGloria bajo la Luz.', 0);
-- 146 Mensajero a Villa Oscura
-- https://es.classic.wowhead.com/quest=146
SET @ID := 146;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me alegro de verte. ¿Debo informar de que La Guardia Nocturna ha salido de Villa Oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Por la Luz! El ejército de Ventormenta se ha retirado de Páramos de Poniente. ¿La Guardia ya no protege Villa Oscura? Aquí hay algo muy siniestro.$B$BAh, quería recompensarte, $c; toma unas monedas. Disculpa, pero tengo que averiguar qué está pasando en Ventormenta.', 0);
-- 174 Mira las estrellas
-- https://es.classic.wowhead.com/quest=174
SET @ID := 174;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has conseguido encontrar a un ingeniero que te haga un tubo de bronce?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Es perfecto, $n. ¡Ya hemos completado el primer paso!', 0);
-- 175 Mira las estrellas
-- https://es.classic.wowhead.com/quest=175
SET @ID := 175;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Pues sí, sí que tenía un espejo.', 0);
-- 177 Mira las estrellas
-- https://es.classic.wowhead.com/quest=177
SET @ID := 177;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Le he enseñado a Cog nuestra máquina de las estrellas. Bueno, lo que hemos hecho hasta ahora. Se quedó muy impresionado. ¿Encontraste el instrumento reflectante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Excelente, excelente! ¡Es perfecto! ¡Muchas gracias!', 0);
-- 181 Mira las estrellas
-- https://es.classic.wowhead.com/quest=181
SET @ID := 181;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Conseguiste convencer a Zzarc\'Vul de que nos preste su monóculo para nuestro experimento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Al fin! ¡Ya hemos completado el instrumento de las estrellas! Gracias, $n. Ya puedo seguir con mis estudios...', 0);
-- 245 Las amenazas de ocho patas
-- https://es.classic.wowhead.com/quest=245
SET @ID := 245;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Será mejor que tengas cuidado cuando trates con las arañas, he perdido a algunos de mis hombres por ellas, y créeme, no es agradable ver a un hombre colgado boca abajo en sus redes después de que el veneno ha comenzado a reblandecerlos.$B$BNo me gustaría que uno de esos bichos te almorzara.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ah! Has vuelto. Y no demasiado agotado, por lo que veo. La Guardia Nocturna está agradecida por tu trabajo, $n, y yo te prometí una recompensa, aquí la tienes.', 0);
-- 163 Cerro del Cuervo
-- https://es.classic.wowhead.com/quest=163
SET @ID := 163;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, $N! ¿De vuelta tan pronto? ¿Sin duda has vuelto a cazar? ¡No se preocupe si ha tenido algunos contratiempos, a la larga mejorará!$B$B... No podrías empeorar mucho, de todos modos ...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡No! ¡Por favor, no me mates! Soy solo yo... ¡¡Alterio!! Están por todas partes... ¡No puedo escapar! ¿Monstruos en Cerro del Cuervo? No, no, no... no puede haber ninguno. Aquí solo está Alterio, el inocente Alterio.', 0);
-- 377 Crimen y castigo
-- https://es.classic.wowhead.com/quest=377
SET @ID := 377;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Cuando se deja vivir a un profanador como Dextren Ward, se traiciona a la justicia. Vuelve a mí cuando se haya cumplido la sentencia de muerte que Lord Ebonlocke dictó contra ese rapiñador de Ward. Vamos a dar a las familias de los muertos la satisfacción que merecen, y además, enviaremos un claro mensaje a la Casa de Nobles de Ventormenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que finalmente, Dextren Ward pagó por sus crímenes contra la humanidad... Eso sí que es hacer limpieza. ¡Y enhorabuena, $gamigo:amiga;! No solo has dado a las familias de los muertos la tranquilidad de espíritu que merecen, además has enviado un contundente mensaje a esos burócratas corruptos de la Casa de Nobles. Ventormenta debe escuchar las necesidades de la gente del Bosque del Ocaso o nos independizaremos y nos liberaremos de su tiranía.', 0);
-- 164 Entrega a Sven
-- https://es.classic.wowhead.com/quest=164
SET @ID := 164;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tienes pinta de ser fuerte, $c. ¿Has venido a unirte a nuestra lucha?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Estos suministros serán muy útiles. La ayuda de la familia Carevin es siempre bienvenida. Aquí tienes un algo por tus molestias.', 0);
-- 58 La Guardia Nocturna
-- https://es.classic.wowhead.com/quest=58
SET @ID := 58;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito tu ayuda, $n. Viaja al cementerio al noroeste y libera el mausoleo oriental de 20 propagadores de peste.$B$BVuelve a verme cuando hayas completado tu tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Te doy las gracias de parte de las gentes de Villa Oscura y de la Guardia Nocturna, $n, por tu valor y dedicación. Que la Luz ilumine tu camino.', 0);
-- 165 El ermitaño
-- https://es.classic.wowhead.com/quest=165
SET @ID := 165;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Elaine Carevin? Je, je, sí, claro... los Carevin.$B$BNo, no pasa nada. Es que ya no puedo ir a la villa, el viaje es demasiado para mí. Los caminos son peligrosos y cada día estoy más viejo. ¿Podrías hacer algunos favores a un pobre viejo?', 0);
-- 226 Con los lobos en los talones
-- https://es.classic.wowhead.com/quest=226
SET @ID := 226;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sigues cazando lobos...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Oh, bien. Has diezmado la manada. Ahora que no tendremos a esos lobos pisándonos los talones, podremos centrarnos en Morbent Vil.$B$BTen, coge algunos de estos manojos destellantes. Los hacen en el pueblo y muchos han sido donados a Sven, para ayudar a su causa.', 0);

-- 67 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=67
SET @ID := 67;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El viejo baúl se abre con un crujido...', 0);
-- 95 La venganza de Sven
-- https://es.classic.wowhead.com/quest=95
SET @ID := 95;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hay un montón de tierra, apilada con prisas, como si alguien se hubiera visto obligado a esconder algo en poco tiempo.', 0);
-- 68 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=68
SET @ID := 68;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me acuerdo de ti... Eres el que estaba preguntando por ese tal Stalvan. ¿Encontraste lo que estabas buscando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Interesante... Así que ese individuo sí que pasó un tiempo en Arroyo de la Luna, después de todo. Resulta extraño que la carta nunca llegara a entregarse. En cualquier caso, voy a actualizar el registro.', 0);
-- 148 Suministros de Villa Oscura
-- https://es.classic.wowhead.com/quest=148
SET @ID := 148;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, necesitas Hilo de pelo de fantasma, ¿no es así? Pues me temo que no tengo ninguno en el almacén, pero puedo hacértelo, si tú me proporcionas el pelo de fantasma.', 0);
-- 149 Hilo de cabello de fantasma
-- https://es.classic.wowhead.com/quest=149
SET @ID := 149;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Snif> Oh, por favor, ¡no me mires! ¡Arranqué estos ojos con mis propias manos, pero puedo sentir tu mirada fija en mí!$B$B¡Soy un monstruo! ¡Un monstruo horrible! ¡¡Por favor, no me mires!!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué es eso? ¿Un peine? ¡Es precioso! Y se desliza como seda por mi cabello, como si no fuera el alambroso y grasiento horror que es.$B$BAy, si tan solo tuviera un espejo...', 0);
-- 5 La hambruna de Alterio
-- https://es.classic.wowhead.com/quest=5
SET @ID := 5;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Un envío de mi hermano? ¡Espléndido! ¡La fortuna realmente me brilla hoy!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesitas croquetas de cangrejo, ¿verdad? Bueno, quizás pueda cocinarte algunas...', 0);
-- 93 Los pasteles de cangrejo oscuro
-- https://es.classic.wowhead.com/quest=93
SET @ID := 93;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Salve, $n. ¿Has conseguido esas patas pegajosas de araña ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Tienes un bonito ramillete de patas ahí! Deja que las condimente con mis especias secretas (¡no mires!) y las saltearé en una sartén...$B$BY, aunque las croquetas de cangrejo son mi especialidad y no te daré nunca la receta, sí te daré la de un plato que es casi igual de bueno.', 0);
-- 240 Regresa junto a Alterio
-- https://es.classic.wowhead.com/quest=240
SET @ID := 240;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, ¡estás aquí! ¡¿Tienes mi comida?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ajá! Gracias, $n. ¡Qué bien sientan estas cosas!$B$B¡Y ten, deja que te pague!', 0);
-- 154 Devuelve el peine
-- https://es.classic.wowhead.com/quest=154
SET @ID := 154;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tengo la sensación de que has visto a Mary la Ciega. ¿Tienes mi peine...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Con esto puedo hacerte un carrete de Hilo de pelo de fantasma y todavía me sobrarían algunas hebras. Ten, acepta estas monedas a cambio de esas hebras.', 0);
-- 157 Devolver el pelo
-- https://es.classic.wowhead.com/quest=157
SET @ID := 157;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito colocar el hilo de cabello de fantasma en mis puertas y ventanas para mantener alejados a esos indeseables espíritus. ¿Me lo conseguiste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Delicioso! Esto funcionará de maravilla.$B$BTen, $n, acepta esto como pago por tu honorable acción.', 0);
-- 158 Zumo de zombi
-- https://es.classic.wowhead.com/quest=158
SET @ID := 158;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesitas un poco de zumo de zombi, ¿verdad? Mmm... es un líquido muy fuerte... no me lo piden muy a menudo.', 0);
-- 230 El campamento de Sven
-- https://es.classic.wowhead.com/quest=230
SET @ID := 230;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que has encontrado qué? Déjame verlo, por favor...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Sven lee las páginas del libro y luego lo cierra de un golpe.>$B$B¡Esa figura misteriosa que vi fue testigo de la muerte de mi familia! Hay preguntas que necesito hacerle a ese hombre... ¡si tan solo supiera quién es!', 0);
-- 262 La figura en las sombras
-- https://es.classic.wowhead.com/quest=262
SET @ID := 262;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Si tienes algo que pertenezca a la figura misteriosa que buscas, enséñamelo. Quizás pueda averiguar algo sobre su dueño.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm... Alguien ha manipulado este libro hace poco... alguien guiado por la venganza. Pero las impresiones que hay en él, al menos las impresiones del dueño original, son débiles.$B$BPero sí puedo decirte que el dueño original de este libro no es oriundo de Villa Oscura.', 0);
-- 69 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=69
SET @ID := 69;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Stalvan? Desde luego, me resulta familiar.', 0);
-- 70 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=70
SET @ID := 70;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué tienes ahí? Deja que le eche un vistazo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo tienes la cara de traer esto aquí?', 0);
-- 333 Harlan necesita un nuevo suministro
-- https://es.wowhead.com/quest=333
SET @ID := 333;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Traes noticias de Bagley?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Dice aquí que el negocio de Harlan está floreciendo. Me alegra oír eso, pero me pregunto por qué la gente necesita tantas armaduras. No he oído nada sobre una declaración de guerra... ¿Acaso los nobles nos están ocultando información?$B$BEn fin, gracias por traer el pedido. Aquí tienes el pago, me encargaré de que Harlan reciba sus suministros.', 0);
-- 334 Un paquete para Thurman
-- https://es.wowhead.com/quest=334
SET @ID := 334;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has venido a comprar ropa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, maldición! Creí que al haberme olvidado las herramientas, no tendría que trabajar. Aunque supongo que ahora tendré que ayudar a los Larson cosiendo...$B$BEn fin... Supongo que tendré que esperar hasta más tarde para divertirme.', 0);
-- 1078 Escamas cristalizadas para Mauren
-- https://es.classic.wowhead.com/quest=1078
SET @ID := 1078;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola otra vez, $n.$B$B¿Ya has regresado de La Vega Carbonizada de Espolón con las escamas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Perfecto, $n. Muchas gracias.$B$BQuizás, algún día yo pueda ayudarte como tú me has ayudado a mí.', 0);
-- 7791, 7792, 7802, 7807, 7813, 7820, 7826, 7833, 10352, 10359 Un donativo de lana
DELETE FROM `quest_request_items_locale` WHERE `ID` IN (7791, 7792, 7802, 7807, 7813, 7820, 7826, 7833, 10352, 10359) AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7791, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7792, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7802, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7807, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7813, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7820, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7826, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7833, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(10352, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(10359, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (7791, 7792, 7802, 7807, 7813, 7820, 7826, 7833, 10352, 10359) AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7791, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7792, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7802, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7807, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7813, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7820, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7826, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7833, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(10352, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(10359, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0);

-- 72 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=72
SET @ID := 72;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Levantas lentamente la tapa de la caja...', 0);
-- 74 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=74
SET @ID := 74;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué tienes ahí? No lo veo. Tengo una vista muy mala. Pónmelo en las manos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Apenas distingo las letras. Pero la caligrafía me recuerda a algo que vi una vez, cuando aún tenía buena vista.', 0);
-- 387 Detener el motín
-- https://es.classic.wowhead.com/quest=387
SET @ID := 387;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡La empalizada todavía está invadida! Estas ratas Defias deben saber que sus acciones no serán toleradas. ¡Ahora baja y muestra algo de fuerza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tus acciones en las Mazmorras fueron muy valientes, $n. Es obvio que este problema nos sobrepasa. Pero lo has hecho muy bien y, por ello, te doy las gracias.', 0);
-- 75 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=75
SET @ID := 75;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado la página de la que te hablé, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡La has encontrado!', 0);
-- 78 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=78
SET @ID := 78;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te envía el mariscal Haggard? ¿Y por qué no lo has dicho antes?$B$BAy, el viejo Haggard... El pobre se quedará ciego dentro de poco. En fin, déjame ver lo que tienes ahí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Por la Luz! Claro que reconozco esa caligrafía.', 0);
-- 265 La búsqueda de la figura continúa
-- https://es.classic.wowhead.com/quest=265
SET @ID := 265;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'A veces vendo libros en blanco a estudiosos y magos, o a cualquiera que quiera escribir un diario.$B$BRecuerdo perfectamente a todos los que me compraron libros en los últimos meses...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, sí. Vendí este libro hace un mes a una persona... algo sombría. No me dio su nombre, pero era un tipo nervioso que no paraba de mirar por encima de su hombro.', 0);
-- 156 Busca flores podridas
-- https://es.classic.wowhead.com/quest=156
SET @ID := 156;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Me has conseguido ya esas flores podridas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien, tienes las flores podridas. Y le diré a Althea Ebonlocke de La Guardia Nocturna que has estado matando esqueletos.$B$BSalvaguardar a las gentes de Villa Oscura es un tremendo peso para La Guardia Nocturna... siempre se alegran de saber que hay otros que ayudan a contener a esas bestias del Bosque del Ocaso.', 0);
-- 159 Entrega de zumo
-- https://es.classic.wowhead.com/quest=159
SET @ID := 159;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito ese zumo de zombi para mantenerme caliente en estas noches frías y oscuras. ¿Me lo conseguiste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Miles de gracias, $n. Has dado una alegría al corazón de este pobre viejo con este gesto estúpid... digo, ¡con este gesto estupendo!', 0);
-- 79 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=79
SET @ID := 79;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Espero que sea importante, $c. Déjame ver lo que traes y cuéntame tu historia. Pero, por la Luz, date prisa. La defensa de Villa Oscura es mi prioridad. No tengo tiempo para tonterías.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Vaya, desde luego, tienes madera de detective, $c.', 0);
-- 80 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=80
SET @ID := 80;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tú otra vez, $n? ¿Qué te trae aquí de nuevo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Pues sí! La caligrafía de esta página coincide con las firmas del registro.', 0);
-- 266 Búsqueda en la posada
-- https://es.classic.wowhead.com/quest=266
SET @ID := 266;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El Cuervo Escarlata ya no es lo que solía ser pero aún pasan por aquí algunos viajeros.$B$BDescribirme al tipo al que buscas, quizás lo recuerde.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, sí, recuerdo este libro. Su dueño alquiló una habitación por unos días. Se pasaba las noches en el bar, escribiendo.$B$BDejó el pueblo a toda prisa, murmurando algo de que le perseguían... La última vez que lo vi se dirigía hacia el oeste... buscaba un nuevo lugar en el que esconderse.$B$BEl primer lugar al que llegaría yendo hacia el oeste sería Cerro del Cuervo...', 0);
-- 97 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=97
SET @ID := 97;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sí, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Lo sabía! ¡Buen trabajo, $n!', 0);
-- 98 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=98
SET @ID := 98;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Lo sé, $n: Stalvan está muerto. Percibí una oleada de esperanza que atravesaba el bosque contaminado. El Bosque del Ocaso está libre, por fin, de su sed de sangre. Aunque mi alegría se ensombrece cuando pienso en aquellos que cayeron a manos de esa horrible bestia. En cualquier caso, has sido valiente y astuto, $c.', 0);
-- 453 Encuentra la figura misteriosa
-- https://es.classic.wowhead.com/quest=453
SET @ID := 453;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo estás? ¡Déjame!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Alterio suspira...>$B$BSí, soy el autor de ese libro. Por fin me has encontrado, ¿eh?$B$BSi has leído ese diario... ¡solo sabes la mitad de la historia!', 0);
-- 133 Un espantapájaros para necrófagos
-- https://es.classic.wowhead.com/quest=133
SET @ID := 133;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Creo que estoy oyendo a una panda de necrófagos en la parte trasera de la casa... ¡tengo que colocar ese espantapájaros ya! ¿Me conseguiste las costillas de necrófago?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, gracias. ¡Son justo lo que necesito!', 0);
-- 134 Ladrones ogros
-- https://es.classic.wowhead.com/quest=134
SET @ID := 134;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes mi cajón? Si lo tienes, ¡dámelo! ¡Rápido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias al Nec... no, no, ¡gracias a TI, $n! Te has ganado tu recompensa.$B$B¡Aah! ¡Qué felicidad! ¡¡Qué noches me esperan!!', 0);
-- 160 Nota para el alcalde
-- https://es.classic.wowhead.com/quest=160
SET @ID := 160;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Abercrombie...? No conozco a nadie con ese nombre. ¿Dices que tienes una carta para mí de ese tal Abercrombie?$B$BBueno, pues dámela...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Ello mira la carta...>$B$B¿Qué idioma es este? Parece antiguo... No puedo leerlo.', 0);
-- 268 Entrega para Sven
-- https://es.classic.wowhead.com/quest=268
SET @ID := 268;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has averiguado quién era la figura misteriosa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Este diario me explica muchas cosas ¡y me indica el camino para enfrentarme a los jinetes oscuros! He visto a esos jinetes en Bosque del Ocaso, y les he visto hablando con el zahorí Morbent Vil, en la Loma Inhóspita.', 0);
-- 323 Pon a prueba tu valor
-- https://es.classic.wowhead.com/quest=323
SET @ID := 323;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Lucha duro, $N. Y no te desesperes, porque la desesperación es el arma más grande del mal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tu habilidad en combate, $n, es indiscutible. ¡Y tu resolución podría ayudarnos a presenciar el final de Morbent Vil!', 0);
-- 269 En busca de sabiduría
-- https://es.classic.wowhead.com/quest=269
SET @ID := 269;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Descansa, $ghermano:hermana;. Se ve que has viajado lejos y que llevas un peso enorme. ¿Puedes decirme qué es lo que proyecta sobre ti esa sombra tan oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Después de leer el diario y de oír tu intención...>$B$BUna malvada mácula se ha hecho con el ya asediado Bosque del Ocaso. Doy gracias a la Luz porque ahora tenemos a un héroe como tú para hacerle frente.$B$BPero primero debes prepararte para la prueba que te espera, pues el poder del Necromántico Morbent Vil es inconmensurable y además, ha lanzado sobre sí mismo oscuros encantamientos que lo protegen de ataques físicos. Si quieres derrotarle, necesitarás un arma que pueda contrarrestar estas protecciones.', 0);
-- 251 Traduce la nota de Abercrombie
-- https://es.classic.wowhead.com/quest=251
SET @ID := 251;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Una nota de Abercrombie el ermitaño, ¿eh? Pues no sé quién es... Pero desde luego, si vive en el cementerio, ¡debe de tener el cerebro podrido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Sirra empieza a traducir la nota...>', 0);
-- 401 Espera a que Sirra acabe
-- https://es.classic.wowhead.com/quest=401
SET @ID := 401;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ya está. Está traducida...$B$B<El aire es cada vez más pesado, como si una espesa y negra cortina se estuviera cerrando sobre el mundo...>', 0);
-- 252 Una traducción para Ello
-- https://es.classic.wowhead.com/quest=252
SET @ID := 252;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ¿la nota está traducida? Déjame verla, por favor...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Ello lee la carta... y palidece. Luego te mira a ti...>$B$BAunque cuando ayudaste a Abercrombie lo hiciste motivado por tu bondad, con tus acciones has condenado a nuestro pueblo.$B$B<Ello se pierde en sus pensamientos...>', 0);
-- 253 La novia del embalsamador
-- https://es.classic.wowhead.com/quest=253
SET @ID := 253;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado la tumba de Eliza? ¿Tienes el corazón del embalsamador?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Lo has conseguido! La magia que contiene su corazón nos protegerá contra el mal del embalsamador y será un poderoso auspicio para Villa Oscura.$B$BHas hecho una gran cosa para nuestra gente, $n. Tu nombre permanecerá para siempre en nuestros anales.', 0);

-- 254 Excavar la tierra
-- https://es.classic.wowhead.com/quest=254
SET @ID := 254;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Excavas entre la tierra suelta que hay sobre la tumba... y encuentras los restos de un féretro.$B$BEn el interior del féretro puedes sentir la vibración de unos dedos arañando y el rechinar de unos dientes podridos...$B$B¿Abrirás el féretro y extraerás el corazón del embalsamador?', 0);
-- 343 Hablando de entereza
-- https://es.classic.wowhead.com/quest=343
SET @ID := 343;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Metalurgia? Ah, sí, tenemos muchos libros sobre eso. Estoy encantado de poder ayudar al hermano Kristoff con su discurso. Y ahora... ¿Qué libro en particular necesita el buen hermano?', 0);
-- 1274 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1274
SET @ID := 1274;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. Soy el Obispo DeLavey.$B$BSin duda, si estás aquí preguntándome sobre mi asunto del Castillo, es porque el joven Thomas ha tenido éxito a la hora de pedirte ayuda para nuestro reino. Siempre ha sido experto en hacer lo que le pido.$B$BMe temo que no tengo mucho tiempo para explicarme, así que iré directo al problema... y, por favor, intenta que nadie se entere de esto.', 0);
-- 2923 Maestro manitas Sobrechispa
-- https://es.classic.wowhead.com/quest=2923
SET @ID := 2923;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, hemos perdido el control del tecnobot. ¿Puedes ayudarme?', 0);
-- 1793 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1793
SET @ID := 1793;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Se ha demostrado que la Luz camina a tu lado, $n, pero el peligro nos acecha cada día y es importante saber qué fuerza se esconde en el interior de cada uno. Tu temple se pondrá a prueba cuando demonios, dragones, o cualquier otro ser malvado entre en tus tierras. ¿Serás lo suficientemente fuerte?$B$BEl coraje, sin tener en cuenta en qué situación, es tan necesario para los paladines como la Luz, tu armadura y tu arma. Proteger a los débiles y no perder la fe, son dos lecciones más que tendrás que aprender cuando estudies en la Catedral de la Luz.', 0);
-- 1649 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1649
SET @ID := 1649;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, quieres pedirme una prueba de coraje. Espléndido.$B$BHay muchas tareas en la ciudad y en las tierras de alrededor que presentan muchos desafíos, perfectos para alguien con tus habilidades.$B$BEsta prueba no se puede tomar a la ligera, $n. Esto, al igual que muchas cosas con las que te encontrarás en tu camino, podría costarte la vida. La iglesia siempre quiere reforzar sus filas, pero también comprende los sacrificios necesarios para asegurar que los paladines son dignos de ella.$B$B¿Estás preparado?', 0);
-- 1650 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1650
SET @ID := 1650;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. Por la armadura y todas esas armas que llevas, supongo que estás aquí para intentar conquistar mi tierra, o porque la iglesia por fin ha enviado a alguien para protegerme mientras mi Jordan no está.$B$BBueno, me presentaré: soy Daphne Fontana. Es un placer.$B$BNo llegas demasiado tarde... Solo he matado media docena de esas bestias desde el último amanecer. Han tardado bastante en subir por esa curva de ahí, pero probablemente te hayan visto venir, así que supongo que estarán aquí en cualquier momento.', 0);
-- 270 La flota maldita
-- https://es.classic.wowhead.com/quest=270
SET @ID := 270;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El hierro Forjaluz es un metal precioso, pero parece que tu misión es muy peligrosa. Has hecho un largo camino, $ghermano:hermana;. Con suerte, encontrarás lo que buscas.$B$BY, si consigues el hierro, sé quién puede forjar un arma para luchar contra ese Necromántico del que hablas del Bosque del Ocaso.', 0);
-- 2040 Asalto subterráneo
-- https://es.classic.wowhead.com/quest=2040
SET @ID := 2040;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado la dentrituradora goblin, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Gracias a ti, Gnomeregan está a un paso más cerca de su día de liberación.', 0);
-- 2928 Excavadoras gyroagujereamáticas
-- https://es.classic.wowhead.com/quest=2928
SET @ID := 2928;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Si esto fuera una carrera, ya habrías perdido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto será perfecto, $n. Una excavadoras gyroagujereamática arreglada, solo quedan 398.', 0);
-- 167 Oh, hermano...
-- https://es.classic.wowhead.com/quest=167
SET @ID := 167;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado alguna pista de mi hermano? ¿Hay alguna esperanza después de todo este tiempo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Mis sospechas eran ciertas! Mi pobre hermano... Bueno, gracias, al menos ahora tengo la conclusión del misterio, incluso aunque la conclusión sea trágica.', 0);
-- 168 Recolección de recuerdos
-- https://es.classic.wowhead.com/quest=168
SET @ID := 168;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Conseguiste recuperar alguna de las Tarjetas del Sindicato Minero de mis colegas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por esto, $n. Tus esfuerzos contribuirán a traer la paz a los caídos en los comienzos de esta tragedia. Me aseguraré de que se informe a las familias.', 0);
-- 543 La Tiara Perenolde
-- https://es.wowhead.com/quest=543
-- https://wow-es.gamepedia.com/Misión:La Tiara Perenolde
SET @ID := 543;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. Intenta evitar pisar el dobladillo de mis pantalones. Este traje es nuevo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ah, qué bien! Está claro que habrá que limpiar esto pero, realmente, te has superado a ti mismo, $n. Haré que alguien prepare la tiara y la coloque en nuestra colección con presteza.$B$BHas de saber que nuestra gratitud, es tan inmensa como nuestra colección.', 0);
-- 1241 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1241
SET @ID := 1241;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm, será mejor que tengas una buena razón para interrumpir a un hombre que está pescando. No me gustan mucho los vendedores ambulantes y mucho menos los vagabundos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm... <Jorgen te mira con los ojos entrecerrados.>$B$BMuy bien. Te ayudaré, pero no porque quiero hacerlo, sino porque estoy obligado.$B$BY dejemos una cosa clara: sabes más de lo que deberías saber. Mantengamos esto en secreto y no vayas por las tabernas por ahí hablando de tus descubrimientos. ¿Comprendido?', 0);
-- 344 Hermano Paxton
-- https://es.classic.wowhead.com/quest=344
SET @ID := 344;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Gavilla se pregunta dónde está su libro? ¡Qué vergüenza! Tengo el libro, pero sigo haciendo la copia y todavía no puedo darte el original.', 0);
-- 579 La biblioteca de Ventormenta
-- https://es.classic.wowhead.com/quest=579
SET @ID := 579;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El rey Varian ha otorgado gran importancia al aprendizaje y, por lo tanto, ha proporcionado fondos para hacer disponibles al público copias de varios tomos y escritos. Es muy simple. Tráeme un libreto de la biblioteca y puedo darte una copia de uno de los libros disponibles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te interesa alguno de estos títulos, $N?', 0);
-- 1242 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1242
SET @ID := 1242;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Puedo hacer algo por ti? ¿Quizás te gustaría probar nuestro cheddar de Trias especial? ¿O un trocito de queso azul de Darnassus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Perdona, ¿una carta para mí? Bueno, yo... cuando te pasas el día trabajando, como yo, no se suele recibir algo que no sea una caja o un barril. Veamos de qué va esto.$B$B<Elling te mira mientras abre la carta.>$B$BPareces algo tenso, $n, ¿estás bien?', 0);
-- 345 Suministros de tinta
-- https://es.classic.wowhead.com/quest=345
SET @ID := 345;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡¿Que necesitas qué?! Por si no te has dado cuenta, estamos muy ocupados fortificando las defensas de Villa del Lago y reparando el daño sufrido por los ataques orcos. Si necesitas mineral de hierro de Rethban, ¡vete a buscarlo!', 0);
-- 1243 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1243
SET @ID := 1243;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'No es demasiado seguro ir por el bosque, $n. Ten cuidado y, si ves algo sospechoso o peligroso, avisa a los vigilantes inmediatamente. No intentes nada sin ayuda. No nos hacemos responsables de ninguna cosa terrible que te pueda suceder.$B$BPero ambos sabemos que vas a pasar de mí y a luchar contra cualquier cosa que aparezca en medio de la oscuridad, ¿verdad? ¡Ja, ja! Sí, vosotros, los aventureros... sois todos iguales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te envía Trias, eh? Eso cambia la cosa.$B$BEntonces, puedes luchar contra cualquier monstruosidad que salga de la oscuridad. Seguro que podrás vencer lo que sea fácilmente, ya que eres capaz de tratar con gente de su calaña.$B$BY bien, ¿para qué me necesita mi amigo en un día tan funesto como este?', 0);
-- 1651 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1651
SET @ID := 1651;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Lo hemos logrado, $n! Gracias por tu ayuda. Estuviste realmente increíble ahí fuera. Nunca pensé que un $c pudiera manejar tantos enemigos a la vez.$B$BRealmente has demostrado valentía frente a las abrumadoras probabilidades.', 0);
-- 347 La mena de Rethban
-- https://es.classic.wowhead.com/quest=347
SET @ID := 347;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes el mineral de hierro de Rethban?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, excelente! Puedo usar este mineral para hacer la tinta y después terminar de copiar La tensión del hierro.$B$B¡Gracias, $n!', 0);
-- 1244 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1244
SET @ID := 1244;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ten cuidado ahí fuera, $n. Sé que Trias fue quien te envió, pero eso no significa que no haya nada acechando en los bosques que podría causarte un par de problemas... especialmente contigo investigando a los Defias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has vuelto de una pieza. Y no se puede pedir mucho más que eso, ¿eh?$B$BAhora, veamos lo que tenemos aquí. Esto parece bastante oficial, a juzgar por los documentos Defias que he visto. Pero podría ser una falsificación, solo para hacerte perder la pista de lo que estés buscando.', 0);
-- 1245 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1245
SET @ID := 1245;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Veo que has vuelto, y que estás de una pieza. Ambos sabemos que no estás aquí por el queso, así que vayamos al grano. ¿Backus te ayudó, o todavía no has terminado en el Bosque del Ocaso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí... una lectura interesante. Jorgen y DeLavey fueron inteligentes por avisarme.$B$BParece que los Defias han estado esforzándose mucho por completar este plan. Espera, ¿qué es esto? ¿"Puño"? Ese nombre me suena.', 0);
-- 346 Regresa junto a Kristoff
-- https://es.classic.wowhead.com/quest=346
SET @ID := 346;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has conseguido encontrar el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Exacto! Gracias, $n. Que la Luz brille sobre tu cuerpo y tu espíritu.', 0);
-- 1246 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1246
SET @ID := 1246;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡¿Qué?!$B$B¿¿¿Vienes a mi callejón a hacerme preguntas personales sobre mis asuntos??? Asuntos con los que, obviamente, no tienes nada que ver.', 0);

-- 1447 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1447
SET @ID := 1447;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido por alguna razón en particular? ¿Qué necesitas?', 0),
(@ID, 'esMX', '¿Has venido por alguna razón en particular? ¿Qué necesitas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quise decir nada con el comentario de que eres un estúpido $c. ¿Somos amigos, verdad? ¿Sin resentimientos?', 0),
(@ID, 'esMX', 'No quise decir nada con el comentario de que eres un estúpido $c. ¿Somos amigos, verdad? ¿Sin resentimientos?', 0);
-- 1247 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1247
SET @ID := 1247;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que sigues con vida, $n. ¿Todo fue bien?$B$BHe estado leyendo más sobre este plan suyo y, aunque no dice el nombre del diplomático al que perseguían, habla sobre un plan B que pusieron en marcha tras fallar su primer intento de captura.$B$BEse Slim al que mencionó Dashel no tiene ningún otro nombre aquí, pero si dices que está en Menethil, al menos es un comienzo.', 0),
(@ID, 'esMX', 'Me alegra ver que sigues con vida, $n. ¿Todo fue bien?$B$BHe estado leyendo más sobre este plan suyo y, aunque no dice el nombre del diplomático al que perseguían, habla sobre un plan B que pusieron en marcha tras fallar su primer intento de captura.$B$BEse Slim al que mencionó Dashel no tiene ningún otro nombre aquí, pero si dices que está en Menethil, al menos es un comienzo.', 0);
-- 1652 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1652
SET @ID := 1652;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, nos volvemos a encontrar, $n, y ya veo que estás de muy buen humor.$B$BLa casa de los Stilwell estará a salvo por otro día, y por tu historia veo que no había escasez de peligro. Bien hecho.$B$BDaphne y Jordan han ayudado mucho a la Iglesia, y lo menos que podíamos hacer por ellos era que protegieras sus propiedades y sus propias vidas.$B$BPor tu valor, serás recompensado.', 0),
(@ID, 'esMX', 'Entonces, nos volvemos a encontrar, $n, y ya veo que estás de muy buen humor.$B$BLa casa de los Stilwell estará a salvo por otro día, y por tu historia veo que no había escasez de peligro. Bien hecho.$B$BDaphne y Jordan han ayudado mucho a la Iglesia, y lo menos que podíamos hacer por ellos era que protegieras sus propiedades y sus propias vidas.$B$BPor tu valor, serás recompensado.', 0);
-- 1653 La prueba de rectitud
-- https://es.classic.wowhead.com/quest=1653
SET @ID := 1653;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres el que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0),
(@ID, 'esMX', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres el que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0);
-- 1248 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1248
SET @ID := 1248;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida con los brazos abiertos, $n. Me alegra que te unas a nosotros. ¿Te apetece una cervecita? ¿O quizás algo de carne de ovino?$B$BDi lo que quieras y me encargaré de que lo tengas. Me llamo Mikhail, y solo deseo servirte bien.$B$B¿Mmm? ¿Qué es eso? ¿Trias? Habla bajo, amigo. Esto no es algo de lo que se deba enterar toda la taberna.', 0),
(@ID, 'esMX', 'Te doy la bienvenida con los brazos abiertos, $n. Me alegra que te unas a nosotros. ¿Te apetece una cervecita? ¿O quizás algo de carne de ovino?$B$BDi lo que quieras y me encargaré de que lo tengas. Me llamo Mikhail, y solo deseo servirte bien.$B$B¿Mmm? ¿Qué es eso? ¿Trias? Habla bajo, amigo. Esto no es algo de lo que se deba enterar toda la taberna.', 0);
-- 1578 Abastecer al frente
-- https://es.classic.wowhead.com/quest=1578
SET @ID := 1578;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tengo tiempo de charlar. ¿Querías algo?', 0),
(@ID, 'esMX', 'No tengo tiempo de charlar. ¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, perdona! No había visto que traes suministros. ¡Nos serán de gran ayuda!$B$BTen, es el patrón de una armadura; espero que te sea útil.', 0),
(@ID, 'esMX', '¡Ah, perdona! No había visto que traes suministros. ¡Nos serán de gran ayuda!$B$BTen, es el patrón de una armadura; espero que te sea útil.', 0);
-- 1618 Equipar Crestagrana
-- https://es.classic.wowhead.com/quest=1618
SET @ID := 1618;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que estés aquí con buenas noticias de Forjaz. ¡Porque estoy al final de mi ingenio!.', 0),
(@ID, 'esMX', 'Espero que estés aquí con buenas noticias de Forjaz. ¡Porque estoy al final de mi ingenio!.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $N. Esto me ayudará enormemente. Con los orcos Roca Negra atacando desde Stonewatch Keep y los gnolls Crestagrana acechando en las estribaciones del norte, siempre estoy arreglando armaduras y fabricando nuevas armas para nuestras tropas.$B$BLos suministros que trajiste me darán un respiro. Tendré tiempo suficiente para enseñarte algo ...', 0),
(@ID, 'esMX', 'Gracias, $N. Esto me ayudará enormemente. Con los orcos Roca Negra atacando desde Stonewatch Keep y los gnolls Crestagrana acechando en las estribaciones del norte, siempre estoy arreglando armaduras y fabricando nuevas armas para nuestras tropas.$B$BLos suministros que trajiste me darán un respiro. Tendré tiempo suficiente para enseñarte algo ...', 0);
-- 7793, 7798, 7803, 7808, 7814, 7821, 7827, 7834, 10354, 10360 Un donativo de seda
DELETE FROM `quest_request_items_locale` WHERE `ID` IN(7793, 7798, 7803, 7808, 7814, 7821, 7827, 7834, 10354, 10360) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES 
(7793, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7798, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7803, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7808, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7814, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7821, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7827, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7834, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10354, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10360, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7793, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7798, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7803, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7808, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7814, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7821, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7827, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7834, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10354, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10360, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN(7793, 7798, 7803, 7808, 7814, 7821, 7827, 7834, 10354, 10360) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES 
(7793, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7798, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7803, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7808, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7814, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7821, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7827, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7834, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10354, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10360, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7793, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7798, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7803, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7808, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7814, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7821, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7827, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7834, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10354, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10360, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0);
-- 1453 Los negocios de los Recuperadores en Desolace
-- https://es.classic.wowhead.com/quest=1453
SET @ID := 1453;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que aún queda gente aventurera.$B$BMe llamo Kreldig. Has hecho bien en unirte a los Recuperadores, $n. Todo el mundo busca algo: un tesoro, un amor perdido... Y tú puedes encontrarlo... por un precio.', 0),
(@ID, 'esMX', 'Me alegra ver que aún queda gente aventurera.$B$BMe llamo Kreldig. Has hecho bien en unirte a los Recuperadores, $n. Todo el mundo busca algo: un tesoro, un amor perdido... Y tú puedes encontrarlo... por un precio.', 0);
-- 707 ¡Vetaferro te necesita!
-- https://es.classic.wowhead.com/quest=707
SET @ID := 707;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de parte de Pico Tormenta? Muy bien.$B$BTengo trabajo para ti.', 0),
(@ID, 'esMX', '¿Vienes de parte de Pico Tormenta? Muy bien.$B$BTengo trabajo para ti.', 0);
-- 1050 Mitología de los titanes
-- https://es.classic.wowhead.com/quest=1050
SET @ID := 1050;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El monasterio era un seminario para paladines. Fue un bastión de la Luz, pero cayó en manos de los fanáticos de la Cruzada Escarlata.$B$BCreían perseguir un noble objetivo: limpiar la tierra de la plaga de los no-muertos; pero acabaron enloqueciendo y enemistándose con todos.$B$BTráeme Mitología de los Titanes para que lo guarde aquí en Forjaz.$B$BLas corruptas salas del monasterio no son lugar para un tesoro como ese.', 0),
(@ID, 'esMX', 'El monasterio era un seminario para paladines. Fue un bastión de la Luz, pero cayó en manos de los fanáticos de la Cruzada Escarlata.$B$BCreían perseguir un noble objetivo: limpiar la tierra de la plaga de los no-muertos; pero acabaron enloqueciendo y enemistándose con todos.$B$BTráeme Mitología de los Titanes para que lo guarde aquí en Forjaz.$B$BLas corruptas salas del monasterio no son lugar para un tesoro como ese.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me traes el texto sagrado!$B$BHas viajado lejos y sin duda fue difícil conseguir el libro. Pero tu labor beneficia a los enanos de Forjaz.$B$BGracias en nombre de la Liga de Exploradores, $n.', 0),
(@ID, 'esMX', '¡Me traes el texto sagrado!$B$BHas viajado lejos y sin duda fue difícil conseguir el libro. Pero tu labor beneficia a los enanos de Forjaz.$B$BGracias en nombre de la Liga de Exploradores, $n.', 0);
-- 2922 ¡Salva el cerebro de Tecnobot!
-- https://es.classic.wowhead.com/quest=2922
SET @ID := 2922;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste al techrobot? ¿Tienes el procesador central de memoria?', 0),
(@ID, 'esMX', '¿Encontraste al techrobot? ¿Tienes el procesador central de memoria?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Gracias, $n, voy a ponerme a trabajar de inmediato!$B$BPobre tecnobot, vaya susto te has llevado.$B$BEnseguida te arreglo; a ver, dónde estará mi llave inglesa giratoria con gato hidráulico...', 0),
(@ID, 'esMX', '¡Excelente! ¡Gracias, $n, voy a ponerme a trabajar de inmediato!$B$BPobre tecnobot, vaya susto te has llevado.$B$BEnseguida te arreglo; a ver, dónde estará mi llave inglesa giratoria con gato hidráulico...', 0);
-- 2039 Encuentra a Bingles
-- https://es.classic.wowhead.com/quest=2039
SET @ID := 2039;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que Gnoarn cree que no sé arreglármelas solo? Pues no veo por qué...$B$BDa igual, ¡te necesito! Bueno, ¡el movimiento te necesita!', 0),
(@ID, 'esMX', '¿Así que Gnoarn cree que no sé arreglármelas solo? Pues no veo por qué...$B$BDa igual, ¡te necesito! Bueno, ¡el movimiento te necesita!', 0);

-- 2927 Al día siguiente
-- https://es.classic.wowhead.com/quest=2927
SET @ID := 2927;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creí que no soportaría la pérdida del pelo, pero ya ves.$B$BEstábamos juntos cuando le cayó la nube radiactiva y se le empezó a caer el pelo a puñados. Fue horroroso. ¡Empezó a tocarse la cabeza, se le pusieron los ojos rojos y juró venganza! Desde entonces la tomó con los troggs.$B$B<Ozzie se estremece.>', 0),
(@ID, 'esMX', 'Creí que no soportaría la pérdida del pelo, pero ya ves.$B$BEstábamos juntos cuando le cayó la nube radiactiva y se le empezó a caer el pelo a puñados. Fue horroroso. ¡Empezó a tocarse la cabeza, se le pusieron los ojos rojos y juró venganza! Desde entonces la tomó con los troggs.$B$B<Ozzie se estremece.>', 0);
-- 2930 Rescatar los datos
-- https://es.classic.wowhead.com/quest=2930
SET @ID := 2930;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la tarjeta perforada prismática?', 0),
(@ID, 'esMX', '¿Tienes la tarjeta perforada prismática?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido recuperar los datos! Son importatísimos, vitales.$B$BEste servicio que nos has prestado será recordado mucho tiempo, $n.', 0),
(@ID, 'esMX', '¡Has conseguido recuperar los datos! Son importatísimos, vitales.$B$BEste servicio que nos has prestado será recordado mucho tiempo, $n.', 0);
-- 2929 La gran traición
-- https://es.classic.wowhead.com/quest=2929
SET @ID := 2929;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La tarea está completa? ¿Pidió indulgencia?, ¿Piedad?', 0),
(@ID, 'esMX', '¿La tarea está completa? ¿Pidió indulgencia?, ¿Piedad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuéntame otra vez cómo le aplastaste el cráneo con la bota, $r. Ahora que ha muerto, estamos más cerca de recuperar Gnomeregan.', 0),
(@ID, 'esMX', 'Cuéntame otra vez cómo le aplastaste el cráneo con la bota, $r. Ahora que ha muerto, estamos más cerca de recuperar Gnomeregan.', 0);
-- 2924 Esencias artificiales
-- https://es.classic.wowhead.com/quest=2924
SET @ID := 2924;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las esencias artificiales?', 0),
(@ID, 'esMX', '¿Tienes las esencias artificiales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora que tengo las esencias, puedo empezar mi nuevo experimento!$B$B¡No puedo agradecerte lo suficiente, $N! ¡Gracias a tu valentía, la investigación gnómica va a dar un salto cuántico!', 0),
(@ID, 'esMX', '¡Ahora que tengo las esencias, puedo empezar mi nuevo experimento!$B$B¡No puedo agradecerte lo suficiente, $N! ¡Gracias a tu valentía, la investigación gnómica va a dar un salto cuántico!', 0);
-- 1653 La prueba de rectitud
-- https://es.classic.wowhead.com/quest=1653
SET @ID := 1653;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres $gel:la; que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0),
(@ID, 'esMX', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres $gel:la; que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0);
-- 1654 La prueba de rectitud
SET @ID := 1654;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los objetos que estás buscando serán difíciles de conseguir, pero puedo asegurarte que el arma que fabricaré para ti valdrá la pena.$B$BSerá mi mejor trabajo hasta la fecha, y solo un pequeño pago por el servicio que me ha prestado.', 0),
(@ID, 'esMX', 'Los objetos que estás buscando serán difíciles de conseguir, pero puedo asegurarte que el arma que fabricaré para ti valdrá la pena.$B$BSerá mi mejor trabajo hasta la fecha, y solo un pequeño pago por el servicio que me ha prestado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es maravilloso! Tienes todos los artículos.$B$BNo debería tener ningún problema en forjarte un gran arma con estos. De hecho, tenía planes para hacer esto desde hace algún tiempo. Simplemente nunca tuve la oportunidad de recolectar los productos. Gracias, $n.$B$BSe siente bien volver a tener el martillo de mi padre... y una gema Kor. Nunca pensé que vería una de estas yo mismo.', 0),
(@ID, 'esMX', '¡Esto es maravilloso! Tienes todos los artículos.$B$BNo debería tener ningún problema en forjarte un gran arma con estos. De hecho, tenía planes para hacer esto desde hace algún tiempo. Simplemente nunca tuve la oportunidad de recolectar los productos. Gracias, $n.$B$BSe siente bien volver a tener el martillo de mi padre... y una gema Kor. Nunca pensé que vería una de estas yo mismo.', 0);
-- 2926 Gnogaine
-- https://es.classic.wowhead.com/quest=2926
SET @ID := 2926;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿No ves que tenemos muchos gnomos que curar?! ¡Necesitamos más restos radiactivos!', 0),
(@ID, 'esMX', '¡¿No ves que tenemos muchos gnomos que curar?! ¡Necesitamos más restos radiactivos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Vamos a probar la nueva fórmula. ¡Si funciona, no solo curaremos a los gnomos leprosos, sino que me volverá a crecer el pelo! ¡Aparta!', 0),
(@ID, 'esMX', '¡Excelente! Vamos a probar la nueva fórmula. ¡Si funciona, no solo curaremos a los gnomos leprosos, sino que me volverá a crecer el pelo! ¡Aparta!', 0);
-- 412 Operación Recombobulación
SET @ID := 412;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El recombobulador estará listo en cuanto tengamos suficientes levas estabilizadoras y engranajes giromecánicos.', 0),
(@ID, 'esMX', 'El recombobulador estará listo en cuanto tengamos suficientes levas estabilizadoras y engranajes giromecánicos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos engranajes giromecánicos y estas levas estabilizadoras cumplen todos los requisitos del esquema de Ozzie para el dispositivo de recombobulación. Cuando añada algo de hidrolubricante a los pistones de combustión, ajuste la manivela y aumente la viscosidad del gel electrogómico, la raza gnoma volverá a ser lo que era.', 0),
(@ID, 'esMX', 'Estos engranajes giromecánicos y estas levas estabilizadoras cumplen todos los requisitos del esquema de Ozzie para el dispositivo de recombobulación. Cuando añada algo de hidrolubricante a los pistones de combustión, ajuste la manivela y aumente la viscosidad del gel electrogómico, la raza gnoma volverá a ser lo que era.', 0);
-- 1806 La prueba de rectitud
-- https://es.classic.wowhead.com/quest=1806
SET @ID := 1806;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está, $n. Un arma digna de $gun campeón:una campeona; de la Luz como tú. Le he puesto el nombre de un gran paladín enano que era amigo mío. Su nombre era Verigan ... Bosch Verigan.$B$BPor favor, acéptalo en mi nombre y en el de mi esposa. Te debemos una gran deuda, y el mundo será un lugar más seguro con alguien de tu habilidad viajando por la tierra.', 0),
(@ID, 'esMX', 'Aquí está, $n. Un arma digna de $gun campeón:una campeona; de la Luz como tú. Le he puesto el nombre de un gran paladín enano que era amigo mío. Su nombre era Verigan ... Bosch Verigan.$B$BPor favor, acéptalo en mi nombre y en el de mi esposa. Te debemos una gran deuda, y el mundo será un lugar más seguro con alguien de tu habilidad viajando por la tierra.', 0);
-- 315 La cerveza perfecta
-- https://es.wowhead.com/quest=315
SET @ID := 315;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la cardaluz ya? Ya casi tengo todo listo para la próxima cerveza y quisiera probar esa plantita en la mezcla.', 0),
(@ID, 'esMX', '¿Tienes la cardaluz ya? Ya casi tengo todo listo para la próxima cerveza y quisiera probar esa plantita en la mezcla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Estoy deseando utilizarla en mis recetas. Estoy pensando en una en concreto a la que le irá de maravilla.', 0),
(@ID, 'esMX', '¡Genial! Estoy deseando utilizarla en mis recetas. Estoy pensando en una en concreto a la que le irá de maravilla.', 0);
-- 310 Rivales acérrimos
-- https://es.classic.wowhead.com/quest=310
SET @ID := 310;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La fecha del barril te indica que no tardará en ser abierto.', 0),
(@ID, 'esMX', 'La fecha del barril te indica que no tardará en ser abierto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas rápidamente el barril de Marleth de brebaje de Cebadiz entre los barriles de Cebatruenos.', 0),
(@ID, 'esMX', 'Colocas rápidamente el barril de Marleth de brebaje de Cebadiz entre los barriles de Cebatruenos.', 0);
-- 413 Cerveza negra Brillante
-- https://es.classic.wowhead.com/quest=413
SET @ID := 413;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $c! ¿Qué te trae hasta aquí?$B$BAlgo emocionante, espero. Hace días que no consigo participar en una buena batalla y se me está acabando este barril de cerveza...', 0),
(@ID, 'esMX', '¡Hola, $c! ¿Qué te trae hasta aquí?$B$BAlgo emocionante, espero. Hace días que no consigo participar en una buena batalla y se me está acabando este barril de cerveza...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El montaraz Cebadiz prueba la cerveza negra Brillante...>$B$BOh. ¡VAYA! Esta cosa le da como un brillo nuevo a la vista. ¡Creo que puedo ver en la oscuridad!', 0),
(@ID, 'esMX', '<El montaraz Cebadiz prueba la cerveza negra Brillante...>$B$BOh. ¡VAYA! Esta cosa le da como un brillo nuevo a la vista. ¡Creo que puedo ver en la oscuridad!', 0);
-- 2962 Necesitamos más material verdoso
-- https://es.classic.wowhead.com/quest=2962
SET @ID := 2962;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, no brillas. Es una buena señal.', 0),
(@ID, 'esMX', 'Mmm, no brillas. Es una buena señal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ozzie te examina.> ¡Impresionante! ¡Todavía tienes todos los dedos! Venga, vamos a ver qué puede hacer esta cosa.', 0),
(@ID, 'esMX', '<Ozzie te examina.> ¡Impresionante! ¡Todavía tienes todos los dedos! Venga, vamos a ver qué puede hacer esta cosa.', 0);
-- 400 Herramientas para Brasacerada
-- https://es.classic.wowhead.com/quest=400
SET @ID := 400;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mm? ¿No eres un poco joven para ser piloto de máquinas de asedio? Bueno, no importa. ¿Necesitas reparar algo?$B$BSi es así, coge número y ponte cómodo. Ahora mismo estoy con un par de motores y no tendré tiempo para nada más hasta dentro de unos días.$B$B¿O venías por otro motivo?', 0),
(@ID, 'esMX', '¿Mm? ¿No eres un poco joven para ser piloto de máquinas de asedio? Bueno, no importa. ¿Necesitas reparar algo?$B$BSi es así, coge número y ponte cómodo. Ahora mismo estoy con un par de motores y no tendré tiempo para nada más hasta dentro de unos días.$B$B¿O venías por otro motivo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis herramientas? ¡Bien hecho, $gmuchacho:muchacha;! Acabo de romper mi último destornillador hace una hora y necesitaba otro para acabar de reparar la máquina de asedio del piloto Roscapiedra. Desde luego, me has hecho un favor enorme trayendo estas herramientas hasta aquí, $n.', 0),
(@ID, 'esMX', '¿Tienes mis herramientas? ¡Bien hecho, $gmuchacho:muchacha;! Acabo de romper mi último destornillador hace una hora y necesitaba otro para acabar de reparar la máquina de asedio del piloto Roscapiedra. Desde luego, me has hecho un favor enorme trayendo estas herramientas hasta aquí, $n.', 0);
-- 384 Costillas de jabalí a la cerveza
-- https://es.wowhead.com/quest=384
SET @ID := 384;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Voy a necesitar esas costillas de jabalíes del risco y una jarra de malta rapsódica, $n.', 0),
(@ID, 'esMX', 'Voy a necesitar esas costillas de jabalíes del risco y una jarra de malta rapsódica, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La malta está lista y los jabalíes muertos$BY antes de acabar y de ponernos a hablar$BTendremos que luchar por ver quién empieza$B¡estas sabrosas costillas de jabalí a la cerveza!', 0),
(@ID, 'esMX', 'La malta está lista y los jabalíes muertos$BY antes de acabar y de ponernos a hablar$BTendremos que luchar por ver quién empieza$B¡estas sabrosas costillas de jabalí a la cerveza!', 0);
-- 403 El barril de Cebatruenos custodiado
-- https://es.classic.wowhead.com/quest=403
SET @ID := 403;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este barril está custodiado por Jarven Cebatruenos. Mientras esté en el sótano, nadie tocará los barriles.', 0),
(@ID, 'esMX', 'Este barril está custodiado por Jarven Cebatruenos. Mientras esté en el sótano, nadie tocará los barriles.', 0);
-- 308 Distraer a Jarven
-- https://es.classic.wowhead.com/quest=308
SET @ID := 308;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya! Con toda la bebida que hay aquí abajo... ¡Y tengo órdenes estrictas de no tocarla! Si tan solo pudiera probar un poco de nuestra Cerveza del Trueno... ¡agudiza el ingenio, y no es broma!', 0),
(@ID, 'esMX', '¡Vaya! Con toda la bebida que hay aquí abajo... ¡Y tengo órdenes estrictas de no tocarla! Si tan solo pudiera probar un poco de nuestra Cerveza del Trueno... ¡agudiza el ingenio, y no es broma!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es para mí? ¡Eres $gun héroe:una heroína;, $n!', 0),
(@ID, 'esMX', '¿Es para mí? ¡Eres $gun héroe:una heroína;, $n!', 0);
-- 311 Regresa junto a Marleth
-- https://es.classic.wowhead.com/quest=311
SET @ID := 311;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Diste el cambiazo?', 0),
(@ID, 'esMX', '¿Diste el cambiazo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No está mal, $n! ¿Te costó mucho superar a su guardia?$B$BNo importa. Muchas gracias. Y oye, si alguna vez necesitas una buena cervezota, ¡no te olvides de los brebajes de Cebadiz!', 0),
(@ID, 'esMX', '¡No está mal, $n! ¿Te costó mucho superar a su guardia?$B$BNo importa. Muchas gracias. Y oye, si alguna vez necesitas una buena cervezota, ¡no te olvides de los brebajes de Cebadiz!', 0);
-- 5541 Municiones para Estruendo
-- https://es.classic.wowhead.com/quest=5541
SET @ID := 5541;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no hayas venido a por munición, ¡porque casi se me ha agotado!', 0),
(@ID, 'esMX', 'Espero que no hayas venido a por munición, ¡porque casi se me ha agotado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, más munición! ¡Por fin ha llegado el cargamento del viejo Loslor! La munición llega con algo de retraso, pero como decía mi abuelo: ¡más vale tarde que nunca!$B$BMuchas gracias, $n. ¡Voy a atender a mis ansiosos compradores!', 0),
(@ID, 'esMX', '¡Genial, más munición! ¡Por fin ha llegado el cargamento del viejo Loslor! La munición llega con algo de retraso, pero como decía mi abuelo: ¡más vale tarde que nunca!$B$BMuchas gracias, $n. ¡Voy a atender a mis ansiosos compradores!', 0);
-- 313 El Cubil Pardo
-- https://es.classic.wowhead.com/quest=313
SET @ID := 313;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, $n, ¿ya has estado en El Cubil Pardo? Esos wendigos pueden llegar a ser muy feroces.', 0),
(@ID, 'esMX', 'Eh, $n, ¿ya has estado en El Cubil Pardo? Esos wendigos pueden llegar a ser muy feroces.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, sí, estas crines me vendrán estupendamente! Tienes agallas, $c. Apuesto a que te veremos protagonizar numerosas hazañas.', 0),
(@ID, 'esMX', '¡Ah, sí, estas crines me vendrán estupendamente! Tienes agallas, $c. Apuesto a que te veremos protagonizar numerosas hazañas.', 0);

-- 466 Búsqueda de incendicita
-- https://es.classic.wowhead.com/quest=466
SET @ID := 466;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dónde está el mineral, $n?!', 0),
(@ID, 'esMX', '¡¿Dónde está el mineral, $n?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes el mineral! ¡Bien hecho, $n! Tengo que encontrar a alguien que quiera trabajar con él. ¡Esperemos que no salga volando por los aires!', 0),
(@ID, 'esMX', '¡Tienes el mineral! ¡Bien hecho, $n! Tengo que encontrar a alguien que quiera trabajar con él. ¡Esperemos que no salga volando por los aires!', 0);
-- 317 Los suministros del reactor a vapor
-- https://es.classic.wowhead.com/quest=317
SET @ID := 317;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los preparativos van bien. ¿Cómo va tu caza?', 0),
(@ID, 'esMX', 'Los preparativos van bien. ¿Cómo va tu caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por la barba de Magni, ¡sí que has cazado! Gracias, $n.', 0),
(@ID, 'esMX', 'Por la barba de Magni, ¡sí que has cazado! Gracias, $n.', 0);
-- 318 La tajada
-- https://es.classic.wowhead.com/quest=318
SET @ID := 318;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que Bramiz necesita un poco de mi tajada? Mm... está bien.', 0),
(@ID, 'esMX', '¿Que Bramiz necesita un poco de mi tajada? Mm... está bien.', 0);
-- 319 Un favor a cambio de un barril de tajada
-- https://es.classic.wowhead.com/quest=319
SET @ID := 319;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has encargado de esos animales salvajes?', 0),
(@ID, 'esMX', '¿Te has encargado de esos animales salvajes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Será estupendo trabajar sin esos gritos y aullidos de fondo.', 0),
(@ID, 'esMX', 'Gracias, $n. Será estupendo trabajar sin esos gritos y aullidos de fondo.', 0);
-- 320 Regresa junto a Bramiz
-- https://es.classic.wowhead.com/quest=320
SET @ID := 320;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste esa tajada?', 0),
(@ID, 'esMX', '¿Conseguiste esa tajada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vale, esta me vale. Creo que abriré una botella ahora mismo para probarla...', 0),
(@ID, 'esMX', 'Vale, esta me vale. Creo que abriré una botella ahora mismo para probarla...', 0);
-- 416 Mata ratas
-- https://es.classic.wowhead.com/quest=416
SET @ID := 416;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ehl, $n, ¿me traes las orejas?', 0),
(@ID, 'esMX', 'Ehl, $n, ¿me traes las orejas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puaj, qué peste!$B$BAquí tienes la recompensa, $n. Buen trabajo.', 0),
(@ID, 'esMX', '¡Puaj, qué peste!$B$BAquí tienes la recompensa, $n. Buen trabajo.', 0);
-- 468 Preséntate ante el montaraz Piedragar
-- https://es.classic.wowhead.com/quest=468
SET @ID := 468;
UPDATE `quest_template_locale` SET `Title` = 'Preséntate ante el montaraz Piedragar' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $c! ¿Estás aquí para la misión de exploración, verdad? ¡Muy bien!$B$BEspero que tu equipo esté en buenas condiciones porque esta misión "de exploración" se ha convertido en algo más... turbio...', 0),
(@ID, 'esMX', '¡Hola, $c! ¿Estás aquí para la misión de exploración, verdad? ¡Muy bien!$B$BEspero que tu equipo esté en buenas condiciones porque esta misión "de exploración" se ha convertido en algo más... turbio...', 0);
-- 1339 La tarea del montaraz Pico Tormenta
-- https://es.classic.wowhead.com/quest=1339
SET @ID := 1339;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pues sí, tengo un trabajito que te llevará lejos de Loch Modan.$B$B¡Ya tienes otra aventura servida!', 0),
(@ID, 'esMX', 'Pues sí, tengo un trabajito que te llevará lejos de Loch Modan.$B$B¡Ya tienes otra aventura servida!', 0);
-- 418 Morcillas de Thelsamar
-- https://es.classic.wowhead.com/quest=418
SET @ID := 418;
UPDATE `quest_template_locale` SET `Details` = 'Aquí en Thelsamar siempre hay alguien que quiere comer, críos por todos lados, los obreros de la excavación y eso. Lo más conocido es la morcilla, ¿la has probado?$B$B¿No? Bueno, pues aquí hay que trabajar para comer, no creas que te libras porque seas $c.$B$BNecesito carne de oso, tripa de jabalí y un poco de icor de araña para darle sabor. ¡Tú trae eso y de cocinar me ocupo yo, Vidra!', `Objectives` = 'Lleva 3 trozos de Carne de oso, 3 Tripas de jabalí y 3 porciones de Icor de araña a Vidra Hogartufa, en Thelsamar.' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si me traes los ingredientes, me pongo ya mismo a cocinar.', 0),
(@ID, 'esMX', 'Si me traes los ingredientes, me pongo ya mismo a cocinar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es más fácil de lo que parece.$B$BNo había conocido a nadie con tanto interés, pero ya que preguntas, te daré la receta. ¡Recuerda que no se conservan demasiado tiempo!', 0),
(@ID, 'esMX', 'Es más fácil de lo que parece.$B$BNo había conocido a nadie con tanto interés, pero ya que preguntas, te daré la receta. ¡Recuerda que no se conservan demasiado tiempo!', 0);
-- 255 Mercenarios
-- https://es.classic.wowhead.com/quest=255
SET @ID := 255;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido algo de suerte?', 0),
(@ID, 'esMX', '¿Has tenido algo de suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estupendas noticias. Quiero agradecerte lo que has hecho en nombre de Thelsamar. Y resuelto el problema de los ogros, podremos concentrarnos en los troggs.', 0),
(@ID, 'esMX', 'Estupendas noticias. Quiero agradecerte lo que has hecho en nombre de Thelsamar. Y resuelto el problema de los ogros, podremos concentrarnos en los troggs.', 0);
-- 1655 Envío de mena de Bailor
-- https://es.classic.wowhead.com/quest=1655
SET @ID := 1655;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿todavía tienes suerte? Jaja, esos ogros todavía no sacaron lo mejor de ti, ¿verdad?', 0),
(@ID, 'esMX', 'Entonces, ¿todavía tienes suerte? Jaja, esos ogros todavía no sacaron lo mejor de ti, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí, esto es todo. ¡Ahh! Si hubiera sabido que realmente ibas a salir y luchar contra esos ogros, te habría dado una lista de cosas para conseguir en lugar de sólo esta. Pero, no estás aquí haciendo negocios por mí, ¿verdad?$B$BUn trato es un trato; Jordan quería un envío de mi aleación y eso es lo que va a conseguir.$B$BSalúdalo de mi parte y ten cuidado, $c.', 0),
(@ID, 'esMX', 'Sí, sí, esto es todo. ¡Ahh! Si hubiera sabido que realmente ibas a salir y luchar contra esos ogros, te habría dado una lista de cosas para conseguir en lugar de sólo esta. Pero, no estás aquí haciendo negocios por mí, ¿verdad?$B$BUn trato es un trato; Jordan quería un envío de mi aleación y eso es lo que va a conseguir.$B$BSalúdalo de mi parte y ten cuidado, $c.', 0);
-- 256 SE BUSCA: Chok'sul
-- https://es.classic.wowhead.com/quest=256
SET @ID := 256;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Necesitas algo?', 0),
(@ID, 'esMX', '¿Sí? ¿Necesitas algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puaj! ¿Qué es eso?$B$BPor la Luz, ¿es la cabeza del ogro? ¡Excelente! Ten la recompensa y gracias en nombre de Thelsamar.', 0),
(@ID, 'esMX', '¡Puaj! ¿Qué es eso?$B$BPor la Luz, ¿es la cabeza del ogro? ¡Excelente! Ten la recompensa y gracias en nombre de Thelsamar.', 0);
-- 436 La excavación de Vetaferro
-- https://es.classic.wowhead.com/quest=436
SET @ID := 436;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que por qué hay un retraso?$B$BVetaferro está preparando el informe, pero ya te digo yo lo que causa el retraso:$B$B¡Los troggs!', 0),
(@ID, 'esMX', '¿Que por qué hay un retraso?$B$BVetaferro está preparando el informe, pero ya te digo yo lo que causa el retraso:$B$B¡Los troggs!', 0);
-- 298 Un informe sobre el avance de la excavación
-- https://es.classic.wowhead.com/quest=298
SET @ID := 298;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes el informe? ¡Excelente!', 0),
(@ID, 'esMX', '¿Me traes el informe? ¡Excelente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me pregunto si Vetaferro quiere la pólvora para la excavación o para luchar contra los troggs...$B$B¡Ambos usos me parecen bien!$B$BLo raro es que le mandé un cargamento hace unas semanas... ¿Dónde habrá ido a parar?', 0),
(@ID, 'esMX', 'Me pregunto si Vetaferro quiere la pólvora para la excavación o para luchar contra los troggs...$B$B¡Ambos usos me parecen bien!$B$BLo raro es que le mandé un cargamento hace unas semanas... ¿Dónde habrá ido a parar?', 0);
-- 738 Encontrar a Agmond
-- https://es.classic.wowhead.com/quest=738
SET @ID := 738;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este esqueleto debe de ser lo que queda del desafortunado Agmond. Su cuerpo está destrozado y han limpiado sus huesos.', 0),
(@ID, 'esMX', 'Este esqueleto debe de ser lo que queda del desafortunado Agmond. Su cuerpo está destrozado y han limpiado sus huesos.', 0);
-- 297 Recoger ídolos
-- https://es.classic.wowhead.com/quest=297
SET @ID := 297;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes los ídolos? Tengo que estudiarlos y enviar un informe a Forjaz.', 0),
(@ID, 'esMX', '¿Me traes los ídolos? Tengo que estudiarlos y enviar un informe a Forjaz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n!$B$BY no parece que te hayan machacado mucho... Tú prometes.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n!$B$BY no parece que te hayan machacado mucho... Tú prometes.', 0);
-- 2038 Suministros de Bingles
-- https://es.classic.wowhead.com/quest=2038
SET @ID := 2038;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¡¿Dónde están mis cosas?!', 0),
(@ID, 'esMX', '¡$n! ¡¿Dónde están mis cosas?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos has prestado un gran servicio, $n. ¡Esos troggs se van a enterar de lo que valen los gnomos de Gnomeregan!', 0),
(@ID, 'esMX', 'Nos has prestado un gran servicio, $n. ¡Esos troggs se van a enterar de lo que valen los gnomos de Gnomeregan!', 0);
-- 301 Informe a Forjaz
-- https://es.classic.wowhead.com/quest=301
SET @ID := 301;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A los Pico Tormenta no nos gusta perder el tiempo, $c. Espero que lo que tengas que decir merezca la pena.', 0),
(@ID, 'esMX', 'A los Pico Tormenta no nos gusta perder el tiempo, $c. Espero que lo que tengas que decir merezca la pena.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maldito sea Vetaferro! Le envié un cargamento de pólvora hace semanas y no lo menciona en el informe.$B$B¿Dónde está la pólvora?', 0),
(@ID, 'esMX', '¡Maldito sea Vetaferro! Le envié un cargamento de pólvora hace semanas y no lo menciona en el informe.$B$B¿Dónde está la pólvora?', 0);
-- 1338 Un pedido de Pico Tormenta
-- https://es.classic.wowhead.com/quest=1338
SET @ID := 1338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una carta de tierras enanas? No sé quién me escribirá de tan al norte...$B$BA ver, déjame ese pedido.', 0),
(@ID, 'esMX', '¿Una carta de tierras enanas? No sé quién me escribirá de tan al norte...$B$BA ver, déjame ese pedido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un pedido de Pico Tormenta... Una de las mejores familias de enanos y también una de las más ricas.$B$BGracias, $n. Esta tarde me pondré con el escudo.', 0),
(@ID, 'esMX', 'Ah, un pedido de Pico Tormenta... Una de las mejores familias de enanos y también una de las más ricas.$B$BGracias, $n. Esta tarde me pondré con el escudo.', 0);
-- 307 Zarpas asquerosas
-- https://es.classic.wowhead.com/quest=307
SET @ID := 307;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el equipamiento de minero, $n?', 0),
(@ID, 'esMX', '¿Traes el equipamiento de minero, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Había muchos kobolds? A ver si desaparecen pronto... Me pongo malo de pensar que andan por nuestra mina.', 0),
(@ID, 'esMX', '¿Había muchos kobolds? A ver si desaparecen pronto... Me pongo malo de pensar que andan por nuestra mina.', 0);

-- 455 El asedio de Algaz
-- https://es.classic.wowhead.com/quest=455
SET @ID := 455;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de Loch Modan? ¿Cómo es la situación con los orcos en la Puerta de Algaz?', 0),
(@ID, 'esMX', '¿Vienes de Loch Modan? ¿Cómo es la situación con los orcos en la Puerta de Algaz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tu informe está lleno de malas noticias!$B$BVeo que los Faucedraco están avanzando con fuerza en Algaz. Normalmente los Faucedraco se quedan escondidos en las colinas. Es un misterio qué les hizo avanzar hacia Algaz...$B$BGracias, $n. Seguramente necesitaremos tu ayuda para combatir a esos orcos.', 0),
(@ID, 'esMX', '¡Tu informe está lleno de malas noticias!$B$BVeo que los Faucedraco están avanzando con fuerza en Algaz. Normalmente los Faucedraco se quedan escondidos en las colinas. Es un misterio qué les hizo avanzar hacia Algaz...$B$BGracias, $n. Seguramente necesitaremos tu ayuda para combatir a esos orcos.', 0);
-- 419 El piloto perdido
-- https://es.classic.wowhead.com/quest=419
SET @ID := 419;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encuentras el cadáver de un enano. Masacrado, congelado y saqueado por los carroñeros de la montaña. Aprieta con la mano un libro que contiene anotaciones garabateadas por Mori Hildelve. El cuerpo está envuelto en un jubón de brigadier que aún está en perfectas condiciones.$B$BEste escenario truculento es seguramente aquel en el que el piloto de máquina de asedio perdió la vida.', 0),
(@ID, 'esMX', 'Encuentras el cadáver de un enano. Masacrado, congelado y saqueado por los carroñeros de la montaña. Aprieta con la mano un libro que contiene anotaciones garabateadas por Mori Hildelve. El cuerpo está envuelto en un jubón de brigadier que aún está en perfectas condiciones.$B$BEste escenario truculento es seguramente aquel en el que el piloto de máquina de asedio perdió la vida.', 0);
-- 417 Vengar al piloto
-- https://es.classic.wowhead.com/quest=417
SET @ID := 417;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Tienes noticias de mi amigo Hildelve?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Tienes noticias de mi amigo Hildelve?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son malas noticias: Hildelve era un buen amigo. Me habría gustado estar allí cuando encontraste a la bestia: ¡Sarnagarra!$B$BGracias, $n. Los pilotos de la Brigada de asedio de Forjaz recordarán tu hazaña.', 0),
(@ID, 'esMX', 'Estas son malas noticias: Hildelve era un buen amigo. Me habría gustado estar allí cuando encontraste a la bestia: ¡Sarnagarra!$B$BGracias, $n. Los pilotos de la Brigada de asedio de Forjaz recordarán tu hazaña.', 0);
-- 414 Cerveza negra para Kadrell
-- https://es.classic.wowhead.com/quest=414
SET @ID := 414;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¡Bienvenido a Thelsamar!', 0),
(@ID, 'esMX', 'Saludos, $c. ¡Bienvenido a Thelsamar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A ver, deja que pruebe...$B$B¡Por la barba de Magni! ¡Esta cosa te hace girar la cabeza! Y oye, te hace sentir como más ligero...$B$B¡Seguro que puedo volar!', 0),
(@ID, 'esMX', 'A ver, deja que pruebe...$B$B¡Por la barba de Magni! ¡Esta cosa te hace girar la cabeza! Y oye, te hace sentir como más ligero...$B$B¡Seguro que puedo volar!', 0);
-- 302 Pólvora para Vetaferro
-- https://es.classic.wowhead.com/quest=302
SET @ID := 302;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que Pico Tormenta quiere que te encargues tú del envío a Vetaferro?$B$BPor mí bien, pero hace apenas un rato que se lo llevó Huldar con los porteadores, Miran y Saean.', 0),
(@ID, 'esMX', '¿Que Pico Tormenta quiere que te encargues tú del envío a Vetaferro?$B$BPor mí bien, pero hace apenas un rato que se lo llevó Huldar con los porteadores, Miran y Saean.', 0);
-- 2398 Los enanos desaparecidos
-- https://es.classic.wowhead.com/quest=2398
SET @ID := 2398;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que aparecieras. ¡Temía perder la apuesta que hice con Olaf!$B$BÉl apostó que su barba le crecería hasta las rodillas antes de que alguien viniera a buscarnos. Aquí estás y, como puedes observar, ¡a la barba de Olaf aún le queda un buen trecho para llegar hasta sus rodillas!$B$BGracias, $n. Repartiré las ganancias contigo.', 0),
(@ID, 'esMX', 'Ya era hora de que aparecieras. ¡Temía perder la apuesta que hice con Olaf!$B$BÉl apostó que su barba le crecería hasta las rodillas antes de que alguien viniera a buscarnos. Aquí estás y, como puedes observar, ¡a la barba de Olaf aún le queda un buen trecho para llegar hasta sus rodillas!$B$BGracias, $n. Repartiré las ganancias contigo.', 0);
-- 1360 Los tesoros reclamados
-- https://es.classic.wowhead.com/quest=1360
SET @ID := 1360;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿conseguiste recuperar mi posesión de mi cofre?', 0),
(@ID, 'esMX', 'Bueno, ¿conseguiste recuperar mi posesión de mi cofre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! Te lo agradezco mucho.$B$BAlgunos enanos aman el brillo del metal, otros el resplandor de las gemas... ¡Pero un Brazorrecio tiene sus reliquias personales!', 0),
(@ID, 'esMX', '¡Por fin! Te lo agradezco mucho.$B$BAlgunos enanos aman el brillo del metal, otros el resplandor de las gemas... ¡Pero un Brazorrecio tiene sus reliquias personales!', 0);
-- 2500 Componentes de Tierras Inhóspitas
-- https://es.classic.wowhead.com/quest=2500
SET @ID := 2500;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes lo que te pedí? No te pagaré hasta que me des los ingredientes.', 0),
(@ID, 'esMX', '¿Me traes lo que te pedí? No te pagaré hasta que me des los ingredientes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n; con esto ya tengo para una temporada. Ten, tu recompensa.$B$BY tengo otro trabajo para ti, si te interesa. Lo que busco está en la excavación de Uldaman y no es fácil de conseguir, pero te recompensaré bien.$B$BY con algo más tentador que las monedas, ¿qué me dices?', 0),
(@ID, 'esMX', 'Buen trabajo, $n; con esto ya tengo para una temporada. Ten, tu recompensa.$B$BY tengo otro trabajo para ti, si te interesa. Lo que busco está en la excavación de Uldaman y no es fácil de conseguir, pero te recompensaré bien.$B$BY con algo más tentador que las monedas, ¿qué me dices?', 0);
-- 273 Aprovisionar la excavación
-- https://es.classic.wowhead.com/quest=273
SET @ID := 273;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Malditos Hierro Negro...!$B$BY que Saean esté conchabado con ellos... Mira que hemos trabajado juntos un año y no me había percatado de nada.$B$BBah, qué más da.', 0),
(@ID, 'esMX', '¡Malditos Hierro Negro...!$B$BY que Saean esté conchabado con ellos... Mira que hemos trabajado juntos un año y no me había percatado de nada.$B$BBah, qué más da.', 0);
-- 454 Tras la emboscada
-- https://es.classic.wowhead.com/quest=454
SET @ID := 454;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c.$B$B¿Tú vas a ser mi escolta? Me alegro, todo este asunto de los Hierro Negro me tiene un poco nervioso.$B$BBueno, voy a acabar de prepararme; ven a hablar conmigo cuando quieras que salgamos.', 0),
(@ID, 'esMX', 'Hola, $c.$B$B¿Tú vas a ser mi escolta? Me alegro, todo este asunto de los Hierro Negro me tiene un poco nervioso.$B$BBueno, voy a acabar de prepararme; ven a hablar conmigo cuando quieras que salgamos.', 0);
-- 309 Proteger el envío
-- https://es.classic.wowhead.com/quest=309
SET @ID := 309;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin, gracias a la Luz, la pólvora ha llegado! Pero eso que los Hierro Negro tengan ayuda interna para conseguir material es muy inquietante.$B$BPero no soy yo quien debe ocuparse de eso; yo voy a ocuparme de la pólvora.', 0),
(@ID, 'esMX', '¡Por fin, gracias a la Luz, la pólvora ha llegado! Pero eso que los Hierro Negro tengan ayuda interna para conseguir material es muy inquietante.$B$BPero no soy yo quien debe ocuparse de eso; yo voy a ocuparme de la pólvora.', 0);
-- 2240 La cámara oculta
-- https://es.classic.wowhead.com/quest=2240
SET @ID := 2240;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que informar?', 0),
(@ID, 'esMX', '¿Tienes algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto la cámara de Khaz\'mul? ¡No puedo creerlo! Baelog estaba seguro de su existencia pero yo he de reconocer que tenía mis dudas.$B$BGracias, $n. Con un poco de suerte, tu hallazgo incitará a nuestros líderes a seguir luchando por recuperar Uldaman. Y, si algún día vuelve a estar bajo el control de Forjaz, ¡los secretos de la cámara de Khaz\'mul serán nuestros!', 0),
(@ID, 'esMX', '¿Has visto la cámara de Khaz\'mul? ¡No puedo creerlo! Baelog estaba seguro de su existencia pero yo he de reconocer que tenía mis dudas.$B$BGracias, $n. Con un poco de suerte, tu hallazgo incitará a nuestros líderes a seguir luchando por recuperar Uldaman. Y, si algún día vuelve a estar bajo el control de Forjaz, ¡los secretos de la cámara de Khaz\'mul serán nuestros!', 0);
-- 250 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=250
SET @ID := 250;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En el barril de aspecto sospechoso hay unos polvos de olor extraño.', 0),
(@ID, 'esMX', 'En el barril de aspecto sospechoso hay unos polvos de olor extraño.', 0);
-- 199 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=199
SET @ID := 199;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste alguna pista, $n?', 0),
(@ID, 'esMX', '¿Encontraste alguna pista, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto tiene muy mala pinta!', 0),
(@ID, 'esMX', '¡Esto tiene muy mala pinta!', 0);
-- 161 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=161
SET @ID := 161;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Decías algo? No oigo nada, me pitan los oídos. ¿Qué es eso que me traes?', 0),
(@ID, 'esMX', '¿Decías algo? No oigo nada, me pitan los oídos. ¿Qué es eso que me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, Hinderweir tiene motivos para preocuparse.', 0),
(@ID, 'esMX', 'Sí, Hinderweir tiene motivos para preocuparse.', 0);
-- 385 La caza de crocoliscos
-- https://es.classic.wowhead.com/quest=385
SET @ID := 385;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te he contado lo del croco que casi se me come la mano? Tenía unos dientes como puñales, así... Pero le bloqueé la mandíbula con el cuchillo. Creo que todavía lo tengo por aquí...', 0),
(@ID, 'esMX', '¿Te he contado lo del croco que casi se me come la mano? Tenía unos dientes como puñales, así... Pero le bloqueé la mandíbula con el cuchillo. Creo que todavía lo tengo por aquí...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Esto es de excelente calidad.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Esto es de excelente calidad.', 0);
-- 257 La fanfarronada de un cazador
-- https://es.classic.wowhead.com/quest=257
SET @ID := 257;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sin suerte? No te sientas mal, $n...$B$BNo todo el mundo puede ser yo.', 0),
(@ID, 'esMX', '¿Sin suerte? No te sientas mal, $n...$B$BNo todo el mundo puede ser yo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que lo has conseguido?$B$BBah, tampoco hay para tanto; hasta un crío con un arco de juguete podría matar a estas bestezuelas. Y no te emociones matando águilas ratoneras, que no es cuestión de que se extingan.$B$BBueno, pues... En fin, Daryl el Audaz siempre cumple su palabra.', 0),
(@ID, 'esMX', '¿Que lo has conseguido?$B$BBah, tampoco hay para tanto; hasta un crío con un arco de juguete podría matar a estas bestezuelas. Y no te emociones matando águilas ratoneras, que no es cuestión de que se extingan.$B$BBueno, pues... En fin, Daryl el Audaz siempre cumple su palabra.', 0);
-- 258 El reto de un cazador
-- https://es.classic.wowhead.com/quest=258
SET @ID := 258;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es natural sentir lástima por ti mismo cuando te lo muestra alguien lo $gnuevo:nueva; que eres en este mundo. No deberías sentirte mal, $n.$B$B¿Hm? ¿Entendí mal tu nombre?', 0),
(@ID, 'esMX', 'Es natural sentir lástima por ti mismo cuando te lo muestra alguien lo $gnuevo:nueva; que eres en este mundo. No deberías sentirte mal, $n.$B$B¿Hm? ¿Entendí mal tu nombre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esos jabalís te han dejado para el arrastre, ¿eh? No te preocupes, que no se lo diré a nadie; bastante mal lo estás pasando.$B$BAh, ¡que sí los has matado! Pues..., bueno, es normal. Era un juego de niños...$B$B¿Apuesta? ¿Qué apuesta?', 0),
(@ID, 'esMX', 'Esos jabalís te han dejado para el arrastre, ¿eh? No te preocupes, que no se lo diré a nadie; bastante mal lo estás pasando.$B$BAh, ¡que sí los has matado! Pues..., bueno, es normal. Era un juego de niños...$B$B¿Apuesta? ¿Qué apuesta?', 0);
-- 271 La venganza de Vyrin
-- https://es.wowhead.com/quest=271
-- https://wow-es.gamepedia.com/Misión:La venganza de Vyrin
SET @ID := 271;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás aquí, $n? ¿Qué tal la caza? ¡No te preocupes si no ha ido bien, ya irás mejorando!$B$BTampoco es que pudieras hacerlo peor que ahora...', 0),
(@ID, 'esMX', '¿Ya estás aquí, $n? ¿Qué tal la caza? ¡No te preocupes si no ha ido bien, ya irás mejorando!$B$BTampoco es que pudieras hacerlo peor que ahora...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué... Qué es esto? Parece una cabeza de oso.$B$B<Se toca la cicatriz sin darse cuenta.>$B$BInteresante. Pero claro, no puede ser aquel oso...$B$B<Se queda callado y empieza a temblar.>$B$B¡Llévatela! ¡Fuera de mi vista!', 0),
(@ID, 'esMX', '¿Qué... Qué es esto? Parece una cabeza de oso.$B$B<Se toca la cicatriz sin darse cuenta.>$B$BInteresante. Pero claro, no puede ser aquel oso...$B$B<Se queda callado y empieza a temblar.>$B$B¡Llévatela! ¡Fuera de mi vista!', 0);
-- 531 La venganza de Vyrin
-- https://es.classic.wowhead.com/quest=531
SET @ID := 531;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n, eso le enseñará! Dame la cabeza, ya me ocupo yo de ella.', 0),
(@ID, 'esMX', '¡Muy bien, $n, eso le enseñará! Dame la cabeza, ya me ocupo yo de ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. Llevaba tiempo buscando la revancha, ¡y lo hemos conseguido! Ten, te has ganado esto.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. Llevaba tiempo buscando la revancha, ¡y lo hemos conseguido! Ten, te has ganado esto.', 0);
-- 224 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=224
SET @ID := 224;
UPDATE `quest_template_locale` SET `Objectives` = 'El montaraz Pedernal, de Thelsamar, quiere que mates a 10 Troggs Rompecantos y 10 Exploradores Rompecantos.' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Loch Modan está sitiado, $n! Necesitamos que todos los miembros sanos de la Alianza ayuden a nuestra causa. ¿Has matado a 10 Troggs Rompecantos y 10 Exploradores Rompecantos?', 0),
(@ID, 'esMX', '¡Loch Modan está sitiado, $n! Necesitamos que todos los miembros sanos de la Alianza ayuden a nuestra causa. ¿Has matado a 10 Troggs Rompecantos y 10 Exploradores Rompecantos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Has demostrado un valor excepcional en combate; nos has ayudado mucho en nuestra lucha contra los troggs.$B$BSi quieres buscarte más aventuras, ve a hablar con el montaraz Gravagau; seguro que agradece la ayuda de alguien tan capaz como tú. Está en la torre.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Has demostrado un valor excepcional en combate; nos has ayudado mucho en nuestra lucha contra los troggs.$B$BSi quieres buscarte más aventuras, ve a hablar con el montaraz Gravagau; seguro que agradece la ayuda de alguien tan capaz como tú. Está en la torre.', 0);
-- 237 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=237
SET @ID := 237;
UPDATE `quest_template_locale` SET `Objectives` = 'El montaraz Gravagau, de la torre de vigilancia sur, quiere que mates a 10 Aplastacráneos Rompecantos y 10 Videntes Rompecantos. Luego ve a informarle.' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitamos más tiempo, $r. Tus órdenes son matar 10 Aplastacráneos Rompecantos y 10 Videntes Rompecantos. Mantener al enemigo bajo presión hasta que se nos unan refuerzos. Este no es momento para comportamientos inactivos.', 0),
(@ID, 'esMX', 'Necesitamos más tiempo, $r. Tus órdenes son matar 10 Aplastacráneos Rompecantos y 10 Videntes Rompecantos. Mantener al enemigo bajo presión hasta que se nos unan refuerzos. Este no es momento para comportamientos inactivos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $r.$B$BPero los refuerzos prometidos no han llegado; muchos de los nuestros yacen en el campo de batalla. Amargo es el dolor, pero debemos seguir adelante, por la Alianza.$B$BHabla con el montaraz Muroplof para que te informe de tu nuevo destino.', 0),
(@ID, 'esMX', 'Buen trabajo, $r.$B$BPero los refuerzos prometidos no han llegado; muchos de los nuestros yacen en el campo de batalla. Amargo es el dolor, pero debemos seguir adelante, por la Alianza.$B$BHabla con el montaraz Muroplof para que te informe de tu nuevo destino.', 0);

-- 263 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=263
SET @ID := 263;
UPDATE `quest_template_locale` SET `Details` = 'Los Montaraces me dicen que eres valiente y capaz, $n. Nos hace falta $gun:una; $r como tú por aquí. La situación con los Troggs no mejora. La reserva está en combate; estamos solos. Pero con tu experiencia como $c, la cosa va a cambiar.$B$BLiquida a 10 Chamanes Rompecantos y a 10 Cascahuesos Rompecantos.$B$BA ver si los Troggs aprenden a temer tu reputación, Mata-Troggs.', `Objectives` = 'El Montaraz Muroplof, de la torre de vigilancia sur, quiere que mates a 10 Chamanes Rompecantos y a 10 Cascahuesos Rompecantos.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De vuelta tan pronto? En caso de que no te haya quedado claro, necesitamos que mates a 10 Chamanes Rompecantos y 10 Rompehuesos Rompecantos, $N. ¡Ahora ve a buscarlos, Mata-Troggs!', 0),
(@ID, 'esMX', '¿De vuelta tan pronto? En caso de que no te haya quedado claro, necesitamos que mates a 10 Chamanes Rompecantos y 10 Rompehuesos Rompecantos, $N. ¡Ahora ve a buscarlos, Mata-Troggs!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo supe en cuanto te vi, $n. Sabía que Forjaz se enorgullecería de ti. Has servido bien al Rey Magni. Ahora que has demostrado ser $gun:una; ayudante leal del reino, quizás deberías hablar con el capitán para que te confíe más detalles.$B$BTe saludo, $n.', 0),
(@ID, 'esMX', 'Lo supe en cuanto te vi, $n. Sabía que Forjaz se enorgullecería de ti. Has servido bien al Rey Magni. Ahora que has demostrado ser $gun:una; ayudante leal del reino, quizás deberías hablar con el capitán para que te confíe más detalles.$B$BTe saludo, $n.', 0);
-- 217 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=217
SET @ID := 217;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Grawmug y sus dos guardias, Rechín y Camorrista, todavía están vivos. Tu misión no estará completa hasta que los 3 hayan muerto. El imperio enano cuenta contigo, $n.', 0),
(@ID, 'esMX', 'Grawmug y sus dos guardias, Rechín y Camorrista, todavía están vivos. Tu misión no estará completa hasta que los 3 hayan muerto. El imperio enano cuenta contigo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Gracias por eliminar a Gromug; ahora tenemos más posibilidades de erradicar a los troggs.', 0),
(@ID, 'esMX', '¡Excelente, $n! Gracias por eliminar a Gromug; ahora tenemos más posibilidades de erradicar a los troggs.', 0);
-- 314 La protección del rebaño
-- https://es.classic.wowhead.com/quest=314
SET @ID := 314;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vagash sigue aterrorizando al ganado! Ayúdanos, por favor, ¡mata a esa maldita bestia!', 0),
(@ID, 'esMX', '¡Vagash sigue aterrorizando al ganado! Ayúdanos, por favor, ¡mata a esa maldita bestia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien hecho! Veron se pondrá muy contento cuando oiga la noticia. Matar a Vagash no es tarea fácil. Imagino que un día combatirás en el frente de la Alianza, entre los hombres del rey Magni.', 0),
(@ID, 'esMX', '¡Muy bien hecho! Veron se pondrá muy contento cuando oiga la noticia. Matar a Vagash no es tarea fácil. Imagino que un día combatirás en el frente de la Alianza, entre los hombres del rey Magni.', 0);
-- 2160 Suministros para Tannok
-- https://es.classic.wowhead.com/quest=2160
SET @ID := 2160;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, sé $gbienvenido:bienvenida;! Venga, siéntate junto al fuego y entra en calor con una jarra de cerveza.', 0),
(@ID, 'esMX', '¡Eh, sé $gbienvenido:bienvenida;! Venga, siéntate junto al fuego y entra en calor con una jarra de cerveza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, por fin! ¡Los suministros! Empezaba a preocuparme. Hemos tenido pocas noticias de Yunquemar desde que los troggs se hicieron con el paso.$B$BGracias por traerme esto, $n. Te lo ruego, ponte $gcómodo:cómoda;. Debes de estar $gcansado:cansada; del viaje.', 0),
(@ID, 'esMX', '¡Ah, por fin! ¡Los suministros! Empezaba a preocuparme. Hemos tenido pocas noticias de Yunquemar desde que los troggs se hicieron con el paso.$B$BGracias por traerme esto, $n. Te lo ruego, ponte $gcómodo:cómoda;. Debes de estar $gcansado:cansada; del viaje.', 0);
-- 179 Los enanos modistos
-- https://es.classic.wowhead.com/quest=179
SET @ID := 179;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Los lobos te están dando problemillas? Ya sabes que tienes que evitar colmillos y patas y otras cosas afiladas, ¿verdad?', 0),
(@ID, 'esMX', '¿Qué? ¿Los lobos te están dando problemillas? Ya sabes que tienes que evitar colmillos y patas y otras cosas afiladas, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Estupendo. Esta carne de lobo me vendrá muy bien. Oh, no te preocupes, $n, no he olvidado mi parte del trato. Ten, alguno de estos debería valerte.', 0),
(@ID, 'esMX', '¡Ah! Estupendo. Esta carne de lobo me vendrá muy bien. Oh, no te preocupes, $n, no he olvidado mi parte del trato. Ten, alguno de estos debería valerte.', 0);
-- 233 Entrega de correo en el Valle de Crestanevada
-- https://es.classic.wowhead.com/quest=233
SET @ID := 233;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Sí? ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, llevo un tiempo esperando estas cartas...$B$BPor desgracia, no son todas para mí. Esta es para Grelin Barbablanca. No está muy lejos de aquí. Si quieres entregársela...', 0),
(@ID, 'esMX', 'Gracias, llevo un tiempo esperando estas cartas...$B$BPor desgracia, no son todas para mí. Esta es para Grelin Barbablanca. No está muy lejos de aquí. Si quieres entregársela...', 0);
-- 170 Una nueva amenaza
-- https://es.classic.wowhead.com/quest=170
SET @ID := 170;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenaces pequeños bichos, ¿no son?', 0),
(@ID, 'esMX', 'Tenaces pequeños bichos, ¿no son?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los problemas que hemos tenido aquí son una muestra de lo que está ocurriendo en el resto de nuestra tierra, ¡tendremos muchos problemas! Solo puedo esperar que el Rey y el Senado estén tomando medidas para acabar con la amenaza que los troggs representan.', 0),
(@ID, 'esMX', 'Si los problemas que hemos tenido aquí son una muestra de lo que está ocurriendo en el resto de nuestra tierra, ¡tendremos muchos problemas! Solo puedo esperar que el Rey y el Senado estén tomando medidas para acabar con la amenaza que los troggs representan.', 0);
-- 3361 Las penurias de un refugiado
-- https://es.classic.wowhead.com/quest=3361
SET @ID := 3361;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es terrible, $n, esta ciudad no es adecuada para individuos como yo. ¡Hay tantas criaturas horribles aquí como en Gnomeregan antes del accidente!$B$B¿Tienes mis pertenencias? Si no es así, quién sabe lo que los trols habrán hecho con ellas a esta altura...', 0),
(@ID, 'esMX', 'Esto es terrible, $n, esta ciudad no es adecuada para individuos como yo. ¡Hay tantas criaturas horribles aquí como en Gnomeregan antes del accidente!$B$B¿Tienes mis pertenencias? Si no es así, quién sabe lo que los trols habrán hecho con ellas a esta altura...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hurra, los has encontrado! Eres todo un salvador. Toma, no es mucho, pero acéptalo por los problemas que te he causado. ¡Gracias!', 0),
(@ID, 'esMX', '¡Hurra, los has encontrado! Eres todo un salvador. Toma, no es mucho, pero acéptalo por los problemas que te he causado. ¡Gracias!', 0);
-- 183 Cazador de jabalíes
-- https://es.classic.wowhead.com/quest=183
SET @ID := 183;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la cacería?', 0),
(@ID, 'esMX', '¿Cómo va la cacería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Ya puedo volver a mi caza diaria tranquilamente. Gracias, $n.', 0),
(@ID, 'esMX', '¡Fantástico! Ya puedo volver a mi caza diaria tranquilamente. Gracias, $n.', 0);
-- 234 Entrega de correo en el Valle de Crestanevada
-- https://es.classic.wowhead.com/quest=234
SET @ID := 234;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', '¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aah, excelente. Hace tiempo que no recibo noticias de Forjaz.', 0),
(@ID, 'esMX', 'Aah, excelente. Hace tiempo que no recibo noticias de Forjaz.', 0);
-- 182 La cueva de los trols
-- https://es.classic.wowhead.com/quest=182
SET @ID := 182;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por lo que he aprendido, estos trolls proceden del clan Peloescarcha. Me temo que no sé mucho más sobre ellos que pueda ser de utilidad para ti, $n.', 0),
(@ID, 'esMX', 'Por lo que he aprendido, estos trolls proceden del clan Peloescarcha. Me temo que no sé mucho más sobre ellos que pueda ser de utilidad para ti, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Argh! ¡Malditos trols, la Luz los maldiga!$B$B<Grelin respira profundamente y se calma... un poco.>$B$B¡Un grupo de ellos vino por la noche y se llevó mi diario! Sabía que no debía confiar en ese bueno para nada de...', 0),
(@ID, 'esMX', '¡Argh! ¡Malditos trols, la Luz los maldiga!$B$B<Grelin respira profundamente y se calma... un poco.>$B$B¡Un grupo de ellos vino por la noche y se llevó mi diario! Sabía que no debía confiar en ese bueno para nada de...', 0);
-- 3364 Entrega una infusión de albaza hirviendo
-- https://es.classic.wowhead.com/quest=3364
SET @ID := 3364;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, soy Durnan Cortapieles. ¿Tienes algo para mí?', 0),
(@ID, 'esMX', 'Sí, soy Durnan Cortapieles. ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, qué bien me va a sentar esto! Deja que me tome un descansito mientras disfruto esta infusión de albaza hirviendo.', 0),
(@ID, 'esMX', '¡Oh, qué bien me va a sentar esto! Deja que me tome un descansito mientras disfruto esta infusión de albaza hirviendo.', 0);
-- 218 El diario robado
-- https://es.classic.wowhead.com/quest=218
SET @ID := 218;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Estoy muy agradecido por recuperar mi cuaderno. Bueno, parece que la situación con los trols aquí en el Valle de Crestanevada está bajo control y no hay por qué preocuparse.$B$BDespués de incluir los últimos detalles en mi informe, necesitaré que alguien se lo lleve a mi hermano Senir.', 0),
(@ID, 'esMX', '¡Excelente, $n! Estoy muy agradecido por recuperar mi cuaderno. Bueno, parece que la situación con los trols aquí en el Valle de Crestanevada está bajo control y no hay por qué preocuparse.$B$BDespués de incluir los últimos detalles en mi informe, necesitaré que alguien se lo lleve a mi hermano Senir.', 0);
-- 282 Las observaciones de Senir
-- https://es.classic.wowhead.com/quest=282
SET @ID := 282;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! Ten cuidado, $n, el túnel de Dun Morogh está infestado de troggs. No es seguro atravesarlo.$B$BSi no tienes asuntos urgentes en Dun Morogh, te aconsejo que te quedes en Yunquemar hasta que el túnel sea más seguro.', 0),
(@ID, 'esMX', '¡Saludos! Ten cuidado, $n, el túnel de Dun Morogh está infestado de troggs. No es seguro atravesarlo.$B$BSi no tienes asuntos urgentes en Dun Morogh, te aconsejo que te quedes en Yunquemar hasta que el túnel sea más seguro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, bueno, si Barbablanca te ha mandado a Dun Morogh para asuntos importantes, yo no puedo detenerte, ¿no?$B$BDeja que te dé algún consejo e indicaciones.', 0),
(@ID, 'esMX', 'Mm, bueno, si Barbablanca te ha mandado a Dun Morogh para asuntos importantes, yo no puedo detenerte, ¿no?$B$BDeja que te dé algún consejo e indicaciones.', 0);
-- 3365 Devuelve la jarra
-- https://es.classic.wowhead.com/quest=3365
SET @ID := 3365;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que la infusión de albaza le llegara caliente a Durnan! ¿Te has acordado de traerme mi taza?', 0),
(@ID, 'esMX', '¡Espero que la infusión de albaza le llegara caliente a Durnan! ¿Te has acordado de traerme mi taza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Te sorprendería saber la cantidad de mensajeros que conozco que olvidan hacer algo tan simple como devolver una taza. ¡Y las tazas no crecen en los árboles, o eso dicen!$B$BAquí tienes algo para premiar tu esfuerzo. Y gracias de nuevo por tu ayuda.', 0),
(@ID, 'esMX', '¡Excelente, $n! Te sorprendería saber la cantidad de mensajeros que conozco que olvidan hacer algo tan simple como devolver una taza. ¡Y las tazas no crecen en los árboles, o eso dicen!$B$BAquí tienes algo para premiar tu esfuerzo. Y gracias de nuevo por tu ayuda.', 0);
-- 420 Las observaciones de Senir
-- https://es.classic.wowhead.com/quest=420
SET @ID := 420;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo estás? ¿Te apetece tomarte algo conmigo? No es que haya mucho más que hacer con este frío.', 0),
(@ID, 'esMX', '¿Cómo estás? ¿Te apetece tomarte algo conmigo? No es que haya mucho más que hacer con este frío.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso? Ah, el informe de mi hermano. Mmm...$B$BLe dije que moderara el uso del nombre del Rey, pero no me ha hecho caso. Supongo que no hará daño a nadie, pero sí que va a erizar alguna que otra pluma en el Senado. ¡Y no vendrá nada mal, no creas! ¡Ja, ja!$B$BEn fin, supongo que yo debería enviar mi informe a Forjaz también, pero la verdad es que voy un poco atrasado. Maldito frío.$B$BSi te interesa, más tarde podría tener trabajo para ti.', 0),
(@ID, 'esMX', '¿Qué es eso? Ah, el informe de mi hermano. Mmm...$B$BLe dije que moderara el uso del nombre del Rey, pero no me ha hecho caso. Supongo que no hará daño a nadie, pero sí que va a erizar alguna que otra pluma en el Senado. ¡Y no vendrá nada mal, no creas! ¡Ja, ja!$B$BEn fin, supongo que yo debería enviar mi informe a Forjaz también, pero la verdad es que voy un poco atrasado. Maldito frío.$B$BSi te interesa, más tarde podría tener trabajo para ti.', 0);
-- 287 Poblado Peloescarcha
-- https://es.classic.wowhead.com/quest=287
SET @ID := 287;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No puedes encontrarlo? ¡Mis instrucciones fueron muy claras! No tenemos mucho tiempo, ¡hay que darse prisa! No regreses hasta que hayas encontrado la cueva.', 0),
(@ID, 'esMX', '¿No puedes encontrarlo? ¡Mis instrucciones fueron muy claras! No tenemos mucho tiempo, ¡hay que darse prisa! No regreses hasta que hayas encontrado la cueva.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n! Pensé que no tendrías problemas para encontrar el lugar, doy excelentes indicaciones, ya me entiendes...$B$BDeja que acabe mi informe.', 0),
(@ID, 'esMX', '¡Ah, $n! Pensé que no tendrías problemas para encontrar el lugar, doy excelentes indicaciones, ya me entiendes...$B$BDeja que acabe mi informe.', 0);
-- 291 Los informes
-- https://es.classic.wowhead.com/quest=291
SET @ID := 291;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya... Menos mal que dije a los guardias que no dejaran pasar mendigos... ¿Y bien? ¿Qué quieres? Habla rápido.', 0),
(@ID, 'esMX', 'Vaya... Menos mal que dije a los guardias que no dejaran pasar mendigos... ¿Y bien? ¿Qué quieres? Habla rápido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Examina rápidamente el informe.>$B$B¡¿Autoridad del REY?! ¡Magni ha perdido totalmente la cabeza! Y ese maldito Barbablanca... Se ha encargado del asunto en persona, ¿eh? Al Senado no le gustará oír esto. Ni una pizca.$B$B¿Pero aún estás aquí? ¡Vete antes de que llame a la guardia!', 0),
(@ID, 'esMX', '<Examina rápidamente el informe.>$B$B¡¿Autoridad del REY?! ¡Magni ha perdido totalmente la cabeza! Y ese maldito Barbablanca... Se ha encargado del asunto en persona, ¿eh? Al Senado no le gustará oír esto. Ni una pizca.$B$B¿Pero aún estás aquí? ¡Vete antes de que llame a la guardia!', 0);
-- 469 Entrega cotidiana
-- https://es.classic.wowhead.com/quest=469
SET @ID := 469;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Estarías interesado en un par de botas? ¿Quizás en algunas pieles recién curtidas?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Estarías interesado en un par de botas? ¿Quizás en algunas pieles recién curtidas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ummm... esto es de parte de Einar, ¿verdad? No ha venido a darme sus pieles en persona desde hace casi una semana. ¡Tendrá otra vez problemas con su mujer!$B$BMe parece que tendré que mandar a mi esposa a hablar con Shida...', 0),
(@ID, 'esMX', 'Ummm... esto es de parte de Einar, ¿verdad? No ha venido a darme sus pieles en persona desde hace casi una semana. ¡Tendrá otra vez problemas con su mujer!$B$BMe parece que tendré que mandar a mi esposa a hablar con Shida...', 0);

-- 274 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=274
SET @ID := 274;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te ha dado Ashlan para mí?', 0),
(@ID, 'esMX', '¿Qué te ha dado Ashlan para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un coloide desactivador para polvo de seforio?', 0),
(@ID, 'esMX', '¿Un coloide desactivador para polvo de seforio?', 0);
-- 631 El Puente Thandol
-- https://es.classic.wowhead.com/quest=631
SET @ID := 631;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Registras el diminuto cadáver enano. Grabado en el yelmo puedes leer claramente: Ebenezer Herrumbra.', 0),
(@ID, 'esMX', 'Registras el diminuto cadáver enano. Grabado en el yelmo puedes leer claramente: Ebenezer Herrumbra.', 0);
-- 304 Una misión hedionda
-- https://es.classic.wowhead.com/quest=304
SET @ID := 304;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has localizado a Balgaras el Hediondo, $c? Se nos ha estado escapando demasiado tiempo.', 0),
(@ID, 'esMX', '¿Ya has localizado a Balgaras el Hediondo, $c? Se nos ha estado escapando demasiado tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Balgaras el Hediondo por fin está muerto. Aunque su muerte no devolverá la vida a todos los enanos inocentes que murieron innecesariamente a sus manos, ayudará a devolver la paz a los que sobrevivieron. Con Balgaras muerto, debería ser fácil acabar con el resto de escoria Hierro Negro. Ahora debemos exterminarlos antes de que sea enviado un nuevo líder.$B$BLo has hecho bien, $c.', 0),
(@ID, 'esMX', 'Balgaras el Hediondo por fin está muerto. Aunque su muerte no devolverá la vida a todos los enanos inocentes que murieron innecesariamente a sus manos, ayudará a devolver la paz a los que sobrevivieron. Con Balgaras muerto, debería ser fácil acabar con el resto de escoria Hierro Negro. Ahora debemos exterminarlos antes de que sea enviado un nuevo líder.$B$BLo has hecho bien, $c.', 0);
-- 303 La guerra contra los Hierro Negro
-- https://es.classic.wowhead.com/quest=303
SET @ID := 303;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Roggo no ha podido contactar con las fuerzas de reserva. Necesitamos presión ofensiva sobre ese campamento Hierro Negro, $c. ¡Ahora vuelve y cumple tu deber con el rey Magni!', 0),
(@ID, 'esMX', 'Roggo no ha podido contactar con las fuerzas de reserva. Necesitamos presión ofensiva sobre ese campamento Hierro Negro, $c. ¡Ahora vuelve y cumple tu deber con el rey Magni!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cumples bien tus órdenes, $c. Has demostrado ser $gun:una; valiente soldado y $gun:una; leal $gservidor:servidora; del rey Magni, ¡te rindo homenaje! Gracias a la presión que ejerciste sobre el campamento Hierro Negro tenemos ahora una oportunidad para expulsarlos definitivamente de nuestras tierras... si tan solo aparecieran las condenadas fuerzas de reserva...', 0),
(@ID, 'esMX', 'Cumples bien tus órdenes, $c. Has demostrado ser $gun:una; valiente soldado y $gun:una; leal $gservidor:servidora; del rey Magni, ¡te rindo homenaje! Gracias a la presión que ejerciste sobre el campamento Hierro Negro tenemos ahora una oportunidad para expulsarlos definitivamente de nuestras tierras... si tan solo aparecieran las condenadas fuerzas de reserva...', 0);
-- 378 La furia mora en las profundidades
-- https://es.classic.wowhead.com/quest=378
SET @ID := 378;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No dejaré que la estúpida burocracia humana interfiera en los asuntos de los enanos, $n. Se ha demostrado que Kam Furiahonda conspiró en el ataque al Puente Thandol. Las gentes del rey Magni perdieron sus vidas por las mentiras y la traición de Furiahonda. Puede que los humanos se hayan quedado satisfechos dejando que Furiahonda se pudra en Las Mazmorras, pero yo no dormiré tranquilo hasta que Furiahonda sea asesinado.', 0),
(@ID, 'esMX', 'No dejaré que la estúpida burocracia humana interfiera en los asuntos de los enanos, $n. Se ha demostrado que Kam Furiahonda conspiró en el ataque al Puente Thandol. Las gentes del rey Magni perdieron sus vidas por las mentiras y la traición de Furiahonda. Puede que los humanos se hayan quedado satisfechos dejando que Furiahonda se pudra en Las Mazmorras, pero yo no dormiré tranquilo hasta que Furiahonda sea asesinado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que Kam Furiahonda por fin supo lo que es mirar a la muerte a los ojos? Bien. Esa cobarde escoria Hierro Negro lo tenía bien merecido. Lo has hecho bien, $c. Las víctimas del ataque al Puente Thandol fueron unas víctimas más de un mundo torturado por la guerra y el caos. Sus familias tendrán la paz de saber que Furiahonda recibió el castigo que merecía. La muerte del hermano de Largatrenza ha sido vengada.', 0),
(@ID, 'esMX', '¿Así que Kam Furiahonda por fin supo lo que es mirar a la muerte a los ojos? Bien. Esa cobarde escoria Hierro Negro lo tenía bien merecido. Lo has hecho bien, $c. Las víctimas del ataque al Puente Thandol fueron unas víctimas más de un mundo torturado por la guerra y el caos. Sus familias tendrán la paz de saber que Furiahonda recibió el castigo que merecía. La muerte del hermano de Largatrenza ha sido vengada.', 0);
-- 632 El Puente Thandol
-- https://es.classic.wowhead.com/quest=632
SET @ID := 632;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna señal de Herrumbra, $n?', 0),
(@ID, 'esMX', '¿Alguna señal de Herrumbra, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, no puede ser, son malas noticias...', 0),
(@ID, 'esMX', 'Oh, no puede ser, son malas noticias...', 0);
-- 633 El Puente Thandol
-- https://es.classic.wowhead.com/quest=633
SET @ID := 633;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El alijo de explosivos debe ser destruido!', 0),
(@ID, 'esMX', '¡El alijo de explosivos debe ser destruido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo que queda del puente está a salvo! Has prestado un gran servicio al rey Magni y a las gentes de Khaz Modan.$B$BSi tan solo pudiéramos resistir hasta la llegada de los refuerzos...', 0),
(@ID, 'esMX', '¡Lo que queda del puente está a salvo! Has prestado un gran servicio al rey Magni y a las gentes de Khaz Modan.$B$BSi tan solo pudiéramos resistir hasta la llegada de los refuerzos...', 0);
-- 647 Licor de luna de Mackreel
-- https://es.classic.wowhead.com/quest=647
SET @ID := 647;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuál es la buena noticia, $r?', 0),
(@ID, 'esMX', '¿Cuál es la buena noticia, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, nada como licor de luna de Nubos MacKreel para calentarte en un día fresco! Y aquí estaba pensando que el mal bicho volvería a estar atrasado en sus pagos. ¡Gracias amigo! ¡Muchas gracias de hecho!', 0),
(@ID, 'esMX', '¡Ah, nada como licor de luna de Nubos MacKreel para calentarte en un día fresco! Y aquí estaba pensando que el mal bicho volvería a estar atrasado en sus pagos. ¡Gracias amigo! ¡Muchas gracias de hecho!', 0);
-- 634 Petición a la Alianza
-- https://es.classic.wowhead.com/quest=634
SET @ID := 634;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todas mis condolencias para Largatrenza y sus valientes soldados. Las noticias del Puente Thandol y de la caída de Dun Modr son un duro golpe.$B$BPero Stromgarde ha caído, de ahí nuestra presencia aquí, en el Refugio de la Zaga. Nos enfrentamos a la reconquista de nuestra propia ciudad.$B$BEl honor y el sentido del deber nos impiden abandonar las Tierras altas hasta que en Stromgarde vuelva a ondear el estandarte del Rey. Enviaré un mensaje a Largatrenza advirtiéndole de que está solo...', 0),
(@ID, 'esMX', 'Todas mis condolencias para Largatrenza y sus valientes soldados. Las noticias del Puente Thandol y de la caída de Dun Modr son un duro golpe.$B$BPero Stromgarde ha caído, de ahí nuestra presencia aquí, en el Refugio de la Zaga. Nos enfrentamos a la reconquista de nuestra propia ciudad.$B$BEl honor y el sentido del deber nos impiden abandonar las Tierras altas hasta que en Stromgarde vuelva a ondear el estandarte del Rey. Enviaré un mensaje a Largatrenza advirtiéndole de que está solo...', 0);
-- 472 La caída de Dun Modr
-- https://es.classic.wowhead.com/quest=472
SET @ID := 472;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué valiente $c envía un mensaje desde Menethil? Ah $n, te llaman.$B$BTraes algo de luz a una situación desesperada. Es una buena noticia que el joven Harlo sobreviviera. Al huir resultó gravemente herido. Apenas tuvimos tiempo para enviarle a lomos del único corcel que quedaba con vida de todo el regimiento.$B$BPero ahora nos enfrentamos a una situación muy peligrosa. Dun Modr ha caído y solo somos una sombra del gran regimiento que fuimos un día.', 0),
(@ID, 'esMX', '¿Qué valiente $c envía un mensaje desde Menethil? Ah $n, te llaman.$B$BTraes algo de luz a una situación desesperada. Es una buena noticia que el joven Harlo sobreviviera. Al huir resultó gravemente herido. Apenas tuvimos tiempo para enviarle a lomos del único corcel que quedaba con vida de todo el regimiento.$B$BPero ahora nos enfrentamos a una situación muy peligrosa. Dun Modr ha caído y solo somos una sombra del gran regimiento que fuimos un día.', 0);
-- 473 Preséntate ante el capitán Puñorrecio
-- https://es.classic.wowhead.com/quest=473
SET @ID := 473;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Valstag me ha informado de tus éxitos sobre los orcos Faucedraco en Dun Algaz. Eres $gun:una; $r de gran valor.$B$BY tengo una tarea para ti.', 0),
(@ID, 'esMX', '$n. Valstag me ha informado de tus éxitos sobre los orcos Faucedraco en Dun Algaz. Eres $gun:una; $r de gran valor.$B$BY tengo una tarea para ti.', 0);
-- 464 Estandartes de batalla
-- https://es.classic.wowhead.com/quest=464
SET @ID := 464;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has atacado ya el campamento Faucedraco?', 0),
(@ID, 'esMX', '¿Has atacado ya el campamento Faucedraco?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen combate, $n. Los Faucedraco ya no suponen la misma amenaza que cuando tenían dragones, pero siguen siendo unos duros oponentes.$B$BLos Faucedraco están liderados por Nek\'rosh, hijo de Nekros, su antiguo cabecilla. Nekros utilizó poderosa magia para domar a los dragones rojos, pero cuando la magia le falló... los dragones no estaban muy contentos.$B$BNekros fue asesinado y su hijo ha jurado venganza contra los dragones que acabaron con su padre.', 0),
(@ID, 'esMX', 'Buen combate, $n. Los Faucedraco ya no suponen la misma amenaza que cuando tenían dragones, pero siguen siendo unos duros oponentes.$B$BLos Faucedraco están liderados por Nek\'rosh, hijo de Nekros, su antiguo cabecilla. Nekros utilizó poderosa magia para domar a los dragones rojos, pero cuando la magia le falló... los dragones no estaban muy contentos.$B$BNekros fue asesinado y su hijo ha jurado venganza contra los dragones que acabaron con su padre.', 0);
-- 484 Piel de crocolisco joven
-- https://es.classic.wowhead.com/quest=484
SET @ID := 484;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿verdad? ¿Tienes mis pieles?', 0),
(@ID, 'esMX', '$n, ¿verdad? ¿Tienes mis pieles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un buen trabajo, $n. Estas pieles son espléndidas. Tendré que curtirlas lo antes posible. Oh, pero antes de hacerlo, tengo otro trabajo del que podrías encargarte.', 0),
(@ID, 'esMX', 'Has hecho un buen trabajo, $n. Estas pieles son espléndidas. Tendré que curtirlas lo antes posible. Oh, pero antes de hacerlo, tengo otro trabajo del que podrías encargarte.', 0);
-- 471 Deberes de aprendiz
-- https://es.classic.wowhead.com/quest=471
SET @ID := 471;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi aprendiz es como un hijo para mí. Le va a ser difícil vivir con una sola pierna.$B$BAh, $n, ¿qué tal va? ¿Tienes mis pieles?', 0),
(@ID, 'esMX', 'Mi aprendiz es como un hijo para mí. Le va a ser difícil vivir con una sola pierna.$B$BAh, $n, ¿qué tal va? ¿Tienes mis pieles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Umm... No creo que estés $ginteresado:interesada; en convertirte en mi aprendiz, ¿verdad?$B$B¡Ja! No, estoy bromeando. Eres demasiado mayor. Además por tu aspecto se diría que tienes otras ambiciones. Bueno, en cualquier caso, me has traído buenas pieles y me serán muy útiles.', 0),
(@ID, 'esMX', 'Umm... No creo que estés $ginteresado:interesada; en convertirte en mi aprendiz, ¿verdad?$B$B¡Ja! No, estoy bromeando. Eres demasiado mayor. Además por tu aspecto se diría que tienes otras ambiciones. Bueno, en cualquier caso, me has traído buenas pieles y me serán muy útiles.', 0);
-- 279 Zarpas de las profundidades
-- https://es.classic.wowhead.com/quest=279
SET @ID := 279;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros mercaderes no estarán a salvo hasta que nos libremos de Engullidor y de esos murlocs.', 0),
(@ID, 'esMX', 'Nuestros mercaderes no estarán a salvo hasta que nos libremos de Engullidor y de esos murlocs.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien hecho, $n.$B$BAcepta esto como pago por haber cumplido con tu contrato con los marinos mercantes.', 0),
(@ID, 'esMX', 'Ah, bien hecho, $n.$B$BAcepta esto como pago por haber cumplido con tu contrato con los marinos mercantes.', 0);
-- 1302 James Hyal
-- https://es.classic.wowhead.com/quest=1302
SET @ID := 1302;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'James Hyal, James Hyal... ¿Por qué me suena tan familiar?$B$B¡Claro! Por el incidente de la Posada Reposo Umbrío. Si tienes información relacionada con lo que ocurrió allí, deberías comunicársela al capitán Vimes cuanto antes. Es él quien lleva la investigación.', 0),
(@ID, 'esMX', 'James Hyal, James Hyal... ¿Por qué me suena tan familiar?$B$B¡Claro! Por el incidente de la Posada Reposo Umbrío. Si tienes información relacionada con lo que ocurrió allí, deberías comunicársela al capitán Vimes cuanto antes. Es él quien lleva la investigación.', 0);
-- 288 La Tercera Flota
-- https://es.classic.wowhead.com/quest=288
SET @ID := 288;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¡tengo mucha sed! ¿No quieres comprarle algo de beber a este pobre y lamentable idiota?', 0),
(@ID, 'esMX', 'Oh, ¡tengo mucha sed! ¿No quieres comprarle algo de beber a este pobre y lamentable idiota?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Ah, me sienta de perlas y suelta la lengua. ¡Gracias colega!', 0),
(@ID, 'esMX', '¡Ah! Ah, me sienta de perlas y suelta la lengua. ¡Gracias colega!', 0);
-- 463 El Guardaverde
-- https://es.classic.wowhead.com/quest=463
SET @ID := 463;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las hiedras y helechos hablan muy bien de ti, $gpequeño:pequeña;. Aunque tengo muchos nombres, solo respondo a unos pocos. Tú puedes llamarme Rethiel.$B$BDebes aguzar el oído... lamentar el destino de estas tierras heridas y te encargaré la misión de sanarlas.', 0),
(@ID, 'esMX', 'Las hiedras y helechos hablan muy bien de ti, $gpequeño:pequeña;. Aunque tengo muchos nombres, solo respondo a unos pocos. Tú puedes llamarme Rethiel.$B$BDebes aguzar el oído... lamentar el destino de estas tierras heridas y te encargaré la misión de sanarlas.', 0);
-- 321 Hierro Forjaluz
-- https://es.classic.wowhead.com/quest=321
SET @ID := 321;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cofre está empapado y el revestimiento está roto. El interior y el exterior del cofre están dañados con zarpazos... como si los murlocs hubieran estado rebuscando y hubieran robado su tesoro.$B$BPero escondido en el cofre descubres un Lingote Forjaluz. Por desgracia se necesitan muchos más para conseguir el metal necesario para forjar un arma.', 0),
(@ID, 'esMX', 'El cofre está empapado y el revestimiento está roto. El interior y el exterior del cofre están dañados con zarpazos... como si los murlocs hubieran estado rebuscando y hubieran robado su tesoro.$B$BPero escondido en el cofre descubres un Lingote Forjaluz. Por desgracia se necesitan muchos más para conseguir el metal necesario para forjar un arma.', 0);
-- 1249 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1249
SET @ID := 1249;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se escapó? Parecía un poco turbio por la forma en que nos miraba.', 0),
(@ID, 'esMX', '¿Se escapó? Parecía un poco turbio por la forma en que nos miraba.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Le has cogido, ¿eh? Bien por ti. Me sorprende que ese fuera Slim.$B$BSeré sincero, nunca pensé que echaría de menos la excitación de algunas de las actividades más turbias. Supongo que las viejas costumbres nunca mueren. No se lo digas a Elling... probablemente intentaría conseguir que volviera a Ventormenta si se enterase de que echo de menos la acción.$B$BMe alegro de haber podido ayudarte en tu estancia en Menethil. Si necesitas algo más, solo tienes que pedirlo.', 0),
(@ID, 'esMX', 'Le has cogido, ¿eh? Bien por ti. Me sorprende que ese fuera Slim.$B$BSeré sincero, nunca pensé que echaría de menos la excitación de algunas de las actividades más turbias. Supongo que las viejas costumbres nunca mueren. No se lo digas a Elling... probablemente intentaría conseguir que volviera a Ventormenta si se enterase de que echo de menos la acción.$B$BMe alegro de haber podido ayudarte en tu estancia en Menethil. Si necesitas algo más, solo tienes que pedirlo.', 0);
-- 1250 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1250
SET @ID := 1250;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿EL REY?! Eh... ¿el rey? ¿El rey, rey? ¿Estás de broma? No dijiste que estabas buscando a los secuestradores del rey. Ni siquiera sabía que había desaparecido... aunque eso explicaría la coronación de su hijo.$B$BEscribiré a Elling ahora mismo. Querrá saber que estás encargándote de esto.$B$BNunca habría adivinado que Jahn vendiese Ventormenta por una simple moneda. Incluso un pícaro debe tener honor cuando se trata de ciertas cosas.$B$BAhora, lo importante es encontrar a ese Hendel. Y creo que puedo ayudarte con eso.', 0),
(@ID, 'esMX', '¡¿EL REY?! Eh... ¿el rey? ¿El rey, rey? ¿Estás de broma? No dijiste que estabas buscando a los secuestradores del rey. Ni siquiera sabía que había desaparecido... aunque eso explicaría la coronación de su hijo.$B$BEscribiré a Elling ahora mismo. Querrá saber que estás encargándote de esto.$B$BNunca habría adivinado que Jahn vendiese Ventormenta por una simple moneda. Incluso un pícaro debe tener honor cuando se trata de ciertas cosas.$B$BAhora, lo importante es encontrar a ese Hendel. Y creo que puedo ayudarte con eso.', 0);
-- 1264 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1264
SET @ID := 1264;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un placer conocerte, $n. Soy el comandante Samaul. Estoy al cargo de las tropas de Jaina Valiente aquí, en Theramore.$B$BEstoy bastante ocupado pero, si tienes alguna pregunta, no dudes en hacérmela. Quizás no tenga mucho tiempo, pero no hay razón para que me ponga desagradable si necesitas mi ayuda.$B$BSi estás planeando viajar fuera de la ciudad, te sugiero que tengas cuidado. Además de ogros, orcos y murlocs, la parte sur del pantano está atestada de dragones negros.', 0),
(@ID, 'esMX', 'Un placer conocerte, $n. Soy el comandante Samaul. Estoy al cargo de las tropas de Jaina Valiente aquí, en Theramore.$B$BEstoy bastante ocupado pero, si tienes alguna pregunta, no dudes en hacérmela. Quizás no tenga mucho tiempo, pero no hay razón para que me ponga desagradable si necesitas mi ayuda.$B$BSi estás planeando viajar fuera de la ciudad, te sugiero que tengas cuidado. Además de ogros, orcos y murlocs, la parte sur del pantano está atestada de dragones negros.', 0);

-- 289 La tripulación maldita
-- https://es.classic.wowhead.com/quest=289
SET @ID := 289;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡En mis sueños a veces escucho los gemidos de mis hermanos! Por favor señor, libéralos de sus ataduras y termina con sus lamentos.', 0),
(@ID, 'esMX', '¡En mis sueños a veces escucho los gemidos de mis hermanos! Por favor señor, libéralos de sus ataduras y termina con sus lamentos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Recibe también la gratitud de mis hermanos malditos.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Recibe también la gratitud de mis hermanos malditos.', 0);
-- 470 Abriéndose paso entre los mocos
-- https://es.classic.wowhead.com/quest=470
SET @ID := 470;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste mi bolsa?', 0),
(@ID, 'esMX', '¿Encontraste mi bolsa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, gracias, $n! ¡Creía que la había perdido para siempre!$B$BUmm... esto ya no me vale de mucho, pero lávalo y estoy segura de que te será muy útil.', 0),
(@ID, 'esMX', '¡Oh, gracias, $n! ¡Creía que la había perdido para siempre!$B$BUmm... esto ya no me vale de mucho, pero lávalo y estoy segura de que te será muy útil.', 0);
-- 278 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=278
SET @ID := 278;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes lo que te pedí? ¡Es muy urgente!', 0),
(@ID, 'esMX', '¿Tienes lo que te pedí? ¡Es muy urgente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo a tiempo, $n!', 0),
(@ID, 'esMX', '¡Justo a tiempo, $n!', 0);
-- 280 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=280
SET @ID := 280;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tapa del barril se desliza lentamente.', 0),
(@ID, 'esMX', 'La tapa del barril se desliza lentamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril crepita un poco al verter la mezcla neutralizadora.', 0),
(@ID, 'esMX', 'El barril crepita un poco al verter la mezcla neutralizadora.', 0);
-- 283 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=283
SET @ID := 283;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! Sin tu ayuda, la presa habría saltado en pedazos. Gracias en nombre del Reino y de la Alianza, $c.$B$BEstamos a salvo... al menos de momento.', 0),
(@ID, 'esMX', '¡Gracias, $n! Sin tu ayuda, la presa habría saltado en pedazos. Gracias en nombre del Reino y de la Alianza, $c.$B$BEstamos a salvo... al menos de momento.', 0);
-- 465 La estrategia de Nek'rosh
-- https://es.classic.wowhead.com/quest=465
SET @ID := 465;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La primera catapulta está ante ti. ¿Vas a prenderle fuego?', 0),
(@ID, 'esMX', 'La primera catapulta está ante ti. ¿Vas a prenderle fuego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas algo de yesca en la catapulta y haces saltar una chispa.$B$B¡Aparece una llama que se extiende rápidamente!', 0),
(@ID, 'esMX', 'Colocas algo de yesca en la catapulta y haces saltar una chispa.$B$B¡Aparece una llama que se extiende rápidamente!', 0);
-- 305 La búsqueda del equipo de excavación
-- https://es.classic.wowhead.com/quest=305
SET @ID := 305;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¡loados sean los cielos! ¡Estás aquí!', 0),
(@ID, 'esMX', 'Oh, ¡loados sean los cielos! ¡Estás aquí!', 0);
-- 294 La venganza de Ormer
-- https://es.classic.wowhead.com/quest=294
SET @ID := 294;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mata a 10 estridadores jaspeados y 10 raptores jaspeados, $n. Mis compañeros de trabajo no se merecían el destino que les tocó. Es hora de igualar el marcador.', 0),
(@ID, 'esMX', 'Mata a 10 estridadores jaspeados y 10 raptores jaspeados, $n. Mis compañeros de trabajo no se merecían el destino que les tocó. Es hora de igualar el marcador.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Matar es un negocio sucio, pero has hecho muy bien tu trabajo, $n. Si no tuviera que permanecer junto al prospector y a Merrin estaría a tu lado vertiendo sangre.', 0),
(@ID, 'esMX', 'Matar es un negocio sucio, pero has hecho muy bien tu trabajo, $n. Si no tuviera que permanecer junto al prospector y a Merrin estaría a tu lado vertiendo sangre.', 0);
-- 306 La búsqueda del equipo de excavación
-- https://es.classic.wowhead.com/quest=306
SET @ID := 306;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido encontrar a Merrin? ¿Ha enviado algún mensaje?', 0),
(@ID, 'esMX', '¿Has podido encontrar a Merrin? ¿Ha enviado algún mensaje?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué noticias tan horribles! Al menos tres sobrevivieron. ¿Cuándo terminarán las muertes? Anhelo el día en el que los súbditos del rey Magni puedan vivir libres de miedo.', 0),
(@ID, 'esMX', '¡Qué noticias tan horribles! Al menos tres sobrevivieron. ¿Cuándo terminarán las muertes? Anhelo el día en el que los súbditos del rey Magni puedan vivir libres de miedo.', 0);
-- 299 Desvelando el pasado
-- https://es.classic.wowhead.com/quest=299
SET @ID := 299;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has descubierto los cuatro fragmentos, $n? Ados, Modr, Golm y Neru...', 0),
(@ID, 'esMX', '¿Ya has descubierto los cuatro fragmentos, $n? Ados, Modr, Golm y Neru...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la piedra Goaz está completa! Buen trabajo, $n. Buen trabajo, sin duda. Ahora puedo seguir con la trascripción de este escrito de los Titanes. ¡Ya puedo descifrar nuevas palabras! Umm... aquí dice, "Dioses antiguos... encadenados bajo la tierra." Esto debe ser el comienzo de algún relato épico.', 0),
(@ID, 'esMX', '¡Ah, la piedra Goaz está completa! Buen trabajo, $n. Buen trabajo, sin duda. Ahora puedo seguir con la trascripción de este escrito de los Titanes. ¡Ya puedo descifrar nuevas palabras! Umm... aquí dice, "Dioses antiguos... encadenados bajo la tierra." Esto debe ser el comienzo de algún relato épico.', 0);
-- 295 La venganza de Ormer
-- https://es.classic.wowhead.com/quest=295
SET @ID := 295;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quiero hacer que esos raptores segadores jaspeados y raptores tajobuches jaspeados paguen por lo que hicieron. ¿Has matado a 10 de cada uno?', 0),
(@ID, 'esMX', 'Quiero hacer que esos raptores segadores jaspeados y raptores tajobuches jaspeados paguen por lo que hicieron. ¿Has matado a 10 de cada uno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hiciste un trabajo fenomenal eliminando a esos raptores, $n!', 0),
(@ID, 'esMX', '¡Hiciste un trabajo fenomenal eliminando a esos raptores, $n!', 0);
-- 296 La venganza de Ormer
-- https://es.classic.wowhead.com/quest=296
SET @ID := 296;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está muerto Sarldente? ¿Has redimido la memoria de los caídos?', 0),
(@ID, 'esMX', '¿Está muerto Sarldente? ¿Has redimido la memoria de los caídos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. No olvidaremos tus esfuerzos. Muchos enanos inocentes murieron en este lugar mientras se limitaban a hacer su trabajo. Has hecho que la venganza caiga sobre esas malvadas criaturas. Se lo pensarán dos veces antes de volver a atacar a los súbditos del rey Magni.', 0),
(@ID, 'esMX', 'Gracias, $n. No olvidaremos tus esfuerzos. Muchos enanos inocentes murieron en este lugar mientras se limitaban a hacer su trabajo. Has hecho que la venganza caiga sobre esas malvadas criaturas. Se lo pensarán dos veces antes de volver a atacar a los súbditos del rey Magni.', 0);
-- 474 Derrota a Nek'rosh
-- https://es.classic.wowhead.com/quest=474
SET @ID := 474;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Nek\'rosh?', 0),
(@ID, 'esMX', '¿Has matado a Nek\'rosh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho con gran resolución, $n. Has dado un golpe contundente al clan orco de los Faucedraco. Quizás nunca se recuperen. Y la destrucción de las catapultas han hecho de Puerto de Menethil un lugar mucho más seguro.$B$BTus méritos son innegables, y el reino de Forjaz sabe recompensar a quienes le sirven.', 0),
(@ID, 'esMX', 'Lo has hecho con gran resolución, $n. Has dado un golpe contundente al clan orco de los Faucedraco. Quizás nunca se recuperen. Y la destrucción de las catapultas han hecho de Puerto de Menethil un lugar mucho más seguro.$B$BTus méritos son innegables, y el reino de Forjaz sabe recompensar a quienes le sirven.', 0);
-- 276 Patas sucias
-- https://es.classic.wowhead.com/quest=276
SET @ID := 276;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aún tienes que completar tu misión, joven $c.', 0),
(@ID, 'esMX', 'Aún tienes que completar tu misión, joven $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al reducir el número de gnolls has cuidado de la salud de Los Humedales. Aunque mi fe en tu pueblo fue puesta a prueba en el pasado, $r, quizás ahora se recupere.', 0),
(@ID, 'esMX', 'Al reducir el número de gnolls has cuidado de la salud de Los Humedales. Aunque mi fe en tu pueblo fue puesta a prueba en el pasado, $r, quizás ahora se recupere.', 0);
-- 277 No al fuego
-- https://es.classic.wowhead.com/quest=277
SET @ID := 277;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las herramientas gnoll para hacer fuego?', 0),
(@ID, 'esMX', '¿Tienes las herramientas gnoll para hacer fuego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '... Gracias. Romperé estos pedernales y los lanzaré al mar para que nunca más puedan ser usados para prender fuego a madera viva.', 0),
(@ID, 'esMX', '... Gracias. Romperé estos pedernales y los lanzaré al mar para que nunca más puedan ser usados para prender fuego a madera viva.', 0);
-- 275 Ampollas en la tierra
-- https://es.classic.wowhead.com/quest=275
SET @ID := 275;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los humedales todavía lloran y los trepadores del pantano todavía se enfurecen. Regresa a mí cuando hayas terminado tu tarea.', 0),
(@ID, 'esMX', 'Los humedales todavía lloran y los trepadores del pantano todavía se enfurecen. Regresa a mí cuando hayas terminado tu tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus esfuerzos han aliviado a esta tierra, recibirás algo muy provechoso.', 0),
(@ID, 'esMX', 'Tus esfuerzos han aliviado a esta tierra, recibirás algo muy provechoso.', 0);
-- 281 Recuperación de bienes
-- https://es.classic.wowhead.com/quest=281
SET @ID := 281;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cajón está cubierto de arañazos y está dañado por el agua. Cuando lo abres descubres paja empapada y podrida, como si hubiera habido algo de valor guardado en el cajón. Buscas por la paja...$B$B... y encuentras un puñado de botellas de color rojo.', 0),
(@ID, 'esMX', 'El cajón está cubierto de arañazos y está dañado por el agua. Cuando lo abres descubres paja empapada y podrida, como si hubiera habido algo de valor guardado en el cajón. Buscas por la paja...$B$B... y encuentras un puñado de botellas de color rojo.', 0);
-- 324 Los lingotes perdidos
-- https://es.classic.wowhead.com/quest=324
SET @ID := 324;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado el hierro Forjaluz que necesitas?', 0),
(@ID, 'esMX', '¿Has encontrado el hierro Forjaluz que necesitas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los encontraste! ¡Vamos a fundir este hierro Forjaluz en algo útil!, ¿qué te parece?', 0),
(@ID, 'esMX', '¡Ah, los encontraste! ¡Vamos a fundir este hierro Forjaluz en algo útil!, ¿qué te parece?', 0);
-- 322 Brazo bendito
-- https://es.classic.wowhead.com/quest=322
SET @ID := 322;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué te podrían servir mis conocimientos, $c?', 0),
(@ID, 'esMX', '¿En qué te podrían servir mis conocimientos, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Menuda historia la tuya! ¡Y tienes hierro Forjaluz! Hace años que no trabajo con ese metal. Será un honor trabajar con él otra vez. Vuelve a verme luego para contarme la historia de tu batalla contra el Necromántico.$B$BPero estamos yendo demasiado deprisa. Antes de nada, tu arma contra Morbent Vil...', 0),
(@ID, 'esMX', '¡Menuda historia la tuya! ¡Y tienes hierro Forjaluz! Hace años que no trabajo con ese metal. Será un honor trabajar con él otra vez. Vuelve a verme luego para contarme la historia de tu batalla contra el Necromántico.$B$BPero estamos yendo demasiado deprisa. Antes de nada, tu arma contra Morbent Vil...', 0);
-- 1448 En búsqueda del templo
-- https://es.classic.wowhead.com/quest=1448
SET @ID := 1448;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He viajado por el mundo desde las selvas de Azeroth hasta los picos nevados de Khaz Modan.$B$BNunca antes había pedido ayuda en mis aventuras. Pero mis viejos huesos están cansados.$B$BNada me dejaría más satisfecho que saber que completé mi búsqueda final de la Liga de Expedicionarios.$B$BSi tuvieras la amabilidad de ayudarme a buscar el Templo de Atal\'Hakkar, $c, te lo agradecería mucho.$B$B¡Explora el Pantano de las Penas e informame de tus hallazgos!', 0),
(@ID, 'esMX', 'He viajado por el mundo desde las selvas de Azeroth hasta los picos nevados de Khaz Modan.$B$BNunca antes había pedido ayuda en mis aventuras. Pero mis viejos huesos están cansados.$B$BNada me dejaría más satisfecho que saber que completé mi búsqueda final de la Liga de Expedicionarios.$B$BSi tuvieras la amabilidad de ayudarme a buscar el Templo de Atal\'Hakkar, $c, te lo agradecería mucho.$B$B¡Explora el Pantano de las Penas e informame de tus hallazgos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Templo de Atal\'Hakkar está sumergido bajo la Charca de Lágrimas? ¿Y rodeado del Vuelo Verde?$B$BUn descubrimiento increíble, $c. Pero, obviamente, algo ha salido terriblemente mal.', 0),
(@ID, 'esMX', '¿El Templo de Atal\'Hakkar está sumergido bajo la Charca de Lágrimas? ¿Y rodeado del Vuelo Verde?$B$BUn descubrimiento increíble, $c. Pero, obviamente, algo ha salido terriblemente mal.', 0);
-- 325 Armado y listo
-- https://es.classic.wowhead.com/quest=325
SET @ID := 325;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. No hace tanto que te fuiste y, sin embargo, veo un fuego en tus ojos que no había visto antes.', 0),
(@ID, 'esMX', 'Hola, $n. No hace tanto que te fuiste y, sin embargo, veo un fuego en tus ojos que no había visto antes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡esto será perfecto para el malvado Morbent Vil! ¡Bien hecho!$B$BYa estás preparado. Morbent Vil caerá.', 0),
(@ID, 'esMX', 'Ah, ¡esto será perfecto para el malvado Morbent Vil! ¡Bien hecho!$B$BYa estás preparado. Morbent Vil caerá.', 0);
-- 1363 La orden de Mazen
-- https://es.classic.wowhead.com/quest=1363
SET @ID := 1363;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No fue culpa mía. En serio, no fue culpa mía.', 0),
(@ID, 'esMX', 'No fue culpa mía. En serio, no fue culpa mía.', 0);
-- 1364 La orden de Mazen
-- https://es.classic.wowhead.com/quest=1364
SET @ID := 1364;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por el Castillo de Nethergarde, $r?', 0),
(@ID, 'esMX', '¿Qué te trae por el Castillo de Nethergarde, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, estupendo!$B$BDurante un tiempo temí que el maestro Mazen de la Academia de Artes y Ciencias Arcanas hubiese olvidado mi pedido de los ensayos de Khadgar sobre convergencia dimensional.$B$BDebe de tener muchísimas peticiones teniendo en cuenta los extraños sucesos que están teniendo lugar.$B$BAhora, si me disculpas, tengo que comenzar con mi investigación. Llegar a comprender por fin a alguien tan grandioso como Khadgar me excita en gran medida.', 0),
(@ID, 'esMX', '¡Ah, estupendo!$B$BDurante un tiempo temí que el maestro Mazen de la Academia de Artes y Ciencias Arcanas hubiese olvidado mi pedido de los ensayos de Khadgar sobre convergencia dimensional.$B$BDebe de tener muchísimas peticiones teniendo en cuenta los extraños sucesos que están teniendo lugar.$B$BAhora, si me disculpas, tengo que comenzar con mi investigación. Llegar a comprender por fin a alguien tan grandioso como Khadgar me excita en gran medida.', 0);

-- 690 Una petición de Malin
-- https://es.classic.wowhead.com/quest=690
SET @ID := 690;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que t\'envía Malin? M\'importa un bledo que Muradin resucitara y te pusiera un dragón pa\' traerte aquí. ¡Estoy ocupao! Habla con Kryten pa\' lo que sea.', 0),
(@ID, 'esMX', '¿Así que t\'envía Malin? M\'importa un bledo que Muradin resucitara y te pusiera un dragón pa\' traerte aquí. ¡Estoy ocupao! Habla con Kryten pa\' lo que sea.', 0);
-- 1477 Suministros de vital importancia
-- https://es.classic.wowhead.com/quest=1477
SET @ID := 1477;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Andromath? Muy bien. Tengo una importante tarea para ti...', 0),
(@ID, 'esMX', '¿Te envía Andromath? Muy bien. Tengo una importante tarea para ti...', 0);
-- 2861 La tarea de Tabetha
-- https://es.classic.wowhead.com/quest=2861
SET @ID := 2861;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es cierto. Tengo unas cuentas que arreglar con un trol. Algunas cuentas. ¡Todas!$B$B¿Quieres ayudarme?', 0),
(@ID, 'esMX', 'Es cierto. Tengo unas cuentas que arreglar con un trol. Algunas cuentas. ¡Todas!$B$B¿Quieres ayudarme?', 0);
-- 212 Un plato bien frío
-- https://es.classic.wowhead.com/quest=212
SET @ID := 212;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Has conseguido el anca ya? Debo cocinar pronto, ¡o el banquete será un desastre total!', 0),
(@ID, 'esMX', '¡$n! ¿Has conseguido el anca ya? Debo cocinar pronto, ¡o el banquete será un desastre total!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡esto vendrá de perlas! ¡Muchas, pero que muchísimas gracias!$B$BAhora, si me disculpas, tengo que picar esta pierna, marinarla y preparar la guarnición para el banquete.', 0),
(@ID, 'esMX', 'Ah, ¡esto vendrá de perlas! ¡Muchas, pero que muchísimas gracias!$B$BAhora, si me disculpas, tengo que picar esta pierna, marinarla y preparar la guarnición para el banquete.', 0);
-- 1260 Morgan Stern
-- https://es.classic.wowhead.com/quest=1260
SET @ID := 1260;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, así que te envía mi tío, ¿eh?$B$BBueno, he estado investigando unas recetas, y tengo algunas pistas, pero necesito ayuda.$B$BAyuda de alguien a quien no le importe mojarse los pies.', 0),
(@ID, 'esMX', 'Ah, así que te envía mi tío, ¿eh?$B$BBueno, he estado investigando unas recetas, y tengo algunas pistas, pero necesito ayuda.$B$BAyuda de alguien a quien no le importe mojarse los pies.', 0);
-- 55 Morbent Vil
-- https://es.classic.wowhead.com/quest=55
SET @ID := 55;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Has derrotado a Morbent Vil?!', 0),
(@ID, 'esMX', '¡¿Has derrotado a Morbent Vil?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Morbent Vil ha sido derrotado. Los jinetes oscuros aún andan por ahí, pero ya ha ocurrido una de las dos cosas que esperaba con desesperación.$B$BHas hecho lo imposible y tu hazaña perdurará en las leyendas del Bosque del Ocaso.$B$BVe, $n. Quizás un día, el destino vuelva a traerte a mí...', 0),
(@ID, 'esMX', 'Morbent Vil ha sido derrotado. Los jinetes oscuros aún andan por ahí, pero ya ha ocurrido una de las dos cosas que esperaba con desesperación.$B$BHas hecho lo imposible y tu hazaña perdurará en las leyendas del Bosque del Ocaso.$B$BVe, $n. Quizás un día, el destino vuelva a traerte a mí...', 0);
-- 284 La búsqueda continúa
-- https://es.classic.wowhead.com/quest=284
SET @ID := 284;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril no ha sido tocado en mucho tiempo. Lo abres...$B$B... y te abruma un fuerte olor a queso. Está un poco mojado, ¡pero aún está bueno!', 0),
(@ID, 'esMX', 'El barril no ha sido tocado en mucho tiempo. Lo abres...$B$B... y te abruma un fuerte olor a queso. Está un poco mojado, ¡pero aún está bueno!', 0);
-- 285 Inspecciona más casuchas
-- https://es.classic.wowhead.com/quest=285
SET @ID := 285;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril está casi enterrado entre el barro y la hierba...', 0),
(@ID, 'esMX', 'El barril está casi enterrado entre el barro y la hierba...', 0);
-- 286 Devuelve la Estatuilla
-- https://es.classic.wowhead.com/quest=286
SET @ID := 286;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la estatuilla?', 0),
(@ID, 'esMX', '¿Tienes la estatuilla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El capitán de La princesa ciega se sentirá aliviado al saber que has recuperado su precioso cargamento. Te has ganado el pago por tus servicios.$B$BEs bueno encontrar a gente fiable como tú, especialmente en tiempos difíciles como estos.', 0),
(@ID, 'esMX', 'El capitán de La princesa ciega se sentirá aliviado al saber que has recuperado su precioso cargamento. Te has ganado el pago por tus servicios.$B$BEs bueno encontrar a gente fiable como tú, especialmente en tiempos difíciles como estos.', 0);
-- 290 Purga de la maldición
-- https://es.classic.wowhead.com/quest=290
SET @ID := 290;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cofre está bien cerrado.', 0),
(@ID, 'esMX', 'Este cofre está bien cerrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave está oxidada pero entra perfectamente en el candado.', 0),
(@ID, 'esMX', 'La llave está oxidada pero entra perfectamente en el candado.', 0);
-- 292 El ojo de Paleth
-- https://es.classic.wowhead.com/quest=292
SET @ID := 292;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía el borracho de Fistimos? Puedes decirle que no tengo más cerveza. ¡Tendrá que ir mendigarle a otro!', 0),
(@ID, 'esMX', '¿Te envía el borracho de Fistimos? Puedes decirle que no tengo más cerveza. ¡Tendrá que ir mendigarle a otro!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un ojo de Paleth? ¡Fascinante! Umm... algo va mal con este. ¿Lo encontraste en uno de los restos de naufragio? ¡Eso lo explica todo! Pero... no sabía que tuvieran un ojo así en la Tercera Flota...$B$BNo me extraña que Fistimos estuviera tan asustado. Encontrarse con un Ojo maldito de Paleth no es ninguna alegría.', 0),
(@ID, 'esMX', '¿Un ojo de Paleth? ¡Fascinante! Umm... algo va mal con este. ¿Lo encontraste en uno de los restos de naufragio? ¡Eso lo explica todo! Pero... no sabía que tuvieran un ojo así en la Tercera Flota...$B$BNo me extraña que Fistimos estuviera tan asustado. Encontrarse con un Ojo maldito de Paleth no es ninguna alegría.', 0);
-- 293 Limpieza del ojo
-- https://es.classic.wowhead.com/quest=293
SET @ID := 293;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es ese orbe? Parece... dañado.', 0),
(@ID, 'esMX', '¿Qué es ese orbe? Parece... dañado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un ojo de Paleth. Pero este ha visto demasiado dolor... debe haber sido testigo de una terrible, terrible tragedia.$B$BDéjame purificarlo, los ojos fueron creados para iluminar y sus poderes pueden ser muy peligrosos si están malditos como este.', 0),
(@ID, 'esMX', 'Un ojo de Paleth. Pero este ha visto demasiado dolor... debe haber sido testigo de una terrible, terrible tragedia.$B$BDéjame purificarlo, los ojos fueron creados para iluminar y sus poderes pueden ser muy peligrosos si están malditos como este.', 0);
-- 681 Mansión Redilnorte
-- https://es.classic.wowhead.com/quest=681
SET @ID := 681;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, con cada hora que pasa nuestro control sobre Stromgarde se vuelve más débil. Debes darte prisa o nuestra ciudad seguramente caerá.', 0),
(@ID, 'esMX', '$n, con cada hora que pasa nuestro control sobre Stromgarde se vuelve más débil. Debes darte prisa o nuestra ciudad seguramente caerá.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Con la muerte de los miembros de la Hermandad debería ser más fácil recibir los suministros de Costasur.$B$BQuizás aún quede esperanza para nuestra causa.', 0),
(@ID, 'esMX', 'Muy bien, $n. Con la muerte de los miembros de la Hermandad debería ser más fácil recibir los suministros de Costasur.$B$BQuizás aún quede esperanza para nuestra causa.', 0);
-- 684 Se busca: Marez Cogulla
-- https://es.classic.wowhead.com/quest=684
SET @ID := 684;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¿Tienes un informe para mí?', 0),
(@ID, 'esMX', 'Saludos, $c. ¿Tienes un informe para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has despachado a Marez Cogulla? Muy bien, $n. ¡Pero que muy bien!$B$BMarez era una amenaza para nuestros defensores de Stromgarde y se rumoreaba que era una emisaria entre la Hermandad y algún poder más oscuro. Nos alegramos de que ya no ejerza sus poderes contra nosotros.', 0),
(@ID, 'esMX', '¿Has despachado a Marez Cogulla? Muy bien, $n. ¡Pero que muy bien!$B$BMarez era una amenaza para nuestros defensores de Stromgarde y se rumoreaba que era una emisaria entre la Hermandad y algún poder más oscuro. Nos alegramos de que ya no ejerza sus poderes contra nosotros.', 0);
-- 685 Se busca: Otto y Lord Falconcrest
-- https://es.classic.wowhead.com/quest=685
SET @ID := 685;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Vienes a presentar un informe?', 0),
(@ID, 'esMX', 'Hola. ¿Vienes a presentar un informe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Falconcrest y Otto? ¡Estupendo!$B$BAquí tienes tu recompensa, $n. Te la pago con mucho gusto.', 0),
(@ID, 'esMX', '¿Falconcrest y Otto? ¡Estupendo!$B$BAquí tienes tu recompensa, $n. Te la pago con mucho gusto.', 0);
-- 691 Valer su peso en oro
-- https://es.classic.wowhead.com/quest=691
SET @ID := 691;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte hasta ahora, $n?$B$B<Kryten toma algunas notas en su diario mientras lee>$B$BSi mi investigación es correcta, los colmillos deberían proceder de cualquier trol Secacorteza. Las bolsas de medicina proceden de los médicos brujos Secacorteza y el más fuerte de los cazadores oscuros Secacorteza debería llevar el cuchillo especial que se les entrega después de completar sus ritos de paso. No hay forma de saber qué cazador oscuro lleva el cuchillo hasta que te enfrentas a ellos.', 0),
(@ID, 'esMX', '¿Ha habido suerte hasta ahora, $n?$B$B<Kryten toma algunas notas en su diario mientras lee>$B$BSi mi investigación es correcta, los colmillos deberían proceder de cualquier trol Secacorteza. Las bolsas de medicina proceden de los médicos brujos Secacorteza y el más fuerte de los cazadores oscuros Secacorteza debería llevar el cuchillo especial que se les entrega después de completar sus ritos de paso. No hay forma de saber qué cazador oscuro lleva el cuchillo hasta que te enfrentas a ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Ahora entiendo por qué Malin te pidió que te unieras a nosotros, ¡gran idea, digo!$B$BA este paso, Skuerto y yo estaremos de vuelta en Ventormenta antes de que nos demos cuenta.$B$BCreo que mi compañero enano ha vuelto de su exploración de la Sala Puño de Roca; ve a hablar con él cuando estés $glisto:lista;.$B$BAl parecer, tuvo una escaramuza con los ogros. Aunque ni se lo menciones, es muy sensible ante las críticas a sus habilidades y a su trabajo como rastreador.', 0),
(@ID, 'esMX', '¡Increíble! Ahora entiendo por qué Malin te pidió que te unieras a nosotros, ¡gran idea, digo!$B$BA este paso, Skuerto y yo estaremos de vuelta en Ventormenta antes de que nos demos cuenta.$B$BCreo que mi compañero enano ha vuelto de su exploración de la Sala Puño de Roca; ve a hablar con él cuando estés $glisto:lista;.$B$BAl parecer, tuvo una escaramuza con los ogros. Aunque ni se lo menciones, es muy sensible ante las críticas a sus habilidades y a su trabajo como rastreador.', 0);
-- 3636 Trae la Luz
-- https://es.classic.wowhead.com/quest=3636
SET @ID := 3636;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Amnennar debe ser erradicado. Vete rápido.', 0),
(@ID, 'esMX', 'Amnennar debe ser erradicado. Vete rápido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. La Plaga ahora se lo pensará dos veces antes de intentar incrementar sus ejércitos.$B$BQue la Luz te bendiga.', 0),
(@ID, 'esMX', 'Gracias, $n. La Plaga ahora se lo pensará dos veces antes de intentar incrementar sus ejércitos.$B$BQue la Luz te bendiga.', 0);
-- 6141 Hermano Anton
-- https://es.classic.wowhead.com/quest=6141
SET @ID := 6141;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recibí noticias de una ayuda que llegaba del este. ¿Eres tú el objeto de tales rumores? ¿Has venido aquí a ayudar a la Hermandad Escarlata en su cruzada?$B$BSi es así, escucha con atención...', 0),
(@ID, 'esMX', 'Recibí noticias de una ayuda que llegaba del este. ¿Eres tú el objeto de tales rumores? ¿Has venido aquí a ayudar a la Hermandad Escarlata en su cruzada?$B$BSi es así, escucha con atención...', 0);
-- 682 Distintivos de Stromgarde
-- https://es.wowhead.com/quest=682
-- https://wow-es.gamepedia.com/Misión:Distintivos de Stromgarde
SET @ID := 682;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido recuperar alguna de las insignias de Stromgarde, $n? La Hermandad debe aprender que no se aprovecharán de nuestros muertos.', 0),
(@ID, 'esMX', '¿Has conseguido recuperar alguna de las insignias de Stromgarde, $n? La Hermandad debe aprender que no se aprovecharán de nuestros muertos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Informaremos a las familias sobre los soldados caídos en la batalla.$B$BSerán noticias crudas pero es mejor que la incertidumbre de alguien querido que ha desaparecido.', 0),
(@ID, 'esMX', 'Gracias, $n. Informaremos a las familias sobre los soldados caídos en la batalla.$B$BSerán noticias crudas pero es mejor que la incertidumbre de alguien querido que ha desaparecido.', 0);
-- 693 Empuñar la varita
-- https://es.classic.wowhead.com/quest=693
SET @ID := 693;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro objetivo es la varita, $n. Por ahora céntrate en eso.', 0),
(@ID, 'esMX', 'Nuestro objetivo es la varita, $n. Por ahora céntrate en eso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, $n! 1 menos, solo faltan 3, según mi lista. Los otros 3 están en Stromgarde.$B$BDescansa un poco pa’ recuperar las fuerzas, que t’hará buena falta pa’ la siguiente fase de mi plan. Vuelve cuando hayas tomado algo caliente y hayas descansado.', 0),
(@ID, 'esMX', '¡Genial, $n! 1 menos, solo faltan 3, según mi lista. Los otros 3 están en Stromgarde.$B$BDescansa un poco pa’ recuperar las fuerzas, que t’hará buena falta pa’ la siguiente fase de mi plan. Vuelve cuando hayas tomado algo caliente y hayas descansado.', 0);
-- 694 Las defensas de Trelane
-- https://es.classic.wowhead.com/quest=694
SET @ID := 694;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola otra vez, $n. ¿Has encontrado ya una ágata azur?', 0),
(@ID, 'esMX', 'Hola otra vez, $n. ¿Has encontrado ya una ágata azur?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n. Una vez más, enhorabuena.$B$BDame un momento para lanzar el hechizo apropiado para encantar la gema ¡y listo!', 0),
(@ID, 'esMX', 'Impresionante, $n. Una vez más, enhorabuena.$B$BDame un momento para lanzar el hechizo apropiado para encantar la gema ¡y listo!', 0);

-- 695 Un encantamiento de aprendiz
-- https://es.classic.wowhead.com/quest=695
SET @ID := 695;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, bien.$B$BSi no hay más impedimentos, ¿qué tal si empezamos?', 0),
(@ID, 'esMX', 'Bien, bien.$B$BSi no hay más impedimentos, ¿qué tal si empezamos?', 0);
-- 696 Ataque a la torre
-- https://es.classic.wowhead.com/quest=696
SET @ID := 696;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haces esto y pa’ mí que Malin estará más que contento contigo.', 0),
(@ID, 'esMX', 'Haces esto y pa’ mí que Malin estará más que contento contigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Malin no podría haber encontrado una persona más valiosa pa’ venir a ayudarnos, $n. ¡Has hecho un trabajo espléndido!$B$BSe alegrará de ver el éxito tan aplastante de nuestra misión.', 0),
(@ID, 'esMX', 'Malin no podría haber encontrado una persona más valiosa pa’ venir a ayudarnos, $n. ¡Has hecho un trabajo espléndido!$B$BSe alegrará de ver el éxito tan aplastante de nuestra misión.', 0);
-- 697 Una petición de Malin
-- https://es.classic.wowhead.com/quest=697
SET @ID := 697;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Me suenas algo, vagamente. Discúlpame, ¿nos conocemos? Estoy tan ocupado que se me escapan las cosas.', 0),
(@ID, 'esMX', '¿Sí? Me suenas algo, vagamente. Discúlpame, ¿nos conocemos? Estoy tan ocupado que se me escapan las cosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El archimago Malin abre la carta y pone ojos como platos.>$B$BPor la Luz, ¡lo has conseguido! ¡Qué maravilla! Trelane se alegrará mucho. Estoy seguro de que Kryten y Skuerto están tan entusiasmados como yo porque los voy a hacer regresar a Ventormenta.$B$BGracias, $n. Te ruego aceptes esto, te ayudará en tus viajes.', 0),
(@ID, 'esMX', '<El archimago Malin abre la carta y pone ojos como platos.>$B$BPor la Luz, ¡lo has conseguido! ¡Qué maravilla! Trelane se alegrará mucho. Estoy seguro de que Kryten y Skuerto están tan entusiasmados como yo porque los voy a hacer regresar a Ventormenta.$B$BGracias, $n. Te ruego aceptes esto, te ayudará en tus viajes.', 0);
-- 1395 Suministros para Nethergarde
-- https://es.classic.wowhead.com/quest=1395
SET @ID := 1395;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! No hagas caso del revuelo, es lo normal en el Castillo de Nethergarde.$B$B¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¡Hola! No hagas caso del revuelo, es lo normal en el Castillo de Nethergarde.$B$B¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, las piedras de potencia! ¡Los magos se alegrarán de verlas!$B$BMuchas gracias, $n. Sé que tu viaje desde Villa Oscura no fue fácil.', 0),
(@ID, 'esMX', '¡Ah, las piedras de potencia! ¡Los magos se alegrarán de verlas!$B$BMuchas gracias, $n. Sé que tu viaje desde Villa Oscura no fue fácil.', 0);
-- 739 Murdaloc
-- https://es.classic.wowhead.com/quest=739
SET @ID := 739;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes noticias del destino de Agmond? ¿Lo encontraste?', 0),
(@ID, 'esMX', '¿Tienes noticias del destino de Agmond? ¿Lo encontraste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una noticia aleccionadora, $n. Pero Agmond tenía un brazo poderoso, con su martillo era brutal ¡y la cabeza tan dura como nadie! A pesar de que esos malditos troggs lo han matado, estoy seguro de que antes se llevó por delante a muchos.', 0),
(@ID, 'esMX', 'Es una noticia aleccionadora, $n. Pero Agmond tenía un brazo poderoso, con su martillo era brutal ¡y la cabeza tan dura como nadie! A pesar de que esos malditos troggs lo han matado, estoy seguro de que antes se llevó por delante a muchos.', 0);
-- 704 El sino de Agmond
-- https://es.classic.wowhead.com/quest=704
SET @ID := 704;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado esas urnas, $n? ¡Debemos averiguar la relación entre ellas y los troggs!', 0),
(@ID, 'esMX', '¿Has encontrado esas urnas, $n? ¡Debemos averiguar la relación entre ellas y los troggs!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien! Con suerte y diligencia, encontraremos la conexión entre los troggs y estos antiguos artefactos.$B$BNos has hecho un gran favor a los prospectores, $n. No lo olvidaremos. Y tampoco a Agmond.', 0),
(@ID, 'esMX', '¡Muy bien! Con suerte y diligencia, encontraremos la conexión entre los troggs y estos antiguos artefactos.$B$BNos has hecho un gran favor a los prospectores, $n. No lo olvidaremos. Y tampoco a Agmond.', 0);
-- 1449 A las Tierras del Interior
-- https://es.classic.wowhead.com/quest=1449
SET @ID := 1449;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué quieres, $gmuchacho:muchacha;? ¿No ves que tengo cosas que hacer aquí? ¿A quién le sobra el tiempo para perderlo con $gun:una; $r $gcharlatán:charlatana;?$B$B¡Hay trols saliendo de la carpintería! Habla rápido.', 0),
(@ID, 'esMX', '¿Qué quieres, $gmuchacho:muchacha;? ¿No ves que tengo cosas que hacer aquí? ¿A quién le sobra el tiempo para perderlo con $gun:una; $r $gcharlatán:charlatana;?$B$B¡Hay trols saliendo de la carpintería! Habla rápido.', 0);
-- 1396 Contra la fauna feroz
-- https://es.classic.wowhead.com/quest=1396
SET @ID := 1396;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las criaturas del pantano se acercan, $n. ¡Por favor, debes defender el campamento!', 0),
(@ID, 'esMX', 'Las criaturas del pantano se acercan, $n. ¡Por favor, debes defender el campamento!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los sonidos de los animales ahora son débiles y distantes. Gracias, $n. ¡Esperemos que no vuelvan!', 0),
(@ID, 'esMX', 'Los sonidos de los animales ahora son débiles y distantes. Gracias, $n. ¡Esperemos que no vuelvan!', 0);
-- 1421 La caravana perdida
-- https://es.classic.wowhead.com/quest=1421
SET @ID := 1421;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los componentes de zahorí, $n?', 0),
(@ID, 'esMX', '¿Tienes los componentes de zahorí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los has encontrado! Con ellos, los zahoríes de Nethergarde podrán continuar con su trabajo. No sé con exactitud lo que hacen pero tiene que ver con El Portal Oscuro de Las Tierras Devastadas y es crucial para la seguridad de la Alianza.', 0),
(@ID, 'esMX', '¡Ah, los has encontrado! Con ellos, los zahoríes de Nethergarde podrán continuar con su trabajo. No sé con exactitud lo que hacen pero tiene que ver con El Portal Oscuro de Las Tierras Devastadas y es crucial para la seguridad de la Alianza.', 0);
-- 1398 Madera a la deriva
-- https://es.classic.wowhead.com/quest=1398
SET @ID := 1398;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste la madera, $n?', 0),
(@ID, 'esMX', '¿Encontraste la madera, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta madera es ligera pero muy resistente. Gracias, $n. Es justo lo que necesito.', 0),
(@ID, 'esMX', 'Esta madera es ligera pero muy resistente. Gracias, $n. Es justo lo que necesito.', 0);
-- 1425 Envío de suministros
-- https://es.classic.wowhead.com/quest=1425
SET @ID := 1425;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que tratar conmigo?', 0),
(@ID, 'esMX', '¿Tienes algo que tratar conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Un paquete de la caravana de Biggs? Ya lo dábamos todo por perdidos...$B$BGracias, $n. Con un poco de suerte contendrá el componente que tanto necesitamos, los cristales de Azora. Nos estamos quedando sin ellos...', 0),
(@ID, 'esMX', '¿Qué? ¿Un paquete de la caravana de Biggs? Ya lo dábamos todo por perdidos...$B$BGracias, $n. Con un poco de suerte contendrá el componente que tanto necesitamos, los cristales de Azora. Nos estamos quedando sin ellos...', 0);
-- 11126 Traidores entre nosotros
-- https://es.wowhead.com/quest=11126
SET @ID := 11126;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has expulsado a los agitadores desertores de Theramore?', 0),
(@ID, 'esMX', '¿Has expulsado a los agitadores desertores de Theramore?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Creo que logramos pillarlos con la guardia baja. Sus agentes probablemente se creían seguros dentro de las murallas de la ciudad.$B$BCon el tiempo, los agitadores regresarán y difundirán sus mentiras nuevamente. Usaremos el tiempo que has ganado para alejar más a los desertores.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Creo que logramos pillarlos con la guardia baja. Sus agentes probablemente se creían seguros dentro de las murallas de la ciudad.$B$BCon el tiempo, los agitadores regresarán y difundirán sus mentiras nuevamente. Usaremos el tiempo que has ganado para alejar más a los desertores.', 0);
-- 11128 Guerra de propaganda
-- https://es.wowhead.com/quest=11128
SET @ID := 11128;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste encontrar y capturar los folletos de propaganda restantes?', 0),
(@ID, 'esMX', '¿Conseguiste encontrar y capturar los folletos de propaganda restantes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El agente de SI: 7 asiente en señal de aprobación.>$B$BExcelente. Todo lo que queda es desacreditar a los desertores para que nunca más vuelvan a afianzarse en Theramore, y tengo el plan perfecto para hacerlo.', 0),
(@ID, 'esMX', '<El agente de SI: 7 asiente en señal de aprobación.>$B$BExcelente. Todo lo que queda es desacreditar a los desertores para que nunca más vuelvan a afianzarse en Theramore, y tengo el plan perfecto para hacerlo.', 0);
-- 11128 Guerra de propaganda
-- https://es.wowhead.com/quest=11128
SET @ID := 11128;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste encontrar y capturar los folletos de propaganda restantes?', 0),
(@ID, 'esMX', '¿Conseguiste encontrar y capturar los folletos de propaganda restantes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El agente del IV:7 asiente en señal de aprobación.>$B$BExcelente. Todo lo que queda es desacreditar a los desertores para que nunca más vuelvan a afianzarse en Theramore, y tengo el plan perfecto para hacerlo.', 0),
(@ID, 'esMX', '<El agente del IV:7 asiente en señal de aprobación.>$B$BExcelente. Todo lo que queda es desacreditar a los desertores para que nunca más vuelvan a afianzarse en Theramore, y tengo el plan perfecto para hacerlo.', 0);
-- 11191 Este viejo faro
-- https://es.wowhead.com/quest=11191
SET @ID := 11191;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno. Puedo usar toda la ayuda que puedas ofrecer. Mi primera prioridad es volver a encender esa lámpara.', 0),
(@ID, 'esMX', 'Bueno. Puedo usar toda la ayuda que puedas ofrecer. Mi primera prioridad es volver a encender esa lámpara.', 0);
-- 11133 Desprestigiando a los desertores
-- https://es.wowhead.com/quest=11133
SET @ID := 11133;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creí escuchar risas provenientes de los barracones. ¿Distribuiste esos panfletos que te di?', 0),
(@ID, 'esMX', 'Creí escuchar risas provenientes de los barracones. ¿Distribuiste esos panfletos que te di?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Calia se ríe mientras describes las reacciones de los guardias a la propaganda.>$B$B¡Justo como esperaba! ¡Creo que es seguro decir que cualquier agente desertor que intente infiltrarse en Theramore sufrirá las burlas de toda la ciudad!', 0),
(@ID, 'esMX', '<Calia se ríe mientras describes las reacciones de los guardias a la propaganda.>$B$B¡Justo como esperaba! ¡Creo que es seguro decir que cualquier agente desertor que intente infiltrarse en Theramore sufrirá las burlas de toda la ciudad!', 0);
-- 11123 Inspeccionando las ruinas
-- https://es.wowhead.com/quest=11123
SET @ID := 11123;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno ver que el Capitán Vimes finalmente está asignando a otros a esta investigación.$B$BHe usado un polvo reflectante en todo el área. Revelará objetos y marcas sospechosas, lo que te ayudará a concentrar sus esfuerzos. Revisa todo lo que el polvo ilumine.', 0),
(@ID, 'esMX', 'Es bueno ver que el Capitán Vimes finalmente está asignando a otros a esta investigación.$B$BHe usado un polvo reflectante en todo el área. Revelará objetos y marcas sospechosas, lo que te ayudará a concentrar sus esfuerzos. Revisa todo lo que el polvo ilumine.', 0);
-- 11212 La granja de Tabetha
-- https://es.wowhead.com/quest=11212
SET @ID := 11212;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno que Theramore haya enviado a alguien. Las sospechas de tu amigo guardia son correctas. Tenemos unos vecinos nuevos y no son del tipo a los que invitarías a comer.', 0),
(@ID, 'esMX', 'Es bueno que Theramore haya enviado a alguien. Las sospechas de tu amigo guardia son correctas. Tenemos unos vecinos nuevos y no son del tipo a los que invitarías a comer.', 0);
-- 1204 Sopa de Fangorroca con tropezones
-- https://es.wowhead.com/quest=1204
SET @ID := 1204;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido las lenguas bífidas?', 0),
(@ID, 'esMX', '¿Has conseguido las lenguas bífidas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas son estupendas! ¡Gracias, $n!$B$BAhora probaré a cocinar estas lenguas con diferentes técnicas para encontrar la que más realce su sabor.$B$B¡Conseguiré un plato digno de servirse en El Ermitaño Taciturno de Ventormenta!', 0),
(@ID, 'esMX', '¡Estas son estupendas! ¡Gracias, $n!$B$BAhora probaré a cocinar estas lenguas con diferentes técnicas para encontrar la que más realce su sabor.$B$B¡Conseguiré un plato digno de servirse en El Ermitaño Taciturno de Ventormenta!', 0);
-- 1258 ...con tropezones
-- https://es.wowhead.com/quest=1258
SET @ID := 1258;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis experimentos con las lenguas Fangorroca bífidas van estupendamente. Espero que tu caza de cangrejos esté yendo bien también...', 0),
(@ID, 'esMX', 'Mis experimentos con las lenguas Fangorroca bífidas van estupendamente. Espero que tu caza de cangrejos esté yendo bien también...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendos ejemplares, $n! Están en perfectas condiciones, y la carne está rosadita y tierna. ¡Tienes sangre de chef corriendo por tus venas!', 0),
(@ID, 'esMX', '¡Estupendos ejemplares, $n! Están en perfectas condiciones, y la carne está rosadita y tierna. ¡Tienes sangre de chef corriendo por tus venas!', 0);
-- 11214 Misión a Piñón de Barro
-- https://es.wowhead.com/quest=11214
SET @ID := 11214;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces Theramore está interesado en hacer negocios? Bueno, esa no es una oferta que rechazaría. Los suministros son bastante escasos aquí en este momento, ¡así que necesitamos todos los contactos comerciales que podamos conseguir!', 0),
(@ID, 'esMX', '¿Entonces Theramore está interesado en hacer negocios? Bueno, esa no es una oferta que rechazaría. Los suministros son bastante escasos aquí en este momento, ¡así que necesitamos todos los contactos comerciales que podamos conseguir!', 0);

-- 1265 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1265
SET @ID := 1265;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El hombre al que buscas, Hendel, no está aquí. Ha llegado información a través de otras fuentes a Lady Valiente, que creo que ya sabes. Me ha pedido que te busque y te ayude en tu misión. Si me lo permites, te diré dónde encontrar al soldado Hendel para que puedas llevarle ante la justicia.', 0),
(@ID, 'esMX', 'El hombre al que buscas, Hendel, no está aquí. Ha llegado información a través de otras fuentes a Lady Valiente, que creo que ya sabes. Me ha pedido que te busque y te ayude en tu misión. Si me lo permites, te diré dónde encontrar al soldado Hendel para que puedas llevarle ante la justicia.', 0);
-- 7070 Trozos Oscuros
-- https://es.classic.wowhead.com/quest=7070
SET @ID := 7070;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya hiciste el viaje? Sé que sería bastante peligroso, pero si tuvieras éxito, valdría mucho la pena.', 0),
(@ID, 'esMX', '¿Ya hiciste el viaje? Sé que sería bastante peligroso, pero si tuvieras éxito, valdría mucho la pena.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son perfectos, $n. De hecho, otros aventureros también regresaron de allí y de ellos pude diseñar estos... por favor, siéntetee libre de tomar uno por su arduo trabajo. Y gracias nuevamente por traer más muestras para estudiar.', 0),
(@ID, 'esMX', 'Estos son perfectos, $n. De hecho, otros aventureros también regresaron de allí y de ellos pude diseñar estos... por favor, siéntetee libre de tomar uno por su arduo trabajo. Y gracias nuevamente por traer más muestras para estudiar.', 0);
-- 11134 El fin de los desertores
-- https://es.wowhead.com/quest=11134
SET @ID := 11134;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu asalto a la base de los desertores?', 0),
(@ID, 'esMX', '¿Has completado tu asalto a la base de los desertores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las peticiones de Gavis no es tan extravagantes como podría parecer. Con el manejo adecuado, Lady Jaina puede devolver a los desertores al redil, pero esa es su decisión, por supuesto.$B$BHa sido un placer trabajar contigo, $n. Sin tu ayuda, dudo que la operación hubiera salido tan bien. Cuando haga mi informe en Ventormenta, te nombrará como $gel:la; $c que puso fin a la amenaza del desertor.', 0),
(@ID, 'esMX', 'Las peticiones de Gavis no es tan extravagantes como podría parecer. Con el manejo adecuado, Lady Jaina puede devolver a los desertores al redil, pero esa es su decisión, por supuesto.$B$BHa sido un placer trabajar contigo, $n. Sin tu ayuda, dudo que la operación hubiera salido tan bien. Cuando haga mi informe en Ventormenta, te nombrará como $gel:la; $c que puso fin a la amenaza del desertor.', 0);
-- 11192 Aceite de trillador
-- https://es.wowhead.com/quest=11192
SET @ID := 11192;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste conseguir algo de ese aceite de trillador?', 0),
(@ID, 'esMX', '¿Pudiste conseguir algo de ese aceite de trillador?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, tengo mis dudas, pero esta es la única solución disponible en este momento. Una vez que lo tengamos en funcionamiento, estoy seguro de que habrá tiempo para buscar otras formas de alimentar la lámpara.', 0),
(@ID, 'esMX', 'Bueno, tengo mis dudas, pero esta es la única solución disponible en este momento. Una vez que lo tengamos en funcionamiento, estoy seguro de que habrá tiempo para buscar otras formas de alimentar la lámpara.', 0);
-- 11193 Ruines Moradores de las Profundidades
-- https://es.wowhead.com/quest=11193
SET @ID := 11193;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué será hoy? El róbalo es bastante bueno.', 0),
(@ID, 'esMX', '¿Qué será hoy? El róbalo es bastante bueno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, eso fue muy amable por parte de Babs al enviar el libro. No sé si lo habrá hojeado o no, pero hay mucha verdad en los cuentos de ese libro. Los marineros no se lo inventan todo, ya sabes.', 0),
(@ID, 'esMX', 'Bueno, eso fue muy amable por parte de Babs al enviar el libro. No sé si lo habrá hojeado o no, pero hay mucha verdad en los cuentos de ese libro. Los marineros no se lo inventan todo, ya sabes.', 0);
-- 11194 ¿Es real?
-- https://es.wowhead.com/quest=11194
SET @ID := 11194;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿quieres saber más sobre los monstruos marinos? Hmm... bueno, te propongo un trato, pero implicará mucho alcohol y algo de vergüenza por tu parte.', 0),
(@ID, 'esMX', 'Entonces, ¿quieres saber más sobre los monstruos marinos? Hmm... bueno, te propongo un trato, pero implicará mucho alcohol y algo de vergüenza por tu parte.', 0);
-- 11136 Un progreso preocupante
-- https://es.wowhead.com/quest=11136
SET @ID := 11136;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán no hace ningún esfuerzo por ocultar que está evaluando tus habilidades.>$B$B¿Has oído hablar del reciente naufragio frente a la costa? Me vendría bien un poco de ayuda para confirmar mis sospechas sobre los supervivientes. ', 0),
(@ID, 'esMX', '<El capitán no hace ningún esfuerzo por ocultar que está evaluando tus habilidades.>$B$B¿Has oído hablar del reciente naufragio frente a la costa? Me vendría bien un poco de ayuda para confirmar mis sospechas sobre los supervivientes. ', 0);
-- 11137 ¿Defias en Revolcafango?
-- https://es.wowhead.com/quest=11137
SET @ID := 11137;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste localizar a su líder?', 0),
(@ID, 'esMX', '¿Pudiste localizar a su líder?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán Wymor acepta las órdenes y las lee.>$B$B¿A qué diablos se podría referir "carga preciosa"? Los Defia han hecho pequeño contrabando en tierras de Ventormenta, pero esto parece fuera de su alcance. El lenguaje de estas órdenes sugiere un mecenas rico o noble.', 0),
(@ID, 'esMX', '<El capitán Wymor acepta las órdenes y las lee.>$B$B¿A qué diablos se podría referir "carga preciosa"? Los Defia han hecho pequeño contrabando en tierras de Ventormenta, pero esto parece fuera de su alcance. El lenguaje de estas órdenes sugiere un mecenas rico o noble.', 0);
-- 11138 Renn McBranquia
-- https://es.wowhead.com/quest=11138
SET @ID := 11138;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Qué te trae por aquí?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Qué te trae por aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Renn revisa las órdenes.>$B$B¡Así que había una valiosa carga a bordo! Tenemos que localizarlo antes de que los Defias lo recuperen. Estos tipos no son buzos, pero vamos a necesitar algo de su equipo si me ayudas a encontrar la carga.', 0),
(@ID, 'esMX', '<Renn revisa las órdenes.>$B$B¡Así que había una valiosa carga a bordo! Tenemos que localizarlo antes de que los Defias lo recuperen. Estos tipos no son buzos, pero vamos a necesitar algo de su equipo si me ayudas a encontrar la carga.', 0);
-- 11209 El trato de Nat
-- https://es.wowhead.com/quest=11209
SET @ID := 11209;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerde el trato,... "no regreses hasta que algo te muerda".', 0),
(@ID, 'esMX', 'Recuerde el trato,... "no regreses hasta que algo te muerda".', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No está nada mal, pero sabes, si fuera tú, creo que me daría un baño lo antes posible.$B$BAhora, sobre tu monstruo marino...$B$BMientras tanto, sírvete algo.', 0),
(@ID, 'esMX', 'No está nada mal, pero sabes, si fuera tú, creo que me daría un baño lo antes posible.$B$BAhora, sobre tu monstruo marino...$B$BMientras tanto, sírvete algo.', 0);
-- 11177 El ermitaño de la Mansión Cienaluz
-- https://es.wowhead.com/quest=11177
SET @ID := 11177;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sal de mi césped ... a menos que, es decir, quieras ayudar al viejo "Ojolodo" un poco en la cocina. ¿Qué dices?', 0),
(@ID, 'esMX', 'Sal de mi césped ... a menos que, es decir, quieras ayudar al viejo "Ojolodo" un poco en la cocina. ¿Qué dices?', 0);
-- 11210 Oh, es real
-- https://es.wowhead.com/quest=11210
SET @ID := 11210;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Cuentas tus experiencias con Nat Pagle, omitiendo cuidadosamente la parte sobre la \'prueba del cebo\'>$B$BBueno, parece que tenemos mucho trabajo por delante. Haré los preparativos.', 0),
(@ID, 'esMX', '<Cuentas tus experiencias con Nat Pagle, omitiendo cuidadosamente la parte sobre la \'prueba del cebo\'>$B$BBueno, parece que tenemos mucho trabajo por delante. Haré los preparativos.', 0);
-- 11198 ¡Elimina a Tethyr!
-- https://es.wowhead.com/quest=11198
SET @ID := 11198;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz tu informe.', 0),
(@ID, 'esMX', 'Haz tu informe.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Lo admito, cuando vi por primera vez a esa bestia, tenía dudas sobre nuestra capacidad para defender los muelles, ¡pero mantuviste unidos a los defensores de manera brillante!', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Lo admito, cuando vi por primera vez a esa bestia, tenía dudas sobre nuestra capacidad para defender los muelles, ¡pero mantuviste unidos a los defensores de manera brillante!', 0);
-- 1266 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1266
SET @ID := 1266;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gciudadano:ciudadana;. Este es un lugar peligroso para las visitas. Yo no me quedaría mucho por aquí si valoras tu vida.$B$BSi tus preguntas son cortas, intentaré ayudarte. Mantén los ojos abiertos y ten cuidado con esos sucios ogros. Según los rumores, hay una base de la Horda cerca del pantano. Los infiltrados hacen todo lo que pueden para encontrarla, pero el proceso va lento y no hemos conseguido avanzar mucho.', 0),
(@ID, 'esMX', 'Hola, $gciudadano:ciudadana;. Este es un lugar peligroso para las visitas. Yo no me quedaría mucho por aquí si valoras tu vida.$B$BSi tus preguntas son cortas, intentaré ayudarte. Mantén los ojos abiertos y ten cuidado con esos sucios ogros. Según los rumores, hay una base de la Horda cerca del pantano. Los infiltrados hacen todo lo que pueden para encontrarla, pero el proceso va lento y no hemos conseguido avanzar mucho.', 0);
-- 1218 Ancas de rana de marisma
-- https://es.classic.wowhead.com/quest=1218
SET @ID := 1218;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Especias. A todos nos vendrían bien. Dan sabor a la vida. ¿No te parece?', 0),
(@ID, 'esMX', 'Especias. A todos nos vendrían bien. Dan sabor a la vida. ¿No te parece?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto sí que son especias! Aquí tienes un poco de buen guiso del pantano.', 0),
(@ID, 'esMX', '¡Esto sí que son especias! Aquí tienes un poco de buen guiso del pantano.', 0);
-- 11180 ¿Quién atormenta la Colina de las Brujas?
-- https://es.wowhead.com/quest=11180
SET @ID := 11180;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has aprendido de los espíritus que acechan este lugar?', 0),
(@ID, 'esMX', '¿Qué has aprendido de los espíritus que acechan este lugar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mordant saca una pequeña hoja de papel y un lápiz, y comienza a escribir notas sobre tus hallazgos.>$B$BSegún tus hallazgos, los espíritus en este lugar deben ser todos los que alguna vez vivieron en esta tierra, no solo los ocupantes anteriores.$B$BAlgo los ha estado corrompiendo y matando. Los que siguen no aprenden la verdad hasta que es demasiado tarde. ¡Tenemos que acabar con esto, $n!', 0),
(@ID, 'esMX', '<Mordant saca una pequeña hoja de papel y un lápiz, y comienza a escribir notas sobre tus hallazgos.>$B$BSegún tus hallazgos, los espíritus en este lugar deben ser todos los que alguna vez vivieron en esta tierra, no solo los ocupantes anteriores.$B$BAlgo los ha estado corrompiendo y matando. Los que siguen no aprenden la verdad hasta que es demasiado tarde. ¡Tenemos que acabar con esto, $n!', 0);
-- 1219 El informe orco
-- https://es.classic.wowhead.com/quest=1219
SET @ID := 1219;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que informar?', 0),
(@ID, 'esMX', '¿Tienes algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm... No entiendo muy bien el lenguaje orco pero, esto parece una especie de informe... ¡escrito por un espía orco!', 0),
(@ID, 'esMX', 'Mm... No entiendo muy bien el lenguaje orco pero, esto parece una especie de informe... ¡escrito por un espía orco!', 0);
-- 1206 Jarl necesita ojos
-- https://es.classic.wowhead.com/quest=1206
SET @ID := 1206;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde están esos ojos?', 0),
(@ID, 'esMX', '¿Dónde están esos ojos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes los ojos! ¡Tienes los ojos! ¡Ricos, ricos ojos de araña!$B$BAlgunos ojos... parece que te miran cuando los miras. Esos son los últimos que hay que comerse. Así te hacen compañía... en el pantano la compañía escasea.$B$BHola, ojitos de araña. ¡Hola! Sabéis a pollo. ¡Rico pollito asado!$B$BMmm.', 0),
(@ID, 'esMX', '¡Tienes los ojos! ¡Tienes los ojos! ¡Ricos, ricos ojos de araña!$B$BAlgunos ojos... parece que te miran cuando los miras. Esos son los últimos que hay que comerse. Así te hacen compañía... en el pantano la compañía escasea.$B$BHola, ojitos de araña. ¡Hola! Sabéis a pollo. ¡Rico pollito asado!$B$BMmm.', 0);
-- 1203 Jarl necesita una hoja
-- https://es.classic.wowhead.com/quest=1203
SET @ID := 1203;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi espada?', 0),
(@ID, 'esMX', '¿Tienes mi espada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esa es una buena espada. Tiene buen equilibrio. Es una buena hoja equilibrada. Gracias. ¡¡¡Gracias, gracias, gracias!!! Ahora quiero probarlo ...$B$BLuego. Lo intentaré más tarde. Pero como estaba diciendo ... gracias.', 0),
(@ID, 'esMX', 'Esa es una buena espada. Tiene buen equilibrio. Es una buena hoja equilibrada. Gracias. ¡¡¡Gracias, gracias, gracias!!! Ahora quiero probarlo ...$B$BLuego. Lo intentaré más tarde. Pero como estaba diciendo ... gracias.', 0);
-- 11181 La ruina de las brujas
-- https://es.wowhead.com/quest=11181
SET @ID := 11181;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste recolectar algo de la hierba? Debemos trabajar rápidamente, antes de que cualquier mal que esté detrás de esta plaga consolide su control en el área.', 0),
(@ID, 'esMX', '¿Pudiste recolectar algo de la hierba? Debemos trabajar rápidamente, antes de que cualquier mal que esté detrás de esta plaga consolide su control en el área.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Mordant acepta tu manojo de hierbas.>$B$B¡Estos coinciden exactamente con la descripción! Preparé la antorcha mientras estabas fuera. Todo lo que queda es sujetar las hierbas en el final.', 0),
(@ID, 'esMX', '<Mordant acepta tu manojo de hierbas.>$B$B¡Estos coinciden exactamente con la descripción! Preparé la antorcha mientras estabas fuera. Todo lo que queda es sujetar las hierbas en el final.', 0);
-- 11183 Limpiar la Colina de las Brujas
-- https://es.wowhead.com/quest=11183
SET @ID := 11183;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se terminó?', 0),
(@ID, 'esMX', '¿Se terminó?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Funcionó?$B$B<Mordant se aclara la garganta.>$B$BQuiero decir ... ¡funcionó! Jarl y yo estamos en deuda contigo, $n. Ahora el único problema que queda es el gusto de mi amigo por los muebles, y me temo que no se resolverá tan fácilmente.', 0),
(@ID, 'esMX', '¿Funcionó?$B$B<Mordant se aclara la garganta.>$B$BQuiero decir ... ¡funcionó! Jarl y yo estamos en deuda contigo, $n. Ahora el único problema que queda es el gusto de mi amigo por los muebles, y me temo que no se resolverá tan fácilmente.', 0);

-- 11146 Captor de raptores
-- https://es.wowhead.com/quest=11146
SET @ID := 11146;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Capturaste esas raptores?', 0),
(@ID, 'esMX', '¿Capturaste esas raptores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces un poco arañado, pero nada importante. Ciertamente estás en mejor forma que los Tótem Siniestro cuando nuestros nuevos amigos raptores terminen con ellos.', 0),
(@ID, 'esMX', 'Pareces un poco arañado, pero nada importante. Ciertamente estás en mejor forma que los Tótem Siniestro cuando nuestros nuevos amigos raptores terminen con ellos.', 0);
-- 1324 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1324
SET @ID := 1324;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo, $n. Espero que no te importe la ayuda, pero no podemos permitir que Hendel se escape o, peor aún, acabe muerto.', 0),
(@ID, 'esMX', 'Hola de nuevo, $n. Espero que no te importe la ayuda, pero no podemos permitir que Hendel se escape o, peor aún, acabe muerto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo aseguro, todos estamos bastante disgustados por los sucesos recientes, pero permite que le llevemos a Theramore para interrogarle a ver si conseguimos información sobre el rey.$B$BSeguro que Lady Valiente querría agradecerte tu ayuda. Habla con ella cuando tengas un momento.', 0),
(@ID, 'esMX', 'Te lo aseguro, todos estamos bastante disgustados por los sucesos recientes, pero permite que le llevemos a Theramore para interrogarle a ver si conseguimos información sobre el rey.$B$BSeguro que Lady Valiente querría agradecerte tu ayuda. Habla con ella cuando tengas un momento.', 0);
-- 11145 Prisioneros de los Tótem Siniestro
-- https://es.wowhead.com/quest=11145
SET @ID := 11145;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste liberar a los cautivos en el Poblado Pezuñanegra?', 0),
(@ID, 'esMX', '¿Conseguiste liberar a los cautivos en el Poblado Pezuñanegra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los cautivos liberados ya han comenzado a regresar del Poblado Pezuñanegra. La información que el capitán está recibiendo de los prisioneros nos dará una ventaja en nuestra próxima batalla contra los Tótem Siniestro.$B$BTienes mi agradecimiento y el de los hombres.', 0),
(@ID, 'esMX', 'Los cautivos liberados ya han comenzado a regresar del Poblado Pezuñanegra. La información que el capitán está recibiendo de los prisioneros nos dará una ventaja en nuestra próxima batalla contra los Tótem Siniestro.$B$BTienes mi agradecimiento y el de los hombres.', 0);
-- 1220 Capitán Vimes
-- https://es.classic.wowhead.com/quest=1220
SET @ID := 1220;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un informe de un espía orco! ¿Cómo lo encontraste? No importa. Veamos lo que dice...', 0),
(@ID, 'esMX', '¡Un informe de un espía orco! ¿Cómo lo encontraste? No importa. Veamos lo que dice...', 0);
-- 1267 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1267
SET @ID := 1267;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Primero, quiero darte las gracias por todo lo que has hecho, $n. Has sido una increíble bendición para todos los míos y para todo el pueblo de Ventormenta. Siento no haber podido conocerte en mejores circunstancias.$B$BEspero que comprendas que no puedo darte las gracias abiertamente, pero te aseguro, que lo aprecio mucho.$B$BCuando vengas a Theramore en el futuro, búscame e intentaré compensarte.$B$BGracias de nuevo, $n.', 0),
(@ID, 'esMX', 'Primero, quiero darte las gracias por todo lo que has hecho, $n. Has sido una increíble bendición para todos los míos y para todo el pueblo de Ventormenta. Siento no haber podido conocerte en mejores circunstancias.$B$BEspero que comprendas que no puedo darte las gracias abiertamente, pero te aseguro, que lo aprecio mucho.$B$BCuando vengas a Theramore en el futuro, búscame e intentaré compensarte.$B$BGracias de nuevo, $n.', 0);
-- 11139 Equipo de buceo de segunda mano
-- https://es.wowhead.com/quest=11139
SET @ID := 11139;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veamos qué has conseguido "pedir prestado" a los Defias.', 0),
(@ID, 'esMX', 'Veamos qué has conseguido "pedir prestado" a los Defias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, esto está en peor estado de lo que pensaba, y estas herramientas ...$B$BBueno, dije que volvería a poner esto en funcionamiento, así que será mejor que me ponga a trabajar.', 0),
(@ID, 'esMX', 'Vaya, esto está en peor estado de lo que pensaba, y estas herramientas ...$B$BBueno, dije que volvería a poner esto en funcionamiento, así que será mejor que me ponga a trabajar.', 0);
-- 11140 ¡Recupera la mercancía!
-- https://es.wowhead.com/quest=11140
SET @ID := 11140;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La búsqueda de restos reveló algo sobre la carga de los Defias?', 0),
(@ID, 'esMX', '¿La búsqueda de restos reveló algo sobre la carga de los Defias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Renn revisa el contenido de las cajas fuertes que recuperaste.>$B$BBuen trabajo. Ahora, veamos si nuestro "precioso cargamento" está aquí...', 0),
(@ID, 'esMX', '<Renn revisa el contenido de las cajas fuertes que recuperaste.>$B$BBuen trabajo. Ahora, veamos si nuestro "precioso cargamento" está aquí...', 0);
-- 11141 Jaina debe saberlo
-- https://es.wowhead.com/quest=11141
SET @ID := 11141;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Renn y tú habéis hecho un trabajo excelente para sacar a la luz esta información y comunicarla de inmediato. Ahora, debemos confirmar los hallazgos. Las implicaciones son demasiado grandes si nos equivocamos.', 0),
(@ID, 'esMX', 'Renn y tú habéis hecho un trabajo excelente para sacar a la luz esta información y comunicarla de inmediato. Ahora, debemos confirmar los hallazgos. Las implicaciones son demasiado grandes si nos equivocamos.', 0);
-- 11142 Inspecciona la Isla de Alcaz
-- https://es.wowhead.com/quest=11142
SET @ID := 11142;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lady Jaina escucha atentamente mientras informas los resultados de tu reconocimiento aéreo.>$B$B¿Un círculo de runas, dragonkin? ¿Los Defia se han aliado con ELLA? ¿El traidor?$B$B<Lady Jaina se recompone y se prepara para explicar.>', 0),
(@ID, 'esMX', '<Lady Jaina escucha atentamente mientras informas los resultados de tu reconocimiento aéreo.>$B$B¿Un círculo de runas, dragonkin? ¿Los Defia se han aliado con ELLA? ¿El traidor?$B$B<Lady Jaina se recompone y se prepara para explicar.>', 0);
-- 1222 La fuga de Apestoso
-- https://es.classic.wowhead.com/quest=1222
SET @ID := 1222;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha visto al Sr. Ignatz? ¡Lo envié al pantano hace algún tiempo y no ha regresado!', 0),
(@ID, 'esMX', '¿Ha visto al Sr. Ignatz? ¡Lo envié al pantano hace algún tiempo y no ha regresado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El señor Ignatz ha estado aquí con las hojas de cienagrana y me dijo que le habías ayudado a salir de un auténtico atolladero.$B$BTe lo agradezco, $n. Pediré a mi tío que te invite a un festín la próxima vez que vayas a El Ermitaño Azul de Ventormenta.', 0),
(@ID, 'esMX', 'El señor Ignatz ha estado aquí con las hojas de cienagrana y me dijo que le habías ayudado a salir de un auténtico atolladero.$B$BTe lo agradezco, $n. Pediré a mi tío que te invite a un festín la próxima vez que vayas a El Ermitaño Azul de Ventormenta.', 0);
-- 1252 Teniente Paval Reethe
-- https://es.classic.wowhead.com/quest=1252
SET @ID := 1252;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algo de interés en la Posada Reposo Umbrío?', 0),
(@ID, 'esMX', '¿Has encontrado algo de interés en la Posada Reposo Umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando me traen la insignia de un guardia, nunca viene acompañada de buenas noticias.$B$BA veces, me la traen porque un hombre o una mujer ha muerto en combate. Y yo tengo que comunicar la noticia a su familia. Otras veces no se sabe ni qué fue de quien portaba la insignia. Y en ocasiones... es peor que todo lo anterior.', 0),
(@ID, 'esMX', 'Cuando me traen la insignia de un guardia, nunca viene acompañada de buenas noticias.$B$BA veces, me la traen porque un hombre o una mujer ha muerto en combate. Y yo tengo que comunicar la noticia a su familia. Otras veces no se sabe ni qué fue de quien portaba la insignia. Y en ocasiones... es peor que todo lo anterior.', 0);
-- 1253 El escudo negro
-- https://es.classic.wowhead.com/quest=1253
SET @ID := 1253;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algo en la Posada Reposo Umbrío?', 0),
(@ID, 'esMX', '¿Has encontrado algo en la Posada Reposo Umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, no soy un experto en la creación de armas y armaduras. En su uso, sí, pero no en su fabricación.$B$BEste escudo parece tan normal como cualquiera, exceptuando el daño que le causó el fuego de la posada.', 0),
(@ID, 'esMX', 'Mm, no soy un experto en la creación de armas y armaduras. En su uso, sí, pero no en su fabricación.$B$BEste escudo parece tan normal como cualquiera, exceptuando el daño que le causó el fuego de la posada.', 0);
-- 1284 Huellas de pezuñas sospechosas
-- https://es.classic.wowhead.com/quest=1284
SET @ID := 1284;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Huellas de pezuñas, ¿eh? Es verdad que los centauros están desplegando una actividad extraordinaria en las tierras cercanas al Marjal Revolcafango. En cortas excursiones a Los Baldíos, encontramos sus campamentos y sus propiedades, estaban por toda la zona.$B$BEnviaré a Falgran Hastil, uno de nuestros rastreadores, a ver si puede averiguar a dónde conducen las huellas.', 0),
(@ID, 'esMX', 'Huellas de pezuñas, ¿eh? Es verdad que los centauros están desplegando una actividad extraordinaria en las tierras cercanas al Marjal Revolcafango. En cortas excursiones a Los Baldíos, encontramos sus campamentos y sus propiedades, estaban por toda la zona.$B$BEnviaré a Falgran Hastil, uno de nuestros rastreadores, a ver si puede averiguar a dónde conducen las huellas.', 0);
-- https://es.wowhead.com/quest=11156
SET @ID := 11156;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho algún progreso para detener los ataques de Tótem Siniestro?', 0),
(@ID, 'esMX', '¿Has hecho algún progreso para detener los ataques de Tótem Siniestro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El aprendiz Morlann asiente.>$B$BBueno. No puedo decir que extrañaré la compañía, si puedes llamarlo así. Pensarías que al menos en medio del pantano obtendrías algo de privacidad, ¿sabes?', 0),
(@ID, 'esMX', '<El aprendiz Morlann asiente.>$B$BBueno. No puedo decir que extrañaré la compañía, si puedes llamarlo así. Pensarías que al menos en medio del pantano obtendrías algo de privacidad, ¿sabes?', 0);
-- 11172 El accidente del zepelín
-- https://es.wowhead.com/quest=11172
SET @ID := 11172;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces te enviaron esos magos ermitaños? ¿Cómo puedo estar seguro de que puedo confiar en ti?$B$BSupongo que puedo usar la ayuda. De todos modos, no hay mucho que le interese a un mago.', 0),
(@ID, 'esMX', '¿Entonces te enviaron esos magos ermitaños? ¿Cómo puedo estar seguro de que puedo confiar en ti?$B$BSupongo que puedo usar la ayuda. De todos modos, no hay mucho que le interese a un mago.', 0);
-- 2846 Tiara de las profundidades
-- https://es.classic.wowhead.com/quest=2846
SET @ID := 2846;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la tiara, $n? ¿Ha aprendido ya Velratha cuál es el precio de contrariarme?', 0),
(@ID, 'esMX', '¿Tienes la tiara, $n? ¿Ha aprendido ya Velratha cuál es el precio de contrariarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! ¡La encontraste! Y lo que es más importante... ¡Velratha ya no la tiene! Gracias, $n. ¡Te estaré siempre en deuda!$B$BY si antes te pareció que tenía algo de mal humor... no hagas caso. Verás que soy mucho más agradable con aquellos que no me han robado nada.', 0),
(@ID, 'esMX', '¡Maravilloso! ¡La encontraste! Y lo que es más importante... ¡Velratha ya no la tiene! Gracias, $n. ¡Te estaré siempre en deuda!$B$BY si antes te pareció que tenía algo de mal humor... no hagas caso. Verás que soy mucho más agradable con aquellos que no me han robado nada.', 0);
-- 11169 El arma Tótem Siniestro
-- https://es.wowhead.com/quest=11169
SET @ID := 11169;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte probando el tótem?', 0),
(@ID, 'esMX', '¿Has tenido suerte probando el tótem?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El aprendiz escucha mientras describe su experimento.>$B$B¿Una bruma y un rayo? ¿Eso es? ¡Tiene que haber más en el tótem que solo eso! No es probable que los Tótem Siniestro traigan algo como esto al campo de batalla a menos que tenga algún tipo de utilidad.', 0),
(@ID, 'esMX', '<El aprendiz escucha mientras describe su experimento.>$B$B¿Una bruma y un rayo? ¿Eso es? ¡Tiene que haber más en el tótem que solo eso! No es probable que los Tótem Siniestro traigan algo como esto al campo de batalla a menos que tenga algún tipo de utilidad.', 0);
-- 11173 El ladrón de componentes
-- https://es.wowhead.com/quest=11173
SET @ID := 11173;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste ese veneno? Morlann va a descubrir que no está en cualquier momento ...', 0),
(@ID, 'esMX', '¿Conseguiste ese veneno? Morlann va a descubrir que no está en cualquier momento ...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El aprendiz Garion inspecciona el veneno.>$B$B¡Esto es absolutamente perfecto! Él nunca notará la diferencia.', 0),
(@ID, 'esMX', '<El aprendiz Garion inspecciona el veneno.>$B$B¡Esto es absolutamente perfecto! Él nunca notará la diferencia.', 0);
-- 11174 Prevención contra la corrosión
-- https://es.wowhead.com/quest=11174
SET @ID := 11174;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hiciste algún progreso contra esos mocos?', 0),
(@ID, 'esMX', '¿Hiciste algún progreso contra esos mocos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, parece un poco más limpio ahí fuera ...$B$BSupongo que es hora de poner manos a la obra de rescatar estos restos.', 0),
(@ID, 'esMX', 'Bueno, parece un poco más limpio ahí fuera ...$B$BSupongo que es hora de poner manos a la obra de rescatar estos restos.', 0);
-- 11207 ¡Asegura el cargamento!
-- https://es.wowhead.com/quest=11207
SET @ID := 11207;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Moxie parece frenética de preocupación.>$B$B¿Sobrevivió la carga? ¿Encontraste algo de eso?', 0),
(@ID, 'esMX', '<Moxie parece frenética de preocupación.>$B$B¿Sobrevivió la carga? ¿Encontraste algo de eso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guauu! Ciertamente, has encontrado mucho más de lo que esperaba. No estoy segura de cuánto pensó Drazzit que íbamos a recuperar aquí, pero tendrá que estar contento con esto por ahora.', 0),
(@ID, 'esMX', '¡Guauu! Ciertamente, has encontrado mucho más de lo que esperaba. No estoy segura de cuánto pensó Drazzit que íbamos a recuperar aquí, pero tendrá que estar contento con esto por ahora.', 0);
-- 11208 Envío para Drazzit
-- https://es.wowhead.com/quest=11208
-- https://wow-es.gamepedia.com/Misión:Envío para Drazzit
SET @ID := 11208;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Si?', 0),
(@ID, 'esMX', '¿Si?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Drazzit coge el cargamento.>$B$B¡Estoy tan hambriento que podría comerme un dragón! Menos mal que Moxie trajo parte del cargamento. ¡Nos hemos visto obligados a apostar a los dados contra el ogro para conseguir lo que hubiera matado en sus cacerías!', 0),
(@ID, 'esMX', '<Drazzit coge el cargamento.>$B$B¡Estoy tan hambriento que podría comerme un dragón! Menos mal que Moxie trajo parte del cargamento. ¡Nos hemos visto obligados a apostar a los dados contra el ogro para conseguir lo que hubiera matado en sus cacerías!', 0);

-- 1259 Teniente Paval Reethe
-- https://es.wowhead.com/quest=1259
-- https://wow-es.gamepedia.com/Misión:Teniente Paval Reethe
SET @ID := 1259;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Deseas información sobre algún miembro de la Guardia de Theramore en concreto? Reethe, ¿no?$B$BDame un momento para que encuentre el libro correcto.', 0),
(@ID, 'esMX', 'Hola, $n. ¿Deseas información sobre algún miembro de la Guardia de Theramore en concreto? Reethe, ¿no?$B$BDame un momento para que encuentre el libro correcto.', 0);
-- 1319 El escudo negro
-- https://es.classic.wowhead.com/quest=1319
SET @ID := 1319;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres enseñarme algo?', 0),
(@ID, 'esMX', '¿Quieres enseñarme algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, esa pieza de metal que tienes ahí es interesante. Es evidente que no es obra de ninguno de los herreros que conozco a este lado del mar. Y desde luego, tampoco es obra mía.', 0),
(@ID, 'esMX', 'Vaya, esa pieza de metal que tienes ahí es interesante. Es evidente que no es obra de ninguno de los herreros que conozco a este lado del mar. Y desde luego, tampoco es obra mía.', 0);
-- 1285 Los hombres de Daelin
-- https://es.classic.wowhead.com/quest=1285
SET @ID := 1285;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Desaparecido? Eso, dicho por el tesorero, quiere decir que es un traidor.$B$BSin duda es uno de esos estúpidos que traicionó a los suyos, cegado por su lealtad al almirante Daelin. ¿No es una deliciosa ironía? Los desertores nos acusan de traicionar a la Alianza.', 0),
(@ID, 'esMX', '¿Desaparecido? Eso, dicho por el tesorero, quiere decir que es un traidor.$B$BSin duda es uno de esos estúpidos que traicionó a los suyos, cegado por su lealtad al almirante Daelin. ¿No es una deliciosa ironía? Los desertores nos acusan de traicionar a la Alianza.', 0);
-- 1286 Los desertores
-- https://es.classic.wowhead.com/quest=1286
SET @ID := 1286;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Vimes? Claro, no podía hacer este trabajo sucio él mismo, ¿verdad?', 0),
(@ID, 'esMX', '¿Te envía Vimes? Claro, no podía hacer este trabajo sucio él mismo, ¿verdad?', 0);
-- 1320 El escudo negro
-- https://es.classic.wowhead.com/quest=1320
SET @ID := 1320;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esa información no nos ayuda gran cosa, pero la tendremos en cuenta. Con suerte, alguna de las otras piezas de este misterio acabará encajando y nos proporcionará una idea más clara de lo que ocurrió.', 0),
(@ID, 'esMX', 'Esa información no nos ayuda gran cosa, pero la tendremos en cuenta. Con suerte, alguna de las otras piezas de este misterio acabará encajando y nos proporcionará una idea más clara de lo que ocurrió.', 0);
-- 1287 Los desertores
-- https://es.classic.wowhead.com/quest=1287
SET @ID := 1287;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enviaré al teniente Caldwell a tratar con los desertores en Punta Perdida. Además, le ordenaré que encuentre a Reethe. El pantano no es tan grande, podrá encontrar su rastro.', 0),
(@ID, 'esMX', 'Enviaré al teniente Caldwell a tratar con los desertores en Punta Perdida. Además, le ordenaré que encuentre a Reethe. El pantano no es tan grande, podrá encontrar su rastro.', 0);
-- 11184 SE BUSCA: Garrasangrienta el Voraz
-- https://es.wowhead.com/quest=11184
SET @ID := 11184;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces bastante satisfecho contigo mismo. ¿Vienes a reclamar la recompensa por ese monstruoso raptor?', 0),
(@ID, 'esMX', 'Pareces bastante satisfecho contigo mismo. ¿Vienes a reclamar la recompensa por ese monstruoso raptor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a Dios, alguien finalmente aceptó esa oferta. ¡Estaba pensando que podría necesitar triplicar la recompensa para matar a ese estúpido raptor, y nuestro presupuesto no podía permitírselo!', 0),
(@ID, 'esMX', 'Gracias a Dios, alguien finalmente aceptó esa oferta. ¡Estaba pensando que podría necesitar triplicar la recompensa para matar a ese estúpido raptor, y nuestro presupuesto no podía permitírselo!', 0);
-- 11217 Atrapa a un dragón por la cola
-- https://es.wowhead.com/quest=11217
SET @ID := 11217;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste alguna de la cola de vermis?', 0),
(@ID, 'esMX', '¿Encontraste alguna de la cola de vermis?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias! Esto ayudará a que nuestros muchachos sigan saliendo al campo hasta que Moxie regrese con el resto de los suministros del accidente del zepelín.', 0),
(@ID, 'esMX', '¡Gracias! Esto ayudará a que nuestros muchachos sigan saliendo al campo hasta que Moxie regrese con el resto de los suministros del accidente del zepelín.', 0);
-- 11158 Plumas Cienorrojo
-- https://es.wowhead.com/quest=11158
SET @ID := 11158;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Brogg te mira esperanzado.>$B$B¿Traes plumas a Brogg?', 0),
(@ID, 'esMX', '<Brogg te mira esperanzado.>$B$B¿Traes plumas a Brogg?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Brogg acepta las plumas.>$B$BBrogg satisfecho con estas plumas. Magia muy fuerte. Brogg no sabe qué hacen las aves rapaces para dar poder a las plumas, pero las plumas de las aves rapaces siempre son las mejores para los rituales.', 0),
(@ID, 'esMX', '<Brogg acepta las plumas.>$B$BBrogg satisfecho con estas plumas. Magia muy fuerte. Brogg no sabe qué hacen las aves rapaces para dar poder a las plumas, pero las plumas de las aves rapaces siempre son las mejores para los rituales.', 0);
-- 11160 El estandarte de los Quebrantarrocas
-- https://es.wowhead.com/quest=11160
SET @ID := 11160;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes estandarte Quebrantarrocas?', 0),
(@ID, 'esMX', '¿Traes estandarte Quebrantarrocas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes el agradecimiento de Brogg, $n. Brogg tiene grandes planes para el estandarte del clan.', 0),
(@ID, 'esMX', 'Tienes el agradecimiento de Brogg, $n. Brogg tiene grandes planes para el estandarte del clan.', 0);
-- 11161 La esencia de la animadversión
-- https://es.wowhead.com/quest=11161
SET @ID := 11161;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las esencias? ¡Brogg debe tenerlas para vengar a sus amigos!', 0),
(@ID, 'esMX', '¿Tienes las esencias? ¡Brogg debe tenerlas para vengar a sus amigos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes el agradecimiento de Brogg, $n. Una vez que Brogg agregue su magia al tótem, podrá redimir los espíritus de los amigos caídos de Brogg.', 0),
(@ID, 'esMX', 'Tienes el agradecimiento de Brogg, $n. Una vez que Brogg agregue su magia al tótem, podrá redimir los espíritus de los amigos caídos de Brogg.', 0);
-- 11143 Una conexión sombría
-- https://es.wowhead.com/quest=11143
SET @ID := 11143;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Capitán Vimes cree que los Tótem Siniestro están detrás de la destrucción de Posada Reposo Umbrío? No habrían sido los primeros en mi lista de sospechosos, pero si el capitán Vimes te envió aquí para seguir una pista, debe tener sus razones. Independientemente, los Tótem Siniestro han sido una espina clavada en nuestro costado durante algún tiempo y siempre nos alegra tener ayuda adicional.', 0),
(@ID, 'esMX', '¿El Capitán Vimes cree que los Tótem Siniestro están detrás de la destrucción de Posada Reposo Umbrío? No habrían sido los primeros en mi lista de sospechosos, pero si el capitán Vimes te envió aquí para seguir una pista, debe tener sus razones. Independientemente, los Tótem Siniestro han sido una espina clavada en nuestro costado durante algún tiempo y siempre nos alegra tener ayuda adicional.', 0);
-- 11159 Espíritus del Bastión Quebrantarrocas
-- https://es.wowhead.com/quest=11159
SET @ID := 11159;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Brogg debe saberlo, ¿has traído la paz a los espíritus violentos Quebrantarrocas?', 0),
(@ID, 'esMX', 'Brogg debe saberlo, ¿has traído la paz a los espíritus violentos Quebrantarrocas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Brogg te agradece tu ayuda, aunque sabe que el señor supremo Mok\'Morokk nunca lo hará. Al menos, los sobrevivientes Quebrantarrocas pueden finalmente concentrarse en los problemas con los vivos y dejar a los muertos donde pertenecen. Solo queda una cosa por hacer para Brogg.', 0),
(@ID, 'esMX', 'Brogg te agradece tu ayuda, aunque sabe que el señor supremo Mok\'Morokk nunca lo hará. Al menos, los sobrevivientes Quebrantarrocas pueden finalmente concentrarse en los problemas con los vivos y dejar a los muertos donde pertenecen. Solo queda una cosa por hacer para Brogg.', 0);
-- 11162 Reta al Vuelo Negro
-- https://es.wowhead.com/quest=11162
SET @ID := 11162;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Brogg se vengará!', 0),
(@ID, 'esMX', '¡Brogg se vengará!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Brogg escucha mientras relatas tu experiencia en la entrada de la guarida de Onyxia>.$B$BBrogg sospechaba que Onyxia sería demasiado cobarde para enfrentarte a ti. Al igual que el vuelo del dragón negro para atacar cuando la victoria está garantizada.$B$BBrogg está agradecido por tu ayuda, $n, y nunca olvidará lo que has hecho por él. Brogg nunca renunciará a su búsqueda para traer Quebrantarrocas de regreso a donde pertenecen.', 0),
(@ID, 'esMX', '<Brogg escucha mientras relatas tu experiencia en la entrada de la guarida de Onyxia>.$B$BBrogg sospechaba que Onyxia sería demasiado cobarde para enfrentarte a ti. Al igual que el vuelo del dragón negro para atacar cuando la victoria está garantizada.$B$BBrogg está agradecido por tu ayuda, $n, y nunca olvidará lo que has hecho por él. Brogg nunca renunciará a su búsqueda para traer Quebrantarrocas de regreso a donde pertenecen.', 0);
-- 11144 Confirmando la sospecha
-- https://es.wowhead.com/quest=11144
SET @ID := 11144;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste encontrar algún rastro?', 0),
(@ID, 'esMX', '¿Pudiste encontrar algún rastro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán Darill echa un vistazo al plan de batalla.>$B$BYo diría que no hay nada más claro que esto. Se han encargado de luchar contra los asentamientos humanos en el área y no tengo dudas de que Theramore es el siguiente en su lista.', 0),
(@ID, 'esMX', '<El capitán Darill echa un vistazo al plan de batalla.>$B$BYo diría que no hay nada más claro que esto. Se han encargado de luchar contra los asentamientos humanos en el área y no tengo dudas de que Theramore es el siguiente en su lista.', 0);
-- 11148 Armas de los Tótem Siniestro
-- https://es.wowhead.com/quest=11148
SET @ID := 11148;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste esas armas Pezuñanegra?', 0),
(@ID, 'esMX', '¿Conseguiste esas armas Pezuñanegra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán Darill inspecciona el armamento que trajiste de la Aldea Pezuñanegra.>$B$BNo hay duda al respecto. Estos coinciden exactamente con la descripción, pero solo hay un problema: nunca se han usado en la batalla. El Poblado Pezuñanegra no debe ser el único puesto de Tótem Siniestro en el pantano.', 0),
(@ID, 'esMX', '<El capitán Darill inspecciona el armamento que trajiste de la Aldea Pezuñanegra.>$B$BNo hay duda al respecto. Estos coinciden exactamente con la descripción, pero solo hay un problema: nunca se han usado en la batalla. El Poblado Pezuñanegra no debe ser el único puesto de Tótem Siniestro en el pantano.', 0);
-- 11149 La ayuda de Tabetha
-- https://es.wowhead.com/quest=11149
SET @ID := 11149;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que quieres que adivine los tótems siniestros, ¿eh? ¿Y qué dirás cuando te diga que no es necesario?', 0),
(@ID, 'esMX', 'Así que quieres que adivine los tótems siniestros, ¿eh? ¿Y qué dirás cuando te diga que no es necesario?', 0);
-- 11150 ¡Arrasa el Puesto Cuernoatroz!
-- https://es.wowhead.com/quest=11150
SET @ID := 11150;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho un buen uso de esa antorcha?', 0),
(@ID, 'esMX', '¿Has hecho un buen uso de esa antorcha?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que los Tótem Siniestro hayan captado el mensaje. Cualquier intento de regresar se encontrará con algo mucho peor que una simple antorcha. Mis aprendices y yo nos encargaremos de eso.', 0),
(@ID, 'esMX', 'Espero que los Tótem Siniestro hayan captado el mensaje. Cualquier intento de regresar se encontrará con algo mucho peor que una simple antorcha. Mis aprendices y yo nos encargaremos de eso.', 0);
-- 11185 La carta de la boticaria
-- https://es.wowhead.com/quest=11185
SET @ID := 11185;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es lo que llevas, $c?', 0),
(@ID, 'esMX', '¿Qué es lo que llevas, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Andello lee la carta, sorprendido por su contenido.>$B$BDurante mucho tiempo hemos tenido dudas sobre la cooperación entre la Horda y los Renegados, y esto solo confirma esas sospechas. Con el respaldo de la magia y las armas de los Renegados, los Tótem Siniestro se convertirían en un enemigo aún más temible. El equilibrio de poder en Kalimdor podría cambiar considerablemente.', 0),
(@ID, 'esMX', '<Andello lee la carta, sorprendido por su contenido.>$B$BDurante mucho tiempo hemos tenido dudas sobre la cooperación entre la Horda y los Renegados, y esto solo confirma esas sospechas. Con el respaldo de la magia y las armas de los Renegados, los Tótem Siniestro se convertirían en un enemigo aún más temible. El equilibrio de poder en Kalimdor podría cambiar considerablemente.', 0);
-- 11151 Justicia para los Hyal
-- https://es.wowhead.com/quest=11151
SET @ID := 11151;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El capitán escucha tu informe con atención>.$B$BHemos vengado a James y su familia, pero ni siquiera eso puede restaurar lo que fue destruido.', 0),
(@ID, 'esMX', '<El capitán escucha tu informe con atención>.$B$BHemos vengado a James y su familia, pero ni siquiera eso puede restaurar lo que fue destruido.', 0);
-- 11152 Al fin paz
-- https://es.wowhead.com/quest=11152
SET @ID := 11152;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pusiste la corona?', 0),
(@ID, 'esMX', '¿Pusiste la corona?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Capitán Vimes sonríe levemente mientras relatas los eventos que presenciaste en la tumba de la familia Hyal.>$B$BEs bueno saber que lo entienden. No les hablaste de James, ¿verdad?$B$BLe entregaré el mensaje de su esposa, pero dudo que lo entienda.', 0),
(@ID, 'esMX', '<El Capitán Vimes sonríe levemente mientras relatas los eventos que presenciaste en la tumba de la familia Hyal.>$B$BEs bueno saber que lo entienden. No les hablaste de James, ¿verdad?$B$BLe entregaré el mensaje de su esposa, pero dudo que lo entienda.', 0);
-- 1070 Estar de guardia en Espolón
-- https://es.classic.wowhead.com/quest=1070
SET @ID := 1070;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, vienes de Vallefresno a instancias de Tara... ¡Cuánto echo de menos mi casa, mis amigos y a ella! Le deben estar yendo bien las cosas con las centinelas si está encargando tareas a aventureros. Me enorgullezco de ella.$B$BUn placer conocerte, $n.', 0),
(@ID, 'esMX', 'Ah, vienes de Vallefresno a instancias de Tara... ¡Cuánto echo de menos mi casa, mis amigos y a ella! Le deben estar yendo bien las cosas con las centinelas si está encargando tareas a aventureros. Me enorgullezco de ella.$B$BUn placer conocerte, $n.', 0);

-- 1085 Estar de guardia en Espolón
-- https://es.classic.wowhead.com/quest=1085
SET @ID := 1085;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Traicionera... traicionera y peligrosa, así es esta tierra.$B$BPero estoy aquí para demostrar a los elfos de la noche que todo va un poco mejor con la ayuda de la vieja ingeniería de toda la vida y una pizca de magia.$B$BVeamos, jurar dejar la magia completamente no ayudará a los elfos de la noche... la necesitan. El mundo la necesita. Y, con la ingeniería y la alquimia, nunca te puedes equivocar. Las posibilidades son infinitas.', 0),
(@ID, 'esMX', 'Traicionera... traicionera y peligrosa, así es esta tierra.$B$BPero estoy aquí para demostrar a los elfos de la noche que todo va un poco mejor con la ayuda de la vieja ingeniería de toda la vida y una pizca de magia.$B$BVeamos, jurar dejar la magia completamente no ayudará a los elfos de la noche... la necesitan. El mundo la necesita. Y, con la ingeniería y la alquimia, nunca te puedes equivocar. Las posibilidades son infinitas.', 0);
-- 1071 Una tregua para el gnomo
-- https://es.classic.wowhead.com/quest=1071
SET @ID := 1071;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va el final de la batalla, $n?', 0),
(@ID, 'esMX', '¿Cómo va el final de la batalla, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchísimas gracias por tu ayuda, $n. Vuelves justo a tiempo.$B$BCreo que tengo el plan perfecto... explosivos. No, ese no es el plan, pero es parte del plan.$B$BVerás, para asustar a los goblins, he estado utilizando explosivos muy potentes, no te preocupes, no son tan peligrosos como piensa todo el mundo. Puedo llevarles de un lado para otro como si fueran ganado con unas cuántas detonaciones en los lados de la montaña, pero llevo unos días con falta de suministros...', 0),
(@ID, 'esMX', 'Muchísimas gracias por tu ayuda, $n. Vuelves justo a tiempo.$B$BCreo que tengo el plan perfecto... explosivos. No, ese no es el plan, pero es parte del plan.$B$BVerás, para asustar a los goblins, he estado utilizando explosivos muy potentes, no te preocupes, no son tan peligrosos como piensa todo el mundo. Puedo llevarles de un lado para otro como si fueran ganado con unas cuántas detonaciones en los lados de la montaña, pero llevo unos días con falta de suministros...', 0);
-- 1072 Un viejo colega
-- https://es.classic.wowhead.com/quest=1072
SET @ID := 1072;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahhh... ¿Te envía Gaxim, eh? ¿Cómo sé que no me estás mintiendo? ¿Mm? ¿Mmm...?', 0),
(@ID, 'esMX', 'Ahhh... ¿Te envía Gaxim, eh? ¿Cómo sé que no me estás mintiendo? ¿Mm? ¿Mmm...?', 0);
-- 1073 Ineptitud + Productos químicos = Diversión
-- https://es.classic.wowhead.com/quest=1073
SET @ID := 1073;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo hacerte el nitromirgliceronio si no tengo las pociones... son vitales para crearlo.', 0),
(@ID, 'esMX', 'No puedo hacerte el nitromirgliceronio si no tengo las pociones... son vitales para crearlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto servirá.$B$BSi no supiera que no es así, diría que tienes conocimientos de alquimia. Bien, bien... el mundo no gira solo con espadas y magia, ¿sabes?', 0),
(@ID, 'esMX', 'Esto servirá.$B$BSi no supiera que no es así, diría que tienes conocimientos de alquimia. Bien, bien... el mundo no gira solo con espadas y magia, ¿sabes?', 0);
-- 1074 Ineptitud + Productos químicos = Diversión
-- https://es.classic.wowhead.com/quest=1074
SET @ID := 1074;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡qué bien! Ya has vuelto.', 0),
(@ID, 'esMX', 'Ah, ¡qué bien! Ya has vuelto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has completado tu tarea sin problemas, $n.$B$BEl NG-5 es el componente inequívoco de la receta para hacer explotar los carros de dinamita.$B$B¿Qué? Sí, dinamita... carros llenos de dinamita. Es la distracción perfecta, te lo digo yo... espera y verás.', 0),
(@ID, 'esMX', 'Has completado tu tarea sin problemas, $n.$B$BEl NG-5 es el componente inequívoco de la receta para hacer explotar los carros de dinamita.$B$B¿Qué? Sí, dinamita... carros llenos de dinamita. Es la distracción perfecta, te lo digo yo... espera y verás.', 0);
-- 1075 Un pergamino de Mauren
-- https://es.classic.wowhead.com/quest=1075
SET @ID := 1075;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, este hechizo que necesitas... que te permita detonar explosivos a distancia... mmm.', 0),
(@ID, 'esMX', 'Bien, este hechizo que necesitas... que te permita detonar explosivos a distancia... mmm.', 0);
-- 1076 Demonios en los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=1076
SET @ID := 1076;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has encontrado el componente que necesito?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has encontrado el componente que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame unos minutos y tendré el pergamino listo.', 0),
(@ID, 'esMX', 'Dame unos minutos y tendré el pergamino listo.', 0);
-- 1077 Entrega especial para Gaxim
-- https://es.classic.wowhead.com/quest=1077
SET @ID := 1077;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja! ¡Has vuelto! ¿Lo tienes? ¿Tienes el hechizo?', 0),
(@ID, 'esMX', '¡Ja, ja! ¡Has vuelto! ¿Lo tienes? ¿Tienes el hechizo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso, $n! Bien hecho.$B$BEste conjuro, mezclado con el NG-5, debería lograr el explosivo remoto perfecto.$B$BPodremos crear una distracción fantástica para que puedas colarte y robar las cartas y los planos de ingeniería de Ventura y Cía.$B$BSeguro que eso paraliza de alguna forma sus acciones de deforestación.', 0),
(@ID, 'esMX', '¡Maravilloso, $n! Bien hecho.$B$BEste conjuro, mezclado con el NG-5, debería lograr el explosivo remoto perfecto.$B$BPodremos crear una distracción fantástica para que puedas colarte y robar las cartas y los planos de ingeniería de Ventura y Cía.$B$BSeguro que eso paraliza de alguna forma sus acciones de deforestación.', 0);
-- 1079 Operaciones secretas: plan A
-- https://es.classic.wowhead.com/quest=1079
SET @ID := 1079;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los planos, $n?', 0),
(@ID, 'esMX', '¿Has conseguido los planos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Un gran golpe para Ventura y Cía.$B$BPodremos encontrar los puntos débiles de sus máquinas e incorporar sus diseños a nuestras propias creaciones. ¡Este es un gran día!', 0),
(@ID, 'esMX', '¡Increíble! Un gran golpe para Ventura y Cía.$B$BPodremos encontrar los puntos débiles de sus máquinas e incorporar sus diseños a nuestras propias creaciones. ¡Este es un gran día!', 0);
-- 1080 Operaciones secretas: plan B
-- https://es.classic.wowhead.com/quest=1080
SET @ID := 1080;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal fue todo, $n?', 0),
(@ID, 'esMX', '¿Qué tal fue todo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble, $n! Kaela y las Centinelas estarán encantadas. Con tu habilidad y mis creaciones, somos imparables.', 0),
(@ID, 'esMX', '¡Increíble, $n! Kaela y las Centinelas estarán encantadas. Con tu habilidad y mis creaciones, somos imparables.', 0);
-- 1057 La reconquista de La Vega Carbonizada
-- https://es.classic.wowhead.com/quest=1057
SET @ID := 1057;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay mucho trabajo por hacer antes de poder restaurar la gloria que, antiguamente, reinaba en La Vega Carbonizada.$B$B¡Elimina esas amenazas de la zona, $n! Solo entonces podremos reclamar lo que le pertenece a la naturaleza.', 0),
(@ID, 'esMX', 'Hay mucho trabajo por hacer antes de poder restaurar la gloria que, antiguamente, reinaba en La Vega Carbonizada.$B$B¡Elimina esas amenazas de la zona, $n! Solo entonces podremos reclamar lo que le pertenece a la naturaleza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que los Furia Sangrienta han sufrido una pérdida tan grande, quizás pueda comenzar el verdadero trabajo de restauración...', 0),
(@ID, 'esMX', 'Ahora que los Furia Sangrienta han sufrido una pérdida tan grande, quizás pueda comenzar el verdadero trabajo de restauración...', 0);
-- 1059 La reconquista de La Vega Carbonizada
-- https://es.classic.wowhead.com/quest=1059
SET @ID := 1059;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El vigilante Albagorm demostró inteligencia al enviarte con tanta urgencia.$B$BVeamos si conseguimos invocar ayuda del gran bosque para viajar a La Vega Carbonizada antes de que sea demasiado tarde.', 0),
(@ID, 'esMX', 'El vigilante Albagorm demostró inteligencia al enviarte con tanta urgencia.$B$BVeamos si conseguimos invocar ayuda del gran bosque para viajar a La Vega Carbonizada antes de que sea demasiado tarde.', 0);
-- 1437 Buscando para Vahlarriel
-- https://es.classic.wowhead.com/quest=1437
SET @ID := 1437;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando examinas los restos del carro, te das cuenta de que fue atacado tanto por hechizos como por armas. Parece que el ataque llegó por un flanco y que fue rápido; no hay restos de sangre y tampoco cuerpos.$B$BQuienquiera que atacara el carro era eficiente y rápido.', 0),
(@ID, 'esMX', 'Cuando examinas los restos del carro, te das cuenta de que fue atacado tanto por hechizos como por armas. Parece que el ataque llegó por un flanco y que fue rápido; no hay restos de sangre y tampoco cuerpos.$B$BQuienquiera que atacara el carro era eficiente y rápido.', 0);
-- 1465 Buscando para Vahlarriel
-- https://es.classic.wowhead.com/quest=1465
SET @ID := 1465;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es exasperante! ¡Todo este asunto!$B$BLos dos fueron advertidos de lo peligroso que sería venir aquí. Y ahora han desaparecido... o algo peor.$B$B¿Dices que viste huellas que se dirigían a un fuerte cercano? Esa es nuestra mejor apuesta.$B$BPor lo que dicen los habitantes de la zona, esa fortaleza está infestada de miembros del Filo Ardiente. Orcos. Orcos que se han consagrado a la causa demoníaca. No representan la mayoría de las creencias de la Horda, pero son malvados y, si te pillan husmeando por allí, te matarán en cuanto te vean.', 0),
(@ID, 'esMX', '¡Esto es exasperante! ¡Todo este asunto!$B$BLos dos fueron advertidos de lo peligroso que sería venir aquí. Y ahora han desaparecido... o algo peor.$B$B¿Dices que viste huellas que se dirigían a un fuerte cercano? Esa es nuestra mejor apuesta.$B$BPor lo que dicen los habitantes de la zona, esa fortaleza está infestada de miembros del Filo Ardiente. Orcos. Orcos que se han consagrado a la causa demoníaca. No representan la mayoría de las creencias de la Horda, pero son malvados y, si te pillan husmeando por allí, te matarán en cuanto te vean.', 0);
-- 1438 Buscando para Vahlarriel
-- https://es.classic.wowhead.com/quest=1438
SET @ID := 1438;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a Elune, por fin alguien ha venido en mi ayuda. Te lo ruego, $c, tienes que ayudarme. Mi hermano Tyranis y yo fuimos capturados y traídos hasta aquí por el Filo Ardiente. ¡Creo que quieren ofrecerme como sacrificio a sus demonios!$B$BSabía que venir a Desolace era un error, pero Tyranis... últimamente ha desarrollado un ferviente interés por todo lo arcano, incluso contra la voluntad de nuestra gente. Decidió emprender este camino, a pesar de haber oído historias de los demonios que infestan estas tierras.$B$BNo sé cómo está pero... temo lo peor.', 0),
(@ID, 'esMX', 'Gracias a Elune, por fin alguien ha venido en mi ayuda. Te lo ruego, $c, tienes que ayudarme. Mi hermano Tyranis y yo fuimos capturados y traídos hasta aquí por el Filo Ardiente. ¡Creo que quieren ofrecerme como sacrificio a sus demonios!$B$BSabía que venir a Desolace era un error, pero Tyranis... últimamente ha desarrollado un ferviente interés por todo lo arcano, incluso contra la voluntad de nuestra gente. Decidió emprender este camino, a pesar de haber oído historias de los demonios que infestan estas tierras.$B$BNo sé cómo está pero... temo lo peor.', 0);
-- 1439 Buscando a Tyranis
-- https://es.classic.wowhead.com/quest=1439
SET @ID := 1439;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Temo que Tyranis intente desvelar los secretos del Filo Ardiente y unirse a ellos si lo permiten... Siempre ha ansiado el poder mágico que proporciona a quienes se acercan a ellos.$B$BNo sé si tengo el valor para volver a casa con la noticia de que el espíritu de Tyranis está flirteando con tales peligros. Entre mi gente, ya es bastante terrible perseguir tales cosas... y convertirse en aquello de lo que intentamos protegernos... es... mucho peor.', 0),
(@ID, 'esMX', 'Temo que Tyranis intente desvelar los secretos del Filo Ardiente y unirse a ellos si lo permiten... Siempre ha ansiado el poder mágico que proporciona a quienes se acercan a ellos.$B$BNo sé si tengo el valor para volver a casa con la noticia de que el espíritu de Tyranis está flirteando con tales peligros. Entre mi gente, ya es bastante terrible perseguir tales cosas... y convertirse en aquello de lo que intentamos protegernos... es... mucho peor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es terrible! Pero supongo que era necesario. Si no lo hubieras hecho tú, seguramente mi gente habría intervenido. Supongo que debería darte las gracias... perdóname si no parezco muy sincera. No es mi intención ofenderte.$B$BAhora que sé qué suerte corrió mi hermano, parece que ha llegado el momento de que huya. Si aún sigue en pie tu ofrecimiento, aceptaré tu ayuda para escapar de este horrible lugar.$B$BCuando estés $glisto:lista;, podemos emprender nuestro camino hacia la salvación.', 0),
(@ID, 'esMX', '¡Esto es terrible! Pero supongo que era necesario. Si no lo hubieras hecho tú, seguramente mi gente habría intervenido. Supongo que debería darte las gracias... perdóname si no parezco muy sincera. No es mi intención ofenderte.$B$BAhora que sé qué suerte corrió mi hermano, parece que ha llegado el momento de que huya. Si aún sigue en pie tu ofrecimiento, aceptaré tu ayuda para escapar de este horrible lugar.$B$BCuando estés $glisto:lista;, podemos emprender nuestro camino hacia la salvación.', 0);
-- 1382 Extraña alianza
-- https://es.classic.wowhead.com/quest=1382
SET @ID := 1382;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Largo de aquí! Los Gelkis no te quieren aquí. ¡¡Márchate!!$B$BVuelve cuando hayas matado a muchos Magram. Entonces hablaré contigo.', 0),
(@ID, 'esMX', '¡Largo de aquí! Los Gelkis no te quieren aquí. ¡¡Márchate!!$B$BVuelve cuando hayas matado a muchos Magram. Entonces hablaré contigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu nombre se susurra entre los Gelkis. Tienes mucha sangre Magram en las manos. Y eso está bien.$B$BTambién estará bien que hablemos. Hablemos de qué puedes hacer por los Gelkis y de qué podemos hacer nosotros por ti.', 0),
(@ID, 'esMX', 'Tu nombre se susurra entre los Gelkis. Tienes mucha sangre Magram en las manos. Y eso está bien.$B$BTambién estará bien que hablemos. Hablemos de qué puedes hacer por los Gelkis y de qué podemos hacer nosotros por ti.', 0);
-- 1368 La alianza con los Gelkis
-- https://es.classic.wowhead.com/quest=1368
SET @ID := 1368;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus dos pies pisan la tierra de Gelkis. ¡Tu no eres bienvenido aqui!$B$BDemuestra que buscas amistad con los Gelkis. Mata al centauro Magram. Regresa cuando el suelo esté mojado con sangre Magram.', 0),
(@ID, 'esMX', 'Tus dos pies pisan la tierra de Gelkis. ¡Tu no eres bienvenido aqui!$B$BDemuestra que buscas amistad con los Gelkis. Mata al centauro Magram. Regresa cuando el suelo esté mojado con sangre Magram.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tierra me habla. Y me dice que has matado muchos Magram. Y eso está bien.$B$BSi eres $gamigo:amiga; de los Gelkis, escucha. Tengo dos misiones más para ti.', 0),
(@ID, 'esMX', 'La tierra me habla. Y me dice que has matado muchos Magram. Y eso está bien.$B$BSi eres $gamigo:amiga; de los Gelkis, escucha. Tengo dos misiones más para ti.', 0);
-- 1384 Asalta a los Kolkar
-- https://es.classic.wowhead.com/quest=1384
SET @ID := 1384;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los talismanes? ¿Demostraste a los Kolkar que son débiles?', 0),
(@ID, 'esMX', '¿Tienes los talismanes? ¿Demostraste a los Kolkar que son débiles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho una buena cosa para los Gelkis. Los Kolkar son débiles y morirán. Su magia es patética; no les salvará. ¡Les enseñaste esto y su miedo los hará aún más débiles!$B$BY en nuestras tierras... los débiles mueren pronto.', 0),
(@ID, 'esMX', 'Has hecho una buena cosa para los Gelkis. Los Kolkar son débiles y morirán. Su magia es patética; no les salvará. ¡Les enseñaste esto y su miedo los hará aún más débiles!$B$BY en nuestras tierras... los débiles mueren pronto.', 0);
-- 1370 ¡A robar provisiones!
-- https://es.classic.wowhead.com/quest=1370
SET @ID := 1370;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vuelve cuando hayas demostrado a los Gelkis tu valía!', 0),
(@ID, 'esMX', '¡Vuelve cuando hayas demostrado a los Gelkis tu valía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. ¡Ya estoy oyendo cómo les rugen las tripas a esos Magram!$B$BDaré esta carne a los Gelkis. Podremos combatir sin descanso muchos días.$B$BLo que has hecho es bueno para los Gelkis, $n.', 0),
(@ID, 'esMX', 'Bien. ¡Ya estoy oyendo cómo les rugen las tripas a esos Magram!$B$BDaré esta carne a los Gelkis. Podremos combatir sin descanso muchos días.$B$BLo que has hecho es bueno para los Gelkis, $n.', 0);
-- 1373 Ongeku
-- https://es.classic.wowhead.com/quest=1373
SET @ID := 1373;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0),
(@ID, 'esMX', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este es el fragmento del que susurró la tierra. ¡Puedo sentir una magia fuerte en él! Usaré esta magia contra los enemigos de los Gelkis.$B$BHas hecho una tarea más por nosotros, $n. Quizás pronto te llamemos amigo', 0),
(@ID, 'esMX', 'Sí, este es el fragmento del que susurró la tierra. ¡Puedo sentir una magia fuerte en él! Usaré esta magia contra los enemigos de los Gelkis.$B$BHas hecho una tarea más por nosotros, $n. Quizás pronto te llamemos amigo', 0);
-- 1374 Khan Jehn
-- https://es.classic.wowhead.com/quest=1374
SET @ID := 1374;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0),
(@ID, 'esMX', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Khan Jehn era fuerte, pero estúpido. Pensó que su propia fuerza era grandiosa. No vio que la magia de la tierra es más fuerte. El centauro Magram ahora caerá sin su líder, ¡y los Gelkis gobernarán algún día!', 0),
(@ID, 'esMX', 'Khan Jehn era fuerte, pero estúpido. Pensó que su propia fuerza era grandiosa. No vio que la magia de la tierra es más fuerte. El centauro Magram ahora caerá sin su líder, ¡y los Gelkis gobernarán algún día!', 0);

-- 1380 Khan Hratha
-- https://es.classic.wowhead.com/quest=1380
SET @ID := 1380;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Khan Hratha está muerto? ¿Tienes el fragmento de la llave?', 0),
(@ID, 'esMX', '¿Khan Hratha está muerto? ¿Tienes el fragmento de la llave?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Está muerto! ¡Khan Hratha está muerto! ¡Y ahora caerán los Maraudine! Cuando los Gelkis gobiernen esta tierra, $n, te recordaremos. Y los espíritus de la tierra cantarán tu nombre para siempre.', 0),
(@ID, 'esMX', '¡Está muerto! ¡Khan Hratha está muerto! ¡Y ahora caerán los Maraudine! Cuando los Gelkis gobiernen esta tierra, $n, te recordaremos. Y los espíritus de la tierra cantarán tu nombre para siempre.', 0);
-- 1385 Políticas brutales
-- https://es.classic.wowhead.com/quest=1385
SET @ID := 1385;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vete ahora, o el Magram te aplastará! Para ser nuestro amigo, debes matar a Gelkis.', 0),
(@ID, 'esMX', '¡Vete ahora, o el Magram te aplastará! Para ser nuestro amigo, debes matar a Gelkis.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos Gelkis muertos. Me gusta eso. Quizás puedas hacer más cosas que me gusten. Quizás tú y el Magram puedan ser amigos.', 0),
(@ID, 'esMX', 'Muchos Gelkis muertos. Me gusta eso. Quizás puedas hacer más cosas que me gusten. Quizás tú y el Magram puedan ser amigos.', 0);
-- 1367 La alianza con los Magram
-- https://es.classic.wowhead.com/quest=1367
SET @ID := 1367;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vete! Los Magram no hablan con los débiles. ¡Los matamos!$B$BSi quieres hablar conmigo, demuéstrame que eres fuerte. Regresa después de matar a muchos Gelkis.', 0),
(@ID, 'esMX', '¡Vete! Los Magram no hablan con los débiles. ¡Los matamos!$B$BSi quieres hablar conmigo, demuéstrame que eres fuerte. Regresa después de matar a muchos Gelkis.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Gelkis lloran cuando escuchan tu nombre, $n. Te temen y te odian. ¡Te odian como odian al Magram!$B$BQuizás eres fuerte como el Magram. Veremos...', 0),
(@ID, 'esMX', 'Los Gelkis lloran cuando escuchan tu nombre, $n. Te temen y te odian. ¡Te odian como odian al Magram!$B$BQuizás eres fuerte como el Magram. Veremos...', 0);
-- 1386 Ataca a los Kolkar
-- https://es.classic.wowhead.com/quest=1386
SET @ID := 1386;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Le tienes miedo a los Kolkar? ¿Por qué no los matas? Quizás has olvidado cómo matar. ¡Date prisa y mata a los Kolkar antes de que mueran!', 0),
(@ID, 'esMX', '¿Le tienes miedo a los Kolkar? ¿Por qué no los matas? Quizás has olvidado cómo matar. ¡Date prisa y mata a los Kolkar antes de que mueran!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los Kolkar te temen ahora! Espero que te hayas reído cuando los mataste. Es mejor reír cuando matas, para que el enemigo pueda ver que es débil.', 0),
(@ID, 'esMX', '¡Los Kolkar te temen ahora! Espero que te hayas reído cuando los mataste. Es mejor reír cuando matas, para que el enemigo pueda ver que es débil.', 0);
-- 1369 Lágrimas rotas
-- https://es.classic.wowhead.com/quest=1369
SET @ID := 1369;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0),
(@ID, 'esMX', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes las lágrimas! Ahora los Gelkis sabrán que Theradras no los ayudará. ¡No llorará cuando los aplastemos! ¡El Magram gobernará!$B$BEres listo por ayudarnos, $n. Somos los mas fuertes.', 0),
(@ID, 'esMX', '¡Tienes las lágrimas! Ahora los Gelkis sabrán que Theradras no los ayudará. ¡No llorará cuando los aplastemos! ¡El Magram gobernará!$B$BEres listo por ayudarnos, $n. Somos los mas fuertes.', 0);
-- 1371 Un cacharro para Warug
-- https://es.classic.wowhead.com/quest=1371
SET @ID := 1371;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0),
(@ID, 'esMX', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí, esto es lo que quería! Haré que se mueva de nuevo. ¡Me hace reir!', 0),
(@ID, 'esMX', '¡Sí, esto es lo que quería! Haré que se mueva de nuevo. ¡Me hace reir!', 0);
-- 1387 Colección de orejas
-- https://es.classic.wowhead.com/quest=1387
SET @ID := 1387;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algún informe, $n?', 0),
(@ID, 'esMX', '¿Tienes algún informe, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, las orejas. Bien hecho.$B$BTu lealtad a la Alianza es incuestionable, $n. La sangre que derramaste en Desolace salvará muchas vidas, te lo aseguro.', 0),
(@ID, 'esMX', 'Ah, las orejas. Bien hecho.$B$BTu lealtad a la Alianza es incuestionable, $n. La sangre que derramaste en Desolace salvará muchas vidas, te lo aseguro.', 0);
-- 7065 Corrupción de la tierra y de la semilla
-- https://es.classic.wowhead.com/quest=7065
SET @ID := 7065;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento el peso de imponer mi súplica a las razas mortales, pero no nos quedan otras opciones. Las razas de Azeroth han demostrado sin lugar a dudas que pueden superar estos desafios cuando trabajan juntas, así que es a ellas a las que les pido ayuda.$B$BSolo espero que sea suficiente.$B$BZaetar, hermano de Remulos, trajo muchos dolores a este mundo y finalmente causó su propia muerte. Hay una lección en esto para todos nosotros si somos lo suficientemente sabios para verla.', 0),
(@ID, 'esMX', 'Siento el peso de imponer mi súplica a las razas mortales, pero no nos quedan otras opciones. Las razas de Azeroth han demostrado sin lugar a dudas que pueden superar estos desafios cuando trabajan juntas, así que es a ellas a las que les pido ayuda.$B$BSolo espero que sea suficiente.$B$BZaetar, hermano de Remulos, trajo muchos dolores a este mundo y finalmente causó su propia muerte. Hay una lección en esto para todos nosotros si somos lo suficientemente sabios para verla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas son maravillosas noticias, $n! ¡Gracias!$B$BAunque me preocupa que no pudieras recuperar los restos de Zaetar, ¿quién soy yo para cuestionar la voluntad del primogénito de Cenarius? Quizás ahora la voluntad de los centauros se doblegue y su sed de sangre se aplaque. No podemos hacer más que esperar.$B$BMe habían otorgado estos objetos para recompensar a quien nos ayudara si nuestra misión era exitosa. Puedes elegir uno como muestra de agradecimiento.', 0),
(@ID, 'esMX', '¡Estas son maravillosas noticias, $n! ¡Gracias!$B$BAunque me preocupa que no pudieras recuperar los restos de Zaetar, ¿quién soy yo para cuestionar la voluntad del primogénito de Cenarius? Quizás ahora la voluntad de los centauros se doblegue y su sed de sangre se aplaque. No podemos hacer más que esperar.$B$BMe habían otorgado estos objetos para recompensar a quien nos ayudara si nuestra misión era exitosa. Puedes elegir uno como muestra de agradecimiento.', 0);
-- 1458 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1458
SET @ID := 1458;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los sátiros son unas criaturas despreciables. La leyenda dice que están ligados de alguna forma a los elfos de la noche, pero no sé si creérmelo.$B$BCreo que esa leyenda surgió por ese elfo que los arrastró a la guerra hace unos años. El mundo no ha vuelto a ser el mismo desde entonces. Es mucho más peligroso y más terrorífico.', 0),
(@ID, 'esMX', 'Los sátiros son unas criaturas despreciables. La leyenda dice que están ligados de alguna forma a los elfos de la noche, pero no sé si creérmelo.$B$BCreo que esa leyenda surgió por ese elfo que los arrastró a la guerra hace unos años. El mundo no ha vuelto a ser el mismo desde entonces. Es mucho más peligroso y más terrorífico.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, bien, $n. No sé si esto es de buena calidad, pero si Zurdibrujo quería algo más específico, tenía que haberlo dejado claro antes de enviar a los RFecuperadores aquí fuera.$B$B¿Qué te pareces si te pones con el siguiente objeto de su lista?', 0),
(@ID, 'esMX', 'Bien, bien, $n. No sé si esto es de buena calidad, pero si Zurdibrujo quería algo más específico, tenía que haberlo dejado claro antes de enviar a los RFecuperadores aquí fuera.$B$B¿Qué te pareces si te pones con el siguiente objeto de su lista?', 0);
-- 1459 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1459
SET @ID := 1459;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento no poder decirte dónde podrías encontrar kodos y escórpidos. No conozco muy bien la zona y no tengo mucho tiempo para explorarla.', 0),
(@ID, 'esMX', 'Siento no poder decirte dónde podrías encontrar kodos y escórpidos. No conozco muy bien la zona y no tengo mucho tiempo para explorarla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres una gran ayuda, $n. Estás reduciendo al menos a la mitad mi estancia en Desolace. Gracias a ti, no tardaré en volver a Forjaz a calentarme los pies.$B$BCuando nos hayamos ocupado de esta lista y yo haya vuelto a casa, búscame. Te invitaré a una cerveza.$B$BPero hasta entonces, acabemos de reunir el resto de los componentes.', 0),
(@ID, 'esMX', 'Eres una gran ayuda, $n. Estás reduciendo al menos a la mitad mi estancia en Desolace. Gracias a ti, no tardaré en volver a Forjaz a calentarme los pies.$B$BCuando nos hayamos ocupado de esta lista y yo haya vuelto a casa, búscame. Te invitaré a una cerveza.$B$BPero hasta entonces, acabemos de reunir el resto de los componentes.', 0);
-- 1466 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1466
SET @ID := 1466;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni siquiera sabía que hubiera demonios de estos en Desolace. Me quedé en que la tierra la ocuparon los centauros hace años, cuando los elfos de la noche recogieron sus bártulos y se fueron.$B$BMe pregunto por qué se instalaron aquí, y como.', 0),
(@ID, 'esMX', 'Ni siquiera sabía que hubiera demonios de estos en Desolace. Me quedé en que la tierra la ocuparon los centauros hace años, cuando los elfos de la noche recogieron sus bártulos y se fueron.$B$BMe pregunto por qué se instalaron aquí, y como.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La verdad? Jamás lo habría pensado. Eres increíble, $n. Te enfrentas a demonios por el experimento de un mago... ¡y además vuelves de una pieza! ¡Buen trabajo!$B$BVoy a hablar personalmente a Roetten sobre ti cuando vuelva a Forjaz.', 0),
(@ID, 'esMX', '¿La verdad? Jamás lo habría pensado. Eres increíble, $n. Te enfrentas a demonios por el experimento de un mago... ¡y además vuelves de una pieza! ¡Buen trabajo!$B$BVoy a hablar personalmente a Roetten sobre ti cuando vuelva a Forjaz.', 0);
-- 1467 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1467
SET @ID := 1467;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, $n. El negocio va de maravilla. Los golpeteos de los yunques resuenan por todo Forjaz, los fuelles alimentan el fuego y mi mujer está haciéndome un postre especial para cenar. ¿No es estupenda la vida?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, $n. El negocio va de maravilla. Los golpeteos de los yunques resuenan por todo Forjaz, los fuelles alimentan el fuego y mi mujer está haciéndome un postre especial para cenar. ¿No es estupenda la vida?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, el paquete de Zurdibrujo de Desolace. Excelente. Aprecio mucho tu trabajo, $c y tu eficiencia. Me alegro de tenerte a bordo, al menos para este trabajito.$B$BTengo tu pago aquí mismo. Que se sepa que Recuperadores S.A. siempre paga bien por una dura semana de trabajo.', 0),
(@ID, 'esMX', 'Ah, el paquete de Zurdibrujo de Desolace. Excelente. Aprecio mucho tu trabajo, $c y tu eficiencia. Me alegro de tenerte a bordo, al menos para este trabajito.$B$BTengo tu pago aquí mismo. Que se sepa que Recuperadores S.A. siempre paga bien por una dura semana de trabajo.', 0);
-- 1454 El naufragio de Karnitol
-- https://es.wowhead.com/quest=1454
SET @ID := 1454;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Examinas el cofre y ves que no parece haber sido dañado por el agua.$B$BPero es evidente que la tapa ha sido forzada y, por las marcas de quemaduras de los bordes, ves que cualquier trampa mágica que se pusiera en su momento para proteger su contenido, fue anulada hace tiempo.', 0),
(@ID, 'esMX', 'Examinas el cofre y ves que no parece haber sido dañado por el agua.$B$BPero es evidente que la tapa ha sido forzada y, por las marcas de quemaduras de los bordes, ves que cualquier trampa mágica que se pusiera en su momento para proteger su contenido, fue anulada hace tiempo.', 0);
-- 7041 La corrupción de Lenguavil
-- https://es.classic.wowhead.com/quest=7041
SET @ID := 7041;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'SI consigues curar a la planta, volverá a crecer. Tenemos que hacer todo lo que podamos, $n...', 0),
(@ID, 'esMX', 'SI consigues curar a la planta, volverá a crecer. Tenemos que hacer todo lo que podamos, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n; seguiré investigando con los restos de líquido.$B$BAunque queda mucho por hacer, has contribuido a limpiar parte de la corrupción de Lenguavil en Maraudon. Toma esto como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Gracias, $n; seguiré investigando con los restos de líquido.$B$BAunque queda mucho por hacer, has contribuido a limpiar parte de la corrupción de Lenguavil en Maraudon. Toma esto como muestra de mi gratitud.', 0);
-- 261 El sendero Escarlata
-- https://es.classic.wowhead.com/quest=261
SET @ID := 261;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Plaga crece en poder con el paso de cada día. Si realmente deseas detener sus avances, muéstremelo.', 0),
(@ID, 'esMX', 'La Plaga crece en poder con el paso de cada día. Si realmente deseas detener sus avances, muéstremelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado tu resolución y la Cruzada Escarlata elogia tu honor.$B$BSi no te arredras ante las matanzas justas, quizás tu camino esté con nosotros...', 0),
(@ID, 'esMX', 'Has demostrado tu resolución y la Cruzada Escarlata elogia tu honor.$B$BSi no te arredras ante las matanzas justas, quizás tu camino esté con nosotros...', 0);
-- 1052 El sendero Escarlata
-- https://es.classic.wowhead.com/quest=1052
SET @ID := 1052;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién va? ¿Qué quieres de mí?', 0),
(@ID, 'esMX', '¿Quién va? ¿Qué quieres de mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El hermano Antón sigue divulgando la palabra de la Cruzada Escarlata? ¡Madre mía!', 0),
(@ID, 'esMX', '¿El hermano Antón sigue divulgando la palabra de la Cruzada Escarlata? ¡Madre mía!', 0);
-- 1440 Regresa junto a Vahlarriel
-- https://es.classic.wowhead.com/quest=1440
SET @ID := 1440;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Dalinda llegó sana y salva a Punta de Nijel y en mejores condiciones de lo que cabría haber esperado. El hecho de que llegara hasta aquí en pleno control de su poder y sus facultades es una buena señal. Espero que tú estés bien.$B$BMe duele pensar que Tyranis y Dalinda no han regresado juntos, pero sobre todo me pesa que ella tenga que soportar la vergüenza de las decisiones que tomó Tyranis. Es algo con lo que tendrá que enfrentarse cuando regrese a Darnassus.', 0),
(@ID, 'esMX', 'Gracias, $n. Dalinda llegó sana y salva a Punta de Nijel y en mejores condiciones de lo que cabría haber esperado. El hecho de que llegara hasta aquí en pleno control de su poder y sus facultades es una buena señal. Espero que tú estés bien.$B$BMe duele pensar que Tyranis y Dalinda no han regresado juntos, pero sobre todo me pesa que ella tenga que soportar la vergüenza de las decisiones que tomó Tyranis. Es algo con lo que tendrá que enfrentarse cuando regrese a Darnassus.', 0);
-- 5561 El rodeo kodo
-- https://es.wowhead.com/quest=5561
SET @ID := 5561;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caravana llegará dentro de nada. ¿Tienes los kodos domados que necesito?', 0),
(@ID, 'esMX', 'La caravana llegará dentro de nada. ¿Tienes los kodos domados que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Smeed Mezclatornillos empieza a contar.>$B$BTres, excelente. Pedí 3 kodos domados y 3 kodos domados tengo. Voy a ser rico, ¡muy, muy rico! ¡Qué ganas de ver la cara que se le quedará a Bibbly cuando se entere de mi éxito! ¡Se pondrá verde!', 0),
(@ID, 'esMX', '<Smeed Mezclatornillos empieza a contar.>$B$BTres, excelente. Pedí 3 kodos domados y 3 kodos domados tengo. Voy a ser rico, ¡muy, muy rico! ¡Qué ganas de ver la cara que se le quedará a Bibbly cuando se entere de mi éxito! ¡Se pondrá verde!', 0);
-- 1375 Khan Shaka
-- https://es.classic.wowhead.com/quest=1375
SET @ID := 1375;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz tareas para los Magram, y te ayudaré.', 0),
(@ID, 'esMX', 'Haz tareas para los Magram, y te ayudaré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Khan Shaka está muerto! ¡Colocaré su cabeza en una pica y la guardaré conmigo para que Shaka pueda ver la fuerza del Magram!', 0),
(@ID, 'esMX', '¡Khan Shaka está muerto! ¡Colocaré su cabeza en una pica y la guardaré conmigo para que Shaka pueda ver la fuerza del Magram!', 0);
-- 1381 Khan Hratha
-- https://es.classic.wowhead.com/quest=1381
SET @ID := 1381;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz lo que te pido. ¡Demuéstrame que eres un aliado de los Magram!', 0),
(@ID, 'esMX', 'Haz lo que te pido. ¡Demuéstrame que eres un aliado de los Magram!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Khan Hratha está muerto! ¡Ahora los Magram son los centauros más fuertes ¡Aplastaremos a los demás y dominaremos Desolace!$B$BTe recordaremos, $n, y te libraremos de nuestros cascos cuando todos los demás sean pisoteados.', 0),
(@ID, 'esMX', '¡Khan Hratha está muerto! ¡Ahora los Magram son los centauros más fuertes ¡Aplastaremos a los demás y dominaremos Desolace!$B$BTe recordaremos, $n, y te libraremos de nuestros cascos cuando todos los demás sean pisoteados.', 0);

-- 1455 El naufragio de Karnitol
-- https://es.wowhead.com/quest=1455
SET @ID := 1455;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de nuevo a Punta de Nijel, $n. Dime, ¿qué has encontrado?$B$B¡¿Qué?! ¿Nada? No van a darnos nada por un cofre vacío...$B$BHáblame de esas marcas que viste.', 0),
(@ID, 'esMX', 'Bienvenido de nuevo a Punta de Nijel, $n. Dime, ¿qué has encontrado?$B$B¡¿Qué?! ¿Nada? No van a darnos nada por un cofre vacío...$B$BHáblame de esas marcas que viste.', 0);
-- 6161 La búsqueda del tesoro de Masatormento
-- https://es.classic.wowhead.com/quest=6161
SET @ID := 6161;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cofre está bien cerrado.', 0),
(@ID, 'esMX', 'Este cofre está bien cerrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El cofre se abre y ves que contiene el tesoro de Masatormento!', 0),
(@ID, 'esMX', '¡El cofre se abre y ves que contiene el tesoro de Masatormento!', 0);
-- 1456 El naufragio de Karnitol
-- https://es.wowhead.com/quest=1456
SET @ID := 1456;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quisiera ofender a Nijel, aunque no sé ni quién es, pero este campamento no es precisamente el sitio más cómodo para pasar la noche, ya me entiendes, $n.', 0),
(@ID, 'esMX', 'No quisiera ofender a Nijel, aunque no sé ni quién es, pero este campamento no es precisamente el sitio más cómodo para pasar la noche, ya me entiendes, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Es genial, $n! ¡Has encontrado las pertenencias de Karnitol!$B$BEsos malditos nagas... siempre andan dando problemas. Creo que preferiría pasar el resto de mi vida luchando con la Horda antes que combatir con esa calaña.$B$BHas hecho un gran servicio a los Recuperadores. Por favor, ¡acepta esto junto con nuestro agradecimiento!', 0),
(@ID, 'esMX', '¡Es genial, $n! ¡Has encontrado las pertenencias de Karnitol!$B$BEsos malditos nagas... siempre andan dando problemas. Creo que preferiría pasar el resto de mi vida luchando con la Horda antes que combatir con esa calaña.$B$BHas hecho un gran servicio a los Recuperadores. Por favor, ¡acepta esto junto con nuestro agradecimiento!', 0);
-- 5741 El Cetro de Luz
-- https://es.classic.wowhead.com/quest=5741
SET @ID := 5741;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el Cetro de Luz?', 0),
(@ID, 'esMX', '¿Tienes el Cetro de Luz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El elusivo Cetro de la Luz! Al hacerte con él has eliminado una gran amenaza para el mundo. Bien hecho, $c, bien hecho.', 0),
(@ID, 'esMX', '¡El elusivo Cetro de la Luz! Al hacerte con él has eliminado una gran amenaza para el mundo. Bien hecho, $c, bien hecho.', 0);
-- 6027 El Libro de los Ancestros
-- https://es.classic.wowhead.com/quest=6027
SET @ID := 6027;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n! Me alegro de volver a verte. ¿Tienes el Libro de los Ancestros?', 0),
(@ID, 'esMX', '¡Ah, $n! Me alegro de volver a verte. ¿Tienes el Libro de los Ancestros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El Libro de los Ancestros! ¡El que tanto tiempo llevaba extraviado! Me aseguraré de que este libro llegue al Alto Consejo. Hoy has hecho algo magnífico. Deberíamos agradecértelo, y te lo agradecemos ¡como a $gun:una; $ghéroe:heroína;!', 0),
(@ID, 'esMX', '¡El Libro de los Ancestros! ¡El que tanto tiempo llevaba extraviado! Me aseguraré de que este libro llegue al Alto Consejo. Hoy has hecho algo magnífico. Deberíamos agradecértelo, y te lo agradecemos ¡como a $gun:una; $ghéroe:heroína;!', 0);
-- 6132 ¡Sácame de aquí!
-- https://es.wowhead.com/quest=6132
SET @ID := 6132;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a mi hermana Melizza? Ella siempre está en movimiento, lo que la mete en problemas todo el tiempo.', 0),
(@ID, 'esMX', '¿Has visto a mi hermana Melizza? Ella siempre está en movimiento, lo que la mete en problemas todo el tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi hermana Melizza dijo que vendrías. Gracias por sacarla del apuro... ¡aunque seguro que a estas horas ya se ha metido en otro lío!', 0),
(@ID, 'esMX', 'Mi hermana Melizza dijo que vendrías. Gracias por sacarla del apuro... ¡aunque seguro que a estas horas ya se ha metido en otro lío!', 0);
-- 5501 Recolección de kodos
-- https://es.wowhead.com/quest=5501
SET @ID := 5501;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los huesos? La caravana llegará de un momento a otro. Solo necesito 10 huesos de kodo más para llegar a la cumbre. ¡A la cumbre de mi carrera, sí señora!', 0),
(@ID, 'esMX', '¿Tienes los huesos? La caravana llegará de un momento a otro. Solo necesito 10 huesos de kodo más para llegar a la cumbre. ¡A la cumbre de mi carrera, sí señora!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué visión tan estupenda! ¡Mis huesos!$B$BEstoy deseando que los de casa vean mi cara en la portada de Grandes fortunas goblin. Seré el goblin más rico del mundo. ¡Y mi profesor de gimnasia decía que nunca llegaría a nada!', 0),
(@ID, 'esMX', '¡Ah, qué visión tan estupenda! ¡Mis huesos!$B$BEstoy deseando que los de casa vean mi cara en la portada de Grandes fortunas goblin. Seré el goblin más rico del mundo. ¡Y mi profesor de gimnasia decía que nunca llegaría a nada!', 0);
-- 6134 La caza de ectoplasmas
-- https://es.wowhead.com/quest=6134
SET @ID := 6134;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está mi ectoplasma, $n?', 0),
(@ID, 'esMX', '¿Dónde está mi ectoplasma, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahí está! Y parece que también llevas un poco encima. Es pegajosillo, ¿eh?$B$BBueno, gracias por todo, $n. Esta cosa me hará ganar una fortuna... ¡si consigo convencer a los centauros de que la vale!', 0),
(@ID, 'esMX', '¡Ahí está! Y parece que también llevas un poco encima. Es pegajosillo, ¿eh?$B$BBueno, gracias por todo, $n. Esta cosa me hará ganar una fortuna... ¡si consigo convencer a los centauros de que la vale!', 0);
-- 7028 Los males de Maraudon
-- https://es.classic.wowhead.com/quest=7028
SET @ID := 7028;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No preguntes!$B$BYa sabes lo que quiero.', 0),
(@ID, 'esMX', '¡No preguntes!$B$BYa sabes lo que quiero.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja! Sabía que volverías.$B$B<Willow habla entre dientes.>$B$BQué fácil de convencer.$B$BLo que sea por una recompensa. Je, je, je...', 0),
(@ID, 'esMX', '¡Ja, ja! Sabía que volverías.$B$B<Willow habla entre dientes.>$B$BQué fácil de convencer.$B$BLo que sea por una recompensa. Je, je, je...', 0);
-- 1457 El naufragio de Karnitol
-- https://es.classic.wowhead.com/quest=1457
SET @ID := 1457;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El negocio va de maravilla, $n y no tengo mucho tiempo para preguntas. Si tienes asuntos con los Recuperadores, te escucharé. Si no es así, tendré que pedirte que hables con uno de mis subalternos. Ellos se ocupan de las cosas por aquí.', 0),
(@ID, 'esMX', 'El negocio va de maravilla, $n y no tengo mucho tiempo para preguntas. Si tienes asuntos con los Recuperadores, te escucharé. Si no es así, tendré que pedirte que hables con uno de mis subalternos. Ellos se ocupan de las cosas por aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que el cofre estaba destruido pero los objetos están todos aquí, ¿eh? Bueno, dejaré que sea él quien lo juzgue. Lo bueno que tiene este negocio es que, si los clientes no quedan satisfechos, ¡les puedo mandar a paseo! Confían en que nosotros encontraremos sus cosas... no han pedido que estén estupendas e intactas cuando las recuperen.$B$BBuen trabajo, $n. Ahora vamos a ocuparnos de que recibas tu pago.', 0),
(@ID, 'esMX', 'Así que el cofre estaba destruido pero los objetos están todos aquí, ¿eh? Bueno, dejaré que sea él quien lo juzgue. Lo bueno que tiene este negocio es que, si los clientes no quedan satisfechos, ¡les puedo mandar a paseo! Confían en que nosotros encontraremos sus cosas... no han pedido que estén estupendas e intactas cuando las recuperen.$B$BBuen trabajo, $n. Ahora vamos a ocuparnos de que recibas tu pago.', 0);
-- 3448 Encargarse de la investigación
-- https://es.classic.wowhead.com/quest=3448
SET @ID := 3448;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que vienes de parte de Karnik? Me lo imaginaba; he descubierto cosas asombrosas sobre Azshara. Los elfos de la noche viven muchos años, pero la gente tiende a olvidar los acontecimientos más desagradables de su historia. No lo digo como crítica, solo constato un hecho.$B$BHace mucho tiempo, construyeron ciudades imbuidas de magia y otras artes hoy perdidas. Esos temas me interesan, por eso empecé a investigar y descubrí cosas maravillosas.', 0),
(@ID, 'esMX', '¿Que vienes de parte de Karnik? Me lo imaginaba; he descubierto cosas asombrosas sobre Azshara. Los elfos de la noche viven muchos años, pero la gente tiende a olvidar los acontecimientos más desagradables de su historia. No lo digo como crítica, solo constato un hecho.$B$BHace mucho tiempo, construyeron ciudades imbuidas de magia y otras artes hoy perdidas. Esos temas me interesan, por eso empecé a investigar y descubrí cosas maravillosas.', 0);
-- 2769 Los hermanos Pernolatón
-- https://es.classic.wowhead.com/quest=2769
SET @ID := 2769;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿quieres ayudarme? ¡Excelente!$B$B¡Hay una parte que quiero para un experimento en el que estoy trabajando, y necesito $gun:una; $c valiente como tú para ayudarme a conseguirlo!', 0),
(@ID, 'esMX', 'Ah, ¿quieres ayudarme? ¡Excelente!$B$B¡Hay una parte que quiero para un experimento en el que estoy trabajando, y necesito $gun:una; $c valiente como tú para ayudarme a conseguirlo!', 0);
-- 3449 Runas Arcanas
-- https://es.classic.wowhead.com/quest=3449
SET @ID := 3449;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, bueno, bueno, me alegro de que hayas llegado hasta aquí, $n. ¿Recibiste los calcos de Tymor?$B$BPor peligroso que sea eselugar, no ha habido demasiada acción a lo largo de la costa. Eso podría deberse a que los nagas nadan bajo el agua, pero ese no es mi problema ... Yo patrullo los cielos.', 0),
(@ID, 'esMX', 'Bueno, bueno, bueno, me alegro de que hayas llegado hasta aquí, $n. ¿Recibiste los calcos de Tymor?$B$BPor peligroso que sea eselugar, no ha habido demasiada acción a lo largo de la costa. Eso podría deberse a que los nagas nadan bajo el agua, pero ese no es mi problema ... Yo patrullo los cielos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno verte $gsano:sana; y $gsalvo:salva;, $n. Espero que las cosas no hayan sido demasiado difíciles para ti.$B$BSe los llevaré a Tymor de inmediato. Estará encantado de echar un vistazo a estas cosas.$B$BAdelante, tira la pistola de bengalas... probablemente ya no te sirva de nada, y ya tengo una nueva.', 0),
(@ID, 'esMX', 'Es bueno verte $gsano:sana; y $gsalvo:salva;, $n. Espero que las cosas no hayan sido demasiado difíciles para ti.$B$BSe los llevaré a Tymor de inmediato. Estará encantado de echar un vistazo a estas cosas.$B$BAdelante, tira la pistola de bengalas... probablemente ya no te sirva de nada, y ya tengo una nueva.', 0);
-- 3450 Un simple envío
-- https://es.classic.wowhead.com/quest=3450
SET @ID := 3450;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué querías, $n? Tengo mucho que hacer, solo he venido a buscar unas crines de wendigo.$B$BAcabo de mandar a alguien al Almacén de Brasacerada, así que tienes un minuto para contarme lo que sea.', 0),
(@ID, 'esMX', '¿Qué querías, $n? Tengo mucho que hacer, solo he venido a buscar unas crines de wendigo.$B$BAcabo de mandar a alguien al Almacén de Brasacerada, así que tienes un minuto para contarme lo que sea.', 0);
-- 3451 Una señal para el envío
-- https://es.classic.wowhead.com/quest=3451
SET @ID := 3451;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma mi pistola de bengalas. Sé paciente después de disparar; solo llevan 2 cartuchos y yo puedo tardar hasta 1 minuto, depende de dónde esté. Tú mira al mar después de lanzar las bengalas.', 0),
(@ID, 'esMX', 'Toma mi pistola de bengalas. Sé paciente después de disparar; solo llevan 2 cartuchos y yo puedo tardar hasta 1 minuto, depende de dónde esté. Tú mira al mar después de lanzar las bengalas.', 0);
-- 3483 Una señal para el envío
-- https://es.classic.wowhead.com/quest=3483
SET @ID := 3483;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Otra pistola de bengalas? Por supuesto.$B$BY recuerda que debes ir a la punta sur de Azshara. Es una islita reconvertida en pista de aterrizaje; seguro que la ves.', 0),
(@ID, 'esMX', '¿Otra pistola de bengalas? Por supuesto.$B$BY recuerda que debes ir a la punta sur de Azshara. Es una islita reconvertida en pista de aterrizaje; seguro que la ves.', 0);
-- 1179 Los hermanos Pernolatón
-- https://es.classic.wowhead.com/quest=1179
SET @ID := 1179;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mira por dónde pisas! ¡Ten mucho, mucho, mucho cuidado! Todos estos chismes que ves por aquí son muy delicados y si queremos ganar, ¡deben funcionar a la perfección!', 0),
(@ID, 'esMX', '¡Mira por dónde pisas! ¡Ten mucho, mucho, mucho cuidado! Todos estos chismes que ves por aquí son muy delicados y si queremos ganar, ¡deben funcionar a la perfección!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, Barbalarga nos ha enviado un cargamento de cascos! ¡Hurra!$B$BQuizás ahora podamos convencer a algún piloto para que conduzca nuestro coche...', 0),
(@ID, 'esMX', '¡Ah, Barbalarga nos ha enviado un cargamento de cascos! ¡Hurra!$B$BQuizás ahora podamos convencer a algún piloto para que conduzca nuestro coche...', 0);
-- 1271 ¡Una fiesta en tu honor!
-- https://es.wowhead.com/quest=1271
SET @ID := 1271;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi sobrino me dijo que le habías ayudado en su investigación en Revolcafango y que sacaste a su socio de un buen apuro. ¡Pues los Stern estamos muy unidos y atendemos a nuestros amigos!$B$BAsí que lávate las manos, $n, ¡porque estamos a punto de montar una fiesta en tu honor!', 0),
(@ID, 'esMX', 'Mi sobrino me dijo que le habías ayudado en su investigación en Revolcafango y que sacaste a su socio de un buen apuro. ¡Pues los Stern estamos muy unidos y atendemos a nuestros amigos!$B$BAsí que lávate las manos, $n, ¡porque estamos a punto de montar una fiesta en tu honor!', 0);
-- 565 Capa de piel de yeti de Bartolo
-- https://es.classic.wowhead.com/quest=565
SET @ID := 565;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has venido de nuevo al gran Bartolo. ¿Ya tienes lo necesario para la capa de piel de yeti? ¿O has venido por la deliciosa compañía del gran Bartolo?', 0),
(@ID, 'esMX', 'Has venido de nuevo al gran Bartolo. ¿Ya tienes lo necesario para la capa de piel de yeti? ¿O has venido por la deliciosa compañía del gran Bartolo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora el gran Bartolo pondrá en práctica su magia! No necesito bastón de mago ni vara de hechicero. ¡Mi magia solo necesita hilo y aguja!', 0),
(@ID, 'esMX', '¡Ahora el gran Bartolo pondrá en práctica su magia! No necesito bastón de mago ni vara de hechicero. ¡Mi magia solo necesita hilo y aguja!', 0);
-- 564 Una amenaza costosa
-- https://es.classic.wowhead.com/quest=564
SET @ID := 564;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los leones de montaña están matando a nuestros caballos a diestro y siniestro y aquí estás queriendo parlotear sobre el clima y que se yo.$B$BDebería buscar un verdadero héroe. Más matar y menos hablar.', 0),
(@ID, 'esMX', 'Los leones de montaña están matando a nuestros caballos a diestro y siniestro y aquí estás queriendo parlotear sobre el clima y que se yo.$B$BDebería buscar un verdadero héroe. Más matar y menos hablar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me alegro de oír eso! Ya sabía yo que tú me resolverías el problema... ¡Eres un orgullo para tu familia, $n!', 0),
(@ID, 'esMX', '¡Me alegro de oír eso! Ya sabía yo que tú me resolverías el problema... ¡Eres un orgullo para tu familia, $n!', 0);
-- 659 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=659
SET @ID := 659;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Procura estar tan quieto como puedas, viajero.$B$BA los orcos no les sienta muy bien que los espíen y en esta Granja hay más de lo que se ve a simple vista.', 0),
(@ID, 'esMX', 'Procura estar tan quieto como puedas, viajero.$B$BA los orcos no les sienta muy bien que los espíen y en esta Granja hay más de lo que se ve a simple vista.', 0);
-- 500 La recompensa Aplastacresta
-- https://es.classic.wowhead.com/quest=500
SET @ID := 500;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás cazando ogros, $n? ¿Me traes los huesos sucios que te pedí?', 0),
(@ID, 'esMX', '¿Estás cazando ogros, $n? ¿Me traes los huesos sucios que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué buen montón de huesos sucios me traes, $n.$B$BEspero que ahora los ogros nos dejen tranquilos; al menos, de momento.', 0),
(@ID, 'esMX', 'Qué buen montón de huesos sucios me traes, $n.$B$BEspero que ahora los ogros nos dejen tranquilos; al menos, de momento.', 0);

-- 505 Hermandad de asesinos
-- https://es.classic.wowhead.com/quest=505
SET @ID := 505;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha matado a esos matones de la Hermandad?', 0),
(@ID, 'esMX', '¿Ha matado a esos matones de la Hermandad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Espero que algunos de los asaltantes de caminos y ladrones que has matado fueran responsables de la muerte del magistrado. Y aunque no fuera así, la Hermandad es una lacra que debe ser erradicada.$B$BEn Costasur se celebran esas muertes.', 0),
(@ID, 'esMX', 'Gracias, $n. Espero que algunos de los asaltantes de caminos y ladrones que has matado fueran responsables de la muerte del magistrado. Y aunque no fuera así, la Hermandad es una lacra que debe ser erradicada.$B$BEn Costasur se celebran esas muertes.', 0);
-- 9435 Los cristales desaparecidos
-- https://es.wowhead.com/quest=9435
SET @ID := 9435;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste recuperar los cristales de los Renegados?', 0),
(@ID, 'esMX', '¿Pudiste recuperar los cristales de los Renegados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a la Luz! Por el tono de la carta del capataz, sonaba como si esa caja de cristales contuviera las únicas muestras conocidas de la mina. Si los hubiéramos perdido, $n, es posible que nunca hubiéramos visto otro igual.$B$BNo puedo agradecerte lo suficiente tu ayuda.', 0),
(@ID, 'esMX', '¡Gracias a la Luz! Por el tono de la carta del capataz, sonaba como si esa caja de cristales contuviera las únicas muestras conocidas de la mina. Si los hubiéramos perdido, $n, es posible que nunca hubiéramos visto otro igual.$B$BNo puedo agradecerte lo suficiente tu ayuda.', 0);
-- 536 Al lo largo de la costa
-- https://es.wowhead.com/quest=536
SET @ID := 536;
UPDATE `quest_template_locale` SET `Title` = 'A lo largo de la costa', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otra cerveza, por favor, ¡la última parecía haber desaparecido!$B$BPor la Luz, ¿cuánto tiempo más voy a estar atrapado aquí?$B$BOh, eres tú, $N. ¿Ya mataste a esos múrlocs?', 0),
(@ID, 'esMX', 'Otra cerveza, por favor, ¡la última parecía haber desaparecido!$B$BPor la Luz, ¿cuánto tiempo más voy a estar atrapado aquí?$B$BOh, eres tú, $N. ¿Ya mataste a esos múrlocs?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así Rutagrana se convencerá de que he cumplido sus órdenes... Es un decir. En fin, el caso es que ya no hay murlocs gracias a ti.', 0),
(@ID, 'esMX', 'Así Rutagrana se convencerá de que he cumplido sus órdenes... Es un decir. En fin, el caso es que ya no hay murlocs gracias a ti.', 0);
-- 555 Sopa de tortuga reconfortante
-- https://es.classic.wowhead.com/quest=555
SET @ID := 555;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste los ingredientes? Esta tierra ya no es tan tranquila como antes. Ay, qué tiempos...', 0),
(@ID, 'esMX', '¿Encontraste los ingredientes? Esta tierra ya no es tan tranquila como antes. Ay, qué tiempos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo el mundo estará encantado de que vuelva a haber sopa de tortuga en el menú.', 0),
(@ID, 'esMX', 'Todo el mundo estará encantado de que vuelva a haber sopa de tortuga en el menú.', 0);
-- 1053 En el nombre de la Luz
-- https://es.classic.wowhead.com/quest=1053
SET @ID := 1053;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción en el Monasterio no terminará hasta que los oficiales de más alto rango sean eliminados.$B$BEn nombre de la Luz, mata a la alta inquisidora Melenablanca, al Comandante Escarlata Mograine, a Herod, el Campeón Escarlata y al maestro de canes Loksey. Una vez muertos, quizás se pueda reavivar la verdadera causa. Hasta entonces, cualquiera que se cruce en el camino de la Cruzada corre peligro.$B$B¡Aventúrate desde Costasur y hazlo así!', 0),
(@ID, 'esMX', 'La corrupción en el Monasterio no terminará hasta que los oficiales de más alto rango sean eliminados.$B$BEn nombre de la Luz, mata a la alta inquisidora Melenablanca, al Comandante Escarlata Mograine, a Herod, el Campeón Escarlata y al maestro de canes Loksey. Una vez muertos, quizás se pueda reavivar la verdadera causa. Hasta entonces, cualquiera que se cruce en el camino de la Cruzada corre peligro.$B$B¡Aventúrate desde Costasur y hazlo así!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras que los discípulos de la Luz nunca se deleitan con la pérdida de la vida, debemos aceptar que, en algunas ocasiones, esos sacrificios deben ocurrir por el bien del reino y del planeta.$B$BGracias a tus acciones en el Monasterio se han salvado muchas vidas inocentes, $n. Aplaudo tu tenacidad.', 0),
(@ID, 'esMX', 'Mientras que los discípulos de la Luz nunca se deleitan con la pérdida de la vida, debemos aceptar que, en algunas ocasiones, esos sacrificios deben ocurrir por el bien del reino y del planeta.$B$BGracias a tus acciones en el Monasterio se han salvado muchas vidas inocentes, $n. Aplaudo tu tenacidad.', 0);
-- 559 La prueba de Farren
-- https://es.classic.wowhead.com/quest=559
SET @ID := 559;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes las cabezas, $n?', 0),
(@ID, 'esMX', '¿Me traes las cabezas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo estás poniendo todo perdido!$B$BYo no puedo tocar esas cosas; el pescado vaya y pase, pero estos bichos... Puaj. Llevo semanas sin comer pescado, y en Costasur eso es mucho decir', 0),
(@ID, 'esMX', '¡Lo estás poniendo todo perdido!$B$BYo no puedo tocar esas cosas; el pescado vaya y pase, pero estos bichos... Puaj. Llevo semanas sin comer pescado, y en Costasur eso es mucho decir', 0);
-- 560 La prueba de Farren
-- https://es.classic.wowhead.com/quest=560
SET @ID := 560;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. ¿Vienes a ayudar en la defensa de Costasur?', 0),
(@ID, 'esMX', 'Saludos. ¿Vienes a ayudar en la defensa de Costasur?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía Farren, ¿eh?$B$BSi tuviste algo que ver con las cabezas, te lo agradezco; necesitamos gente dispuesta a trabajar.', 0),
(@ID, 'esMX', 'Así que te envía Farren, ¿eh?$B$BSi tuviste algo que ver con las cabezas, te lo agradezco; necesitamos gente dispuesta a trabajar.', 0);
-- 561 La prueba de Farren
-- https://es.classic.wowhead.com/quest=561
SET @ID := 561;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los naga, ¿eh? Pues va listo Rutagrana si cree que va a ganarse una medalla a mi costa. Ahora te explico.', 0),
(@ID, 'esMX', 'Los naga, ¿eh? Pues va listo Rutagrana si cree que va a ganarse una medalla a mi costa. Ahora te explico.', 0);
-- 562 Cambio de destino
-- https://es.classic.wowhead.com/quest=562
SET @ID := 562;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo una carta lista para el mayor Samuelson de Ventormenta; solo necesito el informe.', 0),
(@ID, 'esMX', 'Tengo una carta lista para el mayor Samuelson de Ventormenta; solo necesito el informe.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que no hay nagas en Costasur, estoy más cerca de que me devuelvan a Ventormenta y salir de aquí de una vez.', 0),
(@ID, 'esMX', 'Ahora que no hay nagas en Costasur, estoy más cerca de que me devuelvan a Ventormenta y salir de aquí de una vez.', 0);
-- 563 Nueva asignación
-- https://es.classic.wowhead.com/quest=563
SET @ID := 563;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. ¿Necesitas ayuda de la guardia de Ventormenta?', 0),
(@ID, 'esMX', 'Saludos. ¿Necesitas ayuda de la guardia de Ventormenta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Ah, veo que se han tomado medidas con los nagas de Costasur. Gracias, tendré en cuenta este informe.', 0),
(@ID, 'esMX', '¿Qué es esto? Ah, veo que se han tomado medidas con los nagas de Costasur. Gracias, tendré en cuenta este informe.', 0);
-- 511 Una carta cifrada
-- https://es.classic.wowhead.com/quest=511
SET @ID := 511;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías algo?', 0),
(@ID, 'esMX', '¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Déjame ver...$B$BMmm... nunca había visto nada parecido pese a mi considerable experiencia.', 0),
(@ID, 'esMX', '¿Qué es esto? Déjame ver...$B$BMmm... nunca había visto nada parecido pese a mi considerable experiencia.', 0);
-- 510 Documentos de planificación
-- https://es.classic.wowhead.com/quest=510
SET @ID := 510;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te preocupa, $n? ¿Tienes algo que decir?', 0),
(@ID, 'esMX', '¿Qué te preocupa, $n? ¿Tienes algo que decir?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maleb lee los documentos.>$B$BEsto es muy inquietante, $n. Por lo que dice aquí y por las acciones de la Hermandad, esos rufianes han declarado la guerra a Costasur.', 0),
(@ID, 'esMX', '<Maleb lee los documentos.>$B$BEsto es muy inquietante, $n. Por lo que dice aquí y por las acciones de la Hermandad, esos rufianes han declarado la guerra a Costasur.', 0);
-- 512 Nobles muertes
-- https://es.classic.wowhead.com/quest=512
SET @ID := 512;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te estás ocupando de la Hermandad? ¿Tienes los anillos?', 0),
(@ID, 'esMX', '¿Te estás ocupando de la Hermandad? ¿Tienes los anillos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este golpe reducirá la libertad de acción de la Hermandad y los reducirá a la banda de maleantes que son.$B$BSirves muy bien a la Alianza, $n.', 0),
(@ID, 'esMX', 'Este golpe reducirá la libertad de acción de la Hermandad y los reducirá a la banda de maleantes que son.$B$BSirves muy bien a la Alianza, $n.', 0);
-- 514 Una carta para Pico Tormenta
-- https://es.classic.wowhead.com/quest=514
SET @ID := 514;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía Dibbs de Costasur, ¿eh? ¿Cómo le va a esa ratilla de biblioteca?', 0),
(@ID, 'esMX', 'Así que te envía Dibbs de Costasur, ¿eh? ¿Cómo le va a esa ratilla de biblioteca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, soy un especialista en códigos cifrados. A ver...', 0),
(@ID, 'esMX', 'Ah, sí, soy un especialista en códigos cifrados. A ver...', 0);
-- 525 Más misterios
-- https://es.classic.wowhead.com/quest=525
SET @ID := 525;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has estado de viaje por las montañas otra vez? ¿Qué noticias traes?', 0),
(@ID, 'esMX', '$n, ¿has estado de viaje por las montañas otra vez? ¿Qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maleb lee la carta.>$B$B¿Esto estaba en un campamento de la Hermandad? Esto no lo escribió un ladrón ni tampoco un noble de Alterac.$B$BParece que la Hermandad está aliada con otro poder; me estremezco al pensar cuál puede ser.', 0),
(@ID, 'esMX', '<Maleb lee la carta.>$B$B¿Esto estaba en un campamento de la Hermandad? Esto no lo escribió un ladrón ni tampoco un noble de Alterac.$B$BParece que la Hermandad está aliada con otro poder; me estremezco al pensar cuál puede ser.', 0);
-- 537 Consejo oscuro
-- https://es.wowhead.com/quest=537
-- https://wow-es.gamepedia.com/Misión:Consejo oscuro
SET @ID := 537;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Localizaste a los enviados de Despertar de Argus?', 0),
(@ID, 'esMX', '¿Localizaste a los enviados de Despertar de Argus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n.$B$BPero debes saber que Nagaz no era más que un siervo; el Despertar de Argus tiene profundas raíces en Azeroth.$B$BY puede que en todo el mundo.', 0),
(@ID, 'esMX', 'Buen trabajo, $n.$B$BPero debes saber que Nagaz no era más que un siervo; el Despertar de Argus tiene profundas raíces en Azeroth.$B$BY puede que en todo el mundo.', 0);
-- 504 Belicistas Aplastacresta
-- https://es.classic.wowhead.com/quest=504
SET @ID := 504;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes más belicistas que matar, $n. Deberías estar en las montañas en tu tarea, no aquí abajo con tu arma guardada.', 0),
(@ID, 'esMX', 'Tienes más belicistas que matar, $n. Deberías estar en las montañas en tu tarea, no aquí abajo con tu arma guardada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien; aquí tienes la recompensa.$B$BDime, ¿cómo has visto Alterac? Supongo que la cosa estará mal; los ogros no son famosos por ser limpios.$B$BPor suerte, gracias a tus esfuerzos se mantendrán alejados de Costasur.', 0),
(@ID, 'esMX', 'Muy bien; aquí tienes la recompensa.$B$BDime, ¿cómo has visto Alterac? Supongo que la cosa estará mal; los ogros no son famosos por ser limpios.$B$BPor suerte, gracias a tus esfuerzos se mantendrán alejados de Costasur.', 0);
-- 13502 ¿Qué llevas en la cestita?
-- https://es.wowhead.com/quest=13502
SET @ID := 13502;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los 10 chocolates del Jardín Noble?', 0),
(@ID, 'esMX', '¿Tienes los 10 chocolates del Jardín Noble?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! ¡Ten... quédate con la cesta!$B$BRecuerda, ¡puedes venir cuando quieras a canjear chocolates del Jardín Noble por otros objetos!', 0),
(@ID, 'esMX', '¡Buen trabajo! ¡Ten... quédate con la cesta!$B$BRecuerda, ¡puedes venir cuando quieras a canjear chocolates del Jardín Noble por otros objetos!', 0);
-- 8649 Tormenceño el Ancestro
-- https://es.wowhead.com/quest=8649
SET @ID := 8649;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 7905 La Feria de la Luna Negra
-- https://es.wowhead.com/quest=7905
SET @ID := 7905;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías algo? ¿Tienes un vale?', 0),
(@ID, 'esMX', '¿Querías algo? ¿Tienes un vale?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te doy la bienvenida a la Feria de la Luna Negra! ¡Este vale te da derecho a CINCO, has oído bien, CINCO boletos de tómbola y una copia gratuita de la mundialmente conocida guía de campo de la Luna Negra!$B$BCuando tengas suficientes boletos, ven a verme para cambiarlos por premios. ¡Esta práctica guía de campo te ayudará a localizar e identificar los objetos de valor de los coleccionistas que hay en la feria!', 0),
(@ID, 'esMX', '¡Te doy la bienvenida a la Feria de la Luna Negra! ¡Este vale te da derecho a CINCO, has oído bien, CINCO boletos de tómbola y una copia gratuita de la mundialmente conocida guía de campo de la Luna Negra!$B$BCuando tengas suficientes boletos, ven a verme para cambiarlos por premios. ¡Esta práctica guía de campo te ayudará a localizar e identificar los objetos de valor de los coleccionistas que hay en la feria!', 0);

-- 7907 La baraja de Bestias de la Luna Negra
-- https://es.classic.wowhead.com/quest=7907
SET @ID := 7907;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh querido.', 0),
(@ID, 'esMX', 'Oh querido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, esto explica mucho. Si alguna vez encuentra una forma de entrar en Ahn\'Qiraj, esté atento al viejo Brann. Me temo que será inútil sin su mono', 0),
(@ID, 'esMX', 'Bueno, esto explica mucho. Si alguna vez encuentra una forma de entrar en Ahn\'Qiraj, esté atento al viejo Brann. Me temo que será inútil sin su mono', 0);
-- 12133 Aplasta la calabaza
-- https://es.wowhead.com/quest=12133
SET @ID := 12133;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste esto en el interior de la calabaza iluminada del Jinete decapitado? Es un antiguo símbolo de la Luz. Debía de pertenecer al Jinete antes de que fuera maldecido y se convirtiese en el monstruo que es hoy. Gracias, $n. Este símbolo merece estar entre paladines. Me encargaré de que lo reciban.$B$B¡Ah, casi se me olvida! Tienes una admiradora secreta...$B$BUna de las niñas quería regalarte esto, pero le daba mucha vergüenza dártelo personalmente.', 0),
(@ID, 'esMX', '¿Encontraste esto en el interior de la calabaza iluminada del Jinete decapitado? Es un antiguo símbolo de la Luz. Debía de pertenecer al Jinete antes de que fuera maldecido y se convirtiese en el monstruo que es hoy. Gracias, $n. Este símbolo merece estar entre paladines. Me encargaré de que lo reciban.$B$B¡Ah, casi se me olvida! Tienes una admiradora secreta...$B$BUna de las niñas quería regalarte esto, pero le daba mucha vergüenza dártelo personalmente.', 0);
-- 1598 El libro robado
-- https://es.classic.wowhead.com/quest=1598
SET @ID := 1598;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Era demasiado llamativo para mí robar el libro yo mismo. Qué suerte que uno de esos tontos hizo el trabajo sucio por mí.', 0),
(@ID, 'esMX', 'Era demasiado llamativo para mí robar el libro yo mismo. Qué suerte que uno de esos tontos hizo el trabajo sucio por mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente ... Nunca pude acceder a este texto, estaba guardado en un ala protegida de la biblioteca y habría parecido sospechoso si me ven merodeando.$B$BBueno, hiciste un buen trabajo al conseguir esto, y estoy convencido de que probablemente puedas manejar a tu propio diablillo, así que no hay razón para que no te muestre cómo convocar a uno.', 0),
(@ID, 'esMX', 'Excelente ... Nunca pude acceder a este texto, estaba guardado en un ala protegida de la biblioteca y habría parecido sospechoso si me ven merodeando.$B$BBueno, hiciste un buen trabajo al conseguir esto, y estoy convencido de que probablemente puedas manejar a tu propio diablillo, así que no hay razón para que no te muestre cómo convocar a uno.', 0);
-- 7929 La baraja de Elementales de la Luna Negra
-- https://es.wowhead.com/quest=7929
-- https://wow-es.gamepedia.com/Misión:La baraja de Elementales de la Luna Negra
SET @ID := 7929;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veo que has logrado completar un mazo de elementales! ¡Felicidades!', 0),
(@ID, 'esMX', '¡Veo que has logrado completar un mazo de elementales! ¡Felicidades!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has armado un mazo de Elementales. Su gesto de devolvérnoslo creará un vínculo entre usted y la Luna Negra que no se olvidará pronto. Permíteme presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Así que has armado un mazo de Elementales. Su gesto de devolvérnoslo creará un vínculo entre usted y la Luna Negra que no se olvidará pronto. Permíteme presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0);
-- 13484 Colectores primaverales
-- https://es.wowhead.com/quest=13484
SET @ID := 13484;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! ¡Sí, creo que tengo la tarea perfecta para ti!', 0),
(@ID, 'esMX', '¡Sí! ¡Sí, creo que tengo la tarea perfecta para ti!', 0);
-- 13480 La gran búsqueda de huevos
-- https://es.wowhead.com/quest=13480
SET @ID := 13480;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los trozos?', 0),
(@ID, 'esMX', '¿Tienes los trozos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, fantástico, gracias! Puede que me haga falta más de una muestra para conseguir resultados verdaderamente concluyentes, pero lo has hecho muy bien por hoy.', 0),
(@ID, 'esMX', '¡Fantástico, fantástico, gracias! Puede que me haga falta más de una muestra para conseguir resultados verdaderamente concluyentes, pero lo has hecho muy bien por hoy.', 0);
-- 1685 La invocación de Gakin
-- https://es.wowhead.com/quest=1685
SET @ID := 1685;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que aparecieras. Aunque, quizás debería haber enviado a alguien más capaz que Remen para encontrarte.$B$BNo importa.$B$BHas pasado demasiado tiempo sin entrenar, y un brujo sin entrenamiento no mantiene la cabeza sobre los hombros por mucho tiempo.', 0),
(@ID, 'esMX', 'Ya era hora de que aparecieras. Aunque, quizás debería haber enviado a alguien más capaz que Remen para encontrarte.$B$BNo importa.$B$BHas pasado demasiado tiempo sin entrenar, y un brujo sin entrenamiento no mantiene la cabeza sobre los hombros por mucho tiempo.', 0);
-- 1688 Surena Caledon
-- https://es.classic.wowhead.com/quest=1688
SET @ID := 1688;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Incluso los más viejos y sabios pueden caer rendidos ante la gloria de la belleza y la juventud, $n. Un consejo que te vendrá bien recordar toda tu vida.', 0),
(@ID, 'esMX', 'Incluso los más viejos y sabios pueden caer rendidos ante la gloria de la belleza y la juventud, $n. Un consejo que te vendrá bien recordar toda tu vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Surena tenía mucho talento, pero no tanto como para conseguir dominar la magia de los brujos sin ayuda. Es una pena ver el desperdicio de talento pero, algunas veces, es necesario.$B$BEspero tener resultados diferentes contigo.', 0),
(@ID, 'esMX', 'Surena tenía mucho talento, pero no tanto como para conseguir dominar la magia de los brujos sin ayuda. Es una pena ver el desperdicio de talento pero, algunas veces, es necesario.$B$BEspero tener resultados diferentes contigo.', 0);
-- 1689 El vínculo
-- https://es.classic.wowhead.com/quest=1689
SET @ID := 1689;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo enseñarte a controlar a un abisario hasta que no hayas vencido a uno.', 0),
(@ID, 'esMX', 'No puedo enseñarte a controlar a un abisario hasta que no hayas vencido a uno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho mejor de lo que esperaba, $n, pero has estado a la altura de mis esperanzas. Ahora puedes aprender a dominar a tu abisario sometido, un aliado que será muy valioso en los desafíos que, sin lugar a duda, se te presentarán.$B$BNo tengo nada más que enseñarte en este momento, pero todavía no he acabado contigo, $n.', 0),
(@ID, 'esMX', 'Lo has hecho mejor de lo que esperaba, $n, pero has estado a la altura de mis esperanzas. Ahora puedes aprender a dominar a tu abisario sometido, un aliado que será muy valioso en los desafíos que, sin lugar a duda, se te presentarán.$B$BNo tengo nada más que enseñarte en este momento, pero todavía no he acabado contigo, $n.', 0);
-- 1638 Instrucción de guerrero
-- https://es.classic.wowhead.com/quest=1638
SET @ID := 1638;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, jo! Tómate un trago conmigo, $gmuchacho:muchacha;. A primera vista pareces muy $gduro:dura;, pero veamos si puedes arreglártelas con algunas jarras de las especialidades más potentes de El Cerdo Borracho$B$BO bien... ¿has venido para recibir instrucción?', 0),
(@ID, 'esMX', '¡Oh, jo! Tómate un trago conmigo, $gmuchacho:muchacha;. A primera vista pareces muy $gduro:dura;, pero veamos si puedes arreglártelas con algunas jarras de las especialidades más potentes de El Cerdo Borracho$B$BO bien... ¿has venido para recibir instrucción?', 0);
-- 1639 Bartleby, el borracho
-- https://es.classic.wowhead.com/quest=1639
SET @ID := 1639;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola $gmuchachito:muchachita;! ¿Qué hace $gun:una; repipi como tú en El Cerdo Borracho? Ten cuidado, se te podría romper una uña...', 0),
(@ID, 'esMX', '¡Hola $gmuchachito:muchachita;! ¿Qué hace $gun:una; repipi como tú en El Cerdo Borracho? Ten cuidado, se te podría romper una uña...', 0);
-- 1640 Vence a Bartleby
-- https://es.classic.wowhead.com/quest=1640
SET @ID := 1640;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sólo me quitarás la jarra de mis manos frías y muertas...', 0),
(@ID, 'esMX', 'Sólo me quitarás la jarra de mis manos frías y muertas...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres mucho más duro de lo que pareces!', 0),
(@ID, 'esMX', '¡Eres mucho más duro de lo que pareces!', 0);
-- 1665 La jarra de Bartleby
-- https://es.classic.wowhead.com/quest=1665
SET @ID := 1665;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vi tu combate con Bartleby. ¡Bien hecho! ¿Tienes su jarra?', 0),
(@ID, 'esMX', 'Vi tu combate con Bartleby. ¡Bien hecho! ¿Tienes su jarra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La tienes! Seguro que no quería separarse de ella pero has sido muy $gpersuasivo:persuasiva;. Bien hecho.$B$BPasemos ahora a tu lección...', 0),
(@ID, 'esMX', '¡La tienes! Seguro que no quería separarse de ella pero has sido muy $gpersuasivo:persuasiva;. Bien hecho.$B$BPasemos ahora a tu lección...', 0);
-- 3100 Una carta simple
-- https://es.classic.wowhead.com/quest=3100
SET @ID := 3100;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, recibiste mi carta, $n ... bien.$B$BRecientemente ha habido una afluencia de guerreros en Elwynn, lo que es bueno para Ventormenta, pero malo para los kobolds y Defias de la zona.', 0),
(@ID, 'esMX', 'Ah, recibiste mi carta, $n ... bien.$B$BRecientemente ha habido una afluencia de guerreros en Elwynn, lo que es bueno para Ventormenta, pero malo para los kobolds y Defias de la zona.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ponte en pie, estudia el terreno y vuelve conmigo cuando necesites formación. Estaré aquí de día o de noche.$B$BLos Caballeros de la Mano de Plata han hecho bien en hacer que este lugar sea bastante seguro, pero cuando conozcas a los otros ciudadanos, creo que encontrarás que todos tienen problemas con los que les vendría bien un poco de ayuda: ayuda que un $c puede brindarles. Buena suerte.', 0),
(@ID, 'esMX', 'Ponte en pie, estudia el terreno y vuelve conmigo cuando necesites formación. Estaré aquí de día o de noche.$B$BLos Caballeros de la Mano de Plata han hecho bien en hacer que este lugar sea bastante seguro, pero cuando conozcas a los otros ciudadanos, creo que encontrarás que todos tienen problemas con los que les vendría bien un poco de ayuda: ayuda que un $c puede brindarles. Buena suerte.', 0);
-- 3102 Una carta cifrada
-- https://es.classic.wowhead.com/quest=3102
SET @ID := 3102;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo hiciste a la primera, y no parece que mucha gente te haya visto. Suficientemente bueno para mi. No me gusta que llamen mucho la atención aquí atrás ... agradable y tranquilo. Estoy seguro de que lo entenderás.$B$B¿Tienes algún problema todavía? Me alegra saber que no. Eso cambiará muy pronto.', 0),
(@ID, 'esMX', 'Lo hiciste a la primera, y no parece que mucha gente te haya visto. Suficientemente bueno para mi. No me gusta que llamen mucho la atención aquí atrás ... agradable y tranquilo. Estoy seguro de que lo entenderás.$B$B¿Tienes algún problema todavía? Me alegra saber que no. Eso cambiará muy pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Descubrirás que hay una serie de personajes que codiciarán nuestras habilidades, $n. Aventureros, IV:7... diablos, incluso a la Hermandad Defias no le importaría tener un espía o dos dentro de Ventormenta. Pero recuerda esto, eres tu propio jefe. ¡No dejes que nadie te intimide para que hagas algo que no quieres hacer! Además, tenemos todas las cartas ... al menos, antes de que termine el juego. ¡Tu ya sabes!$B$BDe todos modos, solo quería presentarme y hacerlte saber que estoy aquí si necesitas capacitación. Ven en cualquier momento.', 0),
(@ID, 'esMX', 'Descubrirás que hay una serie de personajes que codiciarán nuestras habilidades, $n. Aventureros, IV:7... diablos, incluso a la Hermandad Defias no le importaría tener un espía o dos dentro de Ventormenta. Pero recuerda esto, eres tu propio jefe. ¡No dejes que nadie te intimide para que hagas algo que no quieres hacer! Además, tenemos todas las cartas ... al menos, antes de que termine el juego. ¡Tu ya sabes!$B$BDe todos modos, solo quería presentarme y hacerlte saber que estoy aquí si necesitas capacitación. Ven en cualquier momento.', 0);
-- 3103 Una carta sacralizada
-- https://es.classic.wowhead.com/quest=3103
SET @ID := 3103;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al fin llegas; sabía que vendrías. Que la Luz Sagrada te ilumine. Estos son tiempos difíciles, la Legión Ardiente sigue presente en Azeroth. Kalimdor intenta defenderse. Ayuda en todo lo que puedas.', 0),
(@ID, 'esMX', 'Al fin llegas; sabía que vendrías. Que la Luz Sagrada te ilumine. Estos son tiempos difíciles, la Legión Ardiente sigue presente en Azeroth. Kalimdor intenta defenderse. Ayuda en todo lo que puedas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que ganas experiencia, ven a verme y te enseñaré lo posible. Hasta entonces, que la sabiduría guíe tus pasos. Recuerda que de ti depende mejorar el mundo.', 0),
(@ID, 'esMX', 'A medida que ganas experiencia, ven a verme y te enseñaré lo posible. Hasta entonces, que la sabiduría guíe tus pasos. Recuerda que de ti depende mejorar el mundo.', 0);
-- 3104 Una carta glífica
-- https://es.classic.wowhead.com/quest=3104
SET @ID := 3104;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n, me llamo Khelden. ¿Querías algo?', 0),
(@ID, 'esMX', 'Hola, $n, me llamo Khelden. ¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que mi carta no te apartaría de tu camino. Bien, ¿vienes a aceptar tu destino y enfrentarte a quienes se oponen a tu búsqueda de sabiduría y poder?$B$BTe temerán tanto como te respetarán, $n. Y yo siempre estaré aquí para instruirte; solo tienes que venir a buscarme.', 0),
(@ID, 'esMX', 'Sabía que mi carta no te apartaría de tu camino. Bien, ¿vienes a aceptar tu destino y enfrentarte a quienes se oponen a tu búsqueda de sabiduría y poder?$B$BTe temerán tanto como te respetarán, $n. Y yo siempre estaré aquí para instruirte; solo tienes que venir a buscarme.', 0);
-- 3105 Una carta manchada
-- https://es.classic.wowhead.com/quest=3105
SET @ID := 3105;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, entonces has llegado, y no demasiado pronto, $n. Algunos de los guardias estaban aquí hace un momento y me miraban con curiosidad... mundanos patéticos.', 0),
(@ID, 'esMX', 'Ah, entonces has llegado, y no demasiado pronto, $n. Algunos de los guardias estaban aquí hace un momento y me miraban con curiosidad... mundanos patéticos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que crezcas en poder, se sentirás $gtentado:tentada;; siempre debes recordar controlarte. No mentiré: la corrupción puede llegar a cualquier practicante de lo arcano; especialmente uno que trata con criaturas de la oscuridad. Ten paciencia y prudencia ... pero no dejes que eso reprima tu ambición.$B$BA medida que te vuelvas más $gpoderoso:poderosa;, vuelve a mí y te enseñaré más sobre nuestros caminos.', 0),
(@ID, 'esMX', 'A medida que crezcas en poder, se sentirás $gtentado:tentada;; siempre debes recordar controlarte. No mentiré: la corrupción puede llegar a cualquier practicante de lo arcano; especialmente uno que trata con criaturas de la oscuridad. Ten paciencia y prudencia ... pero no dejes que eso reprima tu ambición.$B$BA medida que te vuelvas más $gpoderoso:poderosa;, vuelve a mí y te enseñaré más sobre nuestros caminos.', 0);
-- 3861 ¡CLOQUEA!
-- https://es.classic.wowhead.com/quest=3861
SET @ID := 3861;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El pollo te mira con ojos fríos y cara de hambre.$B$B"¡CO_COOOC!$B$BCoo-co-cooo."', 0),
(@ID, 'esMX', 'El pollo te mira con ojos fríos y cara de hambre.$B$B"¡CO_COOOC!$B$BCoo-co-cooo."', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"¡COO-COOC!"$B$BEl pollo se pone a engullir la comida.$B$BDe pronto se para, como sorprendido, y se agita incómodo. Vaya, este pollo no el un pollo, es una gallina... Será mejor que mires debajo, a ver.', 0),
(@ID, 'esMX', '"¡COO-COOC!"$B$BEl pollo se pone a engullir la comida.$B$BDe pronto se para, como sorprendido, y se agita incómodo. Vaya, este pollo no el un pollo, es una gallina... Será mejor que mires debajo, a ver.', 0);
-- 5805 ¡Te damos la bienvenida!
-- https://es.classic.wowhead.com/quest=5805
SET @ID := 5805;
UPDATE `quest_template_locale` SET `Details` = '¡Bienvenido a World of Warcraft!$B$BComo agradecimiento especial por haber comprado la Edición de coleccionista de World of Warcraft, entrega este vale a Merissa Fontana en Villadorada. Conseguirás un regalo: Un pequeño compañero que te acompañará en tu búsqueda de aventuras y gloria.$B$B¡Gracias de nuevo, y que disfrutes con World of Warcraft!', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(@ID, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, eres $gun:una; $ghéroe:heroina; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(@ID, 'esMX', 'De hecho, eres $gun:una; $ghéroe:heroina; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0);
-- 5623 Al servicio de la Luz
-- https://es.classic.wowhead.com/quest=5623
SET @ID := 5623;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que hayas llegado, $n. Tenemos mucho que hablar. Debemos hablar sobre tu futuro y tu camino en la Luz.', 0),
(@ID, 'esMX', 'Me alegra que hayas llegado, $n. Tenemos mucho que hablar. Debemos hablar sobre tu futuro y tu camino en la Luz.', 0);

-- 5624 Las prendas de la Luz
-- https://es.classic.wowhead.com/quest=5624
SET @ID := 5624;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como ya habrás aprendido, nuestras magias curativas son vitales para la supervivencia de nuestra gente en estos tiempos difíciles, especialmente para los aventureros y héroes que toman las armas y la magia para luchar contra tantas amenazas diferentes.$B$BHarías bien en recordar siempre lo importante que es esa habilidad. Eso, sumado a la Fortaleza, hará que tus compañeros sean mucho más capaces en la batalla, ya que podrán resistir un mayor número de golpes.$B$BNo dejes que nadie descarte lo poderosas que son sus magias.', 0),
(@ID, 'esMX', 'Como ya habrás aprendido, nuestras magias curativas son vitales para la supervivencia de nuestra gente en estos tiempos difíciles, especialmente para los aventureros y héroes que toman las armas y la magia para luchar contra tantas amenazas diferentes.$B$BHarías bien en recordar siempre lo importante que es esa habilidad. Eso, sumado a la Fortaleza, hará que tus compañeros sean mucho más capaces en la batalla, ya que podrán resistir un mayor número de golpes.$B$BNo dejes que nadie descarte lo poderosas que son sus magias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n Con un guardia más sano para ayudar a la ciudad, estaremos mucho más seguros. Me alegra ver que ya estás aprendiendo a usar tus habilidades con sabiduría. Si sientes que estás listo para recibir más capacitación en cualquier momento, por favor regrese a mí. Pero por ahora, coge esta toga. Les permitirá a los demás saber que eres uno de nuestra orden. Si no quieres ponértela, está bien. Más adelante habrá más pruebas y esta toga no es necesaria para ellas.', 0),
(@ID, 'esMX', 'Excelente, $n Con un guardia más sano para ayudar a la ciudad, estaremos mucho más seguros. Me alegra ver que ya estás aprendiendo a usar tus habilidades con sabiduría. Si sientes que estás listo para recibir más capacitación en cualquier momento, por favor regrese a mí. Pero por ahora, coge esta toga. Les permitirá a los demás saber que eres uno de nuestra orden. Si no quieres ponértela, está bien. Más adelante habrá más pruebas y esta toga no es necesaria para ellas.', 0);
-- 9260 Investigar la Plaga de Ventormenta
-- https://es.wowhead.com/quest=9260
SET @ID := 9260;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hmm. Por lo que me dices, las voces dentro de los círculos... deben usarse como comunicación de algún tipo. Me estremezco al pensar en qué mentes antinaturales se contactan a través de tal magia. Independientemente, parece que has salido $gsano:sana; y $gsalvo:salva;. El Alba Argenta agradece tu servicio.', 0),
(@ID, 'esMX', 'Hmm. Por lo que me dices, las voces dentro de los círculos... deben usarse como comunicación de algún tipo. Me estremezco al pensar en qué mentes antinaturales se contactan a través de tal magia. Independientemente, parece que has salido $gsano:sana; y $gsalvo:salva;. El Alba Argenta agradece tu servicio.', 0);
-- 184 Las escrituras de Cejade
-- https://es.classic.wowhead.com/quest=184
SET @ID := 184;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Tienes la escritura de mi granja?? ¡Qué buena noticia! Me la robaron unos rufianes hace unos días... ¡La daba por perdida!$B$BPor favor, deja que la coja. Estamos saliendo de los Páramos de Poniente y no vamos a volver pronto, pero si lo hacemos, necesitaré esos papeles...', 0),
(@ID, 'esMX', '¿¿Tienes la escritura de mi granja?? ¡Qué buena noticia! Me la robaron unos rufianes hace unos días... ¡La daba por perdida!$B$BPor favor, deja que la coja. Estamos saliendo de los Páramos de Poniente y no vamos a volver pronto, pero si lo hacemos, necesitaré esos papeles...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muchas gracias, $n! Como te decía, este ya no es lugar para gente honrada como nosotros. Pero si en un futuro las cosas mejoran, esta escritura nos permitirá reclamar nuestras tierras.$B$BNo tengo mucho que ofrecer, tan solo esto.', 0),
(@ID, 'esMX', '¡Muchas gracias, $n! Como te decía, este ya no es lugar para gente honrada como nosotros. Pero si en un futuro las cosas mejoran, esta escritura nos permitirá reclamar nuestras tierras.$B$BNo tengo mucho que ofrecer, tan solo esto.', 0);
-- 123 El Coleccionista
-- https://es.classic.wowhead.com/quest=123
SET @ID := 123;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué?! ¡Pero si nuestra gente lleva meses sin trabajar en las minas de Elwynn!$B$BDéjame ver esa nota...', 0),
(@ID, 'esMX', '¡¿Qué?! ¡Pero si nuestra gente lleva meses sin trabajar en las minas de Elwynn!$B$BDéjame ver esa nota...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm... He oído hablar de ese Coleccionista, pero no sé para quién trabaja. Gracias por la información. Nos ayudará a resolver este misterio.', 0),
(@ID, 'esMX', 'Mm... He oído hablar de ese Coleccionista, pero no sé para quién trabaja. Gracias por la información. Nos ayudará a resolver este misterio.', 0);
-- 147 La persecución
-- https://es.classic.wowhead.com/quest=147
SET @ID := 147;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado al Coleccionista? ¿Has averiguado para quién trabaja?', 0),
(@ID, 'esMX', '¿Has encontrado al Coleccionista? ¿Has averiguado para quién trabaja?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has encontrado? Bien hecho, $n. ¡Ya no volverá a "coleccionar"!$B$BY... este anillo que encontraste es muy interesante. Es un anillo de la antigua Hermandad de albañiles de Ventormenta. ¿Cómo habrá llegado el anillo de una hermandad de artesanos a manos de un mísero ladrón? ¿Y por qué los ladrones Defias se llevan dinero de nuestras minas?$B$BSon preguntas difíciles de responder. Pero espero que algún día encontraré esas respuestas.', 0),
(@ID, 'esMX', '¿Lo has encontrado? Bien hecho, $n. ¡Ya no volverá a "coleccionar"!$B$BY... este anillo que encontraste es muy interesante. Es un anillo de la antigua Hermandad de albañiles de Ventormenta. ¿Cómo habrá llegado el anillo de una hermandad de artesanos a manos de un mísero ladrón? ¿Y por qué los ladrones Defias se llevan dinero de nuestras minas?$B$BSon preguntas difíciles de responder. Pero espero que algún día encontraré esas respuestas.', 0);
-- 1666 El mariscal Haggard
-- https://es.classic.wowhead.com/quest=1666
SET @ID := 1666;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién es?$B$B¿Burlguard, eres tú?$B$BTendrás que acercarte un poco más. Mis ojos ya no son lo que eran. $B$B¡Andando así creía que eras un gnoll!', 0),
(@ID, 'esMX', '¿Quién es?$B$B¿Burlguard, eres tú?$B$BTendrás que acercarte un poco más. Mis ojos ya no son lo que eran. $B$B¡Andando así creía que eras un gnoll!', 0);
-- 1667 Jack Dentomuerto
-- https://es.classic.wowhead.com/quest=1667
SET @ID := 1667;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi insignia? No quiero ni pensar en todo el daño que ha podido hacer Jack Dentomuerto con ella.', 0),
(@ID, 'esMX', '¿Tienes mi insignia? No quiero ni pensar en todo el daño que ha podido hacer Jack Dentomuerto con ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡La encontraste! Temía que estuviera perdida para siempre y que la utilizaran los Defias para fingir ser algún oficial de Ventormenta. Bien, ahora ya no pueden hacerlo, gracias a ti.$B$BEstas son algunas armas que utilicé cuando era alguacil. Las conservé en buen estado, ¡elige lo que quieras!', 0),
(@ID, 'esMX', '¡Genial! ¡La encontraste! Temía que estuviera perdida para siempre y que la utilizaran los Defias para fingir ser algún oficial de Ventormenta. Bien, ahora ya no pueden hacerlo, gracias a ti.$B$BEstas son algunas armas que utilicé cuando era alguacil. Las conservé en buen estado, ¡elige lo que quieras!', 0);
-- 2205 Busca el IV:7
-- https://es.classic.wowhead.com/quest=2205
SET @ID := 2205;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte, $c?', 0),
(@ID, 'esMX', '¿Puedo ayudarte, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me encontraste, y al mirarte, diría que la carrera y la búsqueda posterior pueden haber sido una gran tensión para tu sistema, tanto mental como físicamente.$B$B¿Te gustaría que Renzik te mostrara el camino a una posada o estás listo para trabajar?', 0),
(@ID, 'esMX', 'Me encontraste, y al mirarte, diría que la carrera y la búsqueda posterior pueden haber sido una gran tensión para tu sistema, tanto mental como físicamente.$B$B¿Te gustaría que Renzik te mostrara el camino a una posada o estás listo para trabajar?', 0);
-- 1860 Habla con Jennea
-- https://es.classic.wowhead.com/quest=1860
SET @ID := 1860;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te han enviado para ayudarme con mi tarea, $n? Bien. Es alentador ver cómo $glos:las; jóvenes $gmagos:magas; se esfuerzan por ayudar a nuestra causa...$B$B¿Qué causa, dices? A su debido tiempo, joven. Lo sabrás... a su debido tiempo.', 0),
(@ID, 'esMX', '¿Te han enviado para ayudarme con mi tarea, $n? Bien. Es alentador ver cómo $glos:las; jóvenes $gmagos:magas; se esfuerzan por ayudar a nuestra causa...$B$B¿Qué causa, dices? A su debido tiempo, joven. Lo sabrás... a su debido tiempo.', 0);
-- 1861 Lago Espejo
-- https://es.classic.wowhead.com/quest=1861
SET @ID := 1861;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la muestra, $n? El flujo mágico de Ventormenta y Elwynn ha sido alterado y debo averiguar si se está filtrando en el agua.', 0),
(@ID, 'esMX', '¿Tienes la muestra, $n? El flujo mágico de Ventormenta y Elwynn ha sido alterado y debo averiguar si se está filtrando en el agua.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Comprobaré las propiedades mágicas de este agua. Esperemos que no contenga ninguna o los que han estado bebiendo demasiado tiempo agua del Lago Espejo podrían estar afectados.$B$BToma, $n. Coge este orbe o este bastón como prueba de tus servicios. Que te sean de ayuda.', 0),
(@ID, 'esMX', 'Gracias, $n. Comprobaré las propiedades mágicas de este agua. Esperemos que no contenga ninguna o los que han estado bebiendo demasiado tiempo agua del Lago Espejo podrían estar afectados.$B$BToma, $n. Coge este orbe o este bastón como prueba de tus servicios. Que te sean de ayuda.', 0);
-- 2206 El robo
-- https://es.wowhead.com/quest=2206
SET @ID := 2206;
UPDATE `quest_template_locale` SET `Objectives` = 'Encuentra al maestro de embarcadero y recupera el calendario de envíos para el maestro Mathias Shaw.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu mortandad disminuye con cada momento que desperdicias merodeando en los barracones, $c.', 0),
(@ID, 'esMX', 'Tu mortandad disminuye con cada momento que desperdicias merodeando en los barracones, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy asombrado ... Asombrado de que Keryn finalmente haya encontrado $gun:una; recluta que posiblemente podría tener los ingredientes de $gun:una; $c adecuado. Toma esta espada, $n. Llegará un día en que se te llamará nuevamente para servir al IV:7. Perfecciona tus habilidades, mantén los ojos abiertos y la hoja afilada.$B$BNo nos verás venir pero lo sentirás cuando lleguemos ...', 0),
(@ID, 'esMX', 'Estoy asombrado ... Asombrado de que Keryn finalmente haya encontrado $gun:una; recluta que posiblemente podría tener los ingredientes de $gun:una; $c adecuado. Toma esta espada, $n. Llegará un día en que se te llamará nuevamente para servir al IV:7. Perfecciona tus habilidades, mantén los ojos abiertos y la hoja afilada.$B$BNo nos verás venir pero lo sentirás cuando lleguemos ...', 0);
-- 2360 Mathias y los Defias
-- https://es.classic.wowhead.com/quest=2360
SET @ID := 2360;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mathias finalmente envió a otro agente para respaldarme, ¿eh? Bueno, espero que esté listo para escuchar malas noticias.', 0),
(@ID, 'esMX', 'Mathias finalmente envió a otro agente para respaldarme, ¿eh? Bueno, espero que esté listo para escuchar malas noticias.', 0);
-- 2359 La torre de Klaven
-- https://es.classic.wowhead.com/quest=2359
SET @ID := 2359;
UPDATE `quest_template_locale` SET `Objectives` = 'Roba la Llave de la Torre Defias, entra en la Torre Defias y descubre qué contiene el Cofre del Bosque del Ocaso. Lleva toda la información que encuentres a Mathias Shaw de Ventormenta. Lee el diario de Kearnen para saber cómo acceder a la torre.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna noticia del agente Kearnen?', 0),
(@ID, 'esMX', '¿Alguna noticia del agente Kearnen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto explicaría los Defias que tú y Kearnen vieron fuera de la torre, $n. También explicaría la participación de Ventura y Cía. con los Defias y los extraños envíos del Bosque del Ocaso.$B$BSegún este libro, los trols Zanzil de Tuercespina han descubierto una forma de resucitar a los muertos mediante pociones... o para ser más específicos: veneno.$B$BNo serás de utilidad para IV:7 sin una comprensión firme de los venenos, $n, especialmente con la receta para crear no-muerte al alcance de la mano.', 0),
(@ID, 'esMX', 'Esto explicaría los Defias que tú y Kearnen vieron fuera de la torre, $n. También explicaría la participación de Ventura y Cía. con los Defias y los extraños envíos del Bosque del Ocaso.$B$BSegún este libro, los trols Zanzil de Tuercespina han descubierto una forma de resucitar a los muertos mediante pociones... o para ser más específicos: veneno.$B$BNo serás de utilidad para IV:7 sin una comprensión firme de los venenos, $n, especialmente con la receta para crear no-muerte al alcance de la mano.', 0);
-- 2607 Toque de Zanzil
-- https://es.classic.wowhead.com/quest=2607
SET @ID := 2607;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya es hora! Simplemente ponga el queso en la mesa y salte. Osborne te pagará a la salida.', 0),
(@ID, 'esMX', '¡Ya es hora! Simplemente ponga el queso en la mesa y salte. Osborne te pagará a la salida.', 0);
-- 7638 Lord Grisillo Quiebrasombras
-- https://es.classic.wowhead.com/quest=7638
SET @ID := 7638;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir tu montura, y ahora ha llegado el momento.$B$BSeguramente serás probado de muchas formas diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!.', 0),
(@ID, 'esMX', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir tu montura, y ahora ha llegado el momento.$B$BSeguramente serás probado de muchas formas diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!.', 0);
-- 171 Alcaide de la Alianza
-- https://es.wowhead.com/quest=171
SET @ID := 171;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer volver a verte, $n. ¿Has cumplido las obligaciones con las que te comprometiste al ofrecerte como voluntario para la Semana de los Niños?', 0),
(@ID, 'esMX', 'Es un placer volver a verte, $n. ¿Has cumplido las obligaciones con las que te comprometiste al ofrecerte como voluntario para la Semana de los Niños?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¡Un regalo para todos los huérfanos!$B$BQue los cielos te bendigan, $n. Has hecho más por Randis de lo que nunca hubiera pensado. Gracias, eres una estrella brillante en los cielos de la Alianza.$B$BRandis se ha divertido mucho contigo, $n, y ha querido darte una de sus mascotas favoritas para que no te olvides de él.', 0),
(@ID, 'esMX', '¿Qué es esto? ¡Un regalo para todos los huérfanos!$B$BQue los cielos te bendigan, $n. Has hecho más por Randis de lo que nunca hubiera pensado. Gracias, eres una estrella brillante en los cielos de la Alianza.$B$BRandis se ha divertido mucho contigo, $n, y ha querido darte una de sus mascotas favoritas para que no te olvides de él.', 0);
-- 14180 Llamamiento a las armas: Garganta Grito de Guerra
-- https://es.wowhead.com/quest=14180
SET @ID := 14180;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes del frente, $n?', 0),
(@ID, 'esMX', '¿Qué noticias traes del frente, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0);
-- 13478 Esfuerzos concertados
-- https://es.wowhead.com/quest=13478
SET @ID := 13478;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal te va en tus viajes, $gchico:chica;?', 0),
(@ID, 'esMX', '¿Qué tal te va en tus viajes, $gchico:chica;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No eres alguien que decepcione, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0),
(@ID, 'esMX', '¡No eres alguien que decepcione, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0);
-- 13427 Llamamiento a las armas: Valle de Alterac
-- https://es.wowhead.com/quest=13427
SET @ID := 13427;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0),
(@ID, 'esMX', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0);
-- 1715 El Cordero Degollado
-- https://es.classic.wowhead.com/quest=1715
SET @ID := 1715;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Llavenegra? Esos malditos brujos de Forjaz tienen que organizarse; no hay tantos instructores en Ventormenta. Tanto movimiento acabará por llamar la atención.', 0),
(@ID, 'esMX', '¿Te envía Llavenegra? Esos malditos brujos de Forjaz tienen que organizarse; no hay tantos instructores en Ventormenta. Tanto movimiento acabará por llamar la atención.', 0);
-- 8385 Esfuerzos concertados
-- https://es.classic.wowhead.com/quest=8385
SET @ID := 8385;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n. Espero que sigas aportando tu experiencia a los diferentes frentes de batalla. Muchos de nuestros muchachos y muchachas en el campo admiran a los veteranos experimentados como tú.', 0),
(@ID, 'esMX', 'Ah, $n. Espero que sigas aportando tu experiencia a los diferentes frentes de batalla. Muchos de nuestros muchachos y muchachas en el campo admiran a los veteranos experimentados como tú.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás a la altura de tu reputación, $n. Sin gente como tú, la Alianza no tendría ninguna posibilidad contra las fuerzas salvajes de la Horda.', 0),
(@ID, 'esMX', 'Estás a la altura de tu reputación, $n. Sin gente como tú, la Alianza no tendría ninguna posibilidad contra las fuerzas salvajes de la Horda.', 0);
-- 8897 Queridísima Colara:
-- https://es.classic.wowhead.com/quest=8897
SET @ID := 8897;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola $gguapo:guapa;. ¿Te puedo ayudar en algo?', 0),
(@ID, 'esMX', 'Hola $gguapo:guapa;. ¿Te puedo ayudar en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, es tan dulce! Esta es la primera vez que me envía algo. ¿Crees que se está poniendo serio?$B$BColara Heldric? Supongo que suena... Oh, pero me estoy adelantando. Gracias.', 0),
(@ID, 'esMX', '¡Oh, es tan dulce! Esta es la primera vez que me envía algo. ¿Crees que se está poniendo serio?$B$BColara Heldric? Supongo que suena... Oh, pero me estoy adelantando. Gracias.', 0);

-- 7670 Lord Grisillo Quiebrasombras
-- https://es.wowhead.com/quest=7670
SET @ID := 7670;
UPDATE `quest_template_locale` SET `Details` = '$n, voy a explicarte lo que debes hacer para conseguir una montura.$B$BHabla con Lord Grisillo Quiebrasombras en el Distrito de la Catedral de Ventormenta. Te enseñará a cuidar de tu montura y te dirá qué tareas debes completar para conseguir una.$B$BTe deseo lo mejor. ¡Por la Luz, mi noble $ghermano:hermana;', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir su montura, y ahora ha llegado el momento.$B$BSeguramente se te pondrá a prueba de muchas maneras diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!', 0),
(@ID, 'esMX', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir su montura, y ahora ha llegado el momento.$B$BSeguramente se te pondrá a prueba de muchas maneras diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!', 0);
-- 8646 Rugidomazo el Ancestro
-- https://es.wowhead.com/quest=8646
SET @ID := 8646;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 7648 Un trabajo bien hecho
-- https://es.classic.wowhead.com/quest=7648
SET @ID := 7648;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás progresando muy bien, $n. Una vez que haya hecho su barda, estará en camino a la siguiente tarea.', 0),
(@ID, 'esMX', 'Estás progresando muy bien, $n. Una vez que haya hecho su barda, estará en camino a la siguiente tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este trabajo es impresionante. Parece que a medida que Grimand envejece, su destreza continúa mejorando. Esa es una gran hazaña cuando su trabajo ya era uno de los mejores que encontrarías en cualquier lugar cuando hizo mi barda en el pasado.$B$BSi bien esta barda sería una excelente adición a cualquier corcel normal, no estamos tratando con una bestia tan mundana. Necesitará esta barda bendecida por una fuente adecuada para que sea digna de descansar sobre la montura de $gun:una; $c. Lo guardaré por ti hasta entonces.', 0),
(@ID, 'esMX', 'Este trabajo es impresionante. Parece que a medida que Grimand envejece, su destreza continúa mejorando. Esa es una gran hazaña cuando su trabajo ya era uno de los mejores que encontrarías en cualquier lugar cuando hizo mi barda en el pasado.$B$BSi bien esta barda sería una excelente adición a cualquier corcel normal, no estamos tratando con una bestia tan mundana. Necesitará esta barda bendecida por una fuente adecuada para que sea digna de descansar sobre la montura de $gun:una; $c. Lo guardaré por ti hasta entonces.', 0);
-- 11335 Llamamiento a las armas: Cuenca de Arathi
-- https://es.wowhead.com/quest=11335
SET @ID := 11335;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0),
(@ID, 'esMX', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0);
-- 1468 Semana de los Niños
-- https://es.wowhead.com/quest=1468
SET @ID := 1468;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm... hola. Me llamo Randis y supongo que me estás buscando, ¿no? Eres un aventurero, como lo fueron mi mamá y mi papá. Me alegro de conocerte.$B$BEspero que nos divirtamos mucho juntos. Hay unas cosas que me gustaría hacer, y mi matrona dice que harás de hermano para mí esta semana. Me encantaría, sí señor.', 0),
(@ID, 'esMX', 'Mm... hola. Me llamo Randis y supongo que me estás buscando, ¿no? Eres un aventurero, como lo fueron mi mamá y mi papá. Me alegro de conocerte.$B$BEspero que nos divirtamos mucho juntos. Hay unas cosas que me gustaría hacer, y mi matrona dice que harás de hermano para mí esta semana. Me encantaría, sí señor.', 0);
-- 11336 Llamamiento a las armas: Valle de Alterac
-- https://es.wowhead.com/quest=11336
SET @ID := 11336;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0),
(@ID, 'esMX', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0);
-- 11337 Llamamiento a las armas: Ojo de la Tormenta
-- https://es.wowhead.com/quest=11337
SET @ID := 11337;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hemos dado un paso más para lograr la victoria total sobre la Horda. No podemos permitir que el enemigo se establezca en este mundo o en cualquier otro.', 0),
(@ID, 'esMX', 'Hemos dado un paso más para lograr la victoria total sobre la Horda. No podemos permitir que el enemigo se establezca en este mundo o en cualquier otro.', 0);
-- 11338 Llamamiento a las armas: Garganta Grito de Guerra
-- https://es.wowhead.com/quest=11338
SET @ID := 11338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0);
-- 9292 Cristal necrótico rajado
-- https://es.classic.wowhead.com/quest=9292
SET @ID := 9292;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hay algo que necesites?', 0),
(@ID, 'esMX', '¿Hay algo que necesites?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hm, ¿tomaste esto del cadáver de una de las abominaciones invasoras?$B$BHemos recibido noticias desde los campamentos base de la necrópolis que están siendo convocados por la Plaga. Sospecho que querían crear uno dentro de Ventormenta. Es bueno que no hayan tenido éxito.', 0),
(@ID, 'esMX', 'Hm, ¿tomaste esto del cadáver de una de las abominaciones invasoras?$B$BHemos recibido noticias desde los campamentos base de la necrópolis que están siendo convocados por la Plaga. Sospecho que querían crear uno dentro de Ventormenta. Es bueno que no hayan tenido éxito.', 0);
-- 5634
SET @ID := 5634;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'You have done the Light a great service by becoming a shining example to those who travel in these dangerous lands and beyond. Please, accept this lesson as a thanks for all you\'ve done.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(@ID, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0);
-- 5635, 5636, 5637, 5638, 5639, 5640 Oración desesperada
-- https://es.classic.wowhead.com/quest=5635
DELETE FROM `quest_offer_reward` WHERE `ID` IN (5635, 5636, 5637, 5638, 5639, 5640);
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES 
(5635, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5636, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5637, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5638, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5639, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5640, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (5635, 5636, 5637, 5638, 5639, 5640) AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5635, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5636, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5637, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5638, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5639, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5640, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5635, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5636, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5637, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5638, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5639, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5640, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0);
-- 1661 Escrito sobre nobleza
-- https://es.classic.wowhead.com/quest=1661
SET @ID := 1661;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'Congratulations, and may the Light protect you.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Felicitaciones y que la Luz te proteja.', 0),
(@ID, 'esMX', 'Felicitaciones y que la Luz te proteja.', 0);
-- 14163 Llamamiento a las armas: Isla de la Conquista
-- https://es.wowhead.com/quest=14163
SET @ID := 14163;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué bueno verte, $n! ¿Tienes noticias del frente?', 0),
(@ID, 'esMX', '¡Qué bueno verte, $n! ¿Tienes noticias del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Horda nunca será rival para nuestras fuerzas mientras tengamos a gente como tú de nuestro lado, $n.', 0),
(@ID, 'esMX', 'La Horda nunca será rival para nuestras fuerzas mientras tengamos a gente como tú de nuestro lado, $n.', 0);
-- 3681 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=3681
SET @ID := 3681;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; a la Catedral de la Luz, $c.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; a la Catedral de la Luz, $c.', 0);
-- 1790 El Símbolo de la Vida
-- https://es.classic.wowhead.com/quest=1790
SET @ID := 1790;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, $n, más de una vida está en juego si fallas.$B$BSi por alguna razón no ayudas a Gazin y Henze, regresa conmigo y te daré otro Símbolo de Vida para tus viajes.$B$BNo confundas mi ayuda con una simple caridad, debes demostrar que eres digno como cualquier otro $c y el fracaso continuo puede reflejarse en ti más adelante.', 0),
(@ID, 'esMX', 'Date prisa, $n, más de una vida está en juego si fallas.$B$BSi por alguna razón no ayudas a Gazin y Henze, regresa conmigo y te daré otro Símbolo de Vida para tus viajes.$B$BNo confundas mi ayuda con una simple caridad, debes demostrar que eres digno como cualquier otro $c y el fracaso continuo puede reflejarse en ti más adelante.', 0);
-- 8860 ¡Las fiestas de Año Nuevo!
-- https://es.wowhead.com/quest=8860
SET @ID := 8860;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! ¿Has venido al festival o solo te has parado a descansar?', 0),
(@ID, 'esMX', '¡Saludos! ¿Has venido al festival o solo te has parado a descansar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la comida de Pastos de Bosquehumeante! ¡Estupendo!$B$BGracias, $n. Acepta esto como recompensa; y ahora, ¡sal a beber y a divertirte!', 0),
(@ID, 'esMX', '¡Ah, la comida de Pastos de Bosquehumeante! ¡Estupendo!$B$BGracias, $n. Acepta esto como recompensa; y ahora, ¡sal a beber y a divertirte!', 0);
-- 5676 La reacción Arcana
-- https://es.classic.wowhead.com/quest=5676
SET @ID := 5676;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos vimos obligados a aprender algunas magias para protegernos de lo que comúnmente se llama nuestro mayor enemigo: los arcanos.$B$BTe enseñaré un hechizo para ayudarte a defenderte a ti mismo y a tus compañeros de aquellos que ejercen tal poder.', 0),
(@ID, 'esMX', 'Nos vimos obligados a aprender algunas magias para protegernos de lo que comúnmente se llama nuestro mayor enemigo: los arcanos.$B$BTe enseñaré un hechizo para ayudarte a defenderte a ti mismo y a tus compañeros de aquellos que ejercen tal poder.', 0);
-- 5677 La reacción Arcana
-- https://es.classic.wowhead.com/quest=5677
SET @ID := 5677;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'Ah, you have wonderful timing, <name>. I was beginning to wonder if all of my messengers had been successful. I\'m glad to see they were, otherwise I would wager you\'d still be out in the world learning more about all the threats that exist against our people.$B$BAre you ready? Ready for more training I mean. You\'re growing in power more quickly, and I feel you are ready to learn more about our faith.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0),
(@ID, 'esMX', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0);
-- 5678 La reacción Arcana
-- https://es.classic.wowhead.com/quest=5677
SET @ID := 5678;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'Ah, you have wonderful timing, <name>. I was beginning to wonder if all of my messengers had been successful. I\'m glad to see they were, otherwise I would wager you\'d still be out in the world learning more about all the threats that exist against our people.$B$BAre you ready? Ready for more training I mean. You\'re growing in power more quickly, and I feel you are ready to learn more about our faith.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0),
(@ID, 'esMX', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0);
-- 7630 La arcanita
-- https://es.classic.wowhead.com/quest=7630
SET @ID := 7630;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la arcanita, $n? Una vez que lo tenga, puedo hacerte la magnetita.', 0),
(@ID, 'esMX', '¿Tienes la arcanita, $n? Una vez que lo tenga, puedo hacerte la magnetita.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo tienes! ¡Bien hecho! Ahora puedo crear la magnetita. Cuando finalmente estés listo para tu ritual para crear el Círculo de Invocación Mayor, querrás una magnetita para asegurarte de que el ritual no se esfume.', 0),
(@ID, 'esMX', '¡Lo tienes! ¡Bien hecho! Ahora puedo crear la magnetita. Cuando finalmente estés listo para tu ritual para crear el Círculo de Invocación Mayor, querrás una magnetita para asegurarte de que el ritual no se esfume.', 0);
-- 14178 Llamamiento a las armas: Cuenca de Arathi
-- https://es.wowhead.com/quest=14178
SET @ID := 14178;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0),
(@ID, 'esMX', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0);

-- 7023 ¡El Gran Padre Invierno está aquí!
-- https://es.wowhead.com/quest=7023
SET @ID := 7023;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(@ID, 'esMX', 'Hola, hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0);
-- 8356 Saca músculo a cambio de almendrados
-- https://es.wowhead.com/quest=8356
SET @ID := 8356;
UPDATE `quest_template_locale` SET `Objectives` = 'Saca músculos para la tabernera Allison y, a cambio, recibirás un almendrado de Ventormenta.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nada de dulces hasta que saques músculo para mí, $n...', 0),
(@ID, 'esMX', 'Nada de dulces hasta que saques músculo para mí, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja, eres muy poderoso! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', 0),
(@ID, 'esMX', '¡Ja, ja, eres muy poderoso! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', 0);
-- 8371 Esfuerzos concertados
-- https://es.classic.wowhead.com/quest=8371
SET @ID := 8371;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te va en tus viajes, $gchico:chica;?', 0),
(@ID, 'esMX', '¿Cómo te va en tus viajes, $gchico:chica;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No eres de los que decepcionan, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0),
(@ID, 'esMX', '¡No eres de los que decepcionan, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0);
-- 7637 Énfasis en el sacrificio
-- https://es.classic.wowhead.com/quest=7637
SET @ID := 7637;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos, noble $c! He preparado mi incensario de confianza con el incienso más fresco y lo he bendecido tres veces para su uso. Tu donación nos ayudará en Forjaz no solo a crear un nuevo incensario, sino también a reforzar las reservas de comida para nuestros necesitados.', 0),
(@ID, 'esMX', '¡Saludos, noble $c! He preparado mi incensario de confianza con el incienso más fresco y lo he bendecido tres veces para su uso. Tu donación nos ayudará en Forjaz no solo a crear un nuevo incensario, sino también a reforzar las reservas de comida para nuestros necesitados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bendiciones para ti, $gamigo:amiga; $c! Tu donación va mucho más allá de lo necesario. Tu sacrificio no solo nos ayudará a recuperar lo que hemos perdido, sino que también nos ayudará a ayudar a los más necesitados aquí en Forjaz.$B$BAhora, déjeme asegurarme de haber preparado adecuadamente este incensario para tus necesidades futuras...', 0),
(@ID, 'esMX', '¡Bendiciones para ti, $gamigo:amiga; $c! Tu donación va mucho más allá de lo necesario. Tu sacrificio no solo nos ayudará a recuperar lo que hemos perdido, sino que también nos ayudará a ayudar a los más necesitados aquí en Forjaz.$B$BAhora, déjeme asegurarme de haber preparado adecuadamente este incensario para tus necesidades futuras...', 0);
-- 7639 Mostrarse juicioso
-- https://es.classic.wowhead.com/quest=7639
SET @ID := 7639;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de nuevo, $n. ¿Has adquirido el incensario de exorcismo?', 0),
(@ID, 'esMX', 'Bienvenido de nuevo, $n. ¿Has adquirido el incensario de exorcismo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esto servirá. Se le pedirá más de una vez durante este proceso para realizar actos de sacrificio; Me alegra ver que está dispuesto a hacer precisamente eso. El sacrificio es un componente clave en lo que se necesita para cumplir con los deberes de ser un Paladín ... pero no tengo que sermonearte sobre eso.$B$BAhora $n, deberás mostrar el debido juicio en tus acciones. Con ese fin, este incensario actuará como tu recipiente para emitir tal juicio sobre los espíritus torturados de tierras perdidas para nosotros.', 0),
(@ID, 'esMX', 'Sí, esto servirá. Se le pedirá más de una vez durante este proceso para realizar actos de sacrificio; Me alegra ver que está dispuesto a hacer precisamente eso. El sacrificio es un componente clave en lo que se necesita para cumplir con los deberes de ser un Paladín ... pero no tengo que sermonearte sobre eso.$B$BAhora $n, deberás mostrar el debido juicio en tus acciones. Con ese fin, este incensario actuará como tu recipiente para emitir tal juicio sobre los espíritus torturados de tierras perdidas para nosotros.', 0);
-- 658 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=658
SET @ID := 658;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te agradecemos tu ayuda en la búsqueda de ese mensajero, $n.$B$BMientras estabas ausente, Kin vio a un boticario salir de la misma casa al sur de este lugar. Estoy seguro que no pueden tramar nada bueno, solo necesito una prueba antes de salir y hacer algo imprudente.$B$B¿Has encontrado algo?', 0),
(@ID, 'esMX', 'Te agradecemos tu ayuda en la búsqueda de ese mensajero, $n.$B$BMientras estabas ausente, Kin vio a un boticario salir de la misma casa al sur de este lugar. Estoy seguro que no pueden tramar nada bueno, solo necesito una prueba antes de salir y hacer algo imprudente.$B$B¿Has encontrado algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico!$B$BVeamos de qué se trata...', 0),
(@ID, 'esMX', '¡Fantástico!$B$BVeamos de qué se trata...', 0);
-- 657 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=657
SET @ID := 657;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si le trae a Phin el descanso, destruiré personalmente uno a uno a esos Renegados. Ha hecho tanto por nosotros desde la Peste. Nunca pensé que volvería a ver a mis amigos o a la familia.$B$BDame un toque cuando estés <preparado(preparada>. Empezaremos enseguida.', 0),
(@ID, 'esMX', 'Si le trae a Phin el descanso, destruiré personalmente uno a uno a esos Renegados. Ha hecho tanto por nosotros desde la Peste. Nunca pensé que volvería a ver a mis amigos o a la familia.$B$BDame un toque cuando estés $gpreparado:preparada;. Empezaremos enseguida.', 0);
-- 660 Sospechas de una nueva Peste
-- https://es.wowhead.com/quest=660
SET @ID := 660;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos has hecho un gran favor, $n. Gracias.$B$BEspero que Kin no te lo pusiera demasiado difícil. Es muy simpática pero como enemiga es letal.', 0),
(@ID, 'esMX', 'Nos has hecho un gran favor, $n. Gracias.$B$BEspero que Kin no te lo pusiera demasiado difícil. Es muy simpática pero como enemiga es letal.', 0);
-- 661 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=661
SET @ID := 661;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Conque esas dos pícaras están bien después de todo?! Ja, ja, me alegra oírlo. Te agradezco las noticias sobre su paradero y su estado; me complace enormemente que sigan vivas, los dos son amigas insustituibles y viejas compañeras de fatigas.$B$BPero... es más importante que te agradezca como es debido tu ayuda. Aquí tienes además de la gratitud de todos los míos.$B$BCon algo de suerte, averiguaremos qué traman los Renegados y le pondremos fin.', 0),
(@ID, 'esMX', '¡¿Conque esas dos pícaras están bien después de todo?! Ja, ja, me alegra oírlo. Te agradezco las noticias sobre su paradero y su estado; me complace enormemente que sigan vivas, los dos son amigas insustituibles y viejas compañeras de fatigas.$B$BPero... es más importante que te agradezca como es debido tu ayuda. Aquí tienes además de la gratitud de todos los míos.$B$BCon algo de suerte, averiguaremos qué traman los Renegados y le pondremos fin.', 0);
-- 1105 Caparazones endurecidos
-- https://es.classic.wowhead.com/quest=1105
SET @ID := 1105;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi hermano está haciendo progresos en su nuevo combustible y eso me intranquiliza. ¡Quiero ponerme manos a la obra con el depósito de caparazón de tortura lo antes posible!$B$B$n, ¿tienes ya los caparazones?', 0),
(@ID, 'esMX', 'Mi hermano está haciendo progresos en su nuevo combustible y eso me intranquiliza. ¡Quiero ponerme manos a la obra con el depósito de caparazón de tortura lo antes posible!$B$B$n, ¿tienes ya los caparazones?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los has conseguido! ¡Gracias, $n!$B$BVaya, estos caparazones son más duros de lo que yo pensaba. ¡Voy a romper todas mis herramientas!', 0),
(@ID, 'esMX', '¡Los has conseguido! ¡Gracias, $n!$B$BVaya, estos caparazones son más duros de lo que yo pensaba. ¡Voy a romper todas mis herramientas!', 0);
-- 1176 Menos peso
-- https://es.classic.wowhead.com/quest=1176
SET @ID := 1176;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los huesos? Estaba pensando en aligerar la dirección pero no quiero empezar hasta tener todas las piezas que necesito.', 0),
(@ID, 'esMX', '¿Tienes los huesos? Estaba pensando en aligerar la dirección pero no quiero empezar hasta tener todas las piezas que necesito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Ya puedo poner al equipo técnico a trabajar en esto. ¡Gracias, $n!', 0),
(@ID, 'esMX', '¡Genial! Ya puedo poner al equipo técnico a trabajar en esto. ¡Gracias, $n!', 0);
-- 1104 Veneno de El Desierto de Sal
-- https://es.classic.wowhead.com/quest=1104
SET @ID := 1104;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, hola, hola! ¿¿Conseguiste el veneno??', 0),
(@ID, 'esMX', '¡Hola, hola, hola! ¿¿Conseguiste el veneno??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Este veneno será perfecto! ¡Gracias, $n!$B$BAhora solo tengo que espesarlo algo, echarle un poco de correcina, añadir un negacatalizador y... ¡Maldición! ¿¡Dónde están mis notas!?', 0),
(@ID, 'esMX', '¡Genial! ¡Este veneno será perfecto! ¡Gracias, $n!$B$BAhora solo tengo que espesarlo algo, echarle un poco de correcina, añadir un negacatalizador y... ¡Maldición! ¿¡Dónde están mis notas!?', 0);
-- 1110 Las piezas de coche cohete
-- https://es.classic.wowhead.com/quest=1110
SET @ID := 1110;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has estado en El Desierto de Sal? ¿Me has traído las piezas que quería?', 0),
(@ID, 'esMX', '$n, ¿has estado en El Desierto de Sal? ¿Me has traído las piezas que quería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, mira todo eso! Hay algunas cosas interesantes en ese montón de basura. Seguro que saco un buen pellizco por ellas.$B$BEspera... ¿eso que está ahí espachurrado es una oreja? ¡Qué dolor! No me gustaría ser ese piloto...$B$BGracias, $n. Aquí tienes tu dinero. Y te voy a dar un consejo gratis...$B$BSiempre se puede sacar beneficio de las desgracias ajenas.', 0),
(@ID, 'esMX', '¡Vaya, mira todo eso! Hay algunas cosas interesantes en ese montón de basura. Seguro que saco un buen pellizco por ellas.$B$BEspera... ¿eso que está ahí espachurrado es una oreja? ¡Qué dolor! No me gustaría ser ese piloto...$B$BGracias, $n. Aquí tienes tu dinero. Y te voy a dar un consejo gratis...$B$BSiempre se puede sacar beneficio de las desgracias ajenas.', 0);
-- 1175 Un bache en la carretera
-- https://es.classic.wowhead.com/quest=1175
SET @ID := 1175;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya es bastante malo tener que limpiar los restos de los corredores sin tener que sacarlos de partes de animales quemados.', 0),
(@ID, 'esMX', 'Ya es bastante malo tener que limpiar los restos de los corredores sin tener que sacarlos de partes de animales quemados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que no hayas matado a ningún basilisco en la pista! Sus cuerpos tardan mucho en descomponerse al sol y prefiero no tener que coger una pala para despejar la pista.', 0),
(@ID, 'esMX', '¡Espero que no hayas matado a ningún basilisco en la pista! Sus cuerpos tardan mucho en descomponerse al sol y prefiero no tener que coger una pala para despejar la pista.', 0);
-- 1178 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1178
SET @ID := 1178;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Pozzik, eh? Sabes, Pozzik era uno de los manitas más respetados de Minahonda hasta que decidió dejarlo todo para dedicarse a las carreras.$B$BLo primero que hizo tras unirse al equipo fue desarrollar el coche de doble motor. Puede ser que el negocio experimente un bajón ahora que él ya no trabaja en el Gremio de Manitas pero... ¿a quién le importa? ¡No hay nada como las carreras!', 0),
(@ID, 'esMX', '¿Te envía Pozzik, eh? Sabes, Pozzik era uno de los manitas más respetados de Minahonda hasta que decidió dejarlo todo para dedicarse a las carreras.$B$BLo primero que hizo tras unirse al equipo fue desarrollar el coche de doble motor. Puede ser que el negocio experimente un bajón ahora que él ya no trabaja en el Gremio de Manitas pero... ¿a quién le importa? ¡No hay nada como las carreras!', 0);
-- 1106 Martek el Exiliado
-- https://es.classic.wowhead.com/quest=1106
SET @ID := 1106;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Genial, me has encontrado. Bien por ti.$B$B¿Vienes por el hacha que le hice a Gath\'Ilzogg? ¿O acaso vienes a reclamar el honor de la duquesa Pamay?$B$BEn realidad, no me interesan tus motivos. Así que si estás aquí para pelear, acabemos cuanto antes...', 0),
(@ID, 'esMX', 'Genial, me has encontrado. Bien por ti.$B$B¿Vienes por el hacha que le hice a Gath\'Ilzogg? ¿O acaso vienes a reclamar el honor de la duquesa Pamay?$B$BEn realidad, no me interesan tus motivos. Así que si estás aquí para pelear, acabemos cuanto antes...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Fizzle? ¡Eso lo cambia todo! Pues claro que te voy a ayudar. ¡Fizzle y su hermano son de los pocos a los que no les gustaría verme muerto!$B$BAsí que Fizzle quiere unos pistones, ¿verdad? ¿Unos que aguanten bastante presión? Conociendo a Fizzle, ¡seguro que su nuevo coche será un volcán con ruedas!', 0),
(@ID, 'esMX', '¿Te envía Fizzle? ¡Eso lo cambia todo! Pues claro que te voy a ayudar. ¡Fizzle y su hermano son de los pocos a los que no les gustaría verme muerto!$B$BAsí que Fizzle quiere unos pistones, ¿verdad? ¿Unos que aguanten bastante presión? Conociendo a Fizzle, ¡seguro que su nuevo coche será un volcán con ruedas!', 0);
-- 1111 Maestro de muelles Vertipeluca
-- https://es.classic.wowhead.com/quest=1111
SET @ID := 1111;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Habla! Dime... ¿vienes a entregar o a recoger mercancía?', 0),
(@ID, 'esMX', '¡Habla! Dime... ¿vienes a entregar o a recoger mercancía?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Las piezas para Kravel... Me alegro de que hayas venido. Llevan días aquí y tenía miedo de que se oxidaran.', 0),
(@ID, 'esMX', 'Ah, sí. Las piezas para Kravel... Me alegro de que hayas venido. Llevan días aquí y tenía miedo de que se oxidaran.', 0);
-- 5762 Hemet Nesingwary Jr.
-- https://es.classic.wowhead.com/quest=5762
SET @ID := 5762;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo que tienes en el cuello es polvo del desierto...?$B$BMmm... si mi olfato no me engaña, no se trata de polvo... ¡sino de sal! Has estado en El Desierto de Sal, ¿no es así?', 0),
(@ID, 'esMX', '¿Lo que tienes en el cuello es polvo del desierto...?$B$BMmm... si mi olfato no me engaña, no se trata de polvo... ¡sino de sal! Has estado en El Desierto de Sal, ¿no es así?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, Karbarbán me ha enviado mi paquete! Gracias, $n. Contiene munición de un calibre especial que nos vendrá de perlas en la jungla.$B$BAquí tienes tu recompensa y... dime, ¿qué es del viejo Kravel? Apuesto a que no anda metido en nada bueno...', 0),
(@ID, 'esMX', '¡Estupendo, Karbarbán me ha enviado mi paquete! Gracias, $n. Contiene munición de un calibre especial que nos vendrá de perlas en la jungla.$B$BAquí tienes tu recompensa y... dime, ¿qué es del viejo Kravel? Apuesto a que no anda metido en nada bueno...', 0);
-- 2770 Gahz'rilla
-- https://es.classic.wowhead.com/quest=2770
SET @ID := 2770;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la escama? ¡Estoy deseando averiguar cómo aprovechar su energía!', 0),
(@ID, 'esMX', '¿Tienes la escama? ¡Estoy deseando averiguar cómo aprovechar su energía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, has conseguido la escama! Gracias, $n. ¡Estoy deseando ponerme manos a la obra con ella!$B$BAsí que has visto a Gahz\'rilla... ¿¿Es tan grande como dicen??', 0),
(@ID, 'esMX', '¡Vaya, has conseguido la escama! Gracias, $n. ¡Estoy deseando ponerme manos a la obra con ella!$B$BAsí que has visto a Gahz\'rilla... ¿¿Es tan grande como dicen??', 0);
-- 1107 Aletas dorsales taraceadas
-- https://es.classic.wowhead.com/quest=1107
SET @ID := 1107;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las aletas dorsales? Si no puedo proteger nuestro coche de la velocidad, no duraremos mucho en las carreras.', 0),
(@ID, 'esMX', '¿Tienes las aletas dorsales? Si no puedo proteger nuestro coche de la velocidad, no duraremos mucho en las carreras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! Cuando las haya molido y mezclado con una serie de ingredientes, el compuesto estará listo. Y cuando así sea, ¡el coche no sufrirá ningún daño vaya a la velocidad que vaya!$B$BEso sí, siempre que no choque con nada...', 0),
(@ID, 'esMX', '¡Gracias, $n! Cuando las haya molido y mezclado con una serie de ingredientes, el compuesto estará listo. Y cuando así sea, ¡el coche no sufrirá ningún daño vaya a la velocidad que vaya!$B$BEso sí, siempre que no choque con nada...', 0);
-- 865 Los cuernos de raptor
-- https://es.classic.wowhead.com/quest=865
SET @ID := 865;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los cuernos, $n? ¡Ganaré una fortuna con ellos!', 0),
(@ID, 'esMX', '¿Has conseguido los cuernos, $n? ¡Ganaré una fortuna con ellos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, los tienes! Ahora solo necesito molerlos, mezclarlos con algo de vino y...', 0),
(@ID, 'esMX', '¡Genial, los tienes! Ahora solo necesito molerlos, mezclarlos con algo de vino y...', 0);

-- 1069 Huevos de arañas Musgondo
-- https://es.classic.wowhead.com/quest=1069
SET @ID := 1069;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los huevos, $n? ¡Ya he cerrado un trato de flete con el maestro de los muelles Vertipeluca!', 0),
(@ID, 'esMX', '¿Has conseguido los huevos, $n? ¡Ya he cerrado un trato de flete con el maestro de los muelles Vertipeluca!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los tienes! ¡Gracias!$B$BLos mandaré a Vertipeluca para que los envíen a Bahía del Botín. ¡Ya puedo disfrutar de la ganancia!$B$BAquí tienes tu parte, $n. No habría conseguido este trato sin ti.', 0),
(@ID, 'esMX', '¡Los tienes! ¡Gracias!$B$BLos mandaré a Vertipeluca para que los envíen a Bahía del Botín. ¡Ya puedo disfrutar de la ganancia!$B$BAquí tienes tu parte, $n. No habría conseguido este trato sin ti.', 0);
-- 1221 Los tubérculos hojazul
-- https://es.classic.wowhead.com/quest=1221
SET @ID := 1221;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los tubérculos, $n?', 0),
(@ID, 'esMX', '¿Traes los tubérculos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, me pagarán un buen precio por ellos!$B$BGracias, $n, eres genial.', 0),
(@ID, 'esMX', '¡Estupendo, me pagarán un buen precio por ellos!$B$BGracias, $n, eres genial.', 0);
-- 895 SE BUSCA: Capitán Garvey
-- https://es.classic.wowhead.com/quest=895
SET @ID := 895;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué ocurre? ¿Puedo ayudarte en algo? Mercancías que despachar, ¿acaso un trabajo de ingeniería?', 0),
(@ID, 'esMX', '¿Qué ocurre? ¿Puedo ayudarte en algo? Mercancías que despachar, ¿acaso un trabajo de ingeniería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Esa clase de negocio. ¿Sabes?, una vez vi El Temerario en mar abierto. Un barco imponente, o era el barco... ¡esos marineros son tan especiales!$B$BEn cualquier caso, ver ese buque deslizarse por el agua era un espectáculo. Me alegro que su miserable capitán ya no vuelva a causarme problemas.', 0),
(@ID, 'esMX', '¡Ah! Esa clase de negocio. ¿Sabes?, una vez vi El Temerario en mar abierto. Un barco imponente, o era el barco... ¡esos marineros son tan especiales!$B$BEn cualquier caso, ver ese buque deslizarse por el agua era un espectáculo. Me alegro que su miserable capitán ya no vuelva a causarme problemas.', 0);
-- 1483 Ziz Fizziks
-- https://es.classic.wowhead.com/quest=1483
SET @ID := 1483;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creía que los ejecutivos de Ventura y Cía. eran unos negreros pero entonces conocí a Petardol, ¡el más cruel de todos!$B$B¡Ja! Aunque supongo que es mejor que estar sin trabajo... O algo peor, trabajar con el tal Gerenzo. Si estás aquí para ayudar, tengo algo de lo que podrías encargarte.', 0),
(@ID, 'esMX', 'Creía que los ejecutivos de Ventura y Cía. eran unos negreros pero entonces conocí a Petardol, ¡el más cruel de todos!$B$B¡Ja! Aunque supongo que es mejor que estar sin trabajo... O algo peor, trabajar con el tal Gerenzo. Si estás aquí para ayudar, tengo algo de lo que podrías encargarte.', 0);
-- 894 El churumbele
-- https://es.classic.wowhead.com/quest=894
SET @ID := 894;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Varios botones, palancas y lucecitas parpadeantes se encuentran de forma algo desordenada en el frontal de la consola de control. Un pequeño indicador sirve para ver si el aparato funciona dentro de los niveles óptimos y que las tres primeras válvulas de control están abiertas. Hay una pequeña cerradura en la parte inferior derecha del panel de control.', 0),
(@ID, 'esMX', 'Varios botones, palancas y lucecitas parpadeantes se encuentran de forma algo desordenada en el frontal de la consola de control. Un pequeño indicador sirve para ver si el aparato funciona dentro de los niveles óptimos y que las tres primeras válvulas de control están abiertas. Hay una pequeña cerradura en la parte inferior derecha del panel de control.', 0);
-- 959 ¡A por la botella!
-- https://es.classic.wowhead.com/quest=959
SET @ID := 959;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El maestro de los muelles está investigando mi caso desde que Loco Magglish se escapó con ese porto de 99 años. Apuesto que esa botella tenía que haber sido un regalo para el Barón Revilgaz en persona.$B$BSi tienes la paciencia y el valor suficientes para buscar a Loco Magglish y recuperar ese porto, me ocuparé de que tengas una buena recompensa.', 0),
(@ID, 'esMX', 'El maestro de los muelles está investigando mi caso desde que Loco Magglish se escapó con ese porto de 99 años. Apuesto que esa botella tenía que haber sido un regalo para el Barón Revilgaz en persona.$B$BSi tienes la paciencia y el valor suficientes para buscar a Loco Magglish y recuperar ese porto, me ocuparé de que tengas una buena recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! ¡Y justo cuando estaba a punto de perder mi empleo! Me ocuparé de hacer llegar este regalo a Gazlowe inmediatamente.$B$BGracias, $n. Un buen trabajo, ¡vaya!', 0),
(@ID, 'esMX', '¡Soberbio! ¡Y justo cuando estaba a punto de perder mi empleo! Me ocuparé de hacer llegar este regalo a Gazlowe inmediatamente.$B$BGracias, $n. Un buen trabajo, ¡vaya!', 0);
-- 1180 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1180
SET @ID := 1180;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un envío a Trinquete? Permite que compruebe los registros...$B$BNo, el envío más reciente que me consta en las salidas hacia Trinquete son unas botas de Drizzlik. No ha habido mucho más, aparte de suministros y herramientas de construcción. Nada de piezas para carreras.', 0),
(@ID, 'esMX', '¿Un envío a Trinquete? Permite que compruebe los registros...$B$BNo, el envío más reciente que me consta en las salidas hacia Trinquete son unas botas de Drizzlik. No ha habido mucho más, aparte de suministros y herramientas de construcción. Nada de piezas para carreras.', 0);
-- 887 Los filibusteros de los Mares del Sur
-- https://es.classic.wowhead.com/quest=887
SET @ID := 887;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni siquiera quiero pensar en las ganancias que he perdido por las incursiones piratas, ¿y ahora acamparon en mi puerta? Esto se está saliendo de madre, Tienes que hacer algo al respecto.', 0),
(@ID, 'esMX', 'Ni siquiera quiero pensar en las ganancias que he perdido por las incursiones piratas, ¿y ahora acamparon en mi puerta? Esto se está saliendo de madre, Tienes que hacer algo al respecto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has conseguido, $gchaval:chavala;. Un poco más de trabajo igual de bueno y habrá una cosa menos por lo que preocuparse. Con suerte, se convencerán de que deben operar en otro lugar.$B$BMientras tanto, ¡está el asuntillo de recuperar la mercancía que me robaron!', 0),
(@ID, 'esMX', 'Lo has conseguido, $gchaval:chavala;. Un poco más de trabajo igual de bueno y habrá una cosa menos por lo que preocuparse. Con suerte, se convencerán de que deben operar en otro lugar.$B$BMientras tanto, ¡está el asuntillo de recuperar la mercancía que me robaron!', 0);
-- 1112 Las piezas de Kravel
-- https://es.classic.wowhead.com/quest=1112
SET @ID := 1112;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste llegar a Trinquete y hacerte con las piezas?', 0),
(@ID, 'esMX', '¿Conseguiste llegar a Trinquete y hacerte con las piezas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, las tienes! Ahora hay que llevárselas a los gnomos, pero antes...$B$BVoy a elegir una de ellas para quedármela.', 0),
(@ID, 'esMX', '¡Genial, las tienes! Ahora hay que llevárselas a los gnomos, pero antes...$B$BVoy a elegir una de ellas para quedármela.', 0);
-- 896 La fortuna de un minero
-- https://es.classic.wowhead.com/quest=896
SET @ID := 896;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si al menos supiéramos qué minero encontró la esmeralda, sería un paseo...', 0),
(@ID, 'esMX', 'Si al menos supiéramos qué minero encontró la esmeralda, sería un paseo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fíjate en el tamaño de esa cosa, $n! ¡Nos vamos a hacer ricos! A ver, según los tipos que he visto en las gemas que van a Villabajo, debería poder calcular tu parte, cincuenta por ciento, ¡no te preocupes!$B$BAhora veamos... Creo que esto debería bastar. ¡Un placer hacer negocios contigo, $n!', 0),
(@ID, 'esMX', '¡Fíjate en el tamaño de esa cosa, $n! ¡Nos vamos a hacer ricos! A ver, según los tipos que he visto en las gemas que van a Villabajo, debería poder calcular tu parte, cincuenta por ciento, ¡no te preocupes!$B$BAhora veamos... Creo que esto debería bastar. ¡Un placer hacer negocios contigo, $n!', 0);
-- 1491 Bebidas de inteligencia
-- https://es.classic.wowhead.com/quest=1491
SET @ID := 1491;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está mi esencia de lamentos?', 0),
(@ID, 'esMX', '¿Dónde está mi esencia de lamentos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, la tienes! Me muero por probarla. Conseguiré una fortuna con esto, ¡estoy seguro!$B$BGracias, $n. Esto es para ti, y cuando me haga rico, te enviaré más, ¡prometido!', 0),
(@ID, 'esMX', '¡Genial, la tienes! Me muero por probarla. Conseguiré una fortuna con esto, ¡estoy seguro!$B$BGracias, $n. Esto es para ti, y cuando me haga rico, te enviaré más, ¡prometido!', 0);
-- 890 El envío perdido
-- https://es.classic.wowhead.com/quest=890
SET @ID := 890;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mercancías para enviar en el siguiente barco, $n?', 0),
(@ID, 'esMX', '¿Mercancías para enviar en el siguiente barco, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Gazlowe te envía, ¿no? Solo un momento, déjame echar un vistazo para comprobar mis registros y asegurarme de que ningún envío de Gazlowe ha sido despachado al lugar equivocado.$B$BApuesto que espera esas botas de Drizzlek...', 0),
(@ID, 'esMX', 'Ah, Gazlowe te envía, ¿no? Solo un momento, déjame echar un vistazo para comprobar mis registros y asegurarme de que ningún envío de Gazlowe ha sido despachado al lugar equivocado.$B$BApuesto que espera esas botas de Drizzlek...', 0);
-- 892 El envío perdido
-- https://es.classic.wowhead.com/quest=892
SET @ID := 892;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿qué te dijo Vertipeluca?', 0),
(@ID, 'esMX', 'Bueno, ¿qué te dijo Vertipeluca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sin dados? Entonces supongo que fue cosa de los filibusteros... Vertipeluca es limpio, estoy seguro de que no me haría trampa. Después de todo, está en nómina.$B$BParece que tengo que devolver algo de mercancía, $n. ¿Qué me dices?', 0),
(@ID, 'esMX', '¿Sin dados? Entonces supongo que fue cosa de los filibusteros... Vertipeluca es limpio, estoy seguro de que no me haría trampa. Después de todo, está en nómina.$B$BParece que tengo que devolver algo de mercancía, $n. ¿Qué me dices?', 0);
-- 888 El botín robado
-- https://es.classic.wowhead.com/quest=888
SET @ID := 888;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mis cosas, $n?', 0),
(@ID, 'esMX', '¿Has encontrado mis cosas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un alivio recuperar todo esto, gracias por tu ayuda, $n. ¿Sabes?, no me vendría mal $gun:una; $r como tú para ayudarme aquí. Si cualquier día buscas trabajo, ¡recuerda lo bien que paga Gazlowe!', 0),
(@ID, 'esMX', 'Es un alivio recuperar todo esto, gracias por tu ayuda, $n. ¿Sabes?, no me vendría mal $gun:una; $r como tú para ayudarme aquí. Si cualquier día buscas trabajo, ¡recuerda lo bien que paga Gazlowe!', 0);
-- 522 Contrato de asesino
-- https://es.classic.wowhead.com/quest=522
SET @ID := 522;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, qué prisa traes! ¿Tienes noticias?', 0),
(@ID, 'esMX', '¡Vaya, qué prisa traes! ¿Tienes noticias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maleb estudia el contrato.>$B$BEsto explica el ataque a Costasur; la Hermandad quiere liquidarme como hicieron con mi predecesor.', 0),
(@ID, 'esMX', '<Maleb estudia el contrato.>$B$BEsto explica el ataque a Costasur; la Hermandad quiere liquidarme como hicieron con mi predecesor.', 0);
-- 523 Muerte al Barón
-- https://es.classic.wowhead.com/quest=523
SET @ID := 523;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barón Vardus no puede pensar que Costasur le permitirá enviar a sus matones contra nosotros con impunidad. ¡Quiero su cabeza!', 0),
(@ID, 'esMX', 'El barón Vardus no puede pensar que Costasur le permitirá enviar a sus matones contra nosotros con impunidad. ¡Quiero su cabeza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Mi cabeza descansa un poco más tranquila, sabiendo que ese villano perdió la suya.', 0),
(@ID, 'esMX', 'Gracias, $n. Mi cabeza descansa un poco más tranquila, sabiendo que ese villano perdió la suya.', 0);
-- 1108 Indurio
-- https://es.classic.wowhead.com/quest=1108
SET @ID := 1108;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste alguna lámina de indurio, $n? Tengo la forja preparada para recibirlas.', 0),
(@ID, 'esMX', '¿Encontraste alguna lámina de indurio, $n? Tengo la forja preparada para recibirlas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, estas son perfectas. Apliquémosles un poco de calor y veamos qué pasa...', 0),
(@ID, 'esMX', 'Bien, estas son perfectas. Apliquémosles un poco de calor y veamos qué pasa...', 0);
-- 2418 Las piedras de energía
-- https://es.classic.wowhead.com/quest=2418
SET @ID := 2418;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las piedras de energía, $n? Uno de mis roedores robóticos necesita una fuente de alimentación...', 0),
(@ID, 'esMX', '¿Tienes las piedras de energía, $n? Uno de mis roedores robóticos necesita una fuente de alimentación...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, encontraste algunas! Mil gracias, $n. ¡Eres $gel:la; $r más formal que he conocido!$B$BMe muero por probarlas en unos dispositivos que he fabricado. Apuesto que, en las circunstancias apropiadas, los dispositivos impulsados con estas piedras funcionarán, y funcionarán y funcionarán...', 0),
(@ID, 'esMX', '¡Fantástico, encontraste algunas! Mil gracias, $n. ¡Eres $gel:la; $r más formal que he conocido!$B$BMe muero por probarlas en unos dispositivos que he fabricado. Apuesto que, en las circunstancias apropiadas, los dispositivos impulsados con estas piedras funcionarán, y funcionarán y funcionarán...', 0);
-- 703 Alas de águila ratonera a la parrilla
-- https://es.classic.wowhead.com/quest=703
SET @ID := 703;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Me has traído mis alas?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Me has traído mis alas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, empezaré con esas alas enseguida. ¡Ya casi puedo saborearlas!$B$B¡Aquí tienes la receta en caso de que las quieras preparar tú $gmismo:misma;!', 0),
(@ID, 'esMX', 'Ah, empezaré con esas alas enseguida. ¡Ya casi puedo saborearlas!$B$B¡Aquí tienes la receta en caso de que las quieras preparar tú $gmismo:misma;!', 0);
-- 705 La pesca de perlas
-- https://es.classic.wowhead.com/quest=705
SET @ID := 705;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido mis perlas? ¡Casi no me quedan bombas centelleantes!', 0),
(@ID, 'esMX', '¿Has conseguido mis perlas? ¡Casi no me quedan bombas centelleantes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vendrán de maravilla! Solo necesito molerlas en polvo... luego mezclarlas con una pizca de esto y otra pizca de aquello.$B$B¡Prepárense, carroñeros! ¡Prepárense para ser fulminados!', 0),
(@ID, 'esMX', '¡Vendrán de maravilla! Solo necesito molerlas en polvo... luego mezclarlas con una pizca de esto y otra pizca de aquello.$B$B¡Prepárense, carroñeros! ¡Prepárense para ser fulminados!', 0);

-- 709 La solución a la maldición
-- https://es.classic.wowhead.com/quest=709
SET @ID := 709;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la tablilla? ¡Debe de contener secretos! ¡Secretos para salvarnos!', 0),
(@ID, 'esMX', '¿Has encontrado la tablilla? ¡Debe de contener secretos! ¡Secretos para salvarnos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, la suerte está de nuestra parte! ¡Gracias! ¡Puede que aún nos salvemos!', 0),
(@ID, 'esMX', '¡Oh, la suerte está de nuestra parte! ¡Gracias! ¡Puede que aún nos salvemos!', 0);
-- 1137 Noticias para Fizzle
-- https://es.classic.wowhead.com/quest=1137
SET @ID := 1137;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡has vuelto! ¿Encontraste a Martek? ¿Hablaste con él? ¿Y qué dijo? ¿¿Puede ayudarme??$B$B¡Cuéntamelo todo!', 0),
(@ID, 'esMX', '$n, ¡has vuelto! ¿Encontraste a Martek? ¿Hablaste con él? ¿Y qué dijo? ¿¿Puede ayudarme??$B$B¡Cuéntamelo todo!', 0);
-- 727 Ir a Forjaz a buscar el "Compendio" de Yagyin
-- https://es.classic.wowhead.com/quest=727
SET @ID := 727;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. Bienvenido a mi tienda pero ojo con lo que tocas.$B$BEl conocimiento puede ser mortal.', 0),
(@ID, 'esMX', 'Hola. Bienvenido a mi tienda pero ojo con lo que tocas.$B$BEl conocimiento puede ser mortal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh. Saludos, hermano.$B$BY alabados sean los moradores del subsuelo.', 0),
(@ID, 'esMX', 'Oh. Saludos, hermano.$B$BY alabados sean los moradores del subsuelo.', 0);
-- 720 Un signo de esperanza
-- https://es.classic.wowhead.com/quest=720
SET @ID := 720;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Piemartillo está vivo?! ¡Increíble, $n!', 0),
(@ID, 'esMX', '¡¿Piemartillo está vivo?! ¡Increíble, $n!', 0);
-- 721 Un signo de esperanza
-- https://es.classic.wowhead.com/quest=721
SET @ID := 721;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Lo siento... <tose> Estoy muy débil. ¿Puedes acercarte, $c?$B$B¿Así que t’envía Ryedol? Que los hados bendigan a Muradin, ese chico no es tan lento del tarro como pensaba.', 0),
(@ID, 'esMX', '¿Sí? Lo siento... <tose> Estoy muy débil. ¿Puedes acercarte, $c?$B$B¿Así que t’envía Ryedol? Que los hados bendigan a Muradin, ese chico no es tan lento del tarro como pensaba.', 0);
-- 719 Un enano y sus herramientas
-- https://es.classic.wowhead.com/quest=719
SET @ID := 719;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía no sé con seguridad qué buscaban los Forjatiniebla pero desde luego tenían un propósito.', 0),
(@ID, 'esMX', 'Todavía no sé con seguridad qué buscaban los Forjatiniebla pero desde luego tenían un propósito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres mi salvador, $c. Me alegro de que alguien le haya dado una lección a esos Forjatiniebla. Gracias por tu ayuda.', 0),
(@ID, 'esMX', 'Eres mi salvador, $c. Me alegro de que alguien le haya dado una lección a esos Forjatiniebla. Gracias por tu ayuda.', 0);
-- 718 Espejismos
-- https://es.classic.wowhead.com/quest=718
SET @ID := 718;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El desierto es mal lugar para tener hambre, amigo, te lo digo yo.$B$BEh... ¿qué es eso de ahí?...', 0),
(@ID, 'esMX', 'El desierto es mal lugar para tener hambre, amigo, te lo digo yo.$B$BEh... ¿qué es eso de ahí?...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Mientras no estabas, yo... estooo... tragué un puñado de arena. Me...$B$BBah, no importa, saldremos esta noche y conseguiremos algo de comida. ¡Comeremos como reyes!', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Mientras no estabas, yo... estooo... tragué un puñado de arena. Me...$B$BBah, no importa, saldremos esta noche y conseguiremos algo de comida. ¡Comeremos como reyes!', 0);
-- 706 Encantamientos Llamarada ígnea
-- https://es.classic.wowhead.com/quest=706
SET @ID := 706;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $c?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, desde luego, ¡esto vendrá de perlas! ¡Esto hará que al atacar tus armas despidan un calor abrasador!', 0),
(@ID, 'esMX', 'Ah, desde luego, ¡esto vendrá de perlas! ¡Esto hará que al atacar tus armas despidan un calor abrasador!', 0);
-- 3789 Ayuda al archidruida Corzocelada
-- https://es.classic.wowhead.com/quest=3789
SET @ID := 3789;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que te has apresurado a venir al saber que yo dirijo el proyecto, $c.$B$BEscúchame con atención; no tengo ganas de repetir las cosas.', 0),
(@ID, 'esMX', 'Me alegra ver que te has apresurado a venir al saber que yo dirijo el proyecto, $c.$B$BEscúchame con atención; no tengo ganas de repetir las cosas.', 0);
-- 48 Dulce ámbar
-- https://es.classic.wowhead.com/quest=48
SET @ID := 48;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo! ¿Quieres otra?$B$BAllá en el Sur donde las zarzas irritan$BHay una fuente de aguas umbrías$BPura como la sagrada Hija de la Luz$BAgua sagrada de manantial me traerás tú.', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo! ¿Quieres otra?$B$BAllá en el Sur donde las zarzas irritan$BHay una fuente de aguas umbrías$BPura como la sagrada Hija de la Luz$BAgua sagrada de manantial me traerás tú.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 1181 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1181
SET @ID := 1181;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, por supuesto que sabes lo que estás diciendo. Pero no, no te puedo ayudar. Algunos de mis hombres tenían que rastrear los planos de regulador de combustible, pero volvieron con las manos vacías.', 0),
(@ID, 'esMX', 'Oh, por supuesto que sabes lo que estás diciendo. Pero no, no te puedo ayudar. Algunos de mis hombres tenían que rastrear los planos de regulador de combustible, pero volvieron con las manos vacías.', 0);
-- 1182 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1182
SET @ID := 1182;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por mucho que odie admitirlo, ese equipo gnomo que tienen ahí fuera es bastante bueno. Nuestros chicos necesitan toda la ayuda que puedan conseguir.', 0),
(@ID, 'esMX', 'Por mucho que odie admitirlo, ese equipo gnomo que tienen ahí fuera es bastante bueno. Nuestros chicos necesitan toda la ayuda que puedan conseguir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deja que haga una copia de esos planos para tenerlos en mis notas y se los puedes llevar directamente a Pozzik. No quiero que crea que uno de sus mecenas le ha abandonado.', 0),
(@ID, 'esMX', 'Deja que haga una copia de esos planos para tenerlos en mis notas y se los puedes llevar directamente a Pozzik. No quiero que crea que uno de sus mecenas le ha abandonado.', 0);
-- 1183 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1183
SET @ID := 1183;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Has conseguido encontrar el regulador de combustible?', 0),
(@ID, 'esMX', '¡$n! ¿Has conseguido encontrar el regulador de combustible?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperaba que ya estuviera listo, pero esto presenta la oportunidad perfecta de mejorar el diseño original. Gracias, $n. Creo que podré preparar unos esquemas mejorados , construir esta cosa e instalarla rápidamente.', 0),
(@ID, 'esMX', 'Esperaba que ya estuviera listo, pero esto presenta la oportunidad perfecta de mejorar el diseño original. Gracias, $n. Creo que podré preparar unos esquemas mejorados , construir esta cosa e instalarla rápidamente.', 0);
-- 2198 El collar hecho añicos
-- https://es.classic.wowhead.com/quest=2198
SET @ID := 2198;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te has equivocado de gnomo, amigo! ¡Yo nunca he estado allí! ¡No puedes probar nada!$B$BEspera un momento... ¿quién eres? ¿Pero qué...? ¿Dónde encontraste este collar?', 0),
(@ID, 'esMX', '¡Te has equivocado de gnomo, amigo! ¡Yo nunca he estado allí! ¡No puedes probar nada!$B$BEspera un momento... ¿quién eres? ¿Pero qué...? ¿Dónde encontraste este collar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... Yo soy el joyero que ha hecho el collar pero no soy de los que dan información a cambio de nada. La información se paga, amigo. Si quieres que te ayuda, primero has de ayudarme tú a MÍ.', 0),
(@ID, 'esMX', 'Sí... Yo soy el joyero que ha hecho el collar pero no soy de los que dan información a cambio de nada. La información se paga, amigo. Si quieres que te ayuda, primero has de ayudarme tú a MÍ.', 0);
-- 722 El amuleto de los secretos
-- https://es.classic.wowhead.com/quest=722
SET @ID := 722;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El clan Forjatiniebla... <tose> es peligroso. Ten cuidado. <tose> Debes encontrar el amuleto.', 0),
(@ID, 'esMX', 'El clan Forjatiniebla... <tose> es peligroso. Ten cuidado. <tose> Debes encontrar el amuleto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Decir ah! <tose tose>$B$BSabía que me encontrarías el amuleto, $n.$B$BMuy bien hecho, $n. <tose>', 0),
(@ID, 'esMX', '¡Decir ah! <tose tose>$B$BSabía que me encontrarías el amuleto, $n.$B$BMuy bien hecho, $n. <tose>', 0);
-- 723 Tener fe en el porvenir
-- https://es.classic.wowhead.com/quest=723
SET @ID := 723;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Diría que ha sido un mal día pero estamos en las Tierras Inhóspitas: cualquier día es malo.', 0),
(@ID, 'esMX', 'Diría que ha sido un mal día pero estamos en las Tierras Inhóspitas: cualquier día es malo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El amuleto de Piemartillo? Creo que me encontraba más animado cuando creía que estaba muerto. Saberlo con seguridad solo aumenta el dolor. Este amuleto era el trabajo de su vida. No permitiré que haya muerto en vano.', 0),
(@ID, 'esMX', '¿El amuleto de Piemartillo? Creo que me encontraba más animado cuando creía que estaba muerto. Saberlo con seguridad solo aumenta el dolor. Este amuleto era el trabajo de su vida. No permitiré que haya muerto en vano.', 0);
-- 735 La Estrella, la Mano y el Corazón
-- https://es.classic.wowhead.com/quest=735
SET @ID := 735;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los objetos que te pedí?', 0),
(@ID, 'esMX', '¿Traes los objetos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes muchos recursos, $c. Si eres tú quien debe encargarse de la continuidad de nuestra orden, no dudo en que lo harás magníficamente.', 0),
(@ID, 'esMX', 'Tienes muchos recursos, $c. Si eres tú quien debe encargarse de la continuidad de nuestra orden, no dudo en que lo harás magníficamente.', 0);
-- 737 El saber prohibido
-- https://es.classic.wowhead.com/quest=737
SET @ID := 737;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! Hace mucho que te habías marchado. ¿Has conseguido la revista?', 0),
(@ID, 'esMX', '¡Ja! Hace mucho que te habías marchado. ¿Has conseguido la revista?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La tienes! ¡Oh, rayo de esperanza!$B$BPuede que tus esfuerzos sean nuestra salvación, $n. ¡Un monumento habrían de erigirte! ¡Un altar a ti dedicado! ¡Alabado sea tu nombre hasta que tus nietos tengan nietos!$B$BA menos que...ELLOS se liberen y vuelvan a la superficie. Si eso ocurriera, entonces puedes olvidarte de los hijos.$B$BSi ELLOS quedan libres, todos seremos alimento de gusanos.', 0),
(@ID, 'esMX', '¡La tienes! ¡Oh, rayo de esperanza!$B$BPuede que tus esfuerzos sean nuestra salvación, $n. ¡Un monumento habrían de erigirte! ¡Un altar a ti dedicado! ¡Alabado sea tu nombre hasta que tus nietos tengan nietos!$B$BA menos que...ELLOS se liberen y vuelvan a la superficie. Si eso ocurriera, entonces puedes olvidarte de los hijos.$B$BSi ELLOS quedan libres, todos seremos alimento de gusanos.', 0);
-- 971 El conocimiento de las profundidades
-- https://es.classic.wowhead.com/quest=971
SET @ID := 971;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El viaje a Vallefresno es largo y tu misión no es fácil. Pero $n, si me traes el manuscrito, te llevarás una buena recompensa.', 0),
(@ID, 'esMX', 'El viaje a Vallefresno es largo y tu misión no es fácil. Pero $n, si me traes el manuscrito, te llevarás una buena recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El manuscrito! ¡Qué alegría! ¡Por fin podremos divulgar los conocimientos antiguos de Lorgalis!$B$BNo puedo expresar mi agradecimiento, $n. Espero que este regalo sea buena prueba de mi gratitud.', 0),
(@ID, 'esMX', '¡El manuscrito! ¡Qué alegría! ¡Por fin podremos divulgar los conocimientos antiguos de Lorgalis!$B$BNo puedo expresar mi agradecimiento, $n. Espero que este regalo sea buena prueba de mi gratitud.', 0);
-- 724 Tener fe en el porvenir
-- https://es.classic.wowhead.com/quest=724
SET @ID := 724;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Otro viajero que quiere algo de los enanos.$B$B$gSeñor:Señora;, realmente lo siento, pero no tengo tiempo para responder preguntas sin sentido en este momento.', 0),
(@ID, 'esMX', 'Ah, sí. Otro viajero que quiere algo de los enanos.$B$B$gSeñor:Señora;, realmente lo siento, pero no tengo tiempo para responder preguntas sin sentido en este momento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh! Bueno, este es un asunto completamente diferente. Probablemente aún no te hayas dado cuenta de la gravedad de este asunto, ¿verdad?$B$BMe importa mucho la desaparición de Piemartillo, pero si te envió aquí con su amuleto, entonces entendió lo que está en juego.$B$BTendremos que tomarnos un tiempo para lamentar su muerte más tarde.$B$BDéjame mostrarte una de las razones por las que este amuleto es tan valioso.', 0),
(@ID, 'esMX', 'Oh! Bueno, este es un asunto completamente diferente. Probablemente aún no te hayas dado cuenta de la gravedad de este asunto, ¿verdad?$B$BMe importa mucho la desaparición de Piemartillo, pero si te envió aquí con su amuleto, entonces entendió lo que está en juego.$B$BTendremos que tomarnos un tiempo para lamentar su muerte más tarde.$B$BDéjame mostrarte una de las razones por las que este amuleto es tan valioso.', 0);
-- 733 ¡A gorronear!
-- https://es.classic.wowhead.com/quest=733
SET @ID := 733;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, me he apañado con lo que había pero... no es mucho. ¿Has encontrado más suministros?', 0),
(@ID, 'esMX', 'Bueno, me he apañado con lo que había pero... no es mucho. ¿Has encontrado más suministros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un comienzo, $n, y tendrá que servir hasta que sepamos algo de Forjaz o de la Liga de Exploradores.$B$BBien, y si ahora pudiera conseguir sal en algún lado para mi barril de bebida...', 0),
(@ID, 'esMX', 'Es un comienzo, $n, y tendrá que servir hasta que sepamos algo de Forjaz o de la Liga de Exploradores.$B$BBien, y si ahora pudiera conseguir sal en algún lado para mi barril de bebida...', 0);



--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;

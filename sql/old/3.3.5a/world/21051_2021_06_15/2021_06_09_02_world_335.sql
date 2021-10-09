-- 10077 Polvo de cristal de Oshu'gun
-- https://es.wowhead.com/quest=10077
SET @ID := 10077;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta base fue la principal instalación de investigación draenei para el estudio de los cristales de naaru.$B$BLo que hemos descubierto es una verdadera mina de oro de notas de investigación sobre los cristales de la montaña de "diamantes", Oshu\'gun. Parecería que todo en esta región lleva consigo algún polvo residual de los cristales de Oshu\'gun. Si encuentras polvo de cristal mientras te aventuras en esta región, devuélvemela y te recompensaré con una muestra de mi agradecimiento que puedes usar para hacer compras al intendente.', 0),
(@ID, 'esMX', 'Esta base fue la principal instalación de investigación draenei para el estudio de los cristales de naaru.$B$BLo que hemos descubierto es una verdadera mina de oro de notas de investigación sobre los cristales de la montaña de "diamantes", Oshu\'gun. Parecería que todo en esta región lleva consigo algún polvo residual de los cristales de Oshu\'gun. Si encuentras polvo de cristal mientras te aventuras en esta región, devuélvemela y te recompensaré con una muestra de mi agradecimiento que puedes usar para hacer compras al intendente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu contribución, $n. Si encuentra más, ¡ya sabes dónde llevarlos!', 0),
(@ID, 'esMX', 'Gracias por tu contribución, $n. Si encuentra más, ¡ya sabes dónde llevarlos!', 0);
-- 10078 Machacando al enemigo
-- https://es.wowhead.com/quest=10078
SET @ID := 10078;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lanzacuchillos del este quemado', `ObjectiveText2` = 'Lanzacuchillos del este central quemado', `ObjectiveText3` = 'Lanzacuchillos del oeste central quemado', `ObjectiveText4` = 'Lanzacuchillos del oeste quemado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces estar de buen humor. ¿La maquinaria de asedio de la Horda en llamas ha vuelto a poner el ánimo en tu paso?', 0),
(@ID, 'esMX', 'Pareces estar de buen humor. ¿La maquinaria de asedio de la Horda en llamas ha vuelto a poner el ánimo en tu paso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así me gusta!$B$BMe alegro de que hayan llegado refuerzos, pero su actitud hacia la Horda no me alegra tanto. ¡En mi tierra, cualquiera que te apunta con un arma es un enemigo y tiene que ser tratado como tal!', 0),
(@ID, 'esMX', '¡Así me gusta!$B$BMe alegro de que hayan llegado refuerzos, pero su actitud hacia la Horda no me alegra tanto. ¡En mi tierra, cualquiera que te apunta con un arma es un enemigo y tiene que ser tratado como tal!', 0);
-- 10079 Esta mina es un caos
-- https://es.wowhead.com/quest=10079
SET @ID := 10079;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime que se acabó el temblor y mis chicos pueden volver al trabajo... ¿por favor?', 0),
(@ID, 'esMX', 'Dime que se acabó el temblor y mis chicos pueden volver al trabajo... ¿por favor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por el bronce de... la barba de Barbabronce, ¡lo has conseguido!! ¡Eres $gun héroe:una heroína;, $n!', 0),
(@ID, 'esMX', 'Por el bronce de... la barba de Barbabronce, ¡lo has conseguido!! ¡Eres $gun héroe:una heroína;, $n!', 0);
-- 10081 Conocer a la Madre Kashur
-- https://es.wowhead.com/quest=10081
SET @ID := 10081;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La poción que has bebido no tiene ningún efecto real. Solo puedes ver un espíritu si te lo permite. La poción no es más que un símbolo de tu fe y dedicación. Fue una prueba, y has aprobado...', 0),
(@ID, 'esMX', 'La poción que has bebido no tiene ningún efecto real. Solo puedes ver un espíritu si te lo permite. La poción no es más que un símbolo de tu fe y dedicación. Fue una prueba, y has aprobado...', 0);
-- 10082 Los ancestros agitados
-- https://es.wowhead.com/quest=10082
SET @ID := 10082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No necesitas una poción para ver espíritus, $n.', 0),
(@ID, 'esMX', 'No necesitas una poción para ver espíritus, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sirve de nada. Siguen levantándose. Debe de estar ocurriendo algo terrible.', 0),
(@ID, 'esMX', 'No sirve de nada. Siguen levantándose. Debe de estar ocurriendo algo terrible.', 0);
-- 10085 Una visita a los ancestros
-- https://es.wowhead.com/quest=10085
SET @ID := 10085;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Visita el Puesto Primasol', `ObjectiveText2` = 'Visita las Ruinas Riecráneos', `ObjectiveText3` = 'Visita Garadar', `ObjectiveText4` = 'Visita las Ruinas Foso Sangrante', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muévete como el viento, $n.', 0),
(@ID, 'esMX', 'Muévete como el viento, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy preocupante. ¿Dices que ninguno de los ancestros estaban en sus aldeas? ¿Que todos se dirigían al sur?', 0),
(@ID, 'esMX', 'Esto es muy preocupante. ¿Dices que ninguno de los ancestros estaban en sus aldeas? ¿Que todos se dirigían al sur?', 0);
-- 10086 Trabajo... ¡para la Horda!
-- https://es.wowhead.com/quest=10086
SET @ID := 10086;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo ha ido la misión de rescate? ¿Has encontrado algo útil?', 0),
(@ID, 'esMX', '¿Cómo ha ido la misión de rescate? ¿Has encontrado algo útil?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es genial! Un poco retorcido y oxidado, pero los materiales de baja calidad nunca han evitado que hiciera explosivos de alta precisión.$B$BGracias, $n. ¡La verdad es que tienes buen ojo para la basura de calidad!', 0),
(@ID, 'esMX', '¡Esto es genial! Un poco retorcido y oxidado, pero los materiales de baja calidad nunca han evitado que hiciera explosivos de alta precisión.$B$BGracias, $n. ¡La verdad es que tienes buen ojo para la basura de calidad!', 0);
-- 10087 Quémalo... ¡por la Horda!
-- https://es.wowhead.com/quest=10087
SET @ID := 10087;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cañón del este quemado', `ObjectiveText2` = 'Cañón del oeste quemado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He buscado signos de éxito de tu misión; gritos de orcos viles, humo...$B$B¿Qué tal llevas la misión?', 0),
(@ID, 'esMX', 'He buscado signos de éxito de tu misión; gritos de orcos viles, humo...$B$B¿Qué tal llevas la misión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso pensaba! No he podido verlo desde aquí, pero puedo hacerme una idea de cómo ha sido. ¡Espléndido!$B$BBien hecho, $n. ¡El mando de Thrallmar estará encantado con tu éxito!', 0),
(@ID, 'esMX', '¡Eso pensaba! No he podido verlo desde aquí, pero puedo hacerme una idea de cómo ha sido. ¡Espléndido!$B$BBien hecho, $n. ¡El mando de Thrallmar estará encantado con tu éxito!', 0);
-- 10088 Esta mina es un caos
-- https://es.wowhead.com/quest=10088
SET @ID := 10088;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! Ahora, supongo que no estás $gdispuesto:dispuesta; a golpear a algunos peones en la cabeza, ¿o eso costará más?', 0),
(@ID, 'esMX', '¡Por fin! Ahora, supongo que no estás $gdispuesto:dispuesta; a golpear a algunos peones en la cabeza, ¿o eso costará más?', 0);
-- 10091 Los dispositivos de almas
-- https://es.wowhead.com/quest=10091
SET @ID := 10091;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Qué puedo hacer por ti, $n?', 0),
(@ID, 'esMX', '¿Sí? ¿Qué puedo hacer por ti, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'To\'gun estuvo aquí antes dándome su informe. ¡Debería haberse quedado contigo para ayudarte!$B$BLo envié de regreso para ayudar a Grik\'tha. Creo que hacen una buena pareja.$B$BEntonces, ¿estos son los dispositivos del alma que el Consejo de la Sombra estaba usando para mejorar su poder de invocación? Me parecen peligrosos. ¿Quizás los Arúspices sepan qué hacer con ellos?$B$BPor favor, toma uno de estos como recompensa por paralizar la operación del Consejo de la Sombra en el laberinto.', 0),
(@ID, 'esMX', 'To\'gun estuvo aquí antes dándome su informe. ¡Debería haberse quedado contigo para ayudarte!$B$BLo envié de regreso para ayudar a Grik\'tha. Creo que hacen una buena pareja.$B$BEntonces, ¿estos son los dispositivos del alma que el Consejo de la Sombra estaba usando para mejorar su poder de invocación? Me parecen peligrosos. ¿Quizás los Arúspices sepan qué hacer con ellos?$B$BPor favor, toma uno de estos como recompensa por paralizar la operación del Consejo de la Sombra en el laberinto.', 0);
-- 10093 El Templo de Telhamat
-- https://es.wowhead.com/quest=10093
SET @ID := 10093;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, así que has conocido al arúspice Kryv. Es un hombre sabio y de gran talento, y cualquier $r que él considere un amigo también lo será mío.$B$BPonte $gcómodo:comoda; y preséntate a los demás que llaman a este templo su hogar.', 0),
(@ID, 'esMX', 'Ah, así que has conocido al arúspice Kryv. Es un hombre sabio y de gran talento, y cualquier $r que él considere un amigo también lo será mío.$B$BPonte $gcómodo:comoda; y preséntate a los demás que llaman a este templo su hogar.', 0);
-- 10094 El Códice de Sangre
-- https://es.wowhead.com/quest=10094
SET @ID := 10094;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al abrir el tomo suspendido mágicamente, te abruma una sensación de pavor.$B$B¡Algo está definitivamente mal aquí!$B$BSigues leyendo, ¡pero lo que lees parece increíble!', 0),
(@ID, 'esMX', 'Al abrir el tomo suspendido mágicamente, te abruma una sensación de pavor.$B$B¡Algo está definitivamente mal aquí!$B$BSigues leyendo, ¡pero lo que lees parece increíble!', 0);
-- 10095 En el corazón del laberinto
-- https://es.wowhead.com/quest=10095
SET @ID := 10095;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿traes noticias del Laberinto de las Sombras? ¿Se ha resuelto el peligro allí?', 0),
(@ID, 'esMX', '$n, ¿traes noticias del Laberinto de las Sombras? ¿Se ha resuelto el peligro allí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Murmullo casi se liberó ?! Han tenido esa cosa contenida allí durante dos años... Me pregunto qué hicieron mal para perder el control después de todo este tiempo.$B$B$n, ¡al derrotar a esa bestia probablemente nos hayas salvado a todos! Me estremezco al pensar qué nos hubiera pasado a todos nosotros, y al resto de Terrallende, si esa cosa hubiera logrado liberarse de alguna manera.$B$BMe alegro de que nos hayas ayudado a tomar el asunto en nuestras propias manos y lidiar con la amenaza del Consejo de la Sombra en Auchindoun. ¿Cómo podremos recompensarte?', 0),
(@ID, 'esMX', '¡¿Murmullo casi se liberó ?! Han tenido esa cosa contenida allí durante dos años... Me pregunto qué hicieron mal para perder el control después de todo este tiempo.$B$B$n, ¡al derrotar a esa bestia probablemente nos hayas salvado a todos! Me estremezco al pensar qué nos hubiera pasado a todos nosotros, y al resto de Terrallende, si esa cosa hubiera logrado liberarse de alguna manera.$B$BMe alegro de que nos hayas ayudado a tomar el asunto en nuestras propias manos y lidiar con la amenaza del Consejo de la Sombra en Auchindoun. ¿Cómo podremos recompensarte?', 0);
-- 10096 Salvemos a los esporotes
-- https://es.wowhead.com/quest=10096
SET @ID := 10096;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Regresaste tan pronto? ¿Como te fue?', 0),
(@ID, 'esMX', '¿Qué? ¿Regresaste tan pronto? ¿Como te fue?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien! ¡Esas bestias de las marismas no tienen derecho a invadir el hogar de los esporotes!$B$BSería mejor vivir en armonía con estas criaturas, pero si no es posible, entonces nos ocuparemos del asunto.$B$BTen, acepta esto como muestra de agradecimiento.', 0),
(@ID, 'esMX', '¡Bien! ¡Esas bestias de las marismas no tienen derecho a invadir el hogar de los esporotes!$B$BSería mejor vivir en armonía con estas criaturas, pero si no es posible, entonces nos ocuparemos del asunto.$B$BTen, acepta esto como muestra de agradecimiento.', 0);
-- 10097 Hermano contra hermano
-- https://es.wowhead.com/quest=10097
SET @ID := 10097;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Libera a Lakka', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La encontraste, $n? ¿Seguía retenida en las salas?', 0),
(@ID, 'esMX', '¿La encontraste, $n? ¿Seguía retenida en las salas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo agradecerte lo suficiente, $n. Saber que Lakka es libre significa que puedo cortar el resto de mis vínculos con los Sethekk.$B$BUna parte de mí nunca me perdonará la muerte de Syth, pero tenía que hacerlo. Cuando llegue a Skettis, le realizaré los ritos de la muerte. Quizás su espíritu encuentre descanso una vez que haya expiado por haber descarriado a nuestro pueblo.', 0),
(@ID, 'esMX', 'No puedo agradecerte lo suficiente, $n. Saber que Lakka es libre significa que puedo cortar el resto de mis vínculos con los Sethekk.$B$BUna parte de mí nunca me perdonará la muerte de Syth, pero tenía que hacerlo. Cuando llegue a Skettis, le realizaré los ritos de la muerte. Quizás su espíritu encuentre descanso una vez que haya expiado por haber descarriado a nuestro pueblo.', 0);
-- 10098 El legado de Terokk
-- https://es.wowhead.com/quest=10098
SET @ID := 10098;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las reliquias de Terokk han estado ausentes de Skettis durante demasiado tiempo. ¿Pudiste recuperarlas de los Sethekk?', 0),
(@ID, 'esMX', 'Las reliquias de Terokk han estado ausentes de Skettis durante demasiado tiempo. ¿Pudiste recuperarlas de los Sethekk?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puede que nunca se me perdone realmente por mi papel en los crímenes de los Sethekk, pero quizás al devolver las reliquias de Terokk a mi pueblo, pueda comenzar a redimirme.$B$BGracias por ayudarme en esto, $n. No tienes idea de la magnitud de lo que has hecho hoy.', 0),
(@ID, 'esMX', 'Puede que nunca se me perdone realmente por mi papel en los crímenes de los Sethekk, pero quizás al devolver las reliquias de Terokk a mi pueblo, pueda comenzar a redimirme.$B$BGracias por ayudarme en esto, $n. No tienes idea de la magnitud de lo que has hecho hoy.', 0);
-- 10099 El cerebro oculto
-- https://es.wowhead.com/quest=10099
SET @ID := 10099;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Casi tengo miedo de preguntar. Verte salir $gvivo:viva; de la mina solo puede significar una cosas: o mataste al bastardo o perdiste los nervios. Bueno, ¿cuál es?', 0),
(@ID, 'esMX', 'Casi tengo miedo de preguntar. Verte salir $gvivo:viva; de la mina solo puede significar una cosas: o mataste al bastardo o perdiste los nervios. Bueno, ¿cuál es?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que te hayas encargado de... ¿Cómo dices que se llamaba a sí mismo, Z\'kral?$B$BPor lo que cuentas, el nombre le pega. En todo caso, lo importante es que está muerto.', 0),
(@ID, 'esMX', 'Me alegro de que te hayas encargado de... ¿Cómo dices que se llamaba a sí mismo, Z\'kral?$B$BPor lo que cuentas, el nombre le pega. En todo caso, lo importante es que está muerto.', 0);
-- 10100 El cerebro oculto
-- https://es.wowhead.com/quest=10100
SET @ID := 10100;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con suerte, deshacerse de su supervisor hará que las sobras entren en pánico y se rompan. Debería ser fácil de limpiar para mis hijos, una vez que haya encontrado una manera de mantenerlos despiertos.', 0),
(@ID, 'esMX', 'Con suerte, deshacerse de su supervisor hará que las sobras entren en pánico y se rompan. Debería ser fácil de limpiar para mis hijos, una vez que haya encontrado una manera de mantenerlos despiertos.', 0);
-- 10101 Cuando hablan los espíritus
-- https://es.wowhead.com/quest=10101
SET @ID := 10101;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Una suave y melodiosa voz se escucha en tu cabeza.>$B$BSoy K\'ure de los naaru, $n. Te encuentras en el corazón de mi antiguo barco.$B$BOshu\'gun, como los orcos lo llamaron, es el barco en el que vinieron los primeros draenei a este mundo. Aunque caímos del cielo y nos estrellamos aquí hace siglos, mis energías debilitadas permanecieron presas en este naufragio. Lamentablemente, soy el origen del dolor de los espíritus orcos.', 0),
(@ID, 'esMX', '<Una suave y melodiosa voz se escucha en tu cabeza.>$B$BSoy K\'ure de los naaru, $n. Te encuentras en el corazón de mi antiguo barco.$B$BOshu\'gun, como los orcos lo llamaron, es el barco en el que vinieron los primeros draenei a este mundo. Aunque caímos del cielo y nos estrellamos aquí hace siglos, mis energías debilitadas permanecieron presas en este naufragio. Lamentablemente, soy el origen del dolor de los espíritus orcos.', 0);
-- 10102 Un secreto desvelado
-- https://es.wowhead.com/quest=10102
SET @ID := 10102;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'K\'ure hizo bien en enviarte aquí. No podemos ayudarte con el sufrimiento de los antepasados orcos, pero hay alguien que sí puede.$B$BAlguien que pronto renacerá de la Luz...', 0),
(@ID, 'esMX', 'K\'ure hizo bien en enviarte aquí. No podemos ayudarte con el sufrimiento de los antepasados orcos, pero hay alguien que sí puede.$B$BAlguien que pronto renacerá de la Luz...', 0);
-- 10103 A las órdenes de Zurai
-- https://es.wowhead.com/quest=10103
SET @ID := 10103;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La verdad es que esperaba más refuerzos, pero tendré que conformarme solo contigo. $gBienvenido:Bienvenida; a la Avanzada Rata del Pantano.', 0),
(@ID, 'esMX', 'La verdad es que esperaba más refuerzos, pero tendré que conformarme solo contigo. $gBienvenido:Bienvenida; a la Avanzada Rata del Pantano.', 0);
-- 10104 Preocupaciones sobre Tuurem
-- https://es.wowhead.com/quest=10104
SET @ID := 10104;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me halaga que tu amigo Tábido me considere un estudioso de las reliquias de su gente, pero para ser honesto, no he tenido muchas oportunidades de estudiarlas desde mi llegada aquí. Ciertamente era mi intención, pero cuando llegué, descubrí que había otros asuntos que requerían mi atención.', 0),
(@ID, 'esMX', 'Me halaga que tu amigo Tábido me considere un estudioso de las reliquias de su gente, pero para ser honesto, no he tenido muchas oportunidades de estudiarlas desde mi llegada aquí. Ciertamente era mi intención, pero cuando llegué, descubrí que había otros asuntos que requerían mi atención.', 0);
-- 10105 Noticias para Rakoria
-- https://es.wowhead.com/quest=10105
SET @ID := 10105;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperaba que los hombres tuvieran el puesto de avanzada completo antes, pero está costando dinero. Aún así, es un progreso.', 0),
(@ID, 'esMX', 'Esperaba que los hombres tuvieran el puesto de avanzada completo antes, pero está costando dinero. Aún así, es un progreso.', 0);
-- Fortificaciones del Fuego Infernal
-- 10106, 13408, 13410
-- https://es.wowhead.com/quest=10106
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Captura La Dominancia', `ObjectiveText2` = 'Captura El Estadium', `ObjectiveText3` = 'Captura Cerro Tábido', `VerifiedBuild` = 0 WHERE `id` IN(10106, 13408, 13410) AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10106, 13408, 13410) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10106, 'esES', '$n, vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13408, 'esES', '$n, vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13410, 'esES', '$n, vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(10106, 'esMX', '$n, vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13408, 'esMX', '$n, vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13410, 'esMX', '$n, vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10106, 13408, 13410) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10106, 'esES', 'Buen trabajo, $n; tus acciones resultan cruciales en nuestra lucha por la Península del Fuego Infernal.', 0),
(13408, 'esES', 'Buen trabajo, $n; tus acciones resultan cruciales en nuestra lucha por la Península del Fuego Infernal.', 0),
(13410, 'esES', 'Buen trabajo, $n; tus acciones resultan cruciales en nuestra lucha por la Península del Fuego Infernal.', 0),
(10106, 'esMX', 'Buen trabajo, $n; tus acciones resultan cruciales en nuestra lucha por la Península del Fuego Infernal.', 0),
(13408, 'esMX', 'Buen trabajo, $n; tus acciones resultan cruciales en nuestra lucha por la Península del Fuego Infernal.', 0),
(13410, 'esMX', 'Buen trabajo, $n; tus acciones resultan cruciales en nuestra lucha por la Península del Fuego Infernal.', 0);
-- Medidas diplomáticas
-- 10107, 10108
-- https://es.wowhead.com/quest=10107
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10107, 10108) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10107, 'esES', '¿Qué decides, pues? ¿Habrá guerra o vas a prestar tu ayuda?', 0),
(10108, 'esES', '¿Qué decides, pues? ¿Habrá guerra o vas a prestar tu ayuda?', 0),
(10107, 'esMX', '¿Qué decides, pues? ¿Habrá guerra o vas a prestar tu ayuda?', 0),
(10108, 'esMX', '¿Qué decides, pues? ¿Habrá guerra o vas a prestar tu ayuda?', 0);
-- 10109 ¡Los necesito!
-- https://es.wowhead.com/quest=10109
SET @ID := 10109;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes gas?', 0),
(@ID, 'esMX', '¿Traes gas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Ahora solo tengo que hacer unos ajustes y el aparato quedará como nuevo. ¡Ah, sí, la llave! Aquí la tienes.$B$BPor cierto, el Saltatrón tiene un par de fallos que tengo que revisar. Esto..., ten cuidado.', 0),
(@ID, 'esMX', '¡Excelente! Ahora solo tengo que hacer unos ajustes y el aparato quedará como nuevo. ¡Ah, sí, la llave! Aquí la tienes.$B$BPor cierto, el Saltatrón tiene un par de fallos que tengo que revisar. Esto..., ten cuidado.', 0);
-- Fortificaciones del Fuego Infernal
-- 10110, 13409, 13411
-- https://es.wowhead.com/quest=10110
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Captura La Dominancia', `ObjectiveText2` = 'Captura El Estadium', `ObjectiveText3` = 'Captura Cerro Tábido', `VerifiedBuild` = 0 WHERE `id` IN(10110, 13409, 13411) AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10110, 13409, 13411) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10110, 'esES', 'Vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13409, 'esES', 'Vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13411, 'esES', 'Vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(10110, 'esMX', 'Vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13409, 'esMX', 'Vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0),
(13411, 'esMX', 'Vuelve a verme cuando hayas ayudado en la captura de cada uno de los fuertes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10110, 13409, 13411) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10110, 'esES', 'Buen trabajo, $n. Casi podía escuchar las batallas libradas en esos fuertes. ¡Ojalá estuviera allí para verlas!', 0),
(13409, 'esES', 'Buen trabajo, $n. Casi podía escuchar las batallas libradas en esos fuertes. ¡Ojalá estuviera allí para verlas!', 0),
(13411, 'esES', 'Buen trabajo, $n. Casi podía escuchar las batallas libradas en esos fuertes. ¡Ojalá estuviera allí para verlas!', 0),
(10110, 'esMX', 'Buen trabajo, $n. Casi podía escuchar las batallas libradas en esos fuertes. ¡Ojalá estuviera allí para verlas!', 0),
(13409, 'esMX', 'Buen trabajo, $n. Casi podía escuchar las batallas libradas en esos fuertes. ¡Ojalá estuviera allí para verlas!', 0),
(13411, 'esMX', 'Buen trabajo, $n. Casi podía escuchar las batallas libradas en esos fuertes. ¡Ojalá estuviera allí para verlas!', 0);
-- 10111 ¡Tráeme el huevo!
-- https://es.wowhead.com/quest=10111
SET @ID := 10111;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Intenta robar el huevo', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te he dicho cuánto adoro los huevos?', 0),
(@ID, 'esMX', '¿Te he dicho cuánto adoro los huevos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, no es un huevo... ¡Eh! ¡Las gallinas también me gustan! ¡Masticaré incluso sus espolones! ¡Gracias!', 0),
(@ID, 'esMX', 'Bueno, no es un huevo... ¡Eh! ¡Las gallinas también me gustan! ¡Masticaré incluso sus espolones! ¡Gracias!', 0);
-- 10112 Un pequeño favor
-- https://es.wowhead.com/quest=10112
SET @ID := 10112;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veamos si estoy recuperando la memoria...', 0),
(@ID, 'esMX', 'Veamos si estoy recuperando la memoria...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ahora empiezo a recordarlo todo.$B$BY creo que tu diligencia en este asunto merece más que la información que buscas.', 0),
(@ID, 'esMX', 'Sí, ahora empiezo a recordarlo todo.$B$BY creo que tu diligencia en este asunto merece más que la información que buscas.', 0);
-- 10113 El Safari Nesingwary
-- https://es.wowhead.com/quest=10113
SET @ID := 10113;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, pues habrá que buscarle un sustituto al recadero. Tú pareces muy fuerte, $c. ¿Buscas trabajo o has venido a cazar?', 0),
(@ID, 'esMX', 'Bueno, pues habrá que buscarle un sustituto al recadero. Tú pareces muy fuerte, $c. ¿Buscas trabajo o has venido a cazar?', 0);
-- 10114 El Safari Nesingwary
-- https://es.wowhead.com/quest=10114
SET @ID := 10114;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alivia saber que está a salvo. ¿Has venido a unirte a la caza?', 0),
(@ID, 'esMX', 'Me alivia saber que está a salvo. ¿Has venido a unirte a la caza?', 0);
-- 10115 La perversión Dagapantano
-- https://es.wowhead.com/quest=10115
SET @ID := 10115;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto lo que han hecho los Dagapantano? Ahora entiendes por qué debemos aislarlos de los otros Perdidos.', 0),
(@ID, 'esMX', '¿Has visto lo que han hecho los Dagapantano? Ahora entiendes por qué debemos aislarlos de los otros Perdidos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Ya nadie puede hacer nada para redimir a los Dagapantano, pero no creo que los draenei hayan reaccionado con suficiente rapidez en este asunto.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Ya nadie puede hacer nada para redimir a los Dagapantano, pero no creo que los draenei hayan reaccionado con suficiente rapidez en este asunto.', 0);
-- 10116 Se busca: Cabecilla Mummaki
-- https://es.wowhead.com/quest=10116
SET @ID := 10116;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que quieres reclamar la recompensa por el cabecilla Mummaki?', 0),
(@ID, 'esMX', '¿Así que quieres reclamar la recompensa por el cabecilla Mummaki?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Extraordinario! Por aquí han pasado muchos deseosos de cobrar la recompensa, pero ninguno ha vuelto. No cuesta mucho imaginar qué les ha pasado.$B$BEs un alivio pensar que nos hemos librado de Mummaki y sus degenerados.', 0),
(@ID, 'esMX', '¡Extraordinario! Por aquí han pasado muchos deseosos de cobrar la recompensa, pero ninguno ha vuelto. No cuesta mucho imaginar qué les ha pasado.$B$BEs un alivio pensar que nos hemos librado de Mummaki y sus degenerados.', 0);
-- 10117 Se busca: Cabecilla Mummaki
-- https://es.wowhead.com/quest=10117
SET @ID := 10117;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que quieres reclamar la recompensa por el cabecilla Mummaki?', 0),
(@ID, 'esMX', '¿Así que quieres reclamar la recompensa por el cabecilla Mummaki?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi agradecimiento, $n. Estaba empezando a pensar que iba a tener que coger varias tropas del cuartel e ir a por Mummaki yo mismo. Aunque quién sabe lo que habría pasado con Zabra\'jin si hubiéramos hecho eso.', 0),
(@ID, 'esMX', 'Tienes mi agradecimiento, $n. Estaba empezando a pensar que iba a tener que coger varias tropas del cuartel e ir a por Mummaki yo mismo. Aunque quién sabe lo que habría pasado con Zabra\'jin si hubiéramos hecho eso.', 0);
-- 10118 Mensaje a los Dagapantano
-- https://es.wowhead.com/quest=10118
SET @ID := 10118;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo único que entienden los Dagapantano es una acción rápida y brutal. Deben saber que no les dejaremos salirse con la suya.', 0),
(@ID, 'esMX', 'Lo único que entienden los Dagapantano es una acción rápida y brutal. Deben saber que no les dejaremos salirse con la suya.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creo que les has mandado un mensaje bastante contundente. Quizás ahora, el resto de mis hombres no estarán tan aterrorizados y se enfrentarán a los Dagapantano. O, si lo siguen estando, se sentirán avergonzados por su cobardía.', 0),
(@ID, 'esMX', 'Creo que les has mandado un mensaje bastante contundente. Quizás ahora, el resto de mis hombres no estarán tan aterrorizados y se enfrentarán a los Dagapantano. O, si lo siguen estando, se sentirán avergonzados por su cobardía.', 0);
-- 10119 A través de El Portal Oscuro
-- https://es.wowhead.com/quest=10119
SET @ID := 10119;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; a Terrallende, $n, ¡$gbienvenido:bienvenida; a la pesadilla! Aunque la Fuerza Expedicionaria inicial salió ilesa, la Legión está intentando retomar el Portal Oscuro y evitar que lleguen nuestros refuerzos.$B$BPor mucho que me gustaría su ayuda aquí, nuestras tropas y los soldados de la Horda pueden defenderse de los pelotones de la Legión que intentan tomar el control de esta plataforma.$B$BTe necesitamos donde se pueda utilizar mejor tu talento.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; a Terrallende, $n, ¡$gbienvenido:bienvenida; a la pesadilla! Aunque la Fuerza Expedicionaria inicial salió ilesa, la Legión está intentando retomar el Portal Oscuro y evitar que lleguen nuestros refuerzos.$B$BPor mucho que me gustaría su ayuda aquí, nuestras tropas y los soldados de la Horda pueden defenderse de los pelotones de la Legión que intentan tomar el control de esta plataforma.$B$BTe necesitamos donde se pueda utilizar mejor tu talento.', 0);

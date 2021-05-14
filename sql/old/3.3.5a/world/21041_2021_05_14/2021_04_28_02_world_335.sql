-- 8978 Regresa junto a Mokvar
-- https://es.classic.wowhead.com/quest=8978
SET @ID := 8978;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto con el dispositivo?', 0),
(@ID, 'esMX', '¿Has vuelto con el dispositivo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto con el dispositivo! Estoy impresionado por tu dedicación, $n. Excelente trabajo.', 0),
(@ID, 'esMX', '¡Has vuelto con el dispositivo! Estoy impresionado por tu dedicación, $n. Excelente trabajo.', 0);
-- 8979 El presentimiento de Fenstad
-- https://es.classic.wowhead.com/quest=8979
SET @ID := 8979;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo puedo servirte?', 0),
(@ID, 'esMX', '¿Cómo puedo servirte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otra de las obsesiones de Fenstad, ya veo. ¿Cree que la Real Sociedad de Boticarios no tiene nada mejor que hacer que realizar sus pequeñas investigaciones?$B$BMuy bien, lo complaceré una vez más.', 0),
(@ID, 'esMX', 'Otra de las obsesiones de Fenstad, ya veo. ¿Cree que la Real Sociedad de Boticarios no tiene nada mejor que hacer que realizar sus pequeñas investigaciones?$B$BMuy bien, lo complaceré una vez más.', 0);
-- 8980 La evaluación de Zinge
-- https://es.classic.wowhead.com/quest=8980
SET @ID := 8980;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, estaba en lo cierto. No debemos perder el tiempo. Debemos determinar la fuente de estas fragancias contaminadas.$B$BEsto es para reembolsarte la compra de la colonia y el perfume.', 0),
(@ID, 'esMX', 'Entonces, estaba en lo cierto. No debemos perder el tiempo. Debemos determinar la fuente de estas fragancias contaminadas.$B$BEsto es para reembolsarte la compra de la colonia y el perfume.', 0);
-- 8982 Rastrear la fuente
-- https://es.classic.wowhead.com/quest=8982
SET @ID := 8982;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, recientemente recibí stock del perfume y la colonia. No sé cuánto tiempo puedo mantenerlo en los estantes, parece que nadie tiene suficiente.$B$BSi me preguntas, no veo cuál es el problema.', 0),
(@ID, 'esMX', 'Ah, sí, recientemente recibí stock del perfume y la colonia. No sé cuánto tiempo puedo mantenerlo en los estantes, parece que nadie tiene suficiente.$B$BSi me preguntas, no veo cuál es el problema.', 0);
-- 8983 Rastrear la fuente
-- https://es.classic.wowhead.com/quest=8983
SET @ID := 8983;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me temo que vendí todo mi suministro de perfume y colonia a Norman, el posadero. Si deseas algo, debes hablar con él, asumiendo que le quede algo.$B$BAdemás, no deberías perder el tiempo. Creo que la colonia te resultará irresistible.', 0),
(@ID, 'esMX', 'Me temo que vendí todo mi suministro de perfume y colonia a Norman, el posadero. Si deseas algo, debes hablar con él, asumiendo que le quede algo.$B$BAdemás, no deberías perder el tiempo. Creo que la colonia te resultará irresistible.', 0);
-- 8984 El descubrimiento de la fuente
-- https://es.classic.wowhead.com/quest=8984
SET @ID := 8984;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, hice esas fragancias. Maravilloso olor, ¿no? Irresistible.$B$BUna vez que los guerreros de la Alianza y la Horda estén enamorados con estos sentimientos de amor, serán impotentes para detener el surgimiento del Consejo de la Sombra.$B$BEstarán debilitados, desprevenidos. Mientras se preocupan por sus seres queridos, perderán su ventaja.$B$BLa solución fue tan simple. ¿Por qué me tomó tanto tiempo encontrarlo? La debilidad de todos es a través del corazón. Y no hay nada que puedas hacer para detener lo inevitable.', 0),
(@ID, 'esMX', 'Sí, hice esas fragancias. Maravilloso olor, ¿no? Irresistible.$B$BUna vez que los guerreros de la Alianza y la Horda estén enamorados con estos sentimientos de amor, serán impotentes para detener el surgimiento del Consejo de la Sombra.$B$BEstarán debilitados, desprevenidos. Mientras se preocupan por sus seres queridos, perderán su ventaja.$B$BLa solución fue tan simple. ¿Por qué me tomó tanto tiempo encontrarlo? La debilidad de todos es a través del corazón. Y no hay nada que puedas hacer para detener lo inevitable.', 0);
-- 8985 Más componentes importantes
-- https://es.classic.wowhead.com/quest=8985
SET @ID := 8985;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la reliquia en el blandón.$B$BAhora todo lo que queda es ir al Santuario de Eldretharr en el ala este de La Masacre, y usar el blandón para convocar el espíritu de mi antigua cohorte, Isalien. Su espíritu ha sido corrompido por la posesión de la pieza del amuleto de Valthalak y la porción de su alma dentro de ella.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la Isla de Alcaz, así que las convertí en pociones para ti. ¡Elige una!', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la reliquia en el blandón.$B$BAhora todo lo que queda es ir al Santuario de Eldretharr en el ala este de La Masacre, y usar el blandón para convocar el espíritu de mi antigua cohorte, Isalien. Su espíritu ha sido corrompido por la posesión de la pieza del amuleto de Valthalak y la porción de su alma dentro de ella.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la Isla de Alcaz, así que las convertí en pociones para ti. ¡Elige una!', 0);
-- 8986 Más componentes importantes
-- https://es.classic.wowhead.com/quest=8986
SET @ID := 8986;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de los restos en el blandón.$B$BAhora todo lo que queda es ir a la parte inferior de Cumbre de Roca Negra, a la cámara donde reside el Maestro de Guerra Voone en Tazz\'Alaor, y usar el blandón para convocar al espíritu corrupto de mi antiguo cohorte, Mor Pezuña Gris. No puede descansar hasta que le quiten la pieza del amuleto.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la isla de Alcaz, así que te las convertí en pociones. ¡Elige una!', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de los restos en el blandón.$B$BAhora todo lo que queda es ir a la parte inferior de Cumbre de Roca Negra, a la cámara donde reside el Maestro de Guerra Voone en Tazz\'Alaor, y usar el blandón para convocar al espíritu corrupto de mi antiguo cohorte, Mor Pezuña Gris. No puede descansar hasta que le quiten la pieza del amuleto.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la isla de Alcaz, así que te las convertí en pociones. ¡Elige una!', 0);
-- 8987 Más componentes importantes
-- https://es.classic.wowhead.com/quest=8987
SET @ID := 8987;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la espada en el blandón.$B$BAhora todo lo que queda es entrar en El Trono Carmesí dentro del Bastión Escarlata en Stratholme, y usar el blandón para convocar los restos de mis antiguos cohortes, Jarien y Sothos. Sus almas se han torcido aún más por la posesión de la pieza de amuleto de Valthalak y su espíritu dentro.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la isla de Alcaz, así que te las convertí en pociones. ¡Elige una!', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la espada en el blandón.$B$BAhora todo lo que queda es entrar en El Trono Carmesí dentro del Bastión Escarlata en Stratholme, y usar el blandón para convocar los restos de mis antiguos cohortes, Jarien y Sothos. Sus almas se han torcido aún más por la posesión de la pieza de amuleto de Valthalak y su espíritu dentro.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la isla de Alcaz, así que te las convertí en pociones. ¡Elige una!', 0);
-- 8988 Más componentes importantes
-- https://es.classic.wowhead.com/quest=8988
SET @ID := 8988;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de las cenizas en el blandón.$B$BAhora todo lo que queda es entrar en Scholomance, en la cámara de Ras Murmuhielo, y usar el blandón para invocar el espíritu de mi antiguo cohorte, Kormok. La pieza del amuleto y el espíritu de Valthalak en su interior lo han corrompido aún más, y no descansará hasta que se lo quites por la fuerza.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la isla de Alcaz, así que te las convertí en pociones. ¡Elige una!', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de las cenizas en el blandón.$B$BAhora todo lo que queda es entrar en Scholomance, en la cámara de Ras Murmuhielo, y usar el blandón para invocar el espíritu de mi antiguo cohorte, Kormok. La pieza del amuleto y el espíritu de Valthalak en su interior lo han corrompido aún más, y no descansará hasta que se lo quites por la fuerza.$B$BOh, por cierto, me sobraron algunas algas de sangre de tu viaje a la isla de Alcaz, así que te las convertí en pociones. ¡Elige una!', 0);
-- 8989 La parte derecha del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8989
SET @ID := 8989;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces está hecho? ¿Ha recuperado la parte derecha del amuleto de Lord Valthalak, has unido el amuleto en un todo y finalmente has puesto a descansar el espíritu de mi antiguo compañero, Mor Pezuña Gris?', 0),
(@ID, 'esMX', '¿Entonces está hecho? ¿Ha recuperado la parte derecha del amuleto de Lord Valthalak, has unido el amuleto en un todo y finalmente has puesto a descansar el espíritu de mi antiguo compañero, Mor Pezuña Gris?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por ayudar a Mor Pezuña Gris, $n. Otro espíritu descansa en paz, ¡y ahora tenemos el amuleto reensamblado! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes ser recolectar y traerlos aquí.', 0),
(@ID, 'esMX', 'Gracias por ayudar a Mor Pezuña Gris, $n. Otro espíritu descansa en paz, ¡y ahora tenemos el amuleto reensamblado! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes ser recolectar y traerlos aquí.', 0);
-- 8990 La parte derecha del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8990
SET @ID := 8990;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguramente aún no te has ocupado de la salvación del espíritu de Isalien y la recuperación de la parte derecha del amuleto de Lord Valthalak, $n. Asegúrate de volver a combinar las piezas del amuleto antes de dármelo.', 0),
(@ID, 'esMX', 'Seguramente aún no te has ocupado de la salvación del espíritu de Isalien y la recuperación de la parte derecha del amuleto de Lord Valthalak, $n. Asegúrate de volver a combinar las piezas del amuleto antes de dármelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n, por hacer descansar el espíritu de Isalien. Ahora, tal vez, encontrará la paz con su diosa. ¡Y también tenemos el amuleto reensamblado! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes recolectar y traer hasta aquí.', 0),
(@ID, 'esMX', 'Gracias, $n, por hacer descansar el espíritu de Isalien. Ahora, tal vez, encontrará la paz con su diosa. ¡Y también tenemos el amuleto reensamblado! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes recolectar y traer hasta aquí.', 0);
-- 8991 La parte derecha del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8991
SET @ID := 8991;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿Esto significa que ya has puesto a descansar las almas de esos dos tontos y has recombinado las piezas del amuleto de Lord Valthalak?', 0),
(@ID, 'esMX', '$c, ¿Esto significa que ya has puesto a descansar las almas de esos dos tontos y has recombinado las piezas del amuleto de Lord Valthalak?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que es lo mejor que las almas de esos dos finalmente hayan descansado, incluso si no me agradaron mientras estaban vivos. En cualquier caso, tenemos lo que buscábamos, ¡y ahora el amuleto está reensamblado! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes recolectar y traers de regreso aquí.', 0),
(@ID, 'esMX', 'Supongo que es lo mejor que las almas de esos dos finalmente hayan descansado, incluso si no me agradaron mientras estaban vivos. En cualquier caso, tenemos lo que buscábamos, ¡y ahora el amuleto está reensamblado! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes recolectar y traers de regreso aquí.', 0);
-- 8992 La parte derecha del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8992
SET @ID := 8992;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te felicito, $n, si has regresado con el amuleto completo. Sin embargo, si no es así, ocúpate de eso, ya que no hay tiempo que perder, ¡te lo aseguro!', 0),
(@ID, 'esMX', 'Te felicito, $n, si has regresado con el amuleto completo. Sin embargo, si no es así, ocúpate de eso, ya que no hay tiempo que perder, ¡te lo aseguro!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Kormok no fue tan malo para un ogro, al menos no mientras aún estaba vivo, así que espero que obtenga el descanso que se merece. ¡Y ahora tenemos el amuleto completo! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes recolectar y traer de regreso aquí.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Kormok no fue tan malo para un ogro, al menos no mientras aún estaba vivo, así que espero que obtenga el descanso que se merece. ¡Y ahora tenemos el amuleto completo! Pero todavía tenemos la prueba más difícil por delante.$B$BPara que el blandón esté en sintonía con la llamada de Lord Valthalak, hay algunos elementos más que debes recolectar y traer de regreso aquí.', 0);
-- 8993 Ofrecer regalos
-- https://es.classic.wowhead.com/quest=8993
SET @ID := 8993;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Magnífico! Lo pondré con los demás regalos.$B$B¡No esperaba tantos! Desde luego, sabéis cómo honrar a los jefes.$B$BBueno, uno más para la lista...', 0),
(@ID, 'esMX', '¡Magnífico! Lo pondré con los demás regalos.$B$B¡No esperaba tantos! Desde luego, sabéis cómo honrar a los jefes.$B$BBueno, uno más para la lista...', 0);
-- 8994 Últimos preparativos
-- https://es.classic.wowhead.com/quest=8994
SET @ID := 8994;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hemos recorrido un largo camino, $n, y solo quería decir que pase lo que pase, ¡gracias! Te has puesto en peligro de muerte para tratar de ayudar a los miembros supervivientes de nuestra compañía mercenaria, La Hoja Velada, y en lo que a mí respecta, ahora eres uno de nosotros.', 0),
(@ID, 'esMX', 'Hemos recorrido un largo camino, $n, y solo quería decir que pase lo que pase, ¡gracias! Te has puesto en peligro de muerte para tratar de ayudar a los miembros supervivientes de nuestra compañía mercenaria, La Hoja Velada, y en lo que a mí respecta, ahora eres uno de nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es. Extraeré el metal de los brazaletes e impregnaré el blandón con estos componentes finales. Entonces estará listo para que convoques a Lord Valthalak y, finalmente, le devuelvas su amuleto espiritual.$B$BHas recorrido una gran distancia, $n, ¡no vaciles ahora que el final está a la vista!', 0),
(@ID, 'esMX', 'Eso es. Extraeré el metal de los brazaletes e impregnaré el blandón con estos componentes finales. Entonces estará listo para que convoques a Lord Valthalak y, finalmente, le devuelvas su amuleto espiritual.$B$BHas recorrido una gran distancia, $n, ¡no vaciles ahora que el final está a la vista!', 0);
-- 8995 Mea Culpa, Lord Valthalak
-- https://es.classic.wowhead.com/quest=8995
SET @ID := 8995;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡te atreves a perturbar mi descanso!', 0),
(@ID, 'esMX', '$n, ¡te atreves a perturbar mi descanso!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué suerte para ti que sé que no eres parte del grupo original que me robó esto.$B$B¡Recuperaré lo que es mío ahora, mortal! ¡Dame el amuleto!', 0),
(@ID, 'esMX', 'Qué suerte para ti que sé que no eres parte del grupo original que me robó esto.$B$B¡Recuperaré lo que es mío ahora, mortal! ¡Dame el amuleto!', 0);
-- 8996 Regresa junto a Bodley
-- https://es.classic.wowhead.com/quest=8996
SET @ID := 8996;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡has vuelto y sigues con vida! Bueno, al menos eso te convierte en uno de nosotros.$B$B¡Vas a tener que contármelo todo!', 0),
(@ID, 'esMX', '$n, ¡has vuelto y sigues con vida! Bueno, al menos eso te convierte en uno de nosotros.$B$B¡Vas a tener que contármelo todo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Realmente dijo todo eso? Vaya, no puedo creer que vaya a despedir a los asesinos espectrales y acechadores, incluso si insinuó que causaría más daño a mis compañeros vivos en el futuro.$B$B¡Este es un gran día, $n! Has logrado lo que pocos pudieron y nos has absuelto al menos en parte de algunos de nuestros pecados pasados.$B$B¡Gracias! Como muestra de agradecimiento, me gustaría darte esto. Puedes usarlo para convocar espíritus en los mismos lugares encantados que ya conoces, y también en algunos otros.', 0),
(@ID, 'esMX', '¿Realmente dijo todo eso? Vaya, no puedo creer que vaya a despedir a los asesinos espectrales y acechadores, incluso si insinuó que causaría más daño a mis compañeros vivos en el futuro.$B$B¡Este es un gran día, $n! Has logrado lo que pocos pudieron y nos has absuelto al menos en parte de algunos de nuestros pecados pasados.$B$B¡Gracias! Como muestra de agradecimiento, me gustaría darte esto. Puedes usarlo para convocar espíritus en los mismos lugares encantados que ya conoces, y también en algunos otros.', 0);
-- 8997 Regreso al principio
-- https://es.classic.wowhead.com/quest=8997
SET @ID := 8997;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy muy feliz de verte regresar a mí $gsano y salvo:sana y salva;, $n. Te ves bien, si no un poco peor por el desgaste.$B$BVen, cuéntame todo lo que ha sucedido.', 0),
(@ID, 'esMX', 'Estoy muy feliz de verte regresar a mí $gsano y salvo:sana y salva;, $n. Te ves bien, si no un poco peor por el desgaste.$B$BVen, cuéntame todo lo que ha sucedido.', 0);
-- 8998 Regreso al principio
-- https://es.classic.wowhead.com/quest=8998
SET @ID := 8998;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que has sobrevivido, $n. Te ves bien, si no un poco más $gcansado:cansada;.$B$BVen, cuéntame todo lo que ha sucedido.', 0),
(@ID, 'esMX', 'Me alegra ver que has sobrevivido, $n. Te ves bien, si no un poco más $gcansado:cansada;.$B$BVen, cuéntame todo lo que ha sucedido.', 0);
-- 8999 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=8999
SET @ID := 8999;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De acuerdo con nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Corazón Salvaje a cambio de tu nuevo jubón y capucha Cueroferal?', 0),
(@ID, 'esMX', 'De acuerdo con nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Corazón Salvaje a cambio de tu nuevo jubón y capucha Cueroferal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9000 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9000
SET @ID := 9000;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Acechabestias a cambio de tu nuevo almete y manto de maestro de bestias?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Acechabestias a cambio de tu nuevo almete y manto de maestro de bestias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9001 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9001
SET @ID := 9001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar las piezas de tu magister a cambio de tu nueva corona y toga de hechicero?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar las piezas de tu magister a cambio de tu nueva corona y toga de hechicero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9002 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9002
SET @ID := 9002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas Forjaluz a cambio de tu nuevo casco y coraza Forjaalma?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas Forjaluz a cambio de tu nuevo casco y coraza Forjaalma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9003 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9003
SET @ID := 9003;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de devoto a cambio de tu nueva corona y túnica virtuosas?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de devoto a cambio de tu nueva corona y túnica virtuosas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9004 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9004
SET @ID := 9004;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de arte sombrío a cambio de tu nueva almete y túnica Mantoscuro?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de arte sombrío a cambio de tu nueva almete y túnica Mantoscuro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9005 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9005
SET @ID := 9005;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de calígine a cambio de tu nueva máscara y túnica de Brumamorta?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de calígine a cambio de tu nueva máscara y túnica de Brumamorta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9006 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9006
SET @ID := 9006;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Valor a cambio de tu nuevo Yelmo y Peto de heroísmo?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Valor a cambio de tu nuevo Yelmo y Peto de heroísmo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $n. Te debo una gran deuda de gratitud; Creo que nunca podré devolverlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 9007 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9007
SET @ID := 9007;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De acuerdo con nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Corazón Salvaje a cambio de tu nuevo chaleco y capucha de Cueroferal?', 0),
(@ID, 'esMX', 'De acuerdo con nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Corazón Salvaje a cambio de tu nuevo chaleco y capucha de Cueroferal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9008 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9008
SET @ID := 9008;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de acechabestias a cambio de tu nueva gorra y túnica de maestro de bestias?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de acechabestias a cambio de tu nueva gorra y túnica de maestro de bestias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9009 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9009
SET @ID := 9009;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de devoto a cambio de tu nueva corona y túnica virtuosas?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de devoto a cambio de tu nueva corona y túnica virtuosas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9010 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9010
SET @ID := 9010;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de arte sombrío a cambio de tu nueva gorra y túnica Mantoscuro?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de arte sombrío a cambio de tu nueva gorra y túnica Mantoscuro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9011 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9011
SET @ID := 9011;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de elementos a cambio de tu nueva Almófar y Jubón de los Cinco Truenos?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de elementos a cambio de tu nueva Almófar y Jubón de los Cinco Truenos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9012 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9012
SET @ID := 9012;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas calígine a cambio de tu nueva Máscara y Toga Brumamorta?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas calígine a cambio de tu nueva Máscara y Toga Brumamorta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9013 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9013
SET @ID := 9013;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Valor a cambio de tu nuevo Yelmo y Coraza de heroísmo?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Valor a cambio de tu nuevo Yelmo y Coraza de heroísmo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);

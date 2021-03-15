-- 5306 Piedra culebra de la cazadora de las Sombras
-- https://es.classic.wowhead.com/quest=5306
SET @ID := 5306;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La leyenda dice que un uso de la piedra de serpiente de Vosh\'gajin mantendrá un hacha afilada durante 1000 años!', 0),
(@ID, 'esMX', '¡La leyenda dice que un uso de la piedra de serpiente de Vosh\'gajin mantendrá un hacha afilada durante 1000 años!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El conocimiento es poder!', 0),
(@ID, 'esMX', '¡El conocimiento es poder!', 0);
-- 5307 Corrupción
-- https://es.classic.wowhead.com/quest=5307
SET @ID := 5307;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has olvidado qué es lo que te asigné, $n?', 0),
(@ID, 'esMX', '¿Has olvidado qué es lo que te asigné, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debería ser obvio que una espada es siempre la mejor opción.', 0),
(@ID, 'esMX', 'Debería ser obvio que una espada es siempre la mejor opción.', 0);
-- La fortuna de la familia Barov
-- 5341, 5343
-- https://es.classic.wowhead.com/quest=5341
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5341, 5343) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5341, 'esES', 'Inclínate ante mí, $r. Soy noble, después de todo, y tú no eres más que $gun simple campesino:una mísera campesina;.', 0),
(5343, 'esES', 'Inclínate ante mí, $r. Soy noble, después de todo, y tú no eres más que $gun simple campesino:una mísera campesina;.', 0),
(5341, 'esMX', 'Inclínate ante mí, $r. Soy noble, después de todo, y tú no eres más que $gun simple campesino:una mísera campesina;.', 0),
(5343, 'esMX', 'Inclínate ante mí, $r. Soy noble, después de todo, y tú no eres más que $gun simple campesino:una mísera campesina;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5341, 5343) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5341, 'esES', 'Un trabajo excelente, $r. Ahora, para asegurar mi herencia...', 0),
(5343, 'esES', 'Un trabajo excelente, $r. Ahora, para asegurar mi herencia...', 0),
(5341, 'esMX', 'Un trabajo excelente, $r. Ahora, para asegurar mi herencia...', 0),
(5343, 'esMX', 'Un trabajo excelente, $r. Ahora, para asegurar mi herencia...', 0);
-- 5342 El último de los Barov
-- https://es.classic.wowhead.com/quest=5342
SET @ID := 5342;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Asegura mi fortuna y participa del botín.', 0),
(@ID, 'esMX', 'Asegura mi fortuna y participa del botín.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! ¡Si tan solo tuviera el poder y la fortuna de la casa Barov!$B$B<Alexi te arroja una gran bolsa.>$B$BQuédate con el cambio, animal apestoso.', 0),
(@ID, 'esMX', '¡Maravilloso! ¡Si tan solo tuviera el poder y la fortuna de la casa Barov!$B$B<Alexi te arroja una gran bolsa.>$B$BQuédate con el cambio, animal apestoso.', 0);
-- 5344 El último de los Barov
-- https://es.classic.wowhead.com/quest=5344
SET @ID := 5344;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quieres cobrar, ¿no es cierto?', 0),
(@ID, 'esMX', 'Quieres cobrar, ¿no es cierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Este es un día glorioso! Por fin, la gangrena de la casa Barov ha sido eliminada, ¡y mi fortuna está asegurada!$B$BToma esto y desaparece de mi vista, $gcampesino:campesina;.', 0),
(@ID, 'esMX', '¡Este es un día glorioso! Por fin, la gangrena de la casa Barov ha sido eliminada, ¡y mi fortuna está asegurada!$B$BToma esto y desaparece de mi vista, $gcampesino:campesina;.', 0);
-- 5361 Árbol genealógico
-- https://es.classic.wowhead.com/quest=5361
SET @ID := 5361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias me traes, $c? ¡Ah! ¿Un mensaje de mi hermano? ¡Muy bien, pues entrégame el informe!', 0),
(@ID, 'esMX', '¿Qué noticias me traes, $c? ¡Ah! ¿Un mensaje de mi hermano? ¡Muy bien, pues entrégame el informe!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sé de qué conoces a mi hermano pero parece que confía en ti, $c.$B$BYo soy Nataka Cuerno Largo y te doy la bienvenida al Campamento del Espíritu Errante. ¡La ayuda de $gun:una; $c nunca viene mal! Habla con los demás, seguro que hay algo que puedas hacer.', 0),
(@ID, 'esMX', 'No sé de qué conoces a mi hermano pero parece que confía en ti, $c.$B$BYo soy Nataka Cuerno Largo y te doy la bienvenida al Campamento del Espíritu Errante. ¡La ayuda de $gun:una; $c nunca viene mal! Habla con los demás, seguro que hay algo que puedas hacer.', 0);
-- 5381 La Mano de Iruxos
-- https://es.classic.wowhead.com/quest=5381
SET @ID := 5381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes la caja de demonio?', 0),
(@ID, 'esMX', '$n, ¿tienes la caja de demonio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, la caja de demonio. Dámela, $c. La abriré... y te mostraré la Mano de Iruxos.', 0),
(@ID, 'esMX', 'Ah, la caja de demonio. Dámela, $c. La abriré... y te mostraré la Mano de Iruxos.', 0);
-- 5382 Doctor Theolen Krastinov, el Carnicero
-- https://es.classic.wowhead.com/quest=5382
SET @ID := 5382;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Has quemado los restos de Eva Sarkhoff', `ObjectiveText3` = 'Has quemado los restos de Lucien Sarkhoff', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hay que detener al Carnicero!', 0),
(@ID, 'esMX', '¡Hay que detener al Carnicero!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo sentir cómo se cura mi espíritu, $n. Nos has hecho un gran favor a mi marido y a mí, pero estoy segura de que todavía queda mucho por hacer.', 0),
(@ID, 'esMX', 'Puedo sentir cómo se cura mi espíritu, $n. Nos has hecho un gran favor a mi marido y a mí, pero estoy segura de que todavía queda mucho por hacer.', 0);
-- 5384 Kirtonos el Heraldo
-- https://es.classic.wowhead.com/quest=5384
SET @ID := 5384;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado, Kirtonos es un luchador experimentado.', 0),
(@ID, 'esMX', 'Ten cuidado, Kirtonos es un luchador experimentado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la muerte de Kirtonos se ha cerrado un capítulo de la terrible historia de Scholomance. Pero todavía queda mucho por hacer. Los demás ya están al corriente de tus heroicidades.', 0),
(@ID, 'esMX', 'Con la muerte de Kirtonos se ha cerrado un capítulo de la terrible historia de Scholomance. Pero todavía queda mucho por hacer. Los demás ya están al corriente de tus heroicidades.', 0);
-- 5385 Los restos de Trey Forjaluz
-- https://es.classic.wowhead.com/quest=5385
SET @ID := 5385;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo fue todo en Jaedenar, $n?', 0),
(@ID, 'esMX', '¿Cómo fue todo en Jaedenar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! Alabada sea Elune y cualquier poder que adores, $n. Hoy has hecho algo honorable y noble. Sé que Arko\'narin estará satisfecha cuando sepa que no solo la salvaste, sino que además, mataste a la criatura que torturó a uno de sus mejores amigos.$B$BQuisiera poder hacer más por ti, pero al menos, acepta esto.', 0),
(@ID, 'esMX', '¡Lo has conseguido! Alabada sea Elune y cualquier poder que adores, $n. Hoy has hecho algo honorable y noble. Sé que Arko\'narin estará satisfecha cuando sepa que no solo la salvaste, sino que además, mataste a la criatura que torturó a uno de sus mejores amigos.$B$BQuisiera poder hacer más por ti, pero al menos, acepta esto.', 0);
-- 5386 La pesca del día
-- https://es.classic.wowhead.com/quest=5386
SET @ID := 5386;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se me hace la boca agua solo de pensar en un panzasangre frito... ¿No llevarás alguno encima?', 0),
(@ID, 'esMX', 'Se me hace la boca agua solo de pensar en un panzasangre frito... ¿No llevarás alguno encima?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres mi salvador, $n! Estos panzasangres tienen tan buena pinta que podría comérmelos crudos.$B$B<Nataka empieza a salivar.>$B$BAnda, elige uno de estos objetos como pago por los peces.', 0),
(@ID, 'esMX', '¡Eres mi salvador, $n! Estos panzasangres tienen tan buena pinta que podría comérmelos crudos.$B$B<Nataka empieza a salivar.>$B$BAnda, elige uno de estos objetos como pago por los peces.', 0);
-- Comisión de El Alba Argenta
-- 5401, 5405, 5503
-- https://es.classic.wowhead.com/quest=5401
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5401, 5405, 5503) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5401, 'esES', 'Todos los que combaten el mal en nombre del Alba Argenta deben vestir nuestra Comisión. Al hacerlo obtendrás el derecho de reclamar recompensas a nuestros intendentes.$B$BMientras estés bajo nuestra comisión podrás adquirir piedras de la Plaga de sus miembros caídos ya que esas piedras son insignias que a veces llevan consigo. Hazte con esas insignias y tráemelas. Por cada juego que traigas recibirás nuestras señales de heroísmo: las muestras de valor del Alba Argenta.$B$BSigue tu destino, $c, ¡únete hoy mismo a la lucha!', 0),
(5405, 'esES', 'Todos los que combaten el mal en nombre del Alba Argenta deben vestir nuestra Comisión. Al hacerlo obtendrás el derecho de reclamar recompensas a nuestros intendentes.$B$BMientras estés bajo nuestra comisión podrás adquirir piedras de la Plaga de sus miembros caídos ya que esas piedras son insignias que a veces llevan consigo. Hazte con esas insignias y tráemelas. Por cada juego que traigas recibirás nuestras señales de heroísmo: las muestras de valor del Alba Argenta.$B$BSigue tu destino, $c, ¡únete hoy mismo a la lucha!', 0),
(5503, 'esES', 'Todos los que combaten el mal en nombre del Alba Argenta deben vestir nuestra Comisión. Al hacerlo obtendrás el derecho de reclamar recompensas a nuestros intendentes.$B$BMientras estés bajo nuestra comisión podrás adquirir piedras de la Plaga de sus miembros caídos ya que esas piedras son insignias que a veces llevan consigo. Hazte con esas insignias y tráemelas. Por cada juego que traigas recibirás nuestras señales de heroísmo: las muestras de valor del Alba Argenta.$B$BSigue tu destino, $c, ¡únete hoy mismo a la lucha!', 0),
(5401, 'esMX', 'Todos los que combaten el mal en nombre del Alba Argenta deben vestir nuestra Comisión. Al hacerlo obtendrás el derecho de reclamar recompensas a nuestros intendentes.$B$BMientras estés bajo nuestra comisión podrás adquirir piedras de la Plaga de sus miembros caídos ya que esas piedras son insignias que a veces llevan consigo. Hazte con esas insignias y tráemelas. Por cada juego que traigas recibirás nuestras señales de heroísmo: las muestras de valor del Alba Argenta.$B$BSigue tu destino, $c, ¡únete hoy mismo a la lucha!', 0),
(5405, 'esMX', 'Todos los que combaten el mal en nombre del Alba Argenta deben vestir nuestra Comisión. Al hacerlo obtendrás el derecho de reclamar recompensas a nuestros intendentes.$B$BMientras estés bajo nuestra comisión podrás adquirir piedras de la Plaga de sus miembros caídos ya que esas piedras son insignias que a veces llevan consigo. Hazte con esas insignias y tráemelas. Por cada juego que traigas recibirás nuestras señales de heroísmo: las muestras de valor del Alba Argenta.$B$BSigue tu destino, $c, ¡únete hoy mismo a la lucha!', 0),
(5503, 'esMX', 'Todos los que combaten el mal en nombre del Alba Argenta deben vestir nuestra Comisión. Al hacerlo obtendrás el derecho de reclamar recompensas a nuestros intendentes.$B$BMientras estés bajo nuestra comisión podrás adquirir piedras de la Plaga de sus miembros caídos ya que esas piedras son insignias que a veces llevan consigo. Hazte con esas insignias y tráemelas. Por cada juego que traigas recibirás nuestras señales de heroísmo: las muestras de valor del Alba Argenta.$B$BSigue tu destino, $c, ¡únete hoy mismo a la lucha!', 0);
-- 5421 Pescado en un balde
-- https://es.classic.wowhead.com/quest=5421
SET @ID := 5421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recompensaré a cualquiera que haga mi vida un poco más fácil... ¡Mi vida se rige por la ley del mínimo esfuerzo, colega!$B$BBajo el embarcadero, aquí en la Aldea Cazasombras, tengo muchas trampas de marisco. Si fueras tan amable... podrías hacer mi trabajo y recoger mi marisco... Y luego yo te doy algo que quieres, ¿pillas el sistema, colega? ¡Por cada 5 mariscos que me traigas, te daré un estupendo panzasangre!', 0),
(@ID, 'esMX', 'Recompensaré a cualquiera que haga mi vida un poco más fácil... ¡Mi vida se rige por la ley del mínimo esfuerzo, colega!$B$BBajo el embarcadero, aquí en la Aldea Cazasombras, tengo muchas trampas de marisco. Si fueras tan amable... podrías hacer mi trabajo y recoger mi marisco... Y luego yo te doy algo que quieres, ¿pillas el sistema, colega? ¡Por cada 5 mariscos que me traigas, te daré un estupendo panzasangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Genial. Nada mejor que un trabajo bien hecho... sobre todo si lo hace otro, ¿eh?', 0),
(@ID, 'esMX', 'Genial. Nada mejor que un trabajo bien hecho... sobre todo si lo hace otro, ¿eh?', 0);
-- 5441 Peones vagos
-- https://es.classic.wowhead.com/quest=5441
SET @ID := 5441;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has despertado a los peones', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya holgazanes...$B$B¿Eh? ¿Tienes mi cachiporra? ¡¿Pillaste a algún peón durmiendo durante el trabajo?!', 0),
(@ID, 'esMX', 'Vaya holgazanes...$B$B¿Eh? ¿Tienes mi cachiporra? ¡¿Pillaste a algún peón durmiendo durante el trabajo?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, bien. ¡Quizás la próxima vez se lo piensen dos veces antes de ponerse a hacer el vago! ¡Gracias por la ayuda!', 0),
(@ID, 'esMX', 'Bien, bien. ¡Quizás la próxima vez se lo piensen dos veces antes de ponerse a hacer el vago! ¡Gracias por la ayuda!', 0);
-- 5461 El humano, Ras Murmuhielo
-- https://es.classic.wowhead.com/quest=5461
SET @ID := 5461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es raro encontrar un Recuerdo de Evocación, $n.', 0),
(@ID, 'esMX', 'Es raro encontrar un Recuerdo de Evocación, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No creía que fuera posible la existencia de un objeto así. Supone sin duda una gran oportunidad y no debemos echarla a perder.$B$BPrepárate, $n, lo que voy a pedirte te llevará a las profundidades del infierno.', 0),
(@ID, 'esMX', 'No creía que fuera posible la existencia de un objeto así. Supone sin duda una gran oportunidad y no debemos echarla a perder.$B$BPrepárate, $n, lo que voy a pedirte te llevará a las profundidades del infierno.', 0);
-- 5462 El moribundo, Ras Murmuhielo
-- https://es.classic.wowhead.com/quest=5462
SET @ID := 5462;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No hagas preguntas de las que no quieres saber la respuesta.', 0),
(@ID, 'esMX', 'No hagas preguntas de las que no quieres saber la respuesta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Leonid echa un vistazo al recuerdo.>$B$BTu confusión despierta recuerdos que esperaba que nunca más volvieran a salir a la superficie.', 0),
(@ID, 'esMX', '<Leonid echa un vistazo al recuerdo.>$B$BTu confusión despierta recuerdos que esperaba que nunca más volvieran a salir a la superficie.', 0);
-- 5463 El Obsequio de Menethil
-- https://es.classic.wowhead.com/quest=5463
SET @ID := 5463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El área que rodea al Obsequio de Menethil está excepcionalmente fría.', 0),
(@ID, 'esMX', 'El área que rodea al Obsequio de Menethil está excepcionalmente fría.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El área que rodea al Obsequio de Menethil está excepcionalmente fría.', 0),
(@ID, 'esMX', 'El área que rodea al Obsequio de Menethil está excepcionalmente fría.', 0);
-- 5464 El Obsequio de Menethil
-- https://es.classic.wowhead.com/quest=5464
SET @ID := 5464;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Leonid se estremece.>', 0),
(@ID, 'esMX', '<Leonid se estremece.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tal y como el alma se aferraba al recuerdo, se aferrará a la forma física de Ras Murmuhielo.', 0),
(@ID, 'esMX', 'Tal y como el alma se aferraba al recuerdo, se aferrará a la forma física de Ras Murmuhielo.', 0);
-- 5465 El Libro de Memorias del Alma
-- https://es.classic.wowhead.com/quest=5465
SET @ID := 5465;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo imposible?', 0),
(@ID, 'esMX', '¿Has hecho lo imposible?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que te unirías a mí como otro desventurado espíritu.', 0),
(@ID, 'esMX', 'Sabía que te unirías a mí como otro desventurado espíritu.', 0);
-- 5466 El exánime, Ras Murmuhielo
-- https://es.classic.wowhead.com/quest=5466
SET @ID := 5466;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Llevas la carga de diez mil almas inquietas, $n.', 0),
(@ID, 'esMX', 'Llevas la carga de diez mil almas inquietas, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Diez mil almas gritan al unísono, $n! Has dado un golpe mortal a la Plaga y a sus maestros.', 0),
(@ID, 'esMX', '¡Diez mil almas gritan al unísono, $n! Has dado un golpe mortal a la Plaga y a sus maestros.', 0);
-- 5481 La tarea de Gordo
-- https://es.classic.wowhead.com/quest=5481
SET @ID := 5481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está esa bestia inútil? Si no tienes lo que necesito, es mejor que vayas a buscarlo.', 0),
(@ID, 'esMX', '¿Dónde está esa bestia inútil? Si no tienes lo que necesito, es mejor que vayas a buscarlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso? ¡¿Hierba luminiscente?! ¡No necesito hierba luminiscente! Esa bestia inútil está recogiendo margaritas y convenciendo a la Dama sabe cuántos inocentones como tú para que hagan lo mismo. No pasa nada.$B$BAhora estás aquí y eso es lo importante. Dado que no voy a perder el tiempo explicándoselo a esa criatura estúpida, qué te parece si te encargas de recoger lo que realmente necesito... ¡apocalíseas!', 0),
(@ID, 'esMX', '¿Qué es eso? ¡¿Hierba luminiscente?! ¡No necesito hierba luminiscente! Esa bestia inútil está recogiendo margaritas y convenciendo a la Dama sabe cuántos inocentones como tú para que hagan lo mismo. No pasa nada.$B$BAhora estás aquí y eso es lo importante. Dado que no voy a perder el tiempo explicándoselo a esa criatura estúpida, qué te parece si te encargas de recoger lo que realmente necesito... ¡apocalíseas!', 0);
-- 5482 Apocalíseas
-- https://es.classic.wowhead.com/quest=5482
SET @ID := 5482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Será mejor que lo que tengas que decirme sea bueno. ¿Tienes todas las apocalíseas que necesito?', 0),
(@ID, 'esMX', 'Será mejor que lo que tengas que decirme sea bueno. ¿Tienes todas las apocalíseas que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, mis apocalíseas! ¡Excelente!$B$B<El boticario de segunda Holland se frota las manos en un gesto de avaricia.>$B$BMe vienen muy bien. Me has prestado... a la Dama, quiero decir, un magnífico servicio. Como te prometí, aquí tienes la recompensa que mereces.', 0),
(@ID, 'esMX', '¡Ah, mis apocalíseas! ¡Excelente!$B$B<El boticario de segunda Holland se frota las manos en un gesto de avaricia.>$B$BMe vienen muy bien. Me has prestado... a la Dama, quiero decir, un magnífico servicio. Como te prometí, aquí tienes la recompensa que mereces.', 0);
-- 5502 Alcaide de la Horda
-- https://es.classic.wowhead.com/quest=5502
SET @ID := 5502;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer volver a verte, $n. ¿Has cumplido las obligaciones con las que te comprometiste al ofrecerte como $gvoluntario:voluntaria; para la Semana de los Niños?', 0),
(@ID, 'esMX', 'Es un placer volver a verte, $n. ¿Has cumplido las obligaciones con las que te comprometiste al ofrecerte como $gvoluntario:voluntaria; para la Semana de los Niños?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que los espíritus te bendigan, $n. Has hecho más por Grunth de lo que nunca hubiera pensado. Gracias, eres la plasmación perfecta de lo que significa ser $gun héroe:una heroína; de la Horda.$B$BPor favor, si tienes algo de tiempo, vuelve a visitarnos. Sé que a Grunth le gustaría, y a mí también.$B$BGrunth se ha divertido mucho contigo, $n, y ha querido darte una de sus mascotas favoritas para que no te olvides de él.', 0),
(@ID, 'esMX', 'Que los espíritus te bendigan, $n. Has hecho más por Grunth de lo que nunca hubiera pensado. Gracias, eres la plasmación perfecta de lo que significa ser $gun héroe:una heroína; de la Horda.$B$BPor favor, si tienes algo de tiempo, vuelve a visitarnos. Sé que a Grunth le gustaría, y a mí también.$B$BGrunth se ha divertido mucho contigo, $n, y ha querido darte una de sus mascotas favoritas para que no te olvides de él.', 0);
-- Mantos del Alba
-- 5504, 5507, 5513
-- https://es.classic.wowhead.com/quest=5504
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5504, 5507, 5513) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5504, 'esES', '¡Ah, noble $C! ¿Has traído las muestras de valor que te pidieron? Una vez que me las entregue, pondré nuestros diferentes mantos a tu disposición para que los compres.', 0),
(5507, 'esES', '¡Ah, noble $C! ¿Has traído las muestras de valor que te pidieron? Una vez que me las entregue, pondré nuestros diferentes mantos a tu disposición para que los compres.', 0),
(5513, 'esES', '¡Ah, noble $C! ¿Has traído las muestras de valor que te pidieron? Una vez que me las entregue, pondré nuestros diferentes mantos a tu disposición para que los compres.', 0),
(5504, 'esMX', '¡Ah, noble $C! ¿Has traído las muestras de valor que te pidieron? Una vez que me las entregue, pondré nuestros diferentes mantos a tu disposición para que los compres.', 0),
(5507, 'esMX', '¡Ah, noble $C! ¿Has traído las muestras de valor que te pidieron? Una vez que me las entregue, pondré nuestros diferentes mantos a tu disposición para que los compres.', 0),
(5513, 'esMX', '¡Ah, noble $C! ¿Has traído las muestras de valor que te pidieron? Una vez que me las entregue, pondré nuestros diferentes mantos a tu disposición para que los compres.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5504, 5507, 5513) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5504, 'esES', 'Sobresaliente: su tributo al Alba se anota debidamente, $n. Con esto logrado, estoy encantado de poner nuestros mantos a su disposición para su compra. Mientras mantenga su estado actual con nosotros, estos mantos se podrán comprar a cualquier intendente autorizado del Alba Argenta.$B$B¡Por el Alba, $ghermano:hermana; mío!', 0),
(5507, 'esES', 'Sobresaliente: su tributo al Alba se anota debidamente, $n. Con esto logrado, estoy encantado de poner nuestros mantos a su disposición para su compra. Mientras mantenga su estado actual con nosotros, estos mantos se podrán comprar a cualquier intendente autorizado del Alba Argenta.$B$B¡Por el Alba, $ghermano:hermana; mío!', 0),
(5513, 'esES', 'Sobresaliente: su tributo al Alba se anota debidamente, $n. Con esto logrado, estoy encantado de poner nuestros mantos a su disposición para su compra. Mientras mantenga su estado actual con nosotros, estos mantos se podrán comprar a cualquier intendente autorizado del Alba Argenta.$B$B¡Por el Alba, $ghermano:hermana; mío!', 0),
(5504, 'esMX', 'Sobresaliente: su tributo al Alba se anota debidamente, $n. Con esto logrado, estoy encantado de poner nuestros mantos a su disposición para su compra. Mientras mantenga su estado actual con nosotros, estos mantos se podrán comprar a cualquier intendente autorizado del Alba Argenta.$B$B¡Por el Alba, $ghermano:hermana; mío!', 0),
(5507, 'esMX', 'Sobresaliente: su tributo al Alba se anota debidamente, $n. Con esto logrado, estoy encantado de poner nuestros mantos a su disposición para su compra. Mientras mantenga su estado actual con nosotros, estos mantos se podrán comprar a cualquier intendente autorizado del Alba Argenta.$B$B¡Por el Alba, $ghermano:hermana; mío!', 0),
(5513, 'esMX', 'Sobresaliente: su tributo al Alba se anota debidamente, $n. Con esto logrado, estoy encantado de poner nuestros mantos a su disposición para su compra. Mientras mantenga su estado actual con nosotros, estos mantos se podrán comprar a cualquier intendente autorizado del Alba Argenta.$B$B¡Por el Alba, $ghermano:hermana; mío!', 0);
-- La llave de Scholomance
-- 5505, 5511
-- https://es.classic.wowhead.com/quest=5505
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5505, 5511) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5505, 'esES', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.', 0),
(5511, 'esES', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.', 0),
(5505, 'esMX', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.', 0),
(5511, 'esMX', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5505, 5511) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5505, 'esES', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.$B$BBuena suerte, $gpoderoso héroe:poderosa heroína;. ¡Que sigas llevando la Luz a las tinieblas!', 0),
(5511, 'esES', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.$B$BBuena suerte, $gpoderoso héroe:poderosa heroína;. ¡Que sigas llevando la Luz a las tinieblas!', 0),
(5505, 'esMX', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.$B$BBuena suerte, $gpoderoso héroe:poderosa heroína;. ¡Que sigas llevando la Luz a las tinieblas!', 0),
(5511, 'esMX', 'Bien, aquí la tienes $n, la Llave esqueleto. Estoy tan seguro como puedo de que con esta llave podrás adentrarte en los confines de Scholomance. Pero solo hay un modo de asegurarse por completo. No pierdas tiempo intentándolo, te lo aconsejo.$B$BBuena suerte, $gpoderoso héroe:poderosa heroína;. ¡Que sigas llevando la Luz a las tinieblas!', 0);
-- 5514 Molde rima con... ¿oro?
-- https://es.classic.wowhead.com/quest=5514
SET @ID := 5514;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sé quién eres, y sé porqué has venido. Dithers me avisó antes de que llegaras. Vayamos directos al grano, ¿de acuerdo?$B$BTengo un molde que podría servirte para la Llave esqueleto, pero te costará quince piezas de oro, por adelantado y sin negociación. Yo me encargaré de poner los trozos esqueléticos en el molde y también te enseñaré a forjar la caña de la llave sin tener que saber nada de herrería... todo gratis, por supuesto.$B$B¡Quién dice que los mercenarios no ofrecemos buenos tratos!', 0),
(@ID, 'esMX', 'Sí, sé quién eres, y sé porqué has venido. Dithers me avisó antes de que llegaras. Vayamos directos al grano, ¿de acuerdo?$B$BTengo un molde que podría servirte para la Llave esqueleto, pero te costará quince piezas de oro, por adelantado y sin negociación. Yo me encargaré de poner los trozos esqueléticos en el molde y también te enseñaré a forjar la caña de la llave sin tener que saber nada de herrería... todo gratis, por supuesto.$B$B¡Quién dice que los mercenarios no ofrecemos buenos tratos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dithers dijo que traerías los materiales, ¡y así ha sido! Un trato es un trato, déjame que yo ponga los fragmentos en el molde.$B$B¿Dithers ya los ha imbuido? Excelente... si no hubieras tenido que regresar hasta El Baluarte.', 0),
(@ID, 'esMX', 'Dithers dijo que traerías los materiales, ¡y así ha sido! Un trato es un trato, déjame que yo ponga los fragmentos en el molde.$B$B¿Dithers ya los ha imbuido? Excelente... si no hubieras tenido que regresar hasta El Baluarte.', 0);
-- 5538 Molde rima con... ¿oro?
-- Notice: English text corresponds to quest 5514 
-- https://es.classic.wowhead.com/quest=5538
SET @ID := 5538;
UPDATE `quest_request_items` SET `CompletionText` = 'Yeah, I know who you are, and I know why you\'re here. Arbington sent word to me before you arrived. Let\'s cut to deal at hand, now shall we?$B$BI\'ve got a mold you can use for the skeleton key, but it will cost you - fifteen gold, up front, no negotiation. I\'ll pack the skeletal fragments into the mold for you, and I\'ll also teach you on how to forge the stem of the key without any knowledge of blacksmithing... all free of charge no less.$B$BWho says mercenaries don\'t offer competitive deals!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sé quién eres, y sé porqué has venido. Arbington me avisó antes de que llegaras. Vayamos directos al grano, ¿de acuerdo?$B$BTengo un molde que podría servirte para la Llave esqueleto, pero te costará quince piezas de oro, por adelantado y sin negociación. Yo me encargaré de poner los trozos esqueléticos en el molde y también te enseñaré a forjar la caña de la llave sin tener que saber nada de herrería... todo gratis, por supuesto.$B$B¡Quién dice que los mercenarios no ofrecemos buenos tratos!', 0),
(@ID, 'esMX', 'Sí, sé quién eres, y sé porqué has venido. Arbington me avisó antes de que llegaras. Vayamos directos al grano, ¿de acuerdo?$B$BTengo un molde que podría servirte para la Llave esqueleto, pero te costará quince piezas de oro, por adelantado y sin negociación. Yo me encargaré de poner los trozos esqueléticos en el molde y también te enseñaré a forjar la caña de la llave sin tener que saber nada de herrería... todo gratis, por supuesto.$B$B¡Quién dice que los mercenarios no ofrecemos buenos tratos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Arbington dijo que traerías los materiales, ¡y así ha sido! Un trato es un trato, déjame que yo ponga los fragmentos en el molde.$B$B¿Arbington ya los ha imbuido? Excelente... si no hubieras tenido que regresar hasta el Alto del Orvallo.', 0),
(@ID, 'esMX', 'Arbington dijo que traerías los materiales, ¡y así ha sido! Un trato es un trato, déjame que yo ponga los fragmentos en el molde.$B$B¿Arbington ya los ha imbuido? Excelente... si no hubieras tenido que regresar hasta el Alto del Orvallo.', 0);
-- 5515 Bolsa de los horrores de Krastinov
-- https://es.classic.wowhead.com/quest=5515
SET @ID := 5515;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La imagen de Eva se desvanece.>', 0),
(@ID, 'esMX', '<La imagen de Eva se desvanece.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La Bolsa de los horrores!', 0),
(@ID, 'esMX', '¡La Bolsa de los horrores!', 0);
-- 5517 Manto del Alba cromático
-- Notice: Replace "priest" to $c
-- https://es.classic.wowhead.com/quest=5517
SET @ID := 5517;
UPDATE `quest_request_items` SET `CompletionText` = 'Salutations, mighty $c! Have you brought the valor tokens I asked of you? Once you hand them to me, I will issue you your own Chromatic Mantle of the Dawn.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
-- Manto del Alba cromático
-- 5517, 5521, 5524
-- https://es.classic.wowhead.com/quest=5517
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5517, 5521, 5524) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5517, 'esES', '¡Saludos, <poderoso/poderosa $c! ¿Has traído las muestras de valor que te pedí? Una vez que me las entregues, te entregaré tu propio Manto del Alba Cromático.', 0),
(5521, 'esES', '¡Saludos, <poderoso/poderosa $c! ¿Has traído las muestras de valor que te pedí? Una vez que me las entregues, te entregaré tu propio Manto del Alba Cromático.', 0),
(5524, 'esES', '¡Saludos, <poderoso/poderosa $c! ¿Has traído las muestras de valor que te pedí? Una vez que me las entregues, te entregaré tu propio Manto del Alba Cromático.', 0),
(5517, 'esMX', '¡Saludos, <poderoso/poderosa $c! ¿Has traído las muestras de valor que te pedí? Una vez que me las entregues, te entregaré tu propio Manto del Alba Cromático.', 0),
(5521, 'esMX', '¡Saludos, <poderoso/poderosa $c! ¿Has traído las muestras de valor que te pedí? Una vez que me las entregues, te entregaré tu propio Manto del Alba Cromático.', 0),
(5524, 'esMX', '¡Saludos, <poderoso/poderosa $c! ¿Has traído las muestras de valor que te pedí? Una vez que me las entregues, te entregaré tu propio Manto del Alba Cromático.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5517, 5521, 5524) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5517, 'esES', 'muy impresionante, $n: ¡el Manto Cromático del Alba es ahora tuyo!$B$BMientras mantengas el estado Exaltado con el Alba Argenta, podrás comprar mantos cromáticos adicionales. Se pondrán a tu disposición de inmediato a través de cualquiera de los intendentes del Alba.', 0),
(5521, 'esES', 'muy impresionante, $n: ¡el Manto Cromático del Alba es ahora tuyo!$B$BMientras mantengas el estado Exaltado con el Alba Argenta, podrás comprar mantos cromáticos adicionales. Se pondrán a tu disposición de inmediato a través de cualquiera de los intendentes del Alba.', 0),
(5524, 'esES', 'muy impresionante, $n: ¡el Manto Cromático del Alba es ahora tuyo!$B$BMientras mantengas el estado Exaltado con el Alba Argenta, podrás comprar mantos cromáticos adicionales. Se pondrán a tu disposición de inmediato a través de cualquiera de los intendentes del Alba.', 0),
(5517, 'esMX', 'muy impresionante, $n: ¡el Manto Cromático del Alba es ahora tuyo!$B$BMientras mantengas el estado Exaltado con el Alba Argenta, podrás comprar mantos cromáticos adicionales. Se pondrán a tu disposición de inmediato a través de cualquiera de los intendentes del Alba.', 0),
(5521, 'esMX', 'muy impresionante, $n: ¡el Manto Cromático del Alba es ahora tuyo!$B$BMientras mantengas el estado Exaltado con el Alba Argenta, podrás comprar mantos cromáticos adicionales. Se pondrán a tu disposición de inmediato a través de cualquiera de los intendentes del Alba.', 0),
(5524, 'esMX', 'muy impresionante, $n: ¡el Manto Cromático del Alba es ahora tuyo!$B$BMientras mantengas el estado Exaltado con el Alba Argenta, podrás comprar mantos cromáticos adicionales. Se pondrán a tu disposición de inmediato a través de cualquiera de los intendentes del Alba.', 0);
-- 5518 El disfraz de ogro Gordok
-- https://es.classic.wowhead.com/quest=5518
SET @ID := 5518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tanino de ogro es probablemente lo más difícil de encontrar de todo lo que necesito para hacer el traje... Pero creo que se puede encontrar arriba. No lo tengo muy claro porque con esta bola y esta cadena no es que pueda moverme mucho...$B$BEn fin, tú tráeme las cosas que necesito y yo te haré un traje de ogro que hará creer al mismísimo capitán Kromcrush que eres uno de sus hombres.', 0),
(@ID, 'esMX', 'El tanino de ogro es probablemente lo más difícil de encontrar de todo lo que necesito para hacer el traje... Pero creo que se puede encontrar arriba. No lo tengo muy claro porque con esta bola y esta cadena no es que pueda moverme mucho...$B$BEn fin, tú tráeme las cosas que necesito y yo te haré un traje de ogro que hará creer al mismísimo capitán Kromcrush que eres uno de sus hombres.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esto servirá. Mete por aquí, saca por allí... Je, je, ¡funcionará de maravilla! <La cara del goblin se ilumina con una amplia sonrisa.>$B$BYa está, ya estás $glisto:lista;. Pero recuerda que no es el objeto mejor elaborado del mundo. Te durará diez minutos y luego se deshará, ¡y entonces no engañarás a nadie! Póntelo poco antes de acercarte a él y recuerda que el traje solo le hará pensar que eres $gun aliado:una aliada;, ¡no su mejor $gamigo:amiga;!', 0),
(@ID, 'esMX', 'Sí, esto servirá. Mete por aquí, saca por allí... Je, je, ¡funcionará de maravilla! <La cara del goblin se ilumina con una amplia sonrisa.>$B$BYa está, ya estás $glisto:lista;. Pero recuerda que no es el objeto mejor elaborado del mundo. Te durará diez minutos y luego se deshará, ¡y entonces no engañarás a nadie! Póntelo poco antes de acercarte a él y recuerda que el traje solo le hará pensar que eres $gun aliado:una aliada;, ¡no su mejor $gamigo:amiga;!', 0);

-- 10588 La Clave de Condenación
-- https://es.tbc.wowhead.com/quest=10588
SET @ID := 10588;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho?', 0),
(@ID, 'esMX', '¿Está hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El ensalmador de la tierra Torlok toma la Clave de Condenación que le das.>$B$BHas hecho lo que los elementos pidieron. Por ello, te estamos agradecidos. Aunque recibirás una recompensa, el peligro aún nos acecha. Los espíritus de fuego están revueltos. Ha corrido un rumor. Alguien más conoce la Clave de Condenación.$B$BEs críptico, lo sé, pero los espíritus solo nos han dicho eso. Eso y este símbolo...$B$B<El ensalmador de la tierra Torlok se gira y mira al cielo.>$B$B¿Qué significará?', 0),
(@ID, 'esMX', '<El ensalmador de la tierra Torlok toma la Clave de Condenación que le das.>$B$BHas hecho lo que los elementos pidieron. Por ello, te estamos agradecidos. Aunque recibirás una recompensa, el peligro aún nos acecha. Los espíritus de fuego están revueltos. Ha corrido un rumor. Alguien más conoce la Clave de Condenación.$B$BEs críptico, lo sé, pero los espíritus solo nos han dicho eso. Eso y este símbolo...$B$B<El ensalmador de la tierra Torlok se gira y mira al cielo.>$B$B¿Qué significará?', 0);
-- 10589 Obtener acceso
-- https://es.wowhead.com/quest=10589
SET @ID := 10589;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos encontrar una manera de destruir al resto de esos infernales, $n. Hemos llegado lejos, pero el fracaso aún podría costarnos todo.', 0),
(@ID, 'esMX', 'Debemos encontrar una manera de destruir al resto de esos infernales, $n. Hemos llegado lejos, pero el fracaso aún podría costarnos todo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame ver si puedo averiguar cómo funciona esto...', 0),
(@ID, 'esMX', 'Déjame ver si puedo averiguar cómo funciona esto...', 0);
-- 10590 Demuestra tu odio
-- https://es.wowhead.com/quest=10590
SET @ID := 10590;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se ha derrumbado la Plaga bajo tu arma?', 0),
(@ID, 'esMX', '¿Se ha derrumbado la Plaga bajo tu arma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Tal vez, después de todo, te guste la venganza.', 0),
(@ID, 'esMX', 'Muy bien, $n. Tal vez, después de todo, te guste la venganza.', 0);
-- 10592 La sabiduría de la reina alma en pena
-- https://es.wowhead.com/quest=10592
SET @ID := 10592;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $r?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas piedras llevan una mancha que no deseo recordar, pero que no puedo olvidar. Pruebas mi paciencia peligrosamente al traerlas.$B$BSin embargo, está claro que tu corazón busca la misma venganza que yo, y te ayudaré con instrucción.', 0),
(@ID, 'esMX', 'Estas piedras llevan una mancha que no deseo recordar, pero que no puedo olvidar. Pruebas mi paciencia peligrosamente al traerlas.$B$BSin embargo, está claro que tu corazón busca la misma venganza que yo, y te ayudaré con instrucción.', 0);
-- 10593 Mal ancestral
-- https://es.wowhead.com/quest=10593
SET @ID := 10593;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dado que estás $gvivo:viva;, solo puedo suponer que tuviste la suerte de recibir sabiduría en lugar de la muerte de Lady Sylvanas.', 0),
(@ID, 'esMX', 'Dado que estás $gvivo:viva;, solo puedo suponer que tuviste la suerte de recibir sabiduría en lugar de la muerte de Lady Sylvanas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Reina Banshee te ha guiado bien. Esto es precisamente lo que necesito para combinar los fragmentos.$B$B<Mehlar observa cómo la vid se entrelaza a través de los fragmentos, uniéndolos.>$B$B¡Hecho! lo llamaré Finiquiplaga. Ten cuidado cuando lo uses, ya que te sirve contra su voluntad.', 0),
(@ID, 'esMX', 'La Reina Banshee te ha guiado bien. Esto es precisamente lo que necesito para combinar los fragmentos.$B$B<Mehlar observa cómo la vid se entrelaza a través de los fragmentos, uniéndolos.>$B$B¡Hecho! lo llamaré Finiquiplaga. Ten cuidado cuando lo uses, ya que te sirve contra su voluntad.', 0);
-- 10594 Medir la frecuencia resonante
-- https://es.wowhead.com/quest=10594
SET @ID := 10594;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien? ¿Tienes las mediciones de los cristales cantos que te pedí?', 0),
(@ID, 'esMX', '¿Y bien? ¿Tienes las mediciones de los cristales cantos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, esto es extraordinario! No tenía ni idea... es casi como si esos cristales estuvieran vivos.$B$BMe pregunto si habrá algún tipo de relación simbiótica entre ellos y los dragones abisales.$B$B¡Gracias, gracias! Tienes que aceptar algún modelito de mi colección de trapos que no me pienso poner.$B$BAlguno te puede quedar bien.', 0),
(@ID, 'esMX', '¡Oh, esto es extraordinario! No tenía ni idea... es casi como si esos cristales estuvieran vivos.$B$BMe pregunto si habrá algún tipo de relación simbiótica entre ellos y los dragones abisales.$B$B¡Gracias, gracias! Tienes que aceptar algún modelito de mi colección de trapos que no me pienso poner.$B$BAlguno te puede quedar bien.', 0);
-- 10595 ¡Asediados!
-- https://es.wowhead.com/quest=10595
SET @ID := 10595;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás $gcansado:cansada;, $c?', 0),
(@ID, 'esMX', '¿Ya estás $gcansado:cansada;, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy impresionado de que hayas logrado sobrevivir a la masacre. Puede que seas exactamente la persona que necesitaremos para una peligrosa misión.', 0),
(@ID, 'esMX', 'Estoy impresionado de que hayas logrado sobrevivir a la masacre. Puede que seas exactamente la persona que necesitaremos para una peligrosa misión.', 0);
-- 10596 Al Bastión de la Legión
-- https://es.wowhead.com/quest=10596
SET @ID := 10596;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Descubrir los planes de la Legión', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto?', 0),
(@ID, 'esMX', '¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Guardia de sangre Gulmok escucha tu informe, el semblante cada vez más preocupado.>$B$B¿A qué te refieres con que van a intensificar el bombardeo? No podemos permitir que eso ocurra. ¡Vuelve allí y ocúpate de eso mientras queda algo de la Aldea Sombraluna!', 0),
(@ID, 'esMX', '<El Guardia de sangre Gulmok escucha tu informe, el semblante cada vez más preocupado.>$B$B¿A qué te refieres con que van a intensificar el bombardeo? No podemos permitir que eso ocurra. ¡Vuelve allí y ocúpate de eso mientras queda algo de la Aldea Sombraluna!', 0);
-- 10597 Preparación de la bomba
-- https://es.wowhead.com/quest=10597
SET @ID := 10597;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Le das los materiales a Gulmok.>', 0),
(@ID, 'esMX', '<Le das los materiales a Gulmok.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gulmok introduce el núcleo de energía en la caja y la sella.>$B$BEso debería bastar. No me gustaría estar en la bodega cuando esto estalle.', 0),
(@ID, 'esMX', '<Gulmok introduce el núcleo de energía en la caja y la sella.>$B$BEso debería bastar. No me gustaría estar en la bodega cuando esto estalle.', 0);
-- 10598 ¡Infernales por los aires!
-- https://es.wowhead.com/quest=10598
SET @ID := 10598;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Destruye infernales del Bastión de la Legión', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado alguna forma de destruir las reservas de infernales de la Legión?', 0),
(@ID, 'esMX', '¿Has encontrado alguna forma de destruir las reservas de infernales de la Legión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gulmok asiente con gesto grave.>$B$BAún no es hora de celebraciones, $n. El peligro sigue amenazando. Tengo nuevas órdenes para ti.', 0),
(@ID, 'esMX', '<Gulmok asiente con gesto grave.>$B$BAún no es hora de celebraciones, $n. El peligro sigue amenazando. Tengo nuevas órdenes para ti.', 0);
-- 10599 La Forja Muerta
-- https://es.wowhead.com/quest=10599
SET @ID := 10599;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El orco asiente con la cabeza.>$B$BEstará bien contar con ese respaldo. Hemos reunido información sobre lo que puede estar tramando el Consejo de la Sombra allí pero es hora de que el martillo caiga con todo su peso.', 0),
(@ID, 'esMX', '<El orco asiente con la cabeza.>$B$BEstará bien contar con ese respaldo. Hemos reunido información sobre lo que puede estar tramando el Consejo de la Sombra allí pero es hora de que el martillo caiga con todo su peso.', 0);
-- 10600 Esbirros del Consejo de la Sombra
-- https://es.wowhead.com/quest=10600
SET @ID := 10600;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya abriste un camino hacia la Forja Muerta?', 0),
(@ID, 'esMX', '¿Ya abriste un camino hacia la Forja Muerta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado allí aplastando calaveras yo mismo pero mis órdenes son estrictas, nada de combate ahora.$B$B<El explorador farfulla entre dientes, imitando bastante bien al Guardia de sangre Gulmok.>$B$BVenga, a trabajar para cerrar la producción allí.', 0),
(@ID, 'esMX', 'He estado allí aplastando calaveras yo mismo pero mis órdenes son estrictas, nada de combate ahora.$B$B<El explorador farfulla entre dientes, imitando bastante bien al Guardia de sangre Gulmok.>$B$BVenga, a trabajar para cerrar la producción allí.', 0);
-- 10601 El destino de Kagrosh
-- https://es.wowhead.com/quest=10601
SET @ID := 10601;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algún rastro de Kagrosh en La Forja Muerta?', 0),
(@ID, 'esMX', '¿Has encontrado algún rastro de Kagrosh en La Forja Muerta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Zagran sacude la cabeza al tomar el paquete que le entregas.>$B$BTe dije que era un inconsciente. Espero que aquí haya algo que justifique el tiempo que has pasado buscándolo.', 0),
(@ID, 'esMX', '<Zagran sacude la cabeza al tomar el paquete que le entregas.>$B$BTe dije que era un inconsciente. Espero que aquí haya algo que justifique el tiempo que has pasado buscándolo.', 0);
-- 10602 La cámara de invocación
-- https://es.wowhead.com/quest=10602
SET @ID := 10602;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Acaba con el ritual de invocación infernal', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir que sigan con la producción. ¿Has puesto fin al ritual de invocación?', 0),
(@ID, 'esMX', 'No podemos permitir que sigan con la producción. ¿Has puesto fin al ritual de invocación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, vamos avanzando. Nos acercamos un poco más al cierre de esa monstruosidad y volver sanos y salvo a la Aldea Sombraluna.', 0),
(@ID, 'esMX', 'Bien, vamos avanzando. Nos acercamos un poco más al cierre de esa monstruosidad y volver sanos y salvo a la Aldea Sombraluna.', 0);
-- 10603 ¡Tumba al belisario!
-- https://es.wowhead.com/quest=10603
SET @ID := 10603;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes de La Forja Muerta?', 0),
(@ID, 'esMX', '¿Qué noticias traes de La Forja Muerta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Informas al Guardia de sangre y le entregas las órdenes interceptadas.>$B$BBuen trabajo, $n, pero no esperes condecoraciones por esto. Que los elfos de la noche decoren sus bonitos uniformes si les parece. Los auténticos guerreros comparten sus relatos con una jarra de cerveza en la mano.', 0),
(@ID, 'esMX', '<Informas al Guardia de sangre y le entregas las órdenes interceptadas.>$B$BBuen trabajo, $n, pero no esperes condecoraciones por esto. Que los elfos de la noche decoren sus bonitos uniformes si les parece. Los auténticos guerreros comparten sus relatos con una jarra de cerveza en la mano.', 0);
-- 10604 Obtener acceso
-- https://es.wowhead.com/quest=10604
SET @ID := 10604;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cualquier presencia de la Legión entre nosotros es intolerable! Debemos encontrar la forma de eliminarlos antes de que puedan atacar de nuevo.', 0),
(@ID, 'esMX', '¡Cualquier presencia de la Legión entre nosotros es intolerable! Debemos encontrar la forma de eliminarlos antes de que puedan atacar de nuevo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin tenemos algo para echar a la Legión de Sombraluna!', 0),
(@ID, 'esMX', '¡Por fin tenemos algo para echar a la Legión de Sombraluna!', 0);
-- 10605 Cita con Carendin
-- https://es.wowhead.com/quest=10605
SET @ID := 10605;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $gotro iniciado hambriento:otra iniciada hambrienta; de poder. ¡Maravilloso!$B$BNo serías $gun:una; $c si no tuvieras sed de poder, ¿verdad, $gmuchacho:muchacha;? Sigamos con eso.', 0),
(@ID, 'esMX', 'Ah, $gotro iniciado hambriento:otra iniciada hambrienta; de poder. ¡Maravilloso!$B$BNo serías $gun:una; $c si no tuvieras sed de poder, ¿verdad, $gmuchacho:muchacha;? Sigamos con eso.', 0);
-- 10606 El Arte del Cuidado de los Atracadores Viles
-- https://es.wowhead.com/quest=10606
SET @ID := 10606;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el manual?', 0),
(@ID, 'esMX', '¿Has conseguido el manual?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, esto es exactamente lo que necesitaremos. Nunca acusaré a la Legión de producir nada que se asemeje a literatura pero esto servirá.', 0),
(@ID, 'esMX', 'Ah, esto es exactamente lo que necesitaremos. Nunca acusaré a la Legión de producir nada que se asemeje a literatura pero esto servirá.', 0);
-- 10607 Susurros del Dios Cuervo
-- https://es.wowhead.com/quest=10607
SET @ID := 10607;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Recibe la primera profecía', `ObjectiveText2` = 'Recibe la segunda profecía', `ObjectiveText3` = 'Recibe la tercera profecía', `ObjectiveText4` = 'Recibe la cuarta profecía', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es este $n? ¿Qué crees que hará? ¿Adónde crees que te conducirá?', 0),
(@ID, 'esMX', '¿Qué es este $n? ¿Qué crees que hará? ¿Adónde crees que te conducirá?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto sí que es preocupante. Durante mucho tiempo los arakkoa fueron pacíficos. Este culto del Cuervo no pasaba de ser una reunión de inadaptados y locos.$B$BPero su poder ha crecido y no podemos ignorarlo. Quizás haya algo más detrás de este Cuervo de lo que ya sabemos.', 0),
(@ID, 'esMX', 'Esto sí que es preocupante. Durante mucho tiempo los arakkoa fueron pacíficos. Este culto del Cuervo no pasaba de ser una reunión de inadaptados y locos.$B$BPero su poder ha crecido y no podemos ignorarlo. Quizás haya algo más detrás de este Cuervo de lo que ya sabemos.', 0);
-- 10608 Limpieza de despellajadores
-- https://es.wowhead.com/quest=10608
SET @ID := 10608;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya mataste esos despellejadores de cristal de Cresta Canto? No podemos empezar con mi investigación hasta que lo hagas.', 0),
(@ID, 'esMX', '¿Ya mataste esos despellejadores de cristal de Cresta Canto? No podemos empezar con mi investigación hasta que lo hagas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Adiós y buen viaje! Eso digo yo. ¡Qué asco de criaturas!$B$BBien, si estás $gseguro:segura; de que has eliminado a esa peste, entonces tengo otro proyectito de investigación para ti. Creo que te gustará.', 0),
(@ID, 'esMX', '¡Adiós y buen viaje! Eso digo yo. ¡Qué asco de criaturas!$B$BBien, si estás $gseguro:segura; de que has eliminado a esa peste, entonces tengo otro proyectito de investigación para ti. Creo que te gustará.', 0);
-- 10609 ¿Qué fue primero? ¿El draco o el huevo?
-- https://es.wowhead.com/quest=10609
SET @ID := 10609;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo tienes todo? ¿Tienes las tres esencias de draco que tanto necesito para seguir investigando?$B$B¿Sabías que esos huevos de draco abisal en otros tiempo eran huevos de dragón Negro? ¡Es un hecho! Pero cuando Draenor se deshizo, El Vacío Abisal resultante que se extendió provocó una mutación en los huevos.', 0),
(@ID, 'esMX', '¿Lo tienes todo? ¿Tienes las tres esencias de draco que tanto necesito para seguir investigando?$B$B¿Sabías que esos huevos de draco abisal en otros tiempo eran huevos de dragón Negro? ¡Es un hecho! Pero cuando Draenor se deshizo, El Vacío Abisal resultante que se extendió provocó una mutación en los huevos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni te imaginas lo importante que esta investigación podría ser. ¡Gracias!$B$BSerá interesante profundizar en el conocimiento de estas esencias. Tengo especial curiosidad por ver si el efecto abisal que cambió los huevos de dragón Negro en huevos de dragón abisal redundará en otras posibles bendiciones en mis estudios.$B$BDe hecho, creo que deberías ser la primera persona en probar los beneficios de mi recetilla. Toma, llévate estas muestras preliminares y úsalas cuando lo necesites.', 0),
(@ID, 'esMX', 'Ni te imaginas lo importante que esta investigación podría ser. ¡Gracias!$B$BSerá interesante profundizar en el conocimiento de estas esencias. Tengo especial curiosidad por ver si el efecto abisal que cambió los huevos de dragón Negro en huevos de dragón abisal redundará en otras posibles bendiciones en mis estudios.$B$BDe hecho, creo que deberías ser la primera persona en probar los beneficios de mi recetilla. Toma, llévate estas muestras preliminares y úsalas cuando lo necesites.', 0);
-- 10611 El Arte del Cuidado de los Atracadores Viles
-- https://es.wowhead.com/quest=10611
SET @ID := 10611;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el manual?', 0),
(@ID, 'esMX', '¿Has conseguido el manual?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, puedo enseñarte a controlar una de estas cosas, pero no va a ser fácil.', 0),
(@ID, 'esMX', 'Sí, puedo enseñarte a controlar una de estas cosas, pero no va a ser fácil.', 0);
-- 10612 El vil y la furia
-- https://es.wowhead.com/quest=10612
SET @ID := 10612;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Infernal Forja Muerta destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, así que asumiré que la operación salió bien. ¿Qué tienes que informar?', 0),
(@ID, 'esMX', 'Has vuelto, así que asumiré que la operación salió bien. ¿Qué tienes que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¡Has logrado hacer lo que ningún jinete de grifo del Bastión Martillo Salvaje pudo hacer! Has roto la espalda del avance de la Legión Ardiente y nos has librado de la aniquilación a manos de los infernales. Tienes nuestra más profunda gratitud por tu servicio, $n.', 0),
(@ID, 'esMX', '¡Increíble! ¡Has logrado hacer lo que ningún jinete de grifo del Bastión Martillo Salvaje pudo hacer! Has roto la espalda del avance de la Legión Ardiente y nos has librado de la aniquilación a manos de los infernales. Tienes nuestra más profunda gratitud por tu servicio, $n.', 0);

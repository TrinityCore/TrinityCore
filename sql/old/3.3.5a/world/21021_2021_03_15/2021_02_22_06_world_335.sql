-- 5658 Toque de debilidad
-- https://es.classic.wowhead.com/quest=5658
SET @ID := 5658;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, joven $c, me alegro de que hayas regresado. Te enseñaré una lección que harías bien en no olvidar. ¿Estas $gpreparado:preparada;?', 0),
(@ID, 'esMX', 'Ah, joven $c, me alegro de que hayas regresado. Te enseñaré una lección que harías bien en no olvidar. ¿Estas $gpreparado:preparada;?', 0);
-- 6343 Regresa junto con Nyoma
-- https://es.classic.wowhead.com/quest=6343
SET @ID := 6343;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿$n, vienes de Auberdine? ¿Hablaste con Laird?', 0),
(@ID, 'esMX', '¿$n, vienes de Auberdine? ¿Hablaste con Laird?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy interesante. Los peces aquí son enormes, pero no pensaba que la pesca de aquí y la de la península fueran tan diferentes. Debe de haber una razón para tal diferencia...$B$BBueno, gracias, $n. Hablaré con los aldeanos de las noticias que has traído. Quizás un día descubramos la razón de esta extraña diferencia. Pero hasta entonces, ¡disfrutaremos de sus beneficios!', 0),
(@ID, 'esMX', 'Esto es muy interesante. Los peces aquí son enormes, pero no pensaba que la pesca de aquí y la de la península fueran tan diferentes. Debe de haber una razón para tal diferencia...$B$BBueno, gracias, $n. Hablaré con los aldeanos de las noticias que has traído. Quizás un día descubramos la razón de esta extraña diferencia. Pero hasta entonces, ¡disfrutaremos de sus beneficios!', 0);
-- 6361 Un fardo de pellejos
-- https://es.classic.wowhead.com/quest=6361
SET @ID := 6361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes a por un jinete del Viento? ¿Tienes que transportar algo?', 0),
(@ID, 'esMX', '¿Vienes a por un jinete del Viento? ¿Tienes que transportar algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tienes que llevar estas pieles a Cima del Trueno, ¡soy tu orco!', 0),
(@ID, 'esMX', 'Si tienes que llevar estas pieles a Cima del Trueno, ¡soy tu orco!', 0);
-- 6362 Un viaje a Cima del Trueno
-- https://es.classic.wowhead.com/quest=6362
SET @ID := 6362;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En tus hombros hay polvo que debe de proceder de Los Baldíos. ¿Has hablado con mi amigo Jahan?', 0),
(@ID, 'esMX', 'En tus hombros hay polvo que debe de proceder de Los Baldíos. ¿Has hablado con mi amigo Jahan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un nuevo paquete de pieles. ¡Me pondré a trabajarlas de inmediato!$B$BGracias, $ghermano:hermana;. Me has hecho un gran favor. Aquí tienes unas monedas por tu tiempo y los gastos de viaje.', 0),
(@ID, 'esMX', 'Ah, un nuevo paquete de pieles. ¡Me pondré a trabajarlas de inmediato!$B$BGracias, $ghermano:hermana;. Me has hecho un gran favor. Aquí tienes unas monedas por tu tiempo y los gastos de viaje.', 0);
-- 6363 Tal, maestro de jinetes del viento
-- https://es.classic.wowhead.com/quest=6363
SET @ID := 6363;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¿Qué puedo hacer por ti?', 0),
(@ID, 'esMX', 'Saludos, $c. ¿Qué puedo hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes que llevar esto a El Cruce? Sin problema. Si ya has estado allí y has hablado con Devrak, entonces puedes llevar uno de mis jinetes del viento para volver.', 0),
(@ID, 'esMX', '¿Tienes que llevar esto a El Cruce? Sin problema. Si ya has estado allí y has hablado con Devrak, entonces puedes llevar uno de mis jinetes del viento para volver.', 0);
-- 6364 Volver junto a Jahan
-- https://es.classic.wowhead.com/quest=6364
SET @ID := 6364;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has vuelto de Cima del Trueno? ¿Le has entregado los cuernos a Ahanu?', 0),
(@ID, 'esMX', '$n, ¿has vuelto de Cima del Trueno? ¿Le has entregado los cuernos a Ahanu?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ahanu me ha enviado productos acabados? Muy bien. Hay muchos cazadores y aventureros en El Cruce ahora y los negocios florecen. Seguro que no tardaré nada en vender estos.$B$BGracias por todo tu trabajo, $n. Estoy en deuda contigo.', 0),
(@ID, 'esMX', '¿Ahanu me ha enviado productos acabados? Muy bien. Hay muchos cazadores y aventureros en El Cruce ahora y los negocios florecen. Seguro que no tardaré nada en vender estos.$B$BGracias por todo tu trabajo, $n. Estoy en deuda contigo.', 0);
-- 6365 Entrega de carne a Orgrimmar
-- https://es.classic.wowhead.com/quest=6365
SET @ID := 6365;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Necesitas llegar a algún lugar rápido? ¡Entonces has dado con el orco apropiado!', 0),
(@ID, 'esMX', '¿Necesitas llegar a algún lugar rápido? ¡Entonces has dado con el orco apropiado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes que llevar esta carne a Orgrimmar? No hay problema. Por una módica cantidad mi jinete del viento puede llevarte.', 0),
(@ID, 'esMX', '¿Tienes que llevar esta carne a Orgrimmar? No hay problema. Por una módica cantidad mi jinete del viento puede llevarte.', 0);
-- 6381 Nueva vida
-- https://es.classic.wowhead.com/quest=6381
SET @ID := 6381;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Semillas de Gaia encantadas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esas semillas que plantas son fuertes, resisten a la corrupción y sirven como punto de apoyo para otras formas de vida. Crecerán y crecerán, evitando primero la corrupción y curando la tierra herida y, un día, devolverán toda la exuberancia y la gloria de Espolón.$B$B¿Has plantado todas las semillas de Gaia?', 0),
(@ID, 'esMX', 'Esas semillas que plantas son fuertes, resisten a la corrupción y sirven como punto de apoyo para otras formas de vida. Crecerán y crecerán, evitando primero la corrupción y curando la tierra herida y, un día, devolverán toda la exuberancia y la gloria de Espolón.$B$B¿Has plantado todas las semillas de Gaia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una gran victoria para la tierra. Con el tiempo, ocurrirán otras cosas: Ventura y Cía. recogerá sus sierras circulares y hachas, los espíritus furiosos de fuego se tranquilizarán y las harpías serán expulsadas por la misma tierra.$B$BEntonces y solo entonces, $n, Espolón logrará por fin la paz.$B$BLo has hecho bien, $c; coge uno de estos objetos como agradecimiento por la nueva vida que has creado hoy aquí.', 0),
(@ID, 'esMX', 'Una gran victoria para la tierra. Con el tiempo, ocurrirán otras cosas: Ventura y Cía. recogerá sus sierras circulares y hachas, los espíritus furiosos de fuego se tranquilizarán y las harpías serán expulsadas por la misma tierra.$B$BEntonces y solo entonces, $n, Espolón logrará por fin la paz.$B$BLo has hecho bien, $c; coge uno de estos objetos como agradecimiento por la nueva vida que has creado hoy aquí.', 0);
-- 6382 La Caza de Vallefresno
-- https://es.classic.wowhead.com/quest=6382
SET @ID := 6382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido a la nueva frontera, $n. Vallefresno es una tierra de oportunidades, un lugar donde cualquier joven $c como tú puede encontrar innumerables ocasiones para demostrar su temple. Mira alrededor de la avanzada y asegúrate de viajar hasta La Ensenada de Zoram, ya que hay otra avanzada de la Horda allí también.$B$BTu presencia aquí indica que has venido a aprender más sobre la caza. Escucha atentamente y será un placer compartir contigo lo que necesites saber.', 0),
(@ID, 'esMX', 'Bienvenido a la nueva frontera, $n. Vallefresno es una tierra de oportunidades, un lugar donde cualquier joven $c como tú puede encontrar innumerables ocasiones para demostrar su temple. Mira alrededor de la avanzada y asegúrate de viajar hasta La Ensenada de Zoram, ya que hay otra avanzada de la Horda allí también.$B$BTu presencia aquí indica que has venido a aprender más sobre la caza. Escucha atentamente y será un placer compartir contigo lo que necesites saber.', 0);
-- 6383 La Caza de Vallefresno
-- https://es.classic.wowhead.com/quest=6383
SET @ID := 6383;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tres legendarias criaturas componen la Caza de Vallefresno; puedes buscarlas y ponerte a prueba frente a su astucia y fuerza. En ese proceso, espero que aprendas algo sobre ti $gmismo:misma;. Estas criaturas son: el oso Ursangous, el felino sable de la noche Shadumbra y el hipogrifo Garrafilada.$B$BLas criaturas de la Caza de Vallefresno son poderosas y es posible que necesites ayuda para derrotarlas. Si llegas a hacerlo, tráeme la prueba de tu caza.', 0),
(@ID, 'esMX', 'Tres legendarias criaturas componen la Caza de Vallefresno; puedes buscarlas y ponerte a prueba frente a su astucia y fuerza. En ese proceso, espero que aprendas algo sobre ti $gmismo:misma;. Estas criaturas son: el oso Ursangous, el felino sable de la noche Shadumbra y el hipogrifo Garrafilada.$B$BLas criaturas de la Caza de Vallefresno son poderosas y es posible que necesites ayuda para derrotarlas. Si llegas a hacerlo, tráeme la prueba de tu caza.', 0);
-- 6384 Un viaje a Orgrimmar
-- https://es.classic.wowhead.com/quest=6384
SET @ID := 6384;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Algo huele muy bien! ¿No tendrás carne cruda contigo?', 0),
(@ID, 'esMX', '¡Algo huele muy bien! ¿No tendrás carne cruda contigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, qué maravilla! ¡Estupendos cortes! Son de Zargh, ¿verdad? Ese $r sí que sabe robarle el corazón a una dama...$B$BMe muero por cocinarlos. ¡Aunque no demasiado! La carne es mejor poco hecha, ¿no te parece?', 0),
(@ID, 'esMX', '¡Oh, qué maravilla! ¡Estupendos cortes! Son de Zargh, ¿verdad? Ese $r sí que sabe robarle el corazón a una dama...$B$BMe muero por cocinarlos. ¡Aunque no demasiado! La carne es mejor poco hecha, ¿no te parece?', 0);
-- 6385 Doras, maestro de jinetes del viento
-- https://es.classic.wowhead.com/quest=6385
SET @ID := 6385;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Necesitas uno de mis jinetes del Viento?', 0),
(@ID, 'esMX', '¿Necesitas uno de mis jinetes del Viento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes que llevar esto a El Cruce en Los Baldíos? Sí, claro, puedo llevarte…', 0),
(@ID, 'esMX', '¿Tienes que llevar esto a El Cruce en Los Baldíos? Sí, claro, puedo llevarte…', 0);
-- 6386 El regreso a El Cruce
-- https://es.classic.wowhead.com/quest=6386
SET @ID := 6386;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has regresado de Orgrimmar? ¿Le gustó a Gryshka la carne que le envié?', 0),
(@ID, 'esMX', '¿Has regresado de Orgrimmar? ¿Le gustó a Gryshka la carne que le envié?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! ¡Supongo que le gustó! ¡Nada ruboriza tanto a una dama como un hermoso y jugoso filete de carne!$B$BGracias, $n. Me has hecho un gran favor. Aquí tienes algo de dinero por las molestias ¡y no te sorprendas si te invito a mi boda!', 0),
(@ID, 'esMX', '¡Ja! ¡Supongo que le gustó! ¡Nada ruboriza tanto a una dama como un hermoso y jugoso filete de carne!$B$BGracias, $n. Me has hecho un gran favor. Aquí tienes algo de dinero por las molestias ¡y no te sorprendas si te invito a mi boda!', 0);
-- 6387 Estudiantes de honor
-- https://es.classic.wowhead.com/quest=6387
SET @ID := 6387;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya te marchas de Thelsamar?', 0),
(@ID, 'esMX', '¿Ya te marchas de Thelsamar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Transporte a Forjaz? Por supuesto. Ir en grifo solo te costará unas monedas. ¿Qué te parece?', 0),
(@ID, 'esMX', '¿Transporte a Forjaz? Por supuesto. Ir en grifo solo te costará unas monedas. ¿Qué te parece?', 0);
-- 6388 Gryth Thurden
-- https://es.classic.wowhead.com/quest=6388
SET @ID := 6388;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que tienes prisa. ¿Necesitas un grifo?', 0),
(@ID, 'esMX', 'Parece que tienes prisa. ¿Necesitas un grifo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Transporte a Thelsamar? Por supuesto. Si ya has estado allí y has hablado con Thorgrum Borrelson, puedes volver en uno de mis grifos.', 0),
(@ID, 'esMX', '¿Transporte a Thelsamar? Por supuesto. Si ya has estado allí y has hablado con Thorgrum Borrelson, puedes volver en uno de mis grifos.', 0);
-- 6389 Una Peste en la Cruzada
-- https://es.classic.wowhead.com/quest=6389
SET @ID := 6389;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho, $n? ¿Has soltado a las termitas? Que la Luz nos ayude si la Cruzada Escarlata consigue conservar tanto la Serrería como Vega del Amparo. No deberían tener ninguno de los dos. ¡Están sacando provecho de las víctimas de la última guerra y deberían ser sacrificados como animales rabiosos!', 0),
(@ID, 'esMX', '¿Lo has hecho, $n? ¿Has soltado a las termitas? Que la Luz nos ayude si la Cruzada Escarlata consigue conservar tanto la Serrería como Vega del Amparo. No deberían tener ninguno de los dos. ¡Están sacando provecho de las víctimas de la última guerra y deberían ser sacrificados como animales rabiosos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! ¡Lo has conseguido! Por fin el espíritu de mi padre podrá descansar y yo podré vivir en paz.$B$BGracias otra vez. Si hay algo que pueda hacer por ti, solo tienes que pedírmelo.', 0),
(@ID, 'esMX', '¡Gracias, $n! ¡Lo has conseguido! Por fin el espíritu de mi padre podrá descansar y yo podré vivir en paz.$B$BGracias otra vez. Si hay algo que pueda hacer por ti, solo tienes que pedírmelo.', 0);
-- 6390 Una Peste en la Cruzada
-- https://es.classic.wowhead.com/quest=6390
SET @ID := 6390;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho, $n? ¿Has liberado las termitas en la Serrería?$B$BYa fue bastante penoso que mi familia perdiera su trabajo y la vida... ¡y además he tenido que ver cómo esos asquerosos hombres "sagrados" invadían el lugar en el que pasé mi infancia!', 0),
(@ID, 'esMX', '¿Lo has hecho, $n? ¿Has liberado las termitas en la Serrería?$B$BYa fue bastante penoso que mi familia perdiera su trabajo y la vida... ¡y además he tenido que ver cómo esos asquerosos hombres "sagrados" invadían el lugar en el que pasé mi infancia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Ten, acepta esta moneda. Siento no poder darte más. ¡Espero que de todas formas hayas disfrutado ayudando a echar por tierra los esfuerzos de la Cruzada Escarlata!', 0),
(@ID, 'esMX', 'Gracias, $n. Ten, acepta esta moneda. Siento no poder darte más. ¡Espero que de todas formas hayas disfrutado ayudando a echar por tierra los esfuerzos de la Cruzada Escarlata!', 0);
-- 6391 Vuela a Forjaz
-- https://es.classic.wowhead.com/quest=6391
SET @ID := 6391;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, la lista de Gremlock. Los picos honoríficos están listos, solo falta grabar los nombres de los estudiantes.', 0),
(@ID, 'esMX', 'Ah, la lista de Gremlock. Los picos honoríficos están listos, solo falta grabar los nombres de los estudiantes.', 0);
-- 6392 Regresa junto a Gremlock
-- https://es.classic.wowhead.com/quest=6392
SET @ID := 6392;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¿ya estás de vuelta de Forjaz?', 0),
(@ID, 'esMX', 'Ah, $n, ¿ya estás de vuelta de Forjaz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los picos! Se los daré a los chicos, están impacientes por empezar a usarlos.$B$BGracias, $n. Ten; sé que es poco, pero espero que al menos cubra los gastos de viaje.', 0),
(@ID, 'esMX', '¡Ah, los picos! Se los daré a los chicos, están impacientes por empezar a usarlos.$B$BGracias, $n. Ten; sé que es poco, pero espero que al menos cubra los gastos de viaje.', 0);
-- 6393 Guerra elemental
-- https://es.classic.wowhead.com/quest=6393
SET @ID := 6393;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Tribunal de las Mareas se impacienta. Quieren poner fin a esta guerra lleva millones de años causando estragos en todas las dimensiones. Mis hermanos están ansiosos por oír la narración de la gloriosa victoria sobre los execrables elementales de fuego. ¿Tienes las incendritas que necesito?', 0),
(@ID, 'esMX', 'El Tribunal de las Mareas se impacienta. Quieren poner fin a esta guerra lleva millones de años causando estragos en todas las dimensiones. Mis hermanos están ansiosos por oír la narración de la gloriosa victoria sobre los execrables elementales de fuego. ¿Tienes las incendritas que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los espíritus del agua que hay en mí, burbujean llenos de excitación. $n, me has dado una victoria gloriosa sobre la que informar al Tribunal de las Mareas.', 0),
(@ID, 'esMX', 'Los espíritus del agua que hay en mí, burbujean llenos de excitación. $n, me has dado una victoria gloriosa sobre la que informar al Tribunal de las Mareas.', 0);
-- 6394 Pico de Thazz'ril
-- https://es.classic.wowhead.com/quest=6394
SET @ID := 6394;
UPDATE `quest_template_locale` SET `Details` = '$n, eres $gun:una; $r de confianza. ¿Puedo contar contigo para otra tarea?$B$BHace algún tiempo estaba inspeccionando la cueva del Norte en busca de minerales y olvidé allí mi pico favorito. ¡Pero cuando volví a recuperarlo descubrí que la cueva estaba plagada de despiadadas criaturas! ¿Irás a la cueva, el Aquelarre del Filo Ardiente, para recuperar mi pico?$B$BLo dejé en una caverna con cascadas. El pico tiene un hechizo que te permitirá verlo en la oscuridad, así que no tienes que preocuparte mucho por encontrarlo... ¡solo por lo que lo esté custodiando!', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entraste en el Aquelarre del Filo Ardiente, $n? ¿Encontraste mi pico?', 0),
(@ID, 'esMX', '¿Entraste en el Aquelarre del Filo Ardiente, $n? ¿Encontraste mi pico?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, lo conseguiste! Muchas gracias, $n. ¡Es mi pico favorito! Ahora, y si mis peones terminan de talar esos árboles de una vez, tal vez encuentre una bonita cueva para excavar.', 0),
(@ID, 'esMX', '¡Genial, lo conseguiste! Muchas gracias, $n. ¡Es mi pico favorito! Ahora, y si mis peones terminan de talar esos árboles de una vez, tal vez encuentre una bonita cueva para excavar.', 0);
-- 6395 El último deseo de Marla
-- https://es.classic.wowhead.com/quest=6395
SET @ID := 6395;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Los restos de Samuel ya están enterrados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos respetar a nuestros muertos, $n. Es una de las formas en las que nos diferenciamos de la Plaga...', 0),
(@ID, 'esMX', 'Debemos respetar a nuestros muertos, $n. Es una de las formas en las que nos diferenciamos de la Plaga...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy has hecho una buena acción, $n. Aunque nuestra lucha contra la Plaga continúa, esperemos que Marla y Samuel encuentren la paz, juntos, en su última morada.', 0),
(@ID, 'esMX', 'Hoy has hecho una buena acción, $n. Aunque nuestra lucha contra la Plaga continúa, esperemos que Marla y Samuel encuentren la paz, juntos, en su última morada.', 0);
-- 6401 Kaya está viva
-- https://es.classic.wowhead.com/quest=6401
SET @ID := 6401;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cielo santo, mi sobrina Kaya está viva! Esto sí que es una buena noticia. Gracias, $n.', 0),
(@ID, 'esMX', '¡Cielo santo, mi sobrina Kaya está viva! Esto sí que es una buena noticia. Gracias, $n.', 0);
-- 6402 Tienes una cita en Ventormenta
-- https://es.classic.wowhead.com/quest=6402
SET @ID := 6402;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Antes de que empecemos, te pido que reúnas un ejército. ¡Después de todo, nos enfrentamos a un dragón!', 0),
(@ID, 'esMX', 'Antes de que empecemos, te pido que reúnas un ejército. ¡Después de todo, nos enfrentamos a un dragón!', 0);
-- 6403 La gran farsa
-- https://es.classic.wowhead.com/quest=6403
SET @ID := 6403;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yo... yo... yo estaba impotente.', 0),
(@ID, 'esMX', 'Yo... yo... yo estaba impotente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Bolvar sujeta el medallón roto.>$B$BHay que reactivar la magia. Debemos restaurar el Ojo del dragón.$B$BEl sacrificio de Windsor ha liberado nuestro reino, pero la amenaza de Onyxia y los suyos todavía no se ha apagado.$B$BEste medallón era lo que tenía mi cuerpo y mi mente prisioneros. También es lo que me dio acceso a la propia mente de Onyxia, a sus secretos. Si bien es cierto que tengo las visiones algo borrosas, recuerdo algunas cosas.', 0),
(@ID, 'esMX', '<Bolvar sujeta el medallón roto.>$B$BHay que reactivar la magia. Debemos restaurar el Ojo del dragón.$B$BEl sacrificio de Windsor ha liberado nuestro reino, pero la amenaza de Onyxia y los suyos todavía no se ha apagado.$B$BEste medallón era lo que tenía mi cuerpo y mi mente prisioneros. También es lo que me dio acceso a la propia mente de Onyxia, a sus secretos. Si bien es cierto que tengo las visiones algo borrosas, recuerdo algunas cosas.', 0);
-- 6421 Barranco del Alud
-- https://es.classic.wowhead.com/quest=6421
SET @ID := 6421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto del Barranco del Alud? Recuerdo una leyenda que habla sobre la resonita... Aunque no lo sé con toda certeza. Quizás si supiéramos lo que yace en el fondo de la cueva, podríamos descubrir sus malignas intenciones.', 0),
(@ID, 'esMX', '¿Qué has descubierto del Barranco del Alud? Recuerdo una leyenda que habla sobre la resonita... Aunque no lo sé con toda certeza. Quizás si supiéramos lo que yace en el fondo de la cueva, podríamos descubrir sus malignas intenciones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡sí! ¡Eso es! Los cristales de resonita tienen una traza de magia terránea. Los kobolds deben haber cavado muy profundo para encontrarlos.$B$BLa leyenda cuenta que los terráneos son criaturas elementales creadas por los Titanes. Los utilizaban para construir la tierra sobre la que caminamos. Esto constituye una amenaza que no podemos ignorar.$B$B<Mor\'rogal asiente con la cabeza>$B$BQuizás pueda encantarte estas muestras de mineral para que las uses para desbaratar la conspiración kóbold.', 0),
(@ID, 'esMX', 'Ah, ¡sí! ¡Eso es! Los cristales de resonita tienen una traza de magia terránea. Los kobolds deben haber cavado muy profundo para encontrarlos.$B$BLa leyenda cuenta que los terráneos son criaturas elementales creadas por los Titanes. Los utilizaban para construir la tierra sobre la que caminamos. Esto constituye una amenaza que no podemos ignorar.$B$B<Mor\'rogal asiente con la cabeza>$B$BQuizás pueda encantarte estas muestras de mineral para que las uses para desbaratar la conspiración kóbold.', 0);
-- 6441 Los cuernos de sátiro
-- https://es.classic.wowhead.com/quest=6441
SET @ID := 6441;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no tardes en recuperar esos cuernos, $n. ¡Pronto volveré a Trinquete!', 0),
(@ID, 'esMX', 'Espero que no tardes en recuperar esos cuernos, $n. ¡Pronto volveré a Trinquete!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nos vendrán de perlas, $n! ¡Gracias por toda tu ayuda!$B$BAh, y aquí tienes por tu tiempo...', 0),
(@ID, 'esMX', '¡Nos vendrán de perlas, $n! ¡Gracias por toda tu ayuda!$B$BAh, y aquí tienes por tu tiempo...', 0);
-- 6442 Nagas en la Ensenada de Zoram
-- https://es.classic.wowhead.com/quest=6442
SET @ID := 6442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los nagas están incrementando sus efectivos, $n. Completa esta tarea para mí.', 0),
(@ID, 'esMX', 'Los nagas están incrementando sus efectivos, $n. Completa esta tarea para mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos vendría bien más gente como tú por aquí, $n. Gracias por tu ayuda.', 0),
(@ID, 'esMX', 'Nos vendría bien más gente como tú por aquí, $n. Gracias por tu ayuda.', 0);
-- 6461 Chupasangres
-- https://es.classic.wowhead.com/quest=6461
SET @ID := 6461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hey colega, ¿has matado a los peludos comedores de sangre? No temo a nadie aquí en Espolón, pero no voy a caminar por aquí de noche... ¡si sabes a qué me refiero, colega!$B$BMientras me mantenga alejado de su plato, todo estará bien.$B$B¡Buena suerte, $c!', 0),
(@ID, 'esMX', 'Hey colega, ¿has matado a los peludos comedores de sangre? No temo a nadie aquí en Espolón, pero no voy a caminar por aquí de noche... ¡si sabes a qué me refiero, colega!$B$BMientras me mantenga alejado de su plato, todo estará bien.$B$B¡Buena suerte, $c!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, colega! Buenas noticias, a lo mejor esta noche tendremos menos invitados no deseados para cenar.$B$BMuchas gracias, $n. Estamos en deuda contigo eternamente.', 0),
(@ID, 'esMX', '¡Genial, colega! Buenas noticias, a lo mejor esta noche tendremos menos invitados no deseados para cenar.$B$BMuchas gracias, $n. Estamos en deuda contigo eternamente.', 0);
-- 6462 El talismán trol
-- https://es.classic.wowhead.com/quest=6462
SET @ID := 6462;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado los talismanes, $n? Por cada momento que los furbolgs tienen en su posesión esos objetos sagrados, ¡me hierve la sangre!', 0),
(@ID, 'esMX', '¿Has encontrado los talismanes, $n? Por cada momento que los furbolgs tienen en su posesión esos objetos sagrados, ¡me hierve la sangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los encontraste! ¡Gracias! ¡Gracias, $n! No sabes el gran favor que me has hecho.$B$BUn trol sin talismán es como un orco sin cicatrices de guerra...$B$BSin ningún valor.', 0),
(@ID, 'esMX', '¡Los encontraste! ¡Gracias! ¡Gracias, $n! No sabes el gran favor que me has hecho.$B$BUn trol sin talismán es como un orco sin cicatrices de guerra...$B$BSin ningún valor.', 0);
-- 6481 El despertar del terráneo
-- https://es.classic.wowhead.com/quest=6481
SET @ID := 6481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me temo que si no nos deshacemos de esta amenaza de inmediato, todo Espolón se perderá. El poder de un terráneo no se puede igualar de ninguna manera. Al despertar, Goggeroc estará débil de su largo letargo, esta será la oportunidad que debes aprovechar... ¡ve ahora $n!', 0),
(@ID, 'esMX', 'Me temo que si no nos deshacemos de esta amenaza de inmediato, todo Espolón se perderá. El poder de un terráneo no se puede igualar de ninguna manera. Al despertar, Goggeroc estará débil de su largo letargo, esta será la oportunidad que debes aprovechar... ¡ve ahora $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Traes buenas noticias, $c! Temo las posibilidades de lo que significaría un terráneo para Kalimdor.$B$BMatar a Goggeroc era algo digno de un héroe. Lo has hecho bien; Espolón y Kalimdor están en deuda contigo, noble $c.$B$BAcepta esto como recompensa.', 0),
(@ID, 'esMX', '¡Traes buenas noticias, $c! Temo las posibilidades de lo que significaría un terráneo para Kalimdor.$B$BMatar a Goggeroc era algo digno de un héroe. Lo has hecho bien; Espolón y Kalimdor están en deuda contigo, noble $c.$B$BAcepta esto como recompensa.', 0);
-- 6482 Liberar a Ruul
-- https://es.classic.wowhead.com/quest=6482
SET @ID := 6482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a mi hermano Ruul? Entró en el bosque hace días y no ha regresado...', 0),
(@ID, 'esMX', '¿Has visto a mi hermano Ruul? Entró en el bosque hace días y no ha regresado...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Encontraste a mi hermano! ¿Lo capturaron los Piel de Cardo? Qué terrible noticia, ya que muchos furbolgs son criaturas nobles pero los Piel de Cardo están corrompidos.$B$BGracias por rescatar a mi hermano, $n. No quiero ni pensar en cómo debieron de tratar al pobre Ruul. Seguro que necesitará mucho descanso después de este suplicio...', 0),
(@ID, 'esMX', '¡Encontraste a mi hermano! ¿Lo capturaron los Piel de Cardo? Qué terrible noticia, ya que muchos furbolgs son criaturas nobles pero los Piel de Cardo están corrompidos.$B$BGracias por rescatar a mi hermano, $n. No quiero ni pensar en cómo debieron de tratar al pobre Ruul. Seguro que necesitará mucho descanso después de este suplicio...', 0);
-- 6501 El Ojo del Dragón
-- https://es.classic.wowhead.com/quest=6501
SET @ID := 6501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento un aura maligna emanando de tu ser, $r. ¿Qué puedes tener que emita un aura así?', 0),
(@ID, 'esMX', 'Siento un aura maligna emanando de tu ser, $r. ¿Qué puedes tener que emita un aura así?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debería haberlo sabido... un trozo de la madre de Vuelo Negro, Onyxia. Qué asqueroso...', 0),
(@ID, 'esMX', 'Debería haberlo sabido... un trozo de la madre de Vuelo Negro, Onyxia. Qué asqueroso...', 0);
-- 6502 Amuleto Pirodraco
-- https://es.classic.wowhead.com/quest=6502
SET @ID := 6502;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El devenir del tiempo ni se detiene ni se ralentiza, $r. Mi vida es eterna, pero la tuya no. No pierdas el tiempo que tienes...', 0),
(@ID, 'esMX', 'El devenir del tiempo ni se detiene ni se ralentiza, $r. Mi vida es eterna, pero la tuya no. No pierdas el tiempo que tienes...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este amuleto te garantizará el acceso que buscas. Podrás encontrar la guarida de Onyxia en el Marjal Revolcafango. Mientras tengas el amuleto, sus guardianes no podrán evitar que entres.$B$BEl Vuelo Azul te desea suerte, $n.', 0),
(@ID, 'esMX', 'Este amuleto te garantizará el acceso que buscas. Podrás encontrar la guarida de Onyxia en el Marjal Revolcafango. Mientras tengas el amuleto, sus guardianes no podrán evitar que entres.$B$BEl Vuelo Azul te desea suerte, $n.', 0);

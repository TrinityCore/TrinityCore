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

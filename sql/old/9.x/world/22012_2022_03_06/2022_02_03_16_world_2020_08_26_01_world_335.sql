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

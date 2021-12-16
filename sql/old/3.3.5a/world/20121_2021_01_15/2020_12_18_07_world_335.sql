-- 9166 Entregando los planes a An'telas
-- https://es.wowhead.com/quest=9166
SET @ID := 9166;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Menos mal que estás aquí!', 0),
(@ID, 'esMX', '¡Menos mal que estás aquí!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fue horrible! Los elfos de la noche invocaron sus cristales lunares aquí por alguna nefanda razón, pero me escabullí y reuní a bastantes de nuestros exploradores y taumaturgo del Sagrario del Sol. Los matamos a casi todos y el resto del grupo está persiguiendo a los supervivientes.$B$BMe alegro de que estés aquí; ¡solo me quedan un par de exploradores como escolta! ¡Esto es muy peligroso!$B$BDéjame leer estos planes para ver qué pretenden esos elfos de la noche.', 0),
(@ID, 'esMX', '¡Fue horrible! Los elfos de la noche invocaron sus cristales lunares aquí por alguna nefanda razón, pero me escabullí y reuní a bastantes de nuestros exploradores y taumaturgo del Sagrario del Sol. Los matamos a casi todos y el resto del grupo está persiguiendo a los supervivientes.$B$BMe alegro de que estés aquí; ¡solo me quedan un par de exploradores como escolta! ¡Esto es muy peligroso!$B$BDéjame leer estos planes para ver qué pretenden esos elfos de la noche.', 0);
-- 9193 Investiga las Catacumbas Amani
-- https://es.wowhead.com/quest=9193
SET @ID := 9193;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Restos de trol momificado quemados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es un asunto de lo más sombrío e indecoroso, $c. Confío en que completarás esta tarea como para satisfacer a mi señora.', 0),
(@ID, 'esMX', 'Este es un asunto de lo más sombrío e indecoroso, $c. Confío en que completarás esta tarea como para satisfacer a mi señora.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Asqueroso pero necesario, te lo puedo asegurar. Nos has hecho un gran favor investigando este asunto, $c. Te lo ruego, acepta esto como muestra de nuestra generosidad y aprecio.', 0),
(@ID, 'esMX', 'Asqueroso pero necesario, te lo puedo asegurar. Nos has hecho un gran favor investigando este asunto, $c. Te lo ruego, acepta esto como muestra de nuestra generosidad y aprecio.', 0);
-- 9199 Juju trol
-- https://es.wowhead.com/quest=9199
SET @ID := 9199;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No necesito recordarte que mal nos podemos permitir este jaleo con los muertos trols resucitando en nuestro jardín! ¡Ya tenemos suficiente con lo de la Ciudad de la Muerte al sur!', 0),
(@ID, 'esMX', 'No necesito recordarte que mal nos podemos permitir este jaleo con los muertos trols resucitando en nuestro jardín! ¡Ya tenemos suficiente con lo de la Ciudad de la Muerte al sur!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Momias erigidas por sacerdotes trols... ¡ingenioso! Los trols Sombrapino deben de estar intentando incrementar sus efectivos a través de estas prácticas nigrománticas. Apostaría a que estos oráculos usaban el Juju en su ritual de reanimación.$B$BUna vez más has cumplido con tu deber como cabe esperar de $gun:una; $c de creciente reputación como la tuya. Acepta esto con nuestra gratitud.', 0),
(@ID, 'esMX', 'Momias erigidas por sacerdotes trols... ¡ingenioso! Los trols Sombrapino deben de estar intentando incrementar sus efectivos a través de estas prácticas nigrománticas. Apostaría a que estos oráculos usaban el Juju en su ritual de reanimación.$B$BUna vez más has cumplido con tu deber como cabe esperar de $gun:una; $c de creciente reputación como la tuya. Acepta esto con nuestra gratitud.', 0);
-- 9315 Anok'suten
-- https://es.wowhead.com/quest=9315
SET @ID := 9315;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un líder nerubiano? ¡Ninguna de las misiones de exploración informó nada sobre este Anok\'suten!', 0),
(@ID, 'esMX', '¿Un líder nerubiano? ¡Ninguna de las misiones de exploración informó nada sobre este Anok\'suten!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te pido disculpas por la falta de información, $c. Si hubiera oído hablar de esta Anok\'suten, te habría avisado.$B$BEstamos demasiado dispersos y las cosas se nos escurren entre los dedos.', 0),
(@ID, 'esMX', 'Te pido disculpas por la falta de información, $c. Si hubiera oído hablar de esta Anok\'suten, te habría avisado.$B$BEstamos demasiado dispersos y las cosas se nos escurren entre los dedos.', 0);
-- 9139 Aldea Bruma Dorada
-- https://es.wowhead.com/quest=9139
SET @ID := 9139;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He aprendido mucho sobre la lucha contra la Plaga en el tiempo que he estado aquí. Pueden retroceder, pero debe hacerse en pequeños pasos. La manera obscena en la que pueden tomar a los caídos y agregarlos a sus propias filas como los recién resucitados hace que sea imperativo que no cometa errores en el camino.$B$BAhora bien, ¿cómo va la lucha contra la Aldea Bruma Dorada?', 0),
(@ID, 'esMX', 'He aprendido mucho sobre la lucha contra la Plaga en el tiempo que he estado aquí. Pueden retroceder, pero debe hacerse en pequeños pasos. La manera obscena en la que pueden tomar a los caídos y agregarlos a sus propias filas como los recién resucitados hace que sea imperativo que no cometa errores en el camino.$B$BAhora bien, ¿cómo va la lucha contra la Aldea Bruma Dorada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu éxito en la Aldea Bruma Dorada nos acerca un poco más a recuperar nuestra tierra. Pero no te engañes, $c: la lucha no ha terminado.$B$BTen; te lo has ganado de sobra. Puede que lo necesites cuando vayas a enfrentarte a la Aldea Brisaveloz.', 0),
(@ID, 'esMX', 'Tu éxito en la Aldea Bruma Dorada nos acerca un poco más a recuperar nuestra tierra. Pero no te engañes, $c: la lucha no ha terminado.$B$BTen; te lo has ganado de sobra. Puede que lo necesites cuando vayas a enfrentarte a la Aldea Brisaveloz.', 0);
-- 9173 Recuperar Aguja Brisaveloz
-- https://es.wowhead.com/quest=9173
SET @ID := 9173;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Confío en que vuelvas a verme con la noticia de que la Aguja Brisaveloz ha sido limpiada de su infección por la Plaga.', 0),
(@ID, 'esMX', 'Confío en que vuelvas a verme con la noticia de que la Aguja Brisaveloz ha sido limpiada de su infección por la Plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A lady Sylvanas le complacerá saber que hemos hecho progresos en este asunto.$B$BTen, acepta esta moneda en pago por tus esfuerzos.', 0),
(@ID, 'esMX', 'A lady Sylvanas le complacerá saber que hemos hecho progresos en este asunto.$B$BTen, acepta esta moneda en pago por tus esfuerzos.', 0);
-- 9216 Corazones putrefactos
-- https://es.wowhead.com/quest=9216
SET @ID := 9216;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los corazones de zombi que te pedí, $n?', 0),
(@ID, 'esMX', '¿Tienes los corazones de zombi que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tómate este jarabe, $n. Cuando lo tomes notarás un subidón en tu fuerza física frente a la Plaga. Si necesitas más que esta muestra, tráeme más corazones.', 0),
(@ID, 'esMX', 'Tómate este jarabe, $n. Cuando lo tomes notarás un subidón en tu fuerza física frente a la Plaga. Si necesitas más que esta muestra, tráeme más corazones.', 0);
-- 9217 Más corazones putrefactos
-- https://es.wowhead.com/quest=9217
SET @ID := 9217;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído más corazones de zombi? Puedo usar tantos como puedas traer, $n.', 0),
(@ID, 'esMX', '¿Has traído más corazones de zombi? Puedo usar tantos como puedas traer, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con esto tendrás mayor poder frente a la Plaga. Trae más corazones si los encuentras, $n.', 0),
(@ID, 'esMX', 'Con esto tendrás mayor poder frente a la Plaga. Trae más corazones si los encuentras, $n.', 0);
-- 9218 Polvo de espina dorsal
-- https://es.wowhead.com/quest=9218
SET @ID := 9218;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las muestras que te pedí, $n?', 0),
(@ID, 'esMX', '¿Tienes las muestras que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tómate esto, $n. ¡Notarás el cambio enseguida!$B$BTrae todo el polvo de espina dorsal que quieras, puedo usar tanto como puedas suministrar. ¿Efectos secundarios? Podrías notar que las articulaciones te dan un poco de guerra. Nada permanente, ¡te lo garantizo!', 0),
(@ID, 'esMX', 'Tómate esto, $n. ¡Notarás el cambio enseguida!$B$BTrae todo el polvo de espina dorsal que quieras, puedo usar tanto como puedas suministrar. ¿Efectos secundarios? Podrías notar que las articulaciones te dan un poco de guerra. Nada permanente, ¡te lo garantizo!', 0);
-- 9219 Más polvo de espina dorsal
-- https://es.wowhead.com/quest=9219
SET @ID := 9219;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha conseguido más polvo de espina dorsal? Puedo usar tanto como me traigas.', 0),
(@ID, 'esMX', '¿Ha conseguido más polvo de espina dorsal? Puedo usar tanto como me traigas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este polvo es tan potente como siempre, $n. Sigue trayéndome espinas dorsales si necesitas aumentar tus poderes mágicos contra la Plaga.', 0),
(@ID, 'esMX', 'Este polvo es tan potente como siempre, $n. Sigue trayéndome espinas dorsales si necesitas aumentar tus poderes mágicos contra la Plaga.', 0);
-- 9140 La Aldea Brisaveloz
-- https://es.wowhead.com/quest=9140
SET @ID := 9140;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿está liberada la Aldea Brisaveloz? Esos malditos magistri del Sagrario del Sol me han amonestado, están locos por ponerle la mano encima a esos restos de la Plaga que te pedí que recolectaras.$B$BPero no te preocupes por eso. Tómate tu tiempo y haz bien tu trabajo. Yo me ocuparé de los magistri.', 0),
(@ID, 'esMX', '$c, ¿está liberada la Aldea Brisaveloz? Esos malditos magistri del Sagrario del Sol me han amonestado, están locos por ponerle la mano encima a esos restos de la Plaga que te pedí que recolectaras.$B$BPero no te preocupes por eso. Tómate tu tiempo y haz bien tu trabajo. Yo me ocuparé de los magistri.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has conseguido, $n. ¡Has acabado con el control de la Plaga sobre tres aldeas! Ahora podemos dedicar el grueso de nuestras tropas a combatir las fuerzas de la Plaga en La Cicatriz Muerta, al sur de la Ciudad de la Muerte.$B$BAquí tienes, elige la pieza que quieras. Confío en que no te vayas a ningún sitio ¿verdad? ¡Nos vendría realmente bien que siguieras ayudándonos!', 0),
(@ID, 'esMX', 'Lo has conseguido, $n. ¡Has acabado con el control de la Plaga sobre tres aldeas! Ahora podemos dedicar el grueso de nuestras tropas a combatir las fuerzas de la Plaga en La Cicatriz Muerta, al sur de la Ciudad de la Muerte.$B$BAquí tienes, elige la pieza que quieras. Confío en que no te vayas a ningún sitio ¿verdad? ¡Nos vendría realmente bien que siguieras ayudándonos!', 0);
-- 9143 Encargarse de Zeb'Sora
-- https://es.wowhead.com/quest=9143
SET @ID := 9143;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las orejas de trol?$B$BSi Tranquillien nos enviara ayuda de vez en cuando, esto no sería un problema. Me alegro de que estés aquí.', 0),
(@ID, 'esMX', '¿Traes las orejas de trol?$B$BSi Tranquillien nos enviara ayuda de vez en cuando, esto no sería un problema. Me alegro de que estés aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $c. Ahora podemos decir que esta expedición y las vidas que ha costado no han sido en vano.', 0),
(@ID, 'esMX', 'Muchas gracias, $c. Ahora podemos decir que esta expedición y las vidas que ha costado no han sido en vano.', 0);
-- 9157 Rituales olvidados
-- https://es.wowhead.com/quest=9157
SET @ID := 9157;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los medallones, $n? ¡Los ahogados siguen vagando por el lago!', 0),
(@ID, 'esMX', '¿Traes los medallones, $n? ¡Los ahogados siguen vagando por el lago!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con esto invocaremos a Aquantion una vez más. ¡Ese elemental rebelde pagará por lo que hizo y nuestras muertes serán vengadas!', 0),
(@ID, 'esMX', 'Con esto invocaremos a Aquantion una vez más. ¡Ese elemental rebelde pagará por lo que hizo y nuestras muertes serán vengadas!', 0);
-- 644 El sigilo de Aterratrols
-- https://es.classic.wowhead.com/quest=644
SET @ID := 644;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Está rota la línea del sigilo de Ignaeus?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Está rota la línea del sigilo de Ignaeus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es un gran día, $c. La sangre de Aterratrols ya no perseguirá a mi gente, y los sigilos necesarios para tomar Trol\'kalar están en nuestro poder. Pronto, muy pronto, atacaremos a los odiados trols de Zul\'Gurub.', 0),
(@ID, 'esMX', 'Este es un gran día, $c. La sangre de Aterratrols ya no perseguirá a mi gente, y los sigilos necesarios para tomar Trol\'kalar están en nuestro poder. Pronto, muy pronto, atacaremos a los odiados trols de Zul\'Gurub.', 0);
-- 645 Trol'kalar
-- https://es.classic.wowhead.com/quest=645
SET @ID := 645;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los grabados en la piedra sobre la tumba de Aterratrols coinciden con las líneas brillantes del Sello de Ignaeus...', 0),
(@ID, 'esMX', 'Los grabados en la piedra sobre la tumba de Aterratrols coinciden con las líneas brillantes del Sello de Ignaeus...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al hacer coincidir las líneas de la tumba de Aterratrols con las líneas brillantes del Sigilo de Ignaeus, un destello de luz consume el Sigilo y la legendaria espada Trol\'kalar se libera del agarre de las manos de piedra.', 0),
(@ID, 'esMX', 'Al hacer coincidir las líneas de la tumba de Aterratrols con las líneas brillantes del Sigilo de Ignaeus, un destello de luz consume el Sigilo y la legendaria espada Trol\'kalar se libera del agarre de las manos de piedra.', 0);
-- 646 Trol'kalar
-- https://es.classic.wowhead.com/quest=646
SET @ID := 646;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Has conseguido la espada?', 0),
(@ID, 'esMX', '¡$n! ¿Has conseguido la espada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Durante generaciones, las tropas de Strom y de Arathor han devastado a los trols. Ahora su arma más poderosa está en nuestras manos. Se acabó arañar cada centímetro de territorio en los húmedos bosques de Zul\'Gurub.$B$BNos has sido de gran ayuda, $n, y los trols Lanza Negra están en deuda contigo.$B$BMe ocuparé de que la espada se entrega a Nimboya en Grom\'gol.', 0),
(@ID, 'esMX', 'Durante generaciones, las tropas de Strom y de Arathor han devastado a los trols. Ahora su arma más poderosa está en nuestras manos. Se acabó arañar cada centímetro de territorio en los húmedos bosques de Zul\'Gurub.$B$BNos has sido de gran ayuda, $n, y los trols Lanza Negra están en deuda contigo.$B$BMe ocuparé de que la espada se entrega a Nimboya en Grom\'gol.', 0);
-- 648 ¡Rescatar a OOX-17/TN!
-- https://es.classic.wowhead.com/quest=648
SET @ID := 648;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, así que tú eres quien ha rescatado a OOX-17/TN! ¡No sé cómo darte las gracias por tu ayuda! Sin duda, tengo que perfeccionar mi robot mensajero pero gracias a ti no perderé innumerables horas de trabajo construyendo uno nuevo, lo que implicaría perder muchas piezas de oro.$B$BPor favor, elige uno de los objetos que tengo. Con suerte, alguno de ellos te resultará útil. Gracias de nuevo por tu inestimable ayuda. ¡Mis robots y yo estamos en deuda contigo!', 0),
(@ID, 'esMX', '¡Ah, así que tú eres quien ha rescatado a OOX-17/TN! ¡No sé cómo darte las gracias por tu ayuda! Sin duda, tengo que perfeccionar mi robot mensajero pero gracias a ti no perderé innumerables horas de trabajo construyendo uno nuevo, lo que implicaría perder muchas piezas de oro.$B$BPor favor, elige uno de los objetos que tengo. Con suerte, alguno de ellos te resultará útil. Gracias de nuevo por tu inestimable ayuda. ¡Mis robots y yo estamos en deuda contigo!', 0);
-- 649 Recupera el calimocho
-- https://es.classic.wowhead.com/quest=649
SET @ID := 649;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, sí, el calimocho! Mi padre quiere venderlo en una taberna de Orgrimmar, pero nos pagarán más si está en el envase original. Sé de alguien que puede encargarse; está en las Tierras del Interior, como el calimocho. Lo que pasa es que es, esto, un elfo noble.$B$BPero es bueno, no está con la Alianza. En realidad no es que sea bueno, es un borracho; no veas cómo le da.', 0),
(@ID, 'esMX', '¡Ah, sí, el calimocho! Mi padre quiere venderlo en una taberna de Orgrimmar, pero nos pagarán más si está en el envase original. Sé de alguien que puede encargarse; está en las Tierras del Interior, como el calimocho. Lo que pasa es que es, esto, un elfo noble.$B$BPero es bueno, no está con la Alianza. En realidad no es que sea bueno, es un borracho; no veas cómo le da.', 0);
-- 650 Recupera el calimocho
-- https://es.classic.wowhead.com/quest=650
SET @ID := 650;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿conoces a Malton? Es un viejo compañero de juergas. He descubierto algo que trasciende las fronteras y los tratados: el alcohol. Su consumo nos hará libres y felices.$B$BPero sospecho que no has venido a hablar de las virtudes del alcohol, ¿verdad?', 0),
(@ID, 'esMX', 'Ah, ¿conoces a Malton? Es un viejo compañero de juergas. He descubierto algo que trasciende las fronteras y los tratados: el alcohol. Su consumo nos hará libres y felices.$B$BPero sospecho que no has venido a hablar de las virtudes del alcohol, ¿verdad?', 0);
-- 654 Recogida de muestras en Tanaris
-- https://es.classic.wowhead.com/quest=654
SET @ID := 654;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿conseguiste todo lo que necesitabas? Si no lo hiciste y se acaba la luz, todo lo que hay dentro se arruinará y tendrás que empezar de nuevo.$B$BOye, no me busques por ser simpático; Solo quiero que la Compañía de Agua de Gadgetzan obtenga ganancias, y si eso significa venderte fuentes de energía hasta que podamos permitirnos importar agua de los manantiales helados de Dun Morogh, ¡que así sea!', 0),
(@ID, 'esMX', 'Bueno, ¿conseguiste todo lo que necesitabas? Si no lo hiciste y se acaba la luz, todo lo que hay dentro se arruinará y tendrás que empezar de nuevo.$B$BOye, no me busques por ser simpático; Solo quiero que la Compañía de Agua de Gadgetzan obtenga ganancias, y si eso significa venderte fuentes de energía hasta que podamos permitirnos importar agua de los manantiales helados de Dun Morogh, ¡que así sea!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, me tomará solo un segundo quitar la fuente de energía. Después, puedes hacer con él lo que quieras sin tener que preocuparse por perder los datos que contiene.', 0),
(@ID, 'esMX', 'Muy bien, me tomará solo un segundo quitar la fuente de energía. Después, puedes hacer con él lo que quieras sin tener que preocuparse por perder los datos que contiene.', 0);
-- 655 Sentencia
-- https://es.classic.wowhead.com/quest=655
SET @ID := 655;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, hablas de Gor\'mul. Sí, por lo que cuenta, parece que nunca se repuso de la muerte de Martillo Maldito.$B$BGor\'mul estuvo cautivo aquí cuando Thrall y Orgrim luchaban para liberar el campamento pero cuando la tierra tembló y nuestros hermanos escaparon, él se quedó atrás. Estuvo vagando en soledad durante años sin rumbo ni objetivo hasta que volvimos para asentarnos aquí en Sentencia.', 0),
(@ID, 'esMX', 'Ah, hablas de Gor\'mul. Sí, por lo que cuenta, parece que nunca se repuso de la muerte de Martillo Maldito.$B$BGor\'mul estuvo cautivo aquí cuando Thrall y Orgrim luchaban para liberar el campamento pero cuando la tierra tembló y nuestros hermanos escaparon, él se quedó atrás. Estuvo vagando en soledad durante años sin rumbo ni objetivo hasta que volvimos para asentarnos aquí en Sentencia.', 0);
-- 662 Rescate en alta mar
-- https://es.classic.wowhead.com/quest=662
SET @ID := 662;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la misión de búsqueda y recuperación, $n? Tenemos que recuperar los cuadernos de bitácora y las cartas de navegación de El capricho y del Espíritu de argénteos.$B$BSi la información de esas fuentes cayera en manos enemigas, el maestro de flota Cuernomarino nos haría pasear la tabla.$B$BEso si salimos algún día de este lío...', 0),
(@ID, 'esMX', '¿Cómo va la misión de búsqueda y recuperación, $n? Tenemos que recuperar los cuadernos de bitácora y las cartas de navegación de El capricho y del Espíritu de argénteos.$B$BSi la información de esas fuentes cayera en manos enemigas, el maestro de flota Cuernomarino nos haría pasear la tabla.$B$BEso si salimos algún día de este lío...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La certeza de que esta información está a buen recaudo tranquilizará al mando de Bahía del Botín. Muy bien, $n.', 0),
(@ID, 'esMX', 'La certeza de que esta información está a buen recaudo tranquilizará al mando de Bahía del Botín. Muy bien, $n.', 0);
-- 663 ¡Tierra a vista!
-- https://es.classic.wowhead.com/quest=663
SET @ID := 663;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah del barco, colega!$B$BSe ha producido un desastre. Cuernomarino se quedará con mi barco si se entera de lo que se ha hundido.$B$BUno de los inventos del profesor indicaba que el tesoro perdido estaba cerca de esta cala. Hice venir al Heraldo al embarcadero y apunté hacia el Espíritu de argénteos y El capricho para seguir su rumbo.$B$BEntonces el mar retumbó. La marea bajó y los dos barcos encallaron en el arrecife.$B$BNo es solo un arrecife. Allí abajo hay algo más...$B$BAyuda a mi tripulación y recibirás una generosa recompensa.', 0),
(@ID, 'esMX', '¡Ah del barco, colega!$B$BSe ha producido un desastre. Cuernomarino se quedará con mi barco si se entera de lo que se ha hundido.$B$BUno de los inventos del profesor indicaba que el tesoro perdido estaba cerca de esta cala. Hice venir al Heraldo al embarcadero y apunté hacia el Espíritu de argénteos y El capricho para seguir su rumbo.$B$BEntonces el mar retumbó. La marea bajó y los dos barcos encallaron en el arrecife.$B$BNo es solo un arrecife. Allí abajo hay algo más...$B$BAyuda a mi tripulación y recibirás una generosa recompensa.', 0);
-- 664 Ahogar las penas
-- https://es.classic.wowhead.com/quest=664
SET @ID := 664;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bah, tal vez debería ir a matar a esa escoria naga yo mismo. Es obvio que no lo vas a hacer.$B$BTal vez pueda encontrar algunas agujas de tejer para que puedas mantenerte ocupado.', 0),
(@ID, 'esMX', 'Bah, tal vez debería ir a matar a esa escoria naga yo mismo. Es obvio que no lo vas a hacer.$B$BTal vez pueda encontrar algunas agujas de tejer para que puedas mantenerte ocupado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, sí $gseñor:señora;, $r.$B$BEsa escoria se ha llevado su merecido. Aunque nada me devolverá mi barco o mi tripulación, la muerte de esos nagas me brinda algo de consuelo.', 0),
(@ID, 'esMX', 'Buen trabajo, sí $gseñor:señora;, $r.$B$BEsa escoria se ha llevado su merecido. Aunque nada me devolverá mi barco o mi tripulación, la muerte de esos nagas me brinda algo de consuelo.', 0);
-- 665 El tesoro sumergido
-- https://es.classic.wowhead.com/quest=665
SET @ID := 665;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No es momento de hablar! ¡Las gafas deben cargarse con el poder de la piedra!', 0),
(@ID, 'esMX', '¡No es momento de hablar! ¡Las gafas deben cargarse con el poder de la piedra!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las gafas protectoras funcionan ahora perfectamente! Muy bien, $n.', 0),
(@ID, 'esMX', '¡Las gafas protectoras funcionan ahora perfectamente! Muy bien, $n.', 0);

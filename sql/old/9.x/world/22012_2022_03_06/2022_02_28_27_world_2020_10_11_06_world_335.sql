-- 2498 Regresa junto a Denalan
-- https://es.classic.wowhead.com/quest=2498
SET @ID := 2498;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, Rellian te ha enviado para que me ayudes! Me alegro de que hayas llegado tan pronto.$B$B¡He descubierto algo bastante alarmante!', 0),
(@ID, 'esMX', '¡Ah, Rellian te ha enviado para que me ayudes! Me alegro de que hayas llegado tan pronto.$B$B¡He descubierto algo bastante alarmante!', 0);
-- 2499 Roblegüello
-- https://es.classic.wowhead.com/quest=2499
SET @ID := 2499;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has localizado ya a Roblegüello, $r?', 0),
(@ID, 'esMX', '¿Has localizado ya a Roblegüello, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que serías capaz de acabar con esa bestia que aterrorizaba el lago.$B$BEstamos ante una penosa situación; Roblegüello fue en su día un gran líder entre los suyos... pero la corrupción no hace distinción entre el pueblo llano y los nobles.$B$BEl tamaño de este tumor es preocupante pero debo estudiarlo en profundidad para averiguar más datos sobre la enfermedad que está asolando a los Brezomadera.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'Sabía que serías capaz de acabar con esa bestia que aterrorizaba el lago.$B$BEstamos ante una penosa situación; Roblegüello fue en su día un gran líder entre los suyos... pero la corrupción no hace distinción entre el pueblo llano y los nobles.$B$BEl tamaño de este tumor es preocupante pero debo estudiarlo en profundidad para averiguar más datos sobre la enfermedad que está asolando a los Brezomadera.$B$BGracias, $n.', 0);
-- 3661 ¿Creados por Elune?
-- https://es.classic.wowhead.com/quest=3661
SET @ID := 3661;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Intenta no acercarte a ellos; pueden sentirse amenazados y atacarte.', 0),
(@ID, 'esMX', 'Intenta no acercarte a ellos; pueden sentirse amenazados y atacarte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$B¿Aprendiste algo de esas criaturas?$B$BCon estas plumas sabremos más de su naturaleza.$B$BVoy a estudiarlas; tú dedícate a tus cosas y vuelve a hablar conmigo en otro momento.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$B¿Aprendiste algo de esas criaturas?$B$BCon estas plumas sabremos más de su naturaleza.$B$BVoy a estudiarlas; tú dedícate a tus cosas y vuelve a hablar conmigo en otro momento.', 0);
-- 5250 Estrella Fugaz
-- https://es.classic.wowhead.com/quest=5250
SET @ID := 5250;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿$gUn alumno:Una alumna; de Daryn Lightwind? Encantado de conocerte, $n.', 0),
(@ID, 'esMX', '¿$gUn alumno:Una alumna; de Daryn Lightwind? Encantado de conocerte, $n.', 0);
-- 3524 Varado
-- https://es.classic.wowhead.com/quest=3524
SET @ID := 3524;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace poco que esas criaturas han empezado a llegar a Costa Oscura en números tan alarmantes. No puedo evitar pensar que esto es algún tipo de augurio. Si consiguieras para Darnassus una muestra de los huesos de alguna de esas criaturas, nos ayudarías a entender la situación.', 0),
(@ID, 'esMX', 'Hace poco que esas criaturas han empezado a llegar a Costa Oscura en números tan alarmantes. No puedo evitar pensar que esto es algún tipo de augurio. Si consiguieras para Darnassus una muestra de los huesos de alguna de esas criaturas, nos ayudarías a entender la situación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que el múrloc no te pusiera difícil conseguirnos esto! Me aseguraré de mandar esto a Darnassus en el siguiente hipogrifo. El Templo de la Luna me ha concedido unos fondos para entregar a quien nos ayude. Te entrego una parte con nuestro agradecimiento.$B$BTu éxito me ha animado a ofrecerte la posibilidad de ayudar más al Templo de la Luna, si te interesa...', 0),
(@ID, 'esMX', '¡Espero que el múrloc no te pusiera difícil conseguirnos esto! Me aseguraré de mandar esto a Darnassus en el siguiente hipogrifo. El Templo de la Luna me ha concedido unos fondos para entregar a quien nos ayude. Te entrego una parte con nuestro agradecimiento.$B$BTu éxito me ha animado a ofrecerte la posibilidad de ayudar más al Templo de la Luna, si te interesa...', 0);
-- 1138 Rico marisco
-- https://es.classic.wowhead.com/quest=1138
SET @ID := 1138;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '...cangrejo al limón y cangrejo-sorpresa de Forjaz. Creo que no me dejo nada.$B$BOh, hola, $n. ¿Tienes esos trozos de cangrejo de gran calidad de los que te hablaba?', 0),
(@ID, 'esMX', '...cangrejo al limón y cangrejo-sorpresa de Forjaz. Creo que no me dejo nada.$B$BOh, hola, $n. ¿Tienes esos trozos de cangrejo de gran calidad de los que te hablaba?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, estos trozos de cangrejo de gran calidad son justo lo que necesito. ¡Gracias, $n! Encontré esto pescando hace un tiempo y no lo he usado. Quizás tú puedas darle uso. Desde luego, no podrás usarlo para preparar platos de cangrejo.$B$BYa te he hablado de los cangrejos, ¿verdad?', 0),
(@ID, 'esMX', 'Vaya, estos trozos de cangrejo de gran calidad son justo lo que necesito. ¡Gracias, $n! Encontré esto pescando hace un tiempo y no lo he usado. Quizás tú puedas darle uso. Desde luego, no podrás usarlo para preparar platos de cangrejo.$B$BYa te he hablado de los cangrejos, ¿verdad?', 0);
-- 1141 La familia y la caña de pescar
-- https://es.classic.wowhead.com/quest=1141
SET @ID := 1141;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con los meros de Costa Oscura se pueden preparar muchos platos muy buenos. Están muy ricos. Pero a mí me gusta más pescarlos.$B$B¿Tú has pescado alguno ya?', 0),
(@ID, 'esMX', 'Con los meros de Costa Oscura se pueden preparar muchos platos muy buenos. Están muy ricos. Pero a mí me gusta más pescarlos.$B$B¿Tú has pescado alguno ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estos meros son estupendos, $n! ¡Gracias por ayudarme!$B$BEres como mínimo, tan buen pescador como mi prima, Graun Blump. Ella también tiene barba y huele un poco raro, pero eso no le impide cazar como una diosa. Está claro que tienes lo que hace falta para utilizar una caña de pescar de la familia Blump.', 0),
(@ID, 'esMX', '¡Estos meros son estupendos, $n! ¡Gracias por ayudarme!$B$BEres como mínimo, tan buen pescador como mi prima, Graun Blump. Ella también tiene barba y huele un poco raro, pero eso no le impide cazar como una diosa. Está claro que tienes lo que hace falta para utilizar una caña de pescar de la familia Blump.', 0);
-- 963 Un amor eterno
-- https://es.classic.wowhead.com/quest=963
SET @ID := 963;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con una gran pena en el corazón, seguí a Shan\'do Tempestira en su hibernación y arrastré mi pena en mis sueños durante miles de años.', 0),
(@ID, 'esMX', 'Con una gran pena en el corazón, seguí a Shan\'do Tempestira en su hibernación y arrastré mi pena en mis sueños durante miles de años.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Quizás habría sido mejor... que lo hubiera hecho yo. Pero incluso después de tantos milenios, no podía soportar la idea de alzar mi mano contra mi amada.$B$BPor favor, déjame a solas con mi dolor...', 0),
(@ID, 'esMX', 'Gracias, $n. Quizás habría sido mejor... que lo hubiera hecho yo. Pero incluso después de tantos milenios, no podía soportar la idea de alzar mi mano contra mi amada.$B$BPor favor, déjame a solas con mi dolor...', 0);
-- 983 La caja mecánica 827
-- https://es.classic.wowhead.com/quest=983
SET @ID := 983;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja mecánica 827 guarda un inquietante silencio. Un destello luminoso indica que hay que colocar 6 patas de reptador en su soporte.', 0),
(@ID, 'esMX', 'La caja mecánica 827 guarda un inquietante silencio. Un destello luminoso indica que hay que colocar 6 patas de reptador en su soporte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando introduces las patas de reptador en la máquina, oyes chirriar sus engranajes. A juzgar por los sonidos que provienen de la caja mecánica, parece que las patas de reptador están colocándose en su sitio. La máquina empieza a zumbar y luego oyes una vocecita.$B$B"¿Hola? Eeh... ¡Hola! ¡La has arreglado! ¡Por cierto, esta es Zumbang! ¡Muchas gracias! Oye, ¿te apetecería reparar otra...?"', 0),
(@ID, 'esMX', 'Cuando introduces las patas de reptador en la máquina, oyes chirriar sus engranajes. A juzgar por los sonidos que provienen de la caja mecánica, parece que las patas de reptador están colocándose en su sitio. La máquina empieza a zumbar y luego oyes una vocecita.$B$B"¿Hola? Eeh... ¡Hola! ¡La has arreglado! ¡Por cierto, esta es Zumbang! ¡Muchas gracias! Oye, ¿te apetecería reparar otra...?"', 0);
-- 1579 Mecanismos eléctricos
-- https://es.classic.wowhead.com/quest=1579
SET @ID := 1579;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mis mecanismos eléctricos, $n? ¡Sin mis mecanismos eléctricos no puedo ajustarme las clavijas!', 0),
(@ID, 'esMX', '¿Has encontrado mis mecanismos eléctricos, $n? ¡Sin mis mecanismos eléctricos no puedo ajustarme las clavijas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo creer que los hayas encontrado! ¡Eres sin duda $gel:la; $r más $gafortunado:afortunada; de Kalimdor!', 0),
(@ID, 'esMX', '¡No puedo creer que los hayas encontrado! ¡Eres sin duda $gel:la; $r más $gafortunado:afortunada; de Kalimdor!', 0);
-- 4740 SE BUSCA: ¡Viscoso!
-- https://es.classic.wowhead.com/quest=4740
SET @ID := 4740;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos $c. ¿En qué pueden ayudarte los Centinelas hoy? ¿Quizás estás aquí para preguntar por la recompensa por Viscoso?', 0),
(@ID, 'esMX', 'Saludos $c. ¿En qué pueden ayudarte los Centinelas hoy? ¿Quizás estás aquí para preguntar por la recompensa por Viscoso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, diría que no has venido aquí solo a informarte! Los ciudadanos estarán encantados de saber que hoy podrán dormir un poco más tranquilos.$B$BHas traído un poco de paz y justicia a la gente de Auberdine, $n y por eso, quisiera ofrecerte esto como recompensa... Serás $gel héroe:la heroína; de las gentes de Auberdine.', 0),
(@ID, 'esMX', '¡Vaya, diría que no has venido aquí solo a informarte! Los ciudadanos estarán encantados de saber que hoy podrán dormir un poco más tranquilos.$B$BHas traído un poco de paz y justicia a la gente de Auberdine, $n y por eso, quisiera ofrecerte esto como recompensa... Serás $gel héroe:la heroína; de las gentes de Auberdine.', 0);
-- 947 La cueva de las setas
-- https://es.classic.wowhead.com/quest=947
SET @ID := 947;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis champiñones, $n? ¿Has estado en la cueva?', 0),
(@ID, 'esMX', '¿Tienes mis champiñones, $n? ¿Has estado en la cueva?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. ¡Estos champiñones son unos especímenes estupendos!$B$BOye, mientras estabas en el Salto de Fonroca, ¿encontraste algo que confirmara las preocupaciones de los Ancestros?$B$BLos Ancestros son sabios, pero esperaba que esta vez estuvieran equivocados.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. ¡Estos champiñones son unos especímenes estupendos!$B$BOye, mientras estabas en el Salto de Fonroca, ¿encontraste algo que confirmara las preocupaciones de los Ancestros?$B$BLos Ancestros son sabios, pero esperaba que esta vez estuvieran equivocados.', 0);
-- 4811 El cristal rojo
-- https://es.classic.wowhead.com/quest=4811
SET @ID := 4811;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes que informar sobre ese cristal rojo? ¿Existe realmente?', 0),
(@ID, 'esMX', '¿Qué tienes que informar sobre ese cristal rojo? ¿Existe realmente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que el cristal existe, $n. Fascinante... Bien, bien, ¡has hecho un buen trabajo!$B$B¿Y qué es exactamente ese cristal? Esta es solo una pregunta de las muchas que me vienen a la cabeza. Otra sería: ¿por qué los lechúcicos lunares se sienten atraídos por este objeto...? ¿El cristal es de naturaleza benigna o tiene un propósito más siniestro?$B$BY tengo más preguntas, pero será mejor examinar bien el cristal, a ver si las responde.', 0),
(@ID, 'esMX', 'Así que el cristal existe, $n. Fascinante... Bien, bien, ¡has hecho un buen trabajo!$B$B¿Y qué es exactamente ese cristal? Esta es solo una pregunta de las muchas que me vienen a la cabeza. Otra sería: ¿por qué los lechúcicos lunares se sienten atraídos por este objeto...? ¿El cristal es de naturaleza benigna o tiene un propósito más siniestro?$B$BY tengo más preguntas, pero será mejor examinar bien el cristal, a ver si las responde.', 0);
-- 729 El prospector despistado
-- https://es.classic.wowhead.com/quest=729
SET @ID := 729;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hollee, eres tú? Necesito ayuda con esta piedra. Pásame mi cepillo, creo que veo algo.$B$B¡Oye, tú no eres Hollee! ¿No habrás visto mi cepillo de piedra?$B$B¡Eso no importa ahora! Prometí a la Liga que enviaría el misterioso fósil que encontré. ¿Adónde se fue Hollee?$B$B¡Con todo lo que queda por hacer! En fin... ¿y dónde estará ese fósil misterioso? ¿Y mi cepillo...? ¿Y Hollee?$B$B¿Y tú quien eres? En realidad no importa, siempre que estés aquí para ayudar.$B$BAvísame cuando estés listo para empezar a buscar.', 0),
(@ID, 'esMX', '¿Hollee, eres tú? Necesito ayuda con esta piedra. Pásame mi cepillo, creo que veo algo.$B$B¡Oye, tú no eres Hollee! ¿No habrás visto mi cepillo de piedra?$B$B¡Eso no importa ahora! Prometí a la Liga que enviaría el misterioso fósil que encontré. ¿Adónde se fue Hollee?$B$B¡Con todo lo que queda por hacer! En fin... ¿y dónde estará ese fósil misterioso? ¿Y mi cepillo...? ¿Y Hollee?$B$B¿Y tú quien eres? En realidad no importa, siempre que estés aquí para ayudar.$B$BAvísame cuando estés listo para empezar a buscar.', 0);
-- 1001 La caja mecánica 411
-- https://es.classic.wowhead.com/quest=1001
SET @ID := 1001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cubierta de la máquina está abierta y parece estar esperando a que introduzcas 3 ojos de trillador.', 0),
(@ID, 'esMX', 'La cubierta de la máquina está abierta y parece estar esperando a que introduzcas 3 ojos de trillador.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja mecánica cobra vida en cuanto introduces los ojos de trillador. Después de un lapso de tiempo, oyes una vocecilla familiar...$B$B"El vino de reptador es lo mejor..." *hip*$B$B"¿Eh? Oh, ¿ya la has arreglado? Vaya, sí que eres $grápido:rápida;. Dime, ¿quieres arreglar otra caja?"$B$BOyes lo que parece el sonido de un líquido vertiéndose en una copa y luego ruidos ansiosos de alguien tragando.', 0),
(@ID, 'esMX', 'La caja mecánica cobra vida en cuanto introduces los ojos de trillador. Después de un lapso de tiempo, oyes una vocecilla familiar...$B$B"El vino de reptador es lo mejor..." *hip*$B$B"¿Eh? Oh, ¿ya la has arreglado? Vaya, sí que eres $grápido:rápida;. Dime, ¿quieres arreglar otra caja?"$B$BOyes lo que parece el sonido de un líquido vertiéndose en una copa y luego ruidos ansiosos de alguien tragando.', 0);
-- 1580 Los electromuelles
-- https://es.classic.wowhead.com/quest=1580
SET @ID := 1580;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste algún electromuelle? Los necesito para continuar mis pruebas con el señuelo-pato...', 0),
(@ID, 'esMX', '¿Encontraste algún electromuelle? Los necesito para continuar mis pruebas con el señuelo-pato...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo creerlo! ¡Los has encontrado! ¡Eres el mejor pescador que he conocido en mi vida!$B$BGracias, $n. Y ten, acepta esto. Aunque eres tan bueno que probablemente no te hacen falta, te ayudarán.', 0),
(@ID, 'esMX', '¡No puedo creerlo! ¡Los has encontrado! ¡Eres el mejor pescador que he conocido en mi vida!$B$BGracias, $n. Y ten, acepta esto. Aunque eres tan bueno que probablemente no te hacen falta, te ayudarán.', 0);
-- 4681 Varado
-- https://es.classic.wowhead.com/quest=4681
SET @ID := 4681;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando hayas examinado los restos de la criatura que hay en el agua, al oeste de aquí, debería poder redactar un informe para el Templo de la Luna de Darnassus. Quizás entonces estemos más cerca de descubrir la razón por la que estas desafortunadas criaturas eligen acabar sus vidas encalladas en Costa Oscura.', 0),
(@ID, 'esMX', 'Cuando hayas examinado los restos de la criatura que hay en el agua, al oeste de aquí, debería poder redactar un informe para el Templo de la Luna de Darnassus. Quizás entonces estemos más cerca de descubrir la razón por la que estas desafortunadas criaturas eligen acabar sus vidas encalladas en Costa Oscura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sido una ayuda tremenda hoy. Ahora tenemos una buena oportunidad de descubrir el misterio, de saber por qué estas criaturas eligen encallarse en Costa Oscura. La idea de que podrían estar huyendo de Teldrassil es inquietante. Si encontraras más en tus viajes, házmelo saber. Nuestra investigación aquí apenas ha comenzado.$B$BPor favor, acepta esto como muestra de agradecimiento del Templo de la Luna, $n. ¡Gracias!', 0),
(@ID, 'esMX', 'Has sido una ayuda tremenda hoy. Ahora tenemos una buena oportunidad de descubrir el misterio, de saber por qué estas criaturas eligen encallarse en Costa Oscura. La idea de que podrían estar huyendo de Teldrassil es inquietante. Si encontraras más en tus viajes, házmelo saber. Nuestra investigación aquí apenas ha comenzado.$B$BPor favor, acepta esto como muestra de agradecimiento del Templo de la Luna, $n. ¡Gracias!', 0);
-- 1275 Investigaciones acerca de la corrupción
-- https://es.classic.wowhead.com/quest=1275
SET @ID := 1275;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tenga suficientes muestras, podré empezar a trabajar de verdad. Con los bulbos raquídeos corruptos de los sátiros y los nagass de las Cavernas Anegadas podré encontrar la correlación entre las mutaciones.$B$BQuizás, una vez identificada, podré impedir que la deformidad y el mal arraiguen más en los elfos de sangre.', 0),
(@ID, 'esMX', 'Cuando tenga suficientes muestras, podré empezar a trabajar de verdad. Con los bulbos raquídeos corruptos de los sátiros y los nagass de las Cavernas Anegadas podré encontrar la correlación entre las mutaciones.$B$BQuizás, una vez identificada, podré impedir que la deformidad y el mal arraiguen más en los elfos de sangre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has viajado lejos y sin duda, habrás afrontado grandes peligros.$B$BTus acciones son desinteresadas; $n; me ayudas con mi trabajo por el bien de todo Azeroth. Y te doy las gracias por todo lo que has hecho.$B$BAhora, si me perdonas, tengo mucho que hacer...', 0),
(@ID, 'esMX', 'Has viajado lejos y sin duda, habrás afrontado grandes peligros.$B$BTus acciones son desinteresadas; $n; me ayudas con mi trabajo por el bien de todo Azeroth. Y te doy las gracias por todo lo que has hecho.$B$BAhora, si me perdonas, tengo mucho que hacer...', 0);
-- 2178 Guiso de zancudo
-- https://es.classic.wowhead.com/quest=2178
SET @ID := 2178;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta olla está vacía y mi estómago también! ¿Por qué estás tardando tanto?', 0),
(@ID, 'esMX', '¡Esta olla está vacía y mi estómago también! ¿Por qué estás tardando tanto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¡Dime lo que piensas, $n!', 0),
(@ID, 'esMX', '¡Fantástico! ¡Dime lo que piensas, $n!', 0);
-- 4812 Agua en cascada
-- https://es.classic.wowhead.com/quest=4812
SET @ID := 4812;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cristal contrasta extrañamente con el escenario leñoso de Costa Oscura. Te parece oír un suave murmullo de su interior.', 0),
(@ID, 'esMX', 'El cristal contrasta extrañamente con el escenario leñoso de Costa Oscura. Te parece oír un suave murmullo de su interior.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has conseguido llegar una vez más al misterioso cristal. Retiras el tapón del tubo de agua de poza de la luna y viertes su contenido sobre el cristal. A medida que el agua se desliza por su entramado, ves que la superficie empieza a volverse transparente...', 0),
(@ID, 'esMX', 'Has conseguido llegar una vez más al misterioso cristal. Retiras el tapón del tubo de agua de poza de la luna y viertes su contenido sobre el cristal. A medida que el agua se desliza por su entramado, ves que la superficie empieza a volverse transparente...', 0);
-- 954 Bashal'Aran
-- https://es.classic.wowhead.com/quest=954
SET @ID := 954;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aah... Me pregunto a qué debo este increíblemente especial honor de disfrutar de la compañía de alguien como tú. Pues he de reconocer que si se compara con mi compañía actual –sin ánimo de ofender a mis anfitriones, los nobles grells y sátiros– tu presencia aquí podría considerarse una increíble mejora.$B$BPor favor, no permitas que mi zafia lengua te aleje. Han pasado años, incluso décadas, desde la última vez que gocé de compañía civilizada.', 0),
(@ID, 'esMX', 'Aah... Me pregunto a qué debo este increíblemente especial honor de disfrutar de la compañía de alguien como tú. Pues he de reconocer que si se compara con mi compañía actual –sin ánimo de ofender a mis anfitriones, los nobles grells y sátiros– tu presencia aquí podría considerarse una increíble mejora.$B$BPor favor, no permitas que mi zafia lengua te aleje. Han pasado años, incluso décadas, desde la última vez que gocé de compañía civilizada.', 0);
-- 958 Las herramientas de los Altonato
-- https://es.classic.wowhead.com/quest=958
SET @ID := 958;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ay, si el cataclismo que destruyó nuestro mundo hubiera destruido también las herramientas de su destrucción... Pero no fue así. Y debemos asegurarnos de que los horrores de nuestro pasado no se repitan en el futuro.', 0),
(@ID, 'esMX', 'Ay, si el cataclismo que destruyó nuestro mundo hubiera destruido también las herramientas de su destrucción... Pero no fue así. Y debemos asegurarnos de que los horrores de nuestro pasado no se repitan en el futuro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque seguramente es producto de mi imaginación, casi me parece sentir la corrupción de la magia de los altonatos en estas reliquias. Haré que sean destruidas, para que el mal que duerme en ellas nunca vuelva a aflorar.', 0),
(@ID, 'esMX', 'Aunque seguramente es producto de mi imaginación, casi me parece sentir la corrupción de la magia de los altonatos en estas reliquias. Haré que sean destruidas, para que el mal que duerme en ellas nunca vuelva a aflorar.', 0);
-- 1442 La búsqueda de la gema Kor
-- https://es.classic.wowhead.com/quest=1442
SET @ID := 1442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Confiaría menos en alguien que no esté en un camino sagrado si vinieran a preguntar por una gema Kor. Pero confío en los de tu especie más que en algunos de los míos. No juzgo toda su orden basándome en las acciones de solo uno de los caídos.', 0),
(@ID, 'esMX', 'Confiaría menos en alguien que no esté en un camino sagrado si vinieran a preguntar por una gema Kor. Pero confío en los de tu especie más que en algunos de los míos. No juzgo toda su orden basándome en las acciones de solo uno de los caídos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ésta es, de hecho, la gema que Fontana desea, pero antes de que pueda entregársela, debe purificarse de la corrupción: las mujeres naga imbuyen las gemas con poder, eso es cierto, pero de su propia clase malvada.$B$BHazle saber a Fontana que su poder está intacto y que debería funcionar bien para cualquier ritual del que desee que forme parte.$B$BEspero que sepas lo que estás haciendo, $c, esta gema no es un simple objeto.', 0),
(@ID, 'esMX', 'Ésta es, de hecho, la gema que Fontana desea, pero antes de que pueda entregársela, debe purificarse de la corrupción: las mujeres naga imbuyen las gemas con poder, eso es cierto, pero de su propia clase malvada.$B$BHazle saber a Fontana que su poder está intacto y que debería funcionar bien para cualquier ritual del que desee que forme parte.$B$BEspero que sepas lo que estás haciendo, $c, esta gema no es un simple objeto.', 0);

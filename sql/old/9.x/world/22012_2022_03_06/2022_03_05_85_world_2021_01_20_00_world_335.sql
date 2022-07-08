-- 2281 Cita en Crestagrana
-- https://es.classic.wowhead.com/quest=2281
SET @ID := 2281;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, entonces tus dedos están un poco rechonchos, ¿eh? No te preocupes, $n, he convertido a ladrones más inútiles que tú en pícaros consumados.', 0),
(@ID, 'esMX', 'Ah, entonces tus dedos están un poco rechonchos, ¿eh? No te preocupes, $n, he convertido a ladrones más inútiles que tú en pícaros consumados.', 0);
-- 2282 Molino de Alther
-- https://es.classic.wowhead.com/quest=2282
SET @ID := 2282;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te había hablado de los orcos?$B$BHe oído que andan por el molino.', 0),
(@ID, 'esMX', '¿Te había hablado de los orcos?$B$BHe oído que andan por el molino.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya la has abierto? Buen trabajo, $n.$B$BSi te mueres, sabremos que fue por estupidez y no por falta de experiencia.', 0),
(@ID, 'esMX', '¿Ya la has abierto? Buen trabajo, $n.$B$BSi te mueres, sabremos que fue por estupidez y no por falta de experiencia.', 0);
-- 2283 La recuperación del collar
-- https://es.classic.wowhead.com/quest=2283
SET @ID := 2283;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el collar? ¡Si no hay collar, no hay recompensa!', 0),
(@ID, 'esMX', '¿Tienes el collar? ¡Si no hay collar, no hay recompensa!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo huelo desde aquí... ¡Déjame ver!$B$BPero... ¿Me quieres tomar el pelo o qué? ¡Faltan las gemas! ¿Pensabas que no nos íbamos a dar cuenta? Hasta Malton se dio cuenta.$B$BBueno, a lo mejor no las has robado, pero el collar no vale nada sin las gemas. ¡Encuéntralas y termina el trabajo!', 0),
(@ID, 'esMX', 'Lo huelo desde aquí... ¡Déjame ver!$B$BPero... ¿Me quieres tomar el pelo o qué? ¡Faltan las gemas! ¿Pensabas que no nos íbamos a dar cuenta? Hasta Malton se dio cuenta.$B$BBueno, a lo mejor no las has robado, pero el collar no vale nada sin las gemas. ¡Encuéntralas y termina el trabajo!', 0);
-- 2284 La recuperación del collar, 2ª parte
-- https://es.classic.wowhead.com/quest=2284
SET @ID := 2284;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has encontrado los restos del paladín del que habló Dran. Encuentras un diario, muy estropeado y cubierto de sangre. Lo que consigues leer está escrito en humano, te parece.$B$BTendrás que encontrar a alguien que lo traduzca.', 0),
(@ID, 'esMX', 'Has encontrado los restos del paladín del que habló Dran. Encuentras un diario, muy estropeado y cubierto de sangre. Lo que consigues leer está escrito en humano, te parece.$B$BTendrás que encontrar a alguien que lo traduzca.', 0);
-- 2298 Una regia sacudida
-- https://es.classic.wowhead.com/quest=2298
SET @ID := 2298;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Siempre es bueno tener a uno de $glos pícaros:las pícaras; de Hulfdan entre nuestras filas!', 0),
(@ID, 'esMX', '¡Siempre es bueno tener a uno de $glos pícaros:las pícaras; de Hulfdan entre nuestras filas!', 0);
-- 2299 ¡Ve a hablar con Hulfdan!
-- https://es.classic.wowhead.com/quest=2299
SET @ID := 2299;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Baja la voz, $n, los guardias pueden escucharte.', 0),
(@ID, 'esMX', 'Baja la voz, $n, los guardias pueden escucharte.', 0);
-- 2300 IV:7
-- https://es.classic.wowhead.com/quest=2300
SET @ID := 2300;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás listo para empezar a trabajar o necesitas pegarte una siesta antes de empezar?', 0),
(@ID, 'esMX', '¿Estás listo para empezar a trabajar o necesitas pegarte una siesta antes de empezar?', 0);
-- 2318 La traducción del diario
-- https://es.classic.wowhead.com/quest=2318
SET @ID := 2318;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gPoderoso:Poderosa; $c, sé a qué has venido a las Tierras Inhóspitas. Me necesitas por mi vasto conocimiento de otras lenguas y estás buscando las piezas del collar que encontraste en Uldaman.$B$B¿Sorprendido? No lo estés tanto, mi trabajo consiste en averiguar estas cosas. Así pues, centrémonos en el diario y dime qué recibiré a cambio de su traducción. Créeme, no encontrarás a nadie más que pueda hacerlo.$B$BEs más, te haré una oferta mejor que la de Dran Droffers de modo que todavía puedas cumplir su trato. ¿Qué dices?', 0),
(@ID, 'esMX', '$gPoderoso:Poderosa; $c, sé a qué has venido a las Tierras Inhóspitas. Me necesitas por mi vasto conocimiento de otras lenguas y estás buscando las piezas del collar que encontraste en Uldaman.$B$B¿Sorprendido? No lo estés tanto, mi trabajo consiste en averiguar estas cosas. Así pues, centrémonos en el diario y dime qué recibiré a cambio de su traducción. Créeme, no encontrarás a nadie más que pueda hacerlo.$B$BEs más, te haré una oferta mejor que la de Dran Droffers de modo que todavía puedas cumplir su trato. ¿Qué dices?', 0);
-- 2338 La traducción del diario
-- https://es.classic.wowhead.com/quest=2338
SET @ID := 2338;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has pensado en ello, ¿verdad? Eres inteligente, $c, si aceptas este trato, ambos conseguiremos lo que queremos, y Rescates Droffers e Hijos pensará que tienen lo que buscan.', 0),
(@ID, 'esMX', 'Has pensado en ello, ¿verdad? Eres inteligente, $c, si aceptas este trato, ambos conseguiremos lo que queremos, y Rescates Droffers e Hijos pensará que tienen lo que buscan.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se reconoce un buen negocio cuando lo ves, sabía que podía contar contigo.$B$BSolo será un momento mientras lanzo un hechizo para traducir rápidamente la lengua humana en una forma que entenderás. Soy un trol de palabra, pregúntale a cualquiera de la Horda por Jarkal Musgofusión. Bien, empecemos...', 0),
(@ID, 'esMX', 'Se reconoce un buen negocio cuando lo ves, sabía que podía contar contigo.$B$BSolo será un momento mientras lanzo un hechizo para traducir rápidamente la lengua humana en una forma que entenderás. Soy un trol de palabra, pregúntale a cualquiera de la Horda por Jarkal Musgofusión. Bien, empecemos...', 0);
-- 2339 Encuentra las gemas y la fuente de alimentación
-- https://es.classic.wowhead.com/quest=2339
SET @ID := 2339;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te espera otro viaje a las profundidades de Uldaman si no tienes las gemas y una fuente de energía capaz de canalizar el poder mágico de nuevo hacia el collar.$B$BRecuperarás las gemas para entregárselas a los matones de Orgrimmar; me quedaré con la fuente de energía, puesto que será lo que haga funcionar el collar para empezar...', 0),
(@ID, 'esMX', 'Te espera otro viaje a las profundidades de Uldaman si no tienes las gemas y una fuente de energía capaz de canalizar el poder mágico de nuevo hacia el collar.$B$BRecuperarás las gemas para entregárselas a los matones de Orgrimmar; me quedaré con la fuente de energía, puesto que será lo que haga funcionar el collar para empezar...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo de primera, $c. Ahora veremos los bonitos frutos de nuestro desvío. He acabado con el collar y confío en poder reproducir el proceso de construcción sin problemas.$B$BPero primero usaré un conjuro especialmente diseñado para analizar rápidamente esas gemas antes de que te las lleves con el collar de vuelta a Orgrimmar. Solo será un momento.', 0),
(@ID, 'esMX', 'Un trabajo de primera, $c. Ahora veremos los bonitos frutos de nuestro desvío. He acabado con el collar y confío en poder reproducir el proceso de construcción sin problemas.$B$BPero primero usaré un conjuro especialmente diseñado para analizar rápidamente esas gemas antes de que te las lleves con el collar de vuelta a Orgrimmar. Solo será un momento.', 0);
-- 2340 Entregar las gemas
-- https://es.classic.wowhead.com/quest=2340
SET @ID := 2340;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, mira quién tenemos ahí! Te ha llevado un tiempo llegar hasta aquí, ¿eh? ¡Esperemos que no me hayas hecho perder el tiempo! No te pagaré a menos que hayas traído todo lo que te encargué. Y créeme, ¡lo comprobaremos todo dos y hasta tres veces!', 0),
(@ID, 'esMX', '¡Vaya, mira quién tenemos ahí! Te ha llevado un tiempo llegar hasta aquí, ¿eh? ¡Esperemos que no me hayas hecho perder el tiempo! No te pagaré a menos que hayas traído todo lo que te encargué. Y créeme, ¡lo comprobaremos todo dos y hasta tres veces!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, aquí está todo. Oye, ¿te importa si nos quedamos también con la bolsa? ¿No? ¡Gracias, de verdad! ¡Ja!$B$B¡Este collar será nuestra mayor botín! Pero no te pongas así, seguro que el collar no te sentaría bien. ¡Toma que toma!$B$BUn trato es un trato, aquí tienes tu parte por el rescate. Ya hemos rematado el negocio por ahora; vuelve más tarde por si tuviéramos más trabajo para ti. Hasta entonces, ¡andando!', 0),
(@ID, 'esMX', 'Sí, aquí está todo. Oye, ¿te importa si nos quedamos también con la bolsa? ¿No? ¡Gracias, de verdad! ¡Ja!$B$B¡Este collar será nuestra mayor botín! Pero no te pongas así, seguro que el collar no te sentaría bien. ¡Toma que toma!$B$BUn trato es un trato, aquí tienes tu parte por el rescate. Ya hemos rematado el negocio por ahora; vuelve más tarde por si tuviéramos más trabajo para ti. Hasta entonces, ¡andando!', 0);
-- 2341 La recuperación del collar, 3ª parte
-- https://es.classic.wowhead.com/quest=2341
SET @ID := 2341;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La fuente de energía que me diste superó todas las expectativas que tenía. Pude hacernos un collar para ti y para mí, y me sobra lo suficiente para hacer al menos tres más. Obtendrán bastante dinero, con Droffers y Son Salvage sin saberlo.$B$BAquí tienes, $gamigo:amiga;. Te doy las gracias por un trabajo espléndido... y algo muy especial por tus molestias.', 0),
(@ID, 'esMX', 'La fuente de energía que me diste superó todas las expectativas que tenía. Pude hacernos un collar para ti y para mí, y me sobra lo suficiente para hacer al menos tres más. Obtendrán bastante dinero, con Droffers y Son Salvage sin saberlo.$B$BAquí tienes, $gamigo:amiga;. Te doy las gracias por un trabajo espléndido... y algo muy especial por tus molestias.', 0);
-- 2342 Los tesoros reclamados
-- https://es.classic.wowhead.com/quest=2342
SET @ID := 2342;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca acabaré con estos murciélagos que se mofan de mí y de mi escoba. ¡Dime que has reclamado el tesoro de mi familia! Te he ofrecido mis piezas de plata... ¿es que no es suficiente?', 0),
(@ID, 'esMX', 'Nunca acabaré con estos murciélagos que se mofan de mí y de mi escoba. ¡Dime que has reclamado el tesoro de mi familia! Te he ofrecido mis piezas de plata... ¿es que no es suficiente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto ya es otra cosa! No hay duda de que te mereces cada pieza de plata que te he dado.$B$B¿Me estáis escuchando, repugnantes murciélagos? ¡Ahora tengo el arma elegida por la familia Garrett! ¡¡Temblad, murciélagos, temblad!!', 0),
(@ID, 'esMX', '¡Esto ya es otra cosa! No hay duda de que te mereces cada pieza de plata que te he dado.$B$B¿Me estáis escuchando, repugnantes murciélagos? ¡Ahora tengo el arma elegida por la familia Garrett! ¡¡Temblad, murciélagos, temblad!!', 0);
-- 2358 Cuernos de Nez'ra
-- https://es.classic.wowhead.com/quest=2358
SET @ID := 2358;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los cuernos del príncipe demonio?', 0),
(@ID, 'esMX', '¿Tienes los cuernos del príncipe demonio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Negarle a Ravenholdt el artefacto sería negar la propia existencia. Bien hecho, $c. Aún puedes caminar entre los asesinos de Ravenholdt.$B$BCuando era un joven pícaro aventurero en Costa Oscura, descubrí un té que repone energía en combate. Me ha servido bien a lo largo de los años y ahora te paso una muestra del té de cardo. ¡Bébelo cuando te canses, $n, y lucha con vigor una vez más!', 0),
(@ID, 'esMX', 'Negarle a Ravenholdt el artefacto sería negar la propia existencia. Bien hecho, $c. Aún puedes caminar entre los asesinos de Ravenholdt.$B$BCuando era un joven pícaro aventurero en Costa Oscura, descubrí un té que repone energía en combate. Me ha servido bien a lo largo de los años y ahora te paso una muestra del té de cardo. ¡Bébelo cuando te canses, $n, y lucha con vigor una vez más!', 0);
-- 2361 Restaurar el collar
-- https://es.classic.wowhead.com/quest=2361
SET @ID := 2361;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con mucho gusto te doy este collar, poderoso $c. Me has prestado un servicio invaluable y por ello te lo agradezco. Úsalo con orgullo y asegúrate de mencionar en voz alta y repetidamente quién lo hizo para tí.$B$BAdemás, si pudieras indicar el hecho de que realmente no está maldito, sería genial.', 0),
(@ID, 'esMX', 'Con mucho gusto te doy este collar, poderoso $c. Me has prestado un servicio invaluable y por ello te lo agradezco. Úsalo con orgullo y asegúrate de mencionar en voz alta y repetidamente quién lo hizo para tí.$B$BAdemás, si pudieras indicar el hecho de que realmente no está maldito, sería genial.', 0);
-- 2378 Encuentra a los Mano Destrozada
-- https://es.classic.wowhead.com/quest=2378
SET @ID := 2378;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que tú eres a quien han elegido nuestros poderosos aliados para venir a ver a Shenthul? Qué aburrido...', 0),
(@ID, 'esMX', '¿Así que tú eres a quien han elegido nuestros poderosos aliados para venir a ver a Shenthul? Qué aburrido...', 0);
-- 2379 Zando'zan
-- https://es.classic.wowhead.com/quest=2379
SET @ID := 2379;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puede que Zando\'zan se equivocara; te pide disculpas.', 0),
(@ID, 'esMX', 'Puede que Zando\'zan se equivocara; te pide disculpas.', 0);
-- 2380 Ve a Orgrimmar
-- https://es.classic.wowhead.com/quest=2380
SET @ID := 2380;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es importante que la Mano Destrozada permanezca alerta ante los cambios que Thrall desea provocar en la Horda. Nuestro número por sí mismo no serán suficiente para superar su gobierno: se debe dominar el sigilo y el engaño.', 0),
(@ID, 'esMX', 'Es importante que la Mano Destrozada permanezca alerta ante los cambios que Thrall desea provocar en la Horda. Nuestro número por sí mismo no serán suficiente para superar su gobierno: se debe dominar el sigilo y el engaño.', 0);
-- 2381 Saquear a los saqueadores
-- https://es.classic.wowhead.com/quest=2381
SET @ID := 2381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, por lo menos conservas todos tus miembros. ¿Has encontrado el tesoro?', 0),
(@ID, 'esMX', 'Bueno, por lo menos conservas todos tus miembros. ¿Has encontrado el tesoro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¡Improbable! ¡Sencillamente asombroso! Tienes mucho talento, $n. ¡O eso o eres el ser vivo más afortunado!$B$BAquí tienes tu parte del pago. Estoy seguro de que le sacarás más partido que yo.', 0),
(@ID, 'esMX', '¡Increíble! ¡Improbable! ¡Sencillamente asombroso! Tienes mucho talento, $n. ¡O eso o eres el ser vivo más afortunado!$B$BAquí tienes tu parte del pago. Estoy seguro de que le sacarás más partido que yo.', 0);
-- 2382 Desdio de Trinquete
-- https://es.classic.wowhead.com/quest=2382
SET @ID := 2382;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Para qué? Los últimos 5 que me envió el trol acabaron de cena de los tiburones. Espero que a ti te vaya mejor.', 0),
(@ID, 'esMX', '¿Para qué? Los últimos 5 que me envió el trol acabaron de cena de los tiburones. Espero que a ti te vaya mejor.', 0);
-- 2383 Papiro simple
-- https://es.classic.wowhead.com/quest=2383
SET @ID := 2383;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es lo que tienes ahí? ¿Un pergamino? No eres un erudito... espero...', 0),
(@ID, 'esMX', '¿Qué es lo que tienes ahí? ¿Un pergamino? No eres un erudito... espero...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, mi pergamino. Oí que habías venido al Valle, $n. Me alegra saber que lo has conseguido... esperemos que sobrevivas a todos los retos que te aguardan. Como dije, ven a verme cuando crezca tu poder, haré todo lo que pueda por instruirte en las artes $gdel:de la; $c.$B$BBuena suerte, $n, y vuelve a verme cuando creas que estás $gpreparado:preparada;.', 0),
(@ID, 'esMX', 'Ah, mi pergamino. Oí que habías venido al Valle, $n. Me alegra saber que lo has conseguido... esperemos que sobrevivas a todos los retos que te aguardan. Como dije, ven a verme cuando crezca tu poder, haré todo lo que pueda por instruirte en las artes $gdel:de la; $c.$B$BBuena suerte, $n, y vuelve a verme cuando creas que estás $gpreparado:preparada;.', 0);
-- 2439 Los discos de platino
-- https://es.classic.wowhead.com/quest=2439
SET @ID := 2439;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; a Las Arcas de Forjaz, $n. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; a Las Arcas de Forjaz, $n. ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un vale de la Liga de Exploradores, y además muy bueno.$B$BLa Liga de Exploradores me autoriza a ofrecerte una compensación directamente de sus arcas. Debes recibir este objeto y puedes elegir entre cinco pociones curativas superiores o cinco pociones de maná superiores como recompensa.', 0),
(@ID, 'esMX', 'Ah, un vale de la Liga de Exploradores, y además muy bueno.$B$BLa Liga de Exploradores me autoriza a ofrecerte una compensación directamente de sus arcas. Debes recibir este objeto y puedes elegir entre cinco pociones curativas superiores o cinco pociones de maná superiores como recompensa.', 0);
-- 2440 Los discos de platino
-- https://es.classic.wowhead.com/quest=2440
SET @ID := 2440;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos, $c! ¿Estás aquí para recibir instrucción en alquimia o quizás para otra cosa?', 0),
(@ID, 'esMX', '¡Saludos, $c! ¿Estás aquí para recibir instrucción en alquimia o quizás para otra cosa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, $n. En vista de lo que te ha dado, debes haberle caído muy bien a Sabio Buscaverdad. Tienes derecho a elegir como recompensa 5 pociones excelentes de curación o 5 pociones superiores de maná de su alijo de pociones.', 0),
(@ID, 'esMX', 'Vaya, $n. En vista de lo que te ha dado, debes haberle caído muy bien a Sabio Buscaverdad. Tienes derecho a elegir como recompensa 5 pociones excelentes de curación o 5 pociones superiores de maná de su alijo de pociones.', 0);
-- 2458 Agente encubierto
-- https://es.classic.wowhead.com/quest=2458
SET @ID := 2458;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de ver agentes de la Mano Destrozada, pero lo de las bengalas ha sido excesivo.$B$BSi quieres verme otra vez, sopla 2 veces este silbato.', 0),
(@ID, 'esMX', 'Me alegro de ver agentes de la Mano Destrozada, pero lo de las bengalas ha sido excesivo.$B$BSi quieres verme otra vez, sopla 2 veces este silbato.', 0);
-- 2460 El saludo de los Mano Destrozada
-- https://es.classic.wowhead.com/quest=2460
SET @ID := 2460;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Sigue, sigue.', 0),
(@ID, 'esMX', 'Muy bien, $n. Sigue, sigue.', 0);
-- 2478 Misión: Posible, pero no probable
-- https://es.classic.wowhead.com/quest=2478
SET @ID := 2478;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes, $n?', 0),
(@ID, 'esMX', '¿Qué noticias traes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pobre Burbujita, era un buen agente, uno de los mejores. Por desgracia, es el precio que pagamos, $n. Ser un agente de campo de la Mano Destrozada es un trabajo arriesgado.$B$BHas cumplido con tu deber, $c. Sería una lástima que no vivieras para volver a colaborar con nosotros.', 0),
(@ID, 'esMX', 'Pobre Burbujita, era un buen agente, uno de los mejores. Por desgracia, es el precio que pagamos, $n. Ser un agente de campo de la Mano Destrozada es un trabajo arriesgado.$B$BHas cumplido con tu deber, $c. Sería una lástima que no vivieras para volver a colaborar con nosotros.', 0);
-- 2479 La ayuda de Hinott
-- https://es.classic.wowhead.com/quest=2479
SET @ID := 2479;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto?', 0),
(@ID, 'esMX', '¿Qué es esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué palidez tan deliciosa la tuya, $c. ¿Y qué es ese terrible olor?', 0),
(@ID, 'esMX', 'Qué palidez tan deliciosa la tuya, $c. ¿Y qué es ese terrible olor?', 0);
-- 2480 La ayuda de Hinott
-- https://es.classic.wowhead.com/quest=2480
SET @ID := 2480;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La cura está lista! Bebe este antídoto para detener la demencia. Sin embargo, no puedo hacer nada con el olor.', 0),
(@ID, 'esMX', '¡La cura está lista! Bebe este antídoto para detener la demencia. Sin embargo, no puedo hacer nada con el olor.', 0);
-- 2501 Componentes de Tierras Inhóspitas II
-- https://es.classic.wowhead.com/quest=2501
SET @ID := 2501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has usado los vasos para conseguirme la sangre de dragón guardián quemada que necesito? Sí, sé que es una tarea peligrosa... pero la receta de mi bebida reconstituyente aguarda su éxito. Riesgo y recompensa, $gamigo mío:amiga mía;... riesgo y recompensa...', 0),
(@ID, 'esMX', '¿Has usado los vasos para conseguirme la sangre de dragón guardián quemada que necesito? Sí, sé que es una tarea peligrosa... pero la receta de mi bebida reconstituyente aguarda su éxito. Riesgo y recompensa, $gamigo mío:amiga mía;... riesgo y recompensa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De un alquimista a otro, te saludo. Toma esta receta y apréndela. Que te traiga el éxito y las recompensas que me ha brindado a lo largo de los años.', 0),
(@ID, 'esMX', 'De un alquimista a otro, te saludo. Toma esta receta y apréndela. Que te traiga el éxito y las recompensas que me ha brindado a lo largo de los años.', 0);
-- 2521 Al servicio de Kum'isha
-- https://es.classic.wowhead.com/quest=2521
SET @ID := 2521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He dedicado mi vida a la búsqueda de esferas draenetistas perfectas. ¡Toda una vida, $r!', 0),
(@ID, 'esMX', 'He dedicado mi vida a la búsqueda de esferas draenetistas perfectas. ¡Toda una vida, $r!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me engañan mis ojos? ¡Imposible! ¿Dónde... cómo...?$B$BQuizás ahora se pueda abrir una grieta, devolviéndonos a nuestra patria.', 0),
(@ID, 'esMX', '¿Me engañan mis ojos? ¡Imposible! ¿Dónde... cómo...?$B$BQuizás ahora se pueda abrir una grieta, devolviéndonos a nuestra patria.', 0);
-- 2522 Los esfuerzos de Kum'isha
-- https://es.classic.wowhead.com/quest=2522
SET @ID := 2522;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado otra esfera draenetista perfecta?', 0),
(@ID, 'esMX', '¿Has encontrado otra esfera draenetista perfecta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Simplemente asombroso. Había dudado que pudieras encontrar otra esfera, pero aquí está, palpitando en mis manos.$B$B¡Bien hecho, $n!$B$BSi encuentras más, y creo que esto es imposible, tráemelas y te recompensaré de nuevo.', 0),
(@ID, 'esMX', 'Simplemente asombroso. Había dudado que pudieras encontrar otra esfera, pero aquí está, palpitando en mis manos.$B$B¡Bien hecho, $n!$B$BSi encuentras más, y creo que esto es imposible, tráemelas y te recompensaré de nuevo.', 0);
-- Melodía corrupta
-- 2523, 2878, 3363, 4113, 4114, 4116, 4118, 4401, 4464, 4465
-- https://es.classic.wowhead.com/quest=2523
DELETE FROM `quest_request_items_locale` WHERE `id` IN(2523, 2878, 3363, 4113, 4114, 4116, 4118, 4401, 4464, 4465) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(2523, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(2878, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(3363, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4113, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4114, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4116, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4118, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4401, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4464, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4465, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(2523, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(2878, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(3363, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4113, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4114, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4116, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4118, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4401, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4464, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4465, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una melodía. De la planta emana un olor acre y malsano. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2523, 2878, 3363, 4113, 4114, 4116, 4118, 4401, 4464, 4465) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2523, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(2878, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(3363, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4113, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4114, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4116, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4118, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4401, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4464, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4465, 'esES', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(2523, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(2878, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(3363, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4113, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4114, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4116, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4118, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4401, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4464, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4465, 'esMX', 'Aplicas un poco de bálsamo de planta Cenarion a la melodía. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0);

-- 2972 La justicia del castigo
-- https://es.classic.wowhead.com/quest=2972
SET @ID := 2972;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé $gbienvenido, hijo:bienvenida, hija;. Siempre es un placer recibir a poderosos aventureros en el Templo. Si tienes tiempo, ¿podrás compartir alguna de tus historias con los aventureros más jóvenes? Sé que muchos de ellos sacarían provecho de tu sabiduría.$B$BAy, perdona mi mala educación. Has venido al Templo en busca de ayuda y yo abuso de tu amabilidad. Te ruego que me perdones. Dime qué podemos hacer por ti los siervos de la Luz.', 0),
(@ID, 'esMX', 'Sé $gbienvenido, hijo:bienvenida, hija;. Siempre es un placer recibir a poderosos aventureros en el Templo. Si tienes tiempo, ¿podrás compartir alguna de tus historias con los aventureros más jóvenes? Sé que muchos de ellos sacarían provecho de tu sabiduría.$B$BAy, perdona mi mala educación. Has venido al Templo en busca de ayuda y yo abuso de tu amabilidad. Te ruego que me perdones. Dime qué podemos hacer por ti los siervos de la Luz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una historia increíble, $n. Nos reconforta saber que no solo has ayudado a los dragonantes, sino también a una de nuestras sacerdotisas. Jer\'kai acertó al enviarte a mí. Yo me aseguraré de que le sea devuelto su anillo. Tengo exploradores de camino a Feralas. Haré que investiguen esto durante su misión.$B$BGracias otra vez. Y, por favor, estás en tu casa.', 0),
(@ID, 'esMX', 'Es una historia increíble, $n. Nos reconforta saber que no solo has ayudado a los dragonantes, sino también a una de nuestras sacerdotisas. Jer\'kai acertó al enviarte a mí. Yo me aseguraré de que le sea devuelto su anillo. Tengo exploradores de camino a Feralas. Haré que investiguen esto durante su misión.$B$BGracias otra vez. Y, por favor, estás en tu casa.', 0);
-- 2973 El lustre de una nueva capa
-- https://es.classic.wowhead.com/quest=2973
SET @ID := 2973;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los duendes dardo pueden ser criaturas muy peligrosas si se les provoca. Ten cuidado cuando trates con ellos, $c. Y ten mucho más cuidado con los elfos de la noche que pueda haber por la zona. Esos molestos seres tienen por costumbre acechar en los bosques también.$B$BCuando tengas alas suficientes, dímelo. ¡Te recompensaré bien!', 0),
(@ID, 'esMX', 'Los duendes dardo pueden ser criaturas muy peligrosas si se les provoca. Ten cuidado cuando trates con ellos, $c. Y ten mucho más cuidado con los elfos de la noche que pueda haber por la zona. Esos molestos seres tienen por costumbre acechar en los bosques también.$B$BCuando tengas alas suficientes, dímelo. ¡Te recompensaré bien!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, $c! Estas nos vienen de maravilla. Hay suficientes para hacerle la capa a Korrin, ¡incluso puede que sobren! Gracias.$B$BEspero que tu viaje no fuera demasiado peligroso. Feralas no es conocido por su compasión precisamente, pero está claro que no te ha ido tan mal.$B$BGracias otra vez, $c.', 0),
(@ID, 'esMX', '¡Estupendo, $c! Estas nos vienen de maravilla. Hay suficientes para hacerle la capa a Korrin, ¡incluso puede que sobren! Gracias.$B$BEspero que tu viaje no fuera demasiado peligroso. Feralas no es conocido por su compasión precisamente, pero está claro que no te ha ido tan mal.$B$BGracias otra vez, $c.', 0);
-- 2974 Un descubrimiento siniestro
-- https://es.classic.wowhead.com/quest=2974
SET @ID := 2974;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escucha bien lo que te digo, $c, el clan Tótem Siniestro es malvado. Si sabes dónde están, tienes que volver y atacarles. Tienes que asestar tú el primer golpe... antes de que vengan a nuestras tierras y arrasen nuestros poblados y saqueen nuestras tierras.', 0),
(@ID, 'esMX', 'Escucha bien lo que te digo, $c, el clan Tótem Siniestro es malvado. Si sabes dónde están, tienes que volver y atacarles. Tienes que asestar tú el primer golpe... antes de que vengan a nuestras tierras y arrasen nuestros poblados y saqueen nuestras tierras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son unos buenos cuernos, $c. Buen trabajo. Dámelos. Y no te preocupes, me aseguraré de hablar con Belgrom en cuanto regresemos a Orgrimmar. Ya me has ayudado dos veces y por eso te doy mi marca. ¡Quizás pueda ayudarte en un futuro! Buena suerte.', 0),
(@ID, 'esMX', 'Son unos buenos cuernos, $c. Buen trabajo. Dámelos. Y no te preocupes, me aseguraré de hablar con Belgrom en cuanto regresemos a Orgrimmar. Ya me has ayudado dos veces y por eso te doy mi marca. ¡Quizás pueda ayudarte en un futuro! Buena suerte.', 0);
-- 2975 Los ogros de Feralas
-- https://es.classic.wowhead.com/quest=2975
SET @ID := 2975;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muévete rápido, $n. ¿O la tarea que solicité es demasiado difícil?', 0),
(@ID, 'esMX', 'Muévete rápido, $n. ¿O la tarea que solicité es demasiado difícil?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. La tierra se curará con el tiempo. No podemos rendirnos.', 0),
(@ID, 'esMX', 'Excelente, $n. La tierra se curará con el tiempo. No podemos rendirnos.', 0);
-- 2976 Un descubrimiento siniestro
-- https://es.classic.wowhead.com/quest=2976
SET @ID := 2976;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Rapidito, $c, tengo mucho que hacer hoy.', 0),
(@ID, 'esMX', 'Rapidito, $c, tengo mucho que hacer hoy.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Los Tótem Siniestro?! Esto es interesante. ¿Dices que te los encontraste mientras cazabas en Feralas? ¿De verdad?$B$BLos míos querrán oír tus noticias, $c. Cuéntame más detalles. Yo iré contando tus monedas mientras lo haces.$B$BY antes de irte, debes saber que te agradezco la información que me has proporcionado.', 0),
(@ID, 'esMX', '¡¿Los Tótem Siniestro?! Esto es interesante. ¿Dices que te los encontraste mientras cazabas en Feralas? ¿De verdad?$B$BLos míos querrán oír tus noticias, $c. Cuéntame más detalles. Yo iré contando tus monedas mientras lo haces.$B$BY antes de irte, debes saber que te agradezco la información que me has proporcionado.', 0);
-- 2977 Regresa a Forjaz
-- https://es.classic.wowhead.com/quest=2977
SET @ID := 2977;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Les has sacado provecho a los discos o acabaste arando en el mar?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Les has sacado provecho a los discos o acabaste arando en el mar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te faltaban algunos discos? Vaya, es curioso pero parece que los Discos de Norgannon son solo una pieza más del conjunto; como las llaves de un llavero, si prefieres.$B$BSi encontramos las Placas de Uldum, ¡podremos por fin acceder al mismísimo complejo de Uldum! Imagínatelo, explorar el lugar en el que trabajaron los Creadores sin necesidad de utilizar una gran pala!$B$BY con esto no quiero decir que tenga algo de malo utilizar palas, cavar y todo eso.', 0),
(@ID, 'esMX', '¿Te faltaban algunos discos? Vaya, es curioso pero parece que los Discos de Norgannon son solo una pieza más del conjunto; como las llaves de un llavero, si prefieres.$B$BSi encontramos las Placas de Uldum, ¡podremos por fin acceder al mismísimo complejo de Uldum! Imagínatelo, explorar el lugar en el que trabajaron los Creadores sin necesidad de utilizar una gran pala!$B$BY con esto no quiero decir que tenga algo de malo utilizar palas, cavar y todo eso.', 0);
-- 2978 El pergamino Gordunni
-- https://es.classic.wowhead.com/quest=2978
SET @ID := 2978;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso?', 0),
(@ID, 'esMX', '¿Qué es eso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este pergamino... ¿Dices que lo encontraste en la Avanzada Gordunni?', 0),
(@ID, 'esMX', 'Este pergamino... ¿Dices que lo encontraste en la Avanzada Gordunni?', 0);
-- 2979 Una ceremonia oscura
-- https://es.classic.wowhead.com/quest=2979
SET @ID := 2979;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos que descubrir por qué están aquí los Gordunni, $n.', 0),
(@ID, 'esMX', 'Tenemos que descubrir por qué están aquí los Gordunni, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este orbe nos proporcionará más información sobre los Gordunni... información que utilizaremos para planear su caída, $n.', 0),
(@ID, 'esMX', 'Este orbe nos proporcionará más información sobre los Gordunni... información que utilizaremos para planear su caída, $n.', 0);
-- 2980 Los ogros de Feralas
-- https://es.classic.wowhead.com/quest=2980
SET @ID := 2980;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado las ruinas, $n?', 0),
(@ID, 'esMX', '¿Has encontrado las ruinas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado que se puede confiar en ti, $n.', 0),
(@ID, 'esMX', 'Has demostrado que se puede confiar en ti, $n.', 0);
-- 2981 Una amenaza en Feralas
-- https://es.classic.wowhead.com/quest=2981
SET @ID := 2981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía Belgrom. Pues llegas justo a tiempo, $r.$B$BDeja que te explique la situación y luego decides si estás a la altura del desafío... Claro que si te envía Belgrom, es evidente que valor no te falta.', 0),
(@ID, 'esMX', 'Así que te envía Belgrom. Pues llegas justo a tiempo, $r.$B$BDeja que te explique la situación y luego decides si estás a la altura del desafío... Claro que si te envía Belgrom, es evidente que valor no te falta.', 0);
-- 2982 Las Altas Tierras Salvajes
-- https://es.classic.wowhead.com/quest=2982
SET @ID := 2982;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está atento a los Gordunni, $n. Su magia parece causar estragos en la misma tierra en la que se encuentran.', 0),
(@ID, 'esMX', 'Está atento a los Gordunni, $n. Su magia parece causar estragos en la misma tierra en la que se encuentran.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te agradezco mucho lo que has hecho por mí.$B$BPero, por favor, ni una palabra a Troyas sobre esto.', 0),
(@ID, 'esMX', 'Te agradezco mucho lo que has hecho por mí.$B$BPero, por favor, ni una palabra a Troyas sobre esto.', 0);
-- 2983 La llamada del fuego
-- https://es.classic.wowhead.com/quest=2983
SET @ID := 2983;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que... te manda Swart, ¿eh?$B$BBien. Siempre he confiado en Swart. Si te envía a mí, es que estás $glisto:lista; para participar en la siguiente sapta... la sapta de fuego.$B$BYa puedo ver esa chispa, esa llama de impaciencia en tus ojos. Has probado el poder y ahora estás listo para adquirir más. Paciencia, $n. Recuerda lo que la tierra te enseñó. El poder y la destrucción llegan fácilmente, pero siempre has de saber cuándo detener tu mano.', 0),
(@ID, 'esMX', 'Así que... te manda Swart, ¿eh?$B$BBien. Siempre he confiado en Swart. Si te envía a mí, es que estás $glisto:lista; para participar en la siguiente sapta... la sapta de fuego.$B$BYa puedo ver esa chispa, esa llama de impaciencia en tus ojos. Has probado el poder y ahora estás listo para adquirir más. Paciencia, $n. Recuerda lo que la tierra te enseñó. El poder y la destrucción llegan fácilmente, pero siempre has de saber cuándo detener tu mano.', 0);
-- 2984 La llamada del fuego
-- https://es.classic.wowhead.com/quest=2984
SET @ID := 2984;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que... te manda Narm, ¿eh?$B$BBien. Siempre he confiado en Swart. Si te envía a mí, es que estás $glisto:lista; para participar en la siguiente sapta... la sapta de fuego.$B$BYa puedo ver esa chispa, esa llama de impaciencia en tus ojos. Has probado el poder y ahora estás listo para adquirir más. Paciencia, $n. Recuerda lo que la tierra te enseñó. El poder y la destrucción llegan fácilmente, pero siempre has de saber cuándo detener tu mano.', 0),
(@ID, 'esMX', 'Así que... te manda Narm, ¿eh?$B$BBien. Siempre he confiado en Swart. Si te envía a mí, es que estás $glisto:lista; para participar en la siguiente sapta... la sapta de fuego.$B$BYa puedo ver esa chispa, esa llama de impaciencia en tus ojos. Has probado el poder y ahora estás listo para adquirir más. Paciencia, $n. Recuerda lo que la tierra te enseñó. El poder y la destrucción llegan fácilmente, pero siempre has de saber cuándo detener tu mano.', 0);
-- 2985 La llamada del agua
-- https://es.classic.wowhead.com/quest=2985
SET @ID := 2985;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El viento se te acerca rápidamente desde el horizonte; la tierra es firme bajo tus pies; y tu espíritu ya está calentado por el fuego, yo diría que es hora de que aprendas sobre la pureza del agua.$B$BTu camino te ha llevado hasta aquí y tu espíritu te dará la fuerza para seguir adelante. Pero el primer paso es tuyo.', 0),
(@ID, 'esMX', 'El viento se te acerca rápidamente desde el horizonte; la tierra es firme bajo tus pies; y tu espíritu ya está calentado por el fuego, yo diría que es hora de que aprendas sobre la pureza del agua.$B$BTu camino te ha llevado hasta aquí y tu espíritu te dará la fuerza para seguir adelante. Pero el primer paso es tuyo.', 0);
-- 2987 El cobalto Gordunni
-- https://es.classic.wowhead.com/quest=2987
SET @ID := 2987;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ve allí y empieza a cavar!$B$BYo tengo que ir a sitios y ver a gente, ¡el tiempo es oro!', 0),
(@ID, 'esMX', '¡Ve allí y empieza a cavar!$B$BYo tengo que ir a sitios y ver a gente, ¡el tiempo es oro!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Son perfectas! Me las llevaré conmigo en mi viaje, $n. Seguro que consigo encontrar a alguien que me pague bien por este cobalto.$B$BTen. Por las molestias.', 0),
(@ID, 'esMX', '¡Son perfectas! Me las llevaré conmigo en mi viaje, $n. Seguro que consigo encontrar a alguien que me pague bien por este cobalto.$B$BTen. Por las molestias.', 0);
-- 2988 Las jaulas de Secacorteza
-- https://es.classic.wowhead.com/quest=2988
SET @ID := 2988;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Mira en la primera jaula', `ObjectiveText2` = 'Mira en la segunda jaula', `ObjectiveText3` = 'Mira en la tercera jaula', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 2989 El Altar de Zul
-- https://es.classic.wowhead.com/quest=2989
SET @ID := 2989;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Date prisa, $n! Si los trols Vilrama tienen a Picoafilado, ¡quién sabe qué podrían estar haciendo con él!', 0),
(@ID, 'esMX', '¡Date prisa, $n! Si los trols Vilrama tienen a Picoafilado, ¡quién sabe qué podrían estar haciendo con él!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No has encontrado a Picoafilado? Eso es malo y bueno.$B$BAl menos no estaba en el altar de los sacrificios.$B$BGracias por tu ayuda, aunque me queda la tarea más difícil por delante.', 0),
(@ID, 'esMX', '¿No has encontrado a Picoafilado? Eso es malo y bueno.$B$BAl menos no estaba en el altar de los sacrificios.$B$BGracias por tu ayuda, aunque me queda la tarea más difícil por delante.', 0);
-- 2990 Thadius Sombramacabra
-- https://es.classic.wowhead.com/quest=2990
SET @ID := 2990;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes un regalo, $n?', 0),
(@ID, 'esMX', '¿Traes un regalo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Esta pluma pertenece a un noble grifo destinado a grandes cosas... si llega a la edad adulta.$B$BEscúchame si quieres encontrarlo, $c...', 0),
(@ID, 'esMX', 'Ah, sí. Esta pluma pertenece a un noble grifo destinado a grandes cosas... si llega a la edad adulta.$B$BEscúchame si quieres encontrarlo, $c...', 0);
-- 2991 Medallón de Nekrum
-- https://es.classic.wowhead.com/quest=2991
SET @ID := 2991;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el medallón de Nekrum? Estoy deseando estudiar sus poderes.', 0),
(@ID, 'esMX', '¿Traes el medallón de Nekrum? Estoy deseando estudiar sus poderes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se dice que el medallón concede larga vida a los trols, pero a un precio muy alto. Espero poder extraer sus poderes sin sufrir sus desagradables efectos secundarios.$B$BAgradezco tu ayuda, $n. Ahora cumpliré mi promesa.', 0),
(@ID, 'esMX', 'Se dice que el medallón concede larga vida a los trols, pero a un precio muy alto. Espero poder extraer sus poderes sin sufrir sus desagradables efectos secundarios.$B$BAgradezco tu ayuda, $n. Ahora cumpliré mi promesa.', 0);
-- 2992 El ritual de adivinación
-- https://es.classic.wowhead.com/quest=2992
SET @ID := 2992;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ritual ha salido bien; he visto a Picoafilado y puedo decirte dónde encontrarlo.', 0),
(@ID, 'esMX', 'El ritual ha salido bien; he visto a Picoafilado y puedo decirte dónde encontrarlo.', 0);
-- 2993 Regresa a las Tierras del Interior
-- https://es.classic.wowhead.com/quest=2993
SET @ID := 2993;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué ha dicho Sombramacabra?$B$B¿Cómo que los Vilrama tienen a Picoafilado? ¡Eso es intolerable! ¡Tenemos que rescatarlo!', 0),
(@ID, 'esMX', '¿Qué ha dicho Sombramacabra?$B$B¿Cómo que los Vilrama tienen a Picoafilado? ¡Eso es intolerable! ¡Tenemos que rescatarlo!', 0);
-- 2994 Salvar a Picoafilado
-- https://es.classic.wowhead.com/quest=2994
SET @ID := 2994;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Abre la jaula de Picoafilado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Salva a Picoafilado!', 0),
(@ID, 'esMX', '¡Salva a Picoafilado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los padres de Picoafilado acaban de regresar con su hijo... ¿Eh? No lloro, es que se me ha metido algo en el ojo...$B$BTe agradecemos infinitamente lo que has hecho, $n. Los grifos de Pico Nidal y sus jinetes cantarán tus alabanzas durante mucho, mucho tiempo.', 0),
(@ID, 'esMX', 'Los padres de Picoafilado acaban de regresar con su hijo... ¿Eh? No lloro, es que se me ha metido algo en el ojo...$B$BTe agradecemos infinitamente lo que has hecho, $n. Los grifos de Pico Nidal y sus jinetes cantarán tus alabanzas durante mucho, mucho tiempo.', 0);
-- 2995 Líneas de comunicación
-- https://es.classic.wowhead.com/quest=2995
SET @ID := 2995;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Quema las actas de Vallealto.', `ObjectiveText2` = 'Quema las notas de Vallealto.', `ObjectiveText3` = 'Quema los informes de Vallealto.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mantener aislados a los elfos de Vallealto es la clave. ¿Has encontrado la avanzada?', 0),
(@ID, 'esMX', 'Mantener aislados a los elfos de Vallealto es la clave. ¿Has encontrado la avanzada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Mientras en Vallealto intentan recuperar la información perdida, nosotros podremos idear más modos de cortar sus comunicaciones.', 0),
(@ID, 'esMX', 'Muy bien, $n. Mientras en Vallealto intentan recuperar la información perdida, nosotros podremos idear más modos de cortar sus comunicaciones.', 0);
-- Buscando a Strahad
-- 2996, 3001
-- https://es.classic.wowhead.com/quest=2996
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2996, 3001) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2996, 'esES', 'Un día ajetreado en Trinquete, ¿no? Cómo disfruto viendo el trabajo de una ciudad portuaria. Tanto misterio, tanta aventura... tanta ignorancia.$B$B¿Es odio lo que veo en tus ojos, $n? Bien, le daremos un buen uso.', 0),
(3001, 'esES', 'Un día ajetreado en Trinquete, ¿no? Cómo disfruto viendo el trabajo de una ciudad portuaria. Tanto misterio, tanta aventura... tanta ignorancia.$B$B¿Es odio lo que veo en tus ojos, $n? Bien, le daremos un buen uso.', 0),
(2996, 'esMX', 'Un día ajetreado en Trinquete, ¿no? Cómo disfruto viendo el trabajo de una ciudad portuaria. Tanto misterio, tanta aventura... tanta ignorancia.$B$B¿Es odio lo que veo en tus ojos, $n? Bien, le daremos un buen uso.', 0),
(3001, 'esMX', 'Un día ajetreado en Trinquete, ¿no? Cómo disfruto viendo el trabajo de una ciudad portuaria. Tanto misterio, tanta aventura... tanta ignorancia.$B$B¿Es odio lo que veo en tus ojos, $n? Bien, le daremos un buen uso.', 0);
-- Escrito sobre divinidad
-- 2997, 2999
-- https://es.classic.wowhead.com/quest=2997
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2997, 2999) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2997, 'esES', 'Saludos, $n. Espero que la Luz te muestre el verdadero camino y te mantenga a salvo del mal.', 0),
(2999, 'esES', 'Saludos, $n. Espero que la Luz te muestre el verdadero camino y te mantenga a salvo del mal.', 0),
(2997, 'esMX', 'Saludos, $n. Espero que la Luz te muestre el verdadero camino y te mantenga a salvo del mal.', 0),
(2999, 'esMX', 'Saludos, $n. Espero que la Luz te muestre el verdadero camino y te mantenga a salvo del mal.', 0);
-- 3000 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=3000
SET @ID := 3000;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te saludo y te doy la bienvenida, $n.', 0),
(@ID, 'esMX', 'Te saludo y te doy la bienvenida, $n.', 0);
-- 3002 El orbe Gordunni
-- https://es.classic.wowhead.com/quest=3002
SET @ID := 3002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué me has traído, $r?', 0),
(@ID, 'esMX', '¿Qué me has traído, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fascinante, $n.$B$BEste orbe es muy potente, pero también muy peligroso.', 0),
(@ID, 'esMX', 'Fascinante, $n.$B$BEste orbe es muy potente, pero también muy peligroso.', 0);
-- 3062 Corazón oscuro
-- https://es.classic.wowhead.com/quest=3062
SET @ID := 3062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos poner fin al odio que Edana propaga por la tierra.', 0),
(@ID, 'esMX', 'Debemos poner fin al odio que Edana propaga por la tierra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes saber que Edana está verdaderamente muerta. Guardaré este corazón de recuerdo, por lo que representa. Gracias, $n.', 0),
(@ID, 'esMX', 'Debes saber que Edana está verdaderamente muerta. Guardaré este corazón de recuerdo, por lo que representa. Gracias, $n.', 0);
-- 3063 Venganza contra Nortearroyo
-- https://es.classic.wowhead.com/quest=3063
SET @ID := 3063;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las alas de las arpías Nortearroyo son negras como la noche; no les quites los ojos de encima, no sea que desaparezcan en la oscuridad.', 0),
(@ID, 'esMX', 'Las alas de las arpías Nortearroyo son negras como la noche; no les quites los ojos de encima, no sea que desaparezcan en la oscuridad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Has traído mucha paz a la conciencia de un viejo tauren.', 0),
(@ID, 'esMX', 'Gracias, $n. Has traído mucha paz a la conciencia de un viejo tauren.', 0);
-- 3065 Tablilla simple
-- https://es.classic.wowhead.com/quest=3065
SET @ID := 3065;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gOtro:Otra; $r para engrosar las filas. Pareces lo bastante $gbueno:buena;.$B$BSeguramente no te será fácil blandir un buen arma como un hacha, pero una lanza es tan buena como cualquier otra cosa.$B$B$gBienvenido:Bienvenida; al Valle de los Retos.', 0),
(@ID, 'esMX', '$gOtro:Otra; $r para engrosar las filas. Pareces lo bastante $gbueno:buena;.$B$BSeguramente no te será fácil blandir un buen arma como un hacha, pero una lanza es tan buena como cualquier otra cosa.$B$B$gBienvenido:Bienvenida; al Valle de los Retos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando sigas instruyéndote en las artes $gdel:de la; $c encontrarás este lugar muy adecuado. Si tienes cualquier duda no temas en preguntar a cualquiera y cuando te sientas preparado vuelve a verme para recibir instrucción. Tengo el mismo dominio que cualquier otro $c del Valle y puedo transmitirte ese conocimiento... por un precio, claro.', 0),
(@ID, 'esMX', 'Cuando sigas instruyéndote en las artes $gdel:de la; $c encontrarás este lugar muy adecuado. Si tienes cualquier duda no temas en preguntar a cualquiera y cuando te sientas preparado vuelve a verme para recibir instrucción. Tengo el mismo dominio que cualquier otro $c del Valle y puedo transmitirte ese conocimiento... por un precio, claro.', 0);
-- 3082 Tablilla con grabados
-- https://es.classic.wowhead.com/quest=3082
SET @ID := 3082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Jen\'shan ve ante ella $gun poderoso:una poderosa; $c y los espíritus dan su aprobación.$B$BLa senda $gdel:de la; $c es uno de los caminos más antiguos. La Horda se dirigió a nosotros cuando su lucha era solo por la supervivencia en Azeroth y nos pidieron que les enseñáramos y que les mostráramos muchos secretos. Ya eran fuertes: fuertes en las artes chamánicas y fuertes en las artes del guerrero. Pero la senda $gdel:de la; $c no era su senda... entonces.', 0),
(@ID, 'esMX', 'Jen\'shan ve ante ella $gun poderoso:una poderosa; $c y los espíritus dan su aprobación.$B$BLa senda $gdel:de la; $c es uno de los caminos más antiguos. La Horda se dirigió a nosotros cuando su lucha era solo por la supervivencia en Azeroth y nos pidieron que les enseñáramos y que les mostráramos muchos secretos. Ya eran fuertes: fuertes en las artes chamánicas y fuertes en las artes del guerrero. Pero la senda $gdel:de la; $c no era su senda... entonces.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora les enseñamos todo eso y ellos nos enseñan otras cosas. Nos hacemos una única raza... o casi. Somos aliados desde hace mucho, así que recuerda ayudarles. Y Jen\'shan recordará ayudarte.$B$BJen\'shan te instruye en las artes $gdel:de la; $c, te instruye bien. No olvides nunca, <el(la> $c es muy respetado en la tribu. Tú ir a tener un importante papel en el futuro... no olvides nunca.$B$BCuando lo necesites, ven a Jen\'shan. Ella te enseña todo lo que pueda cuando crea que estás $gpreparado:preparada;.', 0),
(@ID, 'esMX', 'Ahora les enseñamos todo eso y ellos nos enseñan otras cosas. Nos hacemos una única raza... o casi. Somos aliados desde hace mucho, así que recuerda ayudarles. Y Jen\'shan recordará ayudarte.$B$BJen\'shan te instruye en las artes $gdel:de la; $c, te instruye bien. No olvides nunca, <el(la> $c es muy respetado en la tribu. Tú ir a tener un importante papel en el futuro... no olvides nunca.$B$BCuando lo necesites, ven a Jen\'shan. Ella te enseña todo lo que pueda cuando crea que estás $gpreparado:preparada;.', 0);
-- 3083 Tablilla encriptada
-- Notice: English text: Change 'Rangrang' to '$n' in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=3083
SET @ID := 3083;
UPDATE `quest_request_items` SET `CompletionText` = 'Welcome to the Valley of Trials, $n. You wouldn\'t be here if you hadn\'t gotten my tablet, so I will get to the point.$B$BI am Rwag and I am responsible for training the rogues, thieves, and cutpurses here in the Valley. I\'m the one the Hand will turn to if you\'re not ready for what\'s to come. But don\'t worry, the Hand won\'t be controlling everything you do, but it would be wise to work with them if they have need of your talents.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; al Valle de los Retos, $n. No estarías aquí si no hubieras recibido mi tablilla, así que iré al grano.$B$BSoy Rwag y soy responsable de entrenar a los pícaros, ladrones y maleantes aquí en el Valle. Soy a quien recurrirá la Mano si no estás listo para lo que está por venir. Pero no te preocupes, la Mano no controlará todo lo que haces, pero sería prudente trabajar con ellos si necesitan tus talentos.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; al Valle de los Retos, $n. No estarías aquí si no hubieras recibido mi tablilla, así que iré al grano.$B$BSoy Rwag y soy responsable de entrenar a los pícaros, ladrones y maleantes aquí en el Valle. Soy a quien recurrirá la Mano si no estás listo para lo que está por venir. Pero no te preocupes, la Mano no controlará todo lo que haces, pero sería prudente trabajar con ellos si necesitan tus talentos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hasta que llegue ese momento, estarás bajo mi tutela. Te mostraré las cuerdas como dicen algunas personas. Siempre que te sientas $gpreparado:preparada;, ven a verme y me ocuparé de capacitarte más. Hasta entonces, practica tus habilidades y mantenlas perfeccionadas al filo de la navaja. Nunca sabrás cuándo necesitarás incluso la habilidad más insignificante.', 0),
(@ID, 'esMX', 'Hasta que llegue ese momento, estarás bajo mi tutela. Te mostraré las cuerdas como dicen algunas personas. Siempre que te sientas $gpreparado:preparada;, ven a verme y me ocuparé de capacitarte más. Hasta entonces, practica tus habilidades y mantenlas perfeccionadas al filo de la navaja. Nunca sabrás cuándo necesitarás incluso la habilidad más insignificante.', 0);
-- 3084 La tablilla con runas grabadas
-- https://es.classic.wowhead.com/quest=3084
SET @ID := 3084;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $gbienvenido:bienvenida;, $n. Me alegra que hayas venido. Con tantos alumnos a los que instruir mis días son largos y ajetreados, pero la llegada de alguien como tú me hace sentir realizada... Todavía recuerdo los días en los que me instruía uno de sus chamanes.', 0),
(@ID, 'esMX', 'Ah, $gbienvenido:bienvenida;, $n. Me alegra que hayas venido. Con tantos alumnos a los que instruir mis días son largos y ajetreados, pero la llegada de alguien como tú me hace sentir realizada... Todavía recuerdo los días en los que me instruía uno de sus chamanes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como seguramente ya sabrás, los elementos nos confieren nuestro poder. Fuego, tierra, agua y aire... esas son nuestras herramientas.$B$BNuestra fuerza nace de los espíritus de nuestros antepasados. Somos los líderes de nuestro pueblo. Lo que Thrall es para la Horda somos nosotros para los poblados y ciudades que visitamos. Buscan en nosotros sabiduría y protección. Para estar más $gpreparado:preparada; debes entrenar e instruirte a menudo. Cuando sientas que has ganado más poder ven a verme y te enseñaré todo lo que pueda.', 0),
(@ID, 'esMX', 'Como seguramente ya sabrás, los elementos nos confieren nuestro poder. Fuego, tierra, agua y aire... esas son nuestras herramientas.$B$BNuestra fuerza nace de los espíritus de nuestros antepasados. Somos los líderes de nuestro pueblo. Lo que Thrall es para la Horda somos nosotros para los poblados y ciudades que visitamos. Buscan en nosotros sabiduría y protección. Para estar más $gpreparado:preparada; debes entrenar e instruirte a menudo. Cuando sientas que has ganado más poder ven a verme y te enseñaré todo lo que pueda.', 0);

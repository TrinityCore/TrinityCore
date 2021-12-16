-- 3902 Hurgar en Camposanto
-- https://es.classic.wowhead.com/quest=3902
SET @ID := 3902;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Nos has conseguido algún objeto útil? No hay que avergonzarse de utilizar lo que otros han desechado. Nosotros no aceptamos limosnas. ¡Los Renegados nos las arreglamos solos!', 0),
(@ID, 'esMX', '¿Nos has conseguido algún objeto útil? No hay que avergonzarse de utilizar lo que otros han desechado. Nosotros no aceptamos limosnas. ¡Los Renegados nos las arreglamos solos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n, sabía que no eras $gun:una; inútil. Ten, acepta uno de los mejores objetos que he encontrado entre los lotes que hemos reunido hasta ahora.', 0),
(@ID, 'esMX', 'Buen trabajo, $n, sabía que no eras $gun:una; inútil. Ten, acepta uno de los mejores objetos que he encontrado entre los lotes que hemos reunido hasta ahora.', 0);
-- 3906 La discordia de las llamas
-- https://es.classic.wowhead.com/quest=3906
SET @ID := 3906;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los elementos todavía están perturbados, $n.', 0),
(@ID, 'esMX', 'Los elementos todavía están perturbados, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puede... no debe ser. La destrucción de Pyron solo ha levantado un velo. En las profundidades de Roca Negra hay una fuente de corrupción mucho más insidiosa.', 0),
(@ID, 'esMX', 'No puede... no debe ser. La destrucción de Pyron solo ha levantado un velo. En las profundidades de Roca Negra hay una fuente de corrupción mucho más insidiosa.', 0);
-- 3907 La discordia del fuego
-- https://es.classic.wowhead.com/quest=3907
SET @ID := 3907;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las llamas pronto habrán consumido estas tierras. ¡Apúrate, $n!', 0),
(@ID, 'esMX', 'Las llamas pronto habrán consumido estas tierras. ¡Apúrate, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Corazón Atronador se aferra a la tablilla de Kurniya.>$B$BRagnaros... aquí...$B$BLos ancianos tenían razón en temer la corrupción que emanaba de la Montaña Roca Negra. ¡Un general de los antiguos dioses! ¡EN NUESTRO MUNDO! Debemos revisar nuestras posiciones aquí en Kargath. Tenemos que decidir si quedarnos a luchar o escapar ante la posibilidad de un nuevo diluvio.$B$BTen mucho cuidado en cualquier nueva exploración en la Montaña Roca Negra, $n. Un mal mucho mayor que cualquiera concebible en este mundo se encuentra en esas salvajes profundidades.', 0),
(@ID, 'esMX', '<Corazón Atronador se aferra a la tablilla de Kurniya.>$B$BRagnaros... aquí...$B$BLos ancianos tenían razón en temer la corrupción que emanaba de la Montaña Roca Negra. ¡Un general de los antiguos dioses! ¡EN NUESTRO MUNDO! Debemos revisar nuestras posiciones aquí en Kargath. Tenemos que decidir si quedarnos a luchar o escapar ante la posibilidad de un nuevo diluvio.$B$BTen mucho cuidado en cualquier nueva exploración en la Montaña Roca Negra, $n. Un mal mucho mayor que cualquiera concebible en este mundo se encuentra en esas salvajes profundidades.', 0);
-- El último elemento
-- 3911, 7201
-- https://es.classic.wowhead.com/quest=3911
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3911, 7201) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3911, 'esES', '<Se frota las manos.>$B$B¡Enséñamelas!', 0),
(7201, 'esES', '<Se frota las manos.>$B$B¡Enséñamelas!', 0),
(3911, 'esMX', '<Se frota las manos.>$B$B¡Enséñamelas!', 0),
(7201, 'esMX', '<Se frota las manos.>$B$B¡Enséñamelas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3911, 7201) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3911, 'esES', '¡Estupendo! ¡Haré que las envíen inmediatamente por mensajero a Entrañas!$B$BEn cuanto a ti, aquí tienes el pago, como te prometí. ¡Quédate con el cambio, bestia asquerosa!', 0),
(7201, 'esES', '¡Estupendo! ¡Haré que las envíen inmediatamente por mensajero a Entrañas!$B$BEn cuanto a ti, aquí tienes el pago, como te prometí. ¡Quédate con el cambio, bestia asquerosa!', 0),
(3911, 'esMX', '¡Estupendo! ¡Haré que las envíen inmediatamente por mensajero a Entrañas!$B$BEn cuanto a ti, aquí tienes el pago, como te prometí. ¡Quédate con el cambio, bestia asquerosa!', 0),
(7201, 'esMX', '¡Estupendo! ¡Haré que las envíen inmediatamente por mensajero a Entrañas!$B$BEn cuanto a ti, aquí tienes el pago, como te prometí. ¡Quédate con el cambio, bestia asquerosa!', 0);
-- 3921 Wenikee Tuercasmil
-- https://es.classic.wowhead.com/quest=3921
SET @ID := 3921;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo muchísimo trabajo, $c. A menos que tengas algo para mí, me conviene seguir...', 0),
(@ID, 'esMX', 'Tengo muchísimo trabajo, $c. A menos que tengas algo para mí, me conviene seguir...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿Un churumbele? ¿Qué es un churumbele?$B$BAh... pero fíjate cómo se mueve cuando lo manejas. Y se oyen engranajes en el interior. ¡Oh, por todos los...! Quiero arreglarlo y ver qué hace, ¿tú no?', 0),
(@ID, 'esMX', '¿Qué es esto? ¿Un churumbele? ¿Qué es un churumbele?$B$BAh... pero fíjate cómo se mueve cuando lo manejas. Y se oyen engranajes en el interior. ¡Oh, por todos los...! Quiero arreglarlo y ver qué hace, ¿tú no?', 0);
-- 3922 Engranajes
-- https://es.classic.wowhead.com/quest=3922
SET @ID := 3922;
UPDATE `quest_template_locale` SET `Objectives` = 'Reúne 15 engranajes de los cubos que encuentres por la zona de El Fangal.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los engranajes, $n? Le he echado un ojo a este churumbele y me muero por hacerle ajustes.', 0),
(@ID, 'esMX', '¿Tienes los engranajes, $n? Le he echado un ojo a este churumbele y me muero por hacerle ajustes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, los tienes! Ahora puedo ponerme a trabajar…', 0),
(@ID, 'esMX', '¡Genial, los tienes! Ahora puedo ponerme a trabajar…', 0);
-- 3923 Rilli Gapegajoso
-- https://es.classic.wowhead.com/quest=3923
SET @ID := 3923;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cuidado con la cabeza! No quiero que se interponga en mi trabajo!', 0),
(@ID, 'esMX', '¡Cuidado con la cabeza! No quiero que se interponga en mi trabajo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¡¿Qué?! ¡Es un churumbele! ¿Dónde lo has conseguido? ¿Has estado curioseando por las instalaciones de Ventura y Cía. en Los Baldíos?$B$BDebes de ser muy valiente, o muy $gestúpido:estúpida;.', 0),
(@ID, 'esMX', '¿Qué es esto? ¡¿Qué?! ¡Es un churumbele! ¿Dónde lo has conseguido? ¿Has estado curioseando por las instalaciones de Ventura y Cía. en Los Baldíos?$B$BDebes de ser muy valiente, o muy $gestúpido:estúpida;.', 0);
-- 3924 El manual del churumbele
-- https://es.classic.wowhead.com/quest=3924
SET @ID := 3924;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el manual?', 0),
(@ID, 'esMX', '¿Tienes el manual?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes el manual! ¡Me muero por leerlo y averiguar cómo reparar el churumbele! Hablé con Petardol en Trinquete, quería agradecerte tu ayuda y recompensarte por tu trabajo.$B$BTambién yo quiero darte las gracias, y si algún día consigo reparar este artilugio, te lo haré saber...', 0),
(@ID, 'esMX', '¡Tienes el manual! ¡Me muero por leerlo y averiguar cómo reparar el churumbele! Hablé con Petardol en Trinquete, quería agradecerte tu ayuda y recompensarte por tu trabajo.$B$BTambién yo quiero darte las gracias, y si algún día consigo reparar este artilugio, te lo haré saber...', 0);
-- 3981 Comandante Gor'shak
-- https://es.classic.wowhead.com/quest=3981
SET @ID := 3981;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tenemos mucho tiempo. Escucha atentamente, $r. Lo que tengo que decirte es confidencial y solo para tus oídos.', 0),
(@ID, 'esMX', 'No tenemos mucho tiempo. Escucha atentamente, $r. Lo que tengo que decirte es confidencial y solo para tus oídos.', 0);
-- 3982 ¿Qué pasa?
-- https://es.classic.wowhead.com/quest=3982
SET @ID := 3982;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Defiéndete, $gtonto:tonta;!', 0),
(@ID, 'esMX', '¡Defiéndete, $gtonto:tonta;!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso ha estado muy cerca. Tu presencia los ha alertado... no tardaremos en ver los efectos.', 0),
(@ID, 'esMX', 'Eso ha estado muy cerca. Tu presencia los ha alertado... no tardaremos en ver los efectos.', 0);
-- 4001 ¿Qué pasa?
-- https://es.classic.wowhead.com/quest=4001
SET @ID := 4001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae a estos terrenos sagrados?', 0),
(@ID, 'esMX', '¿Qué te trae a estos terrenos sagrados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta es una oportunidad para la Horda para cambiar para siempre el clima político de nuestro mundo desgarrado por la guerra. Escucha atentamente, $n.$B$BEl fracaso en esta misión no es una opción.', 0),
(@ID, 'esMX', 'Esta es una oportunidad para la Horda para cambiar para siempre el clima político de nuestro mundo desgarrado por la guerra. Escucha atentamente, $n.$B$BEl fracaso en esta misión no es una opción.', 0);
-- 4002 Los Reinos del Este
-- https://es.classic.wowhead.com/quest=4002
SET @ID := 4002;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el punto de no retorno, $n.', 0),
(@ID, 'esMX', 'Este es el punto de no retorno, $n.', 0);
-- 4003 El rescate real
-- https://es.classic.wowhead.com/quest=4003
SET @ID := 4003;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La princesa Moira se encoge de miedo.>', 0),
(@ID, 'esMX', '<La princesa Moira se encoge de miedo.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué has hecho, criminal?!', 0),
(@ID, 'esMX', '¡¿Qué has hecho, criminal?!', 0);
-- 4004 ¿Princesa salvada?
-- https://es.classic.wowhead.com/quest=4004
SET @ID := 4004;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thrall se muestra muy afectado por la información que acabas de darle.>$B$BUna nueva amenaza se cierne sobre el horizonte. Se acaban los años de Magni y con ello tendrá vía libre la estirpe no nata de Hierro Negro para gobernar Forjaz.$B$BHas cumplido lo que te había encargado y por ello serás $grecompensado:recompensada;.$B$B¡Márchate, $n! Debo discutir algo con Sylvanas y Cairne.', 0),
(@ID, 'esMX', '<Thrall se muestra muy afectado por la información que acabas de darle.>$B$BUna nueva amenaza se cierne sobre el horizonte. Se acaban los años de Magni y con ello tendrá vía libre la estirpe no nata de Hierro Negro para gobernar Forjaz.$B$BHas cumplido lo que te había encargado y por ello serás $grecompensado:recompensada;.$B$B¡Márchate, $n! Debo discutir algo con Sylvanas y Cairne.', 0);
-- 4021 ¡Contraataca!
-- https://es.classic.wowhead.com/quest=4021
SET @ID := 4021;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el estandarte?', 0),
(@ID, 'esMX', '¿Tienes el estandarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! ¡Has derrotado a Kolkar!$B$BMe aseguraré de que Thrall se entere de tus proezas en este lugar, $n.$B$BVe con la cabeza bien alta. Eres motivo de orgullo no solo para ti sino también para la Horda', 0),
(@ID, 'esMX', '¡Lo has logrado! ¡Has derrotado a Kolkar!$B$BMe aseguraré de que Thrall se entere de tus proezas en este lugar, $n.$B$BVe con la cabeza bien alta. Eres motivo de orgullo no solo para ti sino también para la Horda', 0);
-- Un sabor a llamarada
-- 4022, 4023
-- https://es.classic.wowhead.com/quest=4022
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4022, 4023) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4022, 'esES', '<Los ojos de Cyrus forman dos esferas encendidas.>', 0),
(4023, 'esES', '<Los ojos de Cyrus forman dos esferas encendidas.>', 0),
(4022, 'esMX', '<Los ojos de Cyrus forman dos esferas encendidas.>', 0),
(4023, 'esMX', '<Los ojos de Cyrus forman dos esferas encendidas.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4022, 4023) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4022, 'esES', '<Cyrus examina la escama.>$B$BHas demostrado que no eres completamente inútil, mortal.', 0),
(4023, 'esES', '<Cyrus examina la escama.>$B$BHas demostrado que no eres completamente inútil, mortal.', 0),
(4022, 'esMX', '<Cyrus examina la escama.>$B$BHas demostrado que no eres completamente inútil, mortal.', 0),
(4023, 'esMX', '<Cyrus examina la escama.>$B$BHas demostrado que no eres completamente inútil, mortal.', 0);
-- 4024 Un sabor a llamarada
-- https://es.classic.wowhead.com/quest=4024
SET @ID := 4024;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha sucumbido el gigante?', 0),
(@ID, 'esMX', '¿Ha sucumbido el gigante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Cyrus te arrebata la esencia fiera de las manos.>$B$B¡SÍ!$B$BToma tu recompensa y vete. ¡Desaparece inmediatamente de mi vista!', 0),
(@ID, 'esMX', '<Cyrus te arrebata la esencia fiera de las manos.>$B$B¡SÍ!$B$BToma tu recompensa y vete. ¡Desaparece inmediatamente de mi vista!', 0);
-- 4041 El Elixir de Videre
-- https://es.classic.wowhead.com/quest=4041
SET @ID := 4041;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tráeme una raíz del mal y te haré ese Elixir Videre.$B$BSé mucho sobre hierbas y alquimia... ¡Podría contarte una de historias! Por ejemplo, un día transformé el queso que iba a desayunar en oro... ¡Eh! ¿Adónde vas?', 0),
(@ID, 'esMX', 'Tráeme una raíz del mal y te haré ese Elixir Videre.$B$BSé mucho sobre hierbas y alquimia... ¡Podría contarte una de historias! Por ejemplo, un día transformé el queso que iba a desayunar en oro... ¡Eh! ¿Adónde vas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que se la has jugado al viejo Miblon, ¿eh?', 0),
(@ID, 'esMX', 'Así que se la has jugado al viejo Miblon, ¿eh?', 0);
-- 4061 La revuelta de las máquinas
-- https://es.classic.wowhead.com/quest=4061
SET @ID := 4061;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te tomes esto a la ligera, $n!', 0),
(@ID, 'esMX', '¡No te tomes esto a la ligera, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Theodora dispone los fragmentos frente a ella.>$B$B<Theodora examina detenidamente los fragmentos con un enorme monóculo.>$B$BInteresante. En la fundación estructural de cada fragmento hay grabadas... iniciales.', 0),
(@ID, 'esMX', '<Theodora dispone los fragmentos frente a ella.>$B$B<Theodora examina detenidamente los fragmentos con un enorme monóculo.>$B$BInteresante. En la fundación estructural de cada fragmento hay grabadas... iniciales.', 0);
-- 4062 La revuelta de las máquinas
-- https://es.classic.wowhead.com/quest=4062
SET @ID := 4062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $r?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lotwil palidece.>$B$BHe... he visto antes estas marcas.', 0),
(@ID, 'esMX', '<Lotwil palidece.>$B$BHe... he visto antes estas marcas.', 0);
-- 4063 La revuelta de las máquinas
-- https://es.classic.wowhead.com/quest=4063
SET @ID := 4063;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Era él? ¿De verdad estaba vivo?', 0),
(@ID, 'esMX', '¿Era él? ¿De verdad estaba vivo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué es esto?! Esta cabeza no es de carne. Esto es algún tipo de creación de hierro negro: una sombra de Argelmach, ¡OTRA máquina! Sospecho que tu destrucción de Argelmach no durará ya que otro surgirá para ocupar su lugar pronto.', 0),
(@ID, 'esMX', '¡¿Qué es esto?! Esta cabeza no es de carne. Esto es algún tipo de creación de hierro negro: una sombra de Argelmach, ¡OTRA máquina! Sospecho que tu destrucción de Argelmach no durará ya que otro surgirá para ocupar su lugar pronto.', 0);
-- 4081 MATAR INMEDIATAMENTE: enanos Hierro Negro
-- https://es.classic.wowhead.com/quest=4081
SET @ID := 4081;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué pasa, $r? ¿No ves que tengo un pelotón que dirigir?', 0),
(@ID, 'esMX', '¿Qué pasa, $r? ¿No ves que tengo un pelotón que dirigir?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este primer ataque ha debido de provocarle alguna cana a los Forjainquina. Ahora, andando, soldado. Tengo trabajo que hacer, batallas que planificar, ¡enemigos a los que aplastar!$B$BSigue pendiente de los carteles de "Se busca" si quieres más trabajo.', 0),
(@ID, 'esMX', 'Este primer ataque ha debido de provocarle alguna cana a los Forjainquina. Ahora, andando, soldado. Tengo trabajo que hacer, batallas que planificar, ¡enemigos a los que aplastar!$B$BSigue pendiente de los carteles de "Se busca" si quieres más trabajo.', 0);
-- 4082 MATAR INMEDIATAMENTE: oficiales Hierro Negro de alto rango
-- https://es.classic.wowhead.com/quest=4082
SET @ID := 4082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tú otra vez? Te lo tengo que dar, $n, eres tenaz.', 0),
(@ID, 'esMX', '¿Tú otra vez? Te lo tengo que dar, $n, eres tenaz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Forjainquina está sin lugar a dudas... furioso. Vuelve aquí cuando recibas un tercer tributo y procederemos con Operación: muerte a Forjainquina. No puedo entrar en detalles pero ten por seguro que alguien muere.', 0),
(@ID, 'esMX', 'Forjainquina está sin lugar a dudas... furioso. Vuelve aquí cuando recibas un tercer tributo y procederemos con Operación: muerte a Forjainquina. No puedo entrar en detalles pero ten por seguro que alguien muere.', 0);
-- 4083 El cáliz espectral
-- https://es.classic.wowhead.com/quest=4083
SET @ID := 4083;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cáliz espectral flota en el aire, ascendiendo y descendiendo lentamente… como el latido de un corazón moribundo.', 0),
(@ID, 'esMX', 'El cáliz espectral flota en el aire, ascendiendo y descendiendo lentamente… como el latido de un corazón moribundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las gemas caen silenciosas en lo más hondo del cáliz...', 0),
(@ID, 'esMX', 'Las gemas caen silenciosas en lo más hondo del cáliz...', 0);
-- 4102 Limpiar Frondavil
-- https://es.classic.wowhead.com/quest=4102
SET @ID := 4102;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que Frondavil sufre, $n. ¡Y yo sufro con él! He de ser firme, pues si el conocimiento que poseo cayera en manos equivocadas, la desgracia caería sobre Frondavil.$B$BTráeme el ámbar de sangre de los elementales alabeos muertos y te ganarás mi confianza; te dejaré que me ayudes a combatir la corrupción.', 0),
(@ID, 'esMX', 'Sé que Frondavil sufre, $n. ¡Y yo sufro con él! He de ser firme, pues si el conocimiento que poseo cayera en manos equivocadas, la desgracia caería sobre Frondavil.$B$BTráeme el ámbar de sangre de los elementales alabeos muertos y te ganarás mi confianza; te dejaré que me ayudes a combatir la corrupción.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este ámbar de sangre se utilizará para encontrar un medio de acabar con la corrupción de Frondavil. Me has demostrado que estás deseando hacer cualquier cosa por ayudar al Círculo Cenarion. Ahora confío en ti.$B$BPuede parecer extraño que te ganaras mi confianza matando a los elementales, pero cualquier medio está justificado si nos ayuda a lograr un fin mayor: salvar a innumerables seres sensibles. Ahora podemos centrarnos en preservar la vida con los bálsamos que preparo.$B$B$n, ha llegado el momento de limpiar Frondavil.', 0),
(@ID, 'esMX', 'Este ámbar de sangre se utilizará para encontrar un medio de acabar con la corrupción de Frondavil. Me has demostrado que estás deseando hacer cualquier cosa por ayudar al Círculo Cenarion. Ahora confío en ti.$B$BPuede parecer extraño que te ganaras mi confianza matando a los elementales, pero cualquier medio está justificado si nos ayuda a lograr un fin mayor: salvar a innumerables seres sensibles. Ahora podemos centrarnos en preservar la vida con los bálsamos que preparo.$B$B$n, ha llegado el momento de limpiar Frondavil.', 0);
-- Blancoria corrupta
-- 4117, 4443, 4444, 4445, 4446, 4461
-- https://es.classic.wowhead.com/quest=4117
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4117, 4443, 4444, 4445, 4446, 4461) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4117, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4443, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4444, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4445, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4446, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4461, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4117, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4443, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4444, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4445, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4446, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4461, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una blancoria. De la planta cuelga una sustancia viscosa y las raíces visibles parecen endurecidas, como si fueran de cuero. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4117, 4443, 4444, 4445, 4446, 4461) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4117, 'esES', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4443, 'esES', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4444, 'esES', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4445, 'esES', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4446, 'esES', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4461, 'esES', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4117, 'esMX', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4443, 'esMX', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4444, 'esMX', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4445, 'esMX', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4446, 'esMX', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4461, 'esMX', 'Aplicas tres bálsamos de planta de Cenarion a la blancoria. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0);
-- 4120 La fuerza de la corrupción
-- https://es.classic.wowhead.com/quest=4120
SET @ID := 4120;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo lo tocado por lo vil emana un extraño resplandor verde... Siento que es malvado, pero al mismo tiempo, muy poderoso.', 0),
(@ID, 'esMX', 'Todo lo tocado por lo vil emana un extraño resplandor verde... Siento que es malvado, pero al mismo tiempo, muy poderoso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Suena a partir de tus descripciones como si las criaturas mostraran una ferocidad sin sentido...$B$BMantente alerta, $n. Le convendría saber más sobre la corrupción. Conoce siempre a tu enemigo.', 0),
(@ID, 'esMX', 'Suena a partir de tus descripciones como si las criaturas mostraran una ferocidad sin sentido...$B$BMantente alerta, $n. Le convendría saber más sobre la corrupción. Conoce siempre a tu enemigo.', 0);
-- 4121 ¡Estás en un aprieto!
-- https://es.classic.wowhead.com/quest=4121
SET @ID := 4121;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me llevaré a esta escoria traidora, $n.', 0),
(@ID, 'esMX', 'Me llevaré a esta escoria traidora, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus proezas no se quedarán sin reconocimiento, $n. Te has ganado este tributo. El Señor de la Guerra hablará contigo respecto a la misión final.', 0),
(@ID, 'esMX', 'Tus proezas no se quedarán sin reconocimiento, $n. Te has ganado este tributo. El Señor de la Guerra hablará contigo respecto a la misión final.', 0);

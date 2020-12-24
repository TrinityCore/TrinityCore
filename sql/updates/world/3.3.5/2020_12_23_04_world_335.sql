-- 711 Estudio de los elementos: roca
-- https://es.classic.wowhead.com/quest=711
SET @ID := 711;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy encantadísimo, $n. Mis hechizos han afectado a las piezas más pequeñas, justo como predije. Si este experimento sale tan bien como anticipo, los elementales que podré controlar harán que cualquier cosa conjurada antes quede a la altura del betún.', 0),
(@ID, 'esMX', 'Estoy encantadísimo, $n. Mis hechizos han afectado a las piezas más pequeñas, justo como predije. Si este experimento sale tan bien como anticipo, los elementales que podré controlar harán que cualquier cosa conjurada antes quede a la altura del betún.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n, sencillamente asombroso! Creía que haría falta media docena de tauren para traerme todos estos fragmentos.', 0),
(@ID, 'esMX', '¡$n, sencillamente asombroso! Creía que haría falta media docena de tauren para traerme todos estos fragmentos.', 0);
-- 712 Estudio de los elementos: roca
-- https://es.classic.wowhead.com/quest=712
SET @ID := 712;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las losas de piedra que encontraste eran ideales, $n. Lucien llevará las que sobren a Kharanos cuando acabemos aquí. A fin de cuentas, podrían volver a ser útiles.$B$BPor ejemplo, serían una base estupenda para un pequeño y práctico cobertizo cuando empiece a investigar un enfoque multidisciplinario de los explosivos de alto rendimiento...', 0),
(@ID, 'esMX', 'Las losas de piedra que encontraste eran ideales, $n. Lucien llevará las que sobren a Kharanos cuando acabemos aquí. A fin de cuentas, podrían volver a ser útiles.$B$BPor ejemplo, serían una base estupenda para un pequeño y práctico cobertizo cuando empiece a investigar un enfoque multidisciplinario de los explosivos de alto rendimiento...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿alguna vez te has planteado convertirte en un ayudante de investigación ¿No? No sé lo que haría si no contara con tus facultades. Inteligencia, curiosidad y fuerza, todo en una sola persona.', 0),
(@ID, 'esMX', '$n, ¿alguna vez te has planteado convertirte en un ayudante de investigación ¿No? No sé lo que haría si no contara con tus facultades. Inteligencia, curiosidad y fuerza, todo en una sola persona.', 0);
-- 713 Mantener la cabeza fría
-- https://es.classic.wowhead.com/quest=713
SET @ID := 713;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado el aceite que necesitaba? ¡Me vendría tan bien que encontraras un poco!', 0),
(@ID, 'esMX', '¿Has encontrado el aceite que necesitaba? ¡Me vendría tan bien que encontraras un poco!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Formidable! Será el refrigerante perfecto para mis nuevos brazales. Si los encantamientos no duran un siglo, le daré todas mis pertenencias a Servo.$B$BTodos los magos de la Asamblea sentirán un respeto reverencial cuando acabe con esto, $n. Espera y verás.', 0),
(@ID, 'esMX', '¡Formidable! Será el refrigerante perfecto para mis nuevos brazales. Si los encantamientos no duran un siglo, le daré todas mis pertenencias a Servo.$B$BTodos los magos de la Asamblea sentirán un respeto reverencial cuando acabe con esto, $n. Espera y verás.', 0);
-- 714 Un giro... ¿Qué?
-- https://es.classic.wowhead.com/quest=714
SET @ID := 714;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí, ya voy. Solo un segundo.$B$B<Lotwil sigue trabajando en algún tipo de invento.>', 0),
(@ID, 'esMX', 'Sí, sí, ya voy. Solo un segundo.$B$B<Lotwil sigue trabajando en algún tipo de invento.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡TOMA!$B$B<Lotwil te quita el girocronátomo.>$B$BPerfecto… casi estamos. Bueno, casi. YO estoy casi listo. Este proyecto es mi prioridad absoluta... en estos momentos. Deja que coloque esto y verás con tus propios ojos a lo que has contribuido a crear. Solo harán falta unos minutos... a lo mejor... un poco más. Bueno, quizás mucho más. Ya veremos.', 0),
(@ID, 'esMX', '¡TOMA!$B$B<Lotwil te quita el girocronátomo.>$B$BPerfecto… casi estamos. Bueno, casi. YO estoy casi listo. Este proyecto es mi prioridad absoluta... en estos momentos. Deja que coloque esto y verás con tus propios ojos a lo que has contribuido a crear. Solo harán falta unos minutos... a lo mejor... un poco más. Bueno, quizás mucho más. Ya veremos.', 0);
-- 715 Piedra líquida
-- https://es.classic.wowhead.com/quest=715
SET @ID := 715;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está a punto de acabar. ¿Cómo van las cosas de tu lado?', 0),
(@ID, 'esMX', 'Está a punto de acabar. ¿Cómo van las cosas de tu lado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡SÍ!$B$BDigo… gracias, $n. Te vendrán bien cuando viajes por las Tierras Inhóspitas.', 0),
(@ID, 'esMX', '¡SÍ!$B$BDigo… gracias, $n. Te vendrán bien cuando viajes por las Tierras Inhóspitas.', 0);
-- 716 Es mejor la piedra que la tela
-- https://es.classic.wowhead.com/quest=716
SET @ID := 716;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yo no esperaría demasiado para conseguir ese brazal, $n.$B$B¿Quién sabe lo que puede pasar después?', 0),
(@ID, 'esMX', 'Yo no esperaría demasiado para conseguir ese brazal, $n.$B$B¿Quién sabe lo que puede pasar después?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Pruébatelos.', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Pruébatelos.', 0);
-- 717 Terremotos
-- https://es.classic.wowhead.com/quest=717
SET @ID := 717;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cárcel de los dragones ha estado controlada por una poderosa magia y fuertes poderes pero no podemos permitir arriesgarnos a que liberen a Latigoscuro y a Hematus.', 0),
(@ID, 'esMX', 'La cárcel de los dragones ha estado controlada por una poderosa magia y fuertes poderes pero no podemos permitir arriesgarnos a que liberen a Latigoscuro y a Hematus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Kirin Tor ya no tendrá que preocuparse de los prisioneros de Lethlor. Volveré para informar del éxito a mi maestro. Seguro que Krasus se alegrará.', 0),
(@ID, 'esMX', 'El Kirin Tor ya no tendrá que preocuparse de los prisioneros de Lethlor. Volveré para informar del éxito a mi maestro. Seguro que Krasus se alegrará.', 0);
-- 728 Ir a Entrañas a buscar el "Compendio" de Yagyin
-- https://es.classic.wowhead.com/quest=728
SET @ID := 728;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, estamos impacientes, ¿no, $c? ¿Has venido para aprender de mi colección? ¡Bien!$B$BPero ten cuidado: al igual que el conocimiento otorga poder a los fuertes... vuelve locos a los débiles.', 0),
(@ID, 'esMX', 'Vaya, estamos impacientes, ¿no, $c? ¿Has venido para aprender de mi colección? ¡Bien!$B$BPero ten cuidado: al igual que el conocimiento otorga poder a los fuertes... vuelve locos a los débiles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado con lo que dejas ver, $c. Hay quien no cree en la legitimidad de nuestro compromiso.$B$BY hay quien intentará que fracasemos si saben de nuestra existencia.$B$BSiempre debemos tener cuidado. Y estar vigilantes. Y pacientes.', 0),
(@ID, 'esMX', 'Ten cuidado con lo que dejas ver, $c. Hay quien no cree en la legitimidad de nuestro compromiso.$B$BY hay quien intentará que fracasemos si saben de nuestra existencia.$B$BSiempre debemos tener cuidado. Y estar vigilantes. Y pacientes.', 0);
-- 9174 Derrotar a Aquantion
-- https://es.wowhead.com/quest=9174
SET @ID := 9174;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has destruido a Aquantion?', 0),
(@ID, 'esMX', '¿Has destruido a Aquantion?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vengado nuestras muertes y has roto el dominio de Aquantion sobre nuestras almas. Por fin podremos descansar en paz.', 0),
(@ID, 'esMX', 'Has vengado nuestras muertes y has roto el dominio de Aquantion sobre nuestras almas. Por fin podremos descansar en paz.', 0);
-- 9146 Informar al capitán Helios
-- https://es.wowhead.com/quest=9146
SET @ID := 9146;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es muy grave; he sobrestimado la capacidad de liderazgo a Tomathren. Enviaré a un grupo de escolta para él y Valanna.$B$BPor desgracia, seguimos sin noticias de la forestal Salissa; temo lo peor.$B$BHas prestado un gran servicio a los Errantes, $c. Acepta esto como muestra de nuestra gratitud.', 0),
(@ID, 'esMX', 'Eso es muy grave; he sobrestimado la capacidad de liderazgo a Tomathren. Enviaré a un grupo de escolta para él y Valanna.$B$BPor desgracia, seguimos sin noticias de la forestal Salissa; temo lo peor.$B$BHas prestado un gran servicio a los Errantes, $c. Acepta esto como muestra de nuestra gratitud.', 0);
-- 9158 Transmisores de la peste
-- https://es.wowhead.com/quest=9158
SET @ID := 9158;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Es importante que la peste no se extienda a la fauna y flora sanas de Canción Eterna. Si buscas trabajo, tengo más tareas para ti.', 0),
(@ID, 'esMX', 'Muy bien, $n. Es importante que la peste no se extienda a la fauna y flora sanas de Canción Eterna. Si buscas trabajo, tengo más tareas para ti.', 0);
-- 9214 Armas Sombrapino
-- https://es.wowhead.com/quest=9214
SET @ID := 9214;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes esas armas? Con los efectivos de los Sombrapino diezmados, por fin podremos centrar nuestra atención en combatir a la Plaga.', 0),
(@ID, 'esMX', '¿Ya tienes esas armas? Con los efectivos de los Sombrapino diezmados, por fin podremos centrar nuestra atención en combatir a la Plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enviaré inmediatamente a unos forestales para que investiguen el daño que has causado a los trols Sombrapino. Seguro que podremos barrerlos después de tu ofensiva y lanzaremos un ataque sobre la Plaga pronto si estas armas son una muestra de tu éxito.$B$BAquí tienes, toma esta moneda como pago. De todos modos, me está haciendo un agujero en la faltriquera.', 0),
(@ID, 'esMX', 'Enviaré inmediatamente a unos forestales para que investiguen el daño que has causado a los trols Sombrapino. Seguro que podremos barrerlos después de tu ofensiva y lanzaremos un ataque sobre la Plaga pronto si estas armas son una muestra de tu éxito.$B$BAquí tienes, toma esta moneda como pago. De todos modos, me está haciendo un agujero en la faltriquera.', 0);
-- 9274 Los espíritus de los ahogados
-- https://es.wowhead.com/quest=9274
SET @ID := 9274;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has hecho lo que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Me duele ver a los espíritus de mis antepasados en tal estado. Espero que encuentren la paz que merecen.', 0),
(@ID, 'esMX', 'Gracias, $n. Me duele ver a los espíritus de mis antepasados en tal estado. Espero que encuentren la paz que merecen.', 0);
-- 9215 ¡Tráeme la cabeza de Kel'gash!
-- https://es.wowhead.com/quest=9215
SET @ID := 9215;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es este tufo asqueroso?', 0),
(@ID, 'esMX', '¿Qué es este tufo asqueroso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, era la cabeza de Kel\'gash lo que olía tan mal. ¡Un trabajo de categoría, $c!$B$BCon su jefe muerto, la confusión debe reinar entre los trols Sombrapino. Combinado con tus últimas acciones para diezmar sus efectivos, debería ser el momento perfecto para lanzar nuestro contraataque y borrarlos del mapa de una vez por todas.$B$BTienes mi agradecimiento, $n. ¿Crees que te gustaría uno de estos?', 0),
(@ID, 'esMX', 'Ah, era la cabeza de Kel\'gash lo que olía tan mal. ¡Un trabajo de categoría, $c!$B$BCon su jefe muerto, la confusión debe reinar entre los trols Sombrapino. Combinado con tus últimas acciones para diezmar sus efectivos, debería ser el momento perfecto para lanzar nuestro contraataque y borrarlos del mapa de una vez por todas.$B$BTienes mi agradecimiento, $n. ¿Crees que te gustaría uno de estos?', 0);
-- 9276 Ataque a Zeb'Tela
-- https://es.wowhead.com/quest=9276
SET @ID := 9276;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te va con el ataque a Zeb\'Tela?', 0),
(@ID, 'esMX', '¿Cómo te va con el ataque a Zeb\'Tela?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! ¡Buen trabajo! A ver cómo te defiendes con algo un poco más difícil.', 0),
(@ID, 'esMX', '¡Estupendo! ¡Buen trabajo! A ver cómo te defiendes con algo un poco más difícil.', 0);
-- 9275 Un toque de especias
-- https://es.wowhead.com/quest=9275
SET @ID := 9275;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Envenena la carne cruda', `ObjectiveText2` = 'Envenena la carne ahumada', `ObjectiveText3` = 'Envenena el pescado fresco', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No es emocionante? Realmente me enorgullezco de mi trabajo; Espero que lo aprecies, $c.$B$BConfío en que hayas \'sazonado\' la comida en los campamentos de trols en Zeb\'Nowa.', 0),
(@ID, 'esMX', '¿No es emocionante? Realmente me enorgullezco de mi trabajo; Espero que lo aprecies, $c.$B$BConfío en que hayas \'sazonado\' la comida en los campamentos de trols en Zeb\'Nowa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Sabía que encargar la tarea a $gun:una; $r garantizaría el resultado más eficiente. Con un poco de suerte, los trols Sombrapino engordarán con el veneno antes de palmarla. Así dejarán en paz a los Errantes y yo podré volver a Tranquillien.$B$B¡Ha sido un placer trabajar contigo, $c!', 0),
(@ID, 'esMX', '¡Excelente! Sabía que encargar la tarea a $gun:una; $r garantizaría el resultado más eficiente. Con un poco de suerte, los trols Sombrapino engordarán con el veneno antes de palmarla. Así dejarán en paz a los Errantes y yo podré volver a Tranquillien.$B$B¡Ha sido un placer trabajar contigo, $c!', 0);
-- 9161 La sombra del traidor
-- https://es.wowhead.com/quest=9161
SET @ID := 9161;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Echas un vistazo a las primeras páginas del viejo libro y llegas a la conclusión de que perteneció a Dar\'Khan Drathir.', 0),
(@ID, 'esMX', 'Echas un vistazo a las primeras páginas del viejo libro y llegas a la conclusión de que perteneció a Dar\'Khan Drathir.', 0);
-- 9159 Control de plagas
-- https://es.wowhead.com/quest=9159
SET @ID := 9159;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te has tomado la tarea en serio y me gustaría ofrecerte una recompensa adecuada. Necesitamos más aliados con tu coraje y tu osadía, $n.', 0),
(@ID, 'esMX', 'Te has tomado la tarea en serio y me gustaría ofrecerte una recompensa adecuada. Necesitamos más aliados con tu coraje y tu osadía, $n.', 0);
 -- 9277 Asalto a Zeb'Nowa
-- https://es.wowhead.com/quest=9277
SET @ID := 9277;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu asalto a Zeb\'Nowa ya está completo?', 0),
(@ID, 'esMX', '¿Tu asalto a Zeb\'Nowa ya está completo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Tendrías que hablar con el capitán para unirte a los Errantes.$B$BBien, $n, nos has hecho ganar tiempo para seguir reforzándonos. De hecho, según tu recuento, ¡no quedan muchos de esos trols por ahí! A lo mejor podemos unirnos a Tranquillien para atacar la Ciudad de la Muerte.$B$BTe has ganado una recompensa; elige lo que quieras.', 0),
(@ID, 'esMX', '¡Increíble! Tendrías que hablar con el capitán para unirte a los Errantes.$B$BBien, $n, nos has hecho ganar tiempo para seguir reforzándonos. De hecho, según tu recuento, ¡no quedan muchos de esos trols por ahí! A lo mejor podemos unirnos a Tranquillien para atacar la Ciudad de la Muerte.$B$BTe has ganado una recompensa; elige lo que quieras.', 0);
-- 9169 Desactivando An'owyn
-- https://es.wowhead.com/quest=9169
SET @ID := 9169;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cristal lunar de los elfos de la noche desactivado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se acabó, $c? ¿Desactivaste el cristal lunar de los elfos de la noche en An\'owyn?', 0),
(@ID, 'esMX', '¿Se acabó, $c? ¿Desactivaste el cristal lunar de los elfos de la noche en An\'owyn?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué alivio, $c! Te aseguro que si no hubieras desactivado los orbes de visión, nuestra posición sería aún más delicada de lo que ya es. Imagínatelo: ¡rodeados de enemigos y uno de ellos capaz de espiar todos nuestros movimientos!$B$BPero gracias a ti ya no tenemos que preocuparnos por eso. Ten; te mereces una recompensa y tengo unas cuantas cosas que ya no uso.$B$B¡Gracias otra vez, $n!', 0),
(@ID, 'esMX', '¡Qué alivio, $c! Te aseguro que si no hubieras desactivado los orbes de visión, nuestra posición sería aún más delicada de lo que ya es. Imagínatelo: ¡rodeados de enemigos y uno de ellos capaz de espiar todos nuestros movimientos!$B$BPero gracias a ti ya no tenemos que preocuparnos por eso. Ten; te mereces una recompensa y tengo unas cuantas cosas que ya no uso.$B$B¡Gracias otra vez, $n!', 0);
-- 9282 El Enclave del Errante
-- https://es.wowhead.com/quest=9282
SET @ID := 9282;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Kaendris te envió? Puede que tenga una tarea para ti, $c.', 0),
(@ID, 'esMX', '¿Kaendris te envió? Puede que tenga una tarea para ti, $c.', 0);
-- 9162 Huellas del pasado
-- https://es.wowhead.com/quest=9162
SET @ID := 9162;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n, ¿qué has averiguado?', 0),
(@ID, 'esMX', 'Dime, $n, ¿qué has averiguado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta información es muy valiosa, $n. Sabíamos que Dar\'Khan planeaba robar el poder de La Fuente del Sol para la Plaga, pero la información que hay aquí es completamente nueva. El magister Kaendris del Sagrario del Sol la encontrará muy interesante.', 0),
(@ID, 'esMX', 'Esta información es muy valiosa, $n. Sabíamos que Dar\'Khan planeaba robar el poder de La Fuente del Sol para la Plaga, pero la información que hay aquí es completamente nueva. El magister Kaendris del Sagrario del Sol la encontrará muy interesante.', 0);
-- 9172 Informa al magister Kaendris
-- https://es.wowhead.com/quest=9172
SET @ID := 9172;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías hablar conmigo?', 0),
(@ID, 'esMX', '¿Querías hablar conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué...? ¡No puede ser! Es la letra de Dar\'Khan; aquí tiene que haber información que revele algún punto débil de nuestro enemigo.$B$BHas hecho bien en venir a vernos, $n. Los Errantes han demostrado buen juicio al dejar este asunto en nuestras manos. Esta armadura te ayudará a luchar por nuestra causa.', 0),
(@ID, 'esMX', '¿Qué...? ¡No puede ser! Es la letra de Dar\'Khan; aquí tiene que haber información que revele algún punto débil de nuestro enemigo.$B$BHas hecho bien en venir a vernos, $n. Los Errantes han demostrado buen juicio al dejar este asunto en nuestras manos. Esta armadura te ayudará a luchar por nuestra causa.', 0);
-- 9176 Los zigurats gemelos
-- https://es.wowhead.com/quest=9176
SET @ID := 9176;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has recuperado las piedras?', 0),
(@ID, 'esMX', '¿Ya has recuperado las piedras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los rumores eran ciertos! ¡La piedra de luz y la piedra de llama existen! Usaremos su poder para crear armas contra Dar\'Khan.$B$BÚsalas en el momento apropiado y la energía de La Fuente del Sol, atrapada en estos objetos, lo derrotará ¡con el mismísimo poder que él creía habernos arrebatado!', 0),
(@ID, 'esMX', '¡Los rumores eran ciertos! ¡La piedra de luz y la piedra de llama existen! Usaremos su poder para crear armas contra Dar\'Khan.$B$BÚsalas en el momento apropiado y la energía de La Fuente del Sol, atrapada en estos objetos, lo derrotará ¡con el mismísimo poder que él creía habernos arrebatado!', 0);

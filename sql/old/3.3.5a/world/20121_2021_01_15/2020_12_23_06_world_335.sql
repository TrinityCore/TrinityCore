-- 758 La purificación de Tronacuerno
-- https://es.classic.wowhead.com/quest=758
SET @ID := 758;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El pozo de agua Tronacuerno todavía está contaminado, $n. ¡Por favor, debes realizar el ritual!', 0),
(@ID, 'esMX', 'El pozo de agua Tronacuerno todavía está contaminado, $n. ¡Por favor, debes realizar el ritual!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los antepasados del clan Tronacuerno me han hablado en un sueño para felicitarte por tus actos en el pozo.$B$BDesean que tengas esto como muestra de agradecimiento...', 0),
(@ID, 'esMX', 'Los antepasados del clan Tronacuerno me han hablado en un sueño para felicitarte por tus actos en el pozo.$B$BDesean que tengas esto como muestra de agradecimiento...', 0);
-- 759 El tótem Ferocrín
-- https://es.classic.wowhead.com/quest=759
SET @ID := 759;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes lo que te pedí?', 0),
(@ID, 'esMX', '¿Traes lo que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Este sacrificio de la tierra me llena de tristeza y también de orgullo.', 0),
(@ID, 'esMX', 'Gracias, $n. Este sacrificio de la tierra me llena de tristeza y también de orgullo.', 0);
-- 751 La Caravana Devastada
-- https://es.classic.wowhead.com/quest=751
SET @ID := 751;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. ¿Qué has descubierto sobre los planes de Ventura y Cía.?$B$BSi pretenden explotar nuestras tierras como han hecho con otras, los avanzados les harán cambiar de idea.', 0),
(@ID, 'esMX', 'Saludos, $n. ¿Qué has descubierto sobre los planes de Ventura y Cía.?$B$BSi pretenden explotar nuestras tierras como han hecho con otras, los avanzados les harán cambiar de idea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que Ventura y Cía. intenta robarnos nuestros recursos naturales. Es bueno saberlo, aunque ahora tenemos que hacer algo al respecto.', 0),
(@ID, 'esMX', 'Parece que Ventura y Cía. intenta robarnos nuestros recursos naturales. Es bueno saberlo, aunque ahora tenemos que hacer algo al respecto.', 0);
-- 764 Los Ventura y Cía.
-- https://es.classic.wowhead.com/quest=764
SET @ID := 764;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A Ventura y Cia. se le negaron los derechos mineros aquí en Mulgore, pero parece que no aceptan un no por respuesta. Sin embargo, los tauren no somos de los que nos andamos con rodeos, y tenemos otras formas de transmitir nuestro mensaje.', 0),
(@ID, 'esMX', 'A Ventura y Cia. se le negaron los derechos mineros aquí en Mulgore, pero parece que no aceptan un no por respuesta. Sin embargo, los tauren no somos de los que nos andamos con rodeos, y tenemos otras formas de transmitir nuestro mensaje.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que resulta difícil malinterpretar o ignorar esa señal, ¿no? En Ventura y Cía. sabrán que no deben tomar a los tauren a la ligera, y no serán tan arrogantes de pensar que permitiremos que nos roben los recursos naturales sin rechistar.', 0),
(@ID, 'esMX', 'Supongo que resulta difícil malinterpretar o ignorar esa señal, ¿no? En Ventura y Cía. sabrán que no deben tomar a los tauren a la ligera, y no serán tan arrogantes de pensar que permitiremos que nos roben los recursos naturales sin rechistar.', 0);
-- 765 Supervisor Saltatuercas
-- https://es.classic.wowhead.com/quest=765
SET @ID := 765;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me hierve la sangre solo de pensar en las atrocidades que están dispuestos a llevar a cabo contra nosotros en Ventura y Cía. para obtener beneficios.', 0),
(@ID, 'esMX', 'Me hierve la sangre solo de pensar en las atrocidades que están dispuestos a llevar a cabo contra nosotros en Ventura y Cía. para obtener beneficios.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que mi rabia se apacigua ante la idea de que el maleante de Saltatuercas esté muerto. Revisaré sus efectos personales para ver si hay algo más de información sobre los planes futuros de Ventura y Cía. Gracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'Parece que mi rabia se apacigua ante la idea de que el maleante de Saltatuercas esté muerto. Revisaré sus efectos personales para ver si hay algo más de información sobre los planes futuros de Ventura y Cía. Gracias por tu ayuda, $n.', 0);
-- 760 La purificación de Ferocrín
-- https://es.classic.wowhead.com/quest=760
SET @ID := 760;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has limpiado los pozos y sanado nuestra tierra; el Poblado Pezuña de Sangre te está agradecido, $n.$B$BQue tus hazañas sean cantadas hasta la séptima generación de la séptima generación.', 0),
(@ID, 'esMX', 'Has limpiado los pozos y sanado nuestra tierra; el Poblado Pezuña de Sangre te está agradecido, $n.$B$BQue tus hazañas sean cantadas hasta la séptima generación de la séptima generación.', 0);
-- 772 Rito de la Visión
-- https://es.classic.wowhead.com/quest=772
SET @ID := 772;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tengas miedo, $n. Has superado el Rito de la Visión.', 0),
(@ID, 'esMX', 'No tengas miedo, $n. Has superado el Rito de la Visión.', 0);
-- 773 Rito de la Sabiduría
-- https://es.classic.wowhead.com/quest=773
SET @ID := 773;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has puesto gran voluntad en superar los Ritos de la Madre Tierra, $n.$B$BLos espíritus ancestrales representamos a los tauren que dieron la vida para fundar y proteger Cima del Trueno. Ahora ese deber de protección pasa a ti.$B$BHas superado el Rito de la Sabiduría, $c. Entra en Cima del Trueno con orgullo.', 0),
(@ID, 'esMX', 'Has puesto gran voluntad en superar los Ritos de la Madre Tierra, $n.$B$BLos espíritus ancestrales representamos a los tauren que dieron la vida para fundar y proteger Cima del Trueno. Ahora ese deber de protección pasa a ti.$B$BHas superado el Rito de la Sabiduría, $c. Entra en Cima del Trueno con orgullo.', 0);
-- 861 Los hábitos del cazador
-- https://es.classic.wowhead.com/quest=861
SET @ID := 861;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. Presiento que vienes a pedirme instrucción, ¿me equivoco?', 0),
(@ID, 'esMX', 'Saludos. Presiento que vienes a pedirme instrucción, ¿me equivoco?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, vienes de parte de un gran cazador con mucha experiencia; su cuerpo será viejo, pero su espíritu aún es fiero y nos honra contar con él.$B$BVeo por estas garras que tienes habilidad innata para la caza.$B$BSí, puede que ese sea tu camino.', 0),
(@ID, 'esMX', 'Ah, vienes de parte de un gran cazador con mucha experiencia; su cuerpo será viejo, pero su espíritu aún es fiero y nos honra contar con él.$B$BVeo por estas garras que tienes habilidad innata para la caza.$B$BSí, puede que ese sea tu camino.', 0);
-- 5926 Escucha la llamada
-- https://es.classic.wowhead.com/quest=5926
SET @ID := 5926;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0),
(@ID, 'esMX', 'Me alegro de que encontraras el camino hasta aquí, joven $c. Ha llegado el momento de que des un gran paso y te adentres en un mundo más grande.$B$BTodos los hijos de Cenarius servimos a la naturaleza. Los animales y las plantas son nuestros amigos y también nuestros protegidos. Elegimos dedicar nuestra vida a preservar el equilibrio, por su bien, tanto como por el nuestro. Tu primer paso en este mundo será aprender el camino del oso y aprender de la fuerza del cuerpo y del espíritu.$B$B¡Prepárate!', 0);
-- 833 Cementerio sagrado
-- https://es.classic.wowhead.com/quest=833
SET @ID := 833;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay que expulsar a los intrusos Erizapúas de nuestro cementerio sagrado, $n.', 0),
(@ID, 'esMX', 'Hay que expulsar a los intrusos Erizapúas de nuestro cementerio sagrado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Esos Erizapúas se lo pensarán dos veces antes de volver a acercarse a este lugar sagrado.', 0),
(@ID, 'esMX', 'Muy bien. Esos Erizapúas se lo pensarán dos veces antes de volver a acercarse a este lugar sagrado.', 0);
-- 775 Viaje a Cima del Trueno
-- https://es.classic.wowhead.com/quest=775
SET @ID := 775;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Veo que has hallado el sendero hasta mi puerta.', 0),
(@ID, 'esMX', 'Saludos, $c. Veo que has hallado el sendero hasta mi puerta.', 0);
-- 5922 Claro de la Luna
-- https://es.classic.wowhead.com/quest=5922
SET @ID := 5922;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Aquí empieza, Padre Cenarius. Aquí empieza."$B$BDendrita hace un rápido e invisible gesto en el aire por encima de su cabeza, y una ligera aura de poder cae sobre él.$B$B"La primera perspectiva de la naturaleza a la que debes adaptarte es la del oso. Yo te orientaré para que entiendas este aspecto de la vida de los druidas, pero eres tú quien debe seguir el camino y propagarlo... ¡ahora y siempre!"', 0),
(@ID, 'esMX', '"Aquí empieza, Padre Cenarius. Aquí empieza."$B$BDendrita hace un rápido e invisible gesto en el aire por encima de su cabeza, y una ligera aura de poder cae sobre él.$B$B"La primera perspectiva de la naturaleza a la que debes adaptarte es la del oso. Yo te orientaré para que entiendas este aspecto de la vida de los druidas, pero eres tú quien debe seguir el camino y propagarlo... ¡ahora y siempre!"', 0);
-- 5930 Espíritu del gran oso
-- https://es.classic.wowhead.com/quest=5930
SET @ID := 5930;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Regresa solo cuando el Espíritu del gran oso te mande que vuelvas conmigo. Tu entrenamiento no puede continuar sin su bendición.', 0),
(@ID, 'esMX', 'Regresa solo cuando el Espíritu del gran oso te mande que vuelvas conmigo. Tu entrenamiento no puede continuar sin su bendición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras te acercas, Dendrita hace otro gesto. Aparece otra aura de poder sobre él y te sonríe.$B$B"Hay en ti sabiduría nueva. Tu mirada refleja fuerza y decisión, pero debes aprender a dominarlas. Aprenderás a concentrarte y a adoptar las estrategias del oso."', 0),
(@ID, 'esMX', 'Mientras te acercas, Dendrita hace otro gesto. Aparece otra aura de poder sobre él y te sonríe.$B$B"Hay en ti sabiduría nueva. Tu mirada refleja fuerza y decisión, pero debes aprender a dominarlas. Aprenderás a concentrarte y a adoptar las estrategias del oso."', 0);
-- 5932 Vuelve a Cima del Trueno
-- https://es.classic.wowhead.com/quest=5932
SET @ID := 5932;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Veo que tu primer encuentro con el Espíritu del gran oso fue, como para todos los druidas, inquietante pero intenso; también lo fue para mí.$B$BEl Espíritu del gran oso ha residido en Azeroth desde el principio de los tiempos. Los tauren escuchamos atentamente a esos espíritus, y todos prosperamos de su propósito. Ahora, ha llegado el momento de que pases la primera prueba de ese propósito. Escucha con atención…', 0),
(@ID, 'esMX', 'Saludos, $n. Veo que tu primer encuentro con el Espíritu del gran oso fue, como para todos los druidas, inquietante pero intenso; también lo fue para mí.$B$BEl Espíritu del gran oso ha residido en Azeroth desde el principio de los tiempos. Los tauren escuchamos atentamente a esos espíritus, y todos prosperamos de su propósito. Ahora, ha llegado el momento de que pases la primera prueba de ese propósito. Escucha con atención…', 0);
-- 776 Los ritos de la Madre Tierra
-- https://es.classic.wowhead.com/quest=776
SET @ID := 776;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has localizado a Arra’chea?', 0),
(@ID, 'esMX', '¿Ya has localizado a Arra’chea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo!$B$BEnviaré a un grupo para retirar la piel y la carne.$B$BTu gente te debe mucho, $n.', 0),
(@ID, 'esMX', '¡Buen trabajo!$B$BEnviaré a un grupo para retirar la piel y la carne.$B$BTu gente te debe mucho, $n.', 0);
-- 5722 Buscando la cartera perdida
-- https://es.classic.wowhead.com/quest=5722
SET @ID := 5722;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cuerpo presenta muchos golpes pero la ropa y el equipo están intactos. Parece que a los troggs no les interesa mucho la riqueza material.$B$BEmpiezas a inspeccionar el cuerpo en busca de algo que le pueda resultar de interés a Magatha.', 0),
(@ID, 'esMX', 'El cuerpo presenta muchos golpes pero la ropa y el equipo están intactos. Parece que a los troggs no les interesa mucho la riqueza material.$B$BEmpiezas a inspeccionar el cuerpo en busca de algo que le pueda resultar de interés a Magatha.', 0);
-- 5723 Midiendo fuerzas con el enemigo
-- https://es.classic.wowhead.com/quest=5723
SET @ID := 5723;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda por Sima Ígnea? ¿Y los troggs?$B$BNo se puede permitir que la amenaza persista; solo dañará a nuestros hermanos orcos si continúa.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda por Sima Ígnea? ¿Y los troggs?$B$BNo se puede permitir que la amenaza persista; solo dañará a nuestros hermanos orcos si continúa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que te hayas tomado en serio la tarea que te encomendó Magatha. Gracias, $n. Estoy seguro de que los troggs no se recuperarán tan fácilmente después de haber sufrido tantas bajas.$B$BQuizás en un futuro tengamos tiempo de investigar de dónde proceden estas criaturas y cuál es su auténtico propósito.', 0),
(@ID, 'esMX', 'Me alegro de que te hayas tomado en serio la tarea que te encomendó Magatha. Gracias, $n. Estoy seguro de que los troggs no se recuperarán tan fácilmente después de haber sufrido tantas bajas.$B$BQuizás en un futuro tengamos tiempo de investigar de dónde proceden estas criaturas y cuál es su auténtico propósito.', 0);
-- 6002 Cuerpo y corazón
-- https://es.classic.wowhead.com/quest=6002
SET @ID := 6002;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has dado ese gran paso, $n, te has adentrado en un mundo mucho más grande. Percibo en ti las enseñanzas del espíritu del gran oso y percibo que has recibido la fuerza que poseía Garraluna.$B$BYa no hay obstáculos en tu camino... ¡Deja que te enseñe lo que significa ser un $c de la Zarpa!', 0),
(@ID, 'esMX', 'Por fin has dado ese gran paso, $n, te has adentrado en un mundo mucho más grande. Percibo en ti las enseñanzas del espíritu del gran oso y percibo que has recibido la fuerza que poseía Garraluna.$B$BYa no hay obstáculos en tu camino... ¡Deja que te enseñe lo que significa ser un $c de la Zarpa!', 0);
-- 860 Sergra Espinoscura
-- https://es.classic.wowhead.com/quest=860
SET @ID := 860;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Deseas cazar en Los Baldíos?$B$BEres joven e irradias entusiasmo, pero todavía no estás $gpreparado:preparada; para perseguir a una presa por las llanuras de este lugar.$B$BDe todos modos, no te preocupes. Trabajaremos para fortalecer tu cuerpo y tu mente y aprenderás que cazar no solo consiste en encontrar y matar a tu presa.$B$BPrepárate pues tu viaje comienza aquí y ahora.', 0),
(@ID, 'esMX', '¿Deseas cazar en Los Baldíos?$B$BEres joven e irradias entusiasmo, pero todavía no estás $gpreparado:preparada; para perseguir a una presa por las llanuras de este lugar.$B$BDe todos modos, no te preocupes. Trabajaremos para fortalecer tu cuerpo y tu mente y aprenderás que cazar no solo consiste en encontrar y matar a tu presa.$B$BPrepárate pues tu viaje comienza aquí y ahora.', 0);
-- 744 Preparación para la ceremonia
-- https://es.classic.wowhead.com/quest=744
SET @ID := 744;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este penacho será el regalo perfecto para mi hermano.', 0),
(@ID, 'esMX', 'Este penacho será el regalo perfecto para mi hermano.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n.$B$BYa casi he acabado el penacho. Tan solo me queda entregárselo a mi hermano y presenciar la ceremonia.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n.$B$BYa casi he acabado el penacho. Tan solo me queda entregárselo a mi hermano y presenciar la ceremonia.', 0);
-- 732 Terremotos
-- https://es.classic.wowhead.com/quest=732
SET @ID := 732;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El grupo de ogros nómadas se desplaza entre sus campamentos por las Tierras Inhóspitas; el calor que despide la reseca tierra y los remolinos de viento dificultarán su rastreo. He oído que a veces pasan por el Asentamiento Boff. Si estás perdido, podrías empezar a buscar allí.', 0),
(@ID, 'esMX', 'El grupo de ogros nómadas se desplaza entre sus campamentos por las Tierras Inhóspitas; el calor que despide la reseca tierra y los remolinos de viento dificultarán su rastreo. He oído que a veces pasan por el Asentamiento Boff. Si estás perdido, podrías empezar a buscar allí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es buena noticia que lleves el Signo, $n. Los enanos Hierro Negro de la Fortaleza de Angor crearon el Signo de la Tierra para retener a dos de los más crueles tenientes Alamuerte, los gemelos Cinchoscura y Hematus.', 0),
(@ID, 'esMX', 'Es buena noticia que lleves el Signo, $n. Los enanos Hierro Negro de la Fortaleza de Angor crearon el Signo de la Tierra para retener a dos de los más crueles tenientes Alamuerte, los gemelos Cinchoscura y Hematus.', 0);
-- 734 Lo tienes crudo
-- https://es.classic.wowhead.com/quest=734
SET @ID := 734;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Piñón del n.º 5, ¿eh? Sí, esto no va a valer.', 0),
(@ID, 'esMX', 'Piñón del n.º 5, ¿eh? Sí, esto no va a valer.', 0);
-- 736 La Estrella, la Mano y el Corazón
-- https://es.classic.wowhead.com/quest=736
SET @ID := 736;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu misión, $c?', 0),
(@ID, 'esMX', '¿Cómo va tu misión, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estoy impresionado! Posees una gran habilidad, o una gran suerte, por haber conseguido estas reliquias. De cualquier manera, eres un gran activo para nosotros.', 0),
(@ID, 'esMX', '¡Estoy impresionado! Posees una gran habilidad, o una gran suerte, por haber conseguido estas reliquias. De cualquier manera, eres un gran activo para nosotros.', 0);
-- 742 La Caza de Vallefresno
-- https://es.classic.wowhead.com/quest=742
SET @ID := 742;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a la nueva frontera, $n. Vallefresno es una tierra de oportunidades en la que $gun:una; joven $c como tú cuenta con innumerables oportunidades de demostrar lo que vale. Date una vuelta por el Puesto del Hachazo y no olvides visitar La Ensenada de Zoram, la otra avanzada de la Horda.$B$BTu presencia aquí me indica que has venido a instruirte en las artes de la caza. Escucha con atención y con gusto te enseñaré todo lo que has de saber.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a la nueva frontera, $n. Vallefresno es una tierra de oportunidades en la que $gun:una; joven $c como tú cuenta con innumerables oportunidades de demostrar lo que vale. Date una vuelta por el Puesto del Hachazo y no olvides visitar La Ensenada de Zoram, la otra avanzada de la Horda.$B$BTu presencia aquí me indica que has venido a instruirte en las artes de la caza. Escucha con atención y con gusto te enseñaré todo lo que has de saber.', 0);
-- 769 Bolsa de pellejo de kodo
-- https://es.classic.wowhead.com/quest=769
SET @ID := 769;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi material, $n?', 0),
(@ID, 'esMX', '¿Tienes mi material, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien. Gracias, $n. Mi corazón se hinche de orgullo al ver que los jóvenes se interesan por el arte de la peletería.', 0),
(@ID, 'esMX', 'Ah, bien. Gracias, $n. Mi corazón se hinche de orgullo al ver que los jóvenes se interesan por el arte de la peletería.', 0);
-- 770 La capa del demonio marcado
-- https://es.classic.wowhead.com/quest=770
SET @ID := 770;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo creerlo! ¿Has derrotado a Aullido Fantasma? Acabas de ganarte mi respeto con tu habilidad para la caza, $c.$B$BYo ya no cazo, pero me honraría regalarte una de mis armas.$B$BQue te traiga reconocimiento y fortuna.$B$BEsperemos que Aullido Fantasma haya encontrado al fin la paz.', 0),
(@ID, 'esMX', '¡No puedo creerlo! ¿Has derrotado a Aullido Fantasma? Acabas de ganarte mi respeto con tu habilidad para la caza, $c.$B$BYo ya no cazo, pero me honraría regalarte una de mis armas.$B$BQue te traiga reconocimiento y fortuna.$B$BEsperemos que Aullido Fantasma haya encontrado al fin la paz.', 0);
-- 777 Lo tienes crudo
-- https://es.classic.wowhead.com/quest=777
SET @ID := 777;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Sin apartar la vista de los grilletes, Lotwil levanta una mano y agita los dedos con impaciencia.>$B$B¡El piñón, $n, el piñón!', 0),
(@ID, 'esMX', '<Sin apartar la vista de los grilletes, Lotwil levanta una mano y agita los dedos con impaciencia.>$B$B¡El piñón, $n, el piñón!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, perfecto. ¡Retrocede mientras me preparo para hacer historia!$B$B<Lotwil sigue trabajando febrilmente.>', 0),
(@ID, 'esMX', 'Ah, perfecto. ¡Retrocede mientras me preparo para hacer historia!$B$B<Lotwil sigue trabajando febrilmente.>', 0);

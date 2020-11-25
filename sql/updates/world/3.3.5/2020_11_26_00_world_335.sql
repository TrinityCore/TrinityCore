-- Bálsamo por desuello
-- 4106, 4111, 5885, 5890
-- https://es.classic.wowhead.com/quest=4111
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4106, 4111, 5885, 5890) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4106, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(4111, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5885, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5890, 'esES', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(4106, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(4111, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5885, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0),
(5890, 'esMX', 'Una antorcha Cenarion permite a un desollador experto detectar parches de piel manchados en las presas cazadas en Frondavil. Yo convierto esos parches aparentemente inútiles en una pasta espesa que utilizo después como agente acelerador para el bálsamo de planta Cenarion. Cuando desuelles las presas que caces en Frondavil, asegúrate de llevar una antorcha contigo.$B$BSi recoges parches manchados, tráemelos y te daré unos bálsamos de planta Cenarion que tengo preparados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4106, 4111, 5885, 5890) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4106, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(4111, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5885, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5890, 'esES', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(4106, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(4111, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5885, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0),
(5890, 'esMX', '¡Son exactamente lo que necesito! Ten, llévate estos bálsamos de planta y utilízalos para eliminar la corrupción de Frondavil. ¡Debemos perseverar, $n!', 0);
-- Bálsamo por minería
-- 4104, 4109, 5883, 5888
-- https://es.classic.wowhead.com/quest=4104
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4104, 4109, 5883, 5888) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4104, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(4109, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5883, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5888, 'esES', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(4104, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(4109, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5883, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0),
(5888, 'esMX', 'Si llevas una antorcha Cenarion mientras trabajas en los yacimientos de Frondavil, podrás ver el vitriolo contaminado que corrompe una veta del metal. Yo sé cómo purificar ese vitriolo y cómo convertirlo en un componente del bálsamo de planta de Cenarion. Un bálsamo que podrás utilizar para salvar las plantas que encuentres en el bosque.$B$BSi me traes algo de vitriolo contaminado, te daré un bálsamo de planta de Cenarion que tengo preparado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4104, 4109, 5883, 5888) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4104, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(4109, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5883, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5888, 'esES', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(4104, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(4109, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5883, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0),
(5888, 'esMX', 'Muy bien. Aquí tienes algunos bálsamos de planta de Cenarion. Si encuentras más vitriolo cuando extraigas minerales en Frondavil, ¡acuérdate de reservármelo! Cuanto más encuentres, más bálsamo podré preparar.', 0);
-- Bálsamo por recolección
-- 4105, 4110, 5884, 5889
-- https://es.classic.wowhead.com/quest=4105
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4105, 4110, 5884, 5889) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4105, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(4110, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5884, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5889, 'esES', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(4105, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(4110, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5884, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0),
(5889, 'esMX', 'Una antorcha Cenarion permite a un herborista experimentado detectar cualquier agente máculo insidioso, un criminal producto de la corrupción de Frondavil. Trabajando aquí he aprendido a purificar el agente máculo y convertirlo en un agente purificador... uno que se usa en lo que ahora llamamos bálsamo de planta de Cenarion.$B$BSi llevas la antorcha contigo mientras recoges hierbas en Frondavil, deberías poder ver el agente máculo. A cambio de lo que me traigas, te daré un poco de bálsamo de planta de Cenarion que tengo ya preparado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4105, 4110, 5884, 5889) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4105, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(4110, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5884, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5889, 'esES', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(4105, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(4110, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5884, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0),
(5889, 'esMX', 'Un trabajo excelente, $n. Cada gotita, una vez purificada, nos ayudará a recuperar Frondavil. Ten, llévate algunas dosis de bálsamo de planta de Cenarion y adéntrate en el bosque. Y date prisa: ¡debemos sanar la tierra cuanto antes, $r!', 0);
-- Dragón nocturno corrupto
-- 4119, 4447, 4448, 4462
-- https://es.classic.wowhead.com/quest=4119
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4119, 4447, 4448, 4462) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4119, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4447, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4448, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4462, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4119, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4447, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4448, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0),
(4462, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta dragón nocturno. Los frutos que cuelgan de la planta están podridos y envenenados. Necesita desesperadamente ser atendida para recuperar su estado normal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4119, 4447, 4448, 4462) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4119, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4447, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4448, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4462, 'esES', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4119, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4447, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4448, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0),
(4462, 'esMX', 'Aplicas cuatro bálsamos de planta de Cenarion a la dragón nocturno. Inmediatamente empieza a mudar su forma corrupta y se transforma en una planta rebosante de salud.', 0);
-- 5158 Buscando ayuda espiritual
-- https://es.classic.wowhead.com/quest=5158
SET @ID := 5158;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Percibo que no eres un viajero corriente buscando el camino a Trinquete. Ven, siéntate y descansa en nuestro campamento. Habla conmigo cuando estés listo.', 0),
(@ID, 'esMX', 'Percibo que no eres un viajero corriente buscando el camino a Trinquete. Ven, siéntate y descansa en nuestro campamento. Habla conmigo cuando estés listo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, necesitas limpiar el agua de esta Poza de la Luna. Detener esta fuente de maldad de Frondavil es una noble acción, pero yo no soy quién para decidir si el agua será purificada. Preguntaré a los espíritus del Agua. Ellos son quienes deciden si la causa es justa.$B$BDame un momento, les hablaré de tu ruego. Espero que simpaticen con tu causa como yo.', 0),
(@ID, 'esMX', 'Ah, necesitas limpiar el agua de esta Poza de la Luna. Detener esta fuente de maldad de Frondavil es una noble acción, pero yo no soy quién para decidir si el agua será purificada. Preguntaré a los espíritus del Agua. Ellos son quienes deciden si la causa es justa.$B$BDame un momento, les hablaré de tu ruego. Espero que simpaticen con tu causa como yo.', 0);
-- 4842 Fuentes extrañas
-- https://es.classic.wowhead.com/quest=4842
SET @ID := 4842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El agua de los manantiales parece tener algunas propiedades muy extrañas... Todavía no estoy segura de lo que significa...', 0),
(@ID, 'esMX', 'El agua de los manantiales parece tener algunas propiedades muy extrañas... Todavía no estoy segura de lo que significa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, los demonios de Garganta Negro Rumor... creo que su presencia es la que está afectando así a esta tierra. Voy a seguir observando las fuentes termales para ver si averiguo algo más.$B$BSi tienes planes de seguir adentrándote en la Garganta Negro Rumor te convendría esperar a ser un poco más fuerte.', 0),
(@ID, 'esMX', 'Sí, los demonios de Garganta Negro Rumor... creo que su presencia es la que está afectando así a esta tierra. Voy a seguir observando las fuentes termales para ver si averiguo algo más.$B$BSi tienes planes de seguir adentrándote en la Garganta Negro Rumor te convendría esperar a ser un poco más fuerte.', 0);
-- 8464 Actividad de los Nevada
-- https://es.classic.wowhead.com/quest=8464
SET @ID := 8464;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apreciamos mucho lo que has hecho por los Fauce de Madera, $n. Tus continuos esfuerzos seguramente ganarán la confianza y el respeto de mi tribu.', 0),
(@ID, 'esMX', 'Apreciamos mucho lo que has hecho por los Fauce de Madera, $n. Tus continuos esfuerzos seguramente ganarán la confianza y el respeto de mi tribu.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por todo lo que has hecho, aunque haya sido una misión ciertamente entristecedora. Acepta esto como muestra de gratitud.$B$BTe pediría que siguieras ayudándonos, $n. Tenemos pocos aliados a los que recurrir y sin tu ayuda no podremos afrontar todas las amenazas que se ciernen contra mi tribu.', 0),
(@ID, 'esMX', 'Gracias por todo lo que has hecho, aunque haya sido una misión ciertamente entristecedora. Acepta esto como muestra de gratitud.$B$BTe pediría que siguieras ayudándonos, $n. Tenemos pocos aliados a los que recurrir y sin tu ayuda no podremos afrontar todas las amenazas que se ciernen contra mi tribu.', 0);
-- 8469 Cuentas para Salfa
-- https://es.classic.wowhead.com/quest=8469
SET @ID := 8469;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sabido ganarte mi confianza, $n, pero aún tendrás que ganarte la confianza de mi tribu. Hay algo que puedes hacer para conseguirlo.$B$BSe sabe que los Nevada llevan consigo cuentas de espíritus para protegerse contra los espíritus infectos. Esas cuentas no han cumplido sus propósitos ya que los propios Nevada se han convertido en agentes de corrupción. Tráeme las cuentas de espíritu de los furbolgs Nevada caídos, por cada cinco que me traigas aumentará tu reconocimiento entre los Fauces de Madera.', 0),
(@ID, 'esMX', 'Has sabido ganarte mi confianza, $n, pero aún tendrás que ganarte la confianza de mi tribu. Hay algo que puedes hacer para conseguirlo.$B$BSe sabe que los Nevada llevan consigo cuentas de espíritus para protegerse contra los espíritus infectos. Esas cuentas no han cumplido sus propósitos ya que los propios Nevada se han convertido en agentes de corrupción. Tráeme las cuentas de espíritu de los furbolgs Nevada caídos, por cada cinco que me traigas aumentará tu reconocimiento entre los Fauces de Madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nos has probado una vez más tu honor! Me aseguraré de que los míos conozcan todas tus hazañas.$B$BRecuerda traerme todas las cuentas de los Nevada que encuentres. Por cada juego que me traigas hablaré de ti a la tribu.', 0),
(@ID, 'esMX', '¡Nos has probado una vez más tu honor! Me aseguraré de que los míos conozcan todas tus hazañas.$B$BRecuerda traerme todas las cuentas de los Nevada que encuentres. Por cada juego que me traigas hablaré de ti a la tribu.', 0);
-- 5159 El agua purificada vuelve a Frondavil
-- https://es.classic.wowhead.com/quest=5159
SET @ID := 5159;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, veo que has vuelto, $n. Bien. ¿Encontraste a Islen en Los Baldíos? ¿O tenemos que encontrar otra manera de lograr nuestros objetivos?', 0),
(@ID, 'esMX', 'Ah, veo que has vuelto, $n. Bien. ¿Encontraste a Islen en Los Baldíos? ¿O tenemos que encontrar otra manera de lograr nuestros objetivos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta agua debería ser suficiente para nuestros propósitos.$B$BMe alegra que Islen pudiera ayudarnos. Su fuerza sobre los espíritus del agua ha sido siempre considerable. Y también es sabia. Raras son las veces que los espíritus no están de acuerdo con ella. El hecho de que ambos hayan bendecido nuestra causa me da esperanza: estamos en el buen camino.', 0),
(@ID, 'esMX', 'Esta agua debería ser suficiente para nuestros propósitos.$B$BMe alegra que Islen pudiera ayudarnos. Su fuerza sobre los espíritus del agua ha sido siempre considerable. Y también es sabia. Raras son las veces que los espíritus no están de acuerdo con ella. El hecho de que ambos hayan bendecido nuestra causa me da esperanza: estamos en el buen camino.', 0);
-- 3961 La aventura de Linken
-- https://es.classic.wowhead.com/quest=3961
SET @ID := 3961;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola de nuevo, $n!', 0),
(@ID, 'esMX', '¡Hola de nuevo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ayudó J.D. en algo?', 0),
(@ID, 'esMX', '¿Te ayudó J.D. en algo?', 0);
-- 3962 Ir solo es peligroso
-- https://es.classic.wowhead.com/quest=3962
SET @ID := 3962;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La protección del aura que creó sirviéndose de la Llama Dorada hace a Correfuego prácticamente invencible. Solo tú tienes el poder para eliminarla gracias al Tótem plateado de Aquamentas.', 0),
(@ID, 'esMX', 'La protección del aura que creó sirviéndose de la Llama Dorada hace a Correfuego prácticamente invencible. Solo tú tienes el poder para eliminarla gracias al Tótem plateado de Aquamentas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BLa Llama Dorada volverá por fin a mi hogar, allí la protegerán y nunca volverá a caer en manos del mal.$B$B¡Sin tu ayuda todavía seguiría sin saber quién soy! Como has hecho tanto por mí, me gustaría darte algo muy especial...$B$B¡Elige lo que quieras!', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BLa Llama Dorada volverá por fin a mi hogar, allí la protegerán y nunca volverá a caer en manos del mal.$B$B¡Sin tu ayuda todavía seguiría sin saber quién soy! Como has hecho tanto por mí, me gustaría darte algo muy especial...$B$B¡Elige lo que quieras!', 0);
-- 5165 Sofocar las llamas de protección
-- https://es.classic.wowhead.com/quest=5165
SET @ID := 5165;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los blandones deben apagarse si queremos tener alguna esperanza de estar preparados para una batalla mucho mayor. Entrar en la guarida del dragón sin ningún conocimiento es una tarea tonta. Y esto es mucho peor que un dragón. El Consejo de la Sombra es el único responsable de una gran cantidad de crímenes y atrocidades. Tendremos que trabajar rápido si queremos detenerlos.', 0),
(@ID, 'esMX', 'Los blandones deben apagarse si queremos tener alguna esperanza de estar preparados para una batalla mucho mayor. Entrar en la guarida del dragón sin ningún conocimiento es una tarea tonta. Y esto es mucho peor que un dragón. El Consejo de la Sombra es el único responsable de una gran cantidad de crímenes y atrocidades. Tendremos que trabajar rápido si queremos detenerlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pude verte con mis hechizos en cuanto murieron las llamas del último blandón. Buen trabajo, $n.$B$BConseguí averiguar algunas cosas antes de que los brujos del Consejo de la Sombra reaccionaran. Espero que sea suficiente.$B$BAhora descansa un poco. Te diré lo que he averiguado en un momento.', 0),
(@ID, 'esMX', 'Pude verte con mis hechizos en cuanto murieron las llamas del último blandón. Buen trabajo, $n.$B$BConseguí averiguar algunas cosas antes de que los brujos del Consejo de la Sombra reaccionaran. Espero que sea suficiente.$B$BAhora descansa un poco. Te diré lo que he averiguado en un momento.', 0);
-- 5149 La muñeca de Pamela
-- https://es.classic.wowhead.com/quest=5149
SET @ID := 5149;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mi muñeca?', 0),
(@ID, 'esMX', '¿Has encontrado mi muñeca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La has encontrado! ¡Has encontrado a mi muñeca! ¡Gracias!', 0),
(@ID, 'esMX', '¡La has encontrado! ¡Has encontrado a mi muñeca! ¡Gracias!', 0);
-- 5152 Tía Marlene
-- https://es.classic.wowhead.com/quest=5152
SET @ID := 5152;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a Pamela? ¿Y cómo está? ¿¿Está viva?? ¡Oh, no! ¡Pobre Pamela! Era tan joven y tan alegre...$B$BNo sabe lo que le ocurrió a su padre, ¿verdad? ¿Mi hermano Joseph?$B$BNo... ella no podía entender lo que le ocurrió a Joseph. Y aunque pudiera, no tengo valor para contárselo...', 0),
(@ID, 'esMX', '¿Has visto a Pamela? ¿Y cómo está? ¿¿Está viva?? ¡Oh, no! ¡Pobre Pamela! Era tan joven y tan alegre...$B$BNo sabe lo que le ocurrió a su padre, ¿verdad? ¿Mi hermano Joseph?$B$BNo... ella no podía entender lo que le ocurrió a Joseph. Y aunque pudiera, no tengo valor para contárselo...', 0);
-- 5241 Tío Carlin
-- https://es.classic.wowhead.com/quest=5241
SET @ID := 5241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a Pamela? ¿Está viva?$B$B¿Está muerta? ¡No! ¡Oh, Pamela! ¿Por qué debe sufrir tu espíritu en este mundo? ¿Por qué tú has perecido, mientras la fortuna me mantiene a mí con vida? ¡Ojalá pudiera cambiar mi lugar con el tuyo y vagar por Villa Darrow como un fantasma, cargando con tu soledad!$B$BPero esta noticia no puede cambiar el destino. Gracias, $n. Ahora mi voluntad de cumplir con mi deber, mi deber de vengarme, es más fuerte que nunca.', 0),
(@ID, 'esMX', '¿Has visto a Pamela? ¿Está viva?$B$B¿Está muerta? ¡No! ¡Oh, Pamela! ¿Por qué debe sufrir tu espíritu en este mundo? ¿Por qué tú has perecido, mientras la fortuna me mantiene a mí con vida? ¡Ojalá pudiera cambiar mi lugar con el tuyo y vagar por Villa Darrow como un fantasma, cargando con tu soledad!$B$BPero esta noticia no puede cambiar el destino. Gracias, $n. Ahora mi voluntad de cumplir con mi deber, mi deber de vengarme, es más fuerte que nunca.', 0);
-- 6021 Zaeldarr el Marginado
-- https://es.classic.wowhead.com/quest=6021
SET @ID := 6021;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el escondite, $n? ¿Te has encargado de Zaeldarr?', 0),
(@ID, 'esMX', '¿Encontraste el escondite, $n? ¿Te has encargado de Zaeldarr?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Genial, lo tienes! ¡Y espero que también le hayas dado una lección a su pandilla!', 0),
(@ID, 'esMX', 'Genial, lo tienes! ¡Y espero que también le hayas dado una lección a su pandilla!', 0);

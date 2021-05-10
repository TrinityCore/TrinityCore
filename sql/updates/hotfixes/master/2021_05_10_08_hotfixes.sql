DELETE FROM `broadcast_text_locale` WHERE `locale` = 'ptBR' AND `ID` IN (209968, 208581);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(209968, 'ptBR', '', 'Boas-vindas, camarada. Você tem algum interesse em pedras-chave?', 38134),
(208581, 'ptBR', 'Saudações, NOME DE USUÁRIO. Espero que esteja tendo um dia ADJETIVO POSITIVO GERADO ALEATORIAMENTE.', '', 38134);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'ptBR', 'Óculos Escuros de Vidrilho', 38134);

DELETE FROM `currency_types_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1191, 'ptBR', 'Bravura', 'Moeda usada para aumentar o poder de itens de masmorras Míticas.', 38134),
(1602, 'ptBR', 'Dominação', 'Ganha em atividades JxJ Ranqueadas. Use para obter equipamento em Oribos.', 38134),
(1828, 'ptBR', 'Cinzas d\'Alma', 'Uma fonte de poder bruta encontrada no Thanator. Usada para alimentar a Câmara do Entalhador de Runas.', 38134);

DELETE FROM `spell_name_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(328547, 'ptBR', 'Espigão Ósseo Serrilhado', 38134),
(335718, 'ptBR', 'Represália', 38134),
(340882, 'ptBR', 'Chamar Bolsa de Gás', 38134),
(351967, 'ptBR', 'Chamar Rosatroz', 38134),
(320914, 'ptBR', 'Ampulheta do Cronomante', 38134),
(350249, 'ptBR', 'Distorção Temporal', 38134),
(320740, 'ptBR', 'Fixar', 38134),
(335161, 'ptBR', 'Exaustão da Ânima', 38134),
(340433, 'ptBR', 'Dom de Pecádia', 38134),
(220358, 'ptBR', 'Golpes Ciclônicos', 38134),
(352329, 'ptBR', '[DNT] Learn Bananas', 38134),
(163708, 'ptBR', 'Fogueira Enfeitiçada', 38134),
(34477, 'ptBR', 'Redirecionar', 38134),
(202335, 'ptBR', 'Barril Duplo', 38134),
(209584, 'ptBR', 'Chá da Concentração Zen', 38134),
(235219, 'ptBR', 'Ruptura do Gelo', 38134),
(243435, 'ptBR', 'Cerveja Fortificante', 38134),
(248518, 'ptBR', 'Intrusão', 38134),
(321995, 'ptBR', 'Presença Hipotérmica', 38134),
(327193, 'ptBR', 'Momento de Glória', 38134),
(352497, 'ptBR', '[DNT] Teleport', 38134),
(294587, 'ptBR', 'Espetos de Obleron x2', 38134),
(294588, 'ptBR', 'Espetos de Obleron x3', 38134),
(322841, 'ptBR', 'Fúria Célere', 38134),
(324919, 'ptBR', 'Fúria Célere', 38134),
(352816, 'ptBR', '[DNT] Grant Keystone', 38134),
(341220, 'ptBR', 'Besta Górjura', 38134),
(321136, 'ptBR', 'Luz Rutilante', 38134),
(255260, 'ptBR', 'Marca do Caos', 38134),
(281242, 'ptBR', 'Marca do Caos', 38134),
(337541, 'ptBR', 'Espírito da Chama das Trevas', 38134),
(71, 'ptBR', 'Vanguarda', 38134),
(48263, 'ptBR', 'Veterano da Terceira Guerra', 38134),
(245013, 'ptBR', 'Equilíbrio do Mestre Cervejeiro', 38134),
(300346, 'ptBR', 'Adepto Ursino', 38134),
(316714, 'ptBR', 'Veterano da Terceira Guerra', 38134),
(319278, 'ptBR', 'Veterano da Quarta Guerra', 38134),
(353367, 'ptBR', 'Égide de Luz', 38134),
(337334, 'ptBR', 'Beira-céu de Cascais', 38134),
(336061, 'ptBR', 'Investida Viscosa', 38134),
(340271, 'ptBR', 'Contágio Coagulado', 38134),
(327332, 'ptBR', 'Imbuir Arma', 38134),
(45525, 'ptBR', 'Intelecto Arcano', 38134),
(354135, 'ptBR', 'Bottom Barrier Visual', 38134),
(321828, 'ptBR', 'Adoleta', 38134),
(321832, 'ptBR', 'Queimada', 38134),
(326180, 'ptBR', 'Marca de Congelamento', 38134),
(322416, 'ptBR', 'Fratura Escarpada', 38134);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91079, 'ptBR', 'Login with Bananas license (Charity Pet 2021)', 38134),
(91080, 'ptBR', '', 38134),
(91081, 'ptBR', 'Earn character-level Bananas achievement', 38134),
(91082, 'ptBR', '', 38134),
(91386, 'ptBR', 'Ve\'nari reputation is Apprehensive', 38134),
(91388, 'ptBR', 'Ve\'nari reputation is Tentative', 38134),
(91390, 'ptBR', 'Ve\'nari reputation is Ambivalent', 38134),
(91392, 'ptBR', 'Ve\'nari reputation is Cordial', 38134),
(91393, 'ptBR', '', 38134),
(91503, 'ptBR', 'Do You Have All Rank 1s in a Covenant Sanctum?', 38134),
(91504, 'ptBR', 'Login test for backporting of \"do you have all level 1 buildings\"', 38134),
(91505, 'ptBR', '', 38134),
(91506, 'ptBR', 'Do You Have All Rank 2s in a Covenant Sanctum?', 38134),
(91507, 'ptBR', 'Login test for backporting of \"do you have all level 2 buildings\"', 38134),
(91508, 'ptBR', '', 38134),
(91509, 'ptBR', 'Do You Have All Rank 3s in a Covenant Sanctum?', 38134),
(91510, 'ptBR', 'Login test for backporting of \"do you have all level 3 buildings\"', 38134),
(91511, 'ptBR', '', 38134),
(91387, 'ptBR', 'Reputação com Ve\'nari é Apreensão', 38134),
(91389, 'ptBR', 'Reputação com Ve\'nari é Provisório', 38134),
(91391, 'ptBR', 'Reputação com Ve\'nari é Ambivalência', 38134),
(87404, 'ptBR', 'Vencer partidas JxJ Ranqueadas durante a Série 1 de Shadowlands com pontua;ção de 1000 ou acima', 38134),
(87408, 'ptBR', 'Vencer partidas JxJ Ranqueadas durante a Série 1 de Shadowlands  com pontuação de 1000 ou acima', 38134);

DELETE FROM `specialization_spells_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `specialization_spells_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(5164, 'ptBR', '', 38134),
(5369, 'ptBR', '', 38134),
(5480, 'ptBR', '', 38134),
(6271, 'ptBR', '', 38134),
(6285, 'ptBR', '', 38134),
(6286, 'ptBR', '', 38134),
(6287, 'ptBR', '', 38134),
(6288, 'ptBR', '', 38134),
(6289, 'ptBR', '', 38134),
(6292, 'ptBR', '', 38134),
(6293, 'ptBR', '', 38134),
(6294, 'ptBR', '', 38134),
(6295, 'ptBR', '', 38134),
(6298, 'ptBR', '', 38134),
(6299, 'ptBR', '', 38134),
(6306, 'ptBR', '', 38134),
(6377, 'ptBR', '', 38134),
(6455, 'ptBR', '', 38134),
(6457, 'ptBR', '', 38134),
(6463, 'ptBR', '', 38134),
(6478, 'ptBR', '', 38134),
(6531, 'ptBR', '', 38134),
(6532, 'ptBR', '', 38134),
(6533, 'ptBR', '', 38134),
(6534, 'ptBR', '', 38134),
(6535, 'ptBR', '', 38134),
(6608, 'ptBR', '', 38134),
(5262, 'ptBR', '', 38134),
(6609, 'ptBR', '', 38134),
(5320, 'ptBR', '', 38134),
(5521, 'ptBR', '', 38134),
(5580, 'ptBR', '', 38134),
(5938, 'ptBR', '', 38134),
(6113, 'ptBR', '', 38134),
(6114, 'ptBR', '', 38134),
(6193, 'ptBR', '', 38134),
(6195, 'ptBR', '', 38134),
(6324, 'ptBR', '', 38134),
(6400, 'ptBR', '', 38134),
(6434, 'ptBR', '', 38134),
(6447, 'ptBR', '', 38134),
(6515, 'ptBR', '', 38134),
(6516, 'ptBR', '', 38134),
(6610, 'ptBR', '', 38134);

DELETE FROM `battlemaster_list_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `battlemaster_list_locale` (`ID`, `locale`, `Name_lang`, `GameType_lang`, `ShortDescription_lang`, `LongDescription_lang`, `VerifiedBuild`) VALUES
(100, 'ptBR', 'CB Ranqueado', '', '', '', 38134),
(866, 'ptBR', 'Todas as Arenas', 'Briga', '', '', 38134),
(1047, 'ptBR', 'Mugambala', '', '', '', 38134),
(1048, 'ptBR', 'Robódromo', '', '', '', 38134),
(1049, 'ptBR', 'Ponta do Gancho', '', '', '', 38134),
(1050, 'ptBR', 'Domínio Empíreo', '', '', '', 38134);

DELETE FROM `area_table_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12876, 'ptBR', 'Trono do Prócer', 38134),
(12917, 'ptBR', 'Pecádia', 38134),
(12924, 'ptBR', 'Ardena', 38134),
(13387, 'ptBR', 'Ardena', 38134),
(6852, 'ptBR', 'Campo de Testes', 38134);

DELETE FROM `char_titles_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(679, 'ptBR', 'Barão %s', 'Barão %s', 38134),
(680, 'ptBR', 'Baronesa %s', 'Baronesa %s', 38134),
(682, 'ptBR', 'Conde %s', 'Conde %s', 38134),
(683, 'ptBR', 'Condessa %s', 'Condessa %s', 38134);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'ptBR', '', '', '', '', 'Óculos Escuros de Vidrilho', 38134),
(180317, 'ptBR', '', '', '', '', 'Poção de Cura Habitada', 38134),
(180318, 'ptBR', '', '', '', '', 'Poção de Mana Habitada', 38134),
(155622, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(159570, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164580, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164581, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164582, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164583, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164584, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164585, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164586, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164587, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164950, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164951, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164952, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164953, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164954, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164955, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(164956, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164957, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164958, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(164959, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(168316, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(171090, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(171091, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(171092, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(171093, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(171095, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(171096, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(171097, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(171098, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(171099, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(172890, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(172891, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(172892, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(172893, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(172894, 'ptBR', '', '', '', '', 'Signo Belinato', 38134),
(172895, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(172896, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(172897, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(172898, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(172899, 'ptBR', '', '', '', '', 'Troféu do Senhor da Guerra', 38134),
(186099, 'ptBR', 'Essa traquitana abre uma fenda no espaço em miniatura no meio dos seus equipamentos, tem um formato perfeito para uma gema.', '', '', '', 'Aparato do Realinhamento Espacial', 38134),
(183122, 'ptBR', '', '', '', '', 'Manto da Morte', 38134),
(183131, 'ptBR', '', '', '', '', 'Arpéu Estígio', 38134),
(183135, 'ptBR', '', '', '', '', 'Evocar os Caídos', 38134),
(183136, 'ptBR', '', '', '', '', 'Rato-da-gorja Incendiário', 38134),
(183141, 'ptBR', '', '', '', '', 'Magma Estígio', 38134),
(183165, 'ptBR', '', '', '', '', 'Besta Górjura', 38134),
(183187, 'ptBR', '', '', '', '', 'Sortilégio Criassombras', 38134),
(174876, 'ptBR', '', '', '', '', 'Olho Arrancado de N\'Zoth', 38134),
(187116, 'ptBR', '', '', '', '', 'Boneco-alvo', 38134);

DELETE FROM `map_difficulty_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `map_difficulty_locale` (`ID`, `locale`, `Message_lang`, `VerifiedBuild`) VALUES
(4775, 'ptBR', '', 38134);

DELETE FROM `mount_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1458, 'ptBR', 'Anciente Andarilho', '|cFFFFD200Promoção|r', 'Defensores leais das florestas de Azeroth, os ancientes também são conhecidos pelas gloriosas frondes, que mudam de cor com as estações.', 38134);

DELETE FROM `player_condition_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(90553, 'ptBR', '', 38134),
(90651, 'ptBR', '', 38134),
(90652, 'ptBR', '', 38134),
(78581, 'ptBR', '', 38134),
(87399, 'ptBR', 'Requer que Ve\'nari tenha uma opinião de Agradecimento ou melhor sobre você.', 38134);

DELETE FROM `achievement_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(15010, 'ptBR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Apprehensive standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Apprehensive [DNT]', '', 38134),
(15011, 'ptBR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Tentative standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Tentative [DNT]', '', 38134),
(15012, 'ptBR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Ambivalent standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Ambivalent [DNT]', '', 38134),
(15013, 'ptBR', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Cordial standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Cordial [DNT]', '', 38134),
(14340, 'ptBR', 'Derrotar um chefe no Caminho da Ascensão.', 'O caminho para a ascensão 1', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14342, 'ptBR', 'Derrotar três chefes no Caminho da Ascensão.', 'O caminho para a ascensão 3', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14343, 'ptBR', 'Derrotar cinco chefes no Caminho da Ascensão.', 'O caminho para a ascensão 5', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14344, 'ptBR', 'Derrotar sete chefes no Caminho da Ascensão.', 'O caminho para a ascensão 7', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14345, 'ptBR', 'Derrotar 12 chefes no Caminho da Ascensão.', 'O caminho para a ascensão 12', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14346, 'ptBR', 'Derrotar 16 chefes no Caminho da Ascensão.', 'O caminho para a ascensão 16', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14348, 'ptBR', 'Derrotar 20 chefes no Caminho da Ascensão.', 'O caminho para a ascensão 20', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14349, 'ptBR', 'Derrotar 24 chefes no Caminho da Ascensão.', 'O caminho para a ascensão 24', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14351, 'ptBR', 'Derrotar 39 chefes no Caminho da Ascensão.', 'O caminho para a ascensão 39', 'Desbloquear mais desafios no Caminho da Ascensão.', 38134),
(14502, 'ptBR', 'Supere as oito primeiras Provas da Lealdade.', 'Em busca da lealdade', '', 38134),
(14633, 'ptBR', 'Desbloquear o Grau III da Rede de Viagem do seu Santuário.', 'Mestre da navegação', '', 38134),
(14636, 'ptBR', 'Desbloquear o Grau III das Aventuras da Mesa de Comando do seu Santuário.', 'Chefe dos aventureiros', '', 38134),
(14637, 'ptBR', 'Desbloquear o Grau V do Recurso Especial do seu Santuário.', 'O gostinho do seu Pacto', '', 38134),
(14638, 'ptBR', 'Desbloquear todos os locais conectados ao seu Condutor de Ânima.', 'A ânima precisa fluir', '', 38134),
(14639, 'ptBR', 'Usar seu Condutor de Ânima 50 vezes.', 'Dedicação à restauração', '', 38134),
(14670, 'ptBR', 'Incubar um espírito de cada tipo no Conservatório da Rainha.', 'Esse é o espírito da coisa', '', 38134),
(14675, 'ptBR', 'Incubar um espírito superior de cada tipo no Conservatório da Rainha.', 'Conversa com espíritos', '', 38134),
(14676, 'ptBR', 'Incubar um espírito divino de cada tipo no Conservatório da Rainha.', 'Salvador de espíritos divinos', '', 38134),
(14677, 'ptBR', 'Concluir todas as missões de observação de espírito de Felir no Conservatório da Rainha.', 'Observações espirituais', '', 38134),
(14678, 'ptBR', 'Desbloquear os seguintes favores para a sua Corte das Brasas.', 'Favores da Corte', '', 38134),
(14679, 'ptBR', 'Desbloquear os seguintes aprimoramentos para a sua Corte das Brasas.', 'Palácio de festas', '', 38134),
(14680, 'ptBR', 'Desbloquear as seguintes amenidades para a sua Corte das Brasas.', 'Tem para todo mundo', '', 38134),
(14681, 'ptBR', 'Treinar seu dragador da Corte das Brasas nas seguintes artes do serviço de mordomo.', 'Academia dos Dragadores', '', 38134),
(14682, 'ptBR', 'Obter as conquistas de Corte das Brasas listadas abaixo.', 'O Arauto da Festa', 'Título: Arauto da Festa', 38134),
(14683, 'ptBR', 'Desbloquear as seguintes opções cosméticas de dragador para a sua Corte das Brasas:', 'Estilo Dragador', '', 38134),
(14684, 'ptBR', 'Completar as seguintes missões de Sutura de Abominação', 'Vidas abomináveis', '', 38134),
(14723, 'ptBR', 'Receber os seguintes convidados na sua Corte das Brasas.', 'A casa é sua', '', 38134),
(14724, 'ptBR', 'Ajude os seguintes convidados a atingir o nível de humor Eufórico na sua Corte das Brasas.', 'Sucesso de público', '', 38134),
(14725, 'ptBR', 'Realizar uma Corte das Brasas com quatro convidados Eufóricos.', 'Poucos, mas felizes', '', 38134),
(14726, 'ptBR', 'Realizar Cortes das Brasas com os seguintes atributos em níveis altos.', 'Nunca fica chato', '', 38134),
(14727, 'ptBR', 'Concluir 10 Eventos em uma única Corte das Brasas.', 'Mestre de cerimônias', '', 38134),
(14748, 'ptBR', 'Criar 25 desses acessórios de moda com Sutura de Abominação.', 'Guarda-roupa renovado', '', 38134),
(14749, 'ptBR', 'Ajudar Rasgão a achar os seguintes chapéus para usar na Corte das Brasas:', 'O dia do Rasgão', '', 38134),
(14751, 'ptBR', 'Criar todos os seguintes constructos com a Sutura de Abominação:', 'Turminha do barulho', 'Montaria: Tauralus Escolhido', 38134),
(14752, 'ptBR', 'Obter as conquistas de Sutura de Abominação listadas abaixo.', 'Coisas para fazer quando se está morto', 'Título: Abominável e montaria: Tauralus Escolhido Couraçado', 38134),
(14753, 'ptBR', 'Contribuir com 100 Ataduras Imbuídas em Ânima para ajudar o Evocador Gerard a evocar Viséctus, o Espectro da Guerra.', 'Uma atadurinha resolve', '', 38134),
(14764, 'ptBR', 'Com a ajuda de Cordi, obter o grande Sorte-sim.', 'O Grande Sorte-sim', '', 38134),
(14775, 'ptBR', 'Tornar-se exaltado por Marasmius.', 'Cogumuito obrigado', 'Título: Gente Fina', 38134),
(14777, 'ptBR', 'Aprimorar todos os recursos do Santuário do Pacto.', 'Reforma geral', '', 38134),
(14780, 'ptBR', 'Concluir todas as missões de meditação de Ohm no Conservatório da Rainha e atingir a harmonia com a sua paz interior.', 'Mestre da meditação', '', 38134),
(14789, 'ptBR', 'Concluir a série de missões de Lia para restaurar todos os espíritos animais do Conservatório da Rainha.', 'Todos os espíritos, de todos os tamanhos', '', 38134),
(14833, 'ptBR', 'Criar cada um desses Acessórios de Moda com Sutura de Abominação.', 'Abominação da moda', '', 38134),
(14839, 'ptBR', 'Elevar três vínculos de alma até o nível 60 em Aventuras.', 'Vinculado à aventura', '', 38134),
(14840, 'ptBR', 'Elevar um aventureiro ao nível 20.', 'Aventuras: domínio do básico', '', 38134),
(14841, 'ptBR', 'Elevar um aventureiro ao nível 40.', 'Aventuras: agora vai', '', 38134),
(14842, 'ptBR', 'Elevar um aventureiro ao nível 60.', 'Aventuras: força e resistência', '', 38134),
(14843, 'ptBR', 'Colete todos os 12 aventureiros do seu Pacto.', 'Aventuras: harmonia de propósito', '', 38134),
(14844, 'ptBR', 'Complete as seguintes aventuras da Gorja.', 'Aventuras: mergulho no perigo', '', 38134),
(14845, 'ptBR', 'Completar uma aventura.', 'Aventuras: um passo na direção certa', '', 38134),
(14846, 'ptBR', 'Completar 10 aventuras.', 'Aventuras: folhas na floresta', '', 38134),
(14847, 'ptBR', 'Completar 100 aventuras.', 'Aventuras: Protetor das Terras Sombrias', '', 38134),
(14851, 'ptBR', 'Derrotar Calístene e Corinto Covarde usando a Égide Forjada pelo Espírito.', 'Bastião da proteção', '', 38134),
(14852, 'ptBR', 'Derrotar Alderyn e Myn\'ir e Pesadelo Cascafarpa em uma Prova da Lealdade como Mikâniko.', 'Chama o comissário', '', 38134),
(14853, 'ptBR', 'Derrotar Mortino Maluco após ser afetado por Veias Ígneas, Congelamento e Vômito Incontrolável.', 'Sommelier de sofrimento', '', 38134),
(14854, 'ptBR', 'Superar uma Prova da Lealdade usando todos os tipos de equipamento de vínculo de almas.', 'Não é a arma', '', 38134),
(14856, 'ptBR', 'Superar uma Prova da Sabedoria com cinco patuás equipados.', 'Patuá aqui, patuá acolá', '', 38134),
(14857, 'ptBR', 'Derrotar Équitra em uma Prova da Sabedoria após matar 20 Rastejantes.', 'Vinte matar na garra', '', 38134),
(14858, 'ptBR', 'Derrotar Corinto Covarde em uma Prova da Sabedoria após ele consumir dois orbes de ânima.', 'Maldição da sede', '', 38134),
(14859, 'ptBR', 'Derrotar Athanos em uma Prova da Sabedoria após sobreviver a cinco Meneios Fortes.', 'No balanço da lança', '', 38134),
(14860, 'ptBR', 'Superar uma Prova da Sabedoria sem equipamentos de vínculo de almas.', 'Só o necessário', '', 38134),
(14861, 'ptBR', 'Derrotar Calístene e Athanos na Prova da Sabedoria usando Pelagos, Kleia e Mikâniko.', 'Os melhores mentores', '', 38134),
(14862, 'ptBR', 'Superar uma Prova da Humildade usando todos os tipos de equipamento de vínculo de almas.', 'É quem empunha', '', 38134),
(14863, 'ptBR', 'Derrotar Thran\'tiok numa Prova da Sabedoria sem causar dano a ela, antes de destruir todos os filactérios.', 'Morte bem matada', '', 38134),
(14864, 'ptBR', 'Derrotar Azaruux em uma Prova da Sabedoria como Pelagos, sem confrontar lembranças.', 'Pesadelo pessoal', '', 38134),
(14865, 'ptBR', 'Vencer todas as dez Provas da Humildade com Pelagos, Kleia e Mikâniko.', 'Discípulo da humildade', '', 38134),
(14866, 'ptBR', 'Vencer todas as dez Provas da Humildade sem patuás nem braseiros ativos.', 'Mestre do caminho', '', 38134),
(14887, 'ptBR', 'Acenar em despedida para Athanos depois que ele acenar para você.', 'Até a Lua', '', 38134),
(15023, 'ptBR', 'Desbloquear o Ranque I dos quatro Aprimoramentos do Pacto.', 'Reconstruir sempre, render-se jamais', 'Desbloqueia mais recompensas de ânima', 38134),
(15024, 'ptBR', 'Desbloquear o Ranque II dos quatro Aprimoramentos do Pacto.', 'Seca? Que seca?', 'Desbloqueia mais recompensas de ânima', 38134),
(15025, 'ptBR', 'Desbloquear o Ranque III dos quatro Aprimoramentos do Pacto.', 'Superior de Santuário', 'Desbloqueia mais recompensas de ânima', 38134);


DELETE FROM `hotfix_blob` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(13330255, 89547, 'ptBR', 0xFB1E0200ECDA0200, 38134), -- ItemXItemEffect
(3865974254, 187116, 'ptBR', 0xECDA020000000000, 38134), -- ModifiedReagentItem
(3205218938, 34395, 'ptBR', 0x4C4F47494E5F504152454E54414C434F4E54524F4C004F2061636573736F2061206573746120636F6E746120657374C3A120726573747269746F2070656C6F20636F6E74726F6C6520646F7320706169732E20566F63C3AA20706F646520616C746572617220617320636F6E666967757261C3A7C3B5657320646520636F6E74726F6C65206E6F20676572656E6369616D656E746F206F6E2D6C696E6520646520636F6E7461732E0002, 38134), -- GlobalStrings
(3205218938, 33881, 'ptBR', 0x424E45545F4552524F525F3131004F2061636573736F2061206573746120636F6E746120657374C3A120726573747269746F2070656C6F20636F6E74726F6C6520646F7320706169732E20566F63C3AA20706F646520616C746572617220617320636F6E666967757261C3A7C3B5657320646520636F6E74726F6C65206E6F20676572656E6369616D656E746F206F6E2D6C696E6520646520636F6E7461732E0002, 38134), -- GlobalStrings
(3205218938, 33838, 'ptBR', 0x415554485F504152454E54414C5F434F4E54524F4C004F2061636573736F2061206573746120636F6E746120657374C3A120726573747269746F2070656C6F20636F6E74726F6C6520646F7320706169732E20566F63C3AA20706F646520616C746572617220617320636F6E666967757261C3A7C3B5657320646520636F6E74726F6C65206E6F20676572656E6369616D656E746F206F6E2D6C696E6520646520636F6E7461732E0002, 38134), -- GlobalStrings
(1754233351, 4164, 'ptBR', 0x69ED040011C2B8323FF3665F3F00004843000048430000000000000000000000000000000000000000000000000000803F0000803F0000A040, 38134), -- SpellMissile
(240389885, 5745, 'ptBR', 0x005238383800000000020202020000000001000000080000000A0000000C00000000000000000000000000000000000000, 38134), -- UnitCondition
(3776013982, 322416, 'ptBR', 0x004F206C616EC3A761646F722066617A20636F6D2071756520667261747572617320726F63686F736173206972726F6D70616D20736F62206F732070C3A97320646520746F646F73206F7320696E696D69676F73207072C3B378696D6F732C20646572727562616E646F2D6F7320652063617573616E646F202433323234313873312064652064616E6F2046C3AD7369636F2E0000, 38134), -- Spell
(3865974254, 174876, 'ptBR', 0x1CAB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 326180, 'ptBR', 0x0024407370656C6C646573633332313837330D0A0000, 38134), -- Spell
(3776013982, 321832, 'ptBR', 0x0024407370656C6C646573633331303430360D0A0000, 38134), -- Spell
(3776013982, 321828, 'ptBR', 0x004368616D616272756D61206272696E63612064652024407370656C6C6E616D6533323138323820636F6D20756D20696E696D69676F2C2063617573616E646F202473312064652064616E6F206465204E61747572657A61206520636F6E66756E64696E646F206F20616C766F20706F722024642E2045737465206665697469C3A76F20706F64652073657220696E746572726F6D7069646F2070656C6F20616C766F2E2000436F6E6675736F2E00, 38134), -- Spell
(2640972154, 324, 'ptBR', 0x4120436F727465206461732042726173617300440100006F00000000000000050000000001000000000000000500000002000000, 38134), -- GarrTalentTree
(2640972154, 321, 'ptBR', 0x46C3A162726963612064652041626F6D696E61C3A7C3B5657300410100006F00000000000000050000000000000000000000000500000004000000, 38134), -- GarrTalentTree
(2640972154, 320, 'ptBR', 0x43616D696E686F20646120417363656E73C3A36F00400100006F00000000000000050000A31400000000000000000500000001000000, 38134), -- GarrTalentTree
(2640972154, 319, 'ptBR', 0x436F6E736572766174C3B372696F206461205261696E6861003F0100006F00000000000000050000000000000000000000000500000003000000, 38134), -- GarrTalentTree
(4033975491, 441527, 'ptBR', 0x00000000666646C000005040000000000000000000000000B7BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441526, 'ptBR', 0x000000006666464000005040000000000000000000000000B6BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441525, 'ptBR', 0x000000000000000000005040000000000000000000000000B5BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429002, 'ptBR', 0x00000000666646C000003040000000000000000000000000CA8B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429001, 'ptBR', 0x000000006666464000003040000000000000000000000000C98B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429000, 'ptBR', 0x000000000000000000003040000000000000000000000000C88B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(1181150530, 381714, 'ptBR', 0x02000000B7BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381713, 'ptBR', 0x02000000B6BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381712, 'ptBR', 0x02000000B5BC0600FA390200, 38134), -- SpellVisualKitEffect
(3425193231, 280125, 'ptBR', 0x090000000A0000000000000000000000000000000000000003000000FA39020075A60100, 38134), -- SpellVisualEvent
(4146370265, 108149, 'ptBR', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3776013982, 354135, 'ptBR', 0x000000, 38134), -- Spell
(2939349194, 723, 'ptBR', 0x436865666573204D756E64696169732028536861646F776C616E64732900436865666573204D756E646961697300030000002301000000008C4E0100AE08000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 722, 'ptBR', 0x43617374656C6F206465204E61746872696120284865726F69636F29004865726F69636F0003020B0123000000D7008C4E0100F8080F00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 721, 'ptBR', 0x43617374656C6F206465204E61746872696120284DC3AD7469636F29004DC3AD7469636F0003030B0123000000E6008C4E0100F808100000140000000000, 38134), -- GroupFinderActivity
(2939349194, 720, 'ptBR', 0x43617374656C6F206465204E61746872696120284E6F726D616C29004E6F726D616C0003010B0123000000C8008C4E0100F8080E00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 719, 'ptBR', 0x54656174726F20646120446F7220284865726F69636F29004865726F69636F0002010A016300000073008C4E0100F508020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 718, 'ptBR', 0x54656174726F20646120446F7220284DC3AD7469636F29004DC3AD7469636F0002010A016300000073008C4E0100F508170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 717, 'ptBR', 0x54656174726F20646120446F72202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010A01C300000073008C4E0100F508080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 716, 'ptBR', 0x54656174726F20646120446F7220284E6F726D616C29004E6F726D616C0002010A016300000000008C4E0100F508010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 715, 'ptBR', 0x4368616761204E656372C3B37469636120284865726F69636F29004865726F69636F00020109016300000073008C4E0100EE08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 714, 'ptBR', 0x4368616761204E656372C3B37469636120284DC3AD7469636F29004DC3AD7469636F00020109016300000073008C4E0100EE08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 713, 'ptBR', 0x4368616761204E656372C3B374696361202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010901C300000073008C4E0100EE08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 712, 'ptBR', 0x4368616761204E656372C3B37469636120284E6F726D616C29004E6F726D616C00020109016300000000008C4E0100EE08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 711, 'ptBR', 0x546F7272657320646120417363656E73C3A36F20284865726F69636F29004865726F69636F00020108016300000073008C4E0100ED08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 710, 'ptBR', 0x546F7272657320646120417363656E73C3A36F20284DC3AD7469636F29004DC3AD7469636F00020108016300000073008C4E0100ED08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 709, 'ptBR', 0x546F7272657320646120417363656E73C3A36F202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010801C300000073008C4E0100ED08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 708, 'ptBR', 0x546F7272657320646120417363656E73C3A36F20284E6F726D616C29004E6F726D616C00020108016300000000008C4E0100ED08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 707, 'ptBR', 0x50726F66756E64657A61732053616E6775696EC3A17269617320284865726F69636F29004865726F69636F00020107016300000073008C4E0100EC08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 706, 'ptBR', 0x50726F66756E64657A61732053616E6775696EC3A17269617320284DC3AD7469636F29004DC3AD7469636F00020107016300000073008C4E0100EC08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 705, 'ptBR', 0x50726F66756E64657A61732053616E6775696EC3A172696173202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010701C300000073008C4E0100EC08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 704, 'ptBR', 0x50726F66756E64657A61732053616E6775696EC3A17269617320284E6F726D616C29004E6F726D616C00020107016300000000008C4E0100EC08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 703, 'ptBR', 0x4272756D6173206465205469726E6120536369746865202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010601C300000073008C4E0100F208080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 702, 'ptBR', 0x4272756D6173206465205469726E612053636974686520284DC3AD7469636F29004DC3AD7469636F00020106016300000073008C4E0100F208170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 701, 'ptBR', 0x4272756D6173206465205469726E612053636974686520284865726F69636F29004865726F69636F00020106016300000073008C4E0100F208020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 700, 'ptBR', 0x4272756D6173206465205469726E612053636974686520284E6F726D616C29004E6F726D616C00020106016300000000008C4E0100F208010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 699, 'ptBR', 0x53616CC3B56573206461204578706961C3A7C3A36F202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010501C300000073008C4E0100EF08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 698, 'ptBR', 0x53616CC3B56573206461204578706961C3A7C3A36F20284DC3AD7469636F29004DC3AD7469636F00020105016300000073008C4E0100EF08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 697, 'ptBR', 0x53616CC3B56573206461204578706961C3A7C3A36F20284865726F69636F29004865726F69636F00020105016300000073008C4E0100EF08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 696, 'ptBR', 0x53616CC3B56573206461204578706961C3A7C3A36F20284E6F726D616C29004E6F726D616C00020105016300000000008C4E0100EF08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 695, 'ptBR', 0x4F204F7574726F204C61646F202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010401C300000073008C4E0100F308080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 694, 'ptBR', 0x4F204F7574726F204C61646F20284DC3AD7469636F29004DC3AD7469636F00020104016300000073008C4E0100F308170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 693, 'ptBR', 0x4F204F7574726F204C61646F20284865726F69636F29004865726F69636F00020104016300000073008C4E0100F308020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 692, 'ptBR', 0x4F204F7574726F204C61646F20284E6F726D616C29004E6F726D616C00020104016300000000008C4E0100F308010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 691, 'ptBR', 0x456D70C3A973746961202850656472612D6368617665204DC3AD7469636129004DC3AD7469636F2B0002010301C300000073008C4E0100F108080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 690, 'ptBR', 0x456D70C3A97374696120284DC3AD7469636129004DC3AD7469636F00020103016300000073008C4E0100F108170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 689, 'ptBR', 0x456D70C3A97374696120284865726F69636F29004865726F69636F00020103016300000073008C4E0100F108020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 688, 'ptBR', 0x456D70C3A97374696120284E6F726D616C29004E6F726D616C00020103016300000000008C4E0100F108010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 657, 'ptBR', 0x436865666573206465204D756E646F2028426174746C6520666F7220417A65726F74682900436865666573206465204D756E646F0003000000230100000000BF5300000000000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 498, 'ptBR', 0x4D61736D6F72726120416C656174C3B372696120646520426174746C6520666F7220417A65726F746820284865726F69636F29004865726F69636F0002028800620000003A00BF5300006A06020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 497, 'ptBR', 0x4D61736D6F72726120416C656174C3B372696120646520426174746C6520666F7220417A65726F746820284E6F726D616C29004E6F726D616C0002008800620000000000BF5300006A06010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 458, 'ptBR', 0x436865666573206465204D756E646F20284C6567696F6E2900436865666573204D756E64696169730003000000230100000000BF530000C404000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 418, 'ptBR', 0x4D61736D6F72726120416C656174C3B3726961206465204C6567696F6E20284865726F69636129004865726F69636F0002026F00620000003200BF530000C404020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 417, 'ptBR', 0x4D61736D6F72726120416C656174C3B3726961206465204C6567696F6E20284E6F726D616C29004E6F726D616C0002006F00620000000000BF530000C404010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 398, 'ptBR', 0x436865666573206465204D756E646F2028447261656E6F722900436865666573206465204D756E646F0003000000230100000000BF5300005C04000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 397, 'ptBR', 0x436865666573206465204D756E646F202850616E64C3A17269612900436865666573206465204D756E646F0003000000230100000000BF5300006603000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 396, 'ptBR', 0x4D61736D6F72726120416C656174C3B372696120646F205761726C6F72647320284865726F69636129004865726F69636F0002006D00620000000000BF5300005C04020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 395, 'ptBR', 0x4D61736D6F72726120416C656174C3B372696120646F205761726C6F72647320284E6F726D616C29004E6F726D616C0002006D00620000000000BF5300005C04010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 364, 'ptBR', 0x4D61736D6F72726120416C656174C3B37269612064652050616E64C3A172696120284865726F69636129004865726F69636F0002005400620000000000BF5300006603020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 363, 'ptBR', 0x4D61736D6F72726120416C656174C3B37269612064652050616E64C3A172696120284E6F726D616C29004E6F726D616C0002005400620000000000BF5300006603010000050100000000, 38134), -- GroupFinderActivity
(3776013982, 45525, 'ptBR', 0x0041756D656E746120656D2024733125206F20496E74656C6563746F20646520756D20616C6961646F20706F722024642E00496E74656C6563746F2061756D656E7461646F20656D20247331252E00, 38134), -- Spell
(3776013982, 327332, 'ptBR', 0x004F206C616EC3A761646F7220696D6275692061207072C3B3707269612061726D6120656D20C3A26E696D612E204F73207072C3B378696D6F732035206174617175657320656D20246420636175736172C3A36F2064616E6F20417263616E6F2061646963696F6E616C2E004174617175657320636F6D2061726D612063617573616D206D616973202433323733333173312064652064616E6F20417263616E6F2E00, 38134), -- Spell
(3776013982, 340271, 'ptBR', 0x00526564757A20656D2024333430323733733125206F2064616E6F2071756520616C6961646F73207265636562656D20656D20756D207261696F206465203135206D2E00526564757A20656D2024333430323733733125206F2064616E6F2071756520616C6961646F73207265636562656D20656D20756D207261696F206465203135206D2E00, 38134), -- Spell
(3776013982, 336061, 'ptBR', 0x000000, 38134), -- Spell
(603412935, 28771, 'ptBR', 0xE4B8ADE59BBDE9AB98E5B182E4BABAE4BA8BE58F98E58AA80004, 38134), -- ChatProfanity
(603412935, 28770, 'ptBR', 0xE4B8ADE59BBDE9AB98E5B182E69D83E58A9BE69697E4BA890004, 38134), -- ChatProfanity
(603412935, 28769, 'ptBR', 0xE4B8ADE59BBDE5AE98E59CBAE68385E69D80E6A1880004, 38134), -- ChatProfanity
(603412935, 28768, 'ptBR', 0xE69CB1E6BAB6E59FBA0004, 38134), -- ChatProfanity
(603412935, 28767, 'ptBR', 0xE69CB1E6BAB6E9B8A10004, 38134), -- ChatProfanity
(603412935, 28766, 'ptBR', 0xE5AFACE8A1A3E5B89D0004, 38134), -- ChatProfanity
(603412935, 28765, 'ptBR', 0xE7A588E7BFA00004, 38134), -- ChatProfanity
(603412935, 28764, 'ptBR', 0xE5B08FE5ADA6E58D9AE5A3ABE7BFA00004, 38134), -- ChatProfanity
(603412935, 28763, 'ptBR', 0xE694BFE59D9BE9BB91E9A9AC0004, 38134), -- ChatProfanity
(603412935, 28762, 'ptBR', 0xE694BFE6B2BBE6B581E6B0930004, 38134), -- ChatProfanity
(603412935, 28761, 'ptBR', 0xE788B1E59BBDE88085E5908CE79B9FE7BD91E7AB990004, 38134), -- ChatProfanity
(603412935, 28760, 'ptBR', 0xE6AF9BE79A87E5B89D0004, 38134), -- ChatProfanity
(603412935, 28759, 'ptBR', 0xE999A4E58C85E5AD900004, 38134), -- ChatProfanity
(603412935, 28758, 'ptBR', 0xE89BA4E79A870004, 38134), -- ChatProfanity
(603412935, 28757, 'ptBR', 0xE89BA4E89F86E698AFE8B0810004, 38134), -- ChatProfanity
(603412935, 28756, 'ptBR', 0xE89BA4E89F86E698AFE8AAB00004, 38134), -- ChatProfanity
(603412935, 28755, 'ptBR', 0xE680BBE4B9A6E8AEB0E79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28754, 'ptBR', 0xE88081E6B19FE79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28753, 'ptBR', 0xE6B19FE9A9BEE5B4A90004, 38134), -- ChatProfanity
(603412935, 28752, 'ptBR', 0xE6B19FE5898DE79A870004, 38134), -- ChatProfanity
(603412935, 28751, 'ptBR', 0xE6B19FE4B88AE79A870004, 38134), -- ChatProfanity
(603412935, 28750, 'ptBR', 0xE99995E8A5BFE5B8A6E5A4B4E5A4A7E593A50004, 38134), -- ChatProfanity
(603412935, 28749, 'ptBR', 0xE68A97E9BAA6E9838E0004, 38134), -- ChatProfanity
(603412935, 28748, 'ptBR', 0xE6A0BCE890A8E5B094E78E8B0004, 38134), -- ChatProfanity
(603412935, 28747, 'ptBR', 0xE890A8E6A0BCE5B094E78E8B0004, 38134), -- ChatProfanity
(3776013982, 337334, 'ptBR', 0x0050616C6D6120646F20546967726520706173736120612074657220247B246D312B357D206D20646520616C63616E63652C206520766F63C3AA20617272656D65746520696E7374616E74616E65616D656E7465206174C3A9206F20616C766F2E0D0A0D0A50616C6D6120646F2054696772652074616D62C3A96D2061706C69636120756D2065666569746F207175652061756D656E746120656D20243334343032316D3125206120737561206368616E63652064652061636572746F206372C3AD7469636F20636F6E747261206F20616C766F20706F722024333434303231642E20457374652065666569746F2073C3B320706F6465207365722061706C696361646F20756D612076657A2061206361646120243333373334316420706F7220616C766F2E0000, 38134), -- Spell
(813076512, 80114, 'ptBR', 0x2401000057640500, 38134), -- SpellLabel
(813076512, 80113, 'ptBR', 0x1A00000057640500, 38134), -- SpellLabel
(813076512, 80112, 'ptBR', 0x1000000057640500, 38134), -- SpellLabel
(3776013982, 353367, 'ptBR', 0x00546F646F206F2064616E6F20726563656269646F20726564757A69646F20656D20247331252E0000, 38134), -- Spell
(3776013982, 319278, 'ptBR', 0x005669676F722061756D656E7461646F20656D20247331252E0D0A243F733331363731345B526564757A20656D2024733325206F2064616E6F20726563656269646F2E5D5B5D0000, 38134), -- Spell
(3776013982, 316714, 'ptBR', 0x4772617520320041756D656E746120656D2024733125206F205669676F722E0D0A526564757A20656D20247B2461627328247332297D25206F2064616E6F20726563656269646F2E0000, 38134), -- Spell
(3776013982, 300346, 'ptBR', 0x00466F676F204C756E61722C20436F6E666F727461722C2052656D6F76657220436F72727570C3A7C3A36F20652052656E617363696D656E746F2073C3A36F207573C3A176656973206E6120466F726D61206465205572736F2E0D0A0D0A546F646F206F2064616E6F20726563656269646F20726564757A69646F20656D20247332252E0000, 38134), -- Spell
(3776013982, 245013, 'ptBR', 0x00546F646F2064616E6F20726563656269646F20C3A920726564757A69646F20656D202473322520652061756D656E74612061207375612061726D616475726120656D20247331252E0000, 38134), -- Spell
(3776013982, 48263, 'ptBR', 0x005669676F722061756D656E7461646F20656D20247331252E0D0A243F733331363731345B526564757A20656D2024733325206F2064616E6F20726563656269646F2E5D5B5D0000, 38134), -- Spell
(3776013982, 71, 'ptBR', 0x0043616C656A61646F20646520626174616C6861732C20746F646F2064616E6F20726563656269646F20C3A920726564757A69646F20656D20247333252C20736575205669676F7220C3A92061756D656E7461646F20656D20247332252C2065207375612061726D616475726120C3A92061756D656E7461646120656D20247331252064612073756120466F72C3A7612E0000, 38134), -- Spell
(3776013982, 337541, 'ptBR', 0x00537561204D6172636120417264656E7465206375726120766F63C3AA20656D202473312520646F2064616E6F20696E696369616C206361757361646F20616F206C6F6E676F2064652024333337353433642C2065206361646120696E696D69676F206174696E6769646F2070656C6F20736575205369676E6F206461204368616D612061756D656E746120656D2024333337353432733125206F2064616E6F20696E7374616E74C3A26E656F20646120737561207072C3B378696D61204D6172636120417264656E74652C206163756D756C616E646F206174C3A92024333337353432752076657A65732E0000, 38134), -- Spell
(3776013982, 281242, 'ptBR', 0x005365752064616E6F206D61726361206F20616C766F2C2061756D656E74616E646F20656D202431343930733125206F2064616E6F206DC3A16769636F20726563656269646F20706F7220656C652E0000, 38134), -- Spell
(3776013982, 255260, 'ptBR', 0x005365752064616E6F206D61726361206F20616C766F2C2061756D656E74616E646F20656D202431343930733125206F2064616E6F206DC3A16769636F20726563656269646F20706F7220656C652E0000, 38134), -- Spell
(603412935, 28746, 'ptBR', 0x5C62725C733F615C733F705C733F655C733F5C620000, 38134), -- ChatProfanity
(603412935, 28745, 'ptBR', 0x5C62725C733F655C733F745C733F615C733F725C733F64285C733F737C5C733F655C733F64293F5C620000, 38134), -- ChatProfanity
(4033975491, 436804, 'ptBR', 0x00000000000000000000000000000000000000000000000044AA06000A59FF0E030000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000000000000CDCC4C3DCDCC4C3DCC0B0200, 38134), -- SpellVisualKitModelAttach
(3386943305, 171057, 'ptBR', 0x07787800000000000000004A00B20200000000081000000000000400000000000000000001000040000000000000000000E05A0200, 38134), -- CreatureDifficulty
(3386943305, 170644, 'ptBR', 0x07787800000000000000001000B2020000000008100000000000000000000000000000000100000000000000000000000068590200, 38134), -- CreatureDifficulty
(3899321669, 4791, 'ptBR', 0xB71200000101180B0300, 38134), -- SpellAuraVisibility
(3899321669, 4790, 'ptBR', 0xB61200000001180B0300, 38134), -- SpellAuraVisibility
(4033975491, 440494, 'ptBR', 0x0000000000000000CDCC4C3E000000000000000000000000AEB80600D058FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 440493, 'ptBR', 0x0000000000000000CDCCCC3D000000000000000000000000ADB806007F87FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417672, 'ptBR', 0x000000000000000000000000000000000000000000000000885F06000F5AFF00000000000000000000000000000000000000000000000000000000C03F00000000FFFFFFFFFFFF00000800000000000000000000000021030200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417626, 'ptBR', 0x0000000000000000000000000000000000000000000000005A5F0600E64BFF0000000000000000000000000000000000000000000000000000333373400000000000009E009F0000000000000000000000000000000009030200, 38134), -- SpellVisualKitModelAttach
(1181150530, 380178, 'ptBR', 0x02000000AEB8060051160200, 38134), -- SpellVisualKitEffect
(1181150530, 380177, 'ptBR', 0x02000000ADB8060051160200, 38134), -- SpellVisualKitEffect
(3776013982, 321136, 'ptBR', 0x004120636164612024733120244C45736375646F3A45736375646F733B20646F20C38D6E746567726F2C20737561207072C3B378696D612050616C6176726120646520476CC3B3726961206EC3A36F20746572C3A120637573746F2E0000, 38134), -- Spell
(3776013982, 341220, 'ptBR', 0x000024407370656C6C6465736333343132313200, 38134), -- Spell
(3865974254, 183187, 'ptBR', 0x93CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183165, 'ptBR', 0x7DCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183141, 'ptBR', 0x65CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183136, 'ptBR', 0x60CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183135, 'ptBR', 0x5FCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183131, 'ptBR', 0x5BCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183122, 'ptBR', 0x52CB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352816, 'ptBR', 0x000000, 38134), -- Spell
(600565378, 300040, 'ptBR', 0xA06D01000000803F0000803F0074BA0200, 38134), -- CreatureXDisplayInfo
(813076512, 79920, 'ptBR', 0x9703000075A80400, 38134), -- SpellLabel
(13330255, 73366, 'ptBR', 0x081D0200F3D60200, 38134), -- ItemXItemEffect
(3865974254, 186099, 'ptBR', 0xF3D6020000000000, 38134), -- ModifiedReagentItem
(600565378, 299890, 'ptBR', 0x4A6400000000803F0000803F001CBA0200, 38134), -- CreatureXDisplayInfo
(600565378, 299885, 'ptBR', 0x0A6F01000000803F0000803F0017BA0200, 38134), -- CreatureXDisplayInfo
(3865974254, 172899, 'ptBR', 0x63A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172898, 'ptBR', 0x62A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172897, 'ptBR', 0x61A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172896, 'ptBR', 0x60A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172895, 'ptBR', 0x5FA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172894, 'ptBR', 0x5EA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172893, 'ptBR', 0x5DA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172892, 'ptBR', 0x5CA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172891, 'ptBR', 0x5BA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172890, 'ptBR', 0x5AA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171099, 'ptBR', 0x5B9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171098, 'ptBR', 0x5A9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171097, 'ptBR', 0x599C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171096, 'ptBR', 0x589C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171095, 'ptBR', 0x579C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171094, 'ptBR', 0x569C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171093, 'ptBR', 0x559C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171092, 'ptBR', 0x549C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171091, 'ptBR', 0x539C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171090, 'ptBR', 0x529C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168316, 'ptBR', 0x7C91020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164959, 'ptBR', 0x5F84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164958, 'ptBR', 0x5E84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164957, 'ptBR', 0x5D84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164956, 'ptBR', 0x5C84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164955, 'ptBR', 0x5B84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164954, 'ptBR', 0x5A84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164953, 'ptBR', 0x5984020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164952, 'ptBR', 0x5884020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164951, 'ptBR', 0x5784020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164950, 'ptBR', 0x5684020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164587, 'ptBR', 0xEB82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164586, 'ptBR', 0xEA82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164585, 'ptBR', 0xE982020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164584, 'ptBR', 0xE882020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164583, 'ptBR', 0xE782020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164582, 'ptBR', 0xE682020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164581, 'ptBR', 0xE582020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164580, 'ptBR', 0xE482020000000000, 38134), -- ModifiedReagentItem
(3865974254, 159570, 'ptBR', 0x526F020000000000, 38134), -- ModifiedReagentItem
(3865974254, 155622, 'ptBR', 0xE65F020000000000, 38134), -- ModifiedReagentItem
(3205218938, 43871, 'ptBR', 0x43555252454E43595F534541534F4E5F544F54414C5F4D4158494D554D004DC3A178696D6F2064612073C3A97269653A20257325732F25730001, 38134), -- GlobalStrings
(3776013982, 324919, 'ptBR', 0x0024407370656C6C646573633332323834310000, 38134), -- Spell
(3776013982, 322841, 'ptBR', 0x0044616E6F20646F20243F613231323631325B496D70756C736F2056696C5D3F613231323631335B476F6C706520496E6665726E616C5D5B5D2061756D656E7461646F20656D20247331252E0044616E6F20646F20243F613231323631325B496D70756C736F2056696C5D3F613231323631335B476F6C706520496E6665726E616C5D5B5D2061756D656E7461646F20656D20247331252E00, 38134), -- Spell
(3776013982, 294588, 'ptBR', 0x0041756D656E746120656D20247B2473312A2432393435373873317D252061206368616E63652064652061636572746F206372C3AD7469636F2E0000, 38134), -- Spell
(3776013982, 294587, 'ptBR', 0x0041756D656E746120656D20247B2473312A2432393435373873317D252061206368616E63652064652061636572746F206372C3AD7469636F2E0000, 38134), -- Spell
(3865974254, 180318, 'ptBR', 0x5EC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 180317, 'ptBR', 0x5DC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 176406, 'ptBR', 0x16B1020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168564, 'ptBR', 0x7492020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352497, 'ptBR', 0x000000, 38134), -- Spell
(3776013982, 327193, 'ptBR', 0x00436F6E636C75692061207265636172676120646F2045736375646F20646F2056696E6761646F722E2053657573207072C3B378696D6F7320246E2045736375646F7320646F2056696E6761646F72206EC3A36F20746572C3A36F2072656361726761206520636175736172C3A36F20247332252061206D6169732064652064616E6F2E0053657573207072C3B378696D6F7320246E2045736375646F7320646F2056696E6761646F72206EC3A36F20746572C3A36F2072656361726761206520636175736172C3A36F20247732252061206D6169732064652064616E6F2E00, 38134), -- Spell
(3776013982, 321995, 'ptBR', 0x004465697861206F2067656C6F20636F727265722070656C617320737561732076656961732C20726564757A696E646F20656D2024733125206F20637573746F20646520506F6465722052C3BA6E69636F20646173207375617320686162696C69646164657320706F722024642E204EC3A36F206163696F6E61207265636172676120676C6F62616C2E00526564757A20656D2024733125206F20637573746F20646520506F6465722052C3BA6E69636F20646173207375617320686162696C6964616465732E00, 38134), -- Spell
(3776013982, 248518, 'ptBR', 0x54616C656E746F206465204A784A004F207072C3B378696D6F206665697469C3A76F20686F7374696C20636F6E747261206F20616C766F20666172C3A120636F6D20717565206665697469C3A76F7320686F737469732073656A616D2072656469726563696F6E61646F732070617261206F2073657520616A7564616E746520706F722024733120732E0D0A0D0A4F20616A7564616E74652070726563697361206573746172206120243234383531396131206D20646F20616C766F207061726120717565206F73206665697469C3A76F732073656A616D2072656469726563696F6E61646F732E0000, 38134), -- Spell
(3776013982, 243435, 'ptBR', 0x005472616E73666F726D61207375612070656C6520656D2070656472612C2061756D656E74616E646F20656D202473312520736575206DC3A178696D6F20646520706F6E746F7320646520766964612065207365757320706F6E746F732064652076696461206174756169732C20616CC3A96D20646520726564757A697220656D2024733225206F2064616E6F20726563656269646F20706F722024642E004DC3A178696D6F20646520706F6E746F7320646520766964612061756D656E7461646F20656D20247731252E0D0A44616E6F20726563656269646F20726564757A69646F20656D20247732252E243F2477343E315B0D0A4162736F727665202477342064652064616E6F2E5D5B5D00, 38134), -- Spell
(3776013982, 235219, 'ptBR', 0x00436F6E636C75692061207265636172676120646F732073657573206665697469C3A76F732042617272656972612064652047656C6F2C204E6F766120436F6E67656C616E74652C20436F6E65206465204672696F206520426C6F636F2064652047656C6F2E0000, 38134), -- Spell
(3776013982, 209584, 'ptBR', 0x54616C656E746F206465204A784A00436F6E6365646520696D756E696461646520612065666569746F732064652053696CC3AA6E63696F206520496E746572727570C3A7C3A36F20706F722024642E00496D756E6520612065666569746F732064652053696CC3AA6E63696F206520496E746572727570C3A7C3A36F2E00, 38134), -- Spell
(3776013982, 202335, 'ptBR', 0x54616C656E746F206465204A784A00537561207072C3B378696D612050616E636164612064652042617272696C20636175736120247331252064652064616E6F2061646963696F6E616C20652061746F72646F6120746F646F73206F7320616C766F7320717565206174696E676520706F722024323032333436642E0050616E636164612064652042617272696C20636175736120247331252064652064616E6F2061646963696F6E616C20652061746F72646F6120746F646F73206F7320616C766F7320717565206174696E676520706F722024323032333436642E00, 38134), -- Spell
(3776013982, 34477, 'ptBR', 0x0052656469726563696F6E6120746F646120616D6561C3A7612071756520766F63C3AA2063617573612070617261206F206D656D62726F2073656C6563696F6E61646F20646F20677275706F206F752072616964652C20636F6D65C3A7616E646F20636F6D20736575207072C3B378696D6F206174617175652064656E74726F2064652024642E204475726120243335303739642E00416D6561C3A7612072656469726563696F6E61646120646F204361C3A761646F722E00, 38134), -- Spell
(3359787322, 19830, 'ptBR', 0x764D0000, 38134), -- WorldState
(3359787322, 19710, 'ptBR', 0xFE4C0000, 38134), -- WorldState
(3359787322, 19709, 'ptBR', 0xFD4C0000, 38134), -- WorldState
(3359787322, 19384, 'ptBR', 0xB84B0000, 38134), -- WorldState
(368401261, 5214, 'ptBR', 0x5B8800000000000000000000000000000000000000000000, 38134), -- CombatCondition
(368401261, 4771, 'ptBR', 0x848400000000000000000000000000000000000000000000, 38134), -- CombatCondition
(3776013982, 163708, 'ptBR', 0x0041756D656E746120656D20323025206F2064616E6F206465206665697469C3A76F2E0D0A0D0A5065726D69746520616F206172616B6B6F612053657468656B6B206C616EC3A76172204368616D6120456E6665697469C3A76164612E0041756D656E746120656D20323025206F2064616E6F206465206665697469C3A76F2E0D0A0D0A5065726D69746520616F206172616B6B6F612053657468656B6B206C616EC3A76172204368616D6120456E6665697469C3A76164612E00, 38134), -- Spell
(3776013982, 352329, 'ptBR', 0x000000, 38134), -- Spell
(3865974254, 52489, 'ptBR', 0x09CD000000000000, 38134), -- ModifiedReagentItem
(3037505077, 52489, 'ptBR', 0x0100, 38134), -- TradeSkillItem
(3776013982, 220358, 'ptBR', 0x0024407370656C6C646573633130313534360000, 38134), -- Spell
(3776013982, 340433, 'ptBR', 0x00C3826E696D6120726566696E61646120636F7272652070656C6F2073657520636F72706F2C2061756D656E74616E646F20656D2024733125206F2064616E6F206361757361646F20652063757261207265616C697A61646120706F722024642E0044616E6F206361757361646F2061756D656E7461646F20656D20247331252E0D0A43757261207265616C697A6164612061756D656E7461646120656D20247332252E00, 38134), -- Spell
(3776013982, 335161, 'ptBR', 0x004F207661706F7220646520C3A26E696D6120636F6C657461646F20646F7320676F6C69617320636F6D206465666569746F2061756D656E746120656D202473312520612076656C6F636964616465206465206D6F76696D656E746F20652066617A20636F6D20717565206F206A6F6761646F72206972726F6D70612061206361646120247433207320706F722024642C2063617573616E646F202433343434323173312064652064616E6F20417263616E6F20616F7320696E696D69676F73207072C3B378696D6F73206520637572616E646F20243334343432327331206465207669646120646F7320616C6961646F73207072C3B378696D6F732E0056656C6F636964616465206465206D6F76696D656E746F2061756D656E7461646120656D20247331252E2043617573616E646F202433343434323173312064652064616E6F20417263616E6F20616F7320696E696D69676F73207072C3B378696D6F73206520637572616E646F20243334343432327331206465207669646120646F7320616C6961646F73207072C3B378696D6F73206120636164612024743320732E00, 38134), -- Spell
(3205218938, 43287, 'ptBR', 0x4741525249534F4E5F464F4C4C4F5745525F4F4E5F4D495353494F4E5F434F4D504C45544500456D206D697373C3A36F202D20436F6E636C75C3AD64610001, 38134), -- GlobalStrings
(3205218938, 43286, 'ptBR', 0x4741525249534F4E5F464F4C4C4F5745525F4D495353494F4E5F434F4D504C4554454400436F6E636C75C3AD64610001, 38134), -- GlobalStrings
(3205218938, 43283, 'ptBR', 0x434F56454E414E545F464F4C4C4F5745525F4D495353494F4E5F434F4D504C455445004E61204176656E74757261202D20436F6D706C65746164610001, 38134), -- GlobalStrings
(261693969, 59853, 'ptBR', 0xFFFFFFFFFFFFFFFF4368C3A120636F6D2068697374C3B3726961733A20536962696C6120506572646964610000CDE900007599F633010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F88700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59852, 'ptBR', 0xFFFFFFFFFFFFFFFF4368C3A120636F6D2068697374C3B3726961733A20547275636F206520547265636F0000CCE900007499F533010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59850, 'ptBR', 0xFFFFFFFFFFFFFFFF4368C3A120636F6D2068697374C3B3726961733A2056756C63610000CAE900007299F433010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59848, 'ptBR', 0xFFFFFFFFFFFFFFFF4368C3A120636F6D2068697374C3B3726961733A205468656F7461720000C8E900007199F333010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(3776013982, 320740, 'ptBR', 0x000000, 38134), -- Spell
(3776013982, 350249, 'ptBR', 0x00446973746F726365206F20666C75786F2074656D706F72616C2C2061756D656E74616E646F20656D2024733125206120737561206163656C657261C3A7C3A36F2065206120646520746F646173206173207375617320496D6167656E7320457370656C68616461732E20447572612024313130393039642E004163656C657261C3A7C3A36F2061756D656E7461646120656D20247731252E20243F2457343E305B546178612064652074656D706F2061756D656E7461646120656D20247734252E5D5B5D00, 38134), -- Spell
(3776013982, 320914, 'ptBR', 0x00447572616E746520416C74657261722054656D706F2C20766F63C3AA2065207375617320496D6167656E7320457370656C68616461732067616E68616D20756D2062C3B46E757320646520446973746F72C3A7C3A36F2054656D706F72616C20636F6D202473312520646F2076616C6F722E204465736C6F63616D656E746F2054656D706F72616C20652065666569746F732073696D696C61726573206EC3A36F2074C3AA6D2065666569746F20736F627265206973736F2E00447572616E746520416C74657261722054656D706F2C20766F63C3AA2065207375617320496D6167656E7320457370656C68616461732067616E68616D20756D2062C3B46E757320646520446973746F72C3A7C3A36F2054656D706F72616C20636F6D202473312520646F2076616C6F722E204465736C6F63616D656E746F2054656D706F72616C20652065666569746F732073696D696C61726573206EC3A36F2074C3AA6D2065666569746F20736F627265206973736F2E00, 38134), -- Spell
(3893700160, 169, 'ptBR', 0x0F000000E2000000D20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 168, 'ptBR', 0x0E000000E2000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 167, 'ptBR', 0x0D000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 166, 'ptBR', 0x0C000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 165, 'ptBR', 0x0B000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 164, 'ptBR', 0x0A000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 163, 'ptBR', 0x09000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 162, 'ptBR', 0x08000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 161, 'ptBR', 0x07000000D5000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 160, 'ptBR', 0x06000000D2000000C50000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 159, 'ptBR', 0x05000000D2000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 158, 'ptBR', 0x04000000CF000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 157, 'ptBR', 0x03000000CB000000BE0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 156, 'ptBR', 0x02000000C8000000BB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 155, 'ptBR', 0x0100000000000000B70000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3776013982, 351967, 'ptBR', 0x000000, 38134), -- Spell
(3776013982, 340882, 'ptBR', 0x004368616D6120426F6C73612064652047C3A1732C206361736F20656C652074656E68612073756D69646F206F75206D6F727269646F2E004368616D6120426F6C73612064652047C3A1732C206361736F20656C652074656E68612073756D69646F206F75206D6F727269646F2E00, 38134), -- Spell
(2340571112, 755, 'ptBR', 0xBD000000D51C0000D0040000060000008F1B00000000000000000000, 38134), -- ItemBonusListGroupEntry
(2998606315, 212, 'ptBR', 0x0000000005000000803A09000000000000000000, 38134), -- ScheduledInterval
(3359787322, 20659, 'ptBR', 0xB3500000, 38134); -- WorldState

INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(4021368146, 4553, 'ptBR', 0x457374C3AD676961204361C3AD6461000000000000000000D8020000424400000000000000000000000000000000000000, 38134), -- Vignette
(2202435563, 997132, 'ptBR', 0x0C370F00240127010000F3170700, 38134), -- QuestPOIPoint
(2202435563, 997131, 'ptBR', 0x0B370F00240128010000F2170700, 38134), -- QuestPOIPoint
(2921112328, 464883, 'ptBR', 0xF31707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(2921112328, 464882, 'ptBR', 0xF21707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(3776013982, 335718, 'ptBR', 0x00496E76657374696461206520436F6D7072617220427269676120636F6E636564656D204C6576616E7461722045736375646F20706F7220247B2473312F313030307D2073206520526576616E636865212C20676572616E646F20247B2433333537333473312F31307D2064652052616976612E0000, 38134), -- Spell
(2948698321, 339, 'ptBR', 0x6D68C604BDD61274, 38134), -- TactKeyLookup
(2948698321, 278, 'ptBR', 0x7CB28F52811F5830, 38134), -- TactKeyLookup
(3776013982, 328547, 'ptBR', 0x4E6563726F6C6F7264650046696E636120756D206573706967C3A36F20C3B37373656F206E6F20616C766F2C2063617573616E646F202473312064652064616E6F2065202433323430373373312064652064616E6F2064652073616E6772616D656E746F20612063616461202433323430373374312073206174C3A92071756520656C65206D6F727261206F75207361696120646520636F6D626174652E200D0A0D0A526573746974756920756D61206361726761207175616E646F206F20616C766F206D6F7272652E0D0A0D0A7C634646464646464646436F6E63656465203120706F6E746F20646520636F6D626F2C206D616973203120706F72206573706967C3A36F20C3B37373656F20617469766F2E7C720000, 38134), -- Spell
(1369604944, 2081, 'ptBR', 0x000000000000000000000000000000000000000000000000210800006E1C00000000FF2200000000000000002C010000EE0204020000410B0000000000000000002208, 38134), -- SpellVisualMissile
(4033975491, 439153, 'ptBR', 0x00000000000000000000000000000000000000000000000071B3060092001500000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(4033975491, 439152, 'ptBR', 0x00000000000000000000000000000000000000000000000070B3060092001600000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(1181150530, 377991, 'ptBR', 0x050000001ABB020096D20100, 38134), -- SpellVisualKitEffect
(1181150530, 377990, 'ptBR', 0x0500000019BB0200F3290200, 38134), -- SpellVisualKitEffect
(1181150530, 377988, 'ptBR', 0x0500000019BB020054180200, 38134), -- SpellVisualKitEffect
(1181150530, 377987, 'ptBR', 0x0500000018BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377986, 'ptBR', 0x0500000017BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377985, 'ptBR', 0x0500000016BB0200820F0200, 38134), -- SpellVisualKitEffect
(1181150530, 377984, 'ptBR', 0x0500000015BB02009FFA0100, 38134), -- SpellVisualKitEffect
(1181150530, 377983, 'ptBR', 0x050000006C4E01004B4B0100, 38134), -- SpellVisualKitEffect
(1181150530, 377982, 'ptBR', 0x0200000071B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377981, 'ptBR', 0x0200000070B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377980, 'ptBR', 0x05000000EFCC0100FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377979, 'ptBR', 0x06000000B7D20500FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377978, 'ptBR', 0x0500000014BB020052F20100, 38134), -- SpellVisualKitEffect
(1181150530, 377977, 'ptBR', 0x0500000013BB0200D8030200, 38134), -- SpellVisualKitEffect
(3425193231, 278473, 'ptBR', 0x060000000D0000000000000000000000000000000000000002000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278472, 'ptBR', 0x060000000D0000000000000000000000000000000000000001000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278471, 'ptBR', 0x030000000D0000000000000000000000000000000000000001000000FF3402001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278470, 'ptBR', 0x010000000200000000000000000000000000000000000000010000004A4B01001EA30100, 38134), -- SpellVisualEvent
(859088734, 381623, 'ptBR', 0xFFFFFFFF360000000000, 38134), -- SpellVisualAnim
(4146370265, 107294, 'ptBR', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3266400455, 613060, 'ptBR', 0x1ABB02002C713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613059, 'ptBR', 0x1ABB02002B713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613058, 'ptBR', 0x1ABB02002A713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613057, 'ptBR', 0x1ABB020029713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613056, 'ptBR', 0x1ABB020028713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613055, 'ptBR', 0x19BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613054, 'ptBR', 0x19BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613053, 'ptBR', 0x19BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613052, 'ptBR', 0x19BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613051, 'ptBR', 0x19BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613050, 'ptBR', 0x19BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613049, 'ptBR', 0x19BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613043, 'ptBR', 0x18BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613042, 'ptBR', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613041, 'ptBR', 0x18BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613040, 'ptBR', 0x18BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613039, 'ptBR', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613038, 'ptBR', 0x17BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613037, 'ptBR', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613036, 'ptBR', 0x17BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613035, 'ptBR', 0x17BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613034, 'ptBR', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613033, 'ptBR', 0x16BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613032, 'ptBR', 0x16BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613031, 'ptBR', 0x16BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613030, 'ptBR', 0x16BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613029, 'ptBR', 0x16BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613028, 'ptBR', 0x16BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613027, 'ptBR', 0x16BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613018, 'ptBR', 0x15BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613017, 'ptBR', 0x15BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613016, 'ptBR', 0x15BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613015, 'ptBR', 0x15BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613014, 'ptBR', 0x15BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613013, 'ptBR', 0x15BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613012, 'ptBR', 0x15BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613011, 'ptBR', 0x14BB02004AE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613010, 'ptBR', 0x14BB02004BE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613009, 'ptBR', 0x14BB02004CE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613008, 'ptBR', 0x13BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613007, 'ptBR', 0x13BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613006, 'ptBR', 0x13BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613005, 'ptBR', 0x13BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613004, 'ptBR', 0x13BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613003, 'ptBR', 0x13BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613002, 'ptBR', 0x13BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3232102598, 140456, 'ptBR', 0xA82402001ABB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000F4010000F4010000580C00000000803F010000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140455, 'ptBR', 0xA7240200AF6C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140454, 'ptBR', 0xA6240200C06502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140453, 'ptBR', 0xA5240200D07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140452, 'ptBR', 0xA424020019BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140451, 'ptBR', 0xA3240200020A00000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140450, 'ptBR', 0xA224020018BB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140449, 'ptBR', 0xA124020017BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140448, 'ptBR', 0xA02402003E7502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140447, 'ptBR', 0x9F240200447502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140446, 'ptBR', 0x9E24020016BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140445, 'ptBR', 0x9D24020015BB02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140444, 'ptBR', 0x9C240200B9710200000040410000C04100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140443, 'ptBR', 0x9B240200956C02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140442, 'ptBR', 0x9A240200177202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140441, 'ptBR', 0x99240200F46F02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140440, 'ptBR', 0x98240200817202000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140439, 'ptBR', 0x97240200557102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140438, 'ptBR', 0x96240200ED6602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140437, 'ptBR', 0x952402001E7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140436, 'ptBR', 0x94240200E56602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140435, 'ptBR', 0x9324020014BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140434, 'ptBR', 0x9224020013BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140433, 'ptBR', 0x91240200666C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140432, 'ptBR', 0x90240200267102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123926, 'ptBR', 0x16E40100407602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123714, 'ptBR', 0x42E30100437502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000101F4010000F4010000570C0000E8030000E8030000580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123675, 'ptBR', 0x1BE30100457502000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123670, 'ptBR', 0x16E301003D7502000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123594, 'ptBR', 0xCAE20100F17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123515, 'ptBR', 0x7BE20100A27402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123514, 'ptBR', 0x7AE20100A17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123504, 'ptBR', 0x70E201009F7402000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001401F0000401F0000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123503, 'ptBR', 0x6FE201009E7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C010000000000000000000000016400000064000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123502, 'ptBR', 0x6EE201009D7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122935, 'ptBR', 0x37E00100507202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122901, 'ptBR', 0x15E00100167202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122891, 'ptBR', 0x0BE00100187202000000C0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122821, 'ptBR', 0xC5DF0100D1710200000000400000804000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122814, 'ptBR', 0xBEDF0100C87102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122807, 'ptBR', 0xB7DF0100C17102000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001BC020000BC020000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122806, 'ptBR', 0xB6DF0100C07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122804, 'ptBR', 0xB4DF0100BE7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122709, 'ptBR', 0x55DF01004A7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122629, 'ptBR', 0x05DF0100F97002000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B44300000000000000C800000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122404, 'ptBR', 0x24DE0100F56F02000000C0400000404100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121643, 'ptBR', 0x2BDB0100D76C02000000803F0000004000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000001012C0100002C010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121613, 'ptBR', 0x0DDB0100976C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000000012C0100002C010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121609, 'ptBR', 0x09DB0100906C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121587, 'ptBR', 0xF3DA0100686C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 120239, 'ptBR', 0xAFD50100E66602000000C040000040410000000000000000000000000000000000000000000000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 119974, 'ptBR', 0xA6D40100D66502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000002FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 25856, 'ptBR', 0x00650000C9E600000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(1485693696, 5565, 'ptBR', 0x1ABB0200010000000069620000000000000100, 38134); -- SoundEnvelope

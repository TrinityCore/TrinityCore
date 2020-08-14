DELETE FROM `broadcast_text_locale` WHERE `VerifiedBuild`>0 AND `locale` = 'ptBR' AND `ID` IN (201778, 753, 195400, 79796, 165870, 79799, 79798, 79804, 194274, 183984, 201777, 79794, 79795, 141708, 201784, 165241, 165243, 165245, 165239, 165246, 165244, 165237);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(201778, 'ptBR', 'Estamos prontos. Mostre o caminho.', 'Estamos prontos. Mostre o caminho.', 35435),
(753, 'ptBR', 'Quê? Quer dizer que não consegue matar isso aí $Gsozinho:sozinha;?', '', 35435),
(195400, 'ptBR', 'Mostre suas essências sintetizadas, por favor.', 'Mostre suas essências sintetizadas, por favor.', 35435),
(79796, 'ptBR', 'Pedra Xamânica Descoberta: Tocado pelo Fogo', 'Pedra Xamânica Descoberta: Tocado pelo Fogo', 35435),
(165870, 'ptBR', '', 'Eu contarei como foi a queda de Rastakhan quando você estiver pront$Uo:a;.', 35435),
(79799, 'ptBR', 'Pedra do Xamã Descoberta: Fortitude Ôgrica', 'Pedra do Xamã Descoberta: Fortitude Ôgrica', 35435),
(79798, 'ptBR', 'Pedra do Xamã Descoberta: Fúria dos Ventos Cortantes', 'Pedra do Xamã Descoberta: Fúria dos Ventos Cortantes', 35435),
(79804, 'ptBR', 'Pedra do Xamã Descoberta: Tocado pelo Gelo', 'Pedra do Xamã Descoberta: Tocado pelo Gelo', 35435),
(194274, 'ptBR', 'I want to teleport to Operation: Mechagon (Dungeon).', 'I want to teleport to Operation: Mechagon (Dungeon).', 35435),
(183984, 'ptBR', '|cfff2e699+$1i Sanidade|r', '|cfff2e699+$1i Sanidade|r', 35435),
(201777, 'ptBR', '', 'Eu sei como podemos alcançar a filha do mar. Sigam-me quando estiverem prontos.', 35435),
(79794, 'ptBR', 'Pedra Xamânica Descoberta: Bênção do Lobo', 'Pedra Xamânica Descoberta: Bênção do Lobo', 35435),
(79795, 'ptBR', 'Pedra Xamânica Descoberta: Espírito Lobo', 'Pedra Xamânica Descoberta: Espírito Lobo', 35435),
(141708, 'ptBR', 'Enfraqueça o grifo sem perder a firmeza com |TInterface\\ICONS\\INV_MISC_DESECRATED_LEATHERGLOVE.BLP:20|t |cFFFF0000|Hspell:269442|h[Segura Firme]|h|r', '', 35435),
(201784, 'ptBR', 'Eu vi com os meus próprios olhos! A Senhora Jaina atacada em alto mar!', '', 35435),
(165241, 'ptBR', 'Mais fundo, cada vez mais fundo...', 'Mais fundo, cada vez mais fundo...', 35435),
(165243, 'ptBR', 'Enfim... abracem a verdade das sombras.', 'Enfim... abracem a verdade das sombras.', 35435),
(165245, 'ptBR', 'A cada escolha você declara sua servidão a mim.', 'A cada escolha você declara sua servidão a mim.', 35435),
(165239, 'ptBR', 'Domine a sua fúria... faça do seu ódio uma arma.', 'Domine a sua fúria... faça do seu ódio uma arma.', 35435),
(165246, 'ptBR', 'Meras quinquilharias apodrecem sob o olhar de um deus.', 'Meras quinquilharias apodrecem sob o olhar de um deus.', 35435),
(165244, 'ptBR', 'Sim... mais perto... mais perto.', 'Sim... mais perto... mais perto.', 35435),
(165237, 'ptBR', 'Ah... Você acha que sabe o que é poder?', 'Ah... Você acha que sabe o que é poder?', 35435);

DELETE FROM `gameobjects_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `gameobjects_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(341828, 'ptBR', 'Teleportador de Gnomecan', 35435),
(341363, 'ptBR', 'Teleportador de Gnomecan', 35435),
(338477, 'ptBR', 'Teleportador de Gnomecan', 35435);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'ptBR', 'Escudo da Grandiloquência nos Intertubos', 35435);

DELETE FROM `azerite_essence_power_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `azerite_essence_power_locale` (`ID`, `locale`, `SourceAlliance_lang`, `SourceHorde_lang`, `VerifiedBuild`) VALUES
(114, 'ptBR', 'Visões Horrendas de N\'Zoth|n|cFFFFD200Conquista:|r|n\"As profundezas das visões\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Local:|r Câmara do Coração', '', 35435),
(132, 'ptBR', 'Visões Horrendas de N\'Zoth|n|cFFFFD200Conquista:|r|n\"As profundezas das visões\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Local:|r Câmara do Coração', '', 35435),
(140, 'ptBR', 'Visões Horrendas de N\'Zoth|n|cFFFFD200Conquista:|r|n\"As profundezas das visões\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Local:|r Câmara do Coração', '', 35435);

DELETE FROM `currency_types_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1803, 'ptBR', 'Ecos de Ny\'alotha', 'Essa substância carcomida pela corrupção de N\'Zoth pode ser usada pela M.A.D.R.E. para sintetizar essências na Câmara do Coração.', 35435);

DELETE FROM `spell_name_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(324906, 'ptBR', 'Corruption - Twilight Devastation 2', 35435),
(155343, 'ptBR', 'Pedra do Xamã: Fúria dos Ventos Cortantes', 35435),
(324845, 'ptBR', 'Corruption - Echoing Void 3', 35435),
(304086, 'ptBR', 'Conflito', 35435),
(154259, 'ptBR', 'Pedra Xamânica: Espírito Lobo', 35435),
(155313, 'ptBR', 'Pedra do Xamã: Tocado pelo Fogo', 35435),
(154275, 'ptBR', 'Pedra Xamânica: Espírito Lobo', 35435),
(319451, 'ptBR', 'Teleporte para Gnomecan', 35435),
(324887, 'ptBR', 'Corruption - Twisted Appendage 2', 35435),
(292907, 'ptBR', 'Estilhaço de Gelo Corrompido', 35435),
(324900, 'ptBR', 'Corruption - Honed Mind 2', 35435),
(296464, 'ptBR', 'Relé de Reforço', 35435),
(299937, 'ptBR', 'Relé de Reforço', 35435),
(324852, 'ptBR', 'Corruption - Expedient 2', 35435),
(324892, 'ptBR', 'Corruption - Surging Vitality 1', 35435),
(324901, 'ptBR', 'Corruption - Honed Mind 3', 35435),
(332950, 'ptBR', 'Fire Proc (DNT)', 35435),
(155345, 'ptBR', 'Pedra do Xamã: Fortitude Ôgrica', 35435),
(301578, 'ptBR', 'REUSE ME', 35435),
(155315, 'ptBR', 'Pedra do Xamã: Tocado pelo Fogo', 35435),
(324894, 'ptBR', 'Corruption - Surging Vitality 3', 35435),
(324888, 'ptBR', 'Corruption - Twisted Appendage 3', 35435),
(324886, 'ptBR', 'Corruption - Twisted Appendage 1', 35435),
(324890, 'ptBR', 'Corruption - Infinite Stars 2', 35435),
(324881, 'ptBR', 'Corruption - Glimpse of Clarity', 35435),
(337816, 'ptBR', 'Consequências Inevitáveis', 35435),
(301683, 'ptBR', 'REUSE ME', 35435),
(155347, 'ptBR', 'Pedra Xamânica: Espírito Lobo', 35435),
(324851, 'ptBR', 'Corruption - Expedient 3', 35435),
(154274, 'ptBR', 'Pedra Xamânica: Bênção do Lobo', 35435),
(110556, 'ptBR', '[DNT] Force Cast Tried to Fly', 35435),
(324862, 'ptBR', 'Corruption - Versatile 1', 35435),
(300932, 'ptBR', 'REUSE ME [MTMM] (DNT)', 35435),
(155333, 'ptBR', 'Pedra do Xamã: Tocado pelo Gelo', 35435),
(291435, 'ptBR', 'Poço de Sanidade', 35435),
(324853, 'ptBR', 'Corruption - Expedient 1', 35435),
(324884, 'ptBR', 'Corruption - Void Ritual 2', 35435),
(324893, 'ptBR', 'Corruption - Surging Vitality 2', 35435),
(324854, 'ptBR', 'Corruption - Strikethrough 3', 35435),
(293777, 'ptBR', 'Colisão de Sombras', 35435),
(120679, 'ptBR', 'Fera Atroz', 35435),
(274909, 'ptBR', 'Bruma Crescente', 35435),
(300692, 'ptBR', 'REUSE ME [MTMM] (DNT)', 35435),
(324885, 'ptBR', 'Corruption - Void Ritual 3', 35435),
(155344, 'ptBR', 'Pedra do Xamã: Fúria dos Ventos Cortantes', 35435),
(335642, 'ptBR', 'Uber Strike', 35435),
(335148, 'ptBR', 'Símbolo da Espiral Etérea', 35435),
(315958, 'ptBR', 'Teleporte para Gnomecan', 35435),
(327254, 'ptBR', 'Ameaça de Esporo Putrefato', 35435),
(324839, 'ptBR', 'Corruption - Deadly Momentum 3', 35435),
(264663, 'ptBR', 'Sede do Predador', 35435),
(302166, 'ptBR', 'Relé de Reforço', 35435),
(293072, 'ptBR', 'Poço de Sanidade', 35435),
(311204, 'ptBR', 'Leve-me para Gnomecan', 35435),
(324870, 'ptBR', 'Corruption - Severe 3', 35435),
(155334, 'ptBR', 'Pedra do Xamã: Tocado pelo Gelo', 35435),
(324902, 'ptBR', 'Corruption - Gushing Wound', 35435),
(275496, 'ptBR', 'Justiça Indomável', 35435),
(316661, 'ptBR', 'Destruição Obsidiana', 35435),
(324864, 'ptBR', 'Corruption - Versatile 2', 35435),
(321200, 'ptBR', 'Iniciar Missão', 35435),
(324904, 'ptBR', 'Corruption - Ineffable Truth 2', 35435),
(154253, 'ptBR', 'Pedra Xamânica: Bênção do Lobo', 35435),
(331973, 'ptBR', '', 35435),
(325946, 'ptBR', 'Arremessar Visgo', 35435),
(324891, 'ptBR', 'Corruption - Infinite Stars 3', 35435),
(321748, 'ptBR', 'Clone-me!', 35435),
(324882, 'ptBR', 'Corruption - Void Ritual 1', 35435),
(324860, 'ptBR', 'Corruption - Masterful 2', 35435),
(324850, 'ptBR', 'Corruption - Echoing Void 1', 35435),
(324899, 'ptBR', 'Corruption - Honed Mind 1', 35435),
(294003, 'ptBR', 'Canção do Perscrutador', 35435),
(313040, 'ptBR', 'Trevas Infinitas', 35435),
(324903, 'ptBR', 'Corruption - Ineffable Truth 1', 35435),
(324680, 'ptBR', 'Corruption - Deadly Momentum 1', 35435),
(321201, 'ptBR', 'Iniciar Missão', 35435),
(155346, 'ptBR', 'Pedra do Xamã: Fortitude Ôgrica', 35435),
(294479, 'ptBR', 'Desenterrando', 35435),
(325947, 'ptBR', 'Arremessar Visgo', 35435),
(328136, 'ptBR', 'Influência impressionante', 35435),
(324861, 'ptBR', 'Corruption - Masterful 1', 35435),
(300748, 'ptBR', 'REUSE ME [MTMM] (DNT)', 35435),
(335151, 'ptBR', 'Símbolo das Brumas', 35435),
(324879, 'ptBR', 'Corruption - Siphoner 2', 35435),
(256133, 'ptBR', 'REUSE ME [SCS]', 35435),
(324880, 'ptBR', 'Corruption - Siphoner 3', 35435),
(335152, 'ptBR', 'Símbolo de Ferro', 35435),
(306259, 'ptBR', 'Tentáculo', 35435),
(324858, 'ptBR', 'Corruption - Masterful 3', 35435),
(321428, 'ptBR', 'Tributo Infinito', 35435),
(335150, 'ptBR', 'Símbolo do Destruidor', 35435),
(324907, 'ptBR', 'Corruption - Twilight Devastation 3', 35435),
(324889, 'ptBR', 'Corruption - Infinite Stars 1', 35435),
(324898, 'ptBR', 'Corruption - Racing Pulse 3', 35435),
(256134, 'ptBR', 'REUSE ME [SCS]', 35435),
(324875, 'ptBR', 'Corruption - Avoidant 2', 35435),
(324866, 'ptBR', 'Corruption - Severe 1', 35435),
(300798, 'ptBR', 'REUSE ME [MTMM] (DNT)', 35435),
(292579, 'ptBR', 'Fogueira Próxima', 35435),
(337612, 'ptBR', 'Consequências Inevitáveis', 35435),
(324877, 'ptBR', 'Corruption - Siphoner 1', 35435),
(324868, 'ptBR', 'Corruption - Severe 2', 35435),
(324837, 'ptBR', 'Corruption - Deadly Momentum 2', 35435),
(324848, 'ptBR', 'Corruption - Echoing Void 2', 35435),
(115546, 'ptBR', 'Provocar', 35435),
(324895, 'ptBR', 'Corruption - Avoidant 1', 35435),
(324857, 'ptBR', 'Corruption - Strikethrough 1', 35435),
(324897, 'ptBR', 'Corruption - Racing Pulse 2', 35435),
(321714, 'ptBR', 'Teleporte para Silithus', 35435),
(324896, 'ptBR', 'Corruption - Racing Pulse 1', 35435),
(324856, 'ptBR', 'Corrupção - Trespassar 2', 35435),
(335149, 'ptBR', 'Símbolo do Flagelo', 35435),
(324865, 'ptBR', 'Corruption - Versatile 3', 35435),
(324905, 'ptBR', 'Corruption - Twilight Devastation 1', 35435),
(324874, 'ptBR', 'Corruption - Avoidant 3', 35435);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(85118, 'ptBR', '', 35435),
(85126, 'ptBR', '', 35435),
(85114, 'ptBR', '', 35435),
(85084, 'ptBR', '', 35435),
(85132, 'ptBR', '', 35435),
(85098, 'ptBR', '', 35435),
(85134, 'ptBR', '', 35435),
(85025, 'ptBR', 'Costa Sul x Serraria Tarren', 35435),
(85128, 'ptBR', '', 35435),
(84755, 'ptBR', 'Completed Legendary Cloak Quest', 35435),
(85090, 'ptBR', '', 35435),
(85130, 'ptBR', '', 35435),
(84814, 'ptBR', 'Nightborne player is eligible for Heritage Armor', 35435),
(85100, 'ptBR', '', 35435),
(85136, 'ptBR', '', 35435),
(85102, 'ptBR', '', 35435),
(85138, 'ptBR', '', 35435),
(84815, 'ptBR', 'Mag\'har Orc player is eligible for Heritage Armor', 35435),
(85108, 'ptBR', '', 35435),
(85110, 'ptBR', '', 35435),
(85116, 'ptBR', '', 35435),
(84812, 'ptBR', 'Mechagnome player is eligible for Heritage Armor', 35435),
(78565, 'ptBR', 'Diferencial Sincronizado Perfeitamente', 35435),
(34935, 'ptBR', 'Receber a bênção da Pedra Xamânica: Espírito do Lobo', 35435),
(82623, 'ptBR', 'Tirar o lixo de Gnomecan', 35435),
(84810, 'ptBR', 'Dark Iron Dwarf player is eligible for Heritage Armor', 35435),
(84809, 'ptBR', 'Void elf player is eligible for Heritage Armor', 35435),
(85096, 'ptBR', '', 35435),
(85092, 'ptBR', '', 35435),
(84816, 'ptBR', 'Zandalari Troll player is eligible for Heritage Armor', 35435),
(85122, 'ptBR', '', 35435),
(84808, 'ptBR', 'Highmountain tauren player is eligible for Heritage Armor', 35435),
(85120, 'ptBR', '', 35435),
(85112, 'ptBR', '', 35435),
(84813, 'ptBR', 'Vulpera player is eligible for Heritage Armor', 35435),
(85124, 'ptBR', '', 35435),
(85088, 'ptBR', '', 35435),
(85094, 'ptBR', '', 35435),
(85086, 'ptBR', '', 35435),
(85106, 'ptBR', '', 35435),
(84817, 'ptBR', 'Kul Tiran player is eligible for Heritage Armor', 35435),
(85104, 'ptBR', '', 35435),
(84811, 'ptBR', 'Lightforged draenei player is eligible for Heritage Armor', 35435);

DELETE FROM `item_name_description_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `item_name_description_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(13566, 'ptBR', '35 de Corrupção', 35435),
(13578, 'ptBR', '16 de Corrupção', 35435),
(13569, 'ptBR', '10 de Corrupção', 35435),
(13574, 'ptBR', '28 de Corrupção', 35435),
(13572, 'ptBR', '25 de Corrupção', 35435),
(13520, 'ptBR', '30 de Corrupção', 35435),
(13579, 'ptBR', '8 de Corrupção', 35435),
(13516, 'ptBR', '5 de Corrupção', 35435),
(13568, 'ptBR', '20 de Corrupção', 35435),
(13521, 'ptBR', '5-30 de Corrupção', 35435),
(13576, 'ptBR', '30 de Corrupção', 35435),
(13518, 'ptBR', '15 de Corrupção', 35435),
(13519, 'ptBR', '20 de Corrupção', 35435),
(13577, 'ptBR', '12 de Corrupção', 35435),
(13575, 'ptBR', '17 de Corrupção', 35435),
(13570, 'ptBR', '75 de Corrupção', 35435),
(13565, 'ptBR', '66 de Corrupção', 35435),
(13513, 'ptBR', '25 de Corrupção', 35435),
(13580, 'ptBR', '60 de Corrupção', 35435),
(13517, 'ptBR', '10 de Corrupção', 35435),
(13571, 'ptBR', '50 de Corrupção', 35435),
(13573, 'ptBR', '45 de Corrupção', 35435),
(13567, 'ptBR', '15 de Corrupção', 35435);

DELETE FROM `area_table_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12825, 'ptBR', 'Cidade de Gnomecan', 35435),
(10290, 'ptBR', 'Gnomecan', 35435);

DELETE FROM `ui_map_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `ui_map_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1574, 'ptBR', 'Cidade de Gnomecan', 35435),
(1573, 'ptBR', 'Cidade de Gnomecan', 35435);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(177977, 'ptBR', '', '', '', '', 'Contaminante Preservado: Ferida Torrente', 35435),
(177997, 'ptBR', '', '', '', '', 'Contaminante Preservado: Canalizador', 35435),
(178006, 'ptBR', '', '', '', '', 'Contaminante Preservado: Devastação do Crepúsculo', 35435),
(177974, 'ptBR', '', '', '', '', 'Contaminante Preservado: Expedito', 35435),
(177976, 'ptBR', '', '', '', '', 'Contaminante Preservado: Vislumbre de Clareza', 35435),
(178015, 'ptBR', '', '', '', '', 'Contaminante Preservado: Ritual do Caos', 35435),
(178012, 'ptBR', '', '', '', '', 'Contaminante Preservado: Versátil', 35435),
(87487, 'ptBR', '', '', '', '', 'Escudo da Grandiloquência nos Intertubos', 35435),
(177983, 'ptBR', '', '', '', '', 'Contaminante Preservado: Estrelas Infinitas', 35435),
(177980, 'ptBR', '', '', '', '', 'Contaminante Preservado: Mente Afiada', 35435),
(178004, 'ptBR', '', '', '', '', 'Contaminante Preservado: Devastação do Crepúsculo', 35435),
(177987, 'ptBR', '', '', '', '', 'Contaminante Preservado: Primoroso', 35435),
(177965, 'ptBR', '', '', '', '', 'Contaminante Preservado: Inércia Mortífera', 35435),
(177989, 'ptBR', '', '', '', '', 'Contaminante Preservado: Pulso Acelerado', 35435),
(177998, 'ptBR', '', '', '', '', 'Contaminante Preservado: Trespassar', 35435),
(178011, 'ptBR', '', '', '', '', 'Contaminante Preservado: Versátil', 35435),
(177993, 'ptBR', '', '', '', '', 'Contaminante Preservado: Severo', 35435),
(177978, 'ptBR', '', '', '', '', 'Contaminante Preservado: Mente Afiada', 35435),
(178002, 'ptBR', '', '', '', '', 'Contaminante Preservado: Vitalidade Fervilhante', 35435),
(177967, 'ptBR', '', '', '', '', 'Contaminante Preservado: Caos Ecoante', 35435),
(177970, 'ptBR', '', '', '', '', 'Contaminante Preservado: Evasivo', 35435),
(177972, 'ptBR', '', '', '', '', 'Contaminante Preservado: Evasivo', 35435),
(177992, 'ptBR', '', '', '', '', 'Contaminante Preservado: Severo', 35435),
(177985, 'ptBR', '', '', '', '', 'Contaminante Preservado: Estrelas Infinitas', 35435),
(177982, 'ptBR', '', '', '', '', 'Contaminante Preservado: Verdade Inefável', 35435),
(177991, 'ptBR', '', '', '', '', 'Contaminante Preservado: Pulso Acelerado', 35435),
(177971, 'ptBR', '', '', '', '', 'Contaminante Preservado: Evasivo', 35435),
(168043, 'ptBR', 'Cobiçado pelos Amatet, que acreditam ser os guardiões da obra dos Titãs.', '', '', '', 'Artefato Titânico', 35435),
(177964, 'ptBR', '', '', '', '', 'Encantamento Multiplicador de Potência - Arma', 35435),
(177986, 'ptBR', '', '', '', '', 'Contaminante Preservado: Primoroso', 35435),
(178013, 'ptBR', '', '', '', '', 'Contaminante Preservado: Ritual do Caos', 35435),
(177994, 'ptBR', '', '', '', '', 'Contaminante Preservado: Severo', 35435),
(178009, 'ptBR', '', '', '', '', 'Contaminante Preservado: Apêndice Retorcido', 35435),
(173937, 'ptBR', 'O olho desconectado captura o seu olhar para onde quer que você olhe.', '', '', '', 'Óculus Cindido', 35435),
(177973, 'ptBR', '', '', '', '', 'Contaminante Preservado: Expedito', 35435),
(178007, 'ptBR', '', '', '', '', 'Contaminante Preservado: Apêndice Retorcido', 35435),
(177981, 'ptBR', '', '', '', '', 'Contaminante Preservado: Verdade Inefável', 35435),
(178003, 'ptBR', '', '', '', '', 'Contaminante Preservado: Vitalidade Fervilhante', 35435),
(177979, 'ptBR', '', '', '', '', 'Contaminante Preservado: Mente Afiada', 35435),
(177966, 'ptBR', '', '', '', '', 'Contaminante Preservado: Inércia Mortífera', 35435),
(177999, 'ptBR', '', '', '', '', 'Contaminante Preservado: Trespassar', 35435),
(178010, 'ptBR', '', '', '', '', 'Contaminante Preservado: Versátil', 35435),
(177969, 'ptBR', '', '', '', '', 'Contaminante Preservado: Caos Ecoante', 35435),
(178000, 'ptBR', '', '', '', '', 'Contaminante Preservado: Trespassar', 35435),
(177975, 'ptBR', '', '', '', '', 'Contaminante Preservado: Expedito', 35435),
(178001, 'ptBR', '', '', '', '', 'Contaminante Preservado: Vitalidade Fervilhante', 35435),
(178008, 'ptBR', '', '', '', '', 'Contaminante Preservado: Apêndice Retorcido', 35435),
(177995, 'ptBR', '', '', '', '', 'Contaminante Preservado: Canalizador', 35435),
(177968, 'ptBR', '', '', '', '', 'Contaminante Preservado: Caos Ecoante', 35435),
(177955, 'ptBR', '', '', '', '', 'Contaminante Preservado: Inércia Mortífera', 35435),
(177988, 'ptBR', '', '', '', '', 'Contaminante Preservado: Primoroso', 35435),
(177996, 'ptBR', '', '', '', '', 'Contaminante Preservado: Canalizador', 35435),
(177984, 'ptBR', '', '', '', '', 'Contaminante Preservado: Estrelas Infinitas', 35435),
(178014, 'ptBR', '', '', '', '', 'Contaminante Preservado: Ritual do Caos', 35435),
(177990, 'ptBR', '', '', '', '', 'Contaminante Preservado: Pulso Acelerado', 35435),
(178005, 'ptBR', '', '', '', '', 'Contaminante Preservado: Devastação do Crepúsculo', 35435),
(141057, 'ptBR', 'Ensina a fazer um Glifo de Estouro de Luz.', '', '', '', 'Técnica: Glifo de Estouro de Luz', 35435),
(139412, 'ptBR', '', '', '', '', 'Belarugas Ninjas', 35435),
(139345, 'ptBR', '', '', '', '', 'Patas de Rato', 35435),
(139411, 'ptBR', '', '', '', '', 'Banquete dos Esgotos', 35435),
(137826, 'ptBR', 'Ensina a fazer um Pingente de Rubiscuro Mágico.', '', '', '', 'Desenho: Pingente de Rubiscuro Mágico', 35435),
(138016, 'ptBR', 'Ensina a fazer um Baú de Roupas: Cidadãos de Dalaran.', '', '', '', 'Molde de Baú de Roupas: Cidadãos de Dalaran', 35435),
(137932, 'ptBR', 'Ensina a fazer uma Argola Flamejante.', '', '', '', 'Receita: Argola Flamejante', 35435),
(137954, 'ptBR', 'Ensina a fazer uma Cilha de Tramasseda.', '', '', '', 'Molde: Cilha de Tramasseda', 35435),
(137901, 'ptBR', 'Ensina a fazer um Cinturão Batalhante.', '', '', '', 'Receita: Cinturão Batalhante', 35435),
(137881, 'ptBR', 'Ensina a fazer um Cinto de Couro Bélico.', '', '', '', 'Receita: Cinto de Couro Bélico', 35435),
(139344, 'ptBR', '', '', '', '', 'Banana de Mana', 35435),
(139347, 'ptBR', '', '', '', '', 'Geleia dos Esgotos', 35435),
(137706, 'ptBR', 'Ensina a fazer uma Carga de Pólvora.', '', '', '', 'Diagrama: Carga de Pólvora', 35435),
(137962, 'ptBR', 'Ensina a fazer uma Cilha de Tramasseda.', '', '', '', 'Molde: Cilha de Tramasseda', 35435),
(137829, 'ptBR', 'Ensina a fazer um Pingente de Rubiscuro Sutil.', '', '', '', 'Desenho: Pingente de Rubiscuro Sutil', 35435),
(137913, 'ptBR', 'Ensina a fazer um Cinturão Batalhante.', '', '', '', 'Receita: Cinturão Batalhante', 35435),
(137917, 'ptBR', 'Ensina a fazer um Cinturão de Tumbescama.', '', '', '', 'Receita: Cinturão de Tumbescama', 35435),
(139431, 'ptBR', '', '', '', '', 'Caixore de Arneses de Rataranhão', 35435),
(141065, 'ptBR', 'Ensina a fazer o Glifo dos Deimoguardas.', '', '', '', 'Técnica: Glifo dos Deimoguardas', 35435),
(137885, 'ptBR', 'Ensina a fazer um Cinto de Couro Medonho.', '', '', '', 'Receita: Cinto de Couro Medonho', 35435),
(137869, 'ptBR', 'Ensina a fazer um Cinto de Couro Bélico.', '', '', '', 'Receita: Cinto de Couro Bélico', 35435),
(127918, 'ptBR', 'Ensina a fazer uma Poção de Mana Ancestral com mais eficiência.', '', '', '', 'Receita: Poção de Mana Ancestral', 35435),
(139422, 'ptBR', '', '', '', '', 'Isca Vil', 35435),
(141058, 'ptBR', 'Ensina a fazer um Glifo de Bagata em Criaturas.', '', '', '', 'Técnica: Glifo de Bagata em Criaturas', 35435),
(141038, 'ptBR', 'Ensina a fazer um Glifo dos Inimigos de Sombra.', '', '', '', 'Técnica: Glifo dos Inimigos de Sombra', 35435),
(139346, 'ptBR', '', '', '', '', 'Líquido Bebível Patenteado da Thuni', 35435),
(137934, 'ptBR', 'Ensina a fazer uma Coleira de Couro para Ajudante.', '', '', '', 'Receita: Coleira de Couro para Ajudante', 35435),
(137831, 'ptBR', 'Ensina a fazer uma Gargantilha de Pandemonita Vingativa.', '', '', '', 'Desenho: Gargantilha de Pandemonita Vingativa', 35435),
(139425, 'ptBR', '', '', '', '', 'Contrato de Vínculo com Diabrete', 35435),
(141850, 'ptBR', 'Ensina a criar um Arnês de Montaria do Chifrancião.', '', '', '', 'Receita: Arnês de Montaria do Chifrancião', 35435),
(137966, 'ptBR', 'Ensina a fazer uma Cilha de Tramasseda Imbuída.', '', '', '', 'Molde: Cilha de Tramasseda Imbuída', 35435);

DELETE FROM `mount_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(468, 'ptBR', 'Quílen Imperial', '|cFFFFD200Promoção:|r Mists of Pandaria Collector\'s Edition', 'As mascotes prediletas dos antigos príncipes Mogu, os Quílen são cavalgaduras leais e destemidas.', 35435),
(1282, 'ptBR', 'Serpente Negra de N\'Zoth', '|cFFFFD200Conquista:|r As profundezas das visões', 'As serpentes negras de N\'Zoth são os arautos da transformação de sua visão suprema em realidade. Somente servos ou inimigos capazes de adentrar este espaço têm chance de capturá-las.', 35435);

DELETE FROM `player_condition_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(79509, 'ptBR', 'Aprenda qualquer essência da Resistência Ferrúgia de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79518, 'ptBR', 'Aprenda Conflito e Tribulação de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79511, 'ptBR', 'Aprenda Força Vital Condensada, Condutor de Vitalidade ou Presente Imorredouro de Azeroth de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79508, 'ptBR', 'Aprenda Sangue do Inimigo, Artífice do Tempo ou Esfera da Supressão de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79523, 'ptBR', 'Aprenda Caos Disforme de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(74078, 'ptBR', 'Requer Ashjra\'kamas, Mortalha da Determinação.', 35435),
(79512, 'ptBR', 'Aprenda Visão da Perfeição de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79505, 'ptBR', 'Aprenda Ondas no Espaço de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79499, 'ptBR', 'Aprenda Íris Focalizadora, Invocação da Mãe da Vida ou Ânima da Vida e Morte de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79522, 'ptBR', 'Aprenda qualquer essência das Visões Horrendas de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79514, 'ptBR', 'Aprenda qualquer essência Rajani ou do Acordo de Uldum de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(75180, 'ptBR', 'Requer a conquista \"As profundezas das visões\" e a Essência de Ranque 3 desbloqueada. (Não pode comprar se já souber.)', 35435),
(79516, 'ptBR', 'Aprenda Memória de Sonhos Lúcidos de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79519, 'ptBR', 'Aprenda qualquer essência Rajani ou do Acordo de Uldum de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79504, 'ptBR', 'Aprenda Força Vital Condensada, Condutor de Vitalidade ou Presente Imorredouro de Azeroth de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(75170, 'ptBR', 'Requer a conquista \"As profundezas das visões\" e a Essência de Ranque 3 desbloqueada. (Não pode comprar se já souber.)', 35435),
(79513, 'ptBR', 'Aprenda Sangue do Inimigo, Artífice do Tempo ou Esfera da Suppressão de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79502, 'ptBR', 'Aprenda Caldeira das Chamas de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79501, 'ptBR', 'Aprenda Íris Focalizadora, Invocação da Mãe da Vida ou Ânima da Vida e Morte de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79486, 'ptBR', 'Aprenda Força Vital Condensada, Condutor de Vitalidade ou Presente Imorredouro de Azeroth de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79515, 'ptBR', 'Aprenda qualquer essência de reputação de Nazjatar de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79510, 'ptBR', 'Aprenda Íris Focalizadora, Invocação da Mãe da Vida ou Ânima da Vida e Morte de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79497, 'ptBR', 'Aprenda Sangue do Inimigo, Artífice do Tempo ou Esfera da Supressão de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79521, 'ptBR', 'Aprenda qualquer essência Rajani ou do Acordo de Uldum de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(75191, 'ptBR', 'Requer a conquista \"As profundezas das visões\" e a essência de Ranque 3 desbloqueada. (Não pode comprar se já souber.)', 35435),
(79506, 'ptBR', 'Aprenda qualquer essência das Visões Horrendas de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79500, 'ptBR', 'Aprenda qualquer essência da Resistência Ferrúgia de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79503, 'ptBR', 'Aprenda qualquer essência da Resistência Ferrúgia de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79498, 'ptBR', 'Aprenda Ressonância da Veia do Mundo de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79507, 'ptBR', 'Aprenda qualquer essência de reputação de Nazjatar de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79517, 'ptBR', 'Aprenda qualquer essência de reputação de Nazjatar de Grau 3 com outro personagem para desbloquear esta essência.', 35435),
(79520, 'ptBR', 'Aprenda qualquer essência das Visões Horrendas de Grau 3 com outro personagem para desbloquear esta essência.', 35435);

DELETE FROM `map_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(2268, 'ptBR', 'Cidade de Gnomecan', '', '', '', '', 35435);

DELETE FROM `wmo_area_table_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `wmo_area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(103067, 'ptBR', 'Cidade de Gnomecan', 35435);

DELETE FROM `achievement_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14260, 'ptBR', '', '', '', 35435),
(14251, 'ptBR', '', '', '', 35435),
(14256, 'ptBR', '', '', '', 35435),
(14263, 'ptBR', '', '', '', 35435),
(14250, 'ptBR', '', '', '', 35435),
(14241, 'ptBR', '', '', '', 35435),
(14246, 'ptBR', '', '', '', 35435),
(14244, 'ptBR', '', '', '', 35435),
(14264, 'ptBR', '', '', '', 35435),
(6980, 'ptBR', 'Segurar quatro Orbes do Poder e matar quatro inimigos que estejam segurando Orbes do Poder em uma mesma batalha do Templo de Kotmogu.', 'Estrela do Templo de Kotmogu', '', 35435),
(14258, 'ptBR', '', '', '', 35435),
(14249, 'ptBR', '', '', '', 35435),
(14254, 'ptBR', '', '', '', 35435),
(14252, 'ptBR', '', '', '', 35435),
(14212, 'ptBR', '', '', '', 35435),
(14245, 'ptBR', '', '', '', 35435),
(14242, 'ptBR', '', '', '', 35435),
(14257, 'ptBR', '', '', '', 35435),
(14255, 'ptBR', '', '', '', 35435),
(14248, 'ptBR', '', '', '', 35435),
(14259, 'ptBR', '', '', '', 35435),
(14261, 'ptBR', '', '', '', 35435),
(14265, 'ptBR', '', '', '', 35435),
(14247, 'ptBR', '', '', '', 35435),
(14240, 'ptBR', '', '', '', 35435),
(14238, 'ptBR', '', 'Azerite Essence - Rank 3 on any character - Azeroth\'s Undying Gift <DND>', '', 35435),
(14253, 'ptBR', '', '', '', 35435),
(14262, 'ptBR', '', '', '', 35435),
(14239, 'ptBR', '', '', '', 35435),
(14243, 'ptBR', '', '', '', 35435);

DELETE FROM `mail_template_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `mail_template_locale` (`ID`, `locale`, `Body_lang`, `VerifiedBuild`) VALUES
(550, 'ptBR', 'Para reativar sua conta com ouro, retiramos dinheiro não coletado do seu correio. Por isso, você verá menos dinheiro no correio do que esperava. Não se espante, nenhum dinheiro se perdeu.\nObrigado, e boas-vindas de volta a Azeroth!\n - A Equipe de Desenvolvimento do WoW', 35435);

DELETE FROM `dungeon_encounter_locale` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `dungeon_encounter_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(786, 'ptBR', 'Alta-sacerdotisa Mar\'li', 35435);


DELETE FROM `hotfix_blob` WHERE `locale` = 'ptBR' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3386943305, 195997, 'ptBR', 0x0778781000B20200000400081000000000000000000000000000000001000000000000000097A80200, 35435), -- CreatureDifficulty
(600565378, 267260, 'ptBR', 0xE56501000000803F6666A63F0093A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267271, 'ptBR', 0xB46501000000803F0000803F009BA80200, 35435), -- CreatureXDisplayInfo
(3386291891, 174231, 'ptBR', 0x4D69726D6964C3A36F205A616E6A276972000000000007000000E56501000000000000000000000000000000803F0000803F0000803F0000803F879402000000000000000000, 35435), -- Creature
(600565378, 267266, 'ptBR', 0xE56501000000803F6666A63F0097A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267274, 'ptBR', 0xEA6501000000803F9A99993F009EA80200, 35435), -- CreatureXDisplayInfo
(813076512, 22908, 'ptBR', 0x760000002B2F0300, 35435), -- SpellLabel
(813076512, 22909, 'ptBR', 0x240100002B2F0300, 35435), -- SpellLabel
(3776013982, 324874, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630390000, 35435), -- Spell
(3776013982, 324905, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C63464646464646464644657661737461C3A7C3A36F20646F2043726570C3BA7363756C6F7C720D0A24407370656C6C646573633331383237360000, 35435), -- Spell
(3776013982, 324865, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353535330000, 35435), -- Spell
(3776013982, 335149, 'ptBR', 0x0047616E686F7320646520726570757461C3A7C3A36F206465205772617468206F6620746865204C696368204B696E6720706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E007C6346463030414139394576656E746F2042C3B46E75733A2043616D696E686164612054656D706F72616C206465205772617468206F6620746865204C696368204B696E677C720D0A0D0A47616E686F7320646520726570757461C3A7C3A36F206465205772617468206F6620746865204C696368204B696E6720706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E00, 35435), -- Spell
(3776013982, 324856, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C6346464646464646465269736361646F7C720D0A24407370656C6C646573633331353238310000, 35435), -- Spell
(3776013982, 324896, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C63464646464646464650756C736F204163656C657261646F7C720D0A24407370656C6C646573633331383236360000, 35435), -- Spell
(3776013982, 321714, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324897, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C63464646464646464650756C736F204163656C657261646F7C720D0A24407370656C6C646573633331383439320000, 35435), -- Spell
(2230237587, 1188, 'ptBR', 0x43696461646520646520476E6F6D6563616E0096010000250600000000000000, 35435), -- UiMapGroupMember
(3776013982, 324857, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C6346464646464646465269736361646F7C720D0A24407370656C6C646573633331353237370000, 35435), -- Spell
(3776013982, 324895, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630370000, 35435), -- Spell
(3776013982, 115546, 'ptBR', 0x0050726F766F6361206F20616C766F2C2066617A656E646F20636F6D2071756520656C652076656E6861206E61207375612064697265C3A7C3A36F20636F6D20243131363138396D33252061206D6169732064652076656C6F6369646164652E243F733131353331355B0D0A0D0A4120686162696C696461646520706F646520736572206C616EC3A7616461206E612073756120457374C3A174756120646F20426F69204E6567726F2C2070726F766F63616E646F206F206D65736D6F2065666569746F20656D20746F646F73206F7320696E696D69676F7320656D20756D207261696F20646520243131383633354131206D20646120657374C3A17475612E5D5B5D0000, 35435), -- Spell
(3776013982, 324848, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C63464646464646464643616F732045636F616E74657C720D0A24407370656C6C646573633331383438350000, 35435), -- Spell
(3776013982, 324837, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496EC3A972636961204D6F7274C3AD666572617C720D0A24407370656C6C646573633331383439330000, 35435), -- Spell
(3776013982, 324868, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464647726176657C720D0A24407370656C6C646573633331353535370000, 35435), -- Spell
(3776013982, 324877, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464643616E616C697A61646F727C720D0A24407370656C6C646573633331353539300000, 35435), -- Spell
(3205218938, 41793, 'ptBR', 0x4755494C445F46494E4445525F504F5354494E475F455850495245440041207075626C696361C3A7C3A36F2065787069726F75210001, 35435), -- GlobalStrings
(3776013982, 337612, 'ptBR', 0x004E275A6F746820746F6D6120706F7373652064612073756120657373C3AA6E6369612C2063617573616E646F2064616E6F206571756976616C656E74652061202473312520646F20736575206DC3A178696D6F20646520706F6E746F7320646520766964612061206361646120247431207320656E7175616E746F20766F63C3AA206573746976657220656D20636F6D626174652E204F2066696D20657374C3A1207072C3B378696D6F2E005265636562656E646F2064616E6F206571756976616C656E74652061202477312520646F206DC3A178696D6F20646520706F6E746F7320646520766964612061206361646120247431207320647572616E7465206F20636F6D626174652E00, 35435), -- Spell
(3776013982, 292579, 'ptBR', 0x004176656E7475726569726F7320636F6E73656775656D206163656E64657220666F677565697261732071756520657374656A616D20706F7220706572746F2E004176656E7475726569726F7320636F6E73656775656D206163656E64657220666F677565697261732071756520657374656A616D20706F7220706572746F2E00, 35435), -- Spell
(2230237587, 1162, 'ptBR', 0x43696461646520646520476E6F6D6563616E008F010000D90500000400000000, 35435), -- UiMapGroupMember
(2035710060, 7072, 'ptBR', 0x457370C3AD7269746F204C6F6120456E736F6D6272656369646F004120416C74612D7361636572646F74697361204D6172276C6920757361206573746120686162696C696461646520656E7175616E746F20657374C3A120706F737375C3AD64612070656C6F20657370C3AD7269746F2064652047617261276A616C2E0D0A0D0A456C612065766F636120756D20457370C3AD7269746F204C6F6120456E736F6D6272656369646F206E6F206C6F63616C206F6E646520657374C3A12E204F20657370C3AD7269746F207365206669786120656D20756D206A6F6761646F7220616C656174C3B372696F2065206F20706572736567756520706F722024313337333935642C206D6174616E646F2D6F20696E7374616E74616E65616D656E7465207365206368656761722061202431333733393041312064652064697374C3A26E6369612E0D0A0D0A5365206F20657370C3AD7269746F2061696E64612065737469766572207669766F206465706F69732064652024313337333935642C20696D6564696174616D656E74652073616C746172C3A120736F627265206F20616C766F2065206F206D61746172C3A12E0030031C8A1B0000A11B02000000000000000000000000DFA209000200320013, 35435), -- JournalEncounterSection
(3776013982, 300798, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324866, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464647726176657C720D0A24407370656C6C646573633331353535340000, 35435), -- Spell
(3776013982, 324875, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630380000, 35435), -- Spell
(3776013982, 256134, 'ptBR', 0x00526564757A206D7569746F2061207175616E746964616465206465206D6174657269616973206E6563657373C3A1726961207061726120637269617220756D204D6F746F7220537570657263617272656761646F2E0000, 35435), -- Spell
(3776013982, 324898, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C63464646464646464650756C736F204163656C657261646F7C720D0A24407370656C6C646573633331383439360000, 35435), -- Spell
(3776013982, 324889, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C617320496E66696E697461737C720D0A24407370656C6C646573633331383237340000, 35435), -- Spell
(3776013982, 324907, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C63464646464646464644657661737461C3A7C3A36F20646F2043726570C3BA7363756C6F7C720D0A24407370656C6C646573633331383437380000, 35435), -- Spell
(3776013982, 335150, 'ptBR', 0x0047616E686F7320646520726570757461C3A7C3A36F2064652043617461636C79736D20706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E007C6346463030414139394576656E746F2042C3B46E75733A2043616D696E686164612054656D706F72616C2064652043617461636C79736D7C720D0A0D0A47616E686F7320646520726570757461C3A7C3A36F2064652043617461636C79736D20706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E00, 35435), -- Spell
(3776013982, 321428, 'ptBR', 0x004361757361202473312064652064616E6F20646520536F6D627261206120746F646F73206F73206A6F6761646F726573206120636164612024743120732E002473312064652064616E6F20646520536F6D627261206361757361646F206120636164612024743120732E00, 35435), -- Spell
(2035710060, 7071, 'ptBR', 0x49726120646F73204C6F61004120416C74612D7361636572646F74697361204D6172276C6920757361206573746120686162696C696461646520656E7175616E746F20657374C3A120706F737375C3AD64612070656C6F20657370C3AD7269746F2064652047617261276A616C2E0D0A0D0A456C61206174696E676520756D206A6F6761646F7220636F6D20612049726120646F73204C6F612C2063617573616E646F202431333733343773312064652064616E6F20646520536F6D6272612E0030031B8A1B0000A01B02000000000000000000000000BC62090000004000FF, 35435), -- JournalEncounterSection
(3776013982, 324858, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646465072696D6F726F736F7C720D0A24407370656C6C646573633331353533310000, 35435), -- Spell
(3776013982, 306259, 'ptBR', 0x000000, 35435), -- Spell
(2901650891, 1582, 'ptBR', 0x416C74612D7361636572646F74697361204D6172276C6900002E060000300372BA0000000000000309000000, 35435), -- JournalEncounterCreature
(3776013982, 335152, 'ptBR', 0x0047616E686F7320646520726570757461C3A7C3A36F206465205761726C6F726473206F6620447261656E6F7220706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E007C6346463030414139394576656E746F2042C3B46E75733A2043616D696E686164612054656D706F72616C206465205761726C6F726473206F6620447261656E6F727C720D0A0D0A47616E686F7320646520726570757461C3A7C3A36F206465205761726C6F726473206F6620447261656E6F7220706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E00, 35435), -- Spell
(3776013982, 324880, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464643616E616C697A61646F727C720D0A24407370656C6C646573633331353539320000, 35435), -- Spell
(3776013982, 256133, 'ptBR', 0x00526564757A2061207175616E746964616465206465206D6174657269616973206E6563657373C3A1726961207061726120637269617220756D204D6F746F7220537570657263617272656761646F2E0000, 35435), -- Spell
(3776013982, 324879, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464643616E616C697A61646F727C720D0A24407370656C6C646573633331353539310000, 35435), -- Spell
(3776013982, 335151, 'ptBR', 0x0047616E686F7320646520726570757461C3A7C3A36F206465204D69737473206F662050616E646172696120706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E007C6346463030414139394576656E746F2042C3B46E75733A2043616D696E686164612054656D706F72616C206465204D69737473206F662050616E64617269617C720D0A0D0A47616E686F7320646520726570757461C3A7C3A36F206465204D69737473206F662050616E646172696120706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E00, 35435), -- Spell
(3776013982, 300748, 'ptBR', 0x000000, 35435), -- Spell
(20077728, 396607, 'ptBR', 0x000001000000474302000001006FD6, 35435), -- QuestObjective
(3205218938, 42497, 'ptBR', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F5449544C4500566F63C3AA20666F692070726F6D6F7669646F2061206CC3AD6465727C54496E746572666163655C5C47726F75704672616D655C5C55492D47726F75702D4C656164657249636F6E3A303A303A303A2D317C74207C6E7C6E7C636666666664323030476F737461726961206465206C6973746172206F20677275706F206E6F76616D656E74653A7C727C6E25737C6E0001, 35435), -- GlobalStrings
(3776013982, 324861, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646465072696D6F726F736F7C720D0A24407370656C6C646573633331353532390000, 35435), -- Spell
(3776013982, 328136, 'ptBR', 0x0041756D656E74612067616E686F7320646520726570757461C3A7C3A26F20656D2041726775732C204B756C20546972617A2C205A616E64616C61722C204E617A6A617461722065206E617320496C6861732050617274696461732061756D656E746164617320656D20247331252E0047616E686F7320646520726570757461C3A7C3A36F20656D2041726775732C204B756C20546972617A2C205A616E64616C61722C204E617A6A617461722065206E617320496C6861732050617274696461732061756D656E746164617320656D20247331252000, 35435), -- Spell
(3776013982, 325947, 'ptBR', 0x0024407370656C6C646573633239363832300000, 35435), -- Spell
(3776013982, 294479, 'ptBR', 0x000050726F637572616E646F20617274656661746F7320616E7469676F732E00, 35435), -- Spell
(3776013982, 155346, 'ptBR', 0x00566F63C3AA207365207472616E73666F726D6172C3A120706572696F646963616D656E746520656D20756D20706F6465726F736F204F67726F20646520466F676F6672696F2C206F20717565206C686520636F6E6365646572C3A120243135353333377332252061206D61697320646520726573697374C3AA6E63696120612065666569746F732064616E6F736F732E00566F63C3AA207365207472616E73666F726D6172C3A120706572696F646963616D656E746520656D20756D20706F6465726F736F204F67726F20646520466F676F6672696F2C206F20717565206C686520636F6E6365646572C3A120243135353333377332252061206D61697320646520726573697374C3AA6E63696120612065666569746F732064616E6F736F732E00, 35435), -- Spell
(3776013982, 321201, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324680, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496EC3A972636961204D6F7274C3AD666572617C720D0A24407370656C6C646573633331383236380000, 35435), -- Spell
(3776013982, 324903, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C634646464646464646566572646164657320496E6566C3A1766569737C720D0A24407370656C6C646573633331383330330000, 35435), -- Spell
(3205218938, 42500, 'ptBR', 0x47524F55505F46494E4445525F4445534C4953545F5741524E494E475F454449545F4C495354494E4700456469746172206C6973746167656D0001, 35435), -- GlobalStrings
(3776013982, 313040, 'ptBR', 0x004162726520756D20726173676F206E6F2074656369646F2074656D706F72616C2C206472656E616E646F202433313330343073322064652053616E696461646520652063617573616E646F202433313330343073312064652064616E6F20646520536F6D627261206120746F646F73206F7320696E696D69676F732E0D0A0D0A412066656E646120637269612024407370656C6C6E616D6533313736323720706F722024333137363334442E0000, 35435), -- Spell
(3205218938, 42645, 'ptBR', 0x424E45545F4552524F525F34303031310028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C0002, 35435), -- GlobalStrings
(3776013982, 294003, 'ptBR', 0x00004C6F7563757261732072656D6F76696461732E0D0A526567656E6572616E646F2053616E69646164652E00, 35435), -- Spell
(3776013982, 324899, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E7465204166696164617C720D0A24407370656C6C646573633331383236390000, 35435), -- Spell
(3776013982, 324850, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C63464646464646464643616F732045636F616E74657C720D0A24407370656C6C646573633331383238300000, 35435), -- Spell
(3776013982, 324860, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646465072696D6F726F736F7C720D0A24407370656C6C646573633331353533300000, 35435), -- Spell
(3776013982, 324882, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C20646F2043616F737C720D0A24407370656C6C646573633331383238360000, 35435), -- Spell
(3776013982, 321748, 'ptBR', 0x0046617A206F20616C766F20617475616C20636C6F6E6172206F206C616EC3A761646F722E0000, 35435), -- Spell
(3776013982, 324891, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C617320496E66696E697461737C720D0A24407370656C6C646573633331383438380000, 35435), -- Spell
(3776013982, 325946, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 331973, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 154253, 'ptBR', 0x00556D204C6F626F20646F2047656C6F20C3A0732076657A657320616A7564612063616D7065C3B5657320646F20636CC3A3204C6F626F20646F2047656C6F2E00556D204C6F626F20646F2047656C6F20C3A0732076657A657320616A7564612063616D7065C3B5657320646F20636CC3A3204C6F626F20646F2047656C6F2E00, 35435), -- Spell
(3776013982, 324904, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C634646464646464646566572646164657320496E6566C3A1766569737C720D0A24407370656C6C646573633331383438340000, 35435), -- Spell
(3776013982, 321200, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324864, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353535320000, 35435), -- Spell
(3776013982, 316661, 'ptBR', 0x0024407370656C6C646573633331363635310000, 35435), -- Spell
(3776013982, 275496, 'ptBR', 0x004A756C67616D656E746F206361757361206D6169732064616E6F20736520612073756120706F7263656E746167656D206465207669646120666F72206D61696F7220717565206120646F20616C766F2C2063686567616E646F2061206174C3A9202473312064652064616E6F2E0000, 35435), -- Spell
(3776013982, 324902, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F49726F6E4D616964656E735F436F72727570746564426C6F6F642E626C703A32347C74207C63464646464646464646657269646120546F7272656E74657C720D0A24407370656C6C646573633331383237320000, 35435), -- Spell
(3776013982, 155334, 'ptBR', 0x00566F63C3AA20657374C3A120656D2073696E746F6E696120636F6D206F2067656C6F20646120C3A17265612E205365757320696E696D69676F7320636F6E67656C6172C3A36F20616C6561746F7269616D656E74652070656C61207375612070726573656EC3A7612E005365757320696E696D69676F7320636F6E67656C6172C3A36F20616C6561746F7269616D656E74652070656C61207375612070726573656EC3A7612E00, 35435), -- Spell
(3776013982, 324870, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464647726176657C720D0A24407370656C6C646573633331353535380000, 35435), -- Spell
(3776013982, 311204, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 293072, 'ptBR', 0x004372696120756D6120706FC3A761206E6567726120717565206472656E6120246F322064652053616E696461646520616F206C6F6E676F20646520246420646F7320696E696D69676F732071756520656E74726172656D206E656C612E005065726465202473322064652053616E6964616465206120636164612024743220732E00, 35435), -- Spell
(3776013982, 302166, 'ptBR', 0x004F204361C3A761646F722D617373617373696E6F2074656C65706F72746120756E696461646573206465207265666F72C3A76F20646520476E6F6D6563616E2E0000, 35435), -- Spell
(3776013982, 264663, 'ptBR', 0x4665726F636964616465205061737369766100566F63C3AA20652073657520616A7564616E74652067616E68616D202473312520646520536F727665722E00536F727665722061756D656E7461646F20656D20247732252E00, 35435), -- Spell
(3776013982, 324839, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74680D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496EC3A972636961204D6F7274C3AD666572617C720D0A24407370656C6C646573633331383439370000, 35435), -- Spell
(3776013982, 327254, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 315958, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 335148, 'ptBR', 0x0047616E686F7320646520726570757461C3A7C3A36F206465204275726E696E67204372757361646520706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E007C6346463030414139394576656E746F2042C3B46E75733A2043616D696E686164612054656D706F72616C206465204275726E696E6720437275736164657C720D0A0D0A47616E686F7320646520726570757461C3A7C3A36F206465204275726E696E67204372757361646520706F7220636F6D626174652065206D697373C3B565732061756D656E7461646F7320656D20247331252E00, 35435), -- Spell
(3776013982, 335642, 'ptBR', 0x00537472696B65732074686520656E656D7920666F72202473312520776561706F6E2064616D61676520617320536861646F772C20616E6420696E637265617365732064616D616765206465616C74206279202473322520666F722024642E0044616E6F206361757361646F2061756D656E7461646F20656D202473322500, 35435), -- Spell
(3776013982, 155344, 'ptBR', 0x00566F63C3AA207265636562657520612062C3AA6EC3A7C3A36F20646F732076656E746F7320646120536572726120466F676F6672696F2E20566F63C3AA2074656D206368616E63652064652067616E6861722046C3BA72696120646F732056656E746F7320436F7274616E7465732C20636F6E636564656E646F2031303025206465204163656C657261C3A7C3A36F2065206C6576697461C3A7C3A36F2E00566F63C3AA2074656D206368616E63652064652067616E6861722046C3BA72696120646F732056656E746F7320436F7274616E7465732C20636F6E636564656E646F2031303025206465204163656C657261C3A7C3A36F2065206C6576697461C3A7C3A36F2E00, 35435), -- Spell
(3205218938, 41792, 'ptBR', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952455F534F4F4E005075626C696361C3A7C3A36F2065787069726120656D3A0001, 35435), -- GlobalStrings
(3776013982, 324885, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C20646F2043616F737C720D0A24407370656C6C646573633331383438300000, 35435), -- Spell
(3776013982, 300692, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 274909, 'ptBR', 0x00436875746520646F20536F6C204E617363656E746520637572612024323734393132733120706F6E746F73206465207669646120646520746F646F73206F7320616C6961646F73207175652074656E68616D206F732073657573206665697469C3A76F73204272756D61732064612052656E6F7661C3A7C3A36F2C204272756D6120456E766F6C76656E7465206F7520466F6E746520646520457373C3AA6E6369612C20616CC3A96D2064652070726F6C6F6E67617220656D20247331207320746F646F732065737365732065666569746F7320656D206174C3A920247332252064612064757261C3A7C3A36F206F726967696E616C2E0000, 35435), -- Spell
(2035710060, 7050, 'ptBR', 0x416C74612D7361636572646F74697361204D6172276C69000030031800009D1B00000172BA000000000000000000000000000001000000FF, 35435), -- JournalEncounterSection
(3776013982, 120679, 'ptBR', 0x0045766F636120756D6120666572612073656C766167656D206520706F6465726F736120717565206174616361206F20616C766F206520727567652C2061756D656E74616E646F20656D2024323831303336733125206120737561204163656C657261C3A7C3A36F20706F722024642E0000, 35435), -- Spell
(3776013982, 293777, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324854, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C6346464646464646465269736361646F7C720D0A24407370656C6C646573633331353238320000, 35435), -- Spell
(3776013982, 324893, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C69646164652046657276696C68616E74657C720D0A24407370656C6C646573633331383439350000, 35435), -- Spell
(3776013982, 324884, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C20646F2043616F737C720D0A24407370656C6C646573633331383437390000, 35435), -- Spell
(3776013982, 324853, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C7420207C634646464646464646457870656469746F7C720D0A24407370656C6C646573633331353534340000, 35435), -- Spell
(3776013982, 291435, 'ptBR', 0x004372696120756D6120706FC3A761206E6567726120717565206472656E6120246F322064652053616E696461646520616F206C6F6E676F20646520246420646F7320696E696D69676F732071756520656E74726172656D206E656C612E005065726465202473322064652053616E6964616465206120636164612024743220732E00, 35435), -- Spell
(3776013982, 155333, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 300932, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324862, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353534390000, 35435), -- Spell
(3205218938, 42496, 'ptBR', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F53554254455854007C6E2573206174C3A9207365722072656D6F7669646F206461206C69737461206175746F6D61746963616D656E74650001, 35435), -- GlobalStrings
(3776013982, 110556, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 154274, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324851, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C7420207C634646464646464646457870656469746F7C720D0A24407370656C6C646573633331353534360000, 35435), -- Spell
(3776013982, 155347, 'ptBR', 0x004F206C6F626F20646F20657370C3AD7269746F20646F6D696E6F7520766F63C3AA2C2061756D656E74616E646F20656D2024313534323539733125207375612076656C6F63696461646520646520636F727269646120666F726120646520636F6D62617465206E6120536572726120466F676F6672696F2E0056656C6F63696461646520646520636F72726964612061756D656E7461646120656D2024313534323539733125207175616E646F206573746976657220666F726120646520636F6D626174652E00, 35435), -- Spell
(3776013982, 301683, 'ptBR', 0x00456D69746520756D61206F6E64612064652063616C616672696F73207065C3A76F6E68656E746F7320646120706F7369C3A7C3A36F20646F20696E696D69676F2C2063617573616E646F202473312064652064616E6F206120746F646F73206F7320696E696D69676F7320656D20756D207261696F2064652035206D2E0000, 35435), -- Spell
(3776013982, 337816, 'ptBR', 0x0024407370656C6C646573633333373631320000, 35435), -- Spell
(3776013982, 324881, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5741524C4F434B5F534F554C535741502E424C503A32347C74207C6346464646464646465669736C756D62726520646520436C6172657A617C720D0A24407370656C6C646573633331383233390000, 35435), -- Spell
(3776013982, 324890, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C617320496E66696E697461737C720D0A24407370656C6C646573633331383438370000, 35435), -- Spell
(3776013982, 324886, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C6346464646464646464170C3AA6E64696365205265746F726369646F7C720D0A24407370656C6C646573633331383438310000, 35435), -- Spell
(3745449290, 6134, 'ptBR', 0x43696461646520646520476E6F6D6563616E0000F61700008E1F2444E4C4BB431233A4C300000000000000007E1A000084110000C5EC000003000000D9050000310800000000000000000000, 35435), -- AreaPOI
(3776013982, 324888, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C6346464646464646464170C3AA6E64696365205265746F726369646F7C720D0A24407370656C6C646573633331383438330000, 35435), -- Spell
(3776013982, 324894, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C69646164652046657276696C68616E74657C720D0A24407370656C6C646573633331383439390000, 35435), -- Spell
(2035710060, 7070, 'ptBR', 0x457370C3AD7269746F204C6F61204162656EC3A76F61646F004120416C74612D7361636572646F74697361204D6172276C692065766F636120756D20457370C3AD7269746F204C6F61204162656EC3A76F61646F206E6F206C6F63616C206F6E646520657374C3A12E204F20657370C3AD7269746F207365206465736C6F636172C3A1206E612064697265C3A7C3A36F20646F20616C6961646F206465204D6172276C6920717565207469766572206D656E6F7320706F6E746F7320646520766964612065206375726172C3A1202431333733303373312520646F20736575206DC3A178696D6F20646520706F6E746F732064652076696461207365206EC3A36F20666F72206D6F72746F20616E7465732064652063686567617220616F20616C766F2E0D0A0D0A5365206F20657370C3AD7269746F2061696E64612065737469766572207669766F206465706F69732064652024313337323837642C20696D6564696174616D656E74652073616C746172C3A120736F627265206F20616C766F2065206375726172C3A1202431333733303373312520646F20736575206DC3A178696D6F20646520706F6E746F7320646520766964612E0030031A8A1B00009F1B02000000000000000000000000C231080000002200FF, 35435), -- JournalEncounterSection
(3776013982, 155315, 'ptBR', 0x00566F63C3AA20657374C3A120656D2073696E746F6E696120636F6D206F20666F676F20646120C3A17265612E20556D2070696C6172206465206C617661206578706C6F646972C3A120736F62207365757320696E696D69676F7320616C6561746F7269616D656E74652E00556D2070696C6172206465206C617661206578706C6F646972C3A120736F62207365757320696E696D69676F7320616C6561746F7269616D656E74652E00, 35435), -- Spell
(3776013982, 301578, 'ptBR', 0x000000, 35435), -- Spell
(2035710060, 7073, 'ptBR', 0x44657374696E6F20546F7274756F736F004120416C74612D7361636572646F74697361204D6172276C6920757361206573746120686162696C696461646520656E7175616E746F20657374C3A120706F737375C3AD64612070656C6F20657370C3AD7269746F2064652047617261276A616C2E0D0A0D0A456C6120617272616E6361206120616C6D6120646520646F6973206A6F6761646F72657320616C656174C3B372696F73206520617320756E652E204361646120756D612070657273656775652061206F757472612C2063617573616E646F202431333739373273312064652064616E6F20646520736F6D627261206120746F646F73206F73206A6F6761646F726573206120636164612024313337393735743120732E204F2064616E6F2064652044657374696E6F20546F7274756F736F20C3A920726564757A69646F20636F6E666F726D652061756D656E746120612064697374C3A26E63696120656E747265206173206475617320616C6D61732E0D0A0D0A5175616E646F20756D6120616C6D61206D6F7272652C207175656272616E646F206F2076C3AD6E63756C6F20656E74726520617320647561732C20612072656D616E657363656E746520636F6D65C3A761206120636175736172202431333739383673312064652064616E6F20646520536F6D627261206120636164612024313337393836743220732E0030031D8A1B00000000020000000000000000000000009B07070002001A000C, 35435), -- JournalEncounterSection
(3776013982, 155345, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 332950, 'ptBR', 0x00005375617320686162696C6964616465732074C3AA6D206368616E6365206465206361757361722024403930353773312064652064616E6F2E00, 35435), -- Spell
(3776013982, 324901, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E7465204166696164617C720D0A24407370656C6C646573633331383439380000, 35435), -- Spell
(3776013982, 324892, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C69646164652046657276696C68616E74657C720D0A24407370656C6C646573633331383237300000, 35435), -- Spell
(3776013982, 324852, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C7420207C634646464646464646457870656469746F7C720D0A24407370656C6C646573633331353534350000, 35435), -- Spell
(3776013982, 299937, 'ptBR', 0x004F204361C3A761646F722D617373617373696E6F2074656C65706F72746120756E696461646573206465207265666F72C3A76F20646520476E6F6D6563616E2E0000, 35435), -- Spell
(3776013982, 296464, 'ptBR', 0x004120556E6964616465206465204F7072657373C3A36F2041C3A972656120484B2D38207472616E73646F62726120756E696461646573206465207265666F72C3A76F20646520476E6F6D6563616E2E0000, 35435), -- Spell
(3205218938, 42646, 'ptBR', 0x424E45545F4552524F525F34303031320028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C202832290002, 35435), -- GlobalStrings
(3776013982, 324900, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E7465204166696164617C720D0A24407370656C6C646573633331383439340000, 35435), -- Spell
(3776013982, 292907, 'ptBR', 0x0044697370617261206E6F20616C766F20756D20657374696C6861C3A76F2064652067656C6F20717565206361757361202473312520646F2064616E6F2064652061746171756520636F6D6F2064616E6F2046C3AD7369636F2E0000, 35435), -- Spell
(3776013982, 324887, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C6346464646464646464170C3AA6E64696365205265746F726369646F7C720D0A24407370656C6C646573633331383438320000, 35435), -- Spell
(3205218938, 41794, 'ptBR', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F455850495245440041207075626C696361C3A7C3A36F2065787069726F75210001, 35435), -- GlobalStrings
(3776013982, 319451, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 154275, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 155313, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 154259, 'ptBR', 0x004F206C6F626F20646F20657370C3AD7269746F20646F6D696E6F7520766F63C3AA2C2061756D656E74616E646F20656D20733125207375612076656C6F63696461646520646520636F7272696461206E6120536572726120466F676F6672696F2E0056656C6F63696461646520646520636F72726964612061756D656E7461646120656D2024733125206E6120536572726120466F676F6672696F2E00, 35435), -- Spell
(3205218938, 41791, 'ptBR', 0x4755494C445F46494E4445525F504F5354494E475F474F494E475F544F5F455850495245005075626C696361C3A7C3A36F2065787069726120656D3A0001, 35435), -- GlobalStrings
(3776013982, 304086, 'ptBR', 0x457373C3AA6E63696120646520417A6572697461005175616E646F20766F63C3AA20657374C3A12061746F72646F61646F2C206F2062656E6566C3AD63696F20646566656E7369766F2064612073756120566572736174696C69646164652061756D656E746120656D20243330343737357331252E0000, 35435), -- Spell
(3776013982, 324845, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C63464646464646464643616F732045636F616E74657C720D0A24407370656C6C646573633331383438360000, 35435), -- Spell
(3776013982, 155343, 'ptBR', 0x000000, 35435), -- Spell
(3776013982, 324906, 'ptBR', 0x00496D6275697220756D206974656D20636F6D20756D612063657061206D616C69676E6120646120436F72727570C3A7C3A36F206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C63464646464646464644657661737461C3A7C3A36F20646F2043726570C3BA7363756C6F7C720D0A24407370656C6C646573633331383437370000, 35435), -- Spell
(2035710060, 7069, 'ptBR', 0x49726120646F73204C6F61004120416C74612D7361636572646F74697361204D6172276C69206174696E676520756D206A6F6761646F7220636F6D20612049726120646F73204C6F612C2063617573616E646F202431333733343473312064652064616E6F205361677261646F2E003003198A1B00009E1B020000000000000000000000002413020000004000FF, 35435), -- JournalEncounterSection
(2948698321, 249, 'ptBR', 0xD6968DCA7ACF9DD1, 35435), -- TactKeyLookup
(2948698321, 259, 'ptBR', 0xB50278B84158ABDF, 35435), -- TactKeyLookup
(603412935, 28663, 'ptBR', 0x3130E9878CE5B1B1E8B7AFE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28664, 'ptBR', 0xE6899BE9BAA6E9838E0004, 35435), -- ChatProfanity
(603412935, 28644, 'ptBR', 0xE689A9E998B4E599A80004, 35435), -- ChatProfanity
(603412935, 28652, 'ptBR', 0xE5A3B9E59C8BE585A9E8A3BD0004, 35435), -- ChatProfanity
(603412935, 28656, 'ptBR', 0xE99988E696B9E5AE89E7949F0004, 35435), -- ChatProfanity
(603412935, 28653, 'ptBR', 0xE994A4E995B0E5B8AE0004, 35435), -- ChatProfanity
(603412935, 28650, 'ptBR', 0x4C69626572617465484B0004, 35435), -- ChatProfanity
(603412935, 28645, 'ptBR', 0xE5BEB7E5AFB8E88C8E0004, 35435), -- ChatProfanity
(603412935, 28648, 'ptBR', 0xE99B8FE5A5B30004, 35435), -- ChatProfanity
(603412935, 28658, 'ptBR', 0xE794B2E7B49AE688A6E78AAF0004, 35435), -- ChatProfanity
(603412935, 28655, 'ptBR', 0xE69C80E9AB98E4BABAE6B0910004, 35435), -- ChatProfanity
(603412935, 28661, 'ptBR', 0xE684BFE88DA3E58589E5BD92E9A699E6B8AF0004, 35435), -- ChatProfanity
(603412935, 28649, 'ptBR', 0xE6B9BFE7A9B40004, 35435), -- ChatProfanity
(603412935, 28657, 'ptBR', 0xE4BD95E4BF8AE4BB810004, 35435), -- ChatProfanity
(603412935, 28647, 'ptBR', 0xE99CB2E998B4E9B8A10004, 35435), -- ChatProfanity
(603412935, 28662, 'ptBR', 0xE58D81E9878CE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28646, 'ptBR', 0xE88C8EE9BE9F0004, 35435), -- ChatProfanity
(603412935, 28651, 'ptBR', 0x66726565484B0004, 35435), -- ChatProfanity
(603412935, 28660, 'ptBR', 0xE88194E982A6E5AEA3E8A8800004, 35435), -- ChatProfanity
(603412935, 28654, 'ptBR', 0xE4BABAE6B091E6A380E5AF9FE999A20004, 35435), -- ChatProfanity
(603412935, 28659, 'ptBR', 0xE696B0E4B8ADE59BBDE88194E982A60004, 35435), -- ChatProfanity
(4033975491, 403803, 'ptBR', 0x0000704100000000000000410000000000000000000000005B290600308A1300000000000000000000000000000000000000000000000000000000204100000000FFFFFFFFFFFF00000000000000000000000AD50100, 35435), -- SpellVisualKitModelAttach
(4146370265, 91772, 'ptBR', 0x0000A0400000000000002041000000000000000000000000000000000000000022130000000000000000000000000000000000000000000000000000000000000000, 35435), -- SpellVisual
(517656225, 6688, 'ptBR', 0x0000803F00000000E17AD43F000000000000000100001A00000000000303000000000000000000000000A4707D3F0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFF4742000000000000000000000000000000000000C8430000964300000040FFFFFFFF02038030E13E022B873D0AD7233C636D2400000020400000003F69000000000000000000803F0000803F6E186F180000000000000000000000000000000000000000403F3333B33E6666E63E0000000000000000000000000000000000000000000000000000000000000000000000008D5E1E008C5E1E008C5E1E00, 35435), -- SpellChainEffects
(4033975491, 404117, 'ptBR', 0x00000000000000000000C03F000000000000000000000000952A0600D9891300000000000000000000000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000009D50100, 35435), -- SpellVisualKitModelAttach
(1181150530, 307455, 'ptBR', 0x020000005B2906000AD50100, 35435), -- SpellVisualKitEffect
(25144992, 2203, 'ptBR', 0x201A0000000000000000000001000000CB0100000000000013000000FFFFFFFF0000000000000000, 35435); -- BeamEffect


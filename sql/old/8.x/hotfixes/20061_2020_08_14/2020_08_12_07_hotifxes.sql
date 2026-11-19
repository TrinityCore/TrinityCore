DELETE FROM `broadcast_text_locale` WHERE `VerifiedBuild`>0 AND `locale` = 'frFR' AND `ID` IN (201778, 753, 195400, 79796, 165870, 79799, 79798, 79804, 194274, 183984, 201777, 79794, 79795, 141708, 201784, 165241, 165243, 165245, 165239, 165246, 165244, 165237);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(201778, 'frFR', 'Nous sommes prêts. Montrez-nous le chemin !', 'Nous sommes prêts. Montrez-nous le chemin !', 35435),
(753, 'frFR', 'Quoi ? Tu veux dire que tu ne peux pas tuer celui-là toi-même ?', '', 35435),
(195400, 'frFR', 'Montrez-moi vos essences synthétisées, je vous prie.', 'Montrez-moi vos essences synthétisées, je vous prie.', 35435),
(79796, 'frFR', 'Pierre chamanique découverte : touché par le Feu', 'Pierre chamanique découverte : touché par le Feu', 35435),
(165870, 'frFR', '', 'Je vous raconterai la chute de Rastakhan quand vous le souhaiterez.', 35435),
(79799, 'frFR', 'Pierre chamanique découverte : robustesse ogre', 'Pierre chamanique découverte : robustesse ogre', 35435),
(79798, 'frFR', 'Pierre chamanique découverte : rafales battantes', 'Pierre chamanique découverte : rafales battantes', 35435),
(79804, 'frFR', 'Pierre chamanique découverte : touché par la Glace', 'Pierre chamanique découverte : touchée par la Glace', 35435),
(194274, 'frFR', 'I want to teleport to Operation: Mechagon (Dungeon).', 'I want to teleport to Operation: Mechagon (Dungeon).', 35435),
(183984, 'frFR', '|cfff2e699Santé mentale +$1i|r', '|cfff2e699Santé mentale +$1i|r', 35435),
(201777, 'frFR', '', 'La fille du vent salé, je sais comment l\’atteindre. Suivez-moi quand vous serez prêts.', 35435),
(79794, 'frFR', 'Pierre chamanique découverte : bénédiction du loup', 'Pierre chamanique découverte : bénédiction du loup', 35435),
(79795, 'frFR', 'Pierre chamanique découverte : esprit du loup', 'Pierre chamanique découverte : esprit du loup', 35435),
(141708, 'frFR', 'Affaiblissez le griffon mais assurez votre prise avec |TInterface\\ICONS\\INV_MISC_DESECRATED_LEATHERGLOVE.BLP:20|t|cFFFF0000|Hspell:269442|hS\’accrocher|h|r.', '', 35435),
(201784, 'frFR', 'J\’l\’ai vu d\’mes propres yeux ! Dame Jaina a été attaquée en pleine mer !', '', 35435),
(165241, 'frFR', 'Profond, toujours plus profond…', 'Profond, toujours plus profond…', 35435),
(165243, 'frFR', 'Enfin… abandonnez-vous à la vérité des ténèbres.', 'Enfin… abandonnez-vous à la vérité des ténèbres.', 35435),
(165245, 'frFR', 'Chacun de vos choix vous rapproche davantage de la servitude.', 'Chacun de vos choix vous rapproche davantage de la servitude.', 35435),
(165239, 'frFR', 'Maîtrisez votre fureur… Transformez votre haine en arme.', 'Maîtrisez votre fureur… Transformez votre haine en arme.', 35435),
(165246, 'frFR', 'Ces babioles se désintègrent sous le seul regard d\’un dieu.', 'Ces babioles se désintègrent sous le seul regard d\’un dieu.', 35435),
(165244, 'frFR', 'Oui… Vous vous rapprochez… encore un peu plus.', 'Oui… Vous vous rapprochez… encore un peu plus.', 35435),
(165237, 'frFR', 'Ha ! Vous croyez savoir ce qu\’est le pouvoir.', 'Ha ! Vous croyez savoir ce qu\’est le pouvoir.', 35435);

DELETE FROM `gameobjects_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `gameobjects_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(341828, 'frFR', 'Téléporteur de Mécagone', 35435),
(341363, 'frFR', 'Téléporteur de Mécagone', 35435),
(338477, 'frFR', 'Téléporteur de Mécagone', 35435);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'frFR', 'Bouclier de résonance sonore', 35435);

DELETE FROM `azerite_essence_power_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `azerite_essence_power_locale` (`ID`, `locale`, `SourceAlliance_lang`, `SourceHorde_lang`, `VerifiedBuild`) VALUES
(114, 'frFR', 'Visions horrifiques de N\’Zoth|n|cFFFFD200Haut fait :|r|nDans les profondeurs des visions|n|cFFFFD200PNJ :|r Irion|n|cFFFFD200Lieu :|r Chambre du Cœur', '', 35435),
(132, 'frFR', 'Visions horrifiques de N\’Zoth|n|cFFFFD200Haut fait :|r|nDans les profondeurs des visions|n|cFFFFD200PNJ :|r Irion|n|cFFFFD200Lieu :|r Chambre du Cœur', '', 35435),
(140, 'frFR', 'Visions horrifiques de N\’Zoth|n|cFFFFD200Haut fait :|r|nDans les profondeurs des visions|n|cFFFFD200PNJ :|r Irion|n|cFFFFD200Lieu :|r Chambre du Cœur', '', 35435);

DELETE FROM `currency_types_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1803, 'frFR', 'Échos de Ny\’alotha', 'Débarrassée de la corruption de N\’Zoth, D.A.M.E. peut utiliser cette substance pour synthétiser des essences dans la chambre du Cœur.', 35435);

DELETE FROM `spell_name_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(324906, 'frFR', 'Corruption - Dévastation du Crépuscule 2', 35435),
(155343, 'frFR', 'Pierre chamanique : Rafales battantes', 35435),
(324845, 'frFR', 'Corruption - Vide résonnant 3', 35435),
(304086, 'frFR', 'Conflit', 35435),
(154259, 'frFR', 'Pierre chamanique : esprit du loup', 35435),
(155313, 'frFR', 'Pierre chamanique : touché par le Feu', 35435),
(154275, 'frFR', 'Pierre chamanique : esprit du loup', 35435),
(319451, 'frFR', 'Téléportation vers Mécagone', 35435),
(324887, 'frFR', 'Corruption - Appendice dénaturé 2', 35435),
(292907, 'frFR', 'Éclat de glace corrompu', 35435),
(324900, 'frFR', 'Corruption - Esprit affûté 2', 35435),
(296464, 'frFR', 'Relais de renfort', 35435),
(299937, 'frFR', 'Relais de renfort', 35435),
(324852, 'frFR', 'Corruption - Efficace 2', 35435),
(324892, 'frFR', 'Corruption - Déferlement de vitalité 1', 35435),
(324901, 'frFR', 'Corruption - Esprit affûté 3', 35435),
(332950, 'frFR', 'Fire Proc (DNT)', 35435),
(155345, 'frFR', 'Pierre chamanique : robustesse ogre', 35435),
(301578, 'frFR', 'REUSE ME', 35435),
(155315, 'frFR', 'Pierre chamanique : touché par le Feu', 35435),
(324894, 'frFR', 'Corruption - Déferlement de vitalité 3', 35435),
(324888, 'frFR', 'Corruption - Appendice dénaturé 3', 35435),
(324886, 'frFR', 'Corruption - Appendice dénaturé 1', 35435),
(324890, 'frFR', 'Corruption - Étoiles infinies 2', 35435),
(324881, 'frFR', 'Corruption - Éclair de lucidité', 35435),
(337816, 'frFR', 'Conséquences inéluctables', 35435),
(301683, 'frFR', 'REUSE ME', 35435),
(155347, 'frFR', 'Pierre chamanique : esprit du loup', 35435),
(324851, 'frFR', 'Corruption - Efficace 3', 35435),
(154274, 'frFR', 'Pierre chamanique : bénédiction du loup', 35435),
(110556, 'frFR', '[DNT] Force Cast Tried to Fly', 35435),
(324862, 'frFR', 'Corruption - Polyvalent 1', 35435),
(300932, 'frFR', 'REUSE ME [MTMM] (DNT)', 35435),
(155333, 'frFR', 'Pierre chamanique : touché par la Glace', 35435),
(291435, 'frFR', 'Nappe de santé mentale', 35435),
(324853, 'frFR', 'Corruption - Efficace 1', 35435),
(324884, 'frFR', 'Corruption - Rituel du Vide 2', 35435),
(324893, 'frFR', 'Corruption - Déferlement de vitalité 2', 35435),
(324854, 'frFR', 'Corruption - Invalidation 3', 35435),
(293777, 'frFR', 'Déferlante d\’ombre', 35435),
(120679, 'frFR', 'Bête féroce', 35435),
(274909, 'frFR', 'Brume levante', 35435),
(300692, 'frFR', 'REUSE ME [MTMM] (DNT)', 35435),
(324885, 'frFR', 'Corruption - Rituel du Vide 3', 35435),
(155344, 'frFR', 'Pierre chamanique : Rafales battantes', 35435),
(335642, 'frFR', 'Hyper frappe', 35435),
(335148, 'frFR', 'Signe du Néant distordu', 35435),
(315958, 'frFR', 'Téléportation vers Mécagone', 35435),
(327254, 'frFR', 'Menace de spore putréfiée', 35435),
(324839, 'frFR', 'Corruption - Élan mortel 3', 35435),
(264663, 'frFR', 'Soif du prédateur', 35435),
(302166, 'frFR', 'Relais de renfort', 35435),
(293072, 'frFR', 'Nappe de santé mentale', 35435),
(311204, 'frFR', 'Direction Mécagone !', 35435),
(324870, 'frFR', 'Corruption - Drastique 3', 35435),
(155334, 'frFR', 'Pierre chamanique : touché par la Glace', 35435),
(324902, 'frFR', 'Corruption - Blessure hémorragique', 35435),
(275496, 'frFR', 'Justice indomptable', 35435),
(316661, 'frFR', 'Destruction obsidienne', 35435),
(324864, 'frFR', 'Corruption - Polyvalent 2', 35435),
(321200, 'frFR', 'Lancer la quête', 35435),
(324904, 'frFR', 'Corruption - Vérité ineffable 2', 35435),
(154253, 'frFR', 'Pierre chamanique : bénédiction du loup', 35435),
(331973, 'frFR', '', 35435),
(325946, 'frFR', 'Lancer de gelée', 35435),
(324891, 'frFR', 'Corruption - Étoiles infinies 3', 35435),
(321748, 'frFR', 'Clonez-moi !', 35435),
(324882, 'frFR', 'Corruption - Rituel du Vide 1', 35435),
(324860, 'frFR', 'Corruption - Magistral 2', 35435),
(324850, 'frFR', 'Corruption - Vide résonnant 1', 35435),
(324899, 'frFR', 'Corruption - Esprit affûté 1', 35435),
(294003, 'frFR', 'Chant du Chercheur', 35435),
(313040, 'frFR', 'Ténèbres infinies', 35435),
(324903, 'frFR', 'Corruption - Vérité ineffable 1', 35435),
(324680, 'frFR', 'Corruption - Élan mortel 1', 35435),
(321201, 'frFR', 'Lancer la quête', 35435),
(155346, 'frFR', 'Pierre chamanique : robustesse ogre', 35435),
(294479, 'frFR', 'Découverte', 35435),
(325947, 'frFR', 'Lancer de gelée', 35435),
(328136, 'frFR', 'Influence impressionnante', 35435),
(324861, 'frFR', 'Corruption - Magistral 1', 35435),
(300748, 'frFR', 'REUSE ME [MTMM] (DNT)', 35435),
(335151, 'frFR', 'Signe des Brumes', 35435),
(324879, 'frFR', 'Corruption - Siphonneur 2', 35435),
(256133, 'frFR', 'REUSE ME [SCS]', 35435),
(324880, 'frFR', 'Corruption - Siphonneur 3', 35435),
(335152, 'frFR', 'Signe de Fer', 35435),
(306259, 'frFR', 'Tentacule', 35435),
(324858, 'frFR', 'Corruption - Magistral 3', 35435),
(321428, 'frFR', 'Tribut de l\’infini', 35435),
(335150, 'frFR', 'Signe du Destructeur', 35435),
(324907, 'frFR', 'Corruption - Dévastation du Crépuscule 3', 35435),
(324889, 'frFR', 'Corruption - Étoiles infinies 1', 35435),
(324898, 'frFR', 'Corruption - Emballement du pouls 3', 35435),
(256134, 'frFR', 'REUSE ME [SCS]', 35435),
(324875, 'frFR', 'Corruption - Évitant 2', 35435),
(324866, 'frFR', 'Corruption - Drastique 1', 35435),
(300798, 'frFR', 'REUSE ME [MTMM] (DNT)', 35435),
(292579, 'frFR', 'Feu de camp proche', 35435),
(337612, 'frFR', 'Conséquences inéluctables', 35435),
(324877, 'frFR', 'Corruption - Siphonneur 1', 35435),
(324868, 'frFR', 'Corruption - Drastique 2', 35435),
(324837, 'frFR', 'Corruption - Élan mortel 2', 35435),
(324848, 'frFR', 'Corruption - Vide résonnant 2', 35435),
(115546, 'frFR', 'Persiflage', 35435),
(324895, 'frFR', 'Corruption - Évitant 1', 35435),
(324857, 'frFR', 'Corruption - Invalidation 1', 35435),
(324897, 'frFR', 'Corruption - Emballement du pouls 2', 35435),
(321714, 'frFR', 'Téléportation vers Silithus', 35435),
(324896, 'frFR', 'Corruption - Emballement du pouls 1', 35435),
(324856, 'frFR', 'Corruption - Invalidation 2', 35435),
(335149, 'frFR', 'Signe du Fléau', 35435),
(324865, 'frFR', 'Corruption - Polyvalent 3', 35435),
(324905, 'frFR', 'Corruption - Dévastation du Crépuscule 1', 35435),
(324874, 'frFR', 'Corruption - Évitant 3', 35435);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(85118, 'frFR', '', 35435),
(85126, 'frFR', '', 35435),
(85114, 'frFR', '', 35435),
(85084, 'frFR', '', 35435),
(85132, 'frFR', '', 35435),
(85098, 'frFR', '', 35435),
(85134, 'frFR', '', 35435),
(85025, 'frFR', 'Moulin-de-Tarren contre Austrivage', 35435),
(85128, 'frFR', '', 35435),
(84755, 'frFR', 'Quête de la cape légendaire terminée', 35435),
(85090, 'frFR', '', 35435),
(85130, 'frFR', '', 35435),
(84814, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Sacrenuit', 35435),
(85100, 'frFR', '', 35435),
(85136, 'frFR', '', 35435),
(85102, 'frFR', '', 35435),
(85138, 'frFR', '', 35435),
(84815, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Orcs mag\’har', 35435),
(85108, 'frFR', '', 35435),
(85110, 'frFR', '', 35435),
(85116, 'frFR', '', 35435),
(84812, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Mécagnomes', 35435),
(78565, 'frFR', 'Différentiel synchronisé à la perfection', 35435),
(34935, 'frFR', 'Bénédiction obtenue de la pierre chamanique : esprit du loup', 35435),
(82623, 'frFR', 'Nettoyer Mécagone de ses déchets', 35435),
(84810, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Nains sombrefer', 35435),
(84809, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Elfes du Vide', 35435),
(85096, 'frFR', '', 35435),
(85092, 'frFR', '', 35435),
(84816, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Trolls zandalari', 35435),
(85122, 'frFR', '', 35435),
(84808, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Taurens de Haut-Roc', 35435),
(85120, 'frFR', '', 35435),
(85112, 'frFR', '', 35435),
(84813, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Vulpérins', 35435),
(85124, 'frFR', '', 35435),
(85088, 'frFR', '', 35435),
(85094, 'frFR', '', 35435),
(85086, 'frFR', '', 35435),
(85106, 'frFR', '', 35435),
(84817, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Kultirassiens', 35435),
(85104, 'frFR', '', 35435),
(84811, 'frFR', 'Le personnage-joueur débloque l\’armure ancestrale des Draeneï Sancteforge', 35435);

DELETE FROM `item_name_description_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `item_name_description_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(13566, 'frFR', '35 points de corruption', 35435),
(13578, 'frFR', '16 points de corruption', 35435),
(13569, 'frFR', '10 points de corruption', 35435),
(13574, 'frFR', '28 points de corruption', 35435),
(13572, 'frFR', '25 points de corruption', 35435),
(13520, 'frFR', '30 points de corruption', 35435),
(13579, 'frFR', '8 points de corruption', 35435),
(13516, 'frFR', '5 points de corruption', 35435),
(13568, 'frFR', '20 points de corruption', 35435),
(13521, 'frFR', '5 à 30 points de corruption', 35435),
(13576, 'frFR', '30 points de corruption', 35435),
(13518, 'frFR', '15 points de corruption', 35435),
(13519, 'frFR', '20 points de corruption', 35435),
(13577, 'frFR', '12 points de corruption', 35435),
(13575, 'frFR', '17 points de corruption', 35435),
(13570, 'frFR', '75 points de corruption', 35435),
(13565, 'frFR', '66 points de corruption', 35435),
(13513, 'frFR', '25 points de corruption', 35435),
(13580, 'frFR', '60 points de corruption', 35435),
(13517, 'frFR', '10 points de corruption', 35435),
(13571, 'frFR', '50 points de corruption', 35435),
(13573, 'frFR', '45 points de corruption', 35435),
(13567, 'frFR', '15 points de corruption', 35435);

DELETE FROM `area_table_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12825, 'frFR', 'Mécagone', 35435),
(10290, 'frFR', 'Île de Mécagone', 35435);

DELETE FROM `ui_map_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `ui_map_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1574, 'frFR', 'Mécagone', 35435),
(1573, 'frFR', 'Mécagone', 35435);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(177977, 'frFR', '', '', '', '', 'Contaminant préservé : Blessure hémorragique', 35435),
(177997, 'frFR', '', '', '', '', 'Contaminant préservé : Siphonneur', 35435),
(178006, 'frFR', '', '', '', '', 'Contaminant préservé : Dévastation du Crépuscule', 35435),
(177974, 'frFR', '', '', '', '', 'Contaminant préservé : Efficace', 35435),
(177976, 'frFR', '', '', '', '', 'Contaminant préservé : Éclair de lucidité', 35435),
(178015, 'frFR', '', '', '', '', 'Contaminant préservé : Rituel du Vide', 35435),
(178012, 'frFR', '', '', '', '', 'Contaminant préservé : Polyvalent', 35435),
(87487, 'frFR', '', '', '', '', 'Bouclier de résonance sonore', 35435),
(177983, 'frFR', '', '', '', '', 'Contaminant préservé : Étoiles infinies', 35435),
(177980, 'frFR', '', '', '', '', 'Contaminant préservé : Esprit affûté', 35435),
(178004, 'frFR', '', '', '', '', 'Contaminant préservé : Dévastation du Crépuscule', 35435),
(177987, 'frFR', '', '', '', '', 'Contaminant préservé : Magistral', 35435),
(177965, 'frFR', '', '', '', '', 'Contaminant préservé : Élan mortel', 35435),
(177989, 'frFR', '', '', '', '', 'Contaminant préservé : Emballement du pouls', 35435),
(177998, 'frFR', '', '', '', '', 'Contaminant préservé : Invalidation', 35435),
(178011, 'frFR', '', '', '', '', 'Contaminant préservé : Polyvalent', 35435),
(177993, 'frFR', '', '', '', '', 'Contaminant préservé : Drastique', 35435),
(177978, 'frFR', '', '', '', '', 'Contaminant préservé : Esprit affûté', 35435),
(178002, 'frFR', '', '', '', '', 'Contaminant préservé : Déferlement de vitalité', 35435),
(177967, 'frFR', '', '', '', '', 'Contaminant préservé : Vide résonnant', 35435),
(177970, 'frFR', '', '', '', '', 'Contaminant préservé : Évitant', 35435),
(177972, 'frFR', '', '', '', '', 'Contaminant préservé : Évitant', 35435),
(177992, 'frFR', '', '', '', '', 'Contaminant préservé : Drastique', 35435),
(177985, 'frFR', '', '', '', '', 'Contaminant préservé : Étoiles infinies', 35435),
(177982, 'frFR', '', '', '', '', 'Contaminant préservé : Vérité ineffable', 35435),
(177991, 'frFR', '', '', '', '', 'Contaminant préservé : Emballement du pouls', 35435),
(177971, 'frFR', '', '', '', '', 'Contaminant préservé : Évitant', 35435),
(168043, 'frFR', 'Convoité par les Amathet qui se considèrent comme les gardiens de l\’héritage des Titans.', '', '', '', 'Artéfact des Titans', 35435),
(177964, 'frFR', '', '', '', '', 'Enchantement d\’arme (Multiplicateur de force)', 35435),
(177986, 'frFR', '', '', '', '', 'Contaminant préservé : Magistral', 35435),
(178013, 'frFR', '', '', '', '', 'Contaminant préservé : Rituel du Vide', 35435),
(177994, 'frFR', '', '', '', '', 'Contaminant préservé : Drastique', 35435),
(178009, 'frFR', '', '', '', '', 'Contaminant préservé : Appendice dénaturé', 35435),
(173937, 'frFR', 'L\’œil énucléé croise votre regard où que vous le portiez.', '', '', '', 'Oculus sectionné', 35435),
(177973, 'frFR', '', '', '', '', 'Contaminant préservé : Efficace', 35435),
(178007, 'frFR', '', '', '', '', 'Contaminant préservé : Appendice dénaturé', 35435),
(177981, 'frFR', '', '', '', '', 'Contaminant préservé : Vérité ineffable', 35435),
(178003, 'frFR', '', '', '', '', 'Contaminant préservé : Déferlement de vitalité', 35435),
(177979, 'frFR', '', '', '', '', 'Contaminant préservé : Esprit affûté', 35435),
(177966, 'frFR', '', '', '', '', 'Contaminant préservé : Élan mortel', 35435),
(177999, 'frFR', '', '', '', '', 'Contaminant préservé : Invalidation', 35435),
(178010, 'frFR', '', '', '', '', 'Contaminant préservé : Polyvalent', 35435),
(177969, 'frFR', '', '', '', '', 'Contaminant préservé : Vide résonnant', 35435),
(178000, 'frFR', '', '', '', '', 'Contaminant préservé : Invalidation', 35435),
(177975, 'frFR', '', '', '', '', 'Contaminant préservé : Efficace', 35435),
(178001, 'frFR', '', '', '', '', 'Contaminant préservé : Déferlement de vitalité', 35435),
(178008, 'frFR', '', '', '', '', 'Contaminant préservé : Appendice dénaturé', 35435),
(177995, 'frFR', '', '', '', '', 'Contaminant préservé : Siphonneur', 35435),
(177968, 'frFR', '', '', '', '', 'Contaminant préservé : Vide résonnant', 35435),
(177955, 'frFR', '', '', '', '', 'Contaminant préservé : Élan mortel', 35435),
(177988, 'frFR', '', '', '', '', 'Contaminant préservé : Magistral', 35435),
(177996, 'frFR', '', '', '', '', 'Contaminant préservé : Siphonneur', 35435),
(177984, 'frFR', '', '', '', '', 'Contaminant préservé : Étoiles infinies', 35435),
(178014, 'frFR', '', '', '', '', 'Contaminant préservé : Rituel du Vide', 35435),
(177990, 'frFR', '', '', '', '', 'Contaminant préservé : Emballement du pouls', 35435),
(178005, 'frFR', '', '', '', '', 'Contaminant préservé : Dévastation du Crépuscule', 35435),
(141057, 'frFR', 'Vous apprend à graver un Glyphe de bang éclair.', '', '', '', 'Technique : Glyphe de bang éclair', 35435),
(139412, 'frFR', '', '', '', '', 'Jeunes tortues de guerre mutantes', 35435),
(139345, 'frFR', '', '', '', '', 'Pattes de rat', 35435),
(139411, 'frFR', '', '', '', '', 'Banquet des Entrailles', 35435),
(137826, 'frFR', 'Vous apprend à façonner un Pendentif en rubistre ensorceleur.', '', '', '', 'Dessin : Pendentif en rubistre ensorceleur', 35435),
(138016, 'frFR', 'Vous apprend à créer un Coffre à vêtements : citoyens de Dalaran.', '', '', '', 'Patron de coffre à vêtements : citoyens de Dalaran', 35435),
(137932, 'frFR', 'Vous apprend à confectionner un Cerceau enflammé.', '', '', '', 'Patron : Cerceau enflammé', 35435),
(137954, 'frFR', 'Vous apprend à confectionner une Cordelière en soie tissée.', '', '', '', 'Patron : Cordelière en soie tissée', 35435),
(137901, 'frFR', 'Vous apprend à confectionner un Ceinturon de ligebataille.', '', '', '', 'Patron : Ceinturon de ligebataille', 35435),
(137881, 'frFR', 'Vous apprend à confectionner une Ceinture peau-de-guerre.', '', '', '', 'Patron : Ceinture peau-de-guerre', 35435),
(139344, 'frFR', '', '', '', '', 'Banane de mana', 35435),
(139347, 'frFR', '', '', '', '', 'Gelée des profondeurs', 35435),
(137706, 'frFR', 'Vous apprend à préparer une Charge de poudre à canon.', '', '', '', 'Schéma : Charge de poudre à canon', 35435),
(137962, 'frFR', 'Vous apprend à confectionner une Cordelière en soie tissée.', '', '', '', 'Patron : Cordelière en soie tissée', 35435),
(137829, 'frFR', 'Vous apprend à façonner un Pendentif en rubistre subtil.', '', '', '', 'Dessin : Pendentif en rubistre subtil', 35435),
(137913, 'frFR', 'Vous apprend à confectionner un Ceinturon de ligebataille.', '', '', '', 'Patron : Ceinturon de ligebataille', 35435),
(137917, 'frFR', 'Vous apprend à confectionner un Ceinturon tombécaille.', '', '', '', 'Patron : Ceinturon tombécaille', 35435),
(139431, 'frFR', '', '', '', '', 'Caisse de harnais de ralezans', 35435),
(141065, 'frFR', 'Vous apprend à graver un Glyphe du garde de terreur.', '', '', '', 'Technique : Glyphe du garde de terreur', 35435),
(137885, 'frFR', 'Vous apprend à confectionner une Ceinture en cuir-effroi.', '', '', '', 'Patron : Ceinture en cuir-effroi', 35435),
(137869, 'frFR', 'Vous apprend à confectionner une Ceinture peau-de-guerre.', '', '', '', 'Patron : Ceinture peau-de-guerre', 35435),
(127918, 'frFR', 'Vous apprend à concocter plus efficacement une Potion de mana antique.', '', '', '', 'Recette : Potion de mana antique', 35435),
(139422, 'frFR', '', '', '', '', 'Appât gangrené', 35435),
(141058, 'frFR', 'Vous apprend à graver un Glyphe de bestiolifice.', '', '', '', 'Technique : Glyphe de bestiolifice', 35435),
(141038, 'frFR', 'Vous apprend à graver un Glyphe d\'ennemis dans l\'ombre.', '', '', '', 'Technique : Glyphe d\'ennemis dans l\'ombre', 35435),
(139346, 'frFR', '', '', '', '', 'Fluide buvable breveté de Thuni', 35435),
(137934, 'frFR', 'Vous apprend à confectionner une Laisse en cuir pour mascotte.', '', '', '', 'Patron : Laisse en cuir pour mascotte', 35435),
(137831, 'frFR', 'Vous apprend à façonner un Sautoir en pandémonite vindicatif.', '', '', '', 'Dessin : Sautoir en pandémonite vindicatif', 35435),
(139425, 'frFR', '', '', '', '', 'Contrat d\'asservissement de diablotin', 35435),
(141850, 'frFR', 'Vous apprend à confectionner un Harnais de monte de noble-bois.', '', '', '', 'Patron : Harnais de monte de noble-bois', 35435),
(137966, 'frFR', 'Vous apprend à confectionner une Cordelière en soie tissée imprégnée.', '', '', '', 'Patron : Cordelière en soie tissée imprégnée', 35435);

DELETE FROM `mount_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(468, 'frFR', 'Quilen impérial', '|cFFFFD200Promotion :|r Édition Collector de Mists of Pandaria', 'Compagnons favoris des anciens princes mogu, les quilen sont des montures loyales qui ne connaissent pas la peur.', 35435),
(1282, 'frFR', 'Serpent noir de N\’Zoth', '|cFFFFD200Haut fait :|r Dans les profondeurs des visions', 'Les serpents noirs de N\’Zoth présagent la réalisation de la vision suprême du Dieu très ancien. Seuls les serviteurs ou ennemis qui peuvent s\’aventurer en ces lieux ont une chance de les dompter.', 35435);

DELETE FROM `player_condition_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(79509, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence de Résistance de Mécarouille sur un autre personnage pour débloquer cette essence.', 35435),
(79518, 'frFR', 'Apprenez le rang 3 de Conflit et discorde sur un autre personnage pour débloquer cette essence.', 35435),
(79511, 'frFR', 'Apprenez le rang 3 de Force vitale condensée, Conduit de vitalité ou Don éternel d\’Azeroth sur un autre personnage pour débloquer cette essence.', 35435),
(79508, 'frFR', 'Apprenez le rang 3 de Sang de l\’ennemi, Artifice du temps ou Sphère incapacitante sur un autre personnage pour débloquer cette essence.', 35435),
(79523, 'frFR', 'Apprenez le rang 3 du Vide informe sur un autre personnage pour débloquer cette essence.', 35435),
(74078, 'frFR', 'Requiert Ashjra\’kamas, voile de détermination.', 35435),
(79512, 'frFR', 'Apprenez le rang 3 de Vision de perfection sur un autre personnage pour débloquer cette essence.', 35435),
(79505, 'frFR', 'Apprenez le rang 3 d\’Ondulation dans l\’espace sur un autre personnage pour débloquer cette essence.', 35435),
(79499, 'frFR', 'Apprenez le rang 3 d\’Essence de l\’iris de focalisation, Invocation de la Lieuse-de-Vie ou Anima de vie et de mort sur un autre personnage pour débloquer cette essence.', 35435),
(79522, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence des visions horrifiques sur un autre personnage pour débloquer cette essence.', 35435),
(79514, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence des Rajani ou de l\’Accord d\’Uldum sur un autre personnage pour débloquer cette essence.', 35435),
(75180, 'frFR', 'Nécessite le haut fait « Dans les profondeurs des visions » et l\’essence de rang 3. Achat impossible si déjà connu.', 35435),
(79516, 'frFR', 'Apprenez le rang 3 de Souvenirs des rêves lucides sur un autre personnage pour débloquer cette essence.', 35435),
(79519, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence des Rajani ou de l\’Accord d\’Uldum sur un autre personnage pour débloquer cette essence.', 35435),
(79504, 'frFR', 'Apprenez le rang 3 de Force vitale condensée, Conduit de vitalité ou Don éternel d\’Azeroth sur un autre personnage pour débloquer cette essence.', 35435),
(75170, 'frFR', 'Nécessite le haut fait « Dans les profondeurs des visions » et l\’essence de rang 3. Achat impossible si déjà connu.', 35435),
(79513, 'frFR', 'Apprenez le rang 3 de Sang de l\’ennemi, Artifice du temps ou Sphère incapacitante sur un autre personnage pour débloquer cette essence.', 35435),
(79502, 'frFR', 'Apprenez le rang 3 du Creuset des flammes sur un autre personnage pour débloquer cette essence.', 35435),
(79501, 'frFR', 'Apprenez le rang 3 d\’Essence de l\’iris de focalisation, Invocation de la Lieuse-de-Vie ou Anima de vie et de mort sur un autre personnage pour débloquer cette essence.', 35435),
(79486, 'frFR', 'Apprenez le rang 3 de Force vitale condensée, Conduit de vitalité ou Don éternel d\’Azeroth sur un autre personnage pour débloquer cette essence.', 35435),
(79515, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence de Réputation de Nazjatar sur un autre personnage pour débloquer cette essence.', 35435),
(79510, 'frFR', 'Apprenez le rang 3 d\’Essence de l\’iris de focalisation, Invocation de la Lieuse-de-Vie ou Anima de vie et de mort sur un autre personnage pour débloquer cette essence.', 35435),
(79497, 'frFR', 'Apprenez le rang 3 de Sang de l\’ennemi, Artifice du temps ou Sphère incapacitante sur un autre personnage pour débloquer cette essence.', 35435),
(79521, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence des Rajani ou de l\’Accord d\’Uldum sur un autre personnage pour débloquer cette essence.', 35435),
(75191, 'frFR', 'Nécessite le haut fait « Dans les profondeurs des visions » et l\’essence de rang 3. Achat impossible si déjà connu.', 35435),
(79506, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence des visions horrifiques sur un autre personnage pour débloquer cette essence.', 35435),
(79500, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence de Résistance de Mécarouille sur un autre personnage pour débloquer cette essence.', 35435),
(79503, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence de Résistance de Mécarouille sur un autre personnage pour débloquer cette essence.', 35435),
(79498, 'frFR', 'Apprenez le rang 3 de Résonance de la veine du monde sur un autre personnage pour débloquer cette essence.', 35435),
(79507, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence de Réputation de Nazjatar sur un autre personnage pour débloquer cette essence.', 35435),
(79517, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence de Réputation de Nazjatar sur un autre personnage pour débloquer cette essence.', 35435),
(79520, 'frFR', 'Apprenez le rang 3 de n\’importe quelle essence des visions horrifiques sur un autre personnage pour débloquer cette essence.', 35435);

DELETE FROM `map_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(2268, 'frFR', 'Mécagone', '', '', '', '', 35435);

DELETE FROM `wmo_area_table_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `wmo_area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(103067, 'frFR', 'Mécagone', 35435);

DELETE FROM `achievement_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14260, 'frFR', '', '', '', 35435),
(14251, 'frFR', '', '', '', 35435),
(14256, 'frFR', '', '', '', 35435),
(14263, 'frFR', '', '', '', 35435),
(14250, 'frFR', '', '', '', 35435),
(14241, 'frFR', '', '', '', 35435),
(14246, 'frFR', '', '', '', 35435),
(14244, 'frFR', '', '', '', 35435),
(14264, 'frFR', '', '', '', 35435),
(6980, 'frFR', 'Tenir quatre Orbes de pouvoir et tuer quatre ennemis tenant un Orbe de pouvoir en un seul match au temple de Kotmogu.', 'Vedette du temple de Kotmogu', '', 35435),
(14258, 'frFR', '', '', '', 35435),
(14249, 'frFR', '', '', '', 35435),
(14254, 'frFR', '', '', '', 35435),
(14252, 'frFR', '', '', '', 35435),
(14212, 'frFR', '', '<Hidden> 8.3 Main Line - Account Has Obtained Legendary Cloak (DNT)', '', 35435),
(14245, 'frFR', '', '', '', 35435),
(14242, 'frFR', '', '', '', 35435),
(14257, 'frFR', '', '', '', 35435),
(14255, 'frFR', '', '', '', 35435),
(14248, 'frFR', '', '', '', 35435),
(14259, 'frFR', '', '', '', 35435),
(14261, 'frFR', '', '', '', 35435),
(14265, 'frFR', '', '', '', 35435),
(14247, 'frFR', '', '', '', 35435),
(14240, 'frFR', '', '', '', 35435),
(14238, 'frFR', '', 'Azerite Essence - Rank 3 on any character - Azeroth\'s Undying Gift <DND>', '', 35435),
(14253, 'frFR', '', '', '', 35435),
(14262, 'frFR', '', '', '', 35435),
(14239, 'frFR', '', '', '', 35435),
(14243, 'frFR', '', '', '', 35435);

DELETE FROM `mail_template_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `mail_template_locale` (`ID`, `locale`, `Body_lang`, `VerifiedBuild`) VALUES
(550, 'frFR', 'Afin de réactiver votre compte avec des pièces d\’or, nous avons retiré des fonds que vous n\’aviez pas encore récupérés dans votre boîte aux lettres. En conséquence, vous remarquerez peut-être qu\’elle contient moins d\’or que vous ne le pensiez. Ne vous en faites pas, vous n\’avez rien perdu !\nMerci ! Nous sommes ravis de vous retrouver sur Azeroth !\nL\’équipe de développement de WoW', 35435);

DELETE FROM `dungeon_encounter_locale` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `dungeon_encounter_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(786, 'frFR', 'Grande prêtresse Mar\'li', 35435);


DELETE FROM `hotfix_blob` WHERE `locale` = 'frFR' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3386943305, 195997, 'frFR', 0x0778781000B20200000400081000000000000000000000000000000001000000000000000097A80200, 35435), -- CreatureDifficulty
(600565378, 267260, 'frFR', 0xE56501000000803F6666A63F0093A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267271, 'frFR', 0xB46501000000803F0000803F009BA80200, 35435), -- CreatureXDisplayInfo
(3386291891, 174231, 'frFR', 0x4D79726D69646F6E207A616E6A276972000000000007000000E56501000000000000000000000000000000803F0000803F0000803F0000803F879402000000000000000000, 35435), -- Creature
(600565378, 267266, 'frFR', 0xE56501000000803F6666A63F0097A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267274, 'frFR', 0xEA6501000000803F9A99993F009EA80200, 35435), -- CreatureXDisplayInfo
(813076512, 22908, 'frFR', 0x760000002B2F0300, 35435), -- SpellLabel
(813076512, 22909, 'frFR', 0x240100002B2F0300, 35435), -- SpellLabel
(3776013982, 324874, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646C389766974616E747C720D0A24407370656C6C646573633331353630390000, 35435), -- Spell
(3776013982, 324905, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C63464646464646464644C3A9766173746174696F6E206475204372C3A970757363756C657C720D0A24407370656C6C646573633331383237360000, 35435), -- Spell
(3776013982, 324865, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C634646464646464646506F6C7976616C656E747C720D0A24407370656C6C646573633331353535330000, 35435), -- Spell
(3776013982, 335149, 'frFR', 0x004761696E732064652072C3A97075746174696F6E206465205772617468206F6620746865204C696368204B696E67206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E0D0A007C634646303041413939C38976C3A86E656D656E7420626F6E7573C2A03A204D61726368657572732064752074656D7073206465205772617468206F6620746865204C696368204B696E677C720D0A0D0A4761696E732064652072C3A97075746174696F6E206465205772617468206F6620746865204C696368204B696E67206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E00, 35435), -- Spell
(3776013982, 324856, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646496E76616C69646174696F6E7C720D0A24407370656C6C646573633331353238310000, 35435), -- Spell
(3776013982, 324896, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646456D62616C6C656D656E7420647520706F756C737C720D0A24407370656C6C646573633331383236360000, 35435), -- Spell
(3776013982, 321714, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324897, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646456D62616C6C656D656E7420647520706F756C737C720D0A24407370656C6C646573633331383439320000, 35435), -- Spell
(2230237587, 1188, 'frFR', 0x4DC3A96361676F6E650096010000250600000000000000, 35435), -- UiMapGroupMember
(3776013982, 324857, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646496E76616C69646174696F6E7C720D0A24407370656C6C646573633331353237370000, 35435), -- Spell
(3776013982, 324895, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646C389766974616E747C720D0A24407370656C6C646573633331353630370000, 35435), -- Spell
(3776013982, 115546, 'frFR', 0x0050726F766F717565206C61206369626C65206574206CE280996F626C69676520C3A0206176616E636572207665727320766F757320C3A020756E652076697465737365206175676D656E74C3A96520646520243131363138396D33252E243F733131353331355B0D0A0D0A566F757320706F7576657A207574696C6973657220636574746520746563686E697175652073757220766F7472652073746174756520647520427566666C65206E6F697220706F7572206170706C6971756572206C65206DC3AA6D652065666665742073757220746F7573206C657320656E6E656D697320C3A0206D6F696E7320646520243131383633354131C2A06DC3A874726573206465206C61207374617475652E5D5B5D0000, 35435), -- Spell
(3776013982, 324848, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566964652072C3A9736F6E6E616E747C720D0A24407370656C6C646573633331383438350000, 35435), -- Spell
(3776013982, 324837, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646C3896C616E206D6F7274656C7C720D0A24407370656C6C646573633331383439330000, 35435), -- Spell
(3776013982, 324868, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646464472617374697175657C720D0A24407370656C6C646573633331353535370000, 35435), -- Spell
(3776013982, 324877, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C634646464646464646536970686F6E6E6575727C720D0A24407370656C6C646573633331353539300000, 35435), -- Spell
(3205218938, 41793, 'frFR', 0x4755494C445F46494E4445525F504F5354494E475F45585049524544004D65737361676520646520726563686572636865206465206775696C6465206578706972C3A9C2A0210001, 35435), -- GlobalStrings
(3776013982, 337612, 'frFR', 0x004EE280997A6F746820726576656E646971756520766F74726520C3A26D6520657420766F757320696E666C69676520756E206D6F6E74616E742064652064C3A967C3A2747320C3A967616C20C3A0202473312520646520766F747265206D6178696D756D20646520706F696E74732064652076696520746F75746573206C657320247431207320656E20636F6D6261742E204C612066696E206573742070726F6368652E00537562697420756E206D6F6E74616E742064652064C3A967C3A2747320C3A967616C20C3A0202477312520646520736F6E206D6178696D756D20646520706F696E74732064652076696520746F75746573206C657320247431207320656E20636F6D6261742E00, 35435), -- Spell
(3776013982, 292579, 'frFR', 0x00546F7574206176656E747572696572206573742063617061626C652064E28099616C6C756D657220756E206665752064652063616D702070726F6368652E00546F7574206176656E747572696572206573742063617061626C652064E28099616C6C756D657220756E206665752064652063616D702070726F6368652E00, 35435), -- Spell
(2230237587, 1162, 'frFR', 0x4DC3A96361676F6E65008F010000D90500000400000000, 35435), -- UiMapGroupMember
(2035710060, 7072, 'frFR', 0x457370726974206C6F61206F6D6272657578004C61206772616E6465207072C3AA747265737365204D6172E280996C69207365207365727420646520636574746520746563686E69717565207175616E6420656C6C652065737420706F7373C3A964C3A96520706172206CE280996573707269742064652047617261E280996A616C2E0D0A0D0A4C61206772616E6465207072C3AA747265737365204D6172E280996C6920696E766F71756520756E20457370726974206C6F61206F6D627265757820C3A0207365732063C3B474C3A9732E204365742065737072697420736520666978652073757220756E20706572736F6E6E6167652D6A6F756575722063686F697369206175206861736172642C206C6520706F7572737569742070656E64616E74202431333733393564206574206C652074756520696E7374616E74616EC3A96D656E742073E28099696C206C65206C616973736520617070726F6368657220C3A0206D6F696E7320646520243133373339304131206DC3A8747265732E0D0A0D0A5369206CE280996573707269742065737420746F756A6F75727320656E2076696520617072C3A8732024313337333935642C20696C20626F6E64697420696E7374616E74616EC3A96D656E7420737572207361206369626C65206574206C61207475652E0030031C8A1B0000A11B02000000000000000000000000DFA209000200320013, 35435), -- JournalEncounterSection
(3776013982, 300798, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324866, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646464472617374697175657C720D0A24407370656C6C646573633331353535340000, 35435), -- Spell
(3776013982, 324875, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646C389766974616E747C720D0A24407370656C6C646573633331353630380000, 35435), -- Spell
(3776013982, 256134, 'frFR', 0x0052C3A964756974206E657474656D656E74206C61207175616E746974C3A920646520636F6D706F73616E74732072657175697320706F75722066616272697175657220756E206D6F7465757220737572616C696D656E74C3A92E0000, 35435), -- Spell
(3776013982, 324898, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646456D62616C6C656D656E7420647520706F756C737C720D0A24407370656C6C646573633331383439360000, 35435), -- Spell
(3776013982, 324889, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C634646464646464646C389746F696C657320696E66696E6965737C720D0A24407370656C6C646573633331383237340000, 35435), -- Spell
(3776013982, 324907, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C63464646464646464644C3A9766173746174696F6E206475204372C3A970757363756C657C720D0A24407370656C6C646573633331383437380000, 35435), -- Spell
(3776013982, 335150, 'frFR', 0x004761696E732064652072C3A97075746174696F6E2064652043617461636C79736D206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E0D0A007C634646303041413939C38976C3A86E656D656E7420626F6E7573C2A03A204D61726368657572732064752074656D70732064652043617461636C79736D7C720D0A0D0A4761696E732064652072C3A97075746174696F6E2064652043617461636C79736D206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E00, 35435), -- Spell
(3776013982, 321428, 'frFR', 0x00496E666C6967652024733120706F696E74732064652064C3A967C3A274732064E280994F6D6272652061757820706572736F6E6E616765732D6A6F756575727320746F75746573206C65732024743120732E00247331C2A0706F696E74732064652064C3A967C3A274732064E280994F6D62726520696E666C6967C3A97320746F75746573206C657320247431C2A0732E00, 35435), -- Spell
(2035710060, 7071, 'frFR', 0x436F7572726F757820646573204C6F6173004C61206772616E6465207072C3AA747265737365204D6172E280996C69207365207365727420646520636574746520746563686E69717565206C6F72737175E28099656C6C652065737420706F7373C3A964C3A96520706172206CE280996573707269742064652047617261E280996A616C2E0D0A0D0A4C61206772616E6465207072C3AA747265737365204D6172E280996C692066726170706520756E20706572736F6E6E6167652D6A6F75657572206176656320436F7572726F757820646573204C6F6173206574206C756920696E666C6967652024313337333437733120706F696E74732064652064C3A967C3A274732064E280994F6D6272652E0030031B8A1B0000A01B02000000000000000000000000BC62090000004000FF, 35435), -- JournalEncounterSection
(3776013982, 324858, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C7C720D0A24407370656C6C646573633331353533310000, 35435), -- Spell
(3776013982, 306259, 'frFR', 0x000000, 35435), -- Spell
(2901650891, 1582, 'frFR', 0x4772616E6465207072C3AA747265737365204D6172E280996C6900002E060000300372BA0000000000000309000000, 35435), -- JournalEncounterCreature
(3776013982, 335152, 'frFR', 0x004761696E732064652072C3A97075746174696F6E206465205761726C6F726473206F6620447261656E6F72206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E0D0A007C634646303041413939C38976C3A86E656D656E7420626F6E7573C2A03A204D61726368657572732064752074656D7073206465205761726C6F726473206F6620447261656E6F727C720D0A0D0A4761696E732064652072C3A97075746174696F6E206465205761726C6F726473206F6620447261656E6F72206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E00, 35435), -- Spell
(3776013982, 324880, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C634646464646464646536970686F6E6E6575727C720D0A24407370656C6C646573633331353539320000, 35435), -- Spell
(3776013982, 256133, 'frFR', 0x0052C3A964756974206C61207175616E746974C3A920646520636F6D706F73616E74732072657175697320706F75722066616272697175657220756E206D6F7465757220737572616C696D656E74C3A92E0000, 35435), -- Spell
(3776013982, 324879, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C634646464646464646536970686F6E6E6575727C720D0A24407370656C6C646573633331353539310000, 35435), -- Spell
(3776013982, 335151, 'frFR', 0x004761696E732064652072C3A97075746174696F6E206465204D69737473206F662050616E6461726961206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E0D0A007C634646303041413939C38976C3A86E656D656E7420626F6E7573C2A03A204D61726368657572732064752074656D7073206465204D69737473206F662050616E64617269617C720D0A0D0A4761696E732064652072C3A97075746174696F6E206465204D69737473206F662050616E6461726961206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E00, 35435), -- Spell
(3776013982, 300748, 'frFR', 0x000000, 35435), -- Spell
(20077728, 396607, 'frFR', 0x000001000000474302000001006FD6, 35435), -- QuestObjective
(3205218938, 42497, 'frFR', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F5449544C4500566F757320C3AA746573206D61696E74656E616E7420726573706F6E7361626C652064752067726F7570657C54496E746572666163655C5C47726F75704672616D655C5C55492D47726F75702D4C656164657249636F6E3A303A303A303A2D317C74207C6E7C6E7C636666666664323030566F756C657A2D766F75732072C3A9696E736372697265206C652067726F757065C2A03A7C727C6E25737C6E0001, 35435), -- GlobalStrings
(3776013982, 324861, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C7C720D0A24407370656C6C646573633331353532390000, 35435), -- Spell
(3776013982, 328136, 'frFR', 0x004175676D656E7465206C6573206761696E732064652072C3A97075746174696F6E2064657320C3AE6C65732042726973C3A965732C2041726775732C204B756C2054697261732C205A616E64616C6172206574204E617A6A6174617220646520247331252E004761696E732064652072C3A97075746174696F6E2064657320C3AE6C65732042726973C3A965732C2041726775732C204B756C2054697261732C205A616E64616C6172206574204E617A6A61746172206175676D656E74C3A97320646520247331252E00, 35435), -- Spell
(3776013982, 325947, 'frFR', 0x0024407370656C6C646573633239363832300000, 35435), -- Spell
(3776013982, 294479, 'frFR', 0x0000C380206C61207265636865726368652064E28099617274C3A9666163747320616E6369656E732E00, 35435), -- Spell
(3776013982, 155346, 'frFR', 0x00566F757320C3AA7465732070C3A972696F64697175656D656E74207472616E73666F726DC3A920656E207075697373616E74204F6772652064652047697672656665752C20636520717569206175676D656E7465206465202431353533333773322520766F7472652072C3A973697374616E63652061757820656666657473206EC3A96761746966732E00566F757320C3AA7465732070C3A972696F64697175656D656E74207472616E73666F726DC3A920656E207075697373616E74204F6772652064652047697672656665752C20636520717569206175676D656E7465206465202431353533333773322520766F7472652072C3A973697374616E63652061757820656666657473206EC3A96761746966732E00, 35435), -- Spell
(3776013982, 321201, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324680, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646C3896C616E206D6F7274656C7C720D0A24407370656C6C646573633331383236380000, 35435), -- Spell
(3776013982, 324903, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C63464646464646464656C3A9726974C3A920696E65666661626C657C720D0A24407370656C6C646573633331383330330000, 35435), -- Spell
(3205218938, 42500, 'frFR', 0x47524F55505F46494E4445525F4445534C4953545F5741524E494E475F454449545F4C495354494E47004D6F646966696572206CE28099696E736372697074696F6E0001, 35435), -- GlobalStrings
(3776013982, 313040, 'frFR', 0x0044C3A96368697265206C65207469737375206465206C612072C3A9616C6974C3A92C2063652071756920647261696E6520243331333034307332C2A0706F696E74732064652073616E74C3A9206D656E74616C6520657420696E666C69676520243331333034307331C2A0706F696E74732064652064C3A967C3A274732064E280994F6D6272652061757820656E6E656D69732E0D0A0D0A4365747465206272C3A8636865206372C3A96520756E65207A6F6E652064652024407370656C6C6E616D653331373632372071756920647572652024333137363334442E0000, 35435), -- Spell
(3205218938, 42645, 'frFR', 0x424E45545F4552524F525F34303031310028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C0002, 35435), -- GlobalStrings
(3776013982, 294003, 'frFR', 0x0000466F6C6965206775C3A97269652E0D0A52C3A967C3A96EC3A9726174696F6E206465206C612073616E74C3A9206D656E74616C652E00, 35435), -- Spell
(3776013982, 324899, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C63464646464646464645737072697420616666C3BB74C3A97C720D0A24407370656C6C646573633331383236390000, 35435), -- Spell
(3776013982, 324850, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566964652072C3A9736F6E6E616E747C720D0A24407370656C6C646573633331383238300000, 35435), -- Spell
(3776013982, 324860, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C7C720D0A24407370656C6C646573633331353533300000, 35435), -- Spell
(3776013982, 324882, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475656C20647520566964657C720D0A24407370656C6C646573633331383238360000, 35435), -- Spell
(3776013982, 321748, 'frFR', 0x0044C3A9636C656E636865206C6520636C6F6E616765206475206C616E6365757220706172206C61206372C3A96174757265206369626CC3A9652E0000, 35435), -- Spell
(3776013982, 324891, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C634646464646464646C389746F696C657320696E66696E6965737C720D0A24407370656C6C646573633331383438380000, 35435), -- Spell
(3776013982, 325946, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 331973, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 154253, 'frFR', 0x004C6573206368616D70696F6E7320647520636C616E204C6F75702D64652D476976726520736F6E7420706172666F697320C3A97061756CC3A9732070617220756E206C6F75702064652067697672652E004C6573206368616D70696F6E7320647520636C616E204C6F75702D64652D476976726520736F6E7420706172666F697320C3A97061756CC3A9732070617220756E206C6F75702064652067697672652E00, 35435), -- Spell
(3776013982, 324904, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C63464646464646464656C3A9726974C3A920696E65666661626C657C720D0A24407370656C6C646573633331383438340000, 35435), -- Spell
(3776013982, 321200, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324864, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C634646464646464646506F6C7976616C656E747C720D0A24407370656C6C646573633331353535320000, 35435), -- Spell
(3776013982, 316661, 'frFR', 0x0024407370656C6C646573633331363635310000, 35435), -- Spell
(3776013982, 275496, 'frFR', 0x005175616E6420766F74726520706F757263656E7461676520646520706F696E7473206465207669652065737420737570C3A9726965757220C3A02063656C7569206465206C61206369626C652C204A7567656D656E7420696E666C696765206465732064C3A967C3A2747320737570706CC3A96D656E74616972657320706F7576616E742061747465696E6472652024733120706F696E74732064652064C3A967C3A27473206175206D6178696D756D2E0000, 35435), -- Spell
(3776013982, 324902, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F49726F6E4D616964656E735F436F72727570746564426C6F6F642E626C703A32347C74207C634646464646464646426C6573737572652068C3A96D6F72726167697175657C720D0A24407370656C6C646573633331383237320000, 35435), -- Spell
(3776013982, 155334, 'frFR', 0x00566F757320C3AA74657320656E206861726D6F6E69652061766563206C6120676C616365206465206365747465207A6F6E652E20566F7320656E6E656D697320736F6E7420706172666F69732067656CC3A9732070617220766F7472652073696D706C65207072C3A973656E63652E00566F7320656E6E656D697320736F6E7420706172666F69732067656CC3A9732070617220766F7472652073696D706C65207072C3A973656E63652E00, 35435), -- Spell
(3776013982, 324870, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646464472617374697175657C720D0A24407370656C6C646573633331353535380000, 35435), -- Spell
(3776013982, 311204, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 293072, 'frFR', 0x004372C3A96520756E20736F6D6272652062617373696E2071756920647261696E6520246F3220706F696E74732064652073616E74C3A9206D656E74616C6520656E2024642061757820656E6E656D6973207175692070C3A96EC3A87472656E742064616E73206365747465207A6F6E652E0053616E74C3A9206D656E74616C652072C3A964756974652064652024733220746F75746573206C657320247432C2A0246C7365636F6E6465733A7365636F6E6465733B2E00, 35435), -- Spell
(3776013982, 302166, 'frFR', 0x004C652063686173736575722D7475657572206661697420617070617261C3AE747265206465732072656E666F727473206465204DC3A96361676F6E652E0000, 35435), -- Spell
(3776013982, 264663, 'frFR', 0x46C3A9726F636974C3A92070617373697665004175676D656E746520766F74726520506F6E6374696F6E2065742063656C6C6520646520766F7472652066616D696C69657220646520247331252E00506F6E6374696F6E206175676D656E74C3A96520646520247732252E00, 35435), -- Spell
(3776013982, 324839, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646C3896C616E206D6F7274656C7C720D0A24407370656C6C646573633331383439370000, 35435), -- Spell
(3776013982, 327254, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 315958, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 335148, 'frFR', 0x004761696E732064652072C3A97075746174696F6E206465204275726E696E672043727573616465206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E0D0A007C634646303041413939C38976C3A86E656D656E7420626F6E7573C2A03A204D61726368657572732064752074656D7073206465204275726E696E6720437275736164657C720D0A0D0A4761696E732064652072C3A97075746174696F6E206465204275726E696E672043727573616465206C6F72732064657320636F6D62617473206574207175C3AA746573206175676D656E74C3A97320646520247331252E00, 35435), -- Spell
(3776013982, 335642, 'frFR', 0x00467261707065206CE28099656E6E656D692C206C756920696E666C6967652024733125206465732064C3A967C3A27473206465206CE2809961726D6520736F757320666F726D652064652064C3A967C3A274732064E280994F6D627265206574206175676D656E7465206C65732064C3A967C3A2747320696E666C6967C3A97320646520247332252070656E64616E742024642E0044C3A967C3A27473206175676D656E74C3A97320646520247332252E00, 35435), -- Spell
(3776013982, 155344, 'frFR', 0x00566F7573206176657A207265C3A775206C612062C3A96EC3A964696374696F6E206465732076656E7473206465206C61206372C3AA74652064652047697672656665752E20566F7573206176657A20756E65206368616E63652064652062C3A96EC3A966696369657220646520526166616C65732062617474616E7465732C2063652071756920766F757320636F6E66C3A8726520313030252064652068C3A27465206574206465206CC3A97669746174696F6E2E00566F7573206176657A20756E65206368616E63652064652062C3A96EC3A966696369657220646520526166616C65732062617474616E7465732C2063652071756920766F757320636F6E66C3A8726520313030252064652068C3A27465206574206465206CC3A97669746174696F6E2E00, 35435), -- Spell
(3205218938, 41792, 'frFR', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952455F534F4F4E0045787069726174696F6E206465206C61207075626C69636174696F6E2064616E73C2A03A0001, 35435), -- GlobalStrings
(3776013982, 324885, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475656C20647520566964657C720D0A24407370656C6C646573633331383438300D0A0000, 35435), -- Spell
(3776013982, 300692, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 274909, 'frFR', 0x004C6F727371756520766F747265204272756D652064652072C3A96E6F766174696F6E2C20766F747265204272756D6520656E76656C6F7070616E7465206F7520766F7472652052C3A96365707461636C652064E28099657373656E636520736F6E74206163746966732C20436F7570206465207069656420647520736F6C65696C206C6576616E742072656E6420243237343931327331C2A0706F696E74732064652076696520C3A020746F757320766F7320616C6C69C3A9732065742070726F6C6F6E6765206365732065666665747320646520247331C2A0732C206A75737175E28099C3A02024733225206465206C65757220647572C3A965206F726967696E616C652E0000, 35435), -- Spell
(2035710060, 7050, 'frFR', 0x4772616E6465207072C3AA747265737365204D6172276C69000030031800009D1B00000172BA000000000000000000000000000001000000FF, 35435), -- JournalEncounterSection
(3776013982, 120679, 'frFR', 0x00496E766F71756520756E207075697373616E7420616E696D616C2073617576616765207175692061747461717565206C61206369626C6520656E20727567697373616E742C20636520717569206175676D656E746520766F7472652048C3A2746520646520243238313033367331252070656E64616E742024642E0000, 35435), -- Spell
(3776013982, 293777, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324854, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646496E76616C69646174696F6E7C720D0A24407370656C6C646573633331353238320000, 35435), -- Spell
(3776013982, 324893, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C63464646464646464644C3A96665726C656D656E7420646520766974616C6974C3A97C720D0A24407370656C6C646573633331383439350000, 35435), -- Spell
(3776013982, 324884, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475656C20647520566964657C720D0A24407370656C6C646573633331383437390000, 35435), -- Spell
(3776013982, 324853, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C63464646464646464645666669636163657C720D0A24407370656C6C646573633331353534340000, 35435), -- Spell
(3776013982, 291435, 'frFR', 0x004372C3A96520756E20736F6D6272652062617373696E2071756920647261696E6520246F3220706F696E74732064652073616E74C3A9206D656E74616C6520656E2024642061757820656E6E656D6973207175692070C3A96EC3A87472656E742064616E73206365747465207A6F6E652E0053616E74C3A9206D656E74616C652072C3A964756974652064652024733220746F75746573206C657320247432C2A0246C7365636F6E6465733A7365636F6E6465733B2E00, 35435), -- Spell
(3776013982, 155333, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 300932, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324862, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C634646464646464646506F6C7976616C656E747C720D0A24407370656C6C646573633331353534390000, 35435), -- Spell
(3205218938, 42496, 'frFR', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F53554254455854007C6E2573206176616E742064C3A973696E736372697074696F6E206175746F6D6174697175650001, 35435), -- GlobalStrings
(3776013982, 110556, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 154274, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324851, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C63464646464646464645666669636163657C720D0A24407370656C6C646573633331353534360000, 35435), -- Spell
(3776013982, 155347, 'frFR', 0x00566F757320696D7072C3A8676E65206465206CE28099657370726974206475206C6F7570206574206175676D656E746520766F74726520766974657373652064652064C3A9706C6163656D656E742064652024313534323539733125206C6F727371756520766F757320766F75732074726F7576657A20686F727320646520636F6D62617420657420737572206C61206372C3AA74652064652047697672656665752E00566F747265207669746573736520646520636F7572736520686F727320636F6D626174206175676D656E746520646520243135343235397331252E00, 35435), -- Spell
(3776013982, 301683, 'frFR', 0x00556E65206F6E646520646520636F6E76756C73696F6E732076656E696D65757365732073652070726F7061676520646570756973206CE28099656D706C6163656D656E7420646520766F74726520656E6E656D692C2063652071756920696E666C69676520247331C2A0706F696E74732064652064C3A967C3A2747320C3A020746F7573206C657320656E6E656D697320C3A0206D6F696E732064652035C2A06DC3A8747265732E0000, 35435), -- Spell
(3776013982, 337816, 'frFR', 0x0024407370656C6C646573633333373631320000, 35435), -- Spell
(3776013982, 324881, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5741524C4F434B5F534F554C535741502E424C503A32347C74207C634646464646464646C389636C616972206465206C756369646974C3A97C720D0A24407370656C6C646573633331383233390000, 35435), -- Spell
(3776013982, 324890, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C634646464646464646C389746F696C657320696E66696E6965737C720D0A24407370656C6C646573633331383438370000, 35435), -- Spell
(3776013982, 324886, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646417070656E646963652064C3A96E61747572C3A97C720D0A24407370656C6C646573633331383438310000, 35435), -- Spell
(3745449290, 6134, 'frFR', 0x4DC3A96361676F6E650000F61700008E1F2444E4C4BB431233A4C300000000000000007E1A000084110000C5EC000003000000D9050000310800000000000000000000, 35435), -- AreaPOI
(3776013982, 324888, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646417070656E646963652064C3A96E61747572C3A97C720D0A24407370656C6C646573633331383438330000, 35435), -- Spell
(3776013982, 324894, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C63464646464646464644C3A96665726C656D656E7420646520766974616C6974C3A97C720D0A24407370656C6C646573633331383439390000, 35435), -- Spell
(2035710060, 7070, 'frFR', 0x457370726974206C6F612062C3A96E69004C61206772616E6465207072C3AA747265737365204D6172E280996C6920696E766F71756520756E20457370726974206C6F612062C3A96E6920C3A0207365732063C3B474C3A9732E2043657420657370726974207365206469726967652076657273206CE28099616C6C69C3A9206465204D6172E280996C6920646F6E74206C657320706F696E74732064652076696520736F6E74206C657320706C757320626173206574206C6520736F69676E6520706F757220756E206D6F6E74616E7420C3A967616C20C3A0202431333733303373312520647520746F74616C2064652073612072C3A9736572766520646520706F696E747320646520766965207369206CE28099657370726974206EE2809965737420706173207475C3A9206176616E74207175E28099696C206EE280996169742061747465696E74207361206369626C652E0D0A0D0A5369206CE280996573707269742065737420746F756A6F75727320656E2076696520617072C3A8732024313337323837642C20696C20626F6E6469726120696E7374616E74616EC3A96D656E7420737572207361206369626C65206574206C6120736F69676E65726120706F757220756E206D6F6E74616E7420C3A967616C20C3A0202431333733303373312520647520746F74616C2064652073657320706F696E7473206465207669652E0030031A8A1B00009F1B02000000000000000000000000C231080000002200FF, 35435), -- JournalEncounterSection
(3776013982, 155315, 'frFR', 0x00566F757320C3AA74657320656E206861726D6F6E69652061766563206C657320666C616D6D6573206465206365747465207A6F6E652E20556E6520636F6C6F6E6E65206465206C6176652073E28099C3A96CC3A8766520706172666F697320647520736F6C206175207069656420646520766F7320656E6E656D69732E00556E6520636F6C6F6E6E65206465206C6176652073E28099C3A96CC3A87665726120706172666F697320647520736F6C206175207069656420646520766F7320656E6E656D69732E00, 35435), -- Spell
(3776013982, 301578, 'frFR', 0x000000, 35435), -- Spell
(2035710060, 7073, 'frFR', 0x44657374696E20636F6E747265206E6174757265004C61206772616E6465207072C3AA747265737365204D6172E280996C69207365207365727420646520636574746520746563686E69717565207175616E6420656C6C652065737420706F7373C3A964C3A96520706172206CE280996573707269742064652047617261E280996A616C2E0D0A0D0A4C61206772616E6465207072C3AA747265737365204D6172E280996C692061727261636865206CE28099C3A26D65206465206465757820706572736F6E6E616765732D6A6F75657572732063686F6973697320617520686173617264206574206372C3A96520756E206C69656E20656E74726520656C6C65732E2043686171756520C3A26D6520706F757273756974206CE28099C3A26D6520C3A0206C617175656C6C6520656C6C6520657374206C69C3A96520657420696E666C6967652024313337393732733120706F696E74732064652064C3A967C3A274732064E280994F6D62726520C3A020746F7573206C657320706572736F6E6E616765732D6A6F756575727320746F75746573206C657320243133373937357431C2A0732E20506C7573206C657320C3A26D657320736F6E7420C3A96C6F69676EC3A96573206CE28099756E65206465206CE2809961757472652C20706C7573206C65732064C3A967C3A274732064652044657374696E20636F6E747265206E617475726520736F6E742072C3A964756974732E0D0A0D0A5175616E6420756E652064657320C3A26D6573206D657572742C206C65206C69656E20736520726F6D7074206574206CE28099C3A26D652071756920726573746520656E20766965207365206D657420C3A020696E666C696765722024313337393836733120706F696E74732064652064C3A967C3A274732064E280994F6D62726520746F75746573206C657320243133373938367432C2A0732E0030031D8A1B00000000020000000000000000000000009B07070002001A000C, 35435), -- JournalEncounterSection
(3776013982, 155345, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 332950, 'frFR', 0x0000566F7320746563686E6971756573206F6E7420756E65206368616E63652064E28099696E666C69676572202440393035377331C2A0706F696E74732064652064C3A967C3A274732E00, 35435), -- Spell
(3776013982, 324901, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C63464646464646464645737072697420616666C3BB74C3A97C720D0A24407370656C6C646573633331383439380000, 35435), -- Spell
(3776013982, 324892, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C63464646464646464644C3A96665726C656D656E7420646520766974616C6974C3A97C720D0A24407370656C6C646573633331383237300000, 35435), -- Spell
(3776013982, 324852, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C63464646464646464645666669636163657C720D0A24407370656C6C646573633331353534350000, 35435), -- Spell
(3776013982, 299937, 'frFR', 0x004C652063686173736575722D7475657572206661697420617070617261C3AE747265206465732072656E666F727473206465204DC3A96361676F6E652E0000, 35435), -- Spell
(3776013982, 296464, 'frFR', 0x004CE28099756E6974C3A92064E280996F707072657373696F6E2061C3A97269656E6E652043542D38206661697420617070617261C3AE747265206465732072656E666F727473206465204DC3A96361676F6E652E0000, 35435), -- Spell
(3205218938, 42646, 'frFR', 0x424E45545F4552524F525F34303031320028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C202832290002, 35435), -- GlobalStrings
(3776013982, 324900, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C63464646464646464645737072697420616666C3BB74C3A97C720D0A24407370656C6C646573633331383439340000, 35435), -- Spell
(3776013982, 292907, 'frFR', 0x005469726520756E20C3A9636C617420646520676C61636520737572206C61206369626C65206574206C756920696E666C6967652024733125C2A06465206CE280996174746171756520736F757320666F726D652064652064C3A967C3A27473207068797369717565732E0000, 35435), -- Spell
(3776013982, 324887, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646417070656E646963652064C3A96E61747572C3A97C720D0A24407370656C6C646573633331383438320000, 35435), -- Spell
(3205218938, 41794, 'frFR', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F45585049524544004D6573736167652064652072656368657263686520646520636F6D6D756E617574C3A9206578706972C3A9C2A0210001, 35435), -- GlobalStrings
(3776013982, 319451, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 154275, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 155313, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 154259, 'frFR', 0x00566F757320696D7072C3A8676E65206465206CE28099657370726974206475206C6F7570206574206175676D656E746520766F74726520766974657373652064652064C3A9706C6163656D656E7420646520733125206C6F727371756520766F757320766F75732074726F7576657A20737572206C61206372C3AA74652064652047697672656665752E005669746573736520646520636F75727365206175676D656E74C3A965206465202473312520737572206C61204372C3AA74652064652047697672656665752E00, 35435), -- Spell
(3205218938, 41791, 'frFR', 0x4755494C445F46494E4445525F504F5354494E475F474F494E475F544F5F4558504952450045787069726174696F6E206465206C61207075626C69636174696F6E2064616E73C2A03A0001, 35435), -- GlobalStrings
(3776013982, 304086, 'frFR', 0x457373656E63652064E28099617AC3A972697465005175616E6420766F757320C3AA74657320C3A9746F757264692C206C6520626F6E75732064C3A966656E736966206F6374726F79C3A92070617220766F74726520506F6C7976616C656E636520657374206175676D656E74C3A920646520243330343737357331252E0000, 35435), -- Spell
(3776013982, 324845, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566964652072C3A9736F6E6E616E747C720D0A24407370656C6C646573633331383438360000, 35435), -- Spell
(3776013982, 155343, 'frFR', 0x000000, 35435), -- Spell
(3776013982, 324906, 'frFR', 0x00566F757320696D7072C3A9676E657A20756E206F626A6574206176656320756E6520736F75636865206D616C7665696C6C616E7465206465206C6120636F7272757074696F6E206465204EE280995A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C63464646464646464644C3A9766173746174696F6E206475204372C3A970757363756C657C720D0A24407370656C6C646573633331383437370000, 35435), -- Spell
(2035710060, 7069, 'frFR', 0x436F7572726F757820646573204C6F6173004C61206772616E6465207072C3AA747265737365204D6172E280996C692066726170706520756E20706572736F6E6E6167652D6A6F75657572206176656320436F7572726F757820646573204C6F6173206574206C756920696E666C6967652024313337333434733120706F696E74732064652064C3A967C3A274732064752053616372C3A92E003003198A1B00009E1B020000000000000000000000002413020000004000FF, 35435), -- JournalEncounterSection
(2948698321, 249, 'frFR', 0xD6968DCA7ACF9DD1, 35435), -- TactKeyLookup
(2948698321, 259, 'frFR', 0xB50278B84158ABDF, 35435), -- TactKeyLookup
(603412935, 28663, 'frFR', 0x3130E9878CE5B1B1E8B7AFE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28664, 'frFR', 0xE6899BE9BAA6E9838E0004, 35435), -- ChatProfanity
(603412935, 28644, 'frFR', 0xE689A9E998B4E599A80004, 35435), -- ChatProfanity
(603412935, 28652, 'frFR', 0xE5A3B9E59C8BE585A9E8A3BD0004, 35435), -- ChatProfanity
(603412935, 28656, 'frFR', 0xE99988E696B9E5AE89E7949F0004, 35435), -- ChatProfanity
(603412935, 28653, 'frFR', 0xE994A4E995B0E5B8AE0004, 35435), -- ChatProfanity
(603412935, 28650, 'frFR', 0x4C69626572617465484B0004, 35435), -- ChatProfanity
(603412935, 28645, 'frFR', 0xE5BEB7E5AFB8E88C8E0004, 35435), -- ChatProfanity
(603412935, 28648, 'frFR', 0xE99B8FE5A5B30004, 35435), -- ChatProfanity
(603412935, 28658, 'frFR', 0xE794B2E7B49AE688A6E78AAF0004, 35435), -- ChatProfanity
(603412935, 28655, 'frFR', 0xE69C80E9AB98E4BABAE6B0910004, 35435), -- ChatProfanity
(603412935, 28661, 'frFR', 0xE684BFE88DA3E58589E5BD92E9A699E6B8AF0004, 35435), -- ChatProfanity
(603412935, 28649, 'frFR', 0xE6B9BFE7A9B40004, 35435), -- ChatProfanity
(603412935, 28657, 'frFR', 0xE4BD95E4BF8AE4BB810004, 35435), -- ChatProfanity
(603412935, 28647, 'frFR', 0xE99CB2E998B4E9B8A10004, 35435), -- ChatProfanity
(603412935, 28662, 'frFR', 0xE58D81E9878CE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28646, 'frFR', 0xE88C8EE9BE9F0004, 35435), -- ChatProfanity
(603412935, 28651, 'frFR', 0x66726565484B0004, 35435), -- ChatProfanity
(603412935, 28660, 'frFR', 0xE88194E982A6E5AEA3E8A8800004, 35435), -- ChatProfanity
(603412935, 28654, 'frFR', 0xE4BABAE6B091E6A380E5AF9FE999A20004, 35435), -- ChatProfanity
(603412935, 28659, 'frFR', 0xE696B0E4B8ADE59BBDE88194E982A60004, 35435), -- ChatProfanity
(4033975491, 403803, 'frFR', 0x0000704100000000000000410000000000000000000000005B290600308A1300000000000000000000000000000000000000000000000000000000204100000000FFFFFFFFFFFF00000000000000000000000AD50100, 35435), -- SpellVisualKitModelAttach
(4146370265, 91772, 'frFR', 0x0000A0400000000000002041000000000000000000000000000000000000000022130000000000000000000000000000000000000000000000000000000000000000, 35435), -- SpellVisual
(517656225, 6688, 'frFR', 0x0000803F00000000E17AD43F000000000000000100001A00000000000303000000000000000000000000A4707D3F0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFF4742000000000000000000000000000000000000C8430000964300000040FFFFFFFF02038030E13E022B873D0AD7233C636D2400000020400000003F69000000000000000000803F0000803F6E186F180000000000000000000000000000000000000000403F3333B33E6666E63E0000000000000000000000000000000000000000000000000000000000000000000000008D5E1E008C5E1E008C5E1E00, 35435), -- SpellChainEffects
(4033975491, 404117, 'frFR', 0x00000000000000000000C03F000000000000000000000000952A0600D9891300000000000000000000000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000009D50100, 35435), -- SpellVisualKitModelAttach
(1181150530, 307455, 'frFR', 0x020000005B2906000AD50100, 35435), -- SpellVisualKitEffect
(25144992, 2203, 'frFR', 0x201A0000000000000000000001000000CB0100000000000013000000FFFFFFFF0000000000000000, 35435); -- BeamEffect


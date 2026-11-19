UPDATE `creature_template` SET  `npcflag` = `npcflag`|2 WHERE entry IN (94864, 88682);
DELETE FROM `creature_queststarter` WHERE `id` IN (94864, 88682);
INSERT INTO `creature_queststarter` VALUES
(94864, 36198), -- Cymre Brightblade, Uncovering the Artifact Fragments
(88682, 36133); -- Misirin Stouttoe, Uncovering the Artifact Fragments


UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (81765, 81870, 82204, 82660, 82893, 82966, 83830, 83995, 83997);
DELETE FROM `creature_queststarter` WHERE `id` IN (81765, 81870, 82204, 82660, 82893, 82966, 83830, 83995, 83997, 86084, 87391);
INSERT INTO `creature_queststarter` VALUES
(81765, 35243), -- Vivianne, The Dark Lady's Gift
(81870, 35264), -- Anenga, A Bunch of Artifact Fragments
(81870, 35638), -- Anenga, A Few Artifact Fragments
(81870, 35639), -- Anenga, A TON of Artifact Fragments
(82204, 36031), -- Atomik, A Bunch of Artifact Fragments
(82204, 36030), -- Atomik, A Few Artifact Fragments
(82204, 36032), -- Atomik, A TON of Artifact Fragments
(82660, 35690), -- Marketa, A Bunch of Artifact Fragments
(82660, 35689), -- Marketa, A Few Artifact Fragments
(82660, 35691), -- Marketa, A TON of Artifact Fragments
(82893, 35872), -- Valant Brightsworn, A Bunch of Artifact Fragments
(82893, 35871), -- Valant Brightsworn, A Few Artifact Fragments
(82893, 35873), -- Valant Brightsworn, A TON of Artifact Fragments
(82966, 35868), -- Ecilam, A Bunch of Artifact Fragments
(82966, 35867), -- Ecilam, A Few Artifact Fragments
(82966, 35869), -- Ecilam, A TON of Artifact Fragments
(83830, 36026), -- Kalgan, A Bunch of Artifact Fragments
(83830, 36024), -- Kalgan, A Few Artifact Fragments
(83830, 36025), -- Kalgan, A TON of Artifact Fragments
(83995, 36064), -- Fura, A Bunch of Artifact Fragments
(83995, 36063), -- Fura, A Few Artifact Fragments
(83995, 36065), -- Fura, A TON of Artifact Fragments
(83997, 36067), -- Nisstyr, A Bunch of Artifact Fragments
(83997, 36066), -- Nisstyr, A Few Artifact Fragments
(83997, 36068), -- Nisstyr, A TON of Artifact Fragments
(86084, 36633), -- Delvar Ironfist, Delvar Ironfist
(87391, 36055), -- Fate-Twister Seress, Sealing Fate: Apexis Crystals
(87391, 37458), -- Fate-Twister Seress, Sealing Fate: Extended Honor
(87391, 36056), -- Fate-Twister Seress, Sealing Fate: Garrison Resources
(87391, 36054), -- Fate-Twister Seress, Sealing Fate: Gold
(87391, 37452), -- Fate-Twister Seress, Sealing Fate: Heap of Apexis Crystals
(87391, 36057), -- Fate-Twister Seress, Sealing Fate: Honor
(87391, 37455), -- Fate-Twister Seress, Sealing Fate: Immense Fortune of Gold
(87391, 37459), -- Fate-Twister Seress, Sealing Fate: Monumental Honor
(87391, 37453), -- Fate-Twister Seress, Sealing Fate: Mountain of Apexis Crystals
(87391, 37454), -- Fate-Twister Seress, Sealing Fate: Piles of Gold
(87391, 37456), -- Fate-Twister Seress, Sealing Fate: Stockpiled Garrison Resources
(87391, 37457); -- Fate-Twister Seress, Sealing Fate: Tremendous Garrison Resources

DELETE FROM `creature_questender` WHERE `id` IN (81765, 81870, 82204, 82660, 82893, 82966, 83830, 83995, 83997, 86084, 87391);
INSERT INTO `creature_questender` VALUES
(81765, 36709), -- Vivianne, Burning Beauty
(81765, 35243), -- Vivianne, The Dark Lady's Gift
(81870, 35264), -- Anenga, A Bunch of Artifact Fragments
(81870, 35638), -- Anenga, A Few Artifact Fragments
(81870, 35639), -- Anenga, A TON of Artifact Fragments
(82204, 36031), -- Atomik, A Bunch of Artifact Fragments
(82204, 36030), -- Atomik, A Few Artifact Fragments
(82204, 36032), -- Atomik, A TON of Artifact Fragments
(82660, 35690), -- Marketa, A Bunch of Artifact Fragments
(82660, 35689), -- Marketa, A Few Artifact Fragments
(82660, 35691), -- Marketa, A TON of Artifact Fragments
(82893, 35872), -- Valant Brightsworn, A Bunch of Artifact Fragments
(82893, 35871), -- Valant Brightsworn, A Few Artifact Fragments
(82893, 35873), -- Valant Brightsworn, A TON of Artifact Fragments
(82966, 35868), -- Ecilam, A Bunch of Artifact Fragments
(82966, 35867), -- Ecilam, A Few Artifact Fragments
(82966, 35869), -- Ecilam, A TON of Artifact Fragments
(82966, 36133), -- Ecilam, Uncovering the Artifact Fragments
(83830, 36026), -- Kalgan, A Bunch of Artifact Fragments
(83830, 36024), -- Kalgan, A Few Artifact Fragments
(83830, 36025), -- Kalgan, A TON of Artifact Fragments
(83995, 36064), -- Fura, A Bunch of Artifact Fragments
(83995, 36063), -- Fura, A Few Artifact Fragments
(83995, 36065), -- Fura, A TON of Artifact Fragments
(83995, 36198), -- Fura, Uncovering the Artifact Fragments
(83997, 36067), -- Nisstyr, A Bunch of Artifact Fragments
(83997, 36066), -- Nisstyr, A Few Artifact Fragments
(83997, 36068), -- Nisstyr, A TON of Artifact Fragments
(86084, 36630), -- Delvar Ironfist, A Surly Dwarf
(86084, 36633), -- Delvar Ironfist, Delvar Ironfist
(87391, 36055), -- Fate-Twister Seress, Sealing Fate: Apexis Crystals
(87391, 37458), -- Fate-Twister Seress, Sealing Fate: Extended Honor
(87391, 36056), -- Fate-Twister Seress, Sealing Fate: Garrison Resources
(87391, 36054), -- Fate-Twister Seress, Sealing Fate: Gold
(87391, 37452), -- Fate-Twister Seress, Sealing Fate: Heap of Apexis Crystals
(87391, 36057), -- Fate-Twister Seress, Sealing Fate: Honor
(87391, 37455), -- Fate-Twister Seress, Sealing Fate: Immense Fortune of Gold
(87391, 37459), -- Fate-Twister Seress, Sealing Fate: Monumental Honor
(87391, 37453), -- Fate-Twister Seress, Sealing Fate: Mountain of Apexis Crystals
(87391, 37454), -- Fate-Twister Seress, Sealing Fate: Piles of Gold
(87391, 37456), -- Fate-Twister Seress, Sealing Fate: Stockpiled Garrison Resources
(87391, 37457); -- Fate-Twister Seress, Sealing Fate: Tremendous Garrison Resources

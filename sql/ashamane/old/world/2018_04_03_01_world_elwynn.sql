-- Table `creature_template`
UPDATE `creature_template` SET `npcflag` = 0 WHERE (entry = 49874);

-- Table `creature_text_locale`
DELETE FROM `creature_text_locale` WHERE CreatureID = 49874;
INSERT INTO `creature_text_locale` VALUES ('49874', '0', '0', 'frFR', 'Orc TUER $r !');
INSERT INTO `creature_text_locale` VALUES ('49874', '0', '1', 'frFR', 'Rochenoire prend forêt !');
INSERT INTO `creature_text_locale` VALUES ('49874', '0', '2', 'frFR', 'Les raisins étaient DÉLICIEUX !');

-- Table `quest_offer_reward_locale`
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28759', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28769', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28770', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28772', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28774', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('29079', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('31140', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28773', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('28771', 'frFR', 'Excellent travail, $N. Vous avez prouvé que vous étiez un réel atout pour cette garnison. N’hésitez pas à vous adresser à nos maîtres de classe dans l’abbaye et ses jardins si vous avez besoin d’affûter vos compétences martiales.$B$BQuand vous serez prêt, il y a une autre mission dont j’aimerais vous faire part…', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('26389', 'frFR', 'Maintenant que leur principale force d’assaut a été vaincue, les orcs rochenoires vont sûrement se replier ! Il ne reste plus qu\'une chose à faire.', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('26390', 'frFR', 'Maintenant que Kurtok est mort, nous sommes à l’abri des hordes d’orcs. Je vais envoyer des paysans tenter de bloquer le passage, de manière à ce qu’aucun orc ne puisse plus pénétrer sur notre territoire. Hurlevent et l’Alliance vous remercient, héros !', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('54', 'frFR', 'Bien, cela dit que vous avez été promu au grade d\'adjoint des maréchaux de Hurlevent. Félicitations.$B$BEt bonne chance – assurer la sécurité d\'Elwynn n\'est pas une partie de plaisir... Comment faire avec une armée complètement débordée, pour savoir qui fait quoi et pour quel noble !$B$BIl est difficile de garder une politique cohérente en cette sombre époque...', '0');
INSERT IGNORE INTO `quest_offer_reward_locale` VALUES ('37112', 'frFR', 'Le repos et la détente pour ceux qui sont fatigués et qui ont froid – c\'est notre devise ! Je vous en prie, prenez place près du feu et reposez-vous.$B$BVoudriez-vous goûter quelques-uns de nos plus excellents mets et boissons ?', '0');

-- Table `quest_request_items_locale`
INSERT IGNORE INTO `quest_request_items_locale` VALUES ('26389', 'frFR', 'Qu\'en est-il de cette horde d\'orcs déchaînée ?', '0');
INSERT IGNORE INTO `quest_request_items_locale` VALUES ('54', 'frFR', 'Vous avez des nouvelles de McBride ? Comté-du-Nord est un jardin d\'enfant comparé à la forêt d\'Elwynn, mais je me demande de quoi le maréchal McBride veut m\'informer.$B$BBien, laissez-moi jeter un coup d\'œil sur ces documents...', '0');

-- Table `creature_equip_template`
INSERT IGNORE INTO `creature_equip_template` VALUES ('42937', '1', '14877', '0', '0', '0', '0', '0', '0', '0', '0', '0');

-- Table `creature_queststarter`
DELETE FROM `creature_queststarter` WHERE `quest` = 2158;

-- Table `creature_questender`
DELETE FROM `creature_questender` WHERE `quest` = 2158;

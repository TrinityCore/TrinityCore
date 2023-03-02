/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

DROP TABLE IF EXISTS `battlepay_display_info_locales`;
CREATE TABLE IF NOT EXISTS `battlepay_display_info_locales` (
  `Id` int(11) DEFAULT NULL,
  `Locale` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `Name1` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `Name2` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `Name3` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `Name4` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `Name5` varchar(255) CHARACTER SET utf8 DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

DELETE FROM `battlepay_display_info_locales`;
/*!40000 ALTER TABLE `battlepay_display_info_locales` DISABLE KEYS */;
INSERT INTO `battlepay_display_info_locales` (`Id`, `Locale`, `Name1`, `Name2`, `Name3`, `Name4`, `Name5`) VALUES
	(1, 'deDE', 'ZÃ¼gel des Kriegswolfs der Kor\'kron', NULL, 'Die Kor\'kron nutzen nur die mÃ¤chtigsten WÃ¶lfe als Reittiere und kleiden sie in RÃ¼stungen, die schwÃ¤chere Kreaturen in die Knie zwingen wÃ¼rden.', NULL, NULL),
	(2, 'deDE', 'Schwarzer Qirajiresonanzkristall\r\n', NULL, 'Auch wenn noch immer viele Arten der Qirajipanzerdrohne in den Ruinen von Ahn\'Qiraj entdeckt werden kÃ¶nnen, wurden die dunkelste Spezies nur zu Zeiten des hallenden SkarabÃ¤usgongs erblickt.', NULL, NULL),
	(3, 'deDE', 'Tyraels Streitross', NULL, 'Ein Zeichen der Gerechtigkeit in allen bekannten Reichen.', NULL, NULL),
	(4, 'deDE', 'ZÃ¼gel des schwarzen Protodrachen', NULL, 'GezÃ¼chtet, um jene Helden zu ehren, die auÃŸergewÃ¶hnliche WiderstandsfÃ¤higkeit gegen die Gefahren in Nordend bewiesen haben.', NULL, NULL),
	(5, 'deDE', 'Himmelsross', NULL, 'Ein Hoffnungsschimmer, ein leitendes Licht in der Dunkelheit.', NULL, NULL),
	(6, 'deDE', 'GeflÃ¼gelter WÃ¤chter', NULL, 'Dieser mÃ¤chtige, geflÃ¼gelte LÃ¶we wurde vor Kurzem in einer uralten GrabstÃ¤tte entdeckt und hat mÃ¶glicherweise den uralten Prinzen der Tol\'vir gedient.', NULL, NULL),
	(71, 'deDE', 'Charakteraufwertung fÃ¼r Shadowlands', NULL, NULL, NULL, NULL),
	(73, 'deDE', 'Charakterumbenennung', NULL, NULL, NULL, NULL),
	(74, 'deDE', 'Fraktionswechsel', NULL, NULL, NULL, NULL),
	(75, 'deDE', 'Volkswechsel', NULL, NULL, NULL, NULL),
	(76, 'deDE', 'Charakteranpassung', NULL, NULL, NULL, NULL),
	(78, 'deDE', '10.000 Gold', NULL, 'Erhalte 10.000 Gold fÃ¼r deinen Character', NULL, NULL),
	(79, 'deDE', '50.000 Gold', NULL, 'Erhalte 50.000 Gold fÃ¼r deinen Character', NULL, NULL),
	(80, 'deDE', '200.000 Gold', NULL, 'Erhalte 200.000 Gold fÃ¼r deinen Character', NULL, NULL),
	(81, 'deDE', '500.000 Gold', NULL, 'Erhalte 500.000 Gold fÃ¼r deinen Character', NULL, NULL),
	(69, 'deDE', 'Todesschwingchen', NULL, 'Mit Rechtsklick Todesschwingchen beschwÃ¶ren oder wieder freigeben.', NULL, NULL),
	(7, 'deDE', 'Herz der Aspekte', NULL, 'Ihr seid Azeroths wahre WÃ¤chter, und die Zukunft dieser Welt liegt in Euren HÃ¤nden, denn das Zeitalter der Sterblichen hat begonnen. - Alexstrasza', NULL, NULL),
	(8, 'deDE', 'Schnelles Windross', NULL, 'Eine von Pandarias meistgesuchten Kreaturen, die ihren Reitern GlÃ¼ck bringen sollen.', NULL, NULL),
	(9, 'deDE', 'Gepanzerte Blutschwinge', NULL, 'Diese monstrÃ¶se, fleischfressende Fledermaus ist der unangefochtene Herrscher des Nachthimmels.', NULL, NULL),
	(10, 'deDE', 'Verzauberter Feendrache', NULL, 'Diese majestÃ¤tische Kreatur ist Wolkenglanzes Ã¤lterer Bruder. Er versichert, dass sie eigentlich adoptiert wurde.', NULL, NULL),
	(11, 'deDE', 'Eiserner HimmelsjÃ¤ger', NULL, 'Die Bestienmeister der Eisernen Horde haben diesen Rylak fÃ¼r den Krieg gezÃ¼chtet und ihn dann mit schwarzem Stahl und qualmenden Flammen fÃ¼r den Krieg gewappnet.', NULL, NULL),
	(12, 'deDE', 'Kriegsgeschmiedeter Nachtmahr\r\n', NULL, 'Ein Alptraumross aus gehÃ¤rtetem Stahl und rachsÃ¼chtigem Geist. Dieser GefÃ¤hrte wird Euch ohne zu zucken in die Feuerlande und zurÃ¼ck folgen.', NULL, NULL),
	(13, 'deDE', 'Grinsender HÃ¤scher', NULL, 'Ein LÃ¤cheln und ein Grinsen sind zwei verschiedene Dinge. Genau wie kochen und kÃ¼ssen.', NULL, NULL),
	(78, 'ruRU', '10000 Золота', NULL, NULL, NULL, NULL);
/*!40000 ALTER TABLE `battlepay_display_info_locales` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;

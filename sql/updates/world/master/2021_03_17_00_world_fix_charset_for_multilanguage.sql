/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

DROP TABLE IF EXISTS `battlepay_product_group_locales`;
CREATE TABLE IF NOT EXISTS `battlepay_product_group_locales` (
  `GroupID` int(11) DEFAULT NULL,
  `Locale` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `Name` varchar(50) CHARACTER SET utf8 DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

DELETE FROM `battlepay_product_group_locales`;
/*!40000 ALTER TABLE `battlepay_product_group_locales` DISABLE KEYS */;
INSERT INTO `battlepay_product_group_locales` (`GroupID`, `Locale`, `Name`) VALUES
	(1, 'frFR', 'Montures'),
	(2, 'frFR', 'Mascottes'),
	(3, 'frFR', 'Services'),
	(4, 'frFR', 'Pièces d\'or'),
	(17, 'frFR', 'À la une'),
	(16, 'frFR', 'Offre spéciale'),
	(14, 'frFR', 'Packs d\'objets'),
	(1, 'ruRU', 'Маунты'),
	(4, 'ruRU', 'Золото'),
	(3, 'ruRU', 'Сервисы'),
	(2, 'ruRU', 'Питомцы'),
	(5, 'ruRU', 'Профессии');
/*!40000 ALTER TABLE `battlepay_product_group_locales` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;

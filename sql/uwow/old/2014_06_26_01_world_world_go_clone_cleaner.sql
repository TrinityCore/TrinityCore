/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

ALTER IGNORE TABLE gameobject ADD UNIQUE INDEX(id, position_x, position_y, position_z, spawnMask, phaseMask);
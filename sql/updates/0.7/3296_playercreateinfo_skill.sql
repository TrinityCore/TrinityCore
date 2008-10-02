DROP TABLE IF EXISTS `playercreateinfo_skill`;
CREATE TABLE `playercreateinfo_skill` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `Skill` mediumint(8) unsigned NOT NULL default '0',
  `Note` varchar(255) default NULL,
  PRIMARY KEY  (`race`,`class`,`Skill`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `playercreateinfo_skill` VALUES 
(1,1,183,'GENERIC (DND)'),(1,2,183,'GENERIC (DND)'),(1,4,183,'GENERIC (DND)'),(1,5,183,'GENERIC (DND)'),(1,8,183,'GENERIC (DND)'),(1,9,183,'GENERIC (DND)'),(2,1,183,'GENERIC (DND)'),(2,3,183,'GENERIC (DND)'),(2,4,183,'GENERIC (DND)'),(2,7,183,'GENERIC (DND)'),(2,9,183,'GENERIC (DND)'),(3,1,183,'GENERIC (DND)'),(3,2,183,'GENERIC (DND)'),(3,3,183,'GENERIC (DND)'),(3,4,183,'GENERIC (DND)'),(3,5,183,'GENERIC (DND)'),(4,1,183,'GENERIC (DND)'),(4,3,183,'GENERIC (DND)'),(4,4,183,'GENERIC (DND)'),(4,5,183,'GENERIC (DND)'),(4,11,183,'GENERIC (DND)'),(5,1,183,'GENERIC (DND)'),(5,4,183,'GENERIC (DND)'),(5,5,183,'GENERIC (DND)'),(5,8,183,'GENERIC (DND)'),(5,9,183,'GENERIC (DND)'),(6,1,183,'GENERIC (DND)'),(6,3,183,'GENERIC (DND)'),(6,7,183,'GENERIC (DND)'),(6,11,183,'GENERIC (DND)'),(7,1,183,'GENERIC (DND)'),(7,4,183,'GENERIC (DND)'),(7,8,183,'GENERIC (DND)'),(7,9,183,'GENERIC (DND)'),(8,1,183,'GENERIC (DND)'),(8,3,183,'GENERIC (DND)'),(8,4,183,'GENERIC (DND)'),(8,5,183,'GENERIC (DND)'),(8,7,183,'GENERIC (DND)'),(8,8,183,'GENERIC (DND)'),
(1,8,6,'Frost'),(5,8,6,'Frost'),(7,8,6,'Frost'),(8,8,6,'Frost'),
(1,8,8,'Fire'),(5,8,8,'Fire'),(7,8,8,'Fire'),(8,8,8,'Fire'),
(1,1,26,'Arms'),(2,1,26,'Arms'),(3,1,26,'Arms'),(4,1,26,'Arms'),(5,1,26,'Arms'),(6,1,26,'Arms'),(7,1,26,'Arms'),(8,1,26,'Arms'),
(1,4,38,'Combat'),(2,4,38,'Combat'),(3,4,38,'Combat'),(4,4,38,'Combat'),(5,4,38,'Combat'),(7,4,38,'Combat'),(8,4,38,'Combat'),
(2,3,51,'Survival'),(3,3,51,'Survival'),(4,3,51,'Survival'),(6,3,51,'Survival'),(8,3,51,'Survival'),
(1,5,56,'Holy'),(3,5,56,'Holy'),(4,5,56,'Holy'),(5,5,56,'Holy'),(8,5,56,'Holy'),(1,2,594,'Holy'),(3,2,594,'Holy'),
(3,1,101,'Dwarven Racial'),(3,2,101,'Dwarven Racial'),(3,3,101,'Dwarven Racial'),(3,4,101,'Dwarven Racial'),(3,5,101,'Dwarven Racial'),
(6,1,124,'Tauren Racial'),(6,3,124,'Tauren Racial'),(6,7,124,'Tauren Racial'),(6,11,124,'Tauren Racial'),
(2,1,125,'Orc Racial'),(2,3,125,'Orc Racial'),(2,4,125,'Orc Racial'),(2,7,125,'Orc Racial'),(2,9,125,'Orc Racial'),
(4,1,126,'Night Elf Racial'),(4,3,126,'Night Elf Racial'),(4,4,126,'Night Elf Racial'),(4,5,126,'Night Elf Racial'),(4,11,126,'Night Elf Racial'),
(2,3,163,'Marksmanship'),(3,3,163,'Marksmanship'),(4,3,163,'Marksmanship'),(6,3,163,'Marksmanship'),(8,3,163,'Marksmanship'),
(5,1,220,'Racial - Undead'),(5,4,220,'Racial - Undead'),(5,5,220,'Racial - Undead'),(5,8,220,'Racial - Undead'),(5,9,220,'Racial - Undead'),
(1,4,253,'Assassination'),(2,4,253,'Assassination'),(3,4,253,'Assassination'),(4,4,253,'Assassination'),(5,4,253,'Assassination'),(7,4,253,'Assassination'),(8,4,253,'Assassination'),
(1,9,354,'Demonology'),(2,9,354,'Demonology'),(5,9,354,'Demonology'),(7,9,354,'Demonology'),(2,7,374,'Restoration'),
(6,7,374,'Restoration'),(8,7,374,'Restoration'),(4,11,573,'Restoration'),(6,11,573,'Restoration'),
(2,7,375,'Elemental Combat'),(6,7,375,'Elemental Combat'),(8,7,375,'Elemental Combat'),
(4,11,574,'Balance'),(6,11,574,'Balance'),
(1,9,593,'Destruction'),(2,9,593,'Destruction'),(5,9,593,'Destruction'),(7,9,593,'Destruction'),
(8,1,733,'Racial - Troll'),(8,3,733,'Racial - Troll'),(8,4,733,'Racial - Troll'),(8,5,733,'Racial - Troll'),(8,7,733,'Racial - Troll'),(8,8,733,'Racial - Troll'),
(7,1,753,'Racial - Gnome'),(7,4,753,'Racial - Gnome'),(7,8,753,'Racial - Gnome'),(7,9,753,'Racial - Gnome'),
(1,1,754,'Racial - Human'),(1,2,754,'Racial - Human'),(1,4,754,'Racial - Human'),(1,5,754,'Racial - Human'),(1,8,754,'Racial - Human'),(1,9,754,'Racial - Human');

-- add masquerade command info
DELETE FROM `command` WHERE `name`='character masquerade';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES ('character masquerade',842,"Usage: .character masquerade #race
Permanently masquerades the select target (or self) as the specified race.
Available races:
   0 - remove masquerade
   1 - Human
   2 - Orc
   3 - Dwarf
   4 - Night Elf
   5 - Undead
   6 - Tauren
   7 - Gnome
   8 - Troll
  10 - Blood Elf
  11 - Draenei");
  
DELETE FROM `trinity_string` WHERE `entry`=11019;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(11019,'Masquerade system disabled by world config.');

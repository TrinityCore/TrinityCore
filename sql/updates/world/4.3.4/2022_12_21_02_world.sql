DELETE FROM `world_state` WHERE `ID` IN (1941,1942,1943,2851,3695,4273,5360,5361,6306,6436,7671);
INSERT INTO `world_state` (`ID`,`DefaultValue`,`MapIDs`,`AreaIDs`,`ScriptName`,`Comment`) VALUES
(1941,0,NULL,NULL,'','Battleground Call to Arms - Alterac Valley'),
(1942,0,NULL,NULL,'','Battleground Call to Arms - Warsong Gulch'),
(1943,0,NULL,NULL,'','Battleground Call to Arms - Arathi Basin'),
(2851,0,NULL,NULL,'','Battleground Call to Arms - Eye of the Storm'),
(3695,0,NULL,NULL,'','Battleground Call to Arms - Strand of the Ancients'),
(4273,0,NULL,NULL,'','Battleground Call to Arms - Isle of Conquest'),
(5360,0,NULL,NULL,'','Battleground Call to Arms - The Battle for Gilneas'),
(5361,0,NULL,NULL,'','Battleground Call to Arms - Twin Peaks');

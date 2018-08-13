-- Intro Cinematic Scene Templates

-- Nightborne
DELETE FROM `scene_template` WHERE (`SceneId`=1900 AND `ScriptPackageID`=2007);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1900, 9, 2007);

-- Hightmountain Tauren
DELETE FROM `scene_template` WHERE (`SceneId`=1901 AND `ScriptPackageID`=1984);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1901, 9, 1984);

-- Lightforged Dranai
DELETE FROM `scene_template` WHERE (`SceneId`=1902 AND `ScriptPackageID`=2005);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1902, 9, 2005);

-- Void Elf
DELETE FROM `scene_template` WHERE (`SceneId`=1903 AND `ScriptPackageID`=2006);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1903, 9, 2006);
